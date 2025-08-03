#include <check.h>
#include <stdio.h>

#include "../s21_string.h"

START_TEST(test_s21_sscanf_s_empty) {
  const char *input = "";
  char a[10] = {0}, b[10] = {0};
  ck_assert_int_eq(s21_sscanf(input, "%9s", a), sscanf(input, "%9s", b));
  ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_s_basic) {
  const char *input = "Hello";
  char a[10] = {0}, b[10] = {0};
  ck_assert_int_eq(s21_sscanf(input, "%9s", a), sscanf(input, "%9s", b));
  ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_s_with_spaces) {
  const char *input = "Hello world";
  char a[10] = {0}, b[10] = {0};
  ck_assert_int_eq(s21_sscanf(input, "%9s", a), sscanf(input, "%9s", b));
  ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_s_width) {
  const char *input = "Hello";
  char a[10] = {0}, b[10] = {0};
  ck_assert_int_eq(s21_sscanf(input, "%3s", a), sscanf(input, "%3s", b));
  ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_s_no_assign) {
  const char *input = "Hello";
  ck_assert_int_eq(s21_sscanf(input, "%*9s"), sscanf(input, "%*9s"));
}
END_TEST

START_TEST(test_s21_sscanf_s_multiple) {
  const char *input = "Hello world";
  char a1[10] = {0}, a2[10] = {0};
  char b1[10] = {0}, b2[10] = {0};
  ck_assert_int_eq(s21_sscanf(input, "%9s %9s", a1, a2),
                   sscanf(input, "%9s %9s", b1, b2));
  ck_assert_str_eq(a1, b1);
  ck_assert_str_eq(a2, b2);
}
END_TEST

START_TEST(test_s21_sscanf_s_special_chars) {
  const char *input = "H3ll0_w0rld!";
  char a[20] = {0}, b[20] = {0};
  ck_assert_int_eq(s21_sscanf(input, "%19s", a), sscanf(input, "%19s", b));
  ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_s_long_string) {
  const char *input = "This_is_a_very_long_string_that_should_be_truncated";
  char a[60] = {0}, b[60] = {0};
  ck_assert_int_eq(s21_sscanf(input, "%59s", a), sscanf(input, "%59s", b));
  ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_s_only_spaces) {
  const char *input = "                    ";
  char a[20] = {0}, b[20] = {0};
  ck_assert_int_eq(s21_sscanf(input, "%19s", a), sscanf(input, "%19s", b));
  ck_assert_str_eq(a, b);
}
END_TEST

Suite *s21_sscanf_s_suite(void) {
  Suite *s = suite_create("s21_sscanf_s");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_sscanf_s_empty);
  tcase_add_test(tc, test_s21_sscanf_s_basic);
  tcase_add_test(tc, test_s21_sscanf_s_with_spaces);
  tcase_add_test(tc, test_s21_sscanf_s_width);
  tcase_add_test(tc, test_s21_sscanf_s_no_assign);
  tcase_add_test(tc, test_s21_sscanf_s_multiple);
  tcase_add_test(tc, test_s21_sscanf_s_special_chars);
  tcase_add_test(tc, test_s21_sscanf_s_long_string);
  tcase_add_test(tc, test_s21_sscanf_s_only_spaces);

  suite_add_tcase(s, tc);
  return s;
}