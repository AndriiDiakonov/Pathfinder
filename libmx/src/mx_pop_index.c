#include "../inc/libmx.h"

void mx_pop_index(t_list **list, int index) {
    t_list *head = *list, *p;
    int num = 0;
    if (index == 0)
        mx_pop_front(&head);
    while (head -> next != NULL) {
        if (num == index) {
            p = head -> next; 
            mx_pop_back(&head);
            head -> next = p; 
        }
        num++;
        head = head -> next;
    }
    if (num < index) 
        mx_pop_back(&head);
}
