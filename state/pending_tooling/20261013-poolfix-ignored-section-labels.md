# poolfix: undefine labels left in sections apply() empties (category D)

Class: `poolfix.apply` empties a private section (size 0, flags 0, so mwld ignores it as
"unknown") but `drop_private_rodata`/`drop_private_data` only undefine OBJECT symbols in it.
A NOTYPE label MWCC emits for the section (`...bss.0` when a `tu_section_layout` .bss binds
every object by name) stays defined in the ignored section and mwldeppc 1.3.2 crashes in the
`-r` partial link: `Unhandled exception: c0000005 At address: 0043d600`. fn_1_138E44 hit this
twice in batch 144 (agent submit, then `fixup --module main_rel --apply`).

Isolation (scratch `mwldeppc -r` on the single object): raw compile links; apply step by step,
`.fzgxpool`, retarget, `.rodata` and `.data` drops still link, the `.bss` drop crashes.
Nulling the one remaining `...bss.0` symbol links; keeping .bss ALLOC at size 0 also links.

Fix: `Elf._undefine_leftovers(sec)` before a section is emptied in both drop paths: every
non-SECTION symbol defined there that no relocation reaches is made undefined (the same
treatment `drop_section` already gives the primer section).

Why D: it changes the object post-processing the `mwcc_pool` rule applies to every pool unit
(how a unit is linked) and the object the oracle diffs after retargeting.

Measured (patch applied on 67a10f62):
- crashing body `.fzgx/attempts/fn_1_138E44.linkfail.1791943008.c`: oracle exact match, the
  post-apply object has no link hazards (`poolfix.link_hazards` -> []) and `mwldeppc -r`
  links it (before: crash). Full 16-hash link of this exact body not measured: fn_1_138E44
  already landed (40c93554) with an equivalent body that has no .bss layout.
- all 598 matching pool units recompiled and post-processed with HEAD and patched apply:
  595 byte-identical, 0 different, 3 compile failures unrelated to poolfix (DOL GX/DSP units
  under compile_unit). The patch changes no landed object.
- `fzgx gate --also fn_1_138E44` with the patch applied: GATE: PASS (lint 0, 16/16 hashes,
  pool_sample 24/24, recent 24/24, named 1/1). Note ninja does not track poolfix.py, so the
  byte comparison above is the real evidence for existing units.

Interplay: commit 67a10f62's `api._submit` refusal (`poolfix.link_hazards`) stops firing for
this shape once the patch is applied, because the leftover labels are undefined; no change to
the refusal is needed.

Apply: `git apply state/pending_tooling/20261013-poolfix-ignored-section-labels.patch`
then `uv run tools/fzgx.py gate`.
