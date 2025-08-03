#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_memcpy_number) {
  const int num = 250;
  const int *ptr1 = &num;
  int dest;
  int *ptr2 = &dest;
  ck_assert_ptr_eq(s21_memcpy(ptr2, ptr1, sizeof(int)),
                   memcpy(ptr2, ptr1, sizeof(int)));
}
END_TEST

START_TEST(test_s21_memcpy_number_list) {
  const int a[] = {123, 21321, 0};
  int b[3] = {0};
  ck_assert_ptr_eq(s21_memcpy(b, a, sizeof(a)), memcpy(b, a, sizeof(a)));
}
END_TEST

START_TEST(test_s21_memcpy_string) {
  const char a[] = "qwerty";
  char b[sizeof(a)] = {0};
  ck_assert_ptr_eq(s21_memcpy(b, a, sizeof(a)), memcpy(b, a, sizeof(a)));
}
END_TEST

START_TEST(test_s21_memcpy_empty) {
  const char a[7] = {0};
  char b[sizeof(a)] = {0};
  ck_assert_ptr_eq(s21_memcpy(b, a, sizeof(a)), memcpy(b, a, sizeof(a)));
}
END_TEST

START_TEST(test_s21_memcpy_matrix) {
  const char a[2][7] = {"qwerty", "asdfgh"};
  char b[2][7] = {0};
  ck_assert_ptr_eq(s21_memcpy(b, a, sizeof(a)), memcpy(b, a, sizeof(a)));
}
END_TEST

Suite *s21_memcpy_suite(void) {
  Suite *s = suite_create("s21_memcpy");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_memcpy_empty);
  tcase_add_test(tc, test_s21_memcpy_number);
  tcase_add_test(tc, test_s21_memcpy_number_list);
  tcase_add_test(tc, test_s21_memcpy_matrix);
  tcase_add_test(tc, test_s21_memcpy_string);

  suite_add_tcase(s, tc);
  return s;
}