
#include "types.h"
#include "sofdec/sj.h"

enum {
    ADXSJE_MAX_HANDLES = 8,
    ADXSJE_MAX_CHANNELS = 2,
    ADXSJE_MAX_FILTERS = 16,
    ADXSJE_MAX_BLOCK_SAMPLES = 32,
    ADXSJE_BLOCK_BYTES = 18
};

typedef struct AdxSjeIirFilter {
    union {
        unsigned char padding_extent[12];
        struct {
            s8 used;
        } view_used;
    } fields;
} AdxSjeIirFilter;

typedef struct AdxSjePredictorFilter {
    union {
        unsigned char padding_extent[144];
        struct {
            s8 used;
        } view_used;
    } fields;
} AdxSjePredictorFilter;

typedef struct AdxSjeHandle {
    union {
        unsigned char padding_extent[752];
        struct {
            s8 used;
        } view_used;
    } fields;
} AdxSjeHandle;

extern AdxSjeHandle lbl_8017BF78[ADXSJE_MAX_HANDLES];

void fn_800478C0(AdxSjeHandle *encoder);

void ADXSJE_ExecServer(void) {
    s32 index;
    for (index = 0; index < ADXSJE_MAX_HANDLES; index++) {
        if (lbl_8017BF78[index].fields.view_used.used == 1) {
            fn_800478C0(&lbl_8017BF78[index]);
        }
    }
}
