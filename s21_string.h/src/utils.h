#ifndef UTILS_H_
#define UTILS_H_

#include <stdint.h>

#include "s21_string.h"

char *parse_s21_size_t_from_str(const char *str, s21_size_t *result);

void s21_size_t_to_string_with_base(char *str, s21_size_t num, int base);
void s21_size_t_to_string(char *str, s21_size_t num);
void pointer_to_string(char *str, uintptr_t ptr);
void long_double_to_string(char *str, long double num, s21_size_t presicion);
void long_double_to_scientific(char *str, long double num,
                               s21_size_t precision);
void long_double_to_string_auto(char *str, long double num,
                                s21_size_t presicion, int hash_flag);

void to_upper_string(char *str);

#endif