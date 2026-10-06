#pragma use_lmw_stmw off
#include "types.h"
extern u32 lbl_801A6628[2];
extern u32 fn_80071794(u32);
typedef struct Sig_fn_80078F0C_fn_80078F0C_Child {
 u32 flags; u16 index; u16 pad06; u32 value; u8 pad0C[0x14];
} Sig_fn_80078F0C_fn_80078F0C_Child;
typedef struct Sig_fn_80078F0C_fn_80078F0C_Obj {
 u8 pad00[4]; u32 flags; u8 pad08[0x10]; u16 count; u16 count2; u16 count3; u8 pad1E[2]; u32 offset; void *data; u8 pad28[0x18]; Sig_fn_80078F0C_fn_80078F0C_Child children[1];
} Sig_fn_80078F0C_fn_80078F0C_Obj;
extern u8 *fn_80078F0C(Sig_fn_80078F0C_fn_80078F0C_Obj *, void *, u8 *, const char *);
typedef struct Entry { Sig_fn_80078F0C_fn_80078F0C_Obj *obj; const char *name; } Entry;
typedef struct Container { u32 count; u8 *base; Entry *entries; u8 *strings; u32 unk; u8 *buffer; } Container;
void fn_80078DA8(Container *dst, u32 *src, void *arg2) {
 u32 total;
 u32 offset;
 u32 i;
 u8 *buffer;
 Sig_fn_80078F0C_fn_80078F0C_Obj *obj;
 u32 zero = 0;
 total = 0;
 dst->count = src[0];
 dst->base = (u8 *)src + src[1];
 dst->entries = (Entry *)(src + 2);
 dst->strings = (u8 *)(dst->entries + src[0]);
 dst->unk = zero;
 dst->buffer = (u8 *)zero;
 for (i = 0; i < dst->count; i++) {
  Entry *entry = &dst->entries[i];
  if ((u32)entry->obj == 0xFFFFFFFF) {
   entry->obj = (Sig_fn_80078F0C_fn_80078F0C_Obj *)zero;
   entry->name = (const char *)lbl_801A6628[0];
  } else {
   obj = (Sig_fn_80078F0C_fn_80078F0C_Obj *)(dst->base + (u32)entry->obj);
   entry->obj = obj;
   entry->name = (const char *)(dst->strings + (u32)entry->name);
   total += obj->count;
  }
 }
 if (arg2 != 0 && total != 0) {
  dst->buffer = (u8 *)fn_80071794(total * 32);
 } else {
  total = 0;
 }
 buffer = dst->buffer;
 for (i = 0; i < dst->count; i++) {
  Entry *entry = &dst->entries[i];
  if (entry->obj != 0) {
   fn_80078F0C(entry->obj, arg2, buffer, entry->name);
   if (total != 0) buffer += entry->obj->count * 32;
  }
 }
}
