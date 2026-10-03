#include "types.h"

struct Sig_fn_12_2269C_fn_12_2269C_Copy16 {
    u32 a[4];
};
extern void fn_12_2269C(u8 *, int, int, struct Sig_fn_12_2269C_fn_12_2269C_Copy16 *);

int fn_12_2F970(u8 *arg0) {
    struct { int value; } i;
    u32 *p;
    int v;
    p = (u32 *)(arg0 + 0x28d4);
    *(u32 **)(arg0 + 0x1cc8) = p;
    v = *(int *)(arg0 + 0x1cd0);
    *(u32 *)(arg0 + 0x28d4) = 0;
    for (i.value = 0; i.value < 3; i.value++) {
        struct Sig_fn_12_2269C_fn_12_2269C_Copy16 *q = (struct Sig_fn_12_2269C_fn_12_2269C_Copy16 *)(p + 1);
        q->a[0] = 0;
        q->a[1] = 0;
        q->a[2] = 0;
        q->a[3] = 0;
        fn_12_2269C(arg0, v, i.value, q);
        p += 4;
    }
    return 0;
}
