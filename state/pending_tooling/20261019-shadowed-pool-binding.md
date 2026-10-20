# Pending D patch: bind a same-named private `@` pool copy to retail's global pool object

Round 47 (2026-10-19). Class: saved bodies at 100% in the object oracle that `fzgx verify`
rejects at link (link-mismatch). Blocked by this part of the class: `__pformatter` (main,
1908 B; `.fzgx/attempts/__pformatter.linkfail.1792456522.c`).

## Cause

The body's `wide_str = (const unsigned short *)L"";` makes MWCC emit the wide-string pool
`@wstringBase0` as a *local* 2-byte object in our `.sdata`. Retail's `__pformatter` addresses
the TU's wide-string pool, which `symbols.txt` names `@wstringBase0` too (`.sdata:0x801A6630`,
scope global). objdiff compares the relocation by name, so the row is `DIFF_NONE` and
`oracle._pool_rows` never looks at it (it only scans differing rows); no `pool_map` entry is
recorded, so `poolfix.apply` leaves our copy in place and the DOL link resolves our `sda21`
relocation to the private copy (placed elsewhere, and `.sdata` grows by 2 bytes): every hash
after it fails. The committed round-47 change (`oracle.link_conflicts`) now reports this as
`private copy at link: local `@wstringBase0` ... shadows retail's global .sdata object` and
`submit` refuses the body instead of letting verify relink and bisect; it cannot land it.

## What the patch changes (why D)

`oracle._pool_rows` gains one rule for rows that already agree: when both relocations name
the same `@`-prefixed symbol, our object defines it as a local object of a pool section
(.rodata/.sdata2/.data/.sdata) with retail's size and retail's bytes (`Project.bytes_at`), and
retail's symbol is a global object of a pool section, the row is a pool row and the pair
`(@wstringBase0, @wstringBase0)` enters `pool_map`; `poolfix.retarget` already turns an
identity mapping into an undefined global reference and drops the private copy. A new
`_shadowed_pool_names` makes `_diff` run the pool-row scan for a 100% result when the object
has such a local (otherwise the scan is skipped at 100%). This changes what the oracle accepts
(a new pool binding) and how the unit's object is linked, hence D. Bytes are proven equal
before binding; nothing in the object is patched except the symbol binding.

## Measured gain (with the patch applied, C-state tree otherwise)

- `__pformatter` (long2str respelled by the committed repair): `oracle.check` matched=True,
  `pool_map {'@wstringBase0': '@wstringBase0', '@stringBase0': '@stringBase0_80094FC0'}`,
  `link_conflicts []`, `poolfix.link_hazards []`. Without the patch: matched=True but
  `link_conflicts` = the private-copy line above, and submit refuses it.
- Census of the committed detector over all 6177 matched function units: 0 exact-linked units
  carry a shadowed `@` copy (the 111 hits are all `link_state=pool`, which link retail's
  object), so the new rule can only ever fire on new submissions.

## Gate output

The gate was run on the committed C-state tree (7f1f3e28), not with this patch applied
(round time ran out): `lint: 0 finding(s); build ok: True; hashes OK: 16/16; pool_sample: 24
passed, 0 failed; recent: 24 passed, 0 failed; named: 7 passed, 0 failed; GATE: PASS`.
The patch applies cleanly on 7f1f3e28 (`git apply --check`). Run the gate with it applied
(`--also __pformatter` after landing, plus a pool sample) before keeping it.

## How to apply

    git apply state/pending_tooling/20261019-shadowed-pool-binding.patch
    uv run tools/fzgx.py gate --also __pformatter

then land `__pformatter` from `.fzgx/attempts/__pformatter.linkfail.1792456522.c` through
claim/write-unit/submit (the check-time repair respells `long2str_80082040`) and `fzgx verify`.
