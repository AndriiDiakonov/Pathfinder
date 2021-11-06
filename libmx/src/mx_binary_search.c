#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    (*count) = 0;
    for (int i = 0; i < size; i++) {
	if (arr[i] == NULL) return -1;
        for (int j = 0; j < size - 1; j++) {
            if (mx_strcmp (arr[j], arr[j + 1]) > 0) {
                char *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    int first = 0;
    int last = size - 1;
    int middle = (first + last) / 2;

    while (first <= last) {
        (*count)++;
        if (mx_strcmp(arr[middle], s) < 0)
            first = middle + 1;
        else if (mx_strcmp (arr[middle], s) == 0) {
            return middle;
        }
        else
            last = middle - 1;

    middle = (first + last) / 2;
    }
    if (first > last) {
        *count = 0;
        return -1;
    }
    return -1;
}
