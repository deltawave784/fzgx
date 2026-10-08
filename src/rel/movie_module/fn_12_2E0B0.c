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
void fn_12_2E0B0(s32 value, FnEntry *entry, s32 *result, s32 *out) {
 s32 hour_product;
 s32 product;
 s32 t;
 s32 minute_product;
 s32 sum;
 s32 b;
 s32 c;
 s32 e;
 s32 d;
 s32 a;
 a = entry->field_0c;
 c = entry->field_10;
 t = a / 10;
 e = entry->field_18;
 d = entry->field_14;
 t = t * 2;
 product = entry->field_08 * 215892;
 minute_product = c * 60;
 hour_product = a * 3598;
 sum = hour_product + t;
 sum = sum + minute_product;
 sum = product + sum;
 sum = sum + e;
 sum = d + sum;
 *result = sum * 1000;
 *out = value;
}
