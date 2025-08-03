#include <check.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_sprintf_single_unsigned) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%u", 123u), sprintf(original, "%u", 123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_short_positive_unsigned) {
  char original[100];
  char my[100];
  unsigned short int num = 12345u;
  ck_assert_int_eq(s21_sprintf(my, "%hu", num), sprintf(original, "%hu", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_short_max_unsigned) {
  char original[100];
  char my[100];
  unsigned short int num = USHRT_MAX;
  ck_assert_int_eq(s21_sprintf(my, "%hu", num), sprintf(original, "%hu", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_long_positive_unsigned) {
  char original[100];
  char my[100];
  unsigned long int num = 1234567890UL;
  ck_assert_int_eq(s21_sprintf(my, "%lu", num), sprintf(original, "%lu", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_long_max_unsigned) {
  char original[100];
  char my[100];
  unsigned long int num = ULONG_MAX;
  ck_assert_int_eq(s21_sprintf(my, "%lu", num), sprintf(original, "%lu", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_many_unsigned) {
  char original[100];
  char my[100];
  ck_assert_int_eq(
      s21_sprintf(my, "%uHello,world@%u %u55656%u", 1u, 2u, 3u, 4u),
      sprintf(original, "%uHello,world@%u %u55656%u", 1u, 2u, 3u, 4u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_single_unsigned_with_width) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%10u", 123u),
                   sprintf(original, "%10u", 123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_single_unsigned_with_width_and_left_align) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%-10u", 123u),
                   sprintf(original, "%-10u", 123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_single_unsigned_with_width_and_fill) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%010u", 123u),
                   sprintf(original, "%010u", 123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_unsigned_with_width) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%10u", 123u),
                   sprintf(original, "%10u", 123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_unsigned_with_zero_fill) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%010u", 123u),
                   sprintf(original, "%010u", 123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_unsigned_with_all_flags) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%-15u", 123u),
                   sprintf(original, "%-15u", 123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_zero_value_with_flags) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%05u", 0u), sprintf(original, "%05u", 0u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_precision_unsigned) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%.5u", 42u),
                   sprintf(original, "%.5u", 42u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_precision_unsigned_zero) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%.3u", 0u), sprintf(original, "%.3u", 0u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_precision_width) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%10.5u", 123u),
                   sprintf(original, "%10.5u", 123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_precision_minus_flag) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%-10.5u", 123u),
                   sprintf(original, "%-10.5u", 123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_precision_zero_and_num_zero) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%.0u", 0u), sprintf(original, "%.0u", 0u));
  ck_assert_str_eq(my, original);
}
END_TEST

Suite *s21_sprintf_u_suite(void) {
  Suite *s = suite_create("s21_sprintf_u");
  TCase *tc = tcase_create("Core");
  tcase_add_test(tc, test_s21_sprintf_single_unsigned);
  tcase_add_test(tc, test_s21_sprintf_short_positive_unsigned);
  tcase_add_test(tc, test_s21_sprintf_short_max_unsigned);
  tcase_add_test(tc, test_s21_sprintf_long_positive_unsigned);
  tcase_add_test(tc, test_s21_sprintf_long_max_unsigned);
  tcase_add_test(tc, test_s21_sprintf_many_unsigned);
  tcase_add_test(tc, test_s21_sprintf_single_unsigned_with_width);
  tcase_add_test(tc,
                 test_s21_sprintf_single_unsigned_with_width_and_left_align);
  tcase_add_test(tc, test_s21_sprintf_single_unsigned_with_width_and_fill);
  tcase_add_test(tc, test_s21_sprintf_unsigned_with_width);
  tcase_add_test(tc, test_s21_sprintf_unsigned_with_zero_fill);
  tcase_add_test(tc, test_s21_sprintf_unsigned_with_all_flags);
  tcase_add_test(tc, test_s21_sprintf_zero_value_with_flags);
  tcase_add_test(tc, test_s21_sprintf_precision_unsigned);
  tcase_add_test(tc, test_s21_sprintf_precision_unsigned_zero);
  tcase_add_test(tc, test_s21_sprintf_precision_width);
  tcase_add_test(tc, test_s21_sprintf_precision_minus_flag);
  tcase_add_test(tc, test_s21_sprintf_precision_zero_and_num_zero);
  suite_add_tcase(s, tc);
  return s;
}