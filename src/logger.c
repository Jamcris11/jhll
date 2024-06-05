#include "logger.h"

struct Logger
{
	char* buffer;
	int buffer_size;
	int buffer_used;
	struct LoggerOpts options;
};

static struct Logger* logger = NULL;

int
log_init()
{
	logger = malloc(sizeof(struct Logger));

	logger->buffer = malloc(sizeof(char) * BUFFER_SIZE);
	logger->buffer_size = BUFFER_SIZE;
	logger->buffer_used = 0;

	logger->options.min_level = LOG_INFO;

	return 0;
}

void
log_quit()
{
	free(logger->buffer);
	free(logger);
}

void
log_set_opts(const struct LoggerOpts* opts)
{
	memcpy(&logger->options, opts, sizeof(struct LoggerOpts));
}

void
log_log(enum LogLevel level, const char* fmt, ...)
{
	va_list args;
	char buffer[BUFFER_SIZE];
	int index;
	int len;

	if (level < logger->options.min_level) { return; }

	switch (level) {
		case LOG_INFO:
			index = sprintf(buffer, "[INFO]\t");
			break;
		case LOG_WARN:
			index = sprintf(buffer, "[WARN]\t");
			break;	
		case LOG_ERROR:
			index = sprintf(buffer, "[ERROR]\t");
			break;
		case LOG_FATAL:
			index = sprintf(buffer, "[FATAL]\t");
			break;
	}
	
	va_start(args, fmt);
	index += vsprintf(&buffer[index], fmt, args); 

	index += sprintf(&buffer[index], "\n");

	len = strlen(buffer);

	if ( logger->buffer_used + len > logger->buffer_size-1 ) {
		logger->buffer_size *= 2;
		logger->buffer = realloc(logger->buffer, logger->buffer_size);
	}

	strcat(logger->buffer, buffer);
}


void
log_print()
{
	printf("%s", logger->buffer);
}
