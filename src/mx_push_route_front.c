#include "../inc/pathfinder.h"

void mx_push_route_front(r_mx **list, char *start, char *middle, char *end, 
                         int s_distance, int m_distance, int e_distance) {
    r_mx *node = (r_mx *)malloc(sizeof(r_mx));
    if (node == NULL) {
        char *msg = "Malloc Error\n";
        write(2, msg, (int)strlen(msg));
        exit(1);
    }
    node->s = start;
    node->m = middle;
    node->e = end;
    
    node->a = s_distance;
    node->b = m_distance;
    node->c = e_distance;

    node->next = (*list);
    (*list ) = node;
}
