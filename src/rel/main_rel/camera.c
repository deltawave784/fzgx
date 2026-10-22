#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"
#include "game/main_rel/camera_types.h"

extern u8 lbl_1_bss_6F244[128];
extern u8 lbl_1_bss_6EAC6[10];
extern s8 fn_1_86624();
extern s32 fn_1_3F864(void);
extern int fn_1_4C10(void);
extern s16 fn_1_3F0C8(void);
extern void fn_1_739C(void *, u32, u32);
extern u8 fn_1_86634(int index);
extern void *fn_1_86254(int index);
extern u32 fn_1_F2F34(void);
extern s16 camera_get_entry_field_0xa4(u32);
extern u8 fn_1_86678(int index);
extern void fn_1_715C(u8, s16);
extern u32 fn_1_864E8(int index);
extern u8 fn_1_40BB4(void);
extern u8 lbl_1_bss_CC0[152];
extern u32 fn_1_CC5C(void);
extern void fn_1_55FC4(f32 value);
extern void fn_1_55FF0(f32 value);
extern u32 fn_1_55210(u32);
extern void lbl_8006E14C(f32);
extern void fn_80072558(void);
extern u32 lbl_801A6CE0;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern u8 lbl_1_bss_F74;
extern u8 lbl_1_bss_F75;
extern u32 lbl_1_bss_7ADE8[40];
extern void *lbl_1_data_3310;
extern f32 fn_1_A6FE8(void);
extern void fn_1_DCE60(void *);
extern u32 fn_1_435C(u32 value);
extern s32 fn_1_3F8C(u32 arg3, u32 arg0, u32 arg1, u32 index);
extern void fn_1_DCED0(void);
extern const f32 lbl_1_rodata_194;
extern const f32 lbl_1_rodata_188;
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern void *fn_1_868C0(s8 index);
extern s32 fn_1_A5DC4(void);
extern const f32 lbl_1_rodata_200;
extern const f32 lbl_1_rodata_204;
extern f64 lbl_1_rodata_360;
extern s16 camera_get_entry_field_0xa8(u32 index);
extern void camera_set_entry_field_0xa8(u8 index, s16 value);
extern u16 fn_1_8664C(int index);
extern void OSReport(const char *format, ...);
extern f64 lbl_1_rodata_4A8[7];
extern u8 lbl_1_bss_108C[52];
extern void fn_1_BD54(void);
extern void fn_1_B870(void);
extern u8* camera_get_extended_state_storage();
extern void lbl_8006DBAC(void);
extern void lbl_8006DCDC(void);
extern s16 fn_1_6B48(s32 index);
extern void fn_1_6D2C(u32);
extern s32 lbl_1_bss_F78;
extern void fn_1_A2DF4(s32 arg0, void *arg1, s32 arg2);
extern s32 fn_1_8708(s32 mode, f32 *value0, f32 *value1);
extern void fn_1_8A0C(s16 index);
extern void fn_1_8D08(GameCameraEntry *value);
extern f32 lbl_1_bss_1040;
extern f32 lbl_1_bss_1044;
extern u8 lbl_1_bss_103C[4];
extern u8 lbl_1_bss_1014;
extern f32 lbl_1_rodata_2E0[32];
extern f32 lbl_8006D6FC(f32 *value, void *target);
extern s32 fn_1_6514(s32 value);
extern f64 lbl_1_rodata_478;
extern f32 lbl_1_rodata_49C;
extern f32 lbl_1_bss_10C0[6];
extern CameraState* camera_get_state_object(void);

/* fzgx:begin fn_1_5370 noprologue */
#include "types.h"
#include "rel/main_rel/camera.h"

extern u32 fn_1_434C(void);
extern u8 fn_1_86624(void);
extern u32 fn_1_435C(u32);
extern void fn_1_426C(u32);
extern void fn_1_8298(s8);
extern void fn_1_847C(s8);
extern void fn_1_857C(s8);
extern void fn_1_90E0(void);
extern void fn_1_EE44(void);
extern f32 fn_1_A6FE8(void);
extern const f64 lbl_1_rodata_178;
extern const f64 lbl_1_rodata_180;
extern void fn_1_8D08(void *, f32);
extern u16 fn_1_3F8C(u8 *, void (*)(void), void *, u32);
extern void fn_1_EBE4(LiveCamera *, s16, s32, f32);

s8 fn_1_5370(s8 arg0, s16 arg1) {
    Obj_1_bss_F68_Target **base = &lbl_1_bss_F68;
    u32 i;
    s8 old;
    u32 count = 0;
    u32 extra = 0;
    u32 saved;
    u8 *obj;
    s16 id;
    u32 j;
    f32 value;
    if (*base == 0) return -1;
    saved = fn_1_434C();
    fn_1_86624();
    old = (s8)(*base)->unk_4D;
    (*base)->unk_4D = arg0;
    fn_1_435C((*base)->unk_50);
    {
        Obj_1_bss_F68_Target *state;
        for (j = 0; j < (u32)(state = *base)->unk_22; j++)
            fn_1_426C(*(s16 *)((u8 *)state + 4 + j * 2));
        state->unk_22 = 0;
    }
    fn_1_435C((*base)->unk_54);
    {
        Obj_1_bss_F68_Target *state;
        for (j = 0; j < (u32)(state = *base)->unk_44; j++)
            fn_1_426C(*(s16 *)((u8 *)state + 0x26 + j * 2));
        state->unk_44 = 0;
    }
    switch (arg0) {
    case 0: fn_1_8298(arg0); break;
    case 1: case 2: case 4: fn_1_847C(arg0); break;
    case 3: fn_1_857C(arg0); break;
    }
    {
    Obj_1_bss_F68_Target *state = *base;
    switch ((s8)state->unk_48) {
    case 0: count = 1; break;
    case 1: case 2: count = 2; break;
    case 3: case 4: case 5: case 7: count = 3; break;
    case 6: count = 3; extra = 1; break;
    case 8: count = 4; break;
    case 9: extra = 1; break;
    case 10: count = 1; extra = 1; break;
    case 11: count = 0; extra = 0; break;
    }
    state->unk_49 = count + extra;
    }
    obj = *(u8 **)((u8 *)base + 4);
#pragma opt_common_subs off
    for (i = 0; i < count; i++) {
        u8 mode;

        value = fn_1_A6FE8();
        mode = (*base)->unk_48;
        if ((s8)mode == 1 ||
            (i == 0 && (s8)mode == 3) ||
            (i == 1 && (s8)mode == 4) ||
            (i == 2 && (s8)mode == 5))
            value *= lbl_1_rodata_178;
        if ((s8)mode == 2) value *= lbl_1_rodata_180;
        if ((s8)mode == 0) *(s16 *)(obj + 2) = arg1;
        fn_1_8D08(obj, value);
        fn_1_435C((*base)->unk_50);
        id = fn_1_3F8C(lbl_1_data_33CC, fn_1_90E0, obj, 0x14);
        obj += 0x1FC;
        {
            Obj_1_bss_F68_Target *state = *base;
            j = state->unk_22;
            state->unk_22 = j + 1;
            *(s16 *)((u8 *)state + 4 + j * 2) = id;
        }
    }
    if (extra != 0) {
        value = fn_1_A6FE8();
        if (arg0 == 4)
            fn_1_EBE4(*(LiveCamera **)((u8 *)base + 8), -1, 1, value);
        else
            fn_1_EBE4(*(LiveCamera **)((u8 *)base + 8), arg1, 0, value);
        fn_1_435C((*base)->unk_50);
        id = fn_1_3F8C(lbl_1_data_33DC, fn_1_EE44, *(void **)((u8 *)base + 8), 0x14);
        {
            s16 index;
            Obj_1_bss_F68_Target *state = *base;
            index = state->unk_22;
            state->unk_22 = index + 1;
            ((s16 *)&state->unk_4)[index] = id;
        }
    }
    fn_1_435C(saved);
    return old;
}
/* fzgx:end fn_1_5370 */

/* fzgx:begin fn_1_6400 */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
} F68State;

// Report and clear the three pending camera state values.
void fn_1_6400(void) {
    F68State *state;

    state = (F68State *)&lbl_1_bss_F68;
    fn_1_46B4(lbl_801A6410.unk_0, state->unk_8, (const char *)(void *)((*(u8 (*)[180])&lbl_1_data_3318)), 0x396);
    fn_1_46B4(lbl_801A6410.unk_0, state->unk_4, (const char *)(void *)((*(u8 (*)[180])&lbl_1_data_3318)), 0x397);
    fn_1_46B4(lbl_801A6410.unk_0, state->unk_0, (const char *)(void *)((*(u8 (*)[180])&lbl_1_data_3318)), 0x398);
    state->unk_8 = 0;
    state->unk_4 = 0;
    state->unk_0 = 0;
}
/* fzgx:end fn_1_6400 */

/* fzgx:begin camera_get_state */
// Return the camera state byte, or -1 when no camera state is active.
s32 camera_get_state(void) {
    Obj_1_bss_F68_Target *camera = lbl_1_bss_F68;

    if (camera == 0) {
        return -1;
    }

    return camera->unk_48;
}
/* fzgx:end camera_get_state */

/* fzgx:begin camera_get_status */
// Return the camera status when a camera exists and is not marked inactive.
u32 camera_get_status(void) {
    Obj_1_bss_F68_Target *camera = lbl_1_bss_F68;
    u32 status;

    if (camera == 0) {
        status = 0;
    } else if ((camera->unk_0 & ((u32)1 << 31)) != 0) {
        status = 0;
    } else {
        status = camera->unk_4A;
    }

    return fn_1_6514(status);
}
/* fzgx:end camera_get_status */

/* fzgx:begin fn_1_6514 */
s32 fn_1_6514(s32 value) {
    Obj_1_bss_F68_Target *camera = lbl_1_bss_F68;
    s8 mode;

    if (camera == 0) {
        return -1;
    }
    if ((camera->unk_0 & ((u32)1 << 31)) != 0) {
        return 0;
    }

    mode = (s8)camera->unk_48;
    switch (mode) {
    case 9:
        return 2;
    case 10:
        return (value == 0) + 1;
    case 6:
        return (value == 3) + 1;
    }

    switch (game_camera_entries[value].unk_A8) {
    case 0:
        return 1;
    case 1:
    case 2:
        return 3;
    case 3:
        return 4;
    case 4:
        return 5;
    case 5:
        return 6;
    default:
        return -1;
    }
}
/* fzgx:end fn_1_6514 */

/* fzgx:begin camera_get_flags */
u32 camera_get_flags(void) {
    // Reports the active camera object's top-bit flag, or zero when no object is active.
    if (lbl_1_bss_F68 != 0) {
        return lbl_1_bss_F68->unk_0 & (1u << 31);
    }

    return 0;
}
/* fzgx:end camera_get_flags */

/* fzgx:begin camera_update */
extern CameraState *camera_get_state_object(void);
extern void fn_1_BD54(void);
extern void fn_1_B870(void);

// Dispatches the camera update according to the camera state flag.
void camera_update(void) {
    CameraState *state = camera_get_state_object();

    if (((state->unk_0 >> 30) & 1) != 0) {
        fn_1_BD54();
    } else {
        fn_1_B870();
    }
}
/* fzgx:end camera_update */

/* fzgx:begin camera_update_state */
// Updates the camera state through the active or standard camera path.
void camera_update_state(__typeof__(lbl_1_bss_F68) state) {
    if ((state->unk_0 >> 30) & 1) {
        camera_get_extended_state_storage(state);
        lbl_8006DBAC();
    } else {
        fn_8006F038( (Vec3 *)(void *)(&state->unk_4), (Vec3 *)(void *)(&state->unk_4 + 6),
                     *((s16 *)&state->unk_4 + 14));
    }

    lbl_8006DCDC();
}
/* fzgx:end camera_update_state */

/* fzgx:begin fn_1_681C */
struct fn_1_681C_Copy12 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};

struct fn_1_681C_Entry {
    u8 pad_0[0x10];
    struct fn_1_681C_Copy12 unk_10;
    u8 pad_1C[0x1FC - 0x1C];
};

struct fn_1_681C_Other {
    u8 pad_0[0x1C];
    struct fn_1_681C_Copy12 unk_1C;
};

struct fn_1_681C_Globals {
    u32 state;
    struct fn_1_681C_Entry *entries;
    struct fn_1_681C_Other *other;
};



#pragma peephole off
void fn_1_681C(u32 index, u32 *output) {
    struct fn_1_681C_Globals *globals = &(*(struct fn_1_681C_Globals *)&lbl_1_bss_F68);
    u32 state = globals->state;
    s8 mode;

    if (state == 0) {
        return;
    }

    mode = *(s8 *)((u8 *)state + 0x48);

    switch (mode) {
    case 9:
    case 10:
        *(struct fn_1_681C_Copy12 *)output = globals->other->unk_1C;
        return;
    default:
        *(struct fn_1_681C_Copy12 *)output = globals->entries[index & 0xff].unk_10;
        return;
    }
}
#pragma peephole reset
/* fzgx:end fn_1_681C */

/* fzgx:begin fn_1_6898 */
struct fn_1_6898_Copy12 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};

struct fn_1_6898_Entry {
    u8 pad_0[0x1C];
    struct fn_1_6898_Copy12 unk_1C;
    u8 pad_28[0x1FC - 0x28];
};

struct fn_1_6898_Other {
    u8 pad_0[0x28];
    struct fn_1_6898_Copy12 unk_28;
};

struct fn_1_6898_Globals {
    u32 state;
    struct fn_1_6898_Entry *entries;
    struct fn_1_6898_Other *other;
};



#pragma peephole off
void fn_1_6898(u32 index, u32 *output) {
    struct fn_1_6898_Globals *globals = &(*(struct fn_1_6898_Globals *)&lbl_1_bss_F68);
    u32 state = globals->state;
    s8 mode;

    if (state == 0) {
        return;
    }

    mode = *(s8 *)((u8 *)state + 0x48);

    switch (mode) {
    case 9:
    case 10:
        *(struct fn_1_6898_Copy12 *)output = globals->other->unk_28;
        return;
    default:
        *(struct fn_1_6898_Copy12 *)output = globals->entries[index & 0xff].unk_1C;
        return;
    }
}
#pragma peephole reset
/* fzgx:end fn_1_6898 */

/* fzgx:begin fn_1_6914 */
struct fn_1_6914_Copy12 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};

struct fn_1_6914_Entry {
    u8 pad_0[0x28];
    struct fn_1_6914_Copy12 unk_28;
    u8 pad_34[0x1FC - 0x34];
};

struct fn_1_6914_Other {
    u8 pad_0[0x4C];
    struct fn_1_6914_Copy12 unk_4C;
};

struct fn_1_6914_Globals {
    u32 state;
    struct fn_1_6914_Entry *entries;
    struct fn_1_6914_Other *other;
};



#pragma peephole off
void fn_1_6914(u32 index, u32 *output) {
    struct fn_1_6914_Globals *globals = &(*(struct fn_1_6914_Globals *)&lbl_1_bss_F68);
    u32 state = globals->state;
    s8 mode;

    if (state == 0) {
        return;
    }

    mode = *(s8 *)((u8 *)state + 0x48);

    switch (mode) {
    case 9:
    case 10:
        *(struct fn_1_6914_Copy12 *)output = globals->other->unk_4C;
        return;
    default:
        *(struct fn_1_6914_Copy12 *)output = globals->entries[index & 0xff].unk_28;
        return;
    }
}
#pragma peephole reset
/* fzgx:end fn_1_6914 */

/* fzgx:begin fn_1_6990 */
struct fn_1_6990_Copy12 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};

struct fn_1_6990_Entry {
    u8 pad_0[0x64];
    struct fn_1_6990_Copy12 unk_64;
    u8 pad_70[0x1FC - 0x70];
};

struct fn_1_6990_Other {
    u8 pad_0[0x70];
    struct fn_1_6990_Copy12 unk_70;
};

struct fn_1_6990_Globals {
    u32 state;
    struct fn_1_6990_Entry *entries;
    struct fn_1_6990_Other *other;
};



#pragma peephole off
void fn_1_6990(u32 index, u32 *output) {
    struct fn_1_6990_Globals *globals = &(*(struct fn_1_6990_Globals *)&lbl_1_bss_F68);
    u32 state = globals->state;
    s8 mode;

    if (state == 0) {
        return;
    }

    mode = *(s8 *)((u8 *)state + 0x48);

    switch (mode) {
    case 9:
    case 10:
        *(struct fn_1_6990_Copy12 *)output = globals->other->unk_70;
        return;
    default:
        *(struct fn_1_6990_Copy12 *)output = globals->entries[index & 0xff].unk_64;
        return;
    }
}
#pragma peephole reset
/* fzgx:end fn_1_6990 */

/* fzgx:begin fn_1_6A0C pool */
extern void lbl_8006DD14(void *, u32);

#pragma force_active on
Obj_1_bss_F68_Target *lbl_1_bss_F68;
u8 *lbl_1_bss_F6C;
u8 *lbl_1_bss_F70;

/* Prime the native BSS pool in retail address order. */
#pragma section code_type ".fzgxpool"
static void *fzgx_fn_1_6A0C_bss_order(u32 index) {
    if (index == 0) {
        return lbl_1_bss_F68;
    }
    if (index == 1) {
        return lbl_1_bss_F6C;
    }
    return lbl_1_bss_F70;
}
#pragma section code_type ".text"
#pragma force_active reset

#pragma peephole on
#pragma opt_strength_reduction off
void fn_1_6A0C(u32 index, u32 arg) {
    u8 * fzgx_live;
    Obj_1_bss_F68_Target *state = lbl_1_bss_F68;

    if (state == 0) {
        return;
    }

    switch ((s8)state->unk_48) {
    case 9:
    case 10:
        lbl_8006DD14(lbl_1_bss_F70 + 0x7c, arg);
        return;
    default:
        fzgx_live = lbl_1_bss_F6C;
        lbl_8006DD14(((0x34) + (((index & 0xff) * 0x1fc) + (fzgx_live))), arg);
        return;
    }
}
#pragma opt_strength_reduction reset
/* fzgx:end fn_1_6A0C */

/* fzgx:begin camera_get_mode */
// Return the normalized camera status, treating inactive states as zero.
s16 camera_get_mode(void) {
    Obj_1_bss_F68_Target *state = lbl_1_bss_F68;
    s32 index;
    s16 value;

    if (state == 0) {
        index = 0;
    } else if ((state->unk_0 & ((s32)1 << 31)) != 0) {
        index = 0;
    } else {
        index = state->unk_4A;
    }

    value = fn_1_6B48(index);
    if (value == 0xff) {
        value = -1;
    }

    return value;
}
/* fzgx:end camera_get_mode */

/* fzgx:begin camera_get_output */
s16 camera_get_output(void) {
    Obj_1_bss_F68_Target *state = lbl_1_bss_F68;
    u32 result;

    // Return the camera output only when the state is active and ready.
    if ((s8)state->unk_48 == 6) {
        if (state == 0) {
            result = 0;
        } else if ((state->unk_0 & ((s32)1 << 31)) != 0) {
            result = 0;
        } else {
            result = state->unk_4A;
        }

        if (result == 3) {
            return live_camera->unk_6;
        }
    }

    return -1;
}
/* fzgx:end camera_get_output */

/* fzgx:begin fn_1_6B48 */
/* The three camera pointers are one cluster of this TU's .bss; retail
 * addresses them off a single base register. MWCC lays .bss out in
 * first-access order, so the primer below (a section mwld ignores) fixes
 * retail's order: lbl_1_bss_F68, game_camera_entries, live_camera. */
Obj_1_bss_F68_Target *lbl_1_bss_F68;
__typeof__(game_camera_entries) game_camera_entries;
__typeof__(live_camera) live_camera;

#pragma section ".fzgxpool"
__declspec(section ".fzgxpool") void fn_1_6B48_bss_primer(void *out[3]) {
    out[0] = lbl_1_bss_F68;
    out[1] = game_camera_entries;
    out[2] = live_camera;
}

s16 fn_1_6B48(s32 index) {
    Obj_1_bss_F68_Target *state = lbl_1_bss_F68;

    if (state == 0) {
        return -1;
    }
    if ((state->unk_0 & ((s32)1 << 31)) != 0) {
        return -1;
    }
    switch ((s8)state->unk_48) {
    case 9:
    case 10:
        return live_camera->unk_6;
    case 11:
        return -1;
    default:
        return game_camera_entries[index].unk_2;
    }
}
/* fzgx:end fn_1_6B48 */

/* fzgx:begin fn_1_6BC0 */
// lbl_1_bss_9F8.unk_8 read as a 16-bit button word; bits 0/1 select previous/next camera
typedef struct {
    u8 pad_0[0x8];
    u16 buttons : 16;
} CameraSelectInput;

#define CAMERA_SELECT_INPUT ((CameraSelectInput *)&lbl_1_bss_9F8)

#pragma opt_common_subs off
void fn_1_6BC0(void) {
    s32 cur;
    s16 next;

    if (lbl_1_bss_F68 == NULL) {
        return;
    }
    if (*(s8 *)&lbl_1_bss_F68->unk_48 != 0) {
        return;
    }

    cur = game_camera_entries->unk_2;
    next = cur;
    if ((CAMERA_SELECT_INPUT->buttons >> 1) & 1) {
        next++;
        if (next == (s8)fn_1_86624()) {
            next = 0;
        }
    } else if (CAMERA_SELECT_INPUT->buttons & 1) {
        next--;
        if (next < 0) {
            next = (s8)fn_1_86624() - 1;
        }
    }

    if (next != cur) {
        game_camera_entries->unk_2 = next;
        *(s8 *)((u8 *)fn_1_86254(cur) + 0x475) = -1;
        *(s8 *)((u8 *)fn_1_86254(next) + 0x475) = 0;
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_6BC0 */

/* fzgx:begin camera_set_result */
void camera_set_result(s16 value) {
    // Update the camera result only while the camera state is active.
    if (lbl_1_bss_F68 != 0) {
        game_camera_entries->unk_2 = value;
    }
}
/* fzgx:end camera_set_result */

/* fzgx:begin camera_forward_status */
// Forward the camera state's status to the next update stage.
void camera_forward_status(void) {
    Obj_1_bss_F68_Target *state = lbl_1_bss_F68;
    u32 value;

    if (state == 0) {
        value = 0;
    } else if ((state->unk_0 & ((u32)1 << 31)) != 0) {
        value = 0;
    } else {
        value = state->unk_4A;
    }

    fn_1_6D2C(value);
}
/* fzgx:end camera_forward_status */

/* fzgx:begin fn_1_6D2C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"

extern void OSPanic(u8 *file, int line, u8 *message, ...);

typedef struct {
    u32 unk_0;
    u8 unk_4;
    u8 pad_5[0x1F7];
} F6D2CEntry;

typedef struct {
    u32 unk_0;
    u8 pad[8];
    u32 unk_C;
} F6D2COther;

typedef struct {
    Obj_1_bss_F68_Target *state;
    F6D2CEntry *entries;
    F6D2COther *other;
} F6D2CBss;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
Obj_1_bss_F68_Target *fzgx_obj_lbl_1_bss_F68;
F6D2CEntry *fzgx_obj_game_camera_entries;
F6D2COther *fzgx_obj_live_camera;
u8 lbl_1_bss_F74;
u8 lbl_1_bss_F75;
u8 lbl_1_bss_F76;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_F68;
    s = *(u8 *)&fzgx_obj_game_camera_entries;
    s = *(u8 *)&fzgx_obj_live_camera;
    s = *(u8 *)&lbl_1_bss_F74;
    s = *(u8 *)&lbl_1_bss_F75;
    s = *(u8 *)&lbl_1_bss_F76;
}
#pragma section code_type ".text"

u32 fn_1_6D2C(u32 index) {
    
    Obj_1_bss_F68_Target *state = fzgx_obj_lbl_1_bss_F68;
    s8 mode;

    if (state == 0) {
        OSPanic((u8 *)lbl_1_data_3318, 0x546, (u8 *)&lbl_1_data_35B0);
        return 0;
    }
    if ((fzgx_obj_lbl_1_bss_F68->unk_0 & ((u32)1 << 31)) != 0) {
        return *(u32 *)camera_get_state_object();
    }
    mode = (s8)fzgx_obj_lbl_1_bss_F68->unk_48;
    switch (mode) {
    case 9:
    case 10:
        return fzgx_obj_live_camera->unk_C;
    default:
        return fzgx_obj_game_camera_entries[index].unk_4;
    }
}
/* fzgx:end fn_1_6D2C */

/* fzgx:begin fn_1_6DD0 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"

extern void lbl_8006DD14(u32, void *);
extern void OSPanic(u8 *file, int line, u8 *message, ...);
extern u32 *lbl_801A6D00;
extern void *lbl_801A66CC;

typedef struct {
    u32 unk_0;
    u8 unk_4;
} F6DD0Entry;

typedef struct {
    u32 unk_0;
    u8 pad[8];
    u32 unk_C;
} F6DD0Other;

typedef struct {
    Obj_1_bss_F68_Target *state;
    u8 *entries;
    F6DD0Other *other;
} F6DD0Bss;

/* volatile: retail preserves the flag-byte read and write even with a zero mask. */
static inline void F6DD0SetFlag(volatile F6DD0Entry *e, u8 flag) {
    e->unk_4 = e->unk_4 | flag;
}

void fn_1_6DD0(u8 index) {
    F6DD0Bss *bss = (F6DD0Bss *)&lbl_1_bss_F68;
    s8 mode;

    lbl_8006DD14((u32)((u8 *)lbl_801A6D00 + 0x30), lbl_801A66CC);
    if (bss->state == 0) {
        OSPanic((u8 *)lbl_1_data_3318, 0x564, (u8 *)&lbl_1_data_35B0);
    }
    if ((bss->state->unk_0 & ((u32)1 << 31)) != 0) {
        *(u32 *)camera_get_state_object() |= ((u32)1 << 31);
    }
    mode = (s8)bss->state->unk_48;
    switch (mode) {
    case 9:
    case 10:
        bss->other->unk_C |= ((u32)1 << 31);
        break;
    default: {
        /* volatile: retail preserves this byte read/modify/write for a zero mask. */
        F6DD0SetFlag((volatile F6DD0Entry *)(bss->entries + index * 0x1FC), 0);
        break;
    }
    }
}
/* fzgx:end fn_1_6DD0 */

/* fzgx:begin fn_1_6EC0 */
u32 fn_1_6EC0(u8 index) {
    Obj_1_bss_F68_Target *state = lbl_1_bss_F68;

    if (state == 0) {
        return 0;
    }
    if ((state->unk_0 & ((u32)1 << 31)) != 0) {
        return 0;
    }

    switch ((s8)state->unk_48) {
    case 9:
    case 10:
        return 0;
    }

    return game_camera_entries[index].unk_A8 == 0;
}
/* fzgx:end fn_1_6EC0 */

/* fzgx:begin camera_is_mode_0x0b */
// Return whether the camera state is active and has the expected mode.
u32 camera_is_mode_0x0b(void) {
    Obj_1_bss_F68_Target *state = lbl_1_bss_F68;

    if (state == 0) {
        return 0;
    }
    if ((state->unk_0 & ((u32)1 << 31)) != 0) {
        return 0;
    }
    return (s8)state->unk_48 == 0x0B;
}
/* fzgx:end camera_is_mode_0x0b */

/* fzgx:begin fn_1_6F84 */
s32 fn_1_6F84(void) {
    Obj_1_bss_F68_Target *state = lbl_1_bss_F68;
    if (state == 0) {
        return 0;
    }
    if ((state->unk_0 & ((u32)1 << 31)) != 0) {
        return 0;
    }

    switch ((s8)state->unk_48) {
    case 9:
    case 10:
        if (live_camera->unk_2 == 4) {
            return 1;
        }
        return 0;
    }

    return 0;
}
/* fzgx:end fn_1_6F84 */

/* fzgx:begin fn_1_7000 */
s32 fn_1_7000(void) {
    Obj_1_bss_F68_Target *state = lbl_1_bss_F68;

    if (state == 0) {
        return 0;
    }
    if ((state->unk_0 & ((u32)1 << 31)) != 0) {
        return 0;
    }

    switch ((s8)state->unk_48) {
    case 9:
    case 10:
        if (live_camera->unk_2 == 5) {
            return 1;
        }
        return 0;
    }

    return 0;
}
/* fzgx:end fn_1_7000 */

/* fzgx:begin camera_set_entry_field_0xa8 */
void camera_set_entry_field_0xa8(u8 index, s16 value) {
    // Store the selected camera entry's parameter.
    game_camera_entries[index].unk_A8 = value;
}
/* fzgx:end camera_set_entry_field_0xa8 */

/* fzgx:begin fn_1_715C */
void fn_1_715C(u8 index, s16 value) {
    // Toggle the camera effect associated with this entry before storing its state.
    if (game_camera_entries[index].unk_A8 == 0 && index < 4) {
        if (value == 0) {
            if (lbl_1_bss_F78 == 0) {
                fn_1_A2DF4(index, (void *)(u32)(0xa5000000), 8);
                lbl_1_bss_F78 = 1;
            }
        } else if (game_camera_entries[index].unk_A4 == 0 &&
                   lbl_1_bss_F78 != 0) {
            fn_1_A2DF4(index, (void *)(u32)(0xa5000000),
                       (&lbl_1_bss_6F1E4.unk_8)[index * 10]);
            lbl_1_bss_F78 = 0;
        }
    }

    game_camera_entries[index].unk_A4 = value;
}
/* fzgx:end fn_1_715C */

/* fzgx:begin camera_get_entry_field_0xa8 */
s16 camera_get_entry_field_0xa8(u32 index) {
    // Return the selected camera entry's stored value.
    return game_camera_entries[(u8)index].unk_A8;
}
/* fzgx:end camera_get_entry_field_0xa8 */

/* fzgx:begin camera_get_entry_field_0xa4 */
s16 camera_get_entry_field_0xa4(u32 index) {
    // Return the selected camera entry's stored value.
    return game_camera_entries[(u8)index].unk_A4;
}
/* fzgx:end camera_get_entry_field_0xa4 */

/* fzgx:begin fn_1_727C */
typedef struct {
    u8 pad_0[0x48];
    s8 unk_48;
    u8 unk_49;
    u8 unk_4A;
} fn_1_727C_CameraObject;

typedef struct {
    u8 pad_0[0x10];
    u8 unk_10[0x1EC];
} fn_1_727C_CameraEntry;

typedef struct {
    u8 pad_0[0x1C];
    u8 unk_1C;
} fn_1_727C_CameraTable;

typedef struct {
    fn_1_727C_CameraObject *unk_0;
    fn_1_727C_CameraEntry *unk_4;
    fn_1_727C_CameraTable *unk_8;
} fn_1_727C_CameraState;

typedef struct {
    u32 unk_0;
    u8 pad_4[0xE];
} fn_1_727C_Obj_1_bss_6EAB4;



void fn_1_727C(void) {
    fn_1_727C_CameraState *state;
    u8 mode;
    u8 idx;

    state = (fn_1_727C_CameraState *)&(*((fn_1_727C_CameraState *)&lbl_1_bss_F68));
    mode = (s32)fn_1_86624();
    idx = state->unk_0->unk_4A;
    if (state->unk_0 == NULL) {
        return;
    }
    if (mode == 0) {
        return;
    }
    if ((*((fn_1_727C_Obj_1_bss_6EAB4 *)&lbl_1_bss_6EAB4)).unk_0 & 0x20) {
        return;
    }
    if (fn_1_3F864() == 0) {
        return;
    }
    if (fn_1_4C10() != 0) {
        return;
    }
    if (lbl_1_bss_6F244[0] == 0 || lbl_1_bss_6EAC6[0] == 0) {
        return;
    }
    switch (fn_1_3F0C8()) {
    case 0x25:
        return;
    }
    switch (state->unk_0->unk_48) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 10:
        fn_1_739C(&state->unk_4[idx].unk_10, mode, 4);
        break;
    case 9:
        fn_1_739C(&state->unk_8->unk_1C, mode, 4);
        break;
    }
}
/* fzgx:end fn_1_727C */

/* fzgx:begin camera_compare_values */
s32 camera_compare_values(const u8 *lhs_index, const u8 *rhs_index) {
    f32 *camera_values = &lbl_1_bss_6F524.unk_0;
    f32 lhs_value = camera_values[*lhs_index];
    f32 rhs_value = camera_values[*rhs_index];

    // Orders two camera indices by their associated values.
    if (lhs_value < rhs_value) {
        return -1;
    }
    if (lhs_value == rhs_value) {
        return 0;
    }
    return 1;
}
/* fzgx:end camera_compare_values */

/* fzgx:begin fn_1_8298 */
extern GameCameraEntry *game_camera_entries;  // array of 0x1FC-byte records

// Initializes camera entry selections and updates the camera mode from the available entries.
void fn_1_8298(void) {
    s8 found;
    s8 count;
    s32 i;

    found = 0;
    count = fn_1_86624();

    for (i = 0; i < 4; i++) {
        game_camera_entries[i].unk_2 = -1;
    }

    for (i = 0; i < count; i++) {
        s8 index = (s8)fn_1_86634(i);

        if (index != -1) {
            found++;
            game_camera_entries[index].unk_2 = i;
        }
    }

    switch (found) {
    case 0:
        OSPanic( (const char *)(u8 *)(lbl_1_data_3318), 0x7d2, (const char *)(u8 *)(lbl_1_data_35E8));
        break;
    case 1:
        lbl_1_bss_F68->unk_48 = 0;
        break;
    case 2:
        switch (lbl_1_bss_F68->unk_4B) {
        case 0:
            lbl_1_bss_F68->unk_48 = 1;
            break;
        case 1:
            lbl_1_bss_F68->unk_48 = 2;
            break;
        }
        break;
    case 3:
        switch (lbl_1_bss_F68->unk_4C) {
        case 0:
            lbl_1_bss_F68->unk_48 = 3;
            break;
        case 1:
            lbl_1_bss_F68->unk_48 = 4;
            break;
        case 2:
            lbl_1_bss_F68->unk_48 = 5;
            break;
        case 3:
            lbl_1_bss_F68->unk_48 = 6;
            break;
        case 4:
            lbl_1_bss_F68->unk_48 = 6;
            break;
        }
        break;
    case 4:
        lbl_1_bss_F68->unk_48 = 8;
        break;
    }
}
/* fzgx:end fn_1_8298 */

/* fzgx:begin fn_1_847C noprologue */
#include "types.h"

typedef struct {
    u8 pad_0[0x48];
    u8 unk_48;
} CameraObject;

typedef struct {
    u8 pad_0[0x6];
    s16 unk_6;
    u8 pad_8[0x4];
    u32 unk_C;
    u8 pad_10[0x8];
    s32 unk_18;
} CameraTable;

typedef struct {
    u8 pad_0[0x2];
    s16 unk_2;
} CameraEntry;

typedef struct {
    CameraObject *unk_0;
    CameraEntry *unk_4;
    CameraTable *unk_8;
    u8 pad_C[0x8];
    s8 unk_14;
} CameraState;

extern CameraState lbl_1_bss_F68;
extern s8 fn_1_86624(s8 mode);
extern s8 fn_1_86634(s32 index);

#pragma opt_propagation off
void fn_1_847C(s8 mode) {
    CameraState *state;
    s32 i;

    state = &lbl_1_bss_F68;
    state->unk_14 = fn_1_86624(mode);
    state->unk_8->unk_6 = -1;
    i = 0;
    while (i < state->unk_14) {
        if (fn_1_86634(i) == 0) {
            state->unk_8->unk_6 = (s16)i;
            break;
        }
        i++;
    }
    if (state->unk_8->unk_18 != 0) {
        state->unk_8->unk_C |= 0x100000;
    }
    if (mode == 1) {
        state->unk_0->unk_48 = 9;
    } else if (mode == 2) {
        state->unk_0->unk_48 = 10;
        state->unk_4->unk_2 = state->unk_8->unk_6;
    } else if (mode == 4) {
        state->unk_0->unk_48 = 9;
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_847C */

/* fzgx:begin fn_1_857C */
typedef struct {
    u32 unk_0;
    u16 entries[15];
    s16 unk_22;
    u16 unk_24;
    u8 pad_26[0x1E];
    s16 unk_44;
    u16 unk_46;
    u8 unk_48;
    u8 unk_49;
    u8 unk_4A;
    u8 unk_4B;
    u8 unk_4C;
    u8 unk_4D;
    u8 pad_4E[2];
    u32 unk_50;
} fn_1_857C_CameraState;







#pragma opt_propagation off
void fn_1_857C(void) {
    s16 index;
    s16 result;

    (*(fn_1_857C_CameraState * *)&lbl_1_bss_F68)->unk_48 = 0xb;
    lbl_1_data_3310 = lbl_1_bss_7ADE8;
    fn_1_A6FE8();
    fn_1_DCE60(lbl_1_data_3310);
    fn_1_435C((*(fn_1_857C_CameraState * *)&lbl_1_bss_F68)->unk_50);
    result = (s16)fn_1_3F8C( (u32)(char *)((*(char (*)[14])&lbl_1_data_35FC)), (u32)(void *)(fn_1_DCED0), (u32)(void *)(lbl_1_data_3310), 0x14);
    {
        fn_1_857C_CameraState *camera = (*(fn_1_857C_CameraState * *)&lbl_1_bss_F68);
        index = camera->unk_22;
        camera->unk_22 = index + 1;
        camera->entries[index] = result;
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_857C */

/* fzgx:begin camera_get_entry_field_0x2 */
// Returns the selected camera entry value for an 8-bit camera index.
s16 camera_get_entry_field_0x2(u32 index) {
    return game_camera_entries[(u8)index].unk_2;
}
/* fzgx:end camera_get_entry_field_0x2 */

/* fzgx:begin camera_set_selected_value */
// Cache the selected camera value for subsequent camera processing.
void camera_set_selected_value(u8 value) {
    lbl_1_bss_F74 = value;
}
/* fzgx:end camera_set_selected_value */

/* fzgx:begin camera_set_state_flag */
// Store the camera state flag used by subsequent camera updates.
void camera_set_state_flag(u8 value) {
    lbl_1_bss_F75 = value;
}
/* fzgx:end camera_set_state_flag */

/* fzgx:begin camera_get_values */
// Reads the camera values, falling back when the camera state cannot provide them.
s32 camera_get_values(f32 *value0, f32 *value1) {
    f32 result0;
    f32 result1;
    s32 mode;
    Obj_1_bss_F68_Target *obj;
    f32 fallback;

    obj = lbl_1_bss_F68;
    if (obj == 0) {
        mode = 0;
    } else if ((obj->unk_0 & ((u32)1 << 31)) != 0) {
        mode = 0;
    } else {
        mode = obj->unk_4A;
    }

    if (fn_1_8708(mode, &result0, &result1) != 0) {
        *value0 = result0;
        *value1 = result1;
        return 1;
    }

    fallback = (*((f32 *)&lbl_1_rodata_188));
    *value0 = fallback;
    *value1 = fallback;
    return -1;
}
/* fzgx:end camera_get_values */

/* fzgx:begin fn_1_8708 */
s32 fn_1_8708(s32 mode, f32 *value0, f32 *value1) {
    Obj_1_bss_F68_Target **pp;
    Obj_1_bss_F68_Target *obj;

    pp = &lbl_1_bss_F68;
    if (*pp == 0) {
        return -1;
    }
    obj = *pp;
    if ((obj->unk_0 & 0x80000000) != 0) {
        *value0 = lbl_1_rodata_194;
        *value1 = lbl_1_rodata_194;
        return 1;
    }
    *value0 = ((f32 (*)[2])((u8 *)obj + 0x58))[mode][0];
    *value1 = ((f32 (*)[2])((u8 *)*pp + 0x58))[mode][1];
    return 1;
}
/* fzgx:end fn_1_8708 */

/* fzgx:begin live_camera_set_shake */
// Marks the camera state active, accumulates a position delta, and tracks the highest value.
void live_camera_set_shake(s32 value, const f32 *delta) {
    LiveCamera *state;

    if (live_camera == 0) {
        OSPanic( (const char *)(u8 *)(lbl_1_data_3318), 0x89a, (const char *)(u8 *)(lbl_1_data_360C));
    }

    state = live_camera;
    state->unk_AC = 1;
    state->unk_CC += delta[0];
    state->unk_D0 += delta[1];
    state->unk_D4 += delta[2];

    if (value < 0 || (s32)state->unk_B0 < 0) {
        state->unk_B0 = -1;
    } else if ((s32)state->unk_B0 < value) {
        state->unk_B0 = value;
    }
}
/* fzgx:end live_camera_set_shake */

/* fzgx:begin fn_1_8840 */
void fn_1_8840(void) {
    LiveCamera *state;
    f32 value;

    if (live_camera == 0) {
        OSPanic( (const char *)(u8 *)(lbl_1_data_3318), 0x8b6, (const char *)(u8 *)(lbl_1_data_3630));
    }

    state = live_camera;
    value = lbl_1_rodata_188;
    state->unk_AC = 0;
    state->unk_B0 = 0;
    state->unk_C0 = value;
    state->unk_C4 = value;
    state->unk_C8 = value;
    state->unk_CC = value;
    state->unk_D0 = value;
    state->unk_D4 = value;
    state->unk_E4 = value;
    state->unk_E8 = value;
    state->unk_EC = value;
    state->unk_E4 = value;
    state->unk_E8 = value;
    state->unk_EC = value;
}
/* fzgx:end fn_1_8840 */

/* fzgx:begin game_camera_set_shake */
extern GameCameraEntry *game_camera_entries;  // array of 0x1FC-byte records

// Updates the selected camera state with a movement delta and tracks its highest value.
void game_camera_set_shake(s16 index, s16 mode, s32 value, const f32 *delta) {
    GameCameraEntry *camera;

    if (index < 0) {
        return;
    }

    if (game_camera_entries + index == 0) {
        OSPanic( (const char *)(u8 *)(lbl_1_data_3318), 0x8d1, (const char *)(u8 *)(lbl_1_data_3654));
    }

    camera = game_camera_entries + index;
    if (mode != camera->unk_2) {
        fn_1_8A0C(index);
        return;
    }

    camera->unk_10C = 1;
    camera->unk_12C += delta[0];
    camera->unk_130 += delta[1];
    camera->unk_134 += delta[2];
    camera->unk_150 += delta[2];
    camera->unk_154 += delta[1];
    camera->unk_158 += delta[0];

    if (value < 0 || (s32)camera->unk_110 < 0) {
        camera->unk_110 = -1;
    } else if ((s32)camera->unk_110 < value) {
        camera->unk_110 = value;
    }
}
/* fzgx:end game_camera_set_shake */

/* fzgx:begin fn_1_8A0C */
void fn_1_8A0C(s16 index) {
    GameCameraEntry *entry;
    f32 value;

    if (index >= 0) {
        if (game_camera_entries + index == 0) {
            OSPanic( (const char *)(u8 *)(lbl_1_data_3318), 0x8f8, (const char *)(u8 *)(lbl_1_data_3654));
        }
        entry = game_camera_entries + index;
        value = lbl_1_rodata_188;
        entry->unk_10C = 0;
        entry->unk_110 = 0;
        entry->unk_120 = value;
        entry->unk_124 = value;
        entry->unk_128 = value;
        entry->unk_12C = value;
        entry->unk_130 = value;
        entry->unk_134 = value;
        entry->unk_144 = value;
        entry->unk_148 = value;
        entry->unk_14C = value;
        entry->unk_144 = value;
        entry->unk_148 = value;
        entry->unk_14C = value;
    }
}
/* fzgx:end fn_1_8A0C */

/* fzgx:begin camera_init */
// Initialize camera state before passing the shared camera object onward.
void camera_init(void) {
    fn_1_A6FE8();
    fn_1_8D08(game_camera_entries);
}
/* fzgx:end camera_init */

/* fzgx:begin live_camera_get */
// Return the shared camera object used by the camera system.
LiveCamera *live_camera_get(void) {
    return live_camera;
}
/* fzgx:end live_camera_get */

/* fzgx:begin game_camera_get */
// Return the current camera target object.
GameCameraEntry *game_camera_get(void) {
    return game_camera_entries;
}
/* fzgx:end game_camera_get */

/* fzgx:begin fn_1_8B10 */
typedef struct fn_1_8B10_CameraObject {
    s16 pad_00;
    s16 kind;
    u8 pad_04[0xA0];
    s16 index;
} fn_1_8B10_CameraObject;


typedef struct CameraData {
    u8 pad_000[0x118];
    f32 x;
    f32 y;
} CameraData;

typedef struct fn_1_8B10_CameraEntry {
    f32 x;
    f32 y;
    s16 flags0;
    u8 pad_0A[2];
    f32 x1;
    f32 y1;
    s16 flags1;
    u8 pad_16[2];
    f32 x2;
    f32 y2;
    s16 flags2;
    u8 pad_22[2];
} fn_1_8B10_CameraEntry;

typedef struct CameraOutput {
    f32 x0;
    f32 y0;
    s16 flags0;
    u8 pad_0A[2];
    f32 x1;
    f32 y1;
    s16 flags1;
    u8 pad_16[2];
    f32 x2;
    f32 y2;
    s16 flags2;
} CameraOutput;




void fn_1_8B10(fn_1_8B10_CameraObject *camera, CameraOutput *output) {
    CameraTarget *target;
    CameraData *data;

    target = (CameraTarget *)fn_1_868C0((s8)camera->kind);
    if (camera->index == 0 && target != 0 && (data = target->data) != 0) {
        output->x0 = lbl_1_rodata_200 + data->x;
        output->y0 = data->y;
        output->flags0 = 0;
        output->x1 = lbl_1_rodata_200 + data->x;
        output->y1 = data->y;
        output->flags1 = 0;
        output->x2 = lbl_1_rodata_200 + data->x;
        output->y2 = data->y;
        output->flags2 = 0x1AAA;
    } else {
        output->x0 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].x;
        output->y0 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].y;
        output->flags0 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].flags0;
        output->x1 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].x1;
        output->y1 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].y1;
        output->flags1 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].flags1;
        output->x2 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].x2;
        output->y2 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].y2;
        output->flags2 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].flags2;

        if ((s8)fn_1_A5DC4() != 0) {
            f32 adjust;
            switch (camera->index) {
            case 1:
                adjust = lbl_1_rodata_200;
                break;
            case 2:
                adjust = lbl_1_rodata_204;
                break;
            case 3:
                adjust = lbl_1_rodata_204;
                break;
            default:
                adjust = lbl_1_rodata_200;
                break;
            }
            output->x0 -= adjust;
            output->x1 -= adjust;
            output->x2 -= adjust;
        }
    }
}
/* fzgx:end fn_1_8B10 */

/* fzgx:begin fn_1_A888 noprologue */
#include "types.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.30000001192092896f;
    s = 1.100000023841858f;
}
static const unsigned long fzgx_pool_table2[9] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 55.0f;
    s = 0.0f;
    s = -10.0f;
    d = 0.5;
    d = 4503601774854144.0;
}
static const unsigned long fzgx_pool_table4[18] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x40400000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1500.0f;
    s = 53.0f;
    s = 3.0f;
    s = 0.009999999776482582f;
    d = 0.05;
    s = 3.9999998989515007e-05f;
    s = 80.0f;
    s = 108.0f;
    s = 1.350000023841858f;
    s = 90.0f;
    s = 1.2000000476837158f;
    s = 0.20000000298023224f;
}
static const unsigned long fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 0.05000000074505806f;
    s = 0.10000000149011612f;
    d = 0.15;
    s = 1.0f;
    s = 182.04444885253906f;
    s = 0.4000000059604645f;
}
static const unsigned long fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.12;
    s = 5000.0f;
}
static const unsigned long fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.2;
    d = 1.4;
    d = 1.7;
    d = 0.08;
    d = 0.2;
    d = 0.04;
    s = 0.5f;
}
static const unsigned long fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.1;
    s = 1.5f;
    s = 2.299999952316284f;
    s = 0.699999988079071f;
}
static const unsigned long fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.3;
    d = 55.0;
    d = 150.0;
    s = 65.0f;
    s = 0.00023668639187235385f;
    s = 60.0f;
    s = 0.00027777778450399637f;
    d = 7.19;
    s = 5.0f;
    s = 2.940000057220459f;
    d = 4503599627370496.0;
    s = -13.0f;
    s = -20.0f;
    s = 13.0f;
}
static const unsigned long fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 3.0;
}
#pragma section code_type ".text"

typedef struct { f32 x, y, z; } V3;
typedef struct { s16 pad0; s16 id; u8 pad4[0x6C]; f32 val; } Cam;
typedef struct { u8 pad[0x7c]; u32 flags; } Obj;

extern void *fn_1_8627C(s32);
extern void fn_1_862D4(s32, V3 *);
extern void fn_1_8636C(s32, void *);
extern u32 fn_1_20A5C(void *, void *);
extern void fn_1_15578(void *, void *, void *, void *, u32, void *, u32, u32, u32, u32);
extern u32 lbl_8006DAEC(void);
extern void *lbl_8006DC6C(void *);
extern void lbl_8006E1B0(V3 *, V3 *);
extern void fn_8006E250(V3 *, V3 *);
extern void lbl_8006DB30(void);

static inline f64 fn_1_A888_clamp(f64 value) {
    if (value < 0.0) {
        return 0.0;
    }
    if (value > 3.0) {
        return 3.0;
    }
    return value;
}

#pragma opt_propagation off
f32 fn_1_A888(Cam *cam) {
    V3 loc48;
    struct { u32 a[15]; } loc54;
    V3 loc3C;
    V3 loc30;
    V3 loc24;
    u32 loc18[3];
    u32 loc14;
    u32 loc10;
    Obj *obj;
    s32 flag;
    f32 r;
    f64 c;
    f64 t;
    lbl_8006DAEC();
    obj = (Obj *)fn_1_8627C(cam->id);
    if (obj == 0) {
        return 0.0f;
    }
    flag = (obj->flags >> 24) & 1;
    fn_1_862D4(cam->id, &loc48);
    fn_1_8636C(cam->id, &loc54);
    lbl_8006DC6C(&loc54);
    {
        f32 fzgx_lc0_z;
        f32 fzgx_lc0_y;
        f32 fzgx_lc0_x;
        fzgx_lc0_x = loc48.x;
        fzgx_lc0_y = loc48.y;
        fzgx_lc0_z = loc48.z;
        *(f32 *)(0xE0000000 + 0x0C) = fzgx_lc0_x;
        *(f32 *)(0xE0000000 + 0x1C) = fzgx_lc0_y;
        *(f32 *)(0xE0000000 + 0x2C) = fzgx_lc0_z;
    }
    loc3C.x = 0.0f;
    loc3C.y = -13.0f;
    loc3C.z = -20.0f;
    lbl_8006E1B0(&loc3C, &loc30);
    loc3C.y = 13.0f;
    lbl_8006E1B0(&loc3C, &loc24);
    loc14 = fn_1_20A5C(&loc24, &loc10);
    fn_1_15578(&loc30, &loc24, &loc10, loc18, 0x80001, &loc14, 1, 0, 0, 0);
    lbl_8006DC6C(&loc54);
    {
        f32 fzgx_lc1_z;
        f32 fzgx_lc1_y;
        f32 fzgx_lc1_x;
        fzgx_lc1_x = loc48.x;
        fzgx_lc1_y = loc48.y;
        fzgx_lc1_z = loc48.z;
        *(f32 *)(0xE0000000 + 0x0C) = fzgx_lc1_x;
        *(f32 *)(0xE0000000 + 0x1C) = fzgx_lc1_y;
        *(f32 *)(0xE0000000 + 0x2C) = fzgx_lc1_z;
    }
    fn_8006E250(&loc30, &loc30);
    r = (f32)fn_1_A888_clamp(1.2 + loc30.y) / 3.0;
    if (flag != 0) {
        r = 0.3f;
    }
    {
        f32 old = cam->val;
        f64 d = 0.08 * (r - old);
        cam->val = old + d;
    }
    lbl_8006DB30();
    return r;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_A888 */

/* fzgx:begin fn_1_AA54 */
struct fn_1_AA54_Arg0 {
    u8 pad_0[0x2];
    s16 unk_2;
};


void fn_1_AA54(void *arg0) {
    s16 temp_r28;
    u8 temp_r31;
    u8 temp_r3;

    temp_r31 = fn_1_86678((s32) (*(s16 *)((u8 *)(arg0) + 2)));
    temp_r3 = (s8)fn_1_86634((s32) (*(s16 *)((u8 *)(arg0) + 2)));
    temp_r28 = camera_get_entry_field_0xa8((u32) temp_r3);
    if (((s16) (*(s16 *)((u8 *)(&(*((s16 *)&lbl_1_bss_960))) + 0)) != 9) && (fn_1_864E8((s32) (*(s16 *)((u8 *)(arg0) + 2))) & 0x10000)) {
        camera_set_entry_field_0xa8(temp_r3, 2);
        return;
    }
    if (!(fn_1_864E8((s32) (*(s16 *)((u8 *)(arg0) + 2))) & 1)) {
        if (fn_1_864E8((s32) (*(s16 *)((u8 *)(arg0) + 2))) & 0x800) {
            camera_set_entry_field_0xa8(temp_r3, 5);
            return;
        }
        if (!(fn_1_864E8((s32) (*(s16 *)((u8 *)(arg0) + 2))) & 0x80)) {
            goto block_7; /* Preserves the retail branch. */
        }
    } else {
block_7:
        if ((f64) (*(f64 *)((u8 *)(&lbl_1_rodata_360) + 0)) == (f64) (f64) fn_1_8664C((s32) (*(s16 *)((u8 *)(arg0) + 2)))) {
            camera_set_entry_field_0xa8(temp_r3, 3);
            return;
        }
        if (fn_1_8664C((s32) (*(s16 *)((u8 *)(arg0) + 2))) == 0x14) {
            camera_set_entry_field_0xa8(temp_r3, 0);
            return;
        }
        if ((s8) temp_r31 >= 0) {
            camera_set_entry_field_0xa8(temp_r3, temp_r28);
        }
    }
}
/* fzgx:end fn_1_AA54 */

/* fzgx:begin fn_1_ABAC noprologue */
#include "types.h"

typedef struct fn_1_ABAC_Camera {
    u8 pad_0[0x2];
    s16 unk_2;
    u8 pad_4[0xA2];
    s16 unk_A6;
    s16 unk_A8;
} fn_1_ABAC_Camera;

typedef struct fn_1_ABAC_Target {
    u8 pad_0[0x214];
    u16 unk_214;
} fn_1_ABAC_Target;

// Pad input state: retail reloads the button words between the bit tests, so
// the fields are volatile.
typedef struct fn_1_ABAC_PadEntry {
    u8 pad_0[0x10];
    volatile u16 unk_10;  // volatile: pad input, retail reloads it at every bit test
    volatile u16 unk_12;  // volatile: pad input, retail reloads it at every bit test
} fn_1_ABAC_PadEntry;

extern fn_1_ABAC_Target *fn_1_86254(s32 index);
extern s32 fn_1_F2F34(void);
extern s16 camera_get_entry_field_0xa4(u32);
extern s8 fn_1_86678(int index);
extern s8 fn_1_86634(int index);
extern void fn_1_715C(u8, s16);
extern u32 fn_1_864E8(int index);
extern s32 fn_1_40BB4(void);
extern s16 lbl_1_bss_960;
extern fn_1_ABAC_PadEntry lbl_1_bss_9F8[];
extern u8 lbl_1_bss_CC0[152];

// Button byte per player, reloaded at every test like the pad words.
#define FN_1_ABAC_BUTTONS(p) (((volatile u8 *)lbl_1_bss_CC0)[p])

// Steps the camera view selection from the player's pad input.
void fn_1_ABAC(fn_1_ABAC_Camera *camera) {
    s16 view;
    s8 slot;
    fn_1_ABAC_Target *target;
    s8 player;

    target = fn_1_86254(camera->unk_2);
    if (fn_1_F2F34() != 0) {
        player = 0;
        slot = 0;
        view = camera_get_entry_field_0xa4(0);
    } else {
        player = fn_1_86678(camera->unk_2);
        slot = fn_1_86634(camera->unk_2);
        view = camera_get_entry_field_0xa4((u8)slot);
    }

    if (target->unk_214 > 1) {
        fn_1_715C(slot, 5);
        return;
    }
    if (target->unk_214 == 1) {
        fn_1_715C(slot, camera->unk_A6);
        return;
    }
    if (fn_1_864E8(camera->unk_2) & 0x80) {
        fn_1_715C(slot, 5);
        return;
    }

    camera->unk_A6 = view;
    if (player == -1) {
        return;
    }
    if (lbl_1_bss_960 == 10) {
        return;
    }
    if (fn_1_40BB4() != 0) {
        return;
    }

    if (fn_1_F2F34() != 0) {
        if (((lbl_1_bss_9F8[player].unk_10 >> 2) & 1) || ((lbl_1_bss_9F8[player].unk_12 >> 2) & 1)) {
            view++;
        }
        if (((lbl_1_bss_9F8[player].unk_10 >> 3) & 1) || ((lbl_1_bss_9F8[player].unk_12 >> 3) & 1)) {
            view--;
        }
    } else {
        if ((FN_1_ABAC_BUTTONS(player) >> 1) & 1) {
            view++;
        }
        if (FN_1_ABAC_BUTTONS(player) & 1) {
            view--;
        }
    }

    if (view <= 0) {
        view = 0;
    }
    if (camera->unk_A8 == 1) {
        if ((u32)view >= 12) {
            view = 11;
        }
    } else {
        if ((u32)view >= 4) {
            view = 3;
        }
    }
    fn_1_715C(slot, view);
}
/* fzgx:end fn_1_ABAC */

/* fzgx:begin camera_get_position_delta */
// Computes the displacement between two camera positions.
void camera_get_position_delta(u32 index, Vec3 *out) {
    u8 idx = (u8)index;
    Vec3 first;
    Vec3 second;

    fn_1_862D4(idx, &first);
    fn_1_8658C(idx, &second);
    out->x = first.x - second.x;
    out->y = first.y - second.y;
    out->z = first.z - second.z;
}
/* fzgx:end camera_get_position_delta */

/* fzgx:begin camera_reset_transition */
// Resets the camera transition state before refreshing the camera.
void camera_reset_transition(camera_reset_transition_Camera *camera) {
    camera->unk_A4 = 0;
    fn_1_AEB8(camera);
}
/* fzgx:end camera_reset_transition */

/* fzgx:begin camera_update_transition */
// Advances the camera's transition state and updates its active view.
void camera_update_transition(camera_update_transition_Camera *camera) {
    if (camera->unk_78 == 0) {
        camera->unk_A4++;
        if (camera->unk_A4 >= camera_transition_count) {
            camera->unk_A4 = 0;
        }
        fn_1_AEB8( (camera_reset_transition_Camera *)(camera_update_transition_Camera *)(camera));
    }

    fn_1_AFC8(camera);

    if (camera->unk_78 != 0) {
        camera->unk_78--;
    }
}
/* fzgx:end camera_update_transition */

/* fzgx:begin fn_1_AEB8 noprologue */
#include "rel/main_rel/camera.h"

extern f32 lbl_1_rodata_230[44];

typedef struct { f32 x, y, z; } Vec;

typedef struct {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x6C];
    s16 unk_78;
    u8 pad_7A[0x12];
    Vec unk_8C;
    Vec unk_98;
    s16 unk_A4;
    u8 pad_A6[0x13E];
    Vec unk_1E4;
    f32 unk_1F0;
    f32 unk_1F4;
    u8 pad_1F8[2];
    s16 unk_1FA;
} Camera;

typedef struct {
    u32 unk_0;
    Vec position;
    Vec target;
    f32 value;
    s16 count;
    s16 pad;
} TransitionConfig;

typedef struct {
    s32 mode;
    f32 unk_4;
    TransitionConfig config;
    u8 pad_2C[0x28];
} TransitionPreset;

void fn_1_AEB8(Camera *camera) {
    TransitionPreset *preset;
    TransitionConfig config;
    Vec position;
    s32 index = camera->unk_A4;
    if (lbl_1_bss_960 == 14) {
        camera_transition_count = 14;
        preset = &((TransitionPreset *)lbl_1_data_3BD0)[index];
    } else {
        camera_transition_count = 5;
        preset = &((TransitionPreset *)&lbl_1_data_3A2C)[index];
    }
    config = preset->config;
    position = config.position;
    camera->unk_1E4 = position;
    camera->unk_1F0 = 0.0f;
    camera->unk_1F4 = 0.0f;
    camera->unk_78 = preset->mode;
    camera->unk_8C = config.position;
    camera->unk_98 = config.target;
    camera->unk_1FA = config.count;
    camera->unk_8 = config.value;
    camera->unk_1FA = config.count;
}
/* fzgx:end fn_1_AEB8 */

/* fzgx:begin camera_get_target_orientation */
typedef struct camera_get_target_orientation_CameraObject {
    u8 pad_49c[0x49c];
    Transform *unk_49C;
} camera_get_target_orientation_CameraObject;


// Updates the camera orientation from the active target transform.
f32 camera_get_target_orientation(camera_get_target_orientation_CameraObject *camera) {
    Transform *target = camera->unk_49C;

    if (target == 0) {
        return lbl_1_rodata_2E0[0];
    }
    if ((target->unk_7C & 0x01800000) == 0) {
        return lbl_1_rodata_2E0[0];
    }

    lbl_801A66CC->unk_D4 = -lbl_801A6D00->unk_08;
    lbl_801A66CC->unk_D8 = -lbl_801A6D00->unk_18;
    lbl_801A66CC->unk_DC = -lbl_801A6D00->unk_28;
    return lbl_8006D6FC(&lbl_801A66CC->unk_D4, &target->unk_50);
}
/* fzgx:end camera_get_target_orientation */

/* fzgx:begin fn_1_B4D4 pool noprologue */
#include "types.h"
#include "psvec.h"

typedef struct {
    f32 x, y, z;
} fn_1_B4D4_Vec;

struct fn_1_B4D4_Camera {
    u8 pad_0[0x10];
    fn_1_B4D4_Vec pos;           /* 0x10 */
    u8 pad_1C[0xC];
    fn_1_B4D4_Vec target;        /* 0x28 */
    u8 pad_34[0x74];
    s16 unk_A8;
    u8 pad_AA[0x62];
    s32 unk_10C;
    s32 unk_110;
    fn_1_B4D4_Vec posBase;       /* 0x114 */
    fn_1_B4D4_Vec posOfs;        /* 0x120 */
    fn_1_B4D4_Vec posVel;        /* 0x12C */
    fn_1_B4D4_Vec targetBase;    /* 0x138 */
    fn_1_B4D4_Vec targetOfs;     /* 0x144 */
    fn_1_B4D4_Vec targetVel;     /* 0x150 */
};

extern u32 lbl_1_bss_F5C;
extern void fn_1_8840(void);

/* stands in for the camera TU's literal pool ahead of this function's constants */
const struct {
    f32 f[88];
    f64 d[17];
} fn_1_B4D4_pool_head = {
    {
        0.3f,
        1.1f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 55.0f,
        0.0f, -10.0f, 1.75f, 0.0f, 176.0f, -0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 3.0f, 0.0f,
        1500.0f, 53.0f, 3.0f, 0.01f, 1.3249999f, -0.000000000000000000000015881868f,
        0.00004f, 80.0f, 108.0f, 1.35f, 90.0f, 1.2f, 0.2f, 0.0f, 1.035f, 89128.96f,
        0.05f, 0.1f, 1.525f, 0.00000004172325f,
        1.0f, 182.04445f, 0.4f, 0.0f, 1.4899999f, -321864400000000000000000000.0f,
        5000.0f, 0.0f, 1.9f, 0.00000004172325f, 1.925f, 272008300000000000000000.0f,
        1.9625f, 0.00000004172325f, 1.41f, 89128.96f, 1.5749999f,
        -0.000000000000000000000015881868f, 1.285f, 89128.96f, 0.5f, 0.0f, 1.4499999f,
        -0.000000000000000000000015881868f, 1.5f, 2.3f, 0.7f, 0.0f, 1.65f,
        0.00000004172325f, 3.1796875f, 0.0f,
    },
    {
        150.0, 2473901633285.8774, 1099511863578.169, 7.19, 2048.000490074158,
        4503599627370496.0, -4194307.025390625, 4194304.0, 0.0, 3.0, 0.02,
        2199023255552.0, 135.0, 0.0, 0.0, 0.0, 1.0,
    },
};

#pragma fp_contract off
void fn_1_B4D4(struct fn_1_B4D4_Camera *cam) {
    if (cam->unk_10C == 0) {
        cam->posBase = cam->pos;
        cam->targetBase = cam->target;
        return;
    }
    if (!(lbl_1_bss_F5C & 0x50000000)) {
        cam->posVel.x = cam->posVel.x - 0.75 * cam->posOfs.x;
        cam->posVel.y = cam->posVel.y - 0.75 * cam->posOfs.y;
        cam->posVel.z = cam->posVel.z - 0.75 * cam->posOfs.z;
        cam->posVel.x *= 0.8;
        cam->posVel.y *= 0.8;
        cam->posVel.z *= 0.8;
        cam->posOfs.x = cam->posOfs.x + cam->posVel.x;
        cam->posOfs.y = cam->posOfs.y + cam->posVel.y;
        cam->posOfs.z = cam->posOfs.z + cam->posVel.z;
        cam->targetVel.x = cam->targetVel.x - 0.72 * cam->targetOfs.x;
        cam->targetVel.y = cam->targetVel.y - 0.72 * cam->targetOfs.y;
        cam->targetVel.z = cam->targetVel.z - 0.72 * cam->targetOfs.z;
        cam->targetVel.x *= 0.75;
        cam->targetVel.y *= 0.75;
        cam->targetVel.z *= 0.75;
        cam->targetOfs.x = cam->targetOfs.x + cam->targetVel.x;
        cam->targetOfs.y = cam->targetOfs.y + cam->targetVel.y;
        cam->targetOfs.z = cam->targetOfs.z + cam->targetVel.z;
    }
    psvec_add(&cam->posBase, &cam->posOfs, &cam->pos);
    if (cam->unk_A8 == 0) {
        psvec_add(&cam->targetBase, &cam->targetOfs, &cam->target);
    }
    if (!(lbl_1_bss_F5C & 0x50000000) && cam->unk_110 > 0) {
        cam->unk_110--;
        if (cam->unk_110 == 0) {
            fn_1_8840();
        }
    }
}
#pragma fp_contract reset
/* fzgx:end fn_1_B4D4 */

/* fzgx:begin fn_1_B81C */
struct fn_1_B81C_Copy12 { u32 a[3]; };

void fn_1_B81C(struct fn_1_B81C_Copy12 *first, struct fn_1_B81C_Copy12 *second, u32 value) {
    *(struct fn_1_B81C_Copy12 *)((u8 *)&camera_state + 4) = *first;
    *(struct fn_1_B81C_Copy12 *)((u8 *)&camera_state + 16) = *second;
    camera_state.unk_20 = value;
}
/* fzgx:end fn_1_B81C */

/* fzgx:begin camera_save_parameters */
// Saves the two current camera parameters for later processing.
void camera_save_parameters(f32 first_parameter, f32 second_parameter) {
    lbl_1_bss_1040 = first_parameter;
    lbl_1_bss_1044 = second_parameter;
}
/* fzgx:end camera_save_parameters */

/* fzgx:begin fn_1_B870 pool noprologue */
#include "types.h"
#include "game/vec3.h"

typedef struct B870Camera {
    u8 pad_0[0x4];
    Vec3f pos;    /* 0x04 */
    Vec3f lookAt; /* 0x10 */
    f32 fov;      /* 0x1C */
    s16 rotZ;     /* 0x20 */
} B870Camera;

typedef struct {
    u8 pad_0[0x8];
    u16 unk_8;
} B870Bss_D58;

typedef struct {
    s8 stick[4];
    u8 unk_4;
} B870Bss_A48;

typedef struct {
    u16 unk_0;
    u16 unk_2;
    u8 pad_4[0x4];
    u16 unk_8;
} B870Bss_9F8;

extern B870Bss_D58 lbl_1_bss_D58;
extern B870Bss_A48 lbl_1_bss_A48;
extern B870Bss_9F8 lbl_1_bss_9F8;

/* camera.c's .bss cluster at lbl_1_bss_1010, addressed off one section base. */
u32 fzgx_obj_lbl_1_bss_1010;
u8 lbl_1_bss_1014;
B870Camera lbl_1_bss_1018;
f32 fzgx_obj_lbl_1_bss_103C;
f32 lbl_1_bss_1040;
f32 lbl_1_bss_1044;
u8 lbl_1_bss_1048;
u8 lbl_1_bss_1049;

extern void fn_1_C770(void);
extern void fn_8006EDBC(Vec3f *, Vec3f *, s16 *, s16 *);
extern void lbl_8006D7DC(Vec3f *);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_z(s16);
extern void lbl_8006E1B0(Vec3f *, Vec3f *);
extern void fn_8006E250(Vec3f *, Vec3f *);
extern f32 lbl_8006D0E8(f32);
extern f32 lbl_8006D0B4(f32);

/* Primer: the .bss order and the literals of earlier camera.c functions, as in retail. */
extern void fzgx_touch_f(f32);
extern void fzgx_touch(void *);
#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_pool_primer(void) {
    fzgx_touch(&fzgx_obj_lbl_1_bss_1010);
    fzgx_touch(&lbl_1_bss_1014);
    fzgx_touch(&lbl_1_bss_1018);
    fzgx_touch(&fzgx_obj_lbl_1_bss_103C);
    fzgx_touch(&lbl_1_bss_1040);
    fzgx_touch(&lbl_1_bss_1044);
    fzgx_touch(&lbl_1_bss_1048);
    fzgx_touch(&lbl_1_bss_1049);
    fzgx_touch_f(1.0f);
    fzgx_touch_f(0.1f);
    fzgx_touch_f(0.01f);
    fzgx_touch_f(55.0f);
}

#pragma opt_lifetimes off
void fn_1_B870(void) {
    f32 speed;
    f32 clamped;
    f32 scale;
    s32 rot;
    s32 zoom;
    u32 buttons;
    s16 rotX;
    s16 rotY;

    if ((lbl_1_bss_D58.unk_8 >> 10) & 1) {
        lbl_1_bss_1048 ^= 1;
    }
    if (lbl_1_bss_1014 != 0) {
        fn_1_C770();
        return;
    }
    fn_8006EDBC(&lbl_1_bss_1018.pos, &lbl_1_bss_1018.lookAt, &rotX, &rotY);
    speed = fzgx_obj_lbl_1_bss_103C;
    speed = 0.040000000000000008 * speed;
    speed = speed * (1.0 + 4.0 * lbl_1_bss_A48.unk_4 / 140.0);
    clamped = (speed > 50.0) ? 50.0 : speed;
    {
        Vec3f offsetA = {0.0f, 0.0f, 0.0f};
        Vec3f offsetB = {0.0f, 0.0f, 0.0f};
        Vec3f tmp;

        if (lbl_1_bss_1049 != 0 && !((lbl_1_bss_9F8.unk_0 >> 6) & 1)) {
            offsetA.x = speed * (*((0) + (lbl_1_bss_A48.stick))) / 60.0;
            if ((lbl_1_bss_9F8.unk_2 >> 9) & 1) {
                offsetA.y = clamped * (*((1) + (lbl_1_bss_A48.stick))) / 60.0;
            } else {
                offsetA.z = -clamped * (*((1) + (lbl_1_bss_A48.stick))) / 60.0;
            }
            offsetB.x = speed * (*((2) + (lbl_1_bss_A48.stick))) / 60.0;
            if (((*(volatile u16 *)&lbl_1_bss_9F8.unk_2) >> 9) & 1) { /* Retail reloads the mode for the second stick. */
                offsetB.y = clamped * (*((3) + (lbl_1_bss_A48.stick))) / 60.0;
            } else {
                offsetB.z = -clamped * (*((3) + (lbl_1_bss_A48.stick))) / 60.0;
            }
        }
        lbl_8006D7DC(&lbl_1_bss_1018.pos);
        mathutil_mtxA_rotate_y(rotY);
        mathutil_mtxA_rotate_x(rotX);
        mathutil_mtxA_rotate_z(lbl_1_bss_1018.rotZ);
        lbl_8006E1B0(&offsetA, &lbl_1_bss_1018.pos);
        fn_8006E250(&lbl_1_bss_1018.lookAt, &tmp);
        tmp.x += offsetB.x;
        tmp.y += offsetB.y;
        tmp.z += offsetB.z;
        lbl_8006E1B0(&tmp, &lbl_1_bss_1018.lookAt);
        tmp.x = lbl_1_bss_1018.lookAt.x - lbl_1_bss_1018.pos.x;
        tmp.y = lbl_1_bss_1018.lookAt.y - lbl_1_bss_1018.pos.y;
        tmp.z = lbl_1_bss_1018.lookAt.z - lbl_1_bss_1018.pos.z;
        if (__fmadds(tmp.z, tmp.z, __fmadds(tmp.y, tmp.y, tmp.x * tmp.x)) < 0.09) {
            scale = 0.3 * lbl_8006D0E8(__fmadds(tmp.z, tmp.z, __fmadds(tmp.y, tmp.y, tmp.x * tmp.x)));
            lbl_1_bss_1018.lookAt.x = lbl_1_bss_1018.pos.x + (f32)(tmp.x * scale);
            lbl_1_bss_1018.lookAt.y = lbl_1_bss_1018.pos.y + (f32)(tmp.y * scale);
            lbl_1_bss_1018.lookAt.z = lbl_1_bss_1018.pos.z + (f32)(tmp.z * scale);
        }
    }
    {
        Vec3f *pos = &lbl_1_bss_1018.pos;
        Vec3f *lookAt = &lbl_1_bss_1018.lookAt;
        f32 dx = pos->x;
        f32 dz = pos->z;
        f32 dy = pos->y;
        dx -= lookAt->x;
        dy -= lookAt->y;
        dz -= lookAt->z;
        dx = dx * dx;
        dx = dy * dy + dx;
        dx = dz * dz + dx;
        fzgx_obj_lbl_1_bss_103C = lbl_8006D0B4(dx);
    }
    if (((lbl_1_bss_9F8.unk_2 >> 9) & 1) && lbl_1_bss_1049 != 0) {
        buttons = (*(u16 volatile *)&(lbl_1_bss_9F8.unk_0)) /* Retail reloads this field. */;
        if (buttons & 1) {
            rot = 0x800;
        } else {
            rot = ((buttons >> 1) & 1) ? -0x800 : 0;
        }
{
    B870Camera *cam = &lbl_1_bss_1018;
        cam->rotZ += rot;
}
        buttons = lbl_1_bss_9F8.unk_0;
        if ((buttons >> 2) & 1) {
            zoom = 1;
        } else {
            zoom = ((buttons >> 3) & 1) ? -1 : 0;
        }
        lbl_1_bss_1018.fov += zoom;
        lbl_1_bss_1018.fov = (lbl_1_bss_1018.fov < 0.1) ? 0.1
                           : (lbl_1_bss_1018.fov > 90000.0) ? 90000.0 : lbl_1_bss_1018.fov;
        if ((lbl_1_bss_9F8.unk_8 >> 9) & 1) {
            lbl_1_bss_1018.rotZ = 0;
            lbl_1_bss_1018.fov = 55.0f;
        }
    }
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_B870 */

/* fzgx:begin fn_1_BFA0 pool */
extern u32 fn_1_CC5C(void);
extern void fn_1_55FC4(f32);
extern void fn_1_55FF0(f32);
extern u32 fn_1_55210(u32);
extern void lbl_8006D9D8(CamEntry *);
extern void lbl_8006E14C(f32);
extern void fn_80072558(void);
extern u32 lbl_801A6CE0;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_1010;
u8 lbl_1_bss_1014;
u8 lbl_1_bss_1010_gap_1015;
u16 lbl_1_bss_1010_gap_1015_fill_1016;
CamEntry fzgx_obj_camera_state[2];
u32 camera_state_fill_1038;
u8 lbl_1_bss_103C[4];
f32 lbl_1_bss_1040;
f32 lbl_1_bss_1044;
u8 fzgx_obj_camera_flag_0;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_1010;
    s = *(u8 *)&lbl_1_bss_1014;
    s = *(u8 *)&lbl_1_bss_1010_gap_1015;
    s = *(u8 *)&lbl_1_bss_1010_gap_1015_fill_1016;
    s = *(u8 *)&fzgx_obj_camera_state;
    s = *(u8 *)&camera_state_fill_1038;
    s = *(u8 *)&lbl_1_bss_103C;
    s = *(u8 *)&lbl_1_bss_1040;
    s = *(u8 *)&lbl_1_bss_1044;
    s = *(u8 *)&fzgx_obj_camera_flag_0;
}
#pragma section code_type ".text"

/* Per-frame camera update: runs the pending callback and refreshes the camera state. */
void fn_1_BFA0(void) {
    if (lbl_1_bss_1014 != 0) {
        fn_1_CC5C();
    }
    if (fzgx_obj_camera_flag_0 != 0) {
        lbl_8006D9D8(&fzgx_obj_camera_state[1]);
        lbl_8006E14C(lbl_1_bss_1044);
        fn_1_55FC4(lbl_1_bss_1044);
        fn_80072558();
        fn_1_55FF0(lbl_1_bss_1040);
        if (lbl_801A6CE0 & 1) {
            fn_1_55210(lbl_1_bss_38454->unk_8->unk_20);
        }
    }
}
/* fzgx:end fn_1_BFA0 */

/* fzgx:begin fn_1_C038 */
void fn_1_C038(s32 value, f32 start, f32 end) {
    f32 difference;
    f32 ratio;
    f32 converted;

    difference = end - start;
    ratio = difference / (f32)(((u32)(value * value)) >> 2);

    lbl_1_bss_10C0[0] = start;
    lbl_1_bss_10C0[1] = end;
    lbl_1_bss_10C0[4] = lbl_1_rodata_49C;

    lbl_1_bss_10C0[5] = ratio;
    converted = (f32)(u32)value;
    lbl_1_bss_10C0[3] = converted;
    lbl_1_bss_10C0[2] = converted;
}
/* fzgx:end fn_1_C038 */

/* fzgx:begin camera_save_slot */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
} CameraSlot;

// Copies the current camera parameters into the selected camera slot.
void camera_save_slot(u8 index) {
    CameraSlot *dst = (CameraSlot *)&lbl_1_bss_10D8 + index;

    dst->unk_0 = camera_state.unk_0;
    dst->unk_4 = camera_state.unk_4;
    dst->unk_8 = camera_state.unk_8;
    dst->unk_C = camera_state.unk_C;
    dst->unk_10 = camera_state.unk_10;
    dst->unk_14 = camera_state.unk_14;
    dst->unk_18 = camera_state.unk_18;
    dst->unk_1C = camera_state.unk_1C;
    dst->unk_20 = *(u32 *)&camera_state.unk_20;
}
/* fzgx:end camera_save_slot */

/* fzgx:begin fn_1_C10C pool noprologue */
#include "types.h"

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
} CameraPreset;

typedef struct {
    u8 pad_0[0x5];
    u8 unk_5;
    u8 pad_6[0x2];
    CameraPreset current;
    u8 pad_2C[0x9C];
    CameraPreset presets[1];
} CameraState;


/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_1010;
u8 lbl_1_bss_1014;
u8 lbl_1_bss_1010_gap_1015;
u16 lbl_1_bss_1010_gap_1015_fill_1016;
CameraPreset fzgx_obj_camera_state;
u32 lbl_1_bss_103C;
u32 lbl_1_bss_1040;
u32 lbl_1_bss_1044;
u8 fzgx_obj_camera_flag_0;
u8 fzgx_obj_camera_flag_1;
u16 lbl_1_bss_1010_gap_104A;
u32 lbl_1_bss_104C[16];
u32 lbl_1_bss_108C[13];
u32 lbl_1_bss_10C0[6];
CameraPreset fzgx_obj_lbl_1_bss_10D8[1];
u32 lbl_1_bss_10D8_fill_10FC[19];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_1010;
    s = *(u8 *)&lbl_1_bss_1014;
    s = *(u8 *)&lbl_1_bss_1010_gap_1015;
    s = *(u8 *)&lbl_1_bss_1010_gap_1015_fill_1016;
    s = *(u8 *)&fzgx_obj_camera_state;
    s = *(u8 *)&lbl_1_bss_103C;
    s = *(u8 *)&lbl_1_bss_1040;
    s = *(u8 *)&lbl_1_bss_1044;
    s = *(u8 *)&fzgx_obj_camera_flag_0;
    s = *(u8 *)&fzgx_obj_camera_flag_1;
    s = *(u8 *)&lbl_1_bss_1010_gap_104A;
    s = *(u8 *)&lbl_1_bss_104C;
    s = *(u8 *)&lbl_1_bss_108C;
    s = *(u8 *)&lbl_1_bss_10C0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_10D8;
    s = *(u8 *)&lbl_1_bss_10D8_fill_10FC;
}
#pragma section code_type ".text"

void fn_1_C10C(u8 idx) {
    lbl_1_bss_1010_gap_1015 = 0;
    fzgx_obj_camera_state = fzgx_obj_lbl_1_bss_10D8[idx];
}
/* fzgx:end fn_1_C10C */

/* fzgx:begin fn_1_C178 */
typedef struct {
    u8 pad_0[0x4]; f32 unk_4; f32 unk_8; f32 unk_C; f32 unk_10; f32 unk_14; f32 unk_18; f32 unk_1C;
    s16 unk_20; u8 pad_22[0x6]; f32 unk_28; f32 unk_2C; f32 unk_30; f32 unk_34; f32 unk_38; f32 unk_3C; f32 unk_40;
    s16 unk_44; u8 pad_46[0x2A];
} Obj_1_bss_10D8;

void fn_1_C178(void *self) {
    OSReport((((char *)&lbl_1_data_406C)), lbl_1_bss_104C.unk_8, lbl_1_bss_104C.unk_C,
        (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_4, (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_8, (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_C,
        (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_10, (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_14, (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_18,
        (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_1C, (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_20);
    OSReport((((char *)&lbl_1_data_40C8)), (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_28, (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_2C,
        (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_30, (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_34, (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_38,
        (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_3C, (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_40, (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_44,
        self);
}
/* fzgx:end fn_1_C178 */

/* fzgx:begin camera_report_position */
// Reports the camera's current position values for debugging.
void camera_report_position(void) {
    OSReport((const char *)lbl_1_data_4128, lbl_1_bss_10D8.unk_10,
             lbl_1_bss_10D8.unk_14, lbl_1_bss_10D8.unk_18);
}
/* fzgx:end camera_report_position */

/* fzgx:begin fn_1_C268 */
#pragma opt_common_subs off
#pragma opt_strength_reduction off
void fn_1_C268(s32 arg) {
    if ((55.0) == lbl_1_bss_10D8.unk_1C) {
        OSReport((char *)lbl_1_data_4144, lbl_1_bss_10D8.unk_4,
                 lbl_1_bss_10D8.unk_8, lbl_1_bss_10D8.unk_C,
                 lbl_1_bss_10D8.unk_28, lbl_1_bss_10D8.unk_2C,
                 lbl_1_bss_10D8.unk_30, lbl_1_bss_10D8.unk_20, arg,
                 lbl_1_bss_10D8.unk_1C);
    } else {
        OSReport((char *)lbl_1_data_4198, lbl_1_bss_10D8.unk_4,
                 lbl_1_bss_10D8.unk_8, lbl_1_bss_10D8.unk_C,
                 lbl_1_bss_10D8.unk_28, lbl_1_bss_10D8.unk_2C,
                 lbl_1_bss_10D8.unk_30, lbl_1_bss_10D8.unk_20, arg,
                 lbl_1_bss_10D8.unk_1C);
    }
}
#pragma opt_strength_reduction reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_C268 */

/* fzgx:begin fn_1_C304 */
// Reports the camera parameters and caller-supplied value for debugging.
void fn_1_C304(s32 arg) {
    OSReport((const char *)lbl_1_data_4198,
             lbl_1_bss_10D8.unk_4, lbl_1_bss_10D8.unk_8,
             lbl_1_bss_10D8.unk_C, lbl_1_bss_10D8.unk_10,
             lbl_1_bss_10D8.unk_14, lbl_1_bss_10D8.unk_18,
             lbl_1_bss_10D8.unk_20, arg,
             lbl_1_bss_10D8.unk_1C);
}
/* fzgx:end fn_1_C304 */

/* fzgx:begin camera_snapshot */
// Copies the live camera state into its snapshot and resets the snapshot flag.
void camera_snapshot(void) {
    lbl_1_bss_1010.unk_8 = lbl_1_bss_1010.unk_C8;
    lbl_1_bss_1010.unk_C = lbl_1_bss_1010.unk_CC;
    lbl_1_bss_1010.unk_10 = lbl_1_bss_1010.unk_D0;
    lbl_1_bss_1010.unk_14 = lbl_1_bss_1010.unk_D4;
    lbl_1_bss_1010.unk_18 = lbl_1_bss_1010.unk_D8;
    lbl_1_bss_1010.unk_1C = lbl_1_bss_1010.unk_DC;
    lbl_1_bss_1010.unk_20 = lbl_1_bss_1010.unk_E0;
    lbl_1_bss_1010.unk_24 = lbl_1_bss_1010.unk_E4;
    lbl_1_bss_1010.unk_28 = lbl_1_bss_1010.unk_E8;
    lbl_1_bss_1010.unk_3C = 0;
}
/* fzgx:end camera_snapshot */

/* fzgx:begin fn_1_C3B8 pool noprologue */
#include "types.h"

typedef struct {
    f32 x, y, z;
} CamVec;

typedef struct {
    u32 unk_0;
    CamVec pos;
    CamVec at;
    f32 unk_1C;
    s16 unk_20;
} CamKey;

typedef struct {
    s32 counter;
    s32 state;
    s32 total;
    f32 rate;
    u8 pad_10[0x30];
} CamCtl;

typedef struct {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
} CamSway;

extern void lbl_8006D5A4(CamVec *a, CamVec *b, CamVec *out, f32 t);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_1010;
u8 lbl_1_bss_1014;
u8 lbl_1_bss_1010_gap_1015;
u16 lbl_1_bss_1010_gap_1015_fill_1016;
CamKey fzgx_obj_camera_state;
u32 lbl_1_bss_103C;
u32 lbl_1_bss_1040;
u32 lbl_1_bss_1044;
u8 fzgx_obj_camera_flag_0;
u8 fzgx_obj_camera_flag_1;
u16 lbl_1_bss_1010_gap_104A;
CamCtl lbl_1_bss_104C;
u32 lbl_1_bss_108C[13];
CamSway lbl_1_bss_10C0;
CamKey fzgx_obj_lbl_1_bss_10D8[2];
u32 lbl_1_bss_10D8_fill_1120[10];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_1010;
    s = *(u8 *)&lbl_1_bss_1014;
    s = *(u8 *)&lbl_1_bss_1010_gap_1015;
    s = *(u8 *)&lbl_1_bss_1010_gap_1015_fill_1016;
    s = *(u8 *)&fzgx_obj_camera_state;
    s = *(u8 *)&lbl_1_bss_103C;
    s = *(u8 *)&lbl_1_bss_1040;
    s = *(u8 *)&lbl_1_bss_1044;
    s = *(u8 *)&fzgx_obj_camera_flag_0;
    s = *(u8 *)&fzgx_obj_camera_flag_1;
    s = *(u8 *)&lbl_1_bss_1010_gap_104A;
    s = *(u8 *)&lbl_1_bss_104C;
    s = *(u8 *)&lbl_1_bss_108C;
    s = *(u8 *)&lbl_1_bss_10C0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_10D8;
    s = *(u8 *)&lbl_1_bss_10D8_fill_1120;
}
#pragma section code_type ".text"

void fn_1_C3B8(void) {
    CamKey from = fzgx_obj_lbl_1_bss_10D8[0];
    CamKey to = fzgx_obj_lbl_1_bss_10D8[1];
    f32 t;

    switch (lbl_1_bss_104C.state) {
    case 0:
        t = (f32)lbl_1_bss_104C.counter / (f32)lbl_1_bss_104C.total;
        lbl_8006D5A4(&from.pos, &to.pos, &fzgx_obj_camera_state.pos, t);
        lbl_8006D5A4(&from.at, &to.at, &fzgx_obj_camera_state.at, t);
        fzgx_obj_camera_state.unk_1C = from.unk_1C + (f32)(t * (to.unk_1C - from.unk_1C));
        fzgx_obj_camera_state.unk_20 = from.unk_20 + (s16)(t * (to.unk_20 - from.unk_20));
        if (lbl_1_bss_104C.counter >= lbl_1_bss_104C.total) {
            lbl_1_bss_1010_gap_1015 = 0;
        }
        break;
    case 3:
        lbl_1_bss_10C0.unk_8 -= 1.0f;
        if (lbl_1_bss_10C0.unk_8 < lbl_1_bss_10C0.unk_C / 2.0f) {
            lbl_1_bss_10C0.unk_10 -= lbl_1_bss_10C0.unk_14;
        } else {
            lbl_1_bss_10C0.unk_10 += lbl_1_bss_10C0.unk_14;
        }
        t = lbl_1_bss_10C0.unk_0 + lbl_1_bss_10C0.unk_10;
        lbl_1_bss_10C0.unk_0 = t;
        lbl_8006D5A4(&from.pos, &to.pos, &fzgx_obj_camera_state.pos, t);
        lbl_8006D5A4(&from.at, &to.at, &fzgx_obj_camera_state.at, t);
        fzgx_obj_camera_state.unk_1C = from.unk_1C + (f32)(t * (to.unk_1C - from.unk_1C));
        fzgx_obj_camera_state.unk_20 = from.unk_20 + (s16)(t * (to.unk_20 - from.unk_20));
        if (lbl_1_bss_104C.counter >= lbl_1_bss_104C.total) {
            lbl_1_bss_1010_gap_1015 = 0;
        }
        break;
    case 2:
        lbl_8006D5A4(&fzgx_obj_camera_state.pos, &to.pos, &fzgx_obj_camera_state.pos, lbl_1_bss_104C.rate);
        lbl_8006D5A4(&fzgx_obj_camera_state.at, &to.at, &fzgx_obj_camera_state.at, lbl_1_bss_104C.rate);
        fzgx_obj_camera_state.unk_1C += (f32)(lbl_1_bss_104C.rate * (to.unk_1C - fzgx_obj_camera_state.unk_1C));
        fzgx_obj_camera_state.unk_20 += (s32)(lbl_1_bss_104C.rate * (to.unk_20 - fzgx_obj_camera_state.unk_20));
        break;
    }
    lbl_1_bss_104C.counter++;
}
/* fzgx:end fn_1_C3B8 */

/* fzgx:begin camera_get_state_object */
// Returns the camera state object's base address.
CameraState* camera_get_state_object(void) {
    return &camera_state;
}
/* fzgx:end camera_get_state_object */

/* fzgx:begin camera_get_state_field_0x4 */
// Returns the address of the camera state field at offset 4.
u32* camera_get_state_field_0x4(void) {
    return &camera_state.unk_4;
}
/* fzgx:end camera_get_state_field_0x4 */

/* fzgx:begin camera_get_state_field_0x8 */
// Returns the address of the camera state field at offset 0x8.
u32* camera_get_state_field_0x8(void) {
    return &camera_state.unk_8;
}
/* fzgx:end camera_get_state_field_0x8 */

/* fzgx:begin camera_get_state_field_0xc */
// Returns a pointer to the camera object's field at offset 0xC.
u32* camera_get_state_field_0xc(void) {
    return &camera_state.unk_C;
}
/* fzgx:end camera_get_state_field_0xc */

/* fzgx:begin camera_get_state_field_0x10 */
// Returns a pointer to the camera object's state field.
u32* camera_get_state_field_0x10(void) {
    return &camera_state.unk_10;
}
/* fzgx:end camera_get_state_field_0x10 */

/* fzgx:begin camera_get_state_field_0x14 */
// Returns a pointer to the camera object's field at offset 0x14.
u32* camera_get_state_field_0x14(void) {
    return &camera_state.unk_14;
}
/* fzgx:end camera_get_state_field_0x14 */

/* fzgx:begin camera_get_state_field_0x18 */
// Returns a pointer to the camera object's state field at offset 0x18.
u32* camera_get_state_field_0x18(void) {
    return &camera_state.unk_18;
}
/* fzgx:end camera_get_state_field_0x18 */

/* fzgx:begin camera_get_state_storage */
// Returns the camera state storage used by the surrounding camera code.
u8* camera_get_state_storage(void) {
    return lbl_1_bss_103C;
}
/* fzgx:end camera_get_state_storage */

/* fzgx:begin camera_get_extended_state_storage */
// Returns the storage reserved for the camera's extended state.
u8* camera_get_extended_state_storage(void) {
    return lbl_1_bss_108C;
}
/* fzgx:end camera_get_extended_state_storage */

/* fzgx:begin camera_get_state_flag */
// Returns the current camera state flag.
u8 camera_get_state_flag(void) {
    return lbl_1_bss_1014;
}
/* fzgx:end camera_get_state_flag */

/* fzgx:begin camera_enable_flags */
// Enables the camera state flags.
void camera_enable_flags(void) {
    camera_flag_1 = 1;
    camera_flag_0 = 1;
}
/* fzgx:end camera_enable_flags */

/* fzgx:begin camera_disable_flags */
// Clears the camera state flags.
void camera_disable_flags(void) {
    camera_flag_1 = 0;
    camera_flag_0 = 0;
}
/* fzgx:end camera_disable_flags */

/* fzgx:begin camera_are_flags_enabled */
// Returns whether the camera state flag is set.
u8 camera_are_flags_enabled(void) {
    return camera_flag_1;
}
/* fzgx:end camera_are_flags_enabled */
