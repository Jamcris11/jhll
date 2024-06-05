#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"

struct Hashtable;

struct Hashtable*	hashtable_new(size_t size, size_t element_size);
void			hashtable_delete(struct Hashtable* table);

int			hashtable_insert(struct Hashtable* table, const char* key, void* value);
int			hashtable_remove(struct Hashtable* table, const char* key);

void*			hashtable_get(struct Hashtable* table, const char* key);
int			hashtable_count(struct Hashtable* table);
struct LinkedList*	hashtable_keys(struct Hashtable* table);
#endif // HASHTABLE_H
