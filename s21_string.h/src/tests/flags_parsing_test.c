#include <check.h>

#include "../s21_string.h"
#include "s21_sprintf_helpers.h"

START_TEST(test_parse_flags_all_flags) {
  char str[] = "0+- #";
  flags_t flags;
  init_flags(&flags);
  char *result = parse_flags(str, &flags);

  ck_assert_int_eq(flags.base, 1);
  ck_assert_int_eq(flags.fill, 1);
  ck_assert_int_eq(flags.left_alignment, 1);
  ck_assert_int_eq(flags.sign, 1);
  ck_assert_int_eq(flags.space, 1);
  ck_assert_ptr_eq(result, str + 5);
}
END_TEST

START_TEST(test_parse_flags_partial_flags) {
  char str[] = "+ #abc";
  flags_t flags;
  init_flags(&flags);
  char *result = parse_flags(str, &flags);

  ck_assert_int_eq(flags.base, 1);
  ck_assert_int_eq(flags.fill, 0);
  ck_assert_int_eq(flags.left_alignment, 0);
  ck_assert_int_eq(flags.sign, 1);
  ck_assert_int_eq(flags.space, 1);
  ck_assert_ptr_eq(result, str + 3);
}
END_TEST

START_TEST(test_parse_flags_no_flags) {
  char *str = "abc123";
  flags_t flags;
  init_flags(&flags);
  char *result = parse_flags(str, &flags);

  ck_assert_int_eq(flags.base, 0);
  ck_assert_int_eq(flags.fill, 0);
  ck_assert_int_eq(flags.left_alignment, 0);
  ck_assert_int_eq(flags.sign, 0);
  ck_assert_int_eq(flags.space, 0);
  ck_assert_ptr_eq(result, str);
}
END_TEST

START_TEST(test_parse_flags_empty_string) {
  char *str = "";
  flags_t flags;
  init_flags(&flags);
  char *result = parse_flags(str, &flags);

  ck_assert_int_eq(flags.base, 0);
  ck_assert_int_eq(flags.fill, 0);
  ck_assert_int_eq(flags.left_alignment, 0);
  ck_assert_int_eq(flags.sign, 0);
  ck_assert_int_eq(flags.space, 0);
  ck_assert_ptr_eq(result, str);
}
END_TEST

START_TEST(test_parse_flags_mixed_order) {
  char *str = "#0- +";
  flags_t flags;
  init_flags(&flags);
  char *result = parse_flags(str, &flags);

  ck_assert_int_eq(flags.base, 1);
  ck_assert_int_eq(flags.fill, 1);
  ck_assert_int_eq(flags.left_alignment, 1);
  ck_assert_int_eq(flags.sign, 1);
  ck_assert_int_eq(flags.space, 1);
  ck_assert_ptr_eq(result, str + 5);
}
END_TEST

START_TEST(test_parse_flags_invalid_flags) {
  char *str = "-+x0#";
  flags_t flags;
  init_flags(&flags);
  char *result = parse_flags(str, &flags);

  ck_assert_int_eq(flags.base, 0);
  ck_assert_int_eq(flags.fill, 0);
  ck_assert_int_eq(flags.left_alignment, 1);
  ck_assert_int_eq(flags.sign, 1);
  ck_assert_int_eq(flags.space, 0);
  ck_assert_ptr_eq(result, str + 2);
}
END_TEST

START_TEST(test_resolve_conflicts_flags) {
  flags_t flags;
  init_flags(&flags);
  flags.left_alignment = 1;
  flags.fill = 1;
  flags.sign = 1;
  flags.space = 1;

  resolve_conflicts_flags(&flags);

  ck_assert_int_eq(flags.fill, 0);
  ck_assert_int_eq(flags.space, 0);
}
END_TEST

Suite *flags_parsing_suite(void) {
  Suite *s = suite_create("Flags Parsing");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_parse_flags_all_flags);
  tcase_add_test(tc, test_parse_flags_partial_flags);
  tcase_add_test(tc, test_parse_flags_no_flags);
  tcase_add_test(tc, test_parse_flags_empty_string);
  tcase_add_test(tc, test_parse_flags_mixed_order);
  tcase_add_test(tc, test_parse_flags_invalid_flags);
  tcase_add_test(tc, test_resolve_conflicts_flags);

  suite_add_tcase(s, tc);
  return s;
}