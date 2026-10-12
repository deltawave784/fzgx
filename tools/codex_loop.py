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
Every `--maintain-every` batches (default 6), and before it gives up, the loop runs a maintenance step: it pulls
clone A's commits (appended-only conflicts in splits.txt/symbols.txt are resolved by keeping both sides), re-runs
reuse/fixup/sweep over its saved bodies when the pull changed the engine, writes `.fzgx/reports/codex_census.md`, and
leaves `.fzgx/TOOLING_DUE` when it stalls. Tooling rounds and the librarian stay in clone A.
`--max-attempts` (default 12) is how many attempts a function may already have and still be picked, and
`--modules` picks the modules (default: all of them, but only the slice the Claude loop does not route:
over 768 B, best score under 85%, never attempted by Fable/Opus/Sonnet; see docs/COLLABORATION.md).

Stops on: `--max-batches`, `--hours` (wall clock, waits included), `--zero-streak` batches in
a row without a match in the last band, a failed gate, an empty pool, or the file
`.fzgx/STOP` (create it to stop after the current batch or wait). Never pushes.
Log: `.fzgx/reports/codex_loop.log`.
"""

from __future__ import annotations

import argparse
import datetime
import json
import os
import re
import shutil
import sqlite3
import subprocess
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
MODULES = ["main", "movie_module", "customize", "sel", "pilotpoint", "option", "title", "interview",
           "story", "profile", "movie", "winning", "replay", "car_colchg", "sample", "main_rel"]
# The Claude loop (clone A) routes every module: Fable on best >= 85% near misses and Opus on `route --easy` rows, which
# are small first. This loop takes only the slice it does not route, in every module: functions above CLAUDE_SMALL
# bytes whose best score is below CLAUDE_FLOOR percent and that no Claude tier ever attempted (read from the committed
# state/ledger.json). docs/COLLABORATION.md records the agreement; change these constants only together with it.
CLAUDE_SMALL, CLAUDE_FLOOR = 768, 85.0
_claude_tried: set = set()
# (min bytes, max bytes, effort, checks per worker, stale checks) in the order they are worked
BANDS = [(512, 1023, "medium", 24, 8), (1024, 2047, "high", 32, 10), (256, 511, "medium", 16, 5),
         (2048, 4095, "high", 40, 12), (0, 255, "medium", 12, 4), (4096, 100000, "high", 48, 14)]


def run(cmd: list, capture: bool = False) -> subprocess.CompletedProcess:
    return subprocess.run([sys.executable, *cmd], cwd=ROOT, text=True, capture_output=capture)


def run_step(name: str, cmd: list, timeout: int) -> bool:
    """Run one maintenance step with a time limit, logging when it starts and how it ends. On timeout the whole
    process tree is killed (subprocess.run would leave the compiler children running). True when it finished."""
    started = time.time()
    if disk_free_gb() < 10:
        log(f"  step {name}: skipped, only {disk_free_gb():.1f} GB free")
        return False
    log(f"  step {name}: start (limit {timeout // 60} min)")
    proc = subprocess.Popen([sys.executable, *cmd], cwd=ROOT, text=True, stdout=subprocess.PIPE,
                            stderr=subprocess.STDOUT)
    try:
        proc.communicate(timeout=timeout)
        log(f"  step {name}: done in {int(time.time() - started)} s (rc {proc.returncode})")
        return True
    except subprocess.TimeoutExpired:
        subprocess.run(["taskkill", "/T", "/F", "/PID", str(proc.pid)], capture_output=True)
        proc.communicate()
        log(f"  step {name}: TIMED OUT after {timeout // 60} min, process tree killed")
        return False


def disk_free_gb() -> float:
    return shutil.disk_usage(ROOT).free / 2 ** 30


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
    """False for a function the Claude loop routes (small, a near miss, or one a Claude tier already attempted)."""
    best = max(row.get("seed_best") or 0.0, row.get("best") or 0.0)
    return row.get("size", 0) > CLAUDE_SMALL and best < CLAUDE_FLOOR and row["symbol"] not in claude_tried()


def pick(model: str, lo: int, hi: int, per_module: int, count: int, max_attempts: int) -> list:
    out = []
    for module in MODULES:
        res = run(["tools/fzgx.py", "route", "--easy", "--module", module,
                   "--min-size", str(max(lo, CLAUDE_SMALL + 1)),
                   "--max-size", str(hi), "--max-attempts", str(max_attempts), "--skip-tried-by", model,
                   "--limit", str(per_module * 8), "--json"], capture=True)
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
                   "--max-attempts", str(max_attempts), "--limit", "1000", "--json"], capture=True)
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


def git(*args: str) -> subprocess.CompletedProcess:
    env = {**os.environ, "GIT_EDITOR": "true"}
    return subprocess.run(["git", *args], cwd=ROOT, text=True, capture_output=True, env=env)


def matched_count() -> int:
    db = sqlite3.connect(ROOT / ".fzgx" / "ledger.db")
    n = db.execute("SELECT COUNT(*) FROM functions WHERE status = 'matched'").fetchone()[0]
    db.close()
    return n


def gate_ok() -> bool:
    out = run(["tools/fzgx.py", "gate"], capture=True).stdout
    if "GATE: PASS" in out:
        return True
    log("GATE FAILED:\n" + out[-1500:])
    return False


def merge_appended(path: str, text: str):
    """Resolve the conflict hunks of a splits.txt or symbols.txt where both sides only appended entries: keep
    both. None when a hunk is not a pure append of disjoint entries."""
    lines = text.replace("\r\n", "\n").split("\n")
    out, ours, theirs, side = [], set(), set(), 0
    for line in lines:
        if line.startswith("<<<<<<< "):
            side = 1
            continue
        if line == "=======" and side == 1:
            side = 2
            out.append("")
            continue
        if line.startswith(">>>>>>> ") and side == 2:
            side = 0
            continue
        if side:
            key = line.split(" = ")[0] if path.endswith("symbols.txt") else (line if line.startswith("rel/") else "")
            if key:
                (ours if side == 1 else theirs).add(key)
        out.append(line)
    if side or (ours & theirs):
        return None
    return "\n".join(out)


def sync_from_a() -> str:
    """Pull clone A's commits (its tooling fixes, its matches, its Claude attempts). Returns 'current', 'merged',
    'dirty' (this tree has uncommitted work), 'conflict' (needs a person) or 'failed' (the merged tree did not pass)."""
    git("add", "state/progress.csv", "state/repairs/fixup_imports.json")
    git("commit", "-q", "-m", "progress and fixup imports: codex loop rows")
    dirty = git("status", "--short").stdout.strip()
    if dirty:
        log("sync with clone A skipped, tree not clean:\n" + dirty[:400])
        return "dirty"
    res = git("pull", "--no-rebase", "--no-edit", "a-local", "windows-and-types")
    if res.returncode != 0:
        files = git("diff", "--name-only", "--diff-filter=U").stdout.split()
        if not files:  # git itself failed (full disk, merge driver, lock): nothing to resolve, nothing to commit
            log("sync with clone A: git pull failed without a conflict: " + (res.stderr or res.stdout).strip()[-300:])
            return "failed"
        fixed = {}
        for f in files:
            ok = f.startswith("config/GFZE01/") and f.endswith(("splits.txt", "symbols.txt"))
            merged = merge_appended(f, (ROOT / f).read_text(encoding="utf-8")) if ok else None
            if merged is None:
                log(f"sync with clone A: {f} conflicts and is not a pure append; the merge is left for a person")
                return "conflict"
            fixed[f] = merged
        for f, text in fixed.items():
            (ROOT / f).write_text(text, encoding="utf-8", newline="\n")
        git("add", *fixed)
        git("commit", "-q", "--no-edit")
        git("commit", "--amend", "-q", "-m", "Merge branch 'windows-and-types' into codex (appended entries of both sides kept)")
        log(f"sync with clone A: kept both sides of {', '.join(fixed)}")
    elif "Already up to date" in res.stdout:
        return "current"
    _claude_tried.clear()  # the committed ledger changed: reread which functions a Claude tier attempted
    if not gate_ok():
        return "failed"
    run(["tools/fzgx.py", "sync"], capture=True)
    return "merged"


def tooling_changed() -> bool:
    """True when the last merge brought in changes to the fixup/oracle engine."""
    res = git("diff", "--name-only", "HEAD^1", "HEAD", "--", "tools/fzgx")
    return bool(res.stdout.strip())


def census(n: int) -> str:
    """Why this loop's sessions released, by class, into .fzgx/reports/codex_census.md (clone A's tooling rounds read it)."""
    db = sqlite3.connect(ROOT / ".fzgx" / "ledger.db")
    rows = db.execute("SELECT symbol, agent, notes FROM attempts WHERE outcome = 'released' AND notes IS NOT NULL "
                      "AND (agent LIKE 'codex-goal-%' OR agent LIKE 'codex-astra-%') ORDER BY id DESC LIMIT 400").fetchall()
    db.close()
    classes = {"register allocation": r"regist|callee-saved|r3[01]|allocat|swap", "prologue/frame": r"prologue|frame|stack",
               "literal pool": r"pool|literal|rodata", "section/bss layout": r"section|\.bss|\.data|layout",
               "scheduling/order": r"sched|order", "loop/unroll": r"loop|unroll|induction",
               "switch/jump table": r"switch|jump ?table", "types/casts": r"struct|signed|cast",
               "budget/stale": r"budget|stale|check limit"}
    hits, example = {}, {}
    for symbol, _agent, note in rows:
        for name, rx in classes.items():
            if re.search(rx, note.lower()):
                hits[name] = hits.get(name, 0) + 1
                example.setdefault(name, []).append(symbol)
    lines = [f"# Codex loop census after batch {n} ({time.strftime('%Y-%m-%d %H:%M')})", "",
             f"Latest {len(rows)} releases of codex-goal-*/codex-astra-* sessions, by the class named in their note.", ""]
    for name, count in sorted(hits.items(), key=lambda kv: -kv[1]):
        lines.append(f"- {name}: {count} (e.g. {', '.join(dict.fromkeys(example[name]))[:120]})")
    path = ROOT / ".fzgx" / "reports" / "codex_census.md"
    path.write_text("\n".join(lines) + "\n", encoding="utf-8")
    return ", ".join(f"{k} {v}" for k, v in sorted(hits.items(), key=lambda kv: -kv[1])[:3])


def maintenance(a, n: int, why: str):
    """Everything between batches that keeps the loop efficient and is safe in this clone. Tooling rounds and the
    librarian run only in clone A (docs/COLLABORATION.md): here the loop pulls A's fixes, re-runs the deterministic
    engine over its own saved bodies when those fixes touch it, writes the census A's rounds read, and leaves a
    TOOLING_DUE marker when the loop stalls. Returns (functions gained, sync result, stop)."""
    log(f"maintenance after batch {n} ({why})")
    before = matched_count()
    result = sync_from_a()
    if result in ("conflict", "failed"):
        return 0, result, True
    if result == "merged" and tooling_changed():
        log("clone A changed the engine: reuse, fixup and one sweep round over this clone's saved bodies")
        run_step("reuse", ["tools/fzgx.py", "reuse", "--max-size", "2048"], 900)
        run_step("fixup", ["tools/fzgx.py", "fixup", "--min-percent", "85", "--apply", "--budget", "400",
                           "--output", f".fzgx/fixup/codex-maint-{n}"], 1800)
        run_step("sweep", ["tools/fzgx.py", "sweep", "--min-percent", "75", "--max-percent", "95", "--rounds", "1",
                           "--land", "--output", f".fzgx/sweep/codex-maint-{n}"], 2400)
        run_step("verify", ["tools/fzgx.py", "verify"], 1200)
        if not gate_ok():
            return 0, "failed", True
    gained = matched_count() - before
    log(f"maintenance: sync {result}, {gained} functions gained; releases: {census(n) or 'none recorded'}")
    if gained:
        run(["tools/fzgx.py", "progress", "--note", f"codex maintenance {n}"], capture=True)
    return gained, result, False


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
    ap.add_argument("--maintain-every", type=int, default=6,
                    help="batches between maintenance steps (pull clone A, deterministic passes, census); 0 disables")
    ap.add_argument("--max-cycles", type=int, default=6, help="maintenance cycles that may restart a stalled loop")
    ap.add_argument("--min-free-gb", type=float, default=15.0,
                    help="stop when the drive has less free space (sweeps and fixups write many GB of candidates)")
    ap.add_argument("--no-sol", action="store_true", help="skip the Sol batches: Astra only (use with --astra-max)")
    ap.add_argument("--modules", nargs="*", default=MODULES,
                    help="modules to pick from (every module is limited to the slice the Claude loop does not route)")
    a = ap.parse_args()
    astra_used = 0
    retried: set = set()  # functions the retry pass has already handed out in this run
    cycles = 0

    stop_file = ROOT / ".fzgx" / "STOP"
    started, streak, total, band, n, waits = time.time(), 0, 0, 0, 0, 0
    deadline = started + a.hours * 3600
    while n < a.max_batches:
        n += 1
        if stop_file.exists():
            log("stop file present"); break
        if time.time() - started > a.hours * 3600:
            log("time limit"); break
        if disk_free_gb() < a.min_free_gb:
            log(f"stopping: only {disk_free_gb():.1f} GB free on the drive (limit {a.min_free_gb:.0f} GB); "
                "free space, then restart"); break
        symbols, label = [], ""
        while band < len(BANDS) and not a.no_sol:
            lo, hi, effort, checks, stale = BANDS[band]
            symbols = pick(a.model, lo, hi, a.per_module, a.batch_size, a.max_attempts)
            if symbols:
                label = f"band {lo}-{hi} B"
                break
            log(f"band {lo}-{hi} B empty")
            band += 1
        if not symbols and not a.no_sol:  # the easy size bands are used up: hard functions, as the Claude loop routes Fable
            symbols = pick_hard(a.model, a.batch_size, a.max_attempts, a.modules)
            effort, checks, stale, label = "high", 40, 12, "near misses and large functions"
        if not symbols and not a.no_sol:  # fresh functions are gone: one more try for each earlier Sol attempt, near misses first
            symbols = pick_hard(a.model, a.batch_size, a.max_attempts, a.modules, tried_by="retry-pass-",
                                exclude=retried, limit=40)
            retried.update(symbols)
            effort, checks, stale, label = "high", 40, 12, "retry of earlier attempts"
        if not symbols:
            if a.astra_max and astra_used < a.astra_max:
                log("astra only" if a.no_sol else "sol pool empty: astra only")
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
        if a.maintain_every and n % a.maintain_every == 0:
            gained, sync_result, halt = maintenance(a, n, "scheduled")
            if halt:
                log(f"stopping: sync with clone A {sync_result}"); break
            total += gained
            if sync_result == "merged":
                retried.clear()
        if streak >= a.zero_streak:
            if band + 1 < len(BANDS):
                band += 1
                streak = 0
                log(f"{a.zero_streak} batches without a match: moving to band {BANDS[band][0]}-{BANDS[band][1]} B")
            elif band < len(BANDS):
                band = len(BANDS)  # the size bands gave nothing: go to the hard pool
                streak = 0
                log(f"{a.zero_streak} batches without a match in the last band: moving to the hard pool")
            else:  # the last pool is dry: pull clone A and re-run the engine before giving up
                gained, sync_result, halt = maintenance(a, n, f"{a.zero_streak} batches without a match")
                total += gained
                cycles += 1
                if halt or cycles > a.max_cycles or not (gained or sync_result == "merged"):
                    if not halt:
                        (ROOT / ".fzgx" / "TOOLING_DUE").write_text(
                            f"{time.strftime('%Y-%m-%d %H:%M')} codex loop stalled after batch {n}: "
                            "see .fzgx/reports/codex_census.md for the release classes\n", encoding="utf-8")
                        log("tooling due: wrote .fzgx/TOOLING_DUE (a tooling round in clone A reads the census)")
                    log(f"{a.zero_streak} batches without a match in the hard pool"); break
                retried.clear()
                streak = 0
                log("maintenance gave the loop new work: continuing")
    log(f"done: {total} matched")
    return 0


if __name__ == "__main__":
    sys.exit(main())
