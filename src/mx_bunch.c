#include "../inc/pathfinder.h"

int mx_bunch(const char *file) {
    char *data = mx_file_to_str(file);
    if (data[mx_strlen(data) - 1] != '\n') {
        char *temp_data = mx_strnew(mx_strlen(data) + 1);
        int i = 0;
        while (data[i]) {
            temp_data[i] = data[i];
            i++;
        }
        temp_data[i] = '\n';
        char **lines = mx_strsplit(temp_data, '\n');
        int j = 0;
        while (lines[j])
            j++;
        return -j + 1;
    }
    return 0;
}
