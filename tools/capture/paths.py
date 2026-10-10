"""Host paths shared by the capture analysis scripts (env.sh is the shell counterpart).
FZGX_MWCC_ROOT names the recovery project's checkout (default: a sibling `mwcc` of this
repository); FZGX_CAPTURE_DIR the capture directory (default: .fzgx/capture)."""
import os, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
MWCC = Path(os.environ.get('FZGX_MWCC_ROOT', ROOT.parent / 'mwcc'))
CAPTURE = os.environ.get('FZGX_CAPTURE_DIR', str(ROOT / '.fzgx' / 'capture'))
sys.path.insert(0, str(ROOT / 'tools'))


def mwcc_tool(*args):
    """argv running a recovery-project tool with this interpreter (`python3` is a Store stub on Windows)."""
    return [sys.executable, *args]
