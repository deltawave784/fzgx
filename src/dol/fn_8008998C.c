#include "types.h"
typedef struct Sig_fn_8008998C_TRKBuffer Sig_fn_8008998C_TRKBuffer;
struct Sig_fn_8008998C_TRKBuffer {
    u32 mutex;
    u32 isInUse;
    u32 length;
    u32 position;
    u8 data[(0x800 + 0x80)];
};
struct Sig_fn_80089144_fn_80089144_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u32 unk_C;
};
struct Reply {
    u32 unk_0;
    u8 unk_4;
    u8 pad_5[3];
    u8 unk_8;
    u8 pad_9[0x37];
};
extern s32 fn_80089144(struct Sig_fn_80089144_fn_80089144_Arg0 *, u32);
extern s32 fn_8008D398(u32, u32);
extern s32 TRKTargetStopped(void);
extern u32 fn_8008B6BC(void);
extern void *memset(void *, int, u32);
extern s32 fn_8008B784(u32, u32);
extern s32 fn_8008B6CC(u32, u32, u32);

s32 fn_8008998C(Sig_fn_8008998C_TRKBuffer *arg0) {
    s32 v0;
    u32 v4;
    u32 v1;
    u32 v2;
    u32 v5;
    struct Reply loc_108;
    struct Reply loc_C8;
    struct Reply loc_88;
    struct Reply loc_48;
    struct Reply loc_8;
    s32 result;
    fn_80089144((struct Sig_fn_80089144_fn_80089144_Arg0 *)arg0, 0);
    v0 = arg0->data[8];
    v1 = *(u32 *)((u8 *)arg0 + 32);
    v2 = *(u32 *)((u8 *)arg0 + 36);
    switch (v0) {
    case 0:
    case 16:
        v4 = arg0->data[12];
        if (v4 < 1) {
            memset(&loc_108, 0, 64);
            loc_108.unk_4 = 128;
            loc_108.unk_0 = 64;
            loc_108.unk_8 = 17;
            fn_8008D398((u32)&loc_108, 64);
            return 0;
        }
        break;
    case 1:
    case 17:
        v5 = fn_8008B6BC();
        if (v5 < v1 || v5 > v2) {
            memset(&loc_C8, 0, 64);
            loc_C8.unk_4 = 128;
            loc_C8.unk_0 = 64;
            loc_C8.unk_8 = 17;
            fn_8008D398((u32)&loc_C8, 64);
            return 0;
        }
        break;
    default:
        memset(&loc_88, 0, 64);
        loc_88.unk_4 = 128;
        loc_88.unk_0 = 64;
        loc_88.unk_8 = 18;
        fn_8008D398((u32)&loc_88, 64);
        return 0;
    }
    if (!TRKTargetStopped()) {
        memset(&loc_48, 0, 64);
        loc_48.unk_4 = 128;
        loc_48.unk_0 = 64;
        loc_48.unk_8 = 22;
        fn_8008D398((u32)&loc_48, 64);
        return 0;
    }
    memset(&loc_8, 0, 64);
    loc_8.unk_4 = 128;
    loc_8.unk_0 = 64;
    loc_8.unk_8 = 0;
    fn_8008D398((u32)&loc_8, 64);
    result = 0;
    switch (v0) {
    case 0:
    case 16:
        result = fn_8008B784(v4, v0 == 16);
        break;
    case 1:
    case 17:
        result = fn_8008B6CC(v1, v2, v0 == 17);
        break;
    }
    return result;
}
