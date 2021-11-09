#include "../inc/pathfinder.h"

void mx_invalid_islands(t_finder *path) {
    char *buffer = mx_strdup(path -> string);
    path -> num_islands = mx_atoi(buffer);
    if (path -> num_islands < 2)
        mx_print_err_islands();
    for (int i = 0; buffer[i] != '\0'; i++)
        buffer[i] == ',' || buffer[i] == '\n' ? (buffer[i] = '-') : buffer[i];
    path -> words = mx_count_words(buffer,'-');
    path -> islands = mx_strsplit(buffer,'-');
    mx_count_islands(path);
    mx_duplicate_islands(path);
    mx_duplicate_bridges(path);
    mx_sum_bridges(path);
    free(buffer);
    free(path -> string);
}
