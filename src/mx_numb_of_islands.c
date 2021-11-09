#include "../inc/pathfinder.h"

int mx_numb_of_islands(t_finder *path, char *island) {
    for (int i = 0; i < path -> num_islands; i++) {
        if (mx_strcmp(island, path -> unique_isl[i]) == 0)
            return i;
    }
    return 0;
}
