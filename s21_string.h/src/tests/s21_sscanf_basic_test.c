#include <check.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_sscanf_empty_input_and_format) {
  const char *input = "";
  ck_assert_int_eq(s21_sscanf(input, "2"), sscanf(input, "2"));
}
END_TEST

START_TEST(test_s21_sscanf_exact_match) {
  const char *input = "Hello darkness my old friend";
  ck_assert_int_eq(s21_sscanf(input, "Hello darkness my old friend"),
                   sscanf(input, "Hello darkness my old friend"));
}
END_TEST

START_TEST(test_s21_sscanf_partial_match) {
  const char *input = "I've come to talk with you again";
  ck_assert_int_eq(s21_sscanf(input, "I've come to talk"),
                   sscanf(input, "I've come to talk"));
}
END_TEST

START_TEST(test_s21_sscanf_no_match) {
  const char *input = "Because a vision softly creeping";
  ck_assert_int_eq(s21_sscanf(input, "Left its seeds while I was sleeping"),
                   sscanf(input, "Left its seeds while I was sleeping"));
}
END_TEST

START_TEST(test_s21_sscanf_long_string) {
  const char *input =
      "And the vision that was planted in my brain "
      "Still remains Within the sound of silence";
  ck_assert_int_eq(s21_sscanf(input,
                              "And the vision that was planted in my brain "
                              "Still remains Within the sound of silence"),
                   sscanf(input,
                          "And the vision that was planted in my brain "
                          "Still remains Within the sound of silence"));
}
END_TEST

START_TEST(test_s21_sscanf_special_chars) {
  const char *input = "!@#$*()_+-=[]{};':\",./<>?\\|`~";
  ck_assert_int_eq(s21_sscanf(input, "!@#$*()_+-=[]{};':\",./<>?\\|`~"),
                   sscanf(input, "!@#$*()_+-=[]{};':\",./<>?\\|`~"));
}
END_TEST

START_TEST(test_s21_sscanf_repeated_pattern) {
  const char *input = "abcabcabcabcabcabcabcabc";
  ck_assert_int_eq(s21_sscanf(input, "abcabcabcabcabcabcabcabc"),
                   sscanf(input, "abcabcabcabcabcabcabcabc"));
}
END_TEST

START_TEST(test_s21_sscanf_whitespace_variations) {
  const char *input = "   \t\n\v\r\f  spaces  \t\n\v\r\f  ";
  ck_assert_int_eq(s21_sscanf(input, "   \t\n\v\r\f  spaces  \t\n\v\r\f  "),
                   sscanf(input, "   \t\n\v\r\f  spaces  \t\n\v\r\f  "));
}
END_TEST

START_TEST(test_s21_sscanf_mixed_case) {
  const char *input = "ThIs Is A mIxEd CaSe StRiNg";
  ck_assert_int_eq(s21_sscanf(input, "ThIs Is A mIxEd CaSe StRiNg"),
                   sscanf(input, "ThIs Is A mIxEd CaSe StRiNg"));
}
END_TEST

START_TEST(test_s21_sscanf_numbers_as_strings) {
  const char *input = "1234567890 0987654321";
  ck_assert_int_eq(s21_sscanf(input, "1234567890 0987654321"),
                   sscanf(input, "1234567890 0987654321"));
}
END_TEST

START_TEST(test_s21_sscanf_escape_chars) {
  const char *input = "\\n\\t\\r\\\"\\'\\\\";
  ck_assert_int_eq(s21_sscanf(input, "\\n\\t\\r\\\"\\'\\\\"),
                   sscanf(input, "\\n\\t\\r\\\"\\'\\\\"));
}
END_TEST

Suite *s21_sscanf_basic_suite(void) {
  Suite *s = suite_create("s21_sscanf_string_matching");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_sscanf_empty_input_and_format);
  tcase_add_test(tc, test_s21_sscanf_exact_match);
  tcase_add_test(tc, test_s21_sscanf_partial_match);
  tcase_add_test(tc, test_s21_sscanf_no_match);
  tcase_add_test(tc, test_s21_sscanf_long_string);
  tcase_add_test(tc, test_s21_sscanf_special_chars);
  tcase_add_test(tc, test_s21_sscanf_repeated_pattern);
  tcase_add_test(tc, test_s21_sscanf_whitespace_variations);
  tcase_add_test(tc, test_s21_sscanf_mixed_case);
  tcase_add_test(tc, test_s21_sscanf_numbers_as_strings);
  tcase_add_test(tc, test_s21_sscanf_escape_chars);

  suite_add_tcase(s, tc);
  return s;
}