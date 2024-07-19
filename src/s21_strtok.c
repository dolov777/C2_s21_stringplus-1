#include <stdio.h>
#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
    static char *last = NULL;
    char *token = NULL;

    if (str != NULL) {
        last = str;
    }

    int end_of_string = 0;

    if (last == NULL) {
        end_of_string = 1;
    } else {
        while (*last && s21_strchr(delim, *last)) {
            last++;
        }

        if (*last == '\0') {
            end_of_string = 1;
        } else {
            token = last;

            while (*last && !s21_strchr(delim, *last)) {
                last++;
            }

            if (*last) {
                *last = '\0';
                last++;
            } else {
                last = NULL;
            }
        }
    }

    return end_of_string ? NULL : token;
}