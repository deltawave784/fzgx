
#include "types.h"
#include "sofdec/adxt.h"

enum {
    ADXT_STATUS_DECODING_HEADER = 1,
    ADXT_STATUS_BUFFERING = 2,
    ADXT_STATUS_PLAYING = 3,
    ADXT_STATUS_DRAINING = 4,
    ADXT_STATUS_ERROR = 6,
    ADXT_STREAM_TYPE_FILE = 0,
    ADXT_STREAM_TYPE_RANGE = 1,
    ADXT_STREAM_TYPE_MEMORY = 2,
    ADXT_STREAM_TYPE_LINKED = 3,
    ADXSJD_STATUS_HEADER_READY = 2,
    ADXSJD_STATUS_INPUT_END = 3,
    ADXSTM_STATUS_READING = 2,
    ADXSTM_STATUS_END = 3,
    ADXSTM_STATUS_ERROR = 4,
    ADXT_SECTOR_SIZE = 0x800,
    ADXT_MIN_PLAY_DATA = 0x40
};

extern s32 fn_80041578(AdxSjdHandle *decoder);

extern void fn_800416DC(AdxSjdHandle *decoder, s32 samples);

extern void ADXSJD_EntryTrapFunc(AdxSjdHandle *decoder, void (*callback)(void *object),
                                 void *object);

extern void fn_8004AC04(ADXStream *stream, s32 sector);

extern void ADXSTM_EntryEosFunc(ADXStream *stream, void (*callback)(void *object), void *object);

extern s32 fn_8004AE94(ADXStream *stream, s32 sector);

void adxt_eos_entry(void *object) {
    ADXTHandle *handle = (ADXTHandle *)object;
    ADXStream *stream = handle->stream;
    AdxSjdHandle *decoder = handle->decoder;
    s32 loop_start_offset;
    if (stream == 0 || decoder == 0) {
        return;
    }
    loop_start_offset = fn_80041578(decoder);
    if (handle->stream_loop_enabled == 0) {
        fn_800416DC(handle->decoder, -1);
        fn_8004AC04(handle->stream, 0x7FFFFFFF);
    } else {
        fn_8004AE94(stream, loop_start_offset / ADXT_SECTOR_SIZE);
    }
}
