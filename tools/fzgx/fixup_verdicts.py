"""Batch capture verdicts: from a GC/1.3.2 allocator capture to the source lever's class.

`fzgx fixup --verdicts SYM ...` diagnoses each symbol's saved best body (seedrank) without a
search:

  1. compile the body under its recorded compiler and flags; a body recorded under another
     version is captured under GC/1.3.2 only when that compiler gives the same object rows
     (fn_1_82C70: GC/1.3 and GC/1.3.2 agree);
  2. capture it (`fixup_capture.capture`, ~11 s in WSL) and record the final PCode block sizes
     (scheduling regions end at block edges);
  3. map EVERY aligned row whose text agrees with retail once register names are masked to its
     web: the rows that already agree pin those webs to the colour retail gives them, the rows
     that differ name the targets (non-renaming rows are counted, not fatal);
  4. replay (`simplify_replay`) and search its override space for the smallest change that gives
     every mapped web retail's register: exchange two numbers (`43=38`), move one web's number
     (`v134->v140`), degree +/-N (`33:+1`); pairs of the best singles when no single works;
  5. classify the change by the webs it touches:
       declaration-order   two declared locals exchange numbers
       held-local          a window web (shadow @N / temporary) must be numbered below a local:
                           de-CSE it into a declared local, hold the call result, wrap a constant
       inline-region       a declared local must be numbered above a window web: make it a local
                           of an inlined region helper (inlined locals live in the window)
       parameter-copy      a parameter's web moves: a local copy declared at that position
       base-temp           a section/literal-pool base (lowering temporary): no source lever
       expression-order    two compiler webs: creation (expression/statement) order
       degree              only an interference count change reproduces retail: lifetime splits
     plus `structural` (no register row maps), `compiler` (no 1.3.2-equivalent object),
     `unresolved` (no override reproduces every mapped colour; `partial_class` names the best).

One row per function goes to `.fzgx/capture/verdicts.json`, keyed by symbol with the body's
sha256. `fixup.Engine.proposals` reads it: the verdict's families (CLASS_FAMILIES) run first for
that body, candidates touching the target webs' names ahead of the rest.
"""
from __future__ import annotations

import json
import os
import re
from pathlib import Path
from typing import Dict, List, Optional, Tuple

from . import fixup_capture as fc, oracle, stuck
from .project import Project, write_atomic

VERDICTS = fc.CAPTURE_ROOT / 'verdicts.json'
DEGREES = (1, 2, 3, 4, 6, 8, 12, 16)
MAX_REPLAYS = 6000
BEAM, DEPTH, MAX_TOTAL = 6, 3, 40000   # replays are ~1 ms (fn_1_DF6AC, 174 FPR webs)
ORDER = ['base-temp', 'parameter-copy', 'copy-coalesce', 'web-split', 'held-local', 'inline-region',
         'declaration-order', 'expression-order', 'degree', 'unresolved']
# class -> engine family keys (fixup.Engine.directed maps each key to its generator)
CLASS_FAMILIES = {
    'declaration-order': ['capture.solver', 'evidence.register_class_orders',
                          'evidence.attributed_declaration_swaps', 'source.split_declaration_groups'],
    'held-local': ['source.rewrites', 'source.call_results_to_locals', 'source.decse_repeated_expressions', 'capture.pointer_locals', 'evidence.induction_indexing',
                   'source.through_local', 'source.promoted_locals'],
    'inline-region': ['source.forwarded_locals', 'source.region_inline_helpers', 'source.inline_helpers',
                      'source.definition_moves', 'source.inline_parameter_barriers', 'source.self_assignment_barriers'],
    'parameter-copy': ['evidence.parameter_copies'],
    'degree': ['source.definition_moves', 'source.variable_splits', 'source.lifetime_splits', 'evidence.scalar_lifetimes',
               'source.loop_lifetimes', 'source.reuse_temporaries'],
    'expression-order': ['source.definition_moves', 'source.commutations', 'source.expression_trees', 'source.initialization_orders',
                         'evidence.attributed_inlines', 'source.add_trees', 'source.inline_parameter_barriers'],
    # retail defines the copied-to local directly (fn_10_111E8's `row` by the addi): the temp
    # must not exist, so the value is written straight into the local or the copy disappears
    'copy-coalesce': ['source.wrap_constant_pointers', 'source.constant_address_locals', 'source.split_inits',
                      'source.hoists', 'source.through_local', 'source.promoted_locals', 'source.reuse_temporaries',
                      'source.variable_splits'],
    # retail gives one of our webs two registers: the value lives in two variables
    'web-split': ['source.variable_splits', 'source.lifetime_splits', 'evidence.scalar_lifetimes',
                  'source.through_local', 'source.self_assignment_barriers'],
    # no override reproduced retail's colours: the zero-cost barriers (karamzov123, CC0) change
    # a web's class without changing code, then the read-only table qualifier (scheduling)
    'unresolved': ['source.self_assignment_barriers', 'source.inline_parameter_barriers',
                   'source.const_extern_tables', 'source.forwarded_locals', 'source.definition_moves'],
    'base-temp': [],
}


# ----------------------------------------------------------------------------- row mapping

def _pairs(check) -> Tuple[list, int]:
    """([(our row, retail text, our text)] for every aligned row whose texts agree once register
    names are masked (identical rows included), number of rows that are not renamings)."""
    lrows, rrows = getattr(check, '_rows', ([], []))
    out, other = [], 0
    for k in range(min(len(lrows), len(rrows))):
        lf, of = stuck._fmt(lrows[k]) or '', stuck._fmt(rrows[k]) or ''
        if not lf or not of:
            other += bool(lf or of)
            continue
        if fc._BRANCH.match(lf) and fc._BRANCH.match(of):
            continue
        # relocation symbols masked too: the oracle binds the unit's `@49`/`...rodata.0` to retail's
        if fc._RELOC.sub('S', fc._REG.sub('R', lf)) == fc._RELOC.sub('S', fc._REG.sub('R', of)):
            out.append((k, lf, of))
        else:
            other += 1
    return out, other


def retail_colors(check, pairs, cap: Path, idx: str, cls: str) -> Tuple[Dict[int, int], Dict[int, int], Dict[int, list]]:
    """({vreg: retail register}, {vreg: our register}, {vreg: [retail registers]}) over every
    mapped row of class CLS (`fixup_capture._targets` over all rows). A web retail gives two
    registers is a web retail splits (fn_1_82C70's `port`: `clrlwi. r0` then `mr r26`); it is
    left out of the replay search and reported in the third map."""
    fin = json.loads((cap / f'pcode-{idx}-final.json').read_text())
    sch = json.loads((cap / f'pcode-{idx}-scheduled.json').read_text())
    byaddr = {i['address']: i for b in sch['blocks'] for i in b['instructions']}
    final = [i for b in fin['blocks'] for i in b['instructions']]
    rrows = check._rows[1]
    ours = [k for k in range(len(rrows)) if stuck._fmt(rrows[k])]
    if abs(len(ours) - len(final)) > 2:
        return {}, {}, {}
    position = {row: n for n, row in enumerate(ours)}
    reg = re.compile(r'\b' + cls + r'(\d+)\b')
    opclass = {'r': 4, 'f': 3}[cls]
    want: Dict[int, int] = {}
    mine: Dict[int, int] = {}
    bad: Dict[int, set] = {}
    for k, retail, our in pairs:
        n = position.get(k)
        if n is None or n >= len(final):
            continue
        ro = [int(x) for x in reg.findall(our)]
        rr = [int(x) for x in reg.findall(retail)]
        if not ro or len(ro) != len(rr):
            continue
        ins = final[n]
        gops = [o for o in ins['operands'] if o.get('kind') == 0 and o.get('class') == opclass]
        sops = [o for o in byaddr.get(ins['address'], {'operands': []})['operands']
                if o.get('kind') == 0 and o.get('class') == opclass]
        if len(gops) != len(ro) or len(sops) != len(gops):
            continue
        for j, (a, b) in enumerate(zip(ro, rr)):
            v = sops[j]['reg']
            if gops[j]['reg'] != a or v < 32:
                continue
            if want.get(v, b) != b:
                bad.setdefault(v, {want[v]}).add(b)
            want.setdefault(v, b)
            mine.setdefault(v, a)
    for v in bad:
        want.pop(v, None)
    return want, mine, {v: sorted(rs) for v, rs in bad.items()}


def copies(cap: Path, idx: str, cls: str) -> Dict[int, set]:
    """{web: webs it is copied to or from} over the scheduled PCode's MR/FMR instructions."""
    try:
        sch = json.loads((cap / f'pcode-{idx}-scheduled.json').read_text())
    except (OSError, ValueError):
        return {}
    opclass = {'r': 4, 'f': 3}[cls]
    out: Dict[int, set] = {}
    for b in sch['blocks']:
        for i in b['instructions']:
            if (i.get('opcode_descriptor') or {}).get('mnemonic') not in ('MR', 'FMR'):
                continue
            regs = [o['reg'] for o in i['operands'] if o.get('kind') == 0 and o.get('class') == opclass]
            if len(regs) == 2 and min(regs) >= 32:
                out.setdefault(regs[0], set()).add(regs[1])
                out.setdefault(regs[1], set()).add(regs[0])
    return out


def _blocks(cap: Path, idx: str) -> List[int]:
    """Instruction count of every final PCode block (scheduling regions end at block edges)."""
    try:
        fin = json.loads((cap / f'pcode-{idx}-final.json').read_text())
    except (OSError, ValueError):
        return []
    return [len(b['instructions']) for b in fin['blocks']]


# ----------------------------------------------------------------------------- override search

def _compose(mapping: Dict[int, int], m: Dict[int, int]) -> Dict[int, int]:
    """original vreg -> current number, after relabelling the current numbers by M."""
    out = {k: m.get(v, v) for k, v in mapping.items()}
    for v, w in m.items():
        out.setdefault(v, w)
    return out


class _Search:
    """Replays of one captured class graph under hypotheses, scored against retail colours."""

    def __init__(self, sr, before, cls: str, want: Dict[int, int]):
        self.want = want
        self.base = sr.Graph(before, cls)
        self.replays = 0

    def run(self, hyps) -> Tuple[int, Dict[int, int]]:
        """(webs agreeing with retail, colours keyed by the ORIGINAL vreg numbers)."""
        g = self.base.relabel({})
        mapping: Dict[int, int] = {}
        for h in hyps:
            if h[0] == 'degree':
                v = mapping.get(h[1], h[1])
                g.degree0[v] = max(0, g.degree0[v] + h[2])
                continue
            a, to = mapping.get(h[1], h[1]), mapping.get(h[2], h[2])
            if h[0] == 'swap':
                m = {a: to, to: a}
            else:  # move: A takes number TO, the webs in between shift by one
                m = {v: v - 1 for v in range(a + 1, to + 1)} if a < to else {v: v + 1 for v in range(to, a)}
                m[a] = to
            g = g.relabel(m)
            mapping = _compose(mapping, m)
        order = g.simplify()
        color = g.select(order)
        self.replays += 1
        got = {v: color.get(mapping.get(v, v)) for v in self.want}
        return sum(1 for v, r in self.want.items() if got.get(v) == r), got


def _label(h) -> str:
    if h[0] == 'swap':
        return f'{h[1]}={h[2]}'
    if h[0] == 'move':
        return f'v{h[1]}->v{h[2]}'
    return f'{h[1]}:{h[2]:+d}'


def _cost(hyps) -> float:
    c = 0.0
    for h in hyps:
        c += 1 + abs(h[2]) / 16 if h[0] == 'degree' else 1.2 + abs(h[1] - h[2]) / 1000
    return c


def search_overrides(sr, before, cls: str, want: Dict[int, int], limit: int = MAX_REPLAYS) -> dict:
    """The smallest replay override reproducing every mapped retail colour of one class."""
    s = _Search(sr, before, cls, want)
    base_agree, base_colors = s.run([])
    targets = sorted(v for v in want if base_colors.get(v) != want[v])
    out = {'mapped': len(want), 'agree': base_agree, 'targets': targets, 'solutions': [], 'best': None,
           'best_agree': base_agree}
    if not targets:
        return out
    g = s.base
    g0 = g.relabel({})
    callee = {v for v, c in g0.select(g0.simplify()).items() if v >= 32 and c is not None and c >= 14}
    focus = set(targets) | callee
    for t in targets:          # the target's neighbours retail gives callee-saved registers
        focus |= {w for w in g.neighbors.get(t, []) if w in want and (want[w] or 0) >= 14}
    focus = {v for v in focus if v in g.nodes and v >= 32}
    singles = []
    for t in targets:
        for d in DEGREES:
            singles += [('degree', t, d), ('degree', t, -d)]
    for t in targets:
        for w in sorted(focus):
            if w != t:
                singles += [('swap', t, w), ('move', t, w)]
    for w in sorted(focus - set(targets)):
        for d in DEGREES[:5]:
            singles += [('degree', w, d), ('degree', w, -d)]
    full = len(want)
    scored = []
    for h in singles[:limit]:
        try:
            n, _ = s.run([h])
        except (KeyError, ValueError, IndexError):
            continue
        scored.append((n, [h]))
        if n == full:
            out['solutions'].append([h])
    # no single override: a beam over compositions (each step adds one single to the BEAM best
    # states; a second fix is usually a different web, fn_1_DF6AC's sqrt temp plus a shadow pair)
    frontier = [hs for n, hs in sorted(scored, key=lambda x: (-x[0], _cost(x[1])))[:BEAM] if n > base_agree]
    for _ in range(DEPTH - 1):
        if out['solutions'] or not frontier or s.replays >= MAX_TOTAL:
            break
        step = []
        for state in frontier:
            for h in singles:
                if h in state or s.replays >= MAX_TOTAL:
                    continue
                try:
                    n, _ = s.run(state + [h])
                except (KeyError, ValueError, IndexError):
                    continue
                step.append((n, state + [h]))
                if n == full:
                    out['solutions'].append(state + [h])
        scored += step
        best_now = max((n for n, _ in scored), default=base_agree)
        frontier = [hs for n, hs in sorted(step, key=lambda x: (-x[0], _cost(x[1])))[:BEAM] if n >= best_now - 1]
    out['solutions'].sort(key=_cost)
    if out['solutions']:
        out['best'], out['best_agree'] = out['solutions'][0], full
    elif scored:
        n, hs = max(scored, key=lambda x: (x[0], -_cost(x[1])))
        if n > base_agree:
            out['best'], out['best_agree'] = hs, n
    out['replays'] = s.replays
    return out


# ----------------------------------------------------------------------------- classification

def _web(rows, bases, v, cls):
    row = rows.get(v) or {}
    k = fc._class(row)
    if cls == 'r' and v in bases and k == 'temp':
        k = 'base'
    return {'vreg': v, 'name': row.get('name', '?'), 'class': k, 'region': row.get('region', '?'),
            'degree': row.get('degree')}


def classify(hyps, rows, bases, cls) -> Tuple[str, List[dict]]:
    """(class, webs involved) of the override HYPS (see the module docstring)."""
    if not hyps:
        return 'unresolved', []
    webs, kinds = [], []
    for h in hyps:
        a = _web(rows, bases, h[1], cls)
        webs.append(a)
        if h[0] == 'degree':
            kinds.append({'parameter': 'parameter-copy', 'base': 'base-temp'}.get(a['class'], 'degree'))
            continue
        b = _web(rows, bases, h[2], cls)
        webs.append(b)
        pair = {a['class'], b['class']}
        if 'base' in pair:
            kinds.append('base-temp')
        elif 'parameter' in pair:
            kinds.append('parameter-copy')
        elif pair == {'local'}:
            kinds.append('declaration-order')
        elif 'local' in pair:
            # the local is numbered up past a window web: an inline-region local; the window web
            # is numbered down past a local: a held/declared local (de-CSE, held result, carrier)
            local_up = (h[2] > h[1]) if a['class'] == 'local' else (h[1] > h[2])
            kinds.append('inline-region' if local_up else 'held-local')
        else:
            kinds.append('expression-order')
    return min(kinds, key=ORDER.index), webs


def _capture_compiler(p: Project, symbol: str, body: str, mw: str, flags: Optional[str], check):
    """(GC/1.3.2 check of BODY, note) when the capture compiler reproduces the recorded one's rows."""
    if mw == fc.CAPTURE_VERSION:
        return check, None
    import tempfile
    fc.CAPTURE_ROOT.mkdir(parents=True, exist_ok=True)
    with tempfile.NamedTemporaryFile('w', suffix='.c', delete=False, dir=str(fc.CAPTURE_ROOT)) as f:
        f.write(body)
    try:
        other = oracle.check(p, symbol, 0, source=Path(f.name), mw_version=fc.CAPTURE_VERSION, extra_cflags=flags)
    finally:
        os.unlink(f.name)
    if not other.ok:
        return None, None
    same = [stuck._fmt(r) for r in check._rows[1]] == [stuck._fmt(r) for r in other._rows[1]]
    return (other, f'{fc.CAPTURE_VERSION} gives the same rows as {mw}') if same else (None, None)


def diagnose(p: Project, symbol: str, path: Optional[Path] = None, mw: Optional[str] = None,
             flags: Optional[str] = None, run_capture: bool = True) -> dict:
    """One verdict row for SYMBOL's saved best body (or PATH under MW/FLAGS)."""
    from .ledger import Ledger
    sym = p.resolve(symbol)
    if sym is None:
        return {'symbol': symbol, 'class': 'error', 'note': 'unknown symbol'}
    if path is None:
        found = Ledger().ranked_local_attempt(p, symbol)
        if not found:
            return {'symbol': symbol, 'class': 'error', 'note': 'no saved body'}
        path = found[1]
        try:
            meta = json.loads(path.with_suffix('.json').read_text())
            mw, flags = meta.get('mw'), meta.get('flags')
        except (OSError, ValueError):
            pass
    mw = mw or oracle.module_flags(p, sym.module)[1]
    body = Path(path).read_text()
    out = {'symbol': symbol, 'body': str(path), 'sha256': fc._digest(body), 'mw': mw, 'flags': flags}
    check = oracle.check(p, symbol, 0, source=Path(path), mw_version=mw, extra_cflags=flags)
    if not check.ok:
        return {**out, 'class': 'error', 'note': 'does not compile: ' + (check.error or '')[-200:]}
    out.update(percent=round(check.percent, 3), rows=oracle.progress_rows(check))
    if check.matched:
        return {**out, 'class': 'matched'}
    pairs, other = _pairs(check)
    out['register_only'] = bool(fc.residual_rows(check)[0])
    out['structural_rows'] = other
    ccheck, note = _capture_compiler(p, symbol, body, mw, flags, check)
    if ccheck is None:
        return {**out, 'class': 'compiler', 'note': f'{mw} and {fc.CAPTURE_VERSION} differ for this body: no capture'}
    if note:
        out['capture_note'] = note
    cap = fc.capture(p, symbol, body, flags) if run_capture else fc.existing(symbol, body, flags)
    if cap is None:
        return {**out, 'class': 'error', 'note': 'capture unavailable'}
    idx = fc._capture_index(cap, symbol)
    out.update(capture=str(cap), index=idx, blocks=_blocks(cap, idx), classes={})
    sr, vm, _ = fc._recovery()
    try:
        bases = fc._base_temps(cap, idx)
    except (OSError, ValueError, KeyError, TypeError):
        bases = set()
    found = []
    for cls, rcls in (('r', 'gpr'), ('f', 'fpr')):
        try:
            before, after = sr.load(cap, idx, rcls)
        except FileNotFoundError:
            continue
        want, mine, split = retail_colors(ccheck, pairs, cap, idx, cls)
        if not want and not split:
            continue
        g = sr.Graph(before, rcls)
        replayed = g.select(g.simplify())
        captured = sr.captured_colors(after) if after else replayed
        res = search_overrides(sr, before, rcls, want)
        if not res['targets'] and not split:
            continue
        rows = {r['vreg']: r for r in vm.rows(cap, idx, rcls)}
        solved = res['best'] is not None and res['best_agree'] == res['mapped']
        kind, webs = classify(res['best'] if solved else None, rows, bases, cls)
        partial = classify(res['best'], rows, bases, cls)[0] if (not solved and res['best']) else None
        if not solved and res['best']:
            webs = classify(res['best'], rows, bases, cls)[1]
        # a target whose retail register is its copy partner's: retail coalesced the copy
        moved = copies(cap, idx, cls)
        merged = [(t, w) for t in res['targets'] for w in moved.get(t, ()) if want.get(w) == want[t]]
        if merged and not solved:
            kind, webs = 'copy-coalesce', [_web(rows, bases, v, cls) for pair in merged for v in pair]
        if split and (not res['targets'] or not solved):
            kind = 'web-split' if kind == 'unresolved' or not res['targets'] else min(kind, 'web-split', key=ORDER.index)
            webs = webs + [dict(_web(rows, bases, v, cls), retail=[f'{cls}{r}' for r in rs]) for v, rs in split.items()]
        out['classes'][rcls] = {
            'replay_exact': all(replayed.get(v) == c for v, c in captured.items() if v >= 32),
            'mapped': res['mapped'], 'agree': res['agree'],
            'targets': [dict(_web(rows, bases, v, cls), want=f'{cls}{want[v]}', got=f'{cls}{mine.get(v)}')
                        for v in res['targets']],
            'override': ' '.join(_label(h) for h in res['best'] or []), 'override_agree': res['best_agree'],
            'solutions': [' '.join(_label(h) for h in sol) for sol in res['solutions'][:6]],
            'class': kind, 'partial_class': partial, 'webs': webs, 'replays': res.get('replays')}
        found.append(kind)
    if not found:
        out['class'] = 'structural' if other else 'unresolved'
        out['note'] = 'no differing register row maps to a captured web'
        return out
    out['class'] = min(found, key=ORDER.index)
    if other:
        out['note'] = f'{other} rows are not register renamings; the class covers the register rows'
    out['families'] = directed_families(out)
    return out


# ----------------------------------------------------------------------------- consumers

def directed_families(verdict: dict) -> List[str]:
    """Engine family keys of a verdict: the function's class first, then each register file's."""
    classes = [verdict.get('class')]
    for c in verdict.get('classes', {}).values():
        classes += [c.get('class'), c.get('partial_class')]
    out: List[str] = []
    for k in classes:
        for f in CLASS_FAMILIES.get(k or '', []):
            if f not in out:
                out.append(f)
    return out


def target_names(verdict: dict) -> List[str]:
    """C names of the target and involved webs (compiler @N objects and temporaries left out)."""
    names: List[str] = []
    for c in verdict.get('classes', {}).values():
        for w in c.get('targets', []) + c.get('webs', []):
            n = w.get('name') or '?'
            if n != '?' and not n.startswith('@') and n not in names:
                names.append(n)
    return names


def load_verdicts() -> dict:
    try:
        return json.loads(VERDICTS.read_text())
    except (OSError, ValueError):
        return {}


def verdict_for(symbol: str, body: str) -> Optional[dict]:
    """SYMBOL's verdict for exactly BODY, else its verdict marked `stale` (the class still picks
    the families of a derived body; the names may have moved)."""
    v = load_verdicts().get(symbol)
    if not v or v.get('class') in (None, 'error', 'matched', 'compiler', 'structural', 'base-temp'):
        return None
    # families follow the current CLASS_FAMILIES, not the ones saved with the row
    v = dict(v, families=directed_families(v))
    return v if v.get('sha256') == fc._digest(body) else dict(v, stale=True)


def save_verdicts(rows: List[dict]) -> None:
    data = load_verdicts()
    for r in rows:
        data[r['symbol']] = r
    VERDICTS.parent.mkdir(parents=True, exist_ok=True)
    write_atomic(VERDICTS, json.dumps(data, indent=1))


def prioritise(candidates: List[Tuple[str, str]], body: str, names: List[str]) -> List[Tuple[str, str]]:
    """Candidates whose label or changed lines name a target web first (stable otherwise)."""
    if not names:
        return list(candidates)
    rx = re.compile(r'\b(' + '|'.join(map(re.escape, names)) + r')\b')
    old = set(body.splitlines())

    def miss(c):
        label, text = c
        if rx.search(label):
            return 0
        return 0 if any(rx.search(ln) for ln in text.splitlines() if ln not in old) else 1
    return sorted(candidates, key=miss)


def command(p: Project, symbols: List[str], run_capture: bool = True) -> List[dict]:
    rows = []
    for s in symbols:
        try:
            v = diagnose(p, s, run_capture=run_capture)
        except Exception as error:  # one unreadable capture must not lose the batch
            v = {'symbol': s, 'class': 'error', 'note': f'{type(error).__name__}: {error}'[:300]}
        rows.append(v)
        save_verdicts([v])
        detail = '; '.join(f"{k} {c['class']} [{c['override'] or '-'}] {c['override_agree']}/{c['mapped']} "
                           + ','.join(f"{t['name']}:{t['got']}->{t['want']}" for t in c['targets'][:4])
                           for k, c in v.get('classes', {}).items())
        print(f"{s:16} {v.get('percent', '-'):>7} rows {v.get('rows', '-')!s:>4} {v['class']:17} "
              f"{detail or v.get('note', '')}", flush=True)
    counts: Dict[str, int] = {}
    for v in rows:
        counts[v['class']] = counts.get(v['class'], 0) + 1
    print('classes:', ', '.join(f'{k} {n}' for k, n in sorted(counts.items(), key=lambda x: -x[1])))
    return rows
