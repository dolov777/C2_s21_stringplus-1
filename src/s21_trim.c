#include <stdio.h>
#include <stdlib.h>
#include "s21_string.h"

int is_trim_char(char ch, const char *trim_chars) {
    int res = 0;
    while(*trim_chars) {
        if (ch == *trim_chars) {
            res = 1;
            break;
        }
        trim_chars++;
    }

    return res;
}

// void str_cpy(char *ch, const char *src, int length) {
//     for (int i = 0; i < length; i++) {
//         ch[i] = src[i];
//     }
//     ch[length] = '\0';
// }

void *s21_trim(const char *src, const char *trim_chars) {
    char *res = NULL;

    if (src && trim_chars) {
        int start = 0;
        int end = s21_strlen(src) - 1;

        while (start <= end && is_trim_char(src[start], trim_chars)) {
            start++;
        }

        while (end >= start && is_trim_char(src[end], trim_chars)) {
            end--;
        }

        int length = end - start + 1;

        if (length > 0) {
            res = (char*)malloc((length + 1) * sizeof(char));
            if (res) {
                s21_strncpy(res, src + start, length);
                res[length] = '\0';
            }
        } else if (length == 0) {
            res = (char*)malloc(1 * sizeof(char));
            if (res) {
                res[0] = '\0';
            }
        }
    }

    return res;
}

