#include "../inc/pathfinder.h"

r_mx *mx_copy_r_list(r_mx *list) {
    r_mx *dst = mx_create_route_node("NULL", "NULL", "NULL",0,0,0);

    r_mx *tmp = list;
    while (tmp) {
        if (mx_strcmp(tmp->s, "NULL") != 0)
            mx_push_route_back(&dst, tmp->s, tmp->m, tmp->e, tmp->a, tmp->b, tmp->c);
        tmp = tmp -> next;
    }
    return dst;
}