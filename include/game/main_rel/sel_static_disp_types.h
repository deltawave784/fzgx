#ifndef GAME_MAIN_REL_SEL_STATIC_DISP_TYPES_H
#define GAME_MAIN_REL_SEL_STATIC_DISP_TYPES_H

// Types (and the externs that name them) of sel_static_disp.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"
#include "font.h"

typedef struct {
    u32 v[8];
} Word8;

typedef struct {
    u8 pad0[0x4];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad18[0x18];
    s32 unk_30;
    u8 pad34[0x24];
} Sp8;

typedef struct {
    u32 value[22];
} Fn139F18Data;

typedef struct StaticDispParams {
    s32 id;
    f32 x;
    f32 y;
    f32 z;
    u32 unk1[8];
    s32 count;
    u32 unk2[9];
} StaticDispParams;

struct Struct_26F8 {
    u32 unk00;
    f32 unk04;
    f32 unk08;
    f32 unk0C;
    u8 pad10[0x1C];
    f32 unk2C;
    u32 unk30;
    u8 pad34[4];
    u32 unk38;
    u8 pad3C[0x1C];
};

typedef struct {
    const char *p[9];
} PtrTab;

struct fn_1_13F8C4_lbl_801A6410 {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E43C {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E440 {
    u32 unk_0;
};

typedef struct {
    s16 indices[2];
    u8 pad8[4];
    u32 flags;
} Source;

typedef struct {
    s16 index;
    u8 pad2[0x1e];
    char text[0x320];
    void *object;
    void *handle[4];
} Display;

struct Sig_fn_80071718_fn_80071718_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

struct Sig_fn_800711A8_fn_800711A8_Entry {
    u8 pad_00[0x24];
    void *field_24;
};

struct Sig_fn_800711A8_fn_800711A8_Arg0 {
    s32 count;
    u8 pad_04[4];
    struct Sig_fn_800711A8_fn_800711A8_Entry **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

typedef struct {
    u8 data[4];
    f32 value;
    u8 tail[8];
} Fn1_14E9E4Entry;

typedef struct fn_1_150C8C_Entry {
    u8 pad[0x68];
    u32 active;
    u8 tail[0x40];
} fn_1_150C8C_Entry;

typedef struct fn_1_150C8C_Object {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150C8C_Entry entries[1];
} fn_1_150C8C_Object;

typedef struct fn_1_150F30_StaticDisp {
    u8 pad_2728[0x2728];
    s32 unk_2728;
    s32 unk_272c;
} fn_1_150F30_StaticDisp;

typedef struct Fn14E09CValue {
    void *value;
} Fn14E09CValue;

typedef struct Fn14E09CRef {
    u8 pad8[8];
    Fn14E09CValue *value;
} Fn14E09CRef;

typedef struct Fn14E09CObj {
    u8 pad344[0x344];
    Fn14E09CRef *ref;
} Fn14E09CObj;

typedef struct DispNode {
    u8 pad[4];
    f32 value;
} DispNode;

typedef struct DispChildList {
    DispNode *child[3];
} DispChildList;

typedef struct DispObject {
    u32 flags;
    u8 pad0[12];
    f32 value;
    u8 pad1[32];
    DispChildList *children;
} DispObject;

typedef struct fn_1_151668_StaticDispEntry {
    f32 first;
    u8 pad0[0x18];
    f32 values[3];
    DispObject *object;
    u8 active;
    u8 scale_first;
    u8 scale_second;
    u8 clear_flag;
    u8 pad2[0x0c];
} fn_1_151668_StaticDispEntry;

typedef struct fn_1_151668_StaticDisp {
    u8 pad0[0x1830];
    fn_1_151668_StaticDispEntry entries[63];
    u8 pad1[0x30];
    s32 entry_count;
    s32 value_2728;
    s32 value_272c;
} fn_1_151668_StaticDisp;

struct fn_1_142BDC_lbl_1_rodata_92C0 {
    u8 pad_0[0x108];
    f32 unk_108;
    u8 pad_10C[0x1C];
    f64 unk_128;
    u8 pad_130[0x68];
    f32 unk_198;
    f32 unk_19C;
    f32 unk_1A0;
    f32 unk_1A4;
    f32 unk_1A8;
    f32 unk_1AC;
    f32 unk_1B0;
};

typedef struct fn_1_14E09C_Fn14E09CValue {
    void *value;
} fn_1_14E09C_Fn14E09CValue;

typedef struct fn_1_14E09C_Fn14E09CRef {
    u8 pad8[8];
    fn_1_14E09C_Fn14E09CValue *value;
} fn_1_14E09C_Fn14E09CRef;

typedef struct fn_1_14E09C_Fn14E09CObj {
    u8 pad344[0x344];
    fn_1_14E09C_Fn14E09CRef *ref;
} fn_1_14E09C_Fn14E09CObj;

typedef struct fn_1_150CEC_Entry {
    u8 data[0xac];
} fn_1_150CEC_Entry;

typedef struct fn_1_150CEC_Object {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150CEC_Entry entries[1];
} fn_1_150CEC_Object;

typedef struct fn_1_150ED0_Entry {
    u8 data[0xac];
} fn_1_150ED0_Entry;

typedef struct fn_1_150ED0_Object {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150ED0_Entry entries[1];
} fn_1_150ED0_Object;

struct Elem { u8 pad_0[0xe]; s16 unk_E; u8 pad_10[0x10]; };
struct Arg { s16 index; u8 pad_2[0x22]; u8 *unk_24; u8 pad_28[0x10]; f32 f[6]; };

typedef struct {
    f32 a0, a1, a2, a3, a4, a5;
    f32 pad[6];
    s32 i30;
    f32 rest[9];
} SelLocal;

struct fn_1_13A460_Copy88 { f32 a[22]; };
struct fn_1_13A654_Copy88 { f32 a[22]; };

typedef struct fn_1_14E09C_fn_1_14E09C_Fn14E09CValue {
    void *value;
} fn_1_14E09C_fn_1_14E09C_Fn14E09CValue;

typedef struct fn_1_14E09C_fn_1_14E09C_Fn14E09CRef {
    u8 pad8[8];
    fn_1_14E09C_fn_1_14E09C_Fn14E09CValue *value;
} fn_1_14E09C_fn_1_14E09C_Fn14E09CRef;

typedef struct fn_1_14E09C_fn_1_14E09C_Fn14E09CObj {
    u8 pad344[0x344];
    fn_1_14E09C_fn_1_14E09C_Fn14E09CRef *ref;
} fn_1_14E09C_fn_1_14E09C_Fn14E09CObj;

typedef struct E {
    u8 pad0[8];
    u32 flags;
    u8 pad1[0x2c - 0xc];
    f32 x, y, z;
    u8 pad2[0xac - 0x38];
} E;

typedef struct H {
    u8 pad[0x84];
    s32 count;
    E e[1];
} H;

struct A7 { u16 v[7]; };
struct B6 { u16 v[6]; };
extern Word8 lbl_1_rodata_86D8;
extern PtrTab lbl_1_rodata_8C4C;
extern struct fn_1_149C64_lbl_1_bss_8E43C lbl_1_bss_8E43C;
extern struct fn_1_149C64_lbl_1_bss_8E440 lbl_1_bss_8E440;
extern void fn_1_14D728(Source *source, Display *displays);
extern Fn1_14E9E4Entry *fn_1_14F608(int arg0);
extern void fn_1_150C8C(fn_1_150C8C_Object *obj);
extern void fn_1_150F30(fn_1_150F30_StaticDisp *self);
extern void fn_1_150D3C(H *h, void *arg);
extern void fn_1_151668(fn_1_151668_StaticDisp *self);
extern void fn_1_150CEC(fn_1_150CEC_Object *obj);
extern void fn_1_150ED0(fn_1_150ED0_Object *obj, void *arg);
extern struct A7 lbl_1_rodata_922C;
extern struct B6 lbl_1_rodata_923C;

#endif  // GAME_MAIN_REL_SEL_STATIC_DISP_TYPES_H
