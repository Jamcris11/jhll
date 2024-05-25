#include "stack.h"

int
main(int argc, char** argv)
{
	struct Stack* stack;
	char** data;

	stack = stack_new(sizeof(char*));

	stack_push(stack, &(char*){ "Jamie." });
	stack_push(stack, &(char*){ "am" });
	stack_push(stack, &(char*){ "I" });
	stack_push(stack, &(char*){ "Hello" });

	while ( (data = (char**)stack_pop(stack)) != NULL ) {
		printf("%s\n", *data);
		free(data);
	}

	stack_delete(stack);

	return 0;
}
