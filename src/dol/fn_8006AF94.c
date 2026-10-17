#include "types.h"

typedef struct Fn8006AF94Flags {
    u8 flag7 : 1;
    u8 flag6 : 1;
    u8 rest : 6;
} Fn8006AF94Flags;

typedef struct Fn8006AF94Entry {
    u32 unk_0;
    Fn8006AF94Flags flags;
    u8 pad_5[7];
    u8 data_c[8];
    s8 state;
    u8 pad_15[0x38];
    s8 field_4d;
} Fn8006AF94Entry;

extern u8 lbl_80199670[18720];
extern void fn_800137C4(s32, void *);
extern void fn_8006AE90(void *, void *, void *);
extern s32 fn_8006C92C(void *);

#pragma opt_strength_reduction off
#pragma opt_propagation off
#pragma use_lmw_stmw on
void fn_8006AF94(void) {
    s32 offset;
    s32 i;
    u8 *base;
    Fn8006AF94Entry *entry;
    u8 *data;

    base = lbl_80199670;
    for (i = 0; i < 4; i++) {
        entry = (Fn8006AF94Entry *)(base + i * 0x1248);
        if (entry->flags.flag7) {
            data = (u8 *)entry + 0xc;
            fn_800137C4(i, data);
            switch (((s8 *)data)[8]) {
            case -1:
                entry->field_4d = -1;
                entry->flags.flag6 = 1;
                break;
            case 0:
                fn_8006AE90((u8 *)entry + 0x44, data, (u8 *)entry + 0x18);
                fn_8006C92C((u8 *)entry + 0x50);
                break;
            }
        }
    }
}
