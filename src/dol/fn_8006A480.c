#include "types.h"
typedef struct Sig_fn_8006A554_Sig_fn_8006A554_Fn8006A9B4Entry {
    u32 flags;
    u32 b;
    u32 c;
} Sig_fn_8006A554_Sig_fn_8006A554_Fn8006A9B4Entry;
typedef struct Sig_fn_8006A554_Sig_fn_8006A554_Fn8006A9B4Data {
    u8 _pad0[4];
    Sig_fn_8006A554_Sig_fn_8006A554_Fn8006A9B4Entry *entries;
    u8 _pad8[8];
    u8 *strings;
    u32 unk14;
    s32 index;
} Sig_fn_8006A554_Sig_fn_8006A554_Fn8006A9B4Data;
typedef struct Sig_fn_8006A8CC_Sig_fn_8006A768_FstEntry {
    u32 nameOffset;
    u32 parent;
    u32 next;
} Sig_fn_8006A8CC_Sig_fn_8006A768_FstEntry;
typedef struct Sig_fn_8006A8CC_Sig_fn_8006A768_FstInfo {
    u8 pad_0[0x4];
    Sig_fn_8006A8CC_Sig_fn_8006A768_FstEntry *entries;
    u8 pad_8[0x8];
    u8 *strings;
    u8 pad_14[4];
    u32 index;
} Sig_fn_8006A8CC_Sig_fn_8006A768_FstInfo;
struct fn_8006A480_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};
struct fn_8006A480_Copy8 { u32 a[2]; };
extern s32 fn_8006A8CC(Sig_fn_8006A8CC_Sig_fn_8006A768_FstInfo *, u8 *, u32);
extern u32 fn_8006A554(Sig_fn_8006A554_Sig_fn_8006A554_Fn8006A9B4Data *, u32);
extern char lbl_801327AC[70];
extern void OSReport(const char *, ...);

s32 fn_8006A480(struct fn_8006A480_Arg0 *arg0, void *arg1, void *arg2) {
    Sig_fn_8006A554_Sig_fn_8006A554_Fn8006A9B4Entry *v2 = (Sig_fn_8006A554_Sig_fn_8006A554_Fn8006A9B4Entry *)arg0->unk_4;
    s32 t0;
    struct { u32 a[32]; } loc_14;
    t0 = fn_8006A554((Sig_fn_8006A554_Sig_fn_8006A554_Fn8006A9B4Data *)arg0, (u32)arg1);
    if (t0 < 0) {
        fn_8006A8CC((Sig_fn_8006A8CC_Sig_fn_8006A768_FstInfo *)arg0, (u8 *)&loc_14, 128);
        OSReport(lbl_801327AC, arg1, &loc_14);
        return 0;
    }
    if (t0 < 0 || ((v2[t0].flags & 0xFF000000) == 0 ? 0 : 1)) {
        return 0;
    }
    *(u32 *)arg2 = (u32)arg0;
    *(u32 *)((u8 *)arg2 + 4) = v2[t0].b;
    *(u32 *)((u8 *)arg2 + 8) = v2[t0].c;
    return 1;
}
