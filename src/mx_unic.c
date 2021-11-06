#include "../inc/pathfinder.h"

int mx_unic(char *argv) {
    char *data = mx_file_to_str(argv);
    int count = 0;
    int i = 0;
    int unic = 0;

    while (data[count] != '\n') 
        count++;
    
    char x[count];

    while (i != count) {
        x[i] = data[i];
        i++;
    }
    x[i] = '\0';
    
    unic = mx_atoi(x);
    return unic;
}
