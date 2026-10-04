#include "types.h"

/* lbl_80187370: refcount, init flag, two aligned table pointers, then the
 * 16-word table at lbl_80187380 that memset clears (addressed off one base). */
typedef struct {
    s32 refCount;
    s32 initialized;
    f32 *table1;
    u8 *table2;
    u32 slots[16];
} fn_80053BFC_State;

extern fn_80053BFC_State lbl_80187370;
extern void *memset(void *dest, int value, u32 size);
extern u8 lbl_801319E0[2176];
extern u8 lbl_8012B938[8320];
extern const f32 lbl_80091350[];  /* .rodata pool: 2^31 (unsized so it stays out of sdata2) */

void fn_80053BFC(void) {
    fn_80053BFC_State *state = &lbl_80187370;
    u8 *dst;
    s32 i;

    if (state->refCount == 0) {
        memset(state->slots, 0, 0x40);
        if (state->initialized == 0) {
            /* align the table to 32 bytes in place: copy backwards since the
             * destination overlaps the source */
            dst = (u8 *)(((u32)lbl_801319E0 + 0x1f) & ~0x1f);
            state->table1 = (f32 *)dst;
            for (i = 0x800; i >= 0; i--) {
                dst[i] = lbl_801319E0[i];
            }
            for (i = 0; i < 0x200; i++) {
                state->table1[i] *= lbl_80091350[0];
            }

            dst = (u8 *)(((u32)lbl_8012B938 + 0x1f) & ~0x1f);
            state->table2 = dst;
            for (i = 0x2000; i >= 0; i--) {
                dst[i] = lbl_8012B938[i];
            }
            state->initialized = 1;
        }
    }
    state->refCount++;
}
