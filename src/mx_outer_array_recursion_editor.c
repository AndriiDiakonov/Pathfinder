#include "../inc/pathfinder.h"

void mx_outer_array_recursion_editor(r_mx *list, int num_places, char *array[num_places], int arr_int[num_places], int recursed) {
    int checker = 0;
    char *tmp[num_places];
    char *tmp_integer[num_places];
    r_mx *copy = mx_copy_list(list);
    
    for (int i = 0; i < num_places; i++)
        tmp[i] = array[i];
    for (int i = 0; i < num_places; i++)
        tmp_integer[i] = arr_int[i];
    r_mx *copy = mx_r_list_reeverse(tmp);

    for (int i = 0; tmp_integer[i + 1]; i++) {
        r_mx *temp = copy;
        while(temp) {
            if (mx_strcmp(temp -> s, temp[i]) == 0 && mx_strcmp(temp -> e, tmp_arr[i + 1]) == 0) {
                mx_array_editor(copy, num_places, tmp, arr_int, tmp_integer);
                temp -> s = "NULL";
                temp -> e = "NULL";
                checker = 1;
                recursed++;
                break;
            }
            temp = temp -> next;
        }
        if (checker)
            break;
    }
    if (checker)
        mx_outer_array_recursion_editor(copy, num_places, array, arr_int, recursed);
    else {
        if (recursed == 0)
            mx_array_printer(copy, num_places, tmp);
    }
}
