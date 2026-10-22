#include "types.h"
#include "rel/sel/globals.h"
#include "rel/sel/name_entry.h"
#include "dolphin/hw_regs.h"

typedef struct fn_10_25BC8_NameEntryState {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u8 _pad0c[0x0c];
    u32 unk18;
    u32 unk1c;
} fn_10_25BC8_NameEntryState;

typedef struct NameEntryPool {
    u8 pad_0[0x38];
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    f32 unk_54;
    f32 unk_58;
    f32 unk_5C;
    f32 unk_60;
    f32 unk_64;
    f32 unk_68;
    f32 unk_6C;
    u8 pad_70[0x38];
    u32 unk_A8;
    f32 unk_AC;
    f32 unk_B0;
    f32 unk_B4;
} NameEntryPool;

typedef struct {
    s16 v[14];
} fn_10_25E1C_SndTable;

typedef struct {
    s16 v[14];
} fn_10_260D4_SndTable;

typedef struct { u8 r, g, b, a; } Sig_fn_800081C8_Color;

typedef Sig_fn_800081C8_Color Color;

typedef struct CameraDesc {
    u32 mode;
    f32 x;
    f32 y;
    f32 z;
    u32 pad_10[8];
    u32 unk_30;
    u32 pad_34[9];
} CameraDesc;
extern u32 lbl_801A66B4;
extern u32 fn_800081C8(Color arg0, Color arg1, f32 arg2);
extern void fn_1_49410(void);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_4954C(f32 value);
extern void fn_1_495C8(u8 value);
extern void fn_1_495B0(u32 value);
extern void fn_1_49590(f32 value);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_4D494(void);
extern void fn_1_49514(u32 *value);
extern void fn_1_4AE0C(const char* format, ...);
extern u32 fn_1_4D4C8(Color, f32, f32);
extern void fn_1_49528(Color);
extern void fzgx_pool_use(void *);
extern u8 fn_1_B7C00(void);
extern u8 fn_10_26434(void);
extern void fn_10_26554(void);
extern void fn_1_14BD94(void *);
extern void fn_10_26424(void);
extern u16 lbl_1_bss_9F8[5];
extern u8 lbl_1_bss_8B3A0[0x9f];
extern void fn_1_A2D84(u32 arg0);
extern void fn_1_14BCBC(u32 arg0, u32 arg1);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern NameEntryPool lbl_10_rodata_1D70;
extern fn_10_260D4_SndTable lbl_10_rodata_1D8C;
extern void fn_1_48140(int index);
extern CameraDesc lbl_1_rodata_26F8;
extern void fn_10_261E4(s32 arg0, u8 arg1);
extern u32 fn_1_4AEC0(u32 value);
extern u32 fn_800371F8(u32, void *);
extern void fn_1_4966C(f32 value1, f32 value2);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4AEB4(f32 value);
extern void fn_1_4FD64();
extern void fn_1_50164();
extern void fn_8003462C(u32 arg0, u32 arg1, u32 arg2);
extern void fn_8007245C(u32 value);
extern void fn_80072864(u32 arg0);
extern void fn_800728A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80072AB0(s32 arg0, s32 arg1, s32 arg2);
extern void fn_80072C24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072CC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072D64(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_80072E20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80073678(u32 arg0);
extern void fn_80073C6C(s32 index);
extern void fn_80074660(u32 arg0);
extern void fn_80074788(u32 arg0);
extern void fn_800747D0(u32 arg0, u32 arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern u8 lbl_10_bss_55CDC;
extern s16 lbl_1_bss_960;
extern u32 lbl_801A6410;
extern u32 fn_1_435C(u32 value);
extern void fn_1_426C(u32 idx);
extern void fn_1_A8F78(void);
extern void fn_1_412A0(u32 index);
extern u8 lbl_1_bss_8E51D;
extern u8 lbl_1_data_2B0D4[];
extern u8 lbl_1_data_2B144[];
extern s16 fn_1_12EF24(s16 row, s16 column);
extern u32 fn_1_F89E4(u8 value);
extern void fn_1_14A1AC(u8 arg);
extern void fn_1_14BC40(void);
extern void fn_1_1554D0(void);
extern s32 fn_1_1555B0(s32 value);
extern void fn_1_47F74(s32 index);
extern void fn_1_15555C(void);
extern void fn_1_14BD74(void);

/* fzgx:begin fn_10_24BD0 noprologue */
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef signed long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[360] = {0x89709094, 0x00000000, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x824F8250, 0x82518252, 0x82538254, 0x82558256, 0x82578258, 0x81E781E8, 0x00000000, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x00000000, 0x8B4C8D86, 0x00000000, 0x81418142, 0x814C814D, 0x81458143, 0x81448146, 0x81478148, 0x8149817B, 0x817C815E, 0x81818183, 0x8184814F, 0x81518160, 0x81628175, 0x81768169, 0x816A816F, 0x8170816D, 0x816E818F, 0x81908193, 0x81948195, 0x81968197, 0x81E781E8, 0x00000000, 0x82D082E7, 0x82AA82C8, 0x00000000, 0x82A082A2, 0x82A482A6, 0x82A882A9, 0x82AB82AD, 0x82AF82B1, 0x82B382B5, 0x82B782B9, 0x82BB82BD, 0x82BF82C2, 0x82C482C6, 0x82C882C9, 0x82CA82CB, 0x82CC82CD, 0x82D082D3, 0x82D682D9, 0x82DC82DD, 0x82DE82DF, 0x82E082E2, 0x82E482E6, 0x82E782E8, 0x82E982EA, 0x82EB82ED, 0x82EE82EF, 0x82F082F1, 0x82AA82AC, 0x82AE82B0, 0x82B282B4, 0x82B682B8, 0x82BA82BC, 0x82BE82C0, 0x82C382C5, 0x82C782CE, 0x82D182D4, 0x82D782DA, 0x82CF82D2, 0x82D582D8, 0x82DB829F, 0x82A182A3, 0x82A582A7, 0x82C182E1, 0x82E382E5, 0x82EC81E7, 0x81E80000, 0x829F82A1, 0x82A382A5, 0x82A782AA, 0x82AC82AE, 0x82B082B2, 0x82B482B6, 0x82B882BA, 0x82BC82BE, 0x82C082C1, 0x82C582C7, 0x81408140, 0x81408140, 0x814082CE, 0x82D182D4, 0x82D782DA, 0x81408140, 0x81408140, 0x814082E1, 0x82E382E5, 0x81408140, 0x81408140, 0x814082EC, 0x81408140, 0x81408140, 0x82A982AB, 0x82AD82AF, 0x82B182B3, 0x82B582B7, 0x82B982BB, 0x82BD82BF, 0x82C282C4, 0x82C682CF, 0x82D282D5, 0x82D882DB, 0x82CD82D0, 0x82D382D6, 0x82D982A0, 0x82A282A4, 0x82A682A8, 0x82C282E2, 0x82E482E6, 0x82ED8140, 0x81400000, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x814082C3, 0x81408140, 0x81408140, 0x81408140, 0x814082CF, 0x82D282D5, 0x82D882DB, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x82C18140, 0x814082CD, 0x82D082D3, 0x82D682D9, 0x82CE82D1, 0x82D482D7, 0x82DA8140, 0x81408140, 0x81408140, 0x82C38140, 0x81408140, 0x81408140, 0x81400000, 0x834A835E, 0x834A8369, 0x00000000, 0x83418343, 0x83458347, 0x8349834A, 0x834C834E, 0x83508352, 0x83548356, 0x8358835A, 0x835C835E, 0x83608363, 0x83658367, 0x8369836A, 0x836B836C, 0x836D836E, 0x83718374, 0x82D6837A, 0x837D837E, 0x83808381, 0x83828384, 0x83868388, 0x8389838A, 0x838B838C, 0x838D838F, 0x83908391, 0x83928393, 0x8394834B, 0x834D834F, 0x83518353, 0x83558357, 0x8359835B, 0x835D835F, 0x83618364, 0x83668368, 0x836F8372, 0x837582D7, 0x837B8370, 0x83738376, 0x82D8837C, 0x83408342, 0x83448346, 0x83488395, 0x83968362, 0x83838385, 0x8387838E, 0x81E781E8, 0x00000000, 0x83408342, 0x83448346, 0x8348834B, 0x834D834F, 0x83518353, 0x83558357, 0x8359835B, 0x835D835F, 0x83618362, 0x83668368, 0x81408140, 0x81408140, 0x8140836F, 0x83728375, 0x82D7837B, 0x81408140, 0x81408140, 0x81408383, 0x83858387, 0x81408140, 0x81408140, 0x8140838E, 0x81408140, 0x81408140, 0x8345834A, 0x834C834E, 0x83508352, 0x83548356, 0x8358835A, 0x835C835E, 0x83608363, 0x83658367, 0x83708373, 0x837682D8, 0x837C836E, 0x83718374, 0x82D6837A, 0x83418343, 0x83458347, 0x8349834A, 0x83508363, 0x83848386, 0x8388838F, 0x81408140, 0x00000000, 0x81408140, 0x83948140, 0x81408395, 0x81408140, 0x83968140, 0x81408140, 0x81408140, 0x81408140, 0x81408364, 0x81408140, 0x81408140, 0x81408140, 0x81408370, 0x83738376, 0x82D8837C, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x83448395, 0x81408140, 0x83968140, 0x81408140, 0x81408140, 0x81408140, 0x81408362, 0x81408140, 0x836E8371, 0x837482D6, 0x837A836F, 0x83728375, 0x82D7837B, 0x81408140, 0x83948140, 0x8140834B, 0x83518364, 0x81408140, 0x81408140, 0x81408140, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 225.43910217285156f;
}
static const u32 fzgx_pool_table3[65] = {0x74616C20, 0x4C657474, 0x65727300, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x81E781E8, 0x00000000, 0x536D616C, 0x6C204C65, 0x74746572, 0x73000000, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x81E781E8, 0x00000000, 0x5369676E, 0x73000000, 0x81438144, 0x81488149, 0x817B817C, 0x815E815F, 0x81818183, 0x81848146, 0x8147814C, 0x814D814F, 0x81518162, 0x8169816A, 0x816D816E, 0x816F8170, 0x81908193, 0x81948195, 0x81968197, 0x81E781E8, 0x00000000, 0x4E756D62, 0x65727300, 0x824F8250, 0x82518252, 0x82538254, 0x82558256, 0x82578258, 0x81E781E8, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.21;
    d = 1.6666666666666667;
    d = 0.5;
    s = 48.0f;
    s = 0.25f;
    d = 1.0;
    s = 0.12999999523162842f;
}
static const u32 fzgx_pool_table5[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.5;
    d = 2.0;
    s = 1.6666666269302368f;
    s = 0.0625f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 32.0f;
    s = 24.0f;
    s = 18.0f;
}
static const u32 fzgx_pool_table7[6] = {0xFFFFFF00, 0x00FFFF00, 0x00FFFF00, 0x00FFFF00, 0x000000FF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 12.0f;
    s = 0.0f;
}
static const u32 fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    d = 12.0;
    s = 10.100000381469727f;
}
static const u32 fzgx_pool_table11[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 24.0;
    s = 1.0f;
    s = 10.0f;
}
static const u32 fzgx_pool_table13[2] = {0x00FFFF00, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.649999976158142f;
}
static const u32 fzgx_pool_table15[1] = {0x33333333};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const u32 *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table17[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const u32 *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table19[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const u32 *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table20[1] = {0x00FFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table21[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const u32 *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 6.0;
    d = 20.0;
    s = 167.0f;
    s = 38.0f;
    s = 0.5f;
    s = 68.0f;
    s = 10.199999809265137f;
    s = 320.0f;
    s = 140.0f;
    s = 98.0f;
    s = 0.1899999976158142f;
    s = 178.0f;
    s = 0.18000000715255737f;
    s = 0.17000000178813934f;
    s = 352.0f;
    s = 0.1599999964237213f;
    s = 0.15000000596046448f;
    s = 0.14000000059604645f;
    s = 110.0f;
    s = 250.0f;
    s = 180.0f;
    s = 390.0f;
    s = 378.0f;
}
static const u32 fzgx_pool_table23[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const u32 *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.1;
    d = 0.25;
    s = 346.0f;
    s = 0.11999999731779099f;
    s = 397.0f;
    s = 321.0f;
    d = 2.1666666666666665;
    s = 118.0f;
    s = 0.625f;
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table25[1] = {0x00FFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const u32 *volatile cp; cp = fzgx_pool_table25; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef int BOOL;
typedef unsigned long size_t;
typedef struct FontDrawPacket FontDrawPacket;
typedef struct FontVertex {
f32 x, y, z;
} FontVertex;
struct FontDrawPacket {
u32 image;
f32 x, y, z;
f32 scale_x, scale_y;
f32 u0, v0, u1, v1;
s16 rotation_z, rotation_y;
f32 alpha;
u32 flags;
f32 depth;
u8 color[4], color_add[4];
u32 format;
u16 width, height;
void* pixels;
FontDrawPacket* secondary;
void (*vertex_callback)(FontDrawPacket* packet, FontVertex* vertices);
u32 unk_54;
};
void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height,
s16 texture_width, s16 texture_height);
/* Generated by `fzgx headers --module option`: layouts recovered from every access in the */
/* module's disassembly (matched or not). Field names are offsets until the librarian names them; */
/* offsets and widths are facts, names are not. Regenerate rather than hand-edit padding. */
/* lbl_4_bss_0: .bss size 0x2, referenced by 39 functions, shape {'object': 762} */
extern u16 lbl_4_bss_0;
/* lbl_4_data_0: .data size 0xC, referenced by 17 functions, shape {'object': 49} */
extern u8 lbl_4_data_0[0xC];
/* lbl_4_bss_8: .bss size 0x4, referenced by 14 functions, shape {'object': 14} */
extern u32 lbl_4_bss_8;
/* lbl_4_bss_5680: .bss size 0x4, referenced by 8 functions, shape {'object': 112, 'pointer': 28} */
typedef struct {
u32 unk_0; /* 11 loads, 6 stores */
u32 unk_4; /* 1 loads, 1 stores */
u32 unk_8; /* 4 loads, 1 stores */
u8 unk_C; /* 8 loads, 1 stores */
u8 unk_D; /* 5 loads, 4 stores */
u8 unk_E; /* 10 loads, 3 stores */
u8 unk_F; /* 3 loads, 12 stores */
u8 unk_10; /* 1 loads, 0 stores */
u8 unk_11; /* 2 loads, 1 stores */
u16 unk_12; /* 3 loads, 3 stores */
u8 unk_14; /* 2 loads, 2 stores */
u8 unk_15; /* 2 loads, 2 stores */
u8 unk_16; /* 2 loads, 2 stores */
u8 unk_17; /* 2 loads, 2 stores */
u32 unk_18; /* 1 loads, 1 stores */
u32 unk_1C; /* 1 loads, 1 stores */
u32 unk_20; /* 3 loads, 2 stores */
u8 pad_24[0x4];
u8 unk_28; /* 1 loads, 0 stores */
u8 pad_29[0xD];
u8 unk_36; /* 2 loads, 1 stores */
u8 unk_37; /* 0 loads, 1 stores */
u8 pad_38[0x2];
u8 unk_3A; /* 2 loads, 2 stores */
u8 unk_3B; /* 5 loads, 2 stores */
u32 unk_3C; /* 4 loads, 2 stores */
} Obj_4_bss_5680_Target;
extern Obj_4_bss_5680_Target *lbl_10_bss_55CD8;
/* lbl_4_bss_5630: .bss size 0x48, referenced by 6 functions, shape {'object': 5} */
typedef struct {
u32 unk_0; /* 0 loads, 3 stores */
u8 unk_4; /* 0 loads, 1 stores */
u8 pad_5[0x1D];
u8 unk_22; /* 1 loads, 0 stores */
u8 pad_23[0x25];
} Obj_4_bss_5630;
extern Obj_4_bss_5630 lbl_4_bss_5630;
/* lbl_4_bss_2: .bss size 0x1, referenced by 5 functions, shape {'object': 10} */
extern u8 lbl_4_bss_2;
/* lbl_4_data_2F78: .data size 0xA0, referenced by 5 functions, shape {} */
extern u8 lbl_4_data_2F78[0xA0];
/* lbl_4_data_2F1C: .data size 0x4, referenced by 4 functions, shape {'object': 4} */
extern u32 lbl_4_data_2F1C;
/* lbl_4_bss_5684: .bss size 0x1, referenced by 3 functions, shape {'object': 3} */
extern u8 lbl_4_bss_5684;
/* lbl_4_bss_4: .bss size 0x4, referenced by 2 functions, shape {'object': 2} */
extern u32 lbl_4_bss_4;
/* lbl_4_bss_10: .bss size 0xB4, referenced by 2 functions, shape {'object': 8} */
typedef struct {
u16 unk_0; /* 4 loads, 4 stores */
u8 pad_2[0xB2];
} Obj_4_bss_10;
extern Obj_4_bss_10 lbl_4_bss_10;
/* lbl_4_bss_C4: .bss size 0x5554, referenced by 2 functions, shape {'object': 16} */
typedef struct {
u8 pad_0[0x2];
u16 unk_2; /* 1 loads, 1 stores */
u16 unk_4; /* 1 loads, 1 stores */
u16 unk_6; /* 1 loads, 1 stores */
u32 unk_8; /* 1 loads, 1 stores */
u32 unk_C; /* 1 loads, 1 stores */
u32 unk_10; /* 1 loads, 1 stores */
u32 unk_14; /* 1 loads, 1 stores */
u32 unk_18; /* 1 loads, 1 stores */
u8 pad_1C[0x5538];
} Obj_4_bss_C4;
extern Obj_4_bss_C4 lbl_4_bss_C4;
/* lbl_4_data_2F00: .data size 0x1C, referenced by 2 functions, shape {'object': 6} */
typedef struct {
u8 pad_0[0x18];
u32 unk_18; /* 3 loads, 1 stores */
} Obj_4_data_2F00;
extern Obj_4_data_2F00 lbl_4_data_2F00;
/* lbl_4_bss_5685: .bss size 0x1, referenced by 2 functions, shape {'object': 6} */
extern u8 lbl_4_bss_5685;
struct fn_4_C768_Copy88 { u32 a[22]; };
struct fn_4_C768_Ro410 {
u8 pad_0[0x6B8];
f64 unk_6B8;
u8 pad_6C0[0x8];
f64 unk_6C8;
f32 unk_6D0;
u8 pad_6D4[0x1C];
f64 unk_6F0;
f64 unk_6F8;
u8 pad_700[0x28];
f32 unk_728;
u8 pad_72C[0xC];
f64 unk_738;
u8 pad_740[0x10];
f32 unk_750;
u8 pad_754[0x14];
u32 unk_768;
u32 unk_76C;
u32 unk_770;
u32 unk_774;
u32 unk_778;
u8 pad_77C[0x4];
f64 unk_780;
f64 unk_788;
f32 unk_790;
f32 unk_794;
f32 unk_798;
f32 unk_79C;
f32 unk_7A0;
f32 unk_7A4;
f32 unk_7A8;
f32 unk_7AC;
f32 unk_7B0;
f32 unk_7B4;
f32 unk_7B8;
f32 unk_7BC;
f32 unk_7C0;
f32 unk_7C4;
f32 unk_7C8;
f32 unk_7CC;
f32 unk_7D0;
f32 unk_7D4;
f32 unk_7D8;
f32 unk_7DC;
f32 unk_7E0;
u8 pad_7E4[0x4];
f64 unk_7E8;
f64 unk_7F0;
f32 unk_7F8;
f32 unk_7FC;
f32 unk_800;
f32 unk_804;
f64 unk_808;
f32 unk_810;
f32 unk_814;
f32 unk_818;
};
struct fn_4_C768_lbl_1_data_418D4 {
u32 unk_0[1];
};
struct fn_4_C768_Clr { u32 w; };
extern s16 lbl_1_bss_960;
extern s32 lbl_801A66B4;
extern struct fn_4_C768_lbl_1_data_418D4 lbl_1_data_418D4;
extern u8 lbl_1_rodata_26F8[];
extern u32 lbl_10_data_69C0;
extern u32 lbl_10_data_69D8;
extern u32 lbl_801A66A0;
extern u32 fn_1_49410(void);
extern u32 fn_1_134AD4(void);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_1380F0(void *);
extern u32 fn_1_13ABA8(u32);
extern f32 lbl_8006D188(s16);
extern void * memset(void *, int, u32);
extern char * strncpy(char *, const char *, size_t);
extern void fn_1_494DC(s16);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_49514(u32 *);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_133DBC(void *);
static inline u32 * fn_10_24BD0_read_pointer(struct fn_4_C768_Copy88 owner) { return owner.a; }
static inline u32 * fn_10_24BD0_read_pointer_(struct fn_4_C768_Copy88 owner) { return owner.a; }
static inline u32 * fn_10_24BD0_read_pointer__(struct fn_4_C768_Copy88 * owner) { return owner->a; }
#pragma opt_propagation off
void fn_10_24BD0(void) {
    u32 * fzgx_live;
f32 temp_f0_5;
struct fn_4_C768_Copy88 loc_20;
u8 buf[3];
struct fn_4_C768_Clr clr_18;
struct fn_4_C768_Clr clr_14;
struct fn_4_C768_Clr clr_10;
struct fn_4_C768_Clr clr_C;
f32 var_f31;
f32 temp_f0;
f32 temp_f0_2;
f32 temp_f0_3;
f32 temp_f0_4;
u32 sp8;
u32 var_r28;
u32 var_r27;
u32 var_r27_2;
u32 var_r28_2;
u8 *var_r4;
u8 *base;
fn_1_49410();
{
u8 c = lbl_10_bss_55CD8->unk_3A;
u8 *base = (u8 *)(lbl_10_bss_55CD8->unk_3C + lbl_10_bss_55CD8->unk_D * 0x14);
if (c != 0) {
if (c > 9) {
var_f31 = (f32)((0.5) + (f64)(f32)(c - 0xA) / (6.0));
} else {
var_f31 = (f32)((0.5) + (f64)(f32)(0xA - c) / (20.0));
}
lbl_10_bss_55CD8->unk_3A = (*(u8 volatile *)&(lbl_10_bss_55CD8->unk_3A)) /* Retail reloads this field. */ - 1;
} else {
var_f31 = (1.0f);
}
fn_1_134AD4();
if (lbl_1_bss_960 != 3) {
loc_20 = *(struct fn_4_C768_Copy88 *)lbl_1_rodata_26F8;
fn_10_24BD0_read_pointer__(&loc_20)[0] = 0x8F0C;
*(f32 *)((u8 *)&loc_20 + 4) = (167.0f);
*(f32 *)((u8 *)&loc_20 + 8) = (38.0f);
*(f32 *)((u8 *)&loc_20 + 12) = (0.5f);
fn_10_24BD0_read_pointer__(&loc_20)[0xC] = 0xA;
fn_1_4F734((FontDrawPacket *)&loc_20);
}
if (((lbl_10_bss_55CD8->unk_0) >> 0x1FU) == 0) {
if (lbl_801A66B4 == 5) {
fn_1_1380F0(&lbl_10_data_69C0);
} else {
fn_1_1380F0(&lbl_10_data_69D8);
}
} else {
fn_1_1380F0((void *)((u32 *)&lbl_1_data_418D4)[lbl_801A66B4]);
}
fn_1_13ABA8(0x18000000U);
loc_20 = *(struct fn_4_C768_Copy88 *)lbl_1_rodata_26F8;
fn_10_24BD0_read_pointer__(&loc_20)[0] = 0x8F0A;
*(f32 *)((u8 *)&loc_20 + 4) = (0.0f);
*(f32 *)((u8 *)&loc_20 + 8) = (68.0f);
*(f32 *)((u8 *)&loc_20 + 12) = (10.1999998f);
fn_1_4F734((FontDrawPacket *)&loc_20);
*(f32 *)((u8 *)&loc_20 + 4) = (320.0f);
fn_10_24BD0_read_pointer__(&loc_20)[0xC] |= 0x80000;
fn_1_4F734((FontDrawPacket *)&loc_20);
loc_20 = *(struct fn_4_C768_Copy88 *)lbl_1_rodata_26F8;
fn_10_24BD0_read_pointer__(&loc_20)[0] = 0x8F08;
*(f32 *)((u8 *)&loc_20 + 4) = (140.0f);
*(f32 *)((u8 *)&loc_20 + 8) = (98.0f);
*(f32 *)((u8 *)&loc_20 + 12) = (0.189999998f);
fn_1_4F734((FontDrawPacket *)&loc_20);
*(f32 *)((u8 *)&loc_20 + 4) = (320.0f);
fn_10_24BD0_read_pointer__(&loc_20)[0xC] |= 0x80000;
fn_1_4F734((FontDrawPacket *)&loc_20);
loc_20 = *(struct fn_4_C768_Copy88 *)lbl_1_rodata_26F8;
fn_10_24BD0_read_pointer__(&loc_20)[0] = 0x8F05;
*(f32 *)((u8 *)&loc_20 + 4) = (320.0f);
*(f32 *)((u8 *)&loc_20 + 8) = (178.0f);
*(f32 *)((u8 *)&loc_20 + 12) = (0.180000007f);
fn_10_24BD0_read_pointer__(&loc_20)[0xC] = 0xA;
fn_1_4F734((FontDrawPacket *)&loc_20);
loc_20 = *(struct fn_4_C768_Copy88 *)lbl_1_rodata_26F8;
fn_10_24BD0_read_pointer__(&loc_20)[0] = 0x8F06;
*(f32 *)((u8 *)&loc_20 + 4) = (320.0f);
*(f32 *)((u8 *)&loc_20 + 8) = (178.0f);
*(f32 *)((u8 *)&loc_20 + 12) = (0.170000002f);
fn_10_24BD0_read_pointer__(&loc_20)[0xC] = 0xA;
fn_1_4F734((FontDrawPacket *)&loc_20);
loc_20 = *(struct fn_4_C768_Copy88 *)lbl_1_rodata_26F8;
fn_10_24BD0_read_pointer__(&loc_20)[0] = 0x8F0B;
var_r27 = 0;
var_r28 = 0x62;
*(f32 *)((u8 *)&loc_20 + 8) = (352.0f);
*(f32 *)((u8 *)&loc_20 + 12) = (0.159999996f);
do {
*(f32 *)((u8 *)&loc_20 + 4) = (f32)var_r28;
fn_1_4F734((FontDrawPacket *)&loc_20);
var_r27 += 1;
var_r28 += 0x38;
} while (var_r27 < 8);
loc_20 = *(struct fn_4_C768_Copy88 *)lbl_1_rodata_26F8;
fn_10_24BD0_read_pointer__(&loc_20)[0] = 0x8F07;
*(f32 *)((u8 *)&loc_20 + 4) = (320.0f);
*(f32 *)((u8 *)&loc_20 + 8) = (178.0f);
*(f32 *)((u8 *)&loc_20 + 12) = (0.150000006f);
fn_10_24BD0_read_pointer__(&loc_20)[0xC] = 0xA;
*(s16 *)((u8 *)&loc_20 + 40) = (s16)((lbl_10_bss_55CD8->unk_11 << 8) & 0xFF00);
if ((1.0) != var_f31) {
*(f32 *)((u8 *)&loc_20 + 20) = var_f31;
*(f32 *)((u8 *)&loc_20 + 16) = var_f31;
}
fn_1_4F734((FontDrawPacket *)&loc_20);
loc_20 = *(struct fn_4_C768_Copy88 *)lbl_1_rodata_26F8;
*(f32 *)((u8 *)&loc_20 + 4) = (320.0f);
*(f32 *)((u8 *)&loc_20 + 12) = (0.140000001f);
fn_10_24BD0_read_pointer__(&loc_20)[0xC] = 0xA;
fn_10_24BD0_read_pointer__(&loc_20)[0] = 0x8F0D;
*(f32 *)((u8 *)&loc_20 + 8) = (110.0f);
{
u8 v = lbl_10_bss_55CD8->unk_14;
u8 *cb = (u8 *)&clr_18;
clr_18.w = fzgx_pool_table16[0];
cb[0] = (u8)((v * 0x10) & 0xF0);
cb[1] = (u8)((v * 0x10) & 0xF0);
cb[2] = (u8)((v * 0x10) & 0xF0);
fn_10_24BD0_read_pointer__(&loc_20)[0xF] = clr_18.w;
temp_f0 = (f32)((1.0) + (f64)v / (12.0));
*(f32 *)((u8 *)&loc_20 + 20) = temp_f0;
*(f32 *)((u8 *)&loc_20 + 16) = temp_f0;
}
fn_1_4F734((FontDrawPacket *)&loc_20);
*(f32 *)((u8 *)&loc_20 + 8) = (250.0f);
fn_10_24BD0_read_pointer__(&loc_20)[0] = 0x8F02;
{
u8 v = (*(Obj_4_bss_5680_Target *volatile *)&lbl_10_bss_55CD8)->unk_15; /* Retail reloads the owner pointer here. */
u8 *cb = (u8 *)&clr_14;
clr_14.w = fzgx_pool_table17[0];
cb[0] = (u8)((v * 0x10) & 0xF0);
cb[1] = (u8)((v * 0x10) & 0xF0);
cb[2] = (u8)((v * 0x10) & 0xF0);
fzgx_live = fn_10_24BD0_read_pointer__(&loc_20);
fzgx_live[0xF] = clr_14.w;
temp_f0_2 = (f32)((1.0) + (f64)v / (12.0));
*(f32 *)((u8 *)&loc_20 + 20) = temp_f0_2;
*(f32 *)((u8 *)&loc_20 + 16) = temp_f0_2;
}
fn_1_4F734((FontDrawPacket *)&loc_20);
loc_20 = *(struct fn_4_C768_Copy88 *)lbl_1_rodata_26F8;
*(f32 *)((u8 *)&loc_20 + 8) = (180.0f);
*(f32 *)((u8 *)&loc_20 + 12) = (0.140000001f);
*(f32 *)((u8 *)&loc_20 + 4) = (250.0f);
fn_10_24BD0_read_pointer__(&loc_20)[0xC] = 0xA;
fn_10_24BD0_read_pointer__(&loc_20)[0] = 0x8F04;
{
u8 v = lbl_10_bss_55CD8->unk_16;
u8 *cb = (u8 *)&clr_10;
clr_10.w = fzgx_pool_table18[0];
cb[0] = (u8)((v * 0x10) & 0xF0);
cb[1] = (u8)((v * 0x10) & 0xF0);
cb[2] = (u8)((v * 0x10) & 0xF0);
fn_10_24BD0_read_pointer__(&loc_20)[0xF] = clr_10.w;
temp_f0_3 = (f32)((1.0) + (f64)v / (12.0));
*(f32 *)((u8 *)&loc_20 + 20) = temp_f0_3;
*(f32 *)((u8 *)&loc_20 + 16) = temp_f0_3;
}
fn_1_4F734((FontDrawPacket *)&loc_20);
*(f32 *)((u8 *)&loc_20 + 4) = (390.0f);
fn_10_24BD0_read_pointer__(&loc_20)[0xC] |= 0x80000;
{
u8 v = lbl_10_bss_55CD8->unk_17;
u8 *cb = (u8 *)&clr_C;
clr_C.w = fzgx_pool_table19[0];
cb[0] = (u8)((v & 0xF) << 4);
cb[1] = (u8)((v & 0xF) << 4);
cb[2] = (u8)((v & 0xF) << 4);
fn_10_24BD0_read_pointer__(&loc_20)[0xF] = clr_C.w;
temp_f0_4 = (f32)((1.0) + (f64)v / (12.0));
*(f32 *)((u8 *)&loc_20 + 20) = temp_f0_4;
*(f32 *)((u8 *)&loc_20 + 16) = temp_f0_4;
}
fn_1_4F734((FontDrawPacket *)&loc_20);
if (lbl_10_bss_55CD8->unk_E != 7 || lbl_10_bss_55CD8->unk_36 == 0) {
loc_20 = *(struct fn_4_C768_Copy88 *)lbl_1_rodata_26F8;
((FontDrawPacket *)&loc_20)->y = 378.0f;
((FontDrawPacket *)&loc_20)->image = 0x8F09;
((FontDrawPacket *)&loc_20)->z = 0.129999995f;
{
f64 t = (0.25) * lbl_8006D188((s16)((u8)lbl_801A66A0 << 8));
fn_10_24BD0_read_pointer__(&loc_20)[0xC] = 0xA;
temp_f0_5 = (f32)((1.1000000000000001) + t);
}
*(f32 *)((u8 *)&loc_20 + 20) = temp_f0_5;
*(f32 *)((u8 *)&loc_20 + 16) = temp_f0_5;
var_r27_2 = lbl_10_bss_55CD8->unk_E;
var_r28_2 = (var_r27_2 * 0x38) + 0x7C;
while (var_r27_2 < 8) {
*(f32 *)((u8 *)&loc_20 + 4) = (f32)var_r28_2;
fn_1_4F734((FontDrawPacket *)&loc_20);
var_r28_2 += 0x38;
var_r27_2 += 1;
}
}
if (((lbl_10_bss_55CD8->unk_0) >> 0x1FU) == 0) {
loc_20 = *(struct fn_4_C768_Copy88 *)lbl_1_rodata_26F8;
fn_10_24BD0_read_pointer__(&loc_20)[0] = 0x8F00;
*(f32 *)((u8 *)&loc_20 + 4) = (f32)((*(Obj_4_bss_5680_Target *volatile *)&lbl_10_bss_55CD8)->unk_12); /* Retail reloads the owner pointer here. */
*(f32 *)((u8 *)&loc_20 + 8) = (346.0f);
*(f32 *)((u8 *)&loc_20 + 12) = (0.119999997f);
fn_1_4F734((FontDrawPacket *)&loc_20);
fn_10_24BD0_read_pointer__(&loc_20)[0] = 0x8F01;
*(f32 *)((u8 *)&loc_20 + 8) = (397.0f);
fn_1_4F734((FontDrawPacket *)&loc_20);
}
memset(buf, 0, 3);
switch (lbl_10_bss_55CD8->unk_F) {
case 0:
default:
var_r4 = (u8 *)(*(u32 *)(base + 4) + *(u16 *)base * 2);
break;
case 1:
var_r4 = (u8 *)(*(u32 *)(base + 8) + *(u16 *)base * 2);
break;
case 2:
var_r4 = (u8 *)(*(u32 *)(base + 12) + *(u16 *)base * 2);
break;
}
strncpy((char *)buf, (const char *)var_r4, 2);
fn_1_49410();
fn_1_494DC(0x2A);
fn_1_495C8(9);
fn_1_496FC((321.0f), (178.0f));
{
f64 t = (2.1666666666666665) * (f64)var_f31;
fn_1_4955C((f32)t, (f32)t);
}
fn_1_4A0D8((const char *)buf);
loc_20 = *(struct fn_4_C768_Copy88 *)lbl_1_rodata_26F8;
fn_10_24BD0_read_pointer__(&loc_20)[0] = 0x8F03;
*(f32 *)((u8 *)&loc_20 + 4) = (118.0f);
*(f32 *)((u8 *)&loc_20 + 8) = (118.0f);
*(f32 *)((u8 *)&loc_20 + 12) = (0.189999998f);
fn_1_4F734((FontDrawPacket *)&loc_20);
fn_1_49410();
fn_1_494DC(0x2A);
fn_1_496FC((140.0f), (118.0f));
sp8 = fzgx_pool_table20[0];
fn_1_49514(&sp8);
if (lbl_801A66B4 == 5) {
fn_1_4955C((0.625f), (0.625f));
} else {
fn_1_4955C((0.5f), (0.5f));
fn_1_49590((0.300000012f));
fn_1_495B0(0x80000000U);
}
fn_1_4A0D8((const char *)(*(u32 *)(base + 16)));
fn_1_133DBC((void *)1);
}
}
#pragma opt_propagation reset
/* fzgx:end fn_10_24BD0 */

/* fzgx:begin fn_10_25BC8 */
void fn_10_25BC8(void) {
    lbl_10_bss_55CDC = 1;
    fn_1_435C(((fn_10_25BC8_NameEntryState *)lbl_10_bss_55CD8)->unk04);
    fn_1_426C(((fn_10_25BC8_NameEntryState *)lbl_10_bss_55CD8)->unk18);
    fn_1_A8F78();
    fn_1_48140(0x8f);

    if (lbl_1_bss_960 != 1) {
        if (lbl_1_bss_960 != 3) {
            fn_1_412A0(1);
            fn_1_48140(0x9a);
        }
        fn_1_48140(0x9e);
    }

    fn_1_435C(((fn_10_25BC8_NameEntryState *)lbl_10_bss_55CD8)->unk08);
    fn_1_426C(((fn_10_25BC8_NameEntryState *)lbl_10_bss_55CD8)->unk1c);
    fn_1_46B4(lbl_801A6410, (u32)((fn_10_25BC8_NameEntryState *)lbl_10_bss_55CD8), (const char *)(u8 *)(lbl_10_data_6980), 0x562);
    lbl_10_bss_55CD8 = 0;
}
/* fzgx:end fn_10_25BC8 */

/* fzgx:begin fn_10_25CB0 noprologue */
#include "types.h"
#include "rel/sel/globals.h"
#include "rel/sel/name_entry.h"

typedef struct { u8 b[4]; } W4;
extern u8 lbl_10_data_68E0[160];
extern W4 lbl_10_rodata_1D64;
extern s32 lbl_801A66B4;
extern u32 lbl_801A6410;
extern char *fn_80083DB0(char *, const char *);
extern u32 fn_1_435C(u32);
extern void *fn_1_45D0(u32, u32, void *, u32);
extern s32 fn_1_3F8C(void *, void *, void *, u32);
extern void fn_10_2325C();

void fn_10_25CB0(void) {
    struct { s32 value; } i;
    struct { u8 value; } idx;
    W4 loc_8;
    struct { s32 value; } off;
    u8 *q;
    u8 *e;
    u8 *d = (u8 *)&lbl_10_data_68E0;

    if (*(u8 *)((u8 *)lbl_10_bss_55CD8 + 0x28) == 0) {
        if (lbl_801A66B4 == 5) {
            fn_80083DB0((char *)((u8 *)lbl_10_bss_55CD8 + 0x28), (const char *)(d + 0x114));
        } else {
            fn_80083DB0((char *)((u8 *)lbl_10_bss_55CD8 + 0x28), (const char *)(d + 0x120));
        }
        loc_8 = lbl_10_rodata_1D64;
        fn_1_435C(lbl_10_bss_55CD8->unk_8);
        i.value = 0;
        idx.value = 0;
        off.value = 0;
        while (*(e = ((off.value) + ((0x28) + ((u8 *)lbl_10_bss_55CD8)))) != 0) {
            idx.value = (u8)i.value;
            q = (u8 *)fn_1_45D0(lbl_801A6410, 0x12, d + 0xa0, 0xd4);
            *(u16 *)(q + 8) = idx.value * 0x38 + 0x7e;
            *(u16 *)(q + 0xa) = 0x17a;
            q[0] = 2;
            q[1] = 0;
            *(u16 *)(q + 4) = *(u16 *)(q + 8);
            *(u16 *)(q + 6) = *(u16 *)(q + 0xa);
            q[2] = e[0];
            q[3] = e[1];
            *(W4 *)(q + 0xd) = loc_8;
            q[0xc] = idx.value;
            fn_1_3F8C(d + 0xc8, fn_10_2325C, q, 0xb);
            off.value += 2;
            i.value++;
        }
        lbl_10_bss_55CD8->unk_E = i.value;
    }
    lbl_10_bss_55CD8->unk_0 |= 0x10000000;
}
/* fzgx:end fn_10_25CB0 */

/* fzgx:begin fn_10_25E1C */
typedef struct {
    u8 pad[0x8c];
    s16 value;
} fn_10_25E1C_NameEntryState;



void fn_10_25E1C(void) {
    fn_10_25E1C_NameEntryState *state = &(*(fn_10_25E1C_NameEntryState *)&lbl_1_bss_8B3A0);
    s32 i;
    s16 result;

    for (i = 0; i < 6; i++) {
        result = fn_1_12EF24(state->value, i);
        if (state->value == 5) {
            if (i == 5) {
                if ((s32)fn_1_F89E4(0) == 0) {
                    goto set_neg; // shared tail: retail merges both -1 arms
                }
            }
            if (i != 5) {
                if ((s32)fn_1_F89E4((u8)(i + 1)) == 0) {
                    goto set_neg; // shared tail: retail merges both -1 arms
                }
            }
            goto after_neg; // skip the merged -1 arm
        set_neg:
            result = -1;
        after_neg: ;
        }
        if (result != -1) {
            break;
        }
    }

    if (result != -1) {
        lbl_10_bss_55CE0 = (u8)result;
    } else {
        lbl_10_bss_55CE0 = (u8)fn_1_12EF24(state->value, 0);
    }

    fn_1_14A1AC(lbl_1_bss_8E51D);
    fn_1_14BC40();
    fn_1_1554D0();
    fn_1_1555B0(lbl_10_bss_55CE0);
    fn_1_47F74(0x91);
    fn_1_47F74(0x97);
    fn_1_47F74(0x99);

    for (i = 0; i < 6; i++) {
        result = fn_1_12EF24(state->value, i);
        if (result != -1) {
            u8 key = lbl_1_data_2B0D4[result];
            fn_10_25E1C_SndTable table = (*((fn_10_25E1C_SndTable *)&lbl_10_rodata_1D70));
            s16 index = lbl_1_data_2B144[key] - 1;

            if ((((u32)index > 13) ? 0 : (index >= 0)) && table.v[index] != -1) {
                fn_1_47F74(table.v[index]);
            }
        }
    }
    lbl_10_bss_55CE1 = 0;
}
/* fzgx:end fn_10_25E1C */

/* fzgx:begin fn_10_26000 */
u8 fn_10_26000(void) {
    u8 result;
    u16 flags;

    if (fn_1_B7C00()) {
        return 0;
    }

    if (lbl_10_bss_55CE1 != 0) {
        result = fn_10_26434();
        if (result == 1) {
            fn_10_26554();
            fn_1_14BD94(&lbl_10_bss_55CE0);
        }
        if (result != 0) {
            lbl_10_bss_55CE1 = 0;
        }
        return result;
    }

    flags = lbl_1_bss_9F8[4];
    if (((flags >> 11) & 1) != 0) {
        // fzgx-allow: A1 target hardware address
        fn_1_A2D84( (u32)((void *)0xA9011100)); // fzgx-allow: A2 target hardware address
        fn_10_26424();
        lbl_10_bss_55CE1 = 1;
    }
    fn_1_14BCBC( (u32)(void *)(&lbl_10_bss_55CE0), lbl_1_bss_8B3A0[0x9e]);
    return 0;
}
/* fzgx:end fn_10_26000 */

/* fzgx:begin fn_10_260D4 */
typedef struct {
    u8 pad[0x8c];
    s16 value;
} fn_10_260D4_NameEntryState;




void fn_10_260D4(void) {
    fn_10_260D4_NameEntryState *state = &(*(fn_10_260D4_NameEntryState *)&lbl_1_bss_8B3A0);
    s32 i;

    for (i = 5; i >= 0; i--) {
        s16 result = fn_1_12EF24(state->value, i);
        if (result != -1) {
            u8 key = lbl_1_data_2B0D4[result];
            fn_10_260D4_SndTable table = lbl_10_rodata_1D8C;
            s16 index = lbl_1_data_2B144[key] - 1;

            if ((((u32)index > 13) ? 0 : (index >= 0)) && table.v[index] != -1) {
                fn_1_48140(table.v[index]);
            }
        }
    }
    fn_1_48140(0x99);
    fn_1_48140(0x97);
    fn_1_48140(0x91);
    fn_1_15555C();
    fn_1_14BD74();
}
/* fzgx:end fn_10_260D4 */

/* fzgx:begin fn_10_261E4 pool noprologue */
#include "types.h"
#include "dolphin/hw_regs.h"

typedef struct { u8 r, g, b, a; } Sig_fn_800081C8_Color;
typedef Sig_fn_800081C8_Color Color;

extern u32 lbl_801A66B4;

extern Color fn_800081C8(Color, Color, f32);
extern void fn_1_49410(void);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(u8);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4D494(void);
extern void fn_1_49514(Color);
extern void fn_1_4AE0C(const char *, ...);
extern u32 fn_1_4D4C8(Color, f32, f32);
extern void fn_1_49528(Color);

/*
 * Layout stand-in for the TU's .data block at lbl_10_data_6A48: the erase-dialog
 * strings and the per-language pointer tables (question, YES, NO). The pointer
 * tables are relocations in retail; here they are zero words so the private
 * section's bytes can be proven equal and bound to the retail objects at submit.
 */
#pragma explicit_zero_data on
static char sQuestionEn[32] = "OK to erase this course record?";
static char sQuestionGe[36] = "GER OK to erase this course record?";
static char sQuestionFr[36] = "FRE OK to erase this course record?";
static char sQuestionSp[36] = "SPA OK to erase this course record?";
static char sQuestionIt[36] = "ITA OK to erase this course record?";
static char sQuestionJp[52] =
    "\x82\xB1\x82\xCC\x83\x52\x81\x5B\x83\x58\x82\xCC\x83\x8C\x83\x52\x81\x5B\x83\x68\x82\xF0\x0A"
    "\x83\x4E\x83\x8A\x83\x41\x82\xB5\x82\xC4\x82\xE0\x82\xE6\x82\xEB\x82\xB5\x82\xA2\x82\xC5\x82\xB7\x82\xA9\x3F";
static char *sEraseQuestion[6] = {0};
static char sYesEn[4] = "YES";
static char sYesGe[8] = "GER YES";
static char sYesFr[8] = "FRE YES";
static char sYesSp[8] = "SPA YES";
static char sYesIt[8] = "ITA YES";
static char sYesJp[8] = "\x82\xCD\x82\xA2";
static char *sEraseYes[6] = {0};
static char sNoEn[4] = "NO";
static char sNoGe[8] = "GER NO";
static char sNoFr[8] = "FRE NO";
static char sNoSp[8] = "SPA NO";
static char sNoIt[8] = "ITA NO";
static char sNoJp[8] = "\x82\xA2\x82\xA2\x82\xA6";
static char *sEraseNo[6] = {0};
#pragma explicit_zero_data reset

/* Literal-pool primer: reproduces the order of the TU's shared .rodata pool. */
extern void fzgx_pool_use(void *);
#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_pool_fn_10_261E4(s32 x) {
    s16 t0[14] = {0xB5, 0xB6, 0xAD, 0xB3, 0xB8, 0xB2, 0xB1, 0xAE, 0xB4, 0xB9, 0xB0, 0xAF, 0xB7, -1};
    s16 t1[14] = {0xB5, 0xB6, 0xAD, 0xB3, 0xB8, 0xB2, 0xB1, 0xAE, 0xB4, 0xB9, 0xB0, 0xAF, 0xB7, -1};
    fzgx_pool_use(t0);
    fzgx_pool_use(t1);
    fzgx_pool_use(sEraseQuestion);
    fn_1_4955C(320.0f, 240.0f);
    fn_1_4955C(0.1f, 400.0f);
    fn_1_4955C(200.0f, 13.0f);
    fn_1_4955C(26.0f, 1.5f);
    fn_1_4955C(0.75f, 0.09f);
    fn_1_4955C(0.5f, -1.0f);
    fn_1_4955C(8.0f, 0.0f);
    fn_1_4954C(x);
}

void fn_10_261E4(s32 arg0, u8 arg1) {
    Color col = fn_800081C8((Color){0xA0, 0x50, 0x50, 0x00}, (Color){0xA0, 0xA0, 0xA0, 0x00}, 1.0f);

    fn_1_49410();
    fn_1_4955C(0.75f, 0.75f);
    fn_1_4954C(0.09f);
    fn_1_495C8(9);
    fn_1_495B0(0x80000000);
    fn_1_49590(0.5f);
    fn_1_496FC(288.0f, arg0);
    fn_1_495C8(10);
    if (!arg1) {
        fn_1_4D494();
        fn_1_49514((Color){0xFF, 0xFF, 0xFF, 0x00});
        fn_1_4AE0C("%s", sEraseYes[lbl_801A66B4]);
        fn_1_4D4C8(col, 0.09f, 10.0f);
    } else {
        fn_1_49514((Color){0x70, 0x70, 0x70, 0x00});
        fn_1_49528((Color){0x00, 0x00, 0x00, 0x00});
        fn_1_4AE0C("%s", sEraseYes[lbl_801A66B4]);
    }
    fn_1_496FC(352.0f, arg0);
    fn_1_495C8(8);
    if (!arg1) {
        fn_1_49514((Color){0x70, 0x70, 0x70, 0x00});
        fn_1_49528((Color){0x00, 0x00, 0x00, 0x00});
        fn_1_4AE0C("%s", sEraseNo[lbl_801A66B4]);
    } else {
        fn_1_4D494();
        fn_1_49514((Color){0xFF, 0xFF, 0xFF, 0x00});
        fn_1_4AE0C("%s", sEraseNo[lbl_801A66B4]);
        fn_1_4D4C8(col, 0.09f, 10.0f);
    }
}
/* fzgx:end fn_10_261E4 */

/* fzgx:begin fn_10_26424 */
void fn_10_26424(void) {
    lbl_10_bss_55CE2 = 1;
}
/* fzgx:end fn_10_26424 */

/* fzgx:begin fn_10_26434 */
typedef struct SelState {
    u8 pad0[8];
    u16 flags8;
    u8 padA[6];
    u16 flags10;
    u16 flags12;
} SelState;



u8 fn_10_26434(void) {
    if (((*(SelState *)&lbl_1_bss_9F8).flags10 & 1) ||
        ((*(SelState *)&lbl_1_bss_9F8).flags12 & 1)) {
        if (lbl_10_bss_55CE2 == 1) {
            lbl_10_bss_55CE2 = 0;
            fn_1_A2D84(0xA9011300);
        }
    }

    if (((((*(SelState *)&lbl_1_bss_9F8).flags10 >> 1) & 1)) ||
        ((((*(SelState *)&lbl_1_bss_9F8).flags12 >> 1) & 1))) {
        if (lbl_10_bss_55CE2 == 0) {
            lbl_10_bss_55CE2 = 1;
            fn_1_A2D84(0xA9011300);
        }
    }

    if ((((*(SelState *)&lbl_1_bss_9F8).flags8 >> 8) & 1)) {
        fn_1_A2D84(0xA9011100);
        if (lbl_10_bss_55CE2 == 0) {
            return 1;
        }
        if (lbl_10_bss_55CE2 == 1) {
            return 2;
        }
    }

    if ((((*(SelState *)&lbl_1_bss_9F8).flags8 >> 9) & 1)) {
        fn_1_A2D84(0xA9011000);
        return 2;
    }

    return 0;
}
/* fzgx:end fn_10_26434 */

/* fzgx:begin fn_10_266AC */
#define NAME_TABLE ((const char **)lbl_10_data_6B2C)


/* volatile: every store must reach the GX write-gather FIFO; the hardware register must not be merged */
#define GX_FIFO_F32 (*(volatile f32 *)GX_FIFO_BASE)

void fn_10_266AC(void) {
    NameEntryPool *pool = (NameEntryPool *)&lbl_10_rodata_1D70;
    const char *name;
    CameraDesc cam;
    u32 tevStage;

    if (fn_1_B7C00() != 0 || lbl_10_bss_55CE1 != 0) {
        fn_1_4FD64();
        fn_80074918(0, 7, 0);
        fn_80074788(1);
        fn_80074660(0);
        fn_80073678(1);
        fn_80073C6C(0);
        fn_800747D0(4, 0, 0, 0, 0, 2, 2);
        fn_80072AB0(0, 0, 0);
        fn_800734A8(0, 255, 255, 4);
        fn_80072C24(0, 15, 15, 15, 2);
        fn_80072D64(0, 0, 0, 0, 1, 0);
        fn_80072CC4(0, 7, 7, 7, 1);
        fn_80072E20(0, 0, 0, 0, 1, 0);
        fn_800728A8(1, 4, 5, 0);
        fn_80072864(2);
        fn_8007245C(0x200);
        tevStage = pool->unk_A8;
        fn_800371F8(1, &tevStage);
        fn_8003462C(0x80, 7, 4);
        /* full-screen quad through the write-gather pipe */
        GX_FIFO_F32 = pool->unk_6C;
        GX_FIFO_F32 = pool->unk_6C;
        GX_FIFO_F32 = pool->unk_64;
        GX_FIFO_F32 = pool->unk_AC;
        GX_FIFO_F32 = pool->unk_6C;
        GX_FIFO_F32 = pool->unk_64;
        GX_FIFO_F32 = pool->unk_AC;
        GX_FIFO_F32 = pool->unk_B0;
        GX_FIFO_F32 = pool->unk_64;
        GX_FIFO_F32 = pool->unk_6C;
        GX_FIFO_F32 = pool->unk_B0;
        GX_FIFO_F32 = pool->unk_64;
    }

    if (lbl_10_bss_55CE1 != 0) {
        cam = lbl_1_rodata_26F8;
        cam.mode = 2;
        cam.x = pool->unk_38;
        cam.y = pool->unk_3C;
        cam.z = pool->unk_40;
        cam.unk_30 = 10;
        fn_1_50164(pool->unk_44, pool->unk_48, pool->unk_4C, pool->unk_50, &cam);

        name = NAME_TABLE[lbl_801A66B4];
        fn_1_4AEC0(1);
        fn_1_4AEB4(pool->unk_54);
        fn_1_49410();
        fn_1_4955C(pool->unk_58, pool->unk_58);
        fn_1_4954C(pool->unk_5C);
        fn_1_495B0(0x80000000);
        fn_1_49590(pool->unk_60);
        fn_1_495C8(9);
        fn_1_496FC(pool->unk_38, pool->unk_B4);
        fn_1_4966C(pool->unk_64, pool->unk_68);
        fn_1_4A0D8(name);
        fn_1_4AEC0(0);
        fn_1_4AEB4(pool->unk_6C);
        fn_10_261E4(0x118, lbl_10_bss_55CE2);
    }
}
/* fzgx:end fn_10_266AC */
