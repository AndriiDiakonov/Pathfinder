#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    int i = 0;
    int idif = 0;
    int line = 0;

    if (!str)
        return -1;
    while (str[i] == c)
        i++;
    if (str[i])
        line++;
    while (str[i]) {
        if (str[i] == c)
            idif++;
        else
            if (idif > 0) {
                idif = 0;
                line++;
            }   
        i++;
    }
    return line;
}
