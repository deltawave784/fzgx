#include "types.h"
typedef struct Sig_fn_12_23410_MovieState {
    u8 unk_00; u8 unk_01; u8 pad_02[2];
    u32 unk_04; void *unk_08; void *unk_0c;
    s32 unk_10; s32 unk_14; s32 unk_18;
    u32 unk_1c; u32 unk_20; u32 unk_24;
    u8 unk_28; u8 pad_29[3]; u32 unk_2c; u8 pad_30[16];
} Sig_fn_12_23410_MovieState;
struct Sig_fn_12_215F4_fn_12_215F4_Arg2 { u32 unk_0; };
extern u32 fn_12_215F4(void *, u32, struct Sig_fn_12_215F4_fn_12_215F4_Arg2 *);
extern u32 lbl_12_rodata_A18;
extern u8 lbl_12_bss_7250[];
extern void *memcpy(void *, const void *, u32);
#pragma use_lmw_stmw on
static inline s32 scan_movie(u8 *p, s32 count, Sig_fn_12_23410_MovieState *arg2) {
    struct Sig_fn_12_215F4_fn_12_215F4_Arg2 loc;
    while(count > 0) {
        if ((s32)fn_12_215F4(p, count, &loc) != 0) {
            arg2->unk_0c = &lbl_12_rodata_A18;
            arg2->unk_28 = p[7];
            arg2->unk_2c = (p[8] << 24) | (p[9] << 16) | (p[10] << 8) | p[11];
            return 1;
        }
        p += 4;
        count -= 4;
    }
    return 0;
}
static inline s32 copy_scan(u8 *source, s32 length, Sig_fn_12_23410_MovieState *state) {
    s32 count = 2048;
    if (length < 2048) count = length;
    memcpy(lbl_12_bss_7250, source, count);
    return scan_movie(lbl_12_bss_7250, count, state);
}
s32 fn_12_23410(u8 *arg0, s32 arg1, Sig_fn_12_23410_MovieState *arg2, u32 arg3) {
    if (copy_scan(arg0, arg1, arg2)) return 1;
    if (copy_scan(arg0 + 2, arg1 - 2, arg2)) return 1;
    if (copy_scan(arg0 + 1, arg1 - 1, arg2)) return 1;
    if (copy_scan(arg0 + 3, arg1 - 3, arg2)) return 1;
    return 0;
}
