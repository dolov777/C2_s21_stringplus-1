#include <stddef.h>
#include <stdio.h>

int s21_strncmp(const char *str1, const char *str2, size_t n) {
    int res = 0;
    for (size_t i = 0; i < n; i++) {
        
        if (str1[i] != str2[i] || str1[i] == '\0' || str2[i] == '\0') {
            res = (unsigned char)str1[i] - (unsigned char)str2[i];
            break;
        }
    }
    
    return res;
}
