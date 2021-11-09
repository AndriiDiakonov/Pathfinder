#include "../inc/pathfinder.h"

void mx_invalid_argc_or_file(int argc, char *argv[], t_finder *path) {
    int fd;

    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        free(path);
        exit(1);
    }
    close(fd);
}
