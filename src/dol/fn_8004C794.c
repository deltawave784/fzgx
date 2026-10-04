
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

void fn_8004C794(ADXTHandle *handle, SJ *input);

extern s32 lbl_80178CB8;

extern void fn_80046738(void);

extern void fn_80046718(void);

extern void fn_800474E4(const char *message);

extern void fn_80042198(AdxSjdHandle *decoder, SJ *input);

extern void ADXSJD_SetLnkSw(AdxSjdHandle *decoder, s32 enabled);

extern void fn_8004212C(AdxSjdHandle *decoder);

extern void fn_800420F4(AdxSjdHandle *decoder);

extern void ADXSTM_EntryEosFunc(ADXStream *stream, void (*callback)(void *object), void *object);

extern void fn_8004B0EC(ADXStream *stream);

extern void fn_8004EEA4(AXRNAHandle *rna, s32 enabled);

extern void fn_8004EEC4(AXRNAHandle *rna, s32 enabled);

extern void fn_80056CD0(LSCObject *controller);

extern void ADXAMP_Start(ADX_AMP *amplifier);

extern void fn_80046510(ADX_AMP *amplifier);

void ADXT_Stop(ADXTHandle *handle);

extern const char lbl_80090FC4[];

extern const char lbl_80090FEC[];

static inline void ADXT_Stop(ADXTHandle *handle) {
    SJ *input;
    if (handle == 0) {
        fn_800474E4(lbl_80090FC4);
        return;
    }
    if (handle->stream != 0) {
        fn_8004B0EC(handle->stream);
    }
    fn_80046738();
    if (handle->stream_type == ADXT_STREAM_TYPE_LINKED) {
        fn_80056CD0(handle->linked_stream_controller);
        if (handle->input_sj != 0) {
            handle->input_sj->interface->reset(handle->input_sj);
        }
    }
    fn_80046738();
    fn_8004EEC4(handle->rna, 0);
    fn_8004EEA4(handle->rna, 0);
    fn_800420F4(handle->decoder);
    if (handle->stream_type == ADXT_STREAM_TYPE_MEMORY && handle->input_sj != 0) {
        input = handle->input_sj;
        handle->input_sj = 0;
        input->interface->destroy(input);
    }
    if (handle->amplifier != 0) {
        fn_80046510(handle->amplifier);
    }
    handle->input_sj = 0;
    handle->status = ADXT_STATUS_STOP;
    handle->pending_stream_start = 0;
    fn_80046718();
    fn_80046718();
}

void fn_8004C794(ADXTHandle *handle, SJ *input) {
    s32 channel;
    ADXTHandle *cursor;
    if (handle == 0 || input == 0) {
        fn_800474E4(lbl_80090FEC);
        return;
    }
    ADXT_Stop(handle);
    fn_80046738();
    cursor = handle;
    for (channel = 0; channel < handle->maximum_channels; channel++) {
        cursor->output_sj[0]->interface->reset(cursor->output_sj[0]);
        cursor = (ADXTHandle *)((u8 *)cursor + 4);
    }
    fn_80042198(handle->decoder, input);
    handle->input_sj = input;
    fn_8004212C(handle->decoder);
    handle->status = ADXT_STATUS_DECODING_HEADER;
    handle->loop_count = 0;
    handle->decoder_ready = 0;
    handle->eos_sector = 0x7FFFFFFF;
    handle->loop_sample_count = -1;
    handle->playback_time = 0;
    handle->linked_decoded_samples = 0;
    handle->playback_start_vsync = lbl_80178CB8;
    if (handle->amplifier != 0) {
        ADXAMP_Start(handle->amplifier);
    }
    handle->stream_type = ADXT_STREAM_TYPE_SJ;
    handle->link_enabled = 1;
    if (handle->decoder != 0) {
    }
    fn_80046718();
}
