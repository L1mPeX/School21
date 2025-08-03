#include <check.h>
#include <ctype.h>
#include <stdlib.h>

#include "../s21_string.h"

START_TEST(test_s21_to_lower_only_low) {
  void *res = s21_to_lower("qwerty");
  ck_assert_str_eq(res, "qwerty");
  free(res);
}
END_TEST

START_TEST(test_s21_to_lower_only_high) {
  void *res = s21_to_lower("QWERTY");
  ck_assert_str_eq(res, "qwerty");
  free(res);
}
END_TEST

START_TEST(test_s21_to_lower_normal) {
  void *res = s21_to_lower("Nasha Russia");
  ck_assert_str_eq(res, "nasha russia");
  free(res);
}
END_TEST

START_TEST(test_s21_to_lower_empty) {
  void *res = s21_to_lower("");
  ck_assert_str_eq(res, "");
  free(res);
}
END_TEST

START_TEST(test_s21_to_lower_other_symbols) {
  void *res = s21_to_lower("QWERTY && qwertyA");
  ck_assert_str_eq(res, "qwerty && qwertya");
  free(res);
}
END_TEST

START_TEST(test_s21_to_lower_only_other_symbols) {
  void *res = s21_to_lower("1234567890,.32=");
  ck_assert_str_eq(res, "1234567890,.32=");
  free(res);
}
END_TEST

Suite *s21_to_lower_suite(void) {
  Suite *s = suite_create("s21_to_lower");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_to_lower_only_low);
  tcase_add_test(tc, test_s21_to_lower_only_high);
  tcase_add_test(tc, test_s21_to_lower_normal);
  tcase_add_test(tc, test_s21_to_lower_empty);
  tcase_add_test(tc, test_s21_to_lower_other_symbols);
  tcase_add_test(tc, test_s21_to_lower_only_other_symbols);

  suite_add_tcase(s, tc);
  return s;
}