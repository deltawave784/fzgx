#include "types.h"
// fzgx-allow: A1 hardware FIFO register
#define GX_FIFO_ADDRESS 0xCC008000 // fzgx-allow: A1 hardware FIFO register
// fzgx-allow: A2 hardware FIFO register
// fzgx-allow: S2 hardware FIFO register
#define GXWGFifo8 (*(volatile u8 *)GX_FIFO_ADDRESS)
// fzgx-allow: A2 hardware FIFO register
// fzgx-allow: S2 hardware FIFO register
#define GXWGFifo (*(volatile u32 *)GX_FIFO_ADDRESS)
extern u32 gx;
struct GXState { u8 pad0[2]; u16 bpSentNot; u8 pad4[0x1D0]; u32 cmode1; };
void fn_80037D40(u8 enable, u8 alpha) {
    struct GXState *state = (struct GXState *)gx;
    u32 reg = state->cmode1;
    reg = __rlwimi(reg, alpha, 0, 24, 31);
    reg = __rlwimi(reg, enable, 8, 23, 23);
    GXWGFifo8 = 0x61;
    GXWGFifo = reg;
    state->cmode1 = reg;
    state->bpSentNot = 0;
}
