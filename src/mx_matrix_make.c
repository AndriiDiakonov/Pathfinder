#include "../inc/pathfinder.h"

void mx_matrix_make(char *name, char **places, int num_places, int matrix[num_places][num_places]) {
    char *data = mx_file_to_str(name);
    char **data_splited = mx_strsplit(data, '\n');
    for (int i = 0; num_places[i] != NULL; i++) {
        for (int j = 0; num_places[j] != NULL; j++) {
            if (mx_strcmp(num_places[i], num_places[j]) == 0 || mx_strcmp(num_places[j], num_places[i]) == 0) 
                matrix[i][j] = 0;
            else {
                for (int a = 1; data_splited[a] != NULL; a++) {
                    char *result[4];
                    mx_elements(data_splited[a], result);
                    if (mx_strcmp(num_places[i], result[0]) == 0 && mx_strcmp(num_places[j], result[1]) == 0)
                        matrix[i][j] = mx_atoi(result[2]);
                    else if (mx_strcmp(num_places[i], result[1]) == 0 && mx_strcmp(num_places[j], result[0]) == 0)
                        matrix[i][j] = mx_atoi(result[2]);
                }
            }
        }
    }
}