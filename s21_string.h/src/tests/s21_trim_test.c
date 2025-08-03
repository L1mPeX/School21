#include <check.h>
#include <stdlib.h>

#include "../s21_string.h"

START_TEST(test_s21_trim_space) {
  void *res = s21_trim(" kilka ", " ");
  ck_assert_str_eq(res, "kilka");
  free(res);
}
END_TEST

START_TEST(test_s21_trim_many_symbols) {
  void *res = s21_trim("\n kilka ,", " \n,");
  ck_assert_str_eq(res, "kilka");
  free(res);
}
END_TEST

START_TEST(test_s21_trim_many_matches_in_str) {
  void *res = s21_trim(" kilka, qwerty ", " k,y");
  ck_assert_str_eq(res, "ilka, qwert");
  free(res);
}
END_TEST

START_TEST(test_s21_trim_empty_src) {
  void *res = s21_trim("", " k,y");
  ck_assert_str_eq(res, "");
  free(res);
}
END_TEST

START_TEST(test_s21_trim_empty_trim_chars) {
  void *res = s21_trim("\tqwerty\n ", "");
  ck_assert_str_eq(res, "qwerty");
  free(res);
}
END_TEST

START_TEST(test_s21_trim_null_ptr_src) {
  void *res = s21_trim(S21_NULL, "");
  ck_assert_ptr_null(res);
  free(res);
}
END_TEST

START_TEST(test_s21_trim_null_ptr_trim_chars) {
  void *res = s21_trim("qwerty", S21_NULL);
  ck_assert_ptr_null(res);
  free(res);
}
END_TEST

START_TEST(test_s21_trim_null_ptr_all) {
  void *res = s21_trim(S21_NULL, S21_NULL);
  ck_assert_ptr_null(res);
  free(res);
}
END_TEST

Suite *s21_trim_suite(void) {
  Suite *s = suite_create("s21_trim");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_trim_space);
  tcase_add_test(tc, test_s21_trim_many_symbols);
  tcase_add_test(tc, test_s21_trim_many_matches_in_str);
  tcase_add_test(tc, test_s21_trim_empty_src);
  tcase_add_test(tc, test_s21_trim_empty_trim_chars);
  tcase_add_test(tc, test_s21_trim_null_ptr_src);
  tcase_add_test(tc, test_s21_trim_null_ptr_trim_chars);
  tcase_add_test(tc, test_s21_trim_null_ptr_all);

  suite_add_tcase(s, tc);
  return s;
}