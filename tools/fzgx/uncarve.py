"""Undo a carve: a unit that has no matched code behind it goes back to the retail auto object.

Removes the units.json entry, the split range, the generated or stub source, and clears the
ledger's unit column. Used for units verify rejects and for legacy stubs (`--stubs`), so the
unit count stays at the matched count (a stub is a linker object for nothing).
"""

from __future__ import annotations

from typing import Dict, List

from . import collapse, oracle, tufile
from .ledger import Ledger
from .project import ROOT, Project


def stubs(p: Project) -> List[dict]:
    """Units with no matched code: nonmatching, not a pool match, and no function matched in the ledger.

    A pool match keeps `status: nonmatching` with `pool: true` in units.json (the retail object
    still links), so the units.json status alone would select committed matches.
    """
    l = Ledger()
    matched = {r[0] for r in l.db.execute("SELECT symbol FROM functions WHERE status='matched'")}
    out = []
    for u in p.load_units():
        if u.get("status") != "nonmatching" or u.get("pool"):
            continue
        keys = set()
        for s in u.get("symbols", []):
            keys.add(s)
            r = p.resolve(s)
            if r:
                keys.add(p.key(r))
        if keys & matched:
            continue
        rows = l.db.execute("SELECT 1 FROM functions WHERE unit=? AND status='matched' LIMIT 1", (u["source"],))
        if rows.fetchone():
            continue
        out.append(u)
    return out


def uncarve(p: Project, sources: List[str], split: bool = True) -> Dict[str, object]:
    """Drop the units named by source path. Re-splits (unless split=False) but does not relink."""
    want = set(sources)
    with oracle.build_lock("units.lock"):
        units = p.load_units()
        gone = [u for u in units if u["source"] in want]
        keep = [u for u in units if u["source"] not in want]
        by_module: Dict[str, List[str]] = {}
        for u in gone:
            by_module.setdefault(u["module"], []).append(u["source"])
            if u.get("tu"):
                tufile.remove(p, u)  # a block, if one exists
                tufile.gen_path(p, u["source"]).unlink(missing_ok=True)
            else:
                (ROOT / "src" / u["source"]).unlink(missing_ok=True)
        for module, srcs in by_module.items():
            spath = p.module_config_dir(module) / "splits.txt"
            spath.write_text(collapse._splits_without(spath.read_text(), srcs))
        p.save_units(keep)
    l = Ledger()
    for u in gone:
        for s in u.get("symbols", []):
            l.db.execute("UPDATE functions SET unit=NULL, link_state=NULL WHERE symbol=? AND status<>'matched'", (p.key(p.resolve(s)) if p.resolve(s) else s,))
    l.db.commit()
    if split and gone:
        from .api import _reconfigure_and_split
        _reconfigure_and_split(p)
    return {"removed": len(gone), "modules": sorted(by_module)}
