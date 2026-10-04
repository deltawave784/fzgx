
#include "types.h"
#include "sofdec/axrna.h"

void fn_8005A9B8(AXRNAHandle *handle);

extern AXRNAHandle lbl_80191D4C[16];

void AXRNA_ExecServer(void) {
    unsigned int i;
    for (i = 0; i < 16; i++) {
        if (lbl_80191D4C[i].used == 1) {
            fn_8005A9B8(&lbl_80191D4C[i]);
        }
    }
}
