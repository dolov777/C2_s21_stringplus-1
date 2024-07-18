#include "s21_string_test.h"

// START_TEST(test_basic) {
//     char *str = "hello world";
//     char c = 'o';

//     char *res_s21 = s21_memcpy(str1, str2, n); 
//     char *res_orig = memcpy(str1, str2, n);

//     ck_assert_ptr_eq(res_s21, res_orig);
// }
// END_TEST



Suite *strcpy_suite(void) {
    Suite *s = suite_create("suite_memcpy");
    TCase *tc = tcase_create("tc_memcpy");

    // tcase_add_test(tc, test_basic);
    // tcase_add_test(tc, test_char_equals);
    // tcase_add_test(tc, test_not_found);
    // tcase_add_test(tc, test_str_empty);
    // tcase_add_test(tc, test_line_break);
    // tcase_add_test(tc, test_c_break);
    // tcase_add_test(tc, test_c_space);

    suite_add_tcase(s, tc);

    return s;
}