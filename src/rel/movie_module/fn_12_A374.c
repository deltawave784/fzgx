#include "types.h"

/* macroblock_address_increment VLC table: (code << 8) | length */
extern s16 lbl_12_data_68[36];

/* Bit window: `cur` holds the current word already shifted left by `bits`,
 * `next` the following unshifted word, `p` the word after that. */
#define PEEK(v, n)                                  \
    v = cur >> (32 - (n));                          \
    if (bits > 32 - (n)) {                          \
        v |= next >> (64 - (n) - bits);             \
    }

#define SKIP(n)                                     \
    bits += (n);                                    \
    if (bits >= 32) {                               \
        bits -= 32;                                 \
        cur = next << bits;                         \
        next = *p++;                                \
    } else {                                        \
        cur <<= (n);                                \
    }

#define GETBIT(v)                                   \
    v = cur >> 31;                                  \
    if (bits == 31) {                               \
        cur = next;                                 \
        next = *p++;                                \
        bits = 0;                                   \
    } else {                                        \
        cur <<= 1;                                  \
        bits++;                                     \
    }

#define GETBITS(v, n)                               \
    shift = 32 - (n);                               \
    if (bits >= shift) {                            \
        bits -= shift;                              \
        if (bits != 0) {                            \
            cur |= next >> ((n) - bits);            \
            v = cur >> shift;                       \
            cur = next << bits;                     \
        } else {                                    \
            v = cur >> shift;                       \
            cur = next;                             \
        }                                           \
        next = *p++;                                \
    } else {                                        \
        v = cur >> shift;                           \
        bits += (n);                                \
        cur <<= (n);                                \
    }

/* Validates the start of an MPEG slice (start code 0x101, quantiser scale,
 * first macroblock header). Returns 1 when the header fits in `len` bytes. */
s32 fn_12_A374(u8 *start, s32 len, s32 count) {
    s32 bits;
    u32 *p;
    u32 cur;
    u32 next;
    s32 mbtype;
    s32 n;
    u32 v;
    u32 entry;
    u32 bit;
    s32 nbits;
    s32 shift;
    u32 w0;
    u32 w1;
    u32 code;
    u8 *end;

    p = (u32 *)((u32)start & ~3);
    bits = (start - (u8 *)p) << 3;
    w0 = p[0];
    w1 = p[1];
    w0 <<= bits;
    if (bits != 0) {
        code = w0 | (w1 >> (32 - bits));
        cur = w1 << bits;
    } else {
        code = w0;
        cur = w1;
    }
    next = p[2];
    p += 3;
    if (code != 0x101) {
        return 0;
    }

    /* quantiser_scale_code: skipped */
    if (bits >= 27) {
        bits -= 27;
        cur = next;
        if (bits != 0) {
            cur <<= bits;
        }
        next = *p++;
    } else {
        cur <<= 5;
        bits += 5;
    }

    GETBIT(bit);
    if (bit != 0) {
        return 0;
    }
    GETBIT(bit);
    if (bit == 0) {
        return 0;
    }

    PEEK(mbtype, 6);
    switch (mbtype) {
    case 0x16:
    case 0x17:
        SKIP(5);
        break;
    case 0xb:
        SKIP(6);
        break;
    default:
        return 0;
    }

    n = count - 1;
    do {
        PEEK(v, 11);
        if (v != 8) {
            break;
        }
        SKIP(11);
        n -= 33;
    } while (n > 33);

    if (n <= 0 || n > 33) {
        return 0;
    }

    entry = lbl_12_data_68[n];
    nbits = entry & 0xff;
    GETBITS(v, nbits);
    if (v != entry >> 8) {
        return 0;
    }

    PEEK(mbtype, 6);
    switch (mbtype) {
    case 0x16:
    case 0x17:
        SKIP(5);
        break;
    case 0xb:
        SKIP(6);
        break;
    default:
        return 0;
    }

    p = (u32 *)((u8 *)p + ((bits + 7) >> 3));
    return (s32)(((u8 *)p - 8) - start) <= len;
}
