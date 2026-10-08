#ifndef GAME_MAIN_REL_MOTASGLIST_TYPES_H
#define GAME_MAIN_REL_MOTASGLIST_TYPES_H

// Types (and the externs that name them) of motasglist.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/motasglist.h"
#include "dolphin/hw_regs.h"

typedef struct fn_1_41BDC_MotasglistData {
    u8 pad_00[0x26];
    u8 count;
    u8 pad_27;
    void *entries;
    u8 pad_2c[0x08];
    void *fallback;
    u8 pad_38[0x14];
    u8 fallback_base;
} fn_1_41BDC_MotasglistData;

typedef struct Sig_fn_1_41488_Fn41488Data {
    u32 count;
    char *strings;
} Sig_fn_1_41488_Fn41488Data;

typedef struct Sig_fn_1_41328_RelocData {
    u32 count;
    u32 values[1];
} Sig_fn_1_41328_RelocData;

typedef struct Fn142AD0Pair {
    u32 a;
    u32 b;
} Fn142AD0Pair;

typedef struct Fn142AD0Entry {
    u8 pad0[0x88];
    u8 value88[0x0C];
    f32 x;
    u8 pad98[0x0C];
    f32 y;
    u8 padA8[0x0C];
    f32 z;
    Fn142AD0Pair sourceB8;
    u32 sourceC0;
    Fn142AD0Pair sourceC4;
    u32 sourceCC;
    u8 padD0[4];
    u16 keys[6][2][3];
    u32 keysF[3][2][3];
    u8 quat[0x10];
    Fn142AD0Pair value174;
    u32 value17C;
    Fn142AD0Pair value180;
    u32 value188;
} Fn142AD0Entry;

typedef struct Fn142AD0Key {
    u16 value0;
    u16 value1;
    u16 value2;
    u16 value3;
    f32 value4;
    f32 value5;
    f32 value6;
} Fn142AD0Key;

typedef struct Fn142AD0Object {
    u16 count;
    u16 flags;
    u8 pad4[4];
    Fn142AD0Entry *entries;
    u8 padC[0x20];
    f32 value2C;
    f32 value30;
    f32 value34;
    f32 value38;
    u8 pad3C[4];
    Fn142AD0Key cur;
    u8 pad54[4];
    Fn142AD0Key prev;
} Fn142AD0Object;

typedef struct Fn1433A4Object {
    u16 value0;
    u16 value1;
    u16 value2;
    u16 value3;
    f32 value4;
    f32 value5;
    f32 value6;
} Fn1433A4Object;

typedef struct Fn142E74Pair {
    u32 a;
    u32 b;
} Fn142E74Pair;

typedef struct Fn142E74Entry {
    u8 pad0[0xB8];
    Fn142E74Pair sourceB8;
    u32 sourceC0;
    Fn142E74Pair sourceC4;
    u32 sourceCC;
    u8 padD0[0xA4];
    Fn142E74Pair value174;
    u32 value17C;
    Fn142E74Pair value180;
    u32 value188;
} Fn142E74Entry;

typedef struct Fn142E74Object {
    u16 count;
    u16 flags;
    u8 pad4[4];
    Fn142E74Entry *entries;
    u8 padC[0x0C];
    f32 value0;
    f32 value1;
    f32 value2;
    u8 pad24[0x1C];
    u16 flags40;
} Fn142E74Object;

typedef struct Fn1433E0Vec {
    f32 x;
    f32 y;
    f32 z;
} Fn1433E0Vec;

typedef struct Fn1433E0Quat {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Fn1433E0Quat;

typedef struct Fn1433E0Entry {
    u8 pad0[4];
    u16 flags;
    u16 parent;
    u8 pad8[0xC];
    f32 value14;
    Fn1433E0Vec offset18;
    f32 value24;
    u8 pad28[0x60];
    u8 mtx[0x30];
    Fn1433E0Vec scale;
    Fn1433E0Vec offsetC4;
    u8 padD0[0x94];
    Fn1433E0Quat quat;
    Fn1433E0Vec value174;
    Fn1433E0Vec value180;
} Fn1433E0Entry;

typedef struct Fn1433E0Object {
    u16 count;
    u16 flags;
    u8 pad4[4];
    Fn1433E0Entry *entries;
    Fn1433E0Vec scale;
    Fn1433E0Vec offset;
    u8 pad24[4];
    f32 frame;
    f32 duration;
    Fn1433E0Vec prev;
} Fn1433E0Object;

typedef struct Fn14300CObject {
    u8 pad0[2];
    u16 flags;
    f32 value;
    u8 pad1[0x38];
} Fn14300CObject;

typedef struct Fn143058Object {
    u16 count;
    u16 flags;
    u8 pad4[4];
    u8 *entries;
    u8 padC[0xC];
    f32 value0;
    f32 value1;
    f32 value2;
} Fn143058Object;

struct fn_1_41850_lbl_801A6410 {
    u32 unk_0;
};

extern int fn_1_41488(Sig_fn_1_41488_Fn41488Data *, const char *);
extern void fn_1_4270C(Fn142AD0Object *object, void *arg1, u32 arg2);
extern void fn_1_433A4(Fn1433A4Object *dst, Fn1433A4Object *src);
extern void fn_1_438AC(Fn142E74Object *object, Fn142E74Entry *entry, s32 arg2);
extern void fn_1_433E0(Fn1433E0Object *object);
extern void fn_1_4300C(Fn14300CObject *object);
extern void fn_1_43E08(Fn143058Object *object, u8 *entry, void *arg2, void *arg3, f32 value);
extern struct fn_1_41850_lbl_801A6410 lbl_801A6410;
extern void fn_8006E8DC(Fn1433E0Quat *);
extern void fn_8006EB4C(Fn1433E0Quat *, Fn1433E0Quat *, Fn1433E0Quat *, f32);

#endif  // GAME_MAIN_REL_MOTASGLIST_TYPES_H
