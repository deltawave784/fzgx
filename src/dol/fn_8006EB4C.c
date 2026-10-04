#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Quat;

extern f64 fn_80088538(f64);  /* acos */
extern f64 fn_800883E8(f64);  /* sin */
extern const f32 lbl_801A73D4;
extern const f32 lbl_801A73D8;
extern const f64 lbl_801A73E8;

#pragma fp_contract off

/* Quaternion slerp: out = slerp(a, b, t). */
void fn_8006EB4C(Quat *out, Quat *a, Quat *b, f32 t) {
    f32 bx;
    f32 by;
    f32 bz;
    f32 bw;
    f32 scale0;
    f32 theta;
    f32 sinTheta;
    f32 scale1;
    f32 dot;
    f32 omt;

    dot = a->w * (bw = b->w) + (a->z * (bz = b->z) + (a->x * (bx = b->x) + a->y * (by = b->y)));
    if (dot < lbl_801A73D4) {
        dot = -dot;
        bx = -bx;
        by = -by;
        bz = -bz;
        bw = -bw;
    }
    if (lbl_801A73D8 - dot > lbl_801A73E8) {
        theta = fn_80088538(dot);
        sinTheta = fn_800883E8(theta);
        omt = lbl_801A73D8 - t;
        scale0 = fn_800883E8(omt * theta) / sinTheta;
        scale1 = fn_800883E8(t * theta) / sinTheta;
    } else {
        scale0 = lbl_801A73D8 - t;
        scale1 = t;
    }
    out->x = scale0 * a->x + scale1 * bx;
    out->y = scale0 * a->y + scale1 * by;
    out->z = scale0 * a->z + scale1 * bz;
    out->w = scale0 * a->w + scale1 * bw;
}
