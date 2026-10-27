# Pool binding across retail alignment padding (tooling round 68, part A)

Class: a primed TU literal pool that carries pointers is proven word by word against the
retail objects that cover it (`oracle._relocated_pool_mismatch`). Retail pads before an
8-aligned object (main_rel `lbl_1_rodata_9478` ends at 0x947C, `lbl_1_rodata_9480` is
`align:8`), no dtk object covers the pad word, and the proof stopped with
"no retail object covers pool byte +0x1BC" although our primer reproduces the zero word.
Every pool row of the function then stayed unbound.

Change (`tools/fzgx/oracle.py`): `_cover_alignment_padding` covers an uncovered run only when
it lies between two retail objects of the same section (one ending exactly at the run, one
starting exactly after it), is shorter than the next object's `align`, ends at that object's
aligned start, overlaps no object, and the retail section bytes there are all zero. Those
bytes become the expected bytes; relocations are still compared (retail has none in padding,
so a relocation of ours there fails the binding comparison).

Why D: it changes what the oracle accepts (pool binding).

Gate (with the patch applied, `--also` the ten matched sel_static_disp units bound into
`lbl_1_rodata_92C0`): lint 0 findings; build ok; hashes 16/16; pool_sample 24 passed;
recent 24 passed; named 10 passed; GATE: PASS.

Measured gain (saved bodies, `oracle.check`):
- fn_1_146C88 (.fzgx/attempts/fn_1_146C88.1793078269.c): pool rows bound 10 -> 23, differing
  rows 4 -> 2 (left: one scheduling move of `lwz r7, 0x24(r28)`); note gone.
- fn_1_145C6C (.fzgx/attempts/fn_1_145C6C.1793038833.c): pool rows 0 -> 1, differing rows
  40 -> 39 (the rest is register allocation); note gone.
Neither becomes exact from this change alone.

Apply: `git apply state/pending_tooling/20261026-pool-alignment-padding.patch` then `uv run tools/fzgx.py gate`.
