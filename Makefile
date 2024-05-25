CC = clang 
CFLAGS = -Iinclude/ -gdwarf-4
LDFLAGS = 

BIN = libjhll.a

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, bin/obj/%.o, $(SRC))

TESTSDIR = tests/.

all: build tests

build: $(OBJ)
	ar -rcs -o bin/$(BIN) $^ $(LDFLAGS)

bin/obj/%.o: src/%.c dir
	$(CC) -c $(CFLAGS) -o $@ $<

dir:
	@mkdir -p bin
	@mkdir -p bin/obj


.PHONY: tests

tests: $(TESTSDIR)
	$(MAKE) -C $<

