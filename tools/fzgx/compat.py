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
    # The tooling hashes, diffs and content-addresses what it writes, assuming the bytes
    # on disk are the text it wrote. Windows text mode writes CRLF and breaks that, so
    # Path.write_text writes LF unless a caller asks otherwise, exactly as on POSIX.
    # Path.write_text only takes `newline` from Python 3.10; open() always does, and
    # ninja runs configure.py under whichever `python` is first on PATH (3.9 here).
    def _write_text_lf(self, data, encoding=None, errors=None, newline="\n"):
        if not isinstance(data, str):
            raise TypeError(f"data must be str, not {type(data).__name__}")
        with open(self, "w", encoding=encoding, errors=errors, newline=newline) as f:
            return f.write(data)

    Path.write_text = _write_text_lf

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


def replace(src, dst) -> None:
    """os.replace that waits out a concurrent reader on Windows, where replacing a file
    another process has open fails with PermissionError (POSIX rename never does).
    Raises PermissionError if the destination stays busy for about five seconds."""
    if not WINDOWS:
        os.replace(src, dst)
        return
    import time
    for delay in (0.02, 0.05, 0.1, 0.2, 0.4, 0.8, 1.6, 2.0):
        try:
            os.replace(src, dst)
            return
        except PermissionError:
            time.sleep(delay)
    os.replace(src, dst)


def pid_alive(pid: int) -> bool:
    """Whether process `pid` still runs. On Windows os.kill(pid, 0) is TerminateProcess
    with exit code 0, not a probe: it would kill the process it asks about."""
    if not WINDOWS:
        try:
            os.kill(pid, 0)
        except ProcessLookupError:
            return False
        except PermissionError:
            return True
        return True
    import ctypes
    kernel32 = ctypes.windll.kernel32
    handle = kernel32.OpenProcess(0x00100000, False, pid)  # SYNCHRONIZE
    if not handle:
        return False
    try:
        return kernel32.WaitForSingleObject(handle, 0) == 0x102  # WAIT_TIMEOUT: still running
    finally:
        kernel32.CloseHandle(handle)


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
