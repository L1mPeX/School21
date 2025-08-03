#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  while (n > 0 && *str1 && (*str1 == *str2)) {
    str1++;
    str2++;
    n--;
  }
  return (n == 0) ? res : ((unsigned char)*str1 - (unsigned char)*str2);
}