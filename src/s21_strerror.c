#include <stdio.h>
#include <string.h>
#include <errno.h>

char *s21_strerror(int errnum) {
    static char errorMessages[256][50] = {
        "Success",
        "Operation not permitted",
        "No such file or directory",
    };
    
    if (errnum >= 0 && errnum < 256) {
        return errorMessages[errnum];
    } else {
        return "Unknown error";
    }
}