#include "s21_string_test.h"

START_TEST(test_d_flag) {
  char buffer[100];
  char expected[100];

  s21_sprintf(buffer, "%d", 42);
  sprintf(expected, "%d", 42);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_minus_flag) {
  char buffer[100];
  char expected[100];

  s21_sprintf(buffer, "%-5d", 42);
  sprintf(expected, "%-5d", 42);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_plus_flag) {
  char buffer[100];
  char expected[100];

  s21_sprintf(buffer, "%+d", 42);
  sprintf(expected, "%+d", 42);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_space_flag) {
  char buffer[100];
  char expected[100];

  s21_sprintf(buffer, "% d", 42);
  sprintf(expected, "% d", 42);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_zero_flag) {
  char buffer[100];
  char expected[100];
  
  s21_sprintf(buffer, "%05d", 42);
  sprintf(expected, "%05d", 42);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_c_flag) {
  char buffer[100];
  char expected[100];

  s21_sprintf(buffer, "%c", 'A');
  sprintf(expected, "%c", 'A');

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s_flag) {
  char buffer[100];
  char expected[100];

  s21_sprintf(buffer, "%s", "Hello");
  sprintf(expected, "%s", "Hello");

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_u_flag) {
  char buffer[100];
  char expected[100];

  s21_sprintf(buffer, "%u", 42);
  sprintf(expected, "%u", 42);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_f_flag) {
  char buffer[100];
  char expected[100];

  s21_sprintf(buffer, "%.2f", 3.14159);
  sprintf(expected, "%.2f", 3.14159);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_percent_flag) {
  char buffer[100];
  char expected[100];

  s21_sprintf(buffer, "%%");
  sprintf(expected, "%%");

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_width) {
  char buffer[100];
  char expected[100];

  s21_sprintf(buffer, "%10d", 42);
  sprintf(expected, "%10d", 42);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%5s", "abc");
  sprintf(expected, "%5s", "abc");
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%8.2f", 3.14159);
  sprintf(expected, "%8.2f", 3.14159);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_precision) {
  char buffer[100];
  char expected[100];

  s21_sprintf(buffer, "%.2d", 42);
  sprintf(expected, "%.2d", 42);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%.5s", "abcdef");
  sprintf(expected, "%.5s", "abcdef");
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%.3f", 3.14159);
  sprintf(expected, "%.3f", 3.14159);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_length_modifiers) {
  char buffer[100];
  char expected[100];
  short int si = 32000;

  s21_sprintf(buffer, "%hd", si);
  sprintf(expected, "%hd", si);
  ck_assert_str_eq(buffer, expected);

  unsigned short int usi = 60000;
  s21_sprintf(buffer, "%hu", usi);
  sprintf(expected, "%hu", usi);
  ck_assert_str_eq(buffer, expected);

  long int li = 1000000L;
  s21_sprintf(buffer, "%ld", li);
  sprintf(expected, "%ld", li);
  ck_assert_str_eq(buffer, expected);

  unsigned long int uli = 1000000UL;
  s21_sprintf(buffer, "%lu", uli);
  sprintf(expected, "%lu", uli);
  ck_assert_str_eq(buffer, expected);

  long double ld = 3.141592653589793238L;
  s21_sprintf(buffer, "%Lf", ld);
  sprintf(expected, "%Lf", ld);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

Suite *sprintf_suite(void) {
  Suite *s = suite_create("suite_sprintf");
  TCase *tc = tcase_create("tc_sprintf");

  tcase_add_test(tc, test_d_flag);
  tcase_add_test(tc, test_minus_flag);
  tcase_add_test(tc, test_plus_flag);
  tcase_add_test(tc, test_space_flag);
  tcase_add_test(tc, test_zero_flag);
  tcase_add_test(tc, test_c_flag);
  tcase_add_test(tc, test_s_flag);
  tcase_add_test(tc, test_u_flag);
  tcase_add_test(tc, test_f_flag);
  tcase_add_test(tc, test_percent_flag);
  tcase_add_test(tc, test_width);
  tcase_add_test(tc, test_precision);
  tcase_add_test(tc, test_length_modifiers);
  suite_add_tcase(s, tc);
  
  return s;
}