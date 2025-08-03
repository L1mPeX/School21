#include <check.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_sprintf_single_hex) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%x", 0x123u),
                   sprintf(original, "%x", 0x123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_short_positive_hex) {
  char original[100];
  char my[100];
  unsigned short int num = 0x1234u;
  ck_assert_int_eq(s21_sprintf(my, "%hx", num), sprintf(original, "%hx", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_short_max_hex) {
  char original[100];
  char my[100];
  unsigned short int num = USHRT_MAX;
  ck_assert_int_eq(s21_sprintf(my, "%hx", num), sprintf(original, "%hx", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_long_positive_hex) {
  char original[100];
  char my[100];
  unsigned long int num = 0x12345678UL;
  ck_assert_int_eq(s21_sprintf(my, "%lx", num), sprintf(original, "%lx", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_long_max_hex) {
  char original[100];
  char my[100];
  unsigned long int num = ULONG_MAX;
  ck_assert_int_eq(s21_sprintf(my, "%lx", num), sprintf(original, "%lx", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_many_hex) {
  char original[100];
  char my[100];
  ck_assert_int_eq(
      s21_sprintf(my, "%xHello,world@%x %x55656%x", 0x1u, 0x2u, 0x3u, 0x4u),
      sprintf(original, "%xHello,world@%x %x55656%x", 0x1u, 0x2u, 0x3u, 0x4u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_single_hex_with_width) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%10x", 0x123u),
                   sprintf(original, "%10x", 0x123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_single_hex_with_width_and_left_align) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%-10x", 0x123u),
                   sprintf(original, "%-10x", 0x123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_single_hex_with_width_and_fill) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%010x", 0x123u),
                   sprintf(original, "%010x", 0x123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_hex_with_width) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%10x", 0x123u),
                   sprintf(original, "%10x", 0x123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_hex_with_zero_fill) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%010x", 0x123u),
                   sprintf(original, "%010x", 0x123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_hex_with_all_flags) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%-15x", 0x123u),
                   sprintf(original, "%-15x", 0x123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_zero_value_with_flags) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%05x", 0u), sprintf(original, "%05x", 0u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_precision_hex) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%.5x", 0x42u),
                   sprintf(original, "%.5x", 0x42u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_precision_hex_zero) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%.3x", 0u), sprintf(original, "%.3x", 0u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_precision_width) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%10.5x", 0x123u),
                   sprintf(original, "%10.5x", 0x123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_precision_minus_flag) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%-10.5x", 0x123u),
                   sprintf(original, "%-10.5x", 0x123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_precision_zero_and_num_zero) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%.0x", 0u), sprintf(original, "%.0x", 0u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_hex_alternate_form) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%#x", 0x123u),
                   sprintf(original, "%#x", 0x123u));
  ck_assert_str_eq(my, original);
}
END_TEST

Suite *s21_sprintf_x_suite(void) {
  Suite *s = suite_create("s21_sprintf_x");
  TCase *tc = tcase_create("Core");
  tcase_add_test(tc, test_s21_sprintf_single_hex);
  tcase_add_test(tc, test_s21_sprintf_short_positive_hex);
  tcase_add_test(tc, test_s21_sprintf_short_max_hex);
  tcase_add_test(tc, test_s21_sprintf_long_positive_hex);
  tcase_add_test(tc, test_s21_sprintf_long_max_hex);
  tcase_add_test(tc, test_s21_sprintf_many_hex);
  tcase_add_test(tc, test_s21_sprintf_single_hex_with_width);
  tcase_add_test(tc, test_s21_sprintf_single_hex_with_width_and_left_align);
  tcase_add_test(tc, test_s21_sprintf_single_hex_with_width_and_fill);
  tcase_add_test(tc, test_s21_sprintf_hex_with_width);
  tcase_add_test(tc, test_s21_sprintf_hex_with_zero_fill);
  tcase_add_test(tc, test_s21_sprintf_hex_with_all_flags);
  tcase_add_test(tc, test_s21_sprintf_zero_value_with_flags);
  tcase_add_test(tc, test_s21_sprintf_precision_hex);
  tcase_add_test(tc, test_s21_sprintf_precision_hex_zero);
  tcase_add_test(tc, test_s21_sprintf_precision_width);
  tcase_add_test(tc, test_s21_sprintf_precision_minus_flag);
  tcase_add_test(tc, test_s21_sprintf_precision_zero_and_num_zero);
  tcase_add_test(tc, test_s21_sprintf_hex_alternate_form);
  suite_add_tcase(s, tc);
  return s;
}