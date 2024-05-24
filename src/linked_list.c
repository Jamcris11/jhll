#include "linked_list.h"

struct Node
{
	void* data;
	struct Node* next;
};

struct LinkedList
{
	struct Node* start;
	struct Node* current;
	struct Node* end;
	size_t element_size;
};


struct LinkedList*	
linked_list_new(size_t element_size)
{
	struct LinkedList* list;

	list = malloc(sizeof(struct LinkedList));

	list->start = NULL;
	list->current = NULL;
	list->end = NULL;
	list->element_size = element_size;

	return list;
}

void
linked_list_delete(struct LinkedList* list)
{
	void* node_data;

	linked_list_reset_iterator(list);

	if (list->start != NULL) {
		while ( (node_data = linked_list_next(list)) != NULL ) {
			free(node_data);
		} 
	}

	free(list);
}

int
linked_list_add(struct LinkedList* list, void* data)
{
	struct Node* node;

	node = malloc(sizeof(struct Node));

	if ( node == NULL ) {
		perror("malloc failed adding linked list node: ");
		return 1;
	}

	if ( list->start == NULL ) {
		list->start = node; 
		list->current = node;
		list->end = node;
	}
	else {
		list->end->next = node;
		list->end = list->end->next;
	}

	node->data = malloc(list->element_size);
	memcpy(node->data, data, list->element_size);

	node->next = NULL;

	return 0;
}

void*
linked_list_next(struct LinkedList* list)
{
	void* data;

	if ( list->current == NULL ) {
		return NULL;
	}
       
	data = list->current->data;
	list->current = list->current->next;
	return data;
}

void
linked_list_reset_iterator(struct LinkedList* list)
{
	list->current = list->start;
}


