#include "types.h"

typedef struct SjObj {
    struct SjVt *vt;
} SjObj;
struct SjVt {
    void *pad[5];
    void (*fn14)(SjObj *);
};

typedef struct MovieModule {
    u8 pad00[0x40];
    void *stream;
    u8 pad44[8];
    void *lsc;
    u8 pad50[0x20];
    s8 paused;
    u8 pad71[0xb7];
    SjObj *obj;
    s32 field12c;
} MovieModule;

static const char fzgx_pool_strings_lbl_12_rodata_12E0_0[44] = "E1122642: mwPlyLinkStm: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_2C[44] = "E99072101 mwPlyLinkStm: can't link stream";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_58[48] = "E1122637: mwPlyGetSlFname: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_88[40] = "E10821B : Invalid value of stm_no : %d";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_B0[48] = "E1122632: mwPlyStartAfsLp: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_E0[44] = "E1122636: mwPlyEntryAfs: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_10C[52] = "E008311 mwPlyEntryAfs: can't entry pid=%d fid=%d";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_140[44] = "E1122641: mwPlySetLpFlg: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_16C[52] = "E1122634: mwPlyStartSeamless: handle is invalid.";

extern int fn_12_3A36C(MovieModule *);
extern void MWSFSVM_Error(const char *, ...);
extern int fn_12_23280(void *);
extern void fn_12_3916C(MovieModule *, s32);
extern void fn_12_38DC8(MovieModule *);
extern void fn_12_3858C(MovieModule *);
extern void LSC_Start(void *);

void fn_12_349CC(MovieModule *self) {
    if (fn_12_3A36C(self) == 0) {
        MWSFSVM_Error(fzgx_pool_strings_lbl_12_rodata_12E0_16C);
        return;
    }
    if (fn_12_3A36C(self) == 0) {
        MWSFSVM_Error(fzgx_pool_strings_lbl_12_rodata_12E0_0);
    } else {
        int flag = self->paused;
        void *field = self->stream;
        if (flag == 0 && fn_12_23280(field) != 0) {
            MWSFSVM_Error(fzgx_pool_strings_lbl_12_rodata_12E0_2C);
        }
        self->paused = 1;
    }
    fn_12_3916C(self, self->field12c);
    fn_12_38DC8(self);
    LSC_Start(self->lsc);
    if (self->obj != 0) {
        self->obj->vt->fn14(self->obj);
    }
    fn_12_3858C(self);
}
