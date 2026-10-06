#include "types.h"
#include "dolphin/trk.h"
typedef struct Sig_fn_80089C5C_TRKBuffer {
    u32 mutex;
    u32 isInUse;
    u32 length;
    u32 position;
    u8 data[0x880];
} Sig_fn_80089C5C_TRKBuffer;
struct Sig_fn_80089144_fn_80089144_Arg0 { u8 pad_0[8]; u32 unk_8; u32 unk_C; };
struct Sig_fn_80089174_fn_80089174_Arg0 { u8 pad_0[8]; u32 unk_8; u32 unk_C; };
struct Sig_fn_80088B00_fn_80088B00_Arg0 { u8 pad_0[8]; u32 unk_8; };
typedef TRKBuffer Sig_TRKTargetAccessDefault_TRKBuffer;
typedef DSError Sig_TRKTargetAccessDefault_DSError;
struct Reply { u32 unk_0; u8 unk_4; u8 pad_5[3]; u8 unk_8; u8 pad_9[0x37]; };
extern DSError TRKAppendBuffer(TRKBuffer *, const void *, size_t);
extern DSError fn_8008BFB4(u32, u32, TRKBuffer *, size_t *, BOOL);
extern Sig_TRKTargetAccessDefault_DSError TRKTargetAccessDefault(u32, u32, Sig_TRKTargetAccessDefault_TRKBuffer *, size_t *, BOOL);
extern s32 fn_80088B00(struct Sig_fn_80088B00_fn_80088B00_Arg0 *);
extern s32 fn_80089144(struct Sig_fn_80089144_fn_80089144_Arg0 *, u32);
extern s32 fn_8008D398(u32, u32);
extern u32 fn_80089174(struct Sig_fn_80089174_fn_80089174_Arg0 *, u32);
extern u32 fn_8008BB7C(u32, u32, u32, void *, u32);
extern u32 fn_8008C124(u32, u32, u32, void *, u32);
extern u32 lbl_800958F0[];
extern u32 lbl_80095910[];
extern void *memset(void *, int, u32);
extern void MWTRACE(u32, ...);
s32 fn_80089C5C(Sig_fn_80089C5C_TRKBuffer *arg0) {
    s32 v0;
    u32 v1;
    u32 v2;
    s32 v3;
    s32 v4;
    s32 v5;
    s32 v6;
    s32 v7;
    s32 v8;
    struct Reply loc_8C;
    struct Reply loc_4C;
    struct Reply loc_C;
    u32 loc_8;
    v0 = arg0->data[8];
    v1 = *(u16 *)((u8 *)arg0 + 28);
    v2 = *(u16 *)((u8 *)arg0 + 32);
    fn_80089144((struct Sig_fn_80089144_fn_80089144_Arg0 *)arg0, 0);
    if (v1 > v2) {
        memset(&loc_4C, 0, 64);
        loc_4C.unk_4 = 128;
        loc_4C.unk_0 = 64;
        loc_4C.unk_8 = 20;
        fn_8008D398((u32)&loc_4C, 64);
        return 0;
    }
    fn_80089144((struct Sig_fn_80089144_fn_80089144_Arg0 *)arg0, 64);
    switch (v0) {
    case 0:
        v0 = TRKTargetAccessDefault(v1, v2, (Sig_TRKTargetAccessDefault_TRKBuffer *)arg0, (size_t *)&loc_8, 0);
        break;
    case 1:
        v0 = fn_8008C124(v1, v2, (u32)arg0, &loc_8, 0);
        break;
    case 2:
        v0 = fn_8008BFB4(v1, v2, (TRKBuffer *)arg0, (size_t *)&loc_8, 0);
        break;
    case 3:
        v0 = fn_8008BB7C(v1, v2, (u32)arg0, &loc_8, 0);
        break;
    default:
        v0 = 1795;
    }
    fn_80089174((struct Sig_fn_80089174_fn_80089174_Arg0 *)arg0, 0);
    if (v0 == 0) {
        memset(&loc_8C, 0, 64);
        loc_8C.unk_0 = 64;
        loc_8C.unk_4 = 128;
        loc_8C.unk_8 = v0;
        v0 = TRKAppendBuffer((TRKBuffer *)arg0, &loc_8C, 64);
    }
    if (v0 != 0) {
        switch (v0) {
        case 1795: v0 = 18; break;
        case 1793: v0 = 20; break;
        case 770: v0 = 2; break;
        case 1794: v0 = 21; break;
        case 1796: v0 = 33; break;
        case 1797: v0 = 34; break;
        case 1798: v0 = 32; break;
        default: v0 = 3;
        }
        memset(&loc_C, 0, 64);
        loc_C.unk_4 = 128;
        loc_C.unk_0 = 64;
        loc_C.unk_8 = v0;
        fn_8008D398((u32)&loc_C, 64);
        return 0;
    }
    MWTRACE(1, (u32)&lbl_800958F0);
    v0 = fn_80088B00((struct Sig_fn_80088B00_fn_80088B00_Arg0 *)arg0);
    MWTRACE(1, (u32)&lbl_80095910, v0);
    return v0;
}
