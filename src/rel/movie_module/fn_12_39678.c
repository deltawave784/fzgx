#include "dolphin/types.h"

unsigned long strlen(const char *s);
char *strncpy(char *dst, const char *src, unsigned long n);

typedef struct Fn39678Hn {
    char pad0[0x8];
    s32 stat;           /* 0x08 */
    s32 unkC;           /* 0x0C */
    char pad10[0x30];
    void *sfd;          /* 0x40 */
    void *unk44;        /* 0x44 */
    char pad48[0x29];
    s8 unk71;           /* 0x71 */
    s8 pause;           /* 0x72 */
    char pad73[0x9];
    s32 unk7C;          /* 0x7C */
    s32 unk80;          /* 0x80 */
    s32 unk84;          /* 0x84 */
    char pad88[0x88];
    char *fname;        /* 0x110 */
    s32 fnameMax;       /* 0x114 */
    s32 unk118;         /* 0x118 */
    s32 unk11C;         /* 0x11C */
    s32 unk120;         /* 0x120 */
    s32 unk124;         /* 0x124 */
    s32 unk128;         /* 0x128 */
    s32 unk12C;         /* 0x12C */
    char pad130[0xBC];
    char sst[4];        /* 0x1EC */
} Fn39678Hn;


void fn_12_3A888(Fn39678Hn *hn);
s32 fn_12_2B358(void *sfd);
void fn_12_38A0C(s32 code);
void MWSFSVM_Error(const char *fmt, ...);
void fn_12_3B540(void *sst);
void fn_12_34EB0(void *p);
void fn_12_38DBC(void);
s32 MWSFCRE_ResetSfdHn(Fn39678Hn *hn);
void fn_12_3B2EC(Fn39678Hn *hn);
void fn_12_33A14(Fn39678Hn *hn);
void fn_12_353C4(Fn39678Hn *hn);
s32 fn_12_35418(Fn39678Hn *hn);
void fn_12_353FC(Fn39678Hn *hn);
s32 fn_12_2AD88(void *sfd);
s32 fn_12_3A36C(Fn39678Hn *hn);
s32 fn_12_38AD0(void);
s32 fn_12_2D74C(void *sfd, s32 id, s32 *val);
s32 fn_12_2AF5C(void *sfd, s32 sw);
void MWSST_Pause(void *sst, s32 sw);
void MWSST_StartSj(void *sst);
char *fn_80083DB0(char *dst, const char *src);
void fn_12_35014(Fn39678Hn *hn, s32 a, s32 b);
void fn_12_35010(Fn39678Hn *hn, s32 a, s32 b);


static const u32 fzgx_pool_rodata_lbl_12_rodata_2480[10] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45323131, 0x3135313A, 0x20414458, 0x465F4765, 0x74466E61, 0x6D655261, 0x6E676545, 0x78282920,
    0x6661696C, 0x642E0000
};
static const u32 fzgx_pool_rodata_lbl_12_rodata_2480_28[8] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45323131, 0x3132313A, 0x2066696C, 0x656E616D, 0x65206973, 0x206C6F6E, 0x6765722E, 0x0
};
static const u32 fzgx_pool_rodata_lbl_12_rodata_24C8[15] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3FE99999, 0x9999999A, 0x43300000, 0x80000000, 0x45313132, 0x32363338, 0x3A206D77, 0x506C7953,  /* fzgx-allow: A1 retail data bytes */
    0x74617274, 0x4166733A, 0x2068616E, 0x646C6520, 0x69732069, 0x6E76616C, 0x69642E00
};
static const u32 fzgx_pool_rodata_lbl_12_rodata_2480_84[10] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45313132, 0x32363034, 0x206D7753, 0x66645061, 0x7573653B, 0x2068616E, 0x646C6520, 0x69732069,
    0x6E76616C, 0x69642E00
};
static const u32 fzgx_pool_rodata_lbl_12_rodata_2480_AC[9] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45323030, 0x37206D77, 0x53666450, 0x61757365, 0x3B206361, 0x6E277420, 0x70617573, 0x65202825,
    0x73290000
};
static const u32 fzgx_pool_rodata_lbl_12_rodata_2480_D0[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F4E0000
};
static const u32 fzgx_pool_rodata_lbl_12_rodata_2480_D4[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F464600
};
static const u32 fzgx_pool_rodata_lbl_12_rodata_2558[10] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45313132, 0x32363032, 0x206D7753, 0x66645374, 0x6F703A20, 0x68616E64, 0x6C652069, 0x7320696E,
    0x76616C69, 0x642E0000
};
static const u32 fzgx_pool_rodata_lbl_12_rodata_2580[19] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45323030, 0x33206D77, 0x53666453, 0x746F703A, 0x63616E27, 0x74207374, 0x6F702053, 0x46440000,
    0x45313132, 0x32363039, 0x206D7753, 0x66645374, 0x61727453, 0x6A3A2068, 0x616E646C, 0x65206973,
    0x20696E76, 0x616C6964, 0x2E000000
};
static const u32 fzgx_pool_rodata_lbl_12_rodata_2480_14C[11] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45303230, 0x33323633, 0x3A206D77, 0x5F736664, 0x5F737461, 0x72745F65, 0x783A2052, 0x45534554,
    0x20666169, 0x6C65642E, 0x0
};
static const u32 fzgx_pool_rodata_lbl_12_rodata_2480_178[11] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45323031, 0x32313320, 0x6D775F73, 0x66645F73, 0x74617274, 0x5F65783A, 0x2063616E, 0x27742073,
    0x65742041, 0x6464496E, 0x66534A00
};
static const u32 fzgx_pool_rodata_lbl_12_rodata_2480_1A4[19] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45323030, 0x31303730, 0x3346206D, 0x77506C79, 0x53666453, 0x74616E64, 0x62793A20, 0x0,
    0x45313132, 0x32363130, 0x206D7753, 0x66645374, 0x6172744D, 0x656D3A20, 0x68616E64, 0x6C652069,
    0x7320696E, 0x76616C69, 0x642E0000
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_12_rodata_2480(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_rodata_lbl_12_rodata_2480;
    s = *(u8 *)fzgx_pool_rodata_lbl_12_rodata_2480_28;
    s = *(u8 *)fzgx_pool_rodata_lbl_12_rodata_24C8;
    s = *(u8 *)fzgx_pool_rodata_lbl_12_rodata_2480_84;
    s = *(u8 *)fzgx_pool_rodata_lbl_12_rodata_2480_AC;
    s = *(u8 *)fzgx_pool_rodata_lbl_12_rodata_2480_D0;
    s = *(u8 *)fzgx_pool_rodata_lbl_12_rodata_2480_D4;
    s = *(u8 *)fzgx_pool_rodata_lbl_12_rodata_2558;
    s = *(u8 *)fzgx_pool_rodata_lbl_12_rodata_2580;
    s = *(u8 *)fzgx_pool_rodata_lbl_12_rodata_2480_14C;
    s = *(u8 *)fzgx_pool_rodata_lbl_12_rodata_2480_178;
    s = *(u8 *)fzgx_pool_rodata_lbl_12_rodata_2480_1A4;
}
#pragma section code_type ".text"

void fn_12_39678(Fn39678Hn *hn, char *fname, s32 a2, s32 a3)
{
    
    void *sfd;
    s32 pause;
    s32 val;

    hn->unk128 = hn->unk12C;
    sfd = hn->sfd;
    if (sfd != NULL) {
        fn_12_3A888(hn);
        hn->stat = 0;
        if (fn_12_2B358(sfd) != 0) {
            fn_12_38A0C(-0x134);
            MWSFSVM_Error(((const char *)fzgx_pool_rodata_lbl_12_rodata_2580));
        }
        fn_12_3B540(hn->sst);
        if (hn->unk44 != NULL) {
            fn_12_34EB0(hn->unk44);
        }
    }
    fn_12_38DBC();
    if (hn->sfd != NULL) {
        if (MWSFCRE_ResetSfdHn(hn) != 0) {
            MWSFSVM_Error(((const char *)fzgx_pool_rodata_lbl_12_rodata_2480_14C));
            goto set_name; /* Keep the verified branch to set_name. */
        }
        fn_12_3B2EC(hn);
        fn_12_33A14(hn);
        fn_12_353C4(hn);
        if (fn_12_35418(hn) != 0) {
            MWSFSVM_Error(((const char *)fzgx_pool_rodata_lbl_12_rodata_2480_178));
            goto set_name; /* Keep the verified branch to set_name. */
        }
        fn_12_353FC(hn);
    }
    hn->unk7C = 0;
    hn->unk80 = 0;
    if (fn_12_2AD88(hn->sfd) != 0) {
        fn_12_38A0C(-0x137);
        MWSFSVM_Error(((const char *)fzgx_pool_rodata_lbl_12_rodata_2480_1A4));
    }
    pause = hn->pause;
    if (fn_12_3A36C(hn) == 0) {
        MWSFSVM_Error(((const char *)fzgx_pool_rodata_lbl_12_rodata_2480_84));
    } else {
        sfd = hn->sfd;
        if (hn->pause != 0 || pause != 0) {
            if (fn_12_38AD0() == 1 && hn->unkC == 1) {
                if (fn_12_2D74C(sfd, 6, &val) == 0) {
                    if (val == 1) {
                        fn_12_3A888(hn);
                    }
                } else {
                    fn_12_3A888(hn);
                }
            }
            if (fn_12_2AF5C(sfd, pause) != 0) {
                fn_12_38A0C(-0x136);
                MWSFSVM_Error(((const char *)fzgx_pool_rodata_lbl_12_rodata_2480_AC), (pause == 1) ? ((const char *)fzgx_pool_rodata_lbl_12_rodata_2480_D0) : ((const char *)fzgx_pool_rodata_lbl_12_rodata_2480_D4));
            }
            MWSST_Pause(hn->sst, pause);
            hn->pause = pause;
        }
    }
    MWSST_Pause(hn->sst, 1);
    MWSST_StartSj(hn->sst);
    hn->unk84 = 0;
    hn->unk71 = 0;
    hn->stat = 1;
set_name:
    if ((s32)strlen(fname) > hn->fnameMax) {
        MWSFSVM_Error(((const char *)fzgx_pool_rodata_lbl_12_rodata_2480_28));
        strncpy(hn->fname, fname, hn->fnameMax);
    } else {
        fn_80083DB0(hn->fname, fname);
    }
    hn->unk11C = 0;
    hn->unk120 = 0;
    hn->unk124 = 0xFFFFF;
    hn->unk118 = 1;
    fn_12_35014(hn, a2, a3);
    fn_12_35010(hn, a2, a3);
}
