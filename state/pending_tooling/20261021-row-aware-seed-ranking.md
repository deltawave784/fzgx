# Pending D patch: row-aware selection of saved bodies and seeds

Round 55 (2026-10-21). Class: the attempt's saved best body (`api._record_check` / `KEY.best.json`),
claim seeding (`Ledger.ranked_local_attempt` -> `seedrank.pick`) and the recovered-seed manifest
(`tools/seeds/recovered.py`) rank saved bodies by the attempt's progress scale alone
(`oracle.progress_score` = the better of objdiff's similarity and the pool-adjusted row score, less
seedrank's dropped-row penalty where seedrank runs). objdiff gives partial credit to register-only
rows but counts a correctly bound literal pool or section base as a mismatch, so a body with far
fewer differing rows and the pool bound loses to a body with more rows and a higher raw similarity.
Blocked per the round brief: fn_10_111E8 (sel), fn_3_C400 (customize), fn_4_28FC (option),
fn_1_2F294 (main_rel).

## What the patch changes (why D)

Selection only, never acceptance: the oracle and the 16 hashes still decide what matches. It is
treated as D because it changes which body every future attempt starts from (round 51's note).

- `tools/fzgx/seedrank.py`: `row_score(res)` (100 x the share of aligned rows that agree after the
  oracle's accepted pool/section/absolute relocation rows: `oracle.progress_rows`; equals
  `percent_adjusted` when accepted rows exist and the same formula otherwise, so bodies with and
  without a bound pool sit on one scale), `selection_score(raw, row_score, dropped, implicit)` =
  mean of objdiff's similarity and the row score, less the existing dropped-row and
  undeclared-callee penalties, and `selection_of(res)`. `measure` freezes `raw`, `rows`, `row_score`
  (cache key `v5`, old `v4` entries are simply re-measured once); `pick` maximises
  `selection_score`, ties to the higher raw score, then the recorded order.
- `tools/fzgx/api.py` `_record_check`: the saved best body is replaced when the new body's
  `selection_score` beats the saved one's (`selection` in `KEY.best.json`, falling back to
  `percent` for files written before the patch); `IMPLICIT_MARGIN` applies as before. The ledger's
  `best_in_attempt`, `check_score`, the plateau counter and every stop condition are untouched
  (`percent` is still written beside `selection`, `raw`, `rows`, `row_score`).
- `tools/seeds/recovered.py`: `_ranked(record)` uses `selection_score` over the frozen `raw` /
  `row_score` / `dropped_rows` (`_measured(result)` records them in `prepare` and `refine`);
  `current_percent` keeps its meaning (the progress scale) for the threshold tests.

## Measurements (full saved corpus, 2026-10-21)

Every saved body of every function with two or more saved bodies was re-checked through
`oracle.check_many` (1,143 functions, 4,109 bodies; 955 functions with >=2 distinct compiling bodies).
Rules compared: current (`max(raw, adj)` - penalties), `mean` (this patch, 0.5/0.5), `mean75`
(0.75 raw), `mean25`, `rows` (row score primary), `marginN` (current, but within N points prefer
fewer rows).

- Choices changed vs current: mean 60 / 955, mean75 40, mean25 79, rows 91, margin1 33, margin2 54,
  margin3 70. Every changed choice moves to a body with fewer differing rows and a higher adjusted
  score (e.g. fn_12_72F4 99.1%/7 rows -> 95.3%/2 rows, fn_1_FDEC8 98.9%/13 -> 98.3%/2,
  fn_12_3A69C 99.7%/3 -> 99.0%/1, fn_80025EF4 96.9%/340 -> 95.4%/292, fn_1_5D91C 97.4%/94 -> 95.4%/71).
- The four cases (oracle today):
  - fn_10_111E8: seed 88.56% raw / 46.8 adj / 208 rows / 1 dropped store vs the primed rewrite
    85.47% / 72.46 adj / 111 rows / pool bound (25 rows). `_record_check` old rule kept the seed
    (88.56 > 85.47); new rule saves the rewrite (selection 78.96 vs 62.68). `ranked_local_attempt`
    already picks the rewrite at HEAD because seedrank's dropped-row penalty demotes the seed;
    the loss was only in the per-attempt best.
  - fn_3_C400: 99.08% / 25 rows vs the final 98.92% / 98.53 adj / 10 rows. Old rule keeps the
    25-row body in both `_record_check` and `ranked_local_attempt` (HEAD seeds from
    fn_3_C400.1792465002.c); new rule picks the 10-row final in both (selection 98.72 vs 97.70).
  - fn_4_28FC: the 84.9%/241-row seed vs the 83.6%/234-row final flips under the new rule (57.69
    vs 56.50 adj), but a newer body (fn_4_28FC.1792588514.c, 96.5% / 82 rows / 40 pool rows) now
    wins under every rule; the batch-210 loss is moot.
  - fn_1_2F294: the brief's claim does not hold today: the final (81.55%) binds no pool rows
    (pool=0, 317 rows) while the seed binds one and has 247 rows; the newest body
    (fn_1_2F294.1792591315.c, 90.3% / 230 rows / 18 pool rows) wins under every rule.
- Ground truth (matched functions with >=2 saved bodies, the lineage = the saved body closest to
  the matched C by line-level difflib, unambiguous when the gap is >= 0.03): 194 functions.
  Lineage ranked first: current 181, mean75 179, mean 178, margin1/2 178, mean25 176, rows 174.
  This proxy is recency, not rule quality: the lineage is the newest saved body in 182 of 194
  (the matching attempt was seeded from it by the rule in force), and all five current-vs-mean
  disagreements are newest-body lineages (4 current, 1 mean: fn_1_ECE04, whose 5-row body the
  current rule ranked below a 14-row 99.2% body). No rule ranks the eventually-matching lineage
  first more often than the current one under this proxy, and the proxy cannot show otherwise.

## Gate (patch applied)

```
lint: 0 finding(s); build ok: True; hashes OK: 16/16
pool_sample: 24 passed, 0 failed, 0 skipped
recent: 24 passed, 0 failed, 0 skipped
GATE: PASS
```

## How to apply

`git apply state/pending_tooling/20261021-row-aware-seed-ranking.patch`, then
`uv run tools/fzgx.py gate`, then commit. Existing `KEY.best.json` files without `selection` rank by
their `percent`; the seedrank cache re-measures each body once (new `v5` keys).
Not changed, noted: `_record_check` saves the first compiled body of an attempt by the progress
scale (`improved`) as before; the plateau/stop accounting still follows `check_score`.
