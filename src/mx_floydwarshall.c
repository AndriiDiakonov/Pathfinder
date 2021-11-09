#include "../inc/pathfinder.h"

void mx_floydwarshall(t_finder *path) {
    int sum;
    int i;

    for (i = 0; i < path->num_islands; i++) {
        for (int j = i; j < path->num_islands; j++) {
            path->primary[i][j] = path->array[i][j];
            path->primary[j][i] = path->array[j][i];
        }
    }
    for (int k = 0; k < path->num_islands; k++) {
        for (i = 0; i < path->num_islands; i++) {
            for (int j = i + 1; j < path->num_islands; j++) {
                sum = path->array[i][k] + path->array[k][j];
                path->array[k][j] != INT_MAX && path->array[i][k] != INT_MAX
                && sum < path->array[i][j]
                ? path->array[i][j] = sum, path->array[j][i] = sum : i;
            }
        }
    }
}
