#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/stcoli.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"
#include "game/main_rel/stcoli_types.h"

extern void fn_1_9E14C();
extern void fn_1_9E170(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern const f32 lbl_1_rodata_6D0;
extern f32 lbl_1_rodata_6F8;
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_z(u32);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void lbl_8006E0B4(f32, f32, f32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006DBE4();
extern void fn_1_18784();
extern void lbl_8006E1B0(void *, void *);
extern u32 lbl_8006DCA4(void);
extern void fn_80072558(void);
extern void fn_8003462C(u32 arg0, u32 arg1, u32 arg2);
extern f32 lbl_8006D0B4(f32);
extern void fn_8006E2B0(void *, void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DD14(void *, void *);
extern void mathutil_mtxA_from_quat(void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DFC4(void *);
extern f64 __fabs(f64);
extern int fn_1_15578(void *, void *, void *, void *, u32, void *, void *, void *, u32, void *);
extern u8 *fn_1_14F04(void);
extern void *fn_1_868C0(s8 index);
extern void fn_1_F7338(int arg0, void *arg1, void *arg2);
extern u32 fn_1_2B684(void *);
extern void fn_1_A2D84(u32 arg0);
extern const f32 lbl_1_rodata_84C;
extern s32 lbl_801A66C8;
extern void fn_8006E250(void *, void *);
extern f32 lbl_8006D668(void *);
extern int fn_1_4C10(void);
extern u32 fn_1_4060(void);
extern void fn_1_EB080(int mode);
extern u8 lbl_1_bss_8E51D;
extern u32 fn_1_F45B4(void);
extern u32 fn_1_F22D4(void);
extern int fn_1_EB248(void);
extern s32 fn_1_154C84(void);
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_4954C(f32 value);
extern void fn_1_49590(f32 value);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_495C8(u8 value);
extern void fn_1_495A0(f32 value);
extern void fn_1_495B0(u32 value);
extern char *fn_1_15BA78(char *name);
extern f32 fn_1_4B068(char *);
extern f32 fn_1_4B090(s32 value);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_4A0D8(const char *);
extern void fn_1_50A90(void *, s32, s32, s32, s32);
extern char *fn_1_14EA74(s16 arg0, char *arg1, s16 arg2);
extern int sprintf(char *s, const char *format, ...);
extern s16 fn_1_12EF24(s16 row, s16 column);
extern u32 lbl_801A66B4;
extern u32 lbl_1_data_2BD54[111][6];
extern u32 fn_1_4AEC0(u32 value);
extern u32 fn_1_F83F0(s16);
extern u32 fn_1_F8D10(void);
extern void *fn_1_7F49C(s16 arg0, s16 arg1, void *arg2);
extern void fn_1_A2DC4(u32 arg0);
extern void fn_1_F2008(s32 arg);
extern void fn_1_F7F48(s16);
extern void fn_1_F8A58(u32 value);
extern void fn_1_F8C00(s32 value);
extern void fn_1_F8D38(u32 value);
extern void fn_1_F9D68(u32 arg);
extern void fn_1_F9DE8(u32 param);
extern f32 lbl_1_rodata_6B0[6];
extern int fn_1_210A8(void *, f32 *, int, int, int);
extern int fn_1_16BA0(void *, void *, void *, int *, int);
extern f32 fn_1_16E68(void *, void *, int);
extern unsigned char lbl_1_rodata_840[];
extern void fn_1_22F90(void *self, int value);
extern void lbl_8006E1F0(void *, f32, f32, f32);
extern void fn_1_8A190(void *arg0, void *arg1);
extern void *memset(void *, int, unsigned int);
extern void fn_1_9D77C(u32, u32);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern u32 lbl_801A6410;
extern u8 *lbl_801A66CC;
extern int fn_1_180F4(int first, int second, int count, int ascending);
extern void fn_1_18214();
extern void fn_1_21950(f32 *scale, f32 arg1, f32 arg2);
extern f32 lbl_1_rodata_6D4;
extern char lbl_1_bss_9C;
extern u32 fn_1_8C66C(u32 index);
extern int fn_1_163BC(void *arg0, void *arg1, int mask, int value);
extern void lbl_8006E1D8(void *arg0, f32 arg1, f32 arg2, f32 arg3);
extern double lbl_1_rodata_910;
extern const f32 lbl_1_rodata_854;
extern s16 fn_1_7B054();
extern void OSReport(const char *format, ...);
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern const f32 lbl_1_rodata_85C;
extern void fn_8006E978(void *, void *, void *);
extern f64 lbl_1_rodata_860[22];
extern f32 lbl_1_rodata_B74[25];
extern f32 lbl_8006D6FC(void *, void *);
extern s16 lbl_1_bss_3C2A[3];
extern u32 fn_1_203E4(void *, u32, void *, f32, f32, f32);
extern void fn_1_3F2A0(void);

/* fzgx:begin fn_1_14CB4 */
void fn_1_14CB4(void) {
    if (lbl_1_bss_3BE0 != 0) {
        if (lbl_1_bss_3BE0->unk_54 != 0) {
            fn_1_9D77C(lbl_1_bss_3BE0->unk_54, lbl_1_bss_3BE0->unk_48);
        }

        fn_1_46B4(lbl_801A6410, lbl_1_bss_3BE4.unk_0, (const char *)(u8 *)(lbl_1_data_51C8), 0x2c9);
        lbl_1_bss_3BE4.unk_0 = 0;
        fn_1_46B4(lbl_801A6410, (u32)lbl_1_bss_3BE0, (const char *)(u8 *)(lbl_1_data_51C8), 0x2cb);
        lbl_1_bss_3BE0 = 0;
    }
}
/* fzgx:end fn_1_14CB4 */

/* fzgx:begin fn_1_14DC4 */
u32 fn_1_14DC4(void) {
    if (lbl_1_bss_3BE0 != 0) {
        return lbl_1_bss_3BE0->unk_14;
    }
    return 0;
}
/* fzgx:end fn_1_14DC4 */

/* fzgx:begin fn_1_14DE8 */
typedef struct {
    s32 unk_0;
    s32 unk_4;
    s8 unk_8;
    s8 unk_9;
} fn_1_14DE8_StcoliEntry;

typedef struct {
    s32 count;
    u8 *base;
    u8 pad_8[4];
} StcoliRecord;


#pragma opt_loop_invariants off
void fn_1_14DE8(u32 index) {
    Obj_1_bss_3BE0_Target **manager;
    f32 *constants;
    fn_1_14DE8_StcoliEntry *entry;
    StcoliRecord *record;
    u8 *object;
    s32 slot;
    f32 zero;
    f32 value;

    constants = lbl_1_rodata_6B0;
    manager = &lbl_1_bss_3BE0;
    if (*manager == 0) {
        return;
    }
    if (index >= 0x24) {
        return;
    }

    entry = ((fn_1_14DE8_StcoliEntry **)(((u8 *)&lbl_1_data_54B4)))[index];
    if (entry == 0) {
        return;
    }

    while (entry->unk_0 >= 0) {
        record = (StcoliRecord *)(*manager)->unk_C + entry->unk_0;
        if (entry->unk_4 >= record->count) {
            return;
        }

        slot = entry->unk_4;
        object = record->base + slot * 0x50;
        if (entry->unk_8) {
            if ((s32)index == 7) {
                zero = constants[0];
                value = constants[3];
                *(f32 *)(object + 0x0C) = zero;
                *(f32 *)(object + 0x10) = zero;
                *(f32 *)(object + 0x14) = value;
                *(f32 *)(object + 0x08) = -*(f32 *)(object + 0x20);
            } else if (!*(s8 *)(object + 0x4C)) {
                *(s8 *)(object + 0x4C) = 1;
            }
        }

        if (entry->unk_9) {
            if ((s32)index == 7) {
                zero = constants[0];
                value = constants[4];
                *(f32 *)(object + 0x28) = zero;
                *(f32 *)(object + 0x2C) = zero;
                *(f32 *)(object + 0x30) = value;
                *(f32 *)(object + 0x24) = *(f32 *)(object + 0x3C);
            } else if (!*(s8 *)(object + 0x4D)) {
                *(s8 *)(object + 0x4D) = 1;
            }
        }

        entry++;
    }
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_14DE8 */

/* fzgx:begin fn_1_14F04 */
u8 *fn_1_14F04(void) {
    return lbl_801A66CC + 0x1b0;
}
/* fzgx:end fn_1_14F04 */

/* fzgx:begin fn_1_14F18 noprologue */
#include "types.h"
#include "psvec.h"

typedef struct {
    f32 x, y, z;
} fn_1_14F18_Vec;

/* Plane d, normal, then `count` vertices followed by `count` edge normals. */
typedef struct {
    f32 d;
    fn_1_14F18_Vec n;
    fn_1_14F18_Vec verts[1];
} fn_1_14F18_Poly;

extern f32 fn_1_1FFA0(void *, void *, void *, void *, void *, void *);
extern u8 *lbl_801A66CC;

static inline s32 FZGX_NONFINITE(f32 f) {
    return (*(u32 *)&f & 0x7F800000) == 0x7F800000;
}

#pragma opt_propagation off
static inline f32 fn_1_14F18_dot(fn_1_14F18_Vec *a, fn_1_14F18_Vec *b) {
    f32 r;
    f32 y;
    f32 z;
    r = a->x * b->x;
    y = a->y;
    z = a->z;
    r = y * b->y + r;
    r = z * b->z + r;
    return r;
}
#pragma opt_common_subs off
#pragma opt_lifetimes off
s32 fn_1_14F18(fn_1_14F18_Vec *pos, void *arg1, fn_1_14F18_Vec *dir, f32 *outT,
               fn_1_14F18_Poly *poly, s32 count, u32 flags, f32 radius) {
    fn_1_14F18_Vec *edges[5];
    fn_1_14F18_Vec hit;
    fn_1_14F18_Vec out0;
    fn_1_14F18_Vec out1;
    fn_1_14F18_Vec **e;
    s32 i;
    fn_1_14F18_Vec *v;
    fn_1_14F18_Vec **initE;
    fn_1_14F18_Vec *n;
    fn_1_14F18_Vec *d;
    f32 tIn;
    f32 tOut;
    f32 denom;
    f32 dist;
    f32 planeDot;
    s32 j;
    fn_1_14F18_Vec *verts;

    denom = poly->n.x * dir->x;
    denom = poly->n.y * dir->y + denom;
    denom = poly->n.z * dir->z + denom;
    if (denom > 0.0f && !(flags & 0x400000)) {
        return 0;
    }
    planeDot = poly->n.x * pos->x;
    planeDot = poly->n.y * pos->y + planeDot;
    planeDot = poly->n.z * pos->z + planeDot;
    dist = planeDot + poly->d;
    tIn = dist / denom;
    if (1.0f < tIn || FZGX_NONFINITE(tIn)) {
        return 0;
    }
    tOut = (dist - radius) / denom;
    if (tOut < 0.0f || FZGX_NONFINITE(tOut)) {
        return 0;
    }
    if (tIn < 0.0f) {
        tIn = 0.0f;
    }
    psvec_scale_add(pos, dir, -tIn, &hit);

    v = poly->verts;
    initE = &edges[1];
    for (j = count; j > 1; j--) {
        *initE++ = v++;
    }

    verts = poly->verts;
    e = edges;
    e[count] = verts;
    n = verts + count;
    v = verts;
    for (i = 0; i < count;) {
        psvec_sub(&hit, v, lbl_801A66CC + 0xD4);
        d = (fn_1_14F18_Vec *)(lbl_801A66CC + 0xD4);
        if (fn_1_14F18_dot(d, n) < 0.0f) {
            if (fn_1_1FFA0(pos, arg1, v, e[1], &out0, &out1) > radius * radius) {
                return 0;
            }
        }
        e++;
        i++;
        v++;
        n++;
    }

    if (tOut > 1.0f) {
        tOut = 1.0f;
    }
    psvec_scale_add(pos, dir, -tOut, pos);
    *outT = 1.0f - tOut;
    return 1;
}
/* fzgx:end fn_1_14F18 */

/* fzgx:begin fn_1_16BA0 noprologue */
#include "types.h"
#include "game/vec3.h"
#include "rel/main_rel/stcoli.h"

typedef struct {
    u8 pad_0[0x8];
    f32 zero;
    u8 pad_C[0x1C];
    f32 wideThreshold;
    f32 threshold;
} fn_1_16BA0_Pool;

typedef struct {
    u8 pad_0[0x8];
    f32 a0;
    f32 ax;
    f32 ay;
    f32 az;
    u8 pad_18[0xC];
    f32 b0;
    f32 bx;
    f32 by;
    f32 bz;
    u8 pad_34[0x18];
    s8 canBack;
    s8 canFwd;
    u8 pad_4E[0x2];
} fn_1_16BA0_Plane;

typedef struct {
    s32 count;
    fn_1_16BA0_Plane *planes;
    u8 pad_8[0x4];
} fn_1_16BA0_Seg;

extern f32 lbl_1_rodata_6C8[2];
extern s16 fn_1_7B054(void);

#pragma opt_propagation off
s32 fn_1_16BA0(Vec3f *pos, f32 *ratio, s32 idx, s32 *sub, s32 strict) {
    fn_1_16BA0_Pool *pool;
    f32 thr;
    f32 neg;
    f32 a;
    f32 b;
    f32 z;
    f32 bz;
    f32 az;
    f32 ay;
    f32 y;
    f32 by;
    f32 ax;
    f32 x;
    f32 bx;
    f32 sb;
    f32 sa;
    s32 result;
    s32 flag;
    s32 i;
    s32 count;
    s32 cur;
    s32 n;
    s32 first;
    fn_1_16BA0_Seg *segs;
    fn_1_16BA0_Plane *p;
    s32 j;
    s32 k;
    s32 back;
    s32 fwd;

    pool = (fn_1_16BA0_Pool *)&lbl_1_rodata_6C8;
    if (fn_1_7B054() == 25) {
        thr = pool->wideThreshold;
    } else {
        thr = pool->threshold;
    }
    *ratio = pool->zero;
    count = lbl_1_bss_3BE0->unk_8;
    segs = (fn_1_16BA0_Seg *)lbl_1_bss_3BE0->unk_C;
    if (idx < 0 || count <= idx) {
        idx = 0;
    }
    result = -1;
    cur = *sub;
    flag = lbl_1_bss_3BE0->unk_7D;
    if (cur == 0) {
        cur = 1;
    }
    n = 10;
    if (count < 10) {
        n = count;
    }
    neg = -thr;
    first = segs[idx].count;
    for (i = 0; i < n; i++) {
        j = (idx + count) % count;
        if (strict != 0 && first != segs[j].count) {
            break;
        }
        if (cur != 0 && segs[j].count <= cur) {
            k = segs[j].count - 1;
        } else {
            k = cur;
        }
        p = &segs[j].planes[k];
        x = pos->x;
        y = pos->y;
        z = pos->z;
        ax = p->ax;
        bx = p->bx;
        sa = x * ax;
        ay = p->ay;
        sb = x * bx;
        by = p->by;
        az = p->az;
        sa += y * ay;
        sb += y * by;
        bz = p->bz;
        sa += z * az;
        sb += z * bz;
        a = p->a0 + sa;
        b = p->b0 + sb;
        if (j == 0) {
            fwd = neg <= b;
            back = z < pool->zero;
            if (flag != 0) {
                back = 1;
            }
        } else if (j == count - 1) {
            fwd = z >= pool->zero;
            back = neg <= a;
            if (flag != 0 && fn_1_7B054() != 41) {
                fwd = 1;
            }
        } else {
            fwd = neg <= b;
            back = neg <= a;
        }
        if (fwd == 0) {
            if (strict != 0 && p->canFwd == 0) {
                break;
            }
            idx++;
        } else if (back == 0) {
            if (strict != 0 && p->canBack == 0) {
                break;
            }
            idx--;
        } else {
            *sub = k;
            result = j;
            *ratio = a / (a + b);
            break;
        }
    }
    return result;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_16BA0 */

/* fzgx:begin fn_1_16E68 noprologue */
#include "types.h"
#include "rel/main_rel/stcoli.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    s = 0.0f;
    s = 1.0f;
    s = -5.0f;
    s = 10.0f;
    s = -1.0f;
    s = 2.0f;
    s = 0.5f;
    s = 2.5f;
    s = 1.7000000476837158f;
    s = 0.0010000000474974513f;
}
#pragma section code_type ".text"

typedef struct {
    f32 x, y, z;
} StcoliVec;

typedef struct {
    u8 pad_0[0x8];
    f32 d1;
    f32 n1x, n1y, n1z;
    u8 pad_18[0xC];
    f32 d2;
    f32 n2x, n2y, n2z;
    u8 pad_34[0x1C];
} StcoliPlanePair;

typedef struct {
    u32 unk_0;
    StcoliPlanePair *planes;
    u32 unk_8;
} StcoliSegment;

extern s16 fn_1_7B054(void);

/* signed distances of the point to the segment's two boundary planes */
#define PLANE1(v, p) ny = (p)->n1y; nz = (p)->n1z; dot = x * (p)->n1x; dot = y * ny + dot; dot = z * nz + dot; v = (p)->d1 + dot
#define PLANE2(v, p) ny = (p)->n2y; nz = (p)->n2z; dot = x * (p)->n2x; dot = y * ny + dot; dot = z * nz + dot; v = (p)->d2 + dot

#pragma opt_propagation off
f32 fn_1_16E68(StcoliVec *pos, s32 idx, s32 sub) {
    f32 thresh;
    s32 count;
    StcoliPlanePair *p;
    StcoliSegment *seg;
    f32 nz20;
    f32 ny20;
    f32 y0;
    f32 x0;
    f32 dot20;
    f32 nz10;
    f32 ny10;
    f32 dot10;
    f32 nz11;
    f32 ny11;
    f32 dot11;
    f32 nz21;
    f32 ny21;
    f32 y1;
    f32 x1;
    f32 dot21;
    f32 z2;
    f32 y2;
    f32 x2;
    f32 dot22;
    f32 negThresh;
    f32 nz12;
    f32 ny12;
    f32 dot12;
    f32 a;
    f32 b;

    if (fn_1_7B054() == 25) {
        thresh = 1.7f;
    } else {
        thresh = 0.001f;
    }
    count = lbl_1_bss_3BE0->unk_8;
    if (idx < 0 || count <= idx) {
        idx = 0;
    }
    seg = (StcoliSegment *)lbl_1_bss_3BE0->unk_C;
    p = seg[idx].planes + sub;

    if (idx == 0) {
        if (!(pos->z < 0.0f)) {
            return 0.0f;
        }
        x0 = pos->x;
        y0 = pos->y;
        ny20 = p->n2y;
        nz20 = p->n2z;
        dot20 = x0 * p->n2x;
        dot20 = y0 * ny20 + dot20;
        dot20 = pos->z * nz20 + dot20;
        b = p->d2 + dot20;
        if (!(-thresh <= b)) {
            return 1.0f;
        }
        ny10 = p->n1y;
        nz10 = p->n1z;
        dot10 = x0 * p->n1x;
        dot10 = y0 * ny10 + dot10;
        dot10 = pos->z * nz10 + dot10;
        a = p->d1 + dot10;
    } else if (idx == count - 1) {
        if (!(pos->z >= 0.0f)) {
            return 1.0f;
        }
        x1 = pos->x;
        y1 = pos->y;
        ny21 = p->n1y;
        nz21 = p->n1z;
        dot21 = x1 * p->n1x;
        dot21 = y1 * ny21 + dot21;
        dot21 = pos->z * nz21 + dot21;
        a = p->d1 + dot21;
        if (!(-thresh <= a)) {
            return 0.0f;
        }
        ny11 = p->n2y;
        nz11 = p->n2z;
        dot11 = x1 * p->n2x;
        dot11 = y1 * ny11 + dot11;
        dot11 = pos->z * nz11 + dot11;
        b = p->d2 + dot11;
    } else {
        x2 = pos->x;
        y2 = pos->y;
        z2 = pos->z;
        negThresh = -thresh;
        dot22 = x2 * p->n2x;
        dot22 = y2 * p->n2y + dot22;
        dot22 = z2 * p->n2z + dot22;
        b = p->d2 + dot22;
        if (!(negThresh <= b)) {
            return 1.0f;
        }
        ny12 = p->n1y;
        nz12 = p->n1z;
        dot12 = x2 * p->n1x;
        dot12 = y2 * ny12 + dot12;
        dot12 = z2 * nz12 + dot12;
        a = p->d1 + dot12;
        if (!(negThresh <= a)) {
            return 0.0f;
        }
    }
    return a / (a + b);
}
#pragma opt_propagation reset
/* fzgx:end fn_1_16E68 */

/* fzgx:begin fn_1_17098 noprologue */
#include "types.h"
#include "game/main_rel/stcoli_types.h"
#include "rel/main_rel/stcoli.h"

typedef struct Sig_fn_1_2A8D0_ColiQuery {
    u8 p[0xc];
    Sig_fn_1_2A694_V pos;
    Sig_fn_1_2A694_V dir;
} Sig_fn_1_2A8D0_ColiQuery;

extern f32 lbl_1_rodata_6D4[5];
extern const f32 lbl_1_rodata_6E8;
extern int fn_1_16BA0(void *, f32 *, void *, void *, u32);
extern f32 fn_1_16E68(void *, void *, u32);
extern s16 fn_1_7B054(void);
extern void *lbl_8006D5A4(void *, u32, void *, f32);
extern void lbl_8006D758(void);

struct Sig_fn_1_18B40_fn_1_18B40_Obj {
    u32 flags;
    u8 pad_4[0x8];
    s32 count;
    struct Sig_fn_1_18B40_fn_1_18B40_Obj *entries;
    u8 pad_14[0x38];
    s32 unk_4C;
};
struct Sig_fn_1_18B40_fn_1_18B40_Vec { u32 x, y, z; };
extern void fn_1_18B40(void *, void *, u32, struct Sig_fn_1_18B40_fn_1_18B40_Obj *, struct Sig_fn_1_18B40_fn_1_18B40_Vec *, int, void *, void *, f32, u32);

typedef struct ColiRange {
    f32 a, b;
    u8 pad8[0x44];
    s8 enabledA, enabledB;
    u8 pad4E[2];
} ColiRange;
typedef struct ColiEntry {
    u32 unk0;
    ColiRange *ranges;
    struct Sig_fn_1_18B40_fn_1_18B40_Obj *obj;
} ColiEntry;
typedef struct ColiResult {
    s32 count;
    u32 flags;
    s32 any;
    u8 padC[0x10];
    u32 values[4];
    f32 times[4];
    u32 masks[4];
    s32 ids[4];
} ColiResult;
typedef struct ColiContext {
    ColiResult *result;
    s32 *other;
} ColiContext;
typedef struct ColiRecord {
    u32 words[3];
    u32 valid;
    f32 distance;
    u8 pad14[0x34];
} ColiRecord;
typedef struct ColiManager {
    u8 pad0[0x1B8];
    s32 count;
    s32 index;
    s32 segment;
    f32 time;
    u32 unk1C8;
    s32 total;
    u8 pad1D0[8];
    s32 enabled;
    u8 pad1DC[0x50];
    ColiRecord primary[4];
    ColiRecord candidates[8];
    s32 candidateIds[8];
    s32 candidateCount;
} ColiManager;
extern ColiManager *lbl_801A66CC;
typedef void (*ColiDispatch)(void *, u32, u32, struct Sig_fn_1_18B40_fn_1_18B40_Obj *, f32, struct Sig_fn_1_18B40_fn_1_18B40_Vec *, ColiContext *, void *, s32);

static inline u32 coli_bit(u32 flags, s32 bit) {
    return __rlwnm(flags, (bit + 1) & 31, 31, 31);
}
static inline void coli_dispatch(void *arg0, u32 arg1, u32 flags, struct Sig_fn_1_18B40_fn_1_18B40_Obj *obj, struct Sig_fn_1_18B40_fn_1_18B40_Vec *vector, ColiContext *ctx, void *arg6, s32 index, f32 t) {
    ((f32 *)vector)[0] = lbl_1_rodata_6D4[0];
    ((f32 *)vector)[1] = lbl_1_rodata_6D4[0];
    ((f32 *)vector)[2] = lbl_1_rodata_6D4[0];
    ((ColiDispatch *)lbl_1_data_5548)[__cntlzw(obj->flags & 0x3FE0000)](arg0, arg1, flags, obj, t, vector, ctx, arg6, index);
}
static inline s32 coli_selective(u32 flags) {
    s32 enabled = 0;
    if (flags & 0x1800000) {
        if (flags & 0xF8000000) enabled = 1;
    }
    return enabled;
}
static inline void coli_skip(ColiContext *ctx) {
    f32 time = lbl_1_rodata_6D4[0];
    ctx->result->values[ctx->result->count] = 0;
    ctx->result->times[ctx->result->count] = time;
    ctx->result->masks[ctx->result->count] = 0;
    ctx->result->ids[ctx->result->count] = -1;
    if (ctx->result->count < 3) ctx->result->count++;
}

u32 fn_1_17098(void *arg0, u32 arg1, u32 v1, u32 arg3, u32 arg4, ColiContext *ctx, void *arg6) {
    s32 v0;
    s32 i;
    s32 last;
    s32 first;
    s32 missed = 0;
    s32 index;
    void *point;
    struct Sig_fn_1_18B40_fn_1_18B40_Obj *obj;
    s32 *list = (s32 *)arg3;
    u32 maskA, maskB, maskC;
    f32 time;
    f32 t;
    s32 item;
    f32 tmpTime;
    s32 tmpItem;
    f32 vector[3];
    struct Sig_fn_1_18B40_fn_1_18B40_Vec mid;
    s32 currentItem;
    ColiEntry *entry;
    ColiRange *range;
    ColiRecord *best;
    ColiRecord *rec;
    s32 result;
    if (ctx != 0) {
        ctx->result->count = 0;
        ctx->result->flags = 0;
        ctx->result->any = 0;
    }
    if (arg6 != 0) *(u32 *)arg6 = 0;
    v0 = coli_selective(v1);
    if (v0 != 0) {
        u32 bit = __rlwnm(v1, 1, 31, 31) != 0;
        v1 |= 0x80000000U >> bit;
    }
    if ((s32)arg4 > 1) {
        last = (s32)arg4 - 1;
        first = 1;
        lbl_801A66CC->count = last;
    } else {
        first = 0;
        last = 0;
        lbl_801A66CC->count = 1;
    }
    for (i = first; i <= last; i++) {
        item = i;
        index = list[i];
        if (v0 && !coli_bit(v1, i)) index = -1;
        if (index < 0) {
            if (ctx) coli_skip(ctx);
            missed++;
            continue;
        }
        if (v1 & 0x80000) {
            lbl_8006D5A4(arg0, arg1, &mid, lbl_1_rodata_6E8);
            point = &mid;
        } else if (v1 & 0x40000) {
            point = (void *)arg1;
        } else {
            point = arg0;
        }
        if (v1 & 0x20000) {
            tmpItem = item;
            result = fn_1_16BA0(point, &tmpTime, (void *)index, &tmpItem, 1);
            if (result < 0) {
                time = fn_1_16E68(point, (void *)index, item);
            } else {
                index = result;
                time = tmpTime;
                item = tmpItem;
            }
        } else {
            index = fn_1_16BA0(point, &time, (void *)index, &item, 0);
        }
        if (index < 0) {
            if (ctx) coli_skip(ctx);
            missed++;
            continue;
        }
        currentItem = item;
        entry = &((ColiEntry *)lbl_1_bss_3BE0->unk_C)[index];
        range = entry->ranges;
        obj = entry->obj;
        t = range->a + (f32)(time * (range->b - range->a));
        if (currentItem != 0 && obj->unk_4C != 0 && obj->unk_4C != currentItem) continue;
        if (obj->flags & 2) continue;
        lbl_801A66CC->index = currentItem;
        lbl_801A66CC->segment = index;
        lbl_801A66CC->time = time;
        result = 0;
        if (range[item].enabledA && range[item].enabledB) result = 1;
        lbl_801A66CC->enabled = result;
        if (ctx && lbl_801A66CC->count == *ctx->other) {
            if (fn_1_7B054() == 0x18) {
                if ((index >= 2 && index <= 0x1c) ||
                    (index >= 0x1f && index <= 0x33) ||
                    (index >= 0x3a && index <= 0xa3) ||
                    (index >= 0xa7 && index <= 0xb7)) {
                    lbl_801A66CC->enabled = 0;
                }
            } else if (fn_1_7B054() != 8) {
                lbl_801A66CC->enabled = 0;
            }
        }
        lbl_8006D758();
        {
            struct { struct Sig_fn_1_18B40_fn_1_18B40_Vec *value; } output;
            output.value = (struct Sig_fn_1_18B40_fn_1_18B40_Vec *)vector;
            coli_dispatch(arg0, arg1, v1, obj, output.value, ctx, arg6, index, t);
        }
        fn_1_18B40(arg0, (void *)arg1, v1, obj, (struct Sig_fn_1_18B40_fn_1_18B40_Vec *)vector, item, ctx, arg6, t, index);
        lbl_801A66CC->total++;
    }
    lbl_801A66CC->total += missed;
    if (ctx) {
        if (ctx->result->any) {
            for (i = 0; i < ctx->result->count; i++) {
                if (ctx->result->masks[i] & 0x2200000) ctx->result->masks[i] |= 0x20000000;
            }
        }
        for (i = 0; i < ctx->result->count; i++) {
            if (ctx->result->masks[i] & 0xF0000000) ctx->result->flags |= ctx->result->masks[i];
        }
        if (v0 && (ctx->result->flags & 0xF0000000) != 0xF0000000) {
            return fn_1_17098(arg0, arg1, v1 & 0x7FFFFFF, arg3, arg4, ctx, arg6);
        }
    }
    best = 0;
    rec = lbl_801A66CC->candidates;
    for (i = 0; i < lbl_801A66CC->candidateCount; i++, rec++) {
        if (rec->valid && (!best || rec->distance < best->distance)) best = rec;
    }
    if (best) {
        lbl_801A66CC->primary[1] = *best;
        if (ctx) {
            rec = lbl_801A66CC->candidates;
            for (i = 0; i < lbl_801A66CC->candidateCount; i++, rec++) {
                if (rec->valid && rec != best) {
                    ctx->result->masks[lbl_801A66CC->candidateIds[i]] &= 0xFFFFFFF;
                }
            }
        }
    }
    result = 0;
    if ((v1 & 5) == 5) {
        if (lbl_801A66CC->primary[0].valid || lbl_801A66CC->primary[1].valid) {
            rec = &lbl_801A66CC->primary[0];
            i = 0;
            if (!rec->valid) {
                i = 1;
                rec++;
                if (!rec->valid) {
                    i = 2;
                    rec++;
                }
            }
            best = rec;
            for (; i < 2; i++, rec++) {
                if (rec->valid && rec->distance < best->distance) best = rec;
            }
            lbl_801A66CC->primary[2] = *best;
            result = 1;
        }
    } else if ((v1 & 1) && lbl_801A66CC->primary[0].valid) {
        lbl_801A66CC->primary[2] = lbl_801A66CC->primary[0];
        result = 1;
    } else if ((v1 & 4) && lbl_801A66CC->primary[1].valid) {
        lbl_801A66CC->primary[2] = lbl_801A66CC->primary[1];
        result = 1;
    }
    return result;
}
/* fzgx:end fn_1_17098 */

/* fzgx:begin fn_1_17A9C noprologue */
#include "dolphin/types.h"

typedef struct Position17A9C {
    f32 x, y, z;
} Position17A9C;

typedef struct Entry17A9C {
    Position17A9C pos;
    u8 pad[0x80 - 0xC];
} Entry17A9C;

typedef struct State17A9C {
    u8 pad0[0x1CC];
    s32 count;
    u8 pad1[0x5F4 - 0x1D0];
    Entry17A9C entries[1];
} State17A9C;

extern State17A9C *lbl_801A66CC;

/* Volatile input preserves the retail coordinate reloads for each candidate. */
static inline f32 distance17A9C(volatile Position17A9C *a, Position17A9C *b) {
    f32 dx, dy, dz;
    dx = a->x;
    dx -= b->x;
    dy = a->y;
    dy -= b->y;
    dz = a->z;
    dz -= b->z;
    dx *= dx;
    dx += dy * dy;
    dx += dz * dz;
    return dx;
}

static inline s32 count17A9C(State17A9C *state) {
    return state->count;
}

s32 fn_1_17A9C(Position17A9C *arg0) {
    State17A9C *state = lbl_801A66CC;
    s32 count = count17A9C(state);
    u8 *cursor;
    s32 result;
    s32 i;
    f32 dx, dy, dz;
    f32 dist, best;

    if (count <= 1) {
        result = 0;
    } else {
        dist = distance17A9C(arg0, &state->entries[1].pos);
        best = dist;
        cursor = (u8 *)&state->entries[2].pos - 0x444;
        result = 1;
        for (i = 2; i < count; i++) {
            dist = distance17A9C(arg0, (Position17A9C *)(cursor + 0x444));
            if (best > dist) {
                result = i;
                best = dist;
            }
            cursor += 0x80;
        }
    }
    return result;
}
/* fzgx:end fn_1_17A9C */

/* fzgx:begin fn_1_17B5C */
typedef struct {
    u8 pad_0[0x40];
    f32 unk_40;
    f32 unk_44;
    u8 pad_48[0x5];
    s8 unk_4D;
} Fn17B5C_Record;

typedef struct {
    u32 unk_0;
    Fn17B5C_Record *unk_4;
    u32 unk_8;
} Fn17B5C_Slot;

int fn_1_17B5C(int a, int b, int count, f32 threshold) {
    int end;
    int span;
    int j;
    int found;
    int result;
    Fn17B5C_Slot *left;
    Fn17B5C_Slot *right;
    f32 delta;

    if (a == b) {
        return 1;
    }
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    span = b - a;
    {
        int diff = count - span;
        if (diff < span) {
            int temp = a;
            a = b;
            b = temp;
            span = diff;
        }
    }

    left = &((Fn17B5C_Slot *)lbl_1_bss_3BE0->unk_C)[a];
    right = &((Fn17B5C_Slot *)lbl_1_bss_3BE0->unk_C)[b];
    if (threshold > (*((f32 *)&lbl_1_rodata_6D0))) {
        delta = right->unk_4->unk_40 - left->unk_4->unk_44;
        if (delta < (*((f32 *)&lbl_1_rodata_6D0))) {
            delta += *(f32 *)lbl_1_bss_3BE0->unk_90;
        }
        if (delta > threshold) {
            return 0;
        }
    }

    b = a + 1;
    end = count - 1;
    found = 0;
    for (j = 0; j < span; j++) {
        if (b > end) {
            b = 0;
        }
        if (!((Fn17B5C_Slot *)lbl_1_bss_3BE0->unk_C)[a].unk_4->unk_4D) {
            break;
        }
        a = b;
        found++;
        b++;
    }

    result = 0;
    if (span == 0 || found >= span) {
        result = 1;
    }
    return result;
}
/* fzgx:end fn_1_17B5C */

/* fzgx:begin fn_1_17C6C */
typedef struct Entry {
    char pad[0x4d];
    s8 active;
} Entry;

typedef struct Slot {
    int pad;
    Entry *entry;
    int tail;
} Slot;

typedef struct Root {
    char pad[0xc];
    Slot *slots;
} Root;

int fn_1_17C6C(int current, int next, int limit) {
    int end;
    int count;
    int span;
    int result;

    if (current == next) {
        return 1;
    }

    if (current > next) {
        int temp = current;
        current = next;
        next = temp;
    }

    span = next - current;
    {
        int diff = limit - span;
        if (diff < span) {
            current = next;
            span = diff;
        }
    }

    next = current + 1;
    count = 0;
    end = limit - 1;

    while (count < span) {
        if (next > end) {
            next = 0;
        }

        if (!(*(Root **)&(*(u32 *)&lbl_1_bss_3BE0))->slots[current].entry->active) {
            break;
        }
        if (current == 0x8b && fn_1_7B054(current) == 3) {
            break;
        }
        current = next;
        count++;
        next++;
    }

    result = 0;
    if (span == 0 || count >= span) {
        result = 1;
    }
    return result;
}
/* fzgx:end fn_1_17C6C */

/* fzgx:begin fn_1_17D5C */
void fn_1_17D5C(Node *node, u32 *acc) {
    Node *root;
    s32 i1;
    Node *p1;
    Node *p2;
    s32 i2;
    Node *p3;
    s32 i3;
    Node *p4;
    s32 i4;
    Node *p5;
    s32 i5;
    Node *p6;
    s32 i6;
    Node *p7;
    s32 i7;
    Node *p8;
    s32 i8;
    Node *p9;
    s32 i9;

    root = node;
    *acc |= root->unk_0;
    if (root->count > 0) {
        i1 = 0;
        p1 = root->children;
        while (i1 < root->count) {
            *acc |= p1->unk_0;
            if (p1->count > 0) {
                p2 = p1->children;
                i2 = 0;
                while (i2 < p1->count) {
                    *acc |= p2->unk_0;
                    if (p2->count > 0) {
                        p3 = p2->children;
                        i3 = 0;
                        while (i3 < p2->count) {
                            *acc |= p3->unk_0;
                            if (p3->count > 0) {
                                p4 = p3->children;
                                i4 = 0;
                                while (i4 < p3->count) {
                                    *acc |= p4->unk_0;
                                    if (p4->count > 0) {
                                        p5 = p4->children;
                                        i5 = 0;
                                        while (i5 < p4->count) {
                                            *acc |= p5->unk_0;
                                            if (p5->count > 0) {
                                                p6 = p5->children;
                                                i6 = 0;
                                                while (i6 < p5->count) {
                                                    *acc |= p6->unk_0;
                                                    if (p6->count > 0) {
                                                        p7 = p6->children;
                                                        i7 = 0;
                                                        while (i7 < p6->count) {
                                                            *acc |= p7->unk_0;
                                                            if (p7->count > 0) {
                                                                p8 = p7->children;
                                                                i8 = 0;
                                                                while (i8 < p7->count) {
                                                                    *acc |= p8->unk_0;
                                                                    if (p8->count > 0) {
                                                                        p9 = p8->children;
                                                                        i9 = 0;
                                                                        while (i9 < p8->count) {
                                                                            fn_1_17D5C(p9, acc);
                                                                            i9++;
                                                                            p9++;
                                                                        }
                                                                    }
                                                                    i8++;
                                                                    p8++;
                                                                }
                                                            }
                                                            i7++;
                                                            p7++;
                                                        }
                                                    }
                                                    i6++;
                                                    p6++;
                                                }
                                            }
                                            i5++;
                                            p5++;
                                        }
                                    }
                                    i4++;
                                    p4++;
                                }
                            }
                            i3++;
                            p3++;
                        }
                    }
                    i2++;
                    p2++;
                }
            }
            i1++;
            p1++;
        }
    }
}
/* fzgx:end fn_1_17D5C */

/* fzgx:begin fn_1_17FCC */
typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;
} fn_1_17FCC_StcoliEntry;


int fn_1_17FCC(int a, int b, int c) {
    int count;
    int i;
    int end;
    fn_1_17FCC_StcoliEntry *last;
    fn_1_17FCC_StcoliEntry *entry;
    u32 fa;
    u32 fb;
    int result;

    if (a == b) {
        return 1;
    }
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    count = b - a;
    i = c - count;
    if (i < count) {
        a = b;
        count = i;
    }
    b = a + 1;
    end = c;
    end = end - 1;
    last = (fn_1_17FCC_StcoliEntry *)lbl_1_bss_3BE0->unk_C + a;
    i = 0;
    while (i < count) {
        if (b > end) {
            b = 0;
        }
        entry = (fn_1_17FCC_StcoliEntry *)lbl_1_bss_3BE0->unk_C + b;
        fb = 0;
        fa = 0;
        fn_1_17D5C( (Node *)(u32)(last->unk_8), &fa);
        fn_1_17D5C( (Node *)(u32)(entry->unk_8), &fb);
        if ((fa & 0x01000000) != 0 && (fb & 0x00800000) != 0) {
            break;
        }
        if ((fb & 0x01000000) != 0 && (fa & 0x00800000) != 0) {
            break;
        }
        last = entry;
        i++;
        b++;
    }
    result = 0;
    if (count == 0 || i >= count) {
        result = 1;
    }
    return result;
}
/* fzgx:end fn_1_17FCC */

/* fzgx:begin fn_1_180F4 */
typedef struct {
    int unk_0;
    int unk_4;
    int unk_8;
} Entry_180F4;

int fn_1_180F4(int first, int second, int count, int ascending) {
    int wins;
    int current;
    int limit;
    int j;
    int tmp;
    Entry_180F4 *current_entry;
    Entry_180F4 *candidate;
    int result;

    if (first == second) {
        return 1;
    }

    if (first > second) {
        tmp = first;
        first = second;
        second = tmp;
    }

    current = second - first;
    limit = count - current;
    if (limit < current) {
        first = second;
        current = limit;
    }

    current_entry = &((Entry_180F4 *)lbl_1_bss_3BE0->unk_C)[first];
    wins = 0;
    second = first + 1;
    limit = count;
    limit -= 1;
    j = current;

    while (j > 0) {
        if (second > limit) {
            second = 0;
        }

        candidate = &((Entry_180F4 *)lbl_1_bss_3BE0->unk_C)[second];
        if (ascending) {
            if (current_entry->unk_0 < candidate->unk_0) {
                break;
            }
        } else if (current_entry->unk_0 > candidate->unk_0) {
            break;
        }

        current_entry = candidate;
        wins++;
        second++;
        j--;
    }

    result = 0;
    if (current == 0 || wins >= current) {
        result = 1;
    }
    return result;
}
/* fzgx:end fn_1_180F4 */

/* fzgx:begin fn_1_181CC */
// fn_1_181CC: main_rel .text:0x000181CC size 0x24
// Wrapper function that passes first three arguments through and sets fourth to 1

void fn_1_181CC(int a, int b, int c) {
    fn_1_180F4(a, b, c, 1);
}
/* fzgx:end fn_1_181CC */

/* fzgx:begin fn_1_181F0 */
void fn_1_181F0(int a, int b, int c) {
    fn_1_180F4(a, b, c, 0);
}
/* fzgx:end fn_1_181F0 */

/* fzgx:begin fn_1_18214 noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"
#include "game/main_rel/stcoli_types.h"

typedef struct {
    u32 f00, f04, f08, f0c, f10, f14, f18, f1c, f20, f24;
    u32 f28, f2c, f30, f34, f38, f3c, f40, f44;
} fn_1_18214_Cfg;

typedef struct {
    u8 pad_0[0x4];
    fn_1_18214_Cfg *cfg;
    u8 pad_8[0xc];
    f32 fx;
    f32 fy;
    f32 fz;
    f32 rxv;
    f32 ryv;
    f32 rzv;
    f32 sxv;
    f32 syv;
    f32 szv;
} fn_1_18214_Entity;

typedef struct {
    u32 count;
    u32 entries[1];
} fn_1_18214_Stack;

extern f32 fn_1_9E14C(u32, u32, f32);
extern f32 fn_1_9E170(u32, u32, void *, f32);
extern const f32 lbl_1_rodata_6D0;
extern f32 lbl_1_rodata_6F8;
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_z(u32);
extern void fn_80008BEC(void *, int, void *);
extern void lbl_8006E0B4(f32, f32, f32);

void fn_1_18214(fn_1_18214_Entity *arg0, f32 *arg1, fn_1_18214_Stack *arg2, f32 t) {
    fn_1_18214_Cfg *v0 = arg0->cfg;
    u8 *slot;
    s32 ang;
    f32 a;
    f32 b;
    f32 c;
    f32 r;

    if (arg2 != 0) {
        slot = (u8 *)arg2 + arg2->count * 36 + 44;
        if (arg2->entries[arg2->count] != (u32)arg0) {
            fn_80008BEC((u8 *)arg2 + arg2->count * 36 + 44, 0, (void *)36);
        }
        if (v0->f3c != 0) {
            a = fn_1_9E170(v0->f18, v0->f3c, slot, t);
        } else {
            a = arg0->sxv;
        }
        if (v0->f40 != 0) {
            b = fn_1_9E170(v0->f1c, v0->f40, slot + 4, t);
        } else {
            b = arg0->syv;
        }
        if (v0->f44 != 0) {
            c = fn_1_9E170(v0->f20, v0->f44, slot + 8, t);
        } else {
            c = arg0->szv;
        }
        if (lbl_1_rodata_6D0 != a || lbl_1_rodata_6D0 != b || lbl_1_rodata_6D0 != c) {
            lbl_8006E0B4(arg1[0] * a, arg1[1] * b, arg1[2] * c);
        }
        if (v0->f30 != 0) {
            a = fn_1_9E170(v0->f0c, v0->f30, slot + 12, t);
        } else {
            a = arg0->rxv;
        }
        if (v0->f34 != 0) {
            b = fn_1_9E170(v0->f10, v0->f34, slot + 16, t);
        } else {
            b = arg0->ryv;
        }
        if (v0->f38 != 0) {
            c = fn_1_9E170(v0->f14, v0->f38, slot + 20, t);
        } else {
            c = arg0->rzv;
        }
        if (lbl_1_rodata_6D0 != c) {
            if (((s32)(lbl_1_rodata_6F8 * c) & 0xFFFF) != 0) {
                mathutil_mtxA_rotate_z((s16)(u16)(s32)(lbl_1_rodata_6F8 * c));
            }
        }
        if (lbl_1_rodata_6D0 != b) {
            if (((s32)(lbl_1_rodata_6F8 * b) & 0xFFFF) != 0) {
                mathutil_mtxA_rotate_y((s16)(u16)(s32)(lbl_1_rodata_6F8 * b));
            }
        }
        if (lbl_1_rodata_6D0 != a) {
            if (((s32)(lbl_1_rodata_6F8 * a) & 0xFFFF) != 0) {
                mathutil_mtxA_rotate_x((s16)(u16)(s32)(lbl_1_rodata_6F8 * a));
            }
        }
        if (v0->f24 != 0) {
            r = fn_1_9E170(v0->f00, v0->f24, slot + 24, t);
        } else {
            r = arg0->fx;
        }
        arg1[0] = arg1[0] * r;
        if (v0->f28 != 0) {
            r = fn_1_9E170(v0->f04, v0->f28, slot + 28, t);
        } else {
            r = arg0->fy;
        }
        arg1[1] = arg1[1] * r;
        if (v0->f2c != 0) {
            r = fn_1_9E170(v0->f08, v0->f2c, slot + 32, t);
        } else {
            r = arg0->fz;
        }
        arg1[2] = arg1[2] * r;
    } else {
        if (v0->f3c != 0) {
            a = fn_1_9E14C(v0->f18, v0->f3c, t);
        } else {
            a = arg0->sxv;
        }
        if (v0->f40 != 0) {
            b = fn_1_9E14C(v0->f1c, v0->f40, t);
        } else {
            b = arg0->syv;
        }
        if (v0->f44 != 0) {
            c = fn_1_9E14C(v0->f20, v0->f44, t);
        } else {
            c = arg0->szv;
        }
        if (lbl_1_rodata_6D0 != a || lbl_1_rodata_6D0 != b || lbl_1_rodata_6D0 != c) {
            lbl_8006E0B4(arg1[0] * a, arg1[1] * b, arg1[2] * c);
        }
        if (v0->f30 != 0) {
            b = fn_1_9E14C(v0->f0c, v0->f30, t);
        } else {
            b = arg0->rxv;
        }
        if (v0->f34 != 0) {
            a = fn_1_9E14C(v0->f10, v0->f34, t);
        } else {
            a = arg0->ryv;
        }
        if (v0->f38 != 0) {
            c = fn_1_9E14C(v0->f14, v0->f38, t);
        } else {
            c = arg0->rzv;
        }
        if (lbl_1_rodata_6D0 != c) {
            if (((s32)(lbl_1_rodata_6F8 * c) & 0xFFFF) != 0) {
                mathutil_mtxA_rotate_z((s16)(u16)(s32)(lbl_1_rodata_6F8 * c));
            }
        }
        if (lbl_1_rodata_6D0 != a) {
            if (((s32)(lbl_1_rodata_6F8 * a) & 0xFFFF) != 0) {
                mathutil_mtxA_rotate_y((s16)(u16)(s32)(lbl_1_rodata_6F8 * a));
            }
        }
        if (lbl_1_rodata_6D0 != b) {
            if (((s32)(lbl_1_rodata_6F8 * b) & 0xFFFF) != 0) {
                mathutil_mtxA_rotate_x((s16)(u16)(s32)(lbl_1_rodata_6F8 * b));
            }
        }
        if (v0->f24 != 0) {
            r = fn_1_9E14C(v0->f00, v0->f24, t);
        } else {
            r = arg0->fx;
        }
        arg1[0] = arg1[0] * r;
        if (v0->f28 != 0) {
            r = fn_1_9E14C(v0->f04, v0->f28, t);
        } else {
            r = arg0->fy;
        }
        arg1[1] = arg1[1] * r;
        if (v0->f2c != 0) {
            r = fn_1_9E14C(v0->f08, v0->f2c, t);
        } else {
            r = arg0->fz;
        }
        arg1[2] = arg1[2] * r;
    }
    if (arg2 != 0) {
        arg2->entries[arg2->count] = (u32)arg0;
        if ((s32)arg2->count < 9) {
            arg2->count = arg2->count + 1;
        }
    }
}
/* fzgx:end fn_1_18214 */

/* fzgx:begin fn_1_18784 noprologue */
#include "types.h"
#include "psvec.h"

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    u32 f44;
} Cfg;

typedef struct {
    f32 f00;
    f32 f04;
    f32 f08;
    f32 f0c;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1c;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2c;
} Mat;

typedef struct {
    u8 pad_0[0x1bc];
    s32 f1bc;
    u8 pad_1c0[8];
    u32 f1c8;
    s32 f1cc;
    u8 pad_1d0[0xc];
    f32 f1dc;
    f32 f1e0;
} Mgr;

typedef struct {
    u32 f00;
    Cfg *cfg;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    f32 f18;
} Src;

typedef struct {
    u32 f00;
    Cfg *cfg;
    u32 f08;
    s32 f0c;
    Src *f10;
    u32 f14;
    f32 f18;
    f32 f1c;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2c;
} Motion;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    u8 pad_0[0x30];
    Vec3 pos;
    f32 ax;
    f32 ay;
    Vec3 v0;
    Vec3 e;
    Vec3 m;
    f32 d0;
    f32 d1;
    Vec3 o;
    u32 f7c;
    u8 pad_80[0x7c];
    u32 fffc;
} Rec;

struct Pool {
    u8 pad_0[0xc];
    f32 one;
    u8 pad_10[0xc];
    f32 two;
    u8 pad_20[0x14];
    f32 half;
};

extern struct Pool lbl_1_rodata_6C8;
extern u32 lbl_801A66CC;
extern u32 lbl_801A6D00;
extern f64 __fabs(f64);
extern f32 fn_1_9E14C(u32, u32, f32);
extern Rec *lbl_8006DB74(Rec *);
extern void fn_1_18214(Motion *, Vec3 *, void *, f32);

#pragma opt_propagation off
void fn_1_18784(u32 arg0, Motion *a, Vec3 *b, void *c, f32 d)
{
    struct Pool *pl;
    Rec *p;
    Rec *q;
    u32 mask;
    Cfg *cf;
    f64 tmp___fabs;
    f32 scx;
    f32 s2;
    f32 ax;
    f32 ay;
    f32 sm;
    f32 px;

    pl = &lbl_1_rodata_6C8;
    if ((arg0 & 0x800000) != 0) {
        q = (Rec *)((u8 *)((Mgr *)lbl_801A66CC) + ((((Mgr *)lbl_801A66CC)->f1cc) << 7) + 0x5B0);
    } else {
        q = (Rec *)0;
    }
    p = q;
    mask = a->f00 & 0x07E00C01;
    ((Mgr *)lbl_801A66CC)->f1c8 |= mask;
    if ((a->f00 & 0x4000000) != 0) {
        Mgr *m = (Mgr *)lbl_801A66CC;
        if (m->f1bc == 1 || (m->f1bc > 1 && m->f1cc == 0)) {
            if (m->f1cc < 3) {
                m->f1cc = m->f1cc + 1;
                if (p != 0) {
                    p->fffc = 0;
                    p = (Rec *)((u8 *)p + 0x80);
                }
            }
        }
    }
    if ((a->f00 & 0x600000) == 0) {
        fn_1_18214(a, b, c, d);
        if (p != 0) {
            f32 *mtx;
            lbl_8006DB74(p);
            /* Locked cache: the current matrix at 0xE0000000 is not a data symbol. */
            mtx = (f32 *)(0xE0000000 + 0);
            p->pos = *b;
            psvec_set(&p->v0.x, mtx[11], mtx[7], mtx[3]);
            p->e.x = -((Mat *)lbl_801A6D00)->f08;
            p->e.y = -((Mat *)lbl_801A6D00)->f18;
            p->e.z = -((Mat *)lbl_801A6D00)->f28;
            p->m.x = ((Mat *)lbl_801A6D00)->f04;
            p->m.y = ((Mat *)lbl_801A6D00)->f14;
            p->m.z = ((Mat *)lbl_801A6D00)->f24;
        }
    }
    if ((a->f00 & 0x400000) != 0) {
        cf = a->cfg;
        scx = (cf->f3c != 0) ? fn_1_9E14C(cf->f18, cf->f3c, d) : a->f2c;
        scx = pl->two * scx;
        s2 = (cf->f28 != 0) ? fn_1_9E14C(cf->f04, cf->f28, d) : a->f18;
{
    f32 bx;
        bx = (*(f32 volatile *)&(b->x)) /* Retail reloads this field. */;
        sm = scx + s2;
        scx = scx * bx;
        tmp___fabs = __fabs(scx);
        ax = (f32)tmp___fabs;
        tmp___fabs = __fabs(s2 * b->y);
        ay = (f32)tmp___fabs;
        px = bx * sm;
}
        ((Mgr *)lbl_801A66CC)->f1dc = ax;
        ((Mgr *)lbl_801A66CC)->f1e0 = ay;
        if (p != 0) {
            p->ax = ax;
            p->ay = ay;
        }
    }
    if (p != 0) {
        p->f7c |= mask;
        if ((a->f00 & 0x800000) != 0 && a->f0c == 1) {
            Cfg *c2 = (*(Src *volatile *)&(a->f10))->cfg; /* Retail reloads this field. */
            p->d0 = (*(f32 volatile *)&(b->x)) /* Retail reloads this field. */;
            p->d1 = (c2->f28 != 0) ? fn_1_9E14C(c2->f04, c2->f28, d) : (*(Src *volatile *)&(a->f10))->f18 /* Retail reloads this field. */;
        } else if ((a->f00 & 0x200000) == 0) {
            p->d0 = (a->f00 & 0x400000) ? px : (*(f32 volatile *)&(b->x)) /* Retail reloads this field. */;
            p->d1 = pl->one;
        }
        if ((a->f00 & 0x400000) != 0) {
            psvec_scale_add(&p->v0.x, &p->m.x, pl->half * p->ay, &p->o.x);
        } else if ((a->f00 & 0x1800000) != 0) {
            psvec_scale_add(&p->v0.x, &p->m.x, pl->half * b->y, &p->o.x);
        } else {
            p->o = p->v0;
        }
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_18784 */

/* fzgx:begin fn_1_18B40 */
typedef u32 (*fn_1_18B40_Fn)(u32, u32, u32, u32, u32, u32, u32, u32, f32);

struct fn_1_18B40_Obj {
    u32 flags;
    u8 pad_4[0x8];
    s32 count;
    struct fn_1_18B40_Obj *entries;
    u8 pad_14[0x38];
    s32 unk_4C;
};

struct fn_1_18B40_Vec {
    u32 x;
    u32 y;
    u32 z;
};


#pragma opt_loop_invariants off
#pragma opt_common_subs off
void fn_1_18B40(void * arg0, void * arg1, u32 arg2, struct fn_1_18B40_Obj *arg3, struct fn_1_18B40_Vec *arg4, int arg5, void * arg6, void * arg7, f32 arg8, u32 arg9) {
    struct fn_1_18B40_Obj * fzgx_live_;
    struct fn_1_18B40_Obj * fzgx_live;
    struct fn_1_18B40_Vec saved;
    int i;

    if (arg3->count > 0) {
        lbl_8006DAEC();
        fzgx_live_ = arg3->entries;
{
    struct fn_1_18B40_Obj *entry;
        entry = (fzgx_live_);
        i = 0;
        while (i < arg3->count) {
            if (arg5 == 0 || entry->unk_4C == 0 || entry->unk_4C == arg5) {
                if ((entry->flags & 0x2) == 0) {
                    saved = *arg4;
                    lbl_8006DBE4();
                    ((fn_1_18B40_Fn)*(fn_1_18B40_Fn *)(lbl_1_data_5548 + (__cntlzw(entry->flags & 0x3FE0000) << 2)))( (u32)arg0,(u32)arg1, arg2, (u32)entry, (u32)arg4, (u32)arg6, (u32)arg7, arg9, arg8);
                    fn_1_18B40(arg0, arg1, arg2, entry, arg4, arg5, arg6, arg7, arg8, arg9);
                    *arg4 = saved;
                }
            }
            i++;
            entry = (struct fn_1_18B40_Obj *)((u8 *)entry + 0x50);
}
        }
        lbl_8006DB30();
    }
}
#pragma opt_common_subs reset

#pragma opt_loop_invariants reset
/* fzgx:end fn_1_18B40 */

/* fzgx:begin fn_1_18F28 noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"

typedef struct {
    unsigned char pad0[0x0c];
    int count;
    void *entries;
} Fn118F28Object;

typedef struct {
    unsigned int flags;
} Fn118F28Entry;

typedef struct {
    int x;
    int y;
    int z;
} Fn118F28Vector;

extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006DBE4(int, int);
extern void fn_1_1902C(Fn118F28Entry *, int *, int, float);

void fn_1_18F28(Fn118F28Object *obj, int *args, int arg2, float value) {
    Fn118F28Vector vector;
    int i;
    Fn118F28Entry *entry;

    if (obj->count > 0) {
        lbl_8006DAEC();
        entry = (Fn118F28Entry *)obj->entries;
        i = 0;
        while (i < obj->count) {
            if ((entry->flags & 0x1e0002) == 0) {
                vector = *(Fn118F28Vector *)args;
                lbl_8006DBE4(vector.y, vector.x);
                fn_1_1902C(entry, args, arg2, value);
                *(Fn118F28Vector *)args = vector;
            }
            i++;
            entry = (Fn118F28Entry *)((char *)entry + 0x50);
        }
        lbl_8006DB30();
    }
}
/* fzgx:end fn_1_18F28 */

/* fzgx:begin fn_1_18FFC */
void fn_1_18FFC(int a, int b, int c, int d, int e, int f, int g) {
    fn_1_18784(c, d, e, g);
}
/* fzgx:end fn_1_18FFC */

/* fzgx:begin fn_1_1902C noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"

extern void fn_1_18784(int, int, int, int);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void fn_1_18784();
extern void lbl_8006DBE4(void);

typedef struct StcoliNode StcoliNode;
typedef struct StcoliVec {
    u32 x;
    u32 y;
    u32 z;
} StcoliVec;

struct StcoliNode {
    u32 flags;
    u8 pad[8];
    s32 count;
    StcoliNode *items;
    u8 rest[0x3c];
};

extern void fn_1_18F28(StcoliNode *, StcoliVec *, void *, f32);

// Traverse the four-level collision hierarchy, preserving the input vector at each level.
void fn_1_1902C(StcoliNode *root, StcoliVec *vec, void *arg3, f32 value) {
    StcoliNode *level1;
    s32 i1;

    fn_1_18784(0x800000, root, vec, 0, value);
    if (root->count > 0) {
        lbl_8006DAEC();
        level1 = root->items;
        i1 = 0;
        while (i1 < root->count) {
            if ((level1->flags & 0x001e0002) == 0) {
                StcoliVec saved1 = *vec;
                StcoliNode *level2;
                s32 i2;

                lbl_8006DBE4();
                fn_1_18784(0x800000, level1, vec, 0, value);
                if (level1->count > 0) {
                    lbl_8006DAEC();
                    level2 = level1->items;
                    i2 = 0;
                    while (i2 < level1->count) {
                        if ((level2->flags & 0x001e0002) == 0) {
                            StcoliVec saved2 = *vec;
                            StcoliNode *level3;
                            s32 i3;

                            lbl_8006DBE4();
                            fn_1_18784(0x800000, level2, vec, 0, value);
                            if (level2->count > 0) {
                                lbl_8006DAEC();
                                level3 = level2->items;
                                i3 = 0;
                                while (i3 < level2->count) {
                                    if ((level3->flags & 0x001e0002) == 0) {
                                        StcoliVec saved3 = *vec;
                                        StcoliNode *level4;
                                        s32 i4;

                                        lbl_8006DBE4();
                                        fn_1_18784(0x800000, level3, vec, 0, value);
                                        if (level3->count > 0) {
                                            lbl_8006DAEC();
                                            level4 = level3->items;
                                            i4 = 0;
                                            while (i4 < level3->count) {
                                                if ((level4->flags & 0x001e0002) == 0) {
                                                    StcoliVec saved4 = *vec;

                                                    lbl_8006DBE4();
                                                    fn_1_18784(0x800000, level4, vec, 0, value);
                                                    fn_1_18F28(level4, vec, arg3, value);
                                                    *vec = saved4;
                                                }
                                                i4 += 1;
                                                level4 += 1;
                                            }
                                            lbl_8006DB30();
                                        }
                                        *vec = saved3;
                                    }
                                    i3 += 1;
                                    level3 += 1;
                                }
                                lbl_8006DB30();
                            }
                            *vec = saved2;
                        }
                        i2 += 1;
                        level2 += 1;
                    }
                    lbl_8006DB30();
                }
                *vec = saved1;
            }
            i1 += 1;
            level1 += 1;
        }
        lbl_8006DB30();
    }
}
/* fzgx:end fn_1_1902C */

/* fzgx:begin fn_1_1B010 noprologue */
#include "types.h"
#include "game/vec3.h"
#include "rel/main_rel/stcoli.h"

typedef struct {
    u32 off[9];
} OffsetTable;

typedef struct {
    u8 pad_0[0x8];
    f32 zero;
    u8 pad_C[0x4];
    f32 minY;
    f32 maxY;
    u8 pad_18[0x8];
    f32 scale;
    f32 bias;
    u8 pad_28[0x24];
    OffsetTable shapes;
    OffsetTable counts;
} StcoliPool6C8;

typedef struct {
    u32 flags;
    u8 *cfg;
} StcoliEntity;

typedef struct {
    u8 pad_0[0x1D4];
    u32 flags;
} StcoliGlobal;

extern f32 lbl_1_rodata_6C8[2];
extern StcoliGlobal *lbl_801A66CC;
extern void fn_1_18214(StcoliEntity *, f32 *, void *);
extern void fn_8006E250(void *, Vec3f *);

void fn_1_1B010(u32 arg0, void *pos, u32 mode, StcoliEntity *entity, f32 *out, u32 arg5, void *work, f32 value) {
    StcoliPool6C8 *pool;
    OffsetTable shapes;
    OffsetTable counts;
    Vec3f local;
    u8 *cfg;
    s32 i;
    u8 *shape;
    f32 minV;
    f32 maxV;
    f32 t;
    f32 width;
    u32 n;
    s32 empty;

    pool = (StcoliPool6C8 *)&lbl_1_rodata_6C8;
    shapes = pool->shapes;
    counts = pool->counts;
    if ((mode & 0x200000) != 0) {
        empty = 1;
        minV = lbl_1_data_4;
        maxV = pool->zero;
        cfg = entity->cfg;
        for (i = 0; i < 9; i++) {
            shape = *(u8 **)(cfg + shapes.off[i]);
            if (shape != NULL) {
                t = *(f32 *)(shape + 4);
                n = *(u32 *)(cfg + counts.off[i]);
                if (minV > t) {
                    minV = t;
                }
                t = *(f32 *)(shape + n * 20 - 16);
                if (maxV < t) {
                    maxV = t;
                }
                empty = 0;
            }
        }
        if (empty || (minV < value && value < maxV)) {
            fn_1_18214(entity, out, work);
            t = *out;
            if (t < pool->zero) {
                t = -t;
            }
            width = pool->bias + (f32)(pool->scale * t);
            fn_8006E250(pos, &local);
            if (pool->minY < local.y && local.y < pool->maxY) {
                if (-width < local.x && local.x < width) {
                    lbl_801A66CC->flags |= entity->flags & 0x1E0000;
                }
            }
        }
    }
}
/* fzgx:end fn_1_1B010 */

/* fzgx:begin fn_1_1FB80 noprologue */
#include "types.h"
#include "rel/main_rel/stcoli.h"

extern const struct fn_1_1FB80_lbl_1_rodata_708_pool {
    f32 unk_0;
} lbl_1_rodata_708;

typedef struct { f32 x; f32 y; f32 z; } Vec_fn_1_1FB80;

/* 0x24-byte trigger volume entry */
typedef struct {
    u8 pad_0[0xC];
    s16 rot_x;
    s16 rot_y;
    s16 rot_z;
    u8 pad_12[2];
    f32 size_x;
    f32 size_y;
    f32 size_z;
    u32 flags;
} ColiVolume_fn_1_1FB80;


extern f64 __fabs(f64);
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_z(u32);
extern void fn_8006E250(void *, Vec_fn_1_1FB80 *);
extern void lbl_8006D7DC(void *);

#pragma opt_loop_invariants off
#pragma opt_propagation off
u32 fn_1_1FB80(void *pos, u32 mask) {
    struct { u32 value; } result;
    struct { s32 value; } i;
    struct { s32 value; } count;
    struct { ColiVolume_fn_1_1FB80 *value; } vol;
    Vec_fn_1_1FB80 local;

    result.value = 0;
    i.value = 0;
    vol.value = 0;
    count.value = (s32)lbl_1_bss_3BE0->unk_9C;
    vol.value = (ColiVolume_fn_1_1FB80 *)lbl_1_bss_3BE0->unk_A0;
    for (; i.value < count.value; i.value++, vol.value++) {
        if (vol.value->flags & mask) {
            lbl_8006D7DC(vol.value);
            if (vol.value->rot_z) {
                mathutil_mtxA_rotate_z(vol.value->rot_z);
            }
            if (vol.value->rot_y) {
                mathutil_mtxA_rotate_y(vol.value->rot_y);
            }
            if (vol.value->rot_x) {
                mathutil_mtxA_rotate_x(vol.value->rot_x);
            }
            fn_8006E250(pos, &local);
            if (__fabs(local.x) <= lbl_1_rodata_708.unk_0 * vol.value->size_x
             && __fabs(local.y) <= lbl_1_rodata_708.unk_0 * vol.value->size_y
             && __fabs(local.z) <= lbl_1_rodata_708.unk_0 * vol.value->size_z) {
                result.value |= vol.value->flags;
            }
        }
    }
    return result.value;
}
#pragma opt_propagation reset

#pragma opt_loop_invariants reset
/* fzgx:end fn_1_1FB80 */

/* fzgx:begin fn_1_1FC98 noprologue */
#include "types.h"
#include "game/vec3.h"
#include "rel/main_rel/stcoli.h"

typedef struct Sig_fn_1_1FC98_DB53CVec {
    f32 x;
    f32 y;
    f32 z;
} Sig_fn_1_1FC98_DB53CVec;

typedef struct fn_1_1FC98_Entry {
    Vec3f position;
    s16 unk_C;
    s16 unk_E;
    s16 unk_10;
    u8 pad_12[2];
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    u32 unk_20;
} fn_1_1FC98_Entry;

extern f32 lbl_1_rodata_708[78];
extern f64 __fabs(f64);
extern u32 lbl_8006D7DC(void *);
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_z(u32);
extern void fn_8006E250(Vec3f *, Vec3f *);

#pragma opt_loop_invariants off
#pragma opt_propagation off
u32 fn_1_1FC98(Vec3f *arg0, u32 arg1) {
    struct { u32 value; } v4;
    struct { s32 value; } v3;
    struct { s32 value; } v0;
    struct { fn_1_1FC98_Entry *value; } v2;
    Vec3f loc_8;

    v4.value = 0;
    v3.value = 0;
    v2.value = 0;
    v0.value = (s32)lbl_1_bss_3BE0->unk_94;
    v2.value = (fn_1_1FC98_Entry *)lbl_1_bss_3BE0->unk_98;
    while (v3.value < v0.value) {
        if ((v2.value->unk_20 & arg1) != 0) {
            lbl_8006D7DC(v2.value);
            if (v2.value->unk_10) {
                mathutil_mtxA_rotate_z(v2.value->unk_10);
            }
            if (v2.value->unk_E) {
                mathutil_mtxA_rotate_y(v2.value->unk_E);
            }
            if (v2.value->unk_C) {
                mathutil_mtxA_rotate_x(v2.value->unk_C);
            }
            fn_8006E250(arg0, &loc_8);
            if (__fabs(loc_8.x) <= (f32)(lbl_1_rodata_708[0] * v2.value->unk_14)) {
                if (__fabs(loc_8.y) <= (f32)(lbl_1_rodata_708[0] * v2.value->unk_18)) {
                    if (__fabs(loc_8.z) <= (f32)(lbl_1_rodata_708[0] * v2.value->unk_1C)) {
                        v4.value |= v2.value->unk_20;
                    }
                }
            }
        }
        v3.value++;
        v2.value++;
    }
    return v4.value;
}
#pragma opt_propagation reset
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_1FC98 */

/* fzgx:begin fn_1_1FFA0 noprologue */
#include "types.h"
#include "psvec.h"

typedef struct {
    f32 x, y, z;
} fn_1_1FFA0_Vec;

/* Treat an infinite/NaN result as zero (exponent field all ones). */
static inline BOOL fn_1_1FFA0_finite(f32 v) {
    return (*(u32 *)&v & 0x7F800000) != 0x7F800000;
}
#define FN_1_1FFA0_FINITE(v) fn_1_1FFA0_finite(v)

static inline f32 fn_1_1FFA0_squared_length(f32 x, f32 y, f32 z) {
    f32 result = x * x;
    result += y * y;
    result += z * z;
    return result;
}

/* Closest points between segments p1-p2 and p3-p4; returns their squared distance. */
f32 fn_1_1FFA0(fn_1_1FFA0_Vec *p1, fn_1_1FFA0_Vec *p2, fn_1_1FFA0_Vec *p3, fn_1_1FFA0_Vec *p4,
               fn_1_1FFA0_Vec *outA, fn_1_1FFA0_Vec *outB) {
    f32 fzgx_live__;
    f32 fzgx_live_;
    f32 fzgx_live;
    f32 s;
    fn_1_1FFA0_Vec diff;
    f32 t;
    f32 p3z, p1y;
    f32 d2y, d2z;
    f32 d1y, d1x, rx, d1z, rz;
    f32 d2x;
    f32 a, e, c, b, f;
    f32 ry;
    f32 p1z, p1x;

    fzgx_live_ = p3->x;
    p1x = p1->x;
    rx = p1x - fzgx_live_;
    d2x = p4->x - fzgx_live_;
    d1x = p2->x - p1x;
    fzgx_live_ = p3->y;
    p1y = p1->y;
    d2y = p4->y - fzgx_live_;
    d1y = p2->y - p1y;
    fzgx_live_ = p3->y;
    ry = p1y - fzgx_live_;
    p3z = p3->z;
    p1z = p1->z;
    d2z = p4->z - p3z;
    rz = p1z - p3z;
    d1z = p2->z - p1z;

    e = (f32)(rx * d2x) + (f32)(ry * d2y) + (f32)(rz * d2z);
    b = (f32)(d2x * d1x) + (f32)(d2y * d1y) + (f32)(d2z * d1z);
    c = (f32)(d2x * d2x) + (f32)(d2y * d2y) + (f32)(d2z * d2z);
    f = (f32)(rx * d1x) + (f32)(ry * d1y) + (f32)(rz * d1z);
    a = (f32)(d1x * d1x) + (f32)(d1y * d1y) + (f32)(d1z * d1z);

    s = ((f32)(e * b) - (f32)(f * c)) / ((f32)(a * c) - (f32)(b * b));
    if (!FN_1_1FFA0_FINITE(s)) {
        s = 0.0f;
    }
    t = (e + (f32)(s * b)) / c;
    if (!FN_1_1FFA0_FINITE(t)) {
        t = 0.0f;
    }

    psvec_sub(p2, p1, outA);
    if (s < 0.0f) {
        s = 0.0f;
    } else if (s > 1.0f) {
        s = 1.0f;
    }
    psvec_scale(outA, s, outA);
    psvec_add(p1, outA, outA);

    psvec_sub(p4, p3, outB);
    if (t < 0.0f) {
        t = 0.0f;
    } else if (t > 1.0f) {
        t = 1.0f;
    }
    psvec_scale(outB, t, outB);
    psvec_add(p3, outB, outB);

    psvec_sub(outB, outA, &diff);
    return fn_1_1FFA0_squared_length(diff.x, diff.y, diff.z);
}
/* fzgx:end fn_1_1FFA0 */

/* fzgx:begin fn_1_20258 */
typedef struct Fn_1_20258 {
    unsigned char pad00[0x30];
    f32 field30;
    f32 field34;
    unsigned char pad38[4];
    f32 field3c;
    unsigned char pad40[0x28];
    f32 field68;
    f32 field6c;
    unsigned char pad70[0xc];
    u32 flags;
} Fn_1_20258;

#pragma opt_strength_reduction on
f32 fn_1_20258(Fn_1_20258 *self, f32 *out_ratio) {
    u32 flags = self->flags;
    u8 *data = (*(u8 (*)[400])&lbl_1_data_5548);
    Fn_1_20258Constants *constants = &lbl_1_rodata_6C8;
    f32 ratio;
    f32 scale;

    if ((flags & 0x01c00000) != 0) {
        ratio = self->field34 / self->field30;
        if (ratio < constants->valuec0) {
            ratio = constants->value08;
        }
    } else if ((flags & 0x02200000) != 0) {
        ratio = constants->value0c;
    } else {
        OSReport((const char *)(data + 0x108), flags);
        OSPanic((const char *)(data + 0x12c), 0x1650,
                    (const char *)(data + 0x134));
    }

    if ((self->flags & 0x02200000) != 0 ||
        constants->value08 == ratio) {
        scale = self->field68;
    } else if ((self->flags & 0x01800000) != 0) {
        f32 t;

        t = constants->valuec8 * ratio;
        scale = (constants->value0c + t) * (self->field6c * self->field68);
    } else if ((self->flags & 0x00400000) != 0) {
        f32 t;
        f64 prod;

        t = constants->valuec8 * ratio;
        prod = constants->valued0 * self->field3c;
        scale = prod + (constants->value0c + t) * (self->field68 - self->field3c);
    } else {
        OSReport((const char *)(data + 0x138), self->flags);
        OSPanic((const char *)(data + 0x12c), 0x1661,
                    (const char *)(data + 0x15c));
    }

    if (out_ratio != 0) {
        *out_ratio = ratio;
    }
    return scale;
}
#pragma opt_strength_reduction reset
/* fzgx:end fn_1_20258 */

/* fzgx:begin fn_1_203E4 noprologue */
#include "types.h"
#include "game/vec3.h"
#include "rel/main_rel/stcoli.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"

/* The current matrix (mtxA) lives in the locked cache. */
#define MTXA ((f32(*)[4])LC_BASE)

typedef struct {
    u8 pad_0[0x3C];
    f32 unk_3C;
    f32 unk_40;
    u8 pad_44[0x24];
    f32 unk_68;
    f32 unk_6C;
    f32 unk_70;
    f32 unk_74;
    f32 unk_78;
    u32 unk_7C;
} fn_1_203E4_Obj;

/* View of the stcoli.c literal pool at lbl_1_rodata_6C8. */
typedef struct {
    u8 pad_0[0x8];
    f32 zero;      /* 0x08 */
    f32 one;       /* 0x0C */
    u8 pad_10[0x8];
    f32 minusOne;  /* 0x18 */
    u8 pad_1C[0x7C];
    f64 half;      /* 0x98 */
    u8 pad_A0[0x1C];
    f32 angleScale; /* 0xBC */
    u8 pad_C0[0x10];
    f64 two;       /* 0xD0 */
    f64 zeroD;     /* 0xD8 */
    f64 angleScaleD; /* 0xE0 */
    f64 oneD;      /* 0xE8 */
    f64 minusOneD; /* 0xF0 */
} fn_1_203E4_Pool;

extern const u8 lbl_1_rodata_6C8[];
extern void lbl_8006DC6C(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006E15C(f32, f32, f32);
extern u32 mathutil_mtxA_rotate_z(u32);
extern void lbl_8006E0B4(f32, f32, f32);
/* Interior entry 0xC bytes into mathutil_mtxA_rotate_z (mirror about the x axis). */
extern void mathutil_mtxA_rotate_z__fzgx_offset_C(f32, f32);
#define fn_1_203E4_flip mathutil_mtxA_rotate_z__fzgx_offset_C
extern void OSReport(const char *, ...);
extern void OSPanic(const char *, int, const char *, ...);

#pragma opt_propagation off
/* mtxA translation along its x axis */
static inline void fn_1_203E4_translate_x(f32 (*mtx)[4], f32 d) {
    f32 x, y, z;
    x = ((0)[mtx])[0];
    y = ((1)[mtx])[0];
    z = ((2)[mtx])[0];
    x = x * d + mtx[0][3];
    y = y * d + mtx[1][3];
    z = z * d + mtx[2][3];
    mtx[0][3] = x;
    mtx[1][3] = y;
    mtx[2][3] = z;
}

/* Translation used by the curved section. */
static inline void fn_1_203E4_translate_curve(f32 (*mtx)[4], f32 d) {
    f32 x, y, z, xx, yy, zz;
    x = mtx[0][0];
    y = mtx[1][0];
    z = mtx[2][0];
    xx = mtx[0][3];
    yy = mtx[1][3];
    zz = mtx[2][3];
    x = x * d + xx;
    y = y * d + yy;
    z = z * d + zz;
    mtx[0][3] = x;
    mtx[1][3] = y;
    mtx[2][3] = z;
}

/* mtxA translation along its y axis */
static inline void fn_1_203E4_translate_y(f32 (*mtx)[4], f32 d) {
    f32 x, y, z;
    x = ((0)[mtx])[1];
    y = ((1)[mtx])[1];
    z = ((2)[mtx])[1];
    x = x * d + mtx[0][3];
    y = y * d + mtx[1][3];
    z = z * d + mtx[2][3];
    mtx[0][3] = x;
    mtx[1][3] = y;
    mtx[2][3] = z;
}

#pragma opt_propagation off
#pragma opt_lifetimes off
void fn_1_203E4(fn_1_203E4_Obj *obj, s32 noOut, Vec3 *out, f32 pos, f32 scale, f32 dir) {
    f32 tz, ty, tx, distance;
    f32 (*mtx)[4];
    u32 flags;
    u8 *strings;
    const fn_1_203E4_Pool *k;
    f32 half;
    f32 sign;

    strings = lbl_1_data_5548;
    k = (const fn_1_203E4_Pool *)lbl_1_rodata_6C8;
    if (k->zeroD == dir) {
        lbl_8006DC6C(obj);
        mtx = MTXA;
        /* Preserve the retail order of translation-column loads. */
        tx = *(volatile f32 *)&obj->unk_70;
        ty = obj->unk_74;
        tz = obj->unk_78;
        ((0)[mtx])[3] = tx;
        ((1)[mtx])[3] = ty;
        ((2)[mtx])[3] = tz;
    } else {
        lbl_8006DBAC(obj);
    }
    flags = obj->unk_7C;
    if (flags & 1) {
        dir = -dir;
    }
    if ((flags & 0x2200000) || k->zero == dir) {
        distance = pos * scale;
        fn_1_203E4_translate_x(mtx = MTXA, distance);
    } else if (flags & 0x1800000) {
        f64 angle, angleScale;
        lbl_8006E15C(k->one, dir, k->one);
        angleScale = k->angleScaleD;
        angle = k->two;
        angle *= pos;
        mathutil_mtxA_rotate_z((s32)(angleScale * (angle * obj->unk_6C)));
        fn_1_203E4_translate_y(mtx = MTXA, k->half * -obj->unk_68);
        if (noOut == 0 && (obj->unk_7C & 1)) {
            fn_1_203E4_flip(k->zero, k->minusOne);
        }
    } else if (flags & 0x400000) {
        half = k->half * (obj->unk_3C / scale);
        sign = (pos > k->zero) ? k->oneD : k->minusOneD;
        if (k->oneD != dir) {
            lbl_8006E15C(k->one, dir, k->one);
        }
        if (__fabs(pos) < half) {
            lbl_8006E0B4(pos * scale, k->half * -obj->unk_40, k->zero);
        } else {
            f64 poolHalf = k->half;
            if (__fabs(pos) > poolHalf - half) {
                lbl_8006E0B4(scale * ((f64)(poolHalf * sign) - pos), poolHalf * obj->unk_40, k->zero);
                if (noOut == 0) {
                    fn_1_203E4_flip(k->zero, k->minusOne);
                }
            } else {
                pos = (f32)(pos - (f32)(sign * half)) / (poolHalf - (f64)(k->two * half));
                fn_1_203E4_translate_curve(mtx = MTXA, poolHalf * (sign * obj->unk_3C));
                mathutil_mtxA_rotate_z((s32)(k->angleScale * pos));
                fn_1_203E4_translate_y(mtx = MTXA, k->half * -obj->unk_40);
            }
        }
        if (noOut == 0 && (obj->unk_7C & 1)) {
            fn_1_203E4_flip(k->zero, k->minusOne);
        }
    } else {
        OSReport((char *)strings + 0x164, flags);
        OSPanic((char *)strings + 0x12C, 0x16A5, (char *)strings + 0x15C);
    }
    if (noOut) {
        mtx = MTXA;
        psvec_set(out, ((2)[mtx])[3], ((1)[mtx])[3], ((0)[mtx])[3]);
    }
}
#pragma opt_lifetimes reset

#pragma opt_propagation reset
/* fzgx:end fn_1_203E4 */

/* fzgx:begin fn_1_207DC */
#include "types.h"

struct A {
    u8 pad_0[0x30];
    f32 unk_30;
    f32 unk_34;
    u8 pad_38[4];
    f32 unk_3C;
    u8 pad_40[0x28];
    f32 unk_68;
    f32 unk_6C;
    u8 pad_70[0xC];
    u32 unk_7C;
};

struct P {
    u8 pad_0[0x8];
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[0xB0];
    f64 unk_C0;
    f32 unk_C8;
    u8 pad_CC[0x4];
    f64 unk_D0;
};

extern void OSPanic(const char *, int, const char *, ...);
extern void OSReport(const char *, ...);

static inline void st(f32 *o, f32 v) {
    if (o != 0) {
        *o = v;
    }
}

void fn_1_207DC(struct A *a, void *b, f32 t) {
    f32 r;
    f32 v;
    f32 loc;
    u32 fl;
    f32 *pl;
    u8 *d = (u8 *)&(*(u8 (*)[])&lbl_1_data_5548);
    struct P *p = (struct P *)&(*(struct P *)&lbl_1_rodata_6C8);

    if (a->unk_7C & 0x1C00000) {
        r = a->unk_34 / a->unk_30;
        if (r < p->unk_C0) {
            r = p->unk_8;
        }
    } else if (a->unk_7C & 0x2200000) {
        r = p->unk_C;
    } else {
        OSReport((const char *)(d + 0x108), a->unk_7C);
        OSPanic((const char *)(d + 0x12C), 0x1650, (const char *)(d + 0x134));
    }
    fl = a->unk_7C;
    if ((fl & 0x2200000) || p->unk_8 == r) {
        v = a->unk_68;
    } else if (fl & 0x1800000) {
        f32 m = p->unk_C8 * r;
        v = (p->unk_C + m) * (a->unk_6C * a->unk_68);
    } else if (fl & 0x400000) {
        f32 m = p->unk_C8 * r;
        f32 k = p->unk_C + m;
        f32 q = a->unk_3C;
        f64 h = p->unk_D0 * q;
        v = h + (f32)(k * (a->unk_68 - q));
    } else {
        OSReport((const char *)(d + 0x138), fl);
        OSPanic((const char *)(d + 0x12C), 0x1661, (const char *)(d + 0x15C));
    }
    st(&loc, r);
    fn_1_203E4(a, 1, b, t, v, loc);
}
/* fzgx:end fn_1_207DC */

/* fzgx:begin fn_1_20994 */
typedef struct Fn_1_20994_Object {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u8 pad_0C[0x71];
    u8 unk_7D;
} Fn_1_20994_Object;


int fn_1_20994(void *arg, f32 *out) {
    f32 value;
    int result;
    int index;
    Fn_1_20994_Object *object;

    value = lbl_1_rodata_6D0;
    result = 0;
    object = ((Fn_1_20994_Object *)lbl_1_bss_3BE0);
    if (object != 0) {
        if (object->unk_7D != 0) {
            index = 0;
        } else {
            index = object->unk_8 - 1;
        }
        do {
            result = fn_1_210A8(arg, &value, index--, 0, 0);
        } while (result < 0 && index >= 0);
        if (result < 0) {
            result = 0;
            value = lbl_1_rodata_6D0;
        }
    }
    *out = value;
    return result;
}
/* fzgx:end fn_1_20994 */

/* fzgx:begin fn_1_214C4 noprologue */
#include "types.h"
#include "rel/main_rel/stcoli.h"

typedef struct { u8 pad_0[0x40]; f32 lo; f32 hi; } Seg;
typedef struct { u32 a; Seg *seg; u32 b; } Ent;
extern const f32 lbl_1_rodata_6D0;

#pragma opt_propagation off
s32 fn_1_214C4(f32 *out, s32 start, f32 x) {
    Obj_1_bss_3BE0_Target *tbl;
    s32 v;
    s32 offset;
    s32 *p;
    s32 i;
    s32 sum;
    s32 idx;
    s32 loc[2];
    f32 t;
    f32 period;
    s32 n;
    s32 found;
    *out = lbl_1_rodata_6D0;
    if (lbl_1_bss_3BE0 == 0) {
        return 0;
    }
    n = (s32)lbl_1_bss_3BE0->unk_8;
    if (n == 0) {
        return 0;
    }
    if (start < 0 || n <= start) {
        start = 0;
    }
    found = 0;
    loc[0] = 0;
    loc[1] = -1;
    t = x;
    if ((((*(u32 *)&t) & 0x7F800000) - 0x7F800000) == 0) {
        return 0;
    }
    while (x < 0.0f) {
        period = *(f32 *)lbl_1_bss_3BE0->unk_90;
        x += period;
    }
    while (x >= *(f32 *)lbl_1_bss_3BE0->unk_90) {
        x -= *(f32 *)lbl_1_bss_3BE0->unk_90;
    }
    /* Reload the shared table pointer after normalizing the position. */
    tbl = *(Obj_1_bss_3BE0_Target *volatile *)&lbl_1_bss_3BE0;
    p = loc;
    for (i = 0; i < n; i++) {
        Seg *s;
        f32 lo;
        f32 hi;
        offset = (i & 1) * 4;
        v = *(s32 *)((u8 *)p + offset);
        sum = v + n;
        idx = (start + sum) % n;
        if (i & 1) {
            *(s32 *)((u8 *)p + offset) = v - 1;
        } else {
            *(s32 *)((u8 *)p + offset) = v + 1;
        }
        s = ((Ent *)tbl->unk_C)[idx].seg;
        lo = s->lo;
        hi = s->hi;
        if (lo <= x && x <= hi) {
            *out = (x - lo) / (hi - lo);
            found = idx;
            break;
        }
    }
    return found;
}
/* fzgx:end fn_1_214C4 */

/* fzgx:begin fn_1_21644 */
void *fn_1_21644(void *arg0, f32 *arg1, void *arg2) {
    int local;

    int status;

    local = 0;
    status = fn_1_16BA0(arg0, arg1, arg2, &local, 0);
    if (status < 0) {
        local = 0;
        *arg1 = fn_1_16E68(arg0, arg2, 0);
        return arg2;
    }
    return (void *)status;
}
/* fzgx:end fn_1_21644 */

/* fzgx:begin fn_1_216C0 */
void fn_1_216C0(void *arg0, void *arg1, void *arg2) {
    int local;

    local = 0;
    fn_1_16BA0(arg0, arg1, arg2, (int *)(void *)(&local), 0);
}
/* fzgx:end fn_1_216C0 */

/* fzgx:begin fn_1_2192C */
void fn_1_2192C(void *self, void *arg) {
    fn_1_18214(self, arg, 0);
}
/* fzgx:end fn_1_2192C */

/* fzgx:begin fn_1_21950 */
/* transform a vector by the current matrix, in place when src == dst */

/* GX write-gather FIFO: the compiler is free to reorder these stores */
#define GX_FIFO_F32 (*(f32 *)GX_FIFO_BASE)

static inline void fn_1_21950_set(Fn_1_21950Vec *v, f32 x, f32 y, f32 z) {
    f32 *fzgx_value;
    fzgx_value = &(v->x);
    *fzgx_value = x;
    v->y = y;
    v->z = z;
}

static inline void fn_1_21950_pos3(f32 x, f32 y, f32 z) {
    GX_FIFO_F32 = x;
    GX_FIFO_F32 = y;
    GX_FIFO_F32 = z;
}

#pragma opt_propagation off
void fn_1_21950(f32 *scale, f32 arg1, f32 arg2) {
    f32 fzgx_live;
    Fn_1_21950Constants *c;
    s32 drawA;
    s32 drawB;
    Fn_1_21950Vec c1;
    Fn_1_21950Vec c0;
    Fn_1_21950Vec b1;
    Fn_1_21950Vec b0;
    Fn_1_21950Vec a1;
    Fn_1_21950Vec a0;

    c = (Fn_1_21950Constants *)&(*((Fn_1_21950Constants *)&lbl_1_rodata_6C8));
    fzgx_live = c->zero;
    drawA = fzgx_live != arg1;
    fzgx_live = c->zero;
    drawB = fzgx_live != arg2;

    fzgx_live = c->zero;
    fn_1_21950_set(&a0, c->neg_half, fzgx_live, fzgx_live);
    a0.x *= *scale;
    lbl_8006E1B0( (void *)(Fn_1_21950Vec *)(&a0), (void *)(Fn_1_21950Vec *)(&a0));

    fzgx_live = c->zero;
    fn_1_21950_set(&a1, c->half, fzgx_live, fzgx_live);
    a1.x = c->half * *scale;
    lbl_8006E1B0( (void *)(Fn_1_21950Vec *)(&a1), (void *)(Fn_1_21950Vec *)(&a1));

    if (drawA) {
        fzgx_live = c->zero;
        fn_1_21950_set(&b0, c->neg_half, fzgx_live, fzgx_live);
        b0.x = c->neg_half * *scale;
        lbl_8006E1B0( (void *)(Fn_1_21950Vec *)(&b0), (void *)(Fn_1_21950Vec *)(&b0));

        fzgx_live = c->zero;
        fn_1_21950_set(&b1, c->neg_half, arg1, fzgx_live);
        b1.x = c->neg_half * *scale;
        lbl_8006E1B0( (void *)(Fn_1_21950Vec *)(&b1), (void *)(Fn_1_21950Vec *)(&b1));
    }

    if (drawB) {
        fzgx_live = c->zero;
        fn_1_21950_set(&c0, c->half, fzgx_live, fzgx_live);
        c0.x = c->half * *scale;
        lbl_8006E1B0( (void *)(Fn_1_21950Vec *)(&c0), (void *)(Fn_1_21950Vec *)(&c0));

        fzgx_live = c->zero;
        fn_1_21950_set(&c1, c->half, arg2, fzgx_live);
        c1.x = c->half * *scale;
        lbl_8006E1B0( (void *)(Fn_1_21950Vec *)(&c1), (void *)(Fn_1_21950Vec *)(&c1));
    }

    lbl_8006DAEC();
    lbl_8006DCA4();
    fn_80072558();

    fn_8003462C(0xb0, 0, 2);
    GX_FIFO_F32 = a0.x;
    GX_FIFO_F32 = a0.y;
    GX_FIFO_F32 = a0.z;
    GX_FIFO_F32 = a1.x;
    GX_FIFO_F32 = a1.y;
    GX_FIFO_F32 = a1.z;

    if (drawA) {
        fn_8003462C(0xb0, 0, 2);
        fn_1_21950_pos3(b0.x, b0.y, b0.z);
        fn_1_21950_pos3(b1.x, b1.y, b1.z);
    }

    if (drawB) {
        fn_8003462C(0xb0, 0, 2);
        fn_1_21950_pos3(c0.x, c0.y, c0.z);
        fn_1_21950_pos3(c1.x, c1.y, c1.z);
    }

    lbl_8006DB30();
}
#pragma opt_propagation reset
/* fzgx:end fn_1_21950 */

/* fzgx:begin fn_1_21BE4 */
typedef struct Fn_1_21BE4 {
    u32 flags;
    unsigned char pad04[0x38];
    f32 field3c;
    f32 field40;
} Fn_1_21BE4;

void fn_1_21BE4(Fn_1_21BE4 *self, void *arg) {
    f32 value2;
    f32 value1;

    fn_1_18214(self, arg, 0);
    if ((self->flags & 0x800) != 0) {
        value2 = self->field3c;
    } else {
        value2 = (*((f32 *)&lbl_1_rodata_6D0));
    }
    if ((self->flags & 0x400) != 0) {
        value1 = self->field40;
    } else {
        value1 = (*((f32 *)&lbl_1_rodata_6D0));
    }
    fn_1_21950( (f32 *)(void *)(arg), value1, value2);
}
/* fzgx:end fn_1_21BE4 */

/* fzgx:begin fn_1_21C5C */
void fn_1_21C5C(void *self, void *arg) {
    fn_1_18214(self, arg, 0);
    fn_1_21950( (f32 *)(void *)(arg), lbl_1_rodata_6D4, lbl_1_rodata_6D4);
}
/* fzgx:end fn_1_21C5C */

/* fzgx:begin fn_1_21CA0 */
typedef struct Fn_1_21CA0 {
    u32 flags;
    unsigned char pad04[0x38];
    f32 field3c;
    f32 field40;
} Fn_1_21CA0;

void fn_1_21CA0(Fn_1_21CA0 *self, void *arg) {
    f32 value2;
    f32 value1;

    if ((self->flags & 0x800) != 0) {
        value2 = self->field3c;
    } else {
        value2 = (*((f32 *)&lbl_1_rodata_6D0));
    }
    if ((self->flags & 0x400) != 0) {
        value1 = self->field40;
    } else {
        value1 = (*((f32 *)&lbl_1_rodata_6D0));
    }
    fn_1_21950( (f32 *)(void *)(arg), value1, value2);
}
/* fzgx:end fn_1_21CA0 */

/* fzgx:begin fn_1_21CFC noprologue */
#include "dolphin/types.h"
#include "dolphin/hw_regs.h"
#include "game/main_rel/car_test_types.h"

extern const struct fn_1_21CFC_lbl_1_rodata_6D0_pool {
    f32 unk_0;
} lbl_1_rodata_6D0;

extern const struct fn_1_21CFC_lbl_1_rodata_6E8_pool {
    f32 unk_0;
} lbl_1_rodata_6E8;

extern void fn_1_18214(void *, f32 *, u32);
extern f32 lbl_8006D188(s16);
extern void lbl_8006E1B0(Fn183D28Vec3 *, Fn183D28Vec3 *);
extern void lbl_8006DAEC(void);
extern u32 lbl_8006DCA4(void);
extern void fn_80072558(void);
extern void fn_8003462C(u32, u32, u32);
extern void lbl_8006DB30(void);

/* GX write-gather pipe: volatile because every store is a FIFO write. */
#define GX_FIFO_F32 (*(volatile f32 *)GX_FIFO_BASE)

static inline void GXPosition3f32(f32 x, f32 y, f32 z)
{
    GX_FIFO_F32 = x;
    GX_FIFO_F32 = y;
    GX_FIFO_F32 = z;
}

void fn_1_21CFC(void *obj, f32 *scale)
{
    Fn183D28Vec3 pts[16];
    Fn183D28Vec3 *v;
    s32 i;
    s32 angle;
    f32 radius;
    f32 y;
    f32 z;

    fn_1_18214(obj, scale, 0);
    z = lbl_1_rodata_6D0.unk_0;
    radius = lbl_1_rodata_6E8.unk_0;
    v = pts;
    for (i = 0, angle = 0; i < 16; i++, angle += 0x1000) {
        y = radius * lbl_8006D188((s16)(angle + 0x4000));
        v->x = radius * lbl_8006D188((s16)angle);
        v->y = y;
        v->z = z;
        v->x *= scale[0];
        v->y *= scale[1];
        lbl_8006E1B0(v, v);
        v++;
    }
    lbl_8006DAEC();
    lbl_8006DCA4();
    fn_80072558();
    v = pts;
    fn_8003462C(0xb0, 0, 0x11);
    for (i = 0; i < 16; i++) {
        GXPosition3f32(v->x, v->y, v->z);
        v++;
    }
    GX_FIFO_F32 = pts[0].x;
    GX_FIFO_F32 = pts[0].y;
    GX_FIFO_F32 = pts[0].z;
    lbl_8006DB30();
}
/* fzgx:end fn_1_21CFC */

/* fzgx:begin fn_1_21F18 noprologue */
#include "types.h"
#include "dolphin/hw_regs.h"
#include "game/main_rel/car_test_types.h"

typedef struct {
    u8 pad_0[0x4];
    u32 key;
    u8 pad_8[0x20];
    void *curve;
} StcoliCurveSrc;

typedef struct {
    u8 pad_0[0x4];
    StcoliCurveSrc *src;
    u8 pad_8[0x10];
    f32 value;
} StcoliCurveOwner;

typedef struct {
    u8 pad_0[0xc];
    s32 mode;
    StcoliCurveOwner *owner;
} StcoliDrawEntity;

/* Literal pool of stcoli.c, read through one base register. */
typedef struct {
    u8 pad_0[0x8];
    f32 zero;
    u8 pad_C[0x14];
    f32 half;
    u8 pad_24[0x10];
    f32 neg_half;
} StcoliPool6C8;

extern f32 lbl_1_rodata_6C8[2];
extern void fn_1_18214(StcoliDrawEntity *, f32 *, void *);
extern f32 fn_1_9E14C(u32, void *, f32);
extern f32 lbl_8006D188(s16);
extern void lbl_8006DAEC(void);
extern u32 lbl_8006DCA4(void);
extern void fn_80072558(void);
extern void fn_8003462C(u32, u32, u32);
extern void lbl_8006DB30(void);

/* GX write-gather pipe: every store must reach the FIFO, hence volatile. */
#define GX_WRITE_F32(v) (*(volatile f32 *)GX_FIFO_BASE = (v))

static inline void GXPosition3f32(f32 x, f32 y, f32 z) {
    GX_WRITE_F32(x);
    GX_WRITE_F32(y);
    GX_WRITE_F32(z);
}

static inline f32 fn_1_21F18_array_read(f32 *array, s32 index) { return array[index]; }
#pragma opt_common_subs off
void fn_1_21F18(StcoliDrawEntity *entity, f32 *scale, f32 time) {
    StcoliPool6C8 *pool;
    Fn183D28Vec3 v;
    Fn183D28Vec3 pts[16];
    Fn183D28Vec3 *p;
    s32 i;
    s32 angle;
    f32 half;
    f32 c;
    f32 zero;
    register f32 t;
    StcoliCurveOwner *owner;
    StcoliCurveSrc *src;

    pool = (StcoliPool6C8 *)lbl_1_rodata_6C8;
    fn_1_18214(entity, scale, NULL);
    zero = pool->zero;
    half = pool->half;
    p = pts;
    for (i = 0, angle = 0; i < 16; i++, angle += 0x1000) {
        c = half * lbl_8006D188((s16)(angle + 0x4000));
        p->x = half * lbl_8006D188((s16)angle);
        p->y = c;
        p->z = zero;
        p->x *= fn_1_21F18_array_read(scale, 0);
        p->y *= fn_1_21F18_array_read(scale, 1);
        lbl_8006E1B0(p, p);
        p++;
    }
    lbl_8006DAEC();
    lbl_8006DCA4();
    fn_80072558();
    p = pts;
    fn_8003462C(0xb0, 0, 17);
    for (i = 0; i < 16; i++) {
        GXPosition3f32(p->x, p->y, p->z);
        p++;
    }
    GX_WRITE_F32(pts[0].x);
    GX_WRITE_F32(pts[0].y);
    GX_WRITE_F32(pts[0].z);
    lbl_8006DB30();

    if (entity->mode == 1) {
        owner = entity->owner;
        src = owner->src;
        if (src->curve != NULL) {
            t = fn_1_9E14C(src->key, src->curve, time);
        } else {
            t = owner->value;
        }
        {
            /* Preserve the literal-component read order. */
            volatile StcoliPool6C8 *components = pool;
            register f32 n = components->neg_half;
            f32 z = components->zero;
            f32 x;
            f32 y = n + t;
            x = components->half;
            v.z = z;
            v.x = x;
            v.y = y;
            v.x = x * fn_1_21F18_array_read(scale, 0);
            v.y = y * fn_1_21F18_array_read(scale, 1);
        }
        lbl_8006E1B0(&v, &pts[0]);
        v.x = -v.x;
        lbl_8006E1B0(&v, &pts[1]);
        lbl_8006DAEC();
        lbl_8006DCA4();
        fn_80072558();
        fn_8003462C(0xb0, 0, 2);
        GX_WRITE_F32(pts[0].x);
        GX_WRITE_F32(pts[0].y);
        GX_WRITE_F32(pts[0].z);
        GX_WRITE_F32(pts[1].x);
        GX_WRITE_F32(pts[1].y);
        GX_WRITE_F32(pts[1].z);
        lbl_8006DB30();
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_21F18 */

/* fzgx:begin fn_1_224F8 noprologue */
#include "types.h"
#include "game/main_rel/stcoli_types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} StcoliGateVec;

typedef struct {
    StcoliGateVec pos;
    s16 rot_x;
    s16 rot_y;
    s16 rot_z;
    u8 pad_12[2];
    f32 width;
    f32 height;
    u8 pad_1C[4];
    u32 round;
} StcoliGate;

typedef struct {
    u8 pad_0[0x8];
    f32 zero;    /* 0x08 */
    f32 one;     /* 0x0C */
    u8 pad_10[0x4];
    f32 ten;     /* 0x14 */
    f32 neg_one; /* 0x18 */
    u8 pad_1C[0x4];
    f32 half;    /* 0x20 */
} Fn_1_224F8Constants;

extern s16 fn_1_7B054();
extern void lbl_8006DAEC(void);
extern void lbl_8006D7DC(void *);
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_z(u32);
extern void lbl_8006DF44(void);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006DB30(void);

#pragma section code_type ".fzgxpool"
/* Volatile stores preserve the retail shared literal pool's ordering. */
void fzgx_fn_1_224F8_pool_primer(volatile f64 *d, volatile f32 *f) {
    *d = 4503601774854144.0;
    *f = 0.0f;
    *f = 1.0f;
    *f = -5.0f;
    *f = 10.0f;
    *f = -1.0f;
    *f = 2.0f;
    *f = 0.5f;
}
#pragma section code_type ".text"

s32 fn_1_224F8(StcoliGateVec *start, StcoliGateVec *end, u32 *mask) {
    const Fn_1_224F8Constants *c;
    s32 result;
    s32 i;
    s32 first;
    StcoliGate *gate;
    StcoliGateVec p0;
    StcoliGateVec p1;
    StcoliGateVec delta;
    StcoliGateVec hit;
    f32 sx;
    f32 sy;
    f32 t;
    s32 below1;

    c = (const Fn_1_224F8Constants *)&lbl_1_rodata_6C8;
    result = -1;
    if (fn_1_7B054() == -1) {
        return -1;
    }
    if (lbl_1_bss_3BE0 == NULL) {
        return -1;
    }
    first = __cntlzw(*mask);
    lbl_8006DAEC();
    for (i = first, gate = &((StcoliGate *)lbl_1_bss_3BE0->unk_B0)[first]; i < (s32)lbl_1_bss_3BE0->unk_AC; i++, gate++) {
        if (!__rlwnm(*mask, (i + 1) & 0x1F, 31, 31)) {
            continue;
        }
        lbl_8006D7DC(gate);
        if (gate->rot_z) {
            mathutil_mtxA_rotate_z(gate->rot_z);
        }
        if (gate->rot_y) {
            mathutil_mtxA_rotate_y(gate->rot_y);
        }
        if (gate->rot_x) {
            mathutil_mtxA_rotate_x(gate->rot_x);
        }
        lbl_8006DF44();
        lbl_8006E1B0(start, &p0);
        lbl_8006E1B0(end, &p1);
        below1 = p1.z < 0.0f;
        if (!(p0.z < 0.0f) || below1) {
            continue;
        }
        sx = 0.5f * (10.0f * gate->width);
        sy = 0.5f * (10.0f * gate->height);
        p0.x /= sx;
        p0.y /= sy;
        p1.x /= sx;
        p1.y /= sy;
        psvec_sub(&p0, &p1, &delta);
        t = -(p0.z / delta.z);
        psvec_scale_add(&p0, &delta, t, &hit);
        if (gate->round) {
            f32 xx = hit.x * hit.x;
            f32 yy = hit.y * hit.y;
            if (xx + yy <= 1.0f) {
                result = i;
                break;
            }
        } else if ((-1.0f) <= hit.x && hit.x <= 1.0f && (-1.0f) <= hit.y && hit.y <= 1.0f) {
            result = i;
            break;
        }
    }
    lbl_8006DB30();
    if (result >= 0) {
        *mask &= 0xFFFFFFFFu >> (result + 1);
    }
    return result;
}
/* fzgx:end fn_1_224F8 */

/* fzgx:begin fn_1_2277C noprologue */
#include "dolphin/types.h"

#pragma fp_contract on

typedef struct StcoliVec {
    f32 x, y, z;
} StcoliVec;

typedef struct StcoliWheel {
    s32 state;          /* 0x00 */
    f32 f04;            /* 0x04 */
    StcoliVec pos;      /* 0x08 */
    StcoliVec vel;      /* 0x14 */
    u8 pad20[0x24];
    f32 f44;            /* 0x44 */
    f32 f48;            /* 0x48 */
    u8 pad4C[0x10];
} StcoliWheel; /* 0x5c */

typedef struct StcoliPoint {
    StcoliVec pos;      /* 0x00 */
    u8 pad0C[0x18];
    StcoliVec vel;      /* 0x24 */
} StcoliPoint; /* 0x30 */

typedef struct StcoliObj {
    u32 flags;              /* 0x000 */
    s16 s04;                /* 0x004 */
    s16 s06;                /* 0x006 */
    f32 size;               /* 0x008 */
    u8 pad00C[0x30];
    char name[32];          /* 0x03C */
    u8 pad05C[0x50];
    f32 fAC;                /* 0x0AC */
    f32 fB0;                /* 0x0B0 */
    f32 fB4;                /* 0x0B4 */
    u8 pad0B8[0x170];
    f32 f228;               /* 0x228 */
    u8 pad22C[0x18];
    StcoliWheel wheels[4];  /* 0x244 */
    StcoliPoint points[4];  /* 0x3B4 */
    s8 s474;                /* 0x474 */
    s8 s475;                /* 0x475 */
    u8 pad476[0x10E];
    f32 maxLen;             /* 0x584 */
    f32 maxX;               /* 0x588 */
    u8 pad58C[4];
    u8 b590;                /* 0x590 */
    u8 pad591[0x49];
    s16 s5DA;               /* 0x5DA */
} StcoliObj;

typedef struct StcoliDesc {
    char *name;             /* 0x00 */
    u8 pad04[0x50];
    StcoliVec wheelPos[4];  /* 0x54 */
    StcoliVec pointPos[4];  /* 0x84 */
} StcoliDesc;

extern char *strncpy(char *, const char *, unsigned long);
extern void fn_1_22E8C(void *, void *);
extern void fn_1_22F90(void *, int);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006DAEC(void);
extern void lbl_8006D758(void);
extern void lbl_8006DB30(void);

static inline f32 stcoli_mag(StcoliVec *v)
{
    f32 *c = &v->x;
    f32 sq;

    /* distinct operand spellings: MWCC never fuses a literal square a*a */
    sq = v->x * v->x;
    sq += c[1] * v->y;
    sq += c[2] * v->z;
    return lbl_8006D0B4(sq);
}

void fn_1_2277C(StcoliObj *obj, StcoliDesc *desc)
{
    s32 i;
    f32 len;
    f32 ax;
    StcoliPoint *pt;

    obj->flags = 0;
    obj->s04 = 0;
    obj->s06 = 0;
    strncpy(obj->name, desc->name, 31);
    obj->name[31] = 0;
    fn_1_22E8C(obj, desc);

    obj->fAC = 52.0f * obj->size / 16.0f;
    obj->fB0 = 45.0f * obj->size / 16.0f;
    obj->fB4 = 52.0f * obj->size / 16.0f;

    obj->f228 = 0.0f;
    for (i = 0; i < 4; i++) {
        obj->wheels[i].f44 = 0.0f;
        obj->wheels[i].pos = desc->wheelPos[i];
        obj->wheels[i].vel.x = 0.0f;
        obj->wheels[i].vel.y = 0.0f;
        obj->wheels[i].vel.z = 0.0f;
        obj->wheels[i].state = 0;
        obj->wheels[i].f04 = 0.0f;
        obj->wheels[i].f48 = 1.7f;
    }

    obj->maxLen = 0.0f;
    obj->maxX = 1.0f;
    for (i = 0; i < 4; i++) {
        pt = &obj->points[i];
        pt->pos = desc->pointPos[i];
        pt->vel.x = 0.0f;
        pt->vel.y = 0.0f;
        pt->vel.z = 0.0f;
        len = stcoli_mag(&pt->pos);
        if (obj->maxLen < len) {
            obj->maxLen = len;
        }
        ax = __fabs(pt->pos.x);
        if (obj->maxX < ax) {
            obj->maxX = ax;
        }
    }

    obj->maxLen += 0.1f;
    obj->s474 = -1;
    obj->s475 = -1;
    obj->b590 = 0;
    obj->s5DA = 100;
    lbl_8006DAEC();
    lbl_8006D758();
    fn_1_22F90(obj, 1);
    lbl_8006DB30();
}
/* fzgx:end fn_1_2277C */

/* fzgx:begin fn_1_229EC noprologue */
typedef float f32;
typedef double f64;
typedef struct { f32 pad0; f32 f4; f32 f8; f32 fc; f32 pad[12]; f32 f40; } S229;
extern const f32 lbl_1_rodata_840[32];

void fn_1_229EC(S229 *a, f32 *p, f32 *q)
{
    f32 d, t, x, k, m, n;
    f32 old_q;
    const f32 *K = lbl_1_rodata_840;
    old_q = *q;
    m = K[10] * a->f8;
    n = K[10] * a->fc;
    k = m / K[11];
    x = k + *p;
    d = x - old_q;
    t = x / (K[12] + n);
    if (t < K[3]) {
        t = K[3];
    }
    k = K[13] * (a->f8 * (K[14] + a->f8));
    t = t * k;
    if (old_q < K[3]) {
        t = t * K[15];
    }
    {
        f32 e = d * t;
        *p = x - e;
    }
    {
        f32 y = *p;
        f32 h = a->f40;
        if (y > h) {
            *p = y - h;
        } else {
            *p = K[3];
        }
    }
    if (old_q < K[3]) {
        d = d * K[16];
    }
    *q = *q + (K[17] * d) / a->f4;
    {
        f32 s = *q;
        f32 u = s * s;
        *q = s - (K[18] * u) / a->f4;
    }
    if (((const f64 *)K)[10] * *q < ((const f64 *)K)[11]) {
        *q = K[3];
    }
}
/* fzgx:end fn_1_229EC */

/* fzgx:begin fn_1_22B10 noprologue */
#include "types.h"

struct fn_1_22B10_Arg0 {
    u8 pad_0[0x4];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad_18[0x4];
    f32 unk_1C;
    f32 unk_20;
    u8 pad_24[0x10];
    f32 unk_34;
    u8 pad_38[0x4];
    f32 unk_3C;
};

extern f64 __fabs(f64);

/* Primes the literal pool so it lines up with retail's lbl_1_rodata_840. */
#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_pool_fn_1_22B10(s32 fzgx_int_fn_1_22B10) {
    volatile f32 s;  /* volatile: keeps each literal use alive for the primer */
    volatile f64 sd; /* volatile: as above */
    s = 52.0f;
    s = 0.0625f;
    s = 45.0f;
    s = 0.0f;
    s = 1.7f;
    s = 1.0f;
    s = 0.1f;
    s = 0.5f;
    sd = 4503599627370496.0; /* 2^52: retail's int-to-float bias */
    s = 40.0f;
    s = 348.0f;
    s = 36.0f;
    s = 4.0f;
    s = 0.6f;
    s = 5.0f;
    s = 0.05f;
    s = 1000.0f;
    sd = 131072.0;
    sd = 216.0;
    sd = 2.0;
    s = 0.25f;
    s = 0.07f;
    s = 0.2f;
    sd = 0.84;
    s = 2.0f;
    s = 1.8f;
    s = 1.4f;
    s = 1.5f;
    s = 1.2f;
    s = 2.3f;
    s = 0.4f;
    s = 3.2f;
    s = 0.15f;
    s = -0.25f;
    s = 0.16f;
    s = 0.12f;
    s = 0.08f;
    s = 0.45f;
    s = 0.7f;
    sd = (f64)0.6f;
    s = 0.31f;
    s = 0.03f;
    s = 0.01f;
    s = 700.0f;
}

#pragma fp_contract off
void fn_1_22B10(struct fn_1_22B10_Arg0 *p, f32 speed) {
    f32 a;
    f32 b;
    f32 d;
    f32 t;
    f32 k;
    f32 r;
    f32 m;
    f32 y;
    f32 x;
    s32 flag;
    f32 scale;

    flag = 1;
    d = speed - 0.5f;
    if (d > 0.0f) {
        b = 0.0f;
        a = 1.0f;
        x = p->unk_1C;
        if (x > 1.0f) {
            p->unk_1C = x - 1.8f * (x * d);
        }
    } else {
        x = p->unk_1C;
        a = 0.0f;
        b = 1.4f;
        if (x < 1.0f) {
            p->unk_1C = x - 2.0f * ((2.0f - x) * d);
        } else if (x < 1.5f) {
            p->unk_1C = x - 1.2f * (x * d);
        } else {
            p->unk_1C = x - (1.2f - (x - 1.5f)) * (x * d);
        }
        if (p->unk_1C > 2.3f) {
            p->unk_1C = 2.3f;
        }
    }

    if (d < 0.0f && p->unk_8 >= 0.5f && p->unk_C <= 0.2f) {
        flag = 0;
    }

    t = d * __fabs(a - p->unk_C);
    if (d > 0.0f) {
        k = 1.0f;
        if (p->unk_8 < 0.4f) {
            k = 3.2f;
        } else if (p->unk_8 >= 0.5f) {
            if (p->unk_C < 0.15f) {
                k = 0.0f;
            } else {
                k = -0.25f;
            }
        }
        t *= 0.16f * k;
    } else {
        r = (p->unk_C - 0.12f) / 0.08f;
        if (r > 1.0f) {
            r = 1.0f;
        }
        t *= 0.45f * (0.4f + 0.2f * r);
    }

    x = p->unk_8;
    if (x > 0.6f && d < 0.0f) {
        p->unk_8 = x + (2.0f * d) * __fabs(0.7f - x);
    } else {
        p->unk_8 += 0.6f * (-d * __fabs(b - x));
    }

    if (p->unk_8 < 0.4f) {
        m = 1.0f;
        if (p->unk_8 < 0.31f) {
            t *= 1.5f;
            m = 1.5f;
        }
        if (p->unk_3C > 0.03f) {
            m *= 1.5f;
        }
        if (d < 0.0f) {
            m *= 2.0f;
        }
        p->unk_3C -= __fabs(0.7f * (m * (p->unk_3C * d)));
        if (p->unk_3C < 0.01f) {
            p->unk_3C = 0.01f;
        }
    }

    if (p->unk_4 < 700.0f && p->unk_8 > 0.7f) {
        p->unk_8 = 0.7f;
    }

    p->unk_C += t;
    if (d > 0.0f) {
        p->unk_20 *= 1.0f - 0.6f * d;
    } else {
        p->unk_20 *= 1.0f - 0.2f * d;
    }

    scale = 1.0f;
    p->unk_10 = p->unk_10 * (scale + 0.25f * d);
    p->unk_14 = p->unk_14 * (scale + 0.25f * d);

    if (flag) {
        p->unk_34 *= scale + 0.1f * d;
    }
}
#pragma fp_contract reset
/* fzgx:end fn_1_22B10 */

/* fzgx:begin fn_1_22E8C */
typedef struct Fn_1_22E8CInput {
    unsigned char pad00[0x04];
    float field04;
    float field08;
    float field0c;
    float field10;
    float field14;
    float field18;
    float field1c;
    float field20;
    float field24;
    float field28;
    float field2c;
    float field30;
    float field34;
    float field38;
    float field3c;
    float field40;
    float field44;
    unsigned char field48;
    unsigned char field49;
    unsigned char pad4a[0x02];
    float field4c;
    float field50;
} Fn_1_22E8CInput;

typedef struct Fn_1_22E8COutput {
    unsigned int flags;
    unsigned char pad04[0x04];
    float field08;
    float field0c;
    float field10;
    float field14;
    float field18;
    float field1c;
    float field20;
    float field24;
    float field28;
    float field2c;
    float field30;
    float field34;
    float field38;
    unsigned char pad3c[0x1e4];
    float field220;
    unsigned char pad224[0x08];
    float field22c;
    float field230;
    float field234;
    float field238;
    float field23c;
    unsigned char pad240[0x237];
    unsigned char field477;
} Fn_1_22E8COutput;

void fn_1_22E8C(Fn_1_22E8COutput *self, Fn_1_22E8CInput *source) {
    float first = source->field04;
    double scale = lbl_1_rodata_910;

    self->field08 = first;
    self->field0c = source->field10;
    self->field28 = source->field14;
    self->field14 = source->field20;
    self->field1c = source->field28;
    self->field20 = source->field2c;
    self->field24 = source->field30;
    self->field30 = source->field44;
    self->field10 = source->field18;
    self->field2c = source->field1c;
    self->field477 = source->field48;
    self->field34 = source->field4c;
    self->field38 = source->field50;
    self->field18 = source->field24;
    self->field220 = source->field08;
    self->field22c = source->field0c;
    self->field230 = (float)(scale * source->field34);
    self->field234 = source->field38;
    self->field238 = source->field3c;
    self->field23c = source->field40;
    if (source->field49 & 1) {
        self->flags |= 0x100;
    } else {
        self->flags &= ~0x100;
    }
    if (source->field49 & 2) {
        self->flags |= (1u << 31);
    } else {
        self->flags &= 0x7fffffff;
    }
}
/* fzgx:end fn_1_22E8C */

/* fzgx:begin fn_1_23500 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 52.0f;
    s = 0.0625f;
    s = 45.0f;
    s = 0.0f;
    s = 1.7000000476837158f;
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.5f;
    d = 4503599627370496.0;
    s = 40.0f;
    s = 348.0f;
    s = 36.0f;
    s = 4.0f;
    s = 0.6000000238418579f;
    s = 5.0f;
    s = 0.05000000074505806f;
    s = 1000.0f;
    s = 8.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 216.0;
    d = 2.0;
    s = 0.25f;
    s = 0.07000000029802322f;
    s = 0.20000000298023224f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.834999918937683f;
}
static const u32 fzgx_pool_table6[1] = {0xAE147AE1};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.0f;
    s = 1.7999999523162842f;
    s = 1.399999976158142f;
    s = 1.5f;
    s = 1.2000000476837158f;
    s = 2.299999952316284f;
    s = 0.4000000059604645f;
    s = 3.200000047683716f;
    s = 0.15000000596046448f;
    s = -0.25f;
    s = 0.1599999964237213f;
    s = 0.11999999731779099f;
    s = 0.07999999821186066f;
    s = 0.44999998807907104f;
    s = 0.699999988079071f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6000000238418579;
    s = 0.3100000023841858f;
    s = 0.029999999329447746f;
    s = 0.009999999776482582f;
    s = 700.0f;
    s = 1.7674999237060547f;
}
static const u32 fzgx_pool_table10[1] = {0xA3D70A3D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5699999928474426f;
}
static const u32 fzgx_pool_table12[4] = {0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.10000000149011612f;
    s = 200.0f;
    s = 0.019999999552965164f;
}
#pragma section code_type ".text"

typedef struct Fn_1_23500_Rodata {
    unsigned char pad00[0xc];
    f32 value0c;
    unsigned char pad10[0x4];
    f32 value14;
    unsigned char pad18[0x38];
    f64 value50;
    unsigned char pad58[0x98];
    f32 valuef0;
} Fn_1_23500_Rodata;


typedef struct Fn_1_23500 {
    int flags;
    unsigned char pad04[4];
    f32 field08;
    unsigned char pad0c[0x88];
    f32 field94;
    unsigned char pad98[0x168];
    f32 field200;
    unsigned char pad204[0x20];
    f32 field224;
    unsigned char pad228[0x259];
    unsigned char field481;
} Fn_1_23500;

void fn_1_23500(Fn_1_23500 *self, f32 value) {
    Fn_1_23500_Rodata *table;
    f64 factor;
    f32 amount;
    f32 one;

    table = (Fn_1_23500_Rodata *)lbl_1_rodata_840;
    factor = value / (216.0);
    amount = factor * self->field08;
    fn_1_22F90(self, 1);
    if ((0.0f) != value) {
        lbl_8006E1F0(&self->field94, (0.0f), (0.0f), -amount);
        one = (1.0f);
        self->field224 = value / (200.0f);
        self->flags |= 0x400;
        self->field200 = one;
        self->field481 = 0x5a;
    }
    fn_1_8A190(self, (void *)(int)(1));
}
/* fzgx:end fn_1_23500 */

/* fzgx:begin fn_1_235C8 */
typedef struct Fn_1_235C8 {
    unsigned char *field00;
    unsigned char *field04;
    unsigned char data[0xb8];
} Fn_1_235C8;

void fn_1_235C8(Fn_1_235C8 *self) {
    if (self != 0) {
        memset(self, 0, 0xc0);
        self->field00 = &self->data[0];
        self->field04 = &self->data[0x5c];
    }
}
/* fzgx:end fn_1_235C8 */

/* fzgx:begin fn_1_23610 */
void fn_1_23610(void *self) {
    if (self != 0) {
        memset(self, 0, 0x194);
    }
}
/* fzgx:end fn_1_23610 */

/* fzgx:begin fn_1_23640 */
typedef struct Fn_1_23640 {
    unsigned char pad00[0x80];
    int field80;
    unsigned char pad84[0x0c];
    int *field90;
    int *field94;
    unsigned char pad98[0x04];
    int field9c;
    unsigned char padA0[0x18];
    int fieldb8;
    unsigned char padbc[0x0c];
    int fieldc8;
    unsigned char padcc[0x0c];
    int fieldd8;
    unsigned char pade0[0x40];
    int field11c;
    unsigned char pad120[0x3c];
    int field15c;
    unsigned char tail160[0x9c];
} Fn_1_23640;

void fn_1_23640(Fn_1_23640 *self, int value) {
    if (self != 0) {
        if (value != 0) {
            memset(self, 0, 0x1fc);
            self->field11c = -1;
            self->field15c = -1;
        } else {
            memset(self, 0, 0x117);
        }
        self->field80 = value;
        self->field90 = &self->fieldb8;
        self->field94 = &self->fieldc8;
        self->field9c = -1;
        self->fieldb8 = -1;
        self->fieldd8 = -1;
    }
}
/* fzgx:end fn_1_23640 */

/* fzgx:begin fn_1_236CC noprologue */
#include "types.h"
#include "psvec.h"
#include "game/main_rel/stcoli_types.h"
#include "game/vec3.h"

typedef struct Fn_1_236CC_Consts {
    u8 pad_0[0xC];
    f32 zero;       /* 0x0C */
    u8 pad_10[0x4];
    f32 one;        /* 0x14 */
    u8 pad_18[0xD8];
    f32 f200;       /* 0xF0 */
    f32 f0_02;      /* 0xF4 */
    f64 f0_01;      /* 0xF8 */
    f32 f0_04;      /* 0x100 */
} Fn_1_236CC_Consts;

typedef struct Fn_1_236CC_Words {
    s32 a[3];
} Fn_1_236CC_Words;

extern const Fn_1_236CC_Consts lbl_1_rodata_840;
extern double __fabs(double);

extern s32 fn_1_2BF8C(Body *);
extern void fn_1_289B4(Body *, s32 *, void *);
extern s32 fn_1_27E34(Body *);
extern f32 fn_1_253A4(Body *);
extern void fn_1_25870(Body *);
extern void fn_1_278B8(Body *, Part *, f32);
extern void fn_1_25480(Body *, void *, f32);
extern void fn_1_2A214(Body *);
extern void fn_1_29800(Body *);
extern void fn_1_290E8(Body *);
extern void fn_1_294D0(Body *);
extern void fn_1_28184(Body *);
extern void fn_1_28F08(Body *, Vec3f *, f32);
extern void fn_1_2B524(Body *);
extern void fn_1_27DE4(Body *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DB74(void *);

/* translation column of the current matrix in the locked cache */
static inline void fn_1_236CC_set_translate(f32 x, f32 y, f32 z) {
    *(f32 *)(0xE0000000 + 0x0C) = x;
    *(f32 *)(0xE0000000 + 0x1C) = y;
    *(f32 *)(0xE0000000 + 0x2C) = z;
}

#define BODY_VA0(b) ((Vec3f *)(b)->pad_A0)

void fn_1_236CC(Body *b) {
    const Fn_1_236CC_Consts *c;
    f32 rate;
    f32 speed;
    f32 inv;
    s32 i;
    Fn_1_236CC_Words vel;
    Fn_1_236CC_Words hit;
    s32 found;
    u8 n;
    f32 z, y, x;
    f32 zero;

    c = &lbl_1_rodata_840;
    if (fn_1_2BF8C(b) != 0) {
        b->f58C &= ~0x8;
        return;
    }
    b->f58C |= 0x8;
    fn_1_289B4(b, &found, &hit);
    if (fn_1_27E34(b) != 0 && found != 0) {
        *(Fn_1_236CC_Words *)((u8 *)b + 0x1BC) = hit;
    }
    vel = *(Fn_1_236CC_Words *)&b->vel;
    speed = fn_1_253A4(b);
    fn_1_25870(b);
    rate = BODY_VA0(b)->y;
    if (b->b481 != 0) {
        for (i = 0; i < 4; i++) {
            fn_1_278B8(b, &b->parts[i], rate);
        }
    }
    if (b->flags & 0x4) {
        b->f580 = b->f580 * c->f0_02;
    }
    if (__fabs(b->f1F8) > c->f0_01) {
        b->f580 = b->f580 * c->f0_04;
    }
    fn_1_25480(b, &vel, speed);
    fn_1_2A214(b);
    lbl_8006DBAC(b->mtxEC);
    fn_1_29800(b);
    fn_1_290E8(b);
    fn_1_294D0(b);
    inv = c->one / b->mass;
    psvec_scale_add(&b->pos, &b->vel, inv, &b->pos);
    fn_1_28184(b);
    /* Volatile view preserves the position read order before locked-cache writes. */
    x = *(volatile f32 *)&b->pos.x;
    y = b->pos.y;
    z = b->pos.z;
    fn_1_236CC_set_translate(x, y, z);
    fn_1_28F08(b, BODY_VA0(b), c->zero);
    zero = c->zero;
    fn_1_236CC_set_translate(zero, zero, zero);
    lbl_8006DB74(b->mtxEC);
    if (b->flags & 0x2000) {
        b->flags |= 0x80000;
    }
    if (b->flags & 0x8000) {
        b->flags &= ~0x180000;
    }
    if (b->flags & 0x400) {
        n = b->b481;
        if (n < 30) {
            if (n % 6 == 0) {
                fn_1_2B524(b);
            }
        } else if (n < 90) {
            zero = c->zero;
            BODY_VA0(b)->x = zero;
            BODY_VA0(b)->y = zero;
            BODY_VA0(b)->z = zero;
        }
    }
    if (*((u8 *)b + 0x216) != 0) {
        (*((u8 *)b + 0x216))--;
    }
    b->flags &= ~0x03803000;
    *(f32 *)((u8 *)b + 0x208) = c->f200;
    fn_1_27DE4(b);
}
/* fzgx:end fn_1_236CC */

/* fzgx:begin fn_1_239C4 noprologue */
#include "types.h"
#include "psvec.h"
#include "game/vec3.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 52.0f;
    s = 0.0625f;
    s = 45.0f;
    s = 0.0f;
    s = 1.7000000476837158f;
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.5f;
    d = 4503599627370496.0;
    s = 40.0f;
    s = 348.0f;
    s = 36.0f;
    s = 4.0f;
    s = 0.6000000238418579f;
    s = 5.0f;
    s = 0.05000000074505806f;
    s = 1000.0f;
    s = 8.0f;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 216.0;
    d = 2.0;
    s = 0.25f;
    s = 0.07000000029802322f;
    s = 0.20000000298023224f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.834999918937683f;
}
static const unsigned long fzgx_pool_table6[1] = {0xAE147AE1};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.0f;
    s = 1.7999999523162842f;
    s = 1.399999976158142f;
    s = 1.5f;
    s = 1.2000000476837158f;
    s = 2.299999952316284f;
    s = 0.4000000059604645f;
    s = 3.200000047683716f;
    s = 0.15000000596046448f;
    s = -0.25f;
    s = 0.1599999964237213f;
    s = 0.11999999731779099f;
    s = 0.07999999821186066f;
    s = 0.44999998807907104f;
    s = 0.699999988079071f;
}
static const unsigned long fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6000000238418579;
    s = 0.3100000023841858f;
    s = 0.029999999329447746f;
    s = 0.009999999776482582f;
    s = 700.0f;
    s = 1.7674999237060547f;
}
static const unsigned long fzgx_pool_table10[1] = {0xA3D70A3D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5699999928474426f;
}
static const unsigned long fzgx_pool_table12[4] = {0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.10000000149011612f;
    s = 200.0f;
    s = 0.019999999552965164f;
    d = 0.009999999776482582;
    s = 0.03999999910593033f;
    s = 0.800000011920929f;
    d = 13.88888888888889;
    s = 13.88888931274414f;
    s = 1.1920928955078125e-07f;
    s = 800.0f;
    s = 0.949999988079071f;
    s = 2.200000047683716f;
    s = -0.5f;
    s = 0.0020000000949949026f;
    s = 0.0010000000474974513f;
    s = 0.30000001192092896f;
}
static const unsigned long fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    d = 0.1;
}
#pragma section code_type ".text"

typedef struct Sig_fn_1_239C4_CarInfo850C4 {
    u8 pad0[0x115]; u8 rank; u8 pad116[2]; s32 lap;
} Sig_fn_1_239C4_CarInfo850C4;
typedef struct Sig_fn_1_239C4_Car850C4 {
    u32 flags; s16 id; u8 pad6[0x76]; Vec3 pos;
    u8 pad88[0x64]; Vec3 vecEC; u8 padF8[0x8c]; f32 f184;
    u8 pad188[0x314]; Sig_fn_1_239C4_CarInfo850C4 *info;
    u8 pad4A0[0xec]; u32 flags58C; u8 pad590[0x90];
} Sig_fn_1_239C4_Car850C4;
typedef struct { f32 x, y, z; } Sig_fn_1_2BBD0_Fn2BBD0_Vec;
typedef struct {
    u8 pad_0[4]; s16 id; u8 pad_6[0x7c-6]; Sig_fn_1_2BBD0_Fn2BBD0_Vec pos;
} Sig_fn_1_2BBD0_Fn2BBD0_Other;
typedef struct {
    u8 pad_0[0x7c]; Sig_fn_1_2BBD0_Fn2BBD0_Vec pos;
    u8 pad_88[0xec-0x88]; u8 mtx[0x4b4-0xec];
    Sig_fn_1_2BBD0_Fn2BBD0_Vec dir; u8 active, owner;
} Sig_fn_1_2BBD0_Fn2BBD0_Self;
typedef struct Sig_fn_1_2BD30_StcoliObj2BD30 {
    u8 pad0[8]; f32 scale; u8 padC[0x7c-0xc];
    f32 posX, posY, posZ; u8 pad88[0x94-0x88];
    f32 velX, velY, velZ; u8 padA0[0xec-0xa0]; Vec3 rot;
    u8 padF8[0x1bc-0xf8]; u8 ref[0x10];
} Sig_fn_1_2BD30_StcoliObj2BD30;
typedef struct Sig_fn_1_2BD30_StcoliOut2BD30 {
    u8 pad0[0xc]; Vec3 dir; Vec3 axis; u8 pad24[0x30-0x24];
    f32 speed, depth;
} Sig_fn_1_2BD30_StcoliOut2BD30;
typedef struct Sig_fn_1_2A41C_Fn_1_2A41C {
    u32 flags; u8 pad04[0x190]; u16 value194;
} Sig_fn_1_2A41C_Fn_1_2A41C;
typedef struct Sig_fn_1_24F10_Fn_1_24F10 {
    int flags; u8 pad04[0x2c]; f32 field30; u8 pad34[0x150];
    f32 field184; u8 pad188[0x8c]; u16 field214; u8 pad216[0xe];
    f32 field224; u8 pad228[0x284]; f32 field4ac;
    u8 pad4b0[0xe3]; u8 field593; u8 pad594[0x46]; u16 field5da;
} Sig_fn_1_24F10_Fn_1_24F10;
typedef struct Sig_fn_1_2A318_Fn_1_2A318 {
    u8 pad000[0x184]; f32 field184; u8 pad188[2]; u8 field18a;
    u8 pad18b[0x85]; u16 field210; u8 field212; u8 pad213[0x26f];
    u8 field482; u8 pad483[0x10f]; u8 field592;
    u8 pad593[0x47]; u16 field5da;
} Sig_fn_1_2A318_Fn_1_2A318;
struct fn_1_239C4_Arg0 {
    u32 flags; s16 id; s16 type; f32 scale; u8 pad0C[0x70];
    Vec3 pos; u8 pad88[0xc]; Vec3 vel; u8 padA0[0x4c];
    Vec3 vecEC; u8 padF8[0x3d0]; Vec3 prevPos; u8 pad4D4[0x2c];
    Vec3 impulse; u8 pad50C[0x80]; u32 unk_58C;
};
struct fn_1_239C4_lbl_1_rodata_840 {
    u8 pad_0[0xc]; f32 unk_C; u8 pad_10[4];
    f32 unk_14, unk_18, unk_1C; u8 pad_20[0x30]; f64 unk_50;
    u8 pad_58[0x20]; f32 unk_78; u8 pad_7C[8];
    f32 unk_84, unk_88; u8 pad_8C[0x24]; f32 unk_B0;
    u8 pad_B4[0x14]; f32 unk_C8; u8 pad_CC[0x38]; f32 unk_104;
    f64 unk_108; f32 unk_110, unk_114, unk_118, unk_11C;
    f32 unk_120, unk_124, unk_128, unk_12C, unk_130;
    u8 pad_134[4]; f64 unk_138, unk_140;
};
#define lbl_1_rodata_84C ((f32)(0.0f))
#define lbl_1_rodata_854 ((f32)(1.0f))
#define lbl_1_rodata_854__fzgx_offset_4 ((f32)(0.100000001f))
#define lbl_1_rodata_85C ((f32)(0.5f))
#define lbl_1_rodata_860__fzgx_offset_30 ((f64)(216.0))
#define lbl_1_rodata_860__fzgx_offset_58 ((f32)(2.0f))
#define lbl_1_rodata_860__fzgx_offset_64 ((f32)(1.5f))
#define lbl_1_rodata_860__fzgx_offset_68 ((f32)(1.20000005f))
#define lbl_1_rodata_860__fzgx_offset_90 ((f32)(0.699999988f))
#define lbl_1_rodata_860__fzgx_offset_A8 ((f32)(0.00999999978f))
#define lbl_1_rodata_92C__fzgx_offset_18 ((f32)(0.800000012f))
#define lbl_1_rodata_92C__fzgx_offset_1C ((f64)(13.888888888888889))
#define lbl_1_rodata_92C__fzgx_offset_24 ((f32)(13.8888893f))
#define lbl_1_rodata_954 ((f32)(1.1920929e-07f))
#define lbl_1_rodata_954__fzgx_offset_4 ((f32)(800.0f))
#define lbl_1_rodata_954__fzgx_offset_8 ((f32)(0.949999988f))
#define lbl_1_rodata_954__fzgx_offset_C ((f32)(2.20000005f))
#define lbl_1_rodata_954__fzgx_offset_10 ((f32)(-0.5f))
#define lbl_1_rodata_954__fzgx_offset_14 ((f32)(0.00200000009f))
#define lbl_1_rodata_954__fzgx_offset_18 ((f32)(0.00100000005f))
#define lbl_1_rodata_954__fzgx_offset_1C ((f32)(0.300000012f))
#define lbl_1_rodata_954__fzgx_offset_24 ((f64)(0.40000000000000002))
#define lbl_1_rodata_954__fzgx_offset_2C ((f64)(0.10000000000000001))
extern const f32 lbl_1_rodata_3508[4];
extern void fn_1_2BBD0(Sig_fn_1_2BBD0_Fn2BBD0_Self *, Sig_fn_1_2BBD0_Fn2BBD0_Other *, f32);
extern s32 fn_1_251F8(void *, void *, void *, void *, void *, void *, f32, f32);
extern f32 fn_1_2BD30(Sig_fn_1_2BD30_StcoliObj2BD30 *, Sig_fn_1_2BD30_StcoliOut2BD30 *, Vec3 *);
extern f32 fn_1_2A41C(Sig_fn_1_2A41C_Fn_1_2A41C *, int);
extern int fn_1_24F10(Sig_fn_1_24F10_Fn_1_24F10 *, f32);
extern void fn_1_2A318(Sig_fn_1_2A318_Fn_1_2A318 *);
extern void fn_1_F7338(int, void *, void *);
extern void fn_1_A2D84(u32);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006D5F0(void *, void *, f32);
extern void *lbl_8006D5A4(void *, void *, void *, f32);
extern f32 lbl_8006D668(void *);
extern f32 lbl_8006D6FC(void *, void *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBAC(Vec3 *);
extern void fn_8006E2B0(void *, Vec3 *);
extern void lbl_8006DB30(void);
#define F(p,o) (*(f32 *)((u8 *)(p)+(o)))
#define U(p,o) (*(u32 *)((u8 *)(p)+(o)))
#define H(p,o) (*(s16 *)((u8 *)(p)+(o)))
#define B(p,o) (*(u8 *)((u8 *)(p)+(o)))
#define S(p,o) (*(s8 *)((u8 *)(p)+(o)))
#define V(p,o) ((Vec3 *)((u8 *)(p)+(o)))
#define CLEAR_PAIR() do { U(arg0,0x514) &= ~(0x80000000U >> H(arg1,4)); U(arg1,0x514) &= ~(0x80000000U >> H(arg0,4)); } while (0)
#pragma fp_contract on
static inline f32 length239C4(Vec3 *p) {
    f32 x = p->x, y = p->y, z = p->z;
    f32 v1 = x*x;
    v1 = y*y+v1;
    v1 = z*z+v1;
    return lbl_8006D0B4(v1);
}
#define LENGTH(p) length239C4(p)
static inline f32 distance239C4(Vec3 *a, Vec3 *b) {
    f32 x = a->x - b->x;
    f32 y = a->y;
    f32 z = a->z;
    y -= b->y;
    z -= b->z;
    x = x*x;
    x = y*y + x;
    x = z*z + x;
    return lbl_8006D0B4(x);
}
#define DIST(a,b) distance239C4(a,b)
s32 fn_1_239C4(struct fn_1_239C4_Arg0 *arg0, struct fn_1_239C4_Arg0 *arg1) {
    const struct fn_1_239C4_lbl_1_rodata_840 *p_lbl_1_rodata_840;
    f32 v84, v85, v88, v89, v64, v65, v2, v6, v58, v59, v7, v3, v1;
    f32 v10, v11;
    f32 v5, v9, v41, v54;
    int v34, v96, v94, v95, v98, v99;
    Sig_fn_1_2BD30_StcoliOut2BD30 loc_F0;
    Sig_fn_1_2BD30_StcoliOut2BD30 loc_B8;
    Vec3 loc_AC, loc_A0, loc_94, loc_88, loc_7C, loc_70, loc_64;
    Vec3 loc_58, loc_4C, loc_40, loc_34, loc_28, loc_1C, loc_10;
    f32 loc_C;
    s32 loc_8;
    
    if ((arg0->unk_58C | arg1->unk_58C) & 0x10) return 0;
    if (U(arg0,0) & 0x20000000) {
        if (H(arg0,6) >= 2) v5 = lbl_1_rodata_854;
        else v5 = lbl_1_rodata_3508[H(arg0,6)*2+1];
        v10 = F(arg0,0x510)*v5;
        v10 = lbl_1_rodata_92C__fzgx_offset_18 * v10;
        v2 = F(arg0,8);
    } else { v10 = F(arg0,0x510); v2 = F(arg0,8); }
    if (U(arg1,0) & 0x20000000) {
        if (H(arg1,6) >= 2) v9 = lbl_1_rodata_854;
        else v9 = lbl_1_rodata_3508[H(arg1,6)*2+1];
        v11 = F(arg1,0x510)*v9;
        v11 = lbl_1_rodata_92C__fzgx_offset_18 * v11;
        v6 = F(arg1,8);
    } else { v11 = F(arg1,0x510); v6 = F(arg1,8); }
    v1 = DIST((&arg0->pos), (&arg1->pos));
    if (v1 > v11 + (v10 + (F(arg0,0x17c)/lbl_1_rodata_860__fzgx_offset_30 + F(arg1,0x17c)/lbl_1_rodata_860__fzgx_offset_30))) {
        CLEAR_PAIR();
        return 0;
    }
    fn_1_2BBD0((Sig_fn_1_2BBD0_Fn2BBD0_Self *)arg0,(Sig_fn_1_2BBD0_Fn2BBD0_Other *)arg1,v1);
    fn_1_2BBD0((Sig_fn_1_2BBD0_Fn2BBD0_Self *)arg1,(Sig_fn_1_2BBD0_Fn2BBD0_Other *)arg0,v1);
    v1 = DIST((&arg0->prevPos),(&arg0->pos));
    if (v1 > lbl_1_rodata_92C__fzgx_offset_1C) {
        psvec_sub((&arg0->pos), (&arg0->prevPos), &loc_94);
        lbl_8006D5F0(&loc_94,&loc_94,lbl_1_rodata_92C__fzgx_offset_24);
        psvec_add((&arg0->pos), &loc_94, &loc_94);
        lbl_8006D5F0((&arg0->vel), &loc_7C, (f32)(lbl_1_rodata_92C__fzgx_offset_1C*v2));
    } else { loc_94 = *(&arg0->prevPos); loc_7C = *(&arg0->vel); }
    v1 = DIST((&arg1->prevPos),(&arg1->pos));
    if (v1 > lbl_1_rodata_92C__fzgx_offset_1C) {
        psvec_sub((&arg1->pos), (&arg1->prevPos), &loc_88);
        lbl_8006D5F0(&loc_88,&loc_88,lbl_1_rodata_92C__fzgx_offset_24);
        psvec_add((&arg1->pos), &loc_88, &loc_88);
        lbl_8006D5F0((&arg1->vel), &loc_70, (f32)(lbl_1_rodata_92C__fzgx_offset_1C*v6));
    } else { loc_88 = *(&arg1->prevPos); loc_70 = *(&arg1->vel); }
    if (!(s32)fn_1_251F8(&loc_94,(&arg0->pos),&loc_88,(&arg1->pos),&loc_C,&loc_8,v10,v11)) {
        if (!loc_8) { CLEAR_PAIR(); }
        return 0;
    }
    v3 = v10+v11;
    loc_C = lbl_1_rodata_854-loc_C;
    lbl_8006D5A4(&loc_94,(&arg0->pos),&loc_AC,loc_C);
    lbl_8006D5A4(&loc_88,(&arg1->pos),&loc_A0,loc_C);
    v7 = DIST(&loc_AC,&loc_A0);
    v34 = 0;
    if (v7 < v3 && v7 > lbl_1_rodata_954) v34 = 1;
    if (v34) {
        if (__rlwnm(U(arg0,0x514), (H(arg1,4)+1)&31, 31, 31) || __rlwnm(U(arg1,0x514), (H(arg0,4)+1)&31, 31, 31)) v34 = 0;
    } else { CLEAR_PAIR(); }
    if (v34) {
        psvec_sub(&loc_A0,&loc_AC,&loc_64);
        lbl_8006D668(&loc_64);
        {
            f32 offsetB = lbl_1_rodata_85C*((lbl_1_rodata_860__fzgx_offset_A8+v3)-v7);
            v41 = -offsetB;
            psvec_scale_add(&loc_AC,&loc_64,v41,(&arg0->pos));
            psvec_scale_add(&loc_A0,&loc_64,offsetB,(&arg1->pos));
        }
        psvec_add((&arg0->pos),(&arg1->pos),&loc_40);
        psvec_scale(&loc_40,lbl_1_rodata_85C,&loc_40);
        v3 = fn_1_2BD30((Sig_fn_1_2BD30_StcoliObj2BD30 *)arg0,&loc_F0,&loc_40);
        v1 = fn_1_2BD30((Sig_fn_1_2BD30_StcoliObj2BD30 *)arg1,&loc_B8,&loc_40);
        if (v3 > v1) loc_34 = loc_F0.axis;
        else { loc_34.x = -loc_B8.axis.x; loc_34.y = -loc_B8.axis.y; loc_34.z = -loc_B8.axis.z; }
        v3 = LENGTH(&loc_7C);
        if (v3 > lbl_1_rodata_954) v7 = v3*(lbl_8006D6FC(&loc_34,&loc_7C)/v2);
        else v7 = lbl_1_rodata_84C;
        v3 = LENGTH(&loc_70);
        if (v3 > lbl_1_rodata_954) v1 = v3*(lbl_8006D6FC(&loc_34,&loc_70)/v6);
        else v1 = lbl_1_rodata_84C;
        v54 = (lbl_1_rodata_860__fzgx_offset_58*(v7-v1))/(v2+v6);
        F(arg0,0x224) += (f32)(lbl_1_rodata_954__fzgx_offset_4*(loc_F0.depth*v54));
        F(arg1,0x224) += (f32)(lbl_1_rodata_954__fzgx_offset_4*(loc_B8.depth*v54));
        v1 = F(arg0,0x224);
        if (v1 < lbl_1_rodata_84C) F(arg0,0x224) = lbl_1_rodata_84C;
        v1 = F(arg1,0x224);
        if (v1 < lbl_1_rodata_84C) F(arg1,0x224) = lbl_1_rodata_84C;
        {
        v7 = v2*v54;
        v3 = -v6*v54;
        v58 = fn_1_2A41C((Sig_fn_1_2A41C_Fn_1_2A41C *)arg0,U(arg1,0)&0x200);
        v59 = fn_1_2A41C((Sig_fn_1_2A41C_Fn_1_2A41C *)arg1,U(arg0,0)&0x200);
        if (U(arg0,0)&0x80) { v58 *= lbl_1_rodata_860__fzgx_offset_64; v59 *= lbl_1_rodata_860__fzgx_offset_68; }
        if (U(arg1,0)&0x80) { v59 *= lbl_1_rodata_860__fzgx_offset_64; v58 *= lbl_1_rodata_860__fzgx_offset_68; }
        v64 = v59*(v3*v2);
        v65 = v58*(v7*v6);
        }
        psvec_scale(&loc_64,v64,&loc_58);
        psvec_scale(&loc_64,v65,&loc_4C);
        loc_28.x = lbl_1_rodata_954__fzgx_offset_8*(loc_58.x*F(arg0,0x1bc));
        loc_28.y = lbl_1_rodata_954__fzgx_offset_8*(loc_58.y*F(arg0,0x1c0));
        loc_28.z = lbl_1_rodata_954__fzgx_offset_8*(loc_58.z*F(arg0,0x1c4));
        psvec_sub(&loc_58,&loc_28,&loc_58);
        loc_28.x = lbl_1_rodata_954__fzgx_offset_8*(loc_4C.x*F(arg1,0x1bc));
        loc_28.y = lbl_1_rodata_954__fzgx_offset_8*(loc_4C.y*F(arg1,0x1c0));
        loc_28.z = lbl_1_rodata_954__fzgx_offset_8*(loc_4C.z*F(arg1,0x1c4));
        psvec_sub(&loc_4C,&loc_28,&loc_4C);
        *(&arg0->impulse) = loc_58; *(&arg1->impulse) = loc_4C;
        if ((U(arg0,0)|U(arg1,0))&0x20008) v84 = v85 = lbl_1_rodata_860__fzgx_offset_64;
        else v84 = v85 = lbl_1_rodata_954__fzgx_offset_C;
        if (U(arg0,0)&0x20000000) v84 = lbl_1_rodata_854;
        if (U(arg1,0)&0x20000000) v85 = lbl_1_rodata_854;
        psvec_scale(&loc_58,v84,&loc_28);
        if (LENGTH((&arg0->vel)) > lbl_1_rodata_854__fzgx_offset_4 &&
            LENGTH(&loc_58) > lbl_1_rodata_854__fzgx_offset_4) {
            v88 = lbl_8006D6FC((&arg0->vel),&loc_58);
            if (v88 > lbl_1_rodata_84C) v88 = lbl_1_rodata_84C;
            v1 = lbl_1_rodata_860__fzgx_offset_90*v88;
            v88 = lbl_1_rodata_854 + v1;
            psvec_scale(&loc_28,v88,&loc_28);
        }
        psvec_add(&loc_28,&loc_7C,(&arg0->vel));
        psvec_scale(&loc_4C,v85,&loc_28);
        if (LENGTH((&arg1->vel)) > lbl_1_rodata_854__fzgx_offset_4 &&
            LENGTH(&loc_4C) > lbl_1_rodata_854__fzgx_offset_4) {
            v89 = lbl_8006D6FC((&arg1->vel),&loc_4C);
            if (v89 > lbl_1_rodata_84C) v89 = lbl_1_rodata_84C;
            v1 = lbl_1_rodata_860__fzgx_offset_90*v89;
            v89 = lbl_1_rodata_854 + v1;
            psvec_scale(&loc_28,v89,&loc_28);
        }
        psvec_add(&loc_28,&loc_70,(&arg1->vel));
        lbl_8006DAEC();
        v94 = 0;
        v95 = 0;
        if ((U(arg0,0)&0x200) && (U(arg1,0)&0x200)) v96 = 1; else v96 = 0;
        v98 = v99 = 1;
        if (!(U(arg0,0)&0x200)) {
            if ((U(arg1,0)&0x200) && (U(arg0,0)&0x20008) && !(U(arg1,0)&0x20008)) v98 = 0;
        } else {
            if (!(U(arg1,0)&0x200) && (U(arg1,0)&0x20008) && !(U(arg0,0)&0x20008)) v99 = 0;
        }
        lbl_8006DBAC((&arg0->vecEC));
        psvec_scale(&loc_64,lbl_1_rodata_954__fzgx_offset_10,&loc_1C);
        fn_8006E2B0(&loc_1C,&loc_1C);
        fn_8006E2B0(&loc_58,&loc_10);
        F(arg0,0xc4) += loc_10.x;
        F(arg0,0xc8) += loc_10.z;
{
        f32 damage0;
        damage0 = (v59*(lbl_1_rodata_954__fzgx_offset_14*LENGTH(&loc_58)))/v58;
        if (v96) damage0 *= lbl_1_rodata_954__fzgx_offset_18;
        if (U(arg1,0)&0x80) damage0 *= lbl_1_rodata_954__fzgx_offset_1C;
        if (v98 && !B(arg0,0x4c5) && fn_1_24F10((Sig_fn_1_24F10_Fn_1_24F10 *)arg0,damage0)) v94 = 1;
        fn_1_F7338(S(arg0,0x474),(void *)4,(void *)12);
        lbl_8006DBAC((&arg1->vecEC));
        psvec_scale(&loc_64,lbl_1_rodata_85C,&loc_1C);
        fn_8006E2B0(&loc_1C,&loc_1C);
        fn_8006E2B0(&loc_4C,&loc_10);
        F(arg1,0xc4) += loc_10.x;
        F(arg1,0xc8) += loc_10.z;
        v1 = (v58*(lbl_1_rodata_954__fzgx_offset_14*LENGTH(&loc_4C)))/v59;
        if (v96) v1 *= lbl_1_rodata_954__fzgx_offset_18;
        if (U(arg0,0)&0x80) v1 *= lbl_1_rodata_954__fzgx_offset_1C;
        if (v99 && !B(arg1,0x4c5) && fn_1_24F10((Sig_fn_1_24F10_Fn_1_24F10 *)arg1,v1)) v95 = 1;
        if (v94) {
            fn_1_2A318((Sig_fn_1_2A318_Fn_1_2A318 *)arg1);
            if (S(arg1,0x475) != -1 && !(U(arg1,0)&0x4000200)) fn_1_A2D84(0xa9092100);
        }
        if (v95) {
            fn_1_2A318((Sig_fn_1_2A318_Fn_1_2A318 *)arg0);
            if (S(arg0,0x475) != -1 && !(U(arg0,0)&0x4000200)) fn_1_A2D84(0xa9092100);
        }
        fn_1_F7338(S(arg1,0x474),(void *)4,(void *)12);
        v1 = damage0+v1;
        }
        if (v1 > lbl_1_rodata_954__fzgx_offset_24) {
            fn_1_F7338(S(arg0,0x474),(void *)2,(void *)9);
            fn_1_F7338(S(arg1,0x474),(void *)2,(void *)9);
        } else if (v1 > lbl_1_rodata_954__fzgx_offset_2C) {
            fn_1_F7338(S(arg0,0x474),(void *)3,(void *)9);
            fn_1_F7338(S(arg1,0x474),(void *)3,(void *)9);
        }
        if (U(arg0,0)&0x80) F(arg0,0x184) = lbl_1_rodata_84C;
        if (U(arg1,0)&0x80) F(arg1,0x184) = lbl_1_rodata_84C;
        lbl_8006DB30();
        U(arg0,0) |= 0x2000400; U(arg1,0) |= 0x2000400;
        return 1;
    }
    return 0;
}
/* fzgx:end fn_1_239C4 */

/* fzgx:begin fn_1_248C0 */
typedef struct Fn_1_248C0 {
    u32 unk_00;
    unsigned char pad04[0x471];
    signed char unk_475;
    unsigned char pad476[0x3d];
    unsigned char unk_4b3;
} Fn_1_248C0;

// Updates the collision state and reports whether the current flags trigger a response.
int fn_1_248C0(Fn_1_248C0 *self, int arg) {
    int result;
    int test;

    result = 0;
    if (self->unk_00 & 0x800) {
        if (self->unk_00 & 1) {
            result = 1;
        } else if (self->unk_00 & 0x10000) {
            result = 1;
        }
        if (!(self->unk_00 & 0x10000) && self->unk_4b3 == 0) {
            if (*(s16 *)&lbl_1_bss_960 == 9 && lbl_1_bss_9C == 5) {
            } else if (lbl_1_bss_9C == 6) {
            } else if (self->unk_475 != -1 && !(self->unk_00 & 0x04000200)) {
                fn_1_A2D84(0xA9072100);
            }
            self->unk_4b3 = 1;
        }
    } else {
        test = self->unk_00 & 0x80;
        if (test && self->unk_4b3 == 0 && !(self->unk_00 & 0x10000)) {
            if (self->unk_475 != -1 && !(self->unk_00 & 0x04000200)) {
                fn_1_A2D84(0xA9072200);
            }
            self->unk_4b3 = 1;
        }
        if ((self->unk_00 & 1) && test) {
            if ((self->unk_00 & 0x02810000) || arg) {
                result = 1;
            }
        }
    }
    if ((self->unk_00 & 0x40000000) && (self->unk_00 & 1)) {
        result = 1;
    }
    if (self->unk_00 & 0x10000000) {
        result = 0;
    }
    return result;
}
/* fzgx:end fn_1_248C0 */

/* fzgx:begin fn_1_24A4C noprologue */
#include "types.h"
#include "psvec.h"

typedef struct {
    f32 x, y, z;
} fn_1_24A4C_Vec;

typedef struct {
    u8 pad00[8];
    f32 f08;
    f32 f0C;
    f32 f10;
    fn_1_24A4C_Vec prev;
    fn_1_24A4C_Vec cur;
    u8 pad2C[0x44 - 0x2c];
    f32 f44;
    f32 f48;
    u8 pad4C[0x5c - 0x4c];
} fn_1_24A4C_Wheel;

typedef struct {
    u8 pad00[0xc];
    fn_1_24A4C_Vec prev;
    fn_1_24A4C_Vec cur;
    u8 pad24[0x30 - 0x24];
} fn_1_24A4C_Spring;

typedef struct {
    u32 flags;
    s16 id;
    u8 pad06[2];
    f32 mass;
    u8 pad0c[0x7c - 0xc];
    fn_1_24A4C_Vec pos;
    fn_1_24A4C_Vec prevPos;
    fn_1_24A4C_Vec vel;
    u8 padA0[0xd8 - 0xa0];
    f32 maxSpeed;
    u8 padDC[0xec - 0xdc];
    u8 mtx[0x17c - 0xec];
    f32 speed;
    u8 pad180[0x214 - 0x180];
    u16 timer214;
    u8 pad216[2];
    u32 flags218;
    u8 pad21C[0x244 - 0x21c];
    fn_1_24A4C_Wheel wheel[4];
    fn_1_24A4C_Spring spring[4];
    u8 pad474;
    s8 s475;
    u8 pad476[0x4b4 - 0x476];
    fn_1_24A4C_Vec v4b4;
    u8 u4c0;
    u8 pad4c1[0x4e0 - 0x4c1];
    u16 timer4e0;
    u8 pad4e2[0x58c - 0x4e2];
    u32 flags58c;
} fn_1_24A4C_Car;

typedef struct {
    u8 pad[0x390];
    u32 flags390;
} fn_1_24A4C_Other;

typedef struct {
    u8 pad[0x24];
    f32 *p24;
} fn_1_24A4C_Course;

struct fn_1_24A4C_lbl_1_rodata_840 {
    u8 pad_0[0xC];
    f32 unk_C;
    u8 pad_10[0x10];
    f64 unk_20;
    u8 pad_28[0x28];
    f64 unk_50;
    u8 pad_58[0x98];
    f32 unk_F0;
    u8 pad_F4[0x28];
    f32 unk_11C;
    u8 pad_120[0x28];
    f32 unk_148;
    f32 unk_14C;
    f64 unk_150;
    f32 unk_158;
    f32 unk_15C;
    f32 unk_160;
    f32 unk_164;
    f32 unk_168;
    f32 unk_16C;
    f32 unk_170;
    f32 unk_174;
};

extern struct fn_1_24A4C_lbl_1_rodata_840 lbl_1_rodata_840;
extern fn_1_24A4C_Course *lbl_1_bss_3BE0[];
extern s32 lbl_801A66C8[];

extern f32 lbl_8006D0B4(f32);
extern void lbl_8006DBAC(void *);
extern void lbl_8006E1D8(void *, f32, f32, f32);
extern void lbl_8006E1B0(void *, void *);
extern int fn_1_248C0(fn_1_24A4C_Car *, int);
extern int fn_1_24F10(fn_1_24A4C_Car *, f32);
extern void fn_1_25004(fn_1_24A4C_Car *);
extern void fn_1_29A0C(fn_1_24A4C_Car *);
extern void fn_1_2B684(fn_1_24A4C_Car *);
extern void fn_1_2BA48(fn_1_24A4C_Car *);
extern fn_1_24A4C_Other *fn_1_868C0(s8);
extern void fn_1_A2D84(u32);

/* the matrix in the locked cache */
#define LC_MTX ((f32 (*)[4])0xE0000000)

/* parameters declared z, y, x: retail holds x in f2, y in f1, z in f0 */
static inline void fn_1_24A4C_set_translate(f32 z, f32 y, f32 x) {
    LC_MTX[0][3] = x;
    LC_MTX[1][3] = y;
    LC_MTX[2][3] = z;
}

static inline f32 fn_1_24A4C_speed(f64 scale, f32 magnitude, f32 mass) { return scale * (magnitude / mass); }
static inline f64 fn_1_24A4C_timer(f64 bias, f64 value, f64 add) { return add + (value - bias); }
static inline f64 fn_1_24A4C_read_pointer(struct fn_1_24A4C_lbl_1_rodata_840 * owner) { return owner->unk_20; }
#pragma opt_dead_assignments off
#pragma opt_common_subs off
void fn_1_24A4C(fn_1_24A4C_Car *car) {
    f32 fzgx_live;
    struct fn_1_24A4C_lbl_1_rodata_840 *k = &lbl_1_rodata_840;
    s32 i;
    s32 contact;
    s32 below;
    f32 speed;
    f32 y;
    f32 zero;
    f32 vx, vy, vz;
    f32 sq;
    u32 flags;
    fn_1_24A4C_Other *other;
    union {
        f64 d;
        u32 w[2];
    } cvt;

    if (!(car->flags58c & 8)) {
        return;
    }
    lbl_8006DBAC(car->mtx);
    fn_1_24A4C_set_translate(car->pos.z, car->pos.y, car->pos.x);
    if (car->timer4e0 != 0) {
        fn_1_2BA48(car);
    }
    if ((car->flags218 >> 25) & 1) {
        fn_1_24F10(car, k->unk_158);
        contact = 1;
        if ((car->flags58c & 0x200) && (car->flags & 0x80)) {
            fn_1_25004(car);
        }
    }
    lbl_8006DBAC(car->mtx);
    fn_1_24A4C_set_translate(car->pos.z, car->pos.y, car->pos.x);
    for (i = 0; i < 4; i++) {
        fn_1_24A4C_Wheel *w = &car->wheel[i];
        fn_1_24A4C_Spring *s = &car->spring[i];
        w->prev = w->cur;
        lbl_8006E1D8(&w->cur, w->f08, w->f0C + w->f44 - w->f48, w->f10);
        s->prev = s->cur;
        lbl_8006E1B0(s, &s->cur);
    }
    if (!(car->flags58c & 0x10)) {
        y = car->pos.y;
        if (y < k->unk_15C || lbl_1_bss_3BE0[0]->p24[0] - k->unk_160 > y) {
            fn_1_25004(car);
        }
    }
    if (car->pos.y < k->unk_164) {
        car->pos.y = k->unk_164;
        zero = k->unk_C;
        car->vel.x = zero;
        car->vel.y = zero;
        car->vel.z = zero;
    }
    fn_1_29A0C(car);
    if (car->flags & 0x8000) {
        car->speed = k->unk_C;
    } else {
        vx = car->vel.x;
        vy = car->vel.y;
        vz = car->vel.z;
        sq = vx * vx;
        sq += vy * vy;
        sq += vz * vz;
        sq = lbl_8006D0B4(sq);
        car->speed = fn_1_24A4C_speed(k->unk_50, sq, car->mass);
        fzgx_live = car->speed;
        speed = fzgx_live;
        if (speed > car->maxSpeed) {
            below = speed < k->unk_148 + car->maxSpeed;
            below |= speed < k->unk_14C;
            below &= !(car->flags & 0x3800000);
            if (below) {
                car->maxSpeed = speed;
            }
        }
    }
    if (fn_1_248C0(car, 1) != 0) {
        if (car->timer214 == 0) {
            car->timer214 = 180;
            if ((car->flags & 0x80) && ((car->flags & 0x2800000) || contact != 0)) {
                /* (f64)timer214, spelled out because the 2^52 bias is the pooled k->unk_20 */
                cvt.w[1] = car->timer214;
                cvt.w[0] = 0x43300000;
                {
                    f64 converted = cvt.d - fn_1_24A4C_read_pointer(k);
                    car->timer214 = converted + k->unk_150;
                }
            }
            if (car->flags & 0x40000000) {
                car->timer214 = 180;
            }
        }
    } else {
        flags = car->flags;
        if (!(flags & 0x08000201)) {
            if ((flags & 0x80) && car->timer4e0 == 0) {
                fn_1_2B684(car);
            }
        } else if ((flags & 0x280) == 0x280) {
            fzgx_live = car->speed;
            speed = fzgx_live;
            if (speed < k->unk_168) {
                zero = k->unk_C;
                car->vel.x = zero;
                car->vel.y = zero;
                car->vel.z = zero;
                car->pos = car->prevPos;
                car->flags = car->flags | 0x08000000;
                other = fn_1_868C0(car->id);
                if (!(car->flags58c & 0x80)) {
                    car->flags58c = car->flags58c | 0x100;
                    other->flags390 = other->flags390 | 0x200000;
                }
                car->flags58c = car->flags58c | 0x80;
                if (lbl_801A66C8[0] + car->id == 0) {
                    fn_1_A2D84(0xA9092E00);
                    if (car->s475 != -1 && !(car->flags & 0x04000200)) {
                        fn_1_A2D84(0xA9091200);
                    }
                }
            } else if (speed < k->unk_16C) {
                psvec_scale(&car->vel, k->unk_11C, &car->vel);
            } else if (speed < k->unk_170) {
                psvec_scale(&car->vel, k->unk_174, &car->vel);
            }
        }
    }
    if (car->u4c0 == 0 && !(car->flags & 0x880)) {
        vx = car->v4b4.x;
        vy = car->v4b4.y;
        vz = car->v4b4.z;
        sq = vx * vx;
        sq += vy * vy;
        sq += vz * vz;
        if (lbl_8006D0B4(sq) < k->unk_F0) {
            car->u4c0 = 60;
        }
    }
}
#pragma opt_common_subs reset

#pragma opt_dead_assignments reset
/* fzgx:end fn_1_24A4C */

/* fzgx:begin fn_1_24F10 */
typedef struct Fn_1_24F10 {
    int flags;
    unsigned char pad04[0x2c];
    f32 field30;
    unsigned char pad34[0x150];
    f32 field184;
    unsigned char pad188[0x8c];
    u16 field214;
    unsigned char pad216[0x0e];
    f32 field224;
    unsigned char pad228[0x284];
    f32 field4ac;
    unsigned char pad4b0[0xe3];
    u8 field593;
    unsigned char pad594[0x46];
    u16 field5da;
} Fn_1_24F10;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 52.0f;
    s = 0.0625f;
    s = 45.0f;
    s = 0.0f;
    s = 1.7000000476837158f;
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.5f;
    d = 4503599627370496.0;
    s = 40.0f;
    s = 348.0f;
    s = 36.0f;
    s = 4.0f;
    s = 0.6000000238418579f;
    s = 5.0f;
    s = 0.05000000074505806f;
    s = 1000.0f;
    s = 8.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 216.0;
    d = 2.0;
    s = 0.25f;
    s = 0.07000000029802322f;
    s = 0.20000000298023224f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.834999918937683f;
}
static const u32 fzgx_pool_table6[1] = {0xAE147AE1};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.0f;
    s = 1.7999999523162842f;
    s = 1.399999976158142f;
    s = 1.5f;
    s = 1.2000000476837158f;
    s = 2.299999952316284f;
    s = 0.4000000059604645f;
    s = 3.200000047683716f;
    s = 0.15000000596046448f;
    s = -0.25f;
    s = 0.1599999964237213f;
    s = 0.11999999731779099f;
    s = 0.07999999821186066f;
    s = 0.44999998807907104f;
    s = 0.699999988079071f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6000000238418579;
    s = 0.3100000023841858f;
    s = 0.029999999329447746f;
    s = 0.009999999776482582f;
    s = 700.0f;
    s = 1.7674999237060547f;
}
static const u32 fzgx_pool_table10[1] = {0xA3D70A3D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5699999928474426f;
}
static const u32 fzgx_pool_table12[4] = {0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.10000000149011612f;
    s = 200.0f;
    s = 0.019999999552965164f;
    d = 0.009999999776482582;
    s = 0.03999999910593033f;
    s = 0.800000011920929f;
    d = 13.88888888888889;
    s = 13.88888931274414f;
}
static const u32 fzgx_pool_table14[1] = {0x34000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 0.949999988079071f;
    s = 2.200000047683716f;
    s = -0.5f;
    s = 0.0020000000949949026f;
    s = 0.0010000000474974513f;
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    d = 0.1;
    s = 80.0f;
    s = 1700.0f;
    d = 90.0;
    s = 0.3333333432674408f;
    s = -5000.0f;
    s = 900.0f;
    s = -10000.0f;
    s = 10.0f;
    s = 100.0f;
    s = 400.0f;
    s = 0.9900000095367432f;
    s = 20.0f;
    s = 1.0099999904632568f;
}
#pragma section code_type ".text"
int fn_1_24F10(Fn_1_24F10 *self, f32 value) {
    f32 amount;
    f32 dist;
    int result;

    if (self->field214 != 0 || self->field593 != 0) {
        return 0;
    }

    amount = value * self->field30;
    if ((self->flags & 0x200) == 0 && amount > 20.0f) {
        amount = 20.0f;
    }

    if (amount > 1.01f * (f32)self->field5da) {
        amount = 1.01f * (f32)self->field5da;
    }

    self->field4ac = amount;
    dist = self->field184 - self->field4ac;
    self->field184 = dist;
    if (dist < 0.0f) {
        if ((self->flags & 0x10080) != 0) {
            result = 0;
        } else {
            result = 1;
            self->field593 = 0x3c;
        }
        self->flags |= 0x80;
        self->field184 = 0.0f;
        self->field224 = 0.0f;
        return result;
    }

    return 0;
}
/* fzgx:end fn_1_24F10 */

/* fzgx:begin fn_1_25004 */
typedef struct Fn_1_25004_Obj {
    u32 flags00;
    s16 field04;
    u8 pad06[0x8e];
    f32 field94;
    f32 field98;
    f32 field9c;
    f32 fielda0;
    f32 fielda4;
    f32 fielda8;
    u8 padac[0xd0];
    f32 field17c;
    u8 pad180[0x4];
    f32 field184;
    u8 pad188[0x9c];
    f32 field224;
    u8 pad228[0x24c];
    u8 field474;
    u8 pad475[0x117];
    u32 flags58c;
} Fn_1_25004_Obj;

typedef struct Fn_1_25004_Result {
    u8 pad390[0x390];
    u32 flags390;
} Fn_1_25004_Result;

#pragma opt_strength_reduction off
void fn_1_25004(Fn_1_25004_Obj *self) {
    Fn_1_25004_Result *result;
    f32 zero;

    result = (Fn_1_25004_Result *)fn_1_868C0((s8)self->field04);
    if ((self->flags58c & 0x10) == 0) {
        if ((s8)self->field474 != -1) {
            fn_1_F7338((s8)self->field474, (void *)(int)(2), (void *)(int)(0x1e));
        }
        zero = (0.0f);
        self->flags00 |= 0x800;
        self->flags00 |= 0x80;
        self->flags00 |= 0x800000;
        self->flags00 |= 0x40000000;
        self->flags58c |= 0x10;
        self->field184 = zero;
        self->field224 = zero;
        self->field94 = zero;
        self->field98 = zero;
        self->field9c = zero;
        self->fielda0 = zero;
        self->fielda4 = zero;
        self->fielda8 = zero;
        self->field17c = zero;
        self->flags58c &= ~0x80;
        result->flags390 &= ~0x200000;
        result->flags390 |= 0x1000000;
    }
}
#pragma opt_strength_reduction reset
/* fzgx:end fn_1_25004 */

/* fzgx:begin fn_1_250F8 */
typedef struct Fn_1_250F8 {
    u32 flags;
    u8 pad04[0x180];
    f32 field184;
    u8 pad188[0x88];
    u16 field210;
    u8 pad212[0x01];
    u8 field213;
    u8 pad214[0x03];
    u8 field217;
    u8 pad218[0x29A];
    u8 field4b2;
    u8 pad4b3[0xD9];
    u32 field58c;
} Fn_1_250F8;

void fn_1_250F8(Fn_1_250F8 *self) {
    u16 value;
    f32 add;
    f32 elapsed;
    u32 delta;

    if ((self->flags & 0x10000) == 0) {
        value = self->field210;
        add = lbl_1_rodata_85C * self->field184;
        elapsed = (f32)value + add;
        delta = ((u32)self->field213 * 60) / 60;
        self->field210 = (s32)elapsed;
        if (self->field217 == 0) {
            self->field210 += 25;
        }
        if (self->field4b2 == 0) {
            self->field210 += 25;
        }
        if ((self->field58c & 1) == 0) {
            self->field210 += 40;
        }
        if (self->flags & 0x80) {
            self->field210 += 25;
        }
        if (self->field210 > delta) {
            self->field210 -= delta;
        } else {
            self->field210 = 0;
        }
    }
    self->flags |= 0x10000;
}
/* fzgx:end fn_1_250F8 */

/* fzgx:begin fn_1_251F8 noprologue */
#include "types.h"

struct V3 {
    f32 x;
    f32 y;
    f32 z;
};

extern f32 lbl_8006D0B4(f32);
extern const f32 lbl_1_rodata_840[];

static inline f32 *fn_1_251F8_array_read(f32 *array) { return array; }
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
static inline f32 fn_1_251F8_read_pointer(struct V3 * owner) { return owner->y; }
static inline f32 fn_1_251F8_read_pointer_(struct V3 * owner) { return owner->x; }
s32 fn_1_251F8(struct V3 *a0, struct V3 *a1, struct V3 *a2, struct V3 *a3, f32 *out, s32 *flag, f32 r0, f32 r1) {
    f32 fzgx_live_;
    f32 z2;
    f32 fzgx_live__;
    f32 fzgx_live;
    f32 dz;
    f32 big;
    f32 dx;
    f32 dy;
    f32 ey;
    f32 ex;
    f32 ez;
    struct { f32 value; } fx;
    f32 A;
    f32 B;
    f32 C;
    f32 D;
    f32 E;
    big = ((0x16c / 4)[lbl_1_rodata_840]);
    *out = big;
    *flag = 0;
    fzgx_live__ = a0->x;
    dx = fzgx_live__;
    dx = dx - a2->x;
    dy = a0->y - a2->y;
    fzgx_live_ = a1->x;
    fzgx_live_ = fzgx_live_ - fn_1_251F8_read_pointer_(a3);
    ex = fzgx_live_ - dx;
    fzgx_live = a0->z;
    z2 = a2->z;
    dz = fzgx_live - z2;
{
    ey = (a1->y - a3->y) - dy;
    ez = (a1->z - a3->z) - dz;
    A = (f32)((f32)(ez * ez) + (f32)((f32)(ex * ex) + (f32)(ey * ey)));
    if (((0x114 / 4)[lbl_1_rodata_840]) > A) {
        *flag = 1;
        return 0;
    }
    fx.value = r0 + r1;
    B = (f32)((f32)(dz * ez) + (f32)((f32)(dx * ex) + (f32)(dy * ey)));
}
    C = (f32)((f32)(dz * dz) + (f32)((f32)(dx * dx) + (f32)(dy * dy))) - (f32)(fx.value * fx.value);
    D = (f32)(B * B) - (f32)(A * C);
    if (((0xc / 4)[lbl_1_rodata_840]) > D) {
        return 0;
    }
    if (((0xc / 4)[lbl_1_rodata_840]) >= C) {
        *out = ((0xc / 4)[lbl_1_rodata_840]);
        return 1;
    }
    if (((0xc / 4)[lbl_1_rodata_840]) >= C + (B + (A + B))) {
    } else {
        if (((0xc / 4)[lbl_1_rodata_840]) <= B) {
            return 0;
        }
        if (-B >= A) {
            return 0;
        }
    }
    E = lbl_8006D0B4(D);
    *out = -(B + E) / A;
    return 1;
}
#pragma opt_dead_assignments reset

#pragma opt_propagation reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_251F8 */

/* fzgx:begin fn_1_253A4 noprologue */
#include "types.h"

// Scales collision response based on the flagged corner count.










typedef struct {
    u32 flag;                   // 0x0
    u8 _4[0x5c - 0x4];
} Corner;                       // 0x5c

typedef struct {
    u32 state;                  // 0x0
    u8 _4[0x14 - 0x4];
    f32 f14;                    // 0x14
    f32 f18;                    // 0x18
    u8 _1c[0xa4 - 0x1c];
    f32 fa4;                    // 0xa4
    u8 _a8[0x1f8 - 0xa8];
    f32 f1f8;                   // 0x1f8
    f32 f1fc;                   // 0x1fc
    u8 _200[0x20c - 0x200];
    f32 f20c;                   // 0x20c
    u8 _210[0x244 - 0x210];
    Corner corner[4];           // 0x244
} ColObj;

typedef struct {
    u8 _0[0xc];
    f32 kc;                     // 0xc
    u8 _10[0x14 - 0x10];
    f32 k14;                    // 0x14
    u8 _18[0x60 - 0x18];
    f32 k60;                    // 0x60
    u8 _64[0x84 - 0x64];
    f32 k84;                    // 0x84
    u8 _88[0x130 - 0x88];
    f32 k130;                   // 0x130
    u8 _134[0x180 - 0x134];
    f64 k180;                   // 0x180
} ScalePool;

extern const ScalePool lbl_1_rodata_840;

f32 fn_1_253A4(ColObj *p) {
    const ScalePool *k = &lbl_1_rodata_840;
    f32 f1, v, s;
    u32 flags = p->state;
    int i;

    if (!(flags & 0x400)) {
        return k->kc;
    }

    v = k->k14;
    s = k->k60;
    for (i = 0; i < 4; i++) {
        if (p->corner[i].flag & 4) {
            v -= s;
        }
    }

    f1 = p->f18 * (p->f1f8 * p->f1fc);
    v = v * f1;
    f1 = p->f14 + v;
    f1 = f1 * -p->f1fc;
    if (flags & 0x20000) {
        f1 = f1 * k->k130;
    }

    {
        f32 t = k->k84 * f1;
        p->fa4 = p->fa4 + t;
    }
    if (__fabs(p->fa4) < k->k180) {
        p->fa4 = k->kc;
    }
    p->f20c = p->f1fc;
    return f1;
}
/* fzgx:end fn_1_253A4 */

/* fzgx:begin fn_1_25480 noprologue */
#include "game/main_rel/stcoli_types.h"
#include "game/vec3.h"

typedef struct Fn_1_25480_Obj {
    u32 flags;          /* 0x000 */
    u8 pad_4[0x4];
    f32 mass;           /* 0x008 */
    u8 pad_C[0x10];
    f32 f1C;            /* 0x01C */
    f32 f20;            /* 0x020 */
    u8 pad_24[0x8];
    f32 f2C;            /* 0x02C */
    u8 pad_30[0x64];
    Vec3f vel;          /* 0x094 */
    f32 fA0;            /* 0x0A0 */
    u8 pad_A4[0x4];
    f32 fA8;            /* 0x0A8 */
    u8 pad_AC[0xC];
    f32 fB8;            /* 0x0B8 */
    u8 pad_BC[0x4];
    f32 fC0;            /* 0x0C0 */
    u8 pad_C4[0x4];
    f32 fC8;            /* 0x0C8 */
    f32 fCC;            /* 0x0CC */
    f32 fD0;            /* 0x0D0 */
    f32 fD4;            /* 0x0D4 */
    u8 pad_D8[0xE4];
    f32 f1BC;           /* 0x1BC */
    f32 f1C0;           /* 0x1C0 */
    f32 f1C4;           /* 0x1C4 */
    u8 pad_1C8[0x24];
    f32 f1EC;           /* 0x1EC */
    f32 f1F0;           /* 0x1F0 */
    u8 pad_1F4[0x4];
    f32 f1F8;           /* 0x1F8 */
    f32 f1FC;           /* 0x1FC */
    u8 pad_200[0x18];
    u32 f218;           /* 0x218 */
    u8 pad_21C[0x264];
    u8 b480;            /* 0x480 */
    u8 pad_481[0x53];
    f32 f4D4;           /* 0x4D4 */
    u8 pad_4D8[0xB4];
    u32 f58C;           /* 0x58C */
    u8 pad_590[0x80];
    f32 f610;           /* 0x610 */
} Fn_1_25480_Obj;

extern f32 fn_1_26F34(Fn_1_25480_Obj *, f32, f32, f32);
extern f32 fn_1_2B478(void *);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern u32 mathutil_mtxA_rotate_y(u32);
extern void lbl_8006E1F0(Vec3f *, f32, f32, f32);
extern f64 __fabs(f64);

/* Pool primer: reproduces the TU literal pool lbl_1_rodata_840 up to +0x1B4.
 * Literals this function uses are native; the other words are raw tables. */
#pragma section RX ".fzgxpool"
static const u32 fzgx_pool_table_0[2] = { 0x42500000, 0x3D800000 };
__declspec(section ".fzgxpool") u32 fzgx_pool_t00(int i) { return fzgx_pool_table_0[i]; }
__declspec(section ".fzgxpool") f32 fzgx_pool_p08(void) { return 45.0f; }
__declspec(section ".fzgxpool") f32 fzgx_pool_p0C(void) { return 0.0f; }
static const u32 fzgx_pool_table_10[1] = { 0x3FD9999A };
__declspec(section ".fzgxpool") u32 fzgx_pool_t10(int i) { return fzgx_pool_table_10[i]; }
__declspec(section ".fzgxpool") f32 fzgx_pool_p14(void) { return 1.0f; }
static const u32 fzgx_pool_table_18[9] = {
    0x3DCCCCCD, 0x3F000000, 0x43300000, 0x00000000, 0x42200000, 0x43AE0000, 0x42100000, 0x40800000,
    0x3F19999A
};
__declspec(section ".fzgxpool") u32 fzgx_pool_t18(int i) { return fzgx_pool_table_18[i]; }
__declspec(section ".fzgxpool") f32 fzgx_pool_p3C(void) { return 5.0f; }
__declspec(section ".fzgxpool") f32 fzgx_pool_p40(void) { return 0.05f; }
static const u32 fzgx_pool_table_44[1] = { 0x447A0000 };
__declspec(section ".fzgxpool") u32 fzgx_pool_t44(int i) { return fzgx_pool_table_44[i]; }
__declspec(section ".fzgxpool") f32 fzgx_pool_p48(void) { return 8.0f; }
__declspec(section ".fzgxpool") f64 fzgx_pool_p50(void) { return 216.0; }
static const u32 fzgx_pool_table_58[2] = { 0x40000000, 0x00000000 };
__declspec(section ".fzgxpool") u32 fzgx_pool_t58(int i) { return fzgx_pool_table_58[i]; }
__declspec(section ".fzgxpool") f32 fzgx_pool_p60(void) { return 0.25f; }
static const u32 fzgx_pool_table_64[21] = {
    0x3D8F5C29, 0x3E4CCCCD, 0x00000000, 0x3FEAE147, 0xAE147AE1, 0x40000000, 0x3FE66666, 0x3FB33333,
    0x3FC00000, 0x3F99999A, 0x40133333, 0x3ECCCCCD, 0x404CCCCD, 0x3E19999A, 0xBE800000, 0x3E23D70A,
    0x3DF5C28F, 0x3DA3D70A, 0x3EE66666, 0x3F333333, 0x00000000
};
__declspec(section ".fzgxpool") u32 fzgx_pool_t64(int i) { return fzgx_pool_table_64[i]; }
__declspec(section ".fzgxpool") f64 fzgx_pool_pB8(void) { return 0.6f; }
static const u32 fzgx_pool_table_C0[28] = {
    0x3E9EB852, 0x3CF5C28F, 0x3C23D70A, 0x442F0000, 0x3FE23D70, 0xA3D70A3D, 0x3F11EB85, 0x00000000,
    0x00000000, 0x00000000, 0x3F800000, 0xBDCCCCCD, 0x43480000, 0x3CA3D70A, 0x3F847AE1, 0x40000000,
    0x3D23D70A, 0x3F4CCCCD, 0x402BC71C, 0x71C71C72, 0x415E38E4, 0x34000000, 0x44480000, 0x3F733333,
    0x400CCCCD, 0xBF000000, 0x3B03126F, 0x3A83126F
};
__declspec(section ".fzgxpool") u32 fzgx_pool_tC0(int i) { return fzgx_pool_table_C0[i]; }
__declspec(section ".fzgxpool") f32 fzgx_pool_p130(void) { return 0.3f; }
static const u32 fzgx_pool_table_134[13] = {
    0x00000000, 0x3FD99999, 0x9999999A, 0x3FB99999, 0x9999999A, 0x42A00000, 0x44D48000, 0x40568000,
    0x00000000, 0x3EAAAAAB, 0xC59C4000, 0x44610000, 0xC61C4000
};
__declspec(section ".fzgxpool") u32 fzgx_pool_t134(int i) { return fzgx_pool_table_134[i]; }
__declspec(section ".fzgxpool") f32 fzgx_pool_p168(void) { return 10.0f; }
static const u32 fzgx_pool_table_16C[3] = { 0x42C80000, 0x43C80000, 0x3F7D70A4 };
__declspec(section ".fzgxpool") u32 fzgx_pool_t16C(int i) { return fzgx_pool_table_16C[i]; }
__declspec(section ".fzgxpool") f32 fzgx_pool_p178(void) { return 20.0f; }
static const u32 fzgx_pool_table_17C[3] = { 0x3F8147AE, 0x3FF00000, 0x00000000 };
__declspec(section ".fzgxpool") u32 fzgx_pool_t17C(int i) { return fzgx_pool_table_17C[i]; }
__declspec(section ".fzgxpool") f64 fzgx_pool_p188(void) { return 0.55f; }
__declspec(section ".fzgxpool") f32 fzgx_pool_p190(void) { return 3.4f; }
__declspec(section ".fzgxpool") f32 fzgx_pool_p194(void) { return 0.75f; }
__declspec(section ".fzgxpool") f32 fzgx_pool_p198(void) { return 182.04445f; }
__declspec(section ".fzgxpool") f32 fzgx_pool_p19C(void) { return -45.0f; }
__declspec(section ".fzgxpool") f64 fzgx_pool_p1A0(void) { return 0.9259259259259259; }
__declspec(section ".fzgxpool") f64 fzgx_pool_p1A8(void) { return 5.555555555555555; }
__declspec(section ".fzgxpool") f32 fzgx_pool_p1B0(void) { return 1.13f; }

#pragma fp_contract on
void fn_1_25480(Fn_1_25480_Obj *p)
{
    Vec3f push;
    Vec3f kick;
    f32 drive;
    f32 grip;
    f32 yaw;
    f32 speed;
    f32 slip;
    f32 tilt;
    f32 bank;
    f32 len;
    f32 vz;
    f32 vy;
    f32 len2;
    f32 wy;
    f32 *mtx;

    vz = p->fD4;
    vy = p->fD0;
    len = p->fCC * p->fCC;
    len = __fmadds(vy, vy, len);
    len = __fmadds(vz, vz, len);
    drive = -p->fC0;
    yaw = __fabs(p->fB8);
    speed = lbl_8006D0B4(len);
    if (!(p->flags & 0x03800000) && speed > (10.0f * p->mass) / 216.0) {
        slip = p->fD4 / speed;
        slip = slip * slip;
        slip = (1.0f - slip) * p->f2C;
        if (slip > 1.0f) {
            slip = 1.0f;
        }
    } else {
        slip = 0.0f;
    }
    drive = fn_1_26F34(p, drive, yaw, slip);
    grip = fn_1_2B478(p);
    grip = 0.6f + (f64)(0.55f * __fabs(grip));
    if (grip > 1.0f) {
        grip = 1.0f;
    }
    drive *= grip;
    psvec_scale(&p->vel, grip, &p->vel);

    if (p->flags & 0x20) {
        p->fC8 += (f32)(0.05f * drive);
    } else {
        p->fC8 += (f32)(0.25f * drive);
    }

    if (p->flags & 0x2) {
        mtx = (f32 *)lbl_801A6D00.unk_0;
        grip = 3.4f * (0.3f + ((f32)(mtx[10] * p->f1C4) + ((f32)(mtx[2] * p->f1BC) + (f32)(mtx[6] * p->f1C0))));
        if (grip > 1.0f) {
            grip = 1.0f;
        } else {
            if (grip < 0.0f) {
                grip = 0.0f;
            }
            grip = grip * grip;
        }
    } else {
        grip = 1.0f;
    }

    lbl_8006DAEC();
    tilt = p->f1FC * p->f20;
    bank = -(tilt + (f32)(p->f1F8 * p->f1C));
    if (p->flags & 0x20000) {
        bank = 0.0f;
    }
    p->f4D4 = 0.75f * -tilt;
    mathutil_mtxA_rotate_y((s32)(182.04445f * (bank < -45.0f ? -45.0f : (bank > 45.0f ? 45.0f : bank))));
    lbl_8006E1F0(&push, 0.0f, 0.0f, -drive * grip);
    psvec_add(&push, &p->vel, &p->vel);
    lbl_8006DB30();

    wy = p->vel.y;
    len2 = p->vel.x * p->vel.x;
    len2 = __fmadds(wy, wy, len2);
    speed = lbl_8006D0B4(__fmadds(p->vel.z, p->vel.z, len2));
    if (speed / p->mass > 0.9259259259259259) {
        if (p->b480 == 6) {
            f32 limit = speed;
            if (speed > 5.555555555555555 * p->mass) {
                limit = 5.555555555555555 * p->mass;
            }
            lbl_8006E1F0(&kick, p->f610 * limit, 0.0f, 0.0f);
            psvec_add(&kick, &p->vel, &p->vel);
        }
        if ((p->f218 >> 26) & 1) {
            lbl_8006E1F0(&kick, 0.0f, 1.13f * speed, 0.0f);
            psvec_add(&kick, &p->vel, &p->vel);
            p->f58C |= 2;
            p->fA0 = 0.0f;
            p->fA8 = 0.0f;
        }
    }

    p->f1F0 = p->f1EC / 20.0f;
    p->f1EC = p->f1EC + ((f32)(8.0f * p->f1F8) - (f32)(5.0f * p->f1F0));
}
/* fzgx:end fn_1_25480 */

/* fzgx:begin fn_1_25870 */
typedef struct Fn_1_25870 {
    u32 flags;
    unsigned char pad04[0x1f4];
    f32 field1f8;
    f32 field1fc;
    unsigned char pad200[0x24];
    f32 field224;
    unsigned char pad228[0x1c];
    u32 field244;
    unsigned char pad248[0x58];
    u32 field2a0;
    unsigned char pad2a4[0x58];
    u32 field2fc;
    unsigned char pad300[0x58];
    u32 field358;
    unsigned char pad35c[0x11a];
    u8 field476;
    u8 field477;
} Fn_1_25870;

void fn_1_25870(Fn_1_25870 *self) {
    unsigned char *data = lbl_1_rodata_840;
    u32 flags;
    int trigger;

    if (self->field476 != 0) {
        self->field476--;
    }
    flags = self->flags;
    if ((flags & 0x2) == 0) {
        if (self->field224 > *(f32 *)(data + 0x18)) {
            if ((flags & 0x2000) != 0) {
                self->field244 &= ~4;
                self->field2a0 &= ~4;
                self->field2fc &= ~4;
                self->field358 &= ~4;
                self->field476 = self->field477;
            } else {
                trigger = 0;
                if ((flags & 0x1000) != 0 &&
                    __fabs(self->field1fc) > *(f64 *)(data + 0x1b8)) {
                    trigger = 1;
                }
                if ((self->flags & 0x8) != 0) {
                    trigger = 1;
                }
                if (trigger != 0) {
                    self->field244 |= 4;
                    self->field2a0 |= 4;
                    self->field2fc |= 4;
                    self->field358 |= 4;
                }
            }
        }
    } else {
        self->field244 &= ~4;
        self->field2a0 &= ~4;
        self->field2fc &= ~4;
        self->field358 &= ~4;
    }
    flags = self->flags;
    if ((flags & 0x4000) != 0 &&
        __fabs(self->field1fc) < *(f64 *)(data + 0x1b8)) {
        self->flags = flags & ~0x4000;
    }
    if (__fabs(self->field1f8) > *(f64 *)(data + 0x1c0)) {
        self->flags |= 0x4000;
    }
    if ((self->flags & 0x4000) == 0) {
        return;
    }
    self->field244 |= 0x10;
    self->field2a0 |= 0x10;
    self->field2fc |= 0x10;
    self->field358 |= 0x10;
}
/* fzgx:end fn_1_25870 */

/* fzgx:begin fn_1_266A8 noprologue */
#include "dolphin/types.h"
#include "game/vec3.h"
#include "psvec.h"

#pragma fp_contract on

typedef struct { f32 x, y, z; } CollisionVec3;

typedef struct CollisionObject {
    u32 flags;
    u8 pad4[4];
    f32 scale;
    u8 padC[0x70];
    CollisionVec3 position;
    u8 pad88[0xC];
    CollisionVec3 velocity;
    u8 padA0[0x24];
    f32 field_c4;
    f32 field_c8;
    u8 padCC[0xB0];
    f32 field_17c;
    u8 pad180[4];
    f32 field_184;
    u8 pad188[2];
    u8 field_18a;
    u8 field_18b;
    u8 pad18C[0x24];
    CollisionVec3 collision;
    CollisionVec3 normal;
    u8 pad1C8[0x4B];
    u8 field_213;
    u16 field_214;
    u8 field_216;
    u8 pad217[0xD];
    f32 field_224;
    f32 field_228;
    u8 pad22C[0x18];
    u32 field_244;
    u8 pad248[0x58];
    u32 field_2a0;
    u8 pad2A4[0x58];
    u32 field_2fc;
    u8 pad300[0x58];
    u32 field_358;
    u8 pad35C[0x58];
    struct { CollisionVec3 point; u8 pad[0x18]; CollisionVec3 dest; } parts[4];
    s8 field_474;
    u8 pad475[0xC];
    u8 field_481;
    u8 pad482[0x2A];
    f32 field_4ac;
    u8 pad4B0[0x50];
    CollisionVec3 field_500;
    u8 pad50C[0x87];
    u8 field_593;
    u8 pad594[0x46];
    u16 field_5da;
} CollisionObject;

extern const f32 lbl_1_rodata_840[3];
extern s32 fn_1_25A14(CollisionObject *);
extern void fn_1_F7338(s32, s32, s32);
extern void fn_1_29044(CollisionObject *, CollisionVec3 *, CollisionVec3 *);
extern void fn_1_2A2A4(CollisionObject *);
extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D6FC(void *, void *);
extern void lbl_8006D5F0(void *, void *, f32);
extern void fn_8006E2B0(void *, CollisionVec3 *);
extern void lbl_8006E1F0(CollisionVec3 *, f32, f32, f32);

// Pool primer: volatile writes retain the original translation-unit literal order.
#pragma push
#pragma section code_type ".fzgxpool"
/* volatile: preserve literal-pool order by keeping each primer store observable. */
static void fzgx_pool_primer(volatile f32 *f, volatile f64 *d)
{
    *d = 274877969920.00000; /* 0 */
    *f = 45.0000000f; /* 8 */
    *f = 0.0f; /* c */
    *f = 1.70000005f; /* 10 */
    *f = 1.0f; /* 14 */
    *f = 0.1f; /* 18 */
    *f = 0.5f; /* 1c */
    *d = 4503599627370496.0; /* 20 */
    *d = 34359747031.000000; /* 28 */
    *d = 17179873312.000000; /* 30 */
    *f = 0.6f; /* 38 */
    *f = 5.00000000f; /* 3c */
    *d = 2.0463635858390458e-13; /* 40 */
    *d = 131072.00000000000; /* 48 */
    *d = 216.00000000000000; /* 50 */
    *d = 2.0; /* 58 */
    *d = 1.1920931688891301e-7; /* 60 */
    *f = 0.2f; /* 68 */
    *d = 0.83999999999999997; /* 70 */
    *d = 2.0000004760921000; /* 78 */
    *f = 1.39999998f; /* 80 */
    *f = 1.5f; /* 84 */
    *d = 0.025000009690120350; /* 88 */
    *f = 0.4f; /* 90 */
    *f = 3.20000005f; /* 94 */
    *f = 0.15f; /* 98 */
    *f = -0.250000000f; /* 9c */
    *d = 2.3096799886546114e-9; /* a0 */
    *d = 9.0221874811608268e-12; /* a8 */
    *f = 0.7f; /* b0 */
    *d = 0.60000002384185791; /* b8 */
    *d = 4.5776374420825048e-7; /* c0 */
    *d = 5.3776428844767350e-19; /* c8 */
    *d = 0.56999999999999995; /* d0 */
    *d = 0.000068359368015080690; /* d8 */
    *d = 0.0000000000000000; /* e0 */
    *d = 0.0078125055239070210; /* e8 */
    *d = 13510800916852244; /* f0 */
    *d = 0.0099999997764825821; /* f8 */
    *d = 3.5242919890636131e-14; /* 100 */
    *d = 13.888888888888889; /* 108 */
    *d = 7922576.8125000000; /* 110 */
    *d = 8.8544385506608402e+20; /* 118 */
    *f = 2.20000005f; /* 120 */
    *f = -0.5f; /* 124 */
    *d = 1.9719995846449581e-24; /* 128 */
    *f = 0.3f; /* 130 */
    *d = 0.4; /* 138 */
    *d = 0.1; /* 140 */
    *d = 8796095277632.0000; /* 148 */
    *d = 90.000000000000000; /* 150 */
    *d = 7.9472909961415816e-7; /* 158 */
    *d = 2.5087589366215800e+21; /* 160 */
    *d = 524288.13043212891; /* 168 */
    *d = 3.4587650591954883e+18; /* 170 */
    *f = 20.0f; /* 178 */
    *f = 1.01f; /* 17c */
    *d = 1.0000000000000000; /* 180 */
    *d = 0.55000001192092896; /* 188 */
    *d = 102.40003949403763; /* 190 */
    *d = 6204963985555456.0; /* 198 */
    *d = 0.92592592592592593; /* 1a0 */
    *d = 5.5555555555555554; /* 1a8 */
    *d = 0.016249999403953552; /* 1b0 */
    *d = 0.10000000149011612; /* 1b8 */
    *d = 0.30000001192092896; /* 1c0 */
    *d = 0.046296296296296294; /* 1c8 */
    *f = 0.9f; /* 1d0 */
    *f = 1.11f; /* 1d4 */
    *d = 0.0023148148148148147; /* 1d8 */
    *d = 0.5; /* 1e0 */
    *d = 0.004629629629629629; /* 1e8 */
    *d = 0.023148148148148147; /* 1f0 */
    *f = 2000.0f; /* 1f8 */
    *f = 500.0f; /* 1fc */
    *d = 0.2; /* 200 */
    *f = 0.64f; /* 208 */
    *f = 0.35f; /* 20c */
    *d = 1.8518518518518519; /* 210 */
    *d = 3.4000000953674316; /* 218 */
    *d = 1.7000000476837158; /* 220 */
    *d = 3.0; /* 228 */
    *d = 1.5; /* 230 */
    *f = -0.4f; /* 238 */
    *d = 3.240740740740741; /* 240 */
    *f = -1.0f; /* 248 */
}

#pragma pop

static inline f32 collision_vector_squared(const CollisionVec3 *v)
{
    f32 sum; f32 x; f32 y; f32 z;
    x=v->x; y=v->y;
    sum = (f32)(x*x); sum += y*y;
    z=v->z; sum += z*z;
    return sum;
}
#define LENGTH(v) lbl_8006D0B4(collision_vector_squared(&(v)))

static inline f32 collision_factor(f32 speed, CollisionObject *obj,
                                  CollisionVec3 *projected, CollisionVec3 *remainder,
                                  f32 projection)
{
    f32 factor = 2.0 * __fabs(0.5f + speed);
    psvec_scale(&obj->normal, projection, projected);
    psvec_sub(&obj->velocity, projected, remainder);
    return factor;
}

void fn_1_266A8(CollisionObject *obj)
{
    CollisionVec3 impulse;
    CollisionVec3 converted;
    CollisionVec3 part;
    CollisionVec3 remainder;
    CollisionVec3 projected;
    CollisionVec3 up;
    f32 k;      /* scalar fed to the paired-single scale kernels */
    f32 dot;
    f32 speed;
    f32 collisionLength;
    f32 damage;
    s32 hit;
    s32 active;
    s32 i;
    const f32 *pool = (const f32 *)&lbl_1_rodata_840;

    hit = fn_1_25A14(obj);
    collisionLength = LENGTH(obj->collision);
    speed = LENGTH(obj->velocity) / obj->scale;
    if (collisionLength > 0.0023148148148148147) {
        if (hit != 0) {
            obj->flags |= 0x800000;
            if (obj->field_213 < 180) {
                obj->field_213++;
            }
        } else {
            obj->flags |= 0x1000000;
        }
        if ((obj->flags & 0x10) && obj->field_17c > 0.1) {
            if (collisionLength > 2.0) {
                fn_1_F7338(obj->field_474, 2, 9);
            } else if (collisionLength > 0.5) {
                fn_1_F7338(obj->field_474, 3, 9);
            } else {
                fn_1_F7338(obj->field_474, 4, 9);
            }
        }
    }
    active = 0;
    if (collisionLength > 0.004629629629629629 && speed > 0.004629629629629629) {
        active = 1;
    }
    if (obj->field_481 > 60) {
        active = active && (obj->flags & 0x800000);
    }
    if (active) {
        obj->field_500 = obj->collision;
        dot = lbl_8006D6FC(&obj->collision, &obj->velocity);
        if (dot > 0.0f) {
            dot = 0.0f;
        }
        if (speed > 0.023148148148148147) {
            f32 normalDot = lbl_8006D6FC(&obj->collision, &obj->normal);
            damage = 0.0f;
            if ((f32)__fabs(normalDot) < 0.7f) {
                normalDot = dot;
                normalDot *= dot;
                normalDot = (0.15f + normalDot) / 1.5f;
                normalDot *= LENGTH(obj->velocity);
                damage = normalDot;
                if (obj->flags & 0x200) {
                    damage /= 2000.0f;
                } else {
                    damage /= 500.0f;
                    if (obj->field_216) {
                        damage *= 0.15f;
                    }
                }
            }
            if (dot < -0.5f) {
                obj->flags &= 0xFF9FFF9F;
                obj->field_18a = 0;
                obj->field_18b = 0;
            }
            if (obj->field_17c > 0.1f) {
                if (damage > 0.4) {
                    fn_1_F7338(obj->field_474, 2, 9);
                } else if (damage > 0.2) {
                    fn_1_F7338(obj->field_474, 3, 9);
                } else {
                    fn_1_F7338(obj->field_474, 4, 9);
                }
            }
            if ((obj->flags & 0x800000) && obj->field_214 == 0 && obj->field_593 == 0) {
                f32 amount;
                f32 limit;
                amount = damage * *(f32 *)((u8 *)obj + 0x30);
                if (!(obj->flags & 0x200) && amount > 20.0f) {
                    amount = 20.0f;
                }
                limit = 1.01f * obj->field_5da;
                if (amount > limit) {
                    amount = limit;
                }
                obj->field_4ac = amount;
                if ((obj->field_184 -= obj->field_4ac) < 0.0f) {
                    if (!(obj->flags & 0x10080)) {
                        obj->field_593 = 60;
                    }
                    obj->flags |= 0x80;
                    obj->field_184 = 0.0f;
                    obj->field_224 = 0.0f;
                }
            }
        }
        lbl_8006D5F0(&obj->collision, &impulse, dot * LENGTH(obj->velocity));
        if (dot < 0.0f) {
            if (obj->field_216 == 0) {
                f32 t = dot / 0.7f;
                f32 m = 0.2f + (f32)(0.6f * lbl_8006D0B4(1.0f - (f32)(t * t)));
                obj->field_224 *= m;
                obj->field_228 *= 0.3f + (f32)(0.4f * m);
            } else {
                f32 t = dot / 0.7f;
                f32 m = 0.64f + (f32)(0.35f * lbl_8006D0B4(1.0f - (f32)(t * t)));
                obj->field_224 *= m;
                obj->field_228 *= 0.3f + (f32)(0.6f * m);
            }
        }
        if (speed > 1.8518518518518519) {
            f32 factor;
            if (obj->flags & 0x80) {
                factor = 3.4000000953674316 - (f64)(1.7000000476837158 * __fabs(dot));
            } else if (obj->field_216) {
                factor = 2.0 - __fabs(dot);
            } else {
                factor = 3.0 - (f64)(1.5 * __fabs(dot));
            }
            if (dot < -0.4f && speed > 3.240740740740741) {
                k = -factor;
                psvec_scale(&impulse, k, &impulse);
                psvec_add(&impulse, &obj->velocity, &obj->velocity);
            } else {
                k = -factor;
                psvec_scale(&impulse, k, &impulse);
                psvec_add(&impulse, &obj->velocity, &obj->velocity);
            }
            if (obj->field_216 == 0) {
                obj->field_244 |= 4;
                obj->field_2a0 |= 4;
                obj->field_2fc |= 4;
                obj->field_358 |= 4;
            }
            obj->field_216 = 20;
        } else {
            k = -1.0f;
            psvec_scale(&impulse, k, &impulse);
            psvec_add(&impulse, &obj->velocity, &obj->velocity);
        }
        fn_8006E2B0(&impulse, &converted);
        obj->field_c4 += converted.x;
        obj->field_c8 += converted.z;
        if (obj->flags & 0x400) {
            for (i = 0; i < 4; i++) {
                part = obj->parts[i].point;
                part.z += 0.2f;
                fn_1_29044(obj, &part, &obj->parts[i].dest);
            }
        }
        if (obj->field_481 > 60) {
            fn_1_2A2A4(obj);
        }
    } else if (obj->flags & 0x10) {
        if (!(LENGTH(obj->velocity) / obj->scale < 0.046296296296296294)) {
            register f32 len;
            lbl_8006E1F0(&up, 0.0f, 1.0f, 0.0f);
            k = lbl_8006D6FC(&up, &obj->normal);
            /* speed and dot are dead here; retail reuses their registers for
             * the normal projection. */
            speed = lbl_8006D6FC(&obj->velocity, &obj->normal);
            len = LENGTH(obj->velocity);
            if (k < 0.0f) {
                k = 0.0f;
            }
            obj->field_224 *= k;
            dot = len * speed;
            len = collision_factor(speed, obj, &projected, &remainder, dot);
            if (len < 0.9f) {
                lbl_8006D5F0(&remainder, &remainder, 0.9f * ((1.0f - (f32)(1.11f * len)) * k));
            }
            psvec_scale(&projected, k, &projected);
            psvec_sub(&obj->velocity, &projected, &obj->velocity);
            psvec_add(&obj->velocity, &remainder, &obj->velocity);
        }
    }
    psvec_add(&obj->position, &obj->collision, &obj->position);
}
/* fzgx:end fn_1_266A8 */

/* fzgx:begin fn_1_26F34 noprologue */
#include "types.h"
#include "game/vec3.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 52.0f;
    s = 0.0625f;
    s = 45.0f;
    s = 0.0f;
    s = 1.7000000476837158f;
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.5f;
    d = 4503599627370496.0;
    s = 40.0f;
    s = 348.0f;
    s = 36.0f;
    s = 4.0f;
    s = 0.6000000238418579f;
    s = 5.0f;
    s = 0.05000000074505806f;
    s = 1000.0f;
    s = 8.0f;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 216.0;
    d = 2.0;
    s = 0.25f;
    s = 0.07000000029802322f;
    s = 0.20000000298023224f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.834999918937683f;
}
static const unsigned long fzgx_pool_table6[1] = {0xAE147AE1};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.0f;
    s = 1.7999999523162842f;
    s = 1.399999976158142f;
    s = 1.5f;
    s = 1.2000000476837158f;
    s = 2.299999952316284f;
    s = 0.4000000059604645f;
    s = 3.200000047683716f;
    s = 0.15000000596046448f;
    s = -0.25f;
    s = 0.1599999964237213f;
    s = 0.11999999731779099f;
    s = 0.07999999821186066f;
    s = 0.44999998807907104f;
    s = 0.699999988079071f;
}
static const unsigned long fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6000000238418579;
    s = 0.3100000023841858f;
    s = 0.029999999329447746f;
    s = 0.009999999776482582f;
    s = 700.0f;
    s = 1.7674999237060547f;
}
static const unsigned long fzgx_pool_table10[1] = {0xA3D70A3D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5699999928474426f;
}
static const unsigned long fzgx_pool_table12[4] = {0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.10000000149011612f;
    s = 200.0f;
    s = 0.019999999552965164f;
    d = 0.009999999776482582;
    s = 0.03999999910593033f;
    s = 0.800000011920929f;
    d = 13.88888888888889;
    s = 13.88888931274414f;
    s = 1.1920928955078125e-07f;
    s = 800.0f;
    s = 0.949999988079071f;
    s = 2.200000047683716f;
    s = -0.5f;
    s = 0.0020000000949949026f;
    s = 0.0010000000474974513f;
    s = 0.30000001192092896f;
}
static const unsigned long fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    d = 0.1;
    s = 80.0f;
    s = 1700.0f;
    d = 90.0;
    s = 0.3333333432674408f;
    s = -5000.0f;
    s = 900.0f;
    s = -10000.0f;
    s = 10.0f;
    s = 100.0f;
    s = 400.0f;
    s = 0.9900000095367432f;
    s = 20.0f;
    s = 1.0099999904632568f;
    d = 1.0;
    d = 0.550000011920929;
    s = 3.4000000953674316f;
    s = 0.75f;
    s = 182.04444885253906f;
    s = -45.0f;
    d = 0.9259259259259259;
    d = 5.555555555555555;
    s = 1.1299999952316284f;
}
static const unsigned long fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.10000000149011612;
    d = 0.30000001192092896;
    d = 0.046296296296296294;
    s = 0.8999999761581421f;
    s = 1.1100000143051147f;
    d = 0.0023148148148148147;
    d = 0.5;
    d = 0.004629629629629629;
    d = 0.023148148148148147;
    s = 2000.0f;
    s = 500.0f;
    d = 0.2;
    s = 0.6399999856948853f;
    s = 0.3499999940395355f;
    d = 1.8518518518518519;
    d = 3.4000000953674316;
    d = 1.7000000476837158;
    d = 3.0;
    d = 1.5;
    s = -0.4000000059604645f;
}
static const unsigned long fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const unsigned long *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 3.240740740740741;
    s = -1.0f;
    s = 9.999999747378752e-05f;
    s = 0.014000000432133675f;
    s = 9.0f;
    s = 60.0f;
    s = 3.0f;
    s = 0.1666666716337204f;
    s = 1200.0f;
    s = 1600.0f;
}
static const unsigned long fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const unsigned long *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"
typedef struct Sig_fn_1_2A3E4_Fn_1_2A3E4 {
 u32 flags; unsigned char pad04[0x186]; u8 active; unsigned char pad18b[0x85]; u16 value210;
} Sig_fn_1_2A3E4_Fn_1_2A3E4;
struct fn_1_26F34_lbl_1_rodata_840 {
 u8 pad0[12]; f32 unk_C; u8 pad10[4]; f32 unk_14; u8 pad18[4]; f32 unk_1C; f64 unk_20;
 f32 unk_28,unk_2C,unk_30,unk_34,unk_38,unk_3C,unk_40,unk_44;
 u8 pad48[0x20]; f32 unk_68; u8 pad6c[12]; f32 unk_78; u8 pad7c[0x1c]; f32 unk_98;
 u8 pad9c[8]; f32 unk_A4; u8 pada8[0x20]; f32 unk_C8; u8 padcc[0x38]; f32 unk_104;
 u8 pad108[12]; f32 unk_114; u8 pad118[4]; f32 unk_11C; u8 pad120[16]; f32 unk_130;
 u8 pad134[0x34]; f32 unk_168,unk_16C; u8 pad170[0xdc];
 f32 unk_24C,unk_250,unk_254,unk_258,unk_25C,unk_260,unk_264,unk_268;
};
extern const struct fn_1_26F34_lbl_1_rodata_840 lbl_1_rodata_840;
extern void fn_1_2A3E4(Sig_fn_1_2A3E4_Fn_1_2A3E4 *);
extern void fn_1_F7338(int, void *, void *);
#define F(o) (*(f32 *)((u8 *)arg0+(o)))
#define U(o) (*(u32 *)((u8 *)arg0+(o)))
#define H(o) (*(u16 *)((u8 *)arg0+(o)))
#define B(o) (*(u8 *)((u8 *)arg0+(o)))
#define K(n) K_##n
#define K_C 0.0f
#define K_14 1.0f
#define K_1C 0.5f
#define K_28 40.0f
#define K_2C 348.0f
#define K_30 36.0f
#define K_34 4.0f
#define K_38 0.6f
#define K_3C 5.0f
#define K_40 0.05f
#define K_44 1000.0f
#define K_68 0.2f
#define K_78 2.0f
#define K_98 0.15f
#define K_A4 0.12f
#define K_C8 0.01f
#define K_104 0.8f
#define K_114 1.1920928955078125e-7f
#define K_11C 0.95f
#define K_130 0.3f
#define K_168 10.0f
#define K_16C 100.0f
#define K_24C 0.0001f
#define K_250 0.014f
#define K_254 9.0f
#define K_258 60.0f
#define K_25C 3.0f
#define K_260 0.16666667f
#define K_264 1200.0f
#define K_268 1600.0f
/* squared ratio: the argument is evaluated once and its square taken in place */
static inline f32 sq_f32(f32 x) { return x * x; }
f32 fn_1_26F34(u32 arg0, f32 arg1, f32 arg2, f32 arg3) {
 const struct fn_1_26F34_lbl_1_rodata_840 *p_lbl_1_rodata_840=&lbl_1_rodata_840;
 u32 v0=U(0), v1; s32 v9;
 f32 v5, v16, v36, v41, v2, v45, v49, v52, v54, v60, v66;
 f32 v6, v7, v28, v30, v31, v32;
 s32 v14;
 if ((v0&0x80) && H(0x4e0)<120) {
  v1=B(0x197);
  if(v1>60) { F(0x200)=K(C); F(0x204)=K(24C); }
  else B(0x197)=v1+1;
  return K(C);
 }
 v5=F(0x200);
 if(U(0x58c)&4) {
  if(v5<K(C) || B(0x197)>=30) v5=K(C);
 } else {
  if(v5<K(C) || F(0x204)>K(C)) v5=K(C);
 }
 if(!(v0&0x400) && v5<K(130)) v5=K(C);
 if(v5>K(114)) {
  if(!(v0&0x400)) { U(0)|=0x400; B(0x481)=1; }
  if(U(0)&0x8000) F(0xdc)=(f32)(F(0xdc)+v5);
  else if(F(0xdc)>K(C)) { F(0x224)=K(14); U(0)|=0x180000; F(0xdc)=K(C); }
 } else {
  v6=F(0xdc);
  if(v6>K(C)) {
   v7=(f32)(v6-K(78));
   F(0xdc)=v7;
   if(v7<K(C)) F(0xdc)=K(C);
   if(!(U(0)&0x8000)) F(0x224)=K(C);
  } else if(v0&0x8000) F(0x224)=K(C);
 }
 v1=U(0);
 if(v1&0x8000) {
  F(0x224)=(f32)(K(250)*F(0xdc)); B(0x241)=0; B(0x240)=0; return -arg1;
 }
 arg1=(f32)(arg1/F(8));
 if((s8)B(0x474)!=-1) {
  v9=(v1>>6)&1;
  if(H(0x4c6)) { U(0)=v1&~0x40; H(0x4c6)--; }
  if((s32)v9 != 0) { if(H(0x4c6)) H(0x4c6)++; else H(0x4c6)=6; }
 }
 v1=U(0);
 if(v1&0x400000) {
  v16=(f32)(K(14)-(f32)(F(0x228)/(f32)(K(254)*F(0x230))));
  v14=(s32)(f32)(K(1C)*(f32)(K(258)*F(0x234)));
  fn_1_2A3E4((Sig_fn_1_2A3E4_Fn_1_2A3E4 *)arg0);
  if((u8)v14>B(0x18a)) B(0x18a)=v14;
  U(0)&=~0x40; U(0)|=0x20;
  if(v16<K(68)) v16=K(68);
  F(0x228)=(f32)(F(0x228)+(f32)((f32)(K(78)*F(0x230))*v16));
  fn_1_F7338(*(s8 *)((u8 *)arg0+0x474),(void *)3,(void *)15);
  if(B(0x4b2)<100) B(0x4b2)++;
 } else if(B(0x18a)) {
  U(0)=v1&~0x40; U(0)|=0x20;
 } else if((v1&0x40) && F(0x184)>K(14) && v5>K(C)) {
  v16=(f32)(K(14)-(f32)(F(0x228)/(f32)(K(254)*F(0x230))));
  fn_1_2A3E4((Sig_fn_1_2A3E4_Fn_1_2A3E4 *)arg0);
  v14=(s32)(f32)(K(258)*F(0x234));
  B(0x18a)=v14; B(0x18b)=v14;
  U(0)|=0x20; U(0)&=~0x200000;
  if(v16<K(68)) v16=K(68);
  if(B(0x217)<100) B(0x217)++;
  F(0x228)=(f32)(F(0x228)+(f32)(F(0x230)*v16));
  fn_1_F7338(*(s8 *)((u8 *)arg0+0x474),(void *)1,(void *)15);
 } else {
  U(0)&=0xffdfff9f;
  F(0x228)=(f32)(F(0x228)-(f32)((f32)(K(34)+(f32)(K(1C)*F(0x228)))/K(258)));
 }
 if(U(0)&8) {
  v28=F(0x228);
  F(0x228)=(f32)(v28-(f32)((f32)(K(25C)+(f32)(K(1C)*v28))/K(258)));
  v5 *= K(104);
 } else {
  v30=F(0x228);
  F(0x228)=(f32)(v30-(f32)((f32)(K(78)+(f32)(K(1C)*v30))/K(258)));
 }
 if(F(0x228)<K(C)) F(0x228)=K(C);
 v5 *= (f32)(K(28)*F(0x220));
 if(U(0)&0x20) {
  if(B(0x18b)) { F(0x184)=(f32)(F(0x184)-(f32)(K(260)*F(0x4dc))); B(0x18b)--; }
  if(--B(0x18a)==0 && F(0x17c)>K(264)) {
   v36=(f32)((f32)(F(0x17c)-K(264))/K(258));
   if(v36>K(168)) v36=K(168);
   if(v36>(f32)(u32)H(0x4c6)) H(0x4c6)=(s32)v36;
  }
  if(F(0x184)<K(C8)) {
   F(0x184)=K(C8); B(0x18b)=0;
   if(U(0)&0x200000) {
    v14=(s32)(f32)(K(1C)*(f32)(K(258)*F(0x234)));
    if(B(0x18a)>(u8)v14) B(0x18a)=v14;
   } else B(0x18a)=0;
  }
 }
 {
 f32 v40, v42, v43, v44;
 v41=(f32)(v5/K(2C));
 v2=F(0x22c);
 v40=(f32)(K(28)*v2);
 v41+=F(0x224);
 v45=K(78);
 v44=(f32)((f32)(K(30)+v40)+(f32)(F(0x228)*v45));
 v42=F(8); v43=K(C);
 arg2=(f32)((f32)(arg2*F(0x220))/v42);
 v2=(f32)(v41-arg1);
 v49=(f32)(v41/v44);
 if(v49<v43) v49=v43;
 v49 *= (f32)(K(34)*(f32)(F(0x220)*(f32)(K(38)+F(0x220))));
 v1=U(0);
 if(v1&0x400040) v49=K(C);
 else if(v1&0x20) { if(v42>K(44)) v49 *= K(1C); else v49 *= K(130); }
 }
 if(v2>K(C) && (arg1<K(C) || ((U(0x218)>>29)&1))) v49 *= K(3C);
 v52=(f32)((f32)(K(14)-arg3)*(f32)((f32)(v2*v49)+(f32)(arg2*F(0x238))));
 if(F(0x200)<K(14)) v52=(f32)(v52*(f32)(K(40)+(f32)(K(11C)*F(0x200))));
 F(0x224)=(f32)(v41-v52);
 if(F(0x204)>K(40)) { if(B(0x197)<30) B(0x197)++; } else B(0x197)=0;
 if(U(0x58c)&4) {
  if(B(0x197)>=15) v54=(f32)(F(0x204)*(f32)(K(1C)*v49)); else v54=K(C);
 } else v54=(f32)(F(0x204)*(f32)(K(1C)*v49));
 if(v54>K(A4)) v54=K(A4);
 if(v54>F(0x224)) F(0x224)=K(C); else F(0x224)=(f32)(F(0x224)-v54);
 if(F(0x224)>F(0x23c)) F(0x224)-=F(0x23c); else F(0x224)=K(C);
 if(!(v54>K(C))) {
  v60=K(14); if(!(U(0)&0x2000)) v60=K(130);
  if(arg1<K(C)) v2=(f32)(v2*(f32)(K(1C)*v60));
  else if(v2<K(C)) v2=(f32)(v2*(f32)(K(1C)*v60));
 }
 if(B(0x241)) {
  F(0x224)=(f32)(F(0x224)*(f32)(K(14)-(f32)(K(38)*sq_f32((f32)((f32)(u32)B(0x240)/(f32)(K(25C)*(f32)(u32)B(0x241)))))));
  if(B(0x240)>B(0x241) || F(0x224)<=K(C)) { B(0x240)=0; B(0x241)=0; }
  else B(0x240)++;
 }
 v1=U(0);
 if(v1&0x80) {
  v66=(f32)(F(0x17c)/K(16C)); if(v66>K(14)) v66=K(14);
  v2=(f32)(v2*(f32)(K(68)-(f32)(K(98)*v66)));
 }
 if(v1&0x200020) { if(F(8)>K(44)) v2=K(268)*v2; else v2=K(264)*v2; }
 else v2=K(44)*v2;
 return v2;
}
/* fzgx:end fn_1_26F34 */

/* fzgx:begin fn_1_278B8 noprologue */
#include "types.h"
#include "psvec.h"
#include "game/main_rel/camera_types.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 52.0f;
    s = 0.0625f;
    s = 45.0f;
    s = 0.0f;
    s = 1.7000000476837158f;
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.5f;
    d = 4503599627370496.0;
    s = 40.0f;
    s = 348.0f;
    s = 36.0f;
    s = 4.0f;
    s = 0.6000000238418579f;
    s = 5.0f;
    s = 0.05000000074505806f;
    s = 1000.0f;
    s = 8.0f;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 216.0;
    d = 2.0;
    s = 0.25f;
    s = 0.07000000029802322f;
    s = 0.20000000298023224f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.834999918937683f;
}
static const unsigned long fzgx_pool_table6[1] = {0xAE147AE1};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.0f;
    s = 1.7999999523162842f;
    s = 1.399999976158142f;
    s = 1.5f;
    s = 1.2000000476837158f;
    s = 2.299999952316284f;
    s = 0.4000000059604645f;
    s = 3.200000047683716f;
    s = 0.15000000596046448f;
    s = -0.25f;
    s = 0.1599999964237213f;
    s = 0.11999999731779099f;
    s = 0.07999999821186066f;
    s = 0.44999998807907104f;
    s = 0.699999988079071f;
}
static const unsigned long fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6000000238418579;
    s = 0.3100000023841858f;
    s = 0.029999999329447746f;
    s = 0.009999999776482582f;
    s = 700.0f;
    s = 1.7674999237060547f;
}
static const unsigned long fzgx_pool_table10[1] = {0xA3D70A3D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5699999928474426f;
}
static const unsigned long fzgx_pool_table12[4] = {0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.10000000149011612f;
    s = 200.0f;
    s = 0.019999999552965164f;
    d = 0.009999999776482582;
    s = 0.03999999910593033f;
    s = 0.800000011920929f;
    d = 13.88888888888889;
    s = 13.88888931274414f;
    s = 1.1920928955078125e-07f;
    s = 800.0f;
    s = 0.949999988079071f;
    s = 2.200000047683716f;
    s = -0.5f;
    s = 0.0020000000949949026f;
    s = 0.0010000000474974513f;
    s = 0.30000001192092896f;
}
static const unsigned long fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    d = 0.1;
    s = 80.0f;
    s = 1700.0f;
    d = 90.0;
    s = 0.3333333432674408f;
    s = -5000.0f;
    s = 900.0f;
    s = -10000.0f;
    s = 10.0f;
    s = 100.0f;
    s = 400.0f;
    s = 0.9900000095367432f;
    s = 20.0f;
    s = 1.0099999904632568f;
    d = 1.0;
    d = 0.550000011920929;
    s = 3.4000000953674316f;
    s = 0.75f;
    s = 182.04444885253906f;
    s = -45.0f;
    d = 0.9259259259259259;
    d = 5.555555555555555;
    s = 1.1299999952316284f;
}
static const unsigned long fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.10000000149011612;
    d = 0.30000001192092896;
    d = 0.046296296296296294;
    s = 0.8999999761581421f;
    s = 1.1100000143051147f;
    d = 0.0023148148148148147;
    d = 0.5;
    d = 0.004629629629629629;
    d = 0.023148148148148147;
    s = 2000.0f;
    s = 500.0f;
    d = 0.2;
    s = 0.6399999856948853f;
    s = 0.3499999940395355f;
    d = 1.8518518518518519;
    d = 3.4000000953674316;
    d = 1.7000000476837158;
    d = 3.0;
    d = 1.5;
    s = -0.4000000059604645f;
}
static const unsigned long fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const unsigned long *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 3.240740740740741;
    s = -1.0f;
    s = 9.999999747378752e-05f;
    s = 0.014000000432133675f;
    s = 9.0f;
    s = 60.0f;
    s = 3.0f;
    s = 0.1666666716337204f;
    s = 1200.0f;
    s = 1600.0f;
}
static const unsigned long fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const unsigned long *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1000.0;
    d = 0.699999988079071;
    d = 1.1920928955078125e-07;
    s = 0.003000000026077032f;
    s = 0.125f;
}
#pragma section code_type ".text"
#pragma fp_contract off

struct fn_1_278B8_lbl_1_rodata_840 {
    u8 pad_0[0x8]; f32 unk_8; f32 unk_C; u8 pad_10[4];
    f32 unk_14; f32 unk_18; u8 pad_1C[4]; f64 unk_20;
    u8 pad_28[0xC]; f32 unk_34; f32 unk_38; u8 pad_3C[4];
    f32 unk_40; u8 pad_44[0xC]; f64 unk_50; u8 pad_58[0x10];
    f32 unk_68; u8 pad_6C[0xC]; f32 unk_78; u8 pad_7C[0x4C];
    f32 unk_C8; u8 pad_CC[0x38]; f32 unk_104; u8 pad_108[0x70];
    f32 unk_178; u8 pad_17C[0x1C]; f32 unk_198; f32 unk_19C;
    u8 pad_1A0[0x20]; f64 unk_1C0; u8 pad_1C8[0xA8];
    f64 unk_270; f64 unk_278; f64 unk_280; f32 unk_288; f32 unk_28C;
};
extern const f32 lbl_1_rodata_840[3];
extern f64 lbl_8006D0B4(f64);
extern f64 __fabs(f64);
extern f32 __fmadds(f32, f32, f32);
extern u32 fn_1_29044(u32, void *, void *);
extern void lbl_8006E1C0(void *, void *);
extern u32 mathutil_mtxA_rotate_y(u32);
extern void fn_8006E2B0(void *, Vec3 *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);

#pragma opt_common_subs off
f32 fn_1_278B8(u32 arg0, void *arg1, f32 arg2) {
    f64 tmp_call4;
    struct fn_1_278B8_lbl_1_rodata_840 *p_lbl_1_rodata_840;
    s32 v0;
    f32 tmp___fmadds;
    f32 v1, v2, v3;
    s16 v4;
    void *v5;
    f32 v6, v7;
    s32 v8;
    f32 v9, v10, v11, v12;
    u32 v13;
    s32 unk_1;
    f32 v15, v16, v17, v18, v19, v20;
    u32 v21;
    f32 v22, v23, v27, v25, v26, v24;
    f64 v28;
    u32 v29;
    f32 v31, v34;
    void *v35;
    f32 v36, v37;
    Vec3 loc_2C;
    Vec3 loc_20;
    Vec3 loc_14;
    Vec3 loc_8;
    f64 t3;
    v0 = (*(u32 *)((u8 *)arg1) & 4);
    psvec_sub((u8 *)arg1 + 20, (u8 *)arg1 + 32, &loc_2C);
    lbl_8006DAEC();
    v1 = (f32)(*(f32 *)((u8 *)arg0 + 508) * *(f32 *)((u8 *)arg0 + 32));
    v2 = 182.04444885253906f;
    v3 = -(v1 + (f32)(*(f32 *)((u8 *)arg0 + 504) * *(f32 *)((u8 *)arg0 + 28)));
    v6 = v3 < -45.0f ? -45.0f : (v3 > 45.0f ? 45.0f : v3);
    v4 = (s16)(s32)(v2 * v6);
    mathutil_mtxA_rotate_y((s16)(v4 / 2));
    v5 = &loc_2C;
    fn_8006E2B0(v5, (Vec3 *)v5);
    v1 = loc_2C.x * loc_2C.x;
    tmp___fmadds = __fmadds(loc_2C.y, loc_2C.y, v1);
    v1 = tmp___fmadds;
    tmp___fmadds = __fmadds(loc_2C.z, loc_2C.z, v1);
    v1 = tmp___fmadds;
    tmp_call4 = lbl_8006D0B4(v1);
    t3 = 216.0 * tmp_call4;
    v6 = 0.0f;
    loc_14.y = v6;
    loc_14.x = 1.0f;
    loc_14.z = v6;
    v7 = (f32)(t3 / 1000.0);
    v11 = loc_2C.x;
    v8 = 0;
    if (v0 == 0 && (*(u32 *)arg1 & 0x10) != 0) v8 = 1;
    v9 = v6;
    if (v8 != 0 || *(u8 *)((u8 *)arg0 + 1142) != 0) {
        v9 = 20.0f;
    } else {
        v10 = *(f32 *)((u8 *)arg0 + 12);
        v9 = v10;
        if ((*(u32 *)((u8 *)arg0 + 1420) & 4) != 0) {
            if (v0 != 0 && *(u8 *)((u8 *)arg0 + 407) < 30) {
                v9 = *(f32 *)((u8 *)arg0 + 40);
                if (v9 > v10) v9 = v10;
            }
        } else {
            if (v0 != 0 && *(u8 *)((u8 *)arg0 + 407) == 0)
                v9 = *(f32 *)((u8 *)arg0 + 40);
        }
    }
    if (__fabs(v11) < *(f32 *)((u8 *)arg0 + 40)) *(u32 *)arg1 &= ~0x10;
    unk_1 = 1;
    if (v0 == 0 && !(__fabs(*(f32 *)((u8 *)arg0 + 508)) > (f64)0.7f)) unk_1 = 0;
    if (__fabs(v11) > v9 && unk_1 != 0) {
        *(u32 *)arg1 |= 4;
        if (v11 < 0.0f) v9 = -v9;
        v11 = v9;
    } else {
        if (__fabs(v11) < 1.1920928955078125e-7) v11 = 0.0f;
        *(u32 *)arg1 &= ~4;
    }
    v13 = *(u32 *)arg0;
    if ((v13 & 0x03820000) != 0) v11 = 0.0f;
    if ((v13 & 0x08000000) != 0) {
        v11 *= 0.2f;
    } else if ((v13 & 0x80) != 0) {
        v17 = 0.01f * ((f32)*(u16 *)((u8 *)arg0 + 1248) - 4.0f);
        v18 = v17 < 0.0f ? 0.0f : (v17 > 0.05f ? 0.05f : v17);
        v11 *= v18;
    }
    if (0.0f != v11) {
        v19 = *(f32 *)((u8 *)arg0 + 16);
        v31 = v11 * *(f32 *)((u8 *)arg0 + 8);
        if (v19 < 0.1f && *(u8 *)((u8 *)arg0 + 1142) == 0) {
            v21 = *(u32 *)arg1;
            if ((v21 & 2) == 0 && (v13 & 0x40) == 0) {
                v22 = 0.2f;
                v23 = 1.0f;
                v24 = v23 - (f32)*(u8 *)((u8 *)arg0 + 534) / 20.0f;
                v25 = v7;
                if (v7 < v22) v25 = v22;
                else {
                    v26 = 0.8f;
                    if (v7 > v26) v25 = v26;
                }
                v27 = ((v25 - 0.2f) / 0.6f) * (v19 - 0.1f);
                if ((v21 & 4) != 0) v27 = 0.0f;
                else {
                    v28 = (f64)0.3f;
                    v27 *= v28 + (f64)0.7f * __fabs(*(f32 *)((u8 *)arg0 + 508));
                }
                v31 *= 0.1f + (f32)(v27 * v24);
            } else v31 *= 0.1f;
        } else v31 *= v19;
        v29 = *(u32 *)((u8 *)arg0 + 536);
        if (v29 >> 31) v31 *= 0.003f;
        else if ((v29 >> 29) & 1) v31 *= 2.0f;
        psvec_scale(&loc_14, v31, &loc_14);
        lbl_8006E1C0(&loc_14, &loc_20);
        psvec_add(&loc_20, (u8 *)arg1 + 76, (u8 *)arg1 + 76);
        if ((*(u32 *)arg1 & 4) != 0) v31 *= 0.6f;
        *(f32 *)((u8 *)arg0 + 1408) += v31;
    }
    lbl_8006DB30();
    loc_8 = *(Vec3 *)((u8 *)arg1 + 76);
    psvec_add(&loc_8, (u8 *)arg0 + 148, (u8 *)arg0 + 148);
    if (*(u8 *)((u8 *)arg0 + 534) < 6)
        fn_1_29044(arg0, (u8 *)arg1 + 8, (u8 *)arg1 + 76);
    v35 = &loc_8;
    fn_8006E2B0(v35, (Vec3 *)v35);
    if (v0 != 0 && (*(u32 *)arg0 & 0x02000000) == 0) arg2 *= *(f32 *)((u8 *)arg0 + 36);
    v37 = *(f32 *)((u8 *)arg0 + 164);
    *(f32 *)((u8 *)arg0 + 164) = v37 - (f32)(0.125f * arg2);
    return v37;
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_278B8 */

/* fzgx:begin fn_1_27DE4 noprologue */
#include "dolphin/types.h"
#include "psvec.h"

void fn_1_27DE4(void *arg0)
{
    f32 delta[3];
    if (!(*(u32 *)arg0 & 0x8000)) {
        psvec_sub((u8 *)arg0 + 0x7C, (u8 *)arg0 + 0x88, delta);
        psvec_add((u8 *)arg0 + 0x1D4, delta, (u8 *)arg0 + 0x1D4);
    }
}
/* fzgx:end fn_1_27DE4 */

/* fzgx:begin fn_1_27E34 noprologue */
#include "dolphin/types.h"
#include "psvec.h"
#include "dolphin/hw_regs.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 52.0f;
    s = 0.0625f;
    s = 45.0f;
    s = 0.0f;
    s = 1.7000000476837158f;
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.5f;
    d = 4503599627370496.0;
    s = 40.0f;
    s = 348.0f;
    s = 36.0f;
    s = 4.0f;
    s = 0.6000000238418579f;
    s = 5.0f;
    s = 0.05000000074505806f;
    s = 1000.0f;
    s = 8.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 216.0;
    d = 2.0;
    s = 0.25f;
    s = 0.07000000029802322f;
    s = 0.20000000298023224f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.834999918937683f;
}
static const u32 fzgx_pool_table6[1] = {0xAE147AE1};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.0f;
    s = 1.7999999523162842f;
    s = 1.399999976158142f;
    s = 1.5f;
    s = 1.2000000476837158f;
    s = 2.299999952316284f;
    s = 0.4000000059604645f;
    s = 3.200000047683716f;
    s = 0.15000000596046448f;
    s = -0.25f;
    s = 0.1599999964237213f;
    s = 0.11999999731779099f;
    s = 0.07999999821186066f;
    s = 0.44999998807907104f;
    s = 0.699999988079071f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6000000238418579;
    s = 0.3100000023841858f;
    s = 0.029999999329447746f;
    s = 0.009999999776482582f;
    s = 700.0f;
    s = 1.7674999237060547f;
}
static const u32 fzgx_pool_table10[1] = {0xA3D70A3D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5699999928474426f;
}
static const u32 fzgx_pool_table12[4] = {0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.10000000149011612f;
    s = 200.0f;
    s = 0.019999999552965164f;
    d = 0.009999999776482582;
    s = 0.03999999910593033f;
    s = 0.800000011920929f;
    d = 13.88888888888889;
    s = 13.88888931274414f;
    s = 1.1920928955078125e-07f;
    s = 800.0f;
    s = 0.949999988079071f;
    s = 2.200000047683716f;
    s = -0.5f;
    s = 0.0020000000949949026f;
    s = 0.0010000000474974513f;
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    d = 0.1;
    s = 80.0f;
    s = 1700.0f;
    d = 90.0;
    s = 0.3333333432674408f;
    s = -5000.0f;
    s = 900.0f;
    s = -10000.0f;
    s = 10.0f;
    s = 100.0f;
    s = 400.0f;
    s = 0.9900000095367432f;
    s = 20.0f;
    s = 1.0099999904632568f;
    d = 1.0;
    d = 0.550000011920929;
    s = 3.4000000953674316f;
    s = 0.75f;
    s = 182.04444885253906f;
    s = -45.0f;
    d = 0.9259259259259259;
    d = 5.555555555555555;
    s = 1.1299999952316284f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.10000000149011612;
    d = 0.30000001192092896;
    d = 0.046296296296296294;
    s = 0.8999999761581421f;
    s = 1.1100000143051147f;
    d = 0.0023148148148148147;
    d = 0.5;
    d = 0.004629629629629629;
    d = 0.023148148148148147;
    s = 2000.0f;
    s = 500.0f;
    d = 0.2;
    s = 0.6399999856948853f;
    s = 0.3499999940395355f;
    d = 1.8518518518518519;
    d = 3.4000000953674316;
    d = 1.7000000476837158;
    d = 3.0;
    d = 1.5;
    s = -0.4000000059604645f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 3.240740740740741;
    s = -1.0f;
    s = 9.999999747378752e-05f;
    s = 0.014000000432133675f;
    s = 9.0f;
    s = 60.0f;
    s = 3.0f;
    s = 0.1666666716337204f;
    s = 1200.0f;
    s = 1600.0f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1000.0;
    d = 0.699999988079071;
    d = 1.1920928955078125e-07;
    s = 0.003000000026077032f;
    s = 0.125f;
    s = -2000.0f;
    s = 600.0f;
}
#pragma section code_type ".text"
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    u32 flag;
    u8 pad_4[0x18];
    u32 f_1c;
    u8 pad_20[0x1c];
    u32 m_3c;
    u8 pad_40[0xc];
    u32 f_4c;
    u8 pad_50[0xc];
} Agg;

typedef struct {
    Agg *a;
    Agg *b;
} Group;

typedef struct {
    Agg * a;
    Agg * b;
    Agg list_a;
    Agg list_b;
} Ctx;

typedef struct {
    u8 pad_0[0x47c];
    u32 f_47c;
} MgrEntry;

typedef struct {
    u8 pad_0[0x24];
    u32 f_24;
    u8 pad_28[0xe4];
    u32 f_10c;
    u32 f_110;
    f32 f_114;
    u32 f_118;
    u8 pad_11c[0x5e4];
    u32 f_700;
} Mgr;

typedef struct {
    u32 flags;
    s16 f_4;
    u8 pad_6[0x1b6];
    Vec3 v_1bc;
    f32 v_1c8;
    u32 v_1cc;
    f32 v_1d0;
    Vec3 v_1d4;
    u8 pad_1e0[0x3c];
    u32 v_21c;
    u8 pad_220[0x268];
    Group *g_488;
    Group *g_48c;
    Group *g_490;
    Group *g_494;
    u8 pad_498[0x64];
    u32 v_4fc;
    u8 pad_500[0x11c];
    s32 v_61c;
} Object;

extern s16 fn_1_7B054(void);
extern s32 fn_1_2A500(void *, Vec3 *, Vec3 *, void *, u32, f32 *);
extern s32 fn_1_8C6D4(s16);
extern s32 fn_1_8C704(s16);
extern Mgr *fn_1_14F04(void);
extern void lbl_8006E1D8(Vec3 *, f32, f32, f32);

#pragma opt_dead_assignments off

#pragma opt_lifetimes on
#pragma opt_strength_reduction off
s32 fn_1_27E34(Object *arg0)
{
    f32 fzgx_value;
    Agg * fzgx_live;
    Ctx ctx;
    Vec3 tmp;
    Vec3 out;
    Vec3 cur;
    f32 dist;
    Agg * fzgx_live_2;
    Mgr *mgr;
    u32 mode;
    Object *obj = arg0;
    s32 ret;
    s32 a;
    s32 b;
    MgrEntry *ent;

    mode = 0x04060005;
    a = fn_1_8C704(obj->f_4);
    b = fn_1_8C6D4(obj->f_4);
    if (a < 0 || a == b) {
        mode |= 0x200000;
    }
    obj->v_4fc = 0;
    mgr = fn_1_14F04();
    lbl_8006E1D8(&tmp, 0.0f, -2000.0f, 0.0f);
    psvec_set(&cur, *(f32 *)(LC_BASE + 0x2C), *(f32 *)(LC_BASE + 0x1C), *(f32 *)(LC_BASE + 0x0C));
    obj->v_1d4 = tmp;

    if (fn_1_7B054() == 0x24 || fn_1_7B054() == 0x25) {
        Group *g = obj->g_488;
        Group *h;
        Group *j;
        Group *k;
        ctx.a = &ctx.list_a;
        ctx.b = &ctx.list_b;
        ctx.b->flag = 1;
        ctx.b->f_1c = g->b->f_1c;
        ctx.b->m_3c = g->b->m_3c;
        ctx.b->f_4c = g->b->f_4c;
        ctx.a->flag = 0;
        ctx.a->m_3c = g->a->m_3c;
        h = obj->g_48c;
        ctx.b->m_3c &= h->b->m_3c;
        ctx.a->m_3c &= h->a->m_3c;
        j = obj->g_490;
        ctx.b->m_3c &= j->b->m_3c;
        ctx.a->m_3c &= j->a->m_3c;
        k = obj->g_494;
        ctx.b->m_3c &= k->b->m_3c;
        ctx.a->m_3c &= k->a->m_3c;
        fn_1_14F04()->f_700 = (u32)&ctx;
    }

    if (fn_1_2A500(obj, &obj->v_1d4, &cur, &out, mode, &dist)) {
        dist = 20.0f + (dist - 2000.0f);
        if (dist <= 0.0f && !(obj->flags & 0x800)
            && (mgr->f_118 & 0x1C00000) != 0 && (mode & 0x200000) != 0) {
            if (!(mgr->f_118 & 0x800000) || fn_1_7B054() != 15) {
                dist = 1.1920928955078125e-07f;
            }
        }
        obj->v_4fc = mgr->f_24;
    } else {
        dist = 0.0f;
    }

    if (dist <= 0.0f) {
        ret = 0;
        obj->v_1bc.x = 0.0f;
        fzgx_value = 1.0f;
        obj->v_1bc.y = fzgx_value;
        obj->v_1bc.z = 0.0f;
        obj->v_1d4 = cur;
        obj->v_1c8 = 0.0f;
        obj->v_21c = 0;
        obj->v_61c = 0;
    } else {
        ret = 1;
        obj->v_1bc = out;
        obj->v_1c8 = dist;
        obj->v_1cc = mgr->f_110;
        obj->v_1d0 = mgr->f_114;
        ent = (MgrEntry *)((u8 *)mgr + (mgr->f_10c << 7));
        obj->v_21c = ent->f_47c;
        obj->v_61c = mgr->f_118;
    }
    return ret;
}
#pragma opt_strength_reduction reset

#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset
/* fzgx:end fn_1_27E34 */

/* fzgx:begin fn_1_28184 noprologue */
#include "types.h"
#include "psvec.h"
#include "game/vec3.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 52.0f;
    s = 0.0625f;
    s = 45.0f;
    s = 0.0f;
    s = 1.7000000476837158f;
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.5f;
    d = 4503599627370496.0;
    s = 40.0f;
    s = 348.0f;
    s = 36.0f;
    s = 4.0f;
    s = 0.6000000238418579f;
    s = 5.0f;
    s = 0.05000000074505806f;
    s = 1000.0f;
    s = 8.0f;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 216.0;
    d = 2.0;
    s = 0.25f;
    s = 0.07000000029802322f;
    s = 0.20000000298023224f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.834999918937683f;
}
static const unsigned long fzgx_pool_table6[1] = {0xAE147AE1};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.0f;
    s = 1.7999999523162842f;
    s = 1.399999976158142f;
    s = 1.5f;
    s = 1.2000000476837158f;
    s = 2.299999952316284f;
    s = 0.4000000059604645f;
    s = 3.200000047683716f;
    s = 0.15000000596046448f;
    s = -0.25f;
    s = 0.1599999964237213f;
    s = 0.11999999731779099f;
    s = 0.07999999821186066f;
    s = 0.44999998807907104f;
    s = 0.699999988079071f;
}
static const unsigned long fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6000000238418579;
    s = 0.3100000023841858f;
    s = 0.029999999329447746f;
    s = 0.009999999776482582f;
    s = 700.0f;
    s = 1.7674999237060547f;
}
static const unsigned long fzgx_pool_table10[1] = {0xA3D70A3D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5699999928474426f;
}
static const unsigned long fzgx_pool_table12[4] = {0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.10000000149011612f;
    s = 200.0f;
    s = 0.019999999552965164f;
    d = 0.009999999776482582;
    s = 0.03999999910593033f;
    s = 0.800000011920929f;
    d = 13.88888888888889;
    s = 13.88888931274414f;
    s = 1.1920928955078125e-07f;
    s = 800.0f;
    s = 0.949999988079071f;
    s = 2.200000047683716f;
    s = -0.5f;
    s = 0.0020000000949949026f;
    s = 0.0010000000474974513f;
    s = 0.30000001192092896f;
}
static const unsigned long fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    d = 0.1;
    s = 80.0f;
    s = 1700.0f;
    d = 90.0;
    s = 0.3333333432674408f;
    s = -5000.0f;
    s = 900.0f;
    s = -10000.0f;
    s = 10.0f;
    s = 100.0f;
    s = 400.0f;
    s = 0.9900000095367432f;
    s = 20.0f;
    s = 1.0099999904632568f;
    d = 1.0;
    d = 0.550000011920929;
    s = 3.4000000953674316f;
    s = 0.75f;
    s = 182.04444885253906f;
    s = -45.0f;
    d = 0.9259259259259259;
    d = 5.555555555555555;
    s = 1.1299999952316284f;
}
static const unsigned long fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.10000000149011612;
    d = 0.30000001192092896;
    d = 0.046296296296296294;
    s = 0.8999999761581421f;
    s = 1.1100000143051147f;
    d = 0.0023148148148148147;
    d = 0.5;
    d = 0.004629629629629629;
    d = 0.023148148148148147;
    s = 2000.0f;
    s = 500.0f;
    d = 0.2;
    s = 0.6399999856948853f;
    s = 0.3499999940395355f;
    d = 1.8518518518518519;
    d = 3.4000000953674316;
    d = 1.7000000476837158;
    d = 3.0;
    d = 1.5;
    s = -0.4000000059604645f;
}
static const unsigned long fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const unsigned long *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 3.240740740740741;
    s = -1.0f;
    s = 9.999999747378752e-05f;
    s = 0.014000000432133675f;
    s = 9.0f;
    s = 60.0f;
    s = 3.0f;
    s = 0.1666666716337204f;
    s = 1200.0f;
    s = 1600.0f;
}
static const unsigned long fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const unsigned long *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1000.0;
    d = 0.699999988079071;
    d = 1.1920928955078125e-07;
    s = 0.003000000026077032f;
    s = 0.125f;
    s = -2000.0f;
    s = 600.0f;
    s = 6.0f;
    s = 300.0f;
}
#pragma section code_type ".text"

typedef struct Racer28184 {
    u32 flags;          /* 0x000 */
    s16 id;             /* 0x004 */
    u8 pad_006[0x2];
    f32 unk_8;          /* 0x008 */
    u8 pad_00C[0x24];
    f32 unk_30;         /* 0x030 */
    u8 pad_034[0x48];
    Vec3 pos;           /* 0x07C */
    Vec3 center;        /* 0x088 */
    Vec3 vel;           /* 0x094 */
    u8 pad_0A0[0x24];
    f32 unk_C4;         /* 0x0C4 */
    f32 unk_C8;         /* 0x0C8 */
    u8 pad_0CC[0x20];
    u8 mtx[0x90];       /* 0x0EC */
    f32 unk_17C;        /* 0x17C */
    u8 pad_180[0x4];
    f32 unk_184;        /* 0x184 */
    u8 pad_188[0x34];
    Vec3 axis;          /* 0x1BC */
    u8 pad_1C8[0x4C];
    u16 unk_214;        /* 0x214 */
    u8 pad_216[0x2];
    u32 flags2;         /* 0x218 */
    u8 pad_21C[0x8];
    f32 unk_224;        /* 0x224 */
    u8 pad_228[0x284];
    f32 unk_4AC;        /* 0x4AC */
    u8 pad_4B0[0xE3];
    u8 unk_593;         /* 0x593 */
    u8 pad_594[0x46];
    u16 unk_5DA;        /* 0x5DA */
} Racer28184;

/* The TU's shared literal pool, addressed through one base register. */
struct fn_1_28184_Pool {
    u8 pad_0[0xC];
    f32 zero;           /* 0x00C */
    u8 pad_10[0x4];
    f32 one;            /* 0x014 */
    u8 pad_18[0x8];
    f64 u2f_bias;       /* 0x020 */
    u8 pad_28[0xC];
    f32 four;           /* 0x034 */
    f32 ratio_max;      /* 0x038 */
    u8 pad_3C[0x24];
    f32 quarter;        /* 0x060 */
    u8 pad_64[0x14];
    f32 two;            /* 0x078 */
    u8 pad_7C[0x4C];
    f32 ratio_min;      /* 0x0C8 */
    u8 pad_CC[0x48];
    f32 epsilon;        /* 0x114 */
    u8 pad_118[0x50];
    f32 ten;            /* 0x168 */
    u8 pad_16C[0xC];
    f32 twenty;         /* 0x178 */
    f32 speed_scale;    /* 0x17C */
    u8 pad_180[0x28];
    f64 delta_scale;    /* 0x1A8 */
    u8 pad_1B0[0x98];
    f32 minus_one;      /* 0x248 */
    u8 pad_24C[0x48];
    f32 threshold;      /* 0x294 */
    f32 six;            /* 0x298 */
};
#define lbl_1_rodata_84C (0.0f)
#define lbl_1_rodata_854 (1.0f)
#define lbl_1_rodata_860 (4503599627370496.0)
#define lbl_1_rodata_860__fzgx_offset_14 (4.0f)
#define lbl_1_rodata_860__fzgx_offset_18 (0.600000024f)
#define lbl_1_rodata_860__fzgx_offset_40 (0.25f)
#define lbl_1_rodata_860__fzgx_offset_58 (2.0f)
#define lbl_1_rodata_860__fzgx_offset_A8 (0.00999999978f)
#define lbl_1_rodata_954 (1.1920929e-07f)
#define lbl_1_rodata_954__fzgx_offset_54 (10.0f)
#define lbl_1_rodata_954__fzgx_offset_64 (20.0f)
#define lbl_1_rodata_954__fzgx_offset_68 (1.00999999f)
#define lbl_1_rodata_954__fzgx_offset_94 (5.5555555555555554)
#define lbl_1_rodata_954__fzgx_offset_134 (-1.0f)
#define lbl_1_rodata_954__fzgx_offset_180 (600.0f)
#define lbl_1_rodata_954__fzgx_offset_184 (6.0f)

extern int fn_1_163BC(Vec3 *, Vec3 *, u32, u32);
extern u32 fn_1_8C66C(s32);
extern void fn_1_A33F0(s32, f32);
extern void fn_1_694A4(s32, Vec3 *, Vec3 *, f32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D6FC(Vec3 *, Vec3 *);
extern void lbl_8006D5F0(Vec3 *, f32, Vec3 *);
extern void lbl_8006DBAC(void *);
extern void fn_8006E2B0(Vec3 *, Vec3 *);
extern void lbl_8006E1C0(Vec3 *, Vec3 *);

#pragma fp_contract on
#pragma opt_common_subs off
static inline f32 norm28184(Vec3 *v) {
    f32 n = v->x * v->x;
    n += v->y * v->y;
    n += v->z * v->z;
    return lbl_8006D0B4(n);
}
static inline f32 square28184(f32 x) {
    return x * x;
}
static inline f32 add28184(f32 k, f32 x, f32 y) {
    f32 product = k * x;
    return y + product;
}
#pragma fp_contract on
void fn_1_28184(Racer28184 *r) {
    struct fn_1_28184_Pool *c;
    Vec3 pos;
    Vec3 proj;
    Vec3 delta;
    Vec3 b;
    Vec3 a;
    Vec3 d;
    f32 len;
    f32 t;
    f32 sign;
    f32 dist;
    f32 s;
    f32 speed;
    f32 ratio;
    f32 scale;

    pos = r->pos;
    lbl_8006DAEC();
    if (fn_1_163BC(&pos, &r->center, 0x4000, fn_1_8C66C(r->id)) != 0) {
        psvec_sub(&r->pos, &r->center, &a);
        psvec_sub(&pos, &r->center, &d);
        len = norm28184(&a);
        scale = a.x * d.x;
        scale = __fmadds(a.y, d.y, scale);
        scale += a.z * d.z;
        t = scale / (len * len);
        psvec_scale(&a, t, &proj);
        psvec_add(&proj, &r->center, &proj);
        if (r->unk_17C > lbl_1_rodata_954__fzgx_offset_180) {
            sign = lbl_1_rodata_854;
        } else {
            sign = lbl_1_rodata_954__fzgx_offset_134;
        }
        psvec_sub(&proj, &pos, &d);
        dist = norm28184(&d);
        psvec_scale(&r->axis, (dist * lbl_8006D6FC(&r->axis, &d)), &b);
        psvec_add(&b, &pos, &b);
        psvec_sub(&proj, &b, &d);
        scale = norm28184(&d);
        dist = scale / lbl_1_rodata_860__fzgx_offset_14;
        s = sign * lbl_8006D0B4(lbl_1_rodata_854 - square28184(dist));
        dist = s * s;
        scale = lbl_8006D0B4(lbl_1_rodata_854 - dist);
        if (scale > lbl_1_rodata_954) {
            lbl_8006D5F0(&d, scale, &d);
        } else {
            d.x = lbl_1_rodata_84C;
            d.y = lbl_1_rodata_84C;
            d.z = lbl_1_rodata_84C;
        }
        if (s > lbl_1_rodata_954) {
            lbl_8006D5F0(&a, s, &a);
        } else {
            a.x = lbl_1_rodata_84C;
            a.y = lbl_1_rodata_84C;
            a.z = lbl_1_rodata_84C;
        }
        psvec_add(&d, &a, &a);
        lbl_8006D5F0(&a, lbl_1_rodata_860__fzgx_offset_14, &a);
        psvec_add(&a, &b, &r->pos);
        psvec_sub(&r->pos, &pos, &delta);
        lbl_8006DBAC(r->mtx);
        fn_8006E2B0(&delta, &delta);
        ratio = norm28184(&delta) / lbl_1_rodata_954__fzgx_offset_64;
        fn_1_A33F0(r->id, ratio < lbl_1_rodata_860__fzgx_offset_A8 ? lbl_1_rodata_860__fzgx_offset_A8
                          : (ratio > lbl_1_rodata_860__fzgx_offset_18 ? lbl_1_rodata_860__fzgx_offset_18 : ratio));
        lbl_8006D5F0(&delta, lbl_1_rodata_954__fzgx_offset_94 * r->unk_8, &delta);
        r->unk_C4 = add28184(lbl_1_rodata_954__fzgx_offset_184, delta.x, r->unk_C4);
        r->unk_C8 = add28184(lbl_1_rodata_860__fzgx_offset_58, delta.z, r->unk_C8);
        lbl_8006E1C0(&delta, &delta);
        psvec_add(&delta, &r->vel, &r->vel);
        speed = lbl_1_rodata_954__fzgx_offset_64;
        r->flags2 |= 0x40000000;
        if (r->unk_214 == 0 && r->unk_593 == 0) {
            speed *= r->unk_30;
            if (!(r->flags & 0x200) && speed > lbl_1_rodata_954__fzgx_offset_64) {
                speed = lbl_1_rodata_954__fzgx_offset_64;
            }
            scale = lbl_1_rodata_954__fzgx_offset_68 * r->unk_5DA;
            if (speed > scale) {
                speed = scale;
            }
            r->unk_4AC = speed;
            scale = r->unk_184 - r->unk_4AC;
            r->unk_184 = scale;
            if (scale < lbl_1_rodata_84C) {
                if (!(r->flags & 0x10080)) {
                    r->unk_593 = 60;
                }
                r->flags |= 0x80;
                r->unk_184 = lbl_1_rodata_84C;
                r->unk_224 = lbl_1_rodata_84C;
            }
        }
        fn_1_694A4(r->id, &proj, &delta, ratio / lbl_1_rodata_954__fzgx_offset_54);
    }
    lbl_8006DB30();
}
/* fzgx:end fn_1_28184 */

/* fzgx:begin fn_1_28660 */
void fn_1_28660(Fn_1_28660 *self) {
    int result;
    int mask;

    lbl_8006DAEC();

    mask = 0x88;
    if ((self->field58c & 0x2) == 0) {
        mask |= 0x10;
    }
    if ((self->field4fc & 0x00100000) == 0) {
        mask |= 0x2;
    }
    if ((self->field4fc & 0x00080000) == 0) {
        mask |= 0x20;
    }
    if ((self->field4fc & 0x00040000) == 0) {
        mask |= 0x40;
    }
    if ((self->field4fc & 0x00020000) == 0) {
        mask |= 0x80;
    }

    if ((self->field00 & 0x2) != 0) {
        result = 0;
    } else {
        result = fn_1_163BC((char *)self + 0x7c, (char *)self + 0x88,
            mask, (int)fn_1_8C66C(self->field04));
    }

    if ((result & 0x8) != 0) {
        self->field00 |= 0x00600000;
        self->field218 |= 0x10000000;
    }
    if ((self->field4fc & 0x00100000) != 0 ||
        (result & 0x2) != 0) {
        if ((self->field00 & 0x80) == 0) {
            self->field58c |= 1;
            self->field218 |= 0x08000000;
        }
    }
    if ((self->field00 & 0x20) == 0) {
        if ((self->field4fc & 0x00040000) != 0 ||
            (result & 0x40) != 0) {
            self->field218 |= 0x20000000;
        }
    }
    if ((self->field4fc & 0x00080000) != 0 ||
        (result & 0x20) != 0) {
        self->field218 |= 0x80000000u;
    }
    if ((result & 0x10) != 0) {
        self->field218 |= 0x04000000;
    }
    if ((self->field4fc & 0x00020000) != 0 ||
        (result & 0x80) != 0) {
        self->field218 |= 0x02000000;
    }

    lbl_8006DB30();
}
/* fzgx:end fn_1_28660 */

/* fzgx:begin fn_1_287E8 */
/* Shared literal pool primer: retail's TU pool (lbl_1_rodata_840) in address order,
   so this function's 0.0f / 0.5f / 300.0f land at 0xc / 0x1c / 0x29c. */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 52.0f;
    s = 0.0625f;
    s = 45.0f;
    s = 0.0f;
    s = 1.7000000476837158f;
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.5f;
    d = 4503599627370496.0;
    s = 40.0f;
    s = 348.0f;
    s = 36.0f;
    s = 4.0f;
    s = 0.6000000238418579f;
    s = 5.0f;
    s = 0.05000000074505806f;
    s = 1000.0f;
    s = 8.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 216.0;
    d = 2.0;
    s = 0.25f;
    s = 0.07000000029802322f;
    s = 0.20000000298023224f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.834999918937683f;
}
static const u32 fzgx_pool_table6[1] = {0xAE147AE1};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.0f;
    s = 1.7999999523162842f;
    s = 1.399999976158142f;
    s = 1.5f;
    s = 1.2000000476837158f;
    s = 2.299999952316284f;
    s = 0.4000000059604645f;
    s = 3.200000047683716f;
    s = 0.15000000596046448f;
    s = -0.25f;
    s = 0.1599999964237213f;
    s = 0.11999999731779099f;
    s = 0.07999999821186066f;
    s = 0.44999998807907104f;
    s = 0.699999988079071f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6000000238418579;
    s = 0.3100000023841858f;
    s = 0.029999999329447746f;
    s = 0.009999999776482582f;
    s = 700.0f;
    s = 1.7674999237060547f;
}
static const u32 fzgx_pool_table10[1] = {0xA3D70A3D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5699999928474426f;
}
static const u32 fzgx_pool_table12[4] = {0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.10000000149011612f;
    s = 200.0f;
    s = 0.019999999552965164f;
    d = 0.009999999776482582;
    s = 0.03999999910593033f;
    s = 0.800000011920929f;
    d = 13.88888888888889;
    s = 13.88888931274414f;
}
static const u32 fzgx_pool_table14[1] = {0x34000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 0.949999988079071f;
    s = 2.200000047683716f;
    s = -0.5f;
    s = 0.0020000000949949026f;
    s = 0.0010000000474974513f;
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    d = 0.1;
    s = 80.0f;
    s = 1700.0f;
    d = 90.0;
    s = 0.3333333432674408f;
    s = -5000.0f;
    s = 900.0f;
    s = -10000.0f;
    s = 10.0f;
    s = 100.0f;
    s = 400.0f;
    s = 0.9900000095367432f;
    s = 20.0f;
    s = 1.0099999904632568f;
    d = 1.0;
    d = 0.550000011920929;
    s = 3.4000000953674316f;
    s = 0.75f;
    s = 182.04444885253906f;
    s = -45.0f;
    d = 0.9259259259259259;
    d = 5.555555555555555;
    s = 1.1299999952316284f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.10000000149011612;
    d = 0.30000001192092896;
    d = 0.046296296296296294;
    s = 0.8999999761581421f;
    s = 1.1100000143051147f;
    d = 0.0023148148148148147;
    d = 0.5;
    d = 0.004629629629629629;
    d = 0.023148148148148147;
    s = 2000.0f;
    s = 500.0f;
    d = 0.2;
    s = 0.6399999856948853f;
    s = 0.3499999940395355f;
    d = 1.8518518518518519;
    d = 3.4000000953674316;
    d = 1.7000000476837158;
    d = 3.0;
    d = 1.5;
    s = -0.4000000059604645f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 3.240740740740741;
    s = -1.0f;
    s = 9.999999747378752e-05f;
    s = 0.014000000432133675f;
    s = 9.0f;
    s = 60.0f;
    s = 3.0f;
    s = 0.1666666716337204f;
    s = 1200.0f;
    s = 1600.0f;
}
static const u32 fzgx_pool_table22[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1000.0;
    d = 0.699999988079071;
    d = 1.1920928955078125e-07;
    s = 0.003000000026077032f;
    s = 0.125f;
    s = -2000.0f;
    s = 600.0f;
    s = 6.0f;
    s = 300.0f;
}
#pragma section code_type ".text"

void fn_1_287E8(struct fn_1_287E8_Arg0 *p) {
    u32 flags;
    u8 count;

    if (p->unk_17C < 300.0f) {
        if (p->unk_190 == 0) {
            p->flags &= ~0x8;
        }
        p->flags &= ~0x20000;
    }
    if (p->unk_480 != 0) {
        p->flags &= ~0x8;
    }

    if (p->flags & 0x8) {
        if (p->unk_190 == 0) {
            p->unk_190 = 0x40000;
            p->unk_194 = 0x1000;
            if (p->unk_1FC > 0.0f) {
                p->unk_196 = 0;
            } else {
                p->unk_196 = 1;
            }
        } else {
            if (p->unk_190 > p->unk_194) {
                p->unk_190 -= p->unk_194;
                if (p->unk_190 < 0x20000) {
                    p->unk_194 -= 0x41;
                    if (p->unk_194 < 0x50) {
                        p->unk_194 = 0x50;
                    }
                }
            } else {
                p->unk_190 = 0;
                p->unk_194 = 0;
                p->flags &= ~0x8;
            }
        }
        p->flags &= ~0x20000;
    } else {
        p->unk_190 = 0;
    }

    flags = p->flags;
    if (flags & 0x20000) {
        count = p->unk_480;
        if (count == 0) {
            p->unk_480 = 6;
        } else if (count == 1) {
            p->flags = flags & ~0x20000;
        } else {
            p->unk_480 = count - 1;
        }
        if ((p->flags & 0x02800000) || p->unk_200 < 0.5f) {
            p->flags &= ~0x20000;
            p->unk_480 = 1;
        }
    } else {
        p->unk_480 = 0;
    }

    if (p->unk_4C4 != 0) {
        p->unk_4C4--;
    }
    if (!(p->flags & 0x20008)) {
        p->unk_212 = 0;
    }
}
/* fzgx:end fn_1_287E8 */

/* fzgx:begin fn_1_289B4 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 52.0f;
    s = 0.0625f;
    s = 45.0f;
    s = 0.0f;
    s = 1.7000000476837158f;
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.5f;
    d = 4503599627370496.0;
    s = 40.0f;
    s = 348.0f;
    s = 36.0f;
    s = 4.0f;
    s = 0.6000000238418579f;
    s = 5.0f;
    s = 0.05000000074505806f;
    s = 1000.0f;
    s = 8.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 216.0;
    d = 2.0;
    s = 0.25f;
    s = 0.07000000029802322f;
    s = 0.20000000298023224f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.834999918937683f;
}
static const u32 fzgx_pool_table6[1] = {0xAE147AE1};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.0f;
    s = 1.7999999523162842f;
    s = 1.399999976158142f;
    s = 1.5f;
    s = 1.2000000476837158f;
    s = 2.299999952316284f;
    s = 0.4000000059604645f;
    s = 3.200000047683716f;
    s = 0.15000000596046448f;
    s = -0.25f;
    s = 0.1599999964237213f;
    s = 0.11999999731779099f;
    s = 0.07999999821186066f;
    s = 0.44999998807907104f;
    s = 0.699999988079071f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6000000238418579;
    s = 0.3100000023841858f;
    s = 0.029999999329447746f;
    s = 0.009999999776482582f;
    s = 700.0f;
    s = 1.7674999237060547f;
}
static const u32 fzgx_pool_table10[1] = {0xA3D70A3D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5699999928474426f;
}
static const u32 fzgx_pool_table12[4] = {0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.10000000149011612f;
    s = 200.0f;
    s = 0.019999999552965164f;
    d = 0.009999999776482582;
    s = 0.03999999910593033f;
    s = 0.800000011920929f;
    d = 13.88888888888889;
    s = 13.88888931274414f;
    s = 1.1920928955078125e-07f;
    s = 800.0f;
    s = 0.949999988079071f;
    s = 2.200000047683716f;
    s = -0.5f;
    s = 0.0020000000949949026f;
    s = 0.0010000000474974513f;
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    d = 0.1;
    s = 80.0f;
    s = 1700.0f;
    d = 90.0;
    s = 0.3333333432674408f;
    s = -5000.0f;
    s = 900.0f;
    s = -10000.0f;
    s = 10.0f;
    s = 100.0f;
    s = 400.0f;
    s = 0.9900000095367432f;
    s = 20.0f;
    s = 1.0099999904632568f;
    d = 1.0;
    d = 0.550000011920929;
    s = 3.4000000953674316f;
    s = 0.75f;
    s = 182.04444885253906f;
    s = -45.0f;
    d = 0.9259259259259259;
    d = 5.555555555555555;
    s = 1.1299999952316284f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.10000000149011612;
    d = 0.30000001192092896;
    d = 0.046296296296296294;
    s = 0.8999999761581421f;
    s = 1.1100000143051147f;
    d = 0.0023148148148148147;
    d = 0.5;
    d = 0.004629629629629629;
    d = 0.023148148148148147;
    s = 2000.0f;
    s = 500.0f;
    d = 0.2;
    s = 0.6399999856948853f;
    s = 0.3499999940395355f;
    d = 1.8518518518518519;
    d = 3.4000000953674316;
    d = 1.7000000476837158;
    d = 3.0;
    d = 1.5;
    s = -0.4000000059604645f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 3.240740740740741;
    s = -1.0f;
    s = 9.999999747378752e-05f;
    s = 0.014000000432133675f;
    s = 9.0f;
    s = 60.0f;
    s = 3.0f;
    s = 0.1666666716337204f;
    s = 1200.0f;
    s = 1600.0f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1000.0;
    d = 0.699999988079071;
    d = 1.1920928955078125e-07;
    s = 0.003000000026077032f;
    s = 0.125f;
    s = -2000.0f;
    s = 600.0f;
    s = 6.0f;
    s = 300.0f;
    s = 1.1111111640930176f;
    s = 10000.0f;
    s = -3.0f;
    s = 10430.3779296875f;
}
#pragma section code_type ".text"





/* Keep the translation loads in their own registers (retail stores x, y, z from f2, f1, f0),
 * as in fn_1_2BBD0. */
#pragma opt_propagation off
void fn_1_289B4(Body *p, u32 *out, void *arg2) {
    s32 i;
    s32 pending;
    u8 *base;
    Part *part;
    u8 *base2;
    u8 *q;
    s32 allGrounded;
    s32 j;
    f32 len;
    f32 ang;
    f32 a;
    f32 b;
    f32 z, y, x;
    f32 vx, vy, vz;
    f32 zero;
    u16 limit;
    u32 flags;
    u8 v;

    if (p->flags & 0x8000) {
        p->f1FC = 0.0f;
        p->f1F4 = 0.0f;
        p->f204 = 0.0f;
        p->f1F8 = 0.0f;
        p->flags &= ~0x00020048;
    }
    pending = (p->f218 >> 28) & 1;
    p->flags &= ~0x405C0016;
    p->f58C &= ~0x300;
    p->f218 = 0;
    if (!(p->flags & 0x10000000)) {
        fn_1_28660( (Fn_1_28660 *)(Body *)(p));
    }
    if (pending) {
        p->flags &= ~0x400000;
    }

    lbl_8006DBAC(p->mtx11C);
    /* translation column of the locked-cache matrix */
    x = p->prevPos.x;
    y = p->prevPos.y;
    z = p->prevPos.z;
    *(f32 *)(0xE0000000 + 0x0C) = x;
    *(f32 *)(0xE0000000 + 0x1C) = y;
    *(f32 *)(0xE0000000 + 0x2C) = z;
    lbl_8006DD14(p->mtxEC, p->mtx11C);
    p->pos4C8 = p->pos;
    p->prevPos = p->pos4C8;

    base = (u8 *)p;
    for (i = 0; i < 4; i++) {
        part = (Part *)(base + 0x244);
        fn_1_2A638( (void *)(Body *)(p), (Fn_1_2A638 *)(Part *)(part));
        if (part->flags & 4) {
            p->parts[0].flags |= 4;
            p->parts[1].flags |= 4;
            p->parts[2].flags |= 4;
            p->parts[3].flags |= 4;
        }
        base += 0x5c;
    }

    lbl_8006DBAC(p->mtxEC);
    {
        f32 z, y, x;

        x = p->pos.x;
        y = p->pos.y;
        z = p->pos.z;
        *(f32 *)(0xE0000000 + 0x0C) = x;
        *(f32 *)(0xE0000000 + 0x1C) = y;
        *(f32 *)(0xE0000000 + 0x2C) = z;
    }

    if (p->flags & 0x400) {
        *out = fn_1_2AF0C(p, arg2);
    } else {
        *out = 0;
    }

    base2 = (u8 *)p;
    q = (u8 *)p;
    allGrounded = 1;
    for (j = 0; j < 4; j++) {
        if (!(((Part *)(base2 + 0x244))->flags & 2)) {
            allGrounded = 0;
        }
        fn_1_2A678( (Fn_1_2A678_Source *)(Body *)(p), (Fn_1_2A678_Dest *)(void *)(q + 0x3B4));
        base2 += 0x5c;
        q += 0x30;
    }

    if (allGrounded) {
        p->flags |= 2;
        p->b483 += (p->b483 < 180);
        if (p->b483 > 10) {
            p->flags |= 4;
        }
    } else {
        if (p->b483 != 0) {
            p->flags |= 0x10;
        }
        p->b483 = 0;
        p->flags &= ~4;
        p->f58C &= ~2;
    }

    p->f580 = 0.0f;
    p->fC4 *= 0.8f;
    p->fC8 *= 0.9f;

    if (p->flags & 0x400) {
        p->b481 += (p->b481 != 255);
    }

    if ((p->flags & 0x10000) || ((p->f218 >> 27) & 1)) {
        p->f184 += 1.1111111640930176f;
        limit = p->h5DA;
        if (p->f184 > limit) {
            p->f184 = limit;
        }
    }

    vx = p->vel.x;
    vy = p->vel.y;
    vz = p->vel.z;
    len = vx * vx;
    len += vy * vy;
    len += vz * vz;
    len = lbl_8006D0B4(len);
    p->f17C = 216.0 * (len / p->mass);

    flags = p->flags;
    if ((flags & 0x8000000) && !(flags & 2)) {
        if (p->f17C < 10.0f) {
            p->vel.x = 0.0f;
            p->vel.y = 0.0f;
            p->vel.z = 0.0f;
        } else {
            psvec_scale(&p->vel.x, 0.8999999761581421f, &p->vel.x);
        }
    }

    fn_1_287E8( (struct fn_1_287E8_Arg0 *)(Body *)(p));

    if (p->b4C5 != 0) {
        p->b4C5--;
    } else if (p->flags & 0x2000000) {
        p->b4C5 = 6;
    }
    if (p->b593 != 0) {
        p->b593--;
    }

    fn_8006E2B0(&p->vel, &p->fB8);
    lbl_8006DAEC();
    a = p->f1FC * p->f20;
    b = p->f1F8 * p->f1C;
    ang = -(a + b);
    mathutil_mtxA_rotate_y((s32)(182.04444885253906f * (ang < -45.0f ? -45.0f : ang > 45.0f ? 45.0f : ang)));
    fn_8006E2B0(&p->vel, &p->fCC);
    p->fD0 = 0.0f;
    lbl_8006DB30();

    p->pos1E0 = p->pos;
    p->f47C++;

    v = p->b4C3;
    if (v != 0) {
        if ((v & 0xF) - 1 != 0) {
            p->b4C3 = (v & 0xF0) | ((v & 0xF) - 1);
        } else {
            p->b4C3 = 0;
        }
    }

    zero = 0.0f;
    p->v4B4.x = 10000.0f;
    p->v4B4.y = zero;
    p->v4B4.z = zero;
    if (p->b4C0 != 0) {
        p->b4C0--;
    }
    v = p->b592;
    if (v != 0) {
        if (v < 120) {
            p->b592 = v + 1;
        } else {
            p->b592 = 0;
        }
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_289B4 */

/* fzgx:begin fn_1_28F08 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 52.0f;
    s = 0.0625f;
    s = 45.0f;
    s = 0.0f;
    s = 1.7000000476837158f;
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.5f;
    d = 4503599627370496.0;
    s = 40.0f;
    s = 348.0f;
    s = 36.0f;
    s = 4.0f;
    s = 0.6000000238418579f;
    s = 5.0f;
    s = 0.05000000074505806f;
    s = 1000.0f;
    s = 8.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 216.0;
    d = 2.0;
    s = 0.25f;
    s = 0.07000000029802322f;
    s = 0.20000000298023224f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.834999918937683f;
}
static const u32 fzgx_pool_table6[1] = {0xAE147AE1};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.0f;
    s = 1.7999999523162842f;
    s = 1.399999976158142f;
    s = 1.5f;
    s = 1.2000000476837158f;
    s = 2.299999952316284f;
    s = 0.4000000059604645f;
    s = 3.200000047683716f;
    s = 0.15000000596046448f;
    s = -0.25f;
    s = 0.1599999964237213f;
    s = 0.11999999731779099f;
    s = 0.07999999821186066f;
    s = 0.44999998807907104f;
    s = 0.699999988079071f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6000000238418579;
    s = 0.3100000023841858f;
    s = 0.029999999329447746f;
    s = 0.009999999776482582f;
    s = 700.0f;
    s = 1.7674999237060547f;
}
static const u32 fzgx_pool_table10[1] = {0xA3D70A3D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5699999928474426f;
}
static const u32 fzgx_pool_table12[4] = {0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.10000000149011612f;
    s = 200.0f;
    s = 0.019999999552965164f;
    d = 0.009999999776482582;
    s = 0.03999999910593033f;
    s = 0.800000011920929f;
    d = 13.88888888888889;
    s = 13.88888931274414f;
    s = 1.1920928955078125e-07f;
    s = 800.0f;
    s = 0.949999988079071f;
    s = 2.200000047683716f;
    s = -0.5f;
    s = 0.0020000000949949026f;
    s = 0.0010000000474974513f;
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    d = 0.1;
    s = 80.0f;
    s = 1700.0f;
    d = 90.0;
    s = 0.3333333432674408f;
    s = -5000.0f;
    s = 900.0f;
    s = -10000.0f;
    s = 10.0f;
    s = 100.0f;
    s = 400.0f;
    s = 0.9900000095367432f;
    s = 20.0f;
    s = 1.0099999904632568f;
    d = 1.0;
    d = 0.550000011920929;
    s = 3.4000000953674316f;
    s = 0.75f;
    s = 182.04444885253906f;
    s = -45.0f;
    d = 0.9259259259259259;
    d = 5.555555555555555;
    s = 1.1299999952316284f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.10000000149011612;
    d = 0.30000001192092896;
    d = 0.046296296296296294;
    s = 0.8999999761581421f;
    s = 1.1100000143051147f;
    d = 0.0023148148148148147;
    d = 0.5;
    d = 0.004629629629629629;
    d = 0.023148148148148147;
    s = 2000.0f;
    s = 500.0f;
    d = 0.2;
    s = 0.6399999856948853f;
    s = 0.3499999940395355f;
    d = 1.8518518518518519;
    d = 3.4000000953674316;
    d = 1.7000000476837158;
    d = 3.0;
    d = 1.5;
    s = -0.4000000059604645f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 3.240740740740741;
    s = -1.0f;
    s = 9.999999747378752e-05f;
    s = 0.014000000432133675f;
    s = 9.0f;
    s = 60.0f;
    s = 3.0f;
    s = 0.1666666716337204f;
    s = 1200.0f;
    s = 1600.0f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1000.0;
    d = 0.699999988079071;
    d = 1.1920928955078125e-07;
    s = 0.003000000026077032f;
    s = 0.125f;
    s = -2000.0f;
    s = 600.0f;
    s = 6.0f;
    s = 300.0f;
    s = 1.1111111640930176f;
    s = 10000.0f;
    s = -3.0f;
    s = 10430.3779296875f;
}
#pragma section code_type ".text"

typedef f32 Mtx34[3][4];

typedef struct StcoliRot {
    u8 pad[0xac];
    f32 divX;
    f32 divY;
    f32 divZ;
} StcoliRot;


void fn_1_28F08(StcoliRot *rot, Vec3f *p, f32 yOff)
{
    Quat v;
    Mtx34 m;
    f32 len;
    f32 x, y, z;

    v.x = p->x;
    v.y = p->y + yOff;
    v.z = p->z;

    if (v.x > 3.0f) {
        v.x -= 3.0f;
    } else if (v.x < -3.0f) {
        v.x += 3.0f;
    } else {
        v.x = 0.0f;
    }

    if (v.z > 3.0f) {
        v.z -= 3.0f;
    } else if (v.z < -3.0f) {
        v.z += 3.0f;
    } else {
        v.z = 0.0f;
    }

    x = v.x / rot->divX;
    v.x = x;
    len = x * x;
    y = v.y / rot->divY;
    v.y = y;
    len += y * y;
    z = v.z / rot->divZ;
    v.z = z;
    len += z * z;

    len = lbl_8006D0B4(len);
    fn_8006E7E4(&v, (Vec3f *)&v, (s32)(10430.3779296875f * len));
    lbl_8006DAEC();
    mathutil_mtxA_from_quat( (void *)(Quat *)(&v));
    lbl_8006DB74(m);
    lbl_8006DB30();
    lbl_8006DFC4(m);
}
/* fzgx:end fn_1_28F08 */

/* fzgx:begin fn_1_29044 noprologue */
#include "game/vec3.h"
#include "psvec.h"

extern void fn_8006E2B0(void *, Vec3 *);

typedef struct {
    u8 pad[0xA0];
    Vec3 v;
} Object29044;

/* Volatile preserves the ordered input stack copy before the call. */
static inline void copy_vec(volatile Vec3 *out, f32 z, f32 y, f32 x)
{
    out->x = x;
    out->y = y;
    out->z = z;
}

static inline void cross_vec(const Vec3 *a, const Vec3 *b, Vec3 *out)
{
    f32 ax = a->x;
    f32 ay = a->y;
    f32 az = a->z;
    f32 bx = b->x;
    f32 by = b->y;
    f32 bz = b->z;
    f32 x, y, z;
    x = ay * bz;
    x -= az * by;
    y = az * bx;
    y -= ax * bz;
    z = ax * by;
    z -= ay * bx;
    out->x = x;
    out->y = y;
    out->z = z;
}

#pragma opt_propagation off
#pragma opt_common_subs off
void fn_1_29044(Object29044 *self, Vec3 *vec, void *arg2)
{
    Vec3 result;
    Vec3 cross;
    Vec3 input;

    copy_vec(&input, vec->z, vec->y, vec->x);
    fn_8006E2B0(arg2, &result);
    cross_vec(&input, &result, &cross);
    psvec_add(&self->v, &cross, &self->v);
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_29044 */

/* fzgx:begin fn_1_294D0 noprologue */
#include "game/main_rel/stcoli_types.h"

extern f32 lbl_8006D0B4(f32);
extern void lbl_8006D5F0(void *src, void *dst, f32 length);
extern f32 lbl_8006D6FC(void *a, void *b);
extern void lbl_8006E1F0(void *, f32, f32, f32);

/* Shared literal pool primer: retail's TU pool (lbl_1_rodata_840) in address order. */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 52.0f;
    s = 0.0625f;
    s = 45.0f;
    s = 0.0f;
    s = 1.7000000476837158f;
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.5f;
    d = 4503599627370496.0;
    s = 40.0f;
    s = 348.0f;
    s = 36.0f;
    s = 4.0f;
    s = 0.6000000238418579f;
    s = 5.0f;
    s = 0.05000000074505806f;
    s = 1000.0f;
    s = 8.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 216.0;
    d = 2.0;
    s = 0.25f;
    s = 0.07000000029802322f;
    s = 0.20000000298023224f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.834999918937683f;
}
static const u32 fzgx_pool_table6[1] = {0xAE147AE1};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.0f;
    s = 1.7999999523162842f;
    s = 1.399999976158142f;
    s = 1.5f;
    s = 1.2000000476837158f;
    s = 2.299999952316284f;
    s = 0.4000000059604645f;
    s = 3.200000047683716f;
    s = 0.15000000596046448f;
    s = -0.25f;
    s = 0.1599999964237213f;
    s = 0.11999999731779099f;
    s = 0.07999999821186066f;
    s = 0.44999998807907104f;
    s = 0.699999988079071f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6000000238418579;
    s = 0.3100000023841858f;
    s = 0.029999999329447746f;
    s = 0.009999999776482582f;
    s = 700.0f;
    s = 1.7674999237060547f;
}
static const u32 fzgx_pool_table10[1] = {0xA3D70A3D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5699999928474426f;
}
static const u32 fzgx_pool_table12[4] = {0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.10000000149011612f;
    s = 200.0f;
    s = 0.019999999552965164f;
    d = 0.009999999776482582;
    s = 0.03999999910593033f;
    s = 0.800000011920929f;
    d = 13.88888888888889;
    s = 13.88888931274414f;
    s = 1.1920928955078125e-07f;
    s = 800.0f;
    s = 0.949999988079071f;
    s = 2.200000047683716f;
    s = -0.5f;
    s = 0.0020000000949949026f;
    s = 0.0010000000474974513f;
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    d = 0.1;
    s = 80.0f;
    s = 1700.0f;
    d = 90.0;
    s = 0.3333333432674408f;
    s = -5000.0f;
    s = 900.0f;
    s = -10000.0f;
    s = 10.0f;
    s = 100.0f;
    s = 400.0f;
    s = 0.9900000095367432f;
    s = 20.0f;
    s = 1.0099999904632568f;
    d = 1.0;
    d = 0.550000011920929;
    s = 3.4000000953674316f;
    s = 0.75f;
    s = 182.04444885253906f;
    s = -45.0f;
    d = 0.9259259259259259;
    d = 5.555555555555555;
    s = 1.1299999952316284f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.10000000149011612;
    d = 0.30000001192092896;
    d = 0.046296296296296294;
    s = 0.8999999761581421f;
    s = 1.1100000143051147f;
    d = 0.0023148148148148147;
    d = 0.5;
    d = 0.004629629629629629;
    d = 0.023148148148148147;
    s = 2000.0f;
    s = 500.0f;
    d = 0.2;
    s = 0.6399999856948853f;
    s = 0.3499999940395355f;
    d = 1.8518518518518519;
    d = 3.4000000953674316;
    d = 1.7000000476837158;
    d = 3.0;
    d = 1.5;
    s = -0.4000000059604645f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 3.240740740740741;
    s = -1.0f;
    s = 9.999999747378752e-05f;
    s = 0.014000000432133675f;
    s = 9.0f;
    s = 60.0f;
    s = 3.0f;
    s = 0.1666666716337204f;
    s = 1200.0f;
    s = 1600.0f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1000.0;
    d = 0.699999988079071;
    d = 1.1920928955078125e-07;
    s = 0.003000000026077032f;
    s = 0.125f;
    s = -2000.0f;
    s = 600.0f;
    s = 6.0f;
    s = 300.0f;
    s = 1.1111111640930176f;
    s = 10000.0f;
    s = -3.0f;
    s = 10430.3779296875f;
}
static const u32 fzgx_pool_table22[12] = {0, 0, 0x3F7DF3B6, 0x3C03126F, 0x42480000, 0x41700000, 0x457A0000, 0, 0x400CCCCC, 0xCCCCCCCD, 0x3FA66666, 0x3C1374BD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 9990.0;
    s = 46.25f;
    s = 1100.0f;
}
#pragma section code_type ".text"

/* Fields of the machine body this drag step touches. */
typedef struct fn_1_294D0_Body {
    u32 flags;           /* 0x000 */
    u8 pad_4[0x4];
    f32 mass;            /* 0x008 */
    u8 pad_C[0x88];
    Vec3f vel;           /* 0x094 */
    u8 pad_A0[0x11C];
    Vec3f normal;        /* 0x1BC */
    u8 pad_1C8[0x2B0];
    f32 drag;            /* 0x478 */
    u8 pad_47C[0x64];
    u16 boostTimer;      /* 0x4E0 */
} fn_1_294D0_Body;

#pragma fp_contract on
void fn_1_294D0(fn_1_294D0_Body *p) {
    f32 scale1;
    f32 scale2;
    f32 clamp;
    f32 speed;
    f32 down;
    f32 along;
    f32 t;
    f32 sum;
    Vec3f push;
    Vec3f drag;
    Vec3f dir;

    sum = p->vel.y;
    t = p->vel.x * p->vel.x;
    t = __fmadds(sum, sum, t);
    t = __fmadds(p->vel.z, p->vel.z, t);
    speed = lbl_8006D0B4(t) / p->mass;
    if (216.0 * speed < 2.0) {
        p->vel.x = 0.0f;
        p->vel.y = 0.0f;
        p->vel.z = 0.0f;
        p->drag = 0.0f;
        return;
    }
    if (216.0 * speed > 9990.0) {
        lbl_8006D5F0(&p->vel, &p->vel, 46.25f);
        return;
    }

    along = lbl_8006D6FC(&p->normal, &p->vel);
    lbl_8006E1F0(&dir, 0.0f, 0.0f, -1.0f);
    down = lbl_8006D6FC(&p->normal, &dir);
    scale1 = p->mass * (along * speed);
    speed = speed * (8.0f * speed);
    psvec_scale(&p->normal, scale1, &drag);
    psvec_sub(&p->vel, &drag, &push);

    if (p->flags & 2) {
        if (down < 0.0f) {
            down = 1.0f + down;
            if (down < 0.0f) {
                down = 0.0f;
            }
            speed *= down;
        } else {
            down += 1.0f;
        }
    }
    lbl_8006D5F0(&push, &push, speed);
    p->drag = speed;

    if (p->mass < 1100.0f) {
        t = p->mass / 1100.0f;
        along *= t * t;
    }

    if (!(p->flags & 0x20) && (p->flags & 2)) {
        if (along < 0.0f && down > 0.8f) {
            along *= 0.6f + (f32)(4.0f * (down - 0.8f));
        } else {
            along *= 0.6f;
        }
    } else if (p->flags & 0x20) {
        along *= 0.5f;
    } else {
        along *= 0.6f;
    }

    scale2 = speed * along;
    psvec_scale(&p->normal, scale2, &drag);
    psvec_add(&drag, &push, &push);

    if (p->boostTimer != 0) {
        t = 0.01f * ((f32)p->boostTimer - 4.0f);
        if (t < 0.0f) {
            clamp = 0.0f;
        } else if (t > 1.0f) {
            clamp = 1.0f;
        } else {
            clamp = t;
        }
        psvec_scale(&push, clamp, &push);
    }
    psvec_sub(&p->vel, &push, &p->vel);
}
#pragma fp_contract reset
/* fzgx:end fn_1_294D0 */

/* fzgx:begin fn_1_29800 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 52.0f;
    s = 0.0625f;
    s = 45.0f;
    s = 0.0f;
    s = 1.7000000476837158f;
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.5f;
    d = 4503599627370496.0;
    s = 40.0f;
    s = 348.0f;
    s = 36.0f;
    s = 4.0f;
    s = 0.6000000238418579f;
    s = 5.0f;
    s = 0.05000000074505806f;
    s = 1000.0f;
    s = 8.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 216.0;
    d = 2.0;
    s = 0.25f;
    s = 0.07000000029802322f;
    s = 0.20000000298023224f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.834999918937683f;
}
static const u32 fzgx_pool_table6[1] = {0xAE147AE1};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.0f;
    s = 1.7999999523162842f;
    s = 1.399999976158142f;
    s = 1.5f;
    s = 1.2000000476837158f;
    s = 2.299999952316284f;
    s = 0.4000000059604645f;
    s = 3.200000047683716f;
    s = 0.15000000596046448f;
    s = -0.25f;
    s = 0.1599999964237213f;
    s = 0.11999999731779099f;
    s = 0.07999999821186066f;
    s = 0.44999998807907104f;
    s = 0.699999988079071f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6000000238418579;
    s = 0.3100000023841858f;
    s = 0.029999999329447746f;
    s = 0.009999999776482582f;
    s = 700.0f;
    s = 1.7674999237060547f;
}
static const u32 fzgx_pool_table10[1] = {0xA3D70A3D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5699999928474426f;
}
static const u32 fzgx_pool_table12[4] = {0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.10000000149011612f;
    s = 200.0f;
    s = 0.019999999552965164f;
    d = 0.009999999776482582;
    s = 0.03999999910593033f;
    s = 0.800000011920929f;
    d = 13.88888888888889;
    s = 13.88888931274414f;
    s = 1.1920928955078125e-07f;
    s = 800.0f;
    s = 0.949999988079071f;
    s = 2.200000047683716f;
    s = -0.5f;
    s = 0.0020000000949949026f;
    s = 0.0010000000474974513f;
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    d = 0.1;
    s = 80.0f;
    s = 1700.0f;
    d = 90.0;
    s = 0.3333333432674408f;
    s = -5000.0f;
    s = 900.0f;
    s = -10000.0f;
    s = 10.0f;
    s = 100.0f;
    s = 400.0f;
    s = 0.9900000095367432f;
    s = 20.0f;
    s = 1.0099999904632568f;
    d = 1.0;
    d = 0.550000011920929;
    s = 3.4000000953674316f;
    s = 0.75f;
    s = 182.04444885253906f;
    s = -45.0f;
    d = 0.9259259259259259;
    d = 5.555555555555555;
    s = 1.1299999952316284f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.10000000149011612;
    d = 0.30000001192092896;
    d = 0.046296296296296294;
    s = 0.8999999761581421f;
    s = 1.1100000143051147f;
    d = 0.0023148148148148147;
    d = 0.5;
    d = 0.004629629629629629;
    d = 0.023148148148148147;
    s = 2000.0f;
    s = 500.0f;
    d = 0.2;
    s = 0.6399999856948853f;
    s = 0.3499999940395355f;
    d = 1.8518518518518519;
    d = 3.4000000953674316;
    d = 1.7000000476837158;
    d = 3.0;
    d = 1.5;
    s = -0.4000000059604645f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 3.240740740740741;
    s = -1.0f;
    s = 9.999999747378752e-05f;
    s = 0.014000000432133675f;
    s = 9.0f;
    s = 60.0f;
    s = 3.0f;
    s = 0.1666666716337204f;
    s = 1200.0f;
    s = 1600.0f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1000.0;
    d = 0.699999988079071;
    d = 1.1920928955078125e-07;
    s = 0.003000000026077032f;
    s = 0.125f;
    s = -2000.0f;
    s = 600.0f;
    s = 6.0f;
    s = 300.0f;
    s = 1.1111111640930176f;
    s = 10000.0f;
    s = -3.0f;
    s = 10430.3779296875f;
    d = 0.0;
    s = 0.9919999837875366f;
    s = 0.00800000037997961f;
    s = 50.0f;
    s = 15.0f;
    s = 4000.0f;
}
static const u32 fzgx_pool_table22[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 3.6;
    s = 1.2999999523162842f;
    s = 0.009000000543892384f;
    d = 9990.0;
    s = 46.25f;
    s = 1100.0f;
    s = 120.0f;
    s = -50.0f;
    d = 4503601774854144.0;
}
#pragma section code_type ".text"

struct S {
    u32 flags;
    u8 pad_4[0x17C];
    f32 f180;
    u8 pad_184[0x70];
    f32 f1F4;
    u8 pad_1F8[0x4];
    f32 f1FC;
    u8 pad_200[0x1C];
    u32 f21C;
    u8 pad_220[0x261];
    u8 b481;
    u8 pad_482[0x1];
    u8 b483;
    u8 pad_484[0x108];
    u32 f58C;
};


void fn_1_29800(struct S *p) {
    s32 v0 = 0;
    f32 f4;
    f32 t;
    if (p->b481 > 60 && (p->flags & 2) != 0) {
        v0 = 1;
    }
    if (v0 != 0) {
        f4 = 2.0 * __fabs(p->f1FC);
        if ((p->f58C & 2) != 0) {
            f4 = 0.0f;
        }
        if (f4 < 0.1f) {
            f32 q = 4.0f * p->f1F4;
            f4 = f4 + q;
        } else {
            f32 two = 2.0f;
            f32 m = two * p->f1F4;
            f64 pr = m * __fabs(two - f4);
            f4 = f4 + pr;
            if ((p->flags & 0x20) != 0 && (p->flags & 0x200000) == 0) {
                f4 = f4 * two;
            }
        }
        if (p->b483 > 60) {
            t = (f32)(s32)(p->b483 - 60) / 120.0f;
            if (t > 1.0f) {
                t = 1.0f;
            }
            f4 = f4 * (1.0f + (t = 0.3f * t));
            f4 = f4 + t;
        }
        if ((p->f21C & 0x1800000) != 0) {
            f32 k = 0.3f;
            f4 = f4 * k;
        }
        p->f180 = p->f180 + f4;
        {
            f32 v = p->f180;
            if (v < -50.0f) {
                p->f180 = -50.0f;
            } else if (v > 60.0f) {
                p->f180 = 60.0f;
            }
        }
    } else {
        p->f180 = 0.0f;
    }
}
/* fzgx:end fn_1_29800 */

/* fzgx:begin fn_1_29968 noprologue */
typedef float f32;
typedef int s32;
typedef unsigned int u32;
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 52.0f;
    s = 0.0625f;
    s = 45.0f;
    s = 0.0f;
    s = 1.7000000476837158f;
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.5f;
    d = 4503599627370496.0;
    s = 40.0f;
    s = 348.0f;
    s = 36.0f;
    s = 4.0f;
    s = 0.6000000238418579f;
    s = 5.0f;
    s = 0.05000000074505806f;
    s = 1000.0f;
    s = 8.0f;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 216.0;
    d = 2.0;
    s = 0.25f;
    s = 0.07000000029802322f;
    s = 0.20000000298023224f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.834999918937683f;
}
static const unsigned long fzgx_pool_table6[1] = {0xAE147AE1};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.0f;
    s = 1.7999999523162842f;
    s = 1.399999976158142f;
    s = 1.5f;
    s = 1.2000000476837158f;
    s = 2.299999952316284f;
    s = 0.4000000059604645f;
    s = 3.200000047683716f;
    s = 0.15000000596046448f;
    s = -0.25f;
    s = 0.1599999964237213f;
    s = 0.11999999731779099f;
    s = 0.07999999821186066f;
    s = 0.44999998807907104f;
    s = 0.699999988079071f;
}
static const unsigned long fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6000000238418579;
    s = 0.3100000023841858f;
    s = 0.029999999329447746f;
    s = 0.009999999776482582f;
    s = 700.0f;
    s = 1.7674999237060547f;
}
static const unsigned long fzgx_pool_table10[1] = {0xA3D70A3D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5699999928474426f;
}
static const unsigned long fzgx_pool_table12[4] = {0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.10000000149011612f;
    s = 200.0f;
    s = 0.019999999552965164f;
    d = 0.009999999776482582;
    s = 0.03999999910593033f;
    s = 0.800000011920929f;
    d = 13.88888888888889;
    s = 13.88888931274414f;
    s = 1.1920928955078125e-07f;
    s = 800.0f;
    s = 0.949999988079071f;
    s = 2.200000047683716f;
    s = -0.5f;
    s = 0.0020000000949949026f;
    s = 0.0010000000474974513f;
    s = 0.30000001192092896f;
}
static const unsigned long fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    d = 0.1;
    s = 80.0f;
    s = 1700.0f;
    d = 90.0;
    s = 0.3333333432674408f;
    s = -5000.0f;
    s = 900.0f;
    s = -10000.0f;
    s = 10.0f;
    s = 100.0f;
    s = 400.0f;
    s = 0.9900000095367432f;
    s = 20.0f;
    s = 1.0099999904632568f;
    d = 1.0;
    d = 0.550000011920929;
    s = 3.4000000953674316f;
    s = 0.75f;
    s = 182.04444885253906f;
    s = -45.0f;
    d = 0.9259259259259259;
    d = 5.555555555555555;
    s = 1.1299999952316284f;
}
static const unsigned long fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.10000000149011612;
    d = 0.30000001192092896;
    d = 0.046296296296296294;
    s = 0.8999999761581421f;
    s = 1.1100000143051147f;
    d = 0.0023148148148148147;
    d = 0.5;
    d = 0.004629629629629629;
    d = 0.023148148148148147;
    s = 2000.0f;
    s = 500.0f;
    d = 0.2;
    s = 0.6399999856948853f;
    s = 0.3499999940395355f;
    d = 1.8518518518518519;
    d = 3.4000000953674316;
    d = 1.7000000476837158;
    d = 3.0;
    d = 1.5;
    s = -0.4000000059604645f;
}
static const unsigned long fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const unsigned long *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 3.240740740740741;
    s = -1.0f;
    s = 9.999999747378752e-05f;
    s = 0.014000000432133675f;
    s = 9.0f;
    s = 60.0f;
    s = 3.0f;
    s = 0.1666666716337204f;
    s = 1200.0f;
    s = 1600.0f;
}
static const unsigned long fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const unsigned long *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1000.0;
    d = 0.699999988079071;
    d = 1.1920928955078125e-07;
    s = 0.003000000026077032f;
    s = 0.125f;
    s = -2000.0f;
    s = 600.0f;
    s = 6.0f;
    s = 300.0f;
    s = 1.1111111640930176f;
    s = 10000.0f;
    s = -3.0f;
    s = 10430.3779296875f;
    d = 0.0;
    s = 0.9919999837875366f;
    s = 0.00800000037997961f;
    s = 50.0f;
    s = 15.0f;
    s = 4000.0f;
}
static const unsigned long fzgx_pool_table22[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const unsigned long *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 3.6;
    s = 1.2999999523162842f;
    s = 0.009000000543892384f;
    d = 9990.0;
    s = 46.25f;
    s = 1100.0f;
    s = 120.0f;
    s = -50.0f;
    d = 4503601774854144.0;
    s = 30.0f;
    s = -0.20000000298023224f;
}
#pragma section code_type ".text"

extern void lbl_8006DAEC(void);
extern u32 mathutil_mtxA_rotate_x(u32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DB30(void);

#pragma opt_propagation off
void fn_1_29968(char *obj)
{
    f32 x;
    f32 clamped;
    f32 angle_scale;
    f32 tilt_scale;
    f32 quotient;
    f32 numerator;
    lbl_8006DAEC();
    angle_scale = 182.04444885253906f;
    tilt_scale = 30.0f;
    numerator = *(f32 *)(obj + 0x30c);
    quotient = numerator / -*(f32 *)(obj + 0x254);
    x = quotient - 1.0f;
    clamped = x < -0.2f ? -0.2f : x > 0.2f ? 0.2f : x;
    mathutil_mtxA_rotate_x((s32)(angle_scale * (tilt_scale * clamped)));
    lbl_8006DB74(obj + 0x5e0);
    lbl_8006DB30();
}
/* fzgx:end fn_1_29968 */

/* fzgx:begin fn_1_2A214 noprologue */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 52.0f;
    s = 0.0625f;
    s = 45.0f;
    s = 0.0f;
    s = 1.7000000476837158f;
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.5f;
    d = 4503599627370496.0;
    s = 40.0f;
    s = 348.0f;
    s = 36.0f;
    s = 4.0f;
    s = 0.6000000238418579f;
    s = 5.0f;
    s = 0.05000000074505806f;
    s = 1000.0f;
    s = 8.0f;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 216.0;
    d = 2.0;
    s = 0.25f;
    s = 0.07000000029802322f;
    s = 0.20000000298023224f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.834999918937683f;
}
static const unsigned long fzgx_pool_table6[1] = {0xAE147AE1};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.0f;
    s = 1.7999999523162842f;
    s = 1.399999976158142f;
    s = 1.5f;
    s = 1.2000000476837158f;
    s = 2.299999952316284f;
    s = 0.4000000059604645f;
    s = 3.200000047683716f;
    s = 0.15000000596046448f;
    s = -0.25f;
    s = 0.1599999964237213f;
    s = 0.11999999731779099f;
    s = 0.07999999821186066f;
    s = 0.44999998807907104f;
    s = 0.699999988079071f;
}
static const unsigned long fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6000000238418579;
    s = 0.3100000023841858f;
    s = 0.029999999329447746f;
    s = 0.009999999776482582f;
    s = 700.0f;
    s = 1.7674999237060547f;
}
static const unsigned long fzgx_pool_table10[1] = {0xA3D70A3D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5699999928474426f;
}
static const unsigned long fzgx_pool_table12[4] = {0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.10000000149011612f;
    s = 200.0f;
    s = 0.019999999552965164f;
    d = 0.009999999776482582;
    s = 0.03999999910593033f;
    s = 0.800000011920929f;
    d = 13.88888888888889;
    s = 13.88888931274414f;
    s = 1.1920928955078125e-07f;
    s = 800.0f;
    s = 0.949999988079071f;
    s = 2.200000047683716f;
    s = -0.5f;
    s = 0.0020000000949949026f;
    s = 0.0010000000474974513f;
    s = 0.30000001192092896f;
}
static const unsigned long fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    d = 0.1;
    s = 80.0f;
    s = 1700.0f;
    d = 90.0;
    s = 0.3333333432674408f;
    s = -5000.0f;
    s = 900.0f;
    s = -10000.0f;
    s = 10.0f;
    s = 100.0f;
    s = 400.0f;
    s = 0.9900000095367432f;
    s = 20.0f;
    s = 1.0099999904632568f;
    d = 1.0;
    d = 0.550000011920929;
    s = 3.4000000953674316f;
    s = 0.75f;
    s = 182.04444885253906f;
    s = -45.0f;
    d = 0.9259259259259259;
    d = 5.555555555555555;
    s = 1.1299999952316284f;
}
static const unsigned long fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.10000000149011612;
    d = 0.30000001192092896;
    d = 0.046296296296296294;
    s = 0.8999999761581421f;
    s = 1.1100000143051147f;
}
#pragma section code_type ".text"
typedef struct {
    unsigned int flags;
    unsigned char pad4[0x9c];
    float a0;
    float a4;
    float a8;
    float pad_ac;
    float b0;
} StColiObj;

extern float lbl_1_rodata_840[];
extern double __fabs(double);

#pragma opt_strength_reduction off
void fn_1_2A214(StColiObj *obj)
{
    float limit;
    struct { float *value; } c;
    c.value = lbl_1_rodata_840;

    if (obj->flags & 2) {
        float k0 = (0.899999976f);
        float k1 = (0.99000001f);
        obj->a0 = obj->a0 * k0;
        obj->a8 = obj->a8 * k1;
        limit = obj->b0;
    } else if (obj->flags & 0x10) {
        limit = (0.200000003f) * obj->b0;
    } else {
        limit = (0.0500000007f) * obj->b0;
    }
    if (__fabs(obj->a4) > limit) {
        if (obj->a4 < (0.0f)) {
            obj->a4 = -limit;
        } else {
            obj->a4 = limit;
        }
    }
}
#pragma opt_strength_reduction reset
/* fzgx:end fn_1_2A214 */

/* fzgx:begin fn_1_2A2A4 */
typedef struct {
    u8 pad00[0xec];
    u8 field_ec[0xd0];
    u8 pad_1bc[0x1bc];
} Fn1_2A2A4Object;


void fn_1_2A2A4(Fn1_2A2A4Object *self) {
    u8 local_14[12];
    u8 local_8[12];
    f32 value_1;
    f32 value_2;

    value_1 = lbl_1_rodata_84C;
    value_2 = lbl_1_rodata_854;
    lbl_8006E1F0(local_8, value_1, value_2, value_1);
    lbl_8006DAEC();
    fn_8006E978(local_14, local_8, self->pad_1bc);
    mathutil_mtxA_from_quat(local_14);
    lbl_8006DFC4(self->field_ec);
    lbl_8006DB74(self->field_ec);
    lbl_8006DB30();
}
/* fzgx:end fn_1_2A2A4 */

/* fzgx:begin fn_1_2A318 */
typedef struct Fn_1_2A318 {
    unsigned char pad000[0x184];
    f32 field184;
    unsigned char pad188[0x02];
    unsigned char field18a;
    unsigned char pad18b[0x85];
    u16 field210;
    unsigned char field212;
    unsigned char pad213[0x26f];
    unsigned char field482;
    unsigned char pad483[0x10f];
    unsigned char field592;
    unsigned char pad593[0x47];
    u16 field5da;
} Fn_1_2A318;

void fn_1_2A318(Fn_1_2A318 *self) {
    u16 value;
    f32 progress;

    self->field482++;
    self->field212++;
    self->field210 += self->field212 * (self->field18a ? 15 : 10);
    if (self->field592 == 0) {
        self->field592 = 1;
    }
    value = self->field5da;
    progress = self->field184;
    if (progress < value) {
        progress += lbl_1_rodata_B74[0];
        self->field184 = progress;
        if (progress > value) {
            self->field184 = self->field5da;
        }
    }
}
/* fzgx:end fn_1_2A318 */

/* fzgx:begin fn_1_2A3E4 */
typedef struct Fn_1_2A3E4 {
    u32 flags;
    unsigned char pad04[0x186];
    u8 active;
    unsigned char pad18b[0x85];
    u16 value210;
} Fn_1_2A3E4;

void fn_1_2A3E4(Fn_1_2A3E4 *self) {
    if (self->active != 0) {
        if (self->flags & 0x00200000) {
            self->value210 += 0x14;
        } else {
            self->value210 += 0xA;
        }
    }
}
/* fzgx:end fn_1_2A3E4 */

/* fzgx:begin fn_1_2A41C */
typedef struct Fn_1_2A41C {
    u32 flags;
    unsigned char pad04[0x190];
    u16 value194;
} Fn_1_2A41C;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 52.0f;
    s = 0.0625f;
    s = 45.0f;
    s = 0.0f;
    s = 1.7000000476837158f;
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.5f;
    d = 4503599627370496.0;
    s = 40.0f;
    s = 348.0f;
    s = 36.0f;
    s = 4.0f;
    s = 0.6000000238418579f;
    s = 5.0f;
    s = 0.05000000074505806f;
    s = 1000.0f;
    s = 8.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 216.0;
    d = 2.0;
    s = 0.25f;
    s = 0.07000000029802322f;
    s = 0.20000000298023224f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.834999918937683f;
}
static const u32 fzgx_pool_table6[1] = {0xAE147AE1};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.0f;
    s = 1.7999999523162842f;
    s = 1.399999976158142f;
    s = 1.5f;
    s = 1.2000000476837158f;
    s = 2.299999952316284f;
    s = 0.4000000059604645f;
    s = 3.200000047683716f;
    s = 0.15000000596046448f;
    s = -0.25f;
    s = 0.1599999964237213f;
    s = 0.11999999731779099f;
    s = 0.07999999821186066f;
    s = 0.44999998807907104f;
    s = 0.699999988079071f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6000000238418579;
    s = 0.3100000023841858f;
    s = 0.029999999329447746f;
    s = 0.009999999776482582f;
    s = 700.0f;
    s = 1.7674999237060547f;
}
static const u32 fzgx_pool_table10[1] = {0xA3D70A3D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5699999928474426f;
}
static const u32 fzgx_pool_table12[4] = {0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.10000000149011612f;
    s = 200.0f;
    s = 0.019999999552965164f;
    d = 0.009999999776482582;
    s = 0.03999999910593033f;
    s = 0.800000011920929f;
    d = 13.88888888888889;
    s = 13.88888931274414f;
}
static const u32 fzgx_pool_table14[1] = {0x34000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 0.949999988079071f;
    s = 2.200000047683716f;
    s = -0.5f;
    s = 0.0020000000949949026f;
    s = 0.0010000000474974513f;
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    d = 0.1;
    s = 80.0f;
    s = 1700.0f;
    d = 90.0;
    s = 0.3333333432674408f;
    s = -5000.0f;
    s = 900.0f;
    s = -10000.0f;
    s = 10.0f;
    s = 100.0f;
    s = 400.0f;
    s = 0.9900000095367432f;
    s = 20.0f;
    s = 1.0099999904632568f;
    d = 1.0;
    d = 0.550000011920929;
    s = 3.4000000953674316f;
    s = 0.75f;
    s = 182.04444885253906f;
    s = -45.0f;
    d = 0.9259259259259259;
    d = 5.555555555555555;
    s = 1.1299999952316284f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.10000000149011612;
    d = 0.30000001192092896;
    d = 0.046296296296296294;
    s = 0.8999999761581421f;
    s = 1.1100000143051147f;
    d = 0.0023148148148148147;
    d = 0.5;
    d = 0.004629629629629629;
    d = 0.023148148148148147;
    s = 2000.0f;
    s = 500.0f;
    d = 0.2;
    s = 0.6399999856948853f;
    s = 0.3499999940395355f;
    d = 1.8518518518518519;
    d = 3.4000000953674316;
    d = 1.7000000476837158;
    d = 3.0;
    d = 1.5;
    s = -0.4000000059604645f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 3.240740740740741;
    s = -1.0f;
    s = 9.999999747378752e-05f;
    s = 0.014000000432133675f;
    s = 9.0f;
    s = 60.0f;
    s = 3.0f;
    s = 0.1666666716337204f;
    s = 1200.0f;
    s = 1600.0f;
}
static const u32 fzgx_pool_table22[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1000.0;
    d = 0.699999988079071;
    d = 1.1920928955078125e-07;
    s = 0.003000000026077032f;
    s = 0.125f;
    s = -2000.0f;
    s = 600.0f;
    s = 6.0f;
    s = 300.0f;
    s = 1.1111111640930176f;
    s = 10000.0f;
    s = -3.0f;
    s = 10430.3779296875f;
    d = 0.0;
    s = 0.9919999837875366f;
    s = 0.00800000037997961f;
    s = 50.0f;
    s = 15.0f;
    s = 4000.0f;
}
static const u32 fzgx_pool_table24[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 3.6;
    s = 1.2999999523162842f;
    s = 0.009000000543892384f;
    d = 9990.0;
    s = 46.25f;
    s = 1100.0f;
    s = 120.0f;
    s = -50.0f;
    d = 4503601774854144.0;
    s = 30.0f;
    s = -0.20000000298023224f;
    s = 90.0f;
    s = 0.006000000052154064f;
    d = 4.62962962962963;
    s = -5.0f;
    s = 4.5f;
    s = 3640.0f;
    s = 2.5f;
    s = -0.30000001192092896f;
    s = 5.999999848427251e-05f;
    s = 65536.0f;
    s = 6.666666507720947f;
    s = 3.5f;
    s = 0.000244140625f;
}
#pragma section code_type ".text"
f32 fn_1_2A41C(Fn_1_2A41C *self, int arg) {
    f32 result;
    u32 flags;
    f32 delta;
    f32 half;
    f32 scaled;
    f32 t;

    flags = self->flags;
    result = 1.0f;
    if ((flags & 0x20008) != 0) {
        if ((flags & 0x200) != 0) {
            if ((flags & 8) != 0) {
                result *= 3.5f;
            } else {
                result *= 4.0f;
            }
        } else {
            delta = (f32)self->value194;
            delta *= 0.000244140625f;
            half = 0.5f;
            scaled = half * delta;
            t = half + scaled;
            if (arg != 0) {
                if ((flags & 8) != 0) {
                    result *= 5.0f * t;
                } else {
                    result *= 6.0f;
                }
            } else {
                if ((flags & 8) != 0) {
                    result *= 3.0f * t;
                } else {
                    result *= 2.0f;
                }
            }
        }
    } else {
        if ((flags & 0x200) != 0) {
            result *= 0.8f;
        }
    }
    return result;
}
/* fzgx:end fn_1_2A41C */

/* fzgx:begin fn_1_2A500 noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/stcoli.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"

typedef struct Node {
    u32 unk_0;
    u8 pad_4[0x8];
    s32 count;
    struct Node *children;
    u8 pad_14[0x50 - 0x14];
} Node;

typedef struct StcoliNode StcoliNode;

struct StcoliNode {
    u32 flags;
    u8 pad[8];
    s32 count;
    StcoliNode *items;
    u8 rest[0x3c];
};

typedef struct StcoliVec {
    u32 x;
    u32 y;
    u32 z;
} StcoliVec;

typedef struct {
    unsigned char pad0[0x0c];
    int count;
    void *entries;
} Fn118F28Object;

typedef struct Fn_1_20258Constants {
    unsigned char pad08[8];
    f32 value08;
    f32 value0c;
    unsigned char pad10[0xb0];
    f64 valuec0;
    f32 valuec8;
    unsigned char padcc[4];
    f64 valued0;
} Fn_1_20258Constants;

typedef struct {
    u32 f00, f04, f08, f0c, f10, f14, f18, f1c, f20, f24;
    u32 f28, f2c, f30, f34, f38, f3c, f40, f44;
} Cfg;

typedef struct {
    u8 pad_0[0x4];
    Cfg *cfg;
    u8 pad_8[0xc];
    f32 fx;
    f32 fy;
    f32 fz;
    f32 rxv;
    f32 ryv;
    f32 rzv;
    f32 sxv;
    f32 syv;
    f32 szv;
} Entity;

typedef struct {
    u32 count;
    u32 entries[1];
} Stack;

struct fn_1_2B478_lbl_801A6D00 {
    u32 unk_0;
};

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    f32 m[10];
    f64 d;
} Mtx;

struct Pool {
    u8 pad_0[0xc];
    f32 one;
    u8 pad_10[0xc];
    f32 two;
    u8 pad_20[0x14];
    f32 half;
};

struct fn_1_207DC_pool {
    u8 pad_0[8];
    f32 zero;
    f32 one;
    u8 pad_10[0xB0];
    f64 eps;
    f32 pi;
    u8 pad_CC[4];
    f64 two;
};

struct fn_1_21950_lbl_1_rodata_6C8 {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x14];
    f32 unk_20;
    u8 pad_24[0x10];
    f32 unk_34;
};

typedef struct {
    u8 pad_0[0x30];
    Vec3 pos;
    f32 ax;
    f32 ay;
    Vec3 v0;
    Vec3 e;
    Vec3 m;
    f32 d0;
    f32 d1;
    Vec3 o;
    u32 f7c;
    u8 pad_80[0x7c];
    u32 fffc;
} Rec;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    u32 f44;
} fn_1_18784_Cfg;

typedef struct {
    u32 f00;
    fn_1_18784_Cfg *cfg;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    f32 f18;
} Src;

typedef struct {
    u32 f00;
    fn_1_18784_Cfg *cfg;
    u32 f08;
    s32 f0c;
    Src *f10;
    u32 f14;
    f32 f18;
    f32 f1c;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2c;
} Motion;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_21CFC_Vec;

struct fn_1_2D524_Copy200 { char *a[10][5]; };

struct fn_1_2D524_Copy8 { char *a[2]; };

struct fn_1_2D524_lbl_1_rodata_BD8 {
    u8 pad_0[0x24];
    f32 unk_24;
    u8 pad_28[0x30];
    struct fn_1_2D524_Copy200 unk_58;
    struct fn_1_2D524_Copy8 unk_120;
    f32 unk_128;
    f32 unk_12C;
    f32 unk_130;
};
extern void fn_1_9E14C();
extern void fn_1_9E170(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern const f32 lbl_1_rodata_6D0;
extern f32 lbl_1_rodata_6F8;
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_z(u32);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void lbl_8006E0B4(f32, f32, f32);
extern Fn_1_20258Constants lbl_1_rodata_6C8;
extern u8 *lbl_801A66CC;
extern struct fn_1_2B478_lbl_801A6D00 lbl_801A6D00;
extern f64 __fabs(f64);
extern void lbl_8006DB74(void *);
extern void fn_1_18214();
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006DBE4();
extern void fn_1_1902C(StcoliNode *root, StcoliVec *vec, void *arg3, f32 value);
extern void fn_1_18784();
extern void fn_1_18F28(Fn118F28Object *obj, int *args, int arg2, float value);
extern u32 fn_1_203E4(void *, u32, void *, f32, f32, f32);
extern void OSReport(const char *format, ...);
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_8006DCA4(void);
extern void lbl_8006E1B0(void *, void *);
extern void fn_8003462C(u32 arg0, u32 arg1, u32 arg2);
extern void fn_80072558(void);
extern f32 lbl_1_rodata_6B0[6];
extern void fn_1_17D5C(Node *node, u32 *acc);
extern int fn_1_210A8(void *, f32 *, int, int, int);
extern int fn_1_16BA0(void *, void *, void *, int *, int);
extern f32 fn_1_16E68(void *, void *, int);
extern unsigned char lbl_1_rodata_840[];
extern void fn_1_22F90(void *self, int value);
extern void lbl_8006E1F0(void *, f32, f32, f32);
extern void fn_1_8A190(void *arg0, void *arg1);
extern int fn_1_15578();
extern void *memset(void *, int, unsigned int);
extern int fn_1_4C10(void);
extern u32 fn_1_4060(void);
extern void fn_1_EB080(int mode);
extern void fn_1_9D77C(u32, u32);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern u32 lbl_801A6410;
extern int fn_1_180F4(int first, int second, int count, int ascending);
extern void fn_1_21950(u32 arg0, f32 arg1, f32 arg2);
extern f32 lbl_1_rodata_6D4;
extern char lbl_1_bss_9C;
extern void fn_1_A2D84(u32 arg0);
extern u32 fn_1_8C66C(u32 index);
extern int fn_1_163BC(void *arg0, void *arg1, int mask, int value);
extern void lbl_8006E1D8(void *arg0, f32 arg1, f32 arg2, f32 arg3);
extern double lbl_1_rodata_910;
extern const f32 lbl_1_rodata_84C;
extern const f32 lbl_1_rodata_854;
extern s16 fn_1_7B054();
extern void *fn_1_868C0(s8 index);
extern void fn_1_F7338(int arg0, void *arg1, void *arg2);
extern const f32 lbl_1_rodata_85C;
extern void fn_8006E978(f32 *arg0, Vec3 *arg1, Vec3 *arg2);
extern void mathutil_mtxA_from_quat(void *);
extern void lbl_8006DFC4(void *);
extern f64 lbl_1_rodata_860[22];
extern f32 lbl_1_rodata_B74[25];
extern f32 lbl_8006D6FC(void *, void *);
extern s16 lbl_1_bss_3C2A[3];
extern f32 lbl_8006D188(s16 angle);
extern f32 lbl_8006D0B4(f32);
extern void fn_8006E7E4(void *, void *, s32);
extern u32 fn_1_8627C(s32 index);
extern u8 * fn_1_14F04(void);
extern u32 fn_1_2B684(u32);
extern u32 lbl_801A66C8[2];
extern f32 lbl_1_rodata_92C[10];
extern void lbl_8006DBAC(void *arg0);
extern void fn_8006E250(void *arg0, void *arg1);
extern void lbl_8006D668(void *arg0);
extern char *fn_1_14EA74(s16 arg0, char *arg1, s16 arg2);
extern char *fn_1_15BA78(char *name);
extern f32 fn_1_4B068(char *);
extern f32 fn_1_4B090(s32 value);
extern int sprintf(char *s, const char *format, ...);
extern s16 fn_1_12EF24(s16 row, s16 column);
extern struct fn_1_2D524_lbl_1_rodata_BD8 lbl_1_rodata_BD8;
extern u32 lbl_801A66B4;
extern u32 fn_1_4AEC0(u32 value);
extern void fn_1_F83F0(s16 arg0);
extern u32 fn_1_F8D10(void);
extern char *lbl_1_data_2BD54[][6];
extern void *fn_1_7F49C(s16 arg0, s16 arg1, void *arg2);
extern void fn_1_49410(void);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_49590(f32 value);
extern void fn_1_495B0(u32 value);
extern void fn_1_495C8(u8 value);
extern void fn_1_A2DC4(u32 arg0);
extern void fn_1_F2008(s32 arg);
extern void fn_1_F7F48(s16 value);
extern void fn_1_F8A58(u32 value);
extern void fn_1_F8C00(s32 value);
extern void fn_1_F8D38(u32 value);
extern void fn_1_F9D68(u32 arg);
extern void fn_1_F9DE8(u32 param);
extern u8 lbl_1_bss_6F316;
extern u32 fn_1_A1588(void *, u32);
extern void ADXT_Stop(void *);
extern u32 fn_1_435C(u32 value);
extern void fn_1_40E08(u32 arg0);
extern u32 lbl_1_rodata_D18;
extern u32 lbl_1_rodata_D1C[11];
extern void fn_1_49F0(u32 *value);
extern void fn_1_4A00(s32 enabled, u8 mode, void *value);
extern u32 lbl_1_bss_25B9C;
extern u32 fn_1_304A8(void);
extern void fn_1_3F2A0(void);

/* result block passed to the helper; the helper fills scale and vec */
struct CalcOut {
    u32 flags;
    void *self;
    f32 scale;
    Vec3 v;
};


static inline f32 fn_1_2A500_read_pointer(Vec3 * owner) { return owner->x; }
static inline f32 fn_1_2A500_read_y(Vec3 * owner) { return owner->y; }
static inline f32 fn_1_2A500_read_z(Vec3 * owner) { return owner->z; }
#pragma opt_common_subs off
s32 fn_1_2A500(void *self, Vec3 *out, Vec3 *pos, void *a, void *b, f32 *outF)
{
    u32 *fzgx_value;
    void *mgr = (void *)fn_1_8627C(*(s16 *)((u8 *)self + 4));
    struct CalcOut res;
    s32 found_2;
    s32 found;
    f32 f;

    lbl_8006DAEC();

    res.v = *out;
    fzgx_value = &(res.flags);
    *fzgx_value = *(u32 *)((u8 *)self + 0x498);
    res.self = self;

    found = fn_1_15578(&res.v, pos, &res.scale, a, b,
                       (u8 *)mgr + 0x9C, *(u32 *)((u8 *)mgr + 0x98), 0);

    if (found != 0) {
        f32 dz = fn_1_2A500_read_z(out);
        f32 dy = fn_1_2A500_read_y(out);
        f32 dx = fn_1_2A500_read_pointer(out);
        f32 d;

        dz = dz - pos->z;
        dy = dy - pos->y;
        dx = dx - pos->x;
        d = (f32)(dx * dx);
        d = d + dy * dy;
        d = d + dz * dz;

        f = ((((const f32 *)&lbl_1_rodata_854))[0] - res.scale) * lbl_8006D0B4(d);

        *out = res.v;
        found_2 = 1;
    } else {
        f = (((const f32 *)&lbl_1_rodata_84C))[0];
        found_2 = 0;
    }

    lbl_8006DB30();
    *outF = f;
    return found_2;
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_2A500 */

/* fzgx:begin fn_1_2A638 */
void fn_1_2A638(void *arg0, Fn_1_2A638 *self) {
    lbl_8006E1D8((char *)self + 0x14, self->field08,
        self->field0c + self->field44 - self->field48, self->field10);
}
/* fzgx:end fn_1_2A638 */

/* fzgx:begin fn_1_2A678 */
void fn_1_2A678(Fn_1_2A678_Source *self, Fn_1_2A678_Dest *dest) {
    dest->values = self->values;
}
/* fzgx:end fn_1_2A678 */

/* fzgx:begin fn_1_2A694 noprologue */
#include "types.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/stcoli.h"

extern int fn_1_15578(void *, void *, void *, void *, u32, void *, void *, void *, u32, void *);
extern void *fn_1_14F04(void); extern int fn_1_868C0(s8); extern void fn_1_F7338(int,int,int);
extern const f64 lbl_1_rodata_84C; extern void lbl_8006DAEC(void); extern void lbl_8006DB30(void);
typedef struct N { u8 p[0x98]; u32 v98; u32 v9c; } N;
typedef struct O { u32 flags; s16 id; u8 p[0x46e]; u8 v474; u8 p2[0x23]; u32 field498; N *field49c; u8 p3[0xec]; u32 field58c; } O;
typedef struct R { u8 p[0x160]; u32 flags160; u8 p2[0x1c]; u32 v180; u32 v184; u32 v188; } R;
typedef struct V { f32 x; f32 y; f32 z; } V; typedef struct F { f32 x; f32 y; f32 z; } F; typedef struct P { u32 x; u32 y; } P;
#pragma opt_propagation off
int fn_1_2A694(O *self, void *arg1, V *swap, u32 mask, V *out0, V *out1) {
 F local; f32 work[4]; R *result; int status; int actor;
 if ((self->flags&2)==0) mask&=0xfffff8ff;
 { psvec_set(&local.x, *(const f32 *)(LC_BASE + 0x2C), *(const f32 *)(LC_BASE + 0x1C), *(const f32 *)(LC_BASE + 0xC)); } lbl_8006DAEC();
 status=fn_1_15578(&local,arg1,&work[0],&work[1],mask,&self->field49c->v9c,(void *)self->field49c->v98,swap,self->field498,self); lbl_8006DB30();
 if(((0) != (swap))){u32 t=*(u32 *)swap;*(u32 *)swap=*(((1) + ((u32 *)swap)));*(((1) + ((u32 *)swap)))=t;}
 if(status!=0){result=(R *)fn_1_14F04(); if(result->flags160==0x100){self->flags|=0x800;status=0;}else{
  *(P *)out0=*(P *)&result->v180;*(u32 *)((u8 *)out0+8)=result->v188; *(P *)out1=*(P *)&local;*(u32 *)((u8 *)out1+8)=*(u32 *)&local.z;
  if((result->flags160&0x600)!=0){actor=fn_1_868C0((s8)self->id);if((self->field58c&0x10)==0){if((s8)self->v474!=-1)fn_1_F7338((s8)self->v474,2,30);
   self->flags|=0x800;self->flags|=0x80;self->flags|=0x00800000;self->flags|=0x40000000;self->field58c|=0x10;
   *(f32 *)((u8 *)self+0x184)=*(const f32 *)(const void *)&lbl_1_rodata_84C;*(f32 *)((u8 *)self+0x224)=*(const f32 *)(const void *)&lbl_1_rodata_84C;
   *(f32 *)((u8 *)self+0x94)=*(const f32 *)(const void *)&lbl_1_rodata_84C;*(f32 *)((u8 *)self+0x98)=*(const f32 *)(const void *)&lbl_1_rodata_84C;*(f32 *)((u8 *)self+0x9c)=*(const f32 *)(const void *)&lbl_1_rodata_84C;*(f32 *)((u8 *)self+0xa0)=*(const f32 *)(const void *)&lbl_1_rodata_84C;*(f32 *)((u8 *)self+0xa4)=*(const f32 *)(const void *)&lbl_1_rodata_84C;*(f32 *)((u8 *)self+0xa8)=*(const f32 *)(const void *)&lbl_1_rodata_84C;*(f32 *)((u8 *)self+0x17c)=*(const f32 *)(const void *)&lbl_1_rodata_84C;
   self->field58c&=~0x80;*(u32 *)((u8 *)actor+0x390)&=~0x200000;*(u32 *)((u8 *)actor+0x390)|=0x01000000;}} if((result->flags160&0x100)!=0)self->flags|=0x800;}}
 if(status==0){f32 z=*(const f32 *)(const void *)&lbl_1_rodata_84C;out0->x=z;out0->y=z;out0->z=z;out1->x=z;out1->y=z;out1->z=z;} return status;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_2A694 */

/* fzgx:begin fn_1_2A8D0 */
/* Input to the collision query: a point at 0xc and a direction at 0x18. */
typedef struct ColiQuery {
    u8 p[0xc];
    Sig_fn_1_2A694_V pos;
    Sig_fn_1_2A694_V dir;
} ColiQuery;

/* Collision result record returned by fn_1_14F04. */
typedef struct ColiResult {
    u8 p0[0x40];
    u32 hit3;
    u8 p1[0x1c];
    Sig_fn_1_2A694_V normal3;
    u8 p2[0xc];
    u32 attr3;
    u8 p3[0xc];
    u32 hit1;
    u8 p4[0x1c];
    Sig_fn_1_2A694_V normal1;
    u8 p5[0xc];
    u32 attr1;
    u8 p6[0xc];
    u32 hit0;
    u8 p7[0x1c];
    Sig_fn_1_2A694_V normal0;
    u8 p8[0xc];
    u32 attr0;
    u8 p9[0x54];
    u32 flags2;
    u8 pa[0x1c];
    Sig_fn_1_2A694_V normal2;
} ColiResult;



int fn_1_2A8D0(Sig_fn_1_2A694_O *obj, ColiQuery *query, Sig_fn_1_2A694_V *swap, u32 arg3, Sig_fn_1_2A694_V *normals, u32 *attrs, u32 *masks, u32 bit) { ColiTarget *target;
    ColiResult *res;
    int result;
    u32 flags;
    s8 slot;
    u32 tmp;
    struct { u32 a[4]; } loc_20;
    Sig_fn_1_2A694_V dir;
    u32 loc_10;
    Sig_fn_1_2A694_O *loc_C;
    u32 loc_8;

    lbl_8006E1B0(query, &query->dir);
    lbl_8006DAEC();
    dir = query->dir;
    result = fn_1_15578( (void *)(Sig_fn_1_2A694_V *)(&dir), (void *)(Sig_fn_1_2A694_V *)(&query->pos), &loc_10, &loc_20, arg3, (void *)(u32 *)(&obj->field49c->v9c), (void *)(u32)(obj->field49c->v98), (void *)(Sig_fn_1_2A694_V *)(swap), obj->field498, (void *)(Sig_fn_1_2A694_O *)(obj));
    lbl_8006DB30();
    if (swap != NULL) {
        /* swap the first two words without going through the FPU */
        u32 *w = (u32 *)swap;
        tmp = w[0];
        w[0] = w[1];
        w[1] = tmp;
    }
    normals[0].x = 0.0f;
    normals[0].y = 0.0f;
    normals[0].z = 0.0f;
    normals[1].x = 0.0f;
    normals[1].y = 0.0f;
    normals[1].z = 0.0f;
    normals[2].x = 0.0f;
    normals[2].y = 0.0f;
    normals[2].z = 0.0f;
    normals[3].x = 0.0f;
    normals[3].y = 0.0f;
    normals[3].z = 0.0f;
    attrs[3] = 0;
    attrs[2] = 0;
    attrs[1] = 0;
    attrs[0] = 0;
    if (result != 0) {
        res = (ColiResult *)fn_1_14F04();
        if (res->hit0 != 0) {
            normals[0] = res->normal0;
            attrs[0] = res->attr0;
            masks[0] |= bit;
        }
        if (res->hit1 != 0) {
            normals[1] = res->normal1;
            attrs[1] = res->attr1;
            masks[1] |= bit;
        }
        flags = res->flags2;
        if (flags != 0) {
            if (flags & 0x100) {
                result = 0;
                obj->flags |= 0x800;
            } else if (flags & 0x600) {
                normals[2] = res->normal2;
                target = (ColiTarget *)fn_1_868C0((s8)obj->id);
                if (!(obj->field58c & 0x10)) {
                    slot = (s8)obj->v474;
                    if (slot != -1) {
                        fn_1_F7338(slot, (void *)(int)(2), (void *)(int)(30));
                    }
                    obj->flags |= 0x800;
                    obj->flags |= 0x80;
                    obj->flags |= 0x800000;
                    obj->flags |= 0x40000000;
                    obj->field58c |= 0x10;
                    obj->f184 = 0.0f;
                    obj->f224 = 0.0f;
                    obj->f94 = 0.0f;
                    obj->f98 = 0.0f;
                    obj->f9c = 0.0f;
                    obj->fa0 = 0.0f;
                    obj->fa4 = 0.0f;
                    obj->fa8 = 0.0f;
                    obj->f17c = 0.0f;
                    obj->field58c &= ~0x80;
                    target->flags390 &= ~0x200000;
                    target->flags390 |= 0x1000000;
                }
            } else {
                normals[2] = res->normal2;
            }
            masks[2] |= bit;
        }
        if (res->hit3 != 0) {
            normals[3] = res->normal3;
            attrs[3] = res->attr3;
            masks[3] |= bit;
        }
    }
    return result;
}
/* fzgx:end fn_1_2A8D0 */

/* fzgx:begin fn_1_2B478 */
struct fn_1_2B478_Arg0 {
    u8 pad_0[0x1C8];
    f32 unk_1C8;
    u8 pad_1CC[0x2D0];
    u32 unk_49C;
};
struct fn_1_2B478_lbl_801A66CC {
    u32 unk_0;
};

f32 fn_1_2B478(void *arg0) {
    void *temp_r5;

    temp_r5 = (void *)(*(void **)((u8 *)(arg0) + 1180));
    if (!((*(s32 *)((u8 *)(temp_r5) + 124)) & 0x01800000) || ((*(f32 *)((u8 *)(arg0) + 456)) <= (*(f32 *)((u8 *)(&(*(f32 *)&lbl_1_rodata_84C)) + 0)))) {
        return *(f32 *)((u8 *)(&(*(f32 *)&lbl_1_rodata_854)) + 0);
    }
    (*(f32 *)((u8 *)((*(struct fn_1_2B478_lbl_801A66CC *)&lbl_801A66CC).unk_0) + 212)) = (f32) -(*(f32 *)((u8 *)(lbl_801A6D00.unk_0) + 8));
    (*(f32 *)((u8 *)((*(struct fn_1_2B478_lbl_801A66CC *)&lbl_801A66CC).unk_0) + 216)) = (f32) -(*(f32 *)((u8 *)(lbl_801A6D00.unk_0) + 24));
    (*(f32 *)((u8 *)((*(struct fn_1_2B478_lbl_801A66CC *)&lbl_801A66CC).unk_0) + 220)) = (f32) -(*(f32 *)((u8 *)(lbl_801A6D00.unk_0) + 40));
    return lbl_8006D6FC((void *)((*(struct fn_1_2B478_lbl_801A66CC *)&lbl_801A66CC).unk_0 + 0xD4), (void *)((u8 *)(temp_r5) + 0x50));
}
/* fzgx:end fn_1_2B478 */

/* fzgx:begin fn_1_2B524 noprologue */
#include "types.h"
#include "psvec.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 52.0f;
    s = 0.0625f;
    s = 45.0f;
    s = 0.0f;
    s = 1.7000000476837158f;
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.5f;
    d = 4503599627370496.0;
    s = 40.0f;
    s = 348.0f;
    s = 36.0f;
    s = 4.0f;
    s = 0.6000000238418579f;
    s = 5.0f;
    s = 0.05000000074505806f;
    s = 1000.0f;
    s = 8.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 216.0;
    d = 2.0;
    s = 0.25f;
    s = 0.07000000029802322f;
    s = 0.20000000298023224f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.834999918937683f;
}
static const u32 fzgx_pool_table6[1] = {0xAE147AE1};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.0f;
    s = 1.7999999523162842f;
    s = 1.399999976158142f;
    s = 1.5f;
    s = 1.2000000476837158f;
    s = 2.299999952316284f;
    s = 0.4000000059604645f;
    s = 3.200000047683716f;
    s = 0.15000000596046448f;
    s = -0.25f;
    s = 0.1599999964237213f;
    s = 0.11999999731779099f;
    s = 0.07999999821186066f;
    s = 0.44999998807907104f;
    s = 0.699999988079071f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6000000238418579;
    s = 0.3100000023841858f;
    s = 0.029999999329447746f;
    s = 0.009999999776482582f;
    s = 700.0f;
    s = 1.7674999237060547f;
}
static const u32 fzgx_pool_table10[1] = {0xA3D70A3D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5699999928474426f;
}
static const u32 fzgx_pool_table12[4] = {0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.10000000149011612f;
    s = 200.0f;
    s = 0.019999999552965164f;
    d = 0.009999999776482582;
    s = 0.03999999910593033f;
    s = 0.800000011920929f;
    d = 13.88888888888889;
    s = 13.88888931274414f;
    s = 1.1920928955078125e-07f;
    s = 800.0f;
    s = 0.949999988079071f;
    s = 2.200000047683716f;
    s = -0.5f;
    s = 0.0020000000949949026f;
    s = 0.0010000000474974513f;
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    d = 0.1;
    s = 80.0f;
    s = 1700.0f;
    d = 90.0;
    s = 0.3333333432674408f;
    s = -5000.0f;
    s = 900.0f;
    s = -10000.0f;
    s = 10.0f;
    s = 100.0f;
    s = 400.0f;
    s = 0.9900000095367432f;
    s = 20.0f;
    s = 1.0099999904632568f;
    d = 1.0;
    d = 0.550000011920929;
    s = 3.4000000953674316f;
    s = 0.75f;
    s = 182.04444885253906f;
    s = -45.0f;
    d = 0.9259259259259259;
    d = 5.555555555555555;
    s = 1.1299999952316284f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.10000000149011612;
    d = 0.30000001192092896;
    d = 0.046296296296296294;
    s = 0.8999999761581421f;
    s = 1.1100000143051147f;
    d = 0.0023148148148148147;
    d = 0.5;
    d = 0.004629629629629629;
    d = 0.023148148148148147;
    s = 2000.0f;
    s = 500.0f;
    d = 0.2;
    s = 0.6399999856948853f;
    s = 0.3499999940395355f;
    d = 1.8518518518518519;
    d = 3.4000000953674316;
    d = 1.7000000476837158;
    d = 3.0;
    d = 1.5;
    s = -0.4000000059604645f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 3.240740740740741;
    s = -1.0f;
    s = 9.999999747378752e-05f;
    s = 0.014000000432133675f;
    s = 9.0f;
    s = 60.0f;
    s = 3.0f;
    s = 0.1666666716337204f;
    s = 1200.0f;
    s = 1600.0f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1000.0;
    d = 0.699999988079071;
    d = 1.1920928955078125e-07;
    s = 0.003000000026077032f;
    s = 0.125f;
    s = -2000.0f;
    s = 600.0f;
    s = 6.0f;
    s = 300.0f;
    s = 1.1111111640930176f;
    s = 10000.0f;
    s = -3.0f;
    s = 10430.3779296875f;
    d = 0.0;
    s = 0.9919999837875366f;
    s = 0.00800000037997961f;
    s = 50.0f;
    s = 15.0f;
    s = 4000.0f;
}
static const u32 fzgx_pool_table22[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 3.6;
    s = 1.2999999523162842f;
    s = 0.009000000543892384f;
    d = 9990.0;
    s = 46.25f;
    s = 1100.0f;
    s = 120.0f;
    s = -50.0f;
    d = 4503601774854144.0;
    s = 30.0f;
    s = -0.20000000298023224f;
    s = 90.0f;
    s = 0.006000000052154064f;
    d = 4.62962962962963;
    s = -5.0f;
    s = 4.5f;
    s = 3640.0f;
    s = 2.5f;
    s = -0.30000001192092896f;
    s = 5.999999848427251e-05f;
    s = 65536.0f;
    s = 6.666666507720947f;
    s = 3.5f;
    s = 0.000244140625f;
    s = 9000.0f;
}
static const u32 fzgx_pool_table24[5] = {0x02010003, 0x02030103, 0x00020302, 0x03010001, 0x01000200};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.016203703703703703;
}
#pragma section code_type ".text"

typedef struct {
    f32 x, y, z;
} Fn2B524_Vec;

typedef struct {
    u8 pad_0[8];
    f32 ang;
    u8 pad_c[0x7c - 0xc];
    u32 h0, h1, h2;
    u8 pad_88[0xa0 - 0x88];
    Fn2B524_Vec vel;
    u8 pad_ac[0x224 - 0xac];
    u32 h3;
} Fn2B524_Self;

extern u32 fn_8006E2B0(void *, void *);

#pragma opt_propagation off
static inline f32 fn_1_2B524_add(f32 a, f32 b) {
    return a + b;
}
static inline void fn_1_2B524_cross(const Fn2B524_Vec *a, const Fn2B524_Vec *b, Fn2B524_Vec *out) {
    f32 ax, ay, az, bx, bz, by;
    f32 x, y, z;
    ax = a->x;
    ay = a->y;
    az = a->z;
    bx = b->x;
    bz = b->z;
    by = b->y;
    x = ay * bz;
    x = x - az * by;
    y = (f32)(az * bx) - ax * bz;
    z = (f32)(ax * by) - ay * bx;
    out->x = x;
    out->y = y;
    out->z = z;
}
#pragma opt_propagation on
void fn_1_2B524(Fn2B524_Self *self) {
    f32 fzgx_live;
    f32 *fzgx_value;
    u32 h;
    u32 a, b;
    f32 fb, fa;
    f32 mtx[3];
    Fn2B524_Vec v;
    Fn2B524_Vec r;
    Fn2B524_Vec w;

    a = self->h0 ^ self->h1;
    h = self->h2 ^ a;
    h = h ^ self->h3;
    a = (h ^ *(u32 *)&self->vel.x) & 0xFFFF;
    b = (h ^ *(u32 *)&self->vel.y) & 0xFFFF;
    fa = (f32)(2.0f * ((f32)a / 65536.0f)) - 1.0f;
    fb = 0.5f + (f32)(1.5f * ((f32)b / 65536.0f));
    if (fa > 0.0f) {
        v.x = fn_1_2B524_add(fa, 0.5f);
    } else {
        v.x = fa - 0.5f;
    }
    mtx[0] = 0.0f;
    mtx[1] = 0.016203703703703703 * self->ang;
    mtx[2] = 0.0f;
    v.y = 0.0f;
    fzgx_value = &(v.z);
    *fzgx_value = fb;
    fn_8006E2B0(mtx, &w);
    fn_1_2B524_cross(&v, &w, &r);
    psvec_add(&self->vel.x, &r.x, &self->vel.x);
}
/* fzgx:end fn_1_2B524 */

/* fzgx:begin fn_1_2B684 pool noprologue */
#include "types.h"
#include "psvec.h"
#include "game/main_rel/stcoli_types.h"
#include "game/vec3.h"

typedef struct Fn2B684Obj {
    u8 pad_0[0x8];
    f32 mass;            /* 0x08 */
    u8 pad_C[0x70];
    u32 seed7C;          /* 0x7C */
    u32 seed80;          /* 0x80 */
    u32 seed84;          /* 0x84 */
    u8 pad_88[0xC];
    Vec3f vel;           /* 0x94 */
    Vec3f posA0;         /* 0xA0 */
    u8 pad_AC[0xA0];
    u8 mtx14C[0x30];     /* 0x14C */
    f32 f17C;            /* 0x17C */
    u8 pad_180[0x3C];
    Vec3f dir1BC;        /* 0x1BC */
    u8 pad_1C8[0x318];
    u16 timer;           /* 0x4E0 */
    u8 pad_4E2[0xE];
    Vec3f pos4F0;        /* 0x4F0 */
    u8 pad_4FC[0x90];
    u32 flags;           /* 0x58C */
} Fn2B684Obj;

extern void lbl_8006E1F0(Vec3f *, f32, f32, f32);
extern void fn_8006E2B0(void *, void *);
extern void lbl_8006D5F0(void *, void *, f32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBAC(void *);
extern f32 lbl_8006D6FC(void *, void *);
extern f32 lbl_8006D0B4(f32);
extern void mathutil_mtxA_from_quat(void *);
extern void lbl_8006DFC4(void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DB30(void);

extern void fzgx_use_f(f32);
extern void fzgx_use_d(f64);

/* Literal-pool primer: fixes the TU pool layout of lbl_1_rodata_840. */
#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_pool_fn_1_2B684(void) {
    fzgx_use_f(52.0f);
    fzgx_use_f(0.0625f);
    fzgx_use_f(45.0f);
    fzgx_use_f(0.0f);
    fzgx_use_f(1.7f);
    fzgx_use_f(1.0f);
    fzgx_use_f(0.1f);
    fzgx_use_f(0.5f);
    fzgx_use_d(4503599627370496.0);
    fzgx_use_d(34359747031.0);
    fzgx_use_f(36.0f);
    fzgx_use_f(4.0f);
    fzgx_use_f(0.6f);
    fzgx_use_f(5.0f);
    fzgx_use_f(0.05f);
    fzgx_use_f(1000.0f);
    fzgx_use_d(131072.0);
    fzgx_use_d(216.0);
    fzgx_use_d(2.0);
    fzgx_use_f(0.25f);
    fzgx_use_f(0.07f);
    fzgx_use_f(0.2f);
    fzgx_use_d(0.84);
    fzgx_use_f(2.0f);
    fzgx_use_f(1.8f);
    fzgx_use_f(1.4f);
    fzgx_use_f(1.5f);
    fzgx_use_f(1.2f);
    fzgx_use_f(2.3f);
    fzgx_use_f(0.4f);
    fzgx_use_f(3.2f);
    fzgx_use_f(0.15f);
    fzgx_use_f(-0.25f);
    fzgx_use_f(0.16f);
    fzgx_use_f(0.12f);
    fzgx_use_f(0.08f);
    fzgx_use_f(0.45f);
    fzgx_use_f(0.7f);
    fzgx_use_d(0.6000000238418579);
    fzgx_use_f(0.31f);
    fzgx_use_f(0.03f);
    fzgx_use_f(0.01f);
    fzgx_use_f(700.0f);
    fzgx_use_d(0.57);
    fzgx_use_f(0.57f);
}

static const f32 fzgx_quat_91C[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
extern void fzgx_use_p(const void *);

__declspec(section ".fzgxpool") void fzgx_pool2_fn_1_2B684(void) {
    fzgx_use_p(fzgx_quat_91C);
    fzgx_use_f(-0.1f);
}

static const f32 fzgx_span_930[33] = {
    200.0f, 0.02f, 1.035f, 2.0f, 0.04f, 0.8f, 2.6840277f, 1.971901e30f, 13.888889f,
    1.1920929e-7f, 800.0f, 0.95f, 2.2f, -0.5f, 0.002f, 0.001f, 0.3f, 0.0f, 1.6999999f,
    -1.5881868e-23f, 1.4499999f, -1.5881868e-23f, 80.0f, 1700.0f, 3.3515625f, 0.0f,
    0.33333334f, -5000.0f, 900.0f, -10000.0f, 10.0f, 100.0f, 400.0f,
};

__declspec(section ".fzgxpool") void fzgx_pool3_fn_1_2B684(void) {
    fzgx_use_p(fzgx_span_930);
    fzgx_use_f(0.99f);
}

static const f32 fzgx_span_9B8[78] = {
    20.0f, 1.01f, 1.875f, 0.0f, 1.7624999f, -1.0842022e-19f, 3.4f, 0.75f, 182.04445f, -45.0f,
    1.8564814f, 3.8506526e24f, 2.347222f, -2.2789315e-30f, 1.13f, 0.0f, 1.4499999f, -1.0842022e-19f,
    1.65f, 2.0f, 1.3101851f, -2.6592785e27f, 0.9f, 1.11f, 0.88657403f, -0.0787037f, 1.75f, 0.0f,
    0.94907403f, -0.0787037f, 1.1851851f, -2.6592785e27f, 2000.0f, 500.0f, 1.5749999f,
    -1.5881868e-23f, 0.64f, 0.35f, 1.9814814f, 3.8506526e24f, 2.175f, 2.0f, 1.9625f, 2.0f, 2.125f,
    0.0f, 1.9375f, 0.0f, -0.4f, 0.0f, 2.1550925f, 1.0092287e36f, -1.0f, 0.0001f, 0.014f, 9.0f,
    60.0f, 3.0f, 0.16666667f, 1200.0f, 1600.0f, 0.0f, 4.4765625f, 0.0f, 1.8f, 3.689349e19f, 0.25f,
    0.0f, 0.003f, 0.125f, -2000.0f, 600.0f, 6.0f, 300.0f, 1.1111112f, 10000.0f, -3.0f, 10430.378f,
};

__declspec(section ".fzgxpool") void fzgx_pool4_fn_1_2B684(void) {
    fzgx_use_p(fzgx_span_9B8);
    fzgx_use_d(0.0);
}

static const f32 fzgx_span_AF8[30] = {
    0.992f, 0.008f, 50.0f, 15.0f, 4000.0f, 0.0f, 2.1999998f, -107374184.0f, 1.3f, 0.009000001f,
    6.109741f, 0.0f, 46.25f, 1100.0f, 120.0f, -50.0f, 176.0f, -0.0f, 30.0f, -0.2f, 90.0f, 0.006f,
    2.2893517f, -5.943034e-19f, -5.0f, 4.5f, 3640.0f, 2.5f, -0.3f, 0.00006f,
};

__declspec(section ".fzgxpool") void fzgx_pool5_fn_1_2B684(void) {
    fzgx_use_p(fzgx_span_AF8);
    fzgx_use_f(65536.0f);
}

static const f32 fzgx_span_B74[11] = {
    6.6666665f, 3.5f, 0.00024414063f, 9000.0f, 9.477427e-38f, 9.62465e-38f, 1.8475e-40f,
    3.7909697e-37f, 2.3511322e-38f, 1.1296296f, 4.111937e-16f,
};

__declspec(section ".fzgxpool") void fzgx_pool6_fn_1_2B684(void) {
    fzgx_use_p(fzgx_span_B74);
    fzgx_use_f(0.0015f);
    fzgx_use_f(450.0f);
    fzgx_use_f(1365.0f);
}

#pragma opt_propagation off
static inline void fn_1_2B684_cross(Vec3f *a, Vec3f *b, Vec3f *out) {
    f32 ax = a->x, ay = a->y, bz = b->z;
    f32 az = a->z, bx = b->x, by = b->y;
    f32 x = ay * bz;
    f32 y = az * bx;
    f32 z;
    y -= ax * bz;
    x -= az * by;
    z = ax * by;
    z -= ay * bx;
    out->x = x;
    out->y = y;
    out->z = z;
}
#pragma opt_propagation reset

static inline f32 fn_1_2B684_clamp(f32 t) {
    if (t < 0.0f) return 0.0f;
    if (t > 1.0f) return 1.0f;
    return t;
}

static inline f32 fn_1_2B684_square(f32 t) {
    if (t < 0.0) return 0.0f;
    return t * t;
}

static inline f32 fn_1_2B684_lensq(Vec3f *v) {
    return v->z * v->z + (v->y * v->y + v->x * v->x);
}

#pragma opt_common_subs off
#pragma opt_propagation off
void fn_1_2B684(Fn2B684Obj *obj) {
    f32 fzgx_live;
    f32 dirv[3];
#define dir (*(Vec3f *)dirv)
    Vec3f push;
    Vec3f spin;
    Vec3f torque;
    Vec3f up;
    Vec3f axis;
    Quat q;
    u32 hash;
    f32 t;
    f32 k;
    f32 scale;
    f32 dot;
    f32 top;
    f32 sq;

    hash = obj->seed7C ^ obj->seed80 ^ obj->seed84;
    dir.x = (f32)(2.0f * ((f32)((hash ^ *(u32 *)&obj->posA0.x) & 0xFFFF) / 65536.0f)) - 1.0f;
    dir.y = 0.0f;
    dir.z = (f32)(2.0f * ((f32)((hash ^ *(u32 *)&obj->posA0.y) & 0xFFFF) / 65536.0f)) - 1.0f;
    t = dir.x;
    if (t > 0.0f) {
        t += 0.5f;
    } else {
        t -= 0.5f;
    }
    dir.x = t;
    if (dir.z > 0.0f) {
        dir.z += 0.5f;
    } else {
        dir.z -= 0.5f;
    }

    t = (f32)(0.0015f * obj->f17C) - 1.0f;
    k = fn_1_2B684_clamp(t);
    top = 450.0f;
    scale = k * (top / 216.0);

    lbl_8006E1F0(&push, -dir.x, 0.5f, -dir.z);
    fzgx_live = obj->mass;
    psvec_scale(&push, scale * fzgx_live, &push);
    obj->flags |= 2;
    fn_8006E2B0(&push, &spin);
    psvec_scale(&spin, 0.5f, &spin);
    fn_1_2B684_cross(&dir, &spin, &torque);
    psvec_add(&obj->posA0, &torque, &obj->pos4F0);
    fzgx_live = obj->mass;
    lbl_8006D5F0(&obj->dir1BC, &push, 0.2f * (scale * fzgx_live));
    psvec_add(&obj->vel, &push, &obj->vel);

    if (obj->timer > 30) {
        obj->flags |= 0x20;
        lbl_8006DAEC();
        lbl_8006DBAC(obj->mtx14C);
        lbl_8006E1F0(&up, 0.0f, 1.0f, 0.0f);
        dot = lbl_8006D6FC(&up, &obj->dir1BC);
        if (dot < 0.99f) {
            f32 by, bz, y, x, bx, az, ay, ax, z;
            ax = up.x; ay = up.y; az = up.z;
            bz = obj->dir1BC.z; bx = obj->dir1BC.x; by = obj->dir1BC.y;
            x = ay * bz;
            y = az * bx;
            z = ax * by;
            x -= az * by;
            y -= ax * bz;
            z -= ay * bx;
            axis.x = x;
            axis.y = y;
            axis.z = z;
            sq = axis.x * axis.x;
            sq += axis.y * axis.y;
            sq += axis.z * axis.z;
            if (lbl_8006D0B4(sq) > 0.1f) {
                sq = fn_1_2B684_square(dot);
                t = 1.0f - sq;
                fn_8006E7E4(&q, &axis, (s32)(1365.0f * t));
                mathutil_mtxA_from_quat(&q);
                lbl_8006DFC4(obj->mtx14C);
                lbl_8006DB74(obj->mtx14C);
            }
        }
        lbl_8006DB30();
    }

    if (obj->timer < 2) {
        obj->timer = 2;
    } else if (++obj->timer >= 240) {
        obj->timer = 240;
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_2B684 */

/* fzgx:begin fn_1_2BA48 */
typedef struct {
    f32 x, y, z;
} Fn2BA48_Vec;

typedef struct {
    u32 flags;
    s16 id;
    u8 pad_6[0x7c - 6];
    Fn2BA48_Vec v7c;
    Fn2BA48_Vec v88;
    Fn2BA48_Vec v94;
    u8 pad_a0[0x390 - 0xa0];
    u8 pad_390[0x474 - 0x390];
    s8 s474;
    s8 s475;
    u8 pad_476[0x4e0 - 0x476];
    u16 timer;
    Fn2BA48_Vec v4e4;
    Fn2BA48_Vec v4f0;
    u8 pad_4fc[0x50d - 0x4fc];
    u8 cnt;
    u8 pad_50e[0x58c - 0x50e];
    u32 flags2;
} Fn2BA48_Obj;



void fn_1_2BA48(Fn2BA48_Obj *self) {
    s32 limit;
    u8 n;
    s32 t;

    limit = 0x3c;
    if (*(s16 *)&lbl_1_bss_960 != 9) {
        limit = 0xf0;
    }
    if (!(self->flags & 2)) {
        fn_1_2B684(self);
    }
    if (self->timer < 0x3c) {
        psvec_add(&self->v4f0, &self->v4e4, &self->v4e4);
    }
    t = self->cnt + 1;
    self->cnt = t;
    n = t;
    if (n >= (u16)limit) {
        if (!(self->flags & 2)) {
            Fn2BA48_Other *o;
            f32 z = (((f32 *)&lbl_1_rodata_84C))[0];
            self->v94.x = z;
            self->v94.y = z;
            self->v94.z = z;
            self->v7c = self->v88;
            o = (Fn2BA48_Other *)fn_1_868C0((s8)self->id);
            if (!(self->flags2 & 0x90)) {
                self->flags2 |= 0x80;
                self->flags2 |= 0x100;
                o->f390 |= 0x200000;
                if (self->s474 != -1) {
                    fn_1_F7338(self->s474, (void *)(int)(2), (void *)(int)(0x1e));
                }
            }
            if (lbl_801A66C8 + self->id == 0) {
                fn_1_A2D84(0xa9092e00);
                if (self->s475 != -1 && !(self->flags & 0x4000200)) {
                    fn_1_A2D84(0xa9091200);
                }
            }
        }
        self->cnt = limit;
    }
}
/* fzgx:end fn_1_2BA48 */

/* fzgx:begin fn_1_2BBD0 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Fn2BBD0_Vec;


typedef struct {
    u8 pad_0[0x7c];
    Fn2BBD0_Vec pos;
    u8 pad_88[0xec - 0x88];
    u8 mtx[0x4b4 - 0xec];
    Fn2BBD0_Vec dir;
    u8 active;
    u8 owner;
} Fn2BBD0_Self;

typedef struct {
    u8 pad_0[4];
    s16 id;
    u8 pad_6[0x7c - 6];
    Fn2BBD0_Vec pos;
} Fn2BBD0_Other;


/* Keep the translation loads in their own registers (retail stores x, y, z from f2, f1, f0). */
#pragma opt_propagation off
void fn_1_2BBD0(Fn2BBD0_Self *self, Fn2BBD0_Other *other, f32 dist) {
    Fn2BBD0_Vec local;
    f32 dx, dy, dz;
    f32 len;

    if (self->active == 0) {
        dx = self->dir.x;
        dy = self->dir.y;
        dz = self->dir.z;
        len = dx * dx;
        len += dy * dy;
        len += dz * dz;
        if (dist < lbl_8006D0B4(len)) {
            f32 z, y, x;

            lbl_8006DAEC();
            lbl_8006DBAC(self->mtx);
            /* Translation column of the locked-cache matrix. */
            x = self->pos.x;
            y = self->pos.y;
            z = self->pos.z;
            *(f32 *)(LC_BASE + 0x0C) = x;
            *(f32 *)(LC_BASE + 0x1C) = y;
            *(f32 *)(LC_BASE + 0x2C) = z;
            fn_8006E250(&other->pos, &local);
            lbl_8006D668(&local);
            if (local.z < -0.1f) {
                self->dir = local;
                self->owner = other->id;
                lbl_8006D668(&self->dir);
            }
            lbl_8006DB30();
        }
    } else if (self->owner == other->id) {
        f32 z, y, x;

        lbl_8006DAEC();
        lbl_8006DBAC(self->mtx);
        x = self->pos.x;
        y = self->pos.y;
        z = self->pos.z;
        *(f32 *)(LC_BASE + 0x0C) = x;
        *(f32 *)(LC_BASE + 0x1C) = y;
        *(f32 *)(LC_BASE + 0x2C) = z;
        fn_8006E250(&other->pos, &self->dir);
        lbl_8006D668(&self->dir);
        if (self->dir.z > -0.1f) {
            self->dir.z = -0.1f;
        }
        lbl_8006DB30();
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_2BBD0 */

/* fzgx:begin fn_1_2BD30 noprologue */
#include "game/main_rel/camera_types.h"
#include "psvec.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 52.0f;
    s = 0.0625f;
    s = 45.0f;
    s = 0.0f;
    s = 1.7000000476837158f;
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.5f;
    d = 4503599627370496.0;
    s = 40.0f;
    s = 348.0f;
    s = 36.0f;
    s = 4.0f;
    s = 0.6000000238418579f;
    s = 5.0f;
    s = 0.05000000074505806f;
    s = 1000.0f;
    s = 8.0f;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 216.0;
    d = 2.0;
    s = 0.25f;
    s = 0.07000000029802322f;
    s = 0.20000000298023224f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.834999918937683f;
}
static const unsigned long fzgx_pool_table6[1] = {0xAE147AE1};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.0f;
    s = 1.7999999523162842f;
    s = 1.399999976158142f;
    s = 1.5f;
    s = 1.2000000476837158f;
    s = 2.299999952316284f;
    s = 0.4000000059604645f;
    s = 3.200000047683716f;
    s = 0.15000000596046448f;
    s = -0.25f;
    s = 0.1599999964237213f;
    s = 0.11999999731779099f;
    s = 0.07999999821186066f;
    s = 0.44999998807907104f;
    s = 0.699999988079071f;
}
static const unsigned long fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6000000238418579;
    s = 0.3100000023841858f;
    s = 0.029999999329447746f;
    s = 0.009999999776482582f;
    s = 700.0f;
    s = 1.7674999237060547f;
}
static const unsigned long fzgx_pool_table10[1] = {0xA3D70A3D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5699999928474426f;
}
static const unsigned long fzgx_pool_table12[4] = {0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.10000000149011612f;
    s = 200.0f;
    s = 0.019999999552965164f;
    d = 0.009999999776482582;
    s = 0.03999999910593033f;
    s = 0.800000011920929f;
    d = 13.88888888888889;
    s = 13.88888931274414f;
    s = 1.1920928955078125e-07f;
    s = 800.0f;
    s = 0.949999988079071f;
    s = 2.200000047683716f;
    s = -0.5f;
    s = 0.0020000000949949026f;
    s = 0.0010000000474974513f;
    s = 0.30000001192092896f;
}
static const unsigned long fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    d = 0.1;
    s = 80.0f;
    s = 1700.0f;
    d = 90.0;
    s = 0.3333333432674408f;
    s = -5000.0f;
    s = 900.0f;
    s = -10000.0f;
    s = 10.0f;
    s = 100.0f;
    s = 400.0f;
    s = 0.9900000095367432f;
    s = 20.0f;
    s = 1.0099999904632568f;
    d = 1.0;
    d = 0.550000011920929;
    s = 3.4000000953674316f;
    s = 0.75f;
    s = 182.04444885253906f;
    s = -45.0f;
    d = 0.9259259259259259;
    d = 5.555555555555555;
    s = 1.1299999952316284f;
}
static const unsigned long fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.10000000149011612;
    d = 0.30000001192092896;
    d = 0.046296296296296294;
    s = 0.8999999761581421f;
    s = 1.1100000143051147f;
    d = 0.0023148148148148147;
    d = 0.5;
    d = 0.004629629629629629;
    d = 0.023148148148148147;
    s = 2000.0f;
    s = 500.0f;
    d = 0.2;
    s = 0.6399999856948853f;
    s = 0.3499999940395355f;
    d = 1.8518518518518519;
    d = 3.4000000953674316;
    d = 1.7000000476837158;
    d = 3.0;
    d = 1.5;
    s = -0.4000000059604645f;
}
static const unsigned long fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const unsigned long *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 3.240740740740741;
    s = -1.0f;
    s = 9.999999747378752e-05f;
    s = 0.014000000432133675f;
    s = 9.0f;
    s = 60.0f;
    s = 3.0f;
    s = 0.1666666716337204f;
    s = 1200.0f;
    s = 1600.0f;
}
static const unsigned long fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const unsigned long *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1000.0;
    d = 0.699999988079071;
    d = 1.1920928955078125e-07;
    s = 0.003000000026077032f;
    s = 0.125f;
    s = -2000.0f;
    s = 600.0f;
    s = 6.0f;
    s = 300.0f;
    s = 1.1111111640930176f;
    s = 10000.0f;
    s = -3.0f;
    s = 10430.3779296875f;
    d = 0.0;
    s = 0.9919999837875366f;
    s = 0.00800000037997961f;
    s = 50.0f;
    s = 15.0f;
    s = 4000.0f;
}
static const unsigned long fzgx_pool_table22[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const unsigned long *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 3.6;
    s = 1.2999999523162842f;
    s = 0.009000000543892384f;
    d = 9990.0;
    s = 46.25f;
    s = 1100.0f;
    s = 120.0f;
    s = -50.0f;
    d = 4503601774854144.0;
    s = 30.0f;
    s = -0.20000000298023224f;
    s = 90.0f;
    s = 0.006000000052154064f;
    d = 4.62962962962963;
    s = -5.0f;
    s = 4.5f;
    s = 3640.0f;
    s = 2.5f;
    s = -0.30000001192092896f;
    s = 5.999999848427251e-05f;
    s = 65536.0f;
    s = 6.666666507720947f;
    s = 3.5f;
    s = 0.000244140625f;
    s = 9000.0f;
}
static const unsigned long fzgx_pool_table24[5] = {0x02010003, 0x02030103, 0x00020302, 0x03010001, 0x01000200};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const unsigned long *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.016203703703703703;
    s = 0.001500000013038516f;
    s = 450.0f;
    s = 1365.0f;
    s = 9990.0f;
    s = -10.0f;
}
static const unsigned long fzgx_pool_table26[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const unsigned long *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.05000000074505806;
}
#pragma section code_type ".text"

extern void lbl_8006DAEC(void);
extern void lbl_8006DBAC(Vec3 *);
extern void fn_8006E250(Vec3 *, Vec3 *);
extern void fn_8006E2B0(void *, Vec3 *);
extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D668(void *);
extern void lbl_8006E1C0(void *, void *);
extern void lbl_8006DB30(void);

typedef struct StcoliObj2BD30 {
    u8 pad0[0x8];
    f32 scale;          /* 0x08 */
    u8 padC[0x7C - 0xC];
    f32 posX;           /* 0x7C */
    f32 posY;           /* 0x80 */
    f32 posZ;           /* 0x84 */
    u8 pad88[0x94 - 0x88];
    f32 velX;           /* 0x94 */
    f32 velY;           /* 0x98 */
    f32 velZ;           /* 0x9C */
    u8 padA0[0xEC - 0xA0];
    Vec3 rot;           /* 0xEC */
    u8 padF8[0x1BC - 0xF8];
    u8 ref[0x10];       /* 0x1BC */
} StcoliObj2BD30;

typedef struct StcoliOut2BD30 {
    u8 pad0[0xC];
    Vec3 dir;           /* 0x0C */
    Vec3 axis;          /* 0x18 */
    u8 pad24[0x30 - 0x24];
    f32 speed;          /* 0x30 */
    f32 depth;          /* 0x34 */
} StcoliOut2BD30;

/* Locked-cache current matrix (translation column). */
#define CUR_MTX ((f32 *)0xE0000000) /* fzgx-allow: A2 locked-cache current matrix */

static inline void fn_1_2BD30_translate(f32 x, f32 y, f32 z) {
    CUR_MTX[3] = x;
    CUR_MTX[7] = y;
    CUR_MTX[11] = z;
}

static inline void fn_1_2BD30_set(Vec3 *v, f32 x, f32 y, f32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline int fn_1_2BD30_nonfinite(f32 x) {
    return (*(u32 *)&x & 0x7F800000) == 0x7F800000;
}

#pragma opt_common_subs off
static inline f32 fn_1_2BD30_read_pointer(StcoliObj2BD30 * owner) { return owner->velZ; }
#pragma opt_dead_assignments off
f32 fn_1_2BD30(StcoliObj2BD30 *obj, StcoliOut2BD30 *out, Vec3 *src) {
    f32 fzgx_live__;
    f32 fzgx_live_;
    f32 fzgx_live;
    Vec3 local;
    struct { f32 value; } m;
    f32 ax, ay, az;
    f32 vx, vy, vz;
    f32 lengthSquared;

    lbl_8006DAEC();
    lbl_8006DBAC(&obj->rot);
    fzgx_live = obj->posX;
    fzgx_live__ = obj->posY;
    fn_1_2BD30_translate(fzgx_live, fzgx_live__, obj->posZ);
    fn_8006E250(src, &out->dir);
    fn_8006E2B0(obj->ref, &local);
    psvec_sub(&out->dir, &local, &out->dir);
    lengthSquared = (f32)(out->dir.x * out->dir.x);
    lengthSquared += out->dir.y * out->dir.y;
    lengthSquared += out->dir.z * out->dir.z;
    if (lbl_8006D0B4(lengthSquared) > 1.1920929e-7f) {
        lbl_8006D668(&out->dir);
    } else {
        f32 negOne = -1.0f;
        fn_1_2BD30_set(&out->dir, 0.0f, 0.0f, negOne);
    }

    ax = __fabs(out->dir.x);
    ay = 0.05f * __fabs(out->dir.y);
    az = __fabs(out->dir.z);
    out->depth = 0.0f;
    if (ax > ay) {
        if (ax > az) {
            m.value = ax;
            fn_1_2BD30_set(&out->axis, out->dir.x, 0.0f, 0.0f);
        } else {
            m.value = az;
            fn_1_2BD30_set(&out->axis, 0.0f, 0.0f, out->dir.z);
            out->depth = out->dir.z;
        }
    } else {
        if (ay > az) {
            m.value = ay;
            fn_1_2BD30_set(&out->axis, 0.0f, out->dir.y, 0.0f);
        } else {
            m.value = az;
            fn_1_2BD30_set(&out->axis, 0.0f, 0.0f, out->dir.z);
            out->depth = out->dir.z;
        }
    }
    lbl_8006D668(&out->axis);

    fzgx_live_ = obj->velX;
    vx = fzgx_live_;
    if (fn_1_2BD30_nonfinite(vx) || fn_1_2BD30_nonfinite(vy = obj->velY) || fn_1_2BD30_nonfinite(vz = fn_1_2BD30_read_pointer(obj))) {
        out->speed = 0.0f;
    } else {
        lengthSquared = (f32)(vx * vx);
        lengthSquared += vy * vy;
        lengthSquared += vz * vz;
        out->speed = lbl_8006D0B4(lengthSquared) / obj->scale;
    }
    lbl_8006E1C0(&out->axis, &out->axis);
    lbl_8006DB30();
    return __fabs(m.value);
}
#pragma opt_dead_assignments reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_2BD30 */

/* fzgx:begin fn_1_2BF8C noprologue */
#include "types.h"
#include "psvec.h"
#include "game/main_rel/camera_types.h"

struct fn_1_2BF8C_lbl_1_rodata_840 {
    u8 pad_0[0x8];
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[0x4];
    f32 unk_14;
    u8 pad_18[0x4];
    f32 unk_1C;
    f64 unk_20;
    u8 pad_28[0x358];
    f64 unk_380;
    f64 unk_388;
    f32 unk_390;
};
struct fn_1_2BF8C_lbl_801A66CC {
    u32 unk_0;
};

#define lbl_801A66CC (*(struct fn_1_2BF8C_lbl_801A66CC *)&lbl_801A66CC)
extern u32 fn_1_25A14(u32);
extern void * lbl_8006D5A4(void *, u32, void *, f32);
extern void * lbl_8006DD48(void *, void *);
extern void fn_1_22F90(u32, int);
extern void fn_1_8A168(void *);
extern void fn_1_8A190(void *, void *);
extern void fn_1_A2D84(u32);
extern void fn_80008DB4(void *, f32, void *, void *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006DB74(u32);
extern void lbl_8006DBAC(Vec3 *);
extern void lbl_8006DD14(u32, void *);
extern void lbl_8006E0B4(f32, f32, f32);

#pragma opt_lifetimes off

static const u32 fzgx_pool_rodata_lbl_1_rodata_840[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x42500000, 0x3D800000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_840_8[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x42340000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_84C[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x3FD9999A
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_854[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3F800000, 0x3DCCCCCD
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_85C[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3F000000
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_conversion(u32 n) {
    volatile f64 d; /* fzgx-allow: S2 literal-pool layout primer */
    d = n;
}
#pragma section code_type ".text"
static const u32 fzgx_pool_rodata_lbl_1_rodata_860[42] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x42200000, 0x43AE0000, 0x42100000, 0x40800000, 0x3F19999A, 0x40A00000,
    0x3D4CCCCD, 0x447A0000, 0x41000000, 0x0, 0x406B0000, 0x0, 0x40000000, 0x0,
    0x3E800000, 0x3D8F5C29, 0x3E4CCCCD, 0x0, 0x3FEAE147, 0xAE147AE1, 0x40000000, 0x3FE66666,
    0x3FB33333, 0x3FC00000, 0x3F99999A, 0x40133333, 0x3ECCCCCD, 0x404CCCCD, 0x3E19999A, 0xBE800000,
    0x3E23D70A, 0x3DF5C28F, 0x3DA3D70A, 0x3EE66666, 0x3F333333, 0x0, 0x3FE33333, 0x40000000,
    0x3E9EB852, 0x3CF5C28F, 0x3C23D70A, 0x442F0000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_910[172] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3FE23D70, 0xA3D70A3D, 0x3F11EB85, 0x0, 0x0, 0x0, 0x3F800000, 0xBDCCCCCD,
    0x43480000, 0x3CA3D70A, 0x3F847AE1, 0x40000000, 0x3D23D70A, 0x3F4CCCCD, 0x402BC71C, 0x71C71C72,
    0x415E38E4, 0x34000000, 0x44480000, 0x3F733333, 0x400CCCCD, 0xBF000000, 0x3B03126F, 0x3A83126F,
    0x3E99999A, 0x0, 0x3FD99999, 0x9999999A, 0x3FB99999, 0x9999999A, 0x42A00000, 0x44D48000,
    0x40568000, 0x0, 0x3EAAAAAB, 0xC59C4000, 0x44610000, 0xC61C4000, 0x41200000, 0x42C80000,
    0x43C80000, 0x3F7D70A4, 0x41A00000, 0x3F8147AE, 0x3FF00000, 0x0, 0x3FE19999, 0xA0000000,
    0x4059999A, 0x3F400000, 0x43360B61, 0xC2340000, 0x3FEDA12F, 0x684BDA13, 0x401638E3, 0x8E38E38E,
    0x3F90A3D7, 0x0, 0x3FB99999, 0xA0000000, 0x3FD33333, 0x40000000, 0x3FA7B425, 0xED097B42,
    0x3F666666, 0x3F8E147B, 0x3F62F684, 0xBDA12F68, 0x3FE00000, 0x0, 0x3F72F684, 0xBDA12F68,
    0x3F97B425, 0xED097B42, 0x44FA0000, 0x43FA0000, 0x3FC99999, 0x9999999A, 0x3F23D70A, 0x3EB33333,
    0x3FFDA12F, 0x684BDA13, 0x400B3333, 0x40000000, 0x3FFB3333, 0x40000000, 0x40080000, 0x0,
    0x3FF80000, 0x0, 0xBECCCCCD, 0x0, 0x4009ED09, 0x7B425ED1, 0xBF800000, 0x38D1B717,
    0x3C656042, 0x41100000, 0x42700000, 0x40400000, 0x3E2AAAAB, 0x44960000, 0x44C80000, 0x0,
    0x408F4000, 0x0, 0x3FE66666, 0x60000000, 0x3E800000, 0x0, 0x3B449BA6, 0x3E000000,
    0xC4FA0000, 0x44160000, 0x40C00000, 0x43960000, 0x3F8E38E4, 0x461C4000, 0xC0400000, 0x4622F983,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x3F7DF3B6, 0x3C03126F, 0x42480000, 0x41700000, 0x457A0000, 0x0,
    0x400CCCCC, 0xCCCCCCCD, 0x3FA66666, 0x3C1374BD, 0x40C38300, 0x0, 0x42390000, 0x44898000,
    0x42F00000, 0xC2480000, 0x43300000, 0x80000000, 0x41F00000, 0xBE4CCCCD, 0x42B40000, 0x3BC49BA6,  /* fzgx-allow: A1 retail data bytes */
    0x401284BD, 0xA12F684C, 0xC0A00000, 0x40900000, 0x45638000, 0x40200000, 0xBE99999A, 0x387BA882,  /* fzgx-allow: A1 retail data bytes */
    0x47800000, 0x40D55555, 0x40600000, 0x39800000, 0x460CA000, 0x2010003, 0x2030103, 0x20302,
    0x3010001, 0x1000200, 0x3F9097B4, 0x25ED097B, 0x3AC49BA6, 0x43E10000, 0x44AAA000, 0x461C1800,
    0xC1200000, 0x0, 0x3FA99999, 0xA0000000  /* fzgx-allow: A1 retail data bytes */
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_840_380[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4062C000, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_840_388[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4062A000, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_840_390[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3A01742E, 0x0
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_rodata_840(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_840;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_840_8;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_84C;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_854;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_85C;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_860;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_910;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_840_380;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_840_388;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_840_390;
}
#pragma section code_type ".text"

#define fn_1_2BF8C_clamp(value, bound) ((value) < (bound) ? (bound) : ((value) > *(f32 *)fzgx_pool_rodata_lbl_1_rodata_854 ? *(f32 *)fzgx_pool_rodata_lbl_1_rodata_854 : (value)))

s32 fn_1_2BF8C(u32 arg0, f32 arg1) {
    f32 v0;
    f64 timer;
    f32 sy, sx;
    register f32 sz;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    u32 v6;
    u32 v7;
    u32 v8;
    f64 v9;
    u32 v10;
    f32 v11;
    f32 v12;
    f32 v13;
    f32 v14;
    f32 v15;
    u32 v18;
    u8 v19;
    u16 v16;
    f32 v17;
    u32 v20;
    f64 v21;
    f32 v22;
    f32 v23;
    f32 v24;
    struct { f32 a[3]; } loc_8;
    /* frame */
    void * t13;
    void * t16;
    u32 t25;
    void * t27;
    /* 1 instruction(s) not lifted: see the ??? markers */
    
    if (*(u8 *)((u8 *)arg0 + 1496) != 0) {
    *(u32 *)((u8 *)arg0 + 1300) = -1;
    (*(u8 *)((u8 *)arg0 + 1496))--;
    }
    v0 = (f32)(arg1);
    if (*(u16 *)((u8 *)arg0 + 532) != 0) {
    *(u32 *)((u8 *)arg0 + 1300) = -1;
    *(u8 *)((u8 *)arg0 + 1496) = 60;
    (*(u16 *)((u8 *)arg0 + 532))--;
    if (*(u16 *)((u8 *)arg0 + 532) == 179 && (s8)*(u8 *)((u8 *)arg0 + 1141) != -1) {
    v1 = *(u32 *)((u8 *)arg0 + 0);
    if ((v1 & (0x4000000 + 512)) == 0) {
    fn_1_A2D84((0xA9090000 + 8704));
    }
    }
    if (*(u16 *)((u8 *)arg0 + 532) == 170 && (s8)*(u8 *)((u8 *)arg0 + 1141) != -1) {
    v2 = *(u32 *)((u8 *)arg0 + 0);
    if ((v2 & (0x4000000 + 512)) == 0) {
    fn_1_A2D84((0xA9090000 + 8960));
    }
    }
    if (*(u16 *)((u8 *)arg0 + 532) == 20 && (s8)*(u8 *)((u8 *)arg0 + 1141) != -1) {
    v3 = *(u32 *)((u8 *)arg0 + 0);
    if ((v3 & (0x4000000 + 512)) == 0) {
    fn_1_A2D84((0xA9090000 + 9472));
    }
    }
    if (*(u16 *)((u8 *)arg0 + 532) == 0) {
    if ((s8)*(u8 *)((u8 *)arg0 + 1141) != -1) {
    v4 = *(u32 *)((u8 *)arg0 + 0);
    if ((v4 & (0x4000000 + 512)) == 0) {
    fn_1_A2D84((0xA9090000 + 9728));
    }
    }
    if ((s8)*(u8 *)((u8 *)arg0 + 1141) != -1) {
    v5 = *(u32 *)((u8 *)arg0 + 0);
    if ((v5 & (0x4000000 + 512)) == 0) {
    fn_1_A2D84((0xA9090000 + 9216));
    }
    }
    if ((s8)*(u8 *)((u8 *)arg0 + 1141) != -1) {
    v6 = *(u32 *)((u8 *)arg0 + 0);
    if ((v6 & (0x4000000 + 512)) == 0) {
    fn_1_A2D84((0xA9060000 + 7168));
    }
    }
    }
    if ((*(u32 *)((u8 *)arg0 + 0) & 0x10000000) != 0) {
    *(u16 *)((u8 *)arg0 + 532) = 0;
    lbl_8006DAEC();
    lbl_8006DBAC((Vec3 *)(arg0 + 332));
    v0 = (f32)((*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_84C))));
    psvec_set(((u8 *)arg0 + 124), *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C), *(f32 *)(0xE0000000 + 0x0C));
    psvec_set(((u8 *)arg0 + 136), *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C), *(f32 *)(0xE0000000 + 0x0C));
    *(f32 *)(0xE0000000 + 0x0C) = v0;
    *(f32 *)(0xE0000000 + 0x1C) = v0;
    *(f32 *)(0xE0000000 + 0x2C) = v0;
    lbl_8006DB74((arg0 + 236));
    lbl_8006DB74((arg0 + 284));
    lbl_8006DB30();
    if ((s8)*(u8 *)((u8 *)arg0 + 1141) != -1) {
    v7 = *(u32 *)((u8 *)arg0 + 0);
    if ((v7 & (0x4000000 + 512)) == 0) {
    fn_1_A2D84((0xA9090000 + 9216));
    }
    }
    }
    v8 = *(u16 *)((u8 *)arg0 + 532);
    if (*(u16 *)((u8 *)arg0 + 532) == 0) {
    *(u32 *)((u8 *)arg0 + 0) = (*(u32 *)((u8 *)arg0 + 0) & 0xFFFF7FFF);
    return 0;
    } else {
    if (v8 < 20) {
    *(u32 *)((u8 *)arg0 + 0) = (*(u32 *)((u8 *)arg0 + 0) | 32768);
    return 0;
    } else {
    v9 = (*(f64 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_860)));
    timer = (*(f64 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_840_380)));
    if ((f64)(u32)v8 < timer) {
    timer = (*(f64 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_840_388)));
    if (timer == (f64)(u32)v8 && (s8)*(u8 *)((u8 *)arg0 + 1141) != -1) {
    v8 = 0x4000000;
    v10 = *(u32 *)((u8 *)arg0 + 0);
    if ((v10 & (v8 + 512)) == 0) {
    v8 = 0xA9090000;
    v8 += 4608;
    fn_1_A2D84(v8);
    }
    }
    v8 = *(u16 *)((u8 *)arg0 + 532);
    v0 = (f32)((f32)(u32)(v8 - 60));
    if (v0 < (*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_840_8)))) {
    v0 = (f32)(*(f32 *)((u8 *)arg0 + 1308));
    *(f32 *)((u8 *)arg0 + 1308) = (f32)(v0 - (*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_840_390))));
    } else {
    v0 = (f32)(*(f32 *)((u8 *)arg0 + 1308));
    *(f32 *)((u8 *)arg0 + 1308) = (f32)(v0 + (*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_840_390))));
    }
    v0 = (f32)(*(f32 *)((u8 *)arg0 + 1304));
    *(f32 *)((u8 *)arg0 + 1304) = (f32)(v0 + *(f32 *)((u8 *)arg0 + 1308));
    *(f32 *)((u8 *)arg0 + 1304) = fn_1_2BF8C_clamp(*(f32 *)((u8 *)arg0 + 1304), (*(f32 *)fzgx_pool_rodata_lbl_1_rodata_84C));
    *(f32 *)((u8 *)lbl_801A66CC.unk_0 + 212) = *(f32 *)((u8 *)arg0 + 1324);
    *(f32 *)((u8 *)lbl_801A66CC.unk_0 + 216) = *(f32 *)((u8 *)arg0 + 1340);
    *(f32 *)((u8 *)lbl_801A66CC.unk_0 + 220) = *(f32 *)((u8 *)arg0 + 1356);
    loc_8.a[0] = *(f32 *)((u8 *)arg0 + 1440);
    v8 = lbl_801A66CC.unk_0;
    v8 += 212;
    loc_8.a[1] = *(f32 *)((u8 *)arg0 + 1456);
    loc_8.a[2] = *(f32 *)((u8 *)arg0 + 1472);
    v0 = (f32)(*(f32 *)((u8 *)arg0 + 1304));
    t13 = (void *)(lbl_8006D5A4((void *)v8, (u32)&loc_8, (void *)(arg0 + 124), v0));
    v8 = (u16)(t13);
    v0 = (f32)(*(f32 *)((u8 *)arg0 + 1304));
    v8 = (arg0 + 1312);
    fn_80008DB4((void *)v8, v0, (void *)(arg0 + 1428), (void *)(arg0 + 236));
    v14 = (*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_84C)));
    v8 = (arg0 + 1360);
    *(f32 *)((u8 *)arg0 + 280) = v14;
    *(f32 *)((u8 *)arg0 + 264) = v14;
    *(f32 *)((u8 *)arg0 + 248) = v14;
    v0 = (f32)(*(f32 *)((u8 *)arg0 + 1304));
    fn_80008DB4((void *)v8, v0, (void *)(arg0 + 1428), (void *)(arg0 + 332));
    *(f32 *)((u8 *)arg0 + 344) = *(f32 *)((u8 *)arg0 + 124);
    *(f32 *)((u8 *)arg0 + 360) = *(f32 *)((u8 *)arg0 + 128);
    *(f32 *)((u8 *)arg0 + 376) = *(f32 *)((u8 *)arg0 + 132);
    if (*(u16 *)((u8 *)arg0 + 532) == 20) {
    v8 = (arg0 + 1312);
    *(f32 *)((u8 *)arg0 + 124) = *(f32 *)((u8 *)arg0 + 1440);
    *(f32 *)((u8 *)arg0 + 128) = *(f32 *)((u8 *)arg0 + 1456);
    *(f32 *)((u8 *)arg0 + 132) = *(f32 *)((u8 *)arg0 + 1472);
    t16 = (void *)(lbl_8006DD48((void *)v8, (void *)(arg0 + 236)));
    v8 = (u16)(t16);
    v15 = (*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_84C)));
    v8 = (arg0 + 1360);
    *(f32 *)((u8 *)arg0 + 280) = v15;
    *(f32 *)((u8 *)arg0 + 264) = v15;
    *(f32 *)((u8 *)arg0 + 248) = v15;
    lbl_8006DD14(v8, (void *)(arg0 + 332));
    *(f32 *)((u8 *)arg0 + 344) = *(f32 *)((u8 *)arg0 + 124);
    *(f32 *)((u8 *)arg0 + 360) = *(f32 *)((u8 *)arg0 + 128);
    *(f32 *)((u8 *)arg0 + 376) = *(f32 *)((u8 *)arg0 + 132);
    v16 = *(u16 *)((u8 *)arg0 + 532);
    v17 = *(f32 *)((u8 *)arg0 + 388);
    v18 = (*(u32 *)((u8 *)arg0 + 0) & 0x1);
    v19 = *(u8 *)((u8 *)arg0 + 1218);
    lbl_8006DAEC();
    v8 = (arg0 + 1428);
    lbl_8006DBAC((Vec3 *)v8);
    v8 = arg0;
    fn_1_22F90(v8, 0);
    *(u16 *)((u8 *)arg0 + 532) = v16;
    v8 = (v19 + 1);
    v20 = *(u32 *)((u8 *)arg0 + 0);

    v21 = (*(f64 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_860)));
    *(u32 *)((u8 *)arg0 + 0) = (v20 | 1024);
    *(u8 *)((u8 *)arg0 + 1153) = 60;
    *(u8 *)((u8 *)arg0 + 1218) = v8;
    *(u32 *)((u8 *)arg0 + 0) = (*(u32 *)((u8 *)arg0 + 0) | v18);

    v22 = (f32)*(u16 *)((u8 *)arg0 + 1498);
    v23 = (f32)(v22 * (*(f32 *)fzgx_pool_rodata_lbl_1_rodata_85C));
    if (v17 <= v23) {
    *(f32 *)((u8 *)arg0 + 388) = v23;
    } else {
    *(f32 *)((u8 *)arg0 + 388) = v17;
    }
    v8 = arg0;
    fn_1_8A190((void *)v8, (void *)1);
    lbl_8006DB30();
    *(u32 *)((u8 *)arg0 + 0) = (*(u32 *)((u8 *)arg0 + 0) | 32768);
    lbl_8006DAEC();
    v0 = (f32)((*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_84C))));
    lbl_8006E0B4(v0, (*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_854))), v0);
    v8 = arg0;
    for (v1 = 0; v1 < 4; v1++) {
        psvec_set(((u8 *)arg0 + 960 + 48 * v1), *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C), *(f32 *)(0xE0000000 + 0x0C));
    }
    t25 = fn_1_25A14(v8);
    v8 = t25;
    lbl_8006DB30();
    return 0;
    } else {
    return 1;
    }
    } else {
    if (v8 < 180) {
    if (timer == (f64)(u32)v8) {
    v24 = (*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_84C)));
    v8 = (arg0 + 236);
    *(f32 *)((u8 *)arg0 + 1304) = v24;
    *(f32 *)((u8 *)arg0 + 1308) = v24;
    t27 = (void *)(lbl_8006DD48((void *)v8, (void *)(arg0 + 1312)));
    v8 = (u16)(t27);
    v8 = (arg0 + 332);
    *(f32 *)((u8 *)arg0 + 1324) = *(f32 *)((u8 *)arg0 + 124);
    *(f32 *)((u8 *)arg0 + 1340) = *(f32 *)((u8 *)arg0 + 128);
    *(f32 *)((u8 *)arg0 + 1356) = *(f32 *)((u8 *)arg0 + 132);
    lbl_8006DD14(v8, (void *)(arg0 + 1360));
    lbl_8006DAEC();
    v8 = arg0;
    fn_1_8A168((void *)v8);
    v8 = (arg0 + 1428);
    lbl_8006DB74(v8);
    lbl_8006DB30();
    return 1;
    }
    } else {
    *(f32 *)((u8 *)arg0 + 344) = *(f32 *)((u8 *)arg0 + 124);
    *(f32 *)((u8 *)arg0 + 360) = *(f32 *)((u8 *)arg0 + 128);
    *(f32 *)((u8 *)arg0 + 376) = *(f32 *)((u8 *)arg0 + 132);
    }
    }
    }
    }
    }
    v8 = 0;
    return v8;
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_2BF8C */

/* fzgx:begin fn_1_2C688 */
u32 fn_1_2C688(u32 arg0, u32 arg1, u32 arg2) {
    u32 v1;
    s32 v0;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    u32 v6;
    u32 t0;
    u32 t1;
    u32 t2;
    v0 = 0;
    v1 = arg0;
    do {
    v2 = *(u32 *)((u8 *)v1 + 1160);
    v3 = arg0;
    v4 = arg1;
    v5 = arg2;
    if (v2 != 0) {
    v3 = v2;
    v4 = 0;
    v5 = 192;
    t0 = (u32)memset( (void *)(u32)(v3), v4, v5);
    v3 = t0;
    v3 = (v2 + 8);
    *(u32 *)((u8 *)v2 + 0) = v3;
    *(u32 *)((u8 *)v2 + 4) = (v2 + 100);
    }
    v0++;
    v1 += 4;
    } while ((s32)v0 < 4);
    v3 = *(u32 *)((u8 *)arg0 + 1176);
    if (v3 != 0) {
    v4 = 0;
    v5 = 404;
    t1 = (u32)memset( (void *)(u32)(v3), v4, v5);
    v3 = t1;
    }
    v6 = *(u32 *)((u8 *)arg0 + 1180);
    if (v6 != 0) {
    v3 = v6;
    v4 = 0;
    v5 = 279;
    t2 = (u32)memset( (void *)(u32)(v3), v4, v5);
    v3 = t2;
    v4 = (v6 + 184);
    *(u32 *)((u8 *)v6 + 128) = 0;
    v3 = (v6 + 200);
    *(u32 *)((u8 *)v6 + 144) = v4;
    *(u32 *)((u8 *)v6 + 148) = v3;
    *(u32 *)((u8 *)v6 + 156) = -1;
    *(u32 *)((u8 *)v6 + 184) = -1;
    *(u32 *)((u8 *)v6 + 216) = -1;
    }
    return v3;
}
/* fzgx:end fn_1_2C688 */

/* fzgx:begin fn_1_2C768 */
void fn_1_2C768(u32 *arg0) {
    if (lbl_1_bss_3C2A[0] != 0x29 || (lbl_1_bss_3C30.unk_0 & 0x800)) {
        return;
    }
    if (lbl_1_bss_3C30.unk_5 == 2 && *arg0 != lbl_1_bss_3C30.unk_1474) {
        lbl_1_bss_3C30.unk_5 = 6;
    }
    *arg0 += 1;
}
/* fzgx:end fn_1_2C768 */

/* fzgx:begin fn_1_2C7C4 */
void fn_1_2C7C4(u8 *value, const u8 *target, int step) {
    if (value[0] != target[0]) {
        if (value[0] > target[0]) {
            if (value[0] > target[0] + step) {
                value[0] -= step;
            } else {
                value[0] = target[0];
            }
        } else {
            if (value[0] < target[0] - step) {
                value[0] += step;
            } else {
                value[0] = target[0];
            }
        }
    }
    if (value[1] != target[1]) {
        if (value[1] > target[1]) {
            if (value[1] > target[1] + step) {
                value[1] -= step;
            } else {
                value[1] = target[1];
            }
        } else {
            if (value[1] < target[1] - step) {
                value[1] += step;
            } else {
                value[1] = target[1];
            }
        }
    }
    if (value[2] != target[2]) {
        if (value[2] > target[2]) {
            if (value[2] > target[2] + step) {
                value[2] -= step;
            } else {
                value[2] = target[2];
            }
        } else {
            if (value[2] < target[2] - step) {
                value[2] += step;
            } else {
                value[2] = target[2];
            }
        }
    }
    if (value[3] != target[3]) {
        if (value[3] > target[3]) {
            if (value[3] > target[3] + step) {
                value[3] -= step;
            } else {
                value[3] = target[3];
            }
        } else {
            if (value[3] < target[3] - step) {
                value[3] += step;
            } else {
                value[3] = target[3];
            }
        }
    }
}
/* fzgx:end fn_1_2C7C4 */

/* fzgx:begin fn_1_2C908 noprologue */
#include "types.h"

struct fn_1_2C908_lbl_1_bss_3C00 {
    u8 pad_0[0x30];
    u32 unk_30;
    u8 pad_34[0x14B4];
    u16 unk_14E8;
    u8 pad_14EA[0x2];
    u16 unk_14EC;
    u8 pad_14EE[0x6];
    u8 unk_14F4;
    u8 pad_14F5[0x3];
    u32 unk_14F8;
    u16 unk_14FC;
};

extern int fn_1_4C10(void);
extern struct fn_1_2C908_lbl_1_bss_3C00 lbl_1_bss_3C00;
extern u32 fn_1_4060(void);
extern void fn_1_EB080(int);

#pragma opt_lifetimes off
u32 fn_1_2C908(void) {
    struct fn_1_2C908_lbl_1_bss_3C00 *p_lbl_1_bss_3C00;
    u32 v0;
    u32 v1;
    p_lbl_1_bss_3C00 = (struct fn_1_2C908_lbl_1_bss_3C00 *)&lbl_1_bss_3C00;
    v0 = fn_1_4C10();
    if ((s32)v0 == 0) {
    v0 = p_lbl_1_bss_3C00->unk_30;
    v1 = (v0 | 4096);
    p_lbl_1_bss_3C00->unk_14E8 = 42;
    p_lbl_1_bss_3C00->unk_30 = v1;
    p_lbl_1_bss_3C00->unk_14EC = 0;
    p_lbl_1_bss_3C00->unk_14F4 = (p_lbl_1_bss_3C00->unk_14F4 | 1);
    p_lbl_1_bss_3C00->unk_14F8 = 0;
    p_lbl_1_bss_3C00->unk_14FC = 0;
    fn_1_EB080(4);
    v0 = fn_1_4060();
    }
    return v0;
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_2C908 */

/* fzgx:begin fn_1_2D038 pool noprologue */
#include "types.h"

/* stcoli.c's .bss cluster: retail addresses every object off one base (lbl_1_bss_3C00) and
 * only an object's offset 0 is reached base-relative, so the objects this function touches
 * are defined here in retail order, with fillers keeping the retail offsets. */
struct fn_1_2D038_Obj3C30 {
    u32 unk_0;
    u8 unk_4;
    u8 unk_5;
    u8 pad_6[0x14BC - 0x6];
};
u32 lbl_1_bss_3C00;
u32 lbl_1_bss_3C04;
u32 lbl_1_bss_3C08[0x2];
u8 lbl_1_bss_3C10;
u8 lbl_1_bss_3C11;
u8 lbl_1_bss_3C12;
u8 fzgx_fill_3C13;
u8 fzgx_fill_3C14;
u8 fzgx_fill_3C15;
u8 fzgx_fill_3C16;
u8 fzgx_fill_3C17;
u8 fzgx_fill_3C18;
u8 fzgx_fill_3C19;
u8 fzgx_fill_3C1A;
u8 fzgx_fill_3C1B;
u8 lbl_1_bss_3C1C[0xE];
s16 lbl_1_bss_3C2A;
s16 fzgx_fill_3C2C;
s16 fzgx_fill_3C2E;
struct fn_1_2D038_Obj3C30 lbl_1_bss_3C30;
u16 lbl_1_bss_50EC[0xA];
u32 lbl_1_bss_5100;
u8 lbl_1_bss_5104[0x34];
u8 lbl_1_bss_5138[0xEC];
u8 lbl_1_bss_5224;
u8 fzgx_fill_5225;
u8 fzgx_fill_5226;
u8 fzgx_fill_5227;
s32 lbl_1_bss_5228;
u32 lbl_1_bss_522C;
const char *lbl_1_bss_5230;
u8 lbl_1_bss_5234;
u8 fzgx_fill_5235;
u8 fzgx_fill_5236;
u8 fzgx_fill_5237;
s32 lbl_1_bss_5238;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime0(void) {
    volatile u32 sink;  /* fzgx-allow: S2 section-order primer sink */
    sink = lbl_1_bss_3C00;
    sink = lbl_1_bss_3C04;
    sink = lbl_1_bss_3C08[0];
    sink = lbl_1_bss_3C10;
    sink = lbl_1_bss_3C11;
    sink = lbl_1_bss_3C12;
    sink = fzgx_fill_3C13;
    sink = fzgx_fill_3C14;
    sink = fzgx_fill_3C15;
    sink = fzgx_fill_3C16;
    sink = fzgx_fill_3C17;
    sink = fzgx_fill_3C18;
    sink = fzgx_fill_3C19;
    sink = fzgx_fill_3C1A;
    sink = fzgx_fill_3C1B;
    sink = lbl_1_bss_3C1C[0];
    sink = lbl_1_bss_3C2A;
    sink = fzgx_fill_3C2C;
    sink = fzgx_fill_3C2E;
    sink = lbl_1_bss_3C30.unk_0;
    sink = lbl_1_bss_50EC[0];
    sink = lbl_1_bss_5100;
    sink = lbl_1_bss_5104[0];
    sink = lbl_1_bss_5138[0];
    sink = lbl_1_bss_5224;
    sink = fzgx_fill_5225;
    sink = fzgx_fill_5226;
    sink = fzgx_fill_5227;
    sink = lbl_1_bss_5228;
    sink = lbl_1_bss_522C;
    sink = (u32)lbl_1_bss_5230;
    sink = lbl_1_bss_5234;
    sink = fzgx_fill_5235;
    sink = fzgx_fill_5236;
    sink = fzgx_fill_5237;
    sink = lbl_1_bss_5238;
}
static const u32 fzgx_pool_table1[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 15.0f;
    s = 1.0f;
    s = 10.0f;
    s = 1.25f;
    s = 0.10000000149011612f;
    s = 0.8999999761581421f;
    s = 0.0006000000284984708f;
    s = 0.4000000059604645f;
    s = 0.75f;
    s = 70.0f;
    s = 0.5f;
    s = 36.0f;
    s = 16.0f;
    s = 45.0f;
    s = 0.0007999999797903001f;
    s = 18.0f;
    s = 50.0f;
}
static const u32 fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
#pragma section code_type ".text"

/* Text packet handed to fn_1_50A90; the template lives in rodata. */
struct fn_1_2D038_Text {
    u32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    u32 pad_10[7];
    f32 unk_2C;
    u32 unk_30;
    u32 pad_34[9];
};

extern const char *lbl_1_data_5BF8[];
extern const struct fn_1_2D038_Text lbl_1_rodata_26F8;
extern u8 lbl_1_bss_8E51D;
extern u8 fn_1_F45B4(void);
extern int fn_1_F22D4(void);
extern int fn_1_EB248(void);
extern s32 fn_1_154C84(void);
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_4954C(f32);
extern void fn_1_49590(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495C8(u8);
extern void fn_1_495A0(f32);
extern void fn_1_495B0(u32);
extern const char *fn_1_15BA78(const char *);
extern f32 fn_1_4B068(const char *);
extern f32 fn_1_4B090(const char *);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_50A90(void *, s32, s32, s32, s32);

void fn_1_2D038(void) {
    struct fn_1_2D038_Text text;
    f32 t;
    f32 fadeA;
    f32 fadeB;
    f32 height;
    f32 width;
    f32 x;
    f32 h;
    s32 count;
    s32 msg;

    count = 0;
    msg = -1;
    if (!(lbl_1_bss_3C30.unk_0 & 0x800000) || (fn_1_F45B4() != 0 && lbl_1_bss_5224 == 0)) {
        lbl_1_bss_5228 = 0;
    } else {
        if (lbl_1_bss_522C == 0) {
            count = 1;
            lbl_1_bss_5228 = 1;
        } else if (lbl_1_bss_5228 == 0 && lbl_1_bss_522C >= 0xB4) {
            lbl_1_bss_5228 = 1;
            lbl_1_bss_522C = 0;
            lbl_1_bss_5230 = 0;
        }
        if (lbl_1_bss_522C == 0 && lbl_1_bss_5228 != 0) {
            msg = 1;
        }
    }

    if (lbl_1_bss_5234 != 0 || (lbl_1_bss_3C30.unk_5 == 2 && fn_1_F22D4() != 0)) {
        if (lbl_1_bss_522C == 0) {
            count += 1;
            lbl_1_bss_5238 = 1;
        } else if (lbl_1_bss_5238 == 0 && lbl_1_bss_522C >= 0xB4) {
            lbl_1_bss_5238 = 1;
            lbl_1_bss_522C = 0;
            lbl_1_bss_5230 = 0;
        }
        if (count == 2) {
            msg = 0;
            lbl_1_bss_5230 = 0;
        } else if (lbl_1_bss_522C == 0 && lbl_1_bss_5238 != 0 && msg == -1) {
            msg = 2;
        }
    } else {
        lbl_1_bss_5238 = 0;
    }

    if (lbl_1_bss_5228 == 0 && lbl_1_bss_5238 == 0) {
        lbl_1_bss_522C = 0;
        lbl_1_bss_5230 = 0;
        return;
    }

    if (fn_1_EB248() != 0 || fn_1_154C84() != 0) {
        if (lbl_1_bss_522C == 0) {
            return;
        }
        if (lbl_1_bss_522C > 0xF) {
            lbl_1_bss_522C = 0xF;
        } else {
            lbl_1_bss_522C -= 1;
        }
    } else {
        if (lbl_1_bss_3C2A >= 0x2A) {
            if (lbl_1_bss_8E51D == 0xA) {
                if (lbl_1_bss_522C == 0) {
                    msg += 3;
                }
                lbl_1_bss_522C += lbl_1_bss_522C < 0x3C;
            } else {
                lbl_1_bss_522C = 0;
                return;
            }
        } else {
            lbl_1_bss_522C = 0;
            lbl_1_bss_5230 = 0;
            return;
        }
    }

    if (lbl_1_bss_522C < 0xF) {
        t = (f32)lbl_1_bss_522C / 15.0f;
    } else if (lbl_1_bss_522C > 0xA5) {
        t = 1.0f - (f32)(lbl_1_bss_522C - 0xA5) / 15.0f;
    } else {
        t = 1.0f;
    }
    fadeA = 10.0f * t;
    if (fadeA > 1.0f) {
        fadeA = 1.0f;
    }
    fadeB = 1.25f * (t - 0.1f);
    if (fadeB < 0.0f) {
        fadeB = 0.0f;
    }

    {
        f32 alpha;
        alpha = 10.0f * (t - 0.9f);
        if (alpha < 0.0f) {
            alpha = 0.0f;
        }

        fn_1_49410();
        fn_1_495FC();
        fn_1_4954C(0.0006f);
        fn_1_49590(0.4f);
        fn_1_4955C(0.75f, 0.75f);
        fn_1_495C8(1);
        fn_1_495A0(alpha);
        fn_1_495B0(0x80000000);
    }
    if (lbl_1_bss_5230 == 0) {
        lbl_1_bss_5230 = fn_1_15BA78(lbl_1_data_5BF8[msg]);
    }
    width = fn_1_4B068(lbl_1_bss_5230);
    height = fn_1_4B090(lbl_1_bss_5230);
    x = 70.0f + (f32)(width / 2.0f);
    fn_1_496FC(x, 36.0f);
    fn_1_4A0D8(lbl_1_bss_5230);

    text = lbl_1_rodata_26F8;
    h = 45.0f + height;
    text.unk_4 = x;
    text.unk_8 = 16.0f + (f32)(0.5f * h);
    text.unk_C = 0.0008f;
    text.unk_30 = 0xA;
    text.unk_2C = t;
    text.unk_0 = 2;
    fn_1_50A90(&text, (s32)(18.0f * fadeA), (s32)(45.0f * fadeA), (s32)((50.0f + width) * fadeB), (s32)(h * fadeB));
}
/* fzgx:end fn_1_2D038 */

/* fzgx:begin fn_1_2D524 */
struct fn_1_2D524_Obj {
    u16 unk_0;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4[4];
    u16 unk_8[6];
    f32 unk_14;
    f32 unk_18;
    u8 pad_1C[0x4];
    char unk_20[0xC1];
    u8 unk_E1;
    u8 unk_E2;
    u8 unk_E3;
    u8 unk_E4;
    u8 unk_E5;
    u8 unk_E6[5];
    u8 unk_EB;
};
struct fn_1_2D524_lbl_1_data_5730 {
    u8 pad_0[0x538];
    char *unk_538;
    u8 pad_53C[0x50];
    char *unk_58C;
    u8 pad_590[0x58];
    char *unk_5E8;
    u8 pad_5EC[0x58];
    char *unk_644;
    u8 pad_648[0x4C];
    char *unk_694;
    u8 pad_698[0x50];
    char *unk_6E8;
    u8 pad_6EC[0x1C];
    char *unk_708;
};
struct fn_1_2D524_lbl_1_bss_3C30 {
    u8 pad_0[0x6];
    u8 unk_6;
};


void fn_1_2D524(struct fn_1_2D524_Obj *o) {
    struct fn_1_2D524_lbl_1_rodata_BD8 *pool;
    struct fn_1_2D524_lbl_1_data_5730 *strs;
    u8 kind;
    u16 idx;
    u32 t0;
    u32 v2;
    u32 saved;
    char *name;
    struct fn_1_2D524_Copy200 table;
    char buf30[0x40];
    char buf10[0x20];
    struct fn_1_2D524_Copy8 names;

    pool = (struct fn_1_2D524_lbl_1_rodata_BD8 *)&lbl_1_rodata_BD8;
    strs = (struct fn_1_2D524_lbl_1_data_5730 *)&(*((struct fn_1_2D524_lbl_1_data_5730 *)&lbl_1_data_5730));
    kind = o->unk_E1;
    if (kind == 0) {
        t0 = fn_1_F8D10();
        sprintf(o->unk_20, fn_1_15BA78(strs->unk_708), o->unk_0);
        fn_1_F8D38(t0 + o->unk_0);
        o->unk_0 = 0;
    } else if (kind == 1) {
        v2 = lbl_1_data_2BD54[o->unk_E3][lbl_801A66B4];
        sprintf(o->unk_20, fn_1_15BA78(strs->unk_5E8), v2);
        fn_1_F2008((*((struct fn_1_2D524_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_6);
    } else if (kind == 2) {
        table = pool->unk_58;
        sprintf(o->unk_20, fn_1_15BA78(strs->unk_694), table.a[o->unk_E5 & 0xF][lbl_801A66B4]);
        fn_1_F9D68(o->unk_E5 & 0xF);
        fn_1_F9DE8(o->unk_E5 & 0xF);
    } else if (kind == 3) {
        names = pool->unk_120;
        sprintf(o->unk_20, fn_1_15BA78(strs->unk_6E8), fn_1_15BA78((char *)names.a[o->unk_EB]));
        fn_1_F8C00(o->unk_EB);
    } else {
        idx = (u16)(kind - 4);
        if (idx < o->unk_3) {
            fn_1_7F49C(o->unk_4[idx], (s16)lbl_801A66B4, buf10);
            sprintf(o->unk_20, fn_1_15BA78(strs->unk_58C), buf10);
            fn_1_F7F48(o->unk_4[idx]);
        } else if (idx < o->unk_3 + o->unk_2) {
            idx -= o->unk_3;
            fn_1_14EA74((s16)o->unk_8[(u16)idx], buf30, (s16)lbl_801A66B4);
            sprintf(o->unk_20, fn_1_15BA78(strs->unk_538), buf30);
            fn_1_F83F0((s16)o->unk_8[(u16)idx]);
        } else {
            idx -= o->unk_3 + o->unk_2;
            v2 = lbl_1_data_2BD54[fn_1_12EF24(6, o->unk_E6[(u16)idx])][lbl_801A66B4];
            sprintf(o->unk_20, fn_1_15BA78(strs->unk_644), v2);
            fn_1_F8A58(o->unk_E6[(u16)idx]);
        }
    }
    fn_1_49410();
    fn_1_4955C(pool->unk_128, pool->unk_128);
    fn_1_49590(pool->unk_24);
    fn_1_495B0(0x80000000);
    fn_1_495C8(1);
    saved = fn_1_4AEC0(1);
    o->unk_14 = pool->unk_12C + fn_1_4B068(o->unk_20);
    o->unk_18 = pool->unk_130 + fn_1_4B090( (s32)(char *)(o->unk_20));
    fn_1_4AEC0(saved);
    fn_1_A2DC4(0xA9011700);
}
/* fzgx:end fn_1_2D524 */

/* fzgx:begin fn_1_2D888 pool noprologue */
#include "types.h"
#include "rel/main_rel/stcoli.h"

typedef struct {
    u8 pad_0[0x10];
    u16 x;      /* 0x10 */
    u16 y;      /* 0x12 */
    f32 w;      /* 0x14 */
    f32 h;      /* 0x18 */
    f32 t;      /* 0x1C */
    u8 unk_20[0xC2];
    u8 active;  /* 0xE2 */
} fn_1_2D888_Box;

typedef struct {
    s32 mode;       /* 0x00 */
    f32 x;          /* 0x04 */
    f32 y;          /* 0x08 */
    f32 z;          /* 0x0C */
    u8 pad_10[0x1C];
    f32 alpha;      /* 0x2C */
    s32 count;      /* 0x30 */
    u8 pad_34[0x24];
} fn_1_2D888_Text;

extern u32 fn_1_4060(void);
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_4954C(f32 value);
extern void fn_1_495C8(u8 value);
extern void fn_1_495B0(u32 value);
extern void fn_1_49590(f32 value);
extern void fn_1_495A0(f32 value);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_496FC(f32 value1, f32 value2);
extern u32 fn_1_4AEE8(u32);
extern void fn_1_4AF10(void *);
extern void fn_1_4A0D8(const char *);
extern void fn_1_50A90(void *, u32, u32, u32, u32);
extern fn_1_2D888_Text lbl_1_rodata_26F8;

static const u32 fn_1_2D888_pool0[1] = { 0xFFFFFF00 };

/* Primes the shared literal pool in retail order; not linked. */
#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_primer_fn_1_2D888(f32 *o, f64 *d) {
    o[0] = *(f32 *)fn_1_2D888_pool0;
    o[1] = 0.0f;
    o[2] = 15.0f;
    o[3] = 1.0f;
    o[4] = 10.0f;
    o[5] = 1.25f;
    o[6] = 0.1f;
    o[7] = 0.9f;
    o[8] = 0.0006f;
    o[9] = 0.4f;
    o[10] = 0.75f;
    o[11] = 70.0f;
    o[12] = 0.5f;
    o[13] = 36.0f;
    o[14] = 16.0f;
    o[15] = 45.0f;
    o[16] = 0.0008f;
    o[17] = 18.0f;
    o[18] = 50.0f;
    d[0] = 4503599627370496.0;
}

static const u32 fn_1_2D888_pool58[52] = { 0 };

__declspec(section ".fzgxpool") void fzgx_primer2_fn_1_2D888(f32 *o, f64 *d) {
    o[0] = fn_1_2D888_pool58[0];
    o[1] = 0.8f;
    o[2] = 80.0f;
    o[3] = 60.0f;
    d[0] = 4503601774854144.0;
}

void fn_1_2D888(fn_1_2D888_Box *box) {
    f32 fade;
    f32 scale;
    f32 alpha;
    u32 saved;
    u32 w;
    u32 h;
    fn_1_2D888_Text text;

    if (box->active == 0) {
        fn_1_4060();
        return;
    }

    fade = 10.0f * box->t;
    if (fade > 1.0f) {
        fade = 1.0f;
    }
    scale = 1.25f * (box->t - 0.1f);
    if (scale < 0.0f) {
        scale = 0.0f;
    }
    alpha = 10.0f * (box->t - 0.9f);
    if (alpha < 0.0f) {
        alpha = 0.0f;
    }

    fn_1_49410();
    fn_1_495FC();
    fn_1_4954C(0.0006f);
    fn_1_495C8(1);
    fn_1_495B0(0x80000000);
    fn_1_49590(0.4f);
    fn_1_495A0(alpha);
    fn_1_4955C(0.8f, 0.8f);
    fn_1_496FC(box->x, box->y);
    saved = fn_1_4AEE8(0);
    fn_1_4AF10(box->unk_20);
    fn_1_4AEE8(saved);
    fn_1_496FC(box->x, box->y + box->h - 45.0f);
    fn_1_4955C(1.0f, 1.0f);
    fn_1_4A0D8((const char *)lbl_1_data_61D4);

    w = box->w * scale;
    h = box->h * scale;
    text = lbl_1_rodata_26F8;
    text.x = box->x;
    text.y = (s32)(box->y - 10) + (f32)(0.5f * box->h);
    text.z = 0.0008f;
    text.count = 10;
    text.alpha = box->t;
    text.mode = 2;
    fn_1_50A90(&text, 18.0f * fade, 45.0f * fade, w, h);
}
/* fzgx:end fn_1_2D888 */

/* fzgx:begin fn_1_2DB50 noprologue */
#include "types.h"
#include "rel/main_rel/stcoli.h"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 15.0f;
    s = 1.0f;
    s = 10.0f;
    s = 1.25f;
    s = 0.10000000149011612f;
    s = 0.8999999761581421f;
    s = 0.0006000000284984708f;
    s = 0.4000000059604645f;
    s = 0.75f;
    s = 70.0f;
    s = 0.5f;
    s = 36.0f;
    s = 16.0f;
    s = 45.0f;
    s = 0.0007999999797903001f;
    s = 18.0f;
    s = 50.0f;
}
static const u32 fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table5[52] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
    s = 80.0f;
    s = 60.0f;
}
static const u32 fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
#pragma section code_type ".text"

extern void fn_1_A2DC4(u32 addr);
extern s32 ghost_test_record_flag0(u8 value);
extern s32 fn_1_F9D44(u32 value);
extern u8 fn_1_F8C50(u8 value);
extern void fn_1_2D524(Obj_1_bss_5138 *obj);
extern u32 fn_1_4060(void);
extern void fn_80008BEC(void *dst, int value, u32 size);

#pragma opt_propagation off
static inline void fn_1_2DB50_transition(Obj_1_bss_5138 *obj, s32 zero, u8 *threshold) {
    s32 condition;
    *threshold = obj->unk_2 + obj->unk_3 + obj->unk_E4 + 4;
    obj->unk_E0 = zero;
    obj->unk_E1++;
    if (obj->unk_E1 == 1) {
        if (obj->unk_E3 == 0xff) {
            condition = zero;
        } else if (ghost_test_record_flag0(lbl_1_bss_3C30.unk_6) != 0) {
            condition = 0;
        } else {
            condition = 1;
        }
        if (condition == 0) {
            obj->unk_E1 = 2;
        }
    }
}

void fn_1_2DB50(Obj_1_bss_5138 *obj) {
    s32 condition;
    u8 threshold;
    f32 v;
    f32 t;

    if (obj->unk_E0 == 0x78) {
        fn_1_A2DC4(0xA9011100);
    }
    if (++obj->unk_E0 > 0x78) {
        t = (f32)(s32)(obj->unk_E0 - 0x78);
        if (t > 15.0f) {
            fn_1_2DB50_transition(obj, 0, &threshold);
            if (obj->unk_E1 == 2) {
                if (obj->unk_E5 == 0xff) {
                    condition = 0;
                } else if (fn_1_F9D44(obj->unk_E5 & 0xf) != 0) {
                    condition = 0;
                } else {
                    condition = 1;
                }
                if (condition == 0) {
                    obj->unk_E1 = 3;
                }
            }
            if (obj->unk_E1 == 3) {
                if (obj->unk_EB == 0xff) {
                    condition = 0;
                } else if (fn_1_F8C50(obj->unk_EB) != 0) {
                    condition = 0;
                } else {
                    condition = 1;
                }
                if (condition == 0) {
                    obj->unk_E1 = 4;
                }
            }
            if (obj->unk_E1 >= threshold) {
                fn_80008BEC(&lbl_1_bss_5138, 0, 0xec);
                lbl_1_bss_5138.unk_10 = 320;
                lbl_1_bss_5138.unk_12 = 180;
                lbl_1_bss_5138.unk_E1 = 0;
                lbl_1_bss_5138.unk_E0 = 0;
                lbl_1_bss_5138.unk_0 = 0;
                lbl_1_bss_5138.unk_2 = 0;
                lbl_1_bss_5138.unk_3 = 0;
                lbl_1_bss_5138.unk_1C = 0.0f;
                lbl_1_bss_5138.unk_20 = 0;
                lbl_1_bss_5138.unk_E2 = 0;
                lbl_1_bss_5138.unk_E3 = 0xff;
                lbl_1_bss_5138.unk_E4 = 0;
                lbl_1_bss_5138.unk_E5 = 0xff;
                lbl_1_bss_5138.unk_EB = 0xff;
                fn_1_4060();
                return;
            }
            t = 15.0f;
            fn_1_2D524(obj);
        }
        obj->unk_1C = 1.0f - t / 15.0f;
    } else {
        v = (f32)obj->unk_E0 / 15.0f;
        obj->unk_1C = v;
        if (v > 1.0f) {
            obj->unk_1C = 1.0f;
            if (obj->unk_E0 == 0x78) {
                obj->unk_E0 = 0x77;
            }
        }
    }
}
/* fzgx:end fn_1_2DB50 */

/* fzgx:begin fn_1_2DE00 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/game.h"

typedef u32 (*GameStepFn)(void);
typedef s32 (*GameModeFn)(void);
typedef struct {
    u32 unk_0;
    u8 pad_4[2];
    u16 unk_6;
    u8 unk_8;
    u8 unk_9;
    u8 pad_A[0x9];
    u8 unk_13[5];
    u8 pad_18[0x68];
    u8 unk_80;
    u8 unk_81;
    u8 unk_82;
    u8 unk_83;
    u8 pad_84[0x1C];
} GamePlayer;
typedef struct {
    u32 unk_0;
    u8 pad_4;
    u8 unk_5;
    u8 unk_6;
    u8 unk_7;
    u8 unk_8;
    u8 unk_9;
    u8 unk_A;
    u8 unk_B;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E[4];
    u8 pad_12[0xA4 - 0x12];
    u16 unk_A4;
    u8 unk_A6;
    u8 unk_A7;
    u8 pad_A8[4];
    GameStepFn unk_AC;
    GameStepFn unk_B0;
    GameStepFn unk_B4;
    GameStepFn unk_B8;
    GameStepFn unk_BC;
    GameStepFn unk_C0;
    u32 unk_C4;
    GameStepFn unk_C8;
    GameModeFn unk_CC;
    u8 pad_D0[0x4];
    GamePlayer players[4];
    u8 pad_354[0x13F6 - 0x354];
    u8 unk_13F6;
    u8 pad_13F7[0x1474 - 0x13F7];
    u32 unk_1474;
    u16 unk_1478[4];
    u32 unk_1480[4];
    u8 pad_1490[0x14B8 - 0x1490];
} GameState;
typedef struct {
    void *unk_0;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    u8 pad_7;
} GameSlotEntry;
typedef struct {
    GameSlotEntry entries[30];
    GamePlayer player;
    u8 unk_190;
    u8 unk_191;
    u8 unk_192;
    u8 pad_193;
    u8 unk_194[4];
} GameSlotTable;
typedef struct {
    u8 pad_0[3];
    u8 unk_3;
    u8 pad_4[0x2C];
} GameObj5108;
typedef struct {
    u8 pad_0[0xD8];
    f32 unk_D8;
    u8 pad_DC[0x475 - 0xDC];
    u8 unk_475;
    u8 pad_476[0x482 - 0x476];
    u8 unk_482;
    u8 pad_483[0x49C - 0x483];
    void *unk_49C;
} GameRacer;
typedef struct {
    u8 pad_0[0x1FC];
} GameRaceRecord;
typedef struct {
    u8 pad_0[0x328];
    s8 unk_328;
} GameCar;
u32 fzgx_obj_lbl_1_bss_3C00;
u32 fzgx_obj_lbl_1_bss_3C04;
u32 fzgx_obj_lbl_1_bss_3C08;
s32 lbl_1_bss_3C08__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_3C10;
u8 fzgx_obj_lbl_1_bss_3C11;
u8 fzgx_obj_lbl_1_bss_3C12;
u8 lbl_1_bss_3C12__fzgx_offset_1;
u8 lbl_1_bss_3C12__fzgx_offset_2[0x8];
u8 fzgx_obj_lbl_1_bss_3C1C[0xE];
s16 fzgx_obj_lbl_1_bss_3C2A;
u32 lbl_1_bss_3C2A__fzgx_offset_2;
GameState fzgx_obj_lbl_1_bss_3C30;
s16 lbl_1_bss_3C30__fzgx_offset_14B8[2];
u16 fzgx_obj_lbl_1_bss_50EC[0x8];
s16 lbl_1_bss_50EC__fzgx_offset_10;
u16 lbl_1_bss_50EC__fzgx_offset_12;
u32 fzgx_obj_lbl_1_bss_5100;
u8 fzgx_obj_lbl_1_bss_5104[0x4];
GameObj5108 lbl_1_bss_5104__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_5138[0x104];
u8 fzgx_obj_lbl_1_bss_523C[0x20];
GameSlotTable fzgx_obj_lbl_1_bss_525C;
u16 fzgx_obj_lbl_1_bss_53F4;
u8 fzgx_pool_gap_bss_53F6;
u8 fzgx_pool_gap_bss_53F7;
u32 fzgx_obj_lbl_1_bss_53F8[0x22];
#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C00;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C04;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C08;
    s = *(u8 *)&lbl_1_bss_3C08__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C10;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C11;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C12;
    s = *(u8 *)&lbl_1_bss_3C12__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_3C12__fzgx_offset_2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C1C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C2A;
    s = *(u8 *)&lbl_1_bss_3C2A__fzgx_offset_2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C30;
    s = *(u8 *)&lbl_1_bss_3C30__fzgx_offset_14B8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_50EC;
    s = *(u8 *)&lbl_1_bss_50EC__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_50EC__fzgx_offset_12;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5100;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5104;
    s = *(u8 *)&lbl_1_bss_5104__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5138;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_523C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_525C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_53F4;
    s = *(u8 *)&fzgx_pool_gap_bss_53F6;
    s = *(u8 *)&fzgx_pool_gap_bss_53F7;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_53F8;
}
#pragma section code_type ".text"
typedef struct {
    u8 pad_0[0x81C0];
} GameRaceBuf;
extern void fn_1_3F2A0(void);
extern s32 fn_1_8623C(void);
extern void fn_80008BA8(void *, void *, u32);

#pragma opt_loop_invariants off
void fn_1_2DE00(s32 arg0)
{
    s32 i;
    GameRaceBuf *buf;
    s32 j;
    GameSlotEntry *e;
    GamePlayer *p;

    if (fzgx_obj_lbl_1_bss_3C30.unk_0 & 0x00400000) {
        return;
    }
    fn_1_3F2A0();
    buf = (GameRaceBuf *)lbl_1_bss_5480;
    fzgx_obj_lbl_1_bss_525C.unk_192 = 0;
    for (i = 0, j = 0; j < 30 && i < fzgx_obj_lbl_1_bss_3C30.unk_9; i++, j++) {
        p = &fzgx_obj_lbl_1_bss_3C30.players[i];
        e = &fzgx_obj_lbl_1_bss_525C.entries[p->unk_8];
        e->unk_4 = p->unk_80;
        e->unk_5 = p->unk_82;
        e->unk_6 = fzgx_obj_lbl_1_bss_523C[i];
        if (fzgx_obj_lbl_1_bss_53F8[i] != 0) {
            e->unk_0 = &buf[i];
        } else {
            e->unk_0 = NULL;
        }
    }
    p = &fzgx_obj_lbl_1_bss_3C30.players[fn_1_8623C()];
    p->unk_6 = 0;
    p->unk_6 += p->unk_13[0];
    p->unk_6 += p->unk_13[1];
    p->unk_6 += p->unk_13[2];
    p->unk_6 += p->unk_13[3];
    p->unk_6 += p->unk_13[4];
    fn_80008BA8(&fzgx_obj_lbl_1_bss_525C.player, p, sizeof(GamePlayer));
    fzgx_obj_lbl_1_bss_525C.unk_191 = 0;
    if (arg0 != 0) {
        fzgx_obj_lbl_1_bss_525C.unk_190 = fzgx_obj_lbl_1_bss_3C30.unk_7;
        fzgx_obj_lbl_1_bss_3C30.unk_0 |= 0x00400000;
    }
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_2DE00 */

/* fzgx:begin fn_1_2DF98 noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/stcoli.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"

typedef struct Node {
    u32 unk_0;
    u8 pad_4[0x8];
    s32 count;
    struct Node *children;
    u8 pad_14[0x50 - 0x14];
} Node;

typedef struct StcoliNode StcoliNode;

struct StcoliNode {
    u32 flags;
    u8 pad[8];
    s32 count;
    StcoliNode *items;
    u8 rest[0x3c];
};

typedef struct StcoliVec {
    u32 x;
    u32 y;
    u32 z;
} StcoliVec;

typedef struct {
    unsigned char pad0[0x0c];
    int count;
    void *entries;
} Fn118F28Object;

typedef struct Fn_1_20258Constants {
    unsigned char pad08[8];
    f32 value08;
    f32 value0c;
    unsigned char pad10[0xb0];
    f64 valuec0;
    f32 valuec8;
    unsigned char padcc[4];
    f64 valued0;
} Fn_1_20258Constants;

typedef struct {
    u32 f00, f04, f08, f0c, f10, f14, f18, f1c, f20, f24;
    u32 f28, f2c, f30, f34, f38, f3c, f40, f44;
} Cfg;

typedef struct {
    u8 pad_0[0x4];
    Cfg *cfg;
    u8 pad_8[0xc];
    f32 fx;
    f32 fy;
    f32 fz;
    f32 rxv;
    f32 ryv;
    f32 rzv;
    f32 sxv;
    f32 syv;
    f32 szv;
} Entity;

typedef struct {
    u32 count;
    u32 entries[1];
} Stack;

struct fn_1_2B478_lbl_801A6D00 {
    u32 unk_0;
};

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    f32 m[10];
    f64 d;
} Mtx;

struct Pool {
    u8 pad_0[0xc];
    f32 one;
    u8 pad_10[0xc];
    f32 two;
    u8 pad_20[0x14];
    f32 half;
};

struct fn_1_207DC_pool {
    u8 pad_0[8];
    f32 zero;
    f32 one;
    u8 pad_10[0xB0];
    f64 eps;
    f32 pi;
    u8 pad_CC[4];
    f64 two;
};

struct fn_1_21950_lbl_1_rodata_6C8 {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x14];
    f32 unk_20;
    u8 pad_24[0x10];
    f32 unk_34;
};

typedef struct {
    u8 pad_0[0x30];
    Vec3 pos;
    f32 ax;
    f32 ay;
    Vec3 v0;
    Vec3 e;
    Vec3 m;
    f32 d0;
    f32 d1;
    Vec3 o;
    u32 f7c;
    u8 pad_80[0x7c];
    u32 fffc;
} Rec;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    u32 f44;
} fn_1_18784_Cfg;

typedef struct {
    u32 f00;
    fn_1_18784_Cfg *cfg;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    f32 f18;
} Src;

typedef struct {
    u32 f00;
    fn_1_18784_Cfg *cfg;
    u32 f08;
    s32 f0c;
    Src *f10;
    u32 f14;
    f32 f18;
    f32 f1c;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2c;
} Motion;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_21CFC_Vec;

struct fn_1_2D524_Copy200 { char *a[10][5]; };

struct fn_1_2D524_Copy8 { char *a[2]; };

struct fn_1_2D524_lbl_1_rodata_BD8 {
    u8 pad_0[0x24];
    f32 unk_24;
    u8 pad_28[0x30];
    struct fn_1_2D524_Copy200 unk_58;
    struct fn_1_2D524_Copy8 unk_120;
    f32 unk_128;
    f32 unk_12C;
    f32 unk_130;
};
extern void fn_1_9E14C();
extern void fn_1_9E170(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern const f32 lbl_1_rodata_6D0;
extern f32 lbl_1_rodata_6F8;
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_z(u32);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void lbl_8006E0B4(f32, f32, f32);
extern Fn_1_20258Constants lbl_1_rodata_6C8;
extern u8 *lbl_801A66CC;
extern struct fn_1_2B478_lbl_801A6D00 lbl_801A6D00;
extern f64 __fabs(f64);
extern void lbl_8006DB74(void *);
extern void fn_1_18214();
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006DBE4();
extern void fn_1_1902C(StcoliNode *root, StcoliVec *vec, void *arg3, f32 value);
extern void fn_1_18784();
extern void fn_1_18F28(Fn118F28Object *obj, int *args, int arg2, float value);
extern u32 fn_1_203E4(void *, u32, void *, f32, f32, f32);
extern void OSReport(const char *format, ...);
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_8006DCA4(void);
extern void lbl_8006E1B0(void *, void *);
extern void fn_8003462C(u32 arg0, u32 arg1, u32 arg2);
extern void fn_80072558(void);
extern f32 lbl_1_rodata_6B0[6];
extern void fn_1_17D5C(Node *node, u32 *acc);
extern int fn_1_210A8(void *, f32 *, int, int, int);
extern int fn_1_16BA0(void *, void *, void *, int *, int);
extern f32 fn_1_16E68(void *, void *, int);
extern unsigned char lbl_1_rodata_840[];
extern void fn_1_22F90(void *self, int value);
extern void lbl_8006E1F0(void *, f32, f32, f32);
extern void fn_1_8A190(void *arg0, void *arg1);
extern int fn_1_15578();
extern void *memset(void *, int, unsigned int);
extern int fn_1_4C10(void);
extern u32 fn_1_4060(void);
extern void fn_1_EB080(int mode);
extern void fn_1_9D77C(u32, u32);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern u32 lbl_801A6410;
extern int fn_1_180F4(int first, int second, int count, int ascending);
extern void fn_1_21950(u32 arg0, f32 arg1, f32 arg2);
extern f32 lbl_1_rodata_6D4;
extern char lbl_1_bss_9C;
extern void fn_1_A2D84(u32 arg0);
extern u32 fn_1_8C66C(u32 index);
extern int fn_1_163BC(void *arg0, void *arg1, int mask, int value);
extern void lbl_8006E1D8(void *arg0, f32 arg1, f32 arg2, f32 arg3);
extern double lbl_1_rodata_910;
extern const f32 lbl_1_rodata_84C;
extern const f32 lbl_1_rodata_854;
extern s16 fn_1_7B054();
extern void *fn_1_868C0(s8 index);
extern void fn_1_F7338(int arg0, void *arg1, void *arg2);
extern const f32 lbl_1_rodata_85C;
extern void fn_8006E978(f32 *arg0, Vec3 *arg1, Vec3 *arg2);
extern void mathutil_mtxA_from_quat(void *);
extern void lbl_8006DFC4(void *);
extern f64 lbl_1_rodata_860[22];
extern f32 lbl_1_rodata_B74[25];
extern f32 lbl_8006D6FC(void *, void *);
extern s16 lbl_1_bss_3C2A[3];
extern f32 lbl_8006D188(s16 angle);
extern f32 lbl_8006D0B4(f32);
extern void fn_8006E7E4(void *, void *, s32);
extern u32 fn_1_8627C(s32 index);
extern u8 * fn_1_14F04(void);
extern u32 fn_1_2B684(u32);
extern u32 lbl_801A66C8[2];
extern f32 lbl_1_rodata_92C[10];
extern void lbl_8006DBAC(void *arg0);
extern void fn_8006E250(void *arg0, void *arg1);
extern void lbl_8006D668(void *arg0);
extern char *fn_1_14EA74(s16 arg0, char *arg1, s16 arg2);
extern char *fn_1_15BA78(char *name);
extern f32 fn_1_4B068(char *);
extern f32 fn_1_4B090(s32 value);
extern int sprintf(char *s, const char *format, ...);
extern s16 fn_1_12EF24(s16 row, s16 column);
extern struct fn_1_2D524_lbl_1_rodata_BD8 lbl_1_rodata_BD8;
extern u32 lbl_801A66B4;
extern u32 fn_1_4AEC0(u32 value);
extern void fn_1_F83F0(s16 arg0);
extern u32 fn_1_F8D10(void);
extern char *lbl_1_data_2BD54[][6];
extern void *fn_1_7F49C(s16 arg0, s16 arg1, void *arg2);
extern void fn_1_49410(void);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_49590(f32 value);
extern void fn_1_495B0(u32 value);
extern void fn_1_495C8(u8 value);
extern void fn_1_A2DC4(u32 arg0);
extern void fn_1_F2008(s32 arg);
extern void fn_1_F7F48(s16 value);
extern void fn_1_F8A58(u32 value);
extern void fn_1_F8C00(s32 value);
extern void fn_1_F8D38(u32 value);
extern void fn_1_F9D68(u32 arg);
extern void fn_1_F9DE8(u32 param);
extern u8 lbl_1_bss_6F316;
extern u32 fn_1_A1588(void *, u32);
extern void ADXT_Stop(void *);
extern u32 fn_1_435C(u32 value);
extern void fn_1_40E08(u32 arg0);
extern u32 lbl_1_rodata_D18;
extern u32 lbl_1_rodata_D1C[11];
extern void fn_1_49F0(u32 *value);
extern void fn_1_4A00(s32 enabled, u8 mode, void *value);
extern u32 lbl_1_bss_25B9C;
extern u32 fn_1_304A8(void);
extern void fn_1_3F2A0(void);

typedef struct GameStateB {
    u32 f_00;
    u8 pad_04;
    u8 f_05;
    u8 pad_06[2];
    u8 f_08;
    u8 pad_09[0xC4 - 0x09];
    u32 f_C4;
    u8 pad_C8[0x14BC - 0xC8];
} GameStateB;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_3C00;
u32 fzgx_obj_lbl_1_bss_3C04;
u32 fzgx_obj_lbl_1_bss_3C08[2];
u8 fzgx_obj_lbl_1_bss_3C10;
u8 fzgx_obj_lbl_1_bss_3C11;
u8 fzgx_obj_lbl_1_bss_3C12;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b5;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b6;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b7;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b8;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b9;
u32 fzgx_obj_lbl_1_bss_3C1C;
u8 lbl_1_bss_3C1C__fzgx_offset_4[10];
u8 fzgx_obj_lbl_1_bss_3C2A;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b5;
GameStateB fzgx_obj_lbl_1_bss_3C30;
u32 fzgx_obj_lbl_1_bss_50EC[5];
u32 fzgx_obj_lbl_1_bss_5100;
s8 fzgx_obj_lbl_1_bss_5104;
u8 lbl_1_bss_5104__fzgx_offset_4[0x30];
u32 fzgx_obj_lbl_1_bss_5138[65];
u32 fzgx_obj_lbl_1_bss_523C[8];
u32 fzgx_obj_lbl_1_bss_525C[102];
u16 fzgx_obj_lbl_1_bss_53F4;
u32 fzgx_obj_lbl_1_bss_53F8[34];
u32 fzgx_obj_lbl_1_bss_5480[33216];
u16 fzgx_obj_lbl_1_bss_25B80;
s32 fzgx_obj_lbl_1_bss_25B84;
void *fzgx_obj_lbl_1_bss_25B88;
u16 *lbl_1_bss_25B88__fzgx_offset_4;
s32 lbl_1_bss_25B88__fzgx_offset_8;
u32 lbl_1_bss_25B88__fzgx_offset_C;
u16 fzgx_obj_lbl_1_bss_25B98;
u32 fzgx_obj_lbl_1_bss_25B9C;
u32 fzgx_obj_lbl_1_bss_25BA0[42];
u32 fzgx_obj_lbl_1_bss_25C48[23];
u32 fzgx_obj_lbl_1_bss_25CA4[11];
u32 fzgx_obj_lbl_1_bss_25CD0[105];
u32 fzgx_obj_lbl_1_bss_25E74[7];
u32 fzgx_obj_lbl_1_bss_25E90[2];
u8 fzgx_obj_lbl_1_bss_25E98[1];
u32 fzgx_obj_lbl_1_bss_25E9C[240];
u32 fzgx_obj_lbl_1_bss_2625C[8];
u32 fzgx_obj_lbl_1_bss_2627C[30];
u8 fzgx_obj_lbl_1_bss_262F4;
u32 fzgx_obj_lbl_1_bss_262F8[2];
u16 fzgx_obj_lbl_1_bss_26300;
u32 fzgx_obj_lbl_1_bss_26304[4];
u32 fzgx_obj_lbl_1_bss_26314[508];
u32 fzgx_obj_lbl_1_bss_26B04[5];
u8 fzgx_obj_lbl_1_bss_26B18;
u8 fzgx_obj_lbl_1_bss_26B19;
u8 fzgx_obj_lbl_1_bss_26B1A;
u8 fzgx_pool_fzgx_pad_26B1B;
u8 fzgx_pool_fzgx_pad_26B1C;
u8 fzgx_obj_lbl_1_bss_26B1D;
u8 fzgx_obj_lbl_1_bss_26B1E;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b5;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b6;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b7;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b8;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b9;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b10;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b11;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b12;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b13;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b14;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b15;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b16;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b17;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b18;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b19;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b20;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b21;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b22;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b23;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b24;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b25;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b26;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b27;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b28;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b29;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b30;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b31;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b32;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b33;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b34;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b35;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b36;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b37;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b38;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b39;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b40;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b41;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b42;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b43;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b44;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b45;
u32 fzgx_obj_lbl_1_bss_26B4C;
u32 fzgx_obj_lbl_1_bss_26B50;
u32 fzgx_obj_lbl_1_bss_26B54[2];
u8 fzgx_obj_lbl_1_bss_26B5C[30];
u8 fzgx_obj_lbl_1_bss_26B7A;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b5;
u32 fzgx_obj_lbl_1_bss_26B80[42];
u32 fzgx_obj_lbl_1_bss_26C28;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_bss_3C00;
    s = fzgx_obj_lbl_1_bss_3C04;
    s = fzgx_obj_lbl_1_bss_3C08[0];
    s = fzgx_obj_lbl_1_bss_3C10;
    s = fzgx_obj_lbl_1_bss_3C11;
    s = fzgx_obj_lbl_1_bss_3C12;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b5;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b6;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b7;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b8;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b9;
    s = fzgx_obj_lbl_1_bss_3C1C;
    s = lbl_1_bss_3C1C__fzgx_offset_4[0];
    s = fzgx_obj_lbl_1_bss_3C2A;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b5;
    s = *(u32 *)&fzgx_obj_lbl_1_bss_3C30;
    s = fzgx_obj_lbl_1_bss_50EC[0];
    s = fzgx_obj_lbl_1_bss_5100;
    s = fzgx_obj_lbl_1_bss_5104;
    s = lbl_1_bss_5104__fzgx_offset_4[0];
    s = fzgx_obj_lbl_1_bss_5138[0];
    s = fzgx_obj_lbl_1_bss_523C[0];
    s = fzgx_obj_lbl_1_bss_525C[0];
    s = fzgx_obj_lbl_1_bss_53F4;
    s = fzgx_obj_lbl_1_bss_53F8[0];
    s = fzgx_obj_lbl_1_bss_5480[0];
    s = fzgx_obj_lbl_1_bss_25B80;
    s = fzgx_obj_lbl_1_bss_25B84;
    s = *(u32 *)&fzgx_obj_lbl_1_bss_25B88;
    s = *(u32 *)&lbl_1_bss_25B88__fzgx_offset_4;
    s = lbl_1_bss_25B88__fzgx_offset_8;
    s = lbl_1_bss_25B88__fzgx_offset_C;
    s = fzgx_obj_lbl_1_bss_25B98;
    s = fzgx_obj_lbl_1_bss_25B9C;
    s = fzgx_obj_lbl_1_bss_25BA0[0];
    s = fzgx_obj_lbl_1_bss_25C48[0];
    s = fzgx_obj_lbl_1_bss_25CA4[0];
    s = fzgx_obj_lbl_1_bss_25CD0[0];
    s = fzgx_obj_lbl_1_bss_25E74[0];
    s = fzgx_obj_lbl_1_bss_25E90[0];
    s = fzgx_obj_lbl_1_bss_25E98[0];
    s = fzgx_obj_lbl_1_bss_25E9C[0];
    s = fzgx_obj_lbl_1_bss_2625C[0];
    s = fzgx_obj_lbl_1_bss_2627C[0];
    s = fzgx_obj_lbl_1_bss_262F4;
    s = fzgx_obj_lbl_1_bss_262F8[0];
    s = fzgx_obj_lbl_1_bss_26300;
    s = fzgx_obj_lbl_1_bss_26304[0];
    s = fzgx_obj_lbl_1_bss_26314[0];
    s = fzgx_obj_lbl_1_bss_26B04[0];
    s = fzgx_obj_lbl_1_bss_26B18;
    s = fzgx_obj_lbl_1_bss_26B19;
    s = fzgx_obj_lbl_1_bss_26B1A;
    s = fzgx_pool_fzgx_pad_26B1B;
    s = fzgx_pool_fzgx_pad_26B1C;
    s = fzgx_obj_lbl_1_bss_26B1D;
    s = fzgx_obj_lbl_1_bss_26B1E;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b5;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b6;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b7;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b8;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b9;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b10;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b11;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b12;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b13;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b14;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b15;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b16;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b17;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b18;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b19;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b20;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b21;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b22;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b23;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b24;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b25;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b26;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b27;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b28;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b29;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b30;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b31;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b32;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b33;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b34;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b35;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b36;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b37;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b38;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b39;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b40;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b41;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b42;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b43;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b44;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b45;
    s = fzgx_obj_lbl_1_bss_26B4C;
    s = fzgx_obj_lbl_1_bss_26B50;
    s = fzgx_obj_lbl_1_bss_26B54[0];
    s = fzgx_obj_lbl_1_bss_26B5C[0];
    s = fzgx_obj_lbl_1_bss_26B7A;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b5;
    s = fzgx_obj_lbl_1_bss_26B80[0];
    s = fzgx_obj_lbl_1_bss_26C28;
}
#pragma section code_type ".text"

#pragma opt_common_subs on
#pragma opt_propagation off
s32 fn_1_2DF98(void)
{
    u32 ready;
    void *saved;
    s32 count;
    s32 ch;

    fzgx_obj_lbl_1_bss_5104 = -1;
    if ((fzgx_obj_lbl_1_bss_3C30.f_00 & 0x800800) == 0x800800) {
        fzgx_obj_lbl_1_bss_3C30.f_C4 = 0;
        lbl_1_bss_5104__fzgx_offset_4[3] &= 0xFE;
    }

    if (lbl_1_bss_6F316 != 0 && fzgx_obj_lbl_1_bss_25B84 != 0) {
        if (lbl_1_data_5B7C == 5) {
            fn_1_A1588((void *)lbl_1_bss_6EAD0.unk_0->unk_0, 0x18);
        } else {
            fn_1_A1588((void *)lbl_1_bss_6EAD0.unk_0->unk_0, 0x10);
        }
        ADXT_Stop((void *)lbl_1_bss_6EAD0.unk_0->unk_4);
        lbl_1_bss_6F316 = 0;
        if (lbl_1_data_5B7C == 1) {
            saved = (void *)fn_1_435C( (u32)(void *)(fzgx_obj_lbl_1_bss_25B88));
            fn_1_40E08(0x12C);
            fn_1_435C( (u32)(void *)(saved));
        }
    }

    ch = fzgx_obj_lbl_1_bss_3C30.f_08;
    if (ch < 1) ch = 1;
    if (lbl_1_bss_25B88__fzgx_offset_4 == 0) return 1;
    ready = fzgx_obj_lbl_1_bss_3C30.f_05;
    if (ready == 0) ch -= 1;
    count = lbl_1_bss_25B88__fzgx_offset_8;
    if (count >= ch) {
        if (*lbl_1_bss_25B88__fzgx_offset_4 == 0x10) {
            if (fzgx_obj_lbl_1_bss_25B84 != 0) {
                if (lbl_1_data_5B7C == 5) {
                    u32 msg = lbl_1_rodata_D18;
                    fn_1_49F0(&msg);
                } else {
                    u32 msg2 = lbl_1_rodata_D1C[0];
                    fn_1_49F0(&msg2);
                }
            }
            fn_1_4A00(0, 0xF, (void *)fzgx_obj_lbl_1_bss_5100);
        } else if (*lbl_1_bss_25B88__fzgx_offset_4 == 0) {
            if (ready == 0) return count > ch;
            return 1;
        }
        lbl_1_bss_25B88__fzgx_offset_C = *lbl_1_bss_25B88__fzgx_offset_4;
    }
    return 0;
}
#pragma opt_propagation reset
#pragma opt_common_subs reset
/* fzgx:end fn_1_2DF98 */

/* fzgx:begin fn_1_2E1B8 pool noprologue */
#include "types.h"

struct fn_1_2E1B8_t {
    u8 pad_0[0xC0];
    u32 (*unk_C0)(void);
};

struct fn_1_2E1B8_s {
    u8 pad_0[0xC];
    s32 unk_C;
    u8 pad_10[0x20];
    struct fn_1_2E1B8_t t;
    u8 pad_F4[0x13F4];
    u16 unk_14E8;
};

extern int fn_1_4C10(void);
extern u32 lbl_1_bss_25B9C;
extern u32 fn_1_304A8(void);
extern u32 fn_1_4060(void);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_3C00;
u32 fzgx_obj_lbl_1_bss_3C04;
u32 lbl_1_bss_3C08;
s32 lbl_1_bss_3C08_4;
u8 lbl_1_bss_3C10;
u8 fzgx_obj_lbl_1_bss_3C11;
u16 fzgx_obj_lbl_1_bss_3C12;
u32 lbl_1_bss_3C12_fill_3C14[2];
u32 fzgx_obj_lbl_1_bss_3C1C[3];
u16 lbl_1_bss_3C1C_fill_3C28;
u16 fzgx_obj_lbl_1_bss_3C2A;
u32 lbl_1_bss_3C2A_fill_3C2C;
struct fn_1_2E1B8_t fzgx_obj_lbl_1_bss_3C30;
u32 lbl_1_bss_3C30_fill_3CF4[1277];
u16 lbl_1_bss_3C30_14B8;
u16 lbl_1_bss_3C30_fill_50EA;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C00;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C04;
    s = *(u8 *)&lbl_1_bss_3C08;
    s = *(u8 *)&lbl_1_bss_3C08_4;
    s = *(u8 *)&lbl_1_bss_3C10;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C11;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C12;
    s = *(u8 *)&lbl_1_bss_3C12_fill_3C14;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C1C;
    s = *(u8 *)&lbl_1_bss_3C1C_fill_3C28;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C2A;
    s = *(u8 *)&lbl_1_bss_3C2A_fill_3C2C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C30;
    s = *(u8 *)&lbl_1_bss_3C30_fill_3CF4;
    s = *(u8 *)&lbl_1_bss_3C30_14B8;
    s = *(u8 *)&lbl_1_bss_3C30_fill_50EA;
}
#pragma section code_type ".text"

#pragma opt_lifetimes off
void fn_1_2E1B8(void) {
    u32 (* fzgx_live)(void);
    
    struct fn_1_2E1B8_t *q;
    u32 v;
    if (fn_1_4C10() == 0) {
        lbl_1_bss_3C30_14B8 = 45;
        if (lbl_1_bss_3C08_4 != 0) {
            q = &fzgx_obj_lbl_1_bss_3C30;
            lbl_1_bss_25B9C = 0;
            if ((fzgx_live = q->unk_C0) != 0) {
                v = fzgx_live();
                if (v & 4) {
                    lbl_1_bss_25B9C = 1;
                }
                if (v & 2) {
                    fn_1_304A8();
                }
                if (v & 1) {
                    return;
                }
            }
            lbl_1_bss_3C08_4 = 0;
        }
        fn_1_4060();
    }
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_2E1B8 */

/* fzgx:begin fn_1_2E268 */
#include "rel/main_rel/stcoli.h"

void fn_1_2E268(void) {
    Obj_1_bss_3C30 *b = &lbl_1_bss_3C30;
    s32 i;
    s32 j;
    u8 *e;

    for (i = 0; i < b->unk_9; i++) {
        e = (u8 *)b + 0xd4 + i * 0xa0;
        *(u16 *)(e + 4) = 0;
        *(u32 *)(e + 0x78) = 0;
        *(u16 *)(e + 6) = 0;
        if (b->unk_5 == 0) {
            *(u16 *)(e + 4) = *(u32 *)((u8 *)b + 0x1480 + i * 4);
            *(u16 *)(e + 0x9e) = *(u16 *)((u8 *)b + 0x1478 + i * 2);
            e[0x83] = e[8];
        } else {
            for (j = 0; j < b->unk_A7; j++) {
                *(u16 *)(e + 4) += e[9 + j];
                *(u16 *)(e + 6) += e[0x13 + j];
                *(u32 *)(e + 0x78) += *(u16 *)(e + 0x4c + j * 2);
            }
        }
        e[b->unk_A7 + 0xe] = 0xff;
    }
    if (b->unk_A7 != 0) {
        fn_1_3F2A0();
    } else {
        for (i = 0; i < b->unk_9; i++) {
            u8 v = *(u8 *)(*(u32 *)((u8 *)b + 0x2c + i * 4) + 0x115);
            ((Obj_1_bss_3C30 *)((u8 *)&lbl_1_bss_3C30 + v))->unk_1394 = i;
            ((u8 *)b)[0xdc + i * 0xa0] = v;
        }
    }
}
/* fzgx:end fn_1_2E268 */

/* fzgx:begin fn_1_2E928 noprologue */
#include "types.h"

typedef struct {
    u8 pad_0[0x4];
    u16 unk_4;
    u8 pad_6[0x3];
    u8 unk_9[5];
    u8 unk_E[5];
    u8 unk_13[5];
    s16 unk_18[6];
    u32 unk_24[5];
    u32 unk_38[5];
    u16 unk_4C[22];
    u32 unk_78;
    u8 pad_7C[0x24];
} StEntry;

typedef struct {
    u8 pad_0[0x5];
    u8 unk_5;
    u8 pad_6[0x3];
    u8 unk_9;
    u8 pad_A[0x4];
    u8 unk_E[0x99];
    u8 unk_A7;
    u8 pad_A8[0x2C];
    StEntry entries[1];
} StState;

typedef struct {
    u8 pad_0[0x1D4];
    u8 unk_1D4;
    u8 unk_1D5;
    u16 unk_1D6;
    u8 pad_1D8[0x8];
    u8 unk_1E0;
    u8 unk_1E1;
    u16 unk_1E2;
} StInfo;

typedef struct {
    u32 unk_0;
    s16 unk_4;
    u8 pad_6[0xD2];
    f32 unk_D8;
    u8 pad_DC[0x134];
    u16 unk_210;
    u8 pad_212[0x270];
    u8 unk_482;
    u8 pad_483[0x19];
    StInfo *unk_49C;
} StRacer;

extern StState lbl_1_bss_3C30;
extern const f32 lbl_1_rodata_D48[9];
extern const u8 lbl_1_rodata_DB38[32];
extern void fn_1_2E3B4(StEntry *entry, StRacer *racer);

void fn_1_2E928(StRacer *racer) {
    StState *st = &lbl_1_bss_3C30;
    StInfo *info = racer->unk_49C;
    StEntry *e = &st->entries[racer->unk_4];
    s32 i;
    s32 mult;

    u8 k = st->unk_A7;

    if (e->unk_E[k] != 0xFE && e->unk_E[k] != 0xFF) {
        return;
    }
    e->unk_24[k] = (info->unk_1E0 << 20) | (info->unk_1E1 << 12) | info->unk_1E2;
    e->unk_38[st->unk_A7] = (info->unk_1D4 << 20) | (info->unk_1D5 << 12) | info->unk_1D6;
    if (racer->unk_D8 > lbl_1_rodata_D48[0]) {
        e->unk_18[st->unk_A7] = 9999;
    } else {
        e->unk_18[st->unk_A7] = racer->unk_D8;
    }
    if (racer->unk_482 > 30) {
        e->unk_13[st->unk_A7] = 30;
    } else {
        e->unk_13[st->unk_A7] = racer->unk_482;
    }
    if (!(racer->unk_0 & 0x10000)) {
        e->unk_E[st->unk_A7] = 0xFE;
        if (lbl_1_bss_3C30.unk_5 != 0) {
            e->unk_9[st->unk_A7] = 0;
            e->unk_4C[st->unk_A7] = 0;
        }
    } else {
        s16 id = racer->unk_4;

        for (i = 0; i < lbl_1_bss_3C30.unk_9; i++) {
            if (id == lbl_1_bss_3C30.unk_E[i]) {
                break;
            }
        }
        e->unk_E[st->unk_A7] = i;
        e->unk_4C[st->unk_A7] = 0;
        if (lbl_1_bss_3C30.unk_5 != 0) {
            if (i < 30) {
                e->unk_9[st->unk_A7] = lbl_1_rodata_DB38[i];
            } else {
                e->unk_9[st->unk_A7] = 0;
            }
        }
        e->unk_4 += e->unk_9[st->unk_A7];
        mult = 4 - e->unk_E[st->unk_A7];
        if (mult < 1) {
            mult = 1;
        } else if (mult == 4) {
            mult++;
        }
        e->unk_4C[st->unk_A7] = mult * (racer->unk_210 + e->unk_9[st->unk_A7] * 2);
        e->unk_78 += e->unk_4C[st->unk_A7];
    }
    fn_1_2E3B4(e, racer);
}
/* fzgx:end fn_1_2E928 */

/* fzgx:begin fn_1_2EBB8 pool noprologue */
#include "types.h"

#pragma section code_type ".fzgxpool"
static const unsigned long fzgx_pool_table1[1] = {0xFFFFFF00};  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef struct {
    u8 r, g, b, a;
} Color4;

typedef struct {
    u8 type;
    u8 state;
    u8 pad_2[2];
    char *name;
} StcoliMsg;

typedef struct {
    u32 flags;
    u8 pad_4[1];
    u8 unk_5;
    u8 pad_6[0xBE];
    u32 (*callback)(void);
    u8 pad_c8[0x132E];
    u8 unk_13f6;
} StcoliSub;

typedef struct {
    u8 pad_0[0x4];
    f32 zero;
    u8 pad_8[0x1C];
    f32 f24;
    f32 f28;
    u8 pad_2C[0x148];
    Color4 col174;
    Color4 col178;
    f32 f17c;
    f32 f180;
    f32 f184;
    f32 f188;
    f32 f18c;
    f32 f190;
} StcoliPool;

typedef struct {
    u8 pad_0[0x43c];
    f32 unk_43c;
    f32 unk_440;
    f32 unk_444;
    f32 unk_448;
    u8 pad_44c[0x354];
    char *names[14];
    u8 pad_7d8[0x2e4];
    char title[4];
} StcoliDataA;

extern const StcoliPool lbl_1_rodata_BD8;
extern u8 lbl_1_data_5730;

extern void fn_1_4068C(StcoliMsg *);
extern char *fn_1_15BA78(char *);
extern u32 fn_1_2C97C(void);
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_495C8(u8);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_494DC(s16);
extern void fn_1_4955C(f32, f32);
extern f32 fn_1_4B068(char *);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 lbl_1_bss_3C00;
u32 stcoli_fill_4[0xB];
StcoliSub stcoli_sub;
u32 stcoli_fill_1428[0x37];
s8 stcoli_cur_line;
u8 stcoli_fill_1505;
u16 stcoli_fill_1506;
StcoliMsg stcoli_msg;
u32 stcoli_fill_1510[0x82B5];
u16 stcoli_fill_21fe4;
u16 stcoli_hud_flags;
u16 stcoli_hud_1fe8;
u8 stcoli_hud_1fea;
u8 stcoli_fill_21feb;
s32 stcoli_hud_1fec;
s32 stcoli_hud_1ff0;
s32 stcoli_hud_1ff4;
f32 stcoli_hud_1ff8;
f32 stcoli_hud_1ffc;
Color4 stcoli_hud_colors[10];
Color4 stcoli_hud_colors2[2];
f32 stcoli_hud_width;
f32 stcoli_hud_height;

#pragma section code_type ".fzgxpool"

#pragma section code_type ".text"

extern u8 fn_1_382C4__fzgx_offset_0[];
extern u8 fn_1_384E8__fzgx_offset_0[];
extern u8 fn_1_385A4__fzgx_offset_0[];
extern u8 fn_1_3867C__fzgx_offset_0[];
extern u8 fn_1_38BBC__fzgx_offset_0[];
extern u8 fn_1_38CF4__fzgx_offset_0[];
extern u8 fn_1_3908C__fzgx_offset_0[];
extern u8 fn_1_391F0__fzgx_offset_0[];
extern u8 fn_1_39420__fzgx_offset_0[];
extern u8 fn_1_395CC__fzgx_offset_0[];
extern u8 fn_1_39C60__fzgx_offset_0[];
extern u8 fn_1_3A044__fzgx_offset_0[];
extern u8 fn_1_3A2C4__fzgx_offset_0[];
extern u8 fn_1_3A330__fzgx_offset_0[];
extern u8 fn_1_3AEC4__fzgx_offset_0[];
extern u8 fn_1_3B11C__fzgx_offset_0[];
extern u8 fn_1_3B7D4__fzgx_offset_0[];
extern u8 fn_1_3C880__fzgx_offset_0[];
extern u8 fn_1_3CDB0__fzgx_offset_0[];
extern u8 fn_1_3CE94__fzgx_offset_0[];
extern u8 fn_1_3DB9C__fzgx_offset_0[];
extern u8 fn_1_3DDAC__fzgx_offset_0[];
extern u8 fn_1_3DE80__fzgx_offset_0[];
extern u8 fn_1_3E5D0__fzgx_offset_0[];
extern u8 fn_1_3E628__fzgx_offset_0[];
extern u8 fn_1_3E62C__fzgx_offset_0[];
extern u8 fn_1_3E66C__fzgx_offset_0[];
extern u8 fn_1_3E670__fzgx_offset_0[];
extern u8 fn_1_3E6D8__fzgx_offset_0[];
extern u8 fn_1_3EA70__fzgx_offset_0[];
extern u8 lbl_1_data_5730__fzgx_offset_0[];
extern u8 lbl_1_data_573C__fzgx_offset_0[];
extern u8 lbl_1_data_5744__fzgx_offset_0[];
extern u8 lbl_1_data_5750__fzgx_offset_0[];
extern u8 lbl_1_data_5758__fzgx_offset_0[];
extern u8 lbl_1_data_5764__fzgx_offset_0[];
extern u8 lbl_1_data_576C__fzgx_offset_0[];
extern u8 lbl_1_data_5774__fzgx_offset_0[];
extern u8 lbl_1_data_5798__fzgx_offset_0[];
extern u8 lbl_1_data_579C__fzgx_offset_0[];
extern u8 lbl_1_data_57A8__fzgx_offset_0[];
extern u8 lbl_1_data_57B4__fzgx_offset_0[];
extern u8 lbl_1_data_57C0__fzgx_offset_0[];
extern u8 lbl_1_data_57CC__fzgx_offset_0[];
extern u8 lbl_1_data_57D4__fzgx_offset_0[];
extern u8 lbl_1_data_57DC__fzgx_offset_0[];
extern u8 lbl_1_data_57E4__fzgx_offset_0[];
extern u8 lbl_1_data_57EC__fzgx_offset_0[];
extern u8 lbl_1_data_57F8__fzgx_offset_0[];
extern u8 lbl_1_data_5808__fzgx_offset_0[];
extern u8 lbl_1_data_5818__fzgx_offset_0[];
extern u8 lbl_1_data_5820__fzgx_offset_0[];
extern u8 lbl_1_data_5828__fzgx_offset_0[];
extern u8 lbl_1_data_5834__fzgx_offset_0[];
extern u8 lbl_1_data_5840__fzgx_offset_0[];
extern u8 lbl_1_data_5850__fzgx_offset_0[];
extern u8 lbl_1_data_5858__fzgx_offset_0[];
extern u8 lbl_1_data_5864__fzgx_offset_0[];
extern u8 lbl_1_data_5870__fzgx_offset_0[];
extern u8 lbl_1_data_5880__fzgx_offset_0[];
extern u8 lbl_1_data_5888__fzgx_offset_0[];
extern u8 lbl_1_data_5894__fzgx_offset_0[];
extern u8 lbl_1_data_58A0__fzgx_offset_0[];
extern u8 lbl_1_data_58B0__fzgx_offset_0[];
extern u8 lbl_1_data_58B8__fzgx_offset_0[];
extern u8 lbl_1_data_58C4__fzgx_offset_0[];
extern u8 lbl_1_data_58CC__fzgx_offset_0[];
extern u8 lbl_1_data_58D8__fzgx_offset_0[];
extern u8 lbl_1_data_58E8__fzgx_offset_0[];
extern u8 lbl_1_data_58F4__fzgx_offset_0[];
extern u8 lbl_1_data_5900__fzgx_offset_0[];
extern u8 lbl_1_data_5908__fzgx_offset_0[];
extern u8 lbl_1_data_591C__fzgx_offset_0[];
extern u8 lbl_1_data_592C__fzgx_offset_0[];
extern u8 lbl_1_data_593C__fzgx_offset_0[];
extern u8 lbl_1_data_5948__fzgx_offset_0[];
extern u8 lbl_1_data_5954__fzgx_offset_0[];
extern u8 lbl_1_data_5964__fzgx_offset_0[];
extern u8 lbl_1_data_596C__fzgx_offset_0[];
extern u8 lbl_1_data_5978__fzgx_offset_0[];
extern u8 lbl_1_data_5980__fzgx_offset_0[];
extern u8 lbl_1_data_5988__fzgx_offset_0[];
extern u8 lbl_1_data_5990__fzgx_offset_0[];
extern u8 lbl_1_data_5A4C__fzgx_offset_0[];
extern u8 lbl_1_data_5A5C__fzgx_offset_0[];
extern u8 lbl_1_data_5A68__fzgx_offset_0[];
extern u8 lbl_1_data_5A74__fzgx_offset_0[];
extern u8 lbl_1_data_5A80__fzgx_offset_0[];
extern u8 lbl_1_data_5A88__fzgx_offset_0[];
extern u8 lbl_1_data_5A94__fzgx_offset_0[];
extern u8 lbl_1_data_5AA0__fzgx_offset_0[];
extern u8 lbl_1_data_5AAC__fzgx_offset_0[];
extern u8 lbl_1_data_5AB4__fzgx_offset_0[];
extern u8 lbl_1_data_5B94__fzgx_offset_0[];
extern u8 lbl_1_data_5BBC__fzgx_offset_0[];
extern u8 lbl_1_data_5BDC__fzgx_offset_0[];
extern u8 lbl_1_data_5C10__fzgx_offset_0[];
extern u8 lbl_1_data_5C6C__fzgx_offset_0[];
extern u8 lbl_1_data_5CC0__fzgx_offset_0[];
extern u8 lbl_1_data_5D1C__fzgx_offset_0[];
extern u8 lbl_1_data_5D78__fzgx_offset_0[];
extern u8 lbl_1_data_5DC8__fzgx_offset_0[];
extern u8 lbl_1_data_5E1C__fzgx_offset_0[];
extern u8 lbl_1_data_5E3C__fzgx_offset_0[];
extern u8 lbl_1_data_5E48__fzgx_offset_0[];
extern u8 lbl_1_data_5E58__fzgx_offset_0[];
extern u8 lbl_1_data_5E60__fzgx_offset_0[];
extern u8 lbl_1_data_5E70__fzgx_offset_0[];
extern u8 lbl_1_data_5E7C__fzgx_offset_0[];
extern u8 lbl_1_data_5E8C__fzgx_offset_0[];
extern u8 lbl_1_data_5E94__fzgx_offset_0[];
extern u8 lbl_1_data_5EA0__fzgx_offset_0[];
extern u8 lbl_1_data_5EAC__fzgx_offset_0[];
extern u8 lbl_1_data_5EB4__fzgx_offset_0[];
extern u8 lbl_1_data_5EC0__fzgx_offset_0[];
extern u8 lbl_1_data_5EC8__fzgx_offset_0[];
static u32 fzgx_pool_native_lbl_1_data_5730_gap_0[271] = {0x4F564552, 0x54414B45, 0x00000000, 0x4A554D50, 0x00000000, 0x454E454D, 0x59484954, 0x00000000, 0x57414C4C, 0x48495400, 0x53494445, 0x42595349, 0x44450000, 0x53544152, 0x54000000, 0x474F414C, 0x00000000, 0x4C415000, (u32)lbl_1_data_5730__fzgx_offset_0, (u32)lbl_1_data_573C__fzgx_offset_0, (u32)lbl_1_data_5744__fzgx_offset_0, (u32)lbl_1_data_5750__fzgx_offset_0, (u32)lbl_1_data_5758__fzgx_offset_0, (u32)lbl_1_data_5764__fzgx_offset_0, (u32)lbl_1_data_576C__fzgx_offset_0, (u32)lbl_1_data_5774__fzgx_offset_0, 0x4E4F4E00, 0x4D415354, 0x45522052, 0x45435600, 0x4D415354, 0x45522053, 0x454E4400, 0x534C4156, 0x45205345, 0x4E440000, 0x534C4156, 0x45205245, 0x43560000, 0x494E4954, 0x00000000, 0x54455354, 0x00000000, 0x54455354, 0x454E4400, 0x53455455, 0x50000000, 0x53455455, 0x505F444F, 0x4E450000, 0x53455455, 0x505F434F, 0x554E5445, 0x52000000, 0x53455455, 0x505F434E, 0x545F444F, 0x4E450000, 0x554E4C49, 0x4E4B0000, 0x434F494E, 0x00000000, 0x454E5452, 0x595F5741, 0x49540000, 0x4348414C, 0x4C454E47, 0x45520000, 0x4348414C, 0x4C454E47, 0x45525F4F, 0x4B000000, 0x454E5452, 0x59000000, 0x454E5452, 0x595F4F4B, 0x00000000, 0x53494E47, 0x4C454348, 0x45434B00, 0x53494E47, 0x4C454348, 0x45434B5F, 0x4F4B0000, 0x434F5552, 0x53450000, 0x434F5552, 0x53455F4F, 0x4B000000, 0x434F5552, 0x53455F44, 0x41544100, 0x434F5552, 0x53455F44, 0x4154415F, 0x4F4B0000, 0x4D414348, 0x494E4500, 0x4D414348, 0x494E455F, 0x4F4B0000, 0x434F4E46, 0x49470000, 0x434F4E46, 0x49475F4F, 0x4B000000, 0x434F554E, 0x54455241, 0x444A5553, 0x54000000, 0x4C494E4B, 0x57414954, 0x00000000, 0x4C494E4B, 0x57414954, 0x4F4B0000, 0x4C494E4B, 0x53454C00, 0x4C494E4B, 0x44454C49, 0x56455259, 0x53544152, 0x54000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x00000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x4F4B0000, 0x4C494E4B, 0x53454C4F, 0x4B000000, 0x434F5552, 0x53455649, 0x45570000, 0x434F5552, 0x53455649, 0x45575F4F, 0x4B000000, 0x4C494E4B, 0x52455100, 0x4C494E4B, 0x5354414E, 0x44425900, 0x4C494E4B, 0x4F4B0000, 0x4C494E4B, 0x00000000, 0x50415553, 0x45000000, 0x4552524F, 0x52000000, (u32)lbl_1_data_5798__fzgx_offset_0, (u32)lbl_1_data_579C__fzgx_offset_0, (u32)lbl_1_data_57A8__fzgx_offset_0, (u32)lbl_1_data_57B4__fzgx_offset_0, (u32)lbl_1_data_57C0__fzgx_offset_0, (u32)lbl_1_data_57CC__fzgx_offset_0, (u32)lbl_1_data_57D4__fzgx_offset_0, (u32)lbl_1_data_57DC__fzgx_offset_0, (u32)lbl_1_data_57E4__fzgx_offset_0, (u32)lbl_1_data_57EC__fzgx_offset_0, (u32)lbl_1_data_57F8__fzgx_offset_0, (u32)lbl_1_data_5808__fzgx_offset_0, (u32)lbl_1_data_5818__fzgx_offset_0, (u32)lbl_1_data_5820__fzgx_offset_0, (u32)lbl_1_data_5828__fzgx_offset_0, (u32)lbl_1_data_5834__fzgx_offset_0, (u32)lbl_1_data_5840__fzgx_offset_0, (u32)lbl_1_data_5850__fzgx_offset_0, (u32)lbl_1_data_5858__fzgx_offset_0, (u32)lbl_1_data_5864__fzgx_offset_0, (u32)lbl_1_data_5870__fzgx_offset_0, (u32)lbl_1_data_5880__fzgx_offset_0, (u32)lbl_1_data_5888__fzgx_offset_0, (u32)lbl_1_data_5894__fzgx_offset_0, (u32)lbl_1_data_58A0__fzgx_offset_0, (u32)lbl_1_data_58B0__fzgx_offset_0, (u32)lbl_1_data_58B8__fzgx_offset_0, (u32)lbl_1_data_58C4__fzgx_offset_0, (u32)lbl_1_data_58CC__fzgx_offset_0, (u32)lbl_1_data_58D8__fzgx_offset_0, (u32)lbl_1_data_58E8__fzgx_offset_0, (u32)lbl_1_data_58F4__fzgx_offset_0, (u32)lbl_1_data_5900__fzgx_offset_0, (u32)lbl_1_data_5908__fzgx_offset_0, (u32)lbl_1_data_591C__fzgx_offset_0, (u32)lbl_1_data_592C__fzgx_offset_0, (u32)lbl_1_data_593C__fzgx_offset_0, (u32)lbl_1_data_5948__fzgx_offset_0, (u32)lbl_1_data_5954__fzgx_offset_0, (u32)lbl_1_data_5964__fzgx_offset_0, (u32)lbl_1_data_596C__fzgx_offset_0, (u32)lbl_1_data_5978__fzgx_offset_0, (u32)lbl_1_data_5980__fzgx_offset_0, (u32)lbl_1_data_5988__fzgx_offset_0, (u32)lbl_1_data_5990__fzgx_offset_0, 0x636F7572, 0x73655F69, 0x6E74726F, 0x00000000, 0x63757374, 0x6F6D697A, 0x65000000, 0x636F7572, 0x73655F76, 0x69657700, 0x72616365, 0x5F737461, 0x72740000, 0x72616365, 0x00000000, 0x72616365, 0x5F726573, 0x756C7400, 0x6661696C, 0x5F726573, 0x756C7400, 0x70696C6F, 0x74706F69, 0x6E740000, 0x6F766572, 0x00000000, 0x7469636B, 0x65740000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)fn_1_382C4__fzgx_offset_0, (u32)fn_1_384E8__fzgx_offset_0, (u32)fn_1_385A4__fzgx_offset_0, (u32)lbl_1_data_5A4C__fzgx_offset_0, (u32)fn_1_3867C__fzgx_offset_0, (u32)fn_1_38BBC__fzgx_offset_0, (u32)fn_1_38CF4__fzgx_offset_0, (u32)lbl_1_data_5A5C__fzgx_offset_0, (u32)fn_1_3908C__fzgx_offset_0, (u32)fn_1_391F0__fzgx_offset_0, (u32)fn_1_39420__fzgx_offset_0, (u32)lbl_1_data_5A68__fzgx_offset_0, (u32)fn_1_395CC__fzgx_offset_0, (u32)fn_1_39C60__fzgx_offset_0, (u32)fn_1_3A044__fzgx_offset_0, (u32)lbl_1_data_5A74__fzgx_offset_0, (u32)fn_1_3A2C4__fzgx_offset_0, (u32)fn_1_3A330__fzgx_offset_0, (u32)fn_1_3AEC4__fzgx_offset_0, (u32)lbl_1_data_5A80__fzgx_offset_0, (u32)fn_1_3B11C__fzgx_offset_0, (u32)fn_1_3B7D4__fzgx_offset_0, (u32)fn_1_3C880__fzgx_offset_0, (u32)lbl_1_data_5A88__fzgx_offset_0, (u32)fn_1_3CDB0__fzgx_offset_0, (u32)fn_1_3CE94__fzgx_offset_0, (u32)fn_1_3DB9C__fzgx_offset_0, (u32)lbl_1_data_5A94__fzgx_offset_0, (u32)fn_1_3E628__fzgx_offset_0, (u32)fn_1_3E62C__fzgx_offset_0, (u32)fn_1_3E66C__fzgx_offset_0, (u32)lbl_1_data_5AA0__fzgx_offset_0, (u32)fn_1_3DDAC__fzgx_offset_0, (u32)fn_1_3DE80__fzgx_offset_0, (u32)fn_1_3E5D0__fzgx_offset_0, (u32)lbl_1_data_5AAC__fzgx_offset_0, (u32)fn_1_3E670__fzgx_offset_0, (u32)fn_1_3E6D8__fzgx_offset_0, (u32)fn_1_3EA70__fzgx_offset_0, (u32)lbl_1_data_5AB4__fzgx_offset_0}; /* fzgx-allow: A1 measured pool bytes and bindings */
static f32 fzgx_pool_native_lbl_1_data_5730_unk_43c = 320.0f; /* fzgx-allow: A1 measured pool bytes and bindings */
static f32 fzgx_pool_native_lbl_1_data_5730_unk_440 = 160.0f; /* fzgx-allow: A1 measured pool bytes and bindings */
static f32 fzgx_pool_native_lbl_1_data_5730_unk_444 = 320.0f; /* fzgx-allow: A1 measured pool bytes and bindings */
static f32 fzgx_pool_native_lbl_1_data_5730_unk_448 = 280.0f; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_1_data_5730_gap_44C[213] = {0x01000000, 0xFFFFFFFF, 0x0100FFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x54686973, 0x20726570, 0x6C617920, 0x616E6420, 0x67686F73, 0x740A2063, 0x616E6E6F, 0x74206265, 0x20736176, 0x65642E00, 0x54686973, 0x20726570, 0x6C617920, 0x63616E6E, 0x6F742062, 0x65207361, 0x7665642E, 0x00000000, 0x54686973, 0x2067686F, 0x73742063, 0x616E6E6F, 0x74206265, 0x20736176, 0x65642E00, (u32)lbl_1_data_5B94__fzgx_offset_0, (u32)lbl_1_data_5BBC__fzgx_offset_0, (u32)lbl_1_data_5BDC__fzgx_offset_0, (u32)lbl_1_data_5B94__fzgx_offset_0, (u32)lbl_1_data_5BBC__fzgx_offset_0, (u32)lbl_1_data_5BDC__fzgx_offset_0, 0x4E657720, 0x70617274, 0x73206861, 0x7665206A, 0x75737420, 0x61727269, 0x76656421, 0x0A2F6263, 0x30306666, 0x66662F25, 0x732F6263, 0x66666666, 0x66662F0A, 0x596F7520, 0x63616E20, 0x70757263, 0x68617365, 0x20746865, 0x6D20696E, 0x20746865, 0x2073686F, 0x702E0000, (u32)lbl_1_data_5C10__fzgx_offset_0, 0x4D616368, 0x696E650A, 0x2F626330, 0x30666666, 0x662F2573, 0x2F626366, 0x66666666, 0x662F0A68, 0x61732061, 0x72726976, 0x65642E0A, 0x596F7520, 0x63616E20, 0x70757263, 0x68617365, 0x20697420, 0x61742074, 0x68652073, 0x686F702E, 0x00000000, (u32)lbl_1_data_5C6C__fzgx_offset_0, 0x2F626330, 0x30666666, 0x662F2573, 0x2F626366, 0x66666666, 0x662F0A53, 0x74616666, 0x2047686F, 0x73747320, 0x68617665, 0x20617272, 0x69766564, 0x2E0A596F, 0x75206361, 0x6E207075, 0x72636861, 0x73652074, 0x68656D20, 0x61742074, 0x68652073, 0x686F702E, 0x00000000, (u32)lbl_1_data_5CC0__fzgx_offset_0, 0x2F626330, 0x30666666, 0x662F2573, 0x2F626366, 0x66666666, 0x662F0A61, 0x72636164, 0x6520636F, 0x75727365, 0x73206861, 0x76652061, 0x72726976, 0x65642E0A, 0x596F7520, 0x63616E20, 0x70757263, 0x68617365, 0x20746865, 0x6D206174, 0x20746865, 0x2073686F, 0x702E0000, (u32)lbl_1_data_5D1C__fzgx_offset_0, 0x53746F72, 0x790A2F62, 0x63303066, 0x6666662F, 0x25732F62, 0x63666666, 0x6666662F, 0x0A686173, 0x20617272, 0x69766564, 0x2E0A596F, 0x75206361, 0x6E207075, 0x72636861, 0x73652069, 0x74206174, 0x20746865, 0x2073686F, 0x702E0000, (u32)lbl_1_data_5D78__fzgx_offset_0, 0x2F626330, 0x30666666, 0x662F2573, 0x2F626366, 0x66666666, 0x662F0A73, 0x6F756E64, 0x73206861, 0x76652061, 0x72726976, 0x65642E0A, 0x596F7520, 0x63616E20, 0x70757263, 0x68617365, 0x20746865, 0x6D206174, 0x20746865, 0x2073686F, 0x702E0000, (u32)lbl_1_data_5DC8__fzgx_offset_0, 0x596F7520, 0x61637175, 0x69726564, 0x20256420, 0x5469636B, 0x6574732E, 0x00000000, (u32)lbl_1_data_5E1C__fzgx_offset_0, 0x436F6E74, 0x696E7565, 0x00000000, 0x50726F63, 0x65656420, 0x746F204E, 0x65787400, 0x52657472, 0x79000000, 0x4D697373, 0x696F6E20, 0x44697370, 0x6C617900, 0x53657474, 0x696E6773, 0x00000000, 0x53656C65, 0x63742043, 0x6F757273, 0x65000000, 0x5265706C, 0x61790000, 0x53617665, 0x20526570, 0x6C617900, 0x53617665, 0x2047686F, 0x73740000, 0x53746174, 0x75730000, 0x466F7263, 0x65205769, 0x6E000000, 0x52657365, 0x74000000, 0x51756974, 0x00000000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static char *fzgx_pool_native_lbl_1_data_5730_names[14] = {(char *)(u32)lbl_1_data_5E3C__fzgx_offset_0, (char *)(u32)lbl_1_data_5E48__fzgx_offset_0, (char *)(u32)lbl_1_data_5E48__fzgx_offset_0, (char *)(u32)lbl_1_data_5E58__fzgx_offset_0, (char *)(u32)lbl_1_data_5E60__fzgx_offset_0, (char *)(u32)lbl_1_data_5E70__fzgx_offset_0, (char *)(u32)lbl_1_data_5E7C__fzgx_offset_0, (char *)(u32)lbl_1_data_5E8C__fzgx_offset_0, (char *)(u32)lbl_1_data_5E94__fzgx_offset_0, (char *)(u32)lbl_1_data_5EA0__fzgx_offset_0, (char *)(u32)lbl_1_data_5EAC__fzgx_offset_0, (char *)(u32)lbl_1_data_5EB4__fzgx_offset_0, (char *)(u32)lbl_1_data_5EC0__fzgx_offset_0, (char *)(u32)lbl_1_data_5EC8__fzgx_offset_0}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_1_data_5730_gap_7D8[185] = {0x01000000, 0x436C6561, 0x72205363, 0x656E6172, 0x696F380A, 0x00000000, 0x4E6F7420, 0x67657420, 0x5363656E, 0x6172696F, 0x39207965, 0x740A0000, 0x4E6F7420, 0x436C6561, 0x72656420, 0x63757020, 0x25640A00, 0x67657420, 0x7363656E, 0x6172696F, 0x20390A00, 0x7265706C, 0x61795F65, 0x7869745F, 0x67617000, 0x2F626337, 0x66666666, 0x662F5072, 0x6F6C6F67, 0x75652F62, 0x63666666, 0x6666662F, 0x20202020, 0x20426C61, 0x636B2053, 0x6861646F, 0x77277320, 0x44697367, 0x72616365, 0x00000000, 0x2F626337, 0x66666666, 0x662F4368, 0x61707465, 0x7220312F, 0x62636666, 0x66666666, 0x2F202020, 0x20204361, 0x70746169, 0x6E204661, 0x6C636F6E, 0x20547261, 0x696E7300, 0x2F626337, 0x66666666, 0x662F4368, 0x61707465, 0x7220322F, 0x62636666, 0x66666666, 0x2F202020, 0x2020476F, 0x726F683A, 0x20546865, 0x2056656E, 0x67656675, 0x6C205361, 0x6D757261, 0x69000000, 0x2F626337, 0x66666666, 0x662F4368, 0x61707465, 0x7220332F, 0x62636666, 0x66666666, 0x2F202020, 0x20204869, 0x67682053, 0x74616B65, 0x7320696E, 0x204D7574, 0x65204369, 0x74790000, 0x2F626337, 0x66666666, 0x662F4368, 0x61707465, 0x7220342F, 0x62636666, 0x66666666, 0x2F202020, 0x20204368, 0x616C6C65, 0x6E676520, 0x6F662074, 0x68652042, 0x6C6F6F64, 0x79204368, 0x61696E00, 0x2F626337, 0x66666666, 0x662F4368, 0x61707465, 0x7220352F, 0x62636666, 0x66666666, 0x2F202020, 0x20205361, 0x7665204A, 0x6F647921, 0x00000000, 0x2F626337, 0x66666666, 0x662F4368, 0x61707465, 0x7220362F, 0x62636666, 0x66666666, 0x2F202020, 0x2020426C, 0x61636B20, 0x53686164, 0x6F772773, 0x20547261, 0x70000000, 0x2F626337, 0x66666666, 0x662F4368, 0x61707465, 0x7220372F, 0x62636666, 0x66666666, 0x2F202020, 0x20205468, 0x6520462D, 0x5A45524F, 0x20477261, 0x6E642050, 0x72697800, 0x2F626337, 0x66666666, 0x662F4368, 0x61707465, 0x7220382F, 0x62636666, 0x66666666, 0x2F202020, 0x20205365, 0x63726574, 0x73206F66, 0x20746865, 0x20436861, 0x6D70696F, 0x6E204265, 0x6C740000, 0x2F626337, 0x66666666, 0x662F4368, 0x61707465, 0x7220392F, 0x62636666, 0x66666666, 0x2F202020, 0x20204669, 0x6E616C65, 0x3A20456E, 0x74657220, 0x74686520, 0x43726561, 0x746F7273, 0x00000000, 0x4D757465, 0x20436974, 0x79000000, 0x42696720, 0x426C7565, 0x00000000, 0x839F0000, 0x746F5F67, 0x616D656F, 0x7665725F, 0x6576656E, 0x74000000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static char fzgx_pool_native_lbl_1_data_5730_title[4] = {0x51, 0x75, 0x69, 0x74};

#pragma section code_type ".fzgxpool"
static void fzgx_base_order_data(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: the TU references .data in retail order */
    s = *(u8 *)&fzgx_pool_native_lbl_1_data_5730_gap_0;
    s = *(u8 *)&fzgx_pool_native_lbl_1_data_5730_unk_43c;
    s = *(u8 *)&fzgx_pool_native_lbl_1_data_5730_unk_440;
    s = *(u8 *)&fzgx_pool_native_lbl_1_data_5730_unk_444;
    s = *(u8 *)&fzgx_pool_native_lbl_1_data_5730_unk_448;
    s = *(u8 *)&fzgx_pool_native_lbl_1_data_5730_gap_44C;
    s = *(u8 *)&fzgx_pool_native_lbl_1_data_5730_names;
    s = *(u8 *)&fzgx_pool_native_lbl_1_data_5730_gap_7D8;
    s = *(u8 *)&fzgx_pool_native_lbl_1_data_5730_title;
}
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_1_bss_3C00;
    s = *(u8 *)&stcoli_fill_4;
    s = *(u8 *)&stcoli_sub;
    s = *(u8 *)&stcoli_fill_1428;
    s = *(u8 *)&stcoli_cur_line;
    s = *(u8 *)&stcoli_fill_1505;
    s = *(u8 *)&stcoli_fill_1506;
    s = *(u8 *)&stcoli_msg;
    s = *(u8 *)&stcoli_fill_1510;
    s = *(u8 *)&stcoli_fill_21fe4;
    s = *(u8 *)&stcoli_hud_flags;
    s = *(u8 *)&stcoli_hud_1fe8;
    s = *(u8 *)&stcoli_hud_1fea;
    s = *(u8 *)&stcoli_fill_21feb;
    s = *(u8 *)&stcoli_hud_1fec;
    s = *(u8 *)&stcoli_hud_1ff0;
    s = *(u8 *)&stcoli_hud_1ff4;
    s = *(u8 *)&stcoli_hud_1ff8;
    s = *(u8 *)&stcoli_hud_1ffc;
    s = *(u8 *)&stcoli_hud_colors;
    s = *(u8 *)&stcoli_hud_colors2;
    s = *(u8 *)&stcoli_hud_width;
    s = *(u8 *)&stcoli_hud_height;
}
#pragma section code_type ".text"

  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const unsigned long *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 15.0f;
    s = 1.0f;
    s = 10.0f;
    s = 1.25f;
    s = 0.10000000149011612f;
    s = 0.8999999761581421f;
    s = 0.0006000000284984708f;
    s = 0.4000000059604645f;
    s = 0.75f;
    s = 70.0f;
    s = 0.5f;
    s = 36.0f;
    s = 16.0f;
    s = 45.0f;
    s = 0.0007999999797903001f;
    s = 18.0f;
    s = 50.0f;
}
static const unsigned long fzgx_pool_table3[1] = {0x00000000};
  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const unsigned long *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const unsigned long fzgx_pool_table5[52] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const unsigned long *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
    s = 80.0f;
    s = 60.0f;
}
static const unsigned long fzgx_pool_table7[1] = {0x00000000};
  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const unsigned long *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const unsigned long fzgx_pool_table9[2] = {0x00000000, 0xFFFFFF00};
  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const unsigned long *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 470.0f;
    s = 0.0625f;
    s = 14.0f;
    s = 127.0f;
    s = 0.25f;
}
static const unsigned long fzgx_pool_table11[3] = {0x03E8FED4, 0xFE70FE0C, 0xFE0CFE0C};
  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const unsigned long *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 10000.0f;
    s = 15000.0f;
    s = 9999.0f;
}
static const Color4 color174 = { 255, 255, 255, 0 };
#define fzgx_pool_table13 ((const unsigned long *)&color174)
  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const unsigned long *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
  /* fzgx-allow: S2 pool primer sink */
static const Color4 color178 = { 128, 128, 128, 0 };
#define fzgx_pool_table14 ((const unsigned long *)&color178)
  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 240.0f;
    s = 280.0f;
    s = 200.0f;
    s = 40.0f;
    s = 30.0f;
}
static const unsigned long fzgx_pool_table16[1] = {0x80808000};
  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */

 /* fzgx-allow: A1 measured pool bytes and bindings */

#pragma opt_common_subs on
s32 fn_1_2EBB8(u32 flags, u8 arg1) {
    Color4 col;
    s32 i;
    s32 count;
    f32 maxw;
    f32 w;
    f32 h;

    if (stcoli_cur_line != -1) {
        return 0;
    }
    if (arg1 == 0 && (stcoli_sub.flags & 0x800)) {
        fn_1_4068C(&stcoli_msg);
        stcoli_msg.name = fn_1_15BA78(fzgx_pool_native_lbl_1_data_5730_title);
        stcoli_msg.type = 2;
        stcoli_msg.state = 1;
        stcoli_sub.callback = fn_1_2C97C;
    }
    if (stcoli_sub.unk_13f6 == 0 && stcoli_sub.unk_5 == 1) {
        flags &= ~0x28;
    }
    if (stcoli_sub.flags & 0x4000000) {
        flags &= ~0x180;
    }
    stcoli_hud_flags = flags;
    stcoli_hud_1fe8 = 0;
    stcoli_hud_1fea = arg1;
    stcoli_hud_1fec = -2;
    stcoli_hud_1ff0 = 0;
    stcoli_hud_1ff4 = 0;
    stcoli_hud_1ff8 = 0.0f;
    stcoli_hud_1ffc = 0.0f;
    fzgx_pool_native_lbl_1_data_5730_unk_43c = 320.0f;
    fzgx_pool_native_lbl_1_data_5730_unk_440 = 240.0f;
    fzgx_pool_native_lbl_1_data_5730_unk_444 = 320.0f;
    fzgx_pool_native_lbl_1_data_5730_unk_448 = 280.0f;
    col = color174;
    {
        u32 j;
        for (j = 0; j < 10; j++) {
            stcoli_hud_colors[j] = col;
        }
    }
    stcoli_hud_colors2[0] = stcoli_hud_colors2[1] = color178;
    fn_1_49410();
    fn_1_495FC();
    fn_1_495C8(1);
    fn_1_49590(0.4f);
    fn_1_495B0(0x80000000);
    fn_1_494DC(42);
    fn_1_4955C(0.75f, 0.75f);

    count = 0;
    maxw = 0.0f;
    for (i = 14; i > 0; i--) {
        if (flags & (1 << (i - 1))) {
            stcoli_cur_line = i - 1;
            count++;
            w = fn_1_4B068(fn_1_15BA78(fzgx_pool_native_lbl_1_data_5730_names[i - 1]));
            if (maxw < w) {
                maxw = w;
            }
        }
    }
    if (maxw < 200.0f) {
        maxw = 200.0f;
    }
    stcoli_hud_width = 40.0f + maxw;
    h = 30.0f + (f32)(count * 24);
    stcoli_hud_height = h;
    fzgx_pool_native_lbl_1_data_5730_unk_440 -= (f32)(count * 10);
    return (s32)h;
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_2EBB8 */

/* fzgx:begin fn_1_38CF4 pool noprologue */
#include "types.h"

typedef struct {
    void *obj;
    u8 pad_4[0x8];
} fn_1_38CF4_Part;

typedef struct {
    u8 pad_0[0x328];
    s8 unk_328;
    u8 pad_329[0x338 - 0x329];
    fn_1_38CF4_Part parts[6];
    u8 pad_380[0x390 - 0x380];
    u32 flags;
    u8 pad_394[0x3B8 - 0x394];
    s16 unk_3B8;
} fn_1_38CF4_Driver;

typedef struct {
    u8 pad_0[0x3B8];
    s16 unk_3B8;
    u8 pad_3BA[0x440 - 0x3BA];
} fn_1_38CF4_Slot;

typedef struct {
    u32 flags;
    u8 pad_4;
    u8 unk_5;
    u8 pad_6[2];
    u8 unk_8;
    u8 pad_9[0x155 - 0x9];
    u8 unk_155;
    u8 pad_156[0x14B8 - 0x156];
} lbl_1_bss_3C30_t;

extern u8 lbl_1_bss_8B3A0[];
extern s16 lbl_1_data_5B86;

extern fn_1_38CF4_Driver *fn_1_86900(s8);
extern void fn_800713E0(void *, u32);
extern void fn_1_8019C(void *);
extern u32 fn_80008E84(u32);
extern void fn_1_12B3F8(void *, u32, u32, void *, void *, void *);
extern void fn_1_81408(fn_1_38CF4_Driver *, u8, u8);
extern void fn_1_A75DC(fn_1_38CF4_Driver *, s32);
extern void fn_1_1596DC(int);
extern void fn_1_48140(int);
extern void fn_1_412A0(u32);
extern void fn_1_A8F78(void);
extern u32 fn_1_30054(void);
extern s8 fn_1_5370(s8, s16);
extern void fn_1_FCF74(void);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 lbl_1_bss_3C00;
u32 lbl_1_bss_3C04_fill[11];
lbl_1_bss_3C30_t lbl_1_bss_3C30;
s16 lbl_1_bss_50E8;
u16 lbl_1_bss_50EA_fill;
u32 lbl_1_bss_50EC_fill[0x54];
u8 lbl_1_bss_523C[0x20];
u32 lbl_1_bss_525C_fill[0x67];
u8 *lbl_1_bss_53F8[0x22];
u32 lbl_1_bss_5480_fill[0x81C2];
u32 lbl_1_bss_25B88[4];
u32 lbl_1_bss_25B98_fill[0x2C];
s16 lbl_1_bss_25C48[0x2E];
u32 lbl_1_bss_25CA4[10];
u32 lbl_1_bss_25CCC;
u32 lbl_1_bss_25CD0[0x68];
s32 lbl_1_bss_25E70;
u32 lbl_1_bss_25E74_fill[0x37D];
u32 lbl_1_bss_26C68[2];
u8 lbl_1_bss_26C70[0x3B70];
fn_1_38CF4_Slot lbl_1_bss_2A7E0[51];
u32 lbl_1_bss_380A0_fill[0x48];
u8 lbl_1_bss_381C0[0x10];
u8 lbl_1_bss_381D0[0x20];
u32 lbl_1_bss_381F0;
u8 lbl_1_bss_381F4;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_1_bss_3C00;
    s = *(u8 *)&lbl_1_bss_3C04_fill;
    s = *(u8 *)&lbl_1_bss_3C30;
    s = *(u8 *)&lbl_1_bss_50E8;
    s = *(u8 *)&lbl_1_bss_50EA_fill;
    s = *(u8 *)&lbl_1_bss_50EC_fill;
    s = *(u8 *)&lbl_1_bss_523C;
    s = *(u8 *)&lbl_1_bss_525C_fill;
    s = *(u8 *)&lbl_1_bss_53F8;
    s = *(u8 *)&lbl_1_bss_5480_fill;
    s = *(u8 *)&lbl_1_bss_25B88;
    s = *(u8 *)&lbl_1_bss_25B98_fill;
    s = *(u8 *)&lbl_1_bss_25C48;
    s = *(u8 *)&lbl_1_bss_25CA4;
    s = *(u8 *)&lbl_1_bss_25CCC;
    s = *(u8 *)&lbl_1_bss_25CD0;
    s = *(u8 *)&lbl_1_bss_25E70;
    s = *(u8 *)&lbl_1_bss_25E74_fill;
    s = *(u8 *)&lbl_1_bss_26C68;
    s = *(u8 *)&lbl_1_bss_26C70;
    s = *(u8 *)&lbl_1_bss_2A7E0;
    s = *(u8 *)&lbl_1_bss_380A0_fill;
    s = *(u8 *)&lbl_1_bss_381C0;
    s = *(u8 *)&lbl_1_bss_381D0;
    s = *(u8 *)&lbl_1_bss_381F0;
    s = *(u8 *)&lbl_1_bss_381F4;
}
#pragma section code_type ".text"

void fn_1_38CF4(void) {
    s16 i;
    s16 k;
    s8 single;
    fn_1_38CF4_Driver *drv;
    void *obj;
    u32 save;
    s32 old;
    u32 word;
    u32 any;
    fn_1_38CF4_Driver * tmp_call6;
    void * obj_2;
    fn_1_38CF4_Driver * drv_2;

    single = (lbl_1_bss_3C30.unk_8 == 1);
    for (i = 0; i < lbl_1_bss_3C30.unk_8; i++) {
        if (lbl_1_bss_53F8[i] == NULL) {
            lbl_1_bss_25C48[i] = lbl_1_bss_8B3A0[0x9F + i];
        } else {
            lbl_1_bss_53F8[i][0xB] = lbl_1_bss_8B3A0[0x9F + i];
        }
    }
    if (lbl_1_bss_3C30.unk_5 == 2) {
        if (lbl_1_bss_53F8[0] == NULL) {
            lbl_1_bss_3C30.unk_155 = lbl_1_bss_25C48[0];
        } else {
            lbl_1_bss_3C30.unk_155 = lbl_1_bss_53F8[0][0xB];
        }
    }

    for (i = 0; i < 4; i++) {
        drv = fn_1_86900(i);
        if (drv != NULL && !(drv->flags & 0x04000000)) {
            lbl_1_bss_2A7E0[drv->unk_328].unk_3B8 = drv->unk_3B8;
            for (k = 0; k < 6; k++) {
                obj = drv->parts[k].obj;
                if (obj != NULL) {
                    fn_800713E0(obj, *(u32 *)((u8 *)drv + 0x37C + (drv->unk_3B8 % 4) * 4));
                    fn_1_8019C(obj);
                }
            }
        }
    }

    save = fn_80008E84(lbl_1_bss_25CCC);
    fn_1_12B3F8(lbl_1_bss_26C70, lbl_1_bss_25B88[0], lbl_1_bss_25CA4[0],
                lbl_1_bss_381C0, lbl_1_bss_381D0, &lbl_1_bss_381F0);
    fn_80008E84(save);

    for (i = 0; i < 4; i++) {
        tmp_call6 = fn_1_86900(i);
        drv_2 = tmp_call6;
        if (drv_2 != NULL) {
            if (lbl_1_bss_8B3A0[0x14 + ((i) << 5)] != (u8)(1 << drv_2->unk_3B8)) {
                if (drv_2->flags & 0x04000000) {
                    for (k = 0; k < 8; k++) {
                        if ((1 << k) == lbl_1_bss_8B3A0[0x14 + i * 0x20]) {
                            break;
                        }
                    }
                    drv_2->unk_3B8 = k;
                } else {
                    fn_1_81408(drv_2, 1 << drv_2->unk_3B8, lbl_1_bss_8B3A0[0x14 + i * 0x20] << (single ? 0 : 4));
                }
            }
            for (k = 0; k < 32; k++) {
                if ((1 << k) == lbl_1_bss_8B3A0[0x14 + i * 0x20]) {
                    break;
                }
            }
            fn_1_A75DC(drv_2, k);
            lbl_1_bss_523C[i] = 1 << drv_2->unk_3B8;
        }
    }

    fn_1_1596DC(2);
    fn_1_48140(0xA1);
    obj_2 = (void *)fn_80008E84(lbl_1_bss_25CCC);
    fn_1_412A0(1);
    if (single) {
        fn_1_48140(0x9B);
    } else {
        fn_1_48140(0x9D);
    }
    fn_1_48140(0x9A);
    fn_80008E84((u32)obj_2);
    fn_1_A8F78();
    if (lbl_1_bss_25E70 != 0) {
        fn_1_30054();
    }
    if (lbl_1_data_5B86 >= 40) {
        /* set bit 9 temporarily, sample bits 0/9, then restore it */
        old = lbl_1_bss_3C30.flags;
        word = old | 0x200;
        lbl_1_bss_3C30.flags = word;
        any = word & 0x201;
        lbl_1_bss_3C30.flags = word & ~0x200;
        lbl_1_bss_3C30.flags = (word & ~0x200) | (old & 0x200);
        lbl_1_bss_50E8 = (any != 0) + 39;
    }
    fn_1_5370(0, 0);
    fn_1_FCF74();
    if (lbl_1_bss_381F4 != 0) {
        lbl_1_bss_3C30.flags |= 0x100000;
    }
}
/* fzgx:end fn_1_38CF4 */

/* fzgx:begin fn_1_3FCD4 */
void fn_1_3FCD4(u32 mask) {
    if (mask == 0) {
        lbl_1_data_5B80 = 0xffffffff;
    } else {
        lbl_1_data_5B80 &= ~mask;
    }
}
/* fzgx:end fn_1_3FCD4 */
