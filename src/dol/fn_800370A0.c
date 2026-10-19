#include "dolphin/gx.h"
#include "types.h"

typedef struct GXState {
    u16 pad0;
    u16 bpSentNot;
    u8 pad4[0x12C];
    u32 tevColorEnv[16];
} GXState;

extern u32 gx;

void fn_800370A0(u32 stage, u32 a, u32 b, u32 c, u32 d) {
    GXState *state = (GXState *)gx;
    u32 value = state->tevColorEnv[stage];
    value = __rlwimi(value, a, 12, 16, 19);
    value = __rlwimi(value, b, 8, 20, 23);
    value = __rlwimi(value, c, 4, 24, 27);
    value = __rlwimi(value, d, 0, 28, 31);
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = value;
    state->tevColorEnv[stage] = value;
    state->bpSentNot = 0;
}
