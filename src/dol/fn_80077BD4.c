#include "types.h"

extern u32 fn_80072404(u32, s32);

typedef struct Elem {
    u8 pad0[0x13];
    u8 flags;             /* 0x13 */
    u8 pad1[0x1C - 0x14];
    u32 handle;           /* 0x1C */
    u8 pad2[0x28 - 0x20];
    u32 size[2];          /* 0x28, 0x2C */
    u8 pad3[0x60 - 0x30];
} Elem;

typedef struct Tail {
    u8 pad0[0x8];
    u32 a;                /* 0x08 */
    u32 b;                /* 0x0C */
    u8 pad1[0x20 - 0x10];
} Tail;

typedef struct Obj {
    u8 pad0[0x4];
    u32 flags;            /* 0x04 */
    u8 pad1[0x1A - 0x8];
    u16 count0;           /* 0x1A */
    u16 count1;           /* 0x1C */
    u8 pad2[0x20 - 0x1E];
    u32 elemOffset;       /* 0x20 */
} Obj;

typedef struct Mgr {
    u32 count;            /* 0x00 */
    u32 pad;
    u8 *slots;            /* 0x08: 8-byte entries, Obj * first */
} Mgr;

static inline u32 fn_80077BD4_inl(Obj *obj, u32 initial_sum) {
    Elem *e;
    u32 j;
    u32 sum = initial_sum;
    u32 v;
    u32 k;
    u8 *p;

    e = (Elem *)((u8 *)obj + obj->elemOffset);
    for (j = sum; j < (u32)(obj->count0 + obj->count1); j++) {
        v = fn_80072404(e->handle, 0);
        if (obj->flags & 0x18) {
            if (e->size[0]) {
                sum += v * e->size[0];
            }
            if (e->size[1]) {
                sum += v * e->size[1];
            }
            e++;
        } else {
            if (e->size[0]) {
                sum += e->size[0] / v;
            }
            if (e->size[1]) {
                sum += e->size[1] / v;
            }
            p = (u8 *)(e + 1);
            for (k = 0; k < 2; k++) {
                if (e->flags & (1 << k)) {
                    p += e->size[k];
                }
            }
            if (e->flags & 0xC) {
                Tail *t = (Tail *)p;
                p = (u8 *)(t + 1);
                p += t->a;
                p += t->b;
            }
            e = (Elem *)p;
        }
    }
    return sum;
}

u32 fn_80077BD4(Mgr *mgr) {
    u32 off;
    u32 i;
    u32 total;
    Obj *obj;

    total = 0;
    i = 0;
    off = 0;
    for (; i < mgr->count; off += 8, i++) {
        obj = *(Obj **)(mgr->slots + off);
        if (obj == NULL) {
            continue;
        }
        total += fn_80077BD4_inl(obj, 0);
    }
    return total;
}
