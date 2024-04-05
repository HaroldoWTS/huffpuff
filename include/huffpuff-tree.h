#ifndef HUFFPUFF_TREE_H
#define HUFFPUFF_TREE_H

#include "huffpuff-histogram.h"

typedef enum {
	HUFFPUFF_BRANCH = 0,
	HUFFPUFF_LEAF = 1
} huffpuff_tree_type;

struct huffpuff_tree {
	huffpuff_tree_type type;
	unsigned int weight;
	union {
		unsigned char symbol;
		struct huffpuff_tree * branch[2]; 
	} node;
};

typedef struct huffpuff_tree huffpuff_tree_t;

huffpuff_tree_t * huffpuff_tree_create(huffpuff_histogram_t * histogram);

#endif
