#include <check.h>
#include <stdarg.h>
#include <string.h>

#include "../s21_string.h"
#include "s21_sprintf_helpers.h"

// Универсальная обёртка для тестирования
static void test_parse_wrapper(const char *format, fmt_t *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  parse_all_in_flag(format, args, fmt);
  va_end(args);
}

START_TEST(test_parse_all_in_flag_full_format) {
  fmt_t fmt;
  init_fmt(&fmt);
  const char *full_fmt = "-+#05.10hd";

  test_parse_wrapper(full_fmt, &fmt, 5, 10);  // width=5, precision=10

  ck_assert_int_eq(fmt.flags.left_alignment, 1);
  ck_assert_int_eq(fmt.flags.sign, 1);
  ck_assert_int_eq(fmt.flags.space, 0);
  ck_assert_int_eq(fmt.flags.base, 1);
  ck_assert_int_eq(fmt.flags.fill, 0);
  ck_assert_int_eq(fmt.width, 5);
  ck_assert_int_eq(fmt.precision, 10);
  ck_assert_int_eq(fmt.precision_set, 1);
  ck_assert_int_eq(fmt.length, 'h');
  ck_assert_int_eq(fmt.type, 'd');
}
END_TEST

START_TEST(test_parse_all_in_flag_minimal_format) {
  fmt_t fmt;
  init_fmt(&fmt);
  const char *min_fmt = "s";

  // Для форматов без числовых параметров
  test_parse_wrapper(min_fmt, &fmt);  // Без дополнительных аргументов

  ck_assert_int_eq(fmt.type, 's');
  ck_assert_int_eq(fmt.width, 0);
  ck_assert_int_eq(fmt.precision, 0);
  ck_assert_int_eq(fmt.precision_set, 0);
}
END_TEST

START_TEST(test_parse_all_in_flag_no_precision) {
  fmt_t fmt;
  init_fmt(&fmt);
  const char *no_prec_fmt = "08lx";

  test_parse_wrapper(no_prec_fmt, &fmt, 8, 0);  // width=8, precision=0

  ck_assert_int_eq(fmt.flags.fill, 1);
  ck_assert_int_eq(fmt.width, 8);
  ck_assert_int_eq(fmt.precision, 0);
  ck_assert_int_eq(fmt.precision_set, 0);
  ck_assert_int_eq(fmt.length, 'l');
  ck_assert_int_eq(fmt.type, 'x');
}
END_TEST

START_TEST(test_parse_all_in_flag_invalid_format) {
  fmt_t fmt;
  init_fmt(&fmt);
  const char *invalid_fmt = "abc";

  test_parse_wrapper(invalid_fmt, &fmt);  // Без дополнительных аргументов

  ck_assert_int_eq(fmt.type, 'a');
}
END_TEST

Suite *format_parsing_suite(void) {
  Suite *s = suite_create("Format Parsing");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_parse_all_in_flag_full_format);
  tcase_add_test(tc, test_parse_all_in_flag_minimal_format);
  tcase_add_test(tc, test_parse_all_in_flag_no_precision);
  tcase_add_test(tc, test_parse_all_in_flag_invalid_format);

  suite_add_tcase(s, tc);
  return s;
}