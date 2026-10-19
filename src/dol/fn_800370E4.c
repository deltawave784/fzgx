#include "dolphin/gx.h"
#include "types.h"

typedef struct GXState {
    u16 pad0;
    u16 bpSentNot;
    u8 pad4[0x16C];
    u32 tevAlphaEnv[16];
} GXState;

extern u32 gx;

void fn_800370E4(u32 stage, u32 a, u32 b, u32 c, u32 d) {
    GXState *state = (GXState *)gx;
    u32 value = state->tevAlphaEnv[stage];
    value = __rlwimi(value, a, 13, 16, 18);
    value = __rlwimi(value, b, 10, 19, 21);
    value = __rlwimi(value, c, 7, 22, 24);
    value = __rlwimi(value, d, 4, 25, 27);
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = value;
    state->tevAlphaEnv[stage] = value;
    state->bpSentNot = 0;
}
