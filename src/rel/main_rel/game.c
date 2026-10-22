#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/game.h"
#include "font.h"
#include "game/main_rel/game_types.h"

extern void fn_1_451E4(void);
extern void fn_1_D3214(void);
extern void fn_8001AF64(void);
extern s32 fn_1_467F4(void);
extern s32 fn_1_13018(void);
extern u32 lbl_801A6CE0;
extern u32 lbl_1_bss_38454;
extern u32 fn_80070DE0(u32 arg0);
extern void fn_1_40F54(void *arg0);
extern void *fn_1_D3884(u8 *arg0);
extern void *fn_1_D358C(u8 *arg0, void *arg1);
extern int sprintf(char *s, const char *format, ...);
extern int fn_80016DF8(char *buffer);
extern void fn_1_412A0(u32 index);
extern s8 lbl_1_bss_26B5C[30];
extern u8* fn_1_36AD0(void);
extern u32 fn_1_34AC0(void *, u32, u32, u32);
extern void fn_1_8001C(void);
extern void fn_1_12AB38(void *arg0);
extern void fn_1_465D0(char *value, u32 flag);
extern void* fn_1_7F518(s16 car_type, void* car, s32 initialize);
extern u32 fn_1_435C(u32 value);
extern void fn_1_4310(u32 arg0);
extern void fn_1_8616C(void);
extern u32 fn_1_A11EC(void);
extern void fn_1_D0790(void);
extern u32 fn_1_101C0(void);
extern void fn_1_A1588(u32 arg0, u32 arg1);
extern void fn_1_48004(s32 index, s32 image);
extern u32 ghost_test_record_flag0(s32 arg);
extern u32 fn_1_F9D44(u32 arg);
extern u8 fn_1_F8C50(s32 arg0);
extern void fn_1_2DB50(void);
extern void fn_1_3F8C(void *, void *, Obj_1_bss_5138 *, int);
extern void fn_1_2D888(void);
extern void fn_1_2D524(void);
extern FontDrawPacket lbl_1_rodata_26F8;
extern void fn_1_50A90(FontDrawPacket *packet, s32 w, s32 h, s32 clipW, s32 clipH);
extern void fn_1_49514(u32 *value);
extern void fn_1_49614(void);
extern u32 lbl_801A63C0;
extern void fn_1_40BE4(void);
extern void fn_1_41134(void *unused, char *value);
extern void fn_1_12F308(void);
extern int fn_1_4C10(void);
extern u32 fn_1_12F358(u32);
extern void fn_1_4A00(s32 fadeIn, u8 steps, u32 arg);
extern int fn_1_402D4(void);
extern void fn_1_A2D84(u32 arg0);
extern void fn_1_15E330(s32 index, u32 value, void *arg);
extern void fn_1_15E5E4(s32 index, void *arg);
extern void fn_1_15E688(s32 index, u32 value, u8 state, void *arg);
extern void fn_1_15E3E0(s32 index, u32 value);
extern void fn_1_15E434(u32 value);
extern void fn_1_15E540(s32 index, void *arg);
extern void fn_1_CB404(u8 value);
extern void fn_1_D07C4(u32 arg0, u32 arg1);
extern u32 lbl_1_bss_25B84;
extern u32 OSGetTick(void);
extern void fn_1_A0978(void);
extern void fn_1_35174(void);
extern s32 fn_1_3EFA8(void);
extern u16 lbl_1_bss_26B7A[3];
extern u16 lbl_1_bss_26300;
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_1_817C0(void);
extern u32 lbl_1_bss_381FC;
extern void fn_1_EB080(int mode);
extern s64 OSGetTime(void);
extern void fn_1_5370(u32 arg0, u32 arg1);
extern void fn_1_15E27C(void);
extern void fn_1_4811C(int arg);
extern void fn_1_A8F78(void);
extern u8 lbl_1_bss_262F4;
extern u32 lbl_1_bss_25E74[7];
extern u8 lbl_1_bss_3C10;
extern void fn_1_36330(void);
extern void fn_1_36B10(void);
extern void fn_1_3C98(void);
extern void fn_1_37AA8(void);
extern void fn_1_37E98(void);
extern f32 lbl_1_bss_26304[4];
extern u8 lbl_1_bss_26B04[20];
extern u8 lbl_1_bss_26314[2032];
extern s16 fn_1_12EF24(s16 row, s16 column);
extern u8 lbl_1_bss_523C[32];
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 fn_1_46C60(void);
extern u32 lbl_1_bss_26C2C[2];
extern u32 lbl_1_bss_262F8[2];
extern u16 lbl_1_bss_26C68[35526];
extern u32 lbl_1_bss_3C08[2];
extern u32 fn_800075AC(u32, u32, u32);
extern u32 fn_1_FA070(void);
extern u32 fn_1_FA180(u8 a, u8 b);
extern u32 fn_1_F9FEC(void);
extern void fn_1_A2DC4(u32 arg0);
extern u8 lbl_1_bss_26B54[8];
extern u32 fn_1_40EE4(void);
extern u32 lbl_801A63D0;
extern u32 lbl_1_bss_26C34[9];
extern u8 lbl_1_bss_38218[568];
extern u32 fn_1_4060(void);
extern void ARQPostRequest(u8 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6, u32 arg7);
extern u32 GXGetTexBufferSize(u32, u32, u32, u32, u32);
extern u32 lbl_1_bss_26B4C;
extern u8 lbl_1_bss_25E90[8];
extern s32 fn_1_48B0(u32 arg0, u32 arg1);
extern void fn_800711A8(Obj_1_bss_38458_Target *target);
extern void fn_80071718(u32 value);
extern void fn_1_411D4(u32 index, char *value);
extern size_t strlen(const char *str);
extern int fn_80083BCC(const char *s1, const char *s2);
extern u8 lbl_1_A9011300;
extern u8 lbl_1_A9011100;
extern u8 lbl_1_A9011000;
extern u16 lbl_1_bss_25B80;
extern u8 lbl_1_bss_26B1D;
extern void fn_1_15E260(s32 index);

/* fzgx:begin fn_1_2FDBC pool noprologue */
#include "types.h"
#include "rel/main_rel/game.h"

/* The retail TU addresses its .bss objects off one base (lbl_1_bss_3C00): define the
 * cluster this function touches in retail order so the section base is reproduced. */
typedef struct GameFlags_3C30 {
    u32 flags;
    u8 pad_4;
    u8 unk_5;
    u8 pad_6[0x17C2];
} GameFlags_3C30;

u8 fzgx_obj_lbl_1_bss_3C00[4];
u8 fzgx_bss_padding_3C04[0x26];
s16 fzgx_obj_lbl_1_bss_3C2A;
u32 fzgx_obj_lbl_1_bss_3C2C;
GameFlags_3C30 fzgx_obj_lbl_1_bss_3C30;
u8 *fzgx_obj_lbl_1_bss_53F8;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_order(void) {
    volatile u32 sink;  /* fzgx-allow: S2 section-order primer sink */
    sink = fzgx_obj_lbl_1_bss_3C00[0];
    sink = fzgx_bss_padding_3C04[0];
    sink = fzgx_obj_lbl_1_bss_3C2A;
    sink = fzgx_obj_lbl_1_bss_3C2C;
    sink = fzgx_obj_lbl_1_bss_3C30.flags;
    sink = (u32)fzgx_obj_lbl_1_bss_53F8;
}
static const unsigned long fzgx_pool_table1[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const unsigned long *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 15.0f;
    s = 1.0f;
    s = 10.0f;
    s = 1.25f;
    s = 0.10000000149011612f;
    s = 0.8999999761581421f;
    s = 0.0006000000284984708f;
    s = 0.4000000059604645f;
    s = 0.75f;
    s = 70.0f;
    s = 0.5f;
    s = 36.0f;
    s = 16.0f;
    s = 45.0f;
    s = 0.0007999999797903001f;
    s = 18.0f;
    s = 50.0f;
}
static const unsigned long fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const unsigned long *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const unsigned long fzgx_pool_table5[52] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const unsigned long *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
    s = 80.0f;
    s = 60.0f;
}
static const unsigned long fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const unsigned long *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const unsigned long fzgx_pool_table9[2] = {0x00000000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const unsigned long *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 470.0f;
    s = 0.0625f;
    s = 14.0f;
    s = 127.0f;
    s = 0.25f;
}
static const unsigned long fzgx_pool_table11[3] = {0x03E8FED4, 0xFE70FE0C, 0xFE0CFE0C};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const unsigned long *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 10000.0f;
    s = 15000.0f;
    s = 9999.0f;
}
static const unsigned long fzgx_pool_table13[2] = {0xFFFFFF00, 0x80808000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const unsigned long *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 240.0f;
    s = 280.0f;
    s = 200.0f;
    s = 40.0f;
    s = 30.0f;
}
static const unsigned long fzgx_pool_table15[8] = {0x80808000, 0xFFFFFF00, 0x80808000, 0xFFFFFF00, 0xFFFFFF00, 0x00000000, 0x00000000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const unsigned long *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.05000000074505806f;
    s = 0.15000000596046448f;
    s = 0.07999999821186066f;
    s = 2.0f;
    s = 4.0f;
    s = 255.0f;
    s = 1.100000023841858f;
    s = 38.0f;
    s = 20.0f;
    s = 180.0f;
    s = 3.0f;
    s = 0.00019999999494757503f;
    s = 100.0f;
    s = 75.0f;
    s = 0.00039999998989515007f;
    s = 150.0f;
}
static const unsigned long fzgx_pool_table17[7] = {0xFFF200FF, 0xFFF200FF, 0x80808080, 0xFFFFFF96, 0xFFF200FF, 0xFFF200FF, 0xFFFFFF96};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const unsigned long *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.009999999776482582f;
    s = 1000.0f;
    d = 20.0;
}
#pragma section code_type ".text"

typedef struct {
    u8 pad_0[0x8B4];
    u8 unk_8B4;
    u8 unk_8B5;
    u16 unk_8B6;
} Global_801A66CC;

typedef struct {
    u8 pad_0[0x1E0];
    u8 unk_1E0;
    u8 unk_1E1;
    u16 unk_1E2;
    u32 unk_1E4;
} Record_49C;

typedef struct {
    u32 flags;
    u8 pad_4[2];
    s16 unk_6;
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[4];
    f32 unk_14;
    u8 pad_18[0x14];
    f32 unk_2C;
    u8 pad_30[0x1F0];
    f32 unk_220;
    u8 pad_224[8];
    f32 unk_22C;
    u8 pad_230[0x244];
    s8 unk_474;
    u8 pad_475[0x27];
    Record_49C *unk_49C;
} Racer_2FDBC;

extern Global_801A66CC *lbl_801A66CC;
extern s32 fn_1_3EFA8(void);
extern u32 *fn_1_82EDC(s16, s16, u32 *);
extern void *fn_1_22B10(void *, f32);

void fn_1_2FDBC(Racer_2FDBC *racer) {
    s32 changed = 0;
    s32 total;
    Global_801A66CC *g;
    f32 buf[46];
    f32 scale;

    if (fn_1_3EFA8() != 0) {
        return;
    }
    switch (fzgx_obj_lbl_1_bss_3C2A) {
    case 41:
        break;
    default:
        return;
    }
    if (fzgx_obj_lbl_1_bss_3C30.flags & 0x800) {
        return;
    }
    g = lbl_801A66CC;
    total = g->unk_8B4;
    total += g->unk_8B5;
    total += g->unk_8B6;
    if ((racer->flags & 0x10000) == 0) {
        fn_1_82EDC(racer->unk_474, racer->unk_6, (u32 *)buf);
        if (fzgx_obj_lbl_1_bss_53F8 != NULL) {
            scale = fzgx_obj_lbl_1_bss_53F8[0xB];
            scale *= 0.01f;
            fn_1_22B10(buf, scale);
        } else {
            scale = lbl_1_bss_25C48.unk_0;
            scale *= 0.01f;
            fn_1_22B10(buf, scale);
        }
        if (buf[1] != racer->unk_8) {
            changed = 1;
        }
        if (buf[4] != racer->unk_C) {
            changed = 1;
        }
        if (buf[8] != racer->unk_14) {
            changed = 1;
        }
        if (buf[7] != racer->unk_2C) {
            changed = 1;
        }
        if (buf[2] != racer->unk_220) {
            changed = 1;
        }
        if (buf[3] != racer->unk_22C) {
            changed = 1;
        }
    } else if (total == 0) {
        u8 min;
        f32 ms;
        f32 time;

        lbl_801A66CC->unk_8B4 = racer->unk_49C->unk_1E0;
        lbl_801A66CC->unk_8B5 = racer->unk_49C->unk_1E1;
        lbl_801A66CC->unk_8B6 = racer->unk_49C->unk_1E2;
        g = lbl_801A66CC;
        min = g->unk_8B4;
        if (min == 0 && g->unk_8B5 < 20) {
            changed = 1;
        }
        ms = 60.0f * g->unk_8B6 / 1000.0f;
        time = (s32)(g->unk_8B5 + min * 60);
        time *= 60.0f;
        time += ms;
        if (__fabs(time - (f32)racer->unk_49C->unk_1E4) > 20.0) {
            changed = 1;
        }
    }
    if (changed) {
        fzgx_obj_lbl_1_bss_3C30.unk_5 = 6;
    }
}
/* fzgx:end fn_1_2FDBC */

/* fzgx:begin fn_1_31C3C pool noprologue */
#include "types.h"

typedef struct Record {
    u32 time;      /* 0x00 */
    u32 lap;       /* 0x04 */
    u8 pad_8[0x10];
    u16 speed;     /* 0x18 */
    u8 c1A;
    u8 c1B;
    u8 c1C;
    u8 c1D;
    u8 c1E;
    u8 c1F;
} Record;

typedef struct RecordTable {
    Record ranking[10];  /* 0x000 */
    Record bestLap;      /* 0x140 */
    u16 maxSpeed;        /* 0x160 */
    u8 s162;
    u8 pad_163;
    u8 s164;
    u8 s165;
    u8 s166;
    u8 s167;
    u8 s168;
} RecordTable;

typedef struct RaceResult {
    u8 pad_0[0x18];
    u16 speed[6];   /* 0x18 */
    u32 time[5];    /* 0x24 */
    u32 lap[5];     /* 0x38 */
    u8 pad_4C[0x30];
    u8 c7C;
    u8 c7D;
    u8 c7E;
    u8 pad_7F;
    u8 c80;
    u8 c81;
    u8 c82;
} RaceResult;

typedef struct GameState {
    u8 pad_0[6];
    u8 course;          /* 0x06 */
    u8 pad_7[0xCD];
    RaceResult result;  /* 0xD4 */
    u8 pad_158[0x1444 - 0x158];
    Record last;        /* 0x1444 */
    u8 pad_1464[0x1508 - 0x1464];
} GameState;

typedef struct Obj5138 {
    u16 mode;
    u8 pad_2[0xE1];
    u8 course;   /* 0xE3 */
} Obj5138;

typedef struct Obj801A66CC {
    u8 pad_0[0x8B4];
    u8 b8B4;
    u8 b8B5;
    u16 h8B6;
} Obj801A66CC;

typedef struct Obj8B3A0 {
    u8 pad_0[0x90];
    s16 unk_90;
} Obj8B3A0;

/* the TU's .bss, addressed off one section base */
static u32 lbl_1_bss_3C00;
static u32 fzgx_bss_gap00[0xB];
static GameState lbl_1_bss_3C30;
static Obj5138 lbl_1_bss_5138;
static u32 fzgx_bss_gap0[(0x220D0 - 0x161C) / 4];
static RecordTable *lbl_1_bss_25CD0;
static u32 fzgx_bss_gap1[(0x22F08 - 0x220D4) / 4];
static u32 lbl_1_bss_26B08;
static u32 lbl_1_bss_26B0C;
static u32 lbl_1_bss_26B10;

extern Obj801A66CC *lbl_801A66CC;
extern Obj8B3A0 lbl_1_bss_8B3A0;
extern void fn_1_1554D0(void);
extern s32 fn_1_1555B0(s32);
extern void fn_1_155F9C(u32);
extern void fn_1_155FA8(u32);
extern s32 fn_1_F1B84(void);
extern s32 fn_1_F2280(s32);
extern void fn_1_F220C(s32);
extern u32 fn_1_F2338(s32, u32);
extern u32 ghost_test_record_flag0(s32);

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_order(void) {
    volatile u32 s;  /* fzgx-allow: S2 layout primer sink */
    s = lbl_1_bss_3C00;
    s = fzgx_bss_gap00[0];
    s = lbl_1_bss_3C30.course;
    s = lbl_1_bss_5138.mode;
    s = fzgx_bss_gap0[0];
    s = (u32)lbl_1_bss_25CD0;
    s = fzgx_bss_gap1[0];
    s = lbl_1_bss_26B08;
    s = lbl_1_bss_26B0C;
    s = lbl_1_bss_26B10;
}
#pragma section code_type ".text"

void fn_1_31C3C(u32 player) {
    RaceResult *res = &lbl_1_bss_3C30.result;
    u32 time = res->time[player];
    u32 lap = res->lap[player];
    u32 i;

    for (i = 0; i < 10; i++) {
        if (time < lbl_1_bss_25CD0->ranking[i].time) {
            break;
        }
    }
    lbl_1_bss_26B08 = i;

    for (i = 9; i > lbl_1_bss_26B08; i--) {
        lbl_1_bss_25CD0->ranking[i] = lbl_1_bss_25CD0->ranking[i - 1];
    }

    if (lbl_1_bss_26B08 < 10) {
        lbl_1_bss_25CD0->ranking[lbl_1_bss_26B08].time = time;
        lbl_1_bss_25CD0->ranking[lbl_1_bss_26B08].lap = lap;
        lbl_1_bss_25CD0->ranking[lbl_1_bss_26B08].speed = res->speed[player];
        lbl_1_bss_25CD0->ranking[lbl_1_bss_26B08].c1A = res->c82;
        lbl_1_bss_25CD0->ranking[lbl_1_bss_26B08].c1B = res->c80;
        lbl_1_bss_25CD0->ranking[lbl_1_bss_26B08].c1C = res->c81;
        lbl_1_bss_25CD0->ranking[lbl_1_bss_26B08].c1D = res->c7C;
        lbl_1_bss_25CD0->ranking[lbl_1_bss_26B08].c1E = res->c7D;
        lbl_1_bss_25CD0->ranking[lbl_1_bss_26B08].c1F = res->c7E;
    }

    if (lap < lbl_1_bss_25CD0->bestLap.time) {
        lbl_1_bss_26B0C = 1;
        lbl_1_bss_25CD0->bestLap.time = lap;
        lbl_1_bss_25CD0->bestLap.lap = lap;
        lbl_1_bss_25CD0->bestLap.speed = res->speed[player];
        lbl_1_bss_25CD0->bestLap.c1A = res->c82;
        lbl_1_bss_25CD0->bestLap.c1B = res->c80;
        lbl_1_bss_25CD0->bestLap.c1C = res->c81;
        lbl_1_bss_25CD0->bestLap.c1D = res->c7C;
        lbl_1_bss_25CD0->bestLap.c1E = res->c7D;
        lbl_1_bss_25CD0->bestLap.c1F = res->c7E;
    } else {
        lbl_1_bss_26B0C = 0;
    }

    if (lbl_1_bss_25CD0->maxSpeed < res->speed[player]) {
        lbl_1_bss_26B10 = 1;
        lbl_1_bss_25CD0->maxSpeed = res->speed[player];
        lbl_1_bss_25CD0->s162 = res->c82;
        lbl_1_bss_25CD0->s164 = res->c80;
        lbl_1_bss_25CD0->s165 = res->c81;
        lbl_1_bss_25CD0->s166 = res->c7C;
        lbl_1_bss_25CD0->s167 = res->c7D;
        lbl_1_bss_25CD0->s168 = res->c7E;
    } else {
        lbl_1_bss_26B10 = 0;
    }

    lbl_1_bss_3C30.last.lap = lap;
    lbl_1_bss_3C30.last.speed = res->speed[player];
    lbl_1_bss_3C30.last.c1A = res->c82;
    lbl_1_bss_3C30.last.c1B = res->c80;
    lbl_1_bss_3C30.last.c1C = res->c81;
    lbl_1_bss_3C30.last.c1D = res->c7C;
    lbl_1_bss_3C30.last.c1E = res->c7D;
    lbl_1_bss_3C30.last.c1F = res->c7E;
    lbl_1_bss_3C30.last.time = ((lbl_801A66CC->b8B4 << 20) & 0xFF00000) | (lbl_801A66CC->b8B5 << 12) | lbl_801A66CC->h8B6;

    fn_1_1554D0();
    fn_1_1555B0(lbl_1_bss_8B3A0.unk_90);
    if (lbl_1_bss_26B08 < 10) {
        fn_1_155F9C(1);
        fn_1_155FA8(lbl_1_bss_26B08);
    } else {
        fn_1_155F9C(0);
        fn_1_155FA8(-1);
    }

    switch (fn_1_F1B84()) {
    case 1:
        if (fn_1_F2280(lbl_1_bss_3C30.course) == 0) {
            lbl_1_bss_5138.mode = 25;
            fn_1_F220C(lbl_1_bss_3C30.course);
        }
        break;
    }

    if (fn_1_F2338(lbl_1_bss_3C30.course, time) & 0xFF) {
        if ((s32)ghost_test_record_flag0(lbl_1_bss_3C30.course) == 0) {
            lbl_1_bss_5138.course = lbl_1_bss_3C30.course;
            lbl_1_bss_5138.mode = 10;
        }
    }
}
/* fzgx:end fn_1_31C3C */

/* fzgx:begin fn_1_32600 */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 15.0f;
    s = 1.0f;
    s = 10.0f;
    s = 1.25f;
    s = 0.10000000149011612f;
    s = 0.8999999761581421f;
    s = 0.0006000000284984708f;
    s = 0.4000000059604645f;
    s = 0.75f;
    s = 70.0f;
    s = 0.5f;
    s = 36.0f;
    s = 16.0f;
    s = 45.0f;
    s = 0.0007999999797903001f;
    s = 18.0f;
    s = 50.0f;
}
static const u32 fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table5[52] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
    s = 80.0f;
    s = 60.0f;
}
static const u32 fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table9[2] = {0x00000000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 470.0f;
    s = 0.0625f;
    s = 14.0f;
    s = 127.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table11[3] = {0x03E8FED4, 0xFE70FE0C, 0xFE0CFE0C};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 10000.0f;
    s = 15000.0f;
    s = 9999.0f;
}
static const u32 fzgx_pool_table13[2] = {0xFFFFFF00, 0x80808000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 240.0f;
    s = 280.0f;
    s = 200.0f;
    s = 40.0f;
    s = 30.0f;
}
static const u32 fzgx_pool_table15[8] = {0x80808000, 0xFFFFFF00, 0x80808000, 0xFFFFFF00, 0xFFFFFF00, 0x00000000, 0x00000000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const u32 *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.05000000074505806f;
    s = 0.15000000596046448f;
    s = 0.07999999821186066f;
    s = 2.0f;
    s = 4.0f;
    s = 255.0f;
    s = 1.100000023841858f;
    s = 38.0f;
    s = 20.0f;
    s = 180.0f;
    s = 3.0f;
    s = 0.00019999999494757503f;
    s = 100.0f;
}
#pragma section code_type ".text"

typedef struct {
    u32 flags;
    u8 pad_4[0x17C - 4];
    f32 f17c;
    u8 pad_180[0x214 - 0x180];
    u16 u214;
    u8 pad_216[0x475 - 0x216];
    s8 b475;
    u8 pad_476[0x58C - 0x476];
    u32 x58c;
} Fn32600Obj;

s32 fn_1_32600(Fn32600Obj *p) {
    if (!(lbl_1_bss_3C30.unk_0 & 0x8000)) {
        if (p->flags & 0x8000000) {
            return 1;
        }
        if (p->x58c & 0x10) {
            return 1;
        }
        if (p->flags & 0x800) {
            if (p->b475 != -1) {
                fn_1_15E260(p->b475);
            }
            return 1;
        }
        if (p->flags & 0x80) {
            if (p->b475 != -1) {
                fn_1_15E260(p->b475);
            }
            if (lbl_1_bss_3C30.unk_5 != 5) {
                if ((p->flags & 0x200) || p->f17c < 1.0f) {
                    return 1;
                }
            } else {
                return 1;
            }
        }
    }
    {
        u32 g = lbl_1_bss_3C30.unk_0;
        if ((g & 0x40000) && lbl_1_bss_3C30.unk_A4 == 0) {
            f32 b;
            f32 a = p->f17c;
            s32 v;
            if (lbl_1_bss_25B80 < 300) {
                b = 1.0f;
            } else if (lbl_1_bss_25B80 < 600) {
                b = 10.0f;
            } else {
                b = 100.0f;
                a = 0.0f;
            }
            v = (a < b);
            v |= (p->u214 != 0);
            if (p->flags & 0x800) {
                v = 1;
            }
            lbl_1_bss_26B1D++;
            if (v && lbl_1_bss_26B1D > 30) {
                p->flags |= 0x10000000;
                return 1;
            }
        }
        if (g & 0x80000) {
            p->flags |= 0x10000000;
            return 1;
        }
        if (!(p->flags & 0x10200) && lbl_1_bss_25B98 > 420) {
            return 1;
        }
        return 0;
    }
}
/* fzgx:end fn_1_32600 */

/* fzgx:begin fn_1_327F8 */
struct fn_1_327F8_Arg0 {
    u32 unk_0;
    s16 unk_4;
    u8 pad_6[0x46F];
    s8 unk_475;
    u8 pad_476[0x26];
    u32 unk_49C;
};
struct fn_1_327F8_lbl_1_bss_3C30 {
    u32 unk_0;
    u8 unk_4;
    u8 unk_5;
    u8 pad_6[0x13B4 - 0x6];
    u32 unk_13B4;
    u8 pad_13B8[0x13D4 - 0x13B8];
    u32 unk_13D4;
    u8 pad_13D8[0x13F4 - 0x13D8];
    u8 unk_13F4;
    u8 unk_13F5;
    u8 pad_13F6[0x1468 - 0x13F6];
    u8 unk_1468;
    u8 pad_1469[0x1474 - 0x1469];
    u32 unk_1474;
};
struct fn_1_327F8_lbl_1_bss_25B88 {
    u32 unk_0;
};


void fn_1_327F8(struct fn_1_327F8_Arg0 *arg0, u32 arg1) {
    u8 *v0;
    s32 v1;
    u32 v5;
    u32 v2;
    u32 v3;
    u32 v4;

    v0 = (u8 *)arg0->unk_49C;
    v1 = arg0->unk_475;
    v2 = ((*(u8 *)(v0 + 0x174) << 20) | (*(u8 *)(v0 + 0x175) << 12)) | *(u16 *)(v0 + 0x176);
    v3 = ((*(u8 *)(v0 + 0x1e0) << 20) | (*(u8 *)(v0 + 0x1e1) << 12)) | *(u16 *)(v0 + 0x1e2);
    v5 = *(u32 *)(v0 + 0x118);

    if (arg0->unk_475 != -1) {
        if (v5 == 1 && ((*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_0 & 0x10) == 0) {
            fn_1_15E540(v1, (void *)(*((struct fn_1_327F8_lbl_1_bss_25B88 *)&lbl_1_bss_25B88)).unk_0);
        }
        if (v5 == ((*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_4 - 1) && (*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_5 != 3) {
            u32 a = (*((struct fn_1_327F8_lbl_1_bss_25B88 *)&lbl_1_bss_25B88)).unk_0;
            fn_1_15E5E4(arg0->unk_475, (void *)a);
        }
        fn_1_D07C4((u8)arg0->unk_475,
                   (((*(u8 *)(v0 + 0x1d4) << 20) | (*(u8 *)(v0 + 0x1d5) << 12)) | *(u16 *)(v0 + 0x1d6)));
        fn_1_CB404((u8)arg0->unk_475);
    }
    if ((s32)arg1 != -1) {
        *((u8 *)&(*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)) + 0x1468 + arg1) = (u8)v5;
    }
    if (v5 < 8) {
        *((u32 *)((u8 *)&(*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)) + 0x12c) + arg0->unk_4 * 0x28 + v5) = v2;
    }
    if (arg0->unk_475 != -1) {
        fn_1_15E688(arg0->unk_475, v2, (u8)v5, (void *)(*((struct fn_1_327F8_lbl_1_bss_25B88 *)&lbl_1_bss_25B88)).unk_0);
    }
    if ((*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_1474 <= 0x50000 + 0x6ff4) {
        if ((arg0->unk_0 & 0x08000000) != 0) {
            v3 = 0;
        }
        if (*(u8 *)(v0 + 0x115) == 0) {
            if (v5 > (*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_13F4) {
                *(u32 *)((u8 *)&(*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)) + (((v5 - 1) & 3) << 2) + 0x13b4) = v3;
                (*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_13F4 = (u8)v5;
                fn_1_15E3E0(arg0->unk_475, v3);
            }
        } else {
            if (*(u8 *)(v0 + 0x115) == 1) {
                if (v5 > (*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_13F5) {
                    *(u32 *)((u8 *)&(*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)) + (((v5 - 1) & 3) << 2) + 0x13d4) = v3;
                    (*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_13F5 = (u8)v5;
                    fn_1_15E434((*((struct fn_1_327F8_lbl_1_bss_25B88 *)&lbl_1_bss_25B88)).unk_0);
                }
            }
            if (arg0->unk_475 != -1) {
                fn_1_15E330(arg0->unk_475, v3, (void *)(u32)((*((struct fn_1_327F8_lbl_1_bss_25B88 *)&lbl_1_bss_25B88)).unk_0));
            }
        }
    }
}
/* fzgx:end fn_1_327F8 */

/* fzgx:begin fn_1_32A40 pool noprologue */
#include "types.h"
#include "rel/main_rel/game.h"

typedef struct {
    u8 pad_0[0x168];
    u8 unk_168;
    u8 unk_169;
    u16 unk_16A;
} RacerInfo;

typedef struct {
    u32 flags;
    s16 unk_4;
    s16 unk_6;
    f32 unk_8;
    u8 pad_C[0xA4 - 0xC];
    f32 unk_A4;
    u8 pad_A8[0xBC - 0xA8];
    f32 unk_BC;
    u8 pad_C0[0xD8 - 0xC0];
    f32 unk_D8;
    u8 pad_DC[0x17C - 0xDC];
    f32 unk_17C;
    u8 pad_180[0x184 - 0x180];
    f32 unk_184;
    u8 pad_188[0x18B - 0x188];
    u8 unk_18B;
    u8 pad_18C[0x218 - 0x18C];
    u32 unk_218;
    u8 pad_21C[0x224 - 0x21C];
    f32 unk_224;
    u8 pad_228[0x474 - 0x228];
    s8 unk_474;
    s8 unk_475;
    u8 pad_476[0x482 - 0x476];
    u8 unk_482;
    u8 pad_483[0x49C - 0x483];
    RacerInfo *unk_49C;
    u8 pad_4A0[0x50D - 0x4A0];
    u8 unk_50D;
    u8 pad_50E[0x580 - 0x50E];
    f32 unk_580;
    u8 pad_584[0x58C - 0x584];
    u32 unk_58C;
} Racer;

/* .bss 0x3C00 */
typedef struct {
    u8 pad_0[0x2A];
    s16 unk_2A;
    u8 pad_2C[0x4];
} GameHead;

/* .bss 0x3C30 */
typedef struct {
    u32 flags;
    u8 unk_4;
    u8 mode;
    u8 pad_6[2];
    u8 unk_8;
    u8 pad_9[3];
    u8 unk_C;
    u8 unk_D;
    u8 pad_E[0xA4 - 0xE];
    u16 unk_A4;
    u8 pad_A6[0x13F6 - 0xA6];
    u8 unk_13F6;
    u8 pad_13F7[3];
    u16 unk_13FA[4];
    u8 unk_1402;
    u8 unk_1403;
    u8 unk_1404;
    u8 pad_1405[0x1468 - 0x1405];
    u8 unk_1468[0xB];
    u8 unk_1473;
    u8 pad_1474[0x14BC - 0x1474];
} GameSub;

typedef struct {
    u8 data[0x1FC];
} RacerCopy;

typedef struct {
    u8 pad_0[0x4];
    f32 zero;
    u8 pad_8[0x4];
    f32 one;
    u8 pad_10[0x1E4 - 0x10];
    f32 hundred;
} GameRodata;

typedef struct {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 flags;
    u8 unk_19;
} RacerStatus;

static u32 fzgx_obj_lbl_1_bss_3C00;
static u8 fzgx_obj_lbl_1_bss_3C04[0xC];
static u8 fzgx_obj_lbl_1_bss_3C10;
static u8 fzgx_obj_lbl_1_bss_3C11;
static u16 fzgx_obj_lbl_1_bss_3C12;
static u32 fzgx_obj_lbl_1_bss_3C14;
static u32 fzgx_obj_lbl_1_bss_3C18;
static u32 fzgx_obj_lbl_1_bss_3C1C;
static u8 fzgx_obj_lbl_1_bss_3C20[0x8];
static u16 fzgx_obj_lbl_1_bss_3C28;
static s16 fzgx_obj_lbl_1_bss_3C2A;
static u32 fzgx_obj_lbl_1_bss_3C2C;
static GameSub fzgx_obj_lbl_1_bss_3C30;
static u16 fzgx_obj_lbl_1_bss_50EC[4];
static u8 fzgx_obj_lbl_1_bss_50F4[8];
static s16 fzgx_obj_lbl_1_bss_50FC;
static u8 fzgx_obj_bss_gap_50FE[0x25B84 - 0x5100];
static u32 fzgx_obj_lbl_1_bss_25B84;
static void * fzgx_obj_lbl_1_bss_25B88;
static u16 * fzgx_obj_lbl_1_bss_25B8C;
static u32 fzgx_obj_lbl_1_bss_25B90[2];
static u16 fzgx_obj_lbl_1_bss_25B98[(0x26304 - 0x25B98) / 2];
static f32 fzgx_obj_lbl_1_bss_26304[4];
static RacerCopy fzgx_obj_lbl_1_bss_26314[4];
static u8 fzgx_obj_lbl_1_bss_26B04[0x17];
static u8 fzgx_obj_lbl_1_bss_26B1B;
static u8 fzgx_obj_lbl_1_bss_26B1C;
static u8 fzgx_obj_lbl_1_bss_26B1D;
static u8 fzgx_obj_lbl_1_bss_26B1E;
static u8 fzgx_obj_lbl_1_bss_26B1F;
static u8 fzgx_obj_lbl_1_bss_26B20[0x20];
static f32 fzgx_obj_lbl_1_bss_26B40;
static f32 fzgx_obj_lbl_1_bss_26B44;

static const u32 fzgx_obj_lbl_1_rodata_BD8[1] = {0xFFFFFF00};
static const f32 fzgx_obj_lbl_1_rodata_BDC[1] = {0.0f};
static const u32 fzgx_pool_table_8[1] = {0x41700000};
static const f32 fzgx_obj_lbl_1_rodata_BE4[1] = {1.0f};
extern u8 lbl_1_data_5F6C__fzgx_offset_0[];
extern u8 lbl_1_data_5FA8__fzgx_offset_0[];
extern u8 lbl_1_data_5FE0__fzgx_offset_0[];
extern u8 lbl_1_data_6020__fzgx_offset_0[];
extern u8 lbl_1_data_605C__fzgx_offset_0[];
extern u8 lbl_1_data_609C__fzgx_offset_0[];
extern u8 lbl_1_data_60CC__fzgx_offset_0[];
extern u8 lbl_1_data_6104__fzgx_offset_0[];
extern u8 lbl_1_data_613C__fzgx_offset_0[];
extern u8 lbl_1_data_617C__fzgx_offset_0[];
extern u8 lbl_1_data_61BC__fzgx_offset_0[];
extern u8 lbl_1_data_61C8__fzgx_offset_0[];
extern u8 lbl_1_data_62C0__fzgx_offset_0[];
extern u8 lbl_1_data_62C4__fzgx_offset_0[];
static const u32 fzgx_pool_table_10[(0x1E4 - 0x10) / 4] = {
    0x41200000, 0x3FA00000, 0x3DCCCCCD, 0x3F666666, 0x3A1D4952, 0x3ECCCCCD, 0x3F400000, 0x428C0000,
    0x3F000000, 0x42100000, 0x41800000, 0x42340000, 0x3A51B717, 0x41900000, 0x42480000, 0x0,
    0x43300000, 0x0, (u32)lbl_1_data_5F6C__fzgx_offset_0, (u32)lbl_1_data_5F6C__fzgx_offset_0, (u32)lbl_1_data_5F6C__fzgx_offset_0, (u32)lbl_1_data_5F6C__fzgx_offset_0, (u32)lbl_1_data_5F6C__fzgx_offset_0, (u32)lbl_1_data_5FA8__fzgx_offset_0,
    (u32)lbl_1_data_5FA8__fzgx_offset_0, (u32)lbl_1_data_5FA8__fzgx_offset_0, (u32)lbl_1_data_5FA8__fzgx_offset_0, (u32)lbl_1_data_5FA8__fzgx_offset_0, (u32)lbl_1_data_5FE0__fzgx_offset_0, (u32)lbl_1_data_5FE0__fzgx_offset_0, (u32)lbl_1_data_5FE0__fzgx_offset_0, (u32)lbl_1_data_5FE0__fzgx_offset_0,
    (u32)lbl_1_data_5FE0__fzgx_offset_0, (u32)lbl_1_data_6020__fzgx_offset_0, (u32)lbl_1_data_6020__fzgx_offset_0, (u32)lbl_1_data_6020__fzgx_offset_0, (u32)lbl_1_data_6020__fzgx_offset_0, (u32)lbl_1_data_6020__fzgx_offset_0, (u32)lbl_1_data_605C__fzgx_offset_0, (u32)lbl_1_data_605C__fzgx_offset_0,
    (u32)lbl_1_data_605C__fzgx_offset_0, (u32)lbl_1_data_605C__fzgx_offset_0, (u32)lbl_1_data_605C__fzgx_offset_0, (u32)lbl_1_data_609C__fzgx_offset_0, (u32)lbl_1_data_609C__fzgx_offset_0, (u32)lbl_1_data_609C__fzgx_offset_0, (u32)lbl_1_data_609C__fzgx_offset_0, (u32)lbl_1_data_609C__fzgx_offset_0,
    (u32)lbl_1_data_60CC__fzgx_offset_0, (u32)lbl_1_data_60CC__fzgx_offset_0, (u32)lbl_1_data_60CC__fzgx_offset_0, (u32)lbl_1_data_60CC__fzgx_offset_0, (u32)lbl_1_data_60CC__fzgx_offset_0, (u32)lbl_1_data_6104__fzgx_offset_0, (u32)lbl_1_data_6104__fzgx_offset_0, (u32)lbl_1_data_6104__fzgx_offset_0,
    (u32)lbl_1_data_6104__fzgx_offset_0, (u32)lbl_1_data_6104__fzgx_offset_0, (u32)lbl_1_data_613C__fzgx_offset_0, (u32)lbl_1_data_613C__fzgx_offset_0, (u32)lbl_1_data_613C__fzgx_offset_0, (u32)lbl_1_data_613C__fzgx_offset_0, (u32)lbl_1_data_613C__fzgx_offset_0, (u32)lbl_1_data_617C__fzgx_offset_0,
    (u32)lbl_1_data_617C__fzgx_offset_0, (u32)lbl_1_data_617C__fzgx_offset_0, (u32)lbl_1_data_617C__fzgx_offset_0, (u32)lbl_1_data_617C__fzgx_offset_0, (u32)lbl_1_data_61BC__fzgx_offset_0, (u32)lbl_1_data_61C8__fzgx_offset_0, 0x3F4CCCCD, 0x42A00000,
    0x42700000, 0x0, 0x43300000, 0x80000000, 0x0, 0xFFFFFF00, 0x43EB0000, 0x3D800000,  /* fzgx-allow: A1 retail data bytes */
    0x41600000, 0x42FE0000, 0x3E800000, 0x3E8FED4, 0xFE70FE0C, 0xFE0CFE0C, 0x461C4000, 0x466A6000,
    0x461C3C00, 0xFFFFFF00, 0x80808000, 0x43A00000, 0x43700000, 0x438C0000, 0x43480000, 0x42200000,  /* fzgx-allow: A1 retail data bytes */
    0x41F00000, 0x80808000, 0xFFFFFF00, 0x80808000, 0xFFFFFF00, 0xFFFFFF00, (u32)lbl_1_data_62C0__fzgx_offset_0, (u32)lbl_1_data_62C4__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    0xFFFFFF00, 0x3D4CCCCD, 0x3E19999A, 0x3DA3D70A, 0x40000000, 0x40800000, 0x437F0000, 0x3F8CCCCD,
    0x42180000, 0x41A00000, 0x43340000, 0x40400000, 0x3951B717
};
static const f32 fzgx_obj_lbl_1_rodata_DBC[1] = {100.0f};

#pragma section code_type ".fzgxpool"
u32 fzgx_bss_order(void) {
    u32 sum = 0;
    sum += fzgx_obj_lbl_1_bss_3C00;
    sum += fzgx_obj_lbl_1_bss_3C04[0];
    sum += fzgx_obj_lbl_1_bss_3C10;
    sum += fzgx_obj_lbl_1_bss_3C11;
    sum += fzgx_obj_lbl_1_bss_3C12;
    sum += fzgx_obj_lbl_1_bss_3C14;
    sum += fzgx_obj_lbl_1_bss_3C18;
    sum += fzgx_obj_lbl_1_bss_3C1C;
    sum += fzgx_obj_lbl_1_bss_3C20[0];
    sum += fzgx_obj_lbl_1_bss_3C28;
    sum += fzgx_obj_lbl_1_bss_3C2A;
    sum += fzgx_obj_lbl_1_bss_3C2C;
    sum += fzgx_obj_lbl_1_bss_3C30.flags;
    sum += fzgx_obj_lbl_1_bss_50EC[0];
    sum += fzgx_obj_lbl_1_bss_50F4[0];
    sum += fzgx_obj_lbl_1_bss_50FC;
    sum += fzgx_obj_bss_gap_50FE[0];
    sum += fzgx_obj_lbl_1_bss_25B84;
    sum += (u32)fzgx_obj_lbl_1_bss_25B88;
    sum += (u32)fzgx_obj_lbl_1_bss_25B8C;
    sum += fzgx_obj_lbl_1_bss_25B90[0];
    sum += fzgx_obj_lbl_1_bss_25B98[0];
    sum += *(u32 *)&fzgx_obj_lbl_1_bss_26304[0];
    sum += fzgx_obj_lbl_1_bss_26314[0].data[0];
    sum += fzgx_obj_lbl_1_bss_26B04[0];
    sum += fzgx_obj_lbl_1_bss_26B1B;
    sum += fzgx_obj_lbl_1_bss_26B1C;
    sum += fzgx_obj_lbl_1_bss_26B1D;
    sum += fzgx_obj_lbl_1_bss_26B1E;
    sum += fzgx_obj_lbl_1_bss_26B1F;
    sum += fzgx_obj_lbl_1_bss_26B20[0];
    sum += *(u32 *)&fzgx_obj_lbl_1_bss_26B40;
    sum += *(u32 *)&fzgx_obj_lbl_1_bss_26B44;
    sum += (u32)&fzgx_obj_lbl_1_rodata_BD8;
    sum += (u32)&fzgx_obj_lbl_1_rodata_BDC;
    sum += (u32)&fzgx_pool_table_8;
    sum += (u32)&fzgx_obj_lbl_1_rodata_BE4;
    sum += (u32)&fzgx_pool_table_10;
    sum += (u32)&fzgx_obj_lbl_1_rodata_DBC;
    return sum;
}
#pragma section code_type ".text"

#define racer_slot_data (&lbl_1_data_3D544.unk_0)

extern const GameRodata lbl_1_rodata_BD8;
extern u8 lbl_1_bss_718E0[];

extern void fn_1_1566F8(s32, RacerStatus *);
extern void fn_1_1567A8(s32);
extern void fn_1_156754(s32);
extern void fn_1_8D894(Racer *);
extern void fn_1_F7338(s32, s32, s32);
extern void fn_1_2E928(Racer *);
extern s32 fn_1_32600(Racer *);
extern void fn_1_32200(Racer *, s32);
extern u32 fn_1_8C884(s32);
extern void fn_1_15E764(s32, void *);
extern void fn_1_327F8(Racer *, s32);
extern void fn_1_D07AC(u32, u32);
extern void fn_1_A2D84(u32);
extern void fn_80008BA8(void *, void *, u32);

void fn_1_32A40(Racer *racer) {
    s8 idx;
    s32 a;
    s32 b;
    s32 c;
    RacerStatus status;

    idx = racer->unk_474;
    if (idx != -1 && !(fzgx_obj_lbl_1_bss_3C30.flags & 0x800)) {
        status.flags = 0;
        status.unk_19 = racer->unk_6 % 5;
        status.unk_14 = fzgx_obj_lbl_1_rodata_BDC[0];
        a = (racer->flags & 0x400) &&
            !(fzgx_obj_lbl_1_bss_26B1C & (1 << idx));
        b = 0;
        if (a) {
            if ((__rlwnm(lbl_1_bss_718E0[2], (32 - racer->unk_474) & 31, 31, 31))) {
                b = 1;
            }
        }
        c = 0;
        if (b && fzgx_obj_lbl_1_bss_3C2A != 42) {
            c = 1;
        }
        if (c) {
            if (racer->flags & 0x8000) {
                status.flags |= 1;
            } else {
                status.flags &= ~1;
            }
            status.unk_0 = racer->unk_8;
            status.unk_C = racer->unk_17C;
            status.unk_4 = racer->unk_580;
            status.unk_8 = racer->unk_A4;
            status.unk_10 = racer->unk_224;
            if (racer->flags & 0x400040) {
                status.flags |= 8;
            }
            if (racer->flags & 0x10) {
                status.flags |= 4;
                status.unk_14 = racer->unk_BC;
            }
            if (racer->flags & 0x2800000) {
                status.flags |= 0x10;
            }
            if ((racer->unk_218 >> 29) & 1) {
                status.flags |= 0x20;
            }
            if (racer->flags & 0x80) {
                if (racer->flags & 0x40000000) {
                    status.flags |= 0x40;
                }
                if (!(racer->unk_58C & 0x10) && racer->unk_50D == 0xEF) {
                    status.flags |= 2;
                }
                status.flags |= 0x80;
            }
        } else {
            status.unk_0 = fzgx_obj_lbl_1_rodata_BDC[0];
        }
        fn_1_1566F8(racer->unk_474, &status);
        fn_1_1567A8(racer->unk_474);
        if (fzgx_obj_lbl_1_bss_3C30.mode == 2 && !(racer->flags & 0x10000)) {
            if (!(fzgx_obj_lbl_1_bss_26B40 < racer->unk_184) &&
                fzgx_obj_lbl_1_rodata_DBC[0] == racer->unk_184 && racer->unk_18B != 0 &&
                !(racer->unk_218 & 0x8000000)) {
                racer->unk_58C |= 0x40;
            }
        }
    }

    if (!(fzgx_obj_lbl_1_bss_3C30.flags & 0x200000)) {
        s32 player = racer->unk_474;

        if (racer->flags & 0x10000) {
            s8 slot = racer->unk_475;
            if (slot != -1) {
                u8 mask = 1 << slot;
                if (!(fzgx_obj_lbl_1_bss_26B1E & mask)) {
                    fzgx_obj_lbl_1_bss_26B1E |= mask;
                    slot = racer->unk_475;
                    if (slot != -1 && fzgx_obj_lbl_1_bss_26304[slot] < fzgx_obj_lbl_1_rodata_BE4[0]) {
                        fn_80008BA8(&fzgx_obj_lbl_1_bss_26314[slot], racer->unk_49C, 0x1FC);
                        fzgx_obj_lbl_1_bss_26304[racer->unk_475] = racer->unk_D8;
                        if (racer->unk_482 > 30) {
                            fzgx_obj_lbl_1_bss_26B04[racer->unk_475] = 30;
                        } else {
                            fzgx_obj_lbl_1_bss_26B04[racer->unk_475] = racer->unk_482;
                        }
                    }
                    if (fzgx_obj_lbl_1_bss_3C30.mode == 5) {
                        fzgx_obj_lbl_1_bss_50EC[racer->unk_475] = 180;
                    } else {
                        fzgx_obj_lbl_1_bss_50EC[racer->unk_475] = 480;
                    }
                    if (!(racer->flags & 0x4000000)) {
                        fn_1_8D894(racer);
                    }
                    {
                        u16 *timer = &fzgx_obj_lbl_1_bss_50EC[racer->unk_475];
                        fzgx_obj_lbl_1_bss_25B90[0]++;
                        if (fzgx_obj_lbl_1_bss_25B98[0] == 0) {
                            fzgx_obj_lbl_1_bss_25B8C = timer;
                            fzgx_obj_lbl_1_bss_25B84 = 1;
                        }
                    }
                    if (fzgx_obj_lbl_1_bss_50FC == -1) {
                        fzgx_obj_lbl_1_bss_50FC = racer->unk_475;
                    }
                    racer_slot_data[racer->unk_475] = 0;
                } else {
                    fzgx_obj_lbl_1_bss_50EC[slot] -= fzgx_obj_lbl_1_bss_50EC[slot] != 0;
                }
            }
            if (player != -1) {
                u8 mask = 1 << player;
                if (!(fzgx_obj_lbl_1_bss_50F4[0] & mask)) {
                    fn_1_F7338(player, 5, 0);
                }
                fzgx_obj_lbl_1_bss_50F4[0] |= mask;
                fzgx_obj_lbl_1_bss_3C30.unk_1468[player] = fzgx_obj_lbl_1_bss_3C30.unk_4;
                fn_1_156754(player);
            }
            if (!(fzgx_obj_lbl_1_bss_3C30.flags & 0x800)) {
                fzgx_obj_lbl_1_bss_26B20[racer->unk_4] = 1;
            }
            racer->flags |= 1;
            fn_1_2E928(racer);
        } else if (fn_1_32600(racer)) {
            fn_1_32200(racer, player);
        } else {
            RacerInfo *info = racer->unk_49C;
            if (!(racer->flags & 0x8000200) && (fzgx_obj_lbl_1_bss_3C30.flags & 0x40000)) {
                u32 n = fn_1_8C884(racer->unk_4);
                u32 q;
                u32 rem;
                GameSub *sub = &fzgx_obj_lbl_1_bss_3C30;
                if (sub->unk_1403 < n) {
                    s32 v;
                    q = n >> 2;
                    rem = n & 3;
                    if (q >= sub->unk_1404) {
                        q = sub->unk_1404 - 1;
                    }
                    v = fzgx_obj_lbl_1_bss_3C30.unk_13FA[rem] - fzgx_obj_lbl_1_bss_3C30.unk_1402 * q * 60;
                    if (v < 0) {
                        v = 0;
                    }
                    if (v != 0) {
                        sub->unk_1403 = n;
                        fzgx_obj_lbl_1_bss_3C30.unk_A4 += v;
                        if (racer->unk_475 != -1) {
                            fn_1_15E764(racer->unk_475, fzgx_obj_lbl_1_bss_25B88);
                        }
                    }
                }
            }
            if (racer->flags & 0x40000) {
                fn_1_327F8(racer, player);
            }
            if (racer->unk_475 != -1) {
                fn_1_D07AC((u8)racer->unk_475,
                           info->unk_16A | ((info->unk_168 << 20) | (info->unk_169 << 12)));
            }
        }

        if (fzgx_obj_lbl_1_bss_3C30.mode == 2 && !(racer->flags & 0x10000)) {
            if (racer->unk_58C & 0x40) {
                fzgx_obj_lbl_1_bss_3C30.mode = 6;
            }
            fzgx_obj_lbl_1_bss_26B44 = racer->unk_184;
        }
        if (racer->unk_474 != -1 && fzgx_obj_lbl_1_bss_3C30.mode == 1) {
            u8 k = racer->unk_482 / 5;
            if (!(fzgx_obj_lbl_1_bss_3C30.flags & 0x800) && fzgx_obj_lbl_1_bss_3C30.unk_1473 == 0) {
                u8 d = k - fzgx_obj_lbl_1_bss_3C30.unk_1473;
                fzgx_obj_lbl_1_bss_3C30.unk_1473 = k;
                fzgx_obj_lbl_1_bss_3C30.unk_13F6 += d;
                if (d) {
                    fn_1_A2D84(0xA9092800);
                }
            }
        }
        if (!(fzgx_obj_lbl_1_bss_3C30.flags & 0x20)) {
            u8 joined;
            u8 left;
            GameSub *sub;
            s32 i;
            sub = &fzgx_obj_lbl_1_bss_3C30;
            joined = fzgx_obj_lbl_1_bss_50F4[0];
            sub->unk_C = 0;
            left = fzgx_obj_lbl_1_bss_26B1B;
            sub->unk_D = sub->unk_8;
            for (i = 0; i < 4; i++) {
                u32 mask = 1 << i;
                if (joined & mask) {
                    sub->unk_C++;
                }
                if (left & mask) {
                    sub->unk_D--;
                }
            }
        }
    }
}
/* fzgx:end fn_1_32A40 */

/* fzgx:begin fn_1_33890 */
typedef struct {
    u8 pad_0[0x5];
    u8 unk_5;
    u8 pad_6[0x4];
    u8 unk_A;
    u8 pad_B[0x1];
    u8 unk_C;
    u8 unk_D;
} Fn33890Arg;

int fn_1_33890(Fn33890Arg* arg0) {
    u8 count;
    u8 limit;
    u32 flags;

    if ((s32)lbl_1_bss_25BA0.unk_0 != 0) {
        return 0;
    }

    if (((flags = lbl_1_bss_3C30.unk_0) & 0x800) != 0) {
        return 0;
    }

    switch (arg0->unk_5) {
    case 4:
        if (arg0->unk_D == 0 || arg0->unk_A != 1) {
            /* Shared fallback is the irreducible default path. */
            goto fallback;
        }
        return 1;

    case 2:
        if (arg0->unk_C == 0) {
            /* Shared fallback is the irreducible default path. */
            goto fallback;
        }
        return 1;

    case 0:
    case 1:
    case 6:
        count = arg0->unk_C;
        if (count == 0) {
            /* Shared fallback is the irreducible default path. */
            goto fallback;
        }
        limit = arg0->unk_D;
        if (limit <= count) {
            if ((s32)lbl_1_bss_25B84 != 0) {
                lbl_1_bss_3C30.unk_0 |= 0x10000;
            }
            return 1;
        }
        if (lbl_1_bss_3C30.unk_5 == 0 && (limit - count) <= 1) {
            lbl_1_bss_25B98++;
            return 1;
        }
        break;

    default:
        break;
    }

fallback:
    if (lbl_1_bss_3C30.unk_8 != 0) {
        if (lbl_1_bss_3C30.unk_D == 0) {
            return -1;
        }
    } else if (lbl_1_bss_3C30.pad_A[0] == 0) {
        return -1;
    }

    if ((flags & 0x04000000) == 0 && lbl_1_bss_3C30.unk_1474 > 0x57030) {
        lbl_1_bss_3C30.unk_0 |= 0x80000;
        return -1;
    }
    return 0;
}
/* fzgx:end fn_1_33890 */

/* fzgx:begin fn_1_34924 pool noprologue */
#include "types.h"

extern int fn_1_EB200(void);
extern void fn_1_4310(u32);
extern void fn_1_F2EB8(void);
extern void fn_1_A4F18(s32);
extern u32 fn_1_4060(void);
extern void *fn_1_435C(void *);
extern void fn_1_426C(u32);
extern void fn_1_105724(void);
extern void *fn_1_86254(void *);
extern void fn_1_15E540(s32, void *);

typedef struct {
    u32 flags;
    u8 pad_4[4];
    u8 count;
} Obj_34924_F;

typedef struct {
    u8 pad_0[0x30];
    Obj_34924_F f;
    u8 pad_3C[0x14C8];
    s8 unk_1504;
} Obj_34924_A;

typedef struct {
    u8 pad_0[0x1F88];
    void *unk_1F88;
    u8 pad_1F8C[0x118];
    void *unk_20A4;
    u8 pad_20A8[0x1D4];
    s32 unk_227C;
    s32 unk_2280;
    s32 unk_2284;
    u8 pad_2288[0xCC0];
    s32 unk_2F48;
} Obj_34924_B;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_3C00;
u32 fzgx_obj_lbl_1_bss_3C04;
u32 lbl_1_bss_3C08[2];
u8 lbl_1_bss_3C10;
u8 fzgx_obj_lbl_1_bss_3C11;
u16 fzgx_obj_lbl_1_bss_3C12;
u32 lbl_1_bss_3C12_fill_3C14[2];
u32 fzgx_obj_lbl_1_bss_3C1C[3];
u16 lbl_1_bss_3C1C_fill_3C28;
u16 fzgx_obj_lbl_1_bss_3C2A;
u32 lbl_1_bss_3C2A_fill_3C2C;
Obj_34924_F fzgx_obj_lbl_1_bss_3C30;
u32 lbl_1_bss_3C30_fill_3C3C[1324];
u32 fzgx_obj_lbl_1_bss_50EC[5];
u32 fzgx_obj_lbl_1_bss_5100;
s8 fzgx_obj_lbl_1_bss_5104;
u8 lbl_1_bss_5104_fill_5105;
u16 lbl_1_bss_5104_fill_5106;
u32 lbl_1_bss_5104_fill_5108[12];
u8 fzgx_gap_bss_5138[0x348];
u32 fzgx_obj_lbl_1_bss_5480[33216];
u16 lbl_1_bss_25B80;
u16 lbl_1_bss_5480_gap_25B82;
u32 lbl_1_bss_25B84;
void *fzgx_obj_lbl_1_bss_25B88;
u32 lbl_1_bss_25B88_fill_25B8C[3];
u16 fzgx_obj_lbl_1_bss_25B98;
u16 lbl_1_bss_5480_gap_25B9A;
u32 lbl_1_bss_25B9C;
u32 fzgx_obj_lbl_1_bss_25BA0[42];
u32 fzgx_obj_lbl_1_bss_25C48[23];
void *fzgx_obj_lbl_1_bss_25CA4;
u32 lbl_1_bss_25CA4_fill_25CA8[10];
u32 lbl_1_bss_25CD0[105];
u32 lbl_1_bss_25E74[2];
s32 lbl_1_bss_25E74_8;
s32 lbl_1_bss_25E74_C;
s32 lbl_1_bss_25E74_10;
u32 lbl_1_bss_25E74_fill_25E88[2];
u32 lbl_1_bss_25E90[2];
u8 fzgx_obj_lbl_1_bss_25E98;
u8 lbl_1_bss_5480_gap_25E99;
u16 lbl_1_bss_5480_gap_25E99_fill_25E9A;
u32 fzgx_obj_lbl_1_bss_25E9C[240];
u32 fzgx_obj_lbl_1_bss_2625C[8];
u32 lbl_1_bss_2627C[30];
u8 lbl_1_bss_262F4;
u8 lbl_1_bss_5480_gap_262F5;
u16 lbl_1_bss_5480_gap_262F5_fill_262F6;
u32 lbl_1_bss_262F8[2];
u16 lbl_1_bss_26300;
u16 lbl_1_bss_5480_gap_26302;
u32 lbl_1_bss_26304[4];
u32 fzgx_obj_lbl_1_bss_26314[508];
u32 lbl_1_bss_26B04[5];
u8 fzgx_obj_lbl_1_bss_26B18;
u8 fzgx_obj_lbl_1_bss_26B19;
u8 fzgx_obj_lbl_1_bss_26B1A;
u8 lbl_1_bss_5480_gap_26B1B;
u8 lbl_1_bss_5480_gap_26B1B_fill_26B1C;
u8 lbl_1_bss_26B1D;
u16 fzgx_obj_lbl_1_bss_26B1E;
u32 lbl_1_bss_26B1E_fill_26B20[10];
s32 lbl_1_bss_26B1E_2A;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C00;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C04;
    s = *(u8 *)&lbl_1_bss_3C08;
    s = *(u8 *)&lbl_1_bss_3C10;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C11;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C12;
    s = *(u8 *)&lbl_1_bss_3C12_fill_3C14;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C1C;
    s = *(u8 *)&lbl_1_bss_3C1C_fill_3C28;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C2A;
    s = *(u8 *)&lbl_1_bss_3C2A_fill_3C2C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C30;
    s = *(u8 *)&lbl_1_bss_3C30_fill_3C3C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_50EC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5100;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5104;
    s = *(u8 *)&lbl_1_bss_5104_fill_5105;
    s = *(u8 *)&lbl_1_bss_5104_fill_5106;
    s = *(u8 *)&lbl_1_bss_5104_fill_5108;
    s = *(u8 *)&fzgx_gap_bss_5138;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5480;
    s = *(u8 *)&lbl_1_bss_25B80;
    s = *(u8 *)&lbl_1_bss_5480_gap_25B82;
    s = *(u8 *)&lbl_1_bss_25B84;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25B88;
    s = *(u8 *)&lbl_1_bss_25B88_fill_25B8C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25B98;
    s = *(u8 *)&lbl_1_bss_5480_gap_25B9A;
    s = *(u8 *)&lbl_1_bss_25B9C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25BA0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25C48;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25CA4;
    s = *(u8 *)&lbl_1_bss_25CA4_fill_25CA8;
    s = *(u8 *)&lbl_1_bss_25CD0;
    s = *(u8 *)&lbl_1_bss_25E74;
    s = *(u8 *)&lbl_1_bss_25E74_8;
    s = *(u8 *)&lbl_1_bss_25E74_C;
    s = *(u8 *)&lbl_1_bss_25E74_10;
    s = *(u8 *)&lbl_1_bss_25E74_fill_25E88;
    s = *(u8 *)&lbl_1_bss_25E90;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25E98;
    s = *(u8 *)&lbl_1_bss_5480_gap_25E99;
    s = *(u8 *)&lbl_1_bss_5480_gap_25E99_fill_25E9A;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25E9C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_2625C;
    s = *(u8 *)&lbl_1_bss_2627C;
    s = *(u8 *)&lbl_1_bss_262F4;
    s = *(u8 *)&lbl_1_bss_5480_gap_262F5;
    s = *(u8 *)&lbl_1_bss_5480_gap_262F5_fill_262F6;
    s = *(u8 *)&lbl_1_bss_262F8;
    s = *(u8 *)&lbl_1_bss_26300;
    s = *(u8 *)&lbl_1_bss_5480_gap_26302;
    s = *(u8 *)&lbl_1_bss_26304;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_26314;
    s = *(u8 *)&lbl_1_bss_26B04;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_26B18;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_26B19;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_26B1A;
    s = *(u8 *)&lbl_1_bss_5480_gap_26B1B;
    s = *(u8 *)&lbl_1_bss_5480_gap_26B1B_fill_26B1C;
    s = *(u8 *)&lbl_1_bss_26B1D;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_26B1E;
    s = *(u8 *)&lbl_1_bss_26B1E_fill_26B20;
    s = *(u8 *)&lbl_1_bss_26B1E_2A;
}
#pragma section code_type ".text"

void fn_1_34924(u16 *p) {
    
    
    if (fn_1_EB200() == 0) {
        if ((fzgx_obj_lbl_1_bss_3C30.flags & 0x800) || fzgx_obj_lbl_1_bss_5104 == -1) {
            u32 v = (u16)(*p - 1);
            *p = v;
            if (v != 0) {
                if (*p > 0x3C && *p < 0xF0) {
                    u32 fl;
                    fn_1_4310(0);
                    fl = fzgx_obj_lbl_1_bss_3C30.flags | 0x4000;
                    fzgx_obj_lbl_1_bss_3C30.flags = fl;
                    if (fl & 0x800000) {
                        if (*p == 0xEF) {
                            fn_1_F2EB8();
                            lbl_1_bss_26B1E_2A = 1;
                        }
                    } else {
                        lbl_1_bss_26B1E_2A = 1;
                    }
                }
                fn_1_A4F18((u8)(*p / 60));
            } else {
                s32 i;
                fn_1_4060();
                lbl_1_bss_25E74_8 = -1;
                fn_1_435C(fzgx_obj_lbl_1_bss_25B88);
                if (lbl_1_bss_25E74_C != -1) {
                    fn_1_426C(lbl_1_bss_25E74_C);
                    fn_1_105724();
                }
                lbl_1_bss_25E74_C = -1;
                fn_1_435C(fzgx_obj_lbl_1_bss_25CA4);
                if (lbl_1_bss_25E74_10 != -1) {
                    fn_1_426C(lbl_1_bss_25E74_10);
                }
                lbl_1_bss_25E74_10 = -1;
                if (fzgx_obj_lbl_1_bss_3C30.flags & 0x10) {
                    for (i = 0; (s8)i < (&fzgx_obj_lbl_1_bss_3C30)->count; i++) {
                        u8 *r = fn_1_86254((void *)(s32)(s8)i);
                        if ((s8)r[0x475] != -1) {
                            fn_1_15E540((s8)r[0x475], fzgx_obj_lbl_1_bss_25B88);
                        }
                    }
                }
            }
        }
    }
}
/* fzgx:end fn_1_34924 */

/* fzgx:begin fn_1_34AC0 noprologue */
#include "types.h"
#include "rel/main_rel/game.h"

extern s16 fn_1_8D7C8(void);
extern s16 fn_1_12C7B8(s16);
extern u32 fn_1_8D5F0(s16);
extern int fn_1_8D72C(s16);
extern u32 lbl_801A63C0;
extern u8 lbl_1_bss_2627C[120];

static inline s32 fn_1_34AC0_rand(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}

void fn_1_34AC0(s8 *arr, s8 start, s8 total, s32 mode) {
    u64 mask = 0;
    s32 flag = 0;
    s16 r;
    s16 k;
    s16 j;
    s16 m;
    s16 i;
    s16 a;
    s16 b;
    s32 t;

    if (total > fn_1_8D7C8()) {
        flag = 1;
    }
    if (start == 0) {
        start = 1;
    }
    for (i = 0; i < start; i++) {
        mask |= 1ULL << fn_1_12C7B8(arr[i]);
    }

    if ((mode == 0 && lbl_1_bss_3C30.unk_5 == 1 && lbl_1_bss_3C30.unk_A6 == 5) ||
        (mode == 1 && lbl_1_bss_8B3A0.unk_0 == 1 && lbl_1_bss_8B3A0.unk_8C == 5)) {
        k = start;
        for (j = 0; j < 41; j++) {
            if ((fn_1_8D5F0(j) & 0x10000000) && k < total) {
                if (flag ? 1 : (mask & (1ULL << j)) == 0) {
                    ((u32 *)lbl_1_bss_2627C)[k] = 0;
                    arr[k] = j;
                    mask |= 1ULL << j;
                    k++;
                }
            }
        }
        for (m = 0; m < 30; m++) {
            a = fn_1_34AC0_rand() % k;
            b = fn_1_34AC0_rand() % k;
            if (a >= start && b >= start && a != b) {
                t = arr[a];
                arr[a] = arr[b];
                arr[b] = t;
            }
        }
        start = k;
    }

    for (k = start; k < total; k++) {
        do {
            r = fn_1_34AC0_rand() % 41;
        } while ((flag ? 0 : (mask & (1ULL << r))) != 0 || fn_1_8D72C(r) == 0);
        ((u32 *)lbl_1_bss_2627C)[k] = 0;
        arr[k] = r;
        mask |= 1ULL << r;
    }
}
/* fzgx:end fn_1_34AC0 */

/* fzgx:begin fn_1_34E08 */
typedef struct {
    u32 flags;
    u8 pad_4[0x819C];
    u8 unk_81A0;
} Obj_1_34E08_Settings;


void fn_1_34E08(void) {
    struct { u8 *value; } data;
    char buf[0x20];
    u8 tmp[0x20];
    s16 i;
    s32 v;

    data.value = (u8 *)&lbl_1_data_5730;
    v = lbl_1_bss_8B3A0.unk_E;
    if (v > 40) {
        Obj_1_34E08_Settings *s = (Obj_1_34E08_Settings *)fn_1_36AD0();
        v = 50;
        if (!(s->flags & 0x40000000)) {
            v = s->unk_81A0;
        }
    }
    lbl_1_bss_26B5C[0] = v;
    fn_1_34AC0(lbl_1_bss_26B5C, 1, 30, 1);
    fn_1_8001C();
    fn_1_12AB38(data.value + 0xCE4);
    fn_1_465D0( (char *)(void *)(data.value + 0xCF0), 1);
    for (i = 0; i < 30; i++) {
        if (i == 0) {
            sprintf(buf, (const char *)(data.value + 0xD00), fn_1_7F518(lbl_1_bss_26B5C[i], tmp, 0));
        } else {
            sprintf(buf, (const char *)(data.value + 0xD0C), fn_1_7F518(lbl_1_bss_26B5C[i], tmp, 0));
        }
        fn_1_465D0( (char *)(void *)(buf), 1);
    }
    fn_1_12AB38(data.value + 0xD18);
}
/* fzgx:end fn_1_34E08 */

/* fzgx:begin fn_1_34F38 pool */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u8 unk_8[0x8];
    u8 unk_10[0x4A248];
    u8 unk_4A258[0x4A248];
} Fn34F38Arg;

typedef struct {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_A[0xA];
} Fn34F38Slot;

typedef struct {
    u8 pad_0[0x8];
    f32 unk_8;
} Fn34F38Entry;

extern Fn34F38Slot lbl_1_bss_6F1E4[4];

extern u32 fn_8004CD70(s32, void *, u32);
extern void fn_1_A2E24(s32, u32, s32);
extern void fn_80067344(s32, s32, u32, s32);
extern Fn34F38Entry *fn_1_86254(s32);
extern void fn_1_A2DF4(s32, u32, s32);
extern void fn_1_35124(void);
extern void fn_1_4030(void (*)(void));

/* Unused pointer words below retain their zero relocation placeholders. */
#define POOL_RGBA8(r, g, b, a) (((u32)(r) << 24) | ((u32)(g) << 16) | ((u32)(b) << 8) | (u32)(a))

#pragma force_active on
static const u32 fzgx_pool_table_0[] = {
    0xFFFFFF00, 0x00000000, 0x41700000, 0x3F800000,
    0x41200000, 0x3FA00000, 0x3DCCCCCD, 0x3F666666,
    0x3A1D4952, 0x3ECCCCCD, 0x3F400000, 0x428C0000,
    0x3F000000, 0x42100000, 0x41800000, 0x42340000,
    0x3A51B717, 0x41900000, 0x42480000, 0x00000000,
    0x43300000, 0x00000000, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0x3F4CCCCD, 0x42A00000,
    0x42700000, 0x00000000, 0x43300000, 0x80000000,
    0x00000000, 0xFFFFFF00, 0x43EB0000, 0x3D800000,
    0x41600000, 0x42FE0000, 0x3E800000, 0x03E8FED4,
    0xFE70FE0C, 0xFE0CFE0C, 0x461C4000, 0x466A6000,
    0x461C3C00, 0xFFFFFF00, POOL_RGBA8(128, 128, 128, 0), 0x43A00000,
    0x43700000, 0x438C0000, 0x43480000, 0x42200000,
    0x41F00000, POOL_RGBA8(128, 128, 128, 0), 0xFFFFFF00, POOL_RGBA8(128, 128, 128, 0),
    0xFFFFFF00, 0xFFFFFF00, 0, 0,
    0xFFFFFF00, 0x3D4CCCCD, 0x3E19999A, 0x3DA3D70A,
    0x40000000, 0x40800000, 0x437F0000, 0x3F8CCCCD,
    0x42180000, 0x41A00000, 0x43340000, 0x40400000,
    0x3951B717, 0x42C80000, 0x42960000, 0x39D1B717,
    0x43160000, 0xFFF200FF, 0xFFF200FF, POOL_RGBA8(128, 128, 128, 128),
    0xFFFFFF96, 0xFFF200FF, 0xFFF200FF, 0xFFFFFF96,
    0x3C23D70A, 0x447A0000, 0x40340000, 0x00000000,
    0x80000000, 0x40000000, 0x20000000, 0x10000000,
    0x441B0000, 0x430C0000, 0x453B8000, 0x39AEC33E,
    0x3E99999A, 0x3F333333, 0x3E4CCCCD, 0x3F19999A,
    0x43E10000
};
#pragma force_active reset
static const u16 default_values[4] = { 0, 1, 2, 3 };

void fn_1_34F38(Fn34F38Arg *arg0) {
    s8 j;
    s8 i;

    if (arg0 != NULL) {
        if (arg0->unk_0 == 0) {
            arg0->unk_0 = fn_8004CD70(2, arg0->unk_10, sizeof(arg0->unk_10));
        }
        if (arg0->unk_4 == 0) {
            arg0->unk_4 = fn_8004CD70(2, arg0->unk_4A258, sizeof(arg0->unk_4A258));
        }
    }
    fn_1_A2E24(0x10, 0xA0100000, 0x7F);
    fn_1_A2E24(0x10, 0xA0110000, 0);
    fn_80067344(1, 0xF, 0xB0270000, 0x7F);

    for (i = 0; i < 4; i++) {
        if (lbl_1_bss_3C30.unk_8 > i) {
            f32 v = fn_1_86254(i)->unk_8;
            if (v <= 1100.0f) {
                lbl_1_bss_6F1E4[i].unk_8 = 4;
            } else if (v <= 1900.0f) {
                lbl_1_bss_6F1E4[i].unk_8 = 0;
            } else {
                lbl_1_bss_6F1E4[i].unk_8 = 5;
            }
        } else {
            lbl_1_bss_6F1E4[i].unk_8 = default_values[i];
        }
        fn_1_A2DF4(i, 0xA5000000, lbl_1_bss_6F1E4[i].unk_8);
    }
    fn_1_A2DF4(4, 0xA5000000, 0xA);
    fn_1_A2DF4(5, 0xA5000000, 9);
    fn_1_A2DF4(7, 0xA5000000, 6);
    fn_1_A2DF4(6, 0xA5000000, 7);

    for (j = 0; j < 16; j++) {
        fn_1_A2DF4(j, 0xA6000000, 0);
        fn_1_A2DF4(j, 0xA5100000, 0);
    }
    fn_1_4030(fn_1_35124);
}
/* fzgx:end fn_1_34F38 */

/* fzgx:begin fn_1_35124 */
void fn_1_35124(void) {
    OSGetTick();
    fn_1_A0978();
    OSGetTick();
}
/* fzgx:end fn_1_35124 */

/* fzgx:begin fn_1_3514C */
void fn_1_3514C(void* arg0, int arg1) {
    if (arg1 == 1) {
        fn_1_35174();
    }
}
/* fzgx:end fn_1_3514C */

/* fzgx:begin fn_1_35174 */
// fn_1_35174: empty in retail (single blr).
void fn_1_35174(void) {
}
/* fzgx:end fn_1_35174 */

/* fzgx:begin fn_1_35178 */
// Decrement the counter while the associated state is active.
void fn_1_35178(u32* arg0) {
    if (fn_1_3EFA8() == 0) {
        switch (lbl_1_bss_3C2A) {
        case 0x29:
            if ((lbl_1_bss_3C30.unk_0 & 0x00000800) == 0) {
                if (lbl_1_bss_3C30.unk_5 == 2) {
                    u32 value = -(*arg0);

                    if (lbl_1_bss_3C30.unk_14A8 != value) {
                        lbl_1_bss_3C30.unk_14A8 = value;
                    }
                    if (*(s16*)&lbl_1_bss_26B7A[0] == -1 ||
                        *(s16*)&lbl_1_bss_26300 == -1) {
                        lbl_1_bss_3C30.unk_5 = 6;
                    }
                }
                *arg0 -= 1;
            }
            break;
        default:
            break;
        }
    }
}
/* fzgx:end fn_1_35178 */

/* fzgx:begin fn_1_3522C pool noprologue */
#include "types.h"
#include "rel/main_rel/game.h"

extern void fn_1_81834(s8, s8, s8);
extern void fn_1_34AC0(s8 *, s8, s8, s32);
extern void fn_1_3181C(void);
extern void fn_1_584D4(void);
extern void *fn_1_435C(u32);
extern s32 fn_1_3F8C(void *, void *, void *, s32);
extern void fn_1_2C768(u32 *);
extern void fn_1_58694(void);
extern void fn_1_58C6C(void);
extern void fn_1_58994(void);
extern void fn_1_58D38(void);
extern void fn_1_128F10(void);
extern void fn_1_128F54(void);
extern void fn_1_12907C(void);
extern void *fn_1_7BA08(u32, u32, u32);
extern u32 fn_1_45D0(u32, void *, void *, s32);
extern void fn_1_7BA48(void);
extern void fn_1_7BAF8(void);
extern void fn_1_545B8(void);
extern void fn_1_7EAE8(void);
extern void camera_set_state_flag(u8);
extern void fn_1_5124(u32, u32);
extern s8 fn_1_5370(s8, s16);
extern void fn_1_9A578(void);
extern void fn_1_981C4(void);
extern void fn_1_98230(void);
extern void fn_1_9835C(void);
extern u32 fn_1_12AF50(u32);
extern u32 fn_1_82724(u32, u32, void *, u32, u32);
extern u32 fn_1_12AF64(void);
extern u32 fn_1_32A40(u32);
extern void fn_1_835E0(void *, u32, void *);
extern u32 fn_1_331EC(u32);
extern void fn_1_8176C(void *);
extern void fn_1_14A00C(void);
extern void fn_1_14A028(void);
extern void fn_1_15C36C(void);
extern u32 fn_1_8DBB0(void);
extern void fn_1_8DD54(void);
extern void fn_1_2F294(void);
extern u32 fn_1_4068C(void *);
extern void fn_1_408E8(void);
extern void fn_1_2D038(void);
extern void fn_80008BA8(void *, void *, u32);
extern u32 fn_80008E84(u32);
extern void fn_80008BEC(void *, int, u32);
extern u32 lbl_801A63C0;
/* read for its side effect only: retail reloads it after each of these calls */
extern volatile u32 lbl_801A6410;
extern const f32 lbl_1_rodata_BDC[];

/* The game-state objects of this TU's .bss, starting at lbl_1_bss_3C00.
 * Retail addresses them off one section base register, so they are
 * defined here in retail order. */
typedef struct {
    u32 flags;
    u8 pad_4;
    u8 mode;
    u8 pad_6[2];
    u8 humans;
    u8 total;
    u8 total2;
    u8 unk_B;
    u8 unk_C;
    u8 humans2;
    u8 order[0x14A8 - 0xE];
    u8 unk_14A8[0x14D0 - 0x14A8];
} GameObj30;

typedef struct {
    u8 pad_0[3];
    u8 flags;
    u8 pad_4[0x30 - 4];
} GameObj1508;

typedef struct {
    u16 unk_0;
    u8 unk_2;
    u8 unk_3;
    u8 pad_4[0xC];
    u16 unk_10;
    u16 unk_12;
    u8 pad_14[8];
    f32 unk_1C;
    u8 unk_20;
    u8 pad_21[0xE0 - 0x21];
    u8 unk_E0;
    u8 unk_E1;
    u8 unk_E2;
    u8 unk_E3;
    u8 unk_E4;
    u8 unk_E5;
    u8 pad_E6[5];
    u8 unk_EB;
    u8 pad_EC[0x104 - 0xEC];
} GameObj1538;

typedef struct {
    u8 b[5];
} GameEntry5;
extern u8 fn_1_382C4__fzgx_offset_0[];
extern u8 fn_1_384E8__fzgx_offset_0[];
extern u8 fn_1_385A4__fzgx_offset_0[];
extern u8 fn_1_3867C__fzgx_offset_0[];
extern u8 fn_1_38BBC__fzgx_offset_0[];
extern u8 fn_1_38CF4__fzgx_offset_0[];
extern u8 fn_1_3908C__fzgx_offset_0[];
extern u8 fn_1_391F0__fzgx_offset_0[];
extern u8 fn_1_39420__fzgx_offset_0[];
extern u8 fn_1_395CC__fzgx_offset_0[];
extern u8 fn_1_39C60__fzgx_offset_0[];
extern u8 fn_1_3A044__fzgx_offset_0[];
extern u8 fn_1_3A2C4__fzgx_offset_0[];
extern u8 fn_1_3A330__fzgx_offset_0[];
extern u8 fn_1_3AEC4__fzgx_offset_0[];
extern u8 fn_1_3B11C__fzgx_offset_0[];
extern u8 fn_1_3B7D4__fzgx_offset_0[];
extern u8 fn_1_3C880__fzgx_offset_0[];
extern u8 fn_1_3CDB0__fzgx_offset_0[];
extern u8 fn_1_3CE94__fzgx_offset_0[];
extern u8 fn_1_3DB9C__fzgx_offset_0[];
extern u8 fn_1_3DDAC__fzgx_offset_0[];
extern u8 fn_1_3DE80__fzgx_offset_0[];
extern u8 fn_1_3E5D0__fzgx_offset_0[];
extern u8 fn_1_3E628__fzgx_offset_0[];
extern u8 fn_1_3E62C__fzgx_offset_0[];
extern u8 fn_1_3E66C__fzgx_offset_0[];
extern u8 fn_1_3E670__fzgx_offset_0[];
extern u8 fn_1_3E6D8__fzgx_offset_0[];
extern u8 fn_1_3EA70__fzgx_offset_0[];
extern u8 lbl_1_data_5730__fzgx_offset_0[];
extern u8 lbl_1_data_573C__fzgx_offset_0[];
extern u8 lbl_1_data_5744__fzgx_offset_0[];
extern u8 lbl_1_data_5750__fzgx_offset_0[];
extern u8 lbl_1_data_5758__fzgx_offset_0[];
extern u8 lbl_1_data_5764__fzgx_offset_0[];
extern u8 lbl_1_data_576C__fzgx_offset_0[];
extern u8 lbl_1_data_5774__fzgx_offset_0[];
extern u8 lbl_1_data_5798__fzgx_offset_0[];
extern u8 lbl_1_data_579C__fzgx_offset_0[];
extern u8 lbl_1_data_57A8__fzgx_offset_0[];
extern u8 lbl_1_data_57B4__fzgx_offset_0[];
extern u8 lbl_1_data_57C0__fzgx_offset_0[];
extern u8 lbl_1_data_57CC__fzgx_offset_0[];
extern u8 lbl_1_data_57D4__fzgx_offset_0[];
extern u8 lbl_1_data_57DC__fzgx_offset_0[];
extern u8 lbl_1_data_57E4__fzgx_offset_0[];
extern u8 lbl_1_data_57EC__fzgx_offset_0[];
extern u8 lbl_1_data_57F8__fzgx_offset_0[];
extern u8 lbl_1_data_5808__fzgx_offset_0[];
extern u8 lbl_1_data_5818__fzgx_offset_0[];
extern u8 lbl_1_data_5820__fzgx_offset_0[];
extern u8 lbl_1_data_5828__fzgx_offset_0[];
extern u8 lbl_1_data_5834__fzgx_offset_0[];
extern u8 lbl_1_data_5840__fzgx_offset_0[];
extern u8 lbl_1_data_5850__fzgx_offset_0[];
extern u8 lbl_1_data_5858__fzgx_offset_0[];
extern u8 lbl_1_data_5864__fzgx_offset_0[];
extern u8 lbl_1_data_5870__fzgx_offset_0[];
extern u8 lbl_1_data_5880__fzgx_offset_0[];
extern u8 lbl_1_data_5888__fzgx_offset_0[];
extern u8 lbl_1_data_5894__fzgx_offset_0[];
extern u8 lbl_1_data_58A0__fzgx_offset_0[];
extern u8 lbl_1_data_58B0__fzgx_offset_0[];
extern u8 lbl_1_data_58B8__fzgx_offset_0[];
extern u8 lbl_1_data_58C4__fzgx_offset_0[];
extern u8 lbl_1_data_58CC__fzgx_offset_0[];
extern u8 lbl_1_data_58D8__fzgx_offset_0[];
extern u8 lbl_1_data_58E8__fzgx_offset_0[];
extern u8 lbl_1_data_58F4__fzgx_offset_0[];
extern u8 lbl_1_data_5900__fzgx_offset_0[];
extern u8 lbl_1_data_5908__fzgx_offset_0[];
extern u8 lbl_1_data_591C__fzgx_offset_0[];
extern u8 lbl_1_data_592C__fzgx_offset_0[];
extern u8 lbl_1_data_593C__fzgx_offset_0[];
extern u8 lbl_1_data_5948__fzgx_offset_0[];
extern u8 lbl_1_data_5954__fzgx_offset_0[];
extern u8 lbl_1_data_5964__fzgx_offset_0[];
extern u8 lbl_1_data_596C__fzgx_offset_0[];
extern u8 lbl_1_data_5978__fzgx_offset_0[];
extern u8 lbl_1_data_5980__fzgx_offset_0[];
extern u8 lbl_1_data_5988__fzgx_offset_0[];
extern u8 lbl_1_data_5990__fzgx_offset_0[];
extern u8 lbl_1_data_5A4C__fzgx_offset_0[];
extern u8 lbl_1_data_5A5C__fzgx_offset_0[];
extern u8 lbl_1_data_5A68__fzgx_offset_0[];
extern u8 lbl_1_data_5A74__fzgx_offset_0[];
extern u8 lbl_1_data_5A80__fzgx_offset_0[];
extern u8 lbl_1_data_5A88__fzgx_offset_0[];
extern u8 lbl_1_data_5A94__fzgx_offset_0[];
extern u8 lbl_1_data_5AA0__fzgx_offset_0[];
extern u8 lbl_1_data_5AAC__fzgx_offset_0[];
extern u8 lbl_1_data_5AB4__fzgx_offset_0[];
extern u8 lbl_1_data_5B94__fzgx_offset_0[];
extern u8 lbl_1_data_5BBC__fzgx_offset_0[];
extern u8 lbl_1_data_5BDC__fzgx_offset_0[];
extern u8 lbl_1_data_5C10__fzgx_offset_0[];
extern u8 lbl_1_data_5C6C__fzgx_offset_0[];
extern u8 lbl_1_data_5CC0__fzgx_offset_0[];
extern u8 lbl_1_data_5D1C__fzgx_offset_0[];
extern u8 lbl_1_data_5D78__fzgx_offset_0[];
extern u8 lbl_1_data_5DC8__fzgx_offset_0[];
extern u8 lbl_1_data_5E1C__fzgx_offset_0[];
extern u8 lbl_1_data_5E3C__fzgx_offset_0[];
extern u8 lbl_1_data_5E48__fzgx_offset_0[];
extern u8 lbl_1_data_5E58__fzgx_offset_0[];
extern u8 lbl_1_data_5E60__fzgx_offset_0[];
extern u8 lbl_1_data_5E70__fzgx_offset_0[];
extern u8 lbl_1_data_5E7C__fzgx_offset_0[];
extern u8 lbl_1_data_5E8C__fzgx_offset_0[];
extern u8 lbl_1_data_5E94__fzgx_offset_0[];
extern u8 lbl_1_data_5EA0__fzgx_offset_0[];
extern u8 lbl_1_data_5EAC__fzgx_offset_0[];
extern u8 lbl_1_data_5EB4__fzgx_offset_0[];
extern u8 lbl_1_data_5EC0__fzgx_offset_0[];
extern u8 lbl_1_data_5EC8__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_1_data_5730[275] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F564552, 0x54414B45, 0x0, 0x4A554D50, 0x0, 0x454E454D, 0x59484954, 0x0,
    0x57414C4C, 0x48495400, 0x53494445, 0x42595349, 0x44450000, 0x53544152, 0x54000000, 0x474F414C,
    0x0, 0x4C415000, (u32)lbl_1_data_5730__fzgx_offset_0, (u32)lbl_1_data_573C__fzgx_offset_0, (u32)lbl_1_data_5744__fzgx_offset_0, (u32)lbl_1_data_5750__fzgx_offset_0, (u32)lbl_1_data_5758__fzgx_offset_0, (u32)lbl_1_data_5764__fzgx_offset_0,
    (u32)lbl_1_data_576C__fzgx_offset_0, (u32)lbl_1_data_5774__fzgx_offset_0, 0x4E4F4E00, 0x4D415354, 0x45522052, 0x45435600, 0x4D415354, 0x45522053,
    0x454E4400, 0x534C4156, 0x45205345, 0x4E440000, 0x534C4156, 0x45205245, 0x43560000, 0x494E4954,
    0x0, 0x54455354, 0x0, 0x54455354, 0x454E4400, 0x53455455, 0x50000000, 0x53455455,
    0x505F444F, 0x4E450000, 0x53455455, 0x505F434F, 0x554E5445, 0x52000000, 0x53455455, 0x505F434E,
    0x545F444F, 0x4E450000, 0x554E4C49, 0x4E4B0000, 0x434F494E, 0x0, 0x454E5452, 0x595F5741,
    0x49540000, 0x4348414C, 0x4C454E47, 0x45520000, 0x4348414C, 0x4C454E47, 0x45525F4F, 0x4B000000,
    0x454E5452, 0x59000000, 0x454E5452, 0x595F4F4B, 0x0, 0x53494E47, 0x4C454348, 0x45434B00,
    0x53494E47, 0x4C454348, 0x45434B5F, 0x4F4B0000, 0x434F5552, 0x53450000, 0x434F5552, 0x53455F4F,
    0x4B000000, 0x434F5552, 0x53455F44, 0x41544100, 0x434F5552, 0x53455F44, 0x4154415F, 0x4F4B0000,
    0x4D414348, 0x494E4500, 0x4D414348, 0x494E455F, 0x4F4B0000, 0x434F4E46, 0x49470000, 0x434F4E46,
    0x49475F4F, 0x4B000000, 0x434F554E, 0x54455241, 0x444A5553, 0x54000000, 0x4C494E4B, 0x57414954,
    0x0, 0x4C494E4B, 0x57414954, 0x4F4B0000, 0x4C494E4B, 0x53454C00, 0x4C494E4B, 0x44454C49,
    0x56455259, 0x53544152, 0x54000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x0, 0x4C494E4B,
    0x44454C49, 0x56455259, 0x4F4B0000, 0x4C494E4B, 0x53454C4F, 0x4B000000, 0x434F5552, 0x53455649,
    0x45570000, 0x434F5552, 0x53455649, 0x45575F4F, 0x4B000000, 0x4C494E4B, 0x52455100, 0x4C494E4B,
    0x5354414E, 0x44425900, 0x4C494E4B, 0x4F4B0000, 0x4C494E4B, 0x0, 0x50415553, 0x45000000,
    0x4552524F, 0x52000000, (u32)lbl_1_data_5798__fzgx_offset_0, (u32)lbl_1_data_579C__fzgx_offset_0, (u32)lbl_1_data_57A8__fzgx_offset_0, (u32)lbl_1_data_57B4__fzgx_offset_0, (u32)lbl_1_data_57C0__fzgx_offset_0, (u32)lbl_1_data_57CC__fzgx_offset_0,
    (u32)lbl_1_data_57D4__fzgx_offset_0, (u32)lbl_1_data_57DC__fzgx_offset_0, (u32)lbl_1_data_57E4__fzgx_offset_0, (u32)lbl_1_data_57EC__fzgx_offset_0, (u32)lbl_1_data_57F8__fzgx_offset_0, (u32)lbl_1_data_5808__fzgx_offset_0, (u32)lbl_1_data_5818__fzgx_offset_0, (u32)lbl_1_data_5820__fzgx_offset_0,
    (u32)lbl_1_data_5828__fzgx_offset_0, (u32)lbl_1_data_5834__fzgx_offset_0, (u32)lbl_1_data_5840__fzgx_offset_0, (u32)lbl_1_data_5850__fzgx_offset_0, (u32)lbl_1_data_5858__fzgx_offset_0, (u32)lbl_1_data_5864__fzgx_offset_0, (u32)lbl_1_data_5870__fzgx_offset_0, (u32)lbl_1_data_5880__fzgx_offset_0,
    (u32)lbl_1_data_5888__fzgx_offset_0, (u32)lbl_1_data_5894__fzgx_offset_0, (u32)lbl_1_data_58A0__fzgx_offset_0, (u32)lbl_1_data_58B0__fzgx_offset_0, (u32)lbl_1_data_58B8__fzgx_offset_0, (u32)lbl_1_data_58C4__fzgx_offset_0, (u32)lbl_1_data_58CC__fzgx_offset_0, (u32)lbl_1_data_58D8__fzgx_offset_0,
    (u32)lbl_1_data_58E8__fzgx_offset_0, (u32)lbl_1_data_58F4__fzgx_offset_0, (u32)lbl_1_data_5900__fzgx_offset_0, (u32)lbl_1_data_5908__fzgx_offset_0, (u32)lbl_1_data_591C__fzgx_offset_0, (u32)lbl_1_data_592C__fzgx_offset_0, (u32)lbl_1_data_593C__fzgx_offset_0, (u32)lbl_1_data_5948__fzgx_offset_0,
    (u32)lbl_1_data_5954__fzgx_offset_0, (u32)lbl_1_data_5964__fzgx_offset_0, (u32)lbl_1_data_596C__fzgx_offset_0, (u32)lbl_1_data_5978__fzgx_offset_0, (u32)lbl_1_data_5980__fzgx_offset_0, (u32)lbl_1_data_5988__fzgx_offset_0, (u32)lbl_1_data_5990__fzgx_offset_0, 0x636F7572,
    0x73655F69, 0x6E74726F, 0x0, 0x63757374, 0x6F6D697A, 0x65000000, 0x636F7572, 0x73655F76,
    0x69657700, 0x72616365, 0x5F737461, 0x72740000, 0x72616365, 0x0, 0x72616365, 0x5F726573,
    0x756C7400, 0x6661696C, 0x5F726573, 0x756C7400, 0x70696C6F, 0x74706F69, 0x6E740000, 0x6F766572,
    0x0, 0x7469636B, 0x65740000, 0x0, 0x0, 0x0, 0x0, (u32)fn_1_382C4__fzgx_offset_0,
    (u32)fn_1_384E8__fzgx_offset_0, (u32)fn_1_385A4__fzgx_offset_0, (u32)lbl_1_data_5A4C__fzgx_offset_0, (u32)fn_1_3867C__fzgx_offset_0, (u32)fn_1_38BBC__fzgx_offset_0, (u32)fn_1_38CF4__fzgx_offset_0, (u32)lbl_1_data_5A5C__fzgx_offset_0, (u32)fn_1_3908C__fzgx_offset_0,
    (u32)fn_1_391F0__fzgx_offset_0, (u32)fn_1_39420__fzgx_offset_0, (u32)lbl_1_data_5A68__fzgx_offset_0, (u32)fn_1_395CC__fzgx_offset_0, (u32)fn_1_39C60__fzgx_offset_0, (u32)fn_1_3A044__fzgx_offset_0, (u32)lbl_1_data_5A74__fzgx_offset_0, (u32)fn_1_3A2C4__fzgx_offset_0,
    (u32)fn_1_3A330__fzgx_offset_0, (u32)fn_1_3AEC4__fzgx_offset_0, (u32)lbl_1_data_5A80__fzgx_offset_0, (u32)fn_1_3B11C__fzgx_offset_0, (u32)fn_1_3B7D4__fzgx_offset_0, (u32)fn_1_3C880__fzgx_offset_0, (u32)lbl_1_data_5A88__fzgx_offset_0, (u32)fn_1_3CDB0__fzgx_offset_0,
    (u32)fn_1_3CE94__fzgx_offset_0, (u32)fn_1_3DB9C__fzgx_offset_0, (u32)lbl_1_data_5A94__fzgx_offset_0, (u32)fn_1_3E628__fzgx_offset_0, (u32)fn_1_3E62C__fzgx_offset_0, (u32)fn_1_3E66C__fzgx_offset_0, (u32)lbl_1_data_5AA0__fzgx_offset_0, (u32)fn_1_3DDAC__fzgx_offset_0,
    (u32)fn_1_3DE80__fzgx_offset_0, (u32)fn_1_3E5D0__fzgx_offset_0, (u32)lbl_1_data_5AAC__fzgx_offset_0, (u32)fn_1_3E670__fzgx_offset_0, (u32)fn_1_3E6D8__fzgx_offset_0, (u32)fn_1_3EA70__fzgx_offset_0, (u32)lbl_1_data_5AB4__fzgx_offset_0, 0x43A00000,
    0x43200000, 0x43A00000, 0x438C0000
};
static u32 fzgx_pool_data_lbl_1_data_5B7C[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x1000000
};
static u32 fzgx_pool_data_lbl_1_data_5B80[475] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFFFFFFFF, 0x100FFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x54686973, 0x20726570, 0x6C617920,
    0x616E6420, 0x67686F73, 0x740A2063, 0x616E6E6F, 0x74206265, 0x20736176, 0x65642E00, 0x54686973,
    0x20726570, 0x6C617920, 0x63616E6E, 0x6F742062, 0x65207361, 0x7665642E, 0x0, 0x54686973,
    0x2067686F, 0x73742063, 0x616E6E6F, 0x74206265, 0x20736176, 0x65642E00, (u32)lbl_1_data_5B94__fzgx_offset_0, (u32)lbl_1_data_5BBC__fzgx_offset_0,
    (u32)lbl_1_data_5BDC__fzgx_offset_0, (u32)lbl_1_data_5B94__fzgx_offset_0, (u32)lbl_1_data_5BBC__fzgx_offset_0, (u32)lbl_1_data_5BDC__fzgx_offset_0, 0x4E657720, 0x70617274, 0x73206861, 0x7665206A,
    0x75737420, 0x61727269, 0x76656421, 0xA2F6263, 0x30306666, 0x66662F25, 0x732F6263, 0x66666666,
    0x66662F0A, 0x596F7520, 0x63616E20, 0x70757263, 0x68617365, 0x20746865, 0x6D20696E, 0x20746865,
    0x2073686F, 0x702E0000, (u32)lbl_1_data_5C10__fzgx_offset_0, 0x4D616368, 0x696E650A, 0x2F626330, 0x30666666, 0x662F2573,
    0x2F626366, 0x66666666, 0x662F0A68, 0x61732061, 0x72726976, 0x65642E0A, 0x596F7520, 0x63616E20,
    0x70757263, 0x68617365, 0x20697420, 0x61742074, 0x68652073, 0x686F702E, 0x0, (u32)lbl_1_data_5C6C__fzgx_offset_0,
    0x2F626330, 0x30666666, 0x662F2573, 0x2F626366, 0x66666666, 0x662F0A53, 0x74616666, 0x2047686F,
    0x73747320, 0x68617665, 0x20617272, 0x69766564, 0x2E0A596F, 0x75206361, 0x6E207075, 0x72636861,
    0x73652074, 0x68656D20, 0x61742074, 0x68652073, 0x686F702E, 0x0, (u32)lbl_1_data_5CC0__fzgx_offset_0, 0x2F626330,
    0x30666666, 0x662F2573, 0x2F626366, 0x66666666, 0x662F0A61, 0x72636164, 0x6520636F, 0x75727365,
    0x73206861, 0x76652061, 0x72726976, 0x65642E0A, 0x596F7520, 0x63616E20, 0x70757263, 0x68617365,
    0x20746865, 0x6D206174, 0x20746865, 0x2073686F, 0x702E0000, (u32)lbl_1_data_5D1C__fzgx_offset_0, 0x53746F72, 0x790A2F62,
    0x63303066, 0x6666662F, 0x25732F62, 0x63666666, 0x6666662F, 0xA686173, 0x20617272, 0x69766564,
    0x2E0A596F, 0x75206361, 0x6E207075, 0x72636861, 0x73652069, 0x74206174, 0x20746865, 0x2073686F,
    0x702E0000, (u32)lbl_1_data_5D78__fzgx_offset_0, 0x2F626330, 0x30666666, 0x662F2573, 0x2F626366, 0x66666666, 0x662F0A73,
    0x6F756E64, 0x73206861, 0x76652061, 0x72726976, 0x65642E0A, 0x596F7520, 0x63616E20, 0x70757263,
    0x68617365, 0x20746865, 0x6D206174, 0x20746865, 0x2073686F, 0x702E0000, (u32)lbl_1_data_5DC8__fzgx_offset_0, 0x596F7520,
    0x61637175, 0x69726564, 0x20256420, 0x5469636B, 0x6574732E, 0x0, (u32)lbl_1_data_5E1C__fzgx_offset_0, 0x436F6E74,
    0x696E7565, 0x0, 0x50726F63, 0x65656420, 0x746F204E, 0x65787400, 0x52657472, 0x79000000,
    0x4D697373, 0x696F6E20, 0x44697370, 0x6C617900, 0x53657474, 0x696E6773, 0x0, 0x53656C65,
    0x63742043, 0x6F757273, 0x65000000, 0x5265706C, 0x61790000, 0x53617665, 0x20526570, 0x6C617900,
    0x53617665, 0x2047686F, 0x73740000, 0x53746174, 0x75730000, 0x466F7263, 0x65205769, 0x6E000000,
    0x52657365, 0x74000000, 0x51756974, 0x0, (u32)lbl_1_data_5E3C__fzgx_offset_0, (u32)lbl_1_data_5E48__fzgx_offset_0, (u32)lbl_1_data_5E48__fzgx_offset_0, (u32)lbl_1_data_5E58__fzgx_offset_0,
    (u32)lbl_1_data_5E60__fzgx_offset_0, (u32)lbl_1_data_5E70__fzgx_offset_0, (u32)lbl_1_data_5E7C__fzgx_offset_0, (u32)lbl_1_data_5E8C__fzgx_offset_0, (u32)lbl_1_data_5E94__fzgx_offset_0, (u32)lbl_1_data_5EA0__fzgx_offset_0, (u32)lbl_1_data_5EAC__fzgx_offset_0, (u32)lbl_1_data_5EB4__fzgx_offset_0,
    (u32)lbl_1_data_5EC0__fzgx_offset_0, (u32)lbl_1_data_5EC8__fzgx_offset_0, 0x1000000, 0x436C6561, 0x72205363, 0x656E6172, 0x696F380A, 0x0,
    0x4E6F7420, 0x67657420, 0x5363656E, 0x6172696F, 0x39207965, 0x740A0000, 0x4E6F7420, 0x436C6561,
    0x72656420, 0x63757020, 0x25640A00, 0x67657420, 0x7363656E, 0x6172696F, 0x20390A00, 0x7265706C,
    0x61795F65, 0x7869745F, 0x67617000, 0x2F626337, 0x66666666, 0x662F5072, 0x6F6C6F67, 0x75652F62,
    0x63666666, 0x6666662F, 0x20202020, 0x20426C61, 0x636B2053, 0x6861646F, 0x77277320, 0x44697367,
    0x72616365, 0x0, 0x2F626337, 0x66666666, 0x662F4368, 0x61707465, 0x7220312F, 0x62636666,
    0x66666666, 0x2F202020, 0x20204361, 0x70746169, 0x6E204661, 0x6C636F6E, 0x20547261, 0x696E7300,
    0x2F626337, 0x66666666, 0x662F4368, 0x61707465, 0x7220322F, 0x62636666, 0x66666666, 0x2F202020,
    0x2020476F, 0x726F683A, 0x20546865, 0x2056656E, 0x67656675, 0x6C205361, 0x6D757261, 0x69000000,
    0x2F626337, 0x66666666, 0x662F4368, 0x61707465, 0x7220332F, 0x62636666, 0x66666666, 0x2F202020,
    0x20204869, 0x67682053, 0x74616B65, 0x7320696E, 0x204D7574, 0x65204369, 0x74790000, 0x2F626337,
    0x66666666, 0x662F4368, 0x61707465, 0x7220342F, 0x62636666, 0x66666666, 0x2F202020, 0x20204368,
    0x616C6C65, 0x6E676520, 0x6F662074, 0x68652042, 0x6C6F6F64, 0x79204368, 0x61696E00, 0x2F626337,
    0x66666666, 0x662F4368, 0x61707465, 0x7220352F, 0x62636666, 0x66666666, 0x2F202020, 0x20205361,
    0x7665204A, 0x6F647921, 0x0, 0x2F626337, 0x66666666, 0x662F4368, 0x61707465, 0x7220362F,
    0x62636666, 0x66666666, 0x2F202020, 0x2020426C, 0x61636B20, 0x53686164, 0x6F772773, 0x20547261,
    0x70000000, 0x2F626337, 0x66666666, 0x662F4368, 0x61707465, 0x7220372F, 0x62636666, 0x66666666,
    0x2F202020, 0x20205468, 0x6520462D, 0x5A45524F, 0x20477261, 0x6E642050, 0x72697800, 0x2F626337,
    0x66666666, 0x662F4368, 0x61707465, 0x7220382F, 0x62636666, 0x66666666, 0x2F202020, 0x20205365,
    0x63726574, 0x73206F66, 0x20746865, 0x20436861, 0x6D70696F, 0x6E204265, 0x6C740000, 0x2F626337,
    0x66666666, 0x662F4368, 0x61707465, 0x7220392F, 0x62636666, 0x66666666, 0x2F202020, 0x20204669,
    0x6E616C65, 0x3A20456E, 0x74657220, 0x74686520, 0x43726561, 0x746F7273, 0x0, 0x4D757465,
    0x20436974, 0x79000000, 0x42696720, 0x426C7565, 0x0, 0x839F0000, 0x746F5F67, 0x616D656F,
    0x7665725F, 0x6576656E, 0x74000000, 0x51756974, 0x74696E67, 0x20526570, 0x6C61792E, 0x204F4B3F,
    0x0, 0x51756974, 0x74696E67, 0x20477261, 0x6E642050, 0x7269782E, 0x0, 0x51756974,
    0x74696E67, 0x2054696D, 0x65204174, 0x7461636B, 0x2E000000, 0x51756974, 0x74696E67, 0x20746869,
    0x73207363, 0x656E6172, 0x696F2E00, 0x51756974, 0x74696E67, 0x20746865, 0x20726163, 0x652E0000,
    0x53746172, 0x74696E67, 0x20726163, 0x65206F76, 0x65722E00, 0x456E7465, 0x72696E67, 0x20536574,
    0x74696E67, 0x73207363, 0x7265656E, 0x2E000000, 0x456E7465, 0x72696E67, 0x2053656C, 0x65637420,
    0x436F7572, 0x73652073, 0x63726565, 0x6E2E0000, 0x53797374, 0x656D2072, 0x65736574, 0x0,
    0x59455300, 0x4E4F0000, 0x462D5A45, 0x524F2047, 0x58000000, 0x5B204D45, 0x4E55205D, 0x0,
    0x49732074, 0x68697320, 0x4F4B3F00
};
static u32 fzgx_pool_data_lbl_1_data_62EC[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x67616D65, 0x2E630000
};
static u32 fzgx_pool_data_lbl_1_data_62F4[72] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x47414D45, 0x3A206D65, 0x6E75206D, 0x61736B20, 0x6973207A, 0x65726F2E, 0xA000000, 0x47616D65,
    0x43616C63, 0x4C696768, 0x74000000, 0x43617243, 0x616C634C, 0x69676874, 0x0, 0x53746167,
    0x6543616C, 0x63000000, 0x4261636B, 0x47726F75, 0x6E644361, 0x6C630000, 0x466F674D, 0x61696E00,
    0x53746167, 0x65446973, 0x70000000, 0x4261636B, 0x47726F75, 0x6E644469, 0x73700000, 0x79616A69,
    0x72757368, 0x695F6469, 0x73700000, 0x50687973, 0x4F626A44, 0x69737000, 0x50687973, 0x4F626A50,
    0x6F737444, 0x69737000, 0x50687973, 0x53686164, 0x6F775072, 0x6552656E, 0x64000000, 0x50687973,
    0x4F626A43, 0x616C6300, 0x456E656D, 0x79546F74, 0x616C436F, 0x6E74726F, 0x6C4D6169, 0x6E000000,
    0x73657474, 0x696E675F, 0x67617000, 0x6E657874, 0x5F737461, 0x67655F67, 0x61700000, 0x47616D65,
    0x52657374, 0x6172745F, 0x67617000, 0x6361725F, 0x73746174, 0x75735F63, 0x6865636B, 0x0
};
static u8 fzgx_pool_data_lbl_1_data_6414[55] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x76, 0x65, 0x68, 0x69, 0x63, 0x6C, 0x65, 0x2F, 0, 0, 0, 0,
    0x63, 0x61, 0x72, 0x63, 0x6D, 0x6E, 0x74, 0x65, 0x78, 0x2E, 0x74, 0x70,
    0x6C, 0, 0, 0, 0x25, 0x73, 0x5F, 0x70, 0x2E, 0x61, 0x72, 0x63,
    0x2E, 0x6C, 0x7A, 0, 0x25, 0x73, 0x5F, 0x65, 0x2E, 0x61, 0x72, 0x63,
    0x2E, 0x6C, 0x7A, 0, 0x2E, 0x2E, 0
};
static u8 fzgx_pool_data_lbl_1_data_5730_D1B = 1; /* fzgx-allow: A1 retail byte */
static u32 fzgx_pool_data_lbl_1_data_5730_D1C[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4275726E, 0x65720000
};
static u32 fzgx_pool_data_lbl_1_data_5730_D24[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4275726E, 0x65724469, 0x73700000
};
static u32 fzgx_pool_data_lbl_1_data_5730_D30[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x47616D65, 0x52657375, 0x6C744374, 0x726C0000
};
static u32 fzgx_pool_data_lbl_1_data_5730_D40[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x47616D65, 0x52657375, 0x6C744469, 0x73700000
};
static u32 fzgx_pool_data_lbl_1_data_5730_D50[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x53657441, 0x6C6C4361, 0x724C4F44, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_5730_D60[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x64756D6D, 0x795F636F, 0x756E745F, 0x75700000
};
static u32 fzgx_pool_data_lbl_1_data_5730_D70[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45666665, 0x63740000
};
static u32 fzgx_pool_data_lbl_1_data_5730_D78[5] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45666665, 0x63744469, 0x73704265, 0x666F7265, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_5730_D8C[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45666665, 0x63744469, 0x73700000
};
static u32 fzgx_pool_data_lbl_1_data_5730_D98[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45666665, 0x63744469, 0x73704166, 0x74657200
};
static u32 fzgx_pool_data_lbl_1_data_5730_DA8[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x43686563, 0x6B000000
};
static u32 fzgx_pool_data_lbl_1_data_5730_DB0[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x43686563, 0x6B446973, 0x70000000
};
static u32 fzgx_pool_data_lbl_1_data_5730_DBC[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4C696768, 0x744D6169, 0x6E000000
};
static u32 fzgx_pool_data_lbl_1_data_5730_DC8[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x44726177, 0x4F726453, 0x79730000
};
static u32 fzgx_pool_data_lbl_1_data_5730_DD4[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x466F674F, 0x66660000
};
static u32 fzgx_pool_data_lbl_1_data_5730_DDC[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x67616D65, 0x5F6D656E, 0x755F6469, 0x73700000
};
static u32 fzgx_pool_data_lbl_1_data_5730_DEC[5] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x47616D65, 0x4D656E75, 0x57696467, 0x65744469, 0x73700000
};
static u32 fzgx_pool_data_lbl_1_data_5730_E00[46] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x64697370, 0x5F666169, 0x6C5F7265, 0x636F7264, 0x0, 0x46616365, 0x0, 0x46616365,
    0x44697370, 0x0, 0x52756D62, 0x6C654D61, 0x696E0000, 0x736F756E, 0x645F696E, 0x69740000,
    0x67616D65, 0x0, 0x74696D65, 0x5F636F75, 0x6E745F64, 0x65630000, 0x5265706C, 0x6179496E,
    0x666F4465, 0x636F6465, 0x0, 0x5265706C, 0x6179496E, 0x666F456E, 0x636F6465, 0x0,
    0x73746172, 0x745F636F, 0x756E7464, 0x6F776E00, 0x53746172, 0x74657200, 0x53746172, 0x74657244,
    0x69737000, 0x53746F72, 0x7947686F, 0x73745374, 0x61727444, 0x69737000
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_data_5730(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5B7C;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5B80;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_62EC;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_62F4;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_6414;
    s = fzgx_pool_data_lbl_1_data_5730_D1B;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_D1C;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_D24;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_D30;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_D40;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_D50;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_D60;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_D70;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_D78;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_D8C;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_D98;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_DA8;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_DB0;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_DBC;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_DC8;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_DD4;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_DDC;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_DEC;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_E00;
}
#pragma section code_type ".text"


u8 fzgx_obj_lbl_1_bss_3C00[4];
u8 fzgx_obj_3C04[0x20];
u32 fzgx_obj_3C24[3];
GameObj30 fzgx_obj_3C30;
u32 fzgx_obj_5100[2];
GameObj1508 fzgx_obj_5108;
GameObj1538 fzgx_obj_5138;
u8 fzgx_obj_523C[0x40];
/* objects of other functions, between 0x167C and 0x21F88 */
u8 fzgx_obj_527C[0x4000];
u8 fzgx_obj_927C[0x4000];
u8 fzgx_obj_D27C[0x4000];
u8 fzgx_obj_1127C[0x4000];
u8 fzgx_obj_1527C[0x4000];
u8 fzgx_obj_1927C[0x4000];
u8 fzgx_obj_1D27C[0x4000];
u8 fzgx_obj_2127C[0x4000];
u8 fzgx_obj_2527C[0x90C];
u32 fzgx_obj_25B88[(0x21FF0 - 0x21F88) / 4];
u32 fzgx_obj_25BF0[(0x22048 - 0x21FF0) / 4];
u16 fzgx_obj_25C48[(0x220A4 - 0x22048) / 2];
u32 fzgx_obj_25CA4[(0x220C8 - 0x220A4) / 4];
u32 fzgx_obj_25CC8[(0x2226C - 0x220C8) / 4];
u32 fzgx_obj_25E6C;
u32 fzgx_obj_25E70[2];
u32 fzgx_obj_25E78[(0x22298 - 0x22278) / 4];
u8 fzgx_obj_25E98[4];
u16 fzgx_obj_25E9C[(0x2265C - 0x2229C) / 2];
u8 fzgx_obj_2625C[0x226F8 - 0x2265C];
u32 fzgx_obj_262F8[(0x22F50 - 0x226F8) / 4];
u32 fzgx_obj_26B50[3];
u8 fzgx_obj_26B5C[0x22F7A - 0x22F5C];
u16 fzgx_obj_26B7A;
u8 fzgx_obj_26B7C[4];
GameEntry5 fzgx_obj_26B80[(0x23016 - 0x22F80) / 5];
u8 fzgx_obj_26C16;
u8 fzgx_obj_26C18[4];
u32 fzgx_obj_26C1C;

#pragma section code_type ".fzgxpool"
/* layout primer: first use fixes the .bss order to retail's */
void fzgx_primer_bss(volatile u32 *sink) {
    *sink = (u32)fzgx_obj_lbl_1_bss_3C00;
    *sink = (u32)fzgx_obj_3C04;
    *sink = (u32)fzgx_obj_3C24;
    *sink = (u32)&fzgx_obj_3C30;
    *sink = (u32)fzgx_obj_5100;
    *sink = (u32)&fzgx_obj_5108;
    *sink = (u32)&fzgx_obj_5138;
    *sink = (u32)fzgx_obj_523C;
    *sink = (u32)fzgx_obj_527C;
    *sink = (u32)fzgx_obj_927C;
    *sink = (u32)fzgx_obj_D27C;
    *sink = (u32)fzgx_obj_1127C;
    *sink = (u32)fzgx_obj_1527C;
    *sink = (u32)fzgx_obj_1927C;
    *sink = (u32)fzgx_obj_1D27C;
    *sink = (u32)fzgx_obj_2127C;
    *sink = (u32)fzgx_obj_2527C;
    *sink = (u32)fzgx_obj_25B88;
    *sink = (u32)fzgx_obj_25BF0;
    *sink = (u32)fzgx_obj_25C48;
    *sink = (u32)fzgx_obj_25CA4;
    *sink = (u32)fzgx_obj_25CC8;
    *sink = (u32)&fzgx_obj_25E6C;
    *sink = (u32)fzgx_obj_25E70;
    *sink = (u32)fzgx_obj_25E78;
    *sink = (u32)fzgx_obj_25E98;
    *sink = (u32)fzgx_obj_25E9C;
    *sink = (u32)fzgx_obj_2625C;
    *sink = (u32)fzgx_obj_262F8;
    *sink = (u32)fzgx_obj_26B50;
    *sink = (u32)fzgx_obj_26B5C;
    *sink = (u32)&fzgx_obj_26B7A;
    *sink = (u32)fzgx_obj_26B7C;
    *sink = (u32)fzgx_obj_26B80;
    *sink = (u32)&fzgx_obj_26C16;
    *sink = (u32)fzgx_obj_26C18;
    *sink = (u32)&fzgx_obj_26C1C;
}
#pragma section code_type ".text"

void fn_1_3522C(void) {
    struct { s32 value; } n;
    u8 humans;
    struct { u8 value; } total;
    struct { s32 value; } i;
    s32 random;
    void *created;

    humans = fzgx_obj_lbl_1_bss_3C00[0];
    total.value = fzgx_obj_3C30.total;
    fzgx_obj_3C30.humans = humans;
    if (total.value > 30) {
        fzgx_obj_3C30.total = 30;
    } else if (humans > total.value) {
        fzgx_obj_3C30.total = humans;
    }
    i.value = 0;
    fzgx_obj_3C30.total2 = fzgx_obj_3C30.total;
    fzgx_obj_3C30.unk_B = i.value;
    fzgx_obj_3C30.unk_C = i.value;
    fzgx_obj_3C30.mode = (*((char *)fzgx_pool_data_lbl_1_data_5B7C));
    fzgx_obj_3C30.humans2 = fzgx_obj_3C30.humans;
    for (; i.value < fzgx_obj_3C30.total; i.value++) {
        fzgx_obj_3C30.order[i.value] = i.value;
    }
    if (lbl_1_bss_960 == 12 || lbl_1_bss_962 == 160) {
        for (n.value = 0; n.value < fzgx_obj_lbl_1_bss_3C00[0]; n.value++) {
            fn_1_81834(n.value, fzgx_obj_25E98[n.value], n.value);
        }
        for (i.value = fzgx_obj_lbl_1_bss_3C00[0]; i.value < fzgx_obj_3C30.total; i.value++) {
            fzgx_obj_2625C[i.value] = fzgx_obj_26B80[i.value].b[1];
            fzgx_obj_523C[i.value] = 0x10;
        }
    } else {
        if (fzgx_obj_lbl_1_bss_3C00[0]) {
            for (n.value = 0; n.value < fzgx_obj_lbl_1_bss_3C00[0]; n.value++) {
                fn_1_81834(n.value, fzgx_obj_25E98[n.value], n.value);
            }
        } else {
            fn_1_81834(0, -1, 0);
            if (lbl_1_bss_960 == 2) {
                fzgx_obj_2625C[0] = 6;
            } else if (lbl_1_bss_960 == 10) {
                if (fzgx_pool_data_lbl_1_data_5730_D1B) {
                    fzgx_obj_2625C[0] = 6;
                    fzgx_pool_data_lbl_1_data_5730_D1B = 0;
                } else {
                    lbl_801A63C0 = lbl_801A63C0 * 0x676a4b6b + 0x33cb;
                    random = (lbl_801A63C0 >> 16) & 0x7fff;
                    fzgx_obj_2625C[0] = random % (s32)fzgx_obj_3C30.total;
                }
            } else {
                lbl_801A63C0 = lbl_801A63C0 * 0x676a4b6b + 0x33cb;
                random = (lbl_801A63C0 >> 16) & 0x7fff;
                fzgx_obj_2625C[0] = random % (s32)fzgx_obj_3C30.total;
            }
            fzgx_obj_523C[0] = 0x10;
            fzgx_obj_25C48[0] = 50;
        }
        if (lbl_1_bss_960 == 2 && (u8)(*((char *)fzgx_pool_data_lbl_1_data_5B7C)) == 1) {
            fn_80008BA8(fzgx_obj_2625C, fzgx_obj_26B5C, 30);
        } else {
            fn_1_34AC0((s8 *)fzgx_obj_2625C, (s8)(fzgx_obj_lbl_1_bss_3C00[0] + fzgx_obj_26B7C[0]),
                       (s8)fzgx_obj_3C30.total, 0);
        }
    }
    fn_1_3181C();
    lbl_801A6410;
    if (fzgx_obj_3C30.humans < 2 && lbl_1_bss_960 != 10 && lbl_1_bss_960 != 12) {
        fzgx_obj_25CC8[0] = 1;
    } else {
        fzgx_obj_25CC8[0] = 0;
    }
    fn_1_584D4();
    fn_1_435C(fzgx_obj_25B88[0]);
    fzgx_obj_26B7A = fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_D60), fn_1_2C768, fzgx_obj_3C30.unk_14A8, 13);
    if (!(fzgx_obj_3C30.flags & 0x1000000)) {
        fn_1_435C(fzgx_obj_25B88[0]);
        fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_D70), fn_1_58694, 0, 11);
        fn_1_435C(fzgx_obj_25CA4[0]);
        fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_D78), fn_1_58C6C, 0, 0);
        fn_1_435C(fzgx_obj_25CA4[0]);
        fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_D8C), fn_1_58994, 0, 22);
        fn_1_435C(fzgx_obj_25CA4[0]);
        fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_D98), fn_1_58D38, 0, 27);
    }
    if (lbl_1_bss_960 != 10 && lbl_1_bss_960 != 12) {
        fn_1_128F10();
        fn_1_435C(fzgx_obj_25B88[0]);
        fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_DA8), fn_1_128F54, 0, 12);
        fn_1_435C(fzgx_obj_25CA4[0]);
        fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_DB0), fn_1_12907C, 0, 22);
        lbl_801A6410;
    }
    created = fn_1_7BA08(32, 32, 64);
    fzgx_obj_3C24[0] = fn_1_45D0(lbl_801A6410, created, ((char *)fzgx_pool_data_lbl_1_data_62EC), 0x17af);
    fn_1_7BA48();
    fn_1_435C(fzgx_obj_25CA4[0]);
    fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_DBC), fn_1_7BAF8, (void *)fzgx_obj_3C24[0], 3);
    lbl_801A6410;
    fn_1_435C(fzgx_obj_25CA4[0]);
    fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_DC8), fn_1_545B8, 0, 25);
    fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_DD4), fn_1_7EAE8, 0, 29);
    camera_set_state_flag(1);
    fn_1_5124(fzgx_obj_25B88[0], fzgx_obj_25CA4[0]);
    fn_1_5370(3, 0);
    lbl_801A6410;
    fn_1_9A578();
    if (lbl_1_bss_960 == 10 || (lbl_1_bss_960 == 2 && (u8)(*((char *)fzgx_pool_data_lbl_1_data_5B7C)) == 1)) {
        struct { u32 value; } saved;
        saved.value = fn_80008E84(fzgx_obj_262F8[0]);
        fn_1_981C4();
        lbl_801A6410;
        fn_1_435C(fzgx_obj_25B88[0]);
        fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_D1C), fn_1_98230, 0, 10);
        fn_1_435C(fzgx_obj_25CA4[0]);
        fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_D24), fn_1_9835C, 0, 21);
        fn_1_12AF50(saved.value);
        fn_1_82724(fzgx_obj_25B88[0], fzgx_obj_25CA4[0], fzgx_obj_25E9C, fzgx_obj_3C30.total, 1);
        fn_1_12AF64();
        fn_1_835E0(&fzgx_obj_3C30, fzgx_obj_25B88[0], fn_1_32A40);
        fn_1_8176C(fn_1_331EC);
        fn_80008E84(saved.value);
        fn_1_14A00C();
        fn_1_435C(fzgx_obj_25B88[0]);
        fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_D30), fn_1_14A028, &fzgx_obj_3C30, 25);
        fn_1_435C(fzgx_obj_25CA4[0]);
        fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_D40), fn_1_15C36C, &fzgx_obj_3C30, 28);
        fn_1_435C(fzgx_obj_25CA4[0]);
        fn_1_8DBB0();
        fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_D50), fn_1_8DD54, 0, 1);
    }
    fzgx_obj_26C1C = 1;
    fzgx_obj_26B50[0] = 0;
    fzgx_obj_25E6C = 0;
    fzgx_obj_25E70[0] = 0;
    fzgx_obj_25E78[0] = 0;
    fzgx_obj_25BF0[0] = 0;
    fzgx_obj_26C16 = 0;
    fn_1_435C(fzgx_obj_5100[0]);
    fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_DDC), fn_1_2F294, 0, 30);
    fn_1_4068C(&fzgx_obj_5108);
    fzgx_obj_5108.flags &= ~1;
    fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_DEC), fn_1_408E8, &fzgx_obj_5108, 30);
    fn_80008BEC(&fzgx_obj_5138, 0, 0xec);
    fzgx_obj_5138.unk_10 = 320;
    fzgx_obj_5138.unk_12 = 180;
    fzgx_obj_5138.unk_E1 = 0;
    fzgx_obj_5138.unk_E0 = 0;
    fzgx_obj_5138.unk_0 = 0;
    fzgx_obj_5138.unk_2 = 0;
    fzgx_obj_5138.unk_3 = 0;
    fzgx_obj_5138.unk_1C = lbl_1_rodata_BDC[0];
    fzgx_obj_5138.unk_20 = 0;
    fzgx_obj_5138.unk_E2 = 0;
    fzgx_obj_5138.unk_E3 = 255;
    fzgx_obj_5138.unk_E4 = 0;
    fzgx_obj_5138.unk_E5 = 255;
    fzgx_obj_5138.unk_EB = 255;
    fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_E00), fn_1_2D038, 0, 1);
}
/* fzgx:end fn_1_3522C */

/* fzgx:begin fn_1_36A94 */
// Clears one indexed 0x81c0-byte entry in the shared buffer.
void fn_1_36A94(u32 arg0, u32 arg1) {
    u8 *entry = lbl_1_bss_5480;
    u32 stride = 0x81c0;
    u32 offset = (arg0 & 0xFF) * stride;

    fn_80008BA8( (u32)(void *)(entry + offset), (u32)((void *)arg1), stride);
}
/* fzgx:end fn_1_36A94 */

/* fzgx:begin fn_1_36AD0 */
u8* fn_1_36AD0(void) {
    return lbl_1_bss_5480;
}
/* fzgx:end fn_1_36AD0 */

/* fzgx:begin fn_1_36ADC */
void fn_1_36ADC(void) {
    fn_80008BEC(lbl_1_bss_5480, (int)(void *)(0), 0x20700);
}
/* fzgx:end fn_1_36ADC */

/* fzgx:begin fn_1_384E8 pool */
typedef struct {
    u8 pad_0[6];
    u8 unk_6;
} Sub30;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_3C00;
u32 fzgx_obj_lbl_1_bss_3C04;
u32 lbl_1_bss_3C08[2];
u8 lbl_1_bss_3C10;
u8 fzgx_obj_lbl_1_bss_3C11;
u16 fzgx_obj_lbl_1_bss_3C12;
u32 lbl_1_bss_3C12_fill_3C14[2];
u32 fzgx_obj_lbl_1_bss_3C1C[3];
u16 lbl_1_bss_3C1C_fill_3C28;
u16 fzgx_obj_lbl_1_bss_3C2A;
u32 lbl_1_bss_3C2A_fill_3C2C;
u8 fzgx_obj_lbl_1_bss_3C30;
u8 lbl_1_bss_3C30_fill_3C31;
u16 lbl_1_bss_3C30_fill_3C32;
u32 lbl_1_bss_3C30_fill_3C34[1325];
s16 lbl_1_bss_3C30_14B8;
u16 lbl_1_bss_3C30_fill_50EA;
u32 fzgx_obj_lbl_1_bss_50EC[5];
void *fzgx_obj_lbl_1_bss_5100;
u8 lbl_1_bss_5100_fill_5101;
u16 lbl_1_bss_5100_fill_5102;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C00;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C04;
    s = *(u8 *)&lbl_1_bss_3C08;
    s = *(u8 *)&lbl_1_bss_3C10;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C11;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C12;
    s = *(u8 *)&lbl_1_bss_3C12_fill_3C14;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C1C;
    s = *(u8 *)&lbl_1_bss_3C1C_fill_3C28;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C2A;
    s = *(u8 *)&lbl_1_bss_3C2A_fill_3C2C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C30;
    s = *(u8 *)&lbl_1_bss_3C30_fill_3C31;
    s = *(u8 *)&lbl_1_bss_3C30_fill_3C32;
    s = *(u8 *)&lbl_1_bss_3C30_fill_3C34;
    s = *(u8 *)&lbl_1_bss_3C30_14B8;
    s = *(u8 *)&lbl_1_bss_3C30_fill_50EA;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_50EC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5100;
    s = *(u8 *)&lbl_1_bss_5100_fill_5101;
    s = *(u8 *)&lbl_1_bss_5100_fill_5102;
}
#pragma section code_type ".text"

void fn_1_384E8(void) {
    
    fn_1_12F308();
    if (fn_1_4C10() == 0) {
        fn_1_12F358(((Sub30 *)&fzgx_obj_lbl_1_bss_3C30)->unk_6);
        if ((s32)lbl_1_bss_26C28 == 2) {
            if ((int)fn_1_467F4() == 0) {
                fn_1_4A00(0, 0x1e, (u32)(void *)(fzgx_obj_lbl_1_bss_5100));
                lbl_1_bss_26C28 = 1;
            }
        } else if ((s32)lbl_1_bss_26C28 != 0) {
            lbl_1_bss_3C30_14B8 = 0x26;
        } else if (fn_1_402D4() != 0) {
            fn_1_A2D84(0xa9010100);
            lbl_1_bss_26C28 = 2;
        }
    }
}
/* fzgx:end fn_1_384E8 */

/* fzgx:begin fn_1_3908C */
void fn_1_3908C(void) {
    u8 inRange;
    s32 count;

    fn_1_435C(lbl_1_bss_25B88.unk_0);
    fn_1_4310(-1);
    fn_1_435C(lbl_1_bss_25CA4.unk_0);
    fn_1_4310(-1);
    fn_1_8616C();

    switch (lbl_1_bss_3C30.unk_6) {
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
        inRange = 1;
        break;
    default:
        inRange = 0;
        break;
    }

    fn_1_A11EC();
    fn_1_D0790();
    *(s8 *)&lbl_1_bss_5104.unk_0 = -1;

    count = fn_1_101C0();
    lbl_1_bss_26C28 = count;
    if (count < 0) {
        lbl_1_bss_26C28 = 0xF0;
    }

    if (*(s16 *)&lbl_1_bss_960 == 9 || inRange) {
        lbl_1_bss_26C28 = 350;
        fn_1_A1588(lbl_1_bss_6EAD0.unk_0->unk_0, 7);
    } else {
        fn_1_A1588(lbl_1_bss_6EAD0.unk_0->unk_0, 6);
    }

    lbl_1_bss_3C30.unk_1474 = 0;
    lbl_1_bss_381F5 = 1;
    ADXT_Pause( (Sig_ADXT_Pause_ADXTHandle *)((void *)lbl_1_bss_6EAD0.unk_0->unk_0), 1);

    if (lbl_1_bss_3C30.unk_5 == 1) {
        fn_1_48004(0xBB, 1);
    }
}
/* fzgx:end fn_1_3908C */

/* fzgx:begin fn_1_3A044 pool */
extern u32 fn_1_435C(u32 value);
extern void fn_1_426C(u32 idx);
extern void fn_1_A8F78(void);
extern void fn_1_1547FC();
extern void fn_1_C47B4(void);
extern void fn_1_C6F80(u8);
extern void fn_1_79100(void);
extern void fn_1_412A0(u32);
extern void fn_1_E35F0(void);
extern void fn_1_105724(void);
extern void fn_1_F2EDC(void);
extern u32 fn_80008E84(u32);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_3C00;
u32 fzgx_obj_lbl_1_bss_3C04;
u32 fzgx_obj_lbl_1_bss_3C08[2];
u8 fzgx_obj_lbl_1_bss_3C10;
u8 fzgx_obj_lbl_1_bss_3C11;
u16 fzgx_obj_lbl_1_bss_3C12;
u32 fzgx_obj_lbl_1_bss_3C14;
u32 fzgx_obj_lbl_1_bss_3C18;
u8 fzgx_obj_lbl_1_bss_3C1C[0x14];
u8 fzgx_obj_lbl_1_bss_3C30[0x14B8];
s16 fzgx_obj_lbl_1_bss_50E8;
u16 fzgx_obj_lbl_1_bss_50EA;
u8 fzgx_obj_lbl_1_bss_50EC[0x394];
u8 fzgx_obj_lbl_1_bss_5480[0x20700];
u32 fzgx_obj_lbl_1_bss_25B80[2];
u32 fzgx_obj_lbl_1_bss_25B88;
u32 fzgx_obj_lbl_1_bss_25B8C[7];
u8 fzgx_obj_lbl_1_bss_25BA8[0x20];
u8 fzgx_obj_lbl_1_bss_25BC8[0x20];
u8 fzgx_obj_lbl_1_bss_25BE8[0xBC];
u32 fzgx_obj_lbl_1_bss_25CA4;
u32 fzgx_obj_lbl_1_bss_25CA8;
u32 fzgx_obj_lbl_1_bss_25CAC;
u32 fzgx_obj_lbl_1_bss_25CB0;
u32 fzgx_obj_lbl_1_bss_25CB4;
u32 fzgx_obj_lbl_1_bss_25CB8;
u32 fzgx_obj_lbl_1_bss_25CBC;
u32 fzgx_obj_lbl_1_bss_25CC0;
u32 fzgx_obj_lbl_1_bss_25CC4;
u32 fzgx_obj_lbl_1_bss_25CC8;
u32 fzgx_obj_lbl_1_bss_25CCC;
u8 fzgx_obj_lbl_1_bss_25CD0[0x184];
u32 fzgx_obj_lbl_1_bss_25E54;
u32 fzgx_obj_lbl_1_bss_25E58;
u32 fzgx_obj_lbl_1_bss_25E5C;
u32 fzgx_obj_lbl_1_bss_25E60;
u32 fzgx_obj_lbl_1_bss_25E64;
u32 fzgx_obj_lbl_1_bss_25E68;
s32 fzgx_obj_lbl_1_bss_25E6C;
s32 fzgx_obj_lbl_1_bss_25E70;
u32 fzgx_obj_lbl_1_bss_25E74;
u32 fzgx_obj_lbl_1_bss_25E78;
s32 fzgx_obj_lbl_1_bss_25E7C;
s32 fzgx_obj_lbl_1_bss_25E80;
s32 fzgx_obj_lbl_1_bss_25E84;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C00;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C04;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C08;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C10;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C11;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C12;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C14;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C18;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C1C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C30;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_50E8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_50EA;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_50EC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5480;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25B80;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25B88;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25B8C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25BA8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25BC8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25BE8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25CA4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25CA8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25CAC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25CB0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25CB4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25CB8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25CBC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25CC0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25CC4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25CC8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25CCC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25CD0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25E54;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25E58;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25E5C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25E60;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25E64;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25E68;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25E6C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25E70;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25E74;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25E78;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25E7C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25E80;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25E84;
}
#pragma section code_type ".text"

static inline void copy_rows(void) {
    s32 i;

    for (i = 0; i < fzgx_obj_lbl_1_bss_3C30[0x9]; i++) {
        u8 *p = fzgx_obj_lbl_1_bss_3C30 + i * 0xa0 + 0xd4;
        p[fzgx_obj_lbl_1_bss_3C30[0xa7] + 0xe] = fzgx_obj_lbl_1_bss_25BA8[i];
        p[fzgx_obj_lbl_1_bss_3C30[0xa7] + 0x13] = fzgx_obj_lbl_1_bss_25BC8[i];
    }
}

void fn_1_3A044(void) {
    u32 saved;

    if ((s32)lbl_1_bss_381F8 != -1) {
        fn_1_435C(fzgx_obj_lbl_1_bss_25CA4);
        fn_1_426C(lbl_1_bss_381F8);
    }
    fn_1_A8F78();
    if (fzgx_obj_lbl_1_bss_25E6C != 0) {
        fzgx_obj_lbl_1_bss_25E70 = 1;
    }
    if (fzgx_obj_lbl_1_bss_25E70 != 0) {
        copy_rows();
        *(u32 *)(fzgx_obj_lbl_1_bss_3C30 + 0x1464) = 0;
        fzgx_obj_lbl_1_bss_3C30[0x146c] = 0;
        fzgx_obj_lbl_1_bss_3C30[0x146d] = 0;
        fzgx_obj_lbl_1_bss_3C30[0x1470] = 0;
        *(u16 *)(fzgx_obj_lbl_1_bss_3C30 + 0x146e) = 1500;
        fn_1_1547FC();
        fn_1_C47B4();
        fn_1_435C(fzgx_obj_lbl_1_bss_25B88);
        if (fzgx_obj_lbl_1_bss_3C14 != 0) {
            fn_1_426C(fzgx_obj_lbl_1_bss_3C14);
            fzgx_obj_lbl_1_bss_3C14 = 0;
        }
        fn_1_435C(fzgx_obj_lbl_1_bss_25CA4);
        if (fzgx_obj_lbl_1_bss_3C18 != 0) {
            fn_1_426C(fzgx_obj_lbl_1_bss_3C18);
            fzgx_obj_lbl_1_bss_3C18 = 0;
        }
        fn_1_C6F80(0);
        saved = fn_80008E84(fzgx_obj_lbl_1_bss_25CCC);
        fn_1_79100();
        fn_80008E84(saved);
        fn_1_412A0(2);
        fn_1_E35F0();
        fn_1_435C(fzgx_obj_lbl_1_bss_25B88);
        fn_1_426C(fzgx_obj_lbl_1_bss_25CB4);
        fn_1_426C(fzgx_obj_lbl_1_bss_25CB8);
        fn_1_426C(fzgx_obj_lbl_1_bss_25E64);
        fn_1_435C(fzgx_obj_lbl_1_bss_25CA4);
        fn_1_426C(fzgx_obj_lbl_1_bss_25CA8);
        fn_1_426C(fzgx_obj_lbl_1_bss_25CAC);
        fn_1_426C(fzgx_obj_lbl_1_bss_25CB0);
        fn_1_426C(fzgx_obj_lbl_1_bss_25CBC);
        fn_1_426C(fzgx_obj_lbl_1_bss_25CC0);
        fn_1_426C(fzgx_obj_lbl_1_bss_25CC4);
        fn_1_426C(fzgx_obj_lbl_1_bss_25E58);
        fn_1_426C(fzgx_obj_lbl_1_bss_25E5C);
        fn_1_426C(fzgx_obj_lbl_1_bss_25E60);
        fn_1_426C(fzgx_obj_lbl_1_bss_25E54);
    }
    if (fzgx_obj_lbl_1_bss_25E6C != 0) {
        fzgx_obj_lbl_1_bss_3C30[0xa7]++;
    }
    if (fzgx_obj_lbl_1_bss_50E8 != 0x29) {
        fn_1_435C(fzgx_obj_lbl_1_bss_25B88);
        if (fzgx_obj_lbl_1_bss_25E7C != -1) {
            fn_1_426C(fzgx_obj_lbl_1_bss_25E7C);
        }
        if (fzgx_obj_lbl_1_bss_25E80 != -1) {
            fn_1_426C(fzgx_obj_lbl_1_bss_25E80);
            fn_1_105724();
        }
        fn_1_435C(fzgx_obj_lbl_1_bss_25CA4);
        if (fzgx_obj_lbl_1_bss_25E84 != -1) {
            fn_1_426C(fzgx_obj_lbl_1_bss_25E84);
        }
        fzgx_obj_lbl_1_bss_25E7C = -1;
        fzgx_obj_lbl_1_bss_25E80 = -1;
        fzgx_obj_lbl_1_bss_25E84 = -1;
        if (*(u32 *)fzgx_obj_lbl_1_bss_3C30 & 0x800000) {
            fn_1_F2EDC();
        }
    }
}
/* fzgx:end fn_1_3A044 */

/* fzgx:begin fn_1_3A2C4 */
void fn_1_3A2C4(void) {
    s64 time;
    u32 lo, hi;

    fn_1_817C0();
    lbl_1_bss_381FC = 0;
    fn_1_EB080(1);
    time = OSGetTime();
    lo = (u32)time;
    hi = (u32)(time >> 32);
    lbl_1_bss_3C30.unk_14A4 = lo;
    lbl_1_bss_3C30.unk_14A0 = hi;
    lbl_1_bss_3C30.unk_1494 = lo;
    lbl_1_bss_3C30.unk_1490 = hi;
    lbl_1_bss_3C30.unk_149C = 0;
    lbl_1_bss_3C30.unk_1498 = 0;
    lbl_1_bss_38200 = 0xff;
}
/* fzgx:end fn_1_3A2C4 */

/* fzgx:begin fn_1_3AEC4 pool */
extern u32 fn_1_435C(u32 value);
extern void fn_1_426C(u32 idx);
extern void fn_1_105724(void);
extern void fn_1_F2EDC(void);
extern void fn_1_A8F78(void);
extern void fn_1_1547FC(void);
extern void fn_1_C47B4(void);
extern void fn_1_C6F80(u8);
extern void fn_1_79100(void);
extern void fn_1_412A0(u32);
extern void fn_1_E35F0(void);
extern u32 fn_80008E84(u32);
extern void fzgx_touch(void *);

typedef struct {
    u8 b[0xa0];
} GameRacerSlot;

typedef struct {
    u32 flags;               /* 0x00 */
    u8 pad04[0x5];
    u8 count;                /* 0x09 */
    u8 pad0A[0xa7 - 0xa];
    u8 slot;                 /* 0xa7 */
    u8 padA8[0xd4 - 0xa8];
    GameRacerSlot ents[31];  /* 0xd4 */
    u8 pad1434[0x1464 - 0x1434];
    s32 unk_1464;
    u8 pad1468[4];
    u8 unk_146c;
    u8 unk_146d;
    s16 unk_146e;
    u8 unk_1470;
    u8 pad1471[0x14b8 - 0x1471];
} GameRaceState;

/* game.c .bss, laid out from 0x3C00 in retail order */
static u32 fzgx_obj_lbl_1_bss_3C00;
static u8 bss_0004[0x10];
static u32 bss_0014;
static u32 bss_0018;
static u8 bss_001C[0x14];
static GameRaceState bss_0030;
static s16 bss_14E8;
static u8 bss_14EC[0x21f88 - 0x14ec];
static u32 bss_21F88;
static u8 bss_21F8C[0x1c];
static u8 bss_21FA8[0x20];
static u8 bss_21FC8[0x220a4 - 0x21fc8];
static u32 bss_220A4;
static u32 bss_220A8;
static u32 bss_220AC;
static u32 bss_220B0;
static u32 bss_220B4;
static u32 bss_220B8;
static u32 bss_220BC;
static u32 bss_220C0;
static u32 bss_220C4;
static u32 bss_220C8;
static u32 bss_220CC;
static u8 bss_220D0[0x22254 - 0x220d0];
static u32 bss_22254;
static u32 bss_22258;
static u32 bss_2225C;
static u32 bss_22260;
static u32 bss_22264;
static u32 bss_22268;
static s32 bss_2226C;
static s32 bss_22270;
static u8 bss_22274[8];
static s32 bss_2227C;
static s32 bss_22280;
static s32 bss_22284;

void fzgx_primer(void) {
    fzgx_touch(&fzgx_obj_lbl_1_bss_3C00);
    fzgx_touch(&bss_0004);
    fzgx_touch(&bss_0014);
    fzgx_touch(&bss_0018);
    fzgx_touch(&bss_001C);
    fzgx_touch(&bss_0030);
    fzgx_touch(&bss_14E8);
    fzgx_touch(&bss_14EC);
    fzgx_touch(&bss_21F88);
    fzgx_touch(&bss_21F8C);
    fzgx_touch(&bss_21FA8);
    fzgx_touch(&bss_21FC8);
    fzgx_touch(&bss_220A4);
    fzgx_touch(&bss_220A8);
    fzgx_touch(&bss_220AC);
    fzgx_touch(&bss_220B0);
    fzgx_touch(&bss_220B4);
    fzgx_touch(&bss_220B8);
    fzgx_touch(&bss_220BC);
    fzgx_touch(&bss_220C0);
    fzgx_touch(&bss_220C4);
    fzgx_touch(&bss_220C8);
    fzgx_touch(&bss_220CC);
    fzgx_touch(&bss_220D0);
    fzgx_touch(&bss_22254);
    fzgx_touch(&bss_22258);
    fzgx_touch(&bss_2225C);
    fzgx_touch(&bss_22260);
    fzgx_touch(&bss_22264);
    fzgx_touch(&bss_22268);
    fzgx_touch(&bss_2226C);
    fzgx_touch(&bss_22270);
    fzgx_touch(&bss_22274);
    fzgx_touch(&bss_2227C);
    fzgx_touch(&bss_22280);
    fzgx_touch(&bss_22284);
}

static inline void fn_1_3AEC4_copy_slots(void) {
    s32 i;

    for (i = 0; i < bss_0030.count; i++) {
        u8 *e = bss_0030.ents[i].b;
        e[bss_0030.slot + 0xe] = bss_21FA8[i];
        e[bss_0030.slot + 0x13] = bss_21FC8[i];
    }
}

void fn_1_3AEC4(void) {
    s32 i;
    u32 saved;

    fn_1_435C(bss_21F88);
    if (bss_2227C != -1) {
        fn_1_426C(bss_2227C);
    }
    if (bss_22280 != -1) {
        fn_1_426C(bss_22280);
        fn_1_105724();
    }
    fn_1_435C(bss_220A4);
    if (bss_22284 != -1) {
        fn_1_426C(bss_22284);
    }
    bss_2227C = -1;
    bss_22280 = -1;
    bss_22284 = -1;
    if ((bss_0030.flags & 0x800000) && bss_14E8 != 0x2a) {
        fn_1_F2EDC();
    }
    fn_1_A8F78();
    if (bss_2226C != 0) {
        bss_22270 = 1;
    }
    if (bss_22270 != 0) {
        fn_1_3AEC4_copy_slots();
        bss_0030.unk_1464 = 0;
        bss_0030.unk_146c = 0;
        bss_0030.unk_146d = 0;
        bss_0030.unk_1470 = 0;
        bss_0030.unk_146e = 1500;
        fn_1_1547FC();
        fn_1_C47B4();
        fn_1_435C(bss_21F88);
        if (bss_0014 != 0) {
            fn_1_426C(bss_0014);
            bss_0014 = 0;
        }
        fn_1_435C(bss_220A4);
        if (bss_0018 != 0) {
            fn_1_426C(bss_0018);
            bss_0018 = 0;
        }
        fn_1_C6F80(0);
        saved = fn_80008E84(bss_220CC);
        fn_1_79100();
        fn_80008E84(saved);
        fn_1_412A0(2);
        fn_1_E35F0();
        fn_1_435C(bss_21F88);
        fn_1_426C(bss_220B4);
        fn_1_426C(bss_220B8);
        fn_1_426C(bss_22264);
        fn_1_435C(bss_220A4);
        fn_1_426C(bss_220A8);
        fn_1_426C(bss_220AC);
        fn_1_426C(bss_220B0);
        fn_1_426C(bss_220BC);
        fn_1_426C(bss_220C0);
        fn_1_426C(bss_220C4);
        fn_1_426C(bss_22258);
        fn_1_426C(bss_2225C);
        fn_1_426C(bss_22260);
        fn_1_426C(bss_22254);
    }
    if (bss_2226C != 0) {
        bss_0030.slot++;
    }
}
/* fzgx:end fn_1_3AEC4 */

/* fzgx:begin fn_1_3DB9C pool noprologue */
#include "types.h"

typedef struct {
    u8 pad_0[0xe];
    u8 a[5];
    u8 b[5];
    u8 pad_18[0x88];
} Entry3DB9C;

typedef struct {
    u32 flags;               /* 0x00 */
    u8 pad_4[5];
    u8 count;                /* 0x09 */
    u8 pad_a[0x9d];
    u8 sel;                  /* 0xa7 */
    u8 pad_a8[0x2c];
    Entry3DB9C entries[31];  /* 0xd4 */
    u8 pad_1434[0x30];
    u32 unk_1464;
    u8 pad_1468[4];
    u8 unk_146c;
    u8 unk_146d;
    u16 unk_146e;
    u8 unk_1470;
} Sub3DB9C;

/* game.c .bss objects, in retail address order (addressed off one section base) */
u32 lbl_1_bss_3C00;
u8 lbl_1_bss_3C04[0x10];
u32 lbl_1_bss_3C14;
u32 lbl_1_bss_3C18;
u8 lbl_1_bss_3C1C[0x14];
Sub3DB9C lbl_1_bss_3C30;
u8 lbl_1_bss_50A4[0x25B88 - 0x50A4];
u32 lbl_1_bss_25B88;
u8 lbl_1_bss_25B8C[0x1c];
u8 lbl_1_bss_25BA8[0x20];
u8 lbl_1_bss_25BC8[0xdc];
u32 lbl_1_bss_25CA4;
u32 lbl_1_bss_25CA8;
u32 lbl_1_bss_25CAC;
u32 lbl_1_bss_25CB0;
u32 lbl_1_bss_25CB4;
u32 lbl_1_bss_25CB8;
u32 lbl_1_bss_25CBC;
u32 lbl_1_bss_25CC0;
u32 lbl_1_bss_25CC4;
u32 lbl_1_bss_25CC8;
u32 lbl_1_bss_25CCC;
u8 lbl_1_bss_25CD0[0x184];
u32 lbl_1_bss_25E54;
u32 lbl_1_bss_25E58;
u32 lbl_1_bss_25E5C;
u32 lbl_1_bss_25E60;
u32 lbl_1_bss_25E64;
u32 lbl_1_bss_25E68;
s32 lbl_1_bss_25E6C;
s32 lbl_1_bss_25E70;

extern void fn_1_156754(s32);
extern void fn_1_F7578(void);
extern void fn_1_A8F78(void);
extern void fn_1_1547FC(void);
extern void fn_1_C47B4(void);
extern u32 fn_1_435C(u32);
extern void fn_1_426C(u32);
extern void fn_1_C6F80(u8);
extern void fn_1_79100(void);
extern void fn_1_412A0(u32);
extern void fn_1_E35F0(void);
extern u32 fn_80008E84(u32);

/* primer: fixes the .bss layout to retail address order (section dropped at integration) */
#pragma section code_type ".fzgxpool"
void fzgx_primer_fn_1_3DB9C(void) {
    fn_1_426C((u32)&lbl_1_bss_3C00);
    fn_1_426C((u32)lbl_1_bss_3C04);
    fn_1_426C((u32)&lbl_1_bss_3C14);
    fn_1_426C((u32)&lbl_1_bss_3C18);
    fn_1_426C((u32)lbl_1_bss_3C1C);
    fn_1_426C((u32)&lbl_1_bss_3C30);
    fn_1_426C((u32)lbl_1_bss_50A4);
    fn_1_426C((u32)&lbl_1_bss_25B88);
    fn_1_426C((u32)lbl_1_bss_25B8C);
    fn_1_426C((u32)lbl_1_bss_25BA8);
    fn_1_426C((u32)lbl_1_bss_25BC8);
    fn_1_426C((u32)&lbl_1_bss_25CA4);
    fn_1_426C((u32)&lbl_1_bss_25CA8);
    fn_1_426C((u32)&lbl_1_bss_25CAC);
    fn_1_426C((u32)&lbl_1_bss_25CB0);
    fn_1_426C((u32)&lbl_1_bss_25CB4);
    fn_1_426C((u32)&lbl_1_bss_25CB8);
    fn_1_426C((u32)&lbl_1_bss_25CBC);
    fn_1_426C((u32)&lbl_1_bss_25CC0);
    fn_1_426C((u32)&lbl_1_bss_25CC4);
    fn_1_426C((u32)&lbl_1_bss_25CC8);
    fn_1_426C((u32)&lbl_1_bss_25CCC);
    fn_1_426C((u32)lbl_1_bss_25CD0);
    fn_1_426C((u32)&lbl_1_bss_25E54);
    fn_1_426C((u32)&lbl_1_bss_25E58);
    fn_1_426C((u32)&lbl_1_bss_25E5C);
    fn_1_426C((u32)&lbl_1_bss_25E60);
    fn_1_426C((u32)&lbl_1_bss_25E64);
    fn_1_426C((u32)&lbl_1_bss_25E68);
    fn_1_426C((u32)&lbl_1_bss_25E6C);
    fn_1_426C((u32)&lbl_1_bss_25E70);
}
#pragma section code_type ".text"

static inline void fn_1_3DB9C_copy(void) {
    s32 i;
    Entry3DB9C *e;

    for (i = 0; i < lbl_1_bss_3C30.count; i++) {
        e = &lbl_1_bss_3C30.entries[i];
        e->a[lbl_1_bss_3C30.sel] = lbl_1_bss_25BA8[i];
        e->b[lbl_1_bss_3C30.sel] = lbl_1_bss_25BC8[i];
    }
}

void fn_1_3DB9C(void) {
    s32 i;
    u32 saved;

    for (i = 0; i < 4; i++) {
        fn_1_156754(i);
    }
    fn_1_F7578();
    lbl_1_bss_3C30.flags &= ~0x2000;
    fn_1_A8F78();
    if (lbl_1_bss_25E6C != 0) {
        lbl_1_bss_25E70 = 1;
    }
    if (lbl_1_bss_25E70 != 0) {
        fn_1_3DB9C_copy();
        lbl_1_bss_3C30.unk_1464 = 0;
        lbl_1_bss_3C30.unk_146c = 0;
        lbl_1_bss_3C30.unk_146d = 0;
        lbl_1_bss_3C30.unk_1470 = 0;
        lbl_1_bss_3C30.unk_146e = 1500;
        fn_1_1547FC();
        fn_1_C47B4();
        fn_1_435C(lbl_1_bss_25B88);
        if (lbl_1_bss_3C14 != 0) {
            fn_1_426C(lbl_1_bss_3C14);
            lbl_1_bss_3C14 = 0;
        }
        fn_1_435C(lbl_1_bss_25CA4);
        if (lbl_1_bss_3C18 != 0) {
            fn_1_426C(lbl_1_bss_3C18);
            lbl_1_bss_3C18 = 0;
        }
        fn_1_C6F80(0);
        saved = fn_80008E84(lbl_1_bss_25CCC);
        fn_1_79100();
        fn_80008E84(saved);
        fn_1_412A0(2);
        fn_1_E35F0();
        fn_1_435C(lbl_1_bss_25B88);
        fn_1_426C(lbl_1_bss_25CB4);
        fn_1_426C(lbl_1_bss_25CB8);
        fn_1_426C(lbl_1_bss_25E64);
        fn_1_435C(lbl_1_bss_25CA4);
        fn_1_426C(lbl_1_bss_25CA8);
        fn_1_426C(lbl_1_bss_25CAC);
        fn_1_426C(lbl_1_bss_25CB0);
        fn_1_426C(lbl_1_bss_25CBC);
        fn_1_426C(lbl_1_bss_25CC0);
        fn_1_426C(lbl_1_bss_25CC4);
        fn_1_426C(lbl_1_bss_25E58);
        fn_1_426C(lbl_1_bss_25E5C);
        fn_1_426C(lbl_1_bss_25E60);
        fn_1_426C(lbl_1_bss_25E54);
    }
    if (lbl_1_bss_25E6C != 0) {
        lbl_1_bss_3C30.sel++;
    }
}
/* fzgx:end fn_1_3DB9C */

/* fzgx:begin fn_1_3DDAC */
// Initializes global game state and configures startup resources.
void fn_1_3DDAC(void) {
    fn_1_4A00(1, 0x1e, lbl_1_bss_5100);
    fn_1_5370(3, 0);
    fn_1_15E27C();

    lbl_1_bss_26C28 = 0;
    fn_1_D0790();

    lbl_1_bss_3C30.unk_0 |= 0x8;
    lbl_1_bss_6EAB4.unk_0 |= 0x2c;
    fn_1_4811C(0x94);

    fn_1_48004(0x8a, 1);
    fn_1_435C( (u32)((void *)lbl_1_bss_25CA4.unk_0));
    fn_1_4310(0x20000);
    fn_1_435C( (u32)((void *)lbl_1_bss_25B88.unk_0));
    fn_1_4310(0x2c3);

    fn_1_A1588(lbl_1_bss_6EAD0.unk_0->unk_0, 0x1e);
}
/* fzgx:end fn_1_3DDAC */

/* fzgx:begin fn_1_3E5D0 */
// Resets both state objects and advances the game initialization sequence.
void fn_1_3E5D0(void) {
    fn_1_435C( (u32)((void *)lbl_1_bss_25B88.unk_0));
    fn_1_4310(0);
    fn_1_435C( (u32)((void *)lbl_1_bss_25CA4.unk_0));
    fn_1_4310(0);
    fn_1_4811C(0x8a);
    fn_1_A8F78();
}
/* fzgx:end fn_1_3E5D0 */

/* fzgx:begin fn_1_3E628 */
// fn_1_3E628: empty in retail (single blr).
void fn_1_3E628(void) {
}
/* fzgx:end fn_1_3E628 */

/* fzgx:begin fn_1_3E62C */
void fn_1_3E62C(void) {
    if ((s32)lbl_1_bss_25BA0.unk_0 == 0) {
        lbl_1_bss_53F4 = 0xD;
        lbl_1_bss_6EAB4.unk_0 |= 0x2C;
        lbl_1_bss_25BA0.unk_0 = 1;
    }
}
/* fzgx:end fn_1_3E62C */

/* fzgx:begin fn_1_3E66C */
// fn_1_3E66C: empty in retail (single blr).
void fn_1_3E66C(void) {
}
/* fzgx:end fn_1_3E66C */

/* fzgx:begin fn_1_3E670 */
void fn_1_3E670(void) {
    fn_1_4A00(1, 0x1e, lbl_1_bss_5100);
    lbl_1_bss_26C28 = 0;
    fn_1_D0790();
    lbl_1_bss_3C30.unk_0 |= 8;
    lbl_1_bss_6EAB4.unk_0 |= 0x2c;
}
/* fzgx:end fn_1_3E670 */

/* fzgx:begin fn_1_3EA70 */
void fn_1_3EA70(void) {
    fn_1_A8F78();
}
/* fzgx:end fn_1_3EA70 */

/* fzgx:begin fn_1_3EB78 pool noprologue */
#include "rel/main_rel/game.h"

typedef struct {
    u8 count;
    u8 pad0[0x37];
    u8 count2;
    u8 pad1[0x163C - 0x39];
    u8 e[0x20000 + 0x2048 - 0x163C];
    s16 a[0x128];
    u8 b[0x3C4];
    u8 c[0x20];
    u32 d[4];
} S;

typedef struct lbl_1_bss_3C30_t {
    u8 pad_0[0x8];
    u8 count2;
    u8 pad_9[0x14b3];
} lbl_1_bss_3C30_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_1_bss_3C00;
u8 lbl_1_bss_3C00_fill_3C01;
u16 lbl_1_bss_3C00_fill_3C02;
u32 fzgx_obj_lbl_1_bss_3C04;
u32 lbl_1_bss_3C08[2];
u8 lbl_1_bss_3C10;
u8 fzgx_obj_lbl_1_bss_3C11;
u16 fzgx_obj_lbl_1_bss_3C12;
u32 lbl_1_bss_3C12_fill_3C14[2];
u32 fzgx_obj_lbl_1_bss_3C1C[3];
u16 lbl_1_bss_3C1C_fill_3C28;
u16 fzgx_obj_lbl_1_bss_3C2A;
u32 lbl_1_bss_3C2A_fill_3C2C;
lbl_1_bss_3C30_t fzgx_obj_lbl_1_bss_3C30;
u32 fzgx_obj_lbl_1_bss_50EC[5];
u32 fzgx_obj_lbl_1_bss_5100;
u32 fzgx_obj_lbl_1_bss_5104[13];
u32 fzgx_obj_lbl_1_bss_5138[65];
u8 lbl_1_bss_523C;
u8 lbl_1_bss_523C_fill_523D;
u16 lbl_1_bss_523C_fill_523E;
u32 lbl_1_bss_523C_fill_5240[7];
u32 fzgx_obj_lbl_1_bss_525C[102];
u16 fzgx_obj_lbl_1_bss_53F4;
u16 lbl_1_bss_3C00_gap_53F6;
u32 fzgx_obj_lbl_1_bss_53F8[34];
u32 fzgx_obj_lbl_1_bss_5480[33216];
u16 lbl_1_bss_25B80;
u16 lbl_1_bss_3C00_gap_25B82;
u32 lbl_1_bss_25B84;
u32 fzgx_obj_lbl_1_bss_25B88[4];
u16 fzgx_obj_lbl_1_bss_25B98;
u16 lbl_1_bss_3C00_gap_25B9A;
u32 lbl_1_bss_25B9C;
u32 fzgx_obj_lbl_1_bss_25BA0[42];
u8 fzgx_obj_lbl_1_bss_25C48;
u8 lbl_1_bss_25C48_fill_25C49;
u16 lbl_1_bss_25C48_fill_25C4A;
u32 lbl_1_bss_25C48_fill_25C4C[22];
u32 fzgx_obj_lbl_1_bss_25CA4[11];
u32 lbl_1_bss_25CD0[105];
u32 lbl_1_bss_25E74[7];
u32 lbl_1_bss_25E90[2];
u8 fzgx_obj_lbl_1_bss_25E98;
u8 lbl_1_bss_3C00_gap_25E99;
u16 lbl_1_bss_3C00_gap_25E99_fill_25E9A;
u32 fzgx_obj_lbl_1_bss_25E9C[240];
u8 fzgx_obj_lbl_1_bss_2625C[0x20];
u32 lbl_1_bss_2627C[4];
u32 lbl_1_bss_2627C_fill_2628C[26];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C00;
    s = *(u8 *)&lbl_1_bss_3C00_fill_3C01;
    s = *(u8 *)&lbl_1_bss_3C00_fill_3C02;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C04;
    s = *(u8 *)&lbl_1_bss_3C08;
    s = *(u8 *)&lbl_1_bss_3C10;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C11;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C12;
    s = *(u8 *)&lbl_1_bss_3C12_fill_3C14;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C1C;
    s = *(u8 *)&lbl_1_bss_3C1C_fill_3C28;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C2A;
    s = *(u8 *)&lbl_1_bss_3C2A_fill_3C2C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C30;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_50EC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5100;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5104;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5138;
    s = *(u8 *)&lbl_1_bss_523C;
    s = *(u8 *)&lbl_1_bss_523C_fill_523D;
    s = *(u8 *)&lbl_1_bss_523C_fill_523E;
    s = *(u8 *)&lbl_1_bss_523C_fill_5240;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_525C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_53F4;
    s = *(u8 *)&lbl_1_bss_3C00_gap_53F6;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_53F8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5480;
    s = *(u8 *)&lbl_1_bss_25B80;
    s = *(u8 *)&lbl_1_bss_3C00_gap_25B82;
    s = *(u8 *)&lbl_1_bss_25B84;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25B88;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25B98;
    s = *(u8 *)&lbl_1_bss_3C00_gap_25B9A;
    s = *(u8 *)&lbl_1_bss_25B9C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25BA0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25C48;
    s = *(u8 *)&lbl_1_bss_25C48_fill_25C49;
    s = *(u8 *)&lbl_1_bss_25C48_fill_25C4A;
    s = *(u8 *)&lbl_1_bss_25C48_fill_25C4C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25CA4;
    s = *(u8 *)&lbl_1_bss_25CD0;
    s = *(u8 *)&lbl_1_bss_25E74;
    s = *(u8 *)&lbl_1_bss_25E90;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25E98;
    s = *(u8 *)&lbl_1_bss_3C00_gap_25E99;
    s = *(u8 *)&lbl_1_bss_3C00_gap_25E99_fill_25E9A;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25E9C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_2625C;
    s = *(u8 *)&lbl_1_bss_2627C;
    s = *(u8 *)&lbl_1_bss_2627C_fill_2628C;
}
#pragma section code_type ".text"

void fn_1_3EB78(u8 arg0, u8 *arg1, u8 *arg2, u32 *arg3) {
    
    s32 i;
    s32 n;
    n = 0;
    i = 0;
    while (n < arg0 && i < 4) {
        u8 v = *arg1;
        if (v != 0xFF) {
            fzgx_obj_lbl_1_bss_2625C[n] = v;
            if (arg2 == 0 || arg2[i] == 0xFF) {
                (*(u8 (*)[0x20000 + 0x2048 - 0x163C])&lbl_1_bss_523C)[n] = 1;
            } else {
                (*(u8 (*)[0x20000 + 0x2048 - 0x163C])&lbl_1_bss_523C)[n] = arg2[i];
            }
            if (arg3 == 0) {
                lbl_1_bss_2627C[n] = 0;
            } else {
                lbl_1_bss_2627C[n] = arg3[i];
            }
            (*(u8 (*)[0x3C4])&fzgx_obj_lbl_1_bss_25E98)[n] = i;
            (*(s16 (*)[0x128])&fzgx_obj_lbl_1_bss_25C48)[n] = (&lbl_1_bss_8B3A0.unk_9F)[i];
            n++;
        }
        i++;
        arg1++;
    }
    fzgx_obj_lbl_1_bss_3C00 = n;
    fzgx_obj_lbl_1_bss_3C30.count2 = n;
}
/* fzgx:end fn_1_3EB78 */

/* fzgx:begin fn_1_3EF08 */
void fn_1_3EF08(u8 value) {
    lbl_1_bss_262F4 = value;
}
/* fzgx:end fn_1_3EF08 */

/* fzgx:begin fn_1_3EF14 */
static inline s16 current_mode(void) {
    return *(s16 *)&lbl_1_bss_960;
}

// Selects the appropriate buffer initialization based on the current mode.
void fn_1_3EF14(void *arg1) {
    if (lbl_1_bss_3C12.unk_0 != 0 ||
        (u16)(current_mode() - 13) <= 1 ||
        current_mode() == 10 ||
        current_mode() == 16) {
        fn_80008BA8( (u32)(void *)(arg1), (u32)(void *)(&lbl_1_bss_3C30), 0x14b8);
    } else {
        fn_80008BEC(arg1, (int)(void *)(0), 0x14b8);
    }
}
/* fzgx:end fn_1_3EF14 */

/* fzgx:begin fn_1_3EF8C */
// Stores the value unless initialization has already occurred.
void fn_1_3EF8C(u8 value) {
    if (lbl_1_bss_3C12.unk_0 == 0) {
        lbl_1_data_5B7C = value;
    }
}
/* fzgx:end fn_1_3EF8C */

/* fzgx:begin fn_1_3EFA8 */
typedef struct MainRelState {
    u8 pad_0000[0x12];
    u8 unk_12;
    u8 pad_0013[0x1D];
    s32 unk_30;
    u8 pad_0034[0x14C4];
    s32 unk_14F8;
} MainRelState;

// Reports whether the relevant state is active and enabled.
s32 fn_1_3EFA8(void) {
    s32 result = 0;
    MainRelState *state = (MainRelState *)&lbl_1_bss_3C00;

    if (state->unk_14F8 != 0 ||
        (state->unk_30 & 2) != 0 ||
        (s32)lbl_1_bss_26B50 != 0) {
        if (state->unk_12 != 0) {
            result = 1;
        }
    }
    return result;
}
/* fzgx:end fn_1_3EFA8 */

/* fzgx:begin fn_1_3EFF0 */
void fn_1_3EFF0(u32 arg1, u8 arg2) {
    lbl_1_bss_25E74[0] = arg1;
    lbl_1_bss_3C10 = arg2;
    lbl_1_bss_3C11 = 1;
    lbl_1_bss_26C58 = 0;
    lbl_1_bss_26C64 = 0;
}
/* fzgx:end fn_1_3EFF0 */

/* fzgx:begin fn_1_3F02C */
void fn_1_3F02C(u32 arg1) {
    lbl_1_bss_26C64 = arg1;
}
/* fzgx:end fn_1_3F02C */

/* fzgx:begin fn_1_3F038 */
// Initializes the game state and reports whether startup has completed.
int fn_1_3F038(void) {
    if (lbl_1_bss_26C58 != 0) {
        return 1;
    }

    if (lbl_1_bss_3C11 != 0) {
        fn_1_36330();
        lbl_1_bss_3C11 = 0;
    }

    fn_1_36B10();
    fn_1_3C98();
    if ((lbl_1_bss_3C30.unk_0 & 4) == 0) {
        fn_1_37AA8();
    }

    if (lbl_1_bss_26C58 != 0) {
        fn_1_37E98();
        return 1;
    }
    return 0;
}
/* fzgx:end fn_1_3F038 */

/* fzgx:begin fn_1_3F0C8 */
s16 fn_1_3F0C8(void) {
    return lbl_1_bss_3C2A;
}
/* fzgx:end fn_1_3F0C8 */

/* fzgx:begin fn_1_3F0D8 */
u8 *fn_1_3F0D8(u32 index, f32 *value, u8 *flag) {
    u8 idx = (u8)index;
    *value = lbl_1_bss_26304[idx];
    *flag = lbl_1_bss_26B04[idx];
    return &lbl_1_bss_26314[idx * 0x1fc];
}
/* fzgx:end fn_1_3F0D8 */

/* fzgx:begin fn_1_3F114 */
// Returns the current global status byte when the subsystem is enabled.
u8 fn_1_3F114(void) {
    if (lbl_1_bss_3C12.unk_0 != 0) {
        return lbl_1_bss_3C30.unk_4;
    }
    return 0;
}
/* fzgx:end fn_1_3F114 */

/* fzgx:begin fn_1_3F13C */
u8 fn_1_3F13C(void) {
    if (lbl_1_bss_3C12.unk_0 != 0) {
        return lbl_1_bss_3C30.unk_5;
    }
    return 0xff;
}
/* fzgx:end fn_1_3F13C */

/* fzgx:begin fn_1_3F164 */
typedef struct {
    u8 unk_00[0x12];
    u8 unk_12;
    u8 unk_13[0x1d];
    s32 unk_30;
    u8 unk_34[0x14c4];
    s32 unk_14f8;
} MainState;

// Reports whether the active state permits the current mode.
s32 fn_1_3F164(void) {
    s32 result = 0;
    MainState *state = (MainState *)&lbl_1_bss_3C00;

    if (state->unk_14f8 != 0 ||
        (state->unk_30 & 2) != 0 ||
        (s32)lbl_1_bss_26B50 != 0) {
        if (state->unk_12 != 0) {
            result = 1;
        }
    }
    return result;
}
/* fzgx:end fn_1_3F164 */

/* fzgx:begin fn_1_3F1AC */
u32 fn_1_3F1AC(u32 arg0) {
    u32 v0;
    v0 = arg0;
    if ((*(u8 *)&lbl_1_bss_3C12) == 0) {
    v0 = 0;
    return v0;
    }
    return (((*(u32 (*)[])&lbl_1_bss_3C30)[0] >> 1) & 0x1);
}
/* fzgx:end fn_1_3F1AC */

/* fzgx:begin fn_1_3F1D4 */
// Return the stored status byte when the game state is initialized.
s32 fn_1_3F1D4(void) {
    if (lbl_1_bss_3C30.unk_5 == 1) {
        return lbl_1_bss_3C30.unk_13F6;
    }
    return -1;
}
/* fzgx:end fn_1_3F1D4 */

/* fzgx:begin fn_1_3F1F8 */
u8 fn_1_3F1F8(void) {
    if (lbl_1_bss_3C30.unk_A6 != 0xff) {
        return fn_1_12EF24(lbl_1_bss_3C30.unk_A6, lbl_1_bss_3C30.unk_A7);
    }
    return lbl_1_bss_3C30.unk_6;
}
/* fzgx:end fn_1_3F1F8 */

/* fzgx:begin fn_1_3F23C */
// Reads the byte selected by the low eight bits of the index.
u8 fn_1_3F23C(u32 index) {
    u8 *table = &lbl_1_bss_2625C.unk_0;

    return table[index & 0xff];
}
/* fzgx:end fn_1_3F23C */

/* fzgx:begin fn_1_3F250 */
u8 fn_1_3F250(u32 index) {
    return lbl_1_bss_523C[index & 0xff];
}
/* fzgx:end fn_1_3F250 */

/* fzgx:begin fn_1_3F264 */
// Return the stored entry byte, or the indexed fallback when no entry exists.
u8 fn_1_3F264(u32 index) {
    u32 masked = index & 0xff;
    Entry *entry = lbl_1_bss_53F8[masked];

    if (entry != 0) {
        return entry->value;
    }

    return (u8)(&lbl_1_bss_25C48.unk_0)[masked];
}
/* fzgx:end fn_1_3F264 */

/* fzgx:begin fn_1_3F2A0 */
#define B ((u8 *)&lbl_1_bss_3C30)

void fn_1_3F2A0(void) {
    s32 n;
    s32 i;
    s32 j;
    s32 k;
    s32 idx;
    s32 cnt;
    s32 mine;
    s32 other;
    s32 v;
    u8 *e;

    if (lbl_1_bss_3C30.unk_5 == 0) {
        n = lbl_1_bss_3C30.unk_8;
    } else {
        n = lbl_1_bss_3C30.unk_9;
    }
    j = 0;
    for (i = 0; i < n; i++) {
        if (lbl_1_bss_3C30.unk_5 == 0) {
            while (B[0xe + j] >= n) {
                j++;
            }
        }
        idx = B[0xe + j];
        e = B + idx * 0xa0 + 0xd4;
        cnt = 0;
        if (lbl_1_bss_3C30.unk_5 == 0) {
            mine = *(u32 *)(B + 0x1480 + idx * 4);
            *(u16 *)(e + 4) = mine;
            *(u16 *)(e + 0x9e) = *(u16 *)(B + 0x1478 + idx * 2);
        } else {
            mine = *(u16 *)(e + 4);
        }
        for (k = 0; k < lbl_1_bss_3C30.unk_9; k++) {
            if (j != k) {
                v = B[0xe + k];
                if (lbl_1_bss_3C30.unk_5 == 0) {
                    if (v >= n) {
                        continue;
                    }
                    other = *(u32 *)(B + 0x1480 + v * 4);
                } else {
                    other = *(u16 *)(B + v * 0xa0 + 0xd8);
                }
                if (mine < other) {
                    cnt++;
                } else if (mine == other && j > k) {
                    cnt++;
                }
            }
        }
        B[0x1394 + cnt] = idx;
        e[8] = cnt;
        if (lbl_1_bss_3C30.unk_A7 == 0 && lbl_1_bss_3C30.unk_5 != 0) {
            e[0x83] = cnt;
        }
        j++;
    }
}
/* fzgx:end fn_1_3F2A0 */

/* fzgx:begin fn_1_3F440 */
// Reports an out-of-range index and returns the corresponding limit when valid.
s32 fn_1_3F440(u8 index) {
    u8 *limits;

    if (index > 0x1d) {
        OSPanic( (const char *)(const void *)(&lbl_1_data_62EC), 0x2654, (const char *)lbl_1_data_65E8);
    }

    limits = (u8 *)&lbl_1_bss_3C30.unk_0;
    if (lbl_1_bss_3C30.unk_8 > limits[index + 14]) {
        return limits[index + 14];
    }

    return -1;
}
/* fzgx:end fn_1_3F440 */

/* fzgx:begin fn_1_3F4B8 */
extern u32 lbl_1_bss_26C5C;

void fn_1_3F4B8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5)
{
    lbl_1_bss_3C30.unk_13F8 = arg0 * 60;
    lbl_1_bss_3C30.unk_13FA = arg1 * 60;
    lbl_1_bss_3C30.unk_13FC = arg2 * 60;
    lbl_1_bss_3C30.unk_13FE = arg3 * 60;
    lbl_1_bss_3C30.unk_1400 = arg4 * 60;
    lbl_1_bss_3C30.unk_1402 = arg5;
    lbl_1_bss_26C5C = 1;
}
/* fzgx:end fn_1_3F4B8 */

/* fzgx:begin fn_1_3F4FC */
void fn_1_3F4FC(void) {
    u8 *dp;
    s16 i;
    s32 mode;
    u32 flags;
    char buffer[0x20];
    char temp[0x20];

    dp = (u8 *)&lbl_1_data_5730;
    fn_1_12AB38(dp + 0xce4);
    fn_1_465D0( (char *)(void *)(dp + 0xcf0), 1);

    i = 0;
    while (i < lbl_1_bss_3C30.unk_9) {
        flags = lbl_1_bss_25E9C[i].unk_C;
        mode = 0;
        if (flags & 0x100000) {
            mode = 1;
        }

        if (flags & 0xf0000000) {
            sprintf(buffer, (const char *)(dp + 0xd00), (s32)fn_1_7F518(lbl_1_bss_25E9C[i].unk_2, temp, mode));
        } else {
            sprintf(buffer, (const char *)(dp + 0xd0c), (s32)fn_1_7F518(lbl_1_bss_25E9C[i].unk_2, temp, mode));
        }

        fn_1_465D0( (char *)(void *)(buffer), 1);
        i++;
    }

    fn_1_12AB38(dp + 0xd18);
}
/* fzgx:end fn_1_3F4FC */

/* fzgx:begin fn_1_3F75C */
void fn_1_3F75C(void) {
    while (fn_1_467F4() || fn_1_13018()) {
        fn_1_451E4();
        fn_1_D3214();
        fn_8001AF64();
    }
}
/* fzgx:end fn_1_3F75C */

/* fzgx:begin fn_1_3F7A0 */
void fn_1_3F7A0(u32* self) {
    self[0] = fn_1_46C60();
}
/* fzgx:end fn_1_3F7A0 */

/* fzgx:begin fn_1_3F7D0 */
u32 fn_1_3F7D0(void) {
    return lbl_1_bss_26C28;
}
/* fzgx:end fn_1_3F7D0 */

/* fzgx:begin fn_1_3F7E0 */
// Selects the mode-specific byte from the shared game state.
u8 fn_1_3F7E0(void) {
    if (lbl_1_bss_3C30.unk_0 & 0x00008000) {
        return lbl_1_bss_3C30.unk_9;
    }
    return lbl_1_bss_3C30.pad_A[0];
}
/* fzgx:end fn_1_3F7E0 */

/* fzgx:begin fn_1_3F800 */
// Stores the value in the shared game state.
void fn_1_3F800(u32 value) {
    lbl_1_bss_3C30.unk_1464 = value;
}
/* fzgx:end fn_1_3F800 */

/* fzgx:begin fn_1_3F810 */
// Stores a value and its scaled companion in the shared game state.
void fn_1_3F810(u8 value, u32 input) {
    lbl_1_bss_3C30.unk_146C = value;
    lbl_1_bss_3C30.unk_146D = (u8)((input / 5) >> 1);
}
/* fzgx:end fn_1_3F810 */

/* fzgx:begin fn_1_3F834 */
// Stores the byte value in the shared game state.
void fn_1_3F834(u8 value) {
    lbl_1_bss_3C30.unk_1470 = value;
}
/* fzgx:end fn_1_3F834 */

/* fzgx:begin fn_1_3F844 */
// Store the current 16-bit value in the shared game state.
void fn_1_3F844(u16 value) {
    lbl_1_bss_3C30.unk_146E = value;
}
/* fzgx:end fn_1_3F844 */

/* fzgx:begin fn_1_3F854 */
// Return the current game-state byte.
u8 fn_1_3F854(void) {
    return lbl_1_bss_3C30.unk_8;
}
/* fzgx:end fn_1_3F854 */

/* fzgx:begin fn_1_3F864 */
// Reports whether the game is in the guarded state or mode 0x000c.
u8 fn_1_3F864(void) {
    if ((lbl_1_bss_3C30.unk_0 & 0x00100000) != 0 ||
        *(s16 *)&lbl_1_bss_960 == 0x000c) {
        return 1;
    }
    return 0;
}
/* fzgx:end fn_1_3F864 */

/* fzgx:begin fn_1_3F894 */
// Enables the associated game state and records the current mode.
void fn_1_3F894(void) {
    lbl_1_bss_53F4 = lbl_1_bss_3C30.unk_7;
    lbl_1_bss_25BA0.unk_0 = 1;
    lbl_1_bss_26C2C[0] = 1;
}
/* fzgx:end fn_1_3F894 */

/* fzgx:begin fn_1_3F8C0 */
u32 fn_1_3F8C0(void) {
    return lbl_1_bss_262F8[0];
}
/* fzgx:end fn_1_3F8C0 */

/* fzgx:begin fn_1_3F8D0 */
void fn_1_3F8D0(void) {
    u16 *values = (u16 *)&lbl_1_bss_38204;

    values[0] = 0;
    values[1] = 0;
    values[2] = 0;
    values[3] = 0;
}
/* fzgx:end fn_1_3F8D0 */

/* fzgx:begin fn_1_3FBF4 */
void fn_1_3FBF4(u32 arg0) {
    u32 v0;
    v0 = ((*(u32 *)&lbl_1_bss_3C30) & 0xFFFFFFFD);
    if ((s32)arg0 != 0) {
    v0 = ((*(u32 *)&lbl_1_bss_3C30) | 2);
    }
    (*(u32 *)&lbl_1_bss_3C30) = v0;
}
/* fzgx:end fn_1_3FBF4 */

/* fzgx:begin fn_1_3FC18 */
u16 fn_1_3FC18(void) {
    return lbl_1_bss_26C68[0];
}
/* fzgx:end fn_1_3FC18 */

/* fzgx:begin fn_1_3FC28 */
u32 fn_1_3FC28(void) {
    return lbl_1_bss_3C30.unk_0 & 0x00800000;
}
/* fzgx:end fn_1_3FC28 */

/* fzgx:begin fn_1_3FC38 */
u8 fn_1_3FC38(void) {
    return lbl_1_bss_3C12.unk_0;
}
/* fzgx:end fn_1_3FC38 */

/* fzgx:begin fn_1_3FC48 */
u32 fn_1_3FC48(void) {
    return lbl_1_bss_3C30.unk_0 & 0x100;
}
/* fzgx:end fn_1_3FC48 */

/* fzgx:begin fn_1_3FC58 */
u32 fn_1_3FC58(void) {
    return lbl_1_bss_3C30.unk_0 & 0x01000000;
}
/* fzgx:end fn_1_3FC58 */

/* fzgx:begin fn_1_3FC68 */
// Toggles the 0x02000000 status flag according to the requested state.
void fn_1_3FC68(s32 enabled) {
    lbl_1_bss_3C30.unk_0 = enabled != 0
        ? lbl_1_bss_3C30.unk_0 & ~0x02000000
        : lbl_1_bss_3C30.unk_0 | 0x02000000;
}
/* fzgx:end fn_1_3FC68 */

/* fzgx:begin fn_1_3FC8C */
// Return the global state flag stored in bit 6 of the control word.
u32 fn_1_3FC8C(void) {
    return lbl_1_bss_3C30.unk_0 & 0x02000000;
}
/* fzgx:end fn_1_3FC8C */

/* fzgx:begin fn_1_3FC9C */
 // Return the low byte of the signed global status field.
u32 fn_1_3FC9C(void) {
    return (u32)lbl_1_bss_8B3A0.unk_8 & 0xff;
}
/* fzgx:end fn_1_3FC9C */

/* fzgx:begin fn_1_3FCB0 */
static inline u32 fn_1_3FCB0_operand(u32 left, u32 right) { left &= right; return left; }
#pragma opt_propagation off
void fn_1_3FCB0(s32 value) {
    s32 mask = -value;
    mask |= value;
    mask >>= 31;
    lbl_1_bss_3C08[0] = fn_1_3FCB0_operand(((lbl_1_bss_3C08[0] | (u32)value)), ((u32)mask));
}
#pragma opt_propagation reset
/* fzgx:end fn_1_3FCB0 */

/* fzgx:begin fn_1_3FCF8 */
struct fn_1_3FCF8_lbl_1_bss_3C30 {
    u8 pad_0[0x1478];
    u16 unk_1478;
    u16 unk_147A;
    u16 unk_147C;
    u16 unk_147E;
    u32 unk_1480;
    u32 unk_1484;
    u32 unk_1488;
    u32 unk_148C;
};

u32 fn_1_3FCF8(void) {
    u32 v0;
    u32 v1;
    u32 t0;
    (*(struct fn_1_3FCF8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30).unk_1480 = 0;
    (*(struct fn_1_3FCF8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30).unk_1478 = 0;
    (*(struct fn_1_3FCF8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30).unk_1484 = 0;
    (*(struct fn_1_3FCF8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30).unk_147A = 0;
    (*(struct fn_1_3FCF8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30).unk_1488 = 0;
    (*(struct fn_1_3FCF8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30).unk_147C = 0;
    (*(struct fn_1_3FCF8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30).unk_148C = 0;
    (*(struct fn_1_3FCF8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30).unk_147E = 0;
    v1 = (u32)&(*(struct fn_1_3FCF8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30);
    for (v0 = 5; v0 != 0; v0--) {
    *(u8 *)((u8 *)v1 + 343) = 0;
    *(u8 *)((u8 *)v1 + 220) = 0;
    *(u16 *)((u8 *)v1 + 216) = 0;
    *(u8 *)((u8 *)v1 + 503) = 0;
    *(u8 *)((u8 *)v1 + 380) = 0;
    *(u16 *)((u8 *)v1 + 376) = 0;
    *(u8 *)((u8 *)v1 + 663) = 0;
    *(u8 *)((u8 *)v1 + 540) = 0;
    *(u16 *)((u8 *)v1 + 536) = 0;
    *(u8 *)((u8 *)v1 + 823) = 0;
    *(u8 *)((u8 *)v1 + 700) = 0;
    *(u16 *)((u8 *)v1 + 696) = 0;
    *(u8 *)((u8 *)v1 + 983) = 0;
    *(u8 *)((u8 *)v1 + 860) = 0;
    *(u16 *)((u8 *)v1 + 856) = 0;
    *(u8 *)((u8 *)v1 + 1143) = 0;
    *(u8 *)((u8 *)v1 + 1020) = 0;
    *(u16 *)((u8 *)v1 + 1016) = 0;
    v1 = (u32)((u8 *)v1 + 960);
    }
    v1 = 0x80000000;
    t0 = fn_800075AC(v1, 8192, 1);
    v1 = t0;
    return v1;
}
/* fzgx:end fn_1_3FCF8 */

/* fzgx:begin fn_1_3FDA8 */
void fn_1_3FDA8(void *arg0, void *arg1) {
    s32 condition;
    void *value;

    if (lbl_1_bss_5138.unk_0 != 0) {
        lbl_1_bss_5138.unk_E1 = 0;
    } else {
        if (lbl_1_bss_5138.unk_E3 == 0xff) {
            condition = 0;
        } else if ((s32)ghost_test_record_flag0(lbl_1_bss_3C30.unk_6) != 0) {
            condition = 0;
        } else {
            condition = 1;
        }
        if (condition != 0) {
            lbl_1_bss_5138.unk_E1 = 1;
        } else {
            if (lbl_1_bss_5138.unk_E5 == 0xff) {
                condition = 0;
            } else if ((s32)fn_1_F9D44(lbl_1_bss_5138.unk_E5 & 0xf) != 0) {
                condition = 0;
            } else {
                condition = 1;
            }
            if (condition != 0) {
                lbl_1_bss_5138.unk_E1 = 2;
            } else {
                if (lbl_1_bss_5138.unk_EB == 0xff) {
                    condition = 0;
                } else if (fn_1_F8C50(lbl_1_bss_5138.unk_EB) != 0) {
                    condition = 0;
                } else {
                    condition = 1;
                }
                if (condition != 0) {
                    lbl_1_bss_5138.unk_E1 = 3;
                } else if (lbl_1_bss_5138.unk_3 + lbl_1_bss_5138.unk_2 + lbl_1_bss_5138.unk_E4 != 0) {
                    lbl_1_bss_5138.unk_E1 = 4;
                } else {
                    // Skip setup when no state transition is selected.
                    goto done;
                }
            }
        }
    }

    value = (void *)fn_1_435C( (u32)(void *)(arg0));
    fn_1_3F8C(lbl_1_data_6608, (void *)(void (*)(void))(fn_1_2DB50), &lbl_1_bss_5138, 30);
    fn_1_435C( (u32)(void *)(arg1));
    fn_1_3F8C(lbl_1_data_6618, (void *)(void (*)(void))(fn_1_2D888), &lbl_1_bss_5138, 30);
    fn_1_435C( (u32)(void *)(value));
    lbl_1_bss_5138.unk_E2 = 1;
    fn_1_2D524();

done:
    return;
}
/* fzgx:end fn_1_3FDA8 */

/* fzgx:begin fn_1_3FF90 */
void fn_1_3FF90(void) {
    u32 bss_25b88;
    u32 bss_25ca4;
    int flag;

    bss_25ca4 = lbl_1_bss_25CA4.unk_0;
    bss_25b88 = lbl_1_bss_25B88.unk_0;
    if (lbl_1_bss_5138.unk_0 != 0) {
        lbl_1_bss_5138.unk_E1 = 0;
    } else {
        if (lbl_1_bss_5138.unk_E3 == 0xff) {
            flag = 0;
        } else if ((int)ghost_test_record_flag0(lbl_1_bss_3C30.unk_6) != 0) {
            flag = 0;
        } else {
            flag = 1;
        }
        if (flag != 0) {
            lbl_1_bss_5138.unk_E1 = 1;
        } else {
            if (lbl_1_bss_5138.unk_E5 == 0xff) {
                flag = 0;
            } else if ((int)fn_1_F9D44(lbl_1_bss_5138.unk_E5 & 0xf) != 0) {
                flag = 0;
            } else {
                flag = 1;
            }
            if (flag != 0) {
                lbl_1_bss_5138.unk_E1 = 2;
            } else {
                if (lbl_1_bss_5138.unk_EB == 0xff) {
                    flag = 0;
                } else if (fn_1_F8C50(lbl_1_bss_5138.unk_EB)) {
                    flag = 0;
                } else {
                    flag = 1;
                }
                if (flag != 0) {
                    lbl_1_bss_5138.unk_E1 = 3;
                } else if ((lbl_1_bss_5138.unk_3 + lbl_1_bss_5138.unk_2 +
                            lbl_1_bss_5138.unk_E4) == 0) {
                    return;
                } else {
                    lbl_1_bss_5138.unk_E1 = 4;
                }
            }
        }
    }

    bss_25b88 = fn_1_435C(bss_25b88);
    fn_1_3F8C(lbl_1_data_6608, fn_1_2DB50, &lbl_1_bss_5138, 30);
    fn_1_435C(bss_25ca4);
    fn_1_3F8C(lbl_1_data_6618, fn_1_2D888, &lbl_1_bss_5138, 30);
    bss_25b88 = fn_1_435C(bss_25b88);
    lbl_1_bss_5138.unk_E2 = 1;
    fn_1_2D524();
}
/* fzgx:end fn_1_3FF90 */

/* fzgx:begin fn_1_4017C */
int fn_1_4017C(void) {
    int i;
    int result1;
    int result2;
    int result3;

    if ((int)fn_1_FA070() != 0) {
        return 1;
    }
    for (i = 0; i < 3; i++) {
        result1 = (int)fn_1_FA180(1, i);
        result2 = (int)fn_1_FA180(2, i);
        result3 = (int)fn_1_FA180(3, i);
        if (result1 == 0 && result2 == 0 && result3 == 0) {
            return 0;
        }
    }
    return 1;
}
/* fzgx:end fn_1_4017C */

/* fzgx:begin fn_1_40224 */
int fn_1_40224(void) {
    int result;

    if ((int)fn_1_F9FEC() != 0) {
        return 1;
    }
    if ((int)fn_1_FA180(2, 0) == 0) {
        return 0;
    }
    if ((int)fn_1_FA180(2, 1) == 0) {
        return 0;
    }
    result = (int)fn_1_FA180(2, 2);
    return result != 0;
}
/* fzgx:end fn_1_40224 */

/* fzgx:begin fn_1_402D4 */
typedef struct {
    u8 pad_0[8];
    u16 unk_8;
    u8 pad_A[0xA];
} Elem_1_bss_9F8;

int fn_1_402D4(void) {
    s32 i;

    if (lbl_1_bss_3C30.unk_8 != 0) {
        for (i = 0; i < lbl_1_bss_3C30.unk_8; i++) {
            if ((((Elem_1_bss_9F8 *)&lbl_1_bss_9F8)[(&lbl_1_bss_25E98)[i]].unk_8 >> 8) & 1) {
                return 1;
            }
        }
    } else if ((lbl_1_bss_9F8.unk_8 >> 12) & 1) {
        return 1;
    }
    return 0;
}
/* fzgx:end fn_1_402D4 */

/* fzgx:begin fn_1_40354 */
typedef struct {
    u8 pad_0[8];
    u16 unk_8;
    u8 pad_A[0xa];
} Entry_1_bss_9F8;

int fn_1_40354(void) {
    int i;

    if (lbl_1_bss_3C30.unk_8 != 0) {
        for (i = 0; i < lbl_1_bss_3C30.unk_8; i++) {
            if ((((Entry_1_bss_9F8 *)&lbl_1_bss_9F8)[((u8 *)&lbl_1_bss_25E98)[i]].unk_8 >> 12) & 1) {
                return 1;
            }
        }
    } else if ((lbl_1_bss_9F8.unk_8 >> 12) & 1) {
        return 1;
    }
    return 0;
}
/* fzgx:end fn_1_40354 */

/* fzgx:begin fn_1_403D4 pool */
#pragma section code_type ".fzgxpool"
static const unsigned long fzgx_pool_table1[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const unsigned long *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 15.0f;
    s = 1.0f;
    s = 10.0f;
    s = 1.25f;
    s = 0.10000000149011612f;
    s = 0.8999999761581421f;
    s = 0.0006000000284984708f;
    s = 0.4000000059604645f;
    s = 0.75f;
    s = 70.0f;
    s = 0.5f;
    s = 36.0f;
    s = 16.0f;
    s = 45.0f;
    s = 0.0007999999797903001f;
    s = 18.0f;
    s = 50.0f;
}
static const unsigned long fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const unsigned long *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const unsigned long fzgx_pool_table5[52] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const unsigned long *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
    s = 80.0f;
    s = 60.0f;
}
static const unsigned long fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const unsigned long *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const unsigned long fzgx_pool_table9[2] = {0x00000000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const unsigned long *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 470.0f;
    s = 0.0625f;
    s = 14.0f;
    s = 127.0f;
    s = 0.25f;
}
static const unsigned long fzgx_pool_table11[3] = {0x03E8FED4, 0xFE70FE0C, 0xFE0CFE0C};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const unsigned long *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 10000.0f;
    s = 15000.0f;
    s = 9999.0f;
}
static const unsigned long fzgx_pool_table13[2] = {0xFFFFFF00, 0x80808000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const unsigned long *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 240.0f;
    s = 280.0f;
    s = 200.0f;
    s = 40.0f;
    s = 30.0f;
}
static const unsigned long fzgx_pool_table15[8] = {0x80808000, 0xFFFFFF00, 0x80808000, 0xFFFFFF00, 0xFFFFFF00, 0x00000000, 0x00000000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const unsigned long *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.05000000074505806f;
    s = 0.15000000596046448f;
    s = 0.07999999821186066f;
    s = 2.0f;
    s = 4.0f;
    s = 255.0f;
    s = 1.100000023841858f;
    s = 38.0f;
    s = 20.0f;
    s = 180.0f;
    s = 3.0f;
    s = 0.00019999999494757503f;
    s = 100.0f;
    s = 75.0f;
    s = 0.00039999998989515007f;
    s = 150.0f;
}
static const unsigned long fzgx_pool_table17[7] = {0xFFF200FF, 0xFFF200FF, 0x80808080, 0xFFFFFF96, 0xFFF200FF, 0xFFF200FF, 0xFFFFFF96};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const unsigned long *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.009999999776482582f;
    s = 1000.0f;
    d = 20.0;
}
static const unsigned long fzgx_pool_table19[4] = {0x80000000, 0x40000000, 0x20000000, 0x10000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const unsigned long *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 620.0f;
    s = 140.0f;
    s = 3000.0f;
    s = 0.00033333332976326346f;
}
static const f32 fn_1_403D4_pool_scale[1] = {0.3f};
__declspec(section ".fzgxpool") static void fzgx_pool_prime20b(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.6000000238418579f;
    s = 450.0f;
}
static const unsigned long fzgx_pool_table21[2] = {0x00000001, 0x00020003};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const unsigned long *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1100.0f;
    s = 1900.0f;
}
static const unsigned long fzgx_pool_table23[9] = {0x00000000, 0x40000000, 0x40000000, 0x40000000, 0x20000000, 0x20000000, 0x00000000, 0x00000000, 0x50000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const unsigned long *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 600.0f;
    s = -60.0f;
    s = -1.0f;
    s = 35.0f;
    s = -11.0f;
    s = 3.5f;
    s = -10.0f;
    s = 640.0f;
    s = 480.0f;
    s = 6.5f;
}
static const unsigned long fzgx_pool_table25[6] = {0x40000000, 0x40000000, 0x40000000, 0x20000000, 0x20000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const unsigned long *volatile cp; cp = fzgx_pool_table25; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime26(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 1000000.0f;
    s = -0.10000000149011612f;
    s = -2.0f;
}
static const unsigned long fzgx_pool_table27[17] = {0x00B500B6, 0x00AD00B3, 0x00B800B2, 0x00B100AE, 0x00B400B9, 0x00B000AF, 0x00B7FFFF, 0xFFF200FF, 0xFFF200FF, 0xFFFFFF96, 0xFFFFFF96, 0xFFFFFF96, 0xFFFFFF96, 0xFFFFFF96, 0xFFFFFF96, 0xFFFFFF96, 0xFFFFFF96};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep27(void) { const unsigned long *volatile cp; cp = fzgx_pool_table27; }  /* fzgx-allow: S2 pool primer sink */
static const unsigned long fzgx_pool_table28[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const unsigned long *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
static const unsigned long fzgx_pool_table29[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep29(void) { const unsigned long *volatile cp; cp = fzgx_pool_table29; }  /* fzgx-allow: S2 pool primer sink */
static const unsigned long fzgx_pool_table30[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const unsigned long *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0010000000474974513f;
    s = 360.0f;
    s = 90.0f;
}
#pragma section code_type ".text"

typedef struct {
    u8 r, g, b, a;
} Fn403D4Color;

/* Fn408E8Obj followed by the two button colours this box draws. */
typedef struct {
    Fn408E8Obj base;         /* 0x00 */
    u32 unk_24;
    Fn403D4Color colors[2];  /* 0x28 */
} Fn403D4Obj;

#define COLORS(o) (((Fn403D4Obj *)(o))->colors)

extern char *fn_1_15BA78(char *);
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(u8);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_494DC(s16);
extern void fn_1_4955C(f32, f32);
extern f32 fn_1_4B068(char *);
extern f32 fn_1_4B090(char *);
extern void fn_1_49514(u32 *);
extern void fn_1_495A0(f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);

void fn_1_403D4(Fn408E8Obj *obj) {
    f32 textH;
    f32 fade;
    f32 lineH;
    f32 h;
    u32 header;
    s32 i;
    char *text;

    fade = obj->fade;
    text = fn_1_15BA78((char *)obj->unk_4);
    fn_1_49410();
    fn_1_495FC();
    fn_1_4954C(obj->z - 0.001f);
    fn_1_495C8(1);
    fn_1_49590(0.4f);
    fn_1_495B0(0x80000000);
    fn_1_494DC(0x2a);
    fn_1_4955C(0.75f, 0.75f * obj->fade);

    obj->width = (f32)(s32)(150.0f + fn_1_4B068(text));
    if (obj->width < 360.0f) {
        obj->width = 360.0f;
    }
    h = fn_1_4B090(text);
    lineH = 30.0f + h;
    textH = h * fn_1_403D4_pool_scale[0];
    *(volatile f32 *)&obj->height = 90.0f + lineH; /* fzgx-allow: S2 preserve the height publication before reading the shared colour */

    header = ((volatile u32 *)fzgx_pool_table28)[0]; /* fzgx-allow: S2 retain retail shared-pool read ordering */
    fn_1_49514(&header);
    fn_1_495A0(obj->fade);
    fn_1_496FC(obj->x, textH + ((obj->y - lineH) + (f32)((1.0f - fade) * lineH)));
    fn_1_4A0D8(text);
    fn_1_496FC(obj->x, textH + ((obj->y - 10.0f) + (f32)(10.0f * (1.0f - fade))));

    for (i = 0; i < 2; i++) {
        const char *labels[2];
        u32 color;
        f32 alpha;

        labels[0] = (char *)((volatile u32 *)fzgx_pool_table29)[0]; /* fzgx-allow: S2 reload shared label words each iteration */
        labels[1] = (char *)((volatile u32 *)fzgx_pool_table30)[0]; /* fzgx-allow: S2 reload shared label words each iteration */
        color = *(u32 *)&COLORS(obj)[i];
        fn_1_49514(&color);
        alpha = fade * ((f32)COLORS(obj)[i].a / 255.0f);
        if (alpha < 0.0f) {
            alpha = 0.0f;
        }
        fn_1_495A0(alpha);
        fn_1_496FC((obj->x - 90.0f) + (f32)(i * 180), textH + (obj->y + 20.0f * fade));
        fn_1_4A0D8(fn_1_15BA78((char *)labels[i]));
    }
}
/* fzgx:end fn_1_403D4 */

/* fzgx:begin fn_1_40710 */
typedef struct {
    u8 state;
    u8 enabled;
    u8 applied;
    u8 flags;
    u8 pad[0x24];
    u32 value_28;
    u32 value_2c;
} Fn40710Object;



void fn_1_40710(Fn40710Object *obj) {
    Fn40710Object *self = obj;
    Fn40710Config *config = &lbl_1_rodata_BD8;
    int state = self->state;
    u8 *values;
    u32 limits[8];
    u32 flags;

    switch (state) {
    case 2:
        self->enabled &= 1;
        if (self->enabled != 0) {
            self->value_2c = config->value_2f8;
            values = (u8 *)&self->value_28;
        } else {
            self->value_28 = config->value_2fc;
            values = (u8 *)&self->value_2c;
        }
        limits[0] = config->value_300;
        if (values[0] < ((u8 *)&limits[0])[0] - 0x14) {
            values[0] += 0x14;
        } else {
            limits[1] = config->value_304;
            values[0] = ((u8 *)&limits[1])[0];
        }
        limits[2] = config->value_308;
        if (values[1] < ((u8 *)&limits[2])[1] - 0x14) {
            values[1] += 0x14;
        } else {
            limits[3] = config->value_30c;
            values[1] = ((u8 *)&limits[3])[1];
        }
        limits[4] = config->value_310;
        if (values[2] < ((u8 *)&limits[4])[2] - 0x14) {
            values[2] += 0x14;
        } else {
            limits[5] = config->value_314;
            values[2] = ((u8 *)&limits[5])[2];
        }
        limits[6] = config->value_318;
        if (values[3] > ((u8 *)&limits[6])[3] + 0x14) {
            values[3] -= 0x14;
        } else {
            limits[7] = config->value_31c;
            values[3] = ((u8 *)&limits[7])[3];
        }
        // The case-2 path joins the shared state update below.
        goto update_state;
    case 0:
        // The case-0 path joins the shared state update below.
        goto update_state;
    case 1:
        // The case-1 path joins the shared state update below.
        goto update_state;
    default:
        break;
    }
    return;

update_state:
    if (self->enabled != self->applied) {
        /* fzgx-allow: A1 absolute game data address */
        fn_1_A2DC4((u32)0xA9011300);
        self->applied = self->enabled;
    }
    if ((self->flags & 2) != 0) {
        /* fzgx-allow: A1 absolute game data address */
        fn_1_A2DC4((u32)0xA9011100);
        flags = __rlwinm(self->flags, 0, 24, 29);
        self->flags = flags;
    } else if ((self->flags & 4) != 0) {
        /* fzgx-allow: A1 absolute game data address */
        fn_1_A2DC4((u32)0xA9011000);
        self->flags = self->flags & -6;
    }
}
/* fzgx:end fn_1_40710 */

/* fzgx:begin fn_1_408E8 */
#pragma opt_common_subs off
void fn_1_408E8(Fn408E8Obj *obj) {
    struct fn_1_408E8_lbl_1_rodata_BD8 *pool = &(*((struct fn_1_408E8_lbl_1_rodata_BD8 *)&lbl_1_rodata_BD8));
    u32 header;             /* the packet follows this word in the frame */
    FontDrawPacket pkt;
    f32 scale;
    s32 w;
    s32 h;
    s32 clipW;
    s32 clipH;

    if (obj->flags & 1) {
        if (obj->fade < pool->unk_340) {
            obj->fade = obj->fade + pool->unk_1BC;
        } else {
            obj->fade = pool->unk_C;
        }
    } else {
        if (obj->fade > pool->unk_1BC) {
            obj->fade = obj->fade - pool->unk_1BC;
        } else {
            obj->fade = pool->unk_4;
            return;
        }
    }

    scale = pool->unk_1CC * obj->fade;
    if (scale > pool->unk_C) {
        scale = pool->unk_C;
    }

    switch (obj->type) {
    case 1:
        if (obj->data != NULL) {
            break;
        }
        /* fallthrough */
    case 0:
        w = (s32)(obj->width * scale);
        h = (s32)(obj->height * scale);
        break;
    case 2:
        fn_1_403D4(obj);
        w = (s32)obj->width;
        h = (s32)(obj->height * scale);
        break;
    default:
        return;
    }

    pkt = lbl_1_rodata_26F8;
    pkt.x = obj->x;
    pkt.y = obj->y;
    pkt.z = obj->z;
    pkt.flags = 10;
    pkt.image = 2;
    pkt.alpha = obj->fade;
    clipW = (s32)(pool->unk_1DC * (pool->unk_44 * obj->fade));
    clipH = (s32)(pool->unk_1DC * (pool->unk_3C * obj->fade));
    if (clipW > 18 || w > 18) {
        clipW = 18;
    }
    if (clipH > 45 || h > 45) {
        clipH = 45;
    }
    fn_1_50A90(&pkt, clipW, clipH, w, h);
    header = pool->unk_33C;
    fn_1_49514(&header);
    fn_1_49614();
}
/* fzgx:end fn_1_408E8 */

/* fzgx:begin fn_1_40B14 */
u8 *fn_1_40B14(void) {
    return lbl_1_bss_26B54;
}
/* fzgx:end fn_1_40B14 */

/* fzgx:begin fn_1_40B20 */
s32 fn_1_40B20(void) {
    s32 i;
    u8 *q;
    s32 n;
    u8 a7;
    u8 min;
    u8 v;

    if (lbl_1_bss_3C30.unk_5 == 5) {
        return *(s8 *)((u8 *)&lbl_1_bss_9C + 6);
    }
    if (lbl_1_bss_3C30.unk_5 != 1) {
        return -1;
    }
    a7 = lbl_1_bss_3C30.unk_A7;
    if (a7 == 0) {
        return -1;
    }
    n = lbl_1_bss_3C30.unk_9;
    q = (u8 *)&lbl_1_bss_3C30 + a7;
    min = lbl_1_bss_3C30.unk_8;
    for (i = 0; i < n; i++) {
        v = *(u8 *)((u8 *)&lbl_1_bss_3C30 + i + 0x1394);
        if ((s32)v >= (s32)min) {
            if (q[v * 160 + 226] != 254) {
                return v;
            }
        }
    }
    return -1;
}
/* fzgx:end fn_1_40B20 */

/* fzgx:begin fn_1_40BB4 */
u8 fn_1_40BB4(void) {
    return (s8)lbl_1_bss_5104.unk_0 != -1;
}
/* fzgx:end fn_1_40BB4 */

/* fzgx:begin fn_1_40BD4 */
void fn_1_40BD4(void) {
    lbl_1_bss_3820C = 0;
}
/* fzgx:end fn_1_40BD4 */

/* fzgx:begin fn_1_40D44 */
void fn_1_40D44(void) {
    u32 result;
    u32 state;
    u32 arg;

    result = fn_1_40EE4();
    state = lbl_1_bss_3C1C.unk_0;
    if ((state + 0x10000) == 0xffff) {
        lbl_1_bss_3C1C.unk_0 = 0;
        arg = lbl_801A63D0;
    } else {
        arg = state;
    }

    ARQPostRequest(lbl_1_bss_38218, 0, 0, 1, arg, result,
                lbl_1_bss_26C34[0], 0);

    lbl_1_bss_3820C = lbl_1_bss_3820C + 1;
    if (lbl_1_bss_3820C > 6 || result >= 0x00f95fff) {
        lbl_1_bss_3820C = 6;
    }

    fn_1_4060();
}
/* fzgx:end fn_1_40D44 */

/* fzgx:begin fn_1_40E08 */
// Initializes the random-selection bounds and schedules the next callback.
void fn_1_40E08(u32 arg0) {
    u32 value;
    u32 half;
    u32 max;
    u32 remainder;

    if (*(s16 *)&lbl_1_bss_960 == 0x10) {
        lbl_1_bss_3C1C.unk_0 = -1;
    }

    lbl_1_bss_38210 = arg0;
    if (arg0 < 5) {
        lbl_1_bss_38210 = 5;
    }

    value = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    lbl_801A63C0 = value;

    half = lbl_1_bss_38210 >> 1;
    max = lbl_1_bss_38210 - 5;
    remainder = ((value >> 16) & 0x7FFF) % half;
    lbl_1_bss_38214 = half + remainder;
    if (lbl_1_bss_38214 > max) {
        lbl_1_bss_38214 = max;
    }

    fn_1_3F8C(lbl_1_data_662C, (void *)(void (*)(void))(fn_1_40BE4), 0, 1);
}
/* fzgx:end fn_1_40E08 */

/* fzgx:begin fn_1_40ED4 */
u8 fn_1_40ED4(void) {
    return lbl_1_bss_3820C;
}
/* fzgx:end fn_1_40ED4 */

/* fzgx:begin fn_1_40EE4 */
u32 fn_1_40EE4(void) {
    u32 t0;
    return (((lbl_1_bss_3820C * (((GXGetTexBufferSize(320, 224, 1, 0, 0)) + 31) & ~0x1F)) + 0xF20000) + 16384);
}
/* fzgx:end fn_1_40EE4 */

/* fzgx:begin fn_1_40F34 */
u32 fn_1_40F34(void) {
    return lbl_1_bss_26B4C;
}
/* fzgx:end fn_1_40F34 */

/* fzgx:begin fn_1_40F44 */
u8 fn_1_40F44(void) {
    return lbl_1_bss_25E90[0];
}
/* fzgx:end fn_1_40F44 */

/* fzgx:begin fn_1_40F54 */
// Initializes the related game state with the standard allocation size.
void fn_1_40F54(void *arg0) {
    fn_1_48B0( (u32)(void *)(arg0), 0x20);
}
/* fzgx:end fn_1_40F54 */

/* fzgx:begin fn_1_40F78 noprologue */
#include "types.h"
#include "font.h"
#include "game/main_rel/game_types.h"

extern u32 lbl_1_bss_38450;
extern u8 lbl_1_data_66C0[0x10];
extern u8 lbl_1_data_66D0[0x10];

extern u32 lbl_801A6CE0;
extern u32 lbl_1_bss_38454;
extern u32 fn_80070DE0(void (*)(void));
extern void fn_1_40F54(void *arg0);
extern void *fn_1_D3884(u8 *arg0);
extern void *fn_1_D358C(u8 *arg0, void *arg1);

extern u32 lbl_801A6CE0;
extern u32 lbl_1_bss_38454;
extern u32 fn_80070DE0(void (*)(void));
extern void fn_1_40F54(void *arg0);
extern void *fn_1_D3884(u8 *arg0);
extern void *fn_1_D358C(u8 *arg0, void *arg1);

// Initializes the shared resource handles when the subsystem is enabled.
void fn_1_40F78(void) {
    u32 resource_handle;
    void *decoded_data;

    if ((lbl_801A6CE0 & 1) == 0) {
        lbl_1_bss_38450 = 0;
        lbl_1_bss_38454 = 0;
        return;
    }

    resource_handle = fn_80070DE0((void (*)(void))fn_1_40F54);
    decoded_data = fn_1_D3884((u8 *)lbl_1_data_66C0);
    lbl_1_bss_38450 = (u32)decoded_data;
    lbl_1_bss_38454 = (u32)fn_1_D358C((u8 *)lbl_1_data_66D0, decoded_data);
    fn_80070DE0((void (*)(void))resource_handle);
}
/* fzgx:end fn_1_40F78 */

/* fzgx:begin fn_1_4100C */
// Initializes both shared data blocks with their default state.
void fn_1_4100C(void) {
    fn_1_465D0((char *)lbl_1_data_66E0, 1);
    fn_1_465D0((char *)lbl_1_data_66F0, 1);
}
/* fzgx:end fn_1_4100C */

/* fzgx:begin fn_1_41048 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/game.h"

extern void *fn_1_D3884(u8 *arg0);
extern void *fn_1_D358C(u8 *arg0, void *arg1);

extern void *fn_1_D3884(u8 *arg0);
extern void *fn_1_D358C(u8 *arg0, void *arg1);

void fn_1_41048(void) {
    void *value;

    if (lbl_1_bss_38458 == 0) {
        value = fn_1_D3884(lbl_1_data_66E0);
        lbl_1_bss_3845C = (u32)value;
        lbl_1_bss_38458 = (Obj_1_bss_38458_Target *)fn_1_D358C(lbl_1_data_66F0, value);
    }
}
/* fzgx:end fn_1_41048 */

/* fzgx:begin fn_1_410A0 */
void fn_1_410A0(void) {
    if (lbl_1_bss_38458 != 0) {
        fn_800711A8(lbl_1_bss_38458);
        lbl_1_bss_38458 = 0;
    }

    if (lbl_1_bss_3845C != 0) {
        fn_80071718(lbl_1_bss_3845C);
        lbl_1_bss_3845C = 0;
    }
}
/* fzgx:end fn_1_410A0 */

/* fzgx:begin fn_1_41104 */
// Forwards the selected message entry to the formatter.
void fn_1_41104(u32 message_index) {
    char *message = *(char **)(lbl_1_data_66A0 + message_index * sizeof(char *));
    fn_1_41134((void *)message_index, message);
}
/* fzgx:end fn_1_41104 */

/* fzgx:begin fn_1_41134 */
// Format the value with each registered template and publish both results.
void fn_1_41134(void *unused, char *value) {
    char buffer[128];

    sprintf(buffer, (const char *)(u32 *)(&lbl_1_data_6700), value);
    fn_1_465D0(buffer, 1);
    sprintf(buffer, (const char *)(u32 *)(&lbl_1_data_6708), value);
    fn_1_465D0(buffer, 1);
}
/* fzgx:end fn_1_41134 */

/* fzgx:begin fn_1_411A4 */
// Forwards the indexed message entry to the follow-up handler.
void fn_1_411A4(u32 index) {
    fn_1_411D4(index, ((char **)lbl_1_data_66A0)[index]);
}
/* fzgx:end fn_1_411A4 */

/* fzgx:begin fn_1_411D4 pool noprologue */
#include "types.h"
#include "rel/main_rel/game.h"

typedef struct Fn411D4Cache {
    u8 pad_00[0x10];
    u32 flags[7];
    int cached[7];
    char *generated[7];
} Fn411D4Cache;

extern int sprintf(char *buffer, char *format, ...);
extern int fn_80016DF8(char *buffer);
extern void fn_1_412A0(u32 index);
extern char *fn_1_D3884(char *buffer);
extern int fn_1_D358C(char *buffer, char *value);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_38450;
u32 fzgx_obj_lbl_1_bss_38454;
u32 fzgx_obj_lbl_1_bss_38458;
u32 fzgx_obj_lbl_1_bss_3845C;
u8 fzgx_obj_lbl_1_bss_38460;
u8 lbl_1_bss_38460_fill_38461;
u16 lbl_1_bss_38460_fill_38462;
u32 lbl_1_bss_38460_fill_38464[6];
u8 lbl_1_bss_38460_1C;
u8 lbl_1_bss_38460_fill_3847D;
u16 lbl_1_bss_38460_fill_3847E;
u32 lbl_1_bss_38460_fill_38480[6];
u8 lbl_1_bss_38460_38;
u8 lbl_1_bss_38460_fill_38499;
u16 lbl_1_bss_38460_fill_3849A;
u32 lbl_1_bss_38460_fill_3849C[6];
u32 fzgx_obj_lbl_1_bss_384B4;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_38450;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_38454;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_38458;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3845C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_38460;
    s = *(u8 *)&lbl_1_bss_38460_fill_38461;
    s = *(u8 *)&lbl_1_bss_38460_fill_38462;
    s = *(u8 *)&lbl_1_bss_38460_fill_38464;
    s = *(u8 *)&lbl_1_bss_38460_1C;
    s = *(u8 *)&lbl_1_bss_38460_fill_3847D;
    s = *(u8 *)&lbl_1_bss_38460_fill_3847E;
    s = *(u8 *)&lbl_1_bss_38460_fill_38480;
    s = *(u8 *)&lbl_1_bss_38460_38;
    s = *(u8 *)&lbl_1_bss_38460_fill_38499;
    s = *(u8 *)&lbl_1_bss_38460_fill_3849A;
    s = *(u8 *)&lbl_1_bss_38460_fill_3849C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384B4;
}
#pragma section code_type ".text"

void fn_1_411D4(u32 index, char *value) {
    char second_buffer[128];
    char buffer[128];
    int key;
    u32 *flags;
    struct { u32 value; } off;

    
    sprintf(buffer, (char *)&lbl_1_data_6708, value);
    key = fn_80016DF8(buffer);
    off.value = index * 4;
    flags = (u32 *)&fzgx_obj_lbl_1_bss_38460;

    if (*(u32 *)((u8 *)flags + off.value) == 0 ||
        *(int *)((u8 *)&lbl_1_bss_38460_1C + off.value) != key) {
        fn_1_412A0(index);
        *(int *)((u8 *)&lbl_1_bss_38460_1C + off.value) = key;
        sprintf(second_buffer, (char *)&lbl_1_data_6700, value);
        *(char **)((u8 *)&lbl_1_bss_38460_38 + off.value) = fn_1_D3884(second_buffer);
        *(u32 *)((u8 *)flags + off.value) =
            fn_1_D358C(buffer, *(char **)((u8 *)&lbl_1_bss_38460_38 + off.value));
    }
}
/* fzgx:end fn_1_411D4 */

/* fzgx:begin fn_1_412A0 */
typedef struct BssState {
    u8 pad_10[0x10];
    u32 second[7];
    s32 third[7];
    u32 first[7];
} BssState;


/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_38450;
u32 fzgx_obj_lbl_1_bss_38454;
u32 fzgx_obj_lbl_1_bss_38458;
u32 fzgx_obj_lbl_1_bss_3845C;
u32 fzgx_obj_lbl_1_bss_38460[7];
s32 lbl_1_bss_38460__fzgx_offset_1C[7];
u32 lbl_1_bss_38460__fzgx_offset_38[7];
u32 fzgx_obj_lbl_1_bss_384B4;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_38450;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_38454;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_38458;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3845C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_38460;
    s = *(u8 *)&lbl_1_bss_38460__fzgx_offset_1C;
    s = *(u8 *)&lbl_1_bss_38460__fzgx_offset_38;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384B4;
}
#pragma section code_type ".text"

void fn_1_412A0(u32 index) {
    

    if (lbl_1_bss_38460__fzgx_offset_38[index] != 0) {
        fn_80071718( (u32)((void *)lbl_1_bss_38460__fzgx_offset_38[index]));
    }

    if (fzgx_obj_lbl_1_bss_38460[index] != 0) {
        fn_800711A8( (Obj_1_bss_38458_Target *)((void *)fzgx_obj_lbl_1_bss_38460[index]));
    }

    lbl_1_bss_38460__fzgx_offset_38[index] = 0;
    fzgx_obj_lbl_1_bss_38460[index] = 0;
    lbl_1_bss_38460__fzgx_offset_1C[index] = -1;
}
/* fzgx:end fn_1_412A0 */

/* fzgx:begin fn_1_41328 */
typedef struct RelocData {
    u32 count;
    u32 values[1];
} RelocData;

void fn_1_41328(RelocData *data) {
    u32 *values = data->values;
    u32 count = data->count;
    u32 i = 0;

    if (count & ((u32)1 << 31)) {
        return;
    }

    for (i = 0; i <= count; i++) {
        values[i] += (u32)data;
    }

    data->count |= ((u32)1 << 31);
}
/* fzgx:end fn_1_41328 */

/* fzgx:begin fn_1_41418 */
typedef struct Fn41418Data {
    u32 count;
    char *strings;
} Fn41418Data;

static inline u32 add_lengths(u32 length, u32 address) {
    return length + address;
}

char *fn_1_41418(Fn41418Data *data, u32 index) {
    u32 count = data->count & 0x7fffffff;
    u32 str = (u32)data->strings;

    if (index >= count) {
        return 0;
    }

    while (index != 0) {
        str = add_lengths((u32)strlen((char *)str), str);
        index -= 1;
        str += 1;
    }

    return (char *)str;
}
/* fzgx:end fn_1_41418 */

/* fzgx:begin fn_1_41488 */
typedef struct Fn41488Data {
    u32 count;
    char *strings;
} Fn41488Data;

static inline u32 add_lengths(u32 length, u32 address) {
    return length + address;
}

int fn_1_41488(Fn41488Data *data, const char *value) {
    u32 count = data->count & 0x7fffffff;
    u32 str = (u32)data->strings;
    u32 index = 0;

    while (index < count) {
        if (fn_80083BCC(value, (const char *)str) == 0) {
            return index;
        }
        str = add_lengths((u32)strlen((const char *)str), str);
        index += 1;
        str += 1;
    }

    return -1;
}
/* fzgx:end fn_1_41488 */

/* fzgx:begin fn_1_41CB8 */
typedef struct F41Node { u8 pad[0x30]; struct F41Node *next; } F41Node;
typedef struct F41Ent { u8 pad0[4]; F41Node *head; u8 pad8[2]; u16 cnt; } F41Ent;
typedef struct F41D { u16 f0; u16 f2; s16 f4; u16 p6; u32 f8; } F41D;
typedef struct F41Obj {
    u8 pad0;
    u8 count;
    u16 flags;
    u8 pad4[4];
    void *obj8;
    u8 padC[6];
    u16 idx;
    u8 pad14[0x12];
    u8 n26;
    u8 pad27;
    F41Ent *tab28;
    F41D *tab2C;
    F41D *tab30;
    F41Ent *tab34;
    u8 pad38[0x14];
    u8 base4C;
} F41Obj;

extern void fn_1_42E74(void *);
extern F41D *fn_1_42044(F41Obj *, s32);
extern F41D *fn_1_42254(F41Obj *, s32);
extern void fn_1_42458(F41D *, const F41D *);

#pragma opt_lifetimes on
void fn_1_41CB8(F41Obj *o) {
    struct F41Node * fzgx_live;
    F41Ent *e;
    s32 off;
    s32 i;
    F41D *p;
    F41D *a;
    F41D *b;
    F41D *src;
    fn_1_42E74(o->obj8);
    if (o->idx < o->n26) {
        e = (F41Ent *)((u8 *)o->tab28 + o->idx * 12);
    } else if (o->tab34 != 0) {
        e = (F41Ent *)((u8 *)o->tab34 + (o->idx - o->base4C) * 12);
    }
    if ((o->flags & 1) == 0) {
        struct { s32 value; } k;
        /* Preserve the node traversal loads. */
        volatile F41Node *q;
        u16 n = e->cnt;
        q = e->head;
        for (k.value = 0; k.value < n; k.value++) {
            q = q->next;
        }
    }
    i = 0;
    off = 0;
    for (; i < o->count; i++) {
        p = fn_1_42044(o, i);
        a = (F41D *)((u8 *)o->tab2C + off);
        b = (F41D *)((u8 *)o->tab30 + off);
        if (p != 0) {
            src = fn_1_42254(o, i);
        } else {
            p = (F41D *)lbl_1_data_6710;
            src = p;
        }
        if ((a->f0 & 4) == 0) {
            fn_1_42458(a, src);
        }
        fn_1_42458(b, p);
        off += 0x10;
    }
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_41CB8 */
