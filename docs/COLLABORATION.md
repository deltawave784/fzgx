# Two clones, one decompilation

Two people (or two accounts: a Claude loop and a Codex harness) can work on the decompilation at the
same time **if each has its own clone** and they meet through the fork. The ledger, claims and locks are
local to a clone; nothing in them coordinates two clones, so the split below does.

## One-time setup of the second clone

```sh
git clone https://github.com/deltawave784/fzgx.git FZero-GX-Decomp-b
cd FZero-GX-Decomp-b
git switch -c codex origin/windows-and-types   # or: git switch windows-and-types, then branch from it
# copy the disc image into orig/ (it is never committed), then:
uv run tools/prepare_orig.py --version GFZE01
uv run python configure.py --version GFZE01 && uv run ninja     # must end with 16 files OK
uv run tools/fzgx.py sync
git config merge.fzjson.driver "uv run python tools/merge_json_state.py %O %A %B"
git config merge.fzjson.name "keyed JSON state merge"
git config user.name "<name>" && git config user.email "<email>"
```
Do the same `git config merge.fzjson...` lines in the first clone. `.gitattributes` already routes
`state/progress.csv` to git's union merge and `state/repairs/fixup_imports.json` to the driver.

## Who works on what

Split by **module**; the split ranges, symbol files and `units.json` entries are per module, so
merges stay mechanical. Record the split here and keep to it:

| Clone | Modules |
|---|---|
| A (Claude loop, branch `windows-and-types`) | `main_rel` |
| B (Codex, branch `codex`) | `main`, `movie_module`, `customize`, `sel`, and every smaller module |

(1,070 of the 2,121 unmatched functions are in `main_rel`; the rest is spread across the other modules.)
Clone A's router takes `--module main_rel`; clone B's seed manifests list only its modules.

## Rules that keep the clones from colliding

1. **One owner per tool and header.** Tooling rounds, the librarian, `tu-finish`, `tutruth` and any edit
   under `tools/`, `include/` or `config/` run in ONE clone (A). B pulls those changes; it does not make its own.
2. **`state/ledger.json` belongs to clone A.** Only A runs `fzgx snapshot`. B never commits that file
   (its `verify` commits only units, splits, symbols and sources, so this holds by default).
3. **Merge only between batches**, with no claim and no running `fixup`/`verify`/`ninja`, and a clean tree.
4. **After every merge:** `uv run ninja` must end with 16 files OK, then `uv run tools/fzgx.py gate`
   (and `uv run tools/fzgx.py sync` so the local ledger learns what the other side matched).
5. **Never rewrite published history** (no rebase or filter-branch on pushed branches); merge instead.

## The loop at each batch boundary

```sh
git pull --no-rebase fork codex          # in A: take B's work (in B: pull fork windows-and-types)
uv run ninja && uv run tools/fzgx.py gate && uv run tools/fzgx.py sync
# ... run a batch and its close-out (reuse, fixup, verify, progress) ...
git push fork windows-and-types          # (in B: git push fork codex)
```
`git push` is on this project's deny list for Claude; the push step is run by the user, or the user
allows exactly that command for the loop. A merge that conflicts anywhere other than `units.json`,
`splits.txt` or `symbols.txt` hunks of different modules is a sign the split was broken: stop and look.

## Untested

The two-clone flow, the merge driver on a real conflict and the Codex harness against this repo's
current oracle have not been run end to end. Do the first merge by hand and run the gate before automating anything.
