#include <check.h>

#include "../s21_string.h"

START_TEST(test_s21_strncpy_normal) {
  char dest1[20];
  char dest2[20];
  const char *src = "Hello, world!";
  size_t n = strlen(src) + 1;

  ck_assert_str_eq(s21_strncpy(dest1, src, n), strncpy(dest2, src, n));
}
END_TEST

START_TEST(test_s21_strncpy_empty_src) {
  char dest1[20] = "belyash";
  char dest2[20] = "belyash";
  const char *src = "";
  size_t n = 20;

  ck_assert_str_eq(s21_strncpy(dest1, src, n), strncpy(dest2, src, n));
}
END_TEST

START_TEST(test_s21_strncpy_null_symvols_from_src) {
  char dest1[20] = "belyash";
  char dest2[20] = "belyash";
  const char *src = "vkusni";
  size_t n = 0;

  ck_assert_str_eq(s21_strncpy(dest1, src, n), strncpy(dest2, src, n));
}
END_TEST

Suite *s21_strncpy_suite(void) {
  Suite *s = suite_create("s21_strncpy");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_strncpy_normal);
  tcase_add_test(tc, test_s21_strncpy_empty_src);
  tcase_add_test(tc, test_s21_strncpy_null_symvols_from_src);

  suite_add_tcase(s, tc);
  return s;
}