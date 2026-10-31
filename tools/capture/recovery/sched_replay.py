"""sched_replay.py DIR [--block B --before I --after J] [-v]: replay MWCC's list scheduler over a
captured GC/1.3.2 block and say which dependence edge decides an instruction order.

DIR is a capture132.sh output with `pcode-sched-NNNN-before.json` (PCode at each Scheduler entry,
0x500020) and `pcode-0001-scheduled.json` (the order handed to the allocator). The model is the
recovered 1.2.5 backend (rayanht/mwcc src/backend/Scheduler.c, MachineSimulation750.c):
  graph     built from the last instruction to the first. Register defs depend on later uses
            (latency of the def) and later defs (no latency on 750); uses on later defs (none).
            Constant-pool loads (flag 0x40) take part in no memory relation.
            Stack memory operands carry (object, offset, width) and conflict when they overlap: a store depends on later accesses of the
            same slot and on later pointer operations; a pointer read depends on every later
            write, a pointer write on every later access. Volatile accesses also order against
            every later volatile access. Branches and calls are late: everything before waits.
  height    the longest latency path to the block end; latest cycle = max height - height.
  select    each cycle issues up to two ready instructions (all predecessors issued, latency
            elapsed, unit free, six completion slots); among them: an urgent one (latest cycle
            reached) first, then the one whose issue frees the most successors, then the greater
            height, then program order.
  machine   750 pipeline: IU1/IU2, LSU two stages, FPU three stages (fdivs holds stage one for 17
            cycles), SRU, BPU; a store cannot issue while another store sits in LSU stage two
            (measured: without that rule 2 of 26 fn_1_102750 blocks differ, with it 26/26 match).
Memory operands in 1.3.2 keep the offset in bytes 2..3 and the object in bytes 6..9 of the raw
operand (the snapshot reader's `object` field is shifted for them).

Default: validate every block of the pass (exact = the replay reproduces the compiler). Pass 2 is
the pre-allocation scheduling of a single-function capture (pass 1 precedes later optimizations;
pass 3 skips blocks already flagged scheduled, so its differing blocks are not replay errors).
--block B --before I --after J: on the pass-2 input (the pre-allocation pass of a single-function
capture; --pass N selects another), list the single dependence edges whose removal makes input
instruction I issue before J. That names the memory or register relation retail lacks.
"""
import argparse
import collections
import json
from pathlib import Path

UNITS = {}
for _m in ('LBZ LBZU LBZX LHZ LHZU LHZX LHA LHAU LHAX LWZ LWZU LWZX STB STBU STBX STH STHU STHX STW STWU STWX '
           'LFS LFSU LFSX LFD LFDU LFDX STFS STFSU STFSX STFD STFDU STFDX LMW STMW').split():
    UNITS[_m] = (3, 2, (1, 1, 0, 0))
for _m in ('ADD ADDC ADDE ADDI ADDIC ADDICR ADDIS ADDME ADDZE NEG SUBF SUBFC SUBFE SUBFIC SUBFME SUBFZE ANDI '
           'ANDIS ORI ORIS XORI XORIS AND OR XOR NAND NOR EQV ANDC ORC EXTSB EXTSH CNTLZW RLWINM RLWNM RLWIMI '
           'SLW SRW SRAWI SRAW LI LIS MR NOP NOT').split():
    UNITS[_m] = (2, 1, (1, 0, 0, 0))
for _m in 'CMPI CMP CMPLI CMPL'.split():
    UNITS[_m] = (2, 3, (1, 0, 0, 0))
for _m in ('FMR FABS FNEG FNABS FADD FADDS FSUB FSUBS FMULS FMADDS FMSUBS FNMADDS FNMSUBS FRSQRTE FSEL FRSP '
           'FCTIW FCTIWZ FCMPU FCMPO MFFS MTFSF').split():
    UNITS[_m] = (5, 3, (1, 1, 1, 0))
for _m in 'FMUL FMADD FMSUB FNMADD FNMSUB'.split():
    UNITS[_m] = (5, 4, (2, 1, 1, 0))
for _m in 'B BL BC BCLR BCCTR BT BTLR BTCTR BF BFLR BFCTR BDNZ BDNZT BDNZF BDZ BDZT BDZF BLR BCTR BCTRL BLRL'.split():
    UNITS[_m] = (0, 0, (0, 0, 0, 1))
for _m in 'MTXER MTCTR MTLR'.split():
    UNITS[_m] = (8, 2, (2, 0, 0, 1))
for _m in 'CRAND CRANDC CREQV CRNAND CRNOR CROR CRORC CRXOR MCRF MTCRF MTSPR MFSPR MFXER MFCTR MFLR MFCR'.split():
    UNITS[_m] = (8, 1, (1, 0, 0, 1))
UNITS.update({'FDIV': (5, 31, (31, 0, 0, 0)), 'FDIVS': (5, 17, (17, 0, 0, 0)), 'FRES': (5, 10, (10, 0, 0, 0)),
              'MULLW': (1, 5, (5, 0, 0, 0)), 'MULHW': (1, 5, (5, 0, 0, 0)), 'MULHWU': (1, 6, (5, 0, 0, 0)),
              'MULLI': (1, 3, (3, 0, 0, 0)), 'DIVW': (1, 19, (19, 0, 0, 0)), 'DIVWU': (1, 19, (19, 0, 0, 0))})
READ, WRITE, PTR, CONST, VOLATILE = 0x2, 0x4, 0x20, 0x40, 0x80   # GC/1.3.2 instruction flag bits
GPR_CLASS = 4


class Node:
    pass


def width(name):
    if name.startswith(('LFD', 'STFD')):
        return 8
    if name.startswith(('LB', 'STB')):
        return 1
    return 2 if name.startswith(('LH', 'STH')) else 4


def overlap(a, b):
    return a is None or (a[0] == b[0] and a[1] < b[1] + b[2] and b[1] < a[1] + a[2])


def load(path, block):
    out = []
    for ins in json.loads(Path(path).read_text())['blocks'][block]['instructions']:
        regs, slots, text = [], [], []
        for o in ins['operands']:
            if o['kind'] == 0:
                gpr = o['class'] == GPR_CLASS
                text.append(('r' if gpr else 'f' if o['class'] == 3 else f"c{o['class']}:") + str(o['reg'])
                            + ('w' if o['flags'] & 2 else ''))
                if gpr and (o['reg'] in (2, 13) or (o['reg'] == 0 and not o['flags'] & 3)):
                    continue
                regs.append((o['class'], o['reg'], bool(o['flags'] & 2)))
            else:
                raw = bytes.fromhex(o['raw'])
                offset = int.from_bytes(raw[2:4], 'little', signed=True)
                text.append(f"{offset}(obj)" if o['kind'] == 3 else f"#{offset}")
                if o['kind'] == 3:
                    slots.append((raw[6:10].hex(), offset, width(ins['opcode_descriptor']['mnemonic'])))
        name = ins['opcode_descriptor']['mnemonic']
        out.append({'m': name, 'flags': ins['flags'], 'regs': regs, 'slots': slots,
                    'text': f"{name.lower()} {', '.join(text)}"})
    return out


def run(instrs, skip=frozenset(), edges=None, trace=False):
    """Scheduled order (input indices). `skip` removes (pred, succ) edges; `edges` collects them."""
    nodes, owners, reads, writes, lates, branch = [], {}, [], [], [], [None]
    max_height = 0

    def dep(o, d, latency):
        if o is d or (o.i, d.i) in skip:
            return
        if edges is not None:
            edges.add((o.i, d.i))
        for c in o.succ:
            if c[0] is d:
                if c[1] < latency:
                    c[1] = o.lat
                    o.h = max(o.h, d.h + c[1])
                return
        v = o.lat if latency else 0
        o.succ.append([d, v]); d.preds += 1; o.h = max(o.h, d.h + v)

    for i in range(len(instrs) - 1, -1, -1):
        ins = instrs[i]
        n = Node(); n.i, n.ins, n.succ, n.preds, n.early = i, ins, [], 0, 0
        n.unit, n.lat, n.stages = UNITS[ins['m']]
        n.h = n.lat
        f = ins['flags']
        for cls, reg, is_def in ins['regs']:
            defs, uses = owners.setdefault((cls, reg), ([], []))
            if is_def:
                for u in uses: dep(n, u, 1)
            for d in defs: dep(n, d, 0)
            (defs if is_def else uses).insert(0, n)
        volatile, write = bool(f & VOLATILE), bool(f & WRITE)
        if f & (READ | WRITE) and not f & CONST:
            for slot in ins['slots']:
                if volatile:
                    for m, s, v in reads:
                        if v or (write and overlap(s, slot)): dep(n, m, 1)
                    for m, s, v in writes:
                        if v or overlap(s, slot): dep(n, m, 1)
                else:
                    for m, s, v in (reads + writes if write else writes):
                        if overlap(s, slot): dep(n, m, 1)
                (writes if write else reads).insert(0, (n, slot, volatile))
        if f & PTR:
            for m, s, v in (reads + writes if write else writes):
                dep(n, m, 1)
            (writes if write else reads).insert(0, (n, None, volatile))
        if n.stages[3]:
            for p in nodes: dep(n, p, 0)
            lates.insert(0, n)
        for q in lates:
            if q is not n: dep(n, q, 0)
        if not n.succ and branch[0] is not None:
            dep(n, branch[0], 0)
        if ins['m'].startswith('B'):
            branch[0] = n
        max_height = max(max_height, n.h)
        nodes.insert(0, n)
    for n in nodes:
        n.latest = max_height - n.h
    stage, completion, out, ready, cycle = [None] * 9, [], [], list(nodes), 0

    def free(n):
        if len(completion) >= 6:
            return False
        if n.unit == 2:
            if stage[1] is not None and stage[2] is not None:
                return False
        elif stage[n.unit] is not None:
            return False
        return not (n.ins['flags'] & WRITE and stage[4] is not None and stage[4][0].ins['flags'] & WRITE)

    def frees(n):
        return sum(1 for c in n.succ if c[0].preds == 1)

    while ready:
        for slot in range(2):
            best = None
            for c in ready:
                if c.preds or c.early > cycle or not free(c):
                    continue
                if best is None:
                    best = c
                elif best.latest > cycle or c.latest <= cycle:
                    if best.latest > cycle and c.latest <= cycle:
                        best = c
                    elif frees(best) != frees(c):
                        best = c if frees(c) > frees(best) else best
                    elif c.h > best.h:
                        best = c
            if best is None:
                break
            for c in best.succ:
                c[0].preds -= 1
                c[0].early = max(c[0].early, c[1] + cycle)
            if trace:
                print(f"cycle {cycle:3d} #{best.i:<3d} {best.ins['text']:36s} height {best.h} latest {best.latest}")
            out.append(best.i)
            completion.append([best, False])
            unit = 1 if best.unit == 2 and stage[1] is None else best.unit
            stage[unit] = [best, best.stages[0]]
            ready.remove(best)
        for s in stage:
            if s is not None and s[1]:
                s[1] -= 1
        for _ in range(2):
            if completion and completion[0][1]:
                completion.pop(0)

        def retire(k):
            for c in completion:
                if c[0] is stage[k][0]:
                    c[1] = True
            stage[k] = None
        for k in (1, 4, 7, 8, 0, 2):
            if stage[k] is not None and stage[k][1] == 0:
                retire(k)
        if stage[5] is not None and stage[5][1] == 0 and stage[5][0].ins['m'] in ('FDIV', 'FDIVS'):
            retire(5)
        for src, dst, idx in ((6, 7, 2), (5, 6, 1), (3, 4, 1)):
            if stage[src] is not None and stage[src][1] == 0 and stage[dst] is None:
                stage[dst] = [stage[src][0], stage[src][0].stages[idx]]
                stage[src] = None
        cycle += 1
    return out


def compiler_order(before, after):
    used, out = set(), []
    for a in after:
        j = next(k for k, b in enumerate(before) if k not in used and b['text'] == a['text'])
        used.add(j); out.append(j)
    return out


def validate(capture, number):
    stages = sorted(capture.glob('pcode-sched-*-before.json'))
    nexts = stages[1:] + sorted(capture.glob('pcode-*-scheduled.json'))[:1]
    for before, after in list(zip(stages, nexts))[number - 1:number]:
        count = len(json.loads(before.read_text())['blocks'])
        afters = [load(after, k) for k in range(len(json.loads(after.read_text())['blocks']))]
        tally = collections.Counter()
        for b in range(count):
            instrs = load(before, b)
            if len(instrs) < 3:
                continue
            key = collections.Counter(x['text'] for x in instrs)
            match = [a for a in afters if collections.Counter(x['text'] for x in a) == key]
            if not match:
                tally['changed'] += 1
                continue
            try:
                same = run(instrs) == compiler_order(instrs, match[0])
            except KeyError as e:
                tally[f'unmodelled {e}'] += 1
                continue
            tally['exact' if same else 'differs'] += 1
            if not same:
                print(f"{before.name} block {b}: replay differs")
        print(f"{before.name} -> {after.name}: {dict(tally)}")


def main():
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    ap.add_argument('capture')
    ap.add_argument('--pass', dest='pass_', type=int, default=2)
    ap.add_argument('--block', type=int)
    ap.add_argument('--before', type=int, help='input index that should issue first')
    ap.add_argument('--after', type=int, help='input index that should issue later')
    ap.add_argument('-v', action='store_true', help='print the replayed cycles of --block')
    args = ap.parse_args()
    capture = Path(args.capture)
    if args.block is None:
        validate(capture, args.pass_)
        return
    instrs = load(capture / f'pcode-sched-{args.pass_:04d}-before.json', args.block)
    for i, x in enumerate(instrs):
        print(f"{i:3d} {x['text']}")
    edges = set()
    order = run(instrs, edges=edges, trace=args.v)
    print('replay order:', order)
    if args.before is not None and args.after is not None:
        for e in sorted(edges):
            o = run(instrs, skip={e})
            if o.index(args.before) < o.index(args.after):
                print(f"without {e[0]} -> {e[1]} ({instrs[e[0]]['text']} -> {instrs[e[1]]['text']}): {o}")


if __name__ == '__main__':
    main()
