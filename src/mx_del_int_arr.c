#include "../inc/pathfinder.h"

void mx_del_int_arr(int **arr, t_finder *path) {
    if (arr) {
        for (int i = 0; i < path -> num_islands; i++)
            free(arr[i]);
        free(arr);
    }
}
