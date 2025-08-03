#include <check.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_sprintf_single_e) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%e", 123.456),
                   sprintf(original, "%e", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_single_negative_e) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%e", -123.456),
                   sprintf(original, "%e", -123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_e_max) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%e", FLT_MAX),
                   sprintf(original, "%e", FLT_MAX));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_e_min) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%e", FLT_MIN),
                   sprintf(original, "%e", FLT_MIN));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_e_zero) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%e", 0.0), sprintf(original, "%e", 0.0));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_e_with_width) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%15e", 123.456),
                   sprintf(original, "%15e", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_e_with_left_align) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%-15e", 123.456),
                   sprintf(original, "%-15e", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_e_with_zero_fill) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%015e", 123.456),
                   sprintf(original, "%015e", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_e_with_precision) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%.3e", 123.456),
                   sprintf(original, "%.3e", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_e_with_precision_zero) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%.0e", 123.456),
                   sprintf(original, "%.0e", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_e_with_precision_large) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%.10e", 123.456),
                   sprintf(original, "%.10e", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_e_with_width_and_precision) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%15.3e", 123.456),
                   sprintf(original, "%15.3e", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_e_with_plus_flag) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%+e", 123.456),
                   sprintf(original, "%+e", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_e_with_space_flag) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "% e", 123.456),
                   sprintf(original, "% e", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_e_with_hash_flag) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%#e", 123.0),
                   sprintf(original, "%#e", 123.0));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_e_uppercase) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%E", 123.456),
                   sprintf(original, "%E", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_many_es) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%eHello%eworld%e", 1.1, 2.2, 3.3),
                   sprintf(original, "%eHello%eworld%e", 1.1, 2.2, 3.3));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_nan_e) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%e", NAN), sprintf(original, "%e", NAN));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_negative_nan_e) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%e", -NAN), sprintf(original, "%e", -NAN));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_inf_e) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%e", INFINITY),
                   sprintf(original, "%e", INFINITY));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_negative_inf_e) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%e", -INFINITY),
                   sprintf(original, "%e", -INFINITY));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_small_value_e) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%e", 0.0000123456),
                   sprintf(original, "%e", 0.0000123456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_large_value_e) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%e", 123456789.0),
                   sprintf(original, "%e", 123456789.0));
  ck_assert_str_eq(my, original);
}
END_TEST

Suite *s21_sprintf_e_suite(void) {
  Suite *s = suite_create("s21_sprintf_e");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_sprintf_single_e);
  tcase_add_test(tc, test_s21_sprintf_single_negative_e);
  tcase_add_test(tc, test_s21_sprintf_e_max);
  tcase_add_test(tc, test_s21_sprintf_e_min);
  tcase_add_test(tc, test_s21_sprintf_e_zero);
  tcase_add_test(tc, test_s21_sprintf_e_with_width);
  tcase_add_test(tc, test_s21_sprintf_e_with_left_align);
  tcase_add_test(tc, test_s21_sprintf_e_with_zero_fill);
  tcase_add_test(tc, test_s21_sprintf_e_with_precision);
  tcase_add_test(tc, test_s21_sprintf_e_with_precision_zero);
  tcase_add_test(tc, test_s21_sprintf_e_with_precision_large);
  tcase_add_test(tc, test_s21_sprintf_e_with_width_and_precision);
  tcase_add_test(tc, test_s21_sprintf_e_with_plus_flag);
  tcase_add_test(tc, test_s21_sprintf_e_with_space_flag);
  tcase_add_test(tc, test_s21_sprintf_e_with_hash_flag);
  tcase_add_test(tc, test_s21_sprintf_e_uppercase);
  tcase_add_test(tc, test_s21_sprintf_many_es);
  tcase_add_test(tc, test_s21_sprintf_nan_e);
  tcase_add_test(tc, test_s21_sprintf_negative_nan_e);
  tcase_add_test(tc, test_s21_sprintf_inf_e);
  tcase_add_test(tc, test_s21_sprintf_negative_inf_e);
  tcase_add_test(tc, test_s21_sprintf_small_value_e);
  tcase_add_test(tc, test_s21_sprintf_large_value_e);

  suite_add_tcase(s, tc);
  return s;
}