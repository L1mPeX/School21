#include <check.h>

#include "../s21_string.h"

START_TEST(test_s21_strchr_existing_symbol) {
  const char *arg = "string";
  ck_assert_ptr_eq(s21_strchr(arg, 'r'), strchr(arg, 'r'));
  ck_assert_int_eq(*s21_strchr(arg, 'r'), 'r');
}
END_TEST

START_TEST(test_s21_strchr_not_existing_symbol) {
  const char *arg = "string";
  ck_assert_ptr_eq(s21_strchr(arg, 'm'), strchr(arg, 'm'));
}
END_TEST

START_TEST(test_s21_strchr_first_symbol) {
  const char *arg = "string rrrrrrrrr";
  ck_assert_ptr_eq(s21_strchr(arg, 'r'), strchr(arg, 'r'));
  ck_assert_int_eq(*s21_strchr(arg, 'r'), 'r');
}
END_TEST

START_TEST(test_s21_strchr_zero_byte) {
  const char *arg = "string";
  ck_assert_ptr_eq(s21_strchr(arg, '\0'), strchr(arg, '\0'));
  ck_assert_int_eq(*s21_strchr(arg, '\0'), '\0');
}
END_TEST

START_TEST(test_s21_strchr_empty_string) {
  const char *arg = "";
  ck_assert_ptr_eq(s21_strchr(arg, 'o'), strchr(arg, 'o'));
}
END_TEST

START_TEST(test_s21_strchr_zero_byte_in_empty_string) {
  const char *arg = "";
  ck_assert_ptr_eq(s21_strchr(arg, '\0'), strchr(arg, '\0'));
  ck_assert_int_eq(*s21_strchr(arg, '\0'), '\0');
}
END_TEST

START_TEST(test_s21_strchr_character_code) {
  const char *arg = "warning";
  ck_assert_ptr_eq(s21_strchr(arg, 119), strchr(arg, 119));
  ck_assert_int_eq(*s21_strchr(arg, 119), 119);
}
END_TEST

Suite *s21_strchr_suite(void) {
  Suite *s = suite_create("s21_strchr");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_strchr_character_code);
  tcase_add_test(tc, test_s21_strchr_empty_string);
  tcase_add_test(tc, test_s21_strchr_existing_symbol);
  tcase_add_test(tc, test_s21_strchr_first_symbol);
  tcase_add_test(tc, test_s21_strchr_not_existing_symbol);
  tcase_add_test(tc, test_s21_strchr_zero_byte);
  tcase_add_test(tc, test_s21_strchr_zero_byte_in_empty_string);

  suite_add_tcase(s, tc);
  return s;
}