#include <check.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_sscanf_g_empty) {
  const char *input = "";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%g", &a), sscanf(input, "%g", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_g_simple_decimal) {
  const char *input = "123.456";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%g", &a), sscanf(input, "%g", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_g_simple_scientific) {
  const char *input = "1.23456e5";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%g", &a), sscanf(input, "%g", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_g_negative) {
  const char *input = "-789.012";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%g", &a), sscanf(input, "%g", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_g_auto_notation) {
  const char *input = "123456";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%g", &a), sscanf(input, "%g", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_g_auto_notation_small) {
  const char *input = "0.0000123456";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%g", &a), sscanf(input, "%g", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_g_mixed) {
  const char *input = "123.456 7.89e3 -1.23e-4";
  float a1 = 0, a2 = 0, a3 = 0;
  float b1 = 0, b2 = 0, b3 = 0;
  ck_assert_int_eq(s21_sscanf(input, "%g%g%g", &a1, &a2, &a3),
                   sscanf(input, "%g%g%g", &b1, &b2, &b3));
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
}
END_TEST

START_TEST(test_s21_sscanf_g_with_text) {
  const char *input = "Temp: 98.6F, Pressure: 1.01e5Pa";
  float a1 = 0, a2 = 0;
  float b1 = 0, b2 = 0;
  ck_assert_int_eq(s21_sscanf(input, "Temp: %gF, Pressure: %gPa", &a1, &a2),
                   sscanf(input, "Temp: %gF, Pressure: %gPa", &b1, &b2));
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
}
END_TEST

START_TEST(test_s21_sscanf_g_no_fractional) {
  const char *input = "123.";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%g", &a), sscanf(input, "%g", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_g_no_integer) {
  const char *input = ".456";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%g", &a), sscanf(input, "%g", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_g_zero) {
  const char *input = "0.0";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%g", &a), sscanf(input, "%g", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_g_leading_zeros) {
  const char *input = "000123.456";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%g", &a), sscanf(input, "%g", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_g_trailing_zeros) {
  const char *input = "123.456000";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%g", &a), sscanf(input, "%g", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_g_leading_plus) {
  const char *input = "+123.456";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%g", &a), sscanf(input, "%g", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_g_width) {
  const char *input = "12345.6789";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%5g", &a), sscanf(input, "%5g", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_g_star) {
  const char *input = "123.456 789.012";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%*g %g", &a),
                   sscanf(input, "%*g %g", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_g_inf) {
  const char *input = "inf";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%g", &a), sscanf(input, "%g", &b));
  ck_assert(isinf(a) && isinf(b));
}
END_TEST

START_TEST(test_s21_sscanf_g_nan) {
  const char *input = "nan";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%g", &a), sscanf(input, "%g", &b));
  ck_assert(isnan(a) && isnan(b));
}
END_TEST

START_TEST(test_s21_sscanf_g_mixed_notation) {
  const char *input = "1.23 4.56e7 8.9e-1";
  float a1 = 0, a2 = 0, a3 = 0;
  float b1 = 0, b2 = 0, b3 = 0;
  ck_assert_int_eq(s21_sscanf(input, "%g%g%g", &a1, &a2, &a3),
                   sscanf(input, "%g%g%g", &b1, &b2, &b3));
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
}
END_TEST

START_TEST(test_s21_sscanf_g_precision) {
  const char *input = "123.456789";
  float a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%6g", &a), sscanf(input, "%6g", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

Suite *s21_sscanf_g_suite(void) {
  Suite *s = suite_create("s21_sscanf_g");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_sscanf_g_empty);
  tcase_add_test(tc, test_s21_sscanf_g_simple_decimal);
  tcase_add_test(tc, test_s21_sscanf_g_simple_scientific);
  tcase_add_test(tc, test_s21_sscanf_g_negative);
  tcase_add_test(tc, test_s21_sscanf_g_auto_notation);
  tcase_add_test(tc, test_s21_sscanf_g_auto_notation_small);
  tcase_add_test(tc, test_s21_sscanf_g_mixed);
  tcase_add_test(tc, test_s21_sscanf_g_with_text);
  tcase_add_test(tc, test_s21_sscanf_g_no_fractional);
  tcase_add_test(tc, test_s21_sscanf_g_no_integer);
  tcase_add_test(tc, test_s21_sscanf_g_zero);
  tcase_add_test(tc, test_s21_sscanf_g_leading_zeros);
  tcase_add_test(tc, test_s21_sscanf_g_trailing_zeros);
  tcase_add_test(tc, test_s21_sscanf_g_leading_plus);
  tcase_add_test(tc, test_s21_sscanf_g_width);
  tcase_add_test(tc, test_s21_sscanf_g_star);
  tcase_add_test(tc, test_s21_sscanf_g_inf);
  tcase_add_test(tc, test_s21_sscanf_g_nan);
  tcase_add_test(tc, test_s21_sscanf_g_mixed_notation);
  tcase_add_test(tc, test_s21_sscanf_g_precision);

  suite_add_tcase(s, tc);
  return s;
}