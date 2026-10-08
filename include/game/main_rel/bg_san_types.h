#ifndef GAME_MAIN_REL_BG_SAN_TYPES_H
#define GAME_MAIN_REL_BG_SAN_TYPES_H

// Types (and the externs that name them) of bg_san.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_san.h"

typedef struct {
    u8 unk_00[0x10];
    s32 unk_10;
} BgSanContext;

typedef struct {
    f32 x, y, z;
} Fn1DABB4_Vec;

typedef struct BgSanObject {
    u8 unk_00[0x10];
    s32 unk_10;
    void *unk_14;
    u8 unk_18[0x80c];
    f32 unk_824;
    f32 unk_828;
    f32 unk_82c;
} BgSanObject;

typedef struct BgSanPosition {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
} BgSanPosition;

typedef struct fn_1_DC3A4_Entry {
    u8 unk00[0x68];
    s32 initialized;
    u8 unk6c[0x40];
} fn_1_DC3A4_Entry;

typedef struct fn_1_DC3A4_Container {
    s32 count;
    fn_1_DC3A4_Entry entries[1];
} fn_1_DC3A4_Container;

typedef struct SanEntry {
    u8 unk00[0x08];
    u32 unk08;
    u8 unk0c[0x20];
    f32 value2c;
    f32 value30;
    f32 value34;
    u8 unk38[0x74];
} SanEntry;

typedef struct SanContainer {
    s32 count;
    SanEntry entries[1];
} SanContainer;

typedef struct fn_1_DC404_Entry {
    u8 data[0xac];
} fn_1_DC404_Entry;

typedef struct fn_1_DC404_Container {
    s32 count;
    fn_1_DC404_Entry entries[1];
} fn_1_DC404_Container;

struct fn_1_DA6A8_lbl_801A6410 {
    u32 unk_0;
};

struct Sig_fn_80077B64_fn_80077B64_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

struct Sig_fn_80077B14_fn_80077B14_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x18];
    u32 unk_20;
};

extern const Fn1DABB4_Vec lbl_1_rodata_662C;
extern void fn_1_DB138(BgSanContext *context);
extern void fn_1_DB198(BgSanObject *object, void *arg1);
extern void *fn_1_5448C(BgSanPosition *position);
extern void fn_1_DC3A4(fn_1_DC3A4_Container *container);
extern void fn_1_DC454(SanContainer *container, void *arg);
extern void fn_1_DC404(fn_1_DC404_Container *container);
extern struct fn_1_DA6A8_lbl_801A6410 lbl_801A6410;
extern void * fn_80077B64(struct Sig_fn_80077B64_fn_80077B64_Arg0 *);
extern s32 fn_80077B14(struct Sig_fn_80077B14_fn_80077B14_Arg0 *);

#endif  // GAME_MAIN_REL_BG_SAN_TYPES_H
