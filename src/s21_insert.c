#include <stdio.h>
#include <stdlib.h>
#include "s21_string.h"

void *s21_insert(const char *src, const char *str, size_t start_index) {
    void *result = NULL;

    if (src && str) {
        size_t str_len = s21_strlen(str);
        size_t src_len = s21_strlen(src);

        if (start_index <= src_len) {
            char *new_str = (char *)malloc((str_len + src_len + 1) * sizeof(char)); 
            if (new_str) {
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
                result = new_str;   
            }
        }
    }

    return result;
}
