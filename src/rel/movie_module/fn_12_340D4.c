#include "types.h"
#include "sofdec/mwsfd.h"


extern int fn_12_3A36C(MwsPlayer *, void *);
extern char lbl_12_rodata_12B0[46];
extern void MWSFSVM_Error(char *, ...);

void fn_12_340D4(MwsPlayer *self, void *value) {
    if (fn_12_3A36C(self, value) == 0) {
        MWSFSVM_Error(lbl_12_rodata_12B0);
    } else {
        self->field_54 = value;
    }
}
