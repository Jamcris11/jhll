#include "linked_list.h"

int
main(int argc, char** argv)
{
	struct LinkedList* list;
	char** data;

	list = linked_list_new(sizeof(char*));

	linked_list_add(list, &(char*){"Hello world!"});
	linked_list_add(list, &(char*){"How are you doing?"});

	while ( (data = (char**)linked_list_next(list)) != NULL ) {
		printf("%s\n", *data);
	}

	linked_list_delete(list);

	return 0;
}
