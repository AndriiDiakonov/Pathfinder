#include "../inc/libmx.h"

char *mx_first_line_reader(char *str) {
    int i = 0;
    int j = 0;
    while (str[i] != '\n')
        i++;
    char *result = mx_strnew(i);
    while(j < i) {
        result[j] = str[j];
        j++;
    }
    return result;
}
