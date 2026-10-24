#include "types.h"

typedef struct Fn8006BC84Data {
    u8 _pad[0xf0];
    u32 *header;
    void *items[64];
} Fn8006BC84Data;

typedef union Fn8006BC84Handle {
    u32 value;
    struct {
        u32 upper : 26;
        u32 index : 6;
    } bits;
} Fn8006BC84Handle;

extern volatile u32 lbl_801A6C90; /* Retail reloads this cursor after storing it. */
extern volatile u32 lbl_801A6C94; /* Retail reads the generation only after finding a free slot. */

#pragma opt_propagation off
static inline u32 fn_8006BC84Index(u32 value, u32 index) {
    return (index & 63u) | (value & ~63u);
}
#pragma opt_propagation on

s32 fn_8006BC84(Fn8006BC84Data *data) {
    u32 result;
    struct { u32 value; } start;
    u32 i;
    u32 index;
    u32 *header;
    start.value = lbl_801A6C90;
    result = -1;
    for (i = 0; i < 64; i++) {
        index = (i + start.value) & 63;
        if (data->items[index] == 0) {
            lbl_801A6C90 = index + 1;
            lbl_801A6C90 &= 63;
            /* Retail loads the header pointer before reading the volatile generation. */
            header = *(u32 *volatile *)&data->header;
            result = (header[0] << 16) | ((lbl_801A6C94 & 255) << 8);
            result = fn_8006BC84Index(result, index);
            break;
        }
    }
    return result;
}
