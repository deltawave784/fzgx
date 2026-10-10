"""vreg_map.py DIR IDX [--class gpr|fpr]: one line per virtual register of a capture:
    vreg  name  cluster  spill_cost  color  region  degree  [-> coalesce root]
name     the compiler object's C name ('?' for an unnamed temporary; '@N' names are compiler objects)
cluster  param (a parameter of the captured function), fn-scope (a named local), compiler (@N),
         temp (unnamed)
color    the register the compiler assigned (coalesced webs resolved to their root's register)
region   pass1 below the class's coalesce window (parameters and locals numbered before lowering),
         window inside it (CSE/induction shadows and lowering temporaries)
A rebuild of the recovery project's tool; the column order is what triage.py/applyorder.py read.
"""
import re, sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import simplify_replay as sr


def parameters(cap):
    """Parameter names of the captured function, from DIR/SYMBOL.c."""
    cap = Path(cap)
    src = cap / f"{cap.name}.c"
    if not src.exists():
        return set()
    text = src.read_text(errors="replace")
    m = re.search(r"\b" + re.escape(cap.name) + r"\s*\(([^)]*)\)\s*\{", text)
    if not m:
        return set()
    names = set()
    for p in m.group(1).split(","):
        p = re.sub(r"\[[^\]]*\]", "", p).strip()
        w = re.findall(r"[A-Za-z_]\w*", p)
        if w and w[-1] != "void":
            names.add(w[-1])
    return names


def rows(cap, idx, cls="gpr"):
    before, after = sr.load(cap, idx, cls)
    params = parameters(cap)
    colors = sr.captured_colors(after) if after else sr.replay(before)[1]
    first = before.get("coalesce_ranges", {}).get(cls, [None])[0]
    out = []
    for n in before["nodes"]:
        v = n["virtual_register"]
        if v < 32:
            continue
        name = n.get("name") or ""
        cluster = ("param" if name in params else "compiler" if name.startswith("@")
                   else "fn-scope" if name else "temp")
        prefix = "r" if cls == "gpr" else "f"
        color = colors.get(v)
        out.append({"vreg": v, "name": name or "?", "cluster": cluster, "cost": n["spill_cost"],
                    "color": f"{prefix}{color}" if color is not None else "-",
                    "region": "pass1" if first is not None and v < first else "window",
                    "degree": len(n["neighbors"]),
                    "root": n["physical_register"] if n["flags"] & 4 else None})
    return out


def main(argv=None):
    argv = list(sys.argv[1:] if argv is None else argv)
    cls = "gpr"
    if "--class" in argv:
        i = argv.index("--class"); cls = argv[i + 1]; del argv[i:i + 2]
    if len(argv) < 2:
        print(__doc__); return 2
    for r in rows(argv[0], argv[1], cls):
        tail = f" -> v{r['root']}" if r["root"] is not None else ""
        print(f"{r['vreg']} {r['name']} {r['cluster']} {r['cost']} {r['color']} {r['region']} {r['degree']}{tail}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
