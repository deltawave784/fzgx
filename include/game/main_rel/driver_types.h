#ifndef GAME_MAIN_REL_DRIVER_TYPES_H
#define GAME_MAIN_REL_DRIVER_TYPES_H

// Types (and the externs that name them) of driver.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/driver.h"

typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;
} DriverAsset;

struct fn_1_A7F84_lbl_1_rodata_4A28 {
    f32 unk_0;
};

typedef struct FnA8528Config {
    u8 pad_0c[0x0c];
    f32 unk_0c;
    u8 pad_10[0x0c];
    f32 unk_1c;
    u8 pad_20[0x0c];
    f32 unk_2c;
} FnA8528Config;

struct fn_1_A7F84_lbl_801A6D00 {
    u32 unk_0;
};

struct fn_1_A9868_lbl_801A6D00 {
    u32 unk_0;
};

typedef struct FnA861CCamera {
    u8 pad_0[0xdc];
    f32 yaw;      /* 0xdc */
    f32 roll;     /* 0xe0 */
    f32 pitch;    /* 0xe4 */
    u8 unk_e8;
    u8 unk_e9;
    u8 pad_ea[0x15c - 0xea];
    u8 unk_15c[4];
} FnA861CCamera;

typedef struct {
    signed char gpr;
    signed char fpr;
    unsigned short reserved;
    char *input_arg_area;
    char *reg_save_area;
} Sig_parse_format_MkVaListState;

typedef Sig_parse_format_MkVaListState Sig_parse_format_va_list;

typedef struct {
    u8 kind;
    u8 callback;
    u8 flags;
    u8 pad3;
    s16 x;
    s16 y;
    s16 z;
    s16 padA;
    void *data;
} Fn1A9250Entry;

struct fn_1_A9868_lbl_1_rodata_4AA0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    f32 unk_30;
};

typedef struct Sig_fn_80015EE8_Fn80015EE8Out {
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 f4;
    f32 f5;
    f32 f6;
    f32 f7;
    f32 f8;
    f32 f9;
    f32 f10;
    f32 f11;
    f32 f12;
    f32 f13;
    f32 f14;
    f32 f15;
} Sig_fn_80015EE8_Fn80015EE8Out;

struct Sig_fn_800737E4_fn_800737E4_Arg0 {
    f32 unk_0;
    u8 pad_4[0x4];
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[0x4];
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    u8 pad_20[0x8];
    f32 unk_28;
    f32 unk_2C;
};

typedef struct FnA861CVehicle {
    u8 pad_0[8];
    f32 unk_8;
    u8 pad_c[0xa4 - 0xc];
    f32 unk_a4;
    u8 pad_a8[0xb0 - 0xa8];
    f32 unk_b0;
    u8 pad_b4[0xb8 - 0xb4];
    f32 unk_b8;
    u8 pad_bc[0xc0 - 0xbc];
    f32 unk_c0;
} FnA861CVehicle;

typedef struct FnA8834Camera {
    u8 pad_0[0x90];
    u8 unk_90[0x48];
    f32 unk_d8;
    f32 unk_dc;
    u8 pad_e0[4];
    f32 unk_e4;
    u8 pad_e8[0x18c - 0xe8];
    u8 unk_18c[4];
} FnA8834Camera;

typedef struct FnA8834Vehicle {
    u8 pad_0[8];
    f32 unk_8;
    u8 pad_c[0xa4 - 0xc];
    f32 unk_a4;
    u8 pad_a8[0xb0 - 0xa8];
    f32 unk_b0;
    u8 pad_b4[0xc0 - 0xb4];
    f32 unk_c0;
    u8 pad_c4[0x1fc - 0xc4];
    f32 unk_1fc;
} FnA8834Vehicle;

extern struct fn_1_A7F84_lbl_1_rodata_4A28 lbl_1_rodata_4A28;
extern FnA8528Config *lbl_801A6D00;
extern Fn1A9250Entry lbl_1_bss_70658[];
extern struct fn_1_A9868_lbl_1_rodata_4AA0 lbl_1_rodata_4AA0;
extern f32 fn_80015EE8(Sig_fn_80015EE8_Fn80015EE8Out *, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(struct Sig_fn_800737E4_fn_800737E4_Arg0 *, s32, f32);
extern void fn_1_A861C(FnA861CCamera *cam, FnA861CVehicle *veh);
extern void fn_1_A8834(FnA8834Camera *cam, FnA8834Vehicle *veh);

#endif  // GAME_MAIN_REL_DRIVER_TYPES_H
