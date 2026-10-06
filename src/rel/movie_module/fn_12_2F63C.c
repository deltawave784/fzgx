#include "types.h"

struct Sig_fn_12_2F474_Movie;
struct Sig_fn_12_2F474_MovieConfig;
typedef struct Sig_fn_12_24A88_MovieObject Sig_fn_12_24A88_MovieObject;
extern int fn_12_2F474(struct Sig_fn_12_2F474_Movie *, struct Sig_fn_12_2F474_MovieConfig *);
extern s32 fn_12_24A88(Sig_fn_12_24A88_MovieObject *, s32);

typedef struct MovieEntry {
    s32 value0;
    s32 value4;
    s32 value8;
    u32 valueC;
    s32 value10;
    s32 value14;
    s32 value18;
    s32 value1C;
    s32 value20;
    u8 pad[0x20];
} MovieEntry;

s32 fn_12_2F63C(struct Sig_fn_12_2F474_Movie *movie, MovieEntry *entries, struct Sig_fn_12_2F474_MovieConfig **configPtr) {
    struct Sig_fn_12_2F474_MovieConfig *config = *configPtr;
    u32 *values = (u32 *)config;
    int i;
    for (i = 0; i < 9; i++) {
        u32 value;
        entries[i].value8 = 0;
        value = values[i];
        entries[i].value0 = entries[i].value4 = 0;
        entries[i].valueC = value;
        entries[i].value10 = 8;
        entries[i].value14 = 8;
        entries[i].value18 = 8;
        entries[i].value1C = 8;
        entries[i].value20 = -1;
    }
    if (fn_12_2F474(movie, config) != 0) {
        return fn_12_24A88((Sig_fn_12_24A88_MovieObject *)movie, 0xFF000302);
    }
    return 0;
}
