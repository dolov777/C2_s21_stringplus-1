#include <stdio.h>

void *s21_memset(void *str, int c, size_t n) {
    unsigned char *stroke = (unsigned char *)str;

    for (size_t i = 0; i < n; i++) {
        stroke[i] = (char)c;
    }
    
    return str;
}
