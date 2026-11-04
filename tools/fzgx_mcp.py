#!/usr/bin/env python3
"""MCP server exposing the fzgx matcher surface as tools.

Matcher agents get these tools and nothing else (no shell): they can only
claim a function, read its context, replace their own unit's source, check it
against retail, and submit or release. Every mutation is validated against
the ledger's claim (tools/fzgx/api.py), so an agent cannot touch a unit it
does not own.

Each tool call runs the CLI (`tools/fzgx.py --json ...`) in a subprocess
rather than importing the library, so fixes to tools/fzgx/ take effect on the
next call without restarting the server or the session. Overhead is ~0.1 s.

Registered in .mcp.json (Claude Code) and ~/.codex/config.toml (Codex).
Run from the repository root: `uv run tools/fzgx_mcp.py`.
"""

from __future__ import annotations

import json
import os
import re
import subprocess
import sys
import tempfile
import threading
from pathlib import Path
from typing import List, Optional

import anyio
import pydantic_core
from mcp.server.fastmcp import FastMCP

ROOT = Path(__file__).resolve().parent.parent
CLI = ROOT / "tools" / "fzgx.py"

# Claude Code does not hand a tool result of 50,000 characters or more to the model: it writes
# it to `<session>/tool-results/mcp-fzgx-<tool>-<epoch ms>.txt` and returns that path. The name
# carries no request id, so two claims that complete in the same millisecond (eleven matchers
# start together) share one file and the later write wins: `claim fn_1_4A0D8` read
# fn_1_12F4A8's bundle (batches fable-20261103i and -n; 107 of 130 claim results of one
# session were above the threshold). Results that would cross it are written here instead,
# to a file named by the symbol and the agent, and the inline result stays small.
CLIENT_RESULT_LIMIT = 45_000
BUNDLES = ROOT / ".fzgx" / "work" / "claims"


def _result_text(obj) -> str:
    """The text Claude Code measures: FastMCP's own serialization of a dict result."""
    return obj if isinstance(obj, str) else pydantic_core.to_json(obj, fallback=str, indent=2).decode()


def _bundle_path(kind: str, symbol: str, agent: str = "") -> Path:
    safe = lambda s: re.sub(r"[^A-Za-z0-9_.-]+", "_", s)
    BUNDLES.mkdir(parents=True, exist_ok=True)
    return BUNDLES / ".".join(p for p in (safe(symbol), safe(agent), kind, "md") if p)


def _bundle_file(path: Path, text: str) -> dict:
    tmp = path.with_name(path.name + f".{os.getpid()}.{threading.get_ident()}.tmp")
    tmp.write_text(text, encoding="utf-8")
    os.replace(tmp, path)
    return {"bundle_file": path.as_posix(), "bundle_lines": text.count("\n") + 1, "bundle_chars": len(text)}


def _deliver_claim(r, symbol: str, agent: str):
    """A claim result the client can carry inline, or one that points at this agent's own
    bundle file. Also refuses a bundle that names another function (the CLI echoes the
    requested symbol and labels the context with it: equality is the invariant)."""
    if not isinstance(r, dict):
        return r
    wanted = symbol.rsplit(":", 1)[-1]
    label = re.search(r"# Match task: `([^`]+)`", r.get("context") or "")
    labelled = label.group(1).rsplit(":", 1)[-1] if label else wanted
    if r.get("ok") and (r.get("symbol") != symbol or labelled != wanted):
        return {"ok": False, "symbol": symbol, "agent": agent,
                "error": (f"claim crosstalk: you asked for {symbol}, the bundle is labelled "
                          f"{r.get('symbol')}/{labelled}; call claim({symbol}, {agent}) again")}
    if len(_result_text(r)) < CLIENT_RESULT_LIMIT:
        return r
    out = dict(r)
    context = out.pop("context", "") or ""
    seed = dict(out.get("seed") or {})
    parts = [f"# claim {symbol} for {agent}: full bundle", "",
             "Private to this symbol and agent. The inline claim result holds everything but the",
             "text below; read this file completely (offset/limit) before editing.", ""]
    if len(_result_text({**out, "context": ""})) >= CLIENT_RESULT_LIMIT - 1000 and seed.get("source"):
        # the seed alone is too large to carry: it is also the work copy (check/patch_unit act on it)
        source = seed.pop("source")
        seed["source"] = f"({len(source)} characters: in bundle_file under '## seed.source' and already in your work copy)"
        out["seed"] = seed
        parts += ["## seed.source", "", "```c", source.rstrip("\n"), "```", ""]
    parts += ["## context", "", context]
    out.update(_bundle_file(_bundle_path("claim", symbol, agent), "\n".join(parts)))
    out["context"] = (f"({len(context)} characters) saved to bundle_file: Read it completely with offset/limit "
                      f"({out['bundle_lines']} lines) before writing anything. It is your own file; "
                      "ignore any other tool-results file.")
    return out


def _deliver_text(text, kind: str, symbol: str):
    if not isinstance(text, str) or len(text) < CLIENT_RESULT_LIMIT:
        return text
    info = _bundle_file(_bundle_path(kind, symbol), text)
    head = text[:2000]
    return (f"({len(text)} characters) saved to {info['bundle_file']}: Read it completely with offset/limit "
            f"({info['bundle_lines']} lines).\n\n--- first lines ---\n{head}")

mcp = FastMCP("fzgx", instructions=(
    "F-Zero GX matching oracle. The runner supplies the assignment, C and initial diff. "
    "Edit and check; matches and attempt limits end the session automatically."
    if os.environ.get('FZGX_RESULT_FILE') else
    "F-Zero GX matching-decompilation oracle. One function per agent: "
    "claim -> context -> write_unit -> check -> submit | release."))


def _cli(*args: str, as_json: bool = True, timeout: int = 900) -> str | dict | list:
    cmd = [sys.executable, str(CLI)] + (["--json"] if as_json else []) + list(args)
    # stdin is the MCP JSON-RPC stream: a child must never inherit it
    cp = subprocess.run(cmd, cwd=ROOT, text=True, capture_output=True, timeout=timeout,
                        stdin=subprocess.DEVNULL)
    result_file = os.environ.get('FZGX_RESULT_FILE')
    if result_file and Path(result_file).exists():
        # The runner consumes the terminal result and stops this process group.
        # Do not send another tool result to the model just to narrate completion.
        threading.Event().wait(30)
        raise RuntimeError('runner did not stop the completed worker')
    out = cp.stdout.strip()
    if as_json:
        try:
            return json.loads(out) if out else {"ok": False, "error": (cp.stderr or "no output").strip()[-2000:]}
        except json.JSONDecodeError:
            return {"ok": False, "error": (out + "\n" + cp.stderr).strip()[-2000:]}
    return out if cp.returncode == 0 or out else (cp.stderr.strip() or "no output")[-4000:]


async def _run(*args: str, as_json: bool = True):
    return await anyio.to_thread.run_sync(lambda: _cli(*args, as_json=as_json))


SUBMIT_DOC = ("Accept a 100% match: lint, relink every target, verify all 16 hashes, commit. `names` is an optional "
              "list of {kind,target,name,rationale} proposals for the librarian. Pass mw_version (e.g. 'GC/1.3') only "
              "if check(versions=...) showed that version matches.")
RELEASE_DOC = "Give up on SYMBOL. The best attempt is saved for the next agent; say precisely what still differs."
NOTES_DOC = (
    "`notes` (optional) is a list of at most 5 {kind, tu?, detail} entries (detail <= 300 chars) recorded "
    "for the librarian. Use it ONLY for a conflict a human or librarian must resolve outside your unit: a "
    "prototype or return type that disagrees with retail or with callers (kind 'prototype'), an extern/"
    "prologue declaration that conflicts (kind 'declaration'), a header struct/data object with the wrong "
    "type or size (kind 'data'), declared objects that overlap (kind 'overlap'), a missing prototype or "
    "unused helper (kind 'hygiene'), a name (kind 'naming'), else 'other'. Name the symbols, e.g. "
    "{\"kind\": \"prototype\", \"detail\": \"prologue declares extern u32 fn_X(void *) but retail returns nothing\"}. "
    "Never use it for scheduling, register allocation or match-progress observations; put those in "
    "the reason/message.")


def _notes_args(notes: Optional[List[dict]]) -> List[str]:
    """Inline JSON for the CLI's --notes (api.load_notes_arg); the CLI bounds and validates it."""
    return ["--notes", json.dumps(notes[:5] if isinstance(notes, list) else [notes])] if notes else []


@mcp.tool()
async def claim(symbol: str, agent: str) -> dict:
    """Claim SYMBOL for AGENT, initialize its private work copy and return the full context bundle (retail asm, symbols, callers, nearby matched C, flags, idioms, rules) in `context`. Seeded claims include the complete existing candidate in `seed.source`. A large bundle comes back as `bundle_file` (a file private to SYMBOL and AGENT): Read it completely before editing."""
    return _deliver_claim(await _run("claim", symbol, "--agent", agent), symbol, agent)


@mcp.tool()
async def context(symbol: str, budget_tokens: int = 6000) -> str:
    """Context bundle: retail assembly, referenced symbols with declarations, callers, nearby matched C, current unit source, compiler flags, idioms, rules."""
    return _deliver_text(await _run("context", symbol, "--budget-tokens", str(budget_tokens), as_json=False),
                         "context", symbol)


@mcp.tool()
async def read_unit(symbol: str) -> dict:
    """Current source of SYMBOL's unit."""
    return await _run("read-unit", symbol)


@mcp.tool()
async def read_evidence(symbol: str, section: str = 'diff', cursor: int = 0) -> str:
    """Read cached diff (section diff), owned data layouts, values and bindings (data), or retail initializers for data objects your C defines (datainit) by line cursor, without compiling or spending a check."""
    return await _run('read-evidence', symbol, '--section', section, '--cursor', str(cursor), as_json=False)


@mcp.tool()
async def write_unit(symbol: str, agent: str, source: str) -> dict:
    """Replace the whole source of the unit AGENT has claimed for SYMBOL, then compile and diff it against retail. Returns lint findings (A1/A2 hardcoded addresses, S1/S2 goto/volatile) and `check`: match % with a `target | ours` diff."""
    def go():
        with tempfile.NamedTemporaryFile("w", suffix=".c", delete=False, dir=ROOT / ".fzgx") as f:
            f.write(source)
            path = f.name
        try:
            return _cli("write-unit", symbol, "--agent", agent, "--file", path)
        finally:
            Path(path).unlink(missing_ok=True)
    (ROOT / ".fzgx").mkdir(exist_ok=True)
    return await anyio.to_thread.run_sync(go)


@mcp.tool()
async def patch_unit(symbol: str, agent: str, old: str, new: str) -> dict:
    """Edit the unit AGENT has claimed for SYMBOL in place: `old` must occur exactly once in the current source and is replaced by `new`; then compile and diff like write_unit (same `check` result). Use it for every change after the first write_unit: one declaration, one statement, one struct field, sent as a few lines instead of the whole unit."""
    def go():
        (ROOT / ".fzgx").mkdir(exist_ok=True)
        with tempfile.NamedTemporaryFile("w", suffix=".old", delete=False, dir=ROOT / ".fzgx") as f1, \
             tempfile.NamedTemporaryFile("w", suffix=".new", delete=False, dir=ROOT / ".fzgx") as f2:
            f1.write(old); f2.write(new); p1, p2 = f1.name, f2.name
        try:
            return _cli("patch-unit", symbol, "--agent", agent, "--old-file", p1, "--new-file", p2)
        finally:
            Path(p1).unlink(missing_ok=True); Path(p2).unlink(missing_ok=True)
    return await anyio.to_thread.run_sync(go)


@mcp.tool()
async def check(symbol: str, versions: Optional[str] = None, max_diff_lines: int = 80) -> str:
    """Compile SYMBOL's unit and diff against retail. Prints match %, compiler settings and a `target | ours` instruction diff. With versions='all' (or a comma list like 'GC/1.2.5n,GC/1.3.2'), probe CodeWarrior versions, show the winning diff and retain that compiler for subsequent edits and submit."""
    args = ["check", symbol, "--max-diff-lines", str(max_diff_lines)]
    if versions:
        args += ["--versions", versions]
    return await _run(*args, as_json=False)


@mcp.tool(description=SUBMIT_DOC + " " + NOTES_DOC)
async def submit(symbol: str, agent: str, message: str, harness: str = "", model: str = "",
                 mw_version: Optional[str] = None, names: Optional[List[dict]] = None,
                 notes: Optional[List[dict]] = None) -> dict:
    def go():
        args = ["submit", symbol, "--agent", agent, "--message", message] + _notes_args(notes)
        if harness:
            args += ["--harness", harness]
        if model:
            args += ["--model", model]
        if mw_version:
            args += ["--mw-version", mw_version]
        path = None
        if names:
            with tempfile.NamedTemporaryFile("w", suffix=".json", delete=False, dir=ROOT / ".fzgx") as f:
                json.dump(names, f)
                path = f.name
            args += ["--names", path]
        try:
            r = _cli(*args)
            # outside the Codex runner no batch verifier drains accepted matches: link-verify
            # and commit now, as this tool promises
            if isinstance(r, dict) and r.get("ok") and r.get("link") == "pending":
                r["verify"] = _cli("verify", timeout=2400)
            return r
        finally:
            if path:
                Path(path).unlink(missing_ok=True)
    (ROOT / ".fzgx").mkdir(exist_ok=True)
    return await anyio.to_thread.run_sync(go)


@mcp.tool(description=RELEASE_DOC + " " + NOTES_DOC)
async def release(symbol: str, agent: str, reason: str, harness: str = "", model: str = "",
                  notes: Optional[List[dict]] = None) -> dict:
    args = ["release", symbol, "--agent", agent, "--reason", reason] + _notes_args(notes)
    if harness:
        args += ["--harness", harness]
    if model:
        args += ["--model", model]
    return await _run(*args)


@mcp.tool()
async def inventory(module: Optional[str] = None, status: Optional[str] = None,
                    max_size: Optional[int] = None, limit: Optional[int] = 50) -> list:
    """List functions (orchestrator use): filter by module (main, main_rel, ...), status (unmatched|claimed|matched|blocked), max_size bytes."""
    args = ["inventory"]
    if module:
        args += ["--module", module]
    if status:
        args += ["--status", status]
    if max_size:
        args += ["--max-size", str(max_size)]
    if limit:
        args += ["--limit", str(limit)]
    return await _run(*args)


@mcp.tool()
async def report() -> dict:
    """Ledger status totals, costs, and objdiff progress."""
    return await _run("report")


if __name__ == "__main__":
    mcp.run()
