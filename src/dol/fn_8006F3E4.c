#include "types.h"

extern void lbl_8006DAEC(void *arg0, void *arg1, void *arg2);
extern const f32 lbl_801A73F0;
extern const f32 lbl_801A73F4;
extern const f32 lbl_801A73F8;
extern void lbl_8006E1C0(void *arg0, void *arg1);
extern s16 lbl_8006D24C(f32 arg0, f32 arg1);
extern f32 lbl_8006D0B4(f32 arg0);
extern void lbl_8006D8D8(s16 arg0);
extern void mathutil_mtxA_rotate_x(s16 arg0);
extern void fn_8006E2B0(void *arg0, void *arg1);
extern void lbl_8006DB30(void);

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    Vec3 up;
    Vec3 dir;
} UpDir;

#pragma opt_dead_assignments off
void fn_8006F3E4(s16 *arg0, s16 *arg1, s16 *arg2) {
    UpDir v;

    lbl_8006DAEC(arg0, arg1, arg2);

    v.up.x = lbl_801A73F0;
    v.up.y = lbl_801A73F4;
    v.up.z = lbl_801A73F0;
    /* negated third column of the current matrix (locked cache) */
    {
        f32 a = *(f32 *)(0xE0000000 + 0x08) * lbl_801A73F8;
        f32 b = *(f32 *)(0xE0000000 + 0x18) * lbl_801A73F8;
        f32 c = *(f32 *)(0xE0000000 + 0x28) * lbl_801A73F8;
        v.dir.x = a;
        v.dir.y = b;
        v.dir.z = c;
    }

    lbl_8006E1C0(&v.up, &v.up);

    {
        f32 z;
        f32 x;
        f32 magnitude;

        x = v.dir.x;
        z = v.dir.z;
        magnitude = x * x;
        magnitude += z * z;
        *arg1 = lbl_8006D24C(v.dir.y, lbl_8006D0B4(magnitude));
    }
    *arg0 = lbl_8006D24C(v.dir.x, v.dir.z) - 0x8000;

    lbl_8006D8D8(*arg0);
    mathutil_mtxA_rotate_x(*arg1);

    fn_8006E2B0(&v.up, &v.up);
    *arg2 = -lbl_8006D24C(v.up.x, v.up.y);

    lbl_8006DB30();
}
#pragma opt_dead_assignments reset
