"""The librarian's queue: conflicts found mechanically in the tree, plus matchers' notes.

Read-only. Every row is `{kind, severity, resolution, module, tu, symbol, detail, source,
blocks}`; `source` says where the row came from (`tree`, `type-survey`, `ledger`, `waves.md`)
so a structured notes field can join later as one more source.

  kind        prototype      a function's declarations disagree with its matched definition
              declaration    an unmatched function is declared with different signatures
              data           one object declared with different types/sizes in one TU
              overlap        a declared object is larger than its retail symbol and covers
                             another object the TU declares
              unused_helper  a block's static helper is never referenced
              implicit_call  a block calls a project function it never declares
              no_header      a matched function that unmatched callers in other TUs need,
                             declared by no header
              struct_views   a type-survey cluster: private struct views of one object
              note           a matcher's recorded note naming the librarian/headers
  severity    code      the disagreement changes generated code (register class, width,
                        signedness, arity, an implicit int/double conversion, object size)
              cosmetic  types are register-identical (pointer types, pointer vs 32-bit int)
              note      free text
  resolution  'tutruth resolves'  `fzgx tutruth` picks a truth (header > matched definition >
                                  prologue > most common spelling) and rewrites every user
                                  mechanically (its oracle re-check still decides)
              'needs a decision'  no mechanical rule applies (a header disagrees with a
                                  matched definition, a caller uses a void result, a view
                                  is larger than its truth, cross-TU declarations, hygiene)

The parsers are tutruth's/reconcile's/tutidy's; struct sizes come from typesurvey.
"""

from __future__ import annotations

import re
import sqlite3
from collections import Counter, defaultdict
from typing import Dict, List, Optional, Set, Tuple

from . import reconcile, tufile, tutidy, tutruth, typesurvey
from .project import ROOT, STATE_DIR, Project

RESOLVES = "tutruth resolves"
DECIDE = "needs a decision"
KEYWORDS = {"if", "while", "for", "switch", "return", "sizeof", "do", "else", "case"}
INT_TYPES = {
    "s8": (1, True), "char": (1, True), "signed char": (1, True), "u8": (1, False), "unsigned char": (1, False),
    "s16": (2, True), "short": (2, True), "u16": (2, False), "unsigned short": (2, False),
    "s32": (4, True), "int": (4, True), "long": (4, True), "signed": (4, True), "BOOL": (4, True),
    "signed int": (4, True), "u32": (4, False), "unsigned": (4, False), "unsigned int": (4, False),
    "unsigned long": (4, False), "size_t": (4, False),
    "s64": (8, True), "u64": (8, False), "long long": (8, True), "unsigned long long": (8, False),
}
FLOAT_TYPES = {"f32": 4, "float": 4, "f64": 8, "double": 8}
NOTE_RE = re.compile(r"\b(librarian|tutruth|prototype|header)\b", re.I)
SYM_RE = re.compile(r"\b((?:fn|lbl)_[0-9A-Fa-f_]+|[A-Z][A-Za-z0-9]+_[A-Za-z0-9_]+)\b")


def _row(kind, severity, resolution, module, tu, symbol, detail, source="tree", blocks=None) -> dict:
    return {"kind": kind, "severity": severity, "resolution": resolution, "module": module, "tu": tu,
            "symbol": symbol, "detail": detail, "source": source, "blocks": sorted(set(blocks or []))}


# ------------------------------------------------------------------ type comparison
def _clean(t: str) -> str:
    t = re.sub(r"\b(const|volatile|extern|static|inline|struct|union|enum)\b", "", t)
    return re.sub(r"\s+", " ", t).replace(" *", "*").strip()


def _kind(t: str, survey: typesurvey.Survey, path: str) -> Tuple:
    """('v',) void, ('p',) pointer, ('f', size), ('i', size, signed), ('?', name)."""
    c = _clean(t)
    if c == "void":
        return ("v",)
    if "*" in c or "(" in c:
        return ("p",)
    if c in FLOAT_TYPES:
        return ("f", FLOAT_TYPES[c])
    if c in INT_TYPES:
        return ("i",) + INT_TYPES[c]
    info = survey.type_info(c, path)
    if info and info[2] == "p":
        return ("p",)
    if info and info[2] == "f":
        return ("f", info[0])
    if info and info[2] == "i" and info[0] <= 8:
        alias = survey.aliases.get(c)
        return ("i", info[0], INT_TYPES.get(alias, (0, True))[1]) if alias in INT_TYPES else ("i", info[0], None)
    return ("?", c)


def _type_severity(a: str, b: str, survey, path) -> Optional[str]:
    """None when equal, 'cosmetic' when register-identical, else 'code'."""
    if tutruth._same(a, b) or _clean(a) == _clean(b):
        return None
    ka, kb = _kind(a, survey, path), _kind(b, survey, path)
    if ka == kb and ka[0] != "?":
        return "cosmetic"  # two pointer types, or two spellings of one integer type
    if {ka[0], kb[0]} == {"p", "i"} and all(k[0] == "p" or (k[1] == 4) for k in (ka, kb)):
        return "cosmetic"  # u32 against a pointer: the same GPR
    if ka[0] == kb[0] == "i" and ka[1] == kb[1] and None in (ka[2], kb[2]):
        return "cosmetic"
    return "code"


def _sig_severity(d: Tuple, o: Tuple, survey, path) -> Tuple[Optional[str], str]:
    """(severity, short description) of a declaration `o` against signature `d`."""
    worst = None
    why = []
    s = _type_severity(d[0], o[0], survey, path)
    if s:
        worst = s
        why.append(f"returns {o[0]} (definition {d[0]})")
    dp = [x for x in d[2]]
    op = [x for x in o[2]]
    if o[3] or d[3]:  # non-prototype `T f();` / K&R `T f()`: only the return type is declared
        return worst, "; ".join(why) or ""
    fixed_d = [x for x in dp if x != "..."]
    fixed_o = [x for x in op if x != "..."]
    if len(fixed_d) != len(fixed_o) and not ("..." in dp and len(fixed_o) >= len(fixed_d)):
        worst = "code"
        why.append(f"{len(fixed_o)} parameters (definition {len(fixed_d)})")
    else:
        for i, (a, b) in enumerate(zip(fixed_d, fixed_o)):
            s = _type_severity(a, b, survey, path)
            if s:
                why.append(f"arg{i} {b} (definition {a})")
                worst = "code" if "code" in (worst, s) else s
    return worst, "; ".join(why)


def _sig(decl: str) -> Optional[Tuple[str, str, List[str], bool]]:
    s = tutruth._sig(decl)
    if not s:
        return None
    knr = bool(re.search(r"\b" + re.escape(s[1]) + r"\s*\(\s*\)", decl))
    return s[0], s[1], s[2], knr


def _adapts(body: str, n: str, old: str, truth: str) -> bool:
    """tutruth's mechanical rewrite of a block written against `old` exists under `truth`."""
    try:
        return tutruth.adapt(body, n, old, truth, []) is not None
    except (IndexError, AttributeError, ValueError):
        return False


def _render(sig) -> str:
    return f"{sig[0]} ({'' if sig[3] else ', '.join(sig[2]) or 'void'})"


# ------------------------------------------------------------------ the tree
class Tree:
    """Every source file as (module, tu, prologue, blocks), normalised like tutruth does."""

    def __init__(self, p: Project):
        self.p = p
        self.files: Dict[str, dict] = {}   # tu source -> {module, prologue, blocks: {name: (body, flags)}}
        for u in p.load_units():
            if u.get("asm"):
                continue
            key = u.get("tu") or u["source"]
            if key in self.files:
                continue
            path = ROOT / "src" / key
            if not path.exists():
                continue
            if u.get("tu"):
                tf = tufile.load(p, key)
            else:
                tf = tufile.TuFile("", [tufile.Block(u["symbols"][0], path.read_text(errors="replace"), ["noprologue"])])
            pro = tutruth.split_multi(tutruth.join_declarations(tf.prologue))
            blocks = {}
            for b in tf.blocks:
                blocks[b.name] = (tutruth.split_multi(tutruth.join_declarations(b.body)), b.flags)
            self.files[key] = {"module": u["module"], "prologue": pro, "blocks": blocks, "is_tu": bool(u.get("tu"))}
        self.idents: Dict[Tuple[str, str], Counter] = {}
        for key, f in self.files.items():
            for bn, (body, _) in f["blocks"].items():
                self.idents[(key, bn)] = Counter(re.findall(r"[A-Za-z_]\w*", typesurvey.strip_comments(body)))
        self._hn: Dict[Tuple[str, ...], Tuple[Set[str], Set[str]]] = {}

    def gen_text(self, key: str, bn: str) -> str:
        f = self.files[key]
        body, flags = f["blocks"][bn]
        return body if "noprologue" in flags else f["prologue"] + "\n" + body

    def header_names(self, text: str) -> Set[str]:
        """Every name the text's includes declare, following `<...>` and `"..."` includes
        (SDK headers declare prototypes without `extern`): tutidy's shared include walk."""
        incs = tuple(sorted(set(tutidy.INCLUDE_RE.findall(text))))
        if incs not in self._hn:
            names: Set[str] = set()
            for h in tutidy.included_headers("\n".join(f'#include "{i}"' for i in incs)):
                names |= h.names
            self._hn[incs] = (names, set())
        return self._hn[incs][0]


def _header_decls(p: Project) -> Dict[str, List[Tuple[str, str, str]]]:
    """name -> [(scope module or '*', header path, line)] for every header declaration."""
    out: Dict[str, List[Tuple[str, str, str]]] = defaultdict(list)
    for h in tutidy.all_headers():
        m = re.match(r"rel/([^/]+)/", h.rel)
        scope = m.group(1) if m else "*"
        for n, ln in h.decls:
            out[n].append((scope, h.rel, ln))
    return out


def _macros() -> Set[str]:
    out: Set[str] = set()
    for path in list((ROOT / "include").rglob("*.h")) + list((ROOT / "src").rglob("*.c")):
        out |= set(re.findall(r"^\s*#\s*define\s+([A-Za-z_]\w*)\(", path.read_text(errors="replace"), re.M))
    return out


# ------------------------------------------------------------------ the checks
def _functions(p, tree: Tree, hdecls, survey, matched: Set[Tuple[str, str]]) -> List[dict]:
    rows: List[dict] = []
    defs: Dict[Tuple[str, str], Tuple[str, str, Tuple]] = {}   # (module, name) -> (tu, block, sig)
    decls: Dict[Tuple[str, str], List[Tuple[str, str, str]]] = defaultdict(list)  # -> [(tu, holder, line)]
    for key, f in tree.files.items():
        mod = f["module"]
        for ln in f["prologue"].splitlines():
            if tutidy.DECL_LINE_RE.match(ln) and (n := tutidy._decl_name(ln)) and _sig(ln):
                decls[(mod, n)].append((key, "(prologue)", ln.strip()))
        for bn, (body, _) in f["blocks"].items():
            for m in reconcile.DEF_RE.finditer(body):
                n = m.group(2)
                if n in KEYWORDS or n.startswith("fzgx_") or re.search(r"\bstatic\b", m.group(1)):
                    continue
                s = _sig("extern " + re.sub(r"\s+", " ", m.group(1)).strip() + ";")
                if s:
                    defs[(mod, n)] = (key, bn, s)
            for n, ln in reconcile._decls(body):
                if _sig(ln):
                    decls[(mod, n)].append((key, bn, ln))

    by_name: Dict[str, List[str]] = defaultdict(list)
    for (m2, n2) in decls:
        by_name[n2].append(m2)

    def scoped(mod: str, n: str):
        """Declarations of (mod, n): the module's own, plus every module's for a DOL symbol."""
        out = list(decls.get((mod, n), []))
        if mod == "main":
            for m2 in by_name.get(n, []):
                if m2 != "main" and n not in tree.p.symbols(m2):
                    out += decls[(m2, n)]
        hs = [(rel, ln) for sc, rel, ln in hdecls.get(n, []) if sc in (mod, "*") and _sig(ln)]
        return out, hs

    for (mod, n), (dkey, dblock, dsig) in sorted(defs.items()):
        if (mod, n) not in matched:
            continue
        path = "src/" + dkey
        others, hs = scoped(mod, n)
        bad: Dict[str, List[Tuple[str, str]]] = defaultdict(list)   # decl line -> [(tu, holder)]
        sev = None
        whys = {}
        def users_of(tu: str, holder: str) -> List[str]:
            f = tree.files[tu]
            if holder != "(prologue)":
                return [holder]
            return [bn for bn, (body, _) in f["blocks"].items()
                    if tree.idents[(tu, bn)].get(n) and not any(x == n for x, _ in reconcile._decls(body))
                    and not (tu == dkey and bn == dblock)]

        for tu, holder, ln in others:
            if tu == dkey and holder == dblock:
                continue
            s, why = _sig_severity(dsig, _sig(ln), survey, path)
            if s:
                if s == "code" and not any(tutruth.min_call_args(tree.files[tu]["blocks"][bn][0], n) is not None
                                           for bn in users_of(tu, holder)):
                    s, why = "cosmetic", why + " (address only, never called there)"
                bad[ln].append((tu, holder))
                whys[ln] = why if ln not in whys or "address only" in whys[ln] else whys[ln]
                sev = "code" if "code" in (sev, s) else s
        hbad = []
        for rel, ln in hs:
            s, why = _sig_severity(dsig, _sig(ln), survey, path)
            if s:
                hbad.append((rel, ln, why))
                sev = "code" if "code" in (sev, s) else s
        if not bad and not hbad:
            continue
        resolution = DECIDE if hbad else RESOLVES
        truth = hs[0][1] if hs else "extern " + _render_def(dsig, n)
        affected = []
        for ln, holders in bad.items():
            for tu, holder in holders:
                f = tree.files[tu]
                users = users_of(tu, holder)
                if not f["is_tu"]:
                    resolution = DECIDE  # one file per function: no TU pass rewrites it
                for bn in users:
                    affected.append(bn if tu == dkey else f"{tu}:{bn}")
                    if resolution == RESOLVES and not _adapts(f["blocks"][bn][0], n, ln, truth):
                        resolution = DECIDE
        parts = [f"definition {_render(dsig)} in {dblock}"]
        for rel, ln, why in hbad:
            parts.append(f"header {rel}: {why}")
        for ln, holders in sorted(bad.items(), key=lambda kv: -len(kv[1])):
            where = ", ".join(sorted({(h if t == dkey else f"{t.rsplit('/', 1)[-1]}:{h}") for t, h in holders}))
            parts.append(f"{whys[ln]} [{where}]")
        rows.append(_row("prototype", sev, resolution, mod, dkey, n, "; ".join(parts), blocks=affected))
    # unmatched functions: declarations that disagree with each other
    for (mod, n), lst in sorted(decls.items()):
        if (mod, n) in defs:
            continue
        sym = tree.p.symbols(mod).get(n)
        if not sym or sym.kind != "function":
            continue
        forms: Dict[str, List[Tuple[str, str, str]]] = defaultdict(list)
        for tu, holder, ln in lst:
            forms[_render(_sig(ln))].append((tu, holder, ln))
        hs = [(rel, ln) for sc, rel, ln in hdecls.get(n, []) if sc in (mod, "*") and _sig(ln)]
        ranked = sorted(forms.items(), key=lambda kv: -len(kv[1]))
        # the header's prototype is the truth when there is one, else the commonest spelling
        base = _sig(hs[0][1]) if hs else _sig(ranked[0][1][0][2])
        sev = None
        bad = []
        for form, holders in ranked:
            s, _ = _sig_severity(base, _sig(holders[0][2]), survey, "src/" + holders[0][0])
            if s:
                bad.append(form)
                sev = "code" if "code" in (sev, s) else s
        if not sev:
            continue
        tus = Counter(tu for _, hs_ in ranked for tu, _, _ in hs_)
        tu = tus.most_common(1)[0][0]
        if hs:
            # tutruth makes the header the truth in every TU that includes it and casts the rest
            resolution = RESOLVES if all(tree.files[t_]["is_tu"] for t_ in tus) and all(
                _adapts(tree.files[t_]["blocks"][h][0], n, ln, hs[0][1])
                for f_ in bad for t_, h, ln in forms[f_] if h != "(prologue)") else DECIDE
        else:
            resolution = RESOLVES if len(tus) == 1 and tree.files[tu]["is_tu"] else DECIDE
        affected = [h if t_ == tu else f"{t_}:{h}" for f_ in bad for t_, h, _ in forms[f_]]
        detail = (f"header {hs[0][0]}: {_render(base)}; " if hs else "") + "; ".join(
            f"{form} x{len(hs_)} [{', '.join(sorted({(h if t_ == tu else t_.rsplit('/', 1)[-1] + ':' + h) for t_, h, _ in hs_})[:6])}]"
            for form, hs_ in ranked if not hs or form in bad)
        if len(tus) > 1 and not hs:
            detail += f" (declared in {len(tus)} TUs: a header prototype settles it)"
        rows.append(_row("declaration", sev, resolution, mod, tu, n, detail, blocks=affected))
    return rows


def _render_def(sig, n) -> str:
    return f"{sig[0]} {n}({', '.join(sig[2]) or 'void'});"


DATA_DECL_RE = re.compile(r"^\s*extern\s+(?P<t>[^;=(){}]*?)\s*\b(?P<n>[A-Za-z_]\w*)\s*(?P<d>(?:\[[^\]]*\])*)\s*;")
DATA_DEF_RE = re.compile(r"^(?!extern\b|static\b|typedef\b|return\b)(?P<t>[A-Za-z_][\w \t\*]*?)\s*\b(?P<n>(?:lbl|fzgx_obj)_\w+|[A-Za-z_]\w*)\s*(?P<d>(?:\[[^\]]*\])*)\s*(?:=|;)", re.M)


CAST_VIEW_RE = re.compile(r"\(\s*(?P<t>(?:struct\s+)?[A-Za-z_]\w*)\s*\*\s*\)\s*&\s*(?P<n>[A-Za-z_]\w*)\b(?!\s*[\[.])")


def _dims(d: str) -> Optional[List[Optional[int]]]:
    out = []
    for x in re.findall(r"\[([^\]]*)\]", d):
        x = x.strip()
        if not x:
            out.append(None)
            continue
        try:
            out.append(int(x, 0))
        except ValueError:
            return None
    return out


def _size(t: str, dims, survey, path) -> Optional[int]:
    c = _clean(t)
    if c.endswith("*"):
        el = 4
    else:
        info = survey.type_info(c, path)
        if not info:
            return None
        el = info[0]
    for d in dims or []:
        if d is None:
            return None
        el *= d
    return el


def _data(p, tree: Tree, hdecls, survey) -> List[dict]:
    rows: List[dict] = []
    for key, f in sorted(tree.files.items()):
        mod = f["module"]
        syms = p.symbols(mod)
        path = "src/" + key
        forms: Dict[str, Dict[str, Tuple[str, Optional[int], List[str]]]] = defaultdict(dict)  # name -> norm -> (text, size, holders)

        def add(n, t, d, holder):
            sym = syms.get(n) or (syms.get(n[len("fzgx_obj_"):]) if n.startswith("fzgx_obj_") else None)
            if not sym or sym.kind == "function":
                return
            dims = _dims(d)
            if dims is None:
                return
            norm = _clean(t) + "".join(f"[{x if x is not None else ''}]" for x in dims)
            size = _size(t, dims, survey, path)
            text, sz, holders = forms[n].get(norm, (norm, size, []))
            holders.append(holder)
            forms[n][norm] = (text, size, holders)

        for ln in f["prologue"].splitlines():
            m = DATA_DECL_RE.match(ln)
            if m:
                add(m["n"], m["t"], m["d"], "(prologue)")
        visible: Set[str] = set()
        casts: Dict[str, Dict[str, List[str]]] = defaultdict(dict)   # name -> cast type -> blocks
        for bn, (body, _) in f["blocks"].items():
            visible |= tree.header_names(tree.gen_text(key, bn))
            for ln in body.splitlines():
                m = DATA_DECL_RE.match(ln)
                if m:
                    add(m["n"], m["t"], m["d"], bn)
            for m in DATA_DEF_RE.finditer(body):
                if m["n"] in syms and "(" not in m["t"]:
                    add(m["n"], m["t"], m["d"], bn + " (definition)")
            for m in CAST_VIEW_RE.finditer(body):
                if m["n"] in syms and syms[m["n"]].kind != "function":
                    casts[m["n"]].setdefault(_clean(m["t"]), []).append(bn)
        for n in list(forms):
            for sc, rel, ln in hdecls.get(n, []):
                if sc in (mod, "*") and n in visible:
                    m = DATA_DECL_RE.match(ln)
                    if m and m["n"] == n:
                        add(n, m["t"], m["d"], f"header {rel}")
        declared = {n: max((v[1] or 0) for v in fs.values()) for n, fs in forms.items()}
        by_addr = sorted(((s.section, s.addr, s.name) for s in syms.values() if s.name in declared), key=lambda x: (x[0], x[1]))
        for n, fs in sorted(forms.items()):
            sym = syms.get(n) or syms.get(n[len("fzgx_obj_"):])
            # `T x[]` agrees with any `T x[N]`
            items = list(fs.values())
            distinct = []
            for text, size, holders in items:
                if any(re.sub(r"\[\d*\]", "", t2) == re.sub(r"\[\d*\]", "", text) and ("[]" in text or "[]" in t2) for t2, _, _ in distinct):
                    continue
                distinct.append((text, size, holders))
            blocks = sorted({h.split(" ")[0] for _, _, hs in items for h in hs if not h.startswith(("header", "(prologue)"))})
            if len(distinct) > 1:
                sizes = {s for _, s, _ in distinct}
                hdr = [x for x in distinct if any(h.startswith("header") for h in x[2])]
                truth = hdr[0] if hdr else max(distinct, key=lambda x: len(x[2]))
                larger = [x for x in distinct if x[1] and truth[1] and x[1] > truth[1]]
                sev = "code" if len(sizes) > 1 or None in sizes else "cosmetic"
                # tutruth: the header's (else the commonest) spelling, other users through views;
                # a view larger than its truth schedules differently and needs the real size
                resolution = DECIDE if larger else RESOLVES
                detail = "; ".join(f"{t} ({'0x%X' % s if s else '?'} bytes) [{', '.join(sorted(set(hs))[:6])}]" for t, s, hs in
                                   sorted(distinct, key=lambda x: -len(x[2])))
                if sym:
                    detail += f"; dtk size 0x{sym.size:X}"
                if larger:
                    detail += "; a view is larger than the truth (the real size must reach the header)"
                rows.append(_row("data", sev, resolution, mod, key, n, detail, blocks=blocks))
            # a declaration larger than its retail symbol that covers another declared object
            if sym and sym.size:
                big = [(t, s, hs) for t, s, hs in items if s and s > sym.size]
                for t, s, hs in big:
                    covered = [nm for sec, a, nm in by_addr if sec == sym.section and sym.addr < a < sym.addr + s and nm != n]
                    if covered:
                        rows.append(_row("overlap", "code", DECIDE, mod, key, n,
                                         f"{t} is 0x{s:X} bytes over dtk size 0x{sym.size:X} [{', '.join(sorted(set(hs))[:6])}]; "
                                         f"covers {', '.join(covered[:6])} declared in this TU",
                                         blocks=[h.split(' ')[0] for h in hs if not h.startswith(('header', '(prologue)'))]))
        # `(T *)&sym` views wider than the object every declaration and dtk give it
        for n, views in sorted(casts.items()):
            sym = syms[n]
            known = max([sym.size] + [s or 0 for _, s, _ in forms.get(n, {}).values()])
            for ct, bns in sorted(views.items()):
                s = _size(ct, [], survey, path)
                if not s or not known or s <= known:
                    continue
                covered = [nm for sec, a, nm in by_addr if sec == sym.section and sym.addr < a < sym.addr + s and nm != n]
                rows.append(_row("overlap" if covered else "data", "code", DECIDE, mod, key, n,
                                 f"cast view ({ct} *)&{n} is 0x{s:X} bytes, the object 0x{known:X} (dtk 0x{sym.size:X}) "
                                 f"[{', '.join(sorted(set(bns))[:6])}]" + (f"; covers {', '.join(covered[:6])} declared in this TU" if covered else
                                                                         "; the header layout or the view must change"),
                                 blocks=bns))
    return rows


def _hygiene(p, tree: Tree, hdecls, matched) -> List[dict]:
    rows: List[dict] = []
    macros = _macros()
    dol = p.symbols("main")
    for key, f in sorted(tree.files.items()):
        mod = f["module"]
        syms = p.symbols(mod)
        tu_decls = set()
        for ln in f["prologue"].splitlines():
            if tutidy.DECL_LINE_RE.match(ln) and (n := tutidy._decl_name(ln)):
                tu_decls.add(n)
        for bn, (body, _) in f["blocks"].items():
            tu_decls |= {n for n, _ in reconcile._decls(body)}
            tu_decls |= {m.group(2) for m in reconcile.DEF_RE.finditer(body)}
        for bn, (body, _) in f["blocks"].items():
            idents = tree.idents[(key, bn)]
            for m in reconcile.DEF_RE.finditer(body):
                n = m.group(2)
                if re.search(r"\bstatic\b", m.group(1)) and idents.get(n, 0) <= 1 and not n.startswith("fzgx_"):
                    rows.append(_row("unused_helper", "cosmetic", DECIDE, mod, key, n,
                                     f"`{re.sub(chr(10), ' ', m.group(1)).strip()}` in {bn} is never referenced", blocks=[bn]))
            text = tree.gen_text(key, bn)
            known = tree.header_names(text) | macros
            known |= {n for n, _ in reconcile._decls(text)}
            known |= set(re.findall(r"\b([A-Za-z_]\w*)\s*\([^;{}()]*\)\s*\{", text))  # definitions, __declspec too
            known |= set(re.findall(r"\(\s*\*\s*([A-Za-z_]\w*)", text))  # function-pointer objects, `T (*f(...))(...)`
            missing = []
            for m in re.finditer(r"(?<![\w.>])([A-Za-z_]\w*)\s*\(", typesurvey.strip_comments(body)):
                n = m.group(1)
                if n in known or n in KEYWORDS or n in missing:
                    continue
                s = syms.get(n) or dol.get(n)
                if s and s.kind == "function":
                    missing.append(n)
            for n in missing:
                rows.append(_row("implicit_call", "code", RESOLVES if n in tu_decls and f["is_tu"] else DECIDE, mod, key, n,
                                 f"{bn} calls {n} with no declaration in its unit (implicit `int {n}()`: "
                                 f"float arguments widen to double, the result is int)"
                                 + ("; another block of this TU declares it" if n in tu_decls else ""), blocks=[bn]))
    # matched definitions that unmatched callers in other TUs need, with no header prototype
    defs: Dict[Tuple[str, str], str] = {}
    for key, f in tree.files.items():
        for bn, (body, _) in f["blocks"].items():
            for m in reconcile.DEF_RE.finditer(body):
                if not re.search(r"\bstatic\b", m.group(1)):
                    defs[(f["module"], m.group(2))] = key
    for mod in p.modules:
        tus = p.tu_map(mod)
        try:
            fns = p.function_asm(mod)
        except Exception:
            continue
        callers: Dict[str, List[str]] = defaultdict(list)
        for fn in fns.values():
            if (mod, fn.symbol.name) in matched:
                continue
            for r in fn.refs:
                callers[r].append(fn.symbol.name)
        for name, cl in callers.items():
            key = defs.get((mod, name))
            if not key or (mod, name) not in matched:
                continue
            stem = key.rsplit("/", 1)[-1].rsplit(".", 1)[0]
            other = [c for c in cl if tus.get(c) != stem or not tus.get(c)]
            if not other or any(sc in (mod, "*") for sc, _, _ in hdecls.get(name, [])):
                continue
            rows.append(_row("no_header", "cosmetic", DECIDE, mod, key, name,
                             f"{len(other)} unmatched callers in other TUs ({', '.join(sorted(other)[:5])}) and no header prototype",
                             blocks=sorted(other)))
    return rows


def _struct_views() -> List[dict]:
    rows = []
    result = typesurvey.Survey().run()
    for c in result["clusters"]:
        private = [m for m in c["members"] if ":" in m]
        if len(private) < 2:
            continue
        files = Counter(m.split(":", 1)[0] for m in private)
        tu = files.most_common(1)[0][0]
        tu = tu[len("src/"):] if tu.startswith("src/") else tu
        mm = re.match(r"(?:rel/([^/]+)|dol)/", tu)
        mod = mm.group(1) if mm and mm.group(1) else "main"
        anchor = f" anchored by {', '.join(c['anchors'][:2])}" if c["anchors"] else ""
        rows.append(_row("struct_views", "cosmetic", DECIDE, mod, tu, f"type-survey #{c['id']}",
                         f"{len(private)} private struct views of one object (>=0x{c['min_size']:X} bytes, "
                         f"{len(c['conflicts'])} field conflicts){anchor}: {', '.join(m.split(':', 1)[1] for m in private[:6])}"
                         f"; `fzgx type-survey --emit {c['id']}`",
                         source="type-survey", blocks=c["functions"]))
    return rows


def _notes(p, tree: Tree) -> List[dict]:
    rows = []
    where: Dict[str, Tuple[str, str]] = {}
    for key, f in tree.files.items():
        for bn in f["blocks"]:
            where.setdefault(bn, (f["module"], key))

    def locate(sym: Optional[str]) -> Tuple[str, str]:
        if sym and sym in where:
            return where[sym]
        s = p.resolve(sym) if sym else None
        if s:
            stem = p.tu_map(s.module).get(s.name)
            return s.module, (f"{p.module_src_prefix(s.module)}/{stem}.c" if stem else "")
        return "", ""

    db_path = STATE_DIR / "ledger.db"
    if db_path.exists():
        db = sqlite3.connect(f"file:{db_path.as_posix()}?mode=ro", uri=True)
        seen = set()
        for sym, outcome, notes, ended in db.execute(
                "select symbol, outcome, notes, ended from attempts where notes is not null order by id desc"):
            if not notes or not NOTE_RE.search(notes):
                continue
            for sent in re.split(r"(?<=[.;])\s+", notes):
                if not NOTE_RE.search(sent) or re.search(r"\b(loop|pre|block)[- ]?header\b", sent, re.I):
                    continue
                sent = sent.strip()[:300]
                if (sym, sent) in seen:
                    continue
                seen.add((sym, sent))
                mod, tu = locate(sym)
                rows.append(_row("note", "note", DECIDE, mod, tu, sym, f"{outcome}: {sent}", source="ledger", blocks=[sym]))
    waves = STATE_DIR / "reports" / "waves.md"
    if waves.exists():
        for i, ln in enumerate(waves.read_text(errors="replace").splitlines(), 1):
            if "ibrarian" not in ln:
                continue
            syms = [s for s in SYM_RE.findall(ln) if s.startswith(("fn_", "lbl_")) or s in where]
            mod, tu = locate(syms[0] if syms else None)
            rows.append(_row("note", "note", DECIDE, mod, tu, syms[0] if syms else "", ln.strip()[:400],
                             source=f"waves.md:{i}", blocks=syms))
    return rows


def queue(p: Project, module: Optional[str] = None, tu: Optional[str] = None, notes: bool = True,
          survey_views: bool = True) -> List[dict]:
    tree = Tree(p)
    if module:
        tree.files = {k: v for k, v in tree.files.items() if v["module"] == module} if not tu else tree.files
    db = sqlite3.connect(f"file:{(STATE_DIR / 'ledger.db').as_posix()}?mode=ro", uri=True)
    matched = {(m, s) for s, m in db.execute("select symbol, module from functions where status = 'matched'")}
    hdecls = _header_decls(p)
    survey = typesurvey.Survey()
    survey.scan()
    rows = _functions(p, tree, hdecls, survey, matched) + _data(p, tree, hdecls, survey) + _hygiene(p, tree, hdecls, matched)
    if survey_views:
        rows += _struct_views()
    if notes:
        rows += _notes(p, tree)
    if module:
        rows = [r for r in rows if r["module"] == module]
    if tu:
        t = tu if tu.endswith(".c") else tu + ".c"
        rows = [r for r in rows if r["tu"] == t or r["tu"].endswith("/" + t)]
    # cross-reference: a note about a symbol that a mechanical row also reports
    mech = {r["symbol"] for r in rows if r["source"] == "tree"}
    for r in rows:
        if r["kind"] == "note" and any(s in mech for s in r["blocks"]):
            r["detail"] += "  (also found mechanically)"
    rank = {"code": 0, "cosmetic": 1, "note": 2}
    rows.sort(key=lambda r: (r["module"], r["tu"], rank.get(r["severity"], 3), -len(r["blocks"]), r["kind"], r["symbol"]))
    return rows


def summary(rows: List[dict], limit: int = 0) -> str:
    out = []
    kinds = sorted({r["kind"] for r in rows})
    per_mod: Dict[str, Counter] = defaultdict(Counter)
    for r in rows:
        per_mod[r["module"] or "?"][r["kind"]] += 1
    out.append("module".ljust(14) + "".join(k[:13].rjust(14) for k in kinds) + "total".rjust(8))
    for m in sorted(per_mod):
        c = per_mod[m]
        out.append(m.ljust(14) + "".join(str(c[k]).rjust(14) for k in kinds) + str(sum(c.values())).rjust(8))
    tot = Counter(r["kind"] for r in rows)
    out.append("total".ljust(14) + "".join(str(tot[k]).rjust(14) for k in kinds) + str(len(rows)).rjust(8))
    res = Counter((r["severity"], r["resolution"]) for r in rows if r["kind"] != "note")
    out.append("  " + ", ".join(f"{s}/{rs}: {n}" for (s, rs), n in sorted(res.items())))
    out.append("")
    groups: Dict[Tuple[str, str], List[dict]] = defaultdict(list)
    for r in rows:
        groups[(r["module"] or "?", r["tu"] or "?")].append(r)
    order = sorted(groups, key=lambda g: (g[0], -sum(len(r["blocks"]) for r in groups[g] if r["severity"] == "code"), g[1]))
    shown = 0
    for g in order:
        out.append(f"== {g[0]}  {g[1]}  ({len(groups[g])})")
        for r in groups[g]:
            if limit and shown >= limit:
                break
            flag = "T" if r["resolution"] == RESOLVES else "D"
            out.append(f"  [{r['severity'][:4]:4} {flag}] {r['kind']:<13} {r['symbol']:<22} ({len(r['blocks'])}) {r['detail']}"
                       + (f"  <{r['source']}>" if r["source"] != "tree" else ""))
            shown += 1
    out.append("")
    out.append("T = tutruth resolves (header > matched definition > prologue > most common; oracle re-checks), D = needs a decision")
    return "\n".join(out)
