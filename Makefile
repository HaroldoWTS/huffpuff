.PHONY: all clean test

CFLAGS=-Iinclude -Wall

all: bin/huffpuff

bin/huffpuff: src/huffpuff.c src/libhuffpuff.a
	$(CC) -I./include src/huffpuff.c -o bin/huffpuff -L./src -lhuffpuff 

src/libhuffpuff.a:

test: test/histogram

test/histogram: test/histogram.o src/histogram.o

test/histogram.o: test/histogram.c include/huffpuff-histogram.h

src/histogram.o: src/histogram.c include/huffpuff-histogram.h

