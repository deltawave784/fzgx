#include "types.h"
#pragma use_lmw_stmw on
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
extern char lbl_80092188[35];
extern char lbl_80092214[35];
extern void fn_800565FC(const char *, ...);
extern u32 strlen(const char *);

s32 fn_80056E9C(LSCObject *lsc, const char *filename, void *directory, s32 offset, s32 sector_count) {
    LSCStreamInfo *entry;
    s32 previous_id;
    s32 id;
    u32 *name;
    u32 i;
    u32 count;
    if (lsc == 0) {
        fn_800565FC(lbl_80092188);
        return -1;
    }
    if (lsc->stream_count >= 16) return -1;
    if (filename == 0) {
        fn_800565FC(lbl_80092214);
        return -1;
    }
    name = (u32 *)filename;
    previous_id = lsc->stream_info[(lsc->write_position + 15) % 16].id;
    entry = &lsc->stream_info[lsc->write_position];
    if (previous_id == 0x7fffffff) id = 0;
    else id = previous_id + 1;
    entry->id = id;
    entry->filename = filename;
    count = strlen(filename) / 4;
    entry->filename_checksum = 0;
    for (i = 0; i < count; i++) {
        entry->filename_checksum += name[i];
    }
    entry->offset = offset;
    entry->sector_count = sector_count;
    entry->directory = directory;
    entry->state = 0;
    entry->read_sectors = 0;
    lsc->stream_count++;
    lsc->write_position = (lsc->write_position + 1) % 16;
    if (lsc->state == 1) lsc->state = 2;
    return id;
}
