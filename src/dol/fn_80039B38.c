#include "types.h"
#include "dolphin/types.h"
#include "dolphin/gx.h"

extern u32 gx;

void fn_80039B38(void) {
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = 0x2402C022;
    GXWGFifo.u8 = 0x10;
    GXWGFifo.u32 = 0x1006;
    GXWGFifo.u32 = 0x31000;
    ((u16 *)gx)[1] = 1;
}
