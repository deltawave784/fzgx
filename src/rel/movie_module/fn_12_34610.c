#include "types.h"
#include "sofdec/mwsfd.h"


extern void fn_80056BE0(void *movie);

void fn_12_34610(MwsPlayer *module) {
    fn_80056BE0(module->lsc);
}
