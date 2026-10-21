#include "types.h"
typedef struct Sig_fn_12_298AC_MovieModule {
 u8 pad_0[0x28]; int threshold;
 u8 pad_2c[0x1b0c]; int previous;
} Sig_fn_12_298AC_MovieModule;
typedef struct Sig_fn_12_29524_MovieChunks {
 const u8 *data; int length; const u8 *next; int next_length; u32 pad[3];
} Sig_fn_12_29524_MovieChunks;
extern const u8 *fn_12_A0D8(const u8 *, int, int);
extern const u8 *fn_12_A1C4(const u8 *, int, int);
extern int fn_12_A2C4(const u8 *);
extern void *memcpy(void *, const void *, u32);
extern int fn_12_22390(void *, int, void *);
extern void fn_12_21FA4(void *, int, const u8 **, const u8 **);
extern void fn_12_21F48(void *, int, const u8 *, const u8 *);
extern int fn_12_29524(Sig_fn_12_29524_MovieChunks *, int, const u8 *);
extern int fn_12_21F38(void *, int);
extern int fn_12_21C00(void *, int);
extern int fn_12_24A88(void *, int);
#pragma opt_propagation off
#pragma opt_common_subs off
/* One search helper for both directions: every inline site shares the same
 * locals (first/second/i), which is what the retail allocation shows.
 * `backward` is a constant at each site; `next_length` is only used by the
 * backward search, whose caller already holds it in a register. */
static inline void find_delimiter(u8 *buffer, Sig_fn_12_29524_MovieChunks *chunks, int mask, const u8 **out, int *value, int backward, int next_length) {
    const u8 * fzgx_live_;
    const u8 * fzgx_live;
 struct { int value; } first;
 int second;
 int i;
 if (backward) {
  if (next_length != 0) {
   *out = fn_12_A1C4(chunks->next + chunks->next_length, chunks->next_length, mask);
   if (*out) { *value = fn_12_A2C4(*out); return; }
   first.value = chunks->length < 3 ? chunks->length : 3;
   second = chunks->next_length < 3 ? chunks->next_length : 3;
   memcpy(buffer, chunks->data + chunks->length - first.value, first.value);
   memcpy(buffer + first.value, chunks->next, second);
   for (i = 0; i < first.value + second - 3; i++) {
    int type = fn_12_A2C4(buffer + i);
    if (type & mask) {
     *value = type;
     *out = chunks->data + chunks->length - first.value + i;
     return;
    }
   }
  }
  *out = fn_12_A1C4(chunks->data + chunks->length, chunks->length, mask);
  if (*out) { *value = fn_12_A2C4(*out); return; }
  *out = 0;
  return;
 }
 fzgx_live_ = chunks->data;
 *out = fn_12_A0D8(fzgx_live_, chunks->length, mask);
 if (*out) { *value = fn_12_A2C4(*out); return; }
 { int length = chunks->next_length;
 if (length == 0) { *out = 0; return; }
 first.value = chunks->length < 3 ? chunks->length : 3;
 second = length < 3 ? chunks->next_length : 3;
 }
 fzgx_live_ = chunks->data;
 memcpy(buffer, fzgx_live_ + chunks->length - first.value, first.value);
 fzgx_live = chunks->next;
 memcpy(buffer + first.value, fzgx_live, second);
 for (i = 0; i < first.value + second - 3; i++) {
  int type = fn_12_A2C4(buffer + i);
  if (type & mask) {
   *value = type;
   fzgx_live_ = chunks->data;
   *out = fzgx_live_ + chunks->length - first.value + i;
   return;
  }
 }
 fzgx_live = chunks->next;
 *out = fn_12_A0D8(fzgx_live, chunks->next_length, mask);
 if (*out) { *value = fn_12_A2C4(*out); return; }
 *out = 0;
}
static inline const u8 * position_offset_read_pointer(Sig_fn_12_29524_MovieChunks * owner) { return owner->next; }
static inline int position_offset(Sig_fn_12_29524_MovieChunks *chunks, const u8 *p) {
 if (chunks->data <= p && p < chunks->data + chunks->length) return p - chunks->data;
 if (position_offset_read_pointer(chunks) <= p && p < position_offset_read_pointer(chunks) + chunks->next_length) return chunks->length + (p - position_offset_read_pointer(chunks));
 return 0;
}
static inline int shortage(Sig_fn_12_298AC_MovieModule *arg0) {
 int v13 = arg0->previous;
 int v14 = fn_12_21F38(arg0, v13);
 if (v14 - fn_12_21C00(arg0, v13) < arg0->threshold) return fn_12_24A88(arg0, 0xFF000F1C);
 return 0;
}
s32 fn_12_298AC(Sig_fn_12_298AC_MovieModule *arg0, int *arg1, int *arg2) {
 Sig_fn_12_29524_MovieChunks loc_30;
 u32 loc_28[2], loc_20[2], loc_18[2], loc_10[2];
 const u8 *loc_C, *loc_8;
 const u8 *found;
 int v0 = arg0->previous;
 int v2 = 0;
 int result;
 *arg1 = 0; *arg2 = 0;
 result = fn_12_22390(arg0, v0, &loc_30);
 if (result != 0) return result;
 if (loc_30.length == 0) return 0;
 v2 = 0; find_delimiter((u8 *)loc_28, &loc_30, 206, &found, &v2, 0, 0);
 if (found != loc_30.data) {
  if (found) *arg1 = position_offset(&loc_30, found);
  else { int n = loc_30.next_length - 3; n = loc_30.length + n; *arg1 = n & ~(n >> 31); }
  return 0;
 }
 *arg2 = v2; *arg1 = 4;
 if (v2 & 0x80) return 0;
 fn_12_21FA4(arg0, v0, &loc_C, &loc_8);
 if (fn_12_29524(&loc_30, v2, loc_C)) {
  const u8 *end;
  int next_length = loc_30.next_length;
  loc_C = 0;
  if (next_length == 0) end = loc_30.data + loc_30.length;
  else end = loc_30.next + next_length;
  if (loc_8 != end) {
   loc_8 = end;
   find_delimiter((u8 *)loc_20, &loc_30, 204, &found, &result, 1, next_length);
   loc_C = found;
   fn_12_21F48(arg0, v0, found, loc_8);
  }
 }
 if (!loc_C) return shortage(arg0);
 switch(fn_12_A2C4(loc_C)) {
 case 8:
  if (v2 & 0x40) {
   find_delimiter((u8 *)loc_18, &loc_30, 8, &found, &result, 0, 0);
   if (!found || found == loc_C) return shortage(arg0);
  }
  break;
 case 4:
  if (v2 & 0x48) {
   find_delimiter((u8 *)loc_10, &loc_30, 4, &found, &result, 0, 0);
   if (!found || found == loc_C) return shortage(arg0);
  }
  break;
 case 0x40: case 0x80: break;
 default: break;
 }
 *arg1 = position_offset(&loc_30, loc_C);
 return 0;
}
