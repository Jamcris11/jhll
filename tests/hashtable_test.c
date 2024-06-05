#include "hashtable.h"

int
main(int argc, char** argv)
{
	struct Hashtable* table;

	table = hashtable_new(1024, sizeof(char*));

	hashtable_insert(table, "one", &(char*){ "Hello world!" });
	hashtable_insert(table, "two", &(char*){ "How are we doing?" });
	hashtable_insert(table, "three", &(char*){ "I'm doing great!" });

	hashtable_remove(table, "three");

	printf("key -> one: %s\n", *(char**)hashtable_get(table, "one"));
	printf("key -> two: %s\n", *(char**)hashtable_get(table, "two"));

	hashtable_delete(table);

	return 0;
}