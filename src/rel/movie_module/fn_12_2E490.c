#include "types.h"

struct fn_12_2E490_Arg0 {
    u8 pad_0[0x48];
    s32 unk_48;
    u8 pad_4C[4];
    s32 unk_50;
    u8 pad_54[0x910];
    s32 unk_964;
    u8 pad_968[0x5E8];
    s32 (*unk_F50)(struct fn_12_2E490_Arg0 *, s32 *, s32 *);
    volatile s32 unk_F54; /* Previous callback progress is sampled separately for the sentinel test and delta. */
    volatile s32 unk_F58; /* State is re-read while accumulating callback progress. */
    s32 unk_F5C;
};
struct fn_12_2E490_Arg1 { s32 unk_0; };
struct fn_12_2E490_Arg2 { s32 unk_0; };

static inline s32 valid(struct fn_12_2E490_Arg0 *arg0, struct fn_12_2E490_Arg1 *arg1, struct fn_12_2E490_Arg2 *arg2) {
    s32 v0 = arg0->unk_48;
    if (v0 != 4) {
    if (v0 != -4) {
    if (v0 != 6) {
    if (v0 != -6) {
        arg1->unk_0 = -1;
        arg2->unk_0 = 1;
        return 0;
    }
    }
    }
    }
    return 1;
}
static inline s32 active(struct fn_12_2E490_Arg0 *arg0) {
    if (arg0->unk_48 != 4) return 0;
    if (arg0->unk_50 != 0) return 0;
    if (arg0->unk_964 != 0) return 0;
    return 1;
}
s32 fn_12_2E490(struct fn_12_2E490_Arg0 *arg0, struct fn_12_2E490_Arg1 *arg1, struct fn_12_2E490_Arg2 *arg2) {
    s32 value;
    s32 other;
    if (!valid(arg0, arg1, arg2)) return 0;
    if (arg0->unk_F50 == 0) {
        arg1->unk_0 = -2;
        arg2->unk_0 = 1;
        return 0;
    }
    arg0->unk_F50(arg0, &value, &other);
    if (active(arg0) && arg0->unk_F54 != -5) {
        s32 previous;
        s32 accumulated;
        accumulated = arg0->unk_F58;
        previous = arg0->unk_F54;
        arg0->unk_F58 = accumulated + (value - previous);
    }
    arg0->unk_F54 = value;
    arg0->unk_F5C = other;
    arg1->unk_0 = arg0->unk_F58;
    arg2->unk_0 = arg0->unk_F5C;
}
