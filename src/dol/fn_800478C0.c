#include "types.h"
#pragma use_lmw_stmw on
#pragma opt_propagation on

struct Sig_fn_80048340_fn_80048340_stream;
struct Sig_fn_80048340_fn_80048340_block {
    /* Stream callbacks update the block pointer; preserve each observed read. */
    void *volatile ptr;
    s32 size;
};
typedef u32 (*FnA)(struct Sig_fn_80048340_fn_80048340_stream *, u32, u32, struct Sig_fn_80048340_fn_80048340_block *);
typedef u32 (*FnB)(struct Sig_fn_80048340_fn_80048340_stream *, u32, struct Sig_fn_80048340_fn_80048340_block *);
struct StreamVtable {
    u8 pad[0x18];
    FnA get;
    FnB put;
};
struct Sig_fn_80048340_fn_80048340_stream {
    struct StreamVtable *vtable;
};
struct Sig_fn_80048340_fn_80048340_data {
    s8 used;
    s8 state;
    u8 pad2[2];
    struct Sig_fn_80048340_fn_80048340_stream *streams[2];
    struct Sig_fn_80048340_fn_80048340_stream *stream;
    u8 pad10[0x1c];
    s32 total;
    u8 pad30[0x28];
    s32 channels;
    s32 rate;
    s32 unk60;
    s32 unk64;
    u8 pad68[0x18];
    void *outputs[2];
    s16 values[4];
    u8 pad90[0x238];
    s16 pending[4];
};
struct Output {
    u8 pad0[4];
    s16 first;
    s16 second;
    u8 pad8[0x80];
    struct Output *other;
};
extern s32 fn_80048340(struct Sig_fn_80048340_fn_80048340_data *, struct Sig_fn_80048340_fn_80048340_stream *);
extern void fn_80046D94(s16, s32, s16 *, s16 *);
extern void fn_80047A50(void *);

void fn_800478C0(struct Sig_fn_80048340_fn_80048340_data *arg) {
    s32 i;
    struct Sig_fn_80048340_fn_80048340_stream *stream;
    struct Sig_fn_80048340_fn_80048340_data *p;
    struct Sig_fn_80048340_fn_80048340_data *q;
    struct Sig_fn_80048340_fn_80048340_block block;
    s16 second, first;
    s32 count;
    struct Sig_fn_80048340_fn_80048340_data *encoder = arg;

    if (encoder->state == 1) {
        stream = encoder->stream;
        p = encoder;
        q = encoder;
        for (i = 0; i < encoder->channels; i++) {
            p->streams[0]->vtable->get(p->streams[0], 1, 2, &block);
            if (block.size == 0) break;
            q->pending[0] = q->pending[2] = *(s16 *)block.ptr;
            p->streams[0]->vtable->put(p->streams[0], 1, &block);
            p = (struct Sig_fn_80048340_fn_80048340_data *)((u8 *)p + 4);
            q = (struct Sig_fn_80048340_fn_80048340_data *)((u8 *)q + 2);
        }
        if (i < encoder->channels) return;
        {
            s32 j;
            for (j = 0; j < encoder->channels; j++) {
                encoder->values[j] = encoder->pending[j];
                encoder->values[j + 2] = encoder->pending[j + 2];
            }
        }
        count = fn_80048340(encoder, stream);
        if (count == 0) return;
        encoder->total += count;
        {
        struct Sig_fn_80048340_fn_80048340_data *r;
        s32 k;
        struct Output *output;
        r = encoder;
        for (k = 0; k < encoder->channels; r = (struct Sig_fn_80048340_fn_80048340_data *)((u8 *)r + 4)) {
            output = r->outputs[0];
            fn_80046D94((s16)encoder->unk64, encoder->rate, &first, &second);
            {
                s16 b = second;
                s16 a = first;
                struct Output *other;
                s16 c;
                k++;
                output->first = a;
                output->second = b;
                c = second;
                other = output->other;
                a = first;
                other->first = a;
                other->second = c;
            }
        }
        }
        encoder->state = 2;
    } else if (encoder->state == 2) {
        fn_80047A50(encoder);
    }
}
