#include "../inc/pathfinder.h"

void mx_array_recursion_editor(r_mx *list, int num_places, char *array[num_places], int arr_int[num_places], int pure_arr_int[num_places]) {
    int checker = 0;
    r_mx *copy = mx_copy_r_list(list);
    r_mx *tmp = copy;
    char *tmp_arr[num_places];
    for (int i = 0; i < num_places; ++i)
        tmp_arr[i] = array[i];

    for (int i = 0; tmp_arr[i+1] != NULL; ++i) {
        while (tmp) {
            if (mx_strcmp(tmp->s,tmp_arr[i]) == 0 && mx_strcmp(tmp -> e,tmp_arr[i+1]) == 0) {
                mx_array_extender(num_places, tmp_arr, tmp -> m, i + 1);
                mx_int_array_extender(num_places, pure_arr_int, tmp -> a, tmp -> b, i);
                tmp -> s = "NULL";
                tmp -> e = "NULL";
                checker = 1;
                break;
            }
            tmp = tmp -> next;
        }
        if (checker)
            break;
    }
    if (checker)
        mx_array_recursion_editor(copy, num_places, tmp_arr, arr_int, pure_arr_int);
    else
        mx_big_array_printer(num_places, tmp_arr,  pure_arr_int); 
}