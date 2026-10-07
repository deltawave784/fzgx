#include "types.h"

typedef struct { u32 w[4]; } Vec16;

extern const Vec16 lbl_12_rodata_928;

void fn_12_E0C8(Vec16 *dst) {
    *dst = lbl_12_rodata_928;
}
