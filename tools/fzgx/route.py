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
         escalate: Optional[set] = None, exclude: Optional[set] = None) -> List[Dict]:
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
        out.append(dict(symbol=r["symbol"], module=r["module"], size=r["size"], attempts=r["attempts"],
                        best=round(best, 1), seeded=seeded,
                        seed_best=round(seed_best, 1) if seeded else None, tier=t, agent_type=AGENT[t], _rank=rank))
    out.sort(key=lambda d: d.pop("_rank"))
    return out[:limit]


def tried_by(prefix: str) -> set:
    """Symbols a tier already attempted, by agent-id prefix (`sonnet-...`, as the match-wave
    skill names agents) or by recorded model name."""
    rows = Ledger().db.execute("SELECT DISTINCT symbol FROM attempts WHERE agent LIKE ? OR model LIKE ?",
                               (prefix + "%", prefix + "%")).fetchall()
    return {r["symbol"] for r in rows}
