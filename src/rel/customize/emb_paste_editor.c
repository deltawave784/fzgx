#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/emb_paste_editor.h"

struct InputEntry { u16 unk_0; u8 pad_2[0x12]; };

struct InputState {
 union {
  struct { u8 pad8[8]; struct InputEntry unk_8[1]; };
  struct { u8 pad10[0x10]; struct InputEntry unk_10[1]; };
  struct { u8 pad12[0x12]; struct InputEntry unk_12[1]; };
 };
};

struct fn_3_10B68_lbl_1_bss_9F8_8_E20 {
    u16 unk_0;
    u8 pad_2[0x12];
};

struct fn_3_10B68_lbl_1_bss_9F8_12_E20 {
    u16 unk_0;
    u8 pad_2[0x12];
};

struct fn_3_10B68_lbl_1_bss_9F8 {
    union {
        struct { u8 pad_view_unk_8[0x8]; struct fn_3_10B68_lbl_1_bss_9F8_8_E20 unk_8[1]; };
        struct { u8 pad_view_unk_12[0x12]; struct fn_3_10B68_lbl_1_bss_9F8_12_E20 unk_12[1]; };
    };
};

struct Sig_fn_8004E278_fn_8004E278_Arg0 {
    u32 unk_0;
};
extern struct fn_3_10B68_lbl_1_bss_9F8 lbl_1_bss_9F8;
extern void fn_1_A2D84(u32 arg0);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern u32 fn_3_11A38(void);
extern u8 lbl_3_bss_8F200[];
extern void fn_1_FC414(void *arg0, void *arg1);
extern u8 lbl_3_bss_A1778[12];
extern s16 lbl_1_bss_96A;
extern void fn_1_4A00(s32 fadeIn, u8 steps, u32 arg);
extern void fn_1_FDFF4(void);
extern u32 fn_1_435C(u32 value);
extern void fn_1_426C(u32 idx);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);

/* fzgx:begin fn_3_104C4 noprologue */
#include "types.h"
#include "rel/customize/emb_paste_editor.h"

struct InputEntry { u16 unk_0; u8 pad_2[0x12]; };
struct InputState {
 union {
  struct { u8 pad8[8]; struct InputEntry unk_8[1]; };
  struct { u8 pad10[0x10]; struct InputEntry unk_10[1]; };
  struct { u8 pad12[0x12]; struct InputEntry unk_12[1]; };
 };
};
extern struct InputState lbl_1_bss_9F8;
extern void fn_1_A2D84(u32);
extern void fn_80008BEC(void *, int, u32);
#pragma opt_pointer_analysis on
static inline struct InputEntry *array_read(struct InputEntry *array) { return array; }
static inline void finish(Obj_3_bss_7EDD8 *q, u32 state) {
 q->unk_10 = q->unk_C;
 q->unk_C = state;
 lbl_3_bss_7EDD8.unk_18 = 0;
}
void fn_3_104C4(void) {
 Obj_3_bss_7EDD8 *p;
 u16 v;
 u32 index;
 u32 slot;
 u32 previous;
 u32 state;
 p = (Obj_3_bss_7EDD8 *)&lbl_3_bss_7EDD8;
 if ((array_read(lbl_1_bss_9F8.unk_12)[index = p->unk_14].unk_0 & 1) ||
     (lbl_1_bss_9F8.unk_10[index].unk_0 & 1)) {
  if ((s32)lbl_3_bss_7EDD8.unk_18 == 0) fn_1_A2D84(0xA9010000);
  lbl_3_bss_7EDD8.unk_18 = 1;
 }
 if (((array_read(lbl_1_bss_9F8.unk_12)[index = p->unk_14].unk_0 >> 1) & 1) ||
     ((lbl_1_bss_9F8.unk_10[index].unk_0 >> 1) & 1)) {
  if ((s32)lbl_3_bss_7EDD8.unk_18 == 1) fn_1_A2D84(0xA9010000);
  lbl_3_bss_7EDD8.unk_18 = 0;
 }
 v = lbl_1_bss_9F8.unk_8[*(volatile u8 *)&p->unk_14].unk_0; /* Retail reloads the input selector. */
 if (((v >> 9) & 1) || (((v >> 8) & 1) && (s32)lbl_3_bss_7EDD8.unk_18 == 0)) {
  if ((lbl_1_bss_9F8.unk_8[*(volatile u8 *)&p->unk_14].unk_0 >> 8) & 1) /* Retail reloads the input selector. */
   fn_1_A2D84(0xA9010100);
  else fn_1_A2D84(0xA9010200);
  lbl_3_bss_7EDD8.unk_18 = 0;
  lbl_3_bss_7EDD8.unk_C = 0x40000000;
 }
 if (((lbl_1_bss_9F8.unk_8[*(volatile u8 *)&p->unk_14].unk_0 >> 8) & 1) && (s32)lbl_3_bss_7EDD8.unk_18 != 0) { /* Retail reloads the input selector. */
  fn_1_A2D84(0xA9010100);
  slot = (u32)&lbl_3_bss_7EE40;
  index = lbl_3_bss_7EDD8.unk_15;
  slot += index * 0x2060;
  if (((Obj_3_bss_7EE40 *)slot)->unk_24 & 0x80000000)
   *((u32 *)&lbl_3_bss_7EDD8.unk_2C + index) = 1;
  fn_80008BEC((u8 *)&lbl_3_bss_7EE40 + lbl_3_bss_7EDD8.unk_15 * 0x2060 + 0x20, 0, 0x2060);
  fn_80008BEC((u8 *)&lbl_3_bss_87040 + lbl_3_bss_7EDD8.unk_15 * 0x2060 + 0x20, 0, 0x2060);
  finish(&lbl_3_bss_7EDD8, 0x40000000);
 }
}
#pragma opt_pointer_analysis reset
/* fzgx:end fn_3_104C4 */

/* fzgx:begin fn_3_10B68 */
struct fn_3_10B68_lbl_3_bss_7EDD8 {
    u8 pad_0[0x14];
    u8 unk_14;
    u8 unk_15;
    u8 pad_16[0x2];
    u32 unk_18;
};


#pragma opt_pointer_analysis on
static inline struct fn_3_10B68_lbl_1_bss_9F8_12_E20 *fn_3_10B68_array_read(struct fn_3_10B68_lbl_1_bss_9F8_12_E20 *array) { return array; }
void fn_3_10B68(void) {
    struct fn_3_10B68_lbl_3_bss_7EDD8 *p_lbl_3_bss_7EDD8;
    u16 v0;
    void * v1;
    p_lbl_3_bss_7EDD8 = (struct fn_3_10B68_lbl_3_bss_7EDD8 *)&(*((struct fn_3_10B68_lbl_3_bss_7EDD8 *)&lbl_3_bss_7EDD8));
    if ((fn_3_10B68_array_read(lbl_1_bss_9F8.unk_12)[(*(u8 volatile *)&(p_lbl_3_bss_7EDD8->unk_14)) /* Retail reloads this field. */].unk_0 & 0x1) != 0) {
    p_lbl_3_bss_7EDD8->unk_18 = 1;
    fn_1_A2D84(0xA9010000);
    }
    if (((fn_3_10B68_array_read(lbl_1_bss_9F8.unk_12)[(*(u8 volatile *)&(p_lbl_3_bss_7EDD8->unk_14)) /* Retail reloads this field. */].unk_0 >> 1) & 0x1) != 0) {
    (*((struct fn_3_10B68_lbl_3_bss_7EDD8 *)&lbl_3_bss_7EDD8)).unk_18 = 0;
    fn_1_A2D84(0xA9010000);
    }
    v0 = lbl_1_bss_9F8.unk_8[(*(u8 volatile *)&(p_lbl_3_bss_7EDD8->unk_14)) /* Retail reloads this field. */].unk_0;
    if (((v0 >> 9) & 0x1) != 0 || (((v0 >> 8) & 0x1) != 0 && (s32)(*((struct fn_3_10B68_lbl_3_bss_7EDD8 *)&lbl_3_bss_7EDD8)).unk_18 == 0)) {
    if (((lbl_1_bss_9F8.unk_8[(*(u8 volatile *)&(p_lbl_3_bss_7EDD8->unk_14)) /* Retail reloads this field. */].unk_0 >> 8) & 0x1) != 0) {
    fn_1_A2D84((0xA9010000 + 256));
    } else {
    fn_1_A2D84((0xA9010000 + 512));
    }
    v1 = (void *)(((u8 *)&(*((struct fn_3_10B68_lbl_3_bss_7EDD8 *)&lbl_3_bss_7EDD8)) + ((*((struct fn_3_10B68_lbl_3_bss_7EDD8 *)&lbl_3_bss_7EDD8)).unk_15 << 2)));
    *(u32 *)((u8 *)v1 + 44) = 0;
    } else {
    if ((((*(((*(u8 volatile *)&(p_lbl_3_bss_7EDD8->unk_14)) /* Retail reloads this field. */) + (lbl_1_bss_9F8.unk_8))).unk_0 >> 8) & 0x1) != 0 && (s32)(*((struct fn_3_10B68_lbl_3_bss_7EDD8 *)&lbl_3_bss_7EDD8)).unk_18 != 0) {
    fn_1_A2D84((0xA9010000 + 256));
    }
    }
}
#pragma opt_pointer_analysis reset
/* fzgx:end fn_3_10B68 */

/* fzgx:begin fn_3_1180C */
struct fn_3_1180C_Fn3State {
    u8 pad0[4];
    u32 value;
    u8 pad8[2];
    s16 field_a;
    u8 pad_c[0x18];
    s16 mode;
};

void fn_3_1180C(void) {
    if ((*(struct fn_3_1180C_Fn3State *)&lbl_3_bss_7EDD8).mode == 0xf) {
        fn_1_4A00(0, 0xf, (*(struct fn_3_1180C_Fn3State *)&lbl_3_bss_7EDD8).value);
    } else if ((*(struct fn_3_1180C_Fn3State *)&lbl_3_bss_7EDD8).mode == 0) {
        fn_1_FDFF4();
        if ((*(s16 (*)[2])&lbl_3_data_1A40)[0] != -1) {
            fn_1_435C((*(struct fn_3_1180C_Fn3State *)&lbl_3_bss_7EDD8).value);
            fn_1_426C((*(struct fn_3_1180C_Fn3State *)&lbl_3_bss_7EDD8).field_a);
            (*(struct fn_3_1180C_Fn3State *)&lbl_3_bss_7EDD8).field_a = -1;
            lbl_1_bss_96A = (*(s16 (*)[2])&lbl_3_data_1A40)[0];
            (*(s16 (*)[2])&lbl_3_data_1A40)[0] = -1;
        } else {
            (*(s16 (*)[2])&lbl_3_data_1A40)[0] = 0x5f;
        }
    }
}
/* fzgx:end fn_3_1180C */

/* fzgx:begin fn_3_118BC */
#pragma opt_dead_assignments off
void fn_3_118BC(void) {
    u16 flags;
    u8 *tbl;
    fn_3_11A38();
    tbl = (((u8 *)&lbl_1_bss_9F8)) + 8;
    flags = *(u16 *)(tbl + lbl_3_bss_7EDD8.unk_14 * 0x14);
    if (((flags >> 4) & 1) || ((flags >> 9) & 1)) {
        fn_1_A2D84(0xA9010200);
        lbl_3_bss_7EDD8.unk_C = lbl_3_bss_7EDD8.unk_10;
        lbl_3_bss_7EDD8.unk_10 = 0x1000000;
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_3_118BC */

/* fzgx:begin fn_3_11930 */
struct PasteEntry {
    u8 pad[0x2c];
    int active;
};

int fn_3_11930(void) {
    u8 i;
    u8 * base;

    for (i = 0; i < 4; i++) {
        struct PasteEntry *entry = (struct PasteEntry *)(((u8 *)(*(u16 (*)[52])&lbl_3_bss_7EDD8)) + i * 4);
        if (entry->active != 0) {
            return 1;
        }
    }
    return 0;
}
/* fzgx:end fn_3_11930 */

/* fzgx:begin fn_3_11974 */
void fn_3_11974(void) {
    u32 *fields = (u32 *)&(*(u16 (*)[52])&lbl_3_bss_7EDD8);
    fields[11] = 0;
    fields[12] = 0;
    fields[13] = 0;
    fields[14] = 0;
}
/* fzgx:end fn_3_11974 */

/* fzgx:begin fn_3_11994 */
void fn_3_11994(s16 arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg_sp0) {
    s32 temp_r5;
    u8 var_r30;
    void *temp_r4;

    var_r30 = 0;
    while (var_r30 < 4U) {
        if (arg0 != (s32) var_r30) {
            temp_r5 = var_r30 * 0x2060;
            temp_r4 = (void *)(arg2 + temp_r5);
            if (arg1 == (s16) (*(s16 *)((u8 *)(temp_r4) + 0))) {
                if ((*(s32 *)((u8 *)(temp_r4) + 4)) & 0x80000000) {
                    fn_80008BA8( (u32)((struct Sig_fn_8004E278_fn_8004E278_Arg0 *)(arg3 + temp_r5)), (u32)(temp_r4), 0x2060U);
                }
            } else {
                fn_80008BEC( (void *)((struct Sig_fn_8004E278_fn_8004E278_Arg0 *)(arg3 + temp_r5)), 0, 0x2060U);
            }
        }
        var_r30 += 1;
            }
}
/* fzgx:end fn_3_11994 */

/* fzgx:begin fn_3_11F60 */
struct fn_3_11F60_Fn3State {
    u32 value0;
    u32 value1;
};

void fn_3_11F60(u32 value0, u32 value1) {
    (*(struct fn_3_11F60_Fn3State *)&lbl_3_bss_7EDD8).value1 = value1;
    (*(struct fn_3_11F60_Fn3State *)&lbl_3_bss_7EDD8).value0 = value0;
    fn_1_FC414(lbl_3_bss_8F200, (void *)(int)(1));
}
/* fzgx:end fn_3_11F60 */

/* fzgx:begin fn_3_11FA0 */
void fn_3_11FA0(void) {
    (*(u32 (*)[26])&lbl_3_bss_7EDD8)[0] = 0;
    (*(u32 (*)[26])&lbl_3_bss_7EDD8)[1] = 0;
}
/* fzgx:end fn_3_11FA0 */

/* fzgx:begin fn_3_11FB4 */
void fn_3_11FB4(u8 value_47, u8 value_46, u32 value_7EDC0) {
    (*(u8 (*)[0x68])&lbl_3_bss_7EDD8)[0x47] = value_47;
    (*(u32 (*)[3])&lbl_3_bss_7EDC0)[0] = value_7EDC0;
    (*(u8 (*)[0x68])&lbl_3_bss_7EDD8)[0x46] = value_46;
}
/* fzgx:end fn_3_11FB4 */

/* fzgx:begin fn_3_1304C */
// fn_3_1304C: empty in retail (single blr).
void fn_3_1304C(void) {
}
/* fzgx:end fn_3_1304C */

/* fzgx:begin fn_3_13050 */
// fn_3_13050: empty in retail (single blr).
void fn_3_13050(void) {
}
/* fzgx:end fn_3_13050 */

/* fzgx:begin fn_3_13054 */
// fn_3_13054: empty in retail (single blr).
void fn_3_13054(void) {
}
/* fzgx:end fn_3_13054 */

/* fzgx:begin fn_3_13058 */
// fn_3_13058: empty in retail (single blr).
void fn_3_13058(void) {
}
/* fzgx:end fn_3_13058 */

/* fzgx:begin fn_3_1305C */
// fn_3_1305C: empty in retail (single blr).
void fn_3_1305C(void) {
}
/* fzgx:end fn_3_1305C */

/* fzgx:begin fn_3_13060 */
// fn_3_13060: empty in retail (single blr).
void fn_3_13060(void) {
}
/* fzgx:end fn_3_13060 */

/* fzgx:begin fn_3_13064 */
// fn_3_13064: empty in retail (single blr).
void fn_3_13064(void) {
}
/* fzgx:end fn_3_13064 */

/* fzgx:begin fn_3_13068 */
// fn_3_13068: empty in retail (single blr).
void fn_3_13068(void) {
}
/* fzgx:end fn_3_13068 */

/* fzgx:begin fn_3_1306C */
// fn_3_1306C: empty in retail (single blr).
void fn_3_1306C(void) {
}
/* fzgx:end fn_3_1306C */

/* fzgx:begin fn_3_13070 */
// fn_3_13070: empty in retail (single blr).
void fn_3_13070(void) {
}
/* fzgx:end fn_3_13070 */

/* fzgx:begin fn_3_13074 */
// fn_3_13074: empty in retail (single blr).
void fn_3_13074(void) {
}
/* fzgx:end fn_3_13074 */

/* fzgx:begin fn_3_13078 */
// fn_3_13078: empty in retail (single blr).
void fn_3_13078(void) {
}
/* fzgx:end fn_3_13078 */

/* fzgx:begin fn_3_1307C */
u8 fn_3_1307C(void) {
    return lbl_3_bss_A1778[0];
}
/* fzgx:end fn_3_1307C */

/* fzgx:begin fn_3_1308C */
typedef struct {
    u8 pad0[4];
    u32 unk4;
    u8 pad8[0xc];
    u32 unk14;
    u32 unk18;
    u32 unk1c;
} Fn3BssA1768;



void fn_3_1308C(u32 arg0, u32 arg1, u32 arg2) {
    (*(Fn3BssA1768 *)&lbl_3_bss_A1768).unk14 = arg1;
    (*(Fn3BssA1768 *)&lbl_3_bss_A1768).unk18 = arg2;
    (*(Fn3BssA1768 *)&lbl_3_bss_A1768).unk4 = arg0;
    (*(Fn3BssA1768 *)&lbl_3_bss_A1768).unk1c = arg0;
}
/* fzgx:end fn_3_1308C */

/* fzgx:begin fn_3_130A8 */
typedef struct {
    u32 value0;
    u8 pad[0x10];
    u32 value14;
    u32 value18;
    u32 value1c;
} CustomizeState;



void fn_3_130A8(void) {
    CustomizeState *state = (CustomizeState *)&lbl_3_bss_A1768;

    state->value14 = 0;
    state->value18 = 0;
    state->value0 = 0;
    state->value1c = 0;
}
/* fzgx:end fn_3_130A8 */

/* fzgx:begin fn_3_130C8 pool noprologue */
#include "types.h"
#include "rel/customize/emb_paste_editor.h"

typedef struct {
    u32 unk0;
    u32 unk4;
    u16 unk8;
    u16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    u8 pad1C[4];
    u32 unk20;
    u8 pad24[4];
    u8 unk28;
    u8 pad29[3];
} EditSub;

typedef struct {
    u32 unk0;
    u32 unk4;
} EditPair;

typedef struct {
    u8 pad[0x1ec];
    char unk1ec[0x14];
    char unk200[0x14];
    char unk214[0xc];
    char unk220[0x14];
    char unk234[1];
} EditStrings;

extern void fn_3_13508(void);
extern void fn_3_137AC(void);
extern void fn_3_14778(u16, u16, u8, u32);
extern void fn_3_1857C(void);
extern void fn_3_1552C(void);
extern void fn_3_17098(void);
extern void fn_3_14080(void);
extern s16 fn_3_13D98(void *, u32 *);
extern s32 fn_3_13EA4(void *, u32 *);
extern void fn_8006CE1C(f32);
extern void fn_1_435C(u32);
extern u32 fn_1_3F8C(void *, void *, u32, u32);
extern void fn_1_47F74(s32);
extern void fn_1_A176C(u32, u32);
extern void *fn_1_45D0(void *, u32, void *, u32);
extern void fn_80008BEC(void *, int, u32);
extern int fn_1_B7E98(int);
extern u8 fn_1_B8338(int);
extern void fn_1_1317C4(void);
extern u32 *lbl_1_bss_6EAD0[];
extern void *lbl_801A6410;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_3_bss_A1768;
u32 *lbl_3_bss_A1768_4;
u8 lbl_3_bss_A1768_8[8];
u8 lbl_3_bss_A1768_10;
u32 lbl_3_bss_A1768_14;
u32 lbl_3_bss_A1768_18;
u32 *lbl_3_bss_A1768_1c;
u32 lbl_3_bss_A1768_20;
EditPair lbl_3_bss_A1768_24;
u32 lbl_3_bss_A1768_2c;
u32 lbl_3_bss_A1768_30;
u32 lbl_3_bss_A1768_34;
EditSub lbl_3_bss_A1768_38;
s16 lbl_3_bss_A1768_64;
u8 lbl_3_bss_A1768_68[2];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_3_bss_A1768;
    s = *(u8 *)&lbl_3_bss_A1768_4;
    s = *(u8 *)&lbl_3_bss_A1768_8;
    s = *(u8 *)&lbl_3_bss_A1768_10;
    s = *(u8 *)&lbl_3_bss_A1768_14;
    s = *(u8 *)&lbl_3_bss_A1768_18;
    s = *(u8 *)&lbl_3_bss_A1768_1c;
    s = *(u8 *)&lbl_3_bss_A1768_20;
    s = *(u8 *)&lbl_3_bss_A1768_24;
    s = *(u8 *)&lbl_3_bss_A1768_2c;
    s = *(u8 *)&lbl_3_bss_A1768_30;
    s = *(u8 *)&lbl_3_bss_A1768_34;
    s = *(u8 *)&lbl_3_bss_A1768_38;
    s = *(u8 *)&lbl_3_bss_A1768_64;
    s = *(u8 *)&lbl_3_bss_A1768_68;
}
#pragma section code_type ".text"

u32 fzgx_obj_lbl_3_data_3360[0x7b] = {
    0x4d6f7665, 0x20437572, 0x736f7200, 0x00000000, 0x834a815b, 0x835c838b,
    0x82cc88da, 0x93ae0000, 0x48656c70, 0x00000000, 0x90e096be, 0x95b682cc,
    0x955c8ea6, 0x00000000, 0x4368616e,
};
char lbl_3_data_3360_unk1ec[0x14] = {0};
char lbl_3_data_3360_unk200[0x14] = {0};
char lbl_3_data_3360_unk214[0xc] = {0};
char lbl_3_data_3360_unk220[0x14] = {0};
char lbl_3_data_3360_unk234[0x4] = {0};

#define STR(f) (lbl_3_data_3360_##f)

void fn_3_130C8(void) {
    s32 n;
    u8 i;

    fn_8006CE1C(0.0f);
    fn_1_435C(lbl_3_bss_A1768_14);
    lbl_3_bss_A1768_20 = fn_1_3F8C(STR(unk1ec), fn_3_13508, 0, 5);
    fn_1_435C(lbl_3_bss_A1768_18);
    lbl_3_bss_A1768_24.unk4 = fn_1_3F8C(STR(unk200), fn_3_137AC, 0, 5);
    lbl_3_bss_A1768_10 = 0;
    lbl_3_bss_A1768_30 = 0;
    lbl_3_bss_A1768_34 = 0;
    fn_3_14778(0x40, 0x40, 0x10, 5);
    fn_3_1857C();
    fn_3_1552C();
    fn_3_17098();
    fn_3_14080();
    lbl_3_bss_A1768_1c = &lbl_3_bss_A1768_38.unk20;
    fn_1_47F74(0x86);
    fn_1_A176C(*lbl_1_bss_6EAD0[0], 8);
    lbl_3_bss_A1768_38.unk20 = (u32)fn_1_45D0(lbl_801A6410, 0x2000, STR(unk214), 0x94);
    fn_80008BEC((void *)lbl_3_bss_A1768_38.unk20, 0, 0x2000);
    lbl_3_bss_A1768_38.unkC = 0;
    lbl_3_bss_A1768_38.unkE = 0;
    lbl_3_bss_A1768_38.unk10 = 0x20;
    lbl_3_bss_A1768_38.unk12 = 0x20;
    lbl_3_bss_A1768_38.unk4 = 0;
    lbl_3_bss_A1768_38.unk0 = 0;
    lbl_3_bss_A1768_38.unk18 = 0;
    lbl_3_bss_A1768_38.unk16 = 0;
    lbl_3_bss_A1768_38.unk1A = 0;
    lbl_3_bss_A1768_38.unk14 = 0;
    lbl_3_bss_A1768_38.unk28 = 0;
    lbl_3_bss_A1768_64 = 0;
    lbl_3_bss_A1768_4 = fn_1_45D0(lbl_801A6410, 0x3b8, STR(unk214), 0xa6);
    n = (s16)fn_3_13D98(STR(unk220), lbl_3_bss_A1768_4);
    lbl_3_bss_A1768_64 = n + fn_3_13EA4(STR(unk234), lbl_3_bss_A1768_4 + n);
    for (i = lbl_3_bss_A1768_64; i < 0xee; i++) {
        lbl_3_bss_A1768_4[i] = 0;
    }
    lbl_3_bss_A1768_68[0] = fn_1_B7E98(0) ? fn_1_B8338(0) : 0;
    if (fn_1_B7E98(1)) {
        lbl_3_bss_A1768_68[1] = fn_1_B8338(1);
    } else {
        lbl_3_bss_A1768_68[1] = 0;
    }
    fn_1_1317C4();
}
/* fzgx:end fn_3_130C8 */
