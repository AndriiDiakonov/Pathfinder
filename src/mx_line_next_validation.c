#include "../inc/pathfinder.h"

void mx_line_next_validation(t_finder *path) {
    for (int line = 1; *path -> string != '\0'; path -> string++) {
        while (*path -> string != '-') {
            if (!mx_isalpha(*path -> string))
                mx_print_errline(line);
            path -> string++;
        }
        mx_before_type(path, line);
        while(*path -> string != '\n') {
            if (!mx_isdigit(*path -> string) || mx_atol(path -> string) > INT_MAX)
                mx_print_errline(line);
            path -> string++;
        }
        line++;
    }
}
