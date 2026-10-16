"""Capture-driven allocation verdicts and proposals for register-only residuals.

A near miss at 99%+ whose remaining rows differ only by register numbers is decided by MWCC's
coloring order, which the GC/1.3.2 allocator capture (`tools/capture/capture132.sh`) exposes
exactly: every residual row maps to a web, every web to a numbering class, and the replay
(`tools/capture/recovery/simplify_replay.py`) tells which web took the register retail gives
the target. This module turns that into (1) a verdict the engine reports instead of silently
exhausting declaration orders, and (2) candidates chosen by the blocker's class:

  blocker is a declared local          -> the solver's declaration order (source_rank_solver)
  blocker is a compiler shadow (@N)
    numbered above every local         -> the indexed access it strength-reduces becomes a
                                          declared pointer local (the inverse of
                                          `induction_indexing`), at several declaration positions
  target is a parameter                -> `parameter_copies` (fixup_evidence) already covers it
  target is a lowering temporary       -> expression order (reported; no permutation can move it)

A capture is only run from the per-symbol engine (`fzgx fixup SYMBOL`) when the WSL/Lima guest
is present; `fzgx sweep` consumes captures that already exist under `.fzgx/capture/SYMBOL/`.
Captures are keyed by the body's sha256 (`body.sha256` next to the snapshots).
"""
from __future__ import annotations

import hashlib
import json
import os
import re
import shutil
import subprocess
import sys
from pathlib import Path
from typing import Dict, List, Optional, Tuple

from . import oracle, stuck
from .project import ROOT, Project

CAPTURE_ROOT = Path(os.environ.get('FZGX_CAPTURE_DIR', str(ROOT / '.fzgx' / 'capture')))
CAPTURE_SCRIPT = ROOT / 'tools' / 'capture' / 'capture132.sh'
RECOVERY = ROOT / 'tools' / 'capture' / 'recovery'
CAPTURE_VERSION = 'GC/1.3.2'
MIN_PERCENT = 98.9
CALLEE_SAVED = {'r': range(14, 32), 'f': range(14, 32)}


def _recovery():
    if str(RECOVERY) not in sys.path:
        sys.path.insert(0, str(RECOVERY))
    import simplify_replay, vreg_map, source_rank_solver  # noqa: E402
    return simplify_replay, vreg_map, source_rank_solver


def available() -> bool:
    """Whether the capture guest can be driven from this host (WSL on Windows, Lima elsewhere)."""
    return bool(shutil.which('wsl.exe') or shutil.which('limactl')) and CAPTURE_SCRIPT.exists()


def _digest(body: str) -> str:
    return hashlib.sha256(body.encode()).hexdigest()


def _capture_index(cap: Path, symbol: str) -> Optional[str]:
    f = cap / 'functions.json'
    if f.exists():
        for idx, name in json.loads(f.read_text()).items():
            if name == symbol and (cap / f'pcode-{idx}-final.json').exists():
                return idx
    finals = sorted(cap.glob('pcode-*-final.json'))
    return finals[-1].name.split('-')[1] if finals else None


def existing(symbol: str, body: str) -> Optional[Path]:
    """The capture directory of SYMBOL when it holds a capture of exactly this body."""
    cap = CAPTURE_ROOT / symbol
    if _capture_index(cap, symbol) is None:
        return None
    stamp = cap / 'body.sha256'
    src = cap / f'{symbol}.c'
    if stamp.exists():
        return cap if stamp.read_text().strip() == _digest(body) else None
    if src.exists() and src.read_text(errors='replace') == body:
        stamp.write_text(_digest(body) + '\n')
        return cap
    return None


def capture(p: Project, symbol: str, body: str, flags: Optional[str], timeout: int = 420) -> Optional[Path]:
    """Run the GC/1.3.2 capture of BODY (about 15 s) unless one of this body exists."""
    cap = existing(symbol, body)
    if cap is not None or not available():
        return cap
    module = p.resolve(symbol).module
    scratch = ROOT / '.fzgx' / 'capture' / f'{symbol}.body.c'
    scratch.parent.mkdir(parents=True, exist_ok=True)
    # one capture at a time: every capture drives the guest's single gdb port (1234), and the
    # engine generates candidates in forked workers; a second caller skips rather than collides
    lock = scratch.parent / '.capture.lock'
    try:
        fd = os.open(str(lock), os.O_CREAT | os.O_EXCL | os.O_WRONLY)
    except OSError:
        return None
    os.close(fd)
    scratch.write_text(body)
    env = dict(os.environ, EXTRA_FLAGS=flags or '')
    try:
        subprocess.run(['sh', str(CAPTURE_SCRIPT), symbol, str(scratch), module], cwd=str(ROOT),
                       env=env, capture_output=True, text=True, timeout=timeout)
    except (subprocess.TimeoutExpired, OSError):
        return None
    finally:
        scratch.unlink(missing_ok=True)
        lock.unlink(missing_ok=True)
    cap = CAPTURE_ROOT / symbol
    if _capture_index(cap, symbol) is None:
        return None
    (cap / 'body.sha256').write_text(_digest(body) + '\n')
    return cap


_REG = re.compile(r'\b([rf])(\d+)\b')
_BRANCH = re.compile(r'^(b\w*)\s+(?:0x[0-9a-fA-F]+|\S+)$')


def residual_rows(check) -> Tuple[Optional[list], set]:
    """([(ours row, retail text, ours text)], register classes) when every differing row is a
    register renaming. Unlike `fixup_evidence._register_residual` this tolerates branch rows
    that differ only by their printed target (retail's absolute address) and one adjacent pair
    of swapped rows (the scheduler follows the allocation), so a capture verdict still names
    the webs behind fn_1_11B4E4 / fn_1_7B558-shaped residuals."""
    lrows, rrows = getattr(check, '_rows', ([], []))
    accepted = getattr(check, '_accepted_rows', set()) or set()
    out, classes = [], set()
    k, n = 0, min(len(lrows), len(rrows))
    while k < n:
        a, b = lrows[k], rrows[k]
        if k in accepted or ((a.get('diff_kind') or 'DIFF_NONE') == 'DIFF_NONE'
                             and (b.get('diff_kind') or 'DIFF_NONE') == 'DIFF_NONE'):
            k += 1; continue
        lf, of = stuck._fmt(a), stuck._fmt(b)
        if lf == of or not lf or not of:
            k += 1; continue
        bl, bo = _BRANCH.match(lf), _BRANCH.match(of)
        if bl and bo and bl.group(1) == bo.group(1):
            k += 1; continue
        if _REG.sub('R', lf) == _REG.sub('R', of):
            pairs = [(k, lf, of)]
        elif k + 1 < n and _REG.sub('R', lf) == _REG.sub('R', stuck._fmt(rrows[k + 1]) or '')                 and _REG.sub('R', stuck._fmt(lrows[k + 1]) or '') == _REG.sub('R', of):
            pairs = [(k + 1, lf, stuck._fmt(rrows[k + 1])), (k, stuck._fmt(lrows[k + 1]), of)]
            k += 1
        else:
            return None, set()
        for _, x, y in pairs:
            for u, v in zip(_REG.findall(x), _REG.findall(y)):
                if u != v:
                    classes.add(u[0])
        out.extend(pairs)
        k += 1
    return (out if out else None), classes


def eligible(check, mw: Optional[str], percent: Optional[float] = None) -> Tuple[Optional[list], set]:
    """(residual rows, register classes) when the residual is register-only at MIN_PERCENT+
    under the capture compiler; (None, set()) otherwise."""
    if (mw or '') != CAPTURE_VERSION or not getattr(check, 'ok', False):
        return None, set()
    pct = check.percent if percent is None else percent
    if pct < MIN_PERCENT:
        return None, set()
    return residual_rows(check)


# ----------------------------------------------------------------------------- analysis

def _webs(sr, vm, cap: Path, idx: str, cls: str):
    before, after = sr.load(cap, idx, cls)
    rows = {r['vreg']: r for r in vm.rows(cap, idx, cls)}
    graph = sr.Graph(before, cls)
    order = graph.simplify()
    color = graph.select(order)
    return before, rows, graph, order, color


def _targets(check, residual, cap: Path, idx: str, cls: str) -> Dict[int, int]:
    """{vreg: retail register} for the residual rows of one class, aligned 1:1 with the final
    PCode (autotarget.py's mapping: object row k is final instruction k)."""
    fin = json.loads((cap / f'pcode-{idx}-final.json').read_text())
    sch = json.loads((cap / f'pcode-{idx}-scheduled.json').read_text())
    byaddr = {i['address']: i for b in sch['blocks'] for i in b['instructions']}
    final = [i for b in fin['blocks'] for i in b['instructions']]
    lrows, rrows = check._rows
    ours = [(k, stuck._fmt(rrows[k])) for k in range(len(rrows)) if stuck._fmt(rrows[k])]
    if abs(len(ours) - len(final)) > 2:
        return {}
    position = {row: n for n, (row, _) in enumerate(ours)}
    reg = re.compile(r'\b' + cls + r'(\d+)\b')
    out: Dict[int, int] = {}
    for k, retail, mine in residual:
        n = position.get(k)
        if n is None or n >= len(final):
            continue
        ro = [int(x) for x in reg.findall(mine)]
        rr = [int(x) for x in reg.findall(retail)]
        if len(ro) != len(rr):
            continue
        ins = final[n]
        gops = [o for o in ins['operands'] if o.get('kind') == 0]
        sops = [o for o in byaddr.get(ins['address'], {'operands': []})['operands'] if o.get('kind') == 0]
        if len(gops) != len(ro) or len(sops) != len(gops):
            continue
        for j, (a, b) in enumerate(zip(ro, rr)):
            if a != b and gops[j]['reg'] == a:
                v = sops[j]['reg']
                if out.get(v, b) == b:
                    out[v] = b
    return out


def _class(row) -> str:
    if not row:
        return 'temp'
    c = row['cluster']
    if c == 'param':
        return 'parameter'
    if c == 'fn-scope':
        return 'local'
    if c == 'compiler':
        return 'shadow'
    return 'temp'


def analyse(check, residual, classes, cap: Path, symbol: str) -> Optional[dict]:
    """Classify every target web and the web that blocks its retail register.

    For a target T (coloured G, retail R): if an interfering web coloured before T holds R the
    blocker is that occupant; else if T took a claimed register G below... the web that first
    claimed G before T is the blocker (T would have claimed R itself otherwise); else R lies
    below every claimed register at T's turn ('needs earlier claims')."""
    sr, vm, _ = _recovery()
    idx = _capture_index(cap, symbol)
    if idx is None:
        return None
    out = {'symbol': symbol, 'capture': str(cap), 'index': idx, 'targets': []}
    for cls in sorted(classes):
        rcls = {'r': 'gpr', 'f': 'fpr'}[cls]
        try:
            before, rows, graph, order, color = _webs(sr, vm, cap, idx, rcls)
            targets = _targets(check, residual, cap, idx, cls)
        except (FileNotFoundError, KeyError, ValueError):
            continue
        # claim history: register -> first web claiming it, and each web's rank in the order
        rank = {v: n for n, v in enumerate(order)}
        claimed_by: Dict[int, int] = {}
        for v in order:
            r = color.get(v)
            if r is not None and r in CALLEE_SAVED[cls] and r not in claimed_by:
                claimed_by[r] = v
        for v, want in sorted(targets.items()):
            got = color.get(v)
            row = rows.get(v, {})
            t = {'vreg': v, 'name': row.get('name', '?'), 'class': _class(row), 'region': row.get('region', '?'),
                 'degree': row.get('degree'), 'want': f'{cls}{want}', 'got': f'{cls}{got}', 'blockers': []}
            if got == want or v not in rank:
                out['targets'].append(t)
                continue
            before_me = [w for w in graph.neighbors.get(v, []) if w in rank and rank[w] < rank[v]]
            occupants = [w for w in before_me if color.get(w) == want]
            if occupants:
                t['blockers'] = [{'vreg': w, 'name': rows.get(w, {}).get('name', '?'), 'class': _class(rows.get(w)),
                                  'region': rows.get(w, {}).get('region', '?'), 'role': 'holds ' + t['want']}
                                 for w in occupants]
            elif got in claimed_by and rank.get(claimed_by[got], 1 << 30) < rank[v] and want in claimed_by \
                    and rank[claimed_by[want]] < rank[v]:
                w = claimed_by[got]
                t['blockers'] = [{'vreg': w, 'name': rows.get(w, {}).get('name', '?'), 'class': _class(rows.get(w)),
                                  'region': rows.get(w, {}).get('region', '?'), 'role': f'claimed {t["got"]} first'}]
            else:
                role = (f'{t["want"]} free at its turn: numbered later than retail' if want not in CALLEE_SAVED[cls]
                        else f'{t["want"]} unclaimed at its turn')
                t['blockers'] = [{'vreg': None, 'name': '-', 'class': 'order', 'region': '-', 'role': role}]
            out['targets'].append(t)
    if not out['targets']:
        return None
    out['verdict'] = verdict_text(out)
    return out


def verdict_text(a: dict) -> str:
    parts = []
    for t in a['targets']:
        if t['want'] == t['got']:
            continue
        who = ', '.join(f"{b['name']} ({b['class']} {b['region']}, {b['role']})" for b in t['blockers']) or 'none'
        parts.append(f"{t['name']} ({t['class']} v{t['vreg']}) wants {t['want']} got {t['got']}: {who}")
    kinds = {b['class'] for t in a['targets'] for b in t['blockers']} | {t['class'] for t in a['targets'] if t['want'] != t['got']}
    if kinds <= {'local', 'order'}:
        hint = 'declaration order (solver)'
    elif 'shadow' in kinds:
        # measured 2026-10-15 (fn_1_1188CC, fn_1_11B4E4, fn_1_7B558, fn_3_20748 captures): compiler
        # objects are numbered above every local in reverse creation order (loop order), split
        # regions of a reused counter are created after every induction shadow, and a declared
        # pointer removes the shadow but shifts the degree phase of K-boundary webs; a local can
        # only pass a shadow when the shadow's access is spelled through a declared pointer local
        hint = ('structural: shadow webs are numbered above every local in reverse creation order; '
                'declaration order, counter reuse and fresh counters cannot pass one (only a declared '
                'pointer local replacing the indexed access, at the cost of the neighbours\' degree phase)')
    elif 'temp' in kinds:
        hint = 'expression/statement order (lowering temporary)'
    elif 'parameter' in kinds:
        hint = 'parameter copy'
    else:
        hint = 'structural'
    return '; '.join(parts) + f' => {hint}'


# ----------------------------------------------------------------------------- proposals

def _reorder(body: str, name: str, wanted: List[str]) -> Optional[str]:
    """Move the leading local declarations named in WANTED (first declared first) behind the others."""
    from . import fixup_source as fs
    span = fs._function_body_span(body, name)
    if not span:
        return None
    locs = fs._locals(body, span)
    if not locs:
        return None
    decl = {l[3]: body[l[0]:l[1]] for l in locs}
    if any(n not in decl for n in wanted):
        return None
    others = [l[3] for l in locs if l[3] not in wanted]
    new = ''.join(decl[n] for n in others) + ''.join(decl[n] for n in wanted)
    out = body[:locs[0][0]] + new + body[locs[-1][1]:]
    return out if out != body else None


def solver_orders(a: dict, body: str, name: str, limit: int = 3) -> List[Tuple[str, str]]:
    """Declaration orders the solver finds for targets whose blockers are locals."""
    sr, vm, solver = _recovery()
    out = []
    for cls in ('r', 'f'):
        targets = {t['vreg']: int(t['want'][1:]) for t in a['targets'] if t['want'][0] == cls and t['want'] != t['got']
                   and t['class'] == 'local' and all(b['class'] in ('local', 'order') for b in t['blockers'])}
        if not targets:
            continue
        rcls = {'r': 'gpr', 'f': 'fpr'}[cls]
        try:
            res = solver.solve(Path(a['capture']), a['index'], targets, rcls, samples=800, max_permutations=5000)
            names = {r['vreg']: r['name'] for r in vm.rows(Path(a['capture']), a['index'], rcls)}
        except (FileNotFoundError, KeyError, ValueError):
            continue
        for neg, moved, changed, ranked, _ in res['best'][:limit]:
            if -neg < len(targets) or not moved:
                continue
            wanted = [names[v] for v in reversed(ranked) if v in names]
            text = _reorder(body, name, wanted)
            if text:
                out.append((f'capture: solver order {", ".join(wanted)}', text))
    return out


def _loop_body(text: str, start: int) -> Tuple[int, int]:
    depth, k = 0, start
    while k < len(text):
        if text[k] == '{':
            depth += 1
        elif text[k] == '}':
            depth -= 1
            if depth == 0:
                return start + 1, k
        k += 1
    return start + 1, len(text)


def pointer_locals(body: str, name: str, positions: int = 3) -> List[Tuple[str, str]]:
    """The inverse of `induction_indexing`: an indexed access `base[c].m` / `base->arr[c]` inside a
    counted loop over `c` becomes a declared pointer local stepped with the counter, so the
    induction shadow MWCC numbers above every local becomes a pass-1 local whose rank the
    declaration order controls. Each rewrite is tried at a few declaration positions."""
    from . import fixup_source as fs
    span = fs._function_body_span(body, name)
    if not span:
        return []
    locs = fs._locals(body, span)
    if not locs:
        return []
    inner = body[span[1]:span[2]]
    out = []
    used = set(re.findall(r'\b\w+\b', body))
    for loop in re.finditer(r'(?m)^([ \t]*)for\s*\(([^\n]*)\)\s*\{', inner):
        header = loop.group(2)
        m = re.search(r'\b(\w+)\s*\+\+', header)
        if not m:
            continue
        counter = m.group(1)
        b0, b1 = _loop_body(inner, loop.end() - 1)
        lbody = inner[b0:b1]
        # element accesses by the counter: base[counter] (member or whole element)
        shapes = {}
        # a bare local base only: `obj->nodes[c]` names the member, not the local `nodes`
        # (fn_1_1262A4: rewriting it gave `obj->(*nodes_p)`, three uncompilable candidates)
        for am in re.finditer(rf'(?<![\w.>])(\w+)\s*\[\s*{re.escape(counter)}\s*\]', lbody):
            shapes.setdefault(am.group(1), []).append(am)
        for am in re.finditer(rf'\b(\w+)->(\w+)\s*\[\s*{re.escape(counter)}\s*\]', lbody):
            shapes.setdefault(am.group(1) + '->' + am.group(2), []).append(am)
        for base, sites in shapes.items():
            if '->' in base:
                obj, member = base.split('->')
                decl = next((l for l in locs if l[3] == obj), None)
                if not decl or re.search(rf'\b{re.escape(obj)}\s*\[', lbody):
                    continue
                ptype = None
                # the member's element type from the body's struct text
                sm = re.search(rf'\b([\w ]+?\s*\**)\s*{re.escape(member)}\s*\[', body)
                if sm:
                    ptype = sm.group(1).strip() + ' *'
                init = f'{obj}->{member}'
            else:
                decl = next((l for l in locs if l[3] == base), None)
                if not decl or '*' not in decl[2] + '' or decl[4]:
                    continue
                ptype = decl[2].strip()
                if not ptype.endswith('*'):
                    ptype += ' *'
                init = base
            if not ptype:
                continue
            pname = f'{base.replace("->", "_")}_p'
            if pname in used:
                continue
            # the counter starts at an expression in the header: pointer starts at base + start
            sm = re.search(rf'\b{re.escape(counter)}\s*=\s*([^,;]+)', header)
            start = sm.group(1).strip() if sm else '0'
            if not re.fullmatch(r'\w+', start):
                continue
            init_text = init if start == '0' else f'{init} + {start}'
            new_body = lbody
            for am in sorted(sites, key=lambda x: x.start(), reverse=True):
                end = am.end()
                follow = new_body[end:end + 1]
                repl = f'{pname}->' if follow == '.' else f'(*{pname})'
                cut = end + 1 if follow == '.' else end
                new_body = new_body[:am.start()] + repl + new_body[cut:]
            new_header = header.replace(m.group(0), f'{m.group(0)}, {pname}++', 1)
            new_header = re.sub(rf'(\b{re.escape(counter)}\s*=\s*[^,;]+)', rf'\1, {pname} = {init_text}', new_header, count=1)
            if new_header == header:
                continue
            new_inner = inner[:loop.start(2)] + new_header + inner[loop.end(2):b0] + new_body + inner[b1:]
            text = body[:span[1]] + new_inner + body[span[2]:]
            indent = re.match(r'[ \t]*', body[locs[0][0]:]).group(0)
            line = f'{indent}{ptype} {pname};\n'
            slots = [('first', locs[0][0]), ('last', locs[-1][1])]
            mid = len(locs) // 2
            if len(locs) > 2:
                slots.append(('middle', locs[mid][1]))
            for label, at in slots[:positions]:
                cand = text[:at] + line + text[at:]
                out.append((f'capture: pointer local {pname} for {base}[{counter}] declared {label}', cand))
    return out


def proposals(p: Project, symbol: str, body: str, check, mw: Optional[str], flags: Optional[str],
              run_capture: bool = False, emit=None) -> List[Tuple[str, str]]:
    """Candidates from the capture verdict; `emit` receives the verdict as a stage event."""
    residual, classes = eligible(check, mw)
    if not residual:
        return []
    cap = capture(p, symbol, body, flags) if run_capture else existing(symbol, body)
    if cap is None:
        return []
    try:
        a = analyse(check, residual, classes, cap, symbol)
    except Exception as error:  # the capture tools read unversioned snapshots: never fail the round
        if emit:
            emit({'stage': 'capture-verdict', 'symbol': symbol, 'error': str(error)[:200]})
        return []
    if not a:
        return []
    if emit:
        emit({'stage': 'capture-verdict', 'symbol': symbol, 'verdict': a['verdict'], 'targets': a['targets']})
    name = p.resolve(symbol).name
    out: List[Tuple[str, str]] = []
    blocker_classes = {b['class'] for t in a['targets'] for b in t['blockers']}
    target_classes = {t['class'] for t in a['targets'] if t['want'] != t['got']}
    if 'local' in target_classes:
        out += solver_orders(a, body, name)
    if 'shadow' in blocker_classes or 'shadow' in target_classes:
        out += pointer_locals(body, name)
    return out
