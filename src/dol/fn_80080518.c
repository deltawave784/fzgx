#include "types.h"

void fn_80080518(void *dst, const void *src, size_t n) {
    unsigned long blocks;
    unsigned long i;
    unsigned long v2;
    ((unsigned char *)src) = ((unsigned char *)src) + n;
    ((unsigned char *)dst) = ((unsigned char *)dst) + n;
    i = ((unsigned long)((unsigned char *)dst)) & 3;
    if (i) {
        n -= i;
        do
            *--((unsigned char *)dst) = *--((unsigned char *)src);
        while (--i);
    }
    i = n >> 5;
    if (i) {
        do {
            *--((unsigned long *)dst) = *--((unsigned long *)src);
            *--((unsigned long *)dst) = *--((unsigned long *)src);
            *--((unsigned long *)dst) = *--((unsigned long *)src);
            *--((unsigned long *)dst) = *--((unsigned long *)src);
            *--((unsigned long *)dst) = *--((unsigned long *)src);
            *--((unsigned long *)dst) = *--((unsigned long *)src);
            *--((unsigned long *)dst) = *--((unsigned long *)src);
            *--((unsigned long *)dst) = *--((unsigned long *)src);
        } while (--i);
    }
    i = (n & 31) >> 2;
    if (i) {
        do
            *--((unsigned long *)dst) = *--((unsigned long *)src);
        while (--i);
    }
    n &= 3;
    if (n) {
        do
            *--((unsigned char *)dst) = *--((unsigned char *)src);
        while (--n);
    }
}
