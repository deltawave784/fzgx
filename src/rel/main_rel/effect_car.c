#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/effect_car.h"
#include "dolphin/hw_regs.h"
#include "game/main_rel/effect_car_types.h"

extern void *memset(void *dest, int value, u32 size);
extern void *lbl_801A6410;
extern void fn_1_867CC(s16 arg0, void *arg1);
extern u16 fn_1_584AC(void);
extern s16 fn_1_59078(void *arg0);
extern u32 fn_1_864E8(int index);
extern s16 fn_1_58F50(const void *source);
extern u32 lbl_1_rodata_314C[13];
extern void lbl_8006DC6C(void *arg0, u32 arg1);
extern void lbl_8006E1B0(void *arg0, void *arg1);
extern void fn_1_6F90C(void *arg0, void *arg1);
extern s16 fn_1_72318();
extern void fn_1_71D0C(void *arg0, void *arg1);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern u32 fn_1_4630();
extern void fn_1_862D4(s16 value, void *result);
extern s16 fn_1_58E3C(void *source);
extern u32 fn_1_58C4(void);
extern s8 lbl_1_bss_6C878[];
extern void *fn_1_868C0(s8 index);
extern u32 fn_1_71024(void *, void *, u32, f32);
extern u32 fn_1_7099C(void *, void *, u32, f32, f32);
extern u32 fn_1_71768(void *, void *);
extern u32 fn_1_702A0(void *, void *, u32, u32);
extern u32 fn_80008C20(void *, void *, void *);
extern u32 lbl_8006E1C0(void *, void *);
extern u32 fn_1_6FD58(void *, void *, f32, f32);
extern void fn_1_A33F0(s32 id, f32 level);
extern u32 fn_1_6D7BC(void *, void *, f32);
extern u32 fn_1_A5594(u32, void *);

/* fzgx:begin fn_1_680F8 */
typedef struct Fn1_680F8Arg {
    u8 pad_00[0x18];
    s16 unk_18;
    u16 unk_1a;
    u8 pad_1c[0x18];
    u32 unk_34;
    u8 *unk_38;
    u8 unk_3c[4];
} Fn1_680F8Arg;

typedef struct Fn1_680F8Entry {
    u8 pad_00[0x0c];
    u16 unk_0c;
    u8 pad_0e[0x0a];
    s16 unk_18;
    u8 pad_1a[0x1e];
    u8 *unk_38;
    u8 pad_3c[0xac];
} Fn1_680F8Entry;

void fn_1_680F8(Fn1_680F8Arg *arg) {
    u8 *p;
    Fn1_680F8Entry entry;
    u32 n;
    s32 i;

    arg->unk_1a = 0xffff;
{
    u8 *base;
    base = arg->unk_38;
    arg->unk_34 = fn_1_4630((u32)lbl_801A6410, 0x300, lbl_1_data_1D8A8, 0xc7);
    fn_1_862D4(arg->unk_18, arg->unk_3c);
    memset( (void *)((u8 *)&entry), 0, 0xe8);
    entry.unk_18 = arg->unk_18;
    entry.unk_0c = 4;
    p = base;
}
    for (i = 0; i < 4; i++) {
        entry.unk_38 = p + 0x3b4;
        fn_1_58E3C(&entry);
        p += 0x30;
    }
    n = fn_1_58C4();
    for (i = 0; i < n; i++) {
        lbl_1_bss_6C878[i * 24] = -1;
    }
}
/* fzgx:end fn_1_680F8 */

/* fzgx:begin fn_1_68248 */
typedef struct Fn1_68248Arg {
    u8 pad0[0x34];
    void *unk_34;
} Fn1_68248Arg;

// Register the effect resource with the shared effect manager.
void fn_1_68248(Fn1_68248Arg *arg) {
    fn_1_46B4((u32)lbl_801A6410, (u32)(void *)(arg->unk_34), (const char *)(u8 *)(lbl_1_data_1D8A8), 0xe2);
}
/* fzgx:end fn_1_68248 */

/* fzgx:begin fn_1_68B68 */
// Stub function that immediately returns.
void fn_1_68B68(void) {
}
/* fzgx:end fn_1_68B68 */

/* fzgx:begin fn_1_69BBC */
typedef struct fn_1_69BBC_EffectCar {
    u8 pad_00[0x1a];
    u16 field_1a;
} fn_1_69BBC_EffectCar;

void fn_1_69BBC(fn_1_69BBC_EffectCar *car) {
    car->field_1a = 0xffff;
}
/* fzgx:end fn_1_69BBC */

/* fzgx:begin fn_1_6D6A8 */
struct Fn1_6D6A8Car {
    u8 pad_00[0x18];
    s16 field_18;
};

struct Fn1_6D6A8Work {
    u8 pad_00[0x8];
    u32 field_08;
    s16 field_0c;
    u8 pad_0e[0xa];
    s16 field_18;
    u16 field_1a;
    f32 field_1c;
    f32 field_20;
    f32 field_24;
    f32 field_28;
    u8 pad_2c[0x8];
    u32 field_34;
    u8 pad_38[0x4];
    f32 field_3c[3];
    u8 pad_48[0x68];
    u16 field_b0;
    u8 pad_b2[0x36];
};

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -1.0f;
    s = 25.0f;
    s = 15.0f;
    s = 8.0f;
    s = 150.0f;
    s = 10.0f;
    s = 0.5f;
    s = 0.125f;
    s = 32767.0f;
    s = 30.0f;
    s = 20.0f;
    s = 1200.0f;
    s = 0.15000000596046448f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 255.0f;
    s = 102.0f;
    d = 0.8;
    s = 1.600000023841858f;
    s = 3.0f;
    s = 0.009999999776482582f;
    s = 0.6000000238418579f;
    d = 0.3;
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 0.10000000149011612f;
    s = 1.5f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 0.800000011920929f;
    s = 1.0f;
    s = 85.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 3.5f;
    s = 23.0f;
    s = 60.0f;
    s = 4.0f;
}
static const u32 fzgx_pool_table6[1] = {0x34000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.30000001192092896f;
    s = 128.0f;
    s = 224.0f;
    s = 500.0f;
    s = 0.9300000071525574f;
    s = 5.0f;
    s = 2.0f;
    s = 0.05000000074505806f;
    s = 0.07999999821186066f;
    s = 0.8999999761581421f;
    d = 0.30000001192092896;
    d = 0.2;
    d = -0.3;
    d = -1.0;
    d = 0.0;
    d = 30.0;
    d = 3.0;
    s = 0.0010000000474974513f;
    s = 0.0020000000949949026f;
    s = 1.899999976158142f;
    s = 10000.0f;
    s = 3000.0f;
    s = 182.04444885253906f;
    s = 0.5647059082984924f;
    s = 0.6901960968971252f;
    s = 3.605555534362793f;
}
static const u32 fzgx_pool_table10[1] = {0x20000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 5.0;
    s = 1.7774999141693115f;
    s = -5.004882768844254e-05f;
    s = 16384.0f;
}
static const u32 fzgx_pool_table12[3] = {0x00000000, 0x3DCCCCCD, 0x3FC00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 1000.0f;
    d = 0.05;
    d = 12.0;
    d = -0.16;
    d = 119.0;
    d = 2.5;
    d = 1.0;
    s = 1250.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    s = 300.0f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.20000000298023224;
    s = 2500.0f;
    s = 5000.0f;
    d = 0.1;
    d = 50.0;
    d = 0.0003;
    d = 0.02;
    s = 1.2000000476837158f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6;
    s = 44.0f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.3;
    s = 0.0005000000237487257f;
}
static const u32 fzgx_pool_table22[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.003;
    s = 20000.0f;
}
static const u32 fzgx_pool_table24[3] = {0x00000000, 0x3F800000, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 34.0f;
}
static const u32 fzgx_pool_table26[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 10.0;
}
static const u32 fzgx_pool_table28[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -2.0f;
    s = 768.0f;
}
static const u32 fzgx_pool_table30[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 16.0f;
    s = 4096.0f;
    s = 6.0f;
    s = 1820.4444580078125f;
    s = 119.0f;
    s = 51.0f;
}
static const u32 fzgx_pool_table32[3] = {0x00000000, 0x3DCCCCCD, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const u32 *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5f;
    s = 400.0f;
    s = 2000.0f;
    s = 176.0f;
}
static const u32 fzgx_pool_table34[6] = {0x00000000, 0x3DCCCCCD, 0x40000000, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const u32 *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime35(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.7999999523162842f;
}
static const u32 fzgx_pool_table36[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep36(void) { const u32 *volatile cp; cp = fzgx_pool_table36; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime37(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.3333333432674408;
    d = 0.800000011920929;
}
static const u32 fzgx_pool_table38[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep38(void) { const u32 *volatile cp; cp = fzgx_pool_table38; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime39(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.5f;
    s = 1.2999999523162842f;
    s = -1.2000000476837158f;
    s = 1500.0f;
}
static const u32 fzgx_pool_table40[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep40(void) { const u32 *volatile cp; cp = fzgx_pool_table40; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime41(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4000000059604645;
}
static const u32 fzgx_pool_table42[4] = {0x00000000, 0x3DCCCCCD, 0x3FC00000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep42(void) { const u32 *volatile cp; cp = fzgx_pool_table42; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime43(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 40.0;
    s = -2.5f;
    s = 1280.0f;
}
#pragma section code_type ".text"

// Spawn the car effect with a randomised brightness.
void fn_1_6D6A8(struct Fn1_6D6A8Car *car) {
    struct Fn1_6D6A8Work work;
    f32 t;
    f32 ratio;
    f32 scale;

    memset(&work, 0, sizeof(work));
    work.field_18 = car->field_18;
    work.field_0c = 0xe;
    work.field_1a = 0xffff;
    work.field_34 = *(u32 *)(lbl_1_bss_38458->unk_8 + 0x88);
    work.field_08 |= 0x40000;
    fn_1_867CC(car->field_18, work.field_3c);
    work.field_28 = 4.0f;
    work.field_b0 = 0;

    ratio = (f32)(u16)fn_1_584AC() / 32767.0f;
    scale = 0.2f * ratio;
    scale = 0.8f + scale;
    work.field_1c = (255.0f * (0.5f * (1.0f + scale))) / 255.0f;
    work.field_20 = (85.0f * scale) / 255.0f;
    work.field_24 = 0.0f;
    fn_1_59078(&work);
}
/* fzgx:end fn_1_6D6A8 */

/* fzgx:begin fn_1_6E140 */
#include "types.h"
#include "rel/main_rel/effect_car.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -1.0f;
    s = 25.0f;
    s = 15.0f;
    s = 8.0f;
    s = 150.0f;
    s = 10.0f;
    s = 0.5f;
    s = 0.125f;
    s = 32767.0f;
    s = 30.0f;
    s = 20.0f;
    s = 1200.0f;
    s = 0.15000000596046448f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 255.0f;
    s = 102.0f;
    d = 0.8;
    s = 1.600000023841858f;
    s = 3.0f;
    s = 0.009999999776482582f;
    s = 0.6000000238418579f;
    d = 0.3;
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 0.10000000149011612f;
    s = 1.5f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 0.800000011920929f;
    s = 1.0f;
    s = 85.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 3.5f;
    s = 23.0f;
    s = 60.0f;
    s = 4.0f;
    s = 1.1920928955078125e-07f;
    s = 136.0f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.30000001192092896f;
    s = 128.0f;
    s = 224.0f;
    s = 500.0f;
    s = 0.9300000071525574f;
    s = 5.0f;
    s = 2.0f;
    s = 0.05000000074505806f;
    s = 0.07999999821186066f;
    s = 0.8999999761581421f;
    d = 0.30000001192092896;
    d = 0.2;
    d = -0.3;
    d = -1.0;
    d = 0.0;
    d = 30.0;
    d = 3.0;
    s = 0.0010000000474974513f;
    s = 0.0020000000949949026f;
    s = 1.899999976158142f;
    s = 10000.0f;
    s = 3000.0f;
    s = 182.04444885253906f;
    s = 0.5647059082984924f;
    s = 0.6901960968971252f;
    s = 3.605555534362793f;
}
static const u32 fzgx_pool_table8[1] = {0x20000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 5.0;
    s = 1.7774999141693115f;
    s = -5.004882768844254e-05f;
    s = 16384.0f;
}
static const u32 fzgx_pool_table10[3] = {0x00000000, 0x3DCCCCCD, 0x3FC00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 1000.0f;
    d = 0.05;
    d = 12.0;
    d = -0.16;
    d = 119.0;
    d = 2.5;
    d = 1.0;
    s = 1250.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    s = 300.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.20000000298023224;
    s = 2500.0f;
    s = 5000.0f;
    d = 0.1;
    d = 50.0;
    d = 0.0003;
    d = 0.02;
    s = 1.2000000476837158f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6;
    s = 44.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.3;
    s = 0.0005000000237487257f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.003;
    s = 20000.0f;
}
static const u32 fzgx_pool_table22[3] = {0x00000000, 0x3F800000, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 34.0f;
}
static const u32 fzgx_pool_table24[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 10.0;
}
static const u32 fzgx_pool_table26[3] = {0x00000000, 0x00000000, 0xC0000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 768.0f;
}
static const u32 fzgx_pool_table28[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 16.0f;
    s = 4096.0f;
    s = 6.0f;
    s = 1820.4444580078125f;
    s = 119.0f;
    s = 51.0f;
}
static const u32 fzgx_pool_table30[3] = {0x00000000, 0x3DCCCCCD, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5f;
    s = 400.0f;
    s = 2000.0f;
    s = 176.0f;
}
#pragma section code_type ".text"

typedef struct { f32 x, y, z; } V3;

void fn_1_6E140(V3 *a, V3 *b, f32 s) {
    u8 buf[0xe8];
    if ((u32)fn_1_58C4() < 3) {
        f32 t, u;
        memset(buf, 0, 0xe8);
        *(s16 *)(buf + 0x1a) = 3;
        *(s16 *)(buf + 0xc) = 22;
        *(u32 *)(buf + 0x34) = *(u32 *)(((u8 *)((Obj_1_bss_38458_Target *)lbl_1_bss_38458)->unk_8) + 0xe8);
        *(V3 *)(buf + 0x3c) = *a;
        *(V3 *)(buf + 0x48) = *b;
        ((V3 *)(buf + 0x3c))->x = ((V3 *)(buf + 0x3c))->x - ((V3 *)(buf + 0x48))->x;
        ((V3 *)(buf + 0x3c))->y = ((V3 *)(buf + 0x3c))->y - ((V3 *)(buf + 0x48))->y;
        ((V3 *)(buf + 0x3c))->z = ((V3 *)(buf + 0x3c))->z - ((V3 *)(buf + 0x48))->z;
        t = s * (0.8f + (f32)(0.2f * ((f32)(u32)(fn_1_584AC() & 0xFFFF) / 32767.0f)));
        *(f32 *)(buf + 0x2c) = 5.0f * t;
        *(f32 *)(buf + 0x28) = 3.0f * t;
        u = 0.8f + (f32)(0.2f * ((f32)(u32)(fn_1_584AC() & 0xFFFF) / 32767.0f));
        *(f32 *)(buf + 0x1c) = (255.0f * (0.5f * (1.0f + u))) / 255.0f;
        *(f32 *)(buf + 0x20) = (224.0f * u) / 255.0f;
        *(f32 *)(buf + 0x24) = (176.0f * u) / 255.0f;
        *(s16 *)(buf + 0x58) = fn_1_584AC();
        *(s32 *)(buf + 0x10) = 22;
        fn_1_58F50(buf);
    }
}
/* fzgx:end fn_1_6E140 */

/* fzgx:begin fn_1_6F288 */
struct fn_1_6F288_EffectCar {
    u8 pad_00[0x18];
    s16 field_18;
    u8 pad_1a[0x1a];
    u32 field_34;
};

struct EffectData {
    u8 pad_00[0x08];
    u32 field_1c;
    u16 field_20;
    u8 pad_22[0x0a];
    s16 field_2c;
    u16 field_2e;
    u8 pad_30[0x1c];
    u32 field_4c;
    u8 pad_50[0x20];
    s16 field_70;
    u8 pad_72[0x3e];
    f32 field_b0;
    u8 pad_b4[0x48];
};

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -1.0f;
    s = 25.0f;
    s = 15.0f;
    s = 8.0f;
    s = 150.0f;
    s = 10.0f;
    s = 0.5f;
    s = 0.125f;
    s = 32767.0f;
    s = 30.0f;
    s = 20.0f;
    s = 1200.0f;
    s = 0.15000000596046448f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 255.0f;
    s = 102.0f;
    d = 0.8;
    s = 1.600000023841858f;
    s = 3.0f;
    s = 0.009999999776482582f;
    s = 0.6000000238418579f;
    d = 0.3;
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 0.10000000149011612f;
    s = 1.5f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 0.800000011920929f;
    s = 1.0f;
    s = 85.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 3.5f;
    s = 23.0f;
    s = 60.0f;
    s = 4.0f;
}
static const u32 fzgx_pool_table6[1] = {0x34000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.30000001192092896f;
    s = 128.0f;
    s = 224.0f;
    s = 500.0f;
    s = 0.9300000071525574f;
    s = 5.0f;
    s = 2.0f;
    s = 0.05000000074505806f;
    s = 0.07999999821186066f;
    s = 0.8999999761581421f;
    d = 0.30000001192092896;
    d = 0.2;
    d = -0.3;
    d = -1.0;
    d = 0.0;
    d = 30.0;
    d = 3.0;
    s = 0.0010000000474974513f;
    s = 0.0020000000949949026f;
    s = 1.899999976158142f;
    s = 10000.0f;
    s = 3000.0f;
    s = 182.04444885253906f;
    s = 0.5647059082984924f;
    s = 0.6901960968971252f;
    s = 3.605555534362793f;
}
static const u32 fzgx_pool_table10[1] = {0x20000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 5.0;
    s = 1.7774999141693115f;
    s = -5.004882768844254e-05f;
    s = 16384.0f;
}
static const u32 fzgx_pool_table12[3] = {0x00000000, 0x3DCCCCCD, 0x3FC00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 1000.0f;
    d = 0.05;
    d = 12.0;
    d = -0.16;
    d = 119.0;
    d = 2.5;
    d = 1.0;
    s = 1250.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    s = 300.0f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.20000000298023224;
    s = 2500.0f;
    s = 5000.0f;
    d = 0.1;
    d = 50.0;
    d = 0.0003;
    d = 0.02;
    s = 1.2000000476837158f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6;
    s = 44.0f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.3;
    s = 0.0005000000237487257f;
}
static const u32 fzgx_pool_table22[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.003;
    s = 20000.0f;
}
static const u32 fzgx_pool_table24[3] = {0x00000000, 0x3F800000, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 34.0f;
}
static const u32 fzgx_pool_table26[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 10.0;
}
static const u32 fzgx_pool_table28[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -2.0f;
    s = 768.0f;
}
static const u32 fzgx_pool_table30[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 16.0f;
    s = 4096.0f;
    s = 6.0f;
    s = 1820.4444580078125f;
    s = 119.0f;
    s = 51.0f;
}
static const u32 fzgx_pool_table32[3] = {0x00000000, 0x3DCCCCCD, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const u32 *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5f;
    s = 400.0f;
    s = 2000.0f;
    s = 176.0f;
}
static const u32 fzgx_pool_table34[6] = {0x00000000, 0x3DCCCCCD, 0x40000000, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const u32 *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime35(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.7999999523162842f;
}
static const u32 fzgx_pool_table36[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep36(void) { const u32 *volatile cp; cp = fzgx_pool_table36; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime37(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.3333333432674408;
    d = 0.800000011920929;
}
static const u32 fzgx_pool_table38[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep38(void) { const u32 *volatile cp; cp = fzgx_pool_table38; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime39(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.5f;
    s = 1.2999999523162842f;
    s = -1.2000000476837158f;
    s = 1500.0f;
}
static const u32 fzgx_pool_table40[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep40(void) { const u32 *volatile cp; cp = fzgx_pool_table40; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime41(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4000000059604645;
}
static const u32 fzgx_pool_table42[4] = {0x00000000, 0x3DCCCCCD, 0x3FC00000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep42(void) { const u32 *volatile cp; cp = fzgx_pool_table42; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime43(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 40.0;
    s = -2.5f;
    s = 1280.0f;
}
#pragma section code_type ".text"
void fn_1_6F288(struct fn_1_6F288_EffectCar *arg0) {
    s32 result;
    u8 temp[0xc];
    struct EffectData data;
    f32 scale;

    result = (s32)fn_1_864E8(arg0->field_18);
    fn_1_867CC(arg0->field_18, temp);
    memset(&data, 0, 0xe8);
    data.field_2c = arg0->field_18;
    data.field_20 = 0x1c;
    data.field_2e = 0xffff;
    data.field_1c |= 0x2000;

    if (result & 8) {
        data.field_4c = arg0->field_34;
        data.field_b0 = 2.5f;
        fn_1_58F50(&data);
        data.field_b0 = -2.5f;
        fn_1_58F50(&data);
    } else {
        data.field_4c = arg0->field_34;
        data.field_b0 = 2.5f;
        scale = 1280.0f * ((f32)fn_1_584AC() / 32767.0f);
        data.field_70 = 4096.0f + scale;
        fn_1_58F50(&data);
        data.field_b0 = -2.5f;
        scale = 1280.0f * ((f32)fn_1_584AC() / 32767.0f);
        data.field_70 = 4096.0f + scale;
        fn_1_58F50(&data);
    }
}
/* fzgx:end fn_1_6F288 */

/* fzgx:begin fn_1_6F404 */
void fn_1_6F404(void *arg0, void *arg1) {
    struct fn_1_6F404_lbl_1_rodata_2D70 *tbl;
    u32 sp[3];
    u16 rnd;
    f32 var_f31;
    f32 temp_f0;
    f32 temp_f1;
    void *temp_r30;
    void *temp_r27;
    void *unused;

    unused = arg1;
    tbl = &lbl_1_rodata_2D70;
    temp_r30 = (void *)(*(void **)((u8 *)(arg0) + 56));
    temp_r27 = (void *)(fn_1_868C0((s8)((s8) (*(s16 *)((u8 *)(arg0) + 24)))));
    if ((s16) (*(s16 *)((u8 *)(arg0) + 92)) == 0xA) {
        fn_1_71024((void *)(arg0), (void *)(arg1), (u32)(0x37U), (f32)(tbl->unk_31C));
        fn_1_7099C((void *)(arg0), (void *)(arg1), (u32)(0U), (f32)(tbl->unk_18), (f32)(tbl->unk_320));
    }
    if ((s16) (*(s16 *)((u8 *)(arg0) + 92)) == 5) {
        fn_1_71024((void *)(arg0), (void *)(arg1), (u32)(0x37U), (f32)(tbl->unk_31C));
        fn_1_7099C((void *)(arg0), (void *)(arg1), (u32)(0U), (f32)(tbl->unk_18), (f32)(tbl->unk_320));
        fn_1_71768((void *)(arg0), (void *)(arg1));
        fn_1_702A0((void *)(arg0), (void *)(arg1), (u32)(0x14U), (u32)(1U));
    }
    if (!((*(s32 *)((u8 *)(temp_r27) + 912)) & 0x01000000) && !((*(s32 *)((u8 *)(temp_r30) + 1420)) & 0x10)) {
        if (!((*(s32 *)((u8 *)(temp_r30) + 0)) & 2)) {
            temp_f1 = *(f32 *)((u8 *)(temp_r30) + 380);
            if (temp_f1 > tbl->unk_320) {
                temp_f0 = temp_f1 / tbl->unk_298;
                sp[0] = tbl->unk_310;
                sp[1] = tbl->unk_314;
                sp[2] = tbl->unk_318;
                var_f31 = tbl->unk_0;
                if (temp_f0 < var_f31) {
                    var_f31 = tbl->unk_0;
                } else if (temp_f0 > tbl->unk_74) {
                    var_f31 = tbl->unk_74;
                } else {
                    var_f31 = temp_f0;
                }
                fn_80008C20((void *)((u8 *)(temp_r30) + 0x7C), (void *)(arg1), (void *)((u8 *)(arg0) + 0x48));
                lbl_8006E1C0((void *)(sp), (void *)(sp));
                rnd = (s32)(u16) fn_1_584AC();
                if ((rnd % 6) == 0) {
                    fn_1_6FD58((void *)(arg0), (void *)(sp), (f32)(var_f31), (f32)(tbl->unk_1C));
                }
                fn_1_A33F0((u32)((u32) (*(s16 *)((u8 *)(temp_r30) + 4))), (f32)(tbl->unk_1C * var_f31));
                if (((u16) (*(u16 *)((u8 *)(temp_r30) + 1248)) < 0x32U)) {
                    rnd = (s32) fn_1_584AC();
                    if ((rnd % 10) == 0) {
                        fn_1_702A0((void *)(arg0), (void *)(sp), (u32)(1U), (u32)(0U));
                    }
                }
            }
        }
        if ((*(s32 *)((u8 *)(temp_r30) + 1420)) & 0x80) {
            rnd = (s32) fn_1_584AC();
            if ((rnd % 5) == 0) {
                fn_1_7099C((void *)(arg0), (void *)(arg1), (u32)(1U), (f32)(tbl->unk_7C), (f32)(tbl->unk_28));
            }
            rnd = (s32) fn_1_584AC();
            if ((rnd % 80) == 0) {
                fn_1_6D7BC((void *)(arg0), (void *)(arg1), (f32)(tbl->unk_AC));
                fn_1_6D7BC((void *)(arg0), (void *)(arg1), (f32)(tbl->unk_AC));
                fn_1_7099C((void *)(arg0), (void *)(arg1), (u32)(1U), (f32)(tbl->unk_7C), (f32)(tbl->unk_28));
                fn_1_6FD58((void *)(arg0), (void *)(arg1), (f32)(tbl->unk_D8), (f32)(tbl->unk_90));
                if ((s8) (*(u8 *)((u8 *)(temp_r30) + 1141)) >= 0) {
                    fn_1_A5594((u32)(0xA9092A00U), (void *)((u8 *)(arg0) + 0x3C));
                }
            }
        } else if ((s8) (*(u8 *)((u8 *)(temp_r30) + 1141)) != -1) {
            rnd = (s32) fn_1_584AC();
            if ((rnd % 5) == 0) {
                if ((s8) (*(u8 *)((u8 *)(temp_r30) + 1141)) >= 0) {
                    fn_1_A5594((u32)(0xA9092A00U), (void *)((u8 *)(arg0) + 0x3C));
                }
                fn_1_6D7BC((void *)(arg0), (void *)(arg1), (f32)(tbl->unk_AC));
            }
            rnd = (s32) fn_1_584AC();
            if ((rnd % 5) == 0) {
                fn_1_7099C((void *)(arg0), (void *)(arg1), (u32)(1U), (f32)(tbl->unk_7C), (f32)(tbl->unk_28));
            }
            rnd = (s32) fn_1_584AC();
            if ((rnd % 5) == 0) {
                fn_1_714A8( (struct Fn1_714A8Car *)((void *)(arg0)), (f32 *)((void *)(arg1)), (u32)(0x16U), (f32)(tbl->unk_B0));
            }
        } else {
            rnd = (s32) fn_1_584AC();
            if ((rnd % 10) == 0) {
                fn_1_6D7BC((void *)(arg0), (void *)(arg1), (f32)(tbl->unk_AC));
                fn_1_7099C((void *)(arg0), (void *)(arg1), (u32)(1U), (f32)(tbl->unk_7C), (f32)(tbl->unk_28));
            }
            rnd = (s32) fn_1_584AC();
            if ((rnd % 5) == 0) {
                fn_1_7099C((void *)(arg0), (void *)(arg1), (u32)(1U), (f32)(tbl->unk_7C), (f32)(tbl->unk_28));
            }
            rnd = (s32) fn_1_584AC();
            if ((rnd % 20) == 0) {
                fn_1_6FD58((void *)(arg0), (void *)(arg1), (f32)(tbl->unk_D8), (f32)(tbl->unk_90));
            }
        }
    }
}
/* fzgx:end fn_1_6F404 */

/* fzgx:begin fn_1_6F8D0 */
void fn_1_6F8D0(void *arg0, void *arg1) {
    struct EffectData {
        u8 pad_000[0x58c];
        u32 field_58c;
    };
    struct EffectCar {
        u8 pad_00[0x38];
        struct EffectData *field_38;
        u8 pad_3c[0x76];
        u16 field_b2;
    };
    struct EffectCar *self = (struct EffectCar *)arg0;

    if ((self->field_38->field_58c & 0x10) != 0 && self->field_b2 == 0) {
        fn_1_6F90C(arg0, arg1);
    }
}
/* fzgx:end fn_1_6F8D0 */

/* fzgx:begin fn_1_702A0 noprologue */
#include "types.h"
#include "rel/main_rel/effect_car.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -1.0f;
    s = 25.0f;
    s = 15.0f;
    s = 8.0f;
    s = 150.0f;
    s = 10.0f;
    s = 0.5f;
    s = 0.125f;
    s = 32767.0f;
    s = 30.0f;
    s = 20.0f;
    s = 1200.0f;
    s = 0.15000000596046448f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 255.0f;
    s = 102.0f;
    d = 0.8;
    s = 1.600000023841858f;
    s = 3.0f;
    s = 0.009999999776482582f;
    s = 0.6000000238418579f;
    d = 0.3;
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 0.10000000149011612f;
    s = 1.5f;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 0.800000011920929f;
    s = 1.0f;
    s = 85.0f;
    s = 0.25f;
}
static const unsigned long fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 3.5f;
    s = 23.0f;
    s = 60.0f;
    s = 4.0f;
    s = 1.1920928955078125e-07f;
    s = 136.0f;
    s = 0.029999999329447746f;
}
static const unsigned long fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.30000001192092896f;
    s = 128.0f;
    s = 224.0f;
    s = 500.0f;
    s = 0.9300000071525574f;
    s = 5.0f;
    s = 2.0f;
    s = 0.05000000074505806f;
    s = 0.07999999821186066f;
    s = 0.8999999761581421f;
    d = 0.30000001192092896;
    d = 0.2;
    d = -0.3;
    d = -1.0;
    d = 0.0;
    d = 30.0;
    d = 3.0;
    s = 0.0010000000474974513f;
    s = 0.0020000000949949026f;
    s = 1.899999976158142f;
    s = 10000.0f;
    s = 3000.0f;
    s = 182.04444885253906f;
    s = 0.5647059082984924f;
    s = 0.6901960968971252f;
    s = 3.605555534362793f;
}
static const unsigned long fzgx_pool_table8[1] = {0x20000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 5.0;
    s = 1.7774999141693115f;
    s = -5.004882768844254e-05f;
    s = 16384.0f;
}
static const unsigned long fzgx_pool_table10[3] = {0x00000000, 0x3DCCCCCD, 0x3FC00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 1000.0f;
    d = 0.05;
    d = 12.0;
    d = -0.16;
    d = 119.0;
    d = 2.5;
    d = 1.0;
    s = 1250.0f;
}
static const unsigned long fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    s = 300.0f;
}
static const unsigned long fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.20000000298023224;
    s = 2500.0f;
    s = 5000.0f;
    d = 0.1;
    d = 50.0;
    d = 0.0003;
    d = 0.02;
    s = 1.2000000476837158f;
}
static const unsigned long fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6;
    s = 44.0f;
}
static const unsigned long fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const unsigned long *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.3;
    s = 0.0005000000237487257f;
}
static const unsigned long fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const unsigned long *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.003;
    s = 20000.0f;
}
static const unsigned long fzgx_pool_table22[3] = {0x00000000, 0x3F800000, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const unsigned long *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 34.0f;
}
static const unsigned long fzgx_pool_table24[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const unsigned long *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 10.0;
}
static const unsigned long fzgx_pool_table26[3] = {0x00000000, 0x00000000, 0xC0000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const unsigned long *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 768.0f;
}
static const unsigned long fzgx_pool_table28[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const unsigned long *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 16.0f;
    s = 4096.0f;
    s = 6.0f;
    s = 1820.4444580078125f;
    s = 119.0f;
    s = 51.0f;
}
static const unsigned long fzgx_pool_table30[3] = {0x00000000, 0x3DCCCCCD, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const unsigned long *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5f;
    s = 400.0f;
    s = 2000.0f;
    s = 176.0f;
}
static const unsigned long fzgx_pool_table32[6] = {0x00000000, 0x3DCCCCCD, 0x40000000, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const unsigned long *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.7999999523162842f;
}
static const unsigned long fzgx_pool_table34[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const unsigned long *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime35(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.3333333432674408;
    d = 0.800000011920929;
}
static const unsigned long fzgx_pool_table36[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep36(void) { const unsigned long *volatile cp; cp = fzgx_pool_table36; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime37(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.5f;
    s = 1.2999999523162842f;
    s = -1.2000000476837158f;
    s = 1500.0f;
}
static const unsigned long fzgx_pool_table38[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep38(void) { const unsigned long *volatile cp; cp = fzgx_pool_table38; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime39(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4000000059604645;
}
static const unsigned long fzgx_pool_table40[4] = {0x00000000, 0x3DCCCCCD, 0x3FC00000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep40(void) { const unsigned long *volatile cp; cp = fzgx_pool_table40; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime41(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 40.0;
    s = -2.5f;
    s = 1280.0f;
}
static const unsigned long fzgx_pool_table42[3] = {0x00000000, 0x3ECCCCCD, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep42(void) { const unsigned long *volatile cp; cp = fzgx_pool_table42; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime43(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.700000047683716f;
    s = 50.0f;
}
static const unsigned long fzgx_pool_table44[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep44(void) { const unsigned long *volatile cp; cp = fzgx_pool_table44; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime45(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 72.0f;
    s = 5.699999809265137f;
    d = 0.10000000149011612;
    d = 1.399999976158142;
}
static const unsigned long fzgx_pool_table46[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep46(void) { const unsigned long *volatile cp; cp = fzgx_pool_table46; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime47(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 256.0f;
    s = 1024.0f;
}
static const unsigned long fzgx_pool_table48[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep48(void) { const unsigned long *volatile cp; cp = fzgx_pool_table48; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime49(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.05999999865889549f;
}
static const unsigned long fzgx_pool_table50[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep50(void) { const unsigned long *volatile cp; cp = fzgx_pool_table50; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime51(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.03;
    s = 0.003000000026077032f;
}
static const unsigned long fzgx_pool_table52[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep52(void) { const unsigned long *volatile cp; cp = fzgx_pool_table52; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

struct fn_1_702A0_lbl_1_rodata_2D70 {
    u8 pad_0[0x1C]; f32 unk_1C;
    u8 pad_20[4]; f32 unk_24;
    u8 pad_28[0x10]; f64 unk_38; f64 unk_40; f32 unk_48;
    u8 pad_4C[0x24]; f32 unk_70; f32 unk_74; f32 unk_78;
    u8 pad_7C[0x14]; f32 unk_90; f32 unk_94;
    u8 pad_98[0x20]; f32 unk_B8;
    u8 pad_BC[0x14]; f64 unk_D0;
    u8 pad_D8[0x18]; f32 unk_F0;
    u8 pad_F4[0x12C]; f32 unk_220;
    u8 pad_224[0x5C]; f32 unk_280;
    u8 pad_284[0xE4]; f32 unk_368;
    u8 pad_36C[4]; f64 unk_370; f32 unk_378;
};
struct fn_1_702A0_lbl_801A63C0 { u32 unk_0; };
extern struct fn_1_702A0_lbl_1_rodata_2D70 lbl_1_rodata_2D70;
extern struct fn_1_702A0_lbl_801A63C0 lbl_801A63C0;
extern void *memset(void *, int, u32);
extern u16 fn_1_584AC(void);
extern s16 fn_1_59078(void *);
extern s16 fn_1_58F50(const void *);
extern void lbl_8006D5F0(void *, void *, f32);
struct Vec702A0 { f32 x, y, z; };
struct CarData702A0 { u32 flags; u8 pad4[0x471]; s8 unk475; };
struct Car702A0 {
    u8 pad0[0x18]; s16 unk18; u8 pad1a[0x1e];
    struct CarData702A0 *unk38;
    struct Vec702A0 unk3c, unk48;
};
struct Effect702A0 {
    u8 pad0[0xc]; s16 unkc; u8 pade[2]; s32 unk10;
    u8 pad14[4]; s16 unk18; u16 unk1a;
    f32 unk1c, unk20, unk24, unk28; u32 unk2c, unk30, unk34, unk38;
    struct Vec702A0 unk3c, unk48;
    u8 pad54[6]; s16 unk5a, unk5c, unk5e;
    u8 pad60[0x28]; f32 unk88, unk8c;
    u8 pad90[0x58];
};
static inline s32 rand702A0(struct fn_1_702A0_lbl_801A63C0 *unused) {
    struct fn_1_702A0_lbl_801A63C0 *p = &lbl_801A63C0;
    p->unk_0 = p->unk_0 * 0x676A4B6B + 0x33CB;
    return (p->unk_0 >> 16) & 0x7fff;
}
#define u702(x,bias) ((f32)(u32)(x))
#define s702(x,bias) ((f32)(s32)(x))
void fn_1_702A0(void *arg0, void *arg1, u8 count_arg, u8 arg3) {
    struct fn_1_702A0_lbl_1_rodata_2D70 *p_lbl_1_rodata_2D70;
    struct fn_1_702A0_lbl_801A63C0 *p_lbl_801A63C0;
    struct Car702A0 *self = arg0;
    struct CarData702A0 *v0 = self->unk38;
    u8 arg2 = count_arg;
    struct Effect702A0 loc_8;
    f32 v21;
    f32 v20;
    f32 v19;
    f32 v18;
    f32 v17;
    f32 v16;
    f64 v15;
    f32 v14;
    f64 v13;
    f32 v12;
    f64 v11;
    f32 v10;
    f32 v8;
    f32 v6;
    f32 v4;
    f64 v40;
    f32 v22;
    f32 f0;
    p_lbl_1_rodata_2D70 = (struct fn_1_702A0_lbl_1_rodata_2D70 *)&lbl_1_rodata_2D70;
    if ((v0->flags & 1) == 0) {
        memset(&loc_8, 0, 232);
        loc_8.unk18 = self->unk18;
        loc_8.unkc = 31;
        loc_8.unk1a = 0xffff;
        switch (rand702A0(&lbl_801A63C0) % 5) {
        case 0: loc_8.unk34 = *(u32 *)(lbl_1_bss_38458->unk_8 + 456); break;
        case 1: loc_8.unk34 = *(u32 *)(lbl_1_bss_38458->unk_8 + 464); break;
        case 2: loc_8.unk34 = *(u32 *)(lbl_1_bss_38458->unk_8 + 472); break;
        case 3: loc_8.unk34 = *(u32 *)(lbl_1_bss_38458->unk_8 + 480); break;
        case 4: loc_8.unk34 = *(u32 *)(lbl_1_bss_38458->unk_8 + 488); break;
        }
        arg2 = (u8)arg2;
        v4 = 32767.0f;
        p_lbl_801A63C0 = (struct fn_1_702A0_lbl_801A63C0 *)&lbl_801A63C0;
        v6 = 0.5f;
        v8 = 2.0f;
        v10 = 60.0f;
        v11 = 0.5;
        v12 = 0.4f;
        v14 = 0.06f;
        v15 = 0.03;
        v16 = 0.2f;
        v17 = 0.8f;
        v18 = 51.0f;
        v19 = 1.0f;
        v20 = 255.0f;
        v21 = 0.0005f;
        v22 = 0.003f;
        while ((u8)arg2) {
            loc_8.unk3c = self->unk3c;
            loc_8.unk48 = self->unk48;
            loc_8.unk10 = (s32)(v10 * (v8 + (f32)(v6 * (u702(fn_1_584AC(), v40) / v4))));
            loc_8.unk48.x += (f64)(v12 * (u702(fn_1_584AC(), v40) / v4 - v11));
            loc_8.unk48.y += (f64)(v12 * (u702(fn_1_584AC(), v40) / v4 - v11));
            loc_8.unk48.z += (f64)(v12 * (u702(fn_1_584AC(), v40) / v4 - v11));
            lbl_8006D5F0(arg1, arg1, 0.7f);
            loc_8.unk48.x += ((struct Vec702A0 *)arg1)->x;
            loc_8.unk48.y += ((struct Vec702A0 *)arg1)->y;
            loc_8.unk48.z += ((struct Vec702A0 *)arg1)->z;
            loc_8.unk3c.x -= self->unk48.x;
            loc_8.unk3c.y -= self->unk48.y;
            loc_8.unk3c.z -= self->unk48.z;
            loc_8.unk5a = (s16)(v6 * (s702(rand702A0(p_lbl_801A63C0), v13) * (s702(rand702A0(p_lbl_801A63C0), v13) / v4)));
            loc_8.unk5c = (s16)(v6 * (s702(rand702A0(p_lbl_801A63C0), v13) * (s702(rand702A0(p_lbl_801A63C0), v13) / v4)));
            loc_8.unk5e = (s16)(v6 * (s702(rand702A0(p_lbl_801A63C0), v13) * (s702(rand702A0(p_lbl_801A63C0), v13) / v4)));
            f0 = v14 * (s702(rand702A0(p_lbl_801A63C0), v13) / v4);
            loc_8.unk28 = f0 < v15 ? v15 : v14 * (s702(rand702A0(p_lbl_801A63C0), v13) / v4) > v14 ? v14 : v14 * (s702(rand702A0(p_lbl_801A63C0), v13) / v4);
            f0 = v17 + (f32)(v16 * (u702(fn_1_584AC(), v40) / v4));
            loc_8.unk1c = (f32)(v6 * (v19 + f0)) * v18 / v20;
            loc_8.unk20 = v18 * f0 / v20;
            loc_8.unk24 = v20 * f0 / v20;
            loc_8.unk88 = v21 * (u702(fn_1_584AC(), v40) / v4);
            loc_8.unk8c = v22;
            if (v0->unk475 != -1 && (u8)arg3) fn_1_59078(&loc_8);
            else fn_1_58F50(&loc_8);
            arg2--;
        }
    }
}
/* fzgx:end fn_1_702A0 */

/* fzgx:begin fn_1_714A8 */
struct Fn1_714A8Work {
    u8 pad_00[0xc];
    s16 field_0c;
    u8 pad_0e[0x2];
    u32 field_10;
    u8 pad_14[0x6];
    u16 field_1a;
    f32 field_1c;
    f32 field_20;
    f32 field_24;
    f32 field_28;
    f32 field_2c;
    u8 pad_30[0x4];
    u32 field_34;
    u8 pad_38[0x4];
    f32 field_3c;
    f32 field_40;
    f32 field_44;
    Fn1_714A8Vec field_48;
    u8 pad_54[0x4];
    u16 field_58;
    u8 pad_5a[0x8e];
};

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -1.0f;
    s = 25.0f;
    s = 15.0f;
    s = 8.0f;
    s = 150.0f;
    s = 10.0f;
    s = 0.5f;
    s = 0.125f;
    s = 32767.0f;
    s = 30.0f;
    s = 20.0f;
    s = 1200.0f;
    s = 0.15000000596046448f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 255.0f;
    s = 102.0f;
    d = 0.8;
    s = 1.600000023841858f;
    s = 3.0f;
    s = 0.009999999776482582f;
    s = 0.6000000238418579f;
    d = 0.3;
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 0.10000000149011612f;
    s = 1.5f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 0.800000011920929f;
    s = 1.0f;
    s = 85.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 3.5f;
    s = 23.0f;
    s = 60.0f;
    s = 4.0f;
}
static const u32 fzgx_pool_table6[1] = {0x34000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.30000001192092896f;
    s = 128.0f;
    s = 224.0f;
    s = 500.0f;
    s = 0.9300000071525574f;
    s = 5.0f;
    s = 2.0f;
    s = 0.05000000074505806f;
    s = 0.07999999821186066f;
    s = 0.8999999761581421f;
    d = 0.30000001192092896;
    d = 0.2;
    d = -0.3;
    d = -1.0;
    d = 0.0;
    d = 30.0;
    d = 3.0;
    s = 0.0010000000474974513f;
    s = 0.0020000000949949026f;
    s = 1.899999976158142f;
    s = 10000.0f;
    s = 3000.0f;
    s = 182.04444885253906f;
    s = 0.5647059082984924f;
    s = 0.6901960968971252f;
    s = 3.605555534362793f;
}
static const u32 fzgx_pool_table10[1] = {0x20000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 5.0;
    s = 1.7774999141693115f;
    s = -5.004882768844254e-05f;
    s = 16384.0f;
}
static const u32 fzgx_pool_table12[3] = {0x00000000, 0x3DCCCCCD, 0x3FC00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 1000.0f;
    d = 0.05;
    d = 12.0;
    d = -0.16;
    d = 119.0;
    d = 2.5;
    d = 1.0;
    s = 1250.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    s = 300.0f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.20000000298023224;
    s = 2500.0f;
    s = 5000.0f;
    d = 0.1;
    d = 50.0;
    d = 0.0003;
    d = 0.02;
    s = 1.2000000476837158f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6;
    s = 44.0f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.3;
    s = 0.0005000000237487257f;
}
static const u32 fzgx_pool_table22[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.003;
    s = 20000.0f;
}
static const u32 fzgx_pool_table24[3] = {0x00000000, 0x3F800000, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 34.0f;
}
static const u32 fzgx_pool_table26[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 10.0;
}
static const u32 fzgx_pool_table28[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -2.0f;
    s = 768.0f;
}
static const u32 fzgx_pool_table30[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 16.0f;
    s = 4096.0f;
    s = 6.0f;
    s = 1820.4444580078125f;
    s = 119.0f;
    s = 51.0f;
}
static const u32 fzgx_pool_table32[3] = {0x00000000, 0x3DCCCCCD, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const u32 *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5f;
    s = 400.0f;
    s = 2000.0f;
    s = 176.0f;
}
static const u32 fzgx_pool_table34[6] = {0x00000000, 0x3DCCCCCD, 0x40000000, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const u32 *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime35(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.7999999523162842f;
}
static const u32 fzgx_pool_table36[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep36(void) { const u32 *volatile cp; cp = fzgx_pool_table36; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime37(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.3333333432674408;
    d = 0.800000011920929;
}
static const u32 fzgx_pool_table38[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep38(void) { const u32 *volatile cp; cp = fzgx_pool_table38; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime39(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.5f;
    s = 1.2999999523162842f;
    s = -1.2000000476837158f;
    s = 1500.0f;
}
static const u32 fzgx_pool_table40[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep40(void) { const u32 *volatile cp; cp = fzgx_pool_table40; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime41(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4000000059604645;
}
static const u32 fzgx_pool_table42[4] = {0x00000000, 0x3DCCCCCD, 0x3FC00000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep42(void) { const u32 *volatile cp; cp = fzgx_pool_table42; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime43(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 40.0;
    s = -2.5f;
    s = 1280.0f;
}
#pragma section code_type ".text"

// Spawn a jittered car effect: random position offset, velocity pushed along the
// supplied axis, randomised size and colour.
void fn_1_714A8(struct Fn1_714A8Car *car, f32 *axis, u32 arg2, f32 size) {
    u8 *state;
    struct Fn1_714A8Work work;
    f32 ratio;
    f32 scale;
    f32 push;

    state = car->field_38;
    memset(&work, 0, sizeof(work));
    work.field_1a = 0xffff;
    work.field_0c = 0x16;
    work.field_34 = *(u32 *)(lbl_1_bss_38458->unk_8 + 0x168);

    work.field_3c = car->field_3c + (f64)(2.0 * (((f32)(u16)fn_1_584AC() / 32767.0f) - 0.5));
    work.field_40 = car->field_40 + (f64)(2.0 * (((f32)(u16)fn_1_584AC() / 32767.0f) - 0.5));
    work.field_44 = car->field_44 + (f64)(2.0 * (((f32)(u16)fn_1_584AC() / 32767.0f) - 0.5));

    work.field_48 = car->field_48;
    work.field_48.x += (f32)(0.2f * axis[0]);
    work.field_48.x += (f32)(0.2f * axis[0]);
    work.field_48.x += (f32)(0.2f * axis[0]);
    work.field_3c -= work.field_48.x;
    work.field_40 -= work.field_48.y;
    work.field_44 -= work.field_48.z;

    ratio = (f32)(u16)fn_1_584AC() / 32767.0f;
    scale = 0.2f * ratio;
    scale = 0.8f + scale;
    work.field_2c = size * scale;
    work.field_28 = 0.5f * scale;

    ratio = (f32)(u16)fn_1_584AC() / 32767.0f;
    scale = 0.2f * ratio;
    scale = 0.8f + scale;
    work.field_1c = (255.0f * (0.5f * (1.0f + scale))) / 255.0f;
    work.field_20 = (136.0f * scale) / 255.0f;
    work.field_24 = 0.0f;

    work.field_58 = (u32)fn_1_584AC();
    work.field_10 = arg2;
    if ((s8)state[0x475] != -1) {
        fn_1_59078(&work);
    } else {
        fn_1_58F50(&work);
    }
}
/* fzgx:end fn_1_714A8 */

/* fzgx:begin fn_1_71CA0 */
void fn_1_71CA0(void *arg0, void *arg1, u16 arg2) {
    if (arg2 == 0xb4) {
        ((struct {
            u8 pad[0x58];
            s16 field_58;
        } *)arg0)->field_58 = fn_1_72318();
    }
    if (arg2 == 0xaa) {
        fn_1_71D0C(arg0, arg1);
    }
}
/* fzgx:end fn_1_71CA0 */

/* fzgx:begin fn_1_72318 */
struct EffectWorkData {
    u8 pad_00[0xc];
    s16 field_0c;
    u8 pad_0e[0xa];
    s16 field_18;
    u16 field_1a;
    u8 pad_1c[0x1c];
    u32 field_38;
    u32 field_3c;
    u32 field_40;
    u32 field_44;
    u8 pad_48[0x14];
    s16 field_5c;
    u8 pad_5e[0x8a];
};

#pragma opt_propagation off
s16 fn_1_72318(arg0)
struct fn_1_72318_EffectCar *arg0;
{
    f32 vec[3];
    struct EffectWorkData data;
    u32 lab_t0;
    f32 v0, v1, v2;

    lab_t0 = arg0->field_18;

    fn_1_867CC(lab_t0, vec);
    memset(&data, 0, sizeof(data));

    data.field_18 = arg0->field_18;
    data.field_0c = 0x25;
    data.field_38 = arg0->field_38;
    data.field_1a = 0xffff;
    lbl_8006DC6C(&arg0->field_b8, data.field_38);

    v2 = vec[0];
    v1 = vec[1];
    v0 = vec[2];

    // These are effect-engine scratch registers used to pass the generated vector.
    // fzgx-allow: A2 hardware scratch register addresses are encoded by the target.
    *(volatile f32 *)(LC_BASE + 0xC) = v2;
    // fzgx-allow: A2 hardware scratch register addresses are encoded by the target.
    *(volatile f32 *)(LC_BASE + 0x1C) = v1;
    // fzgx-allow: A2 hardware scratch register addresses are encoded by the target.
    *(volatile f32 *)(LC_BASE + 0x2C) = v0;

    data.field_3c = lbl_1_rodata_314C[0];
    data.field_40 = lbl_1_rodata_314C[1];
    data.field_44 = lbl_1_rodata_314C[2];
    lbl_8006E1B0(&data.field_3c, &data.field_3c);

    data.field_5c = 0x100;
    return fn_1_59078(&data);
}
#pragma opt_propagation reset
/* fzgx:end fn_1_72318 */
