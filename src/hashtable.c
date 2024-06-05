#include "hashtable.h"

struct Hashtable
{
	size_t size;
	size_t element_size;
	int count;
	void** data;
};

static int jims_hash_func(const char* key);

struct Hashtable*
hashtable_new(size_t size, size_t element_size)
{
	struct Hashtable* table;

	table = malloc(sizeof(struct Hashtable));

	table->size = size;
	table->element_size = element_size;
	table->count = 0;

	table->data = calloc(size, sizeof(void*));	

	return table;
}

void
hashtable_delete(struct Hashtable* table)
{
	for (int i = 0; i < table->size; i++ ) {
		free(table->data[i]);
	}

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
		perror("Collision occurred in hashtable insert");
		return 1;
	}

	table->data[index] = malloc(table->element_size);
	memcpy(table->data[index], value, table->element_size);

	return 0;
}

int
hashtable_remove(struct Hashtable* table, const char* key)
{
	// Todo
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

