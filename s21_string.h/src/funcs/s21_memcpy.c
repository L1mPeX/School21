#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *d = dest;
  const unsigned char *s = src;
  while (n--) {
    *d++ = *s++;
  }
  return dest;
}