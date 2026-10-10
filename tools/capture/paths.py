"""Host paths shared by the capture analysis scripts (env.sh is the shell counterpart).
The recovery tools (vreg_map, simplify_replay, source_rank_solver, allocator_snapshot) are the
rebuilt copies in tools/capture/recovery unless FZGX_MWCC_ROOT names a recovery-project checkout
that has them; FZGX_CAPTURE_DIR names the capture directory (default: .fzgx/capture)."""
import os, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
REBUILT = ROOT / 'tools' / 'capture' / 'recovery'
EXTERNAL = Path(os.environ['FZGX_MWCC_ROOT']) if os.environ.get('FZGX_MWCC_ROOT') else None
CAPTURE = os.environ.get('FZGX_CAPTURE_DIR', str(ROOT / '.fzgx' / 'capture'))
TOOL_DIRS = ([EXTERNAL / 'tools', EXTERNAL / 'tools' / 'replay', EXTERNAL / 'tools' / 'gdb'] if EXTERNAL else []) + [REBUILT]
sys.path.insert(0, str(ROOT / 'tools'))
for _d in reversed(TOOL_DIRS):
    sys.path.insert(1, str(_d))


def tool(relative):
    """Path of a recovery tool given its recovery-project path under tools/ (e.g. 'replay/simplify_replay.py')."""
    if EXTERNAL and (EXTERNAL / 'tools' / relative).exists():
        return EXTERNAL / 'tools' / relative
    return REBUILT / Path(relative).name


def run_tool(*args):
    """argv running a recovery tool with this interpreter (`python3` is a Store stub on Windows)."""
    return [sys.executable, *map(str, args)]


def capture_index(cap, symbol, default='0001'):
    """The capture index (e.g. '0003') of SYMBOL: a unit's primer and helper functions compile first."""
    import json
    f = Path(cap) / 'functions.json'
    if f.exists():
        for idx, name in json.loads(f.read_text()).items():
            if name == symbol:
                return idx
    return default
