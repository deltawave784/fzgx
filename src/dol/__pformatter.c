#include "types.h"
typedef struct MkVaListState {
 signed char gpr; signed char fpr; unsigned short reserved;
 char *input_arg_area; char *reg_save_area;
} va_list[1];
typedef struct {
 unsigned char justification, sign, precision_specified, alternate_form, argument_options, conversion_char;
 int field_width, precision;
} print_format;
extern char *strchr(const char *, int);
extern size_t strlen(const char *);
extern const char *parse_format(const char *, va_list, print_format *);
extern void *__va_arg(va_list, int);
extern char *longlong2str(s64, char *, print_format *);
extern char *long2str(s32, char *, print_format *);
extern char *float2str(f64, char *, print_format *);
extern char *double2hex(f64, char *, print_format *);
extern size_t wcstombs(char *, const unsigned short *, size_t);
extern void *memchr(const void *, int, size_t);
extern char __null_string[];
#pragma opt_propagation off
#pragma pool_strings on
int __pformatter(void *(*WriteProc)(void *, const char *, size_t), void *WriteProcArg,
 const char *format_input, va_list arg) {
 const char * tmp_call5;
 char buff[512];
 print_format format;
 char padding = ' ';
 struct { char *value; } buffer_pointer;
#define buff_ptr buffer_pointer.value
 const char *format_ptr;
 const char *format_str = format_input;
 int num_chars = 0;
 int string_len;
 int field_len;
 s32 long_num;
 s64 long_long_num;
 f64 double_num;
 void *count_ptr;
 const unsigned short *wide_str;
 char *end;
 while (*format_str) {
  format_ptr = strchr(format_str, '%');
  if (!format_ptr) {
   string_len = strlen(format_str);
   num_chars += string_len;
   if (string_len && !WriteProc(WriteProcArg, format_str, string_len)) return -1;
   break;
  }
  string_len = format_ptr - format_str;
  num_chars += string_len;
  if (string_len && !WriteProc(WriteProcArg, format_str, string_len)) return -1;
  tmp_call5 = parse_format(format_ptr, arg, &format);
  format_str = tmp_call5;
  switch (format.conversion_char) {
  case 'd': case 'i':
   if (format.argument_options == 3) long_num = *(long *)__va_arg(arg, 1);
   else if (format.argument_options == 4) long_long_num = *(s64 *)__va_arg(arg, 2);
   else long_num = *(int *)__va_arg(arg, 1);
   if (format.argument_options == 2) long_num = (s16)long_num;
   if (format.argument_options == 1) long_num = (s8)long_num;
   if (format.argument_options == 4) {
    print_format copy;
    copy = format;
    if (!(buff_ptr = longlong2str(long_long_num, buff + 512, &copy))) /* Conversion failure shares the literal-format fallback. */ goto bad_format;
   } else {
    print_format copy;
    copy = format;
    if (!(buff_ptr = long2str(long_num, buff + 512, &copy))) /* Conversion failure shares the literal-format fallback. */ goto bad_format;
   }
   string_len = buff + 511 - buff_ptr;
   break;
  case 'o': case 'u': case 'x': case 'X':
   if (format.argument_options == 3) long_num = *(unsigned long *)__va_arg(arg, 1);
   else if (format.argument_options == 4) long_long_num = *(u64 *)__va_arg(arg, 2);
   else long_num = *(unsigned int *)__va_arg(arg, 1);
   if (format.argument_options == 2) long_num = (u16)long_num;
   if (format.argument_options == 1) long_num = (u8)long_num;
   if (format.argument_options == 4) {
    print_format copy;
    copy = format;
    if (!(buff_ptr = longlong2str(long_long_num, buff + 512, &copy))) /* Conversion failure shares the literal-format fallback. */ goto bad_format;
   } else {
    print_format copy;
    copy = format;
    if (!(buff_ptr = long2str(long_num, buff + 512, &copy))) /* Conversion failure shares the literal-format fallback. */ goto bad_format;
   }
   string_len = buff + 511 - buff_ptr;
   break;
  case 'f': case 'F': case 'e': case 'E': case 'g': case 'G': {
   print_format copy;
   if (format.argument_options == 5) double_num = *(long double *)__va_arg(arg, 3);
   else double_num = *(double *)__va_arg(arg, 3);
   copy = format;
   if (!(buff_ptr = float2str(double_num, buff + 512, &copy))) /* Conversion failure shares the literal-format fallback. */ goto bad_format;
   string_len = buff + 511 - buff_ptr;
   break;
  }
  case 'a': case 'A': {
   print_format copy;
   if (format.argument_options == 5) double_num = *(long double *)__va_arg(arg, 3);
   else double_num = *(double *)__va_arg(arg, 3);
   copy = format;
   if (!(buff_ptr = double2hex(double_num, buff + 512, &copy))) /* Conversion failure shares the literal-format fallback. */ goto bad_format;
   string_len = buff + 511 - buff_ptr;
   break;
  }
  case 's':
   if (format.argument_options == 6) {
    wide_str = *(unsigned short **)__va_arg(arg, 1);
    if (!wide_str) wide_str = (const unsigned short *)L"";
    if ((int)wcstombs(buff, wide_str, 512) < 0) /* Conversion failure shares the literal-format fallback. */ goto bad_format;
    buff_ptr = buff;
   } else buff_ptr = *(char **)__va_arg(arg, 1);
   if (!buff_ptr) buff_ptr = "";
   if (format.alternate_form) {
    string_len = (unsigned char)*buff_ptr++;
    if (format.precision_specified && string_len > format.precision) string_len = format.precision;
   } else if (format.precision_specified) {
    string_len = format.precision;
    end = memchr(buff_ptr, 0, string_len);
    if (end) string_len = end - buff_ptr;
   } else string_len = strlen(buff_ptr);
   break;
  case 'n':
   count_ptr = *(void **)__va_arg(arg, 1);
   switch (format.argument_options) {
    case 0: *(int *)count_ptr = num_chars; break;
    case 2: *(short *)count_ptr = num_chars; break;
    case 3: *(long *)count_ptr = num_chars; break;
    case 4: *(s64 *)count_ptr = num_chars; break;
   }
   continue;
  case 'c':
   buff_ptr = buff;
   buff[0] = *(int *)__va_arg(arg, 1);
   string_len = 1;
   break;
  case '%':
   buff[0] = '%';
   buff_ptr = buff;
   string_len = 1;
   break;
  case 0xff:
  default:
bad_format:
   string_len = strlen(format_ptr);
   num_chars += string_len;
   if (string_len && !WriteProc(WriteProcArg, format_ptr, string_len)) return -1;
   return num_chars;
  }
  field_len = string_len;
  if (format.justification != 0) {
   padding = format.justification == 2 ? '0' : ' ';
   if ((*buff_ptr == '+' || *buff_ptr == '-' || *buff_ptr == ' ') && padding == '0') {
    if (!WriteProc(WriteProcArg, buff_ptr, 1)) return -1;
    ++buff_ptr;
    --string_len;
   }
   while (field_len < format.field_width) {
    if (!WriteProc(WriteProcArg, &padding, 1)) return -1;
    ++field_len;
   }
  }
  if (string_len && !WriteProc(WriteProcArg, buff_ptr, string_len)) return -1;
  if (format.justification == 0) {
   while (field_len < format.field_width) {
    char space = ' ';
    if (!WriteProc(WriteProcArg, &space, 1)) return -1;
    ++field_len;
   }
  }
  num_chars += field_len;
 }
 return num_chars;
}
