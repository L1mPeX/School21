#include <check.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_sprintf_single_float) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%f", 123.456),
                   sprintf(original, "%f", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_single_negative_float) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%f", -123.456),
                   sprintf(original, "%f", -123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_float_max) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%f", FLT_MAX),
                   sprintf(original, "%f", FLT_MAX));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_float_min) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%f", FLT_MIN),
                   sprintf(original, "%f", FLT_MIN));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_float_zero) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%f", 0.0), sprintf(original, "%f", 0.0));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_float_with_width) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%15f", 123.456),
                   sprintf(original, "%15f", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_float_with_left_align) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%-15f", 123.456),
                   sprintf(original, "%-15f", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_float_with_zero_fill) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%015f", 123.456),
                   sprintf(original, "%015f", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_float_with_precision) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%.3f", 123.456),
                   sprintf(original, "%.3f", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_float_with_precision_zero) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%.0f", 123.456),
                   sprintf(original, "%.0f", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_float_with_precision_large) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%.10f", 123.456),
                   sprintf(original, "%.10f", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_float_with_width_and_precision) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%15.3f", 123.456),
                   sprintf(original, "%15.3f", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_float_with_plus_flag) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%+f", 123.456),
                   sprintf(original, "%+f", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_float_with_space_flag) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "% f", 123.456),
                   sprintf(original, "% f", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_float_with_hash_flag) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%#f", 123.0),
                   sprintf(original, "%#f", 123.0));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_many_floats) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%fHello%fworld%f", 1.1, 2.2, 3.3),
                   sprintf(original, "%fHello%fworld%f", 1.1, 2.2, 3.3));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_nan) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%f", NAN), sprintf(original, "%f", NAN));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_negative_nan) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%f", -NAN), sprintf(original, "%f", -NAN));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_inf) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%f", INFINITY),
                   sprintf(original, "%f", INFINITY));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_negative_inf) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%f", -INFINITY),
                   sprintf(original, "%f", -INFINITY));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_hard_inf) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%f %f %f %f %f %f", NAN, INFINITY, 0.0,
                               -NAN, -INFINITY, -0.0),
                   sprintf(original, "%f %f %f %f %f %f", NAN, INFINITY, 0.0,
                           -NAN, -INFINITY, -0.0));
  ck_assert_str_eq(my, original);
}
END_TEST

Suite *s21_sprintf_f_suite(void) {
  Suite *s = suite_create("s21_sprintf_f");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_sprintf_single_float);
  tcase_add_test(tc, test_s21_sprintf_single_negative_float);
  tcase_add_test(tc, test_s21_sprintf_float_max);
  tcase_add_test(tc, test_s21_sprintf_float_min);
  tcase_add_test(tc, test_s21_sprintf_float_zero);
  tcase_add_test(tc, test_s21_sprintf_float_with_width);
  tcase_add_test(tc, test_s21_sprintf_float_with_left_align);
  tcase_add_test(tc, test_s21_sprintf_float_with_zero_fill);
  tcase_add_test(tc, test_s21_sprintf_float_with_precision);
  tcase_add_test(tc, test_s21_sprintf_float_with_precision_zero);
  tcase_add_test(tc, test_s21_sprintf_float_with_precision_large);
  tcase_add_test(tc, test_s21_sprintf_float_with_width_and_precision);
  tcase_add_test(tc, test_s21_sprintf_float_with_plus_flag);
  tcase_add_test(tc, test_s21_sprintf_float_with_space_flag);
  tcase_add_test(tc, test_s21_sprintf_float_with_hash_flag);
  tcase_add_test(tc, test_s21_sprintf_many_floats);
  tcase_add_test(tc, test_s21_sprintf_nan);
  tcase_add_test(tc, test_s21_sprintf_negative_nan);
  tcase_add_test(tc, test_s21_sprintf_inf);
  tcase_add_test(tc, test_s21_sprintf_negative_inf);
  tcase_add_test(tc, test_s21_sprintf_hard_inf);

  suite_add_tcase(s, tc);
  return s;
}