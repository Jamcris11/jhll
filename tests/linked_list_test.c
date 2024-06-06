#include "linked_list.h"

static void
free_linked_list_node_str(void* data)
{
	free(*(char**)data);
	free(data);
}

int
main(int argc, char** argv)
{
	struct LinkedList* list;
	char* data;
	char** result;

	list = linked_list_new(sizeof(char*), free_linked_list_node_str);

	data = malloc(sizeof(char) * 6);
	strcpy(data, "Hello");
	linked_list_add(list, &data);

	
	data = malloc(sizeof(char) * 6);
	strcpy(data, "Pussy");
	linked_list_add(list, &data);


	data = malloc(sizeof(char) * 13);
	strcpy(data, "Hello world!");
	linked_list_add(list, &data);

	result = (char**)linked_list_next(list);
	
	while ( result != NULL ) {
		printf("%s\n", *result);
		result = (char**)linked_list_next(list);
	}

	linked_list_delete(list);

	return 0;
}
