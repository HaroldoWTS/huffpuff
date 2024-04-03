#ifndef HUFFPUFF_HISTOGRAM_H
#define HUFFPUFF_HISTOGRAM_H
#include "stddef.h"


typedef struct {
	unsigned int frequency[256];
} huffpuff_histogram_t;

huffpuff_histogram_t * huffpuff_histogram_create(const unsigned char * data, size_t datalen);

void huffpuff_histogram_print(huffpuff_histogram_t * h);

#endif
