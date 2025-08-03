#include <check.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_sprintf_single_procent) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%%"), sprintf(original, "%%"));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_many_procents) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%%%%%% %% %% %%%%%%%%%%%%%%"),
                   sprintf(original, "%%%%%% %% %% %%%%%%%%%%%%%%"));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_many_procents_with_other_data) {
  char original[100];
  char my[100];
  ck_assert_int_eq(
      s21_sprintf(my, "%%%%%% %% %% %%%%%%%%%%%%%% %%%s%% %%%s%% %%%c%% %%",
                  "hello", "world", '!'),
      sprintf(original, "%%%%%% %% %% %%%%%%%%%%%%%% %%%s%% %%%s%% %%%c%% %%",
              "hello", "world", '!'));
  ck_assert_str_eq(my, original);
}
END_TEST

Suite *s21_sprintf_percent_suite(void) {
  Suite *s = suite_create("s21_sprintf_percent");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_sprintf_single_procent);
  tcase_add_test(tc, test_s21_sprintf_many_procents);
  tcase_add_test(tc, test_s21_sprintf_many_procents_with_other_data);

  suite_add_tcase(s, tc);
  return s;
}