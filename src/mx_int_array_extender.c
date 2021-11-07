#include "../inc/pathfinder.h"

void mx_int_array_extender(int num_places, int array[num_places], int insert_element_1, int insert_element_2, int insert_count) {
    int i = num_places - 2;
    while (i >= insert_count) {
        array[i + 1] = array[i];
        i--;
    }
    array[i + 1] = insert_element_1;
    
    int j = num_places - 2;
    while (j >= insert_count + 1) {
        array[j + 1] = array[j];
        j--;
    }
    array[j + 1] = insert_element_2;

    for (int i = j + 2; i < num_places + 1; i++) {
        array[i] = array[i + 1];
    }
}
