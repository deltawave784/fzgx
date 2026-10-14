#include "types.h"

typedef struct fn_800244C8_Delay {
    s32 write;
    s32 read;
    s32 size;
    void *buf;
    f32 state;
} fn_800244C8_Delay;

typedef struct fn_800244C8_Reverb {
    fn_800244C8_Delay allpass[6];
    fn_800244C8_Delay comb[6];
    f32 time;
    f32 combGain[6];
    f32 lpState[3];
    f32 coloration;
    f32 damping;
    s32 preDelaySize;
    void *preDelayBuf[3];
    void *preDelayPtr[3];
} fn_800244C8_Reverb;

extern void *memset(void *, int, u32);
extern u32 lbl_80128180[4];
extern void *(*lbl_801A64F8)(u32);
extern f32 fn_800885B8(f32, f32);

static inline void fn_800244C8_setDelay(fn_800244C8_Delay *d, s32 delay) {
    d->read = d->write - delay * 4;
    while (d->read < 0) {
        d->read += d->size;
    }
}

static inline void fn_800244C8_init(fn_800244C8_Delay *d, s32 maxDelay) {
    s32 n;

    n = maxDelay + 2;
    d->size = n * 4;
    d->buf = lbl_801A64F8(n * 4);
    memset(d->buf, 0, n * 4);
    d->state = 0.0f;
    d->read = d->write - (n >> 1) * 4;
    while (d->read < 0) {
        d->read += d->size;
    }
    d->write = 0;
    d->read = 0;
}

int fn_800244C8(fn_800244C8_Reverb *rv, f32 time, f32 preDelay, f32 coloration, f32 damping, f32 mix) {
    u8 i;
    u8 k;
    f32 rate;
    u8 j;

    if (time < 0.0f || time > 1.0f || preDelay < 0.01f || preDelay > 10.0f ||
        coloration < 0.0f || coloration > 1.0f || damping < 0.0f || damping > 1.0f ||
        mix < 0.0f || mix > 0.1f) {
        return 0;
    }

    memset(rv, 0, sizeof(fn_800244C8_Reverb));
    rate = 32000.0f * preDelay;

    for (i = 0; i < 3; i++) {
        for (k = 0; k < 2; k++) {
            fn_800244C8_init(&rv->comb[i * 2 + k], lbl_80128180[k]);
            fn_800244C8_setDelay(&rv->comb[i * 2 + k], lbl_80128180[k]);
            rv->combGain[i * 2 + k] = fn_800885B8(10.0f, (f32)(s32)(lbl_80128180[k] * -3) / rate);
        }
        for (k = 0; k < 2; k++) {
            fn_800244C8_init(&rv->allpass[i * 2 + k], lbl_80128180[k + 2]);
            fn_800244C8_setDelay(&rv->allpass[i * 2 + k], lbl_80128180[k + 2]);
        }
        rv->lpState[i] = 0.0f;
    }

    rv->time = time;
    rv->coloration = coloration;
    rv->damping = damping;
    if (rv->damping < 0.05f) {
        rv->damping = 0.05f;
    }
    rv->damping = 1.0f - (0.05f + (f32)(0.8f * rv->damping));

    if (0.0f != mix) {
        rv->preDelaySize = (s32)(32000.0f * mix);
        for (j = 0; j < 3; j++) {
            rv->preDelayBuf[j] = lbl_801A64F8(rv->preDelaySize * 4);
            memset(rv->preDelayBuf[j], 0, rv->preDelaySize * 4);
            rv->preDelayPtr[j] = rv->preDelayBuf[j];
        }
    } else {
        rv->preDelaySize = 0;
        rv->preDelayBuf[0] = rv->preDelayPtr[0] = NULL;
        rv->preDelayBuf[1] = rv->preDelayPtr[1] = NULL;
        rv->preDelayBuf[2] = rv->preDelayPtr[2] = NULL;
    }
    return 1;
}
