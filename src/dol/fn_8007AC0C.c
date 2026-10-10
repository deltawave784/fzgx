#include "types.h"

typedef struct Chunk {
    u32 hdr;
    u32 unk4;
    struct Chunk *prev;
    struct Chunk *next;
} Chunk;

typedef struct Heap {
    u8 pad_0[0x8];
    u32 maxFree;
    u32 size;
} Heap;

/* free-list head lives in the last word of the heap */
#define HEAD_OFS(h) (((h)->size & ~7) - 4)
#define AT(base, off, T) (*(T *)((u8 *)(base) + (off)))

#define SET_CHUNK(c, sz, prevFlag, lastFlag)      \
    do {                                          \
        (c)->hdr = (sz);                          \
        if (prevFlag) {                           \
            (c)->hdr |= 4;                        \
        }                                         \
        if (lastFlag) {                           \
            (c)->hdr |= 2;                        \
            AT(c, sz, u32) |= 4;                  \
        } else {                                  \
            *(u32 *)((u8 *)(c) + (sz) - 4) = (sz); \
        }                                         \
    } while (0)

#pragma opt_propagation off

Chunk *fn_8007AC0C(Heap *heap, u32 size) {
    struct Chunk * fzgx_live;
    Chunk *cur;
    Chunk *head;
    Chunk *rest;
    u32 sz;
    u32 max;
    u32 hdr;
    u32 attr;
    u32 prev;
    u32 ofs;
    struct { u32 value; } restSize;
    struct { u32 value; } total;
    Chunk * cur_2;
    int linked;
    int last;

    ofs = HEAD_OFS(heap);
    cur = AT(heap, ofs, Chunk *);
    if (cur == 0) {
        heap->maxFree = 0;
        return 0;
    }
    head = cur;
    sz = cur->hdr & ~7;
    (void) sz;  /* fzgx: keeps the web at its definition */
    max = sz;
    cur_2 = cur;
    while (sz < size) {
        cur_2 = cur_2->next;
        sz = cur_2->hdr & ~7;
        if (max < sz) {
            max = sz;
        }
        if (cur_2 == head) {
            heap->maxFree = max;
            return 0;
        }
    }
    if (sz - size >= 0x50) {
        rest = (Chunk *)((u8 *)cur_2 + size);
        hdr = cur_2->hdr;
        linked = !(hdr & 2);
        last = !linked;
        attr = (cur_2->unk4 & ~1) | 1;
        cur_2->unk4 = attr;
        total.value = hdr & ~7;
        SET_CHUNK(cur_2, size, hdr & 4, last);
        rest->unk4 = attr;
        restSize.value = total.value - size;
        SET_CHUNK(rest, restSize.value, last, last);
        if (linked) {
            rest->next = cur_2->next;
            rest->next->prev = rest;
            rest->prev = cur_2;
            cur_2->next = rest;
        }
    }
    ofs = HEAD_OFS(heap);
    fzgx_live = cur_2->next;
    AT(heap, ofs, Chunk *) = fzgx_live;
    hdr = cur_2->hdr;
    cur_2->hdr = hdr | 2;
    AT(cur_2, hdr & ~7, u32) |= 4;
    ofs = HEAD_OFS(heap);
    if (AT(heap, ofs, Chunk *) == cur_2) {
        AT(heap, ofs, Chunk *) = cur_2->next;
    }
    if (AT(heap, ofs, Chunk *) == cur_2) {
        AT(heap, ofs, Chunk *) = 0;
        heap->maxFree = 0;
    } else {
        cur_2->next->prev = cur_2->prev;
        cur_2->prev->next = cur_2->next;
    }
    return cur_2;
}
