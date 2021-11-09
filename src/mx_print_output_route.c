#include "../inc/pathfinder.h"

void mx_print_output_route(t_finder *path, t_output *run) {
    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(path -> unique_isl[run -> route[1]]);
    mx_printstr(" -> ");
    mx_printstr(path -> unique_isl[run -> route[0]]);
    mx_printstr("\n");
    mx_printstr("Route: ");
        for (int i = 1; i < run -> length + 1;) {
            mx_printstr(path -> unique_isl[run -> route[i]]);
            if (++i < run -> length + 1)
                mx_printstr(" -> ");
        }
    mx_printstr("\n");
}
