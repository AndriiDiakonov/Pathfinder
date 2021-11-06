#include "../inc/libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    if (s1 == NULL || s2 == NULL) {
        if (s1 == NULL && s2 == NULL)
            return NULL;
        else if (s1 == NULL) {
            return mx_strdup(s2);
        }
        else
            return mx_strdup(s1);
    }
    int len = mx_strlen(s1) + mx_strlen(s2);
    char *result = mx_strnew(len);
    int i, j;
    for (i = 0; i < mx_strlen(s1); i++) 
        result[i] = s1[i];
    for (j = i; j < len; j++) {
        result[j] = *s2;
        s2++;
    }
    return result;
}
