#include <ctype.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <wchar.h>

#include "../s21_string.h"
#include "../utils.h"

#define MAX_NUM_STR_LEN 64
#define NUMBER_ASCII 128

#define UPPER 1
#define NOT_UPPER 0

#define FLT_FULL 1
#define FLT_SCIEN 2
#define FLT_AUTO 3

typedef struct {
  int left_alignment;
  int sign;
  int space;
  int base;
  int fill;
} flags_t;

typedef struct {
  flags_t flags;
  s21_size_t width;
  s21_size_t precision;
  int precision_set;
  char length;
  char type;
} fmt_t;

typedef void (*process_func_t)(char *, va_list, const fmt_t *, s21_size_t *);

void init_process_array(process_func_t *array_of_funcs) {
  for (int i = 0; i < NUMBER_ASCII; i++) {
    array_of_funcs[i] = (process_func_t)S21_NULL;
  }
}

void register_process_func(process_func_t *array_of_funcs, char flag,
                           process_func_t func) {
  array_of_funcs[(int)flag] = func;
}

void init_flags(flags_t *flags) {
  flags->left_alignment = 0;
  flags->sign = 0;
  flags->space = 0;
  flags->base = 0;
  flags->fill = 0;
}

void init_fmt(fmt_t *fmt) {
  init_flags(&fmt->flags);
  fmt->width = 0;
  fmt->precision = 0;
  fmt->precision_set = 0;
  fmt->length = 0;
  fmt->type = 0;
}

const char *parse_flags(const char *str, flags_t *flags) {
  const char *buffer = str;
  int flag = 1;

  while (*buffer && flag) {
    switch (*buffer) {
      case '-':
        flags->left_alignment = 1;
        break;
      case '+':
        flags->sign = 1;
        break;
      case ' ':
        flags->space = 1;
        break;
      case '#':
        flags->base = 1;
        break;
      case '0':
        flags->fill = 1;
        break;
      default:
        flag = 0;
    }
    if (flag) buffer++;
  }
  return buffer;
}

void resolve_conflicts_flags(flags_t *flags) {
  if (flags->left_alignment) flags->fill = 0;
  if (flags->sign) flags->space = 0;
}

const char *parse_width(const char *str, va_list args, s21_size_t *result) {
  const char *buffer = str;

  if (isdigit(*buffer)) {
    buffer = parse_s21_size_t_from_str(buffer, result);
  } else if (*buffer == '*') {
    *result = (s21_size_t)va_arg(args, s21_size_t);
    buffer++;
  }
  return buffer;
}

const char *parse_precision(const char *str, va_list args, s21_size_t *result,
                            int *result_set) {
  if (*str != '.') return str;

  const char *buffer = str;
  buffer++;

  if (isdigit(*buffer)) {
    buffer = parse_s21_size_t_from_str(buffer, result);
  } else if (*buffer == '*') {
    *result = (s21_size_t)va_arg(args, s21_size_t);
    buffer++;
  }
  *result_set = 1;
  return buffer;
}

const char *parse_length(const char *str, char *result) {
  const char *buffer = str;
  if (*str == 'h' || *str == 'l' || *str == 'L') {
    *result = *buffer++;
  }
  return buffer;
}

const char *parse_type(const char *str, char *result) {
  const char *buffer = str;
  *result = *buffer;
  return ++buffer;
}

const char *parse_all_in_flag(const char *str, va_list args, fmt_t *fmt) {
  const char *buffer = str;

  buffer = parse_flags(buffer, &fmt->flags);
  resolve_conflicts_flags(&fmt->flags);
  buffer = parse_width(buffer, args, &fmt->width);
  buffer = parse_precision(buffer, args, &fmt->precision, &fmt->precision_set);
  buffer = parse_length(buffer, &fmt->length);
  buffer = parse_type(buffer, &fmt->type);

  return buffer;
}

void format_char_with_width_and_left_alignment(char *buffer, char ch,
                                               s21_size_t width,
                                               s21_size_t *len) {
  buffer[(*len)++] = ch;
  s21_memset(buffer + *len, ' ', width - 1);
  *len += width - 1;
}

void format_char_with_width(char *buffer, char ch, s21_size_t width,
                            s21_size_t *len) {
  s21_memset(buffer + *len, ' ', width - 1);
  *len += width - 1;
  buffer[(*len)++] = ch;
}

void format_char(char *buffer, char ch, s21_size_t *len) {
  buffer[(*len)++] = ch;
}

void process_char(char *buffer, va_list args, const fmt_t *fmt,
                  s21_size_t *len) {
  char ch = (char)va_arg(args, int);

  if (fmt->width && fmt->flags.left_alignment) {
    format_char_with_width_and_left_alignment(buffer, ch, fmt->width, len);
  } else if (fmt->width) {
    format_char_with_width(buffer, ch, fmt->width, len);
  } else {
    format_char(buffer, ch, len);
  }
}

const char *get_processed_string(const char *str, const fmt_t *fmt) {
  if (str != S21_NULL) return str;

  str = "(null)";
  if (fmt->precision_set && fmt->precision <= s21_strlen("(null)") - 1) {
    str = "";
  }
  return str;
}

s21_size_t calculate_string_len(const char *str, const fmt_t *fmt) {
  s21_size_t result = s21_strlen(str);
  if (fmt->precision_set) {
    result = result > fmt->precision ? fmt->precision : result;
  }
  return result;
}

s21_size_t calculate_padding(const fmt_t *fmt, s21_size_t string_len) {
  s21_size_t padding = 0;
  if (fmt->width > string_len) {
    padding = fmt->width - string_len;
  }
  return padding;
}

s21_size_t format_string_with_left_alignment(char *buffer, const char *string,
                                             s21_size_t string_len,
                                             s21_size_t padding) {
  s21_size_t offset = 0;
  s21_memcpy(buffer, string, string_len);
  offset += string_len;

  if (padding) {
    s21_memset(buffer + string_len, ' ', padding);
    offset += padding;
  }
  return offset;
}

s21_size_t format_string(char *buffer, const char *string,
                         s21_size_t string_len, s21_size_t padding) {
  s21_size_t offset = 0;

  if (padding) {
    s21_memset(buffer, ' ', padding);
    offset += padding;
  }
  s21_memcpy(buffer + padding, string, string_len);
  offset += string_len;

  return offset;
}

void process_string(char *buffer, va_list args, const fmt_t *fmt,
                    s21_size_t *len) {
  const char *string = (const char *)va_arg(args, char *);
  string = get_processed_string(string, fmt);
  s21_size_t string_len = calculate_string_len(string, fmt);
  s21_size_t padding = calculate_padding(fmt, string_len);

  if (fmt->flags.left_alignment) {
    *len += format_string_with_left_alignment(buffer + *len, string, string_len,
                                              padding);
  } else {
    *len += format_string(buffer + *len, string, string_len, padding);
  }
}

char get_sign(int is_negative, const fmt_t *fmt) {
  char sign = 0;

  if (is_negative) {
    sign = '-';
  } else if (fmt->flags.sign) {
    sign = '+';
  } else if (fmt->flags.space) {
    sign = ' ';
  }
  return sign;
}

void handle_zero_precision_case(char *num_string, s21_size_t num,
                                const fmt_t *fmt) {
  if (fmt->precision_set && fmt->precision == 0 && num == 0) {
    num_string[0] = '\0';
  }
}

s21_size_t get_num_zeros(s21_size_t len_buffer, const fmt_t *fmt) {
  s21_size_t num_zeros = 0;
  if (fmt->precision_set && fmt->precision > len_buffer) {
    num_zeros = fmt->precision - len_buffer;
  }
  return num_zeros;
}

s21_size_t get_padding(s21_size_t total_len, const fmt_t *fmt) {
  return fmt->width > total_len ? fmt->width - total_len : 0;
}

char get_fill(const fmt_t *fmt) {
  return (fmt->flags.fill && !fmt->flags.left_alignment && !fmt->precision_set)
             ? '0'
             : ' ';
}

s21_size_t format_integer_with_left_alignment(char *buffer,
                                              const char *num_string, char sign,
                                              s21_size_t len_buffer,
                                              s21_size_t num_zeros,
                                              s21_size_t padding) {
  s21_size_t offset = 0;

  if (sign) buffer[offset++] = sign;
  if (num_zeros) {
    s21_memset(buffer + offset, '0', num_zeros);
    offset += num_zeros;
  }
  s21_memcpy(buffer + offset, num_string, len_buffer);
  offset += len_buffer;

  if (padding) {
    s21_memset(buffer + offset, ' ', padding);
    offset += padding;
  }
  return offset;
}

s21_size_t format_integer_without_left_alignment(
    char *buffer, const char *num_string, char sign, s21_size_t len_buffer,
    s21_size_t num_zeros, s21_size_t padding, char fill) {
  s21_size_t offset = 0;

  if (fill == ' ') {
    s21_memset(buffer + offset, fill, padding);
    offset += padding;
  }
  if (sign) buffer[offset++] = sign;
  if (fill == '0') {
    s21_memset(buffer + offset, fill, padding);
    offset += padding;
  }
  if (num_zeros) {
    s21_memset(buffer + offset, '0', num_zeros);
    offset += num_zeros;
  }
  s21_memcpy(buffer + offset, num_string, len_buffer);
  offset += len_buffer;

  return offset;
}

void format_integer(char *buffer, char *num_string, s21_size_t num,
                    int is_negative, const fmt_t *fmt, s21_size_t *len) {
  char sign = get_sign(is_negative, fmt);
  handle_zero_precision_case(num_string, num, fmt);

  s21_size_t len_buffer = s21_strlen(num_string);
  s21_size_t num_zeros = get_num_zeros(len_buffer, fmt);
  s21_size_t total_len = len_buffer + num_zeros;
  if (sign) total_len++;

  s21_size_t padding = get_padding(total_len, fmt);
  char fill = get_fill(fmt);

  if (fmt->flags.left_alignment) {
    *len += format_integer_with_left_alignment(buffer + *len, num_string, sign,
                                               len_buffer, num_zeros, padding);
  } else {
    *len += format_integer_without_left_alignment(
        buffer + *len, num_string, sign, len_buffer, num_zeros, padding, fill);
  }
}

void process_int(char *buffer, va_list args, const fmt_t *fmt,
                 s21_size_t *len) {
  long int num = 0;

  if (fmt->length == 'h') {
    num = (long int)((short int)va_arg(args, int));
  } else if (fmt->length == 'l') {
    num = va_arg(args, long);
  } else {
    num = (long int)va_arg(args, int);
  }

  int is_negative = 0;
  if (num < 0) {
    num = -num;
    is_negative = 1;
  }

  char num_string[MAX_NUM_STR_LEN];
  s21_size_t_to_string(num_string, num);
  format_integer(buffer, num_string, num, is_negative, fmt, len);
}

char *make_prefix_for_base(char *buffer, int base, const fmt_t *fmt) {
  if (!fmt->flags.base) return buffer;

  int len = 0;
  if (base == 8) {
    buffer[0] = '0';
    len = 1;
  } else {
    s21_strncpy(buffer, "0x", 2);
    len = 2;
  }
  return buffer + len;
}

void process_unsigned_integer(char *buffer, int base, int upper, va_list args,
                              const fmt_t *fmt, s21_size_t *len) {
  unsigned long int num = 0;

  if (fmt->length == 'h') {
    num = (unsigned long int)((unsigned short int)va_arg(args, unsigned int));
  } else if (fmt->length == 'l') {
    num = va_arg(args, unsigned long int);
  } else {
    num = (unsigned long int)va_arg(args, unsigned int);
  }

  char num_string[66];
  char *num_string_with_prefix = make_prefix_for_base(num_string, base, fmt);
  s21_size_t_to_string_with_base(num_string_with_prefix, num, base);

  if (upper) to_upper_string(num_string);
  format_integer(buffer, num_string, num, 0, fmt, len);
}

void process_unsigned_int(char *buffer, va_list args, const fmt_t *fmt,
                          s21_size_t *len) {
  process_unsigned_integer(buffer, 10, NOT_UPPER, args, fmt, len);
}

void process_hex_int(char *buffer, va_list args, const fmt_t *fmt,
                     s21_size_t *len) {
  process_unsigned_integer(buffer, 16, NOT_UPPER, args, fmt, len);
}

void process_hex_int_with_upper(char *buffer, va_list args, const fmt_t *fmt,
                                s21_size_t *len) {
  process_unsigned_integer(buffer, 16, UPPER, args, fmt, len);
}

void process_octal_int(char *buffer, va_list args, const fmt_t *fmt,
                       s21_size_t *len) {
  process_unsigned_integer(buffer, 8, NOT_UPPER, args, fmt, len);
}

void change_flags_to_correct_for_pointer(fmt_t *fmt) { fmt->flags.base = 1; }

void process_pointer(char *buffer, va_list args, const fmt_t *fmt,
                     s21_size_t *len) {
  uintptr_t ptr = va_arg(args, uintptr_t);
  fmt_t local_fmt = *fmt;
  change_flags_to_correct_for_pointer(&local_fmt);

  char num_string[100];
  char *num_string_with_prefix = num_string;
  if (ptr != (uintptr_t)S21_NULL) {
    num_string_with_prefix = make_prefix_for_base(num_string, 16, &local_fmt);
  }
  pointer_to_string(num_string_with_prefix, ptr);
  format_integer(buffer, num_string, ptr, 0, &local_fmt, len);
}

void process_procent(char *buffer, va_list args, const fmt_t *fmt,
                     s21_size_t *len) {
  (void)args;
  (void)fmt;
  buffer[(*len)++] = '%';
}

void process_number(char *buffer, va_list args, const fmt_t *fmt,
                    const s21_size_t *len) {
  (void)buffer;
  long int *num = 0;

  if (fmt->length == 'l') {
    num = (long int *)va_arg(args, long int *);
  } else if (fmt->length == 'h') {
    num = (long int *)((short int *)va_arg(args, int *));
  } else {
    num = (long int *)va_arg(args, int *);
  }
  *num = (long int)*len;
}

void resolve_precision_flag_for_float(fmt_t *fmt) {
  if (fmt->precision_set) return;
  fmt->precision = 6;
  fmt->precision_set = 1;
}

void resolve_flags_for_float(fmt_t *fmt) {
  fmt->precision_set = 0;
  fmt->precision = 0;
}

void float_to_string_with_mode(char *num_string, long double num,
                               s21_size_t precision, int mode,
                               const fmt_t *fmt) {
  if (mode == FLT_FULL) {
    long_double_to_string(num_string, num, precision);
  } else if (mode == FLT_SCIEN) {
    long_double_to_scientific(num_string, num, precision);
  } else {
    long_double_to_string_auto(num_string, num, precision, fmt->flags.base);
  }
}

void format_float(char *buffer, va_list args, const fmt_t *fmt, s21_size_t *len,
                  int upper, int mode) {
  long double num = 0;

  if (fmt->length == 'L') {
    num = va_arg(args, long double);
  } else {
    num = (long double)va_arg(args, double);
  }

  int is_neg = 0;
  if (num < 0.0L) {
    num = -num;
    is_neg = 1;
  }

  fmt_t local_fmt = *fmt;
  resolve_precision_flag_for_float(&local_fmt);
  char num_string[1000];
  float_to_string_with_mode(num_string, num, local_fmt.precision, mode, fmt);

  if (upper) to_upper_string(num_string);
  resolve_flags_for_float(&local_fmt);
  format_integer(buffer, num_string, 1, is_neg, &local_fmt, len);
}

void process_float(char *buffer, va_list args, const fmt_t *fmt,
                   s21_size_t *len) {
  format_float(buffer, args, fmt, len, NOT_UPPER, FLT_FULL);
}

void process_float_with_upper(char *buffer, va_list args, const fmt_t *fmt,
                              s21_size_t *len) {
  format_float(buffer, args, fmt, len, UPPER, FLT_FULL);
}

void process_float_scien(char *buffer, va_list args, const fmt_t *fmt,
                         s21_size_t *len) {
  format_float(buffer, args, fmt, len, NOT_UPPER, FLT_SCIEN);
}

void process_float_scien_with_upper(char *buffer, va_list args,
                                    const fmt_t *fmt, s21_size_t *len) {
  format_float(buffer, args, fmt, len, UPPER, FLT_SCIEN);
}

void process_float_auto(char *buffer, va_list args, const fmt_t *fmt,
                        s21_size_t *len) {
  format_float(buffer, args, fmt, len, NOT_UPPER, FLT_AUTO);
}

void process_float_auto_with_upper(char *buffer, va_list args, const fmt_t *fmt,
                                   s21_size_t *len) {
  format_float(buffer, args, fmt, len, UPPER, FLT_AUTO);
}

void register_all_funcs(process_func_t *array_of_funcs) {
  register_process_func(array_of_funcs, 'c', process_char);
  register_process_func(array_of_funcs, 's', process_string);
  register_process_func(array_of_funcs, 'd', process_int);
  register_process_func(array_of_funcs, 'i', process_int);
  register_process_func(array_of_funcs, 'u', process_unsigned_int);
  register_process_func(array_of_funcs, 'x', process_hex_int);
  register_process_func(array_of_funcs, 'X', process_hex_int_with_upper);
  register_process_func(array_of_funcs, 'o', process_octal_int);
  register_process_func(array_of_funcs, 'p', (process_func_t)process_pointer);
  register_process_func(array_of_funcs, '%', process_procent);
  register_process_func(array_of_funcs, 'n', (process_func_t)process_number);
  register_process_func(array_of_funcs, 'f', process_float);
  register_process_func(array_of_funcs, 'F', process_float_with_upper);
  register_process_func(array_of_funcs, 'e', process_float_scien);
  register_process_func(array_of_funcs, 'E', process_float_scien_with_upper);
  register_process_func(array_of_funcs, 'g', process_float_auto);
  register_process_func(array_of_funcs, 'G', process_float_auto_with_upper);
}

void process_type(process_func_t *array_of_funcs, char *buffer, va_list args,
                  const fmt_t *fmt, s21_size_t *len) {
  process_func_t func = array_of_funcs[(int)fmt->type];
  if (func) {
    func(buffer, args, fmt, len);
  }
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  const char *fmt_str = format;
  s21_size_t len = 0;
  process_func_t array_of_funcs[NUMBER_ASCII];

  init_process_array(array_of_funcs);
  register_all_funcs(array_of_funcs);

  while (*fmt_str) {
    if (*fmt_str != '%') {
      str[len++] = *fmt_str++;
    } else {
      fmt_str++;
      fmt_t fmt;
      init_fmt(&fmt);
      fmt_str = parse_all_in_flag(fmt_str, args, &fmt);
      process_type(array_of_funcs, str, args, &fmt, &len);
    }
  }
  str[len] = '\0';
  va_end(args);
  return len;
}