#include "types.h"

typedef struct Sig_fn_12_2E6AC_MovieModuleState {
    u8 padding[0x48];
    s32 state;
} Sig_fn_12_2E6AC_MovieModuleState;
struct Sig_fn_12_2E63C_fn_12_2E63C_Arg0 {
    u8 pad_0[0x48];
    u32 unk_48;
};
struct Sig_fn_12_2E63C_fn_12_2E63C_Arg1 {
    u32 unk_0;
};
struct Sig_fn_12_2E63C_fn_12_2E63C_Arg2 {
    u32 unk_0;
};
struct Sig_fn_12_2E5E4_fn_12_2E5E4_Arg0 {
    u8 pad_0[0x48];
    u32 unk_48;
};
struct Sig_fn_12_2E5E4_fn_12_2E5E4_Arg1 {
    u32 unk_0;
};
struct Sig_fn_12_2E5E4_fn_12_2E5E4_Arg2 {
    u32 unk_0;
};

extern s32 fn_12_2E5E4(struct Sig_fn_12_2E5E4_fn_12_2E5E4_Arg0 *, struct Sig_fn_12_2E5E4_fn_12_2E5E4_Arg1 *, struct Sig_fn_12_2E5E4_fn_12_2E5E4_Arg2 *);
extern s32 fn_12_2E63C(struct Sig_fn_12_2E63C_fn_12_2E63C_Arg0 *, struct Sig_fn_12_2E63C_fn_12_2E63C_Arg1 *, struct Sig_fn_12_2E63C_fn_12_2E63C_Arg2 *, u32);
extern s32 fn_12_2E6AC(Sig_fn_12_2E6AC_MovieModuleState *, s32 *, s32 *);
extern u32 fn_12_2E490();

/* Running statistic: eight sample slots, a current value and a valid flag. */
typedef struct MovieStat {
    s32 samples[8];
    s32 value;
    s32 valid;
} MovieStat;

typedef struct MovieHandlers {
    u8 pad_0[0xCC0];
    void *open;
    void *read;
    s32 unk_CC8;
    void *seek;
    s32 unk_CD0;
    void *close;
} MovieHandlers;

typedef struct MovieStatus {
    u8 pad_0[0x18];
    s32 unk_18;
    MovieStat stat_1C;
    MovieStat stat_44;
    MovieStat stat_6C;
    MovieStat stat_94;
    MovieStat stat_BC;
    MovieStat stat_E4;
    s32 unk_10C;
    s32 unk_110;
    s32 unk_114;
    s32 unk_118;
    s32 unk_11C;
    s32 unk_120;
    s32 unk_124;
    s32 history_a[32];
    s32 unk_1A8;
    s32 unk_1AC;
    s32 unk_1B0;
    s32 unk_1B4;
    s32 history_b[32];
    s32 unk_238;
    s32 unk_23C;
    s32 unk_240;
    s32 unk_244;
    s32 unk_248;
    s32 unk_24C;
    s32 unk_250;
    s32 unk_254;
    s32 unk_258;
    s32 unk_25C;
    s32 unk_260;
    s32 unk_264;
    s32 unk_268;
    s32 unk_26C;
    s32 unk_270;
    s32 unk_274;
    s32 unk_278;
    f32 unk_27C;
    s32 unk_280;
    f32 unk_284;
    s32 unk_288;
    s32 unk_28C;
    s32 unk_290;
    s32 unk_294;
    s32 unk_298;
    s32 unk_29C;
} MovieStatus;

void fn_12_2EE7C(MovieHandlers *handlers, MovieStatus *status) {
    s32 i;

    handlers->open = (void *)fn_12_2E6AC;
    handlers->read = (void *)fn_12_2E63C;
    handlers->unk_CC8 = 0;
    handlers->seek = (void *)fn_12_2E5E4;
    handlers->unk_CD0 = 0;
    handlers->close = (void *)fn_12_2E490;

    status->unk_18 = 0;

    status->stat_94.samples[0] = 0;
    status->stat_94.samples[1] = 0;
    status->stat_94.samples[2] = 0;
    status->stat_94.samples[3] = 0;
    status->stat_94.samples[4] = 0;
    status->stat_94.samples[5] = 0;
    status->stat_94.samples[6] = 0;
    status->stat_94.samples[7] = 0;
    status->stat_94.value = 0;
    status->stat_94.valid = 1;

    status->stat_1C.samples[0] = 0;
    status->stat_1C.samples[1] = 0;
    status->stat_1C.samples[2] = 0;
    status->stat_1C.samples[3] = 0;
    status->stat_1C.samples[4] = 0;
    status->stat_1C.samples[5] = 0;
    status->stat_1C.samples[6] = 0;
    status->stat_1C.samples[7] = 0;
    status->stat_1C.value = 0x7fffffff;
    status->stat_1C.valid = 1;

    status->stat_44.samples[0] = 0;
    status->stat_44.samples[1] = 0;
    status->stat_44.samples[2] = 0;
    status->stat_44.samples[3] = 0;
    status->stat_44.samples[4] = 0;
    status->stat_44.samples[5] = 0;
    status->stat_44.samples[6] = 0;
    status->stat_44.samples[7] = 0;
    status->stat_44.value = -1;
    status->stat_44.valid = 1;

    status->stat_6C.samples[0] = 0;
    status->stat_6C.samples[1] = 0;
    status->stat_6C.samples[2] = 0;
    status->stat_6C.samples[3] = 0;
    status->stat_6C.samples[4] = 0;
    status->stat_6C.samples[5] = 0;
    status->stat_6C.samples[6] = 0;
    status->stat_6C.samples[7] = 0;
    status->stat_6C.value = -1;
    status->stat_6C.valid = 1;

    status->stat_BC.samples[0] = 0;
    status->stat_BC.samples[1] = 0;
    status->stat_BC.samples[2] = 0;
    status->stat_BC.samples[3] = 0;
    status->stat_BC.samples[4] = 0;
    status->stat_BC.samples[5] = 0;
    status->stat_BC.samples[6] = 0;
    status->stat_BC.samples[7] = 0;
    status->stat_BC.value = -1;
    status->stat_BC.valid = 1;

    status->stat_E4.samples[0] = 0;
    status->stat_E4.samples[1] = 0;
    status->stat_E4.samples[2] = 0;
    status->stat_E4.samples[3] = 0;
    status->stat_E4.samples[4] = 0;
    status->stat_E4.samples[5] = 0;
    status->stat_E4.samples[6] = 0;
    status->stat_E4.samples[7] = 0;
    status->stat_E4.value = 0x7fffffff;
    status->stat_E4.valid = 1;

    status->unk_10C = 0;
    status->unk_110 = 0;
    status->unk_114 = -1;
    status->unk_118 = -1;
    status->unk_11C = 0;
    status->unk_120 = 0;
    status->unk_124 = 0;
    for (i = 0; i < 32; i++) {
        status->history_a[i] = 0;
    }
    status->unk_1A8 = 1;
    status->unk_1AC = 0;
    status->unk_1B0 = 0;
    status->unk_1B4 = 0;
    for (i = 0; i < 32; i++) {
        status->history_b[i] = 0;
    }
    status->unk_238 = -5;
    status->unk_23C = 1;
    status->unk_240 = -5;
    status->unk_244 = 1;
    status->unk_248 = -5;
    status->unk_24C = 1;
    status->unk_250 = -5;
    status->unk_254 = 0x7fffffff;
    status->unk_258 = 0;
    status->unk_25C = 0x7fffffff;
    status->unk_260 = 0;
    status->unk_264 = 0;
    status->unk_268 = 1000;
    status->unk_26C = 0;
    status->unk_270 = 0;
    status->unk_274 = 1;
    status->unk_278 = 100;
    status->unk_27C = -1.0f;
    status->unk_280 = 0;
    status->unk_284 = -1.0f;
    status->unk_288 = -1;
    status->unk_28C = status->unk_264;
    status->unk_290 = 0;
    status->unk_294 = -5;
    status->unk_298 = 0;
    status->unk_29C = 1;
}
