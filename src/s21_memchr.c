#include "s21_string.h"

void *s21_memchr(const void *str, int c, size_t n) {
    const char *result = str;
    int status = 0;
    int x = 0;

    while (status == 0 && result && (size_t)x < n) {
        if (result[x] == c) {
            if (c != '\0') {
                result += x;
            }
            status = 1;
        }
        x += 1;
    }


    return status ? ((void *)result) : s21_NULL;
}
