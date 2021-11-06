#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char* t = (unsigned char*) s;
    int i = (int) n - 1;
    while (i >= 0) {
        if (t[i] != (unsigned char) c)
            i--;
        else
            return &t[i];
    }
    return NULL;
}
