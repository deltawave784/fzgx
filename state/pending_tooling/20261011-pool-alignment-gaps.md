# Pending (category D): pointer-bearing pools across dtk's unlabelled alignment padding

## Class

A function whose private `.rodata` pool carries pointer relocations (a local
array initialised from function addresses, e.g. fn_1_52968's
`void (*callbacks[4])(void *, void *) = { fn_1_52B68, ... }`) can only bind its
anonymous `...rodata.0` to retail through `oracle._data_pool_rows` ->
`_relocated_pool_matches`, which proves bytes and relocation bindings over the
whole pool. That proof required every byte of the pool to lie inside a retail
object from `dataimport.pool_objects`. dtk names no object for alignment padding
(font.c: `lbl_1_rodata_2770` is 4 bytes, the next literal `lbl_1_rodata_2778` is
8-aligned, so 0x2774..0x2778 has no symbol and no gap_/pad_ label), so the proof
failed on 4 uncovered zero bytes even though bytes and the four function-pointer
bindings were all equal. The check reported only `...rodata.0` relocation rows
(stuck class `reloc`, 99.6%).

## Change

`tools/fzgx/oracle.py`: new `_retail_gap`; `_relocated_pool_matches` fills each
uncovered run from the retail split object that holds the closest preceding pool
object, only when that object covers the run contiguously, no other symbol of it
claims the bytes and no retail relocation touches them. Our bytes must still
equal those retail bytes and our relocations must still equal retail's bindings.

`tools/fzgx/poolfix.py` (added 2026-10-11, link fix): `drop_private_rodata` now also empties
every relocation section applied to the emptied section (`drop_private_data` already did this
for `.data`). Without it the pointer-bearing pool's four function-address relocations stay in
`.rela.rodata` at offsets 0x124..0x130 of a size-0, non-ALLOC `.rodata`, and mwld aborts with
`internal linker error: File: 'ELF_linker.c' Line: 1179` (the earlier verify rejection).

## Why D

It changes what the oracle accepts (pool binding of pointer-bearing pools).

## Gate (patch applied, 2026-10-11)

    lint: 0 finding(s); build ok: True; hashes OK: 16/16
    pool_sample: 24 passed, 0 failed, 0 skipped
    recent: 24 passed, 0 failed, 0 skipped
    named: 225 passed, 0 failed, 1 skipped   (every unit whose pool map binds an anonymous ...section.N pool)
        main:__DSP_boot_task: mwcceppc Usage Error 'off'' (pre-existing extra_cflags quoting, unrelated)
    GATE: PASS

## Measured gain

`fzgx stuck --min-percent 85` over 354 saved bodies, before -> after:

- fn_1_52968 (512 B): matched False, pool_rows 4, 98.44% adjusted -> matched True (pool map binds `...rodata.0` -> lbl_1_rodata_26F8, rodata emptied)
- fn_1_53B14 (196 B): matched False, pool_rows 3, 95.92% adjusted -> matched True
- no other body changed state.

## Link findings (2026-10-11, tooling round 24)

Root cause of the fn_1_52968 verify rejection: not padding or alignment, but the object poolfix
writes. `.fzgx/verify_last_failure.log` ends in the internal linker error above; the stale object
the failed verify left (`build/GFZE01/src/rel/main_rel/font/fn_1_52968.o`, 13:29) is the only one
of 5,852 built objects with a non-empty RELA section targeting a size-0 section.
Reproduced in isolation (`mwldeppc -fp hardware -nodefaults -sdata 0 -sdata2 0 -r` on the single
object, GC/1.3.2):

- fn_1_52968 (attempt `fn_1_52968.linkfail.1791747046.c`): oracle 100% / matched (map `@26,@38,@53,
  ...rodata.0 -> lbl_1_rodata_26F8`); HEAD poolfix: ELF_linker.c:1179; with the poolfix change: link OK.
- fn_1_53B14 (attempt `fn_1_53B14.checks.fbcfccfeed69.c`, GC/1.3.2): oracle 100% / matched (map
  includes `...rodata.0 -> lbl_1_rodata_26F8`, same callbacks array); HEAD poolfix: ELF_linker.c:1179;
  with the change: link OK. The other saved body (95.92%) does not match.

Not measured: a full `fzgx verify` (submit was refused by the session permission policy), so the
16-hash check with either function carved is still open. Gate with both files applied (no units
carved): lint 0, build ok, 16/16 hashes, pool_sample 24/24, recent 24/24, GATE: PASS. The poolfix
change is a no-op for every existing unit (none has relocations left against an emptied section;
any such unit would already have aborted the link).

## Apply

    git apply state/pending_tooling/20261011-pool-alignment-gaps.patch
    uv run tools/fzgx.py gate --also main_rel:fn_1_52968 main_rel:fn_1_53B14
    uv run tools/fzgx.py fixup fn_1_52968 --apply   (and fn_1_53B14), then fzgx verify
    (both oracle.py and poolfix.py must be applied together: the oracle change without the
    poolfix change produces objects that abort mwld)
