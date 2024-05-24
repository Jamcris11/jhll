CC = clang
CFLAGS = -I../include -gdwarf-4
LDFLAGS = -L../bin -ljhll 

all: linked_list_test list_test stack_test queue_test

linked_list_test: linked_list_test.c
	$(CC) $(CFLAGS) -o ../bin/linked_list_test $^ $(LDFLAGS)

list_test: list_test.c
	$(CC) $(CFLAGS) -o ../bin/list_test $^ $(LDFLAGS)

stack_test: stack_test.c
	$(CC) $(CFLAGS) -o ../bin/stack_test $^ $(LDFLAGS)

queue_test: queue_test.c
	$(CC) $(CFLAGS) -o ../bin/queue_test $^ $(LDFLAGS)
