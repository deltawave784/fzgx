#include "types.h"

typedef struct fn_80075908_Obj {
    u32 flags;
    u8 pad_4[0xE];
    u8 unk_12;
} fn_80075908_Obj;

typedef struct fn_80075908_Params {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
} fn_80075908_Params;

typedef struct fn_80075908_State {
    s32 dirty0;
    s32 dirty1;
    s32 unk_8;
    s32 unk_C;
    s16 unk_10;
    s16 unk_12;
} fn_80075908_State;

typedef struct fn_80075908_Info {
    u32 id;
    fn_80075908_Obj *obj;
    u32 arg;
    fn_80075908_Params params;
} fn_80075908_Info;

typedef void (*fn_80075908_Callback)(fn_80075908_Info *);

typedef struct fn_80075908_Global {
    u8 unk_0;
    u8 unk_1;
    u8 pad_2[0x6];
    s32 unk_8;
    s32 unk_C;
    u8 pad_10[0x4];
    s32 unk_14;
    s32 unk_18;
} fn_80075908_Global;

extern fn_80075908_Global lbl_801A3220;
extern fn_80075908_Callback lbl_801A6D40;
extern s32 lbl_801A6D58;
extern s32 lbl_801A6D84;
extern s32 lbl_801A6D88;

extern void fn_800775EC(fn_80075908_Obj *);
extern void fn_80075080(fn_80075908_Obj *);
extern void fn_80072168(u32);
extern void fn_80077488(fn_80075908_Obj *, fn_80075908_State *);
extern void fn_80077384(fn_80075908_Obj *);
extern void fn_80077240(fn_80075908_Obj *, fn_80075908_Params *, fn_80075908_State *);
extern void fn_8007264C(u32, s32, s32, s32, u8);
extern s32 fn_80076CD4(fn_80075908_Obj *, fn_80075908_Params *, u32, fn_80075908_State *);
extern void fn_80074D88(fn_80075908_Obj *, fn_80075908_Params *, fn_80075908_State *);
extern void fn_80077654(s32);
extern void fn_80077714(s32);
extern void fn_80074788(u32);
extern void fn_80073678(u8);
extern void fn_80074660(u8);
extern void fn_80073898(u8);
extern void fn_80075C78(fn_80075908_Obj *);

void fn_80075908(fn_80075908_Obj *obj, u32 arg) {
    fn_80075908_Params params;
    fn_80075908_Info info;
    fn_80075908_State state;

    params.unk_0 = 0;
    params.unk_4 = 0;
    params.unk_8 = 30;
    params.unk_C = 0;
    params.unk_10 = 0;
    params.unk_14 = 64;
    params.unk_18 = 0;
    params.unk_1C = 1;
    params.unk_20 = 0;
    params.unk_C = 1;
    params.unk_8 = 45;
    params.unk_14 = 76;
    params.unk_18 = 4;

    fn_800775EC(obj);
    if ((obj->flags & 1) == 0) {
        fn_80075080(obj);
    }
    fn_80072168(((obj->flags >> 2) & 1) ^ 1);

    state.unk_8 = 10;
    state.unk_C = 5;
    state.unk_10 = 0;
    state.unk_12 = 0;
    state.dirty0 = 0;
    state.dirty1 = 0;
    if (obj->flags & 1) {
        fn_80077488(obj, &state);
    } else {
        fn_80077384(obj);
    }
    if (lbl_801A3220.unk_14 != state.unk_8) {
        state.dirty0 = 1;
        lbl_801A3220.unk_14 = state.unk_8;
    }
    if (lbl_801A3220.unk_18 != state.unk_C) {
        state.dirty1 = 1;
        lbl_801A3220.unk_18 = state.unk_C;
    }

    if ((obj->flags & 0x80) || lbl_801A6D58 != 0) {
        fn_80077240(obj, &params, &state);
    } else {
        fn_8007264C(0, 10, 0, 4, 0);
        if (fn_80076CD4(obj, &params, arg, &state) == 0) {
            fn_80077240(obj, &params, &state);
        }
    }
    if (obj->flags & 0x200) {
        fn_80074D88(obj, &params, &state);
    }

    if (lbl_801A6D40 != NULL) {
        info.id = lbl_801A3220.unk_0;
        info.obj = obj;
        info.arg = arg;
        info.params = params;
        lbl_801A6D40(&info);
        params = info.params;
    }

    if (lbl_801A6D88 != 0) {
        if (lbl_801A3220.unk_8 != params.unk_0) {
            lbl_801A3220.unk_8 = params.unk_0;
            fn_80077654(params.unk_0);
        }
        params.unk_0++;
    }
    if (lbl_801A6D84 != 0) {
        /* retail compares unk_C but writes unk_8 */
        if (lbl_801A3220.unk_C != params.unk_0) {
            lbl_801A3220.unk_8 = params.unk_0;
            fn_80077714(params.unk_0);
        }
        params.unk_0++;
    }

    fn_80074788(1);
    fn_80073678(params.unk_0);
    fn_80074660(params.unk_4);
    fn_80073898(params.unk_10);
    fn_80075C78(obj);

    lbl_801A3220.unk_0 = 0;
    if (obj->flags & 0x80) {
        lbl_801A3220.unk_1 = 0;
    } else {
        lbl_801A3220.unk_1 = obj->unk_12;
    }
}
