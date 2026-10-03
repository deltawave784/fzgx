---
name: match-wave
description: Run one wave of F-Zero GX function matching with tiered Claude subagents (Haiku / Sonnet / Opus) over the fzgx MCP server. Use when asked to match functions, run a wave, or continue the decomp.
---

# Match wave

The routing is deterministic; you only dispatch and report. Run from the repository root.

1. **Preflight.** `uv run ninja` must end with `16 files OK`. The `fzgx` MCP tools must be
   available (they load when a session starts in this repo and the server is approved);
   if they are not, stop and say so.

2. **Pick work.** `uv run tools/fzgx.py route --json --limit N [--mid] [--escalate-from haiku] [--module M]`
   - `N` defaults to 8; keep waves small until per-tier success rates are known.
   - `--mid` sends small near misses to Sonnet (`matcher-mid`) instead of Haiku.
   - `--escalate-from haiku` sends small functions Haiku already failed to Sonnet
     (with `--mid`) or Opus.
   Each row names `agent_type` (`matcher`, `matcher-mid`, `matcher-large`).

3. **Dispatch.** Start one subagent per row, `subagent_type` = the row's `agent_type`, at
   most 6 at a time (submits serialize on the build lock), with exactly this prompt:

       SYMBOL=<symbol> AGENT_ID=<tier>-<symbol>-<YYYYMMDD>

   where `<tier>` is the row's `tier` (`haiku`, `sonnet`, `opus`). The agent ID prefix is
   how the next wave's `--escalate-from` finds what each tier already tried.
   Give no other instructions; the agent definitions carry them.

4. **Collect.** Each agent ends with one line: `SYMBOL: matched` or
   `SYMBOL: released at N% - reason`. Do not retry failures in the same wave.

5. **Close the wave.**
   - `uv run tools/fzgx.py verify` drains anything still `pending` (a full match is submitted,
     relinked and committed by the check that reaches 100%; this catches the rest).
   - `uv run ninja` must still end with `16 files OK` (when ninja has nothing to do it prints no
     summary; `build/tools/dtk shasum -c config/GFZE01/build.sha1` checks the hashes directly).
   - `uv run tools/fzgx.py report` for progress.
   - Matches are committed by the tooling as they are accepted; check `git log`.
   - Report to the user: matched / released per tier, bytes matched, and the release
     reasons that repeat (candidates for `docs/MWCC_IDIOMS.md` or a librarian pass).

Never push. Never run the librarian concurrently with matchers.
