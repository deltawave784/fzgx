#include "types.h"

#define READ_BITS(value, n) \
    if (bits >= 32-(n)) { \
        bits -= 32-(n); \
        if (bits != 0) { \
            current |= next >> ((n)-bits); \
            value = current >> (32-(n)); \
            current = next << bits; \
        } else { \
            value = current >> (32-(n)); \
            current = next; \
        } \
        next = *words++; \
    } else { \
        value = current >> (32-(n)); \
        current <<= (n); \
        bits += (n); \
    }
#define SKIP_BITS(n) \
    bits += (n); \
    if (bits >= 32) { \
        bits -= 32; \
        current = next << bits; \
        next = *words++; \
    } else { \
        current <<= (n); \
    }

void fn_12_62F8(void *output, const void *data, int *count) {
    int bits;
    u32 current;
    u32 next;
    const u32 *words;
    u32 a;
    u32 b;
    u32 c;
    u32 d;
    u32 e;
    u32 address;
    address = (u32)data + 4;
    words = (const u32 *)(address & ~3);
    bits = (address - (u32)words) * 8;
    current = *words++;
    next = *words++;
    current <<= bits;
    if (bits >= 30) {
        bits -= 30;
        if (bits != 0) {
            current |= next >> 1;
            a = current >> 30;
            current = next << 1;
        } else {
            a = current >> 30;
            current = next;
        }
        next = *words++;
    } else {
        a = current >> 30;
        current <<= 2;
        bits += 2;
    }
    SKIP_BITS(2);
    READ_BITS(b, 3);
    SKIP_BITS(1);
    READ_BITS(c, 15);
    SKIP_BITS(1);
    READ_BITS(d, 15);
    SKIP_BITS(1);
    SKIP_BITS(1);
    READ_BITS(e, 22);
    ((u32 *)output)[0] = a == 0;
    ((u32 *)output)[1] = (b << 28) | (c << 13) | (d >> 2);
    ((u32 *)output)[2] = e;
    *count = 12;
}
