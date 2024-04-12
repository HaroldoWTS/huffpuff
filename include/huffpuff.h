#ifndef HUFFPUFF_H
#define HUFFPUFF_H
#include "stdio.h"

int huffpuff_compress(FILE * in, FILE * out);
int huffpuff_decompress(FILE * in, FILE * out);

#endif
