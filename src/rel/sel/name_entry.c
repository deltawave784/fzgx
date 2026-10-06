#include "types.h"
#include "rel/sel/globals.h"
#include "rel/sel/name_entry.h"


extern u8 lbl_10_bss_55CDC;
extern s16 lbl_1_bss_960;
extern u32 lbl_801A6410;
extern void fn_1_435C(u32 value);
extern void fn_1_426C(u32 value);
extern void fn_1_A8F78(void);
extern void fn_1_48140(int value);
extern void fn_1_412A0(int value);
extern u8 fn_1_B7C00(void);
extern u8 fn_10_26434(void);
extern void fn_10_26554(void);
extern void fn_1_14BD94(void *);
extern void fn_10_26424(void);
extern u16 lbl_1_bss_9F8[5];
extern u8 lbl_1_bss_8B3A0[0x9f];
extern void fn_1_A2D84(void *);
extern void fn_1_14BCBC(void *, u8);
extern u8 lbl_1_bss_8E51D;
extern u8 lbl_1_data_2B0D4[];
extern u8 lbl_1_data_2B144[];
extern s16 fn_1_12EF24(s16, s16);
extern s32 fn_1_F89E4(u8);
extern void fn_1_14A1AC(u8);
extern void fn_1_14BC40(void);
extern void fn_1_1554D0(void);
extern void fn_1_1555B0(u8);
extern void fn_1_47F74(s32);
extern void fn_1_15555C(void);
extern void fn_1_14BD74(void);

/* fzgx:begin fn_10_25BC8 */
typedef struct fn_10_25BC8_NameEntryState {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u8 _pad0c[0x0c];
    u32 unk18;
    u32 unk1c;
} fn_10_25BC8_NameEntryState;

extern void fn_1_46B4(u32 arg0, fn_10_25BC8_NameEntryState *arg1, u8 *arg2, int arg3);

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
    fn_1_46B4(lbl_801A6410, (fn_10_25BC8_NameEntryState *)lbl_10_bss_55CD8,
              lbl_10_data_6980, 0x562);
    lbl_10_bss_55CD8 = 0;
}
/* fzgx:end fn_10_25BC8 */

/* fzgx:begin fn_10_25E1C */
#include "types.h"

typedef struct {
    u8 pad[0x8c];
    s16 value;
} fn_10_25E1C_NameEntryState;

typedef struct {
    s16 v[14];
} fn_10_25E1C_SndTable;

extern fn_10_25E1C_SndTable lbl_10_rodata_1D70;
extern u8 lbl_10_bss_55CE0;
extern u8 lbl_10_bss_55CE1;

void fn_10_25E1C(void) {
    fn_10_25E1C_NameEntryState *state = &(*(fn_10_25E1C_NameEntryState *)&lbl_1_bss_8B3A0);
    s32 i;
    s16 result;

    for (i = 0; i < 6; i++) {
        result = fn_1_12EF24(state->value, i);
        if (state->value == 5) {
            if (i == 5) {
                if (fn_1_F89E4(0) == 0) {
                    goto set_neg; // shared tail: retail merges both -1 arms
                }
            }
            if (i != 5) {
                if (fn_1_F89E4((u8)(i + 1)) == 0) {
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
            fn_10_25E1C_SndTable table = lbl_10_rodata_1D70;
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
        fn_1_A2D84((void *)0xA9011100); // fzgx-allow: A2 target hardware address
        fn_10_26424();
        lbl_10_bss_55CE1 = 1;
    }
    fn_1_14BCBC(&lbl_10_bss_55CE0, lbl_1_bss_8B3A0[0x9e]);
    return 0;
}
/* fzgx:end fn_10_26000 */

/* fzgx:begin fn_10_260D4 */
#include "types.h"

typedef struct {
    u8 pad[0x8c];
    s16 value;
} fn_10_260D4_NameEntryState;

typedef struct {
    s16 v[14];
} fn_10_260D4_SndTable;

extern fn_10_260D4_SndTable lbl_10_rodata_1D8C;

extern void fn_1_48140(int);

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

/* fzgx:begin fn_10_26424 */
void fn_10_26424(void) {
    lbl_10_bss_55CE2 = 1;
}
/* fzgx:end fn_10_26424 */

/* fzgx:begin fn_10_26434 noprologue */
#include "types.h"

extern u16 lbl_1_bss_9F8[5];

typedef struct SelState {
    u8 pad0[8];
    u16 flags8;
    u8 padA[6];
    u16 flags10;
    u16 flags12;
} SelState;


extern u8 lbl_10_bss_55CE2;
extern void fn_1_A2D84(int arg);

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
#include "dolphin/hw_regs.h"

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

typedef struct CameraDesc {
    u32 mode;
    f32 x;
    f32 y;
    f32 z;
    u32 pad_10[8];
    u32 unk_30;
    u32 pad_34[9];
} CameraDesc;

extern NameEntryPool lbl_10_rodata_1D70;
extern CameraDesc lbl_1_rodata_26F8;
extern u32 lbl_801A66B4;
#define NAME_TABLE ((const char **)lbl_10_data_6B2C)

extern u32 fn_10_261E4(u32, u32);
extern u32 fn_1_4AEC0(u32);
extern u32 fn_800371F8(u32, void *);
extern u8 fn_1_B7C00(void);
extern void fn_1_49410(void);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4AEB4(f32);
extern void fn_1_4FD64(void);
extern void fn_1_50164(f32, f32, f32, f32, void *);
extern void fn_8003462C(u32, u32, u32);
extern void fn_8007245C(u32);
extern void fn_80072864(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80073678(u32);
extern void fn_80073C6C(s32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern void fn_80074918(u8, s32, u8);

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
