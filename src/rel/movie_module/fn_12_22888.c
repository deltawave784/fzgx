#include "types.h"

typedef struct MovieObject MovieObject;

typedef struct MovieVtable {
    char padding[0xc];
    void (*fn0c)(MovieObject *);
} MovieVtable;

struct MovieObject {
    MovieVtable *vtable;
};

typedef struct MovieHandle {
    u32 field0;
    MovieObject *obj;
} MovieHandle;

typedef struct MovieEntry {
    int state;
    char pad[0xc];
    MovieHandle h;
} MovieEntry;

void fn_12_22888(u8 *module) {
    MovieEntry *e;
    MovieHandle *handle;
    MovieObject *obj;

    e = (MovieEntry *)(module + 0x1140);
    handle = &e->h;
    if (e->state == 5) {
        obj = handle->obj;
        if (obj != 0) {
            obj->vtable->fn0c(obj);
            handle->obj = 0;
        }
    }
    e = (MovieEntry *)(module + 0x11b4);
    handle = &e->h;
    if (e->state == 5) {
        obj = handle->obj;
        if (obj != 0) {
            obj->vtable->fn0c(obj);
            handle->obj = 0;
        }
    }
    e = (MovieEntry *)(module + 0x1228);
    handle = &e->h;
    if (e->state == 5) {
        obj = handle->obj;
        if (obj != 0) {
            obj->vtable->fn0c(obj);
            handle->obj = 0;
        }
    }
}
