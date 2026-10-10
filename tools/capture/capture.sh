#!/bin/sh
# Capture MWCC's PCode and register-coloring state for one function of a per-function body.
#   tools/capture/capture.sh SYMBOL BODY.c MODULE [GC/1.2.5n|GC/1.2.5] [FUNCTION_INDEX]
# Runs in the capture guest (env.sh: the `fzgx-capture` Lima VM on macOS, WSL on Windows):
# qemu-i386 executes the i386 wibo with the stock compiler under a GDB stub, and the
# recovery project's tools/gdb/allocator_snapshot.py writes every PCode stage, the coloring
# graph before/after selection, creation events and the stack-frame home list to
# .fzgx/capture/SYMBOL/. Only the 1.2.5 / 1.2.5n address set is known to the capture scripts.
# Read the result with `python3 $FZGX_MWCC_ROOT/tools/vreg_map.py .fzgx/capture/SYMBOL 0001`
# and replay it with `python3 $FZGX_MWCC_ROOT/tools/replay/simplify_replay.py DIR 0001`.
set -eu
SYM=$1; BODY=$2; MODULE=$3; MW=${4:-GC/1.2.5n}; IDX=${5:-1}
. "$(dirname "$0")/env.sh"
OUT=$CAPTURE_HOST/$SYM
mkdir -p "$OUT"
cp "$BODY" "$OUT/$SYM.c"
OUT_G=$(to_guest "$OUT")
(cd "$ROOT" && uv run python -c "
import sys; sys.path.insert(0,'tools')
from fzgx.project import Project; from fzgx import oracle
print(oracle.module_flags(Project(),'$MODULE')[0] + ' ' + '${EXTRA_FLAGS:-}')") > "$OUT/flags.txt"
TARGET=stock; case "$MW" in *n) TARGET=ninji;; esac
cat > "$OUT/capture.gdb" <<GDB
set pagination off
set confirm off
set architecture i386
python
import sys
sys.path.append('$MWCC_G/tools')
sys.path.append('$MWCC_G/tools/gdb')
end
target remote :1234
source $MWCC_G/tools/gdb/allocator_snapshot.py
mwcc-auto-capture $OUT_G $IDX $TARGET
continue
quit
GDB
cat > "$OUT/run.sh" <<RUN
#!/bin/sh
set -u
export PATH=$GUEST_PATH
cd $ROOT_G
mkdir -p /tmp/wibo
export HOME=/tmp WIBO_TMP_DIR=/tmp/wibo
eval set -- \$(cat $OUT_G/flags.txt)
timeout 600 qemu-i386 -g 1234 $WIBO build/compilers/$MW/mwcceppc.exe "\$@" -c $OUT_G/$SYM.c -o $OUT_G/$SYM.o > $OUT_G/compile.log 2>&1 &
QPID=\$!
sleep 2
timeout 600 gdb-multiarch -batch -x $OUT_G/capture.gdb > $OUT_G/gdb.log 2>&1
wait \$QPID
echo "compile exit \$?" >> $OUT_G/compile.log
RUN
guest_run "$OUT/run.sh"
tail -3 "$OUT/gdb.log"
ls "$OUT" | grep -c json
