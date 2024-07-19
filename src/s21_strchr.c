#include <stdio.h>

char *s21_strchr(const char *str, int c) {
    char *res = NULL;
    while(*str) {
        if (*str == (char)c) {
            res = (char *)str;
            break;
        }
        str++;
    }

    if (c == '\0') {
        res = (char *)str;
    }

    return res;
}