#include "types.h"

typedef struct {
    u8 pad0[0x14];
    u32 x;
    u32 y;
    u32 pad1c;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2c;
    u32 unk30;
    u32 unk34;
    u8 pad1[0x950];
    s16 half[128];
    s16 extra[128];
} Sig_fn_80025D5C_Fn80025D5CObject;

typedef struct { u32 words[24]; } Fn80025E18Entry;
extern u32 lbl_80176160[];
extern void fn_80025D5C(Sig_fn_80025D5C_Fn80025D5CObject *);
extern u32 lbl_801A6B80;
extern u32 lbl_801A6B84;
extern u32 lbl_801A6B88[2];

void fn_80025E18(void) {
    s32 i;
    for (i = 0; i < 64; i++) {
        u8 *p = (u8 *)&((Fn80025E18Entry *)lbl_80176160)[i];
        *(u32 *)(p + 4) = 0x50000000;
        *(u32 *)(p + 8) = 0;
        *(s32 *)(p + 12) = -960;
        *(s32 *)(p + 16) = -960;
        *(u32 *)(p + 28) = 0;
        *(u32 *)(p + 20) = 64;
        *(u32 *)(p + 24) = 127;
        *(s16 *)(p + 56) = *(s16 *)(p + 60) =
        *(s16 *)(p + 64) = *(s16 *)(p + 68) =
        *(s16 *)(p + 72) = *(s16 *)(p + 76) =
        *(s16 *)(p + 80) = *(s16 *)(p + 84) =
        *(s16 *)(p + 88) = *(s16 *)(p + 92) = 0;
        fn_80025D5C((Sig_fn_80025D5C_Fn80025D5CObject *)p);
    }
    lbl_801A6B80 = 0;
    lbl_801A6B84 = 0;
    lbl_801A6B88[0] = 1;
}
