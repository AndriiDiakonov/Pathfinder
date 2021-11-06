#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
	unsigned char *haystack = NULL;
	unsigned char *needle = NULL;

	if (big_len >= little_len && big_len > 0 && little_len > 0) {
		haystack = (unsigned char *)big;
		needle = (unsigned char *)little;
		while (*haystack) {
			if (mx_memcmp(haystack, needle, little_len - 1) == 0)
				return haystack;
			haystack++;
		}
	}
	return NULL;
}
