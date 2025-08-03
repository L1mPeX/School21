#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *last = S21_NULL;
  char *first = S21_NULL;
  int fl = 0;
  if (str) {
    last = str;
  }

  if (last) {
    while (*last && s21_strchr(delim, *last)) {
      last++;
    }

    if (*last == '\0') {
      fl = 1;
    }

    first = last;

    while (*last && !s21_strchr(delim, *last)) {
      last++;
    }

    if (*last) {
      *last = '\0';
      last++;
    } else {
      last = S21_NULL;
    }
  }
  if (fl) {
    first = S21_NULL;
  }
  return first;
}