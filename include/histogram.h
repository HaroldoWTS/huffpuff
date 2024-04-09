#ifndef HUFFPUFF_HISTOGRAM_H
#define HUFFPUFF_HISTOGRAM_H

typedef struct {
	unsigned int element[256];
} huffpuff_histogram_t ;


huffpuff_histogram_t * huffpuff_histogram_create(const char * data, size_t size );
huffpuff_histogram_frequency(huffpuff_histogram_t * h, unsigned char element );


void huffpuff_histogram_destroy(huffpuff_histogram_t * h);
#endif
