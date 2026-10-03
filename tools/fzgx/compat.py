"""Host differences the tooling needs: file locks and process groups.

POSIX uses flock and sessions; Windows uses msvcrt byte-range locks and new
process groups, killed as a tree with taskkill (Windows has no process-group
signal that reaches grandchildren such as wibo-less mwcc or ninja's children).
"""

from __future__ import annotations

import os
import signal
import subprocess
import sys
from pathlib import Path

WINDOWS = sys.platform == "win32"
ROOT = Path(__file__).resolve().parent.parent.parent

if WINDOWS:
    import msvcrt
else:
    import fcntl


def lock(f, blocking: bool = True) -> None:
    """Exclusive lock on an open file. Raises BlockingIOError when `blocking` is
    False and another process holds it."""
    if not WINDOWS:
        fcntl.flock(f, fcntl.LOCK_EX | (0 if blocking else fcntl.LOCK_NB))
        return
    f.seek(0)
    while True:
        try:
            msvcrt.locking(f.fileno(), msvcrt.LK_NBLCK, 1)
            return
        except OSError:
            if not blocking:
                raise BlockingIOError(f"{getattr(f, 'name', f)}: locked")
            # LK_LOCK gives up after ten one-second tries; poll instead so a
            # long holder (a full relink) is waited out like flock would.
            import time
            time.sleep(0.1)


def unlock(f) -> None:
    if not WINDOWS:
        fcntl.flock(f, fcntl.LOCK_UN)
        return
    f.seek(0)
    msvcrt.locking(f.fileno(), msvcrt.LK_UNLCK, 1)


def new_group() -> dict:
    """Popen / create_subprocess_exec kwargs that put the child in its own group."""
    if WINDOWS:
        return {"creationflags": subprocess.CREATE_NEW_PROCESS_GROUP}
    return {"start_new_session": True}


def kill_group(pid: int, force: bool = False) -> None:
    """Signal a child started with new_group() and everything it spawned.
    A group that has already exited is not an error."""
    if WINDOWS:
        # Console children ignore taskkill's polite WM_CLOSE, so there is no SIGTERM
        # equivalent: both cases terminate the tree.
        subprocess.run(["taskkill", "/T", "/F", "/PID", str(pid)],
                       stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        return
    try:
        os.killpg(pid, signal.SIGKILL if force else signal.SIGTERM)
    except ProcessLookupError:
        pass


def tool(name: str) -> Path:
    """A tool configure.py downloaded into build/tools (dtk, objdiff-cli, wibo, ...)."""
    path = ROOT / "build" / "tools" / name
    return path.with_name(name + ".exe") if WINDOWS else path


def mwcc(mw: str) -> list:
    """argv prefix that runs the MWCC version `mw` (e.g. "GC/1.3.2"): native on Windows,
    under wibo elsewhere."""
    exe = str(ROOT / "build" / "compilers" / mw / "mwcceppc.exe")
    return [exe] if WINDOWS else [str(tool("wibo")), exe]
