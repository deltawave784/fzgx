#include "types.h"
#pragma pool_strings on

typedef struct Sig___num2dec_decform {
    char style;
    char reserved;
    s16 digits;
} Sig___num2dec_decform;
typedef struct Sig___num2dec_decimal {
    char sign;
    char reserved;
    s16 exp;
    struct {
        u8 length;
        u8 text[36];
        u8 reserved;
    } sig;
} Sig___num2dec_decimal;

typedef struct {
    unsigned char justification, sign, precision_specified, alternate_form, argument_options, conversion_char;
    int field_width, precision;
} print_format;

extern void __num2dec(const Sig___num2dec_decform *, f64, Sig___num2dec_decimal *);
extern const f64 lbl_801A74E8;
extern u8 lbl_8015B100[256];
extern char *fn_80083DB0(char *, const char *);
extern void fn_800818C8(Sig___num2dec_decimal *, int);

static const char *float2str_pool_primer(void) { return ""; }

/* `format` is passed by value: the caller builds a copy and passes its address. */
char *float2str(f64 num, char *buff, print_format format) {
    Sig___num2dec_decform form;
    Sig___num2dec_decimal dec;
    int integral;
    int fractional;
    int n;
    char *p;
    int digits;
    char *q;
    int j;
    int fill;
    char sign;

    if (format.precision > 509)
        return 0;
    form.style = 0;
    form.digits = 32;
    __num2dec(&form, num, &dec);
    p = (char *)dec.sig.text + dec.sig.length;
    while (dec.sig.length > 1 && *--p == '0') {
        --dec.sig.length;
        ++dec.exp;
    }
    switch (dec.sig.text[0]) {
    case '0':
        dec.exp = 0;
        break;
    case 'I':
        if (num < lbl_801A74E8) {
            buff -= 5;
            if (lbl_8015B100[format.conversion_char] & 0x80)
                fn_80083DB0(buff, "-INF");
            else
                fn_80083DB0(buff, "-inf");
        } else {
            buff -= 4;
            if (lbl_8015B100[format.conversion_char] & 0x80)
                fn_80083DB0(buff, "INF");
            else
                fn_80083DB0(buff, "inf");
        }
        return buff;
    case 'N':
        if (dec.sign) {
            buff -= 5;
            if (lbl_8015B100[format.conversion_char] & 0x80)
                fn_80083DB0(buff, "-NAN");
            else
                fn_80083DB0(buff, "-nan");
        } else {
            buff -= 4;
            if (lbl_8015B100[format.conversion_char] & 0x80)
                fn_80083DB0(buff, "NAN");
            else
                fn_80083DB0(buff, "nan");
        }
        return buff;
    }
    dec.exp += dec.sig.length - 1;
    q = buff - 1;
    *q = 0;
    switch (format.conversion_char) {
    case 'g':
    case 'G':
        if (dec.sig.length > format.precision)
            fn_800818C8(&dec, format.precision);
        if (dec.exp < -4 || dec.exp >= format.precision) {
            if (format.alternate_form)
                --format.precision;
            else
                format.precision = dec.sig.length - 1;
            if (format.conversion_char == 'g')
                format.conversion_char = 'e';
            else
                format.conversion_char = 'E';
            goto e_format; /* shared exponential emitter */
        } else {
            if (format.alternate_form)
                format.precision -= dec.exp + 1;
            else {
                if ((format.precision = dec.sig.length - (dec.exp + 1)) < 0)
                    format.precision = 0;
            }
            goto f_format; /* shared fixed emitter */
        }
    case 'e':
    case 'E':
    e_format:
        if (dec.sig.length > format.precision + 1)
            fn_800818C8(&dec, format.precision + 1);
        n = dec.exp;
        sign = '+';
        if (n < 0) {
            n = -n;
            sign = '-';
        }
        digits = 0;
        while (n != 0 || digits < 2) {
            *--q = n % 10 + '0';
            n /= 10;
            ++digits;
        }
        *--q = sign;
        *--q = format.conversion_char;
        if (format.precision + (buff - q) > 509)
            return 0;
        if (dec.sig.length < format.precision + 1) {
            n = format.precision + 2 - dec.sig.length;
            while (--n)
                *--q = '0';
        }
        {
            char *s = (char *)dec.sig.text + dec.sig.length;
            n = dec.sig.length;
            while (--n)
                *--q = *--s;
        }
        if (format.precision || format.alternate_form)
            *--q = '.';
        *--q = dec.sig.text[0];
        if (dec.sign)
            *--q = '-';
        else if (format.sign == 1)
            *--q = '+';
        else if (format.sign == 2)
            *--q = ' ';
        break;
    case 'f':
    case 'F':
    f_format:
        fractional = dec.sig.length - dec.exp - 1;
        if (fractional < 0)
            fractional = 0;
        if (fractional > format.precision) {
            fn_800818C8(&dec, dec.sig.length - (fractional - format.precision));
            fractional = dec.sig.length - dec.exp - 1;
            if (fractional < 0)
                fractional = 0;
        }
        integral = dec.exp + 1;
        if (integral < 0)
            integral = 0;
        if (integral + fractional > 509)
            return 0;
        n = dec.sig.length;
        p = (char *)dec.sig.text + n;
        for (j = 0; j < format.precision - fractional; ++j)
            *--q = '0';
        for (j = 0; j < fractional && j < dec.sig.length; ++j)
            *--q = *--p;
        for (; j < fractional; ++j)
            *--q = '0';
        if (format.precision || format.alternate_form)
            *--q = '.';
        if (integral) {
            for (j = 0; j < integral - dec.sig.length; ++j)
                *--q = '0';
            for (; j < integral; ++j)
                *--q = *--p;
        } else {
            *--q = '0';
        }
        if (dec.sign)
            *--q = '-';
        else if (format.sign == 1)
            *--q = '+';
        else if (format.sign == 2)
            *--q = ' ';
        break;
    }
    return q;
}
