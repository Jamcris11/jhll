#include "hashtable.h"

int
main(int argc, char** argv)
{
	struct Hashtable* table;
	struct LinkedList* keys;
	char* val;

	table = hashtable_new(1024, sizeof(char*));

	hashtable_insert(table, "one", &(char*){ "Hello world!" });
	hashtable_insert(table, "two", &(char*){ "How are we doing?" });
	hashtable_insert(table, "three", &(char*){ "I'm doing great!" });
	hashtable_insert(table, "four", &(char*){ "I'm doing OK!" });
	hashtable_insert(table, "five", &(char*){ "I'm doing fine!" });
	hashtable_insert(table, "six", &(char*){ "I'm doing poorly!" });
	hashtable_insert(table, "seven", &(char*){ "I'm doing bad!" });
	hashtable_insert(table, "eight", &(char*){ "I'm doing terrible!" });
	hashtable_insert(table, "nine", &(char*){ "I'm doing coke!" });
	hashtable_insert(table, "ten", &(char*){ "Splosh" });

	//hashtable_remove(table, "three");

	keys = hashtable_keys(table);
	val = linked_list_next(keys);

	printf("#of keys: %d\n", hashtable_count(table));

	while ( val != NULL ) {
		printf("key -> %s: %s\n", val, *(char**)hashtable_get(table, val));
		val = linked_list_next(keys);
	}

	hashtable_delete(table);

	return 0;
}
