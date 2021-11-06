#include "../inc/pathfinder.h"

//  checking number of specified arguments
const int mx_error_0(int argc) {
    if (argc != 2)
        return -1;
    else
        return 1;
}

//  checks, whether file exists 
const int mx_error_1(char const *argv[]) {
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        close(fd);
        return fd;
    }
    close(fd);
    return 1;
}

//  file is empty
const int mx_error_2(char const *argv[]) {
    char buffer[1];
    int fd = open(argv[1], O_RDONLY);
    int len = 0;
    while (read(fd, buffer, 1))
        len++;
    close(fd);
    if (len == 0)
        return -1;
    return 0;
}

//  Checks, whether first string contains in valid chars

const int mx_error_3(char const *argv[]) {
    char buffer[1];
    int fd = open(argv[1], O_RDONLY);
    int len = 0;
    while (read(fd, buffer, 1)) {
        if(buffer[0] == "\n")
            break;
        else if (mx_isdigit(buffer[0]) == -1)
            return -1;
        len++;
    }
    close(fd);
    if (len == 0)
        return -1;
    return 0;
}

const int mx_error_4(char const *argv[]) {
    int bunch = mx_bunch(argv[1]);
    if (bunch < 0)
        return bunch;
    char *data = mx_file_to_str(argv[1]);
    char **line = mx_strsplit(data, '\n');
    int i = 0;
    while (line[i]) {
        int d = 0;
        int com = 0;
        for (int j = 0; j < mx_strlen(line[i]); j++) {
            if (com == 0 && line[i][j] != '-' && line[i][j] != ',') {
                if (mx_isalpha(line[i][j] == -1))
                    return -i;
            }
            else if (com == 1 && line[i][j] != '-' && line [i][j] != ',') {
                if (mx_isdigit(line[i][j]) == -1)
                    return -i;
            }
            if (line[i][j] == '-')
                d++;
            else if (line[i][j] == ',')
                com++;
        }
        if (d != 1 || com != 1)
            return -i;
        i++;
    }
    return 0;
}

/*
 * This error case checks, wheather number of islands, 
 * specified in 1st. line, is valid.
 */
int mx_error_5(char const *argv[]) {
    char *file_data = mx_file_to_str(argv[1]);
    char *input_data = mx_first_line_reader(file_data); 
    int i = 0;
    while (file_data[i]) {
        if (file_data[i] == ',' || file_data[i] == '\n' ||  mx_isdigit(file_data[i]) != -1)
            file_data[i] = '-';
        i++;
    }
    char **cities = mx_strsplit(file_data, '-');
    t_list *node = mx_create_node(cities[0]);
    for (int j = 1; cities[j] != NULL; ++j) {
        if (mx_list_value_validator(&node, cities[j]) != -1)
            mx_push_front(&node, cities[j]);
    }
    int number_of_cities = mx_list_size(node);
    if (mx_strcmp(input_data, mx_itoa(number_of_cities)) != 0)
        return -1;
    return 0;
}


int mx_error(int argc, char const argv[]) {
    if (mx_error_0(argc) == -1) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(1);
    }
    else if (mx_error_1(argv) == -1) {
        mx_printerr("error: file");
        mx_printerr((char *)argv[1]);
        mx_printerr(" doesn`t exits\n");
        exit(1);
    }
    else if (mx_error_2(argv) == -1) {
        mx_printerr("error: file");
        mx_printerr((char *)argv[1]);
        mx_printerr(" is empty\n");
        exit(1);
    }
    else if (mx_error_3(argv) == -1) {
        mx_printerr("error: line 1 isn`t valid\n");
        exit(1);
    }
    else if (mx_error_4(argv) < 0) {
        mx_printerr("error: line");
        mx_printerr(mx_itoa((mx_error_4(argv) * (-1)) + 1));
        mx_printerr(" isn`t valid\n");
        exit(1);
    }
    else if (mx_error_5(argv) == -1) {
        mx_printerr("error: invalid number of islands\n");
        exit(1);
    }
    return 1;
}
