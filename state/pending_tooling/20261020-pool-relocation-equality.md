# Pending D patch: relocation-aware pool word equality (pools that carry pointers)

Round 52 (2026-10-20). Class: bodies whose instructions all match (or nearly) but whose
retail TU literal pool holds pointers (string tables, function pointers, switch tables), so
`oracle._pool_rows` refused to bind the anonymous `...rodata.N` / `...data.N` pool with
`pool ...: our object carries relocations (pointers inside the pool), so its bytes cannot be
proven equal to retail's`. Blocked (per the round brief): fn_1_144254 (main_rel, 99.4%),
fn_8_D034 (title, 97.5%), fn_1_451E4 (main_rel, 90.5%), possibly fn_1_1492E0 and fn_17_1798.
Census over the 698 unmatched saved bodies at 90%+: 52 carry that refusal today.

## What the patch changes (why D)

`tools/fzgx/oracle.py` only:

- `_relocated_pool_matches` (already the proof used by `_data_pool_rows` for `.data`/`.rodata`
  sections) becomes a thin wrapper over a new `_relocated_pool_mismatch(project, module, elf,
  section, address, extent, start=0)` that returns None when equal, else one line naming the
  first disagreement: the first relocation offset whose (type, module, section, resolved
  address) binding differs from retail's (`relocation at +0x4C binds main_rel:.text+0x456F8,
  retail binds main_rel:.text+0x45718`), an uncovered retail byte, a non-word relocation, or
  the first differing plain word. `start` lets the proof run on an object that does not sit at
  offset 0 of its section. A switch-table entry that relocates against the function this unit
  itself defines (`fn_1_451E4` in `.text`) binds its retail address (the code is diffed row by
  row anyway); before, that was "not a retail symbol".
- `_pool_rows`: the two refusals (anonymous pool with any relocation; `@`/`$` object with a
  relocation inside it) are removed. Instead, when our pool range carries a relocation, the
  byte comparison is replaced by `_relocated_pool_mismatch` over the same range (`address`,
  reach-limited `size`): every byte outside relocated words must equal retail's, every
  relocated word must bind the same (type, target module, section, resolved address) as
  retail's relocation at the same offset (symbol identity through `dataimport.resolve_target`,
  the same `name_ADDR` rule the oracle uses elsewhere, plus `__fzgx_offset_` aliases), and
  retail may not carry a relocation where we have none (or vice versa). A failing proof is
  reported as `pool ...rodata.0 carries pointers and differs from retail SYM[+off]: <why>`.

This changes what the oracle accepts: a new pool binding for pointer-bearing pools, hence D.
Integration is unchanged and stays hash-guarded: on `matched_pool`, `check` runs
`poolfix.apply` (retargets `...rodata.0` to the retail symbol, drops `.fzgxpool`, empties the
private pool *and its `.rela` section* when nothing reaches it) and re-diffs; if the private
section cannot be emptied (the body also defines retail TU objects) the function stays a
pool match and the retail object is linked. `fzgx verify` checks all 16 hashes either way.
Pending `20261011-pool-alignment-gaps` (uncovered dtk padding inside a pointer pool) is
complementary: its `poolfix.py` hunk is already in HEAD, its `oracle.py` hunk touches the same
function and should be re-based on this patch (three census bodies fail on exactly that:
fn_1_146C88 98.75%, fn_1_1490FC, fn_1_52968 "no retail object covers pool byte +0x1BC/+0x7C").

## Measured gain (patch applied, otherwise HEAD 76815b25; `oracle.check` on saved bodies)

Baseline vs patched over the 698 unmatched bodies at 90%+ (best saved body per symbol):
10 bodies change state, 0 regress, every previously matched/pool-matched body still is.

- **fn_4_7938 (option, 768 B, GC/1.3.2, `.fzgx/attempts/fn_4_7938.1792448937.c`): 98.96 -> 100.0
  adjusted, `matched_pool=True`** (`lbl_4_data_0=initializer[4624]`, `lbl_4_rodata_0=
  initializer[216]`, `link_conflicts []`). Would land as a pool match through `api.submit`.
- fn_1_144254 (main_rel, primed body `.1792526682.c`): 98.05 -> 98.44, the rodata pool binds
  (`lbl_1_rodata_92C0=initializer[904]`, 42 pool rows). Two rows remain and are NOT this
  class: retail keeps the function's 8-pointer local-array initializer inside the TU pool at
  +0x33C..+0x358, where `fixup_evidence.shared_pool_primer` emits raw zero words (REL
  relocation sites) as `fzgx_pool_table`, so MWCC appends our initializer at +0x388
  (`lwz r12, 0x33c(r31)` vs `0x388(r31)`). The primer needs to emit pointer words
  (`(unsigned long)&lbl_1_data_424D0`...) at relocated retail offsets: a separate
  category-C round in `fixup_evidence.py`.
- fn_8_D034 (title, `.final.1792507086.c`): 63.14 -> 63.41 (pool binds:
  `lbl_8_rodata_368=initializer[160]`); the rest is register allocation (r30/r31 swap,
  `mr r30, r3`), not a pool question. The 97.5% in the brief is the similarity score; the
  row-adjusted score was always 63-75.
- fn_1_451E4 (main_rel): no score change; the note now names the real residue:
  `relocation at +0x4C binds main_rel:.text+0x456F8, retail binds main_rel:.text+0x45718`
  (a switch case lands at a different offset: code shape, not the pool).
- fn_1_52968 98.44 (4 -> 8 pool rows), fn_4_A0C 90.0 -> 91.0, fn_1_C0E00 90.06 -> 90.36,
  fn_10_22998 89.45 -> 89.8, fn_80055304 81.76 -> 82.39, fn_10_15B20, fn_1_144F40: more rows
  bound, none closes.
- fn_1_1492E0's saved bodies do not compile (`undefined identifier 'data'`); fn_17_1798's
  residue is a `...bss.0` note, not this class.

## Gate output (patch applied)

    lint: 0 finding(s); build ok: True; hashes OK: 16/16
    pool_sample: 24 passed, 0 failed, 0 skipped
    recent: 24 passed, 0 failed, 0 skipped
    named: 1 passed, 0 failed, 0 skipped   (main:fn_8004EC34, the pool unit whose private rodata carries relocations)
    GATE: PASS

## How to apply

    git apply state/pending_tooling/20261020-pool-relocation-equality.patch
    uv run tools/fzgx.py gate --also main:fn_8004EC34

then land fn_4_7938 from `.fzgx/attempts/fn_4_7938.1792448937.c` (GC/1.3.2) through
claim/write-unit/submit and `fzgx verify`.
