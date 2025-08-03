#include <check.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_sscanf_f_empty) {
  const char *input = "";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_f_simple) {
  const char *input = "123.456";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_f_negative) {
  const char *input = "-456.789";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_f_multiple) {
  const char *input = "789.012 345.678 -901.234";
  float a1 = 0, a2 = 0, a3 = 0;
  float b1 = 0, b2 = 0, b3 = 0;
  ck_assert_int_eq(s21_sscanf(input, "%f%f%f", &a1, &a2, &a3),
                   sscanf(input, "%f%f%f", &b1, &b2, &b3));
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
}
END_TEST

START_TEST(test_s21_sscanf_f_with_text) {
  const char *input = "Value: 42.5, Next: 73.8";
  float a1 = 0, a2 = 0;
  float b1 = 0, b2 = 0;
  ck_assert_int_eq(s21_sscanf(input, "Value: %f, Next: %f", &a1, &a2),
                   sscanf(input, "Value: %f, Next: %f", &b1, &b2));
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
}
END_TEST

START_TEST(test_s21_sscanf_f_leading_whitespace) {
  const char *input = "    \t\n\r\v\f 123.456";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_f_trailing_whitespace) {
  const char *input = "456.789   \t\n\r\v\f";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_f_max_float) {
  const char *input = "3.402823466e+38";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_f_min_float) {
  const char *input = "-3.402823466e+38";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_f_invalid_input) {
  const char *input = "abc123.456";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_f_mixed_input) {
  const char *input = "123.456abc789.012";
  float a1 = 0, a2 = 0;
  float b1 = 0, b2 = 0;
  ck_assert_int_eq(s21_sscanf(input, "%fabc%f", &a1, &a2),
                   sscanf(input, "%fabc%f", &b1, &b2));
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
}
END_TEST

START_TEST(test_s21_sscanf_f_zero) {
  const char *input = "0.0";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_f_leading_zeros) {
  const char *input = "000123.456";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_f_leading_plus) {
  const char *input = "+123.456";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_f_width) {
  const char *input = "123.456789";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%5f", &a), sscanf(input, "%5f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_f_star) {
  const char *input = "123.456 789.012";
  float a = 0;
  ck_assert_int_eq(s21_sscanf(input, "%*f %f", &a),
                   sscanf(input, "%*f %f", &a));
}
END_TEST

START_TEST(test_s21_sscanf_f_scientific) {
  const char *input = "1.23e+4";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_f_scientific_negative) {
  const char *input = "-1.23e-4";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_f_scientific_upper) {
  const char *input = "1.23E+4";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_f_no_fraction) {
  const char *input = "123.";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_f_no_integer) {
  const char *input = ".456";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_f_inf) {
  const char *input = "inf";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert(!!isinf(a) == !!isinf(b));
}
END_TEST

START_TEST(test_s21_sscanf_f_inf_negative) {
  const char *input = "-inf";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert(!!isinf(a) == !!isinf(b));
}
END_TEST

START_TEST(test_s21_sscanf_f_nan) {
  const char *input = "nan";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert(!!isnan(a) == !!isnan(b));
}
END_TEST

START_TEST(test_s21_sscanf_f_nan_negative) {
  const char *input = "-nan";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert(!!isnan(a) == !!isnan(b));
}
END_TEST

START_TEST(test_s21_sscanf_f_long) {
  const char *input = "1234567890.1234567890";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_f_width_star) {
  const char *input = "123.456 789.012 345.678";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%*f %5f %*f", &a),
                   sscanf(input, "%*f %5f %*f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_f_star_no_output) {
  const char *input = "123.456 789.012";
  ck_assert_int_eq(s21_sscanf(input, "%*f %*f"), sscanf(input, "%*f %*f"));
}
END_TEST

START_TEST(test_s21_sscanf_lf_simple) {
  const char *input = "123.456";
  double a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%lf", &a), sscanf(input, "%lf", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_lf_large) {
  const char *input = "1.7976931348623158e+308";
  double a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%lf", &a), sscanf(input, "%lf", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_lf_small) {
  const char *input = "2.2250738585072014e-308";
  double a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%lf", &a), sscanf(input, "%lf", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_Lf_simple) {
  const char *input = "123.456";
  long double a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%Lf", &a), sscanf(input, "%Lf", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_Lf_large) {
  const char *input = "1.189731495357231765e+4932";
  long double a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%Lf", &a), sscanf(input, "%Lf", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

Suite *s21_sscanf_f_suite(void) {
  Suite *s = suite_create("s21_sscanf_f");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_sscanf_f_empty);
  tcase_add_test(tc, test_s21_sscanf_f_simple);
  tcase_add_test(tc, test_s21_sscanf_f_negative);
  tcase_add_test(tc, test_s21_sscanf_f_multiple);
  tcase_add_test(tc, test_s21_sscanf_f_with_text);
  tcase_add_test(tc, test_s21_sscanf_f_leading_whitespace);
  tcase_add_test(tc, test_s21_sscanf_f_trailing_whitespace);
  tcase_add_test(tc, test_s21_sscanf_f_max_float);
  tcase_add_test(tc, test_s21_sscanf_f_min_float);
  tcase_add_test(tc, test_s21_sscanf_f_invalid_input);
  tcase_add_test(tc, test_s21_sscanf_f_mixed_input);
  tcase_add_test(tc, test_s21_sscanf_f_zero);
  tcase_add_test(tc, test_s21_sscanf_f_leading_zeros);
  tcase_add_test(tc, test_s21_sscanf_f_leading_plus);
  tcase_add_test(tc, test_s21_sscanf_f_width);
  tcase_add_test(tc, test_s21_sscanf_f_star);
  tcase_add_test(tc, test_s21_sscanf_f_scientific);
  tcase_add_test(tc, test_s21_sscanf_f_scientific_negative);
  tcase_add_test(tc, test_s21_sscanf_f_scientific_upper);
  tcase_add_test(tc, test_s21_sscanf_f_no_fraction);
  tcase_add_test(tc, test_s21_sscanf_f_no_integer);
  tcase_add_test(tc, test_s21_sscanf_f_inf);
  tcase_add_test(tc, test_s21_sscanf_f_inf_negative);
  tcase_add_test(tc, test_s21_sscanf_f_nan);
  tcase_add_test(tc, test_s21_sscanf_f_nan_negative);
  tcase_add_test(tc, test_s21_sscanf_f_long);
  tcase_add_test(tc, test_s21_sscanf_f_width_star);
  tcase_add_test(tc, test_s21_sscanf_f_star_no_output);
  tcase_add_test(tc, test_s21_sscanf_lf_simple);
  tcase_add_test(tc, test_s21_sscanf_lf_large);
  tcase_add_test(tc, test_s21_sscanf_lf_small);
  tcase_add_test(tc, test_s21_sscanf_Lf_simple);
  tcase_add_test(tc, test_s21_sscanf_Lf_large);

  suite_add_tcase(s, tc);
  return s;
}