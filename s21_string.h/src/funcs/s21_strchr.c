#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *result = S21_NULL;
  for (; *str != '\0'; str++) {
    if (*str == (unsigned char)c) {
      result = (char *)str;
      break;
    }
  }
  if (c == '\0') {
    return (char *)str;
  }
  return result;
}