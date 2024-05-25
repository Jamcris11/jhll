#include "linked_list.h"

int
main(int argc, char** argv)
{
	struct LinkedList* list;
	char* data;
	char* result;

	list = linked_list_new(sizeof(char*));

	data = malloc(sizeof(char) * 6);
	strcpy(data, "Hello");
	linked_list_add(list, data);
	
	strcpy(data, "Pussy");
	linked_list_add(list, data);

	strcpy(data, "Cunny");
	linked_list_add(list, data);
	free(data);

	result = linked_list_next(list);
	
	while ( result != NULL ) {
		printf("%s\n", result);
		result = linked_list_next(list);
	}

	linked_list_delete(list);

	return 0;
}
