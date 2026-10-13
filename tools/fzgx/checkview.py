"""Paged evidence from the selected compile; reads never compile or spend checks."""
from __future__ import annotations

import hashlib
import json
from . import compat, oracle
from .evidence import data_context
from .ledger import Ledger

PAGE_LINES = 80


def _identity(project, key):
    from .api import _canonical_text, _compiler_options
    work = project.work_path(key)
    unit = project.unit_of(project.resolve(key))
    body = work.read_text() if work.exists() else _canonical_text(project, unit) if unit else ''
    attempt = Ledger().current_attempt(key)
    options = _compiler_options(project, key)
    return dict(sha256=hashlib.sha256(body.encode()).hexdigest(),
                attempt=attempt['id'] if attempt else None,
                compiler={name: options.get(name) for name in ('mw', 'flags')})


def _path(project, key):
    return project.work_path(key).with_suffix('.diff.json')


def save(project, key, result):
    """Store only the selected version, including failures to invalidate old evidence."""
    rows = getattr(result, '_rows', ([], []))
    lines = oracle._render_diff(*rows, 1 << 30, getattr(result, '_accepted_rows', set()), addresses=True)
    sym = project.resolve(key)
    fn = project.function_asm(sym.module).get(sym.name)
    payload = dict(identity=_identity(project, key), result=result.to_json(), diff=lines,
                   data=data_context(project, fn, full=True) if fn else [],
                   datainit=_data_initializers(project, key, result))
    path = _path(project, key)
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_suffix('.tmp')
    temporary.write_text(json.dumps(payload) + '\n')
    compat.replace(temporary, path)
    if result.ok:
        result.diff = _page(payload, 'diff', 0)['diff']


def _data_initializers(project, key, result):
    """Retail initializers for the data objects the work copy defines, as a unified diff.

    A matcher that defines the TU's `.data` cluster itself (so MWCC addresses it off one
    section base, as retail does) cannot read retail's bytes from a session and writes filler,
    which the oracle rejects (fn_3_990C: 1182 of 1588 words, fn_1_7ACDC: 98 of 104).
    `fixup_layout.defined_data_initializers` rewrites each defined object in place with
    retail's words and symbolic pointers; this offers that rewrite. Only when the check
    reports a pool whose bytes differ from retail. Pool primers' placeholder tables get the same
    offer, followed by every retail word of each differing pool."""
    if not getattr(result, 'ok', False) or not any('differs from retail' in n for n in result.pool_notes or ()):
        return []
    try:
        import difflib
        from . import fixup_layout
        work = project.work_path(key)
        if not work.exists():
            return []
        body = work.read_text()
    except Exception:  # evidence only: a failure here must never fail the check
        return []
    out = []
    try:
        candidates = fixup_layout.defined_data_initializers(project, key, body, result)
    except Exception:
        candidates = []
    if candidates:
        label, text = candidates[0]
        out += [f'{label}: apply this patch to your work copy (patch_unit/write_unit). Each defined object '
                'becomes a union whose first member carries retail words; uses become `.v`. Pointer '
                'words are `__fzgx_offset_` aliases the oracle binds to retail targets. Do not edit the words.']
        out += [line.rstrip(chr(10)) for line in difflib.unified_diff(
            body.splitlines(True), text.splitlines(True), 'work copy', 'with retail initializers', n=1)]
        body = text
    # literal-pool primers: placeholder words in `fzgx_pool_table_HEX` tables, and the full retail
    # pool (a pool note lists only five differing words; fn_1_15EC40 had 24)
    try:
        tables = fixup_layout.retail_pool_tables(project, key, body, result)
    except Exception:
        tables = []
    if tables:
        label, text = tables[0]
        out += [f'{label}: apply this patch to your work copy; the words are retail bytes.']
        out += [line.rstrip(chr(10)) for line in difflib.unified_diff(
            body.splitlines(True), text.splitlines(True), 'work copy', 'with retail pool words', n=1)]
    try:
        out += fixup_layout.retail_pool_dump(project, key, result)
    except Exception:
        pass
    return out


def _page(payload, section, cursor):
    lines = payload.get(section, [])
    end = min(cursor + PAGE_LINES, len(lines))
    result = dict(payload['result'])
    result.pop('budget', None)
    result['evidence'] = dict(section=section, cursor=cursor, next=end if end < len(lines) else None,
                              total=len(lines), sha256=payload['identity']['sha256'])
    result['diff'] = [f'Cached {section}: lines {cursor}..{end} of {len(lines)}.']
    if section == 'diff':
        result['diff'].append('Columns: aligned row*4, T: target object address, C: candidate object address; target | ours.')
    result['diff'] += lines[cursor:end]
    if end < len(lines):
        result['diff'].append(f'Continue with read_evidence(section="{section}", cursor="{end}"). '
                              f'Existing sessions: check(versions="{section}:{end}") reads the same page without compiling.')
    if section == 'diff' and payload['data']:
        result['diff'].append('Decoded retail data is available: read_evidence(section="data", cursor="0"); '
                              'existing sessions: check(versions="data:0").')
    if section == 'diff' and payload.get('datainit'):
        result['diff'].append('Your defined data objects or pool primer differ from retail bytes: the retail initializers and pool words are '
                              'read_evidence(section="datainit", cursor="0"); existing sessions: check(versions="datainit:0").')
    return result


def read(project, key, section='diff', cursor=0):
    if section not in ('diff', 'data', 'datainit') or cursor < 0:
        return dict(ok=False, error='section must be diff, data or datainit; cursor must be nonnegative')
    path = _path(project, key)
    if not path.exists():
        return dict(ok=False, error='No cached check. Write or check the current source first.')
    payload = json.loads(path.read_text())
    payload['identity']['compiler'] = {name: payload['identity']['compiler'].get(name) for name in ('mw', 'flags')}
    if payload['identity'] != _identity(project, key):
        return dict(ok=False, error='Cached check belongs to different source, compiler or attempt. Check the current source first.')
    if not payload['result']['ok']:
        return payload['result']
    if cursor > len(payload.get(section, [])):
        return dict(ok=False, error=f'cursor exceeds {len(payload.get(section, []))} available lines')
    result = _page(payload, section, cursor)
    result['diff'][0] += ' Reading this page did not compile or spend a check.'
    return result
