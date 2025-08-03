#include <check.h>

#include "../s21_string.h"

START_TEST(test_s21_memchr_1) {
  char *arg = "string";
  ck_assert_ptr_eq(s21_memchr(arg, 'r', 6), memchr(arg, 'r', 6));
}
END_TEST

START_TEST(test_s21_memchr_2) {
  char *arg = "string";
  ck_assert_ptr_eq(s21_memchr(arg, '\0', 7), memchr(arg, '\0', 7));
}
END_TEST

START_TEST(test_s21_memchr_empty) {
  char *arg = "string";
  ck_assert_ptr_eq(s21_memchr(arg, 119, 4), memchr(arg, 119, 4));
}
END_TEST

START_TEST(test_s21_memchr_number) {
  int a = 250;
  int *arg = &a;
  ck_assert_ptr_eq(s21_memchr(arg, 250, 4), memchr(arg, 250, 4));
}
END_TEST

START_TEST(test_s21_memchr_same_chars) {
  char *arg = "rrrrrrrrr";
  ck_assert_ptr_eq(s21_memchr(arg, 'r', 9), memchr(arg, 'r', 9));
}
END_TEST

Suite *s21_memchr_suite(void) {
  Suite *s = suite_create("s21_memchr");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_memchr_1);
  tcase_add_test(tc, test_s21_memchr_2);
  tcase_add_test(tc, test_s21_memchr_empty);
  tcase_add_test(tc, test_s21_memchr_number);
  tcase_add_test(tc, test_s21_memchr_same_chars);

  suite_add_tcase(s, tc);
  return s;
}