#include "types.h"
#define GX_FIFO_ADDRESS 0xCC008000 // fzgx-allow: A1 hardware FIFO register
// fzgx-allow: S2 hardware FIFO register
#define GXWGFifo8 (*(volatile u8 *)GX_FIFO_ADDRESS)
// fzgx-allow: S2 hardware FIFO register
#define GXWGFifo (*(volatile u32 *)GX_FIFO_ADDRESS)
struct GXState { u8 pad0[2]; u16 bpSentNot; u8 pad4[0x1D4]; u32 zmode; };
extern struct GXState *const gx;
void fn_80037BC0(u8 enable, u32 func, u8 update) {
    u32 reg = gx->zmode;
    reg = __rlwimi(reg, enable, 0, 31, 31);
    reg = __rlwimi(reg, func, 1, 28, 30);
    reg = __rlwimi(reg, update, 4, 27, 27);
    GXWGFifo8 = 0x61;
    GXWGFifo = reg;
    gx->zmode = reg;
    gx->bpSentNot = 0;
}
