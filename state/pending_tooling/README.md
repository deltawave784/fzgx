# Pending tooling patches (category D: they change what the oracle accepts)

A tooling round saves such a change here instead of committing it. Apply with `git apply state/pending_tooling/<name>.patch`, then `uv run tools/fzgx.py gate`, then commit.

- `20261007-revise-restore-prologue-guard` (APPLIED 2026-10-07, user-approved): install keeps an accepted block `noprologue` unless the
  prologue compile has identical code, relocations and private literals; a revise that fails the
  link is restored to its previous verified block/unit instead of uncarved. See the `.md`.
- `20261019-shadowed-pool-binding` (APPLIED 2026-10-21, user-approved): binds same-named private `@` pool copies
  (e.g. `@wstringBase0`) in `_pool_rows` and scans 100% objects carrying one; unblocks __pformatter. See the `.md`.
- `20261020-pool-relocation-equality` (APPLIED 2026-10-21, user-approved): pools carrying pointer relocations bind when
  every relocated word's (type, module, section, resolved address) agrees with retail and plain bytes agree elsewhere.
  Gate PASS with `--also main:fn_8004EC34`. See the `.md`.
