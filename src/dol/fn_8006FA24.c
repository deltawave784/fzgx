#include "types.h"

extern void *lbl_8006D5A4(void *, void *, void *, f32);
extern void lbl_8006D668(void *);

typedef struct { f32 x, y, z, pad; } Vector;
typedef struct { Vector a, b, c; } Basis;

static inline void cross(Vector *a, Vector *b, Vector *out) {
    f32 ax;
    f32 ay;
    f32 az;
    f32 bx;
    f32 bz;
    f32 by;
    f32 x;
    f32 y;
    f32 z;
    ay = a->y;
    bz = b->z;
    az = a->z;
    bx = b->x;
    by = b->y;
    ax = a->x;
    x = ay * bz;
    y = az * bx;
    x -= az * by;
    z = ax * by;
    y -= ax * bz;
    z -= ay * bx;
    out->x = x;
    out->y = y;
    out->z = z;
}

void fn_8006FA24(Basis *a, Basis *b, Basis *out, f32 t) {
    lbl_8006D5A4(a, b, out, t);
    lbl_8006D5A4(&a->b, &b->b, &out->b, t);
    cross(&out->a, &out->b, &out->c);
    cross(&out->c, &out->a, &out->b);
    lbl_8006D668(&out->a);
    lbl_8006D668(&out->b);
    lbl_8006D668(&out->c);
}
