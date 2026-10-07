#include "types.h"

struct Vec { f32 x; f32 y; f32 z; };
extern u32 lbl_801A6D00[2];
extern void *lbl_8006D5A4(void *, void *, void *, f32);
extern f32 lbl_8006D668(void *);

static inline void cross(struct Vec *a, struct Vec *b, f32 *out) {
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
    out[0] = x;
    out[1] = y;
    out[2] = z;
}

void fn_8006FB20(void *arg0, f32 arg1) {
    f32 *mtx = (f32 *)lbl_801A6D00[0];
    lbl_8006D5A4(mtx, arg0, mtx, arg1);
    lbl_8006D5A4(mtx + 4, (f32 *)arg0 + 4, mtx + 4, arg1);
    cross((struct Vec *)mtx, (struct Vec *)(mtx + 4), mtx + 8);
    cross((struct Vec *)(mtx + 8), (struct Vec *)mtx, mtx + 4);
    lbl_8006D668(mtx);
    lbl_8006D668(mtx + 4);
    lbl_8006D668(mtx + 8);
}
