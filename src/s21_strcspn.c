#include <stdio.h>
#include "s21_string.h"

size_t s21_strcspn(const char *str1, const char *str2) {
    size_t result = 0;

    while (str1[result] != '\0') {
        size_t index = 0;
        while (str2[index] != '\0') {
            if (str1[result] == str2[index]) {
                return result;
            }
            index++;
        }
        result++;
    }

    return result;
}

