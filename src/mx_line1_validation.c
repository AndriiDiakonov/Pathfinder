#include "../inc/pathfinder.h"

void mx_line1_validation(t_finder *path) {
    for (; *path->string != '\n'; path-> string++) {
        if (!mx_isdigit(*path->string)) {
            mx_print_errline(1);
        }
    }
    path -> string++;
}
