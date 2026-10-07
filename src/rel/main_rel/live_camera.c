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
extern s16 fn_1_7B054(void);
extern void fn_1_10138();
extern void fn_1_8840(void);
extern u32 fn_1_A1588(Sig_ADXT_Stop_ADXTHandle *, u32);
extern u32 fn_1_A1CE8(u32);
extern s32 fn_1_F2F34(void);
extern u8 fn_1_3F1F8(void);
extern int fn_1_45730(char *, Sig_fn_1_45730_LoadResult *);
extern u32 fn_1_45B2C(Sig_fn_1_45730_LoadResult *);
extern u32 fn_1_4630();
extern void fn_1_458A0(Sig_fn_1_45730_LoadResult *, void *, u32, u32);
extern void fn_1_45850(Sig_fn_1_45730_LoadResult *);
extern void fn_80006E10(u32 arg0);
extern int sprintf(char *s, const char *format, ...);
extern u32 lbl_801A6410;
extern const f64 lbl_1_rodata_580;
extern const f64 lbl_1_rodata_588;
extern u32 lbl_1_bss_F5C;
extern s32 camera_get_state(void);
extern u32 lbl_801A63C0;
extern u32 fn_1_107B8(Sig_fn_1_101D0_Fn_1_101D0_State *);
extern u32 fn_1_864E8(int index);
extern u8 fn_1_86624(void);
extern void camera_set_result(s16 value);
extern void camera_set_selected_value(u8 value);
extern void fn_1_5370(s32, s16);
extern s32 fn_80008E30(u32);
extern s32 fn_1_40BB4(void);
extern void *lbl_8006D5A4(void *, void *, void *, f32);
extern void fn_1_862D4(s16, Vec3 *);
extern void fn_1_8636C(int index, void *arg);
extern void fn_1_862A8(s16, void *);
extern void lbl_8006DC6C(void *);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern u32 fn_1_20A5C(void *, void *);
extern void fn_1_15578(void *, fn_1_11544_LiveCamVec *, void *, void *, u32, void *, u32, u32, u32, u32);
extern int fn_1_4C10(void);
extern u32 fn_1_F45A4(void);
extern u32 fn_1_F4594(void);
extern void *fn_1_86254(int index);
extern void fn_1_6DD0(void *);
extern void fn_1_8A0C(s16 index);
extern u32 fn_1_56B8(void);
extern f32 lbl_1_rodata_4E0[];
extern f32 lbl_1_bss_1160[403];
extern u32 fn_1_A1964(u32);
extern void fn_1_A2D84(u32 arg0);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_8006E2B0(void *, Vec3 *);
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u8 lbl_1_bss_17B4[12];
extern char *fn_80083DB0(char *dst, const char *src);
extern u32 *fn_1_1304C(Obj_1_bss_3B30 *, u32);
extern u8 lbl_1_bss_1810[8984];
extern void fn_8000659C(void);
extern u32 OSIsThreadTerminated(u8 *);
extern u32 *fn_1_1289C(u32 *);
extern f32 lbl_1_rodata_4F4[19];
extern const f64 lbl_1_rodata_548[2];
extern s32 lbl_8006D24C(f32, f32);

/* fzgx:begin fn_1_DA34 */
// Reports the camera source location and message used by this routine.
void fn_1_DA34(void) {
    OSPanic( (const char *)(u8 *)(lbl_1_data_4420), 0x34, (const char *)(u8 *)(lbl_1_data_4430));
}
/* fzgx:end fn_1_DA34 */

/* fzgx:begin fn_1_DA6C */
typedef struct {
    u8 pad_0[6];
    s16 unk_6;
    s16 unk_8;
} DA6CArg;

// Cycle the live camera target, wrapping indices and skipping unavailable entries.
void fn_1_DA6C(DA6CArg *state) {
    s16 originalIndex;
    s32 direction;
    struct { s32 value; } targetIndex;
    u32 flags;
    s32 count;
    u32 selectionDeadline;

    if (lbl_1_bss_115C == 0) {
        return;
    }
    if (fn_1_4C10() != 0) {
        return;
    }
    if (fn_1_40BB4() != 0) {
        return;
    }
    if ((s32)fn_1_F2F34() == 0) {
        return;
    }
    selectionDeadline = fn_1_F45A4() - 30;
    if (fn_1_F4594() >= selectionDeadline) {
        return;
    }

    direction = 1;
    if ((lbl_1_bss_9F8.unk_A >> 6) & 1) {
        direction = 1;
        *(s8 *)((u8 *)fn_1_86254(state->unk_6) + 0x475) = -1;
        state->unk_6++;
        count = (s8)fn_1_86624();
        if (state->unk_6 > count - 1) {
            targetIndex.value = 0;
        } else if (state->unk_6 < 0) {
            targetIndex.value = (s8)fn_1_86624() - 1;
        } else {
            targetIndex.value = state->unk_6;
        }
        *(s8 *)((u8 *)fn_1_86254(targetIndex.value) + 0x475) = 0;
        fn_1_6DD0(0);
        fn_1_8A0C(0);
        fn_1_56B8();
    }
    if (state->unk_6 >= (s8)fn_1_86624()) {
        state->unk_6 = 0;
    }
    if (state->unk_6 < 0) {
        state->unk_6 = (s8)fn_1_86624() - 1;
    }
    state->unk_8 = state->unk_6;

    if ((lbl_1_bss_9F8.unk_A >> 7) & 1) {
        direction = -1;
        *(s8 *)((u8 *)fn_1_86254(state->unk_6) + 0x475) = -1;
        state->unk_6--;
        count = (s8)fn_1_86624();
        if (state->unk_6 > count - 1) {
            targetIndex.value = 0;
        } else if (state->unk_6 < 0) {
            targetIndex.value = (s8)fn_1_86624() - 1;
        } else {
            targetIndex.value = state->unk_6;
        }
        *(s8 *)((u8 *)fn_1_86254(targetIndex.value) + 0x475) = 0;
        fn_1_6DD0(0);
        fn_1_8A0C(0);
        fn_1_56B8();
    }
    if (state->unk_6 >= (s8)fn_1_86624()) {
        state->unk_6 = 0;
    }
    if (state->unk_6 < 0) {
        state->unk_6 = (s8)fn_1_86624() - 1;
    }
    state->unk_8 = state->unk_6;

    flags = fn_1_864E8(state->unk_6);
    if ((flags & 0x800) && !(flags & 1)) {
        originalIndex = state->unk_6;
        do {
            *(s8 *)((u8 *)fn_1_86254(state->unk_6) + 0x475) = -1;
            state->unk_6 += direction;
            if (state->unk_6 > (s8)fn_1_86624() - 1) {
                targetIndex.value = 0;
            } else if (state->unk_6 < 0) {
                targetIndex.value = (s8)fn_1_86624() - 1;
            } else {
                targetIndex.value = state->unk_6;
            }
            *(s8 *)((u8 *)fn_1_86254(targetIndex.value) + 0x475) = 0;
            if (state->unk_6 >= (s8)fn_1_86624()) {
                state->unk_6 = 0;
            }
            if (state->unk_6 < 0) {
                state->unk_6 = (s8)fn_1_86624() - 1;
            }
        } while ((fn_1_864E8(state->unk_6) & 0x800) &&
                 originalIndex != state->unk_6);

        if (state->unk_6 >= (s8)fn_1_86624()) {
            state->unk_6 = 0;
        }
        if (state->unk_6 < 0) {
            state->unk_6 = (s8)fn_1_86624() - 1;
        }
        state->unk_8 = state->unk_6;
        if (originalIndex == state->unk_6) {
            camera_set_selected_value(1);
            camera_set_result(state->unk_6);
            fn_1_5370(0, 0);
            camera_set_result(state->unk_6);
            camera_set_selected_value(0);
            return;
        }
        fn_1_56B8();
    }

    if (state->unk_6 >= (s8)fn_1_86624()) {
        state->unk_6 = 0;
    }
    if (state->unk_6 < 0) {
        state->unk_6 = (s8)fn_1_86624() - 1;
    }
    state->unk_8 = state->unk_6;
    camera_set_result(state->unk_6);
}
/* fzgx:end fn_1_DA6C */

/* fzgx:begin fn_1_DE14 */
typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 pad_2[4];
    s16 unk_6;
    u8 pad_8[4];
    u32 unk_C;
    u8 pad_10[0x54];
    u16 unk_64;
} Fn1DE14State;

void fn_1_DE14(Fn1DE14State *state) {
    u8 enabled;

    if (lbl_1_bss_115C == 0) {
        return;
    }
    if (fn_1_4C10() != 0) {
        return;
    }
    if (fn_1_40BB4() != 0) {
        return;
    }
    if ((s32)fn_1_F2F34() == 0) {
        return;
    }
    if (fn_1_F4594() >= fn_1_F45A4() - 0x1e) {
        return;
    }

    enabled = 0;
    if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) {
        enabled = 1;
    }
    if (enabled == 0) {
        return;
    }

    lbl_1_bss_1160[0] = lbl_1_rodata_4E0[0];
    if (state->unk_1 == 0) {
        state->unk_0++;
    } else {
        state->unk_1++;
    }
    if (state->unk_0 >= 4) {
        state->unk_0 = 0;
        state->unk_1 = 1;
    }

    switch (state->unk_1) {
    case 1:
        fn_1_5370(0, state->unk_6);
        break;
    case 2:
        fn_1_5370(1, state->unk_6);
        state->unk_1 = 0;
    default:
        fn_1_5370(1, state->unk_6);
    case 0:
        break;
    }

    state->unk_64 = 0;
    state->unk_C &= ~0x00200000;
    fn_1_6DD0( (void *)(u32)(0));
}
/* fzgx:end fn_1_DE14 */

/* fzgx:begin fn_1_E174 */
#pragma opt_lifetimes off
#pragma opt_propagation off
#pragma opt_strength_reduction off
static inline void fn_1_E174_store(s16 value, s16 *destination) { *destination = value; }
void fn_1_E174(f32 arg0) {
    f32 fzgx_live;
    s16 fzgx_value;
    Obj_1_bss_1148 *p_lbl_1_bss_1148;
    Obj_1_data_43B8 *p_lbl_1_data_43B8;
    struct fn_1_E174_lbl_1_rodata_4E0 *p_lbl_1_rodata_4E0;
    Obj_1_bss_9F8 *p_lbl_1_bss_9F8;
    s16 v0;
    u32 v1;
    s32 v2;
    f32 v3;
    u32 v5;
    s16 v4;
    u32 v6;
    f32 v7;
    u32 v8;
    f32 v9;
    s32 v10;
    s16 v11;
    u32 v12;
    u32 v13;
    f32 v14;
    f32 v15;
    f32 v16;
    s32 v17;
    u32 t7;
    u32 t8;
    u32 t9;
    u32 t10;
    u32 t11;
    u32 t12;
    u32 t13;
    u32 t14;
    u32 t15;
    u32 t16;
    u32 t19;
    u32 t20;
    u32 t21;
    u32 t22;
    u32 t23;
    u32 t24;
    u32 t25;
    u32 t26;
    p_lbl_1_data_43B8 = (Obj_1_data_43B8 *)&lbl_1_data_43B8;
    p_lbl_1_bss_1148 = (Obj_1_bss_1148 *)&lbl_1_bss_1148;
    p_lbl_1_rodata_4E0 = (struct fn_1_E174_lbl_1_rodata_4E0 *)&lbl_1_rodata_4E0;
    if (((10) == (*(s16 *)&lbl_1_bss_960))) {
    fn_1_A1CE8((p_lbl_1_data_43B8->unk_148 & 0xFF));
    } else {
    if (((12) == (*(s16 *)&lbl_1_bss_960)) || (s32)fn_1_F2F34() != 0) {
    v0 = p_lbl_1_data_43B8->unk_148;
    v1 = (v0 - 41);
    switch ((s32)v1) {
    case 1:
    fn_1_A1CE8(((((1) + (v0))) & 0xFF));
    break;
    case 2:
    fn_1_A1CE8(((((1) + (v0))) & 0xFF));
    break;
    default:
    fn_1_A1CE8((v0 & 0xFF));
    }
    }
    }
    v3 = arg0;
    if (p_lbl_1_bss_1148->unk_14 != 0 && (s32)fn_1_40BB4() == 0 && (s32)fn_1_F2F34() != 0) {
    if (p_lbl_1_bss_1148->unk_664 != 0) {
    p_lbl_1_data_43B8->unk_14A = 41;
    p_lbl_1_bss_1148->unk_664 = 0;
    if (p_lbl_1_data_43B8->unk_148 != 41) {
    p_lbl_1_data_43B8->unk_148 = 41;
    lbl_1_bss_6F243 = 0;
    }
    v2 = p_lbl_1_data_43B8->unk_148;
    if (v2 < 41) {
    v2 = (v2 & 0xFF);
    t7 = fn_1_A1964(v2);
    v2 = t7;
    v2 = (p_lbl_1_data_43B8->unk_148 & 0xFF);
    t8 = fn_1_A1CE8(v2);
    v2 = t8;
    } else {
    v5 = (v2 - 41);
    switch ((s32)v5) {
    case 0:
    v2 = (u32)&lbl_1_bss_6EAD0;
    v2 = *(u32 *)((u8 *)v2 + 0);
    v2 = *(u32 *)((u8 *)v2 + 0);
    t9 = fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)v2, 38);
    v2 = t9;
    v2 = (p_lbl_1_data_43B8->unk_148 & 0xFF);
    t10 = fn_1_A1CE8(v2);
    v2 = t10;
    break;
    case 1:
    v2 = (u32)&lbl_1_bss_6EAD0;
    v2 = *(u32 *)((u8 *)v2 + 0);
    v2 = *(u32 *)((u8 *)v2 + 0);
    t11 = fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)v2, 44);
    v2 = t11;
    v2 = p_lbl_1_data_43B8->unk_148;
    v2 = ((v2 + 1) & 0xFF);
    t12 = fn_1_A1CE8(v2);
    v2 = t12;
    break;
    case 2:
    v2 = (u32)&lbl_1_bss_6EAD0;
    v2 = *(u32 *)((u8 *)v2 + 0);
    v2 = *(u32 *)((u8 *)v2 + 0);
    t13 = fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)v2, 43);
    v2 = t13;
    v2 = p_lbl_1_data_43B8->unk_148;
    v2 = ((v2 + 1) & 0xFF);
    t14 = fn_1_A1CE8(v2);
    v2 = t14;
    break;
    default:
    v2 = (u32)&lbl_1_bss_6EAD0;
    v2 = *(u32 *)((u8 *)v2 + 0);
    v2 = *(u32 *)((u8 *)v2 + 0);
    t15 = fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)v2, 38);
    v2 = t15;
    v2 = (p_lbl_1_data_43B8->unk_148 & 0xFF);
    t16 = fn_1_A1CE8(v2);
    v2 = t16;
    }
    }
    }
    if (((12) == (*(s16 *)&lbl_1_bss_960))) {
    p_lbl_1_bss_9F8 = (Obj_1_bss_9F8 *)&lbl_1_bss_9F8;
    if (((p_lbl_1_bss_9F8->unk_12 >> 9) & 0x1) != 0) {
    v3 = (p_lbl_1_rodata_4E0->unk_1C);
    v2 = 0xA9010000;
    v6 = (p_lbl_1_bss_1148->unk_2E + 1);
    v7 = p_lbl_1_bss_1148->unk_24;
    p_lbl_1_bss_1148->unk_2E = v6;
    v2 += 1536;
    p_lbl_1_data_43B8->unk_14C = 60;
    p_lbl_1_bss_1148->unk_8 = v3;
    p_lbl_1_bss_1148->unk_C = v7;
    fn_1_A2D84(v2);
    }
    if (((p_lbl_1_bss_9F8->unk_12 >> 8) & 0x1) != 0) {
    v2 = 0xA9010000;
    v3 = (p_lbl_1_rodata_4E0->unk_1C);
    v8 = (p_lbl_1_bss_1148->unk_2E - 1);
    v9 = (-p_lbl_1_bss_1148->unk_24);
    fn_1_E174_store(60, &(p_lbl_1_data_43B8->unk_14C));
    v2 += 1536;
    fzgx_value = v8;
    p_lbl_1_bss_1148->unk_2E = fzgx_value;
    p_lbl_1_bss_1148->unk_8 = v3;
    p_lbl_1_bss_1148->unk_C = v9;
    fn_1_A2D84(v2);
    }
    }
    v2 = p_lbl_1_data_43B8->unk_14C;
    if (v2 != 0) {
    p_lbl_1_data_43B8->unk_14C = (v2 - 1);
    } else {
    v3 = p_lbl_1_bss_1148->unk_8;
    if (v3 != (p_lbl_1_rodata_4E0->unk_14)) {
    p_lbl_1_bss_1148->unk_8 = (v3 - (p_lbl_1_rodata_4E0->unk_20));
    }
    }
    if (p_lbl_1_bss_1148->unk_2E < 0) {
    v2 = p_lbl_1_bss_1148->unk_608;
    p_lbl_1_bss_1148->unk_2E = (v2 - 1);
    }
    v2 = p_lbl_1_bss_1148->unk_608;
    if (p_lbl_1_bss_1148->unk_2E > (s32)(v2 - 1)) {
    p_lbl_1_bss_1148->unk_2E = 0;
    }
    v2 = (u32)((u8 *)(u32)p_lbl_1_bss_1148 + 1548);
    v10 = (s16)(*(s16 *)((u8 *)v2 + (p_lbl_1_bss_1148->unk_2E << 1)));
    p_lbl_1_data_43B8->unk_14A = v10;
    if (v10 < 0) {
    p_lbl_1_data_43B8->unk_14A = 43;
    }
    if (p_lbl_1_data_43B8->unk_14A >= 44) {
    p_lbl_1_data_43B8->unk_14A = 0;
    }
    if (p_lbl_1_data_43B8->unk_148 != (v11 = p_lbl_1_data_43B8->unk_14A) && ((0) == (p_lbl_1_data_43B8->unk_14C))) {
    p_lbl_1_data_43B8->unk_148 = v11;
    lbl_1_bss_6F243 = 0;
    if (v11 < 41) {
    v2 = (v11 & 0xFF);
    t19 = fn_1_A1964(v2);
    v2 = t19;
    } else {
    v12 = (v11 - 41);
    switch ((s32)v12) {
    case 0:
    v2 = (u32)&lbl_1_bss_6EAD0;
    v2 = *(u32 *)((u8 *)v2 + 0);
    v2 = *(u32 *)((u8 *)v2 + 0);
    t20 = fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)v2, 38);
    v2 = t20;
    break;
    case 1:
    v2 = (u32)&lbl_1_bss_6EAD0;
    v2 = *(u32 *)((u8 *)v2 + 0);
    v2 = *(u32 *)((u8 *)v2 + 0);
    t21 = fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)v2, 44);
    v2 = t21;
    break;
    case 2:
    v2 = (u32)&lbl_1_bss_6EAD0;
    v2 = *(u32 *)((u8 *)v2 + 0);
    v2 = *(u32 *)((u8 *)v2 + 0);
    t22 = fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)v2, 43);
    v2 = t22;
    break;
    default:
    v2 = (u32)&lbl_1_bss_6EAD0;
    v2 = *(u32 *)((u8 *)v2 + 0);
    v2 = *(u32 *)((u8 *)v2 + 0);
    t23 = fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)v2, 38);
    v2 = t23;
    }
    }
    }
    v2 = p_lbl_1_data_43B8->unk_148;
    v13 = (v2 - 41);
    switch ((s32)v13) {
    case 1:
    v2 = ((v2 + 1) & 0xFF);
    t24 = fn_1_A1CE8(v2);
    v2 = t24;
    break;
    case 2:
    v2 = ((v2 + 1) & 0xFF);
    t25 = fn_1_A1CE8(v2);
    v2 = t25;
    break;
    default:
    v2 = (v2 & 0xFF);
    t26 = fn_1_A1CE8(v2);
    v2 = t26;
    }
    v2 = (u32)&lbl_1_bss_9F8;
    if (((*(u16 *)((u8 *)v2 + 16) >> 4) & 0x1) != 0) {
    v2 = p_lbl_1_bss_1148->unk_2C;
    p_lbl_1_bss_1148->unk_2C = (v2 + 1);
    }
    if (p_lbl_1_bss_1148->unk_2C >= 4) {
    p_lbl_1_bss_1148->unk_2C = 0;
    }
    v4 = p_lbl_1_bss_1148->unk_2C;
    v2 = (u32)((u8 *)(u32)p_lbl_1_bss_1148 + 24);
    v14 = (p_lbl_1_rodata_4E0->unk_14);
    fzgx_live = p_lbl_1_rodata_4E0->unk_0;
    v15 = (fzgx_live);
    v16 = (p_lbl_1_rodata_4E0->unk_24);
    v17 = 0;
    while ((s16)v17 < 3) {
    if (((s16)v17) == v4) {
    v3 = *(f32 *)((u8 *)v2 + 0);
    v3 = (v3 + v16);
    *(f32 *)((u8 *)v2 + 0) = v3;
    } else {
    v3 = *(f32 *)((u8 *)v2 + 0);
    v3 = (v3 - v16);
    *(f32 *)((u8 *)v2 + 0) = v3;
    }
    v3 = *(f32 *)((u8 *)v2 + 0);
    if (v3 < v14) {
    *(f32 *)((u8 *)v2 + 0) = v14;
    }
    v3 = *(f32 *)((u8 *)v2 + 0);
    if (v3 > v15) {
    *(f32 *)((u8 *)v2 + 0) = v15;
    }
    v2 = (u32)((u8 *)v2 + 4);
    v17++;
    }
    }
}
#pragma opt_strength_reduction reset

#pragma opt_propagation reset

#pragma opt_lifetimes reset
/* fzgx:end fn_1_E174 */

/* fzgx:begin fn_1_EBE4 */
typedef struct {
    f32 x, y, z;
} CamVec3;

/* live camera state object (first argument) */
typedef struct {
    u8 state;        /* 0x00 */
    u8 unk_1;        /* 0x01 */
    u8 pad_2[4];
    s16 unk_6;       /* 0x06 */
    s16 unk_8;       /* 0x08 */
    u8 pad_A[2];
    u32 flags;       /* 0x0C */
    s16 unk_10;      /* 0x10 */
    s16 unk_12;      /* 0x12 */
    s16 unk_14;      /* 0x14 */
    u8 pad_16[2];
    u32 unk_18;      /* 0x18 */
    CamVec3 pos;     /* 0x1C */
    CamVec3 target;  /* 0x28 */
    u8 pad_34[0x28];
    s16 unk_5C;      /* 0x5C */
    u8 pad_5E[2];
    f32 unk_60;      /* 0x60 */
    s16 unk_64;      /* 0x64 */
    u8 pad_66[4];
    s16 unk_6A;      /* 0x6A */
} fn_1_EBE4_LiveCamera;

/* wider views of the TU's shared state than the generated header carries */
typedef struct {
    u8 unk_0;
    u8 pad_1[0xB];
    f32 unk_C;
    u8 pad_10[4];
    u8 unk_14;
    u8 pad_15[0x64F];
    u8 unk_664;
    u8 pad_665;
    s16 unk_666;
    s32 unk_668;
    u8 unk_66C;
    u8 pad_66D[3];
    u32 unk_670;
    u32 unk_674;
    u8 unk_678;
} LiveCameraState;

typedef struct {
    u8 pad_0[0xD0];
    s32 ids[0x1A];   /* 0xD0 */
    u8 pad_138[0x10];
    s16 unk_148;
    s16 unk_14A;
    s16 unk_14C;
} LiveCameraData;

void fn_1_EBE4(fn_1_EBE4_LiveCamera *cam, s16 id, s32 mode, f32 value) {
    LiveCameraData *dat = (LiveCameraData *)&lbl_1_data_43B8;
    LiveCameraState *st = (LiveCameraState *)&lbl_1_bss_1148;
    s32 *ids;
    u32 i;

    st->unk_666 = 0;
    st->unk_668 = -1;
    dat->unk_14C = 0x3C;
    st->unk_C = 0.0f;
    st->unk_14 = 0;
    st->unk_0 = 0;
    st->unk_66C = 0;
    cam->flags &= ~0x00080000;
    for (i = 0, ids = dat->ids; i < 0x1A; i++, ids++) {
        if (*ids == fn_1_7B054()) {
            cam->flags |= 0x00080000;
        }
    }

    if (mode) {
        cam->state = 6;
        cam->unk_12 = 5;
        cam->unk_14 = 0;
        cam->unk_18 = 0;
        cam->unk_10 = 0;
        fn_1_10138(cam);
    } else {
        cam->state = 5;
        cam->unk_12 = 2;
        cam->unk_14 = 9;
        cam->unk_18 = 0;
        cam->unk_10 = 0;
    }
    cam->unk_1 = 0;
    cam->unk_64 = 0xD2;
    cam->unk_6A = 0;
    cam->flags &= ~0x00200000;
    cam->unk_60 = value;
    cam->unk_5C = 0;
    cam->target = cam->pos;
    cam->unk_8 = id;
    cam->unk_6 = id;
    st->unk_670 = 0;
    st->unk_674 = 0;
    fn_1_8840();

    if (*(s16 *)&lbl_1_bss_960 == 10 && !mode) {
        st->unk_664 = 0;
        st->unk_678 = 2;
        cam->state = 0;
        dat->unk_14A = 0x2A;
        lbl_1_bss_6F243 = 0;
        if (dat->unk_148 != 0x2A) {
            dat->unk_148 = 0x2A;
        }
        fn_1_A1588( (Sig_ADXT_Stop_ADXTHandle *)(u32)(lbl_1_bss_6EAD0.unk_0->unk_0), 1);
        fn_1_A1CE8((u8)dat->unk_148);
    } else if (fn_1_F2F34() && !mode) {
        cam->state = 0;
    }

    if (st->unk_664) {
        st->unk_678 = 2;
    }
}
/* fzgx:end fn_1_EBE4 */

/* fzgx:begin fn_1_EE04 */
typedef struct {
    u8 pad[2];
    s16 state;
} Fn1EE04Context;

typedef void (*Fn1EE04Handler)(Fn1EE04Context *, void *);

// Dispatch the active live-camera handler, then advance camera processing.
void fn_1_EE04(Fn1EE04Context *context) {
    ((Fn1EE04Handler *)lbl_1_data_4440)[context->state](
        context, lbl_1_data_4440);
    fn_1_6DD0(0);
}
/* fzgx:end fn_1_EE04 */

/* fzgx:begin fn_1_F6A8 */
#define ALIGN32(n) (((n) + 0x1F) & ~0x1F)

/* Retail rematerialises the __FILE__ string address (dat + 0x68) at each
 * allocation; keep MWCC from hoisting it into a saved register. */
#pragma opt_common_subs off
#pragma opt_propagation off
/* Load the three live-camera data files into freshly allocated buffers. */
void fn_1_F6A8(void) {
    Obj_1_data_43B8 *dat = (Obj_1_data_43B8 *)&lbl_1_data_43B8;
    Obj_1_bss_1148 *st = (Obj_1_bss_1148 *)&lbl_1_bss_1148;
    u32 size;
    s32 mode;
    u32 n;
    char path[128];
    Sig_fn_1_45730_LoadResult file;

    if ((s32)dat->unk_13C >= 0 && (s32)dat->unk_140 >= 0 && (s32)dat->unk_144 >= 0) {
        return;
    }

    fn_80006E10( (u32)((const char *)dat + 0x280));
    dat->unk_13C = 0;
    st->unk_67C = 0;
    dat->unk_140 = 0;
    st->unk_680 = 0;
    dat->unk_144 = 0;
    st->unk_684 = 0;

    mode = (u32)&lbl_1_bss_960;
    mode = *(s16 *)mode;
    if (mode == 10) {
        sprintf(path, (const char *)dat + 0x284, fn_1_3F1F8());
        if (fn_1_45730(path, &file) == 0) {
            sprintf(path, (const char *)dat + 0x2A0);
            fn_1_45730(path, &file);
        }
    } else if (mode == 14) {
        if (lbl_1_bss_525C.unk_191 & 2) {
            switch (lbl_1_bss_525C.unk_192) {
            case 4:
                sprintf(path, (const char *)dat + 0x2BC);
                break;
            case 3:
                sprintf(path, (const char *)dat + 0x2D4);
                break;
            case 2:
                sprintf(path, (const char *)dat + 0x2EC);
                break;
            default:
                sprintf(path, (const char *)dat + 0x2EC);
                break;
            }
        } else {
            sprintf(path, (const char *)dat + 0x304);
        }
        fn_1_45730(path, &file);
    } else {
        sprintf(path, (const char *)dat + 0x324, fn_1_3F1F8());
        if (fn_1_45730(path, &file) == 0) {
            sprintf(path, (const char *)dat + 0x33C);
            fn_1_45730(path, &file);
        }
    }

    dat->unk_13C = fn_1_45B2C(&file) / 84;
    n = ALIGN32(fn_1_45B2C(&file));
    size = n;
    st->unk_67C = (u32)fn_1_4630(lbl_801A6410, n, (const char *)dat + 0x68, 0x58D);
    fn_1_458A0(&file, (void *)st->unk_67C, size, 0);
    fn_1_45850(&file);

    if (fn_1_7B054() == 50) {
        fn_80006E10( (u32)((const char *)dat + 0x350));
        return;
    }

    sprintf(path, (const char *)dat + 0x354, fn_1_3F1F8());
    if (fn_1_45730(path, &file) == 0) {
        sprintf(path, (const char *)dat + 0x364);
        fn_1_45730(path, &file);
    }
    dat->unk_140 = fn_1_45B2C(&file) / 40;
    mode = ALIGN32(fn_1_45B2C(&file));
    size = mode;
    st->unk_680 = (u32)fn_1_4630(lbl_801A6410, size, (const char *)dat + 0x68, 0x5A5);
    fn_1_458A0(&file, (void *)st->unk_680, size, 0);
    fn_1_45850(&file);

    sprintf(path, (const char *)dat + 0x374, fn_1_3F1F8());
    if (fn_1_45730(path, &file) == 0) {
        sprintf(path, (const char *)dat + 0x388);
        fn_1_45730(path, &file);
    }
    dat->unk_144 = fn_1_45B2C(&file) / 12;
    n = ALIGN32(fn_1_45B2C(&file));
    size = n;
    st->unk_684 = (u32)fn_1_4630(lbl_801A6410, size, (const char *)dat + 0x68, 0x5B6);
    fn_1_458A0(&file, (void *)st->unk_684, size, 0);
    fn_1_45850(&file);

    fn_80006E10( (u32)((const char *)dat + 0x350));
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_F6A8 */

/* fzgx:begin fn_1_FA84 */
void fn_1_FA84(void) {
    Obj_1_data_43B8 *p_lbl_1_data_43B8;
    Obj_1_bss_1148 *p_lbl_1_bss_1148;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    u32 v6;
    s32 v7;
    u32 v8;
    p_lbl_1_data_43B8 = (Obj_1_data_43B8 *)&lbl_1_data_43B8;
    p_lbl_1_bss_1148 = (Obj_1_bss_1148 *)&lbl_1_bss_1148;
    v1 = 0;
    v3 = 0;
    if ((s32)p_lbl_1_data_43B8->unk_13C > 0) {
    v0 = (u32)&lbl_801A6410;
    p_lbl_1_data_43B8->unk_13C = -1;
    v0 = *(u32 *)((u8 *)v0 + 0);
    v1 = (u32)((u8 *)(u32)p_lbl_1_data_43B8 + 104);
    v2 = p_lbl_1_bss_1148->unk_67C;
    v3 = 1472;
    fn_1_46B4(v0, v2, (const char *)((u32)v1), v3);
    }
    v4 = v0;
    v5 = v1;
    v6 = v2;
    v7 = v3;
    if ((s32)p_lbl_1_data_43B8->unk_140 > 0) {
    v4 = (u32)&lbl_801A6410;
    p_lbl_1_data_43B8->unk_140 = -1;
    v4 = *(u32 *)((u8 *)v4 + 0);
    v5 = (u32)((u8 *)(u32)p_lbl_1_data_43B8 + 104);
    v6 = p_lbl_1_bss_1148->unk_680;
    v7 = 1473;
    fn_1_46B4(v4, v6, (const char *)((u32)v5), v7);
    }
    v8 = v4;
    if ((s32)p_lbl_1_data_43B8->unk_144 > 0) {
    v8 = (u32)&lbl_801A6410;
    p_lbl_1_data_43B8->unk_144 = -1;
    v8 = *(u32 *)((u8 *)v8 + 0);
    fn_1_46B4(v8, p_lbl_1_bss_1148->unk_684, (const char *)((u32)((u8 *)(u32)p_lbl_1_data_43B8 + 104)), 1474);
    }
}
/* fzgx:end fn_1_FA84 */

/* fzgx:begin fn_1_FB50 */
typedef struct V3_FB50 {
    f32 x, y, z;
} V3_FB50;

typedef struct LiveCam_FB50 {
    u8 pad_00[0x1c];
    V3_FB50 position;
    u8 pad_28[0x84];
    s32 mode;
    s32 timer;
    V3_FB50 saved;
    V3_FB50 offset;
    V3_FB50 velocity;
} LiveCam_FB50;


void fn_1_FB50(LiveCam_FB50 *cam) {
    if (cam->mode == 0) {
        cam->saved = cam->position;
        return;
    }
    if ((lbl_1_bss_F5C & 0x50000000) == 0) {
        f64 t0, t1, t2;
        t0 = lbl_1_rodata_580 * cam->offset.x;
        cam->velocity.x = cam->velocity.x - t0;
        t1 = lbl_1_rodata_580 * cam->offset.y;
        cam->velocity.y = cam->velocity.y - t1;
        t2 = lbl_1_rodata_580 * cam->offset.z;
        cam->velocity.z = cam->velocity.z - t2;
        cam->velocity.x = cam->velocity.x * lbl_1_rodata_588;
        cam->velocity.y = cam->velocity.y * lbl_1_rodata_588;
        cam->velocity.z = cam->velocity.z * lbl_1_rodata_588;
        cam->offset.x = cam->offset.x + cam->velocity.x;
        cam->offset.y = cam->offset.y + cam->velocity.y;
        cam->offset.z = cam->offset.z + cam->velocity.z;
    }
    {
        psvec_add(&cam->saved, &cam->offset, &cam->position);
    }
    if ((lbl_1_bss_F5C & 0x50000000) == 0) {
        if (cam->timer > 0) {
            cam->timer--;
            if (cam->timer == 0) {
                fn_1_8840();
            }
        }
    }
}
/* fzgx:end fn_1_FB50 */

/* fzgx:begin fn_1_FCB0 */
#define NEXT_RAND() (lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 13259)
#define RAND15(v) ((s32)(((v) >> 16) & 0x7FFF))

void fn_1_FCB0(Sig_fn_1_101D0_Fn_1_101D0_State * arg0, f32 arg1) {
    s32 rnd;
    s16 prev14;
    u32 mask;
    s32 start;
    u8 kind;

    kind = arg0->unk_0;
    if (kind == 1 && (arg0->unk_C & 0x80000) != 0) {
        arg0->unk_12 = 4;
        if ((f64)(u32)arg0->unk_64 > 210.0) {
            arg0->unk_64 = 0;
        } else {
            arg0->unk_64 = 210;
        }
        return;
    }
    if (kind == 0) {
        if ((arg0->unk_C & 0x80000) == 0) {
            arg0->unk_12 = (s16)(RAND15(NEXT_RAND()) % 4);
            if ((s32)arg0->unk_12 == arg0->unk_2) {
                arg0->unk_12 = (s16)((arg0->unk_2 + 1) % 4);
            }
        } else {
            arg0->unk_12 = (s16)(RAND15(NEXT_RAND()) % 6);
            if ((s32)arg0->unk_12 >= 5) {
                arg0->unk_12 = 4;
            }
            if ((s32)arg0->unk_12 == arg0->unk_2) {
                if ((s32)arg0->unk_12 == 4) {
                    prev14 = arg0->unk_4;
                    fn_1_107B8(arg0);
                    if (prev14 == (s32)arg0->unk_14) {
                        arg0->unk_12 = (s16)((arg0->unk_2 + 1) % 5);
                    }
                } else {
                    arg0->unk_12 = (s16)((arg0->unk_2 + 1) % 5);
                }
            }
        }
    } else {
        arg0->unk_12 = (s16)(RAND15(NEXT_RAND()) % 6);
        if ((s32)arg0->unk_12 == arg0->unk_2) {
            arg0->unk_12 = (s16)((arg0->unk_2 + 1) % 6);
        }
        if ((s32)arg0->unk_12 == 5) {
            arg0->unk_12 = 4;
        }
        if ((s32)arg0->unk_12 == 4) {
            if ((arg0->unk_C & 0x80000) == 0) {
                arg0->unk_12 = 3;
            }
            if (arg0->unk_0 == 2) {
                arg0->unk_12 = (s16)((arg0->unk_2 + 1) % 3);
            }
        }
        if ((s8)camera_get_state() == 6) {
            if ((s32)arg0->unk_12 == 2) {
                arg0->unk_12 = (s16)(((s32)arg0->unk_12 + 1) % 3);
            }
        }
    }
    if ((f64)(u32)arg0->unk_64 > 210.0) {
        arg0->unk_64 = 0;
    } else {
        arg0->unk_64 = 210;
    }
    if ((s8)camera_get_state() == 6) {
        rnd = RAND15(NEXT_RAND());
        arg0->unk_6 = (s16)(rnd % (s32)(s8)fn_1_86624());
        if ((fn_1_864E8(arg0->unk_6) & 0x1) == 0) {
            mask = 0x8000880;
            if ((fn_1_864E8(arg0->unk_6) & mask) != 0) {
                start = arg0->unk_6;
                do {
                    arg0->unk_6++;
                    if ((s32)arg0->unk_6 >= (s32)(s8)fn_1_86624()) {
                        arg0->unk_6 = 0;
                    }
                    if ((s32)arg0->unk_6 < 0) {
                        arg0->unk_6 = (s8)fn_1_86624() - 1;
                    }
                } while ((fn_1_864E8(arg0->unk_6) & mask) != 0 && start != (s32)arg0->unk_6);
                if (start == (s32)arg0->unk_6) {
                    camera_set_selected_value(1);
                    camera_set_result(arg0->unk_6);
                    fn_1_5370(0, 0);
                    camera_set_result(arg0->unk_6);
                    camera_set_selected_value(0);
                    return;
                }
            }
        }
        arg0->unk_8 = arg0->unk_6;
    }
}
/* fzgx:end fn_1_FCB0 */

/* fzgx:begin fn_1_10138 */
void fn_1_10138(void) {
    Obj_1_bss_17C4_At0 *obj;
    u32 i;
    u32 count;

    lbl_1_bss_17B0 = 0;
    count = lbl_1_data_44F4.unk_0;
    obj = lbl_1_bss_17C4.unk_0;
    i = 0;
    while (i < count) {
        lbl_1_bss_17B0 += (u32)fn_80008E30(obj->unk_0);
        i++;
        obj++;
    }
}
/* fzgx:end fn_1_10138 */

/* fzgx:begin fn_1_101C0 */
u32 fn_1_101C0(void) {
    return lbl_1_bss_17B0;
}
/* fzgx:end fn_1_101C0 */

/* fzgx:begin fn_1_101D0 */
typedef struct {
    u8 pad_0[0x6];
    u16 unk_6;
    u8 pad_8[0x8];
    u16 unk_10;
    u16 unk_12;
    u16 unk_14;
    u8 pad_16[0x2];
    u32 unk_18;
    u8 pad_1C[0x48];
    u16 unk_64;
} Fn_1_101D0_State;


void fn_1_101D0(Fn_1_101D0_State *self) {
    Obj_1_bss_17C4_At0 *base;
    u32 count;
    u32 off;

    count = lbl_1_data_44F4.unk_0;
    base = lbl_1_bss_17C4.unk_0;

    if (self->unk_64 == 0) {
        self->unk_10++;
        off = self->unk_10 * 0x54;
        if (self->unk_10 < count) {
            self->unk_64 = (u32)fn_80008E30(*(u32 *)((u8 *)base + off));
            self->unk_12 = 5;
            self->unk_14 = self->unk_10;
            self->unk_6 = 0;
            self->unk_18 = 1;
        }
        return;
    }
    self->unk_18 = 0;
}
/* fzgx:end fn_1_101D0 */

/* fzgx:begin fn_1_10268 */
typedef struct {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
} Bss_1_17D0;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    f32 unk_1C;
    s16 unk_20;
} Copy_1_10268;

typedef struct {
    u8 pad_0[4];
    s16 unk_4;
    u8 pad_6[0x16];
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u8 pad_28[0x24];
    u32 unk_4C;
    u32 unk_50;
    u32 unk_54;
    f32 unk_58;
    s16 unk_5C;
    u8 pad_5E[0x6];
    s16 unk_64;
} Camera_1_10268;

void fn_1_10268(Camera_1_10268 *arg) {
    Obj_1_bss_17C4_At0 *e;
    Copy_1_10268 t;
    u32 n;
    u32 m;
    f32 a;
    f32 b;

    e = &lbl_1_bss_17C4.unk_0[arg->unk_4];
    t = *(Copy_1_10268 *)((u8 *)e + 8);

    n = (u32)fn_80008E30(e->unk_0);

    ((Bss_1_17D0 *)&lbl_1_bss_17D0)->unk_0 = lbl_1_rodata_4F4[0];
    ((Bss_1_17D0 *)&lbl_1_bss_17D0)->unk_4 = lbl_1_rodata_4E0[0];
    ((Bss_1_17D0 *)&lbl_1_bss_17D0)->unk_10 = lbl_1_rodata_4F4[0];
    ((Bss_1_17D0 *)&lbl_1_bss_17D0)->unk_14 = lbl_1_rodata_4E0[0] / (f32)((n * n) >> 2);
    a = (f32)n;
    ((Bss_1_17D0 *)&lbl_1_bss_17D0)->unk_C = a;
    ((Bss_1_17D0 *)&lbl_1_bss_17D0)->unk_8 = a;

    arg->unk_64 = (u32)fn_80008E30(e->unk_0);

    arg->unk_1C = t.unk_4;
    arg->unk_20 = t.unk_8;
    arg->unk_24 = t.unk_C;
    arg->unk_4C = t.unk_10;
    arg->unk_50 = t.unk_14;
    arg->unk_54 = t.unk_18;
    arg->unk_5C = t.unk_20;
    arg->unk_58 = t.unk_1C;
}
/* fzgx:end fn_1_10268 */

/* fzgx:begin fn_1_103B0 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 300.0f;
    s = 320.0f;
    s = 234.0f;
    s = 230.0f;
    s = 0.0f;
    s = 0.5f;
    s = 2.0f;
    s = 0.009999999776482582f;
    s = 0.019999999552965164f;
}
static const u32 fzgx_pool_table2[4] = {0x0032FFFF, 0x000000FF, 0x000000FF, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 0.6000000238418579f;
    s = 62.0f;
    s = 16.0f;
    s = 0.20000000298023224f;
    s = 3.0f;
    s = 940.0f;
    s = 650.0f;
    s = 36.0f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 9350.0f;
    s = 1800.0f;
    d = 210.0;
    s = 32.0f;
    s = 484.0f;
    s = 424.0f;
    s = 588.0f;
    s = 443.0f;
    s = 480.0f;
    s = 430.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.75;
    s = 1.8249999284744263f;
}
static const u32 fzgx_pool_table6[1] = {0x9999999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.0;
}
#pragma section code_type ".text"

typedef struct {
    f32 x, y, z;
} fn_1_103B0_LiveCamVec;

/* one keyframe endpoint: position/target pair plus fov and roll */
typedef struct {
    u32 unk_0;
    fn_1_103B0_LiveCamVec pos;
    fn_1_103B0_LiveCamVec target;
    f32 fov;
    s16 roll;
    s16 pad_22;
} LiveCamFrame;

/* lbl_1_bss_17C4.unk_0 element, 0x54 bytes */
typedef struct {
    u32 duration;
    f32 rate;
    LiveCamFrame from;
    LiveCamFrame to;
    s16 mode;
    s16 pad_52;
} LiveCamKey;

typedef struct {
    u8 unk_0;
    u8 pad_1[0x3];
    s16 unk_4;
    u8 pad_6[0xE];
    s16 unk_14;
    u8 pad_16[0x6];
    fn_1_103B0_LiveCamVec pos;
    u8 pad_28[0x24];
    fn_1_103B0_LiveCamVec target;
    f32 fov;
    s16 roll;
    u8 pad_5E[0x6];
    u16 unk_64;
} LiveCamState;


void fn_1_103B0(LiveCamState *cam) {
    LiveCamKey *key;
    s32 count;
    s32 last;
    u32 raw;
    LiveCamFrame from;
    LiveCamFrame to;
    f32 t;

    raw = lbl_1_data_44F4.unk_0;
    key = &((LiveCamKey *)lbl_1_bss_17C4.unk_0)[cam->unk_4];
    if (cam->unk_0 == 3) {
        count = (s16)raw;
        if (fn_1_40BB4() == 0) {
            if ((lbl_1_bss_9F8.unk_A >> 1) & 1) {
                cam->unk_14++;
            }
            if (lbl_1_bss_9F8.unk_A & 1) {
                cam->unk_14--;
            }
            last = count - 1;
            if (cam->unk_14 > last) {
                cam->unk_14 = 0;
            }
            if (cam->unk_14 < 0) {
                cam->unk_14 = last;
            }
        }
    }
    if (cam->unk_64 != 0) {
        from = key->from;
        to = key->to;
        switch (key->mode) {
        case 0:
            t = 1.0 - (f32)cam->unk_64 / (f32)fn_80008E30(key->duration);
            lbl_8006D5A4(&from.pos, &to.pos, &cam->pos, t);
            lbl_8006D5A4(&from.target, &to.target, &cam->target, t);
            cam->fov = from.fov + (f32)(t * (to.fov - from.fov));
            cam->roll = from.roll + (s16)(s32)(t * (f32)(to.roll - from.roll));
            break;
        case 3:
            lbl_1_bss_17D0.unk_8 -= 1.0f;
            if (lbl_1_bss_17D0.unk_8 < lbl_1_bss_17D0.unk_C / 2.0f) {
                lbl_1_bss_17D0.unk_10 -= lbl_1_bss_17D0.unk_14;
            } else {
                lbl_1_bss_17D0.unk_10 += lbl_1_bss_17D0.unk_14;
            }
            t = (lbl_1_bss_17D0.unk_0 += lbl_1_bss_17D0.unk_10);
            lbl_8006D5A4(&from.pos, &to.pos, &cam->pos, t);
            lbl_8006D5A4(&from.target, &to.target, &cam->target, t);
            cam->fov = from.fov + (f32)(t * (to.fov - from.fov));
            cam->roll = from.roll + (s16)(s32)(t * (f32)(to.roll - from.roll));
            break;
        case 2:
            lbl_8006D5A4(&cam->pos, &to.pos, &cam->pos, key->rate);
            lbl_8006D5A4(&cam->target, &to.target, &cam->target, key->rate);
            cam->fov = cam->fov + (f32)(key->rate * (to.fov - cam->fov));
            cam->roll = cam->roll + (s32)(key->rate * (f32)(to.roll - cam->roll));
            break;
        }
    }
}
/* fzgx:end fn_1_103B0 */

/* fzgx:begin fn_1_11544 */
typedef struct {
    u8 unk_0;
    u8 pad_1[0x3];
    s16 unk_4;
    s16 unk_6;
    u8 pad_8[0xC];
    s16 unk_14;
    u8 pad_16[0x6];
    u8 unk_1C[0x30];
    fn_1_11544_LiveCamVec pos;        /* 0x4C */
    u8 pad_58[0x18];
    fn_1_11544_LiveCamVec target;     /* 0x70 */
} fn_1_11544_LiveCamera;

typedef struct {
    u8 pad_0[0xA];
    u16 unk_A;
} LiveCamInput;

typedef struct {
    u8 pad_0[0x10];
} LiveCamEntry;



/* Translation column of the current matrix in the locked cache. Like psvec_set, the
   components are passed z, y, x: the arguments are all loaded before the stores and
   MWCC numbers the first parameter highest, which is the register order retail has. */
static inline void LiveCam_SetCurMtxTrans(const volatile fn_1_11544_LiveCamVec *v) { /* volatile: pins the three loads in source order ahead of the stores, retail's register order (x f2, y f1, z f0) */
    f32 x = v->x;
    f32 y = v->y;
    f32 z = v->z;
    *(f32 *)(0xE0000000 + 0x0C) = x;
    *(f32 *)(0xE0000000 + 0x1C) = y;
    *(f32 *)(0xE0000000 + 0x2C) = z;
}

void fn_1_11544(fn_1_11544_LiveCamera *cam) {
    LiveCamMtx mtx;
    fn_1_11544_LiveCamVec eye;
    fn_1_11544_LiveCamVec at;
    fn_1_11544_LiveCamVec pos;
    fn_1_11544_LiveCamVec out;
    u32 handle;
    u32 info;
    f32 rate;
    f32 cx, cy, cz;

    if (cam->unk_0 == 3 && fn_1_40BB4() == 0) {
        if (((*((LiveCamInput *)&lbl_1_bss_9F8)).unk_A >> 1) & 1) {
            cam->unk_14++;
        }
        if ((*((LiveCamInput *)&lbl_1_bss_9F8)).unk_A & 1) {
            cam->unk_14--;
        }
        if (cam->unk_14 > 5) {
            cam->unk_14 = 0;
        }
        if (cam->unk_14 < 0) {
            cam->unk_14 = 5;
        }
    }

    fn_1_862D4( (s32)(cam->unk_6), (Vec3 *)(fn_1_11544_LiveCamVec *)(&eye));
    fn_1_8636C(cam->unk_6, (void *)(LiveCamMtx *)(&mtx));
    fn_1_862A8( (s32)(cam->unk_6), (void *)(fn_1_11544_LiveCamVec *)(&at));
    lbl_8006DC6C( (void *)(LiveCamMtx *)(&mtx));

    LiveCam_SetCurMtxTrans(&eye);

    lbl_8006E1B0((u8 *)&(*((LiveCamEntry *)&lbl_1_data_4754)) + (cam->unk_4 << 4), cam->unk_1C);

    cam->pos = eye;

    rate = (f32)(*((s16 *)&lbl_1_data_4484));
    cx = cam->target.x;
    cam->target.x = cx + (f32)(rate * (0.05f * (at.x - cx)));
    cy = cam->target.y;
    cam->target.y = cy + (f32)(rate * (0.05f * (at.y - cy)));
    cz = cam->target.z;
    cam->target.z = cz + (f32)(rate * (0.05f * (at.z - cz)));

    lbl_8006DAEC();
    handle = fn_1_20A5C(cam->unk_1C, &info);
    pos = cam->pos;
    fn_1_15578(cam->unk_1C, &pos, &info, &out, 0x40005, &handle, 1, 0, 0, 0);
    lbl_8006DB30();
}
/* fzgx:end fn_1_11544 */

/* fzgx:begin fn_1_11ABC */
typedef struct {
    Vec3 v;              /* 0x00 */
    u8 pad_C[0x14];
} CameraData;            /* 32 bytes */

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 pad_2[2];
    s16 unk_4;
    s16 unk_6;
    u8 pad_8[0xC];
    s16 unk_14;
    u8 pad_16[6];
    f32 unk_1C;
    u8 pad_20[0x14];
    Vec3 unk_34;
    u8 pad_40[0xC];
    Vec3 unk_4C;
    f32 unk_58;
    s16 unk_5C;
    u8 pad_5E[0x12];
    f32 unk_70;
    u8 pad_74[8];
    f32 unk_7C;
} fn_1_11ABC_LiveCamera;


#pragma opt_propagation off
void fn_1_11ABC(fn_1_11ABC_LiveCamera *camera) {
    Vec3 first;
    Vec3 second;
    u8 mode = camera->unk_0;

    if (mode == 5 || mode <= 1 || mode == 2) {
        u32 value;
        u32 next = lbl_801A63C0 * 0x676A4B6Bu + 0x33CB;
        s16 result;

        value = (next << 1) >> 17;
        result = (s16)(value % 9);
        lbl_801A63C0 = next;
        camera->unk_14 = result;
        camera->unk_4 = result;
    }

    fn_1_862D4(camera->unk_6, &first);
    fn_1_8636C(camera->unk_6, &camera->unk_7C);
    fn_1_862A8(camera->unk_6, &camera->unk_70);

    camera->unk_34 = (*(CameraData (*)[])&lbl_1_data_4AA0)[camera->unk_4].v;

    {
        f32 m2, m1, m0;
        f32 *mtx = (f32 *)(LC_BASE + 0x0);
        m0 = first.x;
        m1 = first.y;
        m2 = first.z;
        mtx[3] = m0;
        mtx[7] = m1;
        mtx[11] = m2;
    }

    lbl_8006DC6C(&camera->unk_7C);
    lbl_8006E1B0(&camera->unk_34, &camera->unk_1C);
    fn_8006E2B0(&camera->unk_70, &second);

    camera->unk_4C = first;
    camera->unk_5C = (s16)-lbl_8006D24C(second.x, second.y);
    camera->unk_58 = 55.0f;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_11ABC */

/* fzgx:begin fn_1_12620 */
// Prints the live-camera status text for the current camera event.
#pragma opt_common_subs off
void fn_1_12620(s32 arg0) {
    u8 *base = (u8 *)&lbl_1_data_43B8;
    char buf[0x74];

    fn_80006E10((u32)(base + 0x280));
    if (*(s16 *)&lbl_1_bss_960 == 0xA) {
        sprintf(buf, (const char *)(base + 0x284), arg0);
        if (fn_1_465D0((s32)buf, 1) == -1) {
            sprintf(buf, (const char *)(base + 0x2A0));
            fn_1_465D0((s32)buf, 1);
        }
    } else if (*(s16 *)&lbl_1_bss_960 == 0xE) {
        if (lbl_1_bss_525C.unk_191 & 2) {
            switch (lbl_1_bss_525C.unk_192) {
            case 4:
                sprintf(buf, (const char *)(base + 0x2BC));
                break;
            case 3:
                sprintf(buf, (const char *)(base + 0x2D4));
                break;
            case 2:
                sprintf(buf, (const char *)(base + 0x2EC));
                break;
            default:
                sprintf(buf, (const char *)(base + 0x2EC));
                break;
            }
        } else {
            sprintf(buf, (const char *)(base + 0x304));
        }
        fn_1_465D0((s32)buf, 1);
    } else {
        sprintf(buf, (const char *)(base + 0x324), arg0);
        if (fn_1_465D0((s32)buf, 1) == -1) {
            sprintf(buf, (const char *)(base + 0x33C));
            fn_1_465D0((s32)buf, 1);
        }
    }
    if (arg0 == 0x32) {
        fn_80006E10((u32)(base + 0x350));
        return;
    }
    sprintf(buf, (const char *)(base + 0x354), arg0);
    if (fn_1_465D0((s32)buf, 1) == -1) {
        sprintf(buf, (const char *)(base + 0x364));
        fn_1_465D0((s32)buf, 1);
    }
    sprintf(buf, (const char *)(base + 0x374), arg0);
    if (fn_1_465D0((s32)buf, 1) == -1) {
        sprintf(buf, (const char *)(base + 0x388));
        fn_1_465D0((s32)buf, 1);
    }
    fn_80006E10((u32)(base + 0x350));
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_12620 */

/* fzgx:begin fn_1_12850 */
u8 fn_1_12850(void) {
    return lbl_1_bss_17B4[0];
}
/* fzgx:end fn_1_12850 */

/* fzgx:begin fn_1_12860 */
// Initializes the live-camera state before returning the active camera result.
u32 fn_1_12860(u32 arg0, u32 arg1) {
    u32 *state = (u32 *)lbl_1_bss_1800;

    state[0] = arg0;
    state[1] = arg1;
    state[2] = 0;
    return fn_1_1289C(state)[0];
}
/* fzgx:end fn_1_12860 */

/* fzgx:begin fn_1_12F78 */
u32 fn_1_12F78(void *arg0, u32 arg1) {
    fn_80083DB0( (char *)(Obj_1_bss_3B30 *)(&lbl_1_bss_3B30), (const char *)(void *)(arg0));
    lbl_1_bss_3B30.unk_80 = arg1;
    lbl_1_bss_3B30.unk_84 = 0;
    return *fn_1_1304C(&lbl_1_bss_3B30, 0);
}
/* fzgx:end fn_1_12F78 */

/* fzgx:begin fn_1_13018 */
s32 fn_1_13018(void) {
    fn_8000659C();
    return OSIsThreadTerminated(lbl_1_bss_1810) == 0;
}
/* fzgx:end fn_1_13018 */

/* fzgx:begin fn_1_1350C */
#include "types.h"
#include "rel/main_rel/live_camera.h"

/* volatile: retail reloads these globals at every access (matches codegen) */
#define V(x) (*(volatile u32 *)&(x))

u8 fn_1_1350C(void *a, u8 *buf) {
    s32 n;
    if (V(lbl_1_bss_3B28) == 0) {
        n = V(lbl_1_data_5180);
        if (V(lbl_1_bss_3B2C) + V(lbl_1_data_5180) > (u32)fn_1_45B2C(a)) {
            n = ((u32)fn_1_45B2C(a) - V(lbl_1_bss_3B2C) + 0x1f) & ~0x1f;
        }
        if (n > 0) {
            fn_1_458A0(a, buf, n, V(lbl_1_bss_3B2C));
        }
        V(lbl_1_bss_3B2C) = V(lbl_1_bss_3B2C) + V(lbl_1_data_5180);
    }
    {
        u8 r = buf[V(lbl_1_bss_3B28)];
        V(lbl_1_bss_3B28) = V(lbl_1_bss_3B28) + 1;
        if (V(lbl_1_bss_3B28) >= V(lbl_1_data_5180)) {
            V(lbl_1_bss_3B28) = 0;
        }
        return r;
    }
}
/* fzgx:end fn_1_1350C */
