#include "types.h"

struct Sig_fn_12_22668_fn_12_22668_Copy16 {
    u32 a[4];
};

typedef struct StreamBuf {
    u8 *ptr;
    s32 size;
} StreamBuf;

typedef struct Stream Stream;

typedef struct StreamVtbl {
    u8 pad0[0x18];
    void (*lock)(Stream *, s32, s32, StreamBuf *);
    u8 pad1[0x4];
    void (*unlock)(Stream *, s32, StreamBuf *);
    s32 (*avail)(Stream *, s32);
} StreamVtbl;

struct Stream {
    StreamVtbl *vt;
};

typedef void (*StreamCallback)(void *, s32);

extern s32 fn_12_247BC(u8 *, s32, u8 *, s32, s32 *);
extern void fn_12_22668(u8 *, int, int, struct Sig_fn_12_22668_fn_12_22668_Copy16 *);
extern void *fn_12_57F0(void *, const void *, u32);
extern u32 lbl_12_bss_7E88;

s32 fn_12_25748(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3) {
    struct Sig_fn_12_22668_fn_12_22668_Copy16 q1;
    u8 *src;
    struct Sig_fn_12_22668_fn_12_22668_Copy16 q2;
    StreamCallback cb2a;
    void *ctx1;
    StreamCallback cb2b;
    StreamCallback cb1b;
    void *ctx2;
    StreamCallback cb1a;
    StreamBuf b1a;
    s32 flag;
    s32 len;
    s32 ok;
    u8 *src2;
    Stream *obj2;
    Stream *obj1;
    StreamBuf b1b;
    StreamBuf b2a;
    StreamBuf b2b;
    s32 ok1;

    if (fn_12_247BC(arg0, arg1, arg2, arg3, &flag) != 0) {
        if (flag != 0 && *(s32 *)(arg0 + 0x1B00) != 8) {
            fn_12_22668(arg0, *(s32 *)(arg0 + 0x1B00), 0, &q1);
            obj1 = (Stream *)q1.a[0];
            cb1a = (StreamCallback)q1.a[1];
            cb1b = (StreamCallback)q1.a[2];
            ctx1 = (void *)q1.a[3];
            if (obj1 != 0) {
                // The 18-byte header precedes the payload.
                len = arg3 + 18;
                src = arg2 - 18;
                if (obj1->vt->avail(obj1, 0) < arg3 + 18) {
                    ok1 = 0;
                } else {
                    obj1->vt->lock(obj1, 0, arg3 + 18, &b1a);
                    fn_12_57F0(b1a.ptr, src, b1a.size);
                    obj1->vt->unlock(obj1, 1, &b1a);
                    if (b1a.size == 0) {
                        ok1 = 0;
                    } else {
                        len -= b1a.size;
                        src += b1a.size;
                        if (len > 0) {
                            obj1->vt->lock(obj1, 0, len, &b1b);
                            fn_12_57F0(b1b.ptr, src, b1b.size);
                            obj1->vt->unlock(obj1, 1, &b1b);
                            if (b1b.size != len) {
                                lbl_12_bss_7E88++;
                            }
                        }
                        ok1 = 1;
                    }
                }
                if (ok1 == 1) {
                    if (cb1a != 0) {
                        cb1a(arg0, 0);
                    }
                    if (cb1b != 0) {
                        cb1b(ctx1, 0);
                    }
                }
            }
        }
        return 1;
    }

    if (*(s32 *)(arg0 + 0x1B00) == 8) {
        ok = 1;
    } else {
        fn_12_22668(arg0, *(s32 *)(arg0 + 0x1B00), arg1, &q2);
        obj2 = (Stream *)q2.a[0];
        cb2a = (StreamCallback)q2.a[1];
        cb2b = (StreamCallback)q2.a[2];
        ctx2 = (void *)q2.a[3];
        if (obj2 == 0) {
            ok = 1;
        } else {
            if (obj2->vt->avail(obj2, 0) < arg3) {
                ok = 0;
            } else {
                src2 = arg2;
                obj2->vt->lock(obj2, 0, arg3, &b2a);
                fn_12_57F0(b2a.ptr, arg2, b2a.size);
                obj2->vt->unlock(obj2, 1, &b2a);
                if (b2a.size == 0) {
                    ok = 0;
                } else {
                    arg3 -= b2a.size;
                    src2 += b2a.size;
                    if (arg3 > 0) {
                        obj2->vt->lock(obj2, 0, arg3, &b2b);
                        fn_12_57F0(b2b.ptr, src2, b2b.size);
                        obj2->vt->unlock(obj2, 1, &b2b);
                        if (b2b.size != arg3) {
                            lbl_12_bss_7E88++;
                        }
                    }
                    ok = 1;
                }
            }
            if (ok == 1) {
                if (cb2a != 0) {
                    cb2a(arg0, arg1);
                }
                if (cb2b != 0) {
                    cb2b(ctx2, arg1);
                }
            }
        }
    }
    return ok;
}
