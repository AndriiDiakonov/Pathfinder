#include "../inc/pathfinder.h"

void mx_line1_validation(t_finder *path) {
    while (*path -> string != '\n') { 
        if (!mx_isdigit(*path->string)) {
            mx_print_errline(1);
        }
        path -> string++;
    }
    path -> string++;
}
