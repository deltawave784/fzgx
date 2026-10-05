#include "types.h"

typedef struct MovieQueueItem {
    s32 a;
    s32 b;
    s32 c;
} MovieQueueItem;

typedef struct MovieQueue {
    u8 pad_0[0x1178];
    MovieQueueItem *buf;
    s32 cap;
    s32 count;
    s32 head;
} MovieQueue;

extern s32 fn_12_24A88(void *, s32);

/* queue idx of the movie object: a 0x74-byte stride */
#define Q(base, idx) ((MovieQueue *)((u8 *)(base) + (idx) * 0x74))

s32 fn_12_2CF20(void *base, s32 idx, MovieQueueItem *item) {
    s32 a;
    s32 wrapped;
    s32 h;
    MovieQueueItem *buf;
    s32 r;

    a = item->a;
    if (a < 0) {
        return 0;
    }
    buf = Q(base, idx)->buf;
    if (buf == NULL) {
        return 0;
    }
    if (Q(base, idx)->count == Q(base, idx)->cap) {
        r = -1;
    } else {
        h = Q(base, idx)->head;
        buf[h] = *item;
        wrapped = h + 1 - Q(base, idx)->cap;
        if (h + 1 < Q(base, idx)->cap) {
            wrapped = h + 1;
        }
        Q(base, idx)->count++;
        Q(base, idx)->head = wrapped;
        r = 0;
    }
    if (r == -1) {
        return fn_12_24A88(base, 0xFF000421);
    }
    return 0;
}
