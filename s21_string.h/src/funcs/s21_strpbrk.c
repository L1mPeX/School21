#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  if (!str1 || !str2) return S21_NULL;
  int stop = 0;
  const char *p1 = str1;
  for (; *p1 && !stop; p1++) {
    for (const char *p2 = str2; *p2 && !stop; p2++) {
      if (*p1 == *p2) {
        stop = 1;
      }
    }
  }
  return (stop) ? (char *)(p1 - 1) : S21_NULL;
}
