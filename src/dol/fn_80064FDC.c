#include "types.h"

struct Slot64FDC {
    u32 unk_0;
    u32 unk_4;
    u8 *unk_8;
    u32 unk_c;
};

struct Chan64FDC {
    u8 pad_0[6];
    u8 unk_6;
    u8 unk_7;
    u8 unk_8;
    u8 unk_9;
    u8 pad_a[6];
};

struct Entry64FDC {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    u8 unk_7;
    u8 unk_8;
    u8 unk_9;
    u8 unk_a;
    u8 unk_b;
    u8 unk_c;
    u8 unk_d;
    u8 unk_e;
    u8 unk_f;
    u8 unk_10;
    u8 pad_11[7];
    u8 *unk_18;
    u32 unk_1c;
};

struct Data64FDC {
    struct Slot64FDC slots[0x10];
    u8 pad_100[0x38C];
    struct Chan64FDC chans[0xF];
    u8 pad_57C[0xC];
    struct Entry64FDC entries[0x40];
    u8 map[0x10][0x10][4];
};

struct Src64FDC {
    u8 b[0x10];
};

struct List64FDC {
    u8 count;
    u8 pad_1[7];
    struct Src64FDC items[1];
};

extern struct Data64FDC *lbl_801A6C80;

static inline u8 *fn_80064FDC_offset(s32 offset, u8 *base) {
    u8 *result;
    result = (u8 *)offset;
    result = base + (s32)result;
    return result;
}

static inline void fn_80064FDC_link(u8 arg0, u8 arg1) {
    u8 *a;
    u32 i;
    u16 v;

    a = lbl_801A6C80->slots[arg0].unk_8;
    if (lbl_801A6C80->entries[arg1].unk_1 & 2) {
        if (*(u32 *)(a + 0x28) != 0) {
            lbl_801A6C80->entries[arg1].unk_1c = (u32)a + *(u32 *)(a + 0x28);
        } else {
            lbl_801A6C80->entries[arg1].unk_1c = 0;
        }
        return;
    }
    {
        u8 *base;
        u8 *sub;
        u8 *b;
        base = fn_80064FDC_offset(*(u32 *)(a + 0x1c), a);
        b = base;
        for (i = 0; i <= lbl_801A6C80->entries[arg1].unk_4; i++) {
            b += 2;
        }
        sub = base + *(u16 *)b;
        b = sub;
        for (i = 0; i <= lbl_801A6C80->entries[arg1].unk_5; i++) {
            b += 2;
        }
        v = *(u16 *)b;
        if (v != 0) {
            lbl_801A6C80->entries[arg1].unk_1c = v + (u32)sub;
        } else {
            lbl_801A6C80->entries[arg1].unk_1c = 0;
        }
    }
}

void fn_80064FDC(u8 arg0, struct List64FDC *list) {
    u8 j;
    s16 sum;
    u8 panRaw;
    struct { u8 value; } vol;
    s8 pan;
    u8 k;
    u8 i;
    u8 count;
    u8 slot;
    struct Src64FDC *src;

    src = list->items;
    count = list->count;
    for (i = 0; i <= count; src++, i++) {
        slot = 0xff;
        if (src->b[0] & 0x80) {
            for (j = 0; j < 0x40; j++) {
                if (lbl_801A6C80->entries[j].unk_0 == 0) {
                    slot = j;
                    break;
                }
            }
            lbl_801A6C80->entries[j].unk_0 = 1;
            lbl_801A6C80->entries[j].unk_1 = src->b[0];
            lbl_801A6C80->entries[j].unk_4 = src->b[2];
            lbl_801A6C80->entries[j].unk_5 = src->b[3];
            lbl_801A6C80->entries[j].unk_6 = src->b[0xa];
            lbl_801A6C80->entries[j].unk_7 = src->b[9];
            lbl_801A6C80->entries[j].unk_8 = src->b[0xb];
            lbl_801A6C80->entries[j].unk_9 = src->b[0xc];
            lbl_801A6C80->entries[j].unk_a = src->b[6];
            lbl_801A6C80->entries[j].unk_b = src->b[7];
            lbl_801A6C80->entries[j].unk_c = src->b[8];
            lbl_801A6C80->entries[j].unk_d = src->b[0xd];
            lbl_801A6C80->entries[j].unk_e = src->b[0xd];
            lbl_801A6C80->entries[j].unk_f = src->b[0xe];
            lbl_801A6C80->entries[j].unk_3 = src->b[1];
            lbl_801A6C80->entries[j].unk_18 = src->b;
            pan = 0;
            if (lbl_801A6C80->entries[slot].unk_1 & 2) {
                panRaw = lbl_801A6C80->chans[arg0].unk_9;
                vol.value = lbl_801A6C80->chans[arg0].unk_7;
                if (panRaw != 0x40) {
                    pan = ((s8)panRaw - 0x40) * 2;
                }
            } else {
                panRaw = lbl_801A6C80->chans[arg0].unk_8;
                vol.value = lbl_801A6C80->chans[arg0].unk_6;
                if (panRaw != 0x40) {
                    pan = ((s8)panRaw - 0x40) * 2;
                }
            }
            sum = (s8)vol.value + pan;
            if (sum < 0) {
                sum = 0;
            } else if (sum > 0x7f) {
                sum = 0x7f;
            }
            lbl_801A6C80->entries[j].unk_10 = sum;
            fn_80064FDC_link(arg0, slot);
        }
        if (slot != 0xff) {
            for (k = 0; k < 4; k++) {
                if (lbl_801A6C80->map[arg0][src->b[1]][k] & 1) {
                    lbl_801A6C80->map[arg0][src->b[1]][k] = slot;
                    break;
                }
            }
        }
    }
}
