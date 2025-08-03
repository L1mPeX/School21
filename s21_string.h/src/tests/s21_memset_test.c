#include <check.h>

#include "../s21_string.h"

START_TEST(test_s21_memset_string_full) {
  char str1[] = "qwerty";
  char str2[] = "qwerty";
  ck_assert_str_eq(s21_memset(str1, 'w', 6), memset(str2, 'w', 6));
}
END_TEST

START_TEST(test_s21_memset_string_not_full) {
  char str1[] = "khenkali and chebureckes";
  char str2[] = "khenkali and chebureckes";
  ck_assert_str_eq(s21_memset(str1, 'w', 10), memset(str2, 'w', 10));
}
END_TEST

START_TEST(test_s21_memset_string_null_symvols) {
  char str1[4] = "";
  char str2[4] = "";
  ck_assert_mem_eq(s21_memset(str1, 'w', 4), memset(str2, 'w', 4), 4);
}
END_TEST

START_TEST(test_s21_memset_int_list) {
  int str1[] = {123, 1, 3, 5};
  int str2[] = {123, 1, 3, 5};
  ck_assert_mem_eq(s21_memset(str1, 123, 2 * sizeof(int)),
                   memset(str2, 123, 2 * sizeof(int)), 16);
}
END_TEST

Suite *s21_memset_suite(void) {
  Suite *s = suite_create("s21_memset");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_memset_string_full);
  tcase_add_test(tc, test_s21_memset_string_not_full);
  tcase_add_test(tc, test_s21_memset_string_null_symvols);
  tcase_add_test(tc, test_s21_memset_int_list);

  suite_add_tcase(s, tc);
  return s;
}