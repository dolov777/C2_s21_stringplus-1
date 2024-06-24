#include <stdio.h>
#include <stdlib.h>

int my_strlen(const char *src) {
    int len = 0;
    while(src[len] != '\0') {
        len++;
    }

    return len;
}

void str_cpy(char *ch, const char *src) {
    int len = 0;
    while(src[len] != '\0') {
        ch[len] = src[len];
        len++;
    }
    ch[len] = '\0';
}

void *insert(const char *src, const char *str, size_t start_index) {
    if (!src || !str) {
        return NULL;
    }

    size_t str_len = my_strlen(str);
    size_t src_len = my_strlen(src);

    if (start_index > src_len) {
        return NULL;
    }

    char *new_str = (char *)malloc((str_len + src_len + 1) * sizeof(char)); 
    if (!new_str) {
        return NULL;
    }

     // Копируем часть str до индекса
    for (size_t i = 0; i < start_index; i++) {
        new_str[i] = src[i];
    }

    // всавлям на место указанного индекса элемент
    for (size_t i = 0; i < str_len; i++) {
        new_str[start_index + i] = str[i];
    }

    // вставляем оставшуюся часть элементов
    for (size_t i = start_index; i < src_len; i++) {
        new_str[str_len + i] = src[i];
    }
    
    new_str[src_len + str_len] = '\0';
    return new_str;
}