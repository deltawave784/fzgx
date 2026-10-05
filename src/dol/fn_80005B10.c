#include "types.h"

typedef struct GXColor {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} GXColor;

typedef f32 Mtx44[4][4];

extern GXColor lbl_801A6E58;
extern GXColor lbl_801A7908;
extern void *lbl_801A6D00;


extern void fn_800723F8(void);
extern void fn_8007245C(u32);
extern void fn_80074788(u32);
extern void fn_80074660(u32);
extern void fn_80073678(u32);
extern void fn_80073898(u32);
extern void fn_80073C6C(s32);
extern void fn_80072EDC(s32, s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern void fn_800371F8(u32, GXColor);
extern void fn_80074918(u8, s32, u8);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_800377F8(u32, GXColor, f32, f32, f32, f32);
extern void fn_80072864(u32);
extern void lbl_8006D758(void);
extern void GXLoadPosMtxImm(void *, u32);
extern void fn_80015EE8(Mtx44, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(Mtx44, s32);
extern void fn_80073778(void *, s32);
extern void fn_8003462C(u32, u32, u32);

/* GX write-gather FIFO */
#define GX_FIFO_F32 (*(volatile f32 *)((u8 *)0xCC010000 + -32768))  /* fzgx-allow: A1,A2 */

void fn_80005B10(void *arg0) {
    Mtx44 proj;
    GXColor color;
    f64 x0;
    f64 x1;
    f64 y0;
    f64 y1;
    f32 cx;
    f64 hw;
    f32 cy;
    f64 hh;

    color = lbl_801A6E58;
    fn_800723F8();
    fn_8007245C(0x2200);
    fn_800723F8();
    fn_80074788(0);
    fn_80074660(1);
    fn_80073678(1);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_80072EDC(0, 0);
    fn_800745A4(0, 1, 4, 60, 0, 125);
    fn_800734A8(0, 0, 0, 255);
    fn_80072AB0(0, 0, 0);
    fn_80072C24(0, 15, 2, 8, 4);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 1, 4, 2);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_800747D0(4, 0, 0, 0, 0, 2, 2);
    fn_800371F8(1, color);
    fn_80074918(1, 1, 1);
    fn_800728A8(1, 4, 5, 0);
    fn_800377F8(0, lbl_801A7908, 0.0f, 100.0f, 0.0f, 100.0f);
    fn_80072864(2);
    lbl_8006D758();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    fn_80015EE8(proj, 0.0f, 480.0f, 0.0f, 640.0f, 0.0f, 20000.0f);
    fn_800737E4(proj, 1);
    color.r = 255;
    color.g = 255;
    color.b = 255;
    color.a = 255;
    fn_800371F8(1, color);
    color.r = 0;
    color.g = 0;
    color.b = 0;
    color.a = 0;
    fn_800371F8(2, color);
    fn_80073778(arg0, 0);
    fn_8003462C(128, 7, 4);

    cx = 320.0f;
    hw = 320.0;
    cy = 240.0f;
    hh = 240.0;
    /* corner expressions repeated at each vertex; the compiler CSEs the repeats */
    GX_FIFO_F32 = cx - hw;
    GX_FIFO_F32 = cy - hh;
    GX_FIFO_F32 = -0.5f;
    GX_FIFO_F32 = 0.0f;
    GX_FIFO_F32 = 0.0f;
    GX_FIFO_F32 = hw + cx;
    GX_FIFO_F32 = cy - hh;
    GX_FIFO_F32 = -0.5f;
    GX_FIFO_F32 = 1.0f;
    GX_FIFO_F32 = 0.0f;
    GX_FIFO_F32 = hw + cx;
    GX_FIFO_F32 = hh + cy;
    GX_FIFO_F32 = -0.5f;
    GX_FIFO_F32 = 1.0f;
    GX_FIFO_F32 = 1.0f;
    GX_FIFO_F32 = cx - hw;
    GX_FIFO_F32 = hh + cy;
    GX_FIFO_F32 = -0.5f;
    GX_FIFO_F32 = 0.0f;
    GX_FIFO_F32 = 1.0f;
}
