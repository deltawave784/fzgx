#include "types.h"

typedef struct MovieObject MovieObject;

typedef struct MovieRange {
    int start;
    int end;
} MovieRange;

typedef struct MovieVtable {
    char padding0[0x18];
    void (*query)(MovieObject *, int, int, MovieRange *);
    void (*release)(MovieObject *, int, MovieRange *);
    char padding1[4];
    int (*position)(MovieObject *, int);
} MovieVtable;

struct MovieObject {
    MovieVtable *vtable;
};

typedef struct MovieModule {
    char padding0[0x1144];
    int active;
    char padding1[0xc];
    MovieObject *object;
} MovieModule;

extern void fn_12_24970(void *movie);
extern void fn_12_24950(void *movie);

static inline int MovieReadRange(MovieModule *module, int index, int extra) {
    char movie[4];
    MovieRange head;
    MovieRange tail;
    MovieObject *object;
    struct { int value; } position;
    MovieModule *entry;

    position.value = extra;
    entry = (MovieModule *)((char *)module + index * 0x74);
    object = entry->object;
    if (entry->active != 0 && object != NULL) {
        fn_12_24970(movie);
        position.value = object->vtable->position(object, 1);
        object->vtable->query(object, 1, 0x7fffffff, &head);
        if (head.end < position.value) {
            object->vtable->query(object, 1, 0x7fffffff, &tail);
            object->vtable->release(object, 1, &tail);
        } else {
            tail.start = 0;
            tail.end = 0;
        }
        object->vtable->release(object, 1, &head);
        extra = head.end;
        position.value = tail.end;
        fn_12_24950(movie);
    }
    return extra + position.value;
}

int fn_12_21C00(MovieModule *module, int index) {
    int position = 0;
    return MovieReadRange(module, index, position);
}
