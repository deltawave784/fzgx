#include "types.h"

typedef struct {
    int state;
    int b;
    int c;
} Fn8005BFB4Entry;

typedef struct {
    int count;
    u32 unk04;
    int unk08;
    u32 unk0C;
    int unk10;
    Fn8005BFB4Entry entries[32];
} Fn8005BFB4State;

extern Fn8005BFB4State lbl_80192BD0;
extern void *memset(void *, int, u32);
extern u32 fn_8001E9BC(u32 *);
extern char lbl_800929AC[43];
extern void fn_8005A5BC(const char *);

void fn_8005BFB4(void) {
    u32 tmp;
    Fn8005BFB4Entry *e;
    int i;
    Fn8005BFB4State *s = (Fn8005BFB4State *)&lbl_80192BD0;
    if (--s->count == 0) {
        for (e = s->entries, i = 0; i < 32; e++, i++) {
            if (e->state == 1 && e != 0) {
                e->state = 0;
            }
        }
        memset(s->entries, 0, 0x180);
        if (s->unk04 == 0) {
            fn_8001E9BC(&tmp);
            if (tmp != s->unk0C) {
                fn_8005A5BC(lbl_800929AC);
            }
            s->unk08 = 0;
            s->unk0C = 0;
            s->unk10 = 0;
        }
    }
}
