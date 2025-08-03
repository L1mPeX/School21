#include <check.h>

#include "../s21_string.h"

START_TEST(test_s21_strncat_normal) {
  char dest[20] = "Hello";
  const char *src = ", world!";
  char *res = s21_strncat(dest, src, 8);
  char *expected = strncat(dest, src, 8);

  ck_assert_ptr_eq(res, dest);
  ck_assert_str_eq(dest, expected);
}
END_TEST

START_TEST(test_s21_strncat_limited) {
  char dest1[20] = "Hello";
  char dest2[20] = "Hello";
  const char *src = ", world!";

  s21_strncat(dest1, src, 3);
  strncat(dest2, src, 3);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_s21_strncat_empty_src) {
  char dest1[20] = "Hello";
  char dest2[20] = "Hello";
  const char *src = "";
  size_t n = 5;

  s21_strncat(dest1, src, n);
  strncat(dest2, src, n);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_s21_strncat_zero_null) {
  char dest1[20] = "Hello";
  char dest2[20] = "Hello";
  const char *src = ", world!";

  s21_strncat(dest1, src, 0);
  strncat(dest2, src, 0);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

Suite *s21_strncat_suite(void) {
  Suite *s = suite_create("s21_strncat");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_strncat_normal);
  tcase_add_test(tc, test_s21_strncat_limited);
  tcase_add_test(tc, test_s21_strncat_empty_src);
  tcase_add_test(tc, test_s21_strncat_zero_null);

  suite_add_tcase(s, tc);
  return s;
}