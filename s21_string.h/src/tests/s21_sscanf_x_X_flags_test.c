#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_string.h"

START_TEST(test_s21_sscanf_x_empty) {
  const char *input = "";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%x", &a), sscanf(input, "%x", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_x_simple) {
  const char *input = "abc";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%x", &a), sscanf(input, "%x", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_x_upper_case) {
  const char *input = "ABC";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%x", &a), sscanf(input, "%x", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_x_with_prefix) {
  const char *input = "0xabc";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%x", &a), sscanf(input, "%x", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_x_with_upper_prefix) {
  const char *input = "0XABC";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%x", &a), sscanf(input, "%x", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_x_mixed_case) {
  const char *input = "aBc";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%x", &a), sscanf(input, "%x", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_x_multiple) {
  const char *input = "abc 123 def";
  unsigned int a1 = 0, a2 = 0, a3 = 0;
  unsigned int b1 = 0, b2 = 0, b3 = 0;
  ck_assert_int_eq(s21_sscanf(input, "%x%x%x", &a1, &a2, &a3),
                   sscanf(input, "%x%x%x", &b1, &b2, &b3));
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
}
END_TEST

START_TEST(test_s21_sscanf_x_with_text) {
  const char *input = "Hex: abc, Next: 123";
  unsigned int a1 = 0, a2 = 0;
  unsigned int b1 = 0, b2 = 0;
  ck_assert_int_eq(s21_sscanf(input, "Hex: %x, Next: %x", &a1, &a2),
                   sscanf(input, "Hex: %x, Next: %x", &b1, &b2));
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
}
END_TEST

START_TEST(test_s21_sscanf_x_leading_whitespace) {
  const char *input = "   \t\n\r\v\f abc";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%x", &a), sscanf(input, "%x", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_x_trailing_whitespace) {
  const char *input = "abc   \t\n\r\v\f";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%x", &a), sscanf(input, "%x", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_x_max_uint) {
  const char *input = "ffffffff";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%x", &a), sscanf(input, "%x", &b));
  ck_assert_uint_eq(a, b);
  ck_assert_uint_eq(a, UINT_MAX);
}
END_TEST

START_TEST(test_s21_sscanf_x_invalid_input) {
  const char *input = "xyz123";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%x", &a), sscanf(input, "%x", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_x_mixed_input) {
  const char *input = "123xyz456";
  unsigned int a1 = 0, a2 = 0;
  unsigned int b1 = 0, b2 = 0;
  ck_assert_int_eq(s21_sscanf(input, "%xxyz%x", &a1, &a2),
                   sscanf(input, "%xxyz%x", &b1, &b2));
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
}
END_TEST

START_TEST(test_s21_sscanf_x_zero) {
  const char *input = "0";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%x", &a), sscanf(input, "%x", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_x_leading_zeros) {
  const char *input = "000abc";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%x", &a), sscanf(input, "%x", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_x_width) {
  const char *input = "123abc";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%3x", &a), sscanf(input, "%3x", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_x_star) {
  const char *input = "abc 123";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%*x %x", &a),
                   sscanf(input, "%*x %x", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_X_simple) {
  const char *input = "abc";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%X", &a), sscanf(input, "%X", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_X_upper_case) {
  const char *input = "ABC";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%X", &a), sscanf(input, "%X", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_X_with_prefix) {
  const char *input = "0xabc";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%X", &a), sscanf(input, "%X", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_hx_simple) {
  const char *input = "abc";
  unsigned short a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%hx", &a), sscanf(input, "%hx", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_lx_simple) {
  const char *input = "abcdef12";
  unsigned long a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%lx", &a), sscanf(input, "%lx", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

Suite *s21_sscanf_x_X_suite(void) {
  Suite *s = suite_create("s21_sscanf_x");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_sscanf_x_empty);
  tcase_add_test(tc, test_s21_sscanf_x_simple);
  tcase_add_test(tc, test_s21_sscanf_x_upper_case);
  tcase_add_test(tc, test_s21_sscanf_x_with_prefix);
  tcase_add_test(tc, test_s21_sscanf_x_with_upper_prefix);
  tcase_add_test(tc, test_s21_sscanf_x_mixed_case);
  tcase_add_test(tc, test_s21_sscanf_x_multiple);
  tcase_add_test(tc, test_s21_sscanf_x_with_text);
  tcase_add_test(tc, test_s21_sscanf_x_leading_whitespace);
  tcase_add_test(tc, test_s21_sscanf_x_trailing_whitespace);
  tcase_add_test(tc, test_s21_sscanf_x_max_uint);
  tcase_add_test(tc, test_s21_sscanf_x_invalid_input);
  tcase_add_test(tc, test_s21_sscanf_x_mixed_input);
  tcase_add_test(tc, test_s21_sscanf_x_zero);
  tcase_add_test(tc, test_s21_sscanf_x_leading_zeros);
  tcase_add_test(tc, test_s21_sscanf_x_width);
  tcase_add_test(tc, test_s21_sscanf_x_star);

  tcase_add_test(tc, test_s21_sscanf_X_simple);
  tcase_add_test(tc, test_s21_sscanf_X_upper_case);
  tcase_add_test(tc, test_s21_sscanf_X_with_prefix);

  tcase_add_test(tc, test_s21_sscanf_hx_simple);
  tcase_add_test(tc, test_s21_sscanf_lx_simple);

  suite_add_tcase(s, tc);
  return s;
}