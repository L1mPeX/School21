#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_sscanf_n_multiple) {
  const char *input = "123 456 789";
  int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(s21_sscanf(input, "%d%n %d%n", &a1, &n1, &a2, &n2),
                   sscanf(input, "%d%n %d%n", &b1, &n3, &b2, &n4));
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(n1, n3);
  ck_assert_int_eq(n2, n4);
}
END_TEST

START_TEST(test_s21_sscanf_n_with_text) {
  const char *input = "Number: 42, Next: 73";
  int n1 = 0, n2 = 0;
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(s21_sscanf(input, "Number: %d%n, Next: %d", &a1, &n1, &a2),
                   sscanf(input, "Number: %d%n, Next: %d", &b1, &n2, &b2));
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_s21_sscanf_n_after_failure) {
  const char *input = "abc123";
  int n1 = 0, n2 = 0;
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%d%n", &a, &n1),
                   sscanf(input, "%d%n", &b, &n2));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_s21_sscanf_n_empty_input) {
  const char *input = "";
  int n1 = 0, n2 = 0;
  ck_assert_int_eq(s21_sscanf(input, "%n", &n1), sscanf(input, "%n", &n2));
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_s21_sscanf_n_only) {
  const char *input = "Hello";
  int n1 = 0, n2 = 0;
  ck_assert_int_eq(s21_sscanf(input, "%n", &n1), sscanf(input, "%n", &n2));
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_s21_sscanf_n_with_width) {
  const char *input = "123456789";
  int n1 = 0, n2 = 0;
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%3d%n", &a, &n1),
                   sscanf(input, "%3d%n", &b, &n2));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(n1, n2);
}
END_TEST

Suite *s21_sscanf_n_suite(void) {
  Suite *s = suite_create("s21_sscanf_n");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_sscanf_n_multiple);
  tcase_add_test(tc, test_s21_sscanf_n_with_text);
  tcase_add_test(tc, test_s21_sscanf_n_after_failure);
  tcase_add_test(tc, test_s21_sscanf_n_empty_input);
  tcase_add_test(tc, test_s21_sscanf_n_only);
  tcase_add_test(tc, test_s21_sscanf_n_with_width);

  suite_add_tcase(s, tc);
  return s;
}