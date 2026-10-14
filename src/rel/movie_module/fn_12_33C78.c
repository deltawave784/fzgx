#include "types.h"

typedef struct SfdEntry {
    u8 pad_0[0x38];
    u32 *data;
    s32 w[7]; /* 0x3c */
} SfdEntry;

typedef struct SfdHandle {
    u8 pad_0[0x1c];
    s32 count;
    u8 pad_20[0x20];
    void *stream;
    u8 pad_44[0x10];
    s32 unk_54;
    u8 pad_58[0x20];
    SfdEntry *cur;
    s32 frames;
    u8 pad_80[4];
    s32 skipped;
    s32 w[7]; /* 0x88 */
    s32 unk_a4;
    u8 pad_a8[0xc];
    s32 hdr_done;
    s32 hdr_flag;
    u8 pad_bc[0x1c];
    u8 *ud_buf;
    s32 ud_size;
    u8 *ud_ptr;
    s32 ud_len;
    u8 pad_e8[0x14];
    s32 last_time;
} SfdHandle;

typedef struct SfdInfo {
    s32 valid;
    u8 pad_4[0x28];
    s32 time;
    u8 pad_30[0x18];
    s32 state;
} SfdInfo;

extern char lbl_12_rodata_1118[49];
extern int fn_12_3A36C(void *);
extern void MWSFSVM_Error(const char *, ...);
extern void *fn_12_3A7D8(void *);
extern void fn_12_2B25C(void *, SfdEntry **);
extern int fn_12_2A508(void *);
extern void fn_12_2B1E8(void *, SfdEntry *);
extern s32 fn_12_2D470(void *, void **, u32 *);
extern void *fn_12_3310C(void *, u32);
extern int fn_12_32EAC(void *, s32 *);
extern int fn_12_32DBC(void *, s32, s32 *);
extern int fn_12_31528(void *, s32, s32 *);
extern void fn_12_35670(SfdHandle *, s32);
extern u32 fn_12_330E0(void *);
extern void fn_12_33A44(SfdHandle *, SfdEntry *, SfdInfo *);
extern int fn_12_38AE0(void);
extern void fn_12_4D4(u32, s32, u8 **, s32 *);
extern void fn_12_35060(SfdHandle *, u8 *, s32);
extern void fn_12_3530C(SfdHandle *);
extern int fn_12_3503C(SfdHandle *);
extern void fn_12_3564C(SfdHandle *, s32);
extern int fn_12_35018(SfdHandle *);
extern void *memset(void *, int, u32);
extern void *memcpy(void *, const void *, u32);

#pragma opt_propagation off
void fn_12_33C78(SfdHandle *handle, SfdInfo *arg1) {
    struct { char *value; } str;
    SfdHandle *self = handle;
    SfdInfo *info = arg1;
    void *hdr;
    s32 b;
    u32 a;
    s32 state;
    void *sj;
    s32 i;
    s32 n;
    s32 ok;
    SfdEntry *p;
    SfdEntry *e;
    void *buf;
    u32 size;
    s32 udlen;
    u8 *ud;
    s32 res;
    s32 len;
    s32 ver;

    str.value = lbl_12_rodata_1118;
    if (fn_12_3A36C(self) == 0) {
        MWSFSVM_Error(str.value + 0x138);
        info->valid = 0;
        return;
    }
    sj = fn_12_3A7D8(self);
    fn_12_2B25C(sj, &e);
    if (e != NULL && self->unk_54 == 0) {
        n = self->count;
        for (i = 0; i < n; i++) {
            if (fn_12_3A36C(self) == 0) {
                MWSFSVM_Error(str.value + 0x34);
                ok = 0;
            } else {
                ok = fn_12_2A508(fn_12_3A7D8(self));
            }
            if (ok != 1) {
                break;
            }
            fn_12_2B1E8(sj, e);
            self->skipped++;
            fn_12_2B25C(sj, &e);
        }
    }
    if (e != NULL) {
        if (self->hdr_done != 1) {
            self->hdr_flag = 0;
            self->hdr_done = 1;
            if (fn_12_2D470(self->stream, &buf, &size) == 0 && size >= 0x800 && buf != NULL) {
                hdr = fn_12_3310C(buf, size);
                if (hdr != NULL) {
                    if (fn_12_32EAC(hdr, &ver) != 0 && ver != 0 &&
                        fn_12_32DBC(hdr, 0xe0, &len) != 0 && len != 0 &&
                        fn_12_31528(hdr, 0xe0, &res) != 0) {
                        if (res == 3) {
                            self->hdr_flag = 1;
                            fn_12_35670(self, 1);
                        } else {
                            fn_12_35670(self, 0);
                        }
                    }
                    fn_12_330E0(hdr);
                }
            }
        }
        self->frames++;
        self->cur = e;
        p = e;
        self->w[0] = p->w[0];
        self->w[1] = p->w[1];
        self->w[2] = p->w[2];
        self->w[3] = p->w[3];
        self->w[4] = p->w[4];
        self->w[5] = p->w[5];
        self->w[6] = p->w[6];
        self->unk_a4 = 0;
        fn_12_33A44(self, e, info);
        a = e->data[0];
        b = e->data[1];
        if (fn_12_38AE0() == 1 && self->ud_buf != NULL) {
            if (a != 0 && b > 4) {
                fn_12_4D4(a + 4, b - 4, &ud, &udlen);
            } else {
                ud = NULL;
                udlen = 0;
            }
            if (ud != NULL && udlen > 0) {
                if (udlen > self->ud_size) {
                    udlen = self->ud_size;
                }
                memset(self->ud_buf, 0, self->ud_size);
                memcpy(self->ud_buf, ud, udlen);
                self->ud_ptr = self->ud_buf;
                self->ud_len = udlen;
            } else {
                self->ud_ptr = NULL;
                self->ud_len = 0;
            }
            fn_12_35060(self, self->ud_ptr, self->ud_len);
        }
        if (self->last_time < info->time) {
            fn_12_3530C(self);
        }
        self->last_time = info->time;
        /* (ud_ptr != NULL) is materialized as a flag before the test */
        ok = (self->ud_ptr != NULL);
        if (ok == 1) {
            if (fn_12_3503C(self) == 1) {
                fn_12_3564C(self, 1);
            } else {
                fn_12_3564C(self, 0);
            }
        }
        state = 0;
        switch (e->w[0]) {
        case 3:
            if (e->w[2] == 0) {
                state = 2;
            }
            break;
        case 1:
        case 2:
            state = 2;
            break;
        case 0:
        default:
            MWSFSVM_Error(str.value + 0xbc);
            break;
        }
        if (fn_12_38AE0() == 1 && fn_12_35018(self) == 1) {
            state = 2;
        }
        info->state = state;
    } else {
        info->valid = 0;
    }
}
