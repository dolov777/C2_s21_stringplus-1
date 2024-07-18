#ifndef STRING_TEST_H
#define STRING_TEST_H

#include "../s21_string.h"
#include <check.h>
#include <stddef.h>
#include <string.h>

Suite *strchr_suite(void);
Suite *strstr_suite(void);
Suite *strrchr_suite(void);
Suite *strlen_suite(void);
// Suite *strerror_suite(void);
Suite *memcmp_suite(void);

Suite *to_lower_suite(void);
Suite *to_upper_suite(void);

#endif 