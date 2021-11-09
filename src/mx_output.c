#include "../inc/pathfinder.h"

void mx_output(t_finder *path) {
    t_output *run = (t_output *)malloc(sizeof(t_output));
    run -> route = (int *)malloc(sizeof(int) * (path -> num_islands + 1));
    for (int i = 0; i < path ->  num_islands; i++) {
        for (int j = i + 1; j < path -> num_islands; j++) {
            run -> length = 1;
            run -> route[0] = j;
            run -> route[1] = i;
            mx_shortest_route(path, run);
        }
    }
    free(run -> route);
    free(run);
    mx_clean_memory(path);
}
