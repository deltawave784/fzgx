#include "types.h"
struct Sig_fn_80028B3C_fn_80028B3C_Arg0 {
u8 pad_0[8]; f32 unk_8, unk_C, unk_10, unk_14; u32 unk_18; u8 unk_1C, unk_1D, unk_1E, pad_1F; u16 unk_20, unk_22; f32 unk_24; u32 unk_28;
};
struct Sig_fn_800289C0_fn_800289C0_Arg0 { u8 pad_0[8]; s32 unk_8, unk_C, unk_10; };
struct Sig_fn_80028A78_fn_80028A78_Arg0 { f32 *unk_0; u32 unk_4; f32 unk_8; u32 unk_C; f32 unk_10, unk_14, unk_18, unk_1C; };
struct Sig_fn_80028A1C_fn_80028A1C_Arg0 { u8 pad_0[8]; s32 unk_8, unk_c, unk_10; };
typedef struct Sig_fn_800234D0_Fn800234D0State { u8 pad_000[0x1c]; u32 flags; u8 pad_020[0x1be]; u16 value_high, value_low; } Sig_fn_800234D0_Fn800234D0State;
typedef struct Sig_fn_80023228_Fn80023228Work { u8 _pad0[0x1c]; u32 flags; u8 _pad1[0x158]; s16 field_178, field_17a; } Sig_fn_80023228_Fn80023228Work;
struct Sig_fn_80026D90_fn_80026D90_Arg0 { u8 pad_0[0x18]; u32 unk_18; };
struct Sig_fn_80026E2C_fn_80026E2C_Arg0 { u8 pad_0[0x18]; u32 unk_18; };
struct Sig_fn_80026EAC_fn_80026EAC_Arg0 { u8 pad_0[0x18]; u32 unk_18; };
struct Sig_fn_80026EE0_fn_80026EE0_Arg0 { u8 pad_0[0x18]; u32 unk_18; };
struct Sig_fn_80026F4C_fn_80026F4C_Arg0 { u8 pad_0[0x18]; u32 unk_18; };
struct fn_800285DC_Arg0 { u8 pad_0[0xC]; f32 unk_C; };
extern f32 fn_800288C4(s32);
extern const f32 lbl_801A7028;
extern const f64 lbl_801A7030;
extern u32 fn_80026D90(struct Sig_fn_80026D90_fn_80026D90_Arg0 *, u32);
extern u32 fn_80026E2C(struct Sig_fn_80026E2C_fn_80026E2C_Arg0 *, u32);
extern u32 fn_80026EAC(struct Sig_fn_80026EAC_fn_80026EAC_Arg0 *, u32);
extern void fn_800230A4(void *, s32);
extern void fn_80023228(Sig_fn_80023228_Fn80023228Work *, s32, s32);
extern void fn_800234D0(Sig_fn_800234D0_Fn800234D0State *, f32);
extern void fn_80026EE0(struct Sig_fn_80026EE0_fn_80026EE0_Arg0 *, s32);
extern void fn_80026F4C(struct Sig_fn_80026F4C_fn_80026F4C_Arg0 *, s32);
extern void fn_800289C0(struct Sig_fn_800289C0_fn_800289C0_Arg0 *);
extern void fn_80028A1C(struct Sig_fn_80028A1C_fn_80028A1C_Arg0 *);
extern void fn_80028A78(struct Sig_fn_80028A78_fn_80028A78_Arg0 *);
extern void fn_80028B3C(struct Sig_fn_80028B3C_fn_80028B3C_Arg0 *);
void fn_800285DC(struct fn_800285DC_Arg0 *arg0) {
 f32 v2;
 u32 v7;
 s32 v6, v5, v4, v3;
 s32 v9, v10, v13, v11, v12;
 u32 v18;
 f32 t9;
 v3=0; v4=0; v5=0; v6=0;
 v9=64; v10=127; v13=1; v12=0; v11=0;
 v2=arg0->unk_C / lbl_801A7028;
 v7=*(u32 *)((u8 *)arg0+16);
 while(v7 != 0) {
 switch(*(u32 *)((u8 *)v7+4)) {
 case 1:
 fn_80028B3C((struct Sig_fn_80028B3C_fn_80028B3C_Arg0 *)v7);
 v2 += *(f32 *)((u8 *)v7+36);
 v9=*(u8 *)((u8 *)v7+28);
 v10=*(u8 *)((u8 *)v7+29);
 v5 += *(u32 *)((u8 *)v7+40);
 v11=*(u16 *)((u8 *)v7+32);
 v12=*(u16 *)((u8 *)v7+34);
 v13=*(u8 *)((u8 *)v7+30);
 break;
 case 2: v9=*(u8 *)((u8 *)v7+8); v10=*(u8 *)((u8 *)v7+9); break;
 case 3: v11=*(u16 *)((u8 *)v7+8); v12=*(u16 *)((u8 *)v7+10); break;
 case 4: v13=*(u8 *)((u8 *)v7+8); break;
 case 5: v6 += *(u32 *)((u8 *)v7+8); break;
 case 6: fn_800289C0((struct Sig_fn_800289C0_fn_800289C0_Arg0 *)v7); v6 += *(u32 *)((u8 *)v7+16); break;
 case 7:
 fn_80028A78((struct Sig_fn_80028A78_fn_80028A78_Arg0 *)(v7+8));
 v6 += (s32)((f32)(s32)*(u32 *)((u8 *)v7+40) * *(f32 *)((u8 *)v7+36)); break;
 case 8: v5 += *(u32 *)((u8 *)v7+8); break;
 case 9: v4 += *(u32 *)((u8 *)v7+8); break;
 case 10: v3 += *(u32 *)((u8 *)v7+8); break;
 case 11: fn_80028A1C((struct Sig_fn_80028A1C_fn_80028A1C_Arg0 *)v7); v5 += *(u32 *)((u8 *)v7+16); break;
 case 12: fn_80028A1C((struct Sig_fn_80028A1C_fn_80028A1C_Arg0 *)v7); v4 += *(u32 *)((u8 *)v7+16); break;
 case 13: fn_80028A1C((struct Sig_fn_80028A1C_fn_80028A1C_Arg0 *)v7); v3 += *(u32 *)((u8 *)v7+16); break;
 case 14:
 fn_80028A78((struct Sig_fn_80028A78_fn_80028A78_Arg0 *)(v7+8));
 v5 += (s32)((f32)(s32)*(u32 *)((u8 *)v7+40) * *(f32 *)((u8 *)v7+36)); break;
 case 15:
 fn_80028A78((struct Sig_fn_80028A78_fn_80028A78_Arg0 *)(v7+8));
 v4 += (s32)((f32)(s32)*(u32 *)((u8 *)v7+40) * *(f32 *)((u8 *)v7+36)); break;
 case 16:
 fn_80028A78((struct Sig_fn_80028A78_fn_80028A78_Arg0 *)(v7+8));
 v3 += (s32)((f32)(s32)*(u32 *)((u8 *)v7+40) * *(f32 *)((u8 *)v7+36)); break;
 }
 v7=*(u32 *)v7;
 }
 t9=fn_800288C4(v6 >> 16);
 v18=*(u32 *)((u8 *)arg0+8);
 v2 *= t9;
 fn_800230A4((void *)v18, v13 & 255);
 fn_800234D0((Sig_fn_800234D0_Fn800234D0State *)v18,v2);
 fn_80023228((Sig_fn_80023228_Fn80023228Work *)v18,v11,v12);
 fn_80026D90((struct Sig_fn_80026D90_fn_80026D90_Arg0 *)v18,v5>>16);
 fn_80026E2C((struct Sig_fn_80026E2C_fn_80026E2C_Arg0 *)v18,v4);
 fn_80026EAC((struct Sig_fn_80026EAC_fn_80026EAC_Arg0 *)v18,v3);
 fn_80026EE0((struct Sig_fn_80026EE0_fn_80026EE0_Arg0 *)v18,v9 & 255);
 fn_80026F4C((struct Sig_fn_80026F4C_fn_80026F4C_Arg0 *)v18,v10 & 255);
}
