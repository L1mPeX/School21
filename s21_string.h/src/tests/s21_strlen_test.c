#include <check.h>

#include "../s21_string.h"

START_TEST(test_s21_strlen_empty) {
  ck_assert_uint_eq(s21_strlen(""), strlen(""));
}
END_TEST

START_TEST(test_s21_strlen_basic) {
  ck_assert_uint_eq(s21_strlen("hello"), strlen("hello"));
}
END_TEST

START_TEST(test_s21_strlen_with_null) {
  ck_assert_uint_eq(s21_strlen("hello\0 world"), strlen("hello\0 world"));
}
END_TEST

START_TEST(test_s21_strlen_single_null) {
  ck_assert_uint_eq(s21_strlen("\0"), strlen("\0"));
}
END_TEST

START_TEST(test_s21_strlen_multiple_words) {
  ck_assert_uint_eq(s21_strlen("hello world"), strlen("hello world"));
}
END_TEST

Suite *s21_strlen_suite(void) {
  Suite *s = suite_create("s21_strlen");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_strlen_empty);
  tcase_add_test(tc, test_s21_strlen_basic);
  tcase_add_test(tc, test_s21_strlen_with_null);
  tcase_add_test(tc, test_s21_strlen_single_null);
  tcase_add_test(tc, test_s21_strlen_multiple_words);

  suite_add_tcase(s, tc);
  return s;
}