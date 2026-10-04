#include <types.h>
#include "dolphin/ar.h"

void ARStartDMA(u32 type, u32 mainmem_addr, u32 aram_addr, u32 length);

extern ARQRequest *lbl_801A6A08;

extern ARQRequest *lbl_801A6A14;

extern ARQCallback lbl_801A6A1C;

extern u32 lbl_801A6A20;

void __ARQServiceQueueLo(void) {
    if ((lbl_801A6A14 == 0) && (lbl_801A6A08)) {
        lbl_801A6A14 = lbl_801A6A08;
        lbl_801A6A08 = lbl_801A6A08->next;
    }
    if (lbl_801A6A14) {
        if (lbl_801A6A14->length <= lbl_801A6A20) {
            if (lbl_801A6A14->type == 0x00)
                ARStartDMA(lbl_801A6A14->type, lbl_801A6A14->source, lbl_801A6A14->dest,
                           lbl_801A6A14->length);
            else
                ARStartDMA(lbl_801A6A14->type, lbl_801A6A14->dest, lbl_801A6A14->source,
                           lbl_801A6A14->length);
            lbl_801A6A1C = lbl_801A6A14->callback;
        } else {
            if (lbl_801A6A14->type == 0x00)
                ARStartDMA(lbl_801A6A14->type, lbl_801A6A14->source, lbl_801A6A14->dest,
                           lbl_801A6A20);
            else
                ARStartDMA(lbl_801A6A14->type, lbl_801A6A14->dest, lbl_801A6A14->source,
                           lbl_801A6A20);
        }
        lbl_801A6A14->length -= lbl_801A6A20;
        lbl_801A6A14->source += lbl_801A6A20;
        lbl_801A6A14->dest += lbl_801A6A20;
    }
}
