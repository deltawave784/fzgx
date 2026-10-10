#include "types.h"

/* JPEG DHT (define Huffman table) segment parser. */
struct fn_8003A1CC_Huff {
    u8 *bits;
    s8 *huffsize;
    u8 pad8[0x4];
    u16 count;
    u8 padE[0x2];
    u8 *huffval;
    u8 pad14[0x94];
};

struct fn_8003A1CC_Dec {
    u8 pad0[0x400];
    u8 *ptr;
    u8 pad404[0x14];
    u8 tables;
    u8 pad419[0x7];
    struct fn_8003A1CC_Huff huff[4];
};

extern u8 fn_8003A4E8(struct fn_8003A1CC_Dec *, u8, u8 *);
extern u8 fn_8003A680(struct fn_8003A1CC_Dec *, u8);
extern u8 fn_8003A760(struct fn_8003A1CC_Dec *, u8);

u8 fn_8003A1CC(struct fn_8003A1CC_Dec *d) {
    u8 idx;
    u16 len;
    u16 count;
    u8 tc;
    u8 th;
    u8 b;
    u8 i;
    u8 *bits;
    u8 r;

    len = (d->ptr[0] << 8) | d->ptr[1];
    d->ptr += 2;
    len -= 2;
    do {
        b = *d->ptr++;
        bits = d->ptr;
        tc = b >> 4;
        th = b & 15;
        if (tc > 1 || th >= 2) {
            return 7;
        }
        idx = (th << 1) + tc;
        count = 0;
        for (i = 0; i < 16; i++) {
            count += *d->ptr++;
        }
        d->huff[idx].bits = bits;
        d->huff[idx].huffval = d->ptr;
        d->huff[idx].count = count;
        for (i = 0; i < count; i++) {
            d->ptr++;
        }
        r = fn_8003A4E8(d, idx, bits);
        if (r) {
            return r;
        }
        r = fn_8003A680(d, idx);
        if (r) {
            return r;
        }
        fn_8003A760(d, idx);
        len -= count + 17;
        d->tables |= 1 << idx;
    } while (len);
    return 0;
}
