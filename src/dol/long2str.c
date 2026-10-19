#include "types.h"

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

char *long2str(s32 num, char *buff, format_options *format) {
    u32 unsigned_num = num;
    u32 base;
    char *p = buff;
    struct { u8 value; } conversion;
    s32 n;
    s32 digits;
    s32 minus;
    minus = 0;
    *--p = 0;
    digits = 0;
    if (num == 0 && format->precision == 0 &&
        (!format->alternate || format->conversion != 'o'))
        return p;
    switch (format->conversion) {
    case 'd':
    case 'i':
        base = 10;
        if (num < 0) {
            unsigned_num = -unsigned_num;
            minus = 1;
        }
        break;
    case 'o':
        base = 8;
        format->sign = 0;
        break;
    case 'u':
        base = 10;
        format->sign = 0;
        break;
    case 'x':
    case 'X':
        base = 16;
        format->sign = 0;
        break;
    }
    conversion.value = format->conversion;
    do {
        n = unsigned_num / base;
        n *= base;
        n = unsigned_num - n;
        unsigned_num /= base;
        if (n < 10)
            n += '0';
        else if (conversion.value == 'x')
            n += 'a' - 10;
        else
            n += 'A' - 10;
        *--p = n;
        ++digits;
    } while (unsigned_num != 0);
    if (base == 8 && format->alternate && *p != '0') {
        *--p = '0';
        ++digits;
    }
    if (format->justification == 2) {
        format->precision = format->width;
        if (minus || format->sign)
            --format->precision;
        if (base == 16 && format->alternate)
            format->precision -= 2;
    }
    if (format->precision + (buff - p) > 509)
        return 0;
    {
        s32 precision = format->precision;
        for (; digits < precision; ++digits)
            *--p = '0';
    }
    if (base == 16 && format->alternate) {
        *--p = format->conversion;
        *--p = '0';
    }
    if (minus)
        *--p = '-';
    else if (format->sign == 1)
        *--p = '+';
    else if (format->sign == 2)
        *--p = ' ';
    return p;
}
