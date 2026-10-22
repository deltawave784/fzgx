#include "types.h"
#include "rel/movie/globals.h"
extern u32 lbl_5_bss_0[8];
extern struct fn_5_200_lbl_1_bss_970 lbl_1_bss_970;
extern u32 fn_1_3CC4(u32);
extern u32 fn_1_407C(u32);
extern u32 fn_1_435C(u32);
extern const f32 lbl_5_rodata_0;
extern void fn_8006CE1C(f32);
extern void fn_1_3C78(void);
extern void fn_1_157940(void);
extern void fn_1_41A8(u32);
extern void fn_1_A0AA4(void);
extern void fn_1_47A60(u32);
extern void fn_800068F4(u32);
extern void fn_80006904(u32);
extern void fn_1_A5C98(void *);
extern s16 lbl_1_bss_962;
extern struct fn_5_320_lbl_5_data_40 lbl_5_data_40;
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;
extern u32 fn_1_412A0(u32);
extern u32 fn_1_48140(u32);
extern u8 lbl_5_bss_5F;
extern u8 lbl_5_bss_61;
extern u32 fn_5_3C44(void);
extern u8 lbl_5_bss_40;

/* fzgx:begin fn_5_200 */
struct fn_5_200_lbl_1_bss_970 {
    u32 unk_0;
};

void fn_5_200(void) {
    if ((s32) lbl_1_bss_970.unk_0 > 0) {
        lbl_1_bss_970.unk_0 -= 1;
    }
}
/* fzgx:end fn_5_200 */

/* fzgx:begin fn_5_220 */
struct fn_5_220_lbl_5_bss_0 {
    u8 pad_0[0x28];
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
};

void fn_5_220(void) {
    struct fn_5_220_lbl_5_bss_0 *p_lbl_5_bss_0;
    u32 t0, t2, t3, t5, t7;
    p_lbl_5_bss_0 = (struct fn_5_220_lbl_5_bss_0 *)&(*(struct fn_5_220_lbl_5_bss_0 *)&lbl_5_bss_0);
    t0 = fn_1_435C(p_lbl_5_bss_0->unk_28);
    fn_1_407C(t0);
    t2 = fn_1_435C(p_lbl_5_bss_0->unk_30);
    t3 = fn_1_407C(t2);
    fn_1_3CC4(t3);
    t5 = fn_1_435C(p_lbl_5_bss_0->unk_2C);
    fn_1_407C(t5);
    t7 = fn_1_435C(p_lbl_5_bss_0->unk_34);
    fn_1_407C(t7);
}
/* fzgx:end fn_5_220 */

/* fzgx:begin _epilog */
struct epilog_bss {
    u8 pad_0[0x20];
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u8 unk_38[1];
};

void _epilog(void) {
    struct epilog_bss *p;
    u32 t0;

    p = (struct epilog_bss *)&lbl_5_bss_0;
    fn_8006CE1C(lbl_5_rodata_0);
    fn_1_3C78();
    fn_1_157940();
    t0 = fn_1_435C(p->unk_28);
    fn_1_41A8(t0);
    t0 = fn_1_435C(p->unk_2C);
    fn_1_41A8(t0);
    t0 = fn_1_435C(p->unk_30);
    fn_1_41A8(t0);
    t0 = fn_1_435C(p->unk_34);
    fn_1_41A8(t0);
    fn_1_A0AA4();
    fn_1_47A60(8);
    fn_800068F4(p->unk_20);
    fn_80006904(p->unk_24);
    p->unk_20 = 0;
    p->unk_24 = 0;
    fn_1_A5C98(&p->unk_38);
}
/* fzgx:end _epilog */

/* fzgx:begin fn_5_320 */
typedef u32 (*fn_5_320_Fn0)(void);
struct fn_5_320_lbl_5_data_40_0_E44 {
    u8 pad_0[0x20];
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
};
struct fn_5_320_lbl_5_data_40 {
    struct fn_5_320_lbl_5_data_40_0_E44 unk_0[1];
};

void fn_5_320(void) {
    s32 i;
    struct fn_5_320_lbl_5_data_40_0_E44 *p;
    u32 v0;
    p = lbl_5_data_40.unk_0;
    i = lbl_1_bss_962;
    i -= 129;
    p += i;
    lbl_1_bss_71688 = p->unk_24;
    v0 = p->unk_28;
    lbl_1_bss_7168C = v0;
    ((fn_5_320_Fn0)p->unk_20)();
}
/* fzgx:end fn_5_320 */

/* fzgx:begin fn_5_4C8 pool noprologue */
#include "types.h"
#include "rel/movie/globals.h"

extern u32 fn_5_3C44(void);
extern void fn_1_FA650(void);
extern void fn_1_4A00(s32,u8,u32);
extern int fn_1_4C10(void);
extern s16 lbl_1_bss_964;
extern s16 lbl_1_bss_968;
struct Pad4C8 { u8 pad[8]; u16 buttons; u8 rest[10]; };
extern struct Pad4C8 lbl_1_bss_9F8[4];
struct Result4C8 { u8 pad[0x1c]; u32 flags; };
extern struct Result4C8 lbl_1_bss_58;
struct Movie4C8 {
 u8 pad0[0x2c]; u32 value; u8 pad30[0x10]; s8 state; u8 pad41[0x1f];
 s8 mask; u8 pad61; s8 controller; u8 pad63[3]; s8 toggle; s8 disabled;
};
#pragma opt_propagation off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_5_bss_0[8];
u32 lbl_5_bss_20[3];
u32 lbl_5_bss_20_C;
u32 lbl_5_bss_20_fill_30[4];
s8 lbl_5_bss_40;
u8 lbl_5_bss_40_fill_41;
u16 lbl_5_bss_40_fill_42;
u32 lbl_5_bss_40_fill_44[6];
u8 lbl_5_bss_40_fill_5C;
u8 lbl_5_bss_5D;
u8 lbl_5_bss_0_gap_5E;
u8 lbl_5_bss_5F;
s8 lbl_5_bss_0_gap_60;
u8 lbl_5_bss_61;
s8 lbl_5_bss_61_1;
u8 lbl_5_bss_61_fill_63;
u16 lbl_5_bss_61_fill_64;
s8 lbl_5_bss_61_5;
s8 lbl_5_bss_61_6;
u32 lbl_5_bss_61_fill_68[675];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_5_bss_0;
    s = *(u8 *)&lbl_5_bss_20;
    s = *(u8 *)&lbl_5_bss_20_C;
    s = *(u8 *)&lbl_5_bss_20_fill_30;
    s = *(u8 *)&lbl_5_bss_40;
    s = *(u8 *)&lbl_5_bss_40_fill_41;
    s = *(u8 *)&lbl_5_bss_40_fill_42;
    s = *(u8 *)&lbl_5_bss_40_fill_44;
    s = *(u8 *)&lbl_5_bss_40_fill_5C;
    s = *(u8 *)&lbl_5_bss_5D;
    s = *(u8 *)&lbl_5_bss_0_gap_5E;
    s = *(u8 *)&lbl_5_bss_5F;
    s = *(u8 *)&lbl_5_bss_0_gap_60;
    s = *(u8 *)&lbl_5_bss_61;
    s = *(u8 *)&lbl_5_bss_61_1;
    s = *(u8 *)&lbl_5_bss_61_fill_63;
    s = *(u8 *)&lbl_5_bss_61_fill_64;
    s = *(u8 *)&lbl_5_bss_61_5;
    s = *(u8 *)&lbl_5_bss_61_6;
    s = *(u8 *)&lbl_5_bss_61_fill_68;
}
#pragma section code_type ".text"

void fn_5_4C8(void) {
 u32 flags;
 s32 a,b,c,d;
 u16 buttons;
 u32 value;
 
 if (lbl_5_bss_40 == 1 || lbl_5_bss_40 == 0) {
  flags = 0;
  if (lbl_5_bss_61_6 == 1) {
   d=0; c=0; b=0; a=0;
  } else if (lbl_5_bss_61_1 >= 0 && lbl_5_bss_61_1 < 4) {
   u16 *base = &lbl_1_bss_9F8[0].buttons;
   buttons = base[lbl_5_bss_61_1 * 10];
   a=(buttons>>8)&1; b=(buttons>>9)&1; d=(buttons>>4)&1; c=(buttons>>12)&1;
  } else {
   buttons = lbl_1_bss_9F8[0].buttons;
   a=(buttons>>8)&1; b=(buttons>>9)&1; d=(buttons>>4)&1; c=(buttons>>12)&1;
  }
  if ((lbl_5_bss_0_gap_60 & 1) && a) flags |= 1;
  else if ((lbl_5_bss_0_gap_60 & 2) && b) flags |= 2;
  else if ((lbl_5_bss_0_gap_60 & 4) && c) flags |= 4;
  if (d) { lbl_5_bss_61_5 = !lbl_5_bss_61_5; fn_1_FA650(); }
  if (flags) { fn_5_3C44(); lbl_1_bss_58.flags = flags; }
 } else if (lbl_5_bss_40 == -1) {
  if (lbl_1_bss_964 == 15) {
   lbl_5_bss_40 = 2;
   value = lbl_5_bss_20_C;
   fn_1_4A00(0,15,value);
  } else fn_5_3C44();
 } else if (lbl_5_bss_40 == 2) {
  if (fn_1_4C10() == 0) fn_5_3C44();
 } else if (lbl_5_bss_40 != 0) {
  lbl_1_bss_968 = lbl_1_bss_964;
 }
}
/* fzgx:end fn_5_4C8 */

/* fzgx:begin fn_5_684 */
void fn_5_684(void) {
    if ((s8)lbl_5_bss_5F != 0) {
    fn_1_48140(154);
    fn_1_48140(155);
    fn_1_48140(147);
    fn_1_412A0(1);
    }
    if ((s8)lbl_5_bss_61 != 0) {
    fn_1_48140(1);
    }
}
/* fzgx:end fn_5_684 */

/* fzgx:begin fn_5_13B0 */
void fn_5_13B0(void) {
    if ((s8)lbl_5_bss_40 != -2) {
    fn_5_3C44();
    }
    fn_1_48140(154);
    fn_1_48140(155);
    fn_1_48140(147);
    fn_1_412A0(1);
}
/* fzgx:end fn_5_13B0 */

/* fzgx:begin fn_5_1404 */
extern u32 lbl_5_bss_0[8];
extern struct fn_5_200_lbl_1_bss_970 lbl_1_bss_970;
extern const f32 lbl_5_rodata_0;

struct fn_5_1404_sel {
    u8 pad_0[0x4];
    u8 unk_4;
};

struct fn_5_1404_state {
    u8 pad_0[0x48];
    u8 unk_48;
    u8 pad_49[0x5];
    s16 unk_4E;
    s16 unk_50;
    u8 pad_52[0x2];
    f32 unk_54;
    u8 pad_58[0x5];
    s8 unk_5D;
    s8 unk_5E;
    s8 unk_5F;
};

struct fn_5_1404_entry {
    u8 x;
    u8 y;
    s16 id;
    char name[0x40];
};

struct fn_5_1404_color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
};

extern u8 lbl_5_data_0[20];
extern void fn_1_49410(void);
extern void fn_1_49514(struct fn_5_1404_color *);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4965C(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4AE0C(const char *, ...);

/* Shared literal pool primer: earlier functions of the TU own the first pool
 * slots (0.0f, 1.0f, 0.1f, 8.0f, 0.5f and the int-to-float 2^52 constant).
 * mwld ignores .fzgxpool. */
extern void fzgx_pool_sink(f32);
extern void fzgx_pool_sink_d(f64);
#pragma section ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_pool_primer_fn_5_1404(void) {
    fzgx_pool_sink(0.0f);
    fzgx_pool_sink(1.0f);
    fzgx_pool_sink(0.1f);
    fzgx_pool_sink(8.0f);
    fzgx_pool_sink(0.5f);
    fzgx_pool_sink_d(4503601774854144.0);
}

#define SET_TEXT_COLOR(R, G, B, A) \
    { \
        struct fn_5_1404_color color = { R, G, B, A }; \
        fn_1_49514(&color); \
    }

void fn_5_1404(struct fn_5_1404_entry *list) {
    struct fn_5_1404_sel *sel;
    struct fn_5_1404_state *st;
    u8 *str;
    struct fn_5_1404_entry *e;
    s32 i;
    f32 fx;
    f32 fy;
    const char *name;
    const char *fmt;

    str = lbl_5_data_0;
    st = (struct fn_5_1404_state *)&lbl_5_bss_0;
    fn_1_49410();
    fn_1_4955C(0.5f, 0.5f);
    SET_TEXT_COLOR(0x80, 0xff, 0x80, 0xff);
    sel = (struct fn_5_1404_sel *)&lbl_1_bss_970;
    e = list;
    i = 0;
    while (e->id != -1) {
        fx = (f32)(e->x * 12 + 50);
        fy = (f32)(e->y * 12 + 50);
        fn_1_496FC(fx, fy);
        fn_1_4AE0C((const char *)(str + 0x1544), e->name);
        if (i == sel->unk_4) {
            fn_1_496FC(fx - 12.0f - 4.0f, fy);
            SET_TEXT_COLOR(0xff, 0x00, 0x00, 0xff);
            fn_1_4A0D8((const char *)(str + 0x1548));
            SET_TEXT_COLOR(0x80, 0xff, 0x80, 0xff);
        }
        e++;
        i++;
    }
    SET_TEXT_COLOR(0xff, 0xff, 0x80, 0xff);
    fn_1_496FC(80.0f, 360.0f);
    fn_1_4955C(0.6f, 0.6f);
    fn_1_4965C(2);
    fmt = (const char *)(str + 0x154c);
    name = (const char *)(str + 0x1578);
    if (st->unk_48 != 0) {
        name = (const char *)(str + 0x1574);
    }
    fn_1_4AE0C(fmt, name);
    fn_1_4AE0C((const char *)(str + 0x157c), st->unk_54);
    fn_1_4AE0C((const char *)(str + 0x15b4), st->unk_4E, st->unk_50);
    if (st->unk_5D == 5) {
        name = (const char *)(str + 0x15e8);
    } else if (st->unk_5D == 0) {
        name = (const char *)(str + 0x15f4);
    } else if (st->unk_5D == 1) {
        name = (const char *)(str + 0x1600);
    } else if (st->unk_5D == 2) {
        name = (const char *)(str + 0x160c);
    } else if (st->unk_5D == 3) {
        name = (const char *)(str + 0x1618);
    } else {
        name = (const char *)(str + 0x1630);
        if (st->unk_5D == 4) {
            name = (const char *)(str + 0x1624);
        }
    }
    fn_1_4AE0C((const char *)(str + 0x1634), name);
    fmt = (const char *)(str + 0x1654);
    name = (const char *)(str + 0x1578);
    if (st->unk_5E != 0) {
        name = (const char *)(str + 0x1574);
    }
    fn_1_4AE0C(fmt, name);
    fmt = (const char *)(str + 0x1678);
    name = (const char *)(str + 0x1578);
    if (st->unk_5F != 0) {
        name = (const char *)(str + 0x1574);
    }
    fn_1_4AE0C(fmt, name);
}
/* fzgx:end fn_5_1404 */

/* fzgx:begin fn_5_20FC pool */
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef float f32;

 /* 'OVERTAKE' */
/* lbl_1_bss_6EAB4: .bss size 0x12, referenced by 21 functions, shape {'object': 69} */
typedef struct {
u32 unk_0; /* 43 loads, 26 stores */
u8 pad_4[0xE];
} Obj_1_bss_6EAB4;
extern Obj_1_bss_6EAB4 lbl_1_bss_6EAB4;

/* lbl_1_bss_6EAD0: .bss size 0x708, 6 refs from game.c */
/* one layout for every TU header that declares this symbol (librarian, typedefs.json) */
typedef struct {
u32 unk_0; /* 23 loads, 0 stores */
u32 unk_4; /* 9 loads, 0 stores */
} Obj_1_bss_6EAD0_At0;
typedef struct {
Obj_1_bss_6EAD0_At0 *unk_0; /* 34 loads, 0 stores */
u8 pad_4[0x704];
} Obj_1_bss_6EAD0;
extern Obj_1_bss_6EAD0 lbl_1_bss_6EAD0;

/* ARAM DMA request queue (ARQ), Dolphin SDK names. */
/* Compile-time layout checks for owned types. They declare array typedefs
 * only, so they emit no code or data under MWCC: a wrong size or offset is
 * a negative array bound and fails the compile. */
typedef void (*ARQCallback)(u32 pointerToARQRequest);
typedef struct ARQRequest {
struct ARQRequest *next;
u32 owner;
u32 type;
u32 priority;
u32 source;
u32 dest;
u32 length;
ARQCallback callback;
} ARQRequest;

/* The ADXT handle layout recovered from ADXT_Stop's accesses (signature types), shared by game.c and */
/* live_camera.c, which carried identical copies. Hand-owned (librarian). */
typedef struct Sig_ADXT_Stop_AdxSjdHandle Sig_ADXT_Stop_AdxSjdHandle;
typedef struct Sig_ADXT_Stop_ADXStream Sig_ADXT_Stop_ADXStream;
typedef struct Sig_ADXT_Stop_AXRNAHandle Sig_ADXT_Stop_AXRNAHandle;
typedef struct Sig_ADXT_Stop_SJCK {
unsigned char *data;
int len;
} Sig_ADXT_Stop_SJCK;
typedef void (*Sig_ADXT_Stop_SJErrorCallback)(void *object, int error);
typedef struct Sig_ADXT_Stop_SJInterface Sig_ADXT_Stop_SJInterface;
typedef struct Sig_ADXT_Stop_SJ Sig_ADXT_Stop_SJ;
struct Sig_ADXT_Stop_SJInterface {
void *reserved[3];
void (*destroy)(Sig_ADXT_Stop_SJ *sj);
const void *(*get_uuid)(Sig_ADXT_Stop_SJ *sj);
void (*reset)(Sig_ADXT_Stop_SJ *sj);
void (*get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int max_size, Sig_ADXT_Stop_SJCK *chunk);
void (*unget_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
void (*put_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
int (*get_num_data)(Sig_ADXT_Stop_SJ *sj, int channel);
int (*is_get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int size, int *available);
void (*entry_error_func)(Sig_ADXT_Stop_SJ *sj, Sig_ADXT_Stop_SJErrorCallback callback, void *object);
};
struct Sig_ADXT_Stop_SJ {
const Sig_ADXT_Stop_SJInterface *interface;
};
typedef struct Sig_ADXT_Stop_ADX_AMP Sig_ADXT_Stop_ADX_AMP;
typedef struct Sig_ADXT_Stop_LSCObject Sig_ADXT_Stop_LSCObject;
typedef struct Sig_ADXT_Stop_ADXTHandle {
s8 used;
s8 status;
s8 stream_type;
s8 maximum_channels;
Sig_ADXT_Stop_AdxSjdHandle *decoder;
Sig_ADXT_Stop_ADXStream *stream;
Sig_ADXT_Stop_AXRNAHandle *rna;
Sig_ADXT_Stop_SJ *stream_sj;
Sig_ADXT_Stop_SJ *input_sj;
Sig_ADXT_Stop_SJ *output_sj[2];
u8 *input_buffer;
s32 input_buffer_size;
s32 input_extra_size;
u8 *output_buffer;
s32 output_buffer_size;
s32 output_buffer_distance;
s32 server_frequency;
s16 stream_buffer_sectors;
s16 minimum_buffer_sectors;
s16 output_volume;
s16 output_pan[2];
s16 field_46;
s32 maximum_decode_samples;
s32 loop_count;
s32 link_data_length;
s32 field_54;
s32 field_58;
s32 field_5C;
s16 error_code;
u8 reserved_62[2];
s32 field_64;
s16 field_68;
s16 field_6A;
s8 stream_loop_enabled;
s8 auto_receiver;
u8 reserved_6E[2];
s8 suppress_playback;
s8 decoder_ready;
s8 paused;
u8 reserved_73;
Sig_ADXT_Stop_ADX_AMP *amplifier;
Sig_ADXT_Stop_SJ *amplifier_input[2];
Sig_ADXT_Stop_SJ *amplifier_output[2];
s32 time_offset;
s32 eos_sector;
s32 loop_sample_count;
Sig_ADXT_Stop_LSCObject *linked_stream_controller;
s8 link_enabled;
u8 reserved_99[3];
u32 playback_time;
s32 playback_start_vsync;
s32 linked_decoded_samples;
s8 pending_stream_start;
u8 reserved_A9[3];
u8 *work_end;
const char *pending_filename;
void *pending_directory;
s32 pending_file_offset;
s32 pending_file_sectors;
} Sig_ADXT_Stop_ADXTHandle;
/* CRI ADX talker (ADXT) handle, shared by the ADXT_* / adxt_* units of the DOL. */
typedef struct SJCK {
unsigned char *data;
int len;
} SJCK;
typedef struct SJ SJ;
typedef struct SJInterface SJInterface;
typedef void (*SJErrorCallback)(void *object, int error);
struct SJInterface {
void *reserved[3];
void (*destroy)(SJ *sj);
const void *(*get_uuid)(SJ *sj);
void (*reset)(SJ *sj);
void (*get_chunk)(SJ *sj, int channel, int max_size, SJCK *chunk);
void (*unget_chunk)(SJ *sj, int channel, SJCK *chunk);
void (*put_chunk)(SJ *sj, int channel, SJCK *chunk);
int (*get_num_data)(SJ *sj, int channel);
int (*is_get_chunk)(SJ *sj, int channel, int size, int *available);
void (*entry_error_func)(SJ *sj, SJErrorCallback callback, void *object);
};
struct SJ {
const SJInterface *interface;
};
typedef struct AdxSjdHandle AdxSjdHandle;
typedef struct ADXStream ADXStream;
typedef struct AXRNAHandle AXRNAHandle;
typedef struct LSCObject LSCObject;
typedef struct ADX_AMP ADX_AMP;
typedef struct ADXTHandle {
s8 used;
s8 status;
s8 stream_type;
s8 maximum_channels;
AdxSjdHandle *decoder;
ADXStream *stream;
AXRNAHandle *rna;
SJ *stream_sj;
SJ *input_sj;
SJ *output_sj[2];
u8 *input_buffer;
s32 input_buffer_size;
s32 input_extra_size;
u8 *output_buffer;
s32 output_buffer_size;
s32 output_buffer_distance;
s32 server_frequency;
s16 stream_buffer_sectors;
s16 minimum_buffer_sectors;
s16 output_volume;
s16 output_pan[2];
s16 field_46;
s32 maximum_decode_samples;
s32 loop_count;
s32 link_data_length;
s32 field_54;
s32 field_58;
s32 field_5C;
s16 error_code;
u8 reserved_62[2];
s32 field_64;
s16 field_68;
s16 field_6A;
s8 stream_loop_enabled;
s8 auto_receiver;
u8 reserved_6E[2];
s8 suppress_playback;
s8 decoder_ready;
s8 paused;
u8 reserved_73;
ADX_AMP *amplifier;
SJ *amplifier_input[2];
SJ *amplifier_output[2];
s32 time_offset;
s32 eos_sector;
s32 loop_sample_count;
LSCObject *linked_stream_controller;
s8 link_enabled;
u8 reserved_99[3];
u32 playback_time;
s32 playback_start_vsync;
s32 linked_decoded_samples;
s8 pending_stream_start;
u8 reserved_A9[3];
u8 *work_end;
const char *pending_filename;
void *pending_directory;
s32 pending_file_offset;
s32 pending_file_sectors;
} ADXTHandle;

struct Movie20Obj;
struct Movie20Vtable {
u8 pad_0[0x18];
void (*start)(struct Movie20Obj *, void *);
u8 pad_1C[4];
s32 (*state)(struct Movie20Obj *);
u8 pad_24[8];
void (*volume)(struct Movie20Obj *, s32);
};
struct Movie20Obj { struct Movie20Vtable *vt; };
struct Movie20Command { s16 type, arg, duration; };
struct Movie20Frame {
u32 valid;
u8 pad_4[0x18];
s32 rate;
u8 pad_20[0x10];
s32 frame;
u8 pad_34[0x18];
};
struct Movie20Display {
u8 pad_0[4];
s16 width, height, x, y;
f32 scaleX, scaleY;
};
struct Sig_fn_5_3E74_fn_5_3E74_Arg0 {
s32 unk_0;
s32 unk_4;
s32 unk_8;
s32 unk_C;
u8 unk_10[0x100];
};
struct Sig_fn_80036058_fn_80036058_Arg0 {
u8 pad_0[0xC];
u32 unk_C;
};
extern u8 fn_1_12B4__fzgx_offset_0[];
extern u8 fn_1_12FC__fzgx_offset_0[];
extern u8 fn_1_1300__fzgx_offset_0[];
extern u8 fn_5_13B0__fzgx_offset_0[];
extern u8 fn_5_37C__fzgx_offset_0[];
extern u8 fn_5_4C8__fzgx_offset_0[];
extern u8 fn_5_684__fzgx_offset_0[];
extern u8 fn_5_6E8__fzgx_offset_0[];
extern u8 fn_5_7A0__fzgx_offset_0[];
extern u8 fn_5_7A0__fzgx_offset_474[];
extern u8 fn_5_7A0__fzgx_offset_488[];
extern u8 fn_5_7A0__fzgx_offset_49C[];
extern u8 fn_5_7A0__fzgx_offset_4B0[];
extern u8 fn_5_7A0__fzgx_offset_4C4[];
extern u8 fn_5_7A0__fzgx_offset_4D8[];
extern u8 fn_5_7A0__fzgx_offset_4EC[];
extern u8 fn_5_7A0__fzgx_offset_500[];
extern u8 fn_5_7A0__fzgx_offset_514[];
extern u8 fn_5_7A0__fzgx_offset_528[];
extern u8 fn_5_7A0__fzgx_offset_53C[];
extern u8 fn_5_7A0__fzgx_offset_550[];
extern u8 fn_5_7A0__fzgx_offset_564[];
extern u8 fn_5_7A0__fzgx_offset_578[];
extern u8 fn_5_7A0__fzgx_offset_58C[];
extern u8 fn_5_7A0__fzgx_offset_5A0[];
extern u8 fn_5_7A0__fzgx_offset_5B4[];
extern u8 fn_5_7A0__fzgx_offset_5C8[];
extern u8 fn_5_7A0__fzgx_offset_5DC[];
extern u8 fn_5_7A0__fzgx_offset_640[];
extern u8 fn_5_7A0__fzgx_offset_8A8[];
extern u8 fn_5_7A0__fzgx_offset_9A0[];
extern u8 fn_5_7A0__fzgx_offset_BD0[];
static u32 fzgx_pool_data_lbl_5_data_0[1361] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x2E4019A, 0x1F401FE, 0x2DA0140, 0x28003CA, 0x2D00000, 0x6D6F7669, 0x652E6300, 0x54455354,
    0x4D4F4445, 0x0, 0x667A652E, 0x6D6F7669, 0x655F6D6F, 0x64756C65, 0x2E72656C, 0x0,
    0x534D445F, 0x4D4F5649, 0x455F544F, 0x50000000, 0x0, 0x0, 0x0, 0x0,
    (u32)fn_1_12B4__fzgx_offset_0, (u32)fn_1_12FC__fzgx_offset_0, (u32)fn_1_1300__fzgx_offset_0, 0x534D445F, 0x4D4F5649, 0x455F5445, 0x53540000, 0x0,
    0x0, 0x0, 0x0, (u32)fn_5_6E8__fzgx_offset_0, (u32)fn_5_7A0__fzgx_offset_0, (u32)fn_5_13B0__fzgx_offset_0, 0x534D445F, 0x4D4F5649,
    0x455F4D50, 0x45470000, 0x0, 0x0, 0x0, 0x0, (u32)fn_5_37C__fzgx_offset_0, (u32)fn_5_4C8__fzgx_offset_0,
    (u32)fn_5_684__fzgx_offset_0, 0x534D445F, 0x4D4F5649, 0x455F424F, 0x54544F4D, 0x0, 0x0, 0x0,
    0x0, (u32)fn_1_12B4__fzgx_offset_0, (u32)fn_1_12FC__fzgx_offset_0, (u32)fn_1_1300__fzgx_offset_0, 0x2000003, 0x81458376, 0x838D838D, 0x815B834F,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x2010004, 0x81458356, 0x8369838A,  /* fzgx-allow: A1 retail data bytes */
    0x83498140, 0x82504100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2020005, 0x81458356,  /* fzgx-allow: A1 retail data bytes */
    0x8369838A, 0x83498140, 0x82504200, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2030006,
    0x81458356, 0x8369838A, 0x83498140, 0x82514100, 0x0, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2040007, 0x81458356, 0x8369838A, 0x83498140, 0x82514200, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x2050008, 0x81458356, 0x8369838A, 0x83498140, 0x82524100, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x2060009, 0x81458356, 0x8369838A, 0x83498140, 0x82524200, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x207000A, 0x81458356, 0x8369838A, 0x83498140, 0x82534100,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x208000B, 0x81458356, 0x8369838A, 0x83498140,  /* fzgx-allow: A1 retail data bytes */
    0x82534200, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x209000C, 0x81458356, 0x8369838A,  /* fzgx-allow: A1 retail data bytes */
    0x83498140, 0x82544100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x20A000D, 0x81458356,  /* fzgx-allow: A1 retail data bytes */
    0x8369838A, 0x83498140, 0x82544200, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x20B000E,
    0x81458356, 0x8369838A, 0x83498140, 0x82554100, 0x0, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x20C000F, 0x81458356, 0x8369838A, 0x83498140, 0x82554200, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x20D0010, 0x81458356, 0x8369838A, 0x83498140, 0x82564100, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x20E0011, 0x81458356, 0x8369838A, 0x83498140, 0x82564200, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x20F0012, 0x81458356, 0x8369838A, 0x83498140, 0x82574100,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x2100013, 0x81458356, 0x8369838A, 0x83498140,  /* fzgx-allow: A1 retail data bytes */
    0x82574200, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x2110014, 0x81458356, 0x8369838A,  /* fzgx-allow: A1 retail data bytes */
    0x83498140, 0x82584100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2120015, 0x81458356,  /* fzgx-allow: A1 retail data bytes */
    0x8369838A, 0x83498140, 0x82584200, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x213001E,
    0x81458347, 0x83938366, 0x83428393, 0x834F0000, 0x0, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x214001F, 0x8145834C, 0x83838376, 0x83608383, 0x815B8365, 0x83588367, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xE000028, 0x81454529, 0x83668358, 0x837B815B, 0x83930000, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xE010029, 0x81454529, 0x837D8343, 0x83658342, 0x815B834B, 0x835B838B,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xE02002A, 0x81454529, 0x83578387, 0x83668342, 0x815B8354,  /* fzgx-allow: A1 retail data bytes */
    0x837D815B, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xE03002B, 0x81454529, 0x8368834E, 0x835E815B,  /* fzgx-allow: A1 retail data bytes */
    0x83588360, 0x8385838F, 0x815B8367, 0x0, 0x0, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0xE04002C, 0x81454529, 0x836F836F,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xE05002D, 0x81454529,  /* fzgx-allow: A1 retail data bytes */
    0x83548380, 0x83898343, 0x8353838D, 0x815B0000, 0x0, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xE06002E,
    0x81454529, 0x83738352, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xE07002F, 0x81454529, 0x834C8383, 0x83768365, 0x83938374, 0x8340838B, 0x83528393, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xE080030, 0x81454529, 0x8349834E, 0x8367837D, 0x83930000, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xE090031, 0x81454529, 0x4D722E45, 0x41440000, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xE0A0032, 0x81454529, 0x83578346, 0x815B8380, 0x8358837D,  /* fzgx-allow: A1 retail data bytes */
    0x834E8389, 0x83458368, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xE0B0033, 0x81454529, 0x8372838A, 0x815B0000,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xE0C0034, 0x81454529, 0x83508343,  /* fzgx-allow: A1 retail data bytes */
    0x83678341, 0x838C8393, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xE0D0035, 0x81454529,  /* fzgx-allow: A1 retail data bytes */
    0x835D815B, 0x835F0000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xE0E0036,
    0x81454529, 0x83578383, 0x8362834E, 0x838C8372, 0x83930000, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xE0F0037, 0x81454529, 0x836F8343, 0x8349838C, 0x8362834E, 0x83580000, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xE100038, 0x81454529, 0x83558145, 0x8358834A, 0x838B0000, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xE110039, 0x81454529, 0x83418393, 0x8367836A, 0x8349834B, 0x8358835E,  /* fzgx-allow: A1 retail data bytes */
    0x815B0000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0xE12003A, 0x81454529, 0x8372815B, 0x83588367, 0x837D8393,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xE13003B, 0x81454529, 0x838C8349, 0x83930000,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xE14003C, 0x81454529, 0x8358815B,  /* fzgx-allow: A1 retail data bytes */
    0x8370815B, 0x8341838D, 0x815B0000, 0x0, 0x0, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1E00003D, 0x81454529,  /* fzgx-allow: A1 retail data bytes */
    0x837E835A, 0x83588341, 0x838D815B, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1E01003E,
    0x81454529, 0x8353837D, 0x815B8195, 0x83568349, 0x815B0000, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x1E02003F, 0x81454529, 0x8356838B, 0x836F815B, 0x836A815B, 0x838B835A, 0x83930000, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x1E030040, 0x81454529, 0x837D8343, 0x8350838B, 0x83608346, 0x815B8393, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1E040041, 0x81454529, 0x83758389, 0x83628368, 0x83748340, 0x838B8352,  /* fzgx-allow: A1 retail data bytes */
    0x83930000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1E050042, 0x81454529, 0x83578387, 0x8393835E, 0x8369834A,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1E060043, 0x81454529, 0x83688389, 0x834E0000,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1E070044, 0x81454529, 0x838D8357,  /* fzgx-allow: A1 retail data bytes */
    0x8383815B, 0x836F8358, 0x835E815B, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1E080045, 0x81454529,  /* fzgx-allow: A1 retail data bytes */
    0x8368834E, 0x835E815B, 0x834E8389, 0x83628356, 0x83850000, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1E090046,
    0x81454529, 0x83758389, 0x8362834E, 0x83568383, 0x8368815B, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x1E0A0047, 0x81454529, 0x83688393, 0x8357815B, 0x836A815B, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x1E0B0048, 0x81454529, 0x83668357, 0x837B815B, 0x83430000, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1E0C0049, 0x81454529, 0x835F8343, 0x83548393, 0x83518393, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1E0D004A, 0x81454529, 0x83588379, 0x815B8368, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1E0E004B, 0x81454529, 0x835F8343, 0x8353838D,  /* fzgx-allow: A1 retail data bytes */
    0x815B0000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1E0F004C, 0x81454529, 0x8376838A,  /* fzgx-allow: A1 retail data bytes */
    0x83938356, 0x83418389, 0x8382815B, 0x83680000, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1E10004D, 0x81454529,  /* fzgx-allow: A1 retail data bytes */
    0x838A838A, 0x815B8374, 0x83898343, 0x8384815B, 0x0, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1E11004E,
    0x81454529, 0x504A0000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x1E12004F, 0x81454529, 0x51515100, 0x0, 0x0, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x1E130050, 0x81454529, 0x83748346, 0x836A8362, 0x834E8358, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xFFFF, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x6D6F7669, 0x652F7374, 0x6F727930, 0x30000000, 0x6D6F7669,
    0x652F7374, 0x6F727930, 0x31410000, 0x6D6F7669, 0x652F7374, 0x6F727930, 0x31420000, 0x6D6F7669,
    0x652F7374, 0x6F727930, 0x32410000, 0x6D6F7669, 0x652F7374, 0x6F727930, 0x32420000, 0x6D6F7669,
    0x652F7374, 0x6F727930, 0x33410000, 0x6D6F7669, 0x652F7374, 0x6F727930, 0x33420000, 0x6D6F7669,
    0x652F7374, 0x6F727930, 0x34410000, 0x6D6F7669, 0x652F7374, 0x6F727930, 0x34420000, 0x6D6F7669,
    0x652F7374, 0x6F727930, 0x35410000, 0x6D6F7669, 0x652F7374, 0x6F727930, 0x35420000, 0x6D6F7669,
    0x652F7374, 0x6F727930, 0x36410000, 0x6D6F7669, 0x652F7374, 0x6F727930, 0x36420000, 0x6D6F7669,
    0x652F7374, 0x6F727930, 0x37410000, 0x6D6F7669, 0x652F7374, 0x6F727930, 0x37420000, 0x6D6F7669,
    0x652F7374, 0x6F727930, 0x38410000, 0x6D6F7669, 0x652F7374, 0x6F727930, 0x38420000, 0x6D6F7669,
    0x652F7374, 0x6F727930, 0x39410000, 0x6D6F7669, 0x652F7374, 0x6F727930, 0x39420000, 0x656E6400,
    0x4D41584F, 0x4E000000, 0x42474D45, 0x44000000, 0x5354524C, 0x0, 0x4D41584F, 0x46460000,
    0x57414954, 0x5F303130, 0x30000000, 0x43555430, 0x30313000, 0x43555430, 0x31343000, 0x43555430,
    0x30363500, 0x43555430, 0x30373000, 0x43555430, 0x30383000, 0x43555431, 0x31393000, 0x43555430,
    0x30303000, 0x42474D4F, 0x555F3035, 0x30305F30, 0x35303000, 0x57414954, 0x5F313230, 0x30000000,
    0x43415030, 0x315F3039, 0x30300000, 0x43415030, 0x325F3039, 0x30300000, 0x43415030, 0x335F3039,
    0x30300000, 0x43415030, 0x345F3039, 0x30300000, 0x43415030, 0x355F3039, 0x30300000, 0x43415030,
    0x365F3039, 0x30300000, 0x57414954, 0x5F303230, 0x30000000, 0x424D5025, 0x3032645F, 0x30333030,
    0x0, 0x42474D49, 0x4E4D3031, 0x32305F30, 0x32343000, 0x6D6F7669, 0x652F656E, 0x64696E67,
    0x2F257300, 0x5354524C, 0x57414954, 0x0, 0x42474D4F, 0x555F3032, 0x30305F30, 0x35303000,
    0x57414954, 0x5F303630, 0x30000000, (u32)fn_5_7A0__fzgx_offset_474, (u32)fn_5_7A0__fzgx_offset_488, (u32)fn_5_7A0__fzgx_offset_49C, (u32)fn_5_7A0__fzgx_offset_4B0, (u32)fn_5_7A0__fzgx_offset_4C4,
    (u32)fn_5_7A0__fzgx_offset_4D8, (u32)fn_5_7A0__fzgx_offset_4EC, (u32)fn_5_7A0__fzgx_offset_500, (u32)fn_5_7A0__fzgx_offset_514, (u32)fn_5_7A0__fzgx_offset_528, (u32)fn_5_7A0__fzgx_offset_53C, (u32)fn_5_7A0__fzgx_offset_550, (u32)fn_5_7A0__fzgx_offset_564,
    (u32)fn_5_7A0__fzgx_offset_578, (u32)fn_5_7A0__fzgx_offset_58C, (u32)fn_5_7A0__fzgx_offset_5A0, (u32)fn_5_7A0__fzgx_offset_5B4, (u32)fn_5_7A0__fzgx_offset_5C8, (u32)fn_5_7A0__fzgx_offset_5DC, (u32)fn_5_7A0__fzgx_offset_BD0, (u32)fn_5_7A0__fzgx_offset_BD0,
    (u32)fn_5_7A0__fzgx_offset_BD0, (u32)fn_5_7A0__fzgx_offset_BD0, (u32)fn_5_7A0__fzgx_offset_BD0, (u32)fn_5_7A0__fzgx_offset_BD0, (u32)fn_5_7A0__fzgx_offset_BD0, (u32)fn_5_7A0__fzgx_offset_BD0, (u32)fn_5_7A0__fzgx_offset_640, (u32)fn_5_7A0__fzgx_offset_8A8,
    (u32)fn_5_7A0__fzgx_offset_BD0, (u32)fn_5_7A0__fzgx_offset_BD0, (u32)fn_5_7A0__fzgx_offset_BD0, (u32)fn_5_7A0__fzgx_offset_BD0, (u32)fn_5_7A0__fzgx_offset_BD0, (u32)fn_5_7A0__fzgx_offset_BD0, (u32)fn_5_7A0__fzgx_offset_BD0, (u32)fn_5_7A0__fzgx_offset_BD0,
    (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0,
    (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0,
    (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0,
    (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0,
    (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0, (u32)fn_5_7A0__fzgx_offset_9A0,
    (u32)fn_5_7A0__fzgx_offset_9A0
};
static u32 fzgx_pool_data_lbl_5_data_1544[117] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x25730000, 0x81840000, 0x83668374, 0x838A8362, 0x834A815B, 0x203A2025, 0x2D337320, 0x20202020,
    0x28204348, 0x414E4745, 0x3A582029, 0xA000000, 0x4F4E0000, 0x4F464600, 0x83588350, 0x815B838B,  /* fzgx-allow: A1 retail data bytes */
    0x2020203A, 0x2025332E, 0x31662020, 0x20202028, 0x20434841, 0x4E47453A, 0x4C836783, 0x8A834B81,
    0x5B2B8370, 0x83628368, 0x55442029, 0xA000000, 0x837C8357, 0x83568387, 0x83932020, 0x3A202533,
    0x642C2533, 0x64202820, 0x4348414E, 0x47453A52, 0x8367838A, 0x834B815B, 0x2B837083, 0x62836820,
    0x290A0000, 0x4A415041, 0x4E455345, 0x0, 0x454E474C, 0x49534820, 0x0, 0x4745524D,
    0x414E2020, 0x0, 0x4652454E, 0x43482020, 0x0, 0x5350414E, 0x49534820, 0x0,
    0x4954414C, 0x49414E20, 0x0, 0x0, 0x82B082F1, 0x82B22020, 0x20203A20, 0x25387328,
    0x20434841, 0x4E47453A, 0x5A20290A, 0x0, 0x82D382E8, 0x82AA82C8, 0x2020203A, 0x20252D33,
    0x73202020, 0x20202820, 0x4348414E, 0x47453A59, 0x20290A00, 0x94778C69, 0x20202020, 0x203A2025,
    0x2D337320, 0x20202020, 0x28204348, 0x414E4745, 0x3A4C2029, 0xA000000, 0x43555400, 0x4D415800,
    0x57414954, 0x5F000000, 0x424D5000, 0x43415000, 0x42474D00, 0x42474D49, 0x4E4D0000, 0x42474D49,
    0x4E000000, 0x42474D4F, 0x55000000, 0x25732E73, 0x66640000, 0x25732573, 0x2E747874, 0x0,
    0x51410000, 0x6D6F7669, 0x655F6D70, 0x65675F70, 0x6C61795F, 0x6D61696E, 0x0, 0x6D6F7669,
    0x655F6D70, 0x65675F70, 0x6C61795F, 0x64697370, 0x0
};
static u32 fzgx_pool_data_lbl_5_data_0_1718[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x53746166, 0x66526F6C, 0x6C4D6169, 0x6E000000
};
static u32 fzgx_pool_data_lbl_5_data_0_1728[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x53746166, 0x66526F6C, 0x6C446973, 0x70000000
};
#pragma section code_type ".fzgxpool"
#pragma section code_type ".text"

extern struct Movie20Display lbl_1_bss_58;
extern struct fn_5_200_lbl_1_bss_970 lbl_1_bss_970;
extern void (*lbl_1_bss_184)(struct Movie20Obj *, struct Movie20Frame *);
extern void (*lbl_1_bss_E4)(struct Movie20Obj *, struct Movie20Frame *, u32, u32);
extern void (*lbl_1_bss_180)(struct Movie20Obj *);
extern s32 (*lbl_1_bss_170)(struct Movie20Obj *);
extern void fn_5_3E54(u32);
extern u32 fn_5_3E74(struct Sig_fn_5_3E74_fn_5_3E74_Arg0 *);
extern void fn_5_3BF8(void);
extern f32 fn_1_1577D0(u32, u32, f32);
extern u32 fn_1_435C(u32);
extern s32 fn_1_3F8C(u32, u32, u32, u32);
extern void fn_1_157820(void);
extern void fn_1_1578C4(void);
extern void DCInvalidateRange(void *, u32);
extern void ARQPostRequest(ARQRequest *, u32, u32, u32, u32, u32, u32, ARQCallback);
extern void GXInvalidateTexAll(void);
extern u32 fn_1_A1588(Sig_ADXT_Stop_ADXTHandle *, u32);
extern void ADXT_Pause(ADXTHandle *, s32);
extern s32 fn_1_157930(void);
extern s32 fn_1_A5DC4(void);
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_495B0(u32);
extern void fn_1_4965C(u8);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495C8(u8);
extern void fn_1_49590(f32);
extern u32 fn_1_4AEE8(u32);
extern u32 fn_1_4AEC0(u32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_80036058(struct Sig_fn_80036058_fn_80036058_Arg0 *, u32);
extern void DCFlushRangeNoSync(void *, u32);
extern void fn_1_A2A70(u32, s32);
/* movie work area: the TU's .bss objects, addressed off one section base */
/* first object of the section: carries the retail base symbol's name */
static struct Movie20Obj *fzgx_obj_lbl_5_bss_0;
static s32 sSound;
static s32 sTimer;
static s32 sParam;
static s8 sPending;
static s8 sWait;
static u8 sBuffer;
static u8 sUnk13;
static s8 sIndex;
static s32 sCountdown;
static u8 sAdvance;
static u8 sPad20[8];
static u32 sTask1;
static u32 sTask2;
static u8 sPad30[0x10];
static s8 sMode;
static u8 sPad44[6];
static s16 sWidth;
static s16 sHeight;
static s16 sX;
static s16 sY;
static f32 sScaleX;
static f32 sScaleY;
static u8 sUnk5C;
static s8 sFontType;
static s8 sFont;
static u8 sPad60[4];
static s16 sVolume;
static s8 sSubtitles;
static s8 sFade;
static f32 sAlpha;
static f32 sFadeSpeed;
static u32 sSize1;
static u32 sSize2;
static u32 sBuffers1[2];
static u32 sBuffers2[2];
static u8 sTex1[0x20];
static u8 sTex2[0x20];
static u32 sLength;
static u32 sSource;
static struct Movie20Frame sInfo;
static struct Movie20Command sCommands[30];
static u8 sPad1D0[0x1A4];
static u8 sMatrices[30][0x40];
static u8 sPadAF4[0x78];
static s32 sStarted;
static ARQRequest sRequest;
static u32 sSubPending;
#pragma section code_type ".fzgxpool"

#pragma section code_type ".fzgxpool"
static void fzgx_bss_primer(void **out) {
out[0] = &fzgx_obj_lbl_5_bss_0 ;
out[1] = &sSound;
out[2] = &sTimer;
out[3] = &sParam;
out[4] = &sPending;
out[5] = &sWait;
out[6] = &sBuffer;
out[7] = &sUnk13;
out[8] = &sIndex;
out[9] = &sCountdown;
out[10] = &sAdvance;
out[11] = sPad20;
out[12] = &sTask1;
out[13] = &sTask2;
out[14] = sPad30;
out[15] = &sMode;
out[16] = sPad44;
out[17] = &sWidth;
out[18] = &sHeight;
out[19] = &sX;
out[20] = &sY;
out[21] = &sScaleX;
out[22] = &sScaleY;
out[23] = &sUnk5C;
out[24] = &sFontType;
out[25] = &sFont;
out[26] = sPad60;
out[27] = &sVolume;
out[28] = &sSubtitles;
out[29] = &sFade;
out[30] = &sAlpha;
out[31] = &sFadeSpeed;
out[32] = &sSize1;
out[33] = &sSize2;
out[34] = sBuffers1;
out[35] = sBuffers2;
out[36] = sTex1;
out[37] = sTex2;
out[38] = &sLength;
out[39] = &sSource;
out[40] = &sInfo;
out[41] = sCommands;
out[42] = sPad1D0;
out[43] = sMatrices;
out[44] = sPadAF4;
out[45] = &sStarted;
out[46] = &sRequest;
out[47] = &sSubPending;
}
static void fzgx_data_layout_lbl_5_data_0(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_5_data_0;
    s = *(u8 *)fzgx_pool_data_lbl_5_data_1544;
    s = *(u8 *)fzgx_pool_data_lbl_5_data_0_1718;
    s = *(u8 *)fzgx_pool_data_lbl_5_data_0_1728;
}
static void fzgx_pool_primer_0(volatile f32 *out, s32 value) {  /* fzgx-allow: S2 pool primer sink */
out[0] = 0.0f;
out[1] = 1.0f;
out[2] = 0.1f;
out[3] = 8.0f;
out[4] = 0.5f;
out[5] = (f32)value;
}
#pragma section code_type ".text"

static const u32 fzgx_pool_table_20[4] = {0x80FF80FF, 0xFF0000FF, 0x80FF80FF, 0xFFFF80FF};

#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_30(volatile f32 *out) {  /* fzgx-allow: S2 pool primer sink */
out[0] = 12.0f;
out[1] = 4.0f;
out[2] = 80.0f;
out[3] = 360.0f;
out[4] = 0.6f;
}
#pragma section code_type ".text"

static const u32 fzgx_pool_table_44[1] = {0};

#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_48(volatile f32 *out) {  /* fzgx-allow: S2 pool primer sink */
out[0] = 59.94f;
out[1] = 0.75f;
out[2] = 0.01666666753590107f;
out[3] = 30000.0f;
out[4] = 0.03125f;
out[5] = 24.0f;
out[6] = 320.0f;
out[7] = 321.0f;
out[8] = 500.0f;
}
#pragma section code_type ".text"

#pragma section code_type ".text"
void fn_5_20FC(void) {
u16 maxDuration;
struct Movie20Command *command;
u32 aram;
struct Sig_fn_5_3E74_fn_5_3E74_Arg0 subtitle;
u16 duration;
f32 frameScale;
f32 textY;
s16 start, end;
s32 timer;
u8 advance;
maxDuration = 0;
advance = sAdvance;

if (advance != 0) {
sIndex++;
if (sIndex >= 30) {
sIndex = 29;
sCommands[29].type = 12;
}
command = &sCommands[sIndex];
switch (command->type) {
case 11:
sAdvance = 0;
break;
case 10:
if (sStarted == 0) {
fn_1_1577D0(0, 0, 0.75f);
fn_1_435C(sTask1);
fn_1_3F8C((u32)(((u8 *)fzgx_pool_data_lbl_5_data_0_1718)), (u32)fn_1_157820, 0, 2);
fn_1_435C(sTask2);
fn_1_3F8C((u32)(((u8 *)fzgx_pool_data_lbl_5_data_0_1728)), (u32)fn_1_1578C4, 0, 2);
sStarted = 1;
}
break;
case 9:
if (command->arg != 0) {
sWidth = 640;
sHeight = 336;
sX = 0;
sY = 0;
sScaleX = 1.0f;
sScaleY = 1.0f;
} else {
sWidth = lbl_1_bss_58.width;
sHeight = lbl_1_bss_58.height;
sX = lbl_1_bss_58.x;
sY = lbl_1_bss_58.y;
sScaleX = lbl_1_bss_58.scaleX;
sScaleY = lbl_1_bss_58.scaleY;
}
break;
case 1:
timer = command->duration;
sAdvance = 0;
sCountdown = timer;
break;
case 2:
fzgx_obj_lbl_5_bss_0 ->vt->start(fzgx_obj_lbl_5_bss_0 , sMatrices[sIndex]);
sFade = 1;
sAlpha = 0.0f;
sFadeSpeed = 0.01666666753590107f;
sMode = 1;
sAdvance = 0;
break;
case 3:
sFade = 1;
sAlpha = 0.0f;
sFadeSpeed = 0.01666666753590107f;
sCountdown = command->duration;
sAdvance = 0;
break;
case 4:
sFade = 1;
sAlpha = 0.0f;
sFadeSpeed = 0.01666666753590107f;
sCountdown = command->duration;
sAdvance = 0;
aram = 0xF24000;
aram += command->arg * sLength;
DCInvalidateRange((void *)sSource, sLength);
ARQPostRequest(&sRequest, 0, 1, 1, aram, sSource, sLength, 0);
GXInvalidateTexAll();
break;
case 5:
sSound = 49;
sWait = 1;
sPending = 4;
fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)lbl_1_bss_6EAD0.unk_0->unk_0, 49);
ADXT_Pause((ADXTHandle *)lbl_1_bss_6EAD0.unk_0->unk_0, 1);
sTimer = 0;
break;
case 7:
sSound = 40;
sWait = 1;
sPending = 2;
sTimer = command->arg;
sParam = command->duration;
break;
case 6:
sSound = 40;
sWait = 0;
sPending = 1;
sTimer = command->arg;
sParam = command->duration;
break;
case 8:
sWait = 0;
sPending = 3;
sTimer = command->arg;
sParam = command->duration;
break;
case 12:
sMode = -1;
*(s32 *)&lbl_1_bss_970 = 1;
break;
}
} else {
command = &sCommands[sIndex];
}
switch (command->type) {
case 11:
if (fn_1_157930() != 0) {
sAdvance = 1;
}
break;
case 1:
if (sCountdown > 0) {
sCountdown--;
} else {
sAdvance = 1;
}
break;
case 3:
timer = sCountdown;
if (timer == 60) {
sFade = 2;
sAlpha = 1.0f;
sFadeSpeed = 0.01666666753590107f;
}
if (timer > 0) {
sCountdown--;
} else {
sAdvance = 1;
}
break;
case 4:
timer = sCountdown;
if (timer == 60) {
sFade = 2;
sAlpha = 1.0f;
sFadeSpeed = 0.01666666753590107f;
}
if (timer > 0) {
sCountdown--;
} else {
sAdvance = 1;
}
break;
case 2:
lbl_1_bss_184(fzgx_obj_lbl_5_bss_0 , &sInfo);
fn_5_3E54((u8)sIndex);
frameScale = 30000.0f / (f32)sInfo.rate;
while (sSubPending != 0) {
fn_5_3E74(&subtitle);
start = (f32)subtitle.unk_0 * frameScale;
end = frameScale * (f32)(subtitle.unk_0 + subtitle.unk_4);
duration = end - start;
if (start > sInfo.frame || sInfo.frame >= end) {
continue;
}
textY = (f32)((s8)fn_1_A5DC4() ? 360 : 334);
maxDuration = duration > maxDuration ? duration : maxDuration;
if (!sSubtitles) {
continue;
}
fn_1_49410();
fn_1_495FC();
fn_1_495B0(0x80000000);
if (sFontType == 5) {
fn_1_4965C(4);
} else {
fn_1_4965C(2);
fn_1_4955C((f32)subtitle.unk_8 / 32.0f, (f32)subtitle.unk_8 / 24.0f);
}
fn_1_495C8(1);
fn_1_49590(0.5f);
fn_1_4AEE8(sFont);
fn_1_4AEC0(1);
fn_1_496FC(320.0f, textY + (f32)((subtitle.unk_8 + 14) * subtitle.unk_C));
fn_1_4AE0C((const char *)(((u8 *)fzgx_pool_data_lbl_5_data_1544)), subtitle.unk_10);
fn_1_496FC(321.0f, textY + (f32)((subtitle.unk_8 + 14) * subtitle.unk_C));
fn_1_4AE0C((const char *)(((u8 *)fzgx_pool_data_lbl_5_data_1544)), subtitle.unk_10);
fn_1_4AEC0(0);
}
if (sInfo.valid != 0) {
GXInvalidateTexAll();
fn_80036058((struct Sig_fn_80036058_fn_80036058_Arg0 *)sTex1, sBuffers1[sBuffer]);
fn_80036058((struct Sig_fn_80036058_fn_80036058_Arg0 *)sTex2, sBuffers2[sBuffer]);
lbl_1_bss_E4(fzgx_obj_lbl_5_bss_0 , &sInfo, sBuffers1[sBuffer], sBuffers2[sBuffer]);
DCFlushRangeNoSync((void *)sBuffers1[sBuffer], sSize1);
DCFlushRangeNoSync((void *)sBuffers2[sBuffer], sSize2);
sBuffer++;
if (sBuffer >= 2) {
sBuffer = 0;
}
lbl_1_bss_180(fzgx_obj_lbl_5_bss_0 );
if (sInfo.frame >= lbl_1_bss_170(fzgx_obj_lbl_5_bss_0 ) - command->duration - 30 && !sFade) {
sFade = 2;
sAlpha = 1.0f;
sFadeSpeed = 0.01666666753590107f;
}
}
break;
}
if (sPending != 0 && (!sWait || fzgx_obj_lbl_5_bss_0 ->vt->state(fzgx_obj_lbl_5_bss_0 ) == 2)) {
if (sPending == 2) {
if (sInfo.frame >= lbl_1_bss_170(fzgx_obj_lbl_5_bss_0 ) - sTimer / 2) {
*(u32 *)&lbl_1_bss_6EAB4 |= 1;
fn_1_A2A70(1, sParam);
fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)lbl_1_bss_6EAD0.unk_0->unk_0, (u8)sSound);
sPending = 0;
}
} else if (sTimer > 0) {
sTimer--;
} else if (sTimer == 0) {
switch (sPending) {
case 1:
*(u32 *)&lbl_1_bss_6EAB4 |= 1;
fn_1_A2A70(1, sParam);
fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)lbl_1_bss_6EAD0.unk_0->unk_0, (u8)sSound);
break;
case 3:
*(u32 *)&lbl_1_bss_6EAB4 |= 4;
fn_1_A2A70(4, sParam);
break;
case 4:
ADXT_Pause((ADXTHandle *)lbl_1_bss_6EAD0.unk_0->unk_0, 0);
break;
}
sPending = 0;
}
}
switch (sFade) {
case 1:
if (sAlpha + sFadeSpeed < 1.0f) {
if (command->type != 2 || fzgx_obj_lbl_5_bss_0 ->vt->state(fzgx_obj_lbl_5_bss_0 ) == 2) {
sAlpha += sFadeSpeed;
}
} else {
sAlpha = 1.0f;
sFade = 0;
}
if (sVolume == -1 && sMode == 1) {
fzgx_obj_lbl_5_bss_0 ->vt->volume(fzgx_obj_lbl_5_bss_0 , 0);
} else {
fzgx_obj_lbl_5_bss_0 ->vt->volume(fzgx_obj_lbl_5_bss_0 , sVolume - 999);
}
break;
case 2:
if (sAlpha - sFadeSpeed > 0.0f) {
sAlpha -= sFadeSpeed;
} else {
sAlpha = 0.0f;
sFade = 0;
if (sMode == 1) {
fn_5_3BF8();
}
sAdvance = 1;
}
if (sVolume == -1 && sMode == 1) {
fzgx_obj_lbl_5_bss_0 ->vt->volume(fzgx_obj_lbl_5_bss_0 , (s32)(500.0f * sAlpha) - 499);
} else {
fzgx_obj_lbl_5_bss_0 ->vt->volume(fzgx_obj_lbl_5_bss_0 , sVolume - 999);
}
break;
}
}
/* fzgx:end fn_5_20FC */

/* fzgx:begin fn_5_2C54 noprologue */
#include "types.h"
#include "rel/movie/globals.h"
#include "rel/movie/movie.h"

s16 fn_5_2C54(u8 *arg0, s8 arg1, s8 arg2) {
    s16 value;
    s8 i;
    value = 0;
    for (i = 0; i < arg2; i++) {
        value *= 10;
        value += arg0[arg1 + i] - 0x30;
    }
    return value;
}
/* fzgx:end fn_5_2C54 */

/* fzgx:begin fn_5_3BF8 */
typedef u32 (*fn_5_3BF8_Fn0)(u32);
struct fn_5_3BF8_lbl_5_bss_0 {
    u32 unk_0;
    u8 pad_4[0x3C];
    u8 unk_40;
    u8 unk_41;
};



void fn_5_3BF8(void) {
    struct fn_5_3BF8_lbl_5_bss_0 *p_lbl_5_bss_0;
    u32 v0;
    u32 v1;
    p_lbl_5_bss_0 = (struct fn_5_3BF8_lbl_5_bss_0 *)&(*(struct fn_5_3BF8_lbl_5_bss_0 *)&lbl_5_bss_0);
    v0 = p_lbl_5_bss_0->unk_0;
    v1 = *(u32 *)v0;
    ((fn_5_3BF8_Fn0)*(u32 *)((u8 *)v1 + 28))(v0);
    p_lbl_5_bss_0->unk_40 = 0;
    p_lbl_5_bss_0->unk_41 = 0;
}
/* fzgx:end fn_5_3BF8 */
