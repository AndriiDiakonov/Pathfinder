#include "../inc/pathfinder.h"

void mx_duplicate_islands(t_finder *path) {
    int line = 2;
    for (int i = 1; i < path -> words; i += 3) {
        if (!mx_strcmp(path -> islands[i + 1], path -> islands[i])) {
            mx_print_errline(line);
        }
        line++;
    }
}
