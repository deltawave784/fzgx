"""Unattended Codex batches: route, run, gate, repeat until a stop condition.

Run from a clone with `uv run tools/codex_loop.py`. Each round picks functions with
`fzgx route`, runs one `orchestrate.py --harness codex` batch (which verifies and commits
its own matches), then runs `fzgx gate`. Size bands go in order; a band is left when the
router has nothing new in it. Functions the model already attempted are skipped.

When the Codex account runs out of usage ("try again at 3:35 AM"), the loop marks the
crashed sessions as crashes (they do not count as attempts), sleeps until the reset time
plus a few minutes, and continues. Only completed batches count toward `--max-batches`.

The loop runs Sol (`--model`) only. When the easy size bands are used up Sol moves to a hard pool of saved near
misses and large functions, routed like the Claude loop's Fable batches, and then to one retry of every function
it already tried (near misses first). GPT-6 Astra batches are opt-in
(`--astra-max N`, `--astra-batch`, `--astra-model`): they burn the weekly limit several times faster.
`--max-attempts` (default 12) is how many attempts a function may already have and still be picked, and
`--modules` picks the modules (default: all of them; in main_rel only the slice the Claude loop does not
route: over 768 B, best score under 85%, never attempted by Fable/Opus/Sonnet).

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
           "story", "profile", "movie", "winning", "replay", "car_colchg", "sample", "main_rel"]
# main_rel belongs to the Claude loop (clone A); this loop only takes the slice that loop does not route: functions
# above CLAUDE_SMALL bytes (its Opus/Sonnet fallback stops at 768) whose best score is below CLAUDE_FLOOR percent
# (its Fable floor is 85), minus anything a Claude tier already attempted (read from state/ledger.json).
SHARED_MODULE, CLAUDE_SMALL, CLAUDE_FLOOR = "main_rel", 768, 85.0
_claude_tried: set = set()
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


def claude_tried() -> set:
    """Symbols a Claude tier (fable-/opus-/sonnet-/haiku- agent ids) attempted, from clone A's committed ledger."""
    if not _claude_tried:
        try:
            data = json.loads((ROOT / "state" / "ledger.json").read_text(encoding="utf-8"))
            _claude_tried.update(a["symbol"] for a in data["attempts"]
                                 if str(a.get("agent", "")).startswith(("fable-", "opus-", "sonnet-", "haiku-")))
        except (OSError, ValueError, KeyError):
            pass
        _claude_tried.add("")  # also stops an unreadable ledger from re-reading it on every call
    return _claude_tried


def allowed(row: dict) -> bool:
    """False for a main_rel function the Claude loop owns."""
    if row.get("module") != SHARED_MODULE:
        return True
    best = max(row.get("seed_best") or 0.0, row.get("best") or 0.0)
    return row.get("size", 0) > CLAUDE_SMALL and best < CLAUDE_FLOOR and row["symbol"] not in claude_tried()


def pick(model: str, lo: int, hi: int, per_module: int, count: int, max_attempts: int) -> list:
    out = []
    for module in MODULES:
        shared = module == SHARED_MODULE
        res = run(["tools/fzgx.py", "route", "--easy", "--module", module,
                   "--min-size", str(max(lo, CLAUDE_SMALL + 1) if shared else lo),
                   "--max-size", str(hi), "--max-attempts", str(max_attempts), "--skip-tried-by", model,
                   "--limit", str(per_module * 8 if shared else per_module), "--json"], capture=True)
        try:
            out += [r["symbol"] for r in json.loads(res.stdout) if allowed(r)][:per_module]
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
        m = re.search(r"try again at (?:([A-Z][a-z]{2}) (\d{1,2})(?:st|nd|rd|th)?, (\d{4}) )?(\d{1,2}):(\d{2}) ?([AP]M)", text)
        if m:
            hour = int(m.group(4)) % 12 + (12 if m.group(6) == "PM" else 0)
            now = datetime.datetime.now()
            if m.group(1):  # a weekly limit names the date: "try again at Oct 13th, 2026 9:28 PM"
                day = datetime.datetime.strptime(f"{m.group(1)} {m.group(2)} {m.group(3)}", "%b %d %Y")
                when = day.replace(hour=hour, minute=int(m.group(5)))
            else:
                when = now.replace(hour=hour, minute=int(m.group(5)), second=0, microsecond=0)
                if when <= now:
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
    log(f"usage limit: waiting until {when:%a %b %d %H:%M} (create .fzgx/STOP to stop)")
    while datetime.datetime.now() < when:
        if stop_file.exists() or time.time() > deadline:
            return False
        time.sleep(30)
    return True


def pick_hard(model: str, count: int, max_attempts: int, modules: list, tried_by: str = "", exclude=(), limit: int = 12):
    """Hard functions the model has not tried, the way the Claude loop routes Fable: saved near misses
    first (90-99.9%), then big functions with a partial body, then big ones, then anything left (a body
    that already scores 100% fails on the link, not the C, so it ranks after the near misses). No size
    band and no easy-first ordering."""
    rows = []
    for module in modules:
        res = run(["tools/fzgx.py", "route", "--module", module, "--skip-tried-by", tried_by or model,
                   "--max-attempts", str(max_attempts), "--limit", str(1000 if module == SHARED_MODULE else limit),
                   "--json"], capture=True)
        try:
            rows += json.loads(res.stdout)
        except ValueError:
            continue

    def rank(r):
        best, size = r.get("seed_best") or 0.0, r.get("size", 0)
        group = 0 if 90 <= best < 100 else 1 if best >= 50 and size >= 512 else 2 if size >= 1024 else 3
        return (group, -best, -size)

    rows = [r for r in rows if r["symbol"] not in exclude and allowed(r)]
    rows.sort(key=rank)
    return [r["symbol"] for r in rows[:count]]


def run_batch(a, model: str, effort: str, symbols: list, checks: int, stale: int, parallel: int, batch: str):
    res = run(["tools/orchestrate.py", "--harness", "codex", "--provider", "openai", "--model", model,
               "--effort", effort, "--parallel", str(parallel), "--max-checks", str(checks),
               "--max-stale", str(stale), "--max-attempts", str(a.max_attempts + 12), "--no-trivial", "--batch", batch,
               "--symbols", *symbols], capture=True)
    summary = {}
    for line in reversed(res.stdout.splitlines()):
        if line.startswith("{") and '"matched"' in line:
            summary = json.loads(line)
            break
    return res, summary


def released_in(batch: str) -> list:
    db = sqlite3.connect(ROOT / ".fzgx" / "ledger.db")
    rows = db.execute("SELECT DISTINCT symbol FROM attempts WHERE agent LIKE ? AND outcome = 'released'",
                      (batch + "-codex-%",)).fetchall()
    db.close()
    return [r[0] for r in rows]


def astra_phase(a, n: int, stop_file: Path, deadline: float):
    """One Astra batch on hard functions: medium effort for all, then high on the ones medium released.
    Returns (matched, functions, stop); functions is 0 when nothing is left to try."""
    symbols = pick_hard(a.astra_model, a.astra_batch, a.max_attempts + 12, a.modules)
    if not symbols:
        return 0, 0, False
    attempted, matched, effort = len(symbols), 0, "medium"
    while symbols:
        batch = f"codex-astra-{time.strftime('%Y%m%d-%H%M')}-{n}-{effort}"
        log(f"{batch}: {len(symbols)} functions on {a.astra_model}, effort {effort}")
        res, summary = run_batch(a, a.astra_model, effort, symbols, 40, 12, len(symbols), batch)
        got = summary.get("matched", 0)
        matched += got
        log(f"{batch}: {got} matched, {summary.get('released', '?')} released, {summary.get('failed', '?')} failed, "
            f"{summary.get('wall_s', '?')}s")
        reset = usage_limit(batch, summary.get("failed", 0))
        if reset:
            log(f"{forgive_crashes()} astra crashes returned to the pool")
            if not wait_until(reset, stop_file, deadline):
                return matched, attempted, True
            continue  # same functions, same effort: the limit, not the model, ended them
        if effort == "high" or not summary:
            break
        symbols, effort = released_in(batch), "high"  # only what medium could not match gets the dearer effort
    return matched, attempted, False


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--model", default="gpt-6.1-sol")
    ap.add_argument("--batch-size", type=int, default=16)
    ap.add_argument("--per-module", type=int, default=6)
    ap.add_argument("--max-attempts", type=int, default=12, help="attempts a function may have had and still be picked")
    ap.add_argument("--max-batches", type=int, default=6)
    ap.add_argument("--hours", type=float, default=168.0)
    ap.add_argument("--zero-streak", type=int, default=3)
    ap.add_argument("--parallel", type=int, default=12)
    ap.add_argument("--astra-model", default="gpt-6-astra")
    ap.add_argument("--astra-batch", type=int, default=8, help="hard functions per Astra batch, run in parallel")
    ap.add_argument("--astra-max", type=int, default=0,
                    help="Astra function attempts per loop run; 0 (default) is Sol only. Astra used the weekly limit up in hours")
    ap.add_argument("--modules", nargs="*", default=MODULES,
                    help="modules to pick from (main_rel is limited to the slice the Claude loop does not route)")
    a = ap.parse_args()
    astra_used = 0
    retried: set = set()  # functions the retry pass has already handed out in this run

    stop_file = ROOT / ".fzgx" / "STOP"
    started, streak, total, band, n, waits = time.time(), 0, 0, 0, 0, 0
    deadline = started + a.hours * 3600
    while n < a.max_batches:
        n += 1
        if stop_file.exists():
            log("stop file present"); break
        if time.time() - started > a.hours * 3600:
            log("time limit"); break
        symbols, label = [], ""
        while band < len(BANDS):
            lo, hi, effort, checks, stale = BANDS[band]
            symbols = pick(a.model, lo, hi, a.per_module, a.batch_size, a.max_attempts)
            if symbols:
                label = f"band {lo}-{hi} B"
                break
            log(f"band {lo}-{hi} B empty")
            band += 1
        if not symbols:  # the easy size bands are used up: hard functions, as the Claude loop routes Fable
            symbols = pick_hard(a.model, a.batch_size, a.max_attempts, a.modules)
            effort, checks, stale, label = "high", 40, 12, "near misses and large functions"
        if not symbols:  # fresh functions are gone: one more try for each earlier Sol attempt, near misses first
            symbols = pick_hard(a.model, a.batch_size, a.max_attempts, a.modules, tried_by="retry-pass-",
                                exclude=retried, limit=40)
            retried.update(symbols)
            effort, checks, stale, label = "high", 40, 12, "retry of earlier attempts"
        if not symbols:
            if a.astra_max and astra_used < a.astra_max:
                log("sol pool empty: astra only")
                got, tried, stop = astra_phase(a, n, stop_file, deadline)
                if not tried:
                    log("astra pool empty"); break
                astra_used += tried
                total += got
                if got:
                    run(["tools/fzgx.py", "progress", "--note", f"codex-astra {n}"], capture=True)
                if stop:
                    log("stopping after usage limit"); break
                continue
            log("pool empty"); break
        batch = f"codex-goal-{time.strftime('%Y%m%d-%H%M')}-{n}"
        log(f"{batch}: {len(symbols)} functions, {label}, effort {effort}")
        res, summary = run_batch(a, a.model, effort, symbols, checks, stale, a.parallel, batch)
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
        got, stop = 0, False
        if a.astra_max and astra_used < a.astra_max and not stop_file.exists():
            got, tried, stop = astra_phase(a, n, stop_file, deadline)
            astra_used += tried
            total += got
            if got:
                gate = run(["tools/fzgx.py", "gate"], capture=True)
                if "GATE: PASS" not in gate.stdout:
                    log("GATE FAILED after astra, stopping:\n" + gate.stdout[-1500:]); return 1
        if matched or got:
            run(["tools/fzgx.py", "progress", "--note", f"codex-goal {batch}"], capture=True)
        if stop:
            log("stopping after usage limit"); break
        streak = 0 if matched else streak + 1
        if streak >= a.zero_streak:
            if band + 1 < len(BANDS):
                band += 1
                streak = 0
                log(f"{a.zero_streak} batches without a match: moving to band {BANDS[band][0]}-{BANDS[band][1]} B")
            elif band < len(BANDS):
                band = len(BANDS)  # the size bands gave nothing: go to the hard pool
                streak = 0
                log(f"{a.zero_streak} batches without a match in the last band: moving to the hard pool")
            else:
                log(f"{a.zero_streak} batches without a match in the hard pool"); break
    log(f"done: {total} matched")
    return 0


if __name__ == "__main__":
    sys.exit(main())
