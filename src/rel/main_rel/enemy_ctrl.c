#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/enemy_ctrl.h"
#include "font.h"
#include "game/main_rel/enemy_ctrl_types.h"

extern s32 fn_1_5910();
extern f32 lbl_1_rodata_26F8[22];
extern void fn_1_51564(s16, s16, s16, s16, s16, s16);
extern u32 fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern const f32 lbl_1_rodata_5C3C;
extern const f32 lbl_1_rodata_5CFC;
extern const f32 lbl_1_rodata_5E0C;
extern u32 fn_1_8627C(s32 index);
extern void *fn_1_4DF60(void);
extern const f32 lbl_1_rodata_5C40;
extern const f32 lbl_1_rodata_5F18;
extern u32 fn_1_58C4(void);
extern u32 lbl_1_rodata_5F14;
extern f32 fn_1_519FC(f32 value);
extern f32 fn_1_51AC0(f32 value);
extern s16 fn_1_3F0C8(void);
extern u32 fn_1_485A8(s32 index);
extern void fn_1_C771C(void);
extern void fn_1_C72D4(void);
extern void fn_1_C742C(void);
extern s16 camera_get_mode(void);
extern void fn_1_52070(u32 value);
extern void fn_1_CA8FC();
extern void fn_1_52088(void);
extern void fn_1_CA2A4(int self);
extern void fn_1_CD51C(void *object);
extern void fn_1_CDC8C(void);
extern void fn_1_CEB38(void);
extern void fn_1_C8DC0();
extern void fn_1_CADC4(int arg0);
extern u32 fn_1_3F114(void);
extern void fn_1_CC280();
extern u32 fn_1_CFA0C();
extern int fn_1_CBC24(int, int, u8, u8, u16);
extern void fn_1_CB424(int, int, int);
extern void fn_1_CB028(int, int);
extern void fn_1_CAB38(int, int, int);
extern void fn_1_CA690(int self, int arg1, int arg2);
extern void fn_1_CD7BC(int arg0);
extern u8 fn_1_86810(int index);
extern u32 fn_1_3F7E0(void);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16 index);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_49728(u8 value);
extern void fn_1_51E60(void *);
extern const f32 lbl_1_rodata_5D18;
extern const f32 lbl_1_rodata_5DBC;
extern const f32 lbl_1_rodata_5DC8;
extern const f64 lbl_1_rodata_5C00;
extern const f64 lbl_1_rodata_5DC0;
extern u32 lbl_1_rodata_5D94[10];
extern s32 fn_1_3F1D4(void);
extern f64 fn_80088598(f64, f64);
extern const f32 lbl_1_rodata_5CD4;
extern f32 lbl_1_rodata_5D1C;
extern const f32 lbl_1_rodata_5D90;
extern f32 lbl_1_rodata_5DDC;
extern f32 lbl_1_rodata_5DE0;
extern f32 lbl_1_rodata_5DE4;
extern f32 fn_1_8652C(int index);
extern void fn_1_4966C(f32 value1, f32 value2);
extern f32 lbl_1_rodata_5DE8;
extern f32 lbl_1_rodata_5DEC;
extern void fn_1_4955C(f32 value1, f32 value2);
extern u32 lbl_1_rodata_5EE8[10];
extern const f64 lbl_1_rodata_5CE8;
extern const f32 lbl_1_rodata_5CF8;
extern const f32 lbl_1_rodata_5C48;
extern const f32 lbl_1_rodata_5F10;
extern u16 fn_1_48690(u32 unused);
extern u16 fn_1_486C4(u32 value);
extern u16 fn_1_8664C(int index);
extern u32 fn_1_864E8(int index);
extern f32 lbl_8006D0B4(f32);
extern void fn_1_3EF14(void *arg1);
extern void fn_1_49514(u32 *value);
extern void fn_1_495C8(u8 value);
extern void fn_1_495A0(f32 value);
extern u32 lbl_1_rodata_5FF0;
extern u32 lbl_1_rodata_5FF4;
extern const f32 lbl_1_rodata_5CB0;
extern const f32 lbl_1_rodata_5D68;
extern const f32 lbl_1_rodata_5F7C;
extern const f32 lbl_1_rodata_5FF8;
extern const f32 lbl_1_rodata_5FFC;
extern const f32 lbl_1_rodata_6000;
extern const f32 lbl_1_rodata_6004;
extern const f32 lbl_1_rodata_6008;
extern const f32 lbl_1_rodata_600C;
extern f32 lbl_1_rodata_6010;
extern void fn_1_520A0(void);
extern void fn_1_520CC(void);
extern const f32 lbl_1_rodata_5DCC;
extern const f32 lbl_1_rodata_6050;
extern u32 lbl_801A66B4;
extern void fn_1_4954C(f32 value);
extern u32 lbl_1_rodata_6058;
extern const f32 lbl_1_rodata_5D3C;
extern const f32 lbl_1_rodata_605C;
extern const f32 lbl_1_rodata_6060;
extern const f32 lbl_1_rodata_6064;
extern const f32 lbl_1_rodata_6068;
extern s32 fn_1_156218(u32, void *, void *, void *);
extern void fn_1_495B0(u32 value);
extern void fn_1_495FC(void);
extern f32 lbl_1_rodata_6078;
extern void fn_80034200(u32 arg0);
extern u16 fn_1_A5DB0(void);
extern u32 fn_80008E84(u32 arg0);
extern u32 lbl_1_bss_7AC48[5];
extern void *lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_1_C489C(void);
extern u32 lbl_1_bss_7AC54[4];
extern u8 lbl_1_bss_7AC90[12];
extern u32 lbl_1_rodata_5D40[7];
extern const f32 lbl_1_rodata_5D5C;
extern const f32 lbl_1_rodata_5D60;
extern const f32 lbl_1_rodata_5D64;
extern const f32 lbl_1_rodata_5D6C;
extern const f32 lbl_1_rodata_5D88;
extern const f32 lbl_1_rodata_5D8C;
extern int sprintf(char *s, const char *format, ...);
extern s16 fn_1_12C7B8(s16 arg);
extern s32 fn_1_465D0(char *, s32);
extern s8 fn_1_86690(s8 index);
extern u32 fn_1_12C930(u32);
extern u8 fn_1_86624(void);
extern void *fn_1_868C0(s8 index);
extern void fn_80006E10(u32 arg0);

/* fzgx:begin fn_1_C47B4 */
void fn_1_C47B4(void) {
    u32 *p = lbl_1_bss_7AC48;

    if (p[0] != 0) {
        fn_1_46B4( (u32)(void *)(lbl_801A6410), p[0], (const char *)(void *)(lbl_1_data_3D234), 0x4af);
    }
    fn_1_46B4( (u32)(void *)(lbl_801A6410), p[4], (const char *)(void *)(lbl_1_data_3D234), 0x4b0);
    fn_1_46B4( (u32)(void *)(lbl_801A6410), p[3], (const char *)(void *)(lbl_1_data_3D234), 0x4b1);
    fn_1_46B4( (u32)(void *)(lbl_801A6410), p[2], (const char *)(void *)(lbl_1_data_3D234), 0x4b2);
    p[0] = 0;
    p[4] = 0;
    p[3] = 0;
    p[2] = 0;
}
/* fzgx:end fn_1_C47B4 */

/* fzgx:begin fn_1_C487C */
void fn_1_C487C(void) {
    fn_1_C489C();
}
/* fzgx:end fn_1_C487C */

/* fzgx:begin fn_1_C489C pool noprologue */
#include "types.h"

struct fn_1_C489C_p_lbl_1_rodata_5168_40_E12 {
    u8 unk_0;
    u8 pad_1[2];
    u8 unk_3;
    u8 pad_4[4];
    u32 unk_8;
};
struct fn_1_C489C_lbl_1_rodata_5168 {
    u8 pad_0[0x40];
    struct fn_1_C489C_p_lbl_1_rodata_5168_40_E12 unk_40[41];
};
extern f32 lbl_1_bss_7AC64[9];
#pragma pool_data on
const u8 lbl_1_rodata_5168[64] = {
        0x62, 0x55, 0x2d, 0x46, 0x64, 0x64, 0x0a, 0x00, 0x64, 0x5a, 0x32, 0x50, 0x6e, 0x6e, 0x14, 0x05,
        0x66, 0x5e, 0x3c, 0x5a, 0x7d, 0x7d, 0x23, 0x14, 0x67, 0x60, 0x46, 0x64, 0x87, 0x87, 0x37, 0x1e,
        0x64, 0x64, 0x64, 0x64, 0x64, 0x64, 0x64, 0x64, 0x66, 0x5f, 0x32, 0x50, 0x82, 0x82, 0x1e, 0x0a,
        0x69, 0x64, 0x41, 0x5a, 0x8c, 0x8c, 0x28, 0x14, 0x6c, 0x66, 0x4b, 0x64, 0x96, 0x96, 0x32, 0x28,
};
static const struct fn_1_C489C_p_lbl_1_rodata_5168_40_E12 vehicle_parameters[41] = {
        { 2, {75, 70}, 75, {0, 25, 100, 0}, 0x80000000 },
        { 1, {80, 90}, 75, {0, 30, 100, 0}, 0x80000000 },
        { 2, {70, 100}, 80, {0, 30, 100, 0}, 0x80000000 },
        { 3, {80, 95}, 85, {20, 25, 100, 0}, 0x80000000 },
        { 0, {85, 90}, 90, {80, 25, 100, 0}, 0x20000000 },
        { 1, {100, 85}, 95, {80, 10, 100, 0}, 0x80000000 },
        { 0, {100, 100}, 100, {0, 25, 100, 0}, 0x40000000 },
        { 3, {70, 90}, 95, {0, 30, 100, 0}, 0x80000000 },
        { 2, {90, 90}, 95, {0, 20, 100, 0}, 0x20000000 },
        { 3, {75, 85}, 80, {0, 30, 100, 0}, 0x80000000 },
        { 1, {80, 80}, 70, {0, 30, 100, 0}, 0x80000000 },
        { 3, {90, 95}, 75, {0, 30, 100, 0}, 0x80000000 },
        { 1, {70, 100}, 80, {0, 25, 100, 0}, 0x80000000 },
        { 2, {80, 95}, 85, {0, 30, 100, 0}, 0x80000000 },
        { 1, {75, 90}, 90, {20, 35, 100, 0}, 0x80000000 },
        { 0, {100, 85}, 95, {0, 30, 100, 0}, 0x80000000 },
        { 2, {90, 100}, 90, {0, 30, 100, 0}, 0x80000000 },
        { 3, {75, 80}, 95, {0, 30, 100, 0}, 0x10000000 },
        { 0, {80, 80}, 90, {0, 25, 100, 0}, 0x80000000 },
        { 2, {75, 85}, 80, {0, 30, 100, 0}, 0x80000000 },
        { 0, {90, 95}, 75, {0, 30, 100, 0}, 0x80000000 },
        { 3, {100, 100}, 70, {0, 20, 100, 0}, 0x80000000 },
        { 2, {70, 80}, 80, {0, 30, 100, 0}, 0x80000000 },
        { 0, {80, 95}, 85, {50, 30, 100, 0}, 0x80000000 },
        { 1, {75, 90}, 90, {80, 30, 100, 0}, 0x80000000 },
        { 1, {90, 85}, 95, {0, 30, 100, 0}, 0x80000000 },
        { 2, {80, 80}, 90, {0, 30, 100, 0}, 0x80000000 },
        { 2, {70, 80}, 95, {0, 30, 100, 0}, 0x80000000 },
        { 3, {80, 80}, 90, {0, 30, 100, 0}, 0x80000000 },
        { 0, {80, 70}, 95, {80, 15, 100, 0}, 0x40000000 },
        { 0, {100, 100}, 80, {80, 15, 100, 0}, 0x40000000 },
        { 0, {100, 100}, 90, {80, 20, 100, 0}, 0x80000000 },
        { 1, {70, 100}, 80, {0, 30, 100, 0}, 0x80000000 },
        { 0, {80, 85}, 85, {0, 30, 100, 0}, 0x80000000 },
        { 3, {75, 90}, 90, {0, 30, 100, 0}, 0x80000000 },
        { 0, {100, 95}, 95, {0, 30, 100, 0}, 0x80000000 },
        { 1, {80, 80}, 90, {0, 30, 100, 0}, 0x80000000 },
        { 1, {70, 90}, 95, {0, 30, 100, 0}, 0x80000000 },
        { 3, {80, 80}, 90, {0, 30, 100, 0}, 0x80000000 },
        { 0, {75, 85}, 80, {0, 30, 100, 0}, 0x80000000 },
        { 2, {95, 100}, 95, {0, 30, 100, 0}, 0x80000000 },
};
const u32 lbl_1_rodata_5394[14] = {
    0x44E10000, 0x44ED8000, 0x452F0000, 0x454BC000, 0x45674000, 0x456D8000, 0x45834000, 0x4585C000,
    0x4592E000, 0x45A8C000, 0x45BB8000, 0x45F96000, 0xBF800000, 0xBF800000,
};
const u32 lbl_1_rodata_53CC[16] = {
    0x44110000, 0x44480000, 0x45098000, 0x45354000, 0x457A0000, 0x458CA000, 0x45B54000, 0x45D16000,
    0x45FA0000, 0x4607F000, 0x464E4000, 0x4668D000, 0x466D8000, 0x46716800, 0xBF800000, 0xBF800000,
};
const u32 lbl_1_rodata_540C[6] = {
    0x45B22000, 0x45CB2000, 0x4636D000, 0x46403000, 0xBF800000, 0xBF800000,
};
const u32 lbl_1_rodata_5424[6] = {
    0x459DD000, 0x45A0F000, 0x45B54000, 0x45B86000, 0xBF800000, 0xBF800000,
};
const u32 lbl_1_rodata_543C[14] = {
    0x3F800000, 0x43C80000, 0x45674000, 0x45992000, 0x45D16000, 0x45F0A000, 0x46002000, 0x4607F000,
    0x460CA000, 0x46115000, 0x467D2000, 0x468A4800, 0xBF800000, 0xBF800000,
};
const u32 lbl_1_rodata_5474[8] = {
    0x44ED8000, 0x45322000, 0x4625A000, 0x46354000, 0x4644E000, 0x46610000, 0xBF800000, 0xBF800000,
};
const u32 lbl_1_rodata_5494[14] = {
    0x3F800000, 0x44278000, 0x45C1C000, 0x45CB2000, 0x45DAC000, 0x45E42000, 0x45F3C000, 0x45FD2000,
    0x46435000, 0x465DE000, 0x46610000, 0x466E4800, 0xBF800000, 0xBF800000,
};
const u32 lbl_1_rodata_54CC[10] = {
    0x44BB8000, 0x44ED8000, 0x452F0000, 0x454E4000, 0x45A28000, 0x45AD7000, 0x45D16000, 0x45D48000,
    0xBF800000, 0xBF800000,
};
const u32 lbl_1_rodata_54F4[6] = {
    0x42480000, 0x43FA0000, 0x46787000, 0x46866000, 0xBF800000, 0xBF800000,
};
const u32 lbl_1_rodata_550C[4] = {
    0x45610000, 0x4573C000, 0xBF800000, 0xBF800000,
};
const u32 lbl_1_rodata_551C[4] = {
    0x464E9000, 0x4654F800, 0xBF800000, 0xBF800000,
};
const u32 lbl_1_rodata_552C[16] = {
    0x43DC0000, 0x444A8000, 0x44D70000, 0x4507A000, 0x45412000, 0x45D39000, 0x460B1000, 0x4628C000,
    0x4639C800, 0x4642D800, 0x46816000, 0x46834000, 0x46898000, 0x468FC000, 0xBF800000, 0xBF800000,
};
const u32 lbl_1_rodata_556C[14] = {
    0x432F0000, 0x43D70000, 0x45A28000, 0x45A8C000, 0x461DD000, 0x4620F000, 0x46487800, 0x466A6000,
    0x46802000, 0x4681B000, 0x469E9800, 0x46A02800, 0xBF800000, 0xBF800000,
};
const u32 lbl_1_rodata_55A4[32] = {
    0x44048000, 0x444D4000, 0x450FC000, 0x451C4000, 0x454DA000, 0x455AC000, 0x45A2D000, 0x45AA5000,
    0x45A2D000, 0x45AD7000, 0x45B86000, 0x45BF9000, 0x45CF3000, 0x45D66000, 0x45F0F000, 0x45F5F000,
    0x45FDC000, 0x46034000, 0x46075000, 0x460A4800, 0x4616A000, 0x46199800, 0x46200000, 0x4622F800,
    0x46296000, 0x462C5800, 0x4644E000, 0x465AC000, 0x466D8000, 0x46775800, 0xBF800000, 0xBF800000,
};
const u32 lbl_1_rodata_5624[4] = {
    0x44BB8000, 0x44D48000, 0xBF800000, 0xBF800000,
};
const u32 lbl_1_rodata_5634[20] = {
    0x43A00000, 0x44F78000, 0x45098000, 0x45462000, 0x45778000, 0x45816000, 0x458DE000, 0x45AE6000,
    0x45D2A000, 0x45D7A000, 0x45E6F000, 0x4605E800, 0x46315800, 0x46412000, 0x4661C800, 0x466EC000,
    0x468C3C00, 0x468DA400, 0xBF800000, 0xBF800000,
};
const u32 lbl_1_rodata_5684[22] = {
    0x45802000, 0x45857000, 0x459F6000, 0x45A28000, 0x45B54000, 0x45BB8000, 0x45D61000, 0x45D93000,
    0x4601B000, 0x4604A800, 0x460B1000, 0x460CA000, 0x46115000, 0x4612E000, 0x46234800, 0x46255000,
    0x462BB800, 0x462DC000, 0x46383800, 0x4639C800, 0xBF800000, 0xBF800000,
};
const u32 lbl_1_rodata_56DC[12] = {
    0x44688000, 0x44960000, 0x45610000, 0x45CE4000, 0x46002000, 0x46115000, 0x4636D000, 0x463B8000,
    0x4694D400, 0x469D0800, 0xBF800000, 0xBF800000,
};
const u32 lbl_1_rodata_570C[6] = {
    0x43480000, 0x43FA0000, 0x45DAC000, 0x45E10000, 0xBF800000, 0xBF800000,
};
const u32 lbl_1_rodata_5724[12] = {
    0x3C23D70A, 0x42480000, 0x45EA6000, 0x45FA0000, 0x460B1000, 0x46160000, 0x46593000, 0x465C5000,
    0x46642000, 0x466A6000, 0xBF800000, 0xBF800000,
};
const u32 lbl_1_rodata_5754[18] = {
    0x44960000, 0x44E74000, 0x455AC000, 0x457A0000, 0x45C80000, 0x45DE8000, 0x45F0A000, 0x45FD2000,
    0x4612E000, 0x46250000, 0x463D1000, 0x46435000, 0x46499000, 0x46548000, 0x466A6000, 0x466F1000,
    0xBF800000, 0xBF800000,
};
const u32 lbl_1_rodata_579C[18] = {
    0x45898000, 0x4592E000, 0x45E42000, 0x45F0A000, 0x46034000, 0x4604D000, 0x46034000, 0x4604D000,
    0x463D1000, 0x4644E000, 0x46629000, 0x46723000, 0x46898000, 0x468D6800, 0x46A28000, 0x46A4D800,
    0xBF800000, 0xBF800000,
};
/* Volatile primer stores establish the shared retail literal-pool order. */
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer(volatile f64 *d, volatile f32 *f, u32 u, s32 s) { /* Volatile stores preserve the retail literal-pool order. */
    *d = 0.0;
    *f = 32767.0f;
    *d = 0.01;
    *d = 4503599627370496.0;
    *d = 0.00390625;
    *d = -1.0;
    *d = 1.0;
    *d = 0.5;
    *d = 4503601774854144.0;
    *d = 1.2;
    *d = 1.1;
    *d = 1.05;
    *d = 1.025;
    *d = 10.0;
    *d = 5.0;
    *d = 0.2;
    *d = 100.0;
    *d = 20.0;
    *d = 1.6;
    *d = 21.0;
    *d = 15.0;
}
#pragma section code_type ".text"

extern u32 fn_800793D4(u8 *, u32, u32);
static inline f64 clamp_value(f32 x) {
    if (x < 0.0) return 0.0;
    if (x > 20.0) return 20.0;
    return x;
}

void fn_1_C489C(void *arg0) {
    u32 v0;
    u32 v1;
    s16 v2;
    f64 v5;
    f32 v6;
    f64 v7;
    struct { void *value; } table;
    void *v10;
    void *v11;
    v0 = *(u32 *)((u8 *)arg0 + 1156);
    v1 = *(u32 *)((u8 *)v0 + 64);
    fn_800793D4((u8 *)v0, 0, 136);
    *(u32 *)((u8 *)v0 + 64) = v1;
    v2 = *(s16 *)((u8 *)arg0 + 6);
    if (v2 >= 41) {
        *(u8 *)((u8 *)v0 + 56) = v2 % 4;
    } else {
        *(u8 *)((u8 *)v0 + 56) = v2;
    }
    if (*(u8 *)((u8 *)arg0 + 1294) == 0) {
        *(u32 *)((u8 *)v0 + 0) |= 0x20000000;
    } else {
        *(u8 *)((u8 *)arg0 + 1294) = 0;
    }
    *(u8 *)((u8 *)v0 + 40) = 1;
    *(u8 *)((u8 *)v0 + 42) = 99;
    *(u8 *)((u8 *)v0 + 55) = 255;
    v5 = 0.0;
    *(f32 *)((u8 *)v0 + 36) = 0.2 * (100.0 - (f32)(lbl_1_bss_7AC64[4] * (f32)(u32)vehicle_parameters[*(u8 *)((u8 *)v0 + 56)].unk_3));
    v6 = *(f32 *)((u8 *)v0 + 36);
    v5 = clamp_value(v6);
    v7 = 1.0;
    *(f32 *)((u8 *)v0 + 36) = (f32)v5;
    if (*(f32 *)((u8 *)arg0 + 44) > v7)
        *(u32 *)((u8 *)v0 + 0) |= 0x1000000;
    if (*(f32 *)((u8 *)arg0 + 44) > 1.6)
        *(u32 *)((u8 *)v0 + 0) |= 0x800000;
    if (*(f32 *)((u8 *)arg0 + 28) < 21.0)
        *(u32 *)((u8 *)v0 + 0) |= 0x400000;
    if (*(f32 *)((u8 *)arg0 + 560) > 15.0)
        *(u32 *)((u8 *)v0 + 0) |= 0x200000;
    *(u32 *)((u8 *)v0 + 0) = (*(u32 *)((u8 *)v0 + 0) & ~0x8000) | ((vehicle_parameters[*(u8 *)((u8 *)v0 + 56)].unk_8 >> 14) & 0x8000);
    *(u32 *)((u8 *)v0 + 0) = (*(u32 *)((u8 *)v0 + 0) & ~0x4000) | ((vehicle_parameters[*(u8 *)((u8 *)v0 + 56)].unk_8 >> 14) & 0x4000);
    *(u8 *)((u8 *)v0 + 43) = 255;
    *(u8 *)((u8 *)v0 + 54) = 255;
    *(u8 *)((u8 *)v0 + 49) = vehicle_parameters[*(u8 *)((u8 *)v0 + 56)].unk_0;
    *(u8 *)((u8 *)v0 + 51) = 255;
    *(u8 *)((u8 *)v0 + 52) = 255;
}
/* fzgx:end fn_1_C489C */

/* fzgx:begin fn_1_C6ED4 */
typedef struct Fn1C6ED4Data {
    u32 flags;
    f32 value_4;
    f32 value_8;
    f32 value_c;
    f32 value_10;
    f32 value_14;
} Fn1C6ED4Data;

typedef struct Fn1C6ED4Enemy {
    u32 flags;
    u8 pad_4[0x1f0];
    f32 output_1f4;
    f32 output_1f8;
    f32 output_1fc;
    f32 output_200;
    f32 output_204;
    u8 pad_208[0x27c];
    Fn1C6ED4Data *data;
} Fn1C6ED4Enemy;

void fn_1_C6ED4(Fn1C6ED4Enemy *self) {
    Fn1C6ED4Data *data = self->data;

    self->output_1fc = data->value_4;
    self->output_1f4 = data->value_8;
    self->output_200 = data->value_c;
    self->output_204 = data->value_10;
    self->output_1f8 = data->value_14;

    if (data->flags >> 31) {
        self->flags |= 0x40;
        data->flags &= ~((u32)1 << 31);
    }
    if ((data->flags >> 30) & 1) {
        self->flags |= 0x1000;
        data->flags &= ~((u32)1 << 30);
    }
    if ((data->flags >> 20) & 1) {
        self->flags |= 0x8;
        data->flags &= ~((u32)1 << 20);
    }
}
/* fzgx:end fn_1_C6ED4 */

/* fzgx:begin fn_1_C6F70 */
u32 fn_1_C6F70(void) {
    return lbl_1_bss_7AC54[0];
}
/* fzgx:end fn_1_C6F70 */

/* fzgx:begin fn_1_C6F80 */
void fn_1_C6F80(u8 value) {
    lbl_1_bss_7AC90[0] = value;
}
/* fzgx:end fn_1_C6F80 */

/* fzgx:begin fn_1_C6F8C noprologue */
#include "types.h"

typedef struct {
    u8 pad_0[0x2B4];
    u32 flags[4];
    f32 unk_2C4;
    f32 unk_2C8;
    f32 unk_2CC;
    f32 unk_2D0;
    f32 unk_2D4;
    f32 unk_2D8;
    f32 unk_2DC;
} Fn1C6F8CData;

typedef struct {
    u32 words[18];
} Fn1C6F8CTable;

typedef struct {
    u32 unk_0;
    u8 pad_4[4];
    u8 unk_8;
    u8 pad_9[0x9B];
    u16 unk_A4;
} Fn1C6F8CRace;

typedef struct {
    u8 pad_0[0x94];
    u32 flags;
} Fn1C6F8CState;

extern s16 lbl_1_bss_960;
extern Fn1C6F8CData lbl_1_data_3D290;
extern Fn1C6F8CState lbl_1_bss_8B3A0;

extern s16 fn_1_3F0C8(void);
extern void fn_1_D0428(void);
extern const f32 lbl_1_rodata_5A50;
extern const f32 lbl_1_rodata_5A54;
extern const f32 lbl_1_rodata_5A58;
extern const f32 lbl_1_rodata_5A5C;
extern const f32 lbl_1_rodata_5A60;
extern const f32 lbl_1_rodata_5A64;
extern int fn_1_485A8(int);
extern u32 fn_1_58C4(void);
extern void fn_1_52070(int);
extern s32 camera_get_flags(void);
extern u8 fn_1_D2D48(void);
extern Fn1C6F8CTable lbl_1_rodata_59C0;
extern Fn1C6F8CTable lbl_1_rodata_5A08;
extern void fn_1_C8294(Fn1C6F8CTable *, u8, int);
extern void fn_1_52088(void);
extern void fn_1_CF5B0(int);

extern u8 lbl_1_data_3D290__fzgx_offset_0[];
extern u8 lbl_1_data_3D294__fzgx_offset_0[];
extern u8 lbl_1_data_3D2A0__fzgx_offset_0[];
extern u8 lbl_1_data_3D2AC__fzgx_offset_0[];
extern u8 lbl_1_data_3D2B8__fzgx_offset_0[];
extern u8 lbl_1_data_3D2C4__fzgx_offset_0[];
extern u8 lbl_1_data_3D2CC__fzgx_offset_0[];
extern u8 lbl_1_data_3D2D4__fzgx_offset_0[];
extern u8 lbl_1_data_3D2DC__fzgx_offset_0[];
extern u8 lbl_1_data_3D2E4__fzgx_offset_0[];
extern u8 lbl_1_data_3D2F0__fzgx_offset_0[];
extern u8 lbl_1_data_3D300__fzgx_offset_0[];
extern u8 lbl_1_data_3D310__fzgx_offset_0[];
extern u8 lbl_1_data_3D318__fzgx_offset_0[];
extern u8 lbl_1_data_3D320__fzgx_offset_0[];
extern u8 lbl_1_data_3D32C__fzgx_offset_0[];
extern u8 lbl_1_data_3D338__fzgx_offset_0[];
extern u8 lbl_1_data_3D348__fzgx_offset_0[];
extern u8 lbl_1_data_3D350__fzgx_offset_0[];
extern u8 lbl_1_data_3D35C__fzgx_offset_0[];
extern u8 lbl_1_data_3D368__fzgx_offset_0[];
extern u8 lbl_1_data_3D378__fzgx_offset_0[];
extern u8 lbl_1_data_3D380__fzgx_offset_0[];
extern u8 lbl_1_data_3D38C__fzgx_offset_0[];
extern u8 lbl_1_data_3D398__fzgx_offset_0[];
extern u8 lbl_1_data_3D3A8__fzgx_offset_0[];
extern u8 lbl_1_data_3D3B0__fzgx_offset_0[];
extern u8 lbl_1_data_3D3BC__fzgx_offset_0[];
extern u8 lbl_1_data_3D3C4__fzgx_offset_0[];
extern u8 lbl_1_data_3D3D0__fzgx_offset_0[];
extern u8 lbl_1_data_3D3E0__fzgx_offset_0[];
extern u8 lbl_1_data_3D3EC__fzgx_offset_0[];
extern u8 lbl_1_data_3D3F8__fzgx_offset_0[];
extern u8 lbl_1_data_3D400__fzgx_offset_0[];
extern u8 lbl_1_data_3D414__fzgx_offset_0[];
extern u8 lbl_1_data_3D424__fzgx_offset_0[];
extern u8 lbl_1_data_3D434__fzgx_offset_0[];
extern u8 lbl_1_data_3D440__fzgx_offset_0[];
extern u8 lbl_1_data_3D44C__fzgx_offset_0[];
extern u8 lbl_1_data_3D45C__fzgx_offset_0[];
extern u8 lbl_1_data_3D464__fzgx_offset_0[];
extern u8 lbl_1_data_3D470__fzgx_offset_0[];
extern u8 lbl_1_data_3D478__fzgx_offset_0[];
extern u8 lbl_1_data_3D480__fzgx_offset_0[];
extern u8 lbl_1_data_3D488__fzgx_offset_0[];
static u32 fzgx_pool_native_lbl_1_data_3D290_gap_0[173] = {0x4E4F4E00, 0x4D415354, 0x45522052, 0x45435600, 0x4D415354, 0x45522053, 0x454E4400, 0x534C4156, 0x45205345, 0x4E440000, 0x534C4156, 0x45205245, 0x43560000, 0x494E4954, 0x00000000, 0x54455354, 0x00000000, 0x54455354, 0x454E4400, 0x53455455, 0x50000000, 0x53455455, 0x505F444F, 0x4E450000, 0x53455455, 0x505F434F, 0x554E5445, 0x52000000, 0x53455455, 0x505F434E, 0x545F444F, 0x4E450000, 0x554E4C49, 0x4E4B0000, 0x434F494E, 0x00000000, 0x454E5452, 0x595F5741, 0x49540000, 0x4348414C, 0x4C454E47, 0x45520000, 0x4348414C, 0x4C454E47, 0x45525F4F, 0x4B000000, 0x454E5452, 0x59000000, 0x454E5452, 0x595F4F4B, 0x00000000, 0x53494E47, 0x4C454348, 0x45434B00, 0x53494E47, 0x4C454348, 0x45434B5F, 0x4F4B0000, 0x434F5552, 0x53450000, 0x434F5552, 0x53455F4F, 0x4B000000, 0x434F5552, 0x53455F44, 0x41544100, 0x434F5552, 0x53455F44, 0x4154415F, 0x4F4B0000, 0x4D414348, 0x494E4500, 0x4D414348, 0x494E455F, 0x4F4B0000, 0x434F4E46, 0x49470000, 0x434F4E46, 0x49475F4F, 0x4B000000, 0x434F554E, 0x54455241, 0x444A5553, 0x54000000, 0x4C494E4B, 0x57414954, 0x00000000, 0x4C494E4B, 0x57414954, 0x4F4B0000, 0x4C494E4B, 0x53454C00, 0x4C494E4B, 0x44454C49, 0x56455259, 0x53544152, 0x54000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x00000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x4F4B0000, 0x4C494E4B, 0x53454C4F, 0x4B000000, 0x434F5552, 0x53455649, 0x45570000, 0x434F5552, 0x53455649, 0x45575F4F, 0x4B000000, 0x4C494E4B, 0x52455100, 0x4C494E4B, 0x5354414E, 0x44425900, 0x4C494E4B, 0x4F4B0000, 0x4C494E4B, 0x00000000, 0x50415553, 0x45000000, 0x4552524F, 0x52000000, (u32)lbl_1_data_3D290__fzgx_offset_0, (u32)lbl_1_data_3D294__fzgx_offset_0, (u32)lbl_1_data_3D2A0__fzgx_offset_0, (u32)lbl_1_data_3D2AC__fzgx_offset_0, (u32)lbl_1_data_3D2B8__fzgx_offset_0, (u32)lbl_1_data_3D2C4__fzgx_offset_0, (u32)lbl_1_data_3D2CC__fzgx_offset_0, (u32)lbl_1_data_3D2D4__fzgx_offset_0, (u32)lbl_1_data_3D2DC__fzgx_offset_0, (u32)lbl_1_data_3D2E4__fzgx_offset_0, (u32)lbl_1_data_3D2F0__fzgx_offset_0, (u32)lbl_1_data_3D300__fzgx_offset_0, (u32)lbl_1_data_3D310__fzgx_offset_0, (u32)lbl_1_data_3D318__fzgx_offset_0, (u32)lbl_1_data_3D320__fzgx_offset_0, (u32)lbl_1_data_3D32C__fzgx_offset_0, (u32)lbl_1_data_3D338__fzgx_offset_0, (u32)lbl_1_data_3D348__fzgx_offset_0, (u32)lbl_1_data_3D350__fzgx_offset_0, (u32)lbl_1_data_3D35C__fzgx_offset_0, (u32)lbl_1_data_3D368__fzgx_offset_0, (u32)lbl_1_data_3D378__fzgx_offset_0, (u32)lbl_1_data_3D380__fzgx_offset_0, (u32)lbl_1_data_3D38C__fzgx_offset_0, (u32)lbl_1_data_3D398__fzgx_offset_0, (u32)lbl_1_data_3D3A8__fzgx_offset_0, (u32)lbl_1_data_3D3B0__fzgx_offset_0, (u32)lbl_1_data_3D3BC__fzgx_offset_0, (u32)lbl_1_data_3D3C4__fzgx_offset_0, (u32)lbl_1_data_3D3D0__fzgx_offset_0, (u32)lbl_1_data_3D3E0__fzgx_offset_0, (u32)lbl_1_data_3D3EC__fzgx_offset_0, (u32)lbl_1_data_3D3F8__fzgx_offset_0, (u32)lbl_1_data_3D400__fzgx_offset_0, (u32)lbl_1_data_3D414__fzgx_offset_0, (u32)lbl_1_data_3D424__fzgx_offset_0, (u32)lbl_1_data_3D434__fzgx_offset_0, (u32)lbl_1_data_3D440__fzgx_offset_0, (u32)lbl_1_data_3D44C__fzgx_offset_0, (u32)lbl_1_data_3D45C__fzgx_offset_0, (u32)lbl_1_data_3D464__fzgx_offset_0, (u32)lbl_1_data_3D470__fzgx_offset_0, (u32)lbl_1_data_3D478__fzgx_offset_0, (u32)lbl_1_data_3D480__fzgx_offset_0, (u32)lbl_1_data_3D488__fzgx_offset_0}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_1_data_3D290_flags[4] = {0xFF9FFFFF, 0xFF9FFFFF, 0xFF9FFFFF, 0xFF9FFFFF}; /* fzgx-allow: A1 measured pool bytes and bindings */
static f32 fzgx_pool_native_lbl_1_data_3D290_unk_2C4 = 632.0f; /* fzgx-allow: A1 measured pool bytes and bindings */
static f32 fzgx_pool_native_lbl_1_data_3D290_unk_2C8 = -68.0f; /* fzgx-allow: A1 measured pool bytes and bindings */
static f32 fzgx_pool_native_lbl_1_data_3D290_unk_2CC = 429.0f; /* fzgx-allow: A1 measured pool bytes and bindings */
static f32 fzgx_pool_native_lbl_1_data_3D290_unk_2D0 = 460.0f; /* fzgx-allow: A1 measured pool bytes and bindings */
static f32 fzgx_pool_native_lbl_1_data_3D290_unk_2D4 = 91.0f; /* fzgx-allow: A1 measured pool bytes and bindings */
static f32 fzgx_pool_native_lbl_1_data_3D290_unk_2D8 = 160.0f; /* fzgx-allow: A1 measured pool bytes and bindings */
static f32 fzgx_pool_native_lbl_1_data_3D290_unk_2DC = 160.0f; /* fzgx-allow: A1 measured pool bytes and bindings */

typedef struct lbl_1_bss_3C30_t {
    u32 unk_0;
    u8 pad_4[0x4];
    u8 unk_8;
    u8 pad_9[0x9b];
    u16 unk_A4;
    u8 pad_A6[0x1416];
} lbl_1_bss_3C30_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
lbl_1_bss_3C30_t lbl_1_bss_3C30;
u32 fzgx_obj_lbl_1_bss_50EC[5];
u32 fzgx_obj_lbl_1_bss_5100;
u32 fzgx_obj_lbl_1_bss_5104[13];
u32 fzgx_obj_lbl_1_bss_5138[65];
u32 lbl_1_bss_523C[8];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_1_bss_3C30;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_50EC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5100;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5104;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5138;
    s = *(u8 *)&lbl_1_bss_523C;
}
#pragma section code_type ".text"

#pragma opt_common_subs off
void fn_1_C6F8C(void) {
    
    struct { int value; } count;
    u32 *p;
    int i;

    if (lbl_1_bss_960 == 2 &&
        (fn_1_3F0C8() == 0x25 || fn_1_3F0C8() == 0x26)) {
        return;
    }

    if (lbl_1_bss_960 == 2 && fn_1_3F0C8() == 0x27) {
        fn_1_D0428();
    } else {
        fzgx_pool_native_lbl_1_data_3D290_unk_2C4 = lbl_1_rodata_5A50;
        fzgx_pool_native_lbl_1_data_3D290_unk_2C8 = lbl_1_rodata_5A54;
        fzgx_pool_native_lbl_1_data_3D290_unk_2CC = lbl_1_rodata_5A58;
        fzgx_pool_native_lbl_1_data_3D290_unk_2D0 = lbl_1_rodata_5A5C;
        fzgx_pool_native_lbl_1_data_3D290_unk_2D4 = lbl_1_rodata_5A60;
        fzgx_pool_native_lbl_1_data_3D290_unk_2D8 = lbl_1_rodata_5A64;
        fzgx_pool_native_lbl_1_data_3D290_unk_2DC = lbl_1_rodata_5A64;
    }

    p = fzgx_pool_native_lbl_1_data_3D290_flags;
    for (i = 0; i < 4; i++, p++) {
        if (*p & 1) {
            *p = ~*p;
        }
    }

    if (fn_1_485A8(0x94) == 0) {
        return;
    }

    if (fn_1_58C4() == 1) {
        fn_1_52070(0x60);
    }

    if ((fzgx_pool_native_lbl_1_data_3D290_flags[0] >> 31) && camera_get_flags() == 0 && lbl_1_bss_3C30.unk_8 < 2) {
        u8 id = fn_1_D2D48();
        if (!(lbl_1_bss_8B3A0.flags & 0x40000000)) {
            Fn1C6F8CTable table = lbl_1_rodata_59C0;
            fn_1_C8294(&table, id, 1);
        } else {
            Fn1C6F8CTable table = lbl_1_rodata_5A08;
            fn_1_C8294(&table, id, 1);
        }
    }

    fn_1_52088();

    if (fn_1_58C4() == 1) {
        fn_1_52070(0x140);
    }

    if (lbl_1_bss_8B3A0.flags & 0x40000000) {
        if (lbl_1_bss_3C30.unk_0 & 0x40000) {
            int secs = (lbl_1_bss_3C30.unk_A4 + 0x3b) / 60;
            int min = 99;
            if (secs < 99) {
                min = secs;
            }
            count.value = min;
        }
        fn_1_CF5B0(count.value);
    }

    fn_1_52088();
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_C6F8C */

/* fzgx:begin fn_1_C7224 */
typedef struct {
    u8 padding[0x94];
    u32 flags;
} Fn1C7224State;



void fn_1_C7224(void) {
    if ((*(s16 *)&lbl_1_bss_960) == 2 &&
        (fn_1_3F0C8() == 0x25 || fn_1_3F0C8() == 0x26)) {
        return;
    }

    if ((int)fn_1_485A8(0x94) != 0) {
        if ((*(Fn1C7224State *)&lbl_1_bss_8B3A0).flags & 0x40000000) {
            fn_1_C771C();
        } else if (fn_1_58C4() == 1) {
            if (!((*(Fn1C7224State *)&lbl_1_bss_8B3A0).flags & 0x40000000)) {
                fn_1_C72D4();
            } else {
                fn_1_C771C();
            }
        } else {
            fn_1_C742C();
        }
    }
}
/* fzgx:end fn_1_C7224 */

/* fzgx:begin fn_1_C72D4 */
void fn_1_C72D4(void) {
    int mode;
    fn_1_C72D4_EnemyCtrl *enemy;
    int offset;

    mode = camera_get_mode();
    if (mode == -1 || mode < 0) {
        return;
    }
    enemy = (fn_1_C72D4_EnemyCtrl *)fn_1_8627C(mode);
    if (enemy != 0) {
        if (fn_1_58C4() == 1)
            fn_1_52070(0x60);
        fn_1_CA8FC(mode);
        fn_1_52088();
        if (fn_1_58C4() == 1)
            fn_1_52070(0x140);
        fn_1_CA2A4(mode);
        fn_1_CD51C( (void *)(int)(mode));
        fn_1_CDC8C();
        fn_1_CEB38();
        fn_1_52088();
        if (fn_1_58C4() == 1)
            fn_1_52070(0x220);
        offset = 0;
        fn_1_C8DC0(mode);
        fn_1_CADC4(mode);
        fn_1_CC280(0x19a, 0x18, enemy->field_118 + 1,
            fn_1_3F114() & 0xff);
        if ((u8)fn_1_CFA0C(0x268, 0x43) != 0)
            offset = 0x25;
        fn_1_CBC24(0x1bc, offset + 0x43, enemy->field_1ec,
            enemy->field_1ed, enemy->field_1ee);
        fn_1_CB424(0x269, offset + 0x6e, (int)fn_1_5910());
        fn_1_CB028(0x269, offset + 0x96);
        fn_1_CAB38(mode, 0x268, offset);
        fn_1_52088();
    }
}
/* fzgx:end fn_1_C72D4 */

/* fzgx:begin fn_1_C742C */
typedef void (*fn_1_C742C_DrawFunc)(s32, s32, s32);

typedef struct fn_1_C742C_Vec {
    f32 x;
    f32 y;
    f32 z;
} fn_1_C742C_Vec;

typedef struct fn_1_C742C_Funcs { fn_1_C742C_DrawFunc f[6]; } fn_1_C742C_Funcs;
typedef struct fn_1_C742C_Offsets { fn_1_C742C_Vec v[3][4]; } fn_1_C742C_Offsets;
typedef struct fn_1_C742C_Positions { fn_1_C742C_Vec v[3][6]; } fn_1_C742C_Positions;
typedef struct fn_1_C742C_Values { s32 v[6]; } fn_1_C742C_Values;

extern const fn_1_C742C_Funcs lbl_1_rodata_5A68;
extern const fn_1_C742C_Offsets lbl_1_rodata_5A80;
extern const fn_1_C742C_Positions lbl_1_rodata_5B10;
extern const fn_1_C742C_Values lbl_1_rodata_5BE8;

extern s16 camera_get_mode(void);
extern s32 fn_1_5910(void);
extern u8 fn_1_5348(void);
extern void fn_1_CFA4C(u32, u32);
extern s32 camera_get_state(void);
extern f32 fn_1_519FC(f32);
extern void fn_1_52070(u32);
extern void fn_1_52088(void);
extern void fn_1_CD51C(void *);
extern void fn_1_C7AA0(void);
extern void fn_1_C7874(void);

void fn_1_C742C(void) {
    fn_1_C742C_Funcs funcs = lbl_1_rodata_5A68;
    fn_1_C742C_Offsets offsets = lbl_1_rodata_5A80;
    fn_1_C742C_Positions positions = lbl_1_rodata_5B10;
    fn_1_C742C_Values values = lbl_1_rodata_5BE8;
    s32 idx;
    fn_1_C742C_Vec *pos;
    s32 *val;
    fn_1_C742C_DrawFunc *fn;
    fn_1_C742C_Vec *off;
    s32 row;
    s32 i;
    f32 x;
    f32 y;
    s32 mode;

    mode = camera_get_mode();
    idx = fn_1_5910();
    if (mode == -1 || mode < 0) {
        fn_1_C742C_Vec *v = &offsets.v[2][idx];
        if (fn_1_5348() == 3) {
            fn_1_CFA4C((s32)v->x, (s32)v->y);
        }
        return;
    }

    switch ((s8)camera_get_state()) {
    case 1:
        row = 0;
        break;
    case 2:
        row = 1;
        break;
    case 6:
    case 7:
    case 8:
        row = 2;
        break;
    default:
        return;
    }

    pos = positions.v[row];
    val = values.v;
    fn = funcs.f;
    off = &offsets.v[row][idx];
    for (i = 0; i < 6; i++) {
        x = pos->x + off->x;
        y = pos->y + off->y;
        fn_1_52070((s32)fn_1_519FC((f32)*val));
        (*fn)(mode, (s32)x, (s32)y);
        fn_1_52088();
        pos++;
        val++;
        fn++;
    }
    fn_1_CD51C((void *)mode);

    switch ((s8)camera_get_state()) {
    case 1:
        fn_1_C7AA0();
        break;
    case 2:
        fn_1_C7874();
        break;
    case 6:
    case 7:
    case 8:
        fn_1_C7AA0();
        fn_1_C7874();
        break;
    }
}
/* fzgx:end fn_1_C742C */

/* fzgx:begin fn_1_C771C */
void fn_1_C771C(void) {
    int mode;
    fn_1_C771C_EnemyCtrl *ctrl;
    int value;

    mode = camera_get_mode();
    if (mode == -1 || mode < 0) {
        return;
    }
    ctrl = (fn_1_C771C_EnemyCtrl *)fn_1_8627C(mode);
    if (ctrl == 0) {
        return;
    }
    if (fn_1_58C4() == 1) {
        fn_1_52070( (int)(0x60));
    }
    fn_1_CA690(mode, 0x18, 0x19c);
    fn_1_52088();
    if (fn_1_58C4() == 1) {
        fn_1_52070( (int)(0x140));
    }
    fn_1_CD51C( (void *)(int)(mode));
    fn_1_CD7BC(mode);
    fn_1_52088();
    if (fn_1_58C4() == 1) {
        fn_1_52070( (int)(0x220));
    }
    value = 0;
    fn_1_C8DC0(mode);
    fn_1_CADC4(mode);
    fn_1_CC280(0x19a, 0x18, ctrl->field_118 + 1, fn_1_3F114() & 0xff);
    if ((fn_1_CFA0C(0x268, 0x43) & 0xff) != 0) {
        value = 0x25;
    }
    fn_1_CBC24(0x1bc, value + 0x43, ctrl->field_1ec,
               ctrl->field_1ed, ctrl->field_1ee);
    fn_1_CB424(0x269, value + 0x6e, (int)fn_1_5910());
    fn_1_CB028(0x269, value + 0x96);
    fn_1_CAB38(mode, 0x268, value);
    fn_1_52088();
}
/* fzgx:end fn_1_C771C */

/* fzgx:begin fn_1_C7874 noprologue */
#include "types.h"
#include "font.h"

typedef struct fn_1_C7874_Values {
    s32 a[12];
} fn_1_C7874_Values;

extern const fn_1_C7874_Values lbl_1_rodata_5C08;
extern const FontDrawPacket lbl_1_rodata_26F8;
extern const f32 lbl_1_rodata_5C38; /* 120.0f */
extern const f32 lbl_1_rodata_5C3C; /* 320.0f */
extern const f32 lbl_1_rodata_5C40; /* 240.0f */
extern const f32 lbl_1_rodata_5C44; /* 11.0f */
extern const f32 lbl_1_rodata_5C48; /* 10.0f */

void fn_1_C7874(void) {
    fn_1_C7874_Values vals = lbl_1_rodata_5C08;
    FontDrawPacket pkt;
    u32 i;

    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x9457;
    fn_1_51678(&pkt, pkt.image, 0, 0, 4, 8);
    pkt.scale_x *= lbl_1_rodata_5C38;
    pkt.x = lbl_1_rodata_5C3C;
    pkt.y = lbl_1_rodata_5C40;
    pkt.z = lbl_1_rodata_5C44;
    pkt.rotation_z = 0x4000;
    pkt.flags = 10;
    fn_1_4F734(&pkt);

    for (i = 0; i < 12; i++) {
        pkt = lbl_1_rodata_26F8;
        pkt.image = 0x9457;
        fn_1_51678(&pkt, pkt.image, 4, 0, 4, 8);
        pkt.x = lbl_1_rodata_5C3C;
        pkt.y = (f32)vals.a[i];
        pkt.z = lbl_1_rodata_5C48;
        pkt.rotation_z = 0x4000;
        pkt.flags = 10;
        fn_1_4F734(&pkt);
    }
}
/* fzgx:end fn_1_C7874 */

/* fzgx:begin fn_1_C7AA0 noprologue */
#include "types.h"
#include "font.h"

typedef struct fn_1_C7AA0_Values {
    s32 a[12];
} fn_1_C7AA0_Values;

extern const fn_1_C7AA0_Values lbl_1_rodata_5C4C;
extern const FontDrawPacket lbl_1_rodata_26F8;
extern const f32 lbl_1_rodata_5A64; /* 160.0f */
extern const f32 lbl_1_rodata_5C3C; /* 320.0f */
extern const f32 lbl_1_rodata_5C40; /* 240.0f */
extern const f32 lbl_1_rodata_5C7C; /* 13.0f */
extern const f32 lbl_1_rodata_5C80; /* 12.0f */

void fn_1_C7AA0(void) {
    fn_1_C7AA0_Values vals = lbl_1_rodata_5C4C;
    FontDrawPacket pkt;
    u32 i;

    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x9457;
    fn_1_51678(&pkt, pkt.image, 0, 0, 4, 8);
    pkt.scale_x *= lbl_1_rodata_5A64;
    pkt.x = lbl_1_rodata_5C3C;
    pkt.y = lbl_1_rodata_5C40;
    pkt.z = lbl_1_rodata_5C7C;
    pkt.flags = 10;
    fn_1_4F734(&pkt);

    for (i = 0; i < 12; i++) {
        pkt = lbl_1_rodata_26F8;
        pkt.image = 0x9457;
        fn_1_51678(&pkt, pkt.image, 4, 0, 4, 8);
        pkt.x = (f32)vals.a[i];
        pkt.y = lbl_1_rodata_5C40;
        pkt.z = lbl_1_rodata_5C80;
        pkt.flags = 10;
        fn_1_4F734(&pkt);
    }
}
/* fzgx:end fn_1_C7AA0 */

/* fzgx:begin fn_1_C7CBC */
extern const f32 lbl_1_rodata_5C88;
extern const f32 lbl_1_rodata_5C8C;
extern const f64 lbl_1_rodata_5C00;
extern int fn_1_4F734(FontDrawPacket *);
extern f32 lbl_1_rodata_26F8[22];
extern u32 lbl_1_rodata_5C84;

#pragma opt_common_subs off
void fn_1_C7CBC(u32 arg0, u32 arg1, u32 arg2, u32 arg3, f32 arg4, f32 arg5) {
    u32 v1;
    u32 v0;
    f32 v2;
    f64 v3;
    f32 v5;
    f32 v6;
    f32 v7;
    f32 v8;
    f32 v4;
    s32 v9;
    f64 v11;
    f32 v12;
    f32 v10;
    f64 v13;
    f32 v15;
    f32 v16;
    f32 v14;
    f64 v18;
    u32 v19;
    f32 v20;
    f32 v17;
    f64 v21;
    f32 v23;
    f32 v24;
    f32 v22;
    f64 v26;
    u32 v27;
    f32 v28;
    f32 v25;
    f64 v30;
    f32 v31;
    f32 v29;
    f64 v33;
    u32 v34;
    f32 v35;
    f32 v32;
    struct Color { u8 r, g, b, a; } loc_8;
    FontDrawPacket loc_C;
    loc_8 = *(struct Color *)&lbl_1_rodata_5C84;
    v0 = (0x10000 - 26839);
    if ((s32)arg3 != 0) {
        v0 = (0x10000 - 27592);
    }
    v1 = (0x10000 - 26838);
    if ((s32)arg3 != 0) {
        v1 = (0x10000 - 27591);
    }
    v2 = (f32)(lbl_1_rodata_5C88 * (f32)(lbl_1_rodata_5C8C * arg4));
    loc_C = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v3 = lbl_1_rodata_5C00;
    v5 = (f32)((f32)(s32)(s16)arg0 - v2);
    v6 = (f32)(s32)(s16)arg1;
    v7 = (f32)(v6 - v2);
    loc_C.image = v0;
    v8 = (f32)(s32)(s16)arg2;
    loc_C.x = v5;
    loc_C.y = v7;
    loc_C.z = v8;
    loc_C.scale_x = (f32)(loc_C.scale_x * arg4);
    loc_C.scale_y = (f32)(loc_C.scale_y * arg5);
    loc_C.flags = 15;
    fn_1_4F734(&loc_C);
    loc_C = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v9 = ((s16)arg2 + 1);
    v11 = lbl_1_rodata_5C00;
    v12 = (f32)(s32)v9;
    loc_C.image = v1;
    loc_C.x = v5;
    loc_C.y = v7;
    loc_C.z = v12;
    loc_C.scale_x = (f32)(loc_C.scale_x * arg4);
    loc_C.scale_y = (f32)(loc_C.scale_y * arg5);
    loc_C.flags = 15;
    *(struct Color *)((u8 *)&loc_C + 56) = loc_8;
    fn_1_4F734(&loc_C);
    loc_C = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v13 = lbl_1_rodata_5C00;
    v15 = (f32)((f32)(s32)(s16)arg0 + v2);
    loc_C.image = v0;
    v16 = (f32)(s32)(s16)arg2;
    loc_C.x = v15;
    loc_C.y = v7;
    loc_C.z = v16;
    loc_C.scale_x = (f32)(loc_C.scale_x * arg4);
    loc_C.scale_y = (f32)(loc_C.scale_y * arg5);
    loc_C.flags = (0x80000 + 13);
    fn_1_4F734(&loc_C);
    loc_C = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v18 = lbl_1_rodata_5C00;
    v19 = (0x80000 + 13);
    v20 = (f32)(s32)v9;
    loc_C.image = v1;
    loc_C.x = v15;
    loc_C.y = v7;
    loc_C.z = v20;
    loc_C.scale_x = (f32)(loc_C.scale_x * arg4);
    loc_C.scale_y = (f32)(loc_C.scale_y * arg5);
    loc_C.flags = v19;
    *(struct Color *)((u8 *)&loc_C + 56) = loc_8;
    fn_1_4F734(&loc_C);
    loc_C = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v21 = lbl_1_rodata_5C00;
    v23 = (f32)((f32)(s32)(s16)arg1 + v2);
    loc_C.image = v0;
    v24 = (f32)(s32)(s16)arg2;
    loc_C.x = v5;
    loc_C.y = v23;
    loc_C.z = v24;
    loc_C.scale_x = (f32)(loc_C.scale_x * arg4);
    loc_C.scale_y = (f32)(loc_C.scale_y * arg5);
    loc_C.flags = (0x100000 + 7);
    fn_1_4F734(&loc_C);
    loc_C = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v26 = lbl_1_rodata_5C00;
    v27 = (0x100000 + 7);
    v28 = (f32)(s32)v9;
    loc_C.image = v1;
    loc_C.x = v5;
    loc_C.y = v23;
    loc_C.z = v28;
    loc_C.scale_x = (f32)(loc_C.scale_x * arg4);
    loc_C.scale_y = (f32)(loc_C.scale_y * arg5);
    loc_C.flags = v27;
    *(struct Color *)((u8 *)&loc_C + 56) = loc_8;
    fn_1_4F734(&loc_C);
    loc_C = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v30 = lbl_1_rodata_5C00;
    loc_C.image = v0;
    v31 = (f32)(s32)(s16)arg2;
    loc_C.x = v15;
    loc_C.y = v23;
    loc_C.z = v31;
    loc_C.scale_x = (f32)(loc_C.scale_x * arg4);
    loc_C.scale_y = (f32)(loc_C.scale_y * arg5);
    loc_C.flags = (0x180000 + 5);
    fn_1_4F734(&loc_C);
    loc_C = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v33 = lbl_1_rodata_5C00;
    v34 = (0x180000 + 5);
    v35 = (f32)(s32)v9;
    loc_C.image = v1;
    loc_C.x = v15;
    loc_C.y = v23;
    loc_C.z = v35;
    loc_C.scale_x = (f32)(loc_C.scale_x * arg4);
    loc_C.scale_y = (f32)(loc_C.scale_y * arg5);
    loc_C.flags = v34;
    *(struct Color *)((u8 *)&loc_C + 56) = loc_8;
    fn_1_4F734(&loc_C);
}
/* fzgx:end fn_1_C7CBC */

/* fzgx:begin fn_1_CA218 */
typedef struct EnemyCtrl_CA218 {
    u32 value;
    u8 pad4[2];
    s16 state;
    u32 action;
} EnemyCtrl_CA218;

void fn_1_CA218(EnemyCtrl_CA218 *self) {
    u32 actions[7];

    actions[0] = lbl_1_rodata_5D40[0];
    actions[1] = lbl_1_rodata_5D40[1];
    actions[2] = lbl_1_rodata_5D40[2];
    actions[3] = lbl_1_rodata_5D40[3];
    actions[4] = lbl_1_rodata_5D40[4];
    actions[5] = lbl_1_rodata_5D40[5];
    actions[6] = lbl_1_rodata_5D40[6];

    if (self->state < 14) {
        self->action = actions[self->state / 2];
        self->state = self->state + 1;
    } else {
        self->value = 0;
    }
}
/* fzgx:end fn_1_CA218 */

/* fzgx:begin fn_1_CA2A4 */
typedef struct {
    u32 x[22];
} fn_1_CA2A4_LocalData;

void fn_1_CA2A4(int self) {
    fn_1_CA2A4_LocalData local;
    s32 count;
    s32 max;

    if (((((u32 *)&lbl_1_data_3D544)[fn_1_5910(self)] >> 29) & 1) == 0) {
        return;
    }
    count = (u8)fn_1_86810( (int)(void *)(self)) + 1;
    max = fn_1_3F7E0();
    if (count > max) {
        return;
    }
    fn_1_49410();
    fn_1_494DC(0xc);
    fn_1_496FC(lbl_1_rodata_5C3C, lbl_1_rodata_5D18);
    fn_1_495C8(1);
    fn_1_49728(1);
    fn_1_4AE0C( (const char*)(void *)(&lbl_1_data_3D574), count);
    fn_1_49410();
    fn_1_494DC(0xd);
    fn_1_496FC(lbl_1_rodata_5D5C, lbl_1_rodata_5D60);
    fn_1_49728(1);
    fn_1_4AE0C( (const char*)(void *)(&lbl_1_data_3D574), max);
    local = *(fn_1_CA2A4_LocalData *)lbl_1_rodata_26F8;
    local.x[0] = 0x9429;
    ((f32 *)local.x)[1] = lbl_1_rodata_5D64;
    ((f32 *)local.x)[2] = lbl_1_rodata_5D68;
    fn_1_51E60(&local.x[0]);
    local = *(fn_1_CA2A4_LocalData *)lbl_1_rodata_26F8;
    local.x[0] = 0x9405;
    ((f32 *)local.x)[1] = lbl_1_rodata_5D6C;
    ((f32 *)local.x)[2] = lbl_1_rodata_5D68;
    fn_1_51E60(&local.x[0]);
}
/* fzgx:end fn_1_CA2A4 */

/* fzgx:begin fn_1_CA440 noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/enemy_ctrl.h"

typedef struct { u32 a[4]; } fn_1_CA440_Colors;

extern s32 fn_1_5910(void);
extern u8 fn_1_86810(int);
extern const fn_1_CA440_Colors lbl_1_rodata_5D70;
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern const f32 lbl_1_rodata_5D80;
extern const f32 lbl_1_rodata_5D84;
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern const FontDrawPacket lbl_1_rodata_26F8;
extern int fn_1_4F734(FontDrawPacket *);

void fn_1_CA440(int arg0, s32 x, s32 y) {
    fn_1_CA440_Colors colors;
    FontDrawPacket pkt;
    s32 rank;
    s32 idx;
    int th;
    int teen;
    s32 rem;

    if ((((u32 *)&lbl_1_data_3D544)[fn_1_5910()] >> 29) & 1) {
        rank = fn_1_86810(arg0) + 1;
        colors = lbl_1_rodata_5D70;
        fn_1_49410();
        fn_1_494DC(12);
        fn_1_4955C(lbl_1_rodata_5D80, lbl_1_rodata_5D84);
        fn_1_496FC((f32)x, (f32)y);
        fn_1_4AE0C((const char *)&lbl_1_data_3D570, rank);
        pkt = lbl_1_rodata_26F8;

        teen = 0;
        rem = rank % 100;
        if (rem >= 10 && rank % 100 <= 20) {
            teen = 1;
        }
        if (teen) {
            idx = 3;
        } else {
            th = 0;
            if (rem % 10 >= 4 || rem % 10 == 0) {
                th = 1;
            }
            if (th) {
                idx = 3;
            } else {
                idx = rem % 10 - 1;
            }
        }
        pkt.image = colors.a[idx];
        pkt.x = (f32)(x + 34);
        pkt.y = (f32)(y + 29);
        fn_1_4F734(&pkt);
    }
}
/* fzgx:end fn_1_CA440 */

/* fzgx:begin fn_1_CA690 */
typedef struct {
    u32 x[22];
} fn_1_CA690_LocalData;

void fn_1_CA690(int self, int arg1, int arg2) {
    fn_1_CA690_LocalData local;
    s32 count;
    s32 max;

    if (((((u32 *)&lbl_1_data_3D544)[fn_1_5910(self)] >> 29) & 1) == 0) {
        return;
    }
    count = (u8)fn_1_86810( (int)(void *)(self)) + 1;
    fn_1_49410();
    fn_1_494DC( (u32)(0xc));
    fn_1_496FC(arg1, arg2);
    fn_1_4955C(lbl_1_rodata_5D88, lbl_1_rodata_5D8C);
    fn_1_4966C(lbl_1_rodata_5CD4, lbl_1_rodata_5D90);
    fn_1_49728( (u32)(1));
    fn_1_4AE0C( (const char*)(void *)(&lbl_1_data_3D574), count);
    max = fn_1_3F7E0();
    fn_1_49410();
    fn_1_494DC( (u32)(0xd));
    fn_1_496FC(arg1 + 0x5c, arg2 + 0x1a);
    fn_1_49728( (u32)(1));
    fn_1_4AE0C( (const char*)(void *)(&lbl_1_data_3D574), max);
    local = *(fn_1_CA690_LocalData *)lbl_1_rodata_26F8;
    local.x[0] = 0x9429;
    ((f32 *)local.x)[1] = arg1 + 0x4e;
    ((f32 *)local.x)[2] = arg2 + 0x1a;
    fn_1_51E60(&local.x[0]);
    local = *(fn_1_CA690_LocalData *)lbl_1_rodata_26F8;
    local.x[0] = 0x9405;
    ((f32 *)local.x)[1] = arg1 + 0x4e;
    ((f32 *)local.x)[2] = arg2 + 0xd;
    fn_1_51E60(&local.x[0]);
}
/* fzgx:end fn_1_CA690 */

/* fzgx:begin fn_1_CA8FC */
typedef struct {
    u32 words[22];
} fn_1_CA8FC_Copy88;


void fn_1_CA8FC(void) {
    fn_1_CA8FC_Copy88 pat;
    u32 tbl[10];
    s32 id;
    s32 off;
    s32 i;

    id = fn_1_3F1D4();
    if (id == -1) {
        return;
    }
    if (((((u32 *)&lbl_1_data_3D544)[fn_1_5910()] >> 0x1CU) & 1) == 0) {
        return;
    }
    pat = *(fn_1_CA8FC_Copy88 *)lbl_1_rodata_26F8;
    pat.words[0] = 0x942D;
    ((f32 *)pat.words)[1] = lbl_1_rodata_5D18;
    ((f32 *)pat.words)[2] = lbl_1_rodata_5DBC;
    fn_1_51E60(&pat);
    tbl[0] = lbl_1_rodata_5D94[0];
    tbl[1] = lbl_1_rodata_5D94[1];
    tbl[2] = lbl_1_rodata_5D94[2];
    tbl[3] = lbl_1_rodata_5D94[3];
    tbl[4] = lbl_1_rodata_5D94[4];
    tbl[5] = lbl_1_rodata_5D94[5];
    tbl[6] = lbl_1_rodata_5D94[6];
    tbl[7] = lbl_1_rodata_5D94[7];
    tbl[8] = lbl_1_rodata_5D94[8];
    tbl[9] = lbl_1_rodata_5D94[9];
    pat = *(fn_1_CA8FC_Copy88 *)lbl_1_rodata_26F8;
    ((f32 *)pat.words)[2] = lbl_1_rodata_5DBC;
    for (i = 0, off = 0; i <= 1; i++, off += 0x16) {
        pat.words[0] = tbl[id / (s32)fn_80088598(lbl_1_rodata_5DC0, (f64)i) % 10];
        ((f32 *)pat.words)[1] = (f32)(0x40 - off);
        fn_1_51E60(&pat);
        pat.words[0] = 0x9430;
        ((f32 *)pat.words)[3] = ((f32 *)pat.words)[3] + lbl_1_rodata_5DC8;
        fn_1_51E60(&pat);
    }
}
/* fzgx:end fn_1_CA8FC */

/* fzgx:begin fn_1_CAB38 noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/enemy_ctrl.h"

extern u8 fn_1_86A10(u32);
extern s32 fn_1_5910(void);
extern f32 fn_1_15E1D0(u32);
extern void fn_1_51E60(FontDrawPacket *);
extern const FontDrawPacket lbl_1_rodata_26F8;
extern const f32 lbl_1_rodata_5D90; /* 0.0f */
extern const f32 lbl_1_rodata_5DCC; /* 4.0f */
extern const f32 lbl_1_rodata_5DD0; /* 150.0f */
extern const f32 lbl_1_rodata_5DD4; /* 22.0f */
extern const f32 lbl_1_rodata_5DD8; /* 23.0f */

#define CLAMP(x, lo, hi) ((x) < (lo) ? (lo) : ((x) > (hi) ? (hi) : (x)))

void fn_1_CAB38(u32 arg0, u32 arg1, s32 y) {
    s32 count;
    s32 ypos;
    s32 i;
    s32 x;
    FontDrawPacket pkt;

    count = fn_1_86A10(arg0);
    if (((((u32 *)&lbl_1_data_3D544)[fn_1_5910()] >> 21) & 1) == 0) {
        return;
    }
    if ((((u32 *)&lbl_1_data_3D544)[fn_1_5910()] >> 24) & 1) {
        ypos = (s32)((f32)y + (lbl_1_rodata_5DD0 +
                               (f32)(lbl_1_rodata_5DD4 *
                                     CLAMP(fn_1_15E1D0(fn_1_5910()), lbl_1_rodata_5D90, lbl_1_rodata_5DCC))));
    } else {
        ypos = y + 0x6c;
    }
    pkt = lbl_1_rodata_26F8;
    pkt.y = (f32)ypos;
    if (count > 30) {
        count = 30;
    }
    if (count / 10 > 0) {
        pkt.image = 0x940D;
        for (i = 0; i < count / 10; i++) {
            pkt.x = (f32)(616 - i * 18);
            pkt.flags = 7;
            fn_1_51E60(&pkt);
        }
        pkt.y += lbl_1_rodata_5DD8;
    }
    pkt.image = 0x940E;
    for (i = 0; i < count % 10; i++) {
        pkt.x = (f32)(616 - i * 17);
        pkt.flags = 7;
        fn_1_51E60(&pkt);
    }
}
/* fzgx:end fn_1_CAB38 */

/* fzgx:begin fn_1_CADC4 */
struct fn_1_CADC4_Copy88 { u32 a[22]; };
struct fn_1_CADC4_lbl_1_data_3D544 {
    u32 unk_0[1];
};

void fn_1_CADC4(int arg0) {
    struct FzgxCopy_88 loc_8;
    s32 sp4;
    s32 temp_r31;

    temp_r31 = (s32) fn_1_8652C((s32)(arg0));
    if (((*(u32 *)&((&(*((struct fn_1_CADC4_lbl_1_data_3D544 *)&lbl_1_data_3D544)))[fn_1_5910()])) >> 0x1BU) & 1) {
        fn_1_49410();
        fn_1_494DC((s16)(0xF));
        fn_1_496FC((f32)(*(f32 *)((u8 *)(&lbl_1_rodata_5D1C) + 0)), (f32)(*(f32 *)((u8 *)(&lbl_1_rodata_5DDC) + 0)));
        fn_1_4966C((f32)(*(f32 *)((u8 *)(&(*((f32 *)&lbl_1_rodata_5CD4))) + 0)), (f32)(*(f32 *)((u8 *)(&(*((f32 *)&lbl_1_rodata_5D90))) + 0)));
        fn_1_49728((u8)(1U));
        fn_1_4AE0C((const char *)((s8 *) &lbl_1_data_3D57C), temp_r31);
        loc_8 = *(const struct FzgxCopy_88 *)((((s32)(((u8 *)(&(*((u32 *)&lbl_1_rodata_26F8))) + -4))) + 4));
        loc_8.words[0] = 0x9401;
        (*(f32 *)((u8 *)(&loc_8) + 4)) = *(f32 *)((u8 *)(&lbl_1_rodata_5DE0) + 0);
        (*(f32 *)((u8 *)(&loc_8) + 8)) = *(f32 *)((u8 *)(&lbl_1_rodata_5DE4) + 0);
        fn_1_51E60( (void *)((u32)((u32)(&loc_8))));
    }
}
/* fzgx:end fn_1_CADC4 */

/* fzgx:begin fn_1_CAEBC */
struct fn_1_CAEBC_Copy88 { u32 a[22]; };
struct fn_1_CAEBC_lbl_1_data_3D544 {
    u32 unk_0[1];
};

void fn_1_CAEBC(s32 arg0, s32 arg1, s32 arg2) {
    FontDrawPacket loc_8;
    s32 sp4;
    s32 temp_r31;

    temp_r31 = (s32) fn_1_8652C((s32)(arg0));
    if (((*(u32 *)&((&(*((struct fn_1_CAEBC_lbl_1_data_3D544 *)&lbl_1_data_3D544)))[fn_1_5910()])) >> 0x1BU) & 1) {
        fn_1_49410();
        fn_1_494DC((s16)(0xF));
        fn_1_496FC((f32)((f32) arg1), (f32)((f32) arg2));
        fn_1_4955C((f32)(*(f32 *)((u8 *)(&lbl_1_rodata_5DE8) + 0)), (f32)(*(f32 *)((u8 *)(&lbl_1_rodata_5DEC) + 0)));
        fn_1_4966C((f32)(*(f32 *)((u8 *)(&(*((f32 *)&lbl_1_rodata_5CFC))) + 0)), (f32)(*(f32 *)((u8 *)(&(*((f32 *)&lbl_1_rodata_5D90))) + 0)));
        fn_1_4AE0C((const char *)((s8 *) &lbl_1_data_3D57C), temp_r31);
        loc_8 = *(const FontDrawPacket *)((((s32)(((u8 *)(&(*((u32 *)&lbl_1_rodata_26F8))) + -4))) + 4));
        loc_8.image = 0x9401;
        loc_8.x = (f32) (arg1 + 0x45);
        loc_8.y = (f32) (arg2 + 0xA);
        fn_1_4F734((FontDrawPacket *)(&loc_8));
    }
}
/* fzgx:end fn_1_CAEBC */

/* fzgx:begin fn_1_CB028 noprologue */
#include "types.h"
#include "rel/main_rel/enemy_ctrl.h"

typedef struct {
    u8 r, g, b, a;
} CB028Color;

typedef struct {
    f32 x;
    f32 y;
    f32 scaleX;
    f32 scaleY;
    f32 alpha;
    u32 image;
    s32 index;
    CB028Color color;
    CB028Color color2;
} CB028Sprite;

typedef struct {
    u8 pad_0[3];
    u8 unk_3;
    u8 pad_4[4];
    u8 count;
    u8 pad_9[7];
    u32 images[8];
} CB028List;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u8 unk_8;
    u8 unk_9;
    u8 unk_A;
    u8 unk_B;
} CB028Entry;

extern s32 fn_1_5910(void);
extern void *fn_1_15F618(s32);
extern void fn_1_CB6D8(void *);
extern const CB028Color lbl_1_rodata_5DF0;
extern const CB028Color lbl_1_rodata_5DF4;
extern const CB028Color lbl_1_rodata_5DF8;
extern const CB028Color lbl_1_rodata_5DFC;
extern const CB028Color lbl_1_rodata_5E00;
extern const CB028Color lbl_1_rodata_5E04;
extern const f32 lbl_1_rodata_5CFC;
extern const f32 lbl_1_rodata_5D04;
extern const f32 lbl_1_rodata_5E08;
extern const f32 lbl_1_rodata_5E0C;
extern const f32 lbl_1_rodata_5DD4;
extern const f32 lbl_1_rodata_5E10;
extern const f32 lbl_1_rodata_5CD8;

void fn_1_CB028(s32 x, s32 y) {
    CB028Color color;
    CB028Sprite sprite;
    CB028List *list;
    CB028Entry *entry;
    s32 i;
    s32 skip;
    u32 image;
    f32 step;
    f32 alpha;
    f32 scale;
    f32 shrink;
    f32 fade;
    s32 n;
    s32 last;
    s32 k;

    scale = lbl_1_rodata_5CFC;
    color = lbl_1_rodata_5DF0;
    if ((((u32 *)&lbl_1_data_3D544)[fn_1_5910()] >> 24) & 1) {
        list = fn_1_15F618(fn_1_5910());
        entry = &((CB028Entry *)&lbl_1_bss_7ACA0)[fn_1_5910()];
        alpha = lbl_1_rodata_5CFC - (f32)list->unk_3 / 15.0f;
        n = list->count;
        if (n < 1) {
            return;
        }
        if (n > 4) {
            skip = n - 4;
            if (entry->unk_8 != 0) {
                alpha = lbl_1_rodata_5CFC;
                skip--;
                scale = (f32)entry->unk_8 / 15.0f;
            }
            n = 4;
        } else {
            skip = 0;
        }
        sprite.x = (f32)x;
        sprite.y = (f32)y;
        sprite.scaleX = lbl_1_rodata_5E08;
        sprite.scaleY = lbl_1_rodata_5E0C;
        sprite.alpha = 1.0f;
        sprite.index = -1;
        sprite.color = lbl_1_rodata_5DF4;
        sprite.color2 = lbl_1_rodata_5DF8;
        if (entry->unk_8 != 0) {
            entry->unk_8--;
        }
        last = n + skip;
        image = list->images[--last % 8];
        if (image == entry->unk_4) {
            if (entry->unk_9 != last) {
                entry->unk_A = entry->unk_9;
                entry->unk_B = 60;
                entry->unk_9 = last;
            }
            color = lbl_1_rodata_5DFC;
        }
        step = lbl_1_rodata_5DD4 * scale;
        shrink = lbl_1_rodata_5E0C;
        sprite.index = skip;
        for (i = 0; i < n - 1; i++) {
            k = i + skip;
            sprite.image = list->images[k % 8];
            if (i == 0) {
                sprite.scaleY = scale;
            } else {
                sprite.scaleY = lbl_1_rodata_5CFC;
            }
            sprite.scaleY *= shrink;
            if (entry->unk_9 == k) {
                sprite.color2 = lbl_1_rodata_5E00;
            } else if (entry->unk_A == k && entry->unk_B != 0) {
                fade = lbl_1_rodata_5CFC - (f32)entry->unk_B / lbl_1_rodata_5E10;
                fade *= lbl_1_rodata_5CD8;
                sprite.color2.b = fade;
                sprite.color2.r = 255;
                sprite.color2.g = 255;
            } else {
                sprite.color2 = lbl_1_rodata_5E04;
            }
            fn_1_CB6D8(&sprite);
            if (i == 0) {
                sprite.y += step;
            } else {
                sprite.y += lbl_1_rodata_5DD4;
            }
            sprite.index++;
        }
        if (entry->unk_B != 0) {
            entry->unk_B--;
        }
        sprite.image = image;
        sprite.color2 = color;
        sprite.alpha = alpha;
        fn_1_CB6D8(&sprite);
    }
}
/* fzgx:end fn_1_CB028 */

/* fzgx:begin fn_1_CB404 */
// Set the state flag for the selected enemy-control entry.
void fn_1_CB404(u8 value) {
    (&lbl_1_bss_7ACA0.unk_8)[value * 0xc] = 0xf;
}
/* fzgx:end fn_1_CB404 */

/* fzgx:begin fn_1_CB424 noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/enemy_ctrl.h"

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u8 pad_8[4];
} CB424Entry;

typedef struct {
    f32 x;
    f32 y;
    f32 scaleX;
    f32 scaleY;
    f32 unk_10;
    u32 unk_14;
    s32 unk_18;
    u8 color[4];
    u8 color2[4];
} CB424Sprite;

extern s32 fn_1_5910(void);
extern f32 lbl_1_rodata_26F8[22];
extern const f32 lbl_1_rodata_5E1C;
extern const f32 lbl_1_rodata_5E20;
extern const f32 lbl_1_rodata_5E08;
extern const f32 lbl_1_rodata_5E0C;
extern const f32 lbl_1_rodata_5CFC;
extern const f32 lbl_1_rodata_5E24;
extern const f32 lbl_1_rodata_5CD8;
extern const f32 lbl_1_rodata_5CD4;
extern u32 lbl_1_rodata_5E14;
extern u32 lbl_1_rodata_5E18;
extern void fn_1_51E60(FontDrawPacket *);
extern void fn_1_CB6D8(void *);

void fn_1_CB424(s32 x, s32 y, s32 idx) {
    CB424Entry *entry = &((CB424Entry *)&lbl_1_bss_7ACA0)[idx];
    CB424Sprite sprite;
    FontDrawPacket pkt;
    f32 t;
    f32 a;
    f32 c;

    if ((((u32 *)&lbl_1_data_3D544)[fn_1_5910()] >> 24) & 1) {
        pkt = *(FontDrawPacket *)lbl_1_rodata_26F8;
        pkt.image = 0x9402;
        pkt.x = lbl_1_rodata_5E1C;
        pkt.y = (f32)y;
        fn_1_51E60(&pkt);
        pkt = *(FontDrawPacket *)lbl_1_rodata_26F8;
        pkt.image = 0x940A;
        pkt.x = lbl_1_rodata_5E20;
        pkt.y = (f32)y;
        fn_1_51E60(&pkt);

        sprite.x = (f32)x;
        sprite.y = (f32)(y + 14);
        sprite.scaleX = lbl_1_rodata_5E08;
        sprite.scaleY = lbl_1_rodata_5E0C;
        sprite.unk_10 = lbl_1_rodata_5CFC;
        sprite.unk_18 = -1;
        *(u32 *)sprite.color = lbl_1_rodata_5E14;
        *(u32 *)sprite.color2 = lbl_1_rodata_5E18;
        sprite.unk_14 = entry->unk_0;
        if (entry->unk_4 != 0 && (sprite.unk_14 & ~0xFFF) == 0) {
            t = (f32)(sprite.unk_14 & 0xFFF) / lbl_1_rodata_5E24;
            a = lbl_1_rodata_5CD4 * t;
            c = lbl_1_rodata_5CD8 * (sprite.unk_10 - t);
            *(u8 *)((u8 *)&sprite + 0x1C) = c;
            *(u8 *)((u8 *)&sprite + 0x1D) = c;
            *(u8 *)((u8 *)&sprite + 0x1E) = c;
            if (a > sprite.unk_10) {
                a = sprite.unk_10;
            }
            sprite.color2[3] = lbl_1_rodata_5CD8 * (lbl_1_rodata_5CFC - a);
        }
        fn_1_CB6D8(&sprite);
    }
}
/* fzgx:end fn_1_CB424 */

/* fzgx:begin fn_1_CB6D8 noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/enemy_ctrl.h"

struct fn_1_CB6D8_lbl_1_rodata_5E50 {
    u32 unk_0; u32 unk_4; u32 unk_8; u32 unk_C;
    u32 unk_10; u32 unk_14; u32 unk_18; u32 unk_1C;
    u32 unk_20; u32 unk_24; u32 unk_28; u32 unk_2C;
};
struct fn_1_CB6D8_lbl_1_rodata_5E28 {
    u32 unk_0; u32 unk_4; u32 unk_8; u32 unk_C;
    u32 unk_10; u32 unk_14; u32 unk_18; u32 unk_1C;
    u32 unk_20; u32 unk_24;
};
struct CB6D8Color { u8 r, g, b, a; };
struct CB6D8Packet {
    s32 glyph;
    f32 x, y, z, width, height;
    u32 unk18, unk1C, unk20, unk24, unk28;
    f32 scale;
    u32 mode, unk34;
    struct CB6D8Color color;
    u32 flags;
    u32 unk40, unk44, unk48, unk4C, unk50, unk54;
};
struct CB6D8Input {
    f32 x, y, width, height, scale;
    u32 time;
    s32 rank;
    u32 flags;
    struct CB6D8Color color;
};
extern struct fn_1_CB6D8_lbl_1_rodata_5E28 lbl_1_rodata_5E28;
extern struct fn_1_CB6D8_lbl_1_rodata_5E50 lbl_1_rodata_5E50;
extern struct CB6D8Packet lbl_1_rodata_26F8;
extern f32 fn_1_519FC(f32);
extern f32 fn_1_51AC0(f32);
extern s32 fn_1_58C4(void);
extern s32 fn_1_5910(void);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_51E60(FontDrawPacket *);
extern const f32 lbl_1_rodata_5CFC, lbl_1_rodata_5E0C;
extern const f32 lbl_1_rodata_5E90, lbl_1_rodata_5E94;
extern const f32 lbl_1_rodata_5DC8, lbl_1_rodata_5CD8;
extern const f64 lbl_1_rodata_5CE8;
extern struct CB6D8Color lbl_1_rodata_5E80, lbl_1_rodata_5E84;
extern struct CB6D8Color lbl_1_rodata_5E88, lbl_1_rodata_5E8C;
static inline f32 CB6D8Alpha(u8 a) {
    return lbl_1_rodata_5CFC - (f32)(u32)a / lbl_1_rodata_5CD8;
}
void fn_1_CB6D8(void *arg0) {
    struct CB6D8Packet packet;
    struct fn_1_CB6D8_lbl_1_rodata_5E28 loc_38 = lbl_1_rodata_5E28;
    struct fn_1_CB6D8_lbl_1_rodata_5E50 loc_8 = lbl_1_rodata_5E50;
    s32 i;
    s32 rank = ((struct CB6D8Input *)arg0)->rank;
    u32 time = ((struct CB6D8Input *)arg0)->time;
    s32 first = 0;
    packet = lbl_1_rodata_26F8;
    packet.x = fn_1_519FC(((struct CB6D8Input *)arg0)->x);
    packet.y = fn_1_51AC0(((struct CB6D8Input *)arg0)->y);
    packet.width = ((struct CB6D8Input *)arg0)->scale * ((struct CB6D8Input *)arg0)->width * ((u32)fn_1_58C4() == 1 ? lbl_1_rodata_5CFC : lbl_1_rodata_5E0C);
    packet.height = ((struct CB6D8Input *)arg0)->height * ((u32)fn_1_58C4() == 1 ? lbl_1_rodata_5CFC : lbl_1_rodata_5E0C);
    packet.mode = 5;
    packet.scale = ((struct CB6D8Input *)arg0)->scale;
    packet.flags = ((struct CB6D8Input *)arg0)->flags;
    if ((u32)fn_1_58C4() > 1) {
        if (fn_1_5910() & 1) packet.x -= lbl_1_rodata_5E90;
        else packet.x += lbl_1_rodata_5E94;
    }
    if (rank == -1) first = 3;
    else if (rank < 9) first = 1;
    for (i = 11; i >= first; i--) {
        packet.x -= (f32)(((struct CB6D8Input *)arg0)->width * (((struct CB6D8Input *)arg0)->scale * ((f32 *)&loc_8)[i]) * ((u32)fn_1_58C4() == 1 ? lbl_1_rodata_5CFC : lbl_1_rodata_5E0C));
        if (i != 2) {
            packet.color = ((struct CB6D8Input *)arg0)->color;
            switch (i) {
            case 0: packet.glyph = ((u32 *)&loc_38)[((rank + 1) / 10) % 10]; packet.color = lbl_1_rodata_5E80; break;
            case 1: packet.glyph = ((u32 *)&loc_38)[(rank + 1) % 10]; packet.color = lbl_1_rodata_5E84; break;
            case 3: packet.glyph = ((u32 *)&loc_38)[((time >> 20) & 255) / 10]; break;
            case 4: packet.glyph = ((u32 *)&loc_38)[((time >> 20) & 255) % 10]; break;
            case 6: packet.glyph = ((u32 *)&loc_38)[((time >> 12) & 255) / 10]; break;
            case 7: packet.glyph = ((u32 *)&loc_38)[((time >> 12) & 255) % 10]; break;
            case 9: packet.glyph = ((u32 *)&loc_38)[(time & 4095) / 100]; break;
            case 10: packet.glyph = ((u32 *)&loc_38)[((time & 4095) / 10) % 10]; break;
            case 11: packet.glyph = ((u32 *)&loc_38)[(time & 4095) % 10]; break;
            case 5: packet.glyph = 0x943E; break;
            case 8: packet.glyph = 0x943F; break;
            default: packet.glyph = 0x9440; break;
            }
            packet.scale = ((struct CB6D8Input *)arg0)->scale;
            fn_1_4F734((FontDrawPacket *)&packet);
            if (packet.glyph == 0x943E || packet.glyph == 0x943F) {
                packet.glyph = 0x942F;
                packet.z += lbl_1_rodata_5DC8;
                packet.color = lbl_1_rodata_5E88;
                packet.scale = CB6D8Alpha(*((u8 *)arg0 + 0x23));
                fn_1_51E60((FontDrawPacket *)&packet);
            } else {
                packet.glyph = 0x9430;
                packet.z += lbl_1_rodata_5DC8;
                packet.color = lbl_1_rodata_5E8C;
                packet.scale = CB6D8Alpha(*((u8 *)arg0 + 0x23));
                fn_1_51E60((FontDrawPacket *)&packet);
            }
        }
    }
}
/* fzgx:end fn_1_CB6D8 */

/* fzgx:begin fn_1_CBC24 noprologue */
#include "types.h"
#include "rel/main_rel/enemy_ctrl.h"

struct fn_1_CBC24_Copy88 { u32 a[1]; f32 x, y, z; u32 rest[18]; };
struct fn_1_CBC24_Copy40 { u32 a[10]; };

extern const f32 lbl_1_rodata_5DC8;
extern const f32 lbl_1_rodata_5E20;
extern s32 fn_1_5910(void);
extern const f64 lbl_1_rodata_5C00;
extern struct fn_1_CBC24_Copy40 lbl_1_rodata_5E98;
extern struct fn_1_CBC24_Copy88 lbl_1_rodata_26F8;
extern void fn_1_51E60(void *);

void fn_1_CBC24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    struct fn_1_CBC24_Copy88 loc_30;
    struct fn_1_CBC24_Copy40 loc_8;
    s32 t0;
    s32 v11;
    loc_8 = lbl_1_rodata_5E98;
    t0 = fn_1_5910();
    if ((((&lbl_1_data_3D544.unk_0)[t0] >> 25) & 1) != 0) {
        loc_30 = lbl_1_rodata_26F8;
        *(f32 *)((u8 *)&loc_30 + 8) = (f32)(arg1 + 14);
        loc_30.a[0] = loc_8.a[(arg2 / 10) % 10];
        *(f32 *)((u8 *)&loc_30 + 4) = (f32)arg0;
        fn_1_51E60(&loc_30);
        loc_30.a[0] = 0x9430;
        *(f32 *)((u8 *)&loc_30 + 12) += lbl_1_rodata_5DC8;
        fn_1_51E60(&loc_30);
        loc_30.a[0] = loc_8.a[arg2 % 10];
        *(f32 *)((u8 *)&loc_30 + 4) = (f32)(arg0 + 22);
        fn_1_51E60(&loc_30);
        loc_30.a[0] = 0x9430;
        *(f32 *)((u8 *)&loc_30 + 12) += lbl_1_rodata_5DC8;
        fn_1_51E60(&loc_30);
        loc_30.a[0] = 0x943e;
        *(f32 *)((u8 *)&loc_30 + 4) = (f32)(arg0 + 44);
        fn_1_51E60(&loc_30);
        loc_30.a[0] = 0x942f;
        *(f32 *)((u8 *)&loc_30 + 12) += lbl_1_rodata_5DC8;
        fn_1_51E60(&loc_30);
        loc_30.a[0] = loc_8.a[(arg3 / 10) % 10];
        *(f32 *)((u8 *)&loc_30 + 4) = (f32)(arg0 + 54);
        fn_1_51E60(&loc_30);
        loc_30.a[0] = 0x9430;
        *(f32 *)((u8 *)&loc_30 + 12) += lbl_1_rodata_5DC8;
        fn_1_51E60(&loc_30);
        loc_30.a[0] = loc_8.a[arg3 % 10];
        *(f32 *)((u8 *)&loc_30 + 4) = (f32)(arg0 + 78);
        fn_1_51E60(&loc_30);
        loc_30.a[0] = 0x9430;
        *(f32 *)((u8 *)&loc_30 + 12) += lbl_1_rodata_5DC8;
        fn_1_51E60(&loc_30);
        loc_30.a[0] = 0x943f;
        *(f32 *)((u8 *)&loc_30 + 4) = (f32)(arg0 + 98);
        fn_1_51E60(&loc_30);
        loc_30.a[0] = 0x942f;
        *(f32 *)((u8 *)&loc_30 + 12) += lbl_1_rodata_5DC8;
        fn_1_51E60(&loc_30);
        loc_30.a[0] = loc_8.a[(arg4 / 100) % 10];
        *(f32 *)((u8 *)&loc_30 + 4) = (f32)(arg0 + 108);
        fn_1_51E60(&loc_30);
        loc_30.a[0] = 0x9430;
        *(f32 *)((u8 *)&loc_30 + 12) += lbl_1_rodata_5DC8;
        fn_1_51E60(&loc_30);
        loc_30.a[0] = loc_8.a[(arg4 / 10) % 10];
        *(f32 *)((u8 *)&loc_30 + 4) = (f32)(arg0 + 130);
        fn_1_51E60(&loc_30);
        loc_30.a[0] = 0x9430;
        *(f32 *)((u8 *)&loc_30 + 12) += lbl_1_rodata_5DC8;
        fn_1_51E60(&loc_30);
        loc_30.a[0] = loc_8.a[arg4 % 10];
        *(f32 *)((u8 *)&loc_30 + 4) = (f32)(arg0 + 152);
        fn_1_51E60(&loc_30);
        loc_30.a[0] = 0x9430;
        *(f32 *)((u8 *)&loc_30 + 12) += lbl_1_rodata_5DC8;
        fn_1_51E60(&loc_30);
        loc_30 = lbl_1_rodata_26F8;
        loc_30.a[0] = 0x940a;
        *(f32 *)((u8 *)&loc_30 + 4) = lbl_1_rodata_5E20;
        *(f32 *)((u8 *)&loc_30 + 8) = (f32)arg1;
        fn_1_51E60(&loc_30);
    }
}
/* fzgx:end fn_1_CBC24 */

/* fzgx:begin fn_1_CC27C */
// fn_1_CC27C: empty in retail (single blr).
void fn_1_CC27C(void) {
}
/* fzgx:end fn_1_CC27C */

/* fzgx:begin fn_1_CC280 */
struct fn_1_CC280_Copy88 { u32 a[22]; };
struct fn_1_CC280_lbl_1_data_3D544 {
    u32 unk_0[1];
};


void fn_1_CC280(arg0, arg1, arg2, arg3, arg4)
s32 arg0;
s32 arg1;
s32 arg2;
s32 arg3;
f32 arg4;
{
    s32 i;
    struct fn_1_CC280_lbl_1_rodata_5EC0 loc_8;
    FontDrawPacket loc_30;
    s32 v;

    loc_8 = lbl_1_rodata_5EC0;
    i = (u32)fn_1_5910();
    if ((((*((struct fn_1_CC280_lbl_1_data_3D544 *)&lbl_1_data_3D544)).unk_0[i] >> 26) & 1) != 0) {
        if (arg3 < 10) {
            loc_30 = (*((FontDrawPacket *)&lbl_1_rodata_26F8));
            v = (arg2 % 10);
            loc_30.image = loc_8.unk_0[v];
            loc_30.x = (f32)arg0;
            loc_30.y = (f32)arg1;
            fn_1_51E60(&loc_30);
            loc_30.image = 0x10000 - 27600;
            loc_30.z = loc_30.z + (*((f32 *)&lbl_1_rodata_5DC8));
            fn_1_4F734(&loc_30);
            loc_30.image = 0x10000 - 27618;
            loc_30.x = (f32)(arg0 + 22);
            loc_30.y = (f32)arg1;
            fn_1_51E60(&loc_30);
            v = (arg3 % 10);
            loc_30.image = loc_8.unk_0[v];
            loc_30.x = (f32)(arg0 + 34);
            loc_30.y = (f32)arg1;
            fn_1_51E60(&loc_30);
            loc_30.image = 0x10000 - 27600;
            loc_30.z = loc_30.z + (*((f32 *)&lbl_1_rodata_5DC8));
            fn_1_4F734(&loc_30);
            loc_30.image = 0x10000 - 27646;
            loc_30.x = (f32)(arg0 + 30);
            loc_30.y = (f32)(arg1 + 26);
            fn_1_51E60(&loc_30);
        } else {
            loc_30 = (*((FontDrawPacket *)&lbl_1_rodata_26F8));
            v = (arg2 / 10);
            loc_30.image = loc_8.unk_0[v];
            loc_30.x = (f32)(arg0 - 16);
            loc_30.y = (f32)arg1;
            loc_30.scale_x = loc_30.scale_x * (*((f32 *)&lbl_1_rodata_5E0C));
            fn_1_51E60(&loc_30);
            loc_30.image = 0x10000 - 27600;
            loc_30.z = loc_30.z + (*((f32 *)&lbl_1_rodata_5DC8));
            fn_1_4F734(&loc_30);
            v = (arg2 % 10);
            loc_30.image = loc_8.unk_0[v];
            loc_30.x = (f32)(arg0 + 1);
            loc_30.y = (f32)arg1;
            fn_1_51E60(&loc_30);
            loc_30.image = 0x10000 - 27600;
            loc_30.z = loc_30.z + (*((f32 *)&lbl_1_rodata_5DC8));
            fn_1_4F734(&loc_30);
            loc_30.image = 0x10000 - 27618;
            loc_30.x = (f32)(arg0 + 20);
            loc_30.y = (f32)arg1;
            fn_1_51E60(&loc_30);
            v = (arg3 / 10);
            loc_30.image = loc_8.unk_0[v];
            loc_30.x = (f32)(arg0 + 31);
            loc_30.y = (f32)arg1;
            fn_1_51E60(&loc_30);
            loc_30.image = 0x10000 - 27600;
            loc_30.z = loc_30.z + (*((f32 *)&lbl_1_rodata_5DC8));
            fn_1_4F734(&loc_30);
            v = (arg3 % 10);
            loc_30.image = loc_8.unk_0[v];
            loc_30.x = (f32)(arg0 + 48);
            loc_30.y = (f32)arg1;
            fn_1_51E60(&loc_30);
            loc_30.image = 0x10000 - 27600;
            loc_30.z = loc_30.z + (*((f32 *)&lbl_1_rodata_5DC8));
            fn_1_4F734(&loc_30);
            loc_30.image = 0x10000 - 27646;
            loc_30.x = (f32)(arg0 + 41);
            loc_30.y = (f32)(arg1 + 26);
            loc_30.scale_x = (*((f32 *)&lbl_1_rodata_5CFC));
            fn_1_51E60(&loc_30);
        }
    }
}
/* fzgx:end fn_1_CC280 */

/* fzgx:begin fn_1_CC8E4 */
void fn_1_CC8E4(s32 arg0, s32 arg1, s32 arg2) {
    FontDrawPacket sp30;
    u32 sp8[10];
    s32 val1;
    u8 val2;

    sp8[0] = lbl_1_rodata_5EE8[0];
    sp8[1] = lbl_1_rodata_5EE8[1];
    sp8[2] = lbl_1_rodata_5EE8[2];
    sp8[3] = lbl_1_rodata_5EE8[3];
    sp8[4] = lbl_1_rodata_5EE8[4];
    sp8[5] = lbl_1_rodata_5EE8[5];
    sp8[6] = lbl_1_rodata_5EE8[6];
    sp8[7] = lbl_1_rodata_5EE8[7];
    sp8[8] = lbl_1_rodata_5EE8[8];
    sp8[9] = lbl_1_rodata_5EE8[9];
    val1 = *(s32 *)((u8 *)fn_1_8627C(arg0) + 280) + 1;
    val2 = fn_1_3F114();
    if (((((u32 *)&lbl_1_data_3D544))[fn_1_5910()] >> 26) & 1) {
        if ((s32)val2 < 0xA) {
            sp30 = *(const FontDrawPacket *)(((u8 *)(((u32 *)&lbl_1_rodata_26F8))) + 0);
            sp30.image = sp8[val1 % 10];
            sp30.x = (f32)(arg1 + 3);
            sp30.y = (f32)arg2;
            sp30.scale_x *= lbl_1_rodata_5CF8 / (f32)fn_1_48690(sp30.image);
            sp30.scale_y *= lbl_1_rodata_5F10 / (f32)fn_1_486C4(sp30.image);
            fn_1_4F734(&sp30);
            sp30.image = 0x9430;
            sp30.z += lbl_1_rodata_5DC8;
            fn_1_4F734(&sp30);
            sp30 = *(const FontDrawPacket *)(((u8 *)(((u32 *)&lbl_1_rodata_26F8))) + 0);
            sp30.image = 0x941E;
            sp30.x = (f32)(arg1 + 0x12);
            sp30.y = (f32)arg2;
            sp30.scale_x *= lbl_1_rodata_5C48 / (f32)fn_1_48690(0x941E);
            sp30.scale_y *= lbl_1_rodata_5F10 / (f32)fn_1_486C4(sp30.image);
            fn_1_4F734(&sp30);
            sp30 = *(const FontDrawPacket *)(((u8 *)(((u32 *)&lbl_1_rodata_26F8))) + 0);
            sp30.image = sp8[val2 % 10];
            sp30.x = (f32)(arg1 + 0x1C);
            sp30.y = (f32)arg2;
            sp30.scale_x *= lbl_1_rodata_5CF8 / (f32)fn_1_48690(sp30.image);
            sp30.scale_y *= lbl_1_rodata_5F10 / (f32)fn_1_486C4(sp30.image);
            fn_1_4F734(&sp30);
            sp30.image = 0x9430;
            sp30.z += lbl_1_rodata_5DC8;
            fn_1_4F734(&sp30);
            sp30 = *(const FontDrawPacket *)(((u8 *)(((u32 *)&lbl_1_rodata_26F8))) + 0);
            sp30.image = 0x9402;
            sp30.x = (f32)(arg1 + 0x2D);
            sp30.y = (f32)(arg2 + 9);
            fn_1_4F734(&sp30);
            return;
        }
        sp30 = *(const FontDrawPacket *)(((u8 *)(((u32 *)&lbl_1_rodata_26F8))) + 0);
        sp30.image = sp8[val1 / 10];
        sp30.x = (f32)(arg1 - 0x1D);
        sp30.y = (f32)arg2;
        sp30.scale_x *= lbl_1_rodata_5CF8 / (f32)fn_1_48690(sp30.image);
        sp30.scale_y *= lbl_1_rodata_5F10 / (f32)fn_1_486C4(sp30.image);
        fn_1_4F734(&sp30);
        sp30.image = 0x9430;
        sp30.z += lbl_1_rodata_5DC8;
        fn_1_4F734(&sp30);
        sp30.image = sp8[val1 % 10];
        sp30.x = (f32)(arg1 - 0xD);
        sp30.y = (f32)arg2;
        fn_1_4F734(&sp30);
        sp30.image = 0x9430;
        sp30.z += lbl_1_rodata_5DC8;
        fn_1_4F734(&sp30);
        sp30 = *(const FontDrawPacket *)(((u8 *)(((u32 *)&lbl_1_rodata_26F8))) + 0);
        sp30.image = 0x941E;
        sp30.x = (f32)(arg1 + 2);
        sp30.y = (f32)arg2;
        sp30.scale_x *= lbl_1_rodata_5C48 / (f32)fn_1_48690(0x941E);
        sp30.scale_y *= lbl_1_rodata_5F10 / (f32)fn_1_486C4(sp30.image);
        fn_1_4F734(&sp30);
        sp30 = *(const FontDrawPacket *)(((u8 *)(((u32 *)&lbl_1_rodata_26F8))) + 0);
        sp30.image = sp8[val2 / 10];
        sp30.x = (f32)(arg1 + 0xC);
        sp30.y = (f32)arg2;
        sp30.scale_x *= lbl_1_rodata_5CF8 / (f32)fn_1_48690(sp30.image);
        sp30.scale_y *= lbl_1_rodata_5F10 / (f32)fn_1_486C4(sp30.image);
        fn_1_4F734(&sp30);
        sp30.image = 0x9430;
        sp30.z += lbl_1_rodata_5DC8;
        fn_1_4F734(&sp30);
        sp30.image = sp8[val2 % 10];
        sp30.x = (f32)(arg1 + 0x1C);
        sp30.y = (f32)arg2;
        fn_1_4F734(&sp30);
        sp30.image = 0x9430;
        sp30.z += lbl_1_rodata_5DC8;
        fn_1_4F734(&sp30);
        sp30 = *(const FontDrawPacket *)(((u8 *)(((u32 *)&lbl_1_rodata_26F8))) + 0);
        sp30.image = 0x9402;
        sp30.x = (f32)(arg1 + 0x2D);
        sp30.y = (f32)(arg2 + 9);
        fn_1_4F734(&sp30);
    }
}
/* fzgx:end fn_1_CC8E4 */

/* fzgx:begin fn_1_CD36C */
void fn_1_CD36C(void *unused, s32 a, s32 b) {
    FontDrawPacket p;
    s32 idx;

    idx = fn_1_5910();
    p = (*((FontDrawPacket *)&lbl_1_rodata_26F8));
    p.image = 0x9421;
    fn_1_51564(0, 0, 0x18, 0x14, 2, 2);
    p.x = (f32)a;
    p.y = (f32)b;
    p.z = 10.0f;
    fn_1_5158C(&p, p.image, idx % 2, idx / 2);
    fn_1_4F734(&p);
    p = (*((FontDrawPacket *)&lbl_1_rodata_26F8));
    p.image = 0x9422;
    p.x = (f32)(a + 0xc);
    p.y = (f32)(b + 0xa);
    p.z = 20.0f;
    p.flags = 10;
    fn_1_4F734(&p);
}
/* fzgx:end fn_1_CD36C */

/* fzgx:begin fn_1_CD51C */
extern s32 fn_1_5910();
extern u32 fn_1_8627C(s32 index);
extern void *fn_1_4DF60(void);
extern u32 fn_1_58C4(void);
extern const f32 lbl_1_rodata_5C3C;
extern const f32 lbl_1_rodata_5C40;
extern const f32 lbl_1_rodata_5F18;
extern const f32 lbl_1_rodata_5CFC;
extern const f32 lbl_1_rodata_5E0C;
extern u32 lbl_1_rodata_5F14;
extern f32 fn_1_519FC(f32 value);
extern f32 fn_1_51AC0(f32 value);

typedef struct {
    u8 pad_0[0x6];
    u16 unk_6;
    u32 unk_8;
    f32 unk_c;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1c;
    u8 pad_20[0x18];
    u32 unk_38;
    f32 unk_3c;
    u32 unk_40;
    u8 pad_44[0x1c];
    void *unk_60;
    u8 pad_64[0x14];
    void (*unk_78)(fn_1_CD6C0_object *);
} Fn1Cd51cObject;

// Spawn the display object for an active controller and initialize its layout and update callback.
void fn_1_CD51C(void *object) {
    u32 index;
    u8 *actor;
    Fn1Cd51cObject *state;
    f32 factor;

    index = fn_1_5910(object);
    if (((((u32 *)&lbl_1_data_3D544)[index] >> 19) & 1) == 0) {
        return;
    }

    actor = (u8 *)fn_1_8627C((s32)object);
    if (actor == 0) {
        return;
    }
    if (*(s32 *)(actor + 0x10c) == 0) {
        return;
    }
    if (*(s32 *)(actor + 0x110) == 0) {
        return;
    }

    state = fn_1_4DF60();
    if (state == 0) {
        return;
    }

    state->unk_8 = 0x9435;
    state->unk_c = lbl_1_rodata_5C3C;
    state->unk_10 = lbl_1_rodata_5C40;
    state->unk_14 = lbl_1_rodata_5F18;

    if (fn_1_58C4() == 1) {
        factor = lbl_1_rodata_5CFC;
    } else {
        factor = lbl_1_rodata_5E0C;
    }
    state->unk_18 *= factor;

    if (fn_1_58C4() == 1) {
        factor = lbl_1_rodata_5CFC;
    } else {
        factor = lbl_1_rodata_5E0C;
    }
    state->unk_1c *= factor;

    state->unk_38 = 10;
    state->unk_40 = lbl_1_rodata_5F14;

    if (fn_1_58C4() == 1 && (s32)lbl_1_bss_4E6A8 != 0) {
        u32 value = state->unk_38 | 0x8000000;
        state->unk_38 = value;
        state->unk_3c = (f32)(s32)lbl_1_bss_4E6AC;
    }

    state->unk_6 = 0;
    state->unk_78 = fn_1_CD6C0;
    state->unk_60 = object;
    state->unk_c = fn_1_519FC(state->unk_c);
    state->unk_10 = fn_1_51AC0(state->unk_10);
}
/* fzgx:end fn_1_CD51C */

/* fzgx:begin fn_1_CD6C0 */
typedef struct fn_1_CD6C0_target {
    u8 pad0[0x10c];
    s32 flags;
} fn_1_CD6C0_target;

#pragma opt_propagation off
void fn_1_CD6C0(fn_1_CD6C0_object *object) {
    s32 state;
    s32 out;
    void *controller;
    fn_1_CD6C0_target *target;

    state = object->state;
    if (state + 1 > 0x3b) {
        out = 0;
    } else {
        state++;
        out = 0x3b;
        if (state >= 0) {
            out = state;
        }
    }
    object->state = out;
    if (object->state < 0x1e) {
        object->value = lbl_1_rodata_5CFC;
    } else {
        object->value = lbl_1_rodata_5D90;
    }
    if (fn_1_8664C( (int)(void *)(object->controller)) != 0) {
        object->value = lbl_1_rodata_5D90;
        object->flags = 0;
    }
    if (object->state == 0x1e) {
        controller = object->controller;
        target = (void *)fn_1_8627C( (s32)(void *)(controller));
        if (target != 0) {
            if (target->flags == 0) {
                object->flags = 0;
            }
            if ((fn_1_864E8( (int)(void *)(controller)) & 0x10010880) != 0) {
                object->flags = 0;
            }
        }
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_CD6C0 */

/* fzgx:begin fn_1_CD7BC */
extern const f32 lbl_1_rodata_5C3C; /* 320.0f */
extern const f32 lbl_1_rodata_5C40; /* 240.0f */
extern const f32 lbl_1_rodata_5C48; /* 10.0f */
extern const f32 lbl_1_rodata_5C7C; /* 13.0f */
extern const f32 lbl_1_rodata_5CFC; /* 1.0f */
extern const f32 lbl_1_rodata_5D90; /* 0.0f */
extern const f32 lbl_1_rodata_5E0C; /* 0.8f */
extern const f32 lbl_1_rodata_5F10; /* 20.0f */
extern const f32 lbl_1_rodata_5F18; /* 999.0f */
extern const f32 lbl_1_rodata_5F1C; /* 1/13 */


void fn_1_CD7BC(int arg0) {
    s32 base;
    s32 y;
    s32 n;
    s32 i;
    struct FzgxCopy_88 pkt;
    f32 scale;
    f32 one;
    f32 step;
    f32 count;

    if (!(fn_1_864E8(arg0) & 0x10010080)) {
        n = fn_1_8664C(arg0);
        if (n > 0x14 && n < 0xAA) {
            pkt = *(const struct FzgxCopy_88 *)(((u32 *)&lbl_1_rodata_26F8));
            pkt.words[0] = 0x940C;
            *(f32 *)((u8 *)&pkt + 12) = lbl_1_rodata_5F18;
            if (fn_1_58C4() == 1) {
                scale = lbl_1_rodata_5CFC;
            } else {
                scale = lbl_1_rodata_5E0C;
            }
            *(f32 *)((u8 *)&pkt + 16) *= scale;
            if (fn_1_58C4() == 1) {
                scale = lbl_1_rodata_5CFC;
            } else {
                scale = lbl_1_rodata_5E0C;
            }
            *(f32 *)((u8 *)&pkt + 20) *= scale;
            i = 0;
            y = 0;
            base = n - 0x14;
            *(f32 *)((u8 *)&pkt + 44) = lbl_1_rodata_5D90;
            one = lbl_1_rodata_5CFC;
            do {
                s32 d;
                *(f32 *)((u8 *)&pkt + 20) = one;
                d = base - i;
                if (i < 6) {
                    if (d > 0 && d < 0xA) {
                        pkt.words[0xC] = 9;
                        *(f32 *)((u8 *)&pkt + 4) = lbl_1_rodata_5C3C - (f32)((fn_1_48690(pkt.words[0]) >> 1U) & 0x7FFF);
                    } else {
                        pkt.words[0xC] = 0xB;
                        *(f32 *)((u8 *)&pkt + 4) = lbl_1_rodata_5C3C + (f32)((fn_1_48690(pkt.words[0]) >> 1U) & 0x7FFF);
                    }
                } else if (d > 0 && d < 0xA) {
                    pkt.words[0xC] = 0xB;
                    *(f32 *)((u8 *)&pkt + 4) = lbl_1_rodata_5C3C + (f32)((fn_1_48690(pkt.words[0]) >> 1U) & 0x7FFF);
                } else {
                    pkt.words[0xC] = 9;
                    *(f32 *)((u8 *)&pkt + 4) = lbl_1_rodata_5C3C - (f32)((fn_1_48690(pkt.words[0]) >> 1U) & 0x7FFF);
                }
                *(f32 *)((u8 *)&pkt + 8) = (f32)y + (lbl_1_rodata_5C40 - (f32)((fn_1_486C4(pkt.words[0]) >> 1U) & 0x7FFF));
                if (d > 0 && d < 0xA) {
                    *(f32 *)((u8 *)&pkt + 16) *= lbl_8006D0B4(lbl_1_rodata_5C48 / (f32)(d + 1));
                    *(f32 *)((u8 *)&pkt + 44) = (f32)d / lbl_1_rodata_5C48;
                } else if (d > 0x82 && d < 0x96) {
                    *(f32 *)((u8 *)&pkt + 16) *= lbl_8006D0B4(lbl_1_rodata_5F10 / (f32)(0x97 - d));
                    *(f32 *)((u8 *)&pkt + 44) = (f32)(0x96 - d) / lbl_1_rodata_5F10;
                } else if (d >= 0xA && d <= 0x82) {
                    *(f32 *)((u8 *)&pkt + 16) = lbl_1_rodata_5CFC;
                    *(f32 *)((u8 *)&pkt + 44) = lbl_1_rodata_5CFC;
                } else if (d <= 0 || d >= 0x96) {
                    *(f32 *)((u8 *)&pkt + 44) = lbl_1_rodata_5D90;
                }
                count = lbl_1_rodata_5C7C;
                step = lbl_1_rodata_5F1C;
                *(f32 *)((u8 *)&pkt + 28) = (f32)i / count;
                *(f32 *)((u8 *)&pkt + 36) = (f32)(i + 1) / count;
                *(f32 *)((u8 *)&pkt + 20) *= step;
                fn_1_4F734((FontDrawPacket *)&pkt);
                i += 1;
                y += 4;
            } while (i < 0xD);
        }
    }
}
/* fzgx:end fn_1_CD7BC */

/* fzgx:begin fn_1_CF5B0 */
void fn_1_CF5B0(void *self) {
    FontDrawPacket loc_10;
    u32 spC;
    u32 sp8;
    s32 var_r30;
    s32 var_r31;
    s32 temp_r0;

    if (((((u32 *)&lbl_1_data_3D544)[fn_1_5910(self)]) >> 17) & 1) {
        fn_1_3EF14(&lbl_1_bss_3C30);
        if (lbl_1_bss_3C30.unk_0 & 0x40000) {
            var_r30 = 0;
            var_r31 = ((lbl_1_bss_3C30.unk_A4 + 0x3B) / 60 < 0) ? 0
                      : (((lbl_1_bss_3C30.unk_A4 + 0x3B) / 60 > 0x3E7) ? 0x3E7 : (lbl_1_bss_3C30.unk_A4 + 0x3B) / 60);
            if (var_r31 < 0xA) {
                var_r30 = 1;
            }
            fn_1_49410();
            if (var_r30 != 0) {
                spC = lbl_1_rodata_5FF0;
                fn_1_49514(&spC);
            }
            fn_1_494DC(0x10);
            fn_1_495C8(9);
            if (var_r31 > 0x63) {
                fn_1_4955C(lbl_1_rodata_5FF8, lbl_1_rodata_5CFC);
                fn_1_496FC(lbl_1_rodata_5FFC, lbl_1_rodata_5F7C);
                fn_1_4AE0C((const char *)&lbl_1_data_3D570, var_r31 / 100);
                fn_1_496FC(lbl_1_rodata_5C3C, lbl_1_rodata_5F7C);
                fn_1_4AE0C((const char *)&lbl_1_data_3D570, (var_r31 / 10) % 10);
                fn_1_496FC(lbl_1_rodata_6000, lbl_1_rodata_5F7C);
                fn_1_4AE0C((const char *)&lbl_1_data_3D570, var_r31 % 10);
            } else {
                fn_1_496FC(lbl_1_rodata_6004, lbl_1_rodata_5F7C);
                fn_1_4AE0C((const char *)&lbl_1_data_3D570, var_r31 / 10);
                fn_1_496FC(lbl_1_rodata_6008, lbl_1_rodata_5F7C);
                fn_1_4AE0C((const char *)&lbl_1_data_3D570, var_r31 % 10);
            }
            fn_1_49410();
            fn_1_494DC(0x11);
            fn_1_495C8(9);
            sp8 = lbl_1_rodata_5FF4;
            fn_1_49514(&sp8);
            fn_1_495A0(lbl_1_rodata_5CB0);
            if (var_r31 > 0x63) {
                fn_1_4955C(lbl_1_rodata_5FF8, lbl_1_rodata_5CFC);
                fn_1_496FC(lbl_1_rodata_5FFC, lbl_1_rodata_5F7C);
                fn_1_4AE0C((const char *)&lbl_1_data_3D570, var_r31 / 100);
                fn_1_496FC(lbl_1_rodata_5C3C, lbl_1_rodata_5F7C);
                fn_1_4AE0C((const char *)&lbl_1_data_3D570, (var_r31 / 10) % 10);
                fn_1_496FC(lbl_1_rodata_6000, lbl_1_rodata_5F7C);
                fn_1_4AE0C((const char *)&lbl_1_data_3D570, var_r31 % 10);
            } else {
                fn_1_496FC(lbl_1_rodata_6004, lbl_1_rodata_5F7C);
                fn_1_4AE0C((const char *)&lbl_1_data_3D570, var_r31 / 10);
                fn_1_496FC(lbl_1_rodata_6008, lbl_1_rodata_5F7C);
                fn_1_4AE0C((const char *)&lbl_1_data_3D570, var_r31 % 10);
            }
            loc_10 = *(const FontDrawPacket *)lbl_1_rodata_26F8;
            loc_10.image = 0x940A;
            loc_10.x = lbl_1_rodata_600C;
            loc_10.y = lbl_1_rodata_5D68;
            fn_1_4F734(&loc_10);
        }
    }
}
/* fzgx:end fn_1_CF5B0 */

/* fzgx:begin fn_1_CFA0C */
u32 fn_1_CFA0C(void) {
    u32 bit = (((u32 *)&lbl_1_data_3D544)[fn_1_5910()] >> 16) & 1;
    return bit ? 0 : 0;
}
/* fzgx:end fn_1_CFA0C */

/* fzgx:begin fn_1_CFA4C */
struct fn_1_CFA4C_Copy88 { u32 a[22]; };






void fn_1_CFA4C(u32 arg0, u32 arg1) {
    f32 v0;
    u32 v1;
    f32 v2;
    FontDrawPacket loc_8;
    /* frame */
    fn_1_520A0();
    fn_1_52070(640);
    loc_8 = *(FontDrawPacket *)&(*(u32 *)&lbl_1_rodata_26F8);
    v0 = (f32)(s32)(arg0 + 304);
    v1 = (0x10000 - 27620);
    loc_8.image = v1;
    v2 = (f32)(s32)(arg1 - 11);
    loc_8.x = v0;
    loc_8.y = v2;
    loc_8.z = lbl_1_rodata_6010;
    loc_8.flags = 7;
    fn_1_4F734((FontDrawPacket *)&loc_8);
    fn_1_520CC();
}
/* fzgx:end fn_1_CFA4C */

/* fzgx:begin fn_1_CFCA4 noprologue */
#include "types.h"

typedef struct { f32 value; } fzgx_f32_box;

typedef struct {
    u8 r, g, b, a;
} RGBA8;

typedef struct {
    s32 kind;
    u32 unk_04;
    f32 scale;
    u32 unk_0C[7];
    s16 angle;
    u16 unk_2A;
    u32 unk_2C[11];
} TextBoxState;

extern fzgx_f32_box lbl_1_rodata_5FD8;
extern fzgx_f32_box lbl_1_rodata_603C;
extern fzgx_f32_box lbl_1_rodata_5C88;
extern RGBA8 lbl_1_rodata_602C;
extern RGBA8 lbl_1_rodata_6030;
extern RGBA8 lbl_1_rodata_6034;
extern RGBA8 lbl_1_rodata_6038;
extern fzgx_f32_box lbl_1_rodata_6050;
extern fzgx_f32_box lbl_1_rodata_5CD4;
extern const f32 lbl_1_rodata_6040;
extern const f32 lbl_1_rodata_6044;
extern const f32 lbl_1_rodata_5D90;
extern const f32 lbl_1_rodata_6048;
extern const f32 lbl_1_rodata_604C;
extern const f32 lbl_1_rodata_6054;
extern const f32 lbl_1_rodata_5DCC;
extern const f32 lbl_1_rodata_5CFC;
extern TextBoxState lbl_1_rodata_26F8;
extern s32 lbl_801A66B4;

extern void fn_1_49410(void);
extern void fn_1_495C8(u8);
extern void fn_1_495B0(u32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_49514(RGBA8);
extern void fn_1_49748(f32);
extern void fn_1_495A0(f32);
extern u32 fn_1_52968(s32, s32, const char *, f32, ...);
extern void fn_1_51914(TextBoxState *);
extern void fn_1_496FC(f32, f32);
extern void fn_1_527B4(void);
extern void fn_1_49738(void (*)(void));
extern void fn_1_4954C(f32);
extern void fn_1_4AE0C(const char *, ...);

void fn_1_CFCA4(const char *text, f32 x, f32 y, f32 scale) {
    TextBoxState state;
    RGBA8 color0;
    RGBA8 color1;
    RGBA8 color2;
    RGBA8 color3;
    f32 size0;
    f32 size1;
    f32 size2;
    s32 iy;
    s32 ix;

    size0 = lbl_1_rodata_5FD8.value * scale;
    color0 = lbl_1_rodata_602C;
    size1 = lbl_1_rodata_603C.value * scale;
    color1 = lbl_1_rodata_6030;
    size2 = lbl_1_rodata_5C88.value * scale;
    color2 = lbl_1_rodata_6034;

    fn_1_49410();
    fn_1_495C8(1);
    fn_1_495B0(0x10000);
    fn_1_4955C(lbl_1_rodata_6040, lbl_1_rodata_6040);
    if (lbl_801A66B4 == 5) {
        fn_1_4966C(lbl_1_rodata_6044, lbl_1_rodata_5D90);
    } else {
        fn_1_495B0(0x80000000);
    }

    fn_1_49514(color0);
    fn_1_49748(lbl_1_rodata_6048);
    fn_1_495A0(size0);
    ix = (s32)x;
    iy = (s32)y;
    fn_1_52968(ix, iy, text, lbl_1_rodata_5DCC);

    fn_1_49514(color1);
    fn_1_49748(lbl_1_rodata_604C);
    fn_1_495A0(size1);
    fn_1_52968(ix, iy, text, lbl_1_rodata_6050.value);

    fn_1_49514(color2);
    fn_1_49748(lbl_1_rodata_6054);
    fn_1_495A0(size2);
    fn_1_52968(ix, iy, text, lbl_1_rodata_5CD4.value);

    color3 = lbl_1_rodata_6038;
    state = lbl_1_rodata_26F8;
    state.kind = 5;
    state.angle = -0x4000;
    state.scale = lbl_1_rodata_5CFC;
    fn_1_51914(&state);

    fn_1_49514(color3);
    fn_1_49748(lbl_1_rodata_5D90);
    fn_1_495A0(scale);
    fn_1_495B0(0x80000000);
    fn_1_496FC(x, y);
    fn_1_49738(fn_1_527B4);
    fn_1_4954C(lbl_1_rodata_5CFC);
    fn_1_4AE0C(text);
}
/* fzgx:end fn_1_CFCA4 */

/* fzgx:begin fn_1_CFF94 */
struct fn_1_CFF94_Copy88 { u32 a[22]; };


#pragma opt_strength_reduction off
#pragma opt_common_subs off
void fn_1_CFF94(u32 arg0, s16 arg1, f32 arg2) {
    s32 v6;
    s16 v6s;
    s32 v7;
    s32 v8;
    FontDrawPacket loc_8;

    arg0 = arg0;
    if (arg1 == 0) {
        return;
    }
    v6 = 28;
    if (*(u8 *)((u8 *)&(*((u32 *)&lbl_1_bss_3C30)) + 5) != 2) {
        v6 = 60;
    }
    if ((s32)lbl_801A66B4 == 5) {
        if (arg1 >= 10) {
            v7 = 50;
        } else {
            v7 = 0;
        }
    } else {
        if (arg1 >= 10) {
            v7 = -25;
        } else {
            v7 = -29;
        }
    }
    loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_8.image = 0xBB01;
    ((f32 *)&loc_8)[0xB] = arg2;
    ((u32 *)&loc_8)[0xC] = 10;
    loc_8.x = (f32)(s32)(529 - (s16)v7);
    v6s = (s16)v6;
    loc_8.y = (f32)(s32)(((360) + (v6s)));
    loc_8.z = (3.0f);
    fn_1_4F734((FontDrawPacket *)&loc_8);
    if ((s32)lbl_801A66B4 == 5) {
        if (arg1 >= 10) {
            v8 = 27;
        } else {
            v8 = 0;
        }
    } else {
        if (arg1 >= 10) {
            v8 = 133;
        } else {
            v8 = 106;
        }
    }
    fn_1_49410();
    fn_1_494DC(0x28);
    fn_1_496FC((f32)(s32)(590 - (s16)v8), (f32)(s32)(((355) + (v6s))));
    fn_1_495C8(9);
    fn_1_4954C((4.0f));
    fn_1_495A0(arg2);
    fn_1_4AE0C((const char *)&lbl_1_data_3D630, arg1);
}
#pragma opt_common_subs reset

#pragma opt_strength_reduction reset
/* fzgx:end fn_1_CFF94 */

/* fzgx:begin fn_1_D01B0 */
void fn_1_D01B0(f32 farg0) {
    FontDrawPacket loc_B8;
    u32 sp80[14];
    u32 sp48[14];
    u32 sp10[14];
    u32 sp8[2];
    u32 flags;
    s16 temp_r30;
    s16 temp_r30_2;

    fn_1_156218((u32) lbl_1_bss_3C30.unk_6, (void *) sp80, (void *) sp48, (void *) sp10);
    flags = sp80[0];
    loc_B8 = *(const FontDrawPacket *) (((u32 *)&lbl_1_rodata_26F8));
    loc_B8.image = 0xBB03;
    temp_r30 = (s16) (fn_1_486C4(0xBB03U) / 3);
    fn_1_51564(0, 0, fn_1_48690(loc_B8.image), temp_r30, 1, 3);
    fn_1_5158C(&loc_B8, loc_B8.image, 0U, 0U);
    loc_B8.alpha = farg0;
    loc_B8.x = lbl_1_rodata_6004;
    loc_B8.y = lbl_1_rodata_605C;
    loc_B8.z = lbl_1_rodata_5CD4;
    fn_1_4F734(&loc_B8);
    loc_B8 = *(const FontDrawPacket *) (((u32 *)&lbl_1_rodata_26F8));
    loc_B8.image = 0xBB03;
    temp_r30_2 = (s16) (fn_1_486C4(0xBB03U) / 3);
    fn_1_51564(0, 0, fn_1_48690(loc_B8.image), temp_r30_2, 1, 3);
    fn_1_5158C(&loc_B8, loc_B8.image, 0U, 2U);
    loc_B8.alpha = farg0;
    loc_B8.x = lbl_1_rodata_6060;
    loc_B8.y = lbl_1_rodata_605C;
    loc_B8.z = lbl_1_rodata_6050;
    fn_1_4F734(&loc_B8);
    fn_1_49410();
    fn_1_494DC(0x29);
    fn_1_495B0(0x80000000U);
    fn_1_4955C(lbl_1_rodata_5D3C, lbl_1_rodata_5D3C);
    fn_1_496FC(lbl_1_rodata_6064, lbl_1_rodata_6068);
    fn_1_4954C(lbl_1_rodata_5DCC);
    fn_1_495A0(farg0);
    sp8[0] = lbl_1_rodata_6058;
    fn_1_49514(sp8);
    fn_1_495FC();
    fn_1_4AE0C((const char *) lbl_1_data_3D634, (u8) (flags >> 0x14U), (u8) (flags >> 0xCU), flags & 0xFFF);
}
/* fzgx:end fn_1_D01B0 */

/* fzgx:begin fn_1_D0728 */
#pragma opt_propagation off
void fn_1_D0728(u32 arg0, u32 arg1) {
    u32 *data;
    u32 *state;
    u32 value;

    value = 0xfffb8004;
    data = (u32 *)&lbl_1_data_3D544;
    state = (u32 *)&lbl_1_bss_7ACA0;

    data[0] = value;
    state[0] = 0;
    state[1] = 0;
    ((u8 *)state)[0x8] = 0;
    ((u8 *)state)[0x9] = 0;
    data[1] = value;
    state[3] = 0;
    state[4] = 0;
    ((u8 *)state)[0x14] = 0;
    ((u8 *)state)[0x15] = 0;
    data[2] = value;
    state[6] = 0;
    state[7] = 0;
    ((u8 *)state)[0x20] = 0;
    ((u8 *)state)[0x21] = 0;
    data[3] = value;
    state[9] = 0;
    state[10] = 0;
    ((u8 *)state)[0x2c] = 0;
    ((u8 *)state)[0x2d] = 0;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_D0728 */

/* fzgx:begin fn_1_D0790 */
void fn_1_D0790(void) {
    u32 *p = (u32 *)&lbl_1_data_3D544;
    *p++ = 0;
    *p++ = 0;
    *p++ = 0;
    *p++ = 0;
}
/* fzgx:end fn_1_D0790 */

/* fzgx:begin fn_1_D07AC */
// Stores a value in the indexed enemy-control slot.
void fn_1_D07AC(u32 index, u32 value) {
    u32* slots = &lbl_1_bss_7ACA0.unk_0;
    slots[(index & 0xff) * 3] = value;
}
/* fzgx:end fn_1_D07AC */

/* fzgx:begin fn_1_D07C4 */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
} EnemyCtrlEntry_D07C4;

// Store a value into field 4 of the indexed 0xC-byte entry.
void fn_1_D07C4(u32 arg0, u32 arg1) {
    EnemyCtrlEntry_D07C4 *entry = (EnemyCtrlEntry_D07C4 *)&lbl_1_bss_7ACA0;
    entry += arg0 & 0xFF;
    entry->unk_4 = arg1;
}
/* fzgx:end fn_1_D07C4 */

/* fzgx:begin fn_1_D07E0 noprologue */
#include "types.h"
#include "font.h"
#include "game/main_rel/car_test_types.h"
#include "rel/main_rel/enemy_ctrl.h"

typedef struct {
    f32 value0;
    f32 value1;
    f32 value2;
} Sig_fn_8006F78C_Fn8006F78CData;
struct fn_1_D07E0_Copy88 { u32 a[22]; };
extern const f32 lbl_1_rodata_5CB0;
extern const f32 lbl_1_rodata_5CD8;
extern const f32 lbl_1_rodata_5DC8;
extern const f32 lbl_1_rodata_5E10;
extern const f32 lbl_1_rodata_5F50;
extern const f32 lbl_1_rodata_606C;
extern const f32 lbl_1_rodata_5CFC;
extern const f32 lbl_1_rodata_5DCC;
extern const f64 lbl_1_rodata_5CE8;
extern const f64 lbl_1_rodata_6070;
extern f32 lbl_8006D21C(u32);
extern const f64 lbl_1_rodata_5C00;
extern int fn_1_4F734(FontDrawPacket *);
struct fn_1_D07E0_lbl_1_bss_7ACD0 { s32 unk_0; u32 unk_4; };
extern struct fn_1_D07E0_lbl_1_bss_7ACD0 lbl_1_bss_7ACD0;
extern FontDrawPacket lbl_1_rodata_26F8;
extern u32 fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern u32 lbl_801A66A0;
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);
extern void fn_8006F78C(Fn183D28Vec3 *, Sig_fn_8006F78C_Fn8006F78CData *, f32);
extern Fn183D28Vec3 *fn_1_EB0D8(u32);
extern u32 fn_1_EB0B0(void);

void fn_1_D07E0(f32 arg0, f32 arg1, f32 arg2) {
    struct { f32 *value; } p_lbl_1_rodata_26F8;
    Obj_1_bss_3C30 *p_lbl_1_bss_3C30;
    u8 v0;
    s32 v1;
    s32 v2;
    u32 v3;
    u32 v4;
    s32 v7;
    u32 v6;
    u32 v5;
    Fn183D28Vec3 *v8;
    u32 v9;
    f32 v10;
    u32 v11;
    u32 v12;
    f32 v13;
    s32 v14;
    s32 v15;
    f32 v16;
    u32 v17;
    u32 v18;
    u32 v19;
    int v20;
    FontDrawPacket loc_20;
    Sig_fn_8006F78C_Fn8006F78CData loc_14;
    Sig_fn_8006F78C_Fn8006F78CData loc_8;
    Fn183D28Vec3 *point;
    f32 phase;
    f32 t0;
    int t5;
    t0 = lbl_8006D21C((s32)(f32)(lbl_1_rodata_606C * (f32)(lbl_1_rodata_5CB0 * arg0)));
    loc_20 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_20.image = (0x10000 - 27611);
    fn_1_51564(0, 0, 16, 14, 2, 5);
    p_lbl_1_bss_3C30 = &lbl_1_bss_3C30;
    v0 = p_lbl_1_bss_3C30->unk_1405;
    v5 = 0;
    for (v1 = 0; v1 < 5; v1++) {
        if (v0 & (1 << v1)) v5++;
    }
    if ((s32)v5 == 0) {
        lbl_1_bss_7ACD0.unk_0 = 0;
    } else {
        if (lbl_1_bss_7ACD0.unk_0 < 60) {
            lbl_1_bss_7ACD0.unk_0++;
        }
    }
    v7 = 0;
    v8 = (Fn183D28Vec3 *)&lbl_1_bss_3C30;
    do {
        if ((p_lbl_1_bss_3C30->unk_1405 & (1 << v7)) != 0) {
            loc_20 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
            v9 = lbl_801A66A0 >> 5;
            v12 = v7 + (v5 - v9 % v5);
            loc_20.image = 0x9425;
            v16 = lbl_1_rodata_5CFC - (f32)lbl_1_bss_7ACD0.unk_0 / lbl_1_rodata_5E10;
            loc_20.color_add[0] = 255.0f * v16;
            loc_20.color_add[1] = 255.0f * v16;
            loc_20.color_add[2] = 255.0f * v16;
            loc_20.color_add[3] = 0;
            loc_20.z = (lbl_1_rodata_26F8.z - lbl_1_rodata_5F50) + (f32)(lbl_1_rodata_5DC8 * (f32)(s32)(v12 % v5));
            fn_8006F78C((Fn183D28Vec3 *)((u8 *)&lbl_1_bss_3C30 + v7 * 12 + 5128), &loc_14, t0);
            v16 = (f32)(arg1 + loc_14.value0);
            loc_20.flags = 10;
            loc_20.x = v16;
            loc_20.y = (f32)(arg2 + loc_14.value1);
            if (v7 == 4) {
                fn_1_5158C(&loc_20, loc_20.image, 1, 4);
            } else {
                v17 = ((u32)v7 >> 31);
                fn_1_5158C(&loc_20, loc_20.image, (s16)(v7 % 2), (s16)(v7 / 2));
            }
            t5 = fn_1_4F734(&loc_20);
        }
        v7++;
        v8 = (Fn183D28Vec3 *)v8 + 1;
    } while ((s32)v7 < 5);
    v18 = 0;
    v19 = 0;
    v20 = t5;
    while (v18 < fn_1_EB0B0()) {
        point = fn_1_EB0D8(v18);
        if (point) {
            phase = (f32)((lbl_801A66A0 - ((v18 * 60U) >> 1)) % ((fn_1_EB0B0() * 60U) >> 1));
            phase /= (f32)((fn_1_EB0B0() * 60U) >> 1);
            phase = phase * lbl_1_rodata_6070;
            fn_1_51564(0, 0, 8, 14, 4, 5);
            loc_20 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
            loc_20.image = (0x10000 - 27611);
            fn_1_5158C(&loc_20, loc_20.image, 2, 2);
            loc_20.z = lbl_1_rodata_26F8.z - phase;
            fn_8006F78C(point, &loc_8, t0);
            loc_20.x = (arg1 + loc_8.value0) - lbl_1_rodata_5DCC;
            loc_20.y = arg2 + loc_8.value1;
            loc_20.flags = 10;
            fn_1_4F734(&loc_20);
            loc_20 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
            v11 = v18 + 3;
            loc_20.image = (0x10000 - 27611);
            v14 = v11 & 3;
            v15 = (v11 >> 2) + 2;
            fn_1_5158C(&loc_20, loc_20.image, v14, (s16)v15);
            loc_20.z = lbl_1_rodata_26F8.z - phase;
            fn_8006F78C(point, &loc_8, t0);
            loc_20.x = lbl_1_rodata_5DCC + (arg1 + loc_8.value0);
            loc_20.y = arg2 + loc_8.value1;
            loc_20.flags = 10;
            fn_1_4F734(&loc_20);
        }
        v19 += 60;
        v18++;
    }
}
/* fzgx:end fn_1_D07E0 */

/* fzgx:begin fn_1_D0D68 */
void fn_1_D0D68(void) {
    fn_1_C8DC0();
}
/* fzgx:end fn_1_D0D68 */

/* fzgx:begin fn_1_D0D88 */
u32 fn_1_D0D88(void) {
    return lbl_1_data_3D648.unk_0;
}
/* fzgx:end fn_1_D0D88 */

/* fzgx:begin fn_1_D0D98 */
u16* fn_1_D0D98(void) {
    return &lbl_1_data_3D648.unk_4;
}
/* fzgx:end fn_1_D0D98 */

/* fzgx:begin fn_1_D0DA8 */
// Return the address of the object's 16-bit field at offset 0x6.
u8* fn_1_D0DA8(void) {
    return (u8*)&lbl_1_data_3D648.unk_6;
}
/* fzgx:end fn_1_D0DA8 */

/* fzgx:begin fn_1_D0DB8 */
// Returns the byte address of the object's field at offset 0x8.
u8* fn_1_D0DB8(void) {
    return (u8*)&lbl_1_data_3D648.unk_8;
}
/* fzgx:end fn_1_D0DB8 */

/* fzgx:begin fn_1_D0DC8 */
u8* fn_1_D0DC8(void) {
    return (u8*)&lbl_1_data_3D648 + 0xc;
}
/* fzgx:end fn_1_D0DC8 */

/* fzgx:begin fn_1_D0DD8 */
// Return the address of the enemy-control value at offset 0x10.
u8* fn_1_D0DD8(void) {
    return (u8*)&lbl_1_data_3D648.unk_10;
}
/* fzgx:end fn_1_D0DD8 */

/* fzgx:begin fn_1_D0DE8 */
// Return the address of the object's field at offset 0x12.
u8* fn_1_D0DE8(void) {
    return (u8*)&lbl_1_data_3D648.unk_12;
}
/* fzgx:end fn_1_D0DE8 */

/* fzgx:begin fn_1_D0DF8 */
// Return the enemy-control field at offset 0x14.
u16* fn_1_D0DF8(void) {
    return &lbl_1_data_3D648.unk_14;
}
/* fzgx:end fn_1_D0DF8 */

/* fzgx:begin fn_1_D0E08 */
// Return the address of the enemy-control field at offset 0x16.
u8* fn_1_D0E08(void) {
    return (u8*)&lbl_1_data_3D648.unk_16;
}
/* fzgx:end fn_1_D0E08 */

/* fzgx:begin fn_1_D0E18 */
// Return the address of the enemy-control field at offset 0x18.
u16* fn_1_D0E18(void) {
    return &lbl_1_data_3D648.unk_18;
}
/* fzgx:end fn_1_D0E18 */

/* fzgx:begin fn_1_D0E28 */
// Return the enemy-control data block.
Obj_1_data_3D648* fn_1_D0E28(void) {
    return &lbl_1_data_3D648;
}
/* fzgx:end fn_1_D0E28 */

/* fzgx:begin fn_1_D0E34 */
// Returns the status-byte array beginning at the shared enemy data block.
u8* fn_1_D0E34(void) {
    return &lbl_1_data_3D648.unk_20;
}
/* fzgx:end fn_1_D0E34 */

/* fzgx:begin fn_1_D0E44 */
// Return the address of the enemy controller's status byte.
u8* fn_1_D0E44(void) {
    return &lbl_1_data_3D648.unk_21;
}
/* fzgx:end fn_1_D0E44 */

/* fzgx:begin fn_1_D0E54 */
// Returns the address of this object's byte flag.
u8* fn_1_D0E54(void) {
    return &lbl_1_data_3D648.unk_22;
}
/* fzgx:end fn_1_D0E54 */

/* fzgx:begin fn_1_D0E64 */
// Returns the address of the enemy-control byte at offset 0x23.
u8* fn_1_D0E64(void) {
    return &lbl_1_data_3D648.unk_23;
}
/* fzgx:end fn_1_D0E64 */

/* fzgx:begin fn_1_D0E74 */
struct fn_1_D0E74_lbl_1_data_3D648 {
    u8 pad_0[0x4];
    u16 unk_4;
    u16 unk_6;
    u16 unk_8;
    u8 pad_A[0x16];
    u8 unk_20;
    u8 unk_21;
    u8 unk_22;
    u8 unk_23;
};




void fn_1_D0E74(void) {
    fn_80034200((u32)(2U));
    fn_8003432C((u32)((u32) (*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_4), (u32)((u32) (*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_6), (struct Sig_fn_8003432C_fn_8003432C_Arg2 *)((struct Sig_fn_8003432C_fn_8003432C_Arg2 *) ((u8 *)((u8 *)(&(*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648)) + 28))));
    (*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_20 = (u8) ((u32) (*(u32 *)((u8 *)(&(*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648)) + 28)) >> 0x18U);
    (*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_21 = (u8) ((u32) (*(u32 *)((u8 *)(&(*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648)) + 28)) >> 0x10U);
    (*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_22 = (u8) ((u32) (*(u32 *)((u8 *)(&(*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648)) + 28)) >> 8U);
    (*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_23 = (u8) (*(u32 *)((u8 *)(&(*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648)) + 28));
    GXPeekZ((u32)((u32) (*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_4), (u32)((u32) (*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_6), (struct Sig_GXPeekZ_GXPeekZ_Arg2 *)((struct Sig_GXPeekZ_GXPeekZ_Arg2 *) ((u8 *)((u8 *)(&(*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648)) + 12))));
    (*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_8 = (u16) (s32) (((*(f32 *)((u8 *)(&lbl_1_rodata_6078) + 0)) * (f32) (*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_6) / (f32) fn_1_A5DB0());
}
/* fzgx:end fn_1_D0E74 */

/* fzgx:begin fn_1_D19B8 */
#pragma opt_pointer_analysis off
void fn_1_D19B8(u8 *arg0) {
    u8 *p_lbl_1_data_3D670;
    u32 *p_lbl_1_data_20D1C;
    s32 v2;
    u32 v1;
    u8 v3;
    s8 v6;
    s32 i;
    char loc_88[0x80];
    char loc_8[0x80];

    p_lbl_1_data_3D670 = (u8 *)&(*(u8 (*)[])&lbl_1_data_3D670);
    fn_80006E10((u32)(p_lbl_1_data_3D670 + 0x2bc));

    fn_1_465D0((char *)(p_lbl_1_data_3D670 + 0x470), 3);
    fn_1_465D0((char *)(p_lbl_1_data_3D670 + 0x480), 3);
    i = 0;
    while (i < (s8)fn_1_86624()) {
        v1 = ((*(u32 (*)[0x2d])&lbl_1_data_20D1C))[(s16)fn_1_12C930((s8)fn_1_12C7B8((s8)fn_1_86690((s8)i)))];
        fn_1_868C0((s8)i);
        v2 = 31 - __cntlzw((s8)*arg0);
        v3 = (u8)v2;
        v3 %= 4;
        if (v3 != 0 && v3 != 4) {
            sprintf(loc_88, (const char *)(p_lbl_1_data_3D670 + 0x2c4), v1, v3);
            fn_1_465D0(loc_88, 1);
        }
        i++;
        arg0++;
    }

    if ((*(s16 *)&lbl_1_bss_960) == 9) {
        v6 = (s8)lbl_1_bss_9C;
        switch (v6) {
        case 3:
            sprintf(loc_8, (const char *)(p_lbl_1_data_3D670 + 0x3d0));
            fn_1_465D0(loc_8, 1);
            sprintf(loc_8, (const char *)(p_lbl_1_data_3D670 + 0x318));
            fn_1_465D0(loc_8, 1);
            break;
        case 5:
            sprintf(loc_8, (const char *)(p_lbl_1_data_3D670 + 0x3e4));
            fn_1_465D0(loc_8, 1);
            sprintf(loc_8, (const char *)(p_lbl_1_data_3D670 + 0x32c));
            fn_1_465D0(loc_8, 1);
            break;
        case 4:
            sprintf(loc_8, (const char *)(p_lbl_1_data_3D670 + 0x3f8));
            fn_1_465D0(loc_8, 1);
            sprintf(loc_8, (const char *)(p_lbl_1_data_3D670 + 0x340));
            fn_1_465D0(loc_8, 1);
            sprintf(loc_8, (const char *)(((0x410) + (p_lbl_1_data_3D670))));
            fn_1_465D0(loc_8, 1);
            sprintf(loc_8, (const char *)(p_lbl_1_data_3D670 + 0x358));
            fn_1_465D0(loc_8, 1);
            sprintf(loc_8, (const char *)(p_lbl_1_data_3D670 + 0x428));
            fn_1_465D0(loc_8, 1);
            sprintf(loc_8, (const char *)(p_lbl_1_data_3D670 + 0x370));
            fn_1_465D0(loc_8, 1);
            sprintf(loc_8, (const char *)(p_lbl_1_data_3D670 + 0x440));
            fn_1_465D0(loc_8, 1);
            sprintf(loc_8, (const char *)(p_lbl_1_data_3D670 + 0x388));
            fn_1_465D0(loc_8, 1);
            sprintf(loc_8, (const char *)(p_lbl_1_data_3D670 + 0x458));
            fn_1_465D0(loc_8, 1);
            sprintf(loc_8, (const char *)(p_lbl_1_data_3D670 + 0x3a0));
            fn_1_465D0(loc_8, 1);
            break;
        }
    }

    fn_80006E10((u32)(p_lbl_1_data_3D670 + 0x3b8));
}
#pragma opt_pointer_analysis reset
/* fzgx:end fn_1_D19B8 */

/* fzgx:begin fn_1_D2F50 */
// Stores the initialized enemy-control handle for later subsystem updates.
void fn_1_D2F50(void) {

    lbl_1_data_3D928.unk_0 = fn_80008E84(lbl_1_data_3D924);
}
/* fzgx:end fn_1_D2F50 */

/* fzgx:begin fn_1_D2F84 */
void fn_1_D2F84(void) {
    fn_80008E84(lbl_1_data_3D928.unk_0);
}
/* fzgx:end fn_1_D2F84 */
