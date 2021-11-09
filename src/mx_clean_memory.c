#include "../inc/pathfinder.h"

static void del_int_arr(int **arr, t_finder *path) {
    if (arr) {
        for (int i = 0; i < path -> num_islands; i++)
            free(arr[i]);
        free(arr);
    }
}

void mx_clean_memory(t_finder *path) {
    mx_del_strarr(&path -> unique_isl);
    del_int_arr(path -> array, path);
    del_int_arr(path -> primary, path);
    free(path);
}
