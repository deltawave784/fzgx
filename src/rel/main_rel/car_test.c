#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/car_test.h"
#include "game/main_rel/car_test_types.h"

extern void fn_1_3EF14(void *arg1);
extern s32 fn_1_58C4(void);
extern s16 fn_1_7B054(void);
extern s16 fn_1_3F0C8(void);
extern s32 fn_1_3FC18(void);
extern s32 fn_1_54E34(void *arg0, f32 arg1);
extern f32 fn_1_A71AC(void);
extern s32 camera_get_values(f32 *value0, f32 *value1);
extern s32 fn_1_A5DC4(void);
extern u8 lbl_1_bss_6D980[32];
extern u8 lbl_1_bss_6D9A0[188];
extern void fn_1_5634C(u8 value);
extern void fn_1_7ECB8(u32 arg0, u32 arg1, u32 arg2);
extern void *lbl_801A6410;
extern const f64 lbl_1_rodata_3588;
extern void fn_1_12AB38(void *arg0);
extern s32 fn_1_45D0();
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_1_80F80(void *, u8, void *);
extern void fn_1_1502BC(void *, void *, void *);
extern char *fn_80083DB0(char *dst, const char *src);
extern void fn_1_801F8(s16 arg0, void *arg1);
extern const f32 lbl_1_rodata_33AC;
extern u32 fn_1_4630();
extern const f32 lbl_1_rodata_33B0[84];
extern void *memset(void *dst, int value, u32 size);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_1_7F954(u32 arg0, u32 arg1);
extern void fn_1_49614(void);
extern const f32 lbl_1_rodata_33A8;
extern void fn_80071ED4(f32 arg0, f32 arg1, s32 arg2);
extern void fn_80072014(void *arg0);
extern void fn_800720B0(s32 arg0);
extern const f32 lbl_1_rodata_3500;
extern const f32 lbl_1_rodata_3504;

/* fzgx:begin fn_1_7C13C */
typedef struct {
    u8 pad_32c[0x32c];
    void *field_32c;
    u8 pad_330[0x110];
} Fn17C13CEntry;

typedef struct {
    u8 pad_4[4];
    u16 field_4;
    u16 field_6;
    u8 pad_8[0x17c];
    f32 field_184;
} Fn17C13CObject;

void fn_1_7C13C(Fn17C13CEntry *arg0) {
    f32 value;
    Fn17C13CEntry *p;
    int i;

    value = 100.0f;
    p = arg0;
    for (i = 0; i < 0x29; i++) {
        p->field_32c = (void *)fn_1_4630((*(u8 * *)&lbl_801A6410), 0x620, (*(u8 (*)[128])&lbl_1_data_1EF5C), 0x58);
        ((Fn17C13CObject *)p->field_32c)->field_6 = (u16)i;
        ((Fn17C13CObject *)p->field_32c)->field_4 = (u16)i;
        ((Fn17C13CObject *)p->field_32c)->field_184 = value;
        p++;
    }
}
/* fzgx:end fn_1_7C13C */

/* fzgx:begin fn_1_7C1E8 */
void fn_1_7C1E8(void *out) {
    u8 *p;
    s8 i;

    p = (u8 *)out;
    for (i = 0; i < 2; i++) {
        *(u32 *)p = (u32)fn_1_4630(lbl_801A6410, 4, (*(u8 (*)[128])&lbl_1_data_1EF5C), 0x68);
        memset(*(void **)p, 0xff, 4);
        *(f32 *)(p + 4) = lbl_1_rodata_33B0[0];
        *(u16 *)(p + 8) = 0xE000;
        *(s16 *)(p + 10) = 0x2000;
        p += 0xc;
    }
}
/* fzgx:end fn_1_7C1E8 */

/* fzgx:begin fn_1_7C2A0 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} CtVec3;

typedef struct {
    CtVec3 from;
    CtVec3 to;
} CtAxis;

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} CtColor;

typedef struct {
    u8 pad_0[4];
    s16 id;
    u8 pad_6[0x76];
    CtVec3 pos;
    u8 pad_88[0xc4];
    u8 mtx[0x30];
} CtBody;

typedef struct {
    u32 unk_0;
    u8 *name;
} CtPart;

typedef struct {
    u32 count;
    u8 pad_4[4];
    CtPart *parts;
} CtPartList;

typedef struct {
    void **models;
    CtPartList *info;
    u8 pad_8[4];
} CtSlot;

typedef struct {
    u8 pad_0[2];
    s8 max_parts;
    u8 pad_3[0x329];
    CtBody *body;
    u8 *mtxs;
    CtSlot slots[4];
    u8 pad_364[0x56];
    s16 sel;
} CtCar;

typedef struct {
    u8 pad_0[6];
    u8 mode;
    s8 player;
    s8 part;
    u8 pad_9[3];
    u32 *masks;
    u8 pad_10[0xc];
    CtColor **color;
    union {
        u32 flags;
        struct {
            u32 hide : 1;
            u32 skip : 1;
            u32 rest : 30;
        } bits;
    };
    s8 sel;
} CtState;

#define CT_STATE (*(CtState **)&lbl_1_bss_6D7E8)

/* retail literal pool order of car_test.c ahead of this function */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sink */
    s = 1.0f;
    s = 100.0f;
    s = 17.320507049560546875f;
}
#pragma section code_type ".text"

extern u32 lbl_801A66A0;
extern void fn_1_57714(u8);
extern void fn_1_5773C(CtVec3 *, CtVec3 *, CtColor *);
extern void fn_1_A77DC(CtCar *);
extern void fn_1_A7854(CtCar *, void *);
extern void fn_1_3BDC(s32);
extern void fn_1_87610(CtCar *, CtCar *);
extern void fn_1_55210(void *);
extern void fn_1_87238(CtCar *, s8, f32);
extern s32 fn_1_3C18(s32);
extern void fn_1_A8EF8(u16, u16);
extern void fn_1_A8DD4(const char *, ...);
extern void lbl_8006DAEC(void);
extern void lbl_8006DCA4(void);
extern void fn_80008BEC(void *, int, u32);
extern void fn_80072558(void);
extern void lbl_8006E0A4(CtVec3 *);
extern void mathutil_mtxA_rotate_y(s32);
extern void fn_80074D68(f32, f32, f32);
extern void fn_80074D78(u32);
extern void lbl_8006D7DC(CtVec3 *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DB30(void);
extern u8 *fn_80083970(u8 *, const u8 *);
extern void lbl_8006DBE4(void);
extern void lbl_8006DFC4(void *);

void fn_1_7C2A0(CtCar *car) {
    s8 count;
    s16 i;
    s16 n;
    s8 id;
    CtColor *c;

    if (CT_STATE->flags & 0x40000000) {
        return;
    }
    count = (s8)car->slots[CT_STATE->sel].info->count;
    if (car->body->id != CT_STATE->player && (s32)CT_STATE->mode != 5) {
        return;
    }

    lbl_8006DAEC();
    lbl_8006DCA4();
    {
    CtAxis ax;
    CtAxis ay;
    CtAxis az;
    CtColor cx = {0x00, 0xff, 0x00, 0xff};
    CtColor cy = {0x00, 0xff, 0x00, 0xff};
    CtColor cz = {0x00, 0xff, 0x00, 0xff};
    fn_80008BEC(&ax, 0, sizeof(CtAxis));
    fn_80008BEC(&ay, 0, sizeof(CtAxis));
    fn_80008BEC(&az, 0, sizeof(CtAxis));
    ax.from.x = -100.0f;
    ax.to.x = 100.0f;
    ay.from.y = -100.0f;
    ay.to.y = 100.0f;
    az.from.z = -100.0f;
    az.to.z = 100.0f;
    fn_1_57714(2);
    fn_80072558();
    fn_1_5773C(&ax.from, &ax.to, &cx);
    fn_1_5773C(&ay.from, &ay.to, &cy);
    fn_1_5773C(&az.from, &az.to, &cz);
    }

    if ((s32)CT_STATE->mode == 5) {
        id = (s8)car->body->id;
        car->body->pos.x = 3.0f - (f32)(6.0f * (f32)(id % 2));
        car->body->pos.z = -3.0f + (f32)(6.0f * (f32)(id / 2));
    }
    lbl_8006E0A4(&car->body->pos);
    if ((s32)CT_STATE->mode == 5) {
        mathutil_mtxA_rotate_y((s32)(182.04444885253906f * (f32)(lbl_801A66A0 % 360)));
    }
    c = *CT_STATE->color;
    fn_80074D68(c->r / 255.0f, c->g / 255.0f, c->b / 255.0f);
    fn_80074D78(!(CT_STATE->flags & 0x80000000));
    lbl_8006DAEC();
    lbl_8006D7DC(&car->body->pos);
    lbl_8006DB74(car->body->mtx);
    fn_1_A77DC(car);
    fn_1_A7854(car, 0);
    lbl_8006DB30();
    car->sel = CT_STATE->sel;
    fn_1_3BDC(3);

    if (CT_STATE->part == count) {
        for (i = 0, n = 0; i < count; i++) {
            if (!((1 << i) & CT_STATE->masks[CT_STATE->player])) {
                continue;
            }
            if (i == 0) {
                continue;
            }
            if (n > car->max_parts - 1) {
                break;
            }
            if (fn_80083970(car->slots[CT_STATE->sel].info->parts[i].name, (const u8 *)&lbl_1_data_1EFDC) ==
                car->slots[CT_STATE->sel].info->parts[i].name) {
                continue;
            }
            if (car->slots[CT_STATE->sel].models[i] == NULL) {
                n++;
                continue;
            }
            lbl_8006DAEC();
            if (car->mtxs != NULL) {
                fn_1_87610(car, car);
                lbl_8006DBE4();
                lbl_8006DFC4(((f32 (*)[3][4])car->mtxs)[n]);
                fn_80072558();
                fn_1_55210(car->slots[CT_STATE->sel].models[i]);
            }
            lbl_8006DB30();
            n++;
        }
        fn_80072558();
        fn_1_87238(car, CT_STATE->sel, 1.0f);
    } else {
        fn_80072558();
        fn_1_55210(car->slots[CT_STATE->sel].models[CT_STATE->part]);
    }
    n = fn_1_3C18(3);
    fn_1_A8EF8(0x140, 0x190);
    fn_1_A8DD4((const char *)&lbl_1_data_1EFE4, n);
    lbl_8006DB30();
}
/* fzgx:end fn_1_7C2A0 */

/* fzgx:begin fn_1_7D694 */
typedef struct {
    u8 _pad4[4];
    s16 value;
} Entry;

typedef struct {
    u8 _pad32c[0x32c];
    Entry *entry;
} Object;

typedef struct {
    u8 _pad7[7];
    s8 value;
} GlobalEntry;

// Compares the object's entry selector with the active global selector.
void fn_1_7D694(Object *obj) {
    Entry *entry = obj->entry;
    GlobalEntry *active = *(GlobalEntry **)&lbl_1_bss_6D7E8;

    if (entry->value == active->value) {
        return;
    }
}
/* fzgx:end fn_1_7D694 */

/* fzgx:begin fn_1_7D6B8 */
typedef struct {
    void *info;                 /* -> Fn1_7D6B8Info * */
    s32 *count;
    u32 unk_8;
} Fn1_7D6B8Slot;                /* 0xC */

typedef struct {
    u8 pad_0[0x334];
    Fn1_7D6B8Slot slots[0x16];
    u8 pad_43C[0x440 - 0x43C];
} Fn1_7D6B8Block;               /* 0x440 */

typedef struct {
    u8 *value;
} Fn1_7D6B8ColorContainer;

typedef struct {
    void *base;
    u8 field_4;
    u8 field_5;
    u8 field_6;
    u8 field_7;
    u8 field_8;
    u8 pad_9[0x13];
    Fn1_7D6B8ColorContainer *unk_1c;
    u32 field_20;
    u8 field_24;
} Fn1_7D6B8Arg;

typedef struct {
    u8 pad_18[0x18];
    u16 unk_18;
} Fn1_7D6B8Info;

/* Halfword fields not yet named in car_test.h. */
#define INPUT_14 (*(u16 *)&lbl_1_bss_9F8.pad_14[0])
#define INPUT_24 (*(u16 *)&lbl_1_bss_9F8.pad_14[0x10])
#define INPUT_26 (*(u16 *)&lbl_1_bss_9F8.pad_14[0x12])
extern void * memset(void *, int, u32);
extern u8 fn_1_816E8(void *, u8);
extern u32 fn_800793D4(u8 *, u32, u32);

/* saturate a u8 channel at 0xFF after a signed step */
#define CLAMP_U8(x) (((x) > 0xFFU) ? 0xFF : (x))

#pragma opt_dead_assignments off
#pragma opt_pointer_analysis off
#pragma opt_propagation off
void fn_1_7D6B8(void *arg0) {
    s32 *temp_r3_2;
    Fn1_7D6B8Block *block_entry;
    Fn1_7D6B8Block *block_entry2;
    s32 temp_r0_2;
    s32 temp_r3_4;
    s32 temp_r4;
    s32 shift_idx;
    struct { s32 value; } temp_r5;
    s32 temp_r8;
    s8 temp_r10;
    struct { s32 value; } var_r0;
    s32 var_r6_2;
    s8 var_r4;
    s8 var_r4_2;
    s8 var_r5;
    s8 var_r6;
    u8 *temp_r3_14;
    u8 *temp_r3_15;
    u8 *temp_r3_16;
    u8 *temp_r3_6;
    u8 *temp_r3_7;
    u8 *temp_r3_8;
    u8 *temp_r4_19;
    u8 *temp_r4_21;
    u8 *temp_r4_23;
    u8 *temp_r4_25;
    u8 *temp_r4_3;
    u8 *temp_r4_5;
    u8 *temp_r4_7;
    u8 *temp_r4_9;
    void *temp_r3_10;
    void *temp_r3_11;
    void *temp_r3_12;
    u8 temp_r0;
    u8 temp_r0_3;
    u8 temp_r0_4;
    u8 temp_r0_5;
    u8 temp_r3;
    u8 temp_r3_13;
    u8 temp_r3_5;
    u8 temp_r3_9;
    u8 temp_r4_10;
    u8 temp_r4_14;
    u8 temp_r4_16;
    u8 temp_r4_18;
    u8 temp_r4_22;
    u8 temp_r4_24;
    u8 temp_r4_26;
    u8 temp_r4_2;
    u8 temp_r4_6;
    u8 temp_r4_8;
    u8 *temp_r4_20;
    u8 *temp_r4_4;
    void *temp_r3_3;
    void *temp_r4_11;
    void *temp_r4_12;
    void *temp_r4_13;
    void *temp_r4_15;
    void *temp_r4_17;
    void *temp_r9;

    var_r5 = 0;
    var_r6 = 0;
    var_r4 = 0;
    if (!((*(s32 *)((u8 *)(lbl_1_bss_6D7E8) + 32)) & 0x40000000)) {
        temp_r0 = *(u8 *)((u8 *)(arg0) + 6);
        switch ((s8) temp_r0) {                     /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            if ((((u16) (*(u16 volatile *)&(lbl_1_bss_9F8.unk_10)) /* Retail reloads this field. */ >> 3U) & 1) || (((u16) lbl_1_bss_9F8.unk_12 >> 3U) & 1)) {
                var_r4 = -1;
            }
            if ((((u16) (*(u16 volatile *)&(lbl_1_bss_9F8.unk_10)) /* Retail reloads this field. */ >> 2U) & 1) || (((u16) lbl_1_bss_9F8.unk_12 >> 2U) & 1)) {
                var_r4 += 1;
            }
            (*(u8 *)((u8 *)(arg0) + 4)) = (u8) ((*(u8 *)((u8 *)(arg0) + 4)) + var_r4);
            if ((s8) (*(u8 *)((u8 *)(arg0) + 4)) < 1) {
                (*(u8 *)((u8 *)(arg0) + 4)) = 4U;
            }
            if ((s8) (*(u8 *)((u8 *)(arg0) + 4)) > 4) {
                (*(u8 *)((u8 *)(arg0) + 4)) = 1U;
            }
            if (((u16) lbl_1_bss_9F8.unk_8 >> 8U) & 1) {
                (*(u8 *)((u8 *)(arg0) + 6)) = (u8) (*(u8 *)((u8 *)(arg0) + 4));
                return;
            }
            break;
        case 1:                                     /* switch 1 */
            if (((*(u16 volatile *)&(lbl_1_bss_9F8.unk_10)) /* Retail reloads this field. */ & 1) || (lbl_1_bss_9F8.unk_12 & 1)) {
                var_r4 = -1;
            }
            if ((((u16) (*(u16 volatile *)&(lbl_1_bss_9F8.unk_10)) /* Retail reloads this field. */ >> 1U) & 1) || (((u16) lbl_1_bss_9F8.unk_12 >> 1U) & 1)) {
                var_r4 += 1;
            }
            (*(u8 *)((u8 *)(arg0) + 7)) = (u8) ((*(u8 *)((u8 *)(arg0) + 7)) + var_r4);
            if ((s8) (*(u8 *)((u8 *)(arg0) + 7)) < 0) {
                (*(u8 *)((u8 *)(arg0) + 7)) = 0x28U;
            }
            if ((s8) (*(u8 *)((u8 *)(arg0) + 7)) > 0x28) {
                (*(u8 *)((u8 *)(arg0) + 7)) = 0U;
            }
            block_entry = &((Fn1_7D6B8Block *)(*(void **)arg0))[(s8) *(u8 *)((u8 *)arg0 + 7)];
            temp_r0_2 = (s8) *block_entry->slots[(s8) *(u8 *)((u8 *)arg0 + 36)].count;
            if (((u16) INPUT_14 >> 0xBU) & 1) {
                if (((u16) (*(u16 volatile *)&(INPUT_26)) /* Retail reloads this field. */ >> 3U) & 1) {
                    var_r6 = -1;
                }
                if (((u16) INPUT_26 >> 2U) & 1) {
                    var_r6 += 1;
                }
                block_entry2 = &((Fn1_7D6B8Block *)(*(u32 *)arg0))[*(s8 *)((u8 *)arg0 + 7)];
                temp_r10 = *(s8 *)((u8 *)(arg0) + 36);
                temp_r8 = (s8) (*(Fn1_7D6B8Info **)block_entry2->slots[temp_r10].info)->unk_18;
                if (var_r6 != 0) {
                    temp_r9 = (void *)((u8 *)(arg0) + temp_r10);
                    temp_r8 -= 1;
                    var_r6_2 = (s8) (*(u8 *)((u8 *)(temp_r9) + 37)) + var_r6;
                    if (var_r6_2 > temp_r8) {
                        var_r6_2 = 0;
                    } else if (var_r6_2 < 0) {
                        var_r6_2 = temp_r8;
                    }
                    (*(u8 *)((u8 *)(temp_r9) + 37)) = (u8) var_r6_2;
                }
            }
            if ((((u16) (*(u16 volatile *)&(lbl_1_bss_9F8.unk_10)) /* Retail reloads this field. */ >> 3U) & 1) || (((u16) lbl_1_bss_9F8.unk_12 >> 3U) & 1)) {
                var_r5 = -1;
            }
            if ((((u16) (*(u16 volatile *)&(lbl_1_bss_9F8.unk_10)) /* Retail reloads this field. */ >> 2U) & 1) || (((u16) lbl_1_bss_9F8.unk_12 >> 2U) & 1)) {
                var_r5 += 1;
            }
            (*(u8 *)((u8 *)(arg0) + 8)) = (u8) ((*(u8 *)((u8 *)(arg0) + 8)) + var_r5);
            if ((s8) (*(u8 *)((u8 *)(arg0) + 8)) < 0) {
                (*(u8 *)((u8 *)(arg0) + 8)) = (u8) (s8) temp_r0_2;
            }
            if ((s8) (*(u8 *)((u8 *)(arg0) + 8)) > (s8) temp_r0_2) {
                (*(u8 *)((u8 *)(arg0) + 8)) = 0U;
            }
            if (var_r4 != 0) {
                (*(u8 *)((u8 *)(arg0) + 8)) = (u8) (s8) temp_r0_2;
                (*(s8 *)((u8 *)(arg0) + 37)) = 0;
                (*(s8 *)((u8 *)(arg0) + 38)) = 0;
                (*(s8 *)((u8 *)(arg0) + 39)) = 0;
                (*(s8 *)((u8 *)(arg0) + 40)) = 0;
                (*(s8 *)((u8 *)(arg0) + 41)) = 0;
            }
            temp_r3 = *(u8 *)((u8 *)(arg0) + 8);
            shift_idx = (s8) temp_r3;
            if ((shift_idx != (s8) temp_r0_2) && (((u16) lbl_1_bss_9F8.unk_8 >> 0xBU) & 1)) {
                temp_r5.value = *(s32 *)((u8 *)(arg0) + 12);
                temp_r4 = (s8) (*(u8 *)((u8 *)(arg0) + 7)) * 4;
                (*(s32 *)((u8 *)((temp_r5.value + temp_r4)) + 0)) ^= (1 << shift_idx);
            }
            if (((u16) lbl_1_bss_9F8.unk_8 >> 0xAU) & 1) {
                temp_r3_2 = (s32 *)((*(s32 *)((u8 *)(arg0) + 12)) + ((s8) (*(u8 *)((u8 *)(arg0) + 7)) * 4));
                if ((*(s32 *)((u8 *)(temp_r3_2) + 0)) & 0x80000000) {
                    memset((void *)(temp_r3_2), (s32)(0), (u32)(4U));
                } else {
                    memset((void *)(temp_r3_2), (s32)(-1), (u32)(4U));
                }
            }
            if (((u16) lbl_1_bss_9F8.unk_8 >> 8U) & 1) {
                (*(u8 *)((u8 *)(arg0) + 6)) = 2U;
            }
            if (((u16) lbl_1_bss_9F8.unk_8 >> 9U) & 1) {
                (*(u8 *)((u8 *)(arg0) + 6)) = 0U;
                (*(u8 *)((u8 *)(arg0) + 5)) = 0U;
            }
            if (((u16) (*(u16 *)((u8 *)(&lbl_1_bss_9F8) + 28)) >> 4U) & 1) {
                (*(s32 *)((u8 *)(arg0) + 32)) = (s32) ((*(s32 *)((u8 *)(arg0) + 32)) ^ 0x80000000);
            }
            var_r4_2 = 0;
            if (((u16) INPUT_14 >> 0xBU) & 1) {
                if (((u16) INPUT_26 >> 1U) & 1) {
                    var_r4_2 = 1;
                } else if (INPUT_26 & 1) {
                    var_r4_2 = -1;
                }
            } else if ((((u16) lbl_1_bss_9F8.unk_12 >> 6U) & 1) || (((u16) lbl_1_bss_9F8.unk_12 >> 5U) & 1)) {
                var_r4_2 = 1;
            } else if ((((u16) lbl_1_bss_9F8.unk_12 >> 7U) & 1) || (((u16) lbl_1_bss_9F8.unk_12 >> 4U) & 1)) {
                var_r4_2 = -1;
            }
            if (var_r4_2 != 0) {
                u8 mask;
                do {
                    temp_r3_4 = (s8) (*(u8 *)((u8 *)(arg0) + 36)) + var_r4_2;
                    if (temp_r3_4 > 4) {
                        var_r0.value = 0;
                    } else {
                        var_r0.value = 4;
                        if (temp_r3_4 >= 0) {
                            var_r0.value = temp_r3_4;
                        }
                    }
                    (*(u8 *)((u8 *)(arg0) + 36)) = (u8) var_r0.value;
                    temp_r4_2 = *(u8 *)((u8 *)(arg0) + 36);
                    mask = 1;
                    temp_r4 = mask << (s8) temp_r4_2;
                    mask = temp_r4;
                    temp_r3_3 = (void *)((*(s32 *)((u8 *)(arg0) + 0)) + ((s8) (*(u8 *)((u8 *)(arg0) + 7)) * 0x440));
                } while (!(temp_r4 & (*(u8 *)((u8 *)(temp_r3_3) + 908))));
                (*(u8 *)((u8 *)(arg0) + 8)) = fn_1_816E8(temp_r3_3, temp_r4_2);
                return;
            }
            break;
        case 2:                                     /* switch 1 */
            if (((u16) lbl_1_bss_9F8.unk_8 >> 9U) & 1) {
                (*(u8 *)((u8 *)(arg0) + 6)) = 1U;
            }
            if (((u16) (*(u16 volatile *)&(INPUT_24)) /* Retail reloads this field. */ >> 3U) & 1) {
                var_r4 = -1;
            }
            if (((u16) (*(u16 volatile *)&(INPUT_24)) /* Retail reloads this field. */ >> 2U) & 1) {
                var_r4 += 1;
            }
            if ((*(u16 volatile *)&(INPUT_24)) /* Retail reloads this field. */ & 1) {
                var_r5 = -1;
            }
            if (((u16) (*(u16 volatile *)&(INPUT_24)) /* Retail reloads this field. */ >> 1U) & 1) {
                var_r5 += 1;
            }
            (*(u8 *)((u8 *)(arg0) + 5)) = (u8) ((*(u8 *)((u8 *)(arg0) + 5)) + var_r4);
            if ((s8) (*(u8 *)((u8 *)(arg0) + 5)) < 0) {
                (*(u8 *)((u8 *)(arg0) + 5)) = 2U;
            }
            if ((s8) (*(u8 *)((u8 *)(arg0) + 5)) > 2) {
                (*(u8 *)((u8 *)(arg0) + 5)) = 0U;
            }
            temp_r0_3 = *(u8 *)((u8 *)(arg0) + 5);
            switch ((s8) temp_r0_3) {               /* switch 2; irregular */
            case 0:                                 /* switch 2 */
                temp_r4_3 = (u8 *)(*(u8 **)((u8 *)((*(u8 ***)((u8 *)(arg0) + 28))) + 0));
                (*(u8 *)((u8 *)(temp_r4_3) + 0)) = (u8) ((*(u8 *)((u8 *)(temp_r4_3) + 0)) + var_r5);
                temp_r4_4 = (u8 *)(*(u8 **)((u8 *)((*(u8 ***)((u8 *)(arg0) + 28))) + 0));
                temp_r3_5 = *(u8 *)((u8 *)(temp_r4_4) + 0);
                (*(u8 *)((u8 *)(temp_r4_4) + 0)) = CLAMP_U8(temp_r3_5);
                break;
            case 1:                                 /* switch 2 */
                temp_r4_5 = (u8 *)(*(u8 **)((u8 *)((*(u8 ***)((u8 *)(arg0) + 28))) + 0));
                (*(u8 *)((u8 *)(temp_r4_5) + 1)) = (u8) ((*(u8 *)((u8 *)(temp_r4_5) + 1)) + var_r5);
                temp_r3_6 = (u8 *)(*(u8 **)((u8 *)((*(u8 ***)((u8 *)(arg0) + 28))) + 0));
                temp_r4_6 = *(u8 *)((u8 *)(temp_r3_6) + 1);
                (*(u8 *)((u8 *)(temp_r3_6) + 1)) = CLAMP_U8(temp_r4_6);
                break;
            case 2:                                 /* switch 2 */
                temp_r4_7 = (u8 *)(*(u8 **)((u8 *)((*(u8 ***)((u8 *)(arg0) + 28))) + 0));
                (*(u8 *)((u8 *)(temp_r4_7) + 2)) = (u8) ((*(u8 *)((u8 *)(temp_r4_7) + 2)) + var_r5);
                temp_r3_7 = (u8 *)(*(u8 **)((u8 *)((*(u8 ***)((u8 *)(arg0) + 28))) + 0));
                temp_r4_8 = *(u8 *)((u8 *)(temp_r3_7) + 2);
                (*(u8 *)((u8 *)(temp_r3_7) + 2)) = CLAMP_U8(temp_r4_8);
                break;
            case 3:                                 /* switch 2 */
                temp_r4_9 = (u8 *)(*(u8 **)((u8 *)((*(u8 ***)((u8 *)(arg0) + 28))) + 0));
                (*(u8 *)((u8 *)(temp_r4_9) + 3)) = (u8) ((*(u8 *)((u8 *)(temp_r4_9) + 3)) + var_r5);
                temp_r3_8 = (u8 *)(*(u8 **)((u8 *)((*(u8 ***)((u8 *)(arg0) + 28))) + 0));
                temp_r4_10 = *(u8 *)((u8 *)(temp_r3_8) + 3);
                (*(u8 *)((u8 *)(temp_r3_8) + 3)) = CLAMP_U8(temp_r4_10);
                break;
            }
            if (((u16) (*(u16 *)((u8 *)(&lbl_1_bss_9F8) + 28)) >> 4U) & 1) {
                (*(s32 *)((u8 *)(arg0) + 32)) = (s32) ((*(s32 *)((u8 *)(arg0) + 32)) ^ 0x80000000);
                return;
            }
            break;
        case 4:                                     /* switch 1 */
            if ((((u16) (*(u16 volatile *)&(lbl_1_bss_9F8.unk_10)) /* Retail reloads this field. */ >> 3U) & 1) || (((u16) lbl_1_bss_9F8.unk_12 >> 3U) & 1)) {
                var_r4 = -1;
            }
            if ((((u16) (*(u16 volatile *)&(lbl_1_bss_9F8.unk_10)) /* Retail reloads this field. */ >> 2U) & 1) || (((u16) lbl_1_bss_9F8.unk_12 >> 2U) & 1)) {
                var_r4 += 1;
            }
            if (((*(u16 volatile *)&(lbl_1_bss_9F8.unk_10)) /* Retail reloads this field. */ & 1) || (lbl_1_bss_9F8.unk_12 & 1)) {
                var_r5 = -1;
            }
            if ((((u16) (*(u16 volatile *)&(lbl_1_bss_9F8.unk_10)) /* Retail reloads this field. */ >> 1U) & 1) || (((u16) lbl_1_bss_9F8.unk_12 >> 1U) & 1)) {
                var_r5 += 1;
            }
            (*(u8 *)((u8 *)(arg0) + 5)) = (u8) ((*(u8 *)((u8 *)(arg0) + 5)) + var_r4);
            if ((s8) (*(u8 *)((u8 *)(arg0) + 5)) < 0) {
                (*(u8 *)((u8 *)(arg0) + 5)) = 3U;
            }
            if ((s8) (*(u8 *)((u8 *)(arg0) + 5)) > 3) {
                (*(u8 *)((u8 *)(arg0) + 5)) = 0U;
            }
            temp_r0_4 = *(u8 *)((u8 *)(arg0) + 5);
            switch ((s8) temp_r0_4) {               /* switch 3; irregular */
            case 0:                                 /* switch 3 */
                temp_r4_11 = (void *)(*(void **)((u8 *)(arg0) + 24));
                (*(u8 *)((u8 *)(temp_r4_11) + 0)) = (u8) ((*(u8 *)((u8 *)(temp_r4_11) + 0)) + var_r5);
                temp_r4_12 = (void *)(*(void **)((u8 *)(arg0) + 24));
                temp_r3_9 = *(u8 *)((u8 *)(temp_r4_12) + 0);
                (*(u8 *)((u8 *)(temp_r4_12) + 0)) = CLAMP_U8(temp_r3_9);
                break;
            case 1:                                 /* switch 3 */
                temp_r4_13 = (void *)(*(void **)((u8 *)(arg0) + 24));
                (*(u8 *)((u8 *)(temp_r4_13) + 1)) = (u8) ((*(u8 *)((u8 *)(temp_r4_13) + 1)) + var_r5);
                temp_r3_10 = (void *)(*(void **)((u8 *)(arg0) + 24));
                temp_r4_14 = *(u8 *)((u8 *)(temp_r3_10) + 1);
                (*(u8 *)((u8 *)(temp_r3_10) + 1)) = CLAMP_U8(temp_r4_14);
                break;
            case 2:                                 /* switch 3 */
                temp_r4_15 = (void *)(*(void **)((u8 *)(arg0) + 24));
                (*(u8 *)((u8 *)(temp_r4_15) + 2)) = (u8) ((*(u8 *)((u8 *)(temp_r4_15) + 2)) + var_r5);
                temp_r3_11 = (void *)(*(void **)((u8 *)(arg0) + 24));
                temp_r4_16 = *(u8 *)((u8 *)(temp_r3_11) + 2);
                (*(u8 *)((u8 *)(temp_r3_11) + 2)) = CLAMP_U8(temp_r4_16);
                break;
            case 3:                                 /* switch 3 */
                temp_r4_17 = (void *)(*(void **)((u8 *)(arg0) + 24));
                (*(u8 *)((u8 *)(temp_r4_17) + 3)) = (u8) ((*(u8 *)((u8 *)(temp_r4_17) + 3)) + var_r5);
                temp_r3_12 = (void *)(*(void **)((u8 *)(arg0) + 24));
                temp_r4_18 = *(u8 *)((u8 *)(temp_r3_12) + 3);
                (*(u8 *)((u8 *)(temp_r3_12) + 3)) = CLAMP_U8(temp_r4_18);
                break;
            }
            if (((u16) lbl_1_bss_9F8.unk_8 >> 0xBU) & 1) {
                fn_800793D4((void *)(*(void **)((u8 *)(arg0) + 24)), (s32)(0), (u32)(4U));
            }
            if (((u16) lbl_1_bss_9F8.unk_8 >> 9U) & 1) {
                (*(u8 *)((u8 *)(arg0) + 6)) = 0U;
                (*(u8 *)((u8 *)(arg0) + 5)) = 0U;
                return;
            }
            break;
        case 3:                                     /* switch 1 */
            if (((u16) lbl_1_bss_9F8.unk_8 >> 9U) & 1) {
                (*(u8 *)((u8 *)(arg0) + 6)) = 0U;
                (*(u8 *)((u8 *)(arg0) + 5)) = 0U;
            }
            if ((((u16) (*(u16 volatile *)&(lbl_1_bss_9F8.unk_10)) /* Retail reloads this field. */ >> 3U) & 1) || (((u16) lbl_1_bss_9F8.unk_12 >> 3U) & 1) || (((u16) (*(u16 volatile *)&(INPUT_24)) /* Retail reloads this field. */ >> 3U) & 1) || (((u16) INPUT_26 >> 3U) & 1)) {
                var_r4 = -1;
            }
            if ((((u16) (*(u16 volatile *)&(lbl_1_bss_9F8.unk_10)) /* Retail reloads this field. */ >> 2U) & 1) || (((u16) lbl_1_bss_9F8.unk_12 >> 2U) & 1) || (((u16) (*(u16 volatile *)&(INPUT_24)) /* Retail reloads this field. */ >> 2U) & 1) || (((u16) INPUT_26 >> 2U) & 1)) {
                var_r4 += 1;
            }
            if (((*(u16 volatile *)&(lbl_1_bss_9F8.unk_10)) /* Retail reloads this field. */ & 1) || (lbl_1_bss_9F8.unk_12 & 1) || ((*(u16 volatile *)&(INPUT_24)) /* Retail reloads this field. */ & 1) || (INPUT_26 & 1)) {
                var_r5 = -1;
            }
            if ((((u16) (*(u16 volatile *)&(lbl_1_bss_9F8.unk_10)) /* Retail reloads this field. */ >> 1U) & 1) || (((u16) lbl_1_bss_9F8.unk_12 >> 1U) & 1) || (((u16) (*(u16 volatile *)&(INPUT_24)) /* Retail reloads this field. */ >> 1U) & 1) || (((u16) INPUT_26 >> 1U) & 1)) {
                var_r5 += 1;
            }
            (*(u8 *)((u8 *)(arg0) + 5)) = (u8) ((*(u8 *)((u8 *)(arg0) + 5)) + var_r4);
            if ((s8) (*(u8 *)((u8 *)(arg0) + 5)) < 0) {
                (*(u8 *)((u8 *)(arg0) + 5)) = 2U;
            }
            if ((s8) (*(u8 *)((u8 *)(arg0) + 5)) > 2) {
                (*(u8 *)((u8 *)(arg0) + 5)) = 0U;
            }
            temp_r0_5 = *(u8 *)((u8 *)(arg0) + 5);
            switch ((s8) temp_r0_5) {               /* switch 4; irregular */
            case 0:                                 /* switch 4 */
                temp_r4_19 = (u8 *)(*(u8 **)((u8 *)((*(u8 ***)((u8 *)(arg0) + 28))) + 0));
                (*(u8 *)((u8 *)(temp_r4_19) + 0)) += var_r5;
                temp_r4_20 = (u8 *)(*(u8 **)((u8 *)((*(u8 ***)((u8 *)(arg0) + 28))) + 0));
                temp_r3_13 = *(u8 *)((u8 *)(temp_r4_20) + 0);
                (*(u8 *)((u8 *)(temp_r4_20) + 0)) = CLAMP_U8(temp_r3_13);
                return;
            case 1:                                 /* switch 4 */
                temp_r4_21 = (u8 *)(*(u8 **)((u8 *)((*(u8 ***)((u8 *)(arg0) + 28))) + 0));
                (*(u8 *)((u8 *)(temp_r4_21) + 1)) = (u8) ((*(u8 *)((u8 *)(temp_r4_21) + 1)) + var_r5);
                temp_r3_14 = (u8 *)(*(u8 **)((u8 *)((*(u8 ***)((u8 *)(arg0) + 28))) + 0));
                temp_r4_22 = *(u8 *)((u8 *)(temp_r3_14) + 1);
                (*(u8 *)((u8 *)(temp_r3_14) + 1)) = CLAMP_U8(temp_r4_22);
                return;
            case 2:                                 /* switch 4 */
                temp_r4_23 = (u8 *)(*(u8 **)((u8 *)((*(u8 ***)((u8 *)(arg0) + 28))) + 0));
                (*(u8 *)((u8 *)(temp_r4_23) + 2)) = (u8) ((*(u8 *)((u8 *)(temp_r4_23) + 2)) + var_r5);
                temp_r3_15 = (u8 *)(*(u8 **)((u8 *)((*(u8 ***)((u8 *)(arg0) + 28))) + 0));
                temp_r4_24 = *(u8 *)((u8 *)(temp_r3_15) + 2);
                (*(u8 *)((u8 *)(temp_r3_15) + 2)) = CLAMP_U8(temp_r4_24);
                return;
            case 3:                                 /* switch 4 */
                temp_r4_25 = (u8 *)(*(u8 **)((u8 *)((*(u8 ***)((u8 *)(arg0) + 28))) + 0));
                (*(u8 *)((u8 *)(temp_r4_25) + 3)) = (u8) ((*(u8 *)((u8 *)(temp_r4_25) + 3)) + var_r5);
                temp_r3_16 = (u8 *)(*(u8 **)((u8 *)((*(u8 ***)((u8 *)(arg0) + 28))) + 0));
                temp_r4_26 = *(u8 *)((u8 *)(temp_r3_16) + 3);
                (*(u8 *)((u8 *)(temp_r3_16) + 3)) = CLAMP_U8(temp_r4_26);
                break;
            }
            break;
        case 5:                                     /* switch 1 */
            break;
        }
    }
}
#pragma opt_propagation reset

#pragma opt_pointer_analysis reset

#pragma opt_dead_assignments reset
/* fzgx:end fn_1_7D6B8 */

/* fzgx:begin fn_1_7E7A4 */
typedef struct Fn1_7E7A4Data {
    void *field_0;
    u8 pad_4[8];
    void *field_c;
    u8 pad_10[8];
    void *field_18;
    void *field_1c;
} Fn1_7E7A4Data;

void fn_1_7E7A4(Fn1_7E7A4Data *arg0) {
    s8 i;
    u32 offset;

    for (i = 0, offset = 0; i < 0x29; offset += 0x440, i++) {
        fn_1_46B4( (u32)(void *)(lbl_801A6410), (u32)(void *)(*(void **)(((((((0x32c) + ((u8 *)arg0->field_0)))) + ((offset)))))), (const char *)(u8 *)((*(u8 (*)[128])&lbl_1_data_1EF5C)),
            0x313);
    }

    fn_1_7F954( (u32)(void *)(arg0->field_0), 0x29);

    for (i = 0; i < 2; i++) {
        fn_1_46B4( (u32)(void *)(lbl_801A6410), (u32)(void *)(*(void **)((u8 *)arg0->field_1c + i * 0xc)), (const char *)(u8 *)((*(u8 (*)[128])&lbl_1_data_1EF5C)),
            0x321);
    }

    fn_1_46B4( (u32)(void *)(lbl_801A6410), (u32)(void *)(arg0->field_18), (const char *)(u8 *)((*(u8 (*)[128])&lbl_1_data_1EF5C)), 0x324);
    fn_1_46B4( (u32)(void *)(lbl_801A6410), (u32)(void *)(arg0->field_c), (const char *)(u8 *)((*(u8 (*)[128])&lbl_1_data_1EF5C)), 0x325);
    fn_1_46B4( (u32)(void *)(lbl_801A6410), (u32)(void *)(arg0), (const char *)(u8 *)((*(u8 (*)[128])&lbl_1_data_1EF5C)), 0x326);
    fn_1_49614();
    fn_80074D68(lbl_1_rodata_33A8, lbl_1_rodata_33A8, lbl_1_rodata_33A8);
    fn_80074D78(1);
}
/* fzgx:end fn_1_7E7A4 */

/* fzgx:begin fn_1_7E8F4 */
static inline s32 chk(void) {
    Obj_1_bss_6D620 *p = &lbl_1_bss_6D620;
    s32 r = 0;
    if ((s8)p->unk_F != 0 || (s32)p->unk_10 < 0x20) {
        r = 1;
    }
    return r;
}

typedef struct lbl_1_bss_6D7F4_t {
    u8 unk_0;
    u8 pad_1[0x3];
    f32 unk_4;
    f32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    s8 unk_F;
    u8 pad_10[0x1c];
} lbl_1_bss_6D7F4_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
lbl_1_bss_6D7F4_t fzgx_obj_lbl_1_bss_6D7F4;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D7F4;
}
#pragma section code_type ".text"

void fn_1_7E8F4(void) {
    lbl_1_bss_6D7F0 = 0;
    if (lbl_1_bss_3BE0 != 0) {
        s32 flag = chk();
        fzgx_obj_lbl_1_bss_6D7F4.unk_F = (flag != 0);
        fzgx_obj_lbl_1_bss_6D7F4.unk_0 = lbl_1_bss_6D620.unk_0;
        fzgx_obj_lbl_1_bss_6D7F4.unk_4 = lbl_1_bss_6D620.unk_4;
        fzgx_obj_lbl_1_bss_6D7F4.unk_8 = lbl_1_bss_6D620.unk_8;
        fzgx_obj_lbl_1_bss_6D7F4.unk_C = lbl_1_bss_6D620.unk_C;
        fzgx_obj_lbl_1_bss_6D7F4.unk_D = lbl_1_bss_6D620.unk_D;
        fzgx_obj_lbl_1_bss_6D7F4.unk_E = lbl_1_bss_6D620.unk_E;
    } else {
        fzgx_obj_lbl_1_bss_6D7F4.unk_F = 0;
        fzgx_obj_lbl_1_bss_6D7F4.unk_0 = 5;
        fzgx_obj_lbl_1_bss_6D7F4.unk_4 = lbl_1_rodata_3500;
        fzgx_obj_lbl_1_bss_6D7F4.unk_8 = lbl_1_rodata_3504;
        fzgx_obj_lbl_1_bss_6D7F4.unk_C = 0;
        fzgx_obj_lbl_1_bss_6D7F4.unk_D = 0;
        fzgx_obj_lbl_1_bss_6D7F4.unk_E = 0;
    }
}
/* fzgx:end fn_1_7E8F4 */

/* fzgx:begin fn_1_7E9C4 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/car_test.h"

extern u32 fn_1_5910(void);
extern void fn_1_5634C(s32 arg0);
extern void fn_1_5635C(s32 arg0, f32 arg1, f32 arg2);
extern void fn_1_56374(u8 arg0, u8 arg1, u8 arg2);
extern void fn_1_7EB0C(void);

typedef struct {
    s8 unk_0;
    f32 unk_4;
    f32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    s8 unk_F;
    s32 unk_10;
    s32 unk_14;
} Entry7E9C4;

typedef struct {
    s8 unk_0;
    f32 unk_4;
    f32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    s8 unk_F;
} Cur7E9C4;

static inline s32 check7E9C4(u32 idx) {
    Entry7E9C4 *e = &((Entry7E9C4 *)&lbl_1_bss_6D620)[idx];
    s32 sel = 0;

    if (e->unk_F != 0 || e->unk_10 < 0x20) {
        sel = 1;
    }
    return sel;
}

void fn_1_7E9C4(void) {
    s32 sel;
    if (lbl_1_bss_3BE0 != 0 && (s8)lbl_1_bss_6D7F0 == 0) {
        u32 off;

        off = fn_1_5910() * 0x18;
        sel = 0;
        if (*((s8 *)&lbl_1_bss_6D620 + off + 0xF) != 0 ||
            *(s32 *)((s8 *)&lbl_1_bss_6D620 + off + 0x10) < 0x20) {
            sel = 1;
        }
        ((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_F = sel != 0;
        ((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_0 = ((u8 *)&lbl_1_bss_6D620)[off];
        ((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_4 = *(f32 *)((u8 *)&lbl_1_bss_6D620 + off + 0x4);
        ((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_8 = *(f32 *)((((off) + (0x8)) + ((u8 *)&lbl_1_bss_6D620)));
        ((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_C = *((u8 *)&lbl_1_bss_6D620 + off + 0xC);
        ((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_D = *((u8 *)&lbl_1_bss_6D620 + off + 0xD);
        ((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_E = *((u8 *)&lbl_1_bss_6D620 + off + 0xE);
    }

    fn_1_5634C(((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_F);
    if (((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_F != 0) {
        fn_1_5635C(((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_0,
                   ((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_4,
                   ((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_8);
        fn_1_56374(((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_C,
                   ((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_D,
                   ((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_E);
    }
    fn_1_7EB0C();
}
/* fzgx:end fn_1_7E9C4 */

/* fzgx:begin fn_1_7EAE8 */
// fn_1_7EAE8: main_rel .text:0x0007EAE8 size 0x24
// Wrapper that calls fn_1_5634C with argument 0.

void fn_1_7EAE8(void) {
    fn_1_5634C(0);
}
/* fzgx:end fn_1_7EAE8 */

/* fzgx:begin fn_1_7EB0C */
typedef struct {
    s8 unk_0;
} SignedByteView;

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
} LocalBytes;

void fn_1_7EB0C(void) {
    LocalBytes local0;
    LocalBytes local1;

    local0.unk_0 = lbl_1_bss_6D7F4.unk_C;
    local0.unk_1 = lbl_1_bss_6D7F4.unk_D;
    local0.unk_2 = lbl_1_bss_6D7F4.unk_E;
    if ((s8)lbl_1_bss_6D7F4.unk_F != 0) {
        fn_80071ED4(lbl_1_bss_6D7F4.unk_4, lbl_1_bss_6D7F4.unk_8, ((SignedByteView *)&lbl_1_bss_6D7F4)->unk_0 + 0);
        local1 = local0;
        fn_80072014(&local1);
        fn_800720B0(1);
    } else {
        fn_800720B0(0);
    }
}
/* fzgx:end fn_1_7EB0C */

/* fzgx:begin fn_1_7EB8C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/car_test.h"
#include "game/main_rel/car_test_types.h"
#include "psvec.h"

extern f32 lbl_1_rodata_3508[4];
extern void *lbl_801A6D00;
extern void fn_1_556B8(void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006D848(f32);
extern void lbl_8006DFC4(void *);
extern void fn_80072558(void);

typedef struct DrawNode {
    void *model0;
    u32 pad4;
    void *model8;
} DrawNode;
typedef struct DrawEntry {
    u8 pad0[8];
    DrawNode *node;
} DrawEntry;
typedef struct DrawPair {
    DrawEntry *entry;
    u32 pad4;
} DrawPair;
typedef struct DrawCar {
    u8 pad0[0x328];
    u8 mode;
    u8 pad329[0x67];
    u32 flags;
    u8 pad394[0x10];
    DrawPair *pairs;
    u8 pad3A8[0x12];
    s16 index;
} DrawCar;

static inline f32 calculate_blend(f32 z, u8 *pool) {
    f32 blend = *(f32 *)(pool + 0x10);
    if (__fabs(z) < *(f64 *)(pool + 0x18)) {
        return blend;
    }
    if (z < *(f64 *)(pool + 0x30)) {
        blend = *(f32 *)(pool + 0x28) +
                *(f32 *)(pool + 0x38) / z;
    }
    return blend;
}

void fn_1_7EB8C(DrawCar *arg0) {
    void *model;
    f32 v[3];
    f32 blend;
    f32 *matrix = (f32 *)(0xE0000000 + 0x00);
    u8 *pool = (u8 *)lbl_1_rodata_3508;
    s8 index = arg0->index;
    if (arg0->pairs != 0) {
        if (arg0->flags & 0x04000000) {
            model = arg0->pairs[index].entry->node->model0;
        } else if ((s32)arg0->mode == 4) {
            model = arg0->pairs[index].entry->node->model8;
        } else {
            model = arg0->pairs[index].entry->node->model0;
        }
        psvec_set(v, matrix[11], matrix[7], matrix[3]);
        blend = calculate_blend(matrix[11], pool);
        lbl_8006DB74((u8 *)lbl_801A6D00 + 0x60);
        lbl_8006D848(blend);
        lbl_8006DFC4((u8 *)lbl_801A6D00 + 0x60);
        fn_80072558();
        fn_1_556B8(model);
    }
}
/* fzgx:end fn_1_7EB8C */

/* fzgx:begin fn_1_7F1E8 */
void fn_1_7F1E8(u32 arg0, u32 arg1) {
    fn_1_7ECB8(arg0, arg1, 0x80000000); // fzgx-allow: A1 retail sentinel
}
/* fzgx:end fn_1_7F1E8 */

/* fzgx:begin fn_1_7F20C */
void fn_1_7F20C(u32 arg0, u32 arg1) {
    fn_1_7ECB8(arg0, arg1, 0x40000000); // fzgx-allow: A1 retail sentinel
}
/* fzgx:end fn_1_7F20C */

/* fzgx:begin fn_1_7F230 */
void fn_1_7F230(u32 arg0, u32 arg1) {
    fn_1_7ECB8(arg0, arg1, 0);
}
/* fzgx:end fn_1_7F230 */

/* fzgx:begin fn_1_7F254 */
void *fn_1_7F254(void *arg0, void *arg1) {
    u8 kind = ((u8 *)arg0)[5];
    s16 type;
    void *result;
    char *data = (char *)&lbl_1_data_1F1D8;

    if (kind == 4) {
        type = 2;
    } else if (kind == 0x28 || kind >= 0x29) {
        type = 3;
    } else {
        type = 1;
    }

    if ((((u32 *)arg0)[0] & 0x40000000) == 0) {
        fn_1_12AB38( (void *)(const char *)(data + 0xe0c));
        result = (void *)fn_1_45D0(lbl_801A6410, type * 0x30, data + 0xe18, 0x1d5);
        fn_80008BEC(result, 0, type * 0x30);
        fn_1_80F80(result, ((u8 *)arg0)[0x81a0], arg1);
        fn_1_12AB38( (void *)(const char *)(data + 0xe20));
    } else {
        struct {
            u16 a;
            u16 b;
            u16 c;
        } info;
        *(u32 *)&info = ((const u32 *)&lbl_1_rodata_3588)[0];
        info.c = ((const u16 *)&lbl_1_rodata_3588)[2];
        info.a = ((u8 *)arg0)[0x81a4];
        info.b = ((u8 *)arg0)[0x81ac];
        info.c = ((u8 *)arg0)[0x81b4];
        result = (void *)fn_1_45D0(lbl_801A6410, 0x90, data + 0xe18, 0x1e2);
        fn_80008BEC(result, 0, 0x90);
        fn_1_1502BC(result, &info, arg1);
    }
    return result;
}
/* fzgx:end fn_1_7F254 */

/* fzgx:begin fn_1_7F518 */
// Initializes the car test entry and optionally performs its follow-up setup.
void* fn_1_7F518(s16 car_type, void* car, s32 initialize) {
    fn_80083DB0( (char *)(void*)(car), (const char *)(u32)(((u32 *)lbl_1_data_1F4FC)[car_type]));
    if (initialize == 1) {
        fn_1_801F8(car_type, car);
    }
    return car;
}
/* fzgx:end fn_1_7F518 */

/* fzgx:begin fn_1_83D28 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.0f;
}
static const u32 fzgx_pool_table2[2] = {0x40000000, 0x40000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.5f;
    s = 0.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.1920928955078125e-07;
    s = 1.4499999284744263f;
    s = -1.5881868392106856e-23f;
    s = 1.0f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.15000000074505807;
    s = 0.05000000074505806f;
    s = 30.0f;
    s = 0.00390625f;
    s = 182.04444885253906f;
    s = 180.0f;
    s = 44.0f;
    s = 89.0f;
    s = 360.0f;
    s = 60.0f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.12999999932944775;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table12[306] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00330000, 0x00010001, 0x00020002, 0x00030003, 0x0004002F, 0x00050004, 0x00060005, 0x00070006, 0x00080007, 0x00090008, 0x000A002A, 0x000B0009, 0x000C002B, 0x000D000A, 0x000E002C, 0x000F000B, 0x0010002D, 0x0011000C, 0x0012002E, 0x0013000D, 0x0014000E, 0x003D000F, 0x003E0010, 0x003F0011, 0x00400012, 0x00410013, 0x00420014, 0x00430015, 0x00440016, 0x00450017, 0x00460018, 0x00470019, 0x0048001A, 0x0049001B, 0x004A001C, 0x004B001D, 0x004C0034, 0x004D0035, 0x004E0036, 0x004F0037, 0x001F001E, 0x0020001F, 0x00210020, 0x00220021, 0x00230022, 0x00240023, 0x00250024, 0x00260025, 0x00270026, 0x00280027, 0x00290028, 0x002A0029, 0x00500038, 0x00510030, 0x00520031, 0x00530032, 0x00540033, 0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
}
static const u32 fzgx_pool_table14[3] = {0x0032001E, 0x00140004, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    d = 0.20000000298023224;
    s = 0.10000000149011612f;
    s = 0.11999999731779099f;
    s = -0.10000000149011612f;
    s = -1.0f;
    s = 0.8999999761581421f;
    s = 0.49000000953674316f;
    d = 0.800000011920929;
    s = 0.4000000059604645f;
}
static const u32 fzgx_pool_table16[3] = {0x00000000, 0x3F000000, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.0f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 0.75f;
    s = 0.5f;
    s = 1000.0f;
}
#pragma section code_type ".text"









// Returns the section index the car reaches, -1 for no target, 5 for out of range.
// `speed` is reused as the scratch value after its scaling role is over.
s8 fn_1_83D28(Fn183D28Car *car, f32 speed) {
    Fn183D28Vec3 vec;
    f32 camA;
    f32 camB;
    u8 buf[4];
    s8 result;
    s8 idx;
    Fn183D28Target *target;
    f32 dist;
    f32 depth;
    f32 limit;
    s8 i;

    result = -1;
    idx = fn_1_84124(car, 1, 0, buf);
    if (car->flags & 0x04000000) {
        target = *car->alt->slots[idx]->target;
    } else {
        target = *car->entries[idx].target;
    }
    if (target == NULL) {
        return -1;
    }

    dist = (2.0f * target->radius) * speed;
    lbl_8006DFE8(&car->body->pos);
    if (fn_1_54E34( (void *)(Fn183D28Vec3 *)(&target->dir), target->radius) == 0) {
        return 5;
    }
    lbl_8006E1B0(&target->dir, &vec);
    if (vec.z > -1.1920928955078125e-07f) {
        return idx;
    }

    depth = -vec.z * fn_1_A71AC();
    idx = fn_1_84644(car->body);
    lbl_1_bss_6D980[car->index] = 0;
    speed = (240.0f * dist) / depth;
    if (camera_get_values(&camA, &camB)) {
        speed *= camB;
    }
    if ((s8)fn_1_A5DC4()) {
        speed *= 0.75f;
    }

    for (i = 0; i < 6; i++) {
        limit = (f32)car->entries[i + 1].limit;
        if (i == 3) {
            if (idx == 0) {
                limit = 2.0f;
            } else if (speed < lbl_1_data_1FFE0.unk_0) {
                lbl_1_bss_6D980[car->index] = 1;
            }
        }
        if (speed > limit) {
            if (i > 0) {
                if (speed / ((f32)car->entries[i].limit + limit) > 0.5f) {
                    lbl_1_bss_6D9A0[car->index] = 0;
                } else {
                    lbl_1_bss_6D9A0[car->index] = 1;
                }
            } else {
                lbl_1_bss_6D9A0[car->index] = 1;
            }
            if (i == 4) {
                i = 5;
            }
            result = i;
            break;
        } else if (limit < 0.0f) {
            result = i;
            break;
        }
    }

    if (result == 5 && car->body != NULL && car->body->unk_200 == 0.0f) {
        lbl_1_bss_6D980[car->index] = 0;
        result--;
    }
    return result;
}
/* fzgx:end fn_1_83D28 */

/* fzgx:begin fn_1_870BC */
typedef struct { u8 b[0xE8]; } Blob870BC;
extern Blob870BC lbl_1_rodata_3968;
extern u32 lbl_1_bss_6D82C[3];
extern void fn_1_14E2DC(u32, s32, f32);
extern void fn_1_8E450(void *);
extern void fn_1_87610(void *, s32);
extern void fn_1_875B4(void *, s32, s32, f32);
extern void fn_1_87238(void *, s32, f32);
extern void fn_1_8E480(void);
extern void fn_800713E0(u32, u32);
extern void fn_800712E4(u32, u32, void *);
extern u32 lbl_8006DAEC(void);
extern u32 lbl_8006DBE4(void);
extern void lbl_8006DB30(void);

typedef struct {
    u8 pad0[0x328];
    s8 f328;
    u8 pad1[0x338 - 0x329];
    struct { u32 a, b, c; } slot[2];
    u8 pad2[0x37c - 0x350];
    u32 tab[4];
    u8 pad3[0x390 - 0x38c];
    u32 flags;
    u8 pad4[0x3a0 - 0x394];
    u32 f3a0;
    u8 pad5[0x3b8 - 0x3a4];
    s16 f3b8;
    s16 f3ba;
} Car870BC;

void fn_1_870BC(Car870BC *car, s32 a, s32 b, s16 c, u8 d, f32 x)
{
    Blob870BC tbl;
    s32 i;
    s8 signed_a = (s8)a;
    car->f3ba = signed_a;
    if (car->flags & 0x04000000) {
        fn_1_14E2DC(car->f3a0, signed_a, x);
        return;
    }
    i = d;
    if (car->f3b8 != i) {
        u32 v = car->tab[i % 4];
        if (v != 0) {
            Car870BC *q = (Car870BC *)((u8 *)car + signed_a * 12);
            u32 s;
            fn_800713E0(q->slot[0].a, v);
            s = q->slot[0].a;
            tbl = lbl_1_rodata_3968;
            fn_800712E4(s, lbl_1_bss_6D82C[0], &tbl);
        }
        car->f3b8 = d;
    }
    lbl_8006DAEC();
    fn_1_8E450(car);
    if (c != 0) {
        ((void (**)(void *))lbl_1_data_1F5A0)[car->f328](car);
    } else {
        fn_1_87610(car, b);
    }
    fn_1_875B4(car, b, a, x);
    lbl_8006DBE4();
    fn_1_87238(car, a, x);
    fn_1_8E480();
    lbl_8006DB30();
}
/* fzgx:end fn_1_870BC */

/* fzgx:begin fn_1_8CA00 */
u32 *fn_1_8CA00(void) {
    return &lbl_1_data_1FFDC;
}
/* fzgx:end fn_1_8CA00 */

/* fzgx:begin fn_1_8DD54 */
typedef struct {
    u8 pad_0[0x18];
    u32 unk_18;
    CarTestCar *cars;
    u8 pad_20[0xA];
    u8 car_count;
    u8 pad_2B[0x9];
    u8 unk_34;
    u8 pad_35[0x12B];
    u8 flags[0xEAC];
    u16 costs[0x20][5];
} CarTestManager;



static inline CarTestCar *get_car(CarTestManager *mgr, s32 index) {
    if ((s8)index < (s8)mgr->car_count && mgr->cars != NULL) {
        return &mgr->cars[(s8)index];
    }
    return NULL;
}

void fn_1_8DD54(void) {
    // One-member-style carrier: keeps the manager base and its interior
    // table addresses as CSE'd values (callee-saved shadows) across the loops.
    struct { CarTestManager *value; u16 (*costs)[5]; u8 *flags; } m;
    s32 i;
    u32 limit;
    CarTestCar *car;
    s16 state;
    CarTestInfo info;
    u32 total;

    m.value = (CarTestManager *)&lbl_1_bss_6D820;
    fn_1_3EF14( (void *)(CarTestInfo *)(&info));
    total = 0;
    switch (fn_1_58C4()) {
    case 1:
        state = fn_1_7B054();
        if (state == 40) {
            limit = 2100;
        } else if (state == 25) {
            limit = 1300;
        } else {
            limit = 1600;
        }
        break;
    case 2:
        limit = 1600;
        break;
    case 3:
        limit = 600;
        break;
    case 4:
    default:
        limit = 600;
        break;
    }

    if ((info.flags & 0x4000) && (fn_1_3F0C8() == 40 || fn_1_3FC18() > 0)) {
        (*((f32 *)&lbl_1_data_1FFE0)) = 8.0f;
    } else {
        (*((f32 *)&lbl_1_data_1FFE0)) = 5.0f;
    }

    m.costs = m.value->costs;
    for (i = 0; i < info.count; i++) {
        car = get_car(m.value, i);
        car->state = (s8)fn_1_84408(car);
        state = car->state;
        if (state != 5 && *(u8 *)(m.value->unk_18 + i * 0x620 + 0x50d) >= 0xf0) {
            car->state = 3;
            total += 50;
        } else if (state != 5) {
            total += m.costs[i][state];
        }
    }

    if (total > limit || m.value->unk_34) {
        m.flags = m.value->flags;
        for (i = 0; i < info.count; m.flags++, i++) {
            car = get_car(m.value, i);
            if (*m.flags) {
                total -= m.costs[i][car->state];
                car->state = 5;
            }
        }
        if (total > limit) {
            for (i = 0; i < info.count; i++) {
                car = get_car(m.value, i);
                if (car->state > 0 && car->state < 3) {
                    fn_1_8E084(car, &total, i);
                }
            }
            if (total > limit) {
                for (i = 0; i < info.count; i++) {
                    car = get_car(m.value, i);
                    if (car->state == 0) {
                        fn_1_8E084(car, &total, i);
                    }
                }
            }
        }
    }
}
/* fzgx:end fn_1_8DD54 */
