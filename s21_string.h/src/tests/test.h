#ifndef TEST_H_
#define TEST_H_

#include <check.h>

Suite *s21_memchr_suite(void);
Suite *s21_memcmp_suite(void);
Suite *s21_memcpy_suite(void);
Suite *s21_strlen_suite(void);
Suite *s21_strncmp_suite(void);
Suite *s21_memset_suite(void);
Suite *s21_strncat_suite(void);
Suite *s21_strncpy_suite(void);
Suite *s21_strchr_suite(void);
Suite *s21_strcspn_suite(void);
Suite *s21_strpbrk_suite(void);
Suite *s21_strrchr_suite(void);
Suite *s21_strstr_suite(void);
Suite *s21_strtok_suite(void);
Suite *s21_strerror_suite(void);
Suite *s21_to_upper_suite(void);
Suite *s21_to_lower_suite(void);
Suite *s21_insert_suite(void);
Suite *s21_trim_suite(void);

Suite *flags_parsing_suite(void);
Suite *flags_parsing_suite(void);
Suite *numeric_parsing_suite(void);
Suite *length_parsing_suite(void);
Suite *type_parsing_suite(void);
Suite *format_parsing_suite(void);
Suite *s21_size_t_to_string_suite(void);
Suite *long_double_to_string_suite(void);
Suite *long_double_to_scientific_suite(void);

Suite *s21_sprintf_basic_suite(void);
Suite *s21_sprintf_c_suite(void);
Suite *s21_sprintf_s_suite(void);
Suite *s21_sprintf_di_suite(void);
Suite *s21_sprintf_n_suite(void);
Suite *s21_sprintf_percent_suite(void);
Suite *s21_sprintf_u_suite(void);
Suite *s21_sprintf_x_suite(void);
Suite *s21_sprintf_o_suite(void);
Suite *s21_sprintf_p_suite(void);
Suite *s21_sprintf_f_suite(void);
Suite *s21_sprintf_e_suite(void);
Suite *s21_sprintf_g_suite(void);

Suite *s21_sscanf_basic_suite(void);
Suite *s21_sscanf_d_suite(void);
Suite *s21_sscanf_x_X_suite(void);
Suite *s21_sscanf_o_suite(void);
Suite *s21_sscanf_i_suite(void);
Suite *s21_sscanf_u_suite(void);
Suite *s21_sscanf_c_suite(void);
Suite *s21_sscanf_s_suite(void);
Suite *s21_sscanf_f_suite(void);
Suite *s21_sscanf_F_suite(void);
Suite *s21_sscanf_e_suite(void);
Suite *s21_sscanf_E_suite(void);
Suite *s21_sscanf_g_suite(void);
Suite *s21_sscanf_G_suite(void);
Suite *s21_sscanf_n_suite(void);
Suite *s21_sscanf_percent_suite(void);

#endif