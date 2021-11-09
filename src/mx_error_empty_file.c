#include "../inc/pathfinder.h"

void mx_error_empty_file(char *argv[], t_finder *path) {
    int fd;
    char *buf = mx_strnew(1);
    int reading;

    fd = open(argv[1], O_RDONLY);
    reading = read(fd, buf, 1);
    if (reading < 1) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        free(path);
        exit(1);
        close(fd);
    }
    mx_strdel(&buf);
    path->string = mx_file_to_str(argv[1]);
}
