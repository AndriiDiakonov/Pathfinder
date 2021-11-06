#include "../inc/pathfinder.h"

void mx_big_array_printer(int num_places, char *array[num_places],  int integer[num_places]) {
    char *arrow = "  -> ";
    char *begin = array[0];
    int end = 0;

    mx_array_garbager(num_places, integer);
    mx_printstr("========================================\n");
    mx_printstr(begin);
    mx_printstr(arrow);
    while (array[end] != NULL)
        end++;
    mx_printchar('\n');

    mx_printstr("Route: ");
    for (int i = 0; array[i] != 0; i++) {
        mx_printstr(array[i]);
        if (array[i + 1] != 0)
            mx_printstr(arrow);
    }
    mx_printchar('\n');

    mx_printstr("Distance: ");
    for (int i = 0; integer[i] != 0; i++) {
        char *p = mx_itoa(integer[i]);
        mx_printstr(p);
        if (integer[i + 2] == 0) {
            mx_printstr(" = ");
            char *p_tenp = mx_itoa(integer[i + 1]);
            mx_printstr(p_tenp);
            break;
        }
        else
            mx_printstr(" + ");
    }
    mx_printchar('\n');
    mx_printstr("========================================\n");
}
