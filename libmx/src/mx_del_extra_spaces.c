#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (!str) return NULL;
    char *temp = mx_strnew(mx_strlen(str));
    char *result = NULL;
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!mx_isspace(str[i]) || (i > 0 && !mx_isspace(str[i-1]))) {
            temp[j++] = str[i];
        }
        temp[j] = '\0';
    }
    result = mx_strtrim(temp);
    mx_strdel(&temp);
    return result;
}
