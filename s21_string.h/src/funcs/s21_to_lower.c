#include "../s21_string.h"

void *s21_to_lower(const char *str) {
  char *result = S21_NULL;

  if (str != S21_NULL) {
    s21_size_t len = s21_strlen(str);

    result = (char *)malloc(sizeof(char) * (len + 1));

    if (result) {
      for (s21_size_t i = 0; i <= len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
          result[i] = (str[i] - 'A') + 'a';
        } else {
          result[i] = str[i];
        }
      }
      result[len] = '\0';
    }
  }

  return result;
}