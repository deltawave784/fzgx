#include "types.h"
#include "sofdec/mwsfd.h"

extern int fn_12_3A36C(void *);
extern char lbl_12_rodata_1280[46];
extern void MWSFSVM_Error(char *, ...);


void *fn_12_34084(MwsPlayer *module) {
    if (fn_12_3A36C(module) == 0) {
        MWSFSVM_Error(lbl_12_rodata_1280);
        return 0;
    }
    return module->field_54;
}
