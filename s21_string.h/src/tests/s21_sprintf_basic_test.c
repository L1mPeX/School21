#include <check.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_sprintf_basic_string) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "hello, world!"),
                   sprintf(original, "hello, world!"));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_whitespace) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, " \n\n\n\t\t"),
                   sprintf(original, " \n\n\n\t\t"));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_single_space) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, " "), sprintf(original, " "));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_unicode) {
  char original[100];
  char my[100];
  setlocale(LC_ALL, "");
  ck_assert_int_eq(s21_sprintf(my, "Привет, мир!"),
                   sprintf(original, "Привет, мир!"));
  ck_assert_str_eq(my, original);
}
END_TEST

Suite *s21_sprintf_basic_suite(void) {
  Suite *s = suite_create("s21_sprintf_basic");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_sprintf_basic_string);
  tcase_add_test(tc, test_s21_sprintf_whitespace);
  tcase_add_test(tc, test_s21_sprintf_single_space);
  tcase_add_test(tc, test_s21_sprintf_unicode);

  suite_add_tcase(s, tc);
  return s;
}