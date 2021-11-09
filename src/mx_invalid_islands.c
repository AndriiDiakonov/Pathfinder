#include "../inc/pathfinder.h"

static void count_islands(t_finder *path);
static void duplicate_islands(t_finder *path);
static void sum_bridges(t_finder *path);
static void duplicate_bridges(t_finder *path);

void mx_invalid_islands(t_finder *path) {
    char *buffer = mx_strdup(path->string);

    path->num_islands = mx_atoi(buffer);
    if (path->num_islands < 2)
        mx_print_err_isl();
    for (int i = 0; buffer[i] != '\0'; i++)
        buffer[i] == ',' || buffer[i] == '\n' ? (buffer[i] = '-') : buffer[i];
    path->words = mx_count_words(buffer,'-');
    path->islands = mx_strsplit(buffer,'-');
    count_islands(path);
    duplicate_islands(path);
    duplicate_bridges(path);
    sum_bridges(path);
    free(buffer);
    free(path->string);
}

static void count_islands(t_finder *path) {
    int counter = 1;

    path->unique_isl = (char **)malloc(sizeof(char *) * path->words);
    path->unique_isl[0] = mx_strdup(path->islands[1]);
    for (int i = 1; i < path->words; i++) {
        if (mx_isdigit(path->islands[i][0]))
            continue;
        for (int j = 0; j < counter; j++) {
            if (!mx_strcmp(path->unique_isl[j], path->islands[i]))
                break;
            if (j == counter - 1)
                path->unique_isl[counter++] = mx_strdup(path->islands[i]);
        }
    }
    if (counter != path->num_islands)
        mx_print_err_isl();
}

static void duplicate_islands(t_finder *path) {
    int line = 2;

    for (int i = 1; i < path->words; i +=3) {
        if(!mx_strcmp(path->islands[i + 1], path->islands[i])) {
            mx_print_errline(line);
        }
        line++;
    }
}

static void duplicate_bridges(t_finder *path) {
    for (int i = 1; i < path->words; i +=3) {
        for (int j = i + 3; j < path->words; j+=3) {
            if (!mx_strcmp(path->islands[i], path->islands[j])
                ||!mx_strcmp(path->islands[i], path->islands[j + 1])) {
                if (!mx_strcmp(path->islands[i + 1], path->islands[j])
                    || !mx_strcmp(path->islands[i + 1], path->islands[j])) {
                mx_printerr("error: duplicate bridges\n");
                exit(1);
                }
            }
        }
    }
}

static void sum_bridges(t_finder *path) {
    long sum = 0;

    for (int i = 1; i < path->words; i++) {
        if (mx_isdigit(path->islands[i][0]))
            sum += mx_atoi(path->islands[i]);
        if (sum > INT_MAX) {
            mx_printerr("error: sum of bridges lengths is too big\n");
            exit(1);
        }
    }
}
