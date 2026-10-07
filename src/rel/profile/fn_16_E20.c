#include "types.h"
struct State {
 u8 pad0[8]; s16 controller; u8 padA[2]; s16 selection;
 u8 padE[0x3E]; u32 flags; s16 direction; s16 zero; s16 speed;
};
struct Input { u8 pad0[8]; volatile u16 pressed; u8 padA[6]; volatile u16 repeat; volatile u16 repeat2; }; // input state is read on each test
struct Table { s16 ids[41]; };
extern struct State lbl_1_bss_8B614;
extern struct Input lbl_1_bss_9F8[];
extern struct Table lbl_16_bss_B060;
extern s16 lbl_16_bss_B0B2;
extern void fn_1_A2D84(u32);
extern u32 fn_1_F7BE4(u32);
s16 fn_16_E20(void) {
 s32 direction;
 s32 offset;
 s32 index;
 struct { s16 *p; } ids;
 s32 selection;
 s32 i;
 s32 next;
 s32 limit;
 struct State *state;
 direction = 0;
 offset = lbl_1_bss_8B614.controller;
 if ((lbl_1_bss_9F8[offset].repeat & 1) ||
     (lbl_1_bss_9F8[offset].repeat2 & 1)) direction = -1;
 if (((lbl_1_bss_9F8[offset].repeat >> 1) & 1) ||
     ((lbl_1_bss_9F8[offset].repeat2 >> 1) & 1)) direction++;
 if ((s16)direction != 0) {
  fn_1_A2D84(0xA9010000);
  if ((s16)direction < 0) {
   lbl_1_bss_8B614.flags = 0;
   lbl_1_bss_8B614.flags |= 0x80000000;
   lbl_1_bss_8B614.direction = direction;
   lbl_1_bss_8B614.flags |= 0x20000001;
   lbl_1_bss_8B614.zero = 0;
   lbl_1_bss_8B614.speed = direction * 5;
  } else {
   lbl_1_bss_8B614.flags = 0;
   lbl_1_bss_8B614.flags |= 0x80000000;
   lbl_1_bss_8B614.direction = direction;
   lbl_1_bss_8B614.flags |= 0x40000001;
   lbl_1_bss_8B614.zero = 0;
   lbl_1_bss_8B614.speed = direction * 5;
  }
  ids.p = lbl_16_bss_B060.ids;
  state = (struct State *)&lbl_1_bss_8B614;
  i = 0;
  selection = state->selection;
  for (; (s16)i < 41; i++) {
   if (selection == *ids.p) { index = i; break; }
   ids.p++;
  }
  do {
   limit = lbl_16_bss_B0B2 - 1;
   next = (s16)index + (s16)direction;
   if (next > limit) next = 0;
   else if (next < 0) next = limit;
   index = (s16)next;
  } while ((s32)fn_1_F7BE4(lbl_16_bss_B060.ids[(s16)index]) == 0);
  state->selection = lbl_16_bss_B060.ids[(s16)index];
 }
 if ((lbl_1_bss_9F8[offset].pressed >> 9) & 1) {
  fn_1_A2D84(0xA9010200); return -1;
 }
 if ((lbl_1_bss_9F8[offset].pressed >> 8) & 1) {
  fn_1_A2D84(0xA9010100); return 1;
 }
 return 0;
}
