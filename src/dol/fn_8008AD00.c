#include "types.h"
#include "dolphin/trk.h"

extern void *memset(void *dst, int value, u32 size);
extern s32 fn_80089244(void *out_id, void *out_buffer);
extern s32 TRKAppendBuffer_ui8(void *buffer, const void *data, u32 length);
extern s32 TRKReadBuffer_ui8(void *buffer, void *data, u32 length);
extern s32 fn_8008AB20(void *buffer, void *out, u32 a2, u32 a3, u32 a4);
extern void *TRKGetBuffer(u32 handle);
extern void fn_80089144(void *buffer, u32 position);
extern void fn_800891B4(u32 handle);
extern s32 fn_80088B00(void *buffer);

struct FileRequest {
    u32 length;
    u8 command;
    u8 unk_5[3];
    u32 handle;
    u16 count;
    u8 unk_E[0x32];
};

/* TRKSuppAccessFile: read/write a host file in 0x800-byte chunks. */
s32 fn_8008AD00(u32 handle, u8 *data, u32 *count, s32 *io_result, s32 need_reply, s32 read) {
    u8 *reply;
    s32 error;
    u8 reply_result;
    u16 reply_length;
    u32 reply_id;
    u32 buffer_id;
    u32 buffer;
    struct FileRequest request;
    u8 command;
    u32 length;
    u32 done;
    s32 exit;

    if (data == NULL || *count == 0) {
        return 2;
    }

    exit = 0;
    *io_result = 0;
    done = 0;
    error = 0;
    while (!exit && done < *count && error == 0 && *io_result == 0) {
        memset(&request, 0, 0x40);
        if (*count - done > 0x800) {
            length = 0x800;
        } else {
            length = *count - done;
        }
        command = 0xd0;
        if (read) {
            command = 0xd1;
        }
        request.command = command;
        if (read) {
            request.length = 0x40;
        } else {
            request.length = length + 0x40;
        }
        request.handle = handle;
        request.count = length;

        fn_80089244(&buffer_id, &buffer);
        error = TRKAppendBuffer_ui8((void *)buffer, &request, 0x40);
        if (!read && error == 0) {
            error = TRKAppendBuffer_ui8((void *)buffer, data + done, length);
        }

        if (error == 0) {
            if (need_reply) {
                s32 b = read && handle == 0;
                error = fn_8008AB20((void *)buffer, &reply_id, read ? 5 : 5, 3, !b);
                if (error == 0) {
                    reply = TRKGetBuffer(reply_id);
                }
                reply_result = *(u32 *)(reply + 0x20);
                reply_length = *(u16 *)(reply + 0x24);
                if (read && error == 0 && reply_length <= length) {
                    fn_80089144(reply, 0x40);
                    error = TRKReadBuffer_ui8(reply, data + done, reply_length);
                    if (error == 0x302) {
                        error = 0;
                    }
                }
                if (reply_length != length) {
                    if ((!read || reply_length >= length) && reply_result == 0) {
                        reply_result = 1;
                    }
                    length = reply_length;
                    exit = 1;
                }
                *io_result = reply_result;
                fn_800891B4(reply_id);
            } else {
                error = fn_80088B00((void *)buffer);
            }
        }
        fn_800891B4(buffer_id);
        done += length;
    }
    *count = done;
    return error;
}
