#include <check.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_sscanf_d_empty) {
  const char *input = "";
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%d", &a), sscanf(input, "%d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_d_simple) {
  const char *input = "123";
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%d", &a), sscanf(input, "%d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_d_negative) {
  const char *input = "-456";
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%d", &a), sscanf(input, "%d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_d_multiple) {
  const char *input = "789 012 -345";
  int a1 = 0, a2 = 0, a3 = 0;
  int b1 = 0, b2 = 0, b3 = 0;
  ck_assert_int_eq(s21_sscanf(input, "%d%d%d", &a1, &a2, &a3),
                   sscanf(input, "%d%d%d", &b1, &b2, &b3));
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
}
END_TEST

START_TEST(test_s21_sscanf_d_with_text) {
  const char *input = "Number: 42, Next: 73";
  int a1 = 0, a2 = 0;
  int b1 = 0, b2 = 0;
  ck_assert_int_eq(s21_sscanf(input, "Number: %d, Next: %d", &a1, &a2),
                   sscanf(input, "Number: %d, Next: %d", &b1, &b2));
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_s21_sscanf_d_leading_whitespace) {
  const char *input = "    \t\n\r\v\f 123";
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%d", &a), sscanf(input, "%d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_d_trailing_whitespace) {
  const char *input = "456   \t\n\r\v\f";
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%d", &a), sscanf(input, "%d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_d_max_int) {
  const char *input = "2147483647";
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%d", &a), sscanf(input, "%d", &b));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a, INT_MAX);
}
END_TEST

START_TEST(test_s21_sscanf_d_min_int) {
  const char *input = "-2147483648";
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%d", &a), sscanf(input, "%d", &b));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a, INT_MIN);
}
END_TEST

START_TEST(test_s21_sscanf_d_invalid_input) {
  const char *input = "abc123";
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%d", &a), sscanf(input, "%d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_d_mixed_input) {
  const char *input = "123abc456";
  int a1 = 0, a2 = 0;
  int b1 = 0, b2 = 0;
  ck_assert_int_eq(s21_sscanf(input, "%dabc%d", &a1, &a2),
                   sscanf(input, "%dabc%d", &b1, &b2));
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_s21_sscanf_d_zero) {
  const char *input = "0";
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%d", &a), sscanf(input, "%d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_d_leading_zeros) {
  const char *input = "000123";
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%d", &a), sscanf(input, "%d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_d_leading_plus) {
  const char *input = "+123";
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%d", &a), sscanf(input, "%d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_d_width) {
  const char *input = "123456";
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%3d", &a), sscanf(input, "%3d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_d_star) {
  const char *input = "123 456";
  int a = 0;
  ck_assert_int_eq(s21_sscanf(input, "%*d %d", &a),
                   sscanf(input, "%*d %d", &a));
}
END_TEST

START_TEST(test_s21_sscanf_d_width_3) {
  const char *input = "123456";
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%3d", &a), sscanf(input, "%3d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_d_width_5_overflow) {
  const char *input = "123456789";
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%5d", &a), sscanf(input, "%5d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_d_star_simple) {
  const char *input = "123 456";
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%*d %d", &a),
                   sscanf(input, "%*d %d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_d_star_multiple) {
  const char *input = "10 20 30 40";
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%*d %*d %d %*d", &a),
                   sscanf(input, "%*d %*d %d %*d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_hd_simple) {
  const char *input = "12345";
  short a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%hd", &a), sscanf(input, "%hd", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_ld_simple) {
  const char *input = "2147483648";
  long a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%ld", &a), sscanf(input, "%ld", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_ld_large) {
  const char *input = "9223372036854775807";
  long a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%ld", &a), sscanf(input, "%ld", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_d_width_star) {
  const char *input = "12345 67890";
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%3d %*d %*d", &a),
                   sscanf(input, "%3d %*d %*d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_ld_width) {
  const char *input = "123456789012345";
  long a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%10ld", &a), sscanf(input, "%10ld", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_hd_width_star) {
  const char *input = "32767 12345 99999";
  short a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%*d %4hd %*d", &a),
                   sscanf(input, "%*d %4hd %*d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_d_star_no_output) {
  const char *input = "123 456";
  ck_assert_int_eq(s21_sscanf(input, "%*d %*d"), sscanf(input, "%*d %*d"));
}
END_TEST

START_TEST(test_s21_sscanf_ld_hex_prefix) {
  const char *input = "0x123abc";
  long a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%ld", &a), sscanf(input, "%ld", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

Suite *s21_sscanf_d_suite(void) {
  Suite *s = suite_create("s21_sscanf_d");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_sscanf_d_empty);
  tcase_add_test(tc, test_s21_sscanf_d_simple);
  tcase_add_test(tc, test_s21_sscanf_d_negative);
  tcase_add_test(tc, test_s21_sscanf_d_multiple);
  tcase_add_test(tc, test_s21_sscanf_d_with_text);
  tcase_add_test(tc, test_s21_sscanf_d_leading_whitespace);
  tcase_add_test(tc, test_s21_sscanf_d_trailing_whitespace);
  tcase_add_test(tc, test_s21_sscanf_d_max_int);
  tcase_add_test(tc, test_s21_sscanf_d_min_int);
  tcase_add_test(tc, test_s21_sscanf_d_invalid_input);
  tcase_add_test(tc, test_s21_sscanf_d_mixed_input);
  tcase_add_test(tc, test_s21_sscanf_d_zero);
  tcase_add_test(tc, test_s21_sscanf_d_leading_zeros);
  tcase_add_test(tc, test_s21_sscanf_d_leading_plus);
  tcase_add_test(tc, test_s21_sscanf_d_width);
  tcase_add_test(tc, test_s21_sscanf_d_star);
  tcase_add_test(tc, test_s21_sscanf_d_width_3);
  tcase_add_test(tc, test_s21_sscanf_d_width_5_overflow);
  tcase_add_test(tc, test_s21_sscanf_d_star_simple);
  tcase_add_test(tc, test_s21_sscanf_d_star_multiple);
  tcase_add_test(tc, test_s21_sscanf_d_star_no_output);
  tcase_add_test(tc, test_s21_sscanf_hd_simple);
  tcase_add_test(tc, test_s21_sscanf_ld_simple);
  tcase_add_test(tc, test_s21_sscanf_ld_large);
  tcase_add_test(tc, test_s21_sscanf_ld_hex_prefix);
  tcase_add_test(tc, test_s21_sscanf_d_width_star);
  tcase_add_test(tc, test_s21_sscanf_ld_width);
  tcase_add_test(tc, test_s21_sscanf_hd_width_star);

  suite_add_tcase(s, tc);
  return s;
}