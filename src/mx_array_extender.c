#include "../inc/pathfinder.h"

void mx_array_extender(int num_places, char *array[num_places], char *insert_element, int insert_count) {
    int i = num_places - 2;

    while (i >= insert_count) {
        array[i + 1] = array[i];
        i--;
    }
    array[i + 1] = insert_element;
}
