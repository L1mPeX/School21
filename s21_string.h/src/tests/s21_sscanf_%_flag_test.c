#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_sscanf_percent_sign) {
  const char *input = "100%";
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf(input, "%d%%", &a), sscanf(input, "%d%%", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_double_percent) {
  const char *input = "50%% discount";
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf(input, "%d%%%% discount", &a),
                   sscanf(input, "%d%%%% discount", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_percent_only) {
  const char *input = "%";

  ck_assert_int_eq(s21_sscanf(input, "%%"), sscanf(input, "%%"));
}
END_TEST

START_TEST(test_s21_sscanf_percent_mismatch) {
  const char *input = "50 percent";
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf(input, "%d%%", &a), sscanf(input, "%d%%", &b));
}
END_TEST

START_TEST(test_s21_sscanf_percent_with_text) {
  const char *input = "Today 100% humidity";
  int a = 0, b = 0;
  char str1[20] = {0}, str2[20] = {0};

  ck_assert_int_eq(s21_sscanf(input, "Today %d%% %19s", &a, str1),
                   sscanf(input, "Today %d%% %19s", &b, str2));
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sscanf_percent_literal_match) {
  const char *input = "50%";
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf(input, "%d%%", &a), sscanf(input, "%d%%", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_percent_with_whitespace) {
  const char *input = "  75%  ";
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf(input, " %d%% ", &a),
                   sscanf(input, " %d%% ", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

Suite *s21_sscanf_percent_suite(void) {
  Suite *s = suite_create("s21_sscanf_percent");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_sscanf_percent_sign);
  tcase_add_test(tc, test_s21_sscanf_double_percent);
  tcase_add_test(tc, test_s21_sscanf_percent_only);
  tcase_add_test(tc, test_s21_sscanf_percent_mismatch);
  tcase_add_test(tc, test_s21_sscanf_percent_with_text);
  tcase_add_test(tc, test_s21_sscanf_percent_literal_match);
  tcase_add_test(tc, test_s21_sscanf_percent_with_whitespace);

  suite_add_tcase(s, tc);
  return s;
}