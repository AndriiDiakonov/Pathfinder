#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    for (int i = 0; i < len; i++)
        dst[i] = src[i];
    if (mx_strlen(src) < len) {
        for (int i = mx_strlen(src); i < len; i++) {
            dst[i] = '\0';
        }
    }
    return dst;
}
