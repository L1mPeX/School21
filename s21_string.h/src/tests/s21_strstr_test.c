#include <check.h>

#include "../s21_string.h"

START_TEST(test_s21_strstr_normal_1) {
  char *arg = "string";
  ck_assert_ptr_eq(s21_strstr(arg, "ring"), strstr(arg, "ring"));
}
END_TEST

START_TEST(test_s21_strstr_normal_2) {
  char *arg = "string";
  ck_assert_ptr_eq(s21_strstr(arg, "ri"), strstr(arg, "ri"));
}
END_TEST

START_TEST(test_s21_strstr_from_first_symbol) {
  char *arg = "string";
  ck_assert_ptr_eq(s21_strstr(arg, "st"), strstr(arg, "st"));
}
END_TEST

START_TEST(test_s21_strstr_one_symbol) {
  char *arg = "string";
  ck_assert_ptr_eq(s21_strstr(arg, "t"), strstr(arg, "t"));
}
END_TEST

START_TEST(test_s21_strstr_last_symbol) {
  char *arg = "string";
  ck_assert_ptr_eq(s21_strstr(arg, "g"), strstr(arg, "g"));
}
END_TEST

START_TEST(test_s21_strstr_two_occurrences) {
  char *arg = "string string";
  ck_assert_ptr_eq(s21_strstr(arg, "ing"), strstr(arg, "ing"));
}
END_TEST

START_TEST(test_s21_strstr_three_occurrences) {
  char *arg = "string string string";
  ck_assert_ptr_eq(s21_strstr(arg, "ing"), strstr(arg, "ing"));
}
END_TEST

START_TEST(test_s21_strstr_zero_byte) {
  char *arg = "string string string";
  ck_assert_ptr_eq(s21_strstr(arg, "\0"), strstr(arg, "\0"));
}
END_TEST

START_TEST(test_s21_strstr_empty_second) {
  char *arg = "string string string";
  ck_assert_ptr_eq(s21_strstr(arg, ""), strstr(arg, ""));
}
END_TEST

START_TEST(test_s21_strstr_empty_first) {
  char *arg = "";
  ck_assert_ptr_eq(s21_strstr(arg, "qw"), strstr(arg, "qw"));
}
END_TEST

START_TEST(test_s21_strstr_empty_all) {
  char *arg = "";
  ck_assert_ptr_eq(s21_strstr(arg, ""), strstr(arg, ""));
}
END_TEST

START_TEST(test_s21_strstr_string_not_found) {
  char *arg = "string";
  ck_assert_ptr_eq(s21_strstr(arg, "cheburek"), strstr(arg, "cheburek"));
}
END_TEST

Suite *s21_strstr_suite(void) {
  Suite *s = suite_create("s21_strstr");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_strstr_normal_1);
  tcase_add_test(tc, test_s21_strstr_normal_2);
  tcase_add_test(tc, test_s21_strstr_from_first_symbol);
  tcase_add_test(tc, test_s21_strstr_one_symbol);
  tcase_add_test(tc, test_s21_strstr_last_symbol);
  tcase_add_test(tc, test_s21_strstr_two_occurrences);
  tcase_add_test(tc, test_s21_strstr_three_occurrences);
  tcase_add_test(tc, test_s21_strstr_zero_byte);
  tcase_add_test(tc, test_s21_strstr_empty_second);
  tcase_add_test(tc, test_s21_strstr_empty_first);
  tcase_add_test(tc, test_s21_strstr_empty_all);
  tcase_add_test(tc, test_s21_strstr_string_not_found);

  suite_add_tcase(s, tc);
  return s;
}