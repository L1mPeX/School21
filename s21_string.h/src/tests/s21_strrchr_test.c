#include <check.h>

#include "../s21_string.h"

START_TEST(test_s21_strrchr_existing_symbol_normal) {
  const char *arg = "string";
  ck_assert_ptr_eq(s21_strrchr(arg, 'r'), strrchr(arg, 'r'));
  ck_assert_int_eq(*s21_strrchr(arg, 'r'), 'r');
}
END_TEST

START_TEST(test_s21_strrchr_first_symbol) {
  const char *arg = "string";
  ck_assert_ptr_eq(s21_strrchr(arg, 's'), strrchr(arg, 's'));
  ck_assert_int_eq(*s21_strrchr(arg, 's'), 's');
}
END_TEST

START_TEST(test_s21_strrchr_only_last_symbol) {
  const char *arg = "string";
  ck_assert_ptr_eq(s21_strrchr(arg, 'g'), strrchr(arg, 'g'));
  ck_assert_int_eq(*s21_strrchr(arg, 'g'), 'g');
}
END_TEST

START_TEST(test_s21_strrchr_not_existing_symbol) {
  const char *arg = "string";
  ck_assert_ptr_eq(s21_strrchr(arg, 'm'), strrchr(arg, 'm'));
}
END_TEST

START_TEST(test_s21_strrchr_last_symbol) {
  const char *arg = "string rrrrrrrrr";
  ck_assert_ptr_eq(s21_strrchr(arg, 'r'), strrchr(arg, 'r'));
  ck_assert_int_eq(*s21_strrchr(arg, 'r'), 'r');
}
END_TEST

START_TEST(test_s21_strrchr_zero_byte) {
  const char *arg = "string";
  ck_assert_ptr_eq(s21_strrchr(arg, '\0'), strrchr(arg, '\0'));
  ck_assert_int_eq(*s21_strrchr(arg, '\0'), '\0');
}
END_TEST

START_TEST(test_s21_strrchr_empty_string) {
  const char *arg = "";
  ck_assert_ptr_eq(s21_strrchr(arg, 'o'), strrchr(arg, 'o'));
}
END_TEST

START_TEST(test_s21_strrchr_zero_byte_in_empty_string) {
  const char *arg = "";
  ck_assert_ptr_eq(s21_strrchr(arg, '\0'), strrchr(arg, '\0'));
  ck_assert_int_eq(*s21_strrchr(arg, '\0'), '\0');
}
END_TEST

START_TEST(test_s21_strrchr_character_code) {
  const char *arg = "warning";
  ck_assert_ptr_eq(s21_strrchr(arg, 119), strrchr(arg, 119));
  ck_assert_int_eq(*s21_strrchr(arg, 119), 119);
}
END_TEST

START_TEST(test_s21_strrchr_out_of_bounds) {
  const char *arg = "short";
  ck_assert_ptr_eq(s21_strrchr(arg, 'x'), strrchr(arg, 'x'));
}
END_TEST

Suite *s21_strrchr_suite(void) {
  Suite *s = suite_create("s21_strrchr");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_strrchr_first_symbol);
  tcase_add_test(tc, test_s21_strrchr_only_last_symbol);
  tcase_add_test(tc, test_s21_strrchr_character_code);
  tcase_add_test(tc, test_s21_strrchr_empty_string);
  tcase_add_test(tc, test_s21_strrchr_existing_symbol_normal);
  tcase_add_test(tc, test_s21_strrchr_last_symbol);
  tcase_add_test(tc, test_s21_strrchr_not_existing_symbol);
  tcase_add_test(tc, test_s21_strrchr_zero_byte);
  tcase_add_test(tc, test_s21_strrchr_zero_byte_in_empty_string);
  tcase_add_test(tc, test_s21_strrchr_out_of_bounds);

  suite_add_tcase(s, tc);
  return s;
}