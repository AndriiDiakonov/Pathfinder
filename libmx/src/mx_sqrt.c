#include "../inc/libmx.h"

int mx_sqrt(int x) {
    if(x == 1)  return 1;
    for (int i = 0; i * i <= x; i++)
        if(i * i == x)
            return i;
    return 0;
}
