#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/shadowmap.h"
#include "psvec.h"

typedef struct fn_1_568F8_Color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} fn_1_568F8_Color;

typedef struct fn_1_568F8_Vec3 {
    f32 x;
    f32 y;
    f32 z;
} fn_1_568F8_Vec3;

typedef struct fn_1_568F8_Pool {
    fn_1_568F8_Color tev_color;  // 0x00
    f32 zero;                    // 0x04
    fn_1_568F8_Vec3 axis_x;      // 0x08
    fn_1_568F8_Vec3 axis_y;      // 0x14
    fn_1_568F8_Vec3 axis_z;      // 0x20
    fn_1_568F8_Vec3 up;          // 0x2c
    fn_1_568F8_Color clear_color;  // 0x38
    fn_1_568F8_Color chan_color;   // 0x3c
    f32 neg_three;               // 0x40
    f32 one;                     // 0x44
    f32 twenty;                  // 0x48
    f32 three;                   // 0x4c
    f32 hundred;                 // 0x50
    f32 size;                    // 0x54
} fn_1_568F8_Pool;

typedef struct fn_1_568F8_Data {
    u8 pad_0[0x38c];
    u8 light_mask;               // 0x38c
    u8 pad_38d[0x2b];
    s16 light_param;             // 0x3b8
} fn_1_568F8_Data;

typedef struct fn_1_568F8_Mtx44 {
    f32 m[4][4];
} fn_1_568F8_Mtx44;
extern fn_1_568F8_Pool lbl_1_rodata_28B0;
extern f64 __fabs(f64);
extern int fn_1_56724(void);
extern void fn_1_870BC(fn_1_568F8_Data *, s8, fn_1_568F8_Data *, s32, u8, f32);
extern void fn_80038F10(f32* out);
extern void fn_80038FD8(u32 *, u32 *, u32 *, u32 *);
extern void fn_80038BFC(f32* out);
extern void fn_8006F1F0(void *, void *, void *);
extern void lbl_8006DB74(void *arg);
extern void lbl_8006D89C(f32, f32);
extern void lbl_8006E0D8(f32, f32, f32);
extern void fn_80015EE8(fn_1_568F8_Mtx44 *, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(fn_1_568F8_Mtx44 *, s32);
extern u32 fn_80038EEC();
extern u32 fn_80074188(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern void fn_80074300();
extern void fn_80074438(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern void fn_800744F8(fn_1_568F8_Color, u32);
extern void fn_8003526C(void *, u8);
extern void fn_80007C2C(void);
extern void lbl_8006DC6C(void *);
extern void lbl_8006DFD8(void *);
extern void lbl_8006DBAC(void *);
extern void fn_80072558(void);
extern void fn_80074788(u32 arg0);
extern void fn_80074660(u32 arg0);
extern void fn_80073678(u32 arg0);
extern void fn_80073898(u32 arg0);
extern void fn_800725DC(fn_1_568F8_Color);
extern void fn_80072614(fn_1_568F8_Color);
extern void fn_800747D0(u32 arg0, u32 arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6);
extern void fn_80073C6C(s32 index);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80072EDC(s32 arg0, s32 arg1);
extern void fn_800728A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern u32 fn_80077BAC(u32 arg0);
extern void GXInvalidateTexAll(void);
extern void fn_80072270(f32 *);
extern void fn_800746A8();
extern void fn_8007245C(u32 value);
extern void fn_800720B0(u32);
extern void *lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern f32 lbl_1_rodata_28B4[16];
extern void *GXGetTexBufferSize(int, int, int, int, int);
extern s32 fn_1_45D0();
extern void GXInitTexObj(void *, void *, int, int, int, int, int, int);
extern void GXInitTexObjLOD(void *, int, int, f32, f32, f32, int, int, int);
extern void fn_80073778(void *obj, s32 index);
extern void fn_800724C8(void);
extern void fn_800745A4(u32 arg0, s32 arg1, s32 arg2, u32 arg3, u32 arg4, u32 arg5);
extern void fn_80072AB0(s32 arg0, s32 arg1, s32 arg2);
extern u32 fn_800371F8(u32, void *);
extern void fn_80072C24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072D64(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_80072CC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072E20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_80072864(u32 arg0);
extern void GXSetAlphaCompare(u32, u32, u32, u32, u32);
extern void lbl_8006D758(void);
extern void GXLoadPosMtxImm(void *arg0, int arg1);
extern void fn_8003462C(u32 arg0, u32 arg1, u32 arg2);
extern void *lbl_801A6D00;
extern f32 lbl_1_rodata_28F4[23];
extern void fn_1_57DC0(void);
extern void * fn_1_548AC(u32 amount);
extern void *fn_1_5448C(void *arg);
extern void fn_1_57E84(void);
extern void fn_1_5489C(void **arg0, void **arg1);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);

/* fzgx:begin fn_1_5672C */
typedef struct fn_1_5672C_ShadowMapEntry {
    int field_00;
    int field_04;
    f32 field_08;
    char unk_0c[0x30];
    void *field_3c;
    void *field_40;
    int field_44;
    int field_48;
} fn_1_5672C_ShadowMapEntry;

void fn_1_5672C(fn_1_5672C_ShadowMapEntry *entries, int count) {
    void *buffer;
    int i;
    fn_1_5672C_ShadowMapEntry *entry;
    f32 zero = lbl_1_rodata_28B4[0];

    entry = entries;
    i = 0;
    while (i < count) {
        buffer = GXGetTexBufferSize(0x40, 0x40, 0, 0, 0);
        entry->field_00 = 0;
        entry->field_04 = 0;
        entry->field_08 = zero;
        entry->field_3c = (void *)fn_1_45D0(lbl_801A6410, 0x20, (*(char (*)[12])&lbl_1_data_1C660), 0x67);
        entry->field_40 = (void *)fn_1_45D0(lbl_801A6410, (int)buffer, (*(char (*)[12])&lbl_1_data_1C660), 0x68);
        entry->field_44 = 0;
        entry->field_48 = 0;
        GXInitTexObj(entry->field_3c, entry->field_40, 0x40, 0x40, 0, 0, 0, 0);
        GXInitTexObjLOD(entry->field_3c, 1, 1, lbl_1_rodata_28B4[0],
                        lbl_1_rodata_28B4[0], lbl_1_rodata_28B4[0], 0, 0, 0);
        i++;
        entry++;
    }
}
/* fzgx:end fn_1_5672C */

/* fzgx:begin fn_1_56858 */
typedef struct fn_1_56858_ShadowMapEntry {
    char pad_00[0x3c];
    void *unk_3c;
    void *unk_40;
    char pad_44[0x08];
} fn_1_56858_ShadowMapEntry;

// Register each entry's resources, then clear it for reuse.
void fn_1_56858(fn_1_56858_ShadowMapEntry *entries, u32 count) {
    u32 index;
    fn_1_56858_ShadowMapEntry *current_entry;

    for (index = 0, current_entry = entries; index < count;
         index++, current_entry++) {
        fn_1_46B4( (u32)(void *)(lbl_801A6410), (u32)(void *)(current_entry->unk_3c), (const char *)(unsigned char *)(lbl_1_data_1C660), 0x87);
        fn_1_46B4( (u32)(void *)(lbl_801A6410), (u32)(void *)(current_entry->unk_40), (const char *)(unsigned char *)(lbl_1_data_1C660), 0x88);
        memset(current_entry, 0, 0x4c);
    }
}
/* fzgx:end fn_1_56858 */

/* fzgx:begin fn_1_568EC */
typedef struct ShadowMap {
    u8 pad44[0x44];
    u32 field44;
    u32 field48;
} ShadowMap;

void fn_1_568EC(ShadowMap *map, u32 value0, u32 value1) {
    map->field48 = value0;
    map->field44 = value1;
}
/* fzgx:end fn_1_568EC */

/* fzgx:begin fn_1_568F8 */


typedef struct fn_1_568F8_Mtx {
    f32 m[3][4];
} fn_1_568F8_Mtx;



typedef struct fn_1_568F8_Target {
    u8 pad_0[0x14c];
    fn_1_568F8_Mtx mtx;          // 0x14c
    u8 pad_17c[0x40];
    fn_1_568F8_Vec3 pos;         // 0x1bc
} fn_1_568F8_Target;


typedef struct fn_1_568F8_Entry {
    u32 flags;
    u32 state;
    u8 pad_8[0x38];
    void *tex_obj;               // 0x40
    fn_1_568F8_Data *data;       // 0x44
    fn_1_568F8_Target *target;   // 0x48
} fn_1_568F8_Entry;



static inline void fn_1_568F8_set_chan(fn_1_568F8_Color color) {
    fn_80074788(1);
    fn_80074660(0);
    fn_80073678(1);
    fn_80073898(0);
    fn_800725DC(color);
}

void fn_1_568F8(fn_1_568F8_Entry *entry) {
    fn_1_568F8_Pool *pool = &lbl_1_rodata_28B0;
    fn_1_568F8_Target *target = entry->target;
    s32 use_target = (entry->flags >> 1) & 1;
    fn_1_568F8_Data *data;
    fn_1_568F8_Vec3 *axis;
    f32 ax;
    f32 ay;
    f32 az;
    f32 scale;
    f32 half;
    f32 neg_half;
    s32 i;
    fn_1_568F8_Mtx44 proj;
    fn_1_568F8_Mtx view;
    f32 viewport[6];
    f32 projection[7];
    fn_1_568F8_Vec3 pos;
    fn_1_568F8_Vec3 axis_x;
    fn_1_568F8_Vec3 axis_y;
    fn_1_568F8_Vec3 axis_z;
    fn_1_568F8_Vec3 up;
    u32 sc_x;
    u32 sc_y;
    u32 sc_w;
    u32 sc_h;
    fn_1_568F8_Color chan_color;

    if (!(use_target != 0 || (use_target == 0 && !(entry->state & 1)))) {
        return;
    }
    {
        entry->state &= ~3;
        if (use_target) {
            entry->state |= 2;
        } else {
            entry->state |= 1;
        }

        fn_80038F10(viewport);
        fn_80038FD8(&sc_x, &sc_y, &sc_w, &sc_h);
        fn_80038BFC(projection);

        if (use_target) {
            ax = __fabs(target->pos.x);
            ay = __fabs(target->pos.y);
            az = __fabs(target->pos.z);
            if (ax <= ay && ax <= az) {
                axis_x = pool->axis_x;
                axis = &axis_x;
            } else if (ay <= az && ay <= ax) {
                axis_y = pool->axis_y;
                axis = &axis_y;
            } else {
                axis_z = pool->axis_z;
                axis = &axis_z;
            }
            scale = pool->neg_three;
            axis->x = -axis->x;
            axis->y = -axis->y;
            axis->z = -axis->z;
            psvec_scale(&target->pos, scale, &pos);
            up = pool->up;
            fn_8006F1F0(&pos, axis, &up);
            lbl_8006DB74(&view);
        } else {
            lbl_8006D89C(pool->one, pool->zero);
            lbl_8006E0D8(pool->zero, pool->twenty, pool->zero);
            lbl_8006DB74(&view);
        }

        half = pool->three;
        neg_half = pool->neg_three;
        fn_80015EE8(&proj, half, neg_half, neg_half, half, pool->zero, pool->hundred);
        fn_800737E4(&proj, 1);
        fn_80038EEC(pool->zero, pool->zero, pool->size, pool->size, pool->zero, pool->one);
        fn_80074188(0, 0, 0x80, 0x80);
        fn_80074300(0, 0, 0x80, 0x80);
        fn_80074438(0x40, 0x40, 0, 1);
        fn_800744F8(pool->clear_color, 0xFFFFFF);
        fn_8003526C(entry->tex_obj, 1);
        fn_80007C2C();

        if (use_target) {
            lbl_8006DC6C(&target->mtx);
            lbl_8006DFD8(&view);
        } else {
            lbl_8006DBAC(&view);
        }

        fn_80072558();
        fn_1_568F8_set_chan(pool->chan_color);
        fn_80072614(pool->tev_color);
        fn_800747D0(4, 0, 0, 0, 1, 2, 1);
        fn_80073C6C(0);
        fn_800734A8(0, 0xFF, 0xFF, 4);
        fn_80072EDC(0, 4);
        fn_800728A8(1, 1, 0, 0);
        fn_80074918(1, 3, 1);
        fn_80077BAC( (u32)(void *)(fn_1_56724));

        data = entry->data;
        for (i = 0; i < 6; i++) {
            if (i != 5 && (data->light_mask & (1 << i))) {
                fn_1_870BC(data, (s8)i, data, 0, (u8)data->light_param, pool->one);
                break;
            }
        }

        fn_80077BAC( (u32)(void *)(0));
        fn_8003526C(entry->tex_obj, 1);
        GXInvalidateTexAll();
        fn_80038EEC(viewport[0], viewport[1], viewport[2], viewport[3], viewport[4], viewport[5]);
        fn_80074188(sc_x, sc_y, sc_w, sc_h);
        fn_80072270(projection);
    }
}
/* fzgx:end fn_1_568F8 */

/* fzgx:begin fn_1_571E8 */
typedef union fn_1_571E8_GXFifo {
    volatile f32 f32; /* write-gather FIFO: writes have side effects */
    volatile u8 u8;   /* write-gather FIFO: writes have side effects */
} fn_1_571E8_GXFifo;

enum { GX_FIFO_ADDR = 0xCC008000 }; /* fzgx-allow: A1 GX write-gather FIFO hardware address */
#define GXWGFifo (*(fn_1_571E8_GXFifo *)GX_FIFO_ADDR)

typedef struct fn_1_571E8_Vec3 {
    f32 x;
    f32 y;
    f32 z;
} fn_1_571E8_Vec3;

typedef struct fn_1_571E8_Arg0 {
    u8 pad_0[8];
    fn_1_571E8_Vec3 p0;
    fn_1_571E8_Vec3 p1;
    fn_1_571E8_Vec3 p2;
    fn_1_571E8_Vec3 p3;
    u32 unk_38;
    u32 unk_3C;
    u32 unk_40;
} fn_1_571E8_Arg0;

void fn_1_571E8(fn_1_571E8_Arg0 *arg0) {
    f32 x;
    f32 y;
    f32 z;
    f32 x2;
    f32 y2;
    f32 z2;
    f32 x3;
    f32 y3;
    f32 z3;
    f32 x4;
    f32 y4;
    f32 z4;
    u32 loc_8;

    fn_80073778((void *)arg0->unk_38, 0);
    fn_800724C8();
    fn_8007245C(0x2200);
    fn_80074788(0);
    fn_80074660(1);
    fn_80073678(1);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_800745A4(0, 1, 4, 0x3C, 0, 0x7D);
    fn_800734A8(0, 0, 0, 0xFF);
    fn_80072AB0(0, 0, 0);
    loc_8 = arg0->unk_3C;
    fn_800371F8(1, &loc_8);
    fn_80072C24(0, 0xF, 0xF, 0xF, 2);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 7, 7, 4);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_800720B0(0);
    fn_80072864(2);
    GXSetAlphaCompare(4, 0x4F, 0, 3, 0xFF);
    fn_800728A8(1, 7, 6, 0);
    fn_80074918(1, arg0->unk_40, 0);
    lbl_8006D758();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    fn_8003462C(0x80, 0, 4);

    z = arg0->p0.z;
    y = arg0->p0.y;
    x = arg0->p0.x;
    GXWGFifo.f32 = x;
    GXWGFifo.f32 = y;
    GXWGFifo.f32 = z;
    GXWGFifo.f32 = lbl_1_rodata_28B4[0];
    GXWGFifo.f32 = lbl_1_rodata_28B4[0];

    z2 = arg0->p1.z;
    y2 = arg0->p1.y;
    x2 = arg0->p1.x;
    GXWGFifo.f32 = x2;
    GXWGFifo.f32 = y2;
    GXWGFifo.f32 = z2;
    GXWGFifo.f32 = lbl_1_rodata_28F4[0];
    GXWGFifo.f32 = lbl_1_rodata_28B4[0];

    z3 = arg0->p2.z;
    y3 = arg0->p2.y;
    x3 = arg0->p2.x;
    GXWGFifo.f32 = x3;
    GXWGFifo.f32 = y3;
    GXWGFifo.f32 = z3;
    GXWGFifo.f32 = lbl_1_rodata_28F4[0];
    GXWGFifo.f32 = lbl_1_rodata_28F4[0];

    z4 = arg0->p3.z;
    y4 = arg0->p3.y;
    x4 = arg0->p3.x;
    GXWGFifo.f32 = x4;
    GXWGFifo.f32 = y4;
    GXWGFifo.f32 = z4;
    GXWGFifo.f32 = lbl_1_rodata_28B4[0];
    GXWGFifo.f32 = lbl_1_rodata_28F4[0];

    fn_80074918(1, 3, 1);
    GXSetAlphaCompare(7, 0, 0, 7, 0);
}
/* fzgx:end fn_1_571E8 */

/* fzgx:begin fn_1_57714 */
// Updates the shadow-map enable flag.
void fn_1_57714(u8 value) {
    lbl_1_data_1C670.unk_0 = value;
}
/* fzgx:end fn_1_57714 */

/* fzgx:begin fn_1_57720 */
void fn_1_57720(u32 value_1, u32 value_2, u32 value_3, u32 value_4) {
    lbl_1_data_1C670.unk_4 = value_1;
    lbl_1_data_1C670.unk_8 = value_2;
    lbl_1_data_1C670.unk_C = value_3;
    lbl_1_data_1C670.unk_10 = value_4;
}
/* fzgx:end fn_1_57720 */

/* fzgx:begin fn_1_5773C */
typedef union fn_1_5773C_GXFifo {
    volatile f32 f32; /* write-gather FIFO: writes have side effects */
    volatile u8 u8;   /* write-gather FIFO: writes have side effects */
} fn_1_5773C_GXFifo;

enum { GX_FIFO_ADDR = 0xCC008000 }; /* fzgx-allow: A1 GX write-gather FIFO hardware address */
#define GXWGFifo (*(fn_1_5773C_GXFifo *)GX_FIFO_ADDR)

typedef struct fn_1_5773C_Vec3 {
    f32 x;
    f32 y;
    f32 z;
} fn_1_5773C_Vec3;

void fn_1_5773C(fn_1_5773C_Vec3 *arg0, fn_1_5773C_Vec3 *arg1, u8 *arg2) {
    u32 color;
    f32 y;
    f32 z;
    f32 x;
    f32 y2;
    f32 z2;
    f32 x2;

    fn_1_57DC0();
    color = *(u32 *)arg2;
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    fn_8003462C(0xA8, 0, 2);
    z = arg0->z;
    y = arg0->y;
    x = arg0->x;
    GXWGFifo.f32 = x;
    GXWGFifo.f32 = y;
    GXWGFifo.f32 = z;
    GXWGFifo.u8 = ((u8 *)&color)[0];
    GXWGFifo.u8 = ((u8 *)&color)[1];
    GXWGFifo.u8 = ((u8 *)&color)[2];
    GXWGFifo.u8 = ((u8 *)&color)[3];
    z2 = arg1->z;
    y2 = arg1->y;
    x2 = arg1->x;
    GXWGFifo.f32 = x2;
    GXWGFifo.f32 = y2;
    GXWGFifo.f32 = z2;
    GXWGFifo.u8 = ((u8 *)&color)[0];
    GXWGFifo.u8 = ((u8 *)&color)[1];
    GXWGFifo.u8 = ((u8 *)&color)[2];
    GXWGFifo.u8 = ((u8 *)&color)[3];
}
/* fzgx:end fn_1_5773C */

/* fzgx:begin fn_1_57BBC */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
} Fn1_57BBC_ArgBlock;

typedef struct {
    u32 unk_0;
    void (*unk_4)(void);
    u8 pad_8[0x30];
    u32 unk_38;
    u16 unk_3C;
    u8 pad_3E[0x2];
    void *unk_40;
    Obj_1_data_1C670 unk_44;
} Fn1_57BBC_Object;

typedef struct {
    Fn1_57BBC_ArgBlock unk_0;
    Fn1_57BBC_ArgBlock unk_10;
} Fn1_57BBC_Data;

void fn_1_57BBC(Fn1_57BBC_ArgBlock *arg0, Fn1_57BBC_ArgBlock *arg1) {
    Fn1_57BBC_Object *object;
    Fn1_57BBC_Data *data;
    void *value;

    object = fn_1_548AC(0x60);
    if (object == 0) {
        return;
    }

    data = fn_1_548AC(0x20);
    if (data == 0) {
        return;
    }

    value = fn_1_5448C(arg0);
    object->unk_4 = fn_1_57E84;
    object->unk_38 = 0xA8;
    object->unk_3C = 2;
    object->unk_44 = lbl_1_data_1C670;
    data->unk_0 = *arg0;
    data->unk_10 = *arg1;
    object->unk_40 = data;
    lbl_8006DB74(object->pad_8);
    fn_1_5489C( (void **)(void *)(value), (void **)(void *)(object));
}
/* fzgx:end fn_1_57BBC */

/* fzgx:begin fn_1_57CD0 */
typedef struct {
    u8 pad_0[0x4];
    void (*unk_4)(void);
    u8 pad_8[0x30];
    u32 unk_38;
    u16 unk_3C;
    u8 pad_3E[0x2];
    void *unk_40;
    Obj_1_data_1C670 unk_44;
} Fn1_57CD0_Object;

void fn_1_57CD0(u32 value, void *arg) {
    u32 size;
    Fn1_57CD0_Object *object;
    void *created;
    void *buffer;

    if ((u16)value < 2) {
        return;
    }

    object = fn_1_548AC(0x60);
    if (object == 0) {
        return;
    }

    size = (value & 0xffff) << 4;
    buffer = fn_1_548AC(size);
    if (buffer == 0) {
        return;
    }

    created = fn_1_5448C(arg);
    object->unk_4 = fn_1_57E84;
    object->unk_38 = 0xa8;
    object->unk_3C = (u16)value;
    object->unk_44 = lbl_1_data_1C670;
    fn_80008BA8( (u32)(void *)(buffer), (u32)(void *)(arg), size);
    object->unk_40 = buffer;
    lbl_8006DB74(object->pad_8);
    fn_1_5489C( (void **)(void *)(created), (void **)(void *)(object));
}
/* fzgx:end fn_1_57CD0 */

/* fzgx:begin fn_1_57DC0 */
void fn_1_57DC0(void) {
    fn_800746A8(lbl_1_data_1C670.unk_0, lbl_1_data_1C670.unk_14);
    fn_8007245C(0xa00);
    fn_800728A8(lbl_1_data_1C670.unk_4, lbl_1_data_1C670.unk_8,
                lbl_1_data_1C670.unk_C, lbl_1_data_1C670.unk_10);
    fn_800720B0(0);
    fn_800747D0(4, 0, 1, 1, 0, 2, 1);
    fn_800734A8(0, 0xff, 0xff, 4);
    fn_80072EDC(0, 4);
    fn_80073C6C(0);
    fn_80073678(1);
    fn_80074660(0);
    fn_80073898(0);
    fn_80074788(1);
}
/* fzgx:end fn_1_57DC0 */
