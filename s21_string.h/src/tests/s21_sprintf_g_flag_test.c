#include <check.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_sprintf_single_g) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%g", 123.456),
                   sprintf(original, "%g", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_single_negative_g) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%g", -123.456),
                   sprintf(original, "%g", -123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_g_max) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%g", FLT_MAX),
                   sprintf(original, "%g", FLT_MAX));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_g_min) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%g", FLT_MIN),
                   sprintf(original, "%g", FLT_MIN));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_g_zero) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%g", 0.0), sprintf(original, "%g", 0.0));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_g_small) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%g", 0.0000123456),
                   sprintf(original, "%g", 0.0000123456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_g_large) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%g", 123456789.0),
                   sprintf(original, "%g", 123456789.0));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_g_with_width) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%15g", 123.456),
                   sprintf(original, "%15g", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_g_with_left_align) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%-15g", 123.456),
                   sprintf(original, "%-15g", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_g_with_zero_fill) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%015g", 123.456),
                   sprintf(original, "%015g", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_g_with_precision) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%.3g", 123.456),
                   sprintf(original, "%.3g", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_g_with_precision_zero) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%.0g", 123.456),
                   sprintf(original, "%.0g", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_g_with_precision_large) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%.10g", 123.456),
                   sprintf(original, "%.10g", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_g_with_width_and_precision) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%15.3g", 123.456),
                   sprintf(original, "%15.3g", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_g_with_plus_flag) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%+g", 123.456),
                   sprintf(original, "%+g", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_g_with_space_flag) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "% g", 123.456),
                   sprintf(original, "% g", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_g_with_hash_flag) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%#g", 123.0),
                   sprintf(original, "%#g", 123.0));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_many_gs) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%gHello%gworld%g", 1.1, 2.2, 3.3),
                   sprintf(original, "%gHello%gworld%g", 1.1, 2.2, 3.3));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_g_nan) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%g", NAN), sprintf(original, "%g", NAN));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_g_negative_nan) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%g", -NAN), sprintf(original, "%g", -NAN));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_g_inf) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%g", INFINITY),
                   sprintf(original, "%g", INFINITY));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_g_negative_inf) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%g", -INFINITY),
                   sprintf(original, "%g", -INFINITY));
  ck_assert_str_eq(my, original);
}
END_TEST

Suite *s21_sprintf_g_suite(void) {
  Suite *s = suite_create("s21_sprintf_g");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_sprintf_single_g);
  tcase_add_test(tc, test_s21_sprintf_single_negative_g);
  tcase_add_test(tc, test_s21_sprintf_g_max);
  tcase_add_test(tc, test_s21_sprintf_g_min);
  tcase_add_test(tc, test_s21_sprintf_g_zero);
  tcase_add_test(tc, test_s21_sprintf_g_small);
  tcase_add_test(tc, test_s21_sprintf_g_large);
  tcase_add_test(tc, test_s21_sprintf_g_with_width);
  tcase_add_test(tc, test_s21_sprintf_g_with_left_align);
  tcase_add_test(tc, test_s21_sprintf_g_with_zero_fill);
  tcase_add_test(tc, test_s21_sprintf_g_with_precision);
  tcase_add_test(tc, test_s21_sprintf_g_with_precision_zero);
  tcase_add_test(tc, test_s21_sprintf_g_with_precision_large);
  tcase_add_test(tc, test_s21_sprintf_g_with_width_and_precision);
  tcase_add_test(tc, test_s21_sprintf_g_with_plus_flag);
  tcase_add_test(tc, test_s21_sprintf_g_with_space_flag);
  tcase_add_test(tc, test_s21_sprintf_g_with_hash_flag);
  tcase_add_test(tc, test_s21_sprintf_many_gs);
  tcase_add_test(tc, test_s21_sprintf_g_nan);
  tcase_add_test(tc, test_s21_sprintf_g_negative_nan);
  tcase_add_test(tc, test_s21_sprintf_g_inf);
  tcase_add_test(tc, test_s21_sprintf_g_negative_inf);

  suite_add_tcase(s, tc);
  return s;
}