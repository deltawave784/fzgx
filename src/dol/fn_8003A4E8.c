#include "types.h"

/* JPEG Huffman table: code-length (huffsize) list built from the BITS counts. */
struct fn_8003A4E8_Huff {
    u8 *bits;
    s8 *huffsize;
    u8 pad8[0x9C];
    s32 lastk;
};

struct fn_8003A4E8_Dec {
    u8 pad0[0x420];
    struct fn_8003A4E8_Huff huff[4];
    u8 pad6C0[0xF4];
    u8 *data;
};

s32 fn_8003A4E8(struct fn_8003A4E8_Dec *d, u8 n, u8 *bits) {
    s32 i;
    s32 k;
    s32 count;
    s32 c;

    count = 0;
    for (k = 1; k <= 16; k++) {
        count += bits[k - 1];
    }
    d->huff[n].huffsize = (s8 *)d->data;
    d->data += count + 1;
    k = 0;
    for (i = 1; i <= 16; i++) {
        c = bits[i - 1];
        while (c--) {
            d->huff[n].huffsize[k] = (s8)i;
            k++;
        }
    }
    d->huff[n].huffsize[k] = 0;
    d->huff[n].lastk = k;
    return 0;
}
