#include "types.h"

typedef struct Sig_fn_8006A768_FstEntry {
    u32 nameOffset;
    u32 parent;
    u32 next;
} Sig_fn_8006A768_FstEntry;
typedef struct Sig_fn_8006A768_FstInfo {
    u8 pad_0[0x4];
    Sig_fn_8006A768_FstEntry *entries;
    u8 pad_8[0x8];
    u8 *strings;
    u8 pad_14[4];
    u32 index;
} Sig_fn_8006A768_FstInfo;
extern u32 fn_8006A768(Sig_fn_8006A768_FstInfo *, u32, u8 *, u32);

static inline s32 entryActive(Sig_fn_8006A768_FstEntry *entries, u32 index) {
    if ((entries[index].nameOffset & 0xFF000000) == 0) {
        return 0;
    }
    return 1;
}

s32 fn_8006A8CC(Sig_fn_8006A768_FstInfo *info, u8 *buffer, u32 size) {
    Sig_fn_8006A768_FstEntry *entries;
    u32 index;
    u32 length;
    index = info->index;
    entries = info->entries;
    length = fn_8006A768(info, index, buffer, size);
    if (length == size) {
        buffer[size - 1] = 0;
        length = 0;
    } else {
        if (entryActive(entries, index)) {
            if (length == size - 1) {
                buffer[length] = 0;
                length = 0;
                goto done; /* Keep the verified branch to done. */
            }
            buffer[length] = '/';
            length++;
        }
        buffer[length] = 0;
        length = 1;
    }
done:
    return length;
}
