typedef unsigned char u8;
typedef unsigned long u32;

/* LZSS decoder (4 KiB ring buffer, 18-byte max match): state = {src, dst, done callback}.
 * The source starts with two little-endian words: packed size and decoded size. */
u32 *fn_18_444(u32 *state) {
    u8 win[0x1000 + 0x12 - 1];
    int off;
    int i;
    long len;
    u32 pos;
    u8 *cur;
    u8 *out;
    u32 bits;
    u32 limit;
    u8 *src;
    void (*done)(u32);
    u8 *dst;
    u32 out_size;
    src = (u8 *)state[0];
    done = (void (*)(u32))state[2];
    dst = (u8 *)state[1];
    limit = __lwbrx((u32 *)src, 0) + 8;
    out_size = __lwbrx((u32 *)src, 4);
    if (limit == 0 || out_size == 0) {
        return 0;
    }
    len = 0;
    out = dst;
    cur = src + 8;
    for (; len < 0xfee; len++) {
        win[len] = 0;
    }
    pos = 0xfee;
    bits = 0;
    for (;;) {
        bits >>= 1;
        if ((bits & 0x100) == 0) {
            if ((u32)(cur - src) >= limit) break;
            bits = *cur++ | 0xff00;
        }
        if (bits & 1) {
            u8 v;
            if ((u32)(cur - src) >= limit) break;
            v = *cur++;
            *out++ = v;
            win[pos] = v;
            pos++;
            pos &= 0xfff;
        } else {
            int len;
            if ((u32)(cur - src) >= limit) break;
            off = cur[0];
            if ((u32)((cur + 1) - src) >= limit) break;
            len = cur[1];
            cur += 2;
            off |= (len & 0xf0) << 4;
            len = (len & 0xf) + 2;
            for (i = 0; i <= len; i++) {
                u8 v = win[(off + i) & 0xfff];
                *out++ = v;
                win[pos] = v;
                pos++;
                pos &= 0xfff;
            }
        }
    }
    if (done != 0) {
        done(out_size);
    }
    return &out_size;
}
