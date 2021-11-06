#include "../inc/libmx.h"

char *mx_itoa(int number) {
    if (number == 0) {
        return "0";
    }
    if (number == -2147483648){
        return "-2147483648";
    }
    int length = 0;
    int num_copy = number;
    if (num_copy < 0) {
        length++;
        num_copy *= -1;
    }
    while (num_copy != 0) {
        num_copy /= 10;
        length++;
    }

    char *num_str = mx_strnew(length);
    
    if (number < 0) {
        num_str[0] = '-';
        number *= -1;
    }
    num_str[length--] = '\0';
    while ((number != 0 && length >= 0) && num_str[length] != '-') {
        num_str[length--] = (number % 10) + '0';
        number /= 10;
    }
    return num_str;
}
