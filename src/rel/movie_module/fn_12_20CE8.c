#include "types.h"
#include "sofdec/adxt.h"
typedef void (*Sig_fn_12_20F4C_MoviePrepareFn)(void *, int, int, void *);
typedef void (*Sig_fn_12_20F4C_MovieUpdateFn)(void *, int, void *);
typedef void (*Sig_fn_12_20F4C_MovieProcessFn)(void *, int, void *);
typedef struct Sig_fn_12_20F4C_MovieVTable {
 void *unused[6];
 Sig_fn_12_20F4C_MoviePrepareFn prepare;
 Sig_fn_12_20F4C_MovieUpdateFn update;
 Sig_fn_12_20F4C_MovieProcessFn process;
} Sig_fn_12_20F4C_MovieVTable;
typedef struct Sig_fn_12_20F4C_MovieData { Sig_fn_12_20F4C_MovieVTable *vtable; } Sig_fn_12_20F4C_MovieData;
typedef struct Sig_fn_12_20F4C_MovieState {
 char pad0000[4]; Sig_fn_12_20F4C_MovieData *movie; int field8; char pad000c[0x3c]; int elapsed;
} Sig_fn_12_20F4C_MovieState;
typedef struct Sig_fn_12_20F4C_MovieModule {
 char pad0000[0x1b74]; Sig_fn_12_20F4C_MovieState *state;
} Sig_fn_12_20F4C_MovieModule;
typedef struct Sig_fn_12_2EA6C_MovieModuleState { u8 padding_000[0x118]; int field_118; } Sig_fn_12_2EA6C_MovieModuleState;
typedef struct Sig_fn_12_2E9E4_MovieModuleState { u8 padding_000[0x10c]; u32 field_10c; u32 field_110; } Sig_fn_12_2E9E4_MovieModuleState;
struct Sig_fn_12_2E9F0_fn_12_2E9F0_Arg0 { u8 pad_0[0xE4]; u32 unk_E4; };
struct Sig_fn_12_2E9F0_fn_12_2E9F0_Arg2 { u32 unk_0; };
struct Sig_fn_8004B974_fn_8004B974_Arg2 { u32 unk_0; };
struct fn_12_20CE8_Arg0 { u8 pad_0[0x2908]; u32 unk_2908; };
extern int fn_12_2EA6C(Sig_fn_12_2EA6C_MovieModuleState *, int);
extern s32 fn_8004B7F4(ADXTHandle *, s32, s32);
extern s32 fn_8004B974(u32, u32, struct Sig_fn_8004B974_fn_8004B974_Arg2 *);
extern u32 fn_12_2D73C(u8 *, int);
extern u32 fn_12_2E9F0(struct Sig_fn_12_2E9F0_fn_12_2E9F0_Arg0 *, u32, struct Sig_fn_12_2E9F0_fn_12_2E9F0_Arg2 *);
extern void fn_12_20F4C(Sig_fn_12_20F4C_MovieModule *, void *, int, int *);
extern void fn_12_2D7DC(u8 *, int, int);
extern void fn_12_2E9E4(Sig_fn_12_2E9E4_MovieModuleState *, u32, u32);
static inline u32 get_stream(struct fn_12_20CE8_Arg0 *module) {
 u32 p = module->unk_2908;
 u32 state = *(u32 *)((u8 *)module + 0x1b74);
 if (p == 0) return 0;
 if (*(s32 *)(state + 0x40) > 0) return 0;
 return p + 0xcfc;
}
#pragma use_lmw_stmw on
#pragma opt_propagation off
#pragma opt_lifetimes off
void fn_12_20CE8(struct fn_12_20CE8_Arg0 *arg0, u32 arg1, s32 arg2, u32 *arg3) {
 u32 v9;
 s32 v5;
 s32 v16;
 s32 v4;
 s32 v7;
 s32 v15;
 s32 v8;
 s32 v13;
 #define v17 v7
 #define v12 v5
 u32 v2;
 u32 v1;
 u32 v3;
 int status;
 s32 delta;
 struct Sig_fn_8004B974_fn_8004B974_Arg2 loc_10;
 struct Sig_fn_12_2E9F0_fn_12_2E9F0_Arg2 loc_C;
 struct Sig_fn_8004B974_fn_8004B974_Arg2 loc_8;
{
 s32 v0;
 v0 = (u32)arg0 + 0xcc0;
 *arg3 = 0;
 v3 = get_stream(arg0);
 v2 = *(u32 *)((u8 *)arg0 + 0x1b74);
 if (v3 == 0) status = -1;
 else { v4 = *(s32 *)(v3 + 0xc); v5 = *(s32 *)(v3 + 0x10); status = 0; }
 if (status != 0) {
  *(u32 *)(v2 + 0x3c) = (u32)fn_12_20F4C;
  return;
 }
 v7 = fn_12_2EA6C((Sig_fn_12_2EA6C_MovieModuleState *)v0, v5);
 if (v7 < 0) return;
 if ((s32)fn_12_2D73C((u8 *)arg0, 5) == 0) {
  fn_12_2E9E4((Sig_fn_12_2E9E4_MovieModuleState *)v0, v7, v5);
  *(u32 *)(v2 + 0x3c) = (u32)fn_12_20F4C;
  return;
 }
 v8 = (s32)fn_12_2E9F0((struct Sig_fn_12_2E9F0_fn_12_2E9F0_Arg0 *)v0, v5, &loc_C);
 if (v8 < 0) return;
 fn_12_2E9E4((Sig_fn_12_2E9E4_MovieModuleState *)v0, v8, v5);
}
 delta = (v8 - v7) - *(s32 *)(v2 + 0x38);
 v9 = 0;
 if (delta >= 0) {
  v12 = (delta / 32 * v4) * 18;
  v17 = 0;
  if (v12 > 0) {
   v13 = v4 * 18;
   v15 = v12;
   { s32 limit = v4 * (arg2 / v13) * 18;
    if (limit < v15) v15 = limit;
   }
   v9 = arg1;
   v17 = 0;
   v16 = 0;
   while (v16 < v15) {
    if (fn_8004B974(v9, 18, &loc_8) != 0) { v17 = 1; break; }
    v9 += 18;
    v16 += 18;
   }
   *(s32 *)(v2 + 0x38) += (v16 / v13) << 5;
   v9 = v16;
   v12 -= v15;
  }
  if (v12 <= 0 && (s32)loc_C.unk_0 != 0) {
   *(u32 *)(v2 + 0x3c) = (u32)fn_12_20F4C;
   v17 = fn_8004B974(arg1, arg2, &loc_10);
  }
  if (v17 != 0) fn_12_2D7DC((u8 *)arg0, 6, 0);
 } else if ((s32)loc_C.unk_0 != 0) {
  v13 = ((-delta) / 32) << 5;
  if (v13 > 0) {
   s32 used = fn_8004B7F4((ADXTHandle *)**(u32 **)((u8 *)arg0 + 0x1b74), v4, v13);
   v13 -= used;
   *(s32 *)(v2 + 0x38) -= used;
  }
  if (v13 <= 0) *(u32 *)(v2 + 0x3c) = (u32)fn_12_20F4C;
 }
 *arg3 = v9;
}
