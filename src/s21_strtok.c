#include <stdio.h>
#include "s21_string.h"

char *s21_strtok(char *str, char *delim) {
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

    while(*str && s21_strchr(delim, *str)) {
        str++;
    }
    if (*str == '\0') {
        last = NULL;
        return NULL;
    }

    token = str;

    while(*str && !s21_strchr(delim, *str)) {
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