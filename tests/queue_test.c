#include "queue.h"

void
free_callback(void* data)
{
	free(data);
}

int
main(int argc, char** argv)
{
	struct Queue* queue_str;
	struct Queue* queue_int;
	char* data;
	char** result;
	int* result_int;

	queue_str = queue_new(sizeof(char*), free_callback);

	data = malloc(7);
	strcpy(data, "Jamie.");
	queue_enqueue(queue_str, &data);

	data = malloc(3);
	strcpy(data, "am");
	queue_enqueue(queue_str, &data);


	data = malloc(2);
	strcpy(data, "I");
	queue_enqueue(queue_str, &data);


	data = malloc(6);
	strcpy(data, "Hello");
	queue_enqueue(queue_str, &data);

	while ( (result = (char**)queue_dequeue(queue_str)) != NULL ) {
		printf("%s\n", *result);
		free(*result);
		free(result);
	}

	queue_delete(queue_str);

	queue_int = queue_new(sizeof(int), free_callback);

	for (int x = 1, y = 0, z = 0, i = 0; i < 10; i++ ) {
		z = x + y;
		y = x;
		x = z;

		queue_enqueue(queue_int, &(int){ z });
	}

	while ( (result_int = (int*)queue_dequeue(queue_int)) != NULL ) {
		printf("%d\n", *result_int);
		free(result_int);
	}

	queue_delete(queue_int);

	return 0;
}
