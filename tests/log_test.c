#include "log.h"

int
main(int argc, char** argv)
{
	LOG_INIT();
	LOG_SET_OPTS(&(struct LoggerOpts){ .min_level = LOG_INFO });

	for (int i = 0; i < 100; i++) {
		LOG(LOG_INFO, "Counting to %d", i);
	}
	
	LOG_PRINT();

	LOG_TO_FILE("log.txt");

	LOG_QUIT();

	return 0;
}
