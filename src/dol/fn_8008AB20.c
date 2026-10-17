#include "types.h"

typedef struct TRKBuffer {
    u32 unk_0;
    u32 position;
    u32 length;
    u32 unk_C;
    u8 data[0x880];
} TRKBuffer;

extern u8 lbl_80095A78[168];
extern void MWTRACE(u32, ...);
extern s32 fn_80088B00(void *msg);
extern s32 fn_800894FC(void);
extern TRKBuffer *TRKGetBuffer(s32 id);
extern s32 fn_80089144(TRKBuffer *buffer, u32 pos);
extern void fn_8008A764(u8 *data, s32 length);
extern void fn_8008944C(s32 id);
extern u32 fn_800891B4(s32 id);

/* TRKRequestSend */
s32 fn_8008AB20(void *msgBuf, s32 *bufferId, u32 p1, u32 p2, s32 p3) {
    s32 error = 0;
    TRKBuffer *buffer;
    u32 timer;
    s32 tries;
    s32 msg_command;
    s32 msg_error;
    s32 badReply = 1;
    s32 id;

    *bufferId = -1;

    for (tries = p2 + 1; tries != 0 && *bufferId == -1 && error == 0; tries--) {
        MWTRACE(1, "Calling MessageSend\n");
        error = fn_80088B00(msgBuf);
        if (error == 0) {
            if (p3) {
                timer = 0;
            }

            while (1) {
                do {
                    *bufferId = fn_800894FC();
                    if ((id = *bufferId) != -1)
                        break;
                } while (!p3 || ++timer < 79999980);

                if (id == -1)
                    break;

                badReply = 0;

                buffer = TRKGetBuffer(id);
                fn_80089144(buffer, 0);

                fn_8008A764(&buffer->data[0], buffer->length);
                msg_command = buffer->data[4];
                MWTRACE(1, "msg_command : 0x%02x hdr->cmdID 0x%02x\n", msg_command, msg_command);

                if ((u32)msg_command >= 0x80)
                    break;

                fn_8008944C(*bufferId);
                *bufferId = -1;
            }

            if (*bufferId != -1) {
                if (buffer->length < 0x40) {
                    badReply = 1;
                }
                if (error == 0 && !badReply) {
                    msg_error = buffer->data[8];
                    MWTRACE(1, "msg_error : 0x%02x\n", msg_error);
                }
                if (error == 0 && !badReply) {
                    if ((s32)(p1 = msg_command) != 0x80 || msg_error != 0) {
                        MWTRACE(8, "RequestSend : Bad ack or non ack received msg_command : 0x%02x msg_error 0x%02x\n", p1, msg_error);
                        badReply = 1;
                    }
                }
                if (error != 0 || badReply) {
                    fn_800891B4(*bufferId);
                    *bufferId = -1;
                }
            }
        }
    }

    if (*bufferId == -1) {
        error = 0x800;
    }

    return error;
}
