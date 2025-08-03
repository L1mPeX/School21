#include <check.h>
#include <stdio.h>

#include "../s21_string.h"

START_TEST(test_s21_sscanf_c_basic) {
  const char *input = "A";
  char a = '\0', b = '\0';
  ck_assert_int_eq(s21_sscanf(input, "%c", &a), sscanf(input, "%c", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_c_multiple) {
  const char *input = "ABC";
  char a1 = '\0', a2 = '\0', a3 = '\0';
  char b1 = '\0', b2 = '\0', b3 = '\0';
  ck_assert_int_eq(s21_sscanf(input, "%c%c%c", &a1, &a2, &a3),
                   sscanf(input, "%c%c%c", &b1, &b2, &b3));
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
}
END_TEST

START_TEST(test_s21_sscanf_c_width) {
  const char *input = "ABCDE";
  char a[4] = {0}, b[4] = {0};
  ck_assert_int_eq(s21_sscanf(input, "%3c", a), sscanf(input, "%3c", b));
  ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_c_whitespace) {
  const char *input = "   X";
  char a = '\0', b = '\0';
  ck_assert_int_eq(s21_sscanf(input, "%c", &a), sscanf(input, "%c", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_c_no_output) {
  const char *input = "X";
  ck_assert_int_eq(s21_sscanf(input, "%*c"), sscanf(input, "%*c"));
}
END_TEST

START_TEST(test_s21_sscanf_c_empty_input) {
  const char *input = "";
  char a = 'Z', b = 'Z';
  ck_assert_int_eq(s21_sscanf(input, "%c", &a), sscanf(input, "%c", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

Suite *s21_sscanf_c_suite(void) {
  Suite *s = suite_create("s21_sscanf_c");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_sscanf_c_basic);
  tcase_add_test(tc, test_s21_sscanf_c_multiple);
  tcase_add_test(tc, test_s21_sscanf_c_width);
  tcase_add_test(tc, test_s21_sscanf_c_whitespace);
  tcase_add_test(tc, test_s21_sscanf_c_no_output);
  tcase_add_test(tc, test_s21_sscanf_c_empty_input);

  suite_add_tcase(s, tc);
  return s;
}