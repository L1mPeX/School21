#include <check.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_sprintf_one_string) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%s", "Hello, world!"),
                   sprintf(original, "%s", "Hello, world!"));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_many_strings) {
  char original[100];
  char my[100];
  ck_assert_int_eq(
      s21_sprintf(my, "%s %s", "Hello, world!", "My name is Ivan."),
      sprintf(original, "%s %s", "Hello, world!", "My name is Ivan."));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_many_strings_with_precision) {
  char original[100];
  char my[100];
  ck_assert_int_eq(
      s21_sprintf(my, "%.1s. %.20s.", "Hello, world!", "My name is Ivan."),
      sprintf(original, "%.1s. %.20s.", "Hello, world!", "My name is Ivan."));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_many_strings_with_precision_with_width) {
  char original[100];
  char my[100];
  ck_assert_int_eq(
      s21_sprintf(my, "%20.1s. %30.20s.", "Hello, world!", "My name is Ivan."),
      sprintf(original, "%20.1s. %30.20s.", "Hello, world!",
              "My name is Ivan."));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(
    test_s21_sprintf_many_strings_with_precision_with_width_with_left_alig) {
  char original[100];
  char my[100];
  ck_assert_int_eq(
      s21_sprintf(my, "%-1.1s. %-14.17s.", "Hello, world!", "My name is Ivan."),
      sprintf(original, "%-1.1s. %-14.17s.", "Hello, world!",
              "My name is Ivan."));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_many_strings_with_null) {
  char original[100];
  char my[100];
  const char *null_replacement = "(null)";
  ck_assert_int_eq(
      s21_sprintf(my, "%-1.1s. %-14.17s.", null_replacement, null_replacement),
      sprintf(original, "%-1.1s. %-14.17s.", null_replacement,
              null_replacement));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_empty_string) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%s", ""), sprintf(original, "%s", ""));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_string_with_zero_precision) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%.0s", "Hello"),
                   sprintf(original, "%.0s", "Hello"));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_string_with_large_width) {
  char original[200];
  char my[200];
  ck_assert_int_eq(s21_sprintf(my, "%100s", "Test"),
                   sprintf(original, "%100s", "Test"));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_string_with_width_less_than_length) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%2s", "LongString"),
                   sprintf(original, "%2s", "LongString"));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_string_with_precision_greater_than_length) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%.20s", "Short"),
                   sprintf(original, "%.20s", "Short"));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_mixed_format) {
  char original[200];
  char my[200];
  ck_assert_int_eq(
      s21_sprintf(my, "Char: %-5c, String: %10.3s", 'X', "HelloWorld"),
      sprintf(original, "Char: %-5c, String: %10.3s", 'X', "HelloWorld"));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_null_string_with_precision) {
  char original[100];
  char my[100];
  const char *null_replacement = "(null)";
  ck_assert_int_eq(s21_sprintf(my, "%.8s", null_replacement),
                   sprintf(original, "%.8s", null_replacement));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_many_strings_with_null_with_precision) {
  char original[100];
  char my[100];
  const char *null_replacement = "(null)";
  ck_assert_int_eq(
      s21_sprintf(my, "%.0s. %.1s. %.5s %.6s", null_replacement,
                  null_replacement, null_replacement, null_replacement),
      sprintf(original, "%.0s. %.1s. %.5s %.6s", null_replacement,
              null_replacement, null_replacement, null_replacement));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(
    test_s21_sprintf_many_strings_with_null_with_precision_and_left_aligment) {
  char original[100];
  char my[100];
  const char *null_replacement = "(null)";
  ck_assert_int_eq(
      s21_sprintf(my, "%-.0s. %-.1s. %-.5s %-.6s", null_replacement,
                  null_replacement, null_replacement, null_replacement),
      sprintf(original, "%-.0s. %-.1s. %-.5s %-.6s", null_replacement,
              null_replacement, null_replacement, null_replacement));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_string_with_star_width) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%*s", 8, "test"),
                   sprintf(original, "%*s", 8, "test"));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_string_with_star_precision) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%.*s", 3, "testing"),
                   sprintf(original, "%.*s", 3, "testing"));
  ck_assert_str_eq(my, original);
}
END_TEST

Suite *s21_sprintf_s_suite(void) {
  Suite *s = suite_create("s21_sprintf_s");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_sprintf_one_string);
  tcase_add_test(tc, test_s21_sprintf_many_strings);
  tcase_add_test(tc, test_s21_sprintf_many_strings_with_precision);
  tcase_add_test(tc, test_s21_sprintf_many_strings_with_precision_with_width);
  tcase_add_test(
      tc,
      test_s21_sprintf_many_strings_with_precision_with_width_with_left_alig);
  tcase_add_test(tc, test_s21_sprintf_many_strings_with_null);
  tcase_add_test(tc, test_s21_sprintf_many_strings_with_null_with_precision);
  tcase_add_test(
      tc,
      test_s21_sprintf_many_strings_with_null_with_precision_and_left_aligment);
  tcase_add_test(tc, test_s21_sprintf_empty_string);
  tcase_add_test(tc, test_s21_sprintf_string_with_zero_precision);
  tcase_add_test(tc, test_s21_sprintf_string_with_large_width);
  tcase_add_test(tc, test_s21_sprintf_string_with_width_less_than_length);
  tcase_add_test(tc,
                 test_s21_sprintf_string_with_precision_greater_than_length);
  tcase_add_test(tc, test_s21_sprintf_mixed_format);
  tcase_add_test(tc, test_s21_sprintf_null_string_with_precision);
  tcase_add_test(tc, test_s21_sprintf_string_with_star_width);
  tcase_add_test(tc, test_s21_sprintf_string_with_star_precision);

  suite_add_tcase(s, tc);
  return s;
}