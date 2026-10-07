# Revise integrations never cost a match; installs keep the checked text (category D)

## Class
A `revise-` rewrite that object-matches but fails the link/hash was uncarved by `verify`
(block deleted, unit and split removed, ledger `unmatched`/`link-mismatch`). Lost this way:
fn_1_1286F4 (d7e2a937), fn_1_FB96C (95fa7407) and eight in revise-main-rel-1
(fn_1_B7FDC, 3F75C, AB7C4, ABE88, E49D4, FA1A8, 14A284, 151EF8), all restored by hand.

## Root cause
`api._install` splices an accepted text under the TU prologue whenever that compiles and only
falls back to `noprologue` on a compile error. The oracle checked the self-contained text, so a
prologue that compiles but changes the result links an unchecked object:
- fn_1_FB96C: bg_cas.c's prologue declares `extern void fn_1_FBC5C(u8 idx);`, adding
  `clrlwi r3, r31, 24` where retail (and the noprologue block) has `mr r3, r31`.
- fn_1_1286F4: under accessory.c's prologue the private literals `@75`/`@377` named in the
  unit's `pool` map no longer exist; ninja's `mwcc_pool` step (poolfix) exits 1.
The same path also hits first submits (the FB96C restore attempt was rejected the same way).

## Change (tools/fzgx/api.py, verify.py, tufile.py)
- `_install(..., verify_code=True)` (both submit paths): after a prologue splice compiles, compile
  the accepted text on its own and the generated unit into scratch objects and compare the
  function's relocation-masked words, its relocations (target, kind, addend) and the object's
  private literal symbols (`@N`, `...rodata.N`: name, size, section). Any difference keeps the
  block `noprologue`, i.e. exactly the text the oracle accepted.
- Revise submit: `_save_revise_prior` writes `.fzgx/revise_prior/<key>.json` (block body+flags or
  file text, the full unit record incl. `pool`/`mw_version`/`extra_cflags`, ledger link state and
  matched commit) before installing; the unit's `pool` map now follows the accepted check
  (`_set_unit_pool`, as a first submit does), with a re-split when it changes.
- `verify`: rejected keys with a saved prior go through `restore_revised` (block restored verbatim,
  unit record restored, ledger `matched`/prior link state, attempt outcome
  `revise-link-rejected`, the rewrite saved as `<key>.revise-linkfail.<t>.c`) and a relink; only
  if the prior no longer links either do they fall back to the old uncarve. Verified keys drop
  their prior. Result gains `revise_restored`. Shadow trials install nothing; unchanged.

## Why D
It changes how accepted units are integrated (block flags, units.json pool maps) and what verify
does with rejected units.

## Validation (scratch worktree ../fzgx-wt-r16 at bff33653, 16/16 baseline)
- A: revise fn_1_FB96C with the exact pre-95fa7407 body (the one rejected twice today): stays
  `noprologue`, verify fast path, 16/16 (before: installed under the prologue, uncarved).
- B: revise fn_1_1286F4 with `.fzgx/attempts/fn_1_1286F4.linkfail.1791406117.c` before the literal
  check was added: link failed, `revise_restored: [fn_1_1286F4]`, tree identical to HEAD,
  ledger matched/verified, 16/16 (before: block deleted, d7e2a937).
- C: revise fn_1_FB96C with a changed comment, then the installed block forced under the
  prologue (the pre-fix install): verify restored the prior text and `noprologue` flag, unit
  record unchanged, ledger matched/verified, attempt `revise-link-rejected`, no commit needed.
- F: same 1286F4 body with the final patch: kept `noprologue`, relink rc 0, verified (b2ae6411
  in the worktree), 16/16.

## Gate (live tree, patch applied)
lint 0 findings; build ok; hashes 16/16; pool_sample 24/0/0; recent 24/0/0;
named 10/0/0 (fn_1_FB96C fn_1_1286F4 B7FDC 3F75C AB7C4 ABE88 E49D4 FA1A8 14A284 151EF8); GATE: PASS.

## Apply
`git apply state/pending_tooling/20261007-revise-restore-prologue-guard.patch`, then
`uv run tools/fzgx.py gate --also fn_1_FB96C fn_1_1286F4`, then commit.
