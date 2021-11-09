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

void mx_output(t_finder *path);
void mx_matrix(t_finder *path);
void mx_clean_memory(t_finder *path);
void mx_print_err_islands();
void mx_floyd_warshall(t_finder *path);
void mx_count_islands(t_finder *path);
void mx_duplicate_islands(t_finder *path);
void mx_sum_bridges(t_finder *path);
void mx_duplicate_bridges(t_finder *path);
void mx_invalid_islands(t_finder *path);
void mx_line_next_validation(t_finder *path);
void mx_print_errline(int line);
void mx_error_empty_file(char *argv[], t_finder *path);
void mx_line_one_validation(t_finder *path);
void mx_error(int argc, char *argv[], t_finder *path);
void mx_invalid_argc_or_file(int argc, char *argv[], t_finder *path);

#endif
