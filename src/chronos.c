#include "chronos.h"

double
time_func_sec(size_t (*callback)())
{
	return (double)time_func_clocks(callback) / CLOCKS_PER_SEC;
}

long int
time_func_clocks(size_t (*callback)())
{
	clock_t start;

	start = clock();

	callback();

	return (long int)(clock() - start);
}
