#include "../inc/pathfinder.h"

void mx_array_garbager(int num_places,  int integer[num_places]) {
    int end = num_places - 1;
    while (end != 0) {
        int counter = 0;
        for (int i = 0; i < end; i++)
            counter += integer[i];
        if (integer[end] == counter)
            break;
        end--;
    }

    for (int i = num_places - 1; i > end; i--) {
        integer[i] = 0;
    }
}
