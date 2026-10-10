#!/bin/sh
# One-time guest setup for allocator captures on Windows (the WSL analog of fzgx-capture.yaml).
#   wsl -d Debian -u root -- sh tools/capture/setup-wsl.sh     (run from the repository root)
# Installs qemu-user (for its GDB stub), gdb-multiarch and python3, and the decompals wibo 1.2.0
# i686 build (the version configure.py pins) checked against its published SHA-256.
set -eu
export PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin DEBIAN_FRONTEND=noninteractive
apt-get update -qq
# systemd-binfmt fails to start under WSL; the packages still install and qemu-i386 runs directly.
apt-get install -y -qq --no-install-recommends qemu-user gdb-multiarch python3 curl ca-certificates || true
command -v qemu-i386 gdb-multiarch python3 >/dev/null
mkdir -p /opt/fzgx-capture
cd /opt/fzgx-capture
if ! echo "2575d3b0a2f408b2c2b0850db56f1af5d005a138394a6774eba77b6708ecc304  wibo-i686" | sha256sum -c --status 2>/dev/null; then
  curl -sSL -o wibo-i686 https://github.com/decompals/wibo/releases/download/1.2.0/wibo-i686
  echo "2575d3b0a2f408b2c2b0850db56f1af5d005a138394a6774eba77b6708ecc304  wibo-i686" | sha256sum -c
fi
chmod +x wibo-i686
echo "capture guest ready: $(qemu-i386 --version | head -1); $(gdb-multiarch --version | head -1)"
