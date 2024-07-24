#include "s21_string.h"

void s21_itoa(int value, char *str, int base) {
    char *ptr = str, *ptr1 = str, tmp_char;
    int tmp_value;

    if (value < 0 && base == 10) {
        *ptr++ = '-';
        value = -value;
    }

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "0123456789abcdef"[tmp_value % base];
    } while (value);

    *ptr-- = '\0';

    while (ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr-- = *ptr1;
        *ptr1++ = tmp_char;
    }
}

void s21_uittoa(unsigned int value, char *str, int base) {
    char *ptr = str, *ptr1 = str, tmp_char;
    int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "0123456789abcdef"[tmp_value % base];
    } while (value);

    *ptr-- = '\0';

    while (ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr-- = *ptr1;
        *ptr1++ = tmp_char;
    }
}

void s21_ftoa(double value, char *str, int precision) {
    int int_part = (int)value;
    double fraction_part = value - int_part;
    char *ptr = str;

    // Handle integer part
    s21_itoa(int_part, ptr, 10);
    while (*ptr != '\0') ptr++;

    *ptr++ = '.';

    // Handle fraction part
    for (int i = 0; i < precision; i++) {
        fraction_part *= 10;
        int digit = (int)fraction_part;
        *ptr++ = '0' + digit;
        fraction_part -= digit;
    }

    // Handle rounding
    fraction_part *= 10;
    if ((int)fraction_part >= 5) {
        char *round_ptr = ptr - 1;
        while (round_ptr >= str && *round_ptr == '9') {
            *round_ptr = '0';
            round_ptr--;
        }
        if (round_ptr >= str && *round_ptr != '.') {
            (*round_ptr)++;
        } else if (round_ptr < str) {
            for (char *shift_ptr = ptr; shift_ptr > str; shift_ptr--) {
                *shift_ptr = *(shift_ptr - 1);
            }
            *str = '1';
            ptr++;
        }
    }

    *ptr = '\0';
}

void s21_lftoa(long double value, char *str, int precision) {
    long long int_part = (long long)value;
    long double fraction_part = value - int_part;
    char *ptr = str;

    // Handle integer part
    s21_itoa(int_part, ptr, 10);
    while (*ptr != '\0') ptr++;

    *ptr++ = '.';

    // Handle fraction part
    for (int i = 0; i < precision; i++) {
        fraction_part *= 10;
        int digit = (int)fraction_part;
        *ptr++ = '0' + digit;
        fraction_part -= digit;
    }

    // Handle rounding
    fraction_part *= 10;
    if ((int)fraction_part >= 5) {
        char *round_ptr = ptr - 1;
        while (round_ptr >= str && *round_ptr == '9') {
            *round_ptr = '0';
            round_ptr--;
        }
        if (round_ptr >= str && *round_ptr != '.') {
            (*round_ptr)++;
        } else if (round_ptr < str) {
            for (char *shift_ptr = ptr; shift_ptr > str; shift_ptr--) {
                *shift_ptr = *(shift_ptr - 1);
            }
            *str = '1';
            ptr++;
        }
    }

    *ptr = '\0';
}

int s21_sprintf(char *buffer, const char *format, ...) {
    va_list args;
    va_start(args, format);
    const char *traverse;
    char *str;
    int i;
    unsigned int u;
    double f;
    long double lf;
    char buf[100];
    char *str_beginning = buffer;
    int written = 0;

    for (traverse = format; *traverse != '\0'; traverse++) {
        while (*traverse != '%' && *traverse != '\0') {
            *buffer++ = *traverse++;
            written++;
        }

        if (*traverse == '\0') break;

        traverse++;

        if (*traverse == '%') {
            *buffer++ = '%';
            written++;
            continue;
        }

        int width = 0;
        int precision = -1;
        int left_align = 0;
        int zero_padding = 0;
        int plus_sign = 0;
        int space_sign = 0;
        int hash_flag = 0;

        // Parse flags
        while (*traverse == '-' || *traverse == '+' || *traverse == ' ' ||
               *traverse == '#' || *traverse == '0') {
            if (*traverse == '-')
                left_align = 1;
            else if (*traverse == '+')
                plus_sign = 1;
            else if (*traverse == ' ')
                space_sign = 1;
            else if (*traverse == '#')
                hash_flag = 1;
            else if (*traverse == '0')
                zero_padding = 1;
            traverse++;
        }

        // Parse width
        while (*traverse >= '0' && *traverse <= '9') {
            width = width * 10 + (*traverse - '0');
            traverse++;
        }

        // Parse precision
        if (*traverse == '.') {
            traverse++;
            precision = 0;
            while (*traverse >= '0' && *traverse <= '9') {
                precision = precision * 10 + (*traverse - '0');
                traverse++;
            }
        }

        // Parse length modifier
        char length_modifier = '\0';
        if (*traverse == 'h' || *traverse == 'l' || *traverse == 'L') {
            length_modifier = *traverse;
            traverse++;
            if ((length_modifier == 'h' && *traverse == 'h') ||
                (length_modifier == 'l' && *traverse == 'l')) {
                length_modifier = length_modifier == 'h' ? 'H' : 'L';
                traverse++;
            }
        }

        switch (*traverse) {
            case 'd':
            case 'i':
                if (length_modifier == 'h') {
                    i = (short)va_arg(args, int);
                } else if (length_modifier == 'H') {
                    i = (char)va_arg(args, int);
                } else if (length_modifier == 'l') {
                    i = va_arg(args, long);
                } else {
                    i = va_arg(args, int);
                }
                if (i >= 0 && (plus_sign || space_sign)) {
                    *buffer++ = plus_sign ? '+' : ' ';
                }
                s21_itoa(i, buf, 10);
                str = buf;
                break;
            case 'u':
                if (length_modifier == 'h') {
                    u = (unsigned short)va_arg(args, unsigned int);
                } else if (length_modifier == 'H') {
                    u = (unsigned char)va_arg(args, unsigned int);
                } else if (length_modifier == 'l') {
                    u = va_arg(args, unsigned long);
                } else {
                    u = va_arg(args, unsigned int);
                }
                s21_uittoa(u, buf, 10);
                str = buf;
                break;
            case 'o':
                if (length_modifier == 'h') {
                    u = (unsigned short)va_arg(args, unsigned int);
                } else if (length_modifier == 'H') {
                    u = (unsigned char)va_arg(args, unsigned int);
                } else if (length_modifier == 'l') {
                    u = va_arg(args, unsigned long);
                } else {
                    u = va_arg(args, unsigned int);
                }
                if (hash_flag && u != 0) {
                    *buffer++ = '0';
                }
                s21_uittoa(u, buf, 8);
                str = buf;
                break;
            case 'x':
                if (length_modifier == 'h') {
                    u = (unsigned short)va_arg(args, unsigned int);
                } else if (length_modifier == 'H') {
                    u = (unsigned char)va_arg(args, unsigned int);
                } else if (length_modifier == 'l') {
                    u = va_arg(args, unsigned long);
                } else {
                    u = va_arg(args, unsigned int);
                }
                if (hash_flag && u != 0) {
                    *buffer++ = '0';
                    *buffer++ = 'x';
                }
                s21_uittoa(u, buf, 16);
                str = buf;
                break;
            case 'X':
                if (length_modifier == 'h') {
                    u = (unsigned short)va_arg(args, unsigned int);
                } else if (length_modifier == 'H') {
                    u = (unsigned char)va_arg(args, unsigned int);
                } else if (length_modifier == 'l') {
                    u = va_arg(args, unsigned long);
                } else {
                    u = va_arg(args, unsigned int);
                }
                if (hash_flag && u != 0) {
                    *buffer++ = '0';
                    *buffer++ = 'X';
                }
                s21_uittoa(u, buf, 16);
                for (char *p = buf; *p; p++) *p = toupper(*p);
                str = buf;
                break;
            case 'f':
                if (length_modifier == 'L') {
                    lf = va_arg(args, long double);
                    if (precision == -1) {
                        precision = 6;
                    }
                    s21_lftoa(lf, buf, precision);
                } else {
                    f = va_arg(args, double);
                    if (precision == -1) {
                        precision = 6;
                    }
                    s21_ftoa(f, buf, precision);
                }
                str = buf;
                break;
            case 's':
                str = va_arg(args, char *);
                if (precision >= 0) {
                    s21_strncpy(buf, str, precision);
                    buf[precision] = '\0';
                    str = buf;
                }
                break;
            case 'c':
                buf[0] = (char)va_arg(args, int);
                buf[1] = '\0';
                str = buf;
                break;
            case 'p':
                u = (unsigned long)va_arg(args, void *);
                s21_uittoa(u, buf, 16);
                str = buf;
                break;
            case 'n':
                int *n = va_arg(args, int *);
                *n = written;
                break;
            default:
                str = "";
                break;
        }

        int len = s21_strlen(str);
        int padding = (width > len) ? width - len : 0;

        if (!left_align) {
            while (padding-- > 0) {
                *buffer++ = zero_padding ? '0' : ' ';
            }
        }

        while (*str) {
            *buffer++ = *str++;
        }

        if (left_align) {
            while (padding-- > 0) {
                *buffer++ = ' ';
            }
        }
    }

    *buffer = '\0';
    va_end(args);
    return buffer - str_beginning;
}
