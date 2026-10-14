"""Where a unit's defined TU section objects actually land, against retail.

A body that defines the retail TU's `.bss`/`.data` cluster (so MWCC addresses it off one
section base, `fixup_layout.tu_section_layout`) reproduces retail only when every object sits
at retail's offset from the cluster's first object. Matchers building that cluster by hand
got the offsets wrong in ways the diff only shows indirectly (fn_1_A1DCC: lbl_1_bss_6EAD0 at
+0x30 instead of +0x38; fn_1_39C60: the base object padded so every later offset was +4;
fn_8005596C: DOL objects of 8 bytes or less went to `.sbss` and were addressed off r13).

This compiles the body once, reads every defined data symbol of the unit object, maps its name
to a retail address (`lbl_*` names, the `fzgx_obj_`/`fzgx_pool_<section>_` aliases, `_HEX`
interior suffixes, `_fill_/_tail_/_gap_ADDR` fillers, `fzgx_gap_<section>_ADDR`), and compares
offsets within each unit section. `report` gives matchers the comparison; `repairs` proposes
the deterministic corrections (the oracle still decides):

- DOL small data: a definition MWCC put in `.sbss`/`.sdata` whose retail object is in
  `.bss`/`.data` gets `__declspec(section ".data")` (an uninitialized object then goes to
  `.bss`; measured on GC/1.2.5n and GC/1.3.2: `.bss` itself is rejected as an initialized
  section name).
- `.bss` first-access primer: MWCC emits `.bss` objects in first-access order, so every
  defined retail object is touched in retail address order (missing ones added).
- gaps: the first object below its retail offset gets a filler object before it (`.data`
  fillers carry retail bytes, so they stay initialized); one above it shrinks a preceding
  filler array when there is one.
"""
from __future__ import annotations

import hashlib
import re
from pathlib import Path
from typing import Dict, List, Optional, Tuple

from . import oracle, poolfix
from .project import STATE_DIR

_DATA = ('.bss', '.data', '.sbss', '.sdata')
_SMALL = {'.sbss': '.bss', '.sdata': '.data'}
_LABEL = r'lbl_\d+_(?:bss|data|sbss|sdata)_[0-9A-Fa-f]+|lbl_[0-9A-Fa-f]{8}'
_ALIAS = re.compile(r'^(?:fzgx_obj_|fzgx_pool_(?:bss|data|sbss|sdata)_)?(%s)(?:_(?:fill|tail|gap)_([0-9A-Fa-f]+)|_([0-9A-Fa-f]+))?$' % _LABEL)
_GAP = re.compile(r'^fzgx_gap_(bss|data|sbss|sdata)_([0-9A-Fa-f]+)$')
_FILLER = re.compile(r'_(?:fill|tail|gap)_[0-9A-Fa-f]+$|^fzgx_gap_')
_ELEMENT = {'u8': 1, 's8': 1, 'char': 1, 'u16': 2, 's16': 2, 'u32': 4, 's32': 4}


def retail_address(name: str, syms) -> Optional[Tuple[int, str]]:
    """(retail address, retail section) a unit definition stands for, or None."""
    m = _GAP.match(name)
    if m:
        return int(m[2], 16), '.' + m[1]
    m = _ALIAS.match(name)
    if not m:
        return None
    base = syms.get(m[1])
    if base is None or base.kind != 'object' or base.section not in _DATA:
        return None
    if m[2]:
        return int(m[2], 16), base.section
    return base.addr + (int(m[3], 16) if m[3] else 0), base.section


def _compile(p, symbol, body, check):
    sym = p.resolve(symbol)
    cache = p.__dict__.setdefault('_section_probe', {})
    key = (symbol, getattr(check, 'mw_version', None), getattr(check, 'extra_cflags', None),
           hashlib.sha1(body.encode()).hexdigest())
    if key not in cache:
        d = STATE_DIR / 'fixup' / 'probe'
        d.mkdir(parents=True, exist_ok=True)
        src = d / f'sections_{sym.name}_{key[3][:10]}.c'
        src.write_text(body)
        obj = src.with_suffix('.o')
        try:
            cp = oracle.compile_source(p, sym.module, src, obj, key[1], key[2])
            cache[key] = poolfix.Elf(obj.read_bytes()) if cp.returncode == 0 and obj.exists() else None
        finally:
            src.unlink(missing_ok=True)
            obj.unlink(missing_ok=True)
    return cache[key]


def defined_objects(p, symbol, body, check=None) -> List[dict]:
    """Every defined data symbol of the compiled body that stands for a retail object."""
    # only a body defining one at file scope (a compile per check otherwise)
    if not re.search(r'(?m)^(?![ \t])(?!extern\b)(?!typedef\b)[^\n(;]*\b(?:fzgx_obj_|fzgx_pool_\w*?|fzgx_gap_)?(?:%s|bss|data)\w*\s*'
                     r'(?:\[[^\]\n]*\]\s*)*(?:=|;)' % _LABEL, body):
        return []
    elf = _compile(p, symbol, body, check)
    if elf is None:
        return []
    syms = p.symbols(p.resolve(symbol).module)
    out = []
    for s in elf.symbols():
        if not (0 < s['shndx'] < len(elf.sections)) or not s['name']:
            continue
        section = elf.sections[s['shndx']]['name']
        if section not in _DATA:
            continue
        where = retail_address(s['name'], syms)
        if where is None:
            continue
        out.append(dict(name=s['name'], section=section, offset=s['value'], size=s['size'],
                        retail=where[0], retail_section=where[1]))
    return out


def _groups(objects):
    """{retail section: objects sorted by retail address} for objects in their retail section."""
    groups: Dict[str, List[dict]] = {}
    for o in objects:
        if o['section'] == o['retail_section']:
            groups.setdefault(o['section'], []).append(o)
    return {k: sorted(v, key=lambda o: (o['retail'], o['offset'])) for k, v in groups.items()}


def _misplaced(group):
    """(object, expected unit offset) of the first object off its retail offset, or None."""
    anchor = group[0]
    for o in group[1:]:
        expected = anchor['offset'] + o['retail'] - anchor['retail']
        if o['offset'] != expected:
            return o, expected
    return None


def report(p, symbol, body, check=None) -> List[str]:
    """Lines for matchers: where each defined retail object landed, flagged where it differs."""
    try:
        objects = defined_objects(p, symbol, body, check)
    except Exception:  # evidence only
        return []
    if not objects:
        return []
    lines = []
    small = [o for o in objects if _SMALL.get(o['section']) == o['retail_section']]
    for o in small:
        lines.append(f'  {o["name"]}: MWCC put it in {o["section"]} (small data, addressed off r13); retail '
                     f'has it in {o["retail_section"]}: define it `__declspec(section ".data")`.')
    for section, group in sorted(_groups(objects).items()):
        anchor = group[0]
        bad = _misplaced(group)
        if bad is None and not small:
            continue
        lines.append(f'Section layout of your defined {section} objects (offsets from {anchor["name"]}; '
                     'retail = the dtk address difference):')
        for o in group:
            expected = anchor['offset'] + o['retail'] - anchor['retail']
            delta = o['offset'] - expected
            flag = '' if not delta else f'  <- {abs(delta):#x} bytes {"late" if delta > 0 else "early"}'
            lines.append(f'  {o["name"]}: ours +{o["offset"] - anchor["offset"]:#x}, retail '
                         f'+{o["retail"] - anchor["retail"]:#x}, size {o["size"]:#x}{flag}')
        if bad:
            o, expected = bad
            lines.append(f'  first difference: {o["name"]} ({"insert" if expected > o["offset"] else "remove"} '
                         f'{abs(expected - o["offset"]):#x} bytes before it; a .bss object must also be '
                         'touched in retail order by the .fzgxpool primer).')
    if lines:
        lines.insert(0, 'Defined TU section objects against retail (fzgx section layout check):')
    return lines


def _definition(text, name):
    """The file-scope definition line of `name` (not an extern, not inside a function)."""
    for m in re.finditer(r'(?m)^(?![ \t])(?!extern\b)(?!typedef\b)[^\n(]*?\b%s\b\s*(?:\[[^\]\n]*\]\s*)*(?:=|;)' % re.escape(name), text):
        return m
    return None


def _primer_lines(text):
    """Access lines `s = *(u8 *)&NAME;` / `s = *(u8 *)NAME;` inside `.fzgxpool` primers."""
    out = []
    for region in re.finditer(r'(?ms)^[ \t]*#pragma section code_type "\.fzgxpool"[ \t]*\n.*?^[ \t]*#pragma section code_type "\.text"', text):
        for m in re.finditer(r'(?m)^[ \t]*s\s*=\s*\*\s*\(\s*(?:volatile\s+)?u8\s*\*\s*\)\s*&?\s*\(?\s*(\w+)\s*\)?[^;\n]*;[ \t]*\n',
                             region[0]):
            out.append((region.start() + m.start(), region.start() + m.end(), m[1]))
    return out


def _sbss_fix(text, objects):
    names = [o['name'] for o in objects if _SMALL.get(o['section']) == o['retail_section']]
    out = text
    for name in names:
        m = _definition(out, name)
        if m is None or '__declspec' in m[0]:
            continue
        out = out[:m.start()] + '__declspec(section ".data") ' + out[m.start():]
    return out if out != text else None


def _primer_fix(text, objects):
    names = [o['name'] for o in sorted((o for o in objects if o['retail_section'] == '.bss'),
                                       key=lambda o: o['retail'])]
    if len(names) < 2:
        return None
    lines = _primer_lines(text)
    if lines:
        # a primer can only touch what is defined above it
        names = [n for n in names if (m := _definition(text, n)) is not None and m.start() < lines[0][0]]
    present = [n for _, _, n in lines if n in names]
    if present == names or len(names) < 2:
        return None
    access = ''.join(f'    s = *(u8 *)&{n};\n' for n in names)
    if lines:
        hit = [(a, b) for a, b, n in lines if n in names]
        at = hit[0][0] if hit else lines[0][0]
        out = text
        for a, b in sorted(hit, reverse=True):
            out = out[:a] + out[b:]
        return out[:at] + access + out[at:]
    # no primer yet: one after the last definition
    ends = [m.end() for m in (_definition(text, n) for n in names) if m]
    if not ends:
        return None
    at = text.find('\n', max(ends)) + 1
    block = ('\n#pragma section code_type ".fzgxpool"\nstatic void fzgx_bss_order(void) {\n'
             '    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */\n'
             + access + '}\n#pragma section code_type ".text"\n')
    return text[:at] + block + text[at:]


def _gap_fix(p, symbol, text, group, retail_bytes):
    bad = _misplaced(group)
    if bad is None:
        return None
    o, expected = bad
    delta = expected - o['offset']
    m = _definition(text, o['name'])
    if m is None:
        return None
    section = o['section']
    # a DOL filler of 8 bytes or less would itself go to small data
    spec = '__declspec(section ".data") ' if p.resolve(symbol).module == 'main' else ''
    if delta > 0:
        start = o['retail'] - delta
        name = f'fzgx_gap_{section[1:]}_{start:X}'
        if section == '.data':
            raw = retail_bytes(start, delta)
            if raw is None or not any(raw):
                return None  # all-zero initializers would move the filler to .bss
            words = ', '.join(f'0x{b:02X}' for b in raw)
            decl = f'{spec}u8 {name}[{delta:#x}] = {{ {words} }};  /* fzgx-allow: A1 retail data bytes */\n'
        else:
            decl = f'{spec}u8 {name}[{delta:#x}];\n'
        out = text[:m.start()] + decl + text[m.start():]
        if section == '.bss':
            prim = [(a, n) for a, _, n in _primer_lines(out) if n == o['name']]
            if prim:
                out = out[:prim[0][0]] + f'    s = *(u8 *)&{name};\n' + out[prim[0][0]:]
        return out
    # too late: shrink the nearest preceding filler array (bss only: .data fillers carry bytes)
    if section != '.bss':
        return None
    before = [g for g in group if g['offset'] < o['offset'] and _FILLER.search(g['name'])]
    if not before:
        return None
    filler = max(before, key=lambda g: g['offset'])
    fm = re.search(r'(?m)^(?![ \t])(?:__declspec\(section "\.data"\)\s+)?(?:static\s+)?(u8|s8|char|u16|s16|u32|s32)\s+%s\s*(?:\[\s*(0x[0-9A-Fa-f]+|\d+)\s*\])?\s*;[^\n]*\n'
                   % re.escape(filler['name']), text)
    if not fm:
        return None
    size = _ELEMENT[fm[1]] * (int(fm[2], 0) if fm[2] else 1)
    if -delta > size:
        return None
    left = size + delta
    new = '' if left == 0 else f'{spec}u8 {filler["name"]}[{left:#x}];\n'
    out = text[:fm.start()] + new + text[fm.end():]
    if not new:
        out = re.sub(r'(?m)^[ \t]*s\s*=\s*\*\s*\(\s*u8\s*\*\s*\)\s*&?\s*%s\s*;[ \t]*\n' % re.escape(filler['name']), '', out)
    return out


def repairs(p, symbol, body, check=None) -> List[Tuple[str, str]]:
    """Candidates correcting the defined section objects' placement (see the module doc)."""
    objects = defined_objects(p, symbol, body, check)
    if not objects:
        return []
    from .fixup_layout import section_bytes
    module = p.resolve(symbol).module
    out = []
    fixed = _sbss_fix(body, objects)
    if fixed:
        out.append(('keep defined small objects out of small data (__declspec(section ".data"))', fixed))
    primed = _primer_fix(fixed or body, objects)
    if primed:
        out.append(('touch every defined .bss object in retail order (first-access primer)', primed))
    for section, group in sorted(_groups(objects).items()):
        def raw_at(addr, n, section=section):
            found = section_bytes(p, module, section, addr)
            if not found:
                return None
            base, data = found
            chunk = bytes(data[addr - base:addr - base + n])
            return chunk if len(chunk) == n else None
        try:
            gapped = _gap_fix(p, symbol, body, group, raw_at)
        except (KeyError, ValueError, IndexError):
            gapped = None
        if gapped:
            out.append((f'move the first misplaced defined {section} object to its retail offset', gapped))
    return out
