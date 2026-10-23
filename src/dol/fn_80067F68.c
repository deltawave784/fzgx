#include "types.h"
#include "dol/globals.h"

struct fn_80067F68_lbl_801A6C80_T {
    u8 pad_0[0x104];
    u32 unk_104[16];
    u32 unk_144[16];
    u8 unk_184[16];
    u8 pad_194[0x18];
    u32 unk_1AC[16];
    u32 unk_1EC[16];
    u8 unk_22C[16];
    u8 pad_23C[4];
    u32 unk_240[64];
    u32 unk_340[64];
    u8 unk_440;
    u8 unk_441;
    u8 unk_442;
    u8 unk_443;
    u32 unk_444;
    u32 unk_448;
    u32 unk_44C;
    u8 pad_450[9];
    u8 unk_459;
    u8 unk_45A;
    u8 pad_45B[2];
    u8 unk_45D;
    u8 unk_45E;
    u8 unk_45F;
    u8 unk_460;
    u8 unk_461;
    u8 unk_462;
    u8 unk_463;
    u8 unk_464;
    u8 unk_465;
    u8 pad_466[2];
    u32 unk_468;
    u32 unk_46C;
    u8 unk_470;
    u8 unk_471;
    u8 unk_472;
    u8 unk_473;
    u8 pad_474[0xD14];
    struct {
        u8 unk_0;
        u8 pad_1[0x27];
    } unk_1188[16];
    struct {
        u8 unk_0;
        u8 unk_1;
        u8 pad_2[7];
        u8 unk_9;
        u8 unk_A;
        u8 pad_B[0x11];
        u32 unk_1C;
        u32 unk_20;
        u8 pad_24[8];
        u32 unk_2C;
        u8 pad_30[0xE8];
    } unk_1408[64];
    u8 pad_5A08[8];
    u16 unk_5A10;
    u16 unk_5A12;
    u16 unk_5A14[16];
    u16 unk_5A34[16];
    u16 unk_5A54[16];
    u16 unk_5A74[16];
    u16 unk_5A94[16];
    u16 unk_5AB4[16];
    u16 unk_5AD4[16];
    u16 unk_5AF4[16];
    u8 pad_5B14[4];
    u32 unk_5B18;
    u32 unk_5B1C;
    u32 unk_5B20;
};

#define STATE ((struct fn_80067F68_lbl_801A6C80_T *)lbl_801A6C80)
extern void fn_8006A1F8(void);

void fn_80067F68(void) {
    u32 i, j;
    STATE->unk_440 = 0;
    STATE->unk_441 = 0;
    STATE->unk_442 = 0;
    STATE->unk_443 = 0;
    lbl_801A6C80->unk_444 = 0;
    STATE->unk_459 = 0;
    STATE->unk_44C = 1;
    STATE->unk_45D = 1;
    STATE->unk_45A = 0;
    STATE->unk_448 = 0;
    STATE->unk_468 = 0;
    STATE->unk_45F = 0;
    STATE->unk_460 = 0;
    STATE->unk_461 = 127;
    STATE->unk_462 = 1;
    STATE->unk_463 = 1;
    STATE->unk_45E = 64;
    STATE->unk_464 = 0;
    STATE->unk_470 = 255;
    STATE->unk_471 = 255;
    STATE->unk_472 = 255;
    STATE->unk_473 = 255;
    STATE->unk_46C = 0;
    STATE->unk_465 = 0;
    STATE->unk_5B18 = 0;
    lbl_801A6C80->unk_5B1C = 0;
    STATE->unk_5B20 = -1;
    for (i = 0; i < 64; i++) {
        STATE->unk_240[i] = 0;
        STATE->unk_340[i] = 0;
    }
    for (i = 0; i < 64; i++) {
        STATE->unk_1408[i].unk_0 = 255;
        STATE->unk_1408[i].unk_1C = 0;
        STATE->unk_1408[i].unk_20 = 0;
        STATE->unk_1408[i].unk_2C = 0;
        STATE->unk_1408[i].unk_1 = 0;
        STATE->unk_1408[i].unk_9 = 255;
        STATE->unk_1408[i].unk_A = 255;
    }
    for (i = 0; i < 64; i++) {
        lbl_801A6C80->unk_588[i][0] = 0;
        lbl_801A6C80->unk_588[i][2] = 0;
        lbl_801A6C80->unk_588[i][0x11] = 64;
        lbl_801A6C80->unk_588[i][0x12] = 0;
        lbl_801A6C80->unk_588[i][0x13] = 0;
        lbl_801A6C80->unk_588[i][0x14] = 0;
        lbl_801A6C80->unk_588[i][0x15] = 0;
    }
    for (i = 0; i < 16; i++) {
        *(u32 *)&lbl_801A6C80->unk_0[i][0] = -1;
        *(u32 *)&lbl_801A6C80->unk_0[i][8] = 0;
        lbl_801A6C80->unk_0[i][13] = 255;
        lbl_801A6C80->unk_0[i][14] = 255;
        lbl_801A6C80->unk_48C[i][4] = 255;
        lbl_801A6C80->unk_48C[i][6] = 127;
        lbl_801A6C80->unk_48C[i][7] = 127;
        lbl_801A6C80->unk_48C[i][8] = 64;
        lbl_801A6C80->unk_48C[i][9] = 64;
        lbl_801A6C80->pad_100[i + 0x84] = 0;
        STATE->unk_104[i] = 0;
        STATE->unk_144[i] = 0;
        lbl_801A6C80->pad_100[i + 0x12C] = 0;
        STATE->unk_1AC[i] = 0;
        STATE->unk_1EC[i] = 0;
        for (j = 0; j < 16; j++) {
            u32 k;
            for (k = 0; k < 4; k++) {
                lbl_801A6C80->unk_D88[i][j][k] = 255;
            }
        }
    }
    for (i = 0; i < 16; i++) {
        STATE->unk_1188[i].unk_0 = 0;
    }
    STATE->unk_5A10 = 0;
    STATE->unk_5A12 = 0;
    for (i = 0; i < 16; i++) {
        STATE->unk_5A14[i] = 0;
        STATE->unk_5A34[i] = 0;
        STATE->unk_5A54[i] = 0;
        STATE->unk_5AB4[i] = 0;
        STATE->unk_5AD4[i] = 0;
    }
    for (i = 0; i < 16; i++) {
        STATE->unk_5A74[i] = 0;
        STATE->unk_5A94[i] = 0;
        STATE->unk_5AF4[i] = 0;
    }
    fn_8006A1F8();
}
