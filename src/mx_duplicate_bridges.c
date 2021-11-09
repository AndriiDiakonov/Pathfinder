#include "../inc/pathfinder.h"

void mx_duplicate_bridges(t_finder *path) {
    for (int i = 1; i < path -> words; i += 3) {
        for (int j = i + 3; j < path -> words; j += 3) {
            if (!mx_strcmp(path -> islands[i], path -> islands[j]) || !mx_strcmp(path -> islands[i], path -> islands[j + 1])) {
                if (!mx_strcmp(path -> islands[i + 1], path -> islands[j]) || !mx_strcmp(path -> islands[i + 1], path -> islands[j])) {
                    mx_printerr("error: duplicate bridges\n");
                    exit(1);
                }
            }
        }
    }
}
