#!/usr/bin/env python3
"""Git merge driver for the keyed JSON state files (`state/repairs/fixup_imports.json`).

Usage as a driver: `python tools/merge_json_state.py %O %A %B` (base, ours, theirs); the merged
result is written over %A and the exit status is 0 (clean) or 1 (a conflict was resolved by a rule
below; the file is still written, so the merge never stops on this file).

The files are dicts keyed by function symbol; two clones that each add entries for different
functions merge by union. A key both sides changed to different values keeps the entry that is
link-verified, otherwise theirs. A key one side deleted and the other left unchanged is deleted.
Formatting is the file's own (indent 2), so an unchanged merge produces no diff.
"""
from __future__ import annotations

import json
import sys


def load(path: str) -> dict:
    with open(path, encoding="utf-8") as f:
        text = f.read()
    return json.loads(text) if text.strip() else {}


def dump(path: str, data: dict) -> None:
    with open(path, "w", encoding="utf-8", newline="\n") as f:
        json.dump(data, f, indent=2, ensure_ascii=False)
        f.write("\n")


def verified(entry) -> bool:
    return isinstance(entry, dict) and entry.get("link") == "verified"


def merge(base: dict, ours: dict, theirs: dict):
    out, conflicts = {}, 0
    for key in list(dict.fromkeys([*ours, *theirs, *base])):
        b, o, t = base.get(key), ours.get(key), theirs.get(key)
        if o == t:
            if o is not None:
                out[key] = o
        elif o == b:                      # only theirs changed (or added, or deleted)
            if t is not None:
                out[key] = t
        elif t == b:                      # only ours changed
            if o is not None:
                out[key] = o
        else:                             # both changed differently
            conflicts += 1
            keep = o if (verified(o) and not verified(t)) else t if t is not None else o
            if keep is not None:
                out[key] = keep
    return out, conflicts


def main(argv: list[str]) -> int:
    if len(argv) != 4:
        print(__doc__)
        return 2
    base_path, ours_path, theirs_path = argv[1:4]
    merged, conflicts = merge(load(base_path), load(ours_path), load(theirs_path))
    dump(ours_path, merged)
    if conflicts:
        print(f"merge_json_state: {conflicts} key(s) changed on both sides; kept the verified entry, else theirs")
    return 1 if conflicts else 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
