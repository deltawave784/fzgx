#include "types.h"

struct fn_800764A0_Arg0 {
    u32 unk_0;
};
struct fn_800764A0_lbl_801A3220 {
    u8 pad_0[0x3C];
    u32 unk_3C;
    u32 unk_40;
};
struct fn_800764A0_lbl_801A6D00_T {
    u8 pad_0[0xC];
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
};

extern const f32 lbl_801A7480;
extern const f32 lbl_801A7488;
extern const f32 lbl_801A748C;
extern const f32 lbl_801A749C;
extern u8 lbl_801A3220[];
extern struct fn_800764A0_lbl_801A6D00_T *lbl_801A6D00;
extern void GXLoadTexMtxImm(void *, u32, u32);
extern u32 fn_800736C0(u32, void *);
extern void lbl_8006DAEC(void);
extern u8 lbl_8015AD28[];
extern void fn_8006F120(void *, void *);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_800735C8(s32, s32);
extern void fn_80073C6C(s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void lbl_8006DB30(void);
extern void lbl_8006E14C(f32);

void fn_800764A0(struct fn_800764A0_Arg0 *arg0, void * arg1, u32 arg2) {
    struct fn_800764A0_lbl_801A3220 *p_lbl_801A3220;
    s32 v0;
    s32 v1;
    f32 v2;
    u32 v3;
    struct Color { u8 r, g, b, a; } color, loc_8;
    fn_80073C6C(arg0->unk_0);
    fn_80072AB0(*(u32 *)((u8 *)(u32)arg0 + 0), 0, 0);
    p_lbl_801A3220 = (struct fn_800764A0_lbl_801A3220 *)lbl_801A3220;
    if ((s32)p_lbl_801A3220->unk_3C == 0) {
    lbl_8006DAEC();
    v0 = 30;
    v1 = 0;
    lbl_801A6D00->unk_C = lbl_801A7480;
    lbl_801A6D00->unk_1C = lbl_801A7480;
    lbl_801A6D00->unk_2C = lbl_801A7480;
    GXLoadTexMtxImm(lbl_801A6D00, v0, v1);
    lbl_8006DB30();
    p_lbl_801A3220->unk_3C = 1;
    }
    p_lbl_801A3220 = (struct fn_800764A0_lbl_801A3220 *)lbl_801A3220;
    if ((s32)p_lbl_801A3220->unk_40 == 0) {
    lbl_8006DAEC();
    fn_8006F120(lbl_8015AD28, lbl_801A3220 + 80);
    lbl_801A6D00->unk_C = lbl_801A748C;
    lbl_801A6D00->unk_10 = (f32)(lbl_801A6D00->unk_10 * lbl_801A749C);
    lbl_801A6D00->unk_14 = (f32)(lbl_801A6D00->unk_14 * lbl_801A749C);
    v2 = (f32)(lbl_801A6D00->unk_18 * lbl_801A749C);
    lbl_801A6D00->unk_18 = v2;
    lbl_801A6D00->unk_1C = lbl_801A748C;
    lbl_801A6D00->unk_20 = lbl_801A7480;
    lbl_801A6D00->unk_24 = lbl_801A7480;
    lbl_801A6D00->unk_28 = lbl_801A7480;
    lbl_801A6D00->unk_2C = lbl_801A7488;
    lbl_8006E14C(lbl_801A748C);
    GXLoadTexMtxImm(lbl_801A6D00, 64, 0);
    lbl_8006DB30();
    p_lbl_801A3220->unk_40 = 1;
    }
    color.r = arg2;
    color.g = arg2;
    color.b = arg2;
    color.a = arg2;
    fn_800734A8(*(u32 *)((u8 *)(u32)arg0 + 0), *(u32 *)((u8 *)(u32)arg0 + 4), *(u32 *)((u8 *)(u32)arg0 + 12), 4);
    loc_8 = color;
    fn_800736C0(0, (void *)&loc_8);
    fn_800735C8(*(u32 *)((u8 *)(u32)arg0 + 0), 12);
    fn_800745A4(*(u32 *)((u8 *)(u32)arg0 + 4), 0, 1, 30, 1, 64);
    fn_80072C24(*(u32 *)((u8 *)(u32)arg0 + 0), 15, 8, 14, 15);
    fn_80072D64(*(u32 *)((u8 *)(u32)arg0 + 0), 0, 0, 0, 1, 2);
    fn_80072CC4(*(u32 *)((u8 *)(u32)arg0 + 0), 7, 7, 7, *(u32 *)((u8 *)arg1 + 12));
    fn_80072E20(*(u32 *)((u8 *)(u32)arg0 + 0), 0, 0, 0, 1, 2);
    (*(u32 *)((u8 *)(u32)arg0 + 0))++;
    (*(u32 *)((u8 *)(u32)arg0 + 4))++;
    fn_80073C6C(*(u32 *)((u8 *)(u32)arg0 + 0));
    fn_80072AB0(*(u32 *)((u8 *)(u32)arg0 + 0), 0, 0);
    fn_800734A8(*(u32 *)((u8 *)(u32)arg0 + 0), 255, 255, 255);
    fn_80072C24(*(u32 *)((u8 *)(u32)arg0 + 0), 15, 4, 10, *(u32 *)((u8 *)arg1 + 8));
    fn_80072D64(*(u32 *)((u8 *)(u32)arg0 + 0), 0, 0, 0, 1, 0);
    fn_80072CC4(*(u32 *)((u8 *)(u32)arg0 + 0), 7, 7, 7, 2);
    fn_80072E20(*(u32 *)((u8 *)(u32)arg0 + 0), 0, 0, 0, 1, 0);
    v3 = *(u32 *)((u8 *)(u32)arg0 + 0);
    *(u32 *)((u8 *)(u32)arg0 + 0) = (v3 + 1);
}
