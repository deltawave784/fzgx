"""Shiftability and style lint for src/**/*.c.

Rules (docs/CODING_RULES.md):
  A1  no integer literal in 0x80000000..0x817FFFFF (cached RAM) or
      0xC0000000..0xC17FFFFF (uncached) or 0xCC000000..0xCC00FFFF (hardware
      registers) outside include/dolphin/hw_regs.h; a direct operand of a bitwise
      operator (`flags |= 0xC0000000`, `x & 0xC0000000`) is a mask, not an address; a word
      in the brace initializer of a `const` integer pool table (`static const u32
      fzgx_pool_table_N[] = {...}`, `fzgx_*`/`*pool*` names) is a literal's bit pattern
      (0xC0400000 is -3.0f), not an address
  A2  no cast of a literal to a pointer:  (T *)0x...
  A3  no inline assembly bodies in reconstructed C
  S1  no `goto` without a justification comment on the same or previous line
  S2  no `volatile` / codegen-only `union` without a justification comment
  P1  no `#pragma section code_type ".fzgxpool"` left in force at the end of a block or file
A line may opt out with `// fzgx-allow: <rule> <reason>`.
"""

from __future__ import annotations

import re
from pathlib import Path
from typing import Iterable, List, Tuple

from .project import ROOT

HEX_RE = re.compile(r"\b0[xX]([0-9A-Fa-f]{8})\b")
PTR_CAST_RE = re.compile(r"\(\s*[\w\s]+\*\s*\)\s*0[xX][0-9A-Fa-f]+")
ALLOW_RE = re.compile(r"fzgx-allow:\s*(\w+(?:,\w+)*)")
RANGES = [(0x80000000, 0x817FFFFF), (0xC0000000, 0xC17FFFFF), (0xCC000000, 0xCC00FFFF)]
EXEMPT = {"include/dolphin/hw_regs.h"}


def _rel(path: Path) -> str:
    try:
        return path.resolve().relative_to(ROOT).as_posix()
    except ValueError:
        return path.as_posix()


_BITWISE_BEFORE = re.compile(r"(?:(?<![|&])[|&](?!=)|\^|~|[|&^]=)\s*$")
_BITWISE_AFTER = re.compile(r"^\s*(?:[|&](?![|&])|\^)")


def _bitwise_operand(code: str, start: int, end: int) -> bool:
    """True when the literal at code[start:end] (optionally suffixed `u`/`l`) is a direct operand
    of a bitwise operator: `x |= 0xC0000000`, `x & 0xC0000000`, `~0xC0000000`, `0xC0000000 | y`.
    `||`/`&&` are not bitwise. A1 exempts only this use: the value is a bit mask by construction,
    never a pointer (fn_15_3368's car-flag mask `|= 0xC0000000` was refused for days)."""
    while end < len(code) and code[end] in "uUlL":
        end += 1
    return bool(_BITWISE_BEFORE.search(code[:start])) or bool(_BITWISE_AFTER.match(code[end:]))


_POOL_TABLE = re.compile(
    r'(?m)^[ \t]*(?:static[ \t]+)?(?:(?:const|volatile)[ \t]+)+(?:unsigned[ \t]+|signed[ \t]+)?'
    r'(?:u8|u16|u32|u64|s8|s16|s32|s64|int|long|short|char|(?:union|struct)(?:[ \t]+\w+)?(?:[ \t]*\{[^{}]*\})?)[ \t]+'
    r'(?P<name>fzgx_\w*|\w*[Pp]ool\w*|\w+_pad[0-9A-Fa-f]+)[ \t]*(?:\[[^\]\n]*\][ \t]*)+=[ \t]*\{')


def _pool_table_lines(text: str) -> set:
    """Line numbers inside the brace initializers of file-scope `const` integer pool tables
    (the pool primer's `static const u32 fzgx_pool_table_N[] = {...}` and the one-element
    word tables agents name the same way). Their words are the bit patterns of pooled
    literals: 0xC0400000 is -3.0f, 0xC0A00000 is -5.0f, 0xC1700000 is -15.0f. A1 read them as
    uncached-RAM addresses and blocked two 100% matches until the agents respelled them as
    decimals (fn_3_23A1C) and `0xC000u << 16` (fn_1_67680). The shared-pool primer's raw
    filler tables are named `<symbol>_pad<offset>` (fn_3_225F8_pad1C0 held -3.0f and -5.0f and
    blocked an exact match in tooling round 60), so that name form is a pool table too. Nothing outside the braces is
    exempt, so an address kept in a scalar or in any other table is still flagged."""
    out: set = set()
    for m in _POOL_TABLE.finditer(text):
        depth, i = 0, m.end() - 1
        while i < len(text):
            c = text[i]
            if c == '{':
                depth += 1
            elif c == '}':
                depth -= 1
                if depth == 0:
                    break
            i += 1
        else:
            break
        first = text.count('\n', 0, m.end()) + 1
        last = text.count('\n', 0, i) + 1
        out.update(range(first, last + 1))
    return out


def lint_file(path: Path) -> List[Tuple[str, int, str]]:
    if _rel(path) in EXEMPT:
        return []
    return lint_text(path.read_text(errors="replace"))


def lint_text(text: str) -> List[Tuple[str, int, str]]:
    """The rules over a source text (a candidate body before it is written anywhere)."""
    findings: List[Tuple[str, int, str]] = []
    lines = text.splitlines()
    pool_lines = _pool_table_lines(text) if ('ool' in text or 'fzgx_' in text) else set()
    for i, line in enumerate(lines, 1):
        code = line.split("//", 1)[0]
        allow = {r for m in ALLOW_RE.finditer(line) for r in m.group(1).split(",")}  # every allow comment on the line
        prev = lines[i - 2] if i >= 2 else ""
        justified = "//" in line or "//" in prev or "/*" in line or "/*" in prev
        for m in HEX_RE.finditer(code):
            v = int(m.group(1), 16)
            if v == 0x80000000:
                continue  # the sign-bit mask, not an address (nothing is addressed at the RAM base itself)
            if _bitwise_operand(code, m.start(), m.end()):
                continue  # a direct operand of `| & ^ ~` (`flags |= 0xC0000000`): a bit mask, not an address
            if i in pool_lines:
                continue  # a word of a const pool table's initializer: a pooled literal's bit pattern
            if any(lo <= v <= hi for lo, hi in RANGES) and "A1" not in allow:
                findings.append(("A1", i, f"hardcoded address 0x{v:08X}; use a symbol"))
        if PTR_CAST_RE.search(code) and "A2" not in allow:
            findings.append(("A2", i, "literal cast to pointer; declare an extern symbol"))
        if re.search(r'\b(?:asm|__asm__)\s*(?:volatile\s*)?\{', code):
            findings.append(("A3", i, "inline assembly body in reconstructed C"))
        if re.search(r"\bgoto\b", code) and not justified and "S1" not in allow:
            findings.append(("S1", i, "goto without a justification comment"))
        if re.search(r"\bvolatile\b", code) and not justified and "S2" not in allow:
            findings.append(("S2", i, "volatile without a justification comment"))
    findings.extend(_pool_section_findings(lines))
    return findings


_CODE_TYPE = re.compile(r'^\s*#\s*pragma\s+section\s+code_type\b\s*(?:"([^"]*)")?')
_PRAGMA_STACK = re.compile(r'^\s*#\s*pragma\s+(push|pop)\b')
_BLOCK_MARK = re.compile(r'/\*\s*fzgx:(begin|end)\b')


def _pool_section_findings(lines: List[str]) -> List[Tuple[str, int, str]]:
    """P1: `#pragma section code_type ".fzgxpool"` still in force at the end of a block (or of the
    file). MWCC keeps a code_type until it is switched back to `.text` or a `#pragma pop` closes
    the enclosing `push` (measured on GC/1.1, 1.2.5n and 1.3.2), so every later function of the
    unit, and of the TU once it is collapsed, would be emitted into the section integration
    drops. Primer emitters close the region with `#pragma section code_type ".text"`."""
    out: List[Tuple[str, int, str]] = []
    if "fzgxpool" not in "".join(lines):
        return out
    stack: List[str] = []
    cur, opened, pooled = ".text", 0, False
    for i, line in enumerate(lines, 1):
        mark = _BLOCK_MARK.search(line)
        if mark and mark.group(1) == "begin":
            # a `pool` block is not linked from C (retail's object is), so the stray region
            # cannot move linked code until the block is revised; work copies have no markers
            stack, cur, opened = [], ".text", 0
            pooled = bool(re.search(r"fzgx:begin\s+\S+[^*]*\bpool\b", line))
        ps = _PRAGMA_STACK.match(line)
        if ps:
            if ps.group(1) == "push":
                stack.append(cur)
            elif stack:
                cur = stack.pop()
        m = _CODE_TYPE.match(line)
        if m:
            cur = m.group(1) or ".text"
            if cur == ".fzgxpool":
                opened = i
        if mark and mark.group(1) == "end" and cur == ".fzgxpool" and not pooled:
            out.append(("P1", opened, 'code_type ".fzgxpool" not reset before the block ends; '
                                      'add #pragma section code_type ".text"'))
            stack, cur = [], ".text"
    if cur == ".fzgxpool":
        out.append(("P1", opened, 'code_type ".fzgxpool" still in force at end of file; '
                                  'add #pragma section code_type ".text"'))
    return out


def lint_paths(paths: Iterable[Path]) -> List[Tuple[str, str, int, str]]:
    out: List[Tuple[str, str, int, str]] = []
    for p in paths:
        files = [p] if p.is_file() else sorted(p.rglob("*.c")) + sorted(p.rglob("*.h"))
        for f in files:
            for rule, line, msg in lint_file(f):
                out.append((_rel(f), rule, line, msg))
    return out
