#include <check.h>
#include <math.h>

#include "../utils.h"

START_TEST(test_negative_nan) {
  char str[200];
  long_double_to_string(str, -NAN, 0);
  ck_assert_str_eq(str, "-nan");
}
END_TEST

START_TEST(test_positive_nan) {
  char str[200];
  long_double_to_string(str, +NAN, 0);
  ck_assert_str_eq(str, "nan");
}
END_TEST

START_TEST(test_negative_inf) {
  char str[200];
  long_double_to_string(str, -INFINITY, 0);
  ck_assert_str_eq(str, "-inf");
}
END_TEST

START_TEST(test_positive_inf) {
  char str[200];
  long_double_to_string(str, +INFINITY, 0);
  ck_assert_str_eq(str, "inf");
}
END_TEST

START_TEST(test_small_float) {
  char str[200];
  long_double_to_string(str, 1.081, 3);
  ck_assert_str_eq(str, "1.081");
}
END_TEST

START_TEST(test_small_negative_float) {
  char str[200];
  long_double_to_string(str, -1.081, 3);
  ck_assert_str_eq(str, "-1.081");
}
END_TEST

START_TEST(test_float_without_frac) {
  char str[200];
  long_double_to_string(str, 10, 6);
  ck_assert_str_eq(str, "10.000000");
}
END_TEST

START_TEST(test_rouding) {
  char str[200];
  long_double_to_string(str, 9.999999999L, 6);
  ck_assert_str_eq(str, "10.000000");
}
END_TEST

START_TEST(test_negative_rouding) {
  char str[200];
  long_double_to_string(str, -9.999999999L, 6);
  ck_assert_str_eq(str, "-10.000000");
}
END_TEST

START_TEST(test_max_float) {
  char str[200];
  long_double_to_string(str, FLT_MAX, 3);
  ck_assert_str_eq(str, "340282346638528859811704183484516925440.000");
}
END_TEST

START_TEST(test_float_with_big_precision) {
  char str[200];
  long_double_to_string(str, FLT_MIN * 1e50, 50);
  ck_assert_str_eq(
      str, "1175494350822.28759765625000000000000000000000000000000000000000");
}
END_TEST

START_TEST(test_zero) {
  char str[200];
  long_double_to_string(str, 0.0L, 2);
  ck_assert_str_eq(str, "0.00");
}
END_TEST

START_TEST(test_negative_zero) {
  char str[200];
  long_double_to_string(str, -0.0L, 2);
  ck_assert_str_eq(str, "-0.00");
}
END_TEST

START_TEST(test_large_number) {
  char str[200];
  long_double_to_string(str, 1.23456789e20L, 3);
  ck_assert_str_eq(str, "123456789000000000000.000");
}
END_TEST

START_TEST(test_small_number) {
  char str[200];
  long_double_to_string(str, 1.23456789e-20L, 32);
  ck_assert_str_eq(str, "0.00000000000000000001234567890000");
}
END_TEST

START_TEST(test_precision_zero) {
  char str[200];
  long_double_to_string(str, 3.14159265358979323846L, 0);
  ck_assert_str_eq(str, "3");
}
END_TEST

START_TEST(test_varying_precision) {
  char str[200];
  long_double_to_string(str, 3.14159265358979323846L, 5);
  ck_assert_str_eq(str, "3.14159");

  long_double_to_string(str, 3.14159265358979323846L, 10);
  ck_assert_str_eq(str, "3.1415926536");
}
END_TEST

START_TEST(test_exact_representation) {
  char str[200];
  long_double_to_string(str, 0.1L + 0.2L, 20);
  ck_assert_str_eq(str, "0.30000000000000000000");
}
END_TEST

START_TEST(test_denormal_numbers) {
  char str[200];
  long_double_to_string(str, LDBL_MIN / 2, 50);
  ck_assert(strstr(str, "0.000000") != NULL);
}
END_TEST

START_TEST(test_very_large_precision) {
  char str[500];
  long_double_to_string(str, 1.0L, 100);
  ck_assert_str_eq(str,
                   "1."
                   "00000000000000000000000000000000000000000000000000000000000"
                   "00000000000000000000000000000000000000000");
}
END_TEST

Suite *long_double_to_string_suite(void) {
  Suite *s = suite_create("ldtos Conversion");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_negative_nan);
  tcase_add_test(tc, test_positive_nan);
  tcase_add_test(tc, test_negative_inf);
  tcase_add_test(tc, test_positive_inf);
  tcase_add_test(tc, test_small_float);
  tcase_add_test(tc, test_small_negative_float);
  tcase_add_test(tc, test_float_without_frac);
  tcase_add_test(tc, test_rouding);
  tcase_add_test(tc, test_negative_rouding);
  tcase_add_test(tc, test_max_float);
  tcase_add_test(tc, test_float_with_big_precision);
  tcase_add_test(tc, test_zero);
  tcase_add_test(tc, test_negative_zero);
  tcase_add_test(tc, test_large_number);
  tcase_add_test(tc, test_small_number);
  tcase_add_test(tc, test_precision_zero);
  tcase_add_test(tc, test_varying_precision);
  tcase_add_test(tc, test_exact_representation);
  tcase_add_test(tc, test_denormal_numbers);
  tcase_add_test(tc, test_very_large_precision);

  suite_add_tcase(s, tc);
  return s;
}