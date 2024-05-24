CC = clang
CFLAGS = -I../include -g
LDFLAGS = -L../bin -ljhll 

all: linked_list_test list_test

linked_list_test: linked_list_test.c
	$(CC) $(CFLAGS) -o ../bin/linked_list_test $^ $(LDFLAGS)

list_test: list_test.c
	$(CC) $(CFLAGS) -o ../bin/list_test $^ $(LDFLAGS)
