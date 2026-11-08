#include "types.h"
#pragma readonly_strings on

typedef struct SJ SJ;
typedef struct SJInterface {
    void *reserved[3];
    void (*destroy)(SJ *sj);
} SJInterface;
struct SJ {
    const SJInterface *interface;
};

typedef struct SfdHandle SfdHandle;
typedef struct LSC LSC;
typedef struct SFXHandle SFXHandle;
typedef struct ADXStream ADXStream;
typedef struct SfdTransportInterface SfdTransportInterface;

typedef struct SfdTransportSetup {
    const SfdTransportInterface *entries[9];
} SfdTransportSetup;

typedef struct MwsCreateParams {
    int file_type;
    int maximum_bps;
    int width;
    int height;
    int frame_count;
    int decoder_count;
    void *work;
    int work_size;
    int composition_mode;
    int buffer_format;
    int field_28;
    int field_2C;
} MwsCreateParams;

typedef struct MwsPictureUserConfig {
    void *buffer;
    int buffer_size;
    int element_size;
} MwsPictureUserConfig;

typedef struct MwsStHandle {
    int active;
    unsigned char reserved_004[8];
    SJ *stream;
    int element_id;
    void *backend;
} MwsStHandle;

typedef struct MwsPlayer {
    const void *interface;
    int active;
    int status;
    MwsCreateParams create;
    int playback_mode;
    SfdHandle *sfd;
    ADXStream *stream;
    void *transport;
    LSC *loader;
    int field_050;
    int field_054;
    int flow_limit;
    int field_05C;
    unsigned char reserved_060[8];
    int field_068;
    int field_06C;
    signed char concat_play;
    signed char concat_stopped;
    signed char paused;
    unsigned char field_073;
    int entry_count;
    unsigned char reserved_078[12];
    int field_084;
    unsigned char reserved_088[0x20];
    SFXHandle *sfx;
    void *composition_work;
    int composition_work_size;
    unsigned char reserved_0B4[8];
    MwsPictureUserConfig internal_picture_user;
    unsigned char reserved_0C8[12];
    MwsPictureUserConfig *picture_user;
    void *picture_user_work;
    int picture_user_header_size;
    int picture_user_write;
    int picture_user_read;
    SJ *additional_info_sj;
    unsigned char reserved_0EC[0x24];
    char *filename;
    int filename_capacity;
    unsigned char reserved_118[0x14];
    SJ *input_sj;
    void *input_buffer;
    int input_buffer_size;
    int input_buffer_extra_size;
    unsigned char reserved_13C[0x10];
    SJ *memory_sj;
    unsigned char reserved_150[8];
    void *arena;
    unsigned int arena_size;
    unsigned char *arena_cursor;
    unsigned int arena_used;
    int allocation_count;
    void *allocations[32];
    MwsStHandle sound;
    unsigned char reserved_204[0x24];
} MwsPlayer;

typedef void *(*MwsMallocFn)(void *object, long size);
typedef void (*MwsFreeFn)(void *object, void *memory);

typedef struct MwsLibraryWork {
    int field_00;
    float frame_rate;
    int video_frequency;
    int frame_pool;
    int field_10;
    unsigned char reserved_014[0x14];
    MwsMallocFn malloc_fn;
    MwsFreeFn free_fn;
    void *allocator_object;
    unsigned char reserved_034[0x34];
    MwsPlayer players[8];
} MwsLibraryWork;

typedef struct MW_PLY_OBJ {
    struct MwsPlayerInterface *interface;
} MW_PLY_OBJ;
typedef MW_PLY_OBJ *MWPLY;

typedef struct MwsPlayerInterface {
    void *reserved[3];
} MwsPlayerInterface;

extern void MWSFSVM_Error(const char *, ...);
extern MwsLibraryWork *fn_12_38DBC(void);
extern int fn_12_38A0C(int);
extern void fn_12_390E4(MwsPlayer *);
extern void fn_12_35484(MwsPlayer *);
extern void fn_12_35D74(SFXHandle *);
extern void fn_80057114(LSC *);
extern void fn_12_34F64(ADXStream *);
extern int fn_12_2B6B0(SfdHandle *);
extern void fn_12_3B15C(MwsStHandle *);
extern void *memset(void *, int, unsigned long);
extern int fn_12_38AE0(void);
extern int fn_12_2A434(SfdHandle *, void *, int, int);
extern int fn_12_2D888(SfdHandle *, int, int);
extern int fn_12_2A5C8(SfdHandle *, int, int);
extern SJ *fn_80058498(void *, int, int);
extern SJ *fn_80057B9C(void *, int);
extern int fn_12_2D500(SfdHandle *, int, void **);
extern void fn_12_3A968(MwsPlayer *, int);
extern void fn_12_3A960(MwsPlayer *, int);
extern ADXStream *fn_12_34F84(SJ *);
extern void fn_12_38DC8(MwsPlayer *);
extern LSC *fn_800571EC(SJ *);
extern void fn_8005710C(LSC *, ADXStream *);
extern int fn_12_36208(MwsPlayer *);
extern SFXHandle *fn_12_35D94(void *, int, int, int);
extern void fn_12_356E8(MwsPlayer *, int);
extern SJ *fn_12_354BC(MwsPlayer *);
extern int fn_12_35418(MwsPlayer *);
extern void fn_12_353FC(MwsPlayer *);

extern const SfdTransportInterface lbl_12_rodata_A18;
extern const SfdTransportInterface lbl_12_rodata_A80;
extern const SfdTransportInterface lbl_12_rodata_B58;
extern const SfdTransportInterface lbl_12_rodata_B90;
extern const SfdTransportInterface lbl_12_rodata_BD8;
extern const SfdTransportInterface lbl_12_rodata_E90;
extern const SfdTransportInterface lbl_12_rodata_EC8;

static const SfdTransportSetup lbl_12_rodata_1D88 = {{
    &lbl_12_rodata_B58, &lbl_12_rodata_B90, &lbl_12_rodata_BD8, &lbl_12_rodata_A18,
    0, 0, &lbl_12_rodata_EC8, &lbl_12_rodata_A80, &lbl_12_rodata_E90}};
static const SfdTransportSetup lbl_12_rodata_1DAC = {{
    &lbl_12_rodata_B58, 0, &lbl_12_rodata_BD8, 0, 0, 0, &lbl_12_rodata_EC8, 0, 0}};
static const SfdTransportSetup lbl_12_rodata_1DD0 = {{
    &lbl_12_rodata_B58, &lbl_12_rodata_B90, &lbl_12_rodata_BD8, 0, 0, 0,
    &lbl_12_rodata_EC8, 0, &lbl_12_rodata_E90}};
static const char lbl_12_rodata_1DF4[] = "E2053001 MWSFD_Malloc: cnt over.";
static const char lbl_12_rodata_1E18[0x28] = "E204161: mwPlyGetHdrInf(): NULL pointer";
static const char lbl_12_rodata_1E40[] = "E204162: mwPlyGetHdrInf(): bufsize error";
static const char lbl_12_rodata_1E6C[0x20] = "E20010703E MWSFCRE_DestroySfd: ";
static const char lbl_12_rodata_1E8C[] = "E2053005: forgot free.";
extern u8 fn_12_3901C__fzgx_offset_0[];
extern u8 fn_12_3916C__fzgx_offset_0[];
extern u8 fn_12_393F0__fzgx_offset_0[];
extern u8 fn_12_39930__fzgx_offset_0[];
extern u8 fn_12_39E00__fzgx_offset_0[];
extern u8 fn_12_39E54__fzgx_offset_0[];
extern u8 fn_12_39EA4__fzgx_offset_0[];
extern u8 fn_12_39EF8__fzgx_offset_0[];
extern u8 fn_12_39F48__fzgx_offset_0[];
extern u8 fn_12_3A264__fzgx_offset_0[];
extern u8 fn_12_3AA58__fzgx_offset_0[];
extern u8 fn_12_3ABE0__fzgx_offset_0[];
extern u8 lbl_12_rodata_1D88__fzgx_offset_0[];
extern u8 lbl_12_rodata_1DAC__fzgx_offset_0[];
extern u8 lbl_12_rodata_1DD0__fzgx_offset_0[];
extern u8 mwSfdDestroy__fzgx_offset_0[];
extern u8 mwSfdPause__fzgx_offset_0[];
static const union { u32 w[9]; const char v[0x24]; } fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_18 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45323035, 0x33303033, 0x3A206E6F, 0x7420656E, 0x6F756768, 0x20776F72, 0x6B3A2073, 0x66785F77,
    0x6B000000
}};
static const union { u32 w[10]; const char v[0x28]; } fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_3C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45323035, 0x33303034, 0x3A206E6F, 0x7420656E, 0x6F756768, 0x20776F72, 0x6B3A2061, 0x696E6673,
    0x6A5F6275, 0x66000000
}};
static const union { u32 w[9]; const char v[0x24]; } fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_64 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45333031, 0x32313032, 0x3A204275, 0x66666572, 0x20666F72, 0x6D617420, 0x69732069, 0x6E76616C,
    0x69642E00
}};
static const union { u8 w[43]; const char v[43]; } fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_88 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45, 0x31, 0x31, 0x32, 0x32, 0x36, 0x31, 0x32,
    0x20, 0x6D, 0x77, 0x50, 0x6C, 0x79, 0x43, 0x72,
    0x65, 0x61, 0x74, 0x65, 0x53, 0x6F, 0x66, 0x64,
    0x65, 0x63, 0x20, 0x3A, 0x20, 0x63, 0x70, 0x72,
    0x6D, 0x20, 0x69, 0x73, 0x20, 0x4E, 0x55, 0x4C,
    0x4C, 0x2E, 0x0
}};
static const union { u32 w[11]; const char v[44]; } fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_B4 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x57323030, 0x30206D77, 0x506C7943, 0x72656174, 0x65536F66, 0x6465633A, 0x63616E27, 0x74206372,
    0x65617465, 0x2068616E, 0x646C6500
}};
static const union { u8 w[57]; const char v[57]; } fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_E0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45, 0x32, 0x30, 0x35, 0x33, 0x30, 0x30, 0x36,
    0x20, 0x6D, 0x77, 0x50, 0x6C, 0x79, 0x43, 0x72,
    0x65, 0x61, 0x74, 0x65, 0x53, 0x6F, 0x66, 0x64,
    0x65, 0x63, 0x3A, 0x20, 0x44, 0x69, 0x64, 0x6E,
    0x27, 0x74, 0x20, 0x73, 0x65, 0x74, 0x20, 0x6D,
    0x61, 0x6C, 0x6C, 0x6F, 0x63, 0x2F, 0x66, 0x72,
    0x65, 0x65, 0x20, 0x66, 0x75, 0x6E, 0x63, 0x2E,
    0x0
}};
static const union { u8 w[35]; const char v[35]; } fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_11C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45, 0x32, 0x30, 0x31, 0x32, 0x20, 0x6D, 0x77,
    0x50, 0x6C, 0x79, 0x43, 0x72, 0x65, 0x61, 0x74,
    0x65, 0x3A, 0x63, 0x61, 0x6E, 0x27, 0x74, 0x20,
    0x63, 0x72, 0x65, 0x61, 0x74, 0x65, 0x20, 0x53,
    0x46, 0x44, 0x0
}};
static const union { u8 w[54]; const char v[54]; } fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_140 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45, 0x30, 0x32, 0x31, 0x32, 0x30, 0x35, 0x30,
    0x31, 0x3A, 0x20, 0x49, 0x6E, 0x74, 0x65, 0x72,
    0x6E, 0x61, 0x6C, 0x20, 0x45, 0x72, 0x72, 0x6F,
    0x72, 0x3A, 0x20, 0x6D, 0x77, 0x73, 0x66, 0x63,
    0x72, 0x65, 0x5F, 0x41, 0x74, 0x74, 0x61, 0x63,
    0x68, 0x50, 0x69, 0x63, 0x55, 0x73, 0x72, 0x42,
    0x75, 0x66, 0x28, 0x29, 0x2E, 0x0
}};
static const union { u8 w[58]; const char v[58]; } fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_178 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45, 0x30, 0x32, 0x31, 0x32, 0x30, 0x35, 0x30,
    0x32, 0x3A, 0x20, 0x6D, 0x77, 0x73, 0x66, 0x63,
    0x72, 0x65, 0x5F, 0x41, 0x74, 0x74, 0x61, 0x63,
    0x68, 0x50, 0x69, 0x63, 0x55, 0x73, 0x72, 0x42,
    0x75, 0x66, 0x28, 0x29, 0x3A, 0x20, 0x75, 0x73,
    0x72, 0x64, 0x61, 0x74, 0x62, 0x75, 0x66, 0x20,
    0x69, 0x73, 0x20, 0x73, 0x68, 0x6F, 0x72, 0x74,
    0x2E, 0x0
}};


typedef struct SfdBufferCreateConfig {
    const SfdTransportSetup *transport_setup;
    unsigned char *memory;
    int buffer_sizes[7];
    int field_24;
    int ring_alignment;
} SfdBufferCreateConfig;

typedef struct SfdCreateConfig {
    SfdBufferCreateConfig buffer;
    int picture_user_buffer_minimum;
    int maximum_width;
    int maximum_height;
    int video_output_format;
    unsigned char *handle_memory;
    int handle_memory_size;
} SfdCreateConfig;

typedef struct SfdMpvParameters {
    s32 chroma_width;
    s32 chroma_height;
    s32 width;
    s32 height;
    s32 reference_buffer;
    s32 maximum_width;
    int maximum_height;
    s32 frame_count;
    s32 frame_buffer;
} SfdMpvParameters;

typedef struct SfdAdxtParameters {
    int stream_buffer_size;
    int stream_buffer_extra_size;
    void *stream_buffer;
    int maximum_channels;
    int decoder_work_size;
    int decoder_buffer_size;
    void *decoder_buffer;
} SfdAdxtParameters;

typedef struct MwsReferenceBuffers { void *buffers[2]; } MwsReferenceBuffers;

typedef struct MwsPictureUserWork {
    unsigned char header[0x40];
    unsigned char element_buffer[0x7C0];
} MwsPictureUserWork;


extern void fn_12_3ABE0(void);
extern void fn_12_3AA58(void);
extern void mwSfdDestroy(void);
extern void fn_12_39930(void);
extern void fn_12_3901C(void);
extern void fn_12_3A264(void);
extern void fn_12_39F48(void);
extern void mwSfdPause(void);
extern void fn_12_39EF8(void);
extern void fn_12_39EA4(void);
extern void fn_12_39E54(void);
extern void fn_12_39E00(void);
extern void fn_12_3916C(void);
extern void fn_12_393F0(void);

typedef struct MwsPlayerInterfaceTable {
    void *reserved[3];
    void (*functions[14])(void);
} MwsPlayerInterfaceTable;

static union { u32 w[17]; MwsPlayerInterfaceTable v; } fzgx_pool_init_lbl_12_data_D38 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, 0x0, (u32)fn_12_3ABE0__fzgx_offset_0, (u32)fn_12_3AA58__fzgx_offset_0, (u32)mwSfdDestroy__fzgx_offset_0, (u32)fn_12_39930__fzgx_offset_0, (u32)fn_12_3901C__fzgx_offset_0,
    (u32)fn_12_3A264__fzgx_offset_0, (u32)fn_12_39F48__fzgx_offset_0, (u32)mwSfdPause__fzgx_offset_0, (u32)fn_12_39EF8__fzgx_offset_0, (u32)fn_12_39EA4__fzgx_offset_0, (u32)fn_12_39E54__fzgx_offset_0, (u32)fn_12_39E00__fzgx_offset_0, (u32)fn_12_3916C__fzgx_offset_0,
    (u32)fn_12_393F0__fzgx_offset_0
}};
static union { u32 w[17]; SfdCreateConfig v; } fzgx_pool_init_lbl_12_data_D38__fzgx_offset_44 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_12_rodata_1D88__fzgx_offset_0, 0x0, 0x10000, 0x50800, 0x12000, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x800, 0x3, 0x2D0, 0x240, 0x3, 0x0,
    0x0
}};
static union { u32 w[17]; SfdCreateConfig v; } fzgx_pool_init_lbl_12_data_D38__fzgx_offset_88 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_12_rodata_1DAC__fzgx_offset_0, 0x0, 0x10000, 0x50800, 0x12000, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x800, 0x3, 0x2D0, 0x240, 0x3, 0x0,
    0x0
}};
static union { u32 w[17]; SfdCreateConfig v; } fzgx_pool_init_lbl_12_data_D38__fzgx_offset_CC = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_12_rodata_1DD0__fzgx_offset_0, 0x0, 0x10000, 0x50800, 0x12000, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x800, 0x3, 0x2D0, 0x240, 0x3, 0x0,
    0x0
}};
static union { u32 w[9]; SfdMpvParameters v; } fzgx_pool_init_lbl_12_data_D38__fzgx_offset_110 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xC0, 0xF0, 0x160, 0x1E0, 0x0, 0x160, 0x1E0, 0x4,
    0x0
}};
static union { u32 w[7]; SfdAdxtParameters v; } fzgx_pool_init_lbl_12_data_D38__fzgx_offset_134 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x5DCC, 0x120, 0x0, 0x2, 0xBB80, 0xC1C0, 0x0
}};
static union { u32 w[1]; long v; } fzgx_pool_init_lbl_12_data_D38__fzgx_offset_150 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x800
}};

static int lbl_12_bss_1B9B0;
static int lbl_12_bss_1B9B0__fzgx_offset_4;
static int lbl_12_bss_1B9B0__fzgx_offset_8;
static int lbl_12_bss_1B9B0__fzgx_offset_C;
static int lbl_12_bss_1B9B0__fzgx_offset_10;
static int lbl_12_bss_1B9B0__fzgx_offset_14;
static long lbl_12_bss_1B9B0__fzgx_offset_18;
static int lbl_12_bss_1B9B0__fzgx_offset_1C;
static unsigned char *lbl_12_bss_1B9B0__fzgx_offset_20;

extern int fn_12_38340(MwsPlayer *, MwsCreateParams *, MwsReferenceBuffers *);
extern void fn_12_2A6FC(SfdMpvParameters *, void **, void **);
extern void fn_12_2145C(SfdAdxtParameters *);
extern SfdHandle *fn_12_2BCF4(SfdCreateConfig *, int);
extern int fn_12_249BC(SfdHandle *, void (*)(int, int), MwsPlayer *);
extern void fn_12_388C4(int, int);

static const union { u32 w[2]; const u32 v[2]; } fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_1B4 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3FE00000, 0x0
}}; /* 0.5 */
static const union { u8 w[34]; const char v[34]; } fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_1BC = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45, 0x32, 0x30, 0x31, 0x33, 0x20, 0x6D, 0x77,
    0x50, 0x6C, 0x79, 0x43, 0x72, 0x65, 0x61, 0x74,
    0x65, 0x3A, 0x63, 0x61, 0x6E, 0x27, 0x74, 0x20,
    0x63, 0x72, 0x65, 0x61, 0x74, 0x65, 0x20, 0x53,
    0x4A, 0x0
}};
static const union { u8 w[34]; const char v[34]; } fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_1E0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45, 0x32, 0x30, 0x32, 0x30, 0x20, 0x6D, 0x77,
    0x50, 0x6C, 0x79, 0x43, 0x72, 0x65, 0x61, 0x74,
    0x65, 0x3A, 0x63, 0x61, 0x6E, 0x27, 0x74, 0x20,
    0x63, 0x72, 0x65, 0x61, 0x74, 0x65, 0x20, 0x53,
    0x4A, 0x0
}};
static const union { u32 w[7]; const char v[28]; } fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_204 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45323031, 0x3138353A, 0x2063616E, 0x27742063, 0x72656174, 0x65205366, 0x78486E00
}};
static const union { u32 w[10]; const char v[40]; } fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_220 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45323031, 0x32313220, 0x6D77506C, 0x79437265, 0x6174653A, 0x2063616E, 0x27742073, 0x65742041,
    0x6464496E, 0x66534A00
}};
static const union { u32 w[3]; const u32 v[3]; } fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_248 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x43300000, 0x80000000  /* fzgx-allow: A1 retail data bytes */
}}; /* pad + int-to-double bias */
static const union { u8 w[49]; const char v[49]; } fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_254 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45, 0x30, 0x32, 0x30, 0x33, 0x32, 0x36, 0x31,
    0x3A, 0x20, 0x4D, 0x57, 0x53, 0x46, 0x43, 0x52,
    0x45, 0x5F, 0x52, 0x65, 0x73, 0x65, 0x74, 0x53,
    0x66, 0x64, 0x48, 0x6E, 0x3A, 0x20, 0x53, 0x46,
    0x44, 0x5F, 0x53, 0x74, 0x6F, 0x70, 0x28, 0x29,
    0x20, 0x66, 0x61, 0x69, 0x6C, 0x65, 0x64, 0x2E,
    0x0
}};
static const union { u8 w[53]; const char v[53]; } fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_288 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45, 0x30, 0x32, 0x30, 0x33, 0x32, 0x36, 0x32,
    0x3A, 0x20, 0x4D, 0x57, 0x53, 0x46, 0x43, 0x52,
    0x45, 0x5F, 0x52, 0x65, 0x73, 0x65, 0x74, 0x53,
    0x66, 0x64, 0x48, 0x6E, 0x3A, 0x20, 0x53, 0x46,
    0x44, 0x5F, 0x53, 0x65, 0x74, 0x45, 0x72, 0x72,
    0x46, 0x6E, 0x28, 0x29, 0x20, 0x66, 0x61, 0x69,
    0x6C, 0x65, 0x64, 0x2E, 0x0
}};
static const union { u32 w[14]; const char v[0x38]; } fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_2C0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45303231, 0x32303530, 0x333A206D, 0x77506C79, 0x41747461, 0x63685069, 0x63557372, 0x42756628,
    0x293A2062, 0x75667369, 0x7A652069, 0x73207368, 0x6F72742E, 0x0
}};
static const char lbl_12_rodata_2184[0x28] = "E206011: MwsfdCrePrm: illigal buffmt.";
static const union { u32 w[7]; const char v[0x1C]; } fzgx_pool_init_lbl_12_rodata_2184__fzgx_offset_28 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45323035, 0x33303032, 0x3A206E6F, 0x7420656E, 0x6F756768, 0x20776F72, 0x6B000000
}};
static const union { u32 w[11]; const char v[0x2C]; } fzgx_pool_init_lbl_12_rodata_2184__fzgx_offset_44 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45323030, 0x31303730, 0x3343206D, 0x77506C79, 0x43726561, 0x7465536F, 0x66646563, 0x3A206372,
    0x65617465, 0x20657272, 0x6F720000
}};
static const union { u32 w[10]; const char v[0x28]; } fzgx_pool_init_lbl_12_rodata_2184__fzgx_offset_70 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45323030, 0x31303730, 0x3344206D, 0x77506C79, 0x43726561, 0x7465536F, 0x66646563, 0x3A207365,
    0x74206572, 0x72636200
}};

#pragma section code_type ".fzgxpool"
static void mwsfdcre_layout(void) {
    const void *volatile object; /* fzgx-allow: S2 readonly object first-access order */
    object = &lbl_12_rodata_1D88;
    object = &lbl_12_rodata_1DAC;
    object = &lbl_12_rodata_1DD0;
    object = lbl_12_rodata_1DF4;
    object = lbl_12_rodata_1E18;
    object = lbl_12_rodata_1E40;
    object = lbl_12_rodata_1E6C;
    object = lbl_12_rodata_1E8C;
    object = fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_18.v;
    object = fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_3C.v;
    object = fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_64.v;
    object = fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_88.v;
    object = fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_B4.v;
    object = fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_E0.v;
    object = fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_11C.v;
    object = fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_140.v;
    object = fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_178.v;
    object = fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_1B4.v;
    object = fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_1BC.v;
    object = fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_1E0.v;
    object = fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_204.v;
    object = fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_220.v;
    object = fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_248.v;
    object = fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_254.v;
    object = fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_288.v;
    object = fzgx_pool_init_lbl_12_rodata_1E8C__fzgx_offset_2C0.v;
    object = lbl_12_rodata_2184;
    object = fzgx_pool_init_lbl_12_rodata_2184__fzgx_offset_28.v;
    object = fzgx_pool_init_lbl_12_rodata_2184__fzgx_offset_44.v;
    object = fzgx_pool_init_lbl_12_rodata_2184__fzgx_offset_70.v;
    object = &lbl_12_bss_1B9B0;
    object = &lbl_12_bss_1B9B0__fzgx_offset_4;
    object = &lbl_12_bss_1B9B0__fzgx_offset_8;
    object = &lbl_12_bss_1B9B0__fzgx_offset_C;
    object = &lbl_12_bss_1B9B0__fzgx_offset_10;
    object = &lbl_12_bss_1B9B0__fzgx_offset_14;
    object = &lbl_12_bss_1B9B0__fzgx_offset_18;
    object = &lbl_12_bss_1B9B0__fzgx_offset_1C;
    object = &lbl_12_bss_1B9B0__fzgx_offset_20;
    object = &fzgx_pool_init_lbl_12_data_D38.v;
    object = &fzgx_pool_init_lbl_12_data_D38__fzgx_offset_44.v;
    object = &fzgx_pool_init_lbl_12_data_D38__fzgx_offset_88.v;
    object = &fzgx_pool_init_lbl_12_data_D38__fzgx_offset_CC.v;
    object = &fzgx_pool_init_lbl_12_data_D38__fzgx_offset_110.v;
    object = &fzgx_pool_init_lbl_12_data_D38__fzgx_offset_134.v;
    object = &fzgx_pool_init_lbl_12_data_D38__fzgx_offset_150.v;
}
#pragma section code_type ".text"

static inline void *mwsfcre_Alloc(MwsPlayer *player, long size) {
    MwsLibraryWork *work;
    void *memory;
    if (player->allocation_count >= 32) {
        MWSFSVM_Error(lbl_12_rodata_1DF4);
        return 0;
    }
    if (size < 0) return 0;
    if (player->arena != 0) {
        if (player->arena_used + size > player->arena_size) {
            memory = 0;
        } else {
            memory = player->arena_cursor;
            player->arena_cursor += size;
            player->arena_used += size;
        }
    } else {
        work = fn_12_38DBC();
        memory = work->malloc_fn(work->allocator_object, size);
    }
    if (memory != 0) {
        player->allocations[player->allocation_count] = memory;
        player->allocation_count++;
    }
    return memory;
}

static inline void mwsfcre_FreeAll(MwsPlayer *player) {
    MwsLibraryWork *work;
    int index;
    void *memory;
    for (index = 0; index < 32; index++) {
        int reverse_index = 31 - index;
        memory = player->allocations[reverse_index];
        if (memory != 0) {
            if (player->arena == 0) {
                work = fn_12_38DBC();
                work->free_fn(work->allocator_object, memory);
            }
            player->allocation_count--;
            player->allocations[reverse_index] = 0;
        }
    }
}

static inline int mwsfcre_CalcFrameSize(int source_width, int source_height) {
    int height;
    int width;
    int luma_size;
    int chroma_size;

    width = (source_width + 15) / 16 * 16;
    height = (source_height + 15) / 16 * 16;
    luma_size = height * ((width + 31) / 32 * 32);
    chroma_size = (height / 2) * ((width / 2 + 31) / 32 * 32);
    return luma_size + chroma_size * 2 + 0x20;
}

static inline int mwsfcre_CnvBufFmt(int format) {
    int result;
    switch (format) {
    case 0: result = 3; break;
    case 1: result = 1; break;
    case 2: result = 2; break;
    case 3: result = 3; break;
    default:
        MWSFSVM_Error(lbl_12_rodata_2184);
        result = 3;
        break;
    }
    return result;
}

static inline int mwsfcre_MallocFrmTbl(MwsPlayer *player, const MwsCreateParams *params, void **frame_buffers) {
    int result = 0;
    int frame_count = params->frame_count;
    int frame_size;
    int index;
    int width;
    int height;

    width = params->width;
    height = params->height;
    if (params->buffer_format >= 4 || params->buffer_format < 0)
        MWSFSVM_Error(lbl_12_rodata_2184);
    frame_size = mwsfcre_CalcFrameSize(width, height);
    for (index = 0; index < frame_count; index++) {
        frame_buffers[index] = mwsfcre_Alloc(player, frame_size);
        if (frame_buffers[index] == 0) result = -1;
    }
    return result;
}

static inline void *mwsfcre_MallocWk(MwsPlayer *player, long work_size) {
    long size = work_size;
    return mwsfcre_Alloc(player, size);
}

static inline void *mwsfcre_MallocX(MwsPlayer *player, int size) {
    return mwsfcre_Alloc(player, size);
}

#pragma opt_dead_assignments off
SfdHandle *fn_12_3763C(MwsPlayer *player, MwsCreateParams *params) {
    int frame_height;
    int frame_width;
    int table_frames;
    void *shared_work;
    void *stream_work;
    int frame_result;
    MwsPictureUserWork *picture_user_work;
    void *decoder_work;
    void *video_work;
    void *filename_work;
    int file_type;
    void *audio_stream_buffer;
    void *audio_decoder_work;
    int frame_count;
    int width;
    int height;
    MwsReferenceBuffers references;
    void *frame_buffers[16];
    SfdCreateConfig create;
    SfdHandle *sfd;
    int frame_size;
    int rfb_result;
    int output_format;
    int allocation_size;
    MwsPictureUserConfig *picture_user;
    int current_height;
    int current_width;
    int sector_count;
    int bps;

    file_type = params->file_type;
    frame_count = params->frame_count;
    width = params->width;
    height = params->height;
    sector_count = params->decoder_count;

    bps = params->maximum_bps;
    if (sector_count <= 0) {
        sector_count = 1;
    }
    if (file_type == 2) {
        lbl_12_bss_1B9B0__fzgx_offset_1C = sector_count * (bps / 8 / 0x800 * 0x800);
        lbl_12_bss_1B9B0__fzgx_offset_18 = 0;
        lbl_12_bss_1B9B0__fzgx_offset_14 = 0;
        lbl_12_bss_1B9B0__fzgx_offset_10 = 0;
        lbl_12_bss_1B9B0 = 0;
        lbl_12_bss_1B9B0__fzgx_offset_4 = 0;
    } else if (file_type == 3) {
        lbl_12_bss_1B9B0__fzgx_offset_1C = sector_count * (bps / 8 / 0x800 * 0x800);
        lbl_12_bss_1B9B0__fzgx_offset_14 = bps / 8 / 0x800 * 0x800 / 2 + 0x800;
        lbl_12_bss_1B9B0__fzgx_offset_18 = 0;
        lbl_12_bss_1B9B0__fzgx_offset_10 = 0;
        lbl_12_bss_1B9B0 = 0;
        lbl_12_bss_1B9B0__fzgx_offset_4 = 0;
    } else {
        lbl_12_bss_1B9B0__fzgx_offset_1C = sector_count * (bps / 8 / 0x800 * 0x800);
        lbl_12_bss_1B9B0__fzgx_offset_14 = bps / 8 / 0x800 * 0x800 / 2 + 0x800;
        lbl_12_bss_1B9B0__fzgx_offset_18 = 0;
        lbl_12_bss_1B9B0__fzgx_offset_10 = 0x5DCC;
        lbl_12_bss_1B9B0 = 0x5F0C;
        lbl_12_bss_1B9B0__fzgx_offset_4 = 0xC1C0;
    }

    table_frames = params->frame_count;
    frame_width = params->width;
    frame_height = params->height;
    if (params->buffer_format >= 4 || params->buffer_format < 0) {
        MWSFSVM_Error(lbl_12_rodata_2184);
    }
    frame_size = mwsfcre_CalcFrameSize(frame_width, frame_height);
    lbl_12_bss_1B9B0__fzgx_offset_C = frame_size * 2;
    lbl_12_bss_1B9B0__fzgx_offset_8 = table_frames * frame_size;

    allocation_size = lbl_12_bss_1B9B0__fzgx_offset_18 + lbl_12_bss_1B9B0__fzgx_offset_14 + lbl_12_bss_1B9B0__fzgx_offset_10 + 0x20;
    shared_work = mwsfcre_Alloc(player, allocation_size);
    allocation_size = lbl_12_bss_1B9B0__fzgx_offset_1C + 0x40;
    stream_work = mwsfcre_Alloc(player, allocation_size);
    rfb_result = fn_12_38340(player, params, &references);
    frame_result = mwsfcre_MallocFrmTbl(player, params, frame_buffers);

    allocation_size = lbl_12_bss_1B9B0;
    audio_stream_buffer = mwsfcre_Alloc(player, allocation_size);
    allocation_size = lbl_12_bss_1B9B0__fzgx_offset_4;
    audio_decoder_work = mwsfcre_Alloc(player, allocation_size);
    picture_user_work = mwsfcre_MallocX(player, sizeof(*picture_user_work));
    decoder_work = mwsfcre_MallocWk(player, 0x4000);
    video_work = mwsfcre_MallocWk(player, 0x700);
    filename_work = mwsfcre_MallocX(player, 0x100);
    if (shared_work == 0 || stream_work == 0 || rfb_result != 0 ||
        frame_result != 0 || audio_stream_buffer == 0 || audio_decoder_work == 0 ||
        picture_user_work == 0 || decoder_work == 0 ||
        filename_work == 0 || video_work == 0) {
        MWSFSVM_Error(fzgx_pool_init_lbl_12_rodata_2184__fzgx_offset_28.v);
        mwsfcre_FreeAll(player);
        return 0;
    }

    lbl_12_bss_1B9B0__fzgx_offset_20 = (unsigned char *)(((unsigned int)stream_work + 0x3F) & ~0x3F);
    current_width = params->width;
    current_height = params->height;
    fzgx_pool_init_lbl_12_data_D38__fzgx_offset_110.v.chroma_width = (((current_width / 2) + 31) / 32) * 32;
    fzgx_pool_init_lbl_12_data_D38__fzgx_offset_110.v.chroma_height = current_height / 2;
    fzgx_pool_init_lbl_12_data_D38__fzgx_offset_110.v.width = current_width;
    fzgx_pool_init_lbl_12_data_D38__fzgx_offset_110.v.height = current_height;
    fzgx_pool_init_lbl_12_data_D38__fzgx_offset_110.v.reference_buffer = 0;
    fzgx_pool_init_lbl_12_data_D38__fzgx_offset_110.v.maximum_width = current_width;
    fzgx_pool_init_lbl_12_data_D38__fzgx_offset_110.v.maximum_height = current_height;
    fzgx_pool_init_lbl_12_data_D38__fzgx_offset_110.v.frame_count = frame_count;
    fzgx_pool_init_lbl_12_data_D38__fzgx_offset_110.v.frame_buffer = 0;
    fzgx_pool_init_lbl_12_data_D38__fzgx_offset_134.v.stream_buffer = audio_stream_buffer;
    fzgx_pool_init_lbl_12_data_D38__fzgx_offset_134.v.decoder_buffer = audio_decoder_work;

    switch (file_type) {
    case 1:
        create = fzgx_pool_init_lbl_12_data_D38__fzgx_offset_44.v;
        player->input_buffer = lbl_12_bss_1B9B0__fzgx_offset_20;
        player->input_buffer_size = lbl_12_bss_1B9B0__fzgx_offset_1C - 0x800;
        player->input_buffer_extra_size = 0x800;
        break;
    case 2:
        create = fzgx_pool_init_lbl_12_data_D38__fzgx_offset_88.v;
        player->input_buffer = lbl_12_bss_1B9B0__fzgx_offset_20;
        player->input_buffer_size = lbl_12_bss_1B9B0__fzgx_offset_1C - 0x800;
        player->input_buffer_extra_size = 0x800;
        break;
    case 3:
        create = fzgx_pool_init_lbl_12_data_D38__fzgx_offset_CC.v;
        player->input_buffer = lbl_12_bss_1B9B0__fzgx_offset_20;
        player->input_buffer_size = lbl_12_bss_1B9B0__fzgx_offset_1C - 0x800;
        player->input_buffer_extra_size = 0x800;
        break;
    }
    create.buffer.ring_alignment = fzgx_pool_init_lbl_12_data_D38__fzgx_offset_150.v;
    if (lbl_12_bss_1B9B0__fzgx_offset_18 != 0) {
        lbl_12_bss_1B9B0__fzgx_offset_18 = lbl_12_bss_1B9B0__fzgx_offset_18 - lbl_12_bss_1B9B0__fzgx_offset_18 % fzgx_pool_init_lbl_12_data_D38__fzgx_offset_150.v;
    }

    output_format = mwsfcre_CnvBufFmt(params->buffer_format);
    create.buffer.memory = shared_work;
    create.buffer.buffer_sizes[0] = lbl_12_bss_1B9B0__fzgx_offset_18;
    create.buffer.buffer_sizes[1] = lbl_12_bss_1B9B0__fzgx_offset_14;
    create.buffer.buffer_sizes[2] = lbl_12_bss_1B9B0__fzgx_offset_10;
    create.picture_user_buffer_minimum = frame_count;
    create.maximum_width = width;
    create.maximum_height = height;
    create.video_output_format = output_format;
    create.handle_memory = decoder_work;
    create.handle_memory_size = 0x4000;
    fn_12_2A6FC(&fzgx_pool_init_lbl_12_data_D38__fzgx_offset_110.v, references.buffers, frame_buffers);
    switch (file_type) {
    case 1:
        fn_12_2145C(&fzgx_pool_init_lbl_12_data_D38__fzgx_offset_134.v);
        break;
    case 2:
    case 3:
        break;
    }
    sfd = fn_12_2BCF4(&create, 0);
    if (sfd == 0) {
        fn_12_38A0C(-0x131);
        MWSFSVM_Error(fzgx_pool_init_lbl_12_rodata_2184__fzgx_offset_44.v);
        return 0;
    }
    if (fn_12_249BC(sfd, fn_12_388C4, player) != 0) {
        fn_12_38A0C(-0x12F);
        MWSFSVM_Error(fzgx_pool_init_lbl_12_rodata_2184__fzgx_offset_70.v);
        return 0;
    }
    player->filename = filename_work;
    player->filename_capacity = 0x100;
    player->picture_user_work = picture_user_work;
    player->picture_user_header_size = sizeof(picture_user_work->header);
    player->picture_user_write = 0;
    player->picture_user_read = 0;
    picture_user = &player->internal_picture_user;
    picture_user->buffer = picture_user_work->element_buffer;
    picture_user->buffer_size = sizeof(picture_user_work->element_buffer);
    picture_user->element_size = 0x40;
    player->picture_user = picture_user;
    return sfd;
}
#pragma opt_dead_assignments reset

