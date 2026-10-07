#pragma use_lmw_stmw on
#include "types.h"
#include "dolphin/trk.h"
typedef struct Sig_fn_8008A1CC_TRKBuffer Sig_fn_8008A1CC_TRKBuffer;
struct Sig_fn_8008A1CC_TRKBuffer {
 u32 mutex; u32 isInUse; u32 length; u32 position; u8 data[0x880];
};
struct Sig_fn_80089144_fn_80089144_Arg0 { u8 pad_0[8]; u32 unk_8; u32 unk_C; };
struct Sig_fn_80089174_fn_80089174_Arg0 { u8 pad_0[8]; u32 unk_8; u32 unk_C; };
struct Sig_fn_80088B00_fn_80088B00_Arg0 { u8 pad_0[8]; u32 unk_8; };
extern s32 fn_80088B00(struct Sig_fn_80088B00_fn_80088B00_Arg0 *);
extern s32 fn_80089144(struct Sig_fn_80089144_fn_80089144_Arg0 *, u32);
extern s32 fn_8008C730(void *, u32, u32 *, u32, s32);
extern s32 fn_8008D398(void *, u32);
extern u32 fn_80089174(struct Sig_fn_80089174_fn_80089174_Arg0 *, u32);
extern u8 lbl_80095890[];
extern void *memset(void *, int, u32);
extern void MWTRACE(u32, ...);
s32 fn_8008A1CC(Sig_fn_8008A1CC_TRKBuffer *arg0) {
 struct { s32 value; } v9;
 u8 *p_lbl_80095890;
 s32 v6;
 u16 v1;
 u32 v0;
 u8 v2;
 s32 v3;
 struct { u32 a[512]; } loc_CC;
 struct { u32 a[16]; } loc_8C;
 struct { u8 a[64]; } loc_4C;
 struct { u8 a[64]; } loc_C;
 u32 loc_8;
 p_lbl_80095890 = (u8 *)&lbl_80095890;
 v0 = *(u32 *)((u8 *)arg0 + 32);
 v1 = *(u16 *)((u8 *)arg0 + 28);
 v2 = arg0->data[8];
 MWTRACE(1, p_lbl_80095890 + 384, arg0->data[4], v0, v1, v2);
 if (v2 & 2) {
  memset(&loc_4C, 0, 64);
  loc_4C.a[4] = 128;
  *(u32 *)&loc_4C = 64;
  loc_4C.a[8] = 18;
  fn_8008D398(&loc_4C, 64);
  v3 = 0;
 } else {
  loc_8 = v1;
  fn_80089144((struct Sig_fn_80089144_fn_80089144_Arg0 *)arg0, 64);
  TRKReadBuffer((TRKBuffer *)arg0, &loc_CC, loc_8);
  v6 = fn_8008C730(&loc_CC, v0, &loc_8, ((v2 >> 3) & 1) ^ 1, 0);
  fn_80089174((struct Sig_fn_80089174_fn_80089174_Arg0 *)arg0, 0);
  if (v6 == 0) {
   memset(&loc_8C, 0, 64);
   loc_8C.a[0] = 64;
   *(u8 *)((u8 *)&loc_8C + 4) = 128;
   *(u8 *)((u8 *)&loc_8C + 8) = v6;
   v6 = TRKAppendBuffer((TRKBuffer *)arg0, &loc_8C, 64);
  }
  if (v6 != 0) {
   switch (v6) {
    case 0x702: v6 = 21; break;
    case 0x700: v6 = 19; break;
    case 0x704: v6 = 33; break;
    case 0x705: v6 = 34; break;
    case 0x706: v6 = 32; break;
    default: v6 = 3; break;
   }
   memset(&loc_C, 0, 64);
   loc_C.a[4] = 128;
   *(u32 *)&loc_C = 64;
   loc_C.a[8] = v6;
   fn_8008D398(&loc_C, 64);
   v3 = 0;
  } else {
   MWTRACE(1, p_lbl_80095890 + 96);
   v9.value = fn_80088B00((struct Sig_fn_80088B00_fn_80088B00_Arg0 *)arg0);
   MWTRACE(1, p_lbl_80095890 + 128, v9.value);
   v3 = v9.value;
  }
 }
 return v3;
}
