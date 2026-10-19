#include "types.h"
#include "dolphin/os/OSThread.h"

typedef struct ThreadConfig {
    u32 unk_0;
    u32 prio_4;
    u32 prio_8;
    u32 prio_C;
    u32 unk_10;
    u32 prio_14;
} ThreadConfig;

struct ThreadState {
    u32 unk_0;
    s32 count;
    u8 pad_8[0x1C];
    u32 unk_24;
    OSThread thread_28;
    OSThread thread_340;
    OSThread thread_658;
    OSThread thread_970;
    u32 unk_c88;
    u32 unk_c8c;
    u32 unk_c90;
    u32 unk_c94;
    u32 unk_c98;
    u32 unk_c9c;
    u32 unk_ca0;
    u32 unk_ca4;
    u32 unk_ca8;
    u32 unk_cac;
    u8 stack_cb0[0x2000];
    u8 stack_2cb0[0x2000];
    u8 stack_4cb0[0x2000];
    u8 stack_6cb0[0x1000];
};

typedef void *(*ThreadFunc)(void *);

extern u32 lbl_8009115C[];
extern ThreadConfig lbl_8012B918;

extern void fn_80058BFC(u32);
extern void fn_8004EB00(void);
extern void fn_80058EE4(void (*)(void), u32);
extern void fn_8004EA94(void);
extern void fn_80058ED4(void (*)(void), u32);
extern void fn_8004E9A8(void);
extern void fn_8004E8F8(void);
extern void fn_8004E8A0(void);
extern void fn_8004E7D4(void);
extern BOOL OSCreateThread(OSThread *, ThreadFunc, void *, void *, u32, OSPriority, u16);
extern u32 fn_800102AC(void);
extern long fn_80010CB0(OSThread *);
extern void fn_8004E9D8(void);
extern void fn_80059028(u32, void (*)(void), u32);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
__declspec(section ".data") u32 lbl_8017E980;
__declspec(section ".data") s32 lbl_8017E984;
__declspec(section ".data") u32 lbl_8017E984_fill_8017E988[7];
__declspec(section ".data") u32 lbl_8017E984_20;
__declspec(section ".data") OSThread lbl_8017E984_24;
__declspec(section ".data") OSThread lbl_8017E984_33C;
__declspec(section ".data") OSThread lbl_8017E984_654;
__declspec(section ".data") OSThread lbl_8017E984_96C;
__declspec(section ".data") u32 lbl_8017E984_fill_8017F608;
__declspec(section ".data") volatile u32 lbl_8017E984_C88; /* fzgx-allow: S2 shared thread state flag */
__declspec(section ".data") volatile u32 lbl_8017E984_C8C; /* fzgx-allow: S2 shared thread state flag */
__declspec(section ".data") volatile u32 lbl_8017E984_C90; /* fzgx-allow: S2 shared thread state flag */
__declspec(section ".data") volatile u32 lbl_8017E984_C94; /* fzgx-allow: S2 shared thread state flag */
__declspec(section ".data") volatile u32 lbl_8017E984_C98; /* fzgx-allow: S2 shared thread state flag */
__declspec(section ".data") volatile u32 lbl_8017E984_C9C; /* fzgx-allow: S2 shared thread state flag */
__declspec(section ".data") volatile u32 lbl_8017E984_CA0; /* fzgx-allow: S2 shared thread state flag */
__declspec(section ".data") volatile u32 lbl_8017E984_CA4; /* fzgx-allow: S2 shared thread state flag */
__declspec(section ".data") volatile u32 lbl_8017E984_CA8; /* fzgx-allow: S2 shared thread state flag */
__declspec(section ".data") u8 lbl_8017E984_CAC[0x2000];
__declspec(section ".data") u8 lbl_8017E984_2CAC[0x2000];
__declspec(section ".data") u8 lbl_8017E984_4CAC[0x2000];
__declspec(section ".data") u8 lbl_8017E984_6CAC[0x1000];
__declspec(section ".data") u32 lbl_80186630[4];
__declspec(section ".data") u32 lbl_80186640;
__declspec(section ".data") u32 lbl_80186644[8];
__declspec(section ".data") u32 lbl_80186664[64];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_8017E980;
    s = *(u8 *)&lbl_8017E984;
    s = *(u8 *)&lbl_8017E984_fill_8017E988;
    s = *(u8 *)&lbl_8017E984_20;
    s = *(u8 *)&lbl_8017E984_24;
    s = *(u8 *)&lbl_8017E984_33C;
    s = *(u8 *)&lbl_8017E984_654;
    s = *(u8 *)&lbl_8017E984_96C;
    s = *(u8 *)&lbl_8017E984_fill_8017F608;
    s = *(u8 *)&lbl_8017E984_C88;
    s = *(u8 *)&lbl_8017E984_C8C;
    s = *(u8 *)&lbl_8017E984_C90;
    s = *(u8 *)&lbl_8017E984_C94;
    s = *(u8 *)&lbl_8017E984_C98;
    s = *(u8 *)&lbl_8017E984_C9C;
    s = *(u8 *)&lbl_8017E984_CA0;
    s = *(u8 *)&lbl_8017E984_CA4;
    s = *(u8 *)&lbl_8017E984_CA8;
    s = *(u8 *)&lbl_8017E984_CAC;
    s = *(u8 *)&lbl_8017E984_2CAC;
    s = *(u8 *)&lbl_8017E984_4CAC;
    s = *(u8 *)&lbl_8017E984_6CAC;
    s = *(u8 *)&lbl_80186630;
    s = *(u8 *)&lbl_80186640;
    s = *(u8 *)&lbl_80186644;
    s = *(u8 *)&lbl_80186664;
}
#pragma section code_type ".text"

void fn_8004E59C(ThreadConfig *cfg) {
    
    u32 arg = lbl_8009115C[0];
    void * lab_t3_2;
    void * lab_t3;

    if (lbl_8017E984 == 0) {
        fn_80058BFC(arg);
        fn_80058EE4(fn_8004EB00, 0);
        fn_80058ED4(fn_8004EA94, 0);
        if (cfg == NULL) {
            lbl_8012B918.unk_10 = 16;
            lbl_8012B918.unk_0 = 1;
            lbl_8012B918.prio_4 = 8;
            lbl_8012B918.prio_8 = 12;
            lbl_8012B918.prio_C = 14;
            lbl_8012B918.prio_14 = 24;
        } else {
            lbl_8012B918 = *cfg;
        }
        OSCreateThread(&lbl_8017E984_96C, (ThreadFunc)fn_8004E9A8, NULL, (lab_t3 = lbl_8017E984_6CAC + sizeof(lbl_8017E984_6CAC)), sizeof(lbl_8017E984_6CAC), lbl_8012B918.prio_4, 1);
        lab_t3 = lbl_8017E984_4CAC + sizeof(lbl_8017E984_4CAC);
        OSCreateThread(&lbl_8017E984_33C, (ThreadFunc)fn_8004E8F8, NULL, lab_t3, sizeof(lbl_8017E984_4CAC), lbl_8012B918.prio_8, 1);
        lab_t3 = lbl_8017E984_2CAC + sizeof(lbl_8017E984_2CAC);
        OSCreateThread(&lbl_8017E984_654, (ThreadFunc)fn_8004E8A0, NULL, lab_t3, sizeof(lbl_8017E984_2CAC), lbl_8012B918.prio_C, 1);
        lab_t3_2 = lbl_8017E984_CAC + sizeof(lbl_8017E984_CAC);
        OSCreateThread(&lbl_8017E984_24, (ThreadFunc)fn_8004E7D4, NULL, lab_t3_2, sizeof(lbl_8017E984_CAC), lbl_8012B918.prio_14, 1);
        lbl_8017E984_20 = fn_800102AC();
        lbl_8017E984_CA8 = lbl_8017E984_C98 = lbl_8017E984_CA0 = lbl_8017E984_C90 = 1;
        lbl_8017E984_C8C = 0;
        lbl_8017E984_C9C = 0;
        lbl_8017E984_C94 = 0;
        lbl_8017E984_CA4 = 0;
        lbl_8017E984_C88 = 0;
        fn_80010CB0(&lbl_8017E984_33C);
        fn_80010CB0(&lbl_8017E984_654);
        fn_80010CB0(&lbl_8017E984_24);
        fn_80059028(6, fn_8004E9D8, 0);
    }
    lbl_8017E984++;
}

