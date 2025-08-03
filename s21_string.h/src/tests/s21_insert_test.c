#include <check.h>
#include <stdlib.h>

#include "../s21_string.h"

START_TEST(test_s21_insert_normal_1) {
  char *res = s21_insert("qwerty", "Four", 4);
  ck_assert_str_eq(res, "qwerFourty");
  free(res);
}
END_TEST

START_TEST(test_s21_insert_normal_2) {
  char *res = s21_insert("O, this is pivo", "otlichni ", 11);
  ck_assert_str_eq(res, "O, this is otlichni pivo");
  free(res);
}
END_TEST

START_TEST(test_s21_insert_empty_src) {
  char *null_ptr = S21_NULL;
  ck_assert_ptr_null(s21_insert(null_ptr, "Four", 4));
  free(null_ptr);
}
END_TEST

START_TEST(test_s21_insert_empty_str) {
  char *null_ptr = S21_NULL;
  ck_assert_ptr_null(s21_insert("Govyadina", null_ptr, 4));
  free(null_ptr);
}
END_TEST

START_TEST(test_s21_insert_empty_all) {
  char *null_ptr = S21_NULL;
  ck_assert_ptr_null(s21_insert(null_ptr, null_ptr, 4));
  free(null_ptr);
}
END_TEST

START_TEST(test_s21_insert_end_index) {
  char *res = s21_insert("qwerty", "Four", 6);
  ck_assert_str_eq(res, "qwertyFour");
  free(res);
}
END_TEST

START_TEST(test_s21_insert_begin_index) {
  char *res = s21_insert("qwerty", "Four", 0);
  ck_assert_str_eq(res, "Fourqwerty");
  free(res);
}
END_TEST

START_TEST(test_s21_insert_out_of_range_index) {
  char *res = s21_insert("qwerty", "Four", 10);
  ck_assert_ptr_null(res);
  free(res);
}
END_TEST

START_TEST(test_s21_insert_out_of_the_bounds) {
  char *temp = s21_insert("Hello", "123", 5);
  ck_assert_str_eq(temp, "Hello123");
  free(temp);
}
END_TEST

Suite *s21_insert_suite(void) {
  Suite *s = suite_create("s21_insert");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_insert_normal_1);
  tcase_add_test(tc, test_s21_insert_normal_2);
  tcase_add_test(tc, test_s21_insert_empty_src);
  tcase_add_test(tc, test_s21_insert_empty_str);
  tcase_add_test(tc, test_s21_insert_empty_all);
  tcase_add_test(tc, test_s21_insert_end_index);
  tcase_add_test(tc, test_s21_insert_begin_index);
  tcase_add_test(tc, test_s21_insert_out_of_range_index);
  tcase_add_test(tc, test_s21_insert_out_of_the_bounds);

  suite_add_tcase(s, tc);
  return s;
}