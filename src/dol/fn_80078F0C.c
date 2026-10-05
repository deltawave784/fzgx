#include "types.h"

extern char lbl_8015AD38[];
extern void OSReport(const char *, ...);
extern void OSPanic(const char *, int, const char *, ...);
extern void *fn_80071794(u32 size);

typedef struct fn_80078F0C_Child {
    u32 flags;      /* 0x00 */
    u16 index;      /* 0x04 */
    u16 pad06;
    u32 value;      /* 0x08 */
    u8 pad0C[0x14];
} fn_80078F0C_Child; /* 0x20 */

typedef struct fn_80078F0C_Obj {
    u8 pad00[4];
    u32 flags;      /* 0x04 */
    u8 pad08[0x10];
    u16 count;      /* 0x18 */
    u16 count2;     /* 0x1A */
    u16 count3;     /* 0x1C */
    u8 pad1E[2];
    u32 offset;     /* 0x20 */
    void *data;     /* 0x24 */
    u8 pad28[0x18];
    fn_80078F0C_Child children[1]; /* 0x40 */
} fn_80078F0C_Obj;

typedef struct fn_80078F0C_Entry {
    u32 flags;      /* 0x00 */
    u32 pad04;
    u32 size08;     /* 0x08 */
    u32 size0C;     /* 0x0C */
    u8 pad10[2];
    u8 b12;         /* 0x12 */
    u8 b13;         /* 0x13 */
    u8 pad14[8];
    u32 flags1C;    /* 0x1C */
    u8 pad20[8];
    u32 sizes[2];   /* 0x28, 0x2C */
    u8 pad30[0x30];
} fn_80078F0C_Entry; /* 0x60 */

extern void fn_80071C04(fn_80078F0C_Child *, void *);

u8 *fn_80078F0C(fn_80078F0C_Obj *obj, void *arg1, u8 *buf, const char *name) {
    /* one-member struct: keeps the string table base in a single register */
    struct { char *value; } strs;
    s32 reset;
    fn_80078F0C_Child *child;
    s32 i;
    fn_80078F0C_Child *c;
    fn_80078F0C_Entry *p;
    fn_80078F0C_Entry *q;
    fn_80078F0C_Entry *hdr;
    u8 *next;
    u32 flags;
    u32 a;
    u32 b;
    s32 count;
    s32 n;
    s32 k;

    strs.value = lbl_8015AD38;
    child = obj->children;
    reset = 0;
    if (arg1 == NULL) {
        count = obj->count;
        n = 0;
        c = child;
        for (i = 0; i < count; i++, c++) {
            if (c->flags & 0x200000) {
                n++;
            }
        }
        if (n != count) {
            reset = 1;
            obj->count = 0;
        }
    }

    if (obj->count != 0) {
        if (buf != NULL) {
            obj->data = buf;
            buf += obj->count << 5;
        } else {
            obj->data = fn_80071794(obj->count << 5);
        }
        if (obj->data == NULL) {
            OSReport(strs.value + 0xA4, name);
            OSPanic(strs.value + 0xB0, 0x96B, strs.value + 0xBC);
        }
    } else {
        obj->data = NULL;
    }

    i = 0;
    while (i < obj->count) {
        child[i].value = (u32)obj->data + i * 0x20;
        fn_80071C04(&child[i], arg1);
        if (!(child[i].flags & 0x200000) && child[i].value == 0) {
            OSReport(strs.value + 0xD8, name, child[i].index);
        }
        i++;
    }

    flags = obj->flags;
    p = (fn_80078F0C_Entry *)((u8 *)obj + obj->offset);
    if (flags & 0x18) {
        p->flags1C = flags;
        p = (fn_80078F0C_Entry *)((u8 *)p + 0x20);
    }
    for (i = 0; i < obj->count2 + obj->count3; i++) {
        if (reset) {
            p->b12 = 0;
        }
        if (obj->flags & 0x18) {
            q = p;
            p = (fn_80078F0C_Entry *)((u8 *)p + 0x60);
            if (q->flags1C & 0x800) {
                q->flags |= 0x100;
            }
            if (q->b12 == 0) {
                q->flags |= 0x80;
            }
        } else {
            if (p->flags1C & 0x800) {
                p->flags |= 0x100;
            }
            if (p->b12 == 0) {
                p->flags |= 0x80;
            }
            next = (u8 *)p + 0x60;
            for (k = 0; k < 2; k++) {
                if (p->b13 & (1 << k)) {
                    next += p->sizes[k];
                }
            }
            if (p->b13 & 0xC) {
                hdr = (fn_80078F0C_Entry *)next;
                a = hdr->size08;
                b = hdr->size0C;
                next += 0x20;
                next += a;
                next += b;
            }
            p = (fn_80078F0C_Entry *)next;
        }
    }
    return buf;
}
