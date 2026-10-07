#include "types.h"
#pragma use_lmw_stmw on

typedef struct Buffer Buffer;
typedef struct BufferInterface {
    u32 pad[5];
    void (*reset)(Buffer *);
} BufferInterface;
struct Buffer { BufferInterface *interface; };
typedef struct Handle {
    u8 used;
    u8 flags;
    s8 count2;
    s8 count;
    s32 field4;
    u8 pad8[0x30];
    Buffer *buffers[2];
    u8 field40[2][8];
    u8 field50[2][8];
    s32 field60[2];
    s32 field68;
    s32 field6C;
    s32 field70[2];
    s32 field78;
    s32 field7C;
    u8 pad80[0x28];
    u8 fieldA8[2][32];
} Handle;

extern char lbl_80092790[44];
void fn_8005A648(void);
void fn_8005A628(void);
void fn_8005A5BC(u32);
void *memset(void *, int, unsigned long);

static inline s32 get_enabled(Handle *handle) {
    s32 result;
    if (handle == 0) result = -1;
    else result = handle->flags & 1;
    return result;
}
#pragma opt_propagation off
static inline void delay(s32 n) {
    s32 j;
    j = 0;
    while (j < n) { j++; }
}

#pragma opt_propagation on
void fn_8005B264(Handle *handle, int enabled) {
    Handle *p;
    Handle *p8;
    Handle *p32;
    s32 i;
    s32 retry;
    s32 j;
    s32 count;
    char *messages = lbl_80092790;
    if (handle == 0) return;
    if (enabled == get_enabled(handle)) return;
    if (enabled == 1) {
        fn_8005A648();
        {
            for (i = 0; i < handle->count; i++) {
                handle->buffers[i]->interface->reset(handle->buffers[i]);
                memset(handle->field40[i], 0, 8);
                memset(handle->field50[i], 0, 8);
                memset(handle->fieldA8[i], 0, 32);
                handle->field60[i] = 0;
            }
        }
        handle->field68 = 0;
        handle->field6C = 0;
        handle->field78 = 0;
        handle->field7C = 0;
        handle->field4 = -1;
        handle->flags |= 1;
        fn_8005A628();
    } else if (enabled == 0) {
        for (i = 0; i < handle->count; i++) {
            for (retry = 0; retry < 200; retry++) {
                if (handle->field60[i] == 0) break;
                for (j = 0; j < 100000; j++) {}
            }
            if (retry == 200) {
                fn_8005A5BC((u32)(messages + 0x64));
                return;
            }
            for (retry = 0; retry < 200; retry++) {
                if (handle->field70[i] == 0) break;
                for (j = 0; j < 100000; j++) {}
            }
            if (retry == 200) {
                fn_8005A5BC((u32)(messages + 0x9C));
                return;
            }
        }
        handle->flags &= 2;
    } else {
        fn_8005A5BC((u32)(messages + 0xD4));
    }
}
