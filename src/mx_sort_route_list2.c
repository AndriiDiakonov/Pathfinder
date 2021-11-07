#include "../inc/pathfinder.h"

void mx_sort_route_list2(r_mx *new_route_list) {
    r_mx *tmp = new_route_list;
    while (tmp) {
        r_mx *tmp_2 = tmp -> next;
        while(tmp_2) {
            if (mx_strcmp(tmp_2->s, tmp ->s) == 0 && mx_strcmp(tmp_2->e, tmp ->e) == 0) {
                if (tmp_2->c > tmp->c) {
                    tmp_2->s = "NULL";
                    tmp_2->m = "NULL";
                    tmp_2->e = "NULL";
                    tmp_2->a = TH_TEN;
                    tmp_2->b = TH_TEN;
                    tmp_2->c = TH_TEN;
                }
                else if (tmp_2->c < tmp->c) {
                    tmp->s = "NULL";
                    tmp->m = "NULL";
                    tmp->e = "NULL";
                    tmp->a = TH_TEN;
                    tmp->b = TH_TEN;
                    tmp->c = TH_TEN;
                }
                if (tmp->a == tmp_2->a && tmp->b == tmp_2->b && tmp->c == tmp_2->c) {
                    tmp_2->s = "NULL";
                    tmp_2->m = "NULL";
                    tmp_2->e = "NULL";
                    tmp_2->a = TH_TEN;
                    tmp_2->b = TH_TEN;
                    tmp_2->c = TH_TEN;
                }
                else if (tmp->a == tmp_2->b && tmp->b == tmp_2->a && tmp->c == tmp_2->c) {
                    tmp_2->s = "NULL";
                    tmp_2->m = "NULL";
                    tmp_2->e = "NULL";
                    tmp_2->a = TH_TEN;
                    tmp_2->b = TH_TEN;
                    tmp_2->c = TH_TEN;
                }
            }
            tmp_2 = tmp_2 -> next;
        }
        tmp = tmp -> next;
    }
}
