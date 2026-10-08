#include "types.h"
typedef struct Block { void *data; s32 size; } Block;
typedef struct Stream Stream;
typedef struct VTable {
    u8 pad[0x18];
    void (*get)(Stream *, int, int, Block *);
    void *unused;
    void (*put)(Stream *, int, Block *);
    int (*available)(Stream *, int);
} VTable;
struct Stream { VTable *vt; };
typedef struct Values { s32 channel, type, arg, v0c, v10, v14, v18, size; } Values;
typedef struct State {
    void *module;
    u8 pad[0x140];
    void (*callback)(void *, int);
    void *context;
} State;
typedef struct Movie { u8 pad[0x1aec]; void *state; } Movie;
extern int fn_12_683C(void *, Values *);
extern int fn_12_24A88(void *, int);
extern void *fn_12_57F0(void *, const void *, u32);
extern u32 lbl_12_bss_7E88;
extern int (*lbl_12_rodata_BC8[4])(void *, int, const void *, int, int);

static inline int transfer(Stream *stream, const void *src, int size) {
    Block second;
    Block first;
    int remain;
    if (stream->vt->available(stream, 0) < size) return 0;
    stream->vt->get(stream, 0, size, &first);
    fn_12_57F0(first.data, src, first.size);
    stream->vt->put(stream, 1, &first);
    if (first.size == 0) return 0;
    remain = size - first.size;
    src = (const u8 *)src + first.size;
    if (remain > 0) {
        stream->vt->get(stream, 0, remain, &second);
        fn_12_57F0(second.data, src, second.size);
        stream->vt->put(stream, 1, &second);
        if (second.size != remain) lbl_12_bss_7E88++;
    }
    return 1;
}
int fn_12_25FA8(Movie *movie, const void *src, int capacity, int *written, int *status) {
    Values values;
    void (*callback)(void *, int);
    void *context;
    int result = 0;
    State *state;
    int channel;
    int size;
    int type;
    int arg;
    int extra;
    Stream *stream;
    *written = 0;
    *status = 0;
    state = (State *)movie->state;
    if (fn_12_683C(*(void **)state, &values) != 0)
        result = fn_12_24A88(movie, 0xff000d06);
    size = values.size;
    channel = values.channel;
    type = values.type;
    arg = values.arg;
    extra = values.v14;
    if (size < 0) return fn_12_24A88(movie, 0xff000d0e);
    if (size == 0) {
        *written = 0;
        *status = 1;
        return 0;
    }
    if (capacity < size) return 0;
    stream = ((Stream **)((u8 *)state - 0x2bc))[channel];
    if (stream) {
        int success;
        context = state->context;
        callback = state->callback;
        success = transfer(stream, src, size);
        if (success == 1 && callback) callback(context, channel);
        *status = success;
    } else {
        *status = lbl_12_rodata_BC8[type](movie, arg, src, size, extra);
    }
    switch (*status) {
    case 1: *written = size; break;
    case 0: break;
    default: result = *status; break;
    }
    return result;
}
