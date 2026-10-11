#include "types.h"

typedef struct Fn12_39A68_Object {
    u8 _pad0[0x04];
    s32 state;
    u8 _pad8[0x38];
    u32 handle;
} Fn12_39A68_Object;

typedef struct Fn12_39A68_Info {
    u8 _pad0[0x04];
    s32 unk4;
    u8 _pad8[0x08];
    s32 unk10;
    u8 _pad14[0x08];
    s32 unk1C;
    u8 _pad20[0x20];
} Fn12_39A68_Info;

typedef struct Fn12_39A68_Out {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Fn12_39A68_Out;

#pragma readonly_strings on

extern void MWSFSVM_Error(const char *format, ...);
extern void fn_12_2D58C(u32 handle, Fn12_39A68_Info *info);
extern s32 fn_12_33874(Fn12_39A68_Object *object);

/* Primes the TU literal pool in retail order (lbl_12_rodata_2718 onwards). */
#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_pool_fn_12_39A68(s32 x, f32 *o, double *d) {
    MWSFSVM_Error("E1122640: mwPlyGetSfdHn: handle is invalid.");
    MWSFSVM_Error("E2093001 mwPlyAttachM2v: worksize is invalid.");
    MWSFSVM_Error("E211051: mwPlySetFloatSpeed: handle is invalid.");
    *d = 0.5;
    o[0] = 1000.0f;
    d[1] = 4503601774854144.0; /* 0x4330000080000000, the int-to-float bias */
    MWSFSVM_Error("E302251: mwPlySetSpeed: handle is invalid.");
    MWSFSVM_Error("E202191: mwPlyGetPlyInf: handle is invalid.");
    MWSFSVM_Error("E202232: mwPlyGetNumDropFrm: handle is invalid.");
    MWSFSVM_Error("E1122619: mwPlyGetNumSkipDec: handle is invalid.");
    MWSFSVM_Error("E1122623: mwPlyGetNumSkipEmptyB: handle is invalid.");
}

static inline s32 GetState(Fn12_39A68_Object *object) {
    if (object == 0) {
        return 0;
    }
    return object->state;
}

static inline u32 mwPlyGetSfdHn(Fn12_39A68_Object *object) {
    if (GetState(object) == 0) {
        MWSFSVM_Error("E1122640: mwPlyGetSfdHn: handle is invalid.");
        return 0;
    }
    return object->handle;
}

static inline s32 mwPlyGetNumSkipDec(Fn12_39A68_Object *object) {
    Fn12_39A68_Info info;

    if (GetState(object) == 0) {
        MWSFSVM_Error("E1122619: mwPlyGetNumSkipDec: handle is invalid.");
        return 0;
    }
    fn_12_2D58C(mwPlyGetSfdHn(object), &info);
    return info.unk4 - info.unk10;
}

static inline s32 mwPlyGetNumDropFrm(Fn12_39A68_Object *object) {
    if (GetState(object) == 0) {
        MWSFSVM_Error("E202232: mwPlyGetNumDropFrm: handle is invalid.");
        return 0;
    }
    return mwPlyGetNumSkipDec(object) + fn_12_33874(object);
}

static inline s32 mwPlyGetNumSkipEmptyB(Fn12_39A68_Object *object) {
    Fn12_39A68_Info info;

    if (GetState(object) == 0) {
        MWSFSVM_Error("E1122623: mwPlyGetNumSkipEmptyB: handle is invalid.");
        return 0;
    }
    fn_12_2D58C(object->handle, &info);
    return info.unk10;
}

void fn_12_39A68(Fn12_39A68_Object *object, Fn12_39A68_Out *out) {
    Fn12_39A68_Info info;

    if (GetState(object) == 0) {
        MWSFSVM_Error("E202191: mwPlyGetPlyInf: handle is invalid.");
        return;
    }
    fn_12_2D58C(mwPlyGetSfdHn(object), &info);
    out->unk0 = mwPlyGetNumDropFrm(object);
    out->unk4 = mwPlyGetNumSkipDec(object);
    out->unk8 = fn_12_33874(object);
    out->unkC = mwPlyGetNumSkipEmptyB(object);
    out->unk10 = info.unk1C;
}
