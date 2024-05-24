#include "list.h"

int
main(int argc, char** argv)
{
	struct List* list;

	list = list_new(sizeof(int));

	list_add(list, &(int){10});
	list_add(list, &(int){20});
	list_add(list, &(int){30});
	list_add(list, &(int){40});
	list_add(list, &(int){50});

	for (int i = 0; i < list_length(list); i++ ) {
		printf("%d\n", *(int*)list_get(list, i));
	}

	list_delete(list);

	return 0;
}
