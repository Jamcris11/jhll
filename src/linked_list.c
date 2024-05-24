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
	size_t length;
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
	list->length = 0;

	return list;
}

void
linked_list_delete(struct LinkedList* list)
{
	void* data;
	struct Node* node, *previous_node;

	if (list->start != NULL) {
		node = list->start;

		do {
			previous_node = node;
			node = node->next;
			free(previous_node->data);
			free(previous_node);
		} while ( node != NULL );
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

	list->length++;

	return 0;
}

void
linked_list_remove(struct LinkedList* list, int index)
{
	struct Node* node, *prev_node;

	node = list->start;
	prev_node = NULL;

	for ( int i = 0; i < index; i++ ) {
		if ( node->next == NULL ) { 
			list->end = prev_node;
			break; 
		}

		prev_node = node;
		node = node->next;
	}

	if ( prev_node != NULL ) {
		prev_node->next = node->next;
	}
	else {
		list->start = node->next;
	}

	list->length--;

	free(node->data);
	free(node);
}

void*
linked_list_start(struct LinkedList* list)
{
	return list->start->data;
}

void*
linked_list_end(struct LinkedList* list)
{
	return list->end->data;
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

int
linked_list_length(struct LinkedList* list)
{
	return list->length;
}

size_t
linked_list_element_size(struct LinkedList* list)
{
	return list->element_size;
}
