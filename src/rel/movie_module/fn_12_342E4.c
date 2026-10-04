#include "types.h"
#include "sofdec/mwsfd.h"


extern int fn_12_3A36C(void);
extern char lbl_12_rodata_1338[46];
extern void MWSFSVM_Error(const char* format, ...);
extern u8 lbl_12_rodata_1368[88];
extern int fn_80056BE0(void* movies);
extern void* fn_80056B50(void* movies, int index);
extern int fn_80056A50(void* movies, void* movie);

int fn_12_342E4(MwsPlayer* module, int index) {
    if (!fn_12_3A36C()) {
        MWSFSVM_Error(lbl_12_rodata_1338);
        return 0;
    }

    if (index >= fn_80056BE0(module->lsc)) {
        return 0;
    }

    if (index < 0) {
        MWSFSVM_Error((const char*)lbl_12_rodata_1368, index);
        return 0;
    }

    return fn_80056A50(module->lsc, fn_80056B50(module->lsc, index));
}
