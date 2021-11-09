#include "../inc/pathfinder.h"

void mx_print_output_distance(t_finder *path, t_output *run) {
    int sum = 0;
    mx_printstr("Distance: ");
    for (int i = 1; i < run->length; i++) {
        mx_printint(path->primary[run->route[i]][run->route[i + 1]]);
        sum += path->primary[run->route[i]][run->route[i + 1]];
        if (i < run->length - 1)
            mx_printstr(" + ");
        else if (i > 1) {
            mx_printstr(" = ");
            mx_printint(sum);

        }
    }
    mx_printstr("\n");
    mx_printstr("========================================\n");
}
