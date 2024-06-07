#ifndef CHRONOS_H
#define CHRONOS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TIME(f) time_func_sec(f)

double		time_func_sec(size_t (*callback)());
long int	time_func_clocks(size_t (*callback)());

#endif // CHRONOS_H
