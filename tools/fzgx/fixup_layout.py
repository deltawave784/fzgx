"""Retail translation units define their file-scope objects and string literals in one place,
and MWCC then addresses every object of a section off one base register: object addresses are
materialized (`addi rX, rBase, off`, even at offset 0) whenever a pointer value is needed, and
only an object's offset 0 is addressed base-relative. A per-function unit that declares the
cluster as one extern struct can never reproduce that shape. This family defines the retail
objects in the unit, in retail order under MWCC's file-scope layout rules (scalars at natural
alignment, arrays 4-aligned, `.bss` objects emitted in first-access order, string literals in
first-use order), with primers in `.fzgxpool` that fix the emission order. Field offsets and
sizes come from an MWCC probe compile of the body's own declarations. The oracle binds the
anonymous section bases (`...bss.N`, `...data.N`) to the retail symbols; the private copies are
dropped at integration. Names a module header declares with another layout are defined under
the `fzgx_obj_` alias, which the BSS base binding accepts."""
from __future__ import annotations

import hashlib
import re
from pathlib import Path

from . import oracle, poolfix
from .project import ROOT, STATE_DIR


INCLUDE_TEXT = None
SCALAR = {'u8': 1, 's8': 1, 'char': 1, 'u16': 2, 's16': 2, 'u32': 4, 's32': 4, 'int': 4, 'f32': 4, 'float': 4, 'f64': 8, 'double': 8, 'u64': 8, 's64': 8, 'void': 1}


def include_text():
    global INCLUDE_TEXT
    if INCLUDE_TEXT is None:
        INCLUDE_TEXT = "\n".join(p.read_text(errors='replace') for p in (ROOT / 'include').rglob('*.h'))
    return INCLUDE_TEXT


class Gap:
    def __init__(self, name, addr, end, section):
        self.name, self.addr, self.end, self.size, self.section, self.kind = name, addr, end, end - addr, section, 'object'


def bss_member_bindings(p, symbol, body, obj, check):
    """Name generated layout pieces using their measured retail subobjects."""
    if not obj or not check.ok:
        return []
    elf = poolfix.Elf(Path(obj).read_bytes())
    section = elf.section('.bss')
    if section is None:
        return []
    own = {s['name']: s for s in elf.symbols()}
    module = p.resolve(symbol).module
    retail = p.symbols(module)
    origins = set()
    for private, target, _ in check._pool_pairs:
        anchor = own.get(private)
        name, offset = poolfix.binding_target(target)
        known = retail.get(name)
        if (private.startswith('...bss') and anchor and known
                and anchor['shndx'] == section['index'] and known.section == '.bss'):
            origins.add(known.addr + offset - anchor['value'])
    if len(origins) != 1:
        return []
    origin = origins.pop()
    objects = [s for s in retail.values() if s.kind == 'object' and s.section == '.bss']
    bound = {private for private, _, _ in check._pool_pairs}
    names = {}
    for name, s in own.items():
        if (s['shndx'] != section['index'] or not s['size'] or s['info'] & 15 != 1
                or name in bound or name.startswith('fzgx_pool_') or '__fzgx_offset_' in name):
            continue
        generated = re.fullmatch(r'(.+)_(?:gap|fill)_[0-9A-F]+(?:_fill_[0-9A-F]+)?', name)
        padding = generated or re.fullmatch(r'(?:sdk_)?gap____bss_\d+_[0-9A-Fa-f]+', name)
        member = re.fullmatch(r'(.+)_([0-9A-F]+)', name)
        synthetic = name.startswith('lbl_') and name not in retail
        native = s['info'] == 1 and name not in retail
        if not generated and not synthetic and not native and not (member and member[1] in retail and name not in retail):
            continue
        address = origin + s['value']
        owner = next((o for o in objects if o.addr <= address and address + s['size'] <= o.end), None)
        if owner:
            names[name] = owner.name + f'__fzgx_offset_{address-owner.addr:X}'
        elif padding and 'gap' in name:
            # The linker drops private padding only after all relocations to
            # its section have gone; live uses still prevent externalization.
            names[name] = 'fzgx_pool_' + name
    if not names:
        return []
    text = re.sub(r'\b\w+\b', lambda m: names.get(m[0], m[0]), body)
    return [('canonical BSS subobjects and private layout padding', text)]


def private_data_objects(body, obj, check):
    """Mark file-local storage inside an oracle-proven shared section copy."""
    if not obj or not check.ok or not any(a.startswith('...data') for a, _, _ in check._pool_pairs):
        return []
    elf = poolfix.Elf(Path(obj).read_bytes())
    section = elf.section('.data')
    if section is None:
        return []
    names = {}
    for s in elf.symbols():
        name = s['name']
        if (s['shndx'] != section['index'] or not s['size'] or s['info'] != 1
                or name.startswith(('@', 'fzgx_pool_'))):
            continue
        if re.search(r'(?m)^static\s+[^;{}=\n]+\b'+re.escape(name)+r'\b\s*(?:\[|=)', body):
            names[name] = 'fzgx_pool_' + name
    if not names:
        return []
    text = re.sub(r'\b\w+\b', lambda m: names.get(m[0], m[0]), body)
    return [('private objects in verified shared data section', text)]


def _brace_body(src, opening):
    """Text between the `{` at `opening` and its matching `}`, or None."""
    depth = 0
    for i in range(opening, len(src)):
        if src[i] == '{':
            depth += 1
        elif src[i] == '}':
            depth -= 1
            if depth == 0:
                return src[opening + 1:i]
    return None


def struct_text(tname, text):
    for src in (text, include_text()):
        # the matching brace, not the first `\n}` after the tag: a one-line definition
        # (`typedef struct State { u32 size, unused; Body body; } State;`, fn_12_24C48)
        # otherwise ran on into the next function's body
        m = re.search(r"(?:typedef\s+)?struct\s+%s\s*\{" % re.escape(tname), src)
        if m:
            inner = _brace_body(src, m.end() - 1)
            if inner is not None:
                return inner
        m = re.search(r"(?:typedef\s+)?struct\s+%s\s*\{(.*?)\n\}" % re.escape(tname), src, re.S)
        if m:
            return m.group(1)
        m = re.search(r"typedef\s+struct\s*\w*\s*\{([^{}]*)\n\}\s*%s\s*;" % re.escape(tname), src, re.S)
        if m:
            return m.group(1)
    return None


def field_decls(body):
    """field name -> (type text incl. stars, dims list, raw line)."""
    out = {}
    body = re.sub(r"/\*.*?\*/", "", body, flags=re.S)
    body = re.sub(r"//[^\n]*", "", body)
    for line in body.replace('\n', ' ').split(';'):
        line = line.strip() + ';'
        if line == ';':
            continue
        m = re.match(r"((?:const\s+|volatile\s+|unsigned\s+|signed\s+)*(?:struct\s+|union\s+|enum\s+)?\w+(?:\s*\*+)?)\s*(\w+)((?:\[[^\]]+\])*);$", line)
        if m:
            ttext = re.sub(r"\s+", " ", m.group(1)).replace(" *", " *")
            dims = re.findall(r"\[([^\]]+)\]", m.group(3) or '')
            out[m.group(2)] = (ttext, dims, line)
            continue
        # comma declarators: `u32 size, unused;`, `u8 *a, b[4];` (the stars bind per name)
        cm = re.match(r"((?:const\s+|volatile\s+|unsigned\s+|signed\s+)*(?:struct\s+|union\s+|enum\s+)?\w+)\s+([^;(){}]*,[^;(){}]*);$", line)
        if cm:
            base = re.sub(r"\s+", " ", cm.group(1))
            parts = [re.match(r"\s*(\**)\s*(\w+)\s*((?:\[[^\]]+\])*)\s*$", d) for d in cm.group(2).split(',')]
            if all(parts):
                for d in parts:
                    ttext = base + (' ' + d.group(1) if d.group(1) else '')
                    out[d.group(2)] = (ttext, re.findall(r"\[([^\]]+)\]", d.group(3) or ''), f"{ttext} {d.group(2)}{d.group(3)};")
                continue
        pm = re.match(r"([\w\s\*]+)\(\s*\*\s*(\w+)\s*((?:\[[^\]]+\])*)\s*\)\s*(\([^)]*\));$", line)
        if pm:
            # a function pointer or an array of them: `void (*funcs[5])(void);`
            out[pm.group(2)] = (None, re.findall(r"\[([^\]]+)\]", pm.group(3) or ''), line)
    return out


def pointer_typedef(tname, text):
    """A typedef naming a pointer type: `typedef void (*Handler)(T *);` or `typedef T *P;`."""
    if tname is None:
        return True
    if '*' in tname:
        return True
    for src in (text, include_text()):
        if re.search(r"\btypedef\b[^;{}]*\(\s*\*\s*%s\s*\)\s*\(" % re.escape(tname), src):
            return True
        if re.search(r"\btypedef\s+(?:struct\s+)?\w+\s*\*\s*%s\s*;" % re.escape(tname), src):
            return True
    return False


def probe_layout(p, module, prefix, tname, names, decls, tag):
    """offsets/sizes/elemsizes/aligns of the named fields of struct type tname, from MWCC."""
    lines = []
    for i, n in enumerate(names):
        ttext, dims, raw = decls[n]
        lines.append(f"u8 fzgx_off_{i}[1 + (u32)&(({tname} *)0)->{n}];")
        lines.append(f"u8 fzgx_sz_{i}[sizeof((({tname} *)0)->{n})];")
        sub = ''.join('[0]' for _ in dims)
        lines.append(f"u8 fzgx_esz_{i}[sizeof((({tname} *)0)->{n}{sub})];")
        if ttext is None:
            lines.append(f"u8 fzgx_al_{i}[4];")
        else:
            lines.append(f"struct fzgx_al_{i}_s {{ u8 c; {ttext} t; }};")
            lines.append(f"u8 fzgx_al_{i}[(u32)&((struct fzgx_al_{i}_s *)0)->t];")
    src = prefix + "\n" + "\n".join(lines) + "\n"
    d = STATE_DIR / 'fixup' / 'probe'
    d.mkdir(parents=True, exist_ok=True)
    f = d / f"{tag}_{hashlib.sha1(src.encode()).hexdigest()[:10]}.c"
    f.write_text(src)
    obj = f.with_suffix('.o')
    cp = oracle.compile_source(p, module, f, obj, include_dirs=[ROOT / 'include'])
    if cp.returncode != 0 or not obj.exists():
        return None, re.sub(r"\s+", " ", cp.stdout + cp.stderr)[-300:]
    sizes = {s['name']: s['size'] for s in poolfix.Elf(obj.read_bytes()).symbols()}
    out = {}
    for i, n in enumerate(names):
        try:
            out[n] = (sizes[f'fzgx_off_{i}'] - 1, sizes[f'fzgx_sz_{i}'], sizes[f'fzgx_esz_{i}'], sizes[f'fzgx_al_{i}'])
        except KeyError:
            return None, f'probe symbol missing for {n}'
    return out, None


def filler(prefix, pos, end):
    out, q = [], pos
    while q < end and q % 2:
        out.append((q, f"u8 {prefix}_{q:X};", f"{prefix}_{q:X}")); q += 1
    while q < end and q % 4 and q + 2 <= end:
        out.append((q, f"u16 {prefix}_{q:X};", f"{prefix}_{q:X}")); q += 2
    n = (end - q) // 4
    if n == 1:
        out.append((q, f"u32 {prefix}_{q:X};", f"{prefix}_{q:X}")); q += 4
    elif n > 1:
        out.append((q, f"u32 {prefix}_{q:X}[{n}];", f"{prefix}_{q:X}")); q += 4 * n
    while q + 2 <= end:
        out.append((q, f"u16 {prefix}_{q:X};", f"{prefix}_{q:X}")); q += 2
    while q < end:
        out.append((q, f"u8 {prefix}_{q:X};", f"{prefix}_{q:X}")); q += 1
    return out


def fdef(decl, name):
    ttext, dims, raw = decl
    if ttext is None:
        return re.sub(r"\(\s*\*\s*\w+\s*((?:\[[^\]]+\])*)\s*\)", lambda m: f"(*{name}{m.group(1)})", raw, count=1)
    return f"{ttext}{'' if ttext.endswith('*') else ' '}{name}{''.join(f'[{d}]' for d in dims)};"


def overlapping_field_views(p, symbol, text):
    """Repair lifted offset-named views that accidentally consume each other's storage.

    Offset names nominate a layout, never prove it. Measure the original with
    MWCC and keep each member's type and stride; only the full retail oracle can
    accept the proposed overlapping layout.
    """
    from .sdkimport import masked
    from .signatures import records, record_layouts
    from .fixup_source import _function_body_span
    code = masked(text)
    sym = p.resolve(symbol)
    span = _function_body_span(code, sym.name)
    if not span:
        return
    layouts, _ = record_layouts(code, span[0])
    edits = []
    for record in records(code, span[0]):
        if record['kind'] != 'struct' or record['parent'] or record['key'] not in layouts:
            continue
        fields = layouts[record['key']]
        members = [f for f in fields if not f[0].startswith('pad_')]
        if not members or not any(f[4] for f in members):
            continue
        offsets = {}
        for name, _, _, _, _ in members:
            match = re.fullmatch(r'unk_([0-9A-Fa-f]+)', name)
            if not match:
                break
            offsets[name] = int(match[1], 16)
        else:
            if all(offsets[n] == off for n, _, off, _, _ in members):
                continue
            decls = field_decls(text[record['opening']:record['end'] - 1])
            if any(n not in decls for n in offsets):
                continue
            typ = 'struct ' + record['tag'] if record['tag'] else record['alias']
            measured, error = probe_layout(p, sym.module, text[:span[0]].rsplit('\n', 1)[0],
                                           typ, list(offsets), decls, symbol)
            if error or any(offsets[n] % measured[n][3] for n in offsets):
                continue
            if all(offsets[n] == measured[n][0] for n in offsets):
                continue
            views = []
            for n in offsets:
                padding = f'u8 pad_view_{n}[0x{offsets[n]:X}]; ' if offsets[n] else ''
                views.append('        struct { ' + padding + fdef(decls[n], n) + ' };')
            replacement = '\n    union {\n' + '\n'.join(views) + '\n    };\n'
            edit = (record['opening'], record['end'] - 1, replacement)
            edits.append(edit)
            yield 'overlapping offset views ' + record['key'], text[:edit[0]] + replacement + text[edit[1]:]
    if len(edits) > 1:
        for lo, hi, replacement in sorted(edits, reverse=True):
            text = text[:lo] + replacement + text[hi:]
        yield 'overlapping offset views in all records', text


def find_models(text):
    """(pvar, tname, base, stmt, kind) for pointer models and direct-global models."""
    models = []
    # the one-member carrier `struct { T *value; } w; w.value = (T *)&lbl;` (the lifter's
    # constant-pointer wrapper; fn_1_2FAA0, fn_1_EEB44): the model pointer is `w.value`.
    # Before this the plain form below read `value` alone as the pointer and every rewrite
    # left `st.` in front of an object name.
    for m in re.finditer(r"(?<![\w.>])(\w+)\.(\w+)\s*=\s*(?:\((?:struct\s+)?(\w+)\s*\*\)\s*)?&(lbl_\d+_bss_[0-9A-F]+|lbl_[0-9A-F]{8})\s*;", text):
        carrier, member, cast, base = m.groups()
        dm = re.search(r"\bstruct\s*\{\s*(?:struct\s+)?(\w+)\s*\*\s*%s\s*;\s*\}\s*%s\s*;" % (re.escape(member), re.escape(carrier)), text)
        if not dm or base in {mm[2] for mm in models}:
            continue
        tname = cast or dm.group(1)
        if cast and cast != dm.group(1) or tname in SCALAR:
            continue
        if not cast and not re.search(r"\bextern\s+(?:struct\s+)?%s\s+%s\s*;" % (re.escape(tname), re.escape(base)), text + include_text()):
            continue
        models.append((f'{carrier}.{member}', tname, base, m.group(0), 'ptr'))
    for m in re.finditer(r"(?:(?:struct\s+)?(\w+)\s*\*\s*)?(?<![\w.>])(\w+)\s*=\s*\((?:struct\s+)?(\w+)\s*\*\)\s*&(lbl_\d+_bss_[0-9A-F]+|lbl_[0-9A-F]{8})\s*;", text):
        if m.group(4) in {mm[2] for mm in models}:
            continue
        models.append((m.group(2), m.group(3), m.group(4), m.group(0), 'ptr'))
    # the uncast spelling `T *p = &lbl;` (fn_1_B5F20, fn_1_E9CFC): the type is the pointer's,
    # accepted only when the object's own extern declares the same aggregate type
    for m in re.finditer(r"(?:struct\s+)?(\w+)\s*\*\s*(\w+)\s*=\s*&(lbl_\d+_bss_[0-9A-F]+|lbl_[0-9A-F]{8})\s*;", text):
        tname, pvar, base = m.group(1), m.group(2), m.group(3)
        if tname in SCALAR or tname == 'void' or base in {mm[2] for mm in models}:
            continue
        if not re.search(r"\bextern\s+(?:struct\s+)?%s\s+%s\s*;" % (re.escape(tname), re.escape(base)), text + include_text()):
            continue
        models.append((pvar, tname, base, m.group(0), 'ptr'))
    # an aggregate model at a constant offset into a byte view: `S *s = (S *)(lbl + 0x1600);`,
    # `(S *)((u8 *)&lbl + N)` (fn_1_F0B5C). Every field address is model offset + N; the
    # offset rides in the statement-free kind 'ptr+N' and is read back by `model_offset`.
    for m in re.finditer(r"(?:(?:struct\s+)?(\w+)\s*\*\s*)?(?<![\w.>])(\w+)\s*=\s*\((?:struct\s+)?(\w+)\s*\*\)\s*"
                         r"\(\s*(?:\(\s*(?:u8|s8|char)\s*\*\s*\)\s*&?\s*)?(lbl_\d+_bss_[0-9A-F]+|lbl_[0-9A-F]{8})\s*\+\s*(0x[0-9A-Fa-f]+|\d+)\s*\)\s*;", text):
        declared, pvar, tname, base, off = m.groups()
        if base in {mm[2] for mm in models} or tname in SCALAR or (declared and declared != tname):
            continue
        if len(re.findall(r"(?<![\w.>])%s\s*=(?!=)" % re.escape(pvar), text)) != 1:
            continue
        # a pointer that walks (`bits++`, `p += 0x14`) is no model at a constant offset: leave
        # the base to the byte-array model below (fn_1_2F04)
        if re.search(r"(?:\+\+|--)\s*%s\b|(?<![\w.>])%s\s*(?:\+\+|--|[+-]=)" % (re.escape(pvar), re.escape(pvar)), text):
            continue
        models.append((pvar, tname, base, m.group(0), 'ptr+%d' % int(off, 0)))
    seen = {m[2] for m in models}
    for m in re.finditer(r"\nextern\s+(\w+)\s+(lbl_\d+_bss_[0-9A-F]+|lbl_[0-9A-F]{8})\s*((?:\[[^\]]*\])*)\s*;", text):
        tname, base = m.group(1), m.group(2)
        if base in seen or tname not in SCALAR:
            continue
        # `&lbl[N]`, or byte arithmetic `lbl + N` on the array itself (fn_1_2F04's
        # `(Bits *)(lbl_1_bss_978 + 0x80)`): each offset is a member of the retail cluster
        if ((re.search(r"&\s*%s\b" % re.escape(base), text)
                or re.search(r"(?<![\w&.>])%s\s*\+\s*(?:0x[0-9A-Fa-f]+|\d+)\b" % re.escape(base), text))
                and not re.search(r"\b%s\s*=\s*\(" % re.escape(base), text)):
            models.append((None, tname, base, m.group(0), 'bare'))
            seen.add(base)
    for m in re.finditer(r"\nextern\s+(?:struct\s+)?(\w+)\s+(lbl_\d+_bss_[0-9A-F]+|lbl_[0-9A-F]{8})\s*;", text):
        tname, base = m.group(1), m.group(2)
        if base in seen or tname in ('u8', 'u16', 'u32', 's8', 's16', 's32', 'f32', 'f64', 'int', 'char', 'void'):
            continue
        if re.search(r"\b%s\.\w+" % re.escape(base), text):
            models.append((None, tname, base, m.group(0), 'direct'))
            seen.add(base)
    # declared by an included header: the definition needs the header's extern renamed away
    for base in sorted(set(re.findall(r"\b(lbl_\d+_bss_[0-9A-F]+|lbl_[0-9A-F]{8})\.\w+", text))):
        if base in seen:
            continue
        hm = re.search(r"\nextern\s+(?:struct\s+)?(\w+)\s+%s\s*;" % re.escape(base), include_text())
        if hm:
            models.append((None, hm.group(1), base, '', 'direct-header'))
            seen.add(base)
    return models


def without_member_names(text):
    """`text` without struct/union member declarations and member names after `->`/`.`: a model
    pointer that shares its name with a field (`BS *b` beside `s8 b[4];` and `d->b[0]`,
    fn_1_854D4) is not a use of the pointer."""
    prev = None
    while prev != text:
        prev = text
        text = re.sub(r"\b(?:struct|union)\s*\w*\s*\{[^{}]*\}", ' ', text)
    return re.sub(r"(?:->|(?<![\d\s])\.)\s*[A-Za-z_]\w*", ' ', text)


def data_struct_views(p, symbol, text):
    """A struct model over a same-module `.data` object (`DS *d = (DS *)&lbl_1_data_1F1D8;`,
    also at a constant offset) as the byte view `tu_data_objects` defines object by object.

    Retail addresses the referenced `.data` objects off one section base (fn_1_854D4's three
    `s8[4]` rows as `addi r6/r5/r4` pointers; fn_1_9A7BC's +0x720/+0x2810); a struct model
    folds every field into a displacement off one pointer. Field offsets, sizes and element
    sizes come from an MWCC probe of the body's own struct; each `d->f` becomes
    `(*(T *)(d + off))` (arrays `((T *)(d + off))`), so the byte-view pass cuts objects at the
    field starts and the oracle still proves the whole section before binding."""
    sym = p.resolve(symbol)
    syms = p.symbols(sym.module)
    pat = (r"(?:(?:struct\s+)?(\w+)\s*\*\s*)?(?<![\w.>])(\w+)\s*=\s*\((?:struct\s+)?(\w+)\s*\*\)\s*"
           r"(?:\(\s*(?:\(\s*(?:u8|s8|char)\s*\*\s*\)\s*)?&?\s*(lbl_\d+_(?:ro)?data_[0-9A-F]+|lbl_[0-9A-F]{8})\s*\+\s*(0x[0-9A-Fa-f]+|\d+)\s*\)"
           r"|&?\s*(lbl_\d+_(?:ro)?data_[0-9A-F]+|lbl_[0-9A-F]{8}))\s*;")  # an array decays: `(BgData *)lbl` (fn_1_107F74)
    fm = re.search(r"\n[^\n;{}]*\b%s\s*\([^;{}]*\)\s*\{" % re.escape(sym.name), text)
    if not fm:
        return None, ['function definition not found']
    out, notes, cache = text, [], {}
    for m in list(re.finditer(pat, text)):
        declared, pvar, tname, base = m[1], m[2], m[3], m[4] or m[6]
        offset = int(m[5], 0) if m[5] else 0
        known = syms.get(base)
        if not known or known.section not in DATA_SECTIONS or known.kind != 'object' or tname in SCALAR or (declared and declared != tname):
            continue
        if len(re.findall(r"(?<![\w.>])%s\s*=(?!=)" % re.escape(pvar), out)) != 1 or m[0] not in out:
            continue
        st = struct_text(tname, out)
        if st is None:
            notes.append(f'{tname}: struct text not found'); continue
        decls = field_decls(st)
        access = re.compile(r"\b%s\s*->\s*(\w+)" % re.escape(pvar))
        names = sorted({u[1] for u in access.finditer(out)})
        if not names or any(n not in decls or decls[n][0] is None for n in names):
            notes.append(f'{pvar}: fields without declaration text'); continue
        rest = without_member_names(access.sub(' ', out.replace(m[0], ' ')))
        rest = re.sub(r"(?:struct\s+)?%s\s*\*\s*%s\s*;" % (re.escape(tname), re.escape(pvar)), ' ', rest)
        if re.search(r"\b%s\b" % re.escape(pvar), rest):
            notes.append(f'{pvar}: used other than through ->'); continue
        prefix = out[:re.search(r"\n[^\n;{}]*\b%s\s*\([^;{}]*\)\s*\{" % re.escape(sym.name), out).start() + 1]
        is_alias = re.search(r"\}\s*%s\s*;|typedef\s+struct\s+\w+\s+%s\s*;" % (re.escape(tname), re.escape(tname)), prefix + include_text())
        key = (tname, tuple(names))
        if key not in cache:
            cache[key] = probe_layout(p, sym.module, prefix, tname if is_alias else 'struct ' + tname, names, decls, symbol)
        layout, err = cache[key]
        if layout is None:
            notes.append(f'{tname}: probe failed: {err}'); continue

        def view(u):
            ttext, dims, _ = decls[u[1]]
            off = offset + layout[u[1]][0]
            where = f"{pvar} + {off:#x}" if off else pvar
            if dims:
                inner = ''.join(f'[{d}]' for d in dims[1:])
                return f"(({ttext} (*){inner})({where}))" if inner else f"(({ttext} *)({where}))"
            return f"(*({ttext} *)({where}))"
        out = access.sub(view, out)
        if declared:
            out = out.replace(m[0], f"u8 *{pvar} = (u8 *)&{base};", 1)
        else:
            out = out.replace(m[0], f"{pvar} = (u8 *)&{base};", 1)
            dm = re.search(r"(?m)^([ \t]*)(?:struct\s+)?%s\s*\*\s*%s\s*;" % (re.escape(tname), re.escape(pvar)), out)
            if not dm:
                return None, notes + [f'{pvar}: declaration not found']
            out = out[:dm.start()] + f"{dm[1]}u8 *{pvar};" + out[dm.end():]
        notes.append(f'{base}: {len(names)} fields of {tname} as byte views')
    return (out if out != text else None), notes


def constant_rows(text):
    """Split each multi-dimensional field of a body-local model struct that is only ever
    indexed with a constant first subscript (`s->a[1][i]`) into one field per row.

    Retail addresses every row as its own object (`addi r5, r30, 0x1614; lwzx`, then 0x1628,
    0x163c: fn_1_F0B5C); one `a[3][5]` object folds the row offset into a displacement off
    `base + i*4` (`add r7, r6, r29; lwz r5, 0x14(r7)`). With a field per row, the split layout
    defines each row as a separate object."""
    out = text
    for pvar, tname, base, stmt, kind in find_models(text):
        if not pvar or not kind.startswith('ptr'):
            continue
        sm = (re.search(r"(?:typedef\s+)?struct\s+%s\s*\{(.*?)\n\}" % re.escape(tname), out, re.S)
              or re.search(r"typedef\s+struct\s*\w*\s*\{([^{}]*)\n\}\s*%s\s*;" % re.escape(tname), out, re.S))
        if not sm:
            continue
        lo, hi = sm.span(1)
        for fname, (ttext, dims, _) in field_decls(sm.group(1)).items():
            if ttext is None or len(dims) < 2 or not re.fullmatch(r"\s*(0x[0-9A-Fa-f]+|\d+)\s*", dims[0]):
                continue
            access = r"\b%s\s*->\s*%s\b" % (re.escape(pvar), re.escape(fname))
            total = len(re.findall(access, out))
            rows = list(re.finditer(access + r"\s*\[\s*(0x[0-9A-Fa-f]+|\d+)\s*\]", out))
            count = int(dims[0].strip(), 0)
            if not rows or len(rows) != total or count > 16 or any(int(r[1], 0) >= count for r in rows):
                continue
            body = out[lo:hi]
            dm = re.search(r"(?<![\w>.])%s\s*\[[^\]]+\]((?:\s*\[[^\]]+\])+)\s*;" % re.escape(fname), body)
            if not dm:
                continue
            # the type text stays in front of the first row; every later row restates it
            row_decls = f"{fname}_row0{dm.group(1).strip()}; " + ' '.join(f"{ttext} {fname}_row{k}{dm.group(1).strip()};" for k in range(1, count))
            body = body[:dm.start()] + row_decls + body[dm.end():]
            out = out[:lo] + body + out[hi:]
            out = re.sub(access + r"\s*\[\s*(0x[0-9A-Fa-f]+|\d+)\s*\]", lambda r: f"{pvar}->{fname}_row{int(r[1], 0)}", out)
            sm = (re.search(r"(?:typedef\s+)?struct\s+%s\s*\{(.*?)\n\}" % re.escape(tname), out, re.S)
                  or re.search(r"typedef\s+struct\s*\w*\s*\{([^{}]*)\n\}\s*%s\s*;" % re.escape(tname), out, re.S))
            lo, hi = sm.span(1)
    return out if out != text else None


def derived_models(text, syms):
    """A view derived from a model at a constant byte offset, `T *hi = (T *)((u8 *)work + 0x20000);`
    with `work = (W *)&lbl_3_bss_0`, re-spelled off the retail object that holds its address:
    `(T *)((u8 *)&lbl_3_bss_140 + 0x1FEC0)`, a model of its own (fn_3_381C). Left alone, the base
    model's byte-offset rewrite turned the view into one byte object split out of the array and
    its fields never reached the retail objects (`addis r31, r30, 0x2` became a named `lis/addi`)."""
    for _ in range(4):
        changed = False
        for pvar, tname, base, stmt, kind in find_models(text):
            if not pvar or '.' in pvar or not (kind == 'ptr' or kind.startswith('ptr+')):
                continue
            b = syms.get(base)
            if b is None or b.section != '.bss':
                continue
            off0 = int(kind[4:]) if kind.startswith('ptr+') else 0
            pat = re.compile(r"(?:(?:struct\s+)?(\w+)\s*\*\s*)?(?<![\w.>])(\w+)\s*=\s*\((?:struct\s+)?(\w+)\s*\*\)\s*"
                             r"\(\s*\(\s*(?:u8|s8|char)\s*\*\s*\)\s*%s\s*\+\s*(0x[0-9A-Fa-f]+|\d+)\s*\)\s*;" % re.escape(pvar))
            for m in pat.finditer(text):
                declared, qvar, qtype, k = m.groups()
                if qtype in SCALAR or (declared and declared != qtype) or qvar == pvar:
                    continue
                if len(re.findall(r"(?<![\w.>])%s\s*=(?!=)" % re.escape(qvar), text)) != 1:
                    continue
                addr = b.addr + off0 + int(k, 0)
                owner = next((s for s in syms.values() if s.section == b.section and s.kind == 'object'
                              and s.addr <= addr < s.end), None)
                if owner is None or owner.name == base:
                    continue
                repl = (f"{declared + ' *' if declared else ''}{qvar} = ({qtype} *)((u8 *)&{owner.name}"
                        f" + 0x{addr - owner.addr:X});")
                text = text[:m.start()] + repl + text[m.end():]
                changed = True
                break
            if changed:
                break
        if not changed:
            break
    return text


_BYTE_T = r"(?:const\s+)?(?:u8|s8|char|unsigned\s+char|signed\s+char)"
_INT = r"0x[0-9A-Fa-f]+|\d+"


def _strip_comments(text):
    return re.sub(r"//[^\n]*", "", re.sub(r"/\*.*?\*/", "", text, flags=re.S))


def _view_fields(text, tname):
    """Naive natural-alignment offsets of a plain view struct (`u8 pad[0x5c7c]; u32 flags[2];`):
    field -> (offset, element type, element size, dims). None when a field is not a scalar."""
    st = struct_text(tname, text)
    if st is None:
        return None
    out, off = {}, 0
    for fname, (ttext, dims, _) in field_decls(st).items():
        if ttext is None:
            return None
        t = ttext.replace('const ', '').replace('volatile ', '').strip()
        size = 4 if '*' in t else SCALAR.get(t)
        if size is None or t == 'void':
            return None
        n = 1
        for d in dims:
            try:
                n *= int(d, 0)
            except ValueError:
                return None
        off = (off + size - 1) // size * size
        out[fname] = (off, ttext, size, dims)
        off += size * n
    return out


def _fold_byte_view_forms(text, code, name):
    """Spellings of a flattened byte view the `bare` model cannot read, folded onto `name + N`:
    `(name + 0xA) + (0xB)`, `*(T *)((name + 0xA) + i * sizeof(T))` as an element of an array
    view, and member reads through a cast view struct `((View *)(name + 0xA))->m[i]`. Each left
    as is the whole model failed ("bare symbol used as a value") and the cluster kept no layout
    (fn_1_B8EDC's memcard flags at +0x5c7c and counters at +0x5c74)."""
    n = re.escape(name)
    paren = r"\(\s*%s\s*\+\s*(%s)\s*\)" % (n, _INT)
    code = re.sub(r"\(\s*%s\s*\+\s*\(?\s*(%s)\s*\)?\s*\)" % (paren, _INT),
                  lambda m: f"({name} + 0x{int(m.group(1), 0) + int(m.group(2), 0):X})", code)
    code = re.sub(r"%s\s*\+\s*\(\s*(%s)\s*\)" % (paren, _INT),
                  lambda m: f"({name} + 0x{int(m.group(1), 0) + int(m.group(2), 0):X})", code)

    def elem(m):
        t, k = m.group(1).strip(), int(m.group(4), 0)
        size = 4 if '*' in t else SCALAR.get(t.replace('const ', '').strip())
        if size != k:
            return m.group(0)
        return f"(({t} *)({name} + 0x{int(m.group(2), 0):X}))[{m.group(3).strip()}]"
    code = re.sub(r"\*\s*\(\s*((?:const\s+)?\w+(?:\s*\*)?)\s*\*\s*\)\s*\(\s*%s\s*\+\s*(\w+(?:\s*\.\s*\w+)?)\s*\*\s*(%s)\s*\)"
                  % (paren, _INT), elem, code)
    views = {}

    def member(m):
        tname, base, fname, idx = m.group(1), int(m.group(2), 0), m.group(3), m.group(4)
        if tname not in views:
            views[tname] = _view_fields(text, tname)
        fields = views[tname]
        if not fields or fname not in fields:
            return m.group(0)
        off, ttext, size, dims = fields[fname]
        if dims and idx is not None:
            return f"(({ttext} *)({name} + 0x{base + off:X}))[{idx.strip()}]"
        if not dims and idx is None:
            return f"(*({ttext} *)({name} + 0x{base + off:X}))"
        return m.group(0)
    code = re.sub(r"\(\s*\(\s*(\w+)\s*\*\s*\)\s*\(\s*%s\s*\+\s*(%s)\s*\)\s*\)\s*->\s*(\w+)(?:\s*\[([^\[\]]+)\])?" % (n, _INT),
                  member, code)
    return code


def flatten_byte_views(p, symbol, text):
    """Byte-pointer locals at constant offsets from one same-module .bss object, re-spelled as
    byte arithmetic on the object itself (`extern u8 lbl[]; *(T *)(lbl + 0x49388)`), the shape
    the `bare` model lays out as retail TU objects.

    `base = (u8 *)&lbl_10_bss_0; hi = base + 0x50000; *(u32 *)(hi - 0x6c78)` keeps the base as
    a declared local and the high half as a compiler temp, so the high half is colored first and
    takes r31 where retail holds the section base in r30 and `addis r31, r30, 0x5` (fn_10_4790,
    fn_10_8314). No declaration order, carrier or pragma reaches retail's order; with the objects
    defined in the unit MWCC addresses them off its own section base and the pair comes out as
    retail's (fn_10_4790: 84.9% -> 100%). Returns the rewritten text or None."""
    sym = p.resolve(symbol)
    if sym is None:
        return None
    syms = p.symbols(sym.module)
    fm = re.search(r"\n[^\n;{}]*\b%s\s*\([^;{}]*\)\s*\{" % re.escape(sym.name), text)
    if not fm:
        return None
    inner = _brace_body(text, fm.end() - 1)
    if inner is None:
        return None
    lo, hi = fm.end(), fm.end() + len(inner)
    code = text[lo:hi]
    # byte pointers: plain locals and the one-member carrier `struct { u8 *value; } c;`
    ptrs = {}
    for m in re.finditer(r"(?m)^[ \t]*%s\s*\*\s*(\w+)\s*(?:=[^;]*)?;" % _BYTE_T, code):
        ptrs[m.group(1)] = m.group(0)
    for m in re.finditer(r"(?m)^[ \t]*struct\s*\{\s*%s\s*\*\s*(\w+)\s*;\s*\}\s*(\w+)\s*;" % _BYTE_T, code):
        ptrs[f"{m.group(2)}.{m.group(1)}"] = m.group(0)
    if not ptrs:
        return None

    def bss(name):
        s = syms.get(name)
        return s is not None and s.section == '.bss' and s.kind == 'object'

    byte_arrays = {m.group(1) for m in re.finditer(r"\bextern\s+%s\s+(\w+)\s*\[[^\]]*\]\s*;" % _BYTE_T, text)}
    # `u8 *p = &lbl;` over a byte scalar a module header declares (`extern u8 lbl_1_bss_716C0;`,
    # dtk's size-8 head of fn_1_B4AC0's cluster) is the same byte view as the cast spelling
    byte_scalars = {m.group(1) for m in re.finditer(r"\bextern\s+%s\s+(\w+)\s*;" % _BYTE_T, text + include_text())}
    rhs_form = re.compile(r"&\s*(lbl_\w+)$")
    # value of each pointer: (object, byte offset), resolved in assignment order
    resolved, stmts = {}, {}
    base_form = re.compile(r"(?:\(\s*%s\s*\*\s*\)\s*&?\s*(lbl_\w+)|&\s*(lbl_\w+)\s*\[\s*0\s*\]|(lbl_\w+))$" % _BYTE_T)
    for _ in range(4):
        for pv in ptrs:
            if pv in resolved:
                continue
            pat = re.escape(pv).replace(r'\.', r'\s*\.\s*')
            assigns = list(re.finditer(r"(?<![\w.>])%s\s*=(?!=)\s*([^;]*);" % pat, code))
            if len(assigns) != 1:
                continue
            rhs = assigns[0].group(1).strip()
            got = None
            bm = base_form.match(rhs)
            if bm:
                name = bm.group(1) or bm.group(2) or bm.group(3)
                if bss(name) and (bm.group(1) or name in byte_arrays):
                    got = (name, 0)
            elif rhs_form.match(rhs):
                name = rhs_form.match(rhs).group(1)
                if bss(name) and name in byte_scalars:
                    got = (name, 0)
            else:
                dm = re.fullmatch(r"(?:\(\s*%s\s*\*\s*\)\s*)?(.+?)\s*([+-])\s*(%s)" % (_BYTE_T, _INT), rhs)
                if dm:
                    left, sign, k = dm.group(1).strip(), dm.group(2), int(dm.group(3), 0)
                    left = re.sub(r"\s*\.\s*", ".", left)
                    src = resolved.get(left)
                    if src is None:
                        lm = base_form.match(left)
                        if lm:
                            name = lm.group(1) or lm.group(2) or lm.group(3)
                            if bss(name) and (lm.group(1) or name in byte_arrays):
                                src = (name, 0)
                    if src is not None:
                        got = (src[0], src[1] + (k if sign == '+' else -k))
            if got is not None and got[1] >= 0:
                resolved[pv] = got
                stmts[pv] = assigns[0]
    if not resolved:
        return None
    out = code
    done = []
    # derived pointers first: their assignments still name the pointer they derive from
    for pv, (name, off) in reversed(list(resolved.items())):
        pat = re.escape(pv).replace(r'\.', r'\s*\.\s*')
        stmt = stmts[pv].group(0)
        decl = ptrs[pv]
        # an initialized declaration is its own assignment
        rest = out.replace(stmt, '\0', 1) if stmt not in decl else out.replace(decl, '\0', 1)
        if stmt not in decl:
            rest = rest.replace(decl, '\0', 1)

        def at(k):
            v = off + k
            return f"({name} + 0x{v:X})" if v >= 0 else None

        bad = False

        def plus(m):
            nonlocal bad
            v = at(int(m.group(2), 0) * (1 if m.group(1) == '+' else -1))
            if v is None:
                bad = True
                return m.group(0)
            return v
        new = re.sub(r"(?<![\w.>])%s\s*([+-])\s*(%s)\b(?!\s*[*/%%\[(.])" % (pat, _INT), plus, rest)
        new = re.sub(r"(?<![\w.>])%s\s*\[\s*(%s)\s*\]" % (pat, _INT), lambda m: f"{name}[0x{off + int(m.group(1), 0):X}]", new)
        new = re.sub(r"(?<![\w.>])%s\b(?!\s*(?:->|\[|=(?!=)|\+\+|--|[+\-*/|&^]=|\.))" % pat, lambda m: f"({name} + 0x{off:X})", new)
        if bad or re.search(r"(?<![\w.>])%s\b" % pat, new):
            continue
        out = new.replace('\0', '', 2)
        done.append(pv)
    if not done:
        return None
    for name in sorted({resolved[pv][0] for pv in done}):
        out = _fold_byte_view_forms(text, out, name)
    # the removed declarations and assignments leave indentation-only lines
    out = re.sub(r"(?m)^[ \t]+\n", "", out)
    text = text[:lo] + out + text[hi:]
    for name in sorted({resolved[pv][0] for pv in done}):
        if name in byte_arrays:
            continue
        local = re.compile(r"\nextern\s+[^;\n]*\b%s\b[^;\n]*;" % re.escape(name))
        decl = f"\nextern u8 {name}[];"
        text = local.sub(decl, text, 1) if local.search(text[:fm.start() + 1]) else (
            text[:fm.start()] + decl + text[fm.start():])
    return text


def _enclosing_function(text, pos):
    """(start, end) of the file-scope function definition containing `pos`, or None."""
    from .sdkimport import masked
    code = masked(text)
    for a, b in _top_statements(code):
        if a <= pos < b and code[b - 1] == '}':
            return a, b
    return None


# a unary `&`: in `v == 0 && lbl[0x1F1]` the second `&` belongs to the logical and (fn_1_B4AC0's
# flattened view became `v == 0 &(u8 *)&obj` and the candidate never compiled)
_UNARY_AMP = r"(?<![&\w)\]])(?<![&\w)\]]\s)"


def tu_objects(p, symbol, text, mode, cache, retail_bases=(), only=None, derive=False, early=False):
    sym = p.resolve(symbol)
    syms = p.symbols(sym.module)
    notes = []
    if derive:
        derived = derived_models(text, syms)
        if derived == text:
            return None, ['no derived model']
        text = derived
    models = find_models(text)
    # derived views lay out their own clusters: each model stops where the next one starts
    starts = sorted({syms[m[2]].addr for m in models if syms.get(m[2]) and syms[m[2]].section == '.bss'}) if derive else []
    if only is not None:
        # one model alone: joining a cast and an uncast model in one layout regressed
        # fn_1_EF5E0 (88.5% -> 75.9%) where one of them alone may be retail's shape
        models = [m for m in models if m[2] in only]
    # Saved preprocessed bodies retain spaces around member access. The
    # layout parser below recognizes the pointer token, not that whitespace.
    for pvar, *_ in models:
        if pvar:
            text = re.sub(r'\b' + re.escape(pvar) + r'\s*->\s*', pvar + '->', text)
    # same-module .bss scalars/arrays the body names directly are objects of the retail TU too
    scalars = []
    for m in re.finditer(r"\nextern\s+((?:const\s+)?(?:u8|s8|u16|s16|u32|s32|f32|f64|int|char)(?:\s*\*)?)\s+(lbl_\d+_bss_[0-9A-F]+|lbl_[0-9A-F]{8})\s*((?:\[[^\]]*\])*)\s*;", text):
        s = syms.get(m.group(2))
        if s and s.section == '.bss' and m.group(2) not in {mm[2] for mm in models} and re.search(r"(?<![\w&])%s\b" % re.escape(m.group(2)), text.replace(m.group(0), '')):
            scalars.append((m.group(1), m.group(2), m.group(3), m.group(0), s))
    if not models and not scalars:
        return None, ['no bss model']
    out_text = text
    extra_objs = {s.name: (decl_t, dims, stmt) for decl_t, name, dims, stmt, s in scalars}
    fm = re.search(r"\n[^\n;{}]*\b%s\s*\([^;{}]*\)\s*\{" % re.escape(sym.name), out_text)
    if not fm:
        return None, ['function definition not found']
    prefix = out_text[:fm.start() + 1]
    all_defs, all_typedefs = [], []
    for pvar, tname, base, stmt, kind in models:
        model_offset = 0
        if kind.startswith('ptr+'):
            kind, model_offset = 'ptr', int(kind[4:])
        b = syms.get(base)
        if b is None or b.section != '.bss':
            # another module's object (or SDA data): retail addresses it by name, leave it alone
            notes.append(f'{base}: not a same-module .bss object, left as is'); continue
        if kind == 'direct-header':
            kind = 'direct'
        if kind == 'direct':
            pvar = f'fzgx_p_{base}'
            out_text = re.sub(r"\b%s\." % re.escape(base), f"{pvar}->", out_text)
            out_text = re.sub(_UNARY_AMP + r"&\s*%s\b(?![\.\w])" % re.escape(base), f"((u8 *){pvar} + 0)", out_text)
            body_only = "\n".join(l for l in _strip_comments(out_text.replace(stmt, '')).split("\n") if not l.lstrip().startswith('#'))
            if re.search(r"(?<![\w>])%s\b(?!\s*->)" % re.escape(base), body_only):
                notes.append(f'{base}: direct global used as a value'); return None, notes
            stmt_removed = stmt
            stmt = ''
        else:
            stmt_removed = stmt
        synthetic = {}
        decls = {}
        byte_model = tname in SCALAR
        if kind == 'bare':
            esz0 = SCALAR[tname]
            pvar = f'fzgx_p_{base}'
            out_text = re.sub(_UNARY_AMP + r"&\s*%s\s*\[\s*(0x[0-9A-Fa-f]+|\d+)\s*\]" % re.escape(base), lambda mm: f"({tname} *)({pvar} + {int(mm.group(1), 0)})", out_text)
            out_text = re.sub(r"(?<![\w&])%s\s*\[\s*(0x[0-9A-Fa-f]+|\d+)\s*\]" % re.escape(base), lambda mm: f"{pvar}[{int(mm.group(1), 0)}]", out_text)
            out_text = re.sub(_UNARY_AMP + r"&\s*%s\b(?![\.\[\w])" % re.escape(base), f"({tname} *)({pvar} + 0)", out_text)
            out_text = re.sub(r"(?<![\w&.>])%s\s*\+\s*(0x[0-9A-Fa-f]+|\d+)\b" % re.escape(base),
                              lambda mm: f"({tname} *)({pvar} + {int(mm.group(1), 0)})", out_text)
            body_only = "\n".join(l for l in _strip_comments(out_text.replace(stmt, '')).split("\n") if not l.lstrip().startswith('#'))
            if re.search(r"(?<![\w>])%s\b" % re.escape(base), body_only):
                notes.append(f'{base}: bare symbol used as a value'); return None, notes
            stmt_removed = stmt
            kind = 'bytes'
        if byte_model:
            esz = SCALAR[tname]
            def _syn(ttext, n):
                # a pointer view is a word whatever it points to: `void *` took SCALAR['void'] = 1,
                # so the fill after it shifted every later object by 4 (fn_1_384E8's 5100)
                size = 4 if '*' in ttext else SCALAR.get(ttext.strip())
                if size is None:
                    return None
                fname = f"fzgx_{re.sub(r'[^A-Za-z0-9]', '_', ttext)}_{n:X}"
                synthetic[fname] = (n, size, size, min(size, 8))
                decls[fname] = (ttext, [], f"{ttext} {fname};")
                return fname
            def _deref(mm):  # *(T *)(p + N)
                f = _syn(mm.group(1).strip(), int(mm.group(2), 0))
                return mm.group(0) if f is None else f"{pvar}->{f}"
            out_text = re.sub(r"\*\s*\(\s*((?:const\s+)?\w+(?:\s*\*)?)\s*\*\s*\)\s*\(\s*%s\s*\+\s*(0x[0-9A-Fa-f]+|\d+)\s*\)" % re.escape(pvar), _deref, out_text)
            def _idx(mm):  # p[N]
                f = _syn(tname, int(mm.group(1), 0) * esz)
                return f"{pvar}->{f}"
            out_text = re.sub(r"\b%s\s*\[\s*(0x[0-9A-Fa-f]+|\d+)\s*\]" % re.escape(pvar), _idx, out_text)
            def _addr(mm):  # (T *)(p + N)  -> (T *)&p->byte_N
                f = _syn('u8', int(mm.group(2), 0))
                return f"({mm.group(1).strip()} *)&{pvar}->{f}"
            out_text = re.sub(r"\(\s*((?:const\s+)?\w+(?:\s*\*)?)\s*\*\s*\)\s*\(\s*%s\s*\+\s*(0x[0-9A-Fa-f]+|\d+)\s*\)" % re.escape(pvar), _addr, out_text)
            def _plus(mm):  # p + N
                f = _syn('u8', int(mm.group(1), 0) * esz)
                return f"({tname} *)&{pvar}->{f}"
            out_text = re.sub(r"\b%s\s*\+\s*(0x[0-9A-Fa-f]+|\d+)\b" % re.escape(pvar), _plus, out_text)
            def _bare(mm):
                f = _syn('u8', 0)
                return f"({tname} *)&{pvar}->{f}"
            if kind == 'ptr':
                out_text = re.sub(r"\n[ \t]*(?:const\s+)?%s\s*\*\s*%s\s*;" % (re.escape(tname), re.escape(pvar)), '', out_text)
                out_text = re.sub(r"(?<=[;{}]\s)(?:const\s+)?%s\s*\*\s*%s\s*;\s*" % (re.escape(tname), re.escape(pvar)), '', out_text)
            marked = out_text.replace(stmt_removed, '\x00STMT\x00') if stmt_removed else out_text
            out_text = re.sub(r"(?<![\w>])%s\b(?!\s*(?:->|=[^=]))" % re.escape(pvar), _bare, marked).replace('\x00STMT\x00', stmt_removed)
        else:
            st = struct_text(tname, text)
            if st is None:
                notes.append(f'{tname}: struct text not found'); return None, notes
            decls = field_decls(st)

        def _byteoff(mm):
            n = int(mm.group(1), 0)
            fname = f"fzgx_byte_{n:X}"
            synthetic[fname] = n
            return f"(u8 *)&{pvar}->{fname}"
        out_text = re.sub(r"\(u8 \*\)\s*(?:\(u32\)\s*)?\b%s\b\s*\+\s*(0x[0-9A-Fa-f]+|\d+)" % re.escape(pvar), _byteoff, out_text)
        # the integer spelling of the same interior address, `(u32)p + 8` (fn_1_C24A4's port
        # array, fn_1_BA144): retail keeps that address as an object address (`addi r3, r30, 0x8;
        # lbz 0x1(r3)`), which only a defined object at +8 reproduces; as a model use the
        # pointer was rejected and the cluster never got its layout
        out_text = re.sub(r"\(\s*u32\s*\)\s*\b%s\b\s*\+\s*(0x[0-9A-Fa-f]+|\d+)\b(?!\s*[*/%%\[(])" % re.escape(pvar),
                          lambda mm: "(u32)" + _byteoff(mm), out_text)
        # an index holding another use (`s->k[i][s->c[i] - 1]`) ends the subscript run: the
        # inner use is rewritten on its own (a `[^\]]*` subscript swallowed it, fn_1_F0B5C)
        uses = list(re.finditer(r"(&?)\b%s->(\w+)((?:\[[^\[\]]*\])*)" % re.escape(pvar), out_text))
        # a pointer model is a local of the function holding its statement: another function's
        # parameter of the same name (`record_ptr(void *p) { return p; }`, fn_3_E5D4) is not a
        # use. The `p->` rewrites above are file-wide (a helper receiving the model under the
        # same parameter name follows them, fn_800456A0), so with a `p->` outside the function
        # the whole file stays the scope, as before; file-scope macros expand inside it.
        scope = out_text
        if pvar and not pvar.startswith('fzgx_p_') and stmt_removed and stmt_removed in out_text:
            span = _enclosing_function(out_text, out_text.index(stmt_removed))
            if span is not None:
                outside = "\n".join(l for l in (out_text[:span[0]] + "\n" + out_text[span[1]:]).split("\n")
                                    if not l.lstrip().startswith('#'))
                if not re.search(r"\b%s->" % re.escape(pvar), outside):
                    scope = out_text[span[0]:span[1]]
        other = re.sub(r"\b%s->" % re.escape(pvar), '', scope).replace(stmt_removed, '')
        other = "\n".join(l for l in other.split("\n") if not l.lstrip().startswith('#'))
        other = re.sub(r"(?:struct\s+)?%s\s*\*\s*%s\s*;" % (re.escape(tname), re.escape(pvar)), '', other)
        if re.search(r"\b%s\b" % re.escape(pvar), other if '.' in pvar else without_member_names(other)):
            notes.append(f'{pvar}: used other than through ->'); return None, notes
        if not uses:
            notes.append(f'{pvar}: no uses'); return None, notes
        names = sorted({u.group(2) for u in uses if u.group(2) not in synthetic})
        missing = [n for n in names if n not in decls]
        if missing:
            notes.append(f'{tname}: fields without declaration text: {missing[:3]}'); return None, notes
        if names:
            key = (tname, tuple(names))
            if key not in cache:
                is_alias = re.search(r"\}\s*%s\s*;|typedef\s+struct\s+\w+\s+%s\s*;" % (re.escape(tname), re.escape(tname)), prefix + include_text())
                cache[key] = probe_layout(p, sym.module, prefix, tname if is_alias else 'struct ' + tname, names, decls, symbol)
            layout, err = cache[key]
            if layout is None:
                notes.append(f'{tname}: probe failed: {err}'); return None, notes
        else:
            layout = {}
        for fname, v in synthetic.items():
            if isinstance(v, tuple):
                layout[fname] = v
            else:
                layout[fname] = (v, 1, 1, 1)
                decls[fname] = ('u8', [], f'u8 {fname};')
        start = b
        lower = [syms[r] for r in retail_bases if syms.get(r) and syms[r].section == b.section and syms[r].addr < b.addr and b.addr - syms[r].addr <= 0x10000]
        if lower:
            start = max(lower, key=lambda s: s.addr)
        cluster = sorted((s for s in syms.values() if s.section == b.section and s.kind == 'object' and s.addr >= start.addr), key=lambda s: s.addr)
        if not cluster or cluster[0].addr != start.addr:
            notes.append(f'{base}: not an object start'); return None, notes
        # gaps between dtk objects become pseudo-objects
        full = []
        for i, s in enumerate(cluster):
            full.append(s)
            nxt = cluster[i + 1].addr if i + 1 < len(cluster) else None
            if nxt is not None and nxt > s.end:
                full.append(Gap(f"{base}_gap_{s.end:X}", s.end, nxt, b.section))
        cluster = full
        per_obj, rewrites, views = {}, [], {}
        view_end = b.addr
        for um in uses:
            amp, fname, idx = um.group(1), um.group(2), um.group(3)
            foff, fsize, esize, ealign = layout[fname]
            addr = b.addr + model_offset + foff
            obj = next((s for s in cluster if s.addr <= addr < s.end), None)
            if obj is None:
                notes.append(f'{fname}: offset {foff:#x} outside cluster'); return None, notes
            inner = addr - obj.addr
            if addr + fsize > obj.end:
                ttext, dims, _ = decls[fname]
                if mode not in ('split', 'merge') or not dims or ttext is None or isinstance(obj, Gap):
                    notes.append(f'{fname}: crosses object {obj.name}'); return None, notes
                # A recovered array view can span several retail objects. Keep
                # its type and bounds, but allocate each proven object separately.
                covered = [s for s in cluster if s.addr < addr + fsize and s.end > addr]
                if (not covered or covered[-1].end < addr + fsize
                        or any(a.end != c.addr for a, c in zip(covered, covered[1:]))):
                    notes.append(f'{fname}: incomplete object coverage'); return None, notes
                views[fname] = (ttext, dims)
                view_end = max(view_end, addr + fsize)
                anchor = f'fzgx_byte_{foff:X}'
                decls[anchor] = ('u8', [], f'u8 {anchor};')
                rec = per_obj.setdefault(obj.name, {'sym': obj, 'fields': {}})
                rec['fields'].setdefault(inner, (anchor, 1, 1, 1))
                rewrites.append((um, obj, inner, fname, idx, amp))
                continue
            rec = per_obj.setdefault(obj.name, {'sym': obj, 'fields': {}})
            prev = rec['fields'].get(inner)
            synthetic_name = fname.startswith(('fzgx_byte_', 'fzgx_u8_'))
            if prev and prev[0] != fname and decls[prev[0]] != decls[fname]:
                if synthetic_name:
                    pass  # a byte view of a real field shares the field's object slot
                elif prev[0].startswith(('fzgx_byte_', 'fzgx_u8_')):
                    rec['fields'][inner] = (fname, fsize, esize, ealign)
                else:
                    notes.append(f'{fname}: conflicting field at {obj.name}+{inner:#x}'); return None, notes
            rec['fields'].setdefault(inner, (fname, fsize, esize, ealign))
            rewrites.append((um, obj, inner, fname, idx, amp))
        late_removals = []
        for name, (decl_t, dims, stmt) in list(extra_objs.items()):
            s = syms[name]
            # definitions start at the model's base, so a scalar below it would lose its
            # extern without gaining a definition (fn_1_E9CFC's lbl_1_bss_6D82C)
            if s.addr < max(start.addr, b.addr) or s.addr - start.addr > 0x10000:
                continue
            obj = next((c for c in cluster if c.addr <= s.addr < c.end), None)
            if obj is None or obj.name != name or name in per_obj:
                continue
            fname = f'fzgx_scalar_{name}'
            decls[fname] = (decl_t, [d.strip('[]') for d in re.findall(r'\[[^\]]*\]', dims)], f'{decl_t} {fname}{dims};')
            per_obj[name] = {'sym': obj, 'fields': {0: (fname, obj.size, obj.size, 4 if not dims else 4)}}
            # removed after the field rewrites below: their match offsets index the current text
            # (removing a declaration here shifted every rewrite of fn_1_E9CFC into garbage)
            late_removals.append(stmt)
            extra_objs.pop(name)
        last = max(view_end, max(r['sym'].end for r in per_obj.values()))
        before = [s for s in cluster if s.addr < last]
        beyond = [s for s in cluster if s.addr >= last]
        if len(before) < 6 and beyond:
            last = beyond[min(len(beyond), 6 - len(before)) - 1].end
        later = [a for a in starts if a > b.addr]
        if later:
            last = min(last, later[0])
        defs, pos, access = [], b.addr, {}
        addressed = {(r[1].name, r[2]) for r in rewrites if r[5] or r[3] in views}
        for s in cluster:
            if s.addr >= last:
                break
            if s.addr < pos:
                continue
            rec = per_obj.get(s.name)
            if rec is None:
                parts = filler(s.name + '_fill', s.addr, s.end)
                first = f"{s.name}_fill_{s.addr:X}"
                defs += [(a, d.replace(first, s.name) if a == s.addr else d, acc.replace(first, s.name) if a == s.addr else acc) for a, d, acc in parts]
                pos = s.end
                continue
            fl = rec['fields']
            if mode == 'merge':
                # split only where the body needs an address (`&field`, arrays): a scalar field
                # stays in the object before it. Retail's object at fn_1_A96BC's 6F648 holds +0xC
                # (`addi r3, r4, 0x0; stw r0, 0xc(r3)`) while +0x10 is its own object.
                starts = [0] + [i for i in sorted(fl) if i and ((s.name, i) in addressed or decls[fl[i][0]][1])]
                for gi, g in enumerate(starts):
                    gend = starts[gi + 1] if gi + 1 < len(starts) else s.size
                    members = [i for i in sorted(fl) if g <= i < gend]
                    gname = s.name if g == 0 else f"{s.name}_{g:X}"
                    if not members:
                        parts = filler(f'{s.name}_fill', s.addr + g, s.addr + gend)
                        first = f"{s.name}_fill_{s.addr + g:X}"
                        defs += [(pa, d.replace(first, gname), acc.replace(first, gname)) if pa == s.addr + g else (pa, d, acc)
                                 for pa, d, acc in parts]
                        continue
                    if members == [g]:
                        fname, fsize, esize, ealign = fl[g]
                        dims = decls[fname][1]
                        if (s.addr + g) % max(ealign, 1) or (dims and (s.addr + g) % 4) or g + fsize > gend:
                            notes.append(f'{s.name}: field {fname} misaligned or overlapping as an object'); return None, notes
                        defs.append((s.addr + g, fdef(decls[fname], gname), gname))
                        access[(s.name, g)] = gname
                        if g + fsize < gend:
                            defs += filler(f'{s.name}_fill', s.addr + g + fsize, s.addr + gend)
                        continue
                    body, off, align = [], 0, 1
                    for i in members:
                        fname, fsize, esize, ealign = fl[i]
                        inner = i - g
                        if inner % max(ealign, 1) or inner < off:
                            notes.append(f'{s.name}: field {fname} misaligned or overlapping'); return None, notes
                        if inner > off:
                            body.append(f"    u8 pad_{off:X}[{inner - off:#x}];")
                        body.append("    " + fdef(decls[fname], fname))
                        access[(s.name, i)] = f"{gname}.{fname}"
                        off = inner + fsize
                        align = max(align, ealign)
                    usable = (gend - g) // align * align
                    if off > usable or (s.addr + g) % align:
                        notes.append(f'{gname}: fields exceed aligned size'); return None, notes
                    if off < usable:
                        body.append(f"    u8 pad_{off:X}[{usable - off:#x}];")
                    all_typedefs.append(f"typedef struct {gname}_t {{\n" + "\n".join(body) + f"\n}} {gname}_t;\n\n")
                    defs.append((s.addr + g, f"{gname}_t {gname};", gname))
                    if g + usable < gend:
                        defs += filler(f'{gname}_tail', s.addr + g + usable, s.addr + gend)
                pos = s.end
                continue
            if mode == 'split':
                q = s.addr
                for inner in sorted(fl):
                    fname, fsize, esize, ealign = fl[inner]
                    a = s.addr + inner
                    if a < q:
                        notes.append(f'{s.name}: overlapping fields'); return None, notes
                    if a > q:
                        parts = filler(f'{s.name}_fill', q, a)
                        if q == s.addr:
                            # the object's own name goes on whatever starts at its address: the
                            # oracle binds the compiler's `...bss.N` base to the retail symbol
                            # only through a unit symbol spelled like it (fn_1_7BAF8's first
                            # referenced field is at +0x8; an unnamed leading filler left the
                            # base rows unbound and unexplained)
                            first = f"{s.name}_fill_{s.addr:X}"
                            parts = [(pa, d.replace(first, s.name), acc.replace(first, s.name)) if pa == s.addr else (pa, d, acc)
                                     for pa, d, acc in parts]
                        defs += parts
                    name = s.name if inner == 0 else f"{s.name}_{inner:X}"
                    dims = decls[fname][1]
                    if a % max(ealign, 1) or (dims and a % 4):
                        notes.append(f'{s.name}: field {fname} misaligned as an object'); return None, notes
                    defs.append((a, fdef(decls[fname], name), name))
                    access[(s.name, inner)] = name
                    q = a + fsize
                if q < s.end:
                    defs += filler(f'{s.name}_fill', q, s.end)
                pos = s.end
                continue
            if list(fl) == [0] and fl[0][0].startswith('fzgx_scalar_'):
                fname, fsize, esize, ealign = fl[0]
                defs.append((s.addr, fdef(decls[fname], s.name), s.name))
                access[(s.name, 0)] = s.name
                pos = s.end
                continue
            if list(fl) == [0]:
                fname, fsize, esize, ealign = fl[0]
                dims = decls[fname][1]
                if fsize == s.size and not (dims and s.addr % 4):
                    defs.append((s.addr, fdef(decls[fname], s.name), s.name))
                    access[(s.name, 0)] = s.name
                    pos = s.end
                    continue
            body, off, align = [], 0, 1
            for inner in sorted(fl):
                fname, fsize, esize, ealign = fl[inner]
                if inner % max(ealign, 1):
                    notes.append(f'{s.name}: field {fname} misaligned'); return None, notes
                if inner > off:
                    body.append(f"    u8 pad_{off:X}[{inner - off:#x}];")
                    off = inner
                elif inner < off:
                    notes.append(f'{s.name}: overlapping fields'); return None, notes
                body.append("    " + fdef(decls[fname], fname))
                access[(s.name, inner)] = f"{s.name}.{fname}"
                off += fsize
                align = max(align, ealign)
            usable = s.size // align * align
            if off > usable:
                notes.append(f'{s.name}: fields exceed aligned size'); return None, notes
            if off < usable:
                body.append(f"    u8 pad_{off:X}[{usable - off:#x}];")
            tobj = f"{s.name}_t"
            all_typedefs.append(f"typedef struct {tobj} {{\n" + "\n".join(body) + f"\n}} {tobj};\n\n")
            defs.append((s.addr, f"{tobj} {s.name};", s.name))
            pos = s.addr + usable
            if usable < s.size:
                defs += filler(s.name + '_tail', pos, s.end)
                pos = s.end
        for um, obj, inner, fname, idx, amp in sorted(rewrites, key=lambda r: -r[0].start()):
            value = access[(obj.name, inner)]
            if fname in views:
                ttext, dims = views[fname]
                value = f"(*({ttext} (*){''.join(f'[{d}]' for d in dims)})&{value})"
            repl = f"{amp}{value}{idx}"
            out_text = out_text[:um.start()] + repl + out_text[um.end():]
        for stmt_late in late_removals:
            out_text = out_text.replace(stmt_late, '')
        if stmt_removed:
            out_text = out_text.replace(stmt_removed, '')
        if kind == 'ptr':
            out_text = re.sub(r"\n[ \t]*(?:struct\s+)?%s\s*\*\s*%s\s*;" % (re.escape(tname), re.escape(pvar)), '', out_text)
            if '.' in pvar:
                carrier = pvar.split('.')[0]
                cdecl = re.compile(r"\n[ \t]*struct\s*\{[^{}]*\}\s*%s\s*;[^\n]*" % re.escape(carrier))
                if not re.search(r"\b%s\b" % re.escape(carrier), cdecl.sub('', out_text)):
                    out_text = cdecl.sub('', out_text)
        all_defs += defs
        notes.append(f'{base}: {len(per_obj)} objects referenced, {len(defs)} definitions')
    if not all_defs:
        return None, notes
    all_defs.sort(key=lambda x: x[0])
    # two models (a base view and a view derived from it) each lay out their own cluster; an
    # address both define would be two definitions of one retail byte
    if derive and any(a == b for (a, _, _), (b, _, _) in zip(all_defs, all_defs[1:])):
        notes.append('models define overlapping objects'); return None, notes
    for _, d, _ in all_defs:
        dn = re.search(r"(\w+)(?:\[[^\]]*\])*;$", d.replace('(*', '').replace(')(', ''))
        if dn:
            out_text = re.sub(r"\n[^\n]*\bextern\b[^\n;]*\b%s\b[^\n;]*;" % re.escape(dn.group(1)), '', out_text)
    fm = re.search(r"\n[^\n;{}]*\b%s\s*\([^;{}]*\)\s*\{" % re.escape(sym.name), out_text)
    at = _first_use_point(out_text, fm.start() + 1, {re.split(r'\W', acc)[0] for _, _, acc in all_defs})
    if early:
        # before the unit's own initialized data: of two anonymous section bases MWCC gives the
        # callee-saved register to the section whose objects are defined first in the file
        # (fn_1_B4AC0: bss defined after the `.data` pool put the data base in r31, retail's
        # bss base; defined before it, both bases match)
        data = set(re.findall(r"\b(fzgx_(?:pool_init|pool_data|data)_\w+)\s*(?:\[[^\]]*\])*\s*=\s*\{", out_text[:at]))
        moved = _first_use_point(out_text, at, data) if data else at
        if moved >= at:
            return None, notes + ['no data definition before the layout']
        at = moved
    # names a module header declares with its own layout are defined under an alias (the
    # oracle binds the section base through it); every use in this unit follows the alias
    renamed = {}
    for i, (a, d, acc) in enumerate(all_defs):
        dn = re.search(r"(\w+)(?:\[[^\]]*\])*;$", d.replace('(*', '').replace(')(', ''))
        if dn and re.search(r"\bextern\s+[^;\n]*\b%s\b[^;\n]*;" % re.escape(dn.group(1)), include_text()):
            renamed[dn.group(1)] = 'fzgx_obj_' + dn.group(1)
    if renamed:
        pat = re.compile(r"\b(%s)\b" % "|".join(re.escape(k) for k in renamed))
        all_defs = [(a, pat.sub(lambda m: renamed[m.group(1)], d), pat.sub(lambda m: renamed[m.group(1)], acc)) for a, d, acc in all_defs]
        all_typedefs = [pat.sub(lambda m: renamed[m.group(1)], td) for td in all_typedefs]
        out_text = out_text[:at] + pat.sub(lambda m: renamed[m.group(1)], out_text[at:])
    block = ''.join(all_typedefs) + "/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */\n"
    # DOL units compile with -sdata 8: a defined object of 8 bytes or less would go to .sbss and be
    # addressed off r13 (fn_8005596C); `section ".data"` keeps an uninitialized one in .bss
    spec = '__declspec(section ".data") ' if sym.module == 'main' else ''
    block += "\n".join(spec + d for _, d, _ in all_defs) + "\n\n"
    # a body that already carries a layout primer (another cluster's earlier layout, fn_1_B4AC0)
    # keeps it: a second `fzgx_bss_layout` is a redefinition and the candidate never compiled
    primer, n = 'fzgx_bss_layout', 0
    while re.search(r"\b%s\s*\(" % primer, out_text):
        n += 1
        primer = f'fzgx_bss_layout_{n}'
    block += '#pragma section code_type ".fzgxpool"\nstatic void ' + primer + '(void) {\n    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */\n'
    block += "".join(f"    s = *(u8 *)&{acc};\n" for _, _, acc in all_defs)
    block += '}\n#pragma section code_type ".text"\n\n'
    out_text = out_text[:at] + block + out_text[at:]
    return out_text, notes


def allow_address_words(line):
    """A line of retail data words carries its own A1 allowance when a word looks like an
    address: the lint reads allow comments per line, so the one on an array's first line left
    every later line flagged and blocked an exact `.data` layout match (fn_1_854D4: 0x815B8374)."""
    from .lint import RANGES
    if any(lo <= int(w, 16) <= hi for w in re.findall(r"\b0x([0-9A-Fa-f]{8})\b", line) for lo, hi in RANGES):
        return line + '  /* fzgx-allow: A1 retail data bytes */'
    return line


def _first_use_point(text, limit, names):
    """The top-level boundary before the first use of `names` above `limit`: a static inline
    helper above the function that reads a model (fn_1_2FAA0's `pad_word`) must follow the
    definitions, or the candidate does not compile (undefined identifier)."""
    from .sdkimport import masked
    scan = masked(text[:limit])
    # externs and macros (expanded where they are used) do not need the definitions
    code = re.sub(r"(?m)^[^\n]*\bextern\b[^\n;]*;|^[ \t]*#(?:[^\n]*\\\n)*[^\n]*", lambda m: re.sub(r'[^\n]', ' ', m[0]), scan)
    uses = [m.start() for n in names if n for m in re.finditer(r"\b%s\b" % re.escape(n), code)]
    if not uses:
        return limit
    first, depth, point, pos = min(uses), 0, 0, 0
    # boundaries: ends of lines at brace depth 0 that close a declaration or are directives
    for line in scan[:first].split('\n')[:-1]:
        depth += line.count('{') - line.count('}')
        pos += len(line) + 1
        if depth == 0 and (line.rstrip().endswith((';', '}')) or line.lstrip().startswith('#')):
            point = pos
    return point


def _diff_rows(r):
    rows = r._rows if r._rows else ([], [])
    return sum(1 for l, rr in zip(*rows) if (l.get('diff_kind') or 'DIFF_NONE') != 'DIFF_NONE' or (rr.get('diff_kind') or 'DIFF_NONE') != 'DIFF_NONE')





def section_bytes(p, module, section, addr=None):
    if module == 'main':
        for base, raw in p._rel_layout('main').values():
            if addr is not None and base <= addr < base + len(raw):
                return base, raw
        return None
    sec = p._raw_section(module, section)
    base = p._section_base(module, section)
    return (base, sec) if sec is not None else None


def c_literal(b):
    out = ''
    for ch in b:
        if ch == 0x5c:
            out += '\\\\'
        elif ch == 0x22:
            out += '\\"'
        elif ch == 0x0a:
            out += '\\n'
        elif ch == 0x0d:
            out += '\\r'
        elif ch == 0x09:
            out += '\\t'
        elif 0x20 <= ch < 0x7f:
            out += chr(ch)
        else:
            return None
    return '"' + out + '"'


def string_at(raw, off):
    """(bytes without NUL, padded length) of the NUL-terminated string at off, or None."""
    e = raw.find(b'\0', off)
    if e < 0 or e == off:
        return None
    s = raw[off:e]
    if c_literal(s) is None:
        return None
    n = (e - off + 1 + 3) & ~3
    return s, n


def native_string_views(p, symbol, text):
    """Recover string objects obscured by a byte pointer to a TU pool."""
    from .sdkimport import masked
    from .fixup_source import _function_body_span, commutations
    from .dataimport import pool_objects, payload
    code = masked(text)
    sym = p.resolve(symbol)
    span = _function_body_span(code, sym.name)
    if not span:
        return []
    out = []
    for declaration in re.finditer(r'\bextern\s+(?:const\s+)?(char|u8|unsigned char)\s+(\w+)\s*\[[^\]]*\]\s*;', code[:span[0]]):
        typ, anchor = declaration.groups()
        owner = p.find_symbol(anchor, sym.module)
        if not owner or owner.module != sym.module or owner.section not in ('.rodata', '.data'):
            continue
        casts = r'(?:\(\s*(?:const\s+)?(?:char|u8|unsigned char|u32|void)\s*\*?\s*\)\s*)*'
        assignment = list(re.finditer(r'\b(\w+)\s*=\s*'+casts+r'&?'+re.escape(anchor)+r'\s*;', code[span[1]:span[2]]))
        if len(assignment) != 1:
            continue
        assign = assignment[0]
        root = assign[1]
        if len(re.findall(r'\b'+re.escape(root)+r'\s*=(?!=)',code[span[1]:span[2]])) != 1:
            continue
        root_decl = re.search(r'\b(?:const\s+)?(?:char|u8|unsigned char)\s*\*\s*'+re.escape(root)+r'\s*([;=])', code[span[1]:span[2]])
        if not root_decl:
            continue
        edits = [(declaration.start(), declaration.end(), ''),
                 (span[1]+assign.start(),span[1]+assign.end(),''),
                 (span[1]+root_decl.start(),span[1]+root_decl.end(),'')]
        if root_decl[1] == '=':
            edits = [edits[0],(span[1]+root_decl.start(),span[1]+assign.end(),'')]
        uses = []
        operations = []
        commutations(text, sym.name, operations)
        for op in operations:
            if op['op'] != '+':
                continue
            left,right = (code[slice(*op[k])].strip() for k in ('left','right'))
            left = re.sub(casts, '', left).strip(' ()')
            if left != root or not re.fullmatch(r'0x[\da-fA-F]+|\d+',right):
                continue
            uses.append((op['start'],op['end'],int(right,0)))
        for use in re.finditer(r'\b'+re.escape(root)+r'\b(?:\s*\+\s*(0x[\da-fA-F]+|\d+))?', code[span[1]:span[2]]):
            lo, hi = span[1]+use.start(),span[1]+use.end()
            if any(a<=lo<b for a,b,_ in edits):
                continue
            if any(a<=lo<b for a,b,_ in uses):
                continue
            # Dynamic indexing needs a measured aggregate view, not a string.
            if re.match(r'\s*(?:\[|\+|-|->|=)',code[hi:]):
                uses = []; break
            uses.append((lo,hi,int(use[1],0) if use[1] else 0))
        if not uses:
            continue
        section = section_bytes(p, owner.module, owner.section, owner.addr)
        if section is None:
            continue
        base, raw = section
        cursor, limit = owner.addr-base, max(off for _,_,off in uses)
        start = cursor
        objects = {}
        while cursor-start <= limit:
            string = string_at(raw,cursor)
            if string is None:
                break
            value,width = string
            if raw[cursor+len(value)+1:cursor+width] != bytes(width-len(value)-1):
                break
            objects[cursor-start] = (value,width)
            cursor += width
        if any(off not in objects for _,_,off in uses):
            continue
        try:
            physical = pool_objects(p, owner.module, owner.section, owner.addr, cursor-start)
            if not physical or any(owner.addr <= obj.addr+r['offset'] < base+cursor
                                   for obj in physical for r in payload(p,obj)[1]):
                continue
        except (ValueError, KeyError):
            continue
        prefix = 'fzgx_pool_strings_'+anchor
        storage = 'const char' if owner.section == '.rodata' else 'char'
        definitions = [f'static {storage} {prefix}_{off:X}[{width}] = {c_literal(value)};'
                       for off,(value,width) in objects.items()]
        for lo,hi,off in uses:
            edits.append((lo,hi,f'(({typ} *){prefix}_{off:X})'))
        body = text
        for lo,hi,value in sorted(edits,reverse=True):
            body = body[:lo]+value+body[hi:]
        at = declaration.start()
        definitions = '\n'.join(definitions)+'\n'
        out.append(('native string objects '+anchor,body[:at]+definitions+body[at:]))
    return out


def inline_accessor_calls(text, name):
    """`h(p)` -> `(p->f)` inside function `name`, for every static inline one-parameter
    helper whose body is a single `return EXPR;` reading through its parameter. A model
    pointer passed to such a helper (fn_1_E7524's `phys_debug_table(strs)`) is only read
    through `->`, which the layout families require of a model."""
    helpers = {}
    for m in re.finditer(r"\bstatic\s+inline\s+[^;{}()]*?\b(\w+)\s*\(\s*(?:const\s+)?(?:struct\s+)?\w+\s*\*\s*(\w+)\s*\)"
                         r"\s*\{\s*return\s+([^;{}]+);\s*\}", text):
        h, param, expr = m.groups()
        if re.search(r"\b%s\b(?!\s*->)" % re.escape(param), expr):
            continue
        helpers[h] = (param, expr.strip())
    function = re.search(r'\n[^\n;{}]*\b' + re.escape(name) + r'\s*\([^;{}]*\)\s*\{', text)
    if not helpers or not function:
        return text
    pat = re.compile(r"\b(%s)\s*\(\s*(\w+)\s*\)" % '|'.join(re.escape(h) for h in helpers))
    def _sub(m):
        param, expr = helpers[m.group(1)]
        return '(' + re.sub(r"\b%s\b" % re.escape(param), m.group(2), expr) + ')'
    head, body = text[:function.start()], pat.sub(_sub, text[function.start():])
    # a helper left without callers goes too: its body would read the model's fields
    # before the layout's definitions
    for h in helpers:
        if not re.search(r"\b%s\s*\(" % re.escape(h), body):
            head = re.sub(r"(?m)^[ \t]*static\s+inline\s+[^;{}()]*?\b%s\s*\([^;{}]*\)\s*\{[^{}]*\}[ \t]*\n?" % re.escape(h), '', head)
    return head + body


def initialized_data_views(p, symbol, text):
    """Native data objects behind an extern aggregate view; also with trivial accessor
    helpers inlined, so a model passed to one is still a model."""
    seen = set()
    inlined = inline_accessor_calls(text, p.resolve(symbol).name)
    for source in [text] + ([inlined] if inlined != text else []):
        for label, candidate in _initialized_data_views(p, symbol, source):
            if candidate not in seen:
                seen.add(candidate)
                yield (label + (' (accessors inlined)' if source is not text else '')), candidate


def _initialized_data_views(p, symbol, text):
    """Recover native data objects hidden behind an extern aggregate view.

    MWCC introduces its shared data base for separate initialized objects.
    Keeping the whole region behind one pointer changes both address folding
    and the order of the data and literal bases in the prologue.
    """
    import struct
    from .dataimport import number, payload, pool_objects
    sym = p.resolve(symbol)
    function = re.search(r'\n[^\n;{}]*\b' + re.escape(sym.name) + r'\s*\([^;{}]*\)\s*\{', text)
    if not function:
        return
    # `T *p = (T *)&lbl;`, or the uncast form `T *p = &lbl;` / `p = &lbl;` whose type comes
    # from the pointer's or the object's own declaration (fn_1_154798, fn_1_58994)
    pattern = (r'(?:(?:struct\s+)?(\w+)\s*\*\s*)?(\w+)\s*=\s*'
               r'(?:\((?:struct\s+)?(\w+)\s*\*\)\s*)?&?(lbl_\w+)\s*;')
    for model in re.finditer(pattern, text[function.start():]):
        declared, var, tag, base = model.groups()
        known = p.symbols(sym.module).get(base)
        if not known or known.section != '.data':
            continue
        if tag is None:
            tag = declared
            if tag is None:
                pointer_decl = re.search(r'(?m)^[ \t]*(?:struct\s+)?(\w+)\s*\*\s*' + re.escape(var) + r'\s*;',
                                         text[function.start():])
                object_decl = re.search(r'\bextern\s+(?:struct\s+)?(\w+)\s+' + re.escape(base) + r'\s*;', text)
                tag = (pointer_decl or object_decl or [None, None])[1]
            if tag is None or tag in SCALAR:
                continue
        members = struct_text(tag, text)
        if members is None:
            continue
        decls = field_decls(members)
        used = sorted(set(re.findall(r'\b' + re.escape(var) + r'\s*->\s*(\w+)', text)))
        byte_offsets = {int(m[1], 0) for m in re.finditer(
            r'\(\s*u8\s*\*\s*\)\s*' + re.escape(var) + r'\s*\+\s*(0x[\da-fA-F]+|\d+)\b', text)}
        if byte_offsets:
            is_tag = re.search(r'\bstruct\s+' + re.escape(tag) + r'\s*\{', text)
            all_fields, error = probe_layout(p, sym.module, text[:function.start()],
                'struct ' + tag if is_tag else tag, list(decls), decls, symbol)
            if error:
                continue
            used = sorted(set(used) | {n for n, m in all_fields.items() if m[0] in byte_offsets})
        if not used or any(n not in decls or len(decls[n][1]) > 1 for n in used):
            continue
        # function-pointer tables (inline or through a typedef) are pointer words like `char *`
        if any(decls[n][0] not in ('u32', 's32', 'f32', 'char', 'u8', 'char *', 'void *')
               and not pointer_typedef(decls[n][0], text) for n in used):
            continue
        statement = model[0]
        rest = text[:function.start()] + text[function.start():].replace(statement, '', 1)
        rest = re.sub(r'(?m)^[ \t]*(?:struct\s+)?' + re.escape(tag) + r'\s*\*\s*' + re.escape(var) + r'\s*;\n', '', rest)
        rest_function = re.search(r'\n[^\n;{}]*\b' + re.escape(sym.name) + r'\s*\([^;{}]*\)\s*\{', rest)
        is_tag = re.search(r'\bstruct\s+' + re.escape(tag) + r'\s*\{', text)
        measured, error = probe_layout(p, sym.module, text[:function.start()],
                                       'struct ' + tag if is_tag else tag, used, decls, symbol)
        if error:
            continue
        # Lifts mix named fields with byte-offset aliases of the same arrays.
        # Normalize only exact field starts proven by the selected layout.
        for name, (offset, _, _, _) in measured.items():
            address = (var + '->' + name) if decls[name][1] else ('&(' + var + '->' + name + ')')
            pattern = r'\(\s*u8\s*\*\s*\)\s*' + re.escape(var) + r'\s*\+\s*(0x[\da-fA-F]+|\d+)\b'
            rest = re.sub(pattern, lambda m: '(u8 *)' + address if int(m[1], 0) == offset else m[0], rest)
        from .sdkimport import masked
        accesses = re.sub(r'\b' + re.escape(var) + r'\s*->\s*\w+', '', masked(rest[rest_function.start():]))
        if re.search(r'\b' + re.escape(var) + r'\b', accesses):
            continue
        fields = sorted((measured[n][0], measured[n][0] + measured[n][1], n) for n in used)
        extent = fields[-1][1]
        if any(lo % 4 or hi % 4 for lo, hi, _ in fields):
            continue
        if any(a[1] > b[0] for a, b in zip(fields, fields[1:])):
            continue
        raw_section = section_bytes(p, sym.module, '.data')
        if raw_section is None:
            continue
        origin, raw = raw_section
        raw = raw[known.addr - origin:known.addr - origin + extent]
        if len(raw) != extent:
            continue
        relocations = {}
        try:
            for obj in pool_objects(p, sym.module, '.data', known.addr, extent):
                _, relocs = payload(p, obj)
                for rel in relocs:
                    offset = obj.addr + rel['offset'] - known.addr
                    if 0 <= offset < extent:
                        if rel['kind'] != 1 or offset % 4 or rel['addend'] < 0:
                            raise ValueError('unsupported initialized pointer')
                        relocations[offset] = rel
        except (ValueError, KeyError):
            continue
        declarations, definitions = set(), []
        prefix = 'fzgx_pool_native_' + base
        def value(offset):
            rel = relocations.get(offset)
            if rel:
                alias = rel['symbol'] + '__fzgx_offset_%X' % rel['addend']
                declarations.add('extern u8 ' + alias + '[];')
                return '(u32)' + alias
            return '0x%08X' % struct.unpack_from('>I', raw, offset)[0]
        cursor = 0
        valid = True
        for lo, hi, name in fields:
            if cursor < lo:
                definitions.append('static u32 %s_gap_%X[%d] = {%s}; /* fzgx-allow: A1 measured pool bytes and bindings */' %
                                   (prefix, cursor, (lo - cursor) // 4, ', '.join(value(i) for i in range(cursor, lo, 4))))
            ty, dims, declaration = decls[name]
            native = prefix + '_' + name
            pointer = ty is None or '*' in ty or pointer_typedef(ty, text)
            if ty is None or (pointer and any(i not in relocations and any(raw[i:i + 4]) for i in range(lo, hi, 4))):
                # Inferred pointer arrays sometimes extend into adjacent text.
                # Keep their bounds, but store non-pointer words as words rather
                # than manufacturing literal pointer casts from string bytes.
                definitions.append('static union {u32 words[%d]; %s} %s = {{%s}}; /* fzgx-allow: A1 measured pool bytes and bindings */' %
                                   ((hi - lo) // 4, fdef(decls[name], 'view'), native,
                                    ', '.join(value(i) for i in range(lo, hi, 4))))
                native += '.view'
                values = None
            elif ty in ('char', 'u8'):
                if any(lo <= i < hi for i in relocations):
                    # A saved string view may span later pointer tables.
                    # Preserve the view while giving their relocations full
                    # word initializers; never turn pointer slots into zeros.
                    definitions.append('static union {u32 words[%d]; %s} %s = {{%s}}; /* fzgx-allow: A1 measured pool bytes and bindings */' %
                                       ((hi - lo) // 4, fdef(decls[name], 'view'), native,
                                        ', '.join(value(i) for i in range(lo, hi, 4))))
                    native += '.view'
                    values = None
                else:
                    values = ', '.join('0x%02X' % byte for byte in raw[lo:hi])
            elif ty == 'f32':
                if any(lo <= i < hi for i in relocations):
                    valid = False
                    break
                try:
                    values = ', '.join(number(raw[i:i + 4], ty) for i in range(lo, hi, 4))
                except ValueError:
                    valid = False
                    break
            else:
                values = ', '.join(('(' + ty + ')' if pointer else '') + value(i) for i in range(lo, hi, 4))
            if values is not None:
                initializer = '{' + values + '}' if dims else values
                definitions.append('static ' + fdef(decls[name], native).rstrip(';') + ' = ' + initializer + '; /* fzgx-allow: A1 measured pool bytes and bindings */')
            rest = re.sub(r'\b' + re.escape(var) + r'\s*->\s*' + re.escape(name) + r'\b', native, rest)
            cursor = hi
        if not valid:
            continue
        block = '\n'.join(sorted(declarations)) + '\n' + '\n'.join(definitions) + '\n'
        at = re.search(r'\n[^\n;{}]*\b' + re.escape(sym.name) + r'\s*\([^;{}]*\)\s*\{', rest).start()
        yield 'native initialized data objects ' + base, rest[:at] + '\n' + block + rest[at:]


BYTE_TYPES = r'(?:const\s+)?(?:u8|s8|char|unsigned\s+char|signed\s+char)'
# initialized sections whose objects a TU defines and MWCC addresses off one section base
# (DOL lookup tables live in .rodata: fn_8005C7C0/fn_8005C9D8 read lbl_800929D8 + 0x20/0x40/0x60)
DATA_SECTIONS = ('.data', '.rodata')


def _call_arguments(code, start):
    """Top-level argument texts of the call whose '(' is at `start`, or None."""
    depth, args, cur = 0, [], start + 1
    for i in range(start, len(code)):
        c = code[i]
        if c in '([{':
            depth += 1
        elif c in ')]}':
            depth -= 1
            if depth == 0:
                args.append(code[cur:i].strip())
                return args
        elif c == ',' and depth == 1:
            args.append(code[cur:i].strip())
            cur = i + 1
    return None


def _helper_aliases(code, lo, hi, tokens):
    """((argument token, parameter), (body start, body end), helper) for every static inline helper that
    the function body [lo, hi) calls and that receives one of `tokens` at the same position in
    every call of the file; the parameter is never reassigned in the helper."""
    from .fixup_source import _function_body_span
    out = []
    for d in re.finditer(r'\bstatic\s+inline\b[^;{}()]*?\b(\w+)\s*\(([^;{}()]*)\)\s*\{', code):
        name, params = d[1], [x.strip() for x in d[2].split(',')]
        names = [re.search(r'(\w+)\s*(?:\[[^\]]*\])?$', x) for x in params]
        if not params or any(n is None for n in names):
            continue
        span = _function_body_span(code, name)
        if not span or span[0] != d.start(1):
            continue
        calls = [m for m in re.finditer(r'(?<![\w.>])%s\s*\(' % re.escape(name), code) if m.start() != d.start(1)]
        if not calls or not any(lo <= m.start() < hi for m in calls):
            continue
        argsets = [_call_arguments(code, m.end() - 1) for m in calls]
        if any(a is None or len(a) != len(params) for a in argsets):
            continue
        for k, n in enumerate(names):
            first = argsets[0][k]
            param = n[1]
            if first not in tokens or any(a[k] != first for a in argsets):
                continue
            body = code[span[1]:span[2]]
            if re.search(r'(?<![\w.>])%s\s*(?:[-+*/|&^]?=(?!=)|\+\+|--)|(?:\+\+|--)\s*%s\b|&\s*%s\b'
                         % ((re.escape(param),) * 3), body):
                continue
            out.append(((first, param), (span[1], span[2]), name))
    return out


def _after_type_definitions(code, limit):
    """Offset after the last file-scope typedef/struct/union/enum statement before `limit`
    (masked code: comments and strings blanked), at a line start; 0 when there is none."""
    end, depth, start = 0, 0, 0
    for i in range(limit):
        c = code[i]
        if c == '\n' and depth == 0 and code[start:i].lstrip().startswith('#'):
            start = i + 1
        elif c == '{':
            depth += 1
        elif c == '}':
            depth = max(0, depth - 1)
        elif c == ';' and depth == 0:
            # typedefs, `struct T {...};` and `struct T;`, not `struct T object = ...;`
            if re.match(r'\s*(?:typedef\b|(?:struct|union|enum)\s*\w*\s*(?:\{.*\})?\s*$)', code[start:i], re.S):
                nl = code.find('\n', i)
                end = limit if nl < 0 or nl >= limit else nl + 1
            start = i + 1
    return end


def tu_data_objects(p, symbol, text, top=False, limit=0x100000):
    """Retail `.data` as separate objects addressed off the TU's data section base.

    A byte view of a retail `.data` block (`u8 *s = lbl;`, `lbl + N`) keeps one object, so
    MWCC folds every constant offset into a load displacement (`add; lwz 0x5c84(r3)`) and keeps
    the view in a declared local. Retail defines each object separately: an indexed table gets
    its own address (`addi r4, r30, 0x5c84; lwzx`) and the section base is a compiler
    temporary. This defines the block from the model's symbol up to its last referenced object
    as word arrays split at every referenced dtk object, with retail bytes and every pointer
    word as a symbolic `__fzgx_offset_` initializer, in retail order (a `.fzgxpool` primer
    touches them in that order). The definitions are `fzgx_pool_` statics: the oracle proves
    the whole section against retail before binding its base. MWCC addresses objects off a
    section base only when a function references three or more of them (two are addressed by
    name), and numbers the section-base temporaries by where their sections' first definitions
    sit in the file (fn_1_B5F20: the block above the literal pool gives retail's pool r29,
    data r30), so `top` places the block before every other file-scope definition.

    A view of the far part of a block (`table = lbl + 0x60000;`, `(u8 *)&lbl + 0x80000`) is the
    same model with every use that much further in: retail addresses objects beyond 32 KB of
    a section through one `addis rX, rBase, N` web, and only a unit whose `.data` reaches
    those offsets reproduces it, so the block runs from the section's first object (`limit`
    allows 1 MB: fn_17_5C24's 0x64378-byte block with 937 pointers compiles in about a
    second and gives retail's `addis r31, r3, 0x6` over the `.bss` base r30; a pool match,
    since a pool carrying relocations is not proven byte-equal)."""
    import struct
    from .sdkimport import masked
    from .fixup_source import _function_body_span
    from .dataimport import payload, pool_objects
    sym = p.resolve(symbol)
    syms = p.symbols(sym.module)
    code = masked(text)
    span = _function_body_span(code, sym.name)
    if not span:
        return None, ['function definition not found']
    head, lo, hi = span[0], span[1], span[2]

    def collect(code, head, lo, hi):
        """label -> ([(token, pointee type)], edits removing the byte-pointer models)"""
        found = {}
        # `(?<![\w.>])`: a carrier member `w.value = lbl;` is not a plain local `value`
        for m in re.finditer(r'(?:\b(%s)\s*\*\s*)?(?<![\w.>])(\w+(?:\.\w+)?)\s*=\s*(?:\(\s*(?:%s|void)\s*\*\s*\)\s*)?(&\s*)?\b(lbl_\w+)\s*(?:\+\s*(0x[\da-fA-F]+|\d+)\s*)?;'
                             % (BYTE_TYPES, BYTE_TYPES), code[lo:hi]):
            declared, var, amp, label, base = m.groups()
            # `table = lbl + 0x60000;`: a view of the far part of a large block (retail
            # addresses objects beyond 32 KB of the section base through one `addis` web,
            # fn_17_5C24, fn_16_1038); every use of the view is that much further in
            if base and amp and not re.search(r'\*\s*\)\s*&', m[0]) and not re.search(
                    r'\bextern\s+(?:const\s+)?%s\s+%s\s*;' % (BYTE_TYPES, re.escape(label)), code[:head] + include_text()):
                # `&lbl + N` without a byte cast scales by the object's size; over a byte
                # scalar (`extern u8 lbl_17_data_0;`, fn_17_424C's far view) it is in bytes
                continue
            known = syms.get(label)
            if not known or known.section not in DATA_SECTIONS or known.kind != 'object':
                continue
            if len(re.findall(r'(?<![\w.>])%s\s*=(?!=)' % re.escape(var), code[lo:hi])) != 1:
                continue
            # a cursor (`mode.value++`, fn_1_2F04) is not a constant view: replacing it by the
            # object's address left `(u8 *)obj++`, which never compiles
            if re.search(r'(?<![\w.>])%s\s*(?:\+\+|--|[-+*/|&^]=)|(?:\+\+|--)\s*%s\b' % (re.escape(var), re.escape(var)),
                         code[lo:hi]):
                continue
            edits = [(lo + m.start(), lo + m.end())]
            ptype = declared
            if '.' in var:
                # the lifter's one-member constant-pointer carrier `struct { u8 *value; } w;`
                carrier, member = var.split('.')
                d = re.search(r'(?m)^[ \t]*struct\s*\{\s*(%s)\s*\*\s*%s\s*;\s*\}\s*%s\s*;[ \t]*\n?'
                              % (BYTE_TYPES, re.escape(member), re.escape(carrier)), code[lo:hi])
                if declared or not d:
                    continue
                ptype = d[1]
                edits.append((lo + d.start(), lo + d.end()))
            elif ptype is None:
                d = re.search(r'(?m)^[ \t]*(%s)\s*\*\s*%s\s*;[ \t]*\n?' % (BYTE_TYPES, re.escape(var)), code[lo:hi])
                if not d:
                    continue
                ptype = d[1]
                edits.append((lo + d.start(), lo + d.end()))
            if amp is None:
                decl = re.search(r'\bextern\s+(?:const\s+)?(\w+(?:\s+char)?)\s+%s\s*\[' % re.escape(label), code[:head] + include_text())
                # an array of any element type decays to its address; behind an explicit byte
                # cast (`u8 *base = (u8 *)lbl_1_data_2A0C0;` over `u32 lbl[4]`, fn_1_9D994)
                # every offset is in bytes too. Uncast, only a byte array keeps byte offsets.
                byte_cast = re.search(r'=\s*\(\s*%s\s*\*\s*\)' % BYTE_TYPES, m[0])
                if not decl or not (re.fullmatch(BYTE_TYPES, decl[1]) or byte_cast):
                    continue
            tokens, all_edits, origins = found.setdefault(label, ([], [], {}))
            tokens.append((var, re.sub(r'\s+', ' ', ptype)))
            origins[var] = int(base, 0) if base else 0
            all_edits.extend(edits)
        # a byte array label used directly, also beside a model: `lbl + N`, `(T *)(lbl + N)`
        for label in sorted(set(re.findall(r'\b(lbl_\w+)\s*\+\s*\(?\s*(?:0x[\da-fA-F]+|\d+)\b', code[lo:hi]))):
            known = syms.get(label)
            if not known or known.section not in DATA_SECTIONS or known.kind != 'object':
                continue
            decl = re.search(r'\bextern\s+((?:const\s+)?\w+(?:\s+char)?)\s+%s\s*\[' % re.escape(label), code[:head] + include_text())
            if decl and re.fullmatch(BYTE_TYPES, decl[1]):
                found.setdefault(label, ([], [], {}))[0].append((label, re.sub(r'\s+', ' ', decl[1])))
        return found

    labels = sorted(collect(code, head, lo, hi))
    if not labels:
        return None, ['no byte view of a same-module .data/.rodata object']
    notes, out = [], text
    for label in labels:
        # positions move with every rewrite: collect each label on the current text
        models = collect(code, head, lo, hi)
        if label not in models:
            continue
        tokens, edits, origins = models[label]
        types = dict(tokens)
        known = syms[label]
        token = '(?:%s)' % '|'.join(re.escape(name) for name in types)
        # every use: `x + N`, `x + (N)`, `x[N]`, or the bare pointer (offset 0); the scan covers
        # the body and the file-scope macros that spell the view
        regions = [(lo, hi, token)] + [(m.start(), m.end(), token) for m in re.finditer(r'(?m)^[ \t]*#\s*define\b.*$', code[:head])]
        # a static inline helper that receives the view as an argument at every call indexes the
        # same object through its parameter (fn_8005C9D8's `levels(tbl.value, ...)`): the
        # parameter is a token inside the helper's body
        helpers = set()
        for (arg, param), (a, b), helper in _helper_aliases(code, lo, hi, set(types)):
            types[param] = types[arg]
            if origins.get(arg):
                origins[param] = origins[arg]
            regions.append((a, b, re.escape(param)))
            helpers.add(helper)
        uses = []
        for a, b, tok in regions:
            # `x[K + e]` / `x[e + K]`: an index expression into the object at K
            for m in re.finditer(r'(?<![\w.>])(%s)\b(?!\s*=[^=])(?:\s*\+\s*(\()?\s*(0x[\da-fA-F]+|\d+)\b(?(2)\s*\))'
                                 r'|\s*\[\s*(0x[\da-fA-F]+|\d+)\s*\]'
                                 r'|\s*\[\s*(0x[\da-fA-F]+|\d+)\s*\+\s*(\w+)\s*\]'
                                 r'|\s*\[\s*(\w+)\s*\+\s*(0x[\da-fA-F]+|\d+)\s*\])?' % tok, code[a:b]):
                s, e = a + m.start(), a + m.end()
                if any(x <= s < y for x, y in edits):
                    continue
                if re.search(r'&\s*$', code[max(0, s - 4):s]):
                    break
                off, index = m[3], m[4]
                if m[5] or m[8]:
                    uses.append((s, e, origins.get(m[1], 0) + int(m[5] or m[8], 0), ('xindex', m[6] or m[7]), types[m[1]]))
                    continue
                if off and not m[2] and re.match(r'\s*[*/%\[]', code[e:]):
                    # `x + 4 * i`: only the pointer itself is a constant address
                    e, off = s + len(m[1]), None
                uses.append((s, e, origins.get(m[1], 0) + int(off or index or '0', 0), 'index' if index else 'ptr', types[m[1]]))
            else:
                continue
            uses = None
            break
        if not uses:
            notes.append(f'{label}: no usable references'); continue
        objects = sorted((s for s in syms.values() if s.section == known.section and s.kind == 'object'), key=lambda s: s.addr)
        section = section_bytes(p, sym.module, known.section, known.addr)
        if section is None:
            notes.append(f'{label}: no retail {known.section} bytes'); continue
        origin, whole = section
        cuts, refs = {0}, {}
        for _, _, off, _, _ in uses:
            address = known.addr + off
            owner = next((s for s in objects if s.addr <= address < max(s.end, s.addr + 1)), None)
            start = owner.addr if owner and owner.addr >= known.addr else address
            if start != address and address % 4 == 0:
                # dtk joins unlabelled string literals into one object; each literal is its own
                # retail object (MWCC pools a section base only over three referenced objects),
                # and `(u8 *)obj + k` never folds into the base's `addi rX, rBase, off`
                start = address
            # dtk labels a byte store target inside a word array (fn_1_854D4's `s8[4]` rows:
            # 0x2065C size 1, 0x2065D size 3); a retail array object ends on a word boundary
            following = next((s.addr for s in objects if s.addr > start and s.addr % 4 == 0), None)
            end = owner.end if owner and owner.addr >= known.addr else address + 1
            end = (end + 3) & ~3
            if following is not None and following < end:
                end = following
            refs[off] = start - known.addr
            cuts.update((start - known.addr, end - known.addr))
        extent = max(cuts)
        if any(c % 4 for c in cuts) or known.addr % 4:
            notes.append(f'{label}: a referenced object is not word aligned'); continue
        if extent > limit:
            notes.append(f'{label}: block of {extent:#x} bytes exceeds {limit:#x}'); continue
        raw = whole[known.addr - origin:known.addr - origin + extent]
        if len(raw) != extent:
            notes.append(f'{label}: block runs past the section'); continue
        relocations = {}
        try:
            for obj in pool_objects(p, sym.module, known.section, known.addr, extent):
                for rel in payload(p, obj)[1]:
                    offset = obj.addr + rel['offset'] - known.addr
                    if 0 <= offset < extent:
                        if rel['kind'] != 1 or offset % 4 or rel['addend'] < 0 or not re.fullmatch(r'[A-Za-z_]\w*', rel['symbol']):
                            raise ValueError('unsupported initialized pointer')
                        relocations[offset] = rel
        except (ValueError, KeyError) as exc:
            notes.append(f'{label}: {exc}'); continue
        declarations, definitions, names = set(), [], {}
        def word(offset):
            rel = relocations.get(offset)
            if rel:
                alias = rel['symbol'] + '__fzgx_offset_%X' % rel['addend']
                declarations.add('extern u8 ' + alias + '[];')
                return '(u32)' + alias
            return '0x%X' % struct.unpack_from('>I', raw, offset)[0]
        bounds = sorted(cuts)
        for a, b in zip(bounds, bounds[1:]):
            owner = next((s for s in objects if s.addr == known.addr + a), None)
            name = f'fzgx_pool_{known.section[1:]}_{owner.name if owner else label + "_%X" % a}'
            names[a] = name
            words = [word(i) for i in range(a, b, 4)]
            lines = '\n'.join(allow_address_words('    ' + ', '.join(words[i:i + 8]) + (',' if i + 8 < len(words) else ''))
                              for i in range(0, len(words), 8))
            definitions.append(f'static {"const " if known.section == ".rodata" else ""}u32 {name}[{len(words)}] = {{  /* fzgx-allow: A1 retail data bytes and bindings */\n{lines}\n}};')
        replacements = [(s, e, '') for s, e in edits]
        for s, e, off, kind, ptype in uses:
            start = refs[off]
            inner = off - start
            value = f'(({ptype} *){names[start]} + {inner:#x})' if inner else f'(({ptype} *){names[start]})'
            if isinstance(kind, tuple):
                replacements.append((s, e, f'{value}[{kind[1]}]'))
            else:
                replacements.append((s, e, f'(*{value})' if kind == 'index' else value))
        for s, e, value in sorted(replacements, reverse=True):
            out = out[:s] + value + out[e:]
            code = code[:s] + value + code[e:]
        if not re.search(r'\b%s\b' % re.escape(label), re.sub(r'(?m)^[^\n]*\bextern\b[^\n;]*;', '', code)):
            out = re.sub(r'(?m)^[ \t]*extern\b[^\n;]*\b%s\b[^\n;]*;[ \t]*\n?' % re.escape(label), '', out)
        primer = ('#pragma section code_type ".fzgxpool"\nstatic void fzgx_data_layout_%s(void) {\n'
                  '    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */\n' % label
                  + ''.join(f'    s = *(u8 *){n};\n' for _, n in sorted(names.items()))
                  + '}\n#pragma section code_type ".text"\n')
        block = '\n'.join(sorted(declarations)) + '\n' + '\n'.join(definitions) + '\n' + primer + '\n'
        code = masked(out)
        span = _function_body_span(code, sym.name)
        at = code.rfind('\n', 0, span[0]) + 1
        for helper in helpers:
            # the definitions precede every helper that now names them
            hm = re.search(r'(?m)^[^\n;{}]*\bstatic\s+inline\b[^;{}()]*?\b%s\s*\(' % re.escape(helper), code)
            if hm:
                at = min(at, hm.start())
        if top:
            directives = list(re.finditer(r'(?m)^[ \t]*#\s*include\b[^\n]*\n', code[:at]))
            # a self-contained body spells its own typedefs (fn_4_ADF4, fn_8_D630): the block
            # goes after the last file-scope type definition, never above `typedef ... u32;`
            at = max([directives[-1].end() if directives else 0, _after_type_definitions(code, at)])
        out = out[:at] + block + out[at:]
        code = masked(out)
        span = _function_body_span(code, sym.name)
        head, lo, hi = span
        notes.append(f'{label}: {len(names)} objects over {extent:#x} bytes, {len(relocations)} pointers')
    return (out if out != text else None), notes



def _top_statements(code):
    """(start, end) of every file-scope statement of masked `code`: up to its `;`, or up to the
    closing `}` of a function definition. Preprocessor lines are skipped."""
    out, depth, start, brace, i, n = [], 0, None, None, 0, len(code)
    while i < n:
        c = code[i]
        if depth == 0 and start is None:
            if c.isspace():
                i += 1
                continue
            if c == '#':
                while i < n and code[i] != '\n':
                    i += 2 if code[i] == '\\' else 1
                continue
            start, brace = i, None
        if c in '{([':
            if c == '{' and depth == 0 and brace is None:
                brace = i
            depth += 1
        elif c in '})]':
            depth -= 1
            if depth == 0 and c == '}' and brace is not None and code[start:brace].rstrip().endswith(')'):
                out.append((start, i + 1))
                start = None
        elif c == ';' and depth == 0:
            out.append((start, i + 1))
            start = None
        i += 1
    return out


def _reloc_map(elf, section):
    """{instruction offset: (symbol, addend)} of the relocations against `section`."""
    import struct
    symbols = elf.symbols()
    out = {}
    for rsec in elf.sections:
        if rsec['type'] != 4 or rsec['info'] != section['index']:
            continue
        for pos in range(rsec['offset'], rsec['offset'] + rsec['size'], 12):
            offset, info, addend = struct.unpack_from('>IIi', elf.data, pos)
            out[poolfix.code_reloc_offset(offset, info & 255)] = (symbols[info >> 8], addend)
    return out


def defined_data_initializers(p, symbol, body, check):
    """Retail initializers for the TU data objects a body already defines.

    A body that defines the retail TU's `.data`/`.rodata` objects itself (so MWCC addresses
    them off one section base, `addi rX, rBase, off; lwzx`, as retail does) but cannot read
    retail's bytes carries placeholder initializers (`{ 1 }`, invented strings): the code
    matches while the oracle reports the unit's `...data.0` differing from retail in most
    words (fn_1_956EC: 2785 of 7052, fn_1_9AABC: 248 of 457). The byte-view families
    (`tu_data_objects`, `initialized_data_views`) only rewrite extern labels and models, so
    they never fire on such a body. This compiles the body, anchors each initialized section
    at the retail address its paired code relocations resolve to (all must agree), and
    redefines every named object of the section in place, same declarator, as a
    `fzgx_pool_init_` union whose first member carries retail's words (pointer words as
    symbolic `__fzgx_offset_` initializers) or bytes; uses become `.v`. Code and layout stay
    as written; the oracle still proves the whole section before binding its base."""
    import hashlib
    import struct
    from .sdkimport import masked
    from .dataimport import payload, pool_objects
    if check is None or not check.ok or not check._rows:
        return []
    sym = p.resolve(symbol)
    target = p.target_object_for(sym)
    if target is None or not target.exists():
        return []
    # the checked object is this body under its own compiler response (the engine's checks
    # carry no compiler version); compile only when the check kept no object
    checked = getattr(check, '_object', None)
    if checked is not None and Path(checked).exists():
        ours = poolfix.Elf(Path(checked).read_bytes())
    else:
        d = STATE_DIR / 'fixup' / 'probe'
        d.mkdir(parents=True, exist_ok=True)
        src = d / f"datainit_{sym.name}_{hashlib.sha1(body.encode()).hexdigest()[:10]}.c"
        src.write_text(body)
        obj = src.with_suffix('.o')
        cp = oracle.compile_source(p, sym.module, src, obj, check.mw_version, check.extra_cflags)
        if cp.returncode != 0 or not obj.exists():
            return []
        ours = poolfix.Elf(obj.read_bytes())
        src.unlink(missing_ok=True)
        obj.unlink(missing_ok=True)
    retail = poolfix.Elf(target.read_bytes())
    ofn = next((s for s in ours.symbols() if s['name'] == sym.name and s['shndx']), None)
    rfn = next((s for s in retail.symbols() if s['name'] == sym.name and s['shndx']), None)
    if not ofn or not rfn:
        return []
    orel = _reloc_map(ours, ours.sections[ofn['shndx']])
    rrel = _reloc_map(retail, retail.sections[rfn['shndx']])
    syms = p.symbols(sym.module)
    anchors = {}
    for l, r in zip(*check._rows):
        li, ri = l.get('instruction') or {}, r.get('instruction') or {}
        if not li.get('relocation') or not ri.get('relocation'):
            continue
        # objdiff JSON addresses are section offsets (decimal strings): the function's first
        # row carries its symbol value (fn_1_7ACDC's retail rows start at 0x28c). Adding the
        # value again resolved every anchor to a later instruction's relocation in a multi-
        # function retail object, so the family never fired outside a section's first function
        la, ra = oracle.row_address(l), oracle.row_address(r)
        if la is None or ra is None:
            continue
        lr, rr = rrel.get(la), orel.get(ra)
        if not lr or not rr:
            continue
        (rs, radd), (os_, oadd) = lr, rr
        known = syms.get(rs['name'])
        if not known or known.kind != 'object' or not 0 < os_['shndx'] < len(ours.sections):
            continue
        section = ours.sections[os_['shndx']]
        if section['name'] not in DATA_SECTIONS or known.section != section['name']:
            continue
        anchors.setdefault(section['index'], set()).add(known.addr + radd - os_['value'] - oadd)
    code = masked(body)
    statements = _top_statements(code)
    edits, declarations = [], set()
    for index, values in sorted(anchors.items()):
        if len(values) != 1:
            continue
        section = ours.sections[index]
        anchor = next(iter(values))
        extent = section['size']
        expected, covered, relocs = bytearray(extent), bytearray(extent), {}
        try:
            for owner in pool_objects(p, sym.module, section['name'], anchor, extent):
                raw, rels = payload(p, owner)
                lo, hi = max(anchor, owner.addr), min(anchor + extent, owner.end)
                expected[lo - anchor:hi - anchor] = raw[lo - owner.addr:hi - owner.addr]
                covered[lo - anchor:hi - anchor] = b'\1' * (hi - lo)
                for rel in rels:
                    offset = owner.addr + rel['offset'] - anchor
                    if 0 <= offset < extent:
                        if (rel['kind'] != 1 or offset % 4 or offset + 4 > extent or rel['addend'] < 0
                                or not re.fullmatch(r'[A-Za-z_]\w*', rel['symbol'])):
                            raise ValueError('unsupported initialized pointer')
                        relocs[offset] = rel
        except (ValueError, KeyError):
            continue
        actual = bytes(ours.data[section['offset']:section['offset'] + extent])
        own_relocs = set(_reloc_map(ours, section))
        for own in sorted(ours.symbols(), key=lambda s: s['value']):
            name, lo, size = own['name'], own['value'], own['size']
            if (own['shndx'] != index or not size or own['info'] & 15 != 1 or lo + size > extent
                    or not re.fullmatch(r'[A-Za-z_]\w*', name) or name.startswith('fzgx_pool_init_')):
                continue
            if not all(covered[lo:lo + size]):
                continue
            inside = [o for o in range(lo, lo + size, 4) if o in relocs or o in own_relocs]
            if actual[lo:lo + size] == expected[lo:lo + size] and not inside and name in syms:
                continue
            # an object whose bytes already agree still needs the `fzgx_pool_init_` name when
            # retail has no symbol of that name: the pool binding names every defined object
            # after a retail one (fn_1_7ACDC's `sScene {0, 0, -1, 0}` kept the whole
            # cluster unbound while its filler neighbours took retail's bytes)
            owner = re.compile(r'(?<![\w.])(?<!->)\b%s\b' % re.escape(name))
            found = [(a, b) for a, b in statements if owner.search(code[a:b])
                     and not re.match(r'\s*(?:extern|typedef)\b', code[a:b])]
            definitions = [(a, b) for a, b in found if not re.search(r'\)\s*\{', code[a:b])]
            if len(definitions) != 1:
                continue
            a, b = definitions[0]
            text = code[a:b]
            eq = text.find('=')
            decl = text[:eq] if eq >= 0 else text[:-1]
            if len(owner.findall(decl)) != 1:
                continue
            depth, comma = 0, False
            for c in decl:
                depth += c in '([{'
                depth -= c in ')]}'
                comma |= c == ',' and depth == 0
            if comma:
                continue
            member = re.sub(r'\b(?:static|extern)\b\s*', '', body[a:a + len(decl)])
            member = owner.sub('v', member, count=1).strip()
            if re.search(r'\[\s*\]', member):
                if not re.fullmatch(r'(?:const\s+)?(?:u8|s8|char|unsigned\s+char|signed\s+char)\s+v\s*\[\s*\]', member):
                    continue
                member = re.sub(r'\[\s*\]', '[%d]' % size, member)
            if lo % 4 == 0 and size % 4 == 0:
                items = []
                for i in range(lo, lo + size, 4):
                    rel = relocs.get(i)
                    if rel:
                        alias = rel['symbol'] + '__fzgx_offset_%X' % rel['addend']
                        declarations.add('extern u8 ' + alias + '[];')
                        items.append('(u32)' + alias)
                    else:
                        items.append('0x%X' % struct.unpack_from('>I', expected, i)[0])
                first = 'u32 w[%d]' % (size // 4)
            elif any(lo <= o < lo + size for o in relocs):
                continue
            else:
                first, items = 'u8 w[%d]' % size, ['0x%X' % x for x in expected[lo:lo + size]]
            lines = '\n'.join(allow_address_words('    ' + ', '.join(items[i:i + 8]) + (',' if i + 8 < len(items) else ''))
                              for i in range(0, len(items), 8))
            native = 'fzgx_pool_init_' + name
            storage = 'static const' if section['name'] == '.rodata' else 'static'
            definition = (f'{storage} union {{ {first}; {member}; }} {native} = {{{{  '
                          f'/* fzgx-allow: A1 retail data bytes and bindings */\n{lines}\n}}}};')
            edits.append((a, b, definition, owner, native))
    if not edits:
        return []
    replacements = []
    for a, b, definition, owner, native in edits:
        replacements.append((a, b, definition))
        for m in owner.finditer(code):
            if any(x <= m.start() < y for x, y, *_ in edits):
                continue
            st = next(((x, y) for x, y in statements if x <= m.start() < y), None)
            if st and re.match(r'\s*extern\b', code[st[0]:st[1]]):
                # a redundant extern declaration of the object: only when it declares nothing else
                if ',' in code[st[0]:st[1]]:
                    return []
                end = st[1] + 1 if code[st[1]:st[1] + 1] == '\n' else st[1]
                replacements.append((st[0], end, ''))
                continue
            replacements.append((m.start(), m.end(), native + '.v'))
    text = body
    for s, e, value in sorted(set(replacements), reverse=True):
        text = text[:s] + value + text[e:]
    if declarations:
        first = min(a for a, *_ in edits)
        # the definitions keep their place: the aliases go on the line before the first one,
        # shifted by the removals above it
        shift = sum(len(v) - (e - s) for s, e, v in set(replacements) if e <= first)
        at = text.rfind('\n', 0, first + shift) + 1
        text = text[:at] + '\n'.join(sorted(declarations)) + '\n' + text[at:]
    return [(f'retail initializers for defined data objects ({len(edits)} objects)', text)]


_POOL_NOTE = re.compile(r'^pool (\S+) differs from retail (\S+) in \d+ of (\d+) words: (.*)$')
_POOL_TABLE = re.compile(r'(static\s+const\s+(?:u32|s32)\s+fzgx_pool_(?:table|word)_([0-9A-Fa-f]+)\s*\[\s*(\d+|0x[0-9A-Fa-f]+)\s*\]\s*=\s*)\{([^{}]*)\}')


def retail_pool_anchors(p, symbol, check, merged_only=False):
    """(retail pool symbol, words to show) for every pool the check reports as differing from
    retail's bytes; the span covers the dtk symbol, the private pool's word count and every
    offset the note lists."""
    sym = p.resolve(symbol)
    out = {}
    for note in getattr(check, 'pool_notes', None) or ():
        m = _POOL_NOTE.match(note)
        if not m or merged_only and not m.group(1).startswith('...'):
            continue  # (the primer's tables live in the merged anonymous pool, not an `@N` literal)
        anchor = p.find_symbol(m.group(2), sym.module)
        if anchor is None or anchor.section in ('.bss', '.sbss', '.sbss2'):
            continue
        offsets = [int(o, 16) for o in re.findall(r'\+0x([0-9A-Fa-f]+) ours', m.group(4))]
        span = max([anchor.size, 4 * int(m.group(3))] + [o + 4 for o in offsets])
        out[anchor.name] = max(out.get(anchor.name, 0), span)
    return out


def retail_words(p, module, name, span):
    """Retail words of `name` (a data/rodata symbol) over `span` bytes, or None."""
    anchor = p.find_symbol(name, module)
    if anchor is None:
        return None
    got = section_bytes(p, module, anchor.section, anchor.addr)
    if got is None:
        return None
    base, raw = got
    lo = anchor.addr - base
    data = bytes(raw[lo:lo + span])
    return [int.from_bytes(data[i:i + 4], 'big') for i in range(0, len(data) - 3, 4)]


def retail_pool_tables(p, symbol, body, check):
    """Primer tables (`static const u32 fzgx_pool_table_HEX[N]`, `fzgx_pool_word_HEX[1]`, the
    shared-pool primer's raw words at pool offset HEX) refilled with retail's words. A matcher
    who wrote placeholders (fn_1_15EC40: 0x110..0x174 of lbl_1_rodata_DD58) could only learn
    five differing words per check from the pool note."""
    anchors = retail_pool_anchors(p, symbol, check, merged_only=True)
    if not anchors or not (_POOL_TABLE.search(body) or _NUMBERED_TABLE.search(body)):
        return []
    module = p.resolve(symbol).module
    out = []
    for name in anchors:
        tables = list(_POOL_TABLE.finditer(body))
        span = max([anchors[name]] + [int(t.group(2), 16) + 4 * int(t.group(3), 0) for t in tables])
        words = retail_words(p, module, name, span)
        if not words:
            continue
        text, changed = body, 0
        for t in reversed(tables):
            off, n = int(t.group(2), 16), int(t.group(3), 0)
            if off % 4 or off // 4 + n > len(words):
                continue
            want = words[off // 4:off // 4 + n]
            have = [w.strip() for w in t.group(4).replace('\n', ' ').split(',') if w.strip()]
            try:
                current = [int(w.rstrip('uUlL'), 0) & 0xFFFFFFFF for w in have]
            except ValueError:
                continue  # symbolic contents: not a placeholder
            if current == want:
                continue
            rows = [', '.join(f'0x{w:08X}' for w in want[i:i + 6]) for i in range(0, n, 6)]
            init = '{\n    ' + ',\n    '.join(rows) + ',\n}' if n > 6 else '{ ' + ', '.join(f'0x{w:08X}' for w in want) + ' }'
            text = text[:t.start()] + t.group(1) + init + text[t.end():]
            changed += 1
        if changed:
            out.append((f'retail pool words ({name}, {changed} primer tables)', text))
        out += _short_primer_tables(body, name, words)
    return out


# the shared-pool primer's own tables (`fixup_evidence.shared_pool_primer`): numbered, not
# named by offset, so `_POOL_TABLE` never reaches them
_NUMBERED_TABLE = re.compile(r'(static\s+const\s+unsigned\s+long\s+fzgx_pool_table\d+\s*\[\s*(\d+)\s*\]\s*=\s*)\{([^{}]*)\}')


def _short_primer_tables(body, name, words):
    """A primer table whose initializer has fewer words than its declared length: C fills the
    missing words with zeros at the END, so every word after a dropped zero sits early in the
    pool (fn_1_84860: `fzgx_pool_table12[306]` with 304 entries after an edit to its 248-zero
    run; 25 pool rows). The table is replaced by the retail slice that equals its words with
    one zero run widened by the missing count. Only retail words are written."""
    out = []
    for t in reversed(list(_NUMBERED_TABLE.finditer(body))):
        n = int(t.group(2))
        try:
            have = [int(w.strip().rstrip('uUlL'), 0) & 0xFFFFFFFF for w in t.group(3).split(',') if w.strip()]
        except ValueError:
            continue
        missing = n - len(have)
        if missing <= 0 or len(have) < 2 or n > len(words):
            continue
        found = []
        for o in range(len(words) - n + 1):
            want = words[o:o + n]
            j = 0
            while j < len(have) and have[j] == want[j]:
                j += 1
            # the dropped words are zeros inside (or next to) a zero run of the table
            if all(w == 0 for w in want[j:j + missing]) and want[j + missing:] == have[j:] and want not in found:
                found.append(want)
                if len(found) > 1:
                    break
        if len(found) != 1:
            continue  # absent or ambiguous: no candidate rather than a guess
        want = found[0]
        rows = [', '.join(f'0x{w:08X}' for w in want[i:i + 6]) for i in range(0, n, 6)]
        text = body[:t.start()] + t.group(1) + '{\n    ' + ',\n    '.join(rows) + ',\n}' + body[t.end():]
        out.append((f'retail pool words ({name}: {t.group(0).split("[")[0].split()[-1]} declared [{n}], '
                    f'initialized with {len(have)}; {missing} zero words restored)', text))
    return out


def retail_pool_dump(p, symbol, check):
    """Every retail word of each pool the check reports as differing, four per line, offsets
    relative to the retail symbol (what the primer's `fzgx_pool_table_HEX` names count from)."""
    module = p.resolve(symbol).module
    lines = []
    for name, span in retail_pool_anchors(p, symbol, check).items():
        words = retail_words(p, module, name, span)
        if not words:
            continue
        lines.append(f'retail {name}: {len(words)} words; `fzgx_pool_table_HEX[N]` holds the words at +0xHEX')
        for i in range(0, len(words), 4):
            lines.append(f'  +0x{4 * i:03X}: ' + ' '.join(f'0x{w:08X}' for w in words[i:i + 4]))
    return lines


_PRIMER_REGION = re.compile(r'(?m)^[ \t]*#pragma section code_type "\.fzgxpool"[ \t]*\n.*?^[ \t]*#pragma section code_type "\.text"[ \t]*\n', re.S)
_CODE_TYPE = re.compile(r'(?m)^[ \t]*#pragma[ \t]+section[ \t]+code_type[ \t]+"([^"]*)"[ \t]*$')
_PRIMER_DEF = re.compile(r'(?m)^(?![ \t]*#)[^;{}\n]*?\b(\w+)[ \t]*\([^;{}]*\)[ \t]*\{')
# a function an agent wrote to prime the unit's literal pool or section layout, by name:
# `fzgx_pool_prime_N` (the landed form), `pool_primer` (fn_3_1B4BC), `fn_1_E7764_pool_5`,
# `fn_1_15EFEC_pool_signed`; anything else defined next to the target is a helper
PRIMER_NAME = re.compile(r'(?i)^fzgx_|(?:^|_)(?:pool|primer|prime|literals?)(?:_|$|\d)')
# `#pragma section` spellings that leave code in `.text` (measured on GC/1.3.2: `prime_a`
# stayed in `.text` under every one of them, so the check still listed the primers as extra
# code): the section name without `code_type`, and the `RX` flag forms. Only `code_type
# ".fzgxpool"` (reset by `code_type ".text"` or a bare `code_type`) moves functions.
_INEFFECTIVE_POOL_PRAGMA = re.compile(
    r'(?m)^[ \t]*#pragma[ \t]+section[ \t]+(?:RX[ \t]+)?"\.fzgxpool"(?:[ \t]+"\.fzgxpool")?[ \t]*$')
_INEFFECTIVE_TEXT_PRAGMA = re.compile(
    r'(?m)^[ \t]*#pragma[ \t]+section[ \t]+(?:RX[ \t]+)?"\.text"(?:[ \t]+"\.text")?[ \t]*$')


def primer_like(name: str) -> bool:
    return bool(PRIMER_NAME.search(name))


def normalize_primer_pragmas(body: str) -> str:
    """The body with every ineffective `.fzgxpool` section pragma respelled as
    `#pragma section code_type ".fzgxpool"` and, only then, its `.text` counterparts as
    `#pragma section code_type ".text"`. Unchanged when no ineffective pool pragma exists."""
    if not _INEFFECTIVE_POOL_PRAGMA.search(body):
        return body
    text = _INEFFECTIVE_POOL_PRAGMA.sub('#pragma section code_type ".fzgxpool"', body)
    return _INEFFECTIVE_TEXT_PRAGMA.sub('#pragma section code_type ".text"', text)


def stray_primer_functions(body: str, names=None) -> List[Tuple[str, int, int]]:
    """`fzgx_*` function definitions placed in `.text` (outside every `code_type ".fzgxpool"`
    region): (name, start, end) spans, `end` just past the closing brace. `names` restricts the
    search to the functions an object check reported as extra (any name then: the caller
    decides which extras are primers, `primer_like`). Such a primer is dropped by
    nothing at integration: it links as code retail does not have, the module grows and every
    hash fails (fn_1_E252C, fn_1_115560, fn_1_147508, fn_10_17814, batches codex-20261016d/e)."""
    from .sdkimport import masked
    code = masked(body)  # same offsets; the pragma's string literal is read from `body`
    sections = sorted((m.start(), m.group(1)) for m in _CODE_TYPE.finditer(body))
    out = []
    for m in _PRIMER_DEF.finditer(code):
        if names is not None:
            if m.group(1) not in names:
                continue
        elif not m.group(1).startswith('fzgx_'):
            continue
        current = '.text'
        for at, section in sections:
            if at < m.start():
                current = section
        line_start = code.rfind('\n', 0, m.start()) + 1
        if current == '.fzgxpool' or '__declspec(section ".fzgxpool")' in body[line_start:m.end()]:
            continue
        depth, i = 0, m.end() - 1
        while i < len(code):
            if code[i] == '{':
                depth += 1
            elif code[i] == '}':
                depth -= 1
                if depth == 0:
                    break
            i += 1
        else:
            return []
        out.append((m.group(1), code.rfind('\n', 0, m.start()) + 1, i + 1))
    return out


def primer_sections(body: str, names=None) -> Optional[str]:
    """The body with every stray `fzgx_*` function moved into `.fzgxpool` by a
    `#pragma section code_type` pair around each definition (the landed primer form; nothing
    else changes, so the pooled literals keep their first-use order). None when nothing moves."""
    spans = stray_primer_functions(body, names)
    if not spans:
        return None
    text = body
    for _, start, end in sorted(spans, key=lambda s: s[1], reverse=True):
        tail = text[end:]
        nl = tail.find('\n')
        cut = end + (nl + 1 if nl >= 0 else len(tail))
        text = (text[:start] + '#pragma section code_type ".fzgxpool"\n' + text[start:cut].rstrip('\n') + '\n'
                + '#pragma section code_type ".text"\n' + text[cut:])
    return text


def reset_after_primers(body: str, symbol: str, primers) -> Optional[str]:
    """The body with `#pragma section code_type ".text"` inserted after the last primer
    definition when the target itself was emitted in `.fzgxpool` (a pool region never reset:
    the oracle scores such a body 0, fn_1_E7764 spent eight checks there). None when no primer
    definition is found or a reset already follows the last one."""
    from .sdkimport import masked
    code = masked(body)
    last = None
    for m in _PRIMER_DEF.finditer(code):
        if m.group(1) == symbol or m.group(1) not in primers:
            continue
        depth, i = 0, m.end() - 1
        while i < len(code):
            if code[i] == '{':
                depth += 1
            elif code[i] == '}':
                depth -= 1
                if depth == 0:
                    break
            i += 1
        else:
            return None
        last = max(last or 0, i + 1)
    if last is None:
        return None
    nl = body.find('\n', last)
    cut = len(body) if nl < 0 else nl + 1
    following = body[cut:]
    head = re.search(r'(?m)^[^\n;{}#]*\b' + re.escape(symbol) + r'[ \t]*\([^;{}]*\)[ \t]*\{', following)
    region = following[:head.start()] if head else following
    if re.search(r'(?m)^[ \t]*#pragma[ \t]+section[ \t]+code_type\b', region):
        return None
    return body[:cut] + '#pragma section code_type ".text"\n' + following


def _fresh_primer_names(names, text: str) -> Dict[str, str]:
    """old -> `fzgx_<old>` for every name lacking the prefix, skipping tokens `text` uses."""
    out: Dict[str, str] = {}
    for name in names:
        if name.startswith('fzgx_'):
            continue
        new = 'fzgx_' + name
        while re.search(r'\b' + re.escape(new) + r'\b', text) or new in out.values():
            new += '_'
        out[name] = new
    return out


def primer_repair(body: str, extras, in_pool) -> Optional[Tuple[str, Dict[str, str], List[str]]]:
    """One mechanical repair of a matched body whose only blockers are its primers: the
    ineffective pool pragmas respelled (`normalize_primer_pragmas`), every extra function
    the object placed in `.fzgxpool` renamed `fzgx_<name>` (the oracle's primer rule needs
    the prefix as well as the section), every primer-like extra still in `.text` moved into
    `.fzgxpool` and renamed when it lacks the prefix. `extras` are the object's extra function
    symbols, `in_pool` those of them already in `.fzgxpool`. Returns (text, renames, moved),
    or None when a stray extra is not primer-like (a helper retail inlined away: the agent's
    problem, reported as before) or nothing changes. Batch 20261020: fn_3_1B4BC's
    `pool_primer`, fn_1_15EFEC's `fn_1_15EFEC_pool_*` and fn_1_E7764's `fn_1_E7764_pool_*`
    were all repaired by hand over several checks each."""
    extras = list(extras or [])
    in_pool = set(in_pool or ())
    if not extras:
        return None
    stray = [n for n in extras if n not in in_pool]
    if any(not primer_like(n) for n in stray):
        return None
    text = normalize_primer_pragmas(body)
    renames = _fresh_primer_names(extras, text)
    if renames:
        pattern = re.compile(r'\b(' + '|'.join(re.escape(n) for n in sorted(renames, key=len, reverse=True)) + r')\b')
        text = pattern.sub(lambda m: renames[m.group(1)], text)
    moved: List[str] = []
    if stray:
        current = {renames.get(n, n) for n in stray}
        moved = sorted(n for n, _, _ in stray_primer_functions(text, current))
        if moved:
            text = primer_sections(text, set(moved)) or text
    if text == body:
        return None
    return text, renames, moved
_SECTION_BASE = re.compile(r'addi (r\d+), r\d+, (\S+?)(?:\+0x[0-9A-Fa-f]+)?@l$')


def _base_registers(rows, syms, anonymous_only=False):
    """section -> callee-saved register holding its base, one side of the diff rows (retail:
    named objects of the section; ours: MWCC's anonymous `...data.0` section bases). When
    retail addresses several named objects of one section, the base is the lowest one
    (fn_3_11FF0: `lbl_3_bss_7EDC0` r27 is the `.bss` base, `lbl_3_bss_7EE40` r19 a later
    object addressed by name; the section used to be dropped as ambiguous)."""
    out = {}
    for row in rows:
        m = _SECTION_BASE.match(((row.get('instruction') or {}).get('formatted') or ''))
        if not m or int(m[1][1:]) < 14:
            continue
        anonymous = re.fullmatch(r'\.\.\.(\w+)\.\d+', m[2])
        known = syms.get(m[2])
        if anonymous_only and not anonymous:
            continue
        section = '.' + anonymous[1] if anonymous else (known.section if known and known.kind == 'object' else None)
        if section in ('.data', '.rodata', '.bss'):
            out.setdefault(section, {}).setdefault(m[1], set()).add(-1 if anonymous else known.addr)
    result = {}
    for section, regs in out.items():
        lowest = sorted((min(addrs), reg) for reg, addrs in regs.items())
        if len(lowest) == 1 or lowest[0][0] != lowest[1][0]:
            result[section] = lowest[0][1]
    return result


def _touched_sections(region, before, syms):
    """Sections of the unit-defined retail objects a primer region names (`lbl_*` symbols and
    the `fzgx_obj_`/`fzgx_pool_<section>_`/filler aliases through `fixup_sections.retail_address`,
    the lifter's `fzgx_bss_N`/`fzgx_data_N` statics by name); an extern reference counts for
    nothing (a named global's address is the function's own CSE, not a section base)."""
    from .fixup_sections import retail_address
    out = set()
    for name in sorted(set(re.findall(r'\b(?:lbl_|fzgx_)\w+', region))):
        if not re.search(r'(?m)^(?![ \t]*extern\b)[^\n;(){}]*\b%s\b\s*(?:\[[^\]\n]*\]\s*)*(?:=|;)' % re.escape(name), before):
            continue
        where = retail_address(name, syms)
        if where:
            out.add(where[1])
            continue
        m = re.match(r'fzgx_(bss|data)_[0-9A-Fa-f]+$', name)
        if m:
            out.add('.' + m[1])
    return out


def _primer_section(text, objects):
    """The one section a primer function references, or None: the sections of the defined
    objects it names, `.rodata` for a pool primer (float literals, `fzgx_pool_prime/keep/
    table` names), the engine's `fzgx_data_layout_*`/`fzgx_bss_layout` names."""
    from .sdkimport import masked
    inner = masked(text)
    kinds = {objects[n] for n in set(re.findall(r'\b[A-Za-z_]\w*\b', inner)) if n in objects}
    if _FLOAT_LITERAL.search(inner) or re.search(r'\bfzgx_pool_(?:prime|keep|table)\d', text):
        kinds.add('.rodata')
    for s in re.findall(r'\bfzgx_pool_(data|rodata)_', text):
        kinds.add('.' + s)
    if 'fzgx_bss_layout' in text:
        kinds.add('.bss')
    if 'fzgx_data_layout' in text and not kinds:
        kinds.add('.data')
    return kinds.pop() if len(kinds) == 1 else None


def _emit_primers(seq):
    """The primer items in order, wrapped in `code_type ".fzgxpool"` where they need it."""
    out = ['\n']
    open_pool = False
    for lead, text, kind, section, name, _ in seq:
        # a `__declspec(section ".fzgxpool")` primer is wrapped too: the section pragmas are
        # stripped, and MWCC rejects the declspec before a pragma has named the section
        wrap = kind == 'primer'
        if wrap and not open_pool:
            out.append('\n#pragma section code_type ".fzgxpool"\n')
            open_pool = True
        elif not wrap and open_pool:
            out.append('#pragma section code_type ".text"\n\n')
            open_pool = False
        out.append(lead.strip('\n') + ('\n' if lead.strip() else '') + text.strip('\n') + '\n')
    if open_pool:
        out.append('#pragma section code_type ".text"\n')
    return ''.join(out)


def section_base_order(p, symbol, body, check, obj=None):
    """The order of a unit's section-base registers is the order in which the translation unit
    first references each section, not where the objects are defined (measured on fn_8_7484
    and fn_8_7C4C: moving the `.data` definitions above the pool primer changed nothing; a
    `.fzgxpool` function touching three `.data` objects ahead of the pool primer gave `.data`
    retail's r31 and the pool r30, and dropping that primer from a matching body swapped them
    back). The section referenced first takes the highest callee-saved register. A body whose
    anonymous `...data.0`/`...rodata.0`/`...bss.0` bases hold each other's registers is
    reordered: every primer function (each tagged with the one section it touches, so a
    region mixing pool primers with a `.bss` order function splits, fn_3_11FF0) is re-emitted
    in retail's order just above the function, after the last definition it names, and a
    section that has defined objects but no primer gets one over them (`fzgx_base_order_<s>`:
    fn_16_2560's `static const` literals were first referenced by the function itself, so
    `.data` always came first). Measured: fn_3_11FF0 96.21 -> 96.52 with retail's
    rodata r29 / data r28 / bss r27."""
    rows = getattr(check, '_rows', None) if check is not None else None
    if not rows or not check.ok:
        return []
    sym = p.resolve(symbol)
    if sym is None:
        return []
    syms = p.symbols(sym.module)
    # only MWCC's anonymous section bases follow the TU's first reference; a named extern's
    # address is the function's own CSE (fn_4_63D4: retail's data r30 over `lbl_4_bss_0` r29)
    retail, ours = _base_registers(rows[0], syms), _base_registers(rows[1], syms, anonymous_only=True)
    shared = [s for s in retail if s in ours]
    # the ranking of the shared sections' registers is what the first-reference order sets;
    # the registers themselves also depend on the locals (fn_16_2560: retail data r28 /
    # rodata r29 under two locals, ours rodata r29 / data r30 above them)
    desired = sorted(shared, key=lambda s: -int(retail[s][1:]))
    if len(shared) < 2 or desired == sorted(shared, key=lambda s: -int(ours[s][1:])):
        return []
    from .sdkimport import masked
    from .fixup_source import _function_body_span
    code = masked(body)
    span = _function_body_span(code, sym.name)
    if not span:
        return []
    at = code.rfind('\n', 0, span[0]) + 1
    items, _tail = _section_items(body, code, at)
    objects = {it[4]: it[3] for it in items if it[2] == 'obj'}
    primers = {}
    for k, it in enumerate(items):
        if it[2] == 'primer':
            section = _primer_section(it[1], objects)
            if section is None:
                # a primer named otherwise (`fzgx_bss_order`): the section of the defined
                # objects it touches (`fzgx_obj_`/`fzgx_pool_` aliases through retail_address)
                kinds = _touched_sections(it[1], code[:at], syms)
                section = kinds.pop() if len(kinds) == 1 else None
            if section is not None:
                items[k] = (it[0], it[1], it[2], section, it[4], it[5])
                primers.setdefault(section, []).append(items[k])
    ordered, synthesized = [], []
    for s in desired:
        if primers.get(s):
            ordered.extend(primers[s])
            continue
        defined = [it for it in items if it[2] == 'obj' and it[3] == s]
        if not defined or s == '.rodata':
            # nothing of this section is defined, so its first reference cannot move; the
            # literal pool's first use is the pool primer's business (`shared_pool_primer`):
            # touching a `static const` object by address or value changed nothing on
            # fn_16_2560 (its one-word array is merged into the pool; a scalar read folds)
            return []
        tag = s.lstrip('.')
        sink = '    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: the TU references %s in retail order */\n' % s
        uses = ''.join(f'    s = *(u8 *)&{it[4]};\n' for it in defined)
        text = 'static void fzgx_base_order_%s(void) {\n%s%s}\n' % (tag, sink, uses)
        item = ('', text, 'primer', s, 'fzgx_base_order_' + tag, None)
        ordered.append(item)
        synthesized.append(s)
    # the block goes after the last definition any primer names, never above the first primer
    # (a helper between it and the function keeps its place), and never below the function
    # exact spans: an item's `start` counts its lead after section pragmas were stripped, so
    # the statement text is located in the body (items come in body order); the lead comment
    # moves with the primer only when it directly precedes it
    located, cursor = {}, 0
    for it in items:
        if it[2] not in ('obj', 'primer'):
            continue
        k = body.find(it[1], cursor)
        if k < 0:
            return []
        end = k + len(it[1])
        lead = it[0] if it[0] and body[k - len(it[0]):k] == it[0] else ''
        located[id(it)] = (k - len(lead), end)
        cursor = end
    # a section's defined objects interleaved with its primers (`fzgx_pool_table2` between
    # `fzgx_pool_prime1` and `fzgx_pool_prime3`) move with them: the pool is laid out in
    # first-use order, and the tables are used where they are defined
    for s in desired:
        own = [located[id(it)] for it in primers.get(s, ()) if id(it) in located]
        if not own:
            continue
        lo, hi = min(a for a, _ in own), max(b for _, b in own)
        for it in items:
            if it[2] == 'obj' and it[3] == s and id(it) in located and lo < located[id(it)][0] < hi:
                primers[s].append(it)
        primers[s].sort(key=lambda it: located[id(it)][0])
    ordered = [it for s in desired for it in (primers.get(s) or [o for o in ordered if o[3] == s and o[5] is None])]
    touched = {n for it in ordered for n in set(re.findall(r'\b[A-Za-z_]\w*\b', masked(it[1]))) if n in objects}
    pos = min((located[id(it)][0] for it in ordered if id(it) in located), default=at)
    for it in items:
        if it[2] == 'obj' and it[4] in touched:
            pos = max(pos, located[id(it)][1])
    pos = min(pos, at)
    spans = sorted(located[id(it)] for it in ordered if id(it) in located)
    if any(a < pos < b for a, b in spans):
        return []
    head = body[:at]
    for a, b in reversed(spans):
        if b <= pos:
            pos -= b - a
        head = head[:a] + head[b:]
    block = re.sub(r'(?m)^(?![^\n]*(?://|/\*))([^\n]*\bvolatile\b[^\n]*?)[ \t]*$',
                   r'\1  /* fzgx-allow: S2 pool primer sink */', _emit_primers(ordered))
    text = head[:pos].rstrip('\n') + '\n' + block + '\n' + head[pos:].lstrip('\n') + body[at:]
    text = re.sub(r'\n{3,}', '\n\n', text)
    if re.sub(r'\n{3,}', '\n\n', body) == text:
        return []
    order = ' before '.join(desired)
    label = f'section base order: {order} (first reference takes the highest register)'
    if synthesized:
        label += ', primer added for ' + ', '.join(synthesized)
    return [(label, text)]


_FLOAT_LITERAL = re.compile(r'(?<![\w.])(?:\d+\.\d*|\.\d+|\d+(?=[eE]))(?:[eE][+-]?\d+)?[fF]?(?![\w.])')
_SECTION_PRAGMA = re.compile(r'(?m)^[ \t]*#pragma[ \t]+section[ \t]+(?:code_type[ \t]+"[^"\n]*"|RX[ \t]+"\.fzgxpool")[^\n]*\n?')
_RX_PRAGMA = re.compile(r'(?m)^[ \t]*#pragma[ \t]+section[ \t]+RX[ \t]+"\.fzgxpool"[^\n]*\n?')
_POOL_DECLSPEC = re.compile(r'__declspec\s*\(\s*section\s*"\.fzgxpool"\s*\)')
_TRAILING_LEAD = re.compile(r'(?:(?:/\*.*?\*/|//[^\n]*)[ \t]*\n?|\s)*\Z', re.S)
_DEFINITION = re.compile(r'^(?!\s*(?:extern|typedef|struct\s+\w+\s*\{|union\s+\w+\s*\{|enum\b)\s)'
                         r'(?P<spec>[^=;()\[]*?)\b(?P<name>[A-Za-z_]\w*)\s*(?P<dims>(?:\[[^\]]*\]\s*)*)(?P<init>=.*)?;\s*$', re.S)


def _section_items(body: str, code: str, at: int):
    """The file-scope items of `body[:at]`: (lead, text, kind, section, name, start). `lead` is the
    comment/blank text an item carries; `kind` is `obj` (a defined object), `primer` (a
    `.fzgxpool` function), `helper` (another function), `decl` (anything else, including
    preprocessor lines). Section pragmas are stripped: primers are re-wrapped on emission."""
    items = []
    statements = [(a, b) for a, b in _top_statements(code) if b <= at]
    pool = False
    prev_end = 0
    for a, b in statements:
        gap = body[prev_end:a]
        # the code-type pragma in force at this statement
        for m in re.finditer(r'(?m)^[ \t]*#pragma[ \t]+section[ \t]+code_type[ \t]+"([^"\n]*)"', gap):
            pool = m[1] == '.fzgxpool'
        gap = _SECTION_PRAGMA.sub('', gap)
        lead = _TRAILING_LEAD.search(gap)
        lead_text = lead.group(0) if lead else ''
        rest = gap[:len(gap) - len(lead_text)]
        if rest.strip():
            items.append(('', rest, 'decl', None, None, prev_end))
        start = a - len(lead_text)
        text = body[a:b]
        stmt = code[a:b]
        m = re.search(r'\b(\w+)\s*\([^;{}]*\)\s*\{', stmt)
        if m and stmt.rstrip().endswith('}'):
            name = m[1]
            primer = pool or _POOL_DECLSPEC.search(stmt) or PRIMER_NAME.search(name)
            items.append((lead_text, text, 'primer' if primer else 'helper', None, name, start))
        else:
            d = _DEFINITION.match(stmt.strip())
            # `struct foo;` is a forward declaration; `struct foo bar;` defines bar
            if d and '(' not in d['spec'] and not re.fullmatch(r'\s*(?:struct|union|enum)\s*', d['spec']):
                spec = re.sub(r'^\s*static\s+', '', d['spec'].strip())
                if re.match(r'(?:const\s+)[^*]*$', spec) or re.search(r'\*\s*const\s*$', spec):
                    section = '.rodata'
                elif d['init']:
                    section = '.data'
                else:
                    section = '.bss'
                items.append((lead_text, text, 'obj', section, d['name'], start))
            else:
                items.append((lead_text, text, 'decl', None, None, start))
        prev_end = b
    tail = _SECTION_PRAGMA.sub('', body[prev_end:at])
    return items, tail


def section_group_orders(p, symbol, body, check):
    """Every order of the unit's section-object groups. Which callee-saved register each
    anonymous section base takes (`...bss.N`, `...data.N`, the `...rodata.N` pool) follows
    the source order in which the TU's first object or primer of each section is created
    (fn_1_1049E0 closed its last rows only once the pool primers stood above the `.bss`
    definitions; fn_1_331EC needed the `.bss` statics and their primer before the pool
    primers). The leading definition block of each section (its defined objects and the
    `.fzgxpool` primers that touch them, pool primers for `.rodata`) is permuted as a group,
    and within a section the primers are tried before and after the definitions. Other
    declarations are hoisted above the run, other functions stay below it; everything else
    is kept byte for byte. `section_base_order` is the single-candidate form over primer
    regions; this one also handles a mixed primer region and the definitions themselves."""
    import itertools
    from .sdkimport import masked
    from .fixup_source import _function_body_span
    sym = p.resolve(symbol)
    if sym is None:
        return []
    code = masked(body)
    span = _function_body_span(code, sym.name)
    if not span:
        return []
    at = code.rfind('\n', 0, span[0]) + 1
    items, tail = _section_items(body, code, at)
    objects = {}
    for lead, text, kind, section, name, _ in items:
        if kind == 'obj':
            objects[name] = section
    tagged = []
    for k, (lead, text, kind, section, name, start) in enumerate(items):
        if kind == 'primer':
            kinds = {objects[n] for n in set(re.findall(r'\b[A-Za-z_]\w*\b', masked(text))) if n in objects}
            if _FLOAT_LITERAL.search(masked(text)) or re.search(r'\bfzgx_pool_(?:prime|keep|table)\d', text):
                kinds.add('.rodata')
            for s in re.findall(r'\bfzgx_pool_(data|rodata)_', text):
                kinds.add('.' + s)
            if 'fzgx_bss_layout' in text:
                kinds.add('.bss')
            if 'fzgx_data_layout' in text and not kinds:
                kinds.add('.data')
            if len(kinds) == 1:
                items[k] = (lead, text, kind, kinds.pop(), name, start)
                tagged.append(k)
        elif kind == 'obj':
            tagged.append(k)
    if not tagged:
        return []
    first = tagged[0]
    sections = []
    for k in tagged:
        if items[k][3] not in sections:
            sections.append(items[k][3])
    if len(sections) < 2 or len(sections) > 4:
        return []
    fixed = [it for it in items[first:] if it[2] == 'helper' or (it[2] == 'primer' and it[3] is None)]
    hoisted = [it for it in items[first:] if it[2] == 'decl']
    # a definition initialized with a function that stays below the run cannot move above it
    below = {it[4] for it in fixed}
    for it in items[first:]:
        if it[2] == 'obj' and it[1].count('=') and below & set(re.findall(r'\b[A-Za-z_]\w*\b', masked(it[1]))):
            return []
    rx = ''.join(m.group(0) for m in _RX_PRAGMA.finditer(body[:at]))
    # the prefix is the text up to the first tagged item's lead, section pragmas stripped
    prefix = _SECTION_PRAGMA.sub('', body[:items[first][5]])
    if rx and rx not in prefix:
        prefix = prefix.rstrip('\n') + '\n\n' + rx
    prefix = prefix.rstrip('\n') + '\n'
    for it in hoisted:
        prefix += '\n' + it[0].lstrip('\n') + it[1].rstrip('\n') + '\n'

    def emit(seq):
        out = ['\n']
        open_pool = False
        for lead, text, kind, section, name, _ in seq:
            wrap = kind == 'primer'  # declspec primers too (see `_emit_primers`)
            if wrap and not open_pool:
                out.append('\n#pragma section code_type ".fzgxpool"\n')
                open_pool = True
            elif not wrap and open_pool:
                out.append('#pragma section code_type ".text"\n\n')
                open_pool = False
            out.append(lead.strip('\n') + ('\n' if lead.strip() else '') + text.strip('\n') + '\n')
        if open_pool:
            out.append('#pragma section code_type ".text"\n')
        return ''.join(out)

    def well_formed(seq):
        """No primer ahead of a defined object it names (its tables, its `.bss` objects)."""
        defined = set()
        for lead, text, kind, section, name, _ in seq:
            if kind == 'obj':
                defined.add(name)
            elif kind == 'primer':
                if any(n in objects and n not in defined for n in set(re.findall(r'\b[A-Za-z_]\w*\b', masked(text)))):
                    return False
        return True

    groups = {}
    for k in tagged:
        groups.setdefault(items[k][3], []).append(items[k])
    variants = {}
    for s, lst in groups.items():
        defs = [it for it in lst if it[2] == 'obj']
        prim = [it for it in lst if it[2] == 'primer']
        v = [('as is', lst)]
        if defs and prim:
            v += [('definitions first', defs + prim), ('primers first', prim + defs)]
        seen = set()
        variants[s] = []
        for label, seq in v:
            key = tuple(id(it) for it in seq)
            if key not in seen:
                seen.add(key)
                variants[s].append((label, seq))
    perms = list(itertools.permutations(sections))
    if len(perms) * 3 ** len(sections) > 200:
        variants = {s: v[:1] for s, v in variants.items()}
    original = [id(items[k]) for k in tagged]
    out = []
    for order in perms:
        for choice in itertools.product(*(variants[s] for s in order)):
            seq = [it for _, lst in choice for it in lst]
            if [id(it) for it in seq] == original or not well_formed(seq):
                continue
            text = prefix + emit(seq) + (emit(fixed) if fixed else '') + tail.lstrip('\n')
            if not text.endswith('\n'):
                text += '\n'
            text = re.sub(r'\n{3,}', '\n\n', text) + body[at:]
            if text == body or re.sub(r'\n{3,}', '\n\n', text) == re.sub(r'\n{3,}', '\n\n', body):
                continue
            label = ' before '.join(s.lstrip('.') for s in order) + ''.join(
                f', {s.lstrip(".")} {l}' for s, (l, _) in zip(order, choice) if l != 'as is')
            out.append((f'section group order: {label}', text))
    return out


def string_run(p, symbol, text, cast=''):
    sym = p.resolve(symbol)
    syms = p.symbols(sym.module)
    first = next((syms[l] for l in re.findall(r"\b(lbl_\d+_data_[0-9A-F]+|lbl_[0-9A-F]{8})\b", text) if syms.get(l) and syms[l].section == '.data'), None)
    sb = section_bytes(p, sym.module, '.data', first.addr if first else None)
    if sb is None:
        return None, ['no raw .data for this module']
    base_addr, raw = sb
    notes = []
    out = text
    uses = {}  # (addr) -> list of (span, replacement builder)
    # byte-pointer models: P = (u8 *)&LBL; ... ((u8 *)(u32)P + N) / (P + N) / P
    for m in re.finditer(r"(\w+)\s*=\s*\(u8 \*\)\s*&(lbl_\d+_data_[0-9A-F]+|lbl_[0-9A-F]{8})\s*;", out):
        pvar, lbl = m.group(1), m.group(2)
        out = out.replace(m.group(0), '')
        out = re.sub(r"\n[ \t]*u8\s*\*\s*%s\s*;" % re.escape(pvar), '', out)
        out = re.sub(r"\(u8 \*\)\s*\(u32\)\s*%s\s*\+\s*(0x[0-9A-Fa-f]+|\d+)" % re.escape(pvar), lambda mm: f"{lbl} + {int(mm.group(1), 0)}", out)
        out = re.sub(r"\b%s\s*\+\s*(0x[0-9A-Fa-f]+|\d+)" % re.escape(pvar), lambda mm: f"{lbl} + {int(mm.group(1), 0)}", out)
        out = re.sub(r"\b%s\b" % re.escape(pvar), lbl, out)
    addrs = {}
    # a label declared as an aggregate (`extern PhysStrings lbl;`) and used without a byte
    # cast is a struct pointer (`PhysStrings *str = &lbl;`): a literal there does not compile
    # (fn_1_E9CFC, fn_1_EF5E0, fn_1_EEB44), so only char-typed contexts become literals
    declared = {}
    for dm in re.finditer(r"\bextern\s+(?:const\s+)?(?:struct\s+)?(\w+)\s+(lbl_\d+_data_[0-9A-F]+|lbl_[0-9A-F]{8})\b", text + include_text()):
        declared.setdefault(dm.group(2), dm.group(1))
    def repl_use(mm):
        lbl, off = mm.group(1), int(mm.group(2) or '0', 0)
        s = syms.get(lbl)
        if s is None or s.section != '.data':
            return mm.group(0)
        if not mm.group(0).lstrip().startswith('(') and declared.get(lbl, 'u8') not in SCALAR:
            return mm.group(0)
        a = s.addr + off
        st = string_at(raw, a - base_addr)
        if st is None or (a - 1 - base_addr >= 0 and raw[a - 1 - base_addr] != 0 and a != s.addr):
            addrs[a] = None
            return mm.group(0)
        addrs[a] = st[0]
        return c_literal(st[0])
    pat = re.compile(r"(?:\((?:const )?(?:char|u8|void) \*\)\s*)?&?\b(lbl_\d+_data_[0-9A-F]+|lbl_[0-9A-F]{8})\b(?:\s*\+\s*(0x[0-9A-Fa-f]+|\d+))?(?!\s*\[|\s*\.|\w)")
    fm0 = re.search(r"\n[^\n;{}]*\b%s\s*\([^;{}]*\)\s*\{" % re.escape(sym.name), out)
    if not fm0:
        return None, ['function definition not found']
    head, tail = out[:fm0.start()], out[fm0.start():]
    # string literals are `char[]`: uses typed as u8/void pointers keep an explicit cast
    def repl_use2(mm):
        r = repl_use(mm)
        if r.startswith('"') and mm.group(0).lstrip().startswith('('):
            return mm.group(0)[:mm.group(0).index(')') + 1] + r
        if r.startswith('"') and cast:
            return cast + r
        return r
    out = head + pat.sub(repl_use2, tail)
    if not addrs:
        return None, ['no string references']
    if any(v is None for v in addrs.values()):
        return None, [f'non-string reference at {a:#x}' for a, v in addrs.items() if v is None][:3]
    lo, hi = min(addrs), max(addrs)
    # retail addresses the strings off the TU's first .data object: when that object starts
    # before the string run, the unit reproduces the bytes in between as a private pad
    pad = ''
    bases = [syms[l] for l in set(re.findall(r"\b(lbl_\d+_data_[0-9A-F]+|lbl_[0-9A-F]{8})\b", text)) if syms.get(l) and syms[l].section == '.data' and syms[l].addr < lo]
    if bases:
        b0 = min(bases, key=lambda s: s.addr)
        # mwcc parses initializers slowly: a 16 KB byte list held a whole compile chunk for
        # 10 s, so the pad is capped and written as words
        if lo - b0.addr > 0x2000 or (lo - b0.addr) % 4 or b0.addr % 4:
            return None, [f'pad from {b0.name} to the string run is {lo - b0.addr:#x} bytes']
        pb = raw[b0.addr - base_addr:lo - base_addr]
        words = [int.from_bytes(pb[i:i + 4], 'big') for i in range(0, len(pb), 4)]
        lines = [allow_address_words("    " + ", ".join(f"0x{w:08X}" for w in words[i:i + 8]) + ",") for i in range(0, len(words), 8)]
        pad = f"static u32 fzgx_data_{b0.name}[{len(words):#x}] = {{  /* fzgx-allow: A1 retail data bytes: the TU's .data objects before its string literals; dropped at integration */\n" + "\n".join(lines) + "\n};\n\n"
    run, a = [], lo
    while a <= hi:
        st = string_at(raw, a - base_addr)
        if st is None:
            return None, [f'string run broken at {a:#x}']
        run.append(st[0])
        a += st[1]
    for lbl in set(re.findall(r"\b(lbl_\d+_data_[0-9A-F]+|lbl_[0-9A-F]{8})\b", text)):
        still_used = re.search(r"\b%s\b" % re.escape(lbl), re.sub(r"(?m)^[^\n]*\bextern\b[^\n;]*;", '', out))
        if syms.get(lbl) and lo <= syms[lbl].addr <= hi and not still_used:
            out = re.sub(r"\n[^\n]*\bextern\b[^\n;]*\b%s\b[^\n;]*;" % re.escape(lbl), '', out)
    if not re.search(r"\bOSReport\s*\(", out.split('{')[0]) and 'extern void OSReport' not in out:
        decl = "extern void OSReport(const char *, ...);\n"
    else:
        decl = ''
    prim = '#pragma section code_type ".fzgxpool"\nstatic void fzgx_string_layout(void) {\n    /* fzgx-allow: S2 layout primer: MWCC emits string literals in first-use order; the section is dropped at integration */\n'
    prim += "".join(f"    OSReport({c_literal(s)});\n" for s in run)
    prim += '}\n#pragma section code_type ".text"\n\n'
    fm = re.search(r"\n[^\n;{}]*\b%s\s*\([^;{}]*\)\s*\{" % re.escape(sym.name), out)
    if not fm:
        return None, ['function definition not found']
    out = out[:fm.start() + 1] + decl + pad + prim + out[fm.start() + 1:]
    notes.append(f'{len(addrs)} string uses, run of {len(run)} literals from {lo:#x}')
    return out, notes


def _diff_rows_unused(r):
    rows = r._rows if r._rows else ([], [])
    return sum(1 for l, rr in zip(*rows) if (l.get('diff_kind') or 'DIFF_NONE') != 'DIFF_NONE' or (rr.get('diff_kind') or 'DIFF_NONE') != 'DIFF_NONE')



_PTR_CAST = r"\(\s*(?:const\s+)?(?:struct\s+)?(\w+)\s*\*\s*\)"


def _balanced(s):
    depth = 0
    for c in s:
        depth += {'(': 1, ')': -1}.get(c, 0)
        if depth < 0:
            return False
    return depth == 0


def _strip_outer(s):
    """Outer pointer casts and redundant parentheses of an initializer: (cast) and the cast type."""
    s, casts = s.strip(), []
    while True:
        m = re.match(_PTR_CAST + r"\s*(.*)$", s, re.S)
        rest = m.group(2).strip() if m else ''
        # only a cast over a whole parenthesized operand: `(u8 *)p + i * K` keeps its byte cast
        if m and rest.startswith('(') and rest.endswith(')') and _balanced(rest[1:-1]):
            casts.append(m.group(1)); s = m.group(2).strip(); continue
        if s.startswith('(') and s.endswith(')') and _balanced(s[1:-1]):
            s = s[1:-1].strip(); continue
        return s, casts


def _index_operand(s):
    """A side-effect-free index: one identifier/number or a fully parenthesized arithmetic group."""
    s = s.strip()
    if re.fullmatch(r"\w+", s):
        return s
    if s.startswith('(') and s.endswith(')') and _balanced(s[1:-1]) and re.fullmatch(r"[\w\s+\-*()]+", s) \
            and not re.search(r"\w\s*\(", s) and '++' not in s and '--' not in s:
        return s
    return None


def indexed_element_arrays(p, symbol, body):
    """Retail indexes a TU-defined array of element structs (`tbl[i].f`): MWCC keeps the
    array's address and the scaled index in separate registers (`addi rB, rB, tbl@l;
    mulli rI, i, K; lwzx rX, rB, rI`, `add` + displacement only for non-zero fields, or one
    `addi` per array before indexed accesses). Every pointer spelling of the same access,
    `(u8 *)&sym + i * K` or `(T *)&sym + i`, folds into `add rP, rB, rI` plus displacements,
    and so does a cast over a defined array (fn_1_12A734: only `tbl[idx].field` on a defined
    array of a typed element matched). Proposal: an element pointer initialised from a
    same-module .bss object plus a scaled side-effect-free index becomes direct indexing of
    a `fzgx_obj_` array definition (the oracle binds the section base to the retail symbol);
    byte views `*(T *)(e + off)` become typed fields of a generated element struct."""
    sym = p.resolve(symbol)
    if sym is None:
        return
    syms = p.symbols(sym.module)
    fm = re.search(r"\n[^\n;{}]*\b%s\s*\([^;{}]*\)\s*\{" % re.escape(sym.name), body)
    if not fm:
        return
    head, code = body[:fm.start() + 1], body[fm.start() + 1:]
    stmts = list(re.finditer(r"(?:(?<=[;{}])|(?<=\n))[ \t]*(?:(?:const\s+)?(?:struct\s+)?(\w+)\s*\*\s*)?(\w+)\s*=\s*([^;{}=][^;{}]*);", code))
    for st in stmts:
        dtype, var, rhs = st.group(1), st.group(2), st.group(3)
        inner, casts = _strip_outer(rhs)
        stride = etype = None
        m = re.fullmatch(r"\(\s*(?:u8|char|s8)\s*\*\s*\)\s*(&?\s*\w+)\s*\+\s*(.+?)\s*\*\s*(0x[0-9A-Fa-f]+|\d+)", inner, re.S)
        if m:
            base_text, idx, stride = m.group(1), m.group(2), int(m.group(3), 0)
        else:
            m = re.fullmatch(_PTR_CAST + r"\s*(&?\s*\w+)\s*\+\s*(.+)", inner, re.S) or \
                re.fullmatch(r"&\s*\(\s*" + _PTR_CAST + r"\s*(&?\s*\w+)\s*\)\s*\[(.+)\]", inner, re.S)
            if not m or m.group(1) in SCALAR:
                continue
            etype, base_text, idx = m.group(1), m.group(2), m.group(3)
        idx = _index_operand(idx)
        if idx is None or var == idx.strip('()'):
            continue
        # the pointer's base: the object itself or a local initialised once from its address
        base_var, base = None, base_text.replace(' ', '').lstrip('&')
        if not re.fullmatch(r"lbl_\d+_bss_[0-9A-F]+|lbl_[0-9A-F]{8}", base):
            bm = re.search(r"\b%s\s*=\s*(?:%s\s*)?&\s*(lbl_\d+_bss_[0-9A-F]+|lbl_[0-9A-F]{8})\s*;" % (re.escape(base), _PTR_CAST.replace('(\\w+)', '\\w+')), code[:st.start()])
            if not bm:
                continue
            base_var, base = base_text.replace(' ', ''), bm.group(1)
        obj = syms.get(base)
        if obj is None or obj.section != '.bss':
            continue
        rest = code[st.end():]
        # the index and the element pointer keep their values over the uses
        ids = set(re.findall(r"[A-Za-z_]\w*", idx))
        # (`*(s32 *)e = 0` stores through the pointer: only a bare lvalue reassigns it)
        if any(re.search(r"(?:\+\+|--)\s*%s\b|\b%s\s*(?:\+\+|--)|(?:^|[;{}(,]|\n)\s*%s\s*[-+*/|&^]?=(?!=)" % ((re.escape(n),) * 3), rest) for n in ids | {var}):
            continue
        ptype = dtype or next((c for c in casts), None)
        dm = re.search(r"(?:struct\s+)?(\w+)\s*\*\s*%s\s*;" % re.escape(var), code[:st.start()])
        if ptype is None and dm:
            ptype = dm.group(1)
        name = f'fzgx_obj_{base}'
        ref = f'{name}[{idx}]'
        typedefs, decl = [], None
        new = rest
        if etype is not None or (ptype and ptype not in SCALAR):
            etype = etype or ptype
            if etype in SCALAR:
                continue
            new = re.sub(r"\b%s\s*->\s*" % re.escape(var), ref + '.', new)
            new = re.sub(r"(?<![\w.>])%s\b" % re.escape(var), f'(&{ref})', new)
            tagged = re.search(r"struct\s+%s\b" % re.escape(etype), body) and not re.search(
                r"\}\s*%s\s*;|typedef\s+struct\s+\w+\s+%s\s*;" % (re.escape(etype), re.escape(etype)), body + include_text())
            et = ('struct ' if tagged else '') + etype
            if stride is not None:
                # a byte stride must be the element type's size: MWCC refuses the unit otherwise
                typedefs.append(f"typedef char fzgx_stride_{base}[sizeof({et}) == {stride:#x} ? 1 : -1];")
            decl = f"{et} {name}[{obj.size:#x} / sizeof({et})];"
        else:
            if stride is None or stride > obj.size:
                continue
            fields = {}
            def field(mm):
                t = mm.group(1).strip()
                size = 4 if t.endswith('*') else SCALAR.get(t)
                off = int(mm.group(2), 0) if mm.group(2) else 0
                if not size or t == 'void' or off % size or off + size > stride or fields.get(off, (t,))[0] != t:
                    raise ValueError(t)
                fields[off] = (t, size)
                return f"{ref}.f_{off:X}"
            ty = r"((?:const\s+)?\w+(?:\s*\*)*)"
            try:
                new = re.sub(r"\*\s*\(\s*%s\s*\*\s*\)\s*\(\s*%s\s*\+\s*(0x[0-9A-Fa-f]+|\d+)\s*\)" % (ty, re.escape(var)), field, new)
                new = re.sub(r"\*\s*\(\s*%s\s*\*\s*\)\s*()%s\b(?!\s*[+\[])" % (ty, re.escape(var)), field, new)
            except ValueError:
                continue
            if not fields:
                continue
            ordered = sorted(fields.items())
            if any(a + s > b for (a, (_, s)), (b, _) in zip(ordered, ordered[1:])):
                continue
            new = re.sub(r"(?<![\w.>])%s\b" % re.escape(var), f'((u8 *)&{ref})', new)
            lines, pos = [], 0
            for off, (t, size) in ordered:
                if off > pos:
                    lines.append(f"    u8 pad_{pos:X}[{off - pos:#x}];")
                lines.append(f"    {t} f_{off:X};")
                pos = off + size
            if pos < stride:
                lines.append(f"    u8 pad_{pos:X}[{stride - pos:#x}];")
            et = f"fzgx_elem_{base}"
            typedefs.append(f"typedef struct {et} {{\n" + "\n".join(lines) + f"\n}} {et};")
            typedefs.append(f"typedef char fzgx_stride_{base}[sizeof({et}) == {stride:#x} ? 1 : -1];")
            decl = f"{et} {name}[{obj.size // stride:#x}];"
        before = code[:st.start()]
        if dtype is None:
            # a separate `T *var;` declaration loses its only definition
            before = re.sub(r"\n[ \t]*(?:const\s+)?(?:struct\s+)?\w+\s*\*\s*%s\s*;[ \t]*(?=\n)" % re.escape(var), '', before)
        out = before + new
        if base_var and not re.search(r"(?<![\w.>])%s\b" % re.escape(base_var),
                                      re.sub(r"[^;{}\n]*\b%s\s*=[^;]*;" % re.escape(base_var), '', out)):
            out = re.sub(r"\n[ \t]*(?:(?:const\s+)?(?:struct\s+)?\w+\s*\*\s*)?%s\s*=[^;]*;" % re.escape(base_var), '', out)
            out = re.sub(r"\n[ \t]*(?:const\s+)?(?:struct\s+)?\w+\s*\*\s*%s\s*;" % re.escape(base_var), '', out)
        block = "\n".join(typedefs) + "\n/* the retail TU defines this array: MWCC indexes it off its own address */\n" + decl + "\n\n"
        yield (f'define indexed element array {base}[{idx}]', head + block + out)


_ROW_INDEX = r"(?:\w+(?:(?:\.|->)\w+)*|\([^()]*\))"
_ROW_VIEW = re.compile(
    r"(?<=[(,=;{?:\s])(?P<base>\(\s*\(\s*(?:const\s+)?u8\s*\*\s*\)\s*(?P<o1>fzgx_(?:pool|obj)_\w+)\s*\)"
    r"|\(\s*(?:const\s+)?u8\s*\*\s*\)\s*(?P<o2>fzgx_(?:pool|obj)_\w+))"
    r"\s*\+\s*(?:\(\s*(?P<i1>%s)\s*\*\s*(?P<k1>0x[0-9A-Fa-f]+|\d+)\s*(?:\+\s*(?P<c1>0x[0-9A-Fa-f]+|\d+)\s*)?\)"
    r"|(?P<i2>%s)\s*\*\s*(?P<k2>0x[0-9A-Fa-f]+|\d+)\b(?!\s*[\[(.*/%%]))" % (_ROW_INDEX, _ROW_INDEX))


def row_array_views(text):
    """A row of a TU-defined object addressed as bytes, `(u8 *)obj + (i * K + c)`, as row-array
    indexing `((u8 (*)[K])obj)[i] + c`.

    Probe compiles under GC/1.3.2 (2026-10-11): byte arithmetic folds the object's section base
    straight into the sum (`mulli; addi rI, rI, c; add rI, rI, rBase`), while indexing an
    array view materializes the object's address first (`addi r0, rBase, off; mulli; addi;
    add rI, r0, rI`), the retail shape of fn_1_1018BC's 0x104-byte rows off lbl_1_data_3EFB8.
    Loads through either spelling compile identically, so only address values change."""
    def sub(m):
        lead = text[:m.start()].rstrip()
        if lead and lead[-1] not in '(,=;{?:' and not lead.endswith('return'):
            return m.group(0)
        obj = m['o1'] or m['o2']
        idx, k, c = (m['i1'], m['k1'], m['c1']) if m['i1'] else (m['i2'], m['k2'], None)
        row = f"((u8 (*)[{k}]){obj})[{idx}]"
        return f"({row} + {c})" if c else f"({row})"
    out = _ROW_VIEW.sub(sub, text)
    return out if out != text else None


def tu_section_layout(p, symbol, body, check):
    """Proposals: retail BSS objects defined in the unit (per dtk symbol / per referenced field),
    each also with the TU's string run reproduced, and the string run alone."""
    if not re.search(r"\blbl_(?:\d+_(?:bss|data|rodata)_[0-9A-F]+|[0-9A-F]{8})\b|\bfzgx_(?:pool|obj)_\w+", body):
        return []
    out = []
    cache = {}
    bases = []
    retail_bases = set()
    rows = check._rows if check is not None and check._rows else ([], [])
    for r in rows[0]:
        m = re.match(r"addi r\d+, r\d+, (lbl_\w+)@l$", (r.get('instruction') or {}).get('formatted') or '')
        if m:
            retail_bases.add(m.group(1))
    syms = p.symbols(p.resolve(symbol).module)
    same_module = sorted({m[2] for m in find_models(body) if syms.get(m[2]) and syms[m[2]].section == '.bss'})
    # several models: the joint layout plus each model alone (at most four), so a model whose
    # layout regresses the body cannot hide another's gain
    selections = [None] + ([{b} for b in same_module[:4]] if len(same_module) > 1 else [])
    for only in selections:
        for mode in ('dtk', 'split', 'merge'):
            try:
                text, notes = tu_objects(p, symbol, body, mode, cache, retail_bases, only)
            except (ValueError, KeyError, IndexError, AttributeError, OSError):
                text = None
            if text and text not in {t for _, t in out}:
                label = mode if only is None else f'{mode}, {next(iter(only))} only'
                out.append((f'define retail TU bss objects ({label})', text))
                if only is None and mode != 'merge':
                    bases.append((mode, text))
            # the same layout defined ahead of the unit's initialized data (section base order)
            try:
                text, notes = tu_objects(p, symbol, body, mode, cache, retail_bases, only, early=True)
            except (ValueError, KeyError, IndexError, AttributeError, OSError):
                text = None
            if text and text not in {t for _, t in out}:
                label = mode if only is None else f'{mode}, {next(iter(only))} only'
                out.append((f'define retail TU bss objects ({label}, before the TU data)', text))
    # byte-pointer locals off one object (`base = (u8 *)&lbl; hi = base + 0x50000`) as byte
    # arithmetic on the object, which the bare model lays out (fn_10_4790: 84.9% -> 100%)
    try:
        flat = flatten_byte_views(p, symbol, body)
    except (ValueError, KeyError, IndexError, AttributeError, OSError):
        flat = None
    if flat:
        # the flattened object alone too: a body that also models another TU's cluster
        # (fn_1_B8EDC's lbl_1_bss_9F8, addressed by name in retail) put both clusters in one
        # .bss and shifted every flattened offset by the other's size
        flat_models = sorted({m[2] for m in find_models(flat) if syms.get(m[2]) and syms[m[2]].section == '.bss'})
        for only in [None] + ([{b} for b in flat_models[:4]] if len(flat_models) > 1 else []):
            tag = '' if only is None else f', {next(iter(only))} only'
            for mode in ('dtk', 'split', 'merge'):
                try:
                    text, notes = tu_objects(p, symbol, flat, mode, cache, retail_bases, only)
                except (ValueError, KeyError, IndexError, AttributeError, OSError):
                    text = None
                if text and text not in {t for _, t in out}:
                    out.append((f'define retail TU bss objects ({mode}, flattened byte views{tag})', text))
                try:
                    text, notes = tu_objects(p, symbol, flat, mode, cache, retail_bases, only, early=True)
                except (ValueError, KeyError, IndexError, AttributeError, OSError):
                    text = None
                if text and text not in {t for _, t in out}:
                    out.append((f'define retail TU bss objects ({mode}, flattened byte views, before the TU data{tag})', text))
    # views derived from a model at a constant offset, as models of the retail object holding
    # them (fn_3_381C: 80.7% -> pool match); an addition, the plain layouts above stay
    for mode in ('dtk', 'split', 'merge'):
        try:
            text, notes = tu_objects(p, symbol, body, mode, cache, retail_bases, derive=True)
        except (ValueError, KeyError, IndexError, AttributeError, OSError):
            text = None
        if text and text not in {t for _, t in out}:
            out.append((f'define retail TU bss objects ({mode}, derived views)', text))
    try:
        rows_body = constant_rows(body)
    except (ValueError, KeyError, IndexError, AttributeError):
        rows_body = None
    if rows_body:
        for mode in ('split', 'merge'):
            try:
                text, notes = tu_objects(p, symbol, rows_body, mode, cache, retail_bases)
            except (ValueError, KeyError, IndexError, AttributeError, OSError):
                text = None
            if text and text not in {t for _, t in out}:
                out.append((f'define retail TU bss objects ({mode}, one object per constant row)', text))
    # `.data` struct models (fn_1_854D4, fn_1_107F74, fn_1_9A7BC) as byte views, beside the
    # bss layouts and alone
    viewed = []
    for name, base in bases + [('body', body)]:
        try:
            text, notes = data_struct_views(p, symbol, base)
        except (ValueError, KeyError, IndexError, AttributeError, TypeError, OSError):
            text = None
        if text:
            viewed.append((name + ', data struct views', text))
    for name, base in bases + [('body', body)] + viewed:
        for top in (False, True):
            try:
                text, notes = tu_data_objects(p, symbol, base, top)
            except (ValueError, KeyError, IndexError, AttributeError, TypeError, OSError):
                text = None
            if text:
                out.append((f'define retail TU data objects ({name}, {"file start" if top else "before the function"})', text))
        for cast in ('', '(u8 *)'):
            try:
                text, notes = string_run(p, symbol, base, cast)
            except (ValueError, KeyError, IndexError, AttributeError, OSError):
                text = None
            if text:
                out.append((f'reproduce retail string run ({name}{", cast" if cast else ""})', text))
    try:
        out += [c for c in indexed_element_arrays(p, symbol, body) if c[1] not in {t for _, t in out}]
    except (ValueError, KeyError, IndexError, AttributeError, OSError):
        pass
    # rows of TU-defined objects, in the body as saved (an earlier layout) and in every layout
    rows = []
    for label, text in [('index TU object rows as arrays', body)] + [(l + ', rows as arrays', t) for l, t in out]:
        viewed = row_array_views(text)
        if viewed and viewed not in {t for _, t in out + rows}:
            rows.append((label, viewed))
    out += rows
    # the defined section groups in every order (base registers follow definition order),
    # for the body as saved and for each whole-TU layout above
    seen = {t for _, t in out}
    reorder = [('body', body)] + [(l, t) for l, t in out if l.startswith('define retail TU data objects')
                                  or re.fullmatch(r'define retail TU bss objects \((?:dtk|split|merge)\)', l)]
    for label, text in reorder:
        try:
            orders = section_group_orders(p, symbol, text, check)
        except (ValueError, KeyError, IndexError, AttributeError, TypeError, OSError):
            orders = []
        for name, t in orders:
            if t not in seen:
                seen.add(t)
                out.append((f'{name} ({label})', t))
    # a section layout changes what the base register holds; a file-scope
    # `opt_propagation off` written for the old extern view can then rematerialize
    # `addis rX, rBase, N` at every far access (fn_1_2FAA0): offer each layout without it
    pragma = re.compile(r"(?m)^[ \t]*#\s*pragma\s+opt_propagation\s+(?:off|reset)[ \t]*\n")
    out += [(label + ' without opt_propagation pragma', pragma.sub('', text))
            for label, text in list(out) if label.startswith('define retail') and pragma.search(text)]
    return out
