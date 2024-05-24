#include "linked_list.h"

int
main(int argc, char** argv)
{
	struct LinkedList* list;
	char** data;

	list = linked_list_new(sizeof(char*));

	linked_list_add(list, &(char*){"Hello world!"});
	linked_list_add(list, &(char*){"How are you doing?"});
	linked_list_add(list, &(char*){"I hope you are doing great!"});

	linked_list_remove(list, 0);

	linked_list_reset_iterator(list);

	while ( (data = (char**)linked_list_next(list)) != NULL ) {
		printf("%s\n", *data);
	}

	linked_list_delete(list);

	return 0;
}
