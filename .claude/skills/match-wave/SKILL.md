---
name: match-wave
description: Run one wave of F-Zero GX function matching with tiered Claude subagents (Sonnet / Opus) over the fzgx MCP server. Use when asked to match functions, run a wave, or continue the decomp.
---

# Match wave

The routing is deterministic; you only dispatch and report. Run from the repository root.

1. **Preflight.** `uv run ninja` must end with `16 files OK`. The `fzgx` MCP tools must be
   available (they load when a session starts in this repo and the server is approved);
   if they are not, stop and say so.

2. **Pick work.** `uv run tools/fzgx.py route --json --limit N [--skip-tried] [--escalate-from sonnet-] [--small B] [--module M]`
   - `N` defaults to 8. Functions up to `--small` bytes (256) go to Sonnet (`matcher-mid`),
     larger ones to Opus (`matcher-large`); the user's plan limits Opus, so keep it to 1-2
     rows a wave unless told otherwise.
   - Rows with `seeded: true` start from a saved body (`seed_best` %); they rank first.
   - `--skip-tried` leaves out what a Claude tier already attempted; `--escalate-from sonnet-`
     sends small functions Sonnet already failed to Opus.
   - Haiku is not a matching tier (0 of 5 against Sonnet's 2 of 8 on the same pool).

3. **Dispatch.** Start one subagent per row, `subagent_type` = the row's `agent_type`, at
   most 6 at a time (submits serialize on the build lock), with exactly this prompt:

       SYMBOL=<symbol> AGENT_ID=<tier>-<symbol>-<YYYYMMDD>

   where `<tier>` is the row's `tier` (`sonnet`, `opus`). The agent ID prefix is
   how the next wave's `--escalate-from` finds what each tier already tried.
   Give no other instructions; the agent definitions carry them.

4. **Collect.** Each agent ends with one line: `SYMBOL: matched` or
   `SYMBOL: released at N% - reason`. Do not retry failures in the same wave.

5. **Close the wave.**
   - `uv run tools/fzgx.py fixup --min-percent 95 --apply --budget 1500 --output .fzgx/fixup/<wave>`:
     the deterministic engine over every saved body at 95%+ (register, pragma and pool
     families; wave 3 closed 3 functions in 7 minutes that agents had released). It submits,
     verifies and commits exact results itself; commit `state/repairs/fixup_imports.json` after.
   - `uv run tools/fzgx.py verify` drains anything still `pending` (a full match is submitted,
     relinked and committed by the check that reaches 100%; this catches the rest).
   - `uv run ninja` must still end with `16 files OK` (when ninja has nothing to do it prints no
     summary; `build/tools/dtk shasum -c config/GFZE01/build.sha1` checks the hashes directly).
   - `uv run tools/fzgx.py report` for progress.
   - Matches are committed by the tooling as they are accepted; check `git log`.
   - Report to the user: matched / released per tier, bytes matched, and the release
     reasons that repeat (candidates for `docs/MWCC_IDIOMS.md` or a librarian pass).

Never push. Never run the librarian concurrently with matchers.
