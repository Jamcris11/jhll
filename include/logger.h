#ifndef LOGGER_H
#define LOGGER_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG(E, MSG, ...) log_log(E, MSG __VA_OPT__(,) __VA_ARGS__) 
#define LOG_PRINT() log_print()

#define BUFFER_SIZE 1024

enum LogLevel
{
	LOG_INFO=0,
	LOG_WARN,
	LOG_ERROR,
	LOG_FATAL
};

struct Logger;

int		log_init();
void		log_quit();

void		log_log(enum LogLevel, const char* fmt, ...);
void		log_print();

#endif // LOGGER_H
