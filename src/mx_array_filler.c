#include "../inc/pathfinder.h"

void mx_array_filler(int num_places, char *arr[num_places], int integer[num_places], r_mx *list, char *start, char *end) {
    r_mx *tmp = list;
    while (tmp) {
        if (mx_strcmp(tmp -> s, start) == 0 && mx_strcmp(tmp -> e, end) == 0) {
            arr[0] = tmp -> s;
            arr[1] = tmp -> m;
            arr[2] = tmp -> e;
            integer[0] = tmp -> a;
            integer[1] = tmp -> b;
            integer[2] = tmp -> c;
            break;
        }
        tmp = tmp -> next;
    }
}
