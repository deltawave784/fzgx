
#include "types.h"
#include "sofdec/adxt.h"

extern s32 fn_80041660(AdxSjdHandle *decoder);

extern s16 fn_80041460(AdxSjdHandle *decoder, s32 channel);

extern void ADXSJD_EntryTrapFunc(AdxSjdHandle *decoder, void (*callback)(void *object),
                                 void *object);

extern void ADXSTM_EntryEosFunc(ADXStream *stream, void (*callback)(void *object), void *object);

extern void fn_8004EDC4(AXRNAHandle *rna, s32 channel, s32 pan);

void adxt_set_outpan(ADXTHandle *handle) {
    s32 default_pan[2];
    s32 channel_count;
    s32 channel;
    s32 pan;
    channel_count = fn_80041660(handle->decoder);
    for (channel = 0; channel < 2; channel++) {
        default_pan[channel] = fn_80041460(handle->decoder, channel);
    }
    if (channel_count == 1) {
        pan = handle->output_pan[0];
        if (pan == -128 && default_pan[0] == -128) {
            fn_8004EDC4(handle->rna, 0, 0);
        } else if (pan != -128 && default_pan[0] == -128) {
            fn_8004EDC4(handle->rna, 0, pan);
        } else if (pan == -128 && default_pan[0] != -128) {
            fn_8004EDC4(handle->rna, 0, default_pan[0]);
        } else {
            fn_8004EDC4(handle->rna, 0, pan + default_pan[0]);
        }
        return;
    }
    pan = handle->output_pan[0];
    if (pan == -128 && default_pan[0] == -128) {
        fn_8004EDC4(handle->rna, 0, -15);
    } else if (pan != -128 && default_pan[0] == -128) {
        fn_8004EDC4(handle->rna, 0, pan);
    } else if (pan == -128 && default_pan[0] != -128) {
        fn_8004EDC4(handle->rna, 0, default_pan[0]);
    } else {
        fn_8004EDC4(handle->rna, 0, pan + default_pan[0]);
    }
    pan = handle->output_pan[1];
    if (pan == -128 && default_pan[1] == -128) {
        fn_8004EDC4(handle->rna, 1, 15);
    } else if (pan != -128 && default_pan[1] == -128) {
        fn_8004EDC4(handle->rna, 1, pan);
    } else if (pan == -128 && default_pan[1] != -128) {
        fn_8004EDC4(handle->rna, 1, default_pan[1]);
    } else {
        fn_8004EDC4(handle->rna, 1, pan + default_pan[1]);
    }
}
