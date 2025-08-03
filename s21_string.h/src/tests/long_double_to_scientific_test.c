#include <check.h>
#include <float.h>
#include <math.h>
#include <string.h>

#include "../utils.h"

START_TEST(test_nan) {
  char str[32];
  long_double_to_scientific(str, NAN, 2);
  ck_assert_str_eq(str, "nan");
}
END_TEST

START_TEST(test_negative_nan) {
  char str[32];
  long_double_to_scientific(str, -NAN, 2);
  ck_assert_str_eq(str, "-nan");
}
END_TEST

START_TEST(test_inf) {
  char str[32];
  long_double_to_scientific(str, INFINITY, 2);
  ck_assert_str_eq(str, "inf");
}
END_TEST

START_TEST(test_negative_inf) {
  char str[32];
  long_double_to_scientific(str, -INFINITY, 2);
  ck_assert_str_eq(str, "-inf");
}
END_TEST

START_TEST(test_zero) {
  char str[32];
  long_double_to_scientific(str, 0.0L, 2);
  ck_assert_str_eq(str, "0.00e+00");
}
END_TEST

START_TEST(test_negative_zero) {
  char str[32];
  long_double_to_scientific(str, -0.0L, 2);
  ck_assert_str_eq(str, "-0.00e+00");
}
END_TEST

START_TEST(test_small_positive) {
  char str[32];
  long_double_to_scientific(str, 123.456L, 3);
  ck_assert_str_eq(str, "1.235e+02");
}
END_TEST

START_TEST(test_small_negative) {
  char str[32];
  long_double_to_scientific(str, -123.456L, 3);
  ck_assert_str_eq(str, "-1.235e+02");
}
END_TEST

START_TEST(test_large_positive) {
  char str[32];
  long_double_to_scientific(str, 123456789.0L, 5);
  ck_assert_str_eq(str, "1.23457e+08");
}
END_TEST

START_TEST(test_large_negative) {
  char str[32];
  long_double_to_scientific(str, -123456789.0L, 5);
  ck_assert_str_eq(str, "-1.23457e+08");
}
END_TEST

START_TEST(test_very_small_positive) {
  char str[32];
  long_double_to_scientific(str, 0.00000012345L, 4);
  ck_assert_str_eq(str, "1.2345e-07");
}
END_TEST

START_TEST(test_very_small_negative) {
  char str[32];
  long_double_to_scientific(str, -0.00000012345L, 4);
  ck_assert_str_eq(str, "-1.2345e-07");
}
END_TEST

START_TEST(test_precision_zero) {
  char str[32];
  long_double_to_scientific(str, 123.456L, 0);
  ck_assert_str_eq(str, "1e+02");
}
END_TEST

START_TEST(test_precision_one) {
  char str[32];
  long_double_to_scientific(str, 123.456L, 1);
  ck_assert_str_eq(str, "1.2e+02");
}
END_TEST

START_TEST(test_precision_large) {
  char str[64];
  long_double_to_scientific(str, 123.456L, 15);
  ck_assert_str_eq(str, "1.234560000000000e+02");
}
END_TEST

START_TEST(test_rounding_up) {
  char str[32];
  long_double_to_scientific(str, 9.9999L, 3);
  ck_assert_str_eq(str, "1.000e+01");
}
END_TEST

START_TEST(test_rounding_down) {
  char str[32];
  long_double_to_scientific(str, 1.23444L, 4);
  ck_assert_str_eq(str, "1.2344e+00");
}
END_TEST

Suite *long_double_to_scientific_suite(void) {
  Suite *s = suite_create("Scientific Notation Conversion");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_nan);
  tcase_add_test(tc_core, test_negative_nan);
  tcase_add_test(tc_core, test_inf);
  tcase_add_test(tc_core, test_negative_inf);
  tcase_add_test(tc_core, test_zero);
  tcase_add_test(tc_core, test_negative_zero);
  tcase_add_test(tc_core, test_small_positive);
  tcase_add_test(tc_core, test_small_negative);
  tcase_add_test(tc_core, test_large_positive);
  tcase_add_test(tc_core, test_large_negative);
  tcase_add_test(tc_core, test_very_small_positive);
  tcase_add_test(tc_core, test_very_small_negative);
  tcase_add_test(tc_core, test_precision_zero);
  tcase_add_test(tc_core, test_precision_one);
  tcase_add_test(tc_core, test_precision_large);
  tcase_add_test(tc_core, test_rounding_up);
  tcase_add_test(tc_core, test_rounding_down);

  suite_add_tcase(s, tc_core);
  return s;
}