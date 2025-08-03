#include <check.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_sprintf_single_number) {
  char original[100];
  char my[100];
  int original_n = 0;
  int my_n = 0;
  ck_assert_int_eq(s21_sprintf(my, "%n", &my_n),
                   sprintf(original, "%n", &original_n));
  ck_assert_str_eq(my, original);
  ck_assert_int_eq(my_n, original_n);
}
END_TEST

START_TEST(test_s21_sprintf_many_numbers) {
  char original[100];
  char my[100];
  int original_n_1 = 0;
  int my_n_1 = 0;
  int original_n_2 = 0;
  int my_n_2 = 0;
  ck_assert_int_eq(
      s21_sprintf(my, "Hel%nlo, world!%n", &my_n_1, &my_n_2),
      sprintf(original, "Hel%nlo, world!%n", &original_n_1, &original_n_2));
  ck_assert_str_eq(my, original);
  ck_assert_int_eq(my_n_1, original_n_1);
  ck_assert_int_eq(my_n_2, original_n_2);
}
END_TEST

START_TEST(test_s21_sprintf_single_number_short) {
  char original[100];
  char my[100];
  short int original_n = 0;
  short int my_n = 0;
  ck_assert_int_eq(s21_sprintf(my, "Hello, world!%hn", &my_n),
                   sprintf(original, "Hello, world!%hn", &original_n));
  ck_assert_str_eq(my, original);
  ck_assert_int_eq(my_n, original_n);
}
END_TEST

START_TEST(test_s21_sprintf_single_number_long) {
  char original[100];
  char my[100];
  long int original_n = 0;
  long int my_n = 0;
  ck_assert_int_eq(s21_sprintf(my, "Hello, world!%ln", &my_n),
                   sprintf(original, "Hello, world!%ln", &original_n));
  ck_assert_str_eq(my, original);
  ck_assert_int_eq(my_n, original_n);
}
END_TEST

Suite *s21_sprintf_n_suite(void) {
  Suite *s = suite_create("s21_sprintf_n");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_sprintf_single_number);
  tcase_add_test(tc, test_s21_sprintf_many_numbers);
  tcase_add_test(tc, test_s21_sprintf_single_number_short);
  tcase_add_test(tc, test_s21_sprintf_single_number_long);

  suite_add_tcase(s, tc);
  return s;
}