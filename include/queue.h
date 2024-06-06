#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"

struct Queue;

struct Queue*	queue_new(size_t element_size, void (*free_callback)(void*));
void		queue_delete(struct Queue* queue);

void		queue_enqueue(struct Queue* queue, void* data);
void*		queue_dequeue(struct Queue* queue);
int		queue_length(struct Queue* queue);

#endif // QUEUE_H
