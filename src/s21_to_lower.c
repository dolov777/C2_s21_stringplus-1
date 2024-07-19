#include <stdio.h>
#include <stdlib.h>

void *s21_to_lower(const char *str) {
    char *to_lower = NULL;

    if (str != NULL) {
        int len = 0;
        while(str[len] != '\0') {
            len++;
        }

        to_lower = (char *)malloc((len + 1) * sizeof(char));
        
        if (to_lower != NULL) {
            for (int i = 0; i < len; i++) {
                if (str[i] >= 'A' && str[i] <= 'Z') {
                    to_lower[i] = str[i] - 'A' + 'a';
                } else {
                    to_lower[i] = str[i];
                }
            }   
            to_lower[len] = '\0';
        }
    }

    return (void *)to_lower;
}


