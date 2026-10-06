#include "types.h"
extern u16 lbl_12_bss_6570[128];
extern u16 lbl_12_bss_6530[32];
void fn_12_105BC(void) {
 u16 *output = lbl_12_bss_6570;
 int i;
 *output++ = 0x240;
 *output++ = 0x240;
 *output++ = 0x240;
 *output++ = 0x240;
 *output++ = 0x240;
 *output++ = 0x240;
 *output++ = 0x240;
 *output++ = 0x240;
 *output++ = 0x23b;
 *output++ = 0x240;
 *output++ = 0x240;
 *output++ = 0x240;
 *output++ = 0x240;
 *output++ = 0x240;
 *output++ = 0x240;
 *output++ = 0x22b;
 *output++ = 0x240;
 *output++ = 0x240;
 *output++ = 0x240;
 *output++ = 0x240;
 *output++ = 0x240;
 *output++ = 0x240;
 *output++ = 0x240;
 *output++ = 0x240;
 for(i=33;i>=22;i--) *output++ = (i<<4)|11;
 for(i=21;i>=16;i--) {
 *output++ = (i<<4)|10;
 *output++ = (i<<4)|0xa80b;
 }
 for(i=15;i>=10;i--) {
 *output++ = (i<<4)|8;
 *output++ = (i<<4)|0xa00b;
 *output++ = (i<<4)|0x880a;
 *output++ = (i<<4)|0x880a;
 *output++ = (i<<4)|0xa809;
 *output++ = (i<<4)|0xa809;
 *output++ = (i<<4)|0xa809;
 *output++ = (i<<4)|0xa809;
 }
 for(i=9;i>=8;i--) {
 *output++ = (i<<4)|7;
 *output++ = (i<<4)|7;
 *output++ = (i<<4)|40970;
 *output++ = (i<<4)|40970;
 *output++ = (i<<4)|34825;
 *output++ = (i<<4)|34825;
 *output++ = (i<<4)|34825;
 *output++ = (i<<4)|34825;
 *output++ = (i<<4)|43016;
 *output++ = (i<<4)|43016;
 *output++ = (i<<4)|43016;
 *output++ = (i<<4)|43016;
 *output++ = (i<<4)|43016;
 *output++ = (i<<4)|43016;
 *output++ = (i<<4)|43016;
 *output++ = (i<<4)|43016;
 }
 output = lbl_12_bss_6530;
 *output++ = 0x240;
 *output++ = 0x240;
 for(i=7;i>=6;i--) *output++ = (i<<4)|5;
 for(i=5;i>=4;i--) {
 *output++ = (i<<4)|4;
 *output++ = (i<<4)|0xa805;
 }
 for(i=3;i>=2;i--) {
 *output++ = (i<<4)|3;
 *output++ = (i<<4)|0x8805;
 *output++ = (i<<4)|0xa804;
 *output++ = (i<<4)|0xa804;
 }
 for(i=1;i>=1;i--) {
 *output++ = (i<<4)|1;
 *output++ = (i<<4)|1;
 *output++ = (i<<4)|40964;
 *output++ = (i<<4)|40964;
 *output++ = (i<<4)|34819;
 *output++ = (i<<4)|34819;
 *output++ = (i<<4)|34819;
 *output++ = (i<<4)|34819;
 *output++ = (i<<4)|43010;
 *output++ = (i<<4)|43010;
 *output++ = (i<<4)|43010;
 *output++ = (i<<4)|43010;
 *output++ = (i<<4)|43010;
 *output++ = (i<<4)|43010;
 *output++ = (i<<4)|43010;
 *output++ = (i<<4)|43010;
 }
}
