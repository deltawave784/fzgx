"""Seed claims from the committed repair archives (`state/repairs/*.json.gz`).

The archives hold historical C for unmatched functions with the compiler each body was
measured under. Only `fixup` read them; a claim seeds from the ledger's attempts, whose
restored body paths point at the recording machine. This rescoring import makes the best
archived body of every unmatched function an ordinary local attempt: rescored under the
current oracle with its own compiler settings, saved under .fzgx/attempts/ with the
sidecar a release writes, and recorded as an ended `import-corpus` attempt. That attempt
does not count toward the function's attempt cap.
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


def run(p: Project, per_symbol: int = 2, apply: bool = True) -> Dict[str, dict]:
    ledger = Ledger()
    unmatched = {r[0] for r in ledger.db.execute("SELECT symbol FROM functions WHERE status='unmatched'")}
    picks = candidates(unmatched, per_symbol)
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
                score = res.percent_adjusted if res.pool_rows else res.percent
                if score > best.get(symbol, {}).get("score", -1):
                    best[symbol] = dict(score=score, body=body, record=record, mw=mw, flags=flags,
                                        matched=bool(res.matched or res.matched_pool))
    report = {}
    for symbol, b in sorted(best.items()):
        local = ledger.best_local_attempt(symbol)
        prior = (local[0]["best_in_attempt"] or local[0]["final_percent"] or 0) if local else None
        entry = dict(score=round(b["score"], 2), recorded=round(_recorded(b["record"]), 2), local=prior,
                     archive=b["record"]["archive"], mw=b["mw"], flags=b["flags"], matched=b["matched"])
        report[symbol] = entry
        if not apply or (prior is not None and prior >= b["score"]):
            continue
        dest = STATE_DIR / "attempts" / f"{symbol}.corpus.{b['record']['digest'][:12]}.c"
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
                 f"seeded from state/repairs/{b['record']['archive']} ({b['record'].get('generator') or b['record'].get('label') or 'archived body'})",
                 str(dest)))
        entry["imported"] = True
    return report
