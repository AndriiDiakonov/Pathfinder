#include "../inc/libmx.h"

int mx_atoi(const char *s) {
    int i = -1;
    int result = 0;
    while (s[++i]) {
        if (mx_isdigit(s[i]))
            result = result * 10 + s[i] - '0';
        if (!mx_isdigit(s[i]))
            return result;
    }
    return result;
}
