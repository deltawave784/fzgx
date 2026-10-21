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
CACHE = STATE_DIR / "seedrank.json"
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
    return "|".join(("v4", symbol, hashlib.sha256(body.encode()).hexdigest()[:16], mw or "", flags or ""))


def measure(p: Project, symbol: str, path: Path, mw: Optional[str] = None, flags: Optional[str] = None) -> Optional[dict]:
    """{'percent', 'dropped', 'implicit'} for one saved body (cached); None if it does not compile."""
    from . import oracle
    body = Path(path).read_text()
    key = _key(symbol, body, mw, flags)
    with _LOCK:
        hit = _load().get(key)
    if hit is not None:
        return hit
    res = oracle.check(p, symbol, 0, source=Path(path), mw_version=mw, extra_cflags=flags)
    out = None
    if res.ok:
        sym = p.resolve(symbol)
        diag = (oracle.body_diagnostics(p, sym.module, Path(path), res.mw_version, res.extra_cflags) if sym
                else {"implicit": [], "uninitialized": []})
        out = {"percent": round(oracle.progress_score(res), 4), "dropped": dropped_for(res) or [],
               "implicit": diag["implicit"], "uninitialized": diag["uninitialized"]}
    with _LOCK:
        cache = _load()
        cache[key] = out
        write_atomic(CACHE, json.dumps(cache))
    return out


def pick(p: Project, symbol: str, candidates: Sequence[Tuple[float, Path, Optional[str], Optional[str]]]) -> Optional[int]:
    """Index of the candidate to seed from. `candidates` is (recorded percent, body path, mw,
    flags), best recorded first. Only bodies within WINDOW of the top are measured; the
    winner maximises percent - penalty(dropped), ties keep the recorded order."""
    if not candidates:
        return None
    top = candidates[0][0] or 0.0
    best, best_score, seen = 0, None, set()
    for i, (percent, path, mw, flags) in enumerate(candidates):
        if (percent or 0.0) < top - WINDOW:
            break
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
        score = (m["percent"] - penalty(m["dropped"])
                 - (IMPLICIT_PENALTY if (m.get("implicit") or m.get("uninitialized")) else 0.0))
        if best_score is None or score > best_score:
            best, best_score = i, score
        if len(seen) >= 6:
            break
    return best
