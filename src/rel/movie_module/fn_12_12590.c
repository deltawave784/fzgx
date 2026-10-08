#include "types.h"

typedef struct MovieImage {
    u8 pad0[0x1d0];
    s32 width;
    s32 height;
    u8 pad1[0x254 - 0x1d8];
    u8 *buffer;
    u8 pad2[0x264 - 0x258];
    u8 *planeU;
    u8 *planeV;
    u8 *planeY;
    s16 chromaStride;
    s16 lumaStride;
} MovieImage;

void fn_12_12590(MovieImage *image) {
    s32 width = (image->width + 15) / 16 * 16;
    s32 height = image->height;
    u8 *buffer = image->buffer;
    s32 lumaStride = ((width + 31) / 32) << 5;
    width = ((width / 2 + 31) / 32) << 5;
    height = ((height + 15) / 16) * 16;
    image->lumaStride = lumaStride;
    image->chromaStride = width;
    image->planeY = buffer;
    image->planeU = image->planeY + height * lumaStride;
    image->planeV = image->planeU + (height / 2) * width;
}
