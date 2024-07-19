#include <stdio.h>
#include <stdlib.h>


void *s21_to_upper(const char *str) {
    char *upper_str = NULL;

    if (str != NULL) {
        int len = 0;
        while(str[len] != '\0') {
            len++;
        }

        upper_str = (char *)malloc((len + 1) * sizeof(char));
        if (upper_str != NULL) {
            for (int i = 0; i < len; i++) {
                if (str[i] >= 'a' && str[i] <= 'z') {
                    upper_str[i] = str[i] - 'a' + 'A';
                } else {
                    upper_str[i] = str[i];
                }
            }
            upper_str[len] = '\0';
        }
    }
    
    return (void *)upper_str;
}

