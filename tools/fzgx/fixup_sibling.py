"""Sibling section-layout transplant.

A matched block of the same TU that defines a retail `.bss` cluster as file-scope objects
(`fixup_layout.tu_section_layout`'s output, with its `fzgx_bss_layout` first-access primer)
records the cluster's whole retail layout: every object, in retail order, under the names the
module header allows. A body that addresses the same cluster through a struct view
(`T *p = (T *)&lbl;`, `lbl.field`), through header externs or through its own partial layout
cannot make an object's address a real pointer value (`addi r30, r31, off`) the way retail
does, and the per-body layout family only sees the fields that body touches. This family
copies the sibling's layout and primer into the candidate and rewrites the body's views and
names onto those objects (fn_1_14B1FC closed this way by hand from fn_1_14C6F8). Candidates
only: the oracle and the 16 hashes decide."""
from __future__ import annotations

import bisect
import re
from typing import Dict, List, Optional, Tuple

from . import fixup_layout, tufile

SIZES = {'u8': 1, 's8': 1, 'char': 1, 'BOOL8': 1, 'u16': 2, 's16': 2, 'short': 2,
         'u32': 4, 's32': 4, 'int': 4, 'long': 4, 'f32': 4, 'float': 4, 'BOOL': 4,
         'f64': 8, 'double': 8, 'u64': 8, 's64': 8}
LAYOUT_COMMENT = '/* file-scope objects of the retail TU'
# a layout line: optional `__declspec(section ".data")` (the DOL units' spelling), the type,
# the name, dims, and an optional trailing comment (`/* fzgx-allow: ... */` on volatiles)
DECLSPEC = r'(?:__declspec\(section\s+"[^"]*"\)\s*)?'
DECL = re.compile(r"^(" + DECLSPEC + r")((?:volatile\s+|const\s+)*(?:unsigned\s+|signed\s+)?\w+(?:\s*\*+)?)\s*(\w+)\s*((?:\[[^\]]+\])*)\s*;\s*(/\*.*?\*/)?\s*$")
PRIMER = re.compile(r"#pragma section code_type \"\.fzgxpool\"\s*\nstatic void (fzgx_bss_layout\w*)\(void\) \{.*?\n\}\s*\n#pragma section code_type \"\.text\"\s*\n", re.S)
# a retail data symbol: REL `lbl_<m>_<section>_<offset>` or DOL `lbl_<address>`
LBL = r"(?:lbl_\d+_(?:bss|sbss|data|sdata)_[0-9A-F]+|lbl_[0-9A-F]{8})"
DATA_SECTIONS = ('.bss', '.sbss', '.data', '.sdata')
DEBUG = False


def _decl(line: str) -> Optional[dict]:
    m = DECL.match(line.strip())
    if not m or re.match(r"(?:return|extern|typedef|static|goto)\b", m.group(2)):
        return None
    return dict(spec=m.group(1).strip(), type=re.sub(r"\s+", " ", m.group(2)), name=m.group(3),
                dims=re.findall(r"\[([^\]]+)\]", m.group(4)), comment=m.group(5) or '')


def _type_size(t: str) -> Optional[Tuple[int, int]]:
    t = re.sub(r"\b(?:volatile|const|static|unsigned|signed)\b", " ", t).strip()
    if '*' in t:
        return 4, 4
    n = SIZES.get(t)
    return (n, n) if n else None


def _decl_size(t: str, dims: List[str]) -> Optional[Tuple[int, int]]:
    ts = _type_size(t)
    if ts is None:
        return None
    n, a = ts
    try:
        for d in dims:
            n *= int(d, 0)
    except ValueError:
        return None
    # MWCC's file-scope rule the layout family uses: arrays 4-aligned
    return n, (max(a, 4) if dims else a)


def _addr_hint(name: str, syms, section: Optional[str] = '.bss', exact: bool = False) -> Optional[int]:
    """Retail address a layout name stands for: a dtk symbol, `<sym>_<off>` (an object at that
    offset inside it) or `<sym>_fill_<addr>` (a gap from that address), in `section` (any data
    section when None)."""
    base = name[len('fzgx_obj_'):] if name.startswith('fzgx_obj_') else name
    s = syms.get(base)
    m = None
    if exact:
        # the REL TU layouts' original reading: a dtk `.bss` symbol name only
        return s.addr if s is not None and s.section == '.bss' else None
    if s is None:
        m = re.fullmatch(r"(%s)(?:_fill_([0-9A-F]+)|(?:__fzgx_offset)?_([0-9A-F]+))" % LBL, base)
        s = syms.get(m.group(1)) if m else None
    if s is None and re.fullmatch(r"lbl_[0-9A-F]{8}", base):
        # a DOL label names its own address: an interior label of a dtk symbol
        a = int(base[4:], 16)
        s = _containing(syms, a)
        if s is not None and s.section in ((section,) if section else DATA_SECTIONS):
            return a
        return None
    if s is None or s.section not in ((section,) if section else DATA_SECTIONS):
        return None
    if m is None:
        return s.addr
    return int(m.group(2), 16) if m.group(2) else s.addr + int(m.group(3), 16)


def _included_text(body: str, depth: int = 4) -> str:
    """Text of the project headers `body` includes, transitively."""
    out, todo, seen = [], re.findall(r'(?m)^\s*#\s*include\s+"([^"]+)"', body), set()
    while todo and depth >= 0:
        nxt = []
        for inc in todo:
            path = tufile.ROOT / 'include' / inc
            if inc in seen or not path.is_file():
                continue
            seen.add(inc)
            t = path.read_text(errors='replace')
            out.append(t)
            nxt += re.findall(r'(?m)^\s*#\s*include\s+"([^"]+)"', t)
        todo, depth = nxt, depth - 1
    return "\n".join(out)


_SPANS: Dict[tuple, tuple] = {}


def _containing(syms, addr: int, section: Optional[str] = None):
    """The data symbol of `syms` (in `section`, else any data section: DOL addresses are
    unique, REL offsets are per section) whose extent holds `addr`."""
    key = (id(syms), section)
    spans = _SPANS.get(key)
    if spans is None or spans[0] is not syms:
        rows = sorted(((s.addr, s.size or 0, s) for s in syms.values()
                       if getattr(s, 'section', None) in ((section,) if section else DATA_SECTIONS)),
                      key=lambda r: (r[0], -r[1]))
        spans = _SPANS[key] = (syms, [r[0] for r in rows], rows)
    i = bisect.bisect_right(spans[1], addr) - 1
    if i >= 0:
        start, size, s = spans[2][i]
        if start <= addr < start + size:
            return s
    return None


def _section_of(name: str, syms) -> Optional[str]:
    base = name[len('fzgx_obj_'):] if name.startswith('fzgx_obj_') else name
    m = re.match(LBL, base)
    s = syms.get(m.group(0)) if m else None
    return s.section if s is not None and s.section in DATA_SECTIONS else None


def _typedefs(text: str) -> Dict[str, str]:
    """`typedef struct ... } Name;` definitions of a source, by name."""
    out = {}
    for m in re.finditer(r"(?m)^typedef\s+struct\s*\w*\s*\{", text):
        inner = fixup_layout._brace_body(text, m.end() - 1)
        if inner is None:
            continue
        end = m.end() + len(inner)
        tm = re.match(r"\}\s*(\w+)\s*;[ \t]*\n?", text[end:])
        if tm:
            out[tm.group(1)] = text[m.start():end + tm.end()]
    return out


def _sibling_sources(p, sym):
    """(name, text) of matched sources that can carry a layout of `sym`'s data: the other
    blocks of its TU, or, for a module without a TU map (the DOL's per-function units), every
    other matched source of the module's source directory that defines a layout."""
    tu = tufile.tu_source_for(p, sym)
    if tu:
        for block in tufile.load(p, tu).blocks:
            if block.name != sym.name:
                yield block.name, block.body
        return
    root = tufile.ROOT / 'src' / p.module_src_prefix(sym.module)
    if not root.is_dir():
        return
    for path in sorted(root.rglob('*.c')):
        if path.stem == sym.name:
            continue
        try:
            text = path.read_text(errors='replace')
        except OSError:
            continue
        if LAYOUT_COMMENT in text and 'fzgx_bss_layout' in text:
            yield path.stem, text


def sibling_layouts(p, sym) -> List[List[dict]]:
    """Every data-section layout a matched sibling of `sym` defines, as ordered object lists."""
    syms = p.symbols(sym.module)
    out, seen = [], set()
    strict_modes = (True, False) if tufile.tu_source_for(p, sym) else (False,)
    for _, body in _sibling_sources(p, sym):
        if 'fzgx_bss_layout' not in body:
            continue
        typedefs = None
        lines = body.splitlines()
        for strict, (i, line) in ((st, il) for st in strict_modes for il in enumerate(lines)):
            if not line.lstrip().startswith(LAYOUT_COMMENT):
                continue
            objs = []
            for ln in lines[i + 1:]:
                d = _decl(ln)
                if d is not None and strict and (d['spec'] or d['comment']):
                    d = None
                if d is None:
                    break
                base_t = re.sub(r"\b(?:volatile|const)\b", "", d['type']).strip()
                if '*' not in base_t and base_t not in SIZES:
                    typedefs = _typedefs(body) if typedefs is None else typedefs
                    if base_t in typedefs:
                        d['typedef'] = typedefs[base_t]
                objs.append(d)
            laid = _assign(objs, syms, strict)
            if laid:
                key = tuple((o['name'], o['addr'], o['size']) for o in laid)
                if key not in seen:
                    seen.add(key)
                    out.append(laid)
    for merged in _merged_layouts([l for l in out if not l[0].get('strict')], syms):
        key = tuple((o['name'], o['addr'], o['size']) for o in merged)
        if key not in seen:
            seen.add(key)
            out.append(merged)
    return out


def _merged_layouts(layouts: List[List[dict]], syms) -> List[List[dict]]:
    """Each sibling splits a cluster only where its own function needed an object, so the
    retail TU's objects are the union of every sibling's object starts (fn_80058D24 needs
    fn_80059428's `lbl_8018FF78_40` and fn_80058B54's `lbl_8018FF78_1C0` together). One
    merged layout per group of overlapping same-section layouts: an object spanning exactly
    two consecutive starts keeps its most common spelling, a longer array is cut at the next
    start, any other gap becomes a fill named by its address (fills never add a start)."""
    groups: List[List[List[dict]]] = []
    for lay in sorted(layouts, key=lambda l: l[0]['addr']):
        g = groups[-1] if groups else None
        if g and g[0][0].get('section') == lay[0].get('section') and \
                lay[0]['addr'] < max(l[-1]['addr'] + l[-1]['size'] for l in g):
            g.append(lay)
        else:
            groups.append([lay])
    out = []
    for g in groups:
        if len(g) < 2:
            continue
        # a fill is the gap a sibling left after its last needed byte, not a retail object
        named = [o for l in g for o in l if '_fill_' not in o['name']]
        # an end only bounds an object at a word boundary: a byte read (`u8 lbl_8018FF60`)
        # names the start of a larger retail object, not its extent
        starts = sorted({o['addr'] for o in named} | {o['addr'] + o['size'] for o in named if (o['addr'] + o['size']) % 4 == 0}
                        | {max(l[-1]['addr'] + l[-1]['size'] for l in g)})
        objs = []
        for a, b in zip(starts, starts[1:]):
            exact = [o for l in g for o in l if o['addr'] == a and o['size'] == b - a]
            if exact:
                spell = lambda o: (o['type'], tuple(o['dims']), o['name'])
                counts: Dict[tuple, int] = {}
                for o in exact:
                    counts[spell(o)] = counts.get(spell(o), 0) + 1
                best = max(exact, key=lambda o: counts[spell(o)])
                objs.append({k: v for k, v in best.items() if k not in ('addr', 'size', 'align')})
                continue
            longer = [o for l in g for o in l if o['addr'] == a and o['size'] > b - a and len(o['dims']) == 1]
            cut = None
            for o in longer:
                esz = _type_size(o['type'])
                if esz and (b - a) % esz[0] == 0:
                    cut = dict(o, dims=[str((b - a) // esz[0])])
                    cut = {k: v for k, v in cut.items() if k not in ('addr', 'size', 'align')}
                    break
            if cut is not None:
                objs.append(cut)
                continue
            n = b - a
            s = _containing(syms, a, g[0][0].get('section'))
            if s is not None and s.addr == a:
                name = s.name
            elif s is not None:
                name = f"{s.name}_fill_{a:X}"
            else:
                objs = None
                break
            if a % 4 == 0 and n % 4 == 0:
                t, dims = 'u32', ([str(n // 4)] if n > 4 else [])
            elif n == 1:
                t, dims = 'u8', []
            elif n == 2 and a % 2 == 0:
                t, dims = 'u16', []
            else:
                objs = None
                break
            objs.append(dict(spec=g[0][0].get('spec', ''), type=t, name=name, dims=dims, comment=''))
        if objs:
            laid = _assign(objs, syms)
            if laid:
                out.append(laid)
    return out


def _struct_size(tname: str, text: str) -> Optional[Tuple[int, int]]:
    """(size, alignment) of a flat struct of scalars, pointers and function pointers."""
    body = fixup_layout.struct_text(tname, text)
    if body is None:
        # a one-line anonymous typedef: `typedef struct { u32 fn; u32 arg; } CallbackPair;`
        td = _typedefs(text).get(tname)
        body = td[td.index('{') + 1:td.rindex('}')] if td else None
    if body is None or re.search(r"\b(?:struct|union)\s*\w*\s*\{", body):
        return None
    pos, align = 0, 1
    for _, (ftype, dims, _) in fixup_layout.field_decls(body).items():
        sz = (4, 4) if ftype is None else _type_size(ftype)
        if sz is None:
            return None
        n = sz[0]
        try:
            for d in dims:
                n *= int(d, 0)
        except ValueError:
            return None
        pos = (pos + sz[1] - 1) // sz[1] * sz[1] + n
        align = max(align, sz[1])
    return ((pos + align - 1) // align * align, align) if pos else None


def _assign(objs: List[dict], syms, strict: bool = False) -> Optional[List[dict]]:
    """Sequential addresses under natural alignment, anchored at the first object and checked
    against every name that encodes a retail address (an inconsistent layout is not used).
    A struct object is sized from its typedef, else from the next object's anchor. `strict`
    keeps the REL TU reading (dtk `.bss` names only, scalar types): the candidates it gave
    before DOL units and `.data` were read stay in the family."""
    if not objs:
        return None
    section = '.bss' if strict else _section_of(objs[0]['name'], syms)
    pos = _addr_hint(objs[0]['name'], syms, section, strict) if section else None
    if pos is None:
        return None
    for k, o in enumerate(objs):
        sz = _decl_size(o['type'], o['dims'])
        if sz is None and o.get('typedef') and not o['dims']:
            sz = _struct_size(re.sub(r"\b(?:volatile|const)\b", "", o['type']).strip(), o['typedef'])
        hint = _addr_hint(o['name'], syms, section, strict)
        if sz is None and strict:
            return None
        if sz is None:
            nxt = _addr_hint(objs[k + 1]['name'], syms, section) if k + 1 < len(objs) else None
            start = hint if hint is not None else pos
            if nxt is None or nxt <= start or '*' in o['type']:
                return None
            sz = (nxt - start, 4 if (nxt - start) % 4 == 0 and start % 4 == 0 else 1)
        size, align = sz
        pos = (pos + align - 1) // align * align
        if hint is not None and hint != pos:
            return None
        o['addr'], o['size'], o['align'], o['section'], o['strict'] = pos, size, align, section, strict
        pos += size
    return objs


def _ptr_view(t: str, dims: List[str]) -> str:
    return f"{t} (*){''.join('[%s]' % d for d in dims)}" if dims else f"{t} *"


class _Layout:
    def __init__(self, objs: List[dict]):
        self.objs = objs
        self.section = objs[0].get('section', '.bss')
        self.strict = bool(objs[0].get('strict'))
        self.start = objs[0]['addr']
        self.end = objs[-1]['addr'] + objs[-1]['size']

    def at(self, addr: int) -> Optional[dict]:
        return next((o for o in self.objs if o['addr'] == addr), None)

    def containing(self, addr: int) -> Optional[dict]:
        return next((o for o in self.objs if o['addr'] <= addr < o['addr'] + o['size']), None)

    def view(self, t: str, dims: List[str], addr: int) -> Optional[str]:
        """C expression for an object of type `t dims` at `addr`, over the layout's objects:
        an lvalue for a scalar, a pointer to the first element for an array."""
        o = self.at(addr)
        if o is not None and _norm(t) == _norm(o['type']) and list(dims) == list(o['dims']):
            return o['name']
        if o is not None:
            ref = f"&{o['name']}"
        else:
            o = self.containing(addr)
            if o is None:
                return None
            ref = f"((u8 *)&{o['name']} + 0x{addr - o['addr']:X})"
        if dims:
            inner = ''.join('[%s]' % d for d in dims[1:])
            return f"(({t} (*){inner}){ref})" if inner else f"(({t} *){ref})"
        if '(*)' in t:
            # a function pointer field: `void (*)(u32)` viewed through `void (**)(u32)`
            return f"(*({t.replace('(*)', '(**)', 1)}){ref})"
        return f"(*({t} *){ref})"


def _norm(t: str) -> str:
    return re.sub(r"\s+", "", t)


def _struct_fields(tname: str, body: str) -> Optional[Dict[str, Tuple[int, str, List[str]]]]:
    text = fixup_layout.struct_text(tname, body)
    if text is None:
        return None
    if re.search(r"\b(?:struct|union)\s*\w*\s*\{", text):
        return None
    out, pos = {}, 0
    for fname, (ftype, dims, raw) in fixup_layout.field_decls(text).items():
        if ftype is not None and '*' not in ftype and _type_size(ftype) is None:
            # a struct member: sized from its own definition
            sz = _struct_size(re.sub(r"\b(?:volatile|const|struct)\b", "", ftype).strip(), body)
        elif ftype is None:
            # a function pointer field keeps its type as an abstract declarator
            fm = re.match(r"\s*([\w\s\*]+?)\s*\(\s*\*\s*\w+\s*\)\s*(\([^)]*\))\s*;$", raw)
            if not fm or dims:
                return None
            ftype = re.sub(r"\s+", " ", fm.group(1)) + " (*)" + fm.group(2)
            sz = (4, 4)
        else:
            sz = _type_size(ftype)
        if sz is None:
            return None
        n = sz[0]
        try:
            for d in dims:
                n *= int(d, 0)
        except ValueError:
            return None
        pos = (pos + sz[1] - 1) // sz[1] * sz[1]
        out[fname] = (pos, ftype, dims)
        pos += n
    return out


def _cluster_name_addr(name: str, syms, lay: _Layout) -> Optional[int]:
    a = _addr_hint(name, syms, lay.section, lay.strict)
    return a if a is not None and lay.start <= a < lay.end else None


def _own_definitions(body: str, syms, lay: _Layout, sibling_names, members: bool = False) -> List[tuple]:
    """(line, type, name, dims, addr) of the body's file-scope definitions inside the cluster:
    its own layout block (addresses laid out like a sibling's) and resolvable top-level names."""
    out, seen = [], set()
    lines = body.splitlines(keepends=True)
    for i, line in enumerate(lines):
        if not line.lstrip().startswith(LAYOUT_COMMENT):
            continue
        objs, raw = [], []
        for ln in lines[i + 1:]:
            d = _decl(ln)
            if d is not None and not members and (d["spec"] or d["comment"]):
                d = None
            if d is None:
                break
            objs.append(d)
            raw.append(ln)
        laid = _assign(objs, syms, lay.strict)
        if laid and any(lay.start <= o['addr'] < lay.end for o in laid):
            for o, ln in zip(laid, raw):
                out.append((ln, o['type'], o['name'], o['dims'], o['addr']))
                seen.add(o['name'])
        break
    # with `members`: DOL spellings too (a `__declspec(section)` prefix, a zero initializer,
    # a trailing comment: fn_80058D24's `CallbackBlock lbl_8018FFB8 = {0};`)
    top = (r"(?m)^(?:__declspec\(section\s+\"[^\"]*\"\)[ \t]*)?((?:volatile\s+)?(?:unsigned\s+|signed\s+)?\w+(?:\s*\*+)?)[ \t]+(\w+)[ \t]*((?:\[[^\]]+\])*)[ \t]*(?:=[ \t]*(?:\{[ \t]*0[ \t]*\}|0)[ \t]*)?;[ \t]*(?:/\*[^\n]*?\*/[ \t]*)?\n"
           if members else r"(?m)^((?:volatile\s+)?(?:unsigned\s+|signed\s+)?\w+(?:\s*\*+)?)[ \t]+(\w+)[ \t]*((?:\[[^\]]+\])*)[ \t]*;[ \t]*\n")
    for m in re.finditer(top, body):
        if m.group(1).split()[0] in ('return', 'extern', 'typedef', 'static', 'goto') or m.group(2) in seen:
            continue
        a = _addr_hint(m.group(2), syms, lay.section, lay.strict)
        if a is None or not lay.start <= a < lay.end:
            continue
        out.append((m.group(0), re.sub(r"\s+", " ", m.group(1)), m.group(2),
                    re.findall(r"\[([^\]]+)\]", m.group(3)), a))
    return out


def _addr_expr(lay: _Layout, addr: int, cast: str) -> Optional[str]:
    """`(cast)` address of retail `addr` over the layout's objects."""
    o = lay.containing(addr)
    if o is None:
        return None
    if addr == o['addr']:
        return f"(({cast})&{o['name']})"
    return f"(({cast})((u8 *)&{o['name']} + 0x{addr - o['addr']:X}))"


def _model_arithmetic(text: str, n: str, baddr: int, lay: _Layout, failed: list) -> str:
    """A pointer model's byte and element arithmetic (`(u8 *)p + 0x30`, `&((T *)p)[22]`,
    `(u32)p | 0xB8`) addresses retail objects of the layout: rewrite each onto the object
    holding that address (fn_80059764's `(u32)state | 0xB8` is `&lbl_8018FF68`). The model's
    own declaration goes when nothing else uses it."""
    q = re.escape(n)

    def num(s):
        return int(s.rstrip('uUlL'), 0)

    def byte(mm):
        e = _addr_expr(lay, baddr + num(mm.group(2)), mm.group(1).strip())
        if e is None:
            failed.append(mm.group(0))
            return mm.group(0)
        return e
    text = re.sub(r"\(\s*((?:const\s+|volatile\s+)*(?:u8|s8|char|unsigned\s+char)\s*\*)\s*\)\s*\(?\s*%s\s*\)?\s*\+\s*(0[xX][0-9A-Fa-f]+|\d+)[uUlL]*\b" % q, byte, text)
    text = re.sub(r"\(\s*((?:u32|s32|unsigned\s+int|int))\s*\)\s*\(?\s*%s\s*\)?\s*[+|]\s*(0[xX][0-9A-Fa-f]+|\d+)[uUlL]*\b" % q, byte, text)

    def elem(mm):
        amp, t, k = mm.group(1), mm.group(2).strip(), num(mm.group(3))
        bare = re.sub(r"\b(?:volatile|const|struct)\b", "", t).strip()
        sz = _type_size(bare) or _struct_size(bare, text)
        v = lay.view(t, [], baddr + k * sz[0]) if sz else None
        if v is None:
            failed.append(mm.group(0))
            return mm.group(0)
        return f"(&{v})" if amp else v
    text = re.sub(r"(&\s*)?\(\s*\(\s*((?:const\s+|volatile\s+|struct\s+)*\w+)\s*\*\s*\)\s*%s\s*\)\s*\[\s*(0[xX][0-9A-Fa-f]+|\d+)\s*\]" % q, elem, text)
    # the model itself: its declaration goes when no use is left
    decl = re.search(r"(?m)^[ \t]*(?:(?:volatile|const)\s+)*(?:struct\s+)?\w+\s*\*\s*%s\s*=\s*[^;\n]*;[ \t]*\n" % q, text)
    if decl and not re.search(r"\b%s\b" % q, text[:decl.start()] + text[decl.end():]):
        text = text[:decl.start()] + text[decl.end():]
    return text


def transplant(p, sym, body: str, objs: List[dict], adopt_field_types: bool, members: bool = False) -> Optional[str]:
    """`members` adds the DOL model spellings (fn_80059764's earlier bodies): a volatile model's
    qualifier on every view, nested member chains (`s->state.unk_4`), the model's byte/element
    arithmetic, and only types visible through the body's own includes."""
    syms = p.symbols(sym.module)
    lay0 = _Layout(objs)
    text = body
    # the body's own definitions of cluster objects (an earlier layout) and its primer
    own = _own_definitions(body, syms, lay0, {o["name"] for o in objs}, members)
    merged = [dict(o) for o in objs]
    keep_names = set()
    own_defs = {}
    for line, t, name, dims, a in own:
        own_defs[name] = (t, dims, a)
        for o in merged:
            sz = _decl_size(t, dims)
            if o['addr'] == a and sz and o['size'] == sz[0] and o['dims'] == dims:
                o['type'], o['name'], o['src'] = t, name, 'body'
                keep_names.add(name)
    # a sibling-only object whose type the candidate cannot name: the body's own extern type
    # for that name when it has the same size, else an untyped pointer of the same size
    known = body + "\n" + fixup_layout.include_text()
    # a type the candidate can name: defined by the body or a header it includes (a struct
    # tag declared somewhere else under include/ is not in scope: `Object *`, fn_80053DB4)
    visible = (body + "\n" + _included_text(body)) if members else known
    typedefs = []
    for o in merged:
        base_t = re.sub(r"[\s*]|\b(?:volatile|const|unsigned|signed)\b", "", o['type'])
        if o.get('src') == 'body' or base_t in SIZES or re.search(r"(?:\}\s*|\btypedef\b[^;{}]*\b|\bstruct\s+)%s\b" % re.escape(base_t), visible):
            continue
        em = re.search(r"\nextern\s+((?:volatile\s+)?\w+(?:\s*\*+)?)\s+%s\s*((?:\[[^\]]+\])*)\s*;" % re.escape(o['name']), known)
        if em:
            t, dims = re.sub(r"\s+", " ", em.group(1)), re.findall(r"\[([^\]]+)\]", em.group(2))
            if _decl_size(t, dims) and _decl_size(t, dims)[0] == o['size']:
                o['type'], o['dims'] = t, dims
                continue
        if o.get('typedef'):
            # the sibling's own struct typedef travels with its object (DOL units name them
            # per function: `Cb_80059428`)
            if o['typedef'] not in typedefs:
                typedefs.append(o['typedef'])
            continue
        if '*' not in o['type']:
            return None
        o['type'] = 'void ' + '*' * o['type'].count('*')
    lay = _Layout(merged)
    # the body's old first-access primer goes with its definitions
    for pm in list(PRIMER.finditer(text)):
        if any(re.search(r"&\s*%s\b" % re.escape(n), pm.group(0)) for n in list(own_defs) + [o['name'] for o in objs]):
            text = text.replace(pm.group(0), '')
    # struct views of a cluster object: pointer models and direct `lbl.field` uses
    bases = {}
    cast = (r"\(\s*(?:(?:volatile|const)\s+)*(?:struct\s+)?(\w+)\s*\*\s*\)\s*&\s*(%s)\b(?!\s*[\[.])" % LBL if members
            else r"\((?:struct\s+)?(\w+)\s*\*\)\s*&\s*(lbl_\d+_bss_[0-9A-F]+)\b(?!\s*[\[.])")
    for m in re.finditer(cast, text):
        if _type_size(m.group(1)) is None and _cluster_name_addr(m.group(2), syms, lay) is not None:
            bases.setdefault(m.group(2), set()).add(m.group(1))
    # an uncast pointer model over the header's own type: `volatile T *p = &lbl;`
    for m in re.finditer(r"(?m)^[ \t]*(?:(?:volatile|const)\s+)*(?:struct\s+)?(\w+)\s*\*\s*\w+\s*=\s*&\s*(%s)\s*;" % LBL, text if members else ''):
        if _type_size(m.group(1)) is None and _cluster_name_addr(m.group(2), syms, lay) is not None:
            bases.setdefault(m.group(2), set()).add(m.group(1))
    for m in re.finditer(r"(?<![\w.>])(%s)\s*\.\s*\w+" % LBL, text):
        if _cluster_name_addr(m.group(1), syms, lay) is None:
            continue
        hm = re.search(r"\nextern\s+(?:struct\s+)?(\w+)\s+%s\s*;" % re.escape(m.group(1)), text + "\n" + fixup_layout.include_text())
        if not hm:
            return None
        bases.setdefault(m.group(1), set()).add('.' + hm.group(1))
    adopted = {}
    for base, tnames in bases.items():
        baddr = syms[base].addr
        for tn in tnames:
            direct = tn.startswith('.')
            tn = tn.lstrip('.')
            fields = _struct_fields(tn, text)
            if fields is None:
                return None
            if direct:
                names = [base]
                pat = r"(?<![\w.>])(%s)\s*\.\s*(\w+)((?:\s*\.\s*\w+)*)"
            else:
                names = set(re.findall(r"\b(?:struct\s+)?%s\s*\*\s*(\w+)" % re.escape(tn), text))
                for mm in re.finditer(r"(?m)^[ \t]*#\s*define\s+\w+\(([^)]*)\)(.*)$", text):
                    for arg in [a.strip() for a in mm.group(1).split(',')]:
                        if re.search(r"\(\s*%s\s*\)\s*->\s*(\w+)" % re.escape(arg), mm.group(2)):
                            names.add(arg)
                names = sorted(n for n in names if n not in ('const', 'volatile'))
                pat = r"(?:\(\s*(%s)\s*\)|(?<![\w.>])(%s))\s*->\s*(\w+)((?:\s*\.\s*\w+)*)"
            for n in names:
                failed = []
                qual = 'volatile ' if members and not direct and re.search(
                    r"\bvolatile\s+(?:struct\s+)?%s\s*\*\s*%s\b" % (re.escape(tn), re.escape(n)), text) else ''

                def sub(mm, direct=direct, qual=qual):
                    fname = mm.group(2) if direct else mm.group(3)
                    chain = re.findall(r"\w+", mm.group(3) if direct else mm.group(4))
                    f = fields.get(fname)
                    if f is None:
                        failed.append(fname)
                        return mm.group(0)
                    off, ft, fdims = f
                    # a nested struct member (`s->state.unk_4`): follow the chain to the leaf
                    tail = mm.group(3) if direct else mm.group(4)
                    whole = len(chain)
                    while members and chain and not fdims:
                        inner = _struct_fields(re.sub(r"\b(?:volatile|const|struct)\b", "", ft).strip(), text)
                        g = inner.get(chain[0]) if inner else None
                        if g is None:
                            break
                        if 'volatile' in ft and not qual:
                            qual = 'volatile '
                        off, ft, fdims = off + g[0], g[1], g[2]
                        chain.pop(0)
                    rest = tail if len(chain) == whole else ''.join('.' + c for c in chain)
                    if adopt_field_types and not fdims:
                        o = lay.at(baddr + off)
                        sz = _type_size(ft)
                        if o and o.get('src') != 'body' and not o['dims'] and sz and sz[0] == o['size'] \
                                and adopted.get(o['name'], ft) == ft:
                            adopted[o['name']] = ft
                            o['type'] = ft
                    if qual and not ft.startswith('volatile') and '(*)' not in ft:
                        ft = qual + ft
                    v = lay.view(ft, fdims, baddr + off)
                    if v is None:
                        failed.append(fname)
                        return mm.group(0)
                    return v + rest
                if direct:
                    text = re.sub(pat % re.escape(n), sub, text)
                else:
                    text = re.sub(pat % (re.escape(n), re.escape(n)), sub, text)
                    if members:
                        text = _model_arithmetic(text, n, baddr, lay, failed)
                if failed:
                    if DEBUG:
                        print('transplant declined:', failed)
                    return None
    if adopt_field_types and not adopted:
        return None
    # views written before an adopted type changed spell the old type: recompute them
    if adopted:
        for o in lay.objs:
            if o['name'] in adopted:
                text = re.sub(r"\(\*\(%s \*\)&%s\)" % (re.escape(adopted[o['name']]), re.escape(o['name'])), o['name'], text)
    # remaining address uses of a view base, and scalar names of the cluster
    for base in bases:
        o = lay.at(syms[base].addr)
        if o is None:
            return None
        text = re.sub(r"&\s*%s\b(?!\s*[\[.])" % re.escape(base), f"((void *)&{o['name']})", text)
    decl_lines = set()
    for m in re.finditer(r"(?m)^[ \t]*extern\s+[^;\n(]*?\b((?:fzgx_obj_)?%s)\s*((?:\[[^\]]*\])*)\s*;[ \t]*\n" % LBL, text):
        if _cluster_name_addr(m.group(1), syms, lay) is not None:
            decl_lines.add(m.group(0))
    for line in decl_lines:
        text = text.replace(line, '')
    # body-defined objects that the merged layout does not keep, and cluster externs
    rename = {}
    for name, (t, dims, a) in own_defs.items():
        if name not in keep_names:
            v = lay.view(t, dims, a)
            if v is None:
                return None
            rename[name] = v
    for name in set(re.findall(r"\b(%s)\b" % LBL, text)):
        a = _cluster_name_addr(name, syms, lay)
        if a is None or name in {o['name'] for o in lay.objs} or name in bases or (members and name in rename):
            continue
        hm = re.search(r"\nextern\s+((?:volatile\s+)?\w+(?:\s*\*+)?)\s+%s\s*((?:\[[^\]]*\])*)\s*;" % re.escape(name), body + "\n" + fixup_layout.include_text())
        if not hm:
            return None
        v = lay.view(re.sub(r"\s+", " ", hm.group(1)), re.findall(r"\[([^\]]*)\]", hm.group(2)), a)
        if v is None:
            return None
        rename[name] = v
    # cut the old definitions and primer, then splice the layout in where they were
    m = re.search(r"(?m)^[ \t]*/\* file-scope objects of the retail TU[^\n]*\*/[ \t]*\n", text)
    if m:
        text = text[:m.start()] + "@@FZGX_LAYOUT@@" + text[m.end():]
    for line, *_ in own:
        if "@@FZGX_LAYOUT@@" not in text:
            text = text.replace(line, "@@FZGX_LAYOUT@@", 1)
        else:
            text = text.replace(line, "", 1)
    for name, v in rename.items():
        text = re.sub(r"(?<![\w.>])%s\b" % re.escape(name), lambda _m, v=v: v, text)
    block = [t.rstrip('\n') for t in typedefs if t not in text]
    block += [LAYOUT_COMMENT + ' (from a matched sibling), in retail order: MWCC addresses them off one section base */']
    for o in lay.objs:
        spec = o.get('spec') or ''
        note = o.get('comment') or ''
        if not note and 'volatile' in o['type']:
            note = '/* fzgx-allow: S2 the matched sibling\'s layout keeps this object volatile */'
        block.append(f"{spec + ' ' if spec else ''}{o['type']} {o['name']}{''.join('[%s]' % d for d in o['dims'])};{' ' + note if note else ''}")
    primer = 'fzgx_bss_layout' if not re.search(r"fzgx_bss_layout\s*\(", text) else f'fzgx_bss_layout_{lay.start:X}'
    block += ['', '#pragma section code_type ".fzgxpool"', f'static void {primer}(void) {{',
              '    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */']
    block += [f"    s = *(u8 *)&{o['name']};" for o in lay.objs]
    block += ['}', '#pragma section code_type ".text"', '']
    block = "\n".join(block) + "\n"
    if "@@FZGX_LAYOUT@@" in text:
        text = text.replace("@@FZGX_LAYOUT@@", block, 1)
    else:
        fm = re.search(r"(?m)^(?:static\s+)?(?:inline\s+)?(?:const\s+)?(?:struct\s+)?\w+[\w\s\*]*?\b\w+\s*\([^;{}]*\)\s*\{", text)
        if not fm:
            return None
        text = text[:fm.start()] + block + "\n" + text[fm.start():]
    return text if text != body else None


def sibling_section_layouts(p, symbol, body, check=None) -> List[Tuple[str, str]]:
    """Proposals: each matched sibling's layout of a `.bss` cluster the body addresses."""
    if 'lbl_' not in body and 'fzgx_obj_' not in body:
        return []
    sym = p.resolve(symbol)
    if sym is None:
        return []
    try:
        layouts = sibling_layouts(p, sym)
    except (OSError, ValueError, KeyError):
        return []
    syms = p.symbols(sym.module)
    out = []
    for objs in layouts:
        lay = _Layout(objs)
        refs = [n for n in set(re.findall(r"\b((?:fzgx_obj_)?%s)\b" % LBL, body))
                if _cluster_name_addr(n, syms, lay) is not None]
        if not refs:
            continue
        for adopt, members in ((False, False), (True, False), (False, True), (True, True)):
            try:
                text = transplant(p, sym, body, [dict(o) for o in objs], adopt, members)
            except (ValueError, KeyError, IndexError, AttributeError, re.error, StopIteration):
                text = None
            if text and text not in {t for _, t in out}:
                label = f"transplant sibling {lay.section.lstrip('.')} layout 0x{lay.start:X}..0x{lay.end:X}" + (' (field types)' if adopt else '') \
                    + (' (member arithmetic)' if members else '')
                out.append((label, text))
                # layout position of each object: held locals declared in address order too
                addrs = {}
                for line in text.splitlines():
                    if line[:1].isspace():
                        continue
                    d = _decl(line)
                    if d:
                        addrs.setdefault(d['name'], len(addrs))
                for order in ('argument', 'address', 'reversed address'):
                    held = held_helper_addresses(text, addrs, order)
                    if held and held not in {t for _, t in out}:
                        out.append((label + f', helper address arguments held in locals ({order} order)', held))
    return out


def _split_args(s: str) -> Optional[List[str]]:
    out, depth, cur = [], 0, ''
    for ch in s:
        if ch == ',' and depth == 0:
            out.append(cur.strip()); cur = ''
            continue
        depth += ch in '([{'
        depth -= ch in ')]}'
        if depth < 0:
            return None
        cur += ch
    if cur.strip():
        out.append(cur.strip())
    return out


def held_helper_addresses(text: str, objects: Dict[str, int], order: str = 'argument') -> Optional[str]:
    """`helper(p, &obj, ...);` with `helper` a static inline: hold each object address argument
    in a block-scoped pointer local of the parameter's type. An address passed straight into
    an inline parameter is propagated as a constant (rematerialized per use); held in a local
    it stays a register value `addi rX, rBase, off` as retail keeps it (fn_1_14B62C:
    92.6% -> 96.6% beside the transplanted layout, the matched fn_1_14B1FC's spelling)."""
    helpers = {}
    for m in re.finditer(r"(?m)^static\s+inline\s+[\w\s\*]*?\b(\w+)\s*\(([^;{}()]*)\)\s*\{", text):
        params = _split_args(m.group(2)) or []
        types = []
        for prm in params:
            pm = re.match(r"(.*?\*)\s*(\w+)$", prm.strip())
            types.append(re.sub(r"\s+", " ", pm.group(1)).strip() if pm else None)
        helpers[m.group(1)] = types
    if not helpers:
        return None
    count = [0]

    def sub(m):
        indent, name, args = m.group(1), m.group(2), _split_args(m.group(3))
        types = helpers.get(name)
        if args is None or types is None or len(args) != len(types):
            return m.group(0)
        decls = []
        for i, a in enumerate(args):
            am = re.fullmatch(r"&\s*(\w+)|\(\(void \*\)&(\w+)\)|&\(\*\([^()]*\)&(\w+)\)", a)
            obj = am and next(g for g in am.groups() if g)
            if obj and obj in objects and types[i]:
                local = f'fzgx_held{count[0]}'; count[0] += 1
                decls.append((objects[obj], f"{types[i]} {local} = ({types[i]})&{obj};"))
                args[i] = local
        if not decls:
            return m.group(0)
        if order != 'argument':
            decls.sort(reverse=order.startswith('reversed'))
        return f"{indent}{{ {' '.join(d for _, d in decls)} {name}({', '.join(args)}); }}\n"
    pat = r"(?m)^([ \t]*)(%s)\s*\(((?:[^;()]|\([^;()]*(?:\([^;()]*\)[^;()]*)*\))*)\)\s*;[ \t]*\n" % '|'.join(map(re.escape, helpers))
    out = re.sub(pat, sub, text)
    return out if out != text else None
