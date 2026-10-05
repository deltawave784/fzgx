#include "types.h"
#include "sofdec/adxt.h"

typedef struct MovieModule {
    u8 pad_0000[0x48];
    s32 state;
    u8 pad_004c[0xf60 - 0x4c];
    u8 timer[0x1b74 - 0xf60];
    void *movie_data;
} MovieModule;

typedef struct MovieData {
    void *movie;
    u8 pad_0004[0x20];
    s32 position;
    s32 duration;
} MovieData;

typedef struct Int64Pair {
    s64 a;
    s64 b;
} Int64Pair;

extern u32 lbl_12_bss_6988;

extern s32 fn_12_2E44C(MovieModule *, s32 *, s32 *);
extern s32 fn_8004C658(void *);
extern void fn_8004C164(ADXTHandle *, s32 *, s32 *);
extern s64 fn_12_335B8(void);
extern s64 fn_12_335A4(void);
extern void fn_12_2FE60(void *, Int64Pair *, Int64Pair *, Int64Pair *);

s32 fn_12_205BC(MovieModule *arg0, s32 *out_pos, s32 *out_dur) {
    MovieData *movie_data = (MovieData *)arg0->movie_data;
    void *movie = movie_data->movie;
    void *timer = arg0->timer;
    Int64Pair out;
    Int64Pair in1;
    Int64Pair in0;
    s32 loc_c;
    s32 loc_8;
    s32 pos;
    s32 dur;

    if (fn_12_2E44C(arg0, out_pos, out_dur) == 0) {
        return 0;
    }

    if (arg0->state == 4) {
        lbl_12_bss_6988 = fn_8004C658(movie);
        fn_8004C164((ADXTHandle *)movie, &loc_8, &loc_c);
        in0.a = loc_8;
        in0.b = loc_c;
        in1.a = fn_12_335B8();
        in1.b = fn_12_335A4();
        fn_12_2FE60(timer, &in0, &in1, &out);
        pos = (s32)out.a;
        dur = (s32)out.b;
        if (movie_data->position < pos) {
            movie_data->position = pos;
            movie_data->duration = dur;
        }
    }

    *out_pos = movie_data->position;
    *out_dur = movie_data->duration;
    return 0;
}
