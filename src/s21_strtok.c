#include <stdio.h>

char *strchr(const char *str, int c) {
    while(*str) {
        if (*str == (char)c) {
            return (char *)str;
        }
        str++;
    }

    return 0;
}

char *strtok(char *str, char *delim) {
    static char *last = NULL;
    char *token;
    if (str != NULL) {
        last = str;
    } else {
        if (last == NULL) {
            return NULL;
        }
        str = last;
    }

    while(*str && strchr(delim, *str)) {
        str++;
    }

    if (*str == '\0') {
        last = NULL;
        return NULL;
    }

    token = str;

    while(*str && !strchr(delim, *str)) {
        str++;
    }

    if (*str) {
        *str = '\0';
        last = str + 1;
    } else {
        last = NULL;
    }
    return token;
}
