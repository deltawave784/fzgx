#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/custom_memcard.h"
#include "font.h"
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_1_AA6D8(s32 arg0, u8 arg1, void* arg2);
extern u32 lbl_801A6410;
extern u32 fn_1_4630();
extern int fn_1_B7E98(int index);
extern void fn_1_13198C(s16, u32*, u32*, u32, u32, u32);
extern u32 lbl_1_rodata_8694[4];
extern u32 lbl_1_rodata_86A4[4];
extern const f64 lbl_1_rodata_8600;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_8658;
extern const f32 lbl_1_rodata_86B4;
extern const f32 lbl_1_rodata_86B8;
extern const f32 lbl_1_rodata_86BC;
extern const f32 lbl_1_rodata_86C0;
extern const f32 lbl_1_rodata_86C4;
extern const f32 lbl_1_rodata_86C8;
extern const f32 lbl_1_rodata_86CC;
extern const f32 lbl_1_rodata_86D0;
extern const f32 lbl_1_rodata_86D4;
extern f32 lbl_1_rodata_26F8[22];
extern int fn_1_D66B0(void);
extern u8 fn_1_D6740(u8);
extern void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth);
extern u32 fn_1_5158C(FontDrawPacket *, u32, u32, u32);
extern char *strncpy(char *dst, const char *src, size_t n);
extern void fn_1_50164();
extern void fn_1_49410(void);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_495C8(u8 value);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_49590(f32 value);
extern void fn_1_4965C(u8 value);
extern void fn_1_495B0(u32 value);
extern void fn_1_4CE48(Obj_1_bss_4B9CC *obj, f32 limit);
extern u8 fn_1_B7C00(void);
extern s32 fn_1_B7CD4(void);
extern u32 fn_1_B7C5C(void);
extern void OSReport(const char *format, ...);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u32 lbl_1_bss_8CA6C[1605];
extern void fn_1_1324C4(void *arg0);
extern void fn_1_132774(void *arg0);

/* fzgx:begin fn_1_1312F0 */
// Reset the memcard state after reporting an unavailable card.

void fn_1_1312F0(void) {
    u8* state = (u8*)&lbl_1_bss_8CA40;
    void* memcard;

    if (fn_1_B7C00() == 0) {
        if (fn_1_B7CD4() == 0) {
            OSReport((const char*)lbl_1_data_40EF8, (s32)fn_1_B7C5C());
        }

        memcard = *(void**)(state + 0x18);
        *(s32*)(state + 0x00) = -1;
        *(s32*)(state + 0x08) = -1;
        *(s32*)(state + 0x0c) = 0;
        if (memcard != 0) {
            fn_1_46B4(lbl_801A6410, (u32)(void*)(memcard), (const char *)(u8*)(lbl_1_data_40EA4), 0x136);
            *(void**)(state + 0x18) = 0;
        }
    }
}
/* fzgx:end fn_1_1312F0 */

/* fzgx:begin fn_1_131390 noprologue */
#include "types.h"
#include "dolphin/os/OSTime.h"

typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u8 pad_0C[4];
    u32 unk_10;
    u8 pad_14[4];
    void* unk_18;
} CustomMemcardState;

struct Ptr { u32 unk_0; };

extern CustomMemcardState lbl_1_bss_8CA40;
extern struct Ptr lbl_801A6410;
extern u8 lbl_1_data_40EA4[0x54];
extern u8 lbl_1_data_40F0C[0x22];

extern void OSPanic(const char* arg0, s32 arg1, const char* arg2, ...);
extern void fn_80008BEC(void* dst, s32 value, u32 size);
extern void* fn_1_4630(u32, u32, const char*, s32);
extern void fn_1_AA6D8(s32 arg0, u8 arg1, void* arg2);

void fn_1_131390(void) {
    CustomMemcardState* state = &lbl_1_bss_8CA40;
    OSCalendarTime cal;
    u8 request[0x24];

    if (state->unk_10 == 0) {
        OSPanic((const char*)lbl_1_data_40EA4, 0x147, (const char*)lbl_1_data_40F0C);
        state->unk_00 = -1;
        state->unk_08 = -1;
        state->unk_10 = 0;
    } else if (state->unk_08 == -1) {
        state->unk_00 = -1;
    } else {
        state->unk_18 = fn_1_4630(lbl_801A6410.unk_0, 0x20700, (const char*)lbl_1_data_40EA4, 0x154);
        fn_80008BEC(state->unk_18, 0, 0x20700);
        OSTicksToCalendarTime(OSGetTime(), &cal);
        fn_80008BEC(request, 0, 0x24);
        *(u32*)(request + 4) = 0x104;
        request[0] = 3;
        *(void**)(request + 0xC) = state->unk_18;
        *(u32*)(request + 8) = 0;
        fn_1_AA6D8(2, (u8)state->unk_08, request);
        state->unk_04 = 5;
    }
}
/* fzgx:end fn_1_131390 */

/* fzgx:begin fn_1_1314A4 */
// Reset the card state and release the card after an unavailable-card report.
void fn_1_1314A4(void) {
    u8* state = (u8*)&lbl_1_bss_8CA40;
    void* card;

    if (fn_1_B7C00() == 0) {
        if (fn_1_B7CD4() == 0) {
            OSReport((const char*)lbl_1_data_40EF8, (s32)fn_1_B7C5C());
        }

        fn_80008BA8( (u32)(void*)(*(void**)(state + 0x10)), (u32)(void*)(*(void**)(state + 0x18)), (s32)(0x20700));

        card = *(void**)(state + 0x18);
        *(s32*)(state + 0x00) = -1;
        *(s32*)(state + 0x08) = -1;
        *(void**)(state + 0x10) = 0;

        if (card != 0) {
            fn_1_46B4(lbl_801A6410, (u32)(void*)(card), (const char *)(u8*)(lbl_1_data_40EA4), 0x188);
            *(void**)(state + 0x18) = 0;
        }
    }
}
/* fzgx:end fn_1_1314A4 */

/* fzgx:begin fn_1_131558 noprologue */
#include "types.h"

typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u8 pad_0C[8];
    u32 unk_14;
    u8 pad_18[0x128];
    u8 unk_140[0x1800];
} CustomMemcardState;

extern CustomMemcardState lbl_1_bss_8CA40;
extern u8 lbl_1_data_40EA4[84];
extern char lbl_1_data_40F30[34];

extern void OSPanic(const char* arg0, s32 arg1, const char* arg2, ...);
extern void fn_80008BEC(void* dst, s32 value, u32 size);
extern void fn_1_AA6D8(s32 arg0, u8 arg1, void* arg2);

void fn_1_131558(void) {
    CustomMemcardState* state = &lbl_1_bss_8CA40;
    u8 request[0x24];

    if (state->unk_14 == 0) {
        OSPanic((const char*)lbl_1_data_40EA4, 0x197, (const char*)lbl_1_data_40F30);
        state->unk_00 = -1;
        state->unk_08 = -1;
    } else if (state->unk_08 == -1) {
        state->unk_00 = -1;
    } else {
        fn_80008BEC(state->unk_140, 0, 0x1800);
        fn_80008BEC(request, 0, 0x24);
        request[0] = 3;
        *(void**)((u8*)request + 0x0C) = state->unk_140;
        fn_1_AA6D8(4, (u8)state->unk_08, request);
        state->unk_04 = 7;
    }
}
/* fzgx:end fn_1_131558 */

/* fzgx:begin fn_1_131620 pool noprologue */
#include "types.h"

typedef struct {
    u8 pad_00[0x24];
    u32 unk_24;
    u8 pad_28[4];
    u32 unk_2c;
} MemEntry;

typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u8 pad_0C[8];
    u32* unk_14;
    u8 pad_18[0x128];
    MemEntry unk_140[0x80];
} CustomMemcardState;

extern u8 lbl_1_data_40EF8[0x11];
extern u8 lbl_1_data_40EA4[0x54];
extern u32 lbl_801A6410;

extern u8 fn_1_B7C00(void);
extern s32 fn_1_B7CD4(void);
extern u32 fn_1_B7C5C(void);
extern void fn_1_46B4(u32, u32, const char*, int);
extern void OSReport(const char*, ...);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
s32 fzgx_obj_lbl_1_bss_8CA40;
u32 lbl_1_bss_8CA44;
s32 lbl_1_bss_8CA44_4;
u32 lbl_1_bss_8CA44_fill_8CA4C[2];
u32*lbl_1_bss_8CA44_10;
u32 lbl_1_bss_8CA44_fill_8CA58[5];
u32 lbl_1_bss_8CA6C[69];
MemEntry lbl_1_bss_8CA6C_114[0x80];
u8 fzgx_obj_lbl_1_bss_8E380;
u8 lbl_1_bss_8CA40_gap_8E381;
u16 lbl_1_bss_8CA40_gap_8E381_fill_8E382;
u32 fzgx_obj_lbl_1_bss_8E384[17];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8CA40;
    s = *(u8 *)&lbl_1_bss_8CA44;
    s = *(u8 *)&lbl_1_bss_8CA44_4;
    s = *(u8 *)&lbl_1_bss_8CA44_fill_8CA4C;
    s = *(u8 *)&lbl_1_bss_8CA44_10;
    s = *(u8 *)&lbl_1_bss_8CA44_fill_8CA58;
    s = *(u8 *)&lbl_1_bss_8CA6C;
    s = *(u8 *)&lbl_1_bss_8CA6C_114;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E380;
    s = *(u8 *)&lbl_1_bss_8CA40_gap_8E381;
    s = *(u8 *)&lbl_1_bss_8CA40_gap_8E381_fill_8E382;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E384;
}
#pragma section code_type ".text"

void fn_1_131620(void) {
    
    u32 i;
    MemEntry* e_2;
    MemEntry* e;
    u32 lab_t1;

    if (fn_1_B7C00()) {
        return;
    }
    if (fn_1_B7CD4() == 0) {
        lab_t1 = fn_1_B7C5C();
        OSReport((const char*)lbl_1_data_40EF8, lab_t1);
        e = lbl_1_bss_8CA6C_114;
        for (i = 0; i < 0x80; i++, e++) {
            if (e->unk_24 != 0) {
                fn_1_46B4(lbl_801A6410, e->unk_2c, (const char*)lbl_1_data_40EA4, 0x1c9);
            }
        }
        fzgx_obj_lbl_1_bss_8CA40 = -1;
    } else {
        e_2 = lbl_1_bss_8CA6C_114;
        for (i = 0; i < 0x80; i++, e_2++) {
            if (e_2->unk_24 != 0) {
                lbl_1_bss_8CA44_10[i] = e_2->unk_2c;
            } else {
                lbl_1_bss_8CA44_10[i] = 0;
            }
        }
        fzgx_obj_lbl_1_bss_8CA40 = -1;
        lbl_1_bss_8CA44_4 = -1;
    }
}
/* fzgx:end fn_1_131620 */

/* fzgx:begin fn_1_1317B4 */
u32 fn_1_1317B4(void) {
    return lbl_1_bss_8CA6C[0];
}
/* fzgx:end fn_1_1317B4 */

/* fzgx:begin fn_1_1317C4 */
typedef struct {
    u8 unk_0;
    u8 pad_1[3];
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u8 pad_10[0x14];
} MemcardRequest;

void fn_1_1317C4(void) {
    MemcardRequest request;

    lbl_1_bss_8E384.unk_0 = fn_1_4630(
        lbl_801A6410, 0x20700, (*(u8 (*)[84])&lbl_1_data_40EA4), 0x1f3);

    fn_80008BEC(&request, 0, 0x24);
    request.unk_4 = 4;
    request.unk_4 |= 0x4000;
    request.unk_4 |= 0x2000;
    request.unk_0 = 3;
    request.unk_C = lbl_1_bss_8E384.unk_0;
    request.unk_8 = 0;

    if (fn_1_B7E98(0) != 0) {
        fn_1_AA6D8(2, 0, &request);
    } else if (fn_1_B7E98(1) != 0) {
        fn_1_AA6D8(2, 1, &request);
    } else {
        fn_1_AA6D8(2, 0, &request);
    }

    lbl_1_bss_8E380 = 1;
}
/* fzgx:end fn_1_1317C4 */

/* fzgx:begin fn_1_1318B8 */
u8 fn_1_1318B8(void) {
    return lbl_1_bss_8E380 != 0;
}
/* fzgx:end fn_1_1318B8 */

/* fzgx:begin fn_1_1318D4 */
// Completes the pending memory-card operation and clears its active flag.
s32 fn_1_1318D4(void) {
    s32 error;

    if (lbl_1_bss_8E380 == 0) {
        return 0;
    }

    if (fn_1_B7C00() != 0) {
        return 1;
    }

    if (fn_1_B7CD4() == 0) {
        error = (s32)fn_1_B7C5C();
        OSReport((const char*)lbl_1_data_40EF8, error);
    }

    if (lbl_1_bss_8E384.unk_0 != 0) {
        fn_1_46B4(lbl_801A6410, (u32)((void*)lbl_1_bss_8E384.unk_0), (const char *)(u8*)(lbl_1_data_40EA4), 0x22b);
        lbl_1_bss_8E384.unk_0 = 0;
    }

    lbl_1_bss_8E380 = 0;
    return 1;
}
/* fzgx:end fn_1_1318D4 */

/* fzgx:begin fn_1_13198C noprologue */
#include "types.h"
#include "rel/main_rel/custom_memcard.h"
#include "game/main_rel/car_test_types.h"

typedef struct Sig_fn_8006F038_Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Sig_fn_8006F038_Vec3;

typedef struct {
    u32 w[3];
} Fn13198CTriple;

extern const Fn13198CTriple lbl_1_rodata_8610;
extern const f32 lbl_1_rodata_861C;

extern void OSReport(const char *, ...);
extern void fn_8006F038(Sig_fn_8006F038_Vec3 *, Sig_fn_8006F038_Vec3 *, s16);
extern void lbl_8006DCDC(void);
extern void fn_1_F7870(void *);
extern void lbl_8006D7DC(Fn13198CTriple *);
extern void lbl_8006DB74(void *);
extern void fn_1_8E728(u8 *, u8);
extern void fn_1_13C134(void);
extern void fn_1_9250C(void *);
extern void fn_1_13C16C(void);
extern s32 fn_1_12CB04(s16);

void fn_1_13198C(s16 id, Sig_fn_8006F038_Vec3 *a, Sig_fn_8006F038_Vec3 *b, u8 *objs, u8 *others, s32 mode) {
    s32 off;
    s16 slot;
    u8 *obj;
    s16 bit;
    s16 j;
    u8 *p;
    Fn13198CTriple tri;
    f32 mtx[3][4];

    off = id * 32;
    slot = *(s16 *)((u8 *)&lbl_1_bss_8B3A0 + off + 0xE);
    if ((lbl_1_bss_8B3A0.unk_94 & 0x80000000) != 0) {
        return;
    }
    if (slot == -1) {
        return;
    }
    obj = objs + id * 0x4E0;
    if (obj == NULL) {
        OSReport((const char *)&lbl_1_data_41928);
        return;
    }
    fn_8006F038(a, b, 0);
    lbl_8006DCDC();
    fn_1_F7870(&lbl_1_data_1E5C0);
    tri = lbl_1_rodata_8610;
    lbl_8006D7DC(&tri);
    lbl_8006DB74(mtx);
    for (bit = 0; bit < 8; bit++) {
        if (*((((0x14) + ((u8 *)&lbl_1_bss_8B3A0)) + (off))) & (1 << bit)) {
            break;
        }
    }
    bit %= 4;
    lbl_8006DFE8((Fn183D28Vec3 *)mtx);
    *(f32 *)(obj + 0xA8) = lbl_1_rodata_861C;
    *(f32 *)(obj + 0xAC) = lbl_1_rodata_861C;
    *(f32 *)(obj + 0xB0) = lbl_1_rodata_861C;
    fn_1_8E728(obj, bit);
    if (mode == 1) {
        fn_1_13C134();
    }
    fn_1_9250C(obj);
    if (mode == 1) {
        fn_1_13C16C();
    }
    for (j = 0; j < (s16)fn_1_12CB04(slot); j++) {
        p = others + (s16)id * 0x9C0 + j * 0x4E0;
        if (p != NULL) {
            *(f32 *)(p + 0xA8) = lbl_1_rodata_861C;
            *(f32 *)(p + 0xAC) = lbl_1_rodata_861C;
            *(f32 *)(p + 0xB0) = lbl_1_rodata_861C;
            if (p[0x98] != bit) {
                fn_1_8E728(p, bit);
            }
            if (mode == 1) {
                fn_1_13C134();
            }
            fn_1_9250C(p);
            if (mode == 1) {
                fn_1_13C16C();
            }
        }
        p += 0x4E0;
    }
}
/* fzgx:end fn_1_13198C */

/* fzgx:begin fn_1_131B90 */
typedef struct Obj Obj;

struct Obj {
    s16 index;
    u8 pad_2[2];
    u32 field_4;
    u32 field_8;
    u8 pad_c[0x2c];
    u32 field_38;
    u32 field_3c;
    u32 field_40;
    u32 field_44;
    u32 field_48;
    u32 field_4c;
    u32 field_50[1];
};


#pragma opt_propagation off
s32 fn_1_131B90(Obj* obj) {
    u32 local_a[3];
    u32 local_b[3];
    u32 a0;
    u32 a1;
    u32 b0;
    u32 b1;
    s16 index;

    a1 = obj->field_44;
    a0 = obj->field_48;
    local_b[0] = a1;
    local_b[1] = a0;
    local_b[2] = obj->field_4c;
    b1 = obj->field_38;
    b0 = obj->field_3c;
    local_a[0] = b1;
    local_a[1] = b0;
    local_a[2] = obj->field_40;
    index = obj->index;
    fn_1_13198C(index, local_a, local_b, obj->field_4, obj->field_8,
                obj->field_50[index]);
    return 0;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_131B90 */

/* fzgx:begin fn_1_131C08 noprologue */
#include "types.h"
#include "rel/main_rel/custom_memcard.h"
#include "game/main_rel/shadowmap_types.h"

typedef struct Sig_fn_8006F038_Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Sig_fn_8006F038_Vec3;

struct fn_1_131C08_lbl_1_bss_8B3A0_0_E32 {
    u8 pad_0[0xE];
    s16 unk_E;
    u8 pad_10[4];
    u8 unk_14;
    u8 pad_15[0xB];
};
struct fn_1_131C08_Arg0 {
    s16 unk_0;
    u8 pad_2[0xA];
    fn_1_568F8_Data *unk_C;
    void *unk_10;
    s16 unk_14;
    u8 pad_16[6];
    void *unk_1C;
    u8 pad_20[0x18];
    Sig_fn_8006F038_Vec3 unk_38;
    Sig_fn_8006F038_Vec3 unk_44;
    u32 unk_50[4];
    u8 pad_60[4];
    s16 unk_64;
};

typedef struct {
    u8 pad_0[0x320];
    s16 unk_320;
    u8 pad_322[0x6E];
    u32 unk_390;
    u8 pad_394[0x26];
    s16 unk_3BA;
} Sig_fn_1_FCFA4_CasTarget;
typedef struct {
    u8 unk_0[0x40F0];
    u32 unk_40F0;
    u8 pad_40F4[0xC];
} Sig_fn_1_FCFA4_CasEntry;
typedef struct Sig_fn_1_FCFA4_CasObj {
    Sig_fn_1_FCFA4_CasTarget *unk_0;
    u8 unk_4;
    u8 pad_5[7];
    u32 unk_C;
    u8 pad_10[0x10];
    Sig_fn_1_FCFA4_CasEntry entries[4];
    s32 (*unk_10420)(void);
    s32 (*unk_10424)(struct Sig_fn_1_FCFA4_CasObj *);
    u8 pad_10428[4];
    void (*unk_1042C)(struct Sig_fn_1_FCFA4_CasObj *, Sig_fn_1_FCFA4_CasEntry *);
} Sig_fn_1_FCFA4_CasObj;

extern int fn_1_D6698(void);
extern int fn_1_D66B0(void);
extern u32 lbl_801A66A0;
extern u8 lbl_1_bss_8E3C8[8];
extern s16 lbl_1_bss_96A;
extern void *lbl_801A6D00;
extern const f32 lbl_1_rodata_8620;
extern const f64 lbl_1_rodata_8628;
extern const f32 lbl_1_rodata_8630;
extern const f32 lbl_1_rodata_8634;
extern const f32 lbl_1_rodata_8638;
extern const f32 lbl_1_rodata_863C;
extern void fn_1_D66F8(u8, u8 *, s8 *);
extern void fn_1_F7870(void *);
extern void fn_8006F038(Sig_fn_8006F038_Vec3 *, Sig_fn_8006F038_Vec3 *, s16);
extern void lbl_8006DCDC(void);
extern void lbl_8006D758(void);
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern void lbl_8006E14C(f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DFE8(void *);
extern void fn_80072558(void);
extern void fn_1_13C134(void);
extern void fn_1_13C16C(void);
extern void fn_1_870BC(fn_1_568F8_Data *, s8, fn_1_568F8_Data *, s32, u8, f32);
extern void *fn_1_12F118(void);
extern u8 *fn_1_36AD0(void);
extern u8 fn_1_D66B8(u8);
extern void fn_1_151BDC(void *);
extern void fn_1_14E2DC(void *, s16, f32);
extern Sig_fn_1_FCFA4_CasObj *fn_1_13F8B0(u8);
extern Sig_fn_1_FCFA4_CasObj *fn_1_7F428(u32);
extern void fn_1_FCFA4(Sig_fn_1_FCFA4_CasObj *);
extern void fn_1_FD27C(Sig_fn_1_FCFA4_CasObj *, Sig_fn_1_FCFA4_CasEntry *);
extern void fn_1_FDD7C(Sig_fn_1_FCFA4_CasObj *, Sig_fn_1_FCFA4_CasEntry *);

#pragma fp_contract off
static inline void fn_1_131C08_update(u32 index, s32 active)
{
    if (active == 0) {
        ((u16 *)lbl_1_bss_8E3C8)[index] = (s32)(lbl_1_rodata_8620 * (f32)(lbl_801A66A0 % 360));
    } else {
        u16 *angles = (u16 *)lbl_1_bss_8E3C8;
        s32 angle = angles[index];
        if (angle < 0x7555) {
            angles[index] = (s32)((f64)(u32)angle + lbl_1_rodata_8628 * (lbl_1_rodata_8630 - (f32)(u32)angle));
        } else {
            angles[index] = (s32)((f64)(u32)angle + lbl_1_rodata_8628 * (lbl_1_rodata_8634 - (f32)(u32)angle));
        }
    }
}

s32 fn_1_131C08(struct fn_1_131C08_Arg0 *arg0, f32 arg1)
{
    Obj_1_bss_8B3A0 *p_lbl_1_bss_8B3A0;
    s16 v0;
    s16 v7;
    s32 v2;
    u8 v6;
    u32 v12;
    s32 v13;
    u8 loc_9;
    s8 loc_8;
    f32 matrix[3][4];
    fn_1_568F8_Data *model;
    u8 *pool;
    u8 *entry;
    s16 index;
    s16 selected;
    Sig_fn_1_FCFA4_CasObj *object;
    Sig_fn_1_FCFA4_CasTarget *target;
    u8 oldMode;
    u32 flags;
    u32 bit = 1;
    u8 bits;

    v0 = arg0->unk_0;
    v7 = ((struct fn_1_131C08_lbl_1_bss_8B3A0_0_E32 *)&lbl_1_bss_8B3A0)[v0].unk_E;
    v2 = arg0->unk_50[v0];
    v6 = 0;
    while (v6 < 8) {
        bits = ((struct fn_1_131C08_lbl_1_bss_8B3A0_0_E32 *)&lbl_1_bss_8B3A0)[v0].unk_14;
        if (bits & (bit << v6)) {
            break;
        }
        v6++;
    }
    p_lbl_1_bss_8B3A0 = (Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0;
    if ((p_lbl_1_bss_8B3A0->unk_94 & 0x40000000) && !(u8)fn_1_D6698()) {
        if (arg0->unk_64 != (u8)fn_1_D66B0()) {
            fn_1_D66F8((u8)arg0->unk_64, &loc_9, &loc_8);
            if ((s8)loc_9 != -1) {
                v6 = loc_8;
                v7 = (s8)loc_9;
            }
        }
    }
    if (p_lbl_1_bss_8B3A0->unk_94 & 0x80000000) return 0;
    if (v7 == -1) return 0;
    fn_8006F038(&arg0->unk_38, &arg0->unk_44, 0);
    lbl_8006DCDC();
    fn_1_F7870(&lbl_1_data_1E5C0);
    if ((p_lbl_1_bss_8B3A0->unk_94 & 0x40000000) && !(u8)fn_1_D6698()) {
        v12 = arg0->unk_64;
        v13 = 0;
        if (v12 == (u8)fn_1_D66B0()) {
            s16 active;
            if (lbl_1_bss_960 == 1) {
                s32 activeOffset = lbl_1_bss_962 * 0x94;
                u8 *activeData = (u8 *)lbl_1_bss_8B3A0.unk_A4;
                activeData += activeOffset;
                active = *(s16 *)(activeData - 0x7F4);
            } else {
                active = *(s16 *)arg0->unk_1C;
            }
            if (active) v13 = 1;
        }
        fn_1_131C08_update(v12, v13);
    } else {
        s16 active;
        v12 = v0;
        if (lbl_1_bss_960 == 1) {
            s32 activeOffset = lbl_1_bss_962 * 0x94;
            u8 *activeData = (u8 *)lbl_1_bss_8B3A0.unk_A4;
            u8 *activeAddress = activeData + activeOffset;
            activeAddress += v0 * 0x1C;
            active = *(s16 *)(activeAddress - 0x7F4);
        } else {
            active = *(s16 *)((u8 *)arg0->unk_1C + v0 * 0x1C);
        }
        fn_1_131C08_update(v12, active);
    }
    lbl_8006D758();
    mathutil_mtxA_rotate_x(0xEAAA);
    mathutil_mtxA_rotate_y((s16)((u16 *)lbl_1_bss_8E3C8)[v12]);
    lbl_8006E14C(lbl_1_rodata_8638);
    lbl_8006DB74((u8 *)lbl_801A6D00 + 0x60);
    lbl_8006DB74(matrix);
    if (v7 < 0x29) {
        model = (fn_1_568F8_Data *)((u8 *)arg0->unk_C + v7 * 0x440);
        if (!model) return 0;
        lbl_8006DFE8((u8 *)lbl_801A6D00 + 0x60);
        fn_80072558();
        if (v2 == 1) fn_1_13C134();
        fn_1_870BC(model, (s8)arg0->unk_14, model, 0, v6, lbl_1_rodata_863C);
        if (v2 == 1) fn_1_13C16C();
    } else if ((s16)lbl_1_bss_962 != 0x14 && (s16)lbl_1_bss_96A != 0x14) {
        index = v7 - 0x29;
        entry = fn_1_12F118();
        if (entry == fn_1_36AD0()) {
            if ((p_lbl_1_bss_8B3A0->unk_94 & 0x40000000)) {
                if ((u8)fn_1_D6698()) index = v0;
                else index = fn_1_D66B8((u8)arg0->unk_64);
            } else index = v0;
        }
        entry += index * 0x81C0;
        if (!(*(u32 *)entry & 0x80000000)) return 0;
        lbl_8006DFE8((u8 *)lbl_801A6D00 + 0x60);
        fn_80072558();
        if (*(u32 *)entry & 0x40000000) {
            fn_1_151BDC(entry);
            fn_1_14E2DC((u8 *)arg0->unk_10 + index * 0xA20, arg0->unk_14, lbl_1_rodata_863C);
        } else {
            model = (fn_1_568F8_Data *)((u8 *)arg0->unk_C + entry[0x81A0] * 0x440);
            fn_1_870BC(model, (s8)arg0->unk_14, model, 0, v6, lbl_1_rodata_863C);
        }
    }
    if ((s16)lbl_1_bss_962 != 0x14 && (s16)lbl_1_bss_96A != 0x14) {
        pool = fn_1_12F118();
        selected = v0;
        if (lbl_1_bss_962 == 0x10) {
            if (v7 < 0x29) return 0;
            v0 = v7 - 0x29;
            selected = v0;
        }
        if (!pool) return 0;
        entry = pool + v0 * 0x81C0;
        if (!(*(u32 *)entry & 0x80000000)) return 0;
        if (lbl_1_bss_962 == 0x10 || lbl_1_bss_962 == 0x12) {
            if (lbl_1_bss_962 == 0x10 && lbl_1_bss_8B3A0.unk_0 == 0) return 0;
            if (selected >= 8) return 0;
            if (entry[7] == 0) return 0;
            lbl_8006DFE8(matrix);
            fn_80072558();
            if (fn_1_13F8B0((u8)selected)) {
                fn_1_FCFA4(fn_1_13F8B0((u8)selected));
            }
        } else if (lbl_1_bss_962 == 0x24) {
            object = fn_1_7F428((u8)selected);
            if (!object) return 0;
            target = object->unk_0;
            if (selected >= 4) return 0;
            if (entry[7] == 0) return 0;
            if (!target) return 0;
            if (object) {
                oldMode = target->unk_3BA;
                flags = object->unk_C;
                lbl_8006DFE8(matrix);
                fn_80072558();
                if (lbl_1_bss_8B3A0.unk_0 == 0) {
                    target->unk_3BA = 1;
                } else {
                    target->unk_390 &= ~0x200000;
                    target->unk_3BA = 0;
                }
                object->unk_1042C = fn_1_FD27C;
                object->unk_C = 0x20000000;
                fn_1_FCFA4(object);
                object->unk_1042C = fn_1_FDD7C;
                object->unk_C = flags;
                target->unk_3BA = oldMode;
            }
        }
    }
    return 0;
}
/* fzgx:end fn_1_131C08 */

/* fzgx:begin fn_1_132488 */
void fn_1_132488(void *arg0) {
    if ((lbl_1_bss_8B3A0.unk_94 & 0x40000000) != 0) {
        fn_1_1324C4(arg0);
    } else {
        fn_1_132774(arg0);
    }
}
/* fzgx:end fn_1_132488 */

/* fzgx:begin fn_1_132FB4 */
#pragma opt_common_subs off
#pragma opt_propagation off
void fn_1_132FB4(void) {
    FontDrawPacket packet;
    char buf[17];
    u32 tblA[4];
    u32 tblB[4];
    s32 var_r31;
    s32 var_r30;
    s32 var_r29;
    s32 var_r28;
    char *pbuf;
    f32 lab_t0;
    u32 var_r26;
    f32 lab_t1;

    var_r29 = 0;
    var_r28 = 0;
    var_r26 = 0;
    var_r31 = 0x18;
    var_r30 = 0x43;

    tblA[0] = lbl_1_rodata_8694[0];
    tblA[1] = lbl_1_rodata_8694[1];
    tblA[2] = lbl_1_rodata_8694[2];
    tblA[3] = lbl_1_rodata_8694[3];
    tblB[0] = lbl_1_rodata_86A4[0];
    tblB[1] = lbl_1_rodata_86A4[1];
    tblB[2] = lbl_1_rodata_86A4[2];
    tblB[3] = lbl_1_rodata_86A4[3];

    pbuf = buf;

    do {
        if (var_r29 == (u8)fn_1_D66B0()) {
            var_r28 += 1;
            var_r26 += 4;
        } else if (fn_1_D6740(var_r29) != 0) {
            fn_80008BEC(pbuf, 0, 0x11);
            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0x10000 - 0x61EC;
            fn_1_51564(0, 0, 0x18, 0x14, 2, 2);
            fn_1_5158C(&packet, packet.image, (s16)(var_r28 % 2), (s16)(var_r28 / 2));
            packet.x = (f32)var_r31;
            packet.y = lbl_1_rodata_86B4;
            fn_1_4F734(&packet);
            strncpy(pbuf, (const char *)(*(u32 *)((u8 *)tblA + var_r26)), 0x10);
            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 12;
            *(u32 *)((u8 *)&packet + 0x30) = 5;
            packet.x = (f32)var_r31;
            packet.y = lbl_1_rodata_86B8;
            fn_1_50164(lbl_1_rodata_86BC, lbl_1_rodata_86C0, lbl_1_rodata_86C4, lbl_1_rodata_86C4, &packet);
            fn_1_49410();
            fn_1_496FC((f32)var_r30, lbl_1_rodata_86C8);
            fn_1_495C8(1);
            fn_1_4955C(lbl_1_rodata_86CC, lbl_1_rodata_86CC);
            fn_1_49590(lbl_1_rodata_85F0);
            fn_1_4965C(2);
            fn_1_495B0((0x3u << 30));
            fn_1_4CE48((Obj_1_bss_4B9CC *)pbuf, lbl_1_rodata_86D0);
            fn_1_49410();
            lab_t0 = (f32)var_r30;
            fn_1_496FC(lab_t0, lbl_1_rodata_8658);
            fn_1_495C8(1);
            fn_1_4955C(lbl_1_rodata_86D4, lbl_1_rodata_86D4);
            fn_1_49590(lbl_1_rodata_85F0);
            fn_1_4965C(2);
            fn_1_495B0((0x3u << 30));
            lab_t1 = lbl_1_rodata_86D0;
            fn_1_4CE48((Obj_1_bss_4B9CC *)(*(u32 *)((u8 *)tblB + var_r26)), lab_t1);
            var_r31 += 0x57;
            var_r30 += 0x57;
            var_r28 += 1;
            var_r26 += 4;
        }
        var_r29 += 1;
    } while (var_r29 < 4);
}
#pragma opt_propagation reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_132FB4 */

/* fzgx:begin fn_1_137364 */
// Writes the indexed three-byte value, or the fallback value when the index is out of range.
void fn_1_137364(s16 arg0, u8* arg1, u8* arg2, u8* arg3) {
    if (arg0 < 0x29) {
        u32* values = (u32*)&lbl_1_data_416B8;

        *arg1 = values[arg0 * 3];
        *arg2 = values[arg0 * 3 + 1];
        *arg3 = values[arg0 * 3 + 2];
    } else {
        *arg2 = 2;
        *arg1 = 2;
        *arg3 = 2;
    }
}
/* fzgx:end fn_1_137364 */

/* fzgx:begin fn_1_13F7F8 */
u32 fn_1_13F7F8(s16 arg0, s16 arg1) {
    return ((u32 (*)[6])&lbl_1_data_414D8)[arg0][arg1];
}
/* fzgx:end fn_1_13F7F8 */
