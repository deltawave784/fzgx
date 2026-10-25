#include "types.h"

typedef struct fn_8004A068_Chan {
    u8 pad_0[0x4];
    s16 coef[2];
    s16 hist[2];
    u8 pad_C[0x8];
    s32 count;
    s16 samples[32];
    s8 nibbles[32];
    s32 maxAbs;
    s16 scale;
    u8 pad_7E[0x2];
    f64 inv;
    struct fn_8004A068_Chan *next;
} fn_8004A068_Chan;

typedef struct fn_8004A068_Stream {
    u8 pad_0[0x44];
    s32 chunk;
    u8 pad_48[0x38];
    fn_8004A068_Chan *chans[2];
    s16 hist0[2];
    s16 hist1[2];
    s16 buf[2][32];
} fn_8004A068_Stream;

extern s32 lbl_8012B8F8[];
extern const f64 lbl_80090988[];
extern const f64 lbl_80090980[];

static inline void fn_8004A068_set_hist(fn_8004A068_Chan *c, s16 h0, u16 h1) {
    c->hist[0] = h0;
    c->hist[1] = h1;
}

static inline s16 fn_8004A068_sample(s32 value) {
    return value;
}

static inline void fn_8004A068_update_max(fn_8004A068_Chan *c, s32 r) {
    if (__abs(r) > c->maxAbs) {
        c->maxAbs = __abs(r);
    }
}

static inline void fn_8004A068_predict(fn_8004A068_Chan *c, s32 i, s16 s) {
    s32 j;
    s32 e;
    s32 t;

    if (i == 0) {
        for (j = 0; j < c->count; j++) {
            c->samples[j] = 0;
        }
        c->maxAbs = 0;
    }
    if (c != NULL) {
        e = s - ((c->coef[0] * c->hist[0]) >> 12) - ((c->coef[1] * c->hist[1]) >> 12);
        t = (e < -32768) ? -32768 : e;
        t = (t > 32767) ? 32767 : ((e < -32768) ? -32768 : e);
        {
            s16 residual = t;
            c->samples[i] = residual;
            if (__abs(residual) > c->maxAbs) {
                c->maxAbs = __abs(residual);
            }
        }
        c->hist[1] = c->hist[0];
        c->hist[0] = s;
    }
}

static inline void fn_8004A068_decode(fn_8004A068_Chan *c, s16 d) {
    s32 e;
    s32 t;

    if (c != NULL) {
        e = d + ((c->coef[0] * c->hist[0] + c->coef[1] * c->hist[1]) >> 12);
        t = (e > -32768) ? e : -32768;
        t = (t < 32767) ? ((e > -32768) ? e : -32768) : 32767;
        c->hist[1] = c->hist[0];
        c->hist[0] = t;
    }
}

s32 fn_8004A068(fn_8004A068_Stream *stream, u32 ch, f32 arg2) {
    s16 *buf;
    s32 i;
    fn_8004A068_Chan *c;
    fn_8004A068_Chan *next;
    struct { s32 value; } lim;
    s32 k;
    s32 t;
    s32 q;
    s32 nib;
    s32 d;
    s32 e;
    s32 s;
    s16 v;
    fn_8004A068_Chan *n;
    u32 lab_t2;

    buf = stream->buf[ch];
    c = stream->chans[ch];
    next = c->next;
    fn_8004A068_set_hist(c, stream->hist0[ch], stream->hist1[ch]);
    for (i = 0; i < stream->chunk; i++) {
        fn_8004A068_predict(c, i, buf[i]);
    }

    k = (c->maxAbs - 1) / 7 + 1;
    lim.value = lbl_8012B8F8[0];
    t = (k < lim.value) ? k : lim.value;
    c->scale = (t > 1) ? ((k < lim.value) ? k : lim.value) : 1;
    if (c->maxAbs == 0) {
        c->inv = lbl_80090988[0];
    } else {
        c->inv = lbl_80090988[0] / (f64)c->maxAbs;
    }

    lab_t2 = stream->hist1[ch];
    fn_8004A068_set_hist(c->next, stream->hist0[ch], lab_t2);
    for (i = 0; i < stream->chunk; buf++, i++) {
        s = *(volatile s16 *)buf;  /* fzgx-allow: S2 volatile view keeps the verified load order */
        /* Observe the sample before reading the decoder history. */
        fn_8004A068_set_hist(c, next->hist[0], *(volatile s16 *)&next->hist[1]);
        fn_8004A068_predict(c, i, s);
        v = (c == NULL) ? 0 : c->samples[i];
        q = (s32)((f64)v * c->inv);
        t = (q < -32768) ? -32768 : q;
        v = (t > 32767) ? 32767 : ((q < -32768) ? -32768 : q);
        if (v < 0) {
            nib = (v - 2340) / 4681;
        } else {
            nib = (v + 2340) / 4681;
        }
        t = (nib < -8) ? -8 : nib;
        nib = (t < 7) ? ((nib < -8) ? -8 : nib) : 7;
        c->nibbles[i] = nib;
        d = nib * c->scale;
        t = (d < -32768) ? -32768 : d;
        v = (t > 32767) ? 32767 : ((d < -32768) ? -32768 : d);
        fn_8004A068_decode(c->next, v);
    }
    return 0;
}
