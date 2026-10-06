#include "types.h"
extern const f64 lbl_801A7870;
extern const f64 lbl_801A7878;
extern const f64 lbl_801A7880;
extern const f64 lbl_801A7888;
extern const f64 lbl_801A7890;
extern const f64 lbl_801A7898;
extern f64 lbl_800955E0[13];
typedef union { f64 d; struct { u32 hi, lo; } w; } DB;
f64 fn_80087C44(f64 x, f64 y, s32 iy) {
    f64 t;
    DB zz, a, xx;
    f64 z, r, v, w, s;
    s32 ix, hx;
    xx.d = x;
    hx = xx.w.hi;
    ix = hx & 0x7fffffff;
    if (ix < 0x3e300000) {
        if ((s32)x == 0) {
            if ((ix | xx.w.lo | (iy + 1)) == 0) {
                x = __fabs(x);
                return lbl_801A7870 / x;
            }
            else if (iy == 1)
                return x;
            else
                return lbl_801A7878 / x;
        }
    }
    if (ix >= 0x3fe59428) {
        if (hx < 0) { xx.d = -xx.d; y = -y; }
        zz.d = lbl_801A7880 - xx.d;
        w = lbl_801A7888 - y;
        xx.d = zz.d + w;
        y = lbl_801A7890;
    }
    z = xx.d * xx.d;
    w = z * z;
    r = lbl_800955E0[1] + w * (lbl_800955E0[3] + w * (lbl_800955E0[5] + w * (lbl_800955E0[7] + w * (lbl_800955E0[9] + w * lbl_800955E0[11]))));
    v = z * (lbl_800955E0[2] + w * (lbl_800955E0[4] + w * (lbl_800955E0[6] + w * (lbl_800955E0[8] + w * (lbl_800955E0[10] + w * lbl_800955E0[12])))));
    s = z * xx.d;
    zz.d = z;
    r = y + s * (r + v);
    r = z * r + y;
    r += lbl_800955E0[0] * s;
    w = xx.d + r;
    if (ix >= 0x3fe59428) {
        v = (f64)iy;
        return (f64)(1 - ((hx >> 30) & 2)) * (v - lbl_801A7898 * (xx.d - (w * w / (w + v) - r)));
    }
    if (iy == 1) return w;
    zz.d = w;
    *(u32 *)((u8 *)&zz.d + 4) = 0;
    v = r - (zz.d - xx.d);
    t = lbl_801A7878 / w;
    a.d = t;
    *(u32 *)((u8 *)&a.d + 4) = 0;
    s = lbl_801A7870 + a.d * zz.d;
    return a.d + t * (s + a.d * v);
}
