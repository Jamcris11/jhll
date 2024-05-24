#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct List;

struct List*	list_new(size_t element_size);
struct List*	list_new_sized(size_t element_size, size_t size);
void		list_delete(struct List* list);

int		list_add(struct List* list, void* data);
void*		list_get(struct List* list, int index);
size_t		list_length(struct List* list);

#endif // LIST_H
