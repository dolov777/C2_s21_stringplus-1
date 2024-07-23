#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <ctype.h>
#include <errno.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define s21_NULL ((void *)0)
#define MAX_BUFFER_SIZE 1024
#define MIN_ERRLIST 0
#define MAX_ERRLIST 256

typedef unsigned long s21_size_t;

int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
int s21_sprintf(char *str, const char *format, ...);

size_t s21_strcspn(const char *str1, const char *str2);
size_t s21_strlen(const char *str);

char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strerror(int errnum);
char *s21_strchr(const char *str, int c);
char *s21_strtok(char *str, const char *delim);
char *s21_strncpy(char *str1, const char *str2, s21_size_t n);

void *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);
void *s21_trim(const char *src, const char *trim_chars);
void *s21_memchr(const void *str, int c, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);

#endif