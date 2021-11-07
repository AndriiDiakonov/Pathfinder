#include "../inc/pathfinder.h"

int mx_list_value_validator(r_mx **list, void *data) {
    r_mx *x = *list;
    while (x -> next) {
        if (mx_strcmp(x -> data, data) == 0)
            return -1;
        x = x -> next;
    }
    if (mx_strcmp(x -> data, data) == 0)
        return -1;
    return 0;   
}
