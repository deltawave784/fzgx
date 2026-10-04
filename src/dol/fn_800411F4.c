
#include "types.h"
#include "sofdec/adxt.h"

typedef int (*SVMServerFunction)(void *object);

typedef void (*AdxErrorCallback)(void *object, const char *message);

struct adx_inisBss {
    union {
        unsigned char padding_extent[3096];
        struct {
            int adxt_init_cnt;
        } view_sdk_adxt_init_cnt;
        struct {
            unsigned char padding_sdk_adxt_svr_main_id[8];
            int adxt_svr_main_id;
        } view_sdk_adxt_svr_main_id;
        struct {
            unsigned char padding_sdk_adxt_svr_fs_id[12];
            int adxt_svr_fs_id;
        } view_sdk_adxt_svr_fs_id;
        struct {
            unsigned char padding_sdk_adxt_vsync_cnt[16];
            int adxt_vsync_cnt;
        } view_sdk_adxt_vsync_cnt;
        struct {
            unsigned char padding_sdk_cri_verstr_ptr[20];
            const char *cri_verstr_ptr;
        } view_sdk_cri_verstr_ptr;
        struct {
            unsigned char padding_sdk_adxt_obj[20];
            ADXTHandle adxt_obj[16];
        } view_sdk_adxt_obj;
    } fields;
};
extern struct adx_inisBss lbl_80178CA8;

void fn_800411F4(void);

void fn_80058680(void);

void fn_80058BFC(void);

int fn_80059428(int server_type, SVMServerFunction function, void *object);

void fn_8005912C(int server_type, int id, SVMServerFunction function, void *object);

void *memset(void *destination, int value, unsigned long size);

extern void fn_80046738(void);

extern void fn_80046718(void);

extern void fn_80046758(void);

extern void fn_80058754(void);

extern void fn_80058680(void);

extern void fn_80057D0C(void);

extern void fn_800475C0(void);

extern void fn_8004B7A0(void);

extern void fn_800424E8(void);

extern void fn_8004F74C(void);

extern void fn_8004EF88(void);

extern void fn_8005741C(void);

extern void fn_8004EF48(AdxErrorCallback callback, void *object);

extern void fn_800566BC(AdxErrorCallback callback, void *object);

extern int fn_8004E580(void);

extern void ADXT_SetDefSvrFreq(int frequency);

extern int lbl_8012B6E8;

extern const f64 lbl_80090010;

int fn_80041330(void *object);

int fn_80041354(void *object);

int fn_80041378(void *object);

int fn_800413A4(void *object);

void fn_800413C8(void *object, const char *message);

void fn_800413EC(void *object, const char *message);

void fn_800411F4(void) {
    struct adx_inisBss *bss = &lbl_80178CA8;

    *(volatile u32 *)&lbl_80090010; /* The SDK probes the pooled version word. */
    if ((bss->fields.view_sdk_adxt_init_cnt.adxt_init_cnt) == 0) {
        fn_80046758();
        fn_80046738();
        fn_80058754();
        fn_80058680();
        fn_80057D0C();
        fn_800475C0();
        fn_8004B7A0();
        fn_800424E8();
        fn_8004F74C();
        fn_8004EF88();
        fn_8005741C();
        fn_80058BFC();
        fn_8004EF48(fn_800413EC, 0);
        fn_800566BC(fn_800413C8, 0);
        memset((bss->fields.view_sdk_adxt_obj.adxt_obj), 0,
               sizeof((bss->fields.view_sdk_adxt_obj.adxt_obj)));
        if (fn_8004E580() == 1 && lbl_8012B6E8 == 1) {
            fn_8005912C(2, 1, fn_80041354, 0);
            (bss->fields.view_sdk_adxt_svr_fs_id.adxt_svr_fs_id) = fn_80059428(4, fn_80041330, 0);
            (bss->fields.view_sdk_adxt_svr_main_id.adxt_svr_main_id) =
                fn_80059428(5, fn_800413A4, 0);
        } else {
            (bss->fields.view_sdk_adxt_svr_main_id.adxt_svr_main_id) =
                fn_80059428(5, fn_80041378, 0);
        }
        (bss->fields.view_sdk_adxt_vsync_cnt.adxt_vsync_cnt) = 0;

        fn_80046718();
    }
    (bss->fields.view_sdk_adxt_init_cnt.adxt_init_cnt)++;
}
