#include <stdio.h>

int s21_memcmp(const void *str1, const void *str2, size_t n) {
    int res = 0;
    const unsigned char *s1 = (const unsigned char *)str1;
    const unsigned char *s2 = (const unsigned char *)str2;

    for (size_t i = 0; i < n; i++) {
        if (*s1 != *s2) {
            res = *s1 - *s2;
        }
        s1++;
        s2++;
    }
    return res;
}