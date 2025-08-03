#include <check.h>
#include <ctype.h>
#include <stdlib.h>

#include "../s21_string.h"

START_TEST(test_s21_to_upper_only_low) {
  void *res = s21_to_upper("qwerty");
  ck_assert_str_eq(res, "QWERTY");
  free(res);
}
END_TEST

START_TEST(test_s21_to_upper_only_high) {
  void *res = s21_to_upper("QWERTY");
  ck_assert_str_eq(res, "QWERTY");
  free(res);
}
END_TEST

START_TEST(test_s21_to_upper_normal) {
  void *res = s21_to_upper("Nasha Russia");
  ck_assert_str_eq(res, "NASHA RUSSIA");
  free(res);
}
END_TEST

START_TEST(test_s21_to_upper_empty) {
  void *res = s21_to_upper("");
  ck_assert_str_eq(res, "");
  free(res);
}
END_TEST

START_TEST(test_s21_to_upper_other_symbols) {
  void *res = s21_to_upper("QWERTY && qwertyA");
  ck_assert_str_eq(res, "QWERTY && QWERTYA");
  free(res);
}
END_TEST

START_TEST(test_s21_to_upper_only_other_symbols) {
  void *res = s21_to_upper("1234567890,.32=");
  ck_assert_str_eq(res, "1234567890,.32=");
  free(res);
}
END_TEST

Suite *s21_to_upper_suite(void) {
  Suite *s = suite_create("s21_to_upper");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_to_upper_only_low);
  tcase_add_test(tc, test_s21_to_upper_only_high);
  tcase_add_test(tc, test_s21_to_upper_normal);
  tcase_add_test(tc, test_s21_to_upper_empty);
  tcase_add_test(tc, test_s21_to_upper_other_symbols);
  tcase_add_test(tc, test_s21_to_upper_only_other_symbols);

  suite_add_tcase(s, tc);
  return s;
}