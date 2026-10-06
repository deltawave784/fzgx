#include "types.h"
typedef struct Sig_fn_12_48C4_MovieEntry {
    s32 active;
    u8 unk04[0x38];
    f32 unk3c;
    f32 unk40;
} Sig_fn_12_48C4_MovieEntry;
typedef struct Sig_fn_12_354C_MovieModuleObject { u32 field_0; } Sig_fn_12_354C_MovieModuleObject;
extern u32 lbl_12_bss_10[300];
extern u8 lbl_12_rodata_448[160];
extern Sig_fn_12_48C4_MovieEntry *fn_12_48C4(void);
extern void *fn_12_3570(void *);
extern void fn_12_48A0(void *);
extern void fn_12_354C(void *);
extern void *memset(void *, int, u32);
typedef void (*fn_12_3148_Fn0)(u32, u8 *);
typedef struct MovieModule {
    u32 active;
    u32 field04, field08, field0c;
    u8 pad10[0x10];
    void *field20;
    u32 field24, field28;
    void *field2c;
    u32 field30, field34;
    /* Volatile preserves the retail reload after each buffer-offset store. */
    volatile u32 field38, field3c, field40, field44;
    u8 pad48[8];
    u32 field50;
    s32 field54;
    u8 pad58[8];
    s32 field60;
    u8 pad64[0x2c];
} MovieModule;
static inline void report(u8 *message) {
    fn_12_3148_Fn0 cb = (fn_12_3148_Fn0)lbl_12_bss_10[2];
    u32 count = lbl_12_bss_10[4];
    u32 val = lbl_12_bss_10[3];
    lbl_12_bss_10[4] = count + 1;
    if (cb) cb(val, message);
}
static inline void cleanup(MovieModule *v1) {
    if (v1) {
        void *v2 = v1->field20;
        void *v7 = v1->field2c;
        v1->active = 0;
        fn_12_48A0(v2);
        fn_12_354C(v7);
        lbl_12_bss_10[0]--;
    }
}
static inline s32 validSize(s32 size) {
    return size >= 0x301f;
}
static inline MovieModule *findFree(void) {
    MovieModule *entry = (MovieModule *)((u8 *)lbl_12_bss_10 + 24);
    s32 count;
    for (count = (s32)lbl_12_bss_10[1]; count > 0; count--) {
        if ((s32)entry->active == 0) return entry;
        entry++;
    }
    return 0;
}
MovieModule *fn_12_3148(u32 arg0, s32 arg1) {
    u8 *p_lbl_12_rodata_448 = lbl_12_rodata_448;
    MovieModule *v1;
    s32 v0;
    void *v2;
    v1 = findFree();
    if (!v1) return v1;
    if (validSize(arg1) != 1) {
        report(p_lbl_12_rodata_448 + 52);
        return 0;
    }
    memset(v1, 0, 144);
    v1->field04 = 0;
    v1->field08 = 0;
    v1->field0c = 0;
    v1->field24 = 1;
    v1->field28 = 0;
    v1->field34 = 0;
    v1->field38 = (arg0 + 31) & ~31;
    v1->field3c = v1->field38 + 1024;
    v1->field40 = v1->field3c + 1024;
    v1->field44 = v1->field40 + 1024;
    v1->field50 = arg0;
    v1->field54 = arg1;
    v1->field60 = -1;
    v1->active = 1;
    v2 = fn_12_48C4();
    if (!v2) {
        report(p_lbl_12_rodata_448 + 96);
        cleanup(v1);
        return 0;
    }
    v1->field20 = v2;
    v2 = fn_12_3570(v2);
    if (!v2) {
        report(p_lbl_12_rodata_448 + 128);
        cleanup(v1);
        return 0;
    }
    v1->field2c = v2;
    lbl_12_bss_10[0]++;
    return v1;
}
