#include "types.h"

typedef struct MovieHeap {
    u8 pad00[0x28];
    void *(*alloc)(void *heap, s32 size);
    u8 pad2C[0x4];
    void *heap;
} MovieHeap;

typedef struct MoviePlayer {
    u8 pad000[0x158];
    u32 work_base;
    u32 work_limit;
    u32 work_cur;
    u32 work_used;
    s32 buffer_count;
    void *buffers[32];
} MoviePlayer;

typedef struct MovieInfo {
    u8 pad00[0x8];
    s32 width;
    s32 height;
} MovieInfo;

extern char lbl_12_rodata_1DF4[33];
extern void MWSFSVM_Error(const char *, ...);
extern MovieHeap *fn_12_38DBC(void);

/* Inlined at both call sites in retail; must not be emitted out of line. */
static inline void *allocFrameBuffer(MoviePlayer *player, s32 size) {
    void *buf;

    if (player->buffer_count >= 32) {
        MWSFSVM_Error(lbl_12_rodata_1DF4);
        return NULL;
    }
    if (size < 0) {
        return NULL;
    }
    if (player->work_base != 0) {
        if (player->work_used + size > player->work_limit) {
            buf = NULL;
        } else {
            buf = (void *)player->work_cur;
            player->work_cur += size;
            player->work_used += size;
        }
    } else {
        MovieHeap *heap = fn_12_38DBC();
        buf = heap->alloc(heap->heap, size);
    }
    if (buf != NULL) {
        player->buffers[player->buffer_count] = buf;
        player->buffer_count++;
    }
    return buf;
}

s32 fn_12_38340(MoviePlayer *player, MovieInfo *info, void **out) {
    s32 size;
    s32 result = 0;
    s32 w16;
    s32 h16;
    s32 w8;
    s32 h8;

    /* YUV420 frame: luma plane plus two half-size chroma planes, 32-byte rows. */
    w16 = ((info->width + 15) / 16) * 16;
    h16 = ((info->height + 15) / 16) * 16;
    w8 = w16 / 2;
    h8 = h16 / 2;
    size = h16 * (((w16 + 31) / 32) * 32) + (h8 * (((w8 + 31) / 32) * 32)) * 2 + 32;

    out[0] = allocFrameBuffer(player, size);
    out[1] = allocFrameBuffer(player, size);
    if (out[0] == NULL || out[1] == NULL) {
        result = -1;
    }
    return result;
}
