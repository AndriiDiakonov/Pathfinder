#include "../inc/libmx.h"

bool mx_isupper(int c) {
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *letter = alphabet;

    while(*letter != '\0' && *letter != c)
        ++letter;
    if (*letter)
        return true;
    return false;
}
