#include <check.h>

#include "../s21_string.h"
#include "s21_sprintf_helpers.h"

START_TEST(test_parse_type_d) {
  char result = 0;
  const char *test_str = "d123";
  char *remaining = parse_type(test_str, &result);

  ck_assert_int_eq(result, 'd');
  ck_assert_ptr_eq(remaining, test_str + 1);
}
END_TEST

START_TEST(test_parse_type_empty) {
  char result = 0;
  const char *empty_str = "";
  char *remaining = parse_type(empty_str, &result);

  ck_assert_int_eq(result, '\0');
  ck_assert_ptr_eq(remaining, empty_str + 1);
}
END_TEST

START_TEST(test_parse_type_c) {
  char result = 0;
  const char *c_str = "c456";
  char *remaining = parse_type(c_str, &result);

  ck_assert_int_eq(result, 'c');
  ck_assert_ptr_eq(remaining, c_str + 1);
}
END_TEST

START_TEST(test_parse_type_s) {
  char result = 0;
  const char *s_str = "s789";
  char *remaining = parse_type(s_str, &result);

  ck_assert_int_eq(result, 's');
  ck_assert_ptr_eq(remaining, s_str + 1);
}
END_TEST

Suite *type_parsing_suite(void) {
  Suite *s = suite_create("Type Parsing");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_parse_type_d);
  tcase_add_test(tc, test_parse_type_empty);
  tcase_add_test(tc, test_parse_type_c);
  tcase_add_test(tc, test_parse_type_s);

  suite_add_tcase(s, tc);
  return s;
}