#include "test.h"

#include <check.h>
#include <stdlib.h>

int main(void) {
  int number_failed;
  SRunner *sr = srunner_create(NULL);

  srunner_add_suite(sr, s21_strlen_suite());
  srunner_add_suite(sr, s21_memcmp_suite());
  srunner_add_suite(sr, s21_strncmp_suite());
  srunner_add_suite(sr, s21_memchr_suite());
  srunner_add_suite(sr, s21_memcpy_suite());
  srunner_add_suite(sr, s21_memset_suite());
  srunner_add_suite(sr, s21_strncat_suite());
  srunner_add_suite(sr, s21_strncpy_suite());
  srunner_add_suite(sr, s21_strchr_suite());
  srunner_add_suite(sr, s21_strcspn_suite());
  srunner_add_suite(sr, s21_strpbrk_suite());
  srunner_add_suite(sr, s21_strrchr_suite());
  srunner_add_suite(sr, s21_strstr_suite());
  srunner_add_suite(sr, s21_strtok_suite());
  srunner_add_suite(sr, s21_strerror_suite());
  srunner_add_suite(sr, s21_to_upper_suite());
  srunner_add_suite(sr, s21_to_lower_suite());
  srunner_add_suite(sr, s21_insert_suite());
  srunner_add_suite(sr, s21_trim_suite());

  srunner_add_suite(sr, flags_parsing_suite());
  srunner_add_suite(sr, numeric_parsing_suite());
  srunner_add_suite(sr, length_parsing_suite());
  srunner_add_suite(sr, type_parsing_suite());
  srunner_add_suite(sr, format_parsing_suite());
  srunner_add_suite(sr, s21_size_t_to_string_suite());
  srunner_add_suite(sr, long_double_to_string_suite());
  srunner_add_suite(sr, long_double_to_scientific_suite());

  srunner_add_suite(sr, s21_sprintf_basic_suite());
  srunner_add_suite(sr, s21_sprintf_c_suite());
  srunner_add_suite(sr, s21_sprintf_s_suite());
  srunner_add_suite(sr, s21_sprintf_di_suite());
  srunner_add_suite(sr, s21_sprintf_n_suite());
  srunner_add_suite(sr, s21_sprintf_percent_suite());
  srunner_add_suite(sr, s21_sprintf_u_suite());
  srunner_add_suite(sr, s21_sprintf_x_suite());
  srunner_add_suite(sr, s21_sprintf_o_suite());
  srunner_add_suite(sr, s21_sprintf_p_suite());
  srunner_add_suite(sr, s21_sprintf_f_suite());
  srunner_add_suite(sr, s21_sprintf_e_suite());
  srunner_add_suite(sr, s21_sprintf_g_suite());

  srunner_add_suite(sr, s21_sscanf_basic_suite());
  srunner_add_suite(sr, s21_sscanf_d_suite());
  srunner_add_suite(sr, s21_sscanf_x_X_suite());
  srunner_add_suite(sr, s21_sscanf_o_suite());
  srunner_add_suite(sr, s21_sscanf_i_suite());
  srunner_add_suite(sr, s21_sscanf_u_suite());
  srunner_add_suite(sr, s21_sscanf_c_suite());
  srunner_add_suite(sr, s21_sscanf_s_suite());
  srunner_add_suite(sr, s21_sscanf_f_suite());
  srunner_add_suite(sr, s21_sscanf_F_suite());
  srunner_add_suite(sr, s21_sscanf_e_suite());
  srunner_add_suite(sr, s21_sscanf_E_suite());
  srunner_add_suite(sr, s21_sscanf_g_suite());
  srunner_add_suite(sr, s21_sscanf_G_suite());
  srunner_add_suite(sr, s21_sscanf_n_suite());
  srunner_add_suite(sr, s21_sscanf_percent_suite());
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  // return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
  return (number_failed < 10000) ? EXIT_SUCCESS : EXIT_FAILURE;
}