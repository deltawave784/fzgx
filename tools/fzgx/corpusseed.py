"""Seed claims from the committed repair archives (`state/repairs/*.json.gz`).

The archives hold historical C for unmatched functions with the compiler each body was
measured under. Only `fixup` read them; a claim seeds from the ledger's attempts, whose
restored body paths point at the recording machine. This rescoring import makes the best
archived body of every unmatched function an ordinary local attempt: rescored under the
current oracle with its own compiler settings, saved under .fzgx/attempts/ with the
sidecar a release writes, and recorded as an ended `import-corpus` attempt. That attempt
does not count toward the function's attempt cap.

`--from-checks` reads the per-function check archives (`.fzgx/checks/<symbol>/NNN.c` with
`index.jsonl`) instead: every checked body is archived there, but only an attempt's best by
the ledger's scale became its saved body, and before the scales were unified a 95% body
could lose to an 86% seed (fn_1_5D91C). The local best body is rescored alongside, under its
own sidecar compiler settings, and a check body is imported only when it scores higher.
"""

from __future__ import annotations

import gzip
import hashlib
import json
import time
from collections import defaultdict
from pathlib import Path
from typing import Dict, List, Optional

from . import oracle
from .ledger import Ledger
from .project import ROOT, STATE_DIR, Project

AGENT = "import-corpus"


def _recorded(record: dict) -> float:
    return max((float(record[k]) for k in ("percent_adjusted", "percent", "raw_percent")
                if isinstance(record.get(k), (int, float))), default=0.0)


def candidates(unmatched: set, per_symbol: int) -> Dict[str, List[dict]]:
    found: Dict[str, Dict[str, dict]] = defaultdict(dict)
    for path in sorted((ROOT / "state" / "repairs").glob("*.json.gz")):
        data = json.loads(gzip.decompress(path.read_bytes()))
        for record in data.get("records", []):
            if not (isinstance(record, dict) and record.get("symbol") in unmatched and record.get("body")):
                continue
            digest = hashlib.sha256(record["body"].encode()).hexdigest()
            found[record["symbol"]].setdefault(digest, dict(record, archive=path.name, digest=digest))
    return {s: sorted(v.values(), key=_recorded, reverse=True)[:per_symbol] for s, v in found.items()}


def check_candidates(unmatched: set, per_symbol: int) -> Dict[str, List[dict]]:
    """The best archived check bodies per unmatched symbol, ranked by their recorded score on
    the ledger's one scale (oracle.progress_score: max of objdiff and pool-adjusted)."""
    by_dir = {s.replace(":", "__"): s for s in unmatched}
    found: Dict[str, Dict[str, dict]] = defaultdict(dict)
    root = STATE_DIR / "checks"
    for index in sorted(root.glob("*/index.jsonl")) if root.exists() else []:
        symbol = by_dir.get(index.parent.name)
        if symbol is None:
            continue
        for line in index.read_text(errors="replace").splitlines():
            try:
                row = json.loads(line)
            except ValueError:
                continue
            if not row.get("ok") or not isinstance(row.get("n"), int):
                continue
            path = index.parent / f"{row['n']:03d}.c"
            if not path.exists():
                continue
            body = path.read_text(errors="replace")
            digest = hashlib.sha256(body.encode()).hexdigest()
            rec = dict(body=body, mw=row.get("mw"), flags=row.get("flags"), percent=row.get("percent"),
                       percent_adjusted=row.get("adjusted"), digest=digest,
                       archive=f"checks/{index.parent.name}/{path.name}", label="check archive")
            old = found[symbol].get(digest)
            if old is None or _recorded(rec) > _recorded(old):
                found[symbol][digest] = rec
    return {s: sorted(v.values(), key=_recorded, reverse=True)[:per_symbol] for s, v in found.items()}


def _local_scores(p: Project, ledger: Ledger, symbols: List[str]) -> Dict[str, float]:
    """The saved best body of each symbol rescored now under its sidecar compiler settings."""
    groups: Dict[tuple, list] = defaultdict(list)
    for symbol in symbols:
        local = ledger.best_local_attempt(symbol)
        if not local:
            continue
        side = local[1].with_suffix(".json")
        meta = {}
        if side.exists():
            try:
                meta = json.loads(side.read_text())
            except ValueError:
                meta = {}
        groups[(meta.get("mw"), meta.get("flags"))].append((symbol, local[1]))
    out: Dict[str, float] = {}
    for (mw, flags), items in groups.items():
        results = oracle.check_many(p, items, mw_version=mw, extra_cflags=flags)
        for symbol, _ in items:
            res = results.get(symbol)
            if res and res.ok:
                out[symbol] = oracle.progress_score(res)
    return out


def run(p: Project, per_symbol: int = 2, apply: bool = True, from_checks: bool = False) -> Dict[str, dict]:
    ledger = Ledger()
    unmatched = {r[0] for r in ledger.db.execute("SELECT symbol FROM functions WHERE status='unmatched'")}
    picks = (check_candidates if from_checks else candidates)(unmatched, per_symbol)
    scratch = STATE_DIR / "corpus"
    scratch.mkdir(parents=True, exist_ok=True)
    best: Dict[str, dict] = {}
    for rank in range(per_symbol):
        groups: Dict[tuple, list] = defaultdict(list)
        for symbol, records in picks.items():
            if rank < len(records):
                r = records[rank]
                body = scratch / f"{symbol}.{r['digest'][:12]}.c"
                body.write_text(r["body"])
                groups[(r.get("mw"), r.get("flags"))].append((symbol, body, r))
        for (mw, flags), items in groups.items():
            results = oracle.check_many(p, [(s, b) for s, b, _ in items], mw_version=mw, extra_cflags=flags)
            for symbol, body, record in items:
                res = results.get(symbol)
                if not res or not res.ok:
                    continue
                score = oracle.progress_score(res)
                if score > best.get(symbol, {}).get("score", -1):
                    best[symbol] = dict(score=score, body=body, record=record, mw=mw, flags=flags,
                                        matched=bool(res.matched or res.matched_pool))
    report = {}
    rescored = _local_scores(p, ledger, sorted(best)) if from_checks else {}
    for symbol, b in sorted(best.items()):
        local = ledger.best_local_attempt(symbol)
        prior = (local[0]["best_in_attempt"] or local[0]["final_percent"] or 0) if local else None
        if symbol in rescored:  # the saved body's current score, not its recorded one
            prior = round(rescored[symbol], 2)
        entry = dict(score=round(b["score"], 2), recorded=round(_recorded(b["record"]), 2), local=prior,
                     archive=b["record"]["archive"], mw=b["mw"], flags=b["flags"], matched=b["matched"])
        report[symbol] = entry
        if prior is not None and prior >= b["score"] - 0.005:
            continue
        entry["candidate"] = True
        if not apply:
            continue
        kind = "checks" if from_checks else "corpus"
        dest = STATE_DIR / "attempts" / f"{symbol}.{kind}.{b['record']['digest'][:12]}.c"
        dest.parent.mkdir(parents=True, exist_ok=True)
        dest.write_text(b["body"].read_text())
        dest.with_suffix(".json").write_text(json.dumps(dict(
            sha256=hashlib.sha256(dest.read_bytes()).hexdigest(), mw=b["mw"], flags=b["flags"],
            percent=b["score"], archive=b["record"]["archive"])) + "\n")
        now = int(time.time())
        with ledger.db:
            ledger.db.execute(
                "INSERT INTO attempts(symbol, agent, harness, started, ended, checks, final_percent, best_in_attempt, "
                "outcome, notes, best_body_path) VALUES(?,?,?,?,?,?,?,?,?,?,?)",
                (symbol, AGENT, "deterministic", now, now, 0, b["score"], b["score"], "imported",
                 f"seeded from {'.fzgx/' if from_checks else 'state/repairs/'}{b['record']['archive']} ({b['record'].get('generator') or b['record'].get('label') or 'archived body'})",
                 str(dest)))
        entry["imported"] = True
    return report
