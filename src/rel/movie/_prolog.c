#include "types.h"
#include "rel/movie/globals.h"
extern u32 lbl_5_bss_0[8];
extern struct fn_5_200_lbl_1_bss_970 lbl_1_bss_970;
extern u32 fn_1_3CC4(u32);
extern u32 fn_1_407C(u32);
extern u32 fn_1_435C(u32);
extern const f32 lbl_5_rodata_0;
extern void fn_8006CE1C(f32);
extern void fn_1_3C78(void);
extern void fn_1_157940(void);
extern void fn_1_41A8(u32);
extern void fn_1_A0AA4(void);
extern void fn_1_47A60(u32);
extern void fn_800068F4(u32);
extern void fn_80006904(u32);
extern void fn_1_A5C98(void *);
extern s16 lbl_1_bss_962;
extern struct fn_5_320_lbl_5_data_40 lbl_5_data_40;
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;
extern u32 fn_1_412A0(u32);
extern u32 fn_1_48140(u32);
extern u8 lbl_5_bss_5F;
extern u8 lbl_5_bss_61;
extern u32 fn_5_3C44(void);
extern u8 lbl_5_bss_40;

/* fzgx:begin fn_5_200 */
struct fn_5_200_lbl_1_bss_970 {
    u32 unk_0;
};

void fn_5_200(void) {
    if ((s32) lbl_1_bss_970.unk_0 > 0) {
        lbl_1_bss_970.unk_0 -= 1;
    }
}
/* fzgx:end fn_5_200 */

/* fzgx:begin fn_5_220 */
struct fn_5_220_lbl_5_bss_0 {
    u8 pad_0[0x28];
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
};

void fn_5_220(void) {
    struct fn_5_220_lbl_5_bss_0 *p_lbl_5_bss_0;
    u32 t0, t2, t3, t5, t7;
    p_lbl_5_bss_0 = (struct fn_5_220_lbl_5_bss_0 *)&(*(struct fn_5_220_lbl_5_bss_0 *)&lbl_5_bss_0);
    t0 = fn_1_435C(p_lbl_5_bss_0->unk_28);
    fn_1_407C(t0);
    t2 = fn_1_435C(p_lbl_5_bss_0->unk_30);
    t3 = fn_1_407C(t2);
    fn_1_3CC4(t3);
    t5 = fn_1_435C(p_lbl_5_bss_0->unk_2C);
    fn_1_407C(t5);
    t7 = fn_1_435C(p_lbl_5_bss_0->unk_34);
    fn_1_407C(t7);
}
/* fzgx:end fn_5_220 */

/* fzgx:begin _epilog */
struct epilog_bss {
    u8 pad_0[0x20];
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u8 unk_38[1];
};

void _epilog(void) {
    struct epilog_bss *p;
    u32 t0;

    p = (struct epilog_bss *)&lbl_5_bss_0;
    fn_8006CE1C(lbl_5_rodata_0);
    fn_1_3C78();
    fn_1_157940();
    t0 = fn_1_435C(p->unk_28);
    fn_1_41A8(t0);
    t0 = fn_1_435C(p->unk_2C);
    fn_1_41A8(t0);
    t0 = fn_1_435C(p->unk_30);
    fn_1_41A8(t0);
    t0 = fn_1_435C(p->unk_34);
    fn_1_41A8(t0);
    fn_1_A0AA4();
    fn_1_47A60(8);
    fn_800068F4(p->unk_20);
    fn_80006904(p->unk_24);
    p->unk_20 = 0;
    p->unk_24 = 0;
    fn_1_A5C98(&p->unk_38);
}
/* fzgx:end _epilog */

/* fzgx:begin fn_5_320 */
typedef u32 (*fn_5_320_Fn0)(void);
struct fn_5_320_lbl_5_data_40_0_E44 {
    u8 pad_0[0x20];
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
};
struct fn_5_320_lbl_5_data_40 {
    struct fn_5_320_lbl_5_data_40_0_E44 unk_0[1];
};

void fn_5_320(void) {
    s32 i;
    struct fn_5_320_lbl_5_data_40_0_E44 *p;
    u32 v0;
    p = lbl_5_data_40.unk_0;
    i = lbl_1_bss_962;
    i -= 129;
    p += i;
    lbl_1_bss_71688 = p->unk_24;
    v0 = p->unk_28;
    lbl_1_bss_7168C = v0;
    ((fn_5_320_Fn0)p->unk_20)();
}
/* fzgx:end fn_5_320 */

/* fzgx:begin fn_5_684 */
void fn_5_684(void) {
    if ((s8)lbl_5_bss_5F != 0) {
    fn_1_48140(154);
    fn_1_48140(155);
    fn_1_48140(147);
    fn_1_412A0(1);
    }
    if ((s8)lbl_5_bss_61 != 0) {
    fn_1_48140(1);
    }
}
/* fzgx:end fn_5_684 */

/* fzgx:begin fn_5_13B0 */
void fn_5_13B0(void) {
    if ((s8)lbl_5_bss_40 != -2) {
    fn_5_3C44();
    }
    fn_1_48140(154);
    fn_1_48140(155);
    fn_1_48140(147);
    fn_1_412A0(1);
}
/* fzgx:end fn_5_13B0 */

/* fzgx:begin fn_5_1404 */
extern u32 lbl_5_bss_0[8];
extern struct fn_5_200_lbl_1_bss_970 lbl_1_bss_970;
extern const f32 lbl_5_rodata_0;

struct fn_5_1404_sel {
    u8 pad_0[0x4];
    u8 unk_4;
};

struct fn_5_1404_state {
    u8 pad_0[0x48];
    u8 unk_48;
    u8 pad_49[0x5];
    s16 unk_4E;
    s16 unk_50;
    u8 pad_52[0x2];
    f32 unk_54;
    u8 pad_58[0x5];
    s8 unk_5D;
    s8 unk_5E;
    s8 unk_5F;
};

struct fn_5_1404_entry {
    u8 x;
    u8 y;
    s16 id;
    char name[0x40];
};

struct fn_5_1404_color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
};

extern u8 lbl_5_data_0[20];
extern void fn_1_49410(void);
extern void fn_1_49514(struct fn_5_1404_color *);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4965C(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4AE0C(const char *, ...);

/* Shared literal pool primer: earlier functions of the TU own the first pool
 * slots (0.0f, 1.0f, 0.1f, 8.0f, 0.5f and the int-to-float 2^52 constant).
 * mwld ignores .fzgxpool. */
extern void fzgx_pool_sink(f32);
extern void fzgx_pool_sink_d(f64);
#pragma section ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_pool_primer_fn_5_1404(void) {
    fzgx_pool_sink(0.0f);
    fzgx_pool_sink(1.0f);
    fzgx_pool_sink(0.1f);
    fzgx_pool_sink(8.0f);
    fzgx_pool_sink(0.5f);
    fzgx_pool_sink_d(4503601774854144.0);
}

#define SET_TEXT_COLOR(R, G, B, A) \
    { \
        struct fn_5_1404_color color = { R, G, B, A }; \
        fn_1_49514(&color); \
    }

void fn_5_1404(struct fn_5_1404_entry *list) {
    struct fn_5_1404_sel *sel;
    struct fn_5_1404_state *st;
    u8 *str;
    struct fn_5_1404_entry *e;
    s32 i;
    f32 fx;
    f32 fy;
    const char *name;
    const char *fmt;

    str = lbl_5_data_0;
    st = (struct fn_5_1404_state *)&lbl_5_bss_0;
    fn_1_49410();
    fn_1_4955C(0.5f, 0.5f);
    SET_TEXT_COLOR(0x80, 0xff, 0x80, 0xff);
    sel = (struct fn_5_1404_sel *)&lbl_1_bss_970;
    e = list;
    i = 0;
    while (e->id != -1) {
        fx = (f32)(e->x * 12 + 50);
        fy = (f32)(e->y * 12 + 50);
        fn_1_496FC(fx, fy);
        fn_1_4AE0C((const char *)(str + 0x1544), e->name);
        if (i == sel->unk_4) {
            fn_1_496FC(fx - 12.0f - 4.0f, fy);
            SET_TEXT_COLOR(0xff, 0x00, 0x00, 0xff);
            fn_1_4A0D8((const char *)(str + 0x1548));
            SET_TEXT_COLOR(0x80, 0xff, 0x80, 0xff);
        }
        e++;
        i++;
    }
    SET_TEXT_COLOR(0xff, 0xff, 0x80, 0xff);
    fn_1_496FC(80.0f, 360.0f);
    fn_1_4955C(0.6f, 0.6f);
    fn_1_4965C(2);
    fmt = (const char *)(str + 0x154c);
    name = (const char *)(str + 0x1578);
    if (st->unk_48 != 0) {
        name = (const char *)(str + 0x1574);
    }
    fn_1_4AE0C(fmt, name);
    fn_1_4AE0C((const char *)(str + 0x157c), st->unk_54);
    fn_1_4AE0C((const char *)(str + 0x15b4), st->unk_4E, st->unk_50);
    if (st->unk_5D == 5) {
        name = (const char *)(str + 0x15e8);
    } else if (st->unk_5D == 0) {
        name = (const char *)(str + 0x15f4);
    } else if (st->unk_5D == 1) {
        name = (const char *)(str + 0x1600);
    } else if (st->unk_5D == 2) {
        name = (const char *)(str + 0x160c);
    } else if (st->unk_5D == 3) {
        name = (const char *)(str + 0x1618);
    } else {
        name = (const char *)(str + 0x1630);
        if (st->unk_5D == 4) {
            name = (const char *)(str + 0x1624);
        }
    }
    fn_1_4AE0C((const char *)(str + 0x1634), name);
    fmt = (const char *)(str + 0x1654);
    name = (const char *)(str + 0x1578);
    if (st->unk_5E != 0) {
        name = (const char *)(str + 0x1574);
    }
    fn_1_4AE0C(fmt, name);
    fmt = (const char *)(str + 0x1678);
    name = (const char *)(str + 0x1578);
    if (st->unk_5F != 0) {
        name = (const char *)(str + 0x1574);
    }
    fn_1_4AE0C(fmt, name);
}
/* fzgx:end fn_5_1404 */

/* fzgx:begin fn_5_3BF8 */
typedef u32 (*fn_5_3BF8_Fn0)(u32);
struct fn_5_3BF8_lbl_5_bss_0 {
    u32 unk_0;
    u8 pad_4[0x3C];
    u8 unk_40;
    u8 unk_41;
};



void fn_5_3BF8(void) {
    struct fn_5_3BF8_lbl_5_bss_0 *p_lbl_5_bss_0;
    u32 v0;
    u32 v1;
    p_lbl_5_bss_0 = (struct fn_5_3BF8_lbl_5_bss_0 *)&(*(struct fn_5_3BF8_lbl_5_bss_0 *)&lbl_5_bss_0);
    v0 = p_lbl_5_bss_0->unk_0;
    v1 = *(u32 *)v0;
    ((fn_5_3BF8_Fn0)*(u32 *)((u8 *)v1 + 28))(v0);
    p_lbl_5_bss_0->unk_40 = 0;
    p_lbl_5_bss_0->unk_41 = 0;
}
/* fzgx:end fn_5_3BF8 */
