#include "list.h"


struct List
{
	void** data;
	size_t element_size;
	size_t size;
	size_t length;
};

struct List*
list_new(size_t element_size)
{
	struct List* list;

	list = malloc(sizeof(struct List));

	if ( list == NULL ) {
		perror("failed to malloc list: ");
		return NULL;
	}

	list->element_size = element_size;
	list->size = 1;
	list->length = 0;

	list->data = malloc(sizeof(void*) * list->size);

	return list;
}

struct List*
list_new_sized(size_t element_size, size_t size)
{
	struct List* list;

	list = malloc(sizeof(struct List));

	if ( list == NULL ) {
		perror("failed to malloc list: ");
		return NULL;
	}

	list->element_size = element_size;
	list->size = size;
	list->length = 0;

	list->data = malloc(sizeof(void*) * list->size);

	return list;

}



void
list_delete(struct List* list)
{
	for ( int i = 0; i < list->length; i++ ) {
		free(list->data[i]);
	}

	free(list->data);
	free(list);
}

int
list_add(struct List* list, void* data)
{
	void* data_pos;

	if ( list->length >= list->size ) {
		list->size *= 2;
		list->data = realloc(list->data, sizeof(void*) * list->size);
	}

	list->data[list->length++] = malloc(list->element_size);
	memcpy(list->data[list->length-1], data, list->element_size);

	return 0;
}

void*
list_get(struct List* list, int index)
{
	return list->data[index];	
}

size_t		
list_length(struct List* list)
{
	return list->length;
}
