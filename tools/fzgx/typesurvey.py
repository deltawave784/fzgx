"""Type survey: group the per-function struct views of one object into candidate shared types.

Matchers declare a private struct per function (`Fn184124Object`: padding up to the one
field the function touches). Each is a verified partial view of some real object. This
pass lays every such struct out the way MWCC does, then links views that describe the
same object:

  flow     a function passes its own struct-pointer parameter, unchanged, to another
           function's struct-pointer parameter: both views are of the same pointer.
  overlap  two views agree on rare fields (offset, size, kind), weighted by rarity,
           and disagree on none.

A cluster's merged field table is a lead for the librarian, never an automatic rewrite:
same-offset disagreements are reported (unions, sub-field byte access, or a mis-grouped
view), and every promotion into include/ still has to pass the 16-target hash check.

  fzgx type-survey                 summary of the largest clusters
  fzgx type-survey --emit ID       proposed merged struct for one cluster
"""

from __future__ import annotations

import json
import math
import re
from collections import Counter, defaultdict
from dataclasses import dataclass, field
from pathlib import Path
from typing import Dict, List, Optional, Set, Tuple

from .project import ROOT, STATE_DIR

PRIMS = {
    "u8": 1, "s8": 1, "char": 1, "signed char": 1, "unsigned char": 1, "uchar": 1, "bool": 1,
    "u16": 2, "s16": 2, "short": 2, "unsigned short": 2, "signed short": 2, "vu16": 2,
    "u32": 4, "s32": 4, "int": 4, "unsigned int": 4, "unsigned": 4, "long": 4, "unsigned long": 4,
    "signed long": 4, "BOOL": 4, "size_t": 4, "vu32": 4, "vs32": 4, "enum": 4,
    "f32": 4, "float": 4,
    "u64": 8, "s64": 8, "long long": 8, "unsigned long long": 8, "f64": 8, "double": 8,
}
FLOATS = {"f32", "float", "f64", "double"}
PAD_NAME = re.compile(r"^_?(pad|unk|filler|gap|_)\w*$|^_+$")
GENERIC_NAME = re.compile(r"^(_?pad\w*|unk_?\w*|field_?\w*|value(_?\w+)?|_+\w*)$")
OFFSET_IN_NAME = re.compile(r"^(?:unk|field|value)_?(?:0x)?([0-9A-Fa-f]+)$")
QUALIFIERS = re.compile(r"\b(const|volatile|register|static|extern|inline)\b")


def strip_comments(text: str) -> str:
    text = re.sub(r"/\*.*?\*/", lambda m: re.sub(r"[^\n]", " ", m.group(0)), text, flags=re.S)
    return re.sub(r"//[^\n]*", "", text)


def match_brace(text: str, i: int) -> int:
    """Index just past the brace closing the one at text[i]."""
    depth = 0
    for j in range(i, len(text)):
        c = text[j]
        if c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                return j + 1
    return len(text)


def split_top(text: str, sep: str) -> List[str]:
    out, depth, cur = [], 0, []
    for c in text:
        if c in "({[":
            depth += 1
        elif c in ")}]":
            depth -= 1
        if c == sep and depth == 0:
            out.append("".join(cur)); cur = []
        else:
            cur.append(c)
    out.append("".join(cur))
    return [s.strip() for s in out if s.strip()]


@dataclass
class Field:
    offset: int
    size: int
    kind: str          # "i" int, "f" float, "p" pointer
    name: str
    ctype: str

    @property
    def key(self) -> Tuple[int, int, str]:
        return (self.offset, self.size, self.kind)


@dataclass
class Layout:
    size: int = 0
    align: int = 1
    fields: List[Field] = field(default_factory=list)
    complete: bool = True   # False once an unknown type stops offset computation


@dataclass
class StructDef:
    name: str
    path: str
    body: str
    is_union: bool
    shared: bool                       # declared under include/
    layout: Optional[Layout] = None
    users: Set[str] = field(default_factory=set)

    @property
    def ident(self) -> str:
        return self.name if self.shared else f"{self.path}:{self.name}"


class Survey:
    def __init__(self, root: Path = ROOT):
        self.root = root
        self.structs: Dict[str, StructDef] = {}        # ident -> def
        self.by_name: Dict[Tuple[str, str], str] = {}  # (path or "", name) -> ident
        self.aliases: Dict[str, str] = {}              # typedef alias -> target type text
        self.arrays: Dict[str, Tuple[str, int]] = {}   # typedef T Name[n] -> (T, count)
        self.functions: Dict[str, dict] = {}           # name -> {path, params, calls}

    # ---------- parsing ----------

    def scan(self) -> None:
        files = sorted((self.root / "include").rglob("*.h")) + sorted((self.root / "src").rglob("*.c")) \
            + sorted((self.root / "src").rglob("*.h"))
        for path in files:
            rel = path.relative_to(self.root).as_posix()
            text = strip_comments(path.read_text(errors="replace"))
            self._scan_types(rel, text, shared=rel.startswith("include/"))
        for path in sorted((self.root / "src").rglob("*.c")):
            rel = path.relative_to(self.root).as_posix()
            self._scan_functions(rel, strip_comments(path.read_text(errors="replace")))

    TYPE_START = re.compile(r"\b(typedef\s+)?(struct|union)\s*(\w+)?\s*\{")
    ALIAS = re.compile(r"^\s*typedef\s+([^;{}()]+?)\s+(\**)\s*(\w+)\s*((?:\[[^\]]+\])*)\s*;", re.M)

    def _scan_types(self, rel: str, text: str, shared: bool) -> None:
        for m in self.ALIAS.finditer(text):
            base, stars, name, dims = m.group(1).strip(), m.group(2), m.group(3), m.group(4)
            if base.startswith(("struct ", "union ", "enum ")) and not stars and not dims:
                base = base.split()[1] if not base.startswith("enum") else "enum"
            if stars:
                self.aliases[name] = "void *"
            elif dims:
                count = 1
                for d in re.findall(r"\[([^\]]+)\]", dims):
                    count *= _int(d) or 0
                self.arrays[name] = (base, count)
            else:
                self.aliases.setdefault(name, base)
        i = 0
        while True:
            m = self.TYPE_START.search(text, i)
            if not m:
                break
            # only top-level definitions; nested ones are laid out inline by their parent
            if text.count("{", 0, m.start()) != text.count("}", 0, m.start()):
                i = m.end(); continue
            end = match_brace(text, m.end() - 1)
            body = text[m.end():end - 1]
            tail = re.match(r"\s*(\**)\s*(\w+)?", text[end:])
            tag = m.group(3)
            name = tag
            if m.group(1) and tail and tail.group(2) and not tail.group(1):
                name = tail.group(2)
                if tag:
                    self.aliases.setdefault(tag, name)
            if name:
                sd = StructDef(name, rel, body, m.group(2) == "union", shared)
                key = ("" if shared else rel, name)
                if key not in self.by_name:
                    self.by_name[key] = sd.ident
                    self.structs[sd.ident] = sd
            i = end

    FUNC = re.compile(r"^[A-Za-z_][\w \t\*]*?\b(\w+)\s*\(([^;{}()]*(?:\([^()]*\)[^;{}()]*)*)\)\s*\{", re.M)
    CALL = re.compile(r"\b([A-Za-z_]\w*)\s*\(")

    def _scan_functions(self, rel: str, text: str) -> None:
        for m in self.FUNC.finditer(text):
            name = m.group(1)
            if name in ("if", "while", "for", "switch", "return", "sizeof"):
                continue
            end = match_brace(text, m.end() - 1)
            params = []
            for p in split_top(m.group(2), ","):
                pm = re.match(r"^(.*?)(\**)\s*(\w+)\s*$", QUALIFIERS.sub("", p).strip())
                if not pm or p.strip() == "void":
                    params.append(None); continue
                base = pm.group(1).strip().replace("struct ", "").strip()
                params.append({"name": pm.group(3), "type": base, "ptr": len(pm.group(2))})
            body = text[m.end():end - 1]
            calls = []
            for c in self.CALL.finditer(body):
                close = _match_paren(body, c.end() - 1)
                calls.append((c.group(1), [a.strip() for a in split_top(body[c.end():close - 1], ",")]))
            self.functions.setdefault(name, {"path": rel, "params": params, "calls": calls})

    # ---------- layout ----------

    def resolve(self, typename: str, path: str) -> Optional[str]:
        """Struct ident for a type name seen in `path`, following typedef aliases."""
        seen = set()
        while typename not in seen:
            seen.add(typename)
            for key in ((path, typename), ("", typename)):
                if key in self.by_name:
                    return self.by_name[key]
            typename = self.aliases.get(typename, "")
            if not typename:
                return None
        return None

    def type_info(self, ctype: str, path: str, depth: int = 0) -> Optional[Tuple[int, int, str, Optional[Layout]]]:
        """(size, align, kind, nested layout) or None when unknown."""
        ctype = QUALIFIERS.sub("", ctype).replace("struct ", "").replace("union ", "").strip()
        ctype = re.sub(r"\s+", " ", ctype)
        if ctype.startswith("enum"):
            return (4, 4, "i", None)
        if ctype in PRIMS:
            return (PRIMS[ctype], PRIMS[ctype], "f" if ctype in FLOATS else "i", None)
        if ctype in self.arrays:
            base, count = self.arrays[ctype]
            info = self.type_info(base, path, depth + 1)
            if info is None or not count:
                return None
            return (info[0] * count, info[1], info[2], None)
        ident = self.resolve(ctype, path)
        if ident and depth < 16:
            lay = self.layout(self.structs[ident], depth + 1)
            if lay.complete:
                return (lay.size, lay.align, "s", lay)
            return None
        alias = self.aliases.get(ctype)
        if alias and alias != ctype and depth < 16:
            if alias == "void *":
                return (4, 4, "p", None)
            return self.type_info(alias, path, depth + 1)
        return None

    def layout(self, sd: StructDef, depth: int = 0) -> Layout:
        if sd.layout is None:
            sd.layout = Layout(complete=False)   # recursion guard
            sd.layout = self._layout_body(sd.body, sd.path, sd.is_union, depth)
        return sd.layout

    def _layout_body(self, body: str, path: str, is_union: bool, depth: int) -> Layout:
        lay = Layout()
        off = 0
        bit_unit = None  # (offset, size, bits used) of an open bitfield storage unit
        for decl in split_top(body, ";"):
            decl = QUALIFIERS.sub("", decl).strip()
            if not decl or decl.startswith("#"):
                continue
            nested = re.match(r"^(struct|union)\s*\w*\s*\{", decl)
            if nested:
                close = match_brace(decl, decl.index("{"))
                inner = self._layout_body(decl[decl.index("{") + 1:close - 1], path, nested.group(1) == "union", depth + 1)
                if not inner.complete:
                    lay.complete = False; break
                items = [(d, inner.size, inner.align, "s", inner, d) for d in split_top(decl[close:], ",")] or \
                        [("", inner.size, inner.align, "s", inner, "")]
            elif "(*" in decl:
                fn = re.search(r"\(\s*\*\s*(\w+)", decl)
                items = [(fn.group(1) if fn else "", 4, 4, "p", None, "fnptr")]
            else:
                m = re.match(r"^((?:unsigned |signed )?(?:long long|[A-Za-z_]\w*))\s+(.*)$", decl, re.S)
                if not m:
                    lay.complete = False; break
                base, rest = m.group(1), m.group(2)
                items = []
                for d in split_top(rest, ","):
                    items.append((d, None, None, None, None, base))
            for raw, size, align, kind, inner, ctype in items:
                dm = re.match(r"^(\**)\s*(\w*)\s*((?:\[[^\]]*\])*)\s*(?::\s*(\w+))?$", raw.strip())
                if not dm:
                    lay.complete = False; break
                stars, name, dims, bits = dm.group(1), dm.group(2), dm.group(3), dm.group(4)
                if stars:
                    size, align, kind, inner = 4, 4, "p", None
                elif size is None:
                    info = self.type_info(ctype, path, depth)
                    if info is None:
                        lay.complete = False; break
                    size, align, kind, inner = info
                count = 1
                for d in re.findall(r"\[([^\]]*)\]", dims):
                    n = _int(d)
                    if n is None:
                        lay.complete = False; break
                    count *= n
                if not lay.complete:
                    break
                if bits is not None:
                    width = _int(bits) or 0
                    if bit_unit and bit_unit[1] == size and bit_unit[2] + width <= size * 8:
                        bit_unit = (bit_unit[0], size, bit_unit[2] + width)
                        continue
                    off = _align(off, align) if not is_union else 0
                    bit_unit = (off, size, width)
                    lay.fields.append(Field(off, size, "i", name, ctype + ":bits"))
                    off += size
                    lay.align = max(lay.align, align)
                    lay.size = max(lay.size, off)
                    continue
                bit_unit = None
                at = 0 if is_union else _align(off, align)
                total = size * count
                is_pad = size == 1 and count > 1 and PAD_NAME.match(name or "_")
                if not is_pad:
                    if kind == "s" and inner is not None:
                        for k in range(min(count, 64)):
                            for f in inner.fields:
                                lay.fields.append(Field(at + k * size + f.offset, f.size, f.kind,
                                                        f"{name}.{f.name}" if count == 1 else f"{name}[{k}].{f.name}", f.ctype))
                    else:
                        for k in range(min(count, 64)):
                            lay.fields.append(Field(at + k * size, size, kind,
                                                    name if count == 1 else f"{name}[{k}]", ctype if not stars else ctype + " *"))
                lay.align = max(lay.align, align)
                off = at + total
                lay.size = max(lay.size, off)
            if not lay.complete:
                break
        lay.size = _align(lay.size, lay.align)
        return lay

    # ---------- grouping ----------

    def attach_users(self) -> None:
        for fname, fn in self.functions.items():
            for p in fn["params"]:
                if p and p["ptr"] == 1:
                    ident = self.resolve(p["type"], fn["path"])
                    if ident:
                        self.structs[ident].users.add(fname)

    def flow_edges(self) -> List[Tuple[str, str, str]]:
        edges = []
        for fname, fn in self.functions.items():
            mine = {p["name"]: self.resolve(p["type"], fn["path"]) for p in fn["params"] if p and p["ptr"] == 1}
            mine = {k: v for k, v in mine.items() if v}
            if not mine:
                continue
            for callee, args in fn["calls"]:
                target = self.functions.get(callee)
                if not target:
                    continue
                for i, a in enumerate(args):
                    a = re.sub(r"^\(\s*[\w\s]+\*\s*\)\s*", "", a)   # a bare cast keeps the pointer
                    if a in mine and i < len(target["params"]) and target["params"][i] and target["params"][i]["ptr"] == 1:
                        other = self.resolve(target["params"][i]["type"], target["path"])
                        if other and other != mine[a]:
                            edges.append((mine[a], other, f"{fname}->{callee}#{i}"))
        return edges

    def run(self, min_shared_weight: float = 6.0) -> dict:
        self.scan()
        for sd in self.structs.values():
            self.layout(sd)
        self.attach_users()
        views = {i: sd for i, sd in self.structs.items() if sd.layout and sd.layout.fields}
        df = Counter()
        for sd in views.values():
            for k in {f.key for f in sd.layout.fields}:
                df[k] += 1
        n = max(1, len(views))
        idf = {k: math.log(n / c) for k, c in df.items()}

        # Union-find whose roots carry the cluster's merged field table, so a merge is checked
        # against everything already in the cluster: pairwise checks alone let A~B and B~C
        # chain A and C together however much they disagree.
        parent = {i: i for i in views}
        table = {i: {f.offset: (f.size, f.kind) for f in sd.layout.fields} for i, sd in views.items()}
        anchored = {i: sd.shared for i, sd in views.items()}

        def find(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x

        def clash(ra: str, rb: str) -> List[int]:
            ta, tb = table[ra], table[rb]
            if len(ta) > len(tb):
                ta, tb = tb, ta
            return sorted(o for o, shape in ta.items() if o in tb and tb[o] != shape)

        def union(a: str, b: str) -> List[int]:
            ra, rb = find(a), find(b)
            if ra == rb:
                return []
            if anchored[ra] and anchored[rb]:
                return [-1]   # two shared types are two types; never merge them
            c = clash(ra, rb)
            if c:
                return c
            parent[ra] = rb
            table[rb].update(table.pop(ra))
            anchored[rb] = anchored[rb] or anchored.pop(ra)
            return []

        links = []
        for a, b, why in self.flow_edges():
            if a in views and b in views:
                c = union(a, b)
                links.append({"a": a, "b": b, "via": "flow", "why": why, "merged": not c,
                              "conflicts": [f"0x{o:X}" for o in c if o >= 0]})
        # overlap edges through an inverted index of rare features; shared (include/) types
        # anchor clusters but are never merged with each other
        index = defaultdict(list)
        for i, sd in views.items():
            for k in {f.key for f in sd.layout.fields}:
                if df[k] <= 40 and k[0] >= 0x10:
                    index[k].append(i)
        pair_weight = Counter()
        for k, members in index.items():
            for x in range(len(members)):
                for y in range(x + 1, len(members)):
                    pair_weight[(members[x], members[y])] += idf[k]
        def module(sd: StructDef) -> Optional[str]:
            parts = sd.path.split("/")
            return None if sd.shared else ("/".join(parts[1:3]) if parts[1] == "rel" else parts[1])

        for (a, b), w in sorted(pair_weight.items(), key=lambda kv: -kv[1]):
            if w < min_shared_weight:
                continue
            ma, mb = module(views[a]), module(views[b])
            if ma and mb and ma != mb:
                continue   # coincidental layouts across modules; only flow evidence crosses them
            if not union(a, b):
                links.append({"a": a, "b": b, "via": "overlap", "weight": round(w, 1), "merged": True})

        groups = defaultdict(list)
        for i in views:
            groups[find(i)].append(i)
        clusters = []
        for members in groups.values():
            if len(members) < 2:
                continue
            fields = defaultdict(lambda: {"shapes": Counter(), "names": Counter()})
            users = set()
            for i in members:
                users |= views[i].users
                for f in views[i].layout.fields:
                    slot = fields[f.offset]
                    slot["shapes"][f"{f.size}{f.kind}"] += 1
                    leaf = f.name.split(".")[-1]
                    if leaf and not GENERIC_NAME.match(leaf):
                        slot["names"][leaf] += 1
            shared = sorted(i for i in members if views[i].shared)
            clusters.append({
                "members": sorted(members),
                "anchors": shared,
                "functions": sorted(users),
                "min_size": max((o + int(re.match(r"\d+", next(iter(s["shapes"]))).group(0))
                                 for o, s in fields.items()), default=0),
                "fields": {f"0x{o:X}": {"shapes": dict(s["shapes"]), "names": dict(s["names"].most_common(3))}
                           for o, s in sorted(fields.items())},
                "conflicts": [f"0x{o:X}" for o, s in sorted(fields.items()) if len(s["shapes"]) > 1],
            })
        clusters.sort(key=lambda c: (-len(c["members"]), -len(c["functions"])))
        for i, c in enumerate(clusters):
            c["id"] = i
        local = [sd for sd in self.structs.values() if not sd.shared]
        return {
            "totals": {
                "struct_types": len(self.structs),
                "local_types": len(local),
                "local_types_laid_out": sum(1 for sd in local if sd.layout and sd.layout.complete),
                "views_with_fields": len(views),
                "clustered_views": sum(len(c["members"]) for c in clusters),
                "clusters": len(clusters),
                "flow_links": sum(1 for l in links if l["via"] == "flow" and l["merged"]),
                "flow_links_refused": sum(1 for l in links if l["via"] == "flow" and not l["merged"]),
                "overlap_links": sum(1 for l in links if l["via"] == "overlap"),
            },
            "clusters": clusters,
            "links": links,
        }


def emit(cluster: dict, name: str = "Merged") -> str:
    """A proposed struct: majority shape per offset, best non-generic name, explicit padding.
    Same-offset disagreements and overlapping fields are left as comments for review."""
    lines = [f"/* type-survey cluster {cluster['id']}: {len(cluster['members'])} views, "
             f"{len(cluster['functions'])} functions */", "typedef struct {"]
    ctypes = {"1i": "u8", "2i": "u16", "4i": "u32", "8i": "u64", "4f": "f32", "8f": "f64", "4p": "void *"}
    # one row per offset: majority shape, best name with array indices split off
    rows = []
    for key, slot in cluster["fields"].items():
        off = int(key, 16)
        shape, _ = Counter(slot["shapes"]).most_common(1)[0]
        raw = next(iter(slot["names"]), None) or f"unk_{off:X}"
        m = re.match(r"^(.*?)\[(\d+)\]$", raw)
        base, index = (m.group(1), int(m.group(2))) if m else (raw, None)
        base = re.sub(r"\W+", "_", base.replace("].", "_")).strip("_") or f"unk_{off:X}"
        others = [s for s in slot["shapes"] if s != shape]
        rows.append((off, shape, int(re.match(r"\d+", shape).group(0)), base, index, others))
    lines_out, at, i = [], 0, 0
    used = Counter()
    while i < len(rows):
        off, shape, size, base, index, others = rows[i]
        if off < at:
            lines_out.append(f"    /* 0x{off:X}: {shape} {base} overlaps the previous field */")
            i += 1; continue
        if off > at:
            lines_out.append(f"    u8 pad_{at:X}[0x{off - at:X}];")
        # coalesce a run of consecutive elements of one array back into one declaration
        j = i + 1
        while index is not None and j < len(rows) and rows[j][3] == base and rows[j][1] == shape \
                and rows[j][4] == index + (j - i) and rows[j][0] == off + (j - i) * size:
            j += 1
        count = j - i
        used[base] += 1
        member = base if used[base] == 1 else f"{base}_{off:X}"
        ctype = ctypes.get(shape, "u8")
        decl = f"void *{member}" if ctype.endswith("*") else f"{ctype} {member}"
        if count > 1 or index is not None:
            decl += f"[{count}]"
        notes = sorted({s for r in rows[i:j] for s in r[5]})
        lines_out.append(f"    {decl};  /* 0x{off:X}" + (f"; also {', '.join(notes)}" if notes else "") + " */")
        at = off + size * count
        i = j
    lines.extend(lines_out)
    lines.append(f"}} {name};")
    return "\n".join(lines)


def _match_paren(text: str, i: int) -> int:
    depth = 0
    for j in range(i, len(text)):
        if text[j] == "(":
            depth += 1
        elif text[j] == ")":
            depth -= 1
            if depth == 0:
                return j + 1
    return len(text)


def _int(s: str) -> Optional[int]:
    s = s.strip().rstrip("uUlL")
    try:
        return int(s, 0)
    except ValueError:
        return None


def _align(x: int, a: int) -> int:
    return (x + a - 1) // a * a


def run(out: Optional[Path] = None) -> dict:
    result = Survey().run()
    out = out or STATE_DIR / "typesurvey.json"
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps(result, indent=1))
    return result


def summary(result: dict, top: int = 15) -> str:
    t = result["totals"]
    lines = [f"{t['local_types']} per-function struct types ({t['local_types_laid_out']} laid out), "
             f"{t['struct_types'] - t['local_types']} shared; {t['clustered_views']} views in "
             f"{t['clusters']} clusters ({t['flow_links']} flow links, {t['flow_links_refused']} refused for conflicts, {t['overlap_links']} overlap links)", ""]
    for c in result["clusters"][:top]:
        names = Counter()
        for slot in c["fields"].values():
            names.update(slot["names"])
        hint = ", ".join(n for n, _ in names.most_common(4)) or "-"
        anchor = f" anchored by {', '.join(c['anchors'][:2])}" if c["anchors"] else ""
        lines.append(f"#{c['id']:<4} {len(c['members']):>4} views {len(c['functions']):>4} fns  "
                     f">=0x{c['min_size']:X} bytes  {len(c['fields'])} fields  "
                     f"{len(c['conflicts'])} conflicts{anchor}  [{hint}]")
    return "\n".join(lines)
