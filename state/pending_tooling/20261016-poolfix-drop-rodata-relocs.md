# Pending D patch: drop the relocations applied to the emptied private .rodata

Round 44 (2026-10-16). Class: oracle-matched pool units rejected at the module link by
mwldeppc 1.3.2 `internal linker error: File: 'ELF_linker.c' Line: 1179` (story.preplf,
movie_module.preplf). Blocked: fn_7_3AB0 (story, GC/1.3.2, "define retail TU bss objects"
layout family) and fn_12_B598 (movie_module, GC/1.3.2 -use_lmw_stmw on, "retail initializers
for defined data objects").

## Cause (bisected on the object alone)

`poolfix.Elf.drop_private_rodata` empties the private `.rodata` (size 0, flags 0: mwld
"Section ignored") but leaves `.rela.rodata` intact, unlike `drop_private_data` and
`drop_section`. When the dropped rodata held initializer tables of function pointers /
`__fzgx_offset_` words (fn_7_3AB0: 317 entries, fn_12_B598: 36), the relocation section is
still applied to an ignored section and every partial link (`-r` preplf and `-r1` plf, i.e.
every REL module) aborts at ELF_linker.c:1179. The DOL final link tolerates it (fn_8004EC34
links today with one such entry). Zeroing the relocation section is the whole fix: both
objects then link alone and in the full story / movie_module links, both stages.

## Why D

It changes the object `poolfix.apply` writes for every pool unit whose private rodata
carries relocations, i.e. how a unit is linked. The safety argument: `drop_private_rodata`
already refuses to empty the section unless no relocation anywhere reaches any symbol
defined in it, so the dropped bytes are unreachable and the relocations applied to them
resolve nothing (the retail data unit owns those bytes). The refusal that detects the shape
(`link_hazards`, commit b199cb5b) stays in place and simply stops firing once this lands.

## Measured gain (with the patch applied)

- fn_7_3AB0: oracle.check matched=True, pool_map unchanged, `link_hazards` [] (was 317
  relocations), story.preplf and story.plf scratch links exit 0 (were: linker abort).
- fn_12_B598: matched=True, pool_map unchanged, hazards [] (was 36), movie_module.preplf
  and .plf scratch links exit 0 (were: linker abort).
- Landed unit main:fn_8004EC34 (the only pool unit of 727 with the shape): object rebuilt
  with `.rela.rodata` emptied, DOL hash unchanged.
Without the patch both bodies are now refused at submit with the reason
`POOL OBJECT CRASHES THE LINKER ... N relocations in .rela.rodata applied to emptied .rodata`.

## Gate output (patch applied)

    lint: 0 finding(s); build ok: True; hashes OK: 16/16
    pool_sample: 24 passed, 0 failed, 0 skipped
    recent: 24 passed, 0 failed, 0 skipped
    named: 1 passed, 0 failed, 0 skipped   (main:fn_8004EC34)
    GATE: PASS

## How to apply

    git apply state/pending_tooling/20261016-poolfix-drop-rodata-relocs.patch
    uv run tools/fzgx.py gate --also main:fn_8004EC34

Then re-submit the two bodies (`fzgx fixup fn_7_3AB0` / `fzgx fixup fn_12_B598 --apply`, or the
saved attempts `.fzgx/attempts/fn_7_3AB0.1792146676.c` and
`.fzgx/attempts/fn_12_B598.linkfail.1792147025.c`) and let `fzgx verify` link them.
