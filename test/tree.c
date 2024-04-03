#include "huffpuff-tree.h"

int main(){
	unsigned char * data = (unsigned char *)"banana";
	huffpuff_histogram_t * h = huffpuff_histogram_create(data, 6);
	huffpuff_tree_t * tree = huffpuff_tree_create(h);
	assert(tree->type == HUFFPUFF_BRANCH );
	assert(tree->weight == 6);
	
	huffpuff_tree_t * aux = tree->branch[0];
	assert(aux->type == HUFFPUFF_LEAF);
	assert(aux->node->symbol == 'a');
	assert(aux->node->weight == 3);
	
	tree = tree->branch[1];
	assert(tree->type == HUFFPUFF_BRANCH);	
	return 0;
}
