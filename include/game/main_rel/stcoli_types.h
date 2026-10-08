#ifndef GAME_MAIN_REL_STCOLI_TYPES_H
#define GAME_MAIN_REL_STCOLI_TYPES_H

// Types (and the externs that name them) of stcoli.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/stcoli.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"

typedef struct Node {
    u32 unk_0;
    u8 pad_4[0x8];
    s32 count;
    struct Node *children;
    u8 pad_14[0x50 - 0x14];
} Node;

typedef struct StcoliNode StcoliNode;

struct StcoliNode {
    u32 flags;
    u8 pad[8];
    s32 count;
    StcoliNode *items;
    u8 rest[0x3c];
};

typedef struct StcoliVec {
    u32 x;
    u32 y;
    u32 z;
} StcoliVec;

typedef struct {
    unsigned char pad0[0x0c];
    int count;
    void *entries;
} Fn118F28Object;

typedef struct Fn_1_20258Constants {
    unsigned char pad08[8];
    f32 value08;
    f32 value0c;
    unsigned char pad10[0xb0];
    f64 valuec0;
    f32 valuec8;
    unsigned char padcc[4];
    f64 valued0;
} Fn_1_20258Constants;

typedef struct {
    u32 f00, f04, f08, f0c, f10, f14, f18, f1c, f20, f24;
    u32 f28, f2c, f30, f34, f38, f3c, f40, f44;
} Cfg;

typedef struct {
    u8 pad_0[0x4];
    Cfg *cfg;
    u8 pad_8[0xc];
    f32 fx;
    f32 fy;
    f32 fz;
    f32 rxv;
    f32 ryv;
    f32 rzv;
    f32 sxv;
    f32 syv;
    f32 szv;
} Entity;

typedef struct {
    u32 count;
    u32 entries[1];
} Stack;

struct fn_1_2B478_lbl_801A6D00 {
    u32 unk_0;
};

typedef struct { f32 x, y, z; } Vec3f;

typedef struct Fn_1_21950Constants {
    u8 pad_0[8];
    f32 zero;      /* 0x08 */
    u8 pad_c[0x14];
    f32 half;      /* 0x20 */
    u8 pad_24[0x10];
    f32 neg_half;  /* 0x34 */
} Fn_1_21950Constants;

typedef struct Fn_1_21950Vec {
    f32 x;
    f32 y;
    f32 z;
} Fn_1_21950Vec;

typedef struct Fn_1_28660 {
    int field00;
    short field04;
    unsigned char pad06[0x212];
    int field218;
    unsigned char pad21c[0x2e0];
    int field4fc;
    unsigned char pad500[0x8c];
    int field58c;
} Fn_1_28660;

struct fn_1_287E8_Arg0 {
    u32 flags;
    u8 pad_4[0x178];
    f32 unk_17C;
    u8 pad_180[0x10];
    u32 unk_190;
    u16 unk_194;
    u8 unk_196;
    u8 pad_197[0x65];
    f32 unk_1FC;
    f32 unk_200;
    u8 pad_204[0xE];
    u8 unk_212;
    u8 pad_213[0x26D];
    u8 unk_480;
    u8 pad_481[0x43];
    u8 unk_4C4;
};

typedef struct Fn_1_2A638 {
    unsigned char pad00[0x08];
    f32 field08;
    f32 field0c;
    f32 field10;
    unsigned char pad14[0x30];
    f32 field44;
    f32 field48;
} Fn_1_2A638;

typedef struct Fn_1_2A678_Values {
    int x;
    int y;
    int z;
} Fn_1_2A678_Values;

typedef struct Fn_1_2A678_Source {
    unsigned char pad00[0x7c];
    Fn_1_2A678_Values values;
} Fn_1_2A678_Source;

typedef struct Fn_1_2A678_Dest {
    unsigned char pad00[0xc];
    Fn_1_2A678_Values values;
} Fn_1_2A678_Dest;

typedef struct Part {
    u32 flags;
    u8 pad_4[0x5c - 0x4];
} Part;

typedef struct Body {
    u32 flags;
    u8 pad_4[0x4];
    f32 mass;
    u8 pad_C[0x10];
    f32 f1C;
    f32 f20;
    u8 pad_24[0x58];
    Vec3f pos;           /* 0x7C */
    Vec3f prevPos;       /* 0x88 */
    Vec3f vel;           /* 0x94 */
    u8 pad_A0[0x18];
    f32 fB8;
    u8 pad_BC[0x8];
    f32 fC4;
    f32 fC8;
    f32 fCC;
    f32 fD0;
    u8 pad_D4[0x18];
    f32 mtxEC[12];
    f32 mtx11C[12];
    u8 pad_14C[0x30];
    f32 f17C;
    u8 pad_180[0x4];
    f32 f184;
    u8 pad_188[0x58];
    Vec3f pos1E0;        /* 0x1E0 */
    u8 pad_1EC[0x8];
    f32 f1F4;
    f32 f1F8;
    f32 f1FC;
    u8 pad_200[0x4];
    f32 f204;
    u8 pad_208[0x10];
    u32 f218;
    u8 pad_21C[0x28];
    Part parts[4];       /* 0x244 */
    u8 pad_3B4[0xC8];
    u32 f47C;
    u8 pad_480[0x1];
    u8 b481;
    u8 pad_482[0x1];
    u8 b483;
    u8 pad_484[0x30];
    Vec3f v4B4;
    u8 b4C0;
    u8 pad_4C1[0x2];
    u8 b4C3;
    u8 pad_4C4[0x1];
    u8 b4C5;
    u8 pad_4C6[0x2];
    Vec3f pos4C8;        /* 0x4C8 */
    u8 pad_4D4[0xAC];
    f32 f580;
    u8 pad_584[0x8];
    u32 f58C;
    u8 pad_590[0x2];
    u8 b592;
    u8 b593;
    u8 pad_594[0x46];
    u16 h5DA;
} Body;

typedef struct { f32 x, y, z, w; } Quat;
typedef struct Sig_fn_1_2A694_V { f32 x; f32 y; f32 z; } Sig_fn_1_2A694_V;
typedef struct Sig_fn_1_2A694_N { u8 p[0x98]; u32 v98; u32 v9c; } Sig_fn_1_2A694_N;

typedef struct Sig_fn_1_2A694_O {
    u32 flags;
    s16 id;
    u8 p[0x8e];
    f32 f94;
    f32 f98;
    f32 f9c;
    f32 fa0;
    f32 fa4;
    f32 fa8;
    u8 p1[0xd0];
    f32 f17c;
    u8 p1b[4];
    f32 f184;
    u8 p1c[0x9c];
    f32 f224;
    u8 p2[0x24c];
    u8 v474;
    u8 p3[0x23];
    u32 field498;
    Sig_fn_1_2A694_N *field49c;
    u8 p4[0xec];
    u32 field58c;
} Sig_fn_1_2A694_O;

typedef struct ColiTarget {
    u8 p[0x390];
    u32 flags390;
} ColiTarget;

typedef struct {
    u8 pad[0x390];
    u32 f390;
} Fn2BA48_Other;

struct fn_1_2D038_Text {
    u32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    u32 pad_10[7];
    f32 unk_2C;
    u32 unk_30;
    u32 pad_34[9];
};

struct fn_1_2D524_Copy200 { u32 a[10][5]; };
struct fn_1_2D524_Copy8 { u32 a[2]; };

struct fn_1_2D524_lbl_1_rodata_BD8 {
    u8 pad_0[0x24];
    f32 unk_24;
    u8 pad_28[0x30];
    struct fn_1_2D524_Copy200 unk_58;
    struct fn_1_2D524_Copy8 unk_120;
    f32 unk_128;
    f32 unk_12C;
    f32 unk_130;
};

extern void fn_1_1902C(StcoliNode *root, StcoliVec *vec, void *arg3, f32 value);
extern void fn_1_18F28(Fn118F28Object *obj, int *args, int arg2, float value);
extern Fn_1_20258Constants lbl_1_rodata_6C8;
extern void fn_1_28660(Fn_1_28660 *self);
extern void fn_1_287E8(struct fn_1_287E8_Arg0 *p);
extern void fn_1_2A638(void *arg0, Fn_1_2A638 *self);
extern void fn_1_2A678(Fn_1_2A678_Source *self, Fn_1_2A678_Dest *dest);
extern u32 fn_1_2AF0C(Body *, void *);
extern void fn_8006E7E4(Quat *out, Vec3f *axis, s32 angle);
extern const struct fn_1_2D038_Text lbl_1_rodata_26F8;
extern struct fn_1_2D524_lbl_1_rodata_BD8 lbl_1_rodata_BD8;
extern void fn_1_17D5C(Node *node, u32 *acc);
extern struct fn_1_2B478_lbl_801A6D00 lbl_801A6D00;

#endif  // GAME_MAIN_REL_STCOLI_TYPES_H
