#include <check.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_sprintf_single_int) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%d", 123), sprintf(original, "%d", 123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_single_negative_int) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%d", -123), sprintf(original, "%d", -123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_short_positive_int) {
  char original[100];
  char my[100];
  short int num = 12345;
  ck_assert_int_eq(s21_sprintf(my, "%hd", num), sprintf(original, "%hd", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_short_negative_int) {
  char original[100];
  char my[100];
  short int num = -12345;
  ck_assert_int_eq(s21_sprintf(my, "%hd", num), sprintf(original, "%hd", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_short_min_int) {
  char original[100];
  char my[100];
  short int num = SHRT_MIN;
  ck_assert_int_eq(s21_sprintf(my, "%hd", num), sprintf(original, "%hd", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_short_max_int) {
  char original[100];
  char my[100];
  short int num = SHRT_MAX;
  ck_assert_int_eq(s21_sprintf(my, "%hd", num), sprintf(original, "%hd", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_long_positive_int) {
  char original[100];
  char my[100];
  long int num = 1234567890L;
  ck_assert_int_eq(s21_sprintf(my, "%ld", num), sprintf(original, "%ld", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_long_negative_int) {
  char original[100];
  char my[100];
  long int num = -1234567890L;
  ck_assert_int_eq(s21_sprintf(my, "%ld", num), sprintf(original, "%ld", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_long_min_int) {
  char original[100];
  char my[100];
  long int num = LONG_MIN;
  ck_assert_int_eq(s21_sprintf(my, "%ld", num), sprintf(original, "%ld", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_long_max_int) {
  char original[100];
  char my[100];
  long int num = LONG_MAX;
  ck_assert_int_eq(s21_sprintf(my, "%ld", num), sprintf(original, "%ld", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_many_ints) {
  char original[100];
  char my[100];
  ck_assert_int_eq(
      s21_sprintf(my, "%dHello,world@%d %d55656%d", -1, 2, -3, 4),
      sprintf(original, "%dHello,world@%d %d55656%d", -1, 2, -3, 4));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_single_i) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%i", 123), sprintf(original, "%i", 123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_single_negative_i) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%i", -123), sprintf(original, "%i", -123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_short_positive_i) {
  char original[100];
  char my[100];
  short int num = 12345;
  ck_assert_int_eq(s21_sprintf(my, "%hi", num), sprintf(original, "%hi", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_short_negative_i) {
  char original[100];
  char my[100];
  short int num = -12345;
  ck_assert_int_eq(s21_sprintf(my, "%hi", num), sprintf(original, "%hi", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_long_positive_i) {
  char original[100];
  char my[100];
  long int num = 1234567890L;
  ck_assert_int_eq(s21_sprintf(my, "%li", num), sprintf(original, "%li", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_long_negative_i) {
  char original[100];
  char my[100];
  long int num = -1234567890L;
  ck_assert_int_eq(s21_sprintf(my, "%li", num), sprintf(original, "%li", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_octal_i) {
  char original[100];
  char my[100];
  int num = 0123;
  ck_assert_int_eq(s21_sprintf(my, "%i", num), sprintf(original, "%i", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_hex_lower_i) {
  char original[100];
  char my[100];
  int num = 0xabc;
  ck_assert_int_eq(s21_sprintf(my, "%i", num), sprintf(original, "%i", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_hex_upper_i) {
  char original[100];
  char my[100];
  int num = 0xABC;
  ck_assert_int_eq(s21_sprintf(my, "%i", num), sprintf(original, "%i", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_single_int_with_width) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%10d", 123),
                   sprintf(original, "%10d", 123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_single_int_with_width_and_left_alig) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%-10d", 123),
                   sprintf(original, "%-10d", 123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_single_int_with_width_and_fill) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%010d", 123),
                   sprintf(original, "%010d", 123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_int_with_plus) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%+d", 123), sprintf(original, "%+d", 123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_int_with_plus_and_width) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%+10d", 123),
                   sprintf(original, "%+10d", 123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_int_with_plus_and_left_align) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%-+10d", 123),
                   sprintf(original, "%-+10d", 123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_int_with_plus_and_zero_fill) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%+010d", 123),
                   sprintf(original, "%+010d", 123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_int_with_space) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "% d", 123), sprintf(original, "% d", 123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_int_with_space_and_width) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "% 10d", 123),
                   sprintf(original, "% 10d", 123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_int_with_space_and_left_align) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%- 10d", 123),
                   sprintf(original, "%- 10d", 123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_negative_int) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%d", -123), sprintf(original, "%d", -123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_negative_int_with_width) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%10d", -123),
                   sprintf(original, "%10d", -123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_negative_int_with_zero_fill) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%010d", -123),
                   sprintf(original, "%010d", -123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_negative_int_with_plus) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%+d", -123),
                   sprintf(original, "%+d", -123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_negative_int_with_space) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "% d", -123),
                   sprintf(original, "% d", -123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_int_with_all_flags) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%+-15d", 123),
                   sprintf(original, "%+-15d", 123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_zero_value_with_flags) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%+05d", 0), sprintf(original, "%+05d", 0));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_precision_int) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%.5d", 42), sprintf(original, "%.5d", 42));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_precision_int_zero) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%.3d", 0), sprintf(original, "%.3d", 0));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_precision_int_negative) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%.6d", -123),
                   sprintf(original, "%.6d", -123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_precision_width) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%10.5d", 123),
                   sprintf(original, "%10.5d", 123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_precision_plus_flag) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%+.5d", 42),
                   sprintf(original, "%+.5d", 42));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_precision_space_flag) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "% .5d", 42),
                   sprintf(original, "% .5d", 42));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_precision_minus_flag) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%-10.5d", 123),
                   sprintf(original, "%-10.5d", 123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_s21_sprintf_precision_zero_and_num_zero) {
  char original[100];
  char my[100];
  ck_assert_int_eq(s21_sprintf(my, "%.0d", 0), sprintf(original, "%.0d", 0));
  ck_assert_str_eq(my, original);
}
END_TEST

Suite *s21_sprintf_di_suite(void) {
  Suite *s = suite_create("s21_sprintf_di");
  TCase *tc = tcase_create("Core");
  tcase_add_test(tc, test_s21_sprintf_single_int);
  tcase_add_test(tc, test_s21_sprintf_single_negative_int);
  tcase_add_test(tc, test_s21_sprintf_short_positive_int);
  tcase_add_test(tc, test_s21_sprintf_short_negative_int);
  tcase_add_test(tc, test_s21_sprintf_short_min_int);
  tcase_add_test(tc, test_s21_sprintf_short_max_int);
  tcase_add_test(tc, test_s21_sprintf_long_positive_int);
  tcase_add_test(tc, test_s21_sprintf_long_negative_int);
  tcase_add_test(tc, test_s21_sprintf_long_min_int);
  tcase_add_test(tc, test_s21_sprintf_long_max_int);
  tcase_add_test(tc, test_s21_sprintf_many_ints);
  tcase_add_test(tc, test_s21_sprintf_single_i);
  tcase_add_test(tc, test_s21_sprintf_single_negative_i);
  tcase_add_test(tc, test_s21_sprintf_short_positive_i);
  tcase_add_test(tc, test_s21_sprintf_short_negative_i);
  tcase_add_test(tc, test_s21_sprintf_long_positive_i);
  tcase_add_test(tc, test_s21_sprintf_long_negative_i);
  tcase_add_test(tc, test_s21_sprintf_octal_i);
  tcase_add_test(tc, test_s21_sprintf_hex_lower_i);
  tcase_add_test(tc, test_s21_sprintf_hex_upper_i);
  tcase_add_test(tc, test_s21_sprintf_single_int_with_width);
  tcase_add_test(tc, test_s21_sprintf_single_int_with_width_and_left_alig);
  tcase_add_test(tc, test_s21_sprintf_single_int_with_width_and_fill);
  tcase_add_test(tc, test_s21_sprintf_int_with_plus);
  tcase_add_test(tc, test_s21_sprintf_int_with_plus_and_width);
  tcase_add_test(tc, test_s21_sprintf_int_with_plus_and_left_align);
  tcase_add_test(tc, test_s21_sprintf_int_with_plus_and_zero_fill);
  tcase_add_test(tc, test_s21_sprintf_int_with_space);
  tcase_add_test(tc, test_s21_sprintf_int_with_space_and_width);
  tcase_add_test(tc, test_s21_sprintf_int_with_space_and_left_align);
  tcase_add_test(tc, test_s21_sprintf_negative_int);
  tcase_add_test(tc, test_s21_sprintf_negative_int_with_width);
  tcase_add_test(tc, test_s21_sprintf_negative_int_with_zero_fill);
  tcase_add_test(tc, test_s21_sprintf_negative_int_with_plus);
  tcase_add_test(tc, test_s21_sprintf_negative_int_with_space);
  tcase_add_test(tc, test_s21_sprintf_int_with_all_flags);
  tcase_add_test(tc, test_s21_sprintf_zero_value_with_flags);
  tcase_add_test(tc, test_s21_sprintf_precision_int);
  tcase_add_test(tc, test_s21_sprintf_precision_int_zero);
  tcase_add_test(tc, test_s21_sprintf_precision_int_negative);
  tcase_add_test(tc, test_s21_sprintf_precision_width);
  tcase_add_test(tc, test_s21_sprintf_precision_plus_flag);
  tcase_add_test(tc, test_s21_sprintf_precision_space_flag);
  tcase_add_test(tc, test_s21_sprintf_precision_minus_flag);
  tcase_add_test(tc, test_s21_sprintf_precision_zero_and_num_zero);
  suite_add_tcase(s, tc);
  return s;
}