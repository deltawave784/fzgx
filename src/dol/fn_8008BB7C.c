#include "types.h"
#include "dolphin/trk.h"
#pragma use_lmw_stmw on

typedef void (*fn_8008BB7C_Fn0)(void *, void *);
typedef void (*fn_8008BB7C_Fn1)(void *, void *);
typedef void (*fn_8008BB7C_Fn2)(void *, void *);
typedef void (*fn_8008BB7C_Fn3)(void *, void *);
typedef void (*fn_8008BB7C_Fn4)(void *, void *);
struct fn_8008BB7C_lbl_80095B30 {
    u32 unk_0; u32 unk_4; u32 unk_8; u32 unk_C; u32 unk_10;
    u32 unk_14; u32 unk_18; u32 unk_1C; u32 unk_20; u32 unk_24;
};
typedef struct TRKExceptionStatus {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
} TRKExceptionStatus;

extern TRKExceptionStatus gTRKExceptionStatus;
extern u32 lbl_80095B30[10];
extern struct fn_8008BB7C_lbl_80095B30 lbl_80095B58;
extern u8 lbl_801A5624[20];
extern void fn_8008AFF0(u32, u32);

s32 fn_8008BB7C(u32 arg0, u32 arg1, u32 arg2, void *arg3, u32 arg4) {
    TRKExceptionStatus *p_gTRKExceptionStatus;
    TRKExceptionStatus save;
    struct { u32 a[2]; } loc_C;
    u32 loc_8;
    s32 v0;
    u32 v23;
    u32 v24;
    if (arg1 > 31) {
        return 1793;
    }
    p_gTRKExceptionStatus = &gTRKExceptionStatus;
    save = *p_gTRKExceptionStatus;
    p_gTRKExceptionStatus->unkD = 0;
    {
        struct fn_8008BB7C_lbl_80095B30 loc_C4 = *(struct fn_8008BB7C_lbl_80095B30 *)lbl_80095B30;
        loc_C4.unk_0 = 0x7C98E2A6;
        loc_C4.unk_4 = 0x90830000;
        loc_C4.unk_24 = 0x4E800020;
        fn_8008AFF0((u32)&loc_C4, 40);
        ((fn_8008BB7C_Fn0)&loc_C4)(&loc_8, lbl_801A5624);
    }
    loc_8 |= 0xA0000000;
    {
        struct fn_8008BB7C_lbl_80095B30 loc_9C = *(struct fn_8008BB7C_lbl_80095B30 *)lbl_80095B30;
        loc_9C.unk_0 = 0x8083U << 16; /* lwz r4,0(r3) instruction */
        loc_9C.unk_4 = 0x7C98E3A6;
        loc_9C.unk_24 = 0x4E800020;
        fn_8008AFF0((u32)&loc_9C, 40);
        ((fn_8008BB7C_Fn1)&loc_9C)(&loc_8, lbl_801A5624);
    }
    loc_8 = 0;
    {
        struct fn_8008BB7C_lbl_80095B30 loc_74 = *(struct fn_8008BB7C_lbl_80095B30 *)lbl_80095B30;
        loc_74.unk_0 = 0x8083U << 16; /* lwz r4,0(r3) instruction */
        loc_74.unk_4 = 0x7C90E3A6;
        loc_74.unk_24 = 0x4E800020;
        fn_8008AFF0((u32)&loc_74, 40);
        ((fn_8008BB7C_Fn2)&loc_74)(&loc_8, lbl_801A5624);
    }
    *(u32 *)arg3 = 0;
    v0 = 0;
    v23 = arg0;
    while (v23 <= arg1 && v0 == 0) {
        if ((s32)arg4 != 0) {
            u32 opcode;
            u32 w8;
            u32 w7;
            u32 w6;
            u32 w5;
            u32 w4;
            u32 w3;
            u32 w2;
            u32 w1;
            u32 w0;
            volatile u32 *p; /* volatile: preserve the instruction template snapshot load order */
            u32 w9;
            u32 loc_4C[10];
            p = (volatile u32 *)&lbl_80095B58; /* volatile: snapshot executable instruction words in order */
            w0 = p[0];
            w1 = p[1];
            w2 = p[2];
            w3 = p[3];
            w4 = p[4];
            w5 = p[5];
            w6 = p[6];
            w7 = p[7];
            w8 = p[8];
            w9 = p[9];
            loc_4C[0] = w0;
            loc_4C[1] = w1;
            loc_4C[2] = w2;
            loc_4C[3] = w3;
            loc_4C[4] = w4;
            loc_4C[5] = w5;
            loc_4C[6] = w6;
            loc_4C[7] = w7;
            loc_4C[8] = w8;
            loc_4C[9] = w9;
            opcode = (v23 << 21) | 0xE0030000;
            if ((s32)arg4 != 0) {
                opcode = (v23 << 21) | 0xF0030000;
            }
            loc_4C[0] = opcode;
            loc_4C[9] = 0x4E800020;
            fn_8008AFF0((u32)&loc_4C, 40);
            ((fn_8008BB7C_Fn3)&loc_4C)(&loc_C, lbl_801A5624);
            v0 = TRKAppendBuffer1_ui64((TRKBuffer *)arg2, *(u64 *)&loc_C);
        } else {
            TRKReadBuffer1_ui64((TRKBuffer *)arg2, (u64 *)&loc_C);
            {
                u32 opcode;
                u32 w8;
                u32 w7;
                u32 w6;
                u32 w5;
                u32 w4;
                u32 w3;
                u32 w2;
                u32 w1;
                u32 w0;
                volatile u32 *p; /* volatile: preserve the instruction template snapshot load order */
                u32 w9;
                u32 loc_24[10];
                p = (volatile u32 *)&lbl_80095B58; /* volatile: snapshot executable instruction words in order */
                w0 = p[0];
                w1 = p[1];
                w2 = p[2];
                w3 = p[3];
                w4 = p[4];
                w5 = p[5];
                w6 = p[6];
                w7 = p[7];
                w8 = p[8];
                w9 = p[9];
                loc_24[0] = w0;
                loc_24[1] = w1;
                loc_24[2] = w2;
                loc_24[3] = w3;
                loc_24[4] = w4;
                loc_24[5] = w5;
                loc_24[6] = w6;
                loc_24[7] = w7;
                loc_24[8] = w8;
                loc_24[9] = w9;
                opcode = (v23 << 21) | 0xE0030000;
                if ((s32)arg4 != 0) {
                    opcode = (v23 << 21) | 0xF0030000;
                }
                loc_24[0] = opcode;
                loc_24[9] = 0x4E800020;
                fn_8008AFF0((u32)&loc_24, 40);
                ((fn_8008BB7C_Fn4)&loc_24)(&loc_C, lbl_801A5624);
                v0 = 0;
            }
        }
        v23++;
        *(u32 *)arg3 += 8;
    }
    if (p_gTRKExceptionStatus->unkD != 0) {
        *(u32 *)arg3 = 0;
        v0 = 1794;
    }
    gTRKExceptionStatus = save;
    return v0;
}
