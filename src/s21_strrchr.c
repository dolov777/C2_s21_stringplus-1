#include <stdio.h>

char *strrchr(const char *str, int c) {
    const char *elem = NULL;
    const char *count = str;
    
    while (*count != '\0') {
        if (*count == (char)c) {
            elem = count;
        }
        count++;
    }
    if (*count == (char)c) {
        elem = count;    
    }

    return (char *) elem;
}

