#include "types.h"

struct Sig_fn_800455B8_fn_800455B8_Arg1 { u16 type; };
typedef struct Sig_fn_8004559C_Fn8004559CObject {
    u8 pad[0x98];
    s16 value;
} Sig_fn_8004559C_Fn8004559CObject;
struct Buffer { struct Sig_fn_800455B8_fn_800455B8_Arg1 *data; s32 size; };
struct Stream;
struct VTable {
    u8 pad[0x18];
    void (*get)(struct Stream *, s32, s32, struct Buffer *);
    void (*release)(struct Stream *, s32, struct Buffer *);
    void (*put)(struct Stream *, s32, struct Buffer *);
};
struct Stream { struct VTable *vtable; };
struct fn_80041EF8_Arg0 {
    u8 pad_0;
    u8 unk_1;
    u8 pad_2;
    u8 unk_3;
    Sig_fn_8004559C_Fn8004559CObject *unk_4;
    struct Stream *unk_8;
    u8 pad_C[0x4C];
    u8 unk_58[0x40];
    s32 unk_98;
};
extern s32 fn_800455B8(void *, struct Sig_fn_800455B8_fn_800455B8_Arg1 *, s32);
extern char lbl_80090018[30];
extern char lbl_80090038[33];
extern void fn_80047464(char *, char *);
extern s32 fn_8004559C(Sig_fn_8004559C_Fn8004559CObject *);
extern void *memcpy(void *, const void *, u32);
extern u32 fn_800589BC(struct Buffer *, u32, struct Buffer *, struct Buffer *);

void fn_80041EF8(struct fn_80041EF8_Arg0 *arg0) {
    Sig_fn_8004559C_Fn8004559CObject *object;
    struct Stream *stream;
    s32 count;
    struct Buffer buffer;
    struct Buffer rest;
    struct fn_80041EF8_Arg0 *self = arg0;
    stream = self->unk_8;
    object = self->unk_4;
    stream->vtable->get(stream, 1, 0x1000, &buffer);
    if (buffer.size < 0x10) {
        stream->vtable->release(stream, 1, &buffer);
        return;
    }
    count = fn_800455B8(object, buffer.data, buffer.size);
    if (!count || count > buffer.size) {
        stream->vtable->release(stream, 1, &buffer);
        return;
    }
    if (count < 0) {
        stream->vtable->release(stream, 1, &buffer);
        fn_80047464(lbl_80090018, lbl_80090038);
        self->unk_1 = 4;
        return;
    }
    self->unk_98 = count;
    if (fn_8004559C(object) == 4) self->unk_3 = 1;
    if (fn_8004559C(object) == 2) {
        memcpy(self->unk_58, buffer.data, buffer.size < 0x40 ? buffer.size : 0x40);
    }
    {
        s32 type = fn_8004559C(object);
        if ((u32)(type - 10) <= 1 || type == 20 || type == 15) {
            stream->vtable->release(stream, 1, &buffer);
        } else {
            fn_800589BC(&buffer, count, &buffer, &rest);
            stream->vtable->put(stream, 0, &buffer);
            stream->vtable->release(stream, 1, &rest);
        }
    }
    self->unk_1 = 2;
}
