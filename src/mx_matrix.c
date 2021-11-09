#include "../inc/pathfinder.h"

void mx_matrix(t_finder *path) {
    int i;
    int j;
    path -> array = (int **)malloc(sizeof(int *) * path -> num_islands);
    path -> primary = (int **)malloc(sizeof(int *) * path -> num_islands);
    for (i = 0; i < path -> num_islands; i++) {
        path -> array[i] = (int *)malloc(sizeof(int *) * path -> num_islands);
        path -> primary[i] = (int *)malloc(sizeof(int *) * path -> num_islands);
        for (j = 0; j < path -> num_islands; j++) {
            path -> array[i][j] = i != j ? INT_MAX : 0;
        }
    }
    for (int index = 1; index < path -> words ; index += 3) {
        i = mx_numb_of_islands(path, path -> islands[index]);
        j = mx_numb_of_islands(path, path -> islands[index + 1]);
        path -> array[i][j] = mx_atoi(path -> islands[index + 2]);
        path -> array[j][i] = mx_atoi(path -> islands[index + 2]);
    }
    mx_del_strarr(&path -> islands);
}
