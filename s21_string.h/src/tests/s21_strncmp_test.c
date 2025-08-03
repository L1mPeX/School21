#include <check.h>

#include "../s21_string.h"

START_TEST(test_s21_strncmp_empty) {
  const char *str1 = "";
  const char *str2 = "";
  ck_assert_int_eq(s21_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
}
END_TEST

START_TEST(test_s21_strncmp_diff) {
  const char *str1 = "compared string first";
  const char *str2 = "compared string second";
  ck_assert_int_eq(s21_strncmp(str1, str2, 17), strncmp(str1, str2, 17));
}
END_TEST

START_TEST(test_s21_strncmp_short_long) {
  const char *str1 = "compared";
  const char *str2 = "compared string";
  ck_assert_int_eq(s21_strncmp(str1, str2, 17), strncmp(str1, str2, 17));
}
END_TEST

START_TEST(test_s21_strncmp_equal) {
  const char *str1 = "string";
  const char *str2 = "string";
  ck_assert_int_eq(s21_strncmp(str1, str2, 20), strncmp(str1, str2, 20));
}
END_TEST

Suite *s21_strncmp_suite(void) {
  Suite *s = suite_create("s21_strncmp");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_strncmp_empty);
  tcase_add_test(tc, test_s21_strncmp_equal);
  tcase_add_test(tc, test_s21_strncmp_diff);
  tcase_add_test(tc, test_s21_strncmp_short_long);

  suite_add_tcase(s, tc);
  return s;
}