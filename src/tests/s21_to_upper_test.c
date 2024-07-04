#include "s21_string_test.h"

START_TEST(test_basic) {
    char *str = "Hello World";

    char *res_s21 = s21_to_lower(str); 

    ck_assert_str_eq(res_s21, "HELLO WORLD");
}
END_TEST

START_TEST(test_str_upper) {
    char *str = "HELLO WORLD";

    char *res_s21 = s21_to_lower(str); 

    ck_assert_str_eq(res_s21, "HELLO WORLD");
}
END_TEST

START_TEST(test_str_numbers) {
    char *str = "12345";

    char *res_s21 = s21_to_lower(str); 

    ck_assert_str_eq(res_s21, "12345");
}
END_TEST

START_TEST(test_str_null) {
    char *str = NULL;

    char *res_s21 = s21_to_lower(str); 

    ck_assert_ptr_eq(res_s21, NULL);
}
END_TEST

START_TEST(test_str_spec_chars) {
    char *str = "!@#$$^&*()_+";

    char *res_s21 = s21_to_lower(str); 

    ck_assert_str_eq(res_s21, "!@#$$^&*()_+");
}
END_TEST

START_TEST(test_str_empty) {
    char *str = "";

    char *res_s21 = s21_to_lower(str); 

    ck_assert_str_eq(res_s21, "");
}
END_TEST

START_TEST(test_str_space) {
    char *str = " ";

    char *res_s21 = s21_to_lower(str); 

    ck_assert_str_eq(res_s21, " ");
}
END_TEST

START_TEST(test_str_break) {
    char *str = "Hello,\nWorld!";

    char *res_s21 = s21_to_lower(str); 

    ck_assert_str_eq(res_s21, "HELLO,\nWORLD!");
}
END_TEST

Suite *strchr_suite(void) {
    Suite *s = suite_create("suite_strrchr");
    TCase *tc = tcase_create("tc_strstr");

    tcase_add_test(tc, test_basic);
    tcase_add_test(tc, test_str_upper);
    tcase_add_test(tc, test_str_numbers);
    tcase_add_test(tc, test_str_null);
    tcase_add_test(tc, test_str_spec_chars);
    tcase_add_test(tc, test_str_empty);
    tcase_add_test(tc, test_str_space);
    tcase_add_test(tc, test_str_break);
    
    suite_add_tcase(s, tc);

    return s;
}