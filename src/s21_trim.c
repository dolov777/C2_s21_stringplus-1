#include <stdio.h>
#include <stdlib.h>

int my_strlen(const char *src) {
    int len = 0;
    while(src[len] != '\0') {
        len++;
    }

    return len;
}

int is_trim_char(char ch, const char *trim_chars) {
    while(*trim_chars) {
        if (ch == *trim_chars) {
            return 1;
        }
        trim_chars++;
    }

    return 0;
}

void str_cpy(char *ch, const char *src, int length) {
    for (int i = 0; i < length; i++) {
        ch[i] = src[i];
    }
    ch[length] = '\0';
}

void *trim(const char *src, const char *trim_chars) {
    if (!src || !trim_chars) {
        return NULL;
    }

    int start = 0;
    int end = my_strlen(src) - 1;

    while(start <= end && is_trim_char(src[start], trim_chars)) {
        start++;
    }

    while(end >= start && is_trim_char(src[end], trim_chars)) {
        end--;
    }
    int length = end - start + 1;

    char *result = (char*)malloc((length + 1) * sizeof(char));
    
    if (!result) {
        return NULL;
    }

    str_cpy(result, src + start, length);

    return result;
}

