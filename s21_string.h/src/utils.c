#include "utils.h"

#include <ctype.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

char *parse_s21_size_t_from_str(const char *str, s21_size_t *result) {
  if (str == S21_NULL || result == S21_NULL) return S21_NULL;
  *result = 0;
  const char *buffer = str;
  while (isdigit((int)*buffer)) {
    *result = *result * 10 + (*buffer - '0');
    buffer++;
  }
  return (char *)buffer;
}

void reverse_str(char *str, int len) {
  for (int i = 0, j = len - 1; i < j; i++, j--) {
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
  }
}

void s21_size_t_to_string_with_base(char *str, s21_size_t num, int base) {
  if (base < 2 || base > 36) {
    str[0] = '\0';
    return;
  }
  const char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
  int i = 0;
  if (num == 0) {
    str[i++] = '0';
  } else {
    while (num > 0) {
      str[i++] = digits[num % base];
      num /= base;
    }
  }
  str[i] = '\0';
  reverse_str(str, i);
}

void s21_size_t_to_string(char *str, s21_size_t num) {
  s21_size_t_to_string_with_base(str, num, 10);
}

void to_upper_string(char *str) {
  while (*str) {
    if (*str >= 'a' && *str <= 'z') *str = toupper(*str);
    str++;
  }
}

void pointer_to_string(char *str, uintptr_t ptr) {
  if (ptr == (uintptr_t)S21_NULL)
    s21_strncpy(str, "(nil)", 6);
  else
    s21_size_t_to_string_with_base(str, ptr, 16);
}

static int is_negative(long double num) { return signbit(num); }

static long double get_rounder(s21_size_t precision) {
  long double rounder = 0.5L;
  for (s21_size_t i = 0; i < precision; i++) {
    rounder /= 10.0L;
  }
  return rounder;
}

static void get_int_and_frac_part(long double num, long double *int_part,
                                  long double *frac_part) {
  *frac_part = modfl(num, int_part);
}

static char *process_int_part(char *buffer, long double int_part_d) {
  __uint128_t int_part = (__uint128_t)int_part_d;
  int i = 0;
  if (int_part == 0)
    *buffer++ = '0';
  else {
    while (int_part > 0) {
      buffer[i++] = int_part % 10 + '0';
      int_part /= 10;
    }
    reverse_str(buffer, i);
  }
  return buffer + i;
}

static char *process_frac_part(char *buffer, long double frac_part,
                               s21_size_t precision) {
  if (precision > 0) {
    *buffer++ = '.';
    for (int i = 0; i < (long long)precision; i++) {
      frac_part *= 10;
      int digit = (int)frac_part;
      *buffer++ = '0' + digit;
      frac_part -= digit;
    }
  }
  return buffer;
}

static void __long_double_to_string(char *str, long double num,
                                    s21_size_t precision) {
  char *buffer = str;
  if (is_negative(num)) {
    num = -num;
    *buffer++ = '-';
  }
  num += get_rounder(precision);
  long double int_part;
  long double frac_part;
  get_int_and_frac_part(num, &int_part, &frac_part);
  buffer = process_int_part(buffer, int_part);
  buffer = process_frac_part(buffer, frac_part, precision);
  *buffer = '\0';
}

static int make_buffer_if_nan_or_inf(char *str, long double num) {
  int flag = 0;
  if (isnan(num)) {
    s21_strncpy(str, is_negative(num) ? "-nan" : "nan", 5);
    flag = 1;
  } else if (isinf(num) || num == INFINITY || num == -INFINITY) {
    s21_strncpy(str, is_negative(num) ? "-inf" : "inf", 5);
    flag = 1;
  }
  return flag;
}

void long_double_to_string(char *str, long double num, s21_size_t precision) {
  if (!make_buffer_if_nan_or_inf(str, num))
    __long_double_to_string(str, num, precision);
}

static void re_normalize(long double *num, int *exponent) {
  if (*num >= 10.0L) {
    *num /= 10.0L;
    *exponent += 1;
  }
}

static int get_exponent(long double *abs_normalized) {
  int exponent = 0;
  while (*abs_normalized >= 10.0L) {
    *abs_normalized /= 10.0L;
    exponent++;
  }
  while (*abs_normalized < 1.0L && *abs_normalized != 0.0L) {
    *abs_normalized *= 10.0L;
    exponent--;
  }
  re_normalize(abs_normalized, &exponent);
  return exponent;
}

static void __long_double_to_scientific(char *str, long double num,
                                        s21_size_t precision) {
  if (is_negative(num)) {
    num = -num;
    *str++ = '-';
  }
  int exponent = get_exponent(&num);
  num += get_rounder(precision);
  re_normalize(&num, &exponent);
  long double int_part;
  long double frac_part;
  get_int_and_frac_part(num, &int_part, &frac_part);
  str = process_int_part(str, int_part);
  str = process_frac_part(str, frac_part, precision);
  *str++ = 'e';
  if (exponent < 0) {
    *str++ = '-';
    exponent = -exponent;
  } else
    *str++ = '+';
  if (exponent < 10) *str++ = '0';
  str = process_int_part(str, (long double)exponent);
  *str = '\0';
}

void long_double_to_scientific(char *str, long double num,
                               s21_size_t precision) {
  if (!make_buffer_if_nan_or_inf(str, num))
    __long_double_to_scientific(str, num, precision);
}

static s21_size_t get_precision(s21_size_t precision) {
  if (precision == 0) precision = 1;
  return precision;
}

static int is_scientific(int exponent, s21_size_t precision) {
  int use_scientific = 0;
  if (exponent < -4 || exponent >= (int)precision) use_scientific = 1;
  return use_scientific;
}

static void process_auto_if_scientific(char *buffer, long double num,
                                       s21_size_t precision, int hash_flag) {
  if (hash_flag) {
    __long_double_to_scientific(buffer, num, precision - 1);
    return;
  }
  __long_double_to_scientific(buffer, num, precision - 1);
  const char *e_pos = s21_strchr(buffer, 'e');
  const char *dot_pos = s21_strchr(buffer, '.');
  if (dot_pos < e_pos) {
    char *ptr = (char *)(e_pos - 1);
    while (ptr > dot_pos && *ptr == '0') *ptr-- = '\0';
    if (ptr == dot_pos) *ptr = '\0';
  }
}

static void process_auto_if_not_scientific(char *buffer, long double num,
                                           int exponent, s21_size_t precision,
                                           int hash_flag) {
  if (hash_flag) {
    __long_double_to_string(
        buffer, num, (exponent < 0) ? precision - 1 : precision - 1 - exponent);
    return;
  }
  __long_double_to_string(
      buffer, num, (exponent < 0) ? precision - 1 : precision - 1 - exponent);
  const char *dot_pos = s21_strchr(buffer, '.');
  char *ptr = buffer + s21_strlen(buffer) - 1;
  while (ptr > dot_pos && *ptr == '0') {
    *ptr-- = '\0';
  }
  if (ptr == dot_pos) *ptr = '\0';
}

static void __long_double_to_string_auto(char *str, long double num,
                                         s21_size_t precision, int hash_flag) {
  if (is_negative(num)) {
    num = -num;
    *str++ = '-';
  }
  precision = get_precision(precision);
  double long num_exp = num;
  int exponent = get_exponent(&num_exp);
  int use_scientific = is_scientific(exponent, precision);
  if (use_scientific)
    process_auto_if_scientific(str, num, precision, hash_flag);
  else
    process_auto_if_not_scientific(str, num, exponent, precision, hash_flag);
}

void long_double_to_string_auto(char *str, long double num,
                                s21_size_t precision, int hash_flag) {
  if (!make_buffer_if_nan_or_inf(str, num))
    __long_double_to_string_auto(str, num, precision, hash_flag);
}