#ifndef S21_SPRINTF_HELPERS_H_
#define S21_SPRINTF_HELPERS_H_

#include <stdarg.h>

#include "../s21_string.h"

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

// Объявления функций
void init_flags(flags_t *flags);
void init_fmt(fmt_t *fmt);
char *parse_flags(const char *str, flags_t *flags);
void resolve_conflicts_flags(flags_t *flags);
char *parse_width(const char *str, va_list args, s21_size_t *result);
char *parse_precision(const char *str, va_list args, s21_size_t *result,
                      int *result_set);
char *parse_length(const char *str, char *result);
char *parse_type(const char *str, char *result);
char *parse_all_in_flag(const char *str, va_list args, fmt_t *fmt);

#endif  // S21_SPRINTF_HELPERS_H_