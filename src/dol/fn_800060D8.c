#include "types.h"
#include "dolphin/hw_regs.h"

typedef struct GlyphEntry {
    void *image;
    u16 code;
    u16 width;
} GlyphEntry;

typedef struct TexObj {
    u32 dummy[8];
} TexObj;

extern s32 fn_80006334(u8 *);
extern s16 lbl_801A66EC;
extern GlyphEntry lbl_8015B940[];
extern void GXInitTexObj(TexObj *, void *, u16, u16, s32, s32, s32, u8);
extern void GXInvalidateTexAll(void);
extern void fn_80073778(void *, s32);
extern void fn_8003462C(u32, u32, u32);

/* GX write-gather FIFO: every store is a hardware write, hence volatile */
#define GXWGFifo (*(volatile union { f32 f; u32 u; } *)GX_FIFO_BASE)

static inline GlyphEntry *FindGlyph(s32 c) {
    GlyphEntry *e = lbl_8015B940;
    s32 i;
    for (i = 0; i < lbl_801A66EC; i++, e++) {
        if (e->code == c) {
            return e;
        }
    }
    return NULL;
}

void fn_800060D8(u8 *s, f32 x, f32 y, f32 z) {
    TexObj obj;
    GlyphEntry *e;
    u32 c;
    f32 x2;
    f32 nz = -z;
    f32 y2;

    while (*s != 0) {
        if (fn_80006334(s)) {
            c = *(u16 *)s;
            s += 2;
        } else {
            c = *s;
            s += 1;
        }
        if (c == ' ') {
            x += 8.0;
            continue;
        }
        e = FindGlyph(c);
        if (e == NULL) {
            continue;
        }
        GXInitTexObj(&obj, e->image, 24, 24, 0, 0, 0, 0);
        GXInvalidateTexAll();
        fn_80073778(&obj, 0);
        y2 = y + 24.0;
        x2 = x + (f32)e->width;
        fn_8003462C(0x80, 7, 4);
        GXWGFifo.f = x;
        GXWGFifo.f = y;
        GXWGFifo.f = nz;
        GXWGFifo.f = 0.0f;
        GXWGFifo.f = 0.0f;
        GXWGFifo.f = x2;
        GXWGFifo.f = y;
        GXWGFifo.f = nz;
        GXWGFifo.f = e->width / 24.0;
        GXWGFifo.f = 0.0f;
        GXWGFifo.f = x2;
        GXWGFifo.f = y2;
        GXWGFifo.f = nz;
        GXWGFifo.f = e->width / 24.0;
        GXWGFifo.f = 1.0f;
        GXWGFifo.f = x;
        GXWGFifo.f = y2;
        GXWGFifo.f = nz;
        GXWGFifo.f = 0.0f;
        GXWGFifo.f = 1.0f;
        x += (f32)e->width;
    }
}
