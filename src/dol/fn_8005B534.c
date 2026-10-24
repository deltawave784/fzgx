#include "types.h"

typedef struct Sig_fn_8005B264_Buffer Sig_fn_8005B264_Buffer;
typedef struct Sig_RNARES_Create_RNAResource {
    int used;
    u32 buffer;
    u32 size;
} Sig_RNARES_Create_RNAResource;
typedef struct Sig_fn_8005B264_BufferInterface {
    u32 pad[5];
    void (*reset)(Sig_fn_8005B264_Buffer *);
} Sig_fn_8005B264_BufferInterface;
struct Sig_fn_8005B264_Buffer { Sig_fn_8005B264_BufferInterface *interface; };
typedef struct Sig_fn_8005B264_Handle {
    u8 used;
    u8 flags;
    s8 count2;
    s8 count;
    s32 field4;
    u8 pad8[0x30];
    Sig_fn_8005B264_Buffer *buffers[2];
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
} Sig_fn_8005B264_Handle;
struct Sig_fn_8005BE98_fn_8005BE98_Arg0 { u32 unk_0; };
struct Sig_fn_80026D70_fn_80026D70_Arg0 { u8 pad_0[0x18]; u32 unk_18; };
typedef struct { int unk00; int unk04; } Sig_fn_8005BE80_Fn8005BE80Object;
struct Sig_fn_80026EE0_fn_80026EE0_Arg0 { u8 pad_0[0x18]; u32 unk_18; };
typedef u32 (*fn_8005B534_Fn0)(u32, u32);
typedef u32 (*fn_8005B534_Fn1)(u32, u32);
typedef u32 (*fn_8005B534_Fn2)(u32, u32);
struct fn_8005B534_lbl_80191D4C_0_E232 {
    u8 pad_0[0x2];
    s8 unk_2;
    u8 unk_3;
    u8 pad_4[0x4];
    u32 unk_8;
    u32 unk_C;
    u32 resources[2];
    u32 resource_sizes[2];
    u32 unk_20;
    u32 unk_24;
    u32 voice_ids[2];
    u32 inputs[2];
    u32 buffers[2];
    u8 pad_40[0x40];
    u32 unk_80;
    u32 unk_84;
    u32 unk_88;
    u32 unk_8C;
    u32 unk_90;
    u32 unk_94;
    u32 unk_98;
    u32 unk_9C;
    s16 unk_A0;
    u16 unk_A2;
    u32 unk_A4;
    u8 pad_A8[0x40];
};
struct fn_8005B534_lbl_80191D4C { struct fn_8005B534_lbl_80191D4C_0_E232 unk_0[1]; };
struct fn_8005B534_lbl_8013255C { u8 pad_0[0x3C]; u32 unk_3C[1]; };

extern Sig_RNARES_Create_RNAResource *RNARES_Create(void);
extern int fn_8005BE80(Sig_fn_8005BE80_Fn8005BE80Object *);
extern u32 lbl_8013255C[31];
extern struct fn_8005B534_lbl_80191D4C_0_E232 lbl_80191D4C[16];
extern u32 fn_80020B3C(u32, u32, u32);
extern u32 fn_80026D70(struct Sig_fn_80026D70_fn_80026D70_Arg0 *);
extern u32 fn_80058498(u32, u32, u32);
extern u32 fn_8005B0C4(u32, u32);
extern u32 fn_8005BE68(u32);
extern u32 lbl_80132558[];
extern u32 lbl_80190C80[];
extern u8 lbl_80092790[];
extern void *memset(void *, int, u32);
extern void axrna_voice_drop(void *);
extern void fn_80020ABC(u32);
extern void fn_800230A4(void *, s32);
extern void fn_80023438(u32, u32);
extern void fn_80025EF4(void *, u32, s32, s32, s32, u32, u32, u32);
extern void fn_80026EE0(struct Sig_fn_80026EE0_fn_80026EE0_Arg0 *, s32);
extern void fn_8005A5BC(u32);
extern void fn_8005A628(void);
extern void fn_8005A648(void);
extern void fn_8005B264(Sig_fn_8005B264_Handle *, int);
extern void fn_8005BE98(struct Sig_fn_8005BE98_fn_8005BE98_Arg0 *);

typedef struct fn_8005B534_lbl_80191D4C_0_E232 Handle;
#define WORD(h, off) (((u32 *)(h))[(off) / 4])
#define CHWORD(h, off, ch) (((u32 *)(h))[(off) / 4 + (ch)])
#define COUNT(h) ((s8)(h)->unk_2)

static inline void Destroy(Handle *h) {
    Handle *p;
    int channel;
    u32 buffer, table;
    if (h == 0) return;
    fn_8005B0C4((u32)h, 0);
    fn_8005B264((Sig_fn_8005B264_Handle *)h, 0);
    p = h;
    for (channel = 0; channel < COUNT(h); channel++) {
        buffer = p->buffers[0];
        if (buffer != 0) {
            table = WORD(buffer, 0);
            ((fn_8005B534_Fn0)WORD(table, 0xC))(buffer, table);
        }
        if (p->resources[0] != 0)
            fn_8005BE98((struct Sig_fn_8005BE98_fn_8005BE98_Arg0 *)p->resources[0]);
        fn_8005A648();
        if (p->unk_8 != 0) {
            fn_80026D70((struct Sig_fn_80026D70_fn_80026D70_Arg0 *)p->unk_8);
            fn_80020ABC(p->unk_8);
        }
        fn_8005A628();
        p = (Handle *)((u8 *)p + 4);
    }
    memset(h, 0, sizeof(Handle));
}

static inline void SetMode(Handle *h, u32 mode) {
    if (h != 0) h->unk_A0 = mode;
}
static inline void SetA4(Handle *h, u32 value) {
    if (h != 0) {
        h->unk_A4 = value;
        h->unk_A2 = 1;
    }
}
static inline void SetFrequency(Handle *h, u32 frequency) {
    int channel;
    struct { Handle *ptr; } p;
    struct { u16 a[7]; } loc_8;
    if (h != 0) {
        h->unk_24 = frequency;
        p.ptr = h;
        for (channel = 0; channel < COUNT(h); channel++) {
            fn_8005A648();
            if (p.ptr->unk_8 != 0) {
                if ((s16)h->unk_A0 == 1) {
                    loc_8.a[0] = 1;
                    loc_8.a[1] = 0x7FA9;
                } else {
                    loc_8.a[0] = 1;
                    loc_8.a[1] = 0x8000;
                }
                loc_8.a[2] = 0;
                loc_8.a[3] = 0;
                loc_8.a[4] = 0;
                loc_8.a[5] = 0;
                loc_8.a[6] = 0;
                fn_800230A4((void *)p.ptr->unk_8, h->unk_A4);
                fn_80023438(p.ptr->unk_8, (u32)&loc_8);
            }
            fn_8005A628();
            p.ptr = (Handle *)((u8 *)p.ptr + 4);
        }
    }
}
#pragma opt_propagation off
static inline int PanMinimum(int a, int b) {
    return a < b ? a : b;
}
static inline int PanMaximum(int a, int b) {
    return b > a ? b : a;
}
static inline void SetPan(Handle *h, int channel, int pan) {
    int clamped;
    int upper;
    if (h != 0 && channel < COUNT(h)) {
        upper = pan < 15 ? pan : 15;
        clamped = upper > -15 ? (pan < 15 ? pan : 15) : -15;
        if (clamped != (s32)(&h->unk_88)[channel]) {
            (&h->unk_88)[channel] = clamped;
            fn_8005A648();
            if (CHWORD(h, 8, channel) != 0)
                fn_80026EE0((struct Sig_fn_80026EE0_fn_80026EE0_Arg0 *)CHWORD(h, 8, channel), lbl_8013255C[clamped + 15]);
            fn_8005A628();
        }
    }
}

#pragma opt_propagation off
#pragma opt_loop_invariants off
Handle *fn_8005B534(u32 *arg0, s32 arg1) {
    u8 *p_lbl_80092790;
    u32 slot;
    Handle *handle;
    struct { u32 value; } voice_id;
    u32 channel;
    struct { Handle *ptr; } resource;
    Handle *copy;
    s32 copy_channel;
    u32 *input;
    p_lbl_80092790 = lbl_80092790;
    if (arg1 <= 0) {
        fn_8005A5BC((u32)(p_lbl_80092790 + 0xF8));
        return 0;
    }
    if (arg0 == 0) {
        fn_8005A5BC((u32)(p_lbl_80092790 + 0x120));
        return 0;
    }
    input = arg0;
    for (channel = 0; channel < (u32)arg1; channel++) {
        if (*input == 0) {
            fn_8005A5BC((u32)(p_lbl_80092790 + 0x148));
            return 0;
        }
        input++;
    }
    copy = lbl_80191D4C;
    for (slot = 0; slot < 16; slot++) {
        if ((s8)*(u8 *)copy == 0) break;
        copy++;
    }
    if (slot == 16) {
        fn_8005A5BC((u32)(p_lbl_80092790 + 0x170));
        return 0;
    }
    handle = &lbl_80191D4C[slot];
    handle->unk_3 = arg1;
    handle->unk_2 = arg1;
    {
        copy = handle;
        copy_channel = 0;
        while (copy_channel < (u32)COUNT(handle)) {
            u32 input = *arg0;
            arg0++;
            copy_channel++;
            copy->inputs[0] = input;
            copy = (Handle *)((u8 *)copy + 4);
        }
    }
    handle->unk_84 = 0;
    handle->unk_90 = 127;
    handle->unk_94 = -999;
    handle->unk_98 = -999;
    handle->unk_9C = 0;
    voice_id.value = slot << 1;
    resource.ptr = handle;
    for (channel = 0; channel < (u32)COUNT(handle); channel++) {
        resource.ptr->voice_ids[0] = voice_id.value | 0x80000000;
        if ((resource.ptr->resources[0] = (u32)RNARES_Create()) == 0) {
            fn_8005A5BC((u32)(p_lbl_80092790 + 0x194));
            Destroy(handle);
            return 0;
        }
        resource.ptr->resource_sizes[0] = fn_8005BE80((Sig_fn_8005BE80_Fn8005BE80Object *)resource.ptr->resources[0]);
        handle->unk_20 = fn_8005BE68(resource.ptr->resources[0]);
        resource.ptr->buffers[0] = fn_80058498(resource.ptr->resource_sizes[0] << 1, handle->unk_20 << 1, 0);
        if (resource.ptr->buffers[0] == 0) {
            fn_8005A5BC((u32)(p_lbl_80092790 + 0x1B4));
            Destroy(handle);
            return 0;
        }
        if ((resource.ptr->unk_8 = fn_80020B3C(31, (u32)axrna_voice_drop, 0)) == 0) {
            fn_8005A5BC((u32)(p_lbl_80092790 + 0x1D0));
            Destroy(handle);
            return 0;
        }
        fn_8005A648();
        if (resource.ptr->unk_8 != 0) {
            fn_80025EF4((void *)resource.ptr->unk_8, 3, handle->unk_84,
                handle->unk_94, handle->unk_98, 64, handle->unk_90, handle->unk_9C);
        }
        fn_8005A628();
        voice_id.value++;
        resource.ptr = (Handle *)((u8 *)resource.ptr + 4);
    }
    SetMode(handle, lbl_80190C80[0]);
    SetA4(handle, lbl_80132558[0]);
    handle->unk_A2 = 0;
    SetFrequency(handle, 48000);
    if (handle != 0) handle->unk_80 = 16;
    if (handle->unk_2 == 2) {
        SetPan(handle, 0, -15);
        SetPan(handle, 1, 15);
    } else {
        SetPan(handle, 0, 0);
    }
    *((u8 *)handle + 1) = 0;
    *((u8 *)handle + 0) = 1;
    return handle;
}
#pragma opt_loop_invariants reset

