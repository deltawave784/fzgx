"""What earlier sessions already measured on this seed, read from the check archive.

Every checked body stays in `.fzgx/checks/<key>/NNN.c` with its scores in `index.jsonl`, but a
session only ever saw the best body and its diff. With the pool down to the same ~165 rows per
batch, sessions kept spending their plateau on known states: in codex-20261105m, of 1,116 compiled
edits 297 reproduced the seed's own diff, 213 a state of the same session and 367 a state of an
earlier session; 239 (1.6 per session) produced anything new, against 611 of 1,197 twelve batches
earlier. Each repeat costs a compile, a model turn and one step of the plateau stop.

`section` writes those measurements into the claim context as edits against the current seed;
`seen_before` reports a repeat in the check that made it. Both are advisory. Nothing here decides
what matches, what is saved or when a session stops.
"""
from __future__ import annotations

import difflib
import hashlib
import json
import time
from pathlib import Path
from typing import Dict, List, Optional, Tuple

from .project import STATE_DIR

MAX_BODIES = 400       # newest archived checks read per function
SMALL = 10             # changed lines beyond which a body is a rewrite, not one lever
DEADLINE = 4.0         # seconds of diffing per section; the claim must not wait on history
SESSION_GAP = 900      # seconds between two checks of one session (for per-edit deltas)
CLIP = 170             # characters per displayed line of an edit
CONTEXT = 24           # unchanged characters kept on each side of a displayed change
LIMITS = {'better': 1500, 'none': 2800, 'worse': 1700}   # characters per group in the section
SAME_PERCENT = 0.0005  # objdiff percent differences below this are the same state
SAME_ADJUSTED = 0.005

Lever = Tuple[Tuple[Tuple[str, ...], Tuple[str, ...]], ...]


def _dir(key: str) -> Path:
    return STATE_DIR / 'checks' / key.replace(':', '__')


def _entries(key: str, before: Optional[float] = None) -> List[dict]:
    """The newest archived checks that compiled or failed, oldest first, with their file."""
    directory = _dir(key)
    out: Dict[int, dict] = {}
    try:
        with (directory / 'index.jsonl').open() as handle:
            for line in handle:
                try:
                    entry = json.loads(line)
                except ValueError:
                    continue
                if before is None or (entry.get('t') or 0) < before:
                    out[entry.get('n')] = entry
    except OSError:
        return []
    rows = [out[n] for n in sorted(k for k in out if isinstance(k, int))][-MAX_BODIES:]
    for entry in rows:
        entry['path'] = directory / f"{entry['n']:03d}.c"
    return rows


def _norm(text: str) -> List[str]:
    return [' '.join(line.split()) for line in text.splitlines() if line.strip()]


def lever(old: List[str], new: List[str]) -> Lever:
    """The changed hunks between two normalized bodies, with whitespace removed from the key."""
    start = 0
    limit = min(len(old), len(new))
    while start < limit and old[start] == new[start]:
        start += 1
    end = 0
    while end < limit - start and old[-1 - end] == new[-1 - end]:
        end += 1
    a = old[start:len(old) - end]
    b = new[start:len(new) - end]
    if not a and not b:
        return ()
    matcher = difflib.SequenceMatcher(None, a, b, autojunk=False)
    return tuple((tuple(a[i1:i2]), tuple(b[j1:j2]))
                 for tag, i1, i2, j1, j2 in matcher.get_opcodes() if tag != 'equal')


def _size(item: Lever) -> int:
    return sum(len(removed) + len(added) for removed, added in item)


def _key(item: Lever) -> str:
    return repr(tuple((tuple(''.join(x.split()) for x in removed), tuple(''.join(x.split()) for x in added))
                      for removed, added in item))


def _clip(text: str) -> str:
    return text if len(text) <= CLIP else text[:CLIP - 3] + '...'


def _focus(old: str, new: str) -> Tuple[str, str]:
    """Both sides of one edit without the long text they share: a macro's parameter list can
    fill the line while the edit is one argument."""
    start = 0
    limit = min(len(old), len(new))
    while start < limit and old[start] == new[start]:
        start += 1
    end = 0
    while end < limit - start and old[-1 - end] == new[-1 - end]:
        end += 1
    left = max(0, start - CONTEXT)
    right = max(0, end - CONTEXT)
    head = '...' if left else ''
    tail = '...' if right else ''
    return (head + old[left:len(old) - right] + tail, head + new[left:len(new) - right] + tail)


def _show(item: Lever) -> str:
    hunks = []
    for removed, added in item:
        old = ' '.join(removed)
        new = ' '.join(added)
        if not old:
            hunks.append(f'add `{_clip(new)}`')
        elif not new:
            hunks.append(f'remove `{_clip(old)}`')
        else:
            old, new = _focus(old, new)
            hunks.append(f'`{_clip(old)}` -> `{_clip(new)}`')
    return '; '.join(hunks)


def _same(a: dict, b: dict) -> bool:
    """Equal code when both checks recorded it; older archive rows only have their scores."""
    if a.get('state') and b.get('state'):
        return a['state'] == b['state']
    return (abs((a.get('percent') or 0) - (b.get('percent') or 0)) < SAME_PERCENT
            and abs((a.get('adjusted') or 0) - (b.get('adjusted') or 0)) < SAME_ADJUSTED)


def _compiler(entry: dict) -> Tuple[Optional[str], Optional[str]]:
    return entry.get('mw'), entry.get('flags') or None


def measure(key: str, seed: str, before: Optional[float] = None) -> Optional[dict]:
    """Every small edit measured against `seed` under the seed's compiler, by effect.

    `levers` maps an edit's key to its class (`none`, `better`, `worse`, `failed`), its text, its
    score and how many checks made it. Direct: the archived body differs from the seed by that
    edit. Delta: consecutive checks of one session with equal scores, whose removed lines are in
    the seed: that step changed nothing, whatever else the session had changed by then."""
    entries = _entries(key, before)
    if not entries:
        return None
    seed_digest = hashlib.sha256(seed.encode()).hexdigest()
    seed_lines = _norm(seed)
    seed_set = set(seed_lines)
    bodies: Dict[int, Tuple[str, List[str]]] = {}
    state = None
    for entry in entries:
        try:
            text = entry['path'].read_text(errors='replace')
        except OSError:
            continue
        digest = hashlib.sha256(text.encode()).hexdigest()
        bodies[entry['n']] = (digest, _norm(text))
        if entry.get('ok') and (digest == seed_digest or bodies[entry['n']][1] == seed_lines):
            state = entry
    if state is None:
        return None
    compiler = _compiler(state)
    deadline = time.monotonic() + DEADLINE
    levers: Dict[str, dict] = {}
    probes: Dict[Tuple, dict] = {}
    seen_bodies = set()
    rewrites = 0

    def note(item: Lever, kind: str, entry: dict) -> None:
        slot = levers.setdefault(_key(item), {'kind': kind, 'lever': item, 'percent': entry.get('percent'),
                                              'adjusted': entry.get('adjusted'), 'count': 0, 't': 0})
        slot['count'] += 1
        slot['t'] = max(slot['t'], entry.get('t') or 0)

    previous = None
    for entry in entries:
        body = bodies.get(entry['n'])
        if body is None:
            previous = None
            continue
        digest, lines = body
        if time.monotonic() > deadline:
            break
        if lines == seed_lines:
            if _compiler(entry) != compiler and entry.get('ok'):
                probes[_compiler(entry)] = entry
            previous = entry
            continue
        same_compiler = _compiler(entry) == compiler
        if same_compiler and digest not in seen_bodies:
            seen_bodies.add(digest)
            item = lever(seed_lines, lines)
            if _size(item) > SMALL:
                rewrites += 1
            elif not entry.get('ok'):
                note(item, 'failed', entry)
            elif _same(entry, state):
                note(item, 'none', entry)
            elif ((entry.get('percent') or 0) > (state.get('percent') or 0) + SAME_PERCENT
                  or (entry.get('adjusted') or 0) > (state.get('adjusted') or 0) + SAME_ADJUSTED):
                note(item, 'better', entry)
            else:
                note(item, 'worse', entry)
        elif same_compiler:
            item = lever(seed_lines, lines)
            slot = levers.get(_key(item))
            if slot:
                slot['count'] += 1
                slot['t'] = max(slot['t'], entry.get('t') or 0)
        if (previous is not None and same_compiler and entry.get('ok') and previous.get('ok')
                and _compiler(previous) == compiler and _same(entry, previous)
                and 0 <= (entry.get('t') or 0) - (previous.get('t') or 0) <= SESSION_GAP):
            before_lines = bodies[previous['n']][1]
            step = lever(before_lines, lines)
            if step and _size(step) <= SMALL and all(line in seed_set for removed, _ in step for line in removed):
                slot = levers.get(_key(step))
                if slot is None:
                    note(step, 'none', entry)
                elif slot['kind'] == 'none':
                    slot['count'] += 1
        previous = entry
    return dict(state=state, levers=levers, probes=probes, rewrites=rewrites, checks=len(entries),
                bodies=len({b[0] for b in bodies.values()}))


def section(key: str, seed: str, before: Optional[float] = None) -> Optional[str]:
    """The context section for one function's seed; None when the archive has nothing to say."""
    try:
        data = measure(key, seed, before)
    except (OSError, ValueError, RecursionError):
        return None
    if not data or not (data['levers'] or data['probes']):
        return None
    state = data['state']
    groups: Dict[str, List[dict]] = {'better': [], 'none': [], 'worse': [], 'failed': []}
    for slot in data['levers'].values():
        groups[slot['kind']].append(slot)

    def score(slot: dict) -> str:
        return f"{slot['percent'] or 0:.2f}%/{slot['adjusted'] or 0:.2f}"

    def render(rows: List[dict], limit: int, line) -> List[str]:
        out, used = [], 0
        for slot in rows:
            text = line(slot)
            if used + len(text) > limit:
                out.append(f'- ... and {len(rows) - len(out)} more')
                break
            out.append(text)
            used += len(text)
        return out

    parts = [f"\n## Already measured on this seed ({data['checks']} archived checks, {data['bodies']} distinct bodies, "
             f"seed {state.get('percent') or 0:.2f}%/{state.get('adjusted') or 0:.2f} adjusted)\n"
             "Earlier sessions compiled these exact edits of the body above. Repeating one spends a check and a step "
             "of the plateau stop and returns a known result. Look for a cause they do not touch; combine one with a "
             "new change only if you can say why the combination differs."]
    if groups['better']:
        rows = sorted(groups['better'], key=lambda s: (len(s['lever']), -((s['adjusted'] or 0) + (s['percent'] or 0))))
        parts.append('\n### Moved a score up, not kept as the seed (fewer rows or a higher score on one measure only; a lead worth building on)\n'
                     + '\n'.join(render(rows, LIMITS['better'], lambda s: f"- {score(s)}: {_show(s['lever'])}")))
    if groups['none']:
        rows = sorted(groups['none'], key=lambda s: (len(s['lever']), -s['count'], -s['t']))
        parts.append('\n### No effect: the score did not move (usually identical code)\n'
                     + '\n'.join(render(rows, LIMITS['none'], lambda s: f"- {_show(s['lever'])}" + (f" (x{s['count']})" if s['count'] > 1 else ''))))
    if groups['worse']:
        rows = sorted(groups['worse'], key=lambda s: (len(s['lever']), -s['count'], -(s['adjusted'] or 0)))
        parts.append('\n### Worse than the seed\n'
                     + '\n'.join(render(rows, LIMITS['worse'], lambda s: f"- {score(s)}: {_show(s['lever'])}")))
    if data['probes']:
        parts.append('\n### Compilers tried on this exact body\n'
                     + '\n'.join(f"- {mw or 'default'} {flags or ''}: {e.get('percent') or 0:.2f}%" for (mw, flags), e in data['probes'].items()))
    if data['rewrites']:
        parts.append(f"\n({data['rewrites']} larger rewrites were also measured; none is listed here.)")
    return '\n'.join(parts)


def fields(body: bytes, res) -> dict:
    """What the archive records beyond the scores, so a later check can tell equal code apart
    from equal scores: two different register swaps score the same."""
    out = {'sha': hashlib.sha256(body).hexdigest()}
    rows = getattr(res, '_rows', None)
    if rows:
        ours = chr(10).join((row.get('instruction') or {}).get('formatted', '') for row in rows[1])
        out['state'] = hashlib.sha256(ours.encode()).hexdigest()[:16]
    return out


def seen_before(key: str, recorded: dict, res) -> Optional[dict]:
    """The archived check this one repeats: the same source under the same compiler, else the
    same compiled rows. Call before archiving the body. None for anything the archive has not seen."""
    if not getattr(res, 'ok', False):
        return None
    compiler = (res.mw_version, res.extra_cflags or None)
    state = None
    for entry in reversed(_entries(key)):
        if not entry.get('ok') or _compiler(entry) != compiler:
            continue
        digest = entry.get('sha')
        if digest is None:
            try:
                digest = hashlib.sha256(entry['path'].read_bytes()).hexdigest()
            except OSError:
                continue
        if digest == recorded['sha']:
            return {'kind': 'source', 'check': entry['n'], 'percent': entry.get('percent')}
        if state is None and recorded.get('state') and entry.get('state') == recorded['state']:
            state = {'kind': 'state', 'check': entry['n'], 'percent': entry.get('percent')}
    return state
