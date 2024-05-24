#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LinkedList*	linked_list_new(size_t element_size);
void			linked_list_delete(struct LinkedList* list);

int			linked_list_add(struct LinkedList* list, void* data);
void*			linked_list_next(struct LinkedList* list);
void			linked_list_reset_iterator(struct LinkedList* list);


#endif // LINKED_LIST_H