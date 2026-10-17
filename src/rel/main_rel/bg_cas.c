#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"
#include "game/main_rel/bg_cas_types.h"

struct fn_1_FD3A8_lbl_1_rodata_7600 {
    u8 pad_0[0xC];
    f32 unk_C;
    u8 pad_10[0x4];
    f32 unk_14;
    u8 pad_18[0x4];
    f32 unk_1C;
    u8 pad_20[0x28];
    u32 unk_48;
    f32 unk_4C;
};

struct fn_1_FD3A8_lbl_801A6D00 {
    u32 unk_0;
};

typedef struct Sig_GXInitTexObj__GXTexObj {
    u32 dummy[8];
} Sig_GXInitTexObj_GXTexObj;

typedef enum Sig_GXInitTexObj__GXTexFmt {
    Sig_GXInitTexObj_GX_TF_I4 = 0x0,
    Sig_GXInitTexObj_GX_TF_I8 = 0x1,
    Sig_GXInitTexObj_GX_TF_IA4 = 0x2,
    Sig_GXInitTexObj_GX_TF_IA8 = 0x3,
    Sig_GXInitTexObj_GX_TF_RGB565 = 0x4,
    Sig_GXInitTexObj_GX_TF_RGB5A3 = 0x5,
    Sig_GXInitTexObj_GX_TF_RGBA8 = 0x6,
    Sig_GXInitTexObj_GX_TF_CMPR = 0xE,
    Sig_GXInitTexObj_GX_CTF_R4 = 0x0 | 0x20,
    Sig_GXInitTexObj_GX_CTF_RA4 = 0x2 | 0x20,
    Sig_GXInitTexObj_GX_CTF_RA8 = 0x3 | 0x20,
    Sig_GXInitTexObj_GX_CTF_YUVA8 = 0x6 | 0x20,
    Sig_GXInitTexObj_GX_CTF_A8 = 0x7 | 0x20,
    Sig_GXInitTexObj_GX_CTF_R8 = 0x8 | 0x20,
    Sig_GXInitTexObj_GX_CTF_G8 = 0x9 | 0x20,
    Sig_GXInitTexObj_GX_CTF_B8 = 0xA | 0x20,
    Sig_GXInitTexObj_GX_CTF_RG8 = 0xB | 0x20,
    Sig_GXInitTexObj_GX_CTF_GB8 = 0xC | 0x20,
    Sig_GXInitTexObj_GX_TF_Z8 = 0x1 | 0x10,
    Sig_GXInitTexObj_GX_TF_Z16 = 0x3 | 0x10,
    Sig_GXInitTexObj_GX_TF_Z24X8 = 0x6 | 0x10,
    Sig_GXInitTexObj_GX_CTF_Z4 = 0x0 | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z8M = 0x9 | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z8L = 0xA | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z16L = 0xC | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_TF_A8 = Sig_GXInitTexObj_GX_CTF_A8,
} Sig_GXInitTexObj_GXTexFmt;

typedef enum Sig_GXInitTexObj__GXTexWrapMode {
    Sig_GXInitTexObj_GX_CLAMP,
    Sig_GXInitTexObj_GX_REPEAT,
    Sig_GXInitTexObj_GX_MIRROR,
    Sig_GXInitTexObj_GX_MAX_TEXWRAPMODE,
} Sig_GXInitTexObj_GXTexWrapMode;

typedef struct Sig_GXInitTexObjLOD__GXTexObj {
    u32 texture_filter;
    u32 texture_lod;
    u32 texture_size;
    u32 texture_address;
    u32 user_data;
    u32 texture_format;
    u32 tlut_name;
    u16 texture_time_count;
    u8 texture_tile_type;
    u8 texture_flags;
} Sig_GXInitTexObjLOD_GXTexObj;

typedef enum Sig_GXInitTexObjLOD__GXTexFilter {
    Sig_GXInitTexObjLOD_GX_NEAR,
    Sig_GXInitTexObjLOD_GX_LINEAR,
    Sig_GXInitTexObjLOD_GX_NEAR_MIP_NEAR,
    Sig_GXInitTexObjLOD_GX_LIN_MIP_NEAR,
    Sig_GXInitTexObjLOD_GX_NEAR_MIP_LIN,
    Sig_GXInitTexObjLOD_GX_LIN_MIP_LIN,
} Sig_GXInitTexObjLOD_GXTexFilter;

typedef u8 Sig_GXInitTexObjLOD_GXBool;

typedef enum Sig_GXInitTexObjLOD__GXAnisotropy {
    Sig_GXInitTexObjLOD_GX_ANISO_1,
    Sig_GXInitTexObjLOD_GX_ANISO_2,
    Sig_GXInitTexObjLOD_GX_ANISO_4,
    Sig_GXInitTexObjLOD_GX_MAX_ANISOTROPY,
} Sig_GXInitTexObjLOD_GXAnisotropy;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} FD844_Vec;

typedef struct {
    f32 x, y, z;
} CasVec;

typedef struct {
    CasVec v;
    u8 pad_C[0x34];
} CasMtx;

typedef struct {
    u32 unk_0;
    u32 unk_4;
} CasObj;

typedef struct {
    f32 x, y, z;
} CasSparkVec;

typedef struct {
    CasSparkVec pos;
    CasSparkVec base;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    s32 unk_30;
} CasSpark;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    f32 unk_C;
    u32 unk_10;
    CasSpark sparks[20];
} CasSparkSet;
extern const f32 lbl_1_rodata_7600;
extern const f32 lbl_1_rodata_7604;
extern u32 GXGetTexBufferSize(u16, u16, u32, u8, u8);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_1_FC4E0(void *arg0, int arg1);
extern void fn_1_FC51C(void);
extern struct fn_1_FD3A8_lbl_801A6D00 lbl_801A6D00;
extern void GXInitTexObj(void *, void *, u32, u32, u32, u32, u32, u32);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern void GXLoadTexMtxImm(void *, u32, u32);
extern u32 fn_800371F8(u32, void *);
extern u32 lbl_8006DCA4(void);
extern void fn_1_57720(u32 value_1, u32 value_2, u32 value_3, u32 value_4);
extern void fn_80015C1C(f32 *out, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);
extern void fn_8003462C(u32 arg0, u32 arg1, u32 arg2);
extern void fn_800720B0(int);
extern void fn_8007245C(u32 value);
extern void fn_800724C8(void);
extern void fn_80072558(void);
extern void fn_80072864(u32 arg0);
extern void fn_800728A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80072AB0(s32 arg0, s32 arg1, s32 arg2);
extern void fn_80072C24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072CC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072D64(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_80072E20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80073678(u32 arg0);
extern void fn_80073778(void *obj, s32 index);
extern void fn_80073898(u32 arg0);
extern void fn_80073C6C(s32 index);
extern void fn_800745A4(u32 arg0, s32 arg1, s32 arg2, u32 arg3, u32 arg4, u32 arg5);
extern void fn_80074660(u32 arg0);
extern void fn_80074788(u32 arg0);
extern void fn_800747D0(u32 arg0, u32 arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DD7C(void);
extern void lbl_8006DFC4(void *);
extern void fn_1_FC760(void *, void *);
extern void fn_8006F1F0(FD844_Vec *, FD844_Vec *, FD844_Vec *);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern u32 fn_1_584AC(void);
extern void *memset(void *, int, u32);
extern s32 fn_1_58C4(void);
extern CasVec lbl_1_rodata_77F8;
extern CasVec lbl_1_rodata_7804;
extern CasMtx *fn_80077B14(CasObj *);
extern void fn_1_1024F8(void);
extern void fn_1_102750(void);
extern void fn_1_102C08(void);
extern void fn_800736C0(u32, void *);
extern void fn_800735C8(s32 index, s32 value);
extern void fn_80073620(s32 index, s32 value);
extern void lbl_8006D758(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006E14C(f32);
extern void *fn_1_563B8(void *);
extern void fn_1_566EC(int arg0, int arg1);
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C();
extern void fn_1_7F230();
extern void fn_1_7F1E8();
extern void *fn_1_14DD68(void *);
extern void *fn_1_14DDF4(void *);
extern void lbl_8006E0A4(void *);
extern int fn_1_FCF50(void);
extern void fn_1_FCA10(void);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_FD3A8();
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(CasEmitter *em);
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
extern void fn_1_FFC60(CasSparkSet *state);
extern void fn_1_FEC7C(void *object);
extern f32 lbl_1_rodata_7590[2];
extern const f32 lbl_1_rodata_7598;
extern u8 lbl_1_bss_850E0[256];
extern const f32 lbl_1_rodata_76A8;
extern u32 fn_1_904(void);
extern u32 fn_1_914(void);
extern void fn_1_681C(u32 index, u32 *output);
extern u32 fn_1_1FB80(void *, u32);
extern void fn_1_FC60C(void);
extern void DCFlushRange(void *, u32);
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
#include "game/main_rel/bg_cas_types.h"

// Activates the selected background-cas state and runs its setup stages.
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
} fn_1_FBC5C_CasEntry;


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
    fn_1_FBC5C_CasEntry *ent = &(((fn_1_FBC5C_CasEntry *)&lbl_1_bss_84454))[idx];
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

    GXLoadTexMtxImm((*((Mtx34 * *)&lbl_801A6D00)), 0x24, 0);
    lbl_8006D758();

    (*(*((Mtx34 * *)&lbl_801A6D00)))[0][0] = 0.0f;
    obj = *(u32 *)(lbl_1_data_3EFA8 + 0x40F0);
    if (*(f32 *)(obj + 0x10) < 0.5f || *(f32 *)(obj + 0x10) >= 1.0f) {
        *(f32 *)(obj + 0x10) = 0.5f;
    }
    obj = *(u32 *)(lbl_1_data_3EFA8 + 0x40F0);
    if (*(f32 *)(obj + 0x14) <= 0.0f || *(f32 *)(obj + 0x14) > 0.5f) {
        *(f32 *)(obj + 0x14) = 0.5f;
    }

    (*(*((Mtx34 * *)&lbl_801A6D00)))[0][2] = CAS_VIEW(0x10);
    (*(*((Mtx34 * *)&lbl_801A6D00)))[0][3] = CAS_VIEW(0x14);
    (*(*((Mtx34 * *)&lbl_801A6D00)))[1][1] = 0.0f;
    (*(*((Mtx34 * *)&lbl_801A6D00)))[2][2] = 0.0f;
    (*(*((Mtx34 * *)&lbl_801A6D00)))[2][3] = 1.0f;

    GXLoadTexMtxImm((*((Mtx34 * *)&lbl_801A6D00)), 0x46, 0);
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

/* fzgx:begin fn_1_FCFA4 noprologue */
#include "rel/main_rel/bg_cas.h"

typedef struct {
    u32 rgba;
} CasColor;

extern u32 camera_get_status(void);
extern s32 camera_get_state(void);
extern u8 fn_1_3F854(void);
extern s16 camera_get_output(void);
extern CasColor lbl_1_rodata_7608;
extern void fn_800724C8(void);
extern void fn_8007245C(u32);
extern void fn_80074788(u32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern u32 fn_800371F8(u32, const CasColor *);
extern void fn_80074918(u8, s32, u8);
extern void fn_800720B0(u32);
extern void fn_80072864(u32);

typedef struct {
    u8 pad_0[0x320];
    s16 unk_320;
} CasTarget;

typedef struct {
    u8 unk_0[0x40F0];
    u32 unk_40F0;
    u8 pad_40F4[0xC];
} CasEntry;

typedef struct CasObj {
    CasTarget *unk_0;
    u8 unk_4;
    u8 pad_5[7];
    u32 unk_C;
    u8 pad_10[0x10];
    CasEntry entries[4];
    s32 (*unk_10420)(void);
    s32 (*unk_10424)(struct CasObj *);
    u8 pad_10428[4];
    void (*unk_1042C)(struct CasObj *, CasEntry *);
} CasObj;

static inline u8 fn_1_FCFA4_check(CasObj *obj)
{
    u32 flags = obj->unk_C;

    if (flags & 0x40000000) {
        CasTarget *target = obj->unk_0;
        u32 status = camera_get_status();
        u8 state = camera_get_state();
        u32 limit = fn_1_3F854();
        u8 *table;
        u8 cur;

        if (target == NULL) {
            return 0;
        }
        table = (u8 *)&lbl_1_data_3EFB0;
        cur = table[target->unk_320];
        if ((s16)status == 2 && state == 6) {
            s16 output = camera_get_output();
            if (output != target->unk_320) {
                return 0;
            }
        } else if ((s16)status != 2) {
            if (++table[target->unk_320] >= limit) {
                ((u8 *)&lbl_1_data_3EFB0)[target->unk_320] = 0;
            }
            if (cur != target->unk_320) {
                return 0;
            }
        }
    } else if (flags & 0x80000000) {
        return 0;
    }
    return 1;
}

void fn_1_FCFA4(CasObj *obj)
{
    struct { CasColor color; CasColor argument; } colors;
    s16 i;

    if (obj == NULL) {
        return;
    }
    if (obj->unk_10420 != NULL && obj->unk_10420() != 0) {
        return;
    }
    if (lbl_1_bss_850C6.unk_0 != 0) {
        return;
    }
    if (!fn_1_FCFA4_check(obj)) {
        return;
    }
    if (obj->unk_10424 != NULL && obj->unk_10424(obj) == 0) {
        return;
    }
    fn_800724C8();
    fn_8007245C(0x2200);
    colors.color = lbl_1_rodata_7608;
    fn_80074788(1);
    fn_800747D0(4, 0, 0, 0, 0, 2, 2);
    colors.argument = colors.color;
    fn_800371F8(0, &colors.argument);
    fn_80074918(1, 7, 0);
    fn_800720B0(0);
    fn_80072864(2);
    for (i = 0; i < obj->unk_4; i++) {
        if (obj->entries[i].unk_40F0 != 0) {
            CasEntry *entry = &obj->entries[i];
            lbl_1_data_3EFA8 = (u32)entry;
            obj->unk_1042C(obj, entry);
        }
    }
}
/* fzgx:end fn_1_FCFA4 */

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

/* fzgx:begin fn_1_FD3A8 noprologue */
#include "types.h"

typedef enum Sig_GXInitTexObj__GXTexFmt {
    Sig_GXInitTexObj_GX_TF_I4 = 0x0,
    Sig_GXInitTexObj_GX_TF_I8 = 0x1,
    Sig_GXInitTexObj_GX_TF_IA4 = 0x2,
    Sig_GXInitTexObj_GX_TF_IA8 = 0x3,
    Sig_GXInitTexObj_GX_TF_RGB565 = 0x4,
    Sig_GXInitTexObj_GX_TF_RGB5A3 = 0x5,
    Sig_GXInitTexObj_GX_TF_RGBA8 = 0x6,
    Sig_GXInitTexObj_GX_TF_CMPR = 0xE,
    Sig_GXInitTexObj_GX_CTF_R4 = 0x0 | 0x20,
    Sig_GXInitTexObj_GX_CTF_RA4 = 0x2 | 0x20,
    Sig_GXInitTexObj_GX_CTF_RA8 = 0x3 | 0x20,
    Sig_GXInitTexObj_GX_CTF_YUVA8 = 0x6 | 0x20,
    Sig_GXInitTexObj_GX_CTF_A8 = 0x7 | 0x20,
    Sig_GXInitTexObj_GX_CTF_R8 = 0x8 | 0x20,
    Sig_GXInitTexObj_GX_CTF_G8 = 0x9 | 0x20,
    Sig_GXInitTexObj_GX_CTF_B8 = 0xA | 0x20,
    Sig_GXInitTexObj_GX_CTF_RG8 = 0xB | 0x20,
    Sig_GXInitTexObj_GX_CTF_GB8 = 0xC | 0x20,
    Sig_GXInitTexObj_GX_TF_Z8 = 0x1 | 0x10,
    Sig_GXInitTexObj_GX_TF_Z16 = 0x3 | 0x10,
    Sig_GXInitTexObj_GX_TF_Z24X8 = 0x6 | 0x10,
    Sig_GXInitTexObj_GX_CTF_Z4 = 0x0 | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z8M = 0x9 | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z8L = 0xA | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z16L = 0xC | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_TF_A8 = Sig_GXInitTexObj_GX_CTF_A8,
} Sig_GXInitTexObj_GXTexFmt;
typedef struct Sig_GXInitTexObj__GXTexObj {
    u32 dummy[8];
} Sig_GXInitTexObj_GXTexObj;
typedef enum Sig_GXInitTexObj__GXTexWrapMode {
    Sig_GXInitTexObj_GX_CLAMP,
    Sig_GXInitTexObj_GX_REPEAT,
    Sig_GXInitTexObj_GX_MIRROR,
    Sig_GXInitTexObj_GX_MAX_TEXWRAPMODE,
} Sig_GXInitTexObj_GXTexWrapMode;
typedef enum Sig_GXInitTexObjLOD__GXAnisotropy {
    Sig_GXInitTexObjLOD_GX_ANISO_1,
    Sig_GXInitTexObjLOD_GX_ANISO_2,
    Sig_GXInitTexObjLOD_GX_ANISO_4,
    Sig_GXInitTexObjLOD_GX_MAX_ANISOTROPY,
} Sig_GXInitTexObjLOD_GXAnisotropy;
typedef u8 Sig_GXInitTexObjLOD_GXBool;
typedef enum Sig_GXInitTexObjLOD__GXTexFilter {
    Sig_GXInitTexObjLOD_GX_NEAR,
    Sig_GXInitTexObjLOD_GX_LINEAR,
    Sig_GXInitTexObjLOD_GX_NEAR_MIP_NEAR,
    Sig_GXInitTexObjLOD_GX_LIN_MIP_NEAR,
    Sig_GXInitTexObjLOD_GX_NEAR_MIP_LIN,
    Sig_GXInitTexObjLOD_GX_LIN_MIP_LIN,
} Sig_GXInitTexObjLOD_GXTexFilter;
typedef struct Sig_GXInitTexObjLOD__GXTexObj {
    u32 texture_filter;
    u32 texture_lod;
    u32 texture_size;
    u32 texture_address;
    u32 user_data;
    u32 texture_format;
    u32 tlut_name;
    u16 texture_time_count;
    u8 texture_tile_type;
    u8 texture_flags;
} Sig_GXInitTexObjLOD_GXTexObj;

extern void GXInitTexObj(Sig_GXInitTexObj_GXTexObj *, void *, u16, u16, Sig_GXInitTexObj_GXTexFmt, Sig_GXInitTexObj_GXTexWrapMode, Sig_GXInitTexObj_GXTexWrapMode, u8);
extern void GXInitTexObjLOD(Sig_GXInitTexObjLOD_GXTexObj *, Sig_GXInitTexObjLOD_GXTexFilter, Sig_GXInitTexObjLOD_GXTexFilter, f32, f32, f32, Sig_GXInitTexObjLOD_GXBool, Sig_GXInitTexObjLOD_GXBool, Sig_GXInitTexObjLOD_GXAnisotropy);
extern u32 GXLoadTexMtxImm(u32, u32, u32);

struct fn_1_FD3A8_lbl_1_rodata_7600 {
    u8 pad_0[0xC];
    f32 unk_C;
    u8 pad_10[0x4];
    f32 unk_14;
    u8 pad_18[0x4];
    f32 unk_1C;
    u8 pad_20[0x28];
    u32 unk_48;
    f32 unk_4C;
};
struct fn_1_FD3A8_lbl_801A6D00 {
    u32 unk_0;
};
struct fn_1_FD3A8_lbl_1_bss_850D4 {
    f32 unk_0;
};
struct fn_1_FD3A8_lbl_1_data_3EFA8 {
    u32 unk_0;
};

extern f32 lbl_1_bss_850D8;
extern struct fn_1_FD3A8_lbl_1_bss_850D4 lbl_1_bss_850D4;
extern struct fn_1_FD3A8_lbl_1_data_3EFA8 lbl_1_data_3EFA8;
extern struct fn_1_FD3A8_lbl_1_rodata_7600 lbl_1_rodata_7600;
extern struct fn_1_FD3A8_lbl_801A6D00 lbl_801A6D00;

extern u32 fn_800371F8(u32, void *);
extern u32 lbl_8006DCA4(void);
extern void fn_1_57720(u32, u32, u32, u32);
extern void fn_80015C1C(void *, f32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void fn_8003462C(u32, u32, u32);
extern void fn_800720B0(u32);
extern void fn_8007245C(u32);
extern void fn_800724C8(void);
extern void fn_80072558(void);
extern void fn_80072864(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80073678(u32);
extern void fn_80073778(void *, s32);
extern void fn_80073898(u32);
extern void fn_80073C6C(s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern void fn_80074918(u8, s32, u8);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DD7C(void);
extern void lbl_8006DFC4(void *);

/* Translate the locked-cache matrix accumulator along its z column. */
static inline void mtxa_translate_z(f32 z) {
    f32 *m = (f32 *)(0xE0000000 + 0x0);
    f32 m02 = m[2];
    f32 m03 = m[3];
    f32 m12 = m[6];
    f32 m13 = m[7];
    f32 m22 = m[10];
    f32 m23 = m[11];
    m02 = m03 + m02 * z;
    m12 = m13 + m12 * z;
    m22 = m23 + m22 * z;
    m[3] = m02;
    m[7] = m12;
    m[11] = m22;
}

#pragma opt_lifetimes off
void fn_1_FD3A8(void *arg0, f32 arg1) {
    f32 fzgx_live;
    struct fn_1_FD3A8_lbl_1_rodata_7600 *p_pool;
    f32 v9;
    f32 v0;
    f32 v1;
    f32 v4;
    f32 v9_2;
    f32 v3;
    f32 v5;
    f32 v6;
    struct { u32 a[12]; } loc_78;
    struct { u32 a[12]; } loc_48;
    struct { u32 a[12]; } loc_18;
    u32 loc_10[2];
    f32 z;

    v0 = *(f32 *)((u8 *)arg0 + 64);
    p_pool = (struct fn_1_FD3A8_lbl_1_rodata_7600 *)&lbl_1_rodata_7600;
    v1 = *(f32 *)(((68) + ((u8 *)arg0)));
    v3 = (v0 * arg1);
    v4 = ((-v0) * arg1);
    v5 = ((-v1) * arg1);
    v6 = (v1 * arg1);
    fn_80072558();
    lbl_8006DB74((void *)(lbl_801A6D00.unk_0 + 96));
    lbl_8006DD7C();
    lbl_8006DB74(&loc_78);
    lbl_8006DCA4();
    lbl_8006DFC4(&loc_78);
    fn_80072558();
    fn_1_57720(1, 1, 1, 0);
    {
        f32 d = (lbl_1_bss_850D8 - lbl_1_bss_850D4.unk_0);
        f32 m = (p_pool->unk_C * d);
        v9 = (lbl_1_bss_850D4.unk_0 + m);
        (void) v9;  /* fzgx: keeps the web at its definition */
    }
    lbl_8006DBAC(&loc_78);
    {
        mtxa_translate_z(-v9);
    }
    lbl_8006DB74(&loc_48);
    lbl_8006DCA4();
    lbl_8006DFC4(&loc_48);
    fn_80072558();
    {
        f32 h = p_pool->unk_14;
        fn_80015C1C(&loc_18, v5, v6, v4, v3, lbl_1_bss_850D4.unk_0, h, h, h, h);
    }
    lbl_8006DBAC(&loc_18);
    lbl_8006DFC4((void *)(lbl_801A6D00.unk_0 + 96));
    fzgx_live = p_pool->unk_4C;
    mtxa_translate_z(fzgx_live - v9);
    GXInitTexObj((Sig_GXInitTexObj_GXTexObj *)((u8 *)lbl_1_data_3EFA8.unk_0 + 0x20), (void *)((u8 *)arg0 + 0x60), 0x40, 0x40, 5, 0, 0, 0);
    {
        z = p_pool->unk_C;
        GXInitTexObjLOD((Sig_GXInitTexObjLOD_GXTexObj *)((u8 *)lbl_1_data_3EFA8.unk_0 + 0x20), 1, 1, z, z, z, 0, 0, 0);
    }
    fn_800724C8();
    fn_8007245C(0x2200);
    loc_10[0] = p_pool->unk_48;
    fn_80074788(1);
    fn_800747D0(4, 0, 0, 0, 0, 2, 2);
    loc_10[1] = loc_10[0];
    fn_800371F8(1, &loc_10[1]);
    fn_80074918(1, 7, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_800720B0(0);
    fn_80072864(2);
    fn_80073778((void *)((u8 *)lbl_1_data_3EFA8.unk_0 + 0x20), 0);
    GXLoadTexMtxImm(lbl_801A6D00.unk_0, 30, 0);
    fn_80074660(1);
    fn_800745A4(0, 0, 0, 30, 0, 125);
    fn_80073678(1);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_80072AB0(0, 0, 0);
    fn_800734A8(0, 0, 0, 4);
    fn_80072C24(0, 2, 8, 3, 15);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 4, 1, 7);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    {
        f32 d = (lbl_1_bss_850D8 - lbl_1_bss_850D4.unk_0);
        f32 m = (v9 * d);
        f32 n = (lbl_1_bss_850D4.unk_0 + m);
        v9_2 = (n / lbl_1_bss_850D4.unk_0);
    }
    fn_8003462C(128, 0, 4);
    {
        f32 a = v9_2 * v4;
        f32 c = v9_2 * v6;
        f32 d = v9_2 * v3;
        f32 b = v9_2 * v5;
        *(volatile f32 *)(((-32768) + ((u8 *)0xCC010000))) = a; /* fzgx-allow: A1,A2 GX FIFO write port 0xCC008000 */
        *(volatile f32 *)(((-32768) + ((u8 *)0xCC010000))) = b; /* fzgx-allow: A1,A2 GX FIFO write port 0xCC008000 */
        *(volatile f32 *)(((-32768) + ((u8 *)0xCC010000))) = p_pool->unk_C; /* fzgx-allow: A1,A2 GX FIFO write port 0xCC008000 */
        *(volatile f32 *)(((-32768) + ((u8 *)0xCC010000))) = p_pool->unk_C; /* fzgx-allow: A1,A2 GX FIFO write port 0xCC008000 */
        *(volatile f32 *)(((-32768) + ((u8 *)0xCC010000))) = p_pool->unk_C; /* fzgx-allow: A1,A2 GX FIFO write port 0xCC008000 */
        *(volatile f32 *)(((-32768) + ((u8 *)0xCC010000))) = a; /* fzgx-allow: A1,A2 GX FIFO write port 0xCC008000 */
        *(volatile f32 *)(((-32768) + ((u8 *)0xCC010000))) = c; /* fzgx-allow: A1,A2 GX FIFO write port 0xCC008000 */
        *(volatile f32 *)(((-32768) + ((u8 *)0xCC010000))) = p_pool->unk_C; /* fzgx-allow: A1,A2 GX FIFO write port 0xCC008000 */
        *(volatile f32 *)(((-32768) + ((u8 *)0xCC010000))) = p_pool->unk_C; /* fzgx-allow: A1,A2 GX FIFO write port 0xCC008000 */
        *(volatile f32 *)(((-32768) + ((u8 *)0xCC010000))) = p_pool->unk_1C; /* fzgx-allow: A1,A2 GX FIFO write port 0xCC008000 */
        *(volatile f32 *)(((-32768) + ((u8 *)0xCC010000))) = d; /* fzgx-allow: A1,A2 GX FIFO write port 0xCC008000 */
        *(volatile f32 *)(((-32768) + ((u8 *)0xCC010000))) = c; /* fzgx-allow: A1,A2 GX FIFO write port 0xCC008000 */
        *(volatile f32 *)(((-32768) + ((u8 *)0xCC010000))) = p_pool->unk_C; /* fzgx-allow: A1,A2 GX FIFO write port 0xCC008000 */
        *(volatile f32 *)(((-32768) + ((u8 *)0xCC010000))) = p_pool->unk_1C; /* fzgx-allow: A1,A2 GX FIFO write port 0xCC008000 */
        *(volatile f32 *)(((-32768) + ((u8 *)0xCC010000))) = p_pool->unk_1C; /* fzgx-allow: A1,A2 GX FIFO write port 0xCC008000 */
        *(volatile f32 *)(((-32768) + ((u8 *)0xCC010000))) = d; /* fzgx-allow: A1,A2 GX FIFO write port 0xCC008000 */
        *(volatile f32 *)(((-32768) + ((u8 *)0xCC010000))) = b; /* fzgx-allow: A1,A2 GX FIFO write port 0xCC008000 */
        *(volatile f32 *)(((-32768) + ((u8 *)0xCC010000))) = p_pool->unk_C; /* fzgx-allow: A1,A2 GX FIFO write port 0xCC008000 */
        *(volatile f32 *)(((-32768) + ((u8 *)0xCC010000))) = p_pool->unk_1C; /* fzgx-allow: A1,A2 GX FIFO write port 0xCC008000 */
        *(volatile f32 *)(((-32768) + ((u8 *)0xCC010000))) = p_pool->unk_C; /* fzgx-allow: A1,A2 GX FIFO write port 0xCC008000 */
    }
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_FD3A8 */

/* fzgx:begin fn_1_FD844 */
typedef struct {
    u32 unk_0;
    u8 pad_4[8];
} FD844_Elem12;

/* the loaded cas object referenced by the context */
typedef struct {
    u8 pad_0[0x338];
    FD844_Elem12 elems[7];  /* 0x338 */
    u8 pad_38C[4];
    u32 unk_390;
    u8 pad_394[0xC];
    u32 unk_3A0;            /* table base, 0x360-byte entries */
    u8 pad_3A4[0x16];
    s16 unk_3BA;
} FD844_Obj;

/* texture descriptor at +0x20 of every 0x2060-byte source entry */
typedef struct {
    s16 unk_0;
    u8 pad_2[2];
    u32 flags;              /* 0x4 */
    s16 rot_x;              /* 0x8 */
    s16 rot_y;              /* 0xA */
    u8 pad_C[0x1C];
    FD844_Vec eye;          /* 0x28 */
    FD844_Vec target;       /* 0x34 */
    f32 unk_40;
    f32 unk_44;
    u8 pad_48[0x18];
    u8 image[0x1FE0];       /* 0x60 */
} FD844_Tex;

typedef struct {
    u8 pad_0[0x20];
    FD844_Tex tex;          /* 0x20 */
} FD844_Src;                /* 0x2060 bytes */

typedef struct {
    u8 pad_0[0x40];
    u8 texobj[0x20];        /* 0x40 */
    u8 pad_60[0x60];
    u8 mtx[0x30];           /* 0xC0 */
    u8 pad_F0[0x4104 - 0xF0];
    f32 unk_4104;
    f32 unk_4108;
    FD844_Obj *obj;         /* 0x410C */
    FD844_Tex *tex;         /* 0x4110 */
    void *sel;              /* 0x4114 */
} FD844_Slot;

typedef struct {
    FD844_Obj *obj;         /* 0x0 */
    u8 count;               /* 0x4 */
    u8 pad_5[0x10428 - 0x5];
    u32 unk_10428;
} FD844_Ctx;

/* slot i of the context: 0x4100 bytes apart, the trailing fields overlap the next slot */
#define FD844_SLOT(ctx, i) ((FD844_Slot *)((u8 *)(ctx) + (i) * 0x4100))


/* Literal pool of the retail TU (lbl_1_rodata_7600): MWCC pools literals in
 * first-use order across the TU, so the earlier functions' literals come first. */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sink */
    s = 2.0f;
    s = 8.0f;
}
static const u32 fzgx_pool_table2[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sink */
    s = 0.0f;
}
static const u32 fzgx_pool_table4[11] = {0x00000000, 0x3F000000, 0x41800000, 0x3F800000, 0x43000000,
                                         0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0xBF800000,
                                         0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

int fn_1_FD844(FD844_Src *src, FD844_Ctx *ctx) {
    u8 i;
    u32 table;
    u8 j;
    FD844_Obj *obj;
    u32 off;
    u8 *texobj;
    FD844_Vec target;
    FD844_Vec eye;

    obj = ctx->obj;
    if (src == NULL) {
        return 0;
    }
    if (ctx == NULL) {
        return 0;
    }
    if (obj == NULL) {
        return 0;
    }
    if (obj->unk_390 & 0x4000000) {
        for (j = 0; j < 3; j++) {
            table = obj->unk_3A0;
            if (table == 0) {
                return 0;
            }
            off = obj->unk_3BA << 2;
            off += j * 0x360;
            if (*(u32 *)(table + off + 0x344) == 0) {
                return 0;
            }
        }
    } else {
        if (obj->elems[obj->unk_3BA].unk_0 == 0) {
            return 0;
        }
    }

    for (i = 0; i < ctx->count; i++) {
        if (!(src[i].tex.flags & 0x80000000)) {
            *(u32 *)((u32)ctx + i * 0x4100 + 0x4110) = 0;
        } else {
            FD844_Vec up;
            FD844_SLOT(ctx, i)->obj = ctx->obj;
            {
                FD844_Vec up_init = {0.0f, 1.0f, 0.0f};
                up = up_init;
            }
            eye = src[i].tex.eye;
            target = src[i].tex.target;
            lbl_1_bss_850D4 = 2.0f;
            lbl_1_bss_850D8 = 8.0f;
            FD844_SLOT(ctx, i)->tex = &src[i].tex;
            FD844_SLOT(ctx, i)->sel = (void *)((u32)src + (src[i].tex.unk_0 << 3) + 0x81A4);
            FD844_SLOT(ctx, i)->unk_4104 = FD844_SLOT(ctx, i)->tex->unk_40;
            FD844_SLOT(ctx, i)->unk_4108 = FD844_SLOT(ctx, i)->tex->unk_44;
            fn_8006F1F0(&eye, &up, &target);
            mathutil_mtxA_rotate_x(FD844_SLOT(ctx, i)->tex->rot_x);
            mathutil_mtxA_rotate_y(FD844_SLOT(ctx, i)->tex->rot_y);
            lbl_8006DB74(FD844_SLOT(ctx, i)->mtx);
            texobj = FD844_SLOT(ctx, i)->texobj;
            GXInitTexObj(texobj, FD844_SLOT(ctx, i)->tex->image, 0x40, 0x40, 5, 0, 0, 0);
            GXInitTexObjLOD(texobj, 1, 1, 0.0f, 0.0f, 0.0f, 0, 0, 0);
        }
    }

    for (i = 0; i < ctx->count; i++) {
        FD844_Tex *tex;
        if (ctx->unk_10428 == 0) {
            break;
        }
        tex = FD844_SLOT(ctx, i)->tex;
        if (tex != NULL && (tex->flags & 0x80000000)) {
            if (0.0f == tex->unk_40 || 0.0f == tex->unk_44) {
                tex->flags &= 0x7FFFFFFF;
            } else {
                fn_1_FC760(ctx, &FD844_SLOT(ctx, i)->pad_0[0x20]);
            }
        }
    }
    return 1;
}
/* fzgx:end fn_1_FD844 */

/* fzgx:begin fn_1_FDB40 */
s32 fn_1_FDB40(void * arg0) {
    u32 unk_1;
    u32 unk_2;
    u32 v2;
    if ((u32)arg0 == 0) {
        return 0;
    }
    unk_1 = *(u32 *)arg0;
    if (unk_1 == 0) {
        return 0;
    }
    if (*(s16 *)((u8 *)unk_1 + 800) >= 4) {
        return 0;
    }
    if (*(u32 *)((u8 *)unk_1 + 932) == 0) {
        return 0;
    }
    if (*(s16 *)((u8 *)unk_1 + 954) == 5) {
        return 0;
    }
    if (__rlwnm(*(u32 *)((u8 *)unk_1 + 912), 6, 31, 31) != 0 && *(u32 *)((u8 *)unk_1 + 928) == 0) {
        return 0;
    }
    if ((*(u32 *)((u8 *)unk_1 + 912) & 0x200000) != 0) {
        return 0;
    }
    v2 = *(u32 *)((u8 *)unk_1 + 812);
    if (v2 != 0 && (*(u32 *)((u8 *)v2 + 1420) & 0x10) != 0) {
        return 0;
    }
    return 1;
}
/* fzgx:end fn_1_FDB40 */

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
    fn_1_FFC60( (CasSparkSet *)(Obj_1_data_2A7E0_At3C *)(obj));
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

/* fzgx:begin fn_1_FE644 */
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
#pragma section code_type ".text"

typedef struct { u8 r, g, b, a; } Col4;

extern void fn_1_9AD54(void);
extern u32 fn_1_FFE7C(void *);
extern void fn_1_FED34(void *);
extern void fn_1_9A7A8(Col4 *);

#pragma opt_common_subs off
static inline f32 clamp_fade(f32 v) {
    f32 t = 0.0f;
    if (v < t) {
        return t;
    }
    t = 1.0f;
    if (v > t) {
        return t;
    }
    return v;
}
void fn_1_FE644(void) {
    Obj_1_data_2A7E0_At3C *obj;
    f32 t;
    s32 c;
    f32 v;
    Col4 out;

    obj = lbl_1_data_2A7E0.unk_3C;
    fn_1_9AD54();
    if ((s32)obj->unk_10 != 0) {
        fn_1_FFE7C(obj);
    }
    fn_1_FED34(obj);
    t = 0.0f;
    c = (s16)(*(s16 *)((u8 *)obj + 0x1B1E4));
    if (c < 0x1e78) {
        *(s16 *)((u8 *)obj + 0x1B1E4) = c + 1;
    }
    c = (s16)(*(s16 *)((u8 *)obj + 0x1B1E4));
    if (c > 0x4b0) {
        v = (f32)(s16)(c - 0x4b0) / 6600.0f;
        t = clamp_fade(v);
    }
    {
        Col4 col = *(const Col4 *)fzgx_pool_table2;
        col.r = (s32)(110.0f * t);
        col.g = (s32)(60.0f * t);
        col.b = (s32)(15.0f * t);
        out = col;
    }
    fn_1_9A7A8(&out);
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_FE644 */

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

/* fzgx:begin fn_1_FE7D8 */
typedef struct {
    f32 x, y, z;
} FE7D8_Vec;

/* one 0x24-byte spawn point of the background table */
typedef struct {
    FE7D8_Vec from;  /* 0x00 */
    s16 unk_C;
    s16 unk_E;
    u8 pad_10[4];
    FE7D8_Vec to;    /* 0x14 */
    u8 pad_20[4];
} FE7D8_Spawn;

typedef struct {
    s32 active;      /* 0x00 */
    s32 life;        /* 0x04 */
    FE7D8_Vec pos;   /* 0x08 */
    FE7D8_Vec prev;  /* 0x14 */
    FE7D8_Vec vel;   /* 0x20 */
    u16 rot_x;       /* 0x2C */
    u16 rot_y;       /* 0x2E */
    s16 spin_x;      /* 0x30 */
    s16 spin_y;      /* 0x32 */
    f32 unk_34;
    f32 size;        /* 0x38 */
} FE7D8_Particle;

extern u32 fn_1_584AC(void);
extern void lbl_8006D5F0(FE7D8_Vec *src, FE7D8_Vec *dst, f32 scale);
extern void lbl_8006D8D8(s16 angle);
extern void lbl_8006E1C0(FE7D8_Vec *src, FE7D8_Vec *dst);

/* uniform random value in [0, 1] */
#define RANDF() ((f32)(u16)fn_1_584AC() / 32767.0f)

/* Literal pool of the retail TU (lbl_1_rodata_76A8): MWCC pools literals in
 * first-use order across the TU, so the earlier functions' literals come first. */
#pragma section code_type ".fzgxpool"
static void fzgx_pool_layout(void) {
    volatile f32 s; /* fzgx-allow: S2 pool primer sink: fixes the TU literal order */
    s = 0.0f;
}

static const u32 fzgx_pool_table_4[1] = {0x00000000};

static void fzgx_pool_layout_1(void) {
    volatile f32 s; /* fzgx-allow: S2 pool primer sink: fixes the TU literal order */
    volatile s32 i; /* fzgx-allow: S2 pool primer sink: fixes the TU literal order */
    volatile u32 w; /* fzgx-allow: S2 pool primer sink: fixes the TU literal order */
    w = fzgx_pool_table_4[0];
    s = 1.0f;
    s = 6600.0f;
    s = 110.0f;
    s = 60.0f;
    s = 15.0f;
    s = (f32)i;
}
#pragma section code_type ".text"

#pragma fp_contract off
void fn_1_FE7D8(u8 *arg0, s32 arg1) {
    FE7D8_Particle *p = (FE7D8_Particle *)arg0;
    FE7D8_Spawn *e;
    FE7D8_Vec d;

    e = (FE7D8_Spawn *)lbl_1_bss_3BE0->unk_A8;
    e += (u16)fn_1_584AC() % (s32)lbl_1_bss_3BE0->unk_A4;
    p->active = arg1;
    if (arg1 != 0) {
        p->life = 100.0f + 300.0f * RANDF();
        p->pos = e->from;
        p->prev = p->pos;
        d.x = e->to.x - e->from.x;
        d.y = e->to.y - e->from.y;
        d.z = e->to.z - e->from.z;
        lbl_8006D5F0(&d, &p->vel, (f32)(e->unk_E >> 7) * (15.0f + 4.0f * RANDF()) / 10.0f);
        p->size = 2.0f + 2.0f * RANDF();
        p->size *= (f32)(e->unk_C >> 7) / 10.0f;
    } else {
        p->life = 200.0f + 400.0f * RANDF();
        {
            FE7D8_Vec dir = {0.0f, 0.0f, -1.0f};

            d = dir;
        }
        lbl_8006D8D8(fn_1_584AC());
        lbl_8006E1C0(&d, &d);
        lbl_8006D5F0(&d, &p->pos, 2500.0f + 1000.0f * RANDF());
        p->pos.y = 1400.0f + 300.0f * RANDF();
        p->vel.x = RANDF() - 0.5 - 5.0;
        p->vel.y = -(4.0f + 7.0f * RANDF());
        p->vel.z = RANDF() - 0.5;
        p->size = 2.0f + 2.5f * RANDF();
    }
    p->rot_x = fn_1_584AC();
    p->rot_y = fn_1_584AC();
    p->spin_x = (s32)(768.0f * RANDF()) + 256;
    p->spin_y = (s32)(768.0f * RANDF()) + 256;
    p->unk_34 = 0.0f;
}
#pragma fp_contract reset
/* fzgx:end fn_1_FE7D8 */

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
        fn_1_FF420( (CasEmitter *)(u8 *)(entry));
        index++;
        entry += 0x44C;
    }
    while (count < 0x64) {
        fn_1_FE7D8(entry, 0);
        fn_1_FF420( (CasEmitter *)(u8 *)(entry));
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

/* fzgx:begin fn_1_FF420 */
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
}
#pragma section code_type ".text"

/* random fraction in [0, 1] */
#define RAND_FRAC() ((f32)(u16)fn_1_584AC() / 32767.0f)

/* velocity jittered by up to 10%; the casts keep retail's separate fmul/fadd */
#define JITTER(v) ((f64)(0.9 * (v)) + (f64)(0.1 * (v) * RAND_FRAC()))

void fn_1_FF420(CasEmitter *em) {
    s32 i;
    CasParticle *p;
    f32 v;

    p = em->particles;
    memset(p, 0, sizeof(em->particles));
    for (i = 0; i < 20; i++, p++) {
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
}
/* fzgx:end fn_1_FF420 */

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

/* fzgx:begin fn_1_FFC60 */
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
    s = 0.2f;
    s = 6.0f;
    s = 0.02f;
}
#pragma section code_type ".text"


 /* 0x34 */



/* random fraction in [0, 1] */
#define RAND01() ((f32)(u16)fn_1_584AC() / 32767.0f)

void fn_1_FFC60(CasSparkSet *state) {
    s32 i;
    CasSpark *p;
    u8 *obj;

    if ((u32)fn_1_58C4() < 2) {
        state->unk_10 = 1;
    } else {
        state->unk_10 = 0;
        return;
    }
    state->unk_C = 0.0f;
    obj = *(u8 **)(lbl_1_bss_38458->unk_8 + 0xA0);
    state->unk_0 = *(u32 *)(obj + 0x24);
    state->unk_4 = *(u32 *)(obj + 0x24);
    p = state->sparks;
    for (i = 20; i > 0; i--, p++) {
        p->pos.x = 6.0f * RAND01();
        p->pos.y = 6.0f * RAND01();
        p->pos.z = 6.0f * RAND01();
        p->base = p->pos;
        p->unk_18 = 0.0f;
        p->unk_1C = 0.0f;
        p->unk_20 = 0.0f;
        p->unk_24 = 0.0f;
        p->unk_2C = 0.02f * (1.0f + RAND01());
        p->unk_28 = p->unk_2C;
        p->unk_30 = (s32)(15.0f * RAND01());
    }
}
/* fzgx:end fn_1_FFC60 */

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

/* fzgx:begin fn_1_10161C */
typedef struct {
    u8 pad_0[0x8];
    CasObj **unk_8;
} CasTable;

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 pad_3;
    u16 unk_4[6];
    CasVec unk_10;
    u8 pad_1C[0xC];
    CasVec unk_28;
    CasVec unk_34;
    u8 pad_40[0x4];
} fn_1_10161C_CasEntry;


typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    CasTable *unk_10;
    s32 unk_14;
    fn_1_10161C_CasEntry *unk_18;
    u32 unk_1C;
} CasState;

typedef struct {
    u8 pad_0[0x8];
    u16 unk_8;
} CasInput;


void fn_1_10161C(void) {
    CasState *st = &(*((CasState *)&lbl_1_bss_85250));
    CasObj *obj;
    CasMtx *mtx;

    obj = st->unk_10->unk_8[st->unk_4 * 2];
    if (obj == NULL) {
        return;
    }
    mtx = fn_80077B14(obj);
    if (((*((CasInput *)&lbl_1_bss_D58)).unk_8 >> 4) & 1) {
        st->unk_0 ^= 1;
    }
    if (((*((CasInput *)&lbl_1_bss_D58)).unk_8 >> 3) & 1) {
        st->unk_14 = ((u32)st->unk_14 + 4) % 3;
        if (obj->unk_4 & 0x10) {
            u32 i;
            u32 j;

            for (i = 0; i < st->unk_1C; i++) {
                st->unk_18[i].unk_10 = st->unk_18[i].unk_28;
                for (j = 0; j < st->unk_18[i].unk_2; j++) {
                    mtx[st->unk_18[i].unk_4[j]].v = st->unk_18[i].unk_10;
                }
                st->unk_18[i].unk_34 = lbl_1_rodata_77F8;
            }
        }
    } else if (((*((CasInput *)&lbl_1_bss_D58)).unk_8 >> 2) & 1) {
        st->unk_14 = ((u32)st->unk_14 + 2) % 3;
        if (obj->unk_4 & 0x10) {
            u32 i;
            u32 j;

            for (i = 0; i < st->unk_1C; i++) {
                st->unk_18[i].unk_10 = st->unk_18[i].unk_28;
                for (j = 0; j < st->unk_18[i].unk_2; j++) {
                    mtx[st->unk_18[i].unk_4[j]].v = st->unk_18[i].unk_10;
                }
                st->unk_18[i].unk_34 = lbl_1_rodata_7804;
            }
        }
    }
    if (obj->unk_4 & 0x10) {
        switch (st->unk_14) {
        case 0:
        default:
            fn_1_1024F8();
            break;
        case 1:
            fn_1_102750();
            break;
        case 2:
            fn_1_102C08();
            break;
        }
    }
}
/* fzgx:end fn_1_10161C */
