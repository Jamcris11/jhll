#include "hashtable.h"

struct HashtableKV
{
	char* key;
	void* value;
};

struct Hashtable
{
	size_t size;
	size_t element_size;
	struct HashtableKV* data;
	struct LinkedList* keys;
};

static void	free_callback(void* data);
static int	jims_hash_func(const char* key);
static int	get_key_index(struct Hashtable* table, const char* key);

struct Hashtable*
hashtable_new(size_t size, size_t element_size)
{
	struct Hashtable* table;

	table = malloc(sizeof(struct Hashtable));

	table->size = size;
	table->element_size = element_size;

	table->data = calloc(size, sizeof(struct HashtableKV));
	table->keys = linked_list_new(sizeof(char*), free_callback);

	return table;
}

void
hashtable_delete(struct Hashtable* table)
{
	struct LinkedList* keys;
	void* data;
	int i;

	keys = hashtable_keys(table);
	linked_list_reset_iterator(keys);
	data = linked_list_next(keys);

	while ( data != NULL ) {
		i = get_key_index(table, *(char**)data);
		free(table->data[i].key);
		free(table->data[i].value);
		data = linked_list_next(keys);
	}

	linked_list_delete(table->keys);
	free(table->data);
	free(table);
}

int
hashtable_insert(struct Hashtable* table, const char* key, void* value)
{
	int index;

	index = get_key_index(table, key);

	linked_list_add(table->keys, &(char*) { (char*)key });
	table->data[index].key = malloc(sizeof(char) * strlen(key) + 1);
	strcpy(table->data[index].key, key);

	table->data[index].value = malloc(sizeof(table->element_size));
	memcpy(table->data[index].value, value, table->element_size);

	return 0;
}

int
hashtable_remove(struct Hashtable* table, const char* key)
{
	int index;
	void* ckey;

	linked_list_reset_iterator(table->keys);

	index = 0;
	ckey = linked_list_next(table->keys);

	while ( strcmp(*(char**)ckey, key) ) {
		index++;
		ckey = linked_list_next(table->keys);
	}

	if ( ckey == NULL ) {
		return 1;
	}

	linked_list_remove(table->keys, index);
	linked_list_reset_iterator(table->keys);

	index = get_key_index(table, key);

	free(table->data[index].key);
	free(table->data[index].value);

	table->data[index].key = NULL;
	table->data[index].value = NULL;


	return 0;
}

void*
hashtable_get(struct Hashtable* table, const char* key)
{
	int index;

	index = get_key_index(table, key);

	return table->data[index].key != NULL ? table->data[index].value : NULL;
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

static void
free_callback(void* data)
{
	free(data);
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

static int
get_key_index(struct Hashtable* table, const char* key)
{
	int index;

	index = jims_hash_func(key) % table->size;
	
	while ( table->data[index].key != NULL && strcmp(table->data[index].key, key) ) {
		index = (index + 1) % table->size;
	}

	return index;
}
