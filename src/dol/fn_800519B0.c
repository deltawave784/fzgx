#include "types.h"

struct fn_800519B0_Arg2 { u32 unk_0; };
struct fn_800519B0_Arg3 {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u32 unk_4;
    u32 unk_8;
    u16 unk_C;
    s16 unk_E;
    u8 pad_10[0x2C];
    u8 unk_3C;
    u8 unk_3D;
};

#define READ16(p,o) (((p)[o] << 8) | (p)[(o)+1])
#define READ32(p,o) ((p)[(o)+3] | (((p)[(o)+2] << 8) | (((p)[o] << 24) | ((p)[(o)+1] << 16))))

s32 fn_800519B0(u32 arg0, u32 arg1, struct fn_800519B0_Arg2 *arg2, struct fn_800519B0_Arg3 *arg3) {
    u8 *data = (u8 *)arg0;
    s32 v7;
    u8 *v26;
    s32 v27;
    u8 *v29;
    s32 v30;
    u8 *unk_22;
    if (arg2 != 0) arg2->unk_0 = 0;
    if ((s32)arg1 < 4) return -1;
    if ((u16)READ16(data,0) != 32768) return -4;
    v7 = READ16(data,2);
    if (arg2 != 0) arg2->unk_0 = v7;
    if (arg3 == 0) return 0;
    if ((s32)arg1 < v7 + 4) return -2;
    v7 -= 6;
    if (v7 < 16) return -2;
    v7 -= 16;
    arg3->unk_0 = data[4];
    arg3->unk_1 = data[5];
    arg3->unk_2 = data[6];
    arg3->unk_3 = data[7];
    arg3->unk_4 = READ32(data,8);
    arg3->unk_8 = READ32(data,12);
    arg3->unk_C = READ16(data,16);
    arg3->unk_3C = data[18];
    arg3->unk_3D = data[19];
    if (v7 < 4) return -2;
    unk_22 = data + 24;
    arg3->unk_E = READ16(data,22);
    if (v7 < arg3->unk_E * 20) return -3;
    v26 = (u8 *)arg3;
    v27 = 0;
    while (v27 < arg3->unk_E) {
        v27++;
        *(u16 *)(v26+16) = READ16(unk_22,0);
        *(u16 *)(v26+18) = READ16(unk_22,2);
        *(u32 *)(v26+20) = READ32(unk_22,4);
        *(u32 *)(v26+24) = READ32(unk_22,8);
        *(u32 *)(v26+28) = READ32(unk_22,12);
        *(u32 *)(v26+32) = READ32(unk_22,16);
        v26 += 20;
    }
    v7 -= arg3->unk_E * 20;
    v29 = (u8 *)arg3;
    v30 = 0;
    while (v30 < (s8)arg3->unk_3) {
        if (v7 < 12) return 0;
        *(s16 *)(v29+36) = READ16(unk_22,0);
        if (*(s16 *)(v29+36) > 0)
            *(u16 *)(v29+38) = READ16(unk_22,2);
        *(u8 *)(v29+40) = unk_22[4];
        if (*(s8 *)(v29+40) > 0) *(u8 *)(v29+41) = unk_22[5];
        *(u8 *)(v29+42) = unk_22[6];
        if (*(s8 *)(v29+42) > 0) *(u8 *)(v29+43) = unk_22[7];
        *(u8 *)(v29+44) = unk_22[8];
        if (*(s8 *)(v29+44) > 0) *(u8 *)(v29+45) = unk_22[9];
        *(u8 *)(v29+46) = unk_22[10];
        if (*(s8 *)(v29+46) > 0) *(u8 *)(v29+47) = unk_22[11];
        unk_22 += 12;
        v7 -= 12;
        v29 += 12;
        v30++;
    }
    return 0;
}
