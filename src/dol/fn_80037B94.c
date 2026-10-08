#include "types.h"
#define GX_FIFO_ADDRESS 0xCC008000 // fzgx-allow: A1 hardware FIFO register
#define GXWGFifo8 (*(volatile u8 *)GX_FIFO_ADDRESS) // fzgx-allow: S2 hardware FIFO register
#define GXWGFifo (*(volatile u32 *)GX_FIFO_ADDRESS) // fzgx-allow: S2 hardware FIFO register
struct GXState { u8 pad0[2]; u16 bpSentNot; u8 pad4[0x1CC]; u32 cmode0; };
extern struct GXState *const gx;
void fn_80037B94(u8 enable) {
    u32 reg = gx->cmode0;
    reg = __rlwimi(reg, enable, 4, 27, 27);
    GXWGFifo8 = 0x61;
    GXWGFifo = reg;
    gx->cmode0 = reg;
    gx->bpSentNot = 0;
}
