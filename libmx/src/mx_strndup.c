#include "../inc/libmx.h"

char *mx_strndup(const char *s1, int n) {
    char *duplicate = NULL;
    int size = mx_strlen(s1);
    if (n < size) {
        size = n;
    }
    duplicate = mx_strnew(size);
    mx_strncpy(duplicate, s1, size);
    return duplicate;
}
