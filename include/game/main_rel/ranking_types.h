#ifndef GAME_MAIN_REL_RANKING_TYPES_H
#define GAME_MAIN_REL_RANKING_TYPES_H

// Types (and the externs that name them) of ranking.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/ranking.h"

typedef struct {
    u32 flags;
    u32 value;
    u32 key;
} fn_1_1568C4_RankingState;

typedef struct {
    u32 flags;
    u8 _pad04[8];
    void *data0;
    void *data1;
    void *data2;
    s32 value;
    void *data3;
    void *data4;
} fn_1_156B18_State;

typedef struct {
    u32 flags;
    u8 _pad04[4];
    void *data;
} fn_1_1569A0_State;

typedef struct {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x2c];
    f32 unk_34;
    u8 pad_38[0x14];
    u8 unk_4c;
} Entry;

typedef struct {
    u32 flags;
    void *owner;
    u8 _pad08[8];
    u32 value;
    u8 _pad14[0x20];
    f32 speed;
    u8 _pad38[0x10];
    f32 impulse;
    u8 state_flags;
} fn_1_157070_RankingState;

typedef struct {
    u32 flags;
    void *arg04;
    u8 _pad08[0x14];
    u32 entry;
    u8 _pad20[0x18];
    f32 value;
    u8 _pad3c[0x10];
    u8 status;
} fn_1_157200_RankingState;

typedef struct {
    u32 flags;
    void *field04;
    u8 _pad08[0x18];
    void *data;
    u8 _pad24[0x0c];
    u8 value30;
    u8 _pad31[0x0f];
    f32 value40;
    u8 _pad44[8];
    u8 enabled4c;
} fn_1_157358_RankingState;

typedef struct {
    u32 flags;
    u32 unk_4;
    u8 pad_8[0x24];
    u32 unk_2c;
    u8 pad_30[0x1c];
    u8 unk_4c;
} Obj_fn_1_1576B4;

typedef struct {
    u32 flags;
    void *owner;
    u8 _pad08[0x20];
    u32 value;
    u8 _pad2c[0x20];
    u8 state;
} fn_1_157598_RankingState;

typedef struct {
    u8 field8;
    u8 _pad9[3];
    s32 fieldC;
    s32 field10;
    u8 field14;
    u8 field15;
    u8 field16;
    u8 field17;
    u16 field18;
    u16 field1A;
    u8 _pad1C[0x14];
} fn_1_1568C4_RankingConfig;

typedef struct {
    u8 unk_0;
    u8 pad_1[3];
    u32 unk_4;
    u32 unk_8;
    u8 unk_C;
    u8 pad_D;
    u16 unk_E;
    u16 unk_10;
    u16 unk_12;
    u16 unk_14;
    u8 pad_16[2];
    u32 unk_18;
    u32 unk_1C;
    u8 unk_20;
    u8 unk_21;
    u8 pad_22[2];
} Param_fn_1_1576B4;

typedef struct {
    u8 _pad00[4];
    void *owner;
    u8 _pad08[0x1c];
    u32 value;
} fn_1_1574E0_RankingState;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    s16 unk_8[16];
    s16 unk_28;
    s16 unk_2a;
} fn_1_159804_RankingEntry;

extern void fn_1_1568C4(fn_1_1568C4_RankingState *state);
extern void fn_1_156B18(fn_1_156B18_State *state);
extern void fn_1_1569A0(fn_1_1569A0_State *state);
extern void fn_1_156C08(Entry *);
extern void fn_1_156D9C(Entry *);
extern void fn_1_157070(fn_1_157070_RankingState *state);
extern void fn_1_156F54(Entry *);
extern void fn_1_157200(fn_1_157200_RankingState *state);
extern void fn_1_157358(fn_1_157358_RankingState *state);
extern void fn_1_1576B4(Obj_fn_1_1576B4 *obj);
extern void fn_1_157598(fn_1_157598_RankingState *state);
extern s16 fn_1_159804(s16 value, fn_1_159804_RankingEntry *entry);

#endif  // GAME_MAIN_REL_RANKING_TYPES_H
