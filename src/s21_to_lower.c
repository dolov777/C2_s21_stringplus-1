#include <stdio.h>
#include <stdlib.h>

void *to_lower(const char *str) {
    int len = 0;
    if (str == NULL) {
        return NULL;
    }

    while(str[len] != '\0') {
        len++;
    }

    char *to_lower = (char *)malloc((len + 1) * sizeof(char));
    if (to_lower == NULL) {
        return NULL;
    }

    for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            to_lower[i] = str[i] - 'A' + 'a';
        } else {
            to_lower[i] = str[i];
        }
    }
    to_lower[len] = '\0';
    return (void *)to_lower;
}


