#ifndef HUFFPUFF_HISTOGRAM_H
#define HUFFPUFF_HISTOGRAM_H
#include "stddef.h"


typedef struct {
	unsigned int frequency[256];
} huffpuff_histogram_t;

void huffpuff_histogram_fill(huffpuff_histogram_t * hist , const unsigned char * data, size_t datalen);

void huffpuff_histogram_clear(huffpuff_histogram_t * h);

#endif
