#include "s21_string_test.h"


START_TEST(test_basic) {
    char *str = "Hello World";

    size_t res_s21 = s21_strlen(str); 

    ck_assert_int_eq(res_s21, 11);
}
END_TEST

START_TEST(test_str_numbers) {
    char *str = "123";

    size_t res_s21 = s21_strlen(str); 
    
    ck_assert_int_eq(res_s21, 3);
}
END_TEST

START_TEST(test_str_empty) {
    char *str = "";

    size_t res_s21 = s21_strlen(str); 
    
    ck_assert_int_eq(res_s21, 0);
}
END_TEST

START_TEST(test_str_break) {
    char *str = "abc\n";

    size_t res_s21 = s21_strlen(str); 
    
    ck_assert_int_eq(res_s21, 4);
}
END_TEST

START_TEST(test_str_line_break) {
    char *str = "abc\0";

    size_t res_s21 = s21_strlen(str); 
    
    ck_assert_int_eq(res_s21, 3);
}
END_TEST

START_TEST(test_str_breaks) {
    char *str = "\n\n\n\n";

    size_t res_s21 = s21_strlen(str); 
    
    ck_assert_int_eq(res_s21, 4);
}
END_TEST

START_TEST(test_str_line_breaks) {
    char *str = "\0\0\0\0";

    size_t res_s21 = s21_strlen(str); 
    
    ck_assert_int_eq(res_s21, 0);
}
END_TEST

Suite *strlen_suite(void) {
    Suite *s = suite_create("suite_strrchr");
    TCase *tc = tcase_create("tc_strstr");

    tcase_add_test(tc, test_basic);
    tcase_add_test(tc, test_str_numbers);
    tcase_add_test(tc, test_str_empty);
    tcase_add_test(tc, test_str_break);
    tcase_add_test(tc, test_str_line_break);
    tcase_add_test(tc, test_str_breaks);
    tcase_add_test(tc, test_str_line_breaks);

    suite_add_tcase(s, tc);

    return s;
}