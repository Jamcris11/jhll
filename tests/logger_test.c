#include "logger.h"

int
main(int argc, char** argv)
{
	log_init();

	LOG(LOG_INFO, "This is a test log! From %s", "Jamie");
	LOG(LOG_WARN, "We will find you");
	
	LOG_PRINT();

	log_quit();

	return 0;
}
