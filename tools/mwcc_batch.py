#!/usr/bin/env python3
"""Compile many sources in one mwcc run (the process start is most of a single compile),
then write one depfile for the whole group in ninja's format.

  mwcc_batch.py <group depfile> <object dir> <source>... -- <wibo> <mwcc> <cflags>...

On failure the sources are retried one at a time so the culprit is named:
  FAILED unit: <source>

Replaces mwcc_batch.sh, which needed a POSIX shell that native Windows ninja lacks.
"""

import os
import re
import subprocess
import sys
from pathlib import Path


def dep_lines(d_file: Path) -> str:
    text = d_file.read_text(errors="replace").replace("\r", "")
    if os.name == "nt":
        # Native mwcc writes native paths, which ninja on Windows reads as-is.
        return text if text.endswith("\n") else text + "\n"
    # Under wibo mwcc writes Windows paths: backslashes (keeping the ` \` line continuation)
    # and Z: for absolute host paths.
    out = []
    for line in text.splitlines():
        cont = line.endswith(" \\")
        body = line[:-2] if cont else line
        body = re.sub(r"(^|[ \t])[Zz]:", r"\1", body.replace("\\", "/"))
        out.append(body + (" \\" if cont else ""))
    return "\n".join(out) + "\n"


def main(argv: list) -> int:
    depfile, basedir, rest = argv[0], argv[1], argv[2:]
    split = rest.index("--")
    srcs, cmd = rest[:split], rest[split + 1:]
    if subprocess.run([*cmd, "-MMD", "-c", *srcs, "-o", basedir]).returncode != 0:
        for s in srcs:
            r = subprocess.run([*cmd, "-MMD", "-c", s, "-o", basedir],
                               stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
            if r.returncode != 0:
                print(f"FAILED unit: {s}", file=sys.stderr)
        return 1
    with open(depfile, "w", encoding="utf-8", newline="\n") as f:
        for s in srcs:
            f.write(dep_lines(Path(basedir) / (Path(s).stem + ".d")))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
