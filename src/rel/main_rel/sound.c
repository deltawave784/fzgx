#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sound.h"
#include "sofdec/adxt.h"
#include "game/main_rel/sound_types.h"

extern const f32 lbl_1_rodata_42E0;
extern int OSGetSoundMode(void);
extern u32 fn_1_44A4(void);
extern void fn_1_A2E24(u32 arg0, u32 arg1, s32 arg2);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_80022014(u32 arg0);
extern void fn_80025D50(u32 arg0, u32 arg1);
extern void fn_8004B7D4();
extern void fn_8004BBA4();
extern void ADXT_Stop(ADXTHandle *handle);
extern void fn_8004CAC8(ADXTHandle *handle);
extern u32 fn_8004CD70(u32, u32, u32);
extern u32 fn_8004E59C(u32);
extern u32 fn_8004EC34(u32);
extern void fn_80065890();
extern void fn_8006589C(u32 value);
extern void fn_800658A8(u32 arg0);
extern u32 fn_1_9FE74(void *arg);
extern void fn_1_9FEE8(void *arg);
extern void fn_1_9FF50(void);
extern void fn_1_9FF54(void);
extern void fn_1_9FF58(void);
extern void fn_1_A04AC(void);
extern s16 fn_1_3F0C8(void);
extern void fn_1_3EF14(void *arg1);
extern u32 fn_1_F2F34(void);
extern u32 fn_1_864E8(int index);
extern u8 lbl_1_rodata_43B4[184];
extern void ADXT_Pause(ADXTHandle *handle, s32 paused);
extern u8 lbl_1_bss_A88[24];
extern u8 lbl_1_bss_CC0[152];
extern s32 fn_1_3F864();
extern s32 fn_1_3F854(void);
extern u32 fn_1_86514(int index);
extern f32 fn_1_8652C(int index);
extern s32 fn_80067344(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern s32 fn_80067898(u32 value);
extern void *lbl_801A6410;
extern u32 fn_8001E954(u32 value);
extern u32 fn_80020778(void);
extern u32 fn_80025E18(void);
extern u32 fn_80068BFC(u32, u32, u32, u32, u32);
extern s32 fn_1_45D0();
extern void AIInit(u8 *stack);
extern void fn_1_4438(void);
extern void fn_80020724(void);
extern void fn_8002361C(u32 value0, u32 value1);
extern void fn_8002805C(void);
extern void fn_800411F4(void);
extern s8 fn_1_86690(s8 index);
extern void fn_1_14E9E4(int arg0, void *arg1);
extern u32 lbl_1_rodata_451C[5];
extern u32 lbl_1_rodata_4478[41];
extern void *fn_1_86254(int index);
extern u32 lbl_1_rodata_45D0[82];
extern u32 fn_80008E84();
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern u8 lbl_1_bss_6EAA6;
extern u8 lbl_1_bss_6EAA4;
extern void fn_80067974(void);
extern void fn_800280F0(void);
extern void fn_80026FE0(void);
extern u32 lbl_1_bss_6EAA8[2];
extern u8 lbl_1_bss_6EAB0;
extern u32 ARInit(u32 *stack_index_addr, u32 num_entries);
extern void fn_80020530(void);
extern u8 lbl_1_bss_6F1E1;
extern void fn_1_A2DF4(s32 arg0, void *arg1, s32 arg2);
extern void fn_1_A0680(void);
extern void fn_800674FC(u16 arg0, u32 arg1, s16 arg2);
extern s16 camera_get_mode(void);
extern u8 lbl_1_bss_6F2D8[62];
extern void fn_1_A5470(s32 value);
extern u8 fn_1_3F13C(void);
extern u32 fn_1_EB0B0(void);
extern u32 fn_1_F1B94(void);
extern u32 lbl_1_rodata_4718[];
extern u32 lbl_1_rodata_4730[];
extern u32 lbl_1_rodata_47A8[];
extern u8 lbl_1_bss_6F41C[260];
extern void *lbl_1_rodata_4820[41];
extern s32 fn_8004C658(char *arg0);
extern int fn_8004BBCC(u32 obj);
extern int fn_1_3FC38(void);
extern s32 fn_80063094(s32 arg0, s32 arg1, s32 arg2);
extern s32 fn_80065D70(u32 idx);

/* fzgx:begin fn_1_9FE74 */
// Initialize the sound resource and register it with the sound system.
u32 fn_1_9FE74(void *arg) {
    u32 result;

    fn_1_44A4();
    lbl_1_bss_6EA9C = (u32)fn_80008E84();
    result = (u32)fn_1_45D0(lbl_801A6410, arg, &lbl_1_data_33F1C, 0x94);
    fn_80008E84((void *)lbl_1_bss_6EA9C);
    return result;
}
/* fzgx:end fn_1_9FE74 */

/* fzgx:begin fn_1_9FEE8 */
// Initialize the sound resource and register it with the sound manager.
void fn_1_9FEE8(void *arg) {
    fn_1_44A4();
    lbl_1_bss_6EA9C = (u32)fn_80008E84();
    fn_1_46B4((u32)lbl_801A6410, (u32)(void *)(arg), (const char *)(void *)(&lbl_1_data_33F1C), 0x9c);
    fn_80008E84((void *)lbl_1_bss_6EA9C);
}
/* fzgx:end fn_1_9FEE8 */

/* fzgx:begin fn_1_9FF50 */
// fn_1_9FF50: empty in retail (single blr).
void fn_1_9FF50(void) {
}
/* fzgx:end fn_1_9FF50 */

/* fzgx:begin fn_1_9FF54 */
// fn_1_9FF54: empty in retail (single blr).
void fn_1_9FF54(void) {
}
/* fzgx:end fn_1_9FF54 */

/* fzgx:begin fn_1_9FF58 */
void fn_1_9FF58(void) {
    if (*(s8 *)&lbl_1_bss_6EAA6) {
        fn_80067974();
        fn_800280F0();
        fn_80026FE0();
    }
    lbl_1_bss_6EAA4 = 0;
}
/* fzgx:end fn_1_9FF58 */

/* fzgx:begin fn_1_9FF9C */
void fn_1_9FF9C(void) {
    ARInit( (u32 *)(u8 *)(lbl_1_bss_6EAA8), 2);
    fn_80020530();
    lbl_1_bss_6EAB0 = 0;
}
/* fzgx:end fn_1_9FF9C */

/* fzgx:begin fn_1_9FFD8 */
struct fn_1_9FFD8_lbl_1_bss_6EA98 {
    u32 unk_0;
    u8 pad_4[0x9];
    u8 unk_D;
    u8 unk_E;
    u8 pad_F[0x9];
    u8 unk_18;
    u8 pad_19[0x3];
    u32 unk_1C;
    u16 unk_20;
    u8 pad_22[0x2];
    f32 unk_24;
    f32 unk_28;
    u8 unk_2C;
    u8 unk_2D;
    u8 unk_2E;
    u8 pad_2F[0x1];
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
};
struct fn_1_9FFD8_lbl_801A6410 {
    u32 unk_0;
};


#pragma opt_propagation off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_6EA98;
u32 fzgx_obj_lbl_1_bss_6EA9C[2];
u8 lbl_1_bss_6EAA4;
u8 fzgx_pool_lbl_1_bss_6EA98_gap_6EAA5;
u8 lbl_1_bss_6EAA6;
u8 fzgx_pool_lbl_1_bss_6EA98_gap_6EAA7;
u32 lbl_1_bss_6EAA8[2];
u8 lbl_1_bss_6EAB0;
u8 fzgx_pool_lbl_1_bss_6EA98_gap_6EAB1;
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6EAB1_fill_6EAB2;
u32 fzgx_obj_lbl_1_bss_6EAB4;
u16 lbl_1_bss_6EAB4__fzgx_offset_4;
u16 lbl_1_bss_6EAB4__fzgx_offset_6;
f32 lbl_1_bss_6EAB4__fzgx_offset_8;
f32 lbl_1_bss_6EAB4__fzgx_offset_C;
u8 lbl_1_bss_6EAB4__fzgx_offset_10;
u8 lbl_1_bss_6EAB4__fzgx_offset_11;
u8 fzgx_obj_lbl_1_bss_6EAC6;
u8 lbl_1_bss_6EAC6__fzgx_offset_1;
u32 lbl_1_bss_6EAC6__fzgx_offset_2;
u32 lbl_1_bss_6EAC6__fzgx_offset_6;
u32 fzgx_obj_lbl_1_bss_6EAD0;
u32 lbl_1_bss_6EAD0__fzgx_offset_4;
u8 lbl_1_bss_6EAD0__fzgx_offset_8;
u8 lbl_1_bss_6EAD0__fzgx_offset_9;
u16 lbl_1_bss_6EAD0__fzgx_offset_A;
u32 lbl_1_bss_6EAD0__fzgx_offset_C[447];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA98;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA9C;
    s = *(u8 *)&lbl_1_bss_6EAA4;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6EAA5;
    s = *(u8 *)&lbl_1_bss_6EAA6;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6EAA7;
    s = *(u8 *)&lbl_1_bss_6EAA8;
    s = *(u8 *)&lbl_1_bss_6EAB0;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6EAB1;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6EAB1_fill_6EAB2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAB4;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_6;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_C;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_11;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAC6;
    s = *(u8 *)&lbl_1_bss_6EAC6__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_6EAC6__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_6EAC6__fzgx_offset_6;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAD0;
    s = *(u8 *)&lbl_1_bss_6EAD0__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_6EAD0__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_6EAD0__fzgx_offset_9;
    s = *(u8 *)&lbl_1_bss_6EAD0__fzgx_offset_A;
    s = *(u8 *)&lbl_1_bss_6EAD0__fzgx_offset_C;
}
#pragma section code_type ".text"

void fn_1_9FFD8(void) {
    u32 fzgx_value;
    f32 f0;
    u32 v0;
    u32 v1;
    int lab_t1;
    u32 t11;
    u32 t12;
    u32 t17;
    u32 t19;
    u32 t21;
    u32 t22;
    u32 t23;
    
    AIInit(0);
    fzgx_pool_lbl_1_bss_6EA98_gap_6EAA5 = 0;
    lbl_1_bss_6EAA6 = 0;
    fn_80025D50((u32)fn_1_9FE74, (u32)fn_1_9FEE8);
    fn_80020778();
    fn_8002805C();
    fn_80025E18();
    fn_80022014((u32)fn_1_9FF58);
    fn_8004EC34(0);
    fn_8004E59C(0);
    fn_800411F4();
    fn_8004BBA4((u32)fn_1_9FF50, 0);
    fzgx_value = 0;
    fzgx_obj_lbl_1_bss_6EAB4 = fzgx_value;
    lbl_1_bss_6EAB4__fzgx_offset_4 = 0;
    fzgx_obj_lbl_1_bss_6EAB4 = 0;
    lbl_1_bss_6EAB4__fzgx_offset_4 = 0;
    f0 = lbl_1_rodata_42E0;
    lbl_1_bss_6EAB4__fzgx_offset_8 = f0;
    lbl_1_bss_6EAB4__fzgx_offset_C = f0;
    lbl_1_bss_6EAB4__fzgx_offset_10 = 0xff;
    lbl_1_bss_6EAB4__fzgx_offset_11 = 0;
    fzgx_obj_lbl_1_bss_6EAC6 = 0;
    fn_1_4438();
    t11 = (u32)fn_1_45D0(lbl_801A6410, 0x28000, &lbl_1_data_33F1C, 0xf4);
    lbl_1_bss_6EAC6__fzgx_offset_2 = t11;
    t12 = fn_8001E954(0x6be000);
    lbl_1_bss_6EAC6__fzgx_offset_6 = t12;
    lab_t1 = 0;
    fn_80008BEC((void *)lbl_1_bss_6EAC6__fzgx_offset_2, lab_t1, 0x28000);
    fn_80068BFC(1, 0x28000, 0x6be000, lbl_1_bss_6EAC6__fzgx_offset_2, lbl_1_bss_6EAC6__fzgx_offset_6);
    fn_800658A8((u32)fn_1_A04AC);
    fn_8006589C((u32)fn_1_9FF54);
    t17 = fn_1_44A4();
    fn_80065890(t17);
    t19 = (u32)fn_1_45D0(lbl_801A6410, 0x974a0, &lbl_1_data_33F1C, 0x10b);
    fzgx_obj_lbl_1_bss_6EAD0 = t19;
    lab_t1 = 0;
    fn_80008BEC((void *)t19, lab_t1, 0x974a0);
    t21 = fn_8004CD70(2, (fzgx_obj_lbl_1_bss_6EAD0 + 16), 0x4a248);
    v0 = fzgx_obj_lbl_1_bss_6EAD0;
    *(u32 *)((u8 *)v0 + 0) = t21;
    t22 = fn_8004CD70(2, ((fzgx_obj_lbl_1_bss_6EAD0 + 0x50000) - 0x5da8), 0x4a248);
    v1 = fzgx_obj_lbl_1_bss_6EAD0;
    *(u32 *)((u8 *)v1 + 4) = t22;
    *(u32 *)((u8 *)fzgx_obj_lbl_1_bss_6EAD0 + 8) = 0;
    *(u32 *)((u8 *)fzgx_obj_lbl_1_bss_6EAD0 + 12) = 0;
    t23 = (u32)OSGetSoundMode();
    if (t23 == 0) {
        fn_1_A2E24(0, 0xa0000900, 0);
        fn_8004B7D4(1);
    } else {
        fn_1_A2E24(0, 0xa0000800, 0);
    }
    fn_80020724();
    fn_8002361C((u32)((u8 *)&lbl_1_bss_6EAD0__fzgx_offset_8), 32);
    fzgx_obj_lbl_1_bss_6EA98 = 0;
    lbl_1_bss_6EAB0 = 1;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_9FFD8 */

/* fzgx:begin fn_1_A04AC */
void fn_1_A04AC(void) {
    lbl_1_bss_6F1E0 = 1;
    lbl_1_bss_6F1E1 = 1;
}
/* fzgx:end fn_1_A04AC */

/* fzgx:begin fn_1_A04C4 noprologue */
#include "types.h"

struct fn_1_A04C4_lbl_1_bss_6EA98 {
    u8 pad_0[0xD];
    u8 unk_D;
    u8 unk_E;
    u8 pad_F[0x9];
    u8 unk_18;
    u8 pad_19[0x3];
    u32 unk_1C;
    u16 unk_20;
    u8 pad_22[0x2];
    f32 unk_24;
    f32 unk_28;
    u8 unk_2C;
    u8 unk_2D;
    u8 pad_2E[0x2];
    u32 unk_30;
    u8 pad_34[0x4];
    u32 unk_38;
};

extern f32 lbl_1_rodata_42E0;
extern struct fn_1_A04C4_lbl_1_bss_6EA98 lbl_1_bss_6EA98;
extern u32 OSGetSoundMode(void);
extern u32 fn_1_44A4(void);
extern u32 fn_1_A2E24(u32, u32, u32);
extern u32 fn_80008BEC(u32, u32, u32);
extern u32 fn_80022014(u32);
extern u32 fn_80025D50(u32, u32);
extern u32 fn_8004B7D4(u32);
extern u32 fn_8004BBA4(u32, u32);
extern u32 ADXT_Stop(u32);
extern u32 fn_8004CAC8(u32);
extern u32 fn_8004CD70(u32, u32, u32);
extern u32 fn_8004E59C(u32);
extern u32 fn_8004EC34(u32);
extern u32 fn_80065890(void);
extern u32 fn_8006589C(u32);
extern u32 fn_800658A8(u32);
extern void fn_1_9FE74(void);
extern void fn_1_9FEE8(void);
extern void fn_1_9FF50(void);
extern void fn_1_9FF54(void);
extern void fn_1_9FF58(void);
extern void fn_1_A04AC(void);

void fn_1_A04C4(void) {
    struct fn_1_A04C4_lbl_1_bss_6EA98 *p_lbl_1_bss_6EA98;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 t1, t2, t15, t16, t17, t18, t19, t20;
    p_lbl_1_bss_6EA98 = (struct fn_1_A04C4_lbl_1_bss_6EA98 *)&lbl_1_bss_6EA98;
    p_lbl_1_bss_6EA98->unk_E = 0;
    fn_80025D50((u32)fn_1_9FE74, (u32)fn_1_9FEE8);
    t1 = fn_80022014((u32)fn_1_9FF58);
    t2 = fn_8004EC34(0);
    fn_8004E59C(0);
    fn_8004BBA4((u32)fn_1_9FF50, 0);
    p_lbl_1_bss_6EA98->unk_1C = 0;
    p_lbl_1_bss_6EA98->unk_20 = 0;
    p_lbl_1_bss_6EA98->unk_24 = lbl_1_rodata_42E0;
    p_lbl_1_bss_6EA98->unk_28 = lbl_1_rodata_42E0;
    p_lbl_1_bss_6EA98->unk_2C = 255;
    p_lbl_1_bss_6EA98->unk_2D = 0;
    fn_80008BEC((p_lbl_1_bss_6EA98->unk_30), 0, (0x30000 + -32768));
    fn_800658A8((u32)fn_1_A04AC);
    fn_8006589C((u32)fn_1_9FF54);
    fn_1_44A4();
    fn_80065890();
    ADXT_Stop(*(u32 *)((u8 *)p_lbl_1_bss_6EA98->unk_38 + 0));
    fn_8004CAC8(*(u32 *)((u8 *)p_lbl_1_bss_6EA98->unk_38 + 0));
    ADXT_Stop(*(u32 *)((u8 *)p_lbl_1_bss_6EA98->unk_38 + 4));
    fn_8004CAC8(*(u32 *)((u8 *)p_lbl_1_bss_6EA98->unk_38 + 4));
    fn_80008BEC(p_lbl_1_bss_6EA98->unk_38, 0, (0x90000 + 29856));
    t15 = fn_8004CD70(2, (p_lbl_1_bss_6EA98->unk_38 + 16), (0x50000 - 23992));
    v1 = p_lbl_1_bss_6EA98->unk_38;
    *(u32 *)((u8 *)v1 + 0) = t15;
    t16 = fn_8004CD70(2, ((p_lbl_1_bss_6EA98->unk_38 + 0x50000) - 23976), (0x50000 - 23992));
    v2 = p_lbl_1_bss_6EA98->unk_38;
    *(u32 *)((u8 *)v2 + 4) = t16;
    *(u32 *)((u8 *)p_lbl_1_bss_6EA98->unk_38 + 8) = 0;
    v3 = p_lbl_1_bss_6EA98->unk_38;
    *(u32 *)((u8 *)v3 + 12) = 0;
    t17 = OSGetSoundMode();
    v4 = t17;
    if (t17 == 0) {
    v4 = 0;
    t18 = fn_1_A2E24(v4, (0xA0000000 + 2304), 0);
    v4 = t18;
    v4 = 1;
    t19 = fn_8004B7D4(v4);
    v4 = t19;
    } else {
    v4 = 0;
    t20 = fn_1_A2E24(v4, (0xA0000000 + 2048), 0);
    v4 = t20;
    }
    p_lbl_1_bss_6EA98->unk_18 = 1;
    p_lbl_1_bss_6EA98->unk_D = 0;
}
/* fzgx:end fn_1_A04C4 */

/* fzgx:begin fn_1_A0978 pool noprologue */
#include "dolphin/types.h"
#include "rel/main_rel/sound.h"

extern s32 fn_1_3F864(void);
extern u32 fn_1_A3A1C(void);
extern void fn_1_A31E4(void);
extern u32 fn_1_864E8(u32);
extern void fn_1_A54FC(void);
extern void fn_1_A5590(void);
extern u32 fn_1_A24CC(void);

typedef struct A0978Entry {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02[0x12];
} A0978Entry;

typedef struct A0978State {
    u8 unk_00[0xD];
    u8 unk_0D;
    u8 unk_0E[0x73E];
    A0978Entry unk_74C[5];
    u8 unk_7B0[4];
    s8 unk_7B4[30][2];
    s8 unk_7F0[30][2];
    s8 unk_82C;
} A0978State;

static inline void A0978_tick(s8 counters[][2], u32 id, s32 maximum) {
    counters[id][1]++;
    if (counters[id][1] > maximum) {
        counters[id][0] = 0;
        counters[id][1] = maximum;
    }
}
#pragma opt_propagation on

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_6EA98;
u32 fzgx_obj_lbl_1_bss_6EA9C[2];
u8 lbl_1_bss_6EAA4;
u8 lbl_1_bss_6EA98_gap_6EAA5;
u8 lbl_1_bss_6EAA6;
u8 lbl_1_bss_6EA98_gap_6EAA7;
u32 lbl_1_bss_6EAA8[2];
u8 lbl_1_bss_6EAB0;
u8 lbl_1_bss_6EA98_gap_6EAB1;
u16 lbl_1_bss_6EA98_gap_6EAB1_fill_6EAB2;
u32 fzgx_obj_lbl_1_bss_6EAB4[4];
u16 lbl_1_bss_6EAB4_fill_6EAC4;
u16 fzgx_obj_lbl_1_bss_6EAC6;
u32 lbl_1_bss_6EAC6_fill_6EAC8[2];
u32 fzgx_obj_lbl_1_bss_6EAD0[450];
u8 fzgx_obj_lbl_1_bss_6F1D8;
u8 lbl_1_bss_6EA98_gap_6F1D9;
u16 lbl_1_bss_6EA98_gap_6F1D9_fill_6F1DA;
u32 fzgx_obj_lbl_1_bss_6F1DC;
u8 fzgx_obj_lbl_1_bss_6F1E0;
u8 lbl_1_bss_6F1E1;
u16 lbl_1_bss_6EA98_gap_6F1E2;
u8 fzgx_obj_lbl_1_bss_6F1E4;
u8 lbl_1_bss_6F1E4_fill_6F1E5;
u16 lbl_1_bss_6F1E4_fill_6F1E6;
u32 lbl_1_bss_6F1E4_fill_6F1E8[20];
u8 lbl_1_bss_6F1E4_fill_6F238;
u8 lbl_1_bss_6F239;
u16 lbl_1_bss_6EA98_gap_6F23A;
u32 lbl_1_bss_6F23C;
u16 lbl_1_bss_6F23C_fill_6F240;
u8 lbl_1_bss_6F23C_fill_6F242;
u8 fzgx_obj_lbl_1_bss_6F243;
u32 lbl_1_bss_6F244[2];
s8 lbl_1_bss_6F244_8[30][2];
s8 lbl_1_bss_6F244_44[30][2];
s8 lbl_1_bss_6F2C4;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA98;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA9C;
    s = *(u8 *)&lbl_1_bss_6EAA4;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6EAA5;
    s = *(u8 *)&lbl_1_bss_6EAA6;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6EAA7;
    s = *(u8 *)&lbl_1_bss_6EAA8;
    s = *(u8 *)&lbl_1_bss_6EAB0;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6EAB1;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6EAB1_fill_6EAB2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAB4;
    s = *(u8 *)&lbl_1_bss_6EAB4_fill_6EAC4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAC6;
    s = *(u8 *)&lbl_1_bss_6EAC6_fill_6EAC8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAD0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1D8;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6F1D9;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6F1D9_fill_6F1DA;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1DC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E0;
    s = *(u8 *)&lbl_1_bss_6F1E1;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6F1E2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E4;
    s = *(u8 *)&lbl_1_bss_6F1E4_fill_6F1E5;
    s = *(u8 *)&lbl_1_bss_6F1E4_fill_6F1E6;
    s = *(u8 *)&lbl_1_bss_6F1E4_fill_6F1E8;
    s = *(u8 *)&lbl_1_bss_6F1E4_fill_6F238;
    s = *(u8 *)&lbl_1_bss_6F239;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6F23A;
    s = *(u8 *)&lbl_1_bss_6F23C;
    s = *(u8 *)&lbl_1_bss_6F23C_fill_6F240;
    s = *(u8 *)&lbl_1_bss_6F23C_fill_6F242;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F243;
    s = *(u8 *)&lbl_1_bss_6F244;
    s = *(u8 *)&lbl_1_bss_6F244_8;
    s = *(u8 *)&lbl_1_bss_6F244_44;
    s = *(u8 *)&lbl_1_bss_6F2C4;
}
#pragma section code_type ".text"

void fn_1_A0978(void) {
    s32 i;
    u8 id;
    u32 flags;
    struct { A0978Entry *value; } entry;

    
    if (fn_1_3F864() == 0 || lbl_1_bss_6EA98_gap_6EAA5 != 0) {
        return;
    }
    {
        fn_1_A3A1C();
        fn_1_A31E4();
        entry.value = (*(A0978Entry (*)[5])&fzgx_obj_lbl_1_bss_6F1E4);
        for (i = 0; i < lbl_1_bss_6F2C4; entry.value++, i++) {
            id = entry.value->unk_01;
            flags = fn_1_864E8(id);
            if (!(flags & 0x800000)) {
                A0978_tick(lbl_1_bss_6F244_8, id, 10);
            }
            if (!(flags & 0x2000000)) {
                A0978_tick(lbl_1_bss_6F244_44, id, 30);
            }
        }
        fn_1_A54FC();
        fn_1_A5590();
        fn_1_A24CC();
    }
}
/* fzgx:end fn_1_A0978 */

/* fzgx:begin fn_1_A0C68 */
enum {
    ADDR_A6000000 = 0xA6000000,
    ADDR_A5100000 = 0xA5100000,
    ADDR_A0000300 = 0xA0000300,
    ADDR_A0000400 = 0xA0000400
};

typedef struct fn_1_A0C68_SoundState {
    u8 pad_2e[0x2e];
    u8 unk_2e;
    u8 pad_74c[0x74c - 0x2f];
    u8 unk_74c[0x50];
    u8 pad_7ac[0x7ac - 0x79c];
    u8 unk_7ac;
} fn_1_A0C68_SoundState;

// Initialize the sound resources once the sound system is enabled.
void fn_1_A0C68(void) {
    fn_1_A0C68_SoundState *state;
    s32 i;

    state = (fn_1_A0C68_SoundState *)&lbl_1_bss_6EA98;
    if (state->unk_2e != 0) {
        fn_1_A2DF4(0x10, (void *)ADDR_A6000000, 0);
        fn_1_A2DF4(0x10, (void *)ADDR_A5100000, 0);

        for (i = 1; i < 4; i++) {
            fn_1_A2E24(i, ADDR_A0000300, 0);
        }

        fn_1_A2E24(0x10, ADDR_A0000400, 0);
        fn_80008BEC(&state->unk_74c, 0, 0x50);
        state->unk_7ac = 0;
    }
}
/* fzgx:end fn_1_A0C68 */

/* fzgx:begin fn_1_A116C */
void fn_1_A116C(void) {
    switch ((*(s16 *)&lbl_1_bss_960)) {
    case 2:
    case 8:
    case 9:
    case 12:
        fn_80065D70(1);
        break;
    case 1:
    case 5:
    case 13:
        fn_80065D70(2);
        break;
    case 4:
        if (lbl_1_bss_962 != 0x3D) {
            fn_80065D70(3);
        }
        break;
    case 14:
    case 16:
        fn_80065D70(3);
        break;
    }
}
/* fzgx:end fn_1_A116C */

/* fzgx:begin fn_1_A1340 */
void fn_1_A1340(void) {
    fn_1_A0680();
}
/* fzgx:end fn_1_A1340 */

/* fzgx:begin fn_1_A1360 */
// fn_1_A1360: empty in retail (single blr).
void fn_1_A1360(void) {
}
/* fzgx:end fn_1_A1360 */

/* fzgx:begin fn_1_A2210 pool noprologue */
#include "dolphin/types.h"
#include "sofdec/adxt.h"

extern u8 lbl_1_bss_8CA24;
extern u8 lbl_1_bss_8B5F0;
extern u8 lbl_1_bss_8B5F1;
extern s16 lbl_1_data_2D93C[];
extern const char *lbl_1_data_2D7B8[];

extern s32 fn_1_F2F34(void);
extern u8 lbl_1_rodata_43B4[184];
extern const f64 lbl_1_rodata_42F0;
extern f32 lbl_1_rodata_42E0;
extern f32 lbl_1_rodata_42E4;
extern f32 lbl_1_rodata_42E8;
extern s32 fn_8004C658(char *);
extern void fn_8004D18C(u32, const char *);
extern u32 fn_8004BF0C(u32, u32);
extern void ADXT_Pause(ADXTHandle *, s32);
extern s32 fn_80067898(u32);

typedef struct {
    s8 id;      /* voice line index, -1 = none */
    u8 pad;
    s16 se;     /* sound effect id */
} CueEntry;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_6EA98;
u32 fzgx_obj_lbl_1_bss_6EA9C[2];
u8 lbl_1_bss_6EAA4;
u8 lbl_1_bss_6EA98_gap_6EAA5;
u8 lbl_1_bss_6EAA6;
u8 lbl_1_bss_6EA98_gap_6EAA7;
u32 lbl_1_bss_6EAA8[2];
u8 lbl_1_bss_6EAB0;
u8 lbl_1_bss_6EA98_gap_6EAB1;
u16 lbl_1_bss_6EA98_gap_6EAB1_fill_6EAB2;
u32 fzgx_obj_lbl_1_bss_6EAB4;
u32 lbl_1_bss_6EAB4_fill_6EAB8;
f32 lbl_1_bss_6EAB4_8;
f32 lbl_1_bss_6EAB4_C;
u8 lbl_1_bss_6EAB4_10;
u8 lbl_1_bss_6EAB4_fill_6EAC5;
u16 fzgx_obj_lbl_1_bss_6EAC6;
u32 lbl_1_bss_6EAC6_fill_6EAC8[2];
u32 *fzgx_obj_lbl_1_bss_6EAD0;
u32 lbl_1_bss_6EAD0_fill_6EAD4[449];
u8 fzgx_obj_lbl_1_bss_6F1D8;
u8 lbl_1_bss_6EA98_gap_6F1D9;
u16 lbl_1_bss_6EA98_gap_6F1D9_fill_6F1DA;
u32 fzgx_obj_lbl_1_bss_6F1DC;
u8 fzgx_obj_lbl_1_bss_6F1E0;
u8 lbl_1_bss_6F1E1;
u16 lbl_1_bss_6EA98_gap_6F1E2;
u32 fzgx_obj_lbl_1_bss_6F1E4[21];
u8 lbl_1_bss_6F1E4_fill_6F238;
u8 lbl_1_bss_6F239;
u16 lbl_1_bss_6EA98_gap_6F23A;
u32 lbl_1_bss_6F23C;
u16 lbl_1_bss_6F23C_fill_6F240;
u8 lbl_1_bss_6F23C_6;
u8 fzgx_obj_lbl_1_bss_6F243;
u32 lbl_1_bss_6F244[32];
u8 lbl_1_bss_6F2C4;
u8 lbl_1_bss_6EA98_gap_6F2C5;
u16 lbl_1_bss_6EA98_gap_6F2C5_fill_6F2C6;
u32 lbl_1_bss_6F2C8[4];
u32 lbl_1_bss_6F2D8[15];
u16 lbl_1_bss_6F2D8_fill_6F314;
u8 lbl_1_bss_6F316;
u8 lbl_1_bss_6F317;
u16 lbl_1_bss_6EA98_gap_6F318;
u8 lbl_1_bss_6F31A;
u8 lbl_1_bss_6F31A_fill_6F31B;
s16 lbl_1_bss_6F31A_2[2];
f32 lbl_1_bss_6F31A_6;  /* retail addresses both floats base-relative: two scalars, not an array */
f32 lbl_1_bss_6F31A_A;
u32 lbl_1_bss_6F31A_fill_6F328[31];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA98;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA9C;
    s = *(u8 *)&lbl_1_bss_6EAA4;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6EAA5;
    s = *(u8 *)&lbl_1_bss_6EAA6;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6EAA7;
    s = *(u8 *)&lbl_1_bss_6EAA8;
    s = *(u8 *)&lbl_1_bss_6EAB0;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6EAB1;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6EAB1_fill_6EAB2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAB4;
    s = *(u8 *)&lbl_1_bss_6EAB4_fill_6EAB8;
    s = *(u8 *)&lbl_1_bss_6EAB4_8;
    s = *(u8 *)&lbl_1_bss_6EAB4_C;
    s = *(u8 *)&lbl_1_bss_6EAB4_10;
    s = *(u8 *)&lbl_1_bss_6EAB4_fill_6EAC5;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAC6;
    s = *(u8 *)&lbl_1_bss_6EAC6_fill_6EAC8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAD0;
    s = *(u8 *)&lbl_1_bss_6EAD0_fill_6EAD4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1D8;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6F1D9;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6F1D9_fill_6F1DA;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1DC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E0;
    s = *(u8 *)&lbl_1_bss_6F1E1;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6F1E2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E4;
    s = *(u8 *)&lbl_1_bss_6F1E4_fill_6F238;
    s = *(u8 *)&lbl_1_bss_6F239;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6F23A;
    s = *(u8 *)&lbl_1_bss_6F23C;
    s = *(u8 *)&lbl_1_bss_6F23C_fill_6F240;
    s = *(u8 *)&lbl_1_bss_6F23C_6;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F243;
    s = *(u8 *)&lbl_1_bss_6F244;
    s = *(u8 *)&lbl_1_bss_6F2C4;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6F2C5;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6F2C5_fill_6F2C6;
    s = *(u8 *)&lbl_1_bss_6F2C8;
    s = *(u8 *)&lbl_1_bss_6F2D8;
    s = *(u8 *)&lbl_1_bss_6F2D8_fill_6F314;
    s = *(u8 *)&lbl_1_bss_6F316;
    s = *(u8 *)&lbl_1_bss_6F317;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6F318;
    s = *(u8 *)&lbl_1_bss_6F31A;
    s = *(u8 *)&lbl_1_bss_6F31A_fill_6F31B;
    s = *(u8 *)&lbl_1_bss_6F31A_2;
    s = *(u8 *)&lbl_1_bss_6F31A_6;
    s = *(u8 *)&lbl_1_bss_6F31A_A;
    s = *(u8 *)&lbl_1_bss_6F31A_fill_6F328;
}
#pragma section code_type ".text"

void fn_1_A2210(u8 cue)
{
    u32 handle;
    s16 se;
    s8 id;
    u32 *handles;
    u32 flags;
    const CueEntry *entry;

    if (fzgx_obj_lbl_1_bss_6EAD0 == NULL) {
        return;
    }
    if (lbl_1_bss_8CA24) {
        return;
    }
    if (lbl_1_bss_8B5F0) {
        return;
    }
    if (lbl_1_bss_8B5F1 || lbl_1_bss_6F23C_6) {
        return;
    }
    if (fn_1_F2F34() != 0) {
        return;
    }
    if (fn_8004C658((char *)fzgx_obj_lbl_1_bss_6EAD0[0]) != 3) {
        return;
    }

    if (cue > 0x2D) {
        id = -1;
        se = -1;
    } else {
        entry = (const CueEntry *)lbl_1_rodata_43B4;
        id = entry[cue].id;
        se = entry[cue].se;
    }

    if (id != -1) {
        handles = fzgx_obj_lbl_1_bss_6EAD0;
        handle = handles[1];
        if (!lbl_1_bss_6F31A && handle != 0 && handle != 0xFFFFFFFF) {
            if (handle == handles[0]) {
                flags = fzgx_obj_lbl_1_bss_6EAB4;
                fzgx_obj_lbl_1_bss_6EAB4 = flags & ~4;
                if (flags & 1) {
                    lbl_1_bss_6F31A_2[0] = lbl_1_data_2D93C[(u8)id];
                } else {
                    s32 v = lbl_1_data_2D93C[(u8)id];
                    lbl_1_bss_6EAB4_8 = lbl_1_rodata_42E0;
                    lbl_1_bss_6F31A_6 = v;
                }
            }
            if (handle == handles[1]) {
                flags = fzgx_obj_lbl_1_bss_6EAB4;
                fzgx_obj_lbl_1_bss_6EAB4 = flags & ~8;
                if (flags & 2) {
                    lbl_1_bss_6F31A_2[1] = lbl_1_data_2D93C[(u8)id];
                } else {
                    lbl_1_bss_6EAB4_C = lbl_1_rodata_42E4;
                    lbl_1_bss_6F31A_A = lbl_1_data_2D93C[(u8)id];
                }
            }
            fn_8004D18C(handle, lbl_1_data_2D7B8[(u8)id]);
            flags = fzgx_obj_lbl_1_bss_6EAB4;
            if (flags & 3) {
                if (flags & 1) {
                    lbl_1_bss_6F31A_6 = lbl_1_rodata_42E8;
                }
                if (flags & 2) {
                    lbl_1_bss_6F31A_A = lbl_1_rodata_42E8;
                }
                fn_8004BF0C(handle, -400);
            } else {
                fn_8004BF0C(handle, lbl_1_data_2D93C[(u8)id]);
            }
            lbl_1_bss_6EAB4_10 = id;
        }
        ADXT_Pause((ADXTHandle *)fzgx_obj_lbl_1_bss_6EAD0[1], 1);
        fn_80067898(se | 0xA8000000);
    }
    flags = lbl_1_bss_6F23C;
    lbl_1_bss_6F23C_6 = 1;
    lbl_1_bss_6F23C = flags | 0x20;
}
/* fzgx:end fn_1_A2210 */

/* fzgx:begin fn_1_A24CC pool */
typedef struct {
    ADXTHandle *unk_0;
    ADXTHandle *unk_4;
} fn_1_A24CC_AdxPair;

typedef struct {
    u8 pad_0[0x38];
    fn_1_A24CC_AdxPair *unk_38;
    u8 pad_3C[0x748 - 0x3C];
    u8 unk_748;
    u8 unk_749;
    u8 pad_74A[0x7A4 - 0x74A];
    u32 unk_7A4;
} fn_1_A24CC_SoundState;

typedef struct {
    u8 pad_0[0x118];
    s32 unk_118;
} fn_1_A24CC_Entry;

typedef struct {
    u8 pad_0[4];
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    u8 pad_7[7];
    u8 ids[30];
    fn_1_A24CC_Entry *entries[30];
    u8 pad_A4[0x14C0 - 0xA4];
} fn_1_A24CC_RaceInfo;


/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_6EA98;
u32 fzgx_obj_lbl_1_bss_6EA9C[2];
u8 lbl_1_bss_6EAA4;
u8 lbl_1_bss_6EA98_gap_6EAA5;
u8 lbl_1_bss_6EAA6;
u8 lbl_1_bss_6EA98_gap_6EAA7;
u32 lbl_1_bss_6EAA8[2];
u8 lbl_1_bss_6EAB0;
u8 lbl_1_bss_6EA98_gap_6EAB1;
u16 lbl_1_bss_6EA98_gap_6EAB1_fill_6EAB2;
u32 fzgx_obj_lbl_1_bss_6EAB4[4];
u16 lbl_1_bss_6EAB4_fill_6EAC4;
u16 fzgx_obj_lbl_1_bss_6EAC6;
u32 lbl_1_bss_6EAC6_fill_6EAC8[2];
fn_1_A24CC_AdxPair *fzgx_obj_lbl_1_bss_6EAD0;
u32 lbl_1_bss_6EAD0_fill_6EAD4[449];
u8 fzgx_obj_lbl_1_bss_6F1D8;
u8 lbl_1_bss_6EA98_gap_6F1D9;
u16 lbl_1_bss_6EA98_gap_6F1D9_fill_6F1DA;
u32 fzgx_obj_lbl_1_bss_6F1DC;
u8 fzgx_obj_lbl_1_bss_6F1E0;
u8 lbl_1_bss_6F1E1;
u16 lbl_1_bss_6EA98_gap_6F1E2;
u32 fzgx_obj_lbl_1_bss_6F1E4[21];
u8 lbl_1_bss_6F1E4_fill_6F238;
u8 lbl_1_bss_6F239;
u16 lbl_1_bss_6EA98_gap_6F23A;
u32 lbl_1_bss_6F23C;
u16 lbl_1_bss_6F23C_fill_6F240;
u8 lbl_1_bss_6F23C_fill_6F242;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA98;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA9C;
    s = *(u8 *)&lbl_1_bss_6EAA4;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6EAA5;
    s = *(u8 *)&lbl_1_bss_6EAA6;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6EAA7;
    s = *(u8 *)&lbl_1_bss_6EAA8;
    s = *(u8 *)&lbl_1_bss_6EAB0;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6EAB1;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6EAB1_fill_6EAB2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAB4;
    s = *(u8 *)&lbl_1_bss_6EAB4_fill_6EAC4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAC6;
    s = *(u8 *)&lbl_1_bss_6EAC6_fill_6EAC8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAD0;
    s = *(u8 *)&lbl_1_bss_6EAD0_fill_6EAD4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1D8;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6F1D9;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6F1D9_fill_6F1DA;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1DC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E0;
    s = *(u8 *)&lbl_1_bss_6F1E1;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6F1E2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E4;
    s = *(u8 *)&lbl_1_bss_6F1E4_fill_6F238;
    s = *(u8 *)&lbl_1_bss_6F239;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6F23A;
    s = *(u8 *)&lbl_1_bss_6F23C;
    s = *(u8 *)&lbl_1_bss_6F23C_fill_6F240;
    s = *(u8 *)&lbl_1_bss_6F23C_fill_6F242;
}
#pragma section code_type ".text"

void fn_1_A24CC(void) {
    
    fn_1_A24CC_RaceInfo info;
    fn_1_A24CC_Entry *entry;
    s32 id;
    u32 i;
    u8 first;
    s8 slot;
    u32 flags;

    if (*(s16 *)&lbl_1_bss_960 != 2 && *(s16 *)&lbl_1_bss_960 != 9) {
        return;
    }
    if (fn_1_3F0C8() != 0x29) {
        return;
    }
    fn_1_3EF14(&info);
    if (lbl_1_bss_8CA24 != 0 || lbl_1_bss_8B5F0 != 0 || lbl_1_bss_8B5F1 != 0 || info.unk_5 == 3 ||
        info.unk_5 == 4 || info.unk_4 == 1) {
        return;
    }
    if ((s32)fn_1_F2F34() != 0) {
        return;
    }

    first = info.unk_6;
    for (i = 0; i < 30; i++) {
        id = info.ids[i];
        flags = fn_1_864E8(id);
        entry = info.entries[i];
        if (!(flags & 0x200)) {
            break;
        }
    }

    if (first > 0x2D) {
        slot = -1;
    } else {
        slot = (s8)lbl_1_rodata_43B4[first * 4];
    }

    if (id == 0xFF) {
        return;
    }
    if (entry->unk_118 == (u8)(info.unk_4 - 1) && fzgx_obj_lbl_1_bss_6F1E0 != 0 && lbl_1_bss_6F1E1 != 0 && slot != -1) {
        ADXT_Stop(fzgx_obj_lbl_1_bss_6EAD0->unk_0);
        ADXT_Pause(fzgx_obj_lbl_1_bss_6EAD0->unk_4, 0);
        flags = lbl_1_bss_6F23C;
        lbl_1_bss_6F1E1 = 0;
        lbl_1_bss_6F23C = flags & ~0x20;
    }
    fzgx_obj_lbl_1_bss_6F1E0 = 0;
}
/* fzgx:end fn_1_A24CC */

/* fzgx:begin fn_1_A266C noprologue */
#include "types.h"
#include "sofdec/adxt.h"

typedef struct {
    ADXTHandle *unk_0;
    ADXTHandle *unk_4;
} fn_1_A266C_Streams;

typedef struct {
    u8 pad_0[0x2];
    s8 unk_2;
    u8 pad_3[0x11];
} fn_1_A266C_FadeEntry;

extern void fn_1_A2E24(u32, u32, s32);
extern void fn_1_A2DF4(s32, u32, s32);
extern void fn_1_A4DF4(void);
extern void fn_8004BF0C(ADXTHandle *, s32);
extern void ADXT_Stop(ADXTHandle *);
extern s32 fn_800672E4(u32, u32);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_6EA98;
u32 fzgx_obj_lbl_1_bss_6EA9C[2];
u8 lbl_1_bss_6EAA4;
u8 fzgx_pool_lbl_1_bss_6EA98_gap_6EAA5;
u8 lbl_1_bss_6EAA6;
u8 fzgx_pool_lbl_1_bss_6EA98_gap_6EAA7;
u32 lbl_1_bss_6EAA8[2];
u8 lbl_1_bss_6EAB0;
u8 fzgx_pool_lbl_1_bss_6EA98_gap_6EAB1;
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6EAB2;
u32 fzgx_obj_lbl_1_bss_6EAB4;                 /* fade flags */
u16 lbl_1_bss_6EAB4__fzgx_offset_4;
u16 lbl_1_bss_6EAB4__fzgx_offset_6;
f32 lbl_1_bss_6EAB4__fzgx_offset_8;           /* stream 0 fade step */
f32 lbl_1_bss_6EAB4__fzgx_offset_C;           /* stream 1 fade step */
u8 lbl_1_bss_6EAB4__fzgx_offset_10;
u8 lbl_1_bss_6EAB4__fzgx_offset_11;
u8 fzgx_obj_lbl_1_bss_6EAC6;
u8 lbl_1_bss_6EAC6__fzgx_offset_1;
u32 lbl_1_bss_6EAC6__fzgx_offset_2;
u32 lbl_1_bss_6EAC6__fzgx_offset_6;
fn_1_A266C_Streams *fzgx_obj_lbl_1_bss_6EAD0;
u32 lbl_1_bss_6EAD0__fzgx_offset_4;
u8 lbl_1_bss_6EAD0__fzgx_offset_8;
u8 lbl_1_bss_6EAD0__fzgx_offset_9;
u16 lbl_1_bss_6EAD0__fzgx_offset_A;
u32 lbl_1_bss_6EAD0__fzgx_offset_C[447];
u8 lbl_1_bss_6F1D8;
u8 fzgx_pool_lbl_1_bss_6EA98_gap_6F1D9;
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6F1DA;
u32 lbl_1_bss_6F1DC;
u8 lbl_1_bss_6F1E0;
u8 lbl_1_bss_6F1E1;
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6F1E2;
fn_1_A266C_FadeEntry fzgx_obj_lbl_1_bss_6F1E4[4];
u8 lbl_1_bss_6F1E4__fzgx_offset_50[5];
u8 lbl_1_bss_6F239;
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6F23A;
u8 lbl_1_bss_6F23C[7];
u8 lbl_1_bss_6F243;
u8 fzgx_obj_lbl_1_bss_6F244;
u8 lbl_1_bss_6F244__fzgx_offset_1;
u8 lbl_1_bss_6F244__fzgx_offset_2;
u8 lbl_1_bss_6F244__fzgx_offset_3;
u8 lbl_1_bss_6F244__fzgx_offset_4[4];         /* per-channel volume floor */
u32 lbl_1_bss_6F244__fzgx_offset_8[30];
u8 lbl_1_bss_6F2C4;
u8 fzgx_pool_lbl_1_bss_6EA98_gap_6F2C5;
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6F2C6;
u32 lbl_1_bss_6F2C8[4];
u8 lbl_1_bss_6F2D8[0x3E];
u8 lbl_1_bss_6F316;
u8 lbl_1_bss_6F317;
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6F318;
u8 fzgx_obj_lbl_1_bss_6F31A;                  /* fade paused */
u8 lbl_1_bss_6F31A__fzgx_offset_1;
s16 lbl_1_bss_6F31A__fzgx_offset_2[2];        /* fade-in target volumes */
f32 lbl_1_bss_6F31A__fzgx_offset_6;           /* stream 0 fade volume */
f32 lbl_1_bss_6F31A__fzgx_offset_A;           /* stream 1 fade volume */

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA98;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA9C;
    s = *(u8 *)&lbl_1_bss_6EAA4;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6EAA5;
    s = *(u8 *)&lbl_1_bss_6EAA6;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6EAA7;
    s = *(u8 *)&lbl_1_bss_6EAA8;
    s = *(u8 *)&lbl_1_bss_6EAB0;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6EAB1;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6EAB2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAB4;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_6;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_C;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_11;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAC6;
    s = *(u8 *)&lbl_1_bss_6EAC6__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_6EAC6__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_6EAC6__fzgx_offset_6;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAD0;
    s = *(u8 *)&lbl_1_bss_6EAD0__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_6EAD0__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_6EAD0__fzgx_offset_9;
    s = *(u8 *)&lbl_1_bss_6EAD0__fzgx_offset_A;
    s = *(u8 *)&lbl_1_bss_6EAD0__fzgx_offset_C;
    s = *(u8 *)&lbl_1_bss_6F1D8;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F1D9;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F1DA;
    s = *(u8 *)&lbl_1_bss_6F1DC;
    s = *(u8 *)&lbl_1_bss_6F1E0;
    s = *(u8 *)&lbl_1_bss_6F1E1;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F1E2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E4;
    s = *(u8 *)&lbl_1_bss_6F1E4__fzgx_offset_50;
    s = *(u8 *)&lbl_1_bss_6F239;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F23A;
    s = *(u8 *)&lbl_1_bss_6F23C;
    s = *(u8 *)&lbl_1_bss_6F243;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F244;
    s = *(u8 *)&lbl_1_bss_6F244__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_6F244__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_6F244__fzgx_offset_3;
    s = *(u8 *)&lbl_1_bss_6F244__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_6F244__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_6F2C4;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F2C5;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F2C6;
    s = *(u8 *)&lbl_1_bss_6F2C8;
    s = *(u8 *)&lbl_1_bss_6F2D8;
    s = *(u8 *)&lbl_1_bss_6F316;
    s = *(u8 *)&lbl_1_bss_6F317;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F318;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F31A;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_6;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_A;
}
#pragma section code_type ".text"

void fn_1_A266C(void) {
    s32 vol;
    u8 fadedOut;
    u32 i;
    s8 level;
    u8 silent;
    s32 d;
    u32 flags;

    if (fzgx_obj_lbl_1_bss_6EAD0 == 0) {
        return;
    }

    /* stream 0 fade in */
    if ((fzgx_obj_lbl_1_bss_6EAB4 & 1) && fzgx_obj_lbl_1_bss_6EAD0->unk_0 != 0 && fzgx_obj_lbl_1_bss_6F31A == 0) {
        vol = (s32)(lbl_1_bss_6F31A__fzgx_offset_6 += lbl_1_bss_6EAB4__fzgx_offset_8);
        if (lbl_1_bss_6F31A__fzgx_offset_2[0] > vol) {
            fn_8004BF0C(fzgx_obj_lbl_1_bss_6EAD0->unk_0, vol);
        } else {
            fn_8004BF0C(fzgx_obj_lbl_1_bss_6EAD0->unk_0, lbl_1_bss_6F31A__fzgx_offset_2[0]);
            fzgx_obj_lbl_1_bss_6EAB4 &= ~1;
        }
    }
    /* stream 1 fade in (retail reads the stream 0 fader for the volume) */
    if ((fzgx_obj_lbl_1_bss_6EAB4 & 2) && fzgx_obj_lbl_1_bss_6EAD0->unk_4 != 0 && fzgx_obj_lbl_1_bss_6F31A == 0) {
        lbl_1_bss_6F31A__fzgx_offset_A += lbl_1_bss_6EAB4__fzgx_offset_C;
        vol = (s32)lbl_1_bss_6F31A__fzgx_offset_6;
        if (lbl_1_bss_6F31A__fzgx_offset_2[1] > vol) {
            fn_8004BF0C(fzgx_obj_lbl_1_bss_6EAD0->unk_4, vol);
        } else {
            fn_8004BF0C(fzgx_obj_lbl_1_bss_6EAD0->unk_4, lbl_1_bss_6F31A__fzgx_offset_2[1]);
            fzgx_obj_lbl_1_bss_6EAB4 &= ~2;
        }
    }
    /* stream 0 fade out */
    if ((fzgx_obj_lbl_1_bss_6EAB4 & 4) && fzgx_obj_lbl_1_bss_6EAD0->unk_0 != 0 && fzgx_obj_lbl_1_bss_6F31A == 0) {
        vol = (s32)(lbl_1_bss_6F31A__fzgx_offset_6 -= lbl_1_bss_6EAB4__fzgx_offset_8);
        if (vol > -400) {
            fn_8004BF0C(fzgx_obj_lbl_1_bss_6EAD0->unk_0, vol);
        } else {
            ADXT_Stop(fzgx_obj_lbl_1_bss_6EAD0->unk_0);
            fzgx_obj_lbl_1_bss_6EAB4 &= ~4;
        }
    }
    /* stream 1 fade out */
    if ((fzgx_obj_lbl_1_bss_6EAB4 & 8) && fzgx_obj_lbl_1_bss_6EAD0->unk_4 != 0 && fzgx_obj_lbl_1_bss_6F31A == 0) {
        vol = (s32)(lbl_1_bss_6F31A__fzgx_offset_A -= lbl_1_bss_6EAB4__fzgx_offset_C);
        if (vol > -400) {
            fn_8004BF0C(fzgx_obj_lbl_1_bss_6EAD0->unk_4, vol);
        } else {
            ADXT_Stop(fzgx_obj_lbl_1_bss_6EAD0->unk_4);
            fzgx_obj_lbl_1_bss_6EAB4 &= ~8;
        }
    }

    flags = fzgx_obj_lbl_1_bss_6EAB4;
    if (!(flags & 0x20)) {
        return;
    }
    fadedOut = 0;
    silent = 0;
    if (flags & 0x80) {
        for (i = 1; (s32)i < 4; i++) {
            d = fn_800672E4(i, 0xa0100000) - lbl_1_bss_6F244__fzgx_offset_4[i];
            if (d < 0) {
                d = 0;
            }
            fn_1_A2E24(i, 0xa0100000, d);
        }
        i = 1;
        silent = 1;
        fadedOut = 1;
        for (; (s32)i < 4; i++) {
            if (fn_800672E4(i, 0xa0100000) == 0) {
                silent++;
            }
        }
        fzgx_obj_lbl_1_bss_6F244 = 0;
    } else {
        for (i = 0; (s32)i < 4; i++) {
            d = fn_800672E4(i, 0xa0100000) - lbl_1_bss_6F244__fzgx_offset_4[i];
            if (d < 0) {
                d = 0;
            }
            fn_1_A2E24(i, 0xa0100000, d);
        }
        for (i = 0; (s32)i < 4; i++) {
            if (fn_800672E4(i, 0xa0100000) == 0) {
                silent++;
            }
        }
    }

    if (fzgx_obj_lbl_1_bss_6EAC6) {
        for (i = 0; (s32)i < 4; i++) {
            /* fzgx-allow: preserve the signed byte read before the narrowing subtraction. */
            level = *(volatile s8 *)&fzgx_obj_lbl_1_bss_6F1E4[i].unk_2;
            level -= 2;
            if (level < 0) {
                level = 0;
                fn_1_A2DF4(i, 0xa6000000, 0);
                fadedOut++;
            }
            fn_1_A2DF4(i, 0xa5100000, level);
            fzgx_obj_lbl_1_bss_6F1E4[i].unk_2 = level;
        }
        if (fadedOut >= 4) {
            fn_1_A2E24(0x10, 0xa0000400, 0);
        }
    } else {
        fadedOut = 4;
    }

    if (silent >= 4 && fadedOut >= 4) {
        fn_1_A2E24(0x10, 0xa0000300, 0);
        fn_1_A2E24(0x10, 0xa0000100, 0);
        fn_1_A2E24(0x10, 0xa0100000, 0x7f);
        fzgx_obj_lbl_1_bss_6EAB4 &= ~0x20;
        fn_1_A4DF4();
    }
}
/* fzgx:end fn_1_A266C */

/* fzgx:begin fn_1_A2A70 noprologue */
#include "types.h"

struct fn_1_A2A70_state {
    u8 pad_0[0x1C];
    u32 unk_1C;
    u8 pad_20[0x4];
    f32 unk_24;
    f32 unk_28;
    u8 pad_2C[0xC];
    void **unk_38;
    u8 pad_3C[0x7B0 - 0x3C];
    u8 unk_7B0[4];
    u8 pad_7B4[0x888 - 0x7B4];
    f32 unk_888;
    f32 unk_88C;
};

extern const f32 lbl_1_rodata_446C;
extern const f32 lbl_1_rodata_4470;
extern const f32 lbl_1_rodata_4474;
extern struct fn_1_A2A70_state lbl_1_bss_6EA98;
extern s32 fn_8004BED0(void *);
extern s32 fn_800672E4(s32, u32);

static inline s32 fn_1_A2A70_trunc(f32 x) {
    volatile s32 r = (s32)x; /* volatile: forces the fctiwz stack round trip retail emits */
    return r;
}

#pragma opt_common_subs off
void fn_1_A2A70(u32 flags, s32 n) {
    f32 fzgx_live;
    struct fn_1_A2A70_state *s = &lbl_1_bss_6EA98;
    s32 i;
    s32 v;
    u8 *p;

    if (n > 0) {
        if (flags & 1) {
            s->unk_1C &= ~4;
            s->unk_24 = lbl_1_rodata_446C / (f32)n;
        }
        if (flags & 2) {
            s->unk_1C &= ~8;
            s->unk_28 = lbl_1_rodata_446C / (f32)n;
        }
        if (flags & 4) {
            s->unk_888 = (f32)fn_8004BED0(s->unk_38[0]);
            s->unk_24 = (lbl_1_rodata_446C + (f32)fn_8004BED0(s->unk_38[0])) / (f32)n;
            s->unk_1C &= ~1;
        }
        if (flags & 8) {
            s->unk_88C = (f32)fn_8004BED0(s->unk_38[1]);
            s->unk_28 = (lbl_1_rodata_446C + (f32)fn_8004BED0(s->unk_38[1])) / (f32)n;
            if (flags & 0x40) {
                s->unk_28 = (f32)((fn_8004BED0(s->unk_38[1]) + 600) / n);
                fzgx_live = s->unk_28;
                s->unk_28 = (f32)fn_1_A2A70_trunc(fzgx_live);
                if (s->unk_28 < lbl_1_rodata_4470) {
                    s->unk_28 = lbl_1_rodata_4470;
                }
            }
            s->unk_1C &= ~2;
        }
        p = s->unk_7B0;
        for (i = 0; i < 4; i++) {
            v = fn_800672E4(i, 0xA0100000) / n;
            if (v <= 0) {
                v = 0;
            }
            p[i] = v + 1;
        }
        if (s->unk_24 < lbl_1_rodata_4474) {
            s->unk_24 = lbl_1_rodata_4470;
        }
        if (s->unk_28 < lbl_1_rodata_4474) {
            s->unk_28 = lbl_1_rodata_4470;
        }
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_A2A70 */

/* fzgx:begin fn_1_A2D84 */
void fn_1_A2D84(u32 arg0) {
    if (lbl_1_bss_6F1D8 == 0 && lbl_1_bss_6F1DC <= 0x2D) {
        fn_80067898(arg0);
    }
}
/* fzgx:end fn_1_A2D84 */

/* fzgx:begin fn_1_A2DC4 */
void fn_1_A2DC4(u32 arg0) {
    if (lbl_1_bss_6F1DC <= 0x2D) {
        fn_80067898(arg0);
    }
}
/* fzgx:end fn_1_A2DC4 */

/* fzgx:begin fn_1_A2DF4 */
// Forwards the sound event while sound processing is enabled.
void fn_1_A2DF4(s32 arg0, void *arg1, s32 arg2) {
    if (lbl_1_bss_6EAC6.unk_0 != 0) {
        fn_80063094(arg0, (s32)(void *)(arg1), arg2);
    }
}
/* fzgx:end fn_1_A2DF4 */

/* fzgx:begin fn_1_A2E24 */
// Notifies the sound system when sound processing is enabled.
void fn_1_A2E24(u32 arg0, u32 arg1, s32 arg2) {
    if (lbl_1_bss_6EAC6.unk_0 != 0) {
        fn_800674FC(arg0, arg1, arg2);
    }
}
/* fzgx:end fn_1_A2E24 */

/* fzgx:begin fn_1_A2E5C */
typedef struct {
    u8 unk_0[0x740];
    u8 unk_740;
    u8 unk_741[3];
    u32 unk_744;
    u8 unk_748[4];
    u8 unk_74C[0xE0];
    u8 unk_82C;
} fn_1_A2E5C_SoundState;


typedef struct {
    u8 unk_0[0x6C0];
    s16 unk_6C0;
} fn_1_A2E5C_SoundData;




void fn_1_A2E5C(s32 arg0, s32 arg1) {
    fn_1_A2E5C_SoundState *state = &(*((fn_1_A2E5C_SoundState *)&lbl_1_bss_6EA98));
    s16 local[8];
    u8 *entry;
    s8 i;

    if (fn_1_3F864() != 0) {
        entry = &state->unk_74C[0];
        i = 0;
        while (i < (s8)state->unk_82C) {
            if (arg0 == entry[1] && entry[2] != 0) {
                fn_80067344(1, 0x10, 0xB0270000, entry[2]);
                if (arg1 != 0) {
                    if (state->unk_740 == 0 && state->unk_744 <= 0x2D) {
                        fn_80067898(0xA9090B00);
                    }
                } else if (fn_1_86690(arg0) > 0x28) {
                    fn_1_A2E5C_SoundData *data;
                    u32 snd;
                    s16 half;
                    data = (fn_1_A2E5C_SoundData *)fn_1_86854(fn_1_86690(arg0))->unk_3A0;
                    fn_1_14E9E4(data->unk_6C0, local);
                    half = (s16)(local[4] >> 1);
                    snd = lbl_1_rodata_451C[half];
                    if (state->unk_740 == 0 && state->unk_744 <= 0x2D) {
                        fn_80067898(snd);
                    }
                } else {
                    u32 snd = lbl_1_rodata_4478[fn_1_86690(arg0)];
                    if (state->unk_740 == 0 && state->unk_744 <= 0x2D) {
                        fn_80067898(snd);
                    }
                }
            }
            entry += 0x14;
            i++;
        }
    }
}
/* fzgx:end fn_1_A2E5C */

/* fzgx:begin fn_1_A2FC8 pool */
extern u32 fn_1_864E8(int index);
extern s32 fn_80067344(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern s32 fn_80067898(u32 value);
extern const f32 lbl_1_rodata_4530;  /* 0.25f */
extern const f32 lbl_1_rodata_4474;  /* 0.0f */
extern const f32 lbl_1_rodata_4470;  /* 1.0f */
extern const f32 lbl_1_rodata_4534;  /* 0.125f */
extern const f32 lbl_1_rodata_4538;  /* 0.4f */
extern const f32 lbl_1_rodata_453C;  /* 0.75f */

typedef struct {
    u8 unk_0;
    u8 id;
    u8 sound;
    u8 pad_3[0x11];
} SoundSlot;

typedef struct {
    s8 count;
    s8 timer;
} SoundCounter;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_6EA98;
u8 fzgx_pool_lbl_1_bss_6EA98_gap_6EA9C[0x73C];
u8 lbl_1_bss_6F1D8;
u32 lbl_1_bss_6F1DC;
u8 lbl_1_bss_6F1E0;
u8 fzgx_obj_lbl_1_bss_6F1E1;
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6F1E2;
SoundSlot fzgx_obj_lbl_1_bss_6F1E4[5];
u32 fzgx_pool_lbl_1_bss_6EA98_gap_6F248;
SoundCounter fzgx_obj_lbl_1_bss_6F24C[60];
s8 fzgx_obj_lbl_1_bss_6F2C4;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA98;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6EA9C;
    s = *(u8 *)&lbl_1_bss_6F1D8;
    s = *(u8 *)&lbl_1_bss_6F1DC;
    s = *(u8 *)&lbl_1_bss_6F1E0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E1;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F1E2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E4;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F248;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F24C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F2C4;
}
#pragma section code_type ".text"

void fn_1_A2FC8(s32 id, f32 volume) {
    s32 i;
    s32 found;
    s32 idx;
    u8 sound;
    f32 level;
    s8 *counters;

    found = 0;
    for (i = 0; i < fzgx_obj_lbl_1_bss_6F2C4; i++) {
        if (id == fzgx_obj_lbl_1_bss_6F1E4[i].id) {
            idx = i;
            found = 1;
        }
    }
    if (found == 0) {
        return;
    }

    sound = fzgx_obj_lbl_1_bss_6F1E4[idx].sound;
    if (sound != 0 && fzgx_obj_lbl_1_bss_6F24C[id].count == 0) {
        if (fn_1_864E8(id) & 0x880) {
            return;
        }
        fn_80067344(1, 0x10, 0xB0270000, sound);
        level = volume * lbl_1_rodata_4530;
        level = (level < lbl_1_rodata_4474) ? lbl_1_rodata_4474
              : ((level > lbl_1_rodata_4470) ? lbl_1_rodata_4470 : level);
        if (level < lbl_1_rodata_4534) {
            if (lbl_1_bss_6F1D8 == 0 && lbl_1_bss_6F1DC <= 0x2d) {
                fn_80067898(0xA9090000);
            }
        } else if (level < lbl_1_rodata_4538) {
            if (lbl_1_bss_6F1D8 == 0 && lbl_1_bss_6F1DC <= 0x2d) {
                fn_80067898(0xA9090200);
            }
        } else if (level < lbl_1_rodata_453C) {
            if (lbl_1_bss_6F1D8 == 0 && lbl_1_bss_6F1DC <= 0x2d) {
                fn_80067898(0xA9090500);
            }
        } else {
            if (lbl_1_bss_6F1D8 == 0 && lbl_1_bss_6F1DC <= 0x2d) {
                fn_80067898(0xA9090600);
            }
        }
    }

    fzgx_obj_lbl_1_bss_6F24C[id].count++;
    fzgx_obj_lbl_1_bss_6F24C[id].timer = 0;
    if (fzgx_obj_lbl_1_bss_6F24C[id].count > 6) {
        fzgx_obj_lbl_1_bss_6F24C[id].count = 0;
    }
}
/* fzgx:end fn_1_A2FC8 */

/* fzgx:begin fn_1_A31E4 */
typedef struct {
    u8 unk_0;
    u8 id;      // 0x1
    u8 unk_2;   // 0x2
    u8 pad_3[7];
    u8 unk_A;   // 0xA
    u8 pad_B[9];
} SoundEntry;  // size 0x14

// The sound state cluster, addressed off lbl_1_bss_6EA98.
typedef struct {
    u8 pad_0[0x1C];
    u32 flags_1C;       // 0x1C
    u8 pad_20[0x720];
    u8 busy;            // 0x740
    u8 pad_741[3];
    u32 timer;          // 0x744
    u8 pad_748[4];
    SoundEntry entries[4]; // 0x74C
    u8 pad_79C[0xC];
    s8 last26;          // 0x7A8
    s8 last25;          // 0x7A9
} fn_1_A31E4_SoundState;

typedef struct {
    u8 flags;
    u8 pad_1[5];
} Obj_1_bss_A88_Entry;


// Held in a one-member struct so the base is CSE'd into one register
// instead of being rematerialised at every access.
typedef struct {
    fn_1_A31E4_SoundState *value;
} SoundStateRef;

static inline void play_voice(fn_1_A31E4_SoundState *state, u32 id) {
    if (state->busy == 0 && state->timer <= 0x2d) {
        fn_80067898(id);
    }
}

void fn_1_A31E4(void) {
    s32 n;
    SoundStateRef st;
    SoundEntry *entries;
    s32 cnt26 = 0;
    u8 cnt25 = 0;
    s32 i;
    s32 id;
    u32 flags;
    f32 f;

    st.value = (fn_1_A31E4_SoundState *)&lbl_1_bss_6EA98;
    if (fn_1_3F864() == 0) {
        return;
    }
    n = fn_1_3F854();
    entries = st.value->entries;
    for (i = 0; i < n; i++) {
        id = entries[i].id;
        flags = fn_1_864E8(id);
        if (id == 0xff) continue;
        if (flags & 0x280) continue;
        if ((fn_1_86514(id) >> 27) & 1) {
            if (!(st.value->flags_1C & 0x20)) {
                fn_80067344(1, 7, 0xb0070000, entries[i].unk_A);
            }
            cnt26++;
        }
        if ((((Obj_1_bss_A88_Entry *)lbl_1_bss_A88)[i].flags >> 3) & 1) {
            cnt25++;
        }
        f = fn_1_8652C(id);
        if (((lbl_1_bss_CC0[i] >> 3) & 1) && f > 100.0f) {
            if (fn_1_3F0C8() != 0x28) {
                fn_80067344(1, 0x10, 0xb0270000, entries[i].unk_2);
                play_voice(st.value, 0xa9091500);
            }
        }
    }
    if (st.value->last26 < (u8)cnt26) {
        play_voice(st.value, 0xa9090c00);
    } else if (st.value->last26 > (u8)cnt26) {
        if ((u8)cnt26 == 0) {
            play_voice(st.value, 0xa9090d00);
        }
    }
    if (st.value->last25 > cnt25) {
        if (cnt25 == 0) {
            play_voice(st.value, 0xa9091600);
        }
    }
    st.value->last26 = cnt26;
    st.value->last25 = cnt25;
}
/* fzgx:end fn_1_A31E4 */

/* fzgx:begin fn_1_A33F0 pool */
struct SoundSlot {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 pad_3[0x11];
};

extern const f32 lbl_1_rodata_4544;  /* 0.1f */
extern const f32 lbl_1_rodata_4548;  /* 0.2f */

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 lbl_1_bss_6EA98;
u32 lbl_1_bss_6EA98_gap_4[0x1CF];
u8 lbl_1_bss_6F1D8;
u32 lbl_1_bss_6F1DC;
u8 lbl_1_bss_6F1E0;
u8 lbl_1_bss_6F1E1;
struct SoundSlot lbl_1_bss_6F1E4[0x8];
u8 lbl_1_bss_6EA98_gap_7EC[0x4];
s8 lbl_1_bss_6F244_44[0x1E][2];
s8 lbl_1_bss_6F2C4;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_1_bss_6EA98;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_4;
    s = *(u8 *)&lbl_1_bss_6F1D8;
    s = *(u8 *)&lbl_1_bss_6F1DC;
    s = *(u8 *)&lbl_1_bss_6F1E0;
    s = *(u8 *)&lbl_1_bss_6F1E1;
    s = *(u8 *)&lbl_1_bss_6F1E4;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_7EC;
    s = *(u8 *)&lbl_1_bss_6F244_44;
    s = *(u8 *)&lbl_1_bss_6F2C4;
}
#pragma section code_type ".text"

void fn_1_A33F0(s32 id, f32 level) {
    s8 i;
    s8 played;
    u8 voice;

    played = 0;
    if (fn_1_3F864() == 0) {
        return;
    }

    for (i = 0; i < lbl_1_bss_6F2C4; i++) {
        if (id != lbl_1_bss_6F1E4[i].unk_1) {
            continue;
        }
        if (played > 2) {
            return;
        }
        voice = lbl_1_bss_6F1E4[i].unk_2;
        if (voice != 0 && lbl_1_bss_6F244_44[id][0] == 0) {
            fn_80067344(1, 0x10, 0xB0270000, voice);
            if (level <= lbl_1_rodata_4544) {
                if (lbl_1_bss_6F1D8 == 0 && lbl_1_bss_6F1DC <= 0x2D) {
                    fn_80067898(0xA9090200);
                }
            } else if (level <= lbl_1_rodata_4548) {
                if (lbl_1_bss_6F1D8 == 0 && lbl_1_bss_6F1DC <= 0x2D) {
                    fn_80067898(0xA9090200);
                }
            } else {
                if (lbl_1_bss_6F1D8 == 0 && lbl_1_bss_6F1DC <= 0x2D) {
                    fn_80067898(0xA9090600);
                }
            }
            played++;
        }
        lbl_1_bss_6F244_44[id][0]++;
        lbl_1_bss_6F244_44[id][1] = 0;
        if (lbl_1_bss_6F244_44[id][0] > 6) {
            lbl_1_bss_6F244_44[id][0] = 0;
        }
    }
}
/* fzgx:end fn_1_A33F0 */

/* fzgx:begin fn_1_A358C */
static inline u8 fn_1_A358C_array_read(u8 *array, s32 index) { return array[index]; }
#pragma opt_loop_invariants off
void fn_1_A358C(u32 arg0) {
    u8 *base;
    u8 *temp;
    u8 *entry_74c;
    u8 *entry_830;
    s32 id = arg0;
    s32 i;

    base = (u8 *)&lbl_1_bss_6EA98;
    if (fn_1_3F864() != 0) {
        entry_74c = base + 0x74c;
        entry_830 = base + 0x830;
        i = 0;
        while (i < *(s8 *)(base + 0x82c)) {
            if (id == fn_1_A358C_array_read(entry_74c, 1) && entry_74c[2] != 0) {
                if ((fn_1_864E8( (u32)(id)) & 0x400) != 0) {
                    if ((*(u32 *)entry_830 & 0x400) == 0) {
                        if (*(u8 *)(base + 0x740) == 0) {
                            if (*(u32 *)(base + 0x744) <= 0x2d) {
                                fn_80067898(0xa9091000);
                            }
                        }
                    }
                }
            }
            entry_74c += 0x14;
            entry_830 += 0x4;
            i++;
        }
    }
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_A358C */

/* fzgx:begin fn_1_A3654 pool noprologue */
#include "types.h"

typedef struct SoundCarEntry {
    u8 unk_0;
    u8 unk_1;
    u8 active;
    u8 pad_3[0x11];
} SoundCarEntry;

typedef struct SoundCar {
    u8 pad_0[0x4B0];
    s16 unk_4B0;
} SoundCar;

extern f32 fn_1_8652C(void *);
extern u32 fn_1_864E8(void *);
extern u32 fn_1_864FC(void *);
extern SoundCar *fn_1_86254(void *);
extern s32 fn_80067898(u32);
extern u32 lbl_801A66C8[];

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_1_bss_6EA98[4];
u8 lbl_1_bss_6EA9C_pad[0x73C];
u8 fzgx_obj_lbl_1_bss_6F1D8;
u8 lbl_1_bss_6F1D9_fill;
u16 lbl_1_bss_6F1DA_fill;
u32 fzgx_obj_lbl_1_bss_6F1DC;
u8 fzgx_obj_lbl_1_bss_6F1E0;
u8 fzgx_obj_lbl_1_bss_6F1E1;
u16 lbl_1_bss_6F1E2_fill;
SoundCarEntry lbl_1_bss_6F1E4[11];
u32 lbl_1_bss_6F1E4_fill[2];
u32 lbl_1_bss_6F2C8[4];
u8 fzgx_obj_lbl_1_bss_6F2D8[0x3E];
u16 lbl_1_bss_6F316_fill;
u32 lbl_1_bss_6F318_fill[5];
s16 lbl_1_bss_6F32C[4];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA98;
    s = *(u8 *)&lbl_1_bss_6EA9C_pad;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1D8;
    s = *(u8 *)&lbl_1_bss_6F1D9_fill;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1DC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E1;
    s = *(u8 *)&lbl_1_bss_6F1E2_fill;
    s = *(u8 *)&lbl_1_bss_6F1E4;
    s = *(u8 *)&lbl_1_bss_6F1E4_fill;
    s = *(u8 *)&lbl_1_bss_6F2C8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F2D8;
    s = *(u8 *)&lbl_1_bss_6F316_fill;
    s = *(u8 *)&lbl_1_bss_6F318_fill;
    s = *(u8 *)&lbl_1_bss_6F32C;
}
#pragma section code_type ".text"

#define PLAY_SE(id)                                                                 \
    if (fzgx_obj_lbl_1_bss_6F1D8 == 0 && fzgx_obj_lbl_1_bss_6F1DC <= 45) {          \
        fn_80067898(id);                                                            \
    }

#define ABS(v) __abs(v)

#pragma opt_propagation off
void fn_1_A3654(void *player, u32 id) {
    f32 speed;
    u32 flags;
    u32 flags2;
    SoundCar *obj;
    void *car = player;

    speed = fn_1_8652C(car);
    flags = fn_1_864E8(car);
    flags2 = fn_1_864FC(car);

    if (lbl_1_bss_6F1E4[id].active != 0) {
        if ((flags & 0x8) && !(lbl_1_bss_6F2C8[id] & 0x8)) {
            PLAY_SE(0xA9090E00);
        } else if ((flags & 0x20000) && !(lbl_1_bss_6F2C8[id] & 0x20000)) {
            PLAY_SE(0xA9091D00);
        } else if ((flags & 0x80) && !(lbl_1_bss_6F2C8[id] & 0x80) && !(flags & 0x200)) {
            PLAY_SE(0xA9091100);
        }

        if (flags & 0x100000) {
            PLAY_SE(0xA9091300);
        } else if (flags & 0x80000) {
            PLAY_SE(0xA9091400);
        }

        if (flags & 0x200) {
            return;
        }

        if ((flags & 0x10000) && !(lbl_1_bss_6F2C8[id] & 0x10000)) {
            PLAY_SE(0xA9091C00);
            PLAY_SE(0xA9091600);
        }

        obj = fn_1_86254(car);
        if (ABS((s32)obj->unk_4B0) >= 100 && lbl_1_bss_6F32C[id] == 0 && speed > 100.0f) {
            PLAY_SE(0xA9091B00);
            lbl_1_bss_6F32C[id] = obj->unk_4B0;
        } else if (ABS((s32)obj->unk_4B0) < 100 && lbl_1_bss_6F32C[id] != 0) {
            PLAY_SE(0xA9091C00);
            lbl_1_bss_6F32C[id] = 0;
        }
    }

    if ((flags & 0x80) && !(lbl_1_bss_6F2C8[id] & 0x80)) {
        PLAY_SE(0xA9091C00);
        PLAY_SE(0xA9091600);
        lbl_1_bss_6F32C[id] = 0;
    }

    if ((flags2 & 0x10) && ((lbl_801A66C8[0] + 1) & 7) == 0) {
        PLAY_SE(0xA9092E00);
        PLAY_SE(0xA9091200);
    }
}
/* fzgx:end fn_1_A3654 */

/* fzgx:begin fn_1_A3BD8 pool */
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_6EA98;
u32 fzgx_obj_lbl_1_bss_6EA9C[2];
u8 lbl_1_bss_6EAA4;
u8 lbl_1_bss_6EA98_gap_6EAA5;
u8 lbl_1_bss_6EAA6;
u8 lbl_1_bss_6EA98_gap_6EAA7;
u32 lbl_1_bss_6EAA8[2];
u8 lbl_1_bss_6EAB0;
u8 lbl_1_bss_6EA98_gap_6EAB1;
u16 lbl_1_bss_6EA98_gap_6EAB1_fill_6EAB2;
u32 fzgx_obj_lbl_1_bss_6EAB4[4];
u16 lbl_1_bss_6EAB4_fill_6EAC4;
u16 fzgx_obj_lbl_1_bss_6EAC6;
u32 lbl_1_bss_6EAC6_fill_6EAC8[2];
u32 fzgx_obj_lbl_1_bss_6EAD0[450];
u8 fzgx_obj_lbl_1_bss_6F1D8;
u8 lbl_1_bss_6EA98_gap_6F1D9;
u16 lbl_1_bss_6EA98_gap_6F1D9_fill_6F1DA;
u32 fzgx_obj_lbl_1_bss_6F1DC;
u8 fzgx_obj_lbl_1_bss_6F1E0;
u8 lbl_1_bss_6F1E1;
u16 lbl_1_bss_6EA98_gap_6F1E2;
u8 fzgx_obj_lbl_1_bss_6F1E4;
u8 lbl_1_bss_6F1E4_fill_6F1E5;
u16 lbl_1_bss_6F1E4_fill_6F1E6;
u32 lbl_1_bss_6F1E4_fill_6F1E8[20];
u8 lbl_1_bss_6F1E4_fill_6F238;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA98;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA9C;
    s = *(u8 *)&lbl_1_bss_6EAA4;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6EAA5;
    s = *(u8 *)&lbl_1_bss_6EAA6;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6EAA7;
    s = *(u8 *)&lbl_1_bss_6EAA8;
    s = *(u8 *)&lbl_1_bss_6EAB0;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6EAB1;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6EAB1_fill_6EAB2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAB4;
    s = *(u8 *)&lbl_1_bss_6EAB4_fill_6EAC4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAC6;
    s = *(u8 *)&lbl_1_bss_6EAC6_fill_6EAC8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAD0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1D8;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6F1D9;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6F1D9_fill_6F1DA;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1DC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E0;
    s = *(u8 *)&lbl_1_bss_6F1E1;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6F1E2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E4;
    s = *(u8 *)&lbl_1_bss_6F1E4_fill_6F1E5;
    s = *(u8 *)&lbl_1_bss_6F1E4_fill_6F1E6;
    s = *(u8 *)&lbl_1_bss_6F1E4_fill_6F1E8;
    s = *(u8 *)&lbl_1_bss_6F1E4_fill_6F238;
}
#pragma section code_type ".text"

#pragma opt_lifetimes off
static inline u8 * fn_1_A3BD8_address_2569(u8 * base, s32 offset) {
    u8 * result;
    result = (u8 *)offset;
    result = base + (s32)result;
    return result;
}
void fn_1_A3BD8(s32 arg0, u32 arg1) {
    u8 *entry;
    u8 v;

    
    entry = (u8 *)&fzgx_obj_lbl_1_bss_6F1E4;
    entry = fn_1_A3BD8_address_2569(entry, arg0 * 0x14);
    v = (*((4) + (entry)));
    if ((*((2) + (entry))) != 0) {
        fn_80067344(1, 0x10, 0xB0270000, (*((2) + (entry))));
        fn_80067344(1, 0x10, 0xB02A0000, (s8)v);
        if (fzgx_obj_lbl_1_bss_6F1D8 == 0 && fzgx_obj_lbl_1_bss_6F1DC <= 0x2D) {
            fn_80067898(arg1);
        }
    }
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_A3BD8 */

/* fzgx:begin fn_1_A3C78 */
void fn_1_A3C78(s32 arg0, s32 arg1) {
    u8 *base;
    u8 *entry;

    base = (u8 *)&lbl_1_bss_6EA98;
    if (fn_1_3F864(arg0, arg1) != 0) {
        switch (arg1) {
        case 0:
            if ((fn_1_864E8(arg0) & 0x280) == 0) {
                entry = base + 0x74C;
                arg1 = 0;
                while (arg1 < *(s8 *)(base + 0x82C)) {
                    if (arg0 == *(u8 *)(entry + 1) && *(u8 *)(entry + 2) != 0) {
                        fn_80067344( (s32)(1), (s32)(0x10), 0xB0270000, *(u8 *)(entry + 2));
                        if (base[0x740] == 0 && *(u32 *)(base + 0x744) <= 0x2D) {
                            fn_80067898(0xA9090F00);
                        }
                    }
                    entry += 0x14;
                    arg1++;
                }
            }
            break;
        }
    }
}
/* fzgx:end fn_1_A3C78 */

/* fzgx:begin fn_1_A3D5C noprologue */
#include "types.h"
#include "dolphin/os/OSFastCast.h"

typedef struct {
    f32 x, y, z;
} SndVec;

extern s16 camera_get_mode(void);
extern void fn_1_862D4(void *, SndVec *);
extern s32 fn_1_5910(void);
extern void fn_1_681C(u32, SndVec *);
extern f32 fn_1_8652C(void *);
extern s32 fn_1_58C4(void);
extern u32 lbl_8006DCA4(void);
extern void lbl_8006E1B0(SndVec *, SndVec *);
extern void fn_8006EF10(void *, s16 *, s16 *);
extern f32 lbl_8006D188(s32);
extern u32 OSGetSoundMode(void);

#pragma pool_data off

#define ABS(x) __abs(x)
#define SQ(x) ((x) * (x))
static inline f32 CLAMP(f32 x, f32 lo, f32 hi) {
    if (x < lo) {
        return lo;
    }
    if (x > hi) {
        return hi;
    }
    return x;
}

u8 fn_1_A3D5C(void *obj, s8 *pan, s8 *span, u8 *vol) {
    s32 other;
    f32 distSq;
    f32 fade;
    f32 level;
    f32 balance;
    f32 t;
    u8 ret;
    SndVec local;
    SndVec pos;
    SndVec cam;
    s16 pitch;
    s16 yaw;

    other = camera_get_mode();
    fn_1_862D4(obj, &pos);
    fn_1_681C((u8)fn_1_5910(), &cam);
    {
        f32 dz, dy, dx;
        /* load-then-subtract keeps each load in its difference's register (retail: fsubs f3, f3, f0) */
        dx = cam.x;
        dx -= pos.x;
        dy = cam.y;
        dy -= pos.y;
        dz = cam.z;
        dz -= pos.z;
        distSq = dx * dx;
        distSq += dy * dy;
        distSq += dz * dz;
    }
    if (distSq > 90000.0f) {
        *pan = 0;
        *span = 0;
        *vol = 0;
        return 0;
    }

    lbl_8006DCA4();
    lbl_8006E1B0(&pos, &local);
    fn_8006EF10(&local, &pitch, &yaw);

    balance = fn_1_8652C(obj);
    if (other != -1) {
        t = 0.001f * (balance - fn_1_8652C((void *)other));
        t = (t < -1.0f) ? -1.0f : ((t > 1.0f) ? 1.0f : t);
        if (t < 0.0f) {
            balance = 1.0f - lbl_8006D188((s16)(0.5f * (32768.0f * -t)));
        } else {
            balance = 1.0f + lbl_8006D188((s16)(0.5f * (32768.0f * t)));
        }
    } else {
        balance = 1.0f;
    }

    level = 0.5f * (32768.0f * (distSq / 90000.0f));
    level = lbl_8006D188((s16)(__OSf32tou16(level) + 0x4000));
    level = CLAMP(127.0f * (balance * (level * level)), 0.0f, 127.0f);
    fade = 127.0f * CLAMP(1.0f - distSq / 5625.0f, 0.0f, 1.0f);

    switch (fn_1_58C4()) {
    case 1:
        break;
    case 2:
        level *= 0.9f;
        fade *= 0.9f;
        break;
    case 3:
        level *= 0.85f;
        fade *= 0.85f;
        break;
    case 4:
        level *= 0.8f;
        fade *= 0.8f;
        break;
    }

    ret = __OSf32tou8(level);
    *vol = __OSf32tou8(fade);

    if (ABS(yaw) < 0x4000) {
        *pan = (s8)(0.0039f * (f32)(-yaw));
    } else if (yaw > 0) {
        *pan = (s8)(0.0039f * (f32)(-(0x8000 - yaw)));
    } else {
        *pan = (s8)(0.0039f * (f32)(-(-0x8000 - yaw)));
    }
    *span = (s8)(0.0039 * (ABS(yaw) - 0x4000));

    *pan = (*pan < -64) ? -64 : ((*pan > 63) ? 63 : *pan);
    *span = (*span < -64) ? -64 : ((*span > 63) ? 63 : *span);

    if (OSGetSoundMode() == 0) {
        *pan = 0;
    }
    return ret;
}
/* fzgx:end fn_1_A3D5C */

/* fzgx:begin fn_1_A4BC8 */
typedef struct {
    u8 pad[0x10C];
    s32 field_10C;
    s32 field_110;
} FnA4BC8State;

void fn_1_A4BC8(void *arg0, void *arg1, FnA4BC8State *state) {
    u32 flags;

    flags = fn_1_864E8((int)arg0);
    fn_1_86254((int)arg0);

    if (!(flags & 0x00010880)) {
        if (state->field_10C && state->field_110 &&
            !lbl_1_bss_6F1D8 && lbl_1_bss_6F1DC <= 0x2D) {
            fn_80067898(0xA9061800);
        }

        if ((flags & 0x00040000) &&
            !lbl_1_bss_6F1D8 && lbl_1_bss_6F1DC <= 0x2D) {
            fn_80067898(0xA9092000);
        }
    }
}
/* fzgx:end fn_1_A4BC8 */

/* fzgx:begin fn_1_A4C9C */
void fn_1_A4C9C(s32 index, u8 value) {
    s16 mode;

    mode = (s32)camera_get_mode();
    if (value == lbl_1_bss_6F2D8[index * 2]) {
        return;
    }

    fn_80067344(1, 2, 0xB0270000, 0x7F);

    switch (value) {
    case 2:
        fn_1_A5470(mode);
        lbl_1_bss_6F2D8[index * 2] = value;
        break;
    case 1:
        lbl_1_bss_6F2D8[index * 2] = value;
        break;
    case 3:
        if (((u32)fn_1_3F13C() & 0xFF) == 2 && fn_1_EB0B0() != 0) {
            if ((s32)fn_1_F1B94() == 1) {
                if (lbl_1_bss_6F1DC <= 0x2D) {
                    fn_80067898(0xA9064E00);
                }
                lbl_1_bss_6F2D8[index * 2] = value;
            } else if ((s32)fn_1_F1B94() == 3) {
                if (lbl_1_bss_6F1DC <= 0x2D) {
                    fn_80067898(0xA9064F00);
                }
                lbl_1_bss_6F2D8[index * 2] = value;
            }
        } else {
            if (lbl_1_bss_6F1DC <= 0x2D) {
                fn_80067898(0xA9062200);
            }
            lbl_1_bss_6F2D8[index * 2] = value;
        }
        break;
    }
}
/* fzgx:end fn_1_A4C9C */

/* fzgx:begin fn_1_A4DF4 */
void fn_1_A4DF4(void) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    if (lbl_1_bss_6F1D8 == 0 && lbl_1_bss_6F1DC <= 45) {
    v0 = 0xA9090000;
    v0 += 4608;
    fn_80067898(v0);
    }
    if (lbl_1_bss_6F1D8 == 0 && lbl_1_bss_6F1DC <= 45) {
    v1 = 0xA9090000;
    v1 += 5632;
    fn_80067898(v1);
    }
    if (lbl_1_bss_6F1D8 == 0 && lbl_1_bss_6F1DC <= 45) {
    v2 = 0xA9090000;
    v2 += 7168;
    fn_80067898(v2);
    }
    if (lbl_1_bss_6F1D8 == 0 && lbl_1_bss_6F1DC <= 45) {
    v3 = 0xA9090000;
    v3 += 9216;
    fn_80067898(v3);
    }
    if (lbl_1_bss_6F1D8 == 0 && lbl_1_bss_6F1DC <= 45) {
    v4 = 0xA9090000;
    v4 += 11776;
    fn_80067898(v4);
    }
    if (lbl_1_bss_6F1D8 == 0 && lbl_1_bss_6F1DC <= 45) {
    v5 = 0xA9090000;
    v5 += 3328;
    fn_80067898(v5);
    }
}
/* fzgx:end fn_1_A4DF4 */

/* fzgx:begin fn_1_A4F18 */
void fn_1_A4F18(s32 value) {
    u8 *state = (u8 *)&lbl_1_bss_6EA98;

    if (state[0x7A0] != (u8)value) {
        fn_80067344(1, 0x10, 0xB0270000, 0x7F);

        switch ((u8)value) {
        case 3:
            if (!state[0x740] && *(u32 *)(state + 0x744) <= 0x2D) {
                fn_80067898(0xA9091A00);
            }
            if (!state[0x740] && *(u32 *)(state + 0x744) <= 0x2D) {
                fn_80067898(0xA9060000);
            }
            break;
        case 2:
            if (!state[0x740] && *(u32 *)(state + 0x744) <= 0x2D) {
                fn_80067898(0xA9091A00);
            }
            if (!state[0x740] && *(u32 *)(state + 0x744) <= 0x2D) {
                fn_80067898(0xA9060100);
            }
            break;
        case 1:
            if (!state[0x740] && *(u32 *)(state + 0x744) <= 0x2D) {
                fn_80067898(0xA9091A00);
            }
            if (!state[0x740] && *(u32 *)(state + 0x744) <= 0x2D) {
                fn_80067898(0xA9060200);
            }
            break;
        case 0:
            if (!state[0x740] && *(u32 *)(state + 0x744) <= 0x2D) {
                fn_80067898(0xA9091A00);
            }
            if (!state[0x740] && *(u32 *)(state + 0x744) <= 0x2D) {
                fn_80067898(0xA9060300);
            }
            break;
        }
    }

    state[0x7A0] = value;
}
/* fzgx:end fn_1_A4F18 */

/* fzgx:begin fn_1_A50C8 */
void fn_1_A50C8(s32 index) {
    u32 value;

    if (index > 0x28) {
        value = 0xA9100700;
    } else {
        value = (((u32 *)&lbl_1_rodata_45D0))[index * 2];
    }

    fn_80067344(2, 0xF, 0xB0270000, 0x7F);

    if (!lbl_1_bss_6F1D8 && lbl_1_bss_6F1DC <= 0x2D) {
        fn_80067898(value);
    }
}
/* fzgx:end fn_1_A50C8 */

/* fzgx:begin fn_1_A514C */
void fn_1_A514C(s32 index) {
    u32 offset;
    u32 value;

    if (index <= 0x28) {
        value = lbl_1_rodata_45D0[index * 2 + 1];
        fn_80067344(2, 0xf, 0xb0270000, 0x7f);
        if (lbl_1_bss_6F1D8 == 0 && lbl_1_bss_6F1DC <= 0x2d) {
            fn_80067898(value);
        }
    }
}
/* fzgx:end fn_1_A514C */

/* fzgx:begin fn_1_A51C8 */
void fn_1_A51C8(s16 index) {
    u32 value;

    if (index <= 6) {
        value = lbl_1_rodata_4718[index];
        fn_80067344(2, 0xF, 0xB0270000, 0x7F);

        if (!lbl_1_bss_6F1D8 && lbl_1_bss_6F1DC <= 0x2D) {
            fn_80067898(value);
        }
    }
}
/* fzgx:end fn_1_A51C8 */

/* fzgx:begin fn_1_A5244 */
void fn_1_A5244(u8 index) {
    u32 value;

    if (index <= 0x1D) {
        value = lbl_1_rodata_4730[index];
        fn_80067344(1, 2, 0xB0270000, 0x7F);

        if (lbl_1_bss_6F1DC <= 0x2D) {
            fn_80067898(value);
        }
    }
}
/* fzgx:end fn_1_A5244 */

/* fzgx:begin fn_1_A52B0 */
void fn_1_A52B0(s32 index) {
    u32 value;

    if ((u8)index > 0x1E) {
        return;
    }

    value = lbl_1_rodata_47A8[(u8)index - 1];

    fn_80067344(1, 0xF, 0xB0270000, 0x7F);

    if (!lbl_1_bss_6F1D8 && lbl_1_bss_6F1DC <= 0x2D) {
        fn_80067898(value);
    }
}
/* fzgx:end fn_1_A52B0 */

/* fzgx:begin fn_1_A5330 */
void fn_1_A5330(u8 value, s16 index) {
    lbl_1_bss_6F41C[index] = value;
}
/* fzgx:end fn_1_A5330 */

/* fzgx:begin fn_1_A5344 */
#pragma opt_dead_assignments off
void fn_1_A5344(u8 value, s16 index) {
    u8 *table;
    s32 i;

    table = (*(u8 (*)[])&lbl_1_bss_6EA98) + 0x984;
    if (table[index] > value) {
        for (i = 0; i < (s32)(table[index] - value); i++) {
            if ((value - i) % 10 == 0 &&
                (*(u8 (*)[])&lbl_1_bss_6EA98)[0x740] == 0 &&
                *(u32 *)((*(u8 (*)[])&lbl_1_bss_6EA98) + 0x744) <= 0x2d) {
                fn_80067898(0xa9010300);
            }
        }
    } else if (table[index] < value) {
        for (i = 0; i < (s32)(value - table[index]); i++) {
            if ((value - i) % 10 == 0 &&
                (*(u8 (*)[])&lbl_1_bss_6EA98)[0x740] == 0 &&
                *(u32 *)((*(u8 (*)[])&lbl_1_bss_6EA98) + 0x744) <= 0x2d) {
                fn_80067898(0xa9010300);
            }
        }
    }

    table[index] = value;
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_A5344 */

/* fzgx:begin fn_1_A5470 */
// Starts the requested sound and suppresses playback when the channel limit is reached.
void fn_1_A5470(s32 value) {
    s32 sound_id;
    u32 sound_resource;

    if (value == -1) {
        return;
    }

    sound_id = (s8)value;
    sound_id = (s32)fn_1_86690(sound_id);
    sound_resource = (u32)lbl_1_rodata_4820[(s8)sound_id];

    fn_80067344(1, 0x10, 0xB0270000, 0x7F);
    if (sound_resource != 0 && lbl_1_bss_6F1D8 == 0 &&
        lbl_1_bss_6F1DC <= 0x2D) {
        fn_80067898(sound_resource);
    }
}
/* fzgx:end fn_1_A5470 */

/* fzgx:begin fn_1_A54FC noprologue */
#include "types.h"

typedef struct SoundData {
    u8 pad_000[0x740];
    u8 unk_740;
    u8 pad_741[3];
    u32 unk_744;
    u8 pad_748[0x5c];
    u32 unk_7a4;
    u8 pad_7a8[0xd8];
    s16 unk_880;
} SoundData;

extern SoundData lbl_1_bss_6EA98;
extern void fn_80067898(u32 value);

void fn_1_A54FC(void) {
    u32 flags;

    if ((lbl_1_bss_6EA98.unk_7a4 & 1) == 0 ||
        lbl_1_bss_6EA98.unk_740 != 0) {
        return;
    }

    lbl_1_bss_6EA98.unk_880++;
    if (lbl_1_bss_6EA98.unk_880 == 0x78) {
        if (lbl_1_bss_6EA98.unk_740 == 0 &&
            lbl_1_bss_6EA98.unk_744 <= 0x2d) {
            fn_80067898(0xA9065100);
        }
        flags = lbl_1_bss_6EA98.unk_7a4;
        lbl_1_bss_6EA98.unk_880 = 0;
        lbl_1_bss_6EA98.unk_7a4 = flags & ~1;
    }
}
/* fzgx:end fn_1_A54FC */

/* fzgx:begin fn_1_A5590 */
// fn_1_A5590: empty in retail (single blr).
void fn_1_A5590(void) {
}
/* fzgx:end fn_1_A5590 */

/* fzgx:begin fn_1_A5594 noprologue */
#include "types.h"
#include "dolphin/os/OSFastCast.h"
#include "game/main_rel/car_test_types.h"
#include "rel/main_rel/sound.h"

extern s32 fn_1_5910(void);
extern void fn_1_681C(u32, u32 *);
extern u32 lbl_8006DCA4(void);
extern void lbl_8006E1B0(Fn183D28Vec3 *, Fn183D28Vec3 *);
extern void fn_8006EF10(void *, s16 *, s16 *);
extern u32 OSGetSoundMode(void);
extern s32 fn_80067344(u32, u32, u32, u32);
extern s32 fn_80067898(u32);

extern const f32 lbl_1_rodata_48C4; /* 250000.0f */
extern const f32 lbl_1_rodata_4470; /* 1.0f */
extern const f32 lbl_1_rodata_4474; /* 0.0f */
extern const f32 lbl_1_rodata_4564; /* 127.0f */
extern const f32 lbl_1_rodata_4578; /* 0.0039f */

static inline f32 clamp_value(f32 x, f32 hi, f32 lo)
{
    return x < lo ? lo : (x > hi ? hi : x);
}

void fn_1_A5594(u32 arg0, Fn183D28Vec3 *pos)
{
    Fn183D28Vec3 rel;
    f32 listener[3];
    s16 dist;
    s16 angle;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 scaled;
    struct { f32 value; } distance;
    f32 t;
    u8 vol;
    s8 raw;
    s8 pan;

    fn_1_681C((u8)fn_1_5910(), (u32 *)listener);
    dx = listener[0];
    dx = dx - pos->x;
    dy = listener[1] - pos->y;
    dz = listener[2] - pos->z;
    distance.value = dx * dx;
    distance.value = dy * dy + distance.value;
    distance.value = dz * dz + distance.value;
    if (distance.value > lbl_1_rodata_48C4) {
        return;
    }
    lbl_8006DCA4();
    lbl_8006E1B0(pos, &rel);
    fn_8006EF10(&rel, &dist, &angle);
    {
        struct { f32 value; } hi;
        hi.value = lbl_1_rodata_4470;
        t = hi.value - distance.value / lbl_1_rodata_48C4;
        t = clamp_value(t, hi.value, lbl_1_rodata_4474);
    }
    /* retail: OSFastCast __OSf32tou8 (psq_st ..., 1, qr2; lbz) */
    scaled = lbl_1_rodata_4564 * t;
    vol = __OSf32tou8(scaled);
    if (__abs(angle) < 0x4000) {
        raw = lbl_1_rodata_4578 * -angle;
    } else if (angle > 0) {
        raw = lbl_1_rodata_4578 * -(0x8000 - angle);
    } else {
        raw = lbl_1_rodata_4578 * -(-0x8000 - angle);
    }
    pan = raw < -64 ? -64 : (raw > 63 ? 63 : raw);
    if (OSGetSoundMode() == 0) {
        pan = 0;
    }
    fn_80067344(1, 16, 0xB0270000, vol);
    fn_80067344(1, 16, 0xB02A0000, pan);
    if (lbl_1_bss_6F1D8 == 0 && lbl_1_bss_6F1DC <= 45) {
        fn_80067898(arg0);
    }
    fn_80067344(1, 16, 0xB02A0000, 0);
}
/* fzgx:end fn_1_A5594 */

/* fzgx:begin fn_1_A5848 */
u8 fn_1_A5848(void) {
    return lbl_1_bss_6F1E0;
}
/* fzgx:end fn_1_A5848 */

/* fzgx:begin fn_1_A5858 */
void fn_1_A5858(u8 value) {
    lbl_1_bss_6F1E0 = value;
}
/* fzgx:end fn_1_A5858 */

/* fzgx:begin fn_1_A5864 */
void fn_1_A5864(void) {
    if (lbl_1_bss_6EAD0.unk_0 != 0) {
        if (lbl_1_bss_6EAD0.unk_0->unk_0 != 0 &&
            fn_8004C658( (char *)(u32)(lbl_1_bss_6EAD0.unk_0->unk_0)) == 3) {
            if (fn_8004BBCC(lbl_1_bss_6EAD0.unk_0->unk_0) == 0) {
                ADXT_Pause( (ADXTHandle *)(u32)(lbl_1_bss_6EAD0.unk_0->unk_0), 1);
            }
        }

        if (lbl_1_bss_6EAD0.unk_0->unk_4 != 0 &&
            fn_8004C658( (char *)(u32)(lbl_1_bss_6EAD0.unk_0->unk_4)) == 3) {
            if (fn_8004BBCC(lbl_1_bss_6EAD0.unk_0->unk_4) == 0) {
                ADXT_Pause( (ADXTHandle *)(u32)(lbl_1_bss_6EAD0.unk_0->unk_4), 1);
            }
        }

        if (fn_1_3FC38() != 0) {
            if (lbl_1_bss_6EAC6.unk_0 != 0) {
                fn_800674FC(0x10, 0xA0000300, 0);
            }
            if (lbl_1_bss_6EAC6.unk_0 != 0) {
                fn_800674FC(0x10, 0xA0000400, 0);
            }
            if (lbl_1_bss_6EAC6.unk_0 != 0) {
                fn_800674FC(0, 0xA0020000, 0);
            }
        }
    }
}
/* fzgx:end fn_1_A5864 */

/* fzgx:begin fn_1_A59AC */
// Updates active sound handles and emits the sound-system notification when enabled.
void fn_1_A59AC(void) {
    u8 *sound = (u8 *)&lbl_1_bss_6EA98;

    if (*(u32 *)(sound + 0x38) != 0) {
        if (*(u32 *)(*(u32 *)(sound + 0x38)) != 0 &&
            fn_8004C658( (char *)(u32)(*(u32 *)(*(u32 *)(sound + 0x38)))) == 3 &&
            fn_8004BBCC(*(u32 *)(*(u32 *)(sound + 0x38))) != 0) {
            ADXT_Pause( (ADXTHandle *)(u32)(*(u32 *)(*(u32 *)(sound + 0x38))), 0);
        }

        if (fn_1_3FC38() == 0 || *(u8 *)(sound + 0x749) == 0) {
            if (*(u32 *)(*(u32 *)(sound + 0x38) + 4) != 0 &&
                fn_8004C658( (char *)(u32)(*(u32 *)(*(u32 *)(sound + 0x38) + 4))) == 3 &&
                fn_8004BBCC(*(u32 *)(*(u32 *)(sound + 0x38) + 4)) != 0) {
                ADXT_Pause( (ADXTHandle *)(u32)(*(u32 *)(*(u32 *)(sound + 0x38) + 4)), 0);
            }
        }

        if (fn_1_3FC38() != 0 && *(u8 *)(sound + 0x2e) != 0) {
            fn_800674FC(0, 0xA0030000, 0);
        }
    }
}
/* fzgx:end fn_1_A59AC */

/* fzgx:begin fn_1_A5AA0 noprologue */
#include "types.h"
#include "rel/main_rel/sound.h"

typedef struct A5AA0Obj {
    u32 unk0;
    u8 pad4[0x1C];
    u32 unk20;
    u8 pad24[0x10];
    void (*unk34)(void *);
    u8 pad38[0x10];
    u32 unk48;
} A5AA0Obj;

typedef struct A5AA0Slot {
    A5AA0Obj *unk0;
    u32 unk4;
} A5AA0Slot;

extern u32 lbl_1_bss_6F5C0;
extern u8 lbl_1_bss_6F5C4[44];
extern u8 *lbl_801A6410;
extern u32 fn_1_45D0(void *, u32, void *, int);
extern void OSReport(const char *, ...);
extern void OSPanic(const char *, int, const char *, ...);
extern u32 fn_80006B70(const char *, void *);
extern u32 fn_80006DE8(void *);
extern s32 fn_80006D1C(void *, void *, u32, u32);
extern void fn_80006CE4(void *);
extern s32 fn_80009CD4(void *, u32, void *, int);
extern void OSLinkFixed(void *, u32);
extern void OSLink(void *, u32);

#pragma opt_propagation off
void fn_1_A5AA0(const char *arg0, A5AA0Slot *arg1) {
    u8 *d = (u8 *)&lbl_1_data_33FF0;
    u32 loc[18];
    s32 ok;
    u32 p;
    u32 sz2;
    u32 size;
    A5AA0Obj *o;

    if ((s32)lbl_1_bss_6F5C0 >= 10) {
        OSReport((const char *)(d + 0x148), arg0);
        OSPanic((const char *)(d + 0x150), 0x3b, (const char *)(d + 0x160));
    }
    *(A5AA0Slot **)(lbl_1_bss_6F5C4 + (lbl_1_bss_6F5C0++ << 2)) = arg1;
    arg1->unk0 = 0;
    arg1->unk4 = 0;
    if ((s32)fn_80006B70(arg0, loc) != 0) {
        size = (fn_80006DE8(loc) + 31) & ~31;
        sz2 = size;
        arg1->unk0 = (A5AA0Obj *)fn_1_45D0(lbl_801A6410, size, d + 0x150, 0x48);
        sz2 = fn_80006D1C(loc, arg1->unk0, sz2, 0);
        fn_80006CE4(loc);
        ok = sz2;
        if (ok != 0) {
            o = arg1->unk0;
            p = (((((u32)o) + (31)) + (o->unk48))) & ~31;
            if (p + o->unk20 - (u32)o > size) {
                ok = fn_80009CD4(o, p + o->unk20 - (u32)o, d + 0x150, 0x55);
                if (ok == 0) {
                    p = arg1->unk4 = fn_1_45D0(lbl_801A6410, arg1->unk0->unk20, d + 0x150, 0x58);
                }
            }
            if (ok != 0) {
                OSLinkFixed(arg1->unk0, p);
            } else {
                OSLink(arg1->unk0, p);
            }
            arg1->unk0->unk34(arg1->unk0);
        } else {
            OSReport((const char *)(d + 0x148), arg0);
            OSPanic((const char *)(d + 0x150), 0x64, (const char *)(d + 0x17c));
        }
    } else {
        OSReport((const char *)(d + 0x148), arg0);
        OSPanic((const char *)(d + 0x150), 0x69, (const char *)(d + 0x190));
    }
}
/* fzgx:end fn_1_A5AA0 */
