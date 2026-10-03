"""Deterministic routing of unmatched functions to agent tiers for a Claude Code wave.

The dispatcher (a Claude Code session) runs `fzgx route`, then starts one subagent per row
with the agent type in `agent_type`. No model decides what to work on next.

  haiku   `matcher`        functions up to --small bytes
  sonnet  `matcher-mid`    with --mid: small near misses (best >= --near %), and small
                           functions the haiku tier already attempted (escalation)
  opus    `matcher-large`  larger functions; small escalations too when --mid is off

Ordering puts cheap wins first: near misses by remaining bytes, then small functions, then
the rest by size. Claimed, blocked and assembly-only functions are skipped.
"""

from __future__ import annotations

from typing import Dict, List, Optional

from .ledger import Ledger
from .project import Project

AGENT = {"haiku": "matcher", "sonnet": "matcher-mid", "opus": "matcher-large"}


def tier_for(size: int, best: float, symbol: str, small: int, near: float, mid: bool,
             haiku_tried: set) -> str:
    if size > small:
        return "opus"
    if symbol in haiku_tried:
        return "sonnet" if mid else "opus"
    if mid and best >= near:
        return "sonnet"
    return "haiku"


def plan(p: Project, limit: int = 8, small: int = 256, near: float = 80.0,
         module: Optional[str] = None, tier: Optional[str] = None, mid: bool = False,
         haiku_tried: Optional[set] = None) -> List[Dict]:
    rows = Ledger().db.execute(
        "SELECT symbol, module, size, attempts, best_percent AS best, claimed_by FROM functions "
        "WHERE status = 'unmatched'" + (" AND module = ?" if module else ""),
        (module,) if module else ()).fetchall()
    haiku_tried = haiku_tried or set()
    out = []
    for r in rows:
        if r["claimed_by"]:
            continue
        best = r["best"] or 0
        t = tier_for(r["size"], best, r["symbol"], small, near, mid, haiku_tried)
        if tier and t != tier:
            continue
        remaining = r["size"] * (1 - best / 100)
        rank = (0, remaining) if best >= near else (1, r["size"]) if r["size"] <= small else (2, r["size"])
        out.append(dict(symbol=r["symbol"], module=r["module"], size=r["size"], attempts=r["attempts"],
                        best=round(best, 1), tier=t, agent_type=AGENT[t], _rank=rank))
    out.sort(key=lambda d: d.pop("_rank"))
    return out[:limit]


def tried_by(prefix: str) -> set:
    """Symbols a tier already attempted, by agent-id prefix (`haiku-...`, as the match-wave
    skill names agents) or by recorded model name."""
    rows = Ledger().db.execute("SELECT DISTINCT symbol FROM attempts WHERE agent LIKE ? OR model LIKE ?",
                               (prefix + "%", prefix + "%")).fetchall()
    return {r["symbol"] for r in rows}
