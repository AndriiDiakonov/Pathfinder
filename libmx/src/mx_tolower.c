#include "../inc/libmx.h"

int mx_tolower(int c) {
	if (c >= 97)
		return c;
	else
		return c + 32;
}
