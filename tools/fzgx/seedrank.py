"""Seed ranking that sees through objdiff's equal row weights.

objdiff's similarity weighs every row the same, so a body that simply omits a
store or an address addend can outscore a correct body with a handful of
register-allocation rows (fn_17_7728: a 95.2% body without the else-branch store;
fn_8005D258: 96.8%/98.1% bodies without the `+4` addend). For seed and best-body
SELECTION only (never acceptance: the oracle still decides what matches), a body
loses PENALTY points per retail row whose effect is missing from ours:

- retail-only rows (no instruction of the same opcode opposite them) after register
  names and relocation symbols are masked, and
  after cancelling against our-only rows of the same shape (a moved store is
  scheduling, not an omission);
- that are stores (not frame stores off r1) or non-move arithmetic with a
  nonzero immediate (addi/addis/mulli/ori/... ; `addi rX, rY, 0` is a move).

A body that calls a function it never declares (`oracle.body_diagnostics`: MWCC's implicit
`int f()`) or reads a local it never assigns (MWCC's `not initialized before being used`)
loses IMPLICIT_PENALTY points, the same margin `api.IMPLICIT_MARGIN` applies to the
attempt's saved best, so a sound body within that margin seeds the next attempt.

The primary key is the number of rows still differing (`oracle.progress_rows`), not the
percentage: objdiff's similarity can rank a body with more differing rows above one with fewer
(fn_1_5CA00: a 25-row 99.2% seed over a 12-row 97.1% body; fn_8_D034: 63 rows at 99.0% over
22 rows at 96.8%), and the matcher's remaining work is the rows. Dropped semantic rows and
known store-value conflicts (`CheckResult.value_flow`: a store whose value provably differs
from retail's) count DROPPED_ROWS extra rows each (`effective_rows`); percent minus the
penalties breaks ties. `api._better_body` (the attempt's saved best) and `stuck.best_bodies`
(sweep/fixup seeds) apply the same `effective_rows`, so every path serves the same body (T14).

Candidates are offered best-recorded-percent first and only the top MAX_MEASURED distinct
bodies within WINDOW are compiled; the newest RECENT bodies are measured as well, whatever
their recorded percent: a released attempt's rewrite with pool rows bound and fewer differing
rows (fn_10_12024's 94.0% final, 23rd by percent) was never measured, so the claim seeded the
old 97.1% body again.

Results are cached per (symbol, body hash, compiler, flags) in
.fzgx/seedrank.json, so a ranking compiles each candidate body once.
"""
from __future__ import annotations

import collections
import hashlib
import json
import re
import threading
from pathlib import Path
from typing import Iterable, List, Optional, Sequence, Tuple

from .project import STATE_DIR, Project, write_atomic

PENALTY = 5.0          # points per dropped semantic row
MAX_PENALTY = 15.0     # a badly broken body still ranks by its score beyond this
WINDOW = 15.0          # candidates further below the top than this are never promoted
IMPLICIT_PENALTY = 2.0  # a body calling undeclared functions (api.IMPLICIT_MARGIN: wrong C that still compiles)
DROPPED_ROWS = 2       # extra rows per dropped semantic row (it already counts once as a differing row)
MAX_MEASURED = 12      # distinct bodies measured per ranking (each is one cached compile)
RECENT = 4             # newest saved bodies measured regardless of their recorded percent
CACHE = STATE_DIR / "seedrank.json"
_MISSING = object()
_LOCK = threading.Lock()

ARITH_IMM = {"addi", "addic", "addic.", "addis", "mulli", "subfic", "ori", "oris", "xori", "xoris",
             "andi.", "andis.", "srawi", "srawi.", "slwi", "srwi"}
_REG = re.compile(r"\b(?:r(?:[02-9]|[12]\d|3[01])|f\d+|cr\d)\b")
_SYM = re.compile(r"[\w.$@]+@(?:sda21|ha|h|l)\b|\blbl_\w+|@\d+")


def _shape(row: dict) -> str:
    ins = row.get("instruction") or {}
    text = ins.get("formatted") or ""
    if not text:
        return ""
    return _SYM.sub("SYM", _REG.sub("R", text))


def _semantic(shape: str) -> bool:
    op, _, args = shape.partition(" ")
    parts = [a.strip() for a in args.split(",")]
    if op.startswith(("st", "psq_st")) and not op.startswith("stwu"):
        return "(r1)" not in args
    if op in ARITH_IMM and len(parts) >= 3:
        if "r1" in parts[1:2]:
            return False  # a stack address: frame layout, not program semantics
        imm = parts[-1]
        try:
            return int(imm, 0) != 0
        except ValueError:
            return imm == "SYM"  # an @l/@ha addend half
    return False


def dropped_rows(left: Sequence[dict], right: Sequence[dict], accepted: Iterable[int] = ()) -> List[str]:
    """Shapes of retail (left) rows whose store/immediate-arithmetic effect ours (right) lacks."""
    accepted = set(accepted)
    retail, ours = collections.Counter(), collections.Counter()
    for i, (a, b) in enumerate(zip(left, right)):
        if i in accepted:
            continue
        if (a.get("diff_kind") or "DIFF_NONE") == "DIFF_NONE" and (b.get("diff_kind") or "DIFF_NONE") == "DIFF_NONE":
            continue
        sa, sb = _shape(a), _shape(b)
        if sa == sb or (sa and sb and sa.split(" ", 1)[0] == sb.split(" ", 1)[0]):
            continue  # register names, or an operand difference: the instruction is there
        if sa:
            retail[sa] += 1
        if sb:
            ours[sb] += 1
    # an address addend retail materialises (`addi rX, rB, 0x5638` then `0(rX)`) that ours
    # folds into the access displacement (`0x5638(rB)`) is the section-layout addressing form,
    # not an omitted value: cancel it against our-only displacements just above it
    folded = [int(m, 0) for s in ours for m in re.findall(r"(-?0x[\da-f]+|-?\d+)\(R\)", s)]
    folded += [int(s.rsplit(",", 1)[1], 0) for s in ours
               if s.split(" ", 1)[0] in ("addi", "addis") and re.search(r", -?(?:0x[\da-f]+|\d+)$", s)]
    out = []
    for s in (retail - ours).elements():
        if not _semantic(s):
            continue
        op, _, args = s.partition(" ")
        if op == "addi" and not args.endswith("SYM"):
            imm = int(args.rsplit(",", 1)[1], 0)
            if any(imm <= d < imm + 0x100 for d in folded):
                continue
        out.append(s)
    return sorted(out)


def dropped_for(res) -> Optional[List[str]]:
    """dropped_rows of a CheckResult, None when the check has no row alignment."""
    rows = getattr(res, "_rows", None)
    if not res.ok or not rows:
        return None
    if res.matched:
        return []
    return dropped_rows(rows[0], rows[1], getattr(res, "_accepted_rows", ()))


def penalty(dropped: Optional[Sequence[str]]) -> float:
    return min(MAX_PENALTY, PENALTY * len(dropped or ()))


def _load() -> dict:
    try:
        return json.loads(CACHE.read_text())
    except (OSError, ValueError):
        return {}


def _key(symbol: str, body: str, mw: Optional[str], flags: Optional[str]) -> str:
    return "|".join(("v6", symbol, hashlib.sha256(body.encode()).hexdigest()[:16], mw or "", flags or ""))


def measure(p: Project, symbol: str, path: Path, mw: Optional[str] = None, flags: Optional[str] = None) -> Optional[dict]:
    """{'percent', 'dropped', 'implicit'} for one saved body (cached); None if it does not compile."""
    from . import oracle
    body = Path(path).read_text()
    key = _key(symbol, body, mw, flags)
    with _LOCK:
        hit = _load().get(key)
    if hit is not None:
        if "cancelling" not in hit:
            # measured before `oracle.self_cancelling` joined body_diagnostics (T16): textual,
            # no compile, so the cache keeps its key and only gains the verdict
            sym = p.resolve(symbol)
            hit["cancelling"] = oracle.self_cancelling(p, sym.module, body) if sym else []
            if hit["cancelling"]:
                hit["uninitialized"] = list(hit.get("uninitialized") or []) + [
                    n for n in hit["cancelling"] if n not in (hit.get("uninitialized") or [])]
                with _LOCK:
                    cache = _load()
                    cache[key] = hit
                    write_atomic(CACHE, json.dumps(cache))
        return hit
    res = oracle.check(p, symbol, 0, source=Path(path), mw_version=mw, extra_cflags=flags)
    out = None
    if res.ok:
        sym = p.resolve(symbol)
        diag = (oracle.body_diagnostics(p, sym.module, Path(path), res.mw_version, res.extra_cflags) if sym
                else {"implicit": [], "uninitialized": []})
        out = {"percent": round(oracle.progress_score(res), 4), "rows": oracle.progress_rows(res),
               "dropped": dropped_for(res) or [], "conflicts": len(getattr(res, "value_flow", None) or ()),
               "implicit": diag["implicit"], "uninitialized": diag["uninitialized"],
               "cancelling": [n for n in diag["uninitialized"] if n.startswith("self-cancelling")]}
    with _LOCK:
        cache = _load()
        cache[key] = out
        write_atomic(CACHE, json.dumps(cache))
    return out


def effective_rows(rows: Optional[int], dropped: int = 0, conflicts: int = 0) -> Optional[int]:
    """Differing rows weighted for selection: each dropped semantic row and each known
    store-value conflict (both capped at MAX_PENALTY // PENALTY) counts DROPPED_ROWS extra.
    None without a row alignment. Ranking only, never acceptance."""
    if rows is None:
        return None
    cap = int(MAX_PENALTY // PENALTY)
    return rows + DROPPED_ROWS * (min(int(dropped or 0), cap) + min(int(conflicts or 0), cap))


def rank_key(m: dict) -> tuple:
    """Sort key of a measured body (lower ranks first): a sound body before one calling undeclared
    functions or reading unassigned locals, then fewest `effective_rows` (a body without row
    alignment ranks after every aligned one), then the higher percent - penalty(dropped)."""
    unsound = bool(m.get("implicit") or m.get("uninitialized"))
    rows = effective_rows(m.get("rows"), len(m.get("dropped") or ()), m.get("conflicts") or 0)
    return (unsound, float("inf") if rows is None else rows,
            -(m["percent"] - penalty(m.get("dropped"))))


def cached(symbol: str, path: Path, mw: Optional[str] = None, flags: Optional[str] = None) -> Optional[dict]:
    """The cached measurement of a saved body (no compile): mw/flags default to the body's
    attempt sidecar (`PATH.json`). None when the body was never measured or does not exist;
    `{"failed": True}` when it was measured and did not compile."""
    try:
        body = Path(path).read_text()
    except OSError:
        return None
    if mw is None and flags is None:
        try:
            meta = json.loads(Path(path).with_suffix(".json").read_text())
            mw, flags = meta.get("mw") or None, meta.get("flags") or None
        except (OSError, ValueError):
            pass
    with _LOCK:
        hit = _load().get(_key(symbol, body, mw, flags), _MISSING)
    if hit is _MISSING:
        return None
    return hit if hit is not None else {"failed": True}  # measured: it did not compile


def pick(p: Project, symbol: str, candidates: Sequence[Tuple[float, Path, Optional[str], Optional[str]]],
         always: Iterable[int] = ()) -> Optional[int]:
    """Index of the candidate to seed from. `candidates` is (recorded percent, body path, mw,
    flags), best recorded first. Only bodies within WINDOW of the top are measured: the first
    MAX_MEASURED distinct ones plus every index in `always` (the newest saved bodies, which
    `ledger.ranked_local_attempt` names); the winner has the lowest `rank_key`, ties keep the
    recorded order."""
    if not candidates:
        return None
    always = set(always)
    top = candidates[0][0] or 0.0
    best, best_key, seen = 0, None, set()
    for i, (percent, path, mw, flags) in enumerate(candidates):
        if (percent or 0.0) < top - WINDOW:
            break
        if len(seen) >= MAX_MEASURED and i not in always:
            continue
        try:
            digest = (hashlib.sha256(Path(path).read_bytes()).hexdigest(), mw, flags)
        except OSError:
            continue
        if digest in seen:
            continue
        seen.add(digest)
        m = measure(p, symbol, Path(path), mw, flags)
        if m is None:
            continue
        key = rank_key(m)
        if best_key is None or key < best_key:
            best, best_key = i, key
    return best
