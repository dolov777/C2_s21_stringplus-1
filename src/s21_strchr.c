#include <stdio.h>
// #include <string.h>

char *strchr(const char *str, int c) {
    size_t len = 0;

    while (str[len] != '\0') {
        len++;
    }

    for (size_t i = 0; i < len; i++) {
        if (str[i] == (char)c) {
            return (char *)&str[i];
        }
    }

    if (c == '\0') {
        return (char *)&str[len];
    }

    return NULL;
}

