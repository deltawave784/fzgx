"""The gate a tooling change must pass before it stays.

A tooling round edits `tools/`; the build and the oracle are what the whole project's correctness rests
on, so a change is kept only if, with nothing else running:
  1. `fzgx lint` is clean and `ninja` builds with all 16 target hashes OK;
  2. a sample of already-matched pool-mapped units still check as exact matches under the new oracle;
  3. the most recent matches (the last batch's work) still check as exact matches.
Units whose own compile fails before any comparison (a pre-existing flag-quoting problem on a few
units) are reported as skipped, not failed.
"""

from __future__ import annotations

import random
import subprocess
from typing import Dict, List

from . import compat, oracle
from .ledger import Ledger
from .project import ROOT, Project


def _hashes() -> int:
    cp = subprocess.run([str(compat.tool("dtk")), "shasum", "-c", "config/GFZE01/build.sha1"], cwd=ROOT,
                        text=True, capture_output=True)
    return (cp.stdout + cp.stderr).count("OK")


def _check_units(p: Project, symbols: List[str]) -> Dict[str, List[str]]:
    out: Dict[str, List[str]] = {"passed": [], "failed": [], "skipped": []}
    for s in symbols:
        try:
            r = oracle.check(p, s, 0)
        except Exception as e:  # noqa: BLE001 - a crash is a failure to report, not to hide
            out["failed"].append(f"{s}: {str(e)[:80]}")
            continue
        if not r.ok:
            reason = (r.error or "")[:90].replace("\n", " ")
            (out["skipped"] if "Usage Error" in (r.error or "") else out["failed"]).append(f"{s}: {reason}")
        elif r.matched or r.matched_pool:
            # an exact match is the criterion: re-checking a carved DOL unit also lists its helper
            # (dead-stripped by the DOL link) as "extra", which `unit_fully_matches` would refuse and
            # never did for these units
            out["passed"].append(s)
        else:
            out["failed"].append(f"{s}: {r.percent:.1f}%")
    return out


def run(p: Project, pool_sample: int = 24, recent: int = 24, seed: int = 7, also=()) -> Dict[str, object]:
    report: Dict[str, object] = {"ok": False}
    lint = subprocess.run(["uv", "run", "tools/fzgx.py", "lint"], cwd=ROOT, text=True, capture_output=True)
    report["lint"] = (lint.stdout.strip().splitlines() or [""])[-1]
    if "0 finding" not in report["lint"]:
        return report
    build = subprocess.run(["uv", "run", "ninja"], cwd=ROOT, text=True, capture_output=True)
    report["build_ok"] = build.returncode == 0
    report["hashes_ok"] = _hashes()
    if build.returncode or report["hashes_ok"] != 16:
        return report
    units = [u for u in p.load_units() if isinstance(u.get("pool"), dict) and u.get("status") == "matching" and not u.get("asm")]
    random.Random(seed).shuffle(units)
    report["pool_sample"] = _check_units(p, [u["symbols"][0] for u in units[:pool_sample]])
    db = Ledger().db
    latest = [r[0] for r in db.execute(
        "SELECT symbol FROM attempts WHERE outcome='matched' AND agent NOT LIKE 'diag%' ORDER BY id DESC LIMIT ?", (recent * 2,))]
    seen, chosen = set(), []
    for s in latest:
        if s not in seen and (p.resolve(s) is not None):
            seen.add(s); chosen.append(s)
        if len(chosen) >= recent:
            break
    report["recent"] = _check_units(p, chosen)
    if also:  # the units a change is known to touch: named by the round, re-checked in full
        report["named"] = _check_units(p, [s for s in also if p.resolve(s) is not None])
    report["ok"] = not any(report[k]["failed"] for k in ("pool_sample", "recent", "named") if k in report)
    return report
