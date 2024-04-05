.PHONY: all clean test

CFLAGS=-Iinclude -fanalyzer -Wall -Werror

all: bin/huffpuff

clean:
	rm -f bin/*
	rm -f src/*.o
	rm -f test/*
	rm -f src/test/*.o

bin/huffpuff: src/huffpuff.c src/libhuffpuff.a
	$(CC) -I./include src/huffpuff.c -o bin/huffpuff -L./src -lhuffpuff 

src/libhuffpuff.a:

test: test/histogram test/tree
	test/histogram
	test/tree

test/histogram: src/test/histogram.o src/histogram.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

src/test/histogram.o: src/test/histogram.c include/huffpuff-histogram.h

src/histogram.o: src/histogram.c include/huffpuff-histogram.h

test/tree: src/test/tree.o src/tree.o src/histogram.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

src/test/tree.o: src/test/tree.c include/huffpuff-tree.h include/huffpuff-histogram.h

src/tree.o: src/tree.c include/huffpuff-tree.h include/huffpuff-histogram.h


