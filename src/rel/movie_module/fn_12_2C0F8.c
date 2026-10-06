#include "types.h"
typedef struct Sig_fn_12_2E714_MovieModuleState Sig_fn_12_2E714_MovieModuleState;
typedef s32 (*Sig_fn_12_2E714_MovieCallback)(Sig_fn_12_2E714_MovieModuleState *, s32 *, s32 *);
struct Sig_fn_12_2E714_MovieModuleState {
 u8 padding_000[0xcc0];
 Sig_fn_12_2E714_MovieCallback callbacks[1];
 u8 padding_001[0x244];
 s32 state;
 s32 value;
};
struct Sig_fn_12_2F1D0_fn_12_2F1D0_E68_u32 { u32 unk_0; u8 pad_4[0x40]; };
struct Sig_fn_12_2F1D0_fn_12_2F1D0_Arg0 {
 u8 pad_0[0x1AA4];
 struct Sig_fn_12_2F1D0_fn_12_2F1D0_E68_u32 unk_1AA4[1];
};
typedef struct MovieObject MovieObject;
typedef struct MovieVTable { u8 pad[0x24]; int (*get)(MovieObject *, int); } MovieVTable;
struct MovieObject { MovieVTable *vtable; };
typedef struct MovieEntry { int field_0; MovieObject *object; int field_8; int field_c; u8 pad[0x64]; } MovieEntry;
struct fn_12_2C0F8_Arg0 {
 u8 pad_0[0x48];
 int field_48; int field_4c; int field_50;
 u8 pad54[0x910];
 int field_964; int field_968;
 u8 pad96c[0x48];
 int field_9b4; int field_9b8;
 u8 pad9bc[0x34];
 u32 unk_9F0; u32 unk_9F4;
 u8 pad9f8[0x508];
 int field_f00; int field_f04;
 u8 padf08[0x248];
 MovieEntry entries[1];
 u8 pad11c4[0x974];
 int field_1b38;
 u8 pad1b3c[0x40];
 int field_1b7c;
};
extern int fn_12_332DC(int, int, int, int);
extern int fn_12_2E714(Sig_fn_12_2E714_MovieModuleState *, int *, int *);
extern int fn_12_2D73C(struct fn_12_2C0F8_Arg0 *, int);
extern int fn_12_2E7C8(struct fn_12_2C0F8_Arg0 *, int *, int *);
extern int fn_12_2EAC4(struct fn_12_2C0F8_Arg0 *);
extern int fn_12_2F1D0(struct Sig_fn_12_2F1D0_fn_12_2F1D0_Arg0 *, u32);
extern int fn_12_2E42C(int, int, int, int);
extern int fn_12_2F210(struct fn_12_2C0F8_Arg0 *, int, int, int, int);
extern void fn_12_24970(int *);
extern void fn_12_24950(int *);
extern int fn_12_2BE3C(struct fn_12_2C0F8_Arg0 *);
extern int fn_12_2ADDC(struct fn_12_2C0F8_Arg0 *, int);
extern int fn_12_21D30(struct fn_12_2C0F8_Arg0 *, int);
extern unsigned int UTY_MulDiv(int, int, int);
static inline int time_done(struct fn_12_2C0F8_Arg0 *module) {
 int state, time;
 int first, second;
 state = module->unk_9F0;
 time = module->unk_9F4;
 if(state == -4) return 0;
 fn_12_2E714((Sig_fn_12_2E714_MovieModuleState *)module, &first, &second);
 if(first < 0) return 0;
 if(fn_12_332DC(first,second,state,time)) return 0;
 return 1;
}
static inline int channels_done(struct fn_12_2C0F8_Arg0 *module) {
 int first;
 int second;
 int result;
 if(module->field_9b8 == 0 && module->field_9b4 == 0) return 1;
 result = 0;
 first = fn_12_2F1D0((struct Sig_fn_12_2F1D0_fn_12_2F1D0_Arg0 *)module,6);
 second = fn_12_2F1D0((struct Sig_fn_12_2F1D0_fn_12_2F1D0_Arg0 *)module,7);
 switch(fn_12_2D73C(module,25)) {
 case 1: result = second; break;
 case 2: result = first; break;
 case 3: result = second | first; break;
 case 0: result = second & first; break;
 }
 return result;
}
static inline int special_done(struct fn_12_2C0F8_Arg0 *module) {
 if(module->field_48 != 4 || module->field_50 == 1 || module->field_964 == 1) return 0;
 if(fn_12_2EAC4(module)) return 1;
 return 0;
}
static inline int elapsed(struct fn_12_2C0F8_Arg0 *module) {
 int first, second;
 if(module->field_48 != 4 || module->field_50 == 1 || module->field_964 == 1) return 0;
 if(fn_12_2E7C8(module,&first,&second)) return 0;
 if(first < 0) return 0;
 {
  int value = fn_12_2D73C(module,54);
  if(fn_12_2E42C(value,1000,first,second)) return 1;
 }
 return 0;
}
static inline int reset(struct fn_12_2C0F8_Arg0 *module) {
 if(module->field_48 == 4) {
  int result = fn_12_2F210(module,7,7,0,0);
  if(result) return result;
 }
 module->field_48 = 1;
 module->field_4c = 1;
 return 0;
}
static inline int finish(struct fn_12_2C0F8_Arg0 *module) {
 int result = reset(module);
 if(result) return result;
 module->field_4c = 6;
 return 0;
}
static inline int blocked(struct fn_12_2C0F8_Arg0 *module) {
 int i;
 if(fn_12_2D73C(module,5) && fn_12_2F1D0((struct Sig_fn_12_2F1D0_fn_12_2F1D0_Arg0 *)module,6)) return 1;
 if(fn_12_2D73C(module,6) && fn_12_2F1D0((struct Sig_fn_12_2F1D0_fn_12_2F1D0_Arg0 *)module,7)) return 1;
 for(i=0;i<8;i++) { if(fn_12_21D30(module,i)) return 1; }
 return 0;
}
static inline int limit(struct fn_12_2C0F8_Arg0 *module) {
 MovieEntry *entry;
 int value;
 entry = &module->entries[module->field_1b38];
 value = entry->object->vtable->get(entry->object,1);
 if(value >= entry->field_c * 80 / 100 || value >= fn_12_2D73C(module,0x46)) return 1;
 return 0;
}
static inline int leave(struct fn_12_2C0F8_Arg0 *module) {
 MovieEntry *entry;
 int value;
 int first, second;
 int remaining, total;
 if(blocked(module)) return 1;
 if(fn_12_2D73C(module,5) == 1 && limit(module)) return 1;
 if(fn_12_2D73C(module,6) == 1) {
  entry = &module->entries[module->field_1b7c];
  value = entry->object->vtable->get(entry->object,1);
  if(value >= entry->field_c * 80 / 100) return 1;
 }
 fn_12_2E714((Sig_fn_12_2E714_MovieModuleState *)module,&first,&second);
 remaining = module->field_f00;
 total = module->field_f04;
 remaining -= UTY_MulDiv(fn_12_2D73C(module,0x45),total,1000000);
 if(fn_12_2E42C(first,second,remaining,total)) return 1;
 return 0;
}
int fn_12_2C0F8(struct fn_12_2C0F8_Arg0 *arg0) {
 int work[3];
 int result;
 if(time_done(arg0) || channels_done(arg0) || special_done(arg0) || elapsed(arg0)) {
  result = finish(arg0);
 } else {
  result = 0;
 }
 if(result) return arg0->field_48;
 fn_12_24970(&work[0]);
 result = 0;
 if(arg0->field_964 == 0) {
  if(fn_12_2BE3C(arg0)) {
   arg0->field_964 = 1;
   arg0->field_968++;
   result = fn_12_2ADDC(arg0,1);
  }
 } else if(leave(arg0)) {
  arg0->field_964 = 0;
  result = fn_12_2ADDC(arg0,0);
 }
 fn_12_24950(&work[0]);
 if(result) return arg0->field_48;
 result = arg0->field_48;
 switch(arg0->field_4c) {
 case 4: break;
 case 6: result = 6; break;
 case 5: return result;
 }
 return result;
}
