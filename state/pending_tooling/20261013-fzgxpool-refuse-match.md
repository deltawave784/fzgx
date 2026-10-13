# Pending (category D): refuse a match whose function is emitted in `.fzgxpool`

Tooling round 31, item 4 (2026-10-13).

## Class

A body whose pool/layout primer sets `#pragma section code_type ".fzgxpool"` and never resets it
emits the target function itself in `.fzgxpool`. `poolfix.apply` drops that section at
integration, so the function disappears from the link. fn_12_3710's recorded best (99.07%) was
such a body; with `#pragma section code_type ".text"` before the function it scores 95.21.

Committed already (category C, 95191d8d): a NON-matching result of this shape is scored 0 with a
diff line naming the fix, and `oracle.words` ignores `.fzgxpool` code.

## Why this part is D

The patch also clears `matched` and `matched_pool` for such a result, which changes what the
oracle accepts. Measured on HEAD: fn_4_2394's 100% body with the function moved into `.fzgxpool`
reports `matched=False, matched_pool=True` (percent 0 after the C change) — `api.submit` accepts
pool matches, so it would be carved and spliced, then fail `fzgx verify`'s hashes one drain later.
With the patch: `matched=False, matched_pool=False`.

## Gate (patch applied)

```
lint: 0 finding(s); build ok: True; hashes OK: 16/16
pool_sample: 24 passed, 0 failed, 0 skipped
recent: 24 passed, 0 failed, 0 skipped
GATE: PASS
```

## Measured gain

- fn_4_2394 body in `.fzgxpool`: HEAD matched_pool=True (would be submitted) -> refused.
- fn_4_2394 respelled 100% body in `.text`: 100% matched before and after (unchanged).
- fn_12_3710 saved bodies: 0.0 / not matched before and after (the C change already scores them).
- One saved body in `.fzgx/attempts` has the shape today (fn_12_3710); none matched.

## How to apply

```
git apply state/pending_tooling/20261013-fzgxpool-refuse-match.patch
uv run tools/fzgx.py gate
```
