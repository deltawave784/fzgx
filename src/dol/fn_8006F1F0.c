#include "types.h"

struct fn_8006F1F0_Arg0 {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
};
struct fn_8006F1F0_Arg2 {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
};
extern const f32 lbl_801A73F0;
extern f32 lbl_8006D668(void *);
extern void lbl_8006D7DC(void *);
extern u32 lbl_801A6D00[2];
extern void lbl_8006DF44(void *);

static inline void cross(struct fn_8006F1F0_Arg0 *a, struct fn_8006F1F0_Arg0 *b, f32 *out) {
    f32 ax;
    f32 ay;
    f32 az;
    f32 bx;
    f32 bz;
    f32 by;
    f32 x;
    f32 y;
    f32 z;
    ay = a->unk_4;
    bz = b->unk_8;
    az = a->unk_8;
    bx = b->unk_0;
    by = b->unk_4;
    ax = a->unk_0;
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

void fn_8006F1F0(struct fn_8006F1F0_Arg0 *arg0, void *arg1, struct fn_8006F1F0_Arg2 *arg2, f32 arg3) {
    struct {
        f32 dir[3];
        f32 up[3];
        f32 right[3];
    } v;
    f32 *mtx;
    v.dir[0] = arg0->unk_0 - arg2->unk_0;
    v.dir[1] = arg0->unk_4 - arg2->unk_4;
    v.dir[2] = arg0->unk_8 - arg2->unk_8;
    if (lbl_801A73F0 == lbl_8006D668(v.dir)) {
        lbl_8006D7DC(arg0);
        return;
    }
    cross(arg1, (struct fn_8006F1F0_Arg0 *)v.dir, v.right);
    if (lbl_801A73F0 == lbl_8006D668(v.right)) {
        lbl_8006D7DC(arg0);
        return;
    }
    cross((struct fn_8006F1F0_Arg0 *)v.dir, (struct fn_8006F1F0_Arg0 *)v.right, v.up);
    if (lbl_801A73F0 == lbl_8006D668(v.up)) {
        lbl_8006D7DC(arg0);
        return;
    }
    mtx = (f32 *)lbl_801A6D00[0];
    mtx[0] = v.right[0];
    mtx[1] = v.up[0];
    mtx[2] = v.dir[0];
    mtx[3] = arg0->unk_0;
    mtx[4] = v.right[1];
    mtx[5] = v.up[1];
    mtx[6] = v.dir[1];
    mtx[7] = arg0->unk_4;
    mtx[8] = v.right[2];
    mtx[9] = v.up[2];
    mtx[10] = v.dir[2];
    mtx[11] = arg0->unk_8;
    lbl_8006DF44(mtx);
}
