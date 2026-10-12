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
| A (Claude loop, branch `windows-and-types`) | every module (since 2026-10-10) |
| B (Codex, branch `codex`) | the function slice below in every module (confirmed by clone A 2026-10-10; its Opus route carries `--max-size 768` since c51fb885) |

**2026-10-10:** at the user's request clone A's Fable batches route every module (`route --fable --min-percent 85`,
no `--module`) and its Opus agents take `route --easy --max-size 768` rows from every module. Clone B works only
the function slice below; anything outside it belongs to clone A.

Before 2026-10-10: A owned `main_rel`; B owned `main`, `movie_module`, `customize`, `sel` and every smaller module.

(1,070 of the 2,121 unmatched functions are in `main_rel`; the rest is spread across the other modules.)

**2026-10-12: the function split below is LIFTED.** Clone B (Codex) is stopped (its Sol and Astra pools were empty and the
yield was about 1 to 2 matches a day) and `.fzgx/STOP` is left in the Codex clone so it cannot start by accident. Clone A
routes every function again: the `--max-size 768` ceiling is gone from its Opus route. Do not restart `tools/codex_loop.py`
without agreeing a new split here first, or both clones will claim the same functions and append conflicting entries to
`splits.txt`, `units.json` and `symbols.txt`.

**Split by function, not module (2026-10-10, proposed from the Codex side, confirmed by clone A; in force until 2026-10-12).** Clone A routes every
module, so a module split cannot keep the clones apart; a split by function can. Clone B (Sol, or Astra one agent at a
time) takes only functions that are **over 768 B, have a best recorded score under 85%, and were never attempted by a
Claude tier** (an `opus-`, `sonnet-`, `fable-` or `haiku-` agent id in the committed `state/ledger.json`), in every
module. Clone A keeps everything else: Fable on best >= 85% near misses, Opus on `route --easy` rows. Today that slice
is 607 unmatched functions (1.12 MB), 357 of them in `main_rel`.

What each side must hold to for this to work:
- Clone A: add `--max-size 768` to the Opus route in the match-wave skill (`route --easy --tier opus ... --max-size 768`).
  Without it `--easy` reaches functions over 768 B once the small ones run out, and the clones collide there.
  Keep `route --fable --min-percent` at 85 or above.
- Clone B: `tools/codex_loop.py` enforces the slice in every module (`CLAUDE_SMALL`, `CLAUDE_FLOOR`) and reads clone A's
  Claude attempts from the committed ledger, so B needs a merge of A before each run (rule 3 below) to stay current.
- If either constant changes (the Fable floor, the Opus size ceiling), change the other side in the same commit.
- Both clones append units to every module's `splits.txt`, `units.json` and `symbols.txt`. A conflict at the end of one
  of those files is two sets of appended entries: keep both sides, then `ninja`, hashes and `gate`.
- Clone B stays paused until the user confirms this section and clone A's skill has the `--max-size 768` line.

Until 2026-10-10 clone A's router took `--module main_rel` and clone B's seed manifests listed only its modules.

## Rules that keep the clones from colliding

1. **One owner per tool and header.** Tooling rounds, the librarian, `tu-finish`, `tutruth` and any edit
   under `tools/`, `include/` or `config/` run in ONE clone (A). B pulls those changes; it does not make its own.
2. **`state/ledger.json` belongs to clone A.** Only A runs `fzgx snapshot`. B never commits that file
   (its `verify` commits only units, splits, symbols and sources, so this holds by default). Clone B sets `git config fzgx.snapshot-ledger false` (`orchestrate.py` then neither writes nor commits the snapshot at the end of a batch, so merging A into B cannot conflict on it).
3. **Merge only between batches**, with no claim and no running `fixup`/`verify`/`ninja`, and a clean tree.
4. **After every merge:** `uv run ninja` must end with 16 files OK, then `uv run tools/fzgx.py gate`
   (and `uv run tools/fzgx.py sync` so the local ledger learns what the other side matched).
5. **Never rewrite published history** (no rebase or filter-branch on pushed branches); merge instead.

## Staying in sync: local remotes, not GitHub

Both clones are on the same PC, so they exchange commits directly; no push and no network are involved.
Clone A has a remote `b-local` (the `codex` clone's folder) and clone B has `a-local` (A's folder):

```sh
# in A, between batches (tree clean, nothing claimed or running):
git pull --no-rebase b-local codex
uv run ninja && uv run tools/fzgx.py gate && uv run tools/fzgx.py sync
# in B, the same with:  git pull --no-rebase a-local windows-and-types
```

A and B can both pull at any batch boundary and a pull is never destructive (it adds a merge commit, or
fast-forwards). `fzgx sync` brings the local ledger in line with whatever the other clone matched; the repo
is the truth and `sync` reads it (units, pool matches, assembly units).

**Pushing to the fork is a backup and publication step, not part of the sync.** The user pushes
(`git push fork windows-and-types`, `git push fork codex`) when they want the work backed up or shared.
`git push` stays on the deny list so an unattended loop cannot publish on its own.

A pull that conflicts anywhere other than `units.json`, `splits.txt` or `symbols.txt` hunks of different
modules means the module split was broken: stop and look.

## What a clone does not share

The ledger database (claims, attempt history, blocked functions) is local. Functions blocked by hand in one
clone (`fzgx block`) are not visible in the other, and a clone's `fzgx sync` leaves a function you blocked as it is.

## Untested

The two-clone flow, the merge driver on a real conflict and the Codex harness against this repo's
current oracle have not been run end to end. Do the first merge by hand and run the gate before automating anything.
