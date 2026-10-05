#include "types.h"

typedef struct MovieHandle {
    u8 pad_0000[0xc];
    void *field_000c;
} MovieHandle;

typedef struct MovieData {
    void *movie;
    void *movie_controller;
    u32 field_0008;
    u32 field_000c;
    u32 field_0010;
    u32 field_0014;
    u32 field_0018;
    u32 field_001c;
    u32 field_0020;
    u32 field_0024;
    u32 field_0028;
    s32 paused;
} MovieData;

typedef struct MovieVtable {
    void *field_0000;
    void (*field_0004)(void *);
    void (*field_0008)(void *);
    void (*field_000c)(void *);
    void (*field_0010)(void *);
    void (*field_0014)(void *, int);
} MovieVtable;

typedef struct MovieModule {
    u8 pad_0000[0xf60];
    u8 field_0f60[0xc14];
    MovieData *movie_data;
    u8 pad_1b78[0x10c];
    MovieVtable *vtable_ptr;
    u8 pad_1c88[0xb84];
    MovieData data;
    u8 pad_283c[0x7c];
    MovieVtable vtable;
} MovieModule;

extern int fn_12_2D73C(void *, int);
extern int fn_12_206B8(MovieModule *, MovieData *);
extern int fn_12_2B348(void);
extern u32 lbl_12_bss_7C64[137];
extern s32 fn_12_24A88(MovieModule *, s32);
extern void fn_12_215CC(void *);
extern void fn_12_215A4(void *);
extern void fn_12_2157C(void *);
extern void fn_12_21554(void *);
extern void fn_12_214B0(void *, int);
extern void fn_12_309B8(void *, int);
extern void fn_12_205BC(void);
extern void fn_12_2E41C(MovieModule *, void (*)(void), s32);
extern void fn_12_2D7DC(MovieModule *, int, int);
extern void *fn_8004CD70(u32, u32, u32);
extern void fn_8004BE90(void *, u32);
extern void fn_8004ED18(void *, u32);
extern void *fn_80058498(u32, u32, u32);
extern void fn_8004C794(void *, void *);
extern void ADXT_Pause(void *, s32);

static inline u32 fn_12_208C4_array_read(u32 *array, s32 index) { return array[index]; }
#pragma opt_propagation off
int fn_12_208C4(MovieModule *mod) {
    /* the constant-offset pointer is wrapped so it stays a real variable (r30) */
    struct {
        MovieData *value;
    } data;
    MovieHandle *movie;
    void *controller;
    int result;
    MovieVtable *vt;
    void *adx;

    if (fn_12_2D73C(mod, 6) == 0) {
        return 0;
    }

    data.value = &mod->data;
    mod->movie_data = data.value;
    result = fn_12_206B8(mod, data.value);
    if (result != 0) {
        return result;
    }

    if (fn_12_2B348() != 1) {
        movie = fn_8004CD70(data.value->field_0014, data.value->field_0020, data.value->field_001c);
    } else {
        movie = (MovieHandle *)fn_12_208C4_array_read(lbl_12_bss_7C64, 128);
    }
    if (movie == 0) {
        movie = 0;
    } else {
        fn_8004BE90(movie, 0);
        fn_8004ED18(movie, 1);
    }
    if (movie == 0) {
        return fn_12_24A88(mod, 0xff000c04);
    }

    controller = fn_80058498(data.value->field_0010, data.value->field_0008, data.value->field_000c);
    if (controller == 0) {
        return fn_12_24A88(mod, 0xff000c05);
    }

    data.value->movie = movie;
    data.value->movie_controller = controller;
    vt = &mod->vtable;
    mod->vtable_ptr = vt;
    vt->field_0000 = movie->field_000c;
    vt->field_0004 = fn_12_215CC;
    vt->field_0008 = fn_12_215A4;
    vt->field_000c = fn_12_2157C;
    vt->field_0010 = fn_12_21554;
    vt->field_0014 = fn_12_214B0;
    fn_8004C794(movie, controller);

    adx = mod->movie_data->movie;
    mod->movie_data->paused = 1;
    ADXT_Pause(adx, 1);
    fn_12_309B8(mod->field_0f60, 1);
    fn_12_2E41C(mod, fn_12_205BC, 2);
    fn_12_2D7DC(mod, 15, 2);
    return 0;
}
#pragma opt_propagation reset

