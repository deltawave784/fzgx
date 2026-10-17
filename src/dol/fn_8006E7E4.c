#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec4;

extern const f32 lbl_801A73D0;
extern const f32 lbl_801A73D4;
extern const f32 lbl_801A73D8;
extern f32 lbl_8006D188(s16);
extern f32 lbl_8006D0E8(f32);

#pragma opt_common_subs off
void fn_8006E7E4(Vec4 *out, Vec3 *axis, s16 angle) {
    f32 len2;
    f32 s;
    f32 tmp_call1;
    s32 a;

    len2 = axis->x * axis->x;
    len2 = axis->y * axis->y + len2;
    len2 = axis->z * axis->z + len2;
    if (len2 < lbl_801A73D0) {
        out->x = lbl_801A73D4;
        out->y = lbl_801A73D4;
        out->z = lbl_801A73D4;
        out->w = lbl_801A73D8;
    } else {
        a = angle;
        s = lbl_8006D188((s16)(a >> 1));
        tmp_call1 = lbl_8006D0E8(len2);
        s = tmp_call1 * s;
        out->x = axis->x * s;
        out->y = axis->y * s;
        out->z = axis->z * s;
        out->w = lbl_8006D188((s16)((s16)(a >> 1) + 0x4000));
    }
}
#pragma opt_common_subs reset

