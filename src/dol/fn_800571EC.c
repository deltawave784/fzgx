#include "types.h"
#include "sofdec/sj.h"

typedef struct ADXStream ADXStream;

typedef struct LSCStreamInfo {
    s32 id;
    const char *filename;
    u32 filename_checksum;
    void *directory;
    s32 offset;
    s32 sector_count;
    s32 state;
    s32 read_sectors;
} LSCStreamInfo;

typedef struct LSCObject {
    s8 used;
    s8 state;
    s8 reading;
    s8 loop;
    s8 paused;
    u8 reserved_05;
    u16 reserved_06;
    SJ *sj;
    SJCK chunk;
    s32 minimum_buffer_size;
    s32 buffer_size;
    s32 write_position;
    s32 read_position;
    s32 stream_count;
    ADXStream *stream;
    s32 file_sectors;
    s32 requested_sectors;
    s32 error_count;
    LSCStreamInfo stream_info[16];
} LSCObject;

extern void fn_800565FC(const char *format, ...);
extern void fn_80056710(s32 *state);
extern void fn_800566F0(s32 *state);

extern LSCObject lbl_80188A8C[16];

/* Find an unused object slot. */
static LSCObject *lsc_AllocObject(void) {
    LSCObject *lsc = 0;
    s32 i;
    for (i = 0; i < 16; i++) {
        if (lbl_80188A8C[i].used == 0) {
            lsc = &lbl_80188A8C[i];
            break;
        }
    }
    return lsc;
}

LSCObject *fn_800571EC(SJ *sj) {
    LSCObject *lsc;
    s32 critical_state;
    s32 i;

    if (sj == 0) {
        fn_800565FC("E0001: Illigal parameter=sj (LSC_Create)\n");
        return 0;
    }
    fn_80056710(&critical_state);
    lsc = lsc_AllocObject();
    if (lsc == 0) {
        fn_800565FC("E0002: Not enough instance (LSC_Create)\n");
    } else {
        lsc->sj = sj;
        lsc->state = 0;
        lsc->buffer_size = sj->interface->get_num_data(sj, 0) + sj->interface->get_num_data(sj, 1);
        lsc->minimum_buffer_size = (lsc->buffer_size * 8) / 10;
        for (i = 0; i < 16; i++) {
            lsc->stream_info[i].state = 0;
        }
        lsc->used = 1;
    }
    fn_800566F0(&critical_state);
    return lsc;
}
