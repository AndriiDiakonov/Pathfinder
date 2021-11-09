#include "../inc/pathfinder.h"

void mx_shortest_route(t_finder *path, t_output *run) {
    int i = run -> route[run -> length];
    int j = run -> route[0];

    for (int k = 0; k < path -> num_islands; k++) {
        if (k != run -> route[run -> length]
        && (path -> primary[i][k] == path -> array[i][j] - path -> array[k][j])) {
        run -> length++;
        run -> route[run -> length] = k;
        mx_shortest_route(path, run);
        run -> length--;
        }
    }
    if (run -> route[run -> length] != run -> route[0])
        return;
    mx_print_output_route(path, run);
    mx_print_output_distance(path, run);
}
