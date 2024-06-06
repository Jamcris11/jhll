#include "queue.h"

struct Queue
{
	struct LinkedList* list;
};

struct Queue*
queue_new(size_t element_size, void (*free_callback)(void*))
{
	struct Queue* queue;

	queue = malloc(sizeof(struct Queue));

	queue->list = linked_list_new(element_size, free_callback);

	return queue;
}

void
queue_delete(struct Queue* queue)
{
	linked_list_delete(queue->list);
	free(queue);
}

void
queue_enqueue(struct Queue* queue, void* data)
{
	linked_list_add(queue->list, data);
}

void*
queue_dequeue(struct Queue* queue)
{
	void* val, *data;
	int size;

	if ( linked_list_length(queue->list) <= 0 ) {
		return NULL;
	}

	size = linked_list_element_size(queue->list);

	val = malloc(size);
	data = linked_list_start(queue->list);
	memcpy(val, data, size);

	linked_list_remove(queue->list, 0);

	return val;
}

int
queue_length(struct Queue* queue)
{
	return linked_list_length(queue->list);
}
