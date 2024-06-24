#include <stdio.h>
#include <stdlib.h>

int my_strlen(const char *src) {
    int len = 0;
    while(src[len] != '\0') {
        len++;
    }
    return len;
}

void *memcpy(void *dest, const void *src, size_t n) {
    char *d = (char *)dest;
    const char *s = (const char *)src;
    for (size_t i = 0; i < n; i++) {
        d[i] = s[i];
    }
    return dest;
}


