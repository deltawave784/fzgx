#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/ghost.h"
#include "dolphin/ar.h"
#include "game/main_rel/ghost_types.h"

extern u32 lbl_801A6410[];
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern int fn_1_B7E98(int index);
extern void fn_1_B9C0C(void);
extern void fn_1_B9BE0(void);
extern void fn_1_AA6D8(s32, s32, void *);
extern void fn_1_F1D70(void);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_1_BC29C();
extern void fn_1_EE530(void);
extern u32 fn_1_4630();
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern void fn_1_C0510(void *);
extern void ARQPostRequest(void *arg0, u32 arg1, u32 arg2, u32 arg3, void *arg4, void *arg5, u32 arg6, void (*callback)(void));
extern void fn_1_F1950(void);
extern u32 fn_8002071C();
extern u32 fn_800206FC(u32 arg0);
extern void OSReport(const char *, ...);
extern u32 ARGetDMAStatus(void);
extern void DCInvalidateRange(void *, u32);
extern void fn_1_F23E8(void);
extern u8 fn_1_B7C00(void);
extern void fn_1_B9DE8(Obj_1_bss_7ECB4 *obj);
extern u8 lbl_1_bss_7EA00[56];
extern int fn_1_B7CD4(void);
extern u32 fn_1_B7C5C(void);
extern u32 lbl_1_bss_7B19C[2];
extern void fn_1_C1394(void);
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern const f32 lbl_1_rodata_6D20;
extern const f32 lbl_1_rodata_6D24;
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_495C8(u8 value);
extern s32 lbl_1_bss_7B198;
extern void fn_1_4AE0C(const char* format, ...);
extern u8 lbl_1_bss_7C8CE[70];
extern u32 lbl_1_bss_7EA38[159];
extern const f64 lbl_1_rodata_6B68;
extern const f32 lbl_1_rodata_6D10;
extern const f32 lbl_1_rodata_6D44;
extern void DCFlushRange(void *addr, u32 size);
extern u32 lbl_1_bss_7C848[2];
extern u8 lbl_1_bss_7C8CD;
extern u32 lbl_1_bss_7C948;
extern void fn_1_12EF80(s16 arg, s16 *out_a, s16 *out_b);
extern u32 lbl_1_bss_7B190[2];
extern u32 lbl_1_bss_7ED58[158];
extern f64 lbl_1_rodata_6C88;
extern s32 fn_1_F21B8(s32 arg);
extern void fn_1_F0D10(s32, void *);
extern void fn_1_F0B5C(s32, void *);
extern void fn_1_F0E00(s32, void *);
extern s32 fn_1_3F164(void);
extern void fn_1_1596DC(int index);
extern void fn_1_484CC(s32 index);
extern u32 lbl_1_bss_7C914[13];
extern const f32 lbl_1_rodata_6D38;
extern const f32 lbl_1_rodata_6D3C;
extern const f32 lbl_1_rodata_6D40;
extern void lbl_8006DD14(void *a, void *b);
extern f32 lbl_8006D0B4(f32 x);
extern void lbl_8006D7DC(void *a);
extern void lbl_8006DFC4(void *a);
extern void lbl_8006DB74(void *a);
extern const f32 lbl_1_rodata_6BBC;
extern const f32 lbl_1_rodata_6BD0;
extern const f64 lbl_1_rodata_6D48;
extern const f32 lbl_1_rodata_6D50;
extern f64 fn_80088598(f64, f64);
extern u8 *fn_1_3F0D8(u32 index, f32 *value, u8 *flag);

/* fzgx:begin fn_1_EB330 noprologue */
#include "types.h"
#include "rel/main_rel/ghost.h"

extern u32 lbl_801A6410;
extern u8 lbl_1_data_3E62C[128];
extern void fn_1_46B4(u32, u32, u8 *, s32);
extern s32 fn_1_B7E98(s32);
extern void fn_1_B9C0C(void);
extern void fn_1_B9BE0(void);
extern void fn_1_AA6D8(s32, s32, void *);
extern void fn_1_F1D70(void);
extern void fn_80008BEC(void *, s32, u32);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_7B180[2];
u32 fzgx_obj_lbl_1_bss_7B188[2];
u32 lbl_1_bss_7B190[2];
u32 lbl_1_bss_7B198;
u32 lbl_1_bss_7B19C[2];
s32 fzgx_obj_lbl_1_bss_7B1A4;
u32 lbl_1_bss_7B1A4__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_7B1AC;
u8 lbl_1_bss_7B1AC__fzgx_offset_1;
u16 lbl_1_bss_7B1AC__fzgx_offset_2;
u32 lbl_1_bss_7B1AC__fzgx_offset_4[1269];
u8 fzgx_obj_lbl_1_bss_7C584;
u8 lbl_1_bss_7C584__fzgx_offset_1;
u16 lbl_1_bss_7C584__fzgx_offset_2;
u32 lbl_1_bss_7C584__fzgx_offset_4[176];
u32 lbl_1_bss_7C848[2];
u32 lbl_1_bss_7C850[3];
u32 fzgx_obj_lbl_1_bss_7C85C[28];
u8 lbl_1_bss_7C85C__fzgx_offset_70;
u8 lbl_1_bss_7C8CD;
u16 lbl_1_bss_7C8CE;
u32 lbl_1_bss_7C8CE__fzgx_offset_2[17];
u32 lbl_1_bss_7C914[13];
u32 lbl_1_bss_7C948;
u32 lbl_1_bss_7C94C[67];
u32 lbl_1_bss_7CA58[2020];
u32 lbl_1_bss_7E9E8__fzgx_offset_0[4];
s32 lbl_1_bss_7E9E8__fzgx_offset_10;
s32 lbl_1_bss_7E9E8__fzgx_offset_14;
u8 lbl_1_bss_7EA00;
u8 lbl_1_bss_7EA00__fzgx_offset_1;
u16 lbl_1_bss_7EA00__fzgx_offset_2;
s32 lbl_1_bss_7EA00__fzgx_offset_4;
s32 lbl_1_bss_7EA00__fzgx_offset_8;
u8 lbl_1_bss_7EA00__fzgx_offset_C;
u8 lbl_1_bss_7EA00__fzgx_offset_D;
u16 lbl_1_bss_7EA00__fzgx_offset_E;
s32 lbl_1_bss_7EA00__fzgx_offset_10;
u32 lbl_1_bss_7EA00__fzgx_offset_14[9];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B180;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B188;
    s = *(u8 *)&lbl_1_bss_7B190;
    s = *(u8 *)&lbl_1_bss_7B198;
    s = *(u8 *)&lbl_1_bss_7B19C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1A4;
    s = *(u8 *)&lbl_1_bss_7B1A4__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1AC;
    s = *(u8 *)&lbl_1_bss_7B1AC__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_7B1AC__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_7B1AC__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C584;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_7C848;
    s = *(u8 *)&lbl_1_bss_7C850;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C85C;
    s = *(u8 *)&lbl_1_bss_7C85C__fzgx_offset_70;
    s = *(u8 *)&lbl_1_bss_7C8CD;
    s = *(u8 *)&lbl_1_bss_7C8CE;
    s = *(u8 *)&lbl_1_bss_7C8CE__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_7C914;
    s = *(u8 *)&lbl_1_bss_7C948;
    s = *(u8 *)&lbl_1_bss_7C94C;
    s = *(u8 *)&lbl_1_bss_7CA58;
    s = *(u8 *)&lbl_1_bss_7E9E8__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_7E9E8__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_7E9E8__fzgx_offset_14;
    s = *(u8 *)&lbl_1_bss_7EA00;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_C;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_D;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_E;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_14;
}
#pragma section code_type ".text"

void fn_1_EB330(void) {
    
    u8 *entry = (u8 *)&fzgx_obj_lbl_1_bss_7C584;
    s32 i;
    u8 local[0x2c];

    for (i = 0; i < 0x7f; i++, entry += 4) {
        if (*(u32 *)entry != 0) {
            fn_1_46B4(lbl_801A6410, *(u32 *)entry, lbl_1_data_3E62C, 0x626);
        }
    }

    lbl_1_bss_7E9E8__fzgx_offset_10 = -1;
    fzgx_obj_lbl_1_bss_7B1A4 = 1;
    fn_80008BEC((u8 *)&fzgx_obj_lbl_1_bss_7B1AC, 0, 0x13d8);
    fn_80008BEC((u8 *)&fzgx_obj_lbl_1_bss_7C584, 0, 0x1fc);

    if (fn_1_B7E98(0) == 0 && fn_1_B7E98(1) == 0) {
        lbl_1_bss_7E9E8__fzgx_offset_14 = 0;
        return;
    }

    fn_1_B9C0C();
    fn_1_B9BE0();
    fn_80008BEC(local, 0, 0x24);
    fn_80008BEC(&lbl_1_bss_77380, 0, 0x30);
    local[0] = 2;
    *(u32 *)(local + 0xc) = (u32)&lbl_1_bss_77380;
    *(u32 *)(local + 0x20) = 4;

    if (fn_1_B7E98(0) != 0 && fn_1_B7E98(1) != 0) {
        fn_1_AA6D8(4, 2, local);
    } else {
        fn_1_AA6D8(4, 4, local);
    }

    lbl_1_bss_7E9E8__fzgx_offset_14 = 1;
    lbl_1_bss_7EA00 = 0;
    fn_1_F1D70();
    lbl_1_bss_7EA00__fzgx_offset_4 = 0x14;
    lbl_1_bss_7EA00__fzgx_offset_8 = 0;
    lbl_1_bss_7EA00__fzgx_offset_C = 0;
    lbl_1_bss_7EA00__fzgx_offset_10 = 0;
}
/* fzgx:end fn_1_EB330 */

/* fzgx:begin fn_1_EB4BC pool noprologue */
#include "types.h"

typedef struct {
    u32 data[9];
    u8 minutes;
    u8 seconds;
    u16 millis;
} GhostEntry; /* 0x28 */

typedef struct {
    u8 pad_0[0x24];
    u32 unk_24;
    u32 unk_28;
    u8 *unk_2C;
} GhostSource; /* 0x30 */

typedef struct {
    u8 pad_0[0x14];
    s32 unk_14;
    u8 pad_18[0x4];
} GhostFlags;

extern GhostSource lbl_1_bss_77380[];
extern u32 lbl_801A6410;
extern char lbl_1_data_3E62C[];
extern char lbl_1_data_3E704[];

extern u8 fn_1_B7C00(void);
extern s32 fn_1_B7CD4(void);
extern u32 fn_1_B7C5C(void);
extern void fn_1_46B4(u32, void *, const char *, int);
extern void *fn_1_4630(u32, u32, const char *, int);
extern void OSReport(const char *, ...);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_80008BEC(void *, int, u32);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 lbl_1_bss_7B180[0x8];
u8 lbl_1_bss_7B188[0x24];
GhostEntry lbl_1_bss_7B1AC[127];
void *lbl_1_bss_7C584[127];
u8 lbl_1_bss_7C780[0x227C];
s32 lbl_1_bss_7E9FC;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_1_bss_7B180;
    s = *(u8 *)&lbl_1_bss_7B188;
    s = *(u8 *)&lbl_1_bss_7B1AC;
    s = *(u8 *)&lbl_1_bss_7C584;
    s = *(u8 *)&lbl_1_bss_7C780;
    s = *(u8 *)&lbl_1_bss_7E9FC;
}
#pragma section code_type ".text"

#define GHOST_TIME(e) ((e)->seconds * 1000 + (e)->minutes * 60000 + (e)->millis)

s32 fn_1_EB4BC(void) {
    GhostEntry tmp;
    void *buf;
    void *src;
    s32 i;
    s32 j;
    s32 count;
    void * buf_2;

    if (fn_1_B7C00()) {
        return 1;
    }
    if (lbl_1_bss_7E9FC == 0) {
        return 0;
    }
    if (fn_1_B7CD4() == 0) {
        OSReport(lbl_1_data_3E704, fn_1_B7C5C());
        lbl_1_bss_7E9FC = 0;
        return 1;
    }

    for (i = 0; i < 127; i++) {
        if (lbl_1_bss_77380[i].unk_24 != 0 && (src = lbl_1_bss_77380[i].unk_2C) != NULL) {
            fn_80008BA8(&lbl_1_bss_7B1AC[i], src, sizeof(GhostEntry));
            if (lbl_1_bss_7C584[i] != NULL) {
                fn_1_46B4(lbl_801A6410, lbl_1_bss_7C584[i], lbl_1_data_3E62C, 1660);
            }
            buf = fn_1_4630(lbl_801A6410, 16000, lbl_1_data_3E62C, 1662);
            fn_80008BA8(buf, (u8 *)src + 40, 16000);
            fn_1_46B4(lbl_801A6410, lbl_1_bss_77380[i].unk_2C, lbl_1_data_3E62C, 1666);
            lbl_1_bss_77380[i].unk_2C = NULL;
            lbl_1_bss_7C584[i] = fn_1_4630(lbl_801A6410, 16000, lbl_1_data_3E62C, 1669);
            fn_80008BA8(lbl_1_bss_7C584[i], buf, 16000);
            fn_1_46B4(lbl_801A6410, buf, lbl_1_data_3E62C, 1673);
        } else {
            fn_80008BEC(&lbl_1_bss_7B1AC[i], 0, sizeof(GhostEntry));
            lbl_1_bss_7C584[i] = NULL;
        }
    }

    count = 0;
    for (j = 0; j < 127; j++) {
        if (lbl_1_bss_7C584[j] != NULL) {
            count++;
        }
    }

    for (i = 0; i < count - 1; i++) {
        for (j = i; j < count; j++) {
            if (GHOST_TIME(&lbl_1_bss_7B1AC[i]) > GHOST_TIME(&lbl_1_bss_7B1AC[j])) {
                tmp = lbl_1_bss_7B1AC[i];
                buf_2 = lbl_1_bss_7C584[i];
                lbl_1_bss_7B1AC[i] = lbl_1_bss_7B1AC[j];
                lbl_1_bss_7C584[i] = lbl_1_bss_7C584[j];
                lbl_1_bss_7B1AC[j] = tmp;
                lbl_1_bss_7C584[j] = buf_2;
            }
        }
    }

    lbl_1_bss_7E9FC = 0;
    return 1;
}
/* fzgx:end fn_1_EB4BC */

/* fzgx:begin fn_1_EB85C */
typedef struct {
    u8 pad_0[0x1];
    u8 unk_1;
    u8 pad_2[0x26];
} GhostEntry;

int fn_1_EB85C(void) {
    int result;
    GhostEntry *entry;
    int i;

    if (fn_1_B7C00() != 0) {
        return 0;
    }

    if ((s32)lbl_1_bss_7B1A4 == 0) {
        return 0;
    }

    result = fn_1_F21B8(lbl_1_bss_8B3A0.unk_90) != 0;
    entry = (GhostEntry *)&lbl_1_bss_7B1AC;
    for (i = 0; i < 0x7f; i++) {
        if (lbl_1_bss_8B3A0.unk_90 == entry[i].unk_1) {
            result++;
        }
    }

    return result;
}
/* fzgx:end fn_1_EB85C */

/* fzgx:begin fn_1_EB8F4 pool noprologue */
#include "dolphin/types.h"
#include "rel/main_rel/ghost.h"
#include "font.h"

extern f64 __fabs(f64);

extern u32 lbl_801A66B4;
extern u32 lbl_801A66A0;
typedef union { struct { u8 r, g, b, a; }; u32 word; } PanelColor;
extern u32 lbl_1_rodata_6B70;
extern u32 lbl_1_rodata_6B74;
extern u32 lbl_1_rodata_6B78;
extern u32 lbl_1_rodata_6B7C;
extern u32 lbl_1_rodata_6B80;
extern u32 lbl_1_rodata_6B84;
extern u32 lbl_1_rodata_6B88;
extern u32 lbl_1_rodata_6B8C;
extern u32 lbl_1_rodata_6B90;
#define PANEL_COLOR(x) (*(const PanelColor *)&(x))
extern f32 lbl_1_rodata_26F8[22];
extern const f32 lbl_1_rodata_6B60;
extern const f64 lbl_1_rodata_6B68;
extern const f32 lbl_1_rodata_6B94;
extern const f32 lbl_1_rodata_6B98;
extern const f32 lbl_1_rodata_6B9C;
extern const f32 lbl_1_rodata_6BA0;
extern const f32 lbl_1_rodata_6BA4;
extern const f32 lbl_1_rodata_6BA8;
extern const f32 lbl_1_rodata_6BAC;
extern const f32 lbl_1_rodata_6BB0;
extern const f32 lbl_1_rodata_6BB4;
extern const f32 lbl_1_rodata_6BB8;
extern const f32 lbl_1_rodata_6BBC;
extern const f32 lbl_1_rodata_6BC0;
extern const f32 lbl_1_rodata_6BC4;
extern const f32 lbl_1_rodata_6BC8;
extern const f32 lbl_1_rodata_6BCC;
extern const f32 lbl_1_rodata_6BD0;
extern const f32 lbl_1_rodata_6BD4;
extern const f32 lbl_1_rodata_6BD8;
extern const f32 lbl_1_rodata_6BDC;
extern const f32 lbl_1_rodata_6BE0;
extern const f64 lbl_1_rodata_6BE8;
extern const f64 lbl_1_rodata_6BF0;
extern const f64 lbl_1_rodata_6BF8;
extern const f64 lbl_1_rodata_6C00;
extern const f32 lbl_1_rodata_6C08;
extern const f32 lbl_1_rodata_6C0C;
extern const f32 lbl_1_rodata_6C10;
extern const f32 lbl_1_rodata_6C14;
extern const f32 lbl_1_rodata_6C18;
extern const f64 lbl_1_rodata_6C20;
extern const f64 lbl_1_rodata_6C28;
extern const f32 lbl_1_rodata_6C30;
extern const f32 lbl_1_rodata_6C34;
extern const f32 lbl_1_rodata_6C38;
extern const f32 lbl_1_rodata_6C3C;
extern const f32 lbl_1_rodata_6C40;
extern const f32 lbl_1_rodata_6C44;
extern const f32 lbl_1_rodata_6C48;
extern const f32 lbl_1_rodata_6C4C;
extern const f64 lbl_1_rodata_6C50;
extern const f64 lbl_1_rodata_6C58;
extern const f64 lbl_1_rodata_6C60;
extern const f32 lbl_1_rodata_6C68;
extern const f64 lbl_1_rodata_6C70;
extern const f64 lbl_1_rodata_6C78;
extern const f32 lbl_1_rodata_6C80;
extern const f64 lbl_1_rodata_6C88;
extern u8 fn_1_B7C00(void);
extern int fn_1_B7E98(int);
extern void fn_1_EC910(void);
extern void fn_1_F1D70(void);
extern s32 fn_1_F21B8(s32);
extern void fn_1_53B14(u8 *, f32, f32, f32, f32, f32);
extern void fn_1_53C9C(u8 *, f32, f32, f32, f32, f32, const char *);
extern void fn_1_BFE20(s16, s16, f32, f32, f32, f32, f32);
extern u32 ghost_test_flag(s32);
extern void fn_1_A2D84(u32);
extern void fn_1_F1E30(s32);
extern void fn_1_F1ED0(s32);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_49410(void);
extern void fn_1_49614(void);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_12EF80(s16, s16 *, s16 *);
extern void fn_1_49514(u32 *);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern s32 fn_1_F2280(s32);
extern void *fn_1_7F49C(s16, s16, void *);
extern f32 lbl_8006D188(s16);

extern void ghost_reset(void);
extern void fn_1_ECE00(void);
extern void fn_1_ECF68(void);
extern void fn_1_ED540(void);
extern void fn_1_EE530(void);
extern void fn_1_EF0A0(void);
extern void fn_1_EF5E0(void);
extern void fn_1_EF768(void);
extern void fn_1_EF860(void);
extern void fn_1_EF924(void);
extern void fn_1_EF97C(void);
extern void fn_1_EFA1C(void);
extern void fn_1_EF0A8(void);
extern void fn_1_EF488(void);
extern void fn_1_EF4F8(void);
extern void fn_1_EFA8C(void);
extern void fn_1_F0168(void);
u8 lbl_1_data_3E358[12] = "OVERTAKE";
extern u8 fn_1_ECDFC__fzgx_offset_0[];
extern u8 fn_1_ECE00__fzgx_offset_0[];
extern u8 fn_1_ECE04__fzgx_offset_0[];
extern u8 fn_1_ECF68__fzgx_offset_0[];
extern u8 fn_1_ECF88__fzgx_offset_0[];
extern u8 fn_1_ED540__fzgx_offset_0[];
extern u8 fn_1_EE3F4__fzgx_offset_0[];
extern u8 fn_1_EE530__fzgx_offset_0[];
extern u8 fn_1_EEB44__fzgx_offset_0[];
extern u8 fn_1_EF0A0__fzgx_offset_0[];
extern u8 fn_1_EF0A4__fzgx_offset_0[];
extern u8 fn_1_EF0A8__fzgx_offset_0[];
extern u8 fn_1_EF484__fzgx_offset_0[];
extern u8 fn_1_EF488__fzgx_offset_0[];
extern u8 fn_1_EF4F4__fzgx_offset_0[];
extern u8 fn_1_EF4F8__fzgx_offset_0[];
extern u8 fn_1_EF5DC__fzgx_offset_0[];
extern u8 fn_1_EF5E0__fzgx_offset_0[];
extern u8 fn_1_EF764__fzgx_offset_0[];
extern u8 fn_1_EF768__fzgx_offset_0[];
extern u8 fn_1_EF85C__fzgx_offset_0[];
extern u8 fn_1_EF860__fzgx_offset_0[];
extern u8 fn_1_EF920__fzgx_offset_0[];
extern u8 fn_1_EF924__fzgx_offset_0[];
extern u8 fn_1_EF978__fzgx_offset_0[];
extern u8 fn_1_EF97C__fzgx_offset_0[];
extern u8 fn_1_EFA18__fzgx_offset_0[];
extern u8 fn_1_EFA1C__fzgx_offset_0[];
extern u8 fn_1_EFA4C__fzgx_offset_0[];
extern u8 fn_1_EFA88__fzgx_offset_0[];
extern u8 fn_1_EFA8C__fzgx_offset_0[];
extern u8 fn_1_F0164__fzgx_offset_0[];
extern u8 fn_1_F0168__fzgx_offset_0[];
extern u8 ghost_reset__fzgx_offset_0[];
extern u8 lbl_1_data_3E358__fzgx_offset_0[];
extern u8 lbl_1_data_3E364__fzgx_offset_0[];
extern u8 lbl_1_data_3E36C__fzgx_offset_0[];
extern u8 lbl_1_data_3E378__fzgx_offset_0[];
extern u8 lbl_1_data_3E380__fzgx_offset_0[];
extern u8 lbl_1_data_3E38C__fzgx_offset_0[];
extern u8 lbl_1_data_3E394__fzgx_offset_0[];
extern u8 lbl_1_data_3E39C__fzgx_offset_0[];
extern u8 lbl_1_data_3E3C0__fzgx_offset_0[];
extern u8 lbl_1_data_3E3CC__fzgx_offset_0[];
extern u8 lbl_1_data_3E3D8__fzgx_offset_0[];
extern u8 lbl_1_data_3E478__fzgx_offset_0[];
extern u8 lbl_1_data_3E48C__fzgx_offset_0[];
extern u8 lbl_1_data_3E490__fzgx_offset_0[];
extern u8 lbl_1_data_3E4BC__fzgx_offset_0[];
extern u8 lbl_1_data_3E4C8__fzgx_offset_0[];
extern u8 lbl_1_data_3E4F4__fzgx_offset_0[];
extern u8 lbl_1_data_3E504__fzgx_offset_0[];
static union { u32 w[52]; u32 v[52]; } fzgx_pool_init_lbl_1_data_3E358__fzgx_offset_C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4A554D50, 0x0, 0x454E454D, 0x59484954, 0x0, 0x57414C4C, 0x48495400, 0x53494445,
    0x42595349, 0x44450000, 0x53544152, 0x54000000, 0x474F414C, 0x0, 0x4C415000, (u32)lbl_1_data_3E358__fzgx_offset_0,
    (u32)lbl_1_data_3E364__fzgx_offset_0, (u32)lbl_1_data_3E36C__fzgx_offset_0, (u32)lbl_1_data_3E378__fzgx_offset_0, (u32)lbl_1_data_3E380__fzgx_offset_0, (u32)lbl_1_data_3E38C__fzgx_offset_0, (u32)lbl_1_data_3E394__fzgx_offset_0, (u32)lbl_1_data_3E39C__fzgx_offset_0, 0x67686F73,
    0x7430302E, 0x62696E00, 0x67686F73, 0x7430312E, 0x62696E00, 0x67686F73, 0x7430322E, 0x62696E00,
    (u32)lbl_1_data_3E3C0__fzgx_offset_0, (u32)lbl_1_data_3E3CC__fzgx_offset_0, (u32)lbl_1_data_3E3D8__fzgx_offset_0, (u32)fn_1_ECDFC__fzgx_offset_0, (u32)fn_1_ECE04__fzgx_offset_0, (u32)fn_1_ECF88__fzgx_offset_0, (u32)fn_1_EE3F4__fzgx_offset_0, (u32)fn_1_EEB44__fzgx_offset_0,
    (u32)fn_1_EF5DC__fzgx_offset_0, (u32)fn_1_EF764__fzgx_offset_0, (u32)fn_1_EF85C__fzgx_offset_0, (u32)fn_1_EF920__fzgx_offset_0, (u32)fn_1_EF978__fzgx_offset_0, (u32)fn_1_EFA18__fzgx_offset_0, (u32)fn_1_EF0A4__fzgx_offset_0, (u32)fn_1_EF484__fzgx_offset_0,
    (u32)fn_1_EF4F4__fzgx_offset_0, (u32)fn_1_EFA88__fzgx_offset_0, (u32)fn_1_EFA4C__fzgx_offset_0, (u32)fn_1_F0164__fzgx_offset_0
}};
static union { u32 w[17]; void (*v[17])(void); } fzgx_pool_init_lbl_1_data_3E434 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)fn_1_ECE00__fzgx_offset_0, (u32)fn_1_ECF68__fzgx_offset_0, (u32)fn_1_ED540__fzgx_offset_0, (u32)fn_1_EE530__fzgx_offset_0, (u32)fn_1_EF0A0__fzgx_offset_0, (u32)fn_1_EF5E0__fzgx_offset_0, (u32)fn_1_EF768__fzgx_offset_0, (u32)fn_1_EF860__fzgx_offset_0,
    (u32)fn_1_EF924__fzgx_offset_0, (u32)fn_1_EF97C__fzgx_offset_0, (u32)fn_1_EFA1C__fzgx_offset_0, (u32)fn_1_EF0A8__fzgx_offset_0, (u32)fn_1_EF488__fzgx_offset_0, (u32)fn_1_EF4F8__fzgx_offset_0, (u32)fn_1_EFA8C__fzgx_offset_0, (u32)ghost_reset__fzgx_offset_0,
    (u32)fn_1_F0168__fzgx_offset_0
}};
char lbl_1_data_3E478[20] = "Original Machine";
u32 lbl_1_data_3E48C[1] = {0};
u32 lbl_1_data_3E490[5] = {0x8349838A, 0x83578369, 0x838B837D, 0x83568393, 0x00000000};
static union { u32 w[6]; char *v[6]; } fzgx_pool_init_lbl_1_data_3E4A4 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_1_data_3E478__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E490__fzgx_offset_0
}};
char lbl_1_data_3E4BC[12] = "Staff Ghost";
u32 lbl_1_data_3E4C8[5] = {0x8358835E, 0x83628374, 0x8353815B, 0x83588367, 0x00000000};
static union { u32 w[6]; char *v[6]; } fzgx_pool_init_lbl_1_data_3E4DC = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_1_data_3E4BC__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E4C8__fzgx_offset_0
}};
char lbl_1_data_3E4F4[16] = "SELECT GHOST";
char lbl_1_data_3E504[16] = "GHOST SELECT";
static char *fzgx_pool_init_lbl_1_data_3E514[6] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (char *)lbl_1_data_3E4F4__fzgx_offset_0, (char *)lbl_1_data_3E48C__fzgx_offset_0, (char *)lbl_1_data_3E48C__fzgx_offset_0, (char *)lbl_1_data_3E48C__fzgx_offset_0, (char *)lbl_1_data_3E48C__fzgx_offset_0, (char *)lbl_1_data_3E504__fzgx_offset_0
};
u32 lbl_1_data_3E52C = 0xFFFFFFFF;
static union { u32 w[33]; u32 v[33]; } fzgx_pool_init_lbl_1_data_3E358__fzgx_offset_1D8 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFFFFFFFF, 0xFFFF0000, 0xFFFFFFFF, 0xC, 0x1D, 0xE, 0x17, 0x4,
    0x0, 0x16, 0x1D, 0xC, 0x17, 0x16, 0x0, 0x1D,
    0x1B, 0x4, 0xF, 0x4, 0x0, 0x1D, 0x11, 0x15,
    0xC, 0x14, 0x0, 0x27, 0x5, 0x1F, 0x4, 0x28,
    0x1F
}};
u32 lbl_1_data_3E5B4[30] = {0x0003B3C4, 0x000382B3, 0x001382E7, 0x0013B38B, 0x0020F129, 0x00000000, 0x0010714B, 0x002192B1, 0x001230A9, 0x0021A322, 0x0011A225, 0x00000000, 0x0022838D, 0x00218381, 0x0023B075, 0x00232128, 0x00232328, 0x00000000, 0x0023A28A, 0x00209351, 0x00206394, 0x0023B04C, 0x0020310C, 0x00000000, 0x001062B2, 0x001260B2, 0x00206345, 0x00312110, 0x003322E4, 0x0002E37D};
static union { u32 w[59]; u32 v[59]; } fzgx_pool_init_lbl_1_data_3E358__fzgx_offset_2D4 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x67686F73, 0x742E6300, 0x47686F73, 0x7443616C, 0x63000000, 0x47686F73, 0x74446973, 0x70000000,
    0x73746F72, 0x795F6768, 0x6F73742F, 0x25730000, 0x53746F72, 0x7947686F, 0x7374203A, 0x20257320,
    0x2025640A, 0x0, 0x2E2F7374, 0x6166665F, 0x67686F73, 0x742F6768, 0x6F737425, 0x642E6461,
    0x74000000, 0x70636172, 0x6F626A5B, 0x25645D0A, 0x0, 0x6361726F, 0x626A5B25, 0x645D0A00,
    0x73617665, 0x5F3F3F3F, 0x5B25645D, 0xA000000, 0x76656869, 0x636C655F, 0x70617274, 0x732F0000,
    0x2E2E0000, 0x76656869, 0x636C652F, 0x25735F65, 0x2E617263, 0x2E6C7A00, 0x76656869, 0x636C652F,
    0x25735F70, 0x2E617263, 0x2E6C7A00, 0x76656869, 0x636C652F, 0x0, 0x72657375, 0x6C745F63,
    0x6F64653A, 0x2025640A, 0x0
}};
static union { u32 w[4]; char v[16]; } fzgx_pool_init_lbl_1_data_3E718 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x25303264, 0x3A253032, 0x643A2530, 0x33640000
}};
static union { u32 w[1]; char v[4]; } fzgx_pool_init_lbl_1_data_3E728 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x25730000
}};

typedef union {
    FontDrawPacket packet;
    f32 floats[22];
    u32 words[22];
    s16 shorts[44];
    PanelColor colors[22];
} DrawPacket;
typedef struct {
    u8 car;
    u8 course;
    u8 rest[38];
} GhostRow;
extern Obj_1_bss_8B3A0 lbl_1_bss_8B3A0;
extern Obj_1_bss_9F8 lbl_1_bss_9F8;
#define PF(p,o) ((p).floats[(o)/4])
#define PW(p,o) ((p).words[(o)/4])
#define PH(p,o) ((p).shorts[(o)/2])
#define PC(p,o) ((p).colors[(o)/4])
#define PB(p,o) (*((u8 *)&(p)+(o)))

#pragma fp_contract off
/* file-scope objects of the retail TU (from a matched sibling), in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_7B180[2];
u32 fzgx_obj_lbl_1_bss_7B188[2];
u32 lbl_1_bss_7B190[2];
u32 lbl_1_bss_7B198;
u32 lbl_1_bss_7B19C[2];
s32 fzgx_obj_lbl_1_bss_7B1A4;
u32 lbl_1_bss_7B1A4__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_7B1AC;
u8 lbl_1_bss_7B1AC__fzgx_offset_1;
u16 lbl_1_bss_7B1AC__fzgx_offset_2;
u32 lbl_1_bss_7B1AC__fzgx_offset_4[1269];
u8 fzgx_obj_lbl_1_bss_7C584;
u8 lbl_1_bss_7C584__fzgx_offset_1;
u16 lbl_1_bss_7C584__fzgx_offset_2;
u32 lbl_1_bss_7C584__fzgx_offset_4[176];
u32 lbl_1_bss_7C848[2];
u32 lbl_1_bss_7C850[3];
u32 fzgx_obj_lbl_1_bss_7C85C[28];
u8 lbl_1_bss_7C85C__fzgx_offset_70;
u8 lbl_1_bss_7C8CD;
u16 lbl_1_bss_7C8CE;
u32 lbl_1_bss_7C8CE__fzgx_offset_2[17];
u32 lbl_1_bss_7C914[13];
u32 lbl_1_bss_7C948;
u32 lbl_1_bss_7C94C[67];
u32 lbl_1_bss_7CA58[2020];
u32 lbl_1_bss_7E9E8__fzgx_offset_0[4];
s32 lbl_1_bss_7E9E8__fzgx_offset_10;
s32 lbl_1_bss_7E9E8__fzgx_offset_14;
u8 lbl_1_bss_7EA00;
u8 lbl_1_bss_7EA00__fzgx_offset_1;
u16 lbl_1_bss_7EA00__fzgx_offset_2;
s32 lbl_1_bss_7EA00__fzgx_offset_4;
s32 lbl_1_bss_7EA00__fzgx_offset_8;
u8 lbl_1_bss_7EA00__fzgx_offset_C;
u8 lbl_1_bss_7EA00__fzgx_offset_D;
u16 lbl_1_bss_7EA00__fzgx_offset_E;
s32 lbl_1_bss_7EA00__fzgx_offset_10;
u32 lbl_1_bss_7EA00__fzgx_offset_14[9];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B180;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B188;
    s = *(u8 *)&lbl_1_bss_7B190;
    s = *(u8 *)&lbl_1_bss_7B198;
    s = *(u8 *)&lbl_1_bss_7B19C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1A4;
    s = *(u8 *)&lbl_1_bss_7B1A4__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1AC;
    s = *(u8 *)&lbl_1_bss_7B1AC__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_7B1AC__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_7B1AC__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C584;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_7C848;
    s = *(u8 *)&lbl_1_bss_7C850;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C85C;
    s = *(u8 *)&lbl_1_bss_7C85C__fzgx_offset_70;
    s = *(u8 *)&lbl_1_bss_7C8CD;
    s = *(u8 *)&lbl_1_bss_7C8CE;
    s = *(u8 *)&lbl_1_bss_7C8CE__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_7C914;
    s = *(u8 *)&lbl_1_bss_7C948;
    s = *(u8 *)&lbl_1_bss_7C94C;
    s = *(u8 *)&lbl_1_bss_7CA58;
    s = *(u8 *)&lbl_1_bss_7E9E8__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_7E9E8__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_7E9E8__fzgx_offset_14;
    s = *(u8 *)&lbl_1_bss_7EA00;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_C;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_D;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_E;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_14;
}
#pragma section code_type ".text"


void fn_1_EB8F4(void)
{
    Obj_1_bss_7B180 *bssBase = ((void *)&fzgx_obj_lbl_1_bss_7B180);
#define lbl_1_bss_7B180 (*bssBase)
    DrawPacket arrow;
    DrawPacket selection;
    DrawPacket badge;
    char name[32];
    u32 panelColor;
    u32 selectionColor;
    u32 staffOnColor;
    u32 staffOffColor;
    u32 badgeColor;
    u32 ghostOnColor;
    u32 ghostOffColor;
    s16 courseA;
    s16 courseB;
    u32 count;
    u32 current;
    u32 shown;
    u8 hasStaff;
    u32 row;
    u32 i;
    u32 matches;
    u32 index;
    u32 marked;
    u32 courseIndex;
    u32 height;
    s32 oldTimer;
    s32 cursor;
    f32 t;
    f64 pulse;
    u8 *entry;

    panelColor = lbl_1_rodata_6B70;
    if (fn_1_B7C00()) return;
    if ((s32)(*(u32 *)&fzgx_obj_lbl_1_bss_7B1A4) == 0) return;
    if (fn_1_B7E98(0) == 0 && fn_1_B7E98(1) == 0) {
        fn_1_EC910();
        return;
    }
    if (lbl_1_bss_8B3A0.unk_90 != (s32)(*(u32 *)&lbl_1_bss_7E9E8__fzgx_offset_10)) {
        (*(u32 *)&lbl_1_bss_7E9E8__fzgx_offset_10) = lbl_1_bss_8B3A0.unk_90;
        lbl_1_bss_7EA00 = 0;
        fn_1_F1D70();
        (*(u32 *)&lbl_1_bss_7EA00__fzgx_offset_10) = 0;
    }
    {
        u32 padB, padA;
        if (((padA = lbl_1_bss_9F8.unk_10) & 1) || ((padB = lbl_1_bss_9F8.unk_12) & 1) ||
            ((padA >> 1) & 1) || ((padB >> 1) & 1) || ((lbl_1_bss_9F8.unk_8 >> 9) & 1)) {
            lbl_1_bss_7EA00 = 0;
            fn_1_F1D70();
            (*(u32 *)&lbl_1_bss_7EA00__fzgx_offset_10) = 0;
        }
    }
    if (fn_1_F21B8(lbl_1_bss_8B3A0.unk_90)) {
        hasStaff = 1;
        count = 1;
    } else {
        hasStaff = 0;
        count = 0;
    }
    if ((s32)(*(u32 *)&fzgx_obj_lbl_1_bss_7B1A4) != 0) {
        for (i = 0; i < 127; i++) {
            if (lbl_1_bss_8B3A0.unk_90 == ((GhostRow *)((u8 *)&fzgx_obj_lbl_1_bss_7B1AC))[i].course) count++;
        }
    }
    if (count == 0) return;
    oldTimer = (*(u32 *)&lbl_1_bss_7EA00__fzgx_offset_4);
    (*(u32 *)&lbl_1_bss_7EA00__fzgx_offset_4) = oldTimer - 1;
    if (oldTimer > 0) {
        t = (f32)(20 - (s32)(*(u32 *)&lbl_1_bss_7EA00__fzgx_offset_4)) / lbl_1_rodata_6B94;
        if (count < 7) {
            height = count * 244 / 7;
            fn_1_53B14((u8 *)&panelColor, lbl_1_rodata_6B98,
                (f32)(210 - ((244 - height) >> 1)),
                lbl_1_rodata_6B9C * t, t * (f32)(height + 10), lbl_1_rodata_6BA0);
        } else {
            fn_1_53B14((u8 *)&panelColor, lbl_1_rodata_6B98, lbl_1_rodata_6BA4,
                lbl_1_rodata_6B9C * t, lbl_1_rodata_6BA8 * t, lbl_1_rodata_6BA0);
        }
        return;
    }
    {
        fn_1_53C9C((u8 *)&panelColor,
            lbl_1_rodata_6BAC, lbl_1_rodata_6BB0, lbl_1_rodata_6BB4, lbl_1_rodata_6BB8, lbl_1_rodata_6BBC,
            fzgx_pool_init_lbl_1_data_3E514[lbl_801A66B4]);
    }
    if (count < 7) {
        height = count * 244 / 7;
        fn_1_53B14((u8 *)&panelColor, lbl_1_rodata_6BC0,
            (f32)(210 - ((244 - height) >> 1)), lbl_1_rodata_6BC4,
            (f32)(height + 10), lbl_1_rodata_6BA0);
        fn_1_BFE20(0x265, 0x58, lbl_1_rodata_6BC8, lbl_1_rodata_6BCC,
            (f32)height, lbl_1_rodata_6B60, lbl_1_rodata_6BD0);
    } else {
        fn_1_53B14((u8 *)&panelColor, lbl_1_rodata_6BC0, lbl_1_rodata_6BA4,
            lbl_1_rodata_6BC4, lbl_1_rodata_6BA8, lbl_1_rodata_6BA0);
        fn_1_BFE20(0x265, 0x58, lbl_1_rodata_6BC8, lbl_1_rodata_6BCC,
            lbl_1_rodata_6BD4, (f32)(s32)(*(u32 *)&lbl_1_bss_7EA00__fzgx_offset_10) / (f32)count, lbl_1_rodata_6BD8 / (f32)count);
    }
    if ((lbl_1_bss_9F8.unk_8 >> 10) & 1) {
        if (lbl_1_bss_7EA00 == 0 && hasStaff) {
            index = 0;
        } else {
            matches = 0;
            for (index = 0; index < 127; index++) {
                if (lbl_1_bss_8B3A0.unk_90 == ((GhostRow *)((u8 *)&fzgx_obj_lbl_1_bss_7B1AC))[index].course) {
                    if (hasStaff) {
                        if (matches == (u32)lbl_1_bss_7EA00 - 1) { index++; break; }
                    } else {
                        if (matches == lbl_1_bss_7EA00) { index++; break; }
                    }
                    matches++;
                }
            }
        }
        marked = index;
        if ((s32)ghost_test_flag(index) == 0) fn_1_A2D84(0xA9011100);
        else fn_1_A2D84(0xA9011000);
        if ((s32)ghost_test_flag(marked) == 0) {
            int activeCount = 0;
            for (i = 0; i < 127; i++) {
                if ((u32)activeCount >= 4) fn_1_F1E30(i);
                if ((s32)ghost_test_flag(i) != 0) activeCount++;
            }
        }
        fn_1_F1ED0(marked);
    }
    if (((lbl_1_bss_9F8.unk_10 >> 3) & 1) || ((lbl_1_bss_9F8.unk_12 >> 3) & 1)) {
        fn_1_A2D84(0xA9011300);
        lbl_1_bss_7EA00 = (lbl_1_bss_7EA00 + count - 1) % count;
    } else if (((lbl_1_bss_9F8.unk_10 >> 2) & 1) || ((lbl_1_bss_9F8.unk_12 >> 2) & 1)) {
        fn_1_A2D84(0xA9011300);
        lbl_1_bss_7EA00 = (lbl_1_bss_7EA00 + count + 1) % count;
    }
    cursor = lbl_1_bss_7EA00;
    if (cursor < (s32)(*(u32 *)&lbl_1_bss_7EA00__fzgx_offset_10)) (*(u32 *)&lbl_1_bss_7EA00__fzgx_offset_10) = cursor;
    if (cursor - (s32)(*(u32 *)&lbl_1_bss_7EA00__fzgx_offset_10) > 6) (*(u32 *)&lbl_1_bss_7EA00__fzgx_offset_10) = cursor - 6;
    if ((s32)(*(u32 *)&lbl_1_bss_7EA00__fzgx_offset_10) < 0) (*(u32 *)&lbl_1_bss_7EA00__fzgx_offset_10) = 0;
    if ((*(u32 *)&lbl_1_bss_7EA00__fzgx_offset_10) > count - 7) (*(u32 *)&lbl_1_bss_7EA00__fzgx_offset_10) = count - 7;
    if (count > 7) {
        if ((s32)(*(u32 *)&lbl_1_bss_7EA00__fzgx_offset_10) > 0) {
            arrow = *(DrawPacket *)lbl_1_rodata_26F8;
            PW(arrow,0) = 0x9A00;
            PF(arrow,4) = lbl_1_rodata_6BDC;
            PF(arrow,8) = lbl_1_rodata_6BE0;
            PW(arrow,0x30) = 10;
            PW(arrow,0x38) = lbl_1_rodata_6B74;
            PH(arrow,0x28) = 0x4000;
            PF(arrow,0x10) *= lbl_1_rodata_6BE8 + lbl_1_rodata_6BF0 * __fabs(lbl_8006D188((s16)(lbl_801A66A0 << 9)));
            PF(arrow,0x14) *= lbl_1_rodata_6BE8 + lbl_1_rodata_6BF0 * __fabs(lbl_8006D188((s16)(lbl_801A66A0 << 9)));
            PF(arrow,0x2C) = lbl_1_rodata_6BF8 - lbl_1_rodata_6C00 * __fabs(lbl_8006D188((s16)(lbl_801A66A0 << 9)));
            fn_1_4F734(&arrow.packet);
        }
        if ((*(u32 *)&lbl_1_bss_7EA00__fzgx_offset_10) < count - 7) {
            arrow = *(DrawPacket *)lbl_1_rodata_26F8;
            PW(arrow,0) = 0x9A00;
            PF(arrow,4) = lbl_1_rodata_6BDC;
            PF(arrow,8) = lbl_1_rodata_6C08;
            PW(arrow,0x30) = 10;
            PW(arrow,0x38) = lbl_1_rodata_6B78;
            PH(arrow,0x28) = -0x4000;
            PF(arrow,0x10) *= lbl_1_rodata_6BE8 + lbl_1_rodata_6BF0 * __fabs(lbl_8006D188((s16)(lbl_801A66A0 << 9)));
            PF(arrow,0x14) *= lbl_1_rodata_6BE8 + lbl_1_rodata_6BF0 * __fabs(lbl_8006D188((s16)(lbl_801A66A0 << 9)));
            PF(arrow,0x2C) = lbl_1_rodata_6BF8 - lbl_1_rodata_6C00 * __fabs(lbl_8006D188((s16)(lbl_801A66A0 << 9)));
            fn_1_4F734(&arrow.packet);
        }
    }
    selection = *(DrawPacket *)lbl_1_rodata_26F8;
    PW(selection,0) = 18;
    PF(selection,0x10) = lbl_1_rodata_6C0C;
    PF(selection,0x14) = lbl_1_rodata_6C10;
    PF(selection,4) = lbl_1_rodata_6C14;
    PF(selection,8) = (f32)(88 + (lbl_1_bss_7EA00 - (s32)(*(u32 *)&lbl_1_bss_7EA00__fzgx_offset_10)) * 35);
    PF(selection,0x2C) = lbl_1_rodata_6C18;
    selectionColor = lbl_1_rodata_6B7C;
    ((u8 *)&selectionColor)[2] = lbl_1_rodata_6C20 + lbl_1_rodata_6C28 * __fabs(lbl_8006D188((s16)(lbl_801A66A0 << 9)));
    PF(selection,0xc) = lbl_1_rodata_6C30;
    PW(selection,0x38) = selectionColor;
    fn_1_4F734(&selection.packet);
    fn_1_49410();
    fn_1_49614();
    fn_1_4955C(lbl_1_rodata_6C34, lbl_1_rodata_6C34);
    fn_1_4966C(lbl_1_rodata_6C38, lbl_1_rodata_6B60);
    fn_1_4954C(lbl_1_rodata_6C3C);
    if ((s32)lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(lbl_1_rodata_6BBC);
        fn_1_4966C(lbl_1_rodata_6B60, lbl_1_rodata_6B60);
    }
    if (count != 0) {
        current = (*(u32 *)&lbl_1_bss_7EA00__fzgx_offset_10);
        shown = 0;
        row = 0;
        while (current < 127) {
            if (shown <= 6) {
                if (current == 0 && hasStaff) {
                    fn_1_12EF80(lbl_1_bss_8B3A0.unk_90, &courseA, &courseB);
                    courseIndex = courseB + (courseA - 1) * 6;
                    if ((s32)lbl_801A66B4 != 5) fn_1_4966C(lbl_1_rodata_6B60, lbl_1_rodata_6B60);
                    if ((s32)ghost_test_flag(0) != 0) {
                        staffOnColor = lbl_1_rodata_6B80;
                        fn_1_49514((u32 *)&staffOnColor);
                    } else {
                        staffOffColor = lbl_1_rodata_6B84;
                        fn_1_49514((u32 *)&staffOffColor);
                    }
                    fn_1_496FC(lbl_1_rodata_6C40, (f32)(row + 92));
                    fn_1_4AE0C(fzgx_pool_init_lbl_1_data_3E4DC.v[lbl_801A66B4]);
                    fn_1_496FC(lbl_1_rodata_6C44, (f32)(row + 105));
                    fn_1_4966C(lbl_1_rodata_6C38, lbl_1_rodata_6B60);
                    courseIndex = lbl_1_data_3E5B4[courseIndex];
                    fn_1_4AE0C(fzgx_pool_init_lbl_1_data_3E718.v, (courseIndex >> 20) & 255, (courseIndex >> 12) & 255, courseIndex & 4095);
                    if (fn_1_F2280(lbl_1_bss_8B3A0.unk_90)) {
                        badge = *(DrawPacket *)lbl_1_rodata_26F8;
                        PW(badge,0) = 0xA107;
                        PW(badge,0x30) = 10;
                        PF(badge,0x18) = lbl_1_rodata_6BBC;
                        PF(badge,0x20) = lbl_1_rodata_6C48;
                        PF(badge,4) = lbl_1_rodata_6C4C;
                        PF(badge,8) = (f32)(row + 99);
                        if (__fabs(lbl_8006D188((s16)(lbl_801A66A0 << 9))) < lbl_1_rodata_6C50) {
                            pulse = lbl_1_rodata_6C50;
                        } else if (__fabs(lbl_8006D188((s16)(lbl_801A66A0 << 9))) > lbl_1_rodata_6BF8) {
                            pulse = lbl_1_rodata_6BF8;
                        } else {
                            pulse = __fabs(lbl_8006D188((s16)(lbl_801A66A0 << 9)));
                        }
                        PF(badge,0x10) = lbl_1_rodata_6C58 * (lbl_1_rodata_6C60 * pulse);
                        PF(badge,0x14) = lbl_1_rodata_6C68;
                        badgeColor = lbl_1_rodata_6B88;
                        ((u8 *)&badgeColor)[0] = lbl_1_rodata_6C70 + lbl_1_rodata_6C78 * __fabs(lbl_8006D188((s16)(lbl_801A66A0 << 9)));
                        ((u8 *)&badgeColor)[1] = lbl_1_rodata_6C70 + lbl_1_rodata_6C78 * __fabs(lbl_8006D188((s16)(lbl_801A66A0 << 9)));
                        ((u8 *)&badgeColor)[2] = lbl_1_rodata_6C70 + lbl_1_rodata_6C78 * __fabs(lbl_8006D188((s16)(lbl_801A66A0 << 9)));
                        PF(badge,0xc) = lbl_1_rodata_6C80;
                        PW(badge,0x38) = badgeColor;
                        fn_1_4F734(&badge.packet);
                    }
                    shown++;
                    row += 35;
                } else {
                    if ((s32)lbl_801A66B4 != 5) fn_1_4966C(lbl_1_rodata_6B60, lbl_1_rodata_6B60);
                    matches = 0;
                    for (index = 0; index < 127; index++) {
                        if (lbl_1_bss_8B3A0.unk_90 == ((GhostRow *)((u8 *)&fzgx_obj_lbl_1_bss_7B1AC))[index].course) {
                            if (hasStaff) {
                                if (matches == current - 1) { index++; break; }
                            } else {
                                if (matches == current) { index++; break; }
                            }
                            matches++;
                        }
                    }
                    if (index < 127) {
                        if ((s32)ghost_test_flag(index) != 0) {
                            ghostOnColor = lbl_1_rodata_6B8C;
                            fn_1_49514((u32 *)&ghostOnColor);
                        } else {
                            ghostOffColor = lbl_1_rodata_6B90;
                            fn_1_49514((u32 *)&ghostOffColor);
                        }
                        entry = (u8 *)&((GhostRow *)((u8 *)&fzgx_obj_lbl_1_bss_7B1AC))[index];
                        if (entry[-0x25]) {
                            fn_1_496FC(lbl_1_rodata_6C40, (f32)(row + 92));
                            if (entry[-0x28] >= 0x29 && entry[-0x28] < 0x3a)
                                fn_1_4AE0C(fzgx_pool_init_lbl_1_data_3E728.v, fzgx_pool_init_lbl_1_data_3E4A4.v[lbl_801A66B4]);
                            else
                                fn_1_4AE0C(fzgx_pool_init_lbl_1_data_3E728.v, fn_1_7F49C(entry[-0x28], (s16)lbl_801A66B4, name));
                            fn_1_4966C(lbl_1_rodata_6C38, lbl_1_rodata_6B60);
                            fn_1_496FC(lbl_1_rodata_6C44, (f32)(row + 105));
                            fn_1_4AE0C(fzgx_pool_init_lbl_1_data_3E718.v, entry[-4], entry[-3], *(u16 *)(entry-2));
                            shown++;
                            row += 35;
                        }
                    }
                }
            }
            current++;
        }
    }
    fn_1_49410();
    fn_1_49614();
}
/* fzgx:end fn_1_EB8F4 */

/* fzgx:begin fn_1_EC900 */
// Return the current ghost state value.
u32 fn_1_EC900(void) {
    return lbl_1_bss_7B1A4;
}
/* fzgx:end fn_1_EC900 */

/* fzgx:begin fn_1_EC910 pool noprologue */
#include "dolphin/types.h"

typedef struct {
    u8 kind;          /* 0x00 */
    u8 pad_1[0x3];
    u8 b4;            /* 0x04 */
    u8 b5;            /* 0x05 */
    u8 b6;            /* 0x06 */
    u8 b7;            /* 0x07 */
    u32 w8[4];        /* 0x08 */
    u16 count;        /* 0x18 */
    u16 pad_1A;
    u32 w1C[3];       /* 0x1C */
} GhostRecord;

typedef struct {
    u8 pad_0[0x90];
    s16 unk_90;
} GhostLoadState;

extern GhostLoadState lbl_1_bss_8B3A0;
extern void *lbl_801A6410;

extern int sprintf(char *, const char *, ...);
extern s32 fn_1_F21B8(s32);
extern s32 ghost_test_flag(s32);
extern void fn_1_46B4(void *, void *, const char *, int);
extern void *fn_1_4630(void *, u32, const char *, int);
extern void fn_1_F1960(u32, void *, u32);
extern void fn_1_F1D70(void);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_80008BEC(void *, int, u32);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_7B180[2];
u32 lbl_1_bss_7B180__fzgx_offset_8[7];
s32 lbl_1_bss_7B180__fzgx_offset_24;            /* load pending */
u32 lbl_1_bss_7B180__fzgx_offset_28;
GhostRecord lbl_1_bss_7B180__fzgx_offset_2C[127];  /* ghost headers */
void *lbl_1_bss_7B180__fzgx_offset_1404[127];      /* ghost data buffers */
void *lbl_1_bss_7B180__fzgx_offset_1600[5];
void *lbl_1_bss_7B180__fzgx_offset_1614[5];
void *lbl_1_bss_7B180__fzgx_offset_1628[5];
void *lbl_1_bss_7B180__fzgx_offset_163C[5];
void *lbl_1_bss_7B180__fzgx_offset_1650[5];
void *lbl_1_bss_7B180__fzgx_offset_1664[5];
void *lbl_1_bss_7B180__fzgx_offset_1678[5];
void *lbl_1_bss_7B180__fzgx_offset_168C[5];
void *lbl_1_bss_7B180__fzgx_offset_16A0[5];
u32 lbl_1_bss_7B180__fzgx_offset_16B4[6];
u8 lbl_1_bss_7B180__fzgx_offset_16CC;
u8 lbl_1_bss_7B180__fzgx_offset_16CD;
u16 lbl_1_bss_7B180__fzgx_offset_16CE;
u32 lbl_1_bss_7B180__fzgx_offset_16D0[31];
u8 lbl_1_bss_7B180__fzgx_offset_174C;
u8 lbl_1_bss_7B180__fzgx_offset_174D;
u8 lbl_1_bss_7B180__fzgx_offset_174E;           /* loaded ghost count */
u8 lbl_1_bss_7B180__fzgx_offset_174F;
u32 lbl_1_bss_7B180__fzgx_offset_1750;
u8 lbl_1_bss_7B180__fzgx_offset_1754;
u8 lbl_1_bss_7B180__fzgx_offset_1755;
u16 lbl_1_bss_7B180__fzgx_offset_1756;
u32 lbl_1_bss_7B180__fzgx_offset_1758[30];
struct { s16 value[5]; } lbl_1_bss_7B180__fzgx_offset_17D0;
u16 lbl_1_bss_7B180__fzgx_offset_17DA;
struct { u32 value[5]; } lbl_1_bss_7B180__fzgx_offset_17DC;
struct { u8 value[5][3]; } lbl_1_bss_7B180__fzgx_offset_17F0;

extern void fn_1_ECE00(void);
extern void fn_1_ECF68(void);
extern void fn_1_ED540(void);
extern void fn_1_EE530(void);
extern void fn_1_EF0A0(void);
extern void fn_1_EF5E0(void);
extern void fn_1_EF768(void);
extern void fn_1_EF860(void);
extern void fn_1_EF924(void);
extern void fn_1_EF97C(void);
extern void fn_1_EFA1C(void);
extern void fn_1_EF0A8(void);
extern void fn_1_EF488(void);
extern void fn_1_EF4F8(void);
extern void fn_1_EFA8C(void);
extern void ghost_reset(void);
extern void fn_1_F0168(void);

/* the retail TU's .data up to this function's last string: MWCC addresses it off one section base */
u32 fzgx_pool_table_0[55] = {
    0x4F564552, 0x54414B45, 0x00000000, 0x4A554D50,
    0x00000000, 0x454E454D, 0x59484954, 0x00000000,
    0x57414C4C, 0x48495400, 0x53494445, 0x42595349,
    0x44450000, 0x53544152, 0x54000000, 0x474F414C,
    0x00000000, 0x4C415000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x67686F73, 0x7430302E,
    0x62696E00, 0x67686F73, 0x7430312E, 0x62696E00,
    0x67686F73, 0x7430322E, 0x62696E00, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000,
};
u32 fzgx_pool_funcs_DC[17] = { 0 };
u32 fzgx_pool_table_120[5] = { 0x4F726967, 0x696E616C, 0x204D6163, 0x68696E65, 0x00000000 };
u32 fzgx_pool_table_134[1] = { 0x00000000 };
u32 fzgx_pool_table_138[5] = { 0x8349838A, 0x83578369, 0x838B837D, 0x83568393, 0x00000000 };
u32 fzgx_pool_ptrs_14C[6] = { 0 };
u32 fzgx_pool_table_164[3] = { 0x53746166, 0x66204768, 0x6F737400 };
u32 fzgx_pool_table_170[5] = { 0x8358835E, 0x83628374, 0x8353815B, 0x83588367, 0x00000000 };
u32 fzgx_pool_ptrs_184[6] = { 0 };
u32 fzgx_pool_table_19C[78] = {
    0x53454C45, 0x43542047, 0x484F5354, 0x00000000,
    0x47484F53, 0x54205345, 0x4C454354, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0xFFFFFFFF, 0xFFFFFFFF,
    0xFFFF0000, 0xFFFFFFFF, 0x0000000C, 0x0000001D,
    0x0000000E, 0x00000017, 0x00000004, 0x00000000,
    0x00000016, 0x0000001D, 0x0000000C, 0x00000017,
    0x00000016, 0x00000000, 0x0000001D, 0x0000001B,
    0x00000004, 0x0000000F, 0x00000004, 0x00000000,
    0x0000001D, 0x00000011, 0x00000015, 0x0000000C,
    0x00000014, 0x00000000, 0x00000027, 0x00000005,
    0x0000001F, 0x00000004, 0x00000028, 0x0000001F,
    0x0003B3C4, 0x000382B3, 0x001382E7, 0x0013B38B,
    0x0020F129, 0x00000000, 0x0010714B, 0x002192B1,
    0x001230A9, 0x0021A322, 0x0011A225, 0x00000000,
    0x0022838D, 0x00218381, 0x0023B075, 0x00232128,
    0x00232328, 0x00000000, 0x0023A28A, 0x00209351,
    0x00206394, 0x0023B04C, 0x0020310C, 0x00000000,
    0x001062B2, 0x001260B2, 0x00206345, 0x00312110,
    0x003322E4, 0x0002E37D,
};
char fzgx_pool_str_2D4[8] = "ghost.c";
char fzgx_pool_str_2DC[12] = "GhostCalc";
char fzgx_pool_str_2E8[12] = "GhostDisp";
char fzgx_pool_str_2F4[16] = "story_ghost/%s";
char fzgx_pool_str_304[24] = "StoryGhost : %s  %d\n";
char fzgx_pool_str_31C[28] = "./staff_ghost/ghost%d.dat";
char fzgx_pool_str_338[16] = "pcarobj[%d]\n";
char fzgx_pool_str_348[12] = "carobj[%d]\n";
char fzgx_pool_str_354[16] = "save_\?\?\?[%d]\n";
char fzgx_pool_str_364[16] = "vehicle_parts/";
char fzgx_pool_str_374[4] = "..";
char fzgx_pool_str_378[20] = "vehicle/%s_e.arc.lz";
char fzgx_pool_str_38C[20] = "vehicle/%s_p.arc.lz";
char fzgx_pool_str_3A0[12] = "vehicle/";
char fzgx_pool_str_3AC[20] = "result_code: %d\n";
char fzgx_pool_str_3C0[16] = "%02d:%02d:%03d";
char fzgx_pool_str_3D0[4] = "%s";
char fzgx_pool_str_3D4[16] = "ghost_data[%d]\n";

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B180;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_24;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_28;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_2C;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1404;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1600;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1614;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1628;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_163C;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1650;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1664;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1678;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_168C;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_16A0;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_16B4;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_16CC;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_16CD;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_16CE;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_16D0;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_174C;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_174D;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_174E;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_174F;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1750;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1754;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1755;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1756;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1758;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_17D0;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_17DA;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_17DC;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_17F0;
}
#pragma section code_type ".text"

#define ghostFile    fzgx_pool_str_2D4
#define ghostPending lbl_1_bss_7B180__fzgx_offset_24
#define ghostRecords lbl_1_bss_7B180__fzgx_offset_2C
#define ghostData    lbl_1_bss_7B180__fzgx_offset_1404
#define ghostId      lbl_1_bss_7B180__fzgx_offset_16CC
#define ghostCount   lbl_1_bss_7B180__fzgx_offset_174E
#define ghostLoaded  lbl_1_bss_7B180__fzgx_offset_1754
#define ghostKinds   lbl_1_bss_7B180__fzgx_offset_17D0.value
#define ghostVals    lbl_1_bss_7B180__fzgx_offset_17DC.value
#define ghostAttrs   lbl_1_bss_7B180__fzgx_offset_17F0.value

#define FREE_BUF(arr, line)                                         \
    if (arr[i] != NULL) {                                           \
        fn_1_46B4(lbl_801A6410, arr[i], ghostFile, line);           \
        arr[i] = NULL;                                              \
    }

void fn_1_EC910(void)
{
    char textA[256];
    char textB[256];
    char textC[256];
    GhostLoadState *state;
    GhostRecord *rec;
    u8 *p;
    u32 i;
    u32 n;

    if (ghostPending == 0) {
        return;
    }
    state = &lbl_1_bss_8B3A0;
    ghostCount = 0;
    n = state->unk_90;
    ghostPending = 0;
    ghostId = 0xff;
    if (fn_1_F21B8(n) != 0 && ghost_test_flag(0) != 0) {
        sprintf(textA, fzgx_pool_str_31C, ghostId = state->unk_90);
    }

    for (i = 0; i < 5; i++) {
        FREE_BUF(lbl_1_bss_7B180__fzgx_offset_1600, 0x85a)
        FREE_BUF(lbl_1_bss_7B180__fzgx_offset_1614, 0x85b)
        FREE_BUF(lbl_1_bss_7B180__fzgx_offset_1628, 0x85c)
        FREE_BUF(lbl_1_bss_7B180__fzgx_offset_163C, 0x85d)
        FREE_BUF(lbl_1_bss_7B180__fzgx_offset_1650, 0x85e)
        FREE_BUF(lbl_1_bss_7B180__fzgx_offset_1664, 0x85f)
        FREE_BUF(lbl_1_bss_7B180__fzgx_offset_1678, 0x860)
        FREE_BUF(lbl_1_bss_7B180__fzgx_offset_168C, 0x861)
        FREE_BUF(lbl_1_bss_7B180__fzgx_offset_16A0, 0x862)
        sprintf(textB, fzgx_pool_str_354, i);
    }

    ghostCount = 0;
    for (i = 0; i < 5; i++) {
        ghostKinds[i] = -1;
        ghostVals[i] = 0;
        ghostAttrs[i][0] = 0;
        ghostAttrs[i][1] = 0;
        ghostAttrs[i][2] = 0;
    }

    for (i = 0; i < 127; i++) {
        if (ghost_test_flag(i + 1) != 0) {
            rec = &ghostRecords[i];
            n = ghostCount;
            ghostAttrs[n][0] = rec->b5;
            ghostAttrs[n][1] = rec->b6;
            ghostKinds[n] = rec->kind;
            ghostVals[n] = rec->b4;
            ghostAttrs[n][2] = rec->b7;
            p = fn_1_4630(lbl_801A6410, 0x3ec0, ghostFile, 0x87f);
            fn_80008BEC(p, 0, 0x3ea8);
            *(GhostRecord *)p = *rec;
            fn_80008BA8(p + 0x28, ghostData[i], rec->count << 4);
            fn_1_F1960(0xf24000 + ghostCount * 0x3ec0, p, 0x3ec0);
            fn_1_46B4(lbl_801A6410, p, ghostFile, 0x895);
            ghostCount++;
        }
    }

    ghostLoaded = ghostCount;
    if (fn_1_F21B8(state->unk_90) != 0 && ghost_test_flag(0) != 0) {
        ghostCount++;
    }

    for (i = 0; i < 127; i++) {
        if (ghostData[i] != NULL) {
            fn_1_46B4(lbl_801A6410, ghostData[i], ghostFile, 0x8b0);
            sprintf(textC, fzgx_pool_str_3D4, i);
            ghostData[i] = NULL;
        }
    }
    fn_1_F1D70();
}
/* fzgx:end fn_1_EC910 */

/* fzgx:begin fn_1_ECDFC */
// fn_1_ECDFC: empty in retail (single blr).
void fn_1_ECDFC(void) {
}
/* fzgx:end fn_1_ECDFC */

/* fzgx:begin fn_1_ECE00 */
// fn_1_ECE00: empty in retail (single blr).
void fn_1_ECE00(void) {
}
/* fzgx:end fn_1_ECE00 */

/* fzgx:begin fn_1_ECF68 */
void fn_1_ECF68(void) {
    fn_1_F23E8();
}
/* fzgx:end fn_1_ECF68 */

/* fzgx:begin fn_1_ECF88 noprologue */
#include "types.h"
#include "rel/main_rel/ghost.h"
#include "game/main_rel/ghost_types.h"
#include "game/vec3.h"

#pragma fp_contract on

extern const f32 lbl_1_rodata_6C94;
extern const f32 lbl_1_rodata_6BD0;
extern const f64 lbl_1_rodata_6C98;
extern const f64 lbl_1_rodata_6CA0;
/* Volatile: retail reloads the shared lap threshold in the second branch. */
extern const volatile f64 lbl_1_rodata_6CA8;
extern const f64 lbl_1_rodata_6CB0;
extern const f32 lbl_1_rodata_6CB8;
extern f32 lbl_8006D0B4(f32);
extern f32 __fmadds(f32, f32, f32);
extern s32 fn_1_3F164(void);
extern s32 fn_1_F17B4(const void *);
extern u32 fn_1_F1588(void);
extern void *fn_1_86254(int);
extern void fn_1_8645C(int, void *);
extern void fn_1_F0B5C(u32, void *);
extern void fn_1_F0D10(u32, u32);
extern void fn_1_F0E00(u32, void *);
extern void fn_1_F143C(FnObject *, s32, const f32 *, const f32 *, void *);
extern void fn_80008BEC(void *, int, u32);
extern void fn_8006F5C4(s16 *, s16 *, s16 *);
extern void ghost_pack_bits(u32 *, const u32 *, const u32 *, const u32 *);
extern void lbl_8006DBAC(Vec3 *);

#pragma fp_contract on
void fn_1_ECF88(void) {
    Obj_1_bss_7B180 *p_lbl_1_bss_7B180;
    u32 v0;
    u32 v1;
    void *v3;
    u32 v8;
    f32 v9;
    f32 v14;
    void *v37;
    void *v36;
    u32 *v35;
    u32 *v34;
    u32 *v33;
    u16 *v32;
    void *v31;
    void *v30;
    void *v29;
    u32 v28;
    void *v19;
    u32 v38;
    u16 v39;
    u8 v42;
    s32 v46;
    u32 v44;
    f32 loc_1C[3][4];
    u32 loc_18;
    u32 loc_14;
    u32 loc_10;
    s16 loc_C;
    s16 loc_A;
    s16 loc_8;

    p_lbl_1_bss_7B180 = &lbl_1_bss_7B180;
    v0 = p_lbl_1_bss_7B180->unk_1820;
    v1 = ((v0 / 40 + p_lbl_1_bss_7B180->unk_38B4) << 4) + 40;
    if (v0 >= 28800 || v1 > 16000) {
        p_lbl_1_bss_7B180->unk_10 = 1;
    } else {
        p_lbl_1_bss_7B180->unk_38BC = lbl_1_rodata_6BD0 - (f32)v1 / lbl_1_rodata_6C94;
        v3 = fn_1_86254(0);
        {
            /* These flag reads are separate snapshots in the retail code. */
            u32 mask = -((*(volatile u32 *)v3 >> 2) & 1);
            p_lbl_1_bss_7B180->unk_38C0 = (p_lbl_1_bss_7B180->unk_38C0 + 1) & mask;
        }
        /* Volatile: this flag read is a separate snapshot after the counter update. */
        if ((*(volatile u32 *)v3 & 8) != 0) {
            p_lbl_1_bss_7B180->unk_38B8++;
        } else if (p_lbl_1_bss_7B180->unk_38B8 != 0) {
            p_lbl_1_bss_7B180->unk_38B8 = 0;
        }
        if ((s32)fn_1_F1588() != 0) {
            *(u8 *)p_lbl_1_bss_7B180->unk_38B0 = 1;
        } else {
            v1 = *(u32 *)v3;
            if ((v1 & 4) != 0 && (s32)p_lbl_1_bss_7B180->unk_38C0 < 3) {
                for (v8 = p_lbl_1_bss_7B180->unk_0 - 14; v8 < p_lbl_1_bss_7B180->unk_0 - 10; v8++) {
                    if ((s32)v8 > 0) {
                        *(u8 *)(p_lbl_1_bss_7B180->unk_16E8 + v8) = 1;
                    }
                }
                p_lbl_1_bss_7B180->unk_14 = 1;
                *(u8 *)p_lbl_1_bss_7B180->unk_38B0 = 1;
            } else {
                if ((v1 & 0x800000) != 0 || (v1 & 0x10) != 0) {
                    f32 y = *(f32 *)((u8 *)v3 + 152);
                    v9 = *(f32 *)((u8 *)v3 + 148) * *(f32 *)((u8 *)v3 + 148);
                    v9 = __fmadds(y, y, v9);
                    v9 = __fmadds(*(f32 *)((u8 *)v3 + 156), *(f32 *)((u8 *)v3 + 156), v9);
                    v9 = lbl_8006D0B4(v9);
                    {
                    f64 speed = v9 / *(f32 *)((u8 *)v3 + 8);
                    if (lbl_1_rodata_6C98 * speed > lbl_1_rodata_6CA0) {
                        p_lbl_1_bss_7B180->unk_14 = 1;
                        *(u8 *)p_lbl_1_bss_7B180->unk_38B0 = 1;
                        /* Goto: this successful speed test skips the remaining flag tests. */
                        goto packed_flag;
                    }
                    }
                }
                if (*(u16 *)((u8 *)v3 + 532) == 60) {
                    p_lbl_1_bss_7B180->unk_14 = 1;
                    *(u8 *)p_lbl_1_bss_7B180->unk_38B0 = 1;
                } else if ((s32)p_lbl_1_bss_7B180->unk_14 != 0) {
                    p_lbl_1_bss_7B180->unk_14 = 0;
                    *(u8 *)p_lbl_1_bss_7B180->unk_38B0 = 1;
                } else {
                    *(u8 *)p_lbl_1_bss_7B180->unk_38B0 = 0;
                }
            }
        }
packed_flag:
        if (*(u8 *)p_lbl_1_bss_7B180->unk_38B0 != 0) {
            p_lbl_1_bss_7B180->unk_38B4++;
        }
        fn_1_8645C(0, loc_1C);
        lbl_8006DBAC((Vec3 *)loc_1C);
        fn_8006F5C4(&loc_8, &loc_A, &loc_C);
        *(u8 *)(p_lbl_1_bss_7B180->unk_38AC + 2) = loc_C >> 8;
        *(u16 *)(p_lbl_1_bss_7B180->unk_38AC + 4) = loc_A;
        *(u8 *)(p_lbl_1_bss_7B180->unk_38AC + 3) = loc_8 >> 8;
        *(u8 *)p_lbl_1_bss_7B180->unk_38AC = p_lbl_1_bss_7B180->unk_0 - p_lbl_1_bss_7B180->unk_4;
        loc_18 = fn_1_F17B4(&loc_1C[0][3]);
        loc_14 = fn_1_F17B4(&loc_1C[1][3]);
        loc_10 = fn_1_F17B4(&loc_1C[2][3]);
        ghost_pack_bits((u32 *)(p_lbl_1_bss_7B180->unk_38AC + 8), &loc_18, &loc_14, &loc_10);

        v14 = *(f32 *)(p_lbl_1_bss_7B180->unk_3898 + 256) / *(f32 *)(p_lbl_1_bss_7B180->unk_3898 + 252);
        p_lbl_1_bss_7B180->unk_38A0 = v14;
        if (lbl_1_rodata_6CA8 < v14 && p_lbl_1_bss_7B180->unk_389C < lbl_1_rodata_6CB0) {
            p_lbl_1_bss_7B180->unk_38A4--;
        } else if (lbl_1_rodata_6CA8 < p_lbl_1_bss_7B180->unk_389C && v14 < lbl_1_rodata_6CB0) {
            p_lbl_1_bss_7B180->unk_38A4++;
        }
        p_lbl_1_bss_7B180->unk_389C = v14;
        *(u8 *)(p_lbl_1_bss_7B180->unk_38AC + 1) = p_lbl_1_bss_7B180->unk_38A4;
        *(u16 *)(p_lbl_1_bss_7B180->unk_38AC + 6) = (s32)(lbl_1_rodata_6CB8 * p_lbl_1_bss_7B180->unk_38A0);
        p_lbl_1_bss_7B180->unk_38AC += 16;
        p_lbl_1_bss_7B180->unk_38B0++;
        p_lbl_1_bss_7B180->unk_1820++;
        p_lbl_1_bss_7B180->unk_4 = p_lbl_1_bss_7B180->unk_0;
        p_lbl_1_bss_7B180->unk_0++;

        if ((s32)lbl_1_data_3E52C == 2) {
            v19 = &p_lbl_1_bss_7B180->unk_39F0;
            v37 = p_lbl_1_bss_7B180->arr_38C4;
            v36 = &p_lbl_1_bss_7B180->unk_39B4;
            v35 = v19;
            v34 = &p_lbl_1_bss_7B180->unk_1600;
            v33 = &p_lbl_1_bss_7B180->unk_1824;
            v32 = &p_lbl_1_bss_7B180->unk_1800;
            v31 = p_lbl_1_bss_7B180->arr_3A04;
            v30 = p_lbl_1_bss_7B180->arr_3AF4;
            v29 = p_lbl_1_bss_7B180->arr_19C8;
            for (v28 = 0; (u32)v28 < p_lbl_1_bss_7B180->unk_174E; v28++) {
                fn_1_F0D10(v28, (u32)v37);
                fn_1_F0B5C(v28, v36);
                fn_1_F0E00(v28, v35);
                if (fn_1_3F164() == 0) {
                    v39 = *v32;
                    if ((f32)v39 < ((f32 *)*v34)[*v33 - 1]) {
                        *v32 = v39 + 1;
                    }
                }
                fn_1_F0D10(v28, (u32)v31);
                fn_1_F0B5C(v28, v30);
                if ((s32)p_lbl_1_bss_7B180->unk_17C8 != 0) {
                    fn_1_F143C((FnObject *)v29, v28, (const f32 *)v30, (const f32 *)v36, v31);
                } else {
                    fn_80008BEC(v29, 0, 1568);
                }
                v37 = (u8 *)v37 + 48;
                v36 = (u8 *)v36 + 12;
                v35++;
                v34++;
                v33++;
                v32++;
                v31 = (u8 *)v31 + 48;
                v30 = (u8 *)v30 + 12;
                v29 = (u8 *)v29 + 1568;
            }
            if ((*(u32 *)v3 & 0x40000) != 0) {
                /* Keep the current-lap snapshot for the following comparisons. */
                s32 currentLap;
                /* Volatile: retain this lap snapshot for both comparisons below. */
                if ((s8)p_lbl_1_bss_7B180->unk_38A5 != (currentLap = *(volatile s8 *)&p_lbl_1_bss_7B180->unk_38A4)) {
                    v42 = p_lbl_1_bss_7B180->unk_38A6;
                    if (currentLap > (s8)v42 && (s8)v42 < 3) {
                        p_lbl_1_bss_7B180->unk_38A6 = v42 + 1;
                        p_lbl_1_bss_7B180->unk_38A8 = 120;
                        v46 = 0xF0000001;
                        p_lbl_1_bss_7B180->unk_3B30 = v46;
                        for (v44 = 0; v44 < p_lbl_1_bss_7B180->unk_174E; v44++) {
                            if (v46 < *(s32 *)v19) {
                                v46 = *(s32 *)v19;
                            }
                            v19 = (u8 *)v19 + 4;
                        }
                        p_lbl_1_bss_7B180->unk_3B30 = v46;
                        if ((s32)p_lbl_1_bss_7B180->unk_16D4 != 0) {
                            p_lbl_1_bss_7B180->unk_3B30 = v46 + p_lbl_1_bss_7B180->unk_16D4;
                        }
                    }
                }
            }
            p_lbl_1_bss_7B180->unk_38A5 = p_lbl_1_bss_7B180->unk_38A4;
        }
    }
}
/* fzgx:end fn_1_ECF88 */

/* fzgx:begin fn_1_EE3F4 */
void fn_1_EE3F4(void) {
    u8 *base;
    void *unk_38c4;
    void *unk_39b4;
    void *unk_39f0;
    f32 **unk_1600;
    u32 *unk_1824;
    u16 *unk_1800;
    void *unk_3a04;
    void *unk_3af4;
    void *unk_19c8;
    s32 i;
    u16 value;
    f32 converted;
    base = (u8 *)&lbl_1_bss_7B180;
    i = 0;
    unk_38c4 = base + 0x38c4;
    unk_39b4 = base + 0x39b4;
    unk_39f0 = base + 0x39f0;
    unk_1600 = (f32 **)(base + 0x1600);
    unk_1824 = (u32 *)(base + 0x1824);
    unk_1800 = (u16 *)(base + 0x1800);
    unk_3a04 = base + 0x3a04;
    unk_3af4 = base + 0x3af4;
    unk_19c8 = base + 0x19c8;

    while ((u32)i < base[0x174e]) {
        fn_1_F0D10(i, unk_38c4);
        fn_1_F0B5C(i, unk_39b4);
        fn_1_F0E00(i, unk_39f0);
        if (!fn_1_3F164()) {
            value = *unk_1800;
            converted = (f32)(u32)value;
            if (converted < (*unk_1600)[*unk_1824 - 1]) {
                *unk_1800 = value + 1;
            }
        }
        fn_1_F0D10(i, unk_3a04);
        fn_1_F0B5C(i, unk_3af4);
        fn_1_F143C( (FnObject *)(void *)(unk_19c8), i, (const f32 *)(void *)(unk_3af4), (const f32 *)(void *)(unk_39b4), unk_3a04);
        unk_38c4 = (u8 *)unk_38c4 + 0x30;
        unk_39b4 = (u8 *)unk_39b4 + 0xc;
        unk_39f0 = (u8 *)unk_39f0 + 4;
        unk_1600++;
        unk_1824++;
        unk_1800++;
        unk_3a04 = (u8 *)unk_3a04 + 0x30;
        unk_3af4 = (u8 *)unk_3af4 + 0xc;
        unk_19c8 = (u8 *)unk_19c8 + 0x620;
        i++;
    }
}
/* fzgx:end fn_1_EE3F4 */

/* fzgx:begin fn_1_EE530 noprologue */
#include "types.h"
#include "rel/main_rel/ghost.h"
#include "psvec.h"

#pragma fp_contract on
typedef struct Sig_fn_1_87610_Fn187610Data {
 u8 pad_000[2]; s8 field_002; u8 pad_003[0x205]; u8 field_208[0x120];
} Sig_fn_1_87610_Fn187610Data;
typedef struct Sig_fn_1_87610_Fn187610Object {
 u8 pad_000[0x328]; s8 field_328; u8 pad_329[7]; void *field_330; u8 pad_334[0x86]; s16 field_3BA;
} Sig_fn_1_87610_Fn187610Object;
extern const f32 lbl_1_rodata_6B60, lbl_1_rodata_6BBC, lbl_1_rodata_6BD0, lbl_1_rodata_6C18;
extern const f32 lbl_1_rodata_6CEC, lbl_1_rodata_6CF0, lbl_1_rodata_6CF4, lbl_1_rodata_6CF8, lbl_1_rodata_6CFC, lbl_1_rodata_6D00;
extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D668(void *);
extern s32 fn_1_5910(void);
extern void OSPanic(const char *, int, const char *, ...);
extern void fn_1_14E5E4(u32, u32, f32);
extern void fn_1_556B8(void *);
extern void fn_1_55FF0(f32);
extern void fn_1_56000(u8,u8,u8);
extern void fn_1_5621C(f32,f32,f32,f32);
extern void fn_1_56298(f32,f32,f32,f32);
extern void fn_1_681C(u32,u32 *);
extern void fn_1_875B4(void *,void *,void *,f32);
extern void fn_1_875EC(void *,void *,void *,f32);
extern void fn_1_87610(Sig_fn_1_87610_Fn187610Object *,Sig_fn_1_87610_Fn187610Data *);
extern void fn_80072558(void);
extern void fn_80074A60(u32,u32);
extern void fn_80074A6C(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006DC20(void);
extern void lbl_8006DD14(void *,void *);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E14C(f32);
extern u32 lbl_8006DAEC(void);
extern u32 lbl_8006DCA4(void);
extern void lbl_8006E0A4(void *);

typedef struct { f32 x,y,z; } EEVec;
typedef struct { void **model; u32 a,b; } EEModel;
typedef struct { u8 pad[0x334]; EEModel models[3]; } EEObject;
#define eeclamp(x,lo,hi) ((x)<(lo)?(lo):((x)>(hi)?(hi):(x)))
static inline f32 eefade(f32 value) { return lbl_1_rodata_6CEC*(eeclamp(value-lbl_1_rodata_6CF4,lbl_1_rodata_6B60,lbl_1_rodata_6CF0)/lbl_1_rodata_6CF8); }
#pragma opt_common_subs off
#pragma opt_lifetimes off
void fn_1_EE530(void) {
 Obj_1_bss_7B180 *p_lbl_1_bss_7B180;
 u32 v2;
 f32 **v5;
 u32 *v6;
 u32 v7, v8, v10, v4, v3, v1;
 u32 v0;
 s32 v9;
 u32 v11;
 s32 v13;
 f32 v12;
 f32 v21;
 f32 v30,v29,v31,v32,v33,v34,v35;
 f32 dx;
 s8 v37;
 f32 loc_50[12];
 f32 loc_20[12];
 f32 loc_14[3];
 f32 loc_8[3];
 p_lbl_1_bss_7B180 = &lbl_1_bss_7B180;
 if ((s32)p_lbl_1_bss_7B180->unk_8 != 0) {
 if (p_lbl_1_bss_7B180->unk_174E <= 1) v0=0;
 else if (p_lbl_1_bss_7B180->unk_174E <= 3) v0=1;
 else v0=2;

 v1=(u32)p_lbl_1_bss_7B180->arr_38C4;
 v2=(u32)&p_lbl_1_bss_7B180->unk_39B4;
 v3=(u32)&p_lbl_1_bss_7B180->unk_39F0;
 v4=(u32)&p_lbl_1_bss_7B180->unk_1800;
 v5=(f32 **)&p_lbl_1_bss_7B180->unk_1600;
 v6=(u32 *)&p_lbl_1_bss_7B180->unk_1824;
 v7=(u32)&p_lbl_1_bss_7B180->unk_17A8;
 v8=(u32)&p_lbl_1_bss_7B180->unk_1794;
 v9=-32767;
 for(v10=0;v10<p_lbl_1_bss_7B180->unk_174E;v10++) {
 lbl_8006DD14((void *)v1,loc_50);
 v13=*(s32 *)v3;
 *(EEVec *)loc_14=*(EEVec *)v2;
 if(v9<v13) v9=v13;
 if (*(u16 *)v4>1 &&
 !((*(f32 **)v5)[*(u32 *)v6-1] <= (f32)*(u16 *)v4)) {
 v12=lbl_1_rodata_6B60;
 fn_1_56298(v12,v12,v12,v12);
 v12=lbl_1_rodata_6BD0;
 fn_1_5621C(v12,v12,v12,v12);
 fn_1_681C((u8)fn_1_5910(),(u32 *)loc_8);
 psvec_sub(loc_14,loc_8,loc_8);
 v12=loc_8[0]*loc_8[0];
 v12=loc_8[1]*loc_8[1]+v12;
 v12=loc_8[2]*loc_8[2]+v12;
 v21=lbl_8006D0B4(v12);
 lbl_8006D668(loc_8);
 psvec_scale(loc_8,lbl_1_rodata_6CFC,loc_8);
 psvec_add(loc_14,loc_8,loc_8);
 fn_1_56000(1,3,1);
 lbl_8006DCA4();
 lbl_8006E0A4(loc_8);
 lbl_8006DFC4(loc_50);
 lbl_8006E14C((lbl_1_rodata_6CFC+v21)/v21);
 fn_80072558();
 fn_1_55FF0(lbl_1_rodata_6D00);
 if ((s32)p_lbl_1_bss_7B180->unk_20 != 0 && v10==p_lbl_1_bss_7B180->unk_174E-1) {
 v12=lbl_1_rodata_6C18; fn_1_5621C(v12,v12,lbl_1_rodata_6BD0,lbl_1_rodata_6BD0);
 } else {v12=lbl_1_rodata_6BD0; fn_1_5621C(v12,v12,lbl_1_rodata_6C18,v12);}
 v11=*(u32 *)v7;
 if(v11) {
 fn_1_14E5E4(v11,*(s16 *)((u8 *)*(u32 *)v8+954),lbl_1_rodata_6D00);
 } else {
 v11=*(u32 *)v8;
 if(v11) {
 fn_1_556B8(*((EEObject *)v11)->models[v0].model);
 lbl_8006DAEC();
 v11=*(u32 *)v8;
 fn_1_87610((Sig_fn_1_87610_Fn187610Object *)v11,(Sig_fn_1_87610_Fn187610Data *)v11);
 v11=*(u32 *)v8;
 fn_1_875B4((void *)v11,(void *)v11,(void *)(s8)*(s16 *)((u8 *)v11+954),lbl_1_rodata_6D00);
 lbl_8006DC20();
 }}
 v12=lbl_1_rodata_6B60; fn_1_5621C(v12,v12,v12,v12);
 fn_1_56000(1,3,1);
 fn_1_681C((u8)fn_1_5910(),(u32 *)loc_8);
 dx=loc_8[0];
 dx-=loc_14[0];
 v29=loc_8[1];
 v29-=loc_14[1];
 v30=loc_8[2];
 v30-=loc_14[2];
 v31=dx*dx;
 v31=v29*v29+v31;
 v31=v30*v30+v31;
 v33=eeclamp(eefade(v31),lbl_1_rodata_6B60,lbl_1_rodata_6BBC);
 lbl_8006DCA4();lbl_8006E0A4(loc_14);lbl_8006DFC4(loc_50);fn_80072558();fn_80074A60(4,1);
 if((s32)p_lbl_1_bss_7B180->unk_20!=0 && v10==p_lbl_1_bss_7B180->unk_174E-1) {
 v12=lbl_1_rodata_6C18;fn_1_5621C(v12,v12,lbl_1_rodata_6BD0,lbl_1_rodata_6BD0);
 }else {v12=lbl_1_rodata_6BD0;fn_1_5621C(v12,v12,lbl_1_rodata_6C18,v12);}
 v11=*(u32 *)v8;
 if(v11) {
 v37=(s8)*(s16 *)((u8 *)v11+954);
 lbl_8006DB74(loc_20);
 v11=*(u32 *)v8;
 if((*(u32 *)((u8 *)v11+912)&0x4000000)!=0) {
 v11=*(u32 *)((u8 *)v11+928);
 if(!v11) return;
 fn_1_14E5E4(v11,v37,v33);
 } else {
 if((s8)*(u8 *)((u8 *)v11+808)>=41) OSPanic((char *)lbl_1_data_3E62C,3173,(char *)lbl_1_data_3E73C);
 {
 u32 object;
 v11=v37*12;
 object=*(u32 *)v8;
 fn_1_556B8(**(void ***)((u8 *)object+v11+820));
 }
 lbl_8006DAEC();
 v11=*(u32 *)v8;
 fn_1_87610((Sig_fn_1_87610_Fn187610Object *)v11,(Sig_fn_1_87610_Fn187610Data *)v11);
 v11=*(u32 *)v8;
 fn_1_875EC((void *)v11,(void *)v11,(void *)(s8)*(s16 *)((u8 *)v11+954),v33);
 lbl_8006DC20();
 }}
 fn_80074A6C();
 v12=lbl_1_rodata_6BD0;fn_1_5621C(v12,v12,v12,v12);fn_1_56000(1,3,1);
 }
 v1+=48; v2+=12; v3+=4; v4+=2; v5++; v6++; v7+=4; v8+=4;
 }
 }
}
/* fzgx:end fn_1_EE530 */

/* fzgx:begin fn_1_EEB44 noprologue */
#include "dolphin/types.h"
#include "game/vec3.h"
#include "rel/main_rel/ghost.h"

typedef struct {
    u8 pad0[0x24];
    u8 min;
    u8 sec;
    u16 ms;
} GhostRecord;
typedef struct {
    u8 pad0[0x1e0];
    u8 min;
    u8 sec;
    u16 ms;
} GhostPlayer;
typedef struct {
    u8 pad0[0x324];
    s32 handle;
} GhostObject;
typedef struct {
    u8 lapDelta;
    u8 flags;
    u8 angleY;
    u8 angleX;
    s16 angleZ;
    u16 pad;
    u32 packed;
    u32 unused;
} GhostFrame;

typedef struct {
    u8 pad0[0x1d8];
    u32 busy;
    u16 course;
    u8 pad1[0x2d4 - 0x1de];
    char file[0x338 - 0x2d4];
    char fmtItem[0x10];
    char fmtObj[0x10];
} GhostStrings;

extern void *lbl_801A6410;
extern void fn_80008BEC(void *, int, u32);
extern GhostPlayer *fn_1_3F0D8(u32, f32 *, u8 *);
extern void fn_1_8645C(int, void *);
extern void lbl_8006DBAC(Vec3 *);
extern void fn_8006F5C4(s16 *, s16 *, s16 *);
extern s32 fn_1_F17B4(const void *);
extern void ghost_pack_bits(u32 *, const u32 *, const u32 *, const u32 *);
extern u8 fn_1_3F114(void);
extern s16 *fn_1_86254(int);
extern void fn_1_12A734(s32);
extern void fn_1_7F934(GhostObject *);
extern void fn_1_46B4(void *, void *, const char *, int);
extern int sprintf(char *, const char *, ...);
extern void fn_1_14DBCC(void *);
extern void fn_1_984F0(void *);

void fn_1_EEB44(void)
{
/* one-member wrapper keeps the work base in one register (not rematerialized) */
struct { GhostStrings *value; } str;
struct { Obj_1_bss_7B180 *value; } work;
char objName[0x100];
char itemName[0x100];
f32 mtx[3][4];
f32 speed;
u32 packed0;
u32 packed1;
u32 packed2;
s16 angZ;
s16 angY;
s16 angX;
u8 misc;
GhostPlayer *player;
GhostRecord *rec;
GhostRecord **recs;
s16 *course;
u32 ptime;
u32 rtime;
u32 i;
struct { u32 value; } ghostCounter;
union { u8 *slot; GhostObject **objs; } cursor;
union { void **items; u8 *ghost; } otherCursor;
s32 j;
s32 count;
s32 f;
u8 *lapFlags;
u32 ghostIndex;

str.value = (GhostStrings *)lbl_1_data_3E358;
work.value = &lbl_1_bss_7B180;
if ((s32)work.value->unk_8 != 0 && work.value->unk_38AC != 0 ) {
if ((s32)work.value->unk_3894 != 0) {
str.value->busy = 0;
} else {
i = 0;
cursor.slot = work.value->arr_18D8;
for (; i < 5; i++) {
fn_80008BEC(cursor.slot, 0, 0x30);
cursor.slot += 0x30;
}
if (lbl_1_bss_960 == 9) {
if ((s32)work.value->unk_16C8 >= 0 && (s32)work.value->unk_17CC == 0) {
player = fn_1_3F0D8(0, &speed, &misc);
ptime = ((player)->min * 60000 + (player)->sec * 1000 + (player)->ms) ;
rec = (GhostRecord *)work.value->unk_16B4;
if (ptime >= ((rec)->min * 60000 + (rec)->sec * 1000 + (rec)->ms) ) {
work.value->unk_174C = 3;
} else {
work.value->unk_174C = 1;
}
} else if ((s32)work.value->unk_17CC != 0) {
work.value->unk_174C = 0;
} else if (work.value->unk_174E == 0) {
work.value->unk_174C = 0;
}
} else {
if (work.value->unk_174E != 0 && (s32)work.value->unk_17CC == 0) {
player = fn_1_3F0D8(0, &speed, &misc);
ptime = ((player)->min * 60000 + (player)->sec * 1000 + (player)->ms) ;
count = work.value->unk_174E;
work.value->unk_174C = 1;
recs = (GhostRecord **)&work.value->unk_16B4;
for (j = 0; j < count; j++) {
rec = recs[j];
if (ptime >= ((rec)->min * 60000 + (rec)->sec * 1000 + (rec)->ms) ) {
work.value->unk_174C = 3;
}
}
} else if ((s32)work.value->unk_17CC != 0) {
work.value->unk_174C = 0;
} else if (work.value->unk_174E == 0) {
work.value->unk_174C = 0;
}
}
if (work.value->unk_16CC != 0xff) {
player = fn_1_3F0D8(0, &speed, &misc);
ptime = ((player)->min * 60000 + (player)->sec * 1000 + (player)->ms) ;
if ((s32)work.value->unk_20 != 0) {
recs = (GhostRecord **)&work.value->unk_16B4;
recs += work.value->unk_174E;
rec = recs[-2];
rtime = ((rec)->min * 60000 + (rec)->sec * 1000 + (rec)->ms) ;
} else {
recs = (GhostRecord **)&work.value->unk_16B4;
recs += work.value->unk_174E;
rec = recs[-1];
rtime = ((rec)->min * 60000 + (rec)->sec * 1000 + (rec)->ms) ;
}
if (rtime > ptime) {
work.value->unk_174D = 1;
} else {
work.value->unk_174D = 3;
}
} else {
work.value->unk_174D = 0;
}
work.value->unk_3894 = 1;
fn_1_8645C(0, mtx);
for (f = work.value->unk_0 - 3; (u32)f < work.value->unk_0; f++) {
if (f > 0 && f < 0x7080) {
lapFlags = (u8 *)work.value->unk_16E8;
lapFlags[f] = 1;
}
}
lbl_8006DBAC((Vec3 *)mtx);
fn_8006F5C4(&angX, &angY, &angZ);
((GhostFrame *)work.value->unk_38AC)->angleY = angZ >> 8;
((GhostFrame *)work.value->unk_38AC)->angleZ = angY;
((GhostFrame *)work.value->unk_38AC)->angleX = angX >> 8;
((GhostFrame *)work.value->unk_38AC)->lapDelta = work.value->unk_0 - work.value->unk_4;
packed0 = fn_1_F17B4(&mtx[0][3]);
packed1 = fn_1_F17B4(&mtx[1][3]);
packed2 = fn_1_F17B4(&mtx[2][3]);
ghost_pack_bits(&((GhostFrame *)work.value->unk_38AC)->packed, &packed0, &packed1, &packed2);
((GhostFrame *)work.value->unk_38AC)->flags = fn_1_3F114();
((GhostFrame *)work.value->unk_38AC)->pad = 0;
*(u8 *)work.value->unk_38B0 = 1;
work.value->unk_38AC += sizeof(GhostFrame);
work.value->unk_38B0++;
work.value->unk_1820++;
work.value->unk_4 = work.value->unk_0;
work.value->unk_0++;
work.value->unk_C = 1;
str.value->course = 0;
course = fn_1_86254(0);
if (course != ((void *)0) ) {
str.value->course = course[3];
}
cursor.objs = (GhostObject **)&work.value->unk_1794;
otherCursor.items = (void **)&work.value->unk_17A8;
{
for (i = 0; i < 5; i++) {
if (cursor.objs[i] != ((void *)0) ) {
if (cursor.objs[i]->handle != -1) {
fn_1_12A734(cursor.objs[i]->handle);
cursor.objs[i]->handle = -1;
}
fn_1_7F934(cursor.objs[i]);
fn_1_46B4(lbl_801A6410, cursor.objs[i], str.value->file, 0xd89);
sprintf(objName, str.value->fmtObj, i);
cursor.objs[i] = ((void *)0) ;
}
if (otherCursor.items[i] != ((void *)0) ) {
fn_1_14DBCC(otherCursor.items[i]);
fn_1_46B4(lbl_801A6410, otherCursor.items[i], str.value->file, 0xd93);
sprintf(itemName, str.value->fmtItem, i);
otherCursor.items[i] = ((void *)0) ;
}
}
}
otherCursor.ghost = work.value->arr_19C8;
for (ghostCounter.value = 0; ghostCounter.value < work.value->unk_174E; ghostCounter.value++) {
fn_1_984F0(otherCursor.ghost + ghostCounter.value * 0x620);
}
str.value->busy = 0;
}
}
    return;
}
/* fzgx:end fn_1_EEB44 */

/* fzgx:begin fn_1_EF0A0 */
// fn_1_EF0A0: empty in retail (single blr).
void fn_1_EF0A0(void) {
}
/* fzgx:end fn_1_EF0A0 */

/* fzgx:begin fn_1_EF0A4 */
// fn_1_EF0A4: empty in retail (single blr).
void fn_1_EF0A4(void) {
}
/* fzgx:end fn_1_EF0A4 */

/* fzgx:begin fn_1_EF484 */
// fn_1_EF484: empty in retail (single blr).
void fn_1_EF484(void) {
}
/* fzgx:end fn_1_EF484 */

/* fzgx:begin fn_1_EF488 */
void fn_1_EF488(void) {
    fn_1_EE530();
    if (!fn_1_B7C00()) {
        fn_1_B9BE0();
        fn_1_B9DE8(&lbl_1_bss_7ECB4);
        lbl_1_bss_7ECB4.unk_0 = 4;
        lbl_1_bss_7ECB4.unk_4 = 9;
        lbl_1_bss_7EA00[0] = 0;
        lbl_1_data_3E52C = 13;
    }
}
/* fzgx:end fn_1_EF488 */

/* fzgx:begin fn_1_EF4F4 */
// fn_1_EF4F4: empty in retail (single blr).
void fn_1_EF4F4(void) {
}
/* fzgx:end fn_1_EF4F4 */

/* fzgx:begin fn_1_EF4F8 */
typedef struct {
    u8 pad_000[0x1D4];
    s32 state;
    u8 pad_1D8[0x08];
    s32 saved_state;
    u8 work[0x100];
} MainRelData;

typedef struct {
    u32 unk_0;
    u8 pad_4[0x2C0];
} fn_1_EF4F8_Obj_1_bss_7C584;



void fn_1_EF4F8(void) {
    struct { u32 * value; } entries;
    s32 i;
    MainRelData *data;
    u32 *global;
    s32 zero;
    s32 status;

    data = &(*(MainRelData *)&lbl_1_data_3E358);
    fn_1_EE530();
    status = (s8)fn_1_BA144(&(*(fn_1_EF4F8_Obj_1_bss_7ECB4 *)&lbl_1_bss_7ECB4));
    if (status == 2) {
        fn_1_BC310(&(*(fn_1_EF4F8_Obj_1_bss_7ECB4 *)&lbl_1_bss_7ECB4));
        return;
    }
    if (status == 0) {
        data->state = 5;
        return;
    }

    fn_1_BC29C(&(*(fn_1_EF4F8_Obj_1_bss_7ECB4 *)&lbl_1_bss_7ECB4));
    fn_1_B9C0C();
    entries.value = (u32 *)&(*(fn_1_EF4F8_Obj_1_bss_7C584 *)&lbl_1_bss_7C584);
    global = &(*(u32 *)&lbl_801A6410);
    i = 0;
    zero = 0;
    for (; i < 0x7F; i++) {
        if (*entries.value != 0) {
            fn_1_46B4(*global, *entries.value, (const char *)(void *)(&data->work[0xF0]), 0xEBA);
            *entries.value = zero;
        }
        entries.value++;
    }
    data->state = data->saved_state;
    fn_1_1596DC(2);
    fn_1_484CC(2);
}
/* fzgx:end fn_1_EF4F8 */

/* fzgx:begin fn_1_EF5DC */
// fn_1_EF5DC: empty in retail (single blr).
void fn_1_EF5DC(void) {
}
/* fzgx:end fn_1_EF5DC */

/* fzgx:begin fn_1_EF764 */
// fn_1_EF764: empty in retail (single blr).
void fn_1_EF764(void) {
}
/* fzgx:end fn_1_EF764 */

/* fzgx:begin fn_1_EF768 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/ghost.h"

extern void fn_1_EE530(void);
extern u32 fn_1_4630(u32, u32, const void *, u32);
extern void fn_80008BA8(void *, const void *, u32);
extern void fn_1_C0510(void *);
extern void fn_1_46B4(u32, u32, void *, u32);
extern u32 lbl_801A6410[];

typedef struct {
    u8 pad_0[8];
    u32 unk_8;
    u32 unk_c;
    u32 unk_10;
} Obj_3B34;

typedef struct {
    u8 pad_0[0x1c];
    u32 unk_1c;
    u8 pad_20[0xc];
    u8 unk_2c[0x28];
    u8 pad_54[0x13b0];
    u32 unk_1404[0x7f];
    u8 pad_1600[0x2534];
    Obj_3B34 unk_3b34;
} GhostState;

typedef struct lbl_1_bss_7B19C_t {
    u32 unk_1c;
    u8 pad_4[0x4];
} lbl_1_bss_7B19C_t;

typedef struct lbl_1_bss_7B1AC_t {
    u8 unk_2c[0x28];
    u8 pad_28[0x13b0];
} lbl_1_bss_7B1AC_t;

typedef struct lbl_1_bss_7C584_t {
    u32 unk_1404[0x7f];
    u8 pad_1FC[0xc8];
} lbl_1_bss_7C584_t;

typedef struct lbl_1_bss_7ECB4_t {
    Obj_3B34 unk_3b34;
    u8 pad_14[0x34];
} lbl_1_bss_7ECB4_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_7B180[2];
u32 fzgx_obj_lbl_1_bss_7B188[2];
u32 lbl_1_bss_7B190[2];
u32 lbl_1_bss_7B198;
lbl_1_bss_7B19C_t lbl_1_bss_7B19C;
u32 fzgx_obj_lbl_1_bss_7B1A4[2];
lbl_1_bss_7B1AC_t fzgx_obj_lbl_1_bss_7B1AC;
lbl_1_bss_7C584_t fzgx_obj_lbl_1_bss_7C584;
u32 lbl_1_bss_7C848[2];
u32 lbl_1_bss_7C850[3];
u32 fzgx_obj_lbl_1_bss_7C85C[28];
u8 lbl_1_bss_7C85C__fzgx_offset_70;
u8 lbl_1_bss_7C8CD;
u16 lbl_1_bss_7C8CE;
u32 lbl_1_bss_7C8CE__fzgx_offset_2[17];
u32 lbl_1_bss_7C914[13];
u32 lbl_1_bss_7C948;
u32 lbl_1_bss_7C94C[67];
u32 lbl_1_bss_7CA58[2020];
u32 fzgx_obj_lbl_1_bss_7E9E8[6];
u32 lbl_1_bss_7EA00[14];
u32 lbl_1_bss_7EA38[159];
lbl_1_bss_7ECB4_t fzgx_obj_lbl_1_bss_7ECB4;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B180;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B188;
    s = *(u8 *)&lbl_1_bss_7B190;
    s = *(u8 *)&lbl_1_bss_7B198;
    s = *(u8 *)&lbl_1_bss_7B19C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1A4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1AC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C584;
    s = *(u8 *)&lbl_1_bss_7C848;
    s = *(u8 *)&lbl_1_bss_7C850;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C85C;
    s = *(u8 *)&lbl_1_bss_7C85C__fzgx_offset_70;
    s = *(u8 *)&lbl_1_bss_7C8CD;
    s = *(u8 *)&lbl_1_bss_7C8CE;
    s = *(u8 *)&lbl_1_bss_7C8CE__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_7C914;
    s = *(u8 *)&lbl_1_bss_7C948;
    s = *(u8 *)&lbl_1_bss_7C94C;
    s = *(u8 *)&lbl_1_bss_7CA58;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7E9E8;
    s = *(u8 *)&lbl_1_bss_7EA00;
    s = *(u8 *)&lbl_1_bss_7EA38;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7ECB4;
}
#pragma section code_type ".text"

void fn_1_EF768(void) {
    u32 *p;
    u32 i;
    u32 v;
    u32 h;
    Obj_3B34 *o;

    
    fn_1_EE530();
    h = fn_1_4630(lbl_801A6410[0], 0x3ea8, lbl_1_data_3E62C, 0xf14);
    lbl_1_bss_7B19C.unk_1c = h;
    fn_80008BA8((void *)h, fzgx_obj_lbl_1_bss_7B1AC.unk_2c, 0x28);
    fn_80008BA8((void *)(lbl_1_bss_7B19C.unk_1c + 0x28), (const void *)fzgx_obj_lbl_1_bss_7C584.unk_1404[0], 0x3e80);
    o = &fzgx_obj_lbl_1_bss_7ECB4.unk_3b34;
    o->unk_8 = lbl_1_bss_7B19C.unk_1c;
    o->unk_c = 0x3ea8;
    o->unk_10 = 2;
    fn_1_C0510(o);
    p = fzgx_obj_lbl_1_bss_7C584.unk_1404;
    for (i = 0; i < 0x7f; i++) {
        v = p[i];
        if (v != 0) {
            fn_1_46B4(lbl_801A6410[0], v, lbl_1_data_3E62C, 0xf28);
            p[i] = 0;
        }
    }
    lbl_1_data_3E52C = 7;
}
/* fzgx:end fn_1_EF768 */

/* fzgx:begin fn_1_EF85C */
// fn_1_EF85C: empty in retail (single blr).
void fn_1_EF85C(void) {
}
/* fzgx:end fn_1_EF85C */

/* fzgx:begin fn_1_EF860 */
void fn_1_EF860(void) {
    u8 *base = lbl_1_data_3E358;
    u32 value;

    fn_1_EE530();
    if (!fn_1_B7C00()) {
        if (!fn_1_B7CD4()) {
            value = (int)fn_1_B7C5C();
            OSReport((const char *)(base + 0x3ac), value);
        }
        if (lbl_1_bss_7B19C[0] != 0) {
            fn_1_46B4(lbl_801A6410[0], lbl_1_bss_7B19C[0], (const char *)((void *)(base + 0x2d4)), 0xf44);
            lbl_1_bss_7B19C[0] = 0;
        }
        if (lbl_1_bss_7ECB4.unk_14 == (s8)8) {
            fn_1_C1394();
            *((u32 *)(base + 0x1d4)) = 0xd;
        } else {
            *((u32 *)(base + 0x1d4)) = 8;
        }
    }
}
/* fzgx:end fn_1_EF860 */

/* fzgx:begin fn_1_EF920 */
// fn_1_EF920: empty in retail (single blr).
void fn_1_EF920(void) {
}
/* fzgx:end fn_1_EF920 */

/* fzgx:begin fn_1_EF978 */
// fn_1_EF978: empty in retail (single blr).
void fn_1_EF978(void) {
}
/* fzgx:end fn_1_EF978 */

/* fzgx:begin fn_1_EF97C */
void fn_1_EF97C(void) {
    u8 *base = lbl_1_data_3E358;

    fn_1_EE530();

    if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) {
        *(s32 *)(base + 0x1D4) = 10;
    }

    fn_1_49410();
    fn_1_495FC();
    fn_1_496FC(lbl_1_rodata_6D20, lbl_1_rodata_6D24);
    fn_1_495C8(9);

    if (lbl_1_bss_7B198) {
        fn_1_4AE0C( (const char*)(void *)(base + 0x40C));
    } else {
        fn_1_4AE0C( (const char*)(void *)(base + 0x458));
    }
}
/* fzgx:end fn_1_EF97C */

/* fzgx:begin fn_1_EFA18 */
// fn_1_EFA18: empty in retail (single blr).
void fn_1_EFA18(void) {
}
/* fzgx:end fn_1_EFA18 */

/* fzgx:begin fn_1_EFA4C */
// fn_1_EFA4C: empty in retail (single blr).
void fn_1_EFA4C(void) {
}
/* fzgx:end fn_1_EFA4C */

/* fzgx:begin ghost_reset */
void ghost_reset(void) {
    lbl_1_bss_7C8CE[0] = 0;
    lbl_1_data_3E52C = -1;
    fn_1_F1D70();
}
/* fzgx:end ghost_reset */

/* fzgx:begin fn_1_EFA88 */
// fn_1_EFA88: empty in retail (single blr).
void fn_1_EFA88(void) {
}
/* fzgx:end fn_1_EFA88 */

/* fzgx:begin fn_1_F0164 */
// fn_1_F0164: empty in retail (single blr).
void fn_1_F0164(void) {
}
/* fzgx:end fn_1_F0164 */

/* fzgx:begin fn_1_F0168 pool noprologue */
#include "dolphin/types.h"
#include "rel/main_rel/ghost.h"

typedef struct {
    u16 r;        /* 0x0 */
    u16 g;        /* 0x2 */
    u16 b;        /* 0x4 */
    u16 pad;
    u32 flags;    /* 0x8 */
    u32 pad2;
} GhostDisplayState;

typedef struct {
    u16 index;    /* 0x0 */
    s16 id;       /* 0x2 */
    u32 kind;     /* 0x4 */
    u8 pad[0x18];
} GhostEntry;

extern void *lbl_801A6410;

extern void fn_1_80058(s8, GhostEntry *);
extern void *fn_1_7F518(s16, char *, s32);
extern s32 fn_1_465D0(char *, s32);
extern void fn_1_14F46C(GhostDisplayState *, void *);
extern void fn_1_46B4(void *, void *, const char *, int);
extern void *fn_1_4630(void *, u32, const char *, int);
extern void fn_1_F4F08(u32, void *, u32, void *);
extern void fn_1_F1300(u32, void *, u32, u32, u32);
extern int sprintf(char *, const char *, ...);
extern void fn_80006E10(const char *);

static inline void GhostEntry_setKind(GhostEntry *entry, u16 index, u8 count)
{
    entry->index = index;
    if (count <= 1) {
        entry->kind = 1;
    } else if (count <= 3) {
        entry->kind = 2;
    } else {
        entry->kind = 4;
    }
}

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_7B180[2];
u32 fzgx_obj_lbl_1_bss_7B188[2];
u32 lbl_1_bss_7B190[2];
u32 lbl_1_bss_7B198;
u32 lbl_1_bss_7B19C[2];
u32 fzgx_obj_lbl_1_bss_7B1A4[2];
u32 fzgx_obj_lbl_1_bss_7B1AC[1270];
u32 fzgx_obj_lbl_1_bss_7C584[127];
u32 lbl_1_bss_7C584_1FC;
u32 lbl_1_bss_7C584_fill_7C784[4];
u32 lbl_1_bss_7C584_210;
u32 lbl_1_bss_7C584_fill_7C798[4];
u32 lbl_1_bss_7C584_224;
u32 lbl_1_bss_7C584_fill_7C7AC[4];
u32 lbl_1_bss_7C584_238;
u32 lbl_1_bss_7C584_fill_7C7C0[4];
u32 lbl_1_bss_7C584_24C;
u32 lbl_1_bss_7C584_fill_7C7D4[4];
u32 lbl_1_bss_7C584_260;
u32 lbl_1_bss_7C584_fill_7C7E8[4];
u32 lbl_1_bss_7C584_274;
u32 lbl_1_bss_7C584_fill_7C7FC[19];
u32 lbl_1_bss_7C848[2];
u32 lbl_1_bss_7C850[3];
u32 fzgx_obj_lbl_1_bss_7C85C[4];
u32 lbl_1_bss_7C85C_10;
u32 lbl_1_bss_7C85C_fill_7C870[4];
u32 lbl_1_bss_7C85C_24;
u32 lbl_1_bss_7C85C_fill_7C884[4];
u32 lbl_1_bss_7C85C_38;
u32 lbl_1_bss_7C85C_fill_7C898[4];
u32 lbl_1_bss_7C85C_4C;
u32 lbl_1_bss_7C85C_fill_7C8AC[8];
u8 lbl_1_bss_7C85C_fill_7C8CC;
u8 lbl_1_bss_7C8CD;
u8 lbl_1_bss_7C8CE;
u8 lbl_1_bss_7C8CE_fill_7C8CF;
u32 lbl_1_bss_7C8CE_fill_7C8D0[17];
u32 lbl_1_bss_7C914[11];
u32 lbl_1_bss_7C914_2C;
u32 lbl_1_bss_7C914_fill_7C944;
u32 lbl_1_bss_7C948;
u32 lbl_1_bss_7C94C;
u16 lbl_1_bss_7C94C_4;
u16 lbl_1_bss_7C94C_fill_7C952;
u32 lbl_1_bss_7C94C_fill_7C954[2];
u32 lbl_1_bss_7C94C_10;
u32 lbl_1_bss_7C94C_fill_7C960[4];
u8 lbl_1_bss_7C94C_24;
u8 lbl_1_bss_7C94C_fill_7C971;
u16 lbl_1_bss_7C94C_fill_7C972;
u32 lbl_1_bss_7C94C_fill_7C974[3];
u16 lbl_1_bss_7C94C_34;
u16 lbl_1_bss_7C94C_fill_7C982;
u32 lbl_1_bss_7C94C_fill_7C984[8];
u32 lbl_1_bss_7C94C_58;
u32 lbl_1_bss_7C94C_fill_7C9A8[4];
u8 lbl_1_bss_7C94C_6C;
u16 lbl_1_bss_7C94C_fill_7C9BA;
u32 lbl_1_bss_7C94C_fill_7C9BC[39];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B180;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B188;
    s = *(u8 *)&lbl_1_bss_7B190;
    s = *(u8 *)&lbl_1_bss_7B198;
    s = *(u8 *)&lbl_1_bss_7B19C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1A4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1AC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C584;
    s = *(u8 *)&lbl_1_bss_7C584_1FC;
    s = *(u8 *)&lbl_1_bss_7C584_fill_7C784;
    s = *(u8 *)&lbl_1_bss_7C584_210;
    s = *(u8 *)&lbl_1_bss_7C584_fill_7C798;
    s = *(u8 *)&lbl_1_bss_7C584_224;
    s = *(u8 *)&lbl_1_bss_7C584_fill_7C7AC;
    s = *(u8 *)&lbl_1_bss_7C584_238;
    s = *(u8 *)&lbl_1_bss_7C584_fill_7C7C0;
    s = *(u8 *)&lbl_1_bss_7C584_24C;
    s = *(u8 *)&lbl_1_bss_7C584_fill_7C7D4;
    s = *(u8 *)&lbl_1_bss_7C584_260;
    s = *(u8 *)&lbl_1_bss_7C584_fill_7C7E8;
    s = *(u8 *)&lbl_1_bss_7C584_274;
    s = *(u8 *)&lbl_1_bss_7C584_fill_7C7FC;
    s = *(u8 *)&lbl_1_bss_7C848;
    s = *(u8 *)&lbl_1_bss_7C850;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C85C;
    s = *(u8 *)&lbl_1_bss_7C85C_10;
    s = *(u8 *)&lbl_1_bss_7C85C_fill_7C870;
    s = *(u8 *)&lbl_1_bss_7C85C_24;
    s = *(u8 *)&lbl_1_bss_7C85C_fill_7C884;
    s = *(u8 *)&lbl_1_bss_7C85C_38;
    s = *(u8 *)&lbl_1_bss_7C85C_fill_7C898;
    s = *(u8 *)&lbl_1_bss_7C85C_4C;
    s = *(u8 *)&lbl_1_bss_7C85C_fill_7C8AC;
    s = *(u8 *)&lbl_1_bss_7C85C_fill_7C8CC;
    s = *(u8 *)&lbl_1_bss_7C8CD;
    s = *(u8 *)&lbl_1_bss_7C8CE;
    s = *(u8 *)&lbl_1_bss_7C8CE_fill_7C8CF;
    s = *(u8 *)&lbl_1_bss_7C8CE_fill_7C8D0;
    s = *(u8 *)&lbl_1_bss_7C914;
    s = *(u8 *)&lbl_1_bss_7C914_2C;
    s = *(u8 *)&lbl_1_bss_7C914_fill_7C944;
    s = *(u8 *)&lbl_1_bss_7C948;
    s = *(u8 *)&lbl_1_bss_7C94C;
    s = *(u8 *)&lbl_1_bss_7C94C_4;
    s = *(u8 *)&lbl_1_bss_7C94C_fill_7C952;
    s = *(u8 *)&lbl_1_bss_7C94C_fill_7C954;
    s = *(u8 *)&lbl_1_bss_7C94C_10;
    s = *(u8 *)&lbl_1_bss_7C94C_fill_7C960;
    s = *(u8 *)&lbl_1_bss_7C94C_24;
    s = *(u8 *)&lbl_1_bss_7C94C_fill_7C971;
    s = *(u8 *)&lbl_1_bss_7C94C_fill_7C972;
    s = *(u8 *)&lbl_1_bss_7C94C_fill_7C974;
    s = *(u8 *)&lbl_1_bss_7C94C_34;
    s = *(u8 *)&lbl_1_bss_7C94C_fill_7C982;
    s = *(u8 *)&lbl_1_bss_7C94C_fill_7C984;
    s = *(u8 *)&lbl_1_bss_7C94C_58;
    s = *(u8 *)&lbl_1_bss_7C94C_fill_7C9A8;
    s = *(u8 *)&lbl_1_bss_7C94C_6C;
    s = *(u8 *)&lbl_1_bss_7C94C_fill_7C9BA;
    s = *(u8 *)&lbl_1_bss_7C94C_fill_7C9BC;
}
#pragma section code_type ".text"

extern u8 fn_1_ECDFC__fzgx_offset_0[];
extern u8 fn_1_ECE00__fzgx_offset_0[];
extern u8 fn_1_ECE04__fzgx_offset_0[];
extern u8 fn_1_ECF68__fzgx_offset_0[];
extern u8 fn_1_ECF88__fzgx_offset_0[];
extern u8 fn_1_ED540__fzgx_offset_0[];
extern u8 fn_1_EE3F4__fzgx_offset_0[];
extern u8 fn_1_EE530__fzgx_offset_0[];
extern u8 fn_1_EEB44__fzgx_offset_0[];
extern u8 fn_1_EF0A0__fzgx_offset_0[];
extern u8 fn_1_EF0A4__fzgx_offset_0[];
extern u8 fn_1_EF0A8__fzgx_offset_0[];
extern u8 fn_1_EF484__fzgx_offset_0[];
extern u8 fn_1_EF488__fzgx_offset_0[];
extern u8 fn_1_EF4F4__fzgx_offset_0[];
extern u8 fn_1_EF4F8__fzgx_offset_0[];
extern u8 fn_1_EF5DC__fzgx_offset_0[];
extern u8 fn_1_EF5E0__fzgx_offset_0[];
extern u8 fn_1_EF764__fzgx_offset_0[];
extern u8 fn_1_EF768__fzgx_offset_0[];
extern u8 fn_1_EF85C__fzgx_offset_0[];
extern u8 fn_1_EF860__fzgx_offset_0[];
extern u8 fn_1_EF920__fzgx_offset_0[];
extern u8 fn_1_EF924__fzgx_offset_0[];
extern u8 fn_1_EF978__fzgx_offset_0[];
extern u8 fn_1_EF97C__fzgx_offset_0[];
extern u8 fn_1_EFA18__fzgx_offset_0[];
extern u8 fn_1_EFA1C__fzgx_offset_0[];
extern u8 fn_1_EFA4C__fzgx_offset_0[];
extern u8 fn_1_EFA88__fzgx_offset_0[];
extern u8 fn_1_EFA8C__fzgx_offset_0[];
extern u8 fn_1_F0164__fzgx_offset_0[];
extern u8 fn_1_F0168__fzgx_offset_0[];
extern u8 ghost_reset__fzgx_offset_0[];
extern u8 lbl_1_data_3E358__fzgx_offset_0[];
extern u8 lbl_1_data_3E364__fzgx_offset_0[];
extern u8 lbl_1_data_3E36C__fzgx_offset_0[];
extern u8 lbl_1_data_3E378__fzgx_offset_0[];
extern u8 lbl_1_data_3E380__fzgx_offset_0[];
extern u8 lbl_1_data_3E38C__fzgx_offset_0[];
extern u8 lbl_1_data_3E394__fzgx_offset_0[];
extern u8 lbl_1_data_3E39C__fzgx_offset_0[];
extern u8 lbl_1_data_3E3C0__fzgx_offset_0[];
extern u8 lbl_1_data_3E3CC__fzgx_offset_0[];
extern u8 lbl_1_data_3E3D8__fzgx_offset_0[];
extern u8 lbl_1_data_3E478__fzgx_offset_0[];
extern u8 lbl_1_data_3E48C__fzgx_offset_0[];
extern u8 lbl_1_data_3E490__fzgx_offset_0[];
extern u8 lbl_1_data_3E4BC__fzgx_offset_0[];
extern u8 lbl_1_data_3E4C8__fzgx_offset_0[];
extern u8 lbl_1_data_3E4F4__fzgx_offset_0[];
extern u8 lbl_1_data_3E504__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_1_data_3E358[117] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F564552, 0x54414B45, 0x0, 0x4A554D50, 0x0, 0x454E454D, 0x59484954, 0x0,
    0x57414C4C, 0x48495400, 0x53494445, 0x42595349, 0x44450000, 0x53544152, 0x54000000, 0x474F414C,
    0x0, 0x4C415000, (u32)lbl_1_data_3E358__fzgx_offset_0, (u32)lbl_1_data_3E364__fzgx_offset_0, (u32)lbl_1_data_3E36C__fzgx_offset_0, (u32)lbl_1_data_3E378__fzgx_offset_0, (u32)lbl_1_data_3E380__fzgx_offset_0, (u32)lbl_1_data_3E38C__fzgx_offset_0,
    (u32)lbl_1_data_3E394__fzgx_offset_0, (u32)lbl_1_data_3E39C__fzgx_offset_0, 0x67686F73, 0x7430302E, 0x62696E00, 0x67686F73, 0x7430312E, 0x62696E00,
    0x67686F73, 0x7430322E, 0x62696E00, (u32)lbl_1_data_3E3C0__fzgx_offset_0, (u32)lbl_1_data_3E3CC__fzgx_offset_0, (u32)lbl_1_data_3E3D8__fzgx_offset_0, (u32)fn_1_ECDFC__fzgx_offset_0, (u32)fn_1_ECE04__fzgx_offset_0,
    (u32)fn_1_ECF88__fzgx_offset_0, (u32)fn_1_EE3F4__fzgx_offset_0, (u32)fn_1_EEB44__fzgx_offset_0, (u32)fn_1_EF5DC__fzgx_offset_0, (u32)fn_1_EF764__fzgx_offset_0, (u32)fn_1_EF85C__fzgx_offset_0, (u32)fn_1_EF920__fzgx_offset_0, (u32)fn_1_EF978__fzgx_offset_0,
    (u32)fn_1_EFA18__fzgx_offset_0, (u32)fn_1_EF0A4__fzgx_offset_0, (u32)fn_1_EF484__fzgx_offset_0, (u32)fn_1_EF4F4__fzgx_offset_0, (u32)fn_1_EFA88__fzgx_offset_0, (u32)fn_1_EFA4C__fzgx_offset_0, (u32)fn_1_F0164__fzgx_offset_0, (u32)fn_1_ECE00__fzgx_offset_0,
    (u32)fn_1_ECF68__fzgx_offset_0, (u32)fn_1_ED540__fzgx_offset_0, (u32)fn_1_EE530__fzgx_offset_0, (u32)fn_1_EF0A0__fzgx_offset_0, (u32)fn_1_EF5E0__fzgx_offset_0, (u32)fn_1_EF768__fzgx_offset_0, (u32)fn_1_EF860__fzgx_offset_0, (u32)fn_1_EF924__fzgx_offset_0,
    (u32)fn_1_EF97C__fzgx_offset_0, (u32)fn_1_EFA1C__fzgx_offset_0, (u32)fn_1_EF0A8__fzgx_offset_0, (u32)fn_1_EF488__fzgx_offset_0, (u32)fn_1_EF4F8__fzgx_offset_0, (u32)fn_1_EFA8C__fzgx_offset_0, (u32)ghost_reset__fzgx_offset_0, (u32)fn_1_F0168__fzgx_offset_0,
    0x4F726967, 0x696E616C, 0x204D6163, 0x68696E65, 0x0, 0x0, 0x8349838A, 0x83578369,
    0x838B837D, 0x83568393, 0x0, (u32)lbl_1_data_3E478__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0,
    (u32)lbl_1_data_3E490__fzgx_offset_0, 0x53746166, 0x66204768, 0x6F737400, 0x8358835E, 0x83628374, 0x8353815B, 0x83588367,
    0x0, (u32)lbl_1_data_3E4BC__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E4C8__fzgx_offset_0, 0x53454C45,
    0x43542047, 0x484F5354, 0x0, 0x47484F53, 0x54205345, 0x4C454354, 0x0, (u32)lbl_1_data_3E4F4__fzgx_offset_0,
    (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E504__fzgx_offset_0
};
static u32 fzgx_pool_data_lbl_1_data_3E52C[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFFFFFFFF
};
static u32 fzgx_pool_data_lbl_1_data_3E530[63] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFFFFFFFF, 0xFFFF0000, 0xFFFFFFFF, 0xC, 0x1D, 0xE, 0x17, 0x4,
    0x0, 0x16, 0x1D, 0xC, 0x17, 0x16, 0x0, 0x1D,
    0x1B, 0x4, 0xF, 0x4, 0x0, 0x1D, 0x11, 0x15,
    0xC, 0x14, 0x0, 0x27, 0x5, 0x1F, 0x4, 0x28,
    0x1F, 0x3B3C4, 0x382B3, 0x1382E7, 0x13B38B, 0x20F129, 0x0, 0x10714B,
    0x2192B1, 0x1230A9, 0x21A322, 0x11A225, 0x0, 0x22838D, 0x218381, 0x23B075,
    0x232128, 0x232328, 0x0, 0x23A28A, 0x209351, 0x206394, 0x23B04C, 0x20310C,
    0x0, 0x1062B2, 0x1260B2, 0x206345, 0x312110, 0x3322E4, 0x2E37D
};
static u32 fzgx_pool_data_lbl_1_data_3E62C[32] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x67686F73, 0x742E6300, 0x47686F73, 0x7443616C, 0x63000000, 0x47686F73, 0x74446973, 0x70000000,
    0x73746F72, 0x795F6768, 0x6F73742F, 0x25730000, 0x53746F72, 0x7947686F, 0x7374203A, 0x20257320,
    0x2025640A, 0x0, 0x2E2F7374, 0x6166665F, 0x67686F73, 0x742F6768, 0x6F737425, 0x642E6461,
    0x74000000, 0x70636172, 0x6F626A5B, 0x25645D0A, 0x0, 0x6361726F, 0x626A5B25, 0x645D0A00
};
static u32 fzgx_pool_data_lbl_1_data_3E6AC[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x73617665, 0x5F3F3F3F, 0x5B25645D, 0xA000000
};
static u32 fzgx_pool_data_lbl_1_data_3E358_364[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x76656869, 0x636C655F, 0x70617274, 0x732F0000
};
static u32 fzgx_pool_data_lbl_1_data_3E358_374[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x2E2E0000
};
static u32 fzgx_pool_data_lbl_1_data_3E358_378[5] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x76656869, 0x636C652F, 0x25735F65, 0x2E617263, 0x2E6C7A00
};
static u32 fzgx_pool_data_lbl_1_data_3E358_38C[8] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x76656869, 0x636C652F, 0x25735F70, 0x2E617263, 0x2E6C7A00, 0x76656869, 0x636C652F, 0x0
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_data_3E358(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3E358;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3E52C;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3E530;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3E62C;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3E6AC;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3E358_364;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3E358_374;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3E358_378;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3E358_38C;
}
#pragma section code_type ".text"

void fn_1_F0168(void)
{
    
    
    s32 *loaded = (s32 *)&lbl_1_bss_7C94C_10;
    s16 *ids = (s16 *)&lbl_1_bss_7C94C_4;
    u32 *sizeA = &lbl_1_bss_7C584_210;
    u32 *sizeB;
    GhostEntry *entry = (GhostEntry *)&lbl_1_bss_7C94C_6C;
    u8 (*colors)[3] = (u8 (*)[3])&lbl_1_bss_7C94C_24;
    void **outA = (void **)&lbl_1_bss_7C85C_10;
    u32 *frames = &lbl_1_bss_7C94C_58;
    void **bufA = (void **)&lbl_1_bss_7C584_1FC;
    void **outB = (void **)&lbl_1_bss_7C85C_24;
    void **outC;
    u32 *sizeC;
    void **outD;
    u32 *sizeF;
    u32 *sizeE;
    u32 *sizeD;
    u16 *flags;
    u32 i;
    u32 n;
    u8 count;
    GhostDisplayState state;
    char name[0x20];
    char text[0x30];
    u8 buf[0xa20] __attribute__((aligned(32)));

    sizeB = &lbl_1_bss_7C584_224;
    outC = (void **)&lbl_1_bss_7C85C_38;
    sizeC = &lbl_1_bss_7C584_238;
    outD = (void **)&lbl_1_bss_7C85C_4C;
    sizeF = &lbl_1_bss_7C584_274;
    sizeE = &lbl_1_bss_7C584_260;
    sizeD = &lbl_1_bss_7C584_24C;
    flags = &lbl_1_bss_7C94C_34;

    for (i = 0; i < lbl_1_bss_7C8CE; i++) {
        if (*loaded == 0) {
            fn_1_80058((s8)*ids, entry);
            count = lbl_1_bss_7C8CE;
            entry->index = (u16)i;
            if (count <= 1) {
                entry->kind = 1;
            } else if (count <= 3) {
                entry->kind = 2;
            } else {
                entry->kind = 4;
            }
            fn_1_7F518(entry->id, name, 0);
            if (entry->kind == 2) {
                sprintf(text, ((char *)fzgx_pool_data_lbl_1_data_3E358_378), name);
            } else {
                sprintf(text, ((char *)fzgx_pool_data_lbl_1_data_3E358_38C), name);
            }
            fn_1_465D0(text, 1);
            entry++;
        } else {
            if (lbl_1_bss_7C8CE <= 1) {
                state.flags = 1;
            } else if (lbl_1_bss_7C8CE <= 3) {
                state.flags = 2;
            } else {
                state.flags = 4;
            }
            state.r = (*colors)[0];
            state.g = (*colors)[1];
            state.b = (*colors)[2];
            fn_80006E10(((char *)fzgx_pool_data_lbl_1_data_3E358_364));
            fn_1_14F46C(&state, buf);
            fn_80006E10(((char *)fzgx_pool_data_lbl_1_data_3E358_374));
        }

        if (*outA != NULL) {
            fn_1_46B4(lbl_801A6410, *outA, ((char *)fzgx_pool_data_lbl_1_data_3E62C), 0x1039);
        }
        *outA = fn_1_4630(lbl_801A6410, *frames << 2, ((char *)fzgx_pool_data_lbl_1_data_3E62C), 0x103a);
        fn_1_F4F08(*frames, *bufA, *sizeA, *outA);

        if (*outB != NULL) {
            fn_1_46B4(lbl_801A6410, *outB, ((char *)fzgx_pool_data_lbl_1_data_3E62C), 0x103d);
        }
        *outB = fn_1_4630(lbl_801A6410, *frames << 2, ((char *)fzgx_pool_data_lbl_1_data_3E62C), 0x103e);
        fn_1_F4F08(*frames, *bufA, *sizeB, *outB);

        if (*outC != NULL) {
            fn_1_46B4(lbl_801A6410, *outC, ((char *)fzgx_pool_data_lbl_1_data_3E62C), 0x1041);
        }
        *outC = fn_1_4630(lbl_801A6410, *frames << 2, ((char *)fzgx_pool_data_lbl_1_data_3E62C), 0x1042);
        fn_1_F4F08(*frames, *bufA, *sizeC, *outC);

        if (*outD != NULL) {
            fn_1_46B4(lbl_801A6410, *outD, ((char *)fzgx_pool_data_lbl_1_data_3E62C), 0x1047);
        }
        *outD = fn_1_4630(lbl_801A6410, *frames << 4, ((char *)fzgx_pool_data_lbl_1_data_3E62C), 0x1048);
        fn_1_F1300(*frames, *outD, *sizeD, *sizeE, *sizeF);

        *flags = 0;
        loaded++;
        ids++;
        sizeA++;
        colors++;
        outA++;
        frames++;
        bufA++;
        outB++;
        sizeB++;
        outC++;
        sizeC++;
        outD++;
        sizeF++;
        sizeE++;
        sizeD++;
        flags++;
    }
    lbl_1_bss_7C914_2C = 0;
    *(s32 *)(((char *)fzgx_pool_data_lbl_1_data_3E52C)) = -1;
}
/* fzgx:end fn_1_F0168 */

/* fzgx:begin fn_1_F0B5C pool noprologue */
#include "types.h"

typedef struct { f32 x, y, z; } V3;

typedef struct {
    f32 *k[5];
    f32 *a_row0[5]; f32 * a_row1[5]; f32 * a_row2[5];
    u8 pad0[0x16ec - 0x1650];
    f32 *b_row0[5]; f32 * b_row1[5]; f32 * b_row2[5];
    u8 pad1[0x1758 - 0x1728];
    V3 v[14];
    u16 h[18];
    s32 c[5];
} S;

extern const f64 lbl_1_rodata_6B68;
extern V3 lbl_1_rodata_6D28;
extern f32 fn_1_F4E3C(s32, f32 *, f32 *, f32 *, f32);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_7B180[2];
u32 fzgx_obj_lbl_1_bss_7B188[2];
u32 lbl_1_bss_7B190[2];
u32 lbl_1_bss_7B198;
u32 lbl_1_bss_7B19C[2];
u32 fzgx_obj_lbl_1_bss_7B1A4[2];
u32 fzgx_obj_lbl_1_bss_7B1AC[1270];
u32 fzgx_obj_lbl_1_bss_7C584[127];
f32 *lbl_1_bss_7C584_1FC[5];
f32 *lbl_1_bss_7C584_210[5];
f32 *lbl_1_bss_7C584_224[5];
f32 *lbl_1_bss_7C584_238[5];
u32 lbl_1_bss_7C584_fill_7C7D0[30];
u32 lbl_1_bss_7C848[2];
u32 lbl_1_bss_7C850[3];
u32 fzgx_obj_lbl_1_bss_7C85C[4];
f32 *lbl_1_bss_7C85C_10[5];
f32 *lbl_1_bss_7C85C_24[5];
f32 *lbl_1_bss_7C85C_38[5];
u32 lbl_1_bss_7C85C_fill_7C8A8[9];
u8 lbl_1_bss_7C85C_fill_7C8CC;
u8 lbl_1_bss_7C8CD;
u16 lbl_1_bss_7C8CE;
u32 lbl_1_bss_7C8CE_fill_7C8D0[2];
u8 lbl_1_bss_7C8CE_A;
u8 lbl_1_bss_7C8CE_fill_7C8D9;
u16 lbl_1_bss_7C8CE_fill_7C8DA;
u32 lbl_1_bss_7C8CE_fill_7C8DC[14];
u32 lbl_1_bss_7C914[13];
u32 lbl_1_bss_7C948;
u32 lbl_1_bss_7C94C[13];
u16 lbl_1_bss_7C94C_34[18];
s32 lbl_1_bss_7C94C_58[5];
u32 lbl_1_bss_7C94C_fill_7C9B8[40];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B180;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B188;
    s = *(u8 *)&lbl_1_bss_7B190;
    s = *(u8 *)&lbl_1_bss_7B198;
    s = *(u8 *)&lbl_1_bss_7B19C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1A4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1AC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C584;
    s = *(u8 *)&lbl_1_bss_7C584_1FC;
    s = *(u8 *)&lbl_1_bss_7C584_210;
    s = *(u8 *)&lbl_1_bss_7C584_224;
    s = *(u8 *)&lbl_1_bss_7C584_238;
    s = *(u8 *)&lbl_1_bss_7C584_fill_7C7D0;
    s = *(u8 *)&lbl_1_bss_7C848;
    s = *(u8 *)&lbl_1_bss_7C850;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C85C;
    s = *(u8 *)&lbl_1_bss_7C85C_10;
    s = *(u8 *)&lbl_1_bss_7C85C_24;
    s = *(u8 *)&lbl_1_bss_7C85C_38;
    s = *(u8 *)&lbl_1_bss_7C85C_fill_7C8A8;
    s = *(u8 *)&lbl_1_bss_7C85C_fill_7C8CC;
    s = *(u8 *)&lbl_1_bss_7C8CD;
    s = *(u8 *)&lbl_1_bss_7C8CE;
    s = *(u8 *)&lbl_1_bss_7C8CE_fill_7C8D0;
    s = *(u8 *)&lbl_1_bss_7C8CE_A;
    s = *(u8 *)&lbl_1_bss_7C8CE_fill_7C8D9;
    s = *(u8 *)&lbl_1_bss_7C8CE_fill_7C8DA;
    s = *(u8 *)&lbl_1_bss_7C8CE_fill_7C8DC;
    s = *(u8 *)&lbl_1_bss_7C914;
    s = *(u8 *)&lbl_1_bss_7C948;
    s = *(u8 *)&lbl_1_bss_7C94C;
    s = *(u8 *)&lbl_1_bss_7C94C_34;
    s = *(u8 *)&lbl_1_bss_7C94C_58;
    s = *(u8 *)&lbl_1_bss_7C94C_fill_7C9B8;
}
#pragma section code_type ".text"

#pragma opt_propagation off
s32 fn_1_F0B5C(s32 i, V3 *out) {
    u16 *frames;
    s32 *counts;
    V3 def = lbl_1_rodata_6D28;
    frames = lbl_1_bss_7C94C_34;
    out->x = fn_1_F4E3C((counts = lbl_1_bss_7C94C_58)[i], lbl_1_bss_7C584_1FC[i], lbl_1_bss_7C584_210[i], lbl_1_bss_7C85C_10[i], (f32)frames[i]);
    out->y = fn_1_F4E3C(counts[i], lbl_1_bss_7C584_1FC[i], lbl_1_bss_7C584_224[i], lbl_1_bss_7C85C_24[i], (f32)frames[i]);
    out->z = fn_1_F4E3C(counts[i], lbl_1_bss_7C584_1FC[i], lbl_1_bss_7C584_238[i], lbl_1_bss_7C85C_38[i], (f32)frames[i]);
    if ((f32)frames[i] >= lbl_1_bss_7C584_1FC[i][counts[i] - 1]) {
        *out = def;
        return 0;
    }
    (*(V3 (*)[14])&lbl_1_bss_7C8CE_A)[i] = *out;
    return 1;
}
/* fzgx:end fn_1_F0B5C */

/* fzgx:begin fn_1_F0E00 pool noprologue */
#include "dolphin/types.h"

extern u8 fn_1_3F114(void);
extern const f64 lbl_1_rodata_6B68;
extern const f32 lbl_1_rodata_6BD0;
extern const f64 lbl_1_rodata_6C88;
extern const f32 lbl_1_rodata_6CB8;
extern const f32 lbl_1_rodata_6B60;
extern const f32 lbl_1_rodata_6D34;
extern const f32 lbl_1_rodata_6D10;

typedef struct {
    u8 b0;
    s8 b1;
    u8 pad2[4];
    u16 h6;
    u8 pad8[8];
} GhostKey;

/* File-scope objects in retail order. */
u8 lbl_1_bss_7B180[0x8];
u8 lbl_1_bss_7B188[0x24];
u8 lbl_1_bss_7B1AC[0x13D8];
void *lbl_1_bss_7C584[127];
f32 *lbl_1_bss_7C780[5];
u8 lbl_1_bss_7C794[0x78];
s8 *lbl_1_bss_7C80C[5];
u16 *lbl_1_bss_7C820[5];
u8 lbl_1_bss_7C834[0x30];
GhostKey *lbl_1_bss_7C864;
u8 lbl_1_bss_7C868[0x118];
u16 lbl_1_bss_7C980[16];
u32 lbl_1_bss_7C9A0;
u32 lbl_1_bss_7C9A4[5];
u8 lbl_1_bss_7C9B8[0x2060];
u32 lbl_1_bss_7EA18;
f32 lbl_1_bss_7EA1C;
f32 lbl_1_bss_7EA20;
s8 lbl_1_bss_7EA24;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_1_bss_7B180;
    s = *(u8 *)&lbl_1_bss_7B188;
    s = *(u8 *)&lbl_1_bss_7B1AC;
    s = *(u8 *)&lbl_1_bss_7C584;
    s = *(u8 *)&lbl_1_bss_7C780;
    s = *(u8 *)&lbl_1_bss_7C794;
    s = *(u8 *)&lbl_1_bss_7C80C;
    s = *(u8 *)&lbl_1_bss_7C820;
    s = *(u8 *)&lbl_1_bss_7C834;
    s = *(u8 *)&lbl_1_bss_7C864;
    s = *(u8 *)&lbl_1_bss_7C868;
    s = *(u8 *)&lbl_1_bss_7C980;
    s = *(u8 *)&lbl_1_bss_7C9A0;
    s = *(u8 *)&lbl_1_bss_7C9A4;
    s = *(u8 *)&lbl_1_bss_7C9B8;
    s = *(u8 *)&lbl_1_bss_7EA18;
    s = *(u8 *)&lbl_1_bss_7EA1C;
    s = *(u8 *)&lbl_1_bss_7EA20;
    s = *(u8 *)&lbl_1_bss_7EA24;
}
#pragma section code_type ".text"

static inline f32 ghost_ratio(u32 a, u32 b) {
    return (f32)a / (f32)b;
}

static inline u32 ghost_lerp(u32 a, u32 lo, u32 hi, u32 b) {
    f32 r = (f32)a / (f32)b;
    return (f32)lo * (lbl_1_rodata_6BD0 - r) + (f32)(f32)hi * r;
}

s32 fn_1_F0E00(s32 idx, s32 *out) {
    u32 cur;
    u32 target;
    s32 i;
    f32 *tbl;
    u16 v;

    if (lbl_1_bss_7EA18 == 0) {
        *out = 0;
        return 0;
    }
    v = lbl_1_bss_7C980[idx];
#define tbl lbl_1_bss_7C780[idx]
    if ((f32)v >= tbl[lbl_1_bss_7C9A4[idx] - 1]) {
        cur = fn_1_3F114() * 0xFFFF;
    } else {
        f32 t0;
        u32 a;
        u32 b;
        u32 lo;
        u32 hi;
        u16 *vals;
        s8 *hiw;
        s32 k;
        f32 r;

        for (i = 0; (f32)v > tbl[i]; i++) {
        }
        a = v;
        i--;
        vals = lbl_1_bss_7C820[idx];
        t0 = tbl[i];
        lo = vals[i];
        hi = vals[i + 1];
        a = (f32)a - t0;
        hiw = lbl_1_bss_7C80C[idx];
        lo += hiw[i] * 0xFFFF;
        hi += hiw[i + 1] * 0xFFFF;
        b = tbl[i + 1] - t0;
        r = (f32)a / (f32)b;
        cur = (f32)((f32)lo * (lbl_1_rodata_6BD0 - r)) + (f32)((f32)hi * r);
    }
    target = lbl_1_rodata_6CB8 * (lbl_1_bss_7EA20 + (f32)lbl_1_bss_7EA24);
    if (target > cur) {
        GhostKey *keys = lbl_1_bss_7C864;
        u32 n = lbl_1_bss_7C9A0;
        f32 sum = lbl_1_rodata_6B60;
        f32 key;
        s32 lo;

        do {
            n--;
            key = (f32)keys[n].h6;
            key += (f32)(keys[n].b1 * 0xFFFF);
            sum += (f32)keys[n].b0;
        } while ((f32)cur < key);
        lo = keys[n].h6 + keys[n].b1 * 0xFFFF;
        sum -= (f32)(u32)(cur - lo) /
               (f32)(u32)(keys[n + 1].h6 + keys[n + 1].b1 * 0xFFFF - lo);
        *out = lbl_1_rodata_6D34 * -sum / lbl_1_rodata_6D10;
    } else {
        s8 *h;
        u16 *p;
        s8 *hiw = lbl_1_bss_7C80C[idx];
        u16 *vals = lbl_1_bss_7C820[idx];
        s32 j;
        s32 lo;
        u32 a;
        u32 b;
        f32 key;
        f32 r;
        f32 *t;

        h = hiw;
        p = vals;
        j = 0;
        do {
            key = (s32)(*p + *h * 0xFFFF);
            h++;
            p++;
            j++;
        } while ((f32)target > key);
        j -= 2;
        a = target;
        lo = vals[j] + hiw[j] * 0xFFFF;
        a -= lo;
        b = vals[j + 1] + hiw[j + 1] * 0xFFFF - lo;
        r = (f32)a / (f32)b;
        t = lbl_1_bss_7C780[idx];
        r = t[j] + (f32)(r * (t[j + 1] - t[j]));
        r = (f32)lbl_1_bss_7C980[idx] - r;
        *out = lbl_1_rodata_6D34 * r / lbl_1_rodata_6D10;
    }
    return 1;
}
/* fzgx:end fn_1_F0E00 */

/* fzgx:begin fn_1_F1300 noprologue */
#include "dolphin/types.h"

extern const f32 lbl_1_rodata_6B60;
extern void lbl_8006D758(void);
extern void mathutil_mtxA_rotate_z(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_x(s16);
extern void fn_8006E5FC(f32 *);

void fn_1_F1300(u32 count, f32 (*quat)[4], s8 *rotX, s16 *rotY, s8 *rotZ)
{
    f32 *prev = quat[0];
    f32 *next = quat[1];
    u32 i;
    for (i = 0; i < count; i++, quat++) {
        lbl_8006D758();
        mathutil_mtxA_rotate_z((s16)(rotZ[i] << 8));
        mathutil_mtxA_rotate_y(rotY[i]);
        mathutil_mtxA_rotate_x((s16)(rotX[i] << 8));
        fn_8006E5FC(quat[0]);
    }
    for (i = 0; i < count - 1; i++) {
        f32 a = prev[0] * next[0];
        f32 b = prev[1] * next[1];
        f32 c = prev[2] * next[2];
        f32 d = prev[3] * next[3];
        if (d + (c + (a + b)) < lbl_1_rodata_6B60) {
            next[0] = -next[0];
            next[1] = -next[1];
            next[2] = -next[2];
            next[3] = -next[3];
        }
        prev += 4;
        next += 4;
    }
}
/* fzgx:end fn_1_F1300 */

/* fzgx:begin fn_1_F143C */
#pragma opt_common_subs off
void fn_1_F143C(FnObject *obj, s32 index, const f32 *a, const f32 *b, void *arg5) {
    u32 *entry;
    f32 dz;
    f32 dy;
    f32 dx;
    f32 d2;
    f32 t;

    obj->field_4 = -2;
    entry = (u32 *)lbl_1_bss_7C914[index];
    if (entry != 0) {
        obj->field_6 = *((s8 *)entry + 0x328);
    }

    obj->field_7c = *(const Vec3 *)a;
    obj->field_0 = 0x400;
    lbl_8006DD14(arg5, obj->_pad_ec);
    obj->field_475 = 0;

    dx = a[0];
    dx = dx - b[0];
    dy = a[1];
    dy = dy - b[1];
    dz = a[2];
    dz = dz - b[2];
    d2 = dx * dx;
    d2 = d2 + dy * dy;
    d2 = d2 + dz * dz;

    if (d2 < lbl_1_rodata_6D38) {
        t = lbl_8006D0B4(d2 / lbl_1_rodata_6D38);
        t = lbl_8006D0B4(t);
        obj->field_224 = lbl_1_rodata_6D3C * t;
        obj->field_200 = lbl_1_rodata_6D40 * t;
    } else {
        obj->field_224 = lbl_1_rodata_6D3C;
        obj->field_200 = lbl_1_rodata_6D40;
    }

    lbl_8006D7DC((void *)a);
    lbl_8006DFC4(arg5);
    lbl_8006DB74(obj->field_14c);
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_F143C */

/* fzgx:begin fn_1_F1588 */
u32 fn_1_F1588(void) {
    u32 value = lbl_1_bss_7EA38[0];

    if (value == 0) {
        return 0;
    }

    if ((f32)value < lbl_1_rodata_6D10) {
        return value % 6 == 0;
    }

    if ((f32)value < lbl_1_rodata_6D44) {
        return value % 10 == 0;
    }

    return (value & 0xf) == 0;
}
/* fzgx:end fn_1_F1588 */

/* fzgx:begin fn_1_F1650 */
#pragma opt_common_subs off
f32 fn_1_F1650(const u32 *value) {
    s32 i;
    u32 bits = value[0];
    s32 sign = (s32)((bits >> 20) & 1);
    u32 exponent = (bits >> 15) & 0x1f;
    f32 place;
    f32 fraction;

    if ((bits >> 15) & 0x10) {
        exponent = ~(exponent - 16);
        exponent = exponent * -1;
    } else {
        exponent = exponent - 15;
    }

    {
    f32 fraction = lbl_1_rodata_6BD0;
    f32 place = lbl_1_rodata_6BBC;
    u32 mantissa = bits & 0x7fff;

    for (i = 0; i < 15; i++) {
        if (mantissa & (1 << (14 - i))) {
            fraction += place;
        }
        place *= lbl_1_rodata_6BBC;
    }

    fraction *= fn_80088598(lbl_1_rodata_6D48, (f64)(s32)exponent);

    if (sign != 0) {
        fraction *= lbl_1_rodata_6D50;
    }

    return fraction;
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_F1650 */

/* fzgx:begin fn_1_F17B4 */
s32 fn_1_F17B4(const void *value) {
    u32 bits;
    s32 exponent;
    s32 sign;
    s32 fraction;
    f64 converted;
    s32 magnitude;
    s32 result;

    fn_80008BA8( (u32)(u32 *)(&bits), (u32)(const void *)(value), 4);

    exponent = (s32)((bits >> 23) & 0xff) - 0x7f;
    sign = bits >> 31;
    fraction = bits & 0x7fffff;

    if (exponent >= 0) {
        exponent = (exponent << 27) >> 27;
        exponent += 0xf;
    } else {
        converted = (f32)exponent;
        converted = __fabs(converted);
        magnitude = (s32)converted;
        magnitude = (magnitude << 27) >> 27;
        exponent = ~magnitude + 0x10;
        exponent = (exponent << 27) >> 27;
    }

    result = sign << 20;
    result += exponent << 15;
    result += fraction >> 8;
    return result;
}
/* fzgx:end fn_1_F17B4 */

/* fzgx:begin ghost_pack_bits */
void ghost_pack_bits(u32 *out, const u32 *x, const u32 *y, const u32 *z) {
    out[0] = 0;
    out[1] = 0;
    out[0] += x[0] << 10;
    out[0] += y[0] >> 11;
    out[1] += y[0] << 21;
    out[1] += z[0];
}
/* fzgx:end ghost_pack_bits */

/* fzgx:begin fn_1_F18C0 */
void fn_1_F18C0(const u32 *in, u32 *x, u32 *y, u32 *z) {
    x[0] = (in[0] >> 10) & 0x1fffff;
    y[0] = 0;
    y[0] += (in[0] & 0x3ff) << 11;
    y[0] += in[1] >> 21;
    z[0] = in[1] & 0x1fffff;
}
/* fzgx:end fn_1_F18C0 */

/* fzgx:begin fn_1_F190C */
void fn_1_F190C(void) {
    fn_80008BEC(&lbl_1_bss_7B1AC, 0, 0x13d8);
    fn_80008BEC(&lbl_1_bss_7C584, 0, 0x1fc);
}
/* fzgx:end fn_1_F190C */

/* fzgx:begin fn_1_F1950 */
// Set the transfer completion flag for the asynchronous callback.
void fn_1_F1950(void) {
    lbl_1_bss_7ECFC.unk_0 = 1;
}
/* fzgx:end fn_1_F1950 */

/* fzgx:begin fn_1_F1960 */
void fn_1_F1960(void *arg0, void *arg1, u32 arg2) {
    u32 result;
    u8 temp[0x20];
    // The completion flag is updated asynchronously by the callback.
    volatile u32 *flag;

    result = fn_8002071C(arg0);
    fn_800206FC(arg2);
    lbl_1_bss_7ECFC.unk_0 = 0;
    while (ARGetDMAStatus() != 0) {
    }
    DCFlushRange(arg1, arg2);
    ARQPostRequest(temp, 1, 0, 1, arg1, arg0, arg2, fn_1_F1950);
    flag = &lbl_1_bss_7ECFC.unk_0;
    while ((s32)*flag == 0) {
    }
    fn_800206FC(result);
}
/* fzgx:end fn_1_F1960 */

/* fzgx:begin fn_1_F1A24 noprologue */
#include "dolphin/types.h"
#include "dolphin/ar.h"

typedef struct {
    u8 pad0[0x16b4];
    u8 *bufs[0x28];        /* 0x16b4 */
    u8 count;              /* 0x1754 */
    u8 pad1[0x3b7c - 0x1755];
    volatile s32 dmaDone;  /* 0x3b7c, set by the ARQ callback fn_1_F1950 */
} GhostAramWork;

typedef struct {
    u8 pad0[0x2d4];
    char file[0x4a0 - 0x2d4];     /* 0x2d4 */
    char fmtA[0x10];              /* 0x4a0 */
    char fmtB[0xc];               /* 0x4b0 */
    char fmtC[0x10];              /* 0x4bc */
} GhostAramStrings;

extern GhostAramWork lbl_1_bss_7B180;
extern GhostAramStrings lbl_1_data_3E358;
extern void *lbl_801A6410;

extern void fn_1_F1950(u32);
extern void fn_1_46B4(void *, void *, const char *, int);
extern void *fn_1_4630(void *, u32, const char *, int);
extern u32 fn_8002071C(void);
extern u32 fn_800206FC(u32);
extern void OSReport(const char *, ...);
extern u32 ARGetDMAStatus(void);
extern void DCInvalidateRange(void *, u32);

void fn_1_F1A24(void)
{
    ARQRequest req;
    GhostAramStrings *str = &lbl_1_data_3E358;
    GhostAramWork *work = &lbl_1_bss_7B180;
    struct { u8 **value; } bufs;
    struct { u8 *value; } buf;
    struct { u32 value; } old;
    u32 i;

    bufs.value = work->bufs;
    old.value = 0;
    for (i = 0; i < work->count; i++) {
        if (bufs.value[i] != NULL) {
            fn_1_46B4(lbl_801A6410, bufs.value[i], str->file, 0x12a7);
        }
        bufs.value[i] = fn_1_4630(lbl_801A6410, 0x3ec0, str->file, 0x12a9);
        buf.value = bufs.value[i];
        old.value = fn_8002071C();
        fn_800206FC(0x3ec0);
        work->dmaDone = 0;
        while (ARGetDMAStatus() != 0) {
        }
        DCInvalidateRange(buf.value, 0x3ec0);
        ARQPostRequest(&req, 1, 1, 1, 0xf24000 + i * 0x3ec0, (u32)buf.value, 0x3ec0, fn_1_F1950);
        while (work->dmaDone == 0) {
        }
        fn_800206FC(old.value);
        buf.value = bufs.value[i];
        OSReport(str->fmtA, buf.value[0]);
        OSReport(str->fmtB, buf.value + 8);
        OSReport(str->fmtC, *(u16 *)(buf.value + 0x18));
    }
}
/* fzgx:end fn_1_F1A24 */

/* fzgx:begin fn_1_F1B78 */
void fn_1_F1B78(u32 value) {
    lbl_1_bss_7C848[0] = value;
}
/* fzgx:end fn_1_F1B78 */

/* fzgx:begin fn_1_F1B84 */
u8 fn_1_F1B84(void) {
    return lbl_1_bss_7C8CD;
}
/* fzgx:end fn_1_F1B84 */

/* fzgx:begin fn_1_F1B94 */
u32 fn_1_F1B94(void) {
    f32 a;
    u8 b;
    u8 *base = (u8 *)&lbl_1_bss_7B180;
    u8 *rec;
    u32 result;
    u8 *cur;
    u32 t0;
    u32 t1;

    if (*(s16 *)&lbl_1_bss_960 == 9) {
        if (*(s32 *)(base + 0x16c8) >= 0) {
            rec = fn_1_3F0D8(0, &a, &b);
            cur = *(u8 **)(base + 0x16b4);
            result = 1;
            t0 = rec[0x1e0] * 60000 + rec[0x1e1] * 1000 + *(u16 *)(rec + 0x1e2);
            t1 = cur[0x24] * 60000 + cur[0x25] * 1000 + *(u16 *)(cur + 0x26);
            if (t0 >= t1) {
                result = 3;
            }
            return result;
        }
        return 0;
    }
    return *(u8 *)(base + 0x174c);
}
/* fzgx:end fn_1_F1B94 */

/* fzgx:begin fn_1_F1C54 pool noprologue */
#include "rel/main_rel/ghost.h"

extern int sprintf(char *, const char *, ...);

#pragma opt_propagation off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_7B180[2];
u32 fzgx_obj_lbl_1_bss_7B188[2];
u32 lbl_1_bss_7B190[2];
u32 lbl_1_bss_7B198;
u32 lbl_1_bss_7B19C;
s32 lbl_1_bss_7B19C_4;
u32 fzgx_obj_lbl_1_bss_7B1A4[2];
u32 fzgx_obj_lbl_1_bss_7B1AC[1270];
u32 fzgx_obj_lbl_1_bss_7C584[177];
u32 lbl_1_bss_7C848;
u8 lbl_1_bss_7C848_4;
u8 lbl_1_bss_7C848_fill_7C84D;
u16 lbl_1_bss_7C848_fill_7C84E;
u32 lbl_1_bss_7C850[3];
u32 fzgx_obj_lbl_1_bss_7C85C[28];
u8 lbl_1_bss_7C85C_fill_7C8CC;
u8 lbl_1_bss_7C8CD;
u8 lbl_1_bss_7C8CE;
u8 lbl_1_bss_7C8CE_fill_7C8CF;
u32 lbl_1_bss_7C8CE_fill_7C8D0[17];
u32 lbl_1_bss_7C914[13];
u32 lbl_1_bss_7C948;
u32 lbl_1_bss_7C94C[67];
u32 lbl_1_bss_7CA58[2020];
u32 fzgx_obj_lbl_1_bss_7E9E8[6];
u32 lbl_1_bss_7EA00[14];
u32 lbl_1_bss_7EA38[159];
u32 fzgx_obj_lbl_1_bss_7ECB4[18];
u32 fzgx_obj_lbl_1_bss_7ECFC;
u8 lbl_1_bss_7ECFC_4;
u8 lbl_1_bss_7ECFC_fill_7ED01;
u16 lbl_1_bss_7ECFC_fill_7ED02;
u32 lbl_1_bss_7ECFC_fill_7ED04[21];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B180;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B188;
    s = *(u8 *)&lbl_1_bss_7B190;
    s = *(u8 *)&lbl_1_bss_7B198;
    s = *(u8 *)&lbl_1_bss_7B19C;
    s = *(u8 *)&lbl_1_bss_7B19C_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1A4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1AC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C584;
    s = *(u8 *)&lbl_1_bss_7C848;
    s = *(u8 *)&lbl_1_bss_7C848_4;
    s = *(u8 *)&lbl_1_bss_7C848_fill_7C84D;
    s = *(u8 *)&lbl_1_bss_7C848_fill_7C84E;
    s = *(u8 *)&lbl_1_bss_7C850;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C85C;
    s = *(u8 *)&lbl_1_bss_7C85C_fill_7C8CC;
    s = *(u8 *)&lbl_1_bss_7C8CD;
    s = *(u8 *)&lbl_1_bss_7C8CE;
    s = *(u8 *)&lbl_1_bss_7C8CE_fill_7C8CF;
    s = *(u8 *)&lbl_1_bss_7C8CE_fill_7C8D0;
    s = *(u8 *)&lbl_1_bss_7C914;
    s = *(u8 *)&lbl_1_bss_7C948;
    s = *(u8 *)&lbl_1_bss_7C94C;
    s = *(u8 *)&lbl_1_bss_7CA58;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7E9E8;
    s = *(u8 *)&lbl_1_bss_7EA00;
    s = *(u8 *)&lbl_1_bss_7EA38;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7ECB4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7ECFC;
    s = *(u8 *)&lbl_1_bss_7ECFC_4;
    s = *(u8 *)&lbl_1_bss_7ECFC_fill_7ED01;
    s = *(u8 *)&lbl_1_bss_7ECFC_fill_7ED02;
    s = *(u8 *)&lbl_1_bss_7ECFC_fill_7ED04;
}
#pragma section code_type ".text"

char *fn_1_F1C54(int idx)
{
    
    u8 a = lbl_1_bss_7C848_4;
    const char * lab_t1;
    if (a != 0xff && ((idx == lbl_1_bss_7C8CE - 1 && lbl_1_bss_7B19C_4 == 0) ||
                      (idx == lbl_1_bss_7C8CE - 2 && lbl_1_bss_7B19C_4 != 0))) {
        lab_t1 = (char *)&lbl_1_data_3E894;
        sprintf((char *)((u8 *)&lbl_1_bss_7ECFC_4 + idx * 0x11), lab_t1);
    } else if (a != 0xff && idx == lbl_1_bss_7C8CE - 1 && lbl_1_bss_7B19C_4 != 0) {
        lab_t1 = (char *)&lbl_1_data_3E89C;
        sprintf((char *)((u8 *)&lbl_1_bss_7ECFC_4 + idx * 0x11), lab_t1, idx);
    } else {
        lab_t1 = (char *)&lbl_1_data_3E89C;
        sprintf((char *)((u8 *)&lbl_1_bss_7ECFC_4 + idx * 0x11), lab_t1, idx + 1);
    }
    return (char *)((u8 *)&lbl_1_bss_7ECFC_4 + idx * 0x11);
}
#pragma opt_propagation reset
/* fzgx:end fn_1_F1C54 */

/* fzgx:begin fn_1_F1D60 */
u32 fn_1_F1D60(void) {
    return lbl_1_bss_7C948;
}
/* fzgx:end fn_1_F1D60 */

/* fzgx:begin fn_1_F1D70 */
void fn_1_F1D70(void) {
    lbl_1_bss_7E9E8.unk_0 = 0;
    lbl_1_bss_7E9E8.unk_4 = 0;
    lbl_1_bss_7E9E8.unk_8 = 0;
    lbl_1_bss_7E9E8.unk_C = 0;
}
/* fzgx:end fn_1_F1D70 */

/* fzgx:begin fn_1_F1D8C */
void fn_1_F1D8C(s32 index) {
    if (index < 0x20) {
        lbl_1_bss_7E9E8.unk_0 |= 1 << index;
        return;
    }
    if (index < 0x40) {
        lbl_1_bss_7E9E8.unk_4 |= 1 << (index - 0x20);
        return;
    }
    if (index < 0x60) {
        lbl_1_bss_7E9E8.unk_8 |= 1 << (index - 0x40);
        return;
    }
    lbl_1_bss_7E9E8.unk_C |= 1 << (index - 0x60);
}
/* fzgx:end fn_1_F1D8C */

/* fzgx:begin fn_1_F1E30 */
void fn_1_F1E30(s32 index) {
    if (index < 0x20) {
        lbl_1_bss_7E9E8.unk_0 &= ~(1 << index);
    } else if (index < 0x40) {
        lbl_1_bss_7E9E8.unk_4 &= ~(1 << (index - 0x20));
    } else if (index < 0x60) {
        lbl_1_bss_7E9E8.unk_8 &= ~(1 << (index - 0x40));
    } else {
        lbl_1_bss_7E9E8.unk_C &= ~(1 << (index - 0x60));
    }
}
/* fzgx:end fn_1_F1E30 */

/* fzgx:begin fn_1_F1ED0 */
void fn_1_F1ED0(s32 index) {
    if (index < 0x20) {
        lbl_1_bss_7E9E8.unk_0 ^= 1 << index;
        return;
    }
    if (index < 0x40) {
        lbl_1_bss_7E9E8.unk_4 ^= 1 << (index - 0x20);
        return;
    }
    if (index < 0x60) {
        lbl_1_bss_7E9E8.unk_8 ^= 1 << (index - 0x40);
        return;
    }
    lbl_1_bss_7E9E8.unk_C ^= 1 << (index - 0x60);
}
/* fzgx:end fn_1_F1ED0 */

/* fzgx:begin ghost_test_flag */
// Tests whether a ghost flag is set in the corresponding 32-bit flag word.
u32 ghost_test_flag(s32 index) {
    if (index < 0x20) {
        return lbl_1_bss_7E9E8.unk_0 & (1 << index);
    }
    if (index < 0x40) {
        return lbl_1_bss_7E9E8.unk_4 & (1 << (index - 0x20));
    }
    if (index < 0x60) {
        return lbl_1_bss_7E9E8.unk_8 & (1 << (index - 0x40));
    }
    return lbl_1_bss_7E9E8.unk_C & (1 << (index - 0x60));
}
/* fzgx:end ghost_test_flag */

/* fzgx:begin fn_1_F2008 */
// Records the flag for the ghost entry identified by the decoded pair.
void fn_1_F2008(s32 arg) {
    s16 a;
    s16 b;
    s32 index;
    u8 *ghost_data;

    fn_1_12EF80((s16)arg, &a, &b);
    index = (a - 1) * 6 + b;
    ghost_data = (u8 *)&lbl_1_bss_7F0C0;
    ghost_data[0x4938 + index] |= 1;
}
/* fzgx:end fn_1_F2008 */

/* fzgx:begin ghost_test_record_flag0 */
// Tests the record flag selected by the supplied ghost identifier.
u32 ghost_test_record_flag0(s32 arg) {
    s16 a;
    s16 b;
    s32 index;
    u8 *record_flags;

    fn_1_12EF80((s16)arg, &a, &b);
    index = (a - 1) * 6 + b;
    record_flags = (u8 *)&lbl_1_bss_7F0C0;
    return record_flags[0x4938 + index] & 1;
}
/* fzgx:end ghost_test_record_flag0 */

/* fzgx:begin ghost_set_record_flag1 */
// Sets the second record flag for the record associated with arg.
void ghost_set_record_flag1(s32 arg) {
    s16 a;
    s16 b;
    s32 index;
    u8 *record_flags;

    fn_1_12EF80((s16)arg, &a, &b);
    index = (a - 1) * 6 + b;
    record_flags = (u8 *)&lbl_1_bss_7F0C0;
    record_flags[0x4938 + index] |= 2;
}
/* fzgx:end ghost_set_record_flag1 */

/* fzgx:begin fn_1_F210C */
u32 fn_1_F210C(s32 arg) {
    s16 out_a;
    s16 out_b;
    s32 index;
    u8 *flags;

    fn_1_12EF80((s16)arg, &out_a, &out_b);
    index = (out_a - 1) * 6 + out_b;
    flags = (u8 *)&lbl_1_bss_7F0C0;
    return flags[0x4938 + index] & 2;
}
/* fzgx:end fn_1_F210C */

/* fzgx:begin ghost_set_record_flag2 */
// Set the second flag on the record selected by the argument.
void ghost_set_record_flag2(s32 arg) {
    s16 record_group;
    s16 record_index;
    s32 flag_index;
    u8 *flags;

    fn_1_12EF80((s16)arg, &record_group, &record_index);
    flag_index = (record_group - 1) * 6 + record_index;
    flags = (u8 *)&lbl_1_bss_7F0C0;
    flags[0x4938 + flag_index] |= 4;
}
/* fzgx:end ghost_set_record_flag2 */

/* fzgx:begin fn_1_F21B8 */
// Return the selected record's second flag bit after decoding its table position.
s32 fn_1_F21B8(s32 arg) {
    s16 a;
    s16 b;
    s32 index;
    u8 *flags;

    fn_1_12EF80((s16)arg, &a, &b);
    index = (a - 1) * 6 + b;
    flags = (u8 *)&lbl_1_bss_7F0C0;
    return flags[0x4938 + index] & 4;
}
/* fzgx:end fn_1_F21B8 */

/* fzgx:begin fn_1_F220C */
// Logs the resolved course coordinates and marks the corresponding course as visited.
void fn_1_F220C(s32 arg) {
    s16 a;
    s16 b;
    s32 index;

    fn_1_12EF80((s16)arg, &a, &b);
    index = (a - 1) * 6 + b;
    OSReport((const char *)lbl_1_data_3E8A0, a, b, index);
    ((u8 *)&lbl_1_bss_7F0C0)[0x4938 + index] |= 8;
}
/* fzgx:end fn_1_F220C */

/* fzgx:begin fn_1_F2280 */
// Returns the flag for the state selected by the converted coordinates.
s32 fn_1_F2280(s32 arg) {
    s16 group;
    s16 entry;
    s32 index;
    u8 *state_flags;

    fn_1_12EF80((s16)arg, &group, &entry);
    index = (group - 1) * 6 + entry;
    state_flags = (u8 *)&lbl_1_bss_7F0C0;
    return state_flags[0x4938 + index] & 8;
}
/* fzgx:end fn_1_F2280 */

/* fzgx:begin fn_1_F22D4 */
u32 fn_1_F22D4(void) {
    return lbl_1_bss_7B190[0];
}
/* fzgx:end fn_1_F22D4 */

/* fzgx:begin fn_1_F23D8 */
void fn_1_F23D8(void) {
    lbl_1_bss_7ED58[0] = 0;
}
/* fzgx:end fn_1_F23D8 */

/* fzgx:begin fn_1_F23E8 pool noprologue */
#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} GhostVec;

typedef struct {
    u8 unk_00[0x328];
    s8 unk_328;
    u8 unk_329[0x0B];
    void ***unk_334;
} GhostEntry;

/* One per-player camera record, 0x620 bytes (stride used by fn_1_EE3F4). */
typedef struct {
    u32 unk_0;
    s16 unk_4;
    s16 unk_6;
    u8 pad_8[0x7C - 0x8];
    GhostVec unk_7C;
    u8 pad_88[0xEC - 0x88];
    u8 unk_EC[0x14C - 0xEC];
    u8 unk_14C[0x200 - 0x14C];
    f32 unk_200;
    u8 pad_204[0x224 - 0x204];
    f32 unk_224;
    u8 pad_228[0x475 - 0x228];
    u8 unk_475;
    u8 pad_476[0x620 - 0x476];
} GhostCamera;

typedef struct {
    f32 m[3][4];
} GhostMtx;

typedef struct {
    f32 x, y, z, w;
} GhostQuat;

extern s16 lbl_1_bss_960;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_7B180[2];
u8 lbl_1_bss_7B180__fzgx_offset_8[0x1600 - 0x8];
u32 lbl_1_bss_7B180__fzgx_offset_1600;
u8 lbl_1_bss_7B180__fzgx_offset_1604[0x10];
u32 lbl_1_bss_7B180__fzgx_offset_1614;
u8 lbl_1_bss_7B180__fzgx_offset_1618[0x10];
u32 lbl_1_bss_7B180__fzgx_offset_1628;
u8 lbl_1_bss_7B180__fzgx_offset_162C[0x10];
u32 lbl_1_bss_7B180__fzgx_offset_163C;
u8 lbl_1_bss_7B180__fzgx_offset_1640[0x88];
s32 lbl_1_bss_7B180__fzgx_offset_16C8;
u8 lbl_1_bss_7B180__fzgx_offset_16CC[0x20];
u32 lbl_1_bss_7B180__fzgx_offset_16EC;
u8 lbl_1_bss_7B180__fzgx_offset_16F0[0x10];
u32 lbl_1_bss_7B180__fzgx_offset_1700;
u8 lbl_1_bss_7B180__fzgx_offset_1704[0x10];
u32 lbl_1_bss_7B180__fzgx_offset_1714;
u8 lbl_1_bss_7B180__fzgx_offset_1718[0x10];
u32 lbl_1_bss_7B180__fzgx_offset_1728;
u8 lbl_1_bss_7B180__fzgx_offset_172C[0x68];
GhostEntry *lbl_1_bss_7B180__fzgx_offset_1794;
u8 lbl_1_bss_7B180__fzgx_offset_1798[0x8C];
s32 lbl_1_bss_7B180__fzgx_offset_1824;
u8 lbl_1_bss_7B180__fzgx_offset_1828[0x19C8 - 0x1828];
GhostCamera lbl_1_bss_7B180__fzgx_offset_19C8[4];
u8 lbl_1_bss_7B180__fzgx_offset_3248[0x3BD8 - 0x3248];
s32 lbl_1_bss_7B180__fzgx_offset_3BD8;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B180;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1600;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1604;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1614;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1618;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1628;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_162C;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_163C;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1640;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_16C8;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_16CC;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_16EC;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_16F0;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1700;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1704;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1714;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1718;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1728;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_172C;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1794;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1798;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1824;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1828;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_19C8;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_3248;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_3BD8;
}
#pragma section code_type ".text"

#define ghostCameras lbl_1_bss_7B180__fzgx_offset_19C8
#define ghostEntry lbl_1_bss_7B180__fzgx_offset_1794
#define ghostFrame lbl_1_bss_7B180__fzgx_offset_1824
#define ghostTimer lbl_1_bss_7B180__fzgx_offset_3BD8

extern const f32 lbl_1_rodata_6B60;  /* 0.0f */
extern const f32 lbl_1_rodata_6BBC;  /* 0.5f */
extern const f32 lbl_1_rodata_6BD0;  /* 1.0f */
extern const f64 lbl_1_rodata_6C88;  /* 2^52 + 2^31 */
extern const f32 lbl_1_rodata_6C90;  /* 0.3f */
extern const f32 lbl_1_rodata_6D3C;  /* 5.0f */
extern const f32 lbl_1_rodata_6D40;  /* 2.5f */
extern const f32 lbl_1_rodata_6D54;  /* 120.0f */
extern const f32 lbl_1_rodata_6D58;  /* 0.34f */

extern u32 fn_1_F5458(GhostQuat *, s32, u32, u32, f32);
extern f32 fn_1_F4E3C(s32, u32, u32, u32, f32);
extern void fn_1_556B8(void *);
extern void fn_1_55FF0(f32);
extern void fn_1_5621C(f32, f32, f32, f32);
extern void fn_1_56298(f32, f32, f32, f32);
extern void fn_1_983CC(void *, GhostEntry *);
extern void fn_1_98634(f32);
extern void fn_80072558(void);
extern void fn_80074A60(u32, u32);
extern void fn_80074A6C(void);
extern void lbl_8006D758(void);
extern void lbl_8006D7DC(GhostVec *);
extern void lbl_8006DB74(void *);
extern u32 lbl_8006DCA4(void);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E0A4(GhostVec *);
extern void lbl_8006E0B4(f32, f32, f32);
extern void mathutil_mtxA_from_quat(GhostQuat *);

#pragma opt_dead_assignments off
void fn_1_F23E8(void) {
    GhostMtx mtx;
    GhostQuat quat;
    GhostVec pos;
    f32 height;
    f32 scale;
    f32 t;
    f32 lab_t4;
    f32 lab_t4_;

    if (lbl_1_bss_960 == 9 && lbl_1_bss_7B180__fzgx_offset_16C8 != -1) {
        lab_t4_ = lbl_1_rodata_6B60;
        fn_1_F5458(&quat, ghostFrame, lbl_1_bss_7B180__fzgx_offset_1600, lbl_1_bss_7B180__fzgx_offset_1728, lab_t4_);
        lab_t4 = lbl_1_rodata_6B60;
        pos.x = fn_1_F4E3C(ghostFrame, lbl_1_bss_7B180__fzgx_offset_1600, lbl_1_bss_7B180__fzgx_offset_1614, lbl_1_bss_7B180__fzgx_offset_16EC, lab_t4);
        lab_t4 = lbl_1_rodata_6B60;
        pos.y = fn_1_F4E3C(ghostFrame, lbl_1_bss_7B180__fzgx_offset_1600, lbl_1_bss_7B180__fzgx_offset_1628, lbl_1_bss_7B180__fzgx_offset_1700, lab_t4);
        lab_t4 = lbl_1_rodata_6B60;
        pos.z = fn_1_F4E3C(ghostFrame, lbl_1_bss_7B180__fzgx_offset_1600, lbl_1_bss_7B180__fzgx_offset_163C, lbl_1_bss_7B180__fzgx_offset_1714, lab_t4);

        if (ghostTimer > 180 && ghostTimer < 300) {
            height = ghostTimer - 180;
            height /= lbl_1_rodata_6D54;
            scale = height * height;
            height = height * lbl_1_rodata_6D58;
        } else if (ghostTimer >= 300) {
            height = lbl_1_rodata_6D58;
            scale = lbl_1_rodata_6BD0;
        } else {
            height = lbl_1_rodata_6B60;
            scale = height;
        }

        fn_1_56298(lbl_1_rodata_6B60, lbl_1_rodata_6B60, lbl_1_rodata_6B60, lbl_1_rodata_6B60);
        fn_1_5621C(lbl_1_rodata_6BD0, lbl_1_rodata_6BD0, lbl_1_rodata_6BD0, lbl_1_rodata_6BD0);
        fn_80074A60(4, 1);
        mathutil_mtxA_from_quat(&quat);
        lbl_8006DB74(&mtx);

        ghostCameras[1].unk_7C = pos;
        ghostCameras[1].unk_7C.y += height;
        lbl_8006D7DC(&ghostCameras[1].unk_7C);
        lbl_8006DB74(ghostCameras[1].unk_14C);
        ghostCameras[1].unk_224 = lbl_1_rodata_6D3C * scale;
        ghostCameras[1].unk_200 = lbl_1_rodata_6D40 * scale;
        lbl_8006DCA4();
        lbl_8006E0A4(&pos);
        lbl_8006E0B4(lbl_1_rodata_6B60, height, lbl_1_rodata_6B60);
        lbl_8006DFC4(&mtx);
        fn_80072558();
        fn_1_55FF0(lbl_1_rodata_6BBC * scale);
        fn_1_556B8(*ghostEntry->unk_334);
        fn_1_55FF0(lbl_1_rodata_6BD0);
        fn_80074A6C();

        if (ghostTimer == 0) {
            ghostCameras[1].unk_4 = -2;
            if (ghostEntry != NULL) {
                ghostCameras[1].unk_6 = ghostEntry->unk_328;
            }
            ghostCameras[1].unk_7C = pos;
            ghostCameras[1].unk_0 = 0x400;
            lbl_8006D758();
            lbl_8006DB74(ghostCameras[1].unk_EC);
            ghostCameras[1].unk_475 = 0;
            ghostCameras[1].unk_224 = lbl_1_rodata_6D3C;
            ghostCameras[1].unk_200 = lbl_1_rodata_6D40;
            lbl_8006D7DC(&pos);
            lbl_8006DB74(ghostCameras[1].unk_14C);
            fn_1_98634(lbl_1_rodata_6C90);
            fn_1_983CC(&ghostCameras[1], ghostEntry);
            fn_1_98634(lbl_1_rodata_6B60);
        }
        ghostTimer++;
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_F23E8 */
