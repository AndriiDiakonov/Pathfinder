#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    unsigned char *srcn = (unsigned char *)src;
    unsigned char *dstn = (unsigned char *)dst;
    size_t i = 0;
   
    while (i < n) {
        dstn[i] = srcn[i];
        if (srcn[i] == c) {
            return dstn + (i + 1);
        }
        i++;
    }
    return NULL;
}
