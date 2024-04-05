#include "huffpuff-tree.h"
#include "assert.h"

int main(){
	unsigned char * data = (unsigned char *)"banana";
	huffpuff_histogram_t * h = huffpuff_histogram_create(data, 6);
	huffpuff_tree_t * tree = huffpuff_tree_create(h);
	assert(tree->type == HUFFPUFF_BRANCH );
	assert(tree->weight == 6);
	
	huffpuff_tree_t * aux = tree->node.branch[0];
	assert(aux->type == HUFFPUFF_LEAF);
	assert(aux->node.symbol == 'a');
	assert(aux->weight == 3);
	
	tree = tree->node.branch[1];
	assert(tree->type == HUFFPUFF_BRANCH);
	assert(tree->weight == 3);

	aux = tree->node.branch[0];
	assert(aux->type == HUFFPUFF_LEAF);
	assert(aux->node.symbol == 'n');
	assert(aux->weight == 2);

	aux = tree->node.branch[1];
	assert(aux->type == HUFFPUFF_LEAF);
	assert(aux->node.symbol == 'b');
	assert(aux->weight == 1);


	return 0;
}
