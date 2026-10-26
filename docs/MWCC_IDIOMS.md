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
- **Known-count backend unrolling needs a divisor.** `unroll_counting_loop` and `unroll_loop_by_factor`
  (optimizer/LoopOptimization.c) lower the factor from `unroll_factor_limit` until it divides the trip
  count; a remainder loop after `li rN, count/8; mtctr` is therefore the IR unroller's output, not the
  backend's.
