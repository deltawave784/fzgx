"""Unattended Codex batches: route, run, gate, repeat until a stop condition.

Run from a clone with `uv run tools/codex_loop.py`. Each round picks functions with
`fzgx route`, runs one `orchestrate.py --harness codex` batch (which verifies and commits
its own matches), then runs `fzgx gate`. Size bands go in order; a band is left when the
router has nothing new in it. Functions the model already attempted are skipped.

When the Codex account runs out of usage ("try again at 3:35 AM"), the loop marks the
crashed sessions as crashes (they do not count as attempts), sleeps until the reset time
plus a few minutes, and continues. Only completed batches count toward `--max-batches`.

Stops on: `--max-batches`, `--hours` (wall clock, waits included), `--zero-streak` batches in
a row without a match in the last band, a failed gate, an empty pool, or the file
`.fzgx/STOP` (create it to stop after the current batch or wait). Never pushes.
Log: `.fzgx/reports/codex_loop.log`.
"""

from __future__ import annotations

import argparse
import datetime
import json
import re
import sqlite3
import subprocess
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
MODULES = ["main", "movie_module", "customize", "sel", "pilotpoint", "option", "title", "interview",
           "story", "profile", "movie", "winning", "replay", "car_colchg", "sample"]
# (min bytes, max bytes, effort, checks per worker, stale checks) in the order they are worked
BANDS = [(512, 1023, "medium", 24, 8), (1024, 2047, "high", 32, 10), (256, 511, "medium", 16, 5),
         (2048, 4095, "high", 40, 12), (0, 255, "medium", 12, 4), (4096, 100000, "high", 48, 14)]


def run(cmd: list, capture: bool = False) -> subprocess.CompletedProcess:
    return subprocess.run([sys.executable, *cmd], cwd=ROOT, text=True, capture_output=capture)


def log(msg: str) -> None:
    line = f"{time.strftime('%Y-%m-%d %H:%M:%S')} {msg}"
    print(line, flush=True)
    path = ROOT / ".fzgx" / "reports" / "codex_loop.log"
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("a", encoding="utf-8") as f:
        f.write(line + "\n")


def pick(model: str, lo: int, hi: int, per_module: int, count: int, max_attempts: int) -> list:
    out = []
    for module in MODULES:
        res = run(["tools/fzgx.py", "route", "--easy", "--module", module, "--min-size", str(lo),
                   "--max-size", str(hi), "--max-attempts", str(max_attempts), "--skip-tried-by", model,
                   "--limit", str(per_module), "--json"], capture=True)
        try:
            out += [r["symbol"] for r in json.loads(res.stdout)]
        except (ValueError, KeyError):
            continue
    return out[:count]


def usage_limit(batch: str, failed: int = 1):
    """The reset time (datetime) when the batch's sessions hit the usage limit, else None.
    Falls back to 30 minutes ahead when the message carries no time. A real limit crashes
    sessions (`failed` > 0), and prompts/assignments quote earlier attempts' notes (a
    function's best prior attempt can carry an old limit message), so those never count."""
    if failed <= 0:
        return None
    folder = ROOT / ".fzgx" / "runs" / batch
    hit, when = False, None
    for path in folder.glob("*"):
        if path.suffix not in (".log", ".jsonl", ".json"):
            continue
        if ".assignment." in path.name or ".prompt." in path.name:
            continue
        text = path.read_text(encoding="utf-8", errors="replace")
        if "usageLimitExceeded" not in text and "usage limit" not in text:
            continue
        hit = True
        m = re.search(r"try again at (\d{1,2}):(\d{2}) ?([AP]M)", text)
        if m:
            hour = int(m.group(1)) % 12 + (12 if m.group(3) == "PM" else 0)
            when = datetime.datetime.now().replace(hour=hour, minute=int(m.group(2)), second=0, microsecond=0)
            if when <= datetime.datetime.now():
                when += datetime.timedelta(days=1)
            break
    if not hit:
        return None
    return when or datetime.datetime.now() + datetime.timedelta(minutes=30)


def forgive_crashes() -> int:
    """Crashed sessions are not attempts: mark them and give the attempt back."""
    db = sqlite3.connect(ROOT / ".fzgx" / "ledger.db")
    rows = db.execute("SELECT symbol, COUNT(*) FROM attempts WHERE notes LIKE '%usageLimitExceeded%' "
                      "AND COALESCE(outcome, '') != 'crash' GROUP BY symbol").fetchall()
    for symbol, count in rows:
        db.execute("UPDATE functions SET attempts = MAX(0, attempts - ?) WHERE symbol = ?", (count, symbol))
    db.execute("UPDATE attempts SET outcome = 'crash' WHERE notes LIKE '%usageLimitExceeded%'")
    db.commit()
    db.close()
    return sum(c for _, c in rows)


def wait_until(when, stop_file: Path, deadline: float) -> bool:
    """Sleep until `when` (plus a margin), polling the stop file. False if told to stop."""
    when += datetime.timedelta(minutes=3)
    log(f"usage limit: waiting until {when:%H:%M} (create .fzgx/STOP to stop)")
    while datetime.datetime.now() < when:
        if stop_file.exists() or time.time() > deadline:
            return False
        time.sleep(30)
    return True


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--model", default="gpt-6.1-sol")
    ap.add_argument("--batch-size", type=int, default=16)
    ap.add_argument("--per-module", type=int, default=6)
    ap.add_argument("--max-attempts", type=int, default=6)
    ap.add_argument("--max-batches", type=int, default=6)
    ap.add_argument("--hours", type=float, default=24.0)
    ap.add_argument("--zero-streak", type=int, default=3)
    ap.add_argument("--parallel", type=int, default=12)
    a = ap.parse_args()

    stop_file = ROOT / ".fzgx" / "STOP"
    started, streak, total, band, n, waits = time.time(), 0, 0, 0, 0, 0
    deadline = started + a.hours * 3600
    while n < a.max_batches:
        n += 1
        if stop_file.exists():
            log("stop file present"); break
        if time.time() - started > a.hours * 3600:
            log("time limit"); break
        symbols = []
        while band < len(BANDS):
            lo, hi, effort, checks, stale = BANDS[band]
            symbols = pick(a.model, lo, hi, a.per_module, a.batch_size, a.max_attempts)
            if symbols:
                break
            log(f"band {lo}-{hi} B empty")
            band += 1
        if not symbols:
            log("pool empty"); break
        batch = f"codex-goal-{time.strftime('%Y%m%d-%H%M')}-{n}"
        log(f"{batch}: {len(symbols)} functions, band {lo}-{hi} B, effort {effort}")
        res = run(["tools/orchestrate.py", "--harness", "codex", "--provider", "openai", "--model", a.model,
                   "--effort", effort, "--parallel", str(a.parallel), "--max-checks", str(checks),
                   "--max-stale", str(stale), "--max-attempts", "12", "--no-trivial", "--batch", batch,
                   "--symbols", *symbols], capture=True)
        summary = {}
        for line in reversed(res.stdout.splitlines()):
            if line.startswith("{") and '"matched"' in line:
                summary = json.loads(line)
                break
        matched = summary.get("matched", 0)
        total += matched
        log(f"{batch}: {matched} matched, {summary.get('released', '?')} released, "
            f"{summary.get('failed', '?')} failed, {summary.get('wall_s', '?')}s (total {total})")
        reset = usage_limit(batch, summary.get("failed", 0))
        if reset:
            log(f"{forgive_crashes()} crashed sessions returned to the pool")
            waits += 1
            if summary.get("failed", 0) >= len(symbols) and not matched:
                n -= 1  # a batch that never ran does not count
            if waits > 8 or not wait_until(reset, stop_file, deadline):
                log("stopping after usage limit"); break
            if summary.get("failed", 0) >= len(symbols) and not matched:
                continue
        elif summary.get("failed", 0) >= len(symbols) and not matched:
            log("every session crashed for another reason; stopping. Check .fzgx/runs/" + batch)
            break
        if res.returncode != 0 and not summary:
            log("orchestrate failed:\n" + (res.stderr or res.stdout)[-1500:]); break
        gate = run(["tools/fzgx.py", "gate"], capture=True)
        if "GATE: PASS" not in gate.stdout:
            log("GATE FAILED, stopping:\n" + gate.stdout[-1500:]); return 1
        if matched:
            run(["tools/fzgx.py", "progress", "--note", f"codex-goal {batch}"], capture=True)
        streak = 0 if matched else streak + 1
        if streak >= a.zero_streak:
            if band + 1 < len(BANDS):
                band += 1
                streak = 0
                log(f"{a.zero_streak} batches without a match: moving to band {BANDS[band][0]}-{BANDS[band][1]} B")
            else:
                log(f"{a.zero_streak} batches without a match in the last band"); break
    log(f"done: {total} matched")
    return 0


if __name__ == "__main__":
    sys.exit(main())
