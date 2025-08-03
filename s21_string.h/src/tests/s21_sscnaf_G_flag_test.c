#include <check.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_sscanf_G_empty) {
  const char *input = "";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%G", &a), sscanf(input, "%G", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_G_simple_float) {
  const char *input = "123.456";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%G", &a), sscanf(input, "%G", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_G_simple_exp) {
  const char *input = "1.234E5";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%G", &a), sscanf(input, "%G", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_G_negative) {
  const char *input = "-4.56E2";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%G", &a), sscanf(input, "%G", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_G_exp_positive) {
  const char *input = "1.23E+10";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%G", &a), sscanf(input, "%G", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_G_exp_negative) {
  const char *input = "1.23E-5";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%G", &a), sscanf(input, "%G", &b));
  ck_assert_float_eq_tol(a, b, 1e-7);
}
END_TEST

START_TEST(test_s21_sscanf_G_mixed) {
  const char *input = "7.89E1 0.12 3.45E3";
  float a1 = 0, a2 = 0, a3 = 0;
  float b1 = 0, b2 = 0, b3 = 0;
  ck_assert_int_eq(s21_sscanf(input, "%G%G%G", &a1, &a2, &a3),
                   sscanf(input, "%G%G%G", &b1, &b2, &b3));
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
}
END_TEST

START_TEST(test_s21_sscanf_G_with_text) {
  const char *input = "Value: 4.2E1, Next: 7.3";
  float a1 = 0, a2 = 0;
  float b1 = 0, b2 = 0;
  ck_assert_int_eq(s21_sscanf(input, "Value: %G, Next: %G", &a1, &a2),
                   sscanf(input, "Value: %G, Next: %G", &b1, &b2));
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
}
END_TEST

START_TEST(test_s21_sscanf_G_leading_whitespace) {
  const char *input = "    \t\n\r\v\f 1.23E1";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%G", &a), sscanf(input, "%G", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_G_trailing_whitespace) {
  const char *input = "4.56E2   \t\n\r\v\f";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%G", &a), sscanf(input, "%G", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_G_max_float) {
  const char *input = "3.4028235E38";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%G", &a), sscanf(input, "%G", &b));
  ck_assert_float_eq(a, b);
  ck_assert(a == FLT_MAX || isnan(b));
}
END_TEST

START_TEST(test_s21_sscanf_G_min_float) {
  const char *input = "1.1754944E-38";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%G", &a), sscanf(input, "%G", &b));
  ck_assert_float_eq(a, b);
  ck_assert(a == FLT_MIN || isnan(b));
}
END_TEST

START_TEST(test_s21_sscanf_G_invalid_input) {
  const char *input = "abc1.23E1";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%G", &a), sscanf(input, "%G", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_G_mixed_input) {
  const char *input = "1.23E1abc4.56E2";
  float a1 = 0, a2 = 0;
  float b1 = 0, b2 = 0;
  ck_assert_int_eq(s21_sscanf(input, "%Gabc%G", &a1, &a2),
                   sscanf(input, "%Gabc%G", &b1, &b2));
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
}
END_TEST

START_TEST(test_s21_sscanf_G_zero) {
  const char *input = "0.0";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%G", &a), sscanf(input, "%G", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_G_leading_zeros) {
  const char *input = "0001.23E1";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%G", &a), sscanf(input, "%G", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_G_leading_plus) {
  const char *input = "+1.23E1";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%G", &a), sscanf(input, "%G", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_G_width) {
  const char *input = "1.23456E5";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%4G", &a), sscanf(input, "%4G", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_G_star) {
  const char *input = "1.23E1 4.56E2";
  float a = 0;
  ck_assert_int_eq(s21_sscanf(input, "%*G %G", &a),
                   sscanf(input, "%*G %G", &a));
}
END_TEST

START_TEST(test_s21_sscanf_G_width_3) {
  const char *input = "1.23456E5";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%3G", &a), sscanf(input, "%3G", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_G_star_simple) {
  const char *input = "1.23E1 4.56E2";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%*G %G", &a),
                   sscanf(input, "%*G %G", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_G_star_multiple) {
  const char *input = "1.0E1 2.0 3.0E3 4.0";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%*G %*G %G %*G", &a),
                   sscanf(input, "%*G %*G %G %*G", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_LG_simple) {
  const char *input = "1.23E10";
  long double a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%LG", &a), sscanf(input, "%LG", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_G_inf) {
  const char *input = "InF";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%G", &a), sscanf(input, "%G", &b));
  ck_assert(isinf(a) && isinf(b));
}
END_TEST

START_TEST(test_s21_sscanf_G_nan) {
  const char *input = "NaN";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%G", &a), sscanf(input, "%G", &b));
  ck_assert(isnan(a) && isnan(b));
}
END_TEST

Suite *s21_sscanf_G_suite(void) {
  Suite *s = suite_create("s21_sscanf_G");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_sscanf_G_empty);
  tcase_add_test(tc, test_s21_sscanf_G_simple_float);
  tcase_add_test(tc, test_s21_sscanf_G_simple_exp);
  tcase_add_test(tc, test_s21_sscanf_G_negative);
  tcase_add_test(tc, test_s21_sscanf_G_exp_positive);
  tcase_add_test(tc, test_s21_sscanf_G_exp_negative);
  tcase_add_test(tc, test_s21_sscanf_G_mixed);
  tcase_add_test(tc, test_s21_sscanf_G_with_text);
  tcase_add_test(tc, test_s21_sscanf_G_leading_whitespace);
  tcase_add_test(tc, test_s21_sscanf_G_trailing_whitespace);
  tcase_add_test(tc, test_s21_sscanf_G_max_float);
  tcase_add_test(tc, test_s21_sscanf_G_min_float);
  tcase_add_test(tc, test_s21_sscanf_G_invalid_input);
  tcase_add_test(tc, test_s21_sscanf_G_mixed_input);
  tcase_add_test(tc, test_s21_sscanf_G_zero);
  tcase_add_test(tc, test_s21_sscanf_G_leading_zeros);
  tcase_add_test(tc, test_s21_sscanf_G_leading_plus);
  tcase_add_test(tc, test_s21_sscanf_G_width);
  tcase_add_test(tc, test_s21_sscanf_G_star);
  tcase_add_test(tc, test_s21_sscanf_G_width_3);
  tcase_add_test(tc, test_s21_sscanf_G_star_simple);
  tcase_add_test(tc, test_s21_sscanf_G_star_multiple);
  tcase_add_test(tc, test_s21_sscanf_LG_simple);
  tcase_add_test(tc, test_s21_sscanf_G_inf);
  tcase_add_test(tc, test_s21_sscanf_G_nan);

  suite_add_tcase(s, tc);
  return s;
}