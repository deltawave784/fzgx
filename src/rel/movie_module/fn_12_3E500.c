#include "types.h"

typedef struct Matrix3 {
    f32 m[9];
} Matrix3;

extern const f32 lbl_12_rodata_2E98;

void fn_12_3E500(const Matrix3 *a, Matrix3 *out) {
    struct { f32 value; } s;
    f32 det;
    f32 m0 = a->m[0], m1 = a->m[1], m2 = a->m[2];
    f32 m3 = a->m[3], m4 = a->m[4], m5 = a->m[5];
    f32 m6 = a->m[6], m7 = a->m[7], m8 = a->m[8];
    f32 c0 = m4 * m8 - (f32)(m5 * m7);
    f32 c1 = (f32)(m2 * m7) - m1 * m8;
    f32 c2 = m1 * m5 - m2 * m4;
    f32 c3 = (f32)(m5 * m6) - m3 * m8;
    f32 c4 = m0 * m8 - (f32)(m2 * m6);
    f32 c5 = -(m0 * m5 - m2 * m3);
    f32 c6 = m3 * m7 - (f32)(m4 * m6);
    f32 c7 = (f32)(m1 * m6) - m0 * m7;
    f32 c8 = m0 * m4 - m1 * m3;
    s.value = lbl_12_rodata_2E98;
    det = (m0 * m4 * m8 + m1 * m5 * m6 + m2 * m3 * m7) - (m0 * m5 * m7 + m1 * m3 * m8 + m2 * m4 * m6);
    out->m[0] = s.value * (c0 / det);
    out->m[1] = s.value * (c1 / det);
    out->m[2] = s.value * (c2 / det);
    out->m[3] = s.value * (c3 / det);
    out->m[4] = s.value * (c4 / det);
    out->m[5] = s.value * (c5 / det);
    out->m[6] = s.value * (c6 / det);
    out->m[7] = s.value * (c7 / det);
    out->m[8] = s.value * (c8 / det);
}
