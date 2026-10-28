#include "types.h"
#include "rel/replay/globals.h"

extern u32 fn_1_D0790(void);
extern u32 lbl_13_bss_38;
extern int fn_13_A40(void);
extern s32 fn_13_A48(void);
extern s16 lbl_1_bss_962;
extern struct fn_13_B08_lbl_13_data_18 lbl_13_data_18;
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;
extern u32 lbl_1_bss_26C60;
extern void fn_13_3FC(void);
extern u32 fn_1_3F038(void);
extern u32 lbl_13_bss_40;
extern u8 lbl_13_bss_3C;
extern u32 lbl_1_bss_7167C;
extern u32 lbl_1_bss_71680;
extern u32 lbl_1_bss_71684;
extern u16 lbl_1_bss_96A;
extern void fn_13_AFC(void);
extern void fn_13_B00(void);
extern void fn_13_B08(void);
extern void fn_1_A8F78(void);

/* fzgx:begin fn_13_0 noprologue */
#include "types.h"

struct fn_13_0_Entry {
    u8 unk_0; u8 unk_1; u8 unk_2; u8 unk_3; u8 unk_4; u8 unk_5;
    u8 unk_6[5]; u8 unk_B;
};
struct fn_13_0_Bss {
    u32 unk_0; s32 unk_4; struct fn_13_0_Entry unk_8[1];
};
struct fn_13_0_Slot { u8 unk_0; u8 unk_1; u8 unk_2; u8 unk_3; u8 unk_4; };
struct fn_13_0_Ghost { u8 unk_0[4]; u8 unk_4[0x81BC]; };
struct fn_13_0_lbl_1_bss_8B3A0 { u8 pad_0[0x8]; u16 unk_8; };
struct fn_13_0_lbl_1_bss_7EFD8 {
    u8 pad_0[0x8]; u32 unk_8; u8 pad_C[0x2C]; u8 unk_38[4]; u8 unk_3C[4];
};
extern struct fn_13_0_lbl_1_bss_8B3A0 lbl_1_bss_8B3A0;
extern struct fn_13_0_lbl_1_bss_7EFD8 lbl_1_bss_7EFD8;
extern u32 lbl_801A63C0;
extern u32 lbl_801A63D0;
extern struct fn_13_0_Slot lbl_1_bss_26B80[];
extern u32 fn_1_F453C(u32, u32 *, u32);
extern struct fn_13_0_Ghost *fn_1_36AD0(void);
extern void fn_1_F47A0(u32);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_1_12F10C(struct fn_13_0_Ghost *);
extern void fn_80008BEC(void *, int, u32);
extern void fn_1_3EF8C(int);
extern void fn_1_3ED8C(int, u8, int, u8, int, u8, int);
extern void fn_1_3EB78(int, u8 *, u8 *, int);
extern void fn_1_3EC88(int, void *);
extern void fn_1_3EFF0(void *, int);
extern void fn_1_3FCB0(s32);
extern void fn_1_3FCD4(s32);
extern void fn_13_A6C(void *);
u32 fzgx_obj_lbl_13_bss_0;
u32 lbl_13_bss_4;
u32 lbl_13_bss_4__fzgx_offset_4;
u8 lbl_13_bss_4__fzgx_offset_8;
u16 lbl_13_bss_4__fzgx_offset_A;
u32 lbl_13_bss_4__fzgx_offset_C[10];
u32 lbl_13_bss_38;
u8 lbl_13_bss_3C;
u8 fzgx_pool_lbl_13_bss_0_gap_3D;
u16 fzgx_pool_lbl_13_bss_0_gap_3D_fill_3E;
u32 lbl_13_bss_40[3];
#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    /* volatile keeps the synthetic storage objects so the compiler cannot elide them */
    volatile u8 s;
    s = *(u8 *)&fzgx_obj_lbl_13_bss_0;
    s = *(u8 *)&lbl_13_bss_4;
    s = *(u8 *)&lbl_13_bss_4__fzgx_offset_4;
    s = *(u8 *)&lbl_13_bss_4__fzgx_offset_8;
    s = *(u8 *)&lbl_13_bss_4__fzgx_offset_A;
    s = *(u8 *)&lbl_13_bss_4__fzgx_offset_C;
    s = *(u8 *)&lbl_13_bss_38;
    s = *(u8 *)&lbl_13_bss_3C;
    s = *(u8 *)&fzgx_pool_lbl_13_bss_0_gap_3D;
    s = *(u8 *)&fzgx_pool_lbl_13_bss_0_gap_3D_fill_3E;
    s = *(u8 *)&lbl_13_bss_40;
}
#pragma section code_type ".text"
static inline u8 * fn_13_0_read_pointer(struct fn_13_0_lbl_1_bss_7EFD8 * owner) { return owner->unk_3C; }
#pragma opt_lifetimes off
#pragma opt_dead_assignments off
void fn_13_0(void) {
    u8 fzgx_value;
    u8 idx;
    u32 count;
    u32 i;
    int n;
    u32 t2;
    u8 unk22;
    u8 flag;
    u8 ver;
    int k;
    u32 j;
    struct { u8 value; } b;
    u8 locC[4];
    u8 loc8[4];
    struct fn_13_0_Entry *e;
    u32 t0;
    lbl_13_bss_4 = 0;
    fzgx_obj_lbl_13_bss_0 = lbl_801A63D0;
    fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 8);
    ver = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 7);
    t2 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 6);
    fn_1_F47A0(fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 32));
    t0 = fzgx_obj_lbl_13_bss_0;
    lbl_801A63C0 = fn_1_F453C(t0, &lbl_13_bss_4, 32);
    count = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 5);
    lbl_1_bss_8B3A0.unk_8 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 3);
    fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 2);
    flag = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 1);
    unk22 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 7);
    n = 0;
    for (i = 0; i < count; i++) {
        (*((((i)) + ((lbl_1_bss_26B80))))).unk_0 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 1);
        (*((lbl_1_bss_26B80) + (i))).unk_1 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 6);
        if (ver >= 3) {
            (*((lbl_1_bss_26B80) + (i))).unk_4 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 5);
        }
        if (ver >= 2) {
            (*((lbl_1_bss_26B80) + (i))).unk_3 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 7);
        }
        if ((*((lbl_1_bss_26B80) + (i))).unk_0 != 0) {
            (*((lbl_1_bss_26B80) + (i))).unk_2 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 2);
            if (ver < 2) {
                (*((((i)) + ((lbl_1_bss_26B80))))).unk_3 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 7);
            }
            idx = (u8)n;
            locC[idx] = (*((lbl_1_bss_26B80) + (i))).unk_1;
            loc8[idx] = (*((lbl_1_bss_26B80) + (i))).unk_2;
            if ((u8)fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 1) != 0) {
                for (j = 0; j < 0x81C0; j++) {
                    b.value = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 8);
                    ((u8 *)&fn_1_36AD0()[i])[j] = b.value;
                }
                t0 = (u32)fn_1_36AD0()[i].unk_4;
                fn_80008BA8(&((struct fn_13_0_Entry *)((u8 *)&lbl_13_bss_4__fzgx_offset_4))[idx], (void *)t0, 0xC);
                fn_1_12F10C(fn_1_36AD0());
            } else {
                e = &((struct fn_13_0_Entry *)((u8 *)&lbl_13_bss_4__fzgx_offset_4))[idx];
                fzgx_value = (*((lbl_1_bss_26B80) + (i))).unk_1;
                e->unk_1 = fzgx_value;
                e->unk_2 = 1 << (*((lbl_1_bss_26B80) + (i))).unk_2;
                e->unk_B = (*((lbl_1_bss_26B80) + (i))).unk_3;
                e->unk_4 = 0;
                e->unk_3 = 0;
                e->unk_5 = 0;
                e->unk_0 = 0;
                fn_80008BEC(((struct fn_13_0_Entry *)((u8 *)&lbl_13_bss_4__fzgx_offset_4))[i].unk_6, 0x41, 5);
            }
            n++;
        } else {
            (*((lbl_1_bss_26B80) + (i))).unk_2 = 0;
            (*((lbl_1_bss_26B80) + (i))).unk_3 = 0;
        }
    }
    if (ver >= 4) {
        for (k = 0; k < (u8)n; k++) {
            fn_13_0_read_pointer(&lbl_1_bss_7EFD8)[k] = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 1);
        }
    }
    for (k = 0; k < (u8)n; k++) {
        lbl_1_bss_7EFD8.unk_38[k] = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 2) + 1;
    }
    if (ver >= 5) {
        lbl_1_bss_7EFD8.unk_8 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 20);
    }
    fn_1_3EF8C(6);
    fn_1_3ED8C(0, unk22, 1, (u8)t2, 10, (u8)count, 0);
    fn_1_3EB78(n, locC, loc8, 0);
    fn_1_3EC88(n, (u8 *)&lbl_13_bss_4__fzgx_offset_4);
    fn_1_3EFF0(fn_13_A6C, 1);
    if (flag != 0) {
        fn_1_3FCB0(0x20000);
    } else {
        fn_1_3FCD4(0x20000);
    }
    fn_1_3FCB0(0x800000);
}
#pragma opt_dead_assignments reset
#pragma opt_lifetimes reset
/* fzgx:end fn_13_0 */

/* fzgx:begin fn_13_3FC */
struct Sig_fn_1_F453C_fn_1_F453C_Arg0 { u8 unk_0[1]; };
struct Sig_fn_1_F453C_fn_1_F453C_Arg1 { u32 unk_0; };
struct fn_13_3FC_lbl_13_bss_0 { u32 unk_0; };
struct replay_vec { f32 x,y,z; };
struct replay_record {
    u32 a:15; u32 c:3; u32 d:5; u32 e:5; u32 reserved0:4;
    u32 b:15; u32 f:5; u32 g:5; u32 h:5; u32 reserved1:2;
    struct replay_vec position[4];
    struct replay_vec velocity[4];
    f32 floats[6];
};
struct replay_frame { u8 a,b,c,d,e,f,g; };
struct replay_buffer {
    u8 pad_0[0xA0]; u16 frame_count; u16 reserved_A2;
    struct replay_frame frames[1];
    u8 pad_AB[0xFEF0-0xAB]; u16 count;
    u8 pad_FEF2[0xFF4C-0xFEF2];
    struct replay_record records[1];
};
struct fn_13_3FC_lbl_1_bss_7EFD8 { u8 pad_0[0x18]; u8 unk_18; u8 pad_19[0x27]; struct replay_buffer *unk_40; };
extern struct fn_13_3FC_lbl_13_bss_0 lbl_13_bss_0;
extern struct fn_13_3FC_lbl_1_bss_7EFD8 lbl_1_bss_7EFD8;
extern u8 lbl_13_bss_4[];
extern u32 fn_1_F453C(struct Sig_fn_1_F453C_fn_1_F453C_Arg0 *, struct Sig_fn_1_F453C_fn_1_F453C_Arg1 *, u32);
extern void fn_1_3EF14(void *);
extern void fn_1_F4794(u16);
extern void fn_80008BA8(void *, const void *, u32);
static inline u32 replay_read(u32 bits) {
    return fn_1_F453C((struct Sig_fn_1_F453C_fn_1_F453C_Arg0 *)lbl_13_bss_0.unk_0, (struct Sig_fn_1_F453C_fn_1_F453C_Arg1 *)lbl_13_bss_4, bits);
}
static inline f32 replay_float(void) {
    u32 bits = replay_read(32);
    f32 value;
    fn_80008BA8(&value, &bits, 4);
    return value;
}
void fn_13_3FC(void) {
    u8 *p_lbl_13_bss_4;
    struct fn_13_3FC_lbl_13_bss_0 *p_lbl_13_bss_0;
    void *v0;
    void *v1;
    s32 v2, v3;
    u32 v4,v5,v6,v7,v8,v9,v10,v11,v12,v13,v14,v15,v16,v17,v18,v19,v20;
    s32 v21,v22;
    u32 v23,v24,v25,v26,v27;
    s32 v28,v29;
    u16 v30; u32 v31,v32,v33;
    struct { u32 a[1326]; } loc_68;
    f32 loc_64; u32 loc_60;
    f32 loc_5C; u32 loc_58;
    f32 loc_54; u32 loc_50;
    f32 loc_4C; u32 loc_48;
    f32 loc_44; u32 loc_40;
    f32 loc_3C; u32 loc_38;
    f32 loc_34; u32 loc_30;
    f32 loc_2C; u32 loc_28;
    f32 loc_24; u32 loc_20;
    f32 loc_1C; u32 loc_18;
    f32 loc_14; u32 loc_10;
    f32 loc_C; u32 loc_8;
    u32 t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t12,t14,t16,t18,t20,t22,t24,t26,t28,t30,t32,t34,t35,t36,t37,t38,t39,t40,t41;
    fn_1_3EF14(&loc_68);
    t1 = replay_read(8);
    p_lbl_13_bss_4 = (u8 *)&lbl_13_bss_4;
    v0 = (u8 *)&lbl_1_bss_7EFD8 + 64;
    lbl_1_bss_7EFD8.unk_40->count = t1;
    v1 = (u8 *)&lbl_1_bss_7EFD8 + 24;
    lbl_1_bss_7EFD8.unk_18 = *(u8 *)((u8 *)&loc_68 + 8);
    p_lbl_13_bss_0 = &lbl_13_bss_0;
    v2 = 0; v3 = 0;
    while(v2 < lbl_1_bss_7EFD8.unk_40->count) {
    lbl_1_bss_7EFD8.unk_40->records[v2].a = replay_read(14);
    lbl_1_bss_7EFD8.unk_40->records[v2].b = replay_read(14);
    lbl_1_bss_7EFD8.unk_40->records[v2].c = replay_read(4);
    lbl_1_bss_7EFD8.unk_40->records[v2].d = replay_read(5);
    lbl_1_bss_7EFD8.unk_40->records[v2].e = replay_read(5);
    lbl_1_bss_7EFD8.unk_40->records[v2].f = replay_read(5);
    lbl_1_bss_7EFD8.unk_40->records[v2].g = replay_read(5);
    lbl_1_bss_7EFD8.unk_40->records[v2].h = replay_read(5);
    v21 = 0; v22 = 0;
    while (v21 < lbl_1_bss_7EFD8.unk_18) {
    lbl_1_bss_7EFD8.unk_40->records[v2].position[v21].x = replay_float();
    lbl_1_bss_7EFD8.unk_40->records[v2].position[v21].y = replay_float();
    lbl_1_bss_7EFD8.unk_40->records[v2].position[v21].z = replay_float();
    lbl_1_bss_7EFD8.unk_40->records[v2].velocity[v21].x = replay_float();
    lbl_1_bss_7EFD8.unk_40->records[v2].velocity[v21].y = replay_float();
    lbl_1_bss_7EFD8.unk_40->records[v2].velocity[v21].z = replay_float();
    v21++;
    }
    lbl_1_bss_7EFD8.unk_40->records[v2].floats[0] = replay_float();
    lbl_1_bss_7EFD8.unk_40->records[v2].floats[1] = replay_float();
    lbl_1_bss_7EFD8.unk_40->records[v2].floats[2] = replay_float();
    lbl_1_bss_7EFD8.unk_40->records[v2].floats[3] = replay_float();
    lbl_1_bss_7EFD8.unk_40->records[v2].floats[4] = replay_float();
    lbl_1_bss_7EFD8.unk_40->records[v2].floats[5] = replay_float();
    v2++;
    }
    t34 = replay_read(14);
    p_lbl_13_bss_4 = (u8 *)&lbl_13_bss_4;
    lbl_1_bss_7EFD8.unk_40->frame_count = t34;
    p_lbl_13_bss_0 = &lbl_13_bss_0;
    v28 = 0; v30 = t34;
    for(v2 = 0; v2 <= lbl_1_bss_7EFD8.unk_40->frame_count; v2++) {
    lbl_1_bss_7EFD8.unk_40->frames[v2].a = replay_read(8);
    lbl_1_bss_7EFD8.unk_40->frames[v2].d = replay_read(8);
    lbl_1_bss_7EFD8.unk_40->frames[v2].e = replay_read(7);
    lbl_1_bss_7EFD8.unk_40->frames[v2].f = replay_read(7);
    lbl_1_bss_7EFD8.unk_40->frames[v2].g = replay_read(8);
    lbl_1_bss_7EFD8.unk_40->frames[v2].b = replay_read(8);
    lbl_1_bss_7EFD8.unk_40->frames[v2].c = replay_read(8);
    }
    fn_1_F4794(lbl_1_bss_7EFD8.unk_40->frame_count);
    lbl_1_bss_7EFD8.unk_40->frame_count = 0;
}
/* fzgx:end fn_13_3FC */

/* fzgx:begin fn_13_A40 */
// fn_13_A40: returns a constant.
int fn_13_A40(void) {
    return 0;
}
/* fzgx:end fn_13_A40 */

/* fzgx:begin fn_13_A48 */
s32 fn_13_A48(void) {
    fn_1_D0790();
    return 0;
}
/* fzgx:end fn_13_A48 */

/* fzgx:begin fn_13_A6C */
struct fn_13_A6C_Arg0 {
    u8 pad_0[0xAC];
    u32 unk_AC;
    u8 pad_B0[0x1C];
    u32 unk_CC;
};

void fn_13_A6C(struct fn_13_A6C_Arg0 *arg0) {
    arg0->unk_CC = (u32)fn_13_A40;
    arg0->unk_AC = (u32)fn_13_A48;
    lbl_13_bss_38 = 0;
}
/* fzgx:end fn_13_A6C */

/* fzgx:begin _prolog */
void _prolog(void) {
    lbl_1_bss_7167C = (u32)fn_13_AFC;
    lbl_1_bss_71680 = (u32)fn_13_B00;
    lbl_1_bss_71684 = (u32)fn_13_B08;
    lbl_1_bss_96A = 0xA7;
    fn_1_A8F78();
    lbl_13_bss_3C = 0;
}
/* fzgx:end _prolog */

/* fzgx:begin fn_13_AFC */
// fn_13_AFC: empty in retail (single blr).
void fn_13_AFC(void) {
}
/* fzgx:end fn_13_AFC */

/* fzgx:begin fn_13_B00 */
// fn_13_B00: empty in retail (single blr).
void fn_13_B00(void) {
}
/* fzgx:end fn_13_B00 */

/* fzgx:begin _epilog */
// _epilog: empty in retail (single blr).
void _epilog(void) {
}
/* fzgx:end _epilog */

/* fzgx:begin fn_13_B08 */
typedef u32 (*fn_13_B08_Fn0)(void);
struct fn_13_B08_lbl_13_data_18_0_E16 {
    u8 pad_0[0x4];
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
};
struct fn_13_B08_lbl_13_data_18 {
    struct fn_13_B08_lbl_13_data_18_0_E16 unk_0[1];
};

void fn_13_B08(void) {
    s32 index;
    struct fn_13_B08_lbl_13_data_18_0_E16 *p;
    index = lbl_1_bss_962;
    index -= 167;
    p = &lbl_13_data_18.unk_0[0];
    p += index;
    lbl_1_bss_71688 = p->unk_8;
    lbl_1_bss_7168C = p->unk_C;
    ((fn_13_B08_Fn0)p->unk_4)();
}
/* fzgx:end fn_13_B08 */

/* fzgx:begin fn_13_B64 */
void fn_13_B64(void) {
    lbl_1_bss_26C60 = (u32)fn_13_3FC;
}
/* fzgx:end fn_13_B64 */

/* fzgx:begin fn_13_B78 */
// fn_13_B78: empty in retail (single blr).
void fn_13_B78(void) {
}
/* fzgx:end fn_13_B78 */

/* fzgx:begin fn_13_B7C */
struct fn_13_B7C_lbl_13_bss_3C {
    u8 unk_0;
};

void fn_13_B7C(void) {
    u32 t0;
    t0 = fn_1_3F038();
    if ((s32)t0 != 0) {
    (*(struct fn_13_B7C_lbl_13_bss_3C *)&lbl_13_bss_3C).unk_0 = 1;
    lbl_1_bss_96A = 169;
    lbl_13_bss_40 = 167;
    }
}
/* fzgx:end fn_13_B7C */
