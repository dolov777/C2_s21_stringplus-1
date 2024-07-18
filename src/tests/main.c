#include "s21_string_test.h"

int main() {
    int number_failed;
    Suite *s1, *s2, *s3, *s4, *s5, *s6, *s7, *s8; 
    SRunner *sr;

    s1 = strchr_suite();
    s2 = strstr_suite();
    s3 = strrchr_suite();
    s4 = strlen_suite();
    s5 = to_lower_suite();
    s6 = to_upper_suite();
    s7 = memcmp_suite();
    s8 = strncmp_suite();
    // s9 = strerror_suite();


    sr = srunner_create(s1);
    srunner_add_suite(sr, s2);
    srunner_add_suite(sr, s3);
    srunner_add_suite(sr, s4);
    srunner_add_suite(sr, s5);
    srunner_add_suite(sr, s6);
    srunner_add_suite(sr, s7);
    srunner_add_suite(sr, s8);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? 0 : 1;
}