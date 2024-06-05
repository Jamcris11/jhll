#include "logger.h"

int
main(int argc, char** argv)
{
	log_init();

	log_set_opts(&(struct LoggerOpts){ .min_level = LOG_INFO });


	for (int i = 0; i < 10; i++) {
		LOG(LOG_INFO, "Counting to %d", i);
	}
	
	LOG_PRINT();

	log_to_file("log.txt");

	log_quit();

	return 0;
}
