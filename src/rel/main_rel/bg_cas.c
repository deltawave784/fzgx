#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"

typedef struct {
    f32 x, y, z;
} fn_1_FF6B8_CasVec;

typedef struct {
    s32 life;        /* 0x00 */
    fn_1_FF6B8_CasVec pos;      /* 0x04 */
    fn_1_FF6B8_CasVec prev;     /* 0x10 */
    fn_1_FF6B8_CasVec vel;      /* 0x1C */
    s16 rot;         /* 0x28 */
    s16 rotVel;      /* 0x2A */
    f32 scale;       /* 0x2C */
    f32 size;        /* 0x30 */
} CasParticle;

typedef struct {
    u8 pad_0[0x4];
    s32 active;      /* 0x04 */
    fn_1_FF6B8_CasVec pos;      /* 0x08 */
    u8 pad_14[0xC];
    fn_1_FF6B8_CasVec vel;      /* 0x20 */
    u8 pad_2C[0xC];
    f32 size;        /* 0x38 */
    CasParticle particles[20]; /* 0x3C */
} CasEmitter;
extern const f32 lbl_1_rodata_7600;
extern const f32 lbl_1_rodata_7604;
extern u32 GXGetTexBufferSize(u16, u16, u32, u8, u8);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_1_FC4E0(void *arg0, int arg1);
extern void fn_1_FC51C(void);
extern void GXLoadTexMtxImm(void *, u32, u32);
extern void fn_800736C0(u32, void *);
extern void fn_80072AB0(s32 arg0, s32 arg1, s32 arg2);
extern void fn_80072C24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072CC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072D64(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_80072E20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_800735C8(s32 index, s32 value);
extern void fn_80073620(s32 index, s32 value);
extern void fn_80073678(u32 arg0);
extern void fn_80073778(void *obj, s32 index);
extern void fn_80073898(u32 arg0);
extern void fn_80073C6C(s32 index);
extern void fn_800745A4(u32 arg0, s32 arg1, s32 arg2, u32 arg3, u32 arg4, u32 arg5);
extern void fn_80074660(u32 arg0);
extern void lbl_8006D758(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006DBAC(void *);
extern void lbl_8006E14C(f32);
extern void *fn_1_563B8(void *);
extern void fn_1_566EC(int arg0, int arg1);
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C();
extern void fn_1_7F230();
extern void fn_1_7F1E8();
extern void *fn_1_14DD68(void *);
extern void *fn_1_14DDF4(void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80072558(void);
extern int fn_1_FCF50(void);
extern u32 fn_1_584AC(void);
extern void fn_1_FCA10(void);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_FD3A8(void);
extern void *memset(void *, int, u32);
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(u8 *);
extern void fn_80074788(u32 arg0);
extern void fn_80072864(u32 arg0);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern void fn_800720B0(int);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern void lbl_8006E13C(void *);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_FFC60(Obj_1_data_2A7E0_At3C *arg0);
extern void fn_1_FEC7C(void *object);
extern f32 lbl_1_rodata_7590[2];
extern const f32 lbl_1_rodata_7598;
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern u8 lbl_1_bss_850E0[256];
extern const f32 lbl_1_rodata_76A8;
extern u32 fn_1_904(void);
extern u32 fn_1_914(void);
extern void fn_1_681C(u32 index, u32 *output);
extern u32 fn_1_1FB80(void *, u32);
extern void fn_1_FF6B8(CasEmitter *em);
extern void fn_1_FC60C(void);
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(void *, void *, u32, u32, u32, u32, u32, u32);
extern void fn_1_FB9DC(int index);
extern void fn_1_FBC5C(u8 idx);

/* fzgx:begin fn_1_FB798 */
int fn_1_FB798(int mode, u32 *value) {
    Obj_1_data_2A7E0_At3C *entry = lbl_1_data_2A7E0.unk_3C;

    switch (mode) {
    case 0: {
        u8 *cursor = (u8 *)lbl_1_bss_3BE0->unk_54;
        entry->unk_0 = 0;
        while (cursor != (u8 *)value) {
            u32 count = entry->unk_0;
            cursor += 0x40;
            entry->unk_0 = count + 1;
        }
        *value |= 0x80000000;
        break;
    }

    case 1: {
        u8 *p = (u8 *)entry + 4;
        ((u32 *)(p + 4))[*(u8 *)p] = (u32)value;
        *(u8 *)p = *(u8 *)p + 1;
        *value |= 0x80000000;
        if (*(u8 *)p >= 0x10) {
            OSPanic((const char *)lbl_1_data_3EF90, 0x2f2, (const char *)lbl_1_data_3EF9C);
        }
        break;
    }
    }

    return 1;
}
/* fzgx:end fn_1_FB798 */

/* fzgx:begin fn_1_FB870 */
u8 *fn_1_FB870(void) {
    return &lbl_1_bss_84450;
}
/* fzgx:end fn_1_FB870 */

/* fzgx:begin fn_1_FB87C */
typedef struct {
    u8 unk_0[4];
    u8 unk_4;
    u8 unk_5[0x270 - 5];
} Cas_1_Record;

typedef struct {
    u8 unk_0[4];
    Cas_1_Record unk_4[5];
    u8 unk_C34;
    u32 unk_C38[1];
} Cas_1_State;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_1_bss_84450;
u8 fzgx_pool_lbl_1_bss_84450_gap_84451;
u16 fzgx_pool_lbl_1_bss_84450_gap_84451_fill_84452;
Cas_1_Record fzgx_obj_lbl_1_bss_84454[5];
u8 lbl_1_bss_84454__fzgx_offset_C30;
u8 lbl_1_bss_84454__fzgx_offset_C31;
u16 lbl_1_bss_84454__fzgx_offset_C32;
u32 lbl_1_bss_85088[1];
u32 lbl_1_bss_85088__fzgx_offset_4[13];
u32 fzgx_obj_lbl_1_bss_850C0;
u16 lbl_1_bss_850C0__fzgx_offset_4;
u16 fzgx_obj_lbl_1_bss_850C6;
u32 lbl_1_bss_850C6__fzgx_offset_2[3];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_84450;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_84450_gap_84451;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_84450_gap_84451_fill_84452;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_84454;
    s = *(u8 *)&lbl_1_bss_84454__fzgx_offset_C30;
    s = *(u8 *)&lbl_1_bss_84454__fzgx_offset_C31;
    s = *(u8 *)&lbl_1_bss_84454__fzgx_offset_C32;
    s = *(u8 *)&lbl_1_bss_85088;
    s = *(u8 *)&lbl_1_bss_85088__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_850C0;
    s = *(u8 *)&lbl_1_bss_850C0__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_850C6;
    s = *(u8 *)&lbl_1_bss_850C6__fzgx_offset_2;
}
#pragma section code_type ".text"

void fn_1_FB87C(u32 *values, u8 count) {
    u8 buf[5];
    
    u32 *src;
    u32 *dst;
    Cas_1_Record *rec;
    int i;
    volatile const f32 *zero; /* reloaded each iteration: the callee may write */

    *(u32 *)buf = *(u32 *)lbl_1_rodata_7590;
    buf[4] = ((u8 *)lbl_1_rodata_7590)[4];

    fn_80008BEC(fzgx_obj_lbl_1_bss_84454, 0, 0xc30);

    fzgx_obj_lbl_1_bss_84454[0].unk_4 = buf[0];
    fzgx_obj_lbl_1_bss_84454[1].unk_4 = buf[1];
    fzgx_obj_lbl_1_bss_84454[2].unk_4 = buf[2];
    fzgx_obj_lbl_1_bss_84454[3].unk_4 = buf[3];
    fzgx_obj_lbl_1_bss_84454[4].unk_4 = buf[4];
    lbl_1_bss_84454__fzgx_offset_C30 = count;

    dst = lbl_1_bss_85088;
    src = values;
    zero = &lbl_1_rodata_7598;
    for (i = 0; i < lbl_1_bss_84454__fzgx_offset_C30; i++) {
        f32 z = *zero;

        *dst = *src;
        GXInitTexObjLOD((void *)*dst, 1, 1, z, z, z, 0, 0, 0);
        src++;
        dst++;
    }
}
/* fzgx:end fn_1_FB87C */

/* fzgx:begin fn_1_FB96C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"

// Initializes the selected background-cas state before running its setup stages.
void fn_1_FB96C(int index) {
    u32 *states = &lbl_1_bss_84454.unk_0;

    states[(index & 0xff) * 0x9c] = 1;
    fn_1_FB9DC(index);
    fn_1_FBA88(index);
    fn_1_FBC5C(index);
}
/* fzgx:end fn_1_FB96C */

/* fzgx:begin fn_1_FB9C0 */
// Clear the selected CAS state value.
void fn_1_FB9C0(int index) {
    (&lbl_1_bss_84454.unk_0)[(index & 0xff) * 0x9c] = 0;
}
/* fzgx:end fn_1_FB9C0 */

/* fzgx:begin fn_1_FB9DC */
// Reset the per-slot flags and enable the flags associated with the selected slot.
void fn_1_FB9DC(int index) {
    u32 slot = index & 0xff;
    Obj_1_bss_84454 *state =
        (Obj_1_bss_84454 *)((u8 *)&lbl_1_bss_84454 + slot * 0x270);

    state->unk_14 = 0;
    state->unk_134 = 0;
    state->unk_74 = 0;
    state->unk_194 = 0;
    state->unk_D4 = 0;
    state->unk_1F4 = 0;

    switch (slot) {
    case 0:
        state->unk_14 = 1;
        state->unk_134 = 1;
        break;
    case 1:
        state->unk_134 = 1;
        state->unk_194 = 1;
        break;
    case 2:
        state->unk_134 = 1;
        state->unk_1F4 = 1;
        break;
    case 3:
        state->unk_134 = 1;
        state->unk_1F4 = 1;
        break;
    case 4:
        state->unk_134 = 1;
        state->unk_194 = 1;
        break;
    default:
        break;
    }
}
/* fzgx:end fn_1_FB9DC */

/* fzgx:begin fn_1_FBC5C */
/* one 0x60-byte track element; six of them per 0x270-byte entry starting at 0xC */
typedef struct {
    u32 unk_0;
    u8 unk_4;
    u8 unk_5;
    u8 pad_6[2];
    u32 unk_8;
    f32 pos[3];   /* 0xC */
    f32 rate;     /* 0x18 */
    f32 rate2;    /* 0x1C */
    f32 unk_20;
    f32 scale[3]; /* 0x24 */
    u8 pad_30[0x30];
} CasElem;

typedef struct {
    u8 pad_0[0xC];
    CasElem elem[6];  /* 0xC .. 0x24C */
    u32 unk_24C;
    u8 unk_250[4];
    u8 flags[4];      /* 0x254 */
    f32 speed[3];     /* 0x258 */
    f32 speed2[3];    /* 0x264 */
} CasEntry;


/* Literal pool of the retail TU (lbl_1_rodata_7590): MWCC pools literals in
 * first-use order across the TU, so the earlier functions' data comes first.
 * MWCC emits a function's aggregate data before its scalar literals, so each
 * retail function with both gets its own primer. */
static const u8 fzgx_pool_7590[5] = {0x49, 0x4A, 0x4B, 0x4C, 0x64};

#pragma section code_type ".fzgxpool"
static void fzgx_pool_layout(void) {
    volatile f32 s; /* fzgx-allow: S2 pool primer sink: fixes the TU literal order */
    volatile u32 w; /* fzgx-allow: S2 pool primer sink: fixes the TU literal order */
    w = fzgx_pool_7590[0];
    s = 0.0f;
}

/* file-scope tables are emitted where they are defined: after the first primer's literal */
static const u32 fzgx_pool_759C[6] = {0x2D, 0x30, 0x2A, 0x27, 0x39, 0x36};

static void fzgx_pool_layout_1(void) {
    volatile u32 w; /* fzgx-allow: S2 pool primer sink: fixes the TU literal order */
    w = fzgx_pool_759C[0];
}
#pragma section code_type ".text"

void fn_1_FBC5C(u8 idx) {
    CasEntry *ent = &(((CasEntry *)&lbl_1_bss_84454))[idx];
    s32 i;

    for (i = 0; i < 3; i++) {
        ent->elem[i].pos[0] = 0.0f;
        ent->elem[i].pos[1] = 0.0f;
        ent->elem[i].pos[2] = 0.0f;
        ent->elem[i].scale[0] = 1.0f;
        ent->elem[i].scale[1] = 1.0f;
        ent->elem[i].scale[2] = 1.0f;
        ent->elem[i + 3].pos[0] = (i == 1) ? 0.5f : 0.0f;
        ent->elem[i + 3].pos[1] = 0.0f;
        ent->elem[i + 3].pos[2] = 0.0f;
        ent->elem[i + 3].rate = 0.0f;
        ent->elem[i + 3].rate2 = 0.0f;
        ent->elem[i + 3].unk_20 = 0.0f;
        ent->speed[i] = 0.1f;
        ent->speed2[i] = 0.2f;
        ent->flags[i] = 0;
    }

    for (i = 0; i < 3; i++) {
        switch (idx) {
        case 0:
            ent->elem[i].rate = 0.0033333334140479565f;
            ent->elem[i].rate2 = 0.005000000353902578f;
            ent->elem[i + 3].scale[0] = 0.25f;
            ent->elem[i + 3].scale[1] = 0.25f;
            break;
        case 1:
            ent->elem[i].rate = 0.0016666667070239782f;
            ent->elem[i].rate2 = 0.002500000176951289f;
            ent->elem[i + 3].scale[0] = 0.3f;
            ent->elem[i + 3].scale[1] = 0.25f;
            break;
        case 2:
            ent->elem[i + 3].scale[0] = 1.0f;
            ent->elem[i + 3].scale[1] = 1.0f;
            break;
        case 3:
            ent->elem[i + 3].scale[0] = 1.0f;
            ent->elem[i + 3].scale[1] = 1.0f;
            break;
        case 4:
            ent->elem[i + 3].scale[0] = 1.0f;
            ent->elem[i + 3].scale[1] = 0.25f;
            ent->speed[i] = 0.05f;
            ent->speed2[i] = 0.03f;
            break;
        }
        ent->elem[i + 3].rate = ent->elem[i].rate / 3.0f;
        ent->elem[i + 3].rate2 = ent->elem[i].rate2 / 3.0f;
    }

    switch (idx) {
    case 0:
        break;
    case 1:
        ent->speed[0] = 0.3f;
        ent->speed2[0] = 0.3f;
        ent->elem[3].rate = 0.005f;
        ent->elem[3].rate2 = 0.005f;
        break;
    case 2:
        ent->elem[3].rate = 0.001f;
        ent->elem[3].rate2 = 0.001f;
        ent->speed[0] = 0.0f;
        ent->speed2[0] = 0.3f;
        ent->speed2[2] = 0.07f;
        break;
    case 3:
        ent->elem[3].rate = 0.015f;
        ent->elem[3].rate2 = 0.0f;
        ent->speed[0] = 0.1f;
        ent->speed2[0] = 0.2f;
        ent->elem[5].rate = 0.01f;
        ent->elem[5].rate2 = 0.0f;
        ent->elem[5].scale[0] = 0.25f;
        ent->elem[5].scale[1] = 0.25f;
        ent->speed[2] = 0.05f;
        ent->speed2[2] = 0.05f;
        break;
    case 4:
        break;
    }
}
/* fzgx:end fn_1_FBC5C */

/* fzgx:begin fn_1_FBEA8 */
void fn_1_FBEA8(void) {
    Obj_1_bss_84454 *base;
    Obj_1_bss_84454 *entry;
    u8 i;
    s32 j;

    base = &lbl_1_bss_84454;
    for (i = 0; i < 5; i++) {
        Obj_1_bss_84454 *slot =
            (Obj_1_bss_84454 *)((u8 *)base + i * 0x270);
        if ((s32)slot->unk_0 != 0) {
            for (j = 0, entry = slot; j < 3;
                 j++, entry = (Obj_1_bss_84454 *)((u8 *)entry + 0x60)) {
                if ((s32)entry->unk_14 != 0) {
                    entry->unk_18 += entry->unk_24;
                    entry->unk_1C += entry->unk_28;
                    entry->unk_20 += entry->unk_2C;
                    lbl_8006D758();
                    lbl_8006E13C(&entry->unk_30);
                    lbl_8006E0A4(&entry->unk_18);
                    lbl_8006DB74(entry->pad_3C);
                }
                if ((s32)entry->unk_134 != 0) {
                    entry->unk_138 += entry->unk_144;
                    entry->unk_13C += entry->unk_148;
                    entry->unk_140 += entry->unk_14C;
                    lbl_8006D758();
                    lbl_8006E13C(&entry->unk_150);
                    lbl_8006E0A4(&entry->unk_138);
                    lbl_8006DB74(&entry->pad_158[4]);
                }
            }
        }
    }
}
/* fzgx:end fn_1_FBEA8 */

/* fzgx:begin fn_1_FC40C */
// fn_1_FC40C: empty in retail (single blr).
void fn_1_FC40C(void) {
}
/* fzgx:end fn_1_FC40C */

/* fzgx:begin fn_1_FC410 */
// fn_1_FC410: empty in retail (single blr).
void fn_1_FC410(void) {
}
/* fzgx:end fn_1_FC410 */

/* fzgx:begin fn_1_FC414 noprologue */
#include "types.h"
#include "rel/main_rel/bg_cas.h"

extern const f32 lbl_1_rodata_7600;
extern const f32 lbl_1_rodata_7604;

extern void *GXGetTexBufferSize(int, int, int, int, int);
extern void fn_80008BEC(void *, int, u32);
extern void fn_1_FC4E0(void *, void *);
extern void fn_1_FC51C(void);

typedef struct {
    u8 pad_0[0x10];
    u32 unk_10;
    f32 unk_14;
    f32 unk_18;
    u8 pad_1c[4];
    u8 unk_20[0x100];
    u8 unk_120[0x20];
    u32 unk_140;
} Fn1FC414Data;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_850C0;
u16 lbl_1_bss_850C0__fzgx_offset_4;
u16 lbl_1_bss_850C6__fzgx_offset_0;
u32 lbl_1_bss_850C6__fzgx_offset_2[2];
u32 lbl_1_bss_850C6__fzgx_offset_A;
f32 fzgx_obj_lbl_1_bss_850D4;
f32 fzgx_obj_lbl_1_bss_850D8;
u32 lbl_1_bss_850D8__fzgx_offset_4;
u8 lbl_1_bss_850E0[0x100];
u8 lbl_1_bss_851E0[0x20];
u32 lbl_1_bss_851E0__fzgx_offset_20;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_850C0;
    s = *(u8 *)&lbl_1_bss_850C0__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_850C6__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_850C6__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_850C6__fzgx_offset_A;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_850D4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_850D8;
    s = *(u8 *)&lbl_1_bss_850D8__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_850E0;
    s = *(u8 *)&lbl_1_bss_851E0;
    s = *(u8 *)&lbl_1_bss_851E0__fzgx_offset_20;
}
#pragma section code_type ".text"

void fn_1_FC414(void *arg0, void *arg1) {
    
    f32 v14 = lbl_1_rodata_7600;
    f32 v18 = lbl_1_rodata_7604;
    void *buffer;

    fzgx_obj_lbl_1_bss_850D4 = v14;
    fzgx_obj_lbl_1_bss_850D8 = v18;
    buffer = GXGetTexBufferSize(0x10, 0x10, 1, 0, 0);
    fn_80008BEC(lbl_1_bss_850E0, 0, (u32)buffer);
    fn_80008BEC(lbl_1_bss_851E0, 0, 0x20);
    lbl_1_bss_851E0__fzgx_offset_20 = (u32)GXGetTexBufferSize(0x80, 0x80, 1, 0, 0);
    fn_1_FC4E0(arg0, arg1);
    lbl_1_bss_850C6__fzgx_offset_A = 0;
    fn_1_FC51C();
}
/* fzgx:end fn_1_FC414 */

/* fzgx:begin fn_1_FC4E0 */
void fn_1_FC4E0(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_80008BEC(arg0, 0, (arg1 & 0xff) * 0x10440);
    }
}
/* fzgx:end fn_1_FC4E0 */

/* fzgx:begin fn_1_FC51C */
#pragma opt_common_subs off
void fn_1_FC51C(void) {
    fn_1_FC60C();

    lbl_1_bss_851E0[0] = 0xff;
    lbl_1_bss_851E0[1] = 0xff;
    lbl_1_bss_851E0[2] = 0;
    lbl_1_bss_851E0[3] = 0;
    lbl_1_bss_851E0[4] = 0;
    lbl_1_bss_851E0[5] = 0;
    lbl_1_bss_851E0[6] = 0;
    lbl_1_bss_851E0[7] = 0;

    fn_80008BA8( (u32)(void *)(lbl_1_bss_851E0 + 8), (u32)(void *)(lbl_1_bss_851E0), 8);
    fn_80008BA8( (u32)(void *)(lbl_1_bss_851E0 + 0x10), (u32)(void *)(lbl_1_bss_851E0), 8);
    fn_80008BA8( (u32)(void *)(lbl_1_bss_851E0 + 0x18), (u32)(void *)(lbl_1_bss_851E0), 8);
    DCFlushRange(lbl_1_bss_851E0, 0x20);

    GXInitTexObj((*(u8 (*)[32])&lbl_1_bss_85204), lbl_1_bss_851E0, 8, 4, 1, 0, 0, 0);
    GXInitTexObjLOD((*(u8 (*)[32])&lbl_1_bss_85204), 1, 1, *(const f32 *)&lbl_1_rodata_760C, *(const f32 *)&lbl_1_rodata_760C, *(const f32 *)&lbl_1_rodata_760C, (u8)(0), (u8)(0), 0);
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_FC51C */

/* fzgx:begin fn_1_FC60C */
#pragma opt_common_subs off
void fn_1_FC60C(void) {
    u8 *tex;
    u8 *buf;
    u32 size;
    u32 i;

    size = GXGetTexBufferSize(0x10, 0x10, 1, 0, 0);
    tex = lbl_1_bss_85224;
    buf = lbl_1_bss_850E0;

    for (i = 0; i < 0x100; i++) {
        int idx = ((i & 0x80) >> 2) + ((i >> 4) & 7) + ((i & 0xC) << 4) + ((i & 3) << 3);
        if (i >= 0xA) {
            buf[idx] = (u8)i - 0xA;
        } else {
            buf[idx] = 0;
        }
    }

    GXInitTexObj(tex, buf, 0x10, 0x10, 1, 0, 1, 0);
    GXInitTexObjLOD(tex, 0, 0, (*(f32 (*)[2])&lbl_1_rodata_760C)[0], (*(f32 (*)[2])&lbl_1_rodata_760C)[0],
                    (*(f32 (*)[2])&lbl_1_rodata_760C)[0], 0, 0, 0);
    DCFlushRange(buf, size);
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_FC60C */

/* fzgx:begin fn_1_FCA10 */
typedef f32 Mtx34[3][4];

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_FCA10_CasVec;

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} CasColor;

extern Mtx34 *lbl_801A6D00;


#define CAS_VIEW(field) (*(f32 *)(*(u32 *)(lbl_1_data_3EFA8 + 0x40F0) + (field)))

/* Literal pool of the retail TU (lbl_1_rodata_7600): MWCC pools literals in
 * first-use order across the TU, so the earlier functions' literals come first. */
#pragma section code_type ".fzgxpool"
static void fzgx_pool_layout(void) {
    volatile f32 s; /* fzgx-allow: S2 pool primer sink: fixes the TU literal order */
    volatile u32 w; /* fzgx-allow: S2 pool primer sink: fixes the TU literal order */
    s = 2.0f;
    s = 8.0f;
}

/* MWCC emits a function's aggregate initializers before its scalar literals,
 * so each retail function with both gets its own primer. */
static void fzgx_pool_layout_1(void) {
    volatile f32 s; /* fzgx-allow: S2 pool primer sink: fixes the TU literal order */
    volatile u32 w; /* fzgx-allow: S2 pool primer sink: fixes the TU literal order */
    {
        CasColor c = {0xFF, 0xFF, 0xFF, 0xFF};
        w = *(u32 *)&c;
    }
    s = 0.0f;
}

static void fzgx_pool_layout_2(void) {
    volatile f32 s; /* fzgx-allow: S2 pool primer sink: fixes the TU literal order */
    volatile u32 w; /* fzgx-allow: S2 pool primer sink: fixes the TU literal order */
    {
        CasColor z = {0, 0, 0, 0};
        w = *(u32 *)&z;
    }
    s = 0.5f;
    s = 16.0f;
    s = 1.0f;
    s = 128.0f;
}
#pragma section code_type ".text"

#pragma opt_common_subs off
void fn_1_FCA10(void) {
    CasColor color = {0xFF, 0xFF, 0xFF, 0xFF};
    u16 j;
    s32 i;
    u32 obj;

    fn_800736C0(0, &color);

    for (i = 0; (u16)i < 4; i++) {
        j = (u16)i;
        fn_800735C8(j, 12);
        fn_80073620(j, 28);
    }

    fn_80073778(lbl_1_bss_85224, 0);
    fn_80073778((void *)lbl_1_data_3EFA8, 1);
    fn_80073778((void *)(lbl_1_data_3EFA8 + 0x20), 2);
    fn_80073778(lbl_1_bss_85204, 3);

    GXLoadTexMtxImm((void *)(lbl_1_data_3EFA8 + 0x70), 30, 0);
    GXLoadTexMtxImm((void *)(lbl_1_data_3EFA8 + 0x40), 33, 0);

    lbl_8006DAEC();
    {
        fn_1_FCA10_CasVec trans = {0.0f, 0.0f, 0.0f};
        lbl_8006DBAC((void *)(lbl_1_data_3EFA8 + 0xA0));
        lbl_8006E14C(-1.0f);

        /* Translation column of the locked-cache current matrix. */
        *(f32 *)(0xE0000000 + 0x0C) = trans.x;
        *(f32 *)(0xE0000000 + 0x1C) = trans.y;
        *(f32 *)(0xE0000000 + 0x2C) = trans.z;
    }

    GXLoadTexMtxImm(lbl_801A6D00, 0x24, 0);
    lbl_8006D758();

    (*lbl_801A6D00)[0][0] = 0.0f;
    obj = *(u32 *)(lbl_1_data_3EFA8 + 0x40F0);
    if (*(f32 *)(obj + 0x10) < 0.5f || *(f32 *)(obj + 0x10) >= 1.0f) {
        *(f32 *)(obj + 0x10) = 0.5f;
    }
    obj = *(u32 *)(lbl_1_data_3EFA8 + 0x40F0);
    if (*(f32 *)(obj + 0x14) <= 0.0f || *(f32 *)(obj + 0x14) > 0.5f) {
        *(f32 *)(obj + 0x14) = 0.5f;
    }

    (*lbl_801A6D00)[0][2] = CAS_VIEW(0x10);
    (*lbl_801A6D00)[0][3] = CAS_VIEW(0x14);
    (*lbl_801A6D00)[1][1] = 0.0f;
    (*lbl_801A6D00)[2][2] = 0.0f;
    (*lbl_801A6D00)[2][3] = 1.0f;

    GXLoadTexMtxImm(lbl_801A6D00, 0x46, 0);
    lbl_8006DB30();

    fn_80074660(4);
    fn_800745A4(0, 0, 0, 30, 0, 125);
    fn_800745A4(1, 0, 0, 33, 0, 125);
    fn_800745A4(2, 0, 0, 33, 0, 125);
    fn_80073678(4);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_80072AB0(0, 0, 0);
    fn_800734A8(0, 0, 0, 0xFF);
    fn_80072C24(0, 0xF, 0xF, 0xF, 0xF);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 7, 7, 4);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80073C6C(1);
    fn_80072AB0(1, 0, 0);
    fn_800734A8(1, 1, 1, 0xFF);
    fn_80072C24(1, 0xF, 0xF, 0xF, 0xF);
    fn_80072D64(1, 0, 0, 0, 1, 0);
    fn_80072CC4(1, 4, 0, 6, 7);
    fn_80072E20(1, 14, 0, 0, 0, 0);
    fn_80073C6C(2);
    fn_80072AB0(2, 0, 0);
    fn_800734A8(2, 2, 2, 4);
    fn_80072C24(2, 0xF, 0xF, 0xF, 8);
    fn_80072D64(2, 0, 0, 0, 1, 0);
    fn_80072CC4(2, 7, 0, 4, 7);
    fn_80072E20(2, 0, 0, 1, 1, 0);
    fn_80073C6C(3);
    fn_80072AB0(3, 0, 0);
    fn_800745A4(3, 0, 1, 36, 1, 70);
    fn_800734A8(3, 3, 3, 4);
    fn_80072C24(3, 0xF, 0xF, 0xF, 0);
    fn_80072D64(3, 0, 0, 0, 1, 0);
    fn_80072CC4(3, 7, 4, 0, 7);
    fn_80072E20(3, 0, 0, 0, 1, 0);
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_FCA10 */

/* fzgx:begin fn_1_FCF50 */
int fn_1_FCF50(void) {
    fn_1_FCA10();
    return 1;
}
/* fzgx:end fn_1_FCF50 */

/* fzgx:begin fn_1_FCF74 */
void fn_1_FCF74(void) {
    fn_80008BEC(&lbl_1_data_3EFB0, 0, 4);
}
/* fzgx:end fn_1_FCF74 */

/* fzgx:begin fn_1_FD1D4 */
typedef struct {
    void *value;
} fn_1_FD1D4_Fn1FD27CArg0;

typedef struct {
    u8 pad[0x40f0];
    void *value;
} fn_1_FD1D4_Fn1FD27CArg1;

void fn_1_FD1D4(fn_1_FD1D4_Fn1FD27CArg0 *arg0, fn_1_FD1D4_Fn1FD27CArg1 *arg1) {
    fn_1_FD1D4_Fn1FD27CArg1 *persistent;
    void *value;
    void *result;
    s16 mode;
    u8 local[0x30];

    persistent = arg1;
    value = arg0->value;
    lbl_8006DB74(local);
    if (persistent->value != 0 && (*(u32 *)((u8 *)persistent->value + 4) & ~0x7fffffffU) != 0) {
        result = fn_1_563B8((void *)fn_1_FCF50);
        mode = *(s16 *)persistent->value;
        if (mode == 0) {
            fn_1_7EB8C(value, lbl_1_rodata_761C[0]);
        } else {
            fn_1_7F230(value, (s32)mode, lbl_1_rodata_761C[0]);
        }
        lbl_8006DBAC(local);
        fn_1_563B8(result);
    }
}
/* fzgx:end fn_1_FD1D4 */

/* fzgx:begin fn_1_FD27C */
typedef struct {
    void *value;
} fn_1_FD27C_Fn1FD27CArg0;

typedef struct {
    u8 pad[0x40f0];
    void *value;
} fn_1_FD27C_Fn1FD27CArg1;

void fn_1_FD27C(fn_1_FD27C_Fn1FD27CArg0 *arg0, fn_1_FD27C_Fn1FD27CArg1 *arg1) {
    fn_1_FD27C_Fn1FD27CArg1 *persistent;
    void *value;
    void *result;
    s16 mode;
    u8 local[0x30];

    persistent = arg1;
    value = arg0->value;
    lbl_8006DB74(local);
    if (persistent->value != 0 && (*(u32 *)((u8 *)persistent->value + 4) & ~0x7fffffffU) != 0) {
        result = fn_1_563B8((void *)fn_1_FCF50);
        mode = *(s16 *)persistent->value;
        if (mode == 0) {
            fn_1_7EB8C(value, lbl_1_rodata_761C[0]);
        } else {
            fn_1_7F20C(value, (s32)mode, lbl_1_rodata_761C[0]);
        }
        lbl_8006DBAC(local);
        fn_1_563B8(result);
    }
}
/* fzgx:end fn_1_FD27C */

/* fzgx:begin fn_1_FD324 */
int fn_1_FD324(void *arg0) {
    u8 *p;
    if (arg0 == NULL) {
        return 0;
    }
    p = *(u8 **)arg0;
    if (p == NULL) {
        return 0;
    }
    if (__rlwnm(*(u32 *)(p + 0x390), 6, 31, 31) != 0 && *(u32 *)(p + 0x3A0) == 0) {
        return 0;
    }
    if (*(u32 *)(p + 0x3A4) == 0) {
        return 0;
    }
    return 1;
}
/* fzgx:end fn_1_FD324 */

/* fzgx:begin fn_1_FD388 */
void fn_1_FD388(void) {
    fn_1_FD3A8();
}
/* fzgx:end fn_1_FD388 */

/* fzgx:begin fn_1_FDFF4 */
// Mark the background-collision object as active.
void fn_1_FDFF4(void) {
    lbl_1_bss_850C6.unk_0 = 1;
}
/* fzgx:end fn_1_FDFF4 */

/* fzgx:begin fn_1_FE004 */
void fn_1_FE004(void) {
    lbl_1_bss_850C6.unk_0 = 0;
}
/* fzgx:end fn_1_FE004 */

/* fzgx:begin fn_1_FE014 */
typedef struct {
    s16 unk_0;
    u8 pad_2[0x360 - 2];
} CasTableEntry;          /* 0x360 bytes */

typedef struct {
    u8 unk_0;
    u8 pad_1[7];
} CasSelEntry;            /* 8 bytes */

typedef struct {
    u8 pad_0[0x32C];
    u32 unk_32C;
    u8 pad_330[0x60];
    u32 unk_390;
    u8 pad_394[0xC];
    CasTableEntry *unk_3A0;
    u32 unk_3A4;
    u8 pad_3A8[0x12];
    s16 unk_3BA;
} CasObject;

typedef struct {
    CasObject *value;
} CasObjectRef;

typedef struct {
    u8 pad_0[0x40F0];
    s16 *view;
} CasContext;

typedef struct {
    u8 pad_0[0x4];
    u8 unk_4;
    u8 unk_5;
    u8 pad_6[2];
    CasSelEntry *unk_8;
    u8 *unk_C;
} CasBase;


/* Draw the object with the current view; DRAW_FN is the multi-view variant. */
#define CAS_DRAW(DRAW_FN)                                       \
    obj = ref->value;                                           \
    saved = obj->unk_3BA;                                       \
    if (saved == 3) {                                           \
        obj->unk_3BA = 2;                                       \
    }                                                           \
    if (ctx->view != NULL) {                                    \
        mode = *ctx->view;                                      \
        alpha = (obj->unk_32C == 0) ? 0.5f : 1.0f;              \
        prev = fn_1_563B8((void *)fn_1_FCF50);                  \
        fn_1_566EC(1, 0xff);                                    \
        if (mode == 0) {                                        \
            fn_1_7EB8C(obj, alpha);                             \
        } else if (obj->unk_390 & 0x4000000) {                  \
            DRAW_FN(obj, mode, alpha);                          \
        } else {                                                \
            fn_1_7F1E8(obj, mode, alpha);                       \
        }                                                       \
        fn_1_566EC(0, 0);                                       \
        fn_1_563B8(prev);                                       \
        obj->unk_3BA = saved;                                   \
    }

static inline void cas_draw_inner(CasObjectRef *ref, CasContext *ctx) {
    u8 inner[0x30];
    CasObject *obj;
    void *prev;
    s16 mode;
    s16 saved;
    f32 alpha;

    lbl_8006DB74(inner);
    CAS_DRAW(fn_1_7F20C);
    lbl_8006DBAC(inner);
}

static inline void cas_draw_nested(CasObjectRef *ref, CasContext *ctx) {
    u8 outer[0x30];

    lbl_8006DB74(outer);
    fn_80072558();
    cas_draw_inner(ref, ctx);
    fn_80072558();
    lbl_8006DBAC(outer);
}

static inline void cas_draw_multi(CasObjectRef *ref, CasContext *ctx) {
    CasObject *obj;
    void *prev;
    s16 mode;
    s16 saved;
    f32 alpha;

    CAS_DRAW(fn_1_7F230);
}

static inline void cas_draw_single(CasObjectRef *ref, CasContext *ctx, CasBase *base) {
    u8 buf[0x30];
    void *res;
    s16 kind;

    res = NULL;
    lbl_8006DB74(buf);
    kind = *ctx->view;
    if (kind != 0) {
        if (kind == 1) {
            res = fn_1_14DD68(base->unk_C + base->unk_8->unk_0 * 0xa20);
        } else if (kind == 2) {
            res = fn_1_14DDF4(base->unk_C + base->unk_8->unk_0 * 0xa20);
        }
        lbl_8006E0A4(res);
    }
    fn_80072558();
    cas_draw_multi(ref, ctx);
    lbl_8006DBAC(buf);
}

void fn_1_FE014(CasObjectRef *ref, CasContext *ctx) {
    CasBase *base = (CasBase *)&lbl_1_bss_850C0;
    CasObject *obj;
    CasTableEntry *tbl;
    CasSelEntry *sel;
    s16 idx;
    s32 b;
    s32 a;

    obj = ref->value;
    if (obj == NULL || obj->unk_3A4 == 0 || (tbl = obj->unk_3A0) == NULL || base->unk_C == NULL ||
        (sel = base->unk_8) == NULL) {
        return;
    }

    a = tbl[0].unk_0;
    b = sel[0].unk_0;
    if (a == b && tbl[1].unk_0 == sel[1].unk_0 && tbl[2].unk_0 == sel[2].unk_0 && base->unk_4 == 0) {
        if (base->unk_5 == *ctx->view) {
            cas_draw_nested(ref, ctx);
        }
    } else if (base->unk_4 != 0) {
        idx = *ctx->view;
        if (tbl[idx].unk_0 == sel[idx].unk_0) {
            cas_draw_single(ref, ctx, base);
        }
    } else {
        idx = *ctx->view;
        if (base->unk_5 == idx && tbl[idx].unk_0 == sel[idx].unk_0) {
            if (a != b) {
                cas_draw_single(ref, ctx, base);
            } else {
                cas_draw_nested(ref, ctx);
            }
        }
    }
}
/* fzgx:end fn_1_FE014 */

/* fzgx:begin fn_1_FE5C4 */
void fn_1_FE5C4(u8 arg0, u32 arg1, u32 arg2, u8 arg3) {
    lbl_1_bss_850C0.unk_4 = arg3;
    lbl_1_bss_850C0.unk_5 = arg0;
    *(u32 *)((u8 *)&lbl_1_bss_850C0 + 0x8) = arg2;
    *(u32 *)((u8 *)&lbl_1_bss_850C0 + 0xc) = arg1;
}
/* fzgx:end fn_1_FE5C4 */

/* fzgx:begin fn_1_FE5E0 */
// fn_1_FE5E0: No-op return
void fn_1_FE5E0(void) {
    return;
}
/* fzgx:end fn_1_FE5E0 */

/* fzgx:begin fn_1_FE5E4 */
typedef struct {
    u8 pad_0[0x1B1E4];
    u16 unk_1B1E4;
} Obj_1_data_2A7E0_At3C_Ext;

void fn_1_FE5E4(void) {
    Obj_1_data_2A7E0_At3C *obj;

    obj = lbl_1_data_2A7E0.unk_3C;
    fn_1_9A508(&lbl_1_data_2A7E0);
    fn_1_FFC60(obj);
    fn_1_FEC7C(obj);
    ((Obj_1_data_2A7E0_At3C_Ext *)obj)->unk_1B1E4 = 0;
    obj->unk_430 = lbl_1_rodata_76A8;
}
/* fzgx:end fn_1_FE5E4 */

/* fzgx:begin fn_1_FE640 */
// fn_1_FE640: empty in retail (single blr).
void fn_1_FE640(void) {
}
/* fzgx:end fn_1_FE640 */

/* fzgx:begin fn_1_FE780 */
// fn_1_FE780: Empty return
void fn_1_FE780(void) {
}
/* fzgx:end fn_1_FE780 */

/* fzgx:begin fn_1_FE784 */
// Update the background object and process it when its active state is set.
void fn_1_FE784(void) {
    Obj_1_data_2A7E0_At3C *background_object = lbl_1_data_2A7E0.unk_3C;

    fn_1_9AD88();
    if ((s32)background_object->unk_10 != 0) {
        fn_1_10069C(background_object);
    }
    fn_1_FF038(background_object);
}
/* fzgx:end fn_1_FE784 */

/* fzgx:begin fn_1_FE7D4 */
// fn_1_FE7D4: empty in retail (single blr).
void fn_1_FE7D4(void) {
}
/* fzgx:end fn_1_FE7D4 */

/* fzgx:begin fn_1_FEC7C */
void fn_1_FEC7C(void *object) {
    s32 count;
    s32 index;
    u8 *entry;

    entry = (u8 *)object + 0x434;
    memset(entry, 0, 0x1ADB0);
    index = 0;
    while (index < (count = (s32)lbl_1_bss_3BE0->unk_A4)) {
        fn_1_FE7D8(entry, 1);
        fn_1_FF420(entry);
        index++;
        entry += 0x44C;
    }
    while (count < 0x64) {
        fn_1_FE7D8(entry, 0);
        fn_1_FF420(entry);
        count++;
        entry += 0x44C;
    }
}
/* fzgx:end fn_1_FEC7C */

/* fzgx:begin fn_1_FED34 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 6600.0f;
    s = 110.0f;
    s = 60.0f;
    s = 15.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x00000000, 0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 300.0f;
    s = 32767.0f;
    s = 4.0f;
    s = 10.0f;
    s = 2.0f;
    s = 200.0f;
    s = 400.0f;
    s = 2500.0f;
    s = 1000.0f;
    s = 1400.0f;
    d = 0.5;
    d = 5.0;
    s = 7.0f;
    s = 2.5f;
    s = 768.0f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 0.10000000149011612f;
    s = 0.5f;
    s = 0.25f;
    s = 0.05000000074505806f;
    s = -2000.0f;
    s = 1.0199999809265137f;
    s = 30.0f;
    s = 22.0f;
}
#pragma section code_type ".text"

typedef struct {
    f32 unk_0;
    u8 pad_4[0x4];
    f32 unk_8;
    u8 pad_C[0x8];
    f32 unk_14;
    u8 pad_18[0x8];
    f64 unk_20;
    u8 pad_28[0xC];
    f32 unk_34;
    u8 pad_38[0x50];
    f32 unk_88;
    f32 unk_8C;
    f32 unk_90;
    f32 unk_94;
    f32 unk_98;
    f32 unk_9C;
    f32 unk_A0;
} RoData_76A8;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;



static inline f32 fn_1_FED34_operand(f32 right, f32 left) { return left + right; }
void fn_1_FED34(void *arg0) {
    u8 sp8[16];
    RoData_76A8 *rd;
    s32 var_r30;
    s32 var_r29;
    u8 *var_r28;
    u32 temp_r3;
    f32 var_f31;
    f32 var_f0;
    f32 temp_delta;
    f32 temp_f1;
    f32 temp_f3;

    rd = (RoData_76A8 *)(*(f32 (*)[84])&lbl_1_rodata_76A8);
    var_r28 = (u8 *)arg0 + 0x434;
    temp_r3 = fn_1_904();
    if (temp_r3 < 0xDACU) {
        var_f31 = (0.100000001f);
    } else if (temp_r3 < 0x1388U) {
        var_f31 = (0.5f);
    } else {
        var_f31 = (1.0f);
    }
    if (fn_1_914() > 1U) {
        var_f31 = (0.0f);
    }
    fn_1_681C(0U, (u32 *)(void *)(sp8));
    if (fn_1_1FB80(sp8, 1U) != 0U) {
        var_f0 = (0.0f);
    } else if (fn_1_1FB80(sp8, 2U) != 0U) {
        var_f0 = (0.25f);
    } else if (fn_1_1FB80(sp8, 4U) != 0U) {
        var_f0 = (0.5f);
    } else {
        var_f0 = (1.0f);
    }
    if (var_f31 > var_f0) {
        var_f31 = var_f0;
    }
    temp_f3 = *(f32 *)((u8 *)arg0 + 0x430);
    var_r30 = 0;
    temp_delta = (0.100000001f) * (var_f31 - temp_f3);
    temp_f1 = (100.0f);
    *(f32 *)((u8 *)arg0 + 0x430) = temp_f3 + temp_delta;
    var_r29 = (s32)(temp_f1 * *(f32 *)((u8 *)arg0 + 0x430));
    do {
        s32 count = *(s32 *)(var_r28 + 4);
        if (count != 0) {
            *(s32 *)(var_r28 + 4) = count - 1;
        }
        if (var_r30 <= var_r29) {
            if (*(s32 *)(var_r28 + 4) <= 0) {
                fn_1_FE7D8( (u8 *)(void *)(var_r28), *(u32 *)var_r28);
            }
        } else if (*(s32 *)(var_r28 + 4) > 0x1E) {
            *(s32 *)(var_r28 + 4) = 0x1E;
        }
        if (*(s32 *)(var_r28 + 4) > 0) {
            *(f32 *)(var_r28 + 8) = *(f32 *)(var_r28 + 8) + *(f32 *)(var_r28 + 32);
            *(f32 *)(var_r28 + 12) = *(f32 *)(var_r28 + 12) + *(f32 *)(var_r28 + 36);
            *(f32 *)(var_r28 + 16) = *(f32 *)(var_r28 + 16) + *(f32 *)(var_r28 + 40);
            *(s16 *)(var_r28 + 44) = (s16)(*(s16 *)(var_r28 + 44) + *(s16 *)(var_r28 + 48));
            *(s16 *)(var_r28 + 46) = (s16)(*(s16 *)(var_r28 + 46) + *(s16 *)(var_r28 + 50));
            *(Vec3 *)(var_r28 + 20) = *(Vec3 *)(var_r28 + 8);
            if (*(s32 *)(var_r28 + 4) >= 0x3C) {
                if (*(f32 *)(var_r28 + 52) < (1.0f)) {
                    *(f32 *)(var_r28 + 52) = fn_1_FED34_operand(((0.0500000007f)), (*(f32 *)(var_r28 + 52)));
                }
                if (*(f32 *)(var_r28 + 52) > (1.0f)) {
                    *(f32 *)(var_r28 + 52) = (1.0f);
                }
                if (*(f32 *)(var_r28 + 12) < (-2000.0f)) {
                    *(s32 *)(var_r28 + 4) = 0x1E;
                }
            }
            if (*(s32 *)(var_r28 + 4) < 0x3C) {
                if (*(s32 *)var_r28 != 0) {
                    *(f32 *)(var_r28 + 52) *= (f32)*(s32 *)(var_r28 + 4) / (60.0f);
                } else {
                    if (*(s32 *)(var_r28 + 4) < 0x3C) {
                        *(f32 *)(var_r28 + 56) *= (1.01999998f);
                    }
                    if (*(s32 *)(var_r28 + 4) < 0x1E) {
                        *(f32 *)(var_r28 + 52) *= (f32)*(s32 *)(var_r28 + 4) / (30.0f);
                    }
                }
            }
            fn_1_FF6B8( (CasEmitter *)(void *)(var_r28));
        }
        var_r30 += 1;
        var_r28 += 0x44C;
    } while (var_r30 < 0x64);
}
/* fzgx:end fn_1_FED34 */

/* fzgx:begin fn_1_FF6B8 */

/* Literal pool of the retail TU (lbl_1_rodata_76A8): MWCC pools literals in
 * first-use order across the TU, so the earlier functions' literals come first. */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 6600.0f;
    s = 110.0f;
    s = 60.0f;
    s = 15.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x00000000, 0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 300.0f;
    s = 32767.0f;
    s = 4.0f;
    s = 10.0f;
    s = 2.0f;
    s = 200.0f;
    s = 400.0f;
    s = 2500.0f;
    s = 1000.0f;
    s = 1400.0f;
    d = 0.5;
    d = 5.0;
    s = 7.0f;
    s = 2.5f;
    s = 768.0f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 0.10000000149011612f;
    s = 0.5f;
    s = 0.25f;
    s = 0.05000000074505806f;
    s = -2000.0f;
    s = 1.0199999809265137f;
    s = 30.0f;
    s = 22.0f;
    d = 0.9;
}
static const u32 fzgx_pool_table10[8] = {0x3F19999A, 0x3ECCCCCD, 0x437F0000, 0x3F4CCCCD, 0x3E99999A, 0x3FA66666, 0x3F3504F3, 0};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.1;
    d = 1280.0;
    s = 0.9f;
    d = 0.98;
    s = 20.0f;
}
#pragma section code_type ".text"


       /* 0x34 */


/* random fraction in [0, 1] */
#define RAND_FRAC() ((f32)(u16)fn_1_584AC() / 32767.0f)

/* velocity jittered by up to 10%; the casts keep retail's separate fmul/fadd */
#define JITTER(v) ((f64)(0.9 * (v)) + (f64)(0.1 * (v) * RAND_FRAC()))

void fn_1_FF6B8(CasEmitter *em) {
    s32 i;
    CasParticle *p;
    f32 v;

    p = em->particles;
    for (i = 0; i < 20; i++, p++) {
        if (p->life != 0) {
            p->life--;
        }
        if (p->life <= 0 && em->active > 0) {
            p->life = (s32)(30.0f + (f32)(10.0f * RAND_FRAC()));
            p->pos = em->pos;
            p->prev = em->pos;
            v = em->vel.x;
            p->vel.x = JITTER(v);
            v = em->vel.y;
            p->vel.y = JITTER(v);
            v = em->vel.z;
            p->vel.z = JITTER(v);
            p->rot = fn_1_584AC();
            p->rotVel = (s32)(1280.0 * (RAND_FRAC() - 0.5)) + 512;
            p->scale = 1.0f;
            p->size = 22.0f * em->size;
        }
        p->vel.x *= 0.9f;
        p->vel.y *= 0.9f;
        p->vel.z *= 0.9f;
        p->pos.x += p->vel.x;
        p->pos.y += p->vel.y;
        p->pos.z += p->vel.z;
        p->prev = p->pos;
        p->rot += p->rotVel;
        p->size *= 0.98;
        if (p->life < 20) {
            p->scale *= (f32)p->life / 20.0f;
        }
    }
}
/* fzgx:end fn_1_FF6B8 */

/* fzgx:begin fn_1_1011CC */
void fn_1_1011CC(int arg0, int arg1) {
    fn_80074788(0);
    fn_80072864(0);
    fn_800745A4(0, 1, 4, 0x3c, 0, 0x7d);
    fn_800734A8(0, 0, 0, 0xff);
    fn_80072AB0(0, 0, 0);
    fn_800735C8(0, 0xc);
    fn_80073620(0, 0x1c);
    fn_80073C6C(0);
    if (arg0 != 0) {
        fn_80072C24(0, 0xf, 0xe, 8, 0xf);
    } else {
        fn_80072C24(0, 0xf, 0xf, 0xf, 0xe);
    }
    fn_80072D64(0, 0, 0, 0, 1, 0);
    if (arg1 != 0) {
        fn_80072CC4(0, 7, 6, 4, 7);
    } else {
        fn_80072CC4(0, 7, 7, 7, 6);
    }
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80073678(1);
    fn_80074660(1);
    fn_80074918(1, 3, 0);
    fn_800720B0(0);
}
/* fzgx:end fn_1_1011CC */

/* fzgx:begin fn_1_101348 */
int fn_1_101348(int index, u32 *value) {
    Obj_1_data_2A7E0_At3C *obj = lbl_1_data_2A7E0.unk_3C;

    switch (index) {
    case 0:
        obj->unk_424 = *value;
        break;
    case 1:
        obj->unk_428 = *value;
        break;
    case 2:
        obj->unk_42C = *value;
        break;
    default:
        break;
    }

    return 1;
}
/* fzgx:end fn_1_101348 */

/* fzgx:begin fn_1_1013A0 */
struct fn_1_1013A0_Arg1 {
    u32 unk_0;
};

s32 fn_1_1013A0(s32 arg0, struct fn_1_1013A0_Arg1 *arg1) {
    switch (arg0) {
    case 0:
        arg1->unk_0 |= 0x1000000;
        break;
    }

    return 1;
}
/* fzgx:end fn_1_1013A0 */

/* fzgx:begin fn_1_1013C0 */
// fn_1_1013C0: empty in retail (single blr).
void fn_1_1013C0(void) {
}
/* fzgx:end fn_1_1013C0 */

/* fzgx:begin fn_1_1013C4 */
void fn_1_1013C4(void) {
    Obj_1_data_2A7E0_At3C *ptr = lbl_1_data_2A7E0.unk_3C;
    fn_1_9A508(&lbl_1_data_2A7E0);
    ptr->unk_0 = -1;
}
/* fzgx:end fn_1_1013C4 */

/* fzgx:begin fn_1_101400 */
// fn_1_101400: empty in retail (single blr).
void fn_1_101400(void) {
}
/* fzgx:end fn_1_101400 */

/* fzgx:begin fn_1_101404 */
void fn_1_101404(void) {
    fn_1_9AD54();
}
/* fzgx:end fn_1_101404 */

/* fzgx:begin fn_1_101424 */
// fn_1_101424: empty in retail (single blr).
void fn_1_101424(void) {
}
/* fzgx:end fn_1_101424 */

/* fzgx:begin fn_1_101428 */
void fn_1_101428(void) {
    fn_1_9AD88();
}
/* fzgx:end fn_1_101428 */

/* fzgx:begin fn_1_101448 */
// fn_1_101448: Empty function (blr only)
void fn_1_101448(void) {
}
/* fzgx:end fn_1_101448 */

/* fzgx:begin fn_1_10144C */
// fn_1_10144C: returns a constant.
int fn_1_10144C(void) {
    return 0;
}
/* fzgx:end fn_1_10144C */

/* fzgx:begin fn_1_101454 */
int fn_1_101454(int arg0, u32 *arg1) {
    Obj_1_data_2A7E0_At3C *entry;
    u8 *cursor;

    entry = lbl_1_data_2A7E0.unk_3C;
    switch (arg0) {
    case 0:
        cursor = (u8 *)lbl_1_bss_3BE0->unk_54;
        entry->unk_0 = 0;
        while (cursor != (u8 *)arg1) {
            entry->unk_0 += 1;
            cursor += 0x40;
        }
        *arg1 |= 1u << 31;
        break;
    default:
        goto done; /* The default case skips the zero-argument body. */
    }
done:
    return 1;
}
/* fzgx:end fn_1_101454 */
