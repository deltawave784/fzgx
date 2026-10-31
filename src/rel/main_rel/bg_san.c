#include "types.h"
#include "game/main_rel/bg_san_types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_san.h"
#include "psvec.h"
#include "rel/main_rel/bg_lig.h"
#include "game/vec3.h"
#include "dolphin/gx.h"


extern void fn_1_DC764();  /* takes the handler (reads handler->unk_08); non-prototype so Handler.unk_04 accepts it */

struct fn_1_DB9B0_lbl_1_rodata_6638 {
    f32 unk_0; u8 pad_4[4]; f32 unk_8; f32 unk_C;
    u8 pad_10[0x34];
    u32 unk_44; u32 unk_48; u32 unk_4C;
    u32 unk_50; u32 unk_54; u32 unk_58;
    f32 unk_5C; f64 unk_60; f64 unk_68; f64 unk_70;
    f32 unk_78; f32 unk_7C; f32 unk_80;
    u8 pad_84[4]; f64 unk_88; f64 unk_90;
};

typedef struct V3 { f32 x, y, z; } V3;

typedef struct Src { u8 pad[0xc]; V3 pos; } Src;

typedef struct Elem { V3 pos; f32 w; } Elem;

typedef struct Entry {
    Src *src;
    V3 cur;
    s32 zero;
    f32 one;
    s16 a;
    f32 b;
    Elem first[128];
    Elem second[128];
} Entry;

typedef struct Obj {
    u8 pad[0x10];
    s32 count;
    Entry entries[1];
} Obj;

typedef struct DB53CVec {
    f32 x;
    f32 y;
    f32 z;
} DB53CVec;

typedef struct {
    f32 x, y, z;
} BgSanVec3;

typedef struct {
    f32 x, y, z;
} Fn1DB268_Vec;

typedef struct {
    u32 unk_0;
    u8 pad_4[0x8];
    Fn1DB268_Vec pos;
    s16 rot_x;
    s16 rot_y;
    s16 rot_z;
    f32 scale;
} Fn1DB268_Source;

typedef struct {
    Fn1DB268_Vec pos;
    f32 height;
} Fn1DB268_Point;

typedef struct {
    s16 head;
    f32 height;
    Fn1DB268_Point upper[128];
    Fn1DB268_Point lower[128];
} Fn1DB268_Trail;

typedef struct {
    Fn1DB268_Source *source;
    Fn1DB268_Vec pos;
    s32 age;
    u8 pad_14[4];
    Fn1DB268_Trail trail;
} Fn1DB268_Effect;
extern f32 lbl_8006D668(u32 *);
extern void fn_1_9AD54(void);
extern s32 fn_1_58C4();
extern s16 fn_1_7B054(void);
extern s16 fn_1_3F0C8(void);
extern f32 lbl_1_rodata_6638;
extern const f32 lbl_1_rodata_663C;
extern void fn_1_106084(void *target, s32 index, f32 x, f32 y, f32 z);
extern const f32 lbl_1_rodata_6640;
extern void fn_1_DC6FC(void *context);
extern void fn_1_DC5E8(Obj_1_data_2A7E0_At3C *, s32);
extern void fn_1_FBEA8(void);
extern void fn_1_103F58(void *arg0);
extern void fn_1_9AD88(void);
extern void fn_1_9A508(void);
extern void fn_1_DAF94(Obj *obj);
extern s32 fn_1_5910();
extern u32 fn_1_9D260();
extern void fn_1_1067A8(void *arg0, f32 arg1, f32 arg2);
extern void fn_1_103D28(u8 *base, f32 arg1, u8 count);
extern f32 lbl_1_rodata_66D0[30];
extern void fn_1_72648();
extern void fn_1_103090(void *);
extern void fn_1_1030A4(void *);
extern void **fn_1_54448(s32 arg0);
extern void * fn_1_548AC(u32 amount);
extern void fn_1_DC764(void);
extern void fn_1_5489C(void **arg0, void **arg1);
extern const f64 lbl_1_rodata_6748;
extern void fn_1_D6C10(void *, f32);
extern f32 lbl_1_rodata_6644[35];
extern void lbl_8006DCA4();
extern void fn_1_DB53C(void *arg0, f32 arg1);
extern void fn_1_103264(void *, void *);
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern f32 lbl_1_rodata_6628;
extern void fn_1_FB87C(u32 *values, u8 count);
extern u32 fn_1_FBFE4();
extern void fn_1_FB96C(int index);
extern void fn_1_105AB8(u32 arg0, u32 arg1);
extern u32 lbl_801A66A0;
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006D7DC(void *);
extern void mathutil_mtxA_rotate_z(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_x(s32);
extern void lbl_8006E1B0(void *, void *);
extern DB53CVec lbl_1_bss_7ADB8[];
extern u32 lbl_801A6D00;
extern s32 fn_1_6F84(void);
extern f32 fn_1_DC084(BgSanVec3 *pos);
extern s32 fn_1_54E34(void *arg0, f32 arg1);
extern s16 camera_get_mode(void);
extern u32 camera_get_flags(void);
extern void camera_forward_status(void);
extern void fn_1_862D4(s32, DB53CVec *);
extern u32 fn_1_864E8(int index);
extern u32 fn_1_1FC98(Vec3f *arg0, u32 arg1);
extern u32 fn_1_8627C(s32 index);
extern void fn_1_DB9B0(void *arg0);
extern void u_gxutil_upload_some_mtx(u32, u32);
extern void fn_80072864(u32 arg0);
extern void fn_800728A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80073778(void *obj, s32 index);
extern u32 fn_80036104(void *);
extern u16 GXGetTexObjHeight(void *);
extern u16 GXGetTexObjWidth(void *);
extern void *fn_800360D8(void *);
extern void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
extern void fn_8007245C(u32 value);
extern void fn_800747D0(u32 arg0, u32 arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6);
extern void fn_80073C6C(s32 index);
extern void fn_800745A4(u32 arg0, s32 arg1, s32 arg2, u32 arg3, u32 arg4, u32 arg5);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80072EDC(s32 arg0, s32 arg1);
extern void fn_80073678(u32 arg0);
extern void fn_80074660(u32 arg0);
extern void fn_80074788(u32 arg0);
extern void fn_80073898(u32 arg0);
extern f32 lbl_8006D188(s32);
extern f32 lbl_8006D534(Vec3 *, Vec3 *);
extern f64 __fabs(f64);
extern u32 lbl_8006D46C(f32);
extern void lbl_8006D5F0(Vec3 *, Vec3 *, f32);
extern void fn_1_681C(u32 index, u32 *output);
extern void fn_8003462C(u32 arg0, u32 arg1, u32 arg2);
extern void fn_1_1030D4(void *entry, void *arg);
extern void fn_1_DAAFC();
extern void fn_1_DAB1C();
extern void fn_1_FB9C0(int index);
extern void fn_1_103F10(void *arg);
extern void fn_1_DAB3C();
extern void lbl_8006D91C(s32);
extern void lbl_8006E1C0(void *, void *);
extern void lbl_8006E13C(void *);
extern void lbl_8006DB74(void *);
void fn_1_5948(s32);
extern void fn_1_627C();
extern void fn_1_DB268(Fn1DB268_Effect *effect);
extern void fn_1_DCB10(void);
extern void fn_1_DC648(void *object);
extern u32 fn_1_1FB80(void *pos, u32 mask);

/* fzgx:begin fn_1_D8FC4 */
typedef struct {
    u32 unk_0;
    u8 pad_4[0x4];
    u32 unk_8;
    u8 pad_C[0xA0];
} fn_1_D8FC4_Entry;

typedef struct {
    u8 pad_0[0x6D4];
    s32 unk_6D4;
    fn_1_D8FC4_Entry unk_6D8[1];
} fn_1_D8FC4_Container;

s32 fn_1_D8FC4(s32 arg0, s32 arg1) {
    fn_1_D8FC4_Container *base = (fn_1_D8FC4_Container *)lbl_1_data_2A7E0.unk_3C;

    switch (arg0) {
    case 0:
        base->unk_6D8[base->unk_6D4].unk_8 |= 0x40000000;
        base->unk_6D8[base->unk_6D4].unk_8 |= 0x10000000;
        base->unk_6D8[base->unk_6D4].unk_0 = arg1;
        base->unk_6D4 += 1;
        if (base->unk_6D4 >= 0x20) {
            OSPanic((const char *)lbl_1_data_3DC50, 0x4E7, (const char *)lbl_1_data_3DC5C);
        }
        break;
    case 1:
        base->unk_6D8[base->unk_6D4].unk_8 |= 0x40000000;
        base->unk_6D8[base->unk_6D4].unk_8 |= 0x20000000;
        base->unk_6D8[base->unk_6D4].unk_0 = arg1;
        base->unk_6D4 += 1;
        if (base->unk_6D4 >= 0x20) {
            OSPanic((const char *)lbl_1_data_3DC50, 0x4EE, (const char *)lbl_1_data_3DC5C);
        }
        break;
    case 2:
        base->unk_6D8[base->unk_6D4].unk_8 |= 0x40000000;
        base->unk_6D8[base->unk_6D4].unk_8 |= 0x10000000;
        base->unk_6D8[base->unk_6D4].unk_8 |= 0x08000000;
        base->unk_6D8[base->unk_6D4].unk_0 = arg1;
        base->unk_6D4 += 1;
        if (base->unk_6D4 >= 0x20) {
            OSPanic((const char *)lbl_1_data_3DC50, 0x4F6, (const char *)lbl_1_data_3DC5C);
        }
        break;
    case 3:
        base->unk_6D8[base->unk_6D4].unk_8 |= 0x40000000;
        base->unk_6D8[base->unk_6D4].unk_8 |= 0x20000000;
        base->unk_6D8[base->unk_6D4].unk_8 |= 0x08000000;
        base->unk_6D8[base->unk_6D4].unk_0 = arg1;
        base->unk_6D4 += 1;
        if (base->unk_6D4 >= 0x20) {
            OSPanic((const char *)lbl_1_data_3DC50, 0x4FE, (const char *)lbl_1_data_3DC5C);
        }
        break;
    }
    return 1;
}
/* fzgx:end fn_1_D8FC4 */

/* fzgx:begin fn_1_DA3A0 noprologue */
#include "types.h"
#include "psvec.h"
#include "rel/main_rel/bg_lig.h"

struct Sig_fn_80077B14_fn_80077B14_Arg0 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};
extern f32 lbl_8006D668(u32 *);
extern s32 fn_80077B14(struct Sig_fn_80077B14_fn_80077B14_Arg0 *);
struct VecLocal { f32 a[3]; };
struct VertexLocal { u8 pad[12]; struct VecLocal normal; u8 rest[40]; };
static inline void cross(const struct VecLocal *a, const struct VecLocal *b, struct VecLocal *out) {
 f32 ax, ay, az, bx, bz, by;
 f32 x, y, z;
 ay = a->a[1];
 bz = b->a[2];
 az = a->a[2];
 bx = b->a[0];
 by = b->a[1];
 ax = a->a[0];
 x = ay * bz;
 y = az * bx;
 z = ax * by;
 x = x - az * by;
 y = y - ax * bz;
 z = z - ay * bx;
 out->a[0] = x;
 out->a[1] = y;
 out->a[2] = z;
}
void fn_1_DA3A0(void *arg0, f32 arg1, f32 arg2) {
 u32 v0;
 s32 v1;
 u32 v2;
 u8 *v3;
 f32 v4;
 f32 v5;
 f32 v7;
 u8 *v16;
 u32 v17;
 s32 v18;
 s32 v19;
 struct VecLocal loc_20;
 struct VecLocal loc_14;
 struct VecLocal loc_8;
 if (arg0 != 0) {
  v0 = *(u32 *)((u8 *)arg0 + 4);
  if (v0 != 0) {
   v1 = fn_80077B14((struct Sig_fn_80077B14_fn_80077B14_Arg0 *)v0);
   v2 = 0;
   v3 = (u8 *)(*(u32 *)((u8 *)arg0 + 20) + 2108);
   while (v2 < (*(u32 *)((u8 *)arg0 + 12) - 31)) {
    if (v2 > (*(u32 *)((u8 *)arg0 + 12) - 12)) {
     if (v2 + 1 == 11) {
      psvec_sub(v3 + -52, v3 + 16, &loc_20);
      psvec_sub(v3 + -732, v3 + 16, &loc_14);
      lbl_8006D668((u32 *)&loc_20);
      lbl_8006D668((u32 *)&loc_14);
      cross(&loc_20, &loc_14, &loc_8);
     } else {
      psvec_sub(v3 + -732, v3 + 16, &loc_20);
      psvec_sub(v3 + 84, v3 + 16, &loc_14);
      lbl_8006D668((u32 *)&loc_20);
      lbl_8006D668((u32 *)&loc_14);
      cross(&loc_20, &loc_14, &loc_8);
     }
    } else {
     if (v2 + 1 == 11) {
      psvec_sub(v3 + 764, v3 + 16, &loc_20);
      psvec_sub(v3 + -52, v3 + 16, &loc_14);
      lbl_8006D668((u32 *)&loc_20);
      lbl_8006D668((u32 *)&loc_14);
      cross(&loc_20, &loc_14, &loc_8);
     } else {
      psvec_sub(v3 + 84, v3 + 16, &loc_20);
      psvec_sub(v3 + 764, v3 + 16, &loc_14);
      lbl_8006D668((u32 *)&loc_20);
      lbl_8006D668((u32 *)&loc_14);
      cross(&loc_20, &loc_14, &loc_8);
     }
    }
    v16 = v3;
    v17 = 0;
    while (v17 < *(u8 *)(v3 + 2)) {
     v18 = *(u16 *)(v16 + 4);
     v16 += 2;
     v17++;
     v19 = v1 + ((v18 << 6) + 12);
     ((struct VertexLocal *)v1)[v18].normal = loc_8;
    }
    v2++;
    v3 += 68;
   }
  }
 }
}
/* fzgx:end fn_1_DA3A0 */

/* fzgx:begin fn_1_DA6A8 */
struct fn_1_DA6A8_Copy12 { u32 a[3]; };

struct FzgxCopy_12 { u32 words[3]; };
void fn_1_DA6A8(void *arg0, struct Sig_fn_80077B64_fn_80077B64_Arg0 *arg1) {
    s32 temp_r5;
    s32 var_r3;
    s32 var_r6;
    u32 *temp_r30;
    u32 temp_r4;
    u32 temp_r4_2;
    u32 temp_r4_3;
    u32 var_r7;

    if (arg0 != NULL) {
        temp_r30 = (u32 *)(fn_80077B64((struct Sig_fn_80077B64_fn_80077B64_Arg0 *)(arg1)));
        var_r3 = fn_80077B14((struct Sig_fn_80077B14_fn_80077B14_Arg0 *)((struct Sig_fn_80077B14_fn_80077B14_Arg0 *) arg1));
        var_r7 = 0U;
        var_r6 = 0;
        while (var_r7 < (u32) (*(u32 *)((u8 *)(temp_r30) + 0))) {
            var_r7 += 1;
            temp_r5 = (*(u32 *)((u8 *)(arg0) + 28)) + var_r6;
            var_r6 += 0xC;
            *(struct FzgxCopy_12 *)(var_r3) = *(const struct FzgxCopy_12 *)(temp_r5);
            var_r3 += 0x40;
                    }
        temp_r4 = *(u32 *)((u8 *)(arg0) + 20);
        if (temp_r4 != 0) {
            fn_1_46B4(lbl_801A6410.unk_0, temp_r4, (const char *)((s8 *) &(*(u32 *)&lbl_1_data_3DC50)), 0x6B6);
        }
        temp_r4_2 = *(u32 *)((u8 *)(arg0) + 24);
        if (temp_r4_2 != 0) {
            fn_1_46B4(lbl_801A6410.unk_0, temp_r4_2, (const char *)((s8 *) &(*(u32 *)&lbl_1_data_3DC50)), 0x6B9);
        }
        temp_r4_3 = *(u32 *)((u8 *)(arg0) + 28);
        if (temp_r4_3 != 0) {
            fn_1_46B4(lbl_801A6410.unk_0, temp_r4_3, (const char *)((s8 *) &(*(u32 *)&lbl_1_data_3DC50)), 0x6BC);
        }
    }
}
/* fzgx:end fn_1_DA6A8 */

/* fzgx:begin fn_1_DA7B8 */
// Forwards the active background state to the next processing stage.
void fn_1_DA7B8(void) {
    fn_1_DAAFC(lbl_1_data_2A7E0.unk_3C);
}
/* fzgx:end fn_1_DA7B8 */

/* fzgx:begin fn_1_DA7E4 */
struct fn_1_DA7E4_Sub {
    u8 pad_0[0x9A0];
    u32 blk[141];
    u32 unk_BD4;
    u32 unk_BD8;
};

struct fn_1_DA7E4_lbl_1_data_2A7E0 {
    u8 pad_0[0x2C];
    u32 unk_2C;
    u8 pad_30[0xC];
    struct fn_1_DA7E4_Sub *unk_3C;
};


void fn_1_DA7E4(void) {
    struct fn_1_DA7E4_Sub *obj;
    u32 tmp[4];
    s32 n;
    s32 i;

    obj = (*((struct fn_1_DA7E4_lbl_1_data_2A7E0 *)&lbl_1_data_2A7E0)).unk_3C;
    n = fn_1_58C4();
    for (i = 0; i < n; i++) {
        tmp[i] = obj->blk[i];
    }
    fn_1_9A508();
    n = fn_1_58C4();
    for (i = 0; i < n; i++) {
        obj->blk[i] = tmp[i];
    }
    if (obj->unk_BD4 != 0) {
        fn_1_FB87C(&obj->unk_BD4, 1);
        fn_1_FB96C(0);
        fn_1_FB96C(1);
        fn_1_FB96C(2);
        fn_1_FB96C(4);
    }
    (*((struct fn_1_DA7E4_lbl_1_data_2A7E0 *)&lbl_1_data_2A7E0)).unk_2C = (u32)fn_1_FBFE4;
    fn_1_103D28((u8 *)(&obj->unk_BD8), lbl_1_rodata_6628, (u8)(10));
}
/* fzgx:end fn_1_DA7E4 */

/* fzgx:begin fn_1_DA9F0 */
// Applies the background transition after the scene reports readiness.
void fn_1_DA9F0(void) {
    Obj_1_data_2A7E0_At3C *background_state = lbl_1_data_2A7E0.unk_3C;

    if ((u32)fn_1_58C4() == 1) {
        fn_1_DAB1C(background_state);
    }
}
/* fzgx:end fn_1_DA9F0 */

/* fzgx:begin fn_1_DAA34 */
void fn_1_DAA34(void) {
    fn_1_9AD54();
    fn_1_FBEA8();
}
/* fzgx:end fn_1_DAA34 */

/* fzgx:begin fn_1_DAA58 */
// Loads pending background resources before advancing the scene state.
void fn_1_DAA58(void) {
    Obj_1_data_2A7E0_At3C *state = lbl_1_data_2A7E0.unk_3C;

    if (state->unk_BD4 != 0) {
        fn_1_FB9C0(0);
        fn_1_FB9C0(1);
        fn_1_FB9C0(2);
        fn_1_FB9C0(4);
    }

    fn_1_103F10(&state->unk_BD8);
    fn_1_DAB3C(state);
}
/* fzgx:end fn_1_DAA58 */

/* fzgx:begin fn_1_DAAC4 */
void fn_1_DAAC4(void) {
    fn_1_103F58(&lbl_1_data_2A7E0.unk_3C->unk_BD8);
    fn_1_9AD88();
}
/* fzgx:end fn_1_DAAC4 */

/* fzgx:begin fn_1_DAAF8 */
// fn_1_DAAF8: empty in retail (single blr).
void fn_1_DAAF8(void) {
}
/* fzgx:end fn_1_DAAF8 */

/* fzgx:begin fn_1_DAAFC */
// Initialize the background-san subsystem through its shared setup routine.
void fn_1_DAAFC(void) {
    fn_1_58C4();
}
/* fzgx:end fn_1_DAAFC */

/* fzgx:begin fn_1_DAB1C */
// Runs the background sanitation update.
void fn_1_DAB1C(void) {
    fn_1_58C4();
}
/* fzgx:end fn_1_DAB1C */

/* fzgx:begin fn_1_DAB3C */
// Perform the background sanitation step.
void fn_1_DAB3C(void) {
    fn_1_58C4();
}
/* fzgx:end fn_1_DAB3C */

/* fzgx:begin fn_1_DAB5C */
typedef struct {
    u8 pad_0[0x14];
    f32 unk_14;
    u8 pad_18[0xC];
    u32 unk_24;
} Fn1DAB5C_Obj;

s32 fn_1_DAB5C(s32 mode, Fn1DAB5C_Obj **arg) {
    Obj_1_data_2A7E0_At3C *dest;
    Fn1DAB5C_Obj *obj;
    u32 val;

    obj = *arg;
    dest = lbl_1_data_2A7E0.unk_3C;
    val = obj->unk_24;
    switch (mode) {
    case 1:
        dest->unk_BD4 = val;
        break;
    case 3:
        dest->unk_AF0 = obj->unk_14;
        break;
    case 4:
        dest->unk_18AC = (u32)obj;
        break;
    }
    return 1;
}
/* fzgx:end fn_1_DAB5C */

/* fzgx:begin fn_1_DABB4 */
typedef struct {
    u32 flags;
    u8 pad_4[0x8];
    Fn1DABB4_Vec pos;
    s16 rot_x;
    s16 rot_y;
    s16 rot_z;
    u8 pad_1E[0x2];
    f32 scale_x;
    f32 scale_y;
    f32 scale_z;
} Fn1DABB4_Obj;

typedef struct {
    Fn1DABB4_Obj *obj;
    Fn1DABB4_Vec pos;
    u8 unk_10[0xC];
    u8 unk_1C[0x30];
    f32 radius;
} Fn1DABB4_Entry;


#define MAX(a, b) ((a) > (b) ? (a) : (b))

s32 fn_1_DABB4(s32 mode, Fn1DABB4_Obj *obj) {
    Obj_1_data_2A7E0_At3C *dest;
    Fn1DABB4_Entry *entry;
    Fn1DABB4_Vec vec;
    s32 count;

    dest = lbl_1_data_2A7E0.unk_3C;
    switch (mode) {
    case 0:
        obj->flags |= 0x2000000;
        break;
    case 1:
        obj->flags |= 0x2000000;
        break;
    case 2:
    case 3:
        obj->flags |= 0x2000000;
        break;
    case 4:
        obj->flags |= 0x4000000;
        count = dest->unk_10;
        if (count < 30) {
            entry = (Fn1DABB4_Entry *)((u8 *)dest + 0x14 + count * 0x50);
            vec = lbl_1_rodata_662C;
            entry->obj = obj;
            entry->pos.x = obj->pos.x;
            entry->pos.y = obj->pos.y;
            entry->pos.z = obj->pos.z;
            lbl_8006D91C(obj->rot_z);
            mathutil_mtxA_rotate_y(obj->rot_y);
            mathutil_mtxA_rotate_x(obj->rot_x);
            lbl_8006E1C0(&vec, entry->unk_10);
            lbl_8006D7DC(&obj->pos);
            mathutil_mtxA_rotate_z(obj->rot_z);
            mathutil_mtxA_rotate_y(obj->rot_y);
            mathutil_mtxA_rotate_x(obj->rot_x);
            lbl_8006E13C(&obj->scale_x);
            lbl_8006DB74(entry->unk_1C);
            dest->unk_10++;
            entry->radius = MAX(obj->scale_x, MAX(obj->scale_y, obj->scale_z));
        }
        break;
    case 8:
        dest->unk_BD8 = (u32)obj;
        break;
    }
    return 1;
}
/* fzgx:end fn_1_DABB4 */

/* fzgx:begin fn_1_DAD68 */
// fn_1_DAD68: empty in retail (single blr).
void fn_1_DAD68(void) {
}
/* fzgx:end fn_1_DAD68 */

/* fzgx:begin fn_1_DAD6C */
void fn_1_DAD6C(void) {
    Obj_1_data_2A7E0_At3C *obj;

    obj = lbl_1_data_2A7E0.unk_3C;
    fn_1_9A508();
    fn_1_DAF94( (Obj *)(Obj_1_data_2A7E0_At3C *)(obj));
}
/* fzgx:end fn_1_DAD6C */

/* fzgx:begin fn_1_DADA8 */
struct fn_1_DADA8_lbl_1_data_2A7E0 {
    u8 pad_0[0x3C];
    u32 unk_3C;
};

void fn_1_DADA8(void) {
    u32 v0;
    s32 v1;
    u32 t0;
    v0 = (*(struct fn_1_DADA8_lbl_1_data_2A7E0 *)&lbl_1_data_2A7E0).unk_3C;
    t0 = (u32)fn_1_58C4();
    v1 = 0;
    while (v1 < (s32)t0) {
    fn_1_5948( (u32)(v1));
    fn_1_105AB8(((v0 + 0x10000) + 17056), v1);
    fn_1_627C( (u32)(v1));
    v1++;
    }
}
/* fzgx:end fn_1_DADA8 */

/* fzgx:begin fn_1_DAE24 */

/* Per-frame update of the san background: spawns effects for each active slot. */
void fn_1_DAE24(void) {
    s32 count;
    f32 *value;
    s32 index;
    u32 object;

    object = (u32)lbl_1_data_2A7E0.unk_3C;
    fn_1_9AD54();
    count = fn_1_58C4();
    value = (f32 *)object;
    for (index = 0; index < count; index++) {
        fn_1_5948(index);
        if (fn_1_7B054() == 42) {
            if (fn_1_3F0C8() != 39) {
                fn_1_106084((void *)(object + 0x142a0), index, lbl_1_rodata_6638, *value, lbl_1_rodata_663C);
            }
        }
        fn_1_627C(index);
        value++;
    }
    fn_1_DB138((void *)object);
}
/* fzgx:end fn_1_DAE24 */

/* fzgx:begin fn_1_DAEF8 */
// fn_1_DAEF8: empty in retail (single blr).
void fn_1_DAEF8(void) {
}
/* fzgx:end fn_1_DAEF8 */

/* fzgx:begin fn_1_DAEFC */
// Initializes the current background object and updates it for the active state.
void fn_1_DAEFC(void) {
    s32 slot;
    Obj_1_data_2A7E0_At3C *background;

    slot = fn_1_5910();
    background = lbl_1_data_2A7E0.unk_3C;
    fn_1_DB198( (BgSanObject *)(void *)(background), (void *)fn_1_9D260(&lbl_1_data_2A7E0));
    fn_1_9AD88();
    if (fn_1_7B054() == 42) {
        if (fn_1_3F0C8() != 39) {
            fn_1_1067A8(
                (u8 *)background + 0x142a0,
                ((f32 *)background)[slot],
                lbl_1_rodata_663C
            );
        }
    }
}
/* fzgx:end fn_1_DAEFC */

/* fzgx:begin fn_1_DAF90 */
// fn_1_DAF90: empty in retail (single blr).
void fn_1_DAF90(void) {
}
/* fzgx:end fn_1_DAF90 */

/* fzgx:begin fn_1_DAF94 */


void fn_1_DAF94(Obj *obj) {
    Entry *e = obj->entries;
    if ((u32)fn_1_58C4() < 2) {
        f32 one;
        f32 zero;
        Src *s;
        s32 n;
        zero = (*((const f32 *)&lbl_1_rodata_6638));
        one = lbl_1_rodata_6640;
        n = obj->count;
        for (; n > 0; n--) {
            s32 i;
            Elem *p;
            s = e->src;
            obj->entries[0].a = 0;
            obj->entries[0].b = zero;
            for (i = 128, p = obj->entries[0].first; i != 0; i--, p++) {
                p->pos = s->pos;
                p->w = zero;
            }
            for (i = 128, p = obj->entries[0].second; i != 0; i--, p++) {
                p->pos = s->pos;
                p->w = zero;
            }
            e->cur = s->pos;
            e->zero = 0;
            e->one = one;
            e++;
        }
    }
}
/* fzgx:end fn_1_DAF94 */

/* fzgx:begin fn_1_DB138 */
// Process each background-san entry when the object is in an eligible state.
void fn_1_DB138(BgSanContext *context) {
    u8 *entry;
    s32 count;

    if ((u32)fn_1_58C4(context) < 2) {
        count = context->unk_10;
        entry = (u8 *)context + 0x14;
        while (count > 0) {
            fn_1_DB268( (Fn1DB268_Effect *)(void *)(entry));
            count -= 1;
            entry += 0x1020;
        }
    }
}
/* fzgx:end fn_1_DB138 */

/* fzgx:begin fn_1_DB198 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_san.h"
#include "game/main_rel/bg_san_types.h"

extern s32 fn_1_58C4();
extern void * fn_1_548AC(u32 amount);
extern void fn_1_DC764();  /* takes the handler (reads handler->unk_08); non-prototype so Handler.unk_04 accepts it */
extern void fn_1_5489C(void **arg0, void **arg1);
extern f32 lbl_1_rodata_6644[35];
extern void lbl_8006DCA4(void *data);
extern void fn_1_DB53C(void);

typedef struct BgSanAllocation {
    u8 unk_00[0x4];
    void (*unk_04)(void);
    void *unk_08;
} BgSanAllocation;


// Builds a scaled position event when the object is active.
void fn_1_DB198(BgSanObject *object, void *arg1) {
    BgSanPosition position;
    void *result;
    BgSanAllocation *allocation;

    if ((u32)fn_1_58C4((Obj_1_data_2A7E0 *)object) < 2 && object->unk_10 != 0) {
        position.unk_00 = (((f32 *)object->unk_14)[3] + object->unk_824) * lbl_1_rodata_6644[0];
        position.unk_04 = (((f32 *)object->unk_14)[4] + object->unk_828) * lbl_1_rodata_6644[0];
        position.unk_08 = (((f32 *)object->unk_14)[5] + object->unk_82c) * lbl_1_rodata_6644[0];
        lbl_8006DCA4(object->unk_14);
        result = fn_1_5448C(&position);
        allocation = (BgSanAllocation *)fn_1_548AC( (s32)(12));
        if (allocation != 0) {
            allocation->unk_04 = fn_1_DB53C;
            allocation->unk_08 = arg1;
            fn_1_5489C( (void **)(void *)(result), (void **)(void *)(allocation));
        }
    }
}
/* fzgx:end fn_1_DB198 */

/* fzgx:begin fn_1_DB268 */
extern struct fn_1_DA6A8_lbl_801A6410 lbl_801A6410;
extern void * fn_80077B64(struct Sig_fn_80077B64_fn_80077B64_Arg0 *);

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 30.0f;
    s = 1.0f;
    s = 0.5f;
}
#pragma section code_type ".text"







void fn_1_DB268(Fn1DB268_Effect *effect) {
    Fn1DB268_Trail *slot; /* the trail shifted to the head entry: slot->upper[0] is upper[head] */
    Fn1DB268_Source *source;
    Fn1DB268_Trail *trail;
    Fn1DB268_Vec vecs[2];
    f32 dist;
    f32 drop;
    f32 dz;
    f32 dy;
    f32 dx;
    f32 rise;
    s32 i;
    Fn1DB268_Point *upper;
    Fn1DB268_Point *lower;

    if ((u32)fn_1_58C4() >= 2) {
        return;
    }
    source = effect->source;
    trail = &effect->trail;
    if (lbl_801A66A0 & 1) {
        return;
    }
    if (effect->age < 0xF8) {
        effect->age++;
    }
    dx = source->pos.x - effect->pos.x;
    dy = source->pos.y - effect->pos.y;
    dz = source->pos.z - effect->pos.z;
    vecs[1].x = dx;
    vecs[1].y = dy;
    vecs[1].z = dz;
    dist = dx * dx;
    dist += dy * dy;
    dist += dz * dz;
    dist = lbl_8006D0B4(dist);
    trail->head = (trail->head + 1) % 128;
    slot = (Fn1DB268_Trail *)((u8 *)trail + trail->head * sizeof(Fn1DB268_Point));
    lbl_8006D7DC(&source->pos);
    mathutil_mtxA_rotate_z(source->rot_z);
    mathutil_mtxA_rotate_y(source->rot_y);
    mathutil_mtxA_rotate_x(source->rot_x);
    rise = 25.0f;
    rise *= source->scale;
    {
        Fn1DB268_Vec offset = {0.0f, 0.0f, 0.0f};
        offset.y = rise;
        vecs[0] = offset;
        lbl_8006E1B0(&vecs[0], &vecs[0]);
        slot->upper[0].pos = vecs[0];
    }
    {
        Fn1DB268_Vec offset = {0.0f, 0.0f, 0.0f};
        offset.y = -rise;
        vecs[0] = offset;
        lbl_8006E1B0(&vecs[0], &vecs[0]);
        slot->lower[0].pos = vecs[0];
    }
    drop = 0.1f * dist;
    trail->height -= drop;
    slot->upper[0].height = trail->height;
    slot->lower[0].height = trail->height;
    upper = trail->upper;
    lower = trail->lower;
    for (i = 0; i < 128; i++, upper++, lower++) {
        if (i != trail->head) {
            upper->height += 0.02f * dist;
            lower->height += 0.02f * dist;
        }
    }
    effect->pos = source->pos;
}
/* fzgx:end fn_1_DB268 */

/* fzgx:begin fn_1_DB53C noprologue */
#include "types.h"

typedef struct DB53CVec {
    f32 x;
    f32 y;
    f32 z;
} DB53CVec;

typedef struct DB53CObj {
    u8 pad_0[0x4];
    u32 mask;
    u8 pad_8[0x4];
    DB53CVec pos;
} DB53CObj;

typedef struct DB53CItem {
    DB53CObj *obj;
    u8 pad_4[0x10];
    f32 alpha;
    u8 pad_18[0x808];
    DB53CVec pos;
    u8 pad_82C[0x7F4];
} DB53CItem;

typedef struct DB53CGroup {
    u8 pad_0[0x10];
    s32 count;
    DB53CItem items[1];
} DB53CGroup;

typedef struct DB53CEntry {
    u8 pad_0[0x8];
    u8 *data;
} DB53CEntry;

typedef struct DB53CTable {
    u8 pad_0[0xC];
    DB53CEntry *entries;
} DB53CTable;

typedef struct DB53CGlobal3BE0 {
    DB53CTable *table;
} DB53CGlobal3BE0;

typedef struct DB53CTexHolder {
    u8 pad_0[0x24];
    void *tex;
} DB53CTexHolder;

typedef struct DB53CScene {
    u8 pad_0[0x1C0];
    DB53CTexHolder *holder;
} DB53CScene;

typedef struct DB53CRoot {
    u8 pad_0[0x8];
    DB53CScene *scene;
} DB53CRoot;

typedef struct DB53CData2A7E0 {
    u8 pad_0[0x3C];
    DB53CGroup *group;
} DB53CData2A7E0;

extern DB53CRoot *lbl_1_bss_38458;
extern DB53CData2A7E0 lbl_1_data_2A7E0;
extern DB53CGlobal3BE0 lbl_1_bss_3BE0;
extern DB53CVec lbl_1_bss_7ADB8[];
extern s32 lbl_1_data_3DC70;
extern u32 lbl_801A6D00;

extern u32 fn_1_58C4(void);
extern s32 fn_1_5910(void);
extern s32 fn_1_6F84(void);
extern f32 fn_1_DC084(DB53CVec *);
extern s32 fn_1_54E34(DB53CVec *, f32);
extern s16 fn_1_3F0C8(void);
extern s16 camera_get_mode(void);
extern s32 camera_get_flags(void);
extern u32 camera_forward_status(void);
extern void fn_1_862D4(s32, DB53CVec *);
extern u32 fn_1_864E8(s32);
extern u32 fn_1_1FC98(DB53CVec *, s32);
extern u8 *fn_1_8627C(s32);
extern void fn_1_DB9B0(DB53CItem *, void *);
extern void lbl_8006DCA4(void);
extern void u_gxutil_upload_some_mtx(u32, u32);
extern void fn_80072864(s32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80073778(void *, s32);
extern u32 fn_80036104(void *);
extern u16 GXGetTexObjHeight(void *);
extern u16 GXGetTexObjWidth(void *);
extern void *fn_800360D8(void *);
extern void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
extern void fn_8007245C(u32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern void fn_80073C6C(s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80072EDC(s32, s32);
extern void fn_80073678(u32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_80073898(u32);

/* Pool primer: reproduces the TU's shared literal pool layout (lbl_1_rodata_6638). */
#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_pool_primer_0(f32 *out) {
    out[0] = 0.0f;
    out[1] = 30.0f;
    out[2] = 1.0f;
    out[3] = 0.5f;
}

static const u32 fzgx_pool_table_10[6] = { 0, 0, 0, 0, 0, 0 };

__declspec(section ".fzgxpool") void fzgx_pool_primer_1(f32 *out, const u32 **table) {
    *table = fzgx_pool_table_10;
    out[0] = 25.0f;
    out[1] = 0.1f;
    out[2] = 0.02f;
    out[3] = 2000.0f;
    out[4] = 2500.0f;
    out[5] = 500.0f;
    out[6] = 650.0f;
}

void fn_1_DB53C(void *arg0, f32 arg1) {
    DB53CVec mid;
    DB53CVec b;
    DB53CVec a;
    DB53CVec pos;
    DB53CItem *item;
    s32 count;
    void *ctx;
    s32 mode;
    u32 flags;
    void *tex;
    DB53CGroup *group;
    f32 dist;

    if (fn_1_58C4() >= 2) {
        return;
    }

    ctx = *(void **)((u8 *)arg0 + 8);
    group = lbl_1_data_2A7E0.group;
    item = group->items;
    tex = lbl_1_bss_38458->scene->holder->tex;

    lbl_8006DCA4();
    u_gxutil_upload_some_mtx(lbl_801A6D00, 0);
    fn_80072864(0);
    fn_800728A8(1, 4, 1, 0);
    fn_80073778(tex, 0);
    GXInitTexObj(tex, fn_800360D8(tex), GXGetTexObjWidth(tex), GXGetTexObjHeight(tex),
                 fn_80036104(tex), 0, 1, 0);
    fn_8007245C(0x2A00);
    fn_800747D0(4, 0, 1, 1, 0, 2, 2);
    fn_80073C6C(0);
    fn_800745A4(0, 1, 4, 60, 0, 125);
    fn_800734A8(0, 0, 0, 4);
    fn_80072EDC(0, 0);
    fn_80073678(1);
    fn_80074660(1);
    fn_80074788(1);
    fn_80073898(0);

    for (count = group->count; count > 0; count--, item++) {
        b = item->obj->pos;
        a = item->pos;
        mid.x = 0.5f * (a.x + b.x);
        mid.y = 0.5f * (a.y + b.y);
        mid.z = 0.5f * (a.z + b.z);

        dist = fn_1_DC084(&mid);
        if (dist > 2000.0f) {
            if (dist > 2500.0f) {
                item->alpha = 0.0f;
                continue;
            }
            item->alpha = 1.0f - (dist - 2000.0f) / 500.0f;
        } else {
            item->alpha = 1.0f;
        }

        lbl_8006DCA4();
        if (fn_1_54E34(&mid, 650.0f) == 0 && fn_1_3F0C8() != 39) {
            continue;
        }

        flags = 0;
        mode = camera_get_mode();
        if (camera_get_flags() != 0 && lbl_1_data_3DC70 >= 0) {
            mode = lbl_1_data_3DC70;
        }
        lbl_1_data_3DC70 = mode;

        if (mode >= 0) {
            u8 *cam;

            fn_1_862D4(mode, &pos);
            if (fn_1_864E8(mode) & 0x800) {
                pos = lbl_1_bss_7ADB8[fn_1_5910()];
            } else if (fn_1_6F84() != 0) {
                if (camera_forward_status() & 0x80000000) {
                    lbl_1_bss_7ADB8[fn_1_5910()] = pos;
                } else {
                    pos = lbl_1_bss_7ADB8[fn_1_5910()];
                }
            } else {
                lbl_1_bss_7ADB8[fn_1_5910()] = pos;
            }
            flags = fn_1_1FC98(&pos, -1);
            cam = fn_1_8627C(mode);
            if (cam != NULL) {
                s32 idx = *(s32 *)(cam + 0xB8);
                if (idx >= 0) {
                    u8 *data = lbl_1_bss_3BE0.table->entries[idx].data;
                    if (data != NULL) {
                        flags |= *(u32 *)(data + 0x38);
                    }
                }
            }
        }

        if (flags & item->obj->mask) {
            fn_1_DB9B0(item, ctx);
        } else if (fn_1_3F0C8() == 39) {
            fn_1_DB9B0(item, ctx);
        }
    }
}
/* fzgx:end fn_1_DB53C */

/* fzgx:begin fn_1_DB9B0 */
typedef struct Sig_fn_1_DB9B0_DB53CVec {
    f32 x; f32 y; f32 z;
} Sig_fn_1_DB9B0_DB53CVec;
typedef struct Sig_fn_1_DB9B0_DB53CObj {
    u8 pad_0[0x4];
    u32 mask;
    u8 pad_8[0x4];
    Sig_fn_1_DB9B0_DB53CVec pos;
} Sig_fn_1_DB9B0_DB53CObj;
typedef struct Sig_fn_1_DB9B0_DB53CItem {
    Sig_fn_1_DB9B0_DB53CObj *obj;
    u8 pad_4[0x10];
    f32 alpha;
    u8 pad_18[0x808];
    Sig_fn_1_DB9B0_DB53CVec pos;
    u8 pad_82C[0x7F4];
} Sig_fn_1_DB9B0_DB53CItem;
typedef struct DB9B0Point { Vec3 pos; f32 t; } DB9B0Point;
typedef struct DB9B0Trail { s16 head; u8 pad_2[6]; DB9B0Point a[128]; DB9B0Point b[128]; } DB9B0Trail;
typedef union DB9B0Pipe { f32 f; u8 b; } DB9B0Pipe;
// Graphics FIFO accesses are volatile hardware writes.
#define wgPipe (*(volatile DB9B0Pipe *)&GXWGFifo)
#define DB9B0_PIPE_F wgPipe.f

/* Prime the module's shared literal pool in retail order. */
#pragma section code_type ".fzgxpool"
void fzgx_DB9B0_pool_head(void) {
    lbl_8006D46C(0.0f);
    lbl_8006D46C(30.0f);
    lbl_8006D46C(1.0f);
    lbl_8006D46C(0.5f);
}
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
void fzgx_DB9B0_pool_vectors(void) {
    Vec3 a = {0.0f, 0.0f, 0.0f};
    Vec3 b = {0.0f, 0.0f, 0.0f};
    lbl_8006D534(&a, &b);
    lbl_8006D46C(25.0f);
    lbl_8006D46C(0.1f);
    lbl_8006D46C(0.02f);
    lbl_8006D46C(2000.0f);
    lbl_8006D46C(2500.0f);
    lbl_8006D46C(500.0f);
    lbl_8006D46C(650.0f);
}
#pragma section code_type ".text"

static inline void DB9B0_cross(Vec3 *a, Vec3 *b, Vec3 *out) {
    f32 x = a->y * b->z;
    f32 y = a->z * b->x;
    f32 z = a->x * b->y;
    z -= ((a->y) * (b->x));
    x -= a->z * b->y;
    y -= a->x * b->z;
    out->y = y;
    out->x = x;
    out->z = z;
}

static inline void DB9B0_position_yzx(f32 y, f32 z, f32 x) {
    wgPipe.f = x; wgPipe.f = y; wgPipe.f = z;
}
static inline void DB9B0_position(f64 x, f32 y, f32 z) {
    wgPipe.f = x; wgPipe.f = y; wgPipe.f = z;
}
static inline void DB9B0_color(u8 r, u8 g, u8 b, u8 a) {
    wgPipe.b = r; wgPipe.b = g; wgPipe.b = b; wgPipe.b = a;
}
static inline void DB9B0_tex(f32 s, f32 t) {
    wgPipe.f = s; wgPipe.f = t;
}

#pragma opt_lifetimes off
void fn_1_DB9B0(void *arg0) {
    s32 v3_r2;
    const struct fn_1_DB9B0_lbl_1_rodata_6638 *p_lbl_1_rodata_6638 = ((const struct fn_1_DB9B0_lbl_1_rodata_6638 *)&lbl_1_rodata_6638);
    Sig_fn_1_DB9B0_DB53CObj *v1;
    u8 *v0;
    s32 v3;
    DB9B0Point *v52;
    f32 v20, v33, v49, v62;
    s32 v34, v63, v43;
    if ((u32)fn_1_58C4() < 2) {
        v0 = (u8 *)arg0 + 24;
        v1 = *(Sig_fn_1_DB9B0_DB53CObj **)arg0;
        if (*(s32 *)((u8 *)arg0 + 16) >= 128) {
            fn_8003462C(152, 0, 30);
            {
            Vec3 loc_8C, loc_80;
            s32 v19 = (*(s16 *)v0 + 1) % 128;
            Vec3 loc_74 = { 0.5f, 0.0f, 0.0f };
            Vec3 loc_68, loc_5C, loc_50;
            DB9B0Point *v25;
            s32 next;
            for (v3 = 0; v3 < 15; v3++) {
                v20 = (f32)v3 / 14.0f;
                fn_1_681C((u8)fn_1_5910(), (u32 *)&loc_50);
                next = v19;
                v19 = (v19 + 8) % 128;
                v25 = (DB9B0Point *)(v0 + (next << 4) + 8);
                psvec_sub(&v25->pos, &loc_50, &loc_8C);
                psvec_sub(&v25->pos, &((DB9B0Trail *)v0)->a[v19].pos, &loc_80);
                DB9B0_cross(&loc_8C, &loc_80, &loc_68);
                if (0.0 != loc_68.x ||
                    0.0 != loc_68.y ||
                    0.0 != loc_68.z) {
                    lbl_8006D5F0(&loc_68, &loc_74, 0.5f);
                }
                psvec_scale(&loc_74, (f32)((2.5 * *(f32 *)((u8 *)v1 + 32)) * (1.0 + v20)), &loc_5C);
                v33 = (f32)__fabs(lbl_8006D188(lbl_8006D46C(lbl_8006D534(&loc_8C, &loc_80))));
                v34 = (s32)(v33 * (255.0f * lbl_8006D188((s32)(32768.0f * v20))));
                if (*(s32 *)((u8 *)arg0 + 16) < 248) {
                    v34 = (s32)((f32)(u32)(u8)v34 * ((f32)(*(s32 *)((u8 *)arg0 + 16) - 128) / 120.0f));
                }
                v34 = (s32)((f32)(u32)(u8)v34 * *(f32 *)((u8 *)arg0 + 20));
                {
                f32 positionX = ((volatile DB9B0Point *)v25)->pos.x;  /* fzgx-allow: S2 volatile view keeps the verified load order */
                f32 offsetX = loc_5C.x;
                DB9B0_position_yzx(v25->pos.y + loc_5C.y, v25->pos.z + loc_5C.z, positionX + offsetX);
                DB9B0_color(255, 255, 255, v34);
                DB9B0_tex(0.0f, v25->t);
                DB9B0_position_yzx(v25->pos.y - loc_5C.y, v25->pos.z - loc_5C.z, v25->pos.x - offsetX);
                DB9B0_color(255, 255, 255, v34);
                DB9B0_tex(1.0f, v25->t);
                }
            }
            }
            fn_8003462C(152, 0, 30);
            {
            Vec3 loc_44, loc_38;
            s32 v13 = (*(s16 *)v0 + 1) % 128;
            Vec3 loc_2C = { 0.5f, 0.0f, 0.0f };
            Vec3 loc_20, loc_14, loc_8;
            for (v3_r2 = 0; v3_r2 < 15; v3_r2++) {
                v49 = (f32)v3_r2 / 14.0f;
                fn_1_681C((u8)fn_1_5910(), (u32 *)&loc_8);
                v43 = v13;
                v13 = (v13 + 8) % 128;
                v52 = (DB9B0Point *)((u32)v0 + (u32)(v43 << 4) + 2056);
                psvec_sub(&v52->pos, &loc_8, &loc_44);
                psvec_sub(&v52->pos, (void *)((u32)v0 + (u32)(v13 << 4) + 2056), &loc_38);
                DB9B0_cross(&loc_44, &loc_38, &loc_20);
                if (0.0 != loc_20.x ||
                    0.0 != loc_20.y ||
                    0.0 != loc_20.z) {
                    lbl_8006D5F0(&loc_20, &loc_2C, 0.5f);
                }
                psvec_scale(&loc_2C, (f32)((2.5 * *(f32 *)((u8 *)v1 + 32)) * (1.0 + v49)), &loc_14);
                v62 = (f32)__fabs(lbl_8006D188(lbl_8006D46C(lbl_8006D534(&loc_44, &loc_38))));
                v63 = (s32)(v62 * (255.0f * lbl_8006D188((s32)(32768.0f * v49))));
                if (*(s32 *)((u8 *)arg0 + 16) < 248) {
                    v63 = (s32)((f32)(u32)(u8)v63 * ((f32)(*(s32 *)((u8 *)arg0 + 16) - 128) / 120.0f));
                }
                {
                    f32 baseX = ((volatile DB9B0Point *)v52)->pos.x;  /* fzgx-allow: S2 volatile view keeps the verified load order */
                    f32 offsetX = loc_14.x;
                    f32 positionX = baseX + offsetX;
                    DB9B0_position(positionX, v52->pos.y + loc_14.y, v52->pos.z + loc_14.z);
                    DB9B0_color(255, 255, 255, v63);
                    DB9B0_tex(0.0f, v52->t);
                    DB9B0_position(v52->pos.x - offsetX, v52->pos.y - loc_14.y, v52->pos.z - loc_14.z);
                    DB9B0_color(255, 255, 255, v63);
                    DB9B0_tex(1.0f, v52->t);
                }
            }
            }
        }
    }
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_DB9B0 */

/* fzgx:begin fn_1_DC084 */


#define BGSAN_MIN(a, b) ((a) < (b) ? (a) : (b))

static inline f32 bgsan_distance(BgSanVec3 *p, BgSanVec3 *q) {
    f32 dx = p->x;
    f32 dy;
    f32 dz;
    dx -= q->x;
    dy = p->y;
    dy -= q->y;
    dz = p->z;
    dz -= q->z;
    dx = (f32)(dx * dx);
    dx += dy * dy;
    dx += dz * dz;
    return lbl_8006D0B4(dx);
}

// Smallest distance from pos to any of the fn_1_681C positions.
f32 fn_1_DC084(BgSanVec3 *pos) {
    BgSanVec3 other;
    u32 count;
    u32 i;
    f32 best;

    count = (u32)fn_1_58C4();
    fn_1_681C(0, (u32 *)(BgSanVec3 *)(&other));
    best = bgsan_distance(pos, &other);
    for (i = 1; i < count; i++) {
        fn_1_681C((u8)i, (u32 *)(BgSanVec3 *)(&other));
        // MIN evaluates its operand twice, so the distance is recomputed on the smaller path.
        best = BGSAN_MIN(best, bgsan_distance(pos, &other));
    }
    return best;
}
/* fzgx:end fn_1_DC084 */

/* fzgx:begin fn_1_DC1B8 */
// fn_1_DC1B8: returns a constant.
int fn_1_DC1B8(void) {
    return 0;
}
/* fzgx:end fn_1_DC1B8 */

/* fzgx:begin fn_1_DC1C0 */
typedef struct {
    u8 pad_0[0x14];
    u32 unk_14;
    u8 pad_18[0x1008];
} BgSanEntry;

int fn_1_DC1C0(int arg0, int arg1) {
    Obj_1_data_2A7E0_At3C *obj = lbl_1_data_2A7E0.unk_3C;
    switch (arg0) {
    case 0:
        if ((s32)obj->unk_10 < 20) {
            BgSanEntry *entry = (BgSanEntry *)obj;
            entry += (s32)obj->unk_10;
            entry->unk_14 = arg1;
            obj->unk_10 = (s32)obj->unk_10 + 1;
        }
        break;
    default:
        break;
    }
    return 1;
}
/* fzgx:end fn_1_DC1C0 */

/* fzgx:begin fn_1_DC204 */
// fn_1_DC204: empty in retail (single blr).
void fn_1_DC204(void) {
}
/* fzgx:end fn_1_DC204 */

/* fzgx:begin fn_1_DC208 */
void fn_1_DC208(void) {
    Obj_1_data_2A7E0_At3C *obj = lbl_1_data_2A7E0.unk_3C;

    obj->unk_0 = 0;
    fn_1_9A508();
    fn_1_103D28((u8 *)((u8 *)obj + 0x1588), lbl_1_rodata_66D0[0], (u8)(0x14));
    fn_1_DC3A4( (fn_1_DC3A4_Container *)(Obj_1_data_2A7E0_At3C *)(obj));
}
/* fzgx:end fn_1_DC208 */

/* fzgx:begin fn_1_DC264 */
// fn_1_DC264: empty in retail (single blr).
void fn_1_DC264(void) {
}
/* fzgx:end fn_1_DC264 */

/* fzgx:begin fn_1_DC268 */
// Initializes scene data and updates each active scene entry.
void fn_1_DC268(void) {
    Obj_1_data_2A7E0_At3C *scene_data;
    s32 entry_index;
    s32 entry_count;

    scene_data = lbl_1_data_2A7E0.unk_3C;
    fn_1_9AD54();
    entry_count = (s32)fn_1_9D260();
    fn_1_DCB10();
    fn_1_DC454( (SanContainer *)(Obj_1_data_2A7E0_At3C *)(scene_data), (void *)(s32)(entry_count));

    entry_count = fn_1_58C4();
    for (entry_index = 0; entry_index < entry_count; entry_index++) {
        fn_1_5948(entry_index);
        fn_1_DC648( (void *)(Obj_1_data_2A7E0_At3C *)(scene_data));
        fn_1_627C(entry_index);
    }
}
/* fzgx:end fn_1_DC268 */

/* fzgx:begin fn_1_DC2F8 */
void fn_1_DC2F8(void) {
    Obj_1_data_2A7E0_At3C *obj;

    obj = lbl_1_data_2A7E0.unk_3C;
    fn_1_72648(&lbl_1_data_2A7E0);
    fn_1_DC404( (fn_1_DC404_Container *)(Obj_1_data_2A7E0_At3C *)(obj));
    fn_1_103F10((u8 *)obj + 0x1588);
}
/* fzgx:end fn_1_DC2F8 */

/* fzgx:begin fn_1_DC33C */
// Builds the active background scene and publishes it to the renderer.
void fn_1_DC33C(void) {
    Obj_1_data_2A7E0_At3C *background;
    s32 scene_data;

    background = lbl_1_data_2A7E0.unk_3C;
    scene_data = (s32)fn_1_9D260(&lbl_1_data_2A7E0);
    fn_1_103F58(&background->unk_1588);
    fn_1_DC6FC(background);
    fn_1_DC5E8(background, scene_data);
    fn_1_9AD88();
}
/* fzgx:end fn_1_DC33C */

/* fzgx:begin fn_1_DC3A0 */
// fn_1_DC3A0: empty in retail (single blr).
void fn_1_DC3A0(void) {
}
/* fzgx:end fn_1_DC3A0 */

/* fzgx:begin fn_1_DC3A4 */
// Marks each entry as initialized and processes all entries in the container.
void fn_1_DC3A4(fn_1_DC3A4_Container *container) {
    s32 count;
    fn_1_DC3A4_Entry *entry;

    count = container->count;
    entry = container->entries;
    while (count > 0) {
        entry->initialized = 1;
        fn_1_103090(entry);
        count--;
        entry++;
    }
}
/* fzgx:end fn_1_DC3A4 */

/* fzgx:begin fn_1_DC404 */
// Calls the cleanup routine for each entry in the container.


void fn_1_DC404(fn_1_DC404_Container *container) {
    s32 count;
    fn_1_DC404_Entry *entry;

    count = container->count;
    entry = container->entries;
    while (count > 0) {
        fn_1_1030A4(entry);
        count--;
        entry++;
    }
}
/* fzgx:end fn_1_DC404 */

/* fzgx:begin fn_1_DC454 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"

const f32 lbl_1_rodata_66D0 = 0.5f;

extern u32 lbl_801A66A0;
extern f32 lbl_8006D188(s32);
extern void fn_1_1030D4(void *entry, void *arg);

typedef struct SanEntry {
    u8 unk00[0x08];
    u32 unk08;
    u8 unk0c[0x20];
    f32 value2c;
    f32 value30;
    f32 value34;
    u8 unk38[0x74];
} SanEntry;

typedef struct SanContainer {
    s32 count;
    SanEntry entries[1];
} SanContainer;

void fn_1_DC454(SanContainer *container, void *arg) {
    void *saved_arg;
    s32 count;
    SanEntry *entry;

    saved_arg = arg;
    entry = container->entries;
    count = container->count;
    while (count > 0) {
        if (((1) & ((entry->unk08 >> 28)))) {
            entry->value2c = 0.6499999761581421f;
            entry->value30 = 0.75f;
            entry->value34 = 1.0f;
        } else if ((entry->unk08 >> 29) & 1) {
            entry->value2c = 1.0f;
            entry->value30 = 0.0f;
            entry->value34 = 0.0f;
        } else {
            entry->value2c = (f32)__fabs(lbl_8006D188(
                (s32)(182.04444885253906f * (f32)lbl_801A66A0)));
            entry->value30 = (f32)__fabs(lbl_8006D188(
                (s32)(((((f32)lbl_801A66A0) * (182.04444885253906f)) * (0.5)))));
            entry->value34 = (f32)__fabs(lbl_8006D188(
                (s32)(2.0 * (182.04444885253906f * (f32)lbl_801A66A0))));
        }
        fn_1_1030D4(entry, saved_arg);
        count--;
        entry++;
    }
}
/* fzgx:end fn_1_DC454 */

/* fzgx:begin fn_1_DC5E8 */
typedef struct fn_1_DC5E8_Entry {
    u8 unk_00[0xac];
} fn_1_DC5E8_Entry;

typedef struct fn_1_DC5E8_Container {
    s32 unk_00;
    fn_1_DC5E8_Entry unk_04[1];
} fn_1_DC5E8_Container;

// Apply the supplied argument to each active entry in the container.
void fn_1_DC5E8(Obj_1_data_2A7E0_At3C *container, s32 arg) {
    s32 count;
    fn_1_DC5E8_Entry *entry;
    fn_1_DC5E8_Container *data;

    data = (fn_1_DC5E8_Container *)container;
    entry = data->unk_04;
    count = data->unk_00;
    while (count > 0) {
        fn_1_103264(entry, (void *)arg);
        count--;
        entry++;
    }
}
/* fzgx:end fn_1_DC5E8 */

/* fzgx:begin fn_1_DC648 */
void fn_1_DC648(void *object) {
    u32 index;
    u32 direction;
    u32 offset;
    u8 local;
    s32 value;

    index = (u32)fn_1_5910(object);
    fn_1_681C((u8)index, (u32 *)(u8 *)(&local));
    direction = (s32)fn_1_1FB80( (void *)(u8 *)(&local), 1);
    offset = (index << 1) + 0x2264;
    if ((direction & 1) != 0) {
        value = *(s16 *)((u8 *)object + offset);
        value += 1;
        *(s16 *)((u8 *)object + offset) = (value < 0) ? 0 : ((value > 30) ? 30 : value);
    } else {
        value = *(s16 *)((u8 *)object + offset);
        value -= 1;
        *(s16 *)((u8 *)object + offset) = (value < 0) ? 0 : ((value > 30) ? 30 : value);
    }
}
/* fzgx:end fn_1_DC648 */

/* fzgx:begin fn_1_DC6FC */
typedef struct Handler {
    u8 unk_00[4];
    void (*unk_04)(void);
    void *unk_08;
} Handler;

// Registers the callback and its context with a newly allocated handler.
void fn_1_DC6FC(void *context) {
    void *value;
    Handler *handler;

    value = (void *)fn_1_54448(0);
    handler = fn_1_548AC(12);
    if (handler != 0) {
        handler->unk_04 = fn_1_DC764;
        handler->unk_08 = context;
        fn_1_5489C( (void **)(void *)(value), (void **)(void *)(handler));
    }
}
/* fzgx:end fn_1_DC6FC */

/* fzgx:begin fn_1_DCB10 */
typedef struct fn_1_DCB10_Entry {
    u8 pad_00[0x20];
    u32 flags;
} fn_1_DCB10_Entry;

typedef struct fn_1_DCB10_Container {
    u8 pad_00[0xa4];
    s32 count;
    fn_1_DCB10_Entry *entries;
} fn_1_DCB10_Container;

void fn_1_DCB10(void) {
    fn_1_DCB10_Container **global;
    s32 i;
    fn_1_DCB10_Entry *entry;

    global = (fn_1_DCB10_Container **)&lbl_1_bss_3BE0;
    i = 0;
    entry = (*global)->entries;
    while (i < (*global)->count) {
        if (entry->flags & 2) {
            fn_1_D6C10(entry, *(const f32 *)&lbl_1_rodata_6748);
        }
        i++;
        entry++;
    }
}
/* fzgx:end fn_1_DCB10 */

/* fzgx:begin fn_1_DCB9C */
s32 fn_1_DCB9C(s32 value, u32 *data) {
    Obj_1_data_2A7E0_At3C *obj;

    obj = lbl_1_data_2A7E0.unk_3C;
    switch (value) {
    case 0:
        obj->unk_1584 = *data;
        break;
    case 1:
        obj->unk_225C = *data;
        break;
    case 2:
        obj->unk_2260 = *data;
        break;
    }
    return 1;
}
/* fzgx:end fn_1_DCB9C */
