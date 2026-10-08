#include "types.h"
#define GX_FIFO_ADDRESS 0xCC008000 // fzgx-allow: A1 hardware FIFO register
#define GXWGFifo8 (*(volatile u8 *)GX_FIFO_ADDRESS) // fzgx-allow: S2 hardware FIFO register
#define GXWGFifo (*(volatile u32 *)GX_FIFO_ADDRESS) // fzgx-allow: S2 hardware FIFO register
struct fn_80037B14_gx_T {
    u8 pad_0[0x2];
    u16 unk_2;
    u8 pad_4[0x1CC];
    u32 unk_1D0;
};
extern struct fn_80037B14_gx_T *const gx;
void fn_80037B14(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 v1;
    struct fn_80037B14_gx_T *state = gx;
    v1 = state->unk_1D0;
    v1 = __rlwimi(v1, arg0 == 3, 11, 20, 20);
    v1 = __rlwimi(v1, arg0, 0, 31, 31);
    v1 = __rlwimi(v1, arg0 == 2, 1, 30, 30);
    v1 = __rlwimi(v1, arg3, 12, 16, 19);
    v1 = __rlwimi(v1, arg1, 8, 21, 23);
    v1 = __rlwimi(v1, arg2, 5, 24, 26);
    GXWGFifo8 = 97;
    GXWGFifo = v1;
    state->unk_1D0 = v1;
    state->unk_2 = 0;
}
