#ifndef GAME_MAIN_REL_SPLINE_TYPES_H
#define GAME_MAIN_REL_SPLINE_TYPES_H

// Types (and the externs that name them) of spline.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/spline.h"

typedef struct Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec4;

typedef struct {
    s16 unk_0;
    s16 unk_2;
    s16 unk_4;
    s16 unk_6;
    s16 unk_8;
} Element;

typedef struct {
    Element elements[44];
} fn_1_F9028_Table;

struct fn_1_FA6C0_lbl_1_rodata_7480 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
};

typedef struct {
    u8 data[0x180];
} SplineEntry;

struct fn_1_F8DC4_Table {
    u32 values[4][6];
};

typedef struct {
    u8 flag;          // 0x00
    u8 pad[0x43];
    f32 mtx[4][12];   // 0x44
    u32 x[4];         // 0x104
    u32 y[4];         // 0x114
    u32 w[4];         // 0x124
    u32 h[4];         // 0x134
    u32 halfW[4];     // 0x144
    u32 halfH[4];     // 0x154
    f32 scale;        // 0x164
} SplineViewport;

typedef struct {
    u32 unk_0;
    SplineViewport vp;
} SplineViewportHolder;

typedef struct {
    Element elements[44];
} Table;

extern void fn_1_FA1D8(s32, s32, SplineEntry *);
extern struct fn_1_F8DC4_Table lbl_1_rodata_6FF0;
extern void fn_1_F5A2C(Vec4 *dst, const Vec4 *a, const Vec4 *b, f32 t);
extern struct fn_1_FA6C0_lbl_1_rodata_7480 lbl_1_rodata_7480;
extern void fn_1_FA89C(SplineViewportHolder *holder);
extern void fn_8006E8DC(Vec4 *arg0);

#endif  // GAME_MAIN_REL_SPLINE_TYPES_H
