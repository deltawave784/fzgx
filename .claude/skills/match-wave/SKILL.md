---
name: match-wave
description: Run one wave of F-Zero GX function matching with tiered Claude subagents (Sonnet / Opus) over the fzgx MCP server. Use when asked to match functions, run a wave, or continue the decomp.
---

# Match wave

The routing is deterministic; you only dispatch and report. Run from the repository root.

1. **Preflight.** `uv run ninja` must end with `16 files OK`. The `fzgx` MCP tools must be
   available (they load when a session starts in this repo and the server is approved);
   if they are not, stop and say so.

2. **Pick work.** `uv run tools/fzgx.py route --json --limit 16 --skip-tried [--escalate-from sonnet-] [--small B] [--module M]`
   - Take 8 rows. Functions up to `--small` bytes (256) go to Sonnet (`matcher-mid`), larger
     ones to Opus (`matcher-large`); the user's plan limits Opus: at most 2 Opus rows a wave
     unless told otherwise (skip further Opus rows, take the next Sonnet ones).
   - One row per clone family: rows of the same module and size whose `seed_best` agree are
     usually the same code twice (fn_1_8CA70 / fn_1_8CAF4). Dispatch the first; `reuse` in
     step 5 carries a match to its twins.
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
   - A release saying the body is an instruction MWCC never emits (`twui`, `mtspr`, other
     privileged forms, no `blr`) goes to `uv run tools/fzgx.py asm-unit SYMBOL [TWINS...]`. It
     commits with a plain `git commit`, so run it only with nothing staged.

5. **Close the wave** (after every agent has reported; these touch the build).
   - `uv run tools/fzgx.py reuse --max-size 2048`: rebinds matched C onto retail clones
     (wave 4: fn_1_8CAF4 and a 612-byte fn_1_10B344 from one Sonnet match).
   - `uv run tools/fzgx.py fixup --min-percent 95 --apply --budget 1500 --output .fzgx/fixup/<wave>`:
     the deterministic engine over every saved body at 95%+ (register, pragma and pool
     families; wave 3 closed 3 functions in 7 minutes that agents had released). It submits,
     verifies and commits exact results itself; commit `state/repairs/fixup_imports.json` after.
   - `uv run tools/fzgx.py verify` drains anything still `pending` (a full match is submitted,
     relinked and committed by the check that reaches 100%; this catches the rest).
   - `uv run ninja` must still end with `16 files OK` (when ninja has nothing to do it prints no
     summary; `build/tools/dtk shasum -c config/GFZE01/build.sha1` checks the hashes directly).
   - `uv run tools/fzgx.py progress --note "<wave or batch id>"` records the matched-code percentage in
     `state/progress.csv` and prints the change since the last row and since the first; commit the CSV with the
     close-out. Then `uv run tools/fzgx.py report` for the ledger totals.
   - Matches are committed by the tooling as they are accepted; check `git log`.
   - Report to the user: matched / released per tier, bytes matched, and the release
     reasons that repeat (candidates for `docs/MWCC_IDIOMS.md` or a librarian pass).
     Append the same summary to `.fzgx/reports/waves.md` (local, not committed).

## Unattended runs (`/goal`, `/loop`)

Repeat steps 1-5; each wave starts only after the previous one closed. Stop, report and
wait for the user when:
- the hash check fails, or `verify`/`fixup` reports a rejected or failed link;
- two consecutive waves match nothing (agents, reuse, fixup and asm units together);
- `route --skip-tried` returns no rows (escalation is the user's decision);
- a tool call is refused for permissions, or the same tooling error repeats.
Do not edit tooling, agent definitions or headers in an unattended run, and never start the
librarian or a type-recovery pass. Commit only what the steps above commit.

## Fable autonomous mode (the default for long unattended runs)

Measured 2026-10-04: Fable agents matched 14 of 30 near misses (47%, 6.8 KB) that Sonnet and Opus had
released at 98-99.9%; Sonnet/Opus waves matched about 25% of fresher functions. Use Fable batches.

One batch = steps 1-5 above with these changes:
- Pick: `uv run tools/fzgx.py route --fable --limit 8 --min-percent 98 --json` (best score first, never tried by
  Fable, one per clone family). Dispatch each row with `subagent_type: matcher-large` and `model: fable`, prompt
  `SYMBOL=<symbol> AGENT_ID=fable-<symbol>-<YYYYMMDD><batch letter>`; all 8 at once.
- Close the batch: `reuse --max-size 2048`, then `fixup --min-percent 97 --apply --budget 1200 --output
  .fzgx/fixup/<batch>`, then `verify`, then ninja/hash check, then `progress --note "fable batch <n>"` and `report`; append a line to
  `.fzgx/reports/waves.md` that includes the code percentage; commit `state/progress.csv`.
- If `route --fable` returns fewer than 4 rows, lower `--min-percent` to 95, then 90. Below 90 the match rate is
  unmeasured: stop and ask.

Before EVERY batch check usage with the `mcp__ccd_session_mgmt__get_usage` tool (load it with ToolSearch). Changed
2026-10-05 at the user's request: the user does not use Fable for anything else, so the **weekly Fable window may be
run to its limit**; the 95% cap now applies only to the **5-hour window and the weekly all-models window** (shared
with Opus/Sonnet and the user's other projects). A Fable batch costs 3-7% of the weekly Fable window (7 on
2026-10-05 when agents ran long). Pick the mode for the next batch from the usage reading:
- weekly Fable below 94%: run a Fable batch (the batch may end at or just over 100%; an agent that dies on the limit
  commits nothing, so close the batch as usual and let `verify` drain whatever was submitted).
- weekly Fable at 94% or more, or a Fable batch ended because the limit was hit: switch to **fallback mode** (below)
  and stay there until `resetsAt` of the Fable window has passed (then re-read usage and return to Fable batches).
- weekly all-models or 5-hour at 89% or more: 5-hour: wait for it to reset (sleep in the background until
  `resetsAt`), then continue; weekly all-models: STOP and push a notification (resets Monday 5pm).
- extra usage `spent` above 0: STOP and notify (the run must never spend money). Extra usage is enabled on this
  account, so confirm after each Fable batch near the limit that `spent` is still 0.
After the first three batches, replace the 6% allowance with the largest weekly and 5-hour increase one batch
actually caused (measure usage before and after each batch) plus 1 point, so the margin tracks real cost.

### Fallback mode (Opus and Sonnet, automatic when Fable is at its limit)

One batch = the wave procedure in steps 1-5 above, with a different pick. Do NOT use the plain
`route --skip-tried`: it ranks saved 99% bodies first, which are the near misses Fable and the earlier waves
already failed on (checked 2026-10-05: 14 of its top 16 rows were Fable releases). Use the easy ordering:

    uv run tools/fzgx.py route --easy --small 512 --max-size 768 --max-attempts 3 --json --limit 16 [--escalate-from sonnet-]

`--easy` skips everything a Haiku, Sonnet, Opus or Fable agent attempted, orders by size then recorded attempts
(smallest first, no bonus for a saved body; untouched functions are all large, the small ones were tried long ago), keeps one function per (module, size) retail-clone family, and drops
`:_prolog` entries and compiler save/restore helpers. `--small 512` sends rows up to 512 B to Sonnet
(`matcher-mid`) and larger ones to Opus (`matcher-large`); at most 2 Opus rows per batch unless the user says
otherwise. Take 8 rows, 6 agents at a time. Close-out is unchanged: `reuse`, `fixup`, `verify`, hash check,
`report`. Agent ids use the `sonnet-`/`opus-` prefixes so the next batch's `--escalate-from` finds them. When the
route returns fewer than 8 rows, raise `--max-attempts` to 5, then `--max-size` to 1024. Yield is lower than
Fable's near-miss yield (about 25% of fresher functions, measured earlier), so two consecutive fallback batches
matching nothing stops the run. While in fallback mode check usage before every batch; the 5-hour and weekly
all-models caps above apply. When the Fable window resets, go back to Fable batches (they retry what Opus and
Sonnet released).

Stop conditions (in addition to those under Unattended runs): hash check fails; two consecutive batches match
nothing (agents + reuse + fixup); the same tooling error twice; a permission refusal; `git status` not clean after a
close-out. On every stop, call PushNotification (load via ToolSearch) with one line that leads with the reason, e.g.
`decomp stopped: hash check failed after batch 7 (fn_xxx); tree restored`. Also push once every 5 batches with the
running total (`batch 10 done: 41 fn matched today, 31.9% code`, taking the percentage from `progress`). Also push once when the run switches between Fable
and fallback mode (`decomp: Fable limit reached, continuing with Opus/Sonnet`). No other notifications.

After a context compaction, re-read this skill and the last 40 lines of `.fzgx/reports/waves.md` before continuing.

## Tooling rounds (between batches)

Matching agents keep ending on the same causes; a tooling round fixes one cause for every future batch, behind a
regression gate. A round runs only BETWEEN batches (never while any claim, `fixup`, `verify` or build is
running), with `git status` clean.

**Trigger** (check after each batch close-out; the interval starts at 5 batches and stretches, see decay):
- every `round_interval` batches since the last round, OR
- two consecutive batches closed fewer than 3 functions each.

**Steps:**
1. Census: from the last batches' release lines in `.fzgx/reports/waves.md`, the saved best bodies (`check` of each
   with `oracle.check` / `fzgx stuck`) and the oracle's `pool_notes`, rank blocker classes by functions blocked and
   bytes; skip classes the notes mark as needing the allocator capture (no macOS VM here). Also read
   `state/pending_tooling/` (unapplied D patches are not re-proposed).
2. If no class blocks at least 3 functions, stop the round (log "tooling round: nothing worth fixing"), which costs
   only the census.
3. Baseline for the cheaper-model measurement: pick up to 6 of the blocked functions of the top class and run ONE
   Sonnet batch on them now (`matcher-mid`, ids `sonnet-<symbol>-<date>t0`); record matched/released and the
   release scores in the round's log entry. Skip this step when the class is only reachable by deterministic tools.
4. Dispatch ONE `tooling` agent (`subagent_type: tooling`, default model; pass `model: fable` instead only while
   weekly Fable use is below 70%) with a brief: class, blocked functions with saved-body paths, evidence, and the
   category rules in its definition. Wait for its report.
5. After a kept (A/B/C) change: run the same Sonnet batch again on the same functions (ids `...t1`) and log the
   before/after per-function result: this is the measurement of whether the change made cheaper models more
   effective. Then run `fixup --min-percent 95 --apply` and `verify` (the change may close functions
   deterministically), then `progress --note "tooling round <n>"`.
6. After a D change: DO NOT apply it. Push a notification (`tooling round <n>: oracle change pending your approval:
   <slug>, <measured gain>; see state/pending_tooling/`) and continue batches. The user applies it with
   `git apply state/pending_tooling/<name>.patch` and `fzgx gate`, or asks to.

**Budget and decay:** one agent, about 90 minutes; tooling must stay under about 15% of the run's usage. Log every
round to `.fzgx/reports/waves.md` (class, category, files, gate result, measured gain, cheaper-model before/after,
tokens). `round_interval` is 5 at first; two consecutive rounds with no kept change or no measured gain double it
(5 -> 10 -> 20, capped at 20); a kept change with a gain resets it to 5. A round that fails its gate is reverted
by the agent; two failed gates in a row stop the rounds for the rest of the run and notify.

## Two clones

When a second clone (a Codex harness or another person) works in parallel, read `docs/COLLABORATION.md`: this
clone works only its own modules (`route --fable --module <module>`), merges the other clone's branch only between
batches (`git pull --no-rebase b-local codex`, then ninja, `fzgx gate`, `fzgx sync`), and does not push. The user
pushes to the fork for backup. Do not merge, pull or push from inside a batch.

Never push. Never run the librarian concurrently with matchers.
