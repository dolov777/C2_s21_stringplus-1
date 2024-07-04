#include "s21_string_test.h"

START_TEST(test_basic) {
    char *haystack = "hello world";
    char *needle = "world";

    char *res_s21 = s21_strstr(haystack, needle); 
    char *res_orig = strstr(haystack, needle);

    ck_assert_str_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_str_equals) {
    char *haystack = "hello world";
    char *needle = "hello world";

    char *res_s21 = s21_strstr(haystack, needle); 
    char *res_orig = strstr(haystack, needle);

    ck_assert_str_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_not_found) {
    char *haystack = "hello world";
    char *needle = "caucasus";

    char *res_s21 = s21_strstr(haystack, needle); 
    char *res_orig = strstr(haystack, needle);

    ck_assert_str_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_needle_empty) {
    char *haystack = "hello world";
    char *needle = "";

    char *res_s21 = s21_strstr(haystack, needle); 
    char *res_orig = strstr(haystack, needle);

    ck_assert_str_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_haystack_empty) {
    char *haystack = "";
    char *needle = "world";
   
    char *res_s21 = s21_strstr(haystack, needle); 
    char *res_orig = strstr(haystack, needle);

    ck_assert_str_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_both_empty) {
    char *haystack = "";
    char *needle = "";

    char *res_s21 = s21_strstr(haystack, needle); 
    char *res_orig = strstr(haystack, needle);

    ck_assert_str_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_partially_coincides) {
    char *haystack = "hellohello";
    char *needle = "hello";

    char *res_s21 = s21_strstr(haystack, needle); 
    char *res_orig = strstr(haystack, needle);

    ck_assert_str_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_needle_larger) {
    char *haystack = "hello world";
    char *needle = "hello world hello world";

    char *res_s21 = s21_strstr(haystack, needle); 
    char *res_orig = strstr(haystack, needle);

    ck_assert_str_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_needle_null) {
    char *haystack = "hello world";
    char *needle = NULL;

    char *res_s21 = s21_strstr(haystack, needle); 
    char *res_orig = strstr(haystack, needle);

    ck_assert_ptr_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_haystack_null) {
    char *haystack = NULL;
    char *needle = "hello";

    char *res_s21 = s21_strstr(haystack, needle); 
    char *res_orig = strstr(haystack, needle);

    ck_assert_ptr_eq(res_s21, res_orig);
}
END_TEST

Suite *strchr_suite(void) {
    Suite *s = suite_create("suite_strrchr");
    TCase *tc = tcase_create("tc_strstr");

    tcase_add_test(tc, test_basic);
    tcase_add_test(tc, test_str_equals);
    tcase_add_test(tc, test_not_found);
    tcase_add_test(tc, test_needle_empty);
    tcase_add_test(tc, test_haystack_empty);
    tcase_add_test(tc, test_both_empty);
    tcase_add_test(tc, test_partially_coincides);
    tcase_add_test(tc, test_needle_larger);
    tcase_add_test(tc, test_needle_null);
    tcase_add_test(tc, test_haystack_null);

    suite_add_tcase(s, tc);

    return s;
}