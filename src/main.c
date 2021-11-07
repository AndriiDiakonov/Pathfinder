#include "../inc/pathfinder.h"

int main(int argc, char *argv[]) {
    mx_error(argc, argv);
    int num_places = mx_unic((char *)argv[1]);
    char *unique_cities[num_places + 1];
    mx_unic_array((char *)argv[1], unique_cities);
    int matrix[num_places][num_places];
    for (int i = 0; i < num_places; ++i) {
        for (int j = 0; j < num_places ; ++j)
            matrix[i][j] = TWO_BI;
    }
    mx_matrix_make((char *)argv[1], unique_cities, num_places, matrix);
    
    r_mx *route_list = mx_floyd_warshall(num_places, matrix, unique_cities);

    r_mx *new_route_list =  mx_create_route_node("NULL","NULL","NULL",0,0,0);
    mx_sort_route_list(route_list, new_route_list, unique_cities, num_places);
    mx_sort_route_list2(new_route_list);


    mx_output(num_places, matrix, unique_cities, new_route_list);
}
