#include "../inc/pathfinder.h"

void mx_unic_array(char *name, char **places) {
    char *data = mx_file_to_str(name);
    int count = 0;
    for (int i = 0; i < mx_strlen(file_data); i++) {
        if (mx_isalpha(data[i]) == -1)
            data[i] = ' ';
    }
    char **unic_places = mx_strsplit(data, ' ');
    for (int i = 0; unic_places[i + 1] != NULL; i++) {
        for (int j = i + 1; unic_places[j] != NULL; j++) {
            if (mx_strcmp(unic_places[i],unic_places[j]) == 0)
                unic_places[j] = "deleted";
        }
    }
    for (int i = 0; unic_places[i] != NULL; i++) {
        if (mx_strcmp(unic_places[i], "deleted") != 0) {
            unic_places[count] = unic_places[i];
            count++;
        }
    }
    unic_places[count] = NULL;
}
