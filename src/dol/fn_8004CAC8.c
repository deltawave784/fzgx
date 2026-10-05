#include "types.h"
#include "sofdec/adxt.h"

enum {
    ADXT_STATUS_STOP = 0,
    ADXT_STATUS_DECODING_HEADER = 1,
    ADXT_STREAM_TYPE_MEMORY = 2,
    ADXT_STREAM_TYPE_LINKED = 4
};

extern void fn_80046738(void);

extern void fn_80046718(void);

extern void fn_800474E4(const char *message);

extern void fn_800420F4(AdxSjdHandle *decoder);

extern void fn_800421CC(AdxSjdHandle *decoder);

extern void fn_8004B0EC(ADXStream *stream);

extern void fn_8004AC4C(ADXStream *stream, void (*callback)(void *object), void *object);

extern void fn_8004B1DC(ADXStream *stream);

extern void fn_8004EEA4(AXRNAHandle *rna, s32 enabled);

extern void fn_8004EEC4(AXRNAHandle *rna, s32 enabled);

extern void fn_8004EEE4(AXRNAHandle *rna);

extern void fn_80056CD0(LSCObject *controller);

extern void fn_80057114(LSCObject *controller);

extern void fn_80046510(ADX_AMP *amplifier);

extern void fn_800466D4(ADX_AMP *amplifier);

extern void *memset(void *, int, u32);

extern const char lbl_80090FC4[];

extern const char lbl_80091014[];

extern void (*lbl_8017E58C[])(ADXTHandle *handle);

/* ADXT_Stop (same TU in retail, auto-inlined here) */
static inline void adxt_stop(ADXTHandle *handle) {
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

void fn_8004CAC8(ADXTHandle *handle) {
    ADXStream *stream;
    SJ *sj;
    s32 i;

    if (handle == 0) {
        fn_800474E4(lbl_80091014);
        return;
    }
    if (lbl_8017E58C[0] != 0) {
        lbl_8017E58C[0](handle);
    }
    if (handle->used == ADXT_STATUS_DECODING_HEADER) {
        adxt_stop(handle);
    }
    if (handle->rna != 0) {
        AXRNAHandle *rna = handle->rna;
        handle->rna = 0;
        fn_8004EEE4(rna);
    }
    if (handle->decoder != 0) {
        AdxSjdHandle *decoder = handle->decoder;
        handle->decoder = 0;
        fn_800421CC(decoder);
    }
    stream = handle->stream;
    if (stream != 0) {
        handle->stream = 0;
        fn_8004AC4C(stream, 0, 0);
        fn_8004B1DC(stream);
    }
    if (handle->linked_stream_controller != 0) {
        LSCObject *lsc = handle->linked_stream_controller;
        handle->linked_stream_controller = 0;
        fn_80057114(lsc);
    }
    fn_80046738();
    if (handle->stream_sj != 0) {
        sj = handle->stream_sj;
        handle->stream_sj = 0;
        sj->interface->destroy(sj);
    }
    for (i = 0; i < handle->maximum_channels; i++) {
        if (handle->output_sj[i] != 0) {
            sj = handle->output_sj[i];
            handle->output_sj[i] = 0;
            sj->interface->destroy(sj);
        }
        if (handle->amplifier_input[i] != 0) {
            sj = handle->amplifier_input[i];
            handle->amplifier_input[i] = 0;
            sj->interface->destroy(sj);
        }
        if (handle->amplifier_output[i] != 0) {
            sj = handle->amplifier_output[i];
            handle->amplifier_output[i] = 0;
            sj->interface->destroy(sj);
        }
    }
    if (handle->amplifier != 0) {
        ADX_AMP *amp = handle->amplifier;
        handle->amplifier = 0;
        fn_800466D4(amp);
    }
    memset(handle, 0, sizeof(ADXTHandle));
    handle->used = 0;
    fn_80046718();
}
