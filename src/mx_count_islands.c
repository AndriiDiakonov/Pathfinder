#include "../inc/pathfinder.h"

void mx_count_islands(t_finder *path) {
    int counter = 1;

    path -> unique_isl = (char **)malloc(sizeof(char *) * path -> words);
    path -> unique_isl[0] = mx_strdup(path -> islands[1]);
    for (int i = 1; i < path -> words; i++) {
        if (mx_isdigit(path -> islands[i][0]))
            continue;
        for (int j = 0; j < counter; j++) {
            if (!mx_strcmp(path -> unique_isl[j], path -> islands[i]))
                break;
            if (j == counter - 1)
                path -> unique_isl[counter++] = mx_strdup(path -> islands[i]);
        }
    }
    if (counter != path -> num_islands)
        mx_print_err_islands();
}
