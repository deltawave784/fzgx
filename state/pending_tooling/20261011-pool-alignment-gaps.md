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

## Apply

    git apply state/pending_tooling/20261011-pool-alignment-gaps.patch
    uv run tools/fzgx.py gate --also main_rel:fn_1_52968 main_rel:fn_1_53B14
    uv run tools/fzgx.py fixup fn_1_52968 --apply   (and fn_1_53B14), then fzgx verify
