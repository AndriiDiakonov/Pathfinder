#include "../inc/pathfinder.h"

static void before_type(t_finder *path, int line);

void mx_line_next_validation(t_finder *path) {
    for (int line = 1; *path -> string != '\0'; path -> string++) {
        while (*path -> string != '-') {
            if (!mx_isalpha(*path -> string))
                mx_print_errline(line);
            path -> string++;
        }
        before_type(path, line);
        for ( ; *path -> string != '\n'; path -> string++)
            if (!mx_isdigit(*path -> string) || mx_atol(path -> string) > INT_MAX)
                mx_print_errline(line);
            line++;
    }
}

static void before_type(t_finder *path, int line) {
    if (*path -> string == '-' && !mx_isalpha(*(path -> string - 1)) && !mx_isalpha(*(path->string + 1)))
        mx_print_errline(line);
        path->string++;
    //for ( ; *path->string != ',' ; path->string++)
    while (*path -> string != ',') { 
        if (!mx_isalpha(*path -> string))
            mx_print_errline(line);
        path -> string++;
    }
    if (*path -> string == ',' && !mx_isalpha(*(path -> string-1))
        && !mx_isdigit(*(path -> string + 1)))
        mx_print_errline(line);
        path -> string++;
}
