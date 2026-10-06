#include "types.h"

struct Entry64D4C {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 pad_3[0xe];
    u8 unk_11;
    u8 unk_12;
    u8 unk_13;
    u8 unk_14;
    u8 unk_15;
    u8 pad_16[2];
    u32 unk_18;
    u32 unk_1c;
};
struct Data64D4C {
    u8 pad_0[0x588];
    struct Entry64D4C entries[0x40];
    u8 map[2][16][4];
};
extern struct Data64D4C *lbl_801A6C80;

void fn_80064D4C(u8 arg0, u8 arg1) {
    u8 i;
    u8 j;
    u8 index;
    u8 clear;
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 4; j++) {
            index = lbl_801A6C80->map[arg0][i][j];
            if (index != 0xff) {
                clear = 0;
                if (lbl_801A6C80->entries[index].unk_1 & 1) {
                    if (arg1 == 0) clear = 1;
                } else {
                    if (arg1 == 1) clear = 1;
                }
                if (clear) {
                    lbl_801A6C80->entries[index].unk_0 = 0;
                    lbl_801A6C80->entries[index].unk_1 = 0;
                    lbl_801A6C80->entries[index].unk_18 = 0;
                    lbl_801A6C80->entries[index].unk_1c = 0;
                    lbl_801A6C80->entries[index].unk_2 = 0;
                    lbl_801A6C80->entries[index].unk_11 = 0x40;
                    lbl_801A6C80->entries[index].unk_12 = 0;
                    lbl_801A6C80->entries[index].unk_13 = 0;
                    lbl_801A6C80->entries[index].unk_14 = 0;
                    lbl_801A6C80->entries[index].unk_15 = 0;
                    lbl_801A6C80->map[arg0][i][j] = 0xff;
                }
            }
        }
    }
}
