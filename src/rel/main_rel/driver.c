#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/driver.h"
#include "game/main_rel/driver_types.h"

extern void fn_80006E10(u32 arg0);
extern s32 fn_1_12C930(s8);
extern s16 fn_1_12CCB0(s16 arg0, s16 arg1);
extern int sprintf(char *s, const char *format, ...);
extern void fn_1_D3884();
extern u32 fn_80077D40(void);
extern u32 fn_80071470(u32, u32);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern void fn_80071718(void *value);
extern void fn_1_A8270(void *, void *);
extern void *lbl_801A6410;
extern u32 fn_1_4630();
extern void fn_1_A8528(void *, void *);
extern u32 lbl_8006D91C(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern void mathutil_mtxA_rotate_x(u32);
extern u32 lbl_8006D998(u32);
extern void lbl_8006DBAC(void *arg0);
extern void lbl_8006DB74(void *);
extern void mathutil_mtxA_rotate_z(s32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DFC4(void *pos);
extern void lbl_8006DB30(void);
extern void fn_1_A9420(u8 value);
extern s32 fn_8008077C(u32 arg0, u32 arg1, u32 arg2);
extern void fn_1_A948C(int);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16 index);
extern void fn_1_520A0(void);
extern void fn_1_52088(void);
extern u32 lbl_1_bss_71658[6];
extern const f64 lbl_1_rodata_4A98;
extern void fn_1_49714(f32 value1, f32 value2, f32 value3);
extern void fn_1_49680(f32 value1, f32 value2);
extern void fn_1_A93C4(u32 arg0);
extern void fn_1_4A0D8(void *);
extern void fn_1_520CC(void);
extern void fn_1_49514(u32 *value);
extern void (*lbl_1_bss_7168C)(void);
extern u32 GXLoadPosMtxImm(u32, u32);
extern u32 fn_800720B0(u32);
extern void fn_80072EDC(s32 arg0, s32 arg1);
extern void fn_1_A714C(f32 *a, f32 *b, f32 *c, f32 *d);
extern void fn_80038CFC(u32 value);
extern void fn_8006F1F0(void *, void *, void *);
extern void fn_8007245C(u32 value);
extern void fn_8007264C(u32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80073678(u32 arg0);
extern void fn_80073898(u32 arg0);
extern void fn_80073C6C(s32 index);
extern void fn_80074660(u32 arg0);
extern void fn_800746A8();
extern void fn_80074718(u8 value, s32 arg);
extern void fn_80074788(u32 arg0);
extern void fn_800747D0(u32 arg0, u32 arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern void OSReport(const char *format, ...);
extern void fn_800711A8(void *value);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_1_A7E60(s32 arg0, s8 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void lbl_8006E0A4(void *arg0);
extern void fn_8006F6A8(void *arg0);
extern void fn_1_A89B0(void *arg0, void *arg1, s32 arg2);
extern void fn_1_3920(void);
extern void fn_1_A8D4C(void);
extern void fn_1_A8D64(void);
extern u32 fn_8001A78C(u32 arg0);
extern u32 fn_8001A7D0(u32 arg0);
extern void fn_1_A943C(u32 arg0, u32 arg1);
extern void fn_1_A9464(u16 arg0, u16 arg1);
extern void fn_1_A942C(u8 value);
extern void fn_1_A96BC(void);
extern void (*lbl_1_bss_7167C)(void);
extern void fn_1_A5C98(void *);
extern u8 lbl_1_bss_716C8[320];
extern void (*lbl_1_bss_71680)(void);
extern u32 fn_1_451C(void);
extern void fn_1_A5AA0(void *buffer, void *destination);
extern u32 lbl_1_bss_71670;
extern void (*lbl_1_bss_71684)(void);
extern void (*lbl_1_bss_71688)(void);
extern u32 fn_1_A7024(f32, f32, f32, f32);
extern f32 lbl_1_rodata_4AC4[4];
extern void fn_8003462C(u32, u32, u32);

/* fzgx:begin fn_1_A75DC noprologue */
#include "dolphin/types.h"

/* strings of this TU's .data cluster, addressed off one base register */
typedef struct {
    u8 pad_0[0x18];
    char fmt_plain[0xC];   /* 0x18 */
    char fmt_named[0x10];  /* 0x24 */
    char msg_begin[0x8];   /* 0x34 */
    char msg_end[0x8];     /* 0x3C */
} DriverStrings;

extern u8 lbl_1_data_34348[];
extern char *lbl_1_data_20D1C[0x2D];

typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;
} DriverAsset;

typedef struct {
    u8 pad_0[0x108];
    DriverAsset *unk_108;
} DriverSlot;

typedef struct {
    u8 pad_0[0x328];
    s8 unk_328;
    u8 pad_329[0x394 - 0x329];
    DriverSlot *unk_394[3];
} Driver;

extern void fn_80006E10(char *);
extern s32 fn_1_12C930(s8);
extern s32 fn_1_12CCB0(s8, s16);
extern int sprintf(char *, const char *, ...);
extern DriverAsset *fn_1_D3884(char *);
extern u32 fn_80077D40(void);
extern u32 fn_80071470(u32, u32);
extern void fn_80008BA8(u32, u32, u32);
extern void fn_80071718(DriverAsset *);

void fn_1_A75DC(Driver *driver, s32 variant)
{
    DriverStrings *str = (DriverStrings *)lbl_1_data_34348;
    DriverSlot *slot;
    s32 i;
    Driver *d;
    s32 id;
    s32 heap;
    DriverAsset *asset;
    u32 src;
    u32 dst;
    s8 index;
    char buf[128];

    fn_80006E10(str->msg_begin);
    id = driver->unk_328;
    d = driver;
    for (i = 0; i < 3; i++, d = (Driver *)((u8 *)d + 4)) {
        slot = d->unk_394[0];
        if (slot == NULL) {
            continue;
        }
        if (i == 0) {
            index = fn_1_12C930(id);
        } else {
            index = fn_1_12CCB0(id, (s16)(i - 1));
        }
        if (index < 0) {
            continue;
        }
        if (variant == 0) {
            sprintf(buf, str->fmt_plain, lbl_1_data_20D1C[index]);
        } else {
            sprintf(buf, str->fmt_named, lbl_1_data_20D1C[index], variant);
        }
        asset = fn_1_D3884(buf);
        fn_80008BA8(fn_80071470(slot->unk_108->unk_8, 0), fn_80071470(asset->unk_8, 0), fn_80077D40());
        fn_80071718(asset);
    }
    fn_80006E10(str->msg_end);
}
/* fzgx:end fn_1_A75DC */

/* fzgx:begin fn_1_A7728 */
typedef struct FnA7728Resource {
    u8 pad_104[0x104];
    void *field_104;
    void *field_108;
} FnA7728Resource;

typedef struct FnA7728Object {
    u8 pad_394[0x394];
    FnA7728Resource *field_394;
} FnA7728Object;

void fn_1_A7728(FnA7728Object *objects) {
    u8 *object;
    s32 index;

    object = (u8 *)objects;
    index = 0;
    for (;;) {
        if (((FnA7728Object *)object)->field_394 != 0) {
            if (((FnA7728Object *)object)->field_394->field_108 != 0) {
                fn_80071718(((FnA7728Object *)object)->field_394->field_108);
                ((FnA7728Object *)object)->field_394->field_108 = 0;
            }
            if (((FnA7728Object *)object)->field_394->field_104 != 0) {
                fn_800711A8(((FnA7728Object *)object)->field_394->field_104);
                ((FnA7728Object *)object)->field_394->field_104 = 0;
            }
            fn_1_46B4( (u32)(void *)(lbl_801A6410), (u32)(void *)(((FnA7728Object *)object)->field_394), (const char *)(void *)(lbl_1_data_34354), 0x115);
            ((FnA7728Object *)object)->field_394 = 0;
        }
        index++;
        object += 4;
        if (index >= 3) {
            break;
        }
    }
}
/* fzgx:end fn_1_A7728 */

/* fzgx:begin fn_1_A77DC */
typedef struct FnA77DCObject {
    u8 pad_32c[0x32c];
    void *field_32c;
    u8 pad_330[0x64];
    void *field_394[3];
    u8 pad_3a0[0x1a];
    s16 field_3ba;
} FnA77DCObject;

void fn_1_A77DC(FnA77DCObject *object) {
    s32 index;

    if (object->field_3ba == 0 || object->field_3ba == 1) {
        for (index = 0; index < 3; index++) {
            if (object->field_394[index] != 0) {
                fn_1_A8528(object->field_394[index], object->field_32c);
            }
        }
    }
}
/* fzgx:end fn_1_A77DC */

/* fzgx:begin fn_1_A7854 */
typedef struct FnA7854Object {
    u8 pad_394[0x394];
    void *item;
    u8 pad_398[0x22];
    s16 field_3ba;
} FnA7854Object;


void fn_1_A7854(FnA7854Object *object, void *arg1) {
    FnA7854Object *cursor;
    s32 index;

    if (object->field_3ba == 0 || object->field_3ba == 1) {
        index = 0;
        cursor = object;
        do {
            if (cursor->item != 0) {
                fn_1_A8270(cursor->item, arg1);
            }
            index++;
            cursor = (FnA7854Object *)((u8 *)cursor + 4);
        } while (index < 3);
    }
}
/* fzgx:end fn_1_A7854 */

/* fzgx:begin fn_1_A78CC */
void fn_1_A78CC(void) {
    u32 **table;
    s32 offset;
    s32 index;

    lbl_1_bss_6F638 = (u32)fn_1_4630(lbl_801A6410, 0xb0, (((u8 *)&lbl_1_data_34354)), 0x145);
    table = (u32 **)&lbl_1_bss_6F638;
    index = 0;
    offset = 0;
    do {
        *(u32 *)((u8 *)*table + offset) =
            (u32)fn_1_4630(lbl_801A6410, 0x30c, (((u8 *)&lbl_1_data_34354)), 0x147);
        index++;
        offset += 4;
    } while (index < 0x2c);
}
/* fzgx:end fn_1_A78CC */

/* fzgx:begin fn_1_A7968 */
void fn_1_A7968(void) {
    s32 **table;
    s32 offset;
    s32 index;

    table = (s32 **)&lbl_1_bss_6F638;
    offset = 0;
    index = 0;
    do {
        fn_1_A7E60(41, (s8)index, *(s32 *)((u8 *)*table + offset), -1, 0);
        index++;
        offset += 4;
    } while (index < 44);
}
/* fzgx:end fn_1_A7968 */

/* fzgx:begin fn_1_A79D8 */
typedef struct fn_1_A79D8_Vec {
    u32 x;
    u32 y;
    u32 z;
} fn_1_A79D8_Vec;

typedef struct fn_1_A79D8_Obj {
    u8 pad[0x114];
    fn_1_A79D8_Vec v;
} fn_1_A79D8_Obj;


void fn_1_A79D8(s32 index, fn_1_A79D8_Vec *vec) {
    fn_1_A79D8_Obj *obj;
    fn_1_A79D8_Vec saved;

    obj = ((fn_1_A79D8_Obj **)lbl_1_bss_6F638)[index];
    saved = obj->v;
    obj->v = *vec;
    fn_1_A8528(obj, 0);
    fn_1_A8270(obj, 0);
    obj->v = saved;
}
/* fzgx:end fn_1_A79D8 */

/* fzgx:begin fn_1_A7A70 */
void fn_1_A7A70(void) {
    s32 index;
    u32 *entries;

    for (index = 0; index < 0x2c; index++) {
        entries = (u32 *)lbl_1_bss_6F638;
        if (entries[index] != 0) {
            fn_1_46B4( (u32)(void *)(lbl_801A6410), (u32)((void *)entries[index]), (const char *)(void *)(lbl_1_data_34354), 0x168);
            entries = (u32 *)lbl_1_bss_6F638;
            entries[index] = 0;
        }
    }

    if (lbl_1_bss_6F638 != 0) {
        fn_1_46B4( (u32)(void *)(lbl_801A6410), (u32)((void *)lbl_1_bss_6F638), (const char *)(void *)(lbl_1_data_34354), 0x169);
        lbl_1_bss_6F638 = 0;
    }
}
/* fzgx:end fn_1_A7A70 */

/* fzgx:begin fn_1_A7B30 noprologue */
#include "types.h"

typedef struct FnA7B30Vector {
    s32 x;
    s32 y;
    s32 z;
} FnA7B30Vector;

extern FnA7B30Vector lbl_1_data_35864[];

void fn_1_A7B30(s32 index, FnA7B30Vector *out) {
    *out = lbl_1_data_35864[index - 25];
}
/* fzgx:end fn_1_A7B30 */

/* fzgx:begin fn_1_A7F84 */
void fn_1_A7F84(void *arg0, u32 arg1) {
    switch (arg1) {
    case 0:
        lbl_8006D91C(0U);
        mathutil_mtxA_rotate_y(0U);
        mathutil_mtxA_rotate_x((u32) (*(s16 *)((u8 *)(arg0) + 0)));
        return;
    case 1:
        lbl_8006D91C(0x4000U);
        mathutil_mtxA_rotate_y((u32) (*(s16 *)((u8 *)(arg0) + 2)));
        mathutil_mtxA_rotate_x(0x4000U);
        return;
    case 2:
        lbl_8006D998(0x4000U);
        mathutil_mtxA_rotate_y((u32) (*(s16 *)((u8 *)(arg0) + 4)));
        mathutil_mtxA_rotate_x(0U);
        (*(f32 *)((u8 *)((*((struct fn_1_A7F84_lbl_801A6D00 *)&lbl_801A6D00)).unk_0) + 12)) = (f32) lbl_1_rodata_4A28.unk_0;
        (*(f32 *)((u8 *)((*((struct fn_1_A7F84_lbl_801A6D00 *)&lbl_801A6D00)).unk_0) + 28)) = (f32) (*(f32 *)((u8 *)(arg0) + 28));
        (*(f32 *)((u8 *)((*((struct fn_1_A7F84_lbl_801A6D00 *)&lbl_801A6D00)).unk_0) + 44)) = (f32) (*(f32 *)((u8 *)(arg0) + 32));
        return;
    case 3:
        lbl_8006D998((u32) (*(s16 *)((u8 *)(arg0) + 10)));
        mathutil_mtxA_rotate_y((u32) (*(s16 *)((u8 *)(arg0) + 8)));
        mathutil_mtxA_rotate_x((u32) (*(s16 *)((u8 *)(arg0) + 6)));
        (*(f32 *)((u8 *)((*((struct fn_1_A7F84_lbl_801A6D00 *)&lbl_801A6D00)).unk_0) + 12)) = (f32) (*(f32 *)((u8 *)(arg0) + 36));
        (*(f32 *)((u8 *)((*((struct fn_1_A7F84_lbl_801A6D00 *)&lbl_801A6D00)).unk_0) + 28)) = (f32) (*(f32 *)((u8 *)(arg0) + 40));
        (*(f32 *)((u8 *)((*((struct fn_1_A7F84_lbl_801A6D00 *)&lbl_801A6D00)).unk_0) + 44)) = (f32) (*(f32 *)((u8 *)(arg0) + 44));
        return;
    case 4:
        lbl_8006D998((u32) (*(s16 *)((u8 *)(arg0) + 16)));
        mathutil_mtxA_rotate_y((u32) (*(s16 *)((u8 *)(arg0) + 14)));
        mathutil_mtxA_rotate_x((u32) (*(s16 *)((u8 *)(arg0) + 12)));
        (*(f32 *)((u8 *)((*((struct fn_1_A7F84_lbl_801A6D00 *)&lbl_801A6D00)).unk_0) + 12)) = (f32) (*(f32 *)((u8 *)(arg0) + 48));
        (*(f32 *)((u8 *)((*((struct fn_1_A7F84_lbl_801A6D00 *)&lbl_801A6D00)).unk_0) + 28)) = (f32) (*(f32 *)((u8 *)(arg0) + 52));
        (*(f32 *)((u8 *)((*((struct fn_1_A7F84_lbl_801A6D00 *)&lbl_801A6D00)).unk_0) + 44)) = (f32) (*(f32 *)((u8 *)(arg0) + 56));
        return;
    case 5:
        lbl_8006D998((u32) (s16) (-0x4000 - ((*(s16 *)((u8 *)(arg0) + 10)) + 0x4000)));
        mathutil_mtxA_rotate_y((u32) (*(s16 *)((u8 *)(arg0) + 8)));
        mathutil_mtxA_rotate_x((u32) (s16) (-0x4000 - ((*(s16 *)((u8 *)(arg0) + 6)) + 0x4000)));
        (*(f32 *)((u8 *)((*((struct fn_1_A7F84_lbl_801A6D00 *)&lbl_801A6D00)).unk_0) + 12)) = (f32) -(*(f32 *)((u8 *)(arg0) + 36));
        (*(f32 *)((u8 *)((*((struct fn_1_A7F84_lbl_801A6D00 *)&lbl_801A6D00)).unk_0) + 28)) = (f32) (*(f32 *)((u8 *)(arg0) + 40));
        (*(f32 *)((u8 *)((*((struct fn_1_A7F84_lbl_801A6D00 *)&lbl_801A6D00)).unk_0) + 44)) = (f32) (*(f32 *)((u8 *)(arg0) + 44));
        return;
    case 6:
        lbl_8006D998((u32) (s16) (0x4000 - ((*(s16 *)((u8 *)(arg0) + 16)) - 0x4000)));
        mathutil_mtxA_rotate_y((u32) (*(s16 *)((u8 *)(arg0) + 14)));
        mathutil_mtxA_rotate_x((u32) (s16) (0x4000 - ((*(s16 *)((u8 *)(arg0) + 12)) - 0x4000)));
        (*(f32 *)((u8 *)((*((struct fn_1_A7F84_lbl_801A6D00 *)&lbl_801A6D00)).unk_0) + 12)) = (f32) -(*(f32 *)((u8 *)(arg0) + 48));
        (*(f32 *)((u8 *)((*((struct fn_1_A7F84_lbl_801A6D00 *)&lbl_801A6D00)).unk_0) + 28)) = (f32) (*(f32 *)((u8 *)(arg0) + 52));
        (*(f32 *)((u8 *)((*((struct fn_1_A7F84_lbl_801A6D00 *)&lbl_801A6D00)).unk_0) + 44)) = (f32) (*(f32 *)((u8 *)(arg0) + 56));
        return;
    case 7:
        lbl_8006D91C(-0x4000U);
        mathutil_mtxA_rotate_y((u32) (*(s16 *)((u8 *)(arg0) + 18)));
        mathutil_mtxA_rotate_x(-0x4000U);
        return;
    case 8:
        lbl_8006D998((u32) (s16) (0x4000 - ((*(s16 *)((u8 *)(arg0) + 24)) - 0x4000)));
        mathutil_mtxA_rotate_y((u32) (*(s16 *)((u8 *)(arg0) + 22)));
        mathutil_mtxA_rotate_x((u32) (s16) (0x4000 - ((*(s16 *)((u8 *)(arg0) + 20)) - 0x4000)));
        (*(f32 *)((u8 *)((*((struct fn_1_A7F84_lbl_801A6D00 *)&lbl_801A6D00)).unk_0) + 12)) = (f32) -(*(f32 *)((u8 *)(arg0) + 60));
        (*(f32 *)((u8 *)((*((struct fn_1_A7F84_lbl_801A6D00 *)&lbl_801A6D00)).unk_0) + 28)) = (f32) (*(f32 *)((u8 *)(arg0) + 64));
        (*(f32 *)((u8 *)((*((struct fn_1_A7F84_lbl_801A6D00 *)&lbl_801A6D00)).unk_0) + 44)) = (f32) (*(f32 *)((u8 *)(arg0) + 68));
        return;
    case 9:
        lbl_8006D998((u32) (*(s16 *)((u8 *)(arg0) + 24)));
        mathutil_mtxA_rotate_y((u32) (*(s16 *)((u8 *)(arg0) + 22)));
        mathutil_mtxA_rotate_x((u32) (*(s16 *)((u8 *)(arg0) + 20)));
        (*(f32 *)((u8 *)((*((struct fn_1_A7F84_lbl_801A6D00 *)&lbl_801A6D00)).unk_0) + 12)) = (f32) (*(f32 *)((u8 *)(arg0) + 60));
        (*(f32 *)((u8 *)((*((struct fn_1_A7F84_lbl_801A6D00 *)&lbl_801A6D00)).unk_0) + 28)) = (f32) (*(f32 *)((u8 *)(arg0) + 64));
        (*(f32 *)((u8 *)((*((struct fn_1_A7F84_lbl_801A6D00 *)&lbl_801A6D00)).unk_0) + 44)) = (f32) (*(f32 *)((u8 *)(arg0) + 68));
        /* fallthrough */
    default:
        return;
    }
}
/* fzgx:end fn_1_A7F84 */

/* fzgx:begin fn_1_A8528 */
typedef struct FnA8528Object {
    u8 pad_ea[0xea];
    s16 unk_ea;
    s16 unk_ec;
    s16 unk_ee;
    f32 unk_f0;
    f32 unk_f4;
    f32 unk_f8;
    u8 pad_fc[0x18];
    u8 unk_114[0xc];
    u8 unk_120[0x4];
} FnA8528Object;



// Initializes the driver's state from the active configuration and shared systems.
void fn_1_A8528(void *arg0, void *arg1) {
    s16 orientation[3];
    void *driver_data;

    if (arg1 != 0) {
        driver_data = (u8 *)arg1 + 0x14c;
    } else {
        driver_data = lbl_801A6D00;
    }

    lbl_8006DAEC();
    lbl_8006DBAC(driver_data);
    lbl_8006E0A4(((FnA8528Object *)arg0)->unk_114);
    lbl_8006E0A4(((FnA8528Object *)arg0)->unk_120);
    fn_8006F6A8(orientation);

    ((FnA8528Object *)arg0)->unk_f0 = lbl_801A6D00->unk_0c;
    ((FnA8528Object *)arg0)->unk_f4 = lbl_801A6D00->unk_1c;
    ((FnA8528Object *)arg0)->unk_f8 = lbl_801A6D00->unk_2c;
    ((FnA8528Object *)arg0)->unk_ec = orientation[0];
    ((FnA8528Object *)arg0)->unk_ea = orientation[1];
    ((FnA8528Object *)arg0)->unk_ee = orientation[2];

    fn_1_A861C( (FnA861CCamera *)(void *)(arg0), (FnA861CVehicle *)(void *)(arg1));
    fn_1_A8834( (FnA8834Camera *)(void *)(arg0), (FnA8834Vehicle *)(void *)(arg1));
    fn_1_A89B0(arg0, arg1, 1);
    fn_1_A89B0(arg0, arg1, 0);
    lbl_8006DB30();
}
/* fzgx:end fn_1_A8528 */

/* fzgx:begin fn_1_A861C */
/* The TU's shared literal pool (lbl_1_rodata_4A28 .. +0x40) in retail order, so the
 * function's own literals dedupe onto retail's displacements. */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime_a861c(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sink */
    s = 0.0f;
    s = -0.1f;
    s = 0.1f;
    s = 5.0f;
    s = 0.5f;
    s = 50.0f;
    s = 10.0f;
    s = 57.2957763671875f;
    s = -10.0f;
    s = 0.2f;
    s = -30.0f;
    s = 1.8518518209457397f;
    s = -1.8518518209457397f;
    s = 4.166666507720947f;
    s = 25.0f;
    s = 30.0f;
    s = 182.04444885253906f;
}
#pragma section code_type ".text"

void fn_1_A861C(FnA861CCamera *cam, FnA861CVehicle *veh)
{
    lbl_8006DBAC( (void *)(FnA861CCamera *)(cam));
    if (veh == NULL) {
        cam->pitch = 0.0f;
        cam->yaw = 0.0f;
        cam->roll = 0.0f;
    } else {
        f32 rad = -veh->unk_a4 / veh->unk_b0;
        f32 turn = 0.5f * (veh->unk_b8 / veh->unk_8);
        f32 yaw = (f32)(50.0f * turn) + (f32)(10.0f * (57.2957763671875f * rad));
        f32 roll = -10.0f * (turn + 57.2957763671875f * rad);
        f32 lift;
        f32 limit;
        s32 locked;

        lift = veh->unk_c0 / veh->unk_8;

        cam->pitch += (f32)(0.2f * (f32)((f32)(-30.0f * ((lift < -1.8518518209457397f ? -(1.8518518209457397f + lift) : 0.0f) / 4.166666507720947f)) - cam->pitch));

        locked = 0;
        if (cam->unk_e9 != 0) {
            u8 state = cam->unk_e8;
            if (state == 0x21 || state == 0x2a || state == 0x2b) {
                locked = 1;
            }
        }
        limit = locked ? 0.0f : 25.0f;
        if (yaw > limit) {
            yaw = limit;
        } else if (yaw < -limit) {
            yaw = -limit;
        }
        cam->yaw += (f32)(0.2f * (yaw - cam->yaw));

        if (roll > 30.0f) {
            roll = 30.0f;
        } else if (roll < -30.0f) {
            roll = -30.0f;
        }
        cam->roll += (f32)(0.2f * (roll - cam->roll));
    }
    mathutil_mtxA_rotate_z((s32)(182.04444885253906f * cam->pitch));
    mathutil_mtxA_rotate_y((s32)(182.04444885253906f * cam->yaw));
    mathutil_mtxA_rotate_x((s32)(182.04444885253906f * cam->roll));
    lbl_8006DB74(cam->unk_15c);
}
/* fzgx:end fn_1_A861C */

/* fzgx:begin fn_1_A8834 */
/* The TU's shared literal pool (lbl_1_rodata_4A28 .. +0x58) in retail order, so the
 * function's own literals dedupe onto retail's displacements. */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sink */
    s = 0.0f;
    s = -0.1f;
    s = 0.1f;
    s = 5.0f;
    s = 0.5f;
    s = 50.0f;
    s = 10.0f;
    s = 57.2957763671875f;
    s = -10.0f;
    s = 0.2f;
    s = -30.0f;
    s = 1.8518518f;
    s = -1.8518518f;
    s = 4.166666507720947f;
    s = 25.0f;
    s = 30.0f;
    s = 182.04444885253906f;
    s = 0.46296295523643494f;
    s = 1.0f;
    s = 15.0f;
    s = 45.0f;
    s = -45.0f;
    s = 0.75f;
}
#pragma section code_type ".text"

void fn_1_A8834(FnA8834Camera *cam, FnA8834Vehicle *veh) {
    lbl_8006DAEC();
    if (veh == NULL) {
        cam->unk_d8 = 0.0f;
    } else {
        f32 lateral;
        f32 speed;
        f32 yaw;
        f32 roll;

        lateral = -veh->unk_a4 / veh->unk_b0;
        speed = -veh->unk_c0 / veh->unk_8;
        speed = speed - 0.46296295523643494f;
        if (speed < 0.0f) {
            speed = 0.0f;
        }
        speed = speed / 4.166666507720947f;
        if (speed > 1.0f) {
            speed = 1.0f;
        }
        yaw = 15.0f * (57.2957763671875f * lateral);
        speed = speed * (-30.0f * veh->unk_1fc);
        roll = yaw + speed;
        if (roll > 45.0f) {
            roll = 45.0f;
        } else if (roll < -45.0f) {
            roll = -45.0f;
        }
        cam->unk_d8 = cam->unk_d8 + (f32)(0.1f * (roll - cam->unk_d8));
    }
    lbl_8006DFC4(cam->unk_90);
    mathutil_mtxA_rotate_x((s32)(182.04444885253906f * (0.75f * cam->unk_dc)));
    mathutil_mtxA_rotate_y((s32)(182.04444885253906f * cam->unk_e4));
    mathutil_mtxA_rotate_z((s32)(182.04444885253906f * cam->unk_d8));
    lbl_8006DB74(cam->unk_18c);
    lbl_8006DB30();
}
/* fzgx:end fn_1_A8834 */

/* fzgx:begin fn_1_A8D4C */
void fn_1_A8D4C(void) {
    lbl_1_bss_6F640 += 1;
}
/* fzgx:end fn_1_A8D4C */

/* fzgx:begin fn_1_A8D64 */
void fn_1_A8D64(void) {
    fn_1_3920();
}
/* fzgx:end fn_1_A8D64 */

/* fzgx:begin fn_1_A8D84 */
void fn_1_A8D84(void) {
    lbl_1_bss_6F640 = 0;
    fn_8001A78C( (u32)(void (*)(void))(fn_1_A8D4C));
    fn_8001A7D0( (u32)(void (*)(void))(fn_1_A8D64));
}
/* fzgx:end fn_1_A8D84 */

/* fzgx:begin fn_1_A8DC4 */
// Returns the current driver state handle.
u32 fn_1_A8DC4(void) {
    return lbl_1_bss_6F640;
}
/* fzgx:end fn_1_A8DC4 */

/* fzgx:begin fn_1_A8DD4 */
void fn_1_A8DD4(const char *format, ...) {
    char buffer[0x200];
    Sig_parse_format_va_list args;

    fn_1_A9420(0);
    __builtin_va_info(&args);
    fn_8008077C((u32)buffer, (u32)(const char *)(format), (u32)(Sig_parse_format_va_list *)(&args));
    fn_1_A948C( (int)(char *)(buffer));
}
/* fzgx:end fn_1_A8DD4 */

/* fzgx:begin fn_1_A8E78 */
// fn_1_A8E78: Take an argument, call fn_1_A9420(0), then fn_1_A948C with original arg.

void fn_1_A8E78(int arg) {
    fn_1_A9420(0);
    fn_1_A948C(arg);
}
/* fzgx:end fn_1_A8E78 */

/* fzgx:begin fn_1_A8EB0 */
void fn_1_A8EB0(int arg0, int arg1) {
    fn_1_A9420(0);
    fn_1_A943C(arg0, arg1);
}
/* fzgx:end fn_1_A8EB0 */

/* fzgx:begin fn_1_A8EF8 */
// Reset the current selection before applying the two provided values.
void fn_1_A8EF8(u16 arg0, u16 arg1) {
    fn_1_A9420(0);
    fn_1_A9464(arg0, arg1);
}
/* fzgx:end fn_1_A8EF8 */

/* fzgx:begin fn_1_A8F40 */
// Reset the mode before forwarding the supplied value.
void fn_1_A8F40(u8 arg0) {
    fn_1_A9420(0);
    fn_1_A942C(arg0);
}
/* fzgx:end fn_1_A8F40 */

/* fzgx:begin fn_1_A8F78 */
void fn_1_A8F78(void) {
    fn_1_A9420(0);
    fn_1_A96BC();
}
/* fzgx:end fn_1_A8F78 */

/* fzgx:begin fn_1_A9250 */
void fn_1_A9250(int arg) {
    int i;

    fn_1_49410();
    fn_1_494DC((s16)(((u32 *)&lbl_1_data_35990))[(u8)arg]);
    fn_1_520A0();
    fn_1_52088();

    for (i = 0; i < (int)lbl_1_bss_71658[0]; i++) {
        if ((u8)arg == lbl_1_bss_70658[i].kind) {
            if (((lbl_1_bss_70658[i].flags >> 1) & 1) != 0) {
                fn_1_49714(
                    (f32)(lbl_1_bss_70658[i].x + lbl_1_bss_70658[i].z),
                    (f32)lbl_1_bss_70658[i].y,
                    (f32)lbl_1_bss_70658[i].x);
            } else {
                fn_1_49680(
                    (f32)(lbl_1_bss_70658[i].x + lbl_1_bss_70658[i].z),
                    (f32)lbl_1_bss_70658[i].y);
            }
            fn_1_A93C4(lbl_1_bss_70658[i].callback);
            fn_1_4A0D8(lbl_1_bss_70658[i].data);
        }
    }

    fn_1_49410();
    fn_1_520CC();
}
/* fzgx:end fn_1_A9250 */

/* fzgx:begin fn_1_A93C4 */
void fn_1_A93C4(u32 arg0) {
    u32 v0;
    u32 v1;
    u32 v2;
    s8 loc_8[8];
    v0 = ((arg0 & 0xC0) | 63);
    v1 = (((arg0 << 2) & 0xC0) | 63);
    v2 = (((arg0 << 4) & 0xC0) | 63);
    loc_8[4] = v0;
    loc_8[5] = v1;
    loc_8[6] = v2;
    loc_8[7] = (((arg0 & 0x3) << 6) | 63);
    *(u32 *)&loc_8[0] = *(u32 *)&loc_8[4];
    fn_1_49514((u32 *)loc_8);
}
/* fzgx:end fn_1_A93C4 */

/* fzgx:begin fn_1_A9420 */
// Stores the current value in the driver's status byte.
void fn_1_A9420(u8 value) {
    lbl_1_bss_6F648.unk_0 = value;
}
/* fzgx:end fn_1_A9420 */

/* fzgx:begin fn_1_A942C */
// Stores the value in the driver's secondary byte-sized state field.
void fn_1_A942C(u8 value) {
    lbl_1_bss_6F648.unk_1 = value;
}
/* fzgx:end fn_1_A942C */

/* fzgx:begin fn_1_A943C */
struct fn_1_A943C_lbl_1_bss_6F648 {
    u8 pad_0[0x2];
    u8 unk_2;
    u8 pad_3[0x1];
    u16 unk_4;
    u16 unk_6;
    u16 unk_8;
};

void fn_1_A943C(u32 arg0, u32 arg1) {
    u8 v0;
    v0 = (*((struct fn_1_A943C_lbl_1_bss_6F648 *)&lbl_1_bss_6F648)).unk_2;
    (*((struct fn_1_A943C_lbl_1_bss_6F648 *)&lbl_1_bss_6F648)).unk_4 = arg0;
    (*((struct fn_1_A943C_lbl_1_bss_6F648 *)&lbl_1_bss_6F648)).unk_6 = arg1;
    (*((struct fn_1_A943C_lbl_1_bss_6F648 *)&lbl_1_bss_6F648)).unk_8 = 0;
    (*((struct fn_1_A943C_lbl_1_bss_6F648 *)&lbl_1_bss_6F648)).unk_2 = (v0 & 0xFFFFFFFD);
}
/* fzgx:end fn_1_A943C */

/* fzgx:begin fn_1_A9464 */
// Set the two values and mark the shared state as ready.
void fn_1_A9464(u16 arg0, u16 arg1) {
    u8 flags;

    flags = lbl_1_bss_6F648.unk_2;
    lbl_1_bss_6F648.unk_4 = arg0;
    lbl_1_bss_6F648.unk_6 = arg1;
    lbl_1_bss_6F648.unk_8 = 0;
    lbl_1_bss_6F648.unk_2 = flags | 2;
}
/* fzgx:end fn_1_A9464 */

/* fzgx:begin fn_1_A96BC pool noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/driver.h"

typedef struct lbl_1_bss_6F648_t {
    u8 pad_0[0xc];
    u32 unk_C;
} lbl_1_bss_6F648_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
lbl_1_bss_6F648_t fzgx_obj_lbl_1_bss_6F648;
u8 lbl_1_bss_6F648_10[0x1000];
u32 lbl_1_bss_70658[1024];
u8 lbl_1_bss_71658;
u8 lbl_1_bss_71658_fill_71659;
u16 lbl_1_bss_71658_fill_7165A;
u32 lbl_1_bss_71658_fill_7165C[5];
u32 lbl_1_bss_71670;
u32 fzgx_obj_lbl_1_bss_71674[2];
u32 lbl_1_bss_7167C;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F648;
    s = *(u8 *)&lbl_1_bss_6F648_10;
    s = *(u8 *)&lbl_1_bss_70658;
    s = *(u8 *)&lbl_1_bss_71658;
    s = *(u8 *)&lbl_1_bss_71658_fill_71659;
    s = *(u8 *)&lbl_1_bss_71658_fill_7165A;
    s = *(u8 *)&lbl_1_bss_71658_fill_7165C;
    s = *(u8 *)&lbl_1_bss_71670;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_71674;
    s = *(u8 *)&lbl_1_bss_7167C;
}
#pragma section code_type ".text"

void fn_1_A96BC(void) {
    
    *(u32 *)((u8 *)&lbl_1_bss_71658) = 0;
    fzgx_obj_lbl_1_bss_6F648.unk_C = (u32)lbl_1_bss_6F648_10;
}
/* fzgx:end fn_1_A96BC */

/* fzgx:begin fn_1_A96DC */
void fn_1_A96DC(void) {
    lbl_1_data_3599C.unk_0 = 1;
}
/* fzgx:end fn_1_A96DC */

/* fzgx:begin fn_1_A96EC */
// Clear the driver's first state field.
void fn_1_A96EC(void) {
    lbl_1_data_3599C.unk_0 = 0;
}
/* fzgx:end fn_1_A96EC */

/* fzgx:begin fn_1_A96FC */
// Initialize the driver state and format its startup data.
void fn_1_A96FC(void) {
    u8 buffer[0x48];

    lbl_1_bss_71670 = fn_1_451C();
    sprintf( (char *)(void *)(buffer), (char *)lbl_1_data_35AB8,
                ((u32 *)lbl_1_data_35A70)[*(s16 *)&lbl_1_bss_960]);
    fn_1_A5AA0(buffer, &lbl_1_bss_71674);
}
/* fzgx:end fn_1_A96FC */

/* fzgx:begin fn_1_A9764 */
void fn_1_A9764(void) {
    lbl_1_bss_7167C();
}
/* fzgx:end fn_1_A9764 */

/* fzgx:begin fn_1_A9790 */
void fn_1_A9790(void) {
    lbl_1_bss_71680();
}
/* fzgx:end fn_1_A9790 */

/* fzgx:begin fn_1_A97BC */
void fn_1_A97BC(void) {
    fn_1_A5C98(&lbl_1_bss_71674);
}
/* fzgx:end fn_1_A97BC */

/* fzgx:begin fn_1_A97E4 */
void fn_1_A97E4(void) {
    lbl_1_bss_71684();
}
/* fzgx:end fn_1_A97E4 */

/* fzgx:begin fn_1_A9810 */
void fn_1_A9810(void) {
    lbl_1_bss_71688();
}
/* fzgx:end fn_1_A9810 */

/* fzgx:begin fn_1_A983C */
void fn_1_A983C(void) {
    lbl_1_bss_7168C();
}
/* fzgx:end fn_1_A983C */

/* fzgx:begin fn_1_A9868 */
struct fn_1_A9868_lbl_1_bss_71690 {
    u32 unk_0;
};


void fn_1_A9868(u32 arg0, u32 arg1, u32 arg2, f32 arg3) {
    struct fn_1_A9868_lbl_1_rodata_4AA0 *p_lbl_1_rodata_4AA0;
    struct fn_1_A9868_lbl_1_bss_71690 *p_lbl_1_bss_71690;
    Sig_fn_80015EE8_Fn80015EE8Out loc_2C;
    u32 loc_20[3];
    u32 loc_14[3];
    u32 loc_8[3];
    f32 zero;
    p_lbl_1_rodata_4AA0 = (struct fn_1_A9868_lbl_1_rodata_4AA0 *)&lbl_1_rodata_4AA0;
    p_lbl_1_bss_71690 = (struct fn_1_A9868_lbl_1_bss_71690 *)&(*((struct fn_1_A9868_lbl_1_bss_71690 *)&lbl_1_bss_71690));
    fn_1_A714C((f32 *)((u8 *)(u32)p_lbl_1_bss_71690 + 4), (f32 *)((u8 *)(u32)p_lbl_1_bss_71690 + 8), (f32 *)((u8 *)(u32)p_lbl_1_bss_71690 + 12), (f32 *)((u8 *)(u32)p_lbl_1_bss_71690 + 16));
    fn_8007245C(2560);
    fn_800720B0(0);
    fn_800747D0(4, 0, 1, 1, 0, 2, 1);
    fn_800734A8(0, 255, 255, 4);
    fn_80072EDC(0, 4);
    fn_80073C6C(0);
    fn_8007264C(0, 9, 1, 4, 8);
    fn_80074718(6, 0);
    fn_800746A8(6, 0);
    fn_80073678(1);
    fn_80074660(0);
    fn_80073898(0);
    fn_80074788(1);
    lbl_8006DAEC();
    loc_20[0] = p_lbl_1_rodata_4AA0->unk_0;
    loc_20[1] = p_lbl_1_rodata_4AA0->unk_4;
    loc_20[2] = p_lbl_1_rodata_4AA0->unk_8;
    loc_14[0] = p_lbl_1_rodata_4AA0->unk_C;
    loc_14[1] = p_lbl_1_rodata_4AA0->unk_10;
    loc_14[2] = p_lbl_1_rodata_4AA0->unk_14;
    loc_8[0] = p_lbl_1_rodata_4AA0->unk_18;
    loc_8[1] = p_lbl_1_rodata_4AA0->unk_1C;
    loc_8[2] = p_lbl_1_rodata_4AA0->unk_20;
    fn_8006F1F0((void *)loc_20, (void *)loc_14, (void *)loc_8);
    fn_80038CFC(0);
    GXLoadPosMtxImm((*((struct fn_1_A9868_lbl_801A6D00 *)&lbl_801A6D00)).unk_0, 0);
    lbl_8006DB30();
    zero = fn_80015EE8((Sig_fn_80015EE8_Fn80015EE8Out *)&loc_2C, p_lbl_1_rodata_4AA0->unk_24, p_lbl_1_rodata_4AA0->unk_28, p_lbl_1_rodata_4AA0->unk_24, p_lbl_1_rodata_4AA0->unk_2C, p_lbl_1_rodata_4AA0->unk_24, p_lbl_1_rodata_4AA0->unk_30);
    fn_800737E4((struct Sig_fn_800737E4_fn_800737E4_Arg0 *)&loc_2C, 1, zero);
    fn_80074918(1, 7, 0);
    p_lbl_1_bss_71690->unk_0 = 1;
}
/* fzgx:end fn_1_A9868 */

/* fzgx:begin fn_1_AA350 */
#include "dolphin/hw_regs.h"
#include "types.h"
#include "rel/main_rel/driver.h"

#define WG_F32 (*(volatile f32 *)(GX_FIFO_BASE + 0x0)) /* Hardware access must remain ordered. */
#define WG_U8 (*(volatile u8 *)(GX_FIFO_BASE + 0x0)) /* Hardware access must remain ordered. */

static inline void pos3(f32 x, f32 y) {
    WG_F32 = x;
    WG_F32 = y;
    WG_F32 = lbl_1_rodata_4AC4[0];
}

static inline void col4(u8 r, u8 g, u8 b, u8 a) {
    WG_U8 = r;
    WG_U8 = g;
    WG_U8 = b;
    WG_U8 = a;
}

static inline u16 fn_1_AA350_array_read(s32 index, u8 *array) { return array[index]; }
void fn_1_AA350(s16 *a, s16 *b, u8 *c, u32 n) {
    u32 i;
    if ((s32)lbl_1_bss_71690.unk_0 != 0) {
        fn_8003462C(0x98, 0, (u16)n);
        for (i = 0; i < n; i++) {
            pos3((f32)*a++, (f32)*b++);
            col4(fn_1_AA350_array_read(0, c), fn_1_AA350_array_read(1, c), fn_1_AA350_array_read(2, c), fn_1_AA350_array_read(3, c));
            c += 4;
        }
    }
}
/* fzgx:end fn_1_AA350 */

/* fzgx:begin fn_1_AA538 */
// Initialize the shared rendering state and submit the associated configuration.
void fn_1_AA538(void) {
    Obj_1_bss_71690 *state = (Obj_1_bss_71690 *)&lbl_1_bss_71690;

    fn_1_A7024(state->unk_4, state->unk_8, state->unk_C, state->unk_10);
    fn_80074918(1, 3, 1);
    state->unk_0 = 1;
}
/* fzgx:end fn_1_AA538 */

/* fzgx:begin fn_1_AAEB0 */
struct fn_1_AAEB0_Arg0 {
    u8 unk_0;
    u8 pad_1[0x4];
    u8 unk_5;
    u8 pad_6[0x1E];
    u32 unk_24;
};
struct fn_1_AAEB0_lbl_1_data_35AC8 {
    u8 pad_0[0x6AC4];
    u32 unk_6AC4[1];
};


static inline u32 *fn_1_AAEB0_array_read(u32 *array) { return array; }
#pragma opt_propagation off
void fn_1_AAEB0(struct fn_1_AAEB0_Arg0 *arg0) {
    struct fn_1_AAEB0_lbl_1_data_35AC8 *p_lbl_1_data_35AC8;
    p_lbl_1_data_35AC8 = (struct fn_1_AAEB0_lbl_1_data_35AC8 *)&(*((struct fn_1_AAEB0_lbl_1_data_35AC8 *)&lbl_1_data_35AC8));
    OSReport((const char *)(u32)((u8 *)(u32)p_lbl_1_data_35AC8 + 28000), arg0->unk_0, *(u32 *)((u8 *)arg0->unk_24 + 4), fn_1_AAEB0_array_read(p_lbl_1_data_35AC8->unk_6AC4)[arg0->unk_5]);
    OSPanic((const char *)(u32)((u8 *)(u32)p_lbl_1_data_35AC8 + 27888), 1322, (const char *)(u32)((u8 *)(u32)p_lbl_1_data_35AC8 + 28044));
}
#pragma opt_propagation reset
/* fzgx:end fn_1_AAEB0 */

/* fzgx:begin fn_1_AAF18 */
// fn_1_AAF18: empty in retail (single blr).
void fn_1_AAF18(void) {
}
/* fzgx:end fn_1_AAF18 */

/* fzgx:begin fn_1_AB434 */
// fn_1_AB434: empty in retail (single blr).
void fn_1_AB434(void) {
}
/* fzgx:end fn_1_AB434 */

/* fzgx:begin fn_1_AB438 */
typedef struct Fn1AB438Data {
    u8 pad_00[8];
    s16 field_08;
    s16 field_0A;
    u8 pad_0C[0x1e];
    u8 field_2A;
} Fn1AB438Data;

void fn_1_AB438(Fn1AB438Data *data) {
    data->field_08 = 30;
    data->field_0A = 14;
    data->field_2A |= 4;
}
/* fzgx:end fn_1_AB438 */

/* fzgx:begin fn_1_AB458 */
// fn_1_AB458: empty in retail (single blr).
void fn_1_AB458(void) {
}
/* fzgx:end fn_1_AB458 */

/* fzgx:begin fn_1_AB45C */
void fn_1_AB45C(int index) {
    lbl_1_bss_716C8[index * 0xa0 + 7] = 1;
}
/* fzgx:end fn_1_AB45C */
