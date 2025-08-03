#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_string.h"

START_TEST(test_s21_sscanf_i_decimal) {
  const char *input = "12345";
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%i", &a), sscanf(input, "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_i_octal) {
  const char *input = "01234";
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%i", &a), sscanf(input, "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_i_hex_lower) {
  const char *input = "0x1a3f";
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%i", &a), sscanf(input, "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_i_hex_upper) {
  const char *input = "0XABCD";
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%i", &a), sscanf(input, "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_i_negative) {
  const char *input = "-12345";
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%i", &a), sscanf(input, "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_i_positive_sign) {
  const char *input = "+12345";
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%i", &a), sscanf(input, "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_i_zero) {
  const char *input = "0";
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%i", &a), sscanf(input, "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_i_octal_zero) {
  const char *input = "00";
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%i", &a), sscanf(input, "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_i_hex_zero) {
  const char *input = "0x0";
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%i", &a), sscanf(input, "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_i_max_int) {
  char input[20];
  snprintf(input, sizeof(input), "%d", (int)INT_MAX);  // Явное приведение типа
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%i", &a), sscanf(input, "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_i_min_int) {
  char input[20];
  snprintf(input, sizeof(input), "%d", (int)INT_MIN);  // Явное приведение типа
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%i", &a), sscanf(input, "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_i_multiple) {
  const char *input = "10 012 0xA";
  int a1 = 0, a2 = 0, a3 = 0;
  int b1 = 0, b2 = 0, b3 = 0;
  ck_assert_int_eq(s21_sscanf(input, "%i %i %i", &a1, &a2, &a3),
                   sscanf(input, "%i %i %i", &b1, &b2, &b3));
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
}
END_TEST

START_TEST(test_s21_sscanf_i_with_width) {
  const char *input = "123456789";
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%5i", &a), sscanf(input, "%5i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_i_no_output) {
  const char *input = "12345";
  ck_assert_int_eq(s21_sscanf(input, "%*i"), sscanf(input, "%*i"));
}
END_TEST

START_TEST(test_s21_sscanf_i_invalid) {
  const char *input = "abc";
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%i", &a), sscanf(input, "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

Suite *s21_sscanf_i_suite(void) {
  Suite *s = suite_create("s21_sscanf_i");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_sscanf_i_decimal);
  tcase_add_test(tc_core, test_s21_sscanf_i_octal);
  tcase_add_test(tc_core, test_s21_sscanf_i_hex_lower);
  tcase_add_test(tc_core, test_s21_sscanf_i_hex_upper);
  tcase_add_test(tc_core, test_s21_sscanf_i_negative);
  tcase_add_test(tc_core, test_s21_sscanf_i_positive_sign);
  tcase_add_test(tc_core, test_s21_sscanf_i_zero);
  tcase_add_test(tc_core, test_s21_sscanf_i_octal_zero);
  tcase_add_test(tc_core, test_s21_sscanf_i_hex_zero);
  tcase_add_test(tc_core, test_s21_sscanf_i_max_int);
  tcase_add_test(tc_core, test_s21_sscanf_i_min_int);
  tcase_add_test(tc_core, test_s21_sscanf_i_multiple);
  tcase_add_test(tc_core, test_s21_sscanf_i_with_width);
  tcase_add_test(tc_core, test_s21_sscanf_i_no_output);
  tcase_add_test(tc_core, test_s21_sscanf_i_invalid);

  suite_add_tcase(s, tc_core);

  return s;
}