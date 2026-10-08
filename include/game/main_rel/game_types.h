#ifndef GAME_MAIN_REL_GAME_TYPES_H
#define GAME_MAIN_REL_GAME_TYPES_H

// Types (and the externs that name them) of game.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/game.h"
#include "font.h"

typedef struct Sig_ADXT_Pause_AdxSjdHandle Sig_ADXT_Pause_AdxSjdHandle;
typedef struct Sig_ADXT_Pause_ADXStream Sig_ADXT_Pause_ADXStream;
typedef struct Sig_ADXT_Pause_AXRNAHandle Sig_ADXT_Pause_AXRNAHandle;

typedef struct Sig_ADXT_Pause_SJCK {
    unsigned char *data;
    int len;
} Sig_ADXT_Pause_SJCK;

typedef void (*Sig_ADXT_Pause_SJErrorCallback)(void *object, int error);
typedef struct Sig_ADXT_Pause_SJInterface Sig_ADXT_Pause_SJInterface;
typedef struct Sig_ADXT_Pause_SJ Sig_ADXT_Pause_SJ;

struct Sig_ADXT_Pause_SJ {
    const Sig_ADXT_Pause_SJInterface *interface;
};

struct Sig_ADXT_Pause_SJInterface {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Pause_SJ *sj);
    const void *(*get_uuid)(Sig_ADXT_Pause_SJ *sj);
    void (*reset)(Sig_ADXT_Pause_SJ *sj);
    void (*get_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, int max_size, Sig_ADXT_Pause_SJCK *chunk);
    void (*unget_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, Sig_ADXT_Pause_SJCK *chunk);
    void (*put_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, Sig_ADXT_Pause_SJCK *chunk);
    int (*get_num_data)(Sig_ADXT_Pause_SJ *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Pause_SJ *sj, Sig_ADXT_Pause_SJErrorCallback callback, void *object);
};

typedef struct Sig_ADXT_Pause_ADX_AMP Sig_ADXT_Pause_ADX_AMP;
typedef struct Sig_ADXT_Pause_LSCObject Sig_ADXT_Pause_LSCObject;

typedef struct Sig_ADXT_Pause_ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Pause_AdxSjdHandle *decoder;
    Sig_ADXT_Pause_ADXStream *stream;
    Sig_ADXT_Pause_AXRNAHandle *rna;
    Sig_ADXT_Pause_SJ *stream_sj;
    Sig_ADXT_Pause_SJ *input_sj;
    Sig_ADXT_Pause_SJ *output_sj[2];
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
    Sig_ADXT_Pause_ADX_AMP *amplifier;
    Sig_ADXT_Pause_SJ *amplifier_input[2];
    Sig_ADXT_Pause_SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    Sig_ADXT_Pause_LSCObject *linked_stream_controller;
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
} Sig_ADXT_Pause_ADXTHandle;

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
    u8 unk[0xb];
    u8 value;
} Entry;

typedef struct {
    u8 pad_0[2];
    s16 unk_2;
    u8 pad_4[8];
    u32 unk_C;
    u8 pad_10[0x10];
} Obj_1_bss_25E9C;

typedef struct {
    u8 pad[0x2f8];
    u32 value_2f8;
    u32 value_2fc;
    u32 value_300;
    u32 value_304;
    u32 value_308;
    u32 value_30c;
    u32 value_310;
    u32 value_314;
    u32 value_318;
    u32 value_31c;
} Fn40710Config;

struct fn_1_408E8_lbl_1_rodata_BD8 {
    u8 pad_0[0x4];
    f32 unk_4;
    u8 pad_8[0x4];
    f32 unk_C;
    u8 pad_10[0x2C];
    f32 unk_3C;
    u8 pad_40[0x4];
    f32 unk_44;
    u8 pad_48[0x174];
    f32 unk_1BC;
    u8 pad_1C0[0xC];
    f32 unk_1CC;
    u8 pad_1D0[0xC];
    f32 unk_1DC;
    u8 pad_1E0[0x15C];
    u32 unk_33C;
    f32 unk_340;
};

typedef struct Fn408E8Obj {
    u8 type;         /* 0x00 */
    u8 pad_1[2];
    u8 flags;        /* 0x03 */
    u32 unk_4;
    f32 fade;        /* 0x08 */
    f32 z;           /* 0x0C */
    f32 x;           /* 0x10 */
    f32 y;           /* 0x14 */
    f32 width;       /* 0x18 */
    f32 height;      /* 0x1C */
    void *data;      /* 0x20 */
} Fn408E8Obj;

extern void ADXT_Pause(Sig_ADXT_Pause_ADXTHandle *, s32);
extern Fn40710Config lbl_1_rodata_BD8;
extern void fn_1_403D4(Fn408E8Obj *obj);
extern Entry *lbl_1_bss_53F8[34];
extern Obj_1_bss_25E9C lbl_1_bss_25E9C[30];

#endif  // GAME_MAIN_REL_GAME_TYPES_H
