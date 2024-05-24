#include "list.h"

int
main(int argc, char** argv)
{
	struct List* list;

	list = list_new(sizeof(char*));

	list_add(list, &(char*){"Hello world!"});
	list_add(list, &(char*){"I tolerate you all!"});

	for (int i = 0; i < list_length(list); i++ ) {
		printf("%s\n", *(char**)list_get(list, i));
	}

	list_delete(list);

	return 0;
}
