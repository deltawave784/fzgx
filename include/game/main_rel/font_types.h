#ifndef GAME_MAIN_REL_FONT_TYPES_H
#define GAME_MAIN_REL_FONT_TYPES_H

// Types (and the externs that name them) of font.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/font.h"
#include "runtime/va_list.h"
#include "font.h"

typedef struct FontParams {
    u8 unk_00[0x30];
    u32 unk_30;
    f32 unk_34;
    u8 unk_38[0x58 - 0x38];
} FontParams;

typedef struct fn_1_4EB74_FontObject {
    u32 unk_0;
    u8 pad_4[0x2c];
    u32 unk_30;
} fn_1_4EB74_FontObject;

typedef struct fn_1_54668_node {
    struct fn_1_54668_node *next;
    void *data;
} fn_1_54668_node;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct fn_1_547F8_node {
    struct fn_1_547F8_node *next;
    void (*callback)(struct fn_1_547F8_node *);
} fn_1_547F8_node;

typedef struct fn_1_563E4_FontState {
    u8 pad_00[8];
    f32 scale;
    u8 pad_0C[6];
    u8 enabled;
    u8 color;
    u32 value;
    f32 x;
    f32 y;
    u8 pad_20[4];
    u32 state;
} fn_1_563E4_FontState;

typedef struct State {
    FontDrawPacket *current;
    s32 warned;
    u8 unk_8[0x2028];
    s32 override_enabled, override_value;
    u32 texture[8];
} State;

typedef struct Config {
    u32 capacity;
    FontDrawPacket *packets;
    u8 unk_8[0x44];
    char warning[1];
} Config;

typedef struct ImageInfo {
    u8 unk_0[8];
    u16 width, height;
    u32 unk_C;
} ImageInfo;

typedef struct Images {
    u32 unk_0;
    ImageInfo *info;
    u32 unk_8;
    u32 (*textures)[8];
} Images;

typedef struct Resource {
    s32 loaded;
    u8 unk_4[0x1c];
    Images *images;
    u32 unk_24;
} Resource;

struct fn_1_530C8_lbl_1_rodata_282C {
    f32 unk_0;
};

struct FzgxCopy_88 { u32 words[22]; };

typedef struct {
    u8 pad_00[4];
    u32 unk_04;
    void *unk_08;
    u8 unk_0C[0x30];
    u16 unk_3C;
    u8 pad_3E[2];
    Obj_1_bss_6C7A4 unk_40;
    void *unk_68[4];
} Fn1_55EA0Object;

typedef struct fn_1_56470_FontState {
    u8 unk_00[4];
    void *unk_04;
    f32 unk_08;
    s8 unk_0C;
    u8 unk_0D;
    s8 unk_0E;
    u8 unk_0F;
    u8 unk_10;
    u8 unk_11;
    u8 unk_12;
    u8 unk_13;
    u32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    u32 unk_20;
    u32 unk_24;
} fn_1_56470_FontState;

extern void fn_1_563E4(fn_1_563E4_FontState *font);
extern void fn_1_55EA0(Fn1_55EA0Object *object);
extern void fn_1_56470(fn_1_56470_FontState *state);
extern s32 fn_1_4E724(FontParams *arg);
extern s32 fn_1_4EC74(FontParams *);
extern s32 fn_1_4EB74(fn_1_4EB74_FontObject *self);
extern struct fn_1_530C8_lbl_1_rodata_282C lbl_1_rodata_282C;
extern void fn_1_54668(fn_1_54668_node *node, s32 count, u32 reverse);
extern void fn_1_547F8(fn_1_547F8_node *node);

#endif  // GAME_MAIN_REL_FONT_TYPES_H
