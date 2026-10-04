#include "types.h"

typedef struct MovieSlot {
    s32 state;      /* 0x00: 1 = free, 2 = allocated */
    u32 field_04;
    u32 field_08;
    u32 field_0c;
    u32 field_10;
    s32 ids[43];    /* 0x14..0xbc */
} MovieSlot;        /* 0xc0 bytes */

typedef struct MovieSlotPool {
    u8 pad[0xc];
    s32 count;
    MovieSlot slots[1];
} MovieSlotPool;

extern u32 lbl_12_bss_4DB8[2];  /* [0] = MovieSlotPool * */
extern void fn_12_33428(MovieSlot *, u32, u32);

/* static inline: a plain static helper is inlined too, but MWCC still emits
   its out-of-line body, which shifts the module and breaks the REL hash. */
static inline MovieSlot *find_free_slot(void) {
    MovieSlotPool *pool = (MovieSlotPool *)lbl_12_bss_4DB8[0];
    MovieSlot *slot = pool->slots;
    s32 i;

    for (i = 0; i < pool->count; i++, slot++) {
        if (slot->state == 1) {
            return slot;
        }
    }
    return NULL;
}

MovieSlot *fn_12_6B28(void) {
    MovieSlot *slot = find_free_slot();

    if (slot == NULL) {
        return NULL;
    }
    fn_12_33428(slot, 0, 0x30);
    slot->state = 2;
    slot->field_04 = 0;
    slot->field_08 = 0;
    slot->field_0c = 0;
    slot->field_10 = 2;
    slot->ids[0] = -1;
    slot->ids[1] = -1;
    slot->ids[2] = -1;
    slot->ids[3] = -1;
    slot->ids[4] = -1;
    slot->ids[5] = -1;
    slot->ids[6] = -1;
    slot->ids[7] = -1;
    slot->ids[8] = -1;
    slot->ids[9] = -1;
    slot->ids[10] = -1;
    slot->ids[11] = -1;
    slot->ids[12] = -1;
    slot->ids[13] = -1;
    slot->ids[14] = -1;
    slot->ids[15] = -1;
    slot->ids[16] = -1;
    slot->ids[17] = -1;
    slot->ids[18] = -1;
    slot->ids[19] = -1;
    slot->ids[20] = -1;
    slot->ids[21] = -1;
    slot->ids[22] = -1;
    slot->ids[23] = -1;
    slot->ids[24] = -1;
    slot->ids[25] = -1;
    slot->ids[26] = -1;
    slot->ids[27] = -1;
    slot->ids[28] = -1;
    slot->ids[29] = -1;
    slot->ids[30] = -1;
    slot->ids[31] = -1;
    slot->ids[32] = -1;
    slot->ids[33] = -1;
    slot->ids[34] = -1;
    slot->ids[35] = -1;
    slot->ids[36] = -1;
    slot->ids[37] = -1;
    slot->ids[38] = -1;
    slot->ids[39] = -1;
    slot->ids[40] = -1;
    slot->ids[41] = -1;
    slot->ids[42] = -1;
    return slot;
}
