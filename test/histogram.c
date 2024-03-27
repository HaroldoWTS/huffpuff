#include "stdio.h"
#include "assert.h"
#include "huffpuff-histogram.h"

int main(){
	char * data = "banana";
	huffpuff_histogram_t * h = huffpuff_histogram_create(data, strlen(data));
	unsigned char c;
	for (c = 0; c < 255; c++){
		if (c == 'b')
			assert(huffpuff_histogram_frequency(h, c) == 1 );
		else if (c == 'n')
			assert(huffpuff_histogram_frequency(h, c) == 2 );
		else if (c == 'a')
			assert(huffpuff_histogram_frequency(h, c) == 3 );
		else
			assert(huffpuff_histogram_frequency(h, c) == 0 );
	}
}
