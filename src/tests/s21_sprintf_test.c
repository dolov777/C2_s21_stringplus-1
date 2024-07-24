#include "s21_string_test.h"

START_TEST(test_s21_sprintf_1) {  // c
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, my name is %c...";

  char symbol = 'A';
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, symbol);
  expected_len = sprintf(expected_str, pattern, symbol);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_2) {  // d
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, my age is % d...";

  int age = 17;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, age);
  expected_len = sprintf(expected_str, pattern, age);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_3) {  // i
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, my age is %i...";

  int age = -17;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, age);
  expected_len = sprintf(expected_str, pattern, age);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST



START_TEST(test_s21_sprintf_6) {  // f
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %f...";

  float number = 27.777;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST



START_TEST(test_s21_sprintf_9) {  // o
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %o...";

  int number = -27;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_10) {  // o
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %o...";

  int number = 27;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_11) {  // s
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %-10.2s...";

  char str[5] = "123";
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, str);
  expected_len = sprintf(expected_str, pattern, str);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_12) {  // s
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %s...";

  char str[4] = "123";
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, str);
  expected_len = sprintf(expected_str, pattern, str);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_13) {  // u
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %u...";

  unsigned int number = 123;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_14) {  // u
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %u...";

  unsigned int number = -123;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_15) {  // x
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %x...";

  unsigned int number = 0xFF;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_16) {  // X
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %X...";

  unsigned int number = 0xFF;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_17) {  // p
  char result_str[124] = "";
  char expected_str[124] = "";
  char pattern[124] = "Hello, pointer is %+p ...";

  char *pointer = "test";

  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, &pointer);
  expected_len = sprintf(expected_str, pattern, &pointer);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_18) {  // n
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, count symbols is %n...";

  int result_symbols;
  int expected_symbols;

  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, &result_symbols);
  expected_len = sprintf(expected_str, pattern, &expected_symbols);

  ck_assert_int_eq(result_symbols, expected_symbols);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_19) {  // n
  char result_str[124];
  char expected_str[124];
  const char *pattern = "%n...";

  int result_symbols;
  int expected_symbols;

  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, &result_symbols);
  expected_len = sprintf(expected_str, pattern, &expected_symbols);

  ck_assert_int_eq(result_symbols, expected_symbols);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_20) {  // n
  char result_str[124];
  char expected_str[124];
  const char *pattern = "%n";

  int result_symbols;
  int expected_symbols;

  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, &result_symbols);
  expected_len = sprintf(expected_str, pattern, &expected_symbols);

  ck_assert_int_eq(result_symbols, expected_symbols);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_21) {  // %
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, percent is %d%%...";

  int number = 100;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_22) {  // -
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, percent is %-10d%%...";

  int number = 100;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_23) {  // -
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, percent is %+10d%%...";

  int number = 100;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_24) {  // #o
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %#o...";

  int number = 7;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_25) {  // #X
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %#X...";

  int number = 0xFF;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_26) {  // #x
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %#x...";

  int number = 0xFF;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_27) {  // #f
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %#f...";

  float number = 10;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST


START_TEST(test_s21_sprintf_29) {  // 0
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %010d...";

  int number = 10;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_30) {  // 0
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %01d...";

  int number = 10;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_31) {  // (num)
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %2d...";

  int number = 10;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_32) {  // (num)
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %10d...";

  int number = 10;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST


START_TEST(test_s21_sprintf_35) {  // hd
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %hd...";

  short int number = 32769;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_36) {  // ld
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %ld...";

  long int number = 9223372036854775807;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_37) {  // Lf
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %Lf...";

  long double number = 113132.12315149;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_40) {  // s
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %5.2s...";

  char str[5] = "123";
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, str);
  expected_len = sprintf(expected_str, pattern, str);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_41) {  // c
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, my name is %-3c...";

  char symbol = 'F';
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, symbol);
  expected_len = sprintf(expected_str, pattern, symbol);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

Suite *sprintf_suite(void) {
  Suite *s = suite_create("suite_sprintf");
  TCase *tcase = tcase_create("tc_sprintf");

  tcase_add_test(tcase, test_s21_sprintf_1);
  tcase_add_test(tcase, test_s21_sprintf_2);
  tcase_add_test(tcase, test_s21_sprintf_3);
  tcase_add_test(tcase, test_s21_sprintf_6);
  tcase_add_test(tcase, test_s21_sprintf_9);
  tcase_add_test(tcase, test_s21_sprintf_10);
  tcase_add_test(tcase, test_s21_sprintf_11);
  tcase_add_test(tcase, test_s21_sprintf_12);
  tcase_add_test(tcase, test_s21_sprintf_13);
  tcase_add_test(tcase, test_s21_sprintf_14);
  tcase_add_test(tcase, test_s21_sprintf_15);
  tcase_add_test(tcase, test_s21_sprintf_16);
  tcase_add_test(tcase, test_s21_sprintf_17);
  tcase_add_test(tcase, test_s21_sprintf_18);
  tcase_add_test(tcase, test_s21_sprintf_19);
  tcase_add_test(tcase, test_s21_sprintf_20);
  tcase_add_test(tcase, test_s21_sprintf_21);
  tcase_add_test(tcase, test_s21_sprintf_22);
  tcase_add_test(tcase, test_s21_sprintf_23);
  tcase_add_test(tcase, test_s21_sprintf_24);
  tcase_add_test(tcase, test_s21_sprintf_25);
  tcase_add_test(tcase, test_s21_sprintf_26);
  tcase_add_test(tcase, test_s21_sprintf_27);
  tcase_add_test(tcase, test_s21_sprintf_29);
  tcase_add_test(tcase, test_s21_sprintf_30);
  tcase_add_test(tcase, test_s21_sprintf_31);
  tcase_add_test(tcase, test_s21_sprintf_32);
  tcase_add_test(tcase, test_s21_sprintf_35);
  tcase_add_test(tcase, test_s21_sprintf_36);
  tcase_add_test(tcase, test_s21_sprintf_37);
  tcase_add_test(tcase, test_s21_sprintf_40);
  tcase_add_test(tcase, test_s21_sprintf_41);
  suite_add_tcase(s, tcase);
  
  return s;
}