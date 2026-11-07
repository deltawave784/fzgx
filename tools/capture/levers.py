"""levers.py DIR IDX --target v46:r28,v34:r29 [--class gpr|fpr]: which allocator lever can reach the targets.

The declaration-order solver (source_rank_solver.py) only permutes the named pass-1 locals. Most
near-miss residuals name other webs (autotarget prints them as `temp window`, `@N compiler pass1`),
and those runs ended `status=unsolved` without saying what would move them. This replays the
captured graph under two kinds of perturbation and reports the smallest one that meets the targets:

  numbering  exchange the numbers of two webs of the same group (vreg_map cluster/region):
               fn-scope/pass1   declared locals: declaration order (the solver's search, one swap)
               param/pass1      parameter order
               compiler/pass1   compiler objects (@N): inline-site parameters/locals, struct and
                                comma temporaries; their number follows front-end creation order,
                                so the lever is the inline helper's parameter/local order or the
                                order of the expressions that create them
               temp/pass1       CSE/induction shadow objects: de-CSE into a declared local
               temp/window      lowering temporaries: their number follows the order in which the
                                lowered expressions are created (source expression order, hoisted
                                invariants, conversion constants)
  degree     add or remove interference count on one target (N in 1..8 and K): the web's live range
             overlaps a different number of values in retail; numbering alone cannot reach it.

A numbering verdict means the graph is retail's and only the creation order differs; a degree
verdict means the interference structure differs (liveness, a split web, an extra live value).
`verdict=none` means no single perturbation of either kind reaches every target.
"""
import argparse, itertools, sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import paths  # noqa: E402  (puts the recovery tools on sys.path)
import simplify_replay as sr  # noqa: E402
import vreg_map  # noqa: E402

LEVER = {
    ("fn-scope", "pass1"): "declaration order of the named locals",
    ("param", "pass1"): "parameter order",
    ("compiler", "pass1"): "creation order of compiler objects (inline-site parameters/locals, struct/comma temporaries)",
    ("temp", "pass1"): "CSE/induction shadow objects (de-CSE into a declared local, or hold the value in one)",
    ("temp", "window"): "creation order of lowering temporaries (source expression order, hoisted invariants)",
}
MAX_GROUP = 60   # larger groups: only swaps that involve a target web


def analyse(cap, idx, targets, cls="gpr"):
    before, _ = sr.load(cap, idx, cls)
    base = sr.Graph(before, cls)
    color0 = base.select(base.simplify())
    rows = {r["vreg"]: r for r in vreg_map.rows(cap, idx, cls)
            if r["vreg"] in base.nodes and r["vreg"] not in base.coalesced}

    def score(graph, back):
        color = graph.select(graph.simplify())
        by_old = {back.get(v, v): c for v, c in color.items()}
        met = sum(1 for v, r in targets.items() if by_old.get(v) == r)
        changed = sum(1 for v, c in by_old.items() if v >= 32 and v not in targets and c != color0.get(v))
        return met, changed

    groups = {}
    for v, r in rows.items():
        groups.setdefault((r["cluster"], r["region"]), []).append(v)
    numbering = []
    for key, nums in groups.items():
        nums.sort()
        best = None
        for a, b in itertools.combinations(nums, 2):
            if len(nums) > MAX_GROUP and a not in targets and b not in targets:
                continue
            met, changed = score(base.relabel({a: b, b: a}), {a: b, b: a})
            cand = (-met, changed, a, b)
            if best is None or cand < best:
                best = cand
        if best:
            numbering.append((best, key, len(nums)))
    numbering.sort()

    degree = []
    for v in sorted(targets):
        if v not in base.nodes:
            continue
        for d in sorted({1, 2, 3, 4, 6, 8, base.k}):
            for sign in (1, -1):
                g = base.relabel({})
                g.apply(f"{v}:{sign * d:+d}")
                met, changed = score(g, {})
                degree.append((-met, changed, d, v, sign * d))
    degree.sort()
    return {"baseline": sum(1 for v, r in targets.items() if color0.get(v) == r), "numbering": numbering,
            "degree": degree[:1], "rows": rows, "total": len(targets)}


def report(res, prefix="r"):
    n, rows = res["total"], res["rows"]
    name = lambda v: rows[v]["name"] if v in rows else "?"
    lines = [f"levers: baseline meets {res['baseline']}/{n}"]
    verdict = "none"
    for (met, changed, a, b), key, size in res["numbering"][:3]:
        lines.append(f"  numbering {key[0]}/{key[1]} (n={size}): swap v{a}({name(a)}) <-> v{b}({name(b)}) "
                     f"meets {-met}/{n}, {changed} other colors change")
        if -met == n and verdict == "none":
            verdict = f"numbering {key[0]}/{key[1]}: {LEVER.get(key, key)}"
    for met, changed, d, v, delta in res["degree"]:
        lines.append(f"  degree v{v}({name(v)}) {delta:+d}: meets {-met}/{n}, {changed} other colors change")
        if -met == n and verdict == "none":
            verdict = f"degree: v{v}({name(v)}) interferes with {abs(delta)} {'more' if delta > 0 else 'fewer'} webs in retail"
    lines.append(f"verdict={verdict}")
    return "\n".join(lines)


def main(argv=None):
    ap = argparse.ArgumentParser()
    ap.add_argument("dir"); ap.add_argument("idx")
    ap.add_argument("--target", required=True)
    ap.add_argument("--class", dest="cls", default="gpr", choices=["gpr", "fpr"])
    a = ap.parse_args(argv)
    targets = {}
    for item in a.target.split(","):
        v, r = item.split(":")
        targets[int(v.lstrip("v"))] = int(r.lstrip("rf"))
    print(report(analyse(a.dir, a.idx, targets, a.cls)))


if __name__ == "__main__":
    main()
