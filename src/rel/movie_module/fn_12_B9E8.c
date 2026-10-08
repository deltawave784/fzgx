#include "types.h"
typedef struct MovieObject MovieObject;
typedef struct MovieBits { u32 address; u32 unk4; s32 bit; } MovieBits;
typedef struct MovieVTable {
 u8 pad[0x18];
 void (*method_0018)(MovieObject *, s32, s32, MovieBits *);
 void (*method_001c)(MovieObject *, s32, void *);
 void (*method_0020)(MovieObject *, s32, MovieBits *);
} MovieVTable;
struct MovieObject { MovieVTable *vtable; };
typedef struct MovieState {
 u8 pad0[0x1ec];
 u32 a,b,c,d,e;
 u32 count;
 u8 pad204[0x80];
 u32 flag0,flag1;
 u8 pad28c[0x103c];
 MovieBits bits;
 u8 pad12d4[0x30];
 u32 state;
} MovieState;
extern u32 fn_800589BC(MovieBits *, s32, MovieBits *, void *);
#pragma opt_propagation off
#pragma opt_lifetimes off
s32 fn_12_B9E8(MovieState *ctx, MovieObject *movie) {
 u32 result[2];
 u32 word;
 u32 *p;
 u32 next;
 u32 current;
 s32 shift;
 u32 value;
 ctx->state = 2;
 ctx->count++;
 movie->vtable->method_0018(movie, 1, 0x7fffffff, &ctx->bits);
 p = (u32 *)(ctx->bits.address & ~3);
 shift = (ctx->bits.address - (u32)p) * 8;
 word = p[1];
 p += 2;
 if (shift >= 32) { word = *p++; shift -= 32; }
 if (shift != 0) word <<= shift;
 next = *p++;
 if (shift >= 7) {
  shift -= 7;
  if (shift != 0) {
   current = word | (next >> (25 - shift));
   value = current >> 7;
   current = next << shift;
  } else { value = word >> 7; current = next; }
  next = *p++;
 } else {
  value = word >> 7;
  current = word << 25;
  shift += 25;
 }
 ctx->e = value & 63;
 ctx->d = (value >> 6) & 63;
 ctx->c = (value >> 13) & 63;
 ctx->b = (value >> 19) & 31;
 ctx->a = value >> 24;
 ctx->flag0 = current >> 31;
 if (shift == 31) { current = next; shift = 0; p++; }
 else { current <<= 1; shift++; }
 ctx->flag1 = current >> 31;
 if (shift == 31) { shift = 0; p++; }
 else { shift++; }
 ctx->bits.bit = shift & 7;
 current = ctx->bits.address;
 next = shift - ctx->bits.bit;
 p = (u32 *)((u8 *)p + (((s32)next + 7) >> 3));
 p = (u32 *)((u8 *)p - 8 - (u8 *)current);
 fn_800589BC(&ctx->bits, (s32)p, &ctx->bits, &result);
 movie->vtable->method_0020(movie, 0, &ctx->bits);
 movie->vtable->method_001c(movie, 1, &result);
 return 0;
}
