#include "types.h"

/* MSL alloc.c: Block_construct with SubBlock helpers inlined. */

typedef struct Block {
    struct Block *prev;
    struct Block *next;
    u32 max_size;
    u32 size;
} Block;

typedef struct SubBlock {
    u32 size;
    Block *bp;
    struct SubBlock *prev;
    struct SubBlock *next;
} SubBlock;

#define SubBlock_size(ths) ((ths)->size & ~7)
#define Block_size(ths) ((ths)->size & ~7)
#define Block_start(ths) (*(SubBlock **)((char *)(ths) + Block_size(ths) - sizeof(u32)))

static inline void SubBlock_construct(SubBlock *ths, u32 size, Block *bp, int prev_alloc, int this_alloc) {
    ths->bp = (Block *)((u32)bp | 0x1);
    ths->size = size;
    if (prev_alloc) {
        ths->size |= 0x4;
    }
    if (this_alloc) {
        ths->size |= 0x2;
    } else {
        *(u32 *)((char *)ths + size - sizeof(u32)) = size;
    }
}

static inline void SubBlock_set_free(SubBlock *ths) {
    u32 this_size = SubBlock_size(ths);
    ths->size &= ~0x2;
    *(u32 *)((char *)ths + this_size) &= ~0x4;
    *(u32 *)((char *)ths + this_size - sizeof(u32)) = this_size;
}

/* A macro in MSL: the size expression is evaluated at each use. */
#define SubBlock_set_size(ths, sz)                                   \
    do {                                                             \
        (ths)->size &= 7;                                            \
        (ths)->size |= (sz) & ~7;                                    \
        if (!((ths)->size & 0x2)) {                                  \
            *(u32 *)((char *)(ths) + (sz) - sizeof(u32)) = (sz);     \
        }                                                            \
    } while (0)

static inline SubBlock *SubBlock_merge_prev(SubBlock *ths, SubBlock **start) {
    u32 prevsz;
    SubBlock *p;

    if (!(ths->size & 0x4)) {
        prevsz = *(u32 *)((char *)ths - sizeof(u32));
        if (prevsz & 0x2) {
            return ths;
        }
        p = (SubBlock *)((char *)ths - prevsz);
        SubBlock_set_size(p, prevsz + SubBlock_size(ths));
        if (*start == ths) {
            *start = (*start)->next;
        }
        ths->next->prev = ths->prev;
        ths->next->prev->next = ths->next;
        return p;
    }
    return ths;
}

static inline void SubBlock_merge_next(SubBlock *ths, SubBlock **start) {
    SubBlock *next_sub;
    u32 this_size;

    next_sub = (SubBlock *)((char *)ths + SubBlock_size(ths));
    if (!(next_sub->size & 0x2)) {
        this_size = SubBlock_size(ths) + SubBlock_size(next_sub);
        SubBlock_set_size(ths, this_size);
        if (!(ths->size & 0x2)) {
            *(u32 *)((char *)ths + this_size) &= ~0x4;
        } else {
            *(u32 *)((char *)ths + this_size) |= 0x4;
        }
        if (*start == next_sub) {
            *start = (*start)->next;
        }
        if (*start == next_sub) {
            *start = 0;
        }
        next_sub->next->prev = next_sub->prev;
        next_sub->prev->next = next_sub->next;
    }
}

static inline void Block_link(Block *ths, SubBlock *sb) {
    SubBlock **st;

    SubBlock_set_free(sb);
    st = &Block_start(ths);
    if (*st != 0) {
        sb->prev = (*st)->prev;
        sb->prev->next = sb;
        sb->next = *st;
        (*st)->prev = sb;
        *st = sb;
        *st = SubBlock_merge_prev(*st, st);
        SubBlock_merge_next(*st, st);
    } else {
        *st = sb;
        sb->prev = sb;
        sb->next = sb;
    }
    if (ths->max_size < SubBlock_size(*st)) {
        ths->max_size = SubBlock_size(*st);
    }
}

void fn_8007ADF0(Block *ths, u32 size) {
    SubBlock *sb;

    ths->size = size | 3;
    *(u32 *)((char *)ths + size - 2 * sizeof(u32)) = ths->size;
    sb = (SubBlock *)((char *)ths + sizeof(Block));
    SubBlock_construct(sb, size - sizeof(Block) - 2 * sizeof(u32), ths, 0, 0);
    ths->max_size = size - sizeof(Block) - 2 * sizeof(u32);
    Block_start(ths) = 0;
    Block_link(ths, sb);
}
