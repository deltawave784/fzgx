# Pending tooling patches (category D: they change what the oracle accepts)

A tooling round saves such a change here instead of committing it. Apply with `git apply state/pending_tooling/<name>.patch`, then `uv run tools/fzgx.py gate`, then commit.

- `20261007-revise-restore-prologue-guard` (APPLIED 2026-10-07, user-approved): install keeps an accepted block `noprologue` unless the
  prologue compile has identical code, relocations and private literals; a revise that fails the
  link is restored to its previous verified block/unit instead of uncarved. See the `.md`.
