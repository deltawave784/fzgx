#include "types.h"
#include "rel/customize/globals.h"

typedef struct CustomizeNameEntry {
    const char *names[6];
} CustomizeNameEntry;

struct fn_3_3438_lbl_3_data_B8 {
    u32 unk_0;
};

struct fn_3_4BEC_lbl_3_data_B8 {
    u32 unk_0;
};

struct fn_3_9710_lbl_3_data_B8 {
    u32 unk_0;
};

struct fn_3_61B8_lbl_1_bss_6EAD0 {
    u32 unk_0;
};

struct fn_3_61B8_lbl_3_bss_120 {
    u32 unk_0;
};

struct fn_3_61B8_lbl_3_bss_243A8 {
    u32 unk_0;
};

typedef struct {
    u8 pad_0[8];
    u16 unk_8;
    u8 pad_A[6];
    volatile u16 unk_10; /* Volatile: retail rereads controller flags for each direction. */
    volatile u16 unk_12; /* Volatile: retail rereads alternate controller flags for each direction. */
} Controller;

typedef struct fn_3_78C8_CustomizeEntry {
    u8 pad[0x20];
    s16 count;
    s16 values[0x0a];
} fn_3_78C8_CustomizeEntry;

typedef struct {
    s16 index;
} Fn3AF8Arg;

struct Entry { u8 pad_390[0x390]; u32 flags; u8 pad_394[0x10]; u32 ready; u8 pad_3a8[0x98]; };

typedef struct {
    u8 pad[0x324];
    s32 value;
    u8 tail[0x118];
} fn_3_5E88_CustomizeEntry;

struct fn_3_4C58_Copy160 { u32 a[41]; };

typedef struct {
    void *value;
} Sig_fn_1_FD27C_fn_1_FD27C_Fn1FD27CArg0;

typedef struct {
    u8 pad[0x40f0];
    void *value;
} Sig_fn_1_FD27C_fn_1_FD27C_Fn1FD27CArg1;

struct InitData { u32 words[41]; };

struct fn_3_60C8_lbl_1_bss_6D82C {
    u32 unk_0;
};

typedef struct {
    s16 id;
    u8 pad_2[0x2];
    u32 mask;
    u8 flags;
    u8 pad_9[0x17];
} CustomizeSlot;

typedef struct {
    u8 pad[0x324];
    u32 value;
    u8 tail[0x118];
} fn_3_5F28_CustomizeEntry;

struct fn_3_60C8_lbl_3_bss_20854 {
    u32 unk_0;
};

struct fn_3_60C8_lbl_3_data_11D4 {
    u32 unk_0;
};

struct fn_3_679C_lbl_3_bss_7E080 {
    u32 unk_0;
};

struct fn_3_968C_lbl_3_data_11D8 {
    u32 unk_0;
};

struct fn_3_9710_lbl_3_data_11D8 {
    u32 unk_0;
};
extern void fn_3_2B774(void);
extern void fn_3_BD30(void);
extern void fn_1_4A00(s32 fadeIn, u8 steps, u32 arg);
extern void fn_1_A2D84(u32 arg0);
extern s16 lbl_1_bss_962;
extern s32 lbl_1_bss_970;
extern s16 lbl_1_bss_968;
extern u32 lbl_1_bss_6EAB4;
extern u32 lbl_3_bss_2084C;
extern u32 fn_1_435C(u32 value);
extern void fn_1_407C();
extern void fn_1_3CC4(void);
extern void camera_update(void);
extern u8 lbl_3_data_1230[924];
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;
extern char *fn_80083DB0(char *dst, const char *src);
extern u8 *fn_80083970(u8 *str, const u8 *needle);
extern size_t strlen(const char *str);
extern char *strncpy(char *dst, const char *src, size_t n);
extern char *strcat(char *dest, const char *src);
extern s32 lbl_801A66B4;
extern u8 lbl_3_bss_2437C[44];
extern CustomizeNameEntry lbl_3_data_E80[2];
extern char lbl_3_data_15CC[5];
extern void fn_3_BFC(char *destination, void *unused, const char *source, const char *suffix);
extern u32 fn_1_4AEC0(u32 value);
extern void fn_1_4AEB4(f32 value);
extern void fn_1_49410(void);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_4954C(f32 value);
extern void fn_1_495C8(u8 value);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_4966C(f32 value1, f32 value2);
extern void fn_1_495B0(u32 value);
extern void fn_1_49590(f32 value);
extern void fn_1_4A0D8(const char *);
extern void fn_3_E64();
extern void fn_1_131004(void);
extern u32 fn_1_426C(u32);
extern void fn_1_47F74(s32 index);
extern u32 lbl_3_data_BC[2];
extern s16 lbl_1_bss_96A;
extern s32 lbl_3_data_B8;
extern void fn_3_968C();
extern void fn_3_4A84(void);
extern void fn_1_48140(int index);
extern void fn_1_130EE8(u32 arg0, u32 arg1);
extern s32 fn_1_3F8C(u32 arg3, u32 arg0, u32 arg1, u32 index);
extern void fn_3_4218(void);
extern void fn_3_4C58(void);
extern void fn_3_7CF8(void);
extern void fn_3_9800(void);
extern void fn_3_255DC(void);
extern void fn_3_273F4(void);
extern void fn_3_29508(void);
extern void fn_3_29C94(void);
extern void fn_3_2AAF4(void);
extern u32 fn_1_A176C(u32, u32);
extern u32 lbl_1_bss_6EAD0;
extern s32 lbl_3_bss_120;
extern u32 lbl_3_bss_243A8[6];
extern void fn_3_2C164(void);
extern void fn_3_5F28(void);
extern s16 lbl_3_data_C4;
extern u32 fn_1_152CB4(s16, s32, s32, void *, s16, s16);
extern u32 fn_1_8D5F0(s16 index);
extern s32 fn_1_F7BE4(s32);
extern u8 lbl_1_bss_9F8[];
extern u32 lbl_3_bss_2C584[98];
extern s32 fn_1_152970(s16 *, s16 *, s16, u32, void *, s16, s16);
extern void fn_3_7A08(s16 *, s16 *, int);
extern void fn_3_BD00(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern s16 lbl_3_bss_20[104];
extern u32 lbl_3_bss_243C0;
extern s32 fn_3_837C(s16);
extern u32 lbl_3_data_B4;
extern s32 fn_3_4538(void);
extern int fn_3_AF8(Fn3AF8Arg *arg);
extern int fn_1_4C10(void);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern void fn_1_1280(u32 arg0);
extern void fn_3_60C8(void);
extern int fn_1_FD324(void *arg0);
extern s32 lbl_3_bss_2C70C[45];
extern u32 fn_1_FD844(void *, void *);
extern void fn_3_5D84(s16);
extern fn_3_5E88_CustomizeEntry lbl_3_bss_20860[4];
extern u8 lbl_3_bss_21960[];
extern u32 lbl_3_bss_2C7C0[66624];
extern struct fn_3_4C58_Copy160 lbl_3_rodata_F8;
extern void *fn_1_7F254(void *arg0, void *arg1);
extern void fn_1_FD27C(Sig_fn_1_FD27C_fn_1_FD27C_Fn1FD27CArg0 *, Sig_fn_1_FD27C_fn_1_FD27C_Fn1FD27CArg1 *);
extern void fn_1_FDC00(void);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_3_5E88(s16);
extern void fn_1_7F3AC(u32);
extern struct InitData lbl_3_rodata_1A4;
extern u32 lbl_3_bss_6DD70;
extern void fn_3_11FB4(u8 value_47, u8 value_46, u32 value_7EDC0);
extern u8 lbl_3_data_1814[208];
extern void fn_3_3AE8(int, u8 *, int);
extern f32 lbl_3_rodata_44[45];
extern void fn_8006CE1C(f32 arg0);
extern u32 lbl_3_rodata_248[6];
extern u32 lbl_3_bss_6DD78[42];
extern f32 fn_1_A6FE8(void);
extern void fn_1_DCE60(void *);
extern u32 lbl_1_bss_6D82C;
extern void fn_1_80F1C(s32 arg0, void *arg1);
extern void fn_1_14DBCC(void *);
extern void fn_80071718(u32);
extern CustomizeSlot lbl_3_bss_7DB60[41];
extern fn_3_5F28_CustomizeEntry *lbl_3_bss_20854;
extern void fn_1_80058(s8 arg0, u8 *arg1);
extern void fn_1_12A32C(void *arg0);
extern void fn_1_12A2B8(u32 value);
extern void fn_1_80C18(u8 *arg0, u8 *arg1, s8 arg2);
extern struct fn_3_60C8_lbl_3_data_11D4 lbl_3_data_11D4;
extern u32 fn_1_12A734(u32);
extern void fn_1_12A2D0(s32 value);
extern void fn_1_7F934(void *arg0);
extern void fn_1_15BB34(u32 arg0);
extern s32 fn_8006FDEC(void);
extern u8 jumptable_3_data_18E4[40];
extern void fn_1_F7D6C(void);
extern void fn_1_F7E24(void);
extern void fn_1_F7D18(void);
extern void fn_1_F7DC0(void);
extern u32 fn_1_F8A38(u32 value);
extern void fn_1_F8AD4(u32 value);
extern void fn_1_F8A58(u32 value);
extern void fn_1_F83F0(s32);
extern u8 fn_1_F8C50(s32 arg0);
extern void fn_1_F8C74(s32 value);
extern void fn_1_F8C00(s32 value);
extern struct fn_3_679C_lbl_3_bss_7E080 lbl_3_bss_7E080;
extern u32 fn_1_15BBC4(void);
extern u32 lbl_3_bss_8;
extern void fn_3_65B0(u32);
extern s16 fn_3_6AC4(void);
extern void fn_1_FDFF4(void);
extern void fn_1_FC4E0(void *arg0, int arg1);
extern u32 lbl_3_bss_7EBA4;
extern u32 lbl_3_bss_7EBA8;
extern u8 lbl_3_data_11DC[84];
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_1_BC29C(void);
extern void fn_1_B9C0C(void);
extern char lbl_3_data_1A1C[17];
extern u8 fn_1_B7C00(void);
extern u8 fn_1_B7CD4(void);
extern u32 fn_1_B7C5C(void);
extern void OSReport(const char *format, ...);
extern u32 lbl_3_bss_A179C;
extern u32 lbl_3_data_1A14;
extern s16 lbl_3_bss_6D8C0[600];
extern u8 lbl_3_bss_7E240[1200];
extern s16 fn_1_14F014(void);
extern s16 fn_3_7360(void);
extern void fn_1_DCED0(u32 *);
extern s32 lbl_3_bss_C[3];
extern s32 lbl_3_data_11D8;
extern u32 lbl_3_bss_6DE20;
extern void fn_1_F8580(void);
extern void fn_1_14DC68(void *, int);
extern s16 lbl_3_data_A8[6];
extern const f32 lbl_3_rodata_260;
extern u8 lbl_3_data_1930[40];
extern void fn_1_4AE0C(const char* format, ...);
extern int fn_1_F8334(s16 value);
extern u32 fn_1_14D6D8(s16 index);
extern s16 fn_1_14F344(s16 index);
extern s32 fn_1_F809C(s32 value);
extern u32 lbl_3_bss_20848;
extern void fn_1_14E9E4(int arg0, void *arg1);
extern void fn_1_12AB38(void *arg0);
extern void *fn_1_D3884(void *);
extern void fn_1_12A2C4(u32 value);
extern void fn_1_14D994(void *, u32, u32);
extern void fn_3_7A30(void);
extern s32 fn_8008023C(u32 arg0, u32 arg1, u32 arg2);
extern void fn_3_7B94(void);
extern void fn_1_151BDC(u32 value);
extern void fn_1_FE5C4(u8 arg0, u32 arg1, u32 arg2, u8 arg3);
extern void fn_3_BC60(void);
extern void fn_3_5A50(void);
extern void fn_1_496FC(f32, f32);

/* fzgx:begin fn_3_0 noprologue */
#include "types.h"
#include "rel/customize/globals.h"

extern u16 lbl_3_bss_20[104];
extern void fn_80008BA8(u32, u32, u32);
extern s16 fn_1_14F118(s16, s16);
extern s32 fn_1_F809C(s32);
extern s16 fn_1_14F090(s16, s16);
extern s16 fn_1_14F01C(s16);
extern u32 fn_1_151BE8(s16, s32);
extern int fn_1_8D690(int);

typedef struct {
    u8 id;
    u8 pad_1[3];
    u32 data[1];
} SelSlot;

typedef struct {
    SelSlot slot[3];
    u8 pad_18[2];
    s16 sel[3];
    u8 pad_20[0xAE];
    s16 mode;
} SelState;

#define SEL ((SelState *)lbl_3_bss_20)

/* lbl_3_bss_140 holds 0x81C0-byte save entries; the macros take the entry's byte offset. */
#define ENTRY_SIZE 0x81C0
#define ENTRY_FLAGS(o) (*(u32 *)((u8 *)&lbl_3_bss_140 + (o)))
#define ENTRY_SLOTS(o) ((u8 *)&lbl_3_bss_140 + (o) + 0x81A4)
#define ENTRY_MODE(o) (*(u8 *)((u32)&lbl_3_bss_140 + 0x81A0 + (o)))

/* Pick the first available item in each of the three slots. */
static inline void fn_3_0_reset(void) {
    s16 i;
    s16 j;

    for (i = 0; i < 3; i++) {
        SEL->sel[i] = 0;
        SEL->slot[i].id = fn_1_14F090(i, SEL->sel[i]);
        while (fn_1_F809C(SEL->slot[i].id) == 0) {
            s32 n;
            s32 max;
            max = fn_1_14F01C(i) - 1;
            n = SEL->sel[i] + 1;
            if (n > max) {
                n = 0;
            } else if (n < 0) {
                n = fn_1_14F01C(i) - 1;
            }
            SEL->sel[i] = n;
            SEL->slot[i].id = fn_1_14F090(i, SEL->sel[i]);
        }
        for (j = 0; j < 1; j++) {
            SEL->slot[i].data[j] = fn_1_151BE8(SEL->slot[i].id, j);
        }
    }
}

void fn_3_0(s16 idx, s32 check) {
    s32 off = idx * ENTRY_SIZE;
    s16 i;
    s32 bad;

    if (ENTRY_FLAGS(off) & 0x80000000) {
        if (ENTRY_FLAGS(off) & 0x40000000) {
            bad = 0;
            fn_80008BA8((u32)lbl_3_bss_20, (u32)ENTRY_SLOTS(off), 0x18);
            for (i = 0; i < 3; i++) {
                SEL->sel[i] = fn_1_14F118(SEL->slot[i].id, i);
                if (SEL->sel[i] == -1) {
                    bad = 1;
                }
                if (check != 0 && fn_1_F809C(SEL->slot[i].id) == 0) {
                    bad = 1;
                }
                if (bad == 1) {
                    fn_3_0_reset();
                    SEL->mode = 6;
                    return;
                }
            }
            if (check != 0 && fn_1_8D690(ENTRY_MODE(off)) == 0) {
                SEL->mode = 6;
                return;
            }
            SEL->mode = ENTRY_MODE(off);
        } else {
            fn_3_0_reset();
            SEL->mode = 6;
            SEL->mode = ENTRY_MODE(off);
        }
    } else {
        fn_3_0_reset();
        SEL->mode = 6;
    }
}
/* fzgx:end fn_3_0 */

/* fzgx:begin fn_3_844 noprologue */
#include "types.h"

extern void fn_3_2B774(void);
extern void fn_3_BD30(void);
extern void fn_1_4A00(u32, u32, u32);
extern void fn_1_A2D84(u32);

extern s16 lbl_1_bss_962;
extern struct {
    u8 pad[8];
    u16 flags;
} lbl_1_bss_9F8;
extern s32 lbl_1_bss_970;
extern s16 lbl_1_bss_968;
extern u32 lbl_1_bss_6EAB4;
extern u32 lbl_3_bss_20850;

void fn_3_844(void) {
    fn_3_2B774();
    fn_3_BD30();

    if (lbl_1_bss_962 == 0x5c) {
        if ((lbl_1_bss_9F8.flags >> 9) & 1) {
            fn_1_4A00(0, 0xf, lbl_3_bss_20850);
            lbl_1_bss_970 = 0x10;
            fn_1_A2D84(0xA9010200);
            lbl_1_bss_6EAB4 |= 0x24;
        }

        if (lbl_1_bss_970 > 0) {
            if (--lbl_1_bss_970 == 0) {
                lbl_1_bss_968 = 1;
            }
        }
    }
}
/* fzgx:end fn_3_844 */

/* fzgx:begin fn_3_8F8 */
void fn_3_8F8(void) {
    fn_1_435C(lbl_3_bss_2084C);
    fn_1_407C();
    fn_1_3CC4();
    camera_update();
    fn_1_435C(lbl_3_bss_20850);
    fn_1_407C();
}
/* fzgx:end fn_3_8F8 */

/* fzgx:begin fn_3_AF8 */
int fn_3_AF8(Fn3AF8Arg *arg) {
    u32 *entry = (u32 *)((((u8 *)&lbl_3_bss_140)) + arg->index * 0x81c0);

    *entry |= (u32)1 << 31;
    *entry &= 0xBFFFFFFF;
    return 0;
}
/* fzgx:end fn_3_AF8 */

/* fzgx:begin fn_3_B30 */
typedef struct {
    s16 index;
} Fn3B30Data;

s32 fn_3_B30(Fn3B30Data *data) {
    s16 index = data->index;
    u32 *entry = (u32 *)((((u8 *)&lbl_3_bss_140)) + index * 0x81c0);
    *entry |= (u32)1 << 31;
    *entry |= (u32)1 << 30;
    return 0;
}
/* fzgx:end fn_3_B30 */

/* fzgx:begin fn_3_B68 */
s32 fn_3_B68(const s16 *value) {
    u8 *base = (((u8 *)&lbl_3_bss_140));
    s32 offset = (s32)*value * 0x81c0;
    u32 *entry = (u32 *)(base + offset);

    *entry &= 0xbfffffffu;
    *entry &= 0x7fffffffu;
    return 0;
}
/* fzgx:end fn_3_B68 */

/* fzgx:begin fn_3_BA0 */
typedef struct fn_3_BA0_CustomizeEntry {
    u8 pad[0x20];
    void (*function)(void);
    u32 value24;
    u32 value28;
} fn_3_BA0_CustomizeEntry;


void fn_3_BA0(void) {
    fn_3_BA0_CustomizeEntry *entry;
    s16 index;

    entry = (fn_3_BA0_CustomizeEntry *)lbl_3_data_1230;
    index = lbl_1_bss_962;
    entry += index - 0x5b;
    lbl_1_bss_71688 = entry->value24;
    lbl_1_bss_7168C = entry->value28;
    entry->function();
}
/* fzgx:end fn_3_BA0 */

/* fzgx:begin fn_3_BFC */
void fn_3_BFC(char *destination, void *unused, const char *source, const char *suffix) {
    char buffer[0x400];
    char *prefix;
    unsigned int source_length;
    unsigned int prefix_length;

    fn_80083DB0(buffer, unused);
    prefix = (char *)fn_80083970( (u8 *)(char *)(buffer), (const u8 *)(const char *)(source));
    if (prefix == 0) {
        fn_80083DB0(destination, buffer);
    } else {
        source_length = (unsigned int)strlen(source);
        if (prefix != buffer) {
            prefix_length = (unsigned int)(prefix - buffer);
            strncpy(destination, buffer, prefix_length);
            destination[prefix_length] = 0;
        } else {
            destination[0] = 0;
        }
        strcat(destination, suffix);
        strcat(destination, prefix + source_length);
    }
}
/* fzgx:end fn_3_BFC */

/* fzgx:begin fn_3_E64 pool */
#include "types.h"

typedef struct { u8 r, g, b, a; } Color;

/* Retail .data head (lbl_3_data_0 .. 0xC6): the part index tables. */
u16 probe_head[99] = {
    0x0001, 0x0000, 0x0003, 0x0007, 0x0008, 0x0009, 0x000A, 0x000B, 0x000C, 0x000D,
    0x000E, 0x000F, 0x0010, 0x0011, 0x0012, 0x0013, 0x0014, 0x0015, 0x0016, 0x0017,
    0x0018, 0x0019, 0x001A, 0x001B, 0x001C, 0x001D, 0x001E, 0x001F, 0x0020, 0x0021,
    0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027, 0x0028, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0x0006, 0x0002, 0x0005, 0x0004, 0x0001, 0x0000, 0x0003, 0x0007,
    0x0008, 0x0009, 0x000A, 0x000B, 0x000C, 0x000D, 0x000E, 0x000F, 0x0010, 0x0011,
    0x0012, 0x0013, 0x0014, 0x0015, 0x0016, 0x0017, 0x0018, 0x0019, 0x001A, 0x001B,
    0x001C, 0x001D, 0x001E, 0x001F, 0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025,
    0x0026, 0x0027, 0x0028, 0xFFFF,
    0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF
};
u8 probe_pad0[0xE1C - 0xC8] = {1};
char *probe_tblA[9] = {0};
char *probe_tblB[9] = {0};
u8 probe_pad1[0x15D4 - 0xE64] = {1};

extern Color fn_800081C8(Color, Color, f32);
extern void fn_1_49410(void);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495C8(u8);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_4D494(void);
extern void fn_1_49514(Color);
extern void fn_1_49528(Color);
extern void fn_1_4954C(f32);
extern void fn_1_4AE0C(const char *, ...);
extern u32 fn_1_4D4C8(Color, f32, f32);

/* Retail literal pool (lbl_3_rodata_0 onward), primed in first-use order. */

#pragma section code_type ".fzgxpool"
static void fzgx_base_order_data(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: the TU references .data before its other sections */
    s = *(u8 *)&probe_head;
    s = *(u8 *)&probe_pad0;
    s = *(u8 *)&probe_tblA;
    s = *(u8 *)&probe_tblB;
    s = *(u8 *)&probe_pad1;
}
#pragma section code_type ".text"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 240.0f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = 0.5f;
    s = 480.0f;
    s = 2.0f;
    s = 176.0f;
}
static const u32 fzgx_pool_table3[7] = {0x00000000, 0x00000000, 0x41200000, 0x41200000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.25f;
    s = 0.0f;
}
static const u32 fzgx_pool_table5[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 500.0f;
    s = 300.0f;
    s = 0.10000000149011612f;
}
static const u32 fzgx_pool_table7[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.5f;
    s = -1.0f;
    s = 8.0f;
    s = 4.0f;
    s = 150.0f;
    s = 0.09000000357627869f;
    s = 30.0f;
    s = 0.550000011920929f;
    s = 0.75f;
    d = 4503601774854144.0;
}
#pragma section code_type ".text"

void fn_3_E64(u8 *arg0) {
    Color from = {0xA0, 0x50, 0x50, 0x00};
    Color to = {0xA0, 0xA0, 0xA0, 0x00};
    Color color;
    f32 s;

    color = fn_800081C8(from, to, 1.0f);
    fn_1_49410();
    s = 0.75f;
    fn_1_4955C(s, s);
    fn_1_495C8(9);
    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
        fn_1_4966C(-1.0f, 4.0f);
    }
    fn_1_496FC(288.0f, 320.0f);
    fn_1_495C8(10);
    if (*arg0 == 0) {
        fn_1_4D494();
        {
            Color white0 = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(white0);
        }
        fn_1_4954C(0.08f);
        fn_1_4AE0C("%s", probe_tblA[lbl_801A66B4]);
        fn_1_4D4C8(color, 0.09f, 10.0f);
    } else {
        {
            Color grey0 = {0x70, 0x70, 0x70, 0x00};
            fn_1_49514(grey0);
        }
        {
            Color black0 = {0x00, 0x00, 0x00, 0x00};
            fn_1_49528(black0);
        }
        fn_1_4954C(0.08f);
        fn_1_4AE0C("%s", probe_tblA[lbl_801A66B4]);
    }
    fn_1_496FC(352.0f, 320.0f);
    fn_1_495C8(8);
    if (*arg0 == 0) {
        {
            Color grey1 = {0x70, 0x70, 0x70, 0x00};
            fn_1_49514(grey1);
        }
        {
            Color black1 = {0x00, 0x00, 0x00, 0x00};
            fn_1_49528(black1);
        }
        fn_1_4954C(0.08f);
        fn_1_4AE0C("%s", probe_tblB[lbl_801A66B4]);
    } else {
        fn_1_4D494();
        {
            Color white1 = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(white1);
        }
        fn_1_4954C(0.08f);
        fn_1_4AE0C("%s", probe_tblB[lbl_801A66B4]);
        fn_1_4D4C8(color, 0.09f, 10.0f);
    }
}
/* fzgx:end fn_3_E64 */

/* fzgx:begin fn_3_131C */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 240.0f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = 0.5f;
    s = 480.0f;
    s = 2.0f;
    s = 176.0f;
}
static const u32 fzgx_pool_table3[7] = {0x00000000, 0x00000000, 0x41200000, 0x41200000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.25f;
    s = 0.0f;
}
static const u32 fzgx_pool_table5[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 500.0f;
    s = 300.0f;
    s = 0.10000000149011612f;
}
static const u32 fzgx_pool_table7[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.5f;
    s = -1.0f;
    s = 8.0f;
    s = 4.0f;
    s = 150.0f;
    s = 0.09000000357627869f;
    s = 30.0f;
    s = 0.550000011920929f;
    s = 0.75f;
    d = 4503601774854144.0;
}
#pragma section code_type ".text"

void fn_3_131C(s32 y, void *source) {
    char buffer[0x400];
    f32 scale;

    fn_1_4AEC0(1);
    fn_1_4AEB4(1.5f);
    fn_1_49410();
    scale = 0.75f;
    fn_1_4955C(scale, scale);
    fn_1_4954C(0.09f);
    fn_1_495C8(9);
    fn_1_496FC(320.0f, (f32)y);
    fn_1_4966C(-1.0f, 8.0f);
    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
        fn_1_4966C(-1.0f, 4.0f);
    }
    fn_3_BFC(buffer, source, lbl_3_data_15CC, lbl_3_data_E80[lbl_3_bss_2437C[0]].names[lbl_801A66B4]);
    fn_3_BFC(buffer, buffer, lbl_3_data_15CC, lbl_3_data_E80[lbl_3_bss_2437C[0]].names[lbl_801A66B4]);
    fn_3_BFC(buffer, buffer, lbl_3_data_15CC, lbl_3_data_E80[lbl_3_bss_2437C[0]].names[lbl_801A66B4]);
    fn_1_4A0D8(buffer);
    fn_1_4AEC0(0);
    fn_1_4AEB4(0.0f);
}
/* fzgx:end fn_3_131C */

/* fzgx:begin fn_3_14C4 */
void fn_3_14C4(void) {
    fn_3_E64();
}
/* fzgx:end fn_3_14C4 */

/* fzgx:begin fn_3_33A0 */
void fn_3_33A0(void) {
    fn_1_131004();
    if (*(s32 *)lbl_3_data_BC != -1) {
        fn_1_435C(lbl_3_bss_20850);
        fn_1_426C(lbl_3_data_BC[0]);
        lbl_3_data_BC[0] = (u32)-1;
    }
    if (*(u32 *)(((u16 *)&lbl_3_bss_F0)) & ((u32)1 << 31)) {
        fn_1_47F74(0x85);
        fn_1_47F74(0xa1);
    }
    *(u32 *)(((u16 *)&lbl_3_bss_F0)) &= 0x02ffffff;
}
/* fzgx:end fn_3_33A0 */

/* fzgx:begin fn_3_3438 noprologue */
#include "types.h"

struct fn_3_3438_lbl_3_bss_F0 {
    u32 unk_0;
};
struct fn_3_3438_lbl_3_data_B8 {
    u32 unk_0;
};
struct fn_3_3438_lbl_3_bss_20850 {
    u32 unk_0;
};
extern s16 lbl_1_bss_96A;
extern struct fn_3_3438_lbl_3_bss_20850 lbl_3_bss_20850;
extern struct fn_3_3438_lbl_3_bss_F0 lbl_3_bss_F0;
extern struct fn_3_3438_lbl_3_data_B8 lbl_3_data_B8;
extern void fn_3_968C(void);
extern u32 fn_1_435C(u32);
extern void fn_3_4A84(void);
extern void fn_1_48140(int);

s32 fn_1_426C(u32);                             /* extern */
s32 fn_3_5A50();                                /* extern */
s32 fn_3_AC4C();                                /* extern */

void fn_3_3438(void) {
    if ((lbl_3_bss_F0.unk_0 & 0x40000000) && ((s16) (*(s16 *)((u8 *)(&lbl_1_bss_96A) + 0)) != 0x6B)) {
        fn_3_968C();
        if ((s32) lbl_3_data_B8.unk_0 != -1) {
            fn_1_435C(lbl_3_bss_20850.unk_0);
            fn_1_426C(lbl_3_data_B8.unk_0);
            lbl_3_data_B8.unk_0 = -1U;
        }
    } else if ((lbl_3_bss_F0.unk_0 & 0x20000000) && ((s16) (*(s16 *)((u8 *)(&lbl_1_bss_96A) + 0)) != 0x6C)) {
        fn_3_AC4C();
        if ((s32) lbl_3_data_B8.unk_0 != -1) {
            fn_1_435C(lbl_3_bss_20850.unk_0);
            fn_1_426C(lbl_3_data_B8.unk_0);
            lbl_3_data_B8.unk_0 = -1U;
        }
    } else if ((lbl_3_bss_F0.unk_0 & 0x10000000) && ((s16) (*(s16 *)((u8 *)(&lbl_1_bss_96A) + 0)) != 0x60)) {
        fn_3_4A84();
        if ((s32) lbl_3_data_B8.unk_0 != -1) {
            fn_1_435C(lbl_3_bss_20850.unk_0);
            fn_1_426C(lbl_3_data_B8.unk_0);
            lbl_3_data_B8.unk_0 = -1U;
        }
    } else if ((lbl_3_bss_F0.unk_0 & 0x08000000) && ((s16) (*(s16 *)((u8 *)(&lbl_1_bss_96A) + 0)) != 0x68)) {
        if ((s32) lbl_3_data_B8.unk_0 != -1) {
            fn_1_435C(lbl_3_bss_20850.unk_0);
            fn_1_426C(lbl_3_data_B8.unk_0);
            lbl_3_data_B8.unk_0 = -1U;
        }
    } else if ((lbl_3_bss_F0.unk_0 & 0x04000000) && ((s16) (*(s16 *)((u8 *)(&lbl_1_bss_96A) + 0)) != 0x5F)) {
        fn_3_5A50();
        if ((s32) lbl_3_data_B8.unk_0 != -1) {
            fn_1_435C(lbl_3_bss_20850.unk_0);
            fn_1_426C(lbl_3_data_B8.unk_0);
            lbl_3_data_B8.unk_0 = -1U;
        }
    } else if (lbl_3_bss_F0.unk_0 & 0x01000000) {
        fn_1_48140(0xA3);
        if ((s32) lbl_3_data_B8.unk_0 != -1) {
            fn_1_435C(lbl_3_bss_20850.unk_0);
            fn_1_426C(lbl_3_data_B8.unk_0);
            lbl_3_data_B8.unk_0 = -1U;
        }
    }
    lbl_3_bss_F0.unk_0 &= 0x02FFFFFF;
}
/* fzgx:end fn_3_3438 */

/* fzgx:begin fn_3_368C noprologue */
#include "types.h"

struct fn_3_368C_lbl_3_data_0 {
    u8 pad_0[0xB8];
    u32 unk_B8;
};
struct fn_3_368C_lbl_3_bss_0 {
    u8 pad_0[0xF0];
    u32 unk_F0;
    u8 pad_F4[0x2C];
    u32 unk_120;
};

extern struct fn_3_368C_lbl_3_bss_0 lbl_3_bss_0;
extern struct fn_3_368C_lbl_3_data_0 lbl_3_data_0;
extern u32 fn_1_130EE8(u32, u32);
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_47F74(u32);
extern u32 fn_3_4218(void);
extern u32 fn_3_4C58(void);
extern u32 fn_3_7CF8(void);
extern u32 fn_3_9800(void);
extern void fn_3_255DC(void);
extern void fn_3_273F4(void);
extern void fn_3_29508(void);
extern void fn_3_29C94(void);
extern void fn_3_2AAF4(void);

u32 fn_3_368C(void) {
    struct fn_3_368C_lbl_3_data_0 *p_lbl_3_data_0;
    struct fn_3_368C_lbl_3_bss_0 *p_lbl_3_bss_0;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;
    p_lbl_3_bss_0 = (struct fn_3_368C_lbl_3_bss_0 *)&lbl_3_bss_0;
    p_lbl_3_data_0 = &lbl_3_data_0;
    v0 = ((u32)p_lbl_3_bss_0 + 0x20000);
    *(u8 *)((u8 *)v0 + 17316) = 0;
    v1 = *(u32 *)((u8 *)v0 + 2124);
    *(u32 *)((u8 *)v0 + 17312) = 0;
    fn_1_130EE8(v1, *(u32 *)((u8 *)v0 + 2128));
    v2 = p_lbl_3_bss_0->unk_F0;
    p_lbl_3_bss_0->unk_120 = -1;
    v3 = v2;
    if ((v2 & 0x40000000) != 0 && (s32)p_lbl_3_data_0->unk_B8 == -1) {
    t1 = fn_3_7CF8();
    v3 = t1;
    v3 = (u32)((u8 *)(u32)p_lbl_3_data_0 + 5736);
    t2 = fn_1_3F8C((u32)v3, (u32)fn_3_255DC, 0, 8);
    v3 = t2;
    p_lbl_3_data_0->unk_B8 = v3;
    } else {
    if ((v3 & 0x20000000) != 0 && (s32)p_lbl_3_data_0->unk_B8 == -1) {
    t3 = fn_3_9800();
    v3 = t3;
    v3 = (u32)((u8 *)(u32)p_lbl_3_data_0 + 5752);
    t4 = fn_1_3F8C((u32)v3, (u32)fn_3_273F4, 0, 8);
    v3 = t4;
    p_lbl_3_data_0->unk_B8 = v3;
    } else {
    if ((v3 & 0x10000000) != 0 && (s32)p_lbl_3_data_0->unk_B8 == -1) {
    t5 = fn_3_4218();
    v3 = t5;
    v3 = (u32)((u8 *)(u32)p_lbl_3_data_0 + 5768);
    t6 = fn_1_3F8C((u32)v3, (u32)fn_3_29508, 0, 8);
    v3 = t6;
    p_lbl_3_data_0->unk_B8 = v3;
    } else {
    if ((v3 & 0x8000000) == 0 || (s32)p_lbl_3_data_0->unk_B8 != -1) {
    if ((v3 & 0x4000000) != 0 && (s32)p_lbl_3_data_0->unk_B8 == -1) {
    t7 = fn_3_4C58();
    v3 = t7;
    v3 = (u32)((u8 *)(u32)p_lbl_3_data_0 + 5784);
    t8 = fn_1_3F8C((u32)v3, (u32)fn_3_29C94, 0, 8);
    v3 = t8;
    p_lbl_3_data_0->unk_B8 = v3;
    } else {
    if ((v3 & 0x1000000) != 0 && (s32)p_lbl_3_data_0->unk_B8 == -1) {
    v3 = 163;
    t9 = fn_1_47F74(v3);
    v3 = t9;
    v3 = (u32)((u8 *)(u32)p_lbl_3_data_0 + 5800);
    t10 = fn_1_3F8C((u32)v3, (u32)fn_3_2AAF4, 0, 8);
    v3 = t10;
    p_lbl_3_data_0->unk_B8 = v3;
    }
    }
    }
    }
    }
    }
    return v3;
}
/* fzgx:end fn_3_368C */

/* fzgx:begin fn_3_381C pool noprologue */
#include "rel/customize/globals.h"

extern s32 lbl_3_data_B4;
extern s16 lbl_1_bss_96A;
extern s32 fn_1_1310E0(void);
extern int fn_1_4C10(void);
extern void fn_1_131050(u32, u32);
extern void fn_1_1310B8(void);
extern void fn_1_4A00(s32, u8, u32);

typedef struct {
    u32 flags;
    u8 pad_4[0x20];
    u32 mode;
} CustomizeInput;

typedef struct {
    s32 openMenu;        /* 0x0 */
    s32 openSub;         /* 0x4 */
    s32 openOther;       /* 0x8 */
    u8 pad_C[0xf0 - 0xc];
    CustomizeInput input; /* 0xf0 */
    u8 pad_118[0x8];
    s32 pending;         /* 0x120 */
} CustomizeWork;

typedef struct {
    u8 pad_0[0x850];
    u32 unk_850;
    u8 pad_854[0x437c - 0x854];
    u8 unk_437C;
    u8 pad_437D[0x43a0 - 0x437d];
    s32 unk_43A0;
    u8 unk_43A4;
    u8 pad_43A5[3];
    s32 unk_43A8;
} CustomizeWorkHi;

static inline int fn_3_381C_busy(CustomizeInput *in)
{
    if ((in->mode & 0x80000000) && !(in->mode & 1) && !(in->flags & 2)) {
        return 1;
    }
    if (fn_1_4C10() != 0) {
        return 1;
    }
    return 0;
}

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
s32 fzgx_obj_lbl_3_bss_0;
s32 lbl_3_bss_0_4;
s32 lbl_3_bss_8;
u32 lbl_3_bss_C[3];
u32 fzgx_obj_lbl_3_bss_18[2];
u32 fzgx_obj_lbl_3_bss_20[52];
CustomizeInput fzgx_obj_lbl_3_bss_F0;
u32 lbl_3_bss_F0_fill_118[2];
s32 lbl_3_bss_120;
u32 lbl_3_bss_120_fill_124[7];
u32 fzgx_obj_lbl_3_bss_140[33217];
u16 lbl_3_bss_20844;
u16 lbl_3_bss_140_gap_20846;
u32 fzgx_obj_lbl_3_bss_20848;
u32 lbl_3_bss_2084C;
u32 fzgx_obj_lbl_3_bss_20850;
u32 fzgx_obj_lbl_3_bss_20854[3];
u32 lbl_3_bss_20860[1088];
u32 fzgx_obj_lbl_3_bss_21960[2592];
u32 fzgx_obj_lbl_3_bss_241E0[100];
u32 lbl_3_bss_24370[3];
u8 lbl_3_bss_2437C;
u8 lbl_3_bss_2437C_fill_2437D;
u16 lbl_3_bss_2437C_fill_2437E;
u32 lbl_3_bss_2437C_fill_24380[8];
s32 lbl_3_bss_2437C_24;
u8 lbl_3_bss_2437C_28;
u8 lbl_3_bss_2437C_fill_243A5;
u16 lbl_3_bss_2437C_fill_243A6;
s32 lbl_3_bss_243A8;
u32 lbl_3_bss_243A8_fill_243AC[5];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_3_bss_0;
    s = *(u8 *)&lbl_3_bss_0_4;
    s = *(u8 *)&lbl_3_bss_8;
    s = *(u8 *)&lbl_3_bss_C;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_18;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_20;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_F0;
    s = *(u8 *)&lbl_3_bss_F0_fill_118;
    s = *(u8 *)&lbl_3_bss_120;
    s = *(u8 *)&lbl_3_bss_120_fill_124;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_140;
    s = *(u8 *)&lbl_3_bss_20844;
    s = *(u8 *)&lbl_3_bss_140_gap_20846;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_20848;
    s = *(u8 *)&lbl_3_bss_2084C;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_20850;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_20854;
    s = *(u8 *)&lbl_3_bss_20860;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_21960;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_241E0;
    s = *(u8 *)&lbl_3_bss_24370;
    s = *(u8 *)&lbl_3_bss_2437C;
    s = *(u8 *)&lbl_3_bss_2437C_fill_2437D;
    s = *(u8 *)&lbl_3_bss_2437C_fill_2437E;
    s = *(u8 *)&lbl_3_bss_2437C_fill_24380;
    s = *(u8 *)&lbl_3_bss_2437C_24;
    s = *(u8 *)&lbl_3_bss_2437C_28;
    s = *(u8 *)&lbl_3_bss_2437C_fill_243A5;
    s = *(u8 *)&lbl_3_bss_2437C_fill_243A6;
    s = *(u8 *)&lbl_3_bss_243A8;
    s = *(u8 *)&lbl_3_bss_243A8_fill_243AC;
}
#pragma section code_type ".text"

void fn_3_381C(void)
{
    
    
    s32 *saved;
    s32 pending;

    if (fn_1_1310E0() != 0) {
        return;
    }
    if (lbl_3_bss_120 == -1) {
        fn_1_4C10();
    }
    if (fn_3_381C_busy(&fzgx_obj_lbl_3_bss_F0)) {
        return;
    }
    pending = lbl_3_bss_120;
    if (pending != -1) {
        lbl_3_bss_120 = -1;
        lbl_1_bss_96A = pending;
        return;
    }
    if (fzgx_obj_lbl_3_bss_0 != 0) {
        lbl_3_bss_2437C_24 = 1;
        fzgx_obj_lbl_3_bss_0 = 0;
        fn_1_131050((u32)&fzgx_obj_lbl_3_bss_140, lbl_3_bss_2437C);
        return;
    }
    if (lbl_3_bss_0_4 != 0) {
        lbl_3_bss_2437C_24 = 1;
        lbl_3_bss_0_4 = 0;
        fn_1_131050((u32)&fzgx_obj_lbl_3_bss_140, 4);
        return;
    }
    if (lbl_3_bss_8 != 0) {
        lbl_3_bss_2437C_28 = 1;
        lbl_3_bss_2437C_24 = 1;
        lbl_3_bss_8 = 0;
        fn_1_1310B8();
        return;
    }
    if (fn_1_1310E0() != 0) {
        return;
    }
    lbl_3_bss_120 = 0x5f;
    saved = &lbl_3_data_B4;
    if (*saved != -1) {
        lbl_3_bss_120 = *saved;
        *saved = -1;
    }
    if ((lbl_3_bss_120 == 0x5f && !(fzgx_obj_lbl_3_bss_F0.flags & 0x04000000)) ||
        (fzgx_obj_lbl_3_bss_F0.flags & 0x01000000)) {
        fn_1_4A00(0, 0xf, fzgx_obj_lbl_3_bss_20850);
        lbl_3_bss_243A8 = 0;
        return;
    }
    if (lbl_3_bss_120 == 0x5f && (fzgx_obj_lbl_3_bss_F0.flags & 0x04000000)) {
        fzgx_obj_lbl_3_bss_F0.flags |= 0x02000000;
    }
}
/* fzgx:end fn_3_381C */

/* fzgx:begin fn_3_3E58 noprologue */
#include "types.h"

extern struct fn_3_3E58_lbl_3_bss_20850 lbl_3_bss_20850;
extern struct fn_3_3E58_lbl_3_data_0 lbl_3_data_0;
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_47F74(u32);
extern u32 fn_1_4A00(u32, u32, u32);
extern u32 fn_1_A176C(u32, u32);
extern u32 lbl_1_bss_6EAD0;
extern u32 lbl_3_bss_120;
extern u32 lbl_3_bss_243A8;
extern void fn_3_2C164(void);

struct fn_3_3E58_lbl_3_data_0 {
    u8 pad_0[0xB8];
    u32 unk_B8;
    u8 pad_BC[0x8];
    s16 unk_C4;
};
struct fn_3_3E58_lbl_3_bss_20850 {
    u32 unk_0;
};

u32 fn_3_3E58(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    struct fn_3_3E58_lbl_3_data_0 *p_lbl_3_data_0;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 t1, t2, t3, t4, t5;
    p_lbl_3_data_0 = (struct fn_3_3E58_lbl_3_data_0 *)&lbl_3_data_0;
    fn_1_4A00(1, 15, lbl_3_bss_20850.unk_0);
    lbl_3_bss_243A8 = 0;
    p_lbl_3_data_0->unk_C4 = -1;
    t1 = fn_1_435C(lbl_3_bss_20850.unk_0);
    v0 = arg1;
    v1 = t1;
    v2 = arg2;
    v3 = arg3;
    if ((s32)p_lbl_3_data_0->unk_B8 == -1) {
    v1 = (u32)((u8 *)p_lbl_3_data_0 + 6144);
    v0 = (u32)fn_3_2C164;
    v2 = 0;
    v3 = 8;
    t2 = fn_1_3F8C((u32)v1, (u32)v0, v2, v3);
    v1 = t2;
    p_lbl_3_data_0->unk_B8 = v1;
    }
    v0 = 46;
    v1 = (u32)&lbl_1_bss_6EAD0;
    v1 = *(u32 *)((u8 *)v1 + 0);
    v1 = *(u32 *)((u8 *)v1 + 0);
    t3 = fn_1_A176C(v1, v0);
    v1 = t3;
    v0 = (u32)&lbl_3_bss_120;
    v1 = 133;
    *(u32 *)((u8 *)v0 + 0) = -1;
    t4 = fn_1_47F74(v1);
    v1 = t4;
    v1 = 161;
    t5 = fn_1_47F74(v1);
    v1 = t5;
    return v1;
}
/* fzgx:end fn_3_3E58 */

/* fzgx:begin fn_3_3F20 noprologue */
#include "types.h"

struct fn_3_3F20_lbl_3_bss_F0 {
    u32 unk_0;
    s16 unk_4;
    s16 unk_6;
    u8 pad_8[0x1C];
    u32 unk_24;
};

/* 20-byte input record */
struct fn_3_3F20_pad {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_A[0x6];
    u16 unk_10;
    u16 unk_12;
};

extern int fn_1_4C10(void);
extern void fn_1_4A00(s32, u8, u32);
extern void fn_1_A2D84(u32);
extern s32 lbl_3_bss_120;
extern u32 lbl_3_bss_20850;
extern struct fn_3_3F20_lbl_3_bss_F0 lbl_3_bss_F0;
extern s16 lbl_1_bss_96A;
extern struct fn_3_3F20_pad lbl_1_bss_9F8[];
extern u32 lbl_3_bss_243A8;
extern u32 lbl_801A66A8;

static inline int fn_3_3F20_busy(void) {
    u32 flags = lbl_3_bss_F0.unk_24;
    if ((flags & 0x80000000) && !(flags & 1) && !(lbl_3_bss_F0.unk_0 & 2)) {
        return 1;
    }
    if (fn_1_4C10() != 0) {
        return 1;
    }
    return 0;
}

/* volatile: the hardware-fed button word is re-read for every test (retail reloads it) */
static inline int fn_3_3F20_bit(volatile u16 *word, int bit) {
    return (*word >> bit) & 1;
}

static inline void fn_3_3F20_input(s16 init) {
    struct fn_3_3F20_lbl_3_bss_F0 *state;
    s16 dir;
    s16 delta;
    s32 idx;
    s32 next;

    dir = init;
    delta = dir;
    idx = lbl_3_bss_F0.unk_6;
    if ((lbl_1_bss_9F8[idx].unk_10 & 1) || (lbl_1_bss_9F8[idx].unk_12 & 1)) {
        delta--;
        fn_1_A2D84(0xA9010000);
        lbl_801A66A8 = 0;
    }
    if ((lbl_1_bss_9F8[idx].unk_10 >> 1 & 1) || (lbl_1_bss_9F8[idx].unk_12 >> 1 & 1)) {
        delta++;
        fn_1_A2D84(0xA9010000);
        lbl_801A66A8 = 0;
    }

    state = &lbl_3_bss_F0;
    next = state->unk_4 + delta;
    state->unk_4 = (next > 2) ? 0 : (next < 0) ? 2 : next;

    if (fn_3_3F20_bit(&lbl_1_bss_9F8[idx].unk_8, 8)) {
        dir = 1;
        fn_1_A2D84(0xA9010100);
    } else if (fn_3_3F20_bit(&lbl_1_bss_9F8[idx].unk_8, 9)) {
        fn_1_A2D84(0xA9010200);
        dir = -1;
    }

    if (dir != 0) {
        fn_1_4A00(0, 15, lbl_3_bss_20850);
        lbl_3_bss_243A8 = 0;
    }
    if (dir == -1) {
        lbl_3_bss_120 = 0x5E;
    } else if (dir == 1) {
        switch (state->unk_4) {
        case 0:
            lbl_3_bss_120 = 0x5E;
            break;
        case 1:
            lbl_3_bss_120 = 100;
            break;
        case 2:
            lbl_3_bss_120 = 110;
            break;
        default:
            lbl_3_bss_120 = 0x5E;
            break;
        }
    }
}

void fn_3_3F20(void) {

    if (lbl_3_bss_120 == -1) {
        fn_1_4C10();
    }
    if (fn_3_3F20_busy()) {
        return;
    }
    if (lbl_3_bss_120 != -1) {
        lbl_1_bss_96A = lbl_3_bss_120;
        lbl_3_bss_120 = -1;
        return;
    }

    fn_3_3F20_input(0);
}
/* fzgx:end fn_3_3F20 */

/* fzgx:begin fn_3_41B0 */
void fn_3_41B0(void) {
    if (lbl_3_data_B8 != -1) {
        fn_1_435C((*((s32 *)&lbl_3_bss_20850)));
        fn_1_426C(lbl_3_data_B8);
        lbl_3_data_B8 = -1;
    }
    fn_1_48140(0x85);
    fn_1_48140(0xa1);
}
/* fzgx:end fn_3_41B0 */

/* fzgx:begin fn_3_4218 */
void fn_3_4218(void) {
    fn_3_5F28();
    fn_1_47F74(0x4a);
    fn_1_47F74(0x54);
    fn_1_47F74(0x38);
    fn_1_47F74(0x3e);
    fn_1_47F74(0x37);
    fn_1_47F74(0x55);
    fn_1_47F74(0x30);
    fn_1_47F74(0x35);
    fn_1_47F74(0x3a);
    fn_1_47F74(0x40);
    fn_1_47F74(0x44);
    fn_1_47F74(0x50);
    fn_1_47F74(0x33);
    fn_1_47F74(0x2e);
    fn_1_47F74(0x31);
    fn_1_47F74(0x4f);
    fn_1_47F74(0x39);
    fn_1_47F74(0x3d);
    fn_1_47F74(0x4c);
    fn_1_47F74(0x3f);
    fn_1_47F74(0x48);
    fn_1_47F74(0x52);
    fn_1_47F74(0x45);
    fn_1_47F74(0x53);
    fn_1_47F74(0x3c);
    fn_1_47F74(0x56);
    fn_1_47F74(0x43);
    fn_1_47F74(0x42);
    fn_1_47F74(0x32);
    fn_1_47F74(0x2f);
    fn_1_47F74(0x34);
    fn_1_47F74(0x36);
    fn_1_47F74(0x4d);
    fn_1_47F74(0x46);
    fn_1_47F74(0x41);
    fn_1_47F74(0x51);
    fn_1_47F74(0x4e);
    fn_1_47F74(0x47);
    fn_1_47F74(0x3b);
    fn_1_47F74(0x4b);
    fn_1_47F74(0x49);
}
/* fzgx:end fn_3_4218 */

/* fzgx:begin fn_3_4380 pool noprologue */
#include "types.h"

typedef struct {
    u8 pad_0[0x9E];
    u8 unk_9E;
} Fn3_4380_Bss8B3A0;

typedef struct {
    u8 pad_0[0xC4];
    s16 unk_C4;
    u8 pad_C6[0xA];
} Fn3_4380_State20;

typedef struct {
    u8 pad_0[0x6];
    s16 unk_6;
    s16 unk_8;
    u8 pad_A[0x26];
} Fn3_4380_StateF0;

typedef struct {
    u32 flags;
    u8 pad_4[0x81BC];
} Fn3_4380_Slot;

extern s16 lbl_1_bss_966;
extern Fn3_4380_Bss8B3A0 lbl_1_bss_8B3A0;
extern u8 lbl_3_data_0[];

/* this TU's .bss, in retail order (addressed off one section base) */
u32 lbl_3_bss_0[2];
u32 lbl_3_bss_0_gap_8[6];
Fn3_4380_State20 lbl_3_bss_20;
Fn3_4380_StateF0 lbl_3_bss_F0;
s32 lbl_3_bss_120[8];
Fn3_4380_Slot lbl_3_bss_140[4];
u32 lbl_3_bss_140_gap_20840;
u32 lbl_3_bss_20844[3];
u32 lbl_3_bss_20850[0xED6];
u32 lbl_3_bss_243A8[0x2077];
u32 lbl_3_bss_2C584[98];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_3_bss_0;
    s = *(u8 *)&lbl_3_bss_0_gap_8;
    s = *(u8 *)&lbl_3_bss_20;
    s = *(u8 *)&lbl_3_bss_F0;
    s = *(u8 *)&lbl_3_bss_120;
    s = *(u8 *)&lbl_3_bss_140;
    s = *(u8 *)&lbl_3_bss_140_gap_20840;
    s = *(u8 *)&lbl_3_bss_20844;
    s = *(u8 *)&lbl_3_bss_20850;
    s = *(u8 *)&lbl_3_bss_243A8;
    s = *(u8 *)&lbl_3_bss_2C584;
}
#pragma section code_type ".text"

extern s32 fn_1_3F8C(void *, void (*)(void), u32, u32);
extern s32 fn_8006FDEC(void);
extern void fn_1_152208(void *, s32, void *, s32, s32);
extern s32 fn_1_152970(s16 *, s16 *, s16, u32, void *, s16, s16);
extern void fn_1_4A00(s32, u8, u32);
extern void fn_3_29508(void);
extern void fn_3_4218(void);
extern void fn_3_7A08(s16 *, s16 *, int);

void fn_3_4380(void) {
    u8 *data;
    s16 v;
    s16 a;
    s16 b;
    s16 lo;
    s16 hiv;

    data = lbl_3_data_0;
    v = lbl_3_bss_F0.unk_6;
    if (lbl_1_bss_966 != 0x5d) {
        fn_1_4A00(1, 15, lbl_3_bss_20850[0]);
        lbl_3_bss_243A8[0] = 0;
        if (*(s32 *)(data + 0xb8) == -1) {
            fn_8006FDEC();
            *(s32 *)(data + 0xb8) = fn_1_3F8C(data + 0x1688, fn_3_29508, 0, 8);
        }
        fn_3_4218();
        lbl_3_bss_20.unk_C4 = 0;
    }
    lbl_3_bss_140[lbl_3_bss_F0.unk_8].flags |= 0x80000000;
    lbl_3_bss_140[lbl_3_bss_F0.unk_8].flags &= ~0x40000000;
    fn_1_152208(data + 0x54, 0x2a, lbl_3_bss_2C584, 7, 7);
    lbl_1_bss_8B3A0.unk_9E = v;
    if (*(s16 *)(data + 0xc4) == -1) {
        *(s16 *)(data + 0xc4) = 6;
    } else {
        do {
            fn_1_152970(&a, &b, *(s16 *)(data + 0xc4), 0, lbl_3_bss_2C584, 7, 7);
            fn_3_7A08(&lo, &hiv, 3);
            if (a < lo || a > hiv) {
                lbl_3_bss_20.unk_C4--;
            }
        } while (a < lo || a > hiv);
    }
    lbl_3_bss_120[0] = -1;
}
/* fzgx:end fn_3_4380 */

/* fzgx:begin fn_3_4538 noprologue */
#include "types.h"

#include "rel/customize/globals.h"

extern s16 lbl_3_data_C4;
extern u32 fn_1_152CB4(s16, s32, s32, void *, s16, s16);
extern u32 fn_1_8D5F0(s32);
extern s32 fn_1_F7BE4(s32);
typedef struct {
    u8 pad_0[8];
    u16 unk_8;
    u8 pad_A[6];
    volatile u16 unk_10; /* Volatile: retail rereads controller flags for each direction. */
    volatile u16 unk_12; /* Volatile: retail rereads alternate controller flags for each direction. */
} Controller;
extern Controller lbl_1_bss_9F8[];
extern u32 lbl_3_bss_2C584[98];
extern void fn_1_A2D84(u32);
extern s32 fn_1_152970(s16 *, s16 *, s16, u32, void *, s16, s16);
extern void fn_3_7A08(s16 *, s16 *, int);
extern void fn_3_BD00(u32, u32, u32, u32);
extern s16 lbl_3_bss_20[104];
extern u32 lbl_3_bss_243C0[8304];
extern s32 fn_3_837C(s16);

struct SaveRecord {
    u8 pad_0[5];
    u8 unk_5;
    u8 pad_6[0x819A];
    u8 machine;
    u8 pad_81A1[0x1F];
};
#pragma opt_common_subs on

s32 fn_3_4538(void) {
    Obj_3_bss_F0 *p_lbl_3_bss_F0;
    s32 v1;
    s32 result;
    s32 v7;
    s32 v9;
    s16 v2;
    s16 v0;
    s32 v4;
    s32 v3;
    s16 lo, hi, x, y;
    p_lbl_3_bss_F0 = (Obj_3_bss_F0 *)&lbl_3_bss_F0;
    v0 = lbl_3_data_C4;
    v1 = p_lbl_3_bss_F0->unk_6;
    v2 = p_lbl_3_bss_F0->unk_8;
    result = 0;
    v7 = 0;
    v9 = 0;
    v4 = 0;
    for (v3 = 0; (s16)v3 < 41; v3++) {
        if ((fn_1_8D5F0(v3) & 0x10000000) && fn_1_F7BE4(v3)) {
            v4 = 1;
            break;
        }
    }
    if (((lbl_1_bss_9F8[v1].unk_10 >> 3) & 1) || ((lbl_1_bss_9F8[v1].unk_12 >> 3) & 1)) v7 = -1;
    if (((lbl_1_bss_9F8[v1].unk_10 >> 2) & 1) || ((lbl_1_bss_9F8[v1].unk_12 >> 2) & 1)) v7++;
    if ((lbl_1_bss_9F8[v1].unk_10 & 1) || (lbl_1_bss_9F8[v1].unk_12 & 1)) v9 = -1;
    if (((lbl_1_bss_9F8[v1].unk_10 >> 1) & 1) || ((lbl_1_bss_9F8[v1].unk_12 >> 1) & 1)) v9++;
    if ((s16)v9 != 0 || (s16)v7 != 0) {
        s32 selected = fn_1_152CB4(lbl_3_data_C4, v7, v9, lbl_3_bss_2C584, 7, 7);
        *(u16 *)&lbl_3_data_C4 = selected;
        if (!v4) {
            selected = (s16)selected;
            if (((u16)(selected - 24) <= 2 || selected == 27) && (s16)v7 > 0 && v0 == selected)
                lbl_3_data_C4 = 30;
        } else {
            if ((s16)selected == 34 && (s16)v7 > 0 && v0 == (s16)selected)
                lbl_3_data_C4 = 40;
        }
    }
    if (v0 != lbl_3_data_C4) fn_1_A2D84(0xA9010000);
    fn_1_152970(&x, &y, lbl_3_data_C4, 0, lbl_3_bss_2C584, 7, 7);
    fn_3_7A08(&lo, &hi, 3);
    if (x < lo || x > hi) {
        fn_3_BD00(v7, 0, (s16)(v7 * 10), 0x800000);
        lbl_3_bss_20[98] -= v7;
    }
    if (fn_1_F7BE4(lbl_3_data_C4)) {
        s16 selection = lbl_3_data_C4;
        s32 offset = v2 * 0x81C0;
        *(u8 *)((u32)&lbl_3_bss_140 + 0x81A0 + offset) = selection;
        ((Obj_3_bss_140 *)((u8 *)&lbl_3_bss_140 + offset))->unk_5 = selection;
    } else {
        u8 selection = ((struct SaveRecord *)lbl_3_bss_243C0)->machine;
        s32 offset = v2 * 0x81C0;
        *(u8 *)((u32)&lbl_3_bss_140 + 0x81A0 + offset) = selection;
        ((Obj_3_bss_140 *)((u8 *)&lbl_3_bss_140 + offset))->unk_5 = selection;
    }
    if (fn_1_F7BE4(lbl_3_data_C4) && fn_3_837C(p_lbl_3_bss_F0->unk_8) == 1) {
        u16 *buttons = &lbl_1_bss_9F8[v1].unk_8;
        /* First controller read is independent of the subsequent tests. */
        if (((*(volatile u16 *)buttons >> 12) & 1) || ((*buttons >> 11) & 1)) {
            result = 12;
            fn_1_A2D84(0xA9010100);
        } else if ((*buttons >> 8) & 1) {
            result = 11;
            fn_1_A2D84(0xA9010100);
        }
    }
    if ((lbl_1_bss_9F8[v1].unk_8 >> 9) & 1) {
        result = -1;
        fn_1_A2D84(0xA9010200);
    }
    return result;
}
/* fzgx:end fn_3_4538 */

/* fzgx:begin fn_3_48E0 pool noprologue */
#include "types.h"

typedef struct {
    s16 index;
} Sig_fn_3_AF8_Fn3AF8Arg;

typedef struct {
    u32 flags;   /* 0x00 */
    u32 unk_4;   /* 0x04 */
    s16 unk_8;   /* 0x08 */
    u8 pad_a[0x1A];
    u32 unk_24;  /* 0x24 */
    u8 pad_28[0x8];
} Fn3_48E0_State;

extern s16 lbl_1_bss_96A;
extern u32 lbl_3_data_B4;
extern s32 fn_3_4538(void);
extern int fn_3_AF8(Sig_fn_3_AF8_Fn3AF8Arg *);
extern int fn_1_4C10(void);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_1_1280(u32);

u32 lbl_3_bss_0[2];
u32 lbl_3_bss_8;
u32 lbl_3_bss_C[3];
u16 lbl_3_bss_18[4];
u16 lbl_3_bss_20[0x68];
Fn3_48E0_State lbl_3_bss_F0;
s32 lbl_3_bss_120[8];
u8 lbl_3_bss_140[0x20704];
u16 lbl_3_bss_20844;
u32 lbl_3_bss_20848;
u32 lbl_3_bss_2084C;
u32 lbl_3_bss_20850;
u32 lbl_3_bss_20854[3];
u32 lbl_3_bss_20860[0x440];
u32 lbl_3_bss_21960[0xA20];
f32 lbl_3_bss_241E0[0x64];
u32 lbl_3_bss_24370;
int (*lbl_3_bss_24374)(Sig_fn_3_AF8_Fn3AF8Arg *);
void *lbl_3_bss_24378;
u8 lbl_3_bss_2437C[0x2C];
u32 lbl_3_bss_243A8[6];
u8 lbl_3_bss_243C0[0x81C0];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_3_bss_0;
    s = *(u8 *)&lbl_3_bss_8;
    s = *(u8 *)&lbl_3_bss_C;
    s = *(u8 *)&lbl_3_bss_18;
    s = *(u8 *)&lbl_3_bss_20;
    s = *(u8 *)&lbl_3_bss_F0;
    s = *(u8 *)&lbl_3_bss_120;
    s = *(u8 *)&lbl_3_bss_140;
    s = *(u8 *)&lbl_3_bss_20844;
    s = *(u8 *)&lbl_3_bss_20848;
    s = *(u8 *)&lbl_3_bss_2084C;
    s = *(u8 *)&lbl_3_bss_20850;
    s = *(u8 *)&lbl_3_bss_20854;
    s = *(u8 *)&lbl_3_bss_20860;
    s = *(u8 *)&lbl_3_bss_21960;
    s = *(u8 *)&lbl_3_bss_241E0;
    s = *(u8 *)&lbl_3_bss_24370;
    s = *(u8 *)&lbl_3_bss_24374;
    s = *(u8 *)&lbl_3_bss_24378;
    s = *(u8 *)&lbl_3_bss_2437C;
    s = *(u8 *)&lbl_3_bss_243A8;
    s = *(u8 *)&lbl_3_bss_243C0;
}
#pragma section code_type ".text"

static inline int fn_3_48E0_busy(void) {
    u32 v = lbl_3_bss_F0.unk_24;
    if ((v & 0x80000000) && !(v & 1) && !(lbl_3_bss_F0.flags & 2)) {
        return 1;
    }
    if (fn_1_4C10()) {
        return 1;
    }
    return 0;
}

void fn_3_48E0(void) {
    s32 prev;
    s16 res;

    if (lbl_3_bss_120[0] == -1) {
        fn_1_4C10();
    }
    if (fn_3_48E0_busy()) {
        return;
    }
    prev = lbl_3_bss_120[0];
    if (prev != -1) {
        lbl_3_bss_120[0] = -1;
        lbl_1_bss_96A = prev;
        return;
    }
    res = fn_3_4538();
    if (res == -1) {
        fn_80008BA8(lbl_3_bss_140 + lbl_3_bss_F0.unk_8 * 0x81C0, lbl_3_bss_243C0, 0x81C0);
        lbl_3_bss_120[0] = 0x5f;
        return;
    }
    switch (res) {
    case 12:
        lbl_3_bss_0[0] = 1;
        lbl_3_bss_120[0] = 0x5d;
        fn_1_1280(1);
        lbl_3_data_B4 = 0x60;
        lbl_3_bss_24374 = fn_3_AF8;
        lbl_3_bss_24378 = &lbl_3_bss_F0.unk_8;
        lbl_3_bss_F0.flags |= 0x10000000;
        break;
    case 11:
        lbl_3_bss_0[0] = 1;
        lbl_3_bss_120[0] = 0x5d;
        fn_1_1280(1);
        lbl_3_data_B4 = 0x5f;
        lbl_3_bss_24374 = fn_3_AF8;
        lbl_3_bss_24378 = &lbl_3_bss_F0.unk_8;
        lbl_3_bss_F0.flags |= 0x10000000;
        break;
    }
}
/* fzgx:end fn_3_48E0 */

/* fzgx:begin fn_3_4A84 */
void fn_3_4A84(void) {
    fn_3_60C8();
    fn_1_48140(0x4a);
    fn_1_48140(0x54);
    fn_1_48140(0x38);
    fn_1_48140(0x3e);
    fn_1_48140(0x37);
    fn_1_48140(0x55);
    fn_1_48140(0x30);
    fn_1_48140(0x35);
    fn_1_48140(0x3a);
    fn_1_48140(0x40);
    fn_1_48140(0x44);
    fn_1_48140(0x50);
    fn_1_48140(0x33);
    fn_1_48140(0x2e);
    fn_1_48140(0x31);
    fn_1_48140(0x4f);
    fn_1_48140(0x39);
    fn_1_48140(0x3d);
    fn_1_48140(0x4c);
    fn_1_48140(0x3f);
    fn_1_48140(0x48);
    fn_1_48140(0x52);
    fn_1_48140(0x45);
    fn_1_48140(0x53);
    fn_1_48140(0x3c);
    fn_1_48140(0x56);
    fn_1_48140(0x43);
    fn_1_48140(0x42);
    fn_1_48140(0x32);
    fn_1_48140(0x2f);
    fn_1_48140(0x34);
    fn_1_48140(0x36);
    fn_1_48140(0x4d);
    fn_1_48140(0x46);
    fn_1_48140(0x41);
    fn_1_48140(0x51);
    fn_1_48140(0x4e);
    fn_1_48140(0x47);
    fn_1_48140(0x3b);
    fn_1_48140(0x4b);
    fn_1_48140(0x49);
}
/* fzgx:end fn_3_4A84 */

/* fzgx:begin fn_3_4BEC noprologue */
#include "types.h"

struct fn_3_4BEC_lbl_3_data_B8 {
    u32 unk_0;
};

extern struct fn_3_4BEC_lbl_3_data_B8 lbl_3_data_B8;
extern u32 fn_1_426C(u32);
extern u32 fn_1_435C(u32);
extern u32 fn_3_4A84(void);
extern u32 lbl_3_bss_20850;
extern u32 lbl_3_bss_F0;

void fn_3_4BEC(u32 arg0) {
    u32 v0;
    u32 t0, t1, t2;
    v0 = arg0;
    if ((lbl_3_bss_F0 & 0x10000000) == 0) {
    t0 = fn_3_4A84();
    v0 = t0;
    if ((s32)lbl_3_data_B8.unk_0 != -1) {
    v0 = (u32)&lbl_3_bss_20850;
    v0 = *(u32 *)((u8 *)v0 + 0);
    t1 = fn_1_435C(v0);
    v0 = t1;
    v0 = (u32)&lbl_3_data_B8;
    v0 = *(u32 *)((u8 *)v0 + 0);
    t2 = fn_1_426C(v0);
    v0 = t2;
    lbl_3_data_B8.unk_0 = -1;
    }
    }
}
/* fzgx:end fn_3_4BEC */

/* fzgx:begin fn_3_4C58 */
void fn_3_4C58(void) {
    s16 v0;
    s32 v1;
    struct { u8 *value; } first_selection;
#define v2 first_selection.value
    u32 v4;
    u32 v5;
    s16 v6;
    struct { u8 *value; } current_selection;
#define v7 current_selection.value
    struct { u8 *value; } entry_storage, meta_storage;
#define v8 meta_storage.value
#define v9 entry_storage.value
    struct { u8 *value; } render_storage;
#define v10 render_storage.value
    u8 v12;
    struct { u8 *value; } selection, render_base, entry_base, meta_base;
#define p_lbl_3_bss_140 selection.value
    struct fn_3_4C58_Copy160 loc_8;
    for (v0 = 0; v0 < 4; v0++) fn_3_5D84(v0);
    fn_80008BEC(lbl_3_bss_2C70C, 0, 164);
    p_lbl_3_bss_140 = (u8 *)&lbl_3_bss_140;
    v6 = 0;
    v2 = p_lbl_3_bss_140;
    while (v6 < 4) {
        loc_8 = lbl_3_rodata_F8;
        v4 = ((Obj_3_bss_140 *)v2)->unk_0;
        if ((v4 & 0x80000000) != 0 && (v4 & 0x40000000) == 0) {
            v5 = *(u8 *)(v2 + 0x81a0);
            if (lbl_3_bss_2C70C[v5] == 0) {
                fn_1_47F74(loc_8.a[v5]);
                lbl_3_bss_2C70C[*(u8 *)(v2 + 0x81a0)] = 1;
            }
        }
        v2 += 0x10000;
        v6++;
        v2 -= 0x7e40;
    }
    fn_80008BEC(lbl_3_bss_2C7C0, 0, 0x41100);
    v10 = (u8 *)lbl_3_bss_2C7C0;
    v9 = (((u8 *)&lbl_3_bss_20860));
    v8 = lbl_3_bss_21960;
    v6 = 0;
    v7 = p_lbl_3_bss_140;
    while (v6 < 4) {
        *(u32 *)(v10 + 12) = 0x80000000;
        v12 = *(u8 *)(v7 + 5);
        if (*(u8 *)(v7 + 7) != 0 && (*(u32 *)v7 & 0x80000000)) {
            if (*(u32 *)v7 & 0x40000000) {
                ((Obj_3_bss_140 *)v7)->unk_8 = 3;
                *(u32 *)(v9 + 912) = 0x4000000;
                *(void **)(v9 + 928) = v8;
            } else {
                *(u8 *)(v7 + 5) = *(u8 *)(v7 + 0x81a0);
                if (*(u8 *)(v7 + 5) == 40) *(u8 *)(v7 + 8) = 3;
                else if (*(u8 *)(v7 + 5) == 4) *(u8 *)(v7 + 8) = 2;
                else *(u8 *)(v7 + 8) = 1;
            }
            if (*(u8 *)(v7 + 7) != 0 && *(u8 *)(v7 + 7) <= 4) {
                if (*(void **)(v9 + 932) == 0)
                    *(void **)(v9 + 932) = fn_1_7F254(v7, (void *)2);
                *(u8 *)(v10 + 4) = 4;
                *(void **)(v10 + 0) = v9;
                *(s16 *)(v9 + 954) = 1;
                *(void (**)(void))(v10 + 0x10428) = fn_1_FDC00;
                *(void **)(v10 + 0x1042c) = (void *)fn_1_FD27C;
                *(void **)(v10 + 0x10424) = (void *)fn_1_FD324;
                *(void **)(v10 + 0x10420) = 0;
                *(u32 *)(v10 + 12) = 0x20000000;
                fn_1_FD844(v7, v10);
                if (*(u32 *)v7 & 0x40000000) {
                    *(u32 *)(v9 + 912) &= ~0x4000000;
                    *(void **)(v9 + 928) = 0;
                } else *(u8 *)(v7 + 5) = v12;
            }
        }
        v7 += 0x81c0;
        v10 += 0x10440;
        v9 += 0x440;
        v8 += 0xa20;
        v6++;
    }
}
/* fzgx:end fn_3_4C58 */

/* fzgx:begin fn_3_5A50 */
struct Meta { u32 value; u8 pad[0x81bc]; };

void fn_3_5A50(void) {
    s16 i;
    struct InitData init;
    for (i = 0; i < 4; i++) fn_3_5E88(i);
    init = lbl_3_rodata_1A4;
    for (i = 0; i < 0x29U; i++) {
        if (lbl_3_bss_2C70C[i] != 0) fn_1_48140(init.words[i]);
    }
    for (i = 0; i < 4; i++) {
        struct Entry *entry = &(((struct Entry *)&lbl_3_bss_20860))[i];
        u32 shift = 1;
        if (entry->ready != 0) {
            if (__rlwnm((((struct Meta *)&lbl_3_bss_140))[i].value, shift, 31, 31)) {
                entry->flags |= 0x04000000;
                fn_1_7F3AC( (u32)(void *)(entry));
                entry->flags &= ~0x04000000;
            } else fn_1_7F3AC( (u32)(void *)(entry));
            entry->ready = 0;
        }
    }
}
/* fzgx:end fn_3_5A50 */

/* fzgx:begin fn_3_5B9C */
void fn_3_5B9C(void) {
    s16 i;

    for (i = 0; i < 4; i++) {
        if (lbl_3_bss_6DD70 & (1 << i)) {
            fn_80008BEC( (void *)(u8 *)(&(((u8 *)&lbl_3_bss_140))[i * 0x81c0]), 0, 0x81c0);
        }
    }

    fn_3_11FB4(lbl_3_bss_2437C[0], (((s16 *)&lbl_3_bss_F0))[4], (u32)(u8 *)((((u8 *)&lbl_3_bss_140))));
}
/* fzgx:end fn_3_5B9C */

/* fzgx:begin fn_3_5C4C */
void fn_3_5C4C(void) {
    (((u8 *)&lbl_1_bss_970))[4] = 0;
    fn_1_4A00(1, 15, lbl_3_bss_20850);
}
/* fzgx:end fn_3_5C4C */

/* fzgx:begin fn_3_5C8C */
void fn_3_5C8C(void) {
    fn_3_3AE8(2, lbl_3_data_1814, 0x5d);
}
/* fzgx:end fn_3_5C8C */

/* fzgx:begin fn_3_5CBC */
void fn_3_5CBC(void) {
    fn_8006CE1C(lbl_3_rodata_44[0]);
}
/* fzgx:end fn_3_5CBC */

/* fzgx:begin fn_3_5CE4 */
struct InitBlock {
    u32 first;
    u32 second;
    u32 values[3];
};

void fn_3_5CE4(u32 arg0, u32 arg1) {
    struct InitBlock block;

    block.first = arg0;
    block.second = arg1;
    block.values[0] = lbl_3_rodata_248[0];
    block.values[1] = lbl_3_rodata_248[1];
    block.values[2] = lbl_3_rodata_248[2];

    fn_80008BA8( (u32)(void *)(lbl_3_bss_6DD78), (u32)(const void *)(&block.first), 0xc);
    fn_80008BA8( (u32)(void *)(lbl_3_bss_6DD78 + 6), (u32)(const void *)(&block.first + 1), 0xc);

    {
        struct Triple { u32 a; u32 b; u32 c; };
        *(struct Triple *)&lbl_3_bss_6DD78[9] = *(struct Triple *)block.values;
    }

    fn_1_A6FE8();
    fn_1_DCE60(lbl_3_bss_6DD78);
}
/* fzgx:end fn_3_5CE4 */

/* fzgx:begin fn_3_5E88 */
void fn_3_5E88(s16 arg0) {
    s32 index;

    index = arg0;
    if (lbl_3_bss_20860[index].value != -1) {
        fn_1_80F1C((s16)lbl_3_bss_20860[index].value, (void *)(fn_3_5E88_CustomizeEntry *)(&lbl_3_bss_20860[index]));
        lbl_3_bss_20860[index].value = -1;
    }

    fn_1_14DBCC((u8 *)(((u8 *)&lbl_3_bss_21960)) + index * 0xa20);

    if (lbl_1_bss_6D82C != 0) {
        fn_80071718(lbl_1_bss_6D82C);
        lbl_1_bss_6D82C = 0;
    }
}
/* fzgx:end fn_3_5E88 */

/* fzgx:begin fn_3_5F28 noprologue */
#include "types.h"

typedef struct {
    u8 pad_0[0x1164];
    u8 unk_1164[0x6C];
    s16 unk_11D0;
    u8 pad_11D2[0x2];
    u32 unk_11D4;
} CustomizeData;

typedef struct {
    s16 id;
    u8 pad_2[0x2];
    u32 mask;
    u8 flags;
    u8 pad_9[0x17];
} CustomizeSlot;

typedef struct {
    u8 pad[0x324];
    u32 value;
    u8 tail[0x118];
} CustomizeEntry;

extern CustomizeData lbl_3_data_0;
extern CustomizeSlot lbl_3_bss_7DB60[41];
extern CustomizeEntry *lbl_3_bss_20854;

extern void fn_1_80058(s8, CustomizeSlot *);
extern u32 fn_1_12A32C(void *);
extern void fn_1_12A2B8(u32);
extern void fn_1_80C18(CustomizeEntry *, CustomizeSlot *, s8);

void fn_3_5F28(void) {
    CustomizeData *data;
    s16 i;

    data = &lbl_3_data_0;
    for (i = 0; i < 41; i++) {
        fn_1_80058(i, &lbl_3_bss_7DB60[i]);
        lbl_3_bss_7DB60[i].id = i;
        lbl_3_bss_7DB60[i].flags = 0;
        lbl_3_bss_7DB60[i].flags |= 0x10;
        lbl_3_bss_7DB60[i].mask = 1 << data->unk_11D0;
    }
    data->unk_11D4 = fn_1_12A32C(data->unk_1164);
    fn_1_12A2B8(1);
    fn_1_80C18(lbl_3_bss_20854, lbl_3_bss_7DB60, 41);
    fn_1_12A2B8(0);
    for (i = 0; i < 41; i++) {
        lbl_3_bss_20854[i].value = data->unk_11D4;
    }
}
/* fzgx:end fn_3_5F28 */

/* fzgx:begin fn_3_60C8 */
void fn_3_60C8(void) {
    struct fn_3_60C8_lbl_3_bss_20854 *p_lbl_3_bss_20854;
    u32 v0;
    s32 v2;
    u32 v3;
    u32 v4;
    u32 t5;
    if ((s32)lbl_3_data_11D4.unk_0 != -1) {
    v0 = 1;
    fn_1_12A2B8(v0);
    v0 = (u32)&lbl_3_data_11D4;
    v0 = *(u32 *)((u8 *)v0 + 0);
    fn_1_12A2D0(v0);
    } else {
    v0 = 0;
    fn_1_12A2B8(v0);
    }
    p_lbl_3_bss_20854 = (struct fn_3_60C8_lbl_3_bss_20854 *)&(*((struct fn_3_60C8_lbl_3_bss_20854 *)&lbl_3_bss_20854));
{
    s32 v1;
    v1 = 0;
    v2 = 0;
    while ((s16)v1 < 41) {
    fn_1_7F934((void *)(p_lbl_3_bss_20854->unk_0 + v2));
    v2 += 1088;
    v1++;
}
    }
    v3 = (*((struct fn_3_60C8_lbl_1_bss_6D82C *)&lbl_1_bss_6D82C)).unk_0;
    v4 = v3;
    if (v3 != 0) {
    fn_80071718( (u32)((void *)v4));
    (*((struct fn_3_60C8_lbl_1_bss_6D82C *)&lbl_1_bss_6D82C)).unk_0 = 0;
    }
    v4 = (u32)&lbl_3_data_11D4;
    v4 = *(u32 *)((u8 *)v4 + 0);
    if ((s32)v4 != -1) {
    t5 = fn_1_12A734(v4);
    v4 = t5;
    }
    v4 = 0;
    lbl_3_data_11D4.unk_0 = -1;
    fn_1_12A2B8(v4);
}
/* fzgx:end fn_3_60C8 */

/* fzgx:begin fn_3_61B8 */
struct fn_3_61B8_lbl_3_data_0 {
    u8 pad_0[0xB8];
    u32 unk_B8;
};
struct fn_3_61B8_lbl_3_bss_20850 {
    u32 unk_0;
};


void fn_3_61B8(void) {
    struct fn_3_61B8_lbl_3_data_0 *p_lbl_3_data_0;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 t0, t1;
    p_lbl_3_data_0 = (struct fn_3_61B8_lbl_3_data_0 *)&(*((struct fn_3_61B8_lbl_3_data_0 *)&lbl_3_data_0));
    if ((s32)p_lbl_3_data_0->unk_B8 == -1) {
    t0 = (u32)fn_8006FDEC();
    v1 = t0;
    v1 = (u32)((u8 *)(u32)p_lbl_3_data_0 + 5800);
    v0 = (u32)fn_3_2AAF4;
    v2 = 0;
    v3 = 8;
    t1 = (u32)fn_1_3F8C((u32)v1, (u32)v0, v2, v3);
    v1 = t1;
    p_lbl_3_data_0->unk_B8 = v1;
    }
    fn_1_4A00(1, 15, (*((struct fn_3_61B8_lbl_3_bss_20850 *)&lbl_3_bss_20850)).unk_0);
    (*((struct fn_3_61B8_lbl_3_bss_243A8 *)&lbl_3_bss_243A8)).unk_0 = 0;
    (*((struct fn_3_61B8_lbl_3_bss_120 *)&lbl_3_bss_120)).unk_0 = -1;
    fn_1_47F74(163);
    fn_1_A176C(*(u32 *)((u8 *)(*((struct fn_3_61B8_lbl_1_bss_6EAD0 *)&lbl_1_bss_6EAD0)).unk_0 + 0), 15);
    fn_1_15BB34((u32)((u8 *)(u32)p_lbl_3_data_0 + 4444));
}
/* fzgx:end fn_3_61B8 */

/* fzgx:begin fn_3_6270 pool noprologue */
#include "types.h"

typedef struct {
    u32 flags;      /* 0x00 */
    u16 unk_4;
    s16 padIndex;   /* 0x06 */
    u8 pad_8[0x1C];
    u32 state;      /* 0x24 */
} fn_3_6270_Sub;

typedef struct {
    u8 pad_0[0x8];
    u16 trig;             /* 0x08 */
    u8 pad_A[0x6];
    volatile u16 rep;     /* 0x10 */
    volatile u16 rep2;    /* 0x12 */
} fn_3_6270_Pad;

/* this TU's .bss objects, in retail address order (base lbl_3_bss_0) */
static u8 lbl_3_bss_0[8];
static s32 lbl_3_bss_8;
static u8 lbl_3_bss_C[0xE4];
static fn_3_6270_Sub lbl_3_bss_F0;
static u8 lbl_3_bss_118[0x8];
static s32 lbl_3_bss_120;
static u8 lbl_3_bss_124[0x20844 - 0x124];
static s16 lbl_3_bss_20844;
static u8 lbl_3_bss_20846[0xA];
static u32 lbl_3_bss_20850;
static u8 lbl_3_bss_20854[0x243A8 - 0x20854];
static u32 lbl_3_bss_243A8;

extern s16 lbl_1_bss_96A;
extern fn_3_6270_Pad lbl_1_bss_9F8[];
extern u32 lbl_1_bss_6EAB4;
extern u32 lbl_3_data_B4;
extern u32 lbl_801A66A8;
extern int fn_1_4C10(void);
extern void fn_1_1280(u32);
extern void fn_1_4A00(s32, u8, u32);
extern void fn_1_A2D84(u32);
extern void fn_3_679C(void);

/* fixes the TU's .bss order; dropped at integration */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_primer_fn_3_6270(void) {
    fn_1_A2D84((u32)lbl_3_bss_0);
    fn_1_A2D84((u32)&lbl_3_bss_8);
    fn_1_A2D84((u32)lbl_3_bss_C);
    fn_1_A2D84((u32)&lbl_3_bss_F0);
    fn_1_A2D84((u32)lbl_3_bss_118);
    fn_1_A2D84((u32)&lbl_3_bss_120);
    fn_1_A2D84((u32)lbl_3_bss_124);
    fn_1_A2D84((u32)&lbl_3_bss_20844);
    fn_1_A2D84((u32)lbl_3_bss_20846);
    fn_1_A2D84((u32)&lbl_3_bss_20850);
    fn_1_A2D84((u32)lbl_3_bss_20854);
    fn_1_A2D84((u32)&lbl_3_bss_243A8);
}

static inline int fn_3_6270_busy(fn_3_6270_Sub *sub) {
    if ((sub->state & 0x80000000) && !(sub->state & 1) && !(sub->flags & 2)) {
        return 1;
    }
    if (fn_1_4C10()) {
        return 1;
    }
    return 0;
}

void fn_3_6270(void) {
    s16 vert;
    s16 horiz;
    s32 idx;
    s32 next;
    s32 prev;

    fn_3_679C();
    if (lbl_3_bss_120 == -1) {
        fn_1_4C10();
    }
    if (fn_3_6270_busy(&lbl_3_bss_F0)) {
        return;
    }
    prev = lbl_3_bss_120;
    if (prev != -1) {
        lbl_3_bss_120 = -1;
        lbl_1_bss_96A = prev;
        return;
    }

    horiz = 0;
    vert = horiz;
    idx = lbl_3_bss_F0.padIndex;
    if (((lbl_1_bss_9F8[idx].rep >> 3) & 1) || ((lbl_1_bss_9F8[idx].rep2 >> 3) & 1)) {
        vert = -1;
        fn_1_A2D84(0xA9010000);
        lbl_801A66A8 = 0;
    }
    if (((lbl_1_bss_9F8[idx].rep >> 2) & 1) || ((lbl_1_bss_9F8[idx].rep2 >> 2) & 1)) {
        vert++;
        fn_1_A2D84(0xA9010000);
        lbl_801A66A8 = 0;
    }
    next = lbl_3_bss_20844 + vert;
    lbl_3_bss_20844 = next > 2 ? 0 : (next < 0 ? 2 : next);

    if ((lbl_1_bss_9F8[idx].trig >> 9) & 1) {
        horiz = -1;
        fn_1_A2D84(0xA9010200);
    }
    if ((lbl_1_bss_9F8[idx].trig >> 8) & 1) {
        horiz = 1;
        fn_1_A2D84(0xA9010100);
    }

    if (horiz == -1) {
        if (lbl_3_bss_8 != 0) {
            lbl_3_bss_120 = 0x5D;
            fn_1_1280(1);
            lbl_3_data_B4 = 0x5C;
            lbl_3_bss_F0.flags |= 0x1000000;
        } else {
            fn_1_4A00(0, 15, lbl_3_bss_20850);
            lbl_3_bss_243A8 = 0;
            lbl_1_bss_6EAB4 |= 0x24;
            lbl_3_bss_120 = 0x5C;
        }
    } else if (horiz != 0) {
        switch (lbl_3_bss_20844) {
        case 0:
            fn_1_4A00(0, 15, lbl_3_bss_20850);
            lbl_3_bss_243A8 = 0;
            lbl_3_bss_120 = 0x6D;
            break;
        case 1:
            fn_1_4A00(0, 15, lbl_3_bss_20850);
            lbl_3_bss_243A8 = 0;
            lbl_3_bss_120 = 0x67;
            break;
        case 2:
            fn_1_4A00(0, 15, lbl_3_bss_20850);
            lbl_3_bss_243A8 = 0;
            lbl_3_bss_120 = 0x6F;
            break;
        }
    }
}
/* fzgx:end fn_3_6270 */

/* fzgx:begin fn_3_6540 */
void fn_3_6540(void) {
    if (lbl_1_bss_96A != 0x5d) {
        if (lbl_3_data_B8 != -1) {
            fn_1_435C(lbl_3_bss_20850);
            fn_1_426C(lbl_3_data_B8);
            lbl_3_data_B8 = -1;
        }
        fn_1_48140(0xa3);
    }
}
/* fzgx:end fn_3_6540 */

/* fzgx:begin fn_3_65B0 */
void fn_3_65B0(u32 value) {
    switch ((u16)value) {
    case 0:
        fn_1_F7D6C();
        fn_1_F7E24();
        break;
    case 1:
        fn_1_F7D18();
        fn_1_F7DC0();
        break;
    case 2:
        if ((s32)fn_1_F8A38(0) == 0) {
            fn_1_F8AD4(0);
        }
        fn_1_F8A58(0);
        if ((s32)fn_1_F8A38(1) == 0) {
            fn_1_F8AD4(1);
        }
        fn_1_F8A58(1);
        if ((s32)fn_1_F8A38(2) == 0) {
            fn_1_F8AD4(2);
        }
        fn_1_F8A58(2);
        if ((s32)fn_1_F8A38(3) == 0) {
            fn_1_F8AD4(3);
        }
        fn_1_F8A58(3);
        if ((s32)fn_1_F8A38(4) == 0) {
            fn_1_F8AD4(4);
        }
        fn_1_F8A58(4);
        if ((s32)fn_1_F8A38(5) == 0) {
            fn_1_F8AD4(5);
        }
        fn_1_F8A58(5);
        break;
    case 3:
        fn_1_F83F0(0x11);
        fn_1_F83F0(0x26);
        fn_1_F83F0(0x34);
        break;
    case 4:
        fn_1_F83F0(0x16);
        fn_1_F83F0(0x30);
        fn_1_F83F0(0x3e);
        break;
    case 5:
        fn_1_F83F0(8);
        fn_1_F83F0(0x2c);
        fn_1_F83F0(0x49);
        break;
    case 6:
        fn_1_F83F0(0xb);
        fn_1_F83F0(0x2e);
        fn_1_F83F0(0x39);
        break;
    case 7:
        fn_1_F83F0(1);
        fn_1_F83F0(0x1a);
        fn_1_F83F0(0x46);
        break;
    case 8:
        if (fn_1_F8C50(1) == 0) {
            fn_1_F8C74(1);
        }
        fn_1_F8C00(1);
        break;
    case 9:
        if (fn_1_F8C50(0) == 0) {
            fn_1_F8C74(0);
        }
        fn_1_F8C00(0);
        break;
    }
}
/* fzgx:end fn_3_65B0 */

/* fzgx:begin fn_3_679C */
void fn_3_679C(void) {
    u32 v0;
    u32 t0;

    t0 = fn_1_15BBC4();
    v0 = t0;
    if ((t0 & 0xFFFF) != 65535) {
        if ((s32)lbl_3_bss_7E080.unk_0 == 0) {
            lbl_3_bss_7E080.unk_0 = 1;
            fn_3_65B0(v0);
            v0 = 0xA9000000;
            v0 += 1024;
            fn_1_A2D84(v0);
            lbl_3_bss_8 = 1;
        }
    } else {
        lbl_3_bss_7E080.unk_0 = 0;
    }
}
/* fzgx:end fn_3_679C */

/* fzgx:begin fn_3_6D2C */
void fn_3_6D2C(void) {
    u32 flags;
    s32 ready;

    if (lbl_3_bss_120 == -1) {
        fn_1_4C10();
    }

    flags = (((u32 *)&lbl_3_bss_F0))[9];
    if ((flags & (~((u32)-1 >> 1))) != 0 &&
        (flags & 1) == 0 &&
        ((((u32 *)&lbl_3_bss_F0))[0] & 2) == 0) {
        ready = 1;
    } else if (fn_1_4C10() != 0) {
        ready = 1;
    } else {
        ready = 0;
    }

    if (ready == 0) {
        if (lbl_3_bss_120 != -1) {
            s32 value = lbl_3_bss_120;
            lbl_3_bss_120 = -1;
            (*((u16 *)&lbl_1_bss_96A)) = (u16)value;
        } else if (fn_3_6AC4() == (s16)-1) {
            fn_1_4A00(0, 15, lbl_3_bss_20850);
            lbl_3_bss_243A8[0] = 0;
            lbl_3_bss_120 = 110;
        }
    }
}
/* fzgx:end fn_3_6D2C */

/* fzgx:begin fn_3_6F90 */
static inline s16 fn_3_6F90_array_read(s32 index, s16 *array) { return array[index]; }
void fn_3_6F90(void) {
    s16 values[6];
    struct { s16 * value; } entry;
    u8 *base;
    s16 i;
    s32 k;

    fn_80008BEC( (void *)(s16 *)(values), 0, 6);
    entry.value = (s16 *)lbl_3_bss_6D8C0;
    i = 0;
    while (i < fn_1_14F014()) {
        k = fn_3_6F90_array_read(1, entry.value);
        fn_80008BA8( (u32)(u8 *)((lbl_3_bss_7E240) + k * 0x190 + fn_3_6F90_array_read(k, values) * 0x10), (u32)(s16 *)(entry.value), 0x10);
        values[k]++;
        entry.value += 8;
        i++;
    }
}
/* fzgx:end fn_3_6F90 */

/* fzgx:begin fn_3_7594 */
void fn_3_7594(void) {
    u32 flags;
    s32 ready;

    if (lbl_3_bss_120 == -1) {
        fn_1_4C10();
    }

    flags = (((u32 *)&lbl_3_bss_F0))[9];
    if ((flags & (~((u32)-1 >> 1))) != 0 &&
        (flags & 1) == 0 &&
        ((((u32 *)&lbl_3_bss_F0))[0] & 2) == 0) {
        ready = 1;
    } else if (fn_1_4C10() != 0) {
        ready = 1;
    } else {
        ready = 0;
    }

    if (ready == 0) {
        if (lbl_3_bss_120 != -1) {
            s32 value = lbl_3_bss_120;
            lbl_3_bss_120 = -1;
            (*((u16 *)&lbl_1_bss_96A)) = (u16)value;
        } else {
            fn_1_DCED0(lbl_3_bss_6DD78);
            if (fn_3_7360() == -1) {
                fn_1_4A00(0, 15, lbl_3_bss_20850);
                lbl_3_bss_243A8[0] = 0;
                lbl_3_bss_120 = 110;
            }
        }
    }
}
/* fzgx:end fn_3_7594 */

/* fzgx:begin fn_3_7688 */
void fn_3_7688(void) {
    if ((*((s32 *)&lbl_3_bss_8)) != 0 && lbl_3_bss_C[0] != 0) {
        fn_1_F8580();
    }

    if (lbl_3_data_11D8 != -1) {
        fn_1_12A2B8(1);
        fn_1_12A2D0(lbl_3_data_11D8);
    }

    fn_1_14DC68((((u8 *)&lbl_3_bss_6DE20)), 25);
    fn_1_12A2B8(0);

    if (lbl_3_data_11D8 != -1) {
        fn_1_12A734(lbl_3_data_11D8);
    }

    lbl_3_data_11D8 = -1;

    if (lbl_3_data_B8 != -1) {
        fn_1_435C((*((s32 *)&lbl_3_bss_20850)));
        fn_1_426C(lbl_3_data_B8);
        lbl_3_data_B8 = -1;
    }

    fn_1_48140(163);
}
/* fzgx:end fn_3_7688 */

/* fzgx:begin fn_3_7770 */
void fn_3_7770(void) {
    fn_1_4A00(1, 0xf, lbl_3_bss_20850);
    lbl_3_data_A8[0] = (u16)-1;
}
/* fzgx:end fn_3_7770 */

/* fzgx:begin fn_3_77B0 */
void fn_3_77B0(void) {
    if (((*(u16 *)(lbl_1_bss_9F8 + 8) >> 9) & 1) != 0 && fn_1_4C10() == 0) {
        fn_1_4A00(0, 15, lbl_3_bss_20850);
        lbl_3_data_A8[0] = 0x10;
    }
    if (lbl_3_data_A8[0] > 0 && --lbl_3_data_A8[0] == 0) {
        (*((u16 *)&lbl_1_bss_96A)) = 0x61;
    } else {
        fn_1_496FC(lbl_3_rodata_260, lbl_3_rodata_260);
        fn_1_4AE0C((const char *)lbl_3_data_1930);
    }
}
/* fzgx:end fn_3_77B0 */

/* fzgx:begin fn_3_7864 */
// fn_3_7864: empty in retail (single blr).
void fn_3_7864(void) {
}
/* fzgx:end fn_3_7864 */

/* fzgx:begin fn_3_7868 */
// fn_3_7868: empty in retail (single blr).
void fn_3_7868(void) {
}
/* fzgx:end fn_3_7868 */

/* fzgx:begin fn_3_786C */
// fn_3_786C: empty in retail (single blr).
void fn_3_786C(void) {
}
/* fzgx:end fn_3_786C */

/* fzgx:begin fn_3_7870 */
void fn_3_7870(void) {
    if (lbl_3_data_B8 != -1) {
        fn_1_435C(lbl_3_bss_20850);
        fn_1_426C(lbl_3_data_B8);
        lbl_3_data_B8 = -1;
    }
}
/* fzgx:end fn_3_7870 */

/* fzgx:begin fn_3_78C8 noprologue */
#include "types.h"

extern s16 lbl_3_bss_20[104];

typedef struct fn_3_78C8_CustomizeEntry {
    u8 pad[0x20];
    s16 count;
    s16 values[0x0a];
} fn_3_78C8_CustomizeEntry;

extern void fn_80008BEC(void *, s32, u32);
extern s32 fn_1_F8334(s32);
extern s32 fn_1_14D6D8(s32);
extern s16 fn_1_14F344(s32);
extern s32 fn_1_F809C(s32);

void fn_3_78C8(s32 enabled) {
    s32 i;

    fn_80008BEC((u8 *)(*(fn_3_78C8_CustomizeEntry (*)[3])&lbl_3_bss_20) + 0x20, 0, 0xa2);
    i = 0;
    while ((s16)i < 0x4b) {
        if (enabled != 0) {
            if (fn_1_F8334(i) != 0 &&
                (fn_1_14D6D8(i) & 0x40000000) == 0) {
                s16 index = fn_1_14F344(i);
                fn_3_78C8_CustomizeEntry *entry = &(*(fn_3_78C8_CustomizeEntry (*)[3])&lbl_3_bss_20)[index];

                entry->values[entry->count++] = (s16)i;
            }
        } else if (fn_1_F809C(i) != 0) {
            s16 index = fn_1_14F344(i);
            fn_3_78C8_CustomizeEntry *entry = &(*(fn_3_78C8_CustomizeEntry (*)[3])&lbl_3_bss_20)[index];

            entry->values[entry->count++] = (s16)i;
        }
        i++;
    }
    (*(fn_3_78C8_CustomizeEntry (*)[3])&lbl_3_bss_20)[0].values[(*(fn_3_78C8_CustomizeEntry (*)[3])&lbl_3_bss_20)[0].count] = -1;
    (*(fn_3_78C8_CustomizeEntry (*)[3])&lbl_3_bss_20)[1].values[(*(fn_3_78C8_CustomizeEntry (*)[3])&lbl_3_bss_20)[1].count] = -1;
    (*(fn_3_78C8_CustomizeEntry (*)[3])&lbl_3_bss_20)[2].values[(*(fn_3_78C8_CustomizeEntry (*)[3])&lbl_3_bss_20)[2].count] = -1;
}
/* fzgx:end fn_3_78C8 */

/* fzgx:begin fn_3_7A08 */
void fn_3_7A08(s16 *arg0, s16 *arg1, int arg2) {
    *arg0 = -lbl_3_bss_20[98];
    *arg1 = *arg0 + arg2 - 1;
}
/* fzgx:end fn_3_7A08 */

/* fzgx:begin fn_3_7A30 */
void fn_3_7A30(void) {
    fn_1_47F74(0x65);
    fn_1_47F74(0x6d);
    fn_1_47F74(0x80);
    fn_1_47F74(0x58);
    fn_1_47F74(0x69);
    fn_1_47F74(0x75);
    fn_1_47F74(0x64);
    fn_1_47F74(0x74);
    fn_1_47F74(0x63);
    fn_1_47F74(0x6c);
    fn_1_47F74(0x5a);
    fn_1_47F74(0x6e);
    fn_1_47F74(0x82);
    fn_1_47F74(0x6b);
    fn_1_47F74(0x79);
    fn_1_47F74(0x68);
    fn_1_47F74(0x6a);
    fn_1_47F74(0x59);
    fn_1_47F74(0x6f);
    fn_1_47F74(0x57);
    fn_1_47F74(0x72);
    fn_1_47F74(0x7e);
    fn_1_47F74(0x73);
    fn_1_47F74(0x71);
    fn_1_47F74(0x5b);
    fn_1_47F74(0x81);
    fn_1_47F74(0x62);
    fn_1_47F74(0x7a);
    fn_1_47F74(0x5d);
    fn_1_47F74(0x7c);
    fn_1_47F74(0x5c);
    fn_1_47F74(0x61);
    fn_1_47F74(0x60);
    fn_1_47F74(0x5e);
    fn_1_47F74(0x7f);
    fn_1_47F74(0x5f);
    fn_1_47F74(0x77);
    fn_1_47F74(0x70);
    fn_1_47F74(0x76);
    fn_1_47F74(0x78);
    fn_1_47F74(0x7d);
}
/* fzgx:end fn_3_7A30 */

/* fzgx:begin fn_3_7B94 */
void fn_3_7B94(void) {
    fn_1_48140(0x65);
    fn_1_48140(0x6d);
    fn_1_48140(0x80);
    fn_1_48140(0x58);
    fn_1_48140(0x69);
    fn_1_48140(0x75);
    fn_1_48140(0x64);
    fn_1_48140(0x74);
    fn_1_48140(0x63);
    fn_1_48140(0x6c);
    fn_1_48140(0x5a);
    fn_1_48140(0x6e);
    fn_1_48140(0x82);
    fn_1_48140(0x6b);
    fn_1_48140(0x79);
    fn_1_48140(0x68);
    fn_1_48140(0x6a);
    fn_1_48140(0x59);
    fn_1_48140(0x6f);
    fn_1_48140(0x57);
    fn_1_48140(0x72);
    fn_1_48140(0x7e);
    fn_1_48140(0x73);
    fn_1_48140(0x71);
    fn_1_48140(0x5b);
    fn_1_48140(0x81);
    fn_1_48140(0x62);
    fn_1_48140(0x7a);
    fn_1_48140(0x5d);
    fn_1_48140(0x7c);
    fn_1_48140(0x5c);
    fn_1_48140(0x61);
    fn_1_48140(0x60);
    fn_1_48140(0x5e);
    fn_1_48140(0x7f);
    fn_1_48140(0x5f);
    fn_1_48140(0x77);
    fn_1_48140(0x70);
    fn_1_48140(0x76);
    fn_1_48140(0x78);
    fn_1_48140(0x7d);
}
/* fzgx:end fn_3_7B94 */

/* fzgx:begin fn_3_7CF8 noprologue */
#include "types.h"

#include "rel/customize/globals.h"

extern s16 lbl_3_bss_6D8C0[600];
extern u8 lbl_3_bss_7E240[1200];
extern u32 lbl_1_bss_6D82C;
extern u32 lbl_3_bss_20848;
extern u8 lbl_3_bss_6DE20[64832];
extern s16 fn_1_14F014(void);
extern void fn_1_14E9E4(int, void *);
extern void fn_80008BEC(s16 *, int, u32);
extern void fn_80008BA8(u8 *, s16 *, s32);
extern void fn_1_12AB38(void *);
extern u32 fn_1_D3884(void *);
extern u32 fn_1_12A32C(void *);
extern void fn_1_12A2B8(u32);
extern void fn_1_12A2C4(u32);
extern void fn_1_14D994(void *, u32, u32);
extern void fn_3_7A30(void);

static inline s16 fn_3_7CF8_array_read(s32 index, s16 *array) { return array[index]; }

void fn_3_7CF8(void) {
    s16 loc_8[6];
    struct { s16 *value; } p_lbl_3_bss_6D8C0;
    u8 *p_lbl_3_data_0;
    u8 *p_lbl_3_bss_7E240;
    s16 *v0;
    struct { s32 value; } counter1;
    struct { s32 value; } counter2;
#define v1 counter1.value
#define v2 counter2.value
    s16 v3;
    s32 offset;

    p_lbl_3_data_0 = (u8 *)&lbl_3_data_0;
    v1 = 0;
    while ((s16)v1 < fn_1_14F014()) {
        fn_1_14E9E4(v1, lbl_3_bss_6D8C0 + v1 * 8);
        v1++;
    }
    fn_80008BEC(loc_8, 0, 6);
    v2 = 0;
    while ((s16)v2 < fn_1_14F014()) {
        v3 = fn_3_7CF8_array_read(1, lbl_3_bss_6D8C0 + v2 * 8);
        fn_80008BA8((lbl_3_bss_7E240) + v3 * 0x190 + fn_3_7CF8_array_read(v3, loc_8) * 0x10, lbl_3_bss_6D8C0 + v2 * 8, 0x10);
        loc_8[v3]++;
        v2++;
    }
    if (lbl_1_bss_6D82C == 0) {
        fn_1_12AB38(p_lbl_3_data_0 + 0x18a4);
        lbl_1_bss_6D82C = fn_1_D3884(p_lbl_3_data_0 + 0x18b0);
        fn_1_12AB38(p_lbl_3_data_0 + 0x18c0);
    }
    *(u32 *)(p_lbl_3_data_0 + 0x11d8) = fn_1_12A32C(p_lbl_3_data_0 + 0x1180);
    fn_1_12A2B8(1);
    fn_1_12A2C4(1);
    fn_1_14D994(lbl_3_bss_6DE20, 1 << lbl_3_bss_20848, 1);
    fn_1_12A2B8(0);
    fn_1_12A2C4(0);
    fn_3_7A30();
}
/* fzgx:end fn_3_7CF8 */

/* fzgx:begin fn_3_837C */
s32 fn_3_837C(s16 arg0) {
    return fn_8008023C((u32)(&lbl_3_bss_243C0), (u32)(((u8 *)(&(*((u32 *)&lbl_3_bss_140))) + (arg0 * 0x81C0))), 0x81C0U) != 0;
}
/* fzgx:end fn_3_837C */

/* fzgx:begin fn_3_968C noprologue */
#include "types.h"

extern u32 lbl_3_bss_6DE20;

extern s32 lbl_3_data_11D8;

struct fn_3_968C_lbl_3_data_11D8 {
    u32 unk_0;
};

extern u32 fn_1_12A2B8(u32);
extern u32 fn_1_12A2D0(u32);
extern u32 fn_1_12A734(u32);
extern u32 fn_1_14DC68(u32, u32);
extern u32 fn_3_7B94(void);

void fn_3_968C(u32 arg0) {
    u32 v0;
    u32 v1;
    u32 t0, t1;
    v0 = arg0;
    if ((s32)(*(struct fn_3_968C_lbl_3_data_11D8 *)&lbl_3_data_11D8).unk_0 != -1) {
    v0 = 1;
    t0 = fn_1_12A2B8(v0);
    v0 = t0;
    v0 = (u32)&(*(struct fn_3_968C_lbl_3_data_11D8 *)&lbl_3_data_11D8);
    v0 = *(u32 *)((u8 *)v0 + 0);
    t1 = fn_1_12A2D0(v0);
    v0 = t1;
    }
    fn_1_14DC68((u32)&lbl_3_bss_6DE20, 25);
    fn_1_12A2B8(0);
    v1 = (*(struct fn_3_968C_lbl_3_data_11D8 *)&lbl_3_data_11D8).unk_0;
    if ((s32)v1 != -1) {
    fn_1_12A734(v1);
    }
    (*(struct fn_3_968C_lbl_3_data_11D8 *)&lbl_3_data_11D8).unk_0 = -1;
    fn_3_7B94();
}
/* fzgx:end fn_3_968C */

/* fzgx:begin fn_3_9710 */
void fn_3_9710(u32 arg0, u32 arg1) {
    u32 v0;
    u32 v1;
    u32 t4, t6, t7;
    v1 = arg1;
    if (((*((u32 *)&lbl_3_bss_F0)) & 0x40000000) == 0) {
    if ((s32)(*((struct fn_3_9710_lbl_3_data_11D8 *)&lbl_3_data_11D8)).unk_0 != -1) {
    v0 = 1;
    fn_1_12A2B8(v0);
    v0 = (u32)&(*((struct fn_3_9710_lbl_3_data_11D8 *)&lbl_3_data_11D8));
    v0 = *(u32 *)((u8 *)v0 + 0);
    fn_1_12A2D0(v0);
    }
    v1 = 25;
    v0 = (u32)&lbl_3_bss_6DE20;
    fn_1_14DC68((void *)(u32)v0, v1);
    v0 = 0;
    fn_1_12A2B8(v0);
    v0 = (u32)&(*((struct fn_3_9710_lbl_3_data_11D8 *)&lbl_3_data_11D8));
    v0 = *(u32 *)((u8 *)v0 + 0);
    if ((s32)v0 != -1) {
    t4 = fn_1_12A734(v0);
    v0 = t4;
    }
    (*((struct fn_3_9710_lbl_3_data_11D8 *)&lbl_3_data_11D8)).unk_0 = -1;
    fn_3_7B94();
    if ((s32)(*((struct fn_3_9710_lbl_3_data_B8 *)&lbl_3_data_B8)).unk_0 != -1) {
    v0 = (u32)&lbl_3_bss_20850;
    v0 = *(u32 *)((u8 *)v0 + 0);
    t6 = fn_1_435C(v0);
    v0 = t6;
    v0 = (u32)&(*((struct fn_3_9710_lbl_3_data_B8 *)&lbl_3_data_B8));
    v0 = *(u32 *)((u8 *)v0 + 0);
    t7 = fn_1_426C(v0);
    v0 = t7;
    (*((struct fn_3_9710_lbl_3_data_B8 *)&lbl_3_data_B8)).unk_0 = -1;
    }
    v0 = 0;
    fn_1_151BDC(v0);
    }
    fn_3_BC60();
    fn_1_FE5C4(0, 0, 0, 0);
}
/* fzgx:end fn_3_9710 */
