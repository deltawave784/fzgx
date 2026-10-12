#include "types.h"

/* 8x8 separable transform: out = coef^T * in * coef */
void fn_12_4A38(f64 *in, f64 *out, f64 (*coef)[8]) {
    f64 tmp[64];
    s32 i;
    s32 j;
    s32 k;
    f64 sum;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            sum = 0.0;
            for (k = 0; k < 8; k++) {
                sum += coef[k][j] * in[i * 8 + k];
            }
            tmp[i * 8 + j] = sum;
        }
    }
    for (j = 0; j < 8; j++) {
        for (i = 0; i < 8; i++) {
            sum = 0.0;
            for (k = 0; k < 8; k++) {
                sum += coef[k][i] * tmp[k * 8 + j];
            }
            out[i * 8 + j] = sum;
        }
    }
}
