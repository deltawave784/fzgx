"""Source transformations and compiler-response algebra for the single fixup engine.

No compilation, search runners, caches, or submission live in this module.
"""
from __future__ import annotations
import difflib
import itertools
import math
import re
from collections import defaultdict
from pathlib import Path
from typing import Dict, List, Optional, Tuple
from capstone import Cs, CS_ARCH_PPC, CS_MODE_32, CS_MODE_BIG_ENDIAN
from Levenshtein import distance
from . import oracle, mwgraph, mwconstraints
from .signatures import records, record_tag, declarator

TYPE = (r'(?:(?:register|const|volatile)\s+){0,3}'
        r'(?:(?:unsigned|signed)\s+)?'
        r'(?:(?:long\s+long|long|short)(?:\s+int)?|(?:struct|union|enum)\s+\w+|[A-Za-z_]\w*)'
        r'(?:\s*\*)*')
DECL_RE = re.compile(r'^\s*(' + TYPE + r')(?:(?<=\*)\s*|\s+)([A-Za-z_]\w*)'
                     r'((?:\[[^\]]*\])*)\s*(?:=\s*([^;]+))?;\s*(?:(?:/\*.*?\*/|//[^\n]*)\s*)?$')


def _function_body_span(body: str, name: str) -> Optional[Tuple[int, int, int]]:
    m = re.search(rf"\b{re.escape(name)}\s*\([^;{{]*\)\s*\{{", body)
    if not m:
        return None
    depth, i = 0, m.end() - 1
    while i < len(body):
        if body[i] == "{":
            depth += 1
        elif body[i] == "}":
            depth -= 1
            if depth == 0:
                return m.start(), m.end(), i
        i += 1
    return None


def _locals(body: str, span) -> List[Tuple[int, int, str, str, str]]:
    """Leading local declarations, one per line: (start, end, type, name, dims). Declarations
    with initializers count (their text keeps the initializer)."""
    out = []
    from .sdkimport import masked
    code = masked(body)
    aggregates = None
    consumed = span[1]
    for m in re.finditer(r"[^\n]*\n", code[span[1]:span[2]]):
        line = m.group(0)
        s0 = span[1] + m.start()
        if s0 < consumed:
            continue
        if not line.strip():
            continue
        dm = DECL_RE.match(line.rstrip("\n"))
        if not dm:
            # Inline record declarations used to hide every subsequent local
            # from declaration-order and lifetime repairs.
            if not re.match(r'\s*(?:struct|union)\b',line):
                break
            if aggregates is None:
                aggregates = list(records(code,span[2]))
            start = s0+len(line)-len(line.lstrip())
            record = next((r for r in aggregates if r['start']==start),None)
            if not record:
                break
            end = code.find(';',record['end'],span[2])
            if end<0 or '=' in code[record['end']:end]:
                break
            tail = DECL_RE.fullmatch(record['kind']+' '+record['key']+code[record['end']:end+1])
            if not tail:
                break
            consumed = end+1
            if code[consumed:consumed+1]=='\n':
                consumed += 1
            typ = body[start:record['end']]+tail[1][len(record['kind']+' '+record['key']):]
            out.append((s0,consumed,typ,tail[2],tail[3]))
            continue
        out.append((s0, s0 + len(line), dm.group(1), dm.group(2), dm.group(3)))
    return out


def _init_of(line: str) -> Optional[str]:
    dm = DECL_RE.match(line.rstrip("\n"))
    return dm.group(4).strip() if dm and dm.group(4) else None


def split_declaration_groups(body, name):
    """Expose each scalar home to the captured declaration/lifetime repairs."""
    span = _function_body_span(body, name)
    if not span:
        return []
    pattern = re.compile(r'(?m)^([ \t]*)(' + TYPE + r')\s+'
                         r'(\w+(?:\[[^\],]+\])*(?:\s*,\s*\w+(?:\[[^\],]+\])*)+);[ \t]*$')
    def expand(match):
        if match[2] not in SCALAR_TYPES:
            return match[0]
        return '\n'.join(match[1] + match[2] + ' ' + var.strip() + ';' for var in match[3].split(','))
    inner = pattern.sub(expand, body[span[1]:span[2]])
    if inner == body[span[1]:span[2]]:
        return []
    return [('split scalar declaration groups', body[:span[1]] + inner + body[span[2]:])]


def _order_ok(locs, lines: List[str], order: Tuple[int, ...]) -> bool:
    """An initializer may only name locals declared before it."""
    placed = set()
    for i in order:
        init = _init_of(lines[i])
        if init and any(re.search(rf"\b{re.escape(locs[j][3])}\b", init) for j in range(len(locs)) if j not in placed and j != i):
            return False
        placed.add(i)
    return True


def split_inits(body: str, name: str) -> List[Tuple[str, str]]:
    """`T x = e;` -> `T x;` ... `x = e;` as the first statement (all at once, and one at a
    time); the reverse for a local whose first statement is a plain assignment."""
    out: List[Tuple[str, str]] = []
    span = _function_body_span(body, name)
    if not span:
        return out
    locs = _locals(body, span)
    if not locs:
        return out
    lines = [body[s:e] for s, e, *_ in locs]
    inits = [(i, _init_of(l)) for i, l in enumerate(lines)]
    with_init = [i for i, e in inits if e]
    indent = re.match(r"\s*", lines[0]).group(0)

    def rebuild(split_idx: List[int]) -> str:
        decls, assigns = [], []
        for i, l in enumerate(lines):
            if i in split_idx:
                dm = DECL_RE.match(l.rstrip("\n"))
                decls.append(f"{indent}{dm.group(1)} {dm.group(2)}{dm.group(3)};\n")
                assigns.append(f"{indent}{dm.group(2)} = {dm.group(4).strip()};\n")
            else:
                decls.append(l)
        return body[:locs[0][0]] + "".join(decls) + "".join(assigns) + body[locs[-1][1]:]

    if with_init:
        out.append(("split all inits", rebuild(with_init)))
        if len(with_init) > 1:
            for i in with_init:
                out.append((f"split init {locs[i][3]}", rebuild([i])))
    # the reverse: the first statements `x = e;` for locals without initializers, folded in
    rest = body[locs[-1][1]:span[2]]
    text = body
    folded = 0
    for i, l in enumerate(lines):
        if _init_of(l):
            continue
        m = re.match(r"\s*\n?(\s*)" + re.escape(locs[i][3]) + r" = ([^;]+);\n", rest)
        if not m:
            break
        dm = DECL_RE.match(l.rstrip("\n"))
        if not dm:  # a declaration DECL_RE cannot split (fn_15_5460) cannot take a folded init
            break
        new_line = f"{indent}{dm.group(1)} {dm.group(2)}{dm.group(3)} = {m.group(2)};\n"
        text = text.replace(l, new_line, 1)
        text = text.replace(m.group(0), "\n" if m.group(0).startswith("\n") else "", 1)
        rest = rest[m.end():]
        folded += 1
        out.append((f"fold {folded} inits", text))
    return out


def hoists(body: str, name: str) -> List[Tuple[str, str]]:
    """A local declared in an inner block moved to the top of the function."""
    out: List[Tuple[str, str]] = []
    span = _function_body_span(body, name)
    if not span:
        return out
    locs = _locals(body, span)
    top = locs[-1][1] if locs else span[1] + (1 if body[span[1]] == "\n" else 0)
    names = {l[3] for l in locs}
    from .sdkimport import masked
    code=masked(body)
    sites=[]
    for line in re.finditer(r'(?m)^[ \t]+[^\n]*;[^\n]*\n',code[top:span[2]]):
        declaration=DECL_RE.fullmatch(line[0].rstrip('\n'))
        if declaration and declaration[1] not in ('return','goto','break','continue'):
            sites.append((line,declaration))
    for line, declaration in sites:
        typ,nm,dims,init=declaration.groups()
        if nm in names or nm == name:
            continue
        if sum(d[2]==nm for _,d in sites)>1:
            continue
        indent = re.match(r"\s*", body[locs[0][0]:locs[0][1]]).group(0) if locs else "    "
        s0, e0 = top + line.start(), top + line.end()
        decl = f"{indent}{declarator(typ,nm+dims)};\n"
        repl = f"{re.match(r'[ \t]*',line[0])[0]}{nm} = {body[s0+declaration.start(4):s0+declaration.end(4)].strip()};\n" if init else ""
        text = body[:s0] + repl + body[e0:]
        text = text[:top] + decl + text[top:]
        out.append((f"hoist {nm}", text))
    return out


_FWD_DECL = r"^[ \t]*(?:const\s+)?(?:struct\s+)?\w+[\s*]+{v}\s*;[ \t]*\n"


def forwarded_locals(body: str, name: str) -> List[Tuple[str, str]]:
    """The inverse of a held local: `v = EXPR;` assigned once (no call, no side effect, operands
    never assigned afterwards) is substituted into every later use and its declaration dropped.
    A declared local is numbered in pass 1 below every window web; written as its expression the
    value becomes a CSE/loop-invariant shadow or lowering temporary in the window, numbered after
    the locals (capture verdict class `inline-region`, e.g. fn_1_10B800's `lb = obj->s->q->p`
    replays with lb numbered above the loop temporaries, `v43->v54`)."""
    out: List[Tuple[str, str]] = []
    span = _function_body_span(body, name)
    if not span:
        return out
    lo, hi = span[1], span[2]
    inner = body[lo:hi]
    names = sorted(set(re.findall(r"^[ \t]*(?:const\s+)?(?:struct\s+)?\w+[\s*]+(\w+)\s*;", inner, re.M)))

    def assign(v):
        e = re.escape(v)
        return re.compile(rf"(?<![\w.>]){e}\s*(?:[-+*/%&|^]|<<|>>)?=(?!=)|(?:\+\+|--)\s*{e}\b"
                          rf"|(?<![\w.>]){e}\s*(?:\+\+|--)|&\s*{e}\b")

    for v in names:
        defs = list(assign(v).finditer(inner))
        if len(defs) != 1:
            continue
        m = re.compile(rf"^([ \t]*){re.escape(v)}\s*=\s*([^;{{}}]+);[ \t]*\n", re.M).search(inner)
        if not m or not (m.start() <= defs[0].start() <= m.end(2)):
            continue
        expr = m.group(2).strip()
        if re.search(r"\w\s*\(", expr) or re.search(r"\+\+|--|(?<![=!<>])=(?!=)", expr):
            continue
        after = inner[m.end():]
        operands = set(re.findall(r"(?<![.>\w])[A-Za-z_]\w*", expr)) - {v}
        if any(assign(w).search(after) for w in operands):
            continue
        decl = re.compile(_FWD_DECL.format(v=re.escape(v)), re.M)
        before = decl.sub("", inner[:m.start()], count=1)
        use = re.compile(rf"(?<![\w.>]){re.escape(v)}\b")
        uses = list(use.finditer(after))
        if not uses or use.search(before):
            continue
        new_after = after
        for u in reversed(uses):
            new_after = new_after[:u.start()] + "(" + expr + ")" + new_after[u.end():]
        text = before + new_after
        out.append((f"forward {v} = {expr[:40]} into its {len(uses)} uses", body[:lo] + text + body[hi:]))
    return out


def definition_moves(body: str, name: str, limit: int = 6) -> List[Tuple[str, str]]:
    """A local's only assignment `v = EXPR;` moved up or down past neighbouring one-line
    statements of its block (never past one assigning an operand of EXPR or reading/writing v).
    The move lengthens or shortens v's live range, i.e. changes its interference degree at its
    simplify turn: the lever of a capture verdict of class `degree` (fn_1_10B800: `43:+16`
    reproduces retail's r31 for `lb`, defined earlier it interferes with the loop's setup)."""
    out: List[Tuple[str, str]] = []
    span = _function_body_span(body, name)
    if not span:
        return out
    lo, hi = span[1], span[2]
    inner = body[lo:hi]
    lines = inner.splitlines(keepends=True)
    starts = [0]
    for ln in lines:
        starts.append(starts[-1] + len(ln))
    simple = re.compile(r"^([ \t]*)[^{}\n]*;[ \t]*\n$")

    def assigns(text, w):
        e = re.escape(w)
        return re.search(rf"(?<![\w.>]){e}\s*(?:[-+*/%&|^]|<<|>>)?=(?!=)|(?:\+\+|--)\s*{e}\b|(?<![\w.>]){e}\s*(?:\+\+|--)|&\s*{e}\b", text)

    for k, ln in enumerate(lines):
        m = re.match(r"^([ \t]*)([A-Za-z_]\w*)\s*=(?!=)\s*([^;{}]+);[ \t]*\n$", ln)
        if not m:
            continue
        ind, v, expr = m.groups()
        if sum(1 for _ in re.finditer(rf"(?<![\w.>]){re.escape(v)}\s*(?:[-+*/%&|^]|<<|>>)?=(?!=)", inner)) != 1:
            continue
        operands = set(re.findall(r"(?<![.>\w])[A-Za-z_]\w*", expr)) - {v}
        for direction in (-1, 1):
            j, moved = k + direction, 0
            while 0 <= j < len(lines) and moved < limit:
                other = lines[j]
                sm = simple.match(other)
                if not sm or sm.group(1) != ind or re.match(r"\s*(?:return|break|continue|goto|case|default)\b", other):
                    break
                if re.search(rf"(?<![\w.>]){re.escape(v)}\b", other) or any(assigns(other, w) for w in operands):
                    break
                if re.match(r"^\s*(?:const\s+)?(?:struct\s+)?\w+[\s*]+\w+(?:\[[^\]]*\])*\s*(?:=[^;]*)?;", other) \
                        and not re.match(r"^\s*\w+\s*=", other):
                    break  # a declaration: v cannot move above the block's declarations
                moved += 1
                if direction < 0:
                    new = lines[:j] + [ln] + lines[j:k] + lines[k + 1:]
                else:
                    new = lines[:k] + lines[k + 1:j + 1] + [ln] + lines[j + 1:]
                out.append((f"move {v} = definition {'up' if direction < 0 else 'down'} {moved}",
                            body[:lo] + ''.join(new) + body[hi:]))
                j += direction
    return out


# Zero-cost barriers and table qualifiers, after karamzov123/fzero-gx-decomp (CC0), 2026-10-29
# (docs/MWCC_IDIOMS.md): `v = v;` emits no code but keeps v a user-local web, `p = p;` at the
# top of an inline helper keeps the argument from being substituted as an expression, and a
# `const` table no longer aliases the stores before its loads.
_LOCAL_NAME = re.compile(r"^[ \t]*(?:const\s+|volatile\s+|register\s+)*(?:(?:struct|union|enum)\s+\w+|\w+)[\s*]+"
                         r"(\w+)\s*(?:=[^;]*)?;", re.M)
_DECL_LINE = re.compile(r"^\s*(?:const\s+|volatile\s+|static\s+|register\s+)*(?:(?:struct|union|enum)\s+\w+|"
                        r"[us](?:8|16|32|64)|f32|f64|int|char|short|long|unsigned|signed|float|double|void|"
                        r"[A-Z]\w*)[\s*]+\w+(?:\[[^\]]*\])*\s*(?:=[^;]*)?;")


def _assigned_in(text: str, v: str) -> bool:
    e = re.escape(v)
    return bool(re.search(rf"(?<![\w.>]){e}\s*(?:[-+*/%&|^]|<<|>>)?=(?!=)|(?:\+\+|--)\s*{e}\b"
                          rf"|(?<![\w.>]){e}\s*(?:\+\+|--)|&\s*{e}\b", text))


def _block_end(text: str, i: int) -> int:
    """Index just past the statement starting at text[i] (a braced block or up to `;`)."""
    while i < len(text) and text[i] in " \t\n":
        i += 1
    if i < len(text) and text[i] == "{":
        depth = 0
        for k in range(i, len(text)):
            depth += text[k] == "{"
            depth -= text[k] == "}"
            if depth == 0:
                return k + 1
        return len(text)
    k = text.find(";", i)
    return len(text) if k < 0 else k + 1


def self_assignment_barriers(body: str, name: str, limit: int = 32) -> List[Tuple[str, str]]:
    """`v = EXPR;` followed by `v = v;` (no code: single-use folding of v stops, so v stays a
    declared local's web colored after the IRO temporaries; karamzov123's fn_1_CDC8C), and a
    loop-invariant local read in a `for` body appended to the step as `, v = v` (blocks the
    constant propagation of that one value without `opt_propagation off`; their fn_1_22F90)."""
    out: List[Tuple[str, str]] = []
    span = _function_body_span(body, name)
    if not span:
        return out
    lo, hi = span[1], span[2]
    inner = body[lo:hi]
    names = set(_LOCAL_NAME.findall(inner))
    names |= {p for p in re.findall(r"(\w+)\s*(?:,|$)", re.sub(r"\[[^\]]*\]", "", body[span[0]:lo].split("(", 1)[-1].rsplit(")", 1)[0]))
              if p not in ("void",)}
    names = {n for n in names if not re.fullmatch(r"\d.*|[us](?:8|16|32)|f32|f64|int|char|void", n)}
    lines = inner.splitlines(keepends=True)
    pos = 0
    for k, ln in enumerate(lines):
        start = pos
        pos += len(ln)
        m = re.match(r"^([ \t]*)(?:(?:const\s+)?(?:struct\s+)?\w+[\s*]+)?([A-Za-z_]\w*)\s*=(?!=)\s*[^;{}]+;[ \t]*(?://[^\n]*|/\*.*?\*/)?\n$", ln)
        if not m or m.group(2) not in names or re.match(r"\s*(?:return|if|while|for|else)\b", ln):
            continue
        ind, v = m.groups()
        if re.search(rf"^\s*{re.escape(v)}\s*=\s*{re.escape(v)}\s*;", lines[k + 1] if k + 1 < len(lines) else ""):
            continue
        declared_here = not re.match(rf"\s*{re.escape(v)}\s*=", ln)
        if declared_here:
            nxt = next((x for x in lines[k + 1:] if x.strip()), "")
            if _DECL_LINE.match(nxt):
                continue  # a statement among the declarations is not C89
        at = lo + pos
        out.append((f"barrier {v} = {v} after line {k + 1}", body[:at] + f"{ind}{v} = {v};\n" + body[at:]))
        if len(out) >= limit:
            break
    for m in re.finditer(r"\bfor\s*\(", inner):
        depth, i = 0, m.end() - 1
        while i < len(inner):
            depth += inner[i] == "("
            depth -= inner[i] == ")"
            if depth == 0:
                break
            i += 1
        header = inner[m.end():i]
        if header.count(";") != 2:
            continue
        loop = inner[i + 1:_block_end(inner, i + 1)]
        for v in sorted(names):
            if not re.search(rf"(?<![\w.>]){re.escape(v)}\b", loop) or _assigned_in(loop + header, v):
                continue
            step = header.rsplit(";", 1)
            new_header = step[0] + ";" + (step[1].rstrip() + ", " if step[1].strip() else " ") + f"{v} = {v}"
            at, end = lo + m.end(), lo + i
            out.append((f"barrier for-step {v} = {v}", body[:at] + new_header + body[end:]))
            if len(out) >= 2 * limit:
                return out
    return out


_INLINE_PARAMS_DEF = re.compile(r"^[ \t]*(?:static\s+)?(?:inline|__inline)\s+(?:static\s+)?[^;{}()]*?\b(\w+)\s*\(([^;{}]*)\)\s*\{", re.M)


def inline_parameter_barriers(body: str, name: str) -> List[Tuple[str, str]]:
    """`param = param;` at the top of a static inline helper (after its declarations): the AST
    inliner then binds the argument to a parameter variable instead of substituting the argument
    expression, which changes operand lowering order at the call site (karamzov123's fn_4_28FC).
    One candidate per parameter and one with every parameter."""
    out: List[Tuple[str, str]] = []
    for m in _INLINE_PARAMS_DEF.finditer(body):
        helper = m.group(1)
        if helper == name:
            continue
        params = []
        for p in m.group(2).split(","):
            p = re.sub(r"\[[^\]]*\]", "", p).strip()
            if not p or p in ("void", "...") or "(" in p:
                continue
            pm = re.search(r"(\w+)\s*$", p)
            if pm and pm.group(1) not in ("void",) and not re.fullmatch(r"[us](?:8|16|32)|f32|f64|int|char", pm.group(1)):
                params.append(pm.group(1))
        span = _function_body_span(body, helper)
        if not params or not span:
            continue
        try:
            decls = _locals(body, span)
        except Exception:
            decls = []
        kept = []
        for d in decls:  # `return p;` parses as a declaration of type `return`
            if d[2].strip(' *') in ('return', 'goto', 'break', 'continue', 'case', 'else', 'do'):
                break
            kept.append(d)
        at = kept[-1][1] if kept else span[1]
        if body[at - 1:at] != "\n":
            nl = body.find("\n", at)
            at = nl + 1 if 0 <= nl < span[2] else at
        if any(re.search(rf"^\s*{re.escape(p)}\s*=\s*{re.escape(p)}\s*;", body[span[1]:span[2]], re.M) for p in params):
            continue
        prefix = "" if body[at - 1:at] == "\n" else "\n"
        for p in params:
            out.append((f"inline barrier {helper}: {p} = {p}", body[:at] + prefix + f"    {p} = {p};\n" + body[at:]))
        if len(params) > 1:
            text = "".join(f"    {p} = {p};\n" for p in params)
            out.append((f"inline barrier {helper}: all parameters", body[:at] + prefix + text + body[at:]))
    return out


_EXTERN_TABLE = re.compile(r"^extern[ \t]+(?!const\b)((?:volatile[ \t]+)?(?:(?:struct|union)[ \t]+\w+|\w+)[ \t*]*?)[ \t]*(\w+)[ \t]*((?:\[[^\]\n]*\])+)[ \t]*;", re.M)


def const_extern_tables(body: str, name: str) -> List[Tuple[str, str]]:
    """`extern T tbl[];` that the body never writes -> `extern const T tbl[];`. An unqualified
    table is assumed to alias every earlier byte/half/word store, so its loads cannot be
    scheduled above them; const lets them hoist (retail's load-before-store, karamzov123's
    fn_8006953C). One candidate per table and one with every table."""
    out: List[Tuple[str, str]] = []
    found = []
    for m in _EXTERN_TABLE.finditer(body):
        t, sym = m.group(1).strip(), m.group(2)
        e = re.escape(sym)
        rest = body[:m.start()] + body[m.end():]
        if "volatile" in t or re.search(rf"(?<![\w.>]){e}\s*(?:\[[^\]]*\]\s*)*(?:\.\w+\s*|->\w+\s*|\[[^\]]*\]\s*)*(?:[-+*/%&|^]|<<|>>)?=(?!=)"
                                        rf"|(?:\+\+|--)\s*{e}\b|(?<![\w.>]){e}(?:\s*\[[^\]]*\])*\s*(?:\+\+|--)", rest):
            continue
        if not re.search(rf"(?<![\w.>]){e}\b", rest):
            continue
        found.append((m, t, sym))
    for m, t, sym in found:
        new = f"extern const {t} {sym}{m.group(3)};"
        out.append((f"const table {sym}", body[:m.start()] + new + body[m.end():]))
    if len(found) > 1:
        text = body
        for m, t, sym in reversed(found):
            text = text[:m.start()] + f"extern const {t} {sym}{m.group(3)};" + text[m.end():]
        out.append(("const tables (all)", text))
    return out


def _trees(terms: List[str]):
    """Every full binary bracketing of TERMS in their given order."""
    if len(terms) == 1:
        yield terms[0]
        return
    for k in range(1, len(terms)):
        for left in _trees(terms[:k]):
            for right in _trees(terms[k:]):
                yield f"({left} + {right})"


def add_trees(body: str, name: str, cap: int = 720) -> List[Tuple[str, str]]:
    """A flat `+` chain of 3..6 pure terms rewritten as every binary tree of its terms: every
    order and bracketing up to four terms (120 trees), every bracketing of the source order plus
    every order left-associated for five or six. MWCC keeps the source association of integer
    and pointer sums, so retail's `add` operand order and its address CSEs pin one tree
    (karamzov123: 30,240 trees for six terms compile in one batch)."""
    ops: List[dict] = []
    try:
        commutations(body, name, ops)
    except Exception:
        return []
    adds = [o for o in ops if o['op'] == '+']
    by_span = {(o['start'], o['end']): o for o in adds}
    children = set()
    for o in adds:
        if o['left'] in by_span:
            children.add(o['left'])
        if o['right'] in by_span:
            children.add(o['right'])
    out: List[Tuple[str, str]] = []
    seen = set()

    def flatten(o):
        terms = []
        for side in ('left', 'right'):
            s = o[side]
            if s in by_span:
                terms += flatten(by_span[s])
            else:
                terms.append(body[s[0]:s[1]].strip())
        return terms

    for o in adds:
        if (o['start'], o['end']) in children:
            continue
        terms = flatten(o)
        if not 3 <= len(terms) <= 6:
            continue
        orders = list(itertools.permutations(terms)) if len(terms) <= 4 else [tuple(terms)]
        texts = [t for order in orders for t in _trees(list(order))]
        if len(terms) > 4:
            for order in itertools.permutations(terms):
                acc = order[0]
                for t in order[1:]:
                    acc = f"({acc} + {t})"
                texts.append(acc)
        for t in texts:
            new = body[:o['start']] + t + body[o['end']:]
            if new != body and new not in seen:
                seen.add(new)
                out.append((f"add-tree {len(terms)} terms at {o['start']}: {t[:60]}", new))
                if len(out) >= cap:
                    return out
    return out


def through_local(body: str, name: str) -> List[Tuple[str, str]]:
    """`x = A op B;` where A is a load -> `x = A; x = x op B;` (the loaded value is the local's
    own register), and `if (p->f OP k)` -> `t = p->f; if (t OP k)` with a fresh local."""
    out: List[Tuple[str, str]] = []
    span = _function_body_span(body, name)
    if not span:
        return out
    locs = _locals(body, span)
    inner = body[span[1]:span[2]]
    for m in re.finditer(r"^(\s*)([A-Za-z_]\w*) = ((?:\("+TYPE+r"\)\s*)?[A-Za-z_][\w>.\-\[\]\(\)\* ]*?) (>>|<<|\+|-|&|\||\*|%|/) ([^;]+);\n", inner, re.M):
        ind, x, a, op, b = m.groups()
        value=re.sub(r'^\('+TYPE+r'\)\s*','',a)
        if re.search(r'\b'+re.escape(x)+r'\b',a) or "(" in value and not value.startswith("*("):
            continue
        s0, e0 = span[1] + m.start(), span[1] + m.end()
        out.append((f"through {x}", body[:s0] + f"{ind}{x} = {a};\n{ind}{x} = {x} {op} {b};\n" + body[e0:]))
        # A compound assignment groups its entire RHS. The regex can split
        # input * 53 + 74 at '*'; input *= 53 + 74 would change the value.
        depth = 0
        grouped = True
        for token in TOKEN.findall(b):
            if token in ('(', '['):
                depth += 1
            elif token in (')', ']'):
                depth -= 1
            elif depth == 0 and (token in ('?', ',', ':') or
                                 token in PREC and PREC[token] <= PREC[op]):
                grouped = False
                break
        if grouped and depth == 0:
            out.append((f"through {x} compound", body[:s0] + f"{ind}{x} = {a};\n{ind}{x} {op}= {b};\n" + body[e0:]))
    if locs:
        top = locs[-1][1]
        indent = re.match(r"\s*", body[locs[0][0]:locs[0][1]]).group(0)
        k = 0
        for m in re.finditer(r"^(\s*)(if|while) \(\(?([A-Za-z_]\w*(?:->|\.)\w+) (==|!=|<|>|<=|>=|&)", inner, re.M):
            if span[1] + m.start() < top:
                continue
            k += 1
            t = f"tmp_ra{k}"
            s0 = span[1] + m.start()
            expr = m.group(3)
            text = body[:s0] + f"{m.group(1)}{t} = {expr};\n" + body[s0:s0 + m.start(3) - m.start()] + t + body[s0 + m.end(3) - m.start():]
            text = text[:top] + f"{indent}s32 {t};\n" + text[top:]
            out.append((f"temp for {expr}", text))
    return out



def _decl_anchor(body: str, name: str):
    """(top, indent) for inserting a declaration after the leading locals, or None."""
    span = _function_body_span(body, name)
    if not span:
        return None
    locs = _locals(body, span)
    top = locs[-1][1] if locs else span[1] + (1 if body[span[1]] == "\n" else 0)
    indent = re.match(r"\s*", body[locs[0][0]:locs[0][1]]).group(0) if locs else "    "
    return span, locs, top, indent


def call_results_to_locals(body: str, name: str) -> List[Tuple[str, str]]:
    """A call nested in a larger expression held in a local first: the allocator numbers a
    declared local below every lowering temporary, so the value takes a different register
    (`n = f(); if (a > n - 1)` reproduced fn_1_DA6C's `extsb r4`)."""
    out: List[Tuple[str, str]] = []
    a = _decl_anchor(body, name)
    if not a:
        return out
    span, locs, top, indent = a
    protos = {m.group(2): m.group(1).strip() for m in re.finditer(
        r'(?m)^\s*(?:extern\s+)?(' + TYPE + r')\s*\b([A-Za-z_]\w*)\s*\([^;{]*\)\s*;', body[:span[0]])}
    inner = body[top:span[2]]
    k = 0
    per_callee: Dict[str, list] = {}
    for m in re.finditer(r"(?m)^([ \t]+)(?!return\b)([^\n;{}]*?)\b([A-Za-z_]\w*)\s*(\([^()]*\))([^\n;{]*)([;{])\n", inner):
        ind, before, callee, args, after, term = m.groups()
        after = after + term
        if callee in ('if', 'while', 'for', 'switch', 'sizeof', 'return') or callee == name:
            continue
        if not (before.strip() or after.strip()):
            continue  # a bare call statement or `x = f();` already carries its own register
        if re.fullmatch(r"\s*[A-Za-z_]\w*\s*=\s*", before) and not after.strip():
            continue
        head = re.sub(r'^\s*(if|while|switch)\s*\(', '', before)
        if head.count('(') != head.count(')'):
            continue
        k += 1
        tn = f"tmp_call{k}"
        typ = protos.get(callee, 's32')
        if typ == 'void':
            continue
        if '*' not in typ and typ not in ('u32', 'f32', 'f64', 'float', 'double', 'unsigned int', 'unsigned long'):
            typ = 's32'  # a narrow result widens once, into the local (retail's extsb after the call)
        s0 = top + m.start()
        stmt = f"{ind}{tn} = {callee}{args};\n{ind}{before}{tn}{after}\n"
        text = body[:s0] + stmt + body[top + m.end():]
        for label, pos in (("last", top), ("first", locs[0][0] if locs else top)):
            out.append((f"hold {callee} result in a local declared {label}",
                        text[:pos] + f"{indent}{declarator(typ, tn)};\n" + text[pos:]))
        per_callee.setdefault(callee, []).append((s0, top + m.end(), stmt.replace(tn, f"tmp_{callee}"), typ))
    # every site of one callee through the same reassigned local, and only the sites inside
    # conditions (fn_1_DA6C held the bound in a local for its two `if` tests, not the assignments)
    for callee, sites in per_callee.items():
        if len(sites) < 2:
            continue
        subsets = [("every", sites)]
        conds = [s for s in sites if re.match(r'\s*(if|while|for|else if)\b', s[2].split('\n')[1])]
        if 1 < len(conds) < len(sites):
            subsets.append(("condition", conds))
        for kind, chosen in subsets:
            text = body
            for s0, e0, stmt, typ in sorted(chosen, reverse=True):
                text = text[:s0] + stmt + text[e0:]
            for label, pos in (("last", top), ("first", locs[0][0] if locs else top)):
                out.append((f"hold {kind} {callee} result in one local declared {label}",
                            text[:pos] + f"{indent}{declarator(chosen[0][3], 'tmp_' + callee)};\n" + text[pos:]))
    return out


def wrap_constant_pointers(body: str, name: str) -> List[Tuple[str, str]]:
    """A pointer local holding a constant address is a rematerializable temporary numbered
    above every declared local; a one-member struct keeps it an ordinary local."""
    out: List[Tuple[str, str]] = []
    a = _decl_anchor(body, name)
    if not a:
        return out
    span, locs, top, indent = a
    globals_ = set(re.findall(r'(?m)^\s*extern\s+[^;(]*?\b([A-Za-z_]\w*)\s*(?:\[[^\]]*\])*\s*;', body[:span[0]]))
    inner = body[span[1]:span[2]]
    for s0, e0, typ, nm, dims in locs:
        if dims or '*' not in typ or typ.startswith('struct {'):
            continue
        init = _init_of(body[s0:e0])
        assigns = re.findall(r'(?m)^\s*' + re.escape(nm) + r'\s*=\s*([^;]+);', inner)
        values = ([init] if init else []) + assigns
        const_re = r'\(?\s*(?:\(' + TYPE + r'\)\s*)?&?\s*([A-Za-z_]\w*)(?:\s*\+\s*0x[0-9A-Fa-f]+|\s*\+\s*\d+)?\s*\)?'
        first = re.fullmatch(const_re, values[0].strip()) if values else None
        if not first or first.group(1) not in globals_:
            continue  # the first definition must be a constant address; later ones may vary
        decl_line = body[s0:e0]
        base_type = typ.rstrip('* ').strip()
        stars = typ.count('*')
        new_decl = f"{indent}struct {{ {base_type} {'*' * stars}value; }} {nm};\n"
        rest = body[e0:span[2]]
        rest = re.sub(r'\b' + re.escape(nm) + r'\b(?!\.value)', nm + '.value', rest)
        text = body[:s0] + new_decl + (f"{indent}{nm}.value = {init};\n" if init else "") + rest + body[span[2]:]
        if init:
            # the initializer becomes the first statement after the declarations
            text = body[:s0] + new_decl + rest + body[span[2]:]
            t2 = top - (e0 - s0) + len(new_decl)
            text = text[:t2] + f"{indent}{nm}.value = {init};\n" + text[t2:]
        out.append((f"struct-wrap constant pointer {nm}", text))
    return out


def decse_repeated_expressions(body: str, name: str) -> List[Tuple[str, str]]:
    """A repeated `x << k` / `x * k` computed once into a declared local used at every site:
    the compiler's own common-subexpression web is numbered above every local, a declared
    local is not (fn_12_2D888's offset)."""
    out: List[Tuple[str, str]] = []
    a = _decl_anchor(body, name)
    if not a:
        return out
    span, locs, top, indent = a
    inner = body[top:span[2]]
    exprs: Dict[str, List[int]] = {}
    for m in re.finditer(r'\(?(?<![*\w.>])\b([A-Za-z_]\w*)\s*(<<|\*)\s*(0x[0-9A-Fa-f]+|\d+)\b\)?', inner):
        key = f"{m.group(1)} {m.group(2)} {m.group(3)}"
        exprs.setdefault(key, []).append(m.start())
    # a repeated member-array base `((T *)(base + K))[i]`: retail keeps the base in a register
    # (`addi rB, base, K; lwzx`) where a per-site recompute folds K into the displacement
    for m in re.finditer(r'\(\(' + TYPE + r'\)\(([A-Za-z_]\w*) \+ (0x[0-9A-Fa-f]+|\d+)\)\)', inner):
        key = f"ptr {m.group(0)}"
        exprs.setdefault(key, []).append(m.start())
    k = 0
    for key, sites in exprs.items():
        if len(sites) < 2:
            continue
        k += 1
        tn = f"tmp_cse{k}"
        if key.startswith('ptr '):
            expr = key[4:]
            ptype = re.match(r'\(\((' + TYPE + r')\)', expr).group(1).strip()
            text = inner.replace(expr, tn)
            decl_type = ptype
            key = expr[1:-1]  # the value assigned: (T *)(base + K)
        else:
            var = key.split()[0]
            decl_type = 's32'
            text = re.sub(r'\(?\b' + re.escape(var) + r'\s*' + re.escape(key.split()[1]) + r'\s*' + re.escape(key.split()[2]) + r'\b\)?', tn, inner)
        stmt_start = max(inner.rfind(';\n', 0, sites[0]), inner.rfind('{\n', 0, sites[0]), inner.rfind('}\n', 0, sites[0]))
        first_line = stmt_start + 2 if stmt_start >= 0 else 0
        ind = re.match(r'[ \t]*', inner[first_line:]).group(0)
        # C89: the assignment goes after the declarations of the block; a declaration
        # initializer at the first site is split into declaration and assignment
        lines = text[first_line:].split('\n')
        pending = []
        j = 0
        while j < len(lines):
            dm = DECL_RE.match(lines[j])
            if not dm or dm.group(1).strip() in ('return', 'goto', 'break', 'continue'):
                break
            if dm.group(4):
                lines[j] = f"{ind}{declarator(dm.group(1).strip(), dm.group(2) + dm.group(3))};"
                pending.append(f"{ind}{dm.group(2)} = {dm.group(4).strip()};")
            j += 1
        lines[j:j] = [f"{ind}{tn} = {key};"] + pending
        text = text[:first_line] + '\n'.join(lines)
        for label, pos in (("last", top), ("first", locs[0][0] if locs else top)):
            full = body[:top] + text + body[span[2]:]
            out.append((f"de-CSE {key} into a local declared {label}",
                        full[:pos] + f"{indent}{declarator(decl_type, tn)};\n" + full[pos:]))
    return out



SCALAR_TYPES = {'s8', 'u8', 's16', 'u16', 's32', 'u32', 'int', 'long', 'short', 'char', 'unsigned',
                'unsigned int', 'unsigned long', 'unsigned short', 'unsigned char', 'BOOL', 'f32', 'f64', 'float', 'double'}


def scalar_carriers(body: str, name: str) -> List[Tuple[str, str]]:
    """A scalar local wrapped in a one-member struct: the aggregate is numbered in the
    frontend's promotion stratum above strength-reduced induction variables and CSE temps,
    so its web claims a callee-saved register ahead of them (measured on mwcceppc: a stored
    carrier also owns a 4-byte frame home under 1.2.5n)."""
    out: List[Tuple[str, str]] = []
    a = _decl_anchor(body, name)
    if not a:
        return out
    span, locs, top, indent = a
    for s0, e0, typ, nm, dims in locs:
        base = re.sub(r'\b(register|const|volatile)\b', '', typ).strip()
        if dims or '*' in base or base not in SCALAR_TYPES or _init_of(body[s0:e0]):
            continue
        rest = body[e0:span[2]]
        if not re.search(r'\b' + re.escape(nm) + r'\b', rest):
            continue
        rest = re.sub(r'\b' + re.escape(nm) + r'\b(?!\.value)', nm + '.value', rest)
        out.append((f"one-field carrier {nm}", body[:s0] + f"{indent}struct {{ {base} value; }} {nm};\n" + rest + body[span[2]:]))
    return out


def dead_uses(body: str, name: str) -> List[Tuple[str, str]]:
    """`(void) x;` after a definition: a statement-level use that keeps the value's web
    where the definition put it (no code is emitted)."""
    out: List[Tuple[str, str]] = []
    a = _decl_anchor(body, name)
    if not a:
        return out
    span, locs, top, indent = a
    names = [l[3] for l in locs if not l[4]][:12]
    inner = body[top:span[2]]
    for nm in names:
        for m in re.finditer(r'(?m)^([ \t]+)' + re.escape(nm) + r'(?:\.value)?\s*=[^=][^;\n]*;\n', inner):
            s = top + m.end()
            out.append((f"dead use of {nm} after its definition",
                        body[:s] + f"{m.group(1)}(void) {nm};  /* fzgx: keeps the web at its definition */\n" + body[s:]))
    return out


def variable_splits(body: str, name: str) -> List[Tuple[str, str]]:
    """A local assigned in two regions split into two locals, the second declared last:
    a second assignment otherwise creates a rename web numbered above every named local."""
    out: List[Tuple[str, str]] = []
    a = _decl_anchor(body, name)
    if not a:
        return out
    span, locs, top, indent = a
    inner = body[top:span[2]]
    for s0, e0, typ, nm, dims in locs:
        if dims:
            continue
        defs = [m for m in re.finditer(r'(?m)^[ \t]+' + re.escape(nm) + r'\s*=[^=]', inner)]
        if len(defs) < 2:
            continue
        # split at the second and at the last definition: a reassigned local's later webs are
        # numbered above every declared local, a fresh local declared at position P is not
        # (fn_8003043C: the late result declared right after base takes r26 after base)
        cuts = {defs[1].start(), defs[-1].start()}
        for cut in sorted(cuts):
            tail = re.sub(r'\b' + re.escape(nm) + r'\b', nm + '_2', inner[cut:])
            text = body[:top] + inner[:cut] + tail + body[span[2]:]
            positions = [("last", top)] + [(f"after {l[3]}", l[1]) for l in locs]
            for label, pos in positions:
                out.append((f"split {nm} at definition {sorted(cuts).index(cut) + 1}, {nm}_2 declared {label}",
                            text[:pos] + f"{indent}{declarator(typ.strip(), nm + '_2' + dims)};\n" + text[pos:]))
    return out



SIGN_FLIP = {'s32': 'u32', 'u32': 's32', 'int': 'u32', 's16': 'u16', 'u16': 's16', 's8': 'u8', 'u8': 's8'}


def signedness_flips(body: str, name: str) -> List[Tuple[str, str]]:
    """A local's signedness flipped: `cmpwi` against `cmplwi`, `srawi` against `srwi`,
    `extsh` against `clrlwi` are decided by the declared type, not the value."""
    out: List[Tuple[str, str]] = []
    a = _decl_anchor(body, name)
    if not a:
        return out
    span, locs, top, indent = a
    narrow = []
    for s0, e0, typ, nm, dims in locs:
        base = typ.strip()
        if base not in SIGN_FLIP:
            continue
        line = body[s0:e0]
        new_line = re.sub(r'\b' + re.escape(base) + r'\b', SIGN_FLIP[base], line, count=1)
        out.append((f"{nm}: {base} -> {SIGN_FLIP[base]}", body[:s0] + new_line + body[e0:]))
        if base in ('u8', 's8', 'u16', 's16'):
            # a byte/halfword local kept in a register is truncated at every compare and
            # argument (`clrlwi`); retail's untruncated form is a 32-bit local (fn_80076CD4)
            wide = 's32' if base[0] == 's' else 'u32'
            out.append((f"{nm}: {base} -> {wide}", body[:s0] + re.sub(r'\b' + re.escape(base) + r'\b', wide, line, count=1) + body[e0:]))
            out.append((f"{nm}: {base} -> s32", body[:s0] + re.sub(r'\b' + re.escape(base) + r'\b', 's32', line, count=1) + body[e0:]))
            narrow.append((s0, e0, base, line))
    if len(narrow) > 1:
        text = body
        for s0, e0, base, line in sorted(narrow, reverse=True):
            text = text[:s0] + re.sub(r'\b' + re.escape(base) + r'\b', 's32', line, count=1) + text[e0:]
        out.append(("every byte/halfword local -> s32", text))
    return out


def float_precision(body: str, name: str) -> List[Tuple[str, str]]:
    """Single against double arithmetic: an unsuffixed literal in a float expression promotes
    to double (`fsub` where retail has `fsubs`), and an `f64` local keeps a double temp where
    retail computed in single precision; try the literal suffixes and f32 locals."""
    out: List[Tuple[str, str]] = []
    a = _decl_anchor(body, name)
    if not a:
        return out
    span, locs, top, indent = a
    inner = body[span[1]:span[2]]
    lits = list(re.finditer(r'(?<![\w.])(\d+\.\d*|\.\d+)(?:[eE][+-]?\d+)?(?![\w.])', inner))
    if lits:
        text = inner
        for m in reversed(lits):
            text = text[:m.end()] + 'f' + text[m.end():]
        out.append(("float literal suffixes at every site", body[:span[1]] + text + body[span[2]:]))
        for m in lits[:8]:
            out.append((f"float literal suffix at {m.group(0)}", body[:span[1]] + inner[:m.end()] + 'f' + inner[m.end():] + body[span[2]:]))
    for s0, e0, typ, nm, dims in locs:
        if typ.strip() in ('f64', 'double'):
            line = body[s0:e0]
            out.append((f"{nm}: f64 -> f32", body[:s0] + re.sub(r'\b(f64|double)\b', 'f32', line, count=1) + body[e0:]))
            cast = re.sub(r'\(f64\)\s*', '', body[e0:span[2]])
            out.append((f"{nm}: f64 -> f32 without double casts", body[:s0] + re.sub(r'\b(f64|double)\b', 'f32', line, count=1) + cast + body[span[2]:]))
    return out


_FLOAT_LIT = re.compile(r'(?<![\w.])(\d+\.\d*(?:[eE][+-]?\d+)?|\.\d+(?:[eE][+-]?\d+)?|\d+[eE][+-]?\d+)([fF]?)(?![\w.])')
_CAST_RE = re.compile(r'\(\s*(?:const\s+)?(?:[us](?:8|16|32|64)|f32|f64|float|double|int|unsigned(?:\s+int)?|long|short|char)\s*\)\s*')


def _reciprocal_power(token: str) -> Optional[int]:
    """n when the literal is exactly 2^-n (n >= 1), else None."""
    try:
        v = float(token)
    except ValueError:
        return None
    if not 0.0 < v < 1.0:
        return None
    mant, exp = math.frexp(v)
    return 1 - exp if mant == 0.5 and 1 - exp <= 40 else None


def _unary_end(code: str, i: int, stop: int) -> Optional[int]:
    """End of the unary (cast) expression starting at i, or None when it cannot be delimited."""
    n = stop
    while i < n and code[i].isspace():
        i += 1
    while True:
        m = _CAST_RE.match(code, i, n)
        if m:
            i = m.end(); continue
        if i < n and code[i] in '-+!~' and code[i:i + 2] not in ('--', '++'):
            i += 1
            while i < n and code[i].isspace():
                i += 1
            continue
        break
    if i >= n:
        return None
    if code[i] == '(':
        j = _close(code, i, n)
        if j is None:
            return None
        i = j
    else:
        m = re.compile(r'[A-Za-z_]\w*|\d+\.\d*(?:[eE][+-]?\d+)?[fF]?|\.\d+(?:[eE][+-]?\d+)?[fF]?|0[xX][0-9a-fA-F]+[uUlL]*|\d+[uUlL]*').match(code, i, n)
        if not m:
            return None
        i = m.end()
    while i < n:
        m = re.compile(r'\s*(?:\.|->)\s*[A-Za-z_]\w*').match(code, i, n)
        if m:
            i = m.end(); continue
        m = re.compile(r'\s*[\[(]').match(code, i, n)
        if m:
            j = _close(code, m.end() - 1, n)
            if j is None:
                return None
            i = j; continue
        break
    return i


def _close(code: str, i: int, n: int) -> Optional[int]:
    """Index after the bracket matching code[i]."""
    pairs = {'(': ')', '[': ']'}
    want = [pairs[code[i]]]
    j = i + 1
    while j < n and want:
        c = code[j]
        if c in pairs:
            want.append(pairs[c])
        elif c in ')]':
            if c != want.pop():
                return None
        j += 1
    return j if not want else None


def reciprocal_divisions(body: str, name: str) -> List[Tuple[str, str]]:
    """A multiply by an exact power-of-two reciprocal written as the division retail used.

    MWCC strength-reduces `x / 2.0f` to a multiply by 0.5f with the variable as the FIRST
    `fmuls` operand; `0.5f * x` (and, after operand canonicalisation, often `x * 0.5f`) puts the
    constant first. Measured in fn_16_2EEC, fn_1_535A0 (`/ 8.0f`), fn_1_130C84 (`/ 4.0f`),
    fn_1_13DDB8 and fn_10_D5D4 (2026-10-12). One candidate per site and one with every site."""
    out: List[Tuple[str, str]] = []
    span = _function_body_span(body, name)
    if not span:
        return out
    from .sdkimport import masked
    code = masked(body)
    lo, hi = span[1], span[2]
    edits_: List[Tuple[int, int, str, str]] = []
    for m in _FLOAT_LIT.finditer(code, lo, hi):
        n = _reciprocal_power(m.group(1))
        if n is None:
            continue
        divisor = f"{2 ** n}.0{m.group(2)}"
        # e * c / e *= c: `*` and `/` share precedence and associativity, so only the
        # operator and the literal change (`*=` only when the literal is the whole operand)
        pm = re.search(r'\*(=?)\s*$', code[lo:m.start()])
        whole_rhs = re.match(r'\s*[;,)]', code[m.end():hi])
        if pm and (not pm.group(1) or whole_rhs) and not re.search(r'[*/%(,=?:&|^<>!~+-]\s*\*=?\s*$', code[lo:m.start()]):
            a = lo + pm.start()
            edits_.append((a, m.end(), f"/{pm.group(1)} {divisor}", f"{m.group(0)} -> / {divisor}"))
            continue
        # c * e at the head of its multiplicative chain
        nm = re.compile(r'\s*\*(?!=)').match(code, m.end(), hi)
        before = code[lo:m.start()].rstrip()
        if not nm or not before or before[-1] in '*/%)' or before.endswith(('++', '--')):
            continue
        end = _unary_end(code, nm.end(), hi)
        if end is None:
            continue
        operand = body[nm.end():end].strip()
        if not operand:
            continue
        edits_.append((m.start(), end, f"{operand} / {divisor}", f"{m.group(0)} * {operand[:24]} -> / {divisor}"))
    if not edits_:
        return out
    for a, b, new, label in edits_[:16]:
        out.append((f"reciprocal divide {label}", body[:a] + new + body[b:]))
    if len(edits_) > 1:
        text, last = body, None
        for a, b, new, _ in sorted(edits_, reverse=True):
            if last is not None and b > last:
                continue
            text, last = text[:a] + new + text[b:], a
        out.append(("reciprocal divide at every site", text))
    return out


_SIMPLE_OPERAND = re.compile(r'-?(?:\d+\.\d*(?:[eE][+-]?\d+)?[fF]?|\.\d+(?:[eE][+-]?\d+)?[fF]?|\d+[eE][+-]?\d+[fF]?|0[xX][0-9a-fA-F]+[uUlL]*|\d+[uUlL]*|[A-Za-z_]\w*)')
_ASSIGN_STMT = re.compile(r'^([ \t]*)(?:(' + TYPE + r')\s+)?([A-Za-z_]\w*)\s*=\s*([^;=]+?);[ \t]*$', re.M)
_COMPOUND_STMT = re.compile(r'^[ \t]*([A-Za-z_]\w*)\s*([-+*/])=\s*([^;]+?);[ \t]*$', re.M)


def _top_binary_split(expr: str) -> Optional[Tuple[str, str, str]]:
    """(left, op, right) at the LAST top-level `+ - * /` of `expr` whose right operand is one
    simple token; None when the expression has no such split (unary signs are not splits)."""
    depth = 0
    last = None
    for i, ch in enumerate(expr):
        if ch in '([':
            depth += 1
        elif ch in ')]':
            depth -= 1
        elif depth == 0 and ch in '+-*/' and i > 0:
            prev = expr[:i].rstrip()
            if (not prev or prev[-1] in '+-*/%=<>!&|^~?:,(' or expr[i - 1:i + 1] in ('->', '++', '--')
                    or expr[i:i + 2] in ('++', '--', '->')):
                continue
            last = i
    if last is None:
        return None
    left, op, right = expr[:last].rstrip(), expr[last], expr[last + 1:].strip()
    if not left or not _SIMPLE_OPERAND.fullmatch(right):
        return None
    return left, op, right


def _strip_float_wrap(expr: str) -> str:
    """`(f32)(E)` -> E: the single-precision cast an f32 lvalue implies anyway."""
    m = re.fullmatch(r'\(\s*(?:f32|float)\s*\)\s*(\(.*\))', expr, re.S)
    if m and _close(m.group(1), 0, len(m.group(1))) == len(m.group(1)):
        return m.group(1)[1:-1].strip()
    return expr


def _is_value_load(expr: str) -> bool:
    """A load, call or plain variable (what lands in the assigned web), not arithmetic."""
    if re.fullmatch(r'[A-Za-z_]\w*', expr):
        return True
    if expr[0] in '-!~' or not re.search(r'\w\s*\(|\*\s*\(|\[|\w\.\w|->', expr):
        return False
    depth = 0
    for i, ch in enumerate(expr):
        if ch in '([':
            depth += 1
        elif ch in ')]':
            depth -= 1
        elif depth == 0 and ch in '+-*/%&|^<>?' and i > 0 and expr[i - 1:i + 1] not in ('->',) and expr[i:i + 2] != '->':
            return False
    return True


def compound_assignments(body: str, name: str) -> List[Tuple[str, str]]:
    """Temporary-numbering idioms of a float local written as one in-place web.

    `v = (f32)(v + 1.0f)` after an if/else join splits `v` into a new copy-region web (an
    extra register and `fmr`); `v += 1.0f` keeps the one web (fn_1_14F6F8, 2005b0b7).
    `v = load - K` computes into a temporary and copies; `v = load; v -= K;` lands the reload
    in v's web (same function). `half = (f32)x; half *= 0.5f;` keeps the conversion in its own
    temporary where retail converts inside the strength-reduced `x / 2.0f` (fn_10_DAF8,
    842cb4be). One candidate per site and one with every compatible site."""
    out: List[Tuple[str, str]] = []
    span = _function_body_span(body, name)
    if not span:
        return out
    from .sdkimport import masked
    code = masked(body)
    lo, hi = span[1], span[2]
    edits_: List[Tuple[int, int, str, str]] = []
    for m in _ASSIGN_STMT.finditer(code, lo, hi):
        if m.end() > hi:
            break
        indent, typ, var = m.group(1), m.group(2), m.group(3)
        rhs = body[m.start(4):m.end(4)].strip()
        uses_var = re.compile(rf'\b{re.escape(var)}\b')
        split = _top_binary_split(_strip_float_wrap(rhs))
        if split and not typ:
            left, op, right = split
            if left == var:
                edits_.append((m.start(), m.end(), f"{indent}{var} {op}= {right};", f"{var} {op}= {right}"))
                continue
            if op in '+-' and not uses_var.search(left) and _is_value_load(left):
                edits_.append((m.start(), m.end(), f"{indent}{var} = {left};\n{indent}{var} {op}= {right};",
                               f"{var} = {left[:24]}; {var} {op}= {right}"))
                continue
        cm = re.fullmatch(r'\(\s*(?:f32|float)\s*\)\s*(.+)', rhs, re.S)
        nxt = _COMPOUND_STMT.match(code, m.end() + 1) if m.end() + 1 < hi else None
        if cm and nxt and nxt.end() <= hi and nxt.group(1) == var and _SIMPLE_OPERAND.fullmatch(nxt.group(3).strip()):
            src, op, k = cm.group(1).strip(), nxt.group(2), nxt.group(3).strip()
            if uses_var.search(src):
                continue
            head = f"{indent}{typ + ' ' if typ else ''}{var} = "
            lit = _FLOAT_LIT.fullmatch(k)
            n = _reciprocal_power(lit.group(1)) if lit and op == '*' else None
            if n is not None:
                edits_.append((m.start(), nxt.end(), f"{head}{src} / {2 ** n}.0{lit.group(2)};",
                               f"{var} = {src[:24]} / {2 ** n}.0{lit.group(2)}"))
            else:
                edits_.append((m.start(), nxt.end(), f"{head}{src} {op} {k};", f"{var} = {src[:24]} {op} {k}"))
    if not edits_:
        return out
    for a, b, new, label in edits_[:16]:
        out.append((f"compound assignment {label}", body[:a] + new + body[b:]))
    if len(edits_) > 1:
        text, last = body, None
        for a, b, new, _ in sorted(edits_, reverse=True):
            if last is not None and b > last:
                continue
            text, last = text[:a] + new + text[b:], a
        out.append(("compound assignment at every site", text))
    return out


_CONST_RE = r'-?\s*(?:0[xX][0-9a-fA-F]+[uUlL]*|\d+\.\d*(?:[eE][+-]?\d+)?[fF]?|\.\d+(?:[eE][+-]?\d+)?[fF]?|\d+[uUlL]*)'


def constant_inline_parameters(body: str, name: str) -> List[Tuple[str, str]]:
    """A local set to a constant turned into an inlined helper's parameter.

    MWCC propagates a constant local into every use (`li` per consumer), but an inlined
    static helper's parameter stays a variable: retail's `li rA, K; mr rB, rA` (and constant
    copies into callee-saved locals) come from `helper(K)`. Measured: fn_10_AB98 (`step = 0`
    became `sel_move_cursor(cursor, 0)`), fn_3_3F20 (`dir = init; delta = dir;` inside a helper
    called with 0), fn_80057494. Variants: the local itself is the parameter, or the local is
    assigned from it; the helper holds the whole body, or only the code from the constant
    assignment on (statements before it stay in the caller when they use no local)."""
    out: List[Tuple[str, str]] = []
    span = _function_body_span(body, name)
    if not span:
        return out
    from .sdkimport import masked
    code = masked(body)
    head_start = max(code.rfind('\n', 0, span[0]), code.rfind(';', 0, span[0]), code.rfind('}', 0, span[0])) + 1
    ret = code[head_start:span[0]].strip()
    ret = re.sub(r'\b(?:static|inline|extern|__inline)\b\s*', '', ret).strip()
    if not ret or not re.fullmatch(TYPE, ret) or '#' in ret:
        return out
    void = ret == 'void'
    popen = code.index('(', span[0])
    pclose = code.rfind(')', popen, span[1])
    params = body[popen + 1:pclose].strip()
    if '(' in params or '...' in params or '/*' in params:
        return out
    pnames: List[str] = []
    if params and params != 'void':
        for prm in params.split(','):
            pm = re.search(r'([A-Za-z_]\w*)\s*(?:\[[^\]]*\]\s*)*$', prm.strip())
            if not pm:
                return out
            pnames.append(pm.group(1))
    locs = _locals(body, span)
    top = locs[-1][1] if locs else span[1]
    stmts = _top_statements(code[top:span[2]])
    if not stmts:
        return out
    stmts = [(top + a, top + b) for a, b in stmts]
    lnames = [nm for _, _, _, nm, _ in locs]
    helper = f"{name}_fzgx_inl"
    if re.search(rf'\b{helper}\b', body):
        return out
    indent = '    '
    tried = 0
    for li, (s0, e0, typ, k, dims) in enumerate(locs):
        if tried >= 4:
            break
        if dims or not re.fullmatch(r'(?:[us](?:8|16|32)|f32|f64|int|char|short|long|float|double|BOOL|bool)', typ.strip()):
            continue
        dm = DECL_RE.match(body[s0:e0].rstrip('\n'))
        init = dm.group(4).strip() if dm and dm.group(4) else None
        first = re.search(rf'\b{re.escape(k)}\b', code[top:span[2]])
        if init is not None:
            if not re.fullmatch(_CONST_RE, init):
                continue
            const, at = init, None
        else:
            if not first:
                continue
            pos = top + first.start()
            at = next((i for i, (a, b) in enumerate(stmts) if a == pos), None)
            if at is None:
                continue
            am = re.fullmatch(rf'{re.escape(k)}\s*=\s*({_CONST_RE})\s*;', code[stmts[at][0]:stmts[at][1]])
            if not am:
                continue
            const = am.group(1)
        tried += 1
        const = re.sub(r'\s+', '', const)
        decls_wo = ''.join(body[a:b] for j, (a, b, *_r) in enumerate(locs) if j != li)
        decls_all = ''.join(body[a:b] for a, b, *_r in locs)
        if init is not None:
            decls_all = decls_all.replace(body[s0:e0], f"{indent}{typ} {k};\n", 1)
        split = 0 if at is None else at
        prefix = code[stmts[0][0]:stmts[split][0]] if stmts and split else ''
        placements = [('whole body', 0)]
        if split and not any(re.search(rf'\b{re.escape(v)}\b', prefix) for v in lnames):
            placements.append(('from the assignment', split))
        for variant in ('parameter is the local', 'parameter assigns the local'):
            for place, cut in placements:
                rest_start = stmts[cut][0]
                rest = body[rest_start:span[2]]
                if variant == 'parameter is the local':
                    pdecl, decls = f"{typ.strip()} {k}", decls_wo
                    if at is not None:
                        a, b = stmts[at]
                        lead = body.rfind('\n', 0, a) + 1
                        cut_end = b + 1 if body[b:b + 1] == '\n' else b
                        rest = body[rest_start:lead] + body[cut_end:span[2]] if lead >= rest_start else body[rest_start:a] + body[b:span[2]]
                else:
                    pdecl, decls = f"{typ.strip()} fzgx_init", decls_all
                    if at is not None:
                        a, b = stmts[at]
                        rest = body[rest_start:a] + f"{k} = fzgx_init;" + body[b:span[2]]
                    else:
                        rest = f"{k} = fzgx_init;\n{indent}" + rest
                hparams = ', '.join(([params] if pnames else []) + [pdecl])
                hdef = (f"static inline {ret} {helper}({hparams}) {{\n" + decls
                        + ('\n' if decls else '') + indent + rest.lstrip() + "}\n\n")
                call = f"{'' if void else 'return '}{helper}({', '.join(pnames + [const])});"
                keep = body[stmts[0][0]:rest_start].rstrip() if cut else ''
                outer = "\n" + (indent + keep + "\n" if keep else '') + indent + call + "\n"
                text = body[:head_start] + ('\n' if head_start and body[head_start - 1] != '\n' else '') + hdef \
                    + body[head_start:span[1]] + outer + body[span[2]:]
                out.append((f"{k} = {const}: {variant}, {place}", text))
    return out


_REGION_SCALAR = re.compile(r'(?:(?:register|const|volatile)\s+)*(?:[us](?:8|16|32)|f32|f64|int|char|short|long|'
                            r'float|double|BOOL|bool|unsigned(?:\s+(?:int|char|short|long))?)\s*|.*\*\s*')


def _region_refs(code: str, var: str):
    """Occurrences of a variable (member names `.v`/`->v` excluded)."""
    return [m.start() for m in re.finditer(rf'(?<![\w.])(?<!->)\b{re.escape(var)}\b', code)]


def _region_defines_first(code: str, var: str) -> bool:
    """The first occurrence of var in code is the target of a plain assignment that does not
    read var (`v = expr;`, `a = v = 0;`)."""
    refs = _region_refs(code, var)
    if not refs:
        return False
    m = re.match(r'\s*=(?!=)', code[refs[0] + len(var):])
    if not m:
        return False
    end = code.find(';', refs[0])
    return not any(r < end for r in refs[1:]) if end >= 0 else False


def region_inline_helpers(body: str, name: str) -> List[Tuple[str, str]]:
    """Two locals holding the same constant moved, with the statements around them, into an
    inlined static helper.

    MWCC's second value-numbering pass (ValueNumbering.c, `PC_LI` case) only numbers a `li`
    whose destination lies in the coalesce window: compiler temporaries, which include the
    locals and parameters of an inlined function (CodeGen.c, `@`-named objects allocated after
    `Registers_BeginCoalesceWindow`). Two such temporaries loaded with one constant become
    `li rA, K; mr rB, rA`, and the copy survives coalescing when both are modified later.
    Declared locals of the function itself never take part, so every spelling of
    `a = 0; b = a;` in the caller folds to two `li`. Measured on mwcceppc 1.3.2 (probe
    compiles, fn_4_A0C `li r29,0; mr r27,r29` for a strength-reduced counter, fn_1_C24A4
    `li r4,0; mr r5,r4; ori r0,r4,1`). A whole-body helper is no answer for large functions:
    MWCC's default `inline_max_size` leaves it out of line. The helper therefore spans only the
    top-level statements from the constant assignment to the last use of the pair, receives
    the outer values it reads by value and returns the one outer variable it defines; locals
    used only there (or dead on entry and exit) move inside. Inlined locals are numbered in
    the opposite order to declared locals, so the reversed declaration order is tried too."""
    out: List[Tuple[str, str]] = []
    split = split_declaration_groups(body, name)
    if split:
        body = split[0][1]
    span = _function_body_span(body, name)
    if not span:
        return out
    from .sdkimport import masked
    code = masked(body)
    head_start = max(code.rfind('\n', 0, span[0]), code.rfind(';', 0, span[0]), code.rfind('}', 0, span[0])) + 1
    helper = f"{name}_fzgx_region"
    if re.search(rf'\b{helper}\b', body):
        return out
    popen = code.index('(', span[0])
    pclose = code.rfind(')', popen, span[1])
    params = body[popen + 1:pclose].strip()
    ptypes: Dict[str, str] = {}
    if params and params != 'void':
        if '(' in params or '...' in params:
            return out
        for prm in params.split(','):
            pm = re.fullmatch(r'\s*(.*?)\s*\b([A-Za-z_]\w*)\s*', prm)
            if not pm or '[' in prm:
                return out
            ptypes[pm.group(2)] = pm.group(1)
    raw = _top_statements(code[span[1] + 1:span[2]])
    if not raw:
        return out
    base = span[1] + 1
    stmts: List[Tuple[int, int]] = []
    for a, b in raw:
        a, b = base + a, base + b
        # `struct { ... } name;` splits into the braced part and `name;`
        if stmts and re.fullmatch(r'\s*[A-Za-z_]\w*(?:\[[^\]]*\])*\s*;', code[a:b]) and \
                re.match(r'\s*(?:struct|union)\b', code[stmts[-1][0]:stmts[-1][1]]) and code[stmts[-1][1] - 1] == '}':
            stmts[-1] = (stmts[-1][0], b)
            continue
        stmts.append((a, b))
    # leading declarations: (stmt index, type, name, dims, initializer)
    decls: Dict[str, Tuple[int, str, str, Optional[str]]] = {}
    first = 0
    for i, (a, b) in enumerate(stmts):
        text = ' '.join(code[a:b].split())
        dm = DECL_RE.match(text)
        if dm and dm.group(1).strip() not in ('return', 'goto', 'else'):
            decls[dm.group(2)] = (i, dm.group(1).strip(), dm.group(3) or '', dm.group(4))
            first = i + 1
            continue
        am = re.fullmatch(r'((?:struct|union)\s*(?:\w+\s*)?\{.*\})\s*([A-Za-z_]\w*)((?:\[[^\]]*\])*)\s*;', text)
        if am:
            decls[am.group(2)] = (i, am.group(1), am.group(3), None)
            first = i + 1
            continue
        break
    body_stmts = list(range(first, len(stmts)))
    if not body_stmts:
        return out
    variables = {v: t for v, (_, t, d, _) in decls.items()}
    variables.update(ptypes)

    def stext(i):
        return code[stmts[i][0]:stmts[i][1]]

    # constant pairs: `b = a` after `a = K`, `a = b = K`, `a = K; b = K` in neighbouring statements
    pairs: List[Tuple[str, str]] = []
    inner = code[stmts[first][0]:span[2]] if first < len(stmts) else ''
    scal = [v for v, (_, t, d, _) in decls.items() if not d and re.fullmatch(_REGION_SCALAR, t)]
    for m in re.finditer(r'(?<![\w.>])([A-Za-z_]\w*)\s*=\s*([A-Za-z_]\w*)\s*=\s*(' + _CONST_RE + r')\s*;', inner):
        if m.group(1) in scal and m.group(2) in scal:
            pairs.append((m.group(2), m.group(1), m.start()))
    for m in re.finditer(r'(?<![\w.>])([A-Za-z_]\w*)\s*=\s*([A-Za-z_]\w*)\s*;', inner):
        b_, a_ = m.groups()
        if b_ not in scal or a_ not in scal or a_ == b_:
            continue
        before = inner[:m.start()]
        refs = _region_refs(before, a_)
        if refs and re.match(r'\s*=\s*(' + _CONST_RE + r')\s*;', before[refs[-1] + len(a_):]):
            pairs.append((a_, b_, refs[-1]))
    consts = [(m.start(), m.group(1), re.sub(r'\s+', '', m.group(2)))
              for m in re.finditer(r'(?<![\w.>])([A-Za-z_]\w*)\s*=\s*(' + _CONST_RE + r')\s*;', inner)
              if m.group(1) in scal]
    for (p0, v0, k0), (p1, v1, k1) in zip(consts, consts[1:]):
        if v0 != v1 and k0 == k1 and not re.search(r'[{}]', inner[p0:p1]) and inner[p0:p1].count(';') <= 4:
            pairs.append((v0, v1, p0))
    seen = set()
    pairs = [p for p in pairs if not (frozenset(p[:2]) in seen or seen.add(frozenset(p[:2])))][:3]
    indent = '    '
    origin = stmts[first][0]
    for a_, b_, at in pairs:
        refstmts = [i for i in body_stmts if _region_refs(stext(i), a_) or _region_refs(stext(i), b_)]
        start = next((i for i in body_stmts if stmts[i][0] <= origin + at < stmts[i][1]), None)
        if start is None:
            continue
        later = [i for i in refstmts if i >= start]
        for end in sorted(later, reverse=True):
            built = _region_helper(body, code, name, helper, stmts, body_stmts, decls, variables, head_start,
                                   span, start, end, indent)
            if built is None:
                continue
            for label, text in built:
                # a region past MWCC's default inline_max_size stays a call (16 of 109 region
                # candidates over the 80%+ saved bodies, 2026-10-28) unless the caller carries the pragma
                sized = inline_size_pragmas(text, name)
                out.append((f"{a_}/{b_}: statements {start - first}..{end - first} inlined{label}",
                            sized[0][1] if sized else text))
            break
    return out


def _region_helper(body, code, name, helper, stmts, body_stmts, decls, variables, head_start, span,
                   start, end, indent):
    """Texts with statements start..end of a function moved into an inlined helper, or None
    when the region cannot be expressed (returns, labels, two live-out variables, aggregates
    passed out, address-taken outer variables)."""
    region_code = code[stmts[start][0]:stmts[end][1]]
    if re.search(r'\breturn\b|\bgoto\b|^\s*[A-Za-z_]\w*\s*:(?!:)|\bcase\b|\bdefault\s*:|__asm|\basm\b',
                 region_code, re.M):
        return None
    if re.search(r'\b(?:break|continue)\b', region_code) and '{' not in region_code:
        return None

    def absorbed(lo):
        """Extend the region backwards over plain definitions of variables used only there."""
        while lo - 1 >= body_stmts[0]:
            prev = code[stmts[lo - 1][0]:stmts[lo - 1][1]]
            pm = re.fullmatch(r'\s*([A-Za-z_]\w*)\s*=(?!=)([^;]*);\s*', prev)
            if not pm or pm.group(1) not in decls:
                break
            v = pm.group(1)
            if _region_refs(pm.group(2), v):
                break
            outside = [i for i in body_stmts if (i < lo - 1 or i > end) and _region_refs(code[stmts[i][0]:stmts[i][1]], v)]
            if outside:
                break
            lo -= 1
        return lo

    results = []
    starts = [start]
    wider = absorbed(start)
    if wider != start:
        starts.append(wider)
    for lo in starts:
        built = _region_text(body, code, name, helper, stmts, body_stmts, decls, variables, head_start, span,
                             lo, end, indent)
        if built is None:
            continue
        for label, text in built:
            results.append(((' (preceding definitions included)' if lo != start else '') + label, text))
    return results or None


def _region_text(body, code, name, helper, stmts, body_stmts, decls, variables, head_start, span,
                 lo, hi, indent):
    region_code = code[stmts[lo][0]:stmts[hi][1]]
    before = ''.join(code[stmts[i][0]:stmts[i][1]] + ';' for i in body_stmts if i < lo)
    after_ids = [i for i in body_stmts if i > hi]
    after = ''.join(code[stmts[i][0]:stmts[i][1]] + ';' for i in after_ids)
    used = [v for v in variables if _region_refs(region_code, v)]
    used.sort(key=lambda v: _region_refs(region_code, v)[0])
    inside, inputs, output = [], [], None
    for v in used:
        typ = variables[v]
        dims = decls[v][2] if v in decls else ''
        assigned = bool(re.search(rf'(?<![\w.])(?<!->)\b{re.escape(v)}\s*(?:[-+*/%&|^]|<<|>>)?=(?!=)|'
                                  rf'(?:\+\+|--)\s*\b{re.escape(v)}\b|(?<![\w.])(?<!->)\b{re.escape(v)}\s*(?:\+\+|--)|'
                                  rf'&\s*\b{re.escape(v)}\b', region_code)) or bool(dims)
        in_before = bool(_region_refs(before, v))
        in_after = bool(_region_refs(after, v))
        is_param = v not in decls
        init = decls[v][3] if v in decls else None
        dead_in = (not in_before and not is_param and init is None) or _region_defines_first(region_code, v)
        dead_out = not in_after or _region_defines_first(after, v)
        if v in decls and dead_in and dead_out:
            inside.append(v)
            continue
        if v in decls and not in_before and not in_after:
            inside.append(v)  # used only here: its declaration (and initializer) moves inside
            continue
        if not assigned:
            if dims or re.search(r'\b(?:struct|union)\b', typ) and '*' not in typ:
                return None
            inputs.append(v)
            continue
        if output is not None or dims or (re.search(r'\b(?:struct|union)\b', typ) and '*' not in typ):
            return None
        if re.search(rf'&\s*\b{re.escape(v)}\b', region_code):
            return None
        output = v
        if not dead_in:
            inputs.append(v)
    if output is None and not inside:
        return None
    rtype = variables[output] if output else 'void'
    hparams = ', '.join(f"{variables[v]} {v}" for v in inputs) or 'void'
    args = ', '.join(inputs)
    region_text = body[stmts[lo][0]:stmts[hi][1]]
    decl_lines = {}
    for v in inside:
        i = decls[v][0]
        text = body[stmts[i][0]:stmts[i][1]].strip()
        decl_lines[v] = indent + text + "\n"
    if output and output not in inputs:
        decl_lines.setdefault(output, f"{indent}{variables[output]} {output};\n")
    order = [v for v in sorted(decl_lines, key=lambda v: decls[v][0] if v in decls else -1)]
    call = f"{output} = {helper}({args});" if output else f"{helper}({args});"
    # the outer function: region replaced by the call, declarations used nowhere else dropped
    drop = []
    for v in inside:
        i = decls[v][0]
        rest = ''.join(code[stmts[j][0]:stmts[j][1]] + ';' for j in body_stmts if j < lo or j > hi)
        if not _region_refs(rest, v):
            drop.append(i)
    # rebuild with dropped declarations removed (positions relative to span[1] + 1)
    base = span[1] + 1
    pieces, cursor = [], base
    for i in sorted(drop):
        a, b = stmts[i]
        line_a = body.rfind('\n', 0, a) + 1
        line_b = body.find('\n', b)
        line_b = len(body) if line_b < 0 else line_b + 1
        if body[line_a:a].strip() or body[b:line_b].strip():
            line_a, line_b = a, b
        pieces.append(body[cursor:line_a])
        cursor = line_b
    pieces.append(body[cursor:stmts[lo][0]])
    outer_body = ''.join(pieces) + call + body[stmts[hi][1]:span[2]]
    results = []
    orders = [('', order)]
    if len(order) > 1:
        orders.append((', declarations reversed', order[::-1]))
    for label, ordered in orders:
        hdef = (f"static inline {rtype} {helper}({hparams}) {{\n" + ''.join(decl_lines[v] for v in ordered)
                + '\n' + indent + region_text.strip() + "\n" + (f"{indent}return {output};\n" if output else '')
                + "}\n\n")
        text = body[:head_start] + ('\n' if head_start and body[head_start - 1] != '\n' else '') + hdef \
            + body[head_start:span[1] + 1] + outer_body + body[span[2]:]
        results.append((label, text))
    return results



def embedded_call_assignments(body: str, name: str) -> List[Tuple[str, str]]:
    """`x = expr; f(.., x, ..)` -> `f(.., (x = expr), ..)`: the load lowers straight into the
    variable's web instead of a temporary plus a copy (`lwz r0; mr rX, r0`)."""
    out: List[Tuple[str, str]] = []
    span = _function_body_span(body, name)
    if not span:
        return out
    inner = body[span[1]:span[2]]
    pat = re.compile(r'(?m)^([ \t]+)([A-Za-z_]\w*) = ([^;\n]+);\n([ \t]+)((?:[A-Za-z_][\w.>\-]*\s*=\s*)?[A-Za-z_]\w*\s*\()([^;\n]*?)\)\s*;\n')
    for m in pat.finditer(inner):
        ind, x, expr, ind2, callhead, args = m.groups()
        if x == name or re.search(r'\b' + re.escape(x) + r'\b', expr):
            continue
        argl = [a.strip() for a in args.split(',')]
        if argl.count(x) != 1 or re.search(r'\b' + re.escape(x) + r'\b', callhead):
            continue
        argl[argl.index(x)] = f"({x} = {expr})"
        s0, e0 = span[1] + m.start(), span[1] + m.end()
        out.append((f"embed {x} = ... in its call argument",
                    body[:s0] + f"{ind2}{callhead}{', '.join(argl)});\n" + body[e0:]))
    return out



EXPRESSION_EMBED_LIMIT = 60


def expression_embedded_assignments(body: str, name: str, lines=None,
                                    limit: int = EXPRESSION_EMBED_LIMIT) -> List[Tuple[str, str]]:
    """`x = E; y = A op x ...;` -> `y = A op (x = E) ...;`: the assignment is lowered inside its
    first use, after the operands written before it, so the use's earlier operand loads are
    numbered below E's temporaries while x's web is still created first. A lowering-temporary
    residual (two FPR/GPR temps swapped, declaration order unable to move them) closes this way:
    fn_3_225F8's `v21 = 1.0f + 0.5f * t3; v22 = PF16 * v21;` gave the 1.0f constant f3 and the
    PF16 load f2; `v22 = PF16 * (v21 = ...)` gives retail's f2/f3 (capture renumbering: the sum
    below the load, the load below the constant). LINES (body line numbers, 1-based) restricts
    the sites to statements on or next to implicated lines."""
    out: List[Tuple[str, str]] = []
    span = _function_body_span(body, name)
    if not span:
        return out
    inner = body[span[1]:span[2]]
    base_line = body.count('\n', 0, span[1]) + 1
    near = None if lines is None else {ln + d for ln in lines for d in (-1, 0, 1)}
    pat = re.compile(r'(?m)^([ \t]+)([A-Za-z_]\w*) = ([^;\n{}]+);\n([ \t]+)([^;\n{}=]*?[^=!<>+\-*/%&|^ \t])\s*=\s*([^;\n{}]+);\n')
    k = 0
    while len(out) < limit:
        m = pat.search(inner, k)
        if not m:
            break
        k = m.start() + len(m.group(1)) + 1
        ind, x, expr, ind2, lhs, rhs = m.groups()
        if x == name or re.search(r'\b' + re.escape(x) + r'\b', expr) or re.search(r'\b' + re.escape(x) + r'\b', lhs):
            continue
        if re.match(r'\s*(?:if|for|while|return|switch|case|do|else)\b', lhs) or '(' in lhs and ')' not in lhs:
            continue
        uses = list(re.finditer(r'(?<![\w.>&])' + re.escape(x) + r'(?![\w\[(])(?!\s*(?:=[^=]|\+\+|--))', rhs))
        if len(uses) != 1 or len(re.findall(r'\b' + re.escape(x) + r'\b', rhs)) != 1:
            continue
        if uses[0].start() == 0 and uses[0].end() == len(rhs.rstrip()):
            continue  # `y = x;` is a plain copy, not an operand
        if near is not None:
            ln = base_line + inner.count('\n', 0, m.start())
            if ln not in near and ln + 1 not in near:
                continue
        u = uses[0]
        new_rhs = rhs[:u.start()] + f"({x} = {expr.strip()})" + rhs[u.end():]
        s0, e0 = span[1] + m.start(), span[1] + m.end()
        out.append((f"embed {x} = ... in the next statement's operand",
                    body[:s0] + f"{ind2}{lhs} = {new_rhs};\n" + body[e0:]))
    return out


def condition_embedded_assignments(body: str, name: str) -> List[Tuple[str, str]]:
    """`if (G OP k) { x = G; } else ...` and `x = G; if (x OP k)` -> `if ((x = G) OP k)`: the
    load lowers straight into x's web (a virgin named local otherwise gets `lwz rT; cmp rT;
    mr rX, rT`); keeping a redundant `x = G;` in the then-branch preserves the non-inverted
    branch pair (fn_8000CEBC, capture-validated)."""
    out: List[Tuple[str, str]] = []
    span = _function_body_span(body, name)
    if not span:
        return out
    inner = body[span[1]:span[2]]
    # form A: the then-branch assigns the compared global
    for m in re.finditer(r'(?m)^([ \t]+)if \(([A-Za-z_][\w.>\-\[\]]*) (<=|<|>=|>|==|!=) ([^()\n]+?)\) \{\n([ \t]+)([A-Za-z_]\w*) = \2;\n', inner):
        ind, g, op, k, ind2, x = m.groups()
        s0, e0 = span[1] + m.start(), span[1] + m.end()
        out.append((f"embed {x} = {g} in its condition", body[:s0] + f"{ind}if (({x} = {g}) {op} {k}) {{\n" + body[e0:]))
        out.append((f"embed {x} = {g} in its condition, then-branch reload kept",
                    body[:s0] + f"{ind}if (({x} = {g}) {op} {k}) {{\n{ind2}{x} = {g};\n" + body[e0:]))
    # form B: an assignment immediately followed by a test of the variable
    for m in re.finditer(r'(?m)^([ \t]+)([A-Za-z_]\w*) = ([^;\n]+);\n\1if \(\2 (<=|<|>=|>|==|!=) ([^()\n]+?)\) \{\n', inner):
        ind, x, g, op, k = m.groups()
        s0, e0 = span[1] + m.start(), span[1] + m.end()
        out.append((f"embed {x} = {g} in the following condition", body[:s0] + f"{ind}if (({x} = {g}) {op} {k}) {{\n" + body[e0:]))
    return out


_LOCKED_CACHE_STORE = (r'\*\s*\(\s*(?:volatile\s+)?f32\s*\*\s*\)\s*\(\s*0[xX][eE]'
                       r'(?:0+{k}|0{7}\s*\+\s*0[xX]0*{k})\s*\)')


_LC_ADDR = r'(?:LC_BASE|0[xX][eE]0{7}[uU]?)'
_LC_ARG_UNSAFE = re.compile(r'\+\+|--|[^=!<>]=(?!=)|\b(?!sizeof\b)[A-Za-z_]\w*\s*\(')


def _lc_store(offset: int) -> str:
    return f'*(f32 *)(0xE0000000 + 0x{offset:02X})'


def _lc_block_end(text: str, i: int) -> int:
    """Index of the brace closing the block that contains position `i` (len(text) if none)."""
    depth = 0
    while i < len(text):
        if text[i] == '{':
            depth += 1
        elif text[i] == '}':
            if depth == 0:
                return i
            depth -= 1
        i += 1
    return len(text)


def _lc_split_args(text: str) -> Optional[List[str]]:
    out, depth, cur = [], 0, ''
    for ch in text:
        if ch in '([':
            depth += 1
        elif ch in ')]':
            depth -= 1
        if ch == ',' and depth == 0:
            out.append(cur.strip()); cur = ''
        else:
            cur += ch
    out.append(cur.strip())
    return out if all(out) and depth == 0 else None


def _lc_normalize(text: str) -> str:
    """Spell every locked-cache translation-column store as `*(f32 *)(0xE0000000 + 0xK)`:
    indexed float views of LC_BASE, bare `*(f32 *)0xE000000C` addresses and a block-local
    `f32 (*m)[4]` matrix pointer over the locked cache. Same addresses, one spelling the
    triple rewrite recognises."""
    text = re.sub(r'\(\s*\(\s*(?:volatile\s+)?f32\s*\*\s*\)\s*' + _LC_ADDR + r'\s*\)\s*\[\s*(3|7|11)\s*\]',
                  lambda m: _lc_store(4 * int(m[1])), text)
    text = re.sub(r'\*\s*\(\s*(?:volatile\s+)?f32\s*\*\s*\)\s*0[xX][eE]0{5}([0-2][cC])\b(?!\s*\+)',
                  lambda m: _lc_store(int(m[1], 16)), text)
    text = re.sub(r'\*\s*\(\s*(?:volatile\s+)?f32\s*\*\s*\)\s*\(\s*LC_BASE\s*\+\s*0[xX]0*([0-2][cC])\s*\)',
                  lambda m: _lc_store(int(m[1], 16)), text)
    # a word-index macro over the locked cache: #define M(i) (*(f32 *)(0xE0000000 + (i) * 4))
    for m in re.finditer(r'(?m)^[ \t]*#\s*define\s+(\w+)\s*\(\s*(\w+)\s*\)\s*\(\s*\*\s*\(\s*f32\s*\*\s*\)\s*\(\s*'
                         + _LC_ADDR + r'\s*\+\s*\(\s*\2\s*\)\s*\*\s*4\s*\)\s*\)[ \t]*$', text):
        text = re.sub(r'(?<![\w#])' + m[1] + r'\s*\(\s*(\d+)\s*\)', lambda r: _lc_store(4 * int(r[1])), text)
    decl = re.compile(r'(?m)^[ \t]*f32\s*\(\s*\*\s*(\w+)\s*\)\s*\[\s*4\s*\]\s*=\s*'
                      r'\(\s*f32\s*\(\s*\*\s*\)\s*\[\s*4\s*\]\s*\)\s*' + _LC_ADDR + r'\s*;[ \t]*\n')
    while True:
        for m in decl.finditer(text):
            end = _lc_block_end(text, m.end())
            scope = re.sub(r'\b' + m[1] + r'\s*\[\s*([0-2])\s*\]\s*\[\s*3\s*\]',
                           lambda r: _lc_store(16 * int(r[1]) + 12), text[m.end():end])
            if not re.search(r'\b' + m[1] + r'\b', scope):
                text = text[:m.start()] + scope + text[end:]
                break
        else:
            return text


def _lc_expand_helpers(text: str, name: str) -> str:
    """Expand the target function's statement calls of a static inline helper whose body is
    only float declarations, simple assignments and the locked-cache translation triple. The
    matched shape needs the three loads in the caller's own block; parameters are replaced by
    their (side-effect-free) arguments, so the expansion evaluates the same values."""
    store = lambda k: _LOCKED_CACHE_STORE.replace('{k}', k)
    triple = (r'[ \t]*' + store('[cC]') + r'\s*=\s*[^;]+;\s*' + store('1[cC]') + r'\s*=\s*[^;]+;\s*'
              + store('2[cC]') + r'\s*=\s*[^;]+;\s*')
    shape = re.compile(r'\s*(?:(?:(?:const\s+)?f32\s+[^;{}()]*|\w+\s*=\s*[^;{}]+);\s*)*' + triple)
    helpers = {}
    for m in re.finditer(r'(?m)^static\s+inline\s+void\s+(\w+)\s*\(([^)]*)\)\s*\{', text):
        end = _lc_block_end(text, m.end())
        inner = re.sub(r'/\*.*?\*/|//[^\n]*', '', text[m.end():end], flags=re.S)
        if m[2].strip() in ('', 'void'):
            continue
        params = [re.search(r'(\w+)\s*$', q.strip()) for q in m[2].split(',')]
        if all(params) and shape.fullmatch(inner):
            helpers[m[1]] = ([q[1] for q in params], inner)
    if not helpers:
        return text
    span = _function_body_span(text, name)
    if not span:
        return text
    body = text[span[1]:span[2]]
    call = re.compile(r'(?m)^([ \t]*)(' + '|'.join(map(re.escape, helpers)) + r')\s*\((.*)\)\s*;[ \t]*\n')

    def expand(m):
        params, inner = helpers[m[2]]
        args = _lc_split_args(m[3])
        if not args or len(args) != len(params) or any(_LC_ARG_UNSAFE.search(' ' + a) for a in args):
            return m[0]
        out = inner
        for prm, arg in zip(params, args):
            out = re.sub(r'(?<!\.)(?<!->)\b' + re.escape(prm) + r'\b', lambda _r: '(' + arg + ')', out)
        ind, i2 = m[1], m[1] + '    '
        lines = [ln.strip() for ln in re.split(r'(?<=;)', out) if ln.strip()]
        return f'{ind}{{\n' + ''.join(f'{i2}{ln}\n' for ln in lines) + f'{ind}}}\n'

    new = call.sub(expand, body)
    return text if new == body else text[:span[1]] + new + text[span[2]:]


def locked_cache_columns(body: str, name: str) -> List[Tuple[str, str]]:
    """The translation column of the locked-cache current matrix (stores to 0xE000000C, 1C, 2C).
    Retail loads all three values first, in address order, into temporaries the allocator
    numbers x lowest (x takes the highest FPR: f3/f2/f0 around a live f1); the matched
    spelling (fn_1_61640, fn_1_61EF4) declares the temporaries in reverse order under
    `#pragma opt_propagation off`. Agents write direct stores, initialized block locals or
    member reads, which interleave the loads with the stores or reverse the colors. Every
    site is rewritten into the matched shape, with and without the pragma.
    Without the pragma MWCC forward-substitutes whichever value is stored first (a window
    temporary that takes f0), so no declaration order or helper parameter order reaches retail
    (captures of fn_1_11E98/fn_1_1189C, 2026-10-13). Sites written through an inline helper,
    another store spelling or a run of named-local assignments are first normalised into the
    direct triple (`_lc_normalize`, `_lc_expand_helpers`, the assignment-run fold)."""
    out = _locked_cache_core(body, name)
    prepared = _lc_expand_helpers(_lc_normalize(body), name)
    if prepared != body:
        seen = {t for _, t in out}
        out += [(label + ' (helper/spelling normalised)', t) for label, t in _locked_cache_core(prepared, name)
                if t not in seen]
    return out


_LC_DEREF = re.compile(r'\*\s*\(\s*(?:const\s+)?f32\s*\*\s*\)\s*\(\s*0[xX][eE]0{7}\s*\+\s*0[xX][0-9a-fA-F]+\s*\)')
_LC_MEMBER = re.compile(r'(?<![\w.>&])(?:\(\s*&?\s*[A-Za-z_][\w.>\- ]*\)|[A-Za-z_]\w*)'
                        r'(?:\s*(?:->|\.)\s*[A-Za-z_]\w*|\s*\[[^\[\];]*\])+(?![\w(\[])')


def _lc_volatile_read(expr: str) -> Optional[str]:
    """The first memory read of a translation value spelled through a volatile f32 view, so
    copy propagation cannot sink it to the store: a whole lvalue value as one read, else the
    first locked-cache read or member access of the expression. None when there is no read."""
    e = expr.strip()
    while e.startswith('(') and e.endswith(')'):
        depth = 0
        for i, ch in enumerate(e):
            depth += {'(': 1, ')': -1}.get(ch, 0)
            if depth == 0 and i < len(e) - 1:
                break
        else:
            e = e[1:-1].strip()
            continue
        break
    m = _LC_DEREF.fullmatch(e) or _LC_DEREF.search(e)
    if m:
        return e[:m.start()] + '*(volatile f32 *)' + m[0][m[0].index(')') + 1:].strip() + e[m.end():]
    m = _LC_MEMBER.search(e)
    if m and not re.match(r'\s*\(', e[m.end():]):
        return e[:m.start()] + f'*(volatile f32 *)&({m[0].strip()})' + e[m.end():]
    return None


def _lc_lvalue(expr: str) -> bool:
    """A column value whose address can be passed: a dereference or a member/element access.
    A bare local is excluded (taking its address would move it to the stack)."""
    e = expr.strip()
    deref = re.fullmatch(r'\*\s*\([^()]*\)\s*(?:&\s*)?(?:\([^()]*\)|[A-Za-z_][\w.\->\[\] ]*)', e)
    return bool(deref or _LC_MEMBER.fullmatch(e)) and _LC_ARG_UNSAFE.search(' ' + e) is None


def _lc_helper_copy(body: str, name: str, calls) -> List[Tuple[str, str]]:
    """The column copy through a static inline helper that reads the three values into its own
    locals. Inlined locals are compiler objects numbered above every function-scope local, so
    they colour before the function's long-lived values; function-scope temporaries instead push
    the `register` parameters of a following paired-single asm helper (`psvec_set`, whose
    operands interfere with every value live since function entry) below the K threshold, and a
    long-lived float then claims f31 before them. fn_1_438AC (capture 2026-10-26): v0 took f31
    and psvec_set's x/y f29/f30 with block or function locals; the helper gave retail's
    f29/f30/f31 and matched. Helper value parameters do not work: arguments become window
    temporaries again."""
    if not calls or not all(c[2] for c in calls):
        return []
    head = re.search(r'(?m)^[^\n;{}]*\b' + re.escape(name) + r'\s*\([^;{]*\)\s*\{', body)
    if not head or re.search(r'\b' + re.escape(name) + r'_lc_copy\b', body):
        return []
    volatile = any(c[3] or re.search(r'\bvolatile\b', c[2]) for c in calls)
    note = '  /* fzgx-allow: S2 volatile first read keeps the locked-cache column loads in order */'
    first = ('volatile f32 *s0' if volatile else 'f32 *s0') + ', f32 *s1, f32 *s2'
    helper = (f'/* locked-cache translation column copied through the helper\'s own locals */\n'
              f'static inline void {name}_lc_copy({first}) {{{note if volatile else ""}\n'
              f'    f32 x = *s0;\n    f32 y = *s1;\n    f32 z = *s2;\n'
              f'    *(f32 *)(0xE0000000 + 0x0C) = x;\n'
              f'    *(f32 *)(0xE0000000 + 0x1C) = y;\n'
              f'    *(f32 *)(0xE0000000 + 0x2C) = z;\n}}\n\n')
    text = body
    for a, b, call, held in sorted(calls, reverse=True):
        line = call.rstrip('\n') + (note if re.search(r'\bvolatile\b', call) else '') + '\n'
        text = text[:a] + line + text[b:]
    pos = head.start()
    return [('locked-cache column copy through an inline helper\'s locals', text[:pos] + helper + text[pos:])]


def _locked_cache_core(body: str, name: str) -> List[Tuple[str, str]]:
    span = _function_body_span(body, name)
    if not span:
        return []
    inner = body[span[1]:span[2]]
    store = lambda k: _LOCKED_CACHE_STORE.replace('{k}', k)
    triple = re.compile(r'(?m)^([ \t]*)' + store('[cC]') + r'\s*=\s*([^;]+);[ \t]*\n'
                        r'[ \t]*' + store('1[cC]') + r'\s*=\s*([^;]+);[ \t]*\n'
                        r'[ \t]*' + store('2[cC]') + r'\s*=\s*([^;]+);[ \t]*\n')
    sites = list(triple.finditer(inner))
    if not sites:
        return []

    def balanced(text):
        return text.count('(') == text.count(')') and text.count('[') == text.count(']')

    edits, calls = [], []
    for n, site in enumerate(sites):
        a, b, indent = site.start(), site.end(), site[1]
        values = [v.strip() for v in (site[2], site[3], site[4])]
        # an enclosing `{ f32 decls; triple }` block holds only the copy's own temporaries:
        # replace it whole, reading each temporary's initializer directly
        opener = inner.rfind('{', 0, a)
        closer = re.match(r'[ \t]*\}[ \t]*\n', inner[b:])
        line0 = inner.rfind('\n', 0, opener) + 1 if opener >= 0 else 0
        prefix = inner[opener + 1:a] if opener >= 0 else ''
        own = set()
        for d in re.finditer(r'(?:const\s+)?f32\s+([^;{}]*);', prefix):
            own |= {re.match(r'\s*(\w+)', v)[1] for v in d[1].split(',') if re.match(r'\s*\w+', v)}
        assigned = re.findall(r'(?:^|;)\s*(\w+)\s*=(?!=)', re.sub(r'(?:const\s+)?f32\s+[^;{}]*;', ';', prefix))
        if (closer and opener >= 0 and not inner[line0:opener].strip() and prefix.strip()
                and re.fullmatch(r'\s*(?:(?:(?:const\s+)?f32\s+[^;{}]*|\w+\s*=\s*[^;{}]+);\s*)+', prefix)
                and set(assigned) <= own):
            resolved = []
            for v in values:
                found = None
                if re.fullmatch(r'\w+', v):
                    for m in re.finditer(r'\b' + re.escape(v) + r'\s*=\s*([^;,]+)[;,]', prefix):
                        found = m[1].strip()
                resolved.append(found if found and balanced(found) else None)
            if all(resolved):
                values = resolved
                a, b, indent = line0, b + closer.end(), inner[line0:opener]
        if all(re.fullmatch(r'\w+', v) for v in values) and len(set(values)) == 3:
            # a run of `name = expr;` lines right before the triple defines its named locals:
            # fold each single-use local into the copy (it must not appear anywhere else)
            run, k = {}, a
            while True:
                ln = re.search(r'(?m)^([ \t]*)(\w+)\s*=\s*([^;{}=][^;{}]*);[ \t]*\n\Z', inner[:k])
                if not ln or ln[2] not in values or ln[2] in run:
                    break
                run[ln[2]] = ln[3].strip(); k = ln.start()
            if set(run) == set(values) and all(balanced(e) for e in run.values()):
                rest = re.sub(r'(?m)^[ \t]*(?:const\s+)?f32\s+[^;{}()=]*;[ \t]*$', '', inner[:k] + inner[b:])
                # member declarations of an anonymous view (`(struct { u8 pad[184]; f32 x, y, z; } *)p`)
                # are not uses of the locals (fn_1_438AC)
                rest = re.sub(r'\b(?:struct|union)\s*\w*\s*\{[^{}]*\}', 'struct', rest)
                exprs = ' '.join(run.values())
                if not any(re.search(r'(?<!\.)(?<!->)\b' + v + r'\b', exprs) for v in values) and not any(
                        re.search(r'(?<!\.)(?<!->)\b' + v + r'\b', rest) for v in values):
                    values = [run[v] for v in values]
                    a = k
        x, y, z = (f'fzgx_lc{n}_{c}' for c in 'xyz')
        i2 = indent + '    '

        def block(first, x=x, y=y, z=z, i2=i2, indent=indent, values=values):
            # the volatile view is a codegen choice: lint S2 needs its justification on the line
            note = ('  /* fzgx-allow: S2 volatile first read keeps the locked-cache column loads in order */'
                    if re.search(r'\bvolatile\b', first) else '')
            return (f'{indent}{{\n{i2}f32 {z};\n{i2}f32 {y};\n{i2}f32 {x};\n'
                    f'{i2}{x} = {first};{note}\n{i2}{y} = {values[1]};\n{i2}{z} = {values[2]};\n'
                    f'{i2}*(f32 *)(0xE0000000 + 0x0C) = {x};\n'
                    f'{i2}*(f32 *)(0xE0000000 + 0x1C) = {y};\n'
                    f'{i2}*(f32 *)(0xE0000000 + 0x2C) = {z};\n{indent}}}\n')
        held = _lc_volatile_read(values[0])
        first = held or values[0]
        lvalues = [first] + values[1:]
        call = (f'{indent}{name}_lc_copy(&({lvalues[0]}), &({lvalues[1]}), &({lvalues[2]}));\n'
                if all(_lc_lvalue(v) for v in lvalues) else None)
        edits.append((span[1] + a, span[1] + b, block(values[0]), block(held) if held else None))
        calls.append((span[1] + a, span[1] + b, call, bool(held)))
    text = body
    for a, b, new, _ in sorted(edits, reverse=True):
        text = text[:a] + new + text[b:]
    out = [('locked-cache column copy in reverse-declared temporaries', text)]
    out += _lc_helper_copy(body, name, calls)
    if any(e[3] for e in edits):
        # without opt_propagation off MWCC forward-substitutes the first-stored value's load
        # into its store (a window temporary: f0, loaded last). A volatile read of that one
        # value cannot move, so the loads stay in address order and colour f2/f1/f0 like
        # retail, with no function-wide pragma (fn_1_8D08: 15 -> 0 translation rows)
        held_text = body
        for a, b, new, held in sorted(edits, reverse=True):
            held_text = held_text[:a] + (held or new) + held_text[b:]
        out.append(('locked-cache column copy with the first-stored value read through a volatile view',
                    held_text))
        # computed columns (m[i][3] = m[i][0] * s + m[i][3]): retail's scale outlives the three
        # values but takes the higher FPR (f5 over x f4, y f3, z f2), so the values must number
        # above it: declared first at function scope, z first (fn_1_1ACC0, capture 2026-10-13)
        hoisted = re.sub(r'\{\n[ \t]*f32 (fzgx_lc\d+_z);\n[ \t]*f32 (fzgx_lc\d+_y);\n[ \t]*f32 (fzgx_lc\d+_x);\n',
                         '{\n', held_text)
        names = re.findall(r'\b(fzgx_lc\d+)_x = ', held_text)
        top = _function_body_span(hoisted, name)
        if names and top:
            decl = ''.join(f'    f32 {n}_z;\n    f32 {n}_y;\n    f32 {n}_x;\n' for n in names)
            out.append(('locked-cache column copy, volatile first read, temporaries declared first',
                        hoisted[:top[1]] + '\n' + decl + hoisted[top[1]:].lstrip('\n')))
    head = re.search(r'(?m)^[^\n;{}]*\b' + re.escape(name) + r'\s*\([^;{]*\)\s*\{', text)
    fn = _function_body_span(text, name)
    if head and fn and not re.search(r'#\s*pragma\s+opt_propagation\s+off', text):
        end = text.find('\n', fn[2])
        end = len(text) if end < 0 else end + 1
        out.append(('locked-cache column copy in reverse-declared temporaries under opt_propagation off',
                    text[:head.start()] + '#pragma opt_propagation off\n' + text[head.start():end]
                    + '#pragma opt_propagation reset\n' + text[end:]))
    return out


def rewrites(body: str, name: str) -> List[Tuple[str, str]]:
    """Every single second-stage rewrite of a body."""
    out: List[Tuple[str, str]] = []
    for fn in (primer_sections, scope_moves, split_inits, hoists, through_local, return_values,
               call_results_to_locals, wrap_constant_pointers, decse_repeated_expressions,
               scalar_carriers, dead_uses, variable_splits, signedness_flips, float_precision,
               compound_assignments, embedded_call_assignments, condition_embedded_assignments,
               expression_embedded_assignments, lifetime_splits, constant_address_locals,
               long_loop_counters):
        try:
            out += fn(body, name)
        except Exception:
            continue
    return out


_INLINE_DEF = re.compile(r'^[ \t]*(?:static\s+)?inline\b[^;{=]*?\b([A-Za-z_]\w*)\s*\([^;{]*\)\s*\{', re.M)


def inline_size_pragmas(body: str, name: str) -> List[Tuple[str, str]]:
    """`#pragma inline_max_size(4096)` on the line before the function when the body defines an
    `inline` helper ahead of it. `-inline auto` leaves a helper above MWCC's default size limit out
    of line (40 one-line statements inline, 48 do not; `-inline on`, `inline_depth` do not help),
    and the pragma state in effect at the caller's definition decides, not the one at the helper's
    (GC/1.3.2 probes 2026-10-28: fn_1_D523C's whole-body wrapper 4.4% as a call, 97.2% inlined).
    Without a helper the pragma leaves the code byte-identical. Applied to every region helper
    (`region_inline_helpers`); saved matcher bodies had no helper left out of line (2,114 checked)."""
    span = _function_body_span(body, name)
    if not span or re.search(r'#pragma\s+inline_max_size', body):
        return []
    helpers = [m.group(1) for m in _INLINE_DEF.finditer(body, 0, span[0]) if m.group(1) != name]
    if not helpers:
        return []
    line = body.rfind('\n', 0, span[0]) + 1
    return [(f"inline_max_size(4096) before {name} (inline helper {helpers[0]})",
             body[:line] + "#pragma inline_max_size(4096)\n" + body[line:])]


def primer_sections(body: str, name: str) -> List[Tuple[str, str]]:
    """A matcher's `fzgx_*` primer functions defined in `.text` moved into `.fzgxpool`: the
    object matched at 100% and the link rejected it (main_rel grew by the primers' code;
    fn_1_E252C, fn_1_115560, fn_1_147508, fn_10_17814). The pool order is unchanged."""
    from . import fixup_layout
    text = fixup_layout.primer_sections(body)
    out = [('primer section .fzgxpool', text)] if text else []
    # the same repair over every primer-like definition (`pool_primer`, `<fn>_pool_N`: the
    # oracle only honours `fzgx_*` names in `.fzgxpool`) and the ineffective pragma forms
    names = {m.group(1) for m in fixup_layout._PRIMER_DEF.finditer(body)
             if m.group(1) != name and fixup_layout.primer_like(m.group(1))}
    repaired = fixup_layout.primer_repair(body, sorted(names), ()) if names else None
    if repaired and repaired[0] != text:
        out.append(('primers renamed fzgx_* and moved into .fzgxpool', repaired[0]))
    return out


def _top_statements(text: str) -> Optional[List[Tuple[int, int]]]:
    """Spans of the top-level statements of a block's inner text (`;`-terminated or a
    braced compound, an `else` continuing its `if`). None when comments or preprocessor
    lines make the split unreliable."""
    if '/*' in text or '//' in text or '#' in text:
        return None
    spans, start, paren, brace, i = [], None, 0, 0, 0
    while i < len(text):
        c = text[i]
        if start is None:
            if c.isspace():
                i += 1
                continue
            start = i
        if c == '(':
            paren += 1
        elif c == ')':
            paren -= 1
        elif c == '{':
            brace += 1
        elif c == '}':
            brace -= 1
            if brace == 0 and paren == 0 and not re.match(r'\s*else\b', text[i + 1:]):
                spans.append((start, i + 1)); start = None
        elif c == ';' and paren == 0 and brace == 0:
            if not re.match(r'\s*else\b', text[i + 1:]):
                spans.append((start, i + 1)); start = None
        if paren < 0 or brace < 0:
            return None
        i += 1
    return spans if start is None else None


def _int_literal(token: str) -> Optional[int]:
    m = re.fullmatch(r'(0[xX][0-9a-fA-F]+|\d+)[uUlL]*', token)
    return int(m.group(1), 0) if m else None


def rerolled_loops(body: str, name: str = "") -> List[Tuple[str, str]]:
    """Fold a counted loop whose body is two copies of one search step back into one step.

    MWCC -O4 unrolls a constant-count loop by two: `for (i = 0; i < 26; i++) { e = base + 0x180
    + i * 0x40; if (e[0x18] == ch) { found = e; break; } }` becomes a 13-trip CTR loop with
    the two steps at 0x180/0x1c0 off one base advanced by 0x80, and it keeps the original
    counter as a dead induction value (`li r3, 0; mr r7, r3` ... `addi r7, r7, 1` before the
    `bdnz`). A draft written as the unrolled loop (two steps, `base += 0x80`, `i < 13`) loses
    that counter and moves the found pointer out of r3 (the fn_12_31224 clone family in
    movie_module, 95.4 -> 99.1, probe-verified 2026-10-05). The two halves must agree token
    for token up to a consistent identifier renaming and integer literals offset by one half
    stride; the stride is a trailing `P += S;` or a `V * S` index in the first half."""
    out: List[Tuple[str, str]] = []
    for m in re.finditer(r'\bfor\s*\(', body):
        depth, k = 0, m.end() - 1
        while k < len(body):
            depth += {'(': 1, ')': -1}.get(body[k], 0)
            if depth == 0:
                break
            k += 1
        parts = body[m.end():k].split(';')
        if len(parts) != 3:
            continue
        init, cond, step = (s.strip() for s in parts)
        up = re.fullmatch(r'(\w+)\s*=\s*0', init)
        if up:
            var = up.group(1)
            bound = re.fullmatch(rf'{var}\s*(<|!=)\s*(0[xX][0-9a-fA-F]+|\d+)', cond)
            if not bound or not re.fullmatch(rf'{var}\s*\+\+|\+\+\s*{var}|{var}\s*\+=\s*1', step):
                continue
            count_text = bound.group(2)
        else:
            down = re.fullmatch(r'(\w+)\s*=\s*(0[xX][0-9a-fA-F]+|\d+)', init)
            if not down:
                continue
            var, count_text = down.group(1), down.group(2)
            if not re.fullmatch(rf'{var}\s*(!=|>)\s*0', cond) or not re.fullmatch(rf'{var}\s*--|--\s*{var}|{var}\s*-=\s*1', step):
                continue
        open_ = re.match(r'\s*\{', body[k + 1:])
        if not open_:
            continue
        lo = k + 1 + open_.end()
        depth, hi = 1, lo
        while hi < len(body) and depth:
            depth += {'{': 1, '}': -1}.get(body[hi], 0)
            hi += 1
        hi -= 1
        inner = body[lo:hi]
        spans = _top_statements(inner)
        if not spans:
            continue
        stmts = [inner[a:b] for a, b in spans]
        # trailing steps: pointer advances and other counters stay after the folded body
        tail: List[str] = []
        while stmts and re.fullmatch(r'\w+\s*(\+=\s*\w+|\+\+|--)\s*;', stmts[-1]):
            tail.insert(0, stmts.pop())
        bare = re.compile(TYPE + r'\s*(\w+)\s*;')
        decls = [s for s in stmts if bare.fullmatch(s) and not re.match(r'(return|break|continue)\b', s)]
        core = [s for s in stmts if s not in decls]
        if len(core) < 2 or len(core) % 2:
            continue
        half_a, half_b = core[:len(core) // 2], core[len(core) // 2:]
        rename: Dict[str, str] = {}
        delta: Optional[int] = None
        ok = True
        for sa, sb in zip(half_a, half_b):
            ta = [t for t in TOKEN.findall(sa)]
            tb = [t for t in TOKEN.findall(sb)]
            if len(ta) > len(tb) and ta[len(ta) - len(tb)] == tb[0]:
                ta = ta[len(ta) - len(tb):]   # `T *e = ...;` against `e = ...;`
            if len(ta) != len(tb):
                ok = False; break
            for x, y in zip(ta, tb):
                if x == y:
                    continue
                ix, iy = _int_literal(x), _int_literal(y)
                if ix is not None and iy is not None:
                    if iy <= ix or (delta is not None and iy - ix != delta):
                        ok = False; break
                    delta = iy - ix
                elif re.fullmatch(r'[A-Za-z_]\w*', x) and re.fullmatch(r'[A-Za-z_]\w*', y):
                    if rename.setdefault(x, y) != y:
                        ok = False; break
                else:
                    ok = False; break
            if not ok:
                break
        if not ok or delta is None or var in rename or len(set(rename.values())) != len(rename):
            continue
        stride = 2 * delta
        first = '\n'.join(half_a)
        advances = [i for i, s in enumerate(tail) if re.fullmatch(r'(\w+)\s*\+=\s*(0[xX][0-9a-fA-F]+|\d+)\s*;', s)
                    and _int_literal(re.fullmatch(r'\w+\s*\+=\s*(\w+)\s*;', s).group(1)) == stride]
        indexed = re.compile(rf'\b{var}\s*\*\s*({hex(stride)}|{stride})\b|\b({hex(stride)}|{stride})\s*\*\s*{var}\b', re.I)
        forms: List[Tuple[str, List[str], List[str]]] = []
        if len(advances) == 1:
            i = advances[0]
            stepped = list(tail)
            stepped[i] = re.sub(r'\+=\s*\w+', f'+= {hex(delta) if "0x" in tail[i].lower() else delta}', tail[i])
            forms.append(('advance', list(half_a), stepped))
            # the indexed spelling `P + i * half` off the unadvanced base: retail folds the
            # element's field offset into the base load (`lbz 0x198(r8)`), the stepped
            # element pointer does not (`lbz 0x18(r9)`)
            ptr = re.match(r'(\w+)\s*\+=', tail[i]).group(1)
            if ptr != var and not re.search(rf'\b{ptr}\s*(=[^=]|\+\+|--|[-+*/|&^]=)', first):
                forms.append(('indexed', [re.sub(rf'(?<![\w.>]){ptr}\b', f'({ptr} + {var} * {hex(delta)})', s)
                                          for s in half_a], tail[:i] + tail[i + 1:]))
        elif not advances and indexed.search(first):
            forms.append(('indexed', [indexed.sub(lambda r: f'{var} * {hex(delta)}', s) for s in half_a], list(tail)))
        if not forms:
            continue
        kept = [d for d in decls if re.search(rf'\b{bare.fullmatch(d).group(1)}\b', first)]
        indent = re.search(r'\n([ \t]*)\S', '\n' + inner[:spans[0][0] + 1])
        pad = indent.group(1) if indent else '    '
        close = re.search(r'\n([ \t]*)$', inner)
        count = int(count_text, 0) * 2
        new_cond = cond.replace(count_text, hex(count) if count_text.lower().startswith('0x') else str(count)) if up else cond
        new_init = init if up else init.replace(count_text, hex(count) if count_text.lower().startswith('0x') else str(count))
        header = f'for ({new_init}; {new_cond}; {step})'
        for form, new_a, new_tail in forms:
            new_inner = '\n' + ''.join(pad + s + '\n' for s in kept + new_a + new_tail) + (close.group(1) if close else '')
            text = body[:m.start()] + header + ' {' + new_inner + body[hi:]
            label = f'reroll unrolled loop {var} ({form}): {count_text} x2 steps -> {count} x1 (stride {hex(stride)})'
            out.append((label, text))
            # the folded loop owns a new web (the dead counter), so the callee-saved and
            # volatile order of its locals is searched again: the step pointer hoisted into
            # the enclosing declarations, every order of those declarations, with and without
            # the byte-cast parameters narrowed (fn_12_31224: counter, step, result, base)
            hoisted = _hoist_step_locals(text, m.start())
            for narrowed_label, narrowed in [('', hoisted)] + [(' + ' + l, t) for l, t in narrowed_parameters(hoisted, '')]:
                for order_label, ordered in _declaration_orders(narrowed, m.start()):
                    out.append((label + narrowed_label + order_label, ordered))
    return out


def _enclosing_function(body: str, pos: int) -> Optional[Tuple[int, int, int]]:
    """(header start, body start after '{', closing brace) of the function containing pos."""
    best = None
    for h in re.finditer(r'(?m)^[A-Za-z_][^;{}()\n]*\b(\w+)\s*\([^;{}]*\)\s*\{', body):
        if h.end() > pos:
            break
        span = _function_body_span(body[h.start():], h.group(1))
        if span and h.start() + span[2] > pos:
            best = (h.start(), h.start() + span[1], h.start() + span[2])
    return best


def _hoist_step_locals(text: str, pos: int) -> str:
    """`T *e = expr;` declared at the top of the loop at pos becomes `T *e;` among the enclosing
    function's declarations and `e = expr;` in the loop."""
    fn = _enclosing_function(text, pos)
    open_ = text.find('{', text.find(')', pos))
    if not fn or open_ < 0:
        return text
    locs = _locals(text, (fn[0], fn[1], fn[2]))
    if not locs:
        return text
    inner = DECL_RE.match(text[open_ + 1:].lstrip('\n').split('\n', 1)[0])
    if not inner or inner.group(3) or not inner.group(4):
        return text
    line_start = open_ + 1 + (len(text[open_ + 1:]) - len(text[open_ + 1:].lstrip('\n')))
    line_end = text.index('\n', line_start)
    indent = re.match(r'[ \t]*', text[line_start:]).group(0)
    text = text[:line_start] + f'{indent}{inner.group(2)} = {inner.group(4).strip()};' + text[line_end:]
    decl_indent = re.match(r'[ \t]*', text[locs[-1][0]:]).group(0)
    typ = inner.group(1).strip()
    sep = '' if typ.endswith('*') else ' '
    return text[:locs[-1][1]] + f'{decl_indent}{typ}{sep}{inner.group(2)};\n' + text[locs[-1][1]:]


def _declaration_orders(text: str, pos: int, limit: int = 5) -> List[Tuple[str, str]]:
    """Every order of the leading declarations of the function containing pos (at most
    `limit` declarations, initializers kept on their declaration)."""
    fn = _enclosing_function(text, pos)
    if not fn:
        return [('', text)]
    locs = _locals(text, (fn[0], fn[1], fn[2]))
    if len(locs) < 2 or len(locs) > limit or any(locs[i][1] != locs[i + 1][0] for i in range(len(locs) - 1)):
        return [('', text)]
    out = []
    for order in itertools.permutations(range(len(locs))):
        names = ','.join(locs[i][3] for i in order)
        out.append(('' if order == tuple(range(len(locs))) else f', order {names}', reorder(text, locs, order)))
    return out


NARROW = {'u8': 'u8', 's8': 's8', 'u16': 'u16', 's16': 's16'}


def narrowed_parameters(body: str, name: str = "") -> List[Tuple[str, str]]:
    """A 32-bit parameter whose every use is one narrowing cast, `(u8)arg`, declared with that
    type instead (the casts dropped). MWCC numbers a narrow parameter's truncated value as the
    parameter's own web (a low vreg), where a cast at the use is a late lowering temporary: in
    the fn_12_31224 search loop the key moves from r3 to retail's r9 (probe-verified
    2026-10-05). With an empty name every function of the body is tried."""
    out: List[Tuple[str, str]] = []
    heads = [h for h in re.finditer(r'(?m)^[A-Za-z_][^;{}()\n]*\b(\w+)\s*\(([^;{}()]*)\)\s*\{', body)
             if not name or h.group(1) == name]
    for h in heads:
        span = _function_body_span(body[h.start():], h.group(1))
        if not span:
            continue
        lo, hi = h.end(), h.start() + span[2]
        code = body[lo:hi]
        for p in re.finditer(r'(?:^|,)\s*((?:unsigned\s+)?(?:u32|s32|int|long|unsigned))\s+(\w+)\s*(?=,|$)', h.group(2)):
            pname = p.group(2)
            uses = list(re.finditer(rf'(?<![\w.>]){pname}\b', code))
            casts = list(re.finditer(rf'\(\s*(u8|s8|u16|s16)\s*\)\s*{pname}\b', code))
            if not uses or len(casts) != len(uses) or len({c.group(1) for c in casts}) != 1:
                continue
            narrow = NARROW[casts[0].group(1)]
            params = h.group(2)
            new_params = params[:p.start(1)] + narrow + params[p.end(1):]
            head = body[h.start():h.end()].replace('(' + params + ')', '(' + new_params + ')', 1)
            # the redundant cast is not a no-op for allocation: an inline helper's
            # `(u8)key` of a u8 argument keeps the key in its own web (fn_12_31224 needs it)
            out.append((f'narrow parameter {pname} to {narrow}, casts kept', body[:h.start()] + head + code + body[hi:]))
            new_code = re.sub(rf'\(\s*{casts[0].group(1)}\s*\)\s*{pname}\b', pname, code)
            out.append((f'narrow parameter {pname} to {narrow}', body[:h.start()] + head + new_code + body[hi:]))
    return out


def return_values(body: str, name: str) -> List[Tuple[str, str]]:
    """Recover an omitted result when a void draft leaves the value outside r3.

    Tail calls forward their own result; preserving a local across the call would
    create a different live range and hide the actual return convention.
    """
    signature = re.search(rf'\bvoid\s+{re.escape(name)}\s*\(', body)
    span = _function_body_span(body, name)
    if not signature or not span:
        return []
    locals_ = _locals(body, span)
    values = [nm for _, _, ty, nm, dims in locals_ if not dims and
              (ty.strip() in ('u32', 's32', 'int', 'unsigned', 'u16', 's16', 'u8', 's8') or '*' in ty)]
    out = []
    for value in values:
        inner = body[span[1]:span[2]]
        inner = re.sub(r'\breturn\s*;', f'return (u32){value};', inner)
        inner += f'    return (u32){value};\n'
        text = body[:span[1]] + inner + body[span[2]:]
        text = text[:signature.start()] + 'u32' + text[signature.start() + 4:]
        out.append((f'return {value}', text))
        calls = set()
        def forward(match):
            callee = match[2]
            if not re.search(rf'\bextern\s+void\s+{re.escape(callee)}\s*\(', text):
                return match[0]
            calls.add(callee)
            return f'{match[1]}return {callee}({match[3]});'
        inner = re.sub(r'(?m)^([ \t]*)(\w+)\(([^;\n]*)\);(?=\s*})', forward, inner)
        if calls:
            text = body[:span[1]] + inner + body[span[2]:]
            text = text[:signature.start()] + 'u32' + text[signature.start() + 4:]
            for callee in calls:
                text = re.sub(rf'\bextern\s+void(?=\s+{re.escape(callee)}\s*\()', 'extern u32', text)
            out.append((f'return {value}, forward tail calls', text))
    return out


def reorder(body: str, locs, order: Tuple[int, ...]) -> str:
    lines = [body[s:e] for s, e, *_ in locs]
    return body[:locs[0][0]] + "".join(lines[i] for i in order) + body[locs[-1][1]:]


def scope_moves(body: str, name: str) -> List[Tuple[str, str]]:
    """Each local re-declared in an inner block around its uses; each local split off
    into its own declaration block after a blank line (a second declaration group)."""
    out: List[Tuple[str, str]] = []
    span = _function_body_span(body, name)
    if not span:
        return out
    locs = _locals(body, span)
    if not locs:
        return out
    inner = body[span[1]:span[2]]
    for s, e, typ, nm, dims in locs:
        uses = [span[1] + m.start() for m in re.finditer(rf"\b{re.escape(nm)}\b", inner)]
        uses = [u for u in uses if u >= locs[-1][1]]
        if not uses:
            continue
        line_start = body.rfind("\n", 0, uses[0]) + 1
        line_end = body.find("\n", uses[-1]) + 1
        # only when the use range is a run of whole statements at one nesting depth
        seg = body[line_start:line_end]
        if seg.count("{") != seg.count("}"):
            continue
        decl = body[s:e]
        text = body[:s] + body[e:]
        a, b = line_start - (e - s), line_end - (e - s)
        out.append((f"scope {nm}", text[:a] + "{\n" + decl + text[a:b] + "}\n" + text[b:]))
    return out


def normalise(body: str) -> str:
    """One declarator per line (`u32 a, b;` -> `u32 a;\n u32 b;`), so every family sees every local."""
    lines = []
    for line in body.splitlines(keepends=True):
        # Match only a declaration prefix before splitting declarators. A repeated
        # declaration regex backtracks exponentially on long generated call lines.
        match = re.fullmatch(r'([ \t]+)(struct[ \t]+\w+|[A-Za-z_]\w*)[ \t]+([^;]+);[ \t]*(\n?)', line)
        if match and ',' in match[3]:
            decls = match[3].split(',')
            if all(re.fullmatch(r'\*?\s*[A-Za-z_]\w*(?:\[[^\]]*\])*\s*', decl) for decl in decls):
                lines.append('\n'.join(f'{match[1]}{match[2]} {decl.strip()};' for decl in decls) + match[4])
                continue
        lines.append(line)
    return ''.join(lines)




FLIP = {"s32": "u32", "u32": "s32", "s16": "u16", "u16": "s16", "s8": "u8", "u8": "s8", "f32": "f64", "f64": "f32", "int": "u32"}

def argument_lifetimes(body, name, callees=None):
    """Materialize typed call arguments, optionally selected by retail evidence."""
    from .sdkimport import masked
    code=masked(body);span=_function_body_span(code,name)
    if not span:
        return []
    locs=_locals(body,span);out=[];groups={};calls=call_sites(code)
    prototypes={callee:args for callee,start,end,args in calls if start<span[0] and re.match(r'\s*;',code[end:])}
    for callee,start,end,args in calls:
        if not span[1]<=start<end<=span[2] or (callees is not None and callee not in callees):
            continue
        lo=code.rfind('\n',span[1],start)+1
        prefix=re.fullmatch(r'([ \t]*)((?:[A-Za-z_][\w>.\-\[\]]*\s*=\s*)?)',code[lo:start])
        suffix=re.match(r'[ \t]*;[ \t]*\n',code[end:])
        if not prefix or not suffix:
            continue
        indent,lhs=prefix.groups();hi=end+suffix.end()
        parts=[body[a:b].strip() for a,b in args]
        parameter_types = []
        if callee in prototypes:
            for a,b in prototypes[callee]:
                parameter = code[a:b].strip()
                typed = re.fullmatch('('+TYPE+r')(?:\s+\w+)?', parameter)
                parameter_types.append(typed[1] if typed else None)
        for k, a in enumerate(parts):
            known_type = parameter_types[k] if k < len(parameter_types) else None
            if not known_type and re.fullmatch(r"[A-Za-z_]\w*|-?\d+|0x[0-9A-Fa-f]+|&[A-Za-z_]\w*|\d+\.\d*f?", a):
                continue
            tname = f"lab_t{k}"
            while re.search(r'\b'+tname+r'\b',body):
                tname += '_'
            newparts = list(parts); newparts[k] = tname
            replacement=f"{indent}{tname} = {a};\n{indent}{lhs}{callee}({', '.join(newparts)});\n"
            text = body[:lo] + replacement + body[hi:]
            # The call's conversion belongs in the temporary too. In particular,
            # pointer arguments are not integers and narrow counts truncate here.
            cast = re.match(r'\(('+TYPE+r')\)',a)
            ty = known_type or (cast[1] if cast else None) or ("f32" if re.search(r"\d\.\d|f32|unk_\w*f\b", a) else "u32")
            ins_at = locs[-1][1] if locs else span[1] + 1
            text = text[:ins_at] + f"    {ty} {tname};\n" + text[ins_at:]
            out.append((f"hoist arg {k} of {callee}", text))
            groups.setdefault((callee,k,ty,tname),[]).append((lo,hi,replacement))
        result=re.search(r'(?m)^[ \t]*(?:extern\s+)?('+TYPE+r')\s*'+re.escape(callee)+r'\s*\(',body[:span[0]])
        if callees is not None and result and len(parameter_types)==len(parts) and all(ty and ty!='...' for ty in parameter_types):
            helper=name+'_call_'+callee
            while re.search(r'\b'+re.escape(helper)+r'\b',body):
                helper+='_'
            for order in (list(range(len(parts))),list(reversed(range(len(parts))))):
                params=', '.join(parameter_types[i]+' a'+str(i) for i in order)
                call=callee+'('+', '.join('a'+str(i) for i in range(len(parts)))+');'
                definition='static inline '+result[1]+' '+helper+'('+params+') { '+('' if result[1].strip()=='void' else 'return ')+call+' }\n'
                a,b=start,end
                text=body[:a]+helper+'('+', '.join(parts[i] for i in order)+')'+body[b:]
                at=body.rfind('\n',0,span[0])+1
                text=text[:at]+definition+text[at:]
                out.append((f'call parameter order {callee} '+','.join(map(str,order))+f' at {a}',text))
    for (callee,k,ty,tname),edits in groups.items():
        if len(edits)<2:
            continue
        text=body
        for a,b,value in reversed(edits):
            text=text[:a]+value+text[b:]
        at=locs[-1][1] if locs else span[1]+1
        text=text[:at]+f'    {ty} {tname};\n'+text[at:]
        out.append((f'hoist arg {k} of {callee} at every site',text))
    return out


def perturbations(body: str, name: str) -> List[Tuple[str, str, str]]:
    """(family, label, text) for every single rewrite."""
    out: List[Tuple[str, str, str]] = []
    span = _function_body_span(body, name)
    if not span:
        return out
    locs = _locals(body, span)
    # 1. declaration order: every permutation of up to 5 locals, else reverse and adjacent swaps
    if len(locs) >= 2:
        lines = [body[s:e] for s, e, *_ in locs]
        blk_s, blk_e = locs[0][0], locs[-1][1]
        perms = list(itertools.permutations(range(len(lines)))) if len(lines) <= 5 else \
            [tuple(reversed(range(len(lines))))] + [tuple(list(range(i)) + [i + 1, i] + list(range(i + 2, len(lines)))) for i in range(len(lines) - 1)]
        for perm in perms:
            if list(perm) == list(range(len(lines))):
                continue
            out.append(("decl-order", "order " + ",".join(locs[i][3] for i in perm), body[:blk_s] + "".join(lines[i] for i in perm) + body[blk_e:]))
    # 2. local types
    for s, e, typ, nm, dims in locs:
        t0 = typ.strip()
        if t0 in FLIP:
            out.append(("local-type", f"{nm}: {t0}->{FLIP[t0]}", body[:s] + body[s:e].replace(t0, FLIP[t0], 1) + body[e:]))
    # 3. inner block scope for a local: declare it where it is first used
    inner = body[span[1]:span[2]]
    for s, e, typ, nm, dims in locs:
        uses = [m.start() for m in re.finditer(rf"\b{re.escape(nm)}\b", inner)]
        uses = [u for u in uses if span[1] + u >= locs[-1][1]]
        if not uses:
            continue
        first = span[1] + uses[0]
        line_start = body.rfind("\n", 0, first) + 1
        last = span[1] + uses[-1]
        line_end = body.find("\n", last) + 1
        decl = body[s:e]
        text = body[:s] + body[e:]
        shift = e - s
        a, b = line_start - shift, line_end - shift
        text = text[:a] + "{\n" + decl + text[a:b] + "}\n" + text[b:]
        out.append(("inner-scope", f"scope {nm}", text))
    # Nested switch arms commonly reuse a spelling for unrelated locals. Count
    # reads inside the declaration's scope, rather than the whole function.
    from .sdkimport import masked
    code = masked(body)
    scopes, stack = [], []
    for token in re.finditer(r'[{}]', code):
        if token[0] == '{':
            stack.append(token.start())
        elif stack:
            scopes.append((stack.pop(), token.start()))
    # 4. temp inlining: `v = expr;` used once afterwards -> substitute
    for m in re.finditer(r"^(\s*)([A-Za-z_]\w*) = ([^;]+);\n", body[span[1]:span[2]], re.M):
        v, expr = m.group(2), m.group(3)
        start, end = span[1] + m.start(), span[1] + m.end()
        declarations = list(re.finditer(r'\b'+TYPE+r'\s*(?:(?<=\*)|\s)'+re.escape(v)+r'\s*[;=]', code[span[1]:start]))
        scope_end = span[2]
        for declaration in reversed(declarations):
            enclosing = [(a,b) for a,b in scopes if a < span[1]+declaration.start() < start < b]
            if enclosing:
                scope_end = min(enclosing, key=lambda s:s[1]-s[0])[1]
                break
        rest = body[end:scope_end]
        uses = list(re.finditer(rf"\b{re.escape(v)}\b", rest))
        if len(uses) == 1 and not re.search(rf"\b{re.escape(v)}\s*=", rest):
            # Move only into the immediately following statement. Calls, writes
            # or control flow between the definition and read can change it.
            prefix = rest[:uses[0].start()]
            if re.search(r'[;{}]|\+\+|--', prefix) or call_sites(expr+prefix):
                continue
            new_rest = rest[:uses[0].start()] + f"({expr})" + rest[uses[0].end():]
            out.append(("inline-temp", f"inline {v} at {start}", body[:start] + new_rest + body[scope_end:]))
    out.extend(("hoist-arg",label,text) for label,text in argument_lifetimes(body,name))
    # 6. increment forms
    for m in re.finditer(r"^(\s*)(\S[^=\n]*?) = \2 \+ 1;\n", body, re.M):
        out.append(("increment", "x = x + 1 -> x++", body[:m.start()] + f"{m.group(1)}{m.group(2)}++;\n" + body[m.end():]))
    for m in re.finditer(r"^(\s*)(\S[^\n]*?)\+\+;\n", body, re.M):
        out.append(("increment", "x++ -> x = x + 1", body[:m.start()] + f"{m.group(1)}{m.group(2)} = {m.group(2)} + 1;\n" + body[m.end():]))
    # 7. return forms
    for m in re.finditer(r"^(\s*)return ([A-Za-z_]\w*\([^;]*\));\n", body, re.M):
        out.append(("return-form", "return f() -> f(); return", body[:m.start()] + f"{m.group(1)}{m.group(2)};\n{m.group(1)}return;\n" + body[m.end():]))
    # 8. address forms
    for m in re.finditer(r"\(struct (\w+) \*\)&([A-Za-z_]\w*)", body):
        out.append(("address-form", f"drop cast on &{m.group(2)}", body[:m.start()] + f"&{m.group(2)}" + body[m.end():]))
    # 9. compare forms
    for m in re.finditer(r"\(([^()]+?) != 0\)", body):
        out.append(("compare-form", "x != 0 -> x", body[:m.start()] + f"({m.group(1)})" + body[m.end():]))
    for m in re.finditer(r"\(([^()]+?) == 0\)", body):
        out.append(("compare-form", "x == 0 -> !x", body[:m.start()] + f"(!({m.group(1)}))" + body[m.end():]))
    # 11. commute the operands of a commutative binary operator (register assignment follows
    #     operand order)
    for m in re.finditer(r"\(([A-Za-z_][\w>.\-\[\]]*) ([+*&|^]|==|!=) ([A-Za-z_][\w>.\-\[\]]*|-?\d+|0x[0-9A-Fa-f]+)\)", body[span[1]:span[2]]):
        a_, op, b_ = m.groups()
        if a_ == b_:
            continue
        s0 = span[1] + m.start(); e0 = span[1] + m.end()
        out.append(("commute", f"{a_} {op} {b_} -> {b_} {op} {a_}", body[:s0] + f"({b_} {op} {a_})" + body[e0:]))
    # 12. swap two adjacent statements that share no identifier (independent: order is free)
    from .dataimport import BASIC
    _, variables = declared_types(body,span[0])
    layouts = record_layouts(body,span[0],variables)
    stmts_ = [(m.start() + span[1], m.end() + span[1], m.group(0)) for m in re.finditer(r"^[ \t]*[^\n{}]+;\n", body[span[1]:span[2]], re.M)]
    for (s1, e1, t1), (s2, e2, t2) in zip(stmts_, stmts_[1:]):
        if e1 != s2:
            continue
        ids1 = set(re.findall(r"[A-Za-z_]\w*", t1)); ids2 = set(re.findall(r"[A-Za-z_]\w*", t2))
        shared=ids1 & ids2
        for root in tuple(shared):
            accesses=[]
            for text in (t1,t2):
                pattern=r'\b'+re.escape(root)+r'(?:(?:->|\.)\w+)+'
                members=re.findall(pattern,text)
                if not members or re.search(r'\b'+re.escape(root)+r'\b',re.sub(pattern,'',text)):break
                ranges=[]
                for expression in members:
                    layout=member_layout(expression,layouts,variables)
                    if not layout or layout[0]!=root or layout[3] is not None:break
                    typ=layout[2].strip();width=4 if '*' in typ else BASIC.get(typ,(0,))[0]
                    if not width or 'volatile' in typ:break
                    ranges.append((layout[1],layout[1]+width))
                if len(ranges)!=len(members):break
                accesses.append(ranges)
            if len(accesses)==2 and all(b<=c or d<=a for a,b in accesses[0] for c,d in accesses[1]):shared.remove(root)
        if shared or "(" in t1 and "(" in t2:  # shared values or two calls: order carries meaning
            continue
        out.append(("stmt-swap", f"swap `{t1.strip()[:30]}` / `{t2.strip()[:30]}`", body[:s1] + t2 + t1 + body[e2:]))
    pure=set()
    for helper in re.finditer(r'\bstatic\s+inline\s+'+TYPE+r'\s*(?:(?<=\*)|\s)(\w+)\([^;{}]*\)\s*\{',body[:span[0]]):
        helper_span=_function_body_span(body,helper[1])
        if not helper_span:continue
        text=body[helper_span[1]:helper_span[2]]
        locals_={r[3] for r in _locals(body,helper_span)}
        writes=re.findall(r'\b(\w+(?:(?:->|\.)\w+)*)\s*=(?!=)',text)
        if (not call_sites(text) and not re.search(r'volatile|\+\+|--|(?:^|;)\s*\*[^;]+=(?!=)',text)
                and all('->' not in w and w.split('.')[0] in locals_ for w in writes)):pure.add(helper[1])
    for (a,b,first),(c,d,second),(e,f,third) in zip(stmts_,stmts_[1:],stmts_[2:]):
        if body[b:c].strip() or body[d:e].strip():continue
        store=re.fullmatch(r'\s*(\w+(?:(?:->|\.)\w+)+)\s*=\s*(-?\d+|0x[0-9A-Fa-f]+)[uU]?;\s*',first)
        load=re.fullmatch(r'\s*(\w+)\s*=\s*([^;]+);\s*',second)
        address=re.fullmatch(r'\s*(\w+)\s*=\s*([^;]+);\s*',third)
        if not store or not load or not address or '*' not in variables.get(address[1],''):continue
        if re.search(r'\b'+re.escape(store[1])+r'\b',second+third) or re.search(r'\+\+|--|volatile',second+third):continue
        if any(fn not in pure for fn,_,_,_ in call_sites(second+third)):continue
        if re.search(r'\b'+re.escape(load[1])+r'\b',address[2]) and load[1]!=address[1]:
            out.append(('stmt-swap',f'form address before store at {a}',body[:a]+second+third+first+body[f:]))
    # 13. struct layout: shift every field of a block-private struct by a small delta (front padding)
    for m in re.finditer(r"(?:typedef\s+)?struct\s+\w*\s*\{([^}]*)\}", body):
        inner = m.group(1)
        for delta in (4, 8, -4, -8):
            if delta > 0:
                out.append(("struct-pad", f"+{delta} front padding", body[:m.start(1)] + f"\n    u8 lab_pad[{delta}];" + inner + body[m.end(1):]))
            else:
                pm = re.match(r"\s*u8\s+(\w+)\[(0x[0-9A-Fa-f]+|\d+)\];", inner)
                if pm and int(pm.group(2), 0) + delta > 0:
                    out.append(("struct-pad", f"{delta} front padding", body[:m.start(1)] + re.sub(r"^\s*u8\s+\w+\[[^\]]+\];", f"\n    u8 {pm.group(1)}[{int(pm.group(2), 0) + delta}];", inner, count=1) + body[m.end(1):]))
    # 14. a repeated non-trivial expression becomes a local computed once
    exprs = {}
    for m in re.finditer(r"[A-Za-z_]\w*(?:->|\.)\w+(?:(?:->|\.)\w+)*|[A-Za-z_]\w*\[[^\]]+\]", body[span[1]:span[2]]):
        exprs[m.group(0)] = exprs.get(m.group(0), 0) + 1
    for ex, n in exprs.items():
        if n < 2 or re.search(rf"{re.escape(ex)}\s*=[^=]", body[span[1]:span[2]]):
            continue
        first = body.find(ex, span[1])
        line_start = body.rfind("\n", 0, first) + 1
        ins_at = locs[-1][1] if locs else span[1] + 1
        ty = "f32" if re.search(r"f32|\bf\w*\b", ex) and False else "u32"
        text = body[:line_start] + f"    lab_v = {ex};\n" + body[line_start:]
        text = text.replace(ex, "lab_v")
        text = text.replace("    lab_v = lab_v;\n", f"    lab_v = {ex};\n", 1)
        text = text[:ins_at] + f"    {ty} lab_v;\n" + text[ins_at:]
        out.append(("repeat-to-local", f"local for {ex}", text))
    # 10. parameters: signedness flips and unused trailing parameters
    pm = re.search(rf"\b{re.escape(name)}\s*\(([^)]*)\)\s*\{{", body)
    if pm:
        params = [x.strip() for x in pm.group(1).split(",")] if pm.group(1).strip() not in ("", "void") else []
        for k, prm in enumerate(params):
            t0 = prm.split()[0]
            if t0 in FLIP:
                np = list(params); np[k] = prm.replace(t0, FLIP[t0], 1)
                out.append(("param-type", f"param {k}: {t0}->{FLIP[t0]}", body[:pm.start(1)] + ", ".join(np) + body[pm.end(1):]))
        for extra in (1, 2, 3):
            np = params + [f"u32 lab_unused{i}" for i in range(extra)]
            out.append(("param-count", f"+{extra} unused params", body[:pm.start(1)] + ", ".join(np) + body[pm.end(1):]))
    return out




FIELD_FLIP = {"u16": "s16", "s16": "u16", "u8": "s8", "s8": "u8", "u32": "s32", "s32": "u32"}


def _fn_span(body: str, name: str):
    return _function_body_span(body, name)


def extra_families(body: str, name: str) -> List[Tuple[str, str, str]]:
    """(family, label, text): near/far externs, pointer locals for globals, field signedness,
    loop direction, compare casts, call-result temps."""
    out: List[Tuple[str, str, str]] = []
    span = _fn_span(body, name)
    if not span:
        return out
    # 1. near <-> far: a scalar extern becomes an unknown-size array (far) or back
    for m in re.finditer(r"^extern ((?:struct \w+|[us](?:8|16|32)|f32|f64)) ([A-Za-z_]\w*);$", body, re.M):
        t, g = m.groups()
        text = body[:m.start()] + f"extern {t} {g}[];" + body[m.end():]
        if t.startswith("struct"):
            text = re.sub(rf"(?<![\w>.]){re.escape(g)}\.unk_", f"{g}[0].unk_", text)
        else:
            text = re.sub(rf"(?<![\w>.&]){re.escape(g)}\b(?!\s*\[|\s*=\s*\()", f"{g}[0]", text)
        out.append(("near-far", f"{g} far", text))
    for m in re.finditer(r"^extern ((?:struct \w+|[us](?:8|16|32)|f32|f64)) ([A-Za-z_]\w*)\[\];$", body, re.M):
        t, g = m.groups()
        text = body[:m.start()] + f"extern {t} {g};" + body[m.end():]
        text = text.replace(f"{g}[0]", g)
        out.append(("near-far", f"{g} near", text))
    # 2. a global struct accessed several times through a pointer local
    inner = body[span[1]:span[2]]
    for m in re.finditer(r"^extern struct (\w+) ([A-Za-z_]\w*)(\[\])?;$", body, re.M):
        st, g, arr = m.groups()
        uses = re.findall(rf"(?<![\w>.]){re.escape(g)}(?:\[0\])?\.unk_", inner)
        if len(uses) < 2 or f"p_{g}" in body:
            continue
        acc = f"{g}[0].unk_" if arr else f"{g}.unk_"
        new_inner = inner.replace(acc, f"p_{g}->unk_")
        # the assignment goes before the first statement; the declaration with the locals
        first_stmt = re.search(r"\n(\s*)(?![A-Za-z_][\w ]*\*?\s*[A-Za-z_]\w*(\[[^\]]*\])*;\n)([^\n]*;)", new_inner)
        if not first_stmt:
            continue
        at = first_stmt.start(3)
        new_inner = new_inner[:at] + f"p_{g} = (struct {st} *)&{g};\n    " + new_inner[at:]
        new_inner = f"\n    struct {st} *p_{g};" + new_inner
        out.append(("ptr-local", f"pointer local for {g}", body[:span[1]] + new_inner + body[span[2]:]))
    # 3. field signedness in block-private structs
    for m in re.finditer(r"^(    )([us](?:8|16|32)) (unk_[0-9A-F]+)(\[[^\]]*\])?;$", body, re.M):
        t = m.group(2)
        out.append(("field-type", f"{m.group(3)}: {t}->{FIELD_FLIP[t]}", body[:m.start(2)] + FIELD_FLIP[t] + body[m.end(2):]))
    # 4. counted loop direction
    for m in re.finditer(r"for \((\w+) = ([^;]+); \1 != 0; \1--\)", body):
        v, n = m.groups()
        out.append(("loop-form", "count down -> up", body[:m.start()] + f"for ({v} = 0; {v} < {n}; {v}++)" + body[m.end():]))
    for m in re.finditer(r"for \((\w+) = 0; \1 < ([^;]+); \1\+\+\)", body):
        v, n = m.groups()
        out.append(("loop-form", "count up -> down", body[:m.start()] + f"for ({v} = {n}; {v} != 0; {v}--)" + body[m.end():]))
    # 5. compare casts: drop or flip the cast on a compare operand
    for m in re.finditer(r"\((s32|u32)\)([A-Za-z_][\w>.\-\[\]]*) (==|!=|<|>|<=|>=)", inner):
        s0 = span[1] + m.start(); e0 = span[1] + m.end()
        other = "u32" if m.group(1) == "s32" else "s32"
        out.append(("compare-cast", f"drop ({m.group(1)}) on {m.group(2)}", body[:s0] + f"{m.group(2)} {m.group(3)}" + body[e0:]))
        out.append(("compare-cast", f"({m.group(1)})->({other}) on {m.group(2)}", body[:s0] + f"({other}){m.group(2)} {m.group(3)}" + body[e0:]))
    # 6. a returned parameter or constant on a function whose r3 is scratch: a void function
    ret = re.search(r"^(\s*)return ((?:arg\d+|v\d+|-?\d+|0x[0-9A-Fa-f]+));\n\}\s*$", body, re.M)
    if ret:
        sig = re.search(rf"^(u32|s32|s16|u16|s8|u8)( {re.escape(name)}\()", body, re.M)
        if sig:
            text = body[:sig.start(1)] + "void" + body[sig.end(1):]
            text = text.replace(ret.group(0), "}\n", 1)
            out.append(("void-return", "drop the returned value", text))
    # 7. an early return is the source's if-block around the tail: `if (c) { return; } S` -> `if (!c) { S }`
    for m in re.finditer(r"^(\s*)if \((.+?)\) \{ return; \}[^\n]*\n", inner, re.M):
        cond = m.group(2)
        tail = inner[m.end():]
        close = tail.rfind("\n")
        stmts_tail = tail[:close] if close >= 0 else tail
        if "{" in stmts_tail or "}" in stmts_tail or "return" in stmts_tail or not stmts_tail.strip():
            continue
        inv = {"==": "!=", "!=": "==", "<": ">=", ">": "<=", "<=": ">", ">=": "<"}
        mm = re.fullmatch(r"(.+?) (==|!=|<|>|<=|>=) (.+)", cond)
        ncond = f"{mm.group(1)} {inv[mm.group(2)]} {mm.group(3)}" if mm else f"!({cond})"
        new_inner = inner[:m.start()] + f"{m.group(1)}if ({ncond}) {{\n" + stmts_tail + f"\n{m.group(1)}}}" + tail[close:]
        out.append(("return-to-block", "early return -> if block", body[:span[1]] + new_inner + body[span[2]:]))
    # 8a. a call assigned to a field or global goes through a local first (the scheduler places
    #     the store differently when the value has a home)
    for m in re.finditer(r"^(\s*)([A-Za-z_][\w>.\-\[\]]*) = ([A-Za-z_]\w*\([^;]*\));\n", inner, re.M):
        ind, lhs, call = m.groups()
        if re.fullmatch(r"[A-Za-z_]\w*", lhs) and not re.search(rf"(?:->|\.)", lhs):
            continue  # already a plain local
        decl_at = _locals(body, span)
        ins_at = decl_at[-1][1] if decl_at else span[1] + 1
        new_inner = inner[:m.start()] + f"{ind}spell_call = {call};\n{ind}{lhs} = spell_call;\n" + inner[m.end():]
        text = body[:span[1]] + new_inner + body[span[2]:]
        text = text[:ins_at] + "    u32 spell_call;\n" + text[ins_at:]
        out.append(("call-to-local", f"local for {call[:30]}", text))
    # 9. 64-bit values the body split into two u32 halves (OSTime everywhere in the OS SDK): the
    #    halves travel as an adjacent register pair, so the split is invisible in the diff except
    #    as register order. Pairs are rejoined in the signature, at call sites, in stores, and in
    #    the callee's prototype.
    u64_1 = _u64_family(body, name, span, inner)
    out += u64_1
    seen_u64 = {t for _, _, t in u64_1}
    for _, label1, t1 in u64_1[:12]:
        sp1 = _fn_span(t1, name)
        if not sp1:
            continue
        for _, label2, t2 in _u64_family(t1, name, sp1, t1[sp1[1]:sp1[2]])[:12]:
            if t2 not in seen_u64 and t2 != body:
                seen_u64.add(t2); out.append(("u64", f"{label1} + {label2}", t2))
    # 8. a temporary for a call result used once: inline it
    for m in re.finditer(r"^(\s*)(t\d+) = ([A-Za-z_]\w*\([^;]*\));\n", inner, re.M):
        tn, call = m.group(2), m.group(3)
        rest = inner[m.end():]
        if len(re.findall(rf"\b{tn}\b", rest)) == 1:
            new_inner = inner[:m.start()] + re.sub(rf"\b{tn}\b", call, rest, count=1)
            out.append(("inline-call", f"inline {tn}", body[:span[1]] + new_inner + body[span[2]:]))
    # 10. measured idioms: a power-of-two division strength-reduced to a multiply with the
    #     variable first; a constant local turned into an inlined helper's parameter
    out += [("recipdiv", l, t) for l, t in reciprocal_divisions(body, name)]
    out += [("inlineparam", l, t) for l, t in constant_inline_parameters(body, name)]
    out += [("inlineregion", l, t) for l, t in region_inline_helpers(body, name)]
    return out


def call_sites(text, indirect=False):
    """Balanced call and argument spans, including casts and nested calls."""
    from .sdkimport import masked
    code = masked(text)
    stack, calls = [], []
    for token in re.finditer(r'(?P<name>\b[A-Za-z_]\w*)\s*\(|[()\[\]{},]',code):
        if token[0].endswith('('):
            name = token['name']
            if indirect and name is None and code[:token.start()].rstrip().endswith((')', ']')):
                name = '<indirect>'
            stack.append([name,token.start(),token.end(),[]])
        elif token[0] in '[{':
            stack.append([None,token.start(),token.end(),[]])
        elif token[0]==',' and stack and stack[-1][0]:
            frame=stack[-1];frame[3].append((frame[2],token.start()));frame[2]=token.end()
        elif token[0] in ')]}' and stack:
            name,start,last,args=stack.pop()
            if name:
                if args or code[last:token.start()].strip():
                    args.append((last,token.start()))
                calls.append((name,start,token.end(),args))
    return sorted(calls,key=lambda call:call[1])


def reaching_assignment(code, name, before, lower=0):
    """A scalar definition in the same straight-line region as its use.

    Deliberately stop at control flow or an address escape. Callers may inspect
    the expression, but must not move a load or a side effect to the use site.
    """
    region = code[lower:before]
    pattern = re.compile(r'(?m)^[ \t]*' + re.escape(name) + r'\s*=(?!=)\s*([^;{}\n]+);')
    definitions = list(pattern.finditer(region))
    if not definitions:
        return None
    match = definitions[-1]
    suffix = region[match.end():]
    if (re.search(r'[{}]|\b(?:if|else|while|for|do|switch|goto|case|break|continue|return)\b', suffix)
            or re.search(r'&\s*\b'+re.escape(name)+r'\b|\b'+re.escape(name)+r'\s*(?:[+*/&|^-]=|\+\+|--)', suffix)):
        return None
    return lower + match.start(1), lower + match.end(1)


def initialized_local(code, name, before, lower):
    """Require an assignment in an enclosing block, not solely a sibling arm."""
    scopes, scope = [], ()
    definitions = []
    pattern = r'[{}]|(?m:^[ \t]*)\b' + re.escape(name) + r'\s*=(?!=)[^;{}\n]+;'
    for token in re.finditer(pattern, code[lower:before]):
        if token[0] == '{':
            scopes.append(token.start()); scope = tuple(scopes)
        elif token[0] == '}':
            if scopes:
                scopes.pop()
            scope = tuple(scopes)
        else:
            definitions.append(scope)
    return any(scope[:len(parent)] == parent for parent in definitions)


def _pair_proto(text: str, callee: str, idx: int) -> Optional[str]:
    """The callee's extern prototype with parameters idx and idx+1 (both 32-bit ints) as one u64."""
    m = re.search(rf"^extern ([\w ]+?\*?) {re.escape(callee)}\(([^)]*)\);$", text, re.M)
    if not m:
        return None
    ps = [x.strip() for x in m.group(2).split(",")]
    if len(ps) <= idx + 1 or not all(re.fullmatch(r"(u32|s32|int|unsigned int|unsigned|long|unsigned long)", ps[k]) for k in (idx, idx + 1)):
        return None
    ps[idx:idx + 2] = ["u64"]
    return text[:m.start(2)] + ", ".join(ps) + text[m.end(2):]


def loop_lifetimes(body, name):
    """Separate loop-local homes while preserving their outgoing scalar values."""
    from .sdkimport import masked
    code=masked(body);span=_function_body_span(code,name)
    if not span:return []
    types={r[3]:r[2] for r in _locals(body,span) if not r[4] and
           ('{' not in r[2] or re.fullmatch(r'struct\s*\{\s*'+TYPE+r'\s+value;\s*\}',r[2]))};out=[]
    counted = []
    for callee,start,end,args in call_sites(code):
        if callee != 'for' or not span[1] <= start < end < span[2]:
            continue
        header = re.match(r'for\s*\(\s*(\w+)\s*=(?!=)', code[start:end])
        opening = re.match(r'\s*\{', code[end:])
        if not header or header[1] not in types or not opening:
            continue
        var = header[1]
        lo = end + opening.end() - 1
        hi, depth = lo + 1, 1
        while hi < span[2] and depth:
            depth += (code[hi] == '{') - (code[hi] == '}'); hi += 1
        if (depth or re.search(r'\bgoto\b', code[span[1]:span[2]])
                or re.search(r'&\s*\b' + re.escape(var) + r'\b', code[span[1]:span[2]])
                or any(a <= start < b for a,b,_ in counted)):
            continue
        local = 'fzgx_loop_' + var + '_' + str(start)
        if re.search(r'\b' + local + r'\b', code):
            continue
        region = body[start:hi]
        changes, previous = [], None
        for token in TOKEN.finditer(masked(region)):
            if token[0] == var and previous not in ('.', '->'):
                changes.append((token.start(), token.end()))
            previous = token[0]
        for a,b in reversed(changes):
            region = region[:a] + local + region[b:]
        # Keep the outgoing value, including a break from the loop. Dead-copy
        # elimination removes it when the next loop initializes the counter.
        replacement = ('{\n    ' + types[var] + ' ' + local + ';\n' + region +
                       '\n    ' + var + ' = ' + local + ';\n}')
        counted.append((start, hi, replacement))
    if counted:
        groups = [[edit] for edit in counted]
        if len(counted) > 1:
            groups.append(counted)
            groups.extend([edit for j,edit in enumerate(counted) if j != i] for i in range(len(counted)))
        for group in groups:
            text = body
            for lo,hi,replacement in reversed(group):
                text = text[:lo] + replacement + text[hi:]
            out.append(('lifetime counted loops at ' + ','.join(str(edit[0]) for edit in group), text))
    for callee,start,end,args in call_sites(code):
        if callee!='while' or not span[1]<=start<end<span[2]:continue
        opening=re.match(r'\s*\{',code[end:])
        if not opening:continue
        lo=end+opening.end()-1;depth=1;hi=lo+1
        while hi<span[2] and depth:
            depth+=(code[hi]=='{')-(code[hi]=='}');hi+=1
        if depth or re.search(r'\bgoto\b',code[lo:hi]):continue
        a=body.rfind('\n',0,start)+1;initializers=[]
        for _ in range(6):
            previous=re.search(r'(?m)^([ \t]*)(\w+)(?:\.value)?\s*=\s*[^;{}\n]+;\s*\Z',code[span[1]:a])
            if not previous or previous[2] not in types:break
            a=span[1]+previous.start();initializers.insert(0,previous[2])
        variables=[v for v in initializers if re.search(r'\b'+re.escape(v)+r'\b',code[start:hi]) and
                   not re.search(r'&\s*\b'+re.escape(v)+r'\b',code[span[1]:span[2]])]
        if not variables:continue
        groups=[(v,) for v in variables]
        groups+=list(itertools.combinations(variables,2))
        if len(variables)>2:groups.append(tuple(variables))
        for group in groups:
            names={v:'fzgx_loop_'+v+'_'+str(start) for v in group}
            if any(re.search(r'\b'+n+r'\b',code) for n in names.values()):continue
            region=body[a:hi];changes=[];previous=None
            for token in TOKEN.finditer(masked(region)):
                if token[0] in names and previous not in ('.','->'):
                    changes.append((token.start(),token.end(),names[token[0]]))
                previous=token[0]
            for x,y,value in reversed(changes):region=region[:x]+value+region[y:]
            declarations='\n'.join('    '+types[v]+' '+names[v]+';' for v in group)
            copies='\n'.join('    '+v+('.value' if '{' in types[v] else '')+' = '+names[v]+('.value' if '{' in types[v] else '')+';' for v in group)
            text=body[:a]+'{\n'+declarations+'\n'+region+'\n'+copies+'\n}'+body[hi:]
            out.append((f'lifetime loop at {start}: '+','.join(group),text))
    return out


def flag_stores(body, name):
    """Recover consecutive flag-field assignments hidden by a cached word."""
    from .sdkimport import masked
    code=masked(body);span=_function_body_span(code,name)
    if not span:return []
    pattern=(r'(?m)^([ \t]*)(\w+(?:(?:->|\.)\w+)+)\s*=\s*(\w+)\s*&\s*(0x[0-9a-fA-F]+)[uU]?;\s*\n'
             r'[ \t]*\2\s*=\s*\3\s*&\s*(0x[0-9a-fA-F]+)[uU]?;')
    sites=[]
    for m in re.finditer(pattern,code[span[1]:span[2]]):
        indent,member,var,first,second=m.groups();a,b=span[1]+m.start(),span[1]+m.end()
        assignment=reaching_assignment(code,var,a,span[1])
        if not assignment or code[slice(*assignment)].strip()!=member:continue
        first,second=int(first,16),int(second,16)
        if first&second!=second or first>0xffffffff:continue
        sites.append((a,b,indent,member,first,second))
    out=[]
    for selected in ([sites] if len(sites)>1 else [])+[[s] for s in sites]:
        text=body
        for a,b,indent,member,first,second in reversed(selected):
            replacement=indent+member+' &= '+hex(first)+'U;\n'+indent+member+' &= '+hex(second)+'U;'
            text=text[:a]+replacement+text[b:]
        out.append(('lifetime flag stores compound at '+','.join(str(s[0]) for s in selected),text))
    return out


def initialization_orders(body, name):
    """Reorder independent local initializations as one scheduling decision."""
    from .sdkimport import masked
    code=masked(body);span=_function_body_span(code,name)
    if not span:return []
    locals_={r[3] for r in _locals(body,span)};groups=[];group=[]
    for match in re.finditer(r'(?m)^[ \t]*[^\n]+;[ \t]*$',code[span[1]:span[2]]):
        declaration=DECL_RE.fullmatch(match[0])
        if declaration and declaration[1].strip() not in ('return','goto','break','continue'):
            locals_.add(declaration[2])
    for record in records(code,span[2]):
        if record['start']<span[1]:continue
        tail=re.match(r'\s*(\w+)\s*;',code[record['end']:])
        if tail:locals_.add(tail[1])
    for m in re.finditer(r'(?m)^([ \t]*)(\w+(?:\.\w+)?)\s*=\s*([^;{}\n]+);[ \t]*\n',code[span[1]:span[2]]):
        a,b=span[1]+m.start(),span[1]+m.end();var,value=m[2],m[3]
        if var.split('.')[0] not in locals_ or re.search(r'\b\w+\s*\(|->|[.\[\]+/?:=]|--',value) or re.search(r'&\s*\b'+re.escape(var)+r'\b',code[span[1]:span[2]]):
            if len(group)>1:groups.append(group)
            group=[];continue
        if group and (a!=group[-1][1] or len(group)==4):
            if len(group)>1:groups.append(group)
            group=[]
        group.append((a,b,var,value))
    if len(group)>1:groups.append(group)
    out=[];policies=defaultdict(list)
    for group in groups:
        names={r[2].split('.')[0] for r in group}
        if len(names)!=len(group) or any(names & set(re.findall(r'\b\w+\b',r[3])) for r in group):continue
        a,b=group[0][0],group[-1][1]
        for order in itertools.permutations(group):
            if list(order)==group:continue
            replacement=''.join(body[r[0]:r[1]] for r in order)
            text=body[:a]+replacement+body[b:]
            policies[(tuple(r[2] for r in group),tuple(r[2] for r in order))].append((a,b,replacement))
            out.append((f'lifetime initialization order at {a}: '+','.join(r[2] for r in order),text))
    for (before,after),changes in policies.items():
        if len(changes)<2:continue
        text=body
        for a,b,replacement in reversed(changes):text=text[:a]+replacement+text[b:]
        out.append(('lifetime repeated initialization order: '+','.join(after),text))
    return out


def reuse_temporaries(body, name):
    """Let a dead local carry a later result without extending its old value."""
    from .sdkimport import masked
    code=masked(body);span=_function_body_span(code,name)
    if not span:return []
    # A textual last use is not a death point across a back edge. In particular,
    # a for-loop increment precedes its body in C: reusing that counter in the
    # body changes the next iteration even though no later token names it.
    if re.search(r'\bgoto\b',code[span[1]:span[2]]):return []
    loops=[]
    starts=[(start,end) for callee,start,end,_ in call_sites(code)
            if callee in ('for','while') and span[1]<=start<end<span[2]]
    starts.extend((m.start(),m.end()) for m in re.finditer(r'\bdo\b',code)
                  if span[1]<=m.start()<span[2])
    for start,end in starts:
        opening=re.match(r'\s*\{',code[end:])
        if not opening:
            # The closing while of a do-loop has no body of its own.
            if code[end:].lstrip().startswith(';'):continue
            # Without a compound body we cannot bound nested if/else statements
            # using braces. Keep these locals live through the function.
            loops.append((start,span[2]));continue
        hi=end+opening.end();depth=1
        while hi<span[2] and depth:
            depth+=(code[hi]=='{')-(code[hi]=='}');hi+=1
        loops.append((start,hi if not depth else span[2]))
    locals_=_locals(body,span);_,variables=declared_types(code,span[0]);out=[]
    candidates=[]
    for a,b,ty,var,dims in locals_:
        if dims or ty.strip() not in ('u32','s32','int','unsigned') or re.search(r'&\s*\b'+re.escape(var)+r'\b',code[span[1]:span[2]]):continue
        uses=list(re.finditer(r'\b'+re.escape(var)+r'\b',code[b:span[2]]))
        if uses:
            last=b+uses[-1].end()
            last=max([last]+[hi for lo,hi in loops
                            if any(lo<=b+use.start()<hi for use in uses)])
            candidates.append((var,last))
    for m in re.finditer(r'(?m)^([ \t]*)(\w+)\s*=\s*([^;{}\n]+);',code[span[1]:span[2]]):
        a,b=span[1]+m.start(),span[1]+m.end();indent,var,value=m.groups()
        if variables.get(var,'').strip() not in ('u32','s32','int','unsigned'):continue
        if re.fullmatch(r'-?\d+|0x[0-9A-Fa-f]+',value.strip()):continue
        for temp,last in candidates:
            if last>=a or temp==var:continue
            text=body[:a]+indent+temp+' = '+value+';\n'+indent+var+' = '+temp+';'+body[b:]
            out.append((f'lifetime reuse {temp} for {var} at {a}',text))
    return out


def returned_regions(body, name):
    """Recover a context-free inlined getter from both arms of a value join."""
    from .sdkimport import masked
    code=masked(body);span=_function_body_span(code,name)
    if not span:return []
    _,variables=declared_types(code,span[0]);locals_=set()
    for line in code[span[1]:span[2]].splitlines():
        declaration=DECL_RE.match(line)
        if declaration and declaration[1] not in ('return','break','goto'):locals_.add(declaration[2])
    signature=code[span[0]:span[1]]
    for part in signature[signature.index('(')+1:signature.rfind(')')].split(','):
        match=re.search(r'\b(\w+)\s*$',part)
        if match:locals_.add(match[1])
    closing={};stack=[]
    for token in re.finditer(r'[{}]',code[span[1]-1:span[2]+1]):
        at=span[1]-1+token.start()
        if token[0]=='{':stack.append(at)
        elif stack:closing[stack.pop()]=at
    out=[]
    for callee,start,end,args in call_sites(code):
        if callee!='if' or not span[1]<=start<end<span[2]:continue
        left=re.match(r'\s*\{',code[end:])
        if not left:continue
        a=end+left.end()-1;b=closing.get(a)
        if b is None:continue
        right=re.match(r'\s*else\s*\{',code[b+1:])
        if not right:continue
        c=b+right.end();d=closing.get(c)
        if d is None:continue
        assignments=[]
        for lo,hi in ((a+1,b),(c+1,d)):
            matches=list(re.finditer(r'\b(\w+)\s*=\s*([^;{}]+);\s*$',code[lo:hi]))
            if not matches:break
            match=matches[-1];assignments.append((lo+match.start(),lo+match.end(),match[1],body[lo+match.start(2):lo+match.end(2)]))
        if len(assignments)!=2 or assignments[0][2]!=assignments[1][2]:continue
        var=assignments[0][2];ty=variables.get(var,'')
        if var not in locals_ or not ty or '*' in ty or any(q in ty for q in ('volatile','const')):continue
        region=body[start:d+1]
        for lo,hi,_,value in reversed(assignments):region=region[:lo-start]+'return '+value+';\n'+region[hi-start:]
        identifiers=[];previous=None
        for token in TOKEN.finditer(masked(region)):
            if token[0] in locals_ and previous not in ('.','->'):identifiers.append(token[0])
            previous=token[0]
        if identifiers or re.search(r'\b(?:goto|continue|return)\b',code[start:d+1]):continue
        helper=name+'_value_region'
        while re.search(r'\b'+helper+r'\b',code):helper+='_'
        first=body[start:b+1];last=body[c+1:d]
        lo,hi,_,value=assignments[0];first=first[:lo-start]+'return '+value+';\n'+first[hi-start:]
        lo,hi,_,value=assignments[1];last=last[:lo-c-1]+'return '+value+';\n'+last[hi-c-1:]
        for label,contents in (('',region),(' early return',first+'\n'+last)):
            definition='static inline '+ty+' '+helper+'(void) {\n'+contents+'\n}\n'
            text=body[:start]+var+' = '+helper+'();'+body[d+1:]
            pos=body.rfind('\n',0,span[0])+1
            text=text[:pos]+definition+text[pos:]
            out.append((f'lifetime returned region {var} at {start}'+label,text))
            tail=code[d+1:span[2]]
            consumer=re.match(r'\s*if\s*\(\s*('+re.escape(var)+r')\s*(?:==|!=|<=|>=|<|>)\s*\w+\s*\)',tail)
            if consumer and len(re.findall(r'\b'+re.escape(var)+r'\b',tail))==1:
                x,y=d+1+consumer.start(1),d+1+consumer.end(1)
                text=body[:start]+body[d+1:x]+helper+'()'+body[y:]
                text=text[:pos]+definition+text[pos:]
                out.append((f'lifetime returned region {var} at {start}'+label+' into condition',text))
    return out




def promoted_locals(body, name):
    """Keep narrow conversions explicit while using a full-width local home."""
    from .sdkimport import masked
    code=masked(body);span=_function_body_span(code,name)
    if not span:
        return []
    stack=[];scopes=[]
    for token in re.finditer(r'[{}]',code[span[1]-1:span[2]+1]):
        at=span[1]-1+token.start()
        if token[0]=='{':stack.append(at)
        elif stack:scopes.append((stack.pop(),at))
    out=[];groups={}
    for decl in re.finditer(r'(?m)^[ \t]*(s8|u8|s16|u16|short|unsigned short|signed char|unsigned char)\s+(\w+)\s*(?:=\s*([^;{}]+))?;',code[span[1]:span[2]]):
        a,b=span[1]+decl.start(),span[1]+decl.end();ty,var=decl[1],decl[2]
        enclosing=[(lo,hi) for lo,hi in scopes if lo<a<b<=hi]
        if not enclosing:continue
        end=min(enclosing,key=lambda s:s[1]-s[0])[1];region=code[b:end]
        ident=r'(?<![.>\w])'+re.escape(var)+r'\b'
        if re.search(r'&\s*'+ident,region) or re.search(ident+r'\s*(?:\+\+|--|[+*/&|^%-]=)|(?:\+\+|--)\s*'+ident,region):continue
        if re.search(TYPE+r'\s+'+re.escape(var)+r'\s*[;=]',region):continue
        assignments=list(re.finditer(ident+r'\s*=(?!=)\s*([^;{}]+);',region))
        if not assignments and decl[3] is None:continue
        new='s32' if ty in ('s8','s16','short','signed char') else 'u32'
        changes=[(span[1]+decl.start(1),span[1]+decl.end(1),new)]
        if decl[3] is not None:
            lo,hi=span[1]+decl.start(3),span[1]+decl.end(3)
            narrow_load=re.fullmatch(r'\s*\(\s*\*\s*\(\s*'+re.escape(ty)+r'(?:\s+volatile)?\s*\*\s*\)\s*&\s*\([^();]+\)\s*\)\s*',code[lo:hi])
            if not narrow_load:
                changes.append((lo,hi,'('+ty+')('+body[lo:hi]+')'))
        changes.extend((b+m.start(1),b+m.end(1),'('+ty+')('+body[b+m.start(1):b+m.end(1)]+')') for m in assignments)
        text=body
        for x,y,value in sorted(changes,reverse=True):text=text[:x]+value+text[y:]
        out.append((f'lifetime promoted {var} {ty}->{new} at {a}',text))
        groups.setdefault((var,ty,new),[]).extend(changes)
    for (var,ty,new),changes in groups.items():
        if sum(value==new for _,_,value in changes)<2:continue
        text=body
        for a,b,value in sorted(changes,reverse=True):text=text[:a]+value+text[b:]
        out.insert(0,(f'lifetime promoted {var} {ty}->{new} at every site',text))
    return out


def wide_member_values(body, name):
    """Recover 64-bit values split across adjacent, explicitly typed members."""
    from .sdkimport import masked
    code=masked(body);span=_function_body_span(code,name)
    if not span:
        return []
    fields,variables=declared_types(code,span[0]);layouts=record_layouts(code,span[0],variables)
    member=r'\w+(?:(?:->|\.)\w+)+'
    def pair(high,low):
        h=re.fullmatch(r'(.+)(->|\.)(\w+)',high);l=re.fullmatch(r'(.+)(->|\.)(\w+)',low)
        if not h or not l or h.groups()[:2]!=l.groups()[:2]:
            return None
        owner=member_type(h[1],fields,variables)
        tag=re.sub(r'\b(?:extern|static|struct|const|volatile)\b|\*','',owner).strip()
        layout=layouts.get(tag,{})
        a,b=layout.get(h[3]),layout.get(l[3])
        if not a or not b or b[0]!=a[0]+4 or a[2] or b[2] or a[1] not in ('u32','unsigned int') or b[1] not in ('u32','unsigned int'):
            return None
        if 'volatile' in owner or any('volatile' in member_type(x,fields,variables) for x in (high,low)):
            return None
        return '(*(const u64 *)&'+high+')'
    edits=[]
    shifted=re.compile(r'\(\s*('+member+r')\s*<<\s*(\d+)\s*\)\s*\|\s*\(\s*('+member+r')\s*>>\s*(\d+)\s*\)')
    for m in shifted.finditer(code,span[1],span[2]):
        value=pair(m[1],m[3]);left,right=int(m[2]),int(m[4])
        if value and 0<left<32 and left+right==32:
            edits.append((m.start(),m.end(),f'((u32)({value} >> {right}))','shift'))
    compared=re.compile(r'\(\s*('+member+r')\s*\^\s*('+member+r')\s*\)\s*\|\s*\(\s*('+member+r')\s*\^\s*('+member+r')\s*\)')
    conditions=[args[0] for callee,start,end,args in call_sites(code) if callee in ('if','while') and len(args)==1 and span[1]<=start<end<=span[2]]
    for m in compared.finditer(code,span[1],span[2]):
        left,right=pair(m[1],m[3]),pair(m[2],m[4])
        if not left or not right:
            continue
        for a,b in conditions:
            if not a<=m.start()<m.end()<=b or not re.fullmatch(r'\s*\(*\s*',code[a:m.start()]):
                continue
            suffix=re.fullmatch(r'\s*\)*\s*(==|!=)\s*0\s*\)*\s*',code[m.end():b])
            if suffix:
                edits.append((a,b,f'{left} {suffix[1]} {right}','comparison'))
    out=[]
    for a,b,value,kind in edits:
        out.append((f'recover wide member {kind} at {a}',body[:a]+value+body[b:]))
    if len(edits)>1:
        text=body
        for a,b,value,_ in sorted(edits,reverse=True):
            text=text[:a]+value+text[b:]
        out.insert(0,('recover wide members at every site',text))
    return out


def _u64_family(body: str, name: str, span, inner: str) -> List[Tuple[str, str, str]]:
    out: List[Tuple[str, str, str]] = []
    protos = set(re.findall(r"^extern [\w ]+?\*? ([A-Za-z_]\w*)\([^)]*\);$", body, re.M))
    # `#define InsertAlarm InsertAlarm_8000AC44`: the call names the alias, the prototype the symbol
    aliases = dict(re.findall(r"^#define (\w+) (\w+)$", body, re.M))
    protos |= {a for a, t in aliases.items() if t in protos}
    def proto_name(c):
        return aliases.get(c, c)
    # (a) two adjacent zero arguments: one u64 zero (materialised low word first, as retail does)
    declared = {m.group(1) for m in re.finditer(r"^extern [\w ]+?\*? ([A-Za-z_]\w*)\(", body, re.M)} | set(aliases)
    keywords = {"if", "while", "for", "switch", "return", "sizeof"}
    for callee,_,_,arguments in call_sites(inner):
        if callee == name or callee in keywords or not arguments:
            continue
        al = [inner[a:b].strip() for a,b in arguments]
        for k in range(len(al) - 1):
            if al[k] == "0" and al[k + 1] == "0":
                new_inner = inner[:arguments[0][0]] + ", ".join(al[:k] + ["(u64)0"] + al[k + 2:]) + inner[arguments[-1][1]:]
                text = body[:span[1]] + new_inner + body[span[2]:]
                text = _pair_proto(text, proto_name(callee), k) if callee in declared else text
                if text:
                    out.append(("u64", f"{callee}: zero pair at {k} -> (u64)0", text))
    # (b) two adjacent 32-bit parameters that only ever travel together: one u64 parameter
    sig = re.search(rf"\b{re.escape(name)}\s*\(([^)]*)\)\s*\{{", body)
    if sig and sig.group(1).strip() not in ("", "void"):
        ps = [x.strip() for x in sig.group(1).split(",")]
        for k in range(len(ps) - 1):
            ma = re.fullmatch(r"(u32|s32) (\w+)", ps[k]); mb = re.fullmatch(r"(u32|s32) (\w+)", ps[k + 1])
            if not (ma and mb):
                continue
            A, B = ma.group(2), mb.group(2)
            pair_re = rf"\b{A}, {B}\b"
            # a store of both halves to fields 4 bytes apart, in either order
            store_re = (rf"^(\s*)([A-Za-z_][\w>.\-\[\]]*?)unk_([0-9A-Fa-f]+) = ({A}|{B});\n\s*\2unk_([0-9A-Fa-f]+) = ({A}|{B});\n")
            stores = [m for m in re.finditer(store_re, inner, re.M) if {m.group(4), m.group(6)} == {A, B}
                      and abs(int(m.group(3), 16) - int(m.group(5), 16)) == 4]
            n_pair = len(re.findall(pair_re, inner))
            if n_pair + len(stores) == 0:
                continue
            if len(re.findall(rf"\b{A}\b", inner)) != n_pair + len(stores) or len(re.findall(rf"\b{B}\b", inner)) != n_pair + len(stores):
                continue
            P = f"{A}_{B}"
            new_inner = inner
            for m in reversed(stores):
                lo = min(int(m.group(3), 16), int(m.group(5), 16))
                # the high half is the first parameter (the lower register); the u64 store covers both
                new_inner = new_inner[:m.start()] + f"{m.group(1)}*(u64 *)&{m.group(2)}unk_{lo:X} = {P};\n" + new_inner[m.end():]
            # call sites: the pair becomes one argument; the callee's prototype pairs the same slot
            text = body[:span[1]] + new_inner + body[span[2]:]
            ok = True
            for callee,_,_,arguments in call_sites(new_inner):
                al = [new_inner[a:b].strip() for a,b in arguments]
                for j in range(len(al) - 1):
                    if al[j] == A and al[j + 1] == B:
                        t2 = _pair_proto(text, proto_name(callee), j)
                        if t2 is None:
                            ok = False
                        else:
                            text = t2
            if not ok:
                continue
            text = re.sub(pair_re, P, text)
            text = text.replace(sig.group(1), ", ".join(ps[:k] + [f"u64 {P}"] + ps[k + 2:]), 1)
            out.append(("u64", f"parameters {A}, {B} -> u64 {P}", text))
    # (d) a call argument that is a cast local or a plain local: dropped, with the prototype
    #     shortened (retail's register there was scratch; the body invented the argument)
    for callee,_,_,arguments in call_sites(inner):
        if callee == name or callee in keywords or not arguments:
            continue
        al = [inner[a:b].strip() for a,b in arguments]
        for k, arg in enumerate(al):
            if not re.fullmatch(r"\((?:u32|s32)\)\w+|[a-z]\w*", arg) or len(al) < 2:
                continue
            new_inner = inner[:arguments[0][0]] + ", ".join(al[:k] + al[k + 1:]) + inner[arguments[-1][1]:]
            text = body[:span[1]] + new_inner + body[span[2]:]
            if callee in declared:
                pm = re.search(rf"^extern ([\w ]+?\*?) {re.escape(proto_name(callee))}\(([^)]*)\);$", text, re.M)
                if not pm:
                    continue
                ps = [x.strip() for x in pm.group(2).split(",")]
                if len(ps) != len(al):
                    continue
                del ps[k]
                text = text[:pm.start(2)] + ", ".join(ps) + text[pm.end(2):]
            out.append(("u64", f"{callee}: drop argument {k} ({arg})", text))
    # (c) a u64 value stored as two halves: one store
    for m in re.finditer(r"^(\s*)([A-Za-z_][\w>.\-\[\]]*?)unk_([0-9A-Fa-f]+) = \(u32\)\((\w+) >> 32\);\n\s*\2unk_([0-9A-Fa-f]+) = \(u32\)\4;\n", inner, re.M):
        if int(m.group(5), 16) - int(m.group(3), 16) != 4:
            continue
        new_inner = inner[:m.start()] + f"{m.group(1)}*(u64 *)&{m.group(2)}unk_{m.group(3)} = {m.group(4)};\n" + inner[m.end():]
        out.append(("u64", f"{m.group(4)}: halves -> one u64 store", body[:span[1]] + new_inner + body[span[2]:]))
    return out


def all_rewrites(body: str, name: str) -> List[Tuple[str, str, str]]:
    """Expose every site; the engine owns the compilation budget."""
    out: List[Tuple[str, str, str]] = []
    for fn in (lambda b, n: perturbations(b, n),
               lambda b, n: [("regalloc", l, t) for l, t in rewrites(b, n)],
               extra_families):
        try:
            out += fn(body, name)
        except Exception:
            continue
    kept = list(out)
    by_fam: Dict[str, List[str]] = {}
    for fam, label, text in out:
        by_fam.setdefault(fam, []).append(text)
    # every edit of a family applied together (the same fix at every site): the composition of
    # the per-site texts when their edits do not overlap
    for fam, texts in by_fam.items():
        if len(texts) < 2 or fam in ("decl-order", "regalloc", "param-count", "struct-pad", "inlineparam",
                                          "inlineregion"):
            continue
        changes=[]
        for t in texts[:24]:
            ops=edits(body,t)
            if any(a<max(d,c+1) and c<max(b,a+1) for a,b,_ in ops for c,d,_ in changes):
                continue
            changes.extend(ops)
        text=body
        for a,b,value in sorted(changes,reverse=True):text=text[:a]+value+text[b:]
        if text != body and text not in texts:
            kept.append((fam, f"{fam} compatible sites", text))
    return kept


def fitness(tw: List[int], ow: List[int]) -> Tuple[float, float]:
    """(aligned matched words as a percent, positional percent)."""
    if not tw or not ow:
        return (0.0, 0.0)
    n = max(len(tw), len(ow))
    pos, _ = oracle.word_score(tw, ow)
    return (100.0 * (n - distance(tw, ow)) / n, pos)




TOKEN = re.compile(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|'
                   r'[A-Za-z_]\w*|(?:0[xX][0-9a-fA-F]+|\d+(?:\.\d*)?)(?:[eE][+-]?\d+)?[uUlLfF]*|'
                   r'->|\+\+|--|<<|>>|<=|>=|==|!=|&&|\|\||[+*/%&|^!-]=|[^\s]', re.S)
PREC = {'=': 1, '+=': 1, '-=': 1, '*=': 1, '/=': 1, '|=': 1, '&=': 1,
        '||': 2, '&&': 3, '|': 4, '^': 5, '&': 6, '==': 7, '!=': 7,
        '<': 8, '>': 8, '<=': 8, '>=': 8, '<<': 9, '>>': 9,
        '+': 10, '-': 10, '*': 11, '/': 11, '%': 11}
COMMUTE = {'+', '*', '&', '|', '^', '==', '!='}


def commutations(body, name, operations=None):
    """Parse expression precedence, retaining source spans and parenthesization.

    Calls, updates and assignments make an expression ineligible to commute,
    though pure subexpressions within it remain eligible. Casts and unsupported
    syntax end a parse; compilation checks all proposals against retail.
    """
    span = _function_body_span(body, name)
    if not span:
        return []
    tokens = [(m[0], m.start() + span[1], m.end() + span[1])
              for m in TOKEN.finditer(body[span[1]:span[2]])
              if not m[0].startswith(('/*', '//'))]
    proposals, sites = [], defaultdict(list)
    types = {'void', 'char', 'short', 'int', 'long', 'signed', 'unsigned', 'float', 'double',
             'u8', 's8', 'u16', 's16', 'u32', 's32', 'u64', 's64', 'f32', 'f64'}
    types.update(re.findall(r'\btypedef\s+[^;{}]+\s+(\w+)\s*;', body))

    def parse(i, minimum=1):
        if i >= len(tokens):
            raise ValueError
        tok, start, end = tokens[i]
        i += 1
        pure = True
        if tok == '(':
            close = i
            while close < len(tokens) and (re.fullmatch(r'\w+', tokens[close][0]) or tokens[close][0] == '*'):
                close += 1
            cast = (i < close < len(tokens) and tokens[close][0] == ')' and
                    (tokens[i][0] in types or tokens[i][0] in ('struct', 'union', 'enum', 'const', 'volatile')))
            if cast:
                i, (_, end, pure) = parse(close + 1, 12)
            else:
                i, (_, end, pure) = parse(i)
                if i >= len(tokens) or tokens[i][0] != ')':
                    raise ValueError
                end = tokens[i][2]
                i += 1
        elif tok in ('-', '+', '!', '~', '*', '&', '++', '--'):
            i, (_, end, pure) = parse(i, 12)
            pure &= tok not in ('++', '--')
        elif not re.match(r'[\w"\']', tok):
            raise ValueError
        while i < len(tokens):
            op = tokens[i][0]
            if op in ('->', '.') and i + 1 < len(tokens):
                end = tokens[i + 1][2]
                i += 2
                continue
            if op == '[':
                j, _ = parse(i + 1)
                if j >= len(tokens) or tokens[j][0] != ']':
                    raise ValueError
                # Index expressions can have side effects too.
                pure &= not any(t[0] in ('(', '++', '--', '=') for t in tokens[i + 1:j])
                end, i = tokens[j][2], j + 1
                continue
            if op == '(':
                # Parse arguments to discover commutations inside calls.
                j = i + 1
                while j < len(tokens) and tokens[j][0] != ')':
                    j, _ = parse(j)
                    if j < len(tokens) and tokens[j][0] == ',':
                        j += 1
                    else:
                        break
                if j >= len(tokens) or tokens[j][0] != ')':
                    raise ValueError
                end, i, pure = tokens[j][2], j + 1, False
                continue
            if op in ('++', '--'):
                end, i, pure = tokens[i][2], i + 1, False
                continue
            precedence = PREC.get(op, 0)
            if precedence < minimum:
                break
            j, (rs, re_, rp) = parse(i + 1, precedence + (precedence != 1))
            if operations is not None and pure and rp and precedence > 1:
                operations.append({'start': start, 'end': re_, 'left': (start, end),
                                   'right': (rs, re_), 'op': op})
            if op in COMMUTE and pure and rp and body[start:end] != body[rs:re_]:
                replacement = f'(({body[rs:re_]}) {op} ({body[start:end]}))'
                proposals.append((f'operand {op} at {start}', body[:start] + replacement + body[re_:]))
                sites[(body[start:re_], replacement, op)].append((start, re_))
            end, i, pure = re_, j, pure and rp and precedence != 1
        return i, (start, end, pure)

    i = 0
    while i < len(tokens):
        try:
            j, _ = parse(i)
            i = max(i + 1, j)
        except (ValueError, RecursionError):
            i += 1
    # CSE couples identical occurrences: changing one may leave the shared
    # expression's operand order determined by the unchanged occurrence.
    grouped = []
    for (old, replacement, op), ranges in sites.items():
        ranges = sorted(set(ranges))
        if len(ranges) > 1 and all(b <= c for (_, b), (c, _) in zip(ranges, ranges[1:])):
            text = body
            for a, b in reversed(ranges):
                text = text[:a] + replacement + text[b:]
            grouped.append((f'shared operands {old}', text))
    # Repeated blocks often use different temporary names. Exact text grouping
    # misses their coupled operand choices; group disjoint scalar expressions by
    # operator as well. Exclude pointer arithmetic and nested overlapping trees.
    by_operator = defaultdict(list)
    for (old, replacement, op), ranges in sites.items():
        if re.search(r'\*\s*\)|\b(?:u8|s8|void|char)\b|\[', old):
            continue
        for a,b in ranges:
            by_operator[op].append((a,b,replacement))
    for op, ranges in by_operator.items():
        ranges=sorted(set(ranges))
        if len(ranges)>1 and all(b<=c for (_,b,_),(c,_,_) in zip(ranges,ranges[1:])):
            text=body
            for a,b,replacement in reversed(ranges):
                text=text[:a]+replacement+text[b:]
            grouped.append((f'coupled scalar operands {op}',text))
    return list(dict.fromkeys(grouped + proposals))


def shift_products(body, name):
    """Integer products by a power of two spelled as shifts, alone and with the enclosing
    addition's operands swapped.

    MWCC orders the operands of an integer `add` differently for `E * 2 + n` and
    `(E << 1) + n` although both lower to `slwi`: the product form emits `add rD, n, shifted`
    under every operand order of the source, the shift form follows source order
    (fn_1_112F40: `(n - 1) * 2 + n` gave `add r0, r5, r0`, six spellings stayed there;
    `((n - 1) << 1) + n` gives retail's `add r0, r0, r5` and matches). Commuting the
    product's own operands never reaches it. Floating operands are left alone."""
    operations = []
    commutations(body, name, operations)
    span = _function_body_span(body, name)
    if not span:
        return []
    floats = set(re.findall(r'\b(?:f32|f64|float|double)\s+\**\s*(\w+)', body[:span[2]]))
    parents = [o for o in operations if o['op'] in ('+', '-')]
    out, edits = [], []
    for o in operations:
        if o['op'] != '*':
            continue
        for side, other in (('right', 'left'), ('left', 'right')):
            literal = body[o[side][0]:o[side][1]].strip()
            if not re.fullmatch(r'(?:0x[0-9A-Fa-f]+|\d+)[uU]?', literal):
                continue
            value = int(literal.rstrip('uU'), 0)
            if value < 2 or value & (value - 1) or value > 1 << 30:
                continue
            operand = body[o[other][0]:o[other][1]]
            if (re.search(r'\((?:f32|f64|float|double)\s*\*?\)|\d\.\d*f?\b|\.\d+f?\b', operand)
                    or any(w in floats for w in re.findall(r'[A-Za-z_]\w*', operand))):
                continue
            # the product's full extent, parentheses around a leading operand included
            a, b = o['start'], o['end']
            replacement = f'(({operand}) << {value.bit_length() - 1})'
            edits.append((a, b, replacement))
            out.append((f'shift product {body[a:b]}', body[:a] + replacement + body[b:]))
            parent = next((q for q in parents if q['op'] == '+' and (q['left'] == (a, b) or q['right'] == (a, b))), None)
            if parent:
                (la, lb), (ra, rb) = parent['left'], parent['right']
                left = replacement if (la, lb) == (a, b) else body[la:lb]
                right = replacement if (ra, rb) == (a, b) else body[ra:rb]
                out.append((f'shift product {body[a:b]}, operands swapped',
                            body[:la] + f'({right}) + ({left})' + body[rb:]))
            break
    if len(edits) > 1 and all(b <= c for (_, b, _), (c, _, _) in zip(sorted(edits), sorted(edits)[1:])):
        text = body
        for a, b, value in sorted(edits, reverse=True):
            text = text[:a] + value + text[b:]
        out.append(('shift every product', text))
    return list(dict.fromkeys(out))


def probes(body, name, limit=32):
    """Linear probes, not permutations; each observed response is reusable."""
    choices = commutations(body, name)
    normalized = normalise(body)
    span = _function_body_span(normalized, name)
    if span:
        locs = _locals(normalized, span)
        lines = [normalized[s:e] for s, e, *_ in locs]
        for i in range(len(locs) - 1):
            order = list(range(len(locs)))
            order[i:i + 2] = reversed(order[i:i + 2])
            if _order_ok(locs, lines, order):
                choices.append((f'adjacent declarations {i}', reorder(normalized, locs, order)))
    # Scope and materialization change live ranges; they are not register renames.
    nested = []
    if span:
        declarations = [(m.start() + span[1], m.end() + span[1], m[0])
                        for m in re.finditer(r'[^\n]*\n', normalized[span[1]:span[2]])
                        if (match := DECL_RE.match(m[0].rstrip('\n')))
                        and match[1].strip() not in ('return', 'goto', 'break', 'continue')]
        for (a, b, first), (c, d, second) in zip(declarations, declarations[1:]):
            if b != c:
                continue
            fm, sm = (DECL_RE.match(line.rstrip('\n')) for line in (first, second))
            if re.search(r'\b' + re.escape(fm[2]) + r'\b', sm[4] or ''):
                continue
            nested.append((f'block declarations {fm[2]}, {sm[2]}', normalized[:a] + second + first + normalized[d:]))
    from .fixup_evidence import optimizer_pragmas
    families = [choices, nested, scope_moves(normalized, name),
                optimizer_pragmas(body, name),
                through_local(normalized, name), split_inits(normalized, name)]
    out, seen = [], {body}
    for i in range(max(map(len, families), default=0)):
        for family in families:
            if i < len(family) and family[i][1] not in seen:
                seen.add(family[i][1])
                out.append(family[i])
                if len(out) == limit:
                    return out
    return out


def line_opcodes(left, right, area=4_000_000):
    """difflib opcodes over two line lists, computed on the lines between the shared prefix
    and suffix only. `SequenceMatcher(autojunk=False)` is quadratic per longest-match on
    repeated lines: a body carrying a retail data initializer (fn_16_1038's far block, 15,273
    identical `0x0, ...` lines) kept one alignment running for minutes and a generation round
    for hours. A trimmed middle whose product of lengths still exceeds `area` is reported
    as one replace: coarser spans, never a stall."""
    n = min(len(left), len(right))
    pre = 0
    while pre < n and left[pre] == right[pre]:
        pre += 1
    suf = 0
    while suf < n - pre and left[-suf - 1] == right[-suf - 1]:
        suf += 1
    a, b = left[pre:len(left) - suf], right[pre:len(right) - suf]
    if not a and not b:
        return [('equal', 0, len(left), 0, len(right))] if left else []
    if len(a) * len(b) > area:
        ops = [('replace', 0, len(a), 0, len(b))]
    else:
        ops = difflib.SequenceMatcher(None, a, b, autojunk=False).get_opcodes()
    out = [(tag, i1 + pre, i2 + pre, j1 + pre, j2 + pre) for tag, i1, i2, j1, j2 in ops]
    if pre:
        out.insert(0, ('equal', 0, pre, 0, pre))
    if suf:
        out.append(('equal', len(left) - suf, len(left), len(right) - suf, len(right)))
    return out


def edits(before, after):
    """Align lines, then trim changed spans; never quadratic whole-body character LCS."""
    left, right = before.splitlines(keepends=True), after.splitlines(keepends=True)
    offsets = [0]
    for line in left:
        offsets.append(offsets[-1] + len(line))
    changes = []
    for tag, a, b, c, d in line_opcodes(left, right):
        if tag == 'equal':
            continue
        old, new = ''.join(left[a:b]), ''.join(right[c:d])
        first, last = 0, 0
        while first < min(len(old), len(new)) and old[first] == new[first]:
            first += 1
        while last < min(len(old), len(new)) - first and old[-last-1] == new[-last-1]:
            last += 1
        changes.append((offsets[a] + first, offsets[b] - last, new[first:len(new)-last]))
    return changes


def compose(body, target, baseline, responses):
    """Set cover over exact repaired bits, constrained by source-span conflicts.

    Responses that change any correct bit are excluded. A combined compile is
    essential: register allocation can couple otherwise disjoint source edits.
    """
    remaining = {(i, bit) for i, (a, b) in enumerate(zip(target, baseline))
                 for bit in range(32) if (a ^ b) & (1 << bit)}
    eligible = []
    for label, source, words in responses:
        if words is None or len(words) != len(target):
            continue
        if any((old ^ new) & (wanted ^ new) for wanted, old, new in zip(target, baseline, words)):
            continue
        fixed = {(i, bit) for i, (old, new) in enumerate(zip(baseline, words))
                 for bit in range(32) if (old ^ new) & (1 << bit)}
        if fixed:
            eligible.append((fixed, label, edits(body, source)))
    chosen, patches = [], []
    while eligible:
        eligible.sort(key=lambda r: -len(r[0] & remaining))
        fixed, label, changes = eligible.pop(0)
        if not fixed & remaining:
            break
        if any(max(a, c) <= min(b, d) for a, b, _ in changes for c, d, _ in patches):
            continue
        chosen.append(label)
        patches.extend(changes)
        remaining -= fixed
    if len(chosen) < 2:
        return None
    for a, b, text in sorted(patches, reverse=True):
        body = body[:a] + text + body[b:]
    return ' + '.join(chosen), body


def region_compositions(body, baseline, responses):
    """Combine disjoint C edits with measured improvements in different blocks.

    Register renumbering and changed instruction counts are allowed. The full
    compiler oracle decides whether the source edits actually compose.
    """
    choices=[]
    for label,text,regions in responses:
        if set(regions)!=set(baseline):
            continue
        fixed={key for key,score in regions.items() if tuple(score[:2])<tuple(baseline[key][:2])
               or (not score[2] and baseline[key][2])}
        worsened={key for key,score in regions.items() if tuple(score[:2])>tuple(baseline[key][:2])}
        if fixed and not worsened:
            choices.append((fixed,label,edits(body,text)))
    result=[]
    for rotate in range(min(4,len(choices))):
        remaining=choices[rotate:]+choices[:rotate];covered=set();patches=[];labels=[]
        while remaining:
            remaining.sort(key=lambda r:-len(r[0]-covered))
            fixed,label,changes=remaining.pop(0)
            if not fixed-covered:
                break
            if any(max(a,c)<=min(b,d) for a,b,_ in changes for c,d,_ in patches):
                continue
            covered.update(fixed);patches.extend(changes);labels.append(label)
        if len(labels)<2:
            continue
        text=body
        for a,b,replacement in sorted(patches,reverse=True):text=text[:a]+replacement+text[b:]
        result.append(('region composition: '+' + '.join(labels),text))
    return list(dict.fromkeys(result))


def closes_region(target, baseline, words, regions):
    # Cheap shortlist for register-only block repairs. The aligned object diff
    # still has to confirm the block, its relocations and all other effects.
    if len(target)!=len(baseline) or len(target)!=len(words):
        return False
    starts=sorted(int(key)//4 for key in regions)
    return any(target[a:b]==words[a:b] and target[a:b]!=baseline[a:b]
               for a,b in zip(starts,starts[1:]+[len(target)]))


def instruction_shapes(words):
    """Opcode identities for the cheap prefilter; these are never match proof."""
    result=[]
    for word in words:
        primary=word>>26;extra=0
        if primary in (19,31):extra=(word>>1)&1023
        elif primary in (59,63):
            extra=(word>>1)&31
            if extra not in (18,20,21,22,23,25,28,29,30,31):extra=(word>>1)&1023
        result.append((primary<<10)|extra)
    return result


def linear_compositions(body, target, baseline, responses):
    """Solve the measured bit responses over GF(2), including cancelling effects.

    This is a shortlist, never an assertion that the allocator is linear. Rotating
    pivot order exposes bounded alternative solutions without subset enumeration.
    """
    def vector(words):
        return int.from_bytes(b''.join((a ^ b).to_bytes(4, 'big') for a, b in zip(baseline, words)), 'big')
    wanted = vector(target)
    choices = [(label, source, vector(words)) for label, source, words in responses
               if words and len(words) == len(target)]
    choices = [c for c in choices if c[2]]
    proposals, seen = [], set()
    for offset in range(min(len(choices), 8)):
        ordered = choices[offset:] + choices[:offset]
        basis = {}
        for i, (_, _, value) in enumerate(ordered):
            mask = 1 << i
            while value:
                pivot = value.bit_length()
                if pivot not in basis:
                    basis[pivot] = value, mask
                    break
                other, selected = basis[pivot]
                value ^= other
                mask ^= selected
        value, mask = wanted, 0
        while value and value.bit_length() in basis:
            other, selected = basis[value.bit_length()]
            value ^= other
            mask ^= selected
        if value or mask.bit_count() < 2:
            continue
        patches, labels = [], []
        for i, (label, source, _) in enumerate(ordered):
            if not mask & (1 << i):
                continue
            changes = edits(body, source)
            if any(max(a, c) <= min(b, d) for a, b, _ in changes for c, d, _ in patches):
                break
            patches.extend(changes)
            labels.append(label)
        else:
            text = body
            for a, b, replacement in sorted(patches, reverse=True):
                text = text[:a] + replacement + text[b:]
            if text not in seen:
                seen.add(text)
                proposals.append(('response equations: ' + ' + '.join(labels), text))
    return proposals




ALIASES = {'li': 'addi', 'lis': 'addis', 'subi': 'addi', 'subis': 'addis',
           'slwi': 'rlwinm', 'srwi': 'rlwinm', 'clrlwi': 'rlwinm', 'clrrwi': 'rlwinm',
           'rotlwi': 'rlwinm', 'clrlslwi': 'rlwinm', 'mtlr': 'mtspr', 'mflr': 'mfspr',
           'mtctr': 'mtspr', 'mfctr': 'mfspr', 'cmpwi': 'cmpi', 'cmplwi': 'cmpli',
           'cmpw': 'cmp', 'cmplw': 'cmpl'}


def mnemonic(name):
    return ALIASES.get(name, name)


def decode(words):
    md = Cs(CS_ARCH_PPC, CS_MODE_32 | CS_MODE_BIG_ENDIAN)
    md.skipdata = True
    return [(mnemonic(i.mnemonic), tuple(mwconstraints.REG.findall(i.op_str)), i.op_str)
            for i in md.disasm(b''.join(w.to_bytes(4, 'big') for w in words), 0)]


def final_allocations(captures):
    # Spilling restarts allocation with new virtual registers. Only the last
    # pass of each bank describes the webs that reach the emitted function.
    final = {c['before']['register_class']: i for i, c in enumerate(captures)}
    return [c for i, c in enumerate(captures) if final[c['before']['register_class']] == i]


def web_constraints(captures, target, ours, check=None):
    captures = final_allocations(captures)
    original, retail = decode(ours), decode(target)
    if len(original) != len(ours) or len(retail) != len(target):
        return {'status': 'instruction-shape'}
    shape = lambda row: (row[0], mwconstraints.REG.sub('R', row[2]))
    retail_alignment = difflib.SequenceMatcher(a=[shape(r) for r in original],
                                              b=[shape(r) for r in retail], autojunk=False)
    retail_rows = {block.a + i: block.b + i for block in retail_alignment.get_matching_blocks()
                   for i in range(block.size)}
    if check is not None:
        # Objdiff aligns control-flow changes before the allocator projection.
        # Re-aligning flat opcode strings can join repeated switch arms instead.
        ti=oi=0;aligned={}
        for left,right in zip(*check._rows):
            has_left=bool(left.get('instruction',{}).get('formatted'))
            has_right=bool(right.get('instruction',{}).get('formatted'))
            relocations=[side.get('instruction',{}).get('relocation',{}).get('type_name') for side in (left,right)]
            if (has_left and has_right and oi<len(original) and ti<len(retail) and shape(original[oi])==shape(retail[ti])
                    and all(r in (None,'R_PPC_NONE') for r in relocations)):
                aligned[oi]=ti
            ti+=has_left;oi+=has_right
        if ti==len(retail) and oi==len(original):
            retail_rows=aligned
    nodes = {c['before']['register_class']: {n['virtual_register']: n for n in c['after']['nodes']}
             for c in captures}
    def root(cls, register):
        seen = set()
        while register >= 32 and nodes[cls][register]['flags'] & 4:
            if register in seen:
                raise ValueError('coalescing cycle')
            seen.add(register)
            register = nodes[cls][register]['physical_register']
        return register
    def physical(cls, register):
        register = root(cls, register)
        return register if register < 32 else nodes[cls][register]['physical_register']
    domains, alternatives, anchors = defaultdict(set), [], []
    extra_copies = set()
    # Each bank's PCode is captured before that bank is allocated. The last
    # pass already contains physical operands for earlier banks, so using it
    # for every bank loses their source webs entirely.
    for capture in captures:
        active = capture['before']['register_class']
        pcode = capture['pcode']
        keys, origins = [], []
        displacement_ops={'addi','addis','lbz','lhz','lha','lwz','lfs','lfd','stb','sth','stw','stfs','stfd'}
        def emitted_key(row):
            literals=tuple(int(m[0],0) for m in re.finditer(r'(?<![\w.])-?(?:0x[\da-f]+|\d+)\b',row[2])) if row[0] in displacement_ops else ()
            return row[0],row[1],literals
        for instruction in pcode:
            operands, regs = [], []
            for a in instruction['operands']:
                cls, r = a['class'], a['reg']
                if cls not in nodes or a['flags'] == 0:
                    continue
                prefix = 'r' if cls == 'gpr' else 'f'
                operands.append((cls, root(cls, r)))
                regs.append(prefix + str(physical(cls, r)))
            name = mnemonic(instruction['mnemonic'])
            if name in ('mr', 'fmr') and len(regs) == 2 and regs[0] == regs[1]:
                continue
            literals=[]
            if name in displacement_ops:
                for operand in instruction['operands']:
                    raw=bytes.fromhex(operand['raw'])
                    if operand['class'] is None and int.from_bytes(raw[:2],'little')==2:
                        literals.append(int.from_bytes(raw[2:6],'little',signed=True))
            keys.append((name, tuple(regs),tuple(literals)))
            origins.append(operands)
        matching = difflib.SequenceMatcher(a=[r[:2] for r in keys], b=[r[:2] for r in original], autojunk=False)
        for block in matching.get_matching_blocks():
            for offset in range(block.size):
                row, index = block.b + offset, block.a + offset
                if row not in retail_rows:
                    if keys[index][0] in ('mr','fmr') and len(origins[index])==2:
                        extra_copies.update(web for web in origins[index] if web[0] == active and web[1]>=32)
                    continue
                if keys[index][2] and keys[index][2]!=emitted_key(original[row])[2]:
                    continue
                name, registers, operand_text = retail[retail_rows[row]]
                if name != original[row][0] or len(registers) != len(origins[index]):
                    continue
                if mwconstraints.REG.sub('R', operand_text) != mwconstraints.REG.sub('R', original[row][2]):
                    continue
                pairs = [(web, color) for web, color in zip(origins[index], (int(r[1:]) for r in registers))
                         if web[0] == active]
                anchors.append(row)
                if name in mwconstraints.COMMUTE and len(pairs) == 3:
                    domains[pairs[0][0]].add(pairs[0][1])
                    alternatives.append((row, pairs[1:]))
                else:
                    for web, color in pairs:
                        domains[web].add(color)
    conflicts = {str(k): sorted(v) for k, v in domains.items() if len(v) > 1}
    desired = {web: next(iter(colors)) for web, colors in domains.items() if len(colors) == 1}
    swapped, unresolved = [], []
    for row, pairs in alternatives:
        (a, x), (b, y) = pairs
        valid = [(swap, u, v) for swap, u, v in [(False, x, y), (True, y, x)]
                 if desired.get(a, u) == u and desired.get(b, v) == v and (a != b or u == v)]
        if not valid:
            unresolved.append(row)
            continue
        if len(valid) > 1 and x != y:
            unresolved.append(row)
            continue
        swap, x, y = valid[0]
        desired[a], desired[b] = x, y
        if swap:
            swapped.append(row)
    return {'status': 'web-hypothesis', 'anchors': sorted(set(anchors)),
            'conflicts': conflicts,
            'extra_copy_webs': {cls:[r for bank,r in extra_copies if bank==cls] for cls in nodes},
            'conflicting_webs': {cls:[r for (bank,r),colors in domains.items() if bank==cls and r>=32 and len(colors)>1] for cls in nodes},
            'desired': {cls: {r: c for (bank, r), c in desired.items() if cls == bank and r >= 32}
                        for cls in nodes}, 'operand_order_rows': swapped, 'unresolved_rows': unresolved}


def scalar_locals(body, span):
    # Carriers from a previous repair are fixed aggregate declarations; keep
    # scanning so remaining scalars can be repaired in the next captured graph.
    return [local for local in _locals(body,span) if '{' not in local[2]]


def annotate_verified_branches(body, findings):
    """Document branch preservation only after a full stock-object match."""
    lines = body.splitlines(keepends=True)
    changed = False
    for rule, line, _ in findings:
        if rule == 'S2' and re.search(r'\(\s*volatile\s+\w+\s*\*\s*\)', lines[line - 1].split('//', 1)[0]):
            # a volatile pointer-cast view that a candidate introduced (load-order families):
            # justified by the full match itself, like a verified branch
            text = lines[line - 1]
            end = len(text.rstrip('\r\n'))
            lines[line - 1] = (text[:end] + '  /* fzgx-allow: S2 volatile view keeps the verified load order */'
                               + text[end:])
            changed = True
            continue
        if rule == 'S2' and re.search(r'\bvolatile\b', lines[line - 1].split('//', 1)[0]):
            # a volatile declaration (local carrier, file-scope object) a sweep family introduced:
            # the full match is its justification too (fn_1_6BFB8's sweep match was refused by S2)
            text = lines[line - 1]
            end = len(text.rstrip('\r\n'))
            lines[line - 1] = (text[:end] + '  /* fzgx-allow: S2 volatile keeps the verified access order */'
                               + text[end:])
            changed = True
            continue
        if rule != 'S1':
            continue
        match = re.search(r'\bgoto\s+(\w+)\s*;', lines[line - 1])
        if match:
            pos = match.end()
            lines[line - 1] = (lines[line - 1][:pos] + f' /* Keep the verified branch to {match[1]}. */'
                               + lines[line - 1][pos:])
            changed = True
    return [('document verified control flow', ''.join(lines))] if changed else []


def reciprocal_products(body, name):
    """Power-of-two division lowers to multiply with a different operand web."""
    operations = []
    commutations(body, name, operations)
    changes = []
    for operation in operations:
        if operation['op'] != '*':
            continue
        for constant, value in ((operation['left'], operation['right']),
                                (operation['right'], operation['left'])):
            literal = body[slice(*constant)].strip()
            if not re.fullmatch(r'(?:\d+\.\d*|\.\d+|\d+[eE][+-]?\d+)(?:[eE][+-]?\d+)?[fF]?', literal):
                continue
            number = float(literal.rstrip('fF'))
            if not math.isfinite(number) or number <= 0:
                continue
            mantissa, exponent = math.frexp(number)
            if mantissa != 0.5 or not -125 <= exponent <= 127:
                continue
            inverse = format(1.0 / number, '.17g')
            if '.' not in inverse and 'e' not in inverse:
                inverse += '.0'
            inverse += 'f' if literal.endswith(('f', 'F')) else ''
            replacement = f'(({body[slice(*value)]}) / {inverse})'
            changes.append((operation['start'], operation['end'], replacement))
            break
    changes = sorted(set(changes))
    out = [(f'reciprocal division at {a}', body[:a] + replacement + body[b:])
           for a, b, replacement in changes]
    # The AST can contain nested products; do not compose overlapping edits.
    if len(changes) > 1 and all(b <= c for (_, b, _), (c, _, _) in zip(changes, changes[1:])):
        combined = body
        for a, b, replacement in reversed(changes):
            combined = combined[:a] + replacement + combined[b:]
        out.append(('reciprocal division at every site', combined))
    return out


def declaration_candidates(body, name, captures, constraints, max_orders=50000):
    """Evaluate declaration orders in the actual graph, with no compile loop."""
    if constraints['status'] != 'web-hypothesis':
        return [], {'status': constraints['status'], 'orders': 0}
    captures = final_allocations(captures)
    span = _function_body_span(body, name)
    if span is None:
        return [], {'status': 'no-body', 'orders': 0}
    locals_ = scalar_locals(body, span)
    by_name = defaultdict(list)
    for capture in captures:
        cls = capture['before']['register_class']
        for n in capture['before']['nodes']:
            if n.get('name'):
                by_name[n['name']].append((cls, n['virtual_register']))
    if all(all(next(n['physical_register'] for n in c['after']['nodes'] if n['virtual_register'] == r) == color
                   for r, color in constraints['desired'][c['before']['register_class']].items()) for c in captures):
        return [], {'status': 'no-allocation-difference', 'orders': 0}
    movable = [(i, by_name[n][0]) for i, (a, b, _, n, dims) in enumerate(locals_)
               if not dims and _init_of(body[a:b]) is None and len(by_name.get(n, [])) == 1]
    if len(movable) < 2:
        return [], {'status': 'no-movable-stratum', 'orders': 0}
    slots = {cls: sorted((r for _, (bank, r) in movable if bank == cls), reverse=True)
             for cls in constraints['desired']}
    if any([r for _, (bank, r) in movable if bank == cls] != order for cls, order in slots.items()):
        return [], {'status': 'unknown-creation-order', 'orders': 0}
    witnesses = []
    positions = {}
    for capture in captures:
        before=capture['before']; cls=before['register_class']
        desired={n['virtual_register']:n['physical_register'] for n in capture['after']['nodes']
                 if n['virtual_register'] in before['simplify_order']}
        desired.update({r:color for r,color in constraints['desired'][cls].items() if r in desired})
        if any(not 0<=color<32 for color in desired.values()):
            continue
        witness=mwgraph.selection_order(before,desired)
        if witness:
            positions[cls]={r:i for i,r in enumerate(witness)}
    if positions:
        ordered=list(movable)
        for cls,rank in positions.items():
            indices=[i for i,(_, (bank,r)) in enumerate(movable) if bank==cls]
            values=sorted((movable[i] for i in indices),key=lambda x:rank.get(x[1][1],10**9))
            for i,value in zip(indices,values):
                ordered[i]=value
        witnesses.append(ordered)
    candidates, checked, best = [], 0, None
    # Source ranks still have to reproduce simplify and coloring, not merely
    # the abstract selection witness. Keep a bounded small-stratum fallback.
    orders=itertools.chain(witnesses,itertools.islice(itertools.permutations(movable),min(max_orders,720)))
    for order in orders:
        ranks = {cls: dict(zip((r for _, (bank, r) in order if bank == cls), slots[cls])) for cls in slots}
        score = 0
        for capture in captures:
            before = capture['before']; cls = before['register_class']
            select = mwgraph.simplify(before, ranks[cls])
            if select is None:
                score += 100000
                continue
            colors = mwgraph.replay(before, select)
            score += sum(colors[r] != c for r, c in constraints['desired'][cls].items())
        checked += 1
        best = score if best is None else min(best, score)
        if score:
            continue
        replacements = {i: locals_[j] for (i, _), (j, _) in zip(movable, order)}
        text, cursor = [], 0
        for i, (a, b, *_) in enumerate(locals_):
            text.append(body[cursor:a])
            x, y, *_ = replacements.get(i, locals_[i])
            text.append(body[x:y]); cursor = b
        candidate = ''.join(text) + body[cursor:]
        if candidate != body:
            candidates.append(candidate)
        # Equivalent orders of unused locals do not justify more compiler calls.
        if candidates:
            break
    return candidates, {'status': 'predicted' if candidates else 'no-predicted-declaration-repair',
                        'orders': checked, 'exhaustive': checked >= len(witnesses) + math.factorial(len(movable)),
                        'best_conflicts': best}


def carrier_candidates(body, name, captures, constraints, _span=None):
    """Move implicated scalar homes into MWCC's aggregate-scalarization stratum.

    A one-field aggregate preserves the scalar's declared type. Only identifier
    uses in the function body are changed; field names, strings and comments
    retain their spelling. Every result still requires a stock compile.
    """
    span = _span or _function_body_span(body, name)
    if span is None or constraints['status'] != 'web-hypothesis':
        return []
    captures = final_allocations(captures)
    locals_ = scalar_locals(body, span)
    implicated = set()
    for capture in captures:
        cls = capture['before']['register_class']
        desired = {int(r): c for r, c in constraints['desired'][cls].items()}
        nodes = {n['virtual_register']: n for n in capture['after']['nodes']}
        for n in nodes.values():
            r, seen = n['virtual_register'], set()
            while r >= 32 and nodes[r]['flags'] & 4 and r not in seen:
                seen.add(r); r = nodes[r]['physical_register']
            if r >= 32 and r in desired and nodes[r]['physical_register'] != desired[r] and n.get('name'):
                implicated.add(n['name'])
    # Saved compiler temporaries can carry a source scalar whose original home
    # was coalesced into an ABI register. PCode line provenance recovers those
    # assignments instead of mistaking the temporary's @name for a C local.
    assignments = []
    local_names = {l[3] for l in locals_}
    for a,b,typ,var,dims in locals_:
        if _init_of(body[a:b]) is not None:
            assignments.append((body.count('\n',0,a)+1,body.count('\n',0,b)+1,var))
    for match in re.finditer(r'^\s*(\w+)\s*=(?!=)[^;{}]+;', body[span[1]:span[2]], re.M):
        if match[1] not in local_names:
            continue
        start = span[1] + match.start(); end = span[1] + match.end()
        assignments.append((body.count('\n', 0, start) + 1, body.count('\n', 0, end) + 2, match[1]))
    for capture in captures:
        cls = capture['before']['register_class']
        desired = {int(r): c for r, c in constraints['desired'][cls].items()}
        nodes = {n['virtual_register']: n for n in capture['after']['nodes']}
        wrong = {r for r, color in desired.items() if nodes[r]['physical_register'] != color}
        # A single web demanded in several retail registers needs a lifetime
        # split even when every unambiguous allocation already agrees.
        wrong.update(constraints.get('conflicting_webs', {}).get(cls, []))
        wrong.update(constraints.get('extra_copy_webs', {}).get(cls, []))
        implicated.update(n['name'] for r,n in nodes.items() if r in wrong and n.get('name'))
        for instruction in capture['pcode']:
            line = instruction['line']
            if line is None or line < 1:
                continue
            if any(a['class'] == cls and a['reg'] in wrong and a['flags'] & 2 for a in instruction['operands']):
                implicated.update(var for first, last, var in assignments if first <= line <= last)
    selected = [l for l in locals_ if l[3] in implicated and not l[4]]
    proposals = []
    groups = [(local,) for local in selected]
    groups.extend(itertools.combinations(selected, 2))
    if len(selected) > 2:
        groups.append(tuple(selected))
    # Coalescing a loop's pointer copies changes its allocation stratum.
    # Include adjacent live scalar homes in the same source-realizable move.
    related=set(implicated)
    for capture in captures:
        nodes={n['virtual_register']:n for n in capture['after']['nodes']}
        chosen=[n for n in nodes.values() if n.get('name') in implicated and 14<=n['physical_register']<32]
        if not chosen:continue
        low=min(n['physical_register'] for n in chosen)-1
        high=max(n['physical_register'] for n in chosen)+1
        registers={n['virtual_register'] for n in chosen}
        related.update(n['name'] for n in nodes.values() if n.get('name') and
                       low<=n['physical_register']<=high and registers.intersection(n['neighbors']))
    neighbors=tuple(l for l in locals_ if l[3] in related and not l[4])
    if len(selected)<len(neighbors)<=len(selected)+3:groups.append(neighbors)
    for group in groups:
        if any('volatile' in l[2] or 'register' in l[2] for l in group):
            continue
        names = {l[3] for l in group}
        def uses(text):
            changes, previous = [], None
            for match in TOKEN.finditer(text):
                token = match[0]
                if token.startswith(('/*', '//')):
                    continue
                if token in names and previous not in ('.', '->', 'struct', 'union', 'enum'):
                    changes.append((match.start(), match.end(), token + '.value'))
                previous = token
            for a, b, value in reversed(changes):
                text = text[:a] + value + text[b:]
            return text
        changes = []
        for a, b, type_, var, _ in group:
            init = _init_of(body[a:b])
            initializer = ' = { ' + uses(init) + ' }' if init is not None else ''
            changes.append((a, b, f'    struct {{ {type_} value; }} {var}{initializer};\n'))
        # Rewrite uses between converted declarations too, including scalar
        # initializers depending on an earlier converted local.
        pieces, cursor = [], group[0][0]
        for a, b, declaration in sorted(changes):
            pieces.extend((uses(body[cursor:a]), declaration))
            cursor = b
        pieces.append(uses(body[cursor:span[2]]))
        source = body[:group[0][0]] + ''.join(pieces) + body[span[2]:]
        label = 'carrier:' + ','.join(l[3] for l in group)
        proposals.append((label, source))
        # Aggregate initializers can keep an otherwise scalarized pointer on
        # the stack. Split pure address initializers before the carrier move.
        initialized=[l for l in group if _init_of(body[l[0]:l[1]]) is not None]
        if _span is None and initialized and all(l in group or _init_of(body[l[0]:l[1]]) is None for l in locals_):
            split=source;assignments=[]
            for a,b,type_,var,_ in initialized:
                init=_init_of(body[a:b])
                if not re.fullmatch(r'&?\s*\w+',init):break
                declaration=next(d for x,y,d in changes if x==a)
                split=split.replace(declaration,declaration[:declaration.index(' = {')]+ ';\n',1)
                assignments.append('    '+var+'.value = '+uses(init)+';\n')
            else:
                split_span=_function_body_span(split,name);split_locals=_locals(split,split_span)
                if split_locals:
                    pos=split_locals[-1][1]
                    split=split[:pos]+''.join(assignments)+split[pos:]
                    proposals.append((label+':split-initializer',split))
        # A block-local value can survive scalarization as a separate web where
        # assigning the aggregate member directly collapses back to a scalar.
        split = source
        changed = False
        for _, _, type_, var, _ in group:
            temp = '__reg_value_' + var
            while re.search(r'\b' + temp + r'\b', split):
                temp += '_'
            pattern = re.compile(r'^(\s*)' + re.escape(var) + r'\.value\s*=\s*([^;{}]+);', re.M)
            def replace_assignment(match):
                nonlocal changed
                changed = True
                return (match[1] + '{ ' + type_ + ' ' + temp + ' = ' + match[2] + '; ' +
                        var + '.value = ' + temp + '; }')
            end = span[2] + len(split) - len(body)
            split = split[:span[1]] + pattern.sub(replace_assignment, split[span[1]:end]) + split[end:]
        if changed:
            proposals.append((label + ':block-copy', split))
    return proposals


def scoped_carrier_candidates(body, name, captures, constraints):
    """Project captured homes for locals declared inside branches and loops too."""
    from .sdkimport import masked
    code = masked(body)
    function = _function_body_span(code, name)
    if function is None or constraints['status'] != 'web-hypothesis':
        return []
    stack, scopes = [], []
    for match in re.finditer(r'[{}]', code[function[1]:function[2]]):
        at = function[1] + match.start()
        if match[0] == '{':
            stack.append(at)
        elif stack:
            start = stack.pop()
            prefix = code[max(function[1], code.rfind('\n', function[1], start)):start]
            if re.search(r'\b(?:struct|union|enum)\s*\w*\s*$|=\s*$', prefix):
                continue
            scopes.append((function[0], start + 1, at))
    out = []
    for span in sorted(scopes):
        locals_ = scalar_locals(body, span)
        if not locals_ or any(ty not in SCALAR_TYPES and not ty.endswith('*') for _, _, ty, _, _ in locals_):
            continue
        # A carrier's name substitution must not reach a shadowing declaration.
        names = {var for _, _, _, var, _ in locals_}
        shadowed = False
        for line in code[locals_[-1][1]:span[2]].splitlines():
            declaration = DECL_RE.fullmatch(line)
            if declaration and declaration[2] in names:
                shadowed = True
                break
        if shadowed:
            continue
        line = body.count('\n', 0, span[1]) + 1
        out.extend((f'scope {line} {label}', text)
                   for label, text in carrier_candidates(body, name, captures, constraints, _span=span))
    return out


def expression_trees(body, name):
    operations = []
    commutations(body, name, operations)
    out = []
    for outer in operations:
        op = outer['op']
        if op not in ('+', '*', '&', '|', '^'):
            continue
        for side in ('left', 'right'):
            lo, hi = outer[side]
            children = [r for r in operations if r['op'] == op and lo <= r['start'] and r['end'] <= hi
                        and (r['start'], r['end']) != (outer['start'], outer['end'])
                        and not body[lo:r['start']].strip(' (\t\n') and not body[r['end']:hi].strip(' )\t\n')]
            if not children:
                continue
            child = max(children, key=lambda r:r['end']-r['start'])
            other = outer['right' if side == 'left' else 'left']
            terms = [body[a:b] for a,b in (child['left'], child['right'], other)]
            # Constants and load order affect CSE and FMA selection. Enumerate the
            # two three-leaf trees together instead of commuting just one node.
            for a,b,c in dict.fromkeys(itertools.permutations(terms)):
                for text in (f'((({a}) {op} ({b})) {op} ({c}))', f'(({a}) {op} (({b}) {op} ({c})))'):
                    out.append((f'expression-tree {op} at {outer["start"]}',
                                body[:outer['start']]+text+body[outer['end']:]))
    return list(dict.fromkeys(out))


def address_expressions(body, name):
    """Keep member-base formation separate from a dynamic array index.

    Macro bodies participate too: their argument names need not be declared C
    members until expansion. All forms retain the original element type.
    """
    from .sdkimport import masked
    code = masked(body)
    span = _function_body_span(code, name)
    if not span:
        return []
    identities = [m[2] for m in re.finditer(r'\bstatic\s+inline\s+('+TYPE+r')\s*(?:(?<=\*)|\s)(\w+)\(\s*('+TYPE+r')\s*(?:(?<=\*)|\s)(\w+)\s*\)\s*\{\s*return\s+\4\s*;\s*\}',code)
                  if '*' in m[1] and m[1].strip()==m[3].strip()]
    wrapper = r'(?:\b(?:'+'|'.join(map(re.escape,identities))+r')\(\s*)?' if identities else ''
    pattern = re.compile(wrapper+r'\b(\w+(?:(?:->|\.)\w+)*)\s*'+(r'\)?' if identities else '')+r'\[([^\[\]\n;]+)\]')
    sites = [m for m in pattern.finditer(code)
             if (span[1] <= m.start() < span[2] or body[body.rfind('\n', 0, m.start())+1:m.start()].rstrip().endswith('=')
                 or '\\' in body[m.end():body.find('\n', m.end())])
             and (')' not in code[m.end(1):m.start(2)] or
                  any(re.match(re.escape(helper)+r'\s*\(',m[0]) for helper in identities))
             and not re.fullmatch(r'\s*(?!return\b)'+TYPE+r'\s+',code[code.rfind('\n',0,m.start())+1:m.start()])
             and not re.match(r'\s*(?:=(?!=)|[+*/&|^-]=|\+\+|--)',code[m.end():])
             and not re.search(r'&\s*$',code[max(span[1],m.start()-3):m.start()])]
    out = []
    # Inlining preserves the array parameter's address web before lowering.
    # Resolve macro parameters from their actual member arguments, so a pointer
    # table never acquires an invented scalar element type.
    members = {}
    for declaration in re.finditer(r'('+TYPE+r')\s*(?:(?<=\*)|\s)(\w+)\s*\[[^\]]+\]\s*;', code[:span[0]]):
        members.setdefault(declaration[2], set()).add(declaration[1].strip())
    fields, variables = declared_types(code,span[0])
    # Indexed stores create their base and index webs in a different order
    # from a dereferenced sum. Byte elements make the displacement unambiguous.
    byte_type = r'(?:u8|s8|char|unsigned char|signed char)'
    store = (r'\*\s*\(\s*('+byte_type+r')\s*\*\s*\)\s*\(\s*'
             r'\(\s*\1\s*\*\s*\)\s*(\w+(?:(?:->|\.)\w+)*)\s*\+\s*')
    for match in re.finditer(store,code[span[1]:span[2]]):
        lo, offset_start = span[1]+match.start(), span[1]+match.end()
        end, depth = offset_start, 1
        while end < span[2] and depth:
            depth += (code[end]=='(')-(code[end]==')'); end += 1
        if depth or not re.match(r'\s*=(?!=)', code[end:]):
            continue
        offset = body[offset_start:end-1].strip()
        if re.search(r'[;{}]|\+\+|--', offset) or call_sites(offset):
            continue
        replacement = '(('+match[1]+' *)'+match[2]+')['+offset+']'
        out.append((f'address indexed byte store at {lo}',body[:lo]+replacement+body[end:]))
    offset_home=(r'('+TYPE+r')\s*(?:(?<=\*)|\s)(\w+)\s*(?:=\s*|;\s*\2\s*=\s*)\(\s*\1\s*\)\s*(\w+)\s*;\s*'
                 r'\2\s*=\s*(\w+)\s*\+\s*\(\s*s32\s*\)\s*\2\s*;\s*return\s+\2\s*;')
    for match in re.finditer(offset_home,code[:span[0]]):
        typ,var,offset,base=match.groups()
        if '*' not in typ:continue
        replacement=('struct { '+typ+' value; } '+var+';\n    '+var+'.value = ('+typ+')'+offset+';\n    '
                     +var+'.value = '+base+' + (s32)'+var+'.value;\n    return '+var+'.value;')
        out.append((f'address aggregate offset home at {match.start()}',body[:match.start()]+replacement+body[match.end():]))
    # A dynamic displacement is a distinct live value in the original code.
    # Keeping that boundary across inlining prevents a trailing constant from
    # being distributed into every later field access.
    for assignment in re.finditer(r'(?m)^[ \t]*(\w+)\s*=\s*([^;{}\n]+);',code[span[1]:span[2]]):
        typ=variables.get(assignment[1],'').strip()
        if '*' not in typ:continue
        lo,hi=span[1]+assignment.start(2),span[1]+assignment.end(2)
        rhs=body[lo:hi];depth=0;split=None
        for i,ch in enumerate(rhs):
            depth+=(ch=='(')-(ch==')')
            if ch=='+' and depth==0:split=i
        if split is None:continue
        base,offset=rhs[:split].strip(),rhs[split+1:].strip()
        if not re.search(r'[*/-]',offset) or re.search(r'\+\+|--|\b\w+\s*\(',offset):continue
        helper=name+'_address_'+str(lo)
        if re.search(r'\b'+helper+r'\b',code):continue
        for reverse in (False,True):
            for home in (False,True):
                parameters=typ+' base, s32 offset' if not reverse else 's32 offset, '+typ+' base'
                arguments=base+', '+offset if not reverse else offset+', '+base
                expression='    return base + offset;\n'
                if home:expression='    '+typ+' result;\n    result = ('+typ+')offset;\n    result = base + (s32)result;\n    return result;\n'
                definition='static inline '+typ+' '+helper+'('+parameters+') {\n'+expression+'}\n'
                text=body[:lo]+helper+'('+arguments+')'+body[hi:]
                insertion=body.rfind('\n',0,span[0])+1
                text=text[:insertion]+definition+text[insertion:]
                out.append((f'address displacement at {lo} '+('offset-first' if reverse else 'base-first')+(' result home' if home else ''),text))
    aliases = dict(re.findall(r'(?m)^#define\s+(\w+)\s+(\w+)\s*$',code))
    typed = {}
    for site in sites:
        member = re.split(r'->|\.',site[1])[-1]
        root = re.match(r'\w+',site[1])[0]
        actual = aliases.get(root,root)+site[1][len(root):]
        resolved = member_type(actual,fields,variables)
        resolved = re.sub(r'\s*\*\s*$', '', resolved) if resolved.rstrip().endswith('*') else ''
        resolved = re.sub(r'\b(?:extern|static|register)\s+','',resolved)
        types = {resolved} if resolved else members.get(member,set())
        if not types:
            definitions = list(re.finditer(r'(?m)^#define\s+(\w+)\(([^)]*)\)',code[:site.start()]))
            if definitions:
                macro = definitions[-1]
                parameters = [x.strip() for x in macro[2].split(',')]
                if member in parameters:
                    index = parameters.index(member)
                    arguments = [call[1].split(',') for call in re.finditer(r'\b'+macro[1]+r'\(([^()\n]*)\)',code[span[1]:span[2]])]
                    actual = [args[index].strip() for args in arguments if index<len(args)]
                    if actual and all(arg in members for arg in actual):
                        types = set().union(*(members[arg] for arg in actual))
        if len(types)==1:
            typed.setdefault(next(iter(types)),[]).append(site)
    for element, accesses in typed.items():
        helper = name+'_array_read'
        while re.search(r'\b'+helper+r'\b',code):
            helper += '_'
        for kind in ('index', 'index-first', 'base'):
            if kind == 'base':
                definition = f'static inline {element} *{helper}({element} *array) {{ return array; }}\n'
            else:
                args = f'{element} *array, s32 index' if kind=='index' else f's32 index, {element} *array'
                definition = f'static inline {element} {helper}({args}) {{ return array[index]; }}\n'
            text = body
            for site in reversed(accesses):
                base,index = body[site.start(1):site.end(1)],body[site.start(2):site.end(2)]
                value = f'{helper}({base})[{index}]' if kind=='base' else (f'{helper}({base}, {index})' if kind=='index' else f'{helper}({index}, {base})')
                text = text[:site.start()]+value+text[site.end():]
            # Earlier macro edits change the declaration's byte offset.
            current = _function_body_span(masked(text),name)
            pos = text.rfind('\n',0,current[0])+1
            text = text[:pos]+definition+text[pos:]
            out.append((f'address typed {kind} at every site ({element})',text))
    for kind in ('index-first', 'dereference', 'index-first-dereference'):
        edits = []
        for m in sites:
            base, index = body[m.start(1):m.end(1)], body[m.start(2):m.end(2)]
            if kind == 'index-first':
                replacement = f'({index})[{base}]'
            elif kind == 'dereference':
                replacement = f'*(({base}) + ({index}))'
            else:
                replacement = f'*(({index}) + ({base}))'
            edits.append((m.start(), m.end(), '('+replacement+')'))
        combined = body
        for a,b,value in reversed(edits):
            combined = combined[:a]+value+combined[b:]
        if edits:
            out.append(('address '+kind+' at every site', combined))
        for a,b,value in edits:
            out.append((f'address {kind} at {a}', body[:a]+value+body[b:]))
    return out


def scalar_square_lifetimes(body, name):
    """Finish a dead scalar's square before unrelated loads take its register."""
    from .sdkimport import masked
    code = masked(body); span = _function_body_span(code, name)
    if not span:
        return []
    _, variables = declared_types(code, span[0]); out = []
    for site in re.finditer(r'\b(\w+)\s*\*\s*\1\b', code[span[1]:span[2]]):
        var = site[1]; a, b = span[1]+site.start(), span[1]+site.end()
        if variables.get(var) not in ('s32', 'u32', 'int', 'unsigned int', 'long', 'unsigned long'):
            continue
        # Declaration, definition and these two reads: overwriting the local
        # cannot affect another use or an escaped address.
        if len(re.findall(r'\b'+re.escape(var)+r'\b', code[span[1]:span[2]])) != 4:
            continue
        assignment = reaching_assignment(code, var, a, span[1])
        if not assignment:
            continue
        end = code.find(';', assignment[1], a)
        if end < 0 or re.search(r'[{}]|\b(?:if|else|for|while|do|goto)\b',code[end+1:a]):
            continue
        text = body[:a]+var+body[b:]
        text = text[:end+1]+'\n    '+var+' = '+var+' * '+var+';'+text[end+1:]
        out.append((f'lifetime scalar square {var}', text))
    return out


def comparison_lifetimes(body, name):
    """Keep the zero operand of a floating comparison in its own scalar home."""
    from .sdkimport import masked
    code = masked(body); span = _function_body_span(code, name)
    if not span:
        return []
    fields, variables = declared_types(code, span[0]); out = []
    local = name+'_zero'
    while re.search(r'\b'+local+r'\b',code):
        local += '_'
    for site in re.finditer(r'\b(\w+(?:(?:->|\.)\w+)*)\s*(==|!=)\s*(0\.0[fF]?)\b',code[span[1]:span[2]]):
        kind = member_type(site[1],fields,variables)
        if kind not in ('f32','float','f64','double'):
            continue
        a,b=span[1]+site.start(),span[1]+site.end()
        value='('+local+' = '+site[3]+', '+site[1]+' '+site[2]+' '+local+')'
        text=body[:a]+value+body[b:]
        text=text[:span[1]]+'\n    '+kind+' '+local+';'+text[span[1]:]
        out.append((f'lifetime floating comparison at {a}',text))
    return out


def operand_lifetimes(body, name, operators):
    """Give pure operands separate parameter/return webs before inlining."""
    operations = []
    commutations(body,name,operations)
    span = _function_body_span(body,name)
    if not span:
        return []
    insertion = body.rfind('\n',0,span[0])+1
    helper = name+'_operand'
    while re.search(r'\b'+helper+r'\b',body):
        helper += '_'
    groups = {}
    for op in operations:
        if op['op'] in operators:
            groups.setdefault((op['op'],body[op['start']:op['end']]),[]).append(op)
    work = list(groups.values())
    # Shared subexpressions can keep the old ordering alive even when their
    # surrounding operands differ. Rewrite disjoint uses of the operator too.
    for operator in operators:
        sites = []
        for op in sorted((o for o in operations if o['op']==operator),key=lambda o:(o['start'],-o['end'])):
            if not sites or op['start'] >= sites[-1]['end']:
                sites.append(op)
        if len({body[s['start']:s['end']] for s in sites})>1:
            work.insert(0,sites)
    out = []
    for sites in work:
        op = sites[0]
        for ty in operators[op['op']]:
            for reverse in (True,False):
                names = ['left','right'] if not reverse else ['right','left']
                for assign in (False,True):
                    expression = ('left '+op['op']+'= right; return left;' if assign else 'return left '+op['op']+' right;')
                    definition = f'static inline {ty} {helper}({ty} {names[0]}, {ty} {names[1]}) {{ {expression} }}\n'
                    for positions in ([sites] if len(sites)==1 else [sites]+[[site] for site in sites]):
                        text = body
                        for site in sorted(positions,key=lambda s:s['start'],reverse=True):
                            left,right = (body[a:b] for a,b in (site['left'],site['right']))
                            values = [left,right] if not reverse else [right,left]
                            replacement = helper+'('+', '.join('('+v+')' for v in values)+')'
                            text = text[:site['start']]+replacement+text[site['end']:]
                        text = text[:insertion]+definition+text[insertion:]
                        where = 'every site' if len(positions)>1 else str(positions[0]['start'])
                        label = f'lifetime operands {op["op"]} at {where} {ty} '+('right-first' if reverse else 'left-first')+(' assigned' if assign else '')
                        out.append((label,text))
    return out


def declared_types(code, end):
    """Resolve fields by their owning record, never by a shared member name."""
    from .signatures import member_declarations, declarator
    fields, instances = {}, {}
    for record in records(code,end):
        members = {}
        for name, typ, dims in (field for part in record['body'].split(';')
                               for field in member_declarations(part) or []):
            if dims:
                typ = (declarator(typ, '(*)'+''.join('['+d+']' for d in dims[1:])) if len(dims)>1
                       else declarator(typ, '*').strip())
            members[name] = typ
        fields[record['key']] = members
        if record['td'] and record['alias']:
            fields[record['alias']] = members
        elif record['alias'] and record['parent'] is None:
            instances[record['alias']] = record['kind']+' '+record['key']
    variables = {}
    type_names = set(fields) | {'void','char','short','int','long','float','double','u8','s8','u16','s16','u32','s32','u64','s64','f32','f64','BOOL'}
    type_names.update(re.findall(r'\btypedef\s+[^;{}]+?\b([A-Za-z_]\w*)\s*(?:\[[^]]*\])?\s*;',code))
    for decl in re.finditer(r'('+TYPE+r')\s*(?:(?<=\*)|\s)([A-Za-z_]\w*)\s*(?=[,;=)\[])', code):
        if re.search(r'\b(?:return|else|case|default|break|continue|goto|if|for|switch|while|do|sizeof)\b',decl[1]):
            continue
        typ = re.sub(r'\b(?:extern|static|register|const|volatile|signed|unsigned)\b|\*','',decl[1]).strip()
        if typ not in type_names and not re.fullmatch(r'(?:struct|union|enum)\s+\w+',typ):
            continue
        variables[decl[2]] = decl[1]+(' *' if code[decl.end():].startswith('[') else '')
    variables.update(instances)
    return fields, variables


def record_layouts(code, end, variables):
    """Byte offsets of explicitly declared PowerPC records and their members."""
    from .signatures import record_layouts as layouts
    parsed, _ = layouts(code, end)
    return {tag:{name:(offset,ty+''.join('['+str(n)+']' for n in dims[1:]),dims[0] if dims else None)
                 for name,ty,offset,width,dims in fields} for tag,fields in parsed.items()}


def member_type(expression, fields, variables):
    parts = re.split(r'->|\.', expression)
    ty = variables.get(parts[0], '')
    for member in parts[1:]:
        tag = record_tag(ty)
        ty = fields.get(tag, {}).get(member, '')
    return ty


def member_layout(expression, layouts, variables):
    """Address base and displacement through inline records and pointer loads."""
    root = re.match(r'\w+', expression)
    if not root:
        return None
    base, typ, offset, count = root[0], variables.get(root[0], ''), 0, None
    for member in re.finditer(r'(->|\.)(\w+)', expression[root.end():]):
        at = root.end() + member.start()
        if member[1] == '->' and at > root.end():
            base, offset = expression[:at], 0
        field = layouts.get(record_tag(typ), {}).get(member[2])
        if not field:
            return None
        delta, typ, count = field
        offset += delta
    return base, offset, typ, count


def accessor_lifetimes(body, name):
    """Repair saved accessors that let a copied aggregate's array escape."""
    from .sdkimport import masked
    from .signatures import member_declarations
    code=masked(body); span=_function_body_span(code,name)
    if not span:
        return []
    arrays={r['key']:{n for n,t,d in member_declarations(r['body']) or [] if d}
            for r in records(code,span[0])}
    pattern=(r'\bstatic\s+inline\s+('+TYPE+r')\s+(\w+)\s*\(\s*'
             r'((?:struct|union)\s+\w+|\w+)\s+(\w+)\s*\)\s*'
             r'\{\s*return\s+\4\.(\w+)\s*;\s*\}')
    changes=[]
    for helper in re.finditer(pattern,code[:span[0]]):
        ret,fn,typ,owner,field=helper.groups()
        if '*' not in ret or field not in arrays.get(record_tag(typ),set()):
            continue
        uses=[call for call in call_sites(body) if call[0]==fn and call[1]>=span[1]]
        if not uses or any(len(c[3])!=1 or not re.fullmatch(r'\w+',code[s:e].strip()) for c in uses for s,e in c[3]):
            continue
        changes.append((helper.start(),helper.end(),''))
        for _,start,end,args in uses:
            a,b=args[0];changes.append((start,end,'('+body[a:b]+').'+field))
    text=body
    for a,b,value in sorted(changes,reverse=True):text=text[:a]+value+text[b:]
    return [('restore escaping aggregate member',text)] if changes else []



def pointer_lifetimes(body, name):
    """Materialize pointer and floating-point reads at their evaluation point.

    A repeated member chain often conceals two live values from the allocator.
    Bind before a complete statement, never inside one of its unsequenced
    operands. Function-wide carriers let separate reads share a live range.
    """
    from .sdkimport import masked
    from .signatures import member_declarations
    code = masked(body)
    span = _function_body_span(code, name)
    if not span:
        return []
    fields, variables = declared_types(code, span[0])
    aliases = {}
    for declaration in re.finditer(r'\btypedef\s+([^;{}]+);', code[:span[0]]):
        aliases.update({name:typ for name,typ,dims in member_declarations(declaration[1]) or [] if not dims})
    pointers = {name for name,typ in aliases.items() if '*' in typ}
    while more := {name for name,typ in aliases.items() if typ in pointers} - pointers:
        pointers.update(more)
    out = []
    # A switch selected through a freshly loaded pointer already dominates
    # each arm. Keep that value when an earlier repair redundantly reassigns
    # it after stores to different fields of the same owner.
    for control,start,end,args in call_sites(code):
        if control!='switch' or len(args)!=1 or not span[1]<=start<end<span[2]:continue
        selector=re.fullmatch(r'\s*(\w+)->\w+\s*',code[slice(*args[0])])
        if not selector:continue
        var=selector[1];before=code[span[1]:start]
        init=re.search(r'\b'+re.escape(var)+r'\s*=\s*(\w+->\w+)\s*;\s*$',before)
        if not init:continue
        value=init[1];opening=re.match(r'\s*\{',code[end:])
        if not opening:continue
        closing=end+opening.end();depth=1
        while closing<span[2] and depth:
            depth+=(code[closing]=='{')-(code[closing]=='}');closing+=1
        region=code[end:closing]
        for reload in re.finditer(r'(?m)^[ \t]*'+re.escape(var)+r'\s*=\s*\(?'+re.escape(value)+r'\)?\s*;[^\S\n]*',region):
            a,b=end+reload.start(),end+reload.end()
            cases=list(re.finditer(r'\b(?:case\s+[^:]+|default)\s*:',code[end:a]))
            if not cases:continue
            prefix=code[end+cases[-1].end():a]
            if re.search(r'\b\w+\s*\(|\b(?:if|switch|for|while|goto)\b|[}\[\]]',prefix):continue
            writes=re.findall(r'([^;{}\n]+?)\s*=(?!=)',prefix)
            if any((lhs:=w.strip())==var or lhs==value or not re.fullmatch(r'\w+|'+re.escape(value.split('->')[0])+r'->\w+',lhs) for w in writes):continue
            out.append((f'lifetime retain switch pointer {var} at {a}',body[:a]+body[b:]))
    # An assignment at the first short-circuited read preserves its evaluation
    # point; hoisting the read before the condition can change both behavior
    # and the allocator's live ranges.
    for callee,start,end,args in call_sites(code):
        if callee!='if' or not span[1]<=start<end<span[2] or len(args)!=1:continue
        a,b=args[0];condition=code[a:b]
        if any(fn not in ('if','sizeof') for fn,lo,hi,_ in call_sites(condition)):
            continue
        sites={}
        for m in re.finditer(r'\b\w+(?:(?:->|\.)\w+)+',condition):
            if member_type(m[0],fields,variables).strip() not in ('u32','s32','unsigned','int'):continue
            sites.setdefault(m[0],[]).append(m)
        for expression,reads in sites.items():
            if len(reads)<2 or re.search(r'(?<![=!<>])=(?!=)|\+\+|--',condition):continue
            temp='fzgx_condition_'+str(a)
            if re.search(r'\b'+temp+r'\b',code):continue
            text=body
            for i,m in reversed(list(enumerate(reads))):
                replacement='('+temp+' = '+expression+')' if i==0 else temp
                lo,hi=a+m.start(),a+m.end();text=text[:lo]+replacement+text[hi:]
            ty=member_type(expression,fields,variables).strip()
            text=text[:span[1]]+'\n    '+ty+' '+temp+';'+text[span[1]:]
            out.append((f'lifetime condition {expression} at {a}',text))
    declarations = {}
    for line in re.finditer(r'(?m)^[ \t]*[^\n]+;[ \t]*$',code[span[1]:span[2]]):
        decl = DECL_RE.match(line[0])
        if not decl or decl[3] or decl[1].strip() in ('return','goto','break','continue'):
            continue
        declarations.setdefault(decl[2],[]).append((span[1]+line.start(),span[1]+line.end(),decl[1],decl[4]))
    leading = {r[3] for r in _locals(body,span)}
    for var, decls in declarations.items():
        if len(decls)<2 or var in leading or len({d[2] for d in decls})!=1:
            continue
        if re.search(r'\b'+re.escape(var)+r'\b',code[span[0]:span[1]]):
            continue
        text = body
        for a,b,ty,init in reversed(decls):
            replacement = (re.match(r'[ \t]*',body[a:b])[0]+var+' = '+body[a:b][body[a:b].find('=')+1:].strip()) if init else ''
            text = text[:a]+replacement+text[b:]
        text = text[:span[1]]+'\n    '+decls[0][2]+' '+var+';'+text[span[1]:]
        out.append(('lifetime shared local '+var,text))
    sites = {}
    pattern = re.compile(r'\b(\w+)((?:(?:->|\.)\w+)+)')
    for m in pattern.finditer(code, span[1], span[2]):
        if (code[:m.start()].rstrip().endswith(('.', '->'))
                or re.search(r'(?:&|\+\+|--)\s*\(*\s*$',code[:m.start()])):
            continue
        ty = variables.get(m[1], '')
        for member in re.finditer(r'(->|\.)(\w+)', m[2]):
            tag = record_tag(ty)
            ty = fields.get(tag, {}).get(member[2], '')
            end = m.start(2)+member.end()
            destination = end == m.end() and re.match(r'\s*\)*\s*(?:=(?!=)|[+*/&|^-]=|\+\+|--)',code[end:])
            scalar = re.sub(r'\b(?:const|volatile)\b', '', ty).strip()
            if ('*' in ty or scalar in pointers or scalar in ('f32','float','f64','double')) and not destination:
                value_type = ty if '*' in ty else scalar
                sites.setdefault((body[m.start():end], value_type), []).append((m.start(),end))
    for (expression, ty), uses in sites.items():
        var = 'fzgx_live'
        while re.search(r'\b'+var+r'\b', code):
            var += '_'
        grouped = {}
        for a,b in uses:
            line = code.rfind('\n', span[1], a)+1
            grouped.setdefault(line, []).append((a,b))
        # A switch selector and its arms often consume the same pointer web.
        # A declaration in each arm cannot express that shared lifetime.
        for control in re.finditer(r'\bswitch\s*\([^;{}]*\)\s*\{', code[span[1]:span[2]]):
            lo, opening = span[1]+control.start(), span[1]+control.end()-1
            if expression not in body[lo:opening]:
                continue
            depth, end = 1, opening+1
            while depth and end < span[2]:
                depth += (code[end] == '{')-(code[end] == '}')
                end += 1
            if depth:
                continue
            text = body[lo:end]
            text = re.sub(r'\b'+re.escape(expression)+r'\b', var, text)
            replacement = '{\n    '+declarator(ty,var)+' = '+expression+';\n'+text+'\n}'
            out.insert(0, (f'lifetime switch pointer {expression} at {lo}', body[:lo]+replacement+body[end:]))
        edits = []
        for line, positions in grouped.items():
            # Each line must be a complete expression statement, without a
            # short-circuit or control-flow boundary between repeated reads.
            end = code.find('\n', positions[-1][1])
            statement = code[line:end]
            previous = code[span[1]-1:line].rstrip()
            if (any(x in statement for x in ('&&','||','?', 'if ', 'if(', 'while', 'for '))
                    or not statement.rstrip().endswith(';') or not previous.endswith((';','{','}',':'))
                    or statement.count('(')!=statement.count(')') or DECL_RE.fullmatch(statement)):
                continue
            changes = [(a,b,var) for a,b in positions]
            indent = re.match(r'[ \t]*', body[line:])[0]
            changes.insert(0, (line,line,indent+var+' = '+expression+';\n'))
            text = body
            for a,b,value in reversed(changes):
                text = text[:a]+value+text[b:]
            text = text[:span[1]]+'\n    '+declarator(ty,var)+';'+text[span[1]:]
            out.append((f'lifetime pointer {expression} at {line}', text))
            edits.extend(changes)
        if edits:
            text = body
            for a,b,value in sorted(edits, reverse=True):
                text = text[:a]+value+text[b:]
            text = text[:span[1]]+'\n    '+declarator(ty,var)+';'+text[span[1]:]
            out.insert(0, ('lifetime pointer '+expression+' at every site', text))
        # An inlined accessor has its own parameter/return webs before inlining.
        # This can separate a pointer lifetime without forcing a stack spill.
        root = re.match(r'\w+', expression)[0]
        root_type = variables.get(root)
        if root_type:
            helper = name+'_read_pointer'
            while re.search(r'\b'+helper+r'\b', code):
                helper += '_'
            expression_in_helper = 'owner'+expression[len(root):]
            argument = root
            if '*' not in root_type and record_tag(root_type) in fields:
                # Array members must still refer to the caller's object; a
                # by-value owner would return a pointer into a dead temporary.
                root_type += ' *'
                expression_in_helper = 'owner->'+expression[len(root)+1:]
                argument = '&'+root
            definition = 'static inline '+declarator(ty, helper+'('+declarator(root_type, 'owner')+')')+' { return '+expression_in_helper+'; }\n'
            insertion = body.rfind('\n', 0, span[0])+1
            for positions in [uses]+[[use] for use in uses]:
                text = body
                for a,b in reversed(positions):
                    text = text[:a]+helper+'('+argument+')'+text[b:]
                text = text[:insertion]+definition+text[insertion:]
                out.append((f'lifetime accessor {expression} at '+('every site' if positions is uses else str(positions[0][0])), text))
    # A store's address and computed value have independent lifetimes. Expose
    # either side while retaining the recovered field type and conversion.
    assignments = re.compile(r'(?m)^([ \t]*)(\w+(?:(?:->|\.)\w+)+)\s*=\s*([^;\n]+);')
    for assignment in assignments.finditer(code, span[1], span[2]):
        lhs = assignment[2]
        tokens = re.split(r'->|\.', lhs)
        ty = variables.get(tokens[0], '')
        for member in tokens[1:]:
            tag = record_tag(ty)
            ty = fields.get(tag, {}).get(member, '')
        if not ty or 'volatile' in ty or '__fzgx_record_' in ty:
            continue
        var = 'fzgx_value'
        while re.search(r'\b'+var+r'\b', code):
            var += '_'
        rhs = body[assignment.start(3):assignment.end(3)]
        for address in (False, True):
            declaration = declarator(ty, ('*' if address else '')+var)+';'
            first = '&('+lhs+')' if address else rhs
            second = '*'+var+' = '+rhs if address else lhs+' = '+var
            replacement = assignment[1]+var+' = '+first+';\n'+assignment[1]+second+';'
            text = body[:assignment.start()]+replacement+body[assignment.end():]
            text = text[:span[1]]+'\n    '+declaration+text[span[1]:]
            out.append((f'lifetime store {"address" if address else "value"} at {assignment.start()}', text))
    return out


def missing_values(body, name):
    """Bind a used but never-defined scalar to an already-read source lvalue.

    Preserve the existing load's evaluation point through an assignment expression.
    This repairs missing def/use edges without inserting an arbitrary entry load.
    """
    span = _function_body_span(body, name)
    if not span:
        return []
    locals_ = _locals(body, span)
    if not locals_:
        return []
    start = locals_[-1][1]
    tokens = [(m[0], m.start()+start, m.end()+start) for m in TOKEN.finditer(body[start:span[2]])
              if not m[0].startswith(('/*','//'))]
    out=[]
    for a,b,type_,var,dims in locals_:
        if dims or _init_of(body[a:b]):
            continue
        uses=[i for i,t in enumerate(tokens) if t[0]==var and (i==0 or tokens[i-1][0] not in ('.','->'))]
        if not uses:
            continue
        if any((i+1<len(tokens) and tokens[i+1][0] in ('=','+=','-=','*=','/=','++','--','|=','&=','^='))
               or (i and tokens[i-1][0] in ('++','--','&')) for i in uses):
            continue
        first=tokens[uses[0]][1]
        pattern=r'\b(?:lbl_\w+|[A-Za-z_]\w*(?:->|\.)[A-Za-z_]\w*)(?:(?:->|\.)[A-Za-z_]\w*|\[\d+\])*'
        for m in re.finditer(pattern,body[start:first]):
            lo,hi=start+m.start(),start+m.end()
            # Only reads, never assignment destinations or address-taking.
            if re.match(r'\s*(?:=(?!=)|[+*/&|^-]=|\+\+|--)',body[hi:]) or body[max(start,lo-1):lo]=='&':
                continue
            replacement=f'({var} = {m[0]})'
            out.append((f'missing-value {var} from {m[0]} at {lo}',body[:lo]+replacement+body[hi:]))
    return out


def external_helper(body, name):
    """Use an already-owned helper instead of emitting a duplicate local copy."""
    span=_function_body_span(body,name)
    if not span:
        return
    start=body.rfind('\n',0,span[0])+1
    header=body[start:span[1]-1].strip()
    header=re.sub(r'\b(?:static|inline)\s+', '', header)
    yield 'reuse owned helper '+name,body[:start]+'extern '+header+';\n'+body[span[2]+1:]


def split_helper_calls(body, name):
    """Separate inlined uses from calls to an already-owned out-of-line helper."""
    span=_function_body_span(body,name)
    if not span:
        return
    alias=name+'_inline'
    if re.search(r'\b'+re.escape(alias)+r'\b',body):
        return
    uses=list(re.finditer(r'\b'+re.escape(name)+r'(?=\s*\()',body[span[2]+1:]))
    if not 1<=len(uses)<=8:
        return
    start=body.rfind('\n',0,span[0])+1
    signature=body[start:span[1]-1].strip()
    signature=re.sub(r'\b(?:static|inline|extern)\s+','',signature)
    # Keep the original signature for external calls; the private copy is only
    # allowed to survive if the compiler inlines every selected use.
    for mask in range(1,1<<len(uses)):
        text=body
        for i,use in reversed(list(enumerate(uses))):
            if mask & (1<<i):
                a,b=span[2]+1+use.start(),span[2]+1+use.end()
                text=text[:a]+alias+text[b:]
        text=text[:span[0]]+alias+text[span[0]+len(name):]
        text=text[:start]+'extern '+signature+';\n'+text[start:]
        yield f'split inline/external helper {name} uses {mask:x}',text


def inline_helpers(body, name):
    """Do not emit unused out-of-line copies of reconstructed static helpers.

    A REL retains these copies even when the target function inlined every call.
    They shift its text and every dependent relocation despite an exact function diff.
    """
    pattern = re.compile(r'\bstatic\s+(?!inline\b)(?:'+TYPE+r')\s+(\w+)\s*\([^;{}]*\)\s*\{')
    sites = [m.start()+len('static ') for m in pattern.finditer(body) if m[1] != name]
    if len(sites)>1:
        text=body
        for at in reversed(sites):
            text=text[:at]+'inline '+text[at:]
        yield 'inline all static helpers',text
    for at in sites:
        yield 'inline helper at '+str(at), body[:at]+'inline '+body[at:]
    for definition in re.finditer(r'\bstatic\s+inline\s+(?:'+TYPE+r')\s+(\w+)\s*\([^;{}]*\)\s*\{',body):
        helper=definition[1]
        if helper==name:
            continue
        prototypes=list(re.finditer(r'(?m)^(?!static\b)(?:extern\s+)?(?:'+TYPE+r')\s+'+re.escape(helper)+r'\s*\([^;{}]*\);',body[:definition.start()]))
        if prototypes:
            text=body
            for m in reversed(prototypes):
                text=text[:m.start()]+'static inline '+re.sub(r'^extern\s+','',m[0])+text[m.end():]
            yield 'localize inline helper declaration '+helper,text
    # A recovered helper can also be a public definition already owned by
    # another TU. Keep its body available to the inliner without exporting it.
    pattern = re.compile(r'(?m)^(?!static\b|extern\b)(?:'+TYPE+r')\s+(\w+)\s*\([^;{}]*\)\s*\{')
    for match in pattern.finditer(body):
        if match[1] != name:
            yield 'internal inline helper '+match[1], body[:match.start()]+'static inline '+body[match.start():]


_FIFO_MEMBERS = {'u8': 'u8', 'unsigned char': 'u8', 'u16': 'u16', 'unsigned short': 'u16',
                 'u32': 'u32', 'unsigned int': 'u32', 'unsigned long': 'u32', 's8': 's8',
                 'signed char': 's8', 'char': 's8', 's16': 's16', 'short': 's16', 's32': 's32',
                 'int': 's32', 'long': 's32', 'f32': 'f32', 'float': 'f32', 'f64': 'f64', 'double': 'f64'}
_HW_OWNED = {'__OSBusClock': 'dolphin/hw_regs.h', '__OSTVMode': 'dolphin/hw_regs.h', 'GXWGFifo': 'dolphin/gx.h'}
_HW_LITERAL = re.compile(r'\b0[xX]([0-9A-Fa-f]{8})[uUlL]*\b')
_LC_BASE, _LC_SIZE = 0xE0000000, 0x4000  # Gekko locked cache: hw_regs.h `LC_BASE`, 16 KB


def _hw_name(address, table):
    """FZGX_ADDR_ spelling of a hardware/low-memory address: the exact link-script symbol, else
    the nearest register block below it (within 0x400) plus an offset (same folded constant)."""
    exact = sorted(n for n, a in table.items() if a == address)
    if exact:
        return 'FZGX_ADDR_' + exact[0]
    bases = sorted(((address - a, n) for n, a in table.items() if 0 < address - a < 0x400 and a >= 0xCC000000))
    if bases:
        off, name = bases[0]
        return f'(FZGX_ADDR_{name} + 0x{off:X})'
    return None


def _add_include(text, header):
    if re.search(r'#include\s*[<"]' + re.escape(header) + r'[>"]', text):
        return text
    return f'#include "{header}"\n' + text


_FILE_SCOPE_DATA = re.compile(
    r'(?m)^(?P<head>(?:static\s+)?(?:(?:const|volatile|unsigned|signed|struct|union|enum)\s+)*\w+(?:\s*\*+)?\s+)'
    r'(?P<name>\w+)(?P<dims>(?:\s*\[[^\]]*\])*)\s*=\s*(?P<init>\{(?:[^{}]|\{[^{}]*\})*\}|"(?:[^"\\]|\\.)*"(?:\s*"(?:[^"\\]|\\.)*")*|[^;{}]+);[^\n]*\n?')


_PRIMER_REGION = re.compile(
    r'(?ms)^[ \t]*#pragma\s+section\s+code_type\s+"\.fzgxpool"[^\n]*\n.*?'
    r'(?:^[ \t]*#pragma\s+section\s+code_type(?:\s+"\.text")?[^\n]*\n|\Z)')
_PRIMER_DECL = re.compile(r'(?m)^[ \t]*(?:extern\s+)?[\w \t*]+?\b(?P<name>fzgx_\w+)\s*(?:\([^;{]*\))?\s*;[^\n]*\n?')


def link_spellings(body, conflicts, renames):
    """Respell what mwld refuses in an exact object match (`oracle.link_conflicts`), the oracle
    deciding afterwards as always. `renames` (old -> canonical, `oracle.stale_promotion_names`)
    replaces pre-promotion `name_ADDR` tokens with the global name (__pformatter's
    `long2str_80082040`). A `multiply defined` conflict turns the file-scope definition of each
    retail data symbol into an `extern` declaration of the same type; the private, unreferenced,
    non-const definitions written next to them (a hand-laid `.data` cluster:
    colchg_selcar_disp's `selcar_title` etc.) go too, since `-r` module links keep every
    `.data` object and the module would grow. Pool primers (`const`, `.rodata`) are untouched.
    Returns [(description, text)]; empty when nothing applies."""
    out = []
    text = body
    if renames:
        pattern = re.compile(r'(?<![\w.$@])(' + '|'.join(re.escape(n) for n in sorted(renames, key=len, reverse=True)) + r')(?![\w$@])')
        text = pattern.sub(lambda m: renames[m.group(1)], text)
        if text != body:
            out.append(('canonical names after promotion ' + ', '.join(f'{a}->{b}' for a, b in sorted(renames.items())), text))
    if any(c.startswith('primer without pool binding') for c in conflicts):
        # the match needs no pool binding, so nothing drops the `.fzgxpool` primer at
        # integration: remove the primer regions and the declarations only they used
        # (colchg_selmate_disp's `extern void fzgx_pool_double(f64);`)
        stripped = _PRIMER_REGION.sub('', text)
        if stripped != text:
            def unused_decl(m):
                return '' if len(re.findall(r'\b' + re.escape(m['name']) + r'\b', stripped)) == 1 else m[0]
            stripped = _PRIMER_DECL.sub(unused_decl, stripped)
            text = stripped
            out.append(('primer dropped (no pool binding to drop it at integration)', text))
    defined = sorted({m[1] for m in (re.match(r'multiply defined at link: `(\w+)`', c) for c in conflicts) if m})
    if defined:
        before = text
        dropped = []

        def sub(m):
            name = m['name']
            if name in defined:
                dropped.append(name)
                return f"extern {m['head'].replace('static ', '')}{name}{'[]' if m['dims'].strip() else ''};\n"
            return m[0]
        text = _FILE_SCOPE_DATA.sub(sub, text)
        if set(dropped) == set(defined):
            # private non-const file-scope data nothing in the body reads: extra `.data` bytes in a REL
            def drop_private(m):
                name = m['name']
                if 'const' in m['head'] or len(re.findall(r'\b' + re.escape(name) + r'\b', text)) > 1:
                    return m[0]
                dropped.append(name)
                return ''
            text = _FILE_SCOPE_DATA.sub(drop_private, text)
            if text != before:
                out.append(('retail data declared extern ' + ', '.join(defined), text))
    return out


def hardware_literal_names(body, findings):
    """Lint-clean spellings of an exact match's hardware literals (A1/A2), proposed only after a
    full stock-object match so the oracle rechecks them: GX FIFO stores
    `(*(volatile T *)0xCC008000u) = v` become `GXWGFifo.<member> = v` (dolphin/gx.h, or a local
    absolute declaration when the body defines PPCWGPipe itself); absolute declarations of
    hw_regs.h/gx.h objects (`u32 __OSBusClock : 0x800000F8;`) defer to the header; every other
    address becomes its link-script `FZGX_ADDR_*` name (sdk_addresses.h, the same constant).
    fn_4_2394 matched 100% and was dropped for lint until respelled by hand this way."""
    if not any(rule in ('A1', 'A2') for rule, _, _ in findings):
        return []
    table = oracle.abs_symbols()
    fifo = table.get('__GXFifo', 0xCC008000)
    own_pipe = bool(re.search(r'\}\s*PPCWGPipe\s*;', body))
    out = []
    for use_headers in (True, False):
        text, includes = body, set()
        # GX FIFO stores through a literal pointer
        def fifo_sub(m):
            member = _FIFO_MEMBERS.get(' '.join(m['type'].split()))
            if member is None or int(m['addr'], 16) != fifo:
                return m[0]
            return f'GXWGFifo.{member}'
        cast = r'\*\s*\(\s*volatile\s+(?P<type>(?:unsigned\s+|signed\s+)?\w+)\s*\*\s*\)\s*0[xX](?P<addr>[0-9A-Fa-f]{8})[uUlL]*'
        text = re.sub(r'\(\s*' + cast + r'\s*\)', fifo_sub, text)
        text = re.sub(cast, fifo_sub, text)
        uses_fifo = 'GXWGFifo.' in text and 'GXWGFifo.' not in body
        # absolute object declarations `T name : 0xADDR;`
        def decl_sub(m):
            name, address = m['name'], int(m['addr'], 16)
            if use_headers and name in _HW_OWNED and not (name == 'GXWGFifo' and own_pipe):
                includes.add(_HW_OWNED[name])
                return ''
            spelled = _hw_name(address, table)
            if spelled is None:
                return m[0]
            includes.add('sdk_addresses.h')
            return f"{m['head']}{name} : {spelled};"
        text = re.sub(r'^(?P<head>[ \t]*(?:volatile\s+)?[\w \t*]*?)\b(?P<name>\w+)\s*:\s*0[xX](?P<addr>[0-9A-Fa-f]{8})[uUlL]*\s*;[^\n]*$',
                      decl_sub, text, flags=re.M)
        if uses_fifo and 'GXWGFifo' not in re.sub(r'GXWGFifo\.', '', text):
            if own_pipe or not use_headers:
                if own_pipe:
                    decl = 'volatile PPCWGPipe GXWGFifo : FZGX_ADDR___GXFifo; /* GX write-gather pipe: volatile hardware port */\n'
                    at = re.search(r'\}\s*PPCWGPipe\s*;[^\n]*\n', text)
                    text = text[:at.end()] + decl + text[at.end():]
                    includes.add('sdk_addresses.h')
                else:
                    includes.add('dolphin/gx.h')
            else:
                includes.add('dolphin/gx.h')
        # remaining literals in code and comments
        def lit_sub(m):
            address = int(m[1], 16)
            if _LC_BASE <= address < _LC_BASE + _LC_SIZE:
                # the locked-cache window (`((f32 *)0xE0000000)[3]`, the MTX scratch of fn_1_64760):
                # hw_regs.h's LC_BASE is the same unsigned constant
                includes.add('dolphin/hw_regs.h')
                return 'LC_BASE' if address == _LC_BASE else f'(LC_BASE + 0x{address - _LC_BASE:X})'
            if address == 0x80000000 or not any(lo <= address <= hi for lo, hi in
                                                ((0x80000000, 0x817FFFFF), (0xC0000000, 0xC17FFFFF), (0xCC000000, 0xCC00FFFF))):
                return m[0]
            spelled = _hw_name(address, table)
            if spelled is None:
                return m[0]
            includes.add('sdk_addresses.h')
            return spelled
        lines = []
        for line in text.split('\n'):
            code, sep, comment = line.partition('/*')
            code = _HW_LITERAL.sub(lit_sub, code)
            if sep:
                comment = _HW_LITERAL.sub(lambda m: m[0] if not any(lo <= int(m[1], 16) <= hi for lo, hi in
                                          ((0x80000001, 0x817FFFFF), (0xC0000000, 0xC17FFFFF), (0xCC000000, 0xCC00FFFF)))
                                          else 'its fixed address', comment)
            lines.append(code + sep + comment)
        text = '\n'.join(lines)
        for header in sorted(includes, reverse=True):
            text = _add_include(text, header)
        if text != body and text not in (t for _, t in out):
            out.append(('hardware literals by name' + (' (headers)' if use_headers else ' (sdk addresses)'), text))
    return out


_HELPER_HEADERS = ('psvec.h',)
_STATIC_INLINE_DEF = re.compile(r'^[ \t]*static\s+inline\s+[\w \t*]+?\b(?P<name>\w+)\s*\([^;{)]*\)\s*\{', re.M)


def _header_helper_names(header):
    """Names of the `static inline` helpers a shared header defines (include/psvec.h's kernels)."""
    from .project import ROOT
    path = ROOT / 'include' / header
    try:
        return {m['name'] for m in _STATIC_INLINE_DEF.finditer(path.read_text())}
    except OSError:
        return set()


def _definition_end(text, brace):
    """Index just past the brace matching text[brace] == '{', ignoring braces inside strings,
    character literals and comments; None when unbalanced."""
    depth, i, n = 0, brace, len(text)
    while i < n:
        c = text[i]
        if c == '/' and text.startswith('//', i):
            i = text.find('\n', i)
            if i < 0:
                return None
            continue
        if c == '/' and text.startswith('/*', i):
            j = text.find('*/', i + 2)
            if j < 0:
                return None
            i = j + 2
            continue
        if c in '"\'':
            j = i + 1
            while j < n and text[j] != c:
                j += 2 if text[j] == '\\' else 1
            i = j + 1
            continue
        if c == '{':
            depth += 1
        elif c == '}':
            depth -= 1
            if depth == 0:
                return i + 1
        i += 1
    return None


def header_helper_includes(body, findings):
    """A body that pastes a shared header's inline-assembly helpers (the context prints
    include/psvec.h's kernels and flattened bodies copy them: fn_1_64760, fn_15_3368) fails lint
    A3 although `#include "psvec.h"` compiles the same code. Every pasted definition of a helper
    the header defines is removed and the include added; the oracle rechecks the result.
    Returns [(description, text)]; empty when no A3 finding or no helper is pasted."""
    if not any(rule == 'A3' for rule, _, _ in findings):
        return []
    text = body
    replaced = []
    for header in _HELPER_HEADERS:
        names = _header_helper_names(header)
        if not names:
            continue
        spans = []
        for m in _STATIC_INLINE_DEF.finditer(text):
            if m['name'] not in names:
                continue
            end = _definition_end(text, m.end() - 1)
            if end is None:
                continue
            tail = text[end:]
            nl = tail.find('\n')
            spans.append((m.start(), end + (nl + 1 if nl >= 0 else len(tail)), m['name']))
        if not spans:
            continue
        for start, end, name in sorted(spans, reverse=True):
            text = text[:start] + text[end:]
            replaced.append(name)
        text = _add_include(text, header)
    if not replaced:
        return []
    return [('shared helpers by include ' + ', '.join(sorted(set(replaced))), text)]


_A1_RANGES = ((0x80000000, 0x817FFFFF), (0xC0000000, 0xC17FFFFF), (0xCC000000, 0xCC00FFFF))


def _initializer_offsets(text):
    """Sorted (start, end) spans of brace initializers (`= {...}`, nested braces included)."""
    spans, stack, i, n = [], [], 0, len(text)
    while i < n:
        c = text[i]
        if text.startswith('/*', i):
            j = text.find('*/', i + 2)
            i = n if j < 0 else j + 2
            continue
        if text.startswith('//', i):
            j = text.find('\n', i)
            i = n if j < 0 else j
            continue
        if c in '"\'':
            j = i + 1
            while j < n and text[j] != c:
                j += 2 if text[j] == '\\' else 1
            i = j + 1
            continue
        if c == '{':
            init = bool(stack and stack[-1][0]) or text[:i].rstrip().endswith('=')
            stack.append((init, i))
        elif c == '}' and stack:
            init, start = stack.pop()
            if init and not (stack and stack[-1][0]):
                spans.append((start, i + 1))
        i += 1
    return spans


def non_address_literals(body, findings):
    """A1 literals of an exact match that are values, not addresses: a call argument
    (`fn_1_495B0(0xC0000000)`, fn_15_4578), a scalar (`mask = 0xC0000000`), a float bit pattern
    in a local word table (0xC0400000 is -3.0f). Only literals with no hardware name
    (`hardware_literal_names` spells the rest) and outside a pointer cast (A2, a real address)
    are touched. A word of a brace initializer keeps its spelling and its line gains the
    `fzgx-allow: A1 retail data bytes` comment the data importer writes; any other value is
    respelled `(0xHHHHu << 16)` (`| 0xLLLLu` when the low half is set), the same unsigned
    constant, as fn_1_67680 was respelled by hand. Returns [(description, text)]; the oracle
    rechecks the text, so a respelling that changed code cannot land."""
    rows = {line for rule, line, _ in findings if rule == 'A1'}
    if not rows:
        return []
    table = oracle.abs_symbols()
    inits = _initializer_offsets(body)
    lines = body.split('\n')
    starts, pos = [], 0
    for line in lines:
        starts.append(pos)
        pos += len(line) + 1
    allow, edits = set(), []
    for number in sorted(rows):
        if not 0 < number <= len(lines):
            continue
        line = lines[number - 1]
        code = line.split('//', 1)[0]
        for m in _HW_LITERAL.finditer(code):
            value = int(m[1], 16)
            if value == 0x80000000 or not any(lo <= value <= hi for lo, hi in _A1_RANGES):
                continue
            if _hw_name(value, table) is not None:
                continue
            if re.search(r'\*\s*\)\s*$', code[:m.start()]):
                continue  # `(T *)0x...`: an address (A2), never respelled as a value
            if code.rfind('/*', 0, m.start()) > code.rfind('*/', 0, m.start()):
                continue  # inside a block comment on this line
            at = starts[number - 1] + m.start()
            if any(s < at < e for s, e in inits):
                allow.add(number)
                continue
            suffix = re.match(r'0[xX][0-9A-Fa-f]{8}([uUlL]*)', m[0]).group(1)
            suffix = suffix if 'u' in suffix.lower() else 'u' + suffix
            high, low = value >> 16, value & 0xFFFF
            spelled = f'(0x{high:X}{suffix} << 16)' if not low else f'(0x{high:X}{suffix} << 16 | 0x{low:X}u)'
            edits.append((number, m.start(), m.end(), spelled))
    if not edits and not allow:
        return []
    for number, start, end, spelled in sorted(edits, reverse=True):
        line = lines[number - 1]
        lines[number - 1] = line[:start] + spelled + line[end:]
    for number in sorted(allow):
        if 'fzgx-allow' not in lines[number - 1]:
            lines[number - 1] = lines[number - 1].rstrip() + '  /* fzgx-allow: A1 retail data bytes */'
    steps = []
    if edits:
        steps.append(f'{len(edits)} value literal(s) respelled as shifts')
    if allow:
        steps.append(f'{len(allow)} initializer line(s) marked retail data')
    return [('non-address literals: ' + ', '.join(steps), '\n'.join(lines))]


def lint_spellings(body, findings):
    """Every mechanical lint repair of an exact match composed into one text, so a body that
    needs several (pasted kernels, an `__OSBusClock : 0x800000F8` declaration, a locked-cache
    literal) is clean in one candidate: `header_helper_includes`, then
    `annotate_verified_branches`, then `hardware_literal_names`, then `non_address_literals`
    on the running result. The
    oracle decides afterwards, as for each family alone. Returns [(description, text)]; empty
    when no step applies or the composition equals a single step's text."""
    from .lint import lint_text
    text, steps = body, []
    for family in (header_helper_includes, annotate_verified_branches, hardware_literal_names,
                   non_address_literals):
        current = lint_text(text) if steps else findings
        if not current:
            break
        candidates = family(text, current)
        if not candidates:
            continue
        description, text = candidates[0]
        steps.append(description)
    if len(steps) < 2 or text == body:
        return []
    return [('lint-clean spelling: ' + '; '.join(steps), text)]


# ---------------------------------------------------------------- header drift respelling
# Saved bodies outlive the librarian's header passes: a symbol the body took as `&SYM` into a
# struct-view pointer is later declared `extern u8 SYM[];` (lbl_1_bss_3C00, b73638a3: 26 saved
# bodies stopped compiling with `illegal implicit conversion from 'unsigned char (*)[]'`), and a
# struct the body defined privately later gains a header typedef of the same name (fn_1_36330:
# `identifier 'Obj_1_bss_3C00' redeclared`). Both are spellings, not semantics: the respelled
# body is one more candidate for the oracle (fixup, sweep, recovered seeds) or replaces a seed
# only when the saved text no longer compiles and the respelled one does (claim).

_HEADER_DECLARATIONS: Dict[str, Dict[str, dict]] = {}


def _struct_typedefs(text):
    """{name: normalized member text} for every `typedef struct [tag] {...} name;` in `text`,
    with (start, end) spans in `_struct_typedef_spans`-compatible order; brace balanced so
    nested anonymous structs/unions do not end the scan early."""
    out = {}
    for m in re.finditer(r'(?m)^[ \t]*typedef\s+struct(?:\s+\w+)?\s*\{', text):
        depth, i = 1, m.end()
        while i < len(text) and depth:
            depth += {'{': 1, '}': -1}.get(text[i], 0)
            i += 1
        tail = re.match(r'\s*(\w+)\s*;[ \t]*\n?', text[i:])
        if not depth and tail:
            members = ' '.join(text[m.end():i - 1].split())
            out[tail.group(1)] = dict(members=members, span=(m.start(), i + tail.end()))
    return out


def header_declarations(module):
    """What the module's owned headers declare: incomplete arrays (`extern T NAME[];`) and struct
    typedefs with their normalized member text. Cached per module for the process."""
    if module not in _HEADER_DECLARATIONS:
        root = oracle.ROOT / 'include' if module == 'main' else oracle.ROOT / 'include' / 'rel' / module
        arrays, typedefs = {}, {}
        for path in sorted(root.rglob('*.h')) if root.exists() else []:
            try:
                text = path.read_text(errors='replace')
            except OSError:
                continue
            for m in re.finditer(r'(?m)^\s*extern\s+((?:(?:const|volatile|unsigned|signed|struct)\s+)*\w+)\s+(\w+)\s*\[\s*\]\s*;', text):
                arrays[m.group(2)] = m.group(1)
            for name, record in _struct_typedefs(text).items():
                typedefs[name] = record['members']
        _HEADER_DECLARATIONS[module] = dict(arrays=arrays, typedefs=typedefs)
    return _HEADER_DECLARATIONS[module]


def header_drift_spellings(body, module):
    """[(description, text)]: the body respelled against the module's current headers, empty
    when nothing applies. (1) `&SYM` taken as a struct-view pointer where the header declares
    `extern T SYM[];` becomes `((View *)SYM)`, the view read from the cast, the initialized
    declaration or the assigned lvalue's declared pointer type; a bare cast `(T *)&SYM` just
    drops the `&`. (2) A private `typedef struct {...} Name;` colliding with a header typedef
    is dropped when its members are identical and renamed `Name__fzgx_local` otherwise."""
    decls = header_declarations(module)
    text = body
    steps = []
    # a body that includes no module header owns every declaration it uses (fn_1_2F294's
    # self-contained 90% body): nothing in it drifted
    prefix = 'dol/' if module == 'main' else f'rel/{module}/'
    if not re.search(r'(?m)^\s*#\s*include\s+"(?:' + re.escape(prefix) + r'|(?!types\.h)\w+\.h")', text):
        return []
    # (2) first: a dropped duplicate typedef can be the view type used by (1)
    for name, record in sorted(_struct_typedefs(text).items(), key=lambda kv: -kv[1]['span'][0]):
        header = decls['typedefs'].get(name)
        if header is None:
            continue
        start, end = record['span']
        if record['members'] == header:
            text = text[:start] + text[end:]
            steps.append(f'duplicate header typedef {name} dropped')
        else:
            text = re.sub(r'(?<![\w$])' + re.escape(name) + r'(?![\w$])', name + '__fzgx_local', text)
            steps.append(f'private typedef {name} renamed (differs from the header)')
    for sym in sorted(decls['arrays']):
        if '&' + sym not in text or re.search(r'\bextern\b[^;{}]*\b' + re.escape(sym) + r'\s*[;\[]', text):
            continue  # absent, or declared by the body itself
        ref = r'&\s*' + re.escape(sym) + r'(?![\w\[$])'
        before = text
        # a cast already names the view: `(View *)&SYM` -> `(View *)SYM`
        text = re.sub(r'(\(\s*(?:const\s+)?\w+\s*\*+\s*\))\s*' + ref, r'\1' + sym, text)
        # `View *name = &SYM;`
        text = re.sub(r'(\b(?!return\b)(\w+)\s*\*\s*\w+\s*=\s*)' + ref, lambda m: m.group(1) + f'(({m.group(2)} *){sym})', text)

        # `lvalue = &SYM;`: the view is the declared pointer type of the lvalue's last identifier
        def view_of(lvalue, depth=0):
            # the declared pointer type of the lvalue: `a.b`/`a->b` through the struct `a` is
            # declared with (the one-member carriers), a macro name through one expansion,
            # else the first `T *ident` declaration in the body
            parts = re.findall(r'\w+', lvalue)
            if not parts or depth > 2:
                return None
            ident = parts[-1]
            if len(parts) >= 2:
                carrier = re.search(r'\{[^{}]*?(?<![\w$])(\w+)\s*\*\s*' + re.escape(ident) + r'\s*;[^{}]*\}\s*'
                                    + re.escape(parts[-2]) + r'\s*[;,=\[]', text)
                if carrier:
                    return carrier.group(1)
            macro = re.search(r'(?m)^\s*#\s*define\s+' + re.escape(ident) + r'\s+\(?\s*([\w$][\w$.>\[\]-]*)\s*\)?\s*$', text)
            if macro:
                return view_of(macro.group(1), depth + 1)
            decl = re.search(r'(?<![\w$])(?!return\b)(\w+)\s*\*\s*' + re.escape(ident) + r'\s*(?=[;,=)\[])', text)
            return decl.group(1) if decl else None

        def assign(m):
            # the lvalue is one flat character class, never nested repetition: the earlier
            # declaration-normalizer regex stalled on real drafts
            view = view_of(m.group(1))
            if view is None:
                return m.group(0)
            return m.group(1) + f'(({view} *){sym})'
        text = re.sub(r'((?<![\w$])[\w$][\w$.>\[\]-]*\s*=\s*)' + ref, assign, text)
        if text != before:
            steps.append(f'&{sym} taken as a struct view of the incomplete array')
    if text == body or not steps:
        return []
    return [('header drift: ' + '; '.join(steps), text)]


def header_drift_replacement(project, symbol, body, mw=None, flags=None):
    """(description, text, CheckResult) when `body` no longer compiles under the module's
    current headers and `header_drift_spellings` gives a text that does; None otherwise (the
    saved text stays the seed). Used where one body must be chosen (claim seeding, sweep and
    recovered-manifest seeds); the fixup engine records both as candidates instead."""
    sym = project.resolve(symbol)
    if sym is None:
        return None
    candidates = header_drift_spellings(body, sym.module)
    if not candidates:
        return None
    scratch = oracle.STATE_DIR / 'work' / 'drift' / project.key(sym).replace(':', '__')
    scratch.mkdir(parents=True, exist_ok=True)
    original = scratch / 'original.c'
    original.write_text(body)
    if oracle.check(project, symbol, 0, source=original, mw_version=mw, extra_cflags=flags).ok:
        return None
    description, text = candidates[-1]
    respelled = scratch / 'respelled.c'
    respelled.write_text(text)
    result = oracle.check(project, symbol, 0, source=respelled, mw_version=mw, extra_cflags=flags)
    return (description, text, result) if result.ok else None



_LT_KEYWORDS = {'if', 'else', 'for', 'while', 'do', 'switch', 'return', 'case', 'default', 'break',
                'continue', 'goto', 'sizeof', 'struct', 'union', 'enum', 'typedef', 'static', 'const',
                'volatile', 'register', 'extern', 'inline'}


def _lt_scalar_locals(code: str, span) -> List[Tuple[str, str, int, int]]:
    """(type, name, declaration start, declaration end) of the leading scalar declarations,
    several declarators per line included; arrays and aggregates never take a web."""
    out, i = [], span[1]
    scalar = re.compile(r'\s*((?:(?:const|volatile|register)\s+)*' + TYPE + r')\s*([^;{}()=]*(?:=[^;{}]*)?);')
    other = re.compile(r'\s*(?:(?:const|volatile|static|register)\s+)*(?:(?:struct|union|enum)\b[^;]*?'
                       r'(?:\{[^{}]*\})?[^;{}]*|[A-Za-z_]\w*\s*\**\s*[A-Za-z_(][^;{}]*);')
    while True:
        pre = re.compile(r'\s*#[^\n]*\n').match(code, i)
        if pre:
            i = pre.end()
            continue
        m = scalar.match(code, i)
        words = re.match(r'\s*([A-Za-z_]\w*)', code[i:i + 80])
        if not words or words[1] in _LT_KEYWORDS - {'const', 'volatile', 'register', 'struct', 'union', 'enum', 'static'}:
            return out
        if m and m[2].strip() and not re.match(r'\s*(?:struct|union|enum)\b', m[1]):
            full = re.sub(r'^(?:(?:volatile|register)\s+)+', '', m[1]).strip()
            base = full.rstrip('* ').strip()
            lead = full[len(base):].replace(' ', '')    # `T *a, b`: the star binds to a only
            for n, part in enumerate(m[2].split(',')):
                d = re.fullmatch(r'\s*(\**)\s*([A-Za-z_]\w*)\s*(?:=.*)?', part, re.S)
                if d:
                    stars = (lead if n == 0 else '') + d[1]
                    out.append(((base + ' ' + stars).strip(), d[2], m.start(1), m.end()))
            i = m.end()
            continue
        m = other.match(code, i)
        if not m or re.match(r'\s*[A-Za-z_]\w*\s*(?:=|\(|->|\.|\[)', code[i:m.end()]):
            return out
        i = m.end()





def _lt_splits(code: str, lo: int, hi: int, taken: set):
    """The range splits of one function body code[lo:hi] written as named locals: (tokens,
    renames as (start, end, variable, new name), created locals as (start, type, new name)),
    or None when braces cannot bound the control flow (goto, a loop or switch without
    braces). Every block's leading scalar declarations are considered."""
    if re.search(r'\bgoto\b', code[lo:hi]):
        return None
    toks = [(t.start(), t.end(), t[0]) for t in TOKEN.finditer(code, lo, hi)]

    def opener(k):
        depth, j = 0, k
        while j >= 0:
            depth += {')': 1, '(': -1}.get(toks[j][2], 0)
            if depth == 0:
                return j
            j -= 1
        return -1
    for k, (a, b, t) in enumerate(toks):
        if t in ('for', 'while', 'switch') and k + 1 < len(toks) and toks[k + 1][2] == '(':
            depth, j = 0, k + 1
            while j < len(toks):
                depth += {'(': 1, ')': -1}.get(toks[j][2], 0)
                if depth == 0:
                    break
                j += 1
            if j + 1 >= len(toks) or toks[j + 1][2] not in ('{', ';'):
                return None
        if t == 'do' and (k + 1 >= len(toks) or toks[k + 1][2] != '{'):
            return None
    # the enclosing blocks of every token: (open position, 'loop' / 'switch' / '' body, the
    # loop statement's start)
    stack, chain, close_of, blocks = [(lo - 1, '', lo)], [], {lo - 1: hi}, [lo - 1]
    for k, (a, b, t) in enumerate(toks):
        if t == '{':
            prev = toks[k - 1][2] if k else ''
            kind, begin = ('loop', toks[k - 1][0]) if prev == 'do' else ('', a)
            if prev == ')':
                j = opener(k - 1)
                if j > 0 and toks[j - 1][2] in ('for', 'while', 'switch'):
                    kind = 'switch' if toks[j - 1][2] == 'switch' else 'loop'
                    begin = toks[j - 1][0]
            stack.append((a, kind, begin))
            blocks.append(a)
        chain.append(tuple(stack))
        if t == '}' and len(stack) > 1:
            close_of[stack[-1][0]] = a
            stack.pop()
    rename, created = [], []
    for block_open in blocks:
        b_lo, b_hi = block_open + 1, close_of.get(block_open, hi)
        locs = _lt_scalar_locals(code, (None, b_lo))
        variables = {nm: typ for typ, nm, _, _ in locs}
        decl_end = max((l[3] for l in locs), default=b_lo)
        for var in variables:
            decls = re.findall(r'(?:^|[;{}(,])\s*(?:const\s+)?' + TYPE + r'\s+\**\s*' + re.escape(var)
                               + r'\s*[;=,\[)]', code[b_lo:b_hi])
            if len(decls) > 1 or re.search(r'&\s*' + re.escape(var) + r'\b(?!\s*(?:->|\[))', code[b_lo:b_hi]):
                continue
            mentions = [k for k, (a, b, t) in enumerate(toks) if t == var and b_lo <= a < b_hi
                        and (k == 0 or toks[k - 1][2] not in ('.', '->'))]
            kills = []   # (statement start token, defined-name token)
            for k in mentions:
                if k + 1 >= len(toks) or toks[k + 1][2] != '=':
                    continue
                start = k
                prev = toks[k - 1][2] if k else '{'
                if prev == '(' and k >= 2 and toks[k - 2][2] == 'for':
                    start = k - 2
                    prev = toks[k - 3][2] if k >= 3 else '{'
                if prev not in (';', '{', '}') or chain[start][-1][1] == 'switch':
                    continue    # conditional, or reachable past it through a case label
                j = k + 2
                while j < len(toks) and toks[j][2] != ';':
                    j += 1
                if any(toks[q][2] == var for q in range(k + 2, j)):
                    continue    # a read-modify-write definition keeps its web
                kills.append((start, k))
            regions = []
            for n, (start, k) in enumerate(kills):
                enclosing = chain[start]
                if any(kind == 'switch' for _, kind, _ in enclosing):
                    continue
                # inside a loop a definition starts a web only when nothing in the outermost
                # loop (its header included) reads the variable before it: no value crosses
                # the back edge
                loops = [begin for _, kind, begin in enclosing if kind == 'loop']
                if loops and any(loops[0] <= toks[u][0] < toks[start][0] for u in mentions):
                    continue
                block = enclosing[-1][0]
                stop = next((s for s, _ in kills[n + 1:] if chain[s][-1][0] == block), None)
                stop_pos = toks[stop][0] if stop is not None else close_of.get(block, hi)
                for u in mentions:
                    if u <= k or toks[u][0] < stop_pos:
                        continue
                    # a later mention is safe when a killing definition at the top level of one
                    # of its enclosing blocks lies between the region and it
                    inside = {b0 for b0, _, _ in chain[u]}
                    if not any(stop_pos <= toks[s][0] <= toks[u][0] and chain[s][-1][0] in inside
                               for s, _ in kills):
                        break
                else:
                    regions.append((toks[start][0], stop_pos))
            outside = [toks[u][0] for u in mentions if toks[u][0] >= decl_end
                       and not any(x <= toks[u][0] < y for x, y in regions)]
            for n, (a, b) in enumerate(regions):
                if not outside and n == 0:
                    continue    # every web is a split: the first keeps the declared object
                m = n + 1
                new = f'{var}_r{m}'
                while new in taken or re.search(r'\b' + new + r'\b', code):
                    m += 1
                    new = f'{var}_r{m}'
                taken.add(new)
                rename.append((a, b, var, new))
                created.append((a, variables[var], new))
    return toks, rename, created


def _lt_apply(text: str, toks, rename) -> str:
    edits = []
    for k, (a, b, t) in enumerate(toks):
        if k and toks[k - 1][2] in ('.', '->'):
            continue
        owner = [r for r in rename if r[2] == t and r[0] <= a < r[1]]
        if owner:
            edits.append((a, b, max(owner)[3]))   # the innermost (latest starting) region
    for a, b, new in reversed(edits):
        text = text[:a] + new + text[b:]
    return text


def lifetime_splits(body: str, name: str) -> List[Tuple[str, str]]:
    """`#pragma opt_lifetimes off` with the compiler's range splits written as named locals.

    With lifetimes on, MWCC (IROUseDef.c `fn_00459420`, run when `copts.lifetimes`) splits
    every local whose definitions form disconnected def-use webs into compiler objects
    numbered above every declared local, a read-modify-write chain `x = load; x = x * s + m;`
    included (the load and the result are separate webs). Retail keeps such a chain in one
    register (`lfs f4; fmadds f4, f4, f5, f0`: fn_1_10CC38's locked-cache column, capture
    2026-10-26), which only an unsplit local gives, while every other reused local of the same
    function is split. So the original disabled the splitter and wrote one variable per region:
    every killing definition (`v = e;` or `for (v = e; ...)` at the top level of a block, outside
    any switch, `e` not reading `v`, not read earlier in an enclosing loop) whose later uses are
    all re-killed starts a new named local, declared first in creation order (split objects
    number above the declared locals). Read-modify-write definitions keep the variable. The
    same renaming is offered inside the static inline helpers the function calls (their
    inlined locals are split by the caller's compile)."""
    from .sdkimport import masked
    code = masked(body)
    span = _function_body_span(code, name)
    if not span:
        return []
    taken = set()
    main = _lt_splits(code, span[1], span[2], taken)
    if main is None:
        return []
    toks, rename, created = main
    helpers = []   # (start, helper name, toks, rename, created)
    for h in re.finditer(r'(?m)^static\s+inline\s+[^;{}()]*?\b(\w+)\s*\([^;{}]*\)\s*\{', code):
        if h[1] == name or not re.search(r'\b' + re.escape(h[1]) + r'\s*\(', code[span[1]:span[2]]):
            continue
        hspan = _function_body_span(code[h.start():], h[1])
        if not hspan:
            continue
        found = _lt_splits(code, h.start() + hspan[1], h.start() + hspan[2], taken)
        if found and found[2]:
            helpers.append((h.start(), h[1]) + tuple(found))

    def declare(text, fn, decls, where):
        span2 = _function_body_span(masked(text), fn)
        if where == 'first':
            at = span2[1]
        else:
            locs = _lt_scalar_locals(masked(text), span2)
            at = max(l[3] for l in locs) if locs else span2[1]
        lines = ''.join(f'\n    {declarator(typ.strip(), new)};' for _, typ, new in decls)
        return text[:at] + lines + text[at:]

    def wrap(text):
        span3 = _function_body_span(masked(text), name)
        head = text.rfind('\n', 0, span3[0]) + 1
        end = text.find('\n', span3[2])
        end = len(text) if end < 0 else end + 1
        return (text[:head] + '#pragma opt_lifetimes off\n' + text[head:end]
                + '#pragma opt_lifetimes reset\n' + text[end:])
    out = []
    created.sort()
    if created:
        renamed = _lt_apply(body, toks, rename)
        for label, decls in (('creation order', created), ('reverse creation order', created[::-1])):
            for where in ('first', 'last'):
                out.append((f'lifetimes off, {len(created)} range splits as named locals declared '
                            f'{where} ({label})', wrap(declare(renamed, name, decls, where))))
    if helpers:
        # renames are position based: apply the later function first
        groups = sorted([(span[0], name, toks, rename, created)] + helpers, key=lambda g: -g[0])
        total = sum(len(g[4]) for g in groups)
        for reverse in (False, True):
            text = body
            for _, fn, t, r, c in groups:
                if c:
                    text = declare(_lt_apply(text, t, r), fn, sorted(c, reverse=reverse), 'first')
            out.append((f'lifetimes off, {total} range splits as named locals, inline helpers '
                        f'{",".join(h[1] for h in helpers)} included'
                        + (' (reverse creation order)' if reverse else ''), wrap(text)))
    return out


def _sr_loops(code: str, lo: int, hi: int) -> List[Tuple[int, int]]:
    """(header start, body end) of every for/while/do loop in code[lo:hi] with a braced body."""
    out = []
    for m in re.finditer(r'\b(?:for|while|do)\b', code[lo:hi]):
        a = lo + m.start()
        k = a + len(m.group(0))
        if m.group(0) != 'do':
            k = _close(code, code.find('(', k), hi) if code.find('(', k) >= 0 else None
            if k is None:
                continue
        b = re.match(r'\s*\{', code[k:hi])
        if not b:
            continue
        depth, j = 0, k + b.end() - 1
        while j < hi:
            depth += (code[j] == '{') - (code[j] == '}')
            j += 1
            if depth == 0:
                out.append((a, j))
                break
    return out


def _sr_first_reference_hoists(body: str, name: str) -> List[Tuple[str, str]]:
    """Move a loop header's initialisations ahead of the assignments just before the loop, or
    a header's later initialisations ahead of the loop: either changes which local the
    function references first."""
    from .sdkimport import masked
    code = masked(body)
    span = _function_body_span(code, name)
    if not span:
        return []
    names = {l[3] for l in _locals(body, span)}
    out = []
    for m in re.finditer(r'(?m)^([ \t]*)for\s*\(([^;()]*(?:\([^;()]*\)[^;()]*)*);', code[span[1]:span[2]]):
        indent, init = m.group(1), m.group(2)
        hs = span[1] + m.start(2)
        he = span[1] + m.end(2)
        parts = [x.strip() for x in init.split(',')] if init.strip() else []
        assigns = [re.fullmatch(r'([A-Za-z_]\w*(?:\.\w+)?)\s*=\s*([^=].*)', x) for x in parts]
        if not parts or not all(assigns) or any(a.group(1).split('.')[0] not in names for a in assigns):
            continue
        line_start = span[1] + m.start()
        # the simple assignments immediately before the loop
        run = []
        at = line_start
        while len(run) < 3:
            prev = code.rfind('\n', 0, at - 1) + 1
            pm = re.fullmatch(r'[ \t]*([A-Za-z_]\w*)\s*=\s*([^;{}\n]+);[ \t]*\n', code[prev:at])
            if not pm or pm.group(1) not in names or prev <= span[1]:
                break
            run.insert(0, (prev, at, pm.group(1), pm.group(2)))
            at = prev
        header_vars = {a.group(1).split('.')[0] for a in assigns}
        header_reads = set(re.findall(r'\b\w+\b', ' '.join(a.group(2) for a in assigns)))
        if run and not (header_reads & {r[2] for r in run}) and not any(
                header_vars & set(re.findall(r'\b\w+\b', r[3])) for r in run):
            moved = ''.join(f'{indent}{x};\n' for x in parts)
            text = body[:run[0][0]] + moved + body[run[0][0]:hs] + body[he:]
            out.append((f'split-region order: {",".join(sorted(header_vars))} referenced before '
                        f'{",".join(r[2] for r in run)}', text))
        if len(parts) > 1:
            first = parts[0]
            rest = parts[1:]
            if not set(re.findall(r'\b\w+\b', first)) & {a.group(1) for a in assigns[1:]}:
                moved = ''.join(f'{indent}{x};\n' for x in rest)
                text = body[:line_start] + moved + body[line_start:hs] + first + body[he:]
                out.append((f'split-region order: {",".join(a.group(1) for a in assigns[1:])} '
                            f'referenced before {assigns[0].group(1)}', text))
    return out


def _sr_merges(body: str, name: str) -> List[Tuple[str, str, str]]:
    """A loop pointer or counter local confined to one region renamed to an earlier same-typed local that is
    dead there: (label, merged text, region start in the merged text)."""
    from .sdkimport import masked
    code = masked(body)
    span = _function_body_span(code, name)
    if not span:
        return []
    locs = _locals(body, span)
    inner_lo = locs[-1][1] if locs else span[1]
    loops = _sr_loops(code, inner_lo, span[2])
    norm = lambda t: re.sub(r'\s+', ' ', re.sub(r'\b(?:register|volatile)\b', '', t)).strip()
    uses = {}
    for l in locs:
        if l[4] or ('*' not in l[2] and l[2].strip() not in ('u32', 's32', 'int', 'u16', 's16', 'u8', 's8')):
            continue
        found = [u.start() + inner_lo for u in re.finditer(rf'(?<![\w.>]){re.escape(l[3])}\b', code[inner_lo:span[2]])]
        if found and not re.search(rf'&\s*{re.escape(l[3])}\b', code[inner_lo:span[2]]):
            uses[l[3]] = (l, found)
    out = []
    for p, (pl, pu) in uses.items():
        a, b = pu[0], pu[-1]
        # p must start with a killing definition: `p = ...` (not `==`) and be a loop pointer
        if not re.match(rf'{re.escape(p)}\s*=(?!=)', code[a:a + len(p) + 4]):
            continue
        if not re.search(rf'\b{re.escape(p)}\s*(?:\+\+|\+=)|\+\+\s*{re.escape(p)}\b', code[a:b + len(p) + 4]):
            continue
        found = []
        for q, (ql, qu) in uses.items():
            if q == p or norm(ql[2]) != norm(pl[2]):
                continue
            # an earlier loop's pointer: used before p's region only, or re-killed after it
            if any(a <= u <= b for u in qu) or qu[0] > a:
                continue
            after = [u for u in qu if u > b]
            if after and not re.match(rf'{re.escape(q)}\s*=(?!=)', code[after[0]:after[0] + len(q) + 4]):
                continue
            # q live around a loop that contains p's region would be clobbered
            if any(la <= a and b <= lb and any(la <= u <= lb for u in qu) for la, lb in loops):
                continue
            text = body
            for u in reversed(pu):
                text = text[:u] + q + text[u + len(p):]
            text = text[:pl[0]] + text[pl[1]:]
            found.append((max(u for u in qu if u < a), f'split-region merge: {p} renamed to {q}', text, q))
        # the nearest dead pointer first (the previous loop's)
        out += [f[1:] for f in sorted(found, reverse=True)[:2]]
    return out


def split_region_orders(body: str, name: str) -> List[Tuple[str, str]]:
    """Range-split creation order (IROUseDef.c `fn_00459420`, capture of fn_1_1262A4, 2026-10-26).

    With `opt_lifetimes` on, MWCC splits every local whose definitions form several disconnected
    webs; it walks the variable records in creation order, i.e. the order in which the function
    first references each local, and each split object takes the next `@N`. Split objects are
    numbered in reverse creation order above every declared local, so the region of the local
    referenced first numbers highest and claims its callee-saved register first. Two levers follow:
    the first reference of a loop counter against a loop pointer (`p = base; for (c = 0; ...)`
    against `c = 0; p = base; for (; ...)`), and a loop pointer that retail keeps as a split
    region of an earlier loop's pointer (a separate declared local numbers below every split
    object and claims a low register). Each merge is offered with every first-reference order."""
    combined, merged = [], []
    for label, text, q in _sr_merges(body, name)[:32]:
        merged.append((label, text))
        for l2, t2 in _sr_first_reference_hoists(text, name):
            if re.search(rf'\b{re.escape(q)}\b', l2):
                combined.append((f'{label}; {l2}', t2))
    return combined + merged + _sr_first_reference_hoists(body, name)


_CONST_ADDRESS = re.compile(r'\bLC_BASE\b')
_CONST_ADDRESS_LITERAL = re.compile(r'\b0[xX][eE]0{7}[uU]?\b')


def constant_address_locals(body: str, name: str) -> List[Tuple[str, str]]:
    """The locked-cache base (`LC_BASE`, 0xE0000000) held in a declared local under
    `#pragma opt_propagation off`.

    MWCC hoists a constant address used inside a loop into a compiler object (a pass-2
    shadow) numbered above every declared local, so it claims its callee-saved register
    before them; retail's base often sits below the hoisted pool base and magic divisor
    (fn_1_71D0C: LC r26, pool r27, 0x55555556 r28; ours LC r28). A plain or struct-wrapped
    local assigned the constant is copy-propagated back into that shadow; with propagation
    off the one-member struct keeps a pass-1 web numbered at its declaration. The constant
    reaches every use in the function and in the macros it expands (the macro is redefined
    to the local over the function and restored after it). Variants: every declaration
    position, assigned at the first statement or right before the first top-level loop. A
    static inline helper that uses the base and is called only by this function takes it as
    an extra trailing parameter (`_lc_parameterize_helpers`), since a helper defined before
    the function cannot see the local."""
    out = _constant_address_core(body, name)
    prepared = _lc_parameterize_helpers(body, name)
    if prepared != body:
        seen = {t for _, t in out}
        out += [(label + ' (helper takes the base)', t) for label, t in _constant_address_core(prepared, name)
                if t not in seen]
    return out


def _lc_parameterize_helpers(body: str, name: str) -> str:
    """Every static inline helper whose body names `LC_BASE` and whose only calls are in
    `name` gains a trailing `u32 fzgx_lc_base` parameter that replaces the macro in its body;
    each call passes `LC_BASE` (the same constant, so the expansion is unchanged)."""
    span = _function_body_span(body, name)
    if not span:
        return body
    edits = []
    for m in re.finditer(r'(?m)^static\s+inline\s+[^\n(;]*?\b(\w+)\s*\(([^()]*)\)\s*\{', body[:span[0]]):
        helper, params = m.group(1), m.group(2).strip()
        if helper == name or re.search(r'\bfzgx_lc_base\b', body):
            continue
        depth, k = 0, m.end() - 1
        while k < len(body):
            depth += {'{': 1, '}': -1}.get(body[k], 0)
            if depth == 0:
                break
            k += 1
        hbody = body[m.end():k]
        if not _CONST_ADDRESS.search(hbody):
            continue
        calls = [c for c in re.finditer(rf'\b{re.escape(helper)}\s*\(', body) if c.start() != m.start(1)]
        if not calls or any(not span[1] <= c.start() < span[2] for c in calls):
            continue
        closes = []
        for c in calls:
            d, q = 1, c.end()
            while q < len(body) and d:
                d += {'(': 1, ')': -1}.get(body[q], 0)
                q += 1
            empty = not body[c.end():q - 1].strip()
            closes.append((q - 1, 'LC_BASE' if empty else ', LC_BASE'))
        newparams = 'u32 fzgx_lc_base' if params in ('', 'void') else params + ', u32 fzgx_lc_base'
        edits.append((m.start(2), m.end(2), newparams))
        edits.append((m.end(), k, _CONST_ADDRESS.sub('fzgx_lc_base', hbody)))
        edits += [(q, q, arg) for q, arg in closes]
    for a, b, t in sorted(edits, reverse=True):
        body = body[:a] + t + body[b:]
    return body


def _constant_address_core(body: str, name: str) -> List[Tuple[str, str]]:
    out: List[Tuple[str, str]] = []
    a = _decl_anchor(body, name)
    if not a:
        return out
    span, locs, top, indent = a
    inner = body[top:span[2]]
    macro = bool(_CONST_ADDRESS.search(inner)) or any(
        _CONST_ADDRESS.search(m.group(2)) and re.search(rf'\b{re.escape(m.group(1))}\b', inner)
        for m in re.finditer(r'(?m)^[ \t]*#\s*define\s+(\w+)(?:\([^)]*\))?([^\n]*)', body[:span[0]]))
    literal = bool(_CONST_ADDRESS_LITERAL.search(inner))
    if not (macro or literal) or re.search(r'\bfzgx_lc\b', body):
        return out
    head_start = body.rfind('\n', 0, span[0]) + 1
    end = body.find('\n', span[2])
    end = len(body) if end < 0 else end + 1
    loop = re.search(r'(?m)^' + re.escape(indent) + r'(?:for|while|do)\b', inner)
    sites = [('at the first statement', top)]
    if loop and loop.start() > 0:
        sites.append(('before the first loop', top + loop.start()))
    # the declaration position never changed the result (fn_1_71D0C: all nine equal);
    # the assignment site did. First and last keep the budget small.
    positions = sorted({locs[0][0] if locs else top, top})
    decl = f'{indent}struct {{ u32 value; }} fzgx_lc;\n'
    for pragma in (True, False):
        for k, pos in enumerate(positions):
            for where, at in sites:
                text = body[:span[2]]
                stmt = f'{indent}fzgx_lc.value = LC_BASE;\n' if macro else f'{indent}fzgx_lc.value = 0xE0000000u;\n'
                if macro:
                    stmt += '#undef LC_BASE\n#define LC_BASE (fzgx_lc.value)\n'
                tail = text[at:]
                if literal:
                    tail = _CONST_ADDRESS_LITERAL.sub('fzgx_lc.value', tail)
                text = text[:at] + stmt + tail
                text = text[:pos] + decl + text[pos:]
                fn_text = text[head_start:] + body[span[2]:end]
                after = ''
                if pragma:
                    fn_text = '#pragma opt_propagation off\n' + fn_text
                    after += '#pragma opt_propagation reset\n'
                if macro:
                    after += '#undef LC_BASE\n#define LC_BASE 0xE0000000u\n'
                out.append((f"locked-cache base in a declared local #{k} {where}"
                            + (" under opt_propagation off" if pragma else ""),
                            body[:head_start] + fn_text + after + body[end:]))
    return out


_INT_SPELLING = r'(?:signed\s+int|signed|int|unsigned\s+int|unsigned)'
_LONG_OF = {'signed int': 'long', 'signed': 'long', 'int': 'long',
            'unsigned int': 'unsigned long', 'unsigned': 'unsigned long'}


def long_loop_counters(body: str, name: str) -> List[Tuple[str, str]]:
    """A constant-start loop counter declared `long` (`s32`) instead of `int`: the IR
    unroller's entry guard then survives.

    `unroll_loop` (IroLoop.c) copies the loop test into the preheader as an entry guard
    after the last pass-0 constant propagation that precedes it; the trip count comes from
    the init's constant directly, so it is known either way. `IRO_CopyAndConstantPropagation`
    then folds the guard when the counter's `V = 0` is a propagation candidate, which needs
    the assignment's type to be the variable's own type object: an `int` constant assigned to
    a `long` counter is not, so retail's `li r5, 0; cmpwi r5, 0xfee; bge` before the
    unrolled loop's `mtctr` stays while the count is still `li r0, 0x1fd` (the three LZ
    window clears fn_18_444, fn_1_1304C, fn_1_1289C, round 69; function-wide
    `opt_propagation off` also keeps the guard but leaves the count guard and breaks other
    loops). Every counter of a `for` loop initialised with a constant (in the header, or by
    `V = c;` before `for (; V ...)`) is retyped at its declaration, one at a time and all
    together; a comma declaration splits the counter out after (and before) the rest."""
    out: List[Tuple[str, str]] = []
    span = _function_body_span(body, name)
    if not span:
        return out
    inner = body[span[1]:span[2]]
    const = r'-?(?:0[xX][0-9a-fA-F]+|\d+)[uUlL]*'
    names: List[str] = []
    for m in re.finditer(rf'\bfor\s*\(\s*(\w+)\s*=\s*{const}\s*;\s*\1\s*(?:<|<=|!=|>|>=)', inner):
        names.append(m.group(1))
    for m in re.finditer(rf'\bfor\s*\(\s*;\s*(\w+)\s*(?:<|<=|!=|>|>=)', inner):
        v = m.group(1)
        prev = list(re.finditer(rf'\b{re.escape(v)}\s*=\s*({const})\s*;', inner[:m.start()]))
        if prev and not re.search(rf'\b{re.escape(v)}\s*(?:[-+*/|&^]?=(?!=)|\+\+|--)',
                                  inner[prev[-1].end():m.start()]):
            names.append(v)
    names = list(dict.fromkeys(names))
    retyped = {v: _long_counter_options(body, name, v) for v in names}
    for v, options in retyped.items():
        for where, text in options:
            out.append((f'loop counter {v} declared long{where}', text))
    if sum(1 for o in retyped.values() if o) > 1:
        text = body
        for v in names:
            options = _long_counter_options(text, name, v)
            text = options[0][1] if options else text
        out.append(('every constant-start loop counter declared long', text))
    return out


def _long_counter_options(body: str, name: str, v: str) -> List[Tuple[str, str]]:
    """`v`'s `int` declaration in `name` respelled `long` (a comma list splits it out)."""
    span = _function_body_span(body, name)
    if not span:
        return []
    decl = re.compile(rf'(?m)^([ \t]*)({_INT_SPELLING})\s+([^;\n()]*?)\s*;')
    for d in decl.finditer(body, span[1], span[2]):
        parts = [p.strip() for p in d.group(3).split(',')]
        hit = [k for k, p in enumerate(parts) if re.match(rf'{re.escape(v)}\b(?!\s*\[)', p)]
        if not hit:
            continue
        ind, ty = d.group(1), re.sub(r'\s+', ' ', d.group(2))
        longty, own = _LONG_OF[ty], parts[hit[0]]
        if len(parts) == 1:
            return [('', body[:d.start()] + f'{ind}{longty} {own};' + body[d.end():])]
        rest = ', '.join(p for k, p in enumerate(parts) if k != hit[0])
        return [(' after the rest', body[:d.start()] + f'{ind}{ty} {rest};\n{ind}{longty} {own};' + body[d.end():]),
                (' before the rest', body[:d.start()] + f'{ind}{longty} {own};\n{ind}{ty} {rest};' + body[d.end():])]
    return []


# ---------------------------------------------------------------- uninverted exit-branch pairs
# MWCC inverts `if (c) goto L; goto X; L:` only at statement level (COptimizer
# fold_and_invert_conditional_branch). `if (A || B || C) return;` lowers its leaves in codegen:
# A and B branch to the shared exit block, the last leaf keeps `bCC next; b exit`, and the exit
# block keeps several predecessors. Separate early exits, or an `&&` guard around the rest of
# the body, give the single inverted `b!CC exit`. A dead `b X` right after a switch dispatch is
# an orphaned default/case block of the same mechanism (docs/MWCC_IDIOMS.md, "Laws to apply
# first"; fn_1_1018BC 7 -> 5 rows, fn_1_D523C 23 -> 21 rows by hand).

_EXIT_STMT = re.compile(r'(?:return\b[^;]*|goto\s+\w+|break|continue)\s*;')


def _ex_statements(code: str, lo: int, hi: int) -> Optional[List[Tuple[int, int]]]:
    """Top-level statement spans of code[lo:hi] (masked code: no comments or strings).
    A label prefix stays with its statement; an `else` continues its `if`; `= {...};`
    initializers and `do {...} while (c);` end at their semicolon."""
    spans, start, paren, brace, i = [], None, 0, 0, lo
    while i < hi:
        c = code[i]
        if start is None:
            if c.isspace():
                i += 1
                continue
            if c == '#':  # a preprocessor line inside the body: not reliable
                return None
            start = i
        if c in '([':
            paren += 1
        elif c in ')]':
            paren -= 1
        elif c == '{':
            brace += 1
        elif c == '}':
            brace -= 1
            if brace == 0 and paren == 0:
                rest = code[i + 1:hi]
                head = code[start:i]
                # a compound statement ends at its brace; a declaration's `= {...}` at its `;`
                compound = re.match(r'(?:(?!default\b)\w+\s*:(?!:)\s*)*(?:if|for|while|switch|else|\{)', head)
                if compound and not re.match(r'\s*(?:else\b|;|,|\))', rest) and not re.match(r'do\b', head):
                    spans.append((start, i + 1))
                    start = None
        elif c == ';' and paren == 0 and brace == 0:
            if not re.match(r'\s*else\b', code[i + 1:hi]):
                spans.append((start, i + 1))
                start = None
        if paren < 0 or brace < 0:
            return None
        i += 1
    return spans if start is None else None


def _ex_match_paren(code: str, i: int) -> Optional[int]:
    """Index after the parenthesis matching code[i] == '('."""
    depth = 0
    for j in range(i, len(code)):
        depth += (code[j] == '(') - (code[j] == ')')
        if depth == 0:
            return j + 1
    return None


def _ex_if(code: str, s: int, e: int):
    """(cond_lo, cond_hi, then_lo, then_hi, braced) of `if (C) S` without else, else None."""
    m = re.match(r'if\s*\(', code[s:e])
    if not m:
        return None
    po = s + m.end() - 1
    pc = _ex_match_paren(code, po)
    if pc is None or pc > e:
        return None
    j = pc
    while j < e and code[j].isspace():
        j += 1
    if j >= e:
        return None
    if code[j] == '{':
        depth, k = 0, j
        while k < e:
            depth += (code[k] == '{') - (code[k] == '}')
            if depth == 0:
                break
            k += 1
        if k + 1 != e:
            return None  # an else branch or trailing text
        return po + 1, pc - 1, j + 1, k, True
    if re.search(r'\belse\b', code[j:e]):
        return None
    return po + 1, pc - 1, j, e, False


def _ex_exit(code: str, body: str, lo: int, hi: int) -> Optional[str]:
    """The single exit statement of a then-branch, normalized, else None."""
    if not _EXIT_STMT.fullmatch(code[lo:hi].strip()):
        return None
    return ' '.join(body[lo:hi].split())


def _ex_top_ops(expr: str) -> List[Tuple[int, str]]:
    """(index, operator) of the depth-0 logical, comparison, assignment, ternary and comma
    operators of an expression."""
    out, depth, i, n = [], 0, 0, len(expr)
    while i < n:
        c = expr[i]
        if c in '([{':
            depth += 1
        elif c in ')]}':
            depth -= 1
        elif depth == 0:
            two = expr[i:i + 2]
            if two in ('<<', '>>'):
                if expr[i + 2:i + 3] == '=':
                    out.append((i, '='))
                    i += 3
                    continue
                i += 2
                continue
            if two == '->':
                i += 2
                continue
            if two in ('&&', '||', '==', '!=', '<=', '>='):
                out.append((i, two))
                i += 2
                continue
            if two in ('+=', '-=', '*=', '/=', '%=', '&=', '|=', '^='):
                out.append((i, '='))
                i += 2
                continue
            if c in '<>?,=':
                out.append((i, c))
        i += 1
    return out


def _ex_strip(expr: str) -> str:
    expr = expr.strip()
    while expr.startswith('(') and _ex_match_paren(expr, 0) == len(expr):
        expr = expr[1:-1].strip()
    return expr


def _ex_split(expr: str, op: str) -> List[str]:
    expr = _ex_strip(expr)
    parts, last = [], 0
    for i, o in _ex_top_ops(expr):
        if o == op:
            parts.append(expr[last:i].strip())
            last = i + 2
    parts.append(expr[last:].strip())
    return parts


def _ex_operand(expr: str) -> str:
    """An operand of a `||` chain: parenthesized when it holds a lower-precedence operator."""
    expr = _ex_strip(expr)
    if any(o in ('?', ',', '=', '&&') for _, o in _ex_top_ops(expr)) or _ex_bitwise(expr):
        return f'({expr})'
    return expr


def _ex_bitwise(expr: str) -> bool:
    """A depth-0 binary `&`, `|` or `^` (kept parenthesized inside a logical chain)."""
    depth = 0
    for i, c in enumerate(expr):
        if c in '([{':
            depth += 1
        elif c in ')]}':
            depth -= 1
        elif depth == 0 and c in '&|^' and expr[i - 1:i] != c and expr[i + 1:i + 2] != c:
            prev = expr[:i].rstrip()[-1:]
            if prev and (prev.isalnum() or prev in '_)]'):
                return True
    return False


_EX_FLIP = {'==': '!=', '!=': '==', '<': '>=', '>=': '<', '>': '<=', '<=': '>'}


def _ex_negate(expr: str) -> str:
    expr = _ex_strip(expr)
    ops = _ex_top_ops(expr)
    kinds = {o for _, o in ops}
    if '||' in kinds and not kinds & {'?', ',', '='}:
        return ' && '.join(_ex_and_operand(_ex_negate(x)) for x in _ex_split(expr, '||'))
    if '&&' in kinds and not kinds & {'?', ',', '=', '||'}:
        return ' || '.join(_ex_operand(_ex_negate(x)) for x in _ex_split(expr, '&&'))
    if len(ops) == 1 and ops[0][1] in _EX_FLIP:
        i, o = ops[0]
        return f'{expr[:i].strip()} {_EX_FLIP[o]} {expr[i + len(o):].strip()}'
    if not ops and expr.startswith('!'):
        inner = expr[1:].strip()
        if inner.startswith('(') and _ex_match_paren(inner, 0) == len(inner):
            return _ex_strip(inner)
        if re.fullmatch(r'\w+(?:(?:\.|->)\w+|\[\w+\])*', inner):
            return inner
    if not ops and re.fullmatch(r'\w+(?:(?:\.|->)\w+|\[\w+\])*', expr):
        return '!' + expr
    return f'!({expr})'


def _ex_and_operand(expr: str) -> str:
    return f'({expr})' if any(o in ('?', ',', '=', '||') for _, o in _ex_top_ops(expr)) or _ex_bitwise(expr) else expr


def _ex_indent(body: str, pos: int) -> str:
    line = body.rfind('\n', 0, pos) + 1
    return re.match(r'[ \t]*', body[line:]).group(0)


def _ex_shift(text: str, ind: str, delta: int) -> str:
    """Lines after the first re-indented by delta spaces (negative: removed when present)."""
    lines = text.split('\n')
    out = [lines[0]]
    for l in lines[1:]:
        if delta < 0:
            cut = min(-delta, len(l) - len(l.lstrip(' ')))
            out.append(l[cut:])
        else:
            out.append((' ' * delta + l) if l.strip() else l)
    return '\n'.join(out)


def _ex_if_text(cond: str, exit_stmt: str, indent: str, braced: bool) -> str:
    if braced:
        return f'if ({cond}) {{\n{indent}    {exit_stmt}\n{indent}}}'
    return f'if ({cond}) {exit_stmt}'


def _ex_blocks(code: str, span) -> List[Tuple[int, int, str]]:
    """(inner_lo, inner_hi, kind) of every compound block of the function body; kind is
    'top', 'loop', 'switch' or 'other'."""
    out = [(span[1], span[2], 'top')]
    for i in range(span[1], span[2]):
        if code[i] != '{':
            continue
        depth, k = 0, i
        while k < span[2]:
            depth += (code[k] == '{') - (code[k] == '}')
            if depth == 0:
                break
            k += 1
        if k >= span[2]:
            continue
        head = code[max(span[1], i - 600):i].rstrip()
        kind = 'other'
        if head.endswith(')'):
            depth2, j = 0, len(head) - 1
            while j >= 0:
                depth2 += (head[j] == ')') - (head[j] == '(')
                if depth2 == 0:
                    break
                j -= 1
            kw = re.search(r'(\w+)\s*$', head[:j])
            if kw and kw.group(1) in ('for', 'while'):
                kind = 'loop'
            elif kw and kw.group(1) == 'switch':
                kind = 'switch'
        elif re.search(r'\bdo$', head):
            kind = 'loop'
        elif head.endswith('='):
            continue  # an initializer
        out.append((i + 1, k, kind))
    return out


def exit_branch_chains(body: str, name: str, limit: int = 96) -> List[Tuple[str, str]]:
    """Early-exit spellings that decide whether an exit test keeps retail's uninverted
    `bCC next; b exit` pair: consecutive `if (A) EXIT; if (B) EXIT;` merged into one `||`
    condition (every contiguous run), an `||` exit split back into separate statements, a
    trailing `&&` guard of a void body (or loop body) turned into a negated `||` early return
    (`continue`) merged with the exits before it, and the reverse (early return -> guard).
    Switches: default clauses moved, dropped, added or respelled; an orphaned default block
    is retail's dead `b X` after the dispatch (switch_default_variants)."""
    from .sdkimport import masked
    code = masked(body)
    span = _function_body_span(code, name)
    if not span:
        return []
    void_fn = bool(re.search(r'\bvoid\s+' + re.escape(name) + r'\s*\(', code[max(0, span[0] - 40):span[1]]))
    out: List[Tuple[str, str]] = []

    def emit(label, lo, hi, text):
        new = body[:lo] + text + body[hi:]
        if new != body:
            out.append((label, new))

    for blo, bhi, kind in _ex_blocks(code, span):
        if kind == 'switch':
            continue
        stmts = _ex_statements(code, blo, bhi)
        if not stmts:
            continue
        info = []
        for s, e in stmts:
            m = _ex_if(code, s, e)
            ex = _ex_exit(code, body, m[2], m[3]) if m else None
            info.append((s, e, m, ex))
        # 1. merge every contiguous run (length >= 2) of early exits sharing one exit statement
        i = 0
        while i < len(info):
            j = i
            while info[i][3] and j + 1 < len(info) and info[j + 1][3] == info[i][3]:
                j += 1
            for a in range(i, j):
                for b in range(a + 1, j + 1):
                    conds = [_ex_operand(body[info[k][2][0]:info[k][2][1]]) for k in range(a, b + 1)]
                    text = _ex_if_text(' || '.join(conds), info[a][3], _ex_indent(body, info[a][0]), info[a][2][4])
                    emit(f'merge {b - a + 1} early exits ({info[a][3]}) into one ||', info[a][0], info[b][1], text)
            i = j + 1
        # 2. split an `||` exit into separate statements (fully, and at each single cut)
        for s, e, m, ex in info:
            if not ex:
                continue
            parts = _ex_split(body[m[0]:m[1]], '||')
            if not 2 <= len(parts) <= 8:
                continue
            ind = _ex_indent(body, s)
            cuts = [list(range(1, len(parts)))] + ([[c] for c in range(1, len(parts))] if len(parts) > 2 else [])
            for cut in cuts:
                groups, last = [], 0
                for c in cut + [len(parts)]:
                    groups.append(' || '.join(_ex_operand(x) for x in parts[last:c]))
                    last = c
                emit(f'split || exit ({ex}) at {cut}', s, e,
                     ('\n' + ind).join(_ex_if_text(g, ex, ind, m[4]) for g in groups))
        # 3. a trailing guard `if (C) { BODY }` -> `if (!C) EXIT; BODY`, merged with the exits before it
        exit_stmt = 'return;' if kind == 'top' and void_fn else 'continue;' if kind == 'loop' else None
        if exit_stmt and info:
            s, e, m, ex = info[-1]
            if m and m[4] and not ex and code[m[2]:m[3]].strip():
                ind = _ex_indent(body, s)
                inner = body[m[2]:m[3]].strip()
                inner = _ex_shift(inner, ind, -4)
                neg = _ex_negate(body[m[0]:m[1]])
                for braced in (False, True):
                    emit(f'guard -> early {exit_stmt[:-1]}{" (braced)" if braced else ""}', s, e,
                         _ex_if_text(neg, exit_stmt, ind, braced) + '\n' + ind + inner)
                k = len(info) - 2
                while k >= 0 and info[k][3] == exit_stmt:
                    k -= 1
                for a in range(k + 1, len(info) - 1):
                    conds = [_ex_operand(body[info[q][2][0]:info[q][2][1]]) for q in range(a, len(info) - 1)]
                    conds.append(_ex_operand(neg))
                    emit(f'guard -> early {exit_stmt[:-1]} merged with {len(info) - 1 - a} exits', info[a][0], e,
                         _ex_if_text(' || '.join(conds), exit_stmt, ind, info[a][2][4]) + '\n' + ind + inner)
        # 4. the reverse: one of the last early returns of a void body -> a guard around the rest
        if kind == 'top' and void_fn:
            for idx, (s, e, m, ex) in enumerate(info[:-1]):
                if ex != 'return;' or idx < len(info) - 7:
                    continue
                ind = _ex_indent(body, s)
                rest = _ex_shift(body[info[idx + 1][0]:info[-1][1]], ind, 4)
                emit('early return -> guard', s, info[-1][1],
                     f'if ({_ex_negate(body[m[0]:m[1]])}) {{\n{ind}    {rest}\n{ind}}}')
    out.extend(switch_default_variants(body, name, code, span, void_fn))
    seen, uniq = set(), []
    for label, text in out:
        if text not in seen:
            seen.add(text)
            uniq.append((label, text))
    return uniq[:limit]


def switch_default_variants(body: str, name: str, code: str, span, void_fn: bool) -> List[Tuple[str, str]]:
    """The default clause of every switch moved first/last, dropped when it only breaks,
    added when missing, and its single exit respelled; a contiguous-range switch whose cases
    share one `break` becomes a range test with the default's exit."""
    out: List[Tuple[str, str]] = []
    for m in re.finditer(r'\bswitch\s*\(', code[span[1]:span[2]]):
        sw_lo = span[1] + m.start()
        po = span[1] + m.end() - 1
        pc = _ex_match_paren(code, po)
        if pc is None:
            continue
        ob = code.find('{', pc)
        if ob < 0 or code[pc:ob].strip():
            continue
        depth, cb = 0, ob
        while cb < span[2]:
            depth += (code[cb] == '{') - (code[cb] == '}')
            if depth == 0:
                break
            cb += 1
        if cb >= span[2]:
            continue
        labels, depth, i = [], 0, ob + 1
        while i < cb:
            c = code[i]
            if c in '({[':
                depth += 1
            elif c in ')}]':
                depth -= 1
            elif depth == 0 and not (code[i - 1].isalnum() or code[i - 1] == '_'):
                lm = re.match(r'(case\b[^:;]*?|default\s*):(?!:)', code[i:cb])
                if lm:
                    labels.append((i, i + lm.end(), lm.group(1).strip()))
                    i += lm.end()
                    continue
            i += 1
        if not labels or code[ob + 1:labels[0][0]].strip():
            continue
        clauses = []  # (start, end of labels, end, [labels])
        k = 0
        while k < len(labels):
            j = k
            while j + 1 < len(labels) and not code[labels[j][1]:labels[j + 1][0]].strip():
                j += 1
            end = labels[j + 1][0] if j + 1 < len(labels) else cb
            clauses.append((labels[k][0], labels[j][1], end, [l[2] for l in labels[k:j + 1]]))
            k = j + 1
        ind = _ex_indent(body, labels[0][0])
        close = body.rfind('\n', 0, cb) + 1
        close = close if not body[close:cb].strip() else cb

        def rebuild(cls, extra=''):
            pieces = [ind + body[lo:hi].strip() for lo, _, hi, _ in cls] + ([ind + extra] if extra else [])
            return body[:ob + 1] + '\n' + '\n'.join(pieces) + '\n' + body[close:]

        dflt = [c for c in clauses if 'default' in c[3]]
        if not dflt:
            for alt in ['break;'] + (['return;'] if void_fn else []):
                out.append((f'switch default {alt} added last', rebuild(clauses, f'default: {alt}')))
            continue
        d = dflt[0]
        others = [c for c in clauses if c is not d]
        if d[3] != ['default'] or not others:
            continue
        stmt = ' '.join(code[d[1]:d[2]].split())
        if clauses[0] is not d:
            out.append(('switch default first', rebuild([d] + others)))
        if clauses[-1] is not d:
            out.append(('switch default last', rebuild(others + [d])))
        if stmt in ('break;', 'continue;', ''):
            out.append(('switch default dropped', rebuild(others)))
        if _EXIT_STMT.fullmatch(stmt):
            for alt in ['break;', 'continue;'] + (['return;'] if void_fn else []):
                if alt != stmt:
                    out.append((f'switch default {stmt} -> {alt}', body[:d[1]] + ' ' + alt + body[d[1] + len(body[d[1]:d[2]].rstrip()):]))
                    if clauses[-1] is not d:
                        out.append((f'switch default {stmt} -> {alt}, last', rebuild(others, f'default: {alt}')))
        # a contiguous-range switch whose cases share one `break;` -> a range test with the default's exit
        if len(others) == 1 and ' '.join(code[others[0][1]:others[0][2]].split()) == 'break;' and _EXIT_STMT.fullmatch(stmt):
            values = [_int_literal(l[4:].strip()) if l.startswith('case') else None for l in others[0][3]]
            if values and None not in values and sorted(values) == list(range(min(values), max(values) + 1)):
                lo, hi = min(values), max(values)
                e = _ex_strip(body[po + 1:pc - 1])
                e = e if re.fullmatch(r'\w+(?:(?:\.|->)\w+|\[\w+\])*', e) else f'({e})'
                sw_ind = _ex_indent(body, sw_lo)
                tests = [f'{e} < {lo} || {e} > {hi}', f'{e} > {hi} || {e} < {lo}', f'{e} >= {hi + 1}',
                         f'!({e} >= {lo} && {e} <= {hi})'] + ([f'(u32){e} > {hi}'] if lo == 0 else [])
                for t in tests:
                    for braced in (False, True):
                        out.append((f'range switch -> if ({t}) {stmt}',
                                    body[:sw_lo] + _ex_if_text(t, stmt, sw_ind, braced) + body[cb + 1:]))
    return [(l, t) for l, t in out if t and t != body]
