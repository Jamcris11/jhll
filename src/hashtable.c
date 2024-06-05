#include "hashtable.h"

struct Hashtable
{
	size_t size;
	size_t element_size;
	void** data;
	struct LinkedList* keys;
};

static int jims_hash_func(const char* key);

struct Hashtable*
hashtable_new(size_t size, size_t element_size)
{
	struct Hashtable* table;

	table = malloc(sizeof(struct Hashtable));

	table->size = size;
	table->element_size = element_size;

	table->data = calloc(size, sizeof(void*));
	table->keys = linked_list_new(sizeof(char*));

	return table;
}

void
hashtable_delete(struct Hashtable* table)
{
	for (int i = 0; i < table->size; i++ ) {
		free(table->data[i]);
	}

	linked_list_delete(table->keys);
	free(table->data);
	free(table);
}

int
hashtable_insert(struct Hashtable* table, const char* key, void* value)
{
	int hash;
	int index;

	hash = jims_hash_func(key);

	index = hash % table->size;

	if ( table->data[index] != NULL ) {
		fprintf(stderr, "Collision occurred for key: %s\n", key);
		return 1;
	}

	linked_list_add(table->keys, (void*)key);
	table->data[index] = malloc(table->element_size);
	memcpy(table->data[index], value, table->element_size);

	return 0;
}

int
hashtable_remove(struct Hashtable* table, const char* key)
{
	int hash;
	int index;
	char* ckey;

	linked_list_reset_iterator(table->keys);

	index = 0;
	ckey = linked_list_next(table->keys);

	while ( strcmp(ckey, key) ) {
		index++;
		ckey = linked_list_next(table->keys);
	}

	if ( ckey == NULL ) {
		return 1;
	}

	linked_list_remove(table->keys, index);
	
	hash = jims_hash_func(key);
	index = hash % table->size;
		
	free(table->data[index]);
	table->data[index] = NULL;

	linked_list_reset_iterator(table->keys);

	return 0;
}

void*
hashtable_get(struct Hashtable* table, const char* key)
{
	int hash;
	int index;

	hash = jims_hash_func(key);
	index = hash % table->size;

	return table->data[index];

}

int
hashtable_count(struct Hashtable* table)
{
	return linked_list_length(table->keys); 
}

struct LinkedList*
hashtable_keys(struct Hashtable* table)
{
	return table->keys;
}

static int
jims_hash_func(const char* key)
{
	int val;

	val = 0;

	for (int i = 0; i < strlen(key); i++ ) {
		val += key[i];
	}

	return val;
}

