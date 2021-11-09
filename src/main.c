#include "../inc/pathfinder.h"

int main(int argc, char *argv[]) {
    t_finder *path = (t_finder *)malloc(sizeof(t_finder));

    mx_all_errors(argc, argv, path);
    mx_matrix(path);
    mx_floydwarshall(path);
    mx_output(path);
    return 0;
}
