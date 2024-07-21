#include "s21_string_test.h"

START_TEST(test_integer) {
    char buffer[256];
    s21_sprintf(buffer, "Integer: %d", 42);
    ck_assert_str_eq(buffer, "Integer: 42");
}
END_TEST

START_TEST(test_character) {
    char buffer[256];
    s21_sprintf(buffer, "Character: %c", 'A');
    ck_assert_str_eq(buffer, "Character: A");
}
END_TEST

START_TEST(test_string) {
    char buffer[256];
    s21_sprintf(buffer, "String: %s", "hello");
    ck_assert_str_eq(buffer, "String: hello");
}
END_TEST

START_TEST(test_unsigned) {
    char buffer[256];
    s21_sprintf(buffer, "Unsigned: %u", 42U);
    ck_assert_str_eq(buffer, "Unsigned: 42");
}
END_TEST

START_TEST(test_float) {
    char buffer[256];
    s21_sprintf(buffer, "Float: %.2f", 3.14159);
    ck_assert_str_eq(buffer, "Float: 3.14");
}
END_TEST

START_TEST(test_percent) {
    char buffer[256];
    s21_sprintf(buffer, "Percent: %%");
    ck_assert_str_eq(buffer, "Percent: %");
}
END_TEST

START_TEST(test_width) {
    char buffer[256];
    s21_sprintf(buffer, "Width: %5d", 42);
    ck_assert_str_eq(buffer, "Width:    42");
}
END_TEST

START_TEST(test_precision) {
    char buffer[256];
    s21_sprintf(buffer, "Precision: %.5d", 42);
    ck_assert_str_eq(buffer, "Precision: 00042");
}
END_TEST

// START_TEST(test_combo) {
//     char buffer[256];
//     s21_sprintf(buffer, "Combo: %+08.5d", 42);
//     ck_assert_str_eq(buffer, "Combo: +00042");
// }
// END_TEST

START_TEST(test_short_integer) {
    char buffer[256];
    s21_sprintf(buffer, "Short: %hd", (short)42);
    ck_assert_str_eq(buffer, "Short: 42");
}
END_TEST

START_TEST(test_long_integer) {
    char buffer[256];
    s21_sprintf(buffer, "Long: %ld", (long)42);
    ck_assert_str_eq(buffer, "Long: 42");
}
END_TEST

Suite *sprintf_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("suite_sprintf");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_integer);
    tcase_add_test(tc_core, test_character);
    tcase_add_test(tc_core, test_string);
    tcase_add_test(tc_core, test_unsigned);
    tcase_add_test(tc_core, test_float);
    tcase_add_test(tc_core, test_percent);
    tcase_add_test(tc_core, test_width);
    tcase_add_test(tc_core, test_precision);
    // tcase_add_test(tc_core, test_combo);
    tcase_add_test(tc_core, test_short_integer);
    tcase_add_test(tc_core, test_long_integer);

    suite_add_tcase(s, tc_core);

    return s;
}