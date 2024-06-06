#ifndef UTIL_H
#define UTIL_H

#define LEN(x) sizeof(x)/sizeof(x[0])
#define IS_EVEN(x) x % 2 == 0
#define IS_BETWEEN(x, y, z) x >= y && x <= z
#define SWAP(a, b) \
	a = a^b; \
	b = a^b; \
	a = a^b;

#endif // UTIL_H
