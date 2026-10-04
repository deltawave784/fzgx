"""Compile a TU file as one unit and score every function inside it against retail.

Per-function units cannot reproduce a translation unit's literal pool (retail
addresses it through one base register plus offsets). The whole-TU compile
can, once the TU's functions use the same literals in the same order. This
trial compiles `src/<tu>.c` as a single object and diffs each function's symbol
against that function's retail split object (objdiff two-object mode), so we
can see which functions still match inside the whole-TU compile and which
pool-bound functions start matching only there.
"""

from __future__ import annotations

from pathlib import Path
from typing import Dict, List, Optional

from .project import ROOT, Project
from . import oracle, tufile

def compile_tu(p: Project, tu_source: str, extra_blocks: Optional[Dict[str, str]] = None) -> tuple:
    """Compile the TU file (optionally with extra function bodies appended) as one object.
    Returns (object path or None, compiler text)."""
    module = tu_source.split("/")[1] if tu_source.startswith("rel/") else "main"
    units = [u for u in p.load_units() if u.get("tu") == tu_source]
    flags = ' '.join(units[0].get('extra_cflags') or []) if units else None
    mw = (units[0].get("mw_version") if units else None) or ("GC/1.2.5n" if module == "main" else "GC/1.3.2")
    tf = tufile.load(p, tu_source)
    text = tf.render()
    if extra_blocks:
        for name, body in extra_blocks.items():
            inc, rest = tufile.split_includes(body)
            text += "\n" + tufile.Block(name, "\n".join(inc + [""]) + rest if inc else rest).render()
    d = p.build_dir / "gen" / "tu_trial"
    d.mkdir(parents=True, exist_ok=True)
    src = d / (Path(tu_source).stem + ".c")
    src.write_text(text)
    out = src.with_suffix(".o")
    cp = oracle.compile_source(p, module, src, out, mw_version=mw, extra_cflags=flags)
    msg = "\n".join(l for l in (cp.stdout + cp.stderr).splitlines() if "Usage Warning" not in l).strip()
    return (out if cp.returncode == 0 and out.exists() else None), msg[-3000:]


def score(p: Project, tu_source: str, obj: Path) -> Dict[str, Optional[float]]:
    """Per-function match % of the whole-TU object against each function's retail object."""
    module = tu_source.split("/")[1] if tu_source.startswith("rel/") else "main"
    tf = tufile.load(p, tu_source)
    out: Dict[str, Optional[float]] = {}
    for b in tf.blocks:
        sym = p.find_symbol(b.name, module)
        unit_src = p.unit_of(sym) if sym else None
        meta = p.objdiff_units().get(p.objdiff_unit_name(module, unit_src), {}) if unit_src else {}
        target = ROOT / meta.get("target_path", "") if meta.get("target_path") else None
        if not target or not target.exists():
            out[b.name] = None
            continue
        check = oracle._diff(p, module, b.name, '', 0, target=target, base=obj)
        out[b.name] = (100.0 if check.matched or check.matched_pool else check.percent) if check.ok else None
    return out


def trial(p: Project, tu_source: str, extra_blocks: Optional[Dict[str, str]] = None) -> Dict[str, object]:
    obj, msg = compile_tu(p, tu_source, extra_blocks)
    if obj is None:
        return {"ok": False, "tu": tu_source, "error": msg}
    scores = score(p, tu_source, obj)
    full = sum(1 for v in scores.values() if v is not None and v >= 100.0)
    return {"ok": True, "tu": tu_source, "functions": len(scores), "at_100": full,
            "below": {k: v for k, v in scores.items() if v is None or v < 100.0}, "object": p.rel(obj)}


def strip_declarations(body: str) -> str:
    """The function definitions of a saved body without its private includes, externs and
    struct/typedef definitions: the whole TU's prologue is the one declaration truth."""
    import re
    out: List[str] = []
    depth = 0
    skipping = False
    for line in body.splitlines():
        s = line.strip()
        if depth == 0 and (s.startswith("#include") or re.match(r"extern\b.*;\s*$", s)):
            continue
        if depth == 0 and re.match(r"(typedef\s+)?(struct|union|enum)\b[^;(]*\{?\s*$", s) and not re.search(r"\)\s*\{?$", s):
            skipping = True
        if skipping:
            depth += line.count("{") - line.count("}")
            if depth <= 0 and (";" in s):
                skipping, depth = False, 0
            continue
        out.append(line)
    return "\n".join(out).strip("\n") + "\n"


def near_misses(p: Project, tu_source: str, min_percent: float = 0.0) -> List[Dict[str, object]]:
    """The TU's unmatched functions that have a saved body, each compiled inside the whole TU
    (one trial per body: a body's own declarations may conflict with the TU's) and scored
    against the function's retail object. `saved` is the best score of the body compiled alone
    (the ledger's best attempt), `in_tu` its score inside the whole-TU object, `error` the
    first compiler message when the body cannot join the TU as written."""
    import json
    from .ledger import Ledger
    module = tu_source.split("/")[1] if tu_source.startswith("rel/") else "main"
    tus_json = ROOT / "config" / p.version / module / "tus.json"
    names: List[str] = []
    if tus_json.exists():
        for tu in json.loads(tus_json.read_text()).get("tus", []):
            if tu.get("file") == Path(tu_source).name:
                names = list(tu.get("functions", []))
    ledger = Ledger()
    rows: List[Dict[str, object]] = []
    for name in names:
        sym = p.find_symbol(name, module)
        row = ledger.get(p.key(sym)) if sym else None
        if not row or row["status"] != "unmatched":
            continue
        found = ledger.best_local_attempt(p.key(sym))
        if not found:
            continue
        att, path = found
        saved = att["best_in_attempt"] or att["final_percent"] or 0.0
        if saved < min_percent:
            continue
        entry: Dict[str, object] = {"symbol": name, "size": row["size"], "saved": round(saved, 1)}
        obj, msg = compile_tu(p, tu_source, {name: path.read_text()})
        entry["body"] = "as written"
        if obj is None:
            obj, msg2 = compile_tu(p, tu_source, {name: strip_declarations(path.read_text())})
            if obj is not None:
                entry["body"] = "declarations stripped"
            else:
                msg = msg2 or msg
        if obj is None:
            lines = [l.strip("# ").strip() for l in msg.splitlines()]
            at = next((i for i, l in enumerate(lines) if l.startswith("Error:")), None)
            first = " ".join(x for x in lines[at + 1:at + 3] if x) if at is not None else msg[:120]
            entry["in_tu"] = None
            entry["error"] = first[:140]
        else:
            target = p.target_object_for(sym)
            res = oracle._diff(p, module, name, "", 0, target=target, base=obj) if target else None
            if res is not None and res.ok:
                entry["in_tu"] = 100.0 if (res.matched or res.matched_pool) else round(res.percent, 1)
            else:
                entry["in_tu"] = None
                entry["error"] = "no score" if res is None else str(res.error)[:140]
        rows.append(entry)
    return sorted(rows, key=lambda r: -(r["in_tu"] if r["in_tu"] is not None else -1))
