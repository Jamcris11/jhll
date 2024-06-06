#include "stack.h"

struct Stack
{
	struct LinkedList* list;
};

struct Stack*
stack_new(size_t element_size, void (*free_callback)(void*))
{
	struct Stack* stack;

	stack = malloc(sizeof(struct Stack));

	stack->list = linked_list_new(element_size, free_callback);

	return stack;
}

void
stack_delete(struct Stack* stack)
{
	linked_list_delete(stack->list);
	free(stack);
}

void
stack_push(struct Stack* stack, void* data)
{
	linked_list_add(stack->list, data);
}

void*
stack_pop(struct Stack* stack)
{
	void* val, * data;
	int size;

	if ( linked_list_length(stack->list) <= 0 ) {
		return NULL;
	}

	size = linked_list_element_size(stack->list);
	val = malloc(size);
	data = linked_list_end(stack->list);
	memcpy(val, data, size);
	linked_list_remove(stack->list, linked_list_length(stack->list));

	return val;
}

int
stack_length(struct Stack* stack)
{
	return linked_list_length(stack->list);
}
