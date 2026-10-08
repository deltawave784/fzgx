#include "types.h"
#include "sofdec/adxt.h"
#pragma use_lmw_stmw on
typedef u32 (*fn_80053F38_Fn0)(u32,u32);
typedef u32 (*fn_80053F38_Fn2)(u32,u32,u32,void *);
typedef u32 (*fn_80053F38_Fn3)(u32,u32,void *);
typedef void (*fn_80053F38_Fn5)(u32);
struct fn_80053F38_Arg0 {
 u32 unk_0;
 u8 pad_4; u8 unk_5; u8 pad_6; u8 unk_7;
 u32 unk_8; u32 unk_C; u32 unk_10[2]; u32 unk_18;
 s32 unk_1C; s32 unk_20; s32 unk_24; s32 unk_28; s32 unk_2C; s32 unk_30;
 u32 unk_34; u32 unk_38; fn_80053F38_Fn5 unk_3C; u32 unk_40;
};
struct Sig_fn_80050180_fn_80050180_Arg0 { u8 pad_0[4]; u32 unk_4; };
struct Sig_fn_800510C4_fn_800510C4_Arg0 { u8 pad_0[0x348]; u32 unk_348; };
struct Sig_fn_80050F74_fn_80050F74_Arg0 { u8 pad_0[0x345]; u8 unk_345; };
struct Sig_fn_80050F90_fn_80050F90_Obj { u8 *unk_0; u8 pad_4[0x344]; s32 unk_348; void *unk_34c; void *unk_350; u8 pad_354[0x30]; u8 unk_384[4]; s32 unk_388; u8 pad_38c[0x2c]; u8 unk_3b8[0x200]; u8 unk_5b8[4]; };
struct Sig_fn_800589BC_fn_800589BC_Arg2 { u32 unk_0; u32 unk_4; };
struct Sig_fn_800589BC_fn_800589BC_Arg3 { u32 unk_0; u32 unk_4; };
struct Sig_fn_800501EC_fn_800501EC_Arg0 { u8 pad_0[0x10]; u32 unk_10; };
extern s32 fn_80050180(struct Sig_fn_80050180_fn_80050180_Arg0 *);
extern s32 fn_80050F64(u32);
extern s32 fn_80050F6C(u32);
extern u32 fn_800510C4(struct Sig_fn_800510C4_fn_800510C4_Arg0 *);
extern int fn_80053A30(void);
extern u32 lbl_801873DC[4];
extern u32 fn_800510D8(u32);
extern u32 fn_80050F74(struct Sig_fn_80050F74_fn_80050F74_Arg0 *);
extern s32 fn_80050F90(struct Sig_fn_80050F90_fn_80050F90_Obj *,u8 *,u8 *,s32);
extern void fn_800589BC(const void *,int,void *,void *);
extern u32 fn_800501EC(struct Sig_fn_800501EC_fn_800501EC_Arg0 *);
extern void *memset(void *,int,unsigned long);
void fn_80053F38(struct fn_80053F38_Arg0 *arg0) {
 struct { s32 value; } requested;
#define v5 requested.value
 s32 v9;
 struct { struct Sig_fn_800589BC_fn_800589BC_Arg2 *value; } chunk;
#define v19 chunk.value
 u32 v1;
 u32 *v0;
 s32 v7;
 u32 v14;
 s32 v10;
 s32 v13;
 u32 *v11;
 struct Sig_fn_800589BC_fn_800589BC_Arg2 *v12;
 u32 *v17;
 s32 v15;
 s32 v18;
 struct { struct Sig_fn_800589BC_fn_800589BC_Arg3 *value; } remainder;
#define v16 remainder.value
 s32 v20;
 u32 v21;
 struct Sig_fn_800589BC_fn_800589BC_Arg2 loc_18[2];
 struct Sig_fn_800589BC_fn_800589BC_Arg3 loc_8[2];
 v14 = 0;
 v0 = arg0->unk_10;
 v1 = arg0->unk_0;
 v21 = arg0->unk_C;
 if ((s32)arg0->unk_7 == 1 && (s32)((fn_80053F38_Fn0)*(u32 *)(*(u32 *)v21 + 36))(v21,1) == 0
 && fn_80050180((void *)arg0->unk_8) == 1) {
  arg0->unk_5 = 3; return;
 }
 v5 = fn_80050F64(arg0->unk_0);
 v7 = fn_80050F6C(arg0->unk_0) / 8;
 v21 = arg0->unk_10[0];
 if ((s32)((fn_80053F38_Fn0)*(u32 *)(*(u32 *)v21 + 36))(v21,0) / v7 < v5) return;
 if ((s32)fn_800510C4((void *)v1) != 0) {
  lbl_801873DC[2] = fn_80053A30();
  if ((s32)fn_800510D8(v1) == 1) { arg0->unk_5 = 3; return; }
  lbl_801873DC[3] = fn_80053A30();
 }
 v9 = fn_80050F74((void *)arg0->unk_0);
 memset(loc_18,0,16);
 v19 = loc_18;
 v13 = v5 * v7;
 for (v10=0; v10<v9; v10++) {
  ((SJ *)v0[v10])->interface->get_chunk((SJ *)v0[v10],0,v13,(SJCK *)&loc_18[v10]);
 }
 v20 = loc_18[0].unk_0;
 if (v9 == 2) v14 = loc_18[1].unk_0;
 if ((s32)(loc_18[0].unk_4 >> 1) != v5) { for (;;) {} }
 lbl_801873DC[0] = fn_80053A30();
 v5 = fn_80050F90((void *)v1,(u8 *)v20,(u8 *)v14,v5);
 v15 = v5;
 lbl_801873DC[1] = fn_80053A30();
 v18 = v5 * v7;
 for (v14=0, v10=0; (s32)v14<v9; v14++) {
  fn_800589BC(v19,v18,v19,&loc_8[v10]);
  ((SJ *)v0[v14])->interface->put_chunk((SJ *)v0[v14],1,(SJCK *)v19);
  ((SJ *)v0[v14])->interface->unget_chunk((SJ *)v0[v14],0,(SJCK *)&loc_8[v10]);
  v10++;
  v19++;
 }
 arg0->unk_1C += v15;
 arg0->unk_20 = (s32)(fn_800501EC((void *)arg0->unk_8)+7) / 8;
 arg0->unk_24 += v15;
 arg0->unk_30 += v15;
 if (arg0->unk_2C >= 0 && arg0->unk_30 >= arg0->unk_2C && arg0->unk_3C)
  arg0->unk_3C(arg0->unk_40);
}
