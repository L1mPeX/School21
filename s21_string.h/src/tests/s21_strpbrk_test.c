#include <check.h>

#include "../s21_string.h"

START_TEST(test_s21_strpbrk_no_matches_and_variable_str1) {
  const char str1[] = "hello";
  const char str2[] = "hello";
  ck_assert_ptr_null(s21_strpbrk(str1, "xyz"));
  ck_assert_ptr_null(strpbrk(str2, "xyz"));
}
END_TEST

START_TEST(test_s21_strpbrk_empty_str1) {
  ck_assert_ptr_eq(s21_strpbrk("", "abc"), strpbrk("", "abc"));
}
END_TEST

START_TEST(test_s21_strpbrk_empty_str2) {
  ck_assert_ptr_eq(s21_strpbrk("hello", ""), strpbrk("hello", ""));
}
END_TEST

START_TEST(test_s21_strpbrk_match_at_start) {
  ck_assert_ptr_eq(s21_strpbrk("hello", "h"), strpbrk("hello", "h"));
}
END_TEST

START_TEST(test_s21_strpbrk_match_at_end) {
  ck_assert_ptr_eq(s21_strpbrk("hello", "o"), strpbrk("hello", "o"));
}
END_TEST

START_TEST(test_s21_strpbrk_multiple_matches) {
  ck_assert_ptr_eq(s21_strpbrk("hello", "loe"), strpbrk("hello", "loe"));
}
END_TEST

Suite *s21_strpbrk_suite(void) {
  Suite *s = suite_create("s21_strpbrk");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_strpbrk_no_matches_and_variable_str1);
  tcase_add_test(tc, test_s21_strpbrk_empty_str1);
  tcase_add_test(tc, test_s21_strpbrk_empty_str2);
  tcase_add_test(tc, test_s21_strpbrk_match_at_start);
  tcase_add_test(tc, test_s21_strpbrk_match_at_end);
  tcase_add_test(tc, test_s21_strpbrk_multiple_matches);

  suite_add_tcase(s, tc);
  return s;
}