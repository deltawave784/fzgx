#include "types.h"

typedef struct FnEntry {
    u8 padding[8];
    s32 field_08;
    s32 field_0c;
    s32 field_10;
    s32 field_14;
    s32 field_18;
} FnEntry;

#pragma opt_propagation off
void fn_12_2E1A0(s32 value, FnEntry *entry, s32 *result, s32 *out) {
    s32 hour_product;
    s32 product;
    s32 a;
    s32 minute_product;
    s32 sum;
    s32 days;
    s32 m;
    s32 s;
    s32 ms;
    s32 h;

    h = entry->field_0c;
    m = entry->field_10;
    a = h / 10;
    s = entry->field_18;
    ms = entry->field_14;
    a = a * 2;
    product = entry->field_08 * 86292;
    minute_product = m * 24;
    hour_product = h * 1438;
    sum = hour_product + a;
    sum = sum + minute_product;
    sum = product + sum;
    sum = sum + s;
    sum = ms + sum;
    *result = sum * 1000;
    *out = value;
}
