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

extern char lbl_800922C8[21];
extern void fn_800565FC(const char *, ...);
extern s32 fn_8004AEE4(ADXStream *stream);
extern s32 fn_8004AE78(ADXStream *stream);
extern void fn_8005676C(void);
extern s32 fn_80056E9C(LSCObject *, const char *, void *, s32, s32);
extern void fn_8004AD84(ADXStream *);
extern void fn_8004B0EC(ADXStream *);
extern void fn_8004B180(ADXStream *, const char *, void *, s32, s32);
extern void fn_8004AC04(ADXStream *, s32);
extern s32 fn_8004A550(ADXStream *, s32, s32);
extern s32 fn_8004AE94(ADXStream *, s32);
extern s32 fn_8004ADF4(ADXStream *);

/* Finish the stream at the read position; when looping, re-queue it with
 * its own parameters (the defaults are only used when not looping). */
static inline void lsc_finish_stream(LSCObject *lsc, s32 sectors, s32 offset, void *directory, const char *filename) {
    LSCStreamInfo *info;

    if (lsc->stream == NULL) {
        return;
    }
    if (lsc->loop == 1) {
        info = &lsc->stream_info[lsc->read_position];
        filename = info->filename;
        directory = info->directory;
        offset = info->offset;
        sectors = info->sector_count;
    }
    lsc->stream_count--;
    lsc->read_position = (lsc->read_position + 1) % 16;
    if (lsc->stream_count <= 0) {
        fn_8005676C();
        lsc->state = 1;
    }
    if (lsc->loop == 1) {
        fn_80056E9C(lsc, filename, directory, offset, sectors);
    }
}

void fn_80057494(LSCObject *lsc) {
    LSCStreamInfo *info;
    s32 status;

    if (lsc->paused == 1) {
        return;
    }
    if (lsc->state != 2) {
        return;
    }
    if (lsc->stream_count <= 0) {
        return;
    }

    if (lsc->stream_info[lsc->read_position].state == 1) {
        if (lsc->stream == NULL) {
            fn_800565FC(lbl_800922C8);
        } else {
            info = &lsc->stream_info[lsc->read_position];
            status = fn_8004AEE4(lsc->stream);
            if (status == 4) {
                lsc->state = 3;
            } else if (status == 2) {
                info->read_sectors = fn_8004AE78(lsc->stream);
            } else if (status == 3) {
                info->read_sectors = lsc->file_sectors;
                info->state = 2;
            }
        }
    }

    if (lsc->stream_info[lsc->read_position].state == 2) {
        lsc_finish_stream(lsc, 0, 0, NULL, NULL);
    }

    if (lsc->stream_info[lsc->read_position].state == 0) {
        info = &lsc->stream_info[lsc->read_position];
        if (lsc->stream_count > 0) {
            fn_8004AD84(lsc->stream);
            fn_8004B0EC(lsc->stream);
            fn_8004B180(lsc->stream, info->filename, info->directory, info->offset, info->sector_count);
            fn_8004AC04(lsc->stream, info->sector_count);
            lsc->file_sectors = info->sector_count;
            info->read_sectors = 0;
            lsc->reading = 0;
            if (lsc->reading == 0) {
                fn_8004A550(lsc->stream, lsc->minimum_buffer_size, lsc->buffer_size);
                fn_8004AE94(lsc->stream, 0);
                fn_8004ADF4(lsc->stream);
                lsc->reading = 1;
            }
            info->state = 1;
        }
    }
}
