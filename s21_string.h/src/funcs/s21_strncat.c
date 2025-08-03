#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *ptr = dest;
  while (*ptr) ptr++;

  for (s21_size_t i = 0; i < n && src[i]; i++) {
    *ptr++ = src[i];
  }
  *ptr = '\0';

  return dest;
}