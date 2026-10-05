#include "types.h"

extern f64 lbl_12_rodata_60[12];

typedef struct MovieState {
    int pad0;
    int value;
    int stride;
    u8 pad[0x2c];
    int field38;
} MovieState;

typedef struct MovieData {
    int mode;
    int x;
    int width;
    int height;
    int pad10;
    int y;
    int w;
    u8 pad1c[8];
    int z;
    int d;
    u8 pad2c[0x18];
    int field44;
    int field48;
    u8 pad4c[0x28];
    int field74;
} MovieData;

typedef struct MovieRect {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
} MovieRect;

typedef struct MovieArgs {
    int a;
    int b;
    int c;
    int d;
    int pad[2];
} MovieArgs;

extern void fn_12_309C(MovieState *, MovieData *, void *);
extern void fn_12_3D144(MovieRect *, MovieArgs *);
extern s32 fn_12_308C(void);
extern void fn_12_3DCF0(MovieRect *, MovieArgs *, int);
extern void fn_12_3DF08(MovieRect *, MovieArgs *);

#pragma opt_propagation off

void fn_12_1F84(MovieState *state, MovieData *data, int arg) {
    MovieRect src1;
    MovieArgs dst1;
    MovieArgs dst0;
    MovieRect src0;
    int flag;
    int done;
    int w;
    int half;

    src0.a = data->x;
    src0.b = data->y;
    src0.c = data->z;
    src0.d = data->width;
    src0.e = data->w;
    src0.f = data->d;
    dst0.a = arg;
    dst0.b = data->field44;

    switch (state->value) {
    case 0x11:
    case 0x31:
    case 0x41:
    case 0xf1:
    case 0x1001:
        flag = 0;
        break;
    case 0x21:
    case 0x101:
        flag = 1;
        break;
    default:
        fn_12_309C(NULL, NULL, (char *)lbl_12_rodata_60);
        flag = 0;
        break;
    }

    if (flag == 1) {
        dst0.c = data->field48 / 2;
    } else {
        dst0.c = data->field48;
    }
    if (state->stride == 0) {
        dst0.d = data->width * 4;
    } else {
        dst0.d = state->stride;
    }

    done = 0;
    if (data->field74 == 1) {
        if (done != 1) {
            fn_12_3D144(&src0, &dst0);
        }
    } else {
        if (done != 1) {
            fn_12_3D144(&src0, &dst0);
        }
    }

    w = data->width;
    half = (w * data->height) / 2;
    src1.a = data->x + half;
    src1.b = data->y + half / 2;
    src1.c = data->z + half / 2;
    src1.d = w;
    src1.e = data->w;
    src1.f = data->d;
    dst1.a = arg;
    dst1.b = data->field44;
    dst1.c = data->field48 / 2;
    if (state->stride == 0) {
        dst1.d = w * 4;
    } else {
        dst1.d = state->stride;
    }

    if (fn_12_308C() == 1) {
        fn_12_3DCF0(&src1, &dst1, state->field38);
    } else {
        fn_12_3DF08(&src1, &dst1);
    }
}
