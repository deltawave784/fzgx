#include "types.h"
#include "dolphin/hw_regs.h"
extern u32 lbl_801A7390;
extern u32 OSGetTick(void);
extern u8 lbl_801327F8[163944];
extern u8 lbl_8019E114[44];
extern const f32 lbl_801A7394;
struct fn_8006C7E8_Arg0 {
 u32 unk_0, unk_4, unk_8, unk_C;
 s32 unk_10[10];
 u32 unk_38[10];
 u32 unk_60, unk_64;
 u32 unk_68[16], unk_A8[16];
 u32 unk_E8, unk_EC;
};
#pragma optimize_for_size on
static inline void reset(struct fn_8006C7E8_Arg0 *arg0, s32 *values) {
 s32 i;
 for(i=0;i<10;i++) {
  arg0->unk_10[i]=values[i];
  arg0->unk_38[i]=0;
 }
 /* volatile: retail stores unk_60 again after the loop instead of merging it with the earlier zero store */
 *(volatile u32 *)&arg0->unk_60=0;
}
#pragma opt_loop_invariants off
static inline void convert(f32 *values, s32 *out) {
 s32 i = 0;
 s32 count;
 for(count=10;count!=0;count--) {
  /* volatile: retail reloads the 4096.0f literal inside the loop body on every trip */
  out[i]=(s32)((*(volatile const f32 *)&lbl_801A7394) * values[i]);
  i++;
 }
}
void fn_8006C7E8(struct fn_8006C7E8_Arg0 *arg0, u32 arg1) {
 u32 initial = lbl_801A7390;
 s32 i;
 arg0->unk_4 = 0;
 arg0->unk_60 = 0;
 arg0->unk_E8 = 0;
 for (i=0;i<16;i++) {
  arg0->unk_68[i]=0;
  arg0->unk_A8[i]=0;
 }
 arg0->unk_0=arg1;
 arg0->unk_EC=0;
 arg0->unk_C=0;
 arg0->unk_8=0;
 arg0->unk_64=0;
 arg0->unk_4=OSGetTick() / ((__OSBusClock >> 2) / 1000);
 reset(arg0, (s32 *)&initial);
 convert((f32 *)lbl_801327F8, (s32 *)lbl_8019E114);
 reset(arg0, (s32 *)lbl_8019E114);
}
