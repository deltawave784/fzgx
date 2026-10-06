#include "types.h"
#include "sofdec/sj.h"
typedef struct CvFsObject CvFsObject;
typedef struct ADXStream ADXStream;
typedef void (*ADXStreamEosCallback)(void *object);
struct ADXStream {
    s8 used;
    s8 status;
    s8 read_active;
    s8 retry_count;
    SJ *sj;
    CvFsObject *file;
    s32 file_offset;
    s32 file_size;
    s32 file_sectors;
    u8 reserved18[0x28];
    s8 stop_requested;
    s8 bind_requested;
    s8 release_requested;
    s8 start_requested;
    s8 stop_pending;
    s8 file_open;
    s8 realtime;
    u8 reserved_47[5];
    const char *filename;
    void *directory;
    s32 position;
    s32 transfer_limit;
};
extern void fn_80054AB0(void *);
extern s32 fn_80059B44(void);
extern s32 fn_80059AB4(void);
extern CvFsObject *fn_80054B6C(const char *, void *, int);
extern char lbl_80090990[41];
extern void fn_80047464(const char *, const char *);
extern int fn_80054930(CvFsObject *, int, int);
extern s32 fn_800549F0(CvFsObject *);
extern void fn_8004A80C(ADXStream *);
void fn_8004A5F4(ADXStream *stream) {
    s32 sectors;
    s32 bytes;
    if (stream->read_active == 0) {
        if (stream->stop_pending == 1) {
            stream->stop_pending = 0;
            if (stream->start_requested == 0) {
                stream->status = 1;
            }
        }
        if (stream->release_requested == 1) {
            if (stream->file != 0) {
                CvFsObject *file = stream->file;
                stream->file = 0;
                fn_80054AB0(file);
            }
            stream->release_requested = 0;
            stream->file_open = 0;
        }
        fn_80059B44();
        if (stream->bind_requested == 1) {
            stream->file_open = 1;
            fn_80059AB4();
            if (stream->file == 0) {
                CvFsObject *file = fn_80054B6C(stream->filename, stream->directory, 0);
                stream->file = file;
                if (file == 0) {
                    fn_80047464(lbl_80090990, stream->filename);
                    stream->status = 4;
                    stream->file_open = 0;
                    stream->bind_requested = 0;
                    return;
                }
                fn_80054930(stream->file, 0, 2);
                sectors = fn_800549F0(stream->file);
                bytes = sectors << 11;
                fn_80054930(stream->file, 0, 0);
                if (stream->file_size == 0x7ffff800) {
                    stream->file_size = bytes;
                } else {
                    if (stream->file_offset > sectors) {
                        stream->file_offset = sectors;
                    }
                    if (stream->file_size / 2048 + stream->file_offset > sectors) {
                        stream->file_size = (sectors - stream->file_offset) << 11;
                    }
                }
                stream->position = 0;
                if ((stream->position << 11) > stream->file_size) {
                    stream->position = stream->file_size / 2048 + (stream->file_size % 2048 > 0);
                }
                stream->bind_requested = 0;
            }
        } else {
            fn_80059AB4();
        }
        if (stream->start_requested == 1) {
            stream->start_requested = 0;
        }
    }
    if (stream->status == 2 && stream->file_open == 1) {
        fn_8004A80C(stream);
    }
}
