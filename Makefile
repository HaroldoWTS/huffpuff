.PHONY: all clean

includes = 

all: bin/huffpuff

bin/huffpuff: src/huffpuff.c src/libhuffpuff.a
	$(CC) -I./include src/huffpuff.c -o bin/huffpuff -L./src -lhuffpuff 

src/libhuffpuff.a:
