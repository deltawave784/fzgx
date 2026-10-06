"""Deterministic routing of unmatched functions to agent tiers for a Claude Code wave.

The dispatcher (a Claude Code session) runs `fzgx route`, then starts one subagent per row
with the agent type in `agent_type`. No model decides what to work on next.

  sonnet  `matcher-mid`    functions up to --small bytes
  opus    `matcher-large`  larger functions, and small ones Sonnet already attempted when
                           escalating (`--escalate-from sonnet`)

Haiku was dropped from matching (2026-10-03): on an interleaved pool of small near misses it
closed 0 of 5 where Sonnet closed 2 of 8, ended 2-40 points lower, and took 2-3x as long.

Ordering puts cheap wins first: functions with a saved body on this machine (the claim seeds
the agent with it) by remaining bytes, then near misses without one (a restored ledger keeps the
scores of bodies that stayed on the recording machine; those agents start over), then small
functions, then the rest by size. Claimed, blocked and assembly-only functions are skipped.
"""

from __future__ import annotations

from typing import Dict, List, Optional

from .ledger import Ledger
from .project import Project

AGENT = {"sonnet": "matcher-mid", "opus": "matcher-large"}


def tier_for(size: int, symbol: str, small: int, escalate: set) -> str:
    if size > small or symbol in escalate:
        return "opus"
    return "sonnet"


def plan(p: Project, limit: int = 8, small: int = 256, near: float = 80.0,
         module: Optional[str] = None, tier: Optional[str] = None,
         escalate: Optional[set] = None, exclude: Optional[set] = None,
         easy: bool = False, max_size: Optional[int] = None, max_attempts: Optional[int] = None,
         min_size: Optional[int] = None) -> List[Dict]:
    """`easy` is the Opus/Sonnet fallback ordering used while the Fable window is exhausted: smallest
    functions first, no preference for a saved 99% body (those are the near misses Fable and the
    earlier waves already failed on), one function per (module, size) retail-clone family, and
    `max_size` / `max_attempts` cut off big or repeatedly failed functions. Ordering is size, then
    attempts: untouched functions are all large (the small ones were attempted long ago)."""
    ledger = Ledger()
    rows = ledger.db.execute(
        "SELECT symbol, module, size, attempts, best_percent AS best, claimed_by FROM functions "
        "WHERE status = 'unmatched'" + (" AND module = ?" if module else ""),
        (module,) if module else ()).fetchall()
    escalate = escalate or set()
    out = []
    for r in rows:
        if r["claimed_by"] or (exclude and r["symbol"] in exclude):
            continue
        if easy and (r["symbol"].endswith(":_prolog") or r["symbol"].startswith(("__save_", "__restore_", "_savegpr", "_restgpr", "_savefpr", "_restfpr"))):
            continue  # entry points and compiler FPR/GPR save helpers: not C a matcher can write
        if max_size is not None and r["size"] > max_size:
            continue
        if min_size is not None and r["size"] < min_size:
            continue
        if max_attempts is not None and (r["attempts"] or 0) > max_attempts:
            continue
        best = r["best"] or 0
        t = tier_for(r["size"], r["symbol"], small, escalate)
        if tier and t != tier:
            continue
        found = ledger.best_local_attempt(r["symbol"])
        seeded = found is not None
        seed_best = (found[0]["best_in_attempt"] or found[0]["final_percent"] or 0) if found else None
        remaining = r["size"] * (1 - (seed_best if seeded else best) / 100)
        rank = ((0, remaining) if seeded else (1, remaining) if best >= near else
                (2, r["size"]) if r["size"] <= small else (3, r["size"]))
        if easy:
            rank = (r["size"], r["attempts"] or 0)
        out.append(dict(symbol=r["symbol"], module=r["module"], size=r["size"], attempts=r["attempts"],
                        best=round(best, 1), seeded=seeded,
                        seed_best=round(seed_best, 1) if seeded else None, tier=t, agent_type=AGENT[t], _rank=rank))
    out.sort(key=lambda d: d.pop("_rank"))
    if easy:
        families, kept = set(), []
        for d in out:
            key = (d["module"], d["size"])
            if key in families:
                continue
            families.add(key)
            kept.append(d)
        out = kept
    return out[:limit]


def tried_by(prefix: str) -> set:
    """Symbols a tier already attempted, by agent-id prefix (`sonnet-...`, as the match-wave
    skill names agents) or by recorded model name."""
    rows = Ledger().db.execute("SELECT DISTINCT symbol FROM attempts WHERE (agent LIKE ? OR model LIKE ?) "
                               "AND COALESCE(outcome, '') != 'crash' AND COALESCE(notes, '') NOT LIKE '%usageLimitExceeded%'",
                               (prefix + "%", prefix + "%")).fetchall()
    return {r["symbol"] for r in rows}


def fable_plan(p: Project, limit: int = 8, min_percent: float = 98.0, max_attempts: int = 12,
               module: Optional[str] = None) -> List[Dict]:
    """Next near misses for a Fable batch (agent type `matcher-large`, model fable).

    Unmatched, unclaimed functions whose best recorded score is at least `min_percent`, that no
    Fable agent has attempted, best score first, one per (module, size) family. A family that
    contains a function Fable already attempted is skipped: its members are retail clones, so a
    match carries over through `reuse` and a failure repeats."""
    db = Ledger().db
    tried = {r[0] for r in db.execute("SELECT DISTINCT symbol FROM attempts WHERE agent LIKE 'fable-%'")}
    rows = db.execute(
        "SELECT f.symbol, f.module, f.size, f.attempts, MAX(COALESCE(a.best_in_attempt, a.final_percent, 0)) AS best "
        "FROM functions f LEFT JOIN attempts a ON a.symbol = f.symbol "
        "WHERE f.status = 'unmatched' AND f.claimed_by IS NULL AND f.attempts < ? AND f.symbol NOT LIKE '%:_prolog' "
        + ("AND f.module = ? " if module else "") +
        "GROUP BY f.symbol HAVING best >= ? ORDER BY best DESC",
        (max_attempts, *((module,) if module else ()), min_percent)).fetchall()
    sizes = {(r["module"], r["size"]) for r in db.execute(
        "SELECT module, size, symbol FROM functions").fetchall() if r["symbol"] in tried}
    out, seen = [], set()
    for r in rows:
        key = (r["module"], r["size"])
        if r["symbol"] in tried or key in sizes or key in seen:
            continue
        seen.add(key)
        out.append(dict(symbol=r["symbol"], module=r["module"], size=r["size"], attempts=r["attempts"],
                        best=round(r["best"], 1), tier="fable", agent_type="matcher-large", model="fable"))
        if len(out) >= limit:
            break
    return out
