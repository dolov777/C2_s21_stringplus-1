#include <stdio.h>

char *s21_strstr(const char* haystack, const char* needle) {
    if (!*needle) {
        return (char*)haystack;
    }
    for (const char* h = haystack; *h; h++) {
        if (*h == *needle) {
            const char* h_sub = h;
            const char* n_sub = needle;

            while (*h_sub && *n_sub && *h_sub == *n_sub) {
                h_sub++;
                n_sub++;
            }

            if (!*n_sub) {
                return (char*)h;
            }
        }
    }

    return NULL;
}

