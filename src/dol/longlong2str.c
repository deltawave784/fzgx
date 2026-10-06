#include "types.h"
#pragma use_lmw_stmw on

typedef struct {
    u8 justification;
    u8 sign;
    u8 precision_set;
    u8 alternate;
    u8 length;
    u8 conversion;
    s32 width;
    s32 precision;
} format_options;

char *longlong2str(s64 arg0, char *arg2, format_options *arg3) {
    u64 v7 = arg0;
    u64 v3;
    char *v0 = arg2;
    s32 v18;
    s32 v6;
    s32 digit;
    v6 = 0;
    v18 = 0;
    *--v0 = 0;
    if (arg0 == 0 && arg3->precision == 0 &&
        (!arg3->alternate || arg3->conversion != 'o'))
        return v0;
    switch (arg3->conversion) {
    case 'd':
    case 'i':
        v3 = 10;
        if (arg0 < 0) {
            v7 = -v7;
            v6 = 1;
        }
        break;
    case 'o':
        v3 = 8;
        arg3->sign = 0;
        break;
    case 'u':
        v3 = 10;
        arg3->sign = 0;
        break;
    case 'x':
    case 'X':
        v3 = 16;
        arg3->sign = 0;
        break;
    }
    do {
        digit = v7 % v3;
        v7 /= v3;
        if (digit < 10)
            digit += '0';
        else if (arg3->conversion == 'x')
            digit += 'a' - 10;
        else
            digit += 'A' - 10;
        *--v0 = digit;
        ++v18;
    } while (v7 != 0);
    if (v3 == 8 && arg3->alternate && *v0 != '0') {
        ++v18;
        *--v0 = '0';
    }
    if (arg3->justification == 2) {
        arg3->precision = arg3->width;
        if (v6 || arg3->sign)
            --arg3->precision;
        if (v3 == 16 && arg3->alternate)
            arg3->precision -= 2;
    }
    if (arg3->precision + (arg2 - v0) > 509)
        return 0;
    { s32 precision = arg3->precision;
    for (; v18 < precision; ++v18)
        *--v0 = '0';
    }
    if (v3 == 16 && arg3->alternate) {
        *--v0 = arg3->conversion;
        *--v0 = '0';
    }
    if (v6)
        *--v0 = '-';
    else if (arg3->sign == 1)
        *--v0 = '+';
    else if (arg3->sign == 2)
        *--v0 = ' ';
    return v0;
}
