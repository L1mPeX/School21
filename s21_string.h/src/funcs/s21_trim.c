#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == S21_NULL || trim_chars == S21_NULL) {
    return S21_NULL;
  }

  const char *default_trim = " \t\n";
  const char *trim_set = (*trim_chars == '\0') ? default_trim : trim_chars;

  const char *begin = src;
  while (*begin != '\0' && s21_strchr(trim_set, *begin) != S21_NULL) {
    begin++;
  }

  const char *end = src + s21_strlen(src) - 1;
  while (end >= begin && s21_strchr(trim_set, *end) != S21_NULL) {
    end--;
  }

  size_t len = (end >= begin) ? (end - begin + 1) : 0;
  char *res = (char *)malloc(len + 1);

  if (res != S21_NULL) {
    if (len) {
      s21_memcpy(res, begin, len);
    }
    res[len] = '\0';
  }

  return res;
}