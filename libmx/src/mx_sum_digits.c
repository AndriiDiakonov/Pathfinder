#include "../inc/libmx.h"

int mx_sum_digits(int num) {
	int sum = 0;
	if (num < 0) 
	    num = num - num;
	while (num) {
		sum += num % 10;
		num /= 10;
	}
	return sum;
}
