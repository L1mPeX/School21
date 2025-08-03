#include <check.h>

#include "../s21_string.h"

START_TEST(test_s21_strcspn_no_matches) {
  ck_assert_uint_eq(s21_strcspn("hello", "xyz"), strcspn("hello", "xyz"));
}
END_TEST

START_TEST(test_s21_strcspn_empty_str1) {
  ck_assert_uint_eq(s21_strcspn("", "abc"), strcspn("", "abc"));
}
END_TEST

START_TEST(test_s21_strcspn_empty_str2) {
  ck_assert_uint_eq(s21_strcspn("hello", ""), strcspn("hello", ""));
}
END_TEST

START_TEST(test_s21_strcspn_match_at_start) {
  ck_assert_uint_eq(s21_strcspn("hello", "h"), strcspn("hello", "h"));
}
END_TEST

START_TEST(test_s21_strcspn_match_at_end) {
  ck_assert_uint_eq(s21_strcspn("hello", "o"), strcspn("hello", "o"));
}
END_TEST

START_TEST(test_s21_strcspn_multiple_matches) {
  ck_assert_uint_eq(s21_strcspn("hello", "loe"), strcspn("hello", "loe"));
}
END_TEST

Suite *s21_strcspn_suite(void) {
  Suite *s = suite_create("s21_strcspn");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_strcspn_no_matches);
  tcase_add_test(tc, test_s21_strcspn_empty_str1);
  tcase_add_test(tc, test_s21_strcspn_empty_str2);
  tcase_add_test(tc, test_s21_strcspn_match_at_start);
  tcase_add_test(tc, test_s21_strcspn_match_at_end);
  tcase_add_test(tc, test_s21_strcspn_multiple_matches);

  suite_add_tcase(s, tc);
  return s;
}