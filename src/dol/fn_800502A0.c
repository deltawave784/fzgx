#include "types.h"

struct Buffer {
    u8 *ptr;
    s32 size;
};
struct fn_800502A0_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    s32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    struct Buffer unk_1C;
    s32 unk_24;
    u8 *unk_28;
};
typedef void (*SetFn)(u32, s32, struct Buffer *);
typedef void (*ReadFn)(u32, s32, u32, struct Buffer *);
extern u32 fn_800589BC(struct Buffer *, s32, struct Buffer *, struct Buffer *);

void fn_800502A0(struct fn_800502A0_Arg0 *arg0) {
    s32 count;
    struct Buffer buf;
    struct Buffer rest;
    count = (32 - arg0->unk_C) / 8;
    if (arg0->unk_24 < 4) {
        buf = arg0->unk_1C;
        if (buf.size != 0) {
            fn_800589BC(&buf, buf.size - arg0->unk_24, &buf, &rest);
            ((SetFn)*(u32 *)(*(u32 *)arg0->unk_4 + 0x20))(arg0->unk_4, 0, &buf);
            ((SetFn)*(u32 *)(*(u32 *)arg0->unk_4 + 0x1C))(arg0->unk_4, 1, &rest);
        }
        ((ReadFn)*(u32 *)(*(u32 *)arg0->unk_4 + 0x18))(arg0->unk_4, 1, arg0->unk_18, &arg0->unk_1C);
        arg0->unk_28 = arg0->unk_1C.ptr;
        arg0->unk_24 = arg0->unk_1C.size;
    }
    { s32 n = arg0->unk_24;
    u32 v;
    u8 *p;
    if (count < n) n = count;
    if (n == 3) {
        p = arg0->unk_28;
        v = arg0->unk_8;
        v = (v << 8) | *p++;
        v = (v << 8) | *p++;
        v = (v << 8) | *p++;
        arg0->unk_28 = p;
        arg0->unk_8 = v;
        arg0->unk_C += 24;
        arg0->unk_24 -= 3;
    } else if (n == 2) {
        p = arg0->unk_28;
        v = arg0->unk_8;
        v = (v << 8) | *p++;
        v = (v << 8) | *p++;
        arg0->unk_28 = p;
        arg0->unk_8 = v;
        arg0->unk_C += 16;
        arg0->unk_24 -= 2;
    } else if (n == 1) {
        p = arg0->unk_28;
        v = arg0->unk_8;
        v = (v << 8) | *p++;
        arg0->unk_28 = p;
        arg0->unk_8 = v;
        arg0->unk_C += 8;
        arg0->unk_24 -= 1;
    } else if (n == 4) {
        p = arg0->unk_28;
        v = arg0->unk_8;
        v = (v << 8) | *p++;
        v = (v << 8) | *p++;
        v = (v << 8) | *p++;
        v = (v << 8) | *p++;
        arg0->unk_28 = p;
        arg0->unk_8 = v;
        arg0->unk_C += 32;
        arg0->unk_24 -= 4;
    }
    }
}
