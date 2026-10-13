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

import re
from typing import Dict, List, Optional, Tuple

from . import fixup_layout, tufile

SIZES = {'u8': 1, 's8': 1, 'char': 1, 'BOOL8': 1, 'u16': 2, 's16': 2, 'short': 2,
         'u32': 4, 's32': 4, 'int': 4, 'long': 4, 'f32': 4, 'float': 4, 'BOOL': 4,
         'f64': 8, 'double': 8, 'u64': 8, 's64': 8}
LAYOUT_COMMENT = '/* file-scope objects of the retail TU'
DECL = re.compile(r"^((?:volatile\s+|const\s+)*(?:unsigned\s+|signed\s+)?\w+(?:\s*\*+)?)\s*(\w+)\s*((?:\[[^\]]+\])*)\s*;\s*$")
PRIMER = re.compile(r"#pragma section code_type \"\.fzgxpool\"\s*\nstatic void (fzgx_bss_layout\w*)\(void\) \{.*?\n\}\s*\n#pragma section code_type \"\.text\"\s*\n", re.S)


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


def _addr_hint(name: str, syms) -> Optional[int]:
    base = name[len('fzgx_obj_'):] if name.startswith('fzgx_obj_') else name
    s = syms.get(base)
    if s is not None and s.section == '.bss':
        return s.addr
    return None


def sibling_layouts(p, sym) -> List[List[dict]]:
    """Every `.bss` layout a matched block of `sym`'s TU defines, as ordered object lists."""
    tu = tufile.tu_source_for(p, sym)
    if not tu:
        return []
    tf = tufile.load(p, tu)
    syms = p.symbols(sym.module)
    out, seen = [], set()
    for block in tf.blocks:
        if block.name == sym.name or 'fzgx_bss_layout' not in block.body:
            continue
        lines = block.body.splitlines()
        for i, line in enumerate(lines):
            if not line.lstrip().startswith(LAYOUT_COMMENT):
                continue
            objs = []
            for ln in lines[i + 1:]:
                m = DECL.match(ln.strip())
                if not m or ln.strip().startswith(('return', 'extern', 'typedef', 'static')):
                    break
                t, name = re.sub(r"\s+", " ", m.group(1)), m.group(2)
                dims = re.findall(r"\[([^\]]+)\]", m.group(3))
                objs.append(dict(type=t, name=name, dims=dims))
            laid = _assign(objs, syms)
            if laid:
                key = tuple((o['name'], o['addr'], o['size']) for o in laid)
                if key not in seen:
                    seen.add(key)
                    out.append(laid)
    return out


def _assign(objs: List[dict], syms) -> Optional[List[dict]]:
    """Sequential addresses under natural alignment, anchored at the first object and checked
    against every name that is a real dtk symbol (an inconsistent layout is not used)."""
    if not objs:
        return None
    pos = _addr_hint(objs[0]['name'], syms)
    if pos is None:
        return None
    for o in objs:
        sz = _decl_size(o['type'], o['dims'])
        if sz is None:
            return None
        size, align = sz
        pos = (pos + align - 1) // align * align
        hint = _addr_hint(o['name'], syms)
        if hint is not None and hint != pos:
            return None
        o['addr'], o['size'], o['align'] = pos, size, align
        pos += size
    return objs


def _ptr_view(t: str, dims: List[str]) -> str:
    return f"{t} (*){''.join('[%s]' % d for d in dims)}" if dims else f"{t} *"


class _Layout:
    def __init__(self, objs: List[dict]):
        self.objs = objs
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
    for fname, (ftype, dims, _) in fixup_layout.field_decls(text).items():
        if ftype is None:
            return None
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
    a = _addr_hint(name, syms)
    return a if a is not None and lay.start <= a < lay.end else None


def _own_definitions(body: str, syms, lay: _Layout, sibling_names) -> List[tuple]:
    """(line, type, name, dims, addr) of the body's file-scope definitions inside the cluster:
    its own layout block (addresses laid out like a sibling's) and resolvable top-level names."""
    out, seen = [], set()
    lines = body.splitlines(keepends=True)
    for i, line in enumerate(lines):
        if not line.lstrip().startswith(LAYOUT_COMMENT):
            continue
        objs, raw = [], []
        for ln in lines[i + 1:]:
            m = DECL.match(ln.strip())
            if not m or ln.strip().startswith(('return', 'extern', 'typedef', 'static')):
                break
            objs.append(dict(type=re.sub(r"\s+", " ", m.group(1)), name=m.group(2),
                             dims=re.findall(r"\[([^\]]+)\]", m.group(3))))
            raw.append(ln)
        laid = _assign(objs, syms)
        if laid and any(lay.start <= o['addr'] < lay.end for o in laid):
            for o, ln in zip(laid, raw):
                out.append((ln, o['type'], o['name'], o['dims'], o['addr']))
                seen.add(o['name'])
        break
    for m in re.finditer(r"(?m)^((?:volatile\s+)?(?:unsigned\s+|signed\s+)?\w+(?:\s*\*+)?)[ \t]+(\w+)[ \t]*((?:\[[^\]]+\])*)[ \t]*;[ \t]*\n", body):
        if m.group(1).split()[0] in ('return', 'extern', 'typedef', 'static', 'goto') or m.group(2) in seen:
            continue
        a = _addr_hint(m.group(2), syms)
        if a is None or not lay.start <= a < lay.end:
            continue
        out.append((m.group(0), re.sub(r"\s+", " ", m.group(1)), m.group(2),
                    re.findall(r"\[([^\]]+)\]", m.group(3)), a))
    return out


def transplant(p, sym, body: str, objs: List[dict], adopt_field_types: bool) -> Optional[str]:
    syms = p.symbols(sym.module)
    lay0 = _Layout(objs)
    text = body
    # the body's own definitions of cluster objects (an earlier layout) and its primer
    own = _own_definitions(body, syms, lay0, {o['name'] for o in objs})
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
    for o in merged:
        base_t = re.sub(r"[\s*]|\b(?:volatile|const|unsigned|signed)\b", "", o['type'])
        if o.get('src') == 'body' or base_t in SIZES or re.search(r"(?:\}\s*|\btypedef\b[^;{}]*\b|\bstruct\s+)%s\b" % re.escape(base_t), known):
            continue
        em = re.search(r"\nextern\s+((?:volatile\s+)?\w+(?:\s*\*+)?)\s+%s\s*((?:\[[^\]]+\])*)\s*;" % re.escape(o['name']), known)
        if em:
            t, dims = re.sub(r"\s+", " ", em.group(1)), re.findall(r"\[([^\]]+)\]", em.group(2))
            if _decl_size(t, dims) and _decl_size(t, dims)[0] == o['size']:
                o['type'], o['dims'] = t, dims
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
    for m in re.finditer(r"\((?:struct\s+)?(\w+)\s*\*\)\s*&\s*(lbl_\d+_bss_[0-9A-F]+)\b(?!\s*[\[.])", text):
        if _type_size(m.group(1)) is None and _cluster_name_addr(m.group(2), syms, lay) is not None:
            bases.setdefault(m.group(2), set()).add(m.group(1))
    for m in re.finditer(r"(?<![\w.>])(lbl_\d+_bss_[0-9A-F]+)\s*\.\s*\w+", text):
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
                pat = r"(?<![\w.>])(%s)\s*\.\s*(\w+)"
            else:
                names = set(re.findall(r"\b(?:struct\s+)?%s\s*\*\s*(\w+)" % re.escape(tn), text))
                for mm in re.finditer(r"(?m)^[ \t]*#\s*define\s+\w+\(([^)]*)\)(.*)$", text):
                    for arg in [a.strip() for a in mm.group(1).split(',')]:
                        if re.search(r"\(\s*%s\s*\)\s*->\s*(\w+)" % re.escape(arg), mm.group(2)):
                            names.add(arg)
                names = sorted(n for n in names if n not in ('const', 'volatile'))
                pat = r"(?:\(\s*(%s)\s*\)|(?<![\w.>])(%s))\s*->\s*(\w+)"
            for n in names:
                failed = []

                def sub(mm, direct=direct):
                    fname = mm.group(2) if direct else mm.group(3)
                    f = fields.get(fname)
                    if f is None:
                        failed.append(fname)
                        return mm.group(0)
                    off, ft, fdims = f
                    if adopt_field_types and not fdims:
                        o = lay.at(baddr + off)
                        sz = _type_size(ft)
                        if o and o.get('src') != 'body' and not o['dims'] and sz and sz[0] == o['size'] \
                                and adopted.get(o['name'], ft) == ft:
                            adopted[o['name']] = ft
                            o['type'] = ft
                    v = lay.view(ft, fdims, baddr + off)
                    if v is None:
                        failed.append(fname)
                        return mm.group(0)
                    return v
                if direct:
                    text = re.sub(pat % re.escape(n), sub, text)
                else:
                    text = re.sub(pat % (re.escape(n), re.escape(n)), sub, text)
                if failed:
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
    for m in re.finditer(r"(?m)^[ \t]*extern\s+[^;\n(]*?\b(lbl_\d+_bss_[0-9A-F]+|fzgx_obj_lbl_\d+_bss_[0-9A-F]+)\s*((?:\[[^\]]*\])*)\s*;[ \t]*\n", text):
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
    for name in set(re.findall(r"\b(lbl_\d+_bss_[0-9A-F]+)\b", text)):
        a = _cluster_name_addr(name, syms, lay)
        if a is None or name in {o['name'] for o in lay.objs} or name in bases:
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
    block = [LAYOUT_COMMENT + ' (from a matched sibling), in retail order: MWCC addresses them off one section base */']
    for o in lay.objs:
        block.append(f"{o['type']} {o['name']}{''.join('[%s]' % d for d in o['dims'])};")
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
        refs = [n for n in set(re.findall(r"\b((?:fzgx_obj_)?lbl_\d+_bss_[0-9A-F]+)\b", body))
                if _cluster_name_addr(n, syms, lay) is not None]
        if not refs:
            continue
        for adopt in (False, True):
            try:
                text = transplant(p, sym, body, [dict(o) for o in objs], adopt)
            except (ValueError, KeyError, IndexError, AttributeError, re.error, StopIteration):
                text = None
            if text and text not in {t for _, t in out}:
                label = f"transplant sibling bss layout 0x{lay.start:X}..0x{lay.end:X}" + (' (field types)' if adopt else '')
                out.append((label, text))
                names = {m.group(1) for m in re.finditer(r"(?m)^(?:volatile\s+)?\w+(?:\s*\*+)?\s+(\w+)\s*(?:\[[^\]]+\])*\s*;", text)}
                # layout position of each object: held locals declared in address order too
                addrs = {}
                for line in text.splitlines():
                    m = DECL.match(line.strip())
                    if m and m.group(2) in names:
                        addrs.setdefault(m.group(2), len(addrs))
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
