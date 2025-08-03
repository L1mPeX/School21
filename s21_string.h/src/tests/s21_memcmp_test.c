#include <check.h>
#include <limits.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_memcmp_empty) {
  const char str1[] = "";
  const char str2[] = "";
  ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
}
END_TEST

START_TEST(test_s21_memcmp_first_outside) {
  const char str1[] = "first string";
  const char str2[] = "second string";
  ck_assert_int_eq(s21_memcmp(str1, str2, 5) > 0, memcmp(str1, str2, 5) > 0);
  ck_assert_int_eq(s21_memcmp(str1, str2, 5) < 0, memcmp(str1, str2, 5) < 0);
}
END_TEST

START_TEST(test_s21_memcmp_second_outside) {
  const char str1[] = "qwerty";
  const char str2[] = "qweuty";
  ck_assert_int_eq(s21_memcmp(str1, str2, 6) > 0, memcmp(str1, str2, 6) > 0);
  ck_assert_int_eq(s21_memcmp(str1, str2, 6) < 0, memcmp(str1, str2, 6) < 0);
}
END_TEST

START_TEST(test_s21_memcmp_count_less_len) {
  const char str1[] = "string";
  const char str2[] = "strong";
  ck_assert_int_eq(s21_memcmp(str1, str2, 4) > 0, memcmp(str1, str2, 4) > 0);
  ck_assert_int_eq(s21_memcmp(str1, str2, 4) < 0, memcmp(str1, str2, 4) < 0);
}
END_TEST

START_TEST(test_s21_memcmp_equal) {
  const char str1[] = "string";
  const char str2[] = "string";
  ck_assert_int_eq(s21_memcmp(str1, str2, 6), memcmp(str1, str2, 6));
}
END_TEST

START_TEST(test_s21_memcmp_numbers) {
  const int a = 12, b = 24;
  const void *arg1 = &a;
  const void *arg2 = &b;
  ck_assert_int_eq(s21_memcmp(arg1, arg2, sizeof(int)) > 0,
                   memcmp(arg1, arg2, sizeof(int)) > 0);
  ck_assert_int_eq(s21_memcmp(arg1, arg2, sizeof(int)) < 0,
                   memcmp(arg1, arg2, sizeof(int)) < 0);
}
END_TEST

START_TEST(test_s21_memcmp_numbers_outside) {
  const int a = 12, b = 260;
  const void *arg1 = &a;
  const void *arg2 = &b;
  ck_assert_int_eq(s21_memcmp(arg1, arg2, sizeof(int)) > 0,
                   memcmp(arg1, arg2, sizeof(int)) > 0);
  ck_assert_int_eq(s21_memcmp(arg1, arg2, sizeof(int)) < 0,
                   memcmp(arg1, arg2, sizeof(int)) < 0);
}
END_TEST

START_TEST(test_s21_memcmp_numbers_equality) {
  const int a = 12, b = 12;
  const void *arg1 = &a;
  const void *arg2 = &b;
  ck_assert_int_eq(s21_memcmp(arg1, arg2, sizeof(int)),
                   memcmp(arg1, arg2, sizeof(int)));
}
END_TEST

START_TEST(test_s21_memcmp_point_str) {
  const char *a = "strong";
  const char *b = "string";
  ck_assert_int_eq(s21_memcmp(a, b, 6) > 0, memcmp(a, b, 6) > 0);
  ck_assert_int_eq(s21_memcmp(a, b, 6) < 0, memcmp(a, b, 6) < 0);
}
END_TEST

Suite *s21_memcmp_suite(void) {
  Suite *s = suite_create("s21_memcmp");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_memcmp_empty);
  tcase_add_test(tc, test_s21_memcmp_first_outside);
  tcase_add_test(tc, test_s21_memcmp_second_outside);
  tcase_add_test(tc, test_s21_memcmp_count_less_len);
  tcase_add_test(tc, test_s21_memcmp_equal);
  tcase_add_test(tc, test_s21_memcmp_numbers_equality);
  tcase_add_test(tc, test_s21_memcmp_numbers_outside);
  tcase_add_test(tc, test_s21_memcmp_numbers);
  tcase_add_test(tc, test_s21_memcmp_point_str);

  suite_add_tcase(s, tc);
  return s;
}