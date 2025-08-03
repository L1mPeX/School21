#include <check.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_sprintf_one_char) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%c", 'h'), sprintf(original, "%c", 'h'));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_many_chars) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%c%c%c%c%c %c%c%c%c%c%c", 'h', 'e', 'l',
                               'l', 'o', 'w', 'o', 'r', 'l', 'd', '!'),
                   sprintf(original, "%c%c%c%c%c %c%c%c%c%c%c", 'h', 'e', 'l',
                           'l', 'o', 'w', 'o', 'r', 'l', 'd', '!'));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_width_one_char) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%10c.", 'h'),
                   sprintf(original, "%10c.", 'h'));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_width_many_chars) {
  char original[100];
  char my[100];
  ck_assert_int_eq(
      s21_sprintf(my, "%10c. %9c. %2c. %3c.", 'h', 'h', 'h', 'h'),
      sprintf(original, "%10c. %9c. %2c. %3c.", 'h', 'h', 'h', 'h'));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_width_one_char_with_flag_left_alig) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%-10c.", 'h'),
                   sprintf(original, "%-10c.", 'h'));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_width_many_chars_with_flag_left_alig) {
  char original[100];
  char my[100];
  ck_assert_int_eq(
      s21_sprintf(my, "%-10c. %-9c. %-c. %-c.", 'h', 'h', 'h', 'h'),
      sprintf(original, "%-10c. %-9c. %-c. %-c.", 'h', 'h', 'h', 'h'));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_width_many_chars_with_sign) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%*c. %-*c.", 10, 'h', 9, 'g'),
                   sprintf(original, "%*c. %-*c.", 10, 'h', 9, 'g'));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_char_with_zero_width) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%5c", 'A'), sprintf(original, "%5c", 'A'));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_char_with_multiple_flags) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%-5c", 'B'),
                   sprintf(original, "%-5c", 'B'));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_char_with_zero) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "Hello, %c !", 0),
                   sprintf(original, "Hello, %c !", 0));
  ck_assert_str_eq(my, original);
}
END_TEST

Suite *s21_sprintf_c_suite(void) {
  Suite *s = suite_create("s21_sprintf_c");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_sprintf_one_char);
  tcase_add_test(tc, test_s21_sprintf_many_chars);
  tcase_add_test(tc, test_s21_sprintf_width_one_char);
  tcase_add_test(tc, test_s21_sprintf_width_many_chars);
  tcase_add_test(tc, test_s21_sprintf_width_one_char_with_flag_left_alig);
  tcase_add_test(tc, test_s21_sprintf_width_many_chars_with_flag_left_alig);
  tcase_add_test(tc, test_s21_sprintf_width_many_chars_with_sign);
  tcase_add_test(tc, test_s21_sprintf_char_with_zero_width);
  tcase_add_test(tc, test_s21_sprintf_char_with_multiple_flags);
  tcase_add_test(tc, test_s21_sprintf_char_with_zero);

  suite_add_tcase(s, tc);
  return s;
}