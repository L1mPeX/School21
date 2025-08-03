#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t res = 0, stop = 0;
  while (*str1 && !stop) {
    const char *p = str2;
    while (*p && !stop) {
      if (*str1 == *(p++)) {
        stop = 1;
      }
    }
    if (!stop) {
      str1++;
      res++;
    }
  }
  return res;
}