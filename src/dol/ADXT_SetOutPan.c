
#include "types.h"
#include "sofdec/adxt.h"

enum {
    ADXT_MAX_HANDLES = 16,
    ADXT_STATUS_STOP = 0,
    ADXT_STATUS_DECODING_HEADER = 1,
    ADXT_STATUS_BUFFERING = 2,
    ADXT_STATUS_PLAYING = 3,
    ADXT_STATUS_DRAINING = 4,
    ADXT_STATUS_PLAY_END = 5,
    ADXT_STREAM_TYPE_MEMORY = 2,
    ADXT_STREAM_TYPE_SJ = 3,
    ADXT_STREAM_TYPE_LINKED = 4,
    ADXT_SECTOR_SIZE = 0x800,
    ADXT_INPUT_EXTRA_SIZE = 0x24,
    ADXT_OUTPUT_SIZE = 0x2000,
    ADXT_OUTPUT_DISTANCE = 0x2060,
    ADXT_DEFAULT_PAN = -128
};

extern void fn_800474E4(const char *message);

extern s16 fn_80041460(AdxSjdHandle *decoder, s32 channel);

extern void ADXSTM_EntryEosFunc(ADXStream *stream, void (*callback)(void *object), void *object);

extern void fn_8004EDC4(AXRNAHandle *rna, s32 channel, s32 pan);

extern const char lbl_80090EB0[];

extern const char lbl_80090EDC[];

void ADXT_SetOutPan(ADXTHandle *handle, s32 channel, s32 pan) {
    s16 default_pan;
    if (handle == 0) {
        fn_800474E4(lbl_80090EB0);
        return;
    }
    default_pan = fn_80041460(handle->decoder, channel);
    if (default_pan == ADXT_DEFAULT_PAN) {
        default_pan = 0;
    }
    handle->output_pan[channel] = pan + default_pan;
    if (channel < handle->maximum_channels) {
        fn_8004EDC4(handle->rna, channel, pan);
    } else {
        fn_800474E4(lbl_80090EDC);
    }
}
