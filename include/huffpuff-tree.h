#ifndef HUFFPUFF_TREE_H
#define HUFFPUFF_TREE_H

typedef enum {
	HUFFPUFF_BRANCH = 0,
	HUFFPUFF_LEAF = 1
} huffpuff_tree_type;

typedef struct huffpuff_tree_t;

typedef struct {
	huffpuff_tree_type type;
	unsigned int weight;
	union {
		unsigned char symbol;
		huffpuff_tree_t branch[2]; 
	} node;
} huffpuff_tree_t;

huffpuff_tree_t * huffpuff_tree_create(huffpuff_histogram_t * histogram);

#endif
