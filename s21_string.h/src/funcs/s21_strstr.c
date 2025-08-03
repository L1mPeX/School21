#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  if (*needle == '\0') return (char *)haystack;

  char *res = S21_NULL;
  for (; *haystack; haystack++) {
    const char *h = haystack;
    const char *n = needle;

    while (*h != '\0' && *n != '\0' && *h == *n) {
      h++;
      n++;
    }

    if (*n == '\0') {
      res = (char *)haystack;
      break;
    }
  }
  return res;
}