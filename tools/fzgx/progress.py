"""Overall progress over time: the matched-code percentage objdiff reports, one row per measurement.

`build/<version>/report.json` is rewritten by every `ninja` (the progress target); this module reads
its `measures`, appends a row to `state/progress.csv` when the matched code changed (or a note is
given), and reports the change since the previous row and since the first. The CSV is committed:
it is the history of the number the project is judged by. `git_head` is the HEAD that was measured:
the progress commit that records the row comes after it, so a batch without matches stamps the
previous batch's progress commit.
"""

from __future__ import annotations

import csv
import json
import subprocess
import time
from pathlib import Path
from typing import Dict, List, Optional

from .project import ROOT, Project

FIELDS = ["time_utc", "git_head", "matched_code_pct", "matched_code", "total_code",
          "matched_functions", "total_functions", "complete_code_pct", "note"]
CSV = ROOT / "state" / "progress.csv"


def refresh(p: Project) -> Optional[str]:
    """Bring `report.json` up to date with the linked tree before it is read. `fzgx verify` and the
    batch drain build only `build/<v>/ok`, never the report, so a row recorded straight after a
    match measured the previous build (every row from batch 282 to 287 lagged one match). Runs
    `ninja <report>` under the build lock (a no-op when current); returns an error string or None."""
    from . import oracle
    report = p.build_dir / "report.json"
    try:
        with oracle.build_lock():
            cp = oracle.run(["ninja", p.rel(report)], timeout=1800)
    except oracle.LockTimeout as e:
        return str(e)
    if cp.returncode != 0:
        return f"ninja {p.rel(report)} failed: {(cp.stdout or '')[-400:]}"
    ok = p.build_dir / "ok"
    if ok.exists() and report.exists() and report.stat().st_mtime < ok.stat().st_mtime:
        return f"{p.rel(report)} is older than {p.rel(ok)} after the refresh"
    return None


def measure(p: Project) -> Dict[str, object]:
    report = p.build_dir / "report.json"
    m = json.loads(report.read_text())["measures"]
    head = subprocess.run(["git", "rev-parse", "--short", "HEAD"], cwd=ROOT, text=True, capture_output=True).stdout.strip()
    return {"time_utc": time.strftime("%Y-%m-%dT%H:%M:%SZ", time.gmtime()), "git_head": head,
            "matched_code_pct": round(float(m["matched_code_percent"]), 4), "matched_code": int(m["matched_code"]),
            "total_code": int(m["total_code"]), "matched_functions": int(m["matched_functions"]),
            "total_functions": int(m["total_functions"]), "complete_code_pct": round(float(m["complete_code_percent"]), 4),
            "note": "", "_report_age_s": int(time.time() - report.stat().st_mtime)}


def rows() -> List[Dict[str, str]]:
    if not CSV.exists():
        return []
    with CSV.open(newline="") as f:
        return list(csv.DictReader(f))


def record(row: Dict[str, object], note: str = "") -> bool:
    """Append `row` unless the matched code is unchanged and there is no note. True when written."""
    history = rows()
    if history and not note and int(history[-1]["matched_code"]) == row["matched_code"]:
        return False
    CSV.parent.mkdir(parents=True, exist_ok=True)
    new = not CSV.exists()
    with CSV.open("a", newline="") as f:
        w = csv.DictWriter(f, fieldnames=FIELDS, extrasaction="ignore")
        if new:
            w.writeheader()
        w.writerow(dict(row, note=note))
    return True


def summary(row: Dict[str, object], history: List[Dict[str, str]]) -> str:
    line = (f"{row['matched_code_pct']:.2f}% of code ({row['matched_code']:,} / {row['total_code']:,} bytes), "
            f"{row['matched_functions']:,} / {row['total_functions']:,} functions")
    if history:
        prev, first = history[-1], history[0]
        line += (f"\n  since last row ({prev['time_utc'][:16]}): {row['matched_code'] - int(prev['matched_code']):+,} B, "
                 f"{row['matched_code_pct'] - float(prev['matched_code_pct']):+.3f} pts, "
                 f"{row['matched_functions'] - int(prev['matched_functions']):+d} fns"
                 f"\n  since first row ({first['time_utc'][:16]}): {row['matched_code'] - int(first['matched_code']):+,} B, "
                 f"{row['matched_code_pct'] - float(first['matched_code_pct']):+.3f} pts, "
                 f"{row['matched_functions'] - int(first['matched_functions']):+d} fns")
    return line
