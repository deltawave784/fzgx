"""Overall progress over time: the matched-code percentage objdiff reports, one row per measurement.

`build/<version>/report.json` is rewritten by every `ninja` (the progress target); this module reads
its `measures`, appends a row to `state/progress.csv` when the matched code changed (or a note is
given), and reports the change since the previous row and since the first. The CSV is committed:
it is the history of the number the project is judged by.
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
