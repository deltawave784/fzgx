#include "types.h"

static inline void init_low(u8 *arg1, u8 *arg2, s32 midpoint) {
    s32 lv;
    s32 lo = midpoint;
    s32 acc;
    s32 j;
    lv = midpoint;
    for (; lo > 104; lo -= 3) {
        arg1[lo] = lv;
        arg2[lo] = lv;
        arg1[lo-1] = lv;
        arg2[lo-1] = lv;
        arg1[lo-2] = lv;
        arg2[lo-2] = lv;
        lv--;
    }
    acc = lo * lv;
    for (j = lo; j >= 0; j--) {
        s32 value = acc / lo;
        arg1[j] = value;
        arg2[j] = value;
        acc -= lv;
    }
}

static inline void init_high(u8 *arg1, u8 *arg2, s32 midpoint) {
    s32 start;
    s32 hv;
    s32 hi = midpoint;
    s32 val;
    s32 range;
    s32 delta;
    hv = midpoint;
    for (; hi < 152; hi += 3) {
        arg1[hi] = hv;
        arg2[hi] = hv;
        arg1[hi+1] = hv;
        arg2[hi+1] = hv;
        arg1[hi+2] = hv;
        arg2[hi+2] = hv;
        hv++;
    }
    delta = 255 - hv;
    range = 255 - hi;
    start = hi;
    for (; hi <= 255; hi++) {
        val = hv + delta * (hi - start) / range;
        arg1[hi] = val;
        arg2[hi] = val;
    }
}

void fn_12_3E688(u8 *arg0, u8 *arg1, u8 *arg2) {
    s32 n;
    s32 i = 0;
    s32 v = 0;
    s32 j;

    while (i < 16) {
        arg0[i++] = v++;
        arg0[i++] = v;
        v += 2;
    }
    for (; i < 176; i += 2) {
        arg0[i] = v;
        arg0[i + 1] = v;
        v++;
    }
    for (; i < 192; i++) {
        arg0[i] = v;
        v++;
    }
    for (; i < 256; i++) {
        arg0[i] = v < 255 ? v : 255;
        v += 2;
    }
    init_low(arg1, arg2, 128);
    init_high(arg1, arg2, 128);

}
