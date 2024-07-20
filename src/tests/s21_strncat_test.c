#include "s21_string_test.h"

START_TEST(test_basic) {
    char dest_s21[128] = "hello";
    char dest[128] = "hello";
    char src[] = " world";
    int len = s21_strlen(src);

    char *res_s21 = s21_strncat(dest_s21, src, len);
    char *res_orig = strncat(dest, src, len);

    ck_assert_str_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_dest_empty) {
    char dest_s21[128] = "";
    char dest[128] = "";
    char src[] = " world";
    int len = s21_strlen(src);

    char *res_s21 = s21_strncat(dest_s21, src, len);
    char *res_orig = strncat(dest, src, len);

    ck_assert_str_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_src_empty) {
    char dest_s21[128] = "hello";
    char dest[128] = "hello";
    char src[] = "";
    int len = s21_strlen(src);

    char *res_s21 = s21_strncat(dest_s21, src, len);
    char *res_orig = strncat(dest, src, len);

    ck_assert_str_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_both_empty) {
    char dest_s21[128] = "";
    char dest[128] = "";
    char src[] = "";
    int len = s21_strlen(src);

    char *res_s21 = s21_strncat(dest_s21, src, len);
    char *res_orig = strncat(dest, src, len);

    ck_assert_str_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_spaces) {
    char dest_s21[128] = "hello";
    char dest[128] = "hello";
    char src[] = "           ";
    int len = s21_strlen(src);

    char *res_s21 = s21_strncat(dest_s21, src, len);
    char *res_orig = strncat(dest, src, len);

    ck_assert_str_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_len_larger) {
    char dest_s21[128] = "hello";
    char dest[128] = "hello";
    char src[] = "world";
    int len = 6;

    char *res_s21 = s21_strncat(dest_s21, src, len);
    char *res_orig = strncat(dest, src, len);

    ck_assert_str_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_break) {
    char dest_s21[128] = "hello\n\n";
    char dest[128] = "hello\n\n";
    char src[] = "\n\n";
    int len = s21_strlen(src);

    char* res_s21 = s21_strncat(dest_s21, src, len);
    char* res_orig = strncat(dest, src, len);

    ck_assert_str_eq(res_s21, res_orig);
}
END_TEST

START_TEST(test_line_break) {
    char dest_s21[128] = "\0\0";
    char dest[128] = "\0\0";
    char src[] = "~";
    int len = s21_strlen(src);

    char *res_s21 = s21_strncat(dest_s21, src, len);
    char *res_orig = strncat(dest, src, len);

    ck_assert_str_eq(res_s21, res_orig);
}
END_TEST

Suite *strncat_suite(void) {
    Suite *s = suite_create("suite_strncat");
    TCase *tc = tcase_create("tc_strncat");

    tcase_add_test(tc, test_basic);
    tcase_add_test(tc, test_dest_empty);
    tcase_add_test(tc, test_src_empty);
    tcase_add_test(tc, test_both_empty);
    tcase_add_test(tc, test_spaces);
    tcase_add_test(tc, test_len_larger);
    tcase_add_test(tc, test_break);
    tcase_add_test(tc, test_line_break);

    suite_add_tcase(s, tc);

    return s;
}


// START_TEST(test_s21_strncat_1) {
//   char s21_dest[256] = "Hello, world!";
//   char dest[256] = "Hello, world!";
//   char src[] = "\nMy name is Henry";
//   int len = strlen(src);
//   char *s21_result = s21_strncat(s21_dest, src, len);
//   char *result = strncat(dest, src, len);
//   ck_assert_ptr_eq(s21_result, s21_dest);
//   ck_assert_ptr_eq(result, dest);
//   ck_assert_str_eq(s21_result, result);
// }
// END_TEST

// START_TEST(test_s21_strncat_2) {
//   char s21_dest[10] = "";
//   char dest[10] = "";
//   char src[] = "123";
//   int len = strlen(src);
//   char *s21_result = s21_strncat(s21_dest, src, len);
//   char *result = strncat(dest, src, len);
//   ck_assert_ptr_eq(s21_result, s21_dest);
//   ck_assert_str_eq(s21_result, result);
// }
// END_TEST

// START_TEST(test_s21_strncat_3) {
//   char s21_dest[256] = "Lorem ipsum dolor sit amet consectetur.\n";
//   char dest[256] = "Lorem ipsum dolor sit amet consectetur.\n";
//   char src[10] = " ";
//   int len = 10;
//   char *s21_result = s21_strncat(s21_dest, src, len);
//   char *result = strncat(dest, src, len);
//   ck_assert_ptr_eq(s21_result, s21_dest);
//   ck_assert_str_eq(s21_result, result);
// }
// END_TEST

// START_TEST(test_s21_strncat_4) {
//   char s21_dest[] = "\0\0\0";
//   char dest[] = "\0\0\0";
//   char src[] = "^";
//   int len = strlen(src);
//   char *s21_result = s21_strncat(s21_dest, src, len);
//   char *result = strncat(dest, src, len);
//   ck_assert_ptr_eq(s21_result, s21_dest);
//   ck_assert_str_eq(s21_result, result);
// }
// END_TEST

// START_TEST(test_s21_strncat_5) {
//   char s21_dest[128] = "Hello, world!";
//   char dest[128] = "Hello, world!";
//   char src[] = "Hi, my name is Harry";
//   int len = 5;
//   char *s21_result = s21_strncat(s21_dest, src, len);
//   char *result = strncat(dest, src, len);
//   ck_assert_ptr_eq(s21_result, s21_dest);
//   ck_assert_str_eq(s21_result, result);
// }
// END_TEST

// START_TEST(test_s21_strncat_6) {
//   char s21_dest[128] = "Lorem ipsum dolor sit amet consectetur.\n";
//   char dest[128] = "Lorem ipsum dolor sit amet consectetur.\n";
//   char src[] = "";
//   int len = strlen(src);
//   char *s21_result = s21_strncat(s21_dest, src, len);
//   char *result = strncat(dest, src, len);
//   ck_assert_ptr_eq(s21_result, s21_dest);
//   ck_assert_str_eq(s21_result, result);
// }
// END_TEST

// START_TEST(test_s21_strncat_7) {
//   char s21_dest[128] = "";
//   char dest[128] = "";
//   char src[] = "1234567890\t1234567890";
//   int len = 11;
//   char *s21_result = s21_strncat(s21_dest, src, len);
//   char *result = strncat(dest, src, len);
//   ck_assert_ptr_eq(s21_result, s21_dest);
//   ck_assert_str_eq(s21_result, result);
// }
// END_TEST

// Suite *strncat_suite(void) {
//     Suite *s = suite_create("suite_strncat");
//     TCase *tc = tcase_create("tc_strncat");

//   tcase_add_test(tc, test_s21_strncat_1);
//   tcase_add_test(tc, test_s21_strncat_2);
//   tcase_add_test(tc, test_s21_strncat_3);
//   tcase_add_test(tc, test_s21_strncat_4);
//   tcase_add_test(tc, test_s21_strncat_5);
//   tcase_add_test(tc, test_s21_strncat_6);
//   tcase_add_test(tc, test_s21_strncat_7);

//   return s;
// }