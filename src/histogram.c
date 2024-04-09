#include "huffpuff-histogram.h"
#include "stdio.h"
#include "stdlib.h"

void huffpuff_histogram_fill(huffpuff_histogram_t * ret ,const unsigned char * data, size_t datalen){

	if (!ret)
		return;

	const unsigned char * it;
	unsigned int i;
	for (it = data; datalen > 0; it++,datalen-- ){
		i = (unsigned int)*it;
		ret->frequency[i]++;
	}
}


void huffpuff_histogram_clear(huffpuff_histogram_t * ret){
	unsigned int c;
	if (!ret)
		return;
	for (c = 0; c < 256; c++){
		ret->frequency[c]=0;
	}
}
