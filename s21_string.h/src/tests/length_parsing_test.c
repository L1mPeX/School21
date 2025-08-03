#include <check.h>

#include "../s21_string.h"
#include "s21_sprintf_helpers.h"

START_TEST(test_parse_length_h) {
  char result = 0;
  const char *test_str = "h123";
  char *remaining = parse_length(test_str, &result);

  ck_assert_int_eq(result, 'h');
  ck_assert_ptr_eq(remaining, test_str + 1);
}
END_TEST

START_TEST(test_parse_length_no_length) {
  char result = 0;
  const char *no_length_str = "d123";
  char *remaining = parse_length(no_length_str, &result);

  ck_assert_int_eq(result, 0);
  ck_assert_ptr_eq(remaining, no_length_str);
}
END_TEST

START_TEST(test_parse_length_l) {
  char result = 0;
  const char *l_str = "l456";
  char *remaining = parse_length(l_str, &result);

  ck_assert_int_eq(result, 'l');
  ck_assert_ptr_eq(remaining, l_str + 1);
}
END_TEST

START_TEST(test_parse_length_L) {
  char result = 0;
  const char *L_str = "L789";
  char *remaining = parse_length(L_str, &result);

  ck_assert_int_eq(result, 'L');
  ck_assert_ptr_eq(remaining, L_str + 1);
}
END_TEST

Suite *length_parsing_suite(void) {
  Suite *s = suite_create("Length Parsing");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_parse_length_h);
  tcase_add_test(tc, test_parse_length_no_length);
  tcase_add_test(tc, test_parse_length_l);
  tcase_add_test(tc, test_parse_length_L);

  suite_add_tcase(s, tc);
  return s;
}