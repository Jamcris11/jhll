#include "linked_list.h"

int
main(int argc, char** argv)
{
	struct LinkedList* list;
	int* data;

	list = linked_list_new(sizeof(int));

	for ( int x = 0, y = 1, z = 0, i = 0; i < 25; i++ ) {
		linked_list_add(list, &(int){x + y});
		
		z = y;
		y = x + y;
		x = z;
	}

	while ( (data = (int*)linked_list_next(list)) != NULL ) {
		printf("%d\n", *data);
	}

	linked_list_delete(list);

	return 0;
}
