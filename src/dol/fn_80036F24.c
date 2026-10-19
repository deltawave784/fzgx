#include "types.h"
#include "dolphin/hw_regs.h"

struct GXState {
    u8 pad_000[0x2];
    u16 dirtyFlags_2;
    u8 pad_004[0x11C];
    u32 state_120;
    u32 state_124;
    u8 pad_128[0xDC];
    u32 state_204;
};

extern struct GXState *const gx;

static inline void FlushBP(struct GXState *state) {
    *(u32 *)GX_FIFO_BASE = state->state_124;
    state->dirtyFlags_2 = 0;
}

/* Rebuild the texture-coordinate enable mask from the per-stage tex coord
 * selectors and flush the register to the GP when it changed. */
void fn_80036F24(void) {
    struct { struct GXState *value; } state;
    s32 i;
    u32 bits;
    u32 result;
    u32 count;
    u32 current;

    result = 0;
    count = (gx->state_204 >> 16) & 0x7;

    for (i = 0; i < count; i++) {
        switch (i) {
        case 0:
            bits = gx->state_120 & 0x7;
            break;
        case 1:
            bits = (gx->state_120 >> 6) & 0x7;
            break;
        case 2:
            bits = (gx->state_120 >> 12) & 0x7;
            break;
        case 3:
            bits = (gx->state_120 >> 18) & 0x7;
            break;
        }
        result |= 1 << bits;
    }

    current = gx->state_124;
    if ((current & 0xFF) != result) {
        gx->state_124 = (current & ~0xFF) | result;
        /* write-gather pipe: BP register load (0x61) followed by the value */
        *(u8 *)GX_FIFO_BASE = 0x61;
        FlushBP(gx);
    }
}
