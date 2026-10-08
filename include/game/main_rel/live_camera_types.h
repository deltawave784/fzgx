#ifndef GAME_MAIN_REL_LIVE_CAMERA_TYPES_H
#define GAME_MAIN_REL_LIVE_CAMERA_TYPES_H

// Types (and the externs that name them) of live_camera.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/live_camera.h"
#include "psvec.h"
#include "dolphin/hw_regs.h"

struct fn_1_E174_lbl_1_rodata_4E0 {
    f32 unk_0;
    u8 pad_4[0x10];
    f32 unk_14;
    u8 pad_18[0x4];
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
};

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

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    u32 flags;
    s32 unk_4;
    u32 unk_8;
    u32 unk_C;
} Sig_fn_1_45730_LoadEntry;

typedef struct {
    u32 unk_0;
    u8 pad_4[0x48];
    Sig_fn_1_45730_LoadEntry entry;
} Sig_fn_1_45730_LoadResult;

typedef struct {
    u8 unk_0;
    u8 pad_1;
    s16 unk_2;
    s16 unk_4;
    s16 unk_6;
    u16 unk_8;
    u8 pad_A[0x2];
    u32 unk_C;
    u16 unk_10;
    s16 unk_12;
    s16 unk_14;
    u8 pad_16[0x2];
    u32 unk_18;
    u8 pad_1C[0x48];
    u16 unk_64;
} Sig_fn_1_101D0_Fn_1_101D0_State;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_11544_LiveCamVec;

typedef struct {
    f32 m[3][4];
} LiveCamMtx;

extern u32 fn_1_A1588(Sig_ADXT_Stop_ADXTHandle *, u32);
extern int fn_1_45730(char *, Sig_fn_1_45730_LoadResult *);
extern u32 fn_1_45B2C(Sig_fn_1_45730_LoadResult *);
extern void fn_1_458A0(Sig_fn_1_45730_LoadResult *, void *, u32, u32);
extern void fn_1_45850(Sig_fn_1_45730_LoadResult *);
extern u32 fn_1_107B8(Sig_fn_1_101D0_Fn_1_101D0_State *);
extern void fn_1_862D4(s16, Vec3 *);
extern void fn_1_15578(void *, fn_1_11544_LiveCamVec *, void *, void *, u32, void *, u32, u32, u32, u32);
extern void fn_8006E2B0(void *, Vec3 *);

#endif  // GAME_MAIN_REL_LIVE_CAMERA_TYPES_H
