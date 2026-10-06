#include "types.h"
extern f32 lbl_801A6648[4];
extern f32 lbl_801A664C[4];
#define lbl_801A7508 0.0
#define lbl_801A7510 3.141592653589793
#define lbl_801A7518 1.5707963267948966
#define lbl_801A7520 6.123233995736766e-17
#define lbl_801A7528 0.16666666666666666
#define lbl_801A7530 -0.3255658186224009
#define lbl_801A7538 0.20121253213486293
#define lbl_801A7540 -0.04005553450067941
#define lbl_801A7548 0.0007915349942898145
#define lbl_801A7550 3.479331075960212e-05
#define lbl_801A7558 1.0
#define lbl_801A7560 -2.403394911734414
#define lbl_801A7568 2.0209457602335057
#define lbl_801A7570 -0.6882839716054533
#define lbl_801A7578 0.07703815055590194
#define lbl_801A7580 0.5
#define lbl_801A7588 3.0
#define lbl_801A7590 2.0
extern double __frsqrte(double);
static inline double root(double x) {
    double y;
    if (x > 0.0) {
        y = __frsqrte(x);
        y = (0.5*y)*(3.0-x*(y*y));
        y = (0.5*y)*(3.0-x*(y*y));
        y = (0.5*y)*(3.0-x*(y*y));
        y = (0.5*y)*(3.0-x*(y*y));
        return x*y;
    } else if (0.0 == x) {
        return 0.0;
    } else if (x) {
        return lbl_801A6648[0];
    } else {
        return lbl_801A664C[0];
    }
}
double fn_8008596C(double x) {
    double z,p,q,r,w,s,c,df;
    s32 hx,ix;
    hx = ((s32*)&x)[0];
    ix = hx & 0x7fffffff;
    if (ix >= 0x3ff00000) {
        if (((ix-0x3ff00000) | ((u32*)&x)[1]) == 0) {
            if (hx > 0) return lbl_801A7508;
            else return lbl_801A7510;
        }
        return lbl_801A6648[0];
    }
    if (ix < 0x3fe00000) {
        if (ix <= 0x3c600000) return lbl_801A7518;
        z = x*x;
        p = z*(lbl_801A7528+z*(lbl_801A7530+z*(lbl_801A7538+z*(lbl_801A7540+z*(lbl_801A7548+z*lbl_801A7550)))));
        q = lbl_801A7558+z*(lbl_801A7560+z*(lbl_801A7568+z*(lbl_801A7570+z*lbl_801A7578)));
        r = p/q;
        return lbl_801A7518 - (x - (lbl_801A7520-x*r));
    } else if (hx < 0) {
        z = (lbl_801A7558+x)*lbl_801A7580;
        p = z*(lbl_801A7528+z*(lbl_801A7530+z*(lbl_801A7538+z*(lbl_801A7540+z*(lbl_801A7548+z*lbl_801A7550)))));
        q = lbl_801A7558+z*(lbl_801A7560+z*(lbl_801A7568+z*(lbl_801A7570+z*lbl_801A7578)));
        s = root(z);
        r = p/q;
        w = r*s-lbl_801A7520;
        return lbl_801A7510-lbl_801A7590*(s+w);
    } else {
        z = (lbl_801A7558-x)*lbl_801A7580;
        s = root(z);
        df = s;
        ((u32*)&df)[1] = 0;
        c = (z-df*df)/(s+df);
        p = z*(lbl_801A7528+z*(lbl_801A7530+z*(lbl_801A7538+z*(lbl_801A7540+z*(lbl_801A7548+z*lbl_801A7550)))));
        q = lbl_801A7558+z*(lbl_801A7560+z*(lbl_801A7568+z*(lbl_801A7570+z*lbl_801A7578)));
        r = p/q;
        w = r*s+c;
        return lbl_801A7590*(df+w);
    }
}
