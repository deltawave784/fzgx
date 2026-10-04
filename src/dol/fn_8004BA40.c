
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

s32 fn_8004BA40(ADXTHandle *handle, s32 samples);

extern ADXTHandle lbl_80186B68[];
extern ADXTHandle lbl_80178CBC[];

extern s32 lbl_80178CB8;

extern void fn_80046738(void);

extern void fn_80046718(void);

extern void fn_80046738(void);

extern void ADXSTM_EntryEosFunc(ADXStream *stream, void (*callback)(void *object), void *object);

extern void fn_8004EE44(void);

extern s32 fn_8004ED84(AXRNAHandle *rna, s32 samples);

extern void fn_8004D220(ADXTHandle *handle);

void fn_8004C164(ADXTHandle *handle, s32 *sample_count, s32 *scale);

struct adx_tlkBss {
    s32 adxt_time_mode;
    s32 adxt_tsvr_enter_cnt;
    unsigned char padding_8[36];
    s32 adxt_time_unit;
};
extern struct adx_tlkBss lbl_8017E568;

static inline void adxt_ExecServers(struct adx_tlkBss *bss) {
    ADXTHandle *entry;
    s32 index;

    fn_80046738();
    if ((bss->adxt_tsvr_enter_cnt) != 0) {
        fn_80046718();
        return;
    }
    (bss->adxt_tsvr_enter_cnt) = 1;
    fn_80046718();
    fn_80046738();
    fn_80041700();
    (bss->adxt_tsvr_enter_cnt) = 2;
    entry = lbl_80178CBC;
    for (index = 0; index < ADXT_MAX_HANDLES; index++, entry++) {
        if (entry->used == 1) {
            fn_8004D220(entry);
        }
    }
    (bss->adxt_tsvr_enter_cnt) = 3;
    fn_8004EE44();
    (bss->adxt_tsvr_enter_cnt) = 0;
    fn_80046718();
}

s32 fn_8004BA40(ADXTHandle *handle, s32 samples) {
    s32 discarded;
    s32 count;
    s32 scale;
    s32 saved_time_mode;
    struct adx_tlkBss *bss = &lbl_8017E568;
    if (handle->paused == 0) {
        return 0;
    }
    discarded = fn_8004ED84(handle->rna, samples);
    adxt_ExecServers(bss);
    saved_time_mode = (bss->adxt_time_mode);
    (bss->adxt_time_mode) = 0;
    fn_8004C164(handle, &count, &scale);
    (bss->adxt_time_mode) = saved_time_mode;
    handle->playback_time = (u32)((f32)(bss->adxt_time_unit) * ((f32)count / (f32)scale));
    handle->playback_start_vsync = lbl_80178CB8;
    return discarded;
}
