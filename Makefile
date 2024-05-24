CC = clang 
CFLAGS = -Iinclude/ -gdwarf-4
LDFLAGS = 

BIN = libjhll.a

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, bin/obj/%.o, $(SRC))

all: build

build: $(OBJ)
	ar -rcs -o bin/$(BIN) $^ $(LDFLAGS)

bin/obj/%.o: src/%.c dir
	$(CC) -c $(CFLAGS) -o $@ $<

dir:
	@mkdir -p bin
	@mkdir -p bin/obj
