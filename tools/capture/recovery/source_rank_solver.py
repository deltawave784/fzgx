"""source_rank_solver.py DIR IDX --target v46:r28,v34:r29 [--samples N] [--max-permutations N]
                      [--class gpr|fpr] [--seed N]
Search the declaration order of a captured function's named locals for one under which the
replayed allocator gives each target web its target register.

Model (CLAUDE.md, the recovered CodeGen_PreallocateObjectRegisters): named locals take the
pass-1 vreg numbers below the coalesce window, the first declared local the highest. A
declaration-order change permutes those numbers among the locals and leaves the interference
graph as it is; temporaries, parameters and compiler (@N) objects keep their numbers. Every
candidate is replayed with simplify_replay: the identity, every swap and every 3-cycle first, then
every order (or --samples random ones beyond --max-permutations). Candidates are ranked by the
targets they meet, then by how few locals move, then by how few other colors change.

Output: the best orders, each as `order: vA, vB, ...` listing the locals from the lowest new
number to the highest (applyorder.py takes this string; the reverse is the declaration order),
and a final `status=solved` / `status=partial` / `status=unsolved`. A target that names a web
outside the permutable locals is still scored (the permutation can move it indirectly).
A rebuild of the recovery project's tool.
"""
import argparse, itertools, math, random, sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import simplify_replay as sr
import vreg_map


def parse_targets(text):
    out = {}
    for item in text.split(","):
        item = item.strip()
        if not item:
            continue
        v, r = item.split(":")
        out[int(v.strip().lstrip("v"))] = int(r.strip().lstrip("rf"))
    return out


def solve(cap, idx, targets, cls="gpr", samples=1500, max_permutations=20000, seed=0, keep=5):
    before, _ = sr.load(cap, idx, cls)
    base = sr.Graph(before, cls)
    rows = [r for r in vreg_map.rows(cap, idx, cls) if r["cluster"] == "fn-scope" and r["region"] == "pass1"]
    seen_names = {}
    for r in rows:
        seen_names[r["name"]] = seen_names.get(r["name"], 0) + 1
    # a name with several webs is an inlined helper's local (one per inline site): not reorderable alone
    numbers = sorted(r["vreg"] for r in rows if seen_names[r["name"]] == 1)
    order0 = base.simplify()
    color0 = base.select(order0)

    def evaluate(assign):
        """assign: local (original vreg) -> new number. Returns (met, changed, colors by original vreg)."""
        g = base.relabel(assign)
        color = g.select(g.simplify())
        back = {assign.get(v, v): v for v in base.nodes}
        by_old = {back[v]: c for v, c in color.items() if v in back}
        met = sum(1 for v, r in targets.items() if by_old.get(v) == r)
        changed = sum(1 for v, c in by_old.items() if v >= 32 and v not in targets and c != color0.get(v))
        return met, changed, by_old

    total = math.factorial(len(numbers))
    n = len(numbers)

    def candidates():
        """Smallest changes first: identity, every swap, every 3-cycle; then all orders when
        they fit max_permutations, else random samples."""
        yield tuple(numbers)
        for i, j in itertools.combinations(range(n), 2):
            p = list(numbers); p[i], p[j] = p[j], p[i]; yield tuple(p)
        if n <= 14:
            for i, j, k in itertools.permutations(range(n), 3):
                if i < j and i < k:
                    p = list(numbers); p[i], p[j], p[k] = numbers[k], numbers[i], numbers[j]; yield tuple(p)
        if total <= max_permutations:
            yield from itertools.permutations(numbers)
        else:
            rng = random.Random(seed)
            for _ in range(samples):
                p = list(numbers); rng.shuffle(p); yield tuple(p)

    mode = f"swaps, 3-cycles and {'all ' + str(total) + ' orders' if total <= max_permutations else str(samples) + ' samples of ' + str(total)}"
    tried = set()
    results = []
    seen = 0
    for perm in candidates():
        if perm in tried:
            continue
        tried.add(perm)
        seen += 1
        assign = {old: new for old, new in zip(numbers, perm) if old != new}
        met, changed, colors = evaluate(assign)
        # the locals ordered by their new number, lowest first
        ranked = [old for new, old in sorted((assign.get(v, v), v) for v in numbers)]
        results.append((-met, len(assign), changed, ranked, colors))
        if len(results) > 4 * keep:
            results.sort(key=lambda r: r[:3]); del results[keep:]
        if met == len(targets) and len(assign) <= 3 and seen > n * n:
            break                      # a minimal solution is found; larger orders only add changes
    results.sort(key=lambda r: r[:3])
    return {"locals": numbers, "mode": mode, "evaluated": seen, "baseline_met": sum(1 for v, r in targets.items() if color0.get(v) == r),
            "best": results[:keep]}


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("cap"); ap.add_argument("idx")
    ap.add_argument("--target", required=True)
    ap.add_argument("--samples", type=int, default=1500)
    ap.add_argument("--max-permutations", type=int, default=20000)
    ap.add_argument("--class", dest="cls", default="gpr")
    ap.add_argument("--seed", type=int, default=0)
    a = ap.parse_args(argv)
    idx = a.idx if not a.idx.isdigit() else f"{int(a.idx):04d}"
    targets = parse_targets(a.target)
    res = solve(a.cap, idx, targets, a.cls, a.samples, a.max_permutations, a.seed)
    names = {r["vreg"]: r["name"] for r in vreg_map.rows(a.cap, idx, a.cls)}
    print(f"locals (pass-1 named): {', '.join(f'v{v}={names.get(v)}' for v in res['locals']) or 'none'}")
    print(f"search: {res['mode']}, {res['evaluated']} replayed; baseline meets {res['baseline_met']}/{len(targets)} targets")
    for neg, moved, changed, ranked, colors in res["best"]:
        print(f"met {-neg}/{len(targets)}, {moved} locals moved, {changed} other colors changed; order: {', '.join(f'v{v}' for v in ranked)}"
              f"  (declare: {', '.join(names.get(v, '?') for v in reversed(ranked))})")
        miss = [f"v{v}:want r{r} got r{colors.get(v)}" for v, r in targets.items() if colors.get(v) != r]
        if miss:
            print("   missed:", ", ".join(miss))
    rows = {r["vreg"]: r for r in vreg_map.rows(a.cap, idx, a.cls)}
    outside = [v for v in targets if v not in res["locals"]]
    if outside:
        print("targets outside the declared locals (a declaration order can move them only indirectly; "
              "they need a structural change such as holding the value in a local):")
        for v in outside:
            r = rows.get(v, {})
            print(f"   v{v}: {r.get('name', '?')} {r.get('cluster', '?')} {r.get('region', '?')}, now {r.get('color', '?')}, want r{targets[v]}")
    best = -res["best"][0][0] if res["best"] else 0
    print("status=" + ("solved" if best == len(targets) else "partial" if best > res["baseline_met"] else "unsolved"))
    return 0


if __name__ == "__main__":
    sys.exit(main())
