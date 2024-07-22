#include "s21_string.h"

void processFlags(const char **format, int *flags) {
  while (**format == '-' || **format == '+' || **format == ' ' ||
         **format == '0') {
    if (**format == '-') {
      *flags |= 1;
    } else if (**format == '+') {
      *flags |= 2;
    } else if (**format == ' ') {
      *flags |= 4;
    } else if (**format == '0') {
      *flags |= 8;
    }
    (*format)++;
  }
}

void processWidth(const char **format, int *width) {
  while (**format >= '0' && **format <= '9') {
    *width = *width * 10 + (**format - '0');
    (*format)++;
  }
}

void processPrecision(const char **format, int *precision) {
  if (**format == '.') {
    (*format)++;
    *precision = 0;
    while (**format >= '0' && **format <= '9') {
      *precision = *precision * 10 + (**format - '0');
      (*format)++;
    }
  }
}

void processLengthModifier(const char **format, char *lengthModifier) {
  if (**format == 'h' || **format == 'l') {
    *lengthModifier = **format;
    (*format)++;
  }
}

void processSpecifier(const char **format, va_list args, char **ptr,
                      int *length, int width, int precision,
                      char lengthModifier) {
  switch (**format) {
    case 'd': {
      long value = va_arg(args, long);
      if (lengthModifier == 'h') {
        value = (short)value;
      }
      int written = snprintf(*ptr, MAX_BUFFER_SIZE - (*ptr - *ptr), "%*.*ld",
                             width, precision, value);
      *ptr += written;
      *length += written;
      break;
    }
    case 'c': {
      int value = va_arg(args, int);
      **ptr = (char)value;
      (*ptr)++;
      (*length)++;
      break;
    }
    case 's': {
      char *value = va_arg(args, char *);
      int i = 0;
      while (value[i] != '\0' && (precision == -1 || i < precision)) {
        **ptr = value[i];
        (*ptr)++;
        i++;
      }
      *length += i;
      break;
    }
    case 'u': {
      unsigned long value = va_arg(args, unsigned long);
      if (lengthModifier == 'h') {
        value = (unsigned short)value;
      }
      int written = snprintf(*ptr, MAX_BUFFER_SIZE - (*ptr - *ptr), "%*.*lu",
                             width, precision, value);
      *ptr += written;
      *length += written;
      break;
    }
    case 'f': {
      double value = va_arg(args, double);
      int written = snprintf(*ptr, MAX_BUFFER_SIZE - (*ptr - *ptr), "%*.*f",
                             width, precision, value);
      *ptr += written;
      *length += written;
      break;
    }
    case '%': {
      **ptr = '%';
      (*ptr)++;
      (*length)++;
      break;
    }
    default:
      **ptr = '%';
      (*ptr)++;
      **ptr = **format;
      (*ptr)++;
      *length += 2;
      break;
  }
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);

  char *buffer = malloc(MAX_BUFFER_SIZE);
  int length = 0;
  if (buffer != NULL) {
    char *ptr = buffer;

    while (*format) {
      if (*format == '%') {
        format++;

        int flags = 0;
        processFlags(&format, &flags);

        int width = 0;
        processWidth(&format, &width);

        int precision = -1;
        processPrecision(&format, &precision);

        char lengthModifier = '0';
        processLengthModifier(&format, &lengthModifier);

        processSpecifier(&format, args, &ptr, &length, width, precision,
                         lengthModifier);
      } else {
        *ptr = *format;
        ptr++;
        length++;
      }
      format++;
    }

    *ptr = '\0';

    for (int i = 0; buffer[i] != '\0'; i++) {
      str[i] = buffer[i];
    }
    str[length] = '\0';

    free(buffer);
  }
  va_end(args);
  return length;
}