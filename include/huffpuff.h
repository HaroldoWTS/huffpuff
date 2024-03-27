#ifndef HUFFPUFF_H
#define HUFFPUFF_H

huffpuff_t * huffpuff_create();

void huffpuff_destroy(huffpuff_t * hp);

void huffpuff_compress(huffpuff_t * hp, const char * uncompressed_data, size_t input_size);
void huffpuff_get_compression_header();


#endif
