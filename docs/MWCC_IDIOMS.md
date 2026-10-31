Starter notes on CodeWarrior for GameCube 1.x codegen at `-O4,p`. Grow this
file from what actually unblocked functions; keep each item one or two lines.

## Laws to apply first (probe-verified, 2026-09-15)

- **Paired-single vectors**: `psq_l f, off(rN), 0, qr0` / `psq_st` / `ps_sub` / `ps_add` /
  `ps_muls0` / `ps_madds0` / `ps_merge00` in retail are inline-assembly helpers. Write
  `#include "psvec.h"` and call `psvec_sub(a, b, out)`, `psvec_add(a, b, out)`,
  `psvec_scale(a, s, out)`, `psvec_scale_add(acc, v, s, out)` (out = acc + v*s),
  `psvec_sub_scale_add(a, b, s, d, out)` (d = a - b; out = b + d*s) and
  `psvec_set(out, z, y, x)` (note the z, y, x order) with `void *` addresses such as
  `&v->x`. Never write the three scalar component statements: MWCC can only produce
  the indexed `psq_lx` forms from C, so scalar or `__vec2x32float__` code can never match.
  Pass loads straight as `psvec_set` arguments; loading them into locals first changes
  the registers.
- **Large inline helpers** (GC/1.3.2 probes, 2026-10-28): `-inline auto` inlines a `static inline` helper
  only up to MWCC's default `inline_max_size` (a helper of 40 one-line `if (a > k) ext(a + k);` inlines,
  48 is called). `-inline on/deferred/all` and `#pragma inline_depth` do not lift the limit. What does is
  `#pragma inline_max_size(4096)` (or `#pragma always_inline on`) **in effect at the caller's definition**:
  the pragma state at the call site decides, so a pragma placed before the helper and switched off before
  the caller leaves the call (that is why batch 287's wrappers stayed calls). Put it on the line before
  `void FN(...)`; with no helper in the unit it changes nothing (fn_1_D523C byte-identical). Measured:
  fn_1_D523C whole-body wrapper 4.4% (call) -> 97.2% inlined; fn_17_1798 2.0% -> 97.35% (identical to the
  plain body). Inlining a whole body only renumbers its locals as `@` temporaries; it does not by itself
  turn `beq exit` into retail's `bne next; b exit`.
- **Uninverted `bCC next; b exit` pairs come from one `||` early-return chain** (GC/1.3.2 probes and
  real bodies, 2026-10-28). MWCC inverts `if (c) goto L; goto X; L:` only at statement level
  (`fold_and_invert_conditional_branch`, optimizer/COptimizer.c); nothing at PCode level inverts a pair.
  `if (A || B || C) return;` lowers its leaves in codegen: A and B branch to the return block, the last
  leaf branches round it (`bCC next; b exit`), and the return block keeps several predecessors, so the
  pair survives. Separate `if (A) return; if (B) return;` or an `&&` guard around the body give the
  inverted `b!CC exit`. Apply it whenever retail shows the pair after a run of early-exit tests: merge
  the consecutive early returns (including the earlier ones) into one `||` condition. fn_1_1018BC
  `if (at10 == NULL || (f & 1) || ((f >> 1) & 1)) return;` (7 -> 5 rows; a `switch` on the last bit
  gives the same pair), fn_1_D523C `if (slot == -1 || k == 2 || !(k == 1 || c0 != a || ...)) return;`
  (23 -> 21 rows, branch rows gone; only the base-register swap remains). A dead `b X` block right after
  a switch dispatch is the same mechanism: a `default: return;`/case body whose block was reached only
  by retargeted branches stays in the code (probe b7). Switch lowering (backend/Switch.c, identical in
  1.3.2 by probe) emits the lower-bound test `cmpwi 0; bge body; b default` for every signed 32-bit
  switch whose default covers values on both sides of the case range: both sides are separate default
  ranges, and casting to u8/u16/u32 changes nothing (the expression is promoted to `int`). The compare
  is omitted only when the two leftmost ranges share a target (`b` alone, the compare dies) or for an
  unpromoted unsigned type narrower than int, which would use `cmplwi`. fn_1_D7758's retail
  `cmpwi 20; bge exit; b body; b exit` is therefore not a plain `switch (i)`; still open.
  The fixup family `fixup_evidence.exit_branch_pairs` (sweep `--families exits`) applies this when a
  differing row holds a branch: it merges runs of early exits into one `||`, splits `||` exits, turns a
  trailing `&&` guard into a negated early `return`/`continue` merged with the exits before it (and back),
  and moves, drops, adds or respells switch defaults (range switches become range tests). It reproduces
  both hand fixes above from the old bodies; the switch-default forms did not reach fn_3_152BC's dead
  `b` or fn_1_D7758's pair (default first/last/dropped/`break`/`goto` all compile identically).
- **Fused multiply-add**: `a + b*c` in one expression gives `fmadds`; a product held in a
  temporary or wrapped in `(f32)` stays `fmuls` + `fadds`. Only the product that is a
  direct operand fuses: retail `fmuls; fnmsubs` for `x*y - z*w` is `(f32)(x*y) - z*w`;
  retail `fmuls x; fmadds y; fmadds z` for a squared length is `(f32)(x*x) + y*y + z*z`.
- **Float literal in double context** (GC/1.3.2, 2026-10-26): `(f64)0.8f` and `0.8f * d`
  fold to a new double constant (`lfd` of 0x3FE99999A0000000, one more pool slot that
  shifts every later shared-pool offset); retail's `lfs` of the float word followed by
  double arithmetic is `f32 k = 0.8f; ... k * d`. `native_pool_literals` emits that form
  (`promoted floats held`), resolves pool reads made through inline helpers' pointer
  parameters, and offers each native body already primed (fn_1_6AF70 97.3 -> 99.3,
  fn_1_D6C10 95.7 -> 97.1).
- **Signedness**: `cmpwi`/`lha`/`extsh`/`srawi` need a signed operand type (cast or
  declaration), `cmplwi`/`lhz`/`clrlwi`/`srwi` an unsigned one; flip the operand of that
  statement, not unrelated locals.
- **Locked cache**: `lis rX, 0xe000` + `lfs f, 0xc(rX)` is `*(f32 *)(0xE0000000 + 0x0C)`
  (the current matrix); do not invent a symbol for it. Translation-column writes
  (stores to +0x0C/+0x1C/+0x2C) where retail loads x, y, z first into f2/f1/f0: copy
  propagation sinks the first-stored value's load to its store (x loaded last, f0). Read
  that one value through a volatile view (`x = *(volatile f32 *)&v->x;`) instead of a
  function-wide `opt_propagation off`; for computed columns (`m[i][0] * s + m[i][3]`)
  also declare the three temporaries first in the function, z first, so the scale keeps
  the higher FPR (fn_1_8D08, fn_1_1ACC0; `fixup` family `locked_cache_columns`).
  When a `psvec_set`/asm helper follows the copy and retail keeps its x/y in f30/f31 above a
  long-lived float (f29), copy through a static inline helper whose own locals hold the
  values (`static inline void F_lc_copy(volatile f32 *s0, f32 *s1, f32 *s2) { f32 x = *s0;
  ... }`, called with `&v.x`...): inlined locals number above every function local, so the
  asm helper's register parameters (they interfere with every earlier value and f0-f13)
  keep degree >= K at their scan and colour after the long-lived float. Function or block locals and value parameters all fail (capture of
  fn_1_438AC, 2026-10-26; the same family emits this variant).
  A computed column where retail keeps each load and its `fmadds` result in one FPR
  (`lfs f4, 0x8; ... fmadds f4, f4, f5, f0`) is an unsplit read-modify-write local
  (`x = m[0][2]; x = x * s + m[0][3];`): with `opt_lifetimes` on, MWCC's range splitter
  (IROUseDef.c `fn_00459420`) gives the result its own `@N` object numbered above every local
  (capture of fn_1_10CC38, 2026-10-26). Retail compiled such functions under
  `#pragma opt_lifetimes off` with one named variable per region of every other reused local,
  the new names declared first (split objects number above the declared locals). `fixup` family
  `lifetime_splits` writes those regions mechanically (fn_1_10CC38 landed).
- **Range-split creation order** (capture of fn_1_1262A4, 2026-10-26, landed): the splitter walks
  the variable records in creation order, which is the order of each local's *first reference* in
  the function; every later web of a reused local becomes the next `@N`, and split objects number
  in reverse creation order above the declared locals. So when two reused locals' regions in one
  loop take swapped callee-saved registers (sort loops: counter r30 / pointer r29 against retail
  r29 / r30), change which is referenced first (`p = base; for (c = 0; ...)` against
  `c = 0; p = base; for (; ...)` or `for (c = 0, p = base; ...)` in the first loop that uses
  them). A loop pointer retail keeps high (`lwz r30, nodes(rObj)` straight in) while ours, a
  separate declared local, falls to r25 is a split region of an earlier loop's pointer: reuse
  that variable (`e1` renamed to `e0`). Declaration order changes neither. `fixup` family
  `split_region_orders` (sweep `splitorder`) emits both levers and their combination.
- **Evaluation order at a call**: a value produced by a call and consumed in an expression
  is evaluated first when written inline; holding it in a local moves the call and can
  swap `mullw`/`add` operands (fn_1_76704).
- **Power-of-two products in an add**: `(n - 1) * 2 + n` gives `add rD, n, shifted` under
  every operand order; `((n - 1) << 1) + n` (or a held `m = (n - 1) * 2; m + n`) follows
  source order, `add rD, shifted, n` (fn_1_112F40). `fzgx fixup` tries it (`shift_products`).

- **Loop pointers**: a pointer initialised straight into its callee-saved register
  (`addi r30, r3, sym@l`, no copy) and stepped by a constant is a strength-reduced
  induction shadow of an indexed access: write `base[i].f` or `*(T *)((u8 *)base + i * K + off)`
  with the loop counter, never `p = base; ... p = (T *)((u8 *)p + K)` (that lowers as
  `addi r0, ...; mr r30, r0`). Likewise `off += K` against `i * K`. Shadows are numbered
  above every declared local and coloured first (r31 downward); a constant base that
  retail keeps above them (`manager = lbl + 0x50000` in r31 with the induction shadows in
  r30/r29) is itself a shadow: hold it in a one-member struct (`struct { u8 *value; } mgr;`)
  so its load is the CSE'd value (fn_10_7130, capture-verified).

- **Literal pool base** (383 unmatched functions carry a private `lfd @N` where retail has
  `lfd f, off(r31)`): MWCC lays every `.rodata` object *defined in the unit* (the compiler's own
  float/double literals, including the 2^52 int-to-float constant, `static const` tables) in one
  section in definition/first-use order and, once a base register holds one of them, addresses
  the rest by displacement. An `extern` view of retail's pool can never join that base: the
  compiler's constants stay in the unit's private pool. So the whole retail pool region has to be
  defined inside the unit (`native_pool_objects` + `shared_pool_primer`). Two rules of that
  definition, probe-verified 2026-09-16: a `const f32` scalar definition folds into a literal
  (fine, it dedupes onto the primed slot) but a `const u32` scalar folds into `li` — integer pool
  words must be one-element arrays read as `[0]` (retail's `lwz r0, 0x490(r31)`); and the
  oracle's pool byte comparison must stop at retail's last displacement (the next word belongs
  to the following object). Refinement (probe `head.c`, 2026-09-16): the shared base is the
  *section symbol* `...rodata.0`, which MWCC CSEs across a function's own private literals; a
  user-declared `const` object (even `static`, even one defined in the unit) is addressed by its
  own symbol and never joins that base. So retail's `lfs f, 0x3c(r30)` reads are plain float
  literals in the source (`5.0f`), not fields of a pool object: bodies must spell pool reads as
  native literals (`native_pool_literals`), integer-read words as primer table entries, and the
  primer fixes the first-use order. `#pragma pool_data on` produces the same base-relative
  shape for a unit's own data but is not what retail used (retail leaf functions keep
  per-literal `lis`).

- **Parameter above a local** (capture-verified on fn_1_A358C, landed): parameters are
  numbered below every declared local (`arg0` is vr32 under every declaration order), so a
  parameter that retail keeps in a callee-saved register *above* a local's (`mr r28, r3` with
  the loop counter in r27) is a local copy of the parameter, `s32 id = arg0;`, declared where
  the register order puts it (after the locals retail colours above it). The copy is folded by
  copy propagation unless the body carries `#pragma opt_propagation off` or the copy has its own
  lifetime; 488 stuck bodies show the retail shape, 136 have ours below retail. Evidence family
  `retail parameter copy` (`fixup_evidence.parameter_copies`) reads both prologues and ranks the
  predicted position first; it reproduced every retail parameter register in 85 of 137 bodies.
- **Survivor order** (fn_1_76504, replay-verified): among callee-saved webs the first claims are
  not by vreg number but by *survival*: a web whose total interference degree stays >= K=29
  through simplification pops first (r31 downward, longest survivor first); only then does the
  descending vreg sweep colour the rest. A retail parameter in r28 above a constant-address
  shadow (r27) with identical code means the parameter interferes with ~4 more webs in retail
  (a longer lifetime or more temporaries in its range); declaration order and the struct
  wrapper cannot change it. `simplify_replay.py DIR 0001 32:+6` answers "how much more degree".
- **Lifter pool reads** (fn_1_53830, 405-body sweep 2026-09-16): the byte-addressed forms
  `*(f32 *)((u8 *)pool + 0x140)` and `*(u32 *)((u8 *)pool + 0x138)` through an alias of the pool
  object are pool reads too; `pool_scalar_reads` turns the float ones into native literals and
  the primer turns the integer ones into table entries. Each integer word the function reads
  must be its own one-element table object: `table[1]` materialises the table's address where
  retail has `lwz r0, 0x13c(r29)`. Native literals + primer over the 405 unprimed
  private-literal bodies: 5 matches, 258 improved (up to +31 points), 83 regressed, 97 s.
  The regressions were reads retail makes by the literal's own `lis`/`lo` pair or as a
  materialised single address (`addi r5, r3, sym@l; lfs f0, 0x0(r5)`): the extern declaration
  already reproduces both, and a native literal pools them behind a base instead. Only reads
  through a base that retail reads at several offsets convert (`memory_loads` records the
  form; `pool_scalar_reads` keeps multi-offset pool bases).
- **Compiler 2x loop unroll (2026-10-05, fn_12_31224).** A CTR loop with two copies of one step,
  the base advanced by twice the element size, and a counter that only increments
  (`li r3, 0; mr r7, r3` ... `addi r7, r7, 1; bdnz`) is MWCC -O4 unrolling a
  `for (i = 0; i < 2N; i++)` loop by two; the dead counter is the unroller's. A hand-unrolled
  draft (`i < N`, two steps, `p += 2K`) never gets it. Write one step over 2N trips, indexed
  off the unadvanced base (`e = base + 0x180 + i * 0x40` folds into `lbz 0x198(r8)`).
  The key compared in the loop moved r3 -> r9 only with the outer parameter declared `u8` and
  the inline helper still casting `(u8)key`; then declaration order `i, e, found, base` matched.
  `fixup_source.rerolled_loops` (with `narrowed_parameters` and the reordered locals) emits it.
- Reversed `fmuls` operands on a multiply by 2^-n (retail: variable first) are a division in the
  source: MWCC strength-reduces `x / 2.0f` to `x * 0.5f` keeping x first, while `0.5f * x` keeps the
  constant first (fn_16_2EEC, fn_1_535A0 `/ 8.0f`, fn_1_130C84 `/ 4.0f`, fn_1_13DDB8, fn_10_D5D4).
  `fixup_source.reciprocal_divisions` (sweep family `recipdiv`) proposes each site and all sites.
- `li rA, K; mr rB, rA` (a constant copied between locals) is an inlined static helper's
  parameter: MWCC propagates a constant local into a `li` per use but keeps a helper parameter a
  variable (fn_10_AB98 `step`, fn_3_3F20 `dir`, fn_12_2F7AC `result`). An identity helper
  `static inline s32 k(s32 v) { return v; }` folds and changes nothing (measured).
  `fixup_source.constant_inline_parameters` (sweep family `inlineparam`) wraps the body, or the
  code from the constant assignment on, in `NAME_fzgx_inl` taking the constant.
- **Induction shadows and loop counters** (GC/1.3.2 captures, 2026-10-15: fn_1_1188CC,
  fn_1_11B4E4, fn_1_7B558, fn_3_20748). Compiler objects (`@N`: strength-reduced pointers and
  byte offsets, CSE recomputes, promoted one-member struct wrappers, split regions) are numbered
  above every declared local in *reverse creation order*: loop 5's shadow sits above loop 7's,
  and the split regions of one counter reused across loops (`i` for loops 1, 3, 5) are created
  after every induction shadow, so they land just above the locals (v50-51 under shadows at
  v55-60) and compile identically to fresh per-loop counters. Consequences, each measured:
  declaration order, counter reuse and fresh counters cannot make a counter claim a callee-saved
  register before a shadow of a *later* loop (fn_1_1188CC: retail i1=r29/i3=r30 before the
  loop-5/7 shadows take r26; no single or paired renumbering of the captured graph reproduces
  it); a declared pointer local stepped in the latch removes the shadow (loop 5's inner loop
  matched) but changes the first-scan degree of its K-boundary neighbours (`i`/`node`/`model` at
  degree 30-35 with K=29), which moves the whole spill-phase order (`rope` r27 -> r28); a
  declared `u16 *` over `n->links[k]` lowers as `addi rP, rN, 4; lhz 0(rP)` where retail keeps
  the base copy `mr rP, rN; lhz 4(rP)` (so retail's is the shadow); unwrapping a struct-wrapped
  counter loses the `mr rOff, rI` shadow initialisation (fn_1_7B558); replacing a declared
  `s32 iy = i` by `(s32)i` turns it into a CSE object coloured before the pool base
  (fn_3_20748, 99.5 -> 99.1). The capture verdict now reports this law for shadow blockers;
  `fixup_capture.pointer_locals` is the only lever and it is already tried at three positions.
- **High-half base swap is a TU-object question, not an allocation one (2026-10-25).** Retail
  `addi r30, r3, lbl@l; addis r31, r30, 0x5` (base r30, high half r31) against our r31/r30 pair
  is not reachable from an extern cluster: over 40 spellings of fn_10_4790 (declaration and
  definition order, carriers on either side, recomputed `base + 0x50000`, inline helpers,
  `register`, typed struct members, `opt_propagation/lifetimes/common_subs off`) none flips it.
  The GC/1.3.2 capture shows why: with propagation on, a constant-address local is propagated
  into straight-line uses and rematerialized; with it off the base's address temp is numbered
  above the declared high-half local and colors first. A matched sibling (fn_10_12D8) only
  keeps the base because control flow separates its last use. Defining the retail objects in the
  unit gives the exact pair, since MWCC addresses them off its own section base:
  `fixup_layout.flatten_byte_views` turns byte-pointer locals at constant offsets (`base =
  (u8 *)&lbl; hi = base + 0x50000; *(T *)(hi - 0x6c78)`) into `lbl + 0x49388` arithmetic for
  the bare layout model (fn_10_4790 84.9 -> 100, fn_10_8314 -> 100, fn_3_6E14 95.2 -> 98.9).
  Typed-struct bases (`Obj *obj; u32 upper = (u32)obj + 0x20000`, fn_1_3CDB0) are not covered yet.
- **Interior addresses (`addi rX, rBase, 0x8; lbz 0x1(rX)`) are aggregate objects of the TU**
  (probe compiles under GC/1.3.2, 2026-10-26). With the objects defined in the unit, MWCC reads a
  scalar object base-relative (`lbz 0x1f1(r31)`) and materializes the address of an aggregate
  (array or struct) before every member access (`addi r3, r31, 0x8; lbz 0xa1(r3)` for
  `ch[1].st` of `static Chan ch[2]` at +8), even for a constant index. An extern view of the
  cluster folds both offsets (`lbz 0xa9(r31)`) under every inline helper, pointer parameter,
  local and pragma tried. Of two anonymous section bases (`.bss` and the unit's own `.data`),
  the callee-saved register goes to the section whose objects are *defined first in the file*:
  fn_1_B4AC0 got retail's `r31 = bss, r30 = data` only with the bss layout placed before the
  data pool. `tu_section_layout` now reads `(u32)p + N` model uses and uncast `u8 *p = &lbl`
  byte views and offers each layout ahead of the unit's data (fn_1_C24A4 96.6 -> 98.2,
  237 -> 87 rows). Not this class: ED540's `addi r20, r31, 0x19c8 ... addi r20, r20, 0x620`
  (a struct model member, folded by copy propagation under every spelling tried) and bodies
  that pass the model pointer to inline helpers (fn_1_BA144).
- **Lowering-temporary swaps: embed the assignment in its first use** (2026-10-26, GC/1.3.2
  capture). When the capture verdict says two temps are swapped ("numbered later than retail"),
  renumber the window in the replay (`Graph.relabel` over permutations of the target block's
  vregs) to read the creation order retail needs. fn_3_225F8's two blinking-arrow blocks needed
  the sum's web below the `PF(16)` load and the load below the 1.0f constant: `v21 = 1.0f + 0.5f*t3;
  v22 = PF(16) * v21;` creates the constant first; `v22 = PF(16) * (v21 = 1.0f + 0.5f*t3);`
  creates the load first and matched. `fixup_source.expression_embedded_assignments` (engine
  `rewrites`, sweep family `embed`) tries every adjacent site.

## Selection panel evidence (2026-09-15)

- Four-byte color structs reproduce pooled `lwz` initializers; scalar `const u32`
  colors can fold into immediates. Automatic struct initializers keep per-iteration copies inside loops.
- Separate initialized data objects establish MWCC's native data base. A pointer
  to an extern aggregate can change base setup and address lifetimes despite identical field offsets.
- Complete nested calls before binding a localized string table when retail does;
  an inline indexed lookup closed the last four register differences in `fn_10_1C2D8`.
- DTK `pad_` objects contained 93 of this panel's 867 data pointers. Pool proof
  must inspect their relocations, including unused slots, rather than assuming zero padding.
- Split grouped declarations before allocation analysis. On `fn_10_1D314`, this
  preserved the code and exposed ten locals; the resulting partial repairs remain unmatched.

## General observations

- Register allocation follows declaration order of locals and argument order.
  Reordering declarations moves registers; extra temporaries can force a spill
  or a different register.
- `int` vs `u8/s16` locals change sign/zero extension (`extsb`, `extsh`,
  `rlwinm ... 0xff`). Match the extension you see.
- `-inline auto`: small `static` functions in the same file are inlined into
  callers. If retail has the body inline, define the helper `static inline` in
  the same unit.
- Float compares: `fcmpu` + `cror` patterns come from `<=`/`>=`; a plain
  `fcmpo` from `<`/`>`. `frsp` appears when a double is narrowed to float:
  use `f32` literals (`1.0f`) to avoid double promotion.
- `switch` with dense cases produces a jump table (`.data`); sparse cases
  produce compare chains. A `default` placement can change the layout.
- Struct field access uses the field offset directly in `lwz r, off(base)`;
  when you see an offset, add the field at that offset in the struct.
- Loops: `bdnz` implies a counted loop the compiler could prove; `for (i = 0;
  i < n; i++)` with `n` loop-invariant. `mtctr` at loop entry.
- `stwu r1, -N(r1)` frame size N and `_savegpr_NN` tell how many non-volatile
  registers are live across calls: roughly how many values survive a call.
- String literals go to `.rodata` (`-str reuse` pools identical ones); float
  constants to `.rodata` in RELs (`-sdata2 0`) and `.sdata2` in the DOL.
- `lis/addi` (`@ha/@l`) is a normal address materialisation, not a constant:
  declare the symbol and take its address.
- A value loaded into `r4` (or `r5`...) right before a `bl`, while `r3` is left
  untouched, means the callee takes the caller's first argument as its own
  first parameter and the loaded value as the second: write
  `callee(arg0, table[idx])`, not `callee(table[idx])`. Register choice here is
  a signature question, never a compiler quirk.
- The same in reverse: if you need a parameter in `r4`, add the preceding
  parameter to the signature even when the function body ignores it.
- A missing return can look like register allocation: `fn_80069AE0` needs the
  loaded flags in r3 on one path and the callee's result on the other. Returning
  the flags after both paths incorrectly keeps them live across the call.
- (tooling, not codegen) RELs are linked without `-strip_partial` because retail
  kept unreferenced functions; with stripping on, a carved function nobody
  references vanishes from the link and every REL importing later symbols
  fails its hash.
- A value used both before and after a call is loaded once into a local (a
  non-volatile register, `r31` down); reloading it after the call gives a
  second `lwz` retail does not have. The reverse too: two loads in retail mean
  two expressions in the source, not one local.
- Argument materialisation follows source order: `f(1, 15, g)` loads `g`
  after `li r4, 15`; if retail loads `g` first, `g` came from a local set
  earlier in the function.
- Same asm modulo two swapped `li`/`lwz` rows is never a compiler quirk: it is
  statement order or an intermediate local.

## Rules the lifter learned (each verified byte-exact on retail functions, 2026-09-08)

- `p = (struct S *)&sym;` keeps the address in a saved register across calls; a plain
  `&sym` or `sym.field` is rematerialised (`lis/addi`) after every call. When retail
  holds a global's address in r31/r30 and uses `off(r31)` after calls, write the cast form.
- A loaded value that is read again after a store to the same location lived in a
  local: `v = x; x = v + 1; f(v, &x)`. A plain `x++` reuses the register instead.
- A value used twice (two reads of the same register before it is rewritten, a call
  argument plus a return, a field plus a compare) lived in a local; recomputing the
  expression twice gives extra loads or a different register.
- A value computed into a saved register (r14–r31) before a call and used after it is a
  local assigned before the call.
- The same expression passed as several arguments of one call (`f(v, v, v)`, three
  `fmr` from one `lfs`) is a local assigned right before that call, not a CSE across
  calls (which would land in f31 with `stfd f31` saves).
- Call arguments are the argument registers written since the previous call; an
  untouched r3..r5 followed by a temporary in r6 means the function's own first three
  parameters are passed straight through: `void f(a, b, c) { g(a, b, c); }`.
- `crclr cr1eq` (`crclr 6`) right before a `bl` marks a variadic callee.
- A variadic entry saves r3-r10 and conditionally f1-f8 under `bne cr1`; these are
  the argument-save area, not sixteen fixed parameters. `fn_1_4AE0C` matches with
  `(const char *format, ...)`, a 512-byte character buffer and `__builtin_va_info`.
- Address arguments need pointer-typed prototypes; `(u32)&x` as an argument is hoisted
  into a saved register, `&x` with a `void *` parameter is recomputed per call.
- An address-taken scalar local stays a scalar (`f(&x)` recomputes `addi rN, r1, off` at
  each use); an array decays once into a saved register. A `u8` buffer is 16-byte
  aligned in the frame, a `u32` array or a struct is not.
- When fields match but a struct-copy loop starts four bytes early, check for a
  fake leading field plus an array-minus-four pointer. `fn_1_133BD8` needs an
  aggregate local with the prefix removed, preserving the union's copy extent.
- Signedness of a compare comes from the operand types: `cmpwi` needs a signed
  operand, `cmplwi` an unsigned one, whatever the width.
- Unsigned division by a constant: `mulhwu` with a magic multiplier, then
  `subf/srwi 1/add/srwi s` (or just `srwi s`); a following `mulli` by the divisor and
  `subf` is the remainder. Write `x / 360`, `x % 360`; never the magic number.
- int → float: `lis 0x4330; stw hi; (xoris x,0x8000;) stw x; lfd; fsub(s) <2^52 constant
  from the pool>` is `(f32)(s32)x` (with the xoris) or `(f32)(u32)x` (without). The
  constant is a pooled `lbl_*_rodata_*` symbol; float → int: `fctiwz; stfd; lwz low` is
  `(s32)f`.
- A struct assignment of 8×N bytes is a counted loop: `li rN, N; mtctr; lwz/lwzu/stw/stwu
  … bdnz` with both bases pre-decremented by 4. Write `dst = src;` with a struct of
  that size; never a loop.
- A `while` loop compiles to a jump to the test at the bottom; loop variables live in
  locals initialised before the loop. Registers assigned inside an `if` block and read
  after it are locals too; a flag set to 0 before an if-chain and to 1 inside is a
  local, not a constant.

## What closed the agents' plateaus (spelling search over 1,285 saved bodies, 2026-09-08)

Each line is a family that turned a 60–99% body into a match; the count is how many.
- Declaration order of locals (5) and moving one local into an inner block (2): the
  allocator follows declaration order, so a swapped r30/r31 is a swapped declaration.
- One extra unused trailing parameter (3): a function that ignores an argument still
  declared it; add `u32 unused` before rewriting anything else.
- Hoisting a call argument into a local right before the call (4), or inlining a
  single-use temporary (4): `f(a, p->x)` vs `t = p->x; f(a, t)` moves the load.
- Signedness of a local (3), a parameter (1), a struct field (2): `s32` vs `u32` changes
  `cmpw`/`cmplw` and `extsh`/`rlwinm`, nothing else; flip one at a time.
- `x == 0` -> `!x`, `x != 0` -> `x` (2), and commuted compare operands `2 == x` (2):
  the branch is the same, the register that holds the constant moves.
- Two adjacent statements that share nothing, swapped (2): free order, different
  scheduling.

## Large saved bodies (2026-09-14)

- `fn_8_1394` (GC/2.0): assigning the zero operand inside a floating comparison
  gives it a separate scalar lifetime and reproduces the retail operand order.
- `fn_1_988DC`: completing a dead integer counter's square immediately after its
  definition changes the later register interference. Its floating clamp also
  needs the retail unordered branch behavior; positive nested tests and a
  min/max expression are not interchangeable for NaNs.
- `fn_1_13C1A0`: a 200-byte stack copy is ten rows of five words. Recovering the
  row shape reproduces the address arithmetic that a flat guessed table misses.
- `fn_1_13D460`: placing the count assignment before packet setup and forming
  the strip base plus width-times-index before the final displacement reproduces
  the allocation and operand order without declaration permutations.
- Shared BSS section bases do not emit relocations to every named object. Bind
  split definitions by measured module, section, address and owner bounds. Give
  interior pieces canonical `OWNER__fzgx_offset_HEX` names. Private primer storage
  can disappear only after its section base is proven and no live relocation
  reaches the remaining storage. This linked the 6,608-byte `fn_1_AD264`.
- `.data` section bases (probe compiles, 2026-10-06): MWCC addresses a TU's own
  `.data` objects off one `...data.0` base only when the function references
  three or more distinct objects; with two it addresses each by name. A byte view
  `(u8 *)obj + k` never folds into `addi rX, rBase, off`: every referenced word-
  aligned address must be its own object (dtk joins unlabelled string literals).
  Section-base temporaries are ordered by where each section's first definition
  sits in the file: defining the data block above the literal pool turned
  `fn_1_B5F20`'s data r29/pool r30 into retail's pool r29/data r30.
  `fixup_layout.tu_data_objects` emits this layout (whole block, pointer words as
  `__fzgx_offset_` initializers, `.fzgxpool` primer in retail order).
- Indexed table reads `addi rX, rBase, off; lbzx/lhzx/lwzx rD, rX, rI` (probe compiles,
  2026-10-11): the shape belongs to an array object the TU *defines*, indexed by a variable,
  and only under GC/1.3.2. Every extern spelling folds into `add rY, rBase, rI; lbz off(rY)`
  under every compiler (struct of arrays, `tbl->f[i]`, `tbl[K + i]`, 2-D arrays, held
  base and offset locals); GC/1.2.5n and GC/1.3 fold even the defined arrays (1.3 keeps
  `add; lbz`, 1.2.5n CSEs the sum). A defined object at offset 0 still gets `addi rX, rBase, 0`.
  The same law covers address values: `(u8 *)obj + (i * K + c)` folds (`add rI, rI, rBase`),
  the row-array view `((u8 (*)[K])obj)[i] + c` materializes `addi r0, rBase, 0` first
  (fn_1_1018BC 96.5 -> 97.7); loads compile identically either way. `tu_data_objects` now
  covers `.rodata` blocks (const definitions; DOL tables such as lbl_800929D8 + 0x20/0x40/0x60),
  index expressions `x[K + i]`, the one-member pointer carrier, and static inline helpers that
  receive the view as an argument; `row_array_views` rewrites the byte rows. A `.rodata`
  struct model as TU objects also fixed fn_1_107C74's base-register order (rodata r28, data r29).
  Not reachable this way: fn_1_2C97C's `addi r3, r6, 0x10; lhzx r4, r3, r5` over an extern
  array of 0x14-byte structs addressed by name (held field pointers `u16 *p = &arr[0].f; p[o]`
  give `addi; lhzx` for every pointer but the first used).

## Shared SDK state (2026-09-15)

- A code-complete function can still have a wrong unused data prefix. In VI
  configuration, reconstructing the retail prefix and symbolic switch pointers
  closed two unresolved base relocations without changing an instruction.
  Verify pointer relocation kind, module, section and destination as well as
  initialized bytes. A size-zero section symbol is not a relocation-free object.
- Keep section anchors that already have verified bindings. Rename remaining
  native BSS members from their measured positions, including SDK layout gaps.
  Missing BSS symbols can hide complete typed objects: the OS inquiry block and
  DVD workaround alarm/buffers accounted for 112 bytes of shared storage.
- MWCC emits unreferenced BSS definitions in reverse declaration order. Data-only
  grouped imports must reverse definitions and still prove every object offset,
  section extent and alignment. First-use order in a function primer is a
  different case; put such primers explicitly in `.fzgxpool`.
- Preprocessed C may contain spaces around `->`. Normalize the member-access
  token before the layout parser checks whether a base pointer escapes.

## Lost switch cases and string objects (2026-09-15)

- An integer interval recovered as `if (value < 2 && value >= 0)` can be a
  switch with cases 0 and 1. MWCC retains a different conditional/unconditional
  branch pair for the switch. Restoring contiguous cases exactly matched
  `fn_8002A74C`, `fn_8006BA74` and `fn_12_3256C`. This is a source control-flow
  distinction; disabling dead-code elimination did not repair these examples.
- A shifted sign-bit test can be an incorrectly lifted rotated low-bit test.
  Recover the retail `__rlwnm(value, amount, 31, 31)` expression before changing
  register allocation. This closed `fn_1_7F3AC`, `fn_1_557C4` and `fn_1_55A84`.
- Error-string pools need separate native string objects. A pointer to one
  external character array changes both base initialization and offset-zero
  address formation. Recover each string, its terminating zero and measured
  padding, and reject any intersecting data relocation. This closed
  `fn_12_34390`, `fn_12_346BC` and `fn_12_34798` with the original compiler.
  The repair archive retains all nine inputs, outputs and compiler settings.

## Root causes measured over the whole stuck corpus (2026-09-15)

`fzgx stuck --min-percent 50` over 1,962 saved bodies, counting mnemonics per side
without row alignment (`retail - ours` net rows):

- `lis` -2073 / `addi` +1622 (731 functions): the TU section base and shared literal
  pool (existing primer/layout families).
- `psq_st` +608, `psq_l` +579, `ps_madds0` +148, `ps_sub` +111: 164 unmatched
  functions (244 KB) use paired-single vector kernels. **MWCC's `__vec2x32float__`
  only emits the indexed `psq_lx`/`psq_stx`; the displacement form `psq_l f, 0x10(r29)`
  comes only from inline assembly inlined into the caller.** `include/psvec.h` holds
  the helpers (sub, add, scale, scale_add, sub_scale_add, set), each byte-exact on
  retail: fn_1_FB50 and fn_1_7EB8C match with one call. An inlined asm block's
  register parameters take f0, f1, f2 in declaration order, which is why `psvec_set`
  declares (dst, z, y, x): retail merges x from f2 with y from f1 and stores z from
  f0. Loads passed straight as arguments keep that order; loading into locals first
  changes it (fn_1_2A694). The lifter recognises the kernels (`psvec.kernels`) and the
  engine rewrites per-component statement triples (`paired_vector_kernels`).
- `fmuls` +615 / `fmadds` -525 / `fadds` +318 (251 functions): retail keeps products
  separate where ours fuse. Probe law (GC/1.3.2): `a + b*c` fuses; a product held in a
  named temporary or wrapped in an explicit `(f32)` cast does not (`t = b*c; a + t`
  and `a + (f32)(b*c)` give `fmuls; fadds`), and only the multiply that is a direct
  operand of the add/sub fuses: `(f32)(a*b) - c*d` gives `fmuls; fnmsubs`, `a*b - c*d`
  gives `fmuls(c*d); fmsubs`. `x*x + y*y + z*z` accumulated from the first product
  (`fmuls x; fmadds y; fmadds z`) is `(f32)(x*x) + y*y + z*z`; the plain expression
  materialises `y*y` first. Family: `fusion_control`.
- `cmpwi` +764 / `cmplwi` -443 (460 functions) and `lha` +93: our bodies are
  unsigned where retail is signed. With `-sym on` MWCC emits a DWARF 1 `.line` table
  and byte-identical code, so every differing row names its statement
  (`tools/fzgx/linemap.py`); `attributed_type_flips` flips the casts and declarations
  of that statement's operands toward retail's signedness, `attributed_inlines` folds a
  single-use local read there back into its use (fn_1_76704: the call evaluated
  inside the multiply fixes `mullw` operand order), and the engine tries candidates
  that edit implicated statements before the rest.
- Epilogue `lwz r31; lwz r0` against `lwz r0; lwz r31` (10 functions): the scheduler
  hoists the LR reload only when nothing ties it; same instruction stream, different
  DAG, not closable by flags (`-O3` disables scheduling entirely).
- No other retail-only opcode family above 40 functions exists; the rest of the
  residuals are register allocation, frame layout and control-flow shape.

## Whole-TU compiles: one declaration per symbol (librarian, 2026-10-04)

- The declared size of an object changes scheduling and loop strength reduction even when
  every access goes through a cast pointer: a view (`(T *)&sym`) over dtk's 4-byte
  `lbl_1_bss_384C0` unrolls fn_1_469BC (`lwz` displacements) where retail keeps `lwzu`; an
  `f32[5]`/0xD8-byte declaration reorders loads beyond its end (fn_1_E174, fn_1_12A080).
  Fix the one declaration (typedefs.json `decl`/`typedef` override, or the TU prologue)
  to the merged layout of every matched view; never a per-block view.
- Callers re-extend narrow return values (`u8` -> `clrlwi`, `s8` -> `extsb`), so a caller
  that sign-extends proves an `s8` truth in its TU (fn_1_86624 in live_camera/camera). A
  redundant `(s16)` cast on an `s16` call result changes allocation and can be required
  (fn_1_7B218); `(s8)x` on a `u8` global folds away, `*(s8 *)&x` keeps the `extsb.`.
- Passing a narrow local to a 32-bit parameter inserts `extsh`/`clrlwi`; retail callers of
  `fn_1_6B48(s32)` / `fn_1_8708(s32)` held the value in an `s32` local.
- `const` on an `extern f32` rodata scalar changes load scheduling (accessory 7B1C/7B20).
- A matched `void` wrapper whose caller consumes r3 (fn_1_D3884, fn_1_729F8) is declared
  returning a value in the caller's TU; a definition without `return` compiles identically.
- Duplicated per-block TU-layout definitions (`fzgx_obj_*`, `static fzgx_bss_layout`) and
  inline copies of a TU function must agree in type and differ in name per block before a
  TU compiles: unify the element type through a hoisted typedef (archive 897AC).
- Every `enum` declaration (named or anonymous) consumes one compiler `@N` label number, so
  adding enums to a header shifts the `@N` names of a unit's jump tables/literals and breaks
  its recorded `pool` mapping in units.json (TRKDispatchMessage `@20` -> `@22`). Typedefs and
  struct declarations do not. Keep enums out of headers included by pool-mapped units.
- A byte-field getter (`return obj->unk_4A;`, lbz) whose callers test or index r3 without
  `clrlwi` returns `s32`, not `u8`: the callee's code is identical, the caller's is not
  (fn_1_5910, fn_1_58C4, fn_1_D357C; bg_common fn_1_1067A8). A boolean `return a != b;`
  tested with `cmpwi` in callers is `s32`/`int`, not `u32` (fn_1_467F4, fn_1_8D690).
- `int` and `long` (`s32`) are distinct types to MWCC's redeclaration check even though the
  code is the same: a whole-TU compile fails on `extern int f(void);` after `extern s32 f(void);`.
- A block that reads a TU's first data symbol at offsets far past its dtk size (fn_3_5F28:
  `lbl_3_data_0` +0x1164/+0x11D0/+0x11D4 = `lbl_3_data_1134`+0x30/+0x9C and `lbl_3_data_11D4`;
  fn_3_368C up to +0x18C0, across strings) is MWCC's TU section base, not an under-sized object.
  Do not grow the header type (`Obj_3_data_0` stays 0xA8); a whole-TU compile needs the TU's own
  `.data`/`.bss` objects defined in retail order (fn_3_48E0 does this for `lbl_3_bss_0..243C0`).
- A lifter body that assigns a call's result and overwrites it at once (`t5 = fn_3_4218(); v3 = t5;
  v3 = ...;`) is no evidence of a return value: retail's `void` definition is the truth
  (fn_3_368C, fn_3_4BEC, toolkit fn_3_1A1D8 calling fn_3_141A8).
- An MWCC absolute object (`u32 __OSBusClock : 0x800000F8;`, `volatile PPCWGPipe GXWGFifo : 0xCC008000;`)
  emits no symbol or relocation and compiles to the same `lis/lwz` as a literal pointer read; MWCC
  accepts an identical redeclaration, so the shared ones in `dolphin/hw_regs.h` and `dolphin/gx.h`
  coexist with local copies (fn_800557CC, fn_80055EC0, fn_80022EA4; fn_80038DE8, fn_800377F8).
- OSFastCast (`include/dolphin/os/OSFastCast.h`): retail's `psq_st fN, off(r1), 1, qr2; lbz rX, off(r1)` per colour
  byte is the SDK's `__OSf32tou8`. Inline asm must take `0(ptr)` with `register f32 *ptr = &tmp;` (MWCC folds it into
  the r1 displacement); `tmp` alone as the operand is rejected. The temporary is `f32` for every width, read back as
  `*(u8 *)ptr`: each site owns a 4-byte slot (fn_1_65748's three sites at 0x10/0xc/0x8); a `u8` temp packs 1-byte slots. Needed by fn_1_60D54 and fn_1_A5594 (probe, 1.3.2).
- TU .bss base views (librarian, 2026-10-13): when retail addresses a whole TU's .bss off its first symbol
  (`lbl_1_bss_3C00` to +0x34600, `lbl_1_bss_7B180` to +0x3BDC), the header declares that symbol as a struct view sized
  from every base-relative access (typedefs.json `decl` override) instead of dtk's 1- to 8-byte object; casts of an
  under-sized declared object let MWCC treat distinct offsets as one location (fn_1_304A8, fn_1_3E6D8, fn_1_EF768).
  Superseded for `lbl_1_bss_3C00` (librarian pass 15, 2026-10-20): the 0x34604-byte view made every block that
  defines the TU's objects in retail order (fn_1_31C3C, fn_1_3DB9C, fn_1_3EB78) a redeclaration under the prologue,
  and no block used its fields. The header now declares the real byte object; blocks define the section layout
  (`fixup_layout.tu_section_layout`) instead of casting the base. In retail every `off(rBase)` load/store is the
  start of its own object (`sth 0x14e8(r31)` in fn_1_2C908 is an object at 0x50E8 inside dtk's 0x14BC `lbl_1_bss_3C30`).
- Retail's `li rA, 0; mr rB, rA` for two counters starting equal comes from an inline helper whose parameter seeds both
  (`static inline void h(s16 init) { dir = init; delta = dir; ... }` called as `h(0)`); decrementing (`delta--`) before
  the matching increment keeps retail's schedule (fn_3_3F20, note #252).
- Caller-proven narrow return (librarian, 2026-10-14): a callee that only returns small constants (`li r3, N`) compiles
  identically as `int` or `u8`; its caller decides (a `u8` result kept in a callee-saved register is `clrlwi r31, r3, 24`,
  an `int` one is `clrlwi r0` plus `mr`), so the truth is the caller's type (fn_10_26434 for fn_10_26000).

## Optimizer rules read from the public mwcceppc source (rayanht/mwcc, 2026-10-26)

Citations are to the CC0 matching decompilation (`FZGX_MWCC_SRC`, never copied here); each
rule was probed with real GC/1.3.2 compiles of saved bodies.

- **IR copy propagation moves only numbers and local copies.** `IRO_CopyAndConstantPropagation`
  (optimizer/IroPropagate.c) takes a candidate only through `fn_004592e0`: the right side is an
  int/float/vector constant (`fn_0044d520`, optimizer/IroDump.c) or a non-volatile register local.
  `&global`, `p + off` and every address are *not* copy-propagated; it also skips any use whose
  block has a greater loop depth than the definition's (`block->loopdepth > node->block->loopdepth`;
  depths exist only after `IRO_FindLoops`, so the first pass-0 propagation ignores loops).
- **Expression propagation is block-local and single-use.** `IroPropagate_PropagateExpressions`
  substitutes `v = expr` into a later use only inside the same IR node, only when `v` has one use
  there (`uses == 1`) and the assignment's value is not itself used (`IROLF_Reffed`, a chained
  `a = (v = expr)`). Under -O4 it runs again in pass 1 (`IRO_Optimizer`, optimizer/IrOptimizer.c),
  so a second use that dead-store removal deletes in pass 0 does not keep it from folding.
- **Backend add propagation never fires.** `COpt_AddPropagation` (optimizer/AddPropagation.c) tests
  `flags & fRecordBit | 0x400`, which is always non-zero, so `canPropagate` is always 0. Folding of
  `addi rA, rB, c1` into a later `addi rX, rA, c2` comes from the IR or from the peephole
  (`combine_addi`, `fold_addi_or_mr_reaching_def`, backend/Peephole.c: folds when the first result is
  the same register or dead, and nothing in between uses it or redefines its base).
  fn_1_ED540 (retail `addi r20, r31, 0x19c8 ... addi r20, r20, 0x620`): twelve spellings (hoisted
  temp, in-loop use with `opt_loop_invariants` on and off, `v += 0x620` in the preheader, `for`
  initializer, chained assignment, peephole off) all compile to one `addi r20, r31, 0x1fe8`; the
  fold survives `#pragma peephole off`, so it happens before the peephole. Only an `if` between the
  two statements (a separate IR node) kept both adds, at the cost of a real branch. Unsolved: the
  retail shape needs an IR node boundary that disappears before code generation.
- **IR unroll trip guards fold only by IR constant propagation.** `unroll_loop` (optimizer/IroLoop.c)
  computes the trip count into a temporary (`create_loop_iteration_count`) and emits
  `if (count <= factor) goto remainder` (`create_source_constant_branch`). Only
  `IRO_CopyAndConstantPropagation` turns the temporary into a constant for
  `IRO_EvaluateConditionals`; the backend's `ConstantPropagation.c` folds `addi`/`add` but not compares.
  A caller compiled under `#pragma opt_propagation off` therefore keeps `li r0, N; cmpwi r0, F; ble`
  before the `mtctr` of a constant-bound loop that retail enters directly (fn_12_21C8: N=0xdc, F=8;
  inlined helpers inherit the caller's setting, so a pragma around the inline definition does not help).
  Turning propagation on removes the guard but folds the inlined `li r3, 0; cmpwi r3, 1` result tests
  (96.0% -> 88.6%): retail had propagation on, and those results had more than one reaching definition.
- **An unroller entry guard that survives is a `long` counter.** The opposite case: retail keeps the
  copied loop test `li r5, 0; cmpwi r5, 0xfee; bge` before an 8x-unrolled loop whose count is already
  folded (`li r0, 0x1fd; mtctr`, no `cmpwi r0, 8`). The count comes from the init's constant
  (`create_loop_iteration_count` reads `init->right`), the guard reads the counter, and propagation
  takes `V = 0` only when the assignment's type is the variable's own type object
  (`fn_004592e0`, IroPropagate.c): an `int` literal assigned to a `long` (`s32`) counter is not
  a candidate. Declaring the counter `long` closed all three LZ window clears (fn_18_444, fn_1_1304C,
  fn_1_1289C, round 69; `0L` does not). Family `longctr` (`fixup_source.long_loop_counters`).
- **Known-count backend unrolling needs a divisor.** `unroll_counting_loop` and `unroll_loop_by_factor`
  (optimizer/LoopOptimization.c) lower the factor from `unroll_factor_limit` until it divides the trip
  count; a remainder loop after `li rN, count/8; mtctr` is therefore the IR unroller's output, not the
  backend's.
- **A constant address hoisted out of a loop is a compiler object; hold it in a carrier under
  `opt_propagation off`.** The locked-cache base `0xE0000000` used inside a loop is hoisted into a
  temporary numbered above every declared local, so it claims its callee-saved register before
  the pool base and a magic divisor that retail ranks above it (fn_1_71D0C: retail LC r26, pool
  r27, 0x55555556 r28; ours LC r28). A plain or one-member-struct local assigned the constant is
  propagated back into that temporary; `struct { u32 value; } fzgx_lc; fzgx_lc.value = LC_BASE;`
  assigned right before the loop under a function-scoped `#pragma opt_propagation off` matched
  (assigned at the first statement it did not; the declaration position made no difference).
  `fixup_source.constant_address_locals` (sweep family `constaddr`) emits it, redefining `LC_BASE`
  over the function and passing the base as a trailing parameter to static inline helpers only
  this function calls (round 68: 1 of 45 LC near misses closed).

- Librarian pass 16 (2026-10-27). A scalar FPR stored six times with displacement `psq_st v, 0..0x28(d), 0, qr0`
  and then reused as `ps_mr fN, v` is `psvec_fill4(d, v)` from `include/psvec_fill.h` (fn_1_4EDAC 96.97 -> 99.49%;
  four `psvec_set` calls give merges and stfs instead). Adding any inline function to an already-included header
  (psvec.h) renumbers MWCC's anonymous `@N` literals in every includer and breaks matched units' `pool` maps
  (9 live_camera/stcoli pool units failed): put new kernels in a new header.
- The SDK fast casts read the temporary inside the asm block for signed widths (`lbz; extsb`, `lha`): a C read
  `*(s8 *)ptr` lets MWCC drop the `extsb` before a `stb` (fn_1_A47F4 0x310/0x334; `include/dolphin/os/OSFastCast.h`).
- Folded hardware-register addresses (`lis rX, 0xCC00; stw rY, 0x6828(rX)`) come from `HW_REG32_LITERAL(off)`
  (`include/dolphin/hw_regs.h`, base `FZGX_ADDR___CPRegs`); `extern vu32 __EXIRegs[]` adds an `addi @l`.
- **Constant copies (`li rA, K; mr rB, rA`) come from value numbering of compiler temporaries** (tooling round,
  2026-10-27). The second `ValueNumbering_PerformValueNumbering(1)` (optimizer/GlobalOptimizer.c, after constant
  propagation) numbers a `li`/`lis` only when its destination lies in the coalesce window (optimizer/ValueNumbering.c,
  `PC_LI` case, `gGPRCoalesceFirst..Last`); any other `li` just invalidates. The window opens after the declared
  locals and parameters get their registers (backend/CodeGen.c `allocate_object_registers`, then
  `Registers_BeginCoalesceWindow`): it holds `@`-named objects, i.e. the locals and parameters of inlined functions,
  IR temporaries and lowering temps. So two *inlined-helper locals* set to one constant become `li; mr` (the copy
  stays when both are modified later), while declared locals of the function never do: every caller spelling
  (`b = a`, `b = a = 0`, casts, declaration orders, `opt_propagation off`) gives two `li`. Probes (GC/1.3.2):
  `static inline void lp(void) { unsigned i; for (i = 0; i < 3; i++) { int y = i * 2; ... } }` gives fn_4_A0C's
  `li r31, 0; mr r30, r31` for the strength-reduced counter; the same loop in the caller gives two `li`; locals
  `present = 0; mask = present;` in a helper give fn_1_C24A4's `li r4, 0; mr r5, r4; ori r0, r4, 1`. Inlined locals
  number in the opposite order to declared locals: the reversed declaration order is the first one to try. A
  whole-body helper does not work for large functions: MWCC's default `inline_max_size` leaves it out of line
  (`#pragma inline_max_size(4096)` before the caller inlines it, but renumbers the whole function's locals), so the helper should
  span only the region of the pair. `fixup_source.region_inline_helpers` (family `inlineregion`, `decl` moves on
  `NAME_fzgx_region`) builds it: fn_1_C24A4 4 rows -> 1 (word score 99.47 -> 99.89), fn_4_A0C 95.8% -> 97.5%
  (97.85%, two scheduling rows, when `row` is a helper local too). Not this mechanism: a constant *argument*
  shared with stores (fn_1_36330's `li r3, -1` for four stores and the call): IR constant propagation folds an
  inlined parameter's constant into every use, so moving the call into the helper changes nothing; the argument
  `li r3` targets a physical register, outside the window. fn_8006AA44's `li r6, 0x40` kept past the next `li` is
  scheduling, not a copy.

## Simplify-scan degree: capture verdicts (GC/1.3.2 replay, 2026-10-28)

A WSL capture (`tools/capture/capture132.sh`) runs in ~11 s and the replay reproduces it exactly
(fn_1_DF6AC: FPR 140/140 simplify rows and 174/174 colors, GPR 74/74; fn_1_82C70: 134/134).
`simplify_replay.py DIR IDX V:+N` / `V:-N` / `V=W` answers which degree or number a residual needs.

- **A node's degree at its own scan-1 turn counts every higher-numbered neighbour not yet pushed.**
  Simplify scans vregs in ascending order. A long-lived lowering temp numbered before the short
  temps inside its own range is visited while those temps are still in the graph, misses K, and
  is pushed in scan 2 after every long-lived pass-1 object: popped first, it claims the highest
  callee-saved register. fn_1_DF6AC: sinA1 (v134, the `FMR` of the first sqrt result) has degree
  33 at its turn (14 call-clobbered FPRs, 11 un-pushed long webs, 8 higher temps: normalize's
  `0.0f` load v135, `dot`'s six loads v137-v142 and its `0.0f` v143), K=32, so it gets f31; retail
  gives it f20. Two fewer at its turn (`134:-2` to `134:-25`) or any two of those later temps
  numbered below it (`135=133 143=132`, `137=133 138=132`, or sinA1 renumbered to v137-v143)
  reproduces all 15 FPR targets. Not levers (capture-verified, numbering unchanged): the struct
  wrapper vs a plain local for sinA (both are the call-result temp), a `zero` local or an inline
  parameter carrying the `0.0f` (constants are not register objects; each `lfs` is a fresh
  temp). Holding `dot`'s loads in locals restructures the schedule (44.8%). Open: a spelling that
  creates the sqrt-result web after `dot`'s loads, or two of those loads before it.
- **A degree one below K decides the order between two parameters.** fn_1_82C70:
  `port = ok = f()` put the u8 truncation into port's web (`clrlwi. r26`). Retail's
  `clrlwi. r0, r3, 24; mr r26, r3; stb r26` is `ok = f(); if ((u8)ok) ...; G = ok;` (fixes that
  row), but then port is no longer live at the end: degree 28 < K=29, pushed in scan 1, colored
  after arg0 (r25/r26 swap) and the result takes r27 instead of sharing r26. `33:+1` to `33:+11`
  reproduces all three targets: port needs at least one more interference that is not the result.
  Declaring port `int`/`u32` and reassigning it does not help: MWCC renames the reassigned
  parameter (the result stays a separate temp, numbering and degree unchanged).
  fn_1_82C70 compiles identically under GC/1.3 and GC/1.3.2, so the 1.3.2 capture applies.
- **Section base outranks a declared local** (tooling round, 2026-10-28, GC/1.3.2 captures of
  fn_10_13B24 and fn_17_8B44). A literal-pool or TU section base (`lis; addi rB, sym@l`, and the
  `addis rH, rB, 6` high half over it) is a lowering temporary: it is numbered after every
  parameter, declared local and @N shadow (fn_10_13B24: params v32-34, locals v35-38, shadows
  v39-40, pool base v43; fn_17_8B44: `data` v38, pool base v41 in the window). When it and a
  long-lived local are pushed in the same simplify scan (all five callee-saved webs of
  fn_10_13B24 drop below K together in scan 2; both of fn_17_8B44's are below K in scan 1), the
  higher number is coloured first and claims r31. Retail's order (x r31 above pool r30, data r31
  above pool r30) replays exactly with the two numbers exchanged (`simplify_replay.py DIR IDX 43=38`);
  a degree change does not reproduce it (x needs +16 interferences surviving scan 1). No spelling
  tried renumbers either web: declaration and definition order; the pool held in a plain or
  one-member-struct pointer local at any position, with and without `opt_propagation off` (the
  local's web stays empty and the address temp survives); `x` removed (it becomes shadow @316,
  still below the base); `x = arg1; x *= 150` (folded to the same shadow); `x` as an inline
  helper parameter (an @N object); native literals with the module's pool primer; the TU's
  `.data` and `.bss` defined in the unit (424C's layout transplanted into 8B44: the base stays
  a temporary, `data` stays a local; without the local the high half is no longer hoisted to the
  entry); GC/1.1-2.6. Two section bases order among themselves by creation (fn_17_424C's
  layout family); a declared local cannot be numbered above one. The capture verdict
  (`fixup_capture`) now names the class (`base`) instead of the misleading "expression order",
  runs from 98.0% (these swaps are 98.3-98.9% on long functions), and treats a symbol pair the
  oracle already bound (`lbl_10_rodata_158` against `...rodata.0`) as a renaming. Open: a source
  form in which `x` is a window web (a rename region) without an extra `mr`.

## Capture verdicts in batch (tooling round T1, 2026-10-28)

`fzgx fixup --verdicts SYM ...` (`tools/fzgx/fixup_verdicts.py`) captures each saved best body
(seedrank) under GC/1.3.2 (a GC/1.3 body only when 1.3.2 gives the same rows), maps every
register-renamed row to its web (agreeing rows pin the other webs), and searches the replay's
override space (`a=b` exchange, `va->vb` move, `v:+N` degree; a 6-wide beam up to three steps,
~1 ms per replay) for the smallest change giving every mapped web retail's register. One row per
function goes to `.fzgx/capture/verdicts.json`; `fzgx fixup` runs the class's families first.

- **Classes** (22 stalled near-misses): web-split 6, unresolved 6 (best partial override
  recorded), base-temp 3, copy-coalesce 3, inline-region 2, expression-order 2.
  *web-split*: retail gives one of our webs two registers (fn_1_82C70's `port`: `clrlwi. r0`
  then `mr r26`), so the value lives in two variables in retail. *copy-coalesce*: our temp is
  copied into a web that retail defines directly (fn_10_111E8's `row`: `addi r0; mr r23, r0`
  against `addi r23`). Neither can be reached by renumbering; they are reported, not searched.
- **A declared local numbered above window webs is the value written without the local.**
  fn_16_2560: `y = 24 - a` (a pass-1 local) needed to be numbered above the window's `a`/`b`
  copies (`v36->v39`); substituting the expression into its three uses
  (`fixup_source.forwarded_locals`) makes it a window CSE web and closed 12 of 13 rows. The last
  row was a function-local `static const u32 color_data[1]` duplicating the primer's raw
  `fzgx_pool_table1` word: retail reads it at pool offset 0, so the table itself is the local's
  object (rename the primer table, drop the local) -> pool match, landed. The same substitution
  on fn_1_10B800's `lb = obj->s->q->p` reloads it every loop trip (63 rows): only side-effect-free
  values whose operands do not change across calls survive it.
- `fixup_source.definition_moves` (the `degree` lever: moving a local's only assignment past
  neighbouring statements) did not reproduce fn_1_10B800's `43:+16`; that needs 16 more
  interferences, i.e. a range spanning the loop setup, not a one-statement move.

## Findings from karamzov123/fzero-gx-decomp (CC0), 2026-10-29

Reported by the karamzov123 fork (same tooling base) and restated here. Items marked
*measured here* were re-probed on this tree; the rest are their observations.

1. **Barriers that cost no code.** A self-assignment `v = v;` placed after `v = expr;` emits
   nothing (*measured here*: identical instruction count on GC/1.3.2) but stops MWCC from
   folding a single-use value into its use, so `v` stays a declared-local web and is coloured
   after the optimizer's `@` temporaries (their fn_1_CDC8C). At the top of a `static inline`
   helper, `param = param;` prevents the inliner from substituting the caller's argument
   expression for the parameter; the operands are then lowered in a different order
   (fn_4_28FC). Appending `, v = v` to a `for` step hides one loop-invariant from constant
   propagation without turning `opt_propagation` off for the whole function (fn_1_22F90).
   Engine families: `self_assignment_barriers`, `inline_parameter_barriers`.
2. **Qualify read-only tables `const`.** Loads from a plain `extern u16 tbl[]` are assumed to
   alias any earlier byte/half/word store, so the scheduler keeps them below those stores.
   Declared `extern const`, they move above, giving retail's load-before-store order
   (fn_8006953C). Engine family: `const_extern_tables`.
3. **Sum association is part of the code.** MWCC keeps the source tree of an integer or
   pointer sum, so the `add` operand order and the address CSEs pin a single bracketing.
   Compile every binary tree of the terms in one batch and word-compare: six terms give
   720 orders x 42 bracketings = 30,240 trees, a few seconds. Engine family: `add_trees`
   (all orders and bracketings up to four terms; bracketings plus left-associated orders
   for five and six).
4. **Byte swap that must not become `stwbrx`.** GC/1.3.2 recognises a full 32-bit swap
   feeding a store and emits `stwbrx`. Retail's `rlwinm`/`rlwimi` chain comes from a swap
   whose low half is narrowed first:
   `u32 low = (u16)v; return (low << 24) | ((low << 8) & 0xFF0000) | ((v >> 8) & 0xFF00) | (v >> 24);`
5. **Small spellings.** `u32 mask = 0x80000000 >> n; w &= ~mask;` computes the address before
   the shift. Prefer `base + 0x28 + n * 2` to the lifter's `src = base + 0x28 + i; i += 2`.
   `inv = 1 - t; inv *= inv;` squares in place and keeps one float register.
6. **Scan for clones before repairing.** option, title and sel share menu code; an
   opcode-sequence comparison of unmatched against matched functions found nine matches in
   a day. Porting the matched sibling's C beat repairing the unmatched body.
7. **`#pragma section code_type` is sticky.** `#pragma section code_type ".fzgxpool"` stays in
   force until `code_type ".text"` (*measured here*, GC/1.1, 1.2.5n, 1.3.2: every later
   function lands in `.fzgxpool`). A `#pragma pop` that closes an enclosing `#pragma push`
   does restore the previous section, so the five title blocks using push/pop (fn_8_7EFC,
   fn_8_8440, fn_8_89B8, fn_8_DD64, fn_8_6C90) compile their function into `.text` and are
   verified C links. `fzgx lint` rule P1 now flags a region left open at the end of a block
   or file; the two open regions in `src/` (fn_3_6270, fn_1_155FB4) are pool blocks whose
   function compiles into `.fzgxpool`.
8. **8-byte alignment of BSS/data objects.** They saw a `u8[0xA]` pad move by 4 and shift
   every later object, fixed by separate `s16`s. *Not reproduced here at object level*: under
   this project's flags (GC/1.2.5n and 1.3.2, `-align powerpc`) plain `u8[8]`, `u8[0xA]`,
   `u8[0x10]` and an 8-byte struct of words all take 4-byte alignment in `.bss` and `.data`;
   only a `double` member takes 8. Check the member types before assuming a size rule.
9. **Section base names.** When the only differences are `...data.0` against
   `lbl_M_data_X`, the oracle binds the base to a `fzgx_obj_lbl_M_data_X` that starts at the
   same address and is no larger than the retail symbol.
10. **Dead ends they measured.** A different `-O` level never matched (269 functions). A
    deterministic sweep over the 99%+ band produced 0 matches in 40,208 candidates. Raising
    plateau limits spends tokens without adding matches. About 12% of rows classed as register
    allocation were relocation-only. A search can "match" by inventing a return value, so
    diff what the search changed before accepting it.
11. **Refinements.** Inline-helper locals declared in reverse order gave
    `li r28, 0; mr r29, r28`. Where `vert` is known to be 0, `vert--` reproduces retail
    and `vert = -1` does not. Read operand order off retail: `add rD, rX, rAcc` is
    `x + acc`. Before choosing a return type, look at the epilogue: a function that never
    sets r3 is `void`. Lint A1 misfires on float bit patterns and on hex or "volatile"
    inside comments; `fzgx-allow` must be on the flagged line itself.
12. **LLDB capture on Linux (their 41713f6, 2026-10-29).** `mwgraph.capture` runs on Linux with
    a bare `lldb` that embeds Python and the unstripped Wibo 1.0.0 release at `build/tools/wibo`
    (the loader breakpoint is `loadPEFromSource`); 0.51 s/function, exact replay on six bodies.
    Ported: the `xcrun lldb` -> `lldb` launcher fallback with a named error, and the retail
    target resolved through `Project.target_object_for` when a corpus record has no `target`.
    Skipped: their lldb environment scrub (it pins `PYTHONHOME=/usr` for one host's Python 3.14;
    Windows captures here go through gdb in WSL, `tools/capture/capture132.sh`). Their verdicts,
    real-allocator measurements: fn_12_3A64 (movie_module, theirs) is `fixed-graph-hypothesis`,
    retail's colouring is a three-cycle (`table` r29->r28, `object` r28->r27, `far_z` r27->r29)
    reachable by selection order but with zero declaration projections (853 projected candidates,
    0 matches): a parameter or `@` web holds the rank. fn_12_7870, fn_80059DD8, fn_80022BF4,
    fn_800720B0 and fn_80072168 are `needs-web-alignment` (the interference graph differs from
    retail's): no declaration order or tie re-sweep can close them, only a source change in the
    value webs. This agrees with the T1 verdicts above (no class closed by order alone).
