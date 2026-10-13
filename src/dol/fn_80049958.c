#include "types.h"

typedef struct fn_80049958_Buf {
    void *data;
    u32 size;
} fn_80049958_Buf;

typedef struct fn_80049958_Vtbl {
    u8 pad_0[0x18];
    void (*unk18)(void *, s32, s32, fn_80049958_Buf *);
    void (*unk1C)(void *, s32, fn_80049958_Buf *);
    void (*unk20)(void *, s32, fn_80049958_Buf *);
    u32 (*unk24)(void *, s32);
} fn_80049958_Vtbl;

typedef struct fn_80049958_Obj {
    fn_80049958_Vtbl *vtbl;
} fn_80049958_Obj;

typedef struct fn_80049958_Inner {
    u8 pad_0[0x8];
    s16 unk8;
    s16 unkA;
} fn_80049958_Inner;

typedef struct fn_80049958_Chan {
    u8 pad_0[0x7C];
    s16 unk7C;
    u8 pad_7E[0x2];
    f64 unk80;
    fn_80049958_Inner *unk88;
} fn_80049958_Chan;

typedef struct fn_80049958_Stream {
    u8 pad_0[0x4];
    fn_80049958_Obj *objs[2];
    fn_80049958_Obj *unk_C;
    u8 pad_10[0x20];
    s32 pos;
    u8 pad_34[0x8];
    s32 end;
    u8 pad_40[0x4];
    s32 chunk;
    u8 pad_48[0x10];
    s32 count;
    u8 pad_5C[0x24];
    fn_80049958_Chan *chans[2];
    s16 unk88[2];
    s16 unk8C[2];
    s16 buf0[0x20];
    s16 buf1[0xE0];
    s16 unk290[4];
    f64 unk298[2];
} fn_80049958_Stream;

extern void *memcpy(void *, const void *, u32);
extern void *memset(void *, int, u32);
extern void fn_8004A068(fn_80049958_Stream *, s32);
extern void fn_80049E34(fn_80049958_Stream *, s32);
extern s32 fn_80049BF4(fn_80049958_Stream *);

/* Zero-fills the tail of every channel buffer past `len` samples. */
static inline void fn_80049958_pad(fn_80049958_Stream *arg0, s16 **bufs, s32 len) {
    s32 i;

    for (i = 0; i < arg0->count; i++) {
        if (bufs[i] != NULL) {
            memset(bufs[i] + len, 0, (arg0->chunk - len) * 2);
        }
    }
}

/* Advances every channel and latches its state. */
static inline void fn_80049958_update(fn_80049958_Stream *arg0) {
    s32 i;
    s16 y;
    fn_80049958_Chan *c;
    fn_80049958_Inner *in;

    for (i = 0; i < arg0->count; i++) {
        fn_8004A068(arg0, i);
        c = arg0->chans[i];
        in = c->unk88;
        arg0->unk290[i] = c->unk7C;
        arg0->unk298[i] = c->unk80;
        y = in->unkA;
        arg0->unk88[i] = in->unk8;
        arg0->unk8C[i] = y;
        fn_80049E34(arg0, i);
    }
}

/* Decodes one chunk from every channel; returns the chunk size, or 0 when a
   channel is short of data. */
static inline s32 fn_80049958_decode(fn_80049958_Stream *arg0) {
    s32 len = 0;
    fn_80049958_Obj **objs;
    s32 k;
    s32 i;
    fn_80049958_Buf b;
    s16 *bufs[2];

    len = arg0->end - arg0->pos;
    bufs[0] = arg0->buf0;
    bufs[1] = arg0->buf1;
    objs = arg0->objs;
    if (arg0->chunk < len) {
        len = arg0->chunk;
    }
    k = 0;
    for (i = 0; i < arg0->count; i++) {
        k = objs[i]->vtbl->unk24(objs[i], 1) >> 1;
        if (k < len) {
            k = 0;
            goto copied; /* short channel: skip the copy, report 0 */
        }
    }
    for (i = 0; i < arg0->count; i++) {
        for (k = 0; k < len; ) {
            objs[i]->vtbl->unk18(objs[i], 1, len * 2, &b);
            memcpy(bufs[i] + k, b.data, b.size);
            k += (s16)(b.size >> 1);
            objs[i]->vtbl->unk20(objs[i], 0, &b);
        }
    }
copied:
    if (k == 0) {
        return 0;
    }
    if (len < arg0->chunk) {
        fn_80049958_pad(arg0, bufs, len);
    }
    arg0->pos += arg0->chunk;
    fn_80049958_update(arg0);
    return arg0->chunk;
}

#pragma opt_dead_assignments off
s32 fn_80049958(fn_80049958_Stream *arg0) {
    s32 total = 0;
    fn_80049958_Obj *obj = arg0->unk_C;

    do {
        if ((s32)obj->vtbl->unk24(obj, 0) / 18 / arg0->count <= 0) {
            break;
        }
        if (fn_80049958_decode(arg0) == 0) {
            break;
        }
        total += fn_80049BF4(arg0);
    } while (arg0->pos < arg0->end);
    return total;
}
#pragma opt_dead_assignments reset
