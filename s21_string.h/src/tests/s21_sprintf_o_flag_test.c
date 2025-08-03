#include <check.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_sprintf_single_oct) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%o", 0123u),
                   sprintf(original, "%o", 0123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_short_positive_oct) {
  char original[100];
  char my[100];
  unsigned short int num = 01234u;
  ck_assert_int_eq(s21_sprintf(my, "%ho", num), sprintf(original, "%ho", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_short_max_oct) {
  char original[100];
  char my[100];
  unsigned short int num = USHRT_MAX;
  ck_assert_int_eq(s21_sprintf(my, "%ho", num), sprintf(original, "%ho", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_long_positive_oct) {
  char original[100];
  char my[100];
  unsigned long int num = 012345670UL;
  ck_assert_int_eq(s21_sprintf(my, "%lo", num), sprintf(original, "%lo", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_long_max_oct) {
  char original[100];
  char my[100];
  unsigned long int num = ULONG_MAX;
  ck_assert_int_eq(s21_sprintf(my, "%lo", num), sprintf(original, "%lo", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_many_oct) {
  char original[100];
  char my[100];
  ck_assert_int_eq(
      s21_sprintf(my, "%oHello,world@%o %o55656%o", 01u, 02u, 03u, 04u),
      sprintf(original, "%oHello,world@%o %o55656%o", 01u, 02u, 03u, 04u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_single_oct_with_width) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%10o", 0123u),
                   sprintf(original, "%10o", 0123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_single_oct_with_width_and_left_align) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%-10o", 0123u),
                   sprintf(original, "%-10o", 0123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_single_oct_with_width_and_fill) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%010o", 0123u),
                   sprintf(original, "%010o", 0123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_oct_with_width) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%10o", 0123u),
                   sprintf(original, "%10o", 0123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_oct_with_zero_fill) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%010o", 0123u),
                   sprintf(original, "%010o", 0123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_oct_with_all_flags) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%-15o", 0123u),
                   sprintf(original, "%-15o", 0123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_zero_value_with_flags) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%05o", 0u), sprintf(original, "%05o", 0u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_precision_oct) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%.5o", 042u),
                   sprintf(original, "%.5o", 042u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_precision_oct_zero) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%.3o", 0u), sprintf(original, "%.3o", 0u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_precision_width) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%10.5o", 0123u),
                   sprintf(original, "%10.5o", 0123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_precision_minus_flag) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%-10.5o", 0123u),
                   sprintf(original, "%-10.5o", 0123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_precision_zero_and_num_zero) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%.0o", 0u), sprintf(original, "%.0o", 0u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_oct_alternate_form) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%#o", 0123u),
                   sprintf(original, "%#o", 0123u));
  ck_assert_str_eq(my, original);
}
END_TEST

Suite *s21_sprintf_o_suite(void) {
  Suite *s = suite_create("s21_sprintf_o");
  TCase *tc = tcase_create("Core");
  tcase_add_test(tc, test_s21_sprintf_single_oct);
  tcase_add_test(tc, test_s21_sprintf_short_positive_oct);
  tcase_add_test(tc, test_s21_sprintf_short_max_oct);
  tcase_add_test(tc, test_s21_sprintf_long_positive_oct);
  tcase_add_test(tc, test_s21_sprintf_long_max_oct);
  tcase_add_test(tc, test_s21_sprintf_many_oct);
  tcase_add_test(tc, test_s21_sprintf_single_oct_with_width);
  tcase_add_test(tc, test_s21_sprintf_single_oct_with_width_and_left_align);
  tcase_add_test(tc, test_s21_sprintf_single_oct_with_width_and_fill);
  tcase_add_test(tc, test_s21_sprintf_oct_with_width);
  tcase_add_test(tc, test_s21_sprintf_oct_with_zero_fill);
  tcase_add_test(tc, test_s21_sprintf_oct_with_all_flags);
  tcase_add_test(tc, test_s21_sprintf_zero_value_with_flags);
  tcase_add_test(tc, test_s21_sprintf_precision_oct);
  tcase_add_test(tc, test_s21_sprintf_precision_oct_zero);
  tcase_add_test(tc, test_s21_sprintf_precision_width);
  tcase_add_test(tc, test_s21_sprintf_precision_minus_flag);
  tcase_add_test(tc, test_s21_sprintf_precision_zero_and_num_zero);
  tcase_add_test(tc, test_s21_sprintf_oct_alternate_form);
  suite_add_tcase(s, tc);
  return s;
}