"""One truth per symbol for a TU file.

A block matched under whatever declarations it wrote; blocks disagree, and a single-TU
compile rejects the second spelling of any symbol. The truth of a function is its matched
definition (its own code proves the parameter types), else a header, else the prologue, else
the most common spelling. A block that declared other parameter types keeps its code by
casting each argument to the type it relied on (`fn((u8)x, y, (u8)z)`): the conversion the
old prototype implied is now explicit. Every rewritten block is re-verified under the new
prologue; a block that no longer matches is reverted and reported.

`run` is the command's entry point. The search result is stored under
`.fzgx/tutruth/<tu>.json`, keyed by hashes of everything the result depends on (`input_hashes`),
and reused while every hash still agrees; any disagreement forces a new search and the report
names the inputs that changed. An apply never trusts the stored verdicts: every block of the
exact text about to be written is compiled and diffed again (`apply_result`), and the inputs are
compared once more immediately before the write.
"""
from __future__ import annotations

import hashlib
import json
import re
import time
from pathlib import Path
from collections import Counter, OrderedDict
from typing import Dict, List, Optional, Tuple

from . import oracle, reconcile, tufile, tutidy
from .project import ROOT, STATE_DIR, Project

SCALAR = {'void', 'int', 'char', 'short', 'long', 'unsigned', 'signed', 'float', 'double',
          's8', 'u8', 's16', 'u16', 's32', 'u32', 's64', 'u64', 'f32', 'f64', 'BOOL', 'size_t'}
# parameter lists may hold function-pointer parameters: two levels of nested parentheses
PROTO_RE = re.compile(r'^\s*(?:extern\s+)?(.*?)\b([A-Za-z_]\w*)\s*\(((?:[^()]|\((?:[^()]|\([^()]*\))*\))*)\)\s*(?:,|;)')
QUALIFIERS = {'const', 'volatile', 'register'}
# a typedef name may carry array dimensions (`} Sig_parse_format___va_list[1];`, MWCC's va_list)
ARR = r'(?:\s*\[[^\]]*\])*'
TYPE_TAIL_RE = re.compile(r'\}\s*([A-Za-z_]\w*)' + ARR + r'\s*;', re.M)
ALIAS_RE_TEXT = r'^typedef\s+(?!struct\b|union\b|enum\b)[^;{}()\[\]]*?\b([A-Za-z_]\w*)' + ARR + r'\s*;'


def split_params(inner: str) -> List[str]:
    """Top-level comma-separated parts of a parameter list (commas inside a function-pointer
    parameter's own list stay in it)."""
    parts, depth, start = [], 0, 0
    for i, c in enumerate(inner):
        if c in '([':
            depth += 1
        elif c in ')]':
            depth -= 1
        elif c == ',' and depth == 0:
            parts.append(inner[start:i])
            start = i + 1
    parts.append(inner[start:])
    return [x.strip() for x in parts]


def param_type(part: str) -> str:
    """The type of one parameter declaration, its name dropped: `CurveKey *keys` ->
    `CurveKey *`, `CurveKey` and `const T *` stay, `void (*cb)(s32)` -> `void (*)(s32)`,
    `u8 a[4]` -> `u8 *`."""
    part = re.sub(r'\s+', ' ', part.strip())
    if part in ('', '...'):
        return part
    fp = re.match(r'^(.*?)\(\s*\*\s*(?:[A-Za-z_]\w*)?\s*\)\s*(\(.*\))\s*$', part)
    if fp:
        return f'{fp.group(1).strip()} (*){fp.group(2)}'
    decayed = False
    dims = re.search(r'(?:\s*\[[^\]]*\])+\s*$', part)
    if dims:
        part, decayed = part[:dims.start()].rstrip(), True
    m = re.search(r'\b([A-Za-z_]\w*)\s*$', part)
    if m and m.group(1) not in SCALAR and m.group(1) not in QUALIFIERS:
        # a trailing identifier is the name only when what precedes it is a whole type
        # (not empty, not only qualifiers, not a bare `struct`/`union`/`enum` keyword)
        head = part[:m.start()].strip()
        core = ' '.join(w for w in re.findall(r'[A-Za-z_]\w*|\*', head) if w not in QUALIFIERS)
        if core and core not in ('struct', 'union', 'enum'):
            part = head
    return part + (' *' if decayed else '')


def _sig(decl: str) -> Optional[Tuple[str, str, List[str]]]:
    """(return type, name, [parameter types]) of a prototype line, or None for data."""
    if tutidy.FNPTR_OBJECT_RE.match(decl):
        return None  # a function-pointer object (`void (*tbl[0x45])(void *);`) is data
    m = PROTO_RE.match(decl.strip())
    if not m:
        return None
    ret = re.sub(r'\s+', ' ', m.group(1)).strip()
    params = []
    inner = m.group(3).strip()
    if inner and inner != 'void':
        params = [param_type(part) for part in split_params(inner)]
    return ret, m.group(2), params


def _same(a: str, b: str) -> bool:
    n = lambda s: re.sub(r'\s+', '', s).replace('int', 's32').replace('const', '')
    return n(a) == n(b)


# a definition's head: the type and name on one line (the old per-symbol pattern let `[\w\s\*]*?`
# cross newlines and backtrack across 20,000-line files), parameters and the brace may wrap
DEF_HEAD_RE = re.compile(r'^((?:[A-Za-z_][\w \t\*]*?)\b([A-Za-z_]\w*)\s*\(([^;{}()]*)\))\s*\{', re.M)
_NOT_DEFINITIONS = {'if', 'else', 'while', 'for', 'switch', 'do', 'return', 'sizeof'}
_DEF_INDEX: Dict[str, Tuple[int, int, Dict[str, str]]] = {}  # path -> (mtime_ns, size, {name: decl})


def definition_index(p: Project) -> Dict[str, str]:
    """`extern <signature>;` of every function the project's sources define, first file in
    sorted order winning, parsed once per file and re-read only when the file changed
    (tutruth asked `project_definition` 37 times on avline.c and each call re-read ~3,000
    files: 65% of its runtime; car.c and memcard.c never finished)."""
    merged: Dict[str, str] = {}
    for f in sorted((ROOT / 'src').rglob('*.c')):
        st = f.stat()
        key = str(f)
        hit = _DEF_INDEX.get(key)
        if hit is None or hit[0] != st.st_mtime_ns or hit[1] != st.st_size:
            defs: Dict[str, str] = {}
            for m in DEF_HEAD_RE.finditer(f.read_text()):
                name = m.group(2)
                if name in _NOT_DEFINITIONS or name in defs:
                    continue
                defs[name] = 'extern ' + re.sub(r'\s+', ' ', m.group(1)).strip() + ';'
            hit = (st.st_mtime_ns, st.st_size, defs)
            _DEF_INDEX[key] = hit
        for n, d in hit[2].items():
            merged.setdefault(n, d)
    return merged


def project_definition(p: Project, name: str) -> Optional[str]:
    """`extern <signature>;` of the project's matched definition of `name`, if any."""
    return definition_index(p).get(name)


def _decl_key(ln: str) -> Tuple:
    """What the compiler compares two declarations of one symbol by: a prototype's return and
    parameter types (parameter names are free), a data declaration's text."""
    sig = _sig(ln)
    if sig:
        norm = lambda s: re.sub(r'\s+', '', s)
        return ('F', norm(sig[0]), tuple(norm(t) for t in sig[2]))
    return ('D', re.sub(r'\s+', ' ', ln).strip())


def include_conflicts(prologue: str, includes: List[str]) -> Tuple[List[str], Dict[str, List[Tuple[str, str, str]]]]:
    """Split the block includes to promote into (compatible, {include: [(symbol, prologue
    declaration, header declaration)]}). A header whose declarations contradict one the
    prologue's headers (or an earlier promoted header) already make is not promoted: stcoli's
    prologue has stcoli_types.h (`extern struct fn_1_2B478_lbl_801A6D00 lbl_801A6D00;`) and one
    self-contained block included camera_types.h (`extern Transform *lbl_801A6D00;`); promoting
    it broke the prologue for all 121 blocks (librarian 19)."""
    have: Dict[str, Tuple[Tuple, str]] = {}
    seen_headers: set = set()
    for h in tutidy.included_headers(prologue):
        seen_headers.add(h.rel)
        for n, ln in h.decls:
            have.setdefault(n, (_decl_key(ln), ln))
    ok: List[str] = []
    conflicts: Dict[str, List[Tuple[str, str, str]]] = {}
    for inc in includes:
        new_headers = [h for h in tutidy.included_headers(inc) if h.rel not in seen_headers]
        bad = []
        for h in new_headers:
            for n, ln in h.decls:
                if n in have and have[n][0] != _decl_key(ln):
                    bad.append((n, have[n][1], ln))
        if bad:
            conflicts[inc] = bad
            continue
        ok.append(inc)
        for h in new_headers:
            seen_headers.add(h.rel)
            for n, ln in h.decls:
                have.setdefault(n, (_decl_key(ln), ln))
    return ok, conflicts


def split_args(text: str, start: int) -> Optional[Tuple[List[Tuple[int, int]], int]]:
    """Top-level argument spans of the call whose '(' is at `start`; returns (spans, end)."""
    depth = 0
    spans = []
    a = start + 1
    i = start
    while i < len(text):
        c = text[i]
        if c in '([{':
            depth += 1
        elif c in ')]}':
            depth -= 1
            if depth == 0:
                if text[a:i].strip():
                    spans.append((a, i))
                return spans, i
        elif c == ',' and depth == 1:
            spans.append((a, i))
            a = i + 1
        elif c == '"':
            i += 1
            while i < len(text) and text[i] != '"':
                i += 2 if text[i] == '\\' else 1
        i += 1
    return None


class Unmodelled(ValueError):
    """A signature the call-site rewrites cannot model: the block keeps its own form."""


INTS = {'s8', 'u8', 's16', 'u16', 's32', 'u32', 'int', 'char', 'short', 'long', 'unsigned', 'signed', 'BOOL', 'size_t'}


def cast_calls(body: str, name: str, old: List[str], new: List[str], force: bool = False,
               variadic: bool = False) -> str:
    """Wrap every argument whose old declared type differs from the truth's in a cast to the
    old type, so the conversion the block's prototype implied stays in the code. A parameter
    type it cannot model (empty) raises `Unmodelled`: `resolve` reports the block and keeps
    its own form."""
    if any(not t.strip() for t in list(old) + list(new)):
        raise Unmodelled(f'{name}: parameter types {old} -> {new}')
    out = body
    for m in reversed(list(re.finditer(r'\b' + re.escape(name) + r'\s*\(', body))):
        line_start = body.rfind('\n', 0, m.start()) + 1
        line_end = body.find('\n', m.start())
        if tutidy.DECL_LINE_RE.match(body[line_start:line_end if line_end >= 0 else len(body)]):
            continue  # a declaration, not a call
        res = split_args(body, m.end() - 1)
        if not res:
            continue
        spans, end = res
        if body[end + 1:].lstrip().startswith('{'):
            continue  # the definition
        if variadic:
            # only the fixed parameters of a variadic truth have declared types
            if len(old) != len(new) or len(spans) < len(old):
                continue
        elif len(spans) != len(old) or len(old) != len(new):
            continue
        text = out
        for (a, b), t_old, t_new in reversed(list(zip(spans[:len(old)], old, new))):
            if t_old == '...' or t_new == '...' or _same(t_old, t_new):
                continue
            if not force and t_old.split()[-1] in INTS and t_new.split()[-1] in INTS:
                continue  # integer widening/sign at the call is the parameter's own conversion
            arg = text[a:b].strip()
            castable = '*' in t_old or t_old.split()[-1] in SCALAR
            if not castable:
                if t_new.split()[-1] in SCALAR and '*' not in t_new:
                    text = text[:a] + f' ({t_new})({arg})' + text[b:]
                continue
            if re.fullmatch(r'\(\s*' + re.escape(t_old) + r'\s*\)\s*.*', arg):
                if '*' in t_new or (t_new.split()[-1] in SCALAR and '*' in t_old):
                    text = text[:a] + f' ({t_new})({arg})' + text[b:]  # already cast to the old type
                continue
            if '*' in t_new or (t_new.split()[-1] in SCALAR and '*' in t_old):
                text = text[:a] + f' ({t_new})({t_old})({arg})' + text[b:]  # the truth's type outermost
            else:
                text = text[:a] + f' ({t_old})({arg})' + text[b:]
        out = text
    return out


def join_declarations(body: str) -> str:
    """A declaration continued over several lines becomes one line."""
    out = []
    buf = None
    for ln in body.splitlines():
        if buf is not None:
            buf += ' ' + ln.strip()
            if ln.rstrip().endswith(';'):
                out.append(buf)
                buf = None
            continue
        if re.match(r'^\s*(?:extern\s+)?[A-Za-z_][\w \*]*\b[A-Za-z_]\w*\s*\([^;{}]*,\s*$', ln) or (re.match(r'^\s*extern\b[^;{}]*$', ln) and not ln.rstrip().endswith(';')):
            buf = ln.rstrip()
            continue
        out.append(ln)
    if buf is not None:
        out.append(buf)
    return '\n'.join(out) + ('\n' if body.endswith('\n') else '')


def split_multi(body: str) -> str:
    """`extern void a(...), b(...);` becomes one declaration line per prototype."""
    out = []
    for ln in body.splitlines():
        m = re.match(r'^(\s*(?:extern\s+)?[A-Za-z_][^(;=]*?)\b([A-Za-z_]\w*)\s*\(([^()]*)\)\s*,\s*(.*);\s*$', ln)
        if m and re.search(r'\b[A-Za-z_]\w*\s*\([^()]*\)', m.group(4)):
            head = m.group(1)
            protos = re.findall(r'(\**\s*[A-Za-z_]\w*\s*\([^()]*\))', m.group(2) + '(' + m.group(3) + '), ' + m.group(4))
            for pr in protos:
                out.append(f'{head.rstrip()} {pr.strip()};')
            continue
        out.append(ln)
    return '\n'.join(out) + ('\n' if body.endswith('\n') else '')


def private_type_names(body: str) -> set:
    """Names of the types a block defines: struct/union typedefs and tags, function-pointer
    typedefs and plain aliases."""
    names = set(TYPE_TAIL_RE.findall(body))
    names |= set(re.findall(r'^(?:typedef\s+)?(?:struct|union)\s+([A-Za-z_]\w*)\s*\{', body, re.M))
    names |= set(re.findall(r'^typedef\s+[^;{}]*?\(\s*\*\s*([A-Za-z_]\w*)\s*\)\s*\([^;]*\)\s*;', body, re.M))
    names |= set(re.findall(ALIAS_RE_TEXT, body, re.M))
    return names - {'u8', 'u16', 'u32', 's8', 's16', 's32', 'f32', 'f64'}


def type_definition_span(body: str, tname: str) -> Optional[Tuple[int, int]]:
    """Span of `typedef struct [tag] { ... } tname;`, `struct tname { ... };`, or a one-line
    `typedef ... (*tname)(...);` / `typedef T tname;` in a block."""
    m1 = re.search(r'^typedef\s+[^;{}]*?\(\s*\*\s*' + re.escape(tname) + r'\s*\)\s*\([^;]*\)\s*;\s*\n?', body, re.M)
    if m1:
        return m1.start(), m1.end()
    m2 = re.search(r'^typedef\s+(?!struct\b|union\b|enum\b)[^;{}()\[\]]*?\b' + re.escape(tname) + ARR + r'\s*;\s*\n?', body, re.M)
    if m2:
        return m2.start(), m2.end()
    for m in re.finditer(r'^(?:typedef\s+)?(?:struct|union|enum)\s*(?:[A-Za-z_]\w*\s*)?\{', body, re.M):
        depth = 0
        i = m.end() - 1
        while i < len(body):
            if body[i] == '{':
                depth += 1
            elif body[i] == '}':
                depth -= 1
                if depth == 0:
                    tail = re.match(r'\s*([A-Za-z_]\w*)?' + ARR + r'\s*;', body[i + 1:])
                    if not tail:
                        break
                    end = i + 1 + tail.end()
                    head = body[m.start():m.end()]
                    tagm = re.search(r'(?:struct|union|enum)\s*([A-Za-z_]\w*)', head)
                    name = tail.group(1) if m.group(0).startswith('typedef') else (tagm.group(1) if tagm else None)
                    # the tag of a `typedef struct Tag { ... } Name;` names the same definition
                    if name == tname or (tagm and tagm.group(1) == tname):
                        return m.start(), end + (1 if body[end:end + 1] == '\n' else 0)
                    break
            i += 1
    return None


def dedupe_typedef_lines(prologue: str) -> str:
    """One copy of each identical one-line typedef (name_entry.c carried
    `typedef Sig_fn_800081C8_Color Color;` twice; every hoist appended another)."""
    seen: set = set()
    out = []
    for ln in prologue.splitlines():
        key = re.sub(r'\s+', ' ', ln).strip()
        if re.match(r'^typedef\s+[^;{}]*;$', key):
            if key in seen:
                continue
            seen.add(key)
        out.append(ln)
    return '\n'.join(out) + ('\n' if prologue.endswith('\n') else '')


def order_prologue_types(prologue: str) -> str:
    """A prologue definition that names a typedef defined later in the prologue moves after
    it (committed car.c: `EventObject` used `EventData *` seven lines before its typedef)."""
    for _ in range(64):
        defs = []
        # one-line typedefs (forward declarations, aliases, function pointers) define a name too
        for m in re.finditer(r'^typedef\s+[^;{}]*;\s*\n?', prologue, re.M):
            text = m.group(0)
            fp = re.search(r'\(\s*\*\s*([A-Za-z_]\w*)\s*\)', text)
            tailn = re.findall(r'([A-Za-z_]\w*)' + ARR + r'\s*;', text)
            if not fp and not tailn:
                continue
            name = fp.group(1) if fp else tailn[-1]
            defs.append((m.start(), m.end(), {name}))
        for m in re.finditer(r'^(?:typedef\s+)?(?:struct|union|enum)\b[^;{]*\{', prologue, re.M):
            # find the end of this definition
            i = m.end() - 1
            depth = 0
            while i < len(prologue):
                if prologue[i] == '{':
                    depth += 1
                elif prologue[i] == '}':
                    depth -= 1
                    if depth == 0:
                        tail = re.match(r'\s*([A-Za-z_]\w*)?' + ARR + r'\s*;\s*\n?', prologue[i + 1:])
                        if tail:
                            head = prologue[m.start():m.end()]
                            tagm = re.search(r'(?:struct|union|enum)\s+([A-Za-z_]\w*)', head)
                            names = {x for x in (tail.group(1), tagm.group(1) if tagm else None) if x}
                            defs.append((m.start(), i + 1 + tail.end(), names))
                        break
                i += 1
        defs.sort()
        moved = False
        for k, (a, b, names) in enumerate(defs):
            text = prologue[a:b]
            if re.match(r'^typedef\s+struct\s+(\w+)\s+\1\s*;', text.strip()):
                continue  # a forward declaration depends on nothing
            body_idents = set(re.findall(r'[A-Za-z_]\w*', text)) - names
            by_pointer = set(re.findall(r'\b([A-Za-z_]\w*)\s*\*', text)) - names
            later = []
            for a2, b2, n2 in defs[k + 1:]:
                if not (n2 & body_idents):
                    continue
                is_forward = bool(re.match(r'^typedef\s+struct\s+(\w+)\s+\1\s*;', prologue[a2:b2].strip()))
                # a name used only through a pointer needs just its forward typedef before it
                if (n2 & body_idents) <= by_pointer and not is_forward and any(
                        re.search(r'^typedef\s+struct\s+' + re.escape(x) + r'\s+' + re.escape(x) + r'\s*;', prologue, re.M) for x in n2):
                    continue
                later.append((a2, b2, n2))
            if later:
                a2, b2, _ = later[0]
                dep = prologue[a2:b2]
                prologue = prologue[:a] + dep + prologue[a:a2] + prologue[b2:]
                moved = True
                break
        if not moved:
            break
    return prologue


def hoist_private_types(tf: tufile.TuFile, truths: Dict[str, str], report: Dict[str, object]) -> None:
    """Move the definitions of block-private types that a truth names into the prologue,
    dependencies first, when exactly one block defines the type (reconcile prefixed the
    colliding ones)."""
    private: Dict[str, List[str]] = {}
    for b in tf.blocks:
        for t in private_type_names(b.body):
            private.setdefault(t, []).append(b.name)
    hoisted: List[Tuple[str, str]] = []
    done: set = set()
    # a type an included owned header defines is already visible: copying a block's private
    # copy into the prologue redefined it and broke every block at tu-check (face.c `V3` from
    # face_types.h, bg_san.c `Sig_fn_80077B14_fn_80077B14_Arg0` from shared_types.h)
    header = tutidy.header_types(tf.prologue)

    def in_prologue(t: str) -> bool:
        return bool(t in header or type_definition_span(tf.prologue, t)
                    or re.search(r'^(?:typedef\s+)?struct\s+' + re.escape(t) + r'\s*\{', tf.prologue, re.M))

    def hoist(t: str, stack: Tuple[str, ...] = ()) -> None:
        if t in done or t in stack or t not in private or in_prologue(t):
            return
        owners = private[t]
        if len(set(owners)) != 1:
            report.setdefault('unhoistable', []).append(f'{t}: defined in {sorted(set(owners))}')
            done.add(t)
            return
        b = tf.get(owners[0])
        span = type_definition_span(b.body, t)
        if not span:
            report.setdefault('unhoistable', []).append(f'{t}: no definition span in {b.name}')
            done.add(t)
            return
        text = b.body[span[0]:span[1]]
        for inner in dict.fromkeys(re.findall(r'[A-Za-z_]\w*', text)):
            if inner != t and inner in private:
                if private[inner] == owners and type_definition_span(b.body, inner) == span:
                    continue  # the tag (or alias) of this same definition, not a dependency
                hoist(inner, stack + (t,))
            elif inner != t:
                # a forward typedef (`typedef struct X X;`) the definition relies on
                fwd_ = re.search(r'^typedef\s+struct\s+' + re.escape(inner) + r'\s+' + re.escape(inner) + r'\s*;\s*\n?', b.body, re.M)
                if fwd_ and not re.search(r'^typedef\s+struct\s+' + re.escape(inner) + r'\s+' + re.escape(inner) + r'\s*;', tf.prologue, re.M):
                    tf.prologue = tf.prologue.rstrip('\n') + '\n\n' + fwd_.group(0).strip() + '\n'
                    b.body = b.body[:fwd_.start()] + b.body[fwd_.end():]
        span = type_definition_span(b.body, t)  # offsets may have moved with an inner hoist
        if span is None:
            if in_prologue(t):
                done.add(t)  # an inner hoist carried this very definition (tag and name)
                return
            report.setdefault('unhoistable', []).append(f'{t}: definition vanished from {b.name} during inner hoists')
            done.add(t)
            return
        text = b.body[span[0]:span[1]]
        b.body = b.body[:span[0]] + b.body[span[1]:]
        # a forward typedef of the tag (`typedef struct X X;`, self-referential structs) goes first
        fwd = re.search(r'^typedef\s+struct\s+' + re.escape(t) + r'\s+' + re.escape(t) + r'\s*;\s*\n?', b.body, re.M)
        if fwd:
            b.body = b.body[:fwd.start()] + b.body[fwd.end():]
        if (fwd or re.search(r'\b' + re.escape(t) + r'\s*\*', text)) and not re.search(r'^typedef\s+struct\s+' + re.escape(t) + r'\s+' + re.escape(t) + r'\s*;', tf.prologue, re.M) and text.startswith('struct'):
            tf.prologue = tf.prologue.rstrip('\n') + f'\n\ntypedef struct {t} {t};\n'
        tf.prologue = tf.prologue.rstrip('\n') + '\n\n' + text.rstrip('\n') + '\n'
        hoisted.append((t, b.name))
        done.add(t)

    for truth in truths.values():
        for t in re.findall(r'[A-Za-z_]\w*', truth):
            if t in private:
                hoist(t)
    report['hoisted_types'] = hoisted


def cast_results(body: str, name: str, old_ret: str) -> str:
    """`x = f(...)` under a truth with another return type: cast the call to the old type.
    A struct/union return (a typedef that is neither scalar nor pointer) has no cast from a
    scalar: the block keeps its own form (`Unmodelled`)."""
    if '*' not in old_ret and old_ret.split()[-1] not in SCALAR:
        raise Unmodelled(f'{name}: aggregate return type {old_ret!r} cannot be cast from the truth')
    out = body
    for m in reversed(list(re.finditer(r'\b' + re.escape(name) + r'\s*\(', body))):
        line_start = body.rfind('\n', 0, m.start()) + 1
        line_end = body.find('\n', m.start())
        if tutidy.DECL_LINE_RE.match(body[line_start:line_end if line_end >= 0 else len(body)]):
            continue
        res = split_args(body, m.end() - 1)
        if not res or body[res[1] + 1:].lstrip().startswith('{'):
            continue
        before = body[line_start:m.start()]
        if not re.search(r'(=|return|\(|,|\?|:)\s*$', before):
            continue
        out = out[:m.start()] + f'({old_ret})' + out[m.start():]
    return out


def min_call_args(body: str, name: str) -> Optional[int]:
    """Fewest arguments any call of `name` in the body passes (None: no call)."""
    least = None
    for m in re.finditer(r'\b' + re.escape(name) + r'\s*\(', body):
        line_start = body.rfind('\n', 0, m.start()) + 1
        line_end = body.find('\n', m.start())
        if tutidy.DECL_LINE_RE.match(body[line_start:line_end if line_end >= 0 else len(body)]):
            continue
        res = split_args(body, m.end() - 1)
        if not res or body[res[1] + 1:].lstrip().startswith('{'):
            continue
        least = len(res[0]) if least is None else min(least, len(res[0]))
    return least


def view_rewrite(body: str, name: str, decl: str, truth_is_pointer: bool = False) -> Optional[str]:
    """Every use of a data symbol goes through the block's own view of the object:
    `extern T n;` -> `(*(T *)&n)`, `extern T n[..];` -> `((T *)&n)`, `extern T *n;` -> `((T)n)`
    when the truth is a pointer too. The address is the same symbol."""
    m = re.match(r'^\s*extern\s+(.*?)\s*\b' + re.escape(name) + r'\s*((?:\[[^\]]*\])*)\s*;', decl.strip())
    if not m:
        return None
    t = re.sub(r'\s+', ' ', m.group(1)).strip()
    dims = re.findall(r'\[[^\]]*\]', m.group(2) or '')
    if len(dims) > 1:
        # a multi-dimensional array keeps its inner dimensions (`SelCell lbl[R][C]` -> `(SelCell (*)[C])`)
        view = f'((({t} (*){"".join(dims[1:])})&{name}))'
    elif m.group(2):
        view = f'((({t} *)&{name}))'
    elif t.endswith('*') and truth_is_pointer:
        view = f'(({t}){name})'
    else:
        view = f'(*(({t} *)&{name}))'
    ident = re.compile(r'(?<![\w.>])' + re.escape(name) + r'\b')
    # `&name` of the whole object keeps its address and type: wrapping the view in `&` is not an
    # lvalue (`&(((u32 *)&lbl_3_bss_F0))`, fn_3_BD00/BD30); `&name[i]` / `&name.f` still go
    # through the view (postfix binds first). A pointer truth's `&name` is the pointer itself.
    # Only a unary `&` is an address-of: the second `&` of `&&` (`== 0 && lbl_1_bss_96A != 0x14`,
    # fn_10_436C) and a bitwise `a & name` are binary operators and the name itself is a use.
    whole = re.compile(r'&\s*' + re.escape(name) + r'\b(?!\s*(?:\[|\.|->))')
    if m.group(2):
        address = f'(({t} (*){m.group(2)})&{name})'
    elif t.endswith('*') and truth_is_pointer:
        address = f'&{name}'
    else:
        address = f'(({t} *)&{name})'

    def unary(ln: str, i: int) -> bool:
        j = i - 1
        while j >= 0 and ln[j] in ' \t':
            j -= 1
        if j < 0:
            return True
        c = ln[j]
        if c == ')':
            # `(u8 *)&x` / `(Color)&x` is a cast of an address-of; `(a + b) & x` is binary
            o = ln.rfind('(', 0, j)
            inner = ln[o + 1:j] if o >= 0 else ''
            words = re.findall(r'[A-Za-z_]\w*', inner)
            if words and re.fullmatch(r'[\w\s\*]+', inner) and ('*' in inner or words[-1] in SCALAR
                                                                 or re.search(r'[A-Z]|_t$', words[-1])):
                return True
            return False
        if c in '&]':
            return False
        if c.isalnum() or c == '_':
            k = j
            while k >= 0 and (ln[k].isalnum() or ln[k] == '_'):
                k -= 1
            return ln[k + 1:j + 1] in ('return', 'case', 'else', 'sizeof')
        return True

    out_lines = []
    for ln in body.splitlines():
        if tutidy.DECL_LINE_RE.match(ln) and tutidy._decl_name(ln) == name:
            continue
        pieces, last = [], 0
        for am in whole.finditer(ln):
            if not unary(ln, am.start()):
                continue
            pieces.append(ident.sub(view, ln[last:am.start()]))
            pieces.append(address)
            last = am.end()
        pieces.append(ident.sub(view, ln[last:]))
        out_lines.append(''.join(pieces))
    return '\n'.join(out_lines) + ('\n' if body.endswith('\n') else '')


def adapt(body: str, n: str, old_decl: Optional[str], truth: str, report_bad: List[str], force: bool = False) -> Optional[str]:
    """The block's body under `truth` for symbol n, given the declaration it was written
    against (`old_decl`: its private line, or the old prologue line, or None). Returns None
    when no mechanical adaptation exists (a data view whose declaration cannot be parsed)."""
    lines = [x for x in body.splitlines() if not (tutidy.DECL_LINE_RE.match(x) and tutidy._decl_name(x) == n)]
    body = '\n'.join(lines) + ('\n' if body.endswith('\n') else '')
    if old_decl is None or old_decl.strip() == truth.strip():
        return body
    sv, st = _sig(old_decl), _sig(truth)
    if sv and st:
        if st[2] and st[2][-1] == '...':
            # a variadic truth (OSPanic, OSReport): its fixed parameters still convert, and a
            # block that declared them `u8 *` needs the pointer cast the truth's `char *` needs
            k = len(st[2]) - 1
            fixed = [t for t in sv[2] if t != '...']
            if len(fixed) >= k and fixed[:k] != st[2][:k]:
                body = cast_calls(body, n, fixed[:k], st[2][:k], force, variadic=True)
            return body
        if len(sv[2]) == len(st[2]):
            if sv[2] != st[2] and '...' not in sv[2]:
                permuted = permute_args(body, n, sv[2], st[2])
                body = permuted if permuted is not None else cast_calls(body, n, sv[2], st[2], force)
        elif len(sv[2]) > len(st[2]) and all(_same(a, b) for a, b in zip(sv[2][len(sv[2]) - len(st[2]):], st[2])):
            body = drop_leading_args(body, n, len(sv[2]) - len(st[2]))
        if sv[0] != st[0] and not _same(sv[0], st[0]) and re.sub(r'\s', '', sv[0]) != 'void':
            if re.sub(r'\s', '', st[0]) == 'void' and re.search(r'=\s*' + re.escape(n) + r'\s*\(', body):
                return None
            body = cast_results(body, n, sv[0])
        return body
    if not sv and not st:
        truth_ptr = bool(re.match(r'^\s*extern\s+.*\*\s*' + re.escape(n) + r'\s*;', truth))
        return view_rewrite(body, n, old_decl, truth_is_pointer=truth_ptr)
    return None


def _reg_class(t: str) -> str:
    return 'F' if re.sub(r'\bconst\b', '', t).strip() in ('f32', 'f64', 'float', 'double') else 'G'


def permute_args(body: str, name: str, old: List[str], new: List[str]) -> Optional[str]:
    """Two prototypes that place the same values in the same registers in another order
    (`(u8, f32, f32)` against `(f32, f32, s32)`): reorder the call's arguments so each
    register still receives what it did. Returns None when the classes do not permute."""
    oc, nc = [_reg_class(t) for t in old], [_reg_class(t) for t in new]
    if sorted(oc) != sorted(nc) or oc == nc:
        return None
    order = []
    used = set()
    for c in nc:
        j = next((j for j, c2 in enumerate(oc) if c2 == c and j not in used), None)
        if j is None:
            return None
        used.add(j)
        order.append(j)
    out = body
    for m in reversed(list(re.finditer(r'\b' + re.escape(name) + r'\s*\(', body))):
        line_start = body.rfind('\n', 0, m.start()) + 1
        line_end = body.find('\n', m.start())
        if tutidy.DECL_LINE_RE.match(body[line_start:line_end if line_end >= 0 else len(body)]):
            continue
        res = split_args(body, m.end() - 1)
        if not res or body[res[1] + 1:].lstrip().startswith('{') or len(res[0]) != len(old):
            continue
        args = [body[a:b].strip() for a, b in res[0]]
        new_args = [f'({new[i]})({args[order[i]]})' if not _same(old[order[i]], new[i]) else args[order[i]] for i in range(len(new))]
        out = out[:res[0][0][0]] + ', '.join(new_args) + out[res[0][-1][1]:]
    return out


def knr_definition(body: str, name: str) -> str:
    """The definition of `name` in non-prototype (K&R) form, so callers may pass fewer
    arguments after it (fn_1_5448C's lab_unused parameters; its code is unchanged)."""
    m = re.search(r'^([A-Za-z_][\w \*]*?)\b' + re.escape(name) + r'\s*\(([^;{}()]*)\)\s*\{', body, re.M)
    if not m or m.group(2).strip() in ('', 'void'):
        return body
    params = [x.strip() for x in m.group(2).split(',')]
    names, decls = [], []
    for prm in params:
        pm = re.search(r'([A-Za-z_]\w*)\s*((?:\[[^\]]*\])*)$', prm)
        if not pm or prm == '...':
            return body
        names.append(pm.group(1))
        decls.append(prm + ';')
    return body[:m.start()] + f'{m.group(1)}{name}({", ".join(names)})\n' + '\n'.join(decls) + '\n{' + body[m.end():]


def drop_leading_args(body: str, name: str, k: int) -> str:
    """Calls that passed k more leading arguments than the truth declares."""
    out = body
    for m in reversed(list(re.finditer(r'\b' + re.escape(name) + r'\s*\(', body))):
        line_start = body.rfind('\n', 0, m.start()) + 1
        line_end = body.find('\n', m.start())
        if tutidy.DECL_LINE_RE.match(body[line_start:line_end if line_end >= 0 else len(body)]):
            continue
        res = split_args(body, m.end() - 1)
        if not res or body[res[1] + 1:].lstrip().startswith('{') or len(res[0]) <= k:
            continue
        spans = res[0]
        out = out[:spans[0][0]] + out[spans[k][0]:]
    return out


_TOP_DEF_RE = re.compile(r'^(?:typedef\b|(?:struct|union|enum)\b[^;()]*\{)')


def _block_items(body: str) -> List[Tuple[int, int, set]]:
    """(first line, end line, names defined) of each file-scope type definition and `extern`
    declaration line of a block. Anything else (functions, data, macros) is never an item."""
    lines = body.splitlines()
    items: List[Tuple[int, int, set]] = []
    depth, i = 0, 0
    while i < len(lines):
        ln = lines[i]
        if depth == 0 and _TOP_DEF_RE.match(ln):
            j, d = i, 0
            closed = False
            while j < len(lines):
                d += lines[j].count('{') - lines[j].count('}')
                if d == 0 and lines[j].rstrip().endswith(';'):
                    closed = True
                    break
                j += 1
            if not closed:
                return items  # a shape this reader does not follow: no further items
            text = '\n'.join(lines[i:j + 1]) + '\n'
            if re.match(r'^(?:typedef\s+)?enum\b', text):
                names = set(re.findall(r'[A-Za-z_]\w*', text)) - {'typedef', 'enum'}
            else:
                names = private_type_names(text) | set(re.findall(r'^typedef\s+struct\s+([A-Za-z_]\w*)\s+\1\s*;', text))
            if names:
                items.append((i, j + 1, names))
            i = j + 1
            continue
        # a line declaring several data symbols names only its first: never an item
        if depth == 0 and ln.startswith('extern') and tutidy.DECL_LINE_RE.match(ln) and tutidy._decl_name(ln) \
                and ('(' in ln or ',' not in ln):
            items.append((i, i + 1, {tutidy._decl_name(ln)}))
        depth = max(depth + ln.count('{') - ln.count('}'), 0)
        i += 1
    return items


def strip_unreferenced(body: str) -> str:
    """The block without the type definitions and `extern` lines nothing else in it names:
    `restore` copies every type of the old prologue into a self-contained block (stcoli: 36
    blocks, 4663 duplicate lines). A proposal only: the caller keeps it after the oracle says
    the block still matches."""
    lines = body.splitlines()
    items = _block_items(body)
    word = re.compile(r'[A-Za-z_]\w*')
    total = Counter(word.findall(body))
    counts = [Counter(word.findall('\n'.join(lines[a:b]))) for a, b, _ in items]
    # definitions sharing a name (a forward typedef and its struct) stand or fall together
    groups: List[List[int]] = []
    for k, (_, _, names) in enumerate(items):
        hit = [g for g in groups if any(items[x][2] & names for x in g)]
        groups = [g for g in groups if g not in hit] + [[k] + [x for g in hit for x in g]]
    dropped: set = set()
    changed = True
    while changed:
        changed = False
        for g in groups:
            if g[0] in dropped:
                continue
            inside: Counter = Counter()
            for x in g:
                inside.update(counts[x])
            if all(total[n] <= inside[n] for x in g for n in items[x][2]):
                dropped.update(g)
                total.subtract(inside)
                changed = True
    gone = {ln for k in dropped for ln in range(items[k][0], items[k][1])}
    out = '\n'.join(ln for i, ln in enumerate(lines) if i not in gone)
    return out + ('\n' if body.endswith('\n') else '')


def _matches(r_) -> bool:
    return bool(r_ and r_.ok and (r_.matched or r_.matched_pool) and oracle.unit_fully_matches(r_) is None)


def _measure(text: str) -> Dict[str, int]:
    return {'lines': len(text.splitlines()), 'bytes': len(text.encode('utf-8', 'replace'))}


def _copied_prologue_lines(tf: tufile.TuFile) -> int:
    """Non-blank lines of self-contained blocks that repeat a line of the TU's prologue."""
    pro = {ln.strip() for ln in tf.prologue.splitlines() if ln.strip()}
    return sum(1 for b in tf.blocks if 'noprologue' in b.flags
               for ln in b.body.splitlines() if ln.strip() in pro)


def _size_report(before_text: str, after: tufile.TuFile) -> Dict[str, object]:
    before = tufile.parse(before_text)
    was, now = _measure(before_text), _measure(after.render())
    return {'before': was, 'after': now,
            'delta_lines': now['lines'] - was['lines'], 'delta_bytes': now['bytes'] - was['bytes'],
            'self_contained_before': sum(1 for b in before.blocks if 'noprologue' in b.flags),
            'self_contained_after': sum(1 for b in after.blocks if 'noprologue' in b.flags),
            'copied_prologue_lines_before': _copied_prologue_lines(before),
            'copied_prologue_lines_after': _copied_prologue_lines(after)}


def _prologue_summary(before: str, after: str) -> Dict[str, object]:
    return {'before': _measure(before), 'after': _measure(after),
            'includes': [ln.strip() for ln in after.splitlines() if tufile.INCLUDE_RE.match(ln)],
            'declarations': sum(1 for ln in after.splitlines() if tutidy.DECL_LINE_RE.match(ln)),
            'types': len(private_type_names(after))}


def resolve(p: Project, tu_source: str, v, apply: bool = True,
            extra_blocks: Optional[Dict[str, str]] = None,
            verdicts: Optional['VerdictCache'] = None) -> Dict[str, object]:
    """`extra_blocks` ({name: body}) join the TU as unverified members (unmatched functions'
    best bodies): their declarations are reconciled and adapted like everyone else's, they
    are never restored, and the result is only reported, never written. `verdicts` carries
    this search's oracle verdicts across an interrupted run; `apply_result` never reads it."""
    module = tu_source.split('/')[1] if tu_source.startswith('rel/') else 'main'
    units = {u['symbols'][0]: u for u in p.load_units() if u.get('tu') == tu_source}
    committed_path = tufile.tu_path(p, tu_source)
    committed_text = committed_path.read_text() if committed_path.exists() else ''
    tf = tufile.load(p, tu_source)
    committed_prologue = tf.prologue
    extra_names = set()
    if extra_blocks:
        apply = False
        for name_, body_ in extra_blocks.items():
            tf.blocks.append(tufile.Block(name_, body_, []))
            extra_names.add(name_)
    report: Dict[str, object] = {'tu': tu_source, 'truth': {}, 'rewritten': [], 'reverted': [], 'unresolved': {}}
    tf.prologue = order_prologue_types(split_multi(join_declarations(tf.prologue)))
    for b in tf.blocks:
        b.body = split_multi(join_declarations(b.body))
        b.flags = [x for x in b.flags if x != 'noprologue']  # every block under the one prologue
    # one include set for the TU: headers a block includes join the prologue
    block_includes = []
    own_includes: Dict[str, List[str]] = {}
    for b in tf.blocks:
        inc, rest = tufile.split_includes(b.body)
        own_includes[b.name] = [ln.strip() for ln in inc if ln.strip()]
        for ln in inc:
            if ln.strip() and ln.strip() not in {x.strip() for x in tf.prologue.splitlines()} and ln.strip() not in block_includes:
                block_includes.append(ln.strip())
        b.body = rest.lstrip('\n')
    # a block include whose header contradicts the prologue's headers is not promoted: the
    # blocks that carried it are verified under the prologue like everyone else, and the ones
    # that fail go straight back to their self-contained form (no candidate search can fix a
    # header the prologue does not include)
    conflict_bound: Dict[str, List[str]] = {}
    if block_includes:
        block_includes, conflicts = include_conflicts(tf.prologue, block_includes)
        if conflicts:
            report['include_conflicts'] = {inc: [f'{n}: {a} | {b}' for n, a, b in bad] for inc, bad in conflicts.items()}
            for b in tf.blocks:
                owned = [inc for inc in own_includes[b.name] if inc in conflicts]
                if owned:
                    conflict_bound[b.name] = owned
    if block_includes:
        tf.prologue = tufile.merge_prologue(tf.prologue, block_includes)
        report['promoted_includes'] = block_includes
    header_names, header_typedefs = tutidy._header_names(p, tf.prologue)
    # header declarations are collected transitively: sel.c includes rel/sel/sel.h, which
    # includes rel/sel/globals.h (`extern Obj_10_bss_0 lbl_10_bss_0;`); reading only the
    # direct includes let a block variant (`extern u8 lbl_10_bss_0[];`) become the truth and
    # the prologue redeclared the symbol
    hdecl: Dict[str, str] = {}
    for h in tutidy.included_headers(tf.prologue):
        for n, hl in h.decls:
            hdecl.setdefault(n, hl)
    # block typedefs that collide with a header or prologue typedef: an identical definition
    # is dropped (the prologue carries it), a different one gets the block's prefix
    prologue_typedefs = set(TYPE_TAIL_RE.findall(tf.prologue)) | set(re.findall(r'^(?:typedef\s+)?struct\s+([A-Za-z_]\w*)\s*\{', tf.prologue, re.M))
    # header struct/union tags collide too: two stcoli blocks defined an identical private
    # `struct fn_1_2D524_Copy200 { char *a[10][5]; }` that stcoli_types.h defines with `u32`;
    # unseen as a collision it was hoisted as a shared type and redefined the header's tag
    header_type_names = set(header_typedefs) | tutidy.header_types(tf.prologue)
    for b in tf.blocks:
        for t in sorted((set(TYPE_TAIL_RE.findall(b.body)) | set(re.findall(r'^(?:typedef\s+)?struct\s+([A-Za-z_]\w*)\s*\{', b.body, re.M))) & (header_type_names | prologue_typedefs)):
            span = type_definition_span(b.body, t)
            pspan = type_definition_span(tf.prologue, t)
            if span and pspan and re.sub(r'\s+', ' ', b.body[span[0]:span[1]]).strip() == re.sub(r'\s+', ' ', tf.prologue[pspan[0]:pspan[1]]).strip():
                b.body = b.body[:span[0]] + b.body[span[1]:]
                report.setdefault('dropped_typedefs', []).append((b.name, t))
            else:
                b.body = re.sub(r'\b' + re.escape(t) + r'\b', f'{b.name}_{t}', b.body)
                report.setdefault('renamed_typedefs', []).append((b.name, t))
    # the same private type defined by several blocks: identical text is hoisted once and
    # dropped from the blocks, differing definitions get each block's prefix
    defs_by_type: Dict[str, List[Tuple[str, str]]] = {}
    for b in tf.blocks:
        for t in set(TYPE_TAIL_RE.findall(b.body)) | set(re.findall(r'^(?:typedef\s+)?(?:struct|union)\s+([A-Za-z_]\w*)\s*\{', b.body, re.M)):
            span = type_definition_span(b.body, t)
            if span:
                defs_by_type.setdefault(t, []).append((b.name, re.sub(r'\s+', ' ', b.body[span[0]:span[1]]).strip()))
    for t, owners in defs_by_type.items():
        if type_definition_span(tf.prologue, t):
            continue  # the prologue defines it: the block-vs-prologue rule above handled the copies
        if len(owners) < 2:
            continue
        texts = {text for _, text in owners}
        if len(texts) == 1:
            first = True
            for bname, _ in owners:
                b = tf.get(bname)
                span = type_definition_span(b.body, t)
                if not span:
                    continue
                if first:
                    tf.prologue = tf.prologue.rstrip('\n') + '\n\n' + b.body[span[0]:span[1]].rstrip('\n') + '\n'
                    first = False
                b.body = b.body[:span[0]] + b.body[span[1]:]
            report.setdefault('shared_types', []).append(t)
        else:
            for bname, _ in owners:
                b = tf.get(bname)
                b.body = re.sub(r'\b' + re.escape(t) + r'\b', f'{bname}_{t}', b.body)
            report.setdefault('renamed_typedefs', []).append(('*', t))
    pdecl: Dict[str, str] = {}
    kept_pro = []
    for ln in tf.prologue.splitlines():
        if tutidy.DECL_LINE_RE.match(ln):
            n = tutidy._decl_name(ln)
            if n:
                pdecl[n] = ln.strip()
                continue  # every prologue declaration is re-decided below
        kept_pro.append(ln)
    base_prologue = '\n'.join(kept_pro).rstrip('\n') + '\n'
    definitions: Dict[str, str] = {}
    for b in tf.blocks:
        for m in reconcile.DEF_RE.finditer(b.body):
            definitions[m.group(2)] = 'extern ' + re.sub(r'\s+', ' ', m.group(1)).strip() + ';'
    variants: Dict[str, Counter] = OrderedDict()
    where: Dict[str, Dict[str, str]] = {}
    for b in tf.blocks:
        for n, ln in reconcile._decls(b.body):
            variants.setdefault(n, Counter())[ln] += 1
            where.setdefault(n, {})[b.name] = ln
    # a `volatile` declaration's justification comment sits on the line above it (lint S2):
    # it travels with the declaration into the prologue
    justification: Dict[str, str] = {}
    for b in tf.blocks + [tf.prologue]:
        text_ = b if isinstance(b, str) else b.body
        prev_ = ''
        for ln_ in text_.splitlines():
            s_ = ln_.strip()
            if re.search(r'\bvolatile\b', s_) and tutidy.DECL_LINE_RE.match(ln_) and re.match(r'/[/*]', prev_):
                justification.setdefault(s_, prev_)
            prev_ = s_
    # a TU-local definition called by a block before it (no declaration anywhere) was an
    # implicit `int f()` there: the whole-file compile rejects the later definition, so it
    # joins the prologue too (bg_cas.c: fn_1_FB96C calls fn_1_FB9DC before defining it)
    called_early = []
    for i_, b_ in enumerate(tf.blocks):
        for n_ in definitions:
            if n_ in variants or n_ in pdecl or n_ in called_early or re.search(r'\b(static|inline)\b', definitions[n_]):
                continue
            if any(re.search(r'\b' + re.escape(n_) + r'\s*\(', o.body) for o in tf.blocks[:i_]) and \
                    re.search(r'\b' + re.escape(n_) + r'\s*\([^;{}()]*\)\s*\{', b_.body):
                called_early.append(n_)
    symbols = list(dict.fromkeys(list(variants) + list(pdecl) + called_early))
    private_types = set()
    for b in tf.blocks:
        private_types |= private_type_names(b.body)
    # struct/union tags the headers define count as visible types too (spline_types.h declares
    # `extern struct fn_1_F8DC4_Table lbl_1_rodata_6FF0;`; with tags unknown the header truth was
    # inadmissible, the symbol fell back to each block's own line and every block collided)
    known_types = SCALAR | set(header_typedefs) | tutidy.header_types(tf.prologue) | private_types | private_type_names(tf.prologue) | {'struct', 'union', 'enum', 'extern', 'const', 'volatile', 'static', 'inline', 'unsigned', 'signed'}
    header_lines = {ln.strip() for ln in hdecl.values()}

    def admissible(decl: str) -> bool:
        if decl.strip() in header_lines:
            return True  # an included header's own line compiles wherever the header does
        sig = _sig(decl)
        stripped = re.sub(r'\[[^\]]*\]', '', decl.split('=')[0])  # array dimensions are not types
        words = set(re.findall(r'(?<![\w])[A-Za-z_]\w*', sig[0] + ' ' + ' '.join(sig[2]))) if sig else set(re.findall(r'(?<![\w])[A-Za-z_]\w*', stripped))
        if not sig:
            words -= {tutidy._decl_name(decl)}
        return all(w in known_types or w == '...' for w in words)

    candidates: Dict[str, List[Tuple[str, str]]] = {}
    project_defs: Optional[Dict[str, str]] = None  # built once, on first need
    for n in symbols:
        c: List[Tuple[str, str]] = []
        if n in hdecl:
            c.append(('header', hdecl[n]))
        d = definitions.get(n)
        if not d:
            if project_defs is None:
                project_defs = definition_index(p)
            d = project_defs.get(n)
        if d:
            c.append(('definition', d))
        if n in pdecl:
            c.append(('prologue', pdecl[n]))
        for t, _ in sorted(variants.get(n, {}).items(), key=lambda kv: (-kv[1], len(kv[0]))):
            c.append(('variant', t))
        seen = set()
        adm = [(src, t) for src, t in c if not (t.strip() in seen or seen.add(t.strip())) and admissible(t)]
        if not adm:
            # no spelling whose types this TU can see: the symbol stays out of the prologue and
            # every block keeps its own line (reported; usually a broken committed prologue)
            report.setdefault('inadmissible', []).append((n, c[0][1] if c else None))
            candidates[n] = []
            continue
        c = adm
        # a definition's parameter order across register classes is unconstrained by its own
        # code; a caller's spelling that permutes it by class carries the evaluation-order
        # evidence (fn_1_563E4: retail loads the s32 colour before the two floats)
        d_ = next((t for src, t in c if src == 'definition'), None)
        if d_ and _sig(d_):
            dc = [_reg_class(t) for t in _sig(d_)[2]]
            if len(set(dc)) > 1:
                perms = [(src, t) for src, t in c if src == 'variant' and _sig(t) and len(_sig(t)[2]) == len(dc)
                         and sorted(_reg_class(x) for x in _sig(t)[2]) == sorted(dc) and [_reg_class(x) for x in _sig(t)[2]] != dc]
                if perms:
                    c = perms + [x for x in c if x not in perms]
                    report.setdefault('definition_order_from_callers', []).append((n, perms[0][1]))
        # a definition whose return type is register-identical to the callers' (u32 against
        # void *): the callers' type, with the definition retyped to it (fn_1_548AC)
        if d_ and _sig(d_) and n in definitions:
            dr = _sig(d_)

            def gpr_equivalent(a: str, b: str) -> bool:
                # identical, or an integer against a pointer (never two different pointer types:
                # a definer's field accesses need its own struct pointer)
                if _same(a, b):
                    return True
                if not a.strip() or not b.strip():
                    return False
                ia, ib = a.split()[-1] in INTS and '*' not in a, b.split()[-1] in INTS and '*' not in b
                return ia != ib and ('*' in a or '*' in b) and a != '...' and b != '...'

            for src, t in list(c):
                vs_ = _sig(t)
                if src == 'variant' and vs_ and len(vs_[2]) == len(dr[2]) and t.strip() != d_.strip() \
                        and all(gpr_equivalent(a, b) for a, b in zip(vs_[2], dr[2])) and gpr_equivalent(vs_[0], dr[0]):
                    retyped = f'extern {vs_[0]} {n}({", ".join(vs_[2]) or "void"});'
                    c.insert(0, ('definition-retyped', retyped))
                    break
        if n in definitions:
            # the definer must agree with the prologue: only its own signature or a retyping of it
            c = [(src, t) for src, t in c if src in ('header', 'definition', 'definition-retyped')] or c[:1]
        if n in hdecl and admissible(hdecl[n]):
            # a header declaration is the file's truth for everyone, definers included
            c = [('header', hdecl[n])]
        candidates[n] = c
    # users of a symbol: blocks that declared it privately, called it, or defined it
    users: Dict[str, List[str]] = {}
    for n in symbols:
        pat = re.compile(r'\b' + re.escape(n) + r'\b')
        users[n] = [b.name for b in tf.blocks if b.name in where.get(n, {}) or pat.search(b.body)]
    original = {b.name: b.body for b in tf.blocks}
    symbols = [n for n in symbols if candidates.get(n)]
    choice: Dict[str, int] = {n: 0 for n in symbols}

    def old_decl_for(bname: str, n: str) -> Optional[str]:
        return where.get(n, {}).get(bname) or pdecl.get(n)

    forced: set = set()
    # definitions whose callers pass fewer arguments than they declare (unused trailing
    # parameters a match needed): the definition goes non-prototype so the calls stay legal
    knr_defs: set = set()
    for n in symbols:
        if n not in definitions:
            continue
        st0 = _sig(definitions[n])
        if not st0 or '...' in st0[2]:
            continue
        for b in tf.blocks:
            least = min_call_args(original[b.name], n)
            if least is not None and least < len(st0[2]):
                knr_defs.add(n)

    definer_of = {n: next((bn for bn, ob in original.items() if re.search(r'\b' + re.escape(n) + r'\s*\([^;{}()]*\)\s*\{', ob)), None)
                  for n in symbols if n in definitions}

    unmodelled: Dict[Tuple[str, str], str] = {}

    def derive(bname: str) -> Optional[str]:
        body = original[bname]
        for n in symbols:
            if bname not in users[n]:
                continue
            truth = candidates[n][choice[n]][1]
            if n in definitions and bname == definer_of.get(n):
                # the definer: its own private declaration goes, its signature is the truth
                body = '\n'.join(x for x in body.splitlines() if not (tutidy.DECL_LINE_RE.match(x) and tutidy._decl_name(x) == n)) + '\n'
                if n in knr_defs:
                    body = knr_definition(body, n)
                if candidates[n][choice[n]][0] == 'definition-retyped':
                    st_ = _sig(truth)
                    dm = re.search(r'^([A-Za-z_][\w \*]*?)\b' + re.escape(n) + r'\s*\(([^;{}()]*)\)\s*\{', body, re.M)
                    if dm:
                        params = [x.strip() for x in dm.group(2).split(',')] if dm.group(2).strip() not in ('', 'void') else []
                        names_ = [re.search(r'([A-Za-z_]\w*)\s*$', x).group(1) if re.search(r'([A-Za-z_]\w*)\s*$', x) else '' for x in params]
                        new_params = ', '.join(f'{t} {nm}'.replace('* ', '*') for t, nm in zip(st_[2], names_)) if params else 'void'
                        body = body[:dm.start()] + f'{st_[0]} {n}({new_params}) {{' + body[dm.end():]
                    if not _same(st_[0], dr_ret := _sig(d_full := definitions[n])[0]):
                        body = re.sub(r'\breturn\s+([^;]+);', lambda mm: f'return ({st_[0]})({mm.group(1)});' if not mm.group(1).strip().startswith('(' + st_[0]) else mm.group(0), body)
                continue
            try:
                body = adapt(body, n, old_decl_for(bname, n), truth, [], force=bname in forced)
            except (Unmodelled, IndexError, ValueError) as e:
                # a signature the rewrites cannot model: the block keeps its own form (reported)
                unmodelled.setdefault((bname, n), f'{type(e).__name__}: {e}')
                return None
            if body is None:
                return None
        return body

    def render_prologue() -> str:
        lines = []
        knr = set()
        for n in symbols:
            truth = candidates[n][choice[n]][1]
            st = _sig(truth)
            if st and '...' not in st[2]:
                for bname in users[n]:
                    least = min_call_args(tf.get(bname).body, n)
                    if least is not None and least != len(st[2]):
                        knr.add(n)
            if n in hdecl and candidates[n][choice[n]][0] == 'header':
                continue
            if n in hdecl and candidates[n][choice[n]][0] == 'header':
                continue
            if (n in knr or n in knr_defs) and st:
                lines.append(f'extern {st[0]} {n}();')
            elif n in definitions and candidates[n][choice[n]][0] == 'definition':
                lines.append(truth)  # the TU's own definition, declared ahead of its callers
            else:
                lines.append(truth)
            if lines and lines[-1] == truth and truth.strip() in justification:
                lines[-1] = justification[truth.strip()] + '\n' + truth
        report['knr'] = sorted(knr)
        return order_prologue_types(dedupe_typedef_lines(base_prologue).rstrip('\n') + '\n' + '\n'.join(dict.fromkeys(lines)) + '\n')

    before_hoist = tf.prologue
    hoist_private_types(tf, {f'{n}#{k}': t for n in symbols for k, (_, t) in enumerate(candidates[n])}, report)
    base_prologue = base_prologue.rstrip('\n') + '\n' + tf.prologue[len(before_hoist):]  # the hoisted types
    original = {b.name: b.body for b in tf.blocks}

    scratch = STATE_DIR / 'work' / 'tutruth' / Path(tu_source).stem
    scratch.mkdir(parents=True, exist_ok=True)

    memo: Dict[Tuple[str, str], Tuple[bool, bool]] = {}  # (name, text) -> (matches, compiled)
    compiled: Dict[str, bool] = {}  # each block's compile state at its latest verification

    def verify(names_: List[str]) -> Dict[str, bool]:
        """Direct oracle verdicts on the current state: prologue + block per unit, memoised by
        the generated text within this run and, under `verdicts`, across runs with the same
        compiler, header and retail inputs. The scratch file always holds the current text:
        `why` and `first_round_error` re-check it by path."""
        out: Dict[str, bool] = {}
        items = []
        for n_ in names_:
            text = tufile.gen_text(tf, n_)
            path = scratch / f'{n_}.c'
            path.write_text(text)
            hit = memo.get((n_, text))
            if hit is None and verdicts is not None:
                hit = verdicts.get(n_, text)
            if hit is not None:
                memo[(n_, text)] = hit
                out[n_], compiled[n_] = hit
                continue
            items.append((f'{module}:{n_}', path, text))
        if items:
            res = oracle.check_many(p, [(k, path) for k, path, _ in items], 20)
            for k, path, text in items:
                r_ = res.get(k)
                n_ = k.split(':', 1)[1]
                memo[(n_, text)] = (_matches(r_), bool(r_ and r_.ok))
                out[n_], compiled[n_] = memo[(n_, text)]
                if verdicts is not None:
                    verdicts.put(n_, text, memo[(n_, text)])
        return out

    def prologue_broken() -> bool:
        """Most blocks do not even compile: the shared prologue is at fault, and a per-block
        candidate search cannot change its types (stcoli spent 10 minutes searching all 121
        blocks under a redefined struct tag and rewrote none)."""
        return bool(names) and sum(1 for n_ in names if not compiled.get(n_)) > len(names) // 2

    def rebuild() -> None:
        for b in tf.blocks:
            nb = derive(b.name)
            b.body = nb if nb is not None else original[b.name]
        tf.prologue = render_prologue()

    rebuild()
    names = [b.name for b in tf.blocks if b.name in units and b.name not in extra_names]
    verdict = verify(names)
    if names and sum(1 for n_ in names if not verdict.get(n_)) > len(names) // 2:
        # the prologue itself is likely broken: keep the first compiler message for the report
        first = next(n_ for n_ in names if not verdict.get(n_))
        res0 = oracle.check(p, f'{module}:{first}', 20, source=scratch / f'{first}.c')
        report['first_round_error'] = res0.error[-900:] if not res0.ok else f'{first}: {res0.percent}'
        report['first_round_prologue'] = tf.prologue
    failing = [n for n in names if not verdict.get(n)]
    searched_broken = False  # one representative search while the prologue is broken
    for bname in list(failing):
        fixed = False
        if bname in conflict_bound:
            # its header is not in the prologue by decision, not by candidate choice
            report.setdefault('conflict_bound', {})[bname] = conflict_bound[bname]
            continue
        if prologue_broken():
            if searched_broken:
                report['prologue_broken'] = report.get('first_round_error') or BROKEN_TEXT
                continue
            searched_broken = True
        forced.add(bname)
        rebuild()
        if verify([bname]).get(bname):
            fixed = True
        else:
            forced.discard(bname)
        differing = [n for n in symbols if not fixed and bname in users[n] and len(candidates[n]) > 1
                     and (old_decl_for(bname, n) or '').strip() != candidates[n][choice[n]][1].strip()]
        for n in differing:
            prev = choice[n]
            for k in range(len(candidates[n])):
                if k == prev:
                    continue
                choice[n] = k
                rebuild()
                affected = sorted(set(users[n]) | {bname})
                vd = verify(affected)
                if vd.get(bname) and all(vd.get(x) for x in affected if verdict.get(x)):
                    fixed = True  # the block matches and no other user regressed
                    break
            if fixed:
                break
            choice[n] = prev
        if fixed:
            rebuild()
            verdict = verify(names)
            failing = [n for n in names if not verdict.get(n)]
    for n in symbols:
        report['truth'][n] = candidates[n][choice[n]]
    if unmodelled:
        report['unmodelled'] = [f'{b_} {n_}: {why}' for (b_, n_), why in sorted(unmodelled.items())]
    report['rewritten'] = [n for n in names if verdict.get(n)]
    report['reverted'] = failing
    # a block that cannot be adapted keeps its committed, self-contained form (still contested)
    pristine = tufile.load(p, tu_source)

    def restore(bname: str) -> None:
        """The committed block, self-contained: under the committed prologue when it was not
        self-contained before (its declarations are what it matched against)."""
        b = tf.get(bname)
        pb = pristine.get(bname)
        b.flags = list(pb.flags)
        if 'noprologue' in pb.flags:
            b.body = pb.body
        else:
            # includes and type definitions always; declarations only when the block names them
            keep = []
            idents = set(re.findall(r'[A-Za-z_]\w*', pb.body))
            for ln in pristine.prologue.splitlines():
                if tutidy.DECL_LINE_RE.match(ln):
                    n_ = tutidy._decl_name(ln)
                    if n_ and n_ not in idents:
                        continue
                keep.append(ln)
            b.body = '\n'.join(keep).rstrip('\n') + '\n\n' + pb.body
            b.flags.append('noprologue')

    report['prologue'] = tf.prologue
    broken = prologue_broken()
    if broken:
        report.setdefault('prologue_broken', report.get('first_round_error') or BROKEN_TEXT)
    for bname in failing:
        report.setdefault('adapted', {})[bname] = tf.get(bname).body
        if broken and not compiled.get(bname) and len(report.get('why', {})) >= 3:
            report.setdefault('why', {})[bname] = 'prologue error (see prologue_broken)'
        else:
            res_ = oracle.check(p, f'{module}:{bname}', 12, source=scratch / f'{bname}.c')
            report.setdefault('why', {})[bname] = (res_.error[-500:] if not res_.ok else
                                                  f'{res_.percent:.2f} ' + ' | '.join(l for l in res_.diff if l[0] in '?<>')[:600])
        restore(bname)
    final = verify(names)
    for n in [n for n, ok in final.items() if not ok]:
        restore(n)
    final.update(verify([n for n, ok in final.items() if not ok]))
    # a self-contained block keeps only what it names, when the oracle agrees it still matches
    copies = {b.name: b.body for b in tf.blocks if 'noprologue' in b.flags and b.name in names and final.get(b.name)}
    proposals = [n_ for n_, body in copies.items() if strip_unreferenced(body) != body]
    if proposals:
        for n_ in proposals:
            tf.get(n_).body = strip_unreferenced(copies[n_])
        kept = verify(proposals)
        for n_ in proposals:
            if not kept.get(n_):
                tf.get(n_).body = copies[n_]
        final.update(verify(proposals))
        report['stripped'] = {'blocks': sum(1 for n_ in proposals if kept.get(n_)),
                              'rejected': [n_ for n_ in proposals if not kept.get(n_)],
                              'lines': sum(len(copies[n_].splitlines()) - len(tf.get(n_).body.splitlines()) for n_ in proposals)}
    report['final_matching'] = sum(1 for x in final.values() if x)
    report['final_failing'] = [n for n, ok in final.items() if not ok]
    report['self_contained'] = [b.name for b in tf.blocks if 'noprologue' in b.flags]
    if extra_names:
        report['extra_verdicts'] = verify(sorted(extra_names))
        compiles = {}
        for n_ in sorted(extra_names):
            res_ = oracle.check(p, f'{module}:{n_}', 0, source=scratch / f'{n_}.c')
            compiles[n_] = bool(res_.ok)
            if not res_.ok:
                report.setdefault('extra_errors', {})[n_] = res_.error[-300:]
        report['extra_compiles'] = compiles
        report['tu_text'] = tf.render()
    # the text an apply writes: what a parse of it renders back to
    report['tu_text'] = tufile.parse(tf.render()).render()
    report['size'] = _size_report(committed_text, tufile.parse(report['tu_text']))
    report['prologue_summary'] = _prologue_summary(committed_prologue, tf.prologue)
    if apply:
        apply_result(p, tu_source, report)
    return report


BROKEN_TEXT = 'most blocks do not compile under the shared prologue'


def write_refusal(report: Dict[str, object]) -> Optional[str]:
    """Why this result may not be written. A broken prologue must not reach the tree even when
    every block passes in the end: each block that failed was restored self-contained, so the
    final count says nothing about the prologue the TU would carry."""
    if 'prologue_broken' in report:
        return f"prologue_broken: {str(report['prologue_broken'])[-400:]}"
    if report.get('final_failing'):
        return f"final_failing: {len(report['final_failing'])} blocks do not match: {report['final_failing'][:8]}"
    return None


def apply_result(p: Project, tu_source: str, report: Dict[str, object],
                 key: Optional[Dict[str, str]] = None) -> bool:
    """Write a resolved TU after the gates: refusal reasons, a fresh oracle verdict for every
    block of the exact parsed text (no memo, no store), and, given `key`, the same input hashes
    immediately before the write. Sets `applied` and, when it declines, `refused`."""
    report['applied'] = False
    why = write_refusal(report)
    if why:
        report['refused'] = why
        return False
    module = tu_source.split('/')[1] if tu_source.startswith('rel/') else 'main'
    units = {u['symbols'][0]: u for u in p.load_units() if u.get('tu') == tu_source}
    tf = tufile.parse(report['tu_text'])
    lost = sorted({b.name for b in tufile.load(p, tu_source).blocks} - {b.name for b in tf.blocks})
    if lost:
        report['refused'] = f'result drops blocks: {lost[:8]}'
        return False
    names = [b.name for b in tf.blocks if b.name in units]
    scratch = STATE_DIR / 'work' / 'tutruth' / Path(tu_source).stem
    scratch.mkdir(parents=True, exist_ok=True)
    items = []
    for n_ in names:
        path = scratch / f'{n_}.c'
        path.write_text(tufile.gen_text(tf, n_))
        items.append((f'{module}:{n_}', path))
    res = oracle.check_many(p, items, 20)
    failing = [n_ for n_ in names if not _matches(res.get(f'{module}:{n_}'))]
    report['apply_verified'] = len(names) - len(failing)
    if failing:
        report['apply_failing'] = failing
        report['refused'] = f'the fresh oracle check rejected {len(failing)} blocks: {failing[:8]}'
        return False
    path = tufile.tu_path(p, tu_source)
    lock = tufile._lock(path)
    try:
        if key is not None:
            moved = changed_inputs(key, input_hashes(p, tu_source))
            if moved:
                report['refused'] = f'inputs changed while verifying: {moved}'
                return False
        tufile._write_atomic(path, tf.render())
    finally:
        lock.close()
    report['applied'] = True
    for u in units.values():
        tufile.write_gen(p, u, tf)
    # a rewritten block may renumber its private literals: keep pool mappings current
    for u in list(units.values()):
        if isinstance(u.get('pool'), dict):
            res = oracle.check(p, f"{module}:{u['symbols'][0]}", 20)
            # only a re-derived map under which the block matches outright replaces the old
            # one: a pool match whose private sections cannot all be emptied (a unit that
            # keeps its own BSS definitions, identity bindings) returns an empty `pool_map`,
            # and writing it dropped fn_1_128F10's bindings (multiply-defined link, pass 18)
            if not (res.ok and res.matched and res.pool_map):
                if not (res.ok and (res.matched or res.matched_pool)):
                    report.setdefault('pool_unverified', []).append(u['symbols'][0])
                continue
            if res.pool_map != u['pool']:
                with oracle.build_lock('units.lock'):
                    all_units = p.load_units()
                    for x in all_units:
                        if x['source'] == u['source']:
                            x['pool'] = dict(res.pool_map)
                    p.save_units(all_units)
                report.setdefault('pool_remapped', []).append(u['symbols'][0])
    for u in units.values():
        tufile.write_gen(p, u, tf)
    return True


# ------------------------------------------------------------------ the stored result
STORE_SCHEMA = 1
# inputs of one block's oracle verdict (the TU text and other TUs' definitions choose the text)
VERDICT_INPUTS = ('units', 'compile', 'compilers', 'headers', 'retail', 'config', 'tools')


def _sha(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def _sha_files(paths) -> str:
    h = hashlib.sha256()
    for f in sorted(Path(x) for x in paths):
        h.update(f.as_posix().encode() + b'\0')
        h.update(f.read_bytes() if f.exists() else b'(missing)')
        h.update(b'\0')
    return h.hexdigest()


def _sha_json(value: object) -> str:
    return _sha(json.dumps(value, sort_keys=True, default=str).encode())


def input_hashes(p: Project, tu_source: str) -> Dict[str, str]:
    """A hash per input of the search and its verdicts, over-approximated on purpose: a header,
    tool, configuration or retail change anywhere forces a new search, which costs time; missing
    one would apply a stale result."""
    module = tu_source.split('/')[1] if tu_source.startswith('rel/') else 'main'
    path = tufile.tu_path(p, tu_source)
    raw = path.read_bytes()
    text = path.read_text()
    tf = tufile.parse(text)
    units = sorted((u for u in p.load_units() if u.get('tu') == tu_source), key=lambda u: u['source'])
    versions = {mw for mw, _ in oracle.version_candidates(p, module)} | {u['mw_version'] for u in units if u.get('mw_version')}
    versions.add(oracle.module_flags(p, module)[1])
    retail = []
    for b in tf.blocks:
        sym = p.resolve(f'{module}:{b.name}')
        target = p.target_object_for(sym) if sym else None
        if target is not None:
            retail.append(target)
    idents = set(re.findall(r'[A-Za-z_]\w*', text))
    index = definition_index(p)
    config = ROOT / 'config' / p.version
    return {
        'schema': str(STORE_SCHEMA),
        'tu_file': _sha(raw),
        'tu_prologue': _sha(tf.prologue.encode('utf-8', 'replace')),
        'tu_blocks': _sha_json([[b.name, b.flags, b.body] for b in tf.blocks]),
        'definitions': _sha_json({n: index[n] for n in idents if n in index}),
        'units': _sha_json(units),
        'compile': _sha_json([oracle.module_flags(p, module), oracle.version_candidates(p, module),
                              [[v_, oracle.compile_command(p, module, v_)] for v_ in sorted(versions)]]),
        'compilers': _sha_files([ROOT / 'build' / 'compilers' / v_ / 'mwcceppc.exe' for v_ in sorted(versions)]),
        'headers': _sha_files([f for d in (ROOT / 'include', p.build_dir / 'include') for f in d.rglob('*') if f.is_file()]),
        'retail': _sha_files(retail),
        'config': _sha_files(list(config.rglob('symbols.txt')) + list(config.rglob('splits.txt'))
                             + [config / 'ldscript.tpl', config / 'config.yml']),
        'tools': _sha_files(list((ROOT / 'tools' / 'fzgx').glob('*.py')) + [oracle.OBJDIFF]),
    }


def changed_inputs(stored: Dict[str, str], current: Dict[str, str]) -> List[str]:
    return sorted(k for k in set(stored) | set(current) if stored.get(k) != current.get(k))


def store_stem(tu_source: str) -> Path:
    return STATE_DIR / 'tutruth' / tu_source.replace('/', '__')


class VerdictCache:
    """Oracle verdicts of one TU's search, kept across an interrupted or re-keyed run while the
    inputs of a verdict (`VERDICT_INPUTS`) are unchanged. Append-only so a killed search keeps
    what it paid for. It serves the search and the dry-run report; an apply re-checks."""

    def __init__(self, tu_source: str, key: Dict[str, str]):
        self.path = Path(str(store_stem(tu_source)) + '.verdicts.jsonl')
        self.env = _sha_json({k: key.get(k) for k in VERDICT_INPUTS})
        self.rows: Dict[str, Tuple[bool, bool]] = {}
        self.hits = 0
        self.path.parent.mkdir(parents=True, exist_ok=True)
        if self.path.exists():
            with self.path.open() as fh:
                if fh.readline().strip() == self.env:
                    for ln in fh:
                        try:
                            k, ok, comp = json.loads(ln)
                        except ValueError:
                            continue  # a line cut short by a killed run
                        self.rows[k] = (bool(ok), bool(comp))
        if not self.rows:
            self.reset()

    def reset(self) -> None:
        self.rows = {}
        self.path.write_text(self.env + '\n')

    @staticmethod
    def _key(name: str, text: str) -> str:
        return _sha((name + '\0' + text).encode('utf-8', 'replace'))

    def get(self, name: str, text: str) -> Optional[Tuple[bool, bool]]:
        hit = self.rows.get(self._key(name, text))
        self.hits += hit is not None
        return hit

    def put(self, name: str, text: str, verdict: Tuple[bool, bool]) -> None:
        k = self._key(name, text)
        self.rows[k] = verdict
        with self.path.open('a') as fh:
            fh.write(json.dumps([k, verdict[0], verdict[1]]) + '\n')


def _save_store(tu_source: str, key: Dict[str, str], report: Dict[str, object], elapsed: float,
                invalid: Optional[str] = None) -> None:
    stem = str(store_stem(tu_source))
    tufile._write_atomic(Path(stem + '.json'), json.dumps({
        'key': key, 'report': report, 'search_seconds': round(elapsed, 1), 'invalid': invalid,
        'saved': time.strftime('%Y-%m-%d %H:%M:%S')}))
    # the proposal in a readable form: `git diff --no-index src/<tu> .fzgx/tutruth/<...>.after.c`
    tufile._write_atomic(Path(stem + '.after.c'), str(report.get('tu_text') or ''))
    tufile._write_atomic(Path(stem + '.prologue.h'), str(report.get('prologue') or ''))


def run(p: Project, tu_source: str, apply: bool = False, fresh: bool = False) -> Dict[str, object]:
    """Dry-run or apply through the store: reuse while every input hash agrees, search otherwise.
    `fresh` searches regardless and ignores the saved verdicts; an apply re-checks either way."""
    start = time.monotonic()
    stem = str(store_stem(tu_source))
    key = input_hashes(p, tu_source)
    stored = None
    if not fresh and Path(stem + '.json').exists():
        try:
            stored = json.loads(Path(stem + '.json').read_text())
        except ValueError:
            stored = None
    if fresh:
        changed = ['(--fresh)']
    elif stored is None:
        changed = ['(no stored result)']
    elif stored.get('invalid'):
        changed = [f"(invalidated: {stored['invalid']})"]
    else:
        changed = changed_inputs(stored.get('key') or {}, key)
    if changed:
        verdicts = None if fresh else VerdictCache(tu_source, key)
        report = resolve(p, tu_source, None, apply=False, verdicts=verdicts)
        searched = time.monotonic() - start
        moved = changed_inputs(key, input_hashes(p, tu_source))
        info = {'reused': False, 'recomputed_because': changed, 'search_seconds': round(searched, 1),
                'saved_verdicts_reused': verdicts.hits if verdicts else 0}
        if moved:
            info['not_stored_inputs_moved'] = moved
        else:
            _save_store(tu_source, key, report, searched)
    else:
        report = stored['report']
        info = {'reused': True, 'stored_search_seconds': stored.get('search_seconds'), 'saved': stored.get('saved')}
    info.update(path=stem + '.json', proposal=stem + '.after.c', prologue=stem + '.prologue.h')
    report['store'] = info
    if apply:
        if not apply_result(p, tu_source, report, key) and report.get('apply_failing'):
            # the key agreed and the oracle did not: that result is never offered again
            _save_store(tu_source, key, report, 0.0, invalid=report['refused'])
            VerdictCache(tu_source, key).reset()
    else:
        report['would_refuse'] = write_refusal(report)
    info['total_seconds'] = round(time.monotonic() - start, 1)
    return report


REPORT_ONLY_IN_STORE = ('prologue', 'adapted', 'tu_text', 'truth', 'first_round_prologue')


def summary(report: Dict[str, object]) -> Dict[str, object]:
    """The report for the terminal: the bulky texts stay in the store (`store.path`)."""
    out = {k: v for k, v in report.items() if k not in REPORT_ONLY_IN_STORE}
    out['truth_symbols'] = len(report.get('truth') or {})
    return out
