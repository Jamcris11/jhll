#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"

struct Stack;

struct Stack*	stack_new(size_t element_size, void (*free_callback)(void*));
void		stack_delete(struct Stack* stack);

void		stack_push(struct Stack* stack, void* data);
void*		stack_pop(struct Stack* stack);
int		stack_length(struct Stack* stack);

#endif // STACK_H
