#ifndef GAME_MAIN_REL_SHADOWMAP_TYPES_H
#define GAME_MAIN_REL_SHADOWMAP_TYPES_H

// Types (and the externs that name them) of shadowmap.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/shadowmap.h"
#include "psvec.h"

typedef struct fn_1_568F8_Color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} fn_1_568F8_Color;

typedef struct fn_1_568F8_Vec3 {
    f32 x;
    f32 y;
    f32 z;
} fn_1_568F8_Vec3;

typedef struct fn_1_568F8_Pool {
    fn_1_568F8_Color tev_color;  // 0x00
    f32 zero;                    // 0x04
    fn_1_568F8_Vec3 axis_x;      // 0x08
    fn_1_568F8_Vec3 axis_y;      // 0x14
    fn_1_568F8_Vec3 axis_z;      // 0x20
    fn_1_568F8_Vec3 up;          // 0x2c
    fn_1_568F8_Color clear_color;  // 0x38
    fn_1_568F8_Color chan_color;   // 0x3c
    f32 neg_three;               // 0x40
    f32 one;                     // 0x44
    f32 twenty;                  // 0x48
    f32 three;                   // 0x4c
    f32 hundred;                 // 0x50
    f32 size;                    // 0x54
} fn_1_568F8_Pool;

typedef struct fn_1_568F8_Data {
    u8 pad_0[0x38c];
    u8 light_mask;               // 0x38c
    u8 pad_38d[0x2b];
    s16 light_param;             // 0x3b8
} fn_1_568F8_Data;

typedef struct fn_1_568F8_Mtx44 {
    f32 m[4][4];
} fn_1_568F8_Mtx44;

extern fn_1_568F8_Pool lbl_1_rodata_28B0;
extern void fn_1_870BC(fn_1_568F8_Data *, s8, fn_1_568F8_Data *, s32, u8, f32);
extern void fn_80015EE8(fn_1_568F8_Mtx44 *, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(fn_1_568F8_Mtx44 *, s32);
extern void fn_800744F8(fn_1_568F8_Color, u32);
extern void fn_800725DC(fn_1_568F8_Color);
extern void fn_80072614(fn_1_568F8_Color);

#endif  // GAME_MAIN_REL_SHADOWMAP_TYPES_H
