#include "types.h"

extern u32 lbl_801A6730;
extern u32 lbl_8015BE40[40];
extern u32 lbl_8015BEE0[8];
extern u32 lbl_801A6410;
extern u32 lbl_801A6744;
extern u32 lbl_801A6740;
extern u32 lbl_801A673C;
extern u32 lbl_801A6738;

typedef struct Cell {
    struct Cell *prev;
    struct Cell *next;
    s32 size;
} Cell;

typedef struct HeapDesc {
    s32 size;
    Cell *free;
    Cell *allocated;
} HeapDesc;

/* Swap the active heap context in (same body as fn_8000951C). */
static inline void HeapContextEnter(void) {
    if ((s32)lbl_801A6730 != -1) {
        lbl_8015BEE0[0] = lbl_801A6410;
        lbl_8015BEE0[1] = lbl_801A6744;
        lbl_8015BEE0[2] = lbl_801A6740;
        lbl_8015BEE0[3] = lbl_801A673C;
        lbl_8015BEE0[4] = lbl_801A6738;
        lbl_801A6410 = lbl_8015BE40[lbl_801A6730 * 5];
        lbl_801A6744 = lbl_8015BE40[lbl_801A6730 * 5 + 1];
        lbl_801A6740 = lbl_8015BE40[lbl_801A6730 * 5 + 2];
        lbl_801A673C = lbl_8015BE40[lbl_801A6730 * 5 + 3];
        lbl_801A6738 = lbl_8015BE40[lbl_801A6730 * 5 + 4];
    }
}

/* Swap it back out (same body as fn_800095A4). */
static inline void HeapContextLeave(void) {
    if ((s32)lbl_801A6730 != -1) {
        lbl_8015BE40[lbl_801A6730 * 5] = lbl_801A6410;
        lbl_8015BE40[lbl_801A6730 * 5 + 1] = lbl_801A6744;
        lbl_8015BE40[lbl_801A6730 * 5 + 2] = lbl_801A6740;
        lbl_8015BE40[lbl_801A6730 * 5 + 3] = lbl_801A673C;
        lbl_8015BE40[lbl_801A6730 * 5 + 4] = lbl_801A6738;
        lbl_801A6410 = lbl_8015BEE0[0];
        lbl_801A6744 = lbl_8015BEE0[1];
        lbl_801A6740 = lbl_8015BEE0[2];
        lbl_801A673C = lbl_8015BEE0[3];
        lbl_801A6738 = lbl_8015BEE0[4];
    }
}

static inline Cell *DLAddFront(Cell *list, Cell *cell) {
    cell->next = list;
    cell->prev = NULL;
    if (list != NULL) {
        list->prev = cell;
    }
    return cell;
}

static inline Cell *DLExtract(Cell *list, Cell *cell) {
    if (cell->next != NULL) {
        cell->next->prev = cell->prev;
    }
    if (cell->prev == NULL) {
        list = cell->next;
    } else {
        cell->prev->next = cell->next;
    }
    return list;
}

/* Header plus 32-byte rounding; kept as an expression so the compiler CSEs it. */
#define ROUNDED_SIZE ((size + 0x20 + 0x1F) & ~0x1F)

void *fn_80009830(s32 heap, u32 size) {
    HeapDesc *hd;
    Cell *cell;
    Cell *newCell;
    u32 leftoverSize;
    Cell *list;

    HeapContextEnter();
    hd = &((HeapDesc *)lbl_801A6744)[heap];

    list = hd->free;
    for (cell = list; cell != NULL; cell = cell->next) {
        if ((s32)ROUNDED_SIZE <= cell->size) {
            break;
        }
    }

    if (cell == NULL) {
        HeapContextLeave();
        return NULL;
    }

    leftoverSize = cell->size - ROUNDED_SIZE;
    if (leftoverSize < 0x40) {
        hd->free = DLExtract(hd->free, cell);
    } else {
        cell->size = ROUNDED_SIZE;
        newCell = (Cell *)((u8 *)cell + ROUNDED_SIZE);
        newCell->size = leftoverSize;
        newCell->prev = cell->prev;
        newCell->next = cell->next;
        if (newCell->next != NULL) {
            newCell->next->prev = newCell;
        }
        if (newCell->prev != NULL) {
            newCell->prev->next = newCell;
        } else {
            hd->free = newCell;
        }
    }

    hd->allocated = DLAddFront(hd->allocated, cell);
    HeapContextLeave();
    return (u8 *)cell + 0x20;
}
