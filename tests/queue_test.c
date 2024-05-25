#include "queue.h"

int
main(int argc, char** argv)
{
	struct Queue* queue;
	char** data;

	queue = queue_new(sizeof(char*));

	queue_enqueue(queue, &(char*){ "Jamie." });
	queue_enqueue(queue, &(char*){ "am" });
	queue_enqueue(queue, &(char*){ "I" });
	queue_enqueue(queue, &(char*){ "Hello" });

	while ( (data = (char**)queue_dequeue(queue)) != NULL ) {
		printf("%s\n", *data);
		free(data);
	}

	queue_delete(queue);

	return 0;
}
