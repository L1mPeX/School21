#include <check.h>

#include "../s21_string.h"

START_TEST(test_s21_strtok_two_simbols_delim) {
  char arg1[] = "shaverma kurini, shaverma classic";
  char arg2[] = "shaverma kurini, shaverma classic";
  const char *delim = " ,";
  char *token1 = s21_strtok(arg1, delim);
  char *token2 = strtok(arg2, delim);
  ck_assert_str_eq(token1, token2);

  token1 = s21_strtok(NULL, delim);
  token2 = strtok(NULL, delim);
  ck_assert_str_eq(token1, token2);

  token1 = s21_strtok(NULL, delim);
  token2 = strtok(NULL, delim);
  ck_assert_str_eq(token1, token2);

  token1 = s21_strtok(NULL, delim);
  token2 = strtok(NULL, delim);
  ck_assert_str_eq(token1, token2);
}
END_TEST

START_TEST(test_s21_strtok_first_arg_NULL) {
  char arg1[] = "shaverma kurini, shaverma classic";
  char arg2[] = "shaverma kurini, shaverma classic";
  const char *delim = " ,";
  char *token1 = s21_strtok(arg1, delim);
  char *token2 = strtok(arg2, delim);

  while (token1 != S21_NULL && token2 != S21_NULL) {
    ck_assert_str_eq(token1, token2);
    token1 = s21_strtok(NULL, delim);
    token2 = strtok(NULL, delim);
  }

  ck_assert_ptr_null(token1);
  ck_assert_ptr_null(token2);
}
END_TEST

START_TEST(test_s21_strtok_one_simbol_delim) {
  char arg[] = "shaverma kurini, shaverma classic";
  const char *delim = ",";
  ck_assert_ptr_eq(s21_strtok(arg, delim), strtok(arg, delim));
}
END_TEST

START_TEST(test_s21_strtok_empty_first) {
  char arg[] = "";
  const char *delim = ",";
  ck_assert_ptr_eq(s21_strtok(arg, delim), strtok(arg, delim));
}
END_TEST

START_TEST(test_s21_strtok_empty_all) {
  char arg[] = "";
  const char *delim = "";
  ck_assert_ptr_eq(s21_strtok(arg, delim), strtok(arg, delim));
}
END_TEST

START_TEST(test_s21_strtok_empty_second) {
  char arg[] = "shaverma kurini, shaverma classic";
  const char *delim = "";
  ck_assert_ptr_eq(s21_strtok(arg, delim), strtok(arg, delim));
}
END_TEST

START_TEST(test_s21_strtok_delim_at_the_begining) {
  char arg[] = ",shaverma kurini, shaverma classic";
  const char *delim = " ,";
  ck_assert_ptr_eq(s21_strtok(arg, delim), strtok(arg, delim));
}
END_TEST

START_TEST(test_s21_strtok_delim_in_the_end) {
  char arg[] = "shaverma kurini, shaverma classic,";
  const char *delim = " ,";
  ck_assert_ptr_eq(s21_strtok(arg, delim), strtok(arg, delim));
}
END_TEST

START_TEST(test_s21_strtok_delim_begin_and_end) {
  char arg[] = ",shaverma kurini, shaverma classic,";
  const char *delim = " ,";
  ck_assert_ptr_eq(s21_strtok(arg, delim), strtok(arg, delim));
}
END_TEST

START_TEST(test_s21_strtok_not_delim_in_str) {
  char arg[] = "shaverma kurini shaverma classic";
  const char *delim = ",";
  ck_assert_ptr_eq(s21_strtok(arg, delim), strtok(arg, delim));
}
END_TEST

START_TEST(test_s21_strtok_only_delim_in_str) {
  char arg[] = " ,!;";
  const char *delim = "  ,,,!,;";
  ck_assert_ptr_eq(s21_strtok(arg, delim), strtok(arg, delim));
}
END_TEST

START_TEST(test_s21_strtok_zero_byte) {
  char arg[] = " ,!;";
  const char *delim = "\0";
  ck_assert_ptr_eq(s21_strtok(arg, delim), strtok(arg, delim));
}
END_TEST

Suite *s21_strtok_suite(void) {
  Suite *s = suite_create("s21_strtok");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_strtok_two_simbols_delim);
  tcase_add_test(tc, test_s21_strtok_first_arg_NULL);
  tcase_add_test(tc, test_s21_strtok_one_simbol_delim);
  tcase_add_test(tc, test_s21_strtok_empty_all);
  tcase_add_test(tc, test_s21_strtok_empty_first);
  tcase_add_test(tc, test_s21_strtok_empty_second);
  tcase_add_test(tc, test_s21_strtok_delim_at_the_begining);
  tcase_add_test(tc, test_s21_strtok_delim_in_the_end);
  tcase_add_test(tc, test_s21_strtok_delim_begin_and_end);
  tcase_add_test(tc, test_s21_strtok_not_delim_in_str);
  tcase_add_test(tc, test_s21_strtok_only_delim_in_str);
  tcase_add_test(tc, test_s21_strtok_zero_byte);

  suite_add_tcase(s, tc);
  return s;
}