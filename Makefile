.PHONY: all clean test

CFLAGS=-Iinclude -fanalyzer -g -Wall -Werror

all: bin/huffpuff

clean:
	rm -rf bin/*
	rm -f src/*.o
	rm -f src/test/*.o

src/histogram.o: src/histogram.c include/huffpuff-histogram.h

src/tree.o: src/tree.c include/huffpuff-tree.h include/huffpuff-histogram.h

bin/huffpuff: src/huffpuff.o src/libhuffpuff.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

src/huffpuff.o: src/huffpuff.c include/huffpuff.h

#Daqui pra frente, tudo relacionado a testes

test: bin/test/histogram bin/test/tree test/decompressed test/test.txt
	bin/test/histogram
	bin/test/tree
	if diff -q test/decompressed test/test.txt
	then
		echo "Teste final passou!"
	else
		echo "Teste final não passou!"
	fi
	

bin/test/histogram: src/test/histogram.o src/histogram.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

src/test/histogram.o: src/test/histogram.c include/huffpuff-histogram.h


bin/test/tree: src/test/tree.o src/tree.o src/histogram.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

src/test/tree.o: src/test/tree.c include/huffpuff-tree.h include/huffpuff-histogram.h

test/compressed: test/test.txt bin/huffpuff
	cat $< | bin/huffpuff > $@

test/decompressed: test/compressed bin/huffpuff
	cat $< | bin/huffpuff -x > $@

	
