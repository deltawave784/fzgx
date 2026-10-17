#include "types.h"
#include "dol/globals.h"

struct Sig_fn_800253F0_fn_800253F0_Arg0 { u32 unk_0; };
struct Sig_fn_80024D84_fn_80024D84_Arg0 {
    u8 pad_0[0x13C]; u8 unk_13C;
    f32 unk_140, unk_144, unk_148, unk_14C, unk_150;
};
struct Sig_fn_80024308_fn_80024308_Arg0 {
    u8 pad_0[0x1C4]; u8 unk_1C4;
    f32 unk_1C8, unk_1CC, unk_1D0, unk_1D4, unk_1D8, unk_1DC;
};
struct Sig_fn_800251F0_Sig_fn_80025440_fn_80025440_Arg0;
typedef struct Sig_fn_80025C28_Fn80025C28State {
    u8 _pad00[0x30]; u32 field30, field34, field38;
} Sig_fn_80025C28_Fn80025C28State;
struct Sig_fn_80024E3C_fn_80024E3C_Arg1;
struct Sig_fn_800243C4_fn_800243C4_Arg0;
struct Sig_fn_800243C4_fn_800243C4_Arg1;
typedef struct Sig_fn_80025854_Fn80025854Src Sig_fn_80025854_Fn80025854Src;
typedef struct Sig_fn_80025854_Fn80025854Args Sig_fn_80025854_Fn80025854Args;

extern u8 lbl_801939B4[340];
extern u8 lbl_80193680[480];
extern u8 lbl_80193404[156];
extern u8 lbl_80193308[96];
extern u8 lbl_80193860[340];
extern u8 lbl_801934A0[480];
extern u8 lbl_80193368[156];
extern u8 lbl_801932A8[96];
extern u32 fn_80024DF0(u32);
extern u32 fn_80024378(u32);
extern s32 fn_800253F0(struct Sig_fn_800253F0_fn_800253F0_Arg0 *);
extern s32 fn_80025C70(u32);
extern void fn_800211E0(u32, u32);
extern void fn_800211EC(u32, u32);
extern u32 lbl_801A6410;
extern u32 fn_800090A4(u32);
extern const f64 lbl_801A7320;
extern const f32 lbl_801A7318;
extern u32 fn_80024D84(struct Sig_fn_80024D84_fn_80024D84_Arg0 *);
extern u32 fn_80024E3C(u32, struct Sig_fn_80024E3C_fn_80024E3C_Arg1 *);
extern u32 fn_80024308(struct Sig_fn_80024308_fn_80024308_Arg0 *);
extern void fn_800243C4(struct Sig_fn_800243C4_fn_800243C4_Arg0 *, struct Sig_fn_800243C4_fn_800243C4_Arg1 *);
extern s32 fn_800251F0(struct Sig_fn_800251F0_Sig_fn_80025440_fn_80025440_Arg0 *);
extern void fn_80025504(u32, u32);
extern void fn_80025C28(Sig_fn_80025C28_Fn80025C28State *);
extern void fn_80025854(Sig_fn_80025854_Fn80025854Src *, Sig_fn_80025854_Fn80025854Args *);

#define FLAG0 (lbl_801A6C80->pad_448[0x28])
#define FLAG1 (lbl_801A6C80->pad_448[0x29])
#define KEY0 (lbl_801A6C80->pad_448[0x2A])
#define KEY1 (lbl_801A6C80->pad_448[0x2B])
#define HANDLE (*(s32 *)&lbl_801A6C80->pad_5B20[0])
#define WORD(obj, off) (*(u32 *)((obj) + (off)))
#define FLOAT(obj, off) (*(f32 *)((obj) + (off)))
#define STOP0() \
    switch (FLAG0) { \
    case 0: fn_80024DF0((u32)lbl_801939B4); break; \
    case 1: fn_80024378((u32)lbl_80193680); break; \
    case 2: fn_800253F0((struct Sig_fn_800253F0_fn_800253F0_Arg0 *)lbl_80193404); break; \
    case 3: fn_80025C70((u32)lbl_80193308); break; \
    } \
    fn_800211E0(0, 0)
#define STOP1() \
    switch (FLAG1) { \
    case 0: fn_80024DF0((u32)lbl_80193860); break; \
    case 1: fn_80024378((u32)lbl_801934A0); break; \
    case 2: fn_800253F0((struct Sig_fn_800253F0_fn_800253F0_Arg0 *)lbl_80193368); break; \
    case 3: fn_80025C70((u32)lbl_801932A8); break; \
    } \
    fn_800211EC(0, 0)
#define FAIL(flag, code) \
    flag = 255; \
    if (lbl_801A6C80->unk_5B1C != 0) \
        ((void (*)(s32, s32))lbl_801A6C80->unk_5B1C)(code, required - available)
#define COPY_FLOAT0(obj, src) \
    (obj)[0x13C] = 0; \
    FLOAT(obj, 0x148) = (f32)(src)[1] / lbl_801A7318; \
    FLOAT(obj, 0x150) = (f32)(src)[2] / lbl_801A7318; \
    FLOAT(obj, 0x14C) = (f32)(src)[3] / lbl_801A7318; \
    FLOAT(obj, 0x140) = (f32)(src)[4] / lbl_801A7318; \
    FLOAT(obj, 0x144) = (f32)(src)[5] / lbl_801A7318
#define COPY_FLOAT1(obj, src) \
    (obj)[0x1C4] = 0; \
    FLOAT(obj, 0x1D0) = (f32)(src)[1] / lbl_801A7318; \
    FLOAT(obj, 0x1D8) = (f32)(src)[2] / lbl_801A7318; \
    FLOAT(obj, 0x1D4) = (f32)(src)[3] / lbl_801A7318; \
    FLOAT(obj, 0x1C8) = (f32)(src)[4] / lbl_801A7318; \
    FLOAT(obj, 0x1CC) = (f32)(src)[5] / lbl_801A7318; \
    FLOAT(obj, 0x1DC) = (f32)(src)[6] / lbl_801A7318
#define COPY_INT2(obj, src) \
    WORD(obj, 0x90) = (src)[1]; \
    WORD(obj, 0x94) = (src)[2]; \
    WORD(obj, 0x98) = (src)[3]
#define COPY_INT3(obj, src) \
    WORD(obj, 0x3C) = (src)[1]; \
    WORD(obj, 0x40) = (src)[2]; \
    WORD(obj, 0x44) = (src)[3]; \
    WORD(obj, 0x48) = (src)[4]; \
    WORD(obj, 0x4C) = (src)[5]; \
    WORD(obj, 0x50) = (src)[6]; \
    WORD(obj, 0x54) = (src)[7]; \
    WORD(obj, 0x58) = (src)[8]; \
    WORD(obj, 0x5C) = (src)[9]
#define REQUIRED3(src) \
    (((src)[1] * 32 - 1) / 160 + ((src)[2] * 32 - 1) / 160 + ((src)[3] * 32 - 1) / 160) * 640

void fn_8006331C(u8 arg0, u8 arg1, f32 arg2) {
    u32 i;
    u32 found = 255;
    u32 *cursor;
    u32 *table;
    u32 *record;
    u32 offset;
    s32 available;
    s32 required;
    u8 *resource;

    if (arg0 != 255 || (arg0 == 255 && arg1 == 127)) {
        if (arg1 != 255) {
            if (arg1 != 127) {
                for (i = 0; i < 16; i++) {
                    if (*(u32 *)&lbl_801A6C80->unk_0[i][0] != 0xFFFFFFFF &&
                        arg0 == lbl_801A6C80->unk_0[i][14]) {
                        found = i;
                        break;
                    }
                }
                if (found == 255) return;
                if (KEY0 == arg0 && KEY1 == arg1) return;
                resource = (u8 *)((u32)lbl_801A6C80 + found * 16);
                resource = *(u8 **)(resource + 8);
                table = (u32 *)(resource + *(u32 *)(resource + 0x30));
                cursor = table;
                for (i = 0; i <= (u32)arg1; i++) cursor++;
                record = (u32 *)((u8 *)table + *cursor);
                STOP0();
                STOP1();
                FLAG0 = record[0] >> 24;
                FLAG1 = record[0] >> 16;
                KEY0 = arg0;
                KEY1 = arg1;
                if (HANDLE == -1) available = fn_800090A4(lbl_801A6410);
                else available = fn_800090A4(HANDLE);
                switch (FLAG0) {
                case 0:
                    COPY_FLOAT0(lbl_801939B4, record);
                    required = record[2] * 384 + 52536;
                    if (required <= available) {
                        fn_80024D84((struct Sig_fn_80024D84_fn_80024D84_Arg0 *)lbl_801939B4);
                        fn_800211E0((u32)fn_80024E3C, (u32)lbl_801939B4);
                    } else { FAIL(FLAG0, -1); }
                    offset = 20;
                    break;
                case 1:
                    COPY_FLOAT1(lbl_80193680, record);
                    required = record[2] * 384 + 81328;
                    if (required <= available) {
                        fn_80024308((struct Sig_fn_80024308_fn_80024308_Arg0 *)lbl_80193680);
                        fn_800211E0((u32)fn_800243C4, (u32)lbl_80193680);
                    } else { FAIL(FLAG0, -1); }
                    offset = 24;
                    break;
                case 2:
                    COPY_INT2(lbl_80193404, record);
                    required = 5760;
                    if (available >= 5760) {
                        fn_800251F0((struct Sig_fn_800251F0_Sig_fn_80025440_fn_80025440_Arg0 *)lbl_80193404);
                        fn_800211E0((u32)fn_80025504, (u32)lbl_80193404);
                    } else { FAIL(FLAG0, -1); }
                    offset = 12;
                    break;
                case 3:
                    COPY_INT3(lbl_80193308, record);
                    required = REQUIRED3(record);
                    if (required <= available) {
                        fn_80025C28((Sig_fn_80025C28_Fn80025C28State *)lbl_80193308);
                        fn_800211E0((u32)fn_80025854, (u32)lbl_80193308);
                    } else { FAIL(FLAG0, -1); }
                    offset = 36;
                    break;
                }
                if (HANDLE == -1) available = fn_800090A4(lbl_801A6410);
                else available = fn_800090A4(HANDLE);
                switch (FLAG1) {
                case 0: {
                    u32 *src = (u32 *)((u8 *)record + offset);
                    COPY_FLOAT0(lbl_80193860, src);
                    required = src[2] * 384 + 52536;
                    if (required <= available) {
                        fn_80024D84((struct Sig_fn_80024D84_fn_80024D84_Arg0 *)lbl_80193860);
                        fn_800211EC((u32)fn_80024E3C, (u32)lbl_80193860);
                    } else { FAIL(FLAG1, -2); }
                    break;
                }
                case 1: {
                    u32 *src = (u32 *)((u8 *)record + offset);
                    COPY_FLOAT1(lbl_801934A0, src);
                    required = src[2] * 384 + 81328;
                    if (required <= available) {
                        fn_80024308((struct Sig_fn_80024308_fn_80024308_Arg0 *)lbl_801934A0);
                        fn_800211EC((u32)fn_800243C4, (u32)lbl_801934A0);
                    } else { FAIL(FLAG1, -2); }
                    break;
                }
                case 2: {
                    u32 *src = (u32 *)((u8 *)record + offset);
                    COPY_INT2(lbl_80193368, src);
                    required = 5760;
                    if (available >= 5760) {
                        fn_800251F0((struct Sig_fn_800251F0_Sig_fn_80025440_fn_80025440_Arg0 *)lbl_80193368);
                        fn_800211EC((u32)fn_80025504, (u32)lbl_80193368);
                    } else { FAIL(FLAG1, -2); }
                    break;
                }
                case 3: {
                    u32 *src = (u32 *)((u8 *)record + offset);
                    COPY_INT3(lbl_801932A8, src);
                    required = REQUIRED3(src);
                    if (required <= available) {
                        fn_80025C28((Sig_fn_80025C28_Fn80025C28State *)lbl_801932A8);
                        fn_800211EC((u32)fn_80025854, (u32)lbl_801932A8);
                    } else { FAIL(FLAG1, -2); }
                    break;
                }
                }
            } else {
                STOP0();
                STOP1();
                FLAG0 = 255;
                FLAG1 = 255;
                KEY0 = 255;
                KEY1 = 255;
            }
        }
    }
}
