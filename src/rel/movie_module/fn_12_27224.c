#include "types.h"

typedef struct MovieInfo {
    s32 width;
    s32 height;
    u8 pad08[0x10];
    s32 type;
    u8 pad1c[0x34];
} MovieInfo;

typedef struct MovieEntry {
    u32 used;
    u8 *data;
    u8 pad08[0x20];
    MovieInfo info;
} MovieEntry;

typedef struct MoviePlanes {
    u8 *u;
    u8 *v;
    u8 *y;
    s16 chroma_stride;
    s16 luma_stride;
} MoviePlanes;

typedef struct MovieList {
    u8 pad00[0x100];
    u32 index0;
    u32 index1;
    MoviePlanes planes[2];
    MovieEntry *previous;
    MovieEntry *current;
    MovieEntry *pending;
} MovieList;

typedef struct MovieObject {
    u8 pad00[0x38];
    s32 mode;
    u8 pad3c[0x934];
    s32 failed;
    u8 pad974[0x11bc];
    MovieList *list;
} MovieObject;

typedef struct MovieOutput {
    MoviePlanes planes[2];
    u8 *data;
    MovieInfo *info;
    u32 field28;
    u32 field2c;
} MovieOutput;

extern MovieEntry *fn_12_2AB68(MovieObject *);
extern u32 fn_12_2AAD4(MovieEntry *);

s32 fn_12_27224(MovieObject *movie, MovieInfo *info, MovieOutput *out, MovieEntry **entry) {
    MovieList *list;
    u32 luma_size;
    struct { s32 luma; s32 chroma; } strides;
    u32 chroma_size;
    s32 height;
    s32 rounded_height;
    s32 width;
    s32 chroma_height;
    MoviePlanes *planes;

    list = movie->list;
    if (list->pending != 0) {
        *entry = list->pending;
    } else {
        *entry = fn_12_2AB68(movie);
        if (*entry == 0) {
            movie->failed = 1;
            return -1;
        }
    }
    (*entry)->info = *info;
    if (movie->mode == 3) {
        if ((info->type == 1 || info->type == 2) && list->pending == 0) {
            fn_12_2AAD4(list->previous);
            list->previous = list->current;
            list->current = *entry;
        }
        width = info->width;
        height = info->height;
        width = ((width + 15) / 16) * 16;
        strides.luma = ((width + 31) / 32) << 5;
        strides.chroma = ((width / 2 + 31) / 32) << 5;
        out->planes[0].luma_stride = strides.luma;
        out->planes[0].chroma_stride = strides.chroma;
        rounded_height = ((height + 15) / 16) * 16;
        chroma_height = rounded_height / 2;
        out->planes[0].y = list->previous->data;
        out->planes[0].u = out->planes[0].y + rounded_height * strides.luma;
        out->planes[0].v = out->planes[0].u + chroma_height * strides.chroma;
        out->planes[1].luma_stride = strides.luma;
        out->planes[1].chroma_stride = strides.chroma;
        out->planes[1].y = list->current->data;
        out->planes[1].u = out->planes[1].y + rounded_height * strides.luma;
        out->planes[1].v = out->planes[1].u + chroma_height * strides.chroma;
    } else {
        if (info->type == 1 || info->type == 2) {
            list->index0 ^= 1;
            list->index1 ^= 1;
        }
        planes = list->planes;
        out->planes[0] = *(MoviePlanes *)((u32)planes + (list->index0 << 4));
        out->planes[1] = *(MoviePlanes *)((u32)planes + (list->index1 << 4));
    }
    out->data = (*entry)->data;
    out->info = &(*entry)->info;
    out->field28 = 0;
    out->field2c = 0;
    movie->failed = 0;
    return 0;
}
