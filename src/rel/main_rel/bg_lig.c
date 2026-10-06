#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_lig.h"

typedef struct {
    u8 pad_000[0x6c0];
    f32 threshold;
} fn_1_D8784_LigObject;

typedef struct {
    u8 pad_00[0x68];
    u32 field_68;
    u8 pad_6c[0x40];
} fn_1_D8CA8_LigEntry;

typedef struct {
    u8 pad_00[0x6d4];
    s32 count;
    fn_1_D8CA8_LigEntry entries[1];
} fn_1_D8CA8_LigObject;

typedef struct {
    u8 pad0[0x24];
    f32 value;
    u8 pad28[0x4];
    s16 count;
    u8 pad2e[0x2];
} fn_1_D7B7C_LigEntry;

typedef struct {
    u8 pad0[0x4];
    void (*callback)(void);
    fn_1_D7B7C_LigEntry *entry;
} LigEvent;

typedef struct {
    u8 data[0xac];
} fn_1_D8D08_LigEntry;

typedef struct {
    u8 pad[0x6d4];
    s32 count;
    fn_1_D8D08_LigEntry entries[1];
} LigContainer;

typedef struct {
    u8 unk_0[0xac];
} fn_1_D8EEC_LigEntry;

typedef struct {
    u8 unk_0[0x6d4];
    s32 unk_6d4;
    fn_1_D8EEC_LigEntry unk_6d8[1];
} fn_1_D8EEC_LigObject;

struct fn_1_D66F8_lbl_801A66A0 {
    u32 unk_0;
};

typedef struct {
    u8 pad_000[0x2c];
    f32 x;
    f32 y;
    f32 z;
    u8 pad_038[0x74];
} fn_1_D8D58_LigEntry;

typedef struct {
    f32 pos[3];
    f32 vel[3];
    f32 scale[3];
    f32 value;
    s16 phase;
    s16 step;
    s16 count;
    u8 pad2e[0x2];
} fn_1_D7A10_LigEntry;

typedef struct {
    u8 pad_000[0x6d4];
    s32 count;
    fn_1_D8D58_LigEntry entries[1];
} LigObject;
extern s32 fn_1_58C4();
extern void fn_1_9A508(void);
extern f32 lbl_1_rodata_64A0[33];
extern void fn_1_D79E4(void *obj);
extern u8 fn_1_5300(void);
extern void fn_1_77B80(u32 arg0);
extern void fn_1_76BF8(void);
extern void fn_1_72648(void);
extern void fn_1_D8CA8(fn_1_D8CA8_LigObject *obj);
extern void fn_1_4404(void);
extern u32 fn_1_DA6A8(void *, u32);
extern void fn_1_D9224(void *, u32);
extern void fn_1_446C(void);
extern void fn_1_D9D8C(Obj_1_bss_7AD78 *obj, u32 arg, s32 index);
extern void fn_1_DA3A0(Obj_1_bss_7AD78 *obj);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u32 lbl_1_rodata_6490[4];
extern u32 lbl_801A63D0;
extern u32 fn_1_76504(s32, void *, s32);
extern void fn_1_7269C(u32 arg0, u32 arg1, void *arg2);
extern void fn_1_5948(s32 index);
extern void fn_1_D8388();
extern void fn_1_627C(s32 index);
extern u32 fn_1_9D260();
extern void fn_1_D7B7C(fn_1_D7B7C_LigEntry *base);
extern void fn_1_9AD88(void);
extern void *memset(void *dst, int value, u32 size);
extern void fn_1_D7EF4(void *, u32);
extern f32 lbl_1_rodata_6594[];
extern void lbl_8006DCA4(void);
extern s32 fn_1_54E34(void *arg0, f32 arg1);
extern void **fn_1_54448(s32 arg0);
extern void * fn_1_548AC(u32 amount);
extern void fn_1_D8878(void);
extern void fn_1_5489C(void **arg0, void **arg1);
extern void fn_1_D8D08(LigContainer *container);
extern void fn_1_D8784(fn_1_D8784_LigObject *obj);
extern void fn_1_D8EEC(fn_1_D8EEC_LigObject *obj, void *arg);
extern f32 lbl_1_rodata_6524[];
extern void *fn_1_5448C(fn_1_D7B7C_LigEntry *entry);
extern void fn_1_D7C44(void);
extern void fn_1_103090(fn_1_D8CA8_LigEntry *entry);
extern void fn_1_1030A4(fn_1_D8D08_LigEntry *entry);
extern struct fn_1_D66F8_lbl_801A66A0 lbl_801A66A0;
extern f32 lbl_8006D188(s32 value);
extern void fn_1_1030D4(fn_1_D8D58_LigEntry *entry, void *arg);
extern void fn_1_103264(fn_1_D8EEC_LigEntry *entry, void *arg);
extern void fn_1_D83E4(Obj_1_data_2A7E0_At3C *obj, s32 index);
extern void fn_1_D7A10(fn_1_D7A10_LigEntry *base);
extern void fn_1_D8D58(LigObject *obj, void *arg);
extern void fn_1_E87FC(void);
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_1_rodata_6358;

/* fzgx:begin fn_1_D5C70 */
typedef struct {
    u32 unk0;
    void *data;
    u32 unk8;
    u32 flags;
    u8 rest[0xac - 0x10];
} Elem;

#define IDX (*(s32 *)(p - 0x1820))
#define FLAG(idx) (((Elem *)(p - 0x1820))[idx].flags)
#define DATA(idx) (((Elem *)(p - 0x1820))[idx].data)
#define SB0 (*(s16 *)(p - 0x1888))
#define SB1 (*(s16 *)(p - 0x1886))

s32 fn_1_D5C70(u32 arg0, u32 *arg1) {
    u8 *p;
    u8 *scan;

    p = (u8 *)lbl_1_data_2A7E0.unk_3C + 0x10000;

    switch (arg0) {
    case 0:
        FLAG(IDX) |= 0x40000000;
        FLAG(IDX) |= 0x10000000;
        DATA(IDX) = arg1;
        IDX = IDX + 1;
        if (IDX >= 32) {
            OSPanic((const char *)lbl_1_data_3DBE8, 0x577, (const char *)lbl_1_data_3DBF4);
        }
        break;
    case 1:
        FLAG(IDX) |= 0x40000000;
        FLAG(IDX) |= 0x20000000;
        DATA(IDX) = arg1;
        IDX = IDX + 1;
        if (IDX >= 32) {
            OSPanic((const char *)lbl_1_data_3DBE8, 0x57e, (const char *)lbl_1_data_3DBF4);
        }
        break;
    case 2:
        FLAG(IDX) |= 0x40000000;
        FLAG(IDX) |= 0x10000000;
        FLAG(IDX) |= 0x08000000;
        DATA(IDX) = arg1;
        IDX = IDX + 1;
        if (IDX >= 32) {
            OSPanic((const char *)lbl_1_data_3DBE8, 0x586, (const char *)lbl_1_data_3DBF4);
        }
        break;
    case 3:
        FLAG(IDX) |= 0x40000000;
        FLAG(IDX) |= 0x20000000;
        FLAG(IDX) |= 0x08000000;
        DATA(IDX) = arg1;
        IDX = IDX + 1;
        if (IDX >= 32) {
            OSPanic((const char *)lbl_1_data_3DBE8, 0x58e, (const char *)lbl_1_data_3DBF4);
        }
        break;
    case 5:
        *arg1 |= 0x01000000;
        break;
    case 6:
        if (fn_1_58C4() <= 2) {
            *arg1 |= 0x02000000;
            SB0 = 0x1b;
            SB1 = 0x28;
        } else {
            *arg1 &= ~0x02000000;
        }
        break;
    case 7:
    case 8:
    case 9:
        if (fn_1_58C4() <= 2) {
            *arg1 |= 0x02000000;
            SB0 = 0x18;
            SB1 = 0x18;
        } else {
            *arg1 &= ~0x02000000;
        }
        break;
    case 10:
        scan = (u8 *)lbl_1_bss_3BE0->unk_54;
        *(s32 *)(p - 0x29c) = 0;
        while (scan != (u8 *)arg1) {
            scan += 0x40;
            *(s32 *)(p - 0x29c) = *(s32 *)(p - 0x29c) + 1;
        }
        *arg1 |= 0x80000000;
        break;
    default:
        break;
    }
    return 1;
}
/* fzgx:end fn_1_D5C70 */

/* fzgx:begin fn_1_D6680 */
// fn_1_D6680: returns a constant.
int fn_1_D6680(void) {
    return 0;
}
/* fzgx:end fn_1_D6680 */

/* fzgx:begin fn_1_D6688 */
// fn_1_D6688: returns a constant.
int fn_1_D6688(void) {
    return 1;
}
/* fzgx:end fn_1_D6688 */

/* fzgx:begin fn_1_D6690 */
// fn_1_D6690: returns a constant.
int fn_1_D6690(void) {
    return 0;
}
/* fzgx:end fn_1_D6690 */

/* fzgx:begin fn_1_D6698 */
// fn_1_D6698: returns a constant.
int fn_1_D6698(void) {
    return 0;
}
/* fzgx:end fn_1_D6698 */

/* fzgx:begin fn_1_D66A0 */
// fn_1_D66A0: returns a constant.
int fn_1_D66A0(void) {
    return 0;
}
/* fzgx:end fn_1_D66A0 */

/* fzgx:begin fn_1_D66A8 */
// fn_1_D66A8: returns a constant.
int fn_1_D66A8(void) {
    return 0;
}
/* fzgx:end fn_1_D66A8 */

/* fzgx:begin fn_1_D66B0 */
// fn_1_D66B0: returns a constant.
int fn_1_D66B0(void) {
    return 0;
}
/* fzgx:end fn_1_D66B0 */

/* fzgx:begin fn_1_D66B8 */
// fn_1_D66B8: empty in retail (single blr).
void fn_1_D66B8(void) {
}
/* fzgx:end fn_1_D66B8 */

/* fzgx:begin fn_1_D66BC */
int fn_1_D66BC(void *unused, void *arg)
{
    fn_80008BA8( (u32)(void *)(arg), (u32)(void *)(lbl_1_data_3DC38), 0x10);
    return 1;
}
/* fzgx:end fn_1_D66BC */

/* fzgx:begin fn_1_D66F4 */
// fn_1_D66F4: empty in retail (single blr).
void fn_1_D66F4(void) {
}
/* fzgx:end fn_1_D66F4 */

/* fzgx:begin fn_1_D66F8 */
struct fn_1_D66F8_Arg1 {
    u8 unk_0;
};
struct fn_1_D66F8_Arg2 {
    u8 unk_0;
};

void fn_1_D66F8(u8 arg0, u8 *arg1, s8 *arg2) {
    u32 sp8;

    sp8 = *(u32 *)((u8 *)(&lbl_1_rodata_6358) + 0);
    (*(u8 *)((u8 *)(arg1) + 0)) = *(u8 *)((u8 *)(((u8 *)(&sp8) + arg0)) + 0);
    (*(s8 *)((u8 *)(arg2) + 0)) = ((u32) lbl_801A66A0.unk_0 / (u32) ((arg0 + 1) * 0x1E)) & 3;
}
/* fzgx:end fn_1_D66F8 */

/* fzgx:begin fn_1_D6740 */
// fn_1_D6740: returns a constant.
int fn_1_D6740(void) {
    return 1;
}
/* fzgx:end fn_1_D6740 */

/* fzgx:begin fn_1_D720C */
void fn_1_D720C(void) {
    u32 local[4];
    u32 result;

    local[0] = lbl_1_rodata_6490[0];
    local[1] = lbl_1_rodata_6490[1];
    local[2] = lbl_1_rodata_6490[2];
    local[3] = lbl_1_rodata_6490[3];
    result = fn_1_76504(0x1d, local, 0);
    fn_1_7269C(result, 0, (void *)(u32)(lbl_801A63D0));
}
/* fzgx:end fn_1_D720C */

/* fzgx:begin fn_1_D7274 */
#pragma opt_dead_assignments off
#pragma opt_pointer_analysis on
void fn_1_D7274(void) {
    Obj_1_data_2A7E0_At3C *obj;
    Obj_1_bss_7AD78 *state;
    Obj_1_bss_7AD78 *state2;
    s32 i;
    s32 mode;

    mode = fn_1_58C4();
    obj = lbl_1_data_2A7E0.unk_3C;
    obj->unk_6D4 = 0;
    fn_1_9A508();
    obj->unk_6C0 = (0.0f);
    fn_1_D79E4( (void *)(Obj_1_data_2A7E0_At3C *)(obj));

    if (obj->unk_6CC != 0
        && (mode == 1 || (mode == 2 && fn_1_5300() == 1))) {
        fn_1_77B80(obj->unk_6CC);
    } else {
        fn_1_76BF8();
        fn_1_72648();
    }

    fn_1_D8CA8( (fn_1_D8CA8_LigObject *)(Obj_1_data_2A7E0_At3C *)(obj));
    fn_1_4404();

    if (lbl_1_bss_7AD78.unk_14 != 0) {
        fn_1_DA6A8(&lbl_1_bss_7AD78, obj->unk_1C58);
        fn_80008BEC(&lbl_1_bss_7AD78, (u32)(0), 0x20);
    }

    if (lbl_1_bss_7AD78.unk_34 != 0) {
        state = &lbl_1_bss_7AD78;
        state2 = (Obj_1_bss_7AD78 *)((u8 *)state + 0x20);
        fn_1_DA6A8(state2, obj->unk_1C5C);
        fn_80008BEC(state2, (u32)(0), 0x20);
    }

    if (obj->unk_1C58 != 0) {
        fn_80008BEC(&lbl_1_bss_7AD78, (u32)(0), 0x20);
        fn_1_D9224(&lbl_1_bss_7AD78, obj->unk_1C58);
    }

    if (obj->unk_1C5C) {
        state2 = (Obj_1_bss_7AD78 *)((u8 *)&lbl_1_bss_7AD78 + 0x20);
        fn_80008BEC(state2, (u32)(0), 0x20);
        fn_1_D9224(state2, obj->unk_1C5C);
    }

    fn_1_446C();
    state = &lbl_1_bss_7AD78;
    state2 = (Obj_1_bss_7AD78 *)((u8 *)state + 0x20);
    for (i = 0; i < 0x78; i++) {
        if (obj->unk_1C58 != 0) {
            fn_1_D9D8C( (Obj_1_bss_7AD78 *)(void *)(state), obj->unk_1C58, 0);
            fn_1_DA3A0( (Obj_1_bss_7AD78 *)(void *)((&lbl_1_bss_7AD78)));
        }
        if (obj->unk_1C5C != 0) {
            fn_1_D9D8C( (Obj_1_bss_7AD78 *)(void *)(state2), obj->unk_1C5C, 1);
            fn_1_DA3A0( (Obj_1_bss_7AD78 *)(void *)(state2));
        }
    }
}
#pragma opt_pointer_analysis reset

#pragma opt_dead_assignments reset
/* fzgx:end fn_1_D7274 */

/* fzgx:begin fn_1_D744C */
// Initializes each available background-light entry.
void fn_1_D744C(void) {
    Obj_1_data_2A7E0_At3C *obj;
    s32 count;
    s32 i;

    obj = lbl_1_data_2A7E0.unk_3C;
    count = fn_1_58C4();
    for (i = 0; i < count; i++) {
        fn_1_5948(i);
        fn_1_D8388(obj, i);
        fn_1_627C(i);
    }
}
/* fzgx:end fn_1_D744C */

/* fzgx:begin fn_1_D74C4 */
// Initializes background-light data and installs the completion callback.
void fn_1_D74C4(void) {
    Obj_1_bss_7AD78 *tmp;
    Obj_1_data_2A7E0_At3C *obj;
    Obj_1_data_2A7E0_At3C *arg;
    s32 count;
    s32 i;

    obj = lbl_1_data_2A7E0.unk_3C;
    arg = (Obj_1_data_2A7E0_At3C *)fn_1_9D260(&lbl_1_data_2A7E0);
    fn_1_9AD54();
    count = fn_1_58C4();
    for (i = 0; i < count; i++) {
        fn_1_5948(i);
        fn_1_D83E4(obj, i);
        fn_1_627C(i);
    }

    fn_1_D7A10( (fn_1_D7A10_LigEntry *)(Obj_1_data_2A7E0_At3C *)(obj));
    fn_1_D8D58( (LigObject *)(Obj_1_data_2A7E0_At3C *)(obj), (void *)(Obj_1_data_2A7E0_At3C *)(arg));
    if (obj->unk_1C58 != 0) {
        fn_1_D9D8C(&lbl_1_bss_7AD78, obj->unk_1C58, 0);
        fn_1_DA3A0(&lbl_1_bss_7AD78);
    }
    if (obj->unk_1C5C != 0) {
        tmp = (Obj_1_bss_7AD78 *)((u8 *)&lbl_1_bss_7AD78 + 0x20);
        fn_1_D9D8C(tmp, obj->unk_1C5C, 1);
        fn_1_DA3A0(tmp);
    }
    lbl_1_data_2A7E0.unk_2C = (u32)fn_1_E87FC;
}
/* fzgx:end fn_1_D74C4 */

/* fzgx:begin fn_1_D75CC */
typedef struct {
    u8 data[0xac];
} Sig_fn_1_D8D08_fn_1_D8D08_LigEntry;

typedef struct {
    u8 pad[0x6d4];
    s32 count;
    Sig_fn_1_D8D08_fn_1_D8D08_LigEntry entries[1];
} Sig_fn_1_D8D08_LigContainer;

struct fn_1_D75CC_lbl_1_data_2A7E0 {
    u8 pad_0[0x3C];
    u32 unk_3C;
};


void fn_1_D75CC(void) {
    u32 *temp_r31;
    u32 temp_r30;
    u32 temp_r4;
    u32 temp_r4_2;

    temp_r30 = (*(struct fn_1_D75CC_lbl_1_data_2A7E0 *)&lbl_1_data_2A7E0).unk_3C;
    fn_1_4404();
    temp_r4 = *(u32 *)((u8 *)(temp_r30) + 7256);
    if (temp_r4 != 0) {
        fn_1_DA6A8((void *)(&(*(u32 *)&lbl_1_bss_7AD78)), temp_r4);
        fn_80008BEC((void *)(&(*(u32 *)&lbl_1_bss_7AD78)), 0, 0x20U);
        (*(u32 *)((u8 *)(temp_r30) + 7256)) = 0U;
    }
    temp_r4_2 = *(u32 *)((u8 *)(temp_r30) + 7260);
    if (temp_r4_2 != 0) {
        temp_r31 = (u32 *)((u8 *)(&(*(u32 *)&lbl_1_bss_7AD78)) + 0x20);
        fn_1_DA6A8((void *)(temp_r31), temp_r4_2);
        fn_80008BEC((void *)(temp_r31), 0, 0x20U);
        (*(u32 *)((u8 *)(temp_r30) + 7260)) = 0U;
    }
    fn_1_446C();
    fn_1_76BF8();
    fn_1_72648();
    fn_1_D8D08( (LigContainer *)((Sig_fn_1_D8D08_LigContainer *)((Sig_fn_1_D8D08_LigContainer *)(temp_r30))));
}
/* fzgx:end fn_1_D75CC */

/* fzgx:begin fn_1_D7688 */
void fn_1_D7688(void) {
    Obj_1_data_2A7E0_At3C *obj = lbl_1_data_2A7E0.unk_3C;
    void *value = (void *)fn_1_9D260(&lbl_1_data_2A7E0);
    fn_1_D8784( (fn_1_D8784_LigObject *)(Obj_1_data_2A7E0_At3C *)(obj));
    fn_1_D7B7C( (fn_1_D7B7C_LigEntry *)(Obj_1_data_2A7E0_At3C *)(obj));
    fn_1_D8EEC( (fn_1_D8EEC_LigObject *)(Obj_1_data_2A7E0_At3C *)(obj), value);
    fn_1_9AD88();
}
/* fzgx:end fn_1_D7688 */

/* fzgx:begin fn_1_D76EC */
// fn_1_D76EC: empty in retail (single blr).
void fn_1_D76EC(void) {
}
/* fzgx:end fn_1_D76EC */

/* fzgx:begin fn_1_D76F0 */
// Copies a three-component float vector into the indexed light buffer entry.
void fn_1_D76F0(const f32 *src, s16 index) {
    f32 *dst = (f32 *)lbl_1_data_2A7E0.unk_3C;

    dst[index * 3] = src[0];
    dst += index * 3;
    dst[1] = src[1];
    dst[2] = src[2];
}
/* fzgx:end fn_1_D76F0 */

/* fzgx:begin fn_1_D7724 */
typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Vec3Bits;

// Copies the indexed three-word light entry to the caller-provided buffer.
void fn_1_D7724(Vec3Bits *dst, s16 index) {
    u32 *base = (u32 *)lbl_1_data_2A7E0.unk_3C;
    Vec3Bits *src = (Vec3Bits *)(base + index * 3);

    *dst = *src;
}
/* fzgx:end fn_1_D7724 */

/* fzgx:begin fn_1_D79E4 */
void fn_1_D79E4(void *obj) {
    memset((u8 *)obj + 0x30, 0, 0x3c0);
}
/* fzgx:end fn_1_D79E4 */

/* fzgx:begin fn_1_D7A10 */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[4] = {0x00000000, 0x0280012C, 0x00000000, 0x00000001};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 100.0f;
    s = 3.0f;
}
static const u32 fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.7;
    d = 0.3;
    s = 32767.0f;
    s = 235.0f;
    s = 80.0f;
    s = 30.0f;
    d = 512.0;
    d = 0.5;
    d = 300.0;
    d = 17.0;
    s = 3276.800048828125f;
}
static const u32 fzgx_pool_table5[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    d = 0.98;
    s = 0.07999999821186066f;
}
static const u32 fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.99;
    d = 0.02;
    s = 400.0f;
    s = 0.7071067690849304f;
}
#pragma section code_type ".text"


// Steps every active light particle: damps and gravity-biases the velocity,
// advances the position, decays the phase step and fades the scale out
// over the last 80 frames of the particle's life.
void fn_1_D7A10(fn_1_D7A10_LigEntry *base) {
    fn_1_D7A10_LigEntry *entry;
    s32 i;
    f32 fade;
    f64 delta;

    for (i = 0; i < 0x14; i++) {
        entry = base + i + 1;
        if (entry->count > 0) {
            entry->vel[0] *= 0.98;
            entry->vel[1] *= 0.98;
            entry->vel[2] *= 0.98;
            entry->vel[1] -= 0.08f;
            entry->pos[0] += entry->vel[0];
            entry->pos[1] += entry->vel[1];
            entry->pos[2] += entry->vel[2];
            entry->phase += entry->step;
            entry->step *= 0.99;
            delta = 0.02 * (400.0f - entry->value);
            entry->value = entry->value + delta;
            if (entry->count < 0x50) {
                fade = entry->count / 80.0f;
                entry->scale[0] *= fade;
                entry->scale[1] *= fade;
                entry->scale[2] *= fade;
            }
            if (entry->count > 0) {
                entry->count--;
            }
        }
    }
}
/* fzgx:end fn_1_D7A10 */

/* fzgx:begin fn_1_D7B7C */
void fn_1_D7B7C(fn_1_D7B7C_LigEntry *base) {
    void *data;
    fn_1_D7B7C_LigEntry *entry;
    s32 i;
    LigEvent *event;

    lbl_8006DCA4();

    for (i = 0; i < 0x14; i++) {
        entry = base + i + 1;
        if (entry->count > 0 &&
            fn_1_54E34( (void *)(fn_1_D7B7C_LigEntry *)(entry), (*(f32 (*)[28])&lbl_1_rodata_6524)[0] * entry->value)) {
            data = fn_1_5448C(entry);
            event = (LigEvent *)fn_1_548AC(0xc);
            if (event != 0) {
                event->callback = fn_1_D7C44;
                event->entry = entry;
                fn_1_5489C( (void **)(void *)(data), (void **)(void *)(event));
            }
        }
    }
}
/* fzgx:end fn_1_D7B7C */

/* fzgx:begin fn_1_D8388 */
// Initializes each lighting entry while the lighting system is available.
void fn_1_D8388(void *obj) {
    u8 *entry = (u8 *)obj;
    s32 i;

    if ((u32)fn_1_58C4() < 2) {
        i = 0;
        do {
            fn_1_D7EF4(entry + 0x3f0, 0);
            i++;
            entry += 0x30;
        } while (i < 0xf);
    }
}
/* fzgx:end fn_1_D8388 */

/* fzgx:begin fn_1_D8784 */
typedef void (*LigCallback)(void);

typedef struct {
    u32 unk_00;
    LigCallback callback;
    void *data;
} LigCallbackObject;

typedef struct {
    u8 pad_000[0x3f0];
    u8 callback_data[0x24];
    f32 scale;
} fn_1_D8784_LigEntry;



// Queues callbacks for eligible lig entries.
void fn_1_D8784(fn_1_D8784_LigObject *obj) {
    void *callback_data;
    void *owner;
    u8 i;
    f32 factor;
    fn_1_D8784_LigEntry *entry;

    if ((u32)fn_1_58C4(obj) >= 2) {
        return;
    }
    if (obj->threshold < lbl_1_rodata_6594[0]) {
        return;
    }

    factor = lbl_1_rodata_6524[0];
    i = 0;
    for (; i < 0xf; i++) {
        lbl_8006DCA4();
        entry = (fn_1_D8784_LigEntry *)((u8 *)obj + (i * 0x30));
        callback_data = entry->callback_data;
        if (fn_1_54E34(callback_data, factor * entry->scale) != 0) {
            owner = (void *)fn_1_54448(0);
            {
                LigCallbackObject *callback = (LigCallbackObject *)fn_1_548AC( (s32)(0xc));
                if (callback != 0) {
                    callback->callback = fn_1_D8878;
                    callback->data = callback_data;
                    fn_1_5489C( (void **)(void *)(owner), (void **)(void *)(callback));
                }
            }
        }
    }
}
/* fzgx:end fn_1_D8784 */

/* fzgx:begin fn_1_D8CA8 */
void fn_1_D8CA8(fn_1_D8CA8_LigObject *obj) {
    s32 count = obj->count;
    fn_1_D8CA8_LigEntry *entry = obj->entries;

    while (count > 0) {
        entry->field_68 = 1;
        fn_1_103090(entry);
        count--;
        entry++;
    }
}
/* fzgx:end fn_1_D8CA8 */

/* fzgx:begin fn_1_D8D08 */
void fn_1_D8D08(LigContainer *container) {
    s32 count = container->count;
    fn_1_D8D08_LigEntry *entry = container->entries;

    while (count > 0) {
        fn_1_1030A4(entry);
        count--;
        entry++;
    }
}
/* fzgx:end fn_1_D8D08 */

/* fzgx:begin fn_1_D8D58 */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[4] = {0x00000000, 0x0280012C, 0x00000000, 0x00000001};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 100.0f;
    s = 3.0f;
}
static const u32 fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.7;
    d = 0.3;
    s = 32767.0f;
    s = 235.0f;
    s = 80.0f;
    s = 30.0f;
    d = 512.0;
    d = 0.5;
    d = 300.0;
    d = 17.0;
    s = 3276.800048828125f;
}
static const u32 fzgx_pool_table5[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    d = 0.98;
    s = 0.07999999821186066f;
}
static const u32 fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.99;
    d = 0.02;
    s = 400.0f;
    s = 0.7071067690849304f;
    s = 1.0f;
}
static const u32 fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table11[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.5f;
    s = 0.5f;
    s = 10.0f;
    s = 5.0f;
    s = 0.6000000238418579f;
    s = 170.0f;
    s = 120.0f;
    s = 32.0f;
    s = 90.0f;
    s = 0.4000000059604645f;
    s = 768.0f;
}
static const u32 fzgx_pool_table13[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.05;
    s = 2.5f;
    s = 0.10000000149011612f;
    s = 50.0f;
    s = 20.0f;
    s = 70.0f;
    s = 33.0f;
    s = 15.0f;
    s = 0.6499999761581421f;
    s = 0.75f;
    s = 182.04444885253906f;
}
#pragma section code_type ".text"





void fn_1_D8D58(LigObject *obj, void *arg) {
    s32 count = obj->count;
    fn_1_D8D58_LigEntry *entry = obj->entries;

    while (count > 0) {
        u32 flags = *(u32 *)((u8 *)entry + 8);

        if ((flags >> 28) & 1) {
            f32 x = 0.65f;
            f32 y = 0.75f;
            entry->x = x;
            entry->y = y;
            entry->z = 1.0f;
        } else if ((flags >> 29) & 1) {
            f32 x = 1.0f;
            f32 y = 0.0f;
            entry->x = x;
            entry->y = y;
            entry->z = y;
        } else {
            entry->x = __fabs(lbl_8006D188(
                (s32)((f32)(*(u32 *)&lbl_801A66A0) * 182.04444885253906f)));
            entry->y = __fabs(lbl_8006D188(
                (s32)((f32)(*(u32 *)&lbl_801A66A0) * 182.04444885253906f * 0.5)));
            entry->z = __fabs(lbl_8006D188(
                (s32)((f32)(*(u32 *)&lbl_801A66A0) * 182.04444885253906f * 2.0)));
        }

        fn_1_1030D4(entry, arg);
        count--;
        entry++;
    }
}
/* fzgx:end fn_1_D8D58 */

/* fzgx:begin fn_1_D8EEC */
// Applies the operation to each entry in the object.
void fn_1_D8EEC(fn_1_D8EEC_LigObject *obj, void *arg) {
    s32 count = obj->unk_6d4;
    fn_1_D8EEC_LigEntry *entry = obj->unk_6d8;

    while (count > 0) {
        fn_1_103264(entry, arg);
        count--;
        entry++;
    }
}
/* fzgx:end fn_1_D8EEC */

/* fzgx:begin fn_1_D8F4C */
typedef struct {
    u8 pad_0[0x24];
    u32 unk_24;
} FnInputData;

typedef struct {
    FnInputData *unk_0;
} FnInput;

u32 fn_1_D8F4C(s32 index, FnInput *input) {
    FnInputData *data = input->unk_0;
    Obj_1_data_2A7E0_At3C *state = lbl_1_data_2A7E0.unk_3C;
    u32 value = data->unk_24;

    switch (index) {
    case 0:
        state->unk_6CC = value;
        break;
    case 1:
        state->unk_6D0 = value;
        break;
    case 2:
        if (state->unk_1C58 == 0) {
            state->unk_1C58 = (u32)data;
        }
        break;
    case 3:
        if (state->unk_1C5C == 0) {
            state->unk_1C5C = (u32)data;
        }
        break;
    }

    return 1;
}
/* fzgx:end fn_1_D8F4C */
