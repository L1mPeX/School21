#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *last = S21_NULL;
  const char *p = str;

  while (*p) {
    if (*p == (unsigned char)c) {
      last = p;
    }
    p++;
  }

  return ((unsigned char)c == '\0') ? (char *)p : (char *)last;
}