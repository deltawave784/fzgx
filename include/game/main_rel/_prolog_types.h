#ifndef GAME_MAIN_REL__PROLOG_TYPES_H
#define GAME_MAIN_REL__PROLOG_TYPES_H

// Types (and the externs that name them) of _prolog.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"

/* lbl_1_data_7C0: 0x2c-byte overlay descriptors (callbacks at 0x20/0x24/0x28), indexed by the overlay id */
typedef void (*fn_1_ECC_Callback)(void);
typedef void (*fn_1_ECC_Callback)(void);

struct fn_1_ECC_Overlay {
    u8 pad_0[0x20];
    fn_1_ECC_Callback init;
    fn_1_ECC_Callback update;
    fn_1_ECC_Callback exit;
};

struct fn_1_798_slot {
    u8 unk_0[8];
    s32 value_8;
    u8 unk_C[0x3C];
};

struct ArenaData {
    u32 *arena_lo;
    u32 arena_lo_size;
    u32 *aligned_lo;
    u32 aligned_lo_size;
};

struct fn_1_634_lbl_1_bss_54 {
    u32 unk_0;
};

struct fn_1_904_lbl_1_bss_4 {
    u32 unk_0;
};

struct fn_1_914_lbl_1_bss_0 {
    u32 unk_0;
};

struct fn_1_12B4_lbl_1_bss_962 {
    s16 unk_0;
};

struct fn_1_3C98_lbl_1_bss_DA5 {
    u8 unk_0;
};

struct fn_1_48B0_lbl_801A6CF8 {
    u32 unk_0;
};

struct fn_1_4438_lbl_1_bss_DC4 {
    u32 unk_0;
};

struct fn_1_ECC_Scene {
    u8 pad_0[0x20];
    fn_1_ECC_Callback init;
    fn_1_ECC_Callback update;
    fn_1_ECC_Callback suspend;
    fn_1_ECC_Callback exit;
};

typedef struct fn_1_4374_Node fn_1_4374_Node;

struct fn_1_4374_Node {
    u32 field_0;
    u32 field_4;
    fn_1_4374_Node *next;
    fn_1_4374_Node *prev;
};

struct fn_1_4404_lbl_1_bss_DC0 {
    u32 unk_0;
};

struct fn_1_44B4_lbl_1_bss_DB8 {
    u8 pad_0[0x8];
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
};

typedef struct {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} Fn1_4730Entry;

extern struct fn_1_ECC_Overlay lbl_1_data_7C0[];
extern struct fn_1_ECC_Scene lbl_1_data_460[];
extern struct fn_1_44B4_lbl_1_bss_DB8 lbl_1_bss_DB8;
extern struct fn_1_798_slot lbl_1_bss_8E7E4[];
extern struct ArenaData lbl_1_data_8;
extern struct fn_1_634_lbl_1_bss_54 lbl_1_bss_54;
extern struct fn_1_904_lbl_1_bss_4 lbl_1_bss_4;
extern struct fn_1_914_lbl_1_bss_0 lbl_1_bss_0;
extern struct fn_1_12B4_lbl_1_bss_962 lbl_1_bss_962;
extern struct fn_1_3C98_lbl_1_bss_DA5 lbl_1_bss_DA5;
extern struct fn_1_48B0_lbl_801A6CF8 lbl_801A6CF8;
extern struct fn_1_4438_lbl_1_bss_DC4 lbl_1_bss_DC4;
extern void fn_1_4374(fn_1_4374_Node **list, fn_1_4374_Node *node);
extern struct fn_1_4404_lbl_1_bss_DC0 lbl_1_bss_DC0;
extern Fn1_4730Entry lbl_1_bss_DCC[32];

#endif  // GAME_MAIN_REL__PROLOG_TYPES_H
