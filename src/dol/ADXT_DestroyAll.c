
#include "types.h"
#include "sofdec/sj.h"

typedef struct AdxSjdHandle AdxSjdHandle;

typedef struct ADXStream ADXStream;

typedef struct AXRNAHandle AXRNAHandle;

typedef struct LSCObject LSCObject;

typedef struct ADX_AMP ADX_AMP;

typedef struct ADXTHandle {
    union {
        unsigned char padding_extent[68];
        struct {
            s8 used;
        } view_used;
    } fields;
} ADXTHandle;

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

extern ADXTHandle lbl_80186B68[];

extern void ADXSTM_EntryEosFunc(ADXStream *stream, void (*callback)(void *object), void *object);

void fn_8004FC94(ADXTHandle *handle);

void ADXT_DestroyAll(void) {
    ADXTHandle *handle;
    s32 index;
    for (index = 0; index < ADXT_MAX_HANDLES; index++) {
        handle = &lbl_80186B68[index];
        if (handle->fields.view_used.used == 1) {
            fn_8004FC94(handle);
        }
    }
}
