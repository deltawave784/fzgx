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
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern NameEntryPool lbl_10_rodata_1D70;
extern fn_10_260D4_SndTable lbl_10_rodata_1D8C;
extern void fn_1_48140(int index);
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
extern u16 lbl_1_bss_9F8[5];
extern void fn_1_A2D84(u32 arg0);
extern CameraDesc lbl_1_rodata_26F8;
extern void fn_10_261E4(s32 arg0, u8 arg1);
extern u32 fn_1_4AEC0(u32 value);
extern u32 fn_800371F8(u32, void *);
extern u8 fn_1_B7C00(void);
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
extern int fn_10_26434(void);
extern void fn_10_26554(void);
extern void fn_1_14BD94(void *);
extern void fn_10_26424(void);
extern u8 lbl_1_bss_8B3A0[0x9f];
extern void fn_1_14BCBC(u32 arg0, u32 arg1);
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

/* fzgx:begin fn_10_26000 noprologue */
#include "types.h"
#include "rel/sel/globals.h"
#include "rel/sel/name_entry.h"


extern u8 fn_1_B7C00(void);
extern u8 fn_10_26434(void);
extern void fn_10_26554(void);
extern void fn_1_14BD94(void *);
extern void fn_10_26424(void);
extern u16 lbl_1_bss_9F8[5];
extern u8 lbl_1_bss_8B3A0[0x9f];
extern void fn_1_A2D84(void *);
extern void fn_1_14BCBC(void *, u8);

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
        fn_1_A2D84((void *)0xA9011100); // fzgx-allow: A2 target hardware address
        fn_10_26424();
        lbl_10_bss_55CE1 = 1;
    }
    fn_1_14BCBC(&lbl_10_bss_55CE0, lbl_1_bss_8B3A0[0x9e]);
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
#include "rel/sel/globals.h"
#include "rel/sel/name_entry.h"

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



int fn_10_26434(void) {
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
