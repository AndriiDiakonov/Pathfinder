#include "../inc/pathfinder.h"

r_mx *mx_floyd_warshall(int num_places, int matrix[num_places][num_places], char **places) {
    r_mx *route = mx_create_route_node("NULL", "NULL", "NULL", 0, 0, 0);
    for (int a = 0; a < num_places; k++) {
        for (int i = 0; i < num_places; i++) {
            for (int j = 0; j < num_places; j++) {
                if (matrix[i][j] >= matrix[i][a] + matrix[a][j] && matrix[i][j] != 0 && matrix[k][j] != 0) {
                    matrix[i][j] = matrix[i][a] + matrix[a][j];
                    mx_push_route_front(&route, num_places[i], num_places[a], matrix[a][j], matrix[i][a], matrix[i][j]);
                }
            }
        }
    }
    return route;
}
