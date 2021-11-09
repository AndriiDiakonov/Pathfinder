#pragma once

#include "../libmx/inc/libmx.h"

#define INT_MAX 2147483647

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
void mx_print_err_isl();
void mx_floydwarshall(t_finder *path);
void mx_invalid_islands(t_finder *path);
void mx_line_next_validation(t_finder *path);
void mx_print_errline(int line);
void mx_error_empty_file(char *argv[], t_finder *path);
void mx_line1_validation(t_finder *path);
void mx_all_errors(int argc, char *argv[], t_finder *path);
void mx_invalid_argc_or_file(int argc, char *argv[], t_finder *path);
