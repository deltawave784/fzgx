# Carved units: `.fzgxpool` primers are not extra functions; submit options only on acceptance

Class (tooling round 33, item 2): every carved pool unit with a layout/pool primer re-checks as
"extra functions in our object: fzgx_bss_layout". The uncarved extras rule (oracle `_diff`,
`stray`) ignores `fzgx_*` primers; the carved rule (objdiff `-u unit`) did not. Batch 138's second
`fzgx submit fn_1_EB4BC` printed this error after the first submit had already accepted and carved
the unit. Second part: `_submit` wrote `--mw-version/--extra-cflags` into units.json (and re-split)
before the check, so a rejected re-submit of an installed unit left units.json changed.

Why D: changes the oracle's extras rule (what `unit_fully_matches` accepts for carved units) and
submit logic.

Change:
- oracle.py `_diff`: `extra_in_base` excludes `fzgx_*` functions defined in `.fzgxpool`
  (`res.primer_functions`, read from our object's section table).
- api.py `_submit`: for an already matched/asm function, unit options are written only after the
  check accepts the submit.

Measured: of 84 `link_state=pool` units, 73 re-checked as unfit only because of the primer
(colchg_selmate_init, fn_1_46144, fn_1_C3B8, fn_1_A3654, fn_1_EB4BC, fn_12_341C, fn_12_4D14, ...);
with the patch all 73 pass `unit_fully_matches`. One still fails: fn_1_3AEC4 ('fzgx_primer'
not in `.fzgxpool`, a real finding). 177 blocks/files carrying primers: all pass after.

Gate (patch applied): lint 0; build ok, hashes 16/16; pool_sample 24/24; recent 24/24;
named 22/22 (a cross-module sample of the 73 + fn_1_3AEC4). GATE: PASS.

Apply: `git apply state/pending_tooling/20261013-carved-primer-extras.patch` then `uv run tools/fzgx.py gate`.
