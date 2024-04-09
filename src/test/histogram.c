#include "stdio.h"
#include "string.h"
#include "assert.h"
#include "huffpuff-histogram.h"

int main(){
	unsigned char * data = (unsigned char *)"banana";
	huffpuff_histogram_t h;
	huffpuff_histogram_clear(&h);
	huffpuff_histogram_fill(&h, data, 6);
	unsigned char c;
	for (c = 0; c < 255; c++){
		if (c == 'b')
			assert(h.frequency[c] == 1 );
		else if (c == 'n')
			assert(h.frequency[c] == 2 );
		else if (c == 'a')
			assert(h.frequency[c] == 3 );
		else
			assert(h.frequency[c] == 0 );
	}
	printf("Teste do histograma concluído.\n");
}
