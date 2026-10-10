# Sourced by capture.sh and capture132.sh: host paths, guest paths and the guest runner.
# Two guests are supported: the `fzgx-capture` Lima VM on macOS (fzgx-capture.yaml, the repo and
# the recovery project mounted at their host paths) and a WSL distribution on Windows
# (setup-wsl.sh; the guest sees C: under /mnt/c). The recovery project's checkout defaults to a
# sibling of this repository; override with FZGX_MWCC_ROOT (host path).
ROOT=$(cd "$(dirname "$0")/../.." && pwd)
MWCC_HOST=${FZGX_MWCC_ROOT:-$(cd "$ROOT/.." && pwd)/mwcc}
CAPTURE_HOST=${FZGX_CAPTURE_DIR:-$ROOT/.fzgx/capture}
if command -v wsl.exe >/dev/null 2>&1; then
  DISTRO=${FZGX_WSL_DISTRO:-Debian}
  to_guest() { MSYS_NO_PATHCONV=1 wsl.exe -d "$DISTRO" wslpath -a "$(cygpath -m "$1")" | tr -d '\r'; }
  guest_run() { MSYS_NO_PATHCONV=1 wsl.exe -d "$DISTRO" -u root -- sh "$(to_guest "$1")"; }
  WIBO=/opt/fzgx-capture/wibo-i686
else
  to_guest() { printf '%s\n' "$1"; }
  guest_run() { limactl shell fzgx-capture -- sh "$1"; }
  WIBO=$MWCC_HOST/build/tools/wibo-i686
fi
ROOT_G=$(to_guest "$ROOT")
MWCC_G=$(to_guest "$MWCC_HOST")
# A clean PATH for guest scripts: WSL appends the Windows PATH, whose entries shadow coreutils.
GUEST_PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
