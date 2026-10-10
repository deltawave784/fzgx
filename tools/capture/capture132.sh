#!/bin/sh
# tools/capture/capture132.sh SYMBOL BODY.c MODULE  -> coloring-only GC/1.3.2 capture in $FZGX_CAPTURE_DIR/SYMBOL
# Guest and paths: env.sh (Lima on macOS, WSL on Windows).
set -eu
SYM=$1; BODY=$2; MODULE=$3
. "$(dirname "$0")/env.sh"
OUT=$CAPTURE_HOST/$SYM
mkdir -p "$OUT"; cp "$BODY" "$OUT/$SYM.c"
OUT_G=$(to_guest "$OUT")
(cd "$ROOT" && uv run python -c "
import sys; sys.path.insert(0,'tools')
from fzgx.project import Project; from fzgx import oracle
print(oracle.module_flags(Project(),'$MODULE')[0] + ' ' + '${EXTRA_FLAGS:-}')") > "$OUT/flags.txt"
cat > "$OUT/capture.gdb" <<GDB
set pagination off
set confirm off
set architecture i386
python
import sys
sys.path.append('$MWCC_G/tools')
sys.path.append('$MWCC_G/tools/gdb')
sys.path.append('$ROOT_G/tools/capture')
end
target remote :1234
source $ROOT_G/tools/capture/mwcc132_snapshot.py
mwcc132-capture $OUT_G
continue
quit
GDB
cat > "$OUT/run.sh" <<RUN
#!/bin/sh
set -u
export PATH=$GUEST_PATH
cd $ROOT_G; mkdir -p /tmp/wibo; export HOME=/tmp WIBO_TMP_DIR=/tmp/wibo
eval set -- \$(cat $OUT_G/flags.txt)
timeout 600 qemu-i386 -g 1234 $WIBO build/compilers/GC/1.3.2/mwcceppc.exe "\$@" -c $OUT_G/$SYM.c -o $OUT_G/$SYM.o > $OUT_G/compile.log 2>&1 &
Q=\$!; sleep 2; timeout 600 gdb-multiarch -batch -x $OUT_G/capture.gdb > $OUT_G/gdb.log 2>&1; wait \$Q; echo "compile exit \$?" >> $OUT_G/compile.log
RUN
guest_run "$OUT/run.sh"
grep -v "^Reading\|^warning\|^0x\|^\[Inferior" "$OUT/gdb.log" | tail -8; ls "$OUT" | grep -c json
