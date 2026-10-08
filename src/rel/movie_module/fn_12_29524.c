#include "types.h"
extern const unsigned char *fn_12_A0D8(const unsigned char *, int, int);
extern int fn_12_A2C4(const unsigned char *);
extern void *memcpy(void *, const void *, u32);
typedef struct MovieChunks {
 const u8 *data;
 int length;
 const u8 *next;
 int next_length;
} MovieChunks;

#pragma opt_propagation off
#pragma opt_common_subs off
static inline int find_delimiter(u8 *buffer, MovieChunks *chunks, int mask, const u8 **out) {
 struct { int value; } first;
 int second;
 int i;
 *out = fn_12_A0D8(chunks->data, chunks->length, mask);
 if (*out) {
  return fn_12_A2C4(*out);
 }
 { int length = chunks->next_length;
 if (length == 0) { *out = 0; return 0; }
 first.value = chunks->length < 3 ? chunks->length : 3;
 second = length < 3 ? chunks->next_length : 3;
 }
 memcpy(buffer, chunks->data + chunks->length - first.value, first.value);
 memcpy(buffer + first.value, chunks->next, second);
 for (i = 0; i < first.value + second - 3; i++) {
  int type = fn_12_A2C4(buffer + i);
  if (type & mask) {
   *out = chunks->data + chunks->length - first.value + i;
   return type;
  }
 }
 *out = fn_12_A0D8(chunks->next, chunks->next_length, mask);
 if (*out) {
  return fn_12_A2C4(*out);
 }
 *out = 0;
 return 0;
}

int fn_12_29524(MovieChunks *chunks, int flags, const u8 *position) {
 u32 header;
 u32 buffer8[2];
 u32 buffer4[2];
 const u8 *found;
 int over;
 if (!position) return 1;
 if (position == chunks->data) return 1;
 if (position >= chunks->data && position < chunks->data + chunks->length) {
  over = position + 4 - (chunks->data + chunks->length);
  if (over > 0) {
   if (over > chunks->next_length) return 1;
   memcpy(&header, position, 4 - over);
   memcpy((u8 *)&header + 4 - over, chunks->next, over);
  } else memcpy(&header, position, 4);
 } else if (position >= chunks->next && position < chunks->next + chunks->next_length) {
  if (position + 4 - (chunks->next + chunks->next_length) > 0) return 1;
  memcpy(&header, position, 4);
 } else return 1;
 switch (fn_12_A2C4((u8 *)&header)) {
 case 8:
  if (flags & 0x40) {
   find_delimiter((u8 *)buffer8, chunks, 8, &found);
   if (!found || found == position) return 1;
  }
  break;
 case 4:
  if (flags & 0x48) {
   find_delimiter((u8 *)buffer4, chunks, 4, &found);
   if (!found || found == position) return 1;
  }
  break;
 case 0x40:
 case 0x80:
  break;
 default:
  return 1;
 }
 return 0;
}
