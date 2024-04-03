#include "huffpuff-histogram.h"
#include "stdio.h"
#include "stdlib.h"

huffpuff_histogram_t * huffpuff_histogram_create(const unsigned char * data, size_t datalen){

	huffpuff_histogram_t * ret = malloc(sizeof(huffpuff_histogram_t));
	unsigned int c;
	for (c = 0; c < 256; c++){
		ret->frequency[c]=0;
	}

	const unsigned char * it;
	for (it = data; it - data < datalen; it++){
		ret->frequency[*it]++;
	}
	return ret;
}


void huffpuff_histogram_print(huffpuff_histogram_t * h){
	unsigned int c = 0 ;
	for (c = 0; c < 256; c++){
		printf("%d : %d \n", c, h->frequency[c]);	
	}	
}
