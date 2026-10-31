# tutruth pool remap never writes an empty or unverified map (T7, 2026-10-31)

Class: librarian pass 18 (3549704d4) emptied the `pool` map of main_rel fn_1_128F10 in
units.json; the unit lost its BSS definition bindings and the link failed with multiply
defined symbols. `tutruth.resolve` re-checks every pool-mapped unit after rewriting blocks and
wrote `res.pool_map` whenever the result was `matched or matched_pool` and differed.

Reproduced: `oracle.check(p, 'main_rel:fn_1_128F10', 20, source=<gen unit>)` returns
`matched_pool=True, pool_map={}` (96.18%, 7 pool rows): `poolfix.apply` cannot report every
private section emptied for a unit that keeps its own BSS definitions (identity bindings
`lbl_1_bss_89780 -> lbl_1_bss_89780`), so `_check` returns the first result without a map.
The old condition then wrote `{}`.

Fix: the map is replaced only by a non-empty re-derived map under which the block matches
outright (`res.matched and res.pool_map`); otherwise the existing map stays, and a block that
no longer matches at all is reported under `pool_unverified`.

Why D: it decides the `pool` map in units.json, i.e. how a unit is linked.

Gate (with this patch and c7caf492a's tutruth change in the tree): lint 0 findings; build ok;
hashes 16/16; pool_sample 24 passed; recent 24 passed; named 1 passed (main_rel:fn_1_128F10);
GATE: PASS.

Measured gain: fn_1_128F10 under the new condition keeps its 7-entry map (old: `{}`); no
other behaviour change (tutruth is not run by the gate; the next librarian tutruth run is the
real exercise).

Apply: `git apply state/pending_tooling/20261031-tutruth-pool-remap.patch`, then `uv run tools/fzgx.py gate`.
