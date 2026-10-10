"""simplify_replay.py DIR IDX [HYPOTHESIS ...]: replay MWCC's graph simplification and color
selection over a captured interference graph and compare with the compiler's own result.

A rebuild of the recovery project's tool. The model is Coloring_SimplifyGraph and
Coloring_SelectColors from the recovered backend (rayanht/mwcc src/backend/Coloring.c):
  simplify  repeated ascending scans over vregs 32..count-1; a node that is neither simplified
            nor coalesced is pushed when its degree is below K (its neighbours' degrees drop at
            once), otherwise it joins the remaining list (prepended: highest vreg first). When a
            scan pushes nothing, the remaining node with the lowest spill_cost/degree is pushed
            (strict <, so ties keep the highest vreg) and the scans resume.
  select    pops the stack (last pushed first); each node takes the lowest register in the class
            mask (r0, r3..r12 for GPRs) or among the callee-saved registers already claimed that no
            coloured neighbour holds (neighbours coloured >= 32 are coalesced and ignored); when none
            is free it claims r31, r30, ... downward.
Initial degrees are the neighbour counts. HYPOTHESIS arguments perturb the captured graph:
  V:+N / V:-N   add N to / subtract N from vreg V's initial degree
  V~W           add an interference edge between V and W
  V=W           exchange the numbers of V and W (a declaration-order change)
  k=N           replay with N available registers instead of the class default (29 GPRs, 32 FPRs)
Options: --class fpr replays the FPR graph (default gpr).
"""
import json, sys
from pathlib import Path

# Coloring_GPRColorMask / Coloring_FPRColorMask: the free registers up to r12 / f13 (r1, r2 and
# r13 are reserved); Registers_AvailableGPRs / FPRs: the free registers of 32.
CLASSES = {"gpr": {"mask": [0] + list(range(3, 13)), "k": 29},
           "fpr": {"mask": list(range(0, 14)), "k": 32}}
CALLEE_SAVED = list(range(31, 13, -1))


def _attempts(cap, idx, cls):
    return sorted(Path(cap).glob(f"coloring-{idx}-{cls}-*-before.json"))


def load(cap, idx, cls="gpr", attempt=None):
    """(before, after) coloring snapshots; the last attempt (the one that colored) by default."""
    files = _attempts(cap, idx, cls)
    if not files:
        raise FileNotFoundError(f"no coloring snapshots for {idx} in {cap}")
    before = files[-1] if attempt is None else Path(cap) / f"coloring-{idx}-{cls}-{int(attempt):02d}-before.json"
    after = Path(str(before).replace("-before.json", "-after.json"))
    return json.loads(before.read_text()), (json.loads(after.read_text()) if after.exists() else None)


class Graph:
    def __init__(self, snapshot, cls=None):
        self.cls = cls or snapshot.get("register_class", "gpr")
        self.count = snapshot["virtual_register_count"]
        self.nodes = {n["virtual_register"]: n for n in snapshot["nodes"]}
        self.neighbors = {v: list(n["neighbors"]) for v, n in self.nodes.items()}
        self.degree0 = {v: len(self.neighbors[v]) for v in self.nodes}
        self.cost = {v: n["spill_cost"] for v, n in self.nodes.items()}
        self.coalesced = {v for v, n in self.nodes.items() if v >= 32 and n["flags"] & 4}
        self.coalesce_target = {v: self.nodes[v]["physical_register"] for v in self.coalesced}
        self.k = CLASSES[self.cls]["k"]

    def relabel(self, mapping):
        """Renumber vregs: mapping old -> new (a permutation over some subset)."""
        m = lambda v: mapping.get(v, v)
        g = Graph.__new__(Graph)
        g.count, g.k, g.cls = self.count, self.k, self.cls
        g.nodes = {m(v): n for v, n in self.nodes.items()}
        g.neighbors = {m(v): [m(w) for w in ws] for v, ws in self.neighbors.items()}
        g.degree0 = {m(v): d for v, d in self.degree0.items()}
        g.cost = {m(v): c for v, c in self.cost.items()}
        g.coalesced = {m(v) for v in self.coalesced}
        g.coalesce_target = {m(v): (m(t) if t >= 32 else t) for v, t in self.coalesce_target.items()}
        return g

    def apply(self, hypothesis):
        h = hypothesis.strip()
        if h.startswith("k="):
            self.k = int(h[2:])
        elif "~" in h:
            a, b = (int(x.strip().lstrip("v")) for x in h.split("~"))
            for x, y in ((a, b), (b, a)):
                if y not in self.neighbors[x]:
                    self.neighbors[x].append(y); self.degree0[x] += 1
        elif "=" in h:
            a, b = (int(x.strip().lstrip("v")) for x in h.split("="))
            g = self.relabel({a: b, b: a})
            self.__dict__.update(g.__dict__)
        elif ":" in h:
            v, d = h.split(":")
            self.degree0[int(v.lstrip("v"))] += int(d)
        else:
            raise ValueError(f"unknown hypothesis {h!r}")

    def simplify(self):
        degree = dict(self.degree0)
        done = set(self.coalesced)
        stack = []
        optimistic = self.optimistic = []

        def push(v):
            for w in self.neighbors[v]:
                degree[w] -= 1
            done.add(v)
            stack.append(v)

        def scan():
            removed, remaining = False, []
            for v in range(32, self.count):
                if v not in self.nodes or v in done:
                    continue
                if degree[v] < self.k:
                    push(v); removed = True
                else:
                    remaining.insert(0, v)
            return removed, remaining

        removed, remaining = True, []
        while removed:
            removed, remaining = scan()
        while remaining:
            best, best_cost = None, None
            for v in remaining:
                c = float("inf") if v >= self.count else self.cost[v] / degree[v]
                if best is None or c < best_cost:
                    best, best_cost = v, c
            push(best)
            optimistic.append(best)
            changed = True
            while changed:
                changed, remaining = scan()
        self.final_degree = degree
        return stack[::-1]          # coloring order: the stack's head first

    def select(self, order, mask=None):
        mask = CLASSES[self.cls]["mask"] if mask is None else mask
        color = {v: v for v in range(32)}
        for v in self.coalesced:
            color[v] = self.coalesce_target[v]
        colors = set(mask)
        claimed = []
        spilled = []
        for v in order:
            taken = {color[w] for w in self.neighbors[v] if w in color and 0 <= color[w] < 32}
            free = sorted(colors - taken)
            if free:
                color[v] = free[0]
                continue
            for r in CALLEE_SAVED:
                if r not in claimed:
                    claimed.append(r); colors.add(r); color[v] = r
                    break
            else:
                spilled.append(v)
        for v in self.coalesced:            # Coloring_CommitAssignments resolves coalesced chains
            c = color[v]
            while c is not None and c >= 32:
                c = color.get(c)
            color[v] = c
        self.claimed, self.spilled = claimed, spilled
        return color


def replay(before, hypotheses=()):
    """(coloring order, vreg -> register) for a captured before-snapshot."""
    g = Graph(before)
    for h in hypotheses:
        g.apply(h)
    order = g.simplify()
    return order, g.select(order)


def captured_colors(after):
    nodes = {n["virtual_register"]: n for n in after["nodes"]}
    out = {}
    for v, n in nodes.items():
        c = n["physical_register"]
        while c is not None and c >= 32:
            c = nodes[c]["physical_register"] if c in nodes else None
        out[v] = c
    return out


def main(argv=None):
    argv = list(sys.argv[1:] if argv is None else argv)
    if len(argv) < 2:
        print(__doc__); return 2
    cls = "gpr"
    if "--class" in argv:
        i = argv.index("--class"); cls = argv[i + 1]; del argv[i:i + 2]
    cap, idx, hyps = argv[0], argv[1], argv[2:]
    before, after = load(cap, idx, cls)
    g = Graph(before)
    for h in hyps:
        g.apply(h)
    order = g.simplify()
    color = g.select(order)
    print(f"{Path(cap).name} {idx} {cls}: {g.count} vregs, K={g.k}, {len(order)} simplified, {len(g.coalesced)} coalesced"
          + (f", {len(g.optimistic)} pushed by spill cost" if g.optimistic else ""))
    if not hyps:
        same = sum(1 for a, b in zip(order, before["simplify_order"]) if a == b)
        print(f"simplify order: {same}/{len(before['simplify_order'])} rows match the capture"
              + ("" if order == before["simplify_order"] else f" (first difference at row {next((i for i, (a, b) in enumerate(zip(order, before['simplify_order'])) if a != b), min(len(order), len(before['simplify_order'])))})"))
        if after:
            cap_colors = captured_colors(after)
            agree = [v for v in cap_colors if color.get(v) == cap_colors[v]]
            print(f"colors: {len(agree)}/{len(cap_colors)} match the capture")
            for v in sorted(cap_colors):
                if color.get(v) != cap_colors[v]:
                    print(f"  v{v}: replay r{color.get(v)} capture r{cap_colors[v]}")
    print("callee-saved colors (coloring order):", ", ".join(f"v{v}->r{color[v]}" for v in order if 14 <= (color.get(v) or 0) <= 31 and v >= 32))
    if g.spilled:
        print("spilled:", g.spilled)
    for v in sorted(color):
        if v >= 32 and before and hyps:
            print(f"  v{v} r{color[v]}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
