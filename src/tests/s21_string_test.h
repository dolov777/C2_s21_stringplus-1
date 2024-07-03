#include "s21_string.h"
#include <check.h>
#include <stddef.h>
#include <string.h>

START_TEST(test_basic) {
    char *haystack = "hello world";
    char *needle = "world";

    char *res_s21 = s21_strstr(haystack, needle); 
    char *res_orig = strstr(haystack, needle);

    ck_assert_ptr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_not_found) {
    char *haystack = "hello world";
    char *needle = "caucasus";

    char *res_s21 = s21_strstr(haystack, needle); 
    char *res_orig = strstr(haystack, needle);

    ck_assert_ptr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_needle_empty) {
    char *haystack = "hello world";
    char *needle = "";

    char *res_s21 = s21_strstr(haystack, needle); 
    char *res_orig = strstr(haystack, needle);

    ck_assert_ptr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_haystack_empty) {
    char *haystack = "";
    char *needle = "world";
   
    char *res_s21 = s21_strstr(haystack, needle); 
    char *res_orig = strstr(haystack, needle);

    ck_assert_ptr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_both_empty) {
    char *haystack = "";
    char *needle = "";

    char *res_s21 = s21_strstr(haystack, needle); 
    char *res_orig = strstr(haystack, needle);

    ck_assert_ptr_eq(res_s21, res_orig);
}
END_TEST

