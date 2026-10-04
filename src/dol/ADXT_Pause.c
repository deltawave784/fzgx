
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

extern s32 lbl_80178CB8;

extern void fn_80046738(void);

extern void fn_80046718(void);

extern void fn_800474E4(const char *message);

extern void ADXSTM_EntryEosFunc(ADXStream *stream, void (*callback)(void *object), void *object);

extern void fn_8004EEA4(AXRNAHandle *rna, s32 enabled);

void fn_8004C164(ADXTHandle *handle, s32 *sample_count, s32 *scale);

extern const char lbl_80090A58[];

extern s32 lbl_8017E568;

extern s32 lbl_8017E594;

void ADXT_Pause(ADXTHandle *handle, s32 paused) {
    s32 status;
    s32 count;
    s32 scale;
    s32 saved_time_mode;
    if (handle == 0) {
        fn_800474E4(lbl_80090A58);
        return;
    }
    status = handle->status;
    if (paused == handle->paused) {
        return;
    }
    fn_80046738();
    handle->paused = paused;
    if (status == ADXT_STATUS_PLAYING || status == ADXT_STATUS_DRAINING) {
        if (paused == 1) {
            fn_8004EEA4(handle->rna, 0);
        } else {
            fn_8004EEA4(handle->rna, 1);
            handle->playback_start_vsync = lbl_80178CB8;
        }
        saved_time_mode = lbl_8017E568;
        lbl_8017E568 = 0;
        fn_8004C164(handle, &count, &scale);
        lbl_8017E568 = saved_time_mode;
        handle->playback_time = (u32)((f32)lbl_8017E594 * ((f32)count / (f32)scale));
    }
    fn_80046718();
}
