#include "s21_string.h"

unsigned int get_unsigned_argument(va_list args, char length_modifier);
int get_int_argument(va_list args, char length_modifier);
int s21_sprintf(char *buffer, const char *format, ...);

char to_upper(char ch);

void s21_itoa(long long value, char *str, int base);
void s21_uittoa(unsigned int value, char *str, int base);
void s21_ftoa(double value, char *str, int precision);
void s21_lftoa(long double value, char *str, int precision);
