#include "types.h"
typedef struct Sig_fn_12_2E6AC_MovieModuleState Sig_fn_12_2E6AC_MovieModuleState;
typedef s32 (*fn_12_2EBAC_Fn0)(Sig_fn_12_2E6AC_MovieModuleState *, s32 *, s32 *);
struct Sig_fn_12_2E6AC_MovieModuleState {
    u8 padding[0x48];
    s32 state;
    u8 padding_4c[0xc74];
    fn_12_2EBAC_Fn0 callbacks[16];
};
extern u32 lbl_12_bss_7C64[137];
extern s32 fn_12_2E6AC(Sig_fn_12_2E6AC_MovieModuleState *, s32 *, s32 *);
extern u32 fn_12_2D73C(u8 *, int);
extern void fn_12_24950(s32 *);
extern void fn_12_24970(s32 *);

static inline int active(u8 *v3) {
    if (*(s32 *)(v3 + 72) != 4) return 0;
    if (*(s32 *)(v3 + 80) != 0) return 0;
    if (*(s32 *)(v3 + 2404) != 0) return 0;
    return 1;
}
static inline int active2(u8 *v3) {
    if (*(s32 *)(v3 + 3912) == -1) return 0;
    if (*(s32 *)(v3 + 76) != 4) return 0;
    return 1;
}
void fn_12_2EBAC(void) {
    s32 v1;
    u8 *v3;
    s32 loc_10;
    s32 loc_C;
    s32 loc_8;
    u32 *v2 = lbl_12_bss_7C64;
    struct { fn_12_2EBAC_Fn0 value; } v5;
    v2[0x1b0/4]++;
    for (v1 = 0; v1 < 8; v1++) {
        v3 = ((u8 **)((u8 *)v2 + 0x204))[v1];
        if (v3 != 0) {
            if (active(v3)) {
                *(u32 *)(v3 + 3876) += *(u32 *)(v3 + 3880);
            }
            if (active2(v3)) {
                *(u32 *)(v3 + 3912) += *(u32 *)(v3 + 3880);
            }
            if ((s32)fn_12_2D73C(v3, 71) == 1) {
                fn_12_24970(&loc_8);
                v5.value = ((Sig_fn_12_2E6AC_MovieModuleState *)v3)->callbacks[fn_12_2D73C(v3, 15)];
                if (v5.value == 0) v5.value = fn_12_2E6AC;
                v5.value((Sig_fn_12_2E6AC_MovieModuleState *)v3, &loc_C, &loc_10);
                fn_12_24950(&loc_8);
                if (*(s32 *)(v3 + 3848) != loc_C || *(s32 *)(v3 + 3852) != loc_10) {
                    if ((s32)fn_12_2D73C(v3, 71) == 1) {
                        *(u32 *)(v3 + 3916) = *(u32 *)(v3 + 3876);
                    } else {
                        *(u32 *)(v3 + 3916) = *(u32 *)(v3 + 3928);
                    }
                    *(s32 *)(v3 + 3848) = loc_C;
                    *(s32 *)(v3 + 3852) = loc_10;
                }
                *(u32 *)(v3 + 68) = 1;
            }
        }
    }
}
