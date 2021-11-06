#include "../inc/libmx.h"

void mx_printint(int n) {
   char arr[11];

    if (n == -2147483648) {
        write(1, "-2147483648", 11);
        mx_printchar('\n');
        return;
    }
    if (n < 0 ) {
        mx_printchar('-');
        n = n * (-1);
    }
    if (n >= 0 && n <= 9)
        mx_printchar(n + 48);
    if (n > 9 ) {
        int i = 0;
        
        for (; n; n /= 10, i++) {
            arr[i] = n % 10;
        }
        for (int j = i - 1; j >= 0  ; j--) {
            mx_printchar(arr[j] + 48);
        }
    }     
    mx_printchar('\n');
}
