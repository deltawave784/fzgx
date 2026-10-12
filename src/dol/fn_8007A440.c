#include "types.h"

/* MSL alloc.c: allocate_from_fixed_pools */

typedef struct Block Block;
typedef struct FixBlock FixBlock;
typedef struct FixSubBlock FixSubBlock;

struct Block {
    Block *prev;
    Block *next;
    unsigned long max_size;
    unsigned long size;
};

struct FixBlock {
    FixBlock *prev;
    FixBlock *next;
    unsigned long client_size;
    FixSubBlock *free;
    unsigned long allocated;
};

struct FixSubBlock {
    FixBlock *block;
    FixSubBlock *next;
};

typedef struct FixStart {
    FixBlock *tail;
    FixBlock *head;
} FixStart;

typedef struct MemPoolObj {
    Block *start;
    FixStart fixed[6];
} MemPoolObj;

extern const unsigned long lbl_80094EC0[];

void *fn_8007A9A4(MemPoolObj *pool, unsigned long size, unsigned long *size_received);
void *fn_8007AA7C(MemPoolObj *pool, unsigned long size);

static inline void FixSubBlock_construct(void *ths, FixBlock *block, FixSubBlock *next) {
    ((FixSubBlock *)ths)->block = block;
    ((FixSubBlock *)ths)->next = next;
}

static inline void FixBlock_construct(FixBlock *ths, FixBlock *prev, FixBlock *next, unsigned long index,
                                      void *chunk, unsigned long chunk_size) {
    unsigned long fixSubBlock_size;
    unsigned long n;
    char *p;
    unsigned long i;
    char *np;

    ths->prev = prev;
    ths->next = next;
    prev->next = ths;
    next->prev = ths;
    ths->client_size = lbl_80094EC0[index];
    fixSubBlock_size = lbl_80094EC0[index] + sizeof(FixBlock *);
    n = chunk_size / fixSubBlock_size;
    p = (char *)chunk;
    for (i = 0; i < n - 1; ++i) {
        np = p + fixSubBlock_size;
        FixSubBlock_construct(p, ths, (FixSubBlock *)np);
        p = np;
    }
    FixSubBlock_construct(p, ths, 0);
    ths->free = (FixSubBlock *)((char *)ths + sizeof(FixBlock));
    ths->allocated = 0;
}

static inline unsigned long msize_inline(const void *ptr) {
    return !((unsigned long)((FixSubBlock *)((char *)ptr - 4))->block & 1)
               ? ((FixSubBlock *)((char *)ptr - 4))->block->client_size
               : (*(unsigned long *)((char *)ptr - 8) & ~7) - 8;
}

void *fn_8007A440(MemPoolObj *pool, unsigned long size) {
    unsigned long i = 0;
    FixSubBlock *p;
    FixStart *fs;

    while (size > lbl_80094EC0[i]) {
        ++i;
    }
    fs = &pool->fixed[i];
    if (fs->head == 0 || fs->head->free == 0) {
        unsigned long size_requested = 4096 - sizeof(FixBlock);
        unsigned long n = size_requested / (lbl_80094EC0[i] + sizeof(FixBlock *));
        unsigned long nsave;
        void *newblock;
        unsigned long size_received;
        unsigned long size_has;
        if (n > 256) {
            n = 256;
        }
        nsave = n;
        while (n >= 10) {
            newblock = fn_8007A9A4(pool, n * (lbl_80094EC0[i] + sizeof(FixBlock *)) + sizeof(FixBlock),
                                   &size_received);
            if (newblock != 0) {
                break;
            }
            if (size_received > sizeof(FixBlock)) {
                n = (size_received - sizeof(FixBlock)) / (lbl_80094EC0[i] + sizeof(FixBlock *));
            } else {
                n = 0;
            }
        }
        if (newblock == 0 && n < nsave) {
            newblock = fn_8007AA7C(pool, nsave * (lbl_80094EC0[i] + sizeof(FixBlock *)) + sizeof(FixBlock));
            if (newblock == 0) {
                return 0;
            }
        }
        size_has = msize_inline(newblock);
        if (fs->head == 0) {
            fs->head = (FixBlock *)newblock;
            fs->tail = (FixBlock *)newblock;
        }
        FixBlock_construct((FixBlock *)newblock, fs->tail, fs->head, i, (FixBlock *)newblock + 1,
                           size_has - sizeof(FixBlock));
        fs->head = (FixBlock *)newblock;
    }
    p = fs->head->free;
    fs->head->free = p->next;
    ++fs->head->allocated;
    if (fs->head->free == 0) {
        fs->head = fs->head->next;
        fs->tail = fs->tail->next;
    }
    return (char *)p + 4;
}
