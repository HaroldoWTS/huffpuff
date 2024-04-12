#ifndef HUFFPUFF_DOM_H
#define HUFFPUFF_DOM_H
#include "stdio.h"
#include "stdint.h"

typedef struct {
	int8_t magic[9];/ //HUFFPUFF		
	uint64_t uncompressed_size;
	uint64_t compressed_size;
	uint8_t * compressed_data;
} huffpuff_dom_t;

int huffpuff_dom_from_file(huffpuff_dom_t * dom, FILE * in);
int huffpuff_dom_to_file(const huffpuff_dom_t * dom, FILE * out);

#endif
