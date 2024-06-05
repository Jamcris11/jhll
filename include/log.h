#ifndef LOG_H
#define LOG_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_INIT() log_init();
#define LOG_QUIT() log_quit();
#define LOG_SET_OPTS(OPTS) log_set_opts(OPTS);
#define LOG(E, MSG, ...) log_log(E, MSG __VA_OPT__(,) __VA_ARGS__) 
#define LOG_PRINT() log_print()
#define LOG_TO_FILE(X) log_to_file(X)

#define BUFFER_SIZE 1024

enum LogLevel
{
	LOG_INFO=0,
	LOG_WARN,
	LOG_ERROR,
	LOG_FATAL
};

struct LoggerOpts
{
	enum LogLevel min_level;
};

struct Logger;

int		log_init();
void		log_quit();

void		log_set_opts(const struct LoggerOpts* opts);
void		log_log(enum LogLevel, const char* fmt, ...);
void		log_print();

void		log_to_file(const char* path);

#endif // LOG_H
