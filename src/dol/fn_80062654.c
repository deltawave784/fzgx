#include "types.h"
#include "dol/globals.h"
#pragma use_lmw_stmw on

extern u8 lbl_80192D68[1344];
extern void fn_80062360(u32 index, u32 value);
extern void fn_80060C54(u8 value, u8 *record, u32 index, u32 slot);
extern void fn_8005FBDC(u8 value);

struct fn_80062654_Entry {
    u8 state;
    u8 active;
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
    u8 count;
    u8 pad_d[3];
    u8 *record;
    u8 data[16][4];
};

#define entries ((struct fn_80062654_Entry *)lbl_80192D68)
#define ENTRY_SIZE sizeof(struct fn_80062654_Entry)

static inline void fn_80062654_update(u8 *e, u32 index, u32 value) {
    u32 j;
    u8 *script;
    if (e[1]) {
        script = *(u8 **)(e + 0x10);
        for (j = 0; (u8)j <= entries[index].count; j++) {
            if (script[4] <= value && script[5] >= value && value != 0) {
                fn_80060C54((u8)value, script, index, j);
            } else {
                if (entries[index].data[(u8)j][0] == 1) {
                    if (entries[index].data[(u8)j][2] != 0xff) {
                        fn_8005FBDC(entries[index].data[(u8)j][2]);
                    }
                    if (entries[index].data[(u8)j][3] != 0xff) {
                        fn_8005FBDC(entries[index].data[(u8)j][3]);
                    }
                    entries[index].data[(u8)j][0] = 0;
                }
            }
            script += *script;
        }
        lbl_80192D68[index * ENTRY_SIZE + 0xb] = value;
    } else {
        void (*callback)(s32, u32) = (void (*)(s32, u32))lbl_801A6C80->unk_5B1C;
        if (callback) {
            callback(-5, lbl_801A6C80->unk_444);
        }
    }
}

static inline void fn_80062654_refresh(u8 *e, u32 index) {
    if (e[1] && lbl_80192D68[index * ENTRY_SIZE + 0xb] != 0) {
        fn_80062654_update(e, index, lbl_80192D68[index * ENTRY_SIZE + 0xb]);
    }
}

/* Each parameter case owns its own entry pointer (one block-scoped local per site). */
#define SET_AND_REFRESH(off)                            \
    {                                                   \
        u8 *e = lbl_80192D68 + index * ENTRY_SIZE;      \
        e[off] = value;                                 \
        fn_80062654_refresh(e, index);                  \
    }

void fn_80062654(void) {
    u32 v0;
    u32 index;
    u32 value;
    u8 *item; /* shared by the two cases written out by hand */
    v0 = lbl_801A6C80->unk_444;
    index = (v0 >> 16) & 0xf;
    value = (v0 >> 8) & 0x7f;
    switch ((s32)(v0 & 0xff700000)) {
    case (s32)0xa5000000:
        fn_80062360(index, value);
        break;
    case (s32)0xa5100000:
        SET_AND_REFRESH(3);
        break;
    case (s32)0xa5200000:
        SET_AND_REFRESH(4);
        break;
    case (s32)0xa5300000:
        SET_AND_REFRESH(5);
        break;
    case (s32)0xa5400000:
        SET_AND_REFRESH(6);
        break;
    case (s32)0xa5500000:
        SET_AND_REFRESH(7);
        break;
    case (s32)0xa5700000:
        lbl_80192D68[index * ENTRY_SIZE + 2] = value;
        break;
    case (s32)0xa7000000:
        SET_AND_REFRESH(9);
        break;
    case (s32)0xa7100000:
        SET_AND_REFRESH(0xa);
        break;
    case (s32)0xa6100000:
        value += 0x80;
    case (s32)0xa6000000:
        item = lbl_80192D68 + index * ENTRY_SIZE;
        fn_80062654_update(item, index, value);
        break;
    case (s32)0xa7200000:
        *(s16 *)((u8 *)lbl_801A6C80 + 0x5a74 + index * 2) =
            *(s16 *)((u8 *)lbl_801A6C80 + 0x5af4 + index * 2);
        item = lbl_80192D68 + index * ENTRY_SIZE;
        fn_80062654_refresh(item, index);
        break;
    }
}
