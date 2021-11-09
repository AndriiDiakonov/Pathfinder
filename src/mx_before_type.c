#include "../inc/pathfinder.h"

void mx_before_type(t_finder *path, int line) {
    if (*path -> string == '-' && !mx_isalpha(*(path -> string - 1)) && !mx_isalpha(*(path->string + 1)))
        mx_print_errline(line);
    path -> string++;
    while (*path -> string != ',') { 
        if (!mx_isalpha(*path -> string))
            mx_print_errline(line);
        path -> string++;
    }
    if (*path -> string == ',' && !mx_isalpha(*(path -> string-1)) && !mx_isdigit(*(path -> string + 1)))
        mx_print_errline(line);
    path -> string++;
}
