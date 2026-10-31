"""Exact retail clone discovery and C binding for the shared fixup engine."""

from __future__ import annotations

import re
import hashlib
import shlex
import subprocess
from collections import defaultdict
from pathlib import Path
from typing import Optional

from . import compat, oracle
from .ledger import Ledger
from .project import Project, ROOT, STATE_DIR


def replace_symbols(text: str, mapping: dict) -> str:
    if not mapping:
        return text
    names = "|".join(re.escape(n) for n in sorted(mapping, key=len, reverse=True))
    return re.sub(r"(?<![\w.$])(" + names + r")(?![\w.$])", lambda m: mapping[m[0]], text)


def shape(fn) -> tuple:
    # Preserve registers, immediates, relocation kinds, addends, and branch destinations.
    # Only names change; a shared global must remain shared at every reference site.
    names = {name: f"$S{i}" for i, name in enumerate(fn.refs)}
    labels = {line[:-1]: f"$L{i}" for i, line in enumerate(fn.asm) if line.endswith(":")}
    return tuple(replace_symbols(line.split(": ", 1)[-1], names | labels)
                 for line in fn.asm if not line.endswith(":"))


def families(p, max_size=None, module=None, symbol=None):
    ledger = Ledger()
    groups = defaultdict(list)
    for row in ledger.db.execute("SELECT symbol, module, status, size FROM functions "
                                 "WHERE status IN ('matched', 'unmatched') ORDER BY symbol"):
        key, mod, status, size = row
        if max_size is not None and size > max_size:
            continue
        fn = p.function_asm(mod).get(key.split(":")[-1])
        if fn is not None and fn.symbol.size == size and p.key(fn.symbol) == key:
            groups[shape(fn)].append(dict(symbol=key, module=mod, status=status, size=size))
    return [group for group in groups.values() if len(group) > 1 and any(
        r['status'] == 'unmatched' and (not module or r['module'] == module)
        and (not symbol or r['symbol'] == symbol) for r in group)]


def bindings(p, donor, recipient):
    a, b = p.function(donor), p.function(recipient)
    if a is None or b is None or shape(a) != shape(b):
        raise ValueError(f'{donor} and {recipient}: retail clone changed')
    return dict(zip(a.refs, b.refs)) | {a.symbol.name: b.symbol.name}


def rebind(body, mapping):
    from .sdkimport import replace_c_symbols
    return replace_c_symbols(body, mapping)


def declaration_closure(body):
    from .sdkimport import declarations, masked, IDENT, LEXICAL
    clean = re.sub(r'(?m)^[ \t]*#pragma[^\n]*', lambda m: ' '*len(m[0]), masked(body))
    spans=[]; start=depth=parens=0; function=False
    for i, char in enumerate(clean):
        if char == '(':
            parens += 1
        elif char == ')':
            parens -= 1
        elif char == '{':
            if depth == 0:
                prefix=clean[start:i].strip()
                function=bool(re.search(r'\)\s*$',prefix)) and '=' not in prefix
            depth += 1
        elif char == '}':
            depth -= 1
            if depth == 0 and function:
                spans.append((start,i+1,False));start=i+1;function=False
        elif char == ';' and depth == 0 and parens == 0:
            text=clean[start:i+1].lstrip()
            spans.append((start,i+1,text.startswith(('extern ', 'typedef ', 'struct ', 'union ', 'enum '))))
            start=i+1
    nodes=[]
    for start,end,removable in spans:
        pieces=declarations(clean[start:end])
        names=set().union(*(p.names for p in pieces))
        # A struct declaration may also define storage. Keep every definition;
        # only unused types and extern declarations can disappear here.
        removable=removable and bool(pieces) and all(p.kind=='type' or p.text.startswith('extern ') for p in pieces)
        nodes.append((start,end,removable,names,set(IDENT.findall(clean[start:end]))))
    selected={i for i,n in enumerate(nodes) if not n[2]}
    needed=set().union(*(nodes[i][4] for i in selected))
    while True:
        more={i for i,n in enumerate(nodes) if i not in selected and n[3] & needed}
        if not more:
            break
        selected.update(more)
        needed.update(set().union(*(nodes[i][4] for i in more)))
    for i,(start,end,_,_,_) in reversed(list(enumerate(nodes))):
        if i not in selected:
            text=body[start:end]
            # Keep licensing and compiler state; field-layout commentary leaves
            # with its unused declaration.
            retained=[(m.start(),m[0]) for m in LEXICAL.finditer(text)
                      if m[0].startswith(('/*','//')) and re.search(r'copyright|license|SPDX',m[0],re.I)]
            retained.extend((m.start(),m[0]) for m in re.finditer(r'(?m)^[ \t]*#pragma[^\n]*',text))
            body=body[:start]+'\n'+'\n'.join(t for _,t in sorted(retained))+'\n'+body[end:]
    return re.sub(r'\n(?:[ \t]*\n){2,}', '\n\n', body)


class Declarations:
    """Expand owned headers without losing compiler pragmas or lint justifications."""
    def __init__(self, engine):
        self.engine = engine
        self.root = engine.output / 'declarations'
        self.root.mkdir(exist_ok=True)
        self.markers, self.includes, self.expanded = {}, {}, {}

    def protect(self, text):
        from .sdkimport import LEXICAL
        def marker(value):
            key = 'FZGX_PRESERVE_' + hashlib.sha256(value.encode()).hexdigest()
            self.markers[key] = value
            return key
        # Comments inside directives must remain whitespace: inserting a token
        # there could change a macro or an include filename.
        def comment(match):
            line = text[text.rfind('\n', 0, match.start()) + 1:match.start()]
            if not match[0].startswith(('//', '/*')) or line.lstrip().startswith('#'):
                return match[0]
            value = match[0]
            if value.startswith('//'):
                value = '/*' + value[2:] + ' */'
            return ' ' + marker(value) + ' '
        text = LEXICAL.sub(comment, text)
        # Keep the original directive for preprocessor option queries, and a
        # marker for compilation of the expanded source (-E drops pragmas).
        return re.sub(r'(?m)^[ \t]*#pragma[^\n]*', lambda m: m[0] + '\n' + marker(m[0]), text)

    def include(self, path):
        path = path.resolve()
        if path not in self.includes:
            if not path.is_relative_to(ROOT / 'include') and not path.is_relative_to(ROOT / 'build' / self.engine.project.version / 'include'):
                raise ValueError(f'clone declarations require an owned include directory: {path}')
            dest = self.root / hashlib.sha256(str(path).encode()).hexdigest()[:16]
            # Only the configured header roots, never the candidate corpus.
            for header in sorted(path.rglob('*')):
                if header.is_file():
                    output = dest / header.relative_to(path)
                    output.parent.mkdir(parents=True, exist_ok=True)
                    output.write_text(self.protect(header.read_text()))
            self.includes[path] = dest
        return self.includes[path]

    def expand(self, row):
        if row['id'] in self.expanded:
            return self.expanded[row['id']]
        body = Path(row['source']).read_text()
        if not re.search(r'(?m)^\s*#(?!pragma\b)', body):
            return declaration_closure(body)
        p = self.engine.project
        args = shlex.split(oracle.module_flags(p, p.resolve(row['symbol']).module)[0])
        extra = shlex.split(row['flags']); levels = [f for f in extra if f.startswith('-O')]
        args = [levels[-1] if levels and f.startswith('-O') else f for f in args]
        args += [f for f in extra if not f.startswith('-O')]
        for i, arg in enumerate(args[:-1]):
            if arg in ('-i', '-I'):
                args[i + 1] = str(self.include(ROOT / args[i + 1]))
        wrapper = self.root / (row['id'][:24] + '.c')
        wrapper.write_text(self.protect(body))
        cmd = [*compat.mwcc(row['mw']), *args, '-EP', str(wrapper)]
        # expanded headers can carry bytes the locale codec rejects; on Windows a strict decode
        # fails in the reader thread and leaves stdout None
        result = subprocess.run(cmd, cwd=ROOT, text=True, errors='replace', capture_output=True, timeout=60)
        if result.returncode or result.stdout is None:
            raise ValueError((result.stdout or '')[-2000:] + (result.stderr or '')[-2000:])
        body = re.sub(r'FZGX_PRESERVE_[0-9a-f]{64}', lambda m: self.markers[m[0]], result.stdout)
        body = declaration_closure(body)
        self.expanded[row['id']] = body
        return body


def run(p: Project, max_size: int = 255, module: Optional[str] = None, do_submit: bool = True) -> dict:
    # Compatibility command; all compilation, scoring and integration is fixup's.
    from argparse import Namespace
    from .fixup import command
    return command(p, Namespace(clones=True, symbol=None, body=None, corpus=None,
        output=STATE_DIR/'fixup'/'reuse', captures=None, capture=False, replay=False,
        archive=None, saved=False, apply=do_submit, min_percent=100, max_percent=100,
        module=module, max_size=max_size, limit=None, rounds=0, beam=3,
        max_candidates=80, budget=None, drafts=False))


# ----------------------------------------------------------------------------- near clones
# karamzov123/fzero-gx-decomp (CC0, 2026-10-29): option/title/sel share menu code, and an
# opcode-sequence comparison of unmatched against matched functions found nine ports in a day.
# `families` above needs identical shapes (names only differ); this scan accepts sequences that
# differ in a few instructions, rebinds the donor's matched C by the references of aligned
# instructions, and lets the oracle score the port. Nothing is submitted here: a port that
# scores is a seed for `fzgx fixup SYMBOL --body PATH`, which still decides.

NEAR_ROOT = ROOT / '.fzgx' / 'nearclones'


def _opcodes(fn) -> list:
    return [line.split(': ', 1)[-1].split()[0] for line in fn.asm if not line.endswith(':') and line.strip()]


def _aligned_refs(a, b) -> dict:
    """donor ref -> recipient ref, read off instruction pairs inside equal opcode blocks."""
    import difflib
    la = [ln for ln in a.asm if not ln.endswith(':') and ln.strip()]
    lb = [ln for ln in b.asm if not ln.endswith(':') and ln.strip()]
    ra, rb = set(a.refs), set(b.refs)
    tok = re.compile(r'[A-Za-z_$@.][\w$@.]*')
    mapping, conflict = {}, set()
    sm = difflib.SequenceMatcher(None, _opcodes(a), _opcodes(b), autojunk=False)
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag != 'equal':
            continue
        for x, y in zip(la[i1:i2], lb[j1:j2]):
            na = [t for t in tok.findall(x.split(': ', 1)[-1]) if t in ra]
            nb = [t for t in tok.findall(y.split(': ', 1)[-1]) if t in rb]
            if len(na) != len(nb):
                continue
            for u, v in zip(na, nb):
                if mapping.get(u, v) != v:
                    conflict.add(u)
                mapping.setdefault(u, v)
    return {u: v for u, v in mapping.items() if u not in conflict and u != v}


def near_clones(p: Project, min_ratio: float = 0.9, exclude=(), module: Optional[str] = None,
                min_size: int = 32, check: bool = True) -> list:
    """Pairs (recipient unmatched, donor matched) whose retail opcode sequences agree to at
    least MIN_RATIO (difflib), best donor per recipient; with CHECK, the donor's matched C is
    rebound (donor name and aligned references) and scored by the oracle for the recipient."""
    import bisect
    import difflib
    ledger = Ledger()
    rows = ledger.db.execute("SELECT symbol, module, status, size, unit, best_percent FROM functions "
                             "WHERE status IN ('matched', 'unmatched') AND size >= ?", (min_size,)).fetchall()
    donors, recipients = [], []
    for key, mod, status, size, unit, best in rows:
        if status == 'unmatched' and (mod in exclude or (module and mod != module)):
            continue
        try:
            fn = p.function_asm(mod).get(key.split(':')[-1])
        except Exception:
            continue
        if fn is None or fn.symbol.size != size:
            continue
        item = dict(symbol=key, module=mod, size=size, unit=unit, best=best or 0.0, fn=fn, ops=_opcodes(fn))
        (donors if status == 'matched' else recipients).append(item)
    donors.sort(key=lambda d: d['size'])
    sizes = [d['size'] for d in donors]
    pairs = []
    for r in recipients:
        lo = bisect.bisect_left(sizes, int(r['size'] * min_ratio))
        hi = bisect.bisect_right(sizes, int(r['size'] / min_ratio) + 4)
        best = None
        for d in donors[lo:hi]:
            sm = difflib.SequenceMatcher(None, d['ops'], r['ops'], autojunk=False)
            if sm.real_quick_ratio() < min_ratio or sm.quick_ratio() < min_ratio:
                continue
            ratio = sm.ratio()
            if ratio >= min_ratio and (best is None or ratio > best[0]
                                       or (ratio == best[0] and d['module'] == r['module'])):
                best = (ratio, d)
        if best:
            pairs.append(dict(symbol=r['symbol'], module=r['module'], size=r['size'], best=r['best'],
                              donor=best[1]['symbol'], donor_module=best[1]['module'],
                              ratio=round(best[0], 4), _r=r, _d=best[1]))
    if check and pairs:
        NEAR_ROOT.mkdir(parents=True, exist_ok=True)
        items = []
        for pr in pairs:
            d, r = pr['_d'], pr['_r']
            try:
                donor_src = oracle.unit_source_path(p, d['unit']).read_text()
            except (OSError, TypeError):
                pr['note'] = 'donor unit source missing'
                continue
            mapping = _aligned_refs(d['fn'], r['fn'])
            mapping[d['fn'].symbol.name] = r['fn'].symbol.name
            path = NEAR_ROOT / (pr['symbol'].replace(':', '__') + '.c')
            path.write_text(replace_symbols(donor_src, mapping))
            pr['body'] = str(path)
            pr['rebound'] = len(mapping)
            items.append((pr['symbol'], path))
        results = oracle.check_many(p, items)
        for pr in pairs:
            res = results.get(pr['symbol'])
            if res is not None:
                pr['percent'] = round(res.percent or 0.0, 2) if res.ok else None
                pr['matched'] = bool(res.ok and (res.matched or res.matched_pool))
    for pr in pairs:
        pr.pop('_r', None)
        pr.pop('_d', None)
    pairs.sort(key=lambda x: (-(x.get('percent') or 0), -x['ratio']))
    return pairs
