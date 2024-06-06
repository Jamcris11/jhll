#include "stack.h"

static void
free_callback(void* data)
{
	free(data);
}

int
main(int argc, char** argv)
{
	struct Stack* stack_str;
	struct Stack* stack_int;
	char* data;
	char** result;
	int* result_int;

	stack_str = stack_new(sizeof(char*), free_callback);

	data = malloc(13);
	strcpy(data, "Hello world!");
	stack_push(stack_str, &data);

	data = malloc(7);
	strcpy(data, "Jamie.");
	stack_push(stack_str, &data);

	data = malloc(3);
	strcpy(data, "am");
	stack_push(stack_str, &data);

	data = malloc(2);
	strcpy(data, "I");
	stack_push(stack_str, &data);
	
	data = malloc(6);
	strcpy(data, "Hello");
	stack_push(stack_str, &data);

	while ( (result = (char**)stack_pop(stack_str)) != NULL ) {
		printf("%s\n", *result);
		free(*result);
		free(result);
	}

	stack_delete(stack_str);

	stack_int = stack_new(sizeof(int), free_callback);


	for ( int x = 1, y = 0, z = 0, i = 0; i < 10; i++ ) {
		z = x + y;
		y = x;
		x = z;

		stack_push(stack_int, &(int){ x });
	}

	while ( (result_int = (int*)stack_pop(stack_int)) != NULL ) {
		printf("%d\n", *result_int);
		free(result_int);
	}

	stack_delete(stack_int);

	return 0;
}
