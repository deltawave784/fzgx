#include "types.h"

typedef void (*MovieCallback)(u32, s32);
typedef struct MovieObject {
    MovieCallback callback0;
    union {
        u32 callback_arg0;
        MovieCallback callback1;
    };
    u32 callback_arg1;
    s32 state;
} MovieObject;

extern u32 lbl_12_bss_4DB0;
extern MovieObject *lbl_12_bss_4DB8;

static inline s32 movie_invalid(MovieObject *movie) {
    lbl_12_bss_4DB0 = (u32)movie;
    if (movie == 0) return -1;
    if (*(s32 *)movie == 1) return -1;
    return 0;
}

s32 fn_12_6CA8(MovieObject *movie, MovieCallback callback, u32 arg) {
    if (movie == 0) {
        movie = lbl_12_bss_4DB8;
        movie->callback0 = callback;
        movie->callback_arg0 = arg;
    } else {
        if (movie_invalid(movie)) {
            movie = lbl_12_bss_4DB8;
            movie->callback_arg1 = 0xFF020101;
            if (movie->callback0 != 0) {
                movie->callback0(movie->callback_arg0, 0xFF020101);
            }
            return 0xFF020101;
        }
        movie->callback1 = callback;
        movie->callback_arg1 = arg;
    }
    return 0;
}
