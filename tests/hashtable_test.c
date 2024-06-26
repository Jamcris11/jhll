#include "chronos.h"
#include "hashtable.h"

static size_t
do_stuff()
{
	struct Hashtable* table;
	struct LinkedList* keys;
	void* val;

	table = hashtable_new(1024, sizeof(char*));

	hashtable_insert(table, "zero", &(char*){ "..." });
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
	hashtable_insert(table, "fifthteen", &(char*){ "Splonky" });


	hashtable_remove(table, "zero");
	hashtable_remove(table, "fifthteen");

	keys = hashtable_keys(table);
	linked_list_reset_iterator(keys);
	val = linked_list_next(keys);

	printf("#of keys: %d\n", hashtable_count(table));

	while ( val != NULL ) {
		printf("key -> %s: %s\n", *(char**)val, *(char**)hashtable_get(table, *(char**)val));
		val = linked_list_next(keys);
	}

	hashtable_delete(table);

	return 0;
}

int
main(int argc, char** argv)
{
	double seconds_elapsed = TIME(do_stuff);

	printf("---------------------\n");
	printf("Time taken: %f\n", seconds_elapsed);

	return 0;
}
