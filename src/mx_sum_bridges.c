#include "../inc/pathfinder.h"

void mx_sum_bridges(t_finder *path) {
    long sum = 0;

    for (int i = 1; i < path -> words; i++) {
        if (mx_isdigit(path -> islands[i][0]))
            sum += mx_atoi(path -> islands[i]);
        if (sum > INT_MAX) {
            mx_printerr("error: sum of bridges lengths is too big\n");
            exit(1);
        }
    }
}
