#include "types.h"

#pragma section sconst_type ".rodata" ".rodata" data_mode=far_abs

void fn_800531F0(f32 *v, f32 *window, s16 *out) {
    s32 n;
    f32 sum;
    s32 value;

    n = 32;
    do {
        sum = 0.0f;
        sum += window[0] * v[0];
        sum += window[1] * v[96];
        sum += window[2] * v[128];
        sum += window[3] * v[224];
        sum += window[4] * v[256];
        sum += window[5] * v[352];
        sum += window[6] * v[384];
        sum += window[7] * v[480];
        sum += window[8] * v[512];
        sum += window[9] * v[608];
        sum += window[10] * v[640];
        sum += window[11] * v[-288];
        sum += window[12] * v[-256];
        sum += window[13] * v[-160];
        sum += window[14] * v[-128];
        sum += window[15] * v[-32];
        window += 16;
        v++;

        if (sum > 2147483648.0f) {
            sum = 2147483648.0f;
        } else if (sum < -2147483648.0f) {
            sum = -2147483648.0f;
        }
        value = (s32)sum >> 16;
        *out++ = (s16)(f32)value;
    } while (--n != 0);
}
