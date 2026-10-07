#include "types.h"
#include "rel/option/globals.h"

extern struct fn_4_347C_lbl_1_bss_9C8 lbl_1_bss_9C8;
extern u32 lbl_1_data_2AC0;
extern u32 lbl_1_data_2B40;
extern u32 lbl_1_data_2B50;
extern u32 lbl_1_data_2B58;
extern u32 lbl_4_data_14D0;
extern void fn_4_3128(void);
extern u32 fn_80008BA8(u32, u32, u32);
extern u32 fn_1_F7308(void);
extern u32 lbl_1_bss_AA0;
extern u32 lbl_1_data_2B60;
extern u32 lbl_4_data_2AE8;
extern u32 memcpy(u32, u32, u32);
extern void fn_4_63D4(void);
extern int fn_1_4C10(void);
extern u16 lbl_1_bss_96A;
extern u32 fn_4_0(u32, u32, u32, u32, u32);
extern u32 lbl_1_bss_9F8;
extern u8 lbl_4_data_2C58[84];
extern void fn_1_1280(u32);
extern void fn_1_A2D84(u32);
extern u32 fn_4_ABB0(void);
extern u32 fn_1_1380F0(u32);
extern u32 fn_1_13ABA8(u32);
extern u32 lbl_4_data_1A4;
extern s32 lbl_801A66B4;
extern u8 lbl_4_bss_5618;
extern u32 fn_1_B7E98(u32);
extern u32 fn_1_B800C(u32);
extern u32 fn_1_B80F0(u32);
extern u32 fn_1_B8170(u32);
extern u32 lbl_4_data_2DB4;
extern void fn_4_9AD0(void);
extern u8 *fn_4_A82C(u8 *);
extern void fn_80083DB0(u8 *, u32);
extern u32 fn_1_B9C0C(void);
extern s8 fn_1_BA144(u32 *);
extern u32 lbl_4_bss_5678;
extern u32 fn_1_B7C00(void);
extern u32 fn_1_BC310(void *);
extern u32 fn_1_C0510(u32);
extern u32 fn_1_C1394(void *);
extern s16 lbl_1_bss_962;
extern struct fn_4_9B0_lbl_4_data_1260 lbl_4_data_1260;
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;
extern u32 fn_1_3CC4(u32);
extern u32 fn_1_407C(u32);
extern u32 fn_1_426C(u32);
extern void fn_4_AB90(void);
extern struct _prolog_lbl_1_bss_6EAD0 lbl_1_bss_6EAD0;
extern struct fn_4_869C_lbl_1_bss_718E0 lbl_1_bss_718E0;
extern s32 lbl_1_bss_970;
extern u8 lbl_4_bss_2;
extern u16 lbl_1_bss_968;

/* fzgx:begin fn_4_0 */
extern u32 lbl_1_bss_9F8;
extern void fn_1_A2D84(u32);
/* Input flags may change asynchronously. */
struct Input { u8 pad[16]; volatile u16 flags; volatile u16 repeat; };
#pragma opt_common_subs on
u32 fn_4_0(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    u32 v15 = arg0;
    s32 v14 = 0;
    u32 v1;
    u32 v2;
    if ((s32)arg3 == -1) {
        if (arg4 == 0) {
            v1 = ((((struct Input *)&lbl_1_bss_9F8)[0].flags >> 3 & 1) != 0 || (((struct Input *)&lbl_1_bss_9F8)[0].repeat >> 3 & 1) != 0);
            v2 = ((((struct Input *)&lbl_1_bss_9F8)[0].flags >> 2 & 1) != 0 || (((struct Input *)&lbl_1_bss_9F8)[0].repeat >> 2 & 1) != 0);
        } else {
            v1 = ((((struct Input *)&lbl_1_bss_9F8)[0].flags & 1) != 0 || (((struct Input *)&lbl_1_bss_9F8)[0].repeat & 1) != 0);
            v2 = ((((struct Input *)&lbl_1_bss_9F8)[0].flags >> 1 & 1) != 0 || (((struct Input *)&lbl_1_bss_9F8)[0].repeat >> 1 & 1) != 0);
        }
    } else {
        if (arg4 == 0) {
            s32 offset = arg3 * 20;
            /* volatile: input flags may change asynchronously between reads. */
            volatile u16 *v6 = (volatile u16 *)((u8 *)&lbl_1_bss_9F8 + (u32)offset);
            v1 = ((*(v6 += 8) >> 3 & 1) != 0 || (*(volatile u16 *)((u8 *)&lbl_1_bss_9F8 + offset + 18) >> 3 & 1) != 0); /* volatile: asynchronous input */
            v2 = ((*v6 >> 2 & 1) != 0 || (*(volatile u16 *)((u8 *)&lbl_1_bss_9F8 + offset + 18) >> 2 & 1) != 0); /* volatile: asynchronous input */
        } else {
            s32 offset = arg3 * 20;
            /* volatile: input flags may change asynchronously between reads. */
            volatile u16 *v6 = (volatile u16 *)((u8 *)&lbl_1_bss_9F8 + (u32)offset);
            v1 = ((*(v6 += 8) & 1) != 0 || (*(volatile u16 *)((u8 *)&lbl_1_bss_9F8 + offset + 18) & 1) != 0); /* volatile: asynchronous input */
            v2 = ((*v6 >> 1 & 1) != 0 || (*(volatile u16 *)((u8 *)&lbl_1_bss_9F8 + offset + 18) >> 1 & 1) != 0); /* volatile: asynchronous input */
        }
    }
    if (v1 != 0) v14 = -1;
    if (v2 != 0) v14++;
    if (arg2 - arg1 == 1) {
        if (v14 == -1) v15 = arg1;
        else if (v14 == 1) v15 = arg2;
    } else {
        u32 v16 = arg0 + v14;
        if ((s32)v16 < (s32)arg1) v15 = arg2;
        else if (v16 > arg2) v15 = arg1;
        else v15 = v16;
    }
    if (arg0 != v15) fn_1_A2D84(0xA9010000);
    return v15;
}
/* fzgx:end fn_4_0 */

/* fzgx:begin fn_4_250 */
#include "font.h"

struct fn_4_250_Copy88 { u32 a[22]; };
struct fn_4_250_lbl_4_rodata_0 {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
};

extern int fn_1_4F734(FontDrawPacket *);
extern struct fn_4_250_lbl_4_rodata_0 lbl_4_rodata_0;
extern u32 lbl_1_rodata_26F8;

#pragma opt_lifetimes off
void fn_4_250(void) {
    f32 v0;
    f32 v1;
    FontDrawPacket loc_8;
    /* frame */
    loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v0 = (167.0f);
    v1 = (38.0f);
    loc_8.image = (0x10000 - 28668);
    loc_8.x = v0;
    loc_8.y = v1;
    loc_8.z = (0.5f);
    loc_8.flags = 10;
    fn_1_4F734((FontDrawPacket *)&loc_8);
}
#pragma opt_lifetimes reset
/* fzgx:end fn_4_250 */

/* fzgx:begin _prolog noprologue */
#include "types.h"

struct _prolog_lbl_4_bss_0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
};
struct _prolog_data {
    u8 pad_0[0x1250];
};
struct _prolog_lbl_801A6410 {
    u32 unk_0;
};
struct _prolog_lbl_1_bss_970 {
    u32 unk_0;
    u8 unk_4;
};
struct _prolog_lbl_1_bss_71684 {
    u32 unk_0;
};
struct _prolog_lbl_1_bss_6EAD0 {
    u32 unk_0;
};
extern struct _prolog_lbl_1_bss_6EAD0 lbl_1_bss_6EAD0;
extern struct _prolog_lbl_1_bss_71684 lbl_1_bss_71684;
extern struct _prolog_lbl_1_bss_970 lbl_1_bss_970;
extern struct _prolog_lbl_4_bss_0 lbl_4_bss_0;
extern struct _prolog_lbl_801A6410 lbl_801A6410;
extern u16 lbl_1_bss_96A;
extern u32 lbl_1_bss_7167C;
extern u32 lbl_1_bss_71680;
extern u8 lbl_4_data_0[];
extern s32 fn_1_45D0(u32, u32, u32, u32);
extern u32 fn_1_3CF0(u32, u32);
extern u32 fn_1_435C(u32);
extern s32 fn_1_3F8C(u32, u32, u32, u32);
extern void fn_1_411A4(u32);
extern u32 fn_1_479F0(s16);
extern void fn_1_48418(int);
extern void fn_1_159440(int, int);
extern u32 fn_8004CD70(u32, u32, u32);

s32 fn_1_A176C(u32, s32);                   /* extern */
extern s32 fn_1_133DBC;
extern s32 fn_1_134AD4;
extern s32 fn_4_250;
extern s32 fn_4_800;
extern s32 fn_4_894;
extern s32 fn_4_9B0;

#pragma opt_common_subs off
#pragma opt_propagation off
void _prolog(void) {
    struct _prolog_lbl_4_bss_0 *bss;
    struct _prolog_data *data;
    u32 lab_t0;
    u32 lab_t0_;

    bss = &lbl_4_bss_0;
    data = (struct _prolog_data *)lbl_4_data_0;

    lab_t0 = lbl_801A6410.unk_0;
    lab_t0_ = lab_t0;
    bss->unk_4 = fn_1_45D0(lab_t0_, 0xE3CU, (u32)((u8 *)data + 0x1218), 0x320U);
    lab_t0 = lbl_801A6410.unk_0;
    lab_t0_ = lab_t0;
    bss->unk_8 = fn_1_45D0(lab_t0_, 0xE3CU, (u32)((u8 *)data + 0x1218), 0x321U);
    fn_1_3CF0(bss->unk_4, 0x40U);
    fn_1_3CF0(bss->unk_8, 0x40U);
    fn_1_435C(bss->unk_4);
    fn_1_435C(bss->unk_8);
    fn_1_3F8C((u32)((u8 *)data + 0x1224), (u32)(&fn_1_133DBC), 0U, 0x11U);
    fn_1_3F8C((u32)((u8 *)data + 0x1238), (u32)(&fn_1_134AD4), 0U, 0x11U);
    fn_1_3F8C((u32)((u8 *)data + 0x124C), (u32)(&fn_4_250), 0U, 0x11U);
    lbl_1_bss_970.unk_0 = 0;
    lbl_1_bss_970.unk_4 = 0;
    bss->unk_C = 0;
    bss->unk_D = 0;
    lbl_1_bss_96A = 0x4B;
    bss->unk_E = 0;
    lbl_1_bss_7167C = (u32)(&fn_4_800);
    lbl_1_bss_71680 = (u32)(&fn_4_894);
    lbl_1_bss_71684.unk_0 = (u32)(&fn_4_9B0);
    fn_1_411A4(1U);
    fn_1_479F0(3);
    fn_1_48418(2);
    fn_1_159440(2, 0);
    if ((u32) lbl_1_bss_6EAD0.unk_0 != 0) {
        if ((u32) (*(u32 *)((u8 *)(lbl_1_bss_6EAD0.unk_0) + 0)) == 0) {
            (*(u32 *)((u8 *)(lbl_1_bss_6EAD0.unk_0) + 0)) = fn_8004CD70(2U, lbl_1_bss_6EAD0.unk_0 + 0x10, 0x25124U);
        }
        if ((u32) (*(u32 *)((u8 *)(lbl_1_bss_6EAD0.unk_0) + 4)) == 0) {
            (*(u32 *)((u8 *)(lbl_1_bss_6EAD0.unk_0) + 4)) = fn_8004CD70(2U, lbl_1_bss_6EAD0.unk_0 + 0x4A258, 0x25124U);
        }
        fn_1_A176C(*(u32 *)((u8 *)(lbl_1_bss_6EAD0.unk_0) + 0), 0x37);
    }
}
#pragma opt_propagation reset

#pragma opt_common_subs reset
/* fzgx:end _prolog */

/* fzgx:begin fn_4_800 */
extern u32 fn_1_4A00(u32, u32, u32);
extern int fn_1_4C10(void);

void fn_4_800(void) {
    u8 value;

    value = lbl_4_bss_2;
    lbl_4_bss_2 = value + 1;

    switch (lbl_1_bss_970) {
    case 0:
        break;
    case 1:
        fn_1_4A00(0, 15, lbl_4_bss_8);
        lbl_1_bss_970 = 2;
        break;
    case 2:
        if (fn_1_4C10() == 0) {
            lbl_1_bss_968 = 1;
        }
        break;
    default:
        break;
    }
}
/* fzgx:end fn_4_800 */

/* fzgx:begin fn_4_894 */
extern u32 fn_1_435C(u32);

// Initializes both option subsystems in sequence.
void fn_4_894(void) {
    u32 first_state;
    u32 second_state;

    first_state = fn_1_435C(lbl_4_bss_4);
    first_state = fn_1_407C(first_state);
    fn_1_3CC4(first_state);

    second_state = fn_1_435C(lbl_4_bss_8);
    fn_1_407C(second_state);
}
/* fzgx:end fn_4_894 */

/* fzgx:begin _epilog */
#include "types.h"

extern const f32 lbl_4_rodata_4C[45];






extern void fn_8006CE1C(f32);
extern void fn_1_1596DC(u32);
extern void fn_1_484CC(u32);
extern void fn_1_47A60(u32);
extern void fn_1_412A0(u32);
extern void fn_1_3C78(void);
extern void fn_1_435C(u32);
extern void fn_1_41A8(void);
extern void fn_8004BF0C(u32, s32);
extern void ADXT_Stop(u32);

struct option_epilog_lbl_4_bss_4 {
    u32 unk_0;
};
struct option_epilog_lbl_4_bss_8 {
    u32 unk_0;
};
struct option_epilog_lbl_1_bss_6EAD0 {
    u32 unk_0;
};
struct option_epilog_object {
    u32 unk_0;
    u32 unk_4;
};

void _epilog(void) {
    fn_8006CE1C(lbl_4_rodata_4C[0]);
    fn_1_1596DC(2);
    fn_1_484CC(2);
    fn_1_47A60(3);
    fn_1_412A0(1);
    fn_1_3C78();
    fn_1_435C((*(struct option_epilog_lbl_4_bss_4 *)&lbl_4_bss_4).unk_0);
    fn_1_41A8();
    fn_1_435C((*(struct option_epilog_lbl_4_bss_8 *)&lbl_4_bss_8).unk_0);
    fn_1_41A8();
    if ((*(struct option_epilog_lbl_1_bss_6EAD0 *)&lbl_1_bss_6EAD0).unk_0 != 0) {
        fn_8004BF0C(((struct option_epilog_object *)(*(struct option_epilog_lbl_1_bss_6EAD0 *)&lbl_1_bss_6EAD0).unk_0)->unk_0, -999);
        fn_8004BF0C(((struct option_epilog_object *)(*(struct option_epilog_lbl_1_bss_6EAD0 *)&lbl_1_bss_6EAD0).unk_0)->unk_4, -999);
        ADXT_Stop(((struct option_epilog_object *)(*(struct option_epilog_lbl_1_bss_6EAD0 *)&lbl_1_bss_6EAD0).unk_0)->unk_0);
        ADXT_Stop(((struct option_epilog_object *)(*(struct option_epilog_lbl_1_bss_6EAD0 *)&lbl_1_bss_6EAD0).unk_0)->unk_4);
    }
}
/* fzgx:end _epilog */

/* fzgx:begin fn_4_9B0 */
#include "types.h"

extern struct fn_4_9B0_lbl_4_data_1260 lbl_4_data_1260;
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;

typedef u32 (*fn_4_9B0_Fn0)(void);
struct fn_4_9B0_lbl_4_data_1260_0_E44 {
    u8 pad_0[0x20];
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
};
struct fn_4_9B0_lbl_4_data_1260 {
    struct fn_4_9B0_lbl_4_data_1260_0_E44 unk_0[1];
};

void fn_4_9B0(void) {
    struct fn_4_9B0_lbl_4_data_1260_0_E44 *p;
    s16 idx;
    u32 v0;
    p = (struct fn_4_9B0_lbl_4_data_1260_0_E44 *)&lbl_4_data_1260;
    idx = lbl_1_bss_962;
    p = (struct fn_4_9B0_lbl_4_data_1260_0_E44 *)((u8 *)p + (idx - 75) * 44);
    lbl_1_bss_71688 = p->unk_24;
    lbl_1_bss_7168C = (p->unk_28);
    ((fn_4_9B0_Fn0)p->unk_20)();
}
/* fzgx:end fn_4_9B0 */

/* fzgx:begin fn_4_D10 noprologue */
#include "types.h"

extern struct fn_4_D10_lbl_4_bss_0 lbl_4_bss_0;
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_4A00(u32, u32, u32);
extern u32 lbl_4_data_14A0;
extern void fn_4_A0C(void);

struct fn_4_D10_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x6];
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
};

void fn_4_D10(void) {
    struct fn_4_D10_lbl_4_bss_0 *p_lbl_4_bss_0;
    u32 t1;
    p_lbl_4_bss_0 = (struct fn_4_D10_lbl_4_bss_0 *)&lbl_4_bss_0;
    fn_1_435C(p_lbl_4_bss_0->unk_8);
    t1 = fn_1_3F8C((u32)&lbl_4_data_14A0, (u32)fn_4_A0C, 0, 5);
    p_lbl_4_bss_0->unk_0 = t1;
    p_lbl_4_bss_0->unk_10 = 0;
    fn_1_4A00(1, 15, p_lbl_4_bss_0->unk_8);
}
/* fzgx:end fn_4_D10 */

/* fzgx:begin fn_4_D7C */
#include "types.h"
#include "rel/option/globals.h"

extern int fn_1_4C10(void);
extern void fn_1_1280(u32);
extern void fn_1_A2D84(u32);
extern u32 fn_4_0(u32, u32, u32, u32, u32);
extern u32 fn_1_4A00(u32, u32, u32);
extern u16 lbl_1_bss_96A;

struct fn_4_D7C_lbl_1_bss_970 {
    s32 unk_0;
    u8 unk_4;
};



struct fn_4_D7C_lbl_1_bss_6EAB4 {
    u32 unk_0;
};
extern struct fn_4_D7C_lbl_1_bss_6EAB4 lbl_1_bss_6EAB4;

struct fn_4_D7C_lbl_1_bss_9F8 {
    u8 pad_0[0x8];
    u16 unk_8;
};



struct fn_4_D7C_lbl_4_data_144C {
    s16 unk_0;
    u8 pad_2[0x1A];
};
extern struct fn_4_D7C_lbl_4_data_144C lbl_4_data_144C[];

void fn_4_D7C(void) {
    struct fn_4_D7C_lbl_1_bss_970 *p;
    u32 v;
    struct fn_4_D7C_lbl_1_bss_6EAB4 *q;

    p = (struct fn_4_D7C_lbl_1_bss_970 *)&(*(struct fn_4_D7C_lbl_1_bss_970 *)&lbl_1_bss_970);
    if (p->unk_0 <= 0) {
        if (lbl_4_bss_10.unk_0 != 0) {
            if (fn_1_4C10() == 0) {
                fn_1_1280(1);
                lbl_1_bss_96A = lbl_4_bss_10.unk_0;
                lbl_4_bss_10.unk_0 = 0;
            }
        } else {
            p->unk_4 = fn_4_0(p->unk_4, 0, 2, -1, 0);
            if (((*(struct fn_4_D7C_lbl_1_bss_9F8 *)&lbl_1_bss_9F8).unk_8 >> 9) & 1) {
                fn_1_A2D84(0xA9010200);
                q = (struct fn_4_D7C_lbl_1_bss_6EAB4 *)&lbl_1_bss_6EAB4;
                v = q->unk_0;
                q->unk_0 = v | 0x2C;
                (*(struct fn_4_D7C_lbl_1_bss_970 *)&lbl_1_bss_970).unk_0 = 1;
            } else if (((*(struct fn_4_D7C_lbl_1_bss_9F8 *)&lbl_1_bss_9F8).unk_8 >> 8) & 1) {
                fn_1_A2D84(0xA9010100);
                lbl_4_bss_10.unk_0 = lbl_4_data_144C[p->unk_4].unk_0;
                fn_1_4A00(0, 15, lbl_4_bss_8);
            }
        }
    }
}
/* fzgx:end fn_4_D7C */

/* fzgx:begin fn_4_EA0 */
// Clear the pending option selection after applying its associated value.
void fn_4_EA0(void) {
    if (lbl_4_bss_0 != 0) {
        fn_1_435C(lbl_4_bss_8);
        fn_1_426C(lbl_4_bss_0);
        lbl_4_bss_0 = 0;
    }
}
/* fzgx:end fn_4_EA0 */

/* fzgx:begin fn_4_347C noprologue */
#include "types.h"

extern struct fn_4_347C_lbl_1_bss_9C8 lbl_1_bss_9C8;
extern u32 lbl_1_data_2AC0;
extern u32 lbl_1_data_2B40;
extern u32 lbl_1_data_2B50;
extern u32 lbl_1_data_2B58;
extern u32 lbl_4_data_14D0;
extern void fn_4_3128(void);
extern u32 fn_80008BA8(u32, u32, u32);

struct fn_4_347C_lbl_1_bss_9C8_0_E12 {
    u8 pad_0[0x2];
    u8 unk_2;
    u8 unk_3;
    u8 pad_4[0x8];
};
struct fn_4_347C_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x6];
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
    u8 pad_12[0x46];
    u8 unk_58;
    u8 unk_59;
    u8 unk_5A;
    u8 unk_5B;
    u8 unk_5C;
    u8 unk_5D;
};
struct fn_4_347C_lbl_1_bss_9C8 {
    struct fn_4_347C_lbl_1_bss_9C8_0_E12 unk_0[1];
};

extern s32 fn_1_3F8C(u32, u32, u32, u32);
extern struct fn_4_347C_lbl_4_bss_0 lbl_4_bss_0;
extern u32 fn_1_435C(u32);
extern u32 fn_1_4A00(u32, u32, u32);

void fn_4_347C(void) {
    struct fn_4_347C_lbl_4_bss_0 *p_lbl_4_bss_0;
    u32 v0;
    u8 v1;
    u8 v2;
    u32 t1;
    p_lbl_4_bss_0 = (struct fn_4_347C_lbl_4_bss_0 *)&lbl_4_bss_0;
    fn_1_435C(p_lbl_4_bss_0->unk_8);
    t1 = fn_1_3F8C((u32)&lbl_4_data_14D0, (u32)fn_4_3128, 0, 20);
    p_lbl_4_bss_0->unk_0 = t1;
    fn_80008BA8((u32)((u8 *)(u32)p_lbl_4_bss_0 + 96), (u32)&lbl_1_data_2AC0, 64);
    fn_80008BA8((u32)((u8 *)(u32)p_lbl_4_bss_0 + 160), (u32)&lbl_1_data_2B40, 8);
    fn_80008BA8((u32)((u8 *)(u32)p_lbl_4_bss_0 + 168), (u32)&lbl_1_data_2B50, 8);
    fn_80008BA8((u32)((u8 *)(u32)p_lbl_4_bss_0 + 176), (u32)&lbl_1_data_2B58, 8);
    v0 = p_lbl_4_bss_0->unk_8;
    p_lbl_4_bss_0->unk_5A = 0;
    p_lbl_4_bss_0->unk_5C = 0;
    p_lbl_4_bss_0->unk_5B = 0;
    p_lbl_4_bss_0->unk_10 = 0;
    fn_1_4A00(1, 15, v0);
    v1 = lbl_1_bss_9C8.unk_0[p_lbl_4_bss_0->unk_5D].unk_2;
    p_lbl_4_bss_0->unk_58 = v1;
    p_lbl_4_bss_0->unk_59 = (lbl_1_bss_9C8.unk_0[p_lbl_4_bss_0->unk_5D].unk_3);
}
/* fzgx:end fn_4_347C */

/* fzgx:begin fn_4_406C */
// Finalizes the pending option callback and clears its handle.
void fn_4_406C(void) {
    if (lbl_4_bss_0 != 0) {
        fn_1_435C(lbl_4_bss_8);
        fn_1_426C(lbl_4_bss_0);
        lbl_4_bss_0 = 0;
    }
}
/* fzgx:end fn_4_406C */

/* fzgx:begin fn_4_4784 noprologue */
#include "types.h"

extern struct fn_4_4784_lbl_4_bss_0 lbl_4_bss_0;
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_4A00(u32, u32, u32);
extern u32 fn_1_F70D0(u32);
extern u32 fn_1_F7568(void);
extern u32 lbl_4_data_1500;
extern u32 lbl_4_data_150C;
extern void fn_1_F7128(void);
extern void fn_4_467C(void);

struct fn_4_4784_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x2];
    u32 unk_4;
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
    u8 pad_12[0xA8];
    u8 unk_BA;
    u8 unk_BB;
    u8 pad_BC[0x1];
    u8 unk_BD;
    u8 unk_BE;
    u8 pad_BF[0x1];
    u16 unk_C0;
};

void fn_4_4784(void) {
    struct fn_4_4784_lbl_4_bss_0 *p_lbl_4_bss_0;
    u32 t0, t1, t3, t5;
    p_lbl_4_bss_0 = (struct fn_4_4784_lbl_4_bss_0 *)&lbl_4_bss_0;
    t0 = fn_1_F7568();
    p_lbl_4_bss_0->unk_BE = t0;
    p_lbl_4_bss_0->unk_BA = t0;
    p_lbl_4_bss_0->unk_BD = 0;
    p_lbl_4_bss_0->unk_BB = 0;
    t1 = fn_1_435C(p_lbl_4_bss_0->unk_4);
    fn_1_F70D0(t1);
    t3 = fn_1_3F8C((u32)&lbl_4_data_1500, (u32)fn_1_F7128, 0, 10);
    p_lbl_4_bss_0->unk_C0 = t3;
    fn_1_435C(p_lbl_4_bss_0->unk_8);
    t5 = fn_1_3F8C((u32)&lbl_4_data_150C, (u32)fn_4_467C, 0, 5);
    p_lbl_4_bss_0->unk_0 = t5;
    p_lbl_4_bss_0->unk_10 = 0;
    fn_1_4A00(1, 15, p_lbl_4_bss_0->unk_8);
}
/* fzgx:end fn_4_4784 */

/* fzgx:begin fn_4_4834 noprologue */
#include "types.h"

struct fn_4_4834_lbl_4_bss_0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[0x2];
    u8 unk_E;
    u8 pad_F[0x1];
    u16 unk_10;
    u8 pad_12[0xA6];
    u16 unk_B8;
    u8 unk_BA;
    u8 unk_BB;
    u8 unk_BC;
    u8 unk_BD;
    u8 unk_BE;
};
struct fn_4_4834_lbl_1_bss_718E0 {
    u8 pad_0[0x2];
    u8 unk_2;
};
extern int fn_1_4C10(void);
extern struct fn_4_4834_lbl_1_bss_718E0 lbl_1_bss_718E0;
extern struct fn_4_4834_lbl_4_bss_0 lbl_4_bss_0;
extern u16 lbl_1_bss_96A;
extern u32 fn_4_0(u32, u32, u32, u32, u32);
extern u32 lbl_1_bss_9F8;
extern void fn_1_1280(u32);
extern void fn_1_156884(s32);
extern void fn_1_4A00(s32, u8, u32);
extern void fn_1_A2D84(u32);
extern void fn_1_F73A8(int, void *, void *);
extern void fn_1_F755C(u8);

static inline u32 test_bit(u32 value, u32 bit) {
    return (u32)__cntlzw(__rlwnm(value, (32 - bit) & 31, 31, 31)) >> 5;
}

void fn_4_4834(void) {
    struct fn_4_4834_lbl_4_bss_0 *p_lbl_4_bss_0;
    s32 v5;
    u32 v0;
    u16 v4;
    u32 v3;
    u32 v7;
    u32 v8;
    p_lbl_4_bss_0 = (struct fn_4_4834_lbl_4_bss_0 *)&lbl_4_bss_0;
    v5 = 0;
    if (p_lbl_4_bss_0->unk_10 != 0) {
        if (fn_1_4C10() == 0) {
            fn_1_1280(1);
            lbl_1_bss_96A = p_lbl_4_bss_0->unk_10;
            p_lbl_4_bss_0->unk_10 = 0;
        }
        return;
    }
    switch ((s32)p_lbl_4_bss_0->unk_BB) {
    case 0:
        p_lbl_4_bss_0->unk_BD = fn_4_0(p_lbl_4_bss_0->unk_BD, 0, 3, -1, 0);
        v0 = *(u16 *)((u8 *)&lbl_1_bss_9F8 + 8);
        if ((v0 >> 8) & 1) {
            fn_1_A2D84(0xA9010100);
            p_lbl_4_bss_0->unk_BB = 1;
        } else if ((v0 >> 9) & 1) {
            fn_1_A2D84(0xA9010200);
            if (p_lbl_4_bss_0->unk_BA == lbl_1_bss_718E0.unk_2) {
                fn_1_F755C(p_lbl_4_bss_0->unk_BE);
                v3 = p_lbl_4_bss_0->unk_8;
                p_lbl_4_bss_0->unk_10 = 77;
                fn_1_4A00(0, 15, v3);
            } else {
                p_lbl_4_bss_0->unk_BB = 2;
                p_lbl_4_bss_0->unk_BC = 0;
            }
        }
        break;
    case 1:
        if ((*(u16 *)((u8 *)&lbl_1_bss_9F8 + 8) >> 9) & 1) {
            fn_1_A2D84(0xA9010200);
            p_lbl_4_bss_0->unk_BB = 0;
            break;
        }
        v4 = *(u16 *)((u8 *)&lbl_1_bss_9F8 + 16);
        if (((v4 >> 1) & 1) || (((v0 = *(u16 *)((u8 *)&lbl_1_bss_9F8 + 18)) >> 1) & 1)) {
            p_lbl_4_bss_0->unk_BA &= ~(0x80000000u >> (31 - p_lbl_4_bss_0->unk_BD));
            fn_1_A2D84(0xA9010000);
        } else if ((v4 & 1) || (v0 & 1)) {
            fn_1_A2D84(0xA9010000);
            v7 = p_lbl_4_bss_0->unk_BD;
            v8 = p_lbl_4_bss_0->unk_BA;
            v5 = test_bit(v8, v7);
            p_lbl_4_bss_0->unk_BA = v8 | (0x80000000u >> (31-v7));
        }
        fn_1_F755C(p_lbl_4_bss_0->unk_BA);
        if (v5) {
            fn_1_F73A8(p_lbl_4_bss_0->unk_BD, (void *)1, (void *)18);
            fn_1_156884(p_lbl_4_bss_0->unk_BD);
        }
        break;
    case 2:
        p_lbl_4_bss_0->unk_BC = fn_4_0(p_lbl_4_bss_0->unk_BC, 0, 1, -1, 1);
        v0 = *(u16 *)((u8 *)&lbl_1_bss_9F8 + 8);
        if ((v0 >> 9) & 1) {
            fn_1_A2D84(0xA9010200);
            p_lbl_4_bss_0->unk_BB = 0;
        } else if ((v0 >> 8) & 1) {
            fn_1_A2D84(0xA9010100);
            if (p_lbl_4_bss_0->unk_BC == 0) {
                lbl_1_bss_718E0.unk_2 = p_lbl_4_bss_0->unk_BA;
                p_lbl_4_bss_0->unk_E = 1;
                p_lbl_4_bss_0->unk_B8 = 77;
                p_lbl_4_bss_0->unk_10 = 76;
            } else {
                fn_1_F755C(p_lbl_4_bss_0->unk_BE);
                v3 = p_lbl_4_bss_0->unk_8;
                p_lbl_4_bss_0->unk_10 = 77;
                fn_1_4A00(0, 15, v3);
            }
        }
        break;
    }
}
/* fzgx:end fn_4_4834 */

/* fzgx:begin fn_4_4B10 */
extern u32 fn_1_435C(u32);

struct fn_4_4B10_state {
    u16 unk_0;
    u8 pad_2[0x2];
    u32 unk_4;
    u32 unk_8;
    u8 pad_C[0xB4];
    u16 unk_C0;
};

/* Stop active option sounds and clear the pending sound handle. */
void fn_4_4B10(void) {
    struct fn_4_4B10_state *state;

    state = (struct fn_4_4B10_state *)&lbl_4_bss_0;
    fn_1_F7308();
    fn_1_435C(state->unk_4);
    fn_1_426C(state->unk_C0);
    if (state->unk_0 != 0) {
        fn_1_435C(state->unk_8);
        fn_1_426C(state->unk_0);
        state->unk_0 = 0;
    }
}
/* fzgx:end fn_4_4B10 */

/* fzgx:begin fn_4_4B74 noprologue */
#include "types.h"

extern u8 jumptable_4_data_2974[36];

struct fn_4_4B74_obj {
    u16 unk_0;
    u16 unk_2;
    u16 unk_4;
    u16 unk_6;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
};

extern struct fn_4_4B74_obj lbl_4_bss_C4[];

s32 fn_4_4B74(u32 arg0, u32 arg1) {
    u32 idx;
    u32 v;

    switch (arg0) {
    case 0:
    case 4:
    default:
        idx = 0;
        break;
    case 1:
        idx = 0;
        break;
    case 2:
        idx = 1;
        break;
    case 3:
        idx = 2;
        break;
    }

    switch (arg1) {
    case 0:
        v = lbl_4_bss_C4[idx].unk_0;
        break;
    case 1:
        v = lbl_4_bss_C4[idx].unk_2;
        break;
    case 2:
        v = lbl_4_bss_C4[idx].unk_4;
        break;
    case 3:
        v = lbl_4_bss_C4[idx].unk_6;
        break;
    case 4:
        v = lbl_4_bss_C4[idx].unk_8;
        break;
    case 5:
        v = lbl_4_bss_C4[idx].unk_C;
        break;
    case 6:
        v = lbl_4_bss_C4[idx].unk_10;
        break;
    case 7:
        v = lbl_4_bss_C4[idx].unk_14;
        break;
    case 8:
        v = lbl_4_bss_C4[idx].unk_18;
        break;
    }

    return 31 - __cntlzw(v);
}
/* fzgx:end fn_4_4B74 */

/* fzgx:begin fn_4_6678 noprologue */
#include "types.h"

extern u32 fn_80008BA8(u32, u32, u32);
extern u32 lbl_1_bss_AA0;
extern u32 lbl_1_data_2B60;
extern u32 lbl_4_data_2AE8;
extern u32 memcpy(u32, u32, u32);
extern void fn_4_63D4(void);

extern struct fn_4_6678_lbl_4_bss_0 lbl_4_bss_0;
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_4A00(u32, u32, u32);

struct fn_4_6678_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x6];
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
    u8 pad_12[0x106];
    u8 unk_118;
    u8 pad_119[0x2];
    u8 unk_11B;
    u8 pad_11C[0x2];
    u8 unk_11E;
    u8 pad_11F[0x155];
    u8 unk_274;
};

void fn_4_6678(void) {
    struct fn_4_6678_lbl_4_bss_0 *p_lbl_4_bss_0;
    u32 t1;
    p_lbl_4_bss_0 = (struct fn_4_6678_lbl_4_bss_0 *)&lbl_4_bss_0;
    fn_1_435C(p_lbl_4_bss_0->unk_8);
    t1 = fn_1_3F8C((u32)&lbl_4_data_2AE8, (u32)fn_4_63D4, 0, 5);
    p_lbl_4_bss_0->unk_0 = t1;
    fn_80008BA8((u32)((u8 *)p_lbl_4_bss_0 + 288), (u32)&lbl_1_bss_AA0, 336);
    memcpy((u32)((u8 *)p_lbl_4_bss_0 + 624), (u32)&lbl_1_data_2B60, 4);
    p_lbl_4_bss_0->unk_11B = 0;
    p_lbl_4_bss_0->unk_274 = 255;
    p_lbl_4_bss_0->unk_118 = 0;
    p_lbl_4_bss_0->unk_11E = 0;
    p_lbl_4_bss_0->unk_10 = 0;
    fn_1_4A00(1, 15, p_lbl_4_bss_0->unk_8);
}
/* fzgx:end fn_4_6678 */

/* fzgx:begin fn_4_78E0 */
extern u32 fn_1_435C(u32);

/* Clears the pending option state after notifying the option handlers. */
void fn_4_78E0(void) {
    if (lbl_4_bss_0 != 0) {
        fn_1_435C(lbl_4_bss_8);
        fn_1_426C(lbl_4_bss_0);
        lbl_4_bss_0 = 0;
    }
}
/* fzgx:end fn_4_78E0 */

/* fzgx:begin fn_4_7C38 noprologue */
#include "types.h"

extern struct fn_4_7C38_lbl_4_bss_0 lbl_4_bss_0;
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_4A00(u32, u32, u32);
extern u32 lbl_4_data_2CAC;
extern void fn_4_7938(void);

struct fn_4_7C38_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x6];
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
};

void fn_4_7C38(void) {
    struct fn_4_7C38_lbl_4_bss_0 *p_lbl_4_bss_0;
    u32 t1;
    p_lbl_4_bss_0 = (struct fn_4_7C38_lbl_4_bss_0 *)&lbl_4_bss_0;
    fn_1_435C(p_lbl_4_bss_0->unk_8);
    t1 = fn_1_3F8C((u32)&lbl_4_data_2CAC, (u32)fn_4_7938, 0, 5);
    p_lbl_4_bss_0->unk_0 = t1;
    p_lbl_4_bss_0->unk_10 = 0;
    fn_1_4A00(1, 15, p_lbl_4_bss_0->unk_8);
}
/* fzgx:end fn_4_7C38 */

/* fzgx:begin fn_4_7CA4 */
extern int fn_1_4C10(void);
extern u16 lbl_1_bss_96A;
extern u32 fn_4_0(u32, u32, u32, u32, u32);

extern void fn_1_1280(u32);
extern void fn_1_A2D84(u32);

struct fn_4_7CA4_lbl_4_bss_0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 unk_C;
    u8 pad_D[0x3];
    u16 unk_10;
};

extern u32 fn_1_4A00(u32, u32, u32);

void fn_4_7CA4(void) {
    struct fn_4_7CA4_lbl_4_bss_0 *option_state;
    u32 result;
    u32 availability, selected_mode, notification_result;

    /* Apply pending option changes, then update the active option state. */
    option_state = (struct fn_4_7CA4_lbl_4_bss_0 *)&lbl_4_bss_0;
    if (option_state->unk_10 != 0) {
        availability = fn_1_4C10();
        result = availability;
        if ((s32)result != 0) {
            return;
        }
        result = 1;
        fn_1_1280(result);
        lbl_1_bss_96A = option_state->unk_10;
        option_state->unk_10 = 0;
        return;
    }
    result = option_state->unk_C;
    selected_mode = fn_4_0(result, 0, 2, -1, 0);
    result = selected_mode;
    option_state->unk_C = result;
    result = (u32)&lbl_1_bss_9F8;
    result = *(u16 *)((u8 *)result + 8);
    if (((result >> 9) & 0x1) != 0) {
        result = 0xA9010000;
        result += 512;
        fn_1_A2D84(result);
        option_state->unk_10 = 75;
    } else {
        if (((result >> 8) & 0x1) != 0) {
            result = 0xA9010000;
            result += 256;
            fn_1_A2D84(result);
            result = (u32)&lbl_4_data_2C58;
            option_state->unk_10 = *(s16 *)((u8 *)result + (option_state->unk_C * 28));
        } else {
            return;
        }
    }
    result = 0;
    notification_result = fn_1_4A00(result, 15, option_state->unk_8);
    result = notification_result;
}
/* fzgx:end fn_4_7CA4 */

/* fzgx:begin fn_4_7D94 */
extern u32 fn_1_435C(u32);

// Reset the option subsystem after releasing its active resource.
void fn_4_7D94(void) {
    if (lbl_4_bss_0 != 0) {
        fn_1_435C(lbl_4_bss_8);
        fn_1_426C(lbl_4_bss_0);
        lbl_4_bss_0 = 0;
    }
}
/* fzgx:end fn_4_7D94 */

/* fzgx:begin fn_4_80EC noprologue */
#include "types.h"

extern struct fn_4_80EC_lbl_4_bss_0 lbl_4_bss_0;
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_4A00(u32, u32, u32);
extern u32 lbl_4_data_2D5C;
extern void fn_4_7DEC(void);

struct fn_4_80EC_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x6];
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
};

void fn_4_80EC(void) {
    struct fn_4_80EC_lbl_4_bss_0 *p_lbl_4_bss_0;
    u32 t1;
    p_lbl_4_bss_0 = (struct fn_4_80EC_lbl_4_bss_0 *)&lbl_4_bss_0;
    fn_1_435C(p_lbl_4_bss_0->unk_8);
    t1 = fn_1_3F8C((u32)&lbl_4_data_2D5C, (u32)fn_4_7DEC, 0, 5);
    p_lbl_4_bss_0->unk_0 = t1;
    p_lbl_4_bss_0->unk_10 = 0;
    fn_1_4A00(1, 15, p_lbl_4_bss_0->unk_8);
}
/* fzgx:end fn_4_80EC */

/* fzgx:begin fn_4_8158 */
#include "types.h"

struct fn_4_8158_lbl_4_bss_0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[0x1];
    u8 unk_D;
    u8 pad_E[0x2];
    u16 unk_10;
};

extern int fn_1_4C10(void);


extern u16 lbl_1_bss_96A;
extern u32 fn_1_4A00(u32, u32, u32);
extern u32 fn_4_0(u32, u32, u32, u32, u32);


extern u8 lbl_4_data_2D24[56];
extern void fn_1_1280(u32);
extern void fn_1_A2D84(u32);

void fn_4_8158(void) {
    struct fn_4_8158_lbl_4_bss_0 *p_lbl_4_bss_0;
    u32 v0;
    u32 t0, t2, t5;

    p_lbl_4_bss_0 = (struct fn_4_8158_lbl_4_bss_0 *)&(*(struct fn_4_8158_lbl_4_bss_0 *)&lbl_4_bss_0);
    if (p_lbl_4_bss_0->unk_10 != 0) {
        t0 = fn_1_4C10();
        if ((s32)t0 == 0) {
            fn_1_1280(1);
            lbl_1_bss_96A = p_lbl_4_bss_0->unk_10;
            p_lbl_4_bss_0->unk_10 = 0;
        }
    } else {
        t2 = fn_4_0(p_lbl_4_bss_0->unk_D, 0, 1, -1, 0);
        p_lbl_4_bss_0->unk_D = t2;
        v0 = *(u16 *)((u8 *)&lbl_1_bss_9F8 + 8);
        if (((v0 >> 9) & 1) != 0) {
            fn_1_A2D84(0xA9010200);
            p_lbl_4_bss_0->unk_10 = 75;
        } else if (((v0 >> 8) & 1) != 0) {
            fn_1_A2D84(0xA9010100);
            p_lbl_4_bss_0->unk_10 = *(s16 *)((u8 *)&lbl_4_data_2D24 + p_lbl_4_bss_0->unk_D * 28);
        } else {
            return;
        }
        fn_1_4A00(0, 15, p_lbl_4_bss_0->unk_8);
    }
}
/* fzgx:end fn_4_8158 */

/* fzgx:begin fn_4_8248 */
extern u32 fn_1_435C(u32);

/* Finalize the pending option state and clear its completion flag. */
void fn_4_8248(void) {
    if (lbl_4_bss_0 != 0) {
        fn_1_435C(lbl_4_bss_8);
        fn_1_426C(lbl_4_bss_0);
        lbl_4_bss_0 = 0;
    }
}
/* fzgx:end fn_4_8248 */

/* fzgx:begin fn_4_869C noprologue */
#include "types.h"

extern struct fn_4_869C_lbl_1_bss_718E0 lbl_1_bss_718E0;
extern struct fn_4_869C_lbl_4_bss_0 lbl_4_bss_0;
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_4A00(u32, u32, u32);
extern u32 lbl_4_data_2D78;
extern void fn_4_82A0(void);

struct fn_4_869C_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x6];
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
    u8 pad_12[0x26E];
    u8 unk_280;
    u8 pad_281[0x1];
    u8 unk_282;
    u8 unk_283;
};
struct fn_4_869C_lbl_1_bss_718E0 {
    u8 pad_0[0x3];
    u8 unk_3;
};

void fn_4_869C(void) {
    struct fn_4_869C_lbl_4_bss_0 *p_lbl_4_bss_0;
    u32 t1;
    p_lbl_4_bss_0 = (struct fn_4_869C_lbl_4_bss_0 *)&lbl_4_bss_0;
    p_lbl_4_bss_0->unk_283 = lbl_1_bss_718E0.unk_3;
    p_lbl_4_bss_0->unk_282 = lbl_1_bss_718E0.unk_3;
    fn_1_435C(p_lbl_4_bss_0->unk_8);
    t1 = fn_1_3F8C((u32)&lbl_4_data_2D78, (u32)fn_4_82A0, 0, 5);
    p_lbl_4_bss_0->unk_0 = t1;
    p_lbl_4_bss_0->unk_280 = 0;
    p_lbl_4_bss_0->unk_10 = 0;
    fn_1_4A00(1, 15, p_lbl_4_bss_0->unk_8);
}
/* fzgx:end fn_4_869C */

/* fzgx:begin fn_4_8720 noprologue */
#include "types.h"

struct fn_4_8720_lbl_4_bss_0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[0x2];
    u8 unk_E;
    u8 pad_F[0x1];
    u16 unk_10;
    u8 pad_12[0xA6];
    u16 unk_B8;
    u8 pad_BA[0x1C6];
    u8 unk_280;
    u8 unk_281;
    u8 unk_282;
    u8 unk_283;
};
struct fn_4_8720_lbl_1_bss_9F8 {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_A[0x6];
    u16 unk_10;
    u16 unk_12;
};
struct fn_4_8720_lbl_1_bss_718E0 {
    u8 pad_0[0x3];
    u8 unk_3;
};

extern struct fn_4_8720_lbl_1_bss_9F8 lbl_1_bss_9F8;
extern struct fn_4_8720_lbl_4_bss_0 lbl_4_bss_0;
extern struct fn_4_8720_lbl_1_bss_718E0 lbl_1_bss_718E0;
extern u16 lbl_1_bss_96A;
extern int fn_1_4C10(void);
extern void fn_1_1280(u32);
extern u32 fn_4_0(u32, u32, u32, u32, u32);
extern void fn_1_A2D84(u32);
extern void fn_1_A6840(u32);
extern u32 fn_1_4A00(u32, u32, u32);

void fn_4_8720(void) {
    struct fn_4_8720_lbl_4_bss_0 *p = &lbl_4_bss_0;
    struct fn_4_8720_lbl_1_bss_9F8 *q;
    u16 v;

    if (p->unk_10 != 0) {
        if (fn_1_4C10() == 0) {
            fn_1_1280(1U);
            lbl_1_bss_96A = p->unk_10;
            p->unk_10 = 0;
        }
    } else if (p->unk_280 != 0) {
        p->unk_281 = fn_4_0(p->unk_281, 0U, 1U, -1U, 1U);
        q = &lbl_1_bss_9F8;
        if ((q->unk_8 >> 9U) & 1) {
            fn_1_A2D84(0xA9010200U);
            p->unk_280 = 0;
        } else if ((q->unk_8 >> 8U) & 1) {
            fn_1_A2D84(0xA9010100U);
            if (p->unk_281 == 0) {
                lbl_1_bss_718E0.unk_3 = p->unk_283;
                p->unk_E = 1;
            } else if (lbl_1_bss_718E0.unk_3 != p->unk_283) {
                fn_1_A6840(lbl_1_bss_718E0.unk_3);
            }
            if (p->unk_E != 0) {
                p->unk_B8 = 0x4B;
                p->unk_10 = 0x4C;
            } else {
                p->unk_10 = 0x4B;
                fn_1_4A00(0U, 0xFU, p->unk_8);
            }
        }
    } else {
        q = &lbl_1_bss_9F8;
        if ((((q->unk_10) & 1) || (lbl_1_bss_9F8.unk_12 & 1)) && p->unk_282 == 1) {
            p->unk_282 = 0;
            fn_1_A2D84(0xA9010000U);
        } else if ((((q->unk_10 >> 1U) & 1) || (lbl_1_bss_9F8.unk_12 >> 1U) & 1) && p->unk_282 == 0) {
            p->unk_282 = 1;
            fn_1_A2D84(0xA9010000U);
        }
        q = &lbl_1_bss_9F8;
        if (((q->unk_8 >> 8U) & 1) && p->unk_282 != p->unk_283) {
            fn_1_A2D84(0xA9010100U);
            fn_1_A6840(p->unk_282);
            p->unk_283 = p->unk_282;
        }
        if ((q->unk_8 >> 9U) & 1) {
            fn_1_A2D84(0xA9010200U);
            if (p->unk_283 != lbl_1_bss_718E0.unk_3) {
                p->unk_280 = 1;
                p->unk_281 = 0;
            } else {
                p->unk_10 = 0x4B;
                fn_1_4A00(0U, 0xFU, p->unk_8);
            }
        }
    }
}
/* fzgx:end fn_4_8720 */

/* fzgx:begin fn_4_898C */
extern u32 fn_1_435C(u32);

/* Reset the option state after releasing its active resource. */
void fn_4_898C(void) {
    if (lbl_4_bss_0 != 0) {
        fn_1_435C(lbl_4_bss_8);
        fn_1_426C(lbl_4_bss_0);
        lbl_4_bss_0 = 0;
    }
}
/* fzgx:end fn_4_898C */

/* fzgx:begin fn_4_89E4 noprologue */
#include "types.h"

extern struct fn_4_89E4_lbl_4_bss_0 lbl_4_bss_0;
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_4A00(u32, u32, u32);
extern u32 fn_4_AB30(void);
extern u32 lbl_4_data_2D8C;
extern void fn_4_AC58(void);

struct fn_4_89E4_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x6];
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
};

void fn_4_89E4(void) {
    struct fn_4_89E4_lbl_4_bss_0 *p_lbl_4_bss_0;
    u32 t2;
    p_lbl_4_bss_0 = (struct fn_4_89E4_lbl_4_bss_0 *)&lbl_4_bss_0;
    fn_4_AB30();
    p_lbl_4_bss_0->unk_10 = 0;
    fn_1_435C(p_lbl_4_bss_0->unk_8);
    t2 = fn_1_3F8C((u32)&lbl_4_data_2D8C, (u32)fn_4_AC58, 0, 5);
    p_lbl_4_bss_0->unk_0 = t2;
    fn_1_4A00(1, 15, p_lbl_4_bss_0->unk_8);
}
/* fzgx:end fn_4_89E4 */

/* fzgx:begin fn_4_8A54 */
extern int fn_1_4C10(void);
extern u16 lbl_1_bss_96A;
extern void fn_1_1280(u32);

extern u32 fn_1_4A00(u32, u32, u32);

/* Advance the option resource state and clear a completed selection. */
void fn_4_8A54(void) {
    u16 value;

    if (lbl_4_bss_10.unk_0 != 0) {
        if (fn_1_4C10() == 0) {
            fn_1_1280(1);
            value = lbl_4_bss_10.unk_0;
            lbl_1_bss_96A = value;
            lbl_4_bss_10.unk_0 = 0;
        }
    } else {
        value = fn_4_ABB0();
        lbl_4_bss_10.unk_0 = value;
        if (value != 0) {
            fn_1_4A00(0, 15, lbl_4_bss_8);
        }
    }
}
/* fzgx:end fn_4_8A54 */

/* fzgx:begin fn_4_8AE0 */
extern u32 fn_1_435C(u32);

// Completes the pending option callback and clears its handle.
void fn_4_8AE0(void) {
    fn_4_AB90();

    if (lbl_4_bss_0 != 0) {
        fn_1_435C(lbl_4_bss_8);
        fn_1_426C(lbl_4_bss_0);
        lbl_4_bss_0 = 0;
    }
}
/* fzgx:end fn_4_8AE0 */

/* fzgx:begin fn_4_8DC0 noprologue */
#include "types.h"

extern struct fn_4_8DC0_lbl_4_bss_0 lbl_4_bss_0;
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_4A00(u32, u32, u32);
extern u32 lbl_4_data_2D9C;
extern void fn_4_8B3C(void);

struct fn_4_8DC0_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x6];
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
    u8 pad_12[0x273];
    u8 unk_285;
    u8 unk_286;
};

void fn_4_8DC0(void) {
    struct fn_4_8DC0_lbl_4_bss_0 *p_lbl_4_bss_0;
    u32 t1;
    p_lbl_4_bss_0 = (struct fn_4_8DC0_lbl_4_bss_0 *)&lbl_4_bss_0;
    p_lbl_4_bss_0->unk_286 = 0;
    p_lbl_4_bss_0->unk_285 = 0;
    fn_1_435C(p_lbl_4_bss_0->unk_8);
    t1 = fn_1_3F8C((u32)&lbl_4_data_2D9C, (u32)fn_4_8B3C, 0, 5);
    p_lbl_4_bss_0->unk_0 = t1;
    p_lbl_4_bss_0->unk_10 = 0;
    fn_1_4A00(1, 15, p_lbl_4_bss_0->unk_8);
}
/* fzgx:end fn_4_8DC0 */

/* fzgx:begin fn_4_9A78 */
extern u32 fn_1_435C(u32);

// Finalizes the pending option callback and clears its handle.
void fn_4_9A78(void) {
    if (lbl_4_bss_0 != 0) {
        fn_1_435C(lbl_4_bss_8);
        fn_1_426C(lbl_4_bss_0);
        lbl_4_bss_0 = 0;
    }
}
/* fzgx:end fn_4_9A78 */

/* fzgx:begin fn_4_9AD0 */
void fn_4_9AD0(void) {
    if (lbl_4_bss_5618 != 0) {
    fn_1_1380F0(*(u32 *)((u8 *)&lbl_4_data_1A4 + (lbl_801A66B4 << 2)));
    fn_1_13ABA8(0);
    }
}
/* fzgx:end fn_4_9AD0 */

/* fzgx:begin fn_4_9B20 noprologue */
#include "types.h"

extern u32 fn_1_B7E98(u32);
extern u32 fn_1_B800C(u32);
extern u32 fn_1_B80F0(u32);
extern u32 fn_1_B8170(u32);
extern u32 lbl_4_data_2DB4;
extern void fn_4_9AD0(void);

struct fn_4_9B20_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x6];
    u32 unk_8;
    u8 pad_C[0x285];
    u8 unk_291;
    u8 pad_292[0x2];
    u8 unk_294;
    u8 pad_295[0x5383];
    u8 unk_5618;
    u8 unk_5619;
    u8 unk_561A;
    u8 unk_561B;
    u32 unk_561C;
    u8 unk_5620;
    u8 unk_5621;
    u8 unk_5622;
};

extern struct fn_4_9B20_lbl_4_bss_0 lbl_4_bss_0;
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_435C(u32);

s32 fn_4_9B20(void) {
    struct fn_4_9B20_lbl_4_bss_0 *p_lbl_4_bss_0;
    u32 v0;
    u32 t1, t2, t3, t4, t5;
    p_lbl_4_bss_0 = (struct fn_4_9B20_lbl_4_bss_0 *)&lbl_4_bss_0;
    fn_1_435C(p_lbl_4_bss_0->unk_8);
    t1 = fn_1_3F8C((u32)&lbl_4_data_2DB4, (u32)fn_4_9AD0, 0, 5);
    p_lbl_4_bss_0->unk_0 = t1;
    p_lbl_4_bss_0->unk_5618 = 1;
    p_lbl_4_bss_0->unk_5619 = 0;
    p_lbl_4_bss_0->unk_561A = 0;
    p_lbl_4_bss_0->unk_561B = 0;
    p_lbl_4_bss_0->unk_294 = 0;
    p_lbl_4_bss_0->unk_561C = 0;
    t2 = fn_1_B7E98(0);
    v0 = t2;
    if ((s32)t2 != 0) {
    v0 = 0;
    v0 = (fn_1_B800C(v0));
    if ((s32)v0 == 0) {
    v0 = 0;
    t4 = fn_1_B8170(v0);
    v0 = t4;
    if ((v0 & 0x2) == 0) {
    v0 = 1;
    p_lbl_4_bss_0->unk_561B = v0;
    p_lbl_4_bss_0->unk_561C = 120;
    p_lbl_4_bss_0->unk_5619 = v0;
    p_lbl_4_bss_0->unk_291 = v0;
    p_lbl_4_bss_0->unk_561A = v0;
    }
    }
    v0 = 0;
    t5 = fn_1_B80F0(v0);
    v0 = t5;
    v0 = 1;
    p_lbl_4_bss_0->unk_5620 = v0;
    p_lbl_4_bss_0->unk_5621 = v0;
    p_lbl_4_bss_0->unk_5622 = 0;
    } else {
    v0 = 0;
    p_lbl_4_bss_0->unk_5620 = v0;
    p_lbl_4_bss_0->unk_5621 = v0;
    p_lbl_4_bss_0->unk_5622 = 120;
    }
    return v0;
}
/* fzgx:end fn_4_9B20 */

/* fzgx:begin fn_4_A734 */
// Finalizes the pending option callback and clears its handle.
void fn_4_A734(void) {
    if (lbl_4_bss_0 != 0) {
        fn_1_435C(lbl_4_bss_8);
        fn_1_426C(lbl_4_bss_0);
        lbl_4_bss_0 = 0;
    }
}
/* fzgx:end fn_4_A734 */

/* fzgx:begin fn_4_A78C */
void fn_4_A78C(u32 arg0) {
    u8 loc_8[32];
    u8 *p;
    u8 *out;

    if (lbl_801A66B4 != 5) {
        fn_80083DB0(loc_8, arg0);
        p = loc_8;
        out = (u8 *)arg0;
        while (*p != 0) {
            if (*p < 0x80) {
                *out = *p;
                p++;
                out++;
            } else {
                u8 *q = fn_4_A82C(p);
                if (q != 0) {
                    *out = *q;
                    out++;
                }
                p += 2;
            }
        }
        *out = 0;
    }
}
/* fzgx:end fn_4_A78C */

/* fzgx:begin fn_4_AB30 */
// Initialize the option state and reset its associated data value.
void fn_4_AB30(void) {
    fn_1_B9BE0();
    fn_1_B9DE8((u32)&lbl_4_bss_5630);
    lbl_4_bss_5630.unk_0 = 4;
    lbl_4_bss_5630.unk_0 |= 0x10;
    lbl_4_bss_5630.unk_0 |= 0x20;
    lbl_4_bss_5630.unk_4 = 0xc;
    lbl_4_data_2F1C = 0;
}
/* fzgx:end fn_4_AB30 */

/* fzgx:begin fn_4_AB90 */
void fn_4_AB90(void) {
    fn_1_B9C0C();
}
/* fzgx:end fn_4_AB90 */

/* fzgx:begin fn_4_AC58 */
extern s32 lbl_801A66B4;
extern u32 fn_1_1380F0(u32);
extern u32 fn_1_B7C00(void);
extern u32 fn_1_13ABA8(u32);

#pragma opt_propagation off
void fn_4_AC58(void) {
    Obj_4_data_2F00 *p = &lbl_4_data_2F00;
    u32 *table = (u32 *)&p->pad_0[0x60];
    fn_1_1380F0(table[lbl_801A66B4]);
    if ((u8)fn_1_B7C00() || (s32)lbl_4_bss_5630.unk_22 == 2) {
        fn_1_13ABA8(0);
    } else {
        fn_1_13ABA8(0x28000000);
    }
    if ((s32)p->unk_18 >= 0) {
        u32 offset = p->unk_18 * 4;
        void (**callbacks)(void) = (void (**)(void))&p->pad_0[0xC];
        (*(void (**)(void))((u8 *)callbacks + offset))();
    }
}
/* fzgx:end fn_4_AC58 */

/* fzgx:begin fn_4_ACF0 */
void fn_4_ACF0(void) {
    u32 v0;
    u32 t0;
    t0 = fn_1_BA144((u32 *)(u32)&lbl_4_bss_5630);
    v0 = t0;
    if ((s8)t0 == 0) {
    lbl_4_data_2F1C = 1;
    } else {
    if ((s8)t0 == 1) {
    lbl_4_bss_5678 = 78;
    }
    }
}
/* fzgx:end fn_4_ACF0 */

/* fzgx:begin fn_4_AD44 */
void fn_4_AD44(void) {
    u32 t0;
    t0 = fn_1_B7C00();
    if ((t0 & 0xFF) == 0) {
    fn_1_BC310(&lbl_4_bss_5630);
    }
}
/* fzgx:end fn_4_AD44 */

/* fzgx:begin fn_4_AD78 */
void fn_4_AD78(void) {
    fn_1_C0510((u32)&lbl_4_bss_5630);
    lbl_4_data_2F1C = 2;
}
/* fzgx:end fn_4_AD78 */

/* fzgx:begin fn_4_ADAC */
// fn_4_ADAC: empty in retail (single blr).
void fn_4_ADAC(void) {
}
/* fzgx:end fn_4_ADAC */

/* fzgx:begin fn_4_ADB0 */
void fn_4_ADB0(void) {
    u32 t0;
    t0 = fn_1_B7C00();
    if ((t0 & 0xFF) == 0) {
    lbl_4_data_2F1C = 0;
    fn_1_C1394(&lbl_4_bss_5630);
    }
}
/* fzgx:end fn_4_ADB0 */

/* fzgx:begin fn_4_ADF0 */
// fn_4_ADF0: empty in retail (single blr).
void fn_4_ADF0(void) {
}
/* fzgx:end fn_4_ADF0 */

/* fzgx:begin fn_4_ADF4 */
#include "font.h"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[360] = {0x89709094, 0x00000000, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x824F8250, 0x82518252, 0x82538254, 0x82558256, 0x82578258, 0x81E781E8, 0x00000000, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x00000000, 0x8B4C8D86, 0x00000000, 0x81418142, 0x814C814D, 0x81458143, 0x81448146, 0x81478148, 0x8149817B, 0x817C815E, 0x81818183, 0x8184814F, 0x81518160, 0x81628175, 0x81768169, 0x816A816F, 0x8170816D, 0x816E818F, 0x81908193, 0x81948195, 0x81968197, 0x81E781E8, 0x00000000, 0x82D082E7, 0x82AA82C8, 0x00000000, 0x82A082A2, 0x82A482A6, 0x82A882A9, 0x82AB82AD, 0x82AF82B1, 0x82B382B5, 0x82B782B9, 0x82BB82BD, 0x82BF82C2, 0x82C482C6, 0x82C882C9, 0x82CA82CB, 0x82CC82CD, 0x82D082D3, 0x82D682D9, 0x82DC82DD, 0x82DE82DF, 0x82E082E2, 0x82E482E6, 0x82E782E8, 0x82E982EA, 0x82EB82ED, 0x82EE82EF, 0x82F082F1, 0x82AA82AC, 0x82AE82B0, 0x82B282B4, 0x82B682B8, 0x82BA82BC, 0x82BE82C0, 0x82C382C5, 0x82C782CE, 0x82D182D4, 0x82D782DA, 0x82CF82D2, 0x82D582D8, 0x82DB829F, 0x82A182A3, 0x82A582A7, 0x82C182E1, 0x82E382E5, 0x82EC81E7, 0x81E80000, 0x829F82A1, 0x82A382A5, 0x82A782AA, 0x82AC82AE, 0x82B082B2, 0x82B482B6, 0x82B882BA, 0x82BC82BE, 0x82C082C1, 0x82C582C7, 0x81408140, 0x81408140, 0x814082CE, 0x82D182D4, 0x82D782DA, 0x81408140, 0x81408140, 0x814082E1, 0x82E382E5, 0x81408140, 0x81408140, 0x814082EC, 0x81408140, 0x81408140, 0x82A982AB, 0x82AD82AF, 0x82B182B3, 0x82B582B7, 0x82B982BB, 0x82BD82BF, 0x82C282C4, 0x82C682CF, 0x82D282D5, 0x82D882DB, 0x82CD82D0, 0x82D382D6, 0x82D982A0, 0x82A282A4, 0x82A682A8, 0x82C282E2, 0x82E482E6, 0x82ED8140, 0x81400000, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x814082C3, 0x81408140, 0x81408140, 0x81408140, 0x814082CF, 0x82D282D5, 0x82D882DB, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x82C18140, 0x814082CD, 0x82D082D3, 0x82D682D9, 0x82CE82D1, 0x82D482D7, 0x82DA8140, 0x81408140, 0x81408140, 0x82C38140, 0x81408140, 0x81408140, 0x81400000, 0x834A835E, 0x834A8369, 0x00000000, 0x83418343, 0x83458347, 0x8349834A, 0x834C834E, 0x83508352, 0x83548356, 0x8358835A, 0x835C835E, 0x83608363, 0x83658367, 0x8369836A, 0x836B836C, 0x836D836E, 0x83718374, 0x82D6837A, 0x837D837E, 0x83808381, 0x83828384, 0x83868388, 0x8389838A, 0x838B838C, 0x838D838F, 0x83908391, 0x83928393, 0x8394834B, 0x834D834F, 0x83518353, 0x83558357, 0x8359835B, 0x835D835F, 0x83618364, 0x83668368, 0x836F8372, 0x837582D7, 0x837B8370, 0x83738376, 0x82D8837C, 0x83408342, 0x83448346, 0x83488395, 0x83968362, 0x83838385, 0x8387838E, 0x81E781E8, 0x00000000, 0x83408342, 0x83448346, 0x8348834B, 0x834D834F, 0x83518353, 0x83558357, 0x8359835B, 0x835D835F, 0x83618362, 0x83668368, 0x81408140, 0x81408140, 0x8140836F, 0x83728375, 0x82D7837B, 0x81408140, 0x81408140, 0x81408383, 0x83858387, 0x81408140, 0x81408140, 0x8140838E, 0x81408140, 0x81408140, 0x8345834A, 0x834C834E, 0x83508352, 0x83548356, 0x8358835A, 0x835C835E, 0x83608363, 0x83658367, 0x83708373, 0x837682D8, 0x837C836E, 0x83718374, 0x82D6837A, 0x83418343, 0x83458347, 0x8349834A, 0x83508363, 0x83848386, 0x8388838F, 0x81408140, 0x00000000, 0x81408140, 0x83948140, 0x81408395, 0x81408140, 0x83968140, 0x81408140, 0x81408140, 0x81408140, 0x81408364, 0x81408140, 0x81408140, 0x81408140, 0x81408370, 0x83738376, 0x82D8837C, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x83448395, 0x81408140, 0x83968140, 0x81408140, 0x81408140, 0x81408140, 0x81408362, 0x81408140, 0x836E8371, 0x837482D6, 0x837A836F, 0x83728375, 0x82D7837B, 0x81408140, 0x83948140, 0x8140834B, 0x83518364, 0x81408140, 0x81408140, 0x81408140, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 225.43910217285156f;
}
static const u32 fzgx_pool_table3[65] = {0x74616C20, 0x4C657474, 0x65727300, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x81E781E8, 0x00000000, 0x536D616C, 0x6C204C65, 0x74746572, 0x73000000, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x81E781E8, 0x00000000, 0x5369676E, 0x73000000, 0x81438144, 0x81488149, 0x817B817C, 0x815E815F, 0x81818183, 0x81848146, 0x8147814C, 0x814D814F, 0x81518162, 0x8169816A, 0x816D816E, 0x816F8170, 0x81908193, 0x81948195, 0x81968197, 0x81E781E8, 0x00000000, 0x4E756D62, 0x65727300, 0x824F8250, 0x82518252, 0x82538254, 0x82558256, 0x82578258, 0x81E781E8, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.21;
    d = 1.6666666666666667;
    d = 0.5;
    s = 48.0f;
    s = 0.25f;
    d = 1.0;
    s = 0.12999999523162842f;
    s = 0.0f;
    d = 1.5;
    d = 2.0;
    s = 1.6666666269302368f;
    s = 0.0625f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"
struct fn_8_D630_rodata {
u8 pad_0[0x6A8];
f64 unk_6A8;
f64 unk_6B0;
f64 unk_6B8;
f32 unk_6C0;
f32 unk_6C4;
f64 unk_6C8;
f32 unk_6D0;
u8 pad_6D4[0x4];
f64 unk_6D8;
f64 unk_6E0;
f32 unk_6E8;
f32 unk_6EC;
f64 unk_6F0;
f64 unk_6F8;
};
struct fn_8_D630_550 {
u32 unk_0;
};
#pragma pack(1)
struct fn_8_D630_obj {
u8 unk_0;
u8 unk_1;
u8 unk_2;
u8 unk_3;
u16 unk_4;
u16 unk_6;
u16 unk_8;
u16 unk_A;
u8 unk_C;
u32 unk_D;
};
#pragma pack()

extern struct fn_8_D630_rodata lbl_4_rodata_410;
extern u8 lbl_4_data_2F78[];
extern u32 lbl_1_rodata_26F8;
extern u32 lbl_801A6410;
extern u8 lbl_4_bss_5684;
extern void fn_1_46B4(u32, u32, const char *, int);
extern u32 fn_1_4060(void);
extern s32 strncmp(const char *, const char *, size_t);
extern char * strncpy(char *, const char *, size_t);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_495C8(u8);
extern void fn_1_49514(u32 *);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_A2D84(u32);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_4A0D8(const char *);
#pragma pool_data on
#pragma fp_contract off
#pragma opt_common_subs off
static inline f64 fn_10_2325C_read_pointer(struct fn_8_D630_rodata * owner) { return owner->unk_6B0; }
static inline s32 fn_4_ADF4_sign(s32 x) { return x < 0 ? -1 : x > 0; }
static inline u8 fn_4_ADF4_blend(u8 c, f32 f) {
    f32 delta = (f32)(255 - c) * f;
    return (s32)((f32)c + delta);
}
void fn_4_ADF4(struct fn_8_D630_obj *arg0)
{
struct fn_8_D630_obj *p;
struct fn_8_D630_rodata *r;
u8 *d;
u8 name[4];
u8 ph[4];
u32 col1;
u32 col2;
u32 col3;
u32 col4;
FontDrawPacket loc_20;
f32 f;
f32 scale;
u32 t;
u32 n2;
s32 e;
p = arg0;
r = &lbl_4_rodata_410;
d = lbl_4_data_2F78;
if (lbl_4_bss_5684 != 0) {
fn_1_46B4(lbl_801A6410, (u32)p, (const char *)(d + 0xA0), 0xFB);
fn_1_4060();
return;
}
n2 = (p->unk_C + 1) & 0x1F;
t = lbl_4_bss_5680->unk_20;
if (__rlwnm(t, n2, 31, 31) != 0) {
if (p->unk_0 != 1 || p->unk_1 != 0x18) {
p->unk_0 = 4;
p->unk_1 = 0x10;
lbl_4_bss_5680->unk_20 &= ~(0x80000000U >> p->unk_C);
if (strncmp((const char *)p + 2, (const char *)(d + 0xB0), 2) == 0) {
strncpy((char *)p + 2, (const char *)(d + 0xB4), 2);
name[0] = p->unk_2;
name[1] = p->unk_3;
}
}
}
name[0] = p->unk_2;
name[1] = p->unk_3;
name[2] = 0;
fn_1_49410();
fn_1_494DC(0x2A);
fn_1_495C8(9);
switch (p->unk_0) {
case 1:
{
u16 c4 = p->unk_4;
s32 t4 = (s32)p->unk_8 - (s32)c4;
f64 dd = 0.21 * (f64)t4;
if ((s32)dd != 0) {
p->unk_4 = (u16)(s32)((f64)(u32)c4 + dd);
} else {
e = fn_4_ADF4_sign(t4);
/* Retail rereads the position after selecting the one-step adjustment. */
p->unk_4 = *(volatile u16 *)&p->unk_4 + e;
}
{
u16 c6 = p->unk_6;
s32 t6 = (s32)p->unk_A - (s32)c6;
dd = 0.21 * (f64)t6;
if ((s32)dd != 0) {
p->unk_6 = (u16)(s32)((f64)(u32)c6 + dd);
} else {
e = fn_4_ADF4_sign(t6);
/* Retail rereads the position after selecting the one-step adjustment. */
p->unk_6 = *(volatile u16 *)&p->unk_6 + e;
}
}
}
col1 = p->unk_D;
fn_1_49514(&col1);
fn_1_496FC((f32)p->unk_4, (f32)p->unk_6);
{
f64 scale_d = 1.6666666666666667 * (0.5 + (f32)(0x18 - p->unk_1) / 48.0f);
fn_1_4955C(scale_d, scale_d);
}
if (p->unk_1 == 1) {
p->unk_0 = 2;
p->unk_4 = p->unk_8;
p->unk_6 = p->unk_A;
}
break;
case 2:
if (p->unk_1 == 0) {
p->unk_1 = 4;
fn_1_A2D84(0xA9010100);
}
*(u32 *)ph = p->unk_D;
{
f32 quarter = 0.25f;
f = (f32)p->unk_1 * quarter;
{
ph[0] += (255 - ph[0]) * f;
ph[1] += (255 - ph[1]) * f;
ph[2] += (255 - ph[2]) * f;
}
}
col2 = *(u32 *)ph;
fn_1_49514(&col2);
fn_1_496FC((f32)p->unk_4, (f32)p->unk_6);
{
f64 scale_d = 1.6666666666666667 * (1.0 + 0.5 * (f64)f);
fn_1_4955C(scale_d, scale_d);
}
loc_20 = *(FontDrawPacket *)(&lbl_1_rodata_26F8);
loc_20.image = 0x8F09;
loc_20.x = (f32)p->unk_4;
loc_20.y = (f32)p->unk_6;
loc_20.z = 0.13f;
loc_20.scale_x = loc_20.scale_y = (1.5 + 2.0 * (f64)f);
loc_20.flags = 0xA;
fn_1_4F734((FontDrawPacket *)&loc_20);
if (p->unk_1 == 1) {
p->unk_0 = 3;
if (strncmp((const char *)p + 2, (const char *)(d + 0xB4), 2) == 0) {
strncpy((char *)p + 2, (const char *)(d + 0xB0), 2);
name[0] = p->unk_2;
name[1] = p->unk_3;
}
}
break;
case 3:
col3 = p->unk_D;
fn_1_49514(&col3);
fn_1_496FC((f32)p->unk_4, (f32)p->unk_6);
fn_1_4955C(1.6666666f, 1.6666666f);
break;
case 4:
if (p->unk_1 == 0) {
fn_1_46B4(lbl_801A6410, (u32)p, (const char *)(d + 0xA0), 0x169);
fn_1_4060();
return;
}
col4 = p->unk_D;
fn_1_49514(&col4);
fn_1_496FC((f32)p->unk_4, (f32)p->unk_6);
{
f64 scale_d = 1.6666666666666667 * (1.0 + 0.5 * (f32)(0x10 - p->unk_1));
fn_1_4955C(scale_d, scale_d);
}
{
f32 alpha = (f32)p->unk_1;
alpha *= 0.0625f;
fn_1_495A0(alpha);
}
break;
}
fn_1_4A0D8((const char *)name);
p->unk_1--;
}
#pragma opt_common_subs reset
/* fzgx:end fn_4_ADF4 */
