#include "../inc/libmx.h"

bool mx_islower(int d) { 
    if ('a' <= d && d <= 'z')
        return 1;
    else
        return 0;
}
