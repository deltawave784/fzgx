#include "types.h"

/* fzgx:begin fn_8_67F8 */
struct fn_8_67F8_lbl_8_bss_2B8 {
    u32 unk_0;
};
struct fn_8_67F8_lbl_8_bss_2BC {
    u32 unk_0;
};

extern struct fn_8_67F8_lbl_8_bss_2B8 lbl_8_bss_2B8;
extern struct fn_8_67F8_lbl_8_bss_2BC lbl_8_bss_2BC;
extern u32 fn_1_3F8C0(void);
extern u32 fn_1_46B4(u32, u32, u32, u32);
extern u32 fn_80008E84(u32);
extern u32 fn_8_8C80(u32);
extern u32 lbl_801A6410;
extern u32 lbl_8_data_8AD4;
extern void fn_1_14DBCC(void *);
extern void fn_1_48140(int);

void fn_8_67F8(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    u32 v6;
    u32 v7;
    u32 v8;
    s32 v9;
    u32 t0, t1, t4, t6, t7;
    t0 = fn_1_3F8C0();
    t1 = fn_80008E84(t0);
    fn_1_48140(148);
    v0 = lbl_8_bss_2B8.unk_0;
    v1 = arg1;
    v2 = v0;
    v3 = arg2;
    v4 = arg3;
    if (v0 != 0) {
    fn_1_14DBCC((void *)v2);
    v3 = (u32)&lbl_801A6410;
    v4 = (u32)&lbl_8_bss_2B8;
    v2 = *(u32 *)((u8 *)v3 + 0);
    v3 = (u32)&lbl_8_data_8AD4;
    v1 = *(u32 *)((u8 *)v4 + 0);
    v4 = 1035;
    t4 = fn_1_46B4(v2, v1, (u32)v3, v4);
    v2 = t4;
    lbl_8_bss_2B8.unk_0 = 0;
    }
    v5 = lbl_8_bss_2BC.unk_0;
    v6 = v1;
    v7 = v5;
    v8 = v3;
    v9 = v4;
    if (v5 != 0) {
    fn_1_14DBCC((void *)v7);
    v8 = (u32)&lbl_801A6410;
    v9 = (u32)&lbl_8_bss_2BC;
    v7 = *(u32 *)((u8 *)v8 + 0);
    v8 = (u32)&lbl_8_data_8AD4;
    v6 = *(u32 *)((u8 *)v9 + 0);
    v9 = 1040;
    t6 = fn_1_46B4(v7, v6, (u32)v8, v9);
    v7 = t6;
    lbl_8_bss_2BC.unk_0 = 0;
    }
    t7 = fn_80008E84(t1);
    fn_8_8C80(t7);
}
/* fzgx:end fn_8_67F8 */

/* fzgx:begin fn_8_68D8 */
extern u32 lbl_8_bss_2A8;
extern u32 lbl_8_bss_2C0;

void fn_8_68D8(void) {
    lbl_8_bss_2C0 = 4;
    lbl_8_bss_2A8 = 0;
}
/* fzgx:end fn_8_68D8 */

/* fzgx:begin fn_8_68F4 */
extern struct fn_8_68F4_lbl_8_bss_2C0 lbl_8_bss_2C0;
extern u32 fn_1_411A4(u32);
extern u32 fn_1_4630(u32, u32, u32, u32);
extern u32 fn_1_46B4(u32, u32, u32, u32);
extern u32 fn_8_8C48(void);
extern u32 fn_8_8E00(void);
extern u32 fn_8_988C(void);
extern u32 fn_8_9B04(void);
extern u32 lbl_801A6410;
extern u32 lbl_801A66B4;
extern u32 lbl_8_bss_2B0;
extern u32 lbl_8_data_8AD4;

struct fn_8_68F4_lbl_8_bss_2C0 {
    u32 unk_0;
};

u32 fn_8_68F4(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 t0, t1, t2, t3, t4, t5, t6, t7;
    v0 = lbl_8_bss_2C0.unk_0;
    if ((s32)lbl_8_bss_2C0.unk_0 == 1) {
    v1 = arg2;
    v2 = arg3;
    if (lbl_8_bss_2B0 != 0) {
    v2 = (u32)&lbl_801A6410;
    v1 = (u32)&lbl_8_data_8AD4;
    v0 = *(u32 *)((u8 *)v2 + 0);
    v2 = 1152;
    t0 = fn_1_46B4(v0, lbl_8_bss_2B0, (u32)v1, v2);
    v0 = t0;
    }
    v2 = (u32)&lbl_801A6410;
    v1 = (u32)&lbl_8_data_8AD4;
    v0 = *(u32 *)((u8 *)v2 + 0);
    v2 = 1154;
    t1 = fn_1_4630(v0, (0x90000 - 16384), (u32)v1, v2);
    v0 = t1;
    lbl_8_bss_2B0 = v0;
    if ((s32)lbl_801A66B4 == 5) {
    v0 = 4;
    t2 = fn_1_411A4(v0);
    v0 = t2;
    } else {
    v0 = 5;
    t3 = fn_1_411A4(v0);
    v0 = t3;
    }
    t4 = fn_8_988C();
    v0 = t4;
    t5 = fn_8_9B04();
    v0 = t5;
    t6 = fn_8_8C48();
    v0 = t6;
    v3 = lbl_8_bss_2C0.unk_0;
    v0 = v3;
    lbl_8_bss_2C0.unk_0 = (v0 - 1);
    } else {
    lbl_8_bss_2C0.unk_0 = (v0 - 1);
    if ((s32)v0 <= 0) {
    t7 = fn_8_8E00();
    v0 = t7;
    }
    }
    return v0;
}
/* fzgx:end fn_8_68F4 */

/* fzgx:begin fn_8_69D8 */
extern struct fn_8_69D8_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_412A0(u32);
extern u32 fn_1_46B4(u32, u32, u32, u32);
extern u32 lbl_801A66B4;
extern u32 lbl_8_bss_2B0;
extern u32 lbl_8_data_8AD4;

struct fn_8_69D8_lbl_801A6410 {
    u32 unk_0;
};

void fn_8_69D8(void) {
    if ((s32)lbl_801A66B4 == 5) {
    fn_1_412A0(4);
    } else {
    fn_1_412A0(5);
    }
    if (lbl_8_bss_2B0 != 0) {
    fn_1_46B4(lbl_801A6410.unk_0, lbl_8_bss_2B0, (u32)&lbl_8_data_8AD4, 1199);
    lbl_8_bss_2B0 = 0;
    }
}
/* fzgx:end fn_8_69D8 */

/* fzgx:begin fn_8_6A50 */
struct fn_8_6A50_lbl_8_bss_2A8 {
    u32 unk_0;
    u8 pad_4[0x14];
    u32 unk_18;
    u32 unk_1C;
};

extern struct fn_8_6A50_lbl_8_bss_2A8 lbl_8_bss_2A8;

void fn_8_6A50(void) {
    struct fn_8_6A50_lbl_8_bss_2A8 *p_lbl_8_bss_2A8;
    p_lbl_8_bss_2A8 = (struct fn_8_6A50_lbl_8_bss_2A8 *)&lbl_8_bss_2A8;
    p_lbl_8_bss_2A8->unk_1C = 0;
    p_lbl_8_bss_2A8->unk_18 = 4;
    p_lbl_8_bss_2A8->unk_0 = 0;
}
/* fzgx:end fn_8_6A50 */

/* fzgx:begin fn_8_6A70 */
struct fn_8_6A70_lbl_8_bss_2A8 {
    u8 pad_0[0x18];
    u32 unk_18;
    u8 pad_1C[0x4];
    u32 unk_20;
    u8 pad_24[0xF0];
    u32 unk_114;
    u32 unk_118;
    u32 unk_11C;
    u32 unk_120;
};

struct fn_8_6A70_lbl_801A63C0 {
    u32 unk_0;
};

extern struct fn_8_6A70_lbl_801A63C0 lbl_801A63C0;
extern struct fn_8_6A70_lbl_8_bss_2A8 lbl_8_bss_2A8;
extern u32 lbl_801A66B4;
extern u32 fn_1_3EB78(u32, u32, u32, u32);
extern u32 fn_1_3ED8C(u32, u32, u32, u32, u32, u32, u32);
extern u32 fn_8_BD08(void);
extern void fn_8_663C(void);
extern void fn_8_67F8(u32, u32, u32, u32);
extern void fn_1_3EF08(u8);
extern void fn_1_3EF8C(u8);
extern void fn_1_3EFF0(u32, u8);
extern void fn_1_3F02C(u32);
extern void fn_1_411A4(u32);
extern void fn_80008BEC(void *, int, u32);

void fn_8_6A70(void) {
    struct fn_8_6A70_lbl_8_bss_2A8 *p_lbl_8_bss_2A8;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    s32 v4;
    s32 v5;
    u32 v6;
    u32 v7;

    p_lbl_8_bss_2A8 = (struct fn_8_6A70_lbl_8_bss_2A8 *)&lbl_8_bss_2A8;
    v0 = p_lbl_8_bss_2A8->unk_18;
    if ((s32)v0 == 1) {
        v0 = 0x2AAB0000;
        v1 = lbl_801A63C0.unk_0;
        v2 = (v0 - 21845);
        v0 = (v1 * (0x676A0000 + 19307));
        v3 = (v0 + 13259);
        v0 = ((v3 >> 16) & 0x7FFF);
        lbl_801A63C0.unk_0 = v3;
        v4 = ((s32)v0 >> 8);
        v5 = v4 % 6;
        switch (v5) {
        case 0:
            v6 = 31;
            break;
        case 1:
            v6 = 32;
            break;
        case 2:
            v6 = 33;
            break;
        case 3:
            v6 = 34;
            break;
        case 4:
            v6 = 35;
            break;
        default:
            v6 = 36;
        }
        v0 = 6;
        fn_1_3EF8C(v0);
        v0 = 0;
        fn_1_3ED8C(v0, 3, 1, (v6 & 0xFF), 10, 15, 0);
        v0 = 0;
        fn_1_3EB78(v0, 0, 0, 0);
        v0 = (u32)&fn_8_663C;
        fn_1_3EFF0(v0, 1);
        v0 = (u32)&fn_8_67F8;
        fn_1_3F02C(v0);
        v0 = 0;
        fn_1_3EF08(v0);
        p_lbl_8_bss_2A8->unk_20 = 0;
        if ((s32)lbl_801A66B4 == 5) {
            v0 = 4;
            fn_1_411A4(v0);
        } else {
            v0 = 5;
            fn_1_411A4(v0);
        }
        v7 = p_lbl_8_bss_2A8->unk_18;
        p_lbl_8_bss_2A8->unk_18 = (v7 - 1);
        fn_80008BEC((void *)((u8 *)p_lbl_8_bss_2A8 + 36), 0, 60);
        v0 = (u32)((u8 *)p_lbl_8_bss_2A8 + 96);
        fn_80008BEC((void *)v0, 0, 60);
        v0 = (u32)((u8 *)p_lbl_8_bss_2A8 + 156);
        fn_80008BEC((void *)v0, 0, 60);
        v0 = (u32)((u8 *)p_lbl_8_bss_2A8 + 216);
        fn_80008BEC((void *)v0, 0, 60);
        p_lbl_8_bss_2A8->unk_114 = 0;
        p_lbl_8_bss_2A8->unk_118 = 0;
        p_lbl_8_bss_2A8->unk_11C = 0;
        p_lbl_8_bss_2A8->unk_120 = 0;
    } else {
        p_lbl_8_bss_2A8->unk_18 = (v0 - 1);
        if ((s32)v0 <= 0) {
            fn_8_BD08();
        }
    }
}
/* fzgx:end fn_8_6A70 */

/* fzgx:begin fn_8_6C50 */
extern u32 fn_1_412A0(u32);
extern u32 lbl_801A66B4;

void fn_8_6C50(void) {
    if ((s32)lbl_801A66B4 == 5) {
    fn_1_412A0(4);
    } else {
    fn_1_412A0(5);
    }
}
/* fzgx:end fn_8_6C50 */

/* fzgx:begin fn_8_8440 */
#include "rel/title/operation.h"

extern s32 lbl_801A66B4;
extern void fn_1_A2D84(u32);
extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32,f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32,f32);
extern void fn_1_495A0(f32);
extern void fn_1_4D0A0(void);
extern void fn_1_49738(void (*)(void));
extern void fn_1_5233C(void);
extern void fn_1_49748(f32);
extern void fn_1_4AE0C(const char *,...);
typedef struct { u8 r,g,b,a; } Color;
extern void fn_1_4D0D4(void *,f32);
typedef struct { u8 pad[0xa2c]; const char *a[21]; const char *b[11]; const char *c[11]; } TextData;
extern u32 fn_8_CC4C(u32,u32);
extern void pool_f32(f32);
extern void pool_f64(f64);
#pragma push
#pragma force_active on
#pragma section code_type ".fzgxpool"
void shared_pool_primer(s32 n) {
    pool_f64(15.0);
    pool_f32(320.0f);
    pool_f32(640.0f);
    pool_f64(1.0);
    pool_f32(150.0f);
    pool_f32(0.1f);
    pool_f32(20.0f);
    pool_f32(0.8333333f);
    pool_f64(4503601774854144.0);
}
void shared_pool_primer_b(void) {
    { Color white = {255,255,255,0}; fn_1_4D0D4(&white,20.0f); }
    pool_f32(0.0f);
    pool_f32(1.0f);
    pool_f32(0.5f);
    pool_f32(0.09f);
    pool_f32(5.0f);
    pool_f32(255.0f);
}
void shared_pool_primer_c(void) {
    struct { Color first[6]; f32 scale; Color last[2]; } colors = {
        {{255,255,255,0}, {255,255,255,0}, {255,255,255,0},
         {255,255,255,0}, {255,255,255,0}, {255,255,255,0}},
        0.3f, {{255,255,255,0}, {255,255,255,0}}
    };
    fn_1_4D0D4(&colors,20.0f);
}
#pragma pop
#pragma push
#pragma opt_propagation off
#pragma opt_lifetimes off
void fn_8_8440(void) {
    s32 x;
    f32 t;
    f32 alpha;
    TextData *data = (TextData *)&lbl_8_data_7E50;
    Color color;
    if ((s32)lbl_8_bss_3CC == (s32)lbl_8_bss_3D0.unk_0 - 1)
        fn_1_A2D84(0xA9120200);
    if ((s32)lbl_8_bss_3CC < 15.0) {
        t = 1.0 - (f32)(s32)lbl_8_bss_3CC / 15.0;
        x = 320.0f + (f32)(640.0f * t);
    } else if ((s32)lbl_8_bss_3CC > (s32)lbl_8_bss_3D0.unk_0 - 15.0) {
        t = 1.0 - (f32)((s32)lbl_8_bss_3D0.unk_0 - (s32)lbl_8_bss_3CC) / 15.0;
        x = 320.0f - (f32)(640.0f * t);
    } else {
        t = 0.0f;
        x = 320;
    }
    alpha = (1.0f-t)*(1.0f-t);
    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_49590(0.5f);
    fn_1_495C8(9);
    fn_1_496FC(x,150.0f);
    fn_1_4954C(0.09f);
    if (lbl_801A66B4 == 5) fn_1_4955C(1.0f,1.0f);
    else fn_1_4955C(0.8333333f,0.8333333f);
    fn_1_495A0(alpha);
    fn_1_4D0A0();
    fn_1_49738(fn_1_5233C);
    fn_1_49748(5.0f);
    { const char *text = (const char *)data->a; text = ((const char **)text)[lbl_801A66B4]; fn_1_4AE0C(text); }
    fn_1_49738(0);
    { const char *text = (const char *)data->b; text = ((const char **)text)[lbl_801A66B4]; fn_1_4AE0C(text); }
    { const char *text = (const char *)data->c; text = ((const char **)text)[lbl_801A66B4]; fn_1_4AE0C(text); }
    {
        Color white = {255,255,255,0};
        white.a = (s32)(255.0f*alpha);
        color = white;
        fn_1_4D0D4(&color,20.0f);
    }
    fn_8_CC4C(505,394);
}
/* fzgx:end fn_8_8440 */

/* fzgx:begin fn_8_86FC */
#include "rel/title/operation.h"

extern s32 lbl_801A66B4;
extern void fn_1_A2D84(u32);
extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32,f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32,f32);
extern void fn_1_495A0(f32);
extern void fn_1_4D0A0(void);
extern void fn_1_5233C(void);
extern void fn_1_49738(void (*)(void));
extern void fn_1_49748(f32);
extern void fn_1_4AE0C(const char *,...);
typedef struct { u8 r,g,b,a; } Color;
extern u8 fn_8_8C48__fzgx_offset_0[];
extern u8 fn_8_8C80__fzgx_offset_0[];
extern u8 fn_8_8E00__fzgx_offset_0[];
extern u8 fn_8_988C__fzgx_offset_0[];
extern u8 fn_8_9B04__fzgx_offset_0[];
extern u8 fn_8_9B40__fzgx_offset_0[];
extern u8 lbl_8_data_7E50__fzgx_offset_0[];
extern u8 lbl_8_data_7E54__fzgx_offset_0[];
extern u8 lbl_8_data_7E60__fzgx_offset_0[];
extern u8 lbl_8_data_7E6C__fzgx_offset_0[];
extern u8 lbl_8_data_7E78__fzgx_offset_0[];
extern u8 lbl_8_data_7E84__fzgx_offset_0[];
extern u8 lbl_8_data_7E8C__fzgx_offset_0[];
extern u8 lbl_8_data_7E94__fzgx_offset_0[];
extern u8 lbl_8_data_7E9C__fzgx_offset_0[];
extern u8 lbl_8_data_7EA4__fzgx_offset_0[];
extern u8 lbl_8_data_7EB0__fzgx_offset_0[];
extern u8 lbl_8_data_7EC0__fzgx_offset_0[];
extern u8 lbl_8_data_7ED0__fzgx_offset_0[];
extern u8 lbl_8_data_7ED8__fzgx_offset_0[];
extern u8 lbl_8_data_7EE0__fzgx_offset_0[];
extern u8 lbl_8_data_7EEC__fzgx_offset_0[];
extern u8 lbl_8_data_7EF8__fzgx_offset_0[];
extern u8 lbl_8_data_7F08__fzgx_offset_0[];
extern u8 lbl_8_data_7F10__fzgx_offset_0[];
extern u8 lbl_8_data_7F1C__fzgx_offset_0[];
extern u8 lbl_8_data_7F28__fzgx_offset_0[];
extern u8 lbl_8_data_7F38__fzgx_offset_0[];
extern u8 lbl_8_data_7F40__fzgx_offset_0[];
extern u8 lbl_8_data_7F4C__fzgx_offset_0[];
extern u8 lbl_8_data_7F58__fzgx_offset_0[];
extern u8 lbl_8_data_7F68__fzgx_offset_0[];
extern u8 lbl_8_data_7F70__fzgx_offset_0[];
extern u8 lbl_8_data_7F7C__fzgx_offset_0[];
extern u8 lbl_8_data_7F84__fzgx_offset_0[];
extern u8 lbl_8_data_7F90__fzgx_offset_0[];
extern u8 lbl_8_data_7FA0__fzgx_offset_0[];
extern u8 lbl_8_data_7FAC__fzgx_offset_0[];
extern u8 lbl_8_data_7FB8__fzgx_offset_0[];
extern u8 lbl_8_data_7FC0__fzgx_offset_0[];
extern u8 lbl_8_data_7FD4__fzgx_offset_0[];
extern u8 lbl_8_data_7FE4__fzgx_offset_0[];
extern u8 lbl_8_data_7FF4__fzgx_offset_0[];
extern u8 lbl_8_data_8000__fzgx_offset_0[];
extern u8 lbl_8_data_800C__fzgx_offset_0[];
extern u8 lbl_8_data_801C__fzgx_offset_0[];
extern u8 lbl_8_data_8024__fzgx_offset_0[];
extern u8 lbl_8_data_8030__fzgx_offset_0[];
extern u8 lbl_8_data_8038__fzgx_offset_0[];
extern u8 lbl_8_data_8040__fzgx_offset_0[];
extern u8 lbl_8_data_8048__fzgx_offset_0[];
extern u8 lbl_8_data_8104__fzgx_offset_0[];
extern u8 lbl_8_data_8110__fzgx_offset_0[];
extern u8 lbl_8_data_8118__fzgx_offset_0[];
extern u8 lbl_8_data_8124__fzgx_offset_0[];
extern u8 lbl_8_data_812C__fzgx_offset_0[];
extern u8 lbl_8_data_8138__fzgx_offset_0[];
extern u8 lbl_8_data_8140__fzgx_offset_0[];
extern u8 lbl_8_data_8148__fzgx_offset_0[];
extern u8 lbl_8_data_816C__fzgx_offset_0[];
extern u8 lbl_8_data_8174__fzgx_offset_0[];
extern u8 lbl_8_data_819C__fzgx_offset_0[];
extern u8 lbl_8_data_81AC__fzgx_offset_0[];
extern u8 lbl_8_data_81B0__fzgx_offset_0[];
extern u8 lbl_8_data_81D4__fzgx_offset_0[];
extern u8 lbl_8_data_81E0__fzgx_offset_0[];
extern u8 lbl_8_data_8208__fzgx_offset_0[];
extern u8 lbl_8_data_8214__fzgx_offset_0[];
extern u8 lbl_8_data_823C__fzgx_offset_0[];
extern u8 lbl_8_data_8248__fzgx_offset_0[];
extern u8 lbl_8_data_8270__fzgx_offset_0[];
extern u8 lbl_8_data_827C__fzgx_offset_0[];
extern u8 lbl_8_data_82A4__fzgx_offset_0[];
extern u8 lbl_8_data_82C0__fzgx_offset_0[];
extern u8 lbl_8_data_82FC__fzgx_offset_0[];
extern u8 lbl_8_data_8328__fzgx_offset_0[];
extern u8 lbl_8_data_835C__fzgx_offset_0[];
extern u8 lbl_8_data_8368__fzgx_offset_0[];
extern u8 lbl_8_data_8394__fzgx_offset_0[];
extern u8 lbl_8_data_83B8__fzgx_offset_0[];
extern u8 lbl_8_data_83FC__fzgx_offset_0[];
extern u8 lbl_8_data_8438__fzgx_offset_0[];
extern u8 lbl_8_data_8448__fzgx_offset_0[];
extern u8 lbl_8_data_8470__fzgx_offset_0[];
extern u8 lbl_8_data_8490__fzgx_offset_0[];
extern u8 lbl_8_data_84D0__fzgx_offset_0[];
extern u8 lbl_8_data_84DC__fzgx_offset_0[];
extern u8 lbl_8_data_8504__fzgx_offset_0[];
extern u8 lbl_8_data_8528__fzgx_offset_0[];
extern u8 lbl_8_data_856C__fzgx_offset_0[];
extern u8 lbl_8_data_8578__fzgx_offset_0[];
extern u8 lbl_8_data_85A0__fzgx_offset_0[];
extern u8 lbl_8_data_85D8__fzgx_offset_0[];
extern u8 lbl_8_data_8618__fzgx_offset_0[];
extern u8 lbl_8_data_8644__fzgx_offset_0[];
extern u8 lbl_8_data_868C__fzgx_offset_0[];
extern u8 lbl_8_data_8698__fzgx_offset_0[];
extern u8 lbl_8_data_86BC__fzgx_offset_0[];
extern u8 lbl_8_data_86E8__fzgx_offset_0[];
extern u8 lbl_8_data_871C__fzgx_offset_0[];
extern u8 lbl_8_data_874C__fzgx_offset_0[];
extern u8 lbl_8_data_8788__fzgx_offset_0[];
extern u8 lbl_8_data_87B4__fzgx_offset_0[];
extern u8 lbl_8_data_87F4__fzgx_offset_0[];
extern u8 lbl_8_data_881C__fzgx_offset_0[];
extern u8 lbl_8_data_8858__fzgx_offset_0[];
extern u8 lbl_8_data_8868__fzgx_offset_0[];
extern u8 lbl_8_data_8894__fzgx_offset_0[];
extern u8 lbl_8_data_88AC__fzgx_offset_0[];
extern u8 lbl_8_data_88E8__fzgx_offset_0[];
extern u8 lbl_8_data_8914__fzgx_offset_0[];
extern u8 lbl_8_data_891C__fzgx_offset_0[];
extern u8 lbl_8_data_893C__fzgx_offset_0[];
extern u8 lbl_8_data_8958__fzgx_offset_0[];
extern u8 lbl_8_data_898C__fzgx_offset_0[];
extern u8 lbl_8_data_89B0__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_8_data_7E50[693] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4E4F4E00, 0x4D415354, 0x45522052, 0x45435600, 0x4D415354, 0x45522053, 0x454E4400, 0x534C4156,
    0x45205345, 0x4E440000, 0x534C4156, 0x45205245, 0x43560000, 0x494E4954, 0x0, 0x54455354,
    0x0, 0x54455354, 0x454E4400, 0x53455455, 0x50000000, 0x53455455, 0x505F444F, 0x4E450000,
    0x53455455, 0x505F434F, 0x554E5445, 0x52000000, 0x53455455, 0x505F434E, 0x545F444F, 0x4E450000,
    0x554E4C49, 0x4E4B0000, 0x434F494E, 0x0, 0x454E5452, 0x595F5741, 0x49540000, 0x4348414C,
    0x4C454E47, 0x45520000, 0x4348414C, 0x4C454E47, 0x45525F4F, 0x4B000000, 0x454E5452, 0x59000000,
    0x454E5452, 0x595F4F4B, 0x0, 0x53494E47, 0x4C454348, 0x45434B00, 0x53494E47, 0x4C454348,
    0x45434B5F, 0x4F4B0000, 0x434F5552, 0x53450000, 0x434F5552, 0x53455F4F, 0x4B000000, 0x434F5552,
    0x53455F44, 0x41544100, 0x434F5552, 0x53455F44, 0x4154415F, 0x4F4B0000, 0x4D414348, 0x494E4500,
    0x4D414348, 0x494E455F, 0x4F4B0000, 0x434F4E46, 0x49470000, 0x434F4E46, 0x49475F4F, 0x4B000000,
    0x434F554E, 0x54455241, 0x444A5553, 0x54000000, 0x4C494E4B, 0x57414954, 0x0, 0x4C494E4B,
    0x57414954, 0x4F4B0000, 0x4C494E4B, 0x53454C00, 0x4C494E4B, 0x44454C49, 0x56455259, 0x53544152,
    0x54000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x0, 0x4C494E4B, 0x44454C49, 0x56455259,
    0x4F4B0000, 0x4C494E4B, 0x53454C4F, 0x4B000000, 0x434F5552, 0x53455649, 0x45570000, 0x434F5552,
    0x53455649, 0x45575F4F, 0x4B000000, 0x4C494E4B, 0x52455100, 0x4C494E4B, 0x5354414E, 0x44425900,
    0x4C494E4B, 0x4F4B0000, 0x4C494E4B, 0x0, 0x50415553, 0x45000000, 0x4552524F, 0x52000000,
    (u32)lbl_8_data_7E50__fzgx_offset_0, (u32)lbl_8_data_7E54__fzgx_offset_0, (u32)lbl_8_data_7E60__fzgx_offset_0, (u32)lbl_8_data_7E6C__fzgx_offset_0, (u32)lbl_8_data_7E78__fzgx_offset_0, (u32)lbl_8_data_7E84__fzgx_offset_0, (u32)lbl_8_data_7E8C__fzgx_offset_0, (u32)lbl_8_data_7E94__fzgx_offset_0,
    (u32)lbl_8_data_7E9C__fzgx_offset_0, (u32)lbl_8_data_7EA4__fzgx_offset_0, (u32)lbl_8_data_7EB0__fzgx_offset_0, (u32)lbl_8_data_7EC0__fzgx_offset_0, (u32)lbl_8_data_7ED0__fzgx_offset_0, (u32)lbl_8_data_7ED8__fzgx_offset_0, (u32)lbl_8_data_7EE0__fzgx_offset_0, (u32)lbl_8_data_7EEC__fzgx_offset_0,
    (u32)lbl_8_data_7EF8__fzgx_offset_0, (u32)lbl_8_data_7F08__fzgx_offset_0, (u32)lbl_8_data_7F10__fzgx_offset_0, (u32)lbl_8_data_7F1C__fzgx_offset_0, (u32)lbl_8_data_7F28__fzgx_offset_0, (u32)lbl_8_data_7F38__fzgx_offset_0, (u32)lbl_8_data_7F40__fzgx_offset_0, (u32)lbl_8_data_7F4C__fzgx_offset_0,
    (u32)lbl_8_data_7F58__fzgx_offset_0, (u32)lbl_8_data_7F68__fzgx_offset_0, (u32)lbl_8_data_7F70__fzgx_offset_0, (u32)lbl_8_data_7F7C__fzgx_offset_0, (u32)lbl_8_data_7F84__fzgx_offset_0, (u32)lbl_8_data_7F90__fzgx_offset_0, (u32)lbl_8_data_7FA0__fzgx_offset_0, (u32)lbl_8_data_7FAC__fzgx_offset_0,
    (u32)lbl_8_data_7FB8__fzgx_offset_0, (u32)lbl_8_data_7FC0__fzgx_offset_0, (u32)lbl_8_data_7FD4__fzgx_offset_0, (u32)lbl_8_data_7FE4__fzgx_offset_0, (u32)lbl_8_data_7FF4__fzgx_offset_0, (u32)lbl_8_data_8000__fzgx_offset_0, (u32)lbl_8_data_800C__fzgx_offset_0, (u32)lbl_8_data_801C__fzgx_offset_0,
    (u32)lbl_8_data_8024__fzgx_offset_0, (u32)lbl_8_data_8030__fzgx_offset_0, (u32)lbl_8_data_8038__fzgx_offset_0, (u32)lbl_8_data_8040__fzgx_offset_0, (u32)lbl_8_data_8048__fzgx_offset_0, 0x4F564552, 0x54414B45, 0x0,
    0x4A554D50, 0x0, 0x454E454D, 0x59484954, 0x0, 0x57414C4C, 0x48495400, 0x53494445,
    0x42595349, 0x44450000, 0x53544152, 0x54000000, 0x474F414C, 0x0, 0x4C415000, (u32)lbl_8_data_8104__fzgx_offset_0,
    (u32)lbl_8_data_8110__fzgx_offset_0, (u32)lbl_8_data_8118__fzgx_offset_0, (u32)lbl_8_data_8124__fzgx_offset_0, (u32)lbl_8_data_812C__fzgx_offset_0, (u32)lbl_8_data_8138__fzgx_offset_0, (u32)lbl_8_data_8140__fzgx_offset_0, (u32)lbl_8_data_8148__fzgx_offset_0, 0x6D656E75,
    0x0, 0x77617463, 0x68000000, (u32)lbl_8_data_816C__fzgx_offset_0, (u32)fn_8_988C__fzgx_offset_0, (u32)fn_8_9B04__fzgx_offset_0, (u32)fn_8_9B40__fzgx_offset_0, (u32)lbl_8_data_8174__fzgx_offset_0,
    (u32)fn_8_8C48__fzgx_offset_0, (u32)fn_8_8E00__fzgx_offset_0, (u32)fn_8_8C80__fzgx_offset_0, 0x41434345, 0x4C455241, 0x544F520A, 0x0, 0x0,
    0x8341834E, 0x835A838B, 0xA000000, (u32)lbl_8_data_819C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,
    (u32)lbl_8_data_81B0__fzgx_offset_0, 0x73706565, 0x64207570, 0x2E0A0000, 0x89C191AC, 0x82B582DC, 0x82B78142, 0xA000000,
    (u32)lbl_8_data_81D4__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81E0__fzgx_offset_0, 0x41495220, 0x4252414B,
    0x450A0000, 0x83478341, 0x8375838C, 0x815B834C, 0xA000000, (u32)lbl_8_data_8208__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8214__fzgx_offset_0, 0x736C6F77, 0x20646F77, 0x6E2E0A00, 0x8CB891AC, 0x82B582DC,
    0x82B78142, 0xA000000, (u32)lbl_8_data_823C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8248__fzgx_offset_0,
    0x53544545, 0x52494E47, 0xA000000, 0x83588365, 0x8341838A, 0x8393834F, 0xA000000, (u32)lbl_8_data_8270__fzgx_offset_0,
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_827C__fzgx_offset_0, 0x436F6E74, 0x726F6C20, 0x796F7572,
    0x206D6163, 0x68696E65, 0x20776974, 0x680A0000, 0x83588365, 0x8341838A, 0x8393834F, 0x82C68341,
    0x834E835A, 0x838B82C5, 0x837D8356, 0x839382F0, 0xA000000, (u32)lbl_8_data_82A4__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_82C0__fzgx_offset_0, 0x74686520, 0x73746565, 0x72696E67, 0x20776865, 0x656C2061,
    0x6E642074, 0x68652061, 0x6363656C, 0x65726174, 0x6F722E0A, 0x0, 0x83528393, 0x8367838D,
    0x815B838B, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420A00, (u32)lbl_8_data_82FC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8328__fzgx_offset_0, 0x44415348, 0x20504C41, 0x54450A00, 0x835F8362, 0x83568385,
    0x8376838C, 0x815B8367, 0xA000000, (u32)lbl_8_data_835C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_8_data_8368__fzgx_offset_0, 0x53706565, 0x64207769, 0x6C6C2074, 0x656D706F, 0x72617269, 0x6C792069, 0x6E637265,
    0x6173650A, 0x0, 0x92CA89DF, 0x82B782E9, 0x82C68358, 0x8373815B, 0x836882AA, 0x88EA8E9E,
    0x934982C9, 0x83418362, 0x837682B5, 0x82DC82B7, 0xA000000, (u32)lbl_8_data_8394__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_83B8__fzgx_offset_0, 0x7768656E, 0x20706173, 0x73696E67, 0x206F7665, 0x72206120,
    0x64617368, 0x20706C61, 0x74652E0A, 0x0, (u32)lbl_8_data_83FC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, 0x4E4F524D, 0x414C2054, 0x55524E0A, 0x0, 0x836D815B, 0x837D838B,
    0x835E815B, 0x83930A00, (u32)lbl_8_data_8438__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8448__fzgx_offset_0,
    0x436F726E, 0x6572696E, 0x67207769, 0x74682074, 0x68652073, 0x74656572, 0x696E672E, 0xA000000,
    0x83588365, 0x8341838A, 0x8393834F, 0x82BE82AF, 0x82CC8352, 0x815B8369, 0x838A8393, 0x834F82C5,  /* fzgx-allow: A1 retail data bytes */
    0x82B78142, 0xA000000, (u32)lbl_8_data_8470__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8490__fzgx_offset_0,
    0x534C4944, 0x45205455, 0x524E0A00, 0x83588389, 0x83438368, 0x835E815B, 0x83930A00, (u32)lbl_8_data_84D0__fzgx_offset_0,
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_84DC__fzgx_offset_0, 0x50756C6C, 0x20746865, 0x20706164,
    0x646C6520, 0x7768696C, 0x6520636F, 0x726E6572, 0x696E672E, 0xA000000, 0x8352815B, 0x8369838A,
    0x8393834F, 0x928682C9, 0x83708368, 0x838B838C, 0x836F815B, 0x82F088F8, 0x82AB82DC, 0x82B78142,
    0xA000000, (u32)lbl_8_data_8504__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8528__fzgx_offset_0, 0x44524946,
    0x54205455, 0x524E0A00, 0x8368838A, 0x83748367, 0x835E815B, 0x83930A00, (u32)lbl_8_data_856C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8578__fzgx_offset_0, 0x4272616B, 0x65206265, 0x666F7265, 0x20796F75,
    0x20656E74, 0x65722074, 0x68652063, 0x75727665, 0x20776974, 0x68207468, 0x65206163, 0x63656C65,
    0x7261746F, 0x720A0000, 0x8352815B, 0x8369815B, 0x82CC8EE8, 0x914F82C5, 0x8341834E, 0x835A838B,
    0x82F093A5, 0x82F182BE, 0x82DC82DC, 0xA000000, (u32)lbl_8_data_85A0__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_85D8__fzgx_offset_0, 0x73746570, 0x70656420, 0x6F6E2C20, 0x7468656E, 0x20747572, 0x6E207468,
    0x65207374, 0x65657269, 0x6E672077, 0x6865656C, 0x2E0A0000, 0x8375838C, 0x815B834C, 0x82F08C79,  /* fzgx-allow: A1 retail data bytes */
    0x82AD93A5, 0x82DD82C8, 0x82AA82E7, 0x83588365, 0x8341838A, 0x8393834F, 0x82F090D8, 0x82E882DC,
    0x82B70A00, (u32)lbl_8_data_8618__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8644__fzgx_offset_0, 0x424F4F53,
    0x5445520A, 0x0, 0x8375815B, 0x83588367, 0xA000000, (u32)lbl_8_data_868C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8698__fzgx_offset_0, 0x54686520, 0x73706565, 0x64206F66, 0x20746865, 0x206D6163,
    0x68696E65, 0x2077696C, 0x6C20696E, 0x7374616E, 0x746C790A, 0x0, 0x328EFC96, 0xDA82A982,
    0xE78E6797, 0x7089C294, 0x5C82C582, 0xB781420A, 0x0, (u32)lbl_8_data_86BC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_86E8__fzgx_offset_0, 0x696E6372, 0x65617365, 0x20627920, 0x70726573, 0x73696E67,
    0x20746865, 0x20626F6F, 0x73742062, 0x7574746F, 0x6E206F6E, 0x63652E0A, 0x0, 0x8F758AD4,
    0x934982C9, 0x83588373, 0x815B8368, 0x82AA8341, 0x83628376, 0x82B582DC, 0x82B78142, 0xA000000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_8_data_871C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_874C__fzgx_offset_0, 0x55736520, 0x74686520,
    0x626F6F73, 0x74657220, 0x6173206D, 0x616E7920, 0x74696D65, 0x73206173, 0x20796F75, 0x2077616E,
    0x743B0A00, 0x8375815B, 0x8358835E, 0x815B82C9, 0x89F19094, 0x90A78CC0, 0x82CD82A0, 0x82E882DC,  /* fzgx-allow: A1 retail data bytes */
    0x82B982F1, 0x82AA8141, 0xA000000, (u32)lbl_8_data_8788__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,
    (u32)lbl_8_data_87B4__fzgx_offset_0, 0x686F7765, 0x7665722C, 0x20757361, 0x67652064, 0x65706C65, 0x74657320, 0x74686520,
    0x656E6572, 0x67792E0A, 0x0, 0x8E679770, 0x82B782E9, 0x82C68347, 0x836C838B, 0x834D815B,
    0x82F08FC1, 0x94EF82B5, 0x82DC82B7, 0x81420A00, (u32)lbl_8_data_87F4__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_881C__fzgx_offset_0, 0x454E4552, 0x4759204D, 0x45544552, 0xA000000, 0x83478369, 0x8357815B,
    0x8381815B, 0x835E815B, 0xA000000, (u32)lbl_8_data_8858__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,
    (u32)lbl_8_data_8868__fzgx_offset_0, 0x4E6F2065, 0x6E657267, 0x792C206E, 0x6F20626F, 0x6F73742E, 0xA000000, 0x8347836C,
    0x838B834D, 0x815B82AA, 0x3082C982, 0xC882E982, 0xC6837581, 0x5B835883, 0x5E815B82, 0xCD0A0000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_8_data_8894__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_88AC__fzgx_offset_0, 0x8E679770, 0x82C582AB,
    0x82DC82B9, 0x82F18142, 0xA000000, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,
    (u32)lbl_8_data_88E8__fzgx_offset_0, 0x5049540A, 0x0, 0x83738362, 0x83670A00
};
static u32 fzgx_pool_data_lbl_8_data_7E50_AD4[6] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_8_data_8914__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_891C__fzgx_offset_0
};
static u32 fzgx_pool_data_lbl_8_data_893C[14] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x456E6572, 0x67792063, 0x616E2062, 0x65207265, 0x706C656E, 0x69736865, 0x640A0000, 0x83738362,
    0x83678347, 0x838A8341, 0x82F09196, 0x8D7382B7, 0x82E982C6, 0xA000000
};
static u32 fzgx_pool_data_lbl_8_data_7E50_B24[6] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_8_data_893C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8958__fzgx_offset_0
};
static u32 fzgx_pool_data_lbl_8_data_898C[16] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x62792074, 0x72617665, 0x6C696E67, 0x20746872, 0x6F756768, 0x20746865, 0x20706974, 0x20617265,
    0x612E0A00, 0x8347836C, 0x838B834D, 0x815B82AA, 0x89F1959C, 0x82B582DC, 0x82B78142, 0xA000000  /* fzgx-allow: A1 retail data bytes */
};
static u32 fzgx_pool_data_lbl_8_data_7E50_B7C[6] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_8_data_898C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_89B0__fzgx_offset_0
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_8_data_7E50(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_8_data_7E50;
    s = *(u8 *)fzgx_pool_data_lbl_8_data_7E50_AD4;
    s = *(u8 *)fzgx_pool_data_lbl_8_data_893C;
    s = *(u8 *)fzgx_pool_data_lbl_8_data_7E50_B24;
    s = *(u8 *)fzgx_pool_data_lbl_8_data_898C;
    s = *(u8 *)fzgx_pool_data_lbl_8_data_7E50_B7C;
}
#pragma section code_type ".text"

extern void fn_1_4D0D4(Color *,f32);
extern u32 fn_8_CC4C(u32,u32);
extern void primer_d(f64);
extern void primer_f(f32);
extern void primer_c(Color);
#pragma section code_type ".fzgxpool"
void shared_pool_primer(void) {
 primer_d(15.0); primer_f(320.0f); primer_f(640.0f); primer_d(1.0);
 primer_f(150.0f); primer_f(0.1f); primer_f(20.0f); primer_f(0.8333333f);
 primer_d(4503601774854144.0);
}
void shared_pool_primer2(void) {
 { Color c = {255,255,255,0}; primer_c(c); }
 primer_f(0.0f);
 primer_f(1.0f); primer_f(0.5f); primer_f(0.09f); primer_f(5.0f); primer_f(255.0f);
}
void shared_pool_primer3(void) {
 { Color c = {255,255,255,0}; primer_c(c); }
 { Color c = {255,255,255,0}; primer_c(c); }
 { Color c = {255,255,255,0}; primer_c(c); }
 { Color c = {255,255,255,0}; primer_c(c); }
 { Color c = {255,255,255,0}; primer_c(c); }
 { Color c = {255,255,255,0}; primer_c(c); }
 primer_f(0.3f);
}
void shared_pool_primer4(void) {
 { Color c = {255,255,255,0}; primer_c(c); }
 { Color c = {255,255,255,0}; primer_c(c); }
 { Color c = {255,255,255,0}; primer_c(c); }
}
#pragma section code_type ".text"
typedef struct {
 u8 pad[0xAD4];
 const char *a[20];
 const char *b[22];
 const char *c[1];
} TextData;
void fn_8_86FC(void) {
    s32 x;
    f32 t, alpha;
    
    if ((s32)lbl_8_bss_3CC == (s32)lbl_8_bss_3D0.unk_0-1)
        fn_1_A2D84(0xA9120300);
    if ((s32)lbl_8_bss_3CC < 15.0) {
        t = 1.0 - (f32)(s32)lbl_8_bss_3CC / 15.0;
        x = 320.0f + (f32)(640.0f*t);
    } else if ((s32)lbl_8_bss_3CC > (s32)lbl_8_bss_3D0.unk_0 - 15.0) {
        t = 1.0 - (f32)((s32)lbl_8_bss_3D0.unk_0-(s32)lbl_8_bss_3CC) / 15.0;
        x = 320.0f - (f32)(640.0f*t);
    } else {
        t = 0.0f;
        x = 320;
    }
    alpha = (1.0f-t)*(1.0f-t);
    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_49590(0.5f);
    fn_1_495C8(9);
    fn_1_496FC(x,150.0f);
    fn_1_4954C(0.09f);
    if (lbl_801A66B4 == 5) fn_1_4955C(1.0f,1.0f);
    else fn_1_4955C(0.8333333f,0.8333333f);
    fn_1_495A0(alpha);
    fn_1_4D0A0();
    fn_1_49738(fn_1_5233C);
    fn_1_49748(5.0f);
    { const char **table = ((const char * *)(((u8 *)fzgx_pool_data_lbl_8_data_7E50_AD4))); fn_1_4AE0C(table[lbl_801A66B4]); }
    fn_1_49738(0);
    { const char **table = ((const char * *)(((u8 *)fzgx_pool_data_lbl_8_data_7E50_B24))); fn_1_4AE0C(table[lbl_801A66B4]); }
    { const char **table = ((const char * *)(((u8 *)fzgx_pool_data_lbl_8_data_7E50_B7C))); fn_1_4AE0C(table[lbl_801A66B4]); }
    { Color copy; Color c = {255,255,255,0};
    c.a = 255.0f*alpha;
    copy = c; fn_1_4D0D4(&copy,20.0f); }
    fn_8_CC4C(505,394);
}
/* fzgx:end fn_8_86FC */

/* fzgx:begin fn_8_8C44 */
// fn_8_8C44: empty in retail (single blr).
void fn_8_8C44(void) {
}
/* fzgx:end fn_8_8C44 */

/* fzgx:begin fn_8_8C48 */
struct fn_8_8C48_lbl_8_bss_2A8 {
    u8 pad_0[0x124];
    u32 unk_124;
    u8 pad_128[0x4];
    u32 unk_12C;
    u32 unk_130;
    u32 unk_134;
    u32 unk_138;
};

extern struct fn_8_8C48_lbl_8_bss_2A8 lbl_8_bss_2A8;
extern u32 lbl_1_bss_26C60;
extern void fn_8_5FD4(void);

void fn_8_8C48(void) {
    struct fn_8_8C48_lbl_8_bss_2A8 *p_lbl_8_bss_2A8;
    p_lbl_8_bss_2A8 = (struct fn_8_8C48_lbl_8_bss_2A8 *)&lbl_8_bss_2A8;
    lbl_1_bss_26C60 = (u32)fn_8_5FD4;
    p_lbl_8_bss_2A8->unk_12C = 0;
    p_lbl_8_bss_2A8->unk_124 = 0;
    p_lbl_8_bss_2A8->unk_130 = 0;
    p_lbl_8_bss_2A8->unk_134 = -1;
    p_lbl_8_bss_2A8->unk_138 = 0;
}
/* fzgx:end fn_8_8C48 */

/* fzgx:begin fn_8_8C80 */
struct fn_8_8C80_ctx {
    u8 pad_0[0x13c];
    u32 unk_13C[9];
    u32 unk_160[9];
    u32 unk_184[9];
    u32 unk_1A8[9];
    u32 unk_1CC[9][4];
};

struct fn_8_8C80_lbl_801A6410 {
    u32 unk_0;
};

extern struct fn_8_8C80_ctx lbl_8_bss_2A8;
extern struct fn_8_8C80_lbl_801A6410 lbl_801A6410;
extern u8 lbl_8_data_8AD4[];
extern void fn_1_469BC(void);
extern u32 fn_1_46EE8(void);
extern void fn_1_46B4(u32, u32, const char *, int);

void fn_8_8C80(void) {
    u32 base;
    u32 *v0;
    u32 *v1;
    u32 *v2;
    u32 *v3;
    u32 (*v4)[4];
    s32 v5;
    s32 v6;
    u32 v7;

    base = (u32)&lbl_8_bss_2A8;
    fn_1_469BC();
    fn_1_46EE8();
    v0 = (u32 *)(base + 0x13c);
    v1 = (u32 *)(base + 0x160);
    v2 = (u32 *)(base + 0x184);
    v3 = (u32 *)(base + 0x1a8);
    v4 = (u32 (*)[4])(base + 0x1cc);
    for (v5 = 0; v5 < 9; v5++) {
        if (v0[0] != 0) {
            fn_1_46B4(lbl_801A6410.unk_0, v0[0], (const char *)&lbl_8_data_8AD4, 1975);
            v0[0] = 0;
        }
        if (v1[0] != 0) {
            fn_1_46B4(lbl_801A6410.unk_0, v1[0], (const char *)&lbl_8_data_8AD4, 1979);
            v1[0] = 0;
        }
        if (v2[0] != 0) {
            fn_1_46B4(lbl_801A6410.unk_0, v2[0], (const char *)&lbl_8_data_8AD4, 1983);
            v2[0] = 0;
        }
        if (v3[0] != 0) {
            fn_1_46B4(lbl_801A6410.unk_0, v3[0], (const char *)&lbl_8_data_8AD4, 1987);
            v3[0] = 0;
        }
        v7 = 0;
        for (v6 = 0; v6 < 4; v6++) {
            if (v4[0][v6] != 0) {
                fn_1_46B4(lbl_801A6410.unk_0, v4[0][v6], (const char *)&lbl_8_data_8AD4, 1992);
                v4[0][v6] = v7;
            }
        }
        v0++;
        v1++;
        v2++;
        v3++;
        v4++;
    }
}
/* fzgx:end fn_8_8C80 */

/* fzgx:begin fn_8_988C */
extern int sprintf(char *, const char *, ...);

struct fn_8_988C_ctx {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[0x130];
    u32 unk_13C[9];
    u32 unk_160[9];
    u32 unk_184[9];
    u32 unk_1A8[9];
    u32 unk_1CC[9][4];
    u32 unk_25C[9];
};

struct fn_8_988C_lbl_801A6410 {
    u32 unk_0;
};

extern struct fn_8_988C_ctx lbl_8_bss_2A8;
extern struct fn_8_988C_lbl_801A6410 lbl_801A6410;
extern u8 lbl_8_data_7E50[];
extern u32 lbl_1_bss_970;
extern const f32 lbl_8_rodata_194;

extern s32 fn_1_45730(const char *, void *);
extern u32 fn_1_45B2C(void *);
extern u32 fn_1_4630(u32, u32, const char *, int);
extern void DCFlushRange(void *, u32);
extern void fn_1_458A0(void *, u32, u32, u32);
extern void fn_1_45850(void *);
extern void fn_80008BA8(u32, u32, u32);
extern void fn_1_A8F78(void);
extern void fn_1_4BB0(void);
extern void fn_8006CE1C(f32);

void fn_8_988C(void) {
    u32 data;
    u32 ctx;
    u32 *src;
    u32 *v25C;
    u32 *v13C;
    u32 *v160;
    u32 *v184;
    u32 *v1A8;
    u32 *v1CC;
    u8 res[0x5c];
    u8 buf[0xfc];
    s32 i;
    u32 base;
    s32 j;
    u32 dest;

    data = (u32)lbl_8_data_7E50;
    ctx = (u32)&lbl_8_bss_2A8;
    fn_1_A8F78();
    fn_1_4BB0();
    fn_8006CE1C(lbl_8_rodata_194);
    lbl_1_bss_970 = 1200;
    src = (u32 *)(data + 0xe14);
    v25C = (u32 *)(ctx + 0x25c);
    v13C = (u32 *)(ctx + 0x13c);
    v160 = (u32 *)(ctx + 0x160);
    v184 = (u32 *)(ctx + 0x184);
    v1A8 = (u32 *)(ctx + 0x1a8);
    v1CC = (u32 *)(ctx + 0x1cc);
    for (i = 0; i < 9; i++) {
        sprintf((char *)buf, (const char *)(data + 0xe78), src[0]);
        if (fn_1_45730((const char *)buf, res) != 0) {
            v25C[0] = fn_1_45B2C(res);
            v13C[0] = fn_1_4630(lbl_801A6410.unk_0, v25C[0], (const char *)(data + 0xc84), 2454);
            DCFlushRange((void *)v13C[0], v25C[0] + 32);
            fn_1_458A0(res, v13C[0], (v25C[0] + 31) & ~31, 0);
            fn_1_45850(res);
        }
        sprintf((char *)buf, (const char *)(data + 0xe90), src[0]);
        if (fn_1_45730((const char *)buf, res) != 0) {
            v160[0] = fn_1_4630(lbl_801A6410.unk_0, 0x620, (const char *)(data + 0xc84), 2472);
            v184[0] = fn_1_4630(lbl_801A6410.unk_0, 0x1fc, (const char *)(data + 0xc84), 2473);
            v1A8[0] = fn_1_4630(lbl_801A6410.unk_0, 0x194, (const char *)(data + 0xc84), 2474);
            for (j = 0; j < 4; j++) {
                v1CC[j] = fn_1_4630(lbl_801A6410.unk_0, 0xc0, (const char *)(data + 0xc84), 2476);
            }
            fn_1_458A0(res, *(u32 *)(ctx + 0x8), (fn_1_45B2C(res) + 31) & ~31, 0);
            fn_1_45850(res);
            base = *(u32 *)(ctx + 0x8);
            fn_80008BA8(v160[0], base, 0x5a0);
            fn_80008BA8(v184[0], base + 0x5a0, 0x1fc);
            dest = base + 0x79c;
            for (j = 0; j < 4; j++) {
                fn_80008BA8(v1CC[j], dest, 0xc0);
                dest += 0xc0;
            }
            fn_80008BA8(v1A8[0], dest, 0x194);
        }
        src += 2;
        v25C++;
        v13C++;
        v160++;
        v184++;
        v1A8++;
        v1CC += 4;
    }
}
/* fzgx:end fn_8_988C */

/* fzgx:begin fn_8_9B04 */
extern struct fn_8_9B04_lbl_8_bss_2A8 lbl_8_bss_2A8;
extern u32 fn_80008BA8(u32, u32, u32);
extern u32 fn_8_5C54(u32);

struct fn_8_9B04_lbl_8_bss_2A8 {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[0x130];
    u32 unk_13C;
    u8 pad_140[0x11C];
    u32 unk_25C;
};

void fn_8_9B04(void) {
    fn_80008BA8(lbl_8_bss_2A8.unk_8, lbl_8_bss_2A8.unk_13C, lbl_8_bss_2A8.unk_25C);
    fn_8_5C54(1);
}
/* fzgx:end fn_8_9B04 */

/* fzgx:begin fn_8_9B40 */
// fn_8_9B40: empty in retail (single blr).
void fn_8_9B40(void) {
}
/* fzgx:end fn_8_9B40 */

/* fzgx:begin fn_8_BAEC noprologue */
#include "types.h"

struct fn_8_BAEC_lbl_8_bss_2A8 {
    u8 pad_0[0x9C];
    s16 unk_9C;
    u8 pad_9E[0x86];
    s32 unk_124;
    s32 unk_128;
};

extern const f64 lbl_8_rodata_188;
extern f32 lbl_8_rodata_198;
extern u32 lbl_801A66A0;
extern struct fn_8_BAEC_lbl_8_bss_2A8 lbl_8_bss_2A8;
extern u32 fn_1_5370(s8, u32);
extern void fn_80008BEC(void *, int, u32);
extern void fn_8006CE1C(f32);

void fn_8_BAEC(void) {
    struct fn_8_BAEC_lbl_8_bss_2A8 *base;
    f32 v;
    u32 t;

    base = (struct fn_8_BAEC_lbl_8_bss_2A8 *)&lbl_8_bss_2A8;
    if (base->unk_124 == base->unk_128 / 2) {
        fn_80008BEC((u8 *)base + 0x24, 0, 60);
        fn_80008BEC((u8 *)base + 0x60, 0, 60);
        fn_80008BEC((u8 *)base + 0x9C, 0, 60);
        fn_80008BEC((u8 *)base + 0xD8, 0, 60);
        fn_1_5370(1, 0);
    }

    base->unk_9C = lbl_801A66A0 * 512;
    fn_8006CE1C(lbl_8_rodata_198 - (f32)__fabs((f64)(f32)(base->unk_128 / 2 - base->unk_124)) / (f32)(base->unk_128 / 2));
}
/* fzgx:end fn_8_BAEC */

/* fzgx:begin fn_8_BC04 noprologue */
#include "types.h"

struct fn_8_BC04_lbl_8_bss_2A8 {
    u8 pad_0[0x124];
    s32 unk_124;
    s32 unk_128;
};

extern f32 lbl_8_rodata_198[89];
extern struct fn_8_BC04_lbl_8_bss_2A8 lbl_8_bss_2A8;
extern u32 fn_1_5370(s8, u32);
extern void fn_80008BEC(void *, int, u32);
extern void fn_8006CE1C(f32);

void fn_8_BC04(void) {
    struct fn_8_BC04_lbl_8_bss_2A8 *p;

    p = &lbl_8_bss_2A8;
    if (p->unk_124 == p->unk_128 / 2) {
        fn_80008BEC((u8 *)p + 36, 0, 60);
        fn_80008BEC((u8 *)p + 96, 0, 60);
        fn_80008BEC((u8 *)p + 156, 0, 60);
        fn_80008BEC((u8 *)p + 216, 0, 60);
        fn_1_5370(1, 0);
    }
    fn_8006CE1C(lbl_8_rodata_198[0] - (f32)__fabs((f32)(p->unk_124 - p->unk_128 / 2)) / (f32)(p->unk_128 / 2));
}
/* fzgx:end fn_8_BC04 */

/* fzgx:begin fn_8_C7B0 */
extern f32 lbl_8_rodata_2FC[27];
extern u32 fn_800371F8(u32, void *);
extern void fn_8003462C(u32, u32, u32);
extern void fn_8007245C(u32);
extern void fn_80072864(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(u32, u32, u32, u32, u32);
extern void fn_80072D64(u32, u32, u32, u32, u32, u32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80073678(u32);
extern void fn_80073C6C(s32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_800747D0(u32, u32, u32, u32, u32, u32, u32);
extern void fn_80074918(u8, s32, u8);

void fn_8_C7B0(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    u32 loc_8;

    fn_80074918(1, 7, 1);
    fn_80074788(1);
    fn_80074660(0);
    fn_80073678(1);
    fn_80073C6C(0);
    fn_800747D0(4, 0, 0, 0, 0, 2, 2);
    fn_80072AB0(0, 0, 0);
    fn_800734A8(0, 255, 255, 4);
    fn_80072C24(0, 15, 15, 15, 2);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 7, 7, 1);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_80072864(2);
    fn_8007245C(512);
    loc_8 = *(u32 *)((u8 *)arg0 + 0);
    fn_800371F8(1, (void *)&loc_8);
    fn_8003462C(128, 7, 4);
    *(f32 *)((u8 *)0xCC008000) = arg3;  /* fzgx-allow: A1,A2 GX FIFO write port */
    *(f32 *)((u8 *)0xCC008000) = arg1;  /* fzgx-allow: A1,A2 GX FIFO write port */
    *(f32 *)((u8 *)0xCC008000) = lbl_8_rodata_2FC[0];  /* fzgx-allow: A1,A2 GX FIFO write port */
    *(f32 *)((u8 *)0xCC008000) = arg4;  /* fzgx-allow: A1,A2 GX FIFO write port */
    *(f32 *)((u8 *)0xCC008000) = arg1;  /* fzgx-allow: A1,A2 GX FIFO write port */
    *(f32 *)((u8 *)0xCC008000) = lbl_8_rodata_2FC[0];  /* fzgx-allow: A1,A2 GX FIFO write port */
    *(f32 *)((u8 *)0xCC008000) = arg4;  /* fzgx-allow: A1,A2 GX FIFO write port */
    *(f32 *)((u8 *)0xCC008000) = arg2;  /* fzgx-allow: A1,A2 GX FIFO write port */
    *(f32 *)((u8 *)0xCC008000) = lbl_8_rodata_2FC[0];  /* fzgx-allow: A1,A2 GX FIFO write port */
    *(f32 *)((u8 *)0xCC008000) = arg3;  /* fzgx-allow: A1,A2 GX FIFO write port */
    *(f32 *)((u8 *)0xCC008000) = arg2;  /* fzgx-allow: A1,A2 GX FIFO write port */
    *(f32 *)((u8 *)0xCC008000) = lbl_8_rodata_2FC[0];  /* fzgx-allow: A1,A2 GX FIFO write port */
    fn_80074918(1, 3, 1);
}
/* fzgx:end fn_8_C7B0 */

/* fzgx:begin fn_8_C9A8 */
extern u8 lbl_8_data_7E50[];

extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_4954C(f32);
extern void fn_1_495A0(f32);
extern void fn_1_4965C(u8);
extern void fn_1_49738(void *);
extern void fn_1_49748(f32);
extern void fn_1_49514(u32 *);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_5233C(void);

struct Color {
    u8 r, g, b, a;
};

/* The retail TU's literal pool (lbl_8_rodata_160) in retail order. MWCC emits a file-scope
 * object at its definition and a function's literals right after that function, so the words
 * this function does not read are private tables and its own literals (and the compiler's
 * int-to-float constant) are primed in between. Dropped at integration. */
#pragma section code_type ".fzgxpool"
static const f32 fzgx_pool_00[10] = {2.71875f, 0.0f, 320.0f, 640.0f, 1.875f, 0.0f, 150.0f, 0.1f, 20.0f, 0.8333333f};
static void fzgx_pool_layout_28(void) {
    volatile f32 s;  /* fzgx-allow: S2 layout primer sink: pools the 2^52 + 2^31 conversion constant */
    volatile s32 n;  /* fzgx-allow: S2 layout primer source */
    s = (f32)n;
}
static const u32 fzgx_pool_30[2] = {0xFFFFFF00, 0x00000000};
static void fzgx_pool_layout_38(void) {
    volatile f32 s;  /* fzgx-allow: S2 layout primer sink: MWCC pools literals in first-use order */
    s = 1.0f;
    s = 0.5f;
    s = 0.09f;
}
static const f32 fzgx_pool_44[1] = {5.0f};
static void fzgx_pool_layout_48(void) {
    volatile f32 s;  /* fzgx-allow: S2 layout primer sink */
    s = 255.0f;
}
static const u32 fzgx_pool_4C[6] = {0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00};
static const f32 fzgx_pool_64[1] = {0.3f};
static const u32 fzgx_pool_68[5] = {0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00};
static const f32 fzgx_pool_7C[36] = {
    0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.01f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.01f,
    60.0f, 0.7f, 0.01f, 240.0f, 45.0f, 0.001f, 100.0f, -200.0f, 120.0f, 200.0f, -120.0f, -0.01f,
    10.0f, -10240.0f, 1.8f, -1.8f, -20.0f, -4096.0f, -2048.0f, 1.1f, -0.51f, 4096.0f, -1.1f, 0.8f,
};
static const u32 fzgx_pool_10C[1] = {0xFFFFFF00};
static const f32 fzgx_pool_110[1] = {345.0f};
static void fzgx_pool_layout_114(void) {
    volatile f32 s;  /* fzgx-allow: S2 layout primer sink */
    s = 2.0f;
}
static const f32 fzgx_pool_118[4] = {1.8375f, 0.00000004172325f, -160.0f, 90.0f};
static const u32 fzgx_pool_128[1] = {0xFFFFFF00};
static const f32 fzgx_pool_12C[4] = {112.0f, 272.0f, 30.0f, 70.0f};
static const u32 fzgx_pool_13C[2] = {0xFFFFFF00, 0xFF4040FF};
static const f32 fzgx_pool_144[2] = {1.1111112f, 160.0f};
static const u32 fzgx_pool_14C[3] = {0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00};
static const f32 fzgx_pool_158[1] = {-100.0f};
static const u32 fzgx_pool_15C[2] = {0xFFFFFF00, 0xFFFFFFFF};
static const f32 fzgx_pool_164[6] = {541.0f, 0.11f, 0.48f, 0.44f, 591.0f, 289.0f};
static const u32 fzgx_pool_17C[1] = {0xFFFFFFFF};
static const f32 fzgx_pool_180[5] = {0.0f, 6.5f, 81.25f, 26.0f, 620.0f};
static const u32 fzgx_pool_194[1] = {0x00000080};
static const f32 fzgx_pool_198[19] = {
    448.0f, -1.0f, 481.0f, 641.0f, 0.000015f, 0.00006f, 0.00005f, 0.0f, 3.3515625f, 0.0f,
    3.21875f, 0.0f, 2.96875f, 0.0f, 0.009f, -177.0f, 108.0f, -0.009f, -71.0f,
};
static const u32 fzgx_pool_1E4[1] = {0xFFC80000};
static void fzgx_pool_layout_1E8(void) {
    volatile f32 s;  /* fzgx-allow: S2 layout primer sink */
    s = 3.0f;
}
#pragma section code_type ".text"

void fn_8_C9A8(s32 x, s32 y, f32 alpha) {
    struct { const char *value; } strings;
    u32 packed;
    struct Color color;

    strings.value = (const char *)lbl_8_data_7E50;

    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_49590(0.5f);
    fn_1_495C8(8);
    fn_1_4954C(0.09f);
    fn_1_495A0(alpha);
    fn_1_4965C(4);
    fn_1_49738((void *)fn_1_5233C);
    fn_1_49748(3.0f);

    *(u32 *)&color = fzgx_pool_1E4[0];
    color.a = (u8)(s32)(255.0f * alpha);
    packed = *(u32 *)&color;
    fn_1_49514(&packed);

    fn_1_4955C(2.0f, 2.0f);
    fn_1_496FC((f32)(x + 0x64), (f32)(y + 0xf0));
    fn_1_4AE0C(strings.value + 0x224c);

    fn_1_4955C(2.0f, 2.0f);
    fn_1_496FC((f32)(x + 0xbd), (f32)(y + 0xf0));
    fn_1_4AE0C(strings.value + 0x2254);

    fn_1_4955C(1.0f, 2.0f);
    fn_1_496FC((f32)(x + 0xdd), (f32)(y + 0xf0));
    fn_1_4AE0C(strings.value + 0x2258);

    fn_1_4955C(2.0f, 2.0f);
    fn_1_496FC((f32)(x + 0x10d), (f32)(y + 0xf0));
    fn_1_4AE0C(strings.value + 0x225c);

    fn_1_4955C(1.0f, 2.0f);
    fn_1_496FC((f32)(x + 0x208), (f32)(y + 0xf0));
    fn_1_4AE0C(strings.value + 0x2268);
}
/* fzgx:end fn_8_C9A8 */

/* fzgx:begin fn_8_CC2C */
struct OperationValue {
    f32 value;
    u8 unk04[0x08];
    f32 delta;
};

struct OperationState {
    u8 unk00[0x54];
    f32 delta;
};

void fn_8_CC2C(struct OperationState *state, struct OperationValue *value) {
    f32 current;
    f32 delta;

    current = value->value;
    value->value = current + (delta = state->delta);
    value->delta = value->delta + delta;
}
/* fzgx:end fn_8_CC2C */

/* fzgx:begin fn_8_CC4C */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 15.0;
    s = 320.0f;
    s = 640.0f;
    d = 1.0;
    s = 150.0f;
    s = 0.10000000149011612f;
    s = 20.0f;
    s = 0.8333333134651184f;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table2[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 1.0f;
    s = 0.5f;
    s = 0.09000000357627869f;
    s = 5.0f;
    s = 255.0f;
}
static const u32 fzgx_pool_table4[6] = {0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table6[17] = {0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3C23D70A, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3C23D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.699999988079071f;
    s = 0.009999999776482582f;
    s = 240.0f;
    s = 45.0f;
    s = 0.0010000000474974513f;
    s = 100.0f;
    s = -200.0f;
    s = 120.0f;
    s = 200.0f;
    s = -120.0f;
    s = -0.009999999776482582f;
    s = 10.0f;
    s = -10240.0f;
    s = 1.7999999523162842f;
    s = -1.7999999523162842f;
    s = -20.0f;
    s = -4096.0f;
    s = -2048.0f;
    s = 1.100000023841858f;
    s = -0.5099999904632568f;
    s = 4096.0f;
    s = -1.100000023841858f;
    s = 0.800000011920929f;
}
static const u32 fzgx_pool_table8[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 345.0f;
    s = 2.0f;
    d = 0.85;
    s = -160.0f;
    s = 90.0f;
}
static const u32 fzgx_pool_table10[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 112.0f;
    s = 272.0f;
    s = 30.0f;
    s = 70.0f;
}
static const u32 fzgx_pool_table12[2] = {0xFFFFFF00, 0xFF4040FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.1111111640930176f;
    s = 160.0f;
}
static const u32 fzgx_pool_table14[3] = {0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -100.0f;
}
static const u32 fzgx_pool_table16[2] = {0xFFFFFF00, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 541.0f;
    s = 0.10999999940395355f;
    s = 0.47999998927116394f;
    s = 0.4399999976158142f;
    s = 591.0f;
    s = 289.0f;
}
static const u32 fzgx_pool_table18[2] = {0xFFFFFFFF, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 6.5f;
    s = 81.25f;
    s = 26.0f;
    s = 620.0f;
}
static const u32 fzgx_pool_table20[1] = {0x00000080};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 448.0f;
    s = -1.0f;
    s = 481.0f;
    s = 641.0f;
    s = 1.4999999621068127e-05f;
    s = 5.999999848427251e-05f;
    s = 4.999999873689376e-05f;
}
static const u32 fzgx_pool_table22[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 90.0;
    d = 60.0;
    d = 30.0;
    s = 0.008999999612569809f;
    s = -177.0f;
    s = 108.0f;
    s = -0.008999999612569809f;
    s = -71.0f;
}
static const u32 fzgx_pool_table24[1] = {0xFFC80000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.0f;
    s = 0.029999999329447746f;
    s = 40.0f;
    s = -0.029999999329447746f;
    s = 5.500000042957254e-05f;
    s = 32768.0f;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"
struct fn_8_CC4C_lbl_801A66B4 { u32 unk_0; };
struct fn_8_CC4C_lbl_8_rodata_160 {
u8 pad_0[0x20]; f32 unk_20; u8 pad_24[4]; f64 unk_28;
u8 pad_30[4]; f32 unk_34; f32 unk_38; u8 pad_3C[0x7C];
f32 unk_B8; f32 unk_BC; f32 unk_C0; f32 unk_C4;
u8 pad_C8[0xE8]; f32 unk_1B0; u8 pad_1B4[0x38];
f32 unk_1EC; f32 unk_1F0; f32 unk_1F4; f32 unk_1F8; f32 unk_1FC; f64 unk_200;
};
struct fn_8_CC4C_lbl_1_bss_38460 { u8 pad_0[0x10]; u32 unk_10; u32 unk_14; };
struct fn_8_CC4C_lbl_801A66C8 { u32 unk_0; };
extern f32 fn_1_A6FE8(void);
extern f32 lbl_8006D188(u32);
extern f32 lbl_8006D21C(u32);
extern struct fn_8_CC4C_lbl_1_bss_38460 lbl_1_bss_38460;
extern struct fn_8_CC4C_lbl_801A66B4 lbl_801A66B4;
extern struct fn_8_CC4C_lbl_801A66C8 lbl_801A66C8;
extern struct fn_8_CC4C_lbl_8_rodata_160 lbl_8_rodata_160;
extern u32 fn_1_A7024(f32,f32,f32,f32);
extern u32 mathutil_mtxA_rotate_z(u32);
extern void fn_1_556B8(void *);
extern void fn_1_55FF0(f32);
extern void fn_1_56000(u8,u8,u8);
extern void fn_1_5621C(f32,f32,f32,f32);
extern void fn_1_A71CC(void);
extern void fn_1_A722C(void);
extern void fn_80072558(void);
extern void lbl_8006D758(void);
extern void lbl_8006E0B4(f32,f32,f32);
extern void lbl_8006E14C(f32);
#pragma opt_common_subs on
#pragma opt_propagation off
#pragma opt_lifetimes off
void fn_8_CC4C(u32 x, u32 y) {
struct { u32 value; } model;
#define v2 model.value
u32 arg1 = y;
u32 arg0 = x;
struct fn_8_CC4C_lbl_8_rodata_160 *p_lbl_8_rodata_160;
u32 v0;
f32 v1;
f32 v3;
f32 v13;
f32 v12;
f32 v11;
f32 v4;
f32 v9;
f32 v5;
u32 v6;
f32 v14;
union { f64 d; struct { u32 hi, lo; } w; } cv0, cv1, cv2;
v0 = lbl_801A66B4.unk_0;
if ((s32)v0 != 5 || lbl_1_bss_38460.unk_10 != 0) {
if ((s32)v0 == 5 || lbl_1_bss_38460.unk_14 != 0) {
if ((s32)v0 == 5) {
v2 = *(u32 *)((u8 *)*(u32 *)((u8 *)lbl_1_bss_38460.unk_10 + 8) + 8);
} else {
v2 = *(u32 *)((u8 *)*(u32 *)((u8 *)lbl_1_bss_38460.unk_14 + 8) + 8);
}
fn_1_56000(1,7,1);
v1 = lbl_8006D21C(4096);
v3 = 240.0f;
v1 = v3 / v1;
v4 = 0.03f / v1;
fn_1_A71CC();
fn_1_A7024(45.0f,fn_1_A6FE8(),0.001f,100.0f);
v1 = (f32)((lbl_801A66C8.unk_0) % 40);
v9 = v1 / 40.0f;
lbl_8006D758();
v1 = (f32)(s32)(arg0 - 320);
v11 = v1 * v4;
v1 = v11;
v12 = (f32)(s32)(arg1 - 240) * v4;
lbl_8006E0B4(v1,v12,-0.03f);
v1 = 40.0f;
v1 = v1 * v9;
v13 = (f32)(v1 - 20.0f) * v4;
v1 = v13;
lbl_8006E0B4(v1,v13,0.0f);
mathutil_mtxA_rotate_z(-8192);
v1 = 0.000055f;
lbl_8006E14C(v1);
fn_80072558();
v4 = 32768.0f * v9;
v14 = v4;
v1 = lbl_8006D188((s32)v4);
fn_1_55FF0(v1);
v1 = 0.0f;
fn_1_5621C(v1,v1,v1,1.0f);
fn_1_556B8((void *)v2);
v1 = 1.0f;
fn_1_5621C(v1,v1,v1,v1);
lbl_8006D758();
v1 = v11;
lbl_8006E0B4(v1,v12,-0.03f);
v1 = v13;
lbl_8006E0B4(v1,v13,0.0f);
mathutil_mtxA_rotate_z(-8192);
v1 = 0.00005f;
lbl_8006E14C(v1);
fn_80072558();
v1 = lbl_8006D188((s32)v14);
fn_1_55FF0(v1);
v1 = 1.0f;
fn_1_5621C(v1,v1,0.0f,v1);
fn_1_556B8((void *)v2);
v1 = 1.0f;
fn_1_5621C(v1,v1,v1,v1);
fn_1_A722C();
v1 = 1.0f;
fn_1_55FF0(v1);
fn_1_56000(1,3,1);
}
}
}
/* fzgx:end fn_8_CC4C */

/* fzgx:begin fn_8_CF58 */
// fn_8_CF58: returns a constant.
int fn_8_CF58(void) {
    return 0;
}
/* fzgx:end fn_8_CF58 */

/* fzgx:begin fn_8_CF60 */
// fn_8_CF60: returns a constant.
int fn_8_CF60(void) {
    return 0;
}
/* fzgx:end fn_8_CF60 */

/* fzgx:begin fn_8_CF68 */
// fn_8_CF68: returns a constant.
int fn_8_CF68(void) {
    return 2;
}
/* fzgx:end fn_8_CF68 */

/* fzgx:begin fn_8_CF70 */
extern u32 fn_1_D0790(void);

s32 fn_8_CF70(void) {
    fn_1_D0790();
    return 0;
}
/* fzgx:end fn_8_CF70 */

/* fzgx:begin fn_8_CF94 */
extern u32 fn_1_5370(u32, u32);
extern void fn_8_CF58(void);
extern void fn_8_CF60(void);
extern void fn_8_CF68(void);
extern void fn_8_CF70(void);

struct fn_8_CF94_Arg0 {
    u32 unk_0;
    u8 pad_4[0xA4];
    u32 unk_A8;
    u32 unk_AC;
    u8 pad_B0[0x14];
    u32 unk_C4;
    u8 pad_C8[0x4];
    u32 unk_CC;
};

void fn_8_CF94(struct fn_8_CF94_Arg0 *arg0) {
    arg0->unk_A8 = (u32)fn_8_CF58;
    arg0->unk_C4 = (u32)fn_8_CF68;
    arg0->unk_CC = (u32)fn_8_CF60;
    arg0->unk_AC = (u32)fn_8_CF70;
    arg0->unk_0 = (arg0->unk_0 | 513);
    arg0->unk_0 = ((arg0->unk_0 | 0x200000) | 256);
    arg0->unk_0 = (arg0->unk_0 | 32768);
    arg0->unk_0 = (arg0->unk_0 | 0x1000000);
    fn_1_5370(1, 0);
}
/* fzgx:end fn_8_CF94 */

/* fzgx:begin fn_8_D020 */
// fn_8_D020: empty in retail (single blr).
void fn_8_D020(void) {
}
/* fzgx:end fn_8_D020 */

/* fzgx:begin fn_8_D024 */
extern u32 lbl_8_bss_544;

void fn_8_D024(void) {
    lbl_8_bss_544 = 4;
}
/* fzgx:end fn_8_D024 */

/* fzgx:begin fn_8_D5F4 */
extern u32 fn_1_14BD74(u32);
extern u32 fn_1_15555C(u32);
extern u32 fn_1_48140(u32);

void fn_8_D5F4(void) {
    u32 t2, t3;
    fn_1_48140(149);
    fn_1_48140(152);
    t2 = fn_1_48140(151);
    t3 = fn_1_15555C(t2);
    fn_1_14BD74(t3);
}
/* fzgx:end fn_8_D5F4 */

/* fzgx:begin fn_8_FC5C */
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef signed long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef int BOOL;
typedef unsigned long size_t;
/* Generated by `fzgx headers --module option`: layouts recovered from every access in the */
/* module's disassembly (matched or not). Field names are offsets until the librarian names them; */
/* offsets and widths are facts, names are not. Regenerate rather than hand-edit padding. */
/* lbl_4_bss_0: .bss size 0x2, referenced by 39 functions, shape {'object': 762} */
extern u16 lbl_4_bss_0;
/* lbl_4_data_0: .data size 0xC, referenced by 17 functions, shape {'object': 49} */
extern u8 lbl_4_data_0[0xC];
/* lbl_4_bss_8: .bss size 0x4, referenced by 14 functions, shape {'object': 14} */
extern u32 lbl_4_bss_8;
/* lbl_4_bss_5680: .bss size 0x4, referenced by 8 functions, shape {'object': 112, 'pointer': 28} */
typedef struct {
u32 unk_0; /* 11 loads, 6 stores */
u32 unk_4; /* 1 loads, 1 stores */
u32 unk_8; /* 4 loads, 1 stores */
u8 unk_C; /* 8 loads, 1 stores */
u8 unk_D; /* 5 loads, 4 stores */
u8 unk_E; /* 10 loads, 3 stores */
u8 unk_F; /* 3 loads, 12 stores */
u8 unk_10; /* 1 loads, 0 stores */
u8 unk_11; /* 2 loads, 1 stores */
u16 unk_12; /* 3 loads, 3 stores */
u8 unk_14; /* 2 loads, 2 stores */
u8 unk_15; /* 2 loads, 2 stores */
u8 unk_16; /* 2 loads, 2 stores */
u8 unk_17; /* 2 loads, 2 stores */
u32 unk_18; /* 1 loads, 1 stores */
u32 unk_1C; /* 1 loads, 1 stores */
u32 unk_20; /* 3 loads, 2 stores */
u8 pad_24[0x4];
u8 unk_28; /* 1 loads, 0 stores */
u8 pad_29[0xD];
u8 unk_36; /* 2 loads, 1 stores */
u8 unk_37; /* 0 loads, 1 stores */
u8 pad_38[0x2];
u8 unk_3A; /* 2 loads, 2 stores */
u8 unk_3B; /* 5 loads, 2 stores */
u32 unk_3C; /* 4 loads, 2 stores */
} Obj_4_bss_5680_Target;
extern Obj_4_bss_5680_Target *lbl_8_bss_550;
/* lbl_4_bss_5630: .bss size 0x48, referenced by 6 functions, shape {'object': 5} */
typedef struct {
u32 unk_0; /* 0 loads, 3 stores */
u8 unk_4; /* 0 loads, 1 stores */
u8 pad_5[0x1D];
u8 unk_22; /* 1 loads, 0 stores */
u8 pad_23[0x25];
} Obj_4_bss_5630;
extern Obj_4_bss_5630 lbl_4_bss_5630;
/* lbl_4_bss_2: .bss size 0x1, referenced by 5 functions, shape {'object': 10} */
extern u8 lbl_4_bss_2;
/* lbl_4_data_2F78: .data size 0xA0, referenced by 5 functions, shape {} */
extern u8 lbl_8_data_A1E8[0xA0];
/* lbl_4_data_2F1C: .data size 0x4, referenced by 4 functions, shape {'object': 4} */
extern u32 lbl_4_data_2F1C;
/* lbl_4_bss_5684: .bss size 0x1, referenced by 3 functions, shape {'object': 3} */
extern u8 lbl_4_bss_5684;
/* lbl_4_bss_4: .bss size 0x4, referenced by 2 functions, shape {'object': 2} */
extern u32 lbl_4_bss_4;
/* lbl_4_bss_10: .bss size 0xB4, referenced by 2 functions, shape {'object': 8} */
typedef struct {
u16 unk_0; /* 4 loads, 4 stores */
u8 pad_2[0xB2];
} Obj_4_bss_10;
extern Obj_4_bss_10 lbl_4_bss_10;
/* lbl_4_bss_C4: .bss size 0x5554, referenced by 2 functions, shape {'object': 16} */
typedef struct {
u8 pad_0[0x2];
u16 unk_2; /* 1 loads, 1 stores */
u16 unk_4; /* 1 loads, 1 stores */
u16 unk_6; /* 1 loads, 1 stores */
u32 unk_8; /* 1 loads, 1 stores */
u32 unk_C; /* 1 loads, 1 stores */
u32 unk_10; /* 1 loads, 1 stores */
u32 unk_14; /* 1 loads, 1 stores */
u32 unk_18; /* 1 loads, 1 stores */
u8 pad_1C[0x5538];
} Obj_4_bss_C4;
extern Obj_4_bss_C4 lbl_4_bss_C4;
/* lbl_4_data_2F00: .data size 0x1C, referenced by 2 functions, shape {'object': 6} */
typedef struct {
u8 pad_0[0x18];
u32 unk_18; /* 3 loads, 1 stores */
} Obj_4_data_2F00;
extern Obj_4_data_2F00 lbl_4_data_2F00;
/* lbl_4_bss_5685: .bss size 0x1, referenced by 2 functions, shape {'object': 6} */
extern u8 lbl_4_bss_5685;
typedef struct { u32 value; } EntryColor;
extern EntryColor lbl_8_rodata_C24;
extern EntryColor lbl_8_rodata_C28;
extern s32 lbl_801A66B4;
extern struct fn_4_D420_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_435C(u32);
extern s32 fn_1_45D0(u32, u32, u8 *, u32);
extern s32 fn_1_3F8C(u8 *, u32, u32, u32);
extern void fn_1_A2D84(u32);
extern s32 fn_1_14CEB8(u32);
extern void fn_80083DB0(void *, void *);
extern void fn_8_D630(void);
struct fn_4_D420_lbl_801A6410 {
u32 unk_0;
};
/* scratch record built for each populated entry */
typedef struct {
u8 unk_0;
u8 unk_1;
u8 unk_2;
u8 unk_3;
u16 unk_4;
u16 unk_6;
u16 unk_8;
u16 unk_A;
u8 unk_C;
u8 pad_D[0x3];
u32 unk_10;
} Entry_4_D420;
static inline u8 fn_4_D420_array_read(u8 *array, s32 index) { return array[index]; }
static inline u8 entry_at(s32 index, u8 *array) { return array[index]; }
static inline u32 widen_entry(u8 value) { return value; }
#pragma opt_loop_invariants off
#pragma opt_dead_assignments off
#pragma opt_propagation off
s32 fn_8_FC5C(void) {
u16 fzgx_value;
u8 *data;
EntryColor c;
EntryColor c2;
u8 *src2;
s32 res;
u32 offset;
u32 n2;
u8 *src;
s32 i;
u8 n;
s32 k;
Entry_4_D420 *t;
Obj_4_bss_5680_Target *obj;
res = 0;
data = lbl_8_data_A1E8;
if ((lbl_8_bss_550->unk_0 >> 30) & 1) {
c = lbl_8_rodata_C28;
fn_1_435C(lbl_8_bss_550->unk_8);
n = 0;
i = 0;
/* Volatile reload preserves the global pointer lookup on each loop test. */
while ((obj = *(Obj_4_bss_5680_Target * volatile *)&lbl_8_bss_550, src = (u8 *)obj + 0x28 + i), fn_4_D420_array_read(src, 0) != 0) {
t = (Entry_4_D420 *)fn_1_45D0(lbl_801A6410.unk_0, 0x12, data + 0xA0, 0xD4);
t->unk_8 = n * 0x38 + 0x7E;
t->unk_A = 0x17A;
t->unk_0 = 2;
t->unk_1 = 0;
t->unk_4 = t->unk_8;
t->unk_6 = t->unk_A;
t->unk_2 = fn_4_D420_array_read(src, 0);
t->unk_3 = fn_4_D420_array_read(src, 1);
*(EntryColor *)((u8 *)t + 0xD) = c;
t->unk_C = n;
fn_1_3F8C(data + 0xC8, (u32)&fn_8_D630, (u32)t, 0xB);
i += 2;
n += 1;
}
lbl_8_bss_550->unk_0 = obj->unk_0 & ~0x40000000;
}
if (lbl_8_bss_550->unk_0 >> 31) {
return 1;
}
if (((lbl_8_bss_550->unk_0 >> 29) & 1) || ((lbl_8_bss_550->unk_0 >> 28) & 1)) {
fn_1_A2D84(0xA9010100);
lbl_8_bss_550->unk_0 &= ~0x20000000;
lbl_8_bss_550->unk_0 &= ~0x10000000;
lbl_8_bss_550->unk_0 |= 0x80000000;
if (fn_1_14CEB8((u32)lbl_8_bss_550 + 0x28) != 0) {
k = 0;
i = 0;
lbl_8_bss_550->unk_0 |= 0x40000000;
while ((obj = lbl_8_bss_550, offset = 0x28 + i, ((u8 *)obj)[offset]) != 0) {
obj->unk_20 |= 0x80000000 >> k;
i += 2;
k += 1;
}
}
if (((u8 *)lbl_8_bss_550)[0x28] == 0) {
if (lbl_801A66B4 == 5) {
fn_80083DB0((u8 *)lbl_8_bss_550 + 0x28, data + 0x114);
} else {
fn_80083DB0((u8 *)lbl_8_bss_550 + 0x28, data + 0x120);
}
c2 = lbl_8_rodata_C24;
fn_1_435C(lbl_8_bss_550->unk_8);
n = 0;
offset = 0;
while ((src2 = (u8 *)lbl_8_bss_550 + 0x28 + offset), src2[0] != 0) {
i = n;
t = (Entry_4_D420 *)fn_1_45D0(lbl_801A6410.unk_0, 0x12, data + 0xA0, 0xD4);
t->unk_8 = i * 0x38 + 0x7E;
t->unk_A = 0x17A;
t->unk_0 = 2;
t->unk_1 = 0;
fzgx_value = t->unk_8;
t->unk_4 = fzgx_value;
t->unk_6 = t->unk_A;
t->unk_2 = fn_4_D420_array_read(src2, 0);
t->unk_3 = fn_4_D420_array_read(src2, 1);
*(EntryColor *)((u8 *)t + 0xD) = c2;
t->unk_C = i;
fn_1_3F8C(data + 0xC8, (u32)&fn_8_D630, (u32)t, 0xB);
offset += 2;
n += 1;
}
lbl_8_bss_550->unk_E = n;
}
res = 1;
}
return res;
}
#pragma opt_dead_assignments reset

#pragma opt_loop_invariants reset
/* fzgx:end fn_8_FC5C */
