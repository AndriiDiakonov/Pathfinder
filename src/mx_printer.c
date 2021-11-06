#include "../inc/pathfinder.h"

void mx_printer(char *a, char *b, int result) {
    char *arrow = " -> ";

    mx_printstr("Path: ");
    mx_printstr(a);
    mx_printstr(arrow);
    mx_printstr(b);
    mx_printchar('\n');

    mx_printstr("Route: ");
    mx_printstr(a);
    mx_printstr(arrow);
    mx_printstr(b);
    mx_printchar('\n');

    char *r = mx_itoa(result);
    mx_printstr("Distance: ");
    mx_printstr(a);
    mx_printchar('\n');
}
