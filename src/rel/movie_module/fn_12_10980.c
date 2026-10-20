#include "types.h"
extern u16 lbl_12_bss_66F0[256];
extern u16 lbl_12_bss_6670[64];

#pragma opt_propagation off
#pragma opt_strength_reduction off
#pragma opt_common_subs off
void fn_12_10980(void) {
    int m;
    u16 *output;
    int i;
    int h;
    int j;
    s16 value;
    int k;
    u16 *output2;
    int n;
    output = lbl_12_bss_66F0;
    for (j=0;j<16;j++) *output++ = 0x240;
    *output++ = 0x23b;
    *output++ = 0x23b;
    for (j=0;j<12;j++) *output++ = 0x240;
    *output++ = 0x22b;
    *output++ = 0x22b;
    for (j=0;j<16;j++) *output++ = 0x240;
    for (i=33<<4;i>=22<<4;i-=16) {
        *output++ = i|0x440d;
        *output++ = i|0x40c;
    }
    for (i=21<<4;i>=16<<4;i-=16) {
        *output++ = i|0x440c;
        *output++ = i|0x440c;
        *output++ = i|0x40b;
        *output++ = i|0x40b;
    }
    for (m=15<<4;m>=10<<4;m-=16) {
        for(j=0;j<8;j++) *output++ = m|0x440a;
        for(j=0;j<8;j++) *output++ = m|0x409;
    }
    for (i=9;i>=8;i--) {
        value = (i<<4)|0x4409;
        for(j=0;j<16;j++) *output++ = value;
        value = (i<<4)|0x408;
        for(j=0;j<16;j++) *output++ = value;
    }
    output2 = lbl_12_bss_6670;
    *output2++ = 0x240;
    *output2++ = 0x240;
    *output2++ = 0x240;
    *output2++ = 0x240;
    for (i=7<<4;i>=6<<4;i-=16) {
        *output2++ = i|0x4407;
        *output2++ = i|0x406;
    }
    for (m=5<<4;m>=4<<4;m-=16) {
        *output2++ = m|0x4406;
        *output2++ = m|0x4406;
        *output2++ = m|0x405;
        *output2++ = m|0x405;
    }
    for (h=3<<4;h>=2<<4;h-=16) {
        for(n=0;n<4;n++) *output2++ = h|0x4405;
        for(n=0;n<4;n++) *output2++ = h|0x404;
    }
    for (k=1<<4;k>=1<<4;k-=16) {
        value = k|0x4403;
        for(n=0;n<16;n++) *output2++ = value;
        value = k|0x402;
        for(n=0;n<16;n++) *output2++ = value;
    }
}
#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
