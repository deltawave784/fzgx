#include "types.h"
typedef struct Sig_fn_12_3DF08_MovieArgs {
    int a; int b; int c; int d; int pad[2];
} Sig_fn_12_3DF08_MovieArgs;
typedef struct Sig_fn_12_3DF08_MovieRect {
    int a; int b; int c; int d; int e; int f; int g;
} Sig_fn_12_3DF08_MovieRect;
void fn_12_3DF08(Sig_fn_12_3DF08_MovieRect *arg0, Sig_fn_12_3DF08_MovieArgs *arg1) {
    u32 v0;
    u32 v12;
    int v1;
    int v2;
    int v4;
    u32 v5;
    u32 v6;
    int advance;
    int skip;
    s32 v8;
    int width;
    u32 v11;
    s32 v13;
    u32 v14;
    u32 v15;
    u32 v16;
    int v9;
    int v10;
    int v7;
    u32 mask1;
    u32 mask2;
    v0 = arg0->d;
    v1 = arg1->b;
    v12 = v0 >> 2;
    width = v1 / 4;
    skip = arg1->d - v1;
    v13 = arg1->c / 4;
    v2 = arg1->a;
    v4 = arg0->a;
    v5 = v12 << 2;
    advance = v12 * 12;
    v6 = v12 << 4;
    skip = (skip << 4) & 0xFFFFFFC0;
    v7 = v4;
    v9 = v2;
    v8 = 0;
    while (v8 < v13) {
        for (v10 = 0; v10 < width; v10++) {
            v11 = *(u32 *)v7;
            v7 += v5;
            mask1 = (v11 & 0xFF000000) | ((v11 >> 8) & 0xFF00);
            mask2 = (v11 << 16) & 0xFF000000;
            mask2 |= (v11 & 0xFF) << 8;
            *(u32 *)(v9 + 0) &= mask1 | 0x00FF00FF;
            *(u32 *)(v9 + 4) &= mask2 | 0x00FF00FF;
            v14 = *(u32 *)v7;
            v7 += v5;
            mask1 = (v14 & 0xFF000000) | ((v14 >> 8) & 0xFF00);
            mask2 = (v14 << 16) & 0xFF000000;
            mask2 |= (v14 & 0xFF) << 8;
            *(u32 *)(v9 + 8) &= mask1 | 0x00FF00FF;
            *(u32 *)(v9 + 12) &= mask2 | 0x00FF00FF;
            v15 = *(u32 *)v7;
            v7 += v5;
            mask1 = (v15 & 0xFF000000) | ((v15 >> 8) & 0xFF00);
            mask2 = (v15 << 16) & 0xFF000000;
            mask2 |= (v15 & 0xFF) << 8;
            *(u32 *)(v9 + 16) &= mask1 | 0x00FF00FF;
            *(u32 *)(v9 + 20) &= mask2 | 0x00FF00FF;
            v16 = *(u32 *)v7;
            v7 += v5;
            v7 -= v6;
            v7 += 4;
            mask1 = (v16 & 0xFF000000) | ((v16 >> 8) & 0xFF00);
            mask2 = (v16 << 16) & 0xFF000000;
            mask2 |= (v16 & 0xFF) << 8;
            *(u32 *)(v9 + 24) &= mask1 | 0x00FF00FF;
            *(u32 *)(v9 + 28) &= mask2 | 0x00FF00FF;
            v9 += 64;
        }
        v7 += advance;
        v9 += skip;
        v8++;
    }
}
