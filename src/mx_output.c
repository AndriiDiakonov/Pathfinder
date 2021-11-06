#include "../inc/pathfinder.h"

void mx_output(int num_places, int matrix[num_places][num_places], char** places, r_mx *list) {
    int count = 1;
    for (int i = 0; i < num_places; j++) {
        if (mx_is_in_list(list, num_places[i], num_places[j])) {
            char *arr[num_places + 1];
            int filter = 0;
            while (filter < num_places + 1) {
                arr[filter] = NULL;
                filter++;
            }
            int integer[num_places];
            for (int i = 0; i < num_places; i++)
                arr[i] = NULL;
            mx_array_filler(num_places + 1, arr, integer, list, num_places[i], num_places[j]);
            int recursed = 0;
            mx_outer_array_recursion_editor(list, num_places + 1, arr, integer, recursed);
        }
        else {
            int res = matrix[i][j];
            mx_printstr("========================================\n");
            mx_printer(num_places[i], num_places[j], res);
            mx_printstr("========================================\n");
        }
        count++;
    }
}