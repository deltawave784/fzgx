#include "types.h"

extern signed short lbl_12_bss_6230[128];
extern signed short lbl_12_bss_61F0[32];

#pragma opt_common_subs off
void fn_12_FC04(void) {
    signed short *output = lbl_12_bss_6230;
    int i;
    int level;
    short code;
    long escape_count = 24;
    long entry_count = 16;

    for (i = 0; i < escape_count; i++)
        *output++ = 0x7f;
    {
    int fzgx_loop_level_339;
for (fzgx_loop_level_339 = 16; fzgx_loop_level_339 >= 11; fzgx_loop_level_339--) {
        code = (fzgx_loop_level_339 & 0xff) | 0xb00;
        *output++ = code;
        code = (-fzgx_loop_level_339 & 0xff) | 0xb00;
        *output++ = code;
    }
    level = fzgx_loop_level_339;
}
    {
    int fzgx_loop_level_521;
for (fzgx_loop_level_521 = 10; fzgx_loop_level_521 >= 8; fzgx_loop_level_521--) {
        code = (fzgx_loop_level_521 & 0xff) | 0xa00;
        for (i = 0; i < 2; i++)
            *output++ = code;
        code = (-fzgx_loop_level_521 & 0xff) | 0xa00;
        for (i = 0; i < 2; i++)
            *output++ = code;
    }
    level = fzgx_loop_level_521;
}
    {
    int fzgx_loop_level_774;
for (fzgx_loop_level_774 = 7; fzgx_loop_level_774 >= 5; fzgx_loop_level_774--) {
        code = (fzgx_loop_level_774 & 0xff) | 0x800;
        for (i = 0; i < 8; i++)
            *output++ = code;
        code = (-fzgx_loop_level_774 & 0xff) | 0x800;
        for (i = 0; i < 8; i++)
            *output++ = code;
    }
    level = fzgx_loop_level_774;
}
    {
    int fzgx_loop_level_1026;
for (fzgx_loop_level_1026 = 4; fzgx_loop_level_1026 >= 4; fzgx_loop_level_1026--) {
        code = (fzgx_loop_level_1026 & 0xff) | 0x700;
        for (i = 0; i < entry_count; i++)
            *output++ = code;
        code = (-fzgx_loop_level_1026 & 0xff) | 0x700;
        for (i = 0; i < entry_count; i++)
            *output++ = code;
    }
    level = fzgx_loop_level_1026;
}

    output = lbl_12_bss_61F0;
    for (i = 0; i < 2; i++)
        *output++ = 0x7f;
{ long tail0;
    for (tail0 = 3; tail0 >= 3; tail0--) {
        code = (tail0 & 0xff) | 0x500;
        *output++ = code;
        code = (-tail0 & 0xff) | 0x500;
        *output++ = code;
    }
}
{ long tail1;
    for (tail1 = 2; tail1 >= 2; tail1--) {
        code = (tail1 & 0xff) | 0x400;
        for (i = 0; i < 2; i++)
            *output++ = code;
        code = (-tail1 & 0xff) | 0x400;
        for (i = 0; i < 2; i++)
            *output++ = code;
    }
}
{ long tail2;
    for (tail2 = 1; tail2 >= 1; tail2--) {
        code = (tail2 & 0xff) | 0x300;
        for (i = 0; i < 4; i++)
            *output++ = code;
        code = (-tail2 & 0xff) | 0x300;
        for (i = 0; i < 4; i++)
            *output++ = code;
    }
}
{ long tail3;
    for (tail3 = 0; tail3 >= 0; tail3--) {
        code = (tail3 & 0xff) | 0x100;
        {
            int fzgx_loop_i_2727;
            for (fzgx_loop_i_2727 = 0; fzgx_loop_i_2727 < entry_count; fzgx_loop_i_2727++)
                *output++ = code;
            i = fzgx_loop_i_2727;
        }
    }
}
}
#pragma opt_common_subs reset

