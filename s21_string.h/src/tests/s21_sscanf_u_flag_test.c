#include <check.h>
#include <limits.h>
#include <stdio.h>

#include "../s21_string.h"

START_TEST(test_s21_sscanf_u_basic) {
  const char *input = "12345";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%u", &a), sscanf(input, "%u", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_u_zero) {
  const char *input = "0";
  unsigned int a = 1, b = 1;
  ck_assert_int_eq(s21_sscanf(input, "%u", &a), sscanf(input, "%u", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_u_max) {
  char input[20];
  sprintf(input, "%u", (unsigned int)UINT_MAX);
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%u", &a), sscanf(input, "%u", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_u_overflow) {
  const char *input = "4294967296";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%u", &a), sscanf(input, "%u", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_u_multiple) {
  const char *input = "123 456 789";
  unsigned int a1 = 0, a2 = 0, a3 = 0;
  unsigned int b1 = 0, b2 = 0, b3 = 0;
  ck_assert_int_eq(s21_sscanf(input, "%u %u %u", &a1, &a2, &a3),
                   sscanf(input, "%u %u %u", &b1, &b2, &b3));
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
}
END_TEST

START_TEST(test_s21_sscanf_u_with_width) {
  const char *input = "123456789";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%5u", &a), sscanf(input, "%5u", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_u_no_output) {
  const char *input = "12345";
  ck_assert_int_eq(s21_sscanf(input, "%*u"), sscanf(input, "%*u"));
}
END_TEST

START_TEST(test_s21_sscanf_u_invalid) {
  const char *input = "abc";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%u", &a), sscanf(input, "%u", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_u_hex_input) {
  const char *input = "0x123";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%u", &a), sscanf(input, "%u", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_u_octal_input) {
  const char *input = "0123";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%u", &a), sscanf(input, "%u", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_u_long) {
  const char *input = "123456";
  unsigned long a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%lu", &a), sscanf(input, "%lu", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_u_short) {
  const char *input = "123";
  unsigned short a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf(input, "%hu", &a), sscanf(input, "%hu", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

Suite *s21_sscanf_u_suite(void) {
  Suite *s = suite_create("s21_sscanf_u");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_sscanf_u_basic);
  tcase_add_test(tc_core, test_s21_sscanf_u_zero);
  tcase_add_test(tc_core, test_s21_sscanf_u_max);
  tcase_add_test(tc_core, test_s21_sscanf_u_overflow);
  tcase_add_test(tc_core, test_s21_sscanf_u_multiple);
  tcase_add_test(tc_core, test_s21_sscanf_u_with_width);
  tcase_add_test(tc_core, test_s21_sscanf_u_no_output);
  tcase_add_test(tc_core, test_s21_sscanf_u_invalid);
  tcase_add_test(tc_core, test_s21_sscanf_u_hex_input);
  tcase_add_test(tc_core, test_s21_sscanf_u_octal_input);
  tcase_add_test(tc_core, test_s21_sscanf_u_long);
  tcase_add_test(tc_core, test_s21_sscanf_u_short);

  suite_add_tcase(s, tc_core);

  return s;
}