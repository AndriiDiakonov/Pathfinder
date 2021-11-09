#include "../inc/pathfinder.h"

static void shortest_route(t_finder *path, t_output *run);
static void print_output_route(t_finder *path, t_output *run);
static void print_output_distance(t_finder *path, t_output *run);

void mx_output(t_finder *path) {
    t_output *run = (t_output *)malloc(sizeof(t_output));

    run -> route = (int *)malloc(sizeof(int) * (path -> num_islands + 1));
    for (int i = 0; i < path ->  num_islands; i++) {
        for (int j = i + 1; j < path -> num_islands; j++) {
            run -> length = 1;
            run -> route[0] = j;
            run -> route[1] = i;
            shortest_route(path, run);
        }
    }
    free(run -> route);
    free(run);
    mx_clean_memory(path);
}

static void shortest_route(t_finder *path, t_output *run) {
    int i = run -> route[run -> length];
    int j = run -> route[0];

    for (int k = 0; k < path -> num_islands; k++) {
        if (k != run -> route[run -> length]
        && (path -> primary[i][k] == path -> array[i][j] - path -> array[k][j])) {
        run -> length++;
        run -> route[run -> length] = k;
        shortest_route(path, run);
        run -> length--;
        }
    }
    if (run -> route[run -> length] != run -> route[0])
        return;
    print_output_route(path, run);
    print_output_distance(path, run);
}

static void print_output_route(t_finder *path, t_output *run) {
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

static void print_output_distance(t_finder *path, t_output *run) {
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
