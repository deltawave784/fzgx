#include "types.h"

typedef struct { u32 a, b, c, d; } V4;
extern const V4 lbl_12_rodata_A08;

void fn_12_2013C(u8 *arg0) {
    const V4 *src = &lbl_12_rodata_A08;
    V4 *dst = (V4 *)(arg0 + 0x34);
    *dst = *src;
}
