#include <stdio.h>
#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, size_t n) {
    // if (dest == NULL || src == NULL) {
    //     return NULL;
    // }

    size_t dest_len = s21_strlen(dest);
    size_t count = 0;
    
    for (size_t i = 0; i < n; i++) {
        dest[dest_len + i] = src[i];
        count++;
    }
    dest[dest_len + count] = '\0';

    return dest;
}