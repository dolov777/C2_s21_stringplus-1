#include "s21_string.h"

char *s21_sprintf(char *str, const char *format, ...) {
    va_list args;
    va_start(args, format);

    char *buffer = malloc(MAX_BUFFER_SIZE);
    if (buffer != NULL) {
        char *ptr = buffer;
        while (*format) {
            if (*format == '%') {
                format++;

                int flags = 0;
                while (*format == '-' || *format == '+' ||
                    *format == ' ' || *format == '0') {
                    if (*format == '-') {
                        flags |= 1;
                    } else if (*format == '+') {
                        flags |= 2;
                    } else if (*format == ' ') {
                        flags |= 4;
                    } else if (*format == '0') {
                        flags |= 8;
                    }
                    format++;
                }

                int width = 0;
                if (*format >= '0' && *format <= '9') {
                    while (*format >= '0' && *format <= '9') {
                        width = width * 10 + (*format - '0');
                        format++;
                    }
                }

                int precision = -1;
                if (*format == '.') {
                    format++;
                    if (*format >= '0' && *format <= '9') {
                        precision = 0;
                        while (*format >= '0' && *format <= '9') {
                            precision = precision * 10 + (*format - '0');
                            format++;
                        }
                    }
                }

                char lengthModifier = '0';
                if (*format == 'h' || *format == 'l') {
                    lengthModifier = *format;
                    format++;
                }

                switch (*format) {
                    case 'd': {
                        long value = va_arg(args, long);
                        if (lengthModifier == 'h') {
                            value = (short)value;
                        }
                        ptr += snprintf(ptr, MAX_BUFFER_SIZE - (ptr - buffer), "%*.*ld", width, precision, value);
                        break;
                    }
                    case 'c': {
                        int value = va_arg(args, int);
                        *ptr++ = (char)value;
                        break;
                    }
                    case 's': {
                        char *value = va_arg(args, char *);
                        int i = 0;
                        while (value[i] != '\0' && (precision == -1 || i < precision)) {
                            *ptr++ = value[i];
                            i++;
                        }
                        break;
                    }
                    case 'u': {
                        unsigned long value = va_arg(args, unsigned long);
                        if (lengthModifier == 'h') {
                            value = (unsigned short)value;
                        }
                        ptr += snprintf(ptr, MAX_BUFFER_SIZE - (ptr - buffer), "%*.*lu", width, precision, value);
                        break;
                    }
                    case 'f': {
                        double value = va_arg(args, double);
                        ptr += snprintf(ptr, MAX_BUFFER_SIZE - (ptr - buffer), "%*.*f", width, precision, value);
                        break;
                    }
                    case '%': {
                        *ptr++ = '%';
                        break;
                    }
                    default:
                        *ptr++ = '%';
                        *ptr++ = *format;
                        break;
                }
            } else {
                *ptr++ = *format;
            }
            format++;
        }
        *ptr = '\0';

        int i = 0;
        while (buffer[i] != '\0') {
            str[i] = buffer[i];
            i++;
        }
        str[i] = '\0';

        free(buffer);
    }
    va_end(args);
    return str;
}