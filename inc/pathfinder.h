#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"

typedef struct s_finder {
    int num_islands;
    int words;
    char *string;
    char **islands;
    char **unique_isl;
    int **array;
    int **primary;
}              t_finder;

typedef struct s_output {
    int length;
    int *route;
}              t_output;

    //  Input error 
void mx_line_next_validation(t_finder *path);
void mx_line_one_validation(t_finder *path);
void mx_error(int argc, char *argv[], t_finder *path);

    //  Floyd–Warshall algorithm
void mx_floyd_warshall(t_finder *path);

    //   Creating matrix (Cities)
void mx_matrix(t_finder *path);
void mx_del_int_arr(int **arr, t_finder *path);
void mx_clean_memory(t_finder *path);
void mx_count_islands(t_finder *path);
void mx_duplicate_islands(t_finder *path);
void mx_invalid_islands(t_finder *path);
void mx_before_type(t_finder *path, int line);
int mx_numb_of_islands(t_finder *path, char *island);
void mx_shortest_route(t_finder *path, t_output *run);

    //  Output the result 
void mx_output(t_finder *path);
void mx_print_err_islands();
void mx_sum_bridges(t_finder *path);
void mx_print_errline(int line);
void mx_duplicate_bridges(t_finder *path);
void mx_error_empty_file(char *argv[], t_finder *path);
void mx_print_output_route(t_finder *path, t_output *run);
void mx_print_output_distance(t_finder *path, t_output *run);
void mx_invalid_argc_or_file(int argc, char *argv[], t_finder *path);

#endif
