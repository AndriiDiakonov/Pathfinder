#include "../inc/pathfinder.h"

void mx_clean_memory(t_finder *path) {
    mx_del_strarr(&path -> unique_isl);
    mx_del_int_arr(path -> array, path);
    mx_del_int_arr(path -> primary, path);
    free(path);
}
