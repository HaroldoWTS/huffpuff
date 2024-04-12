#include "huffpuff.h"
#include "huffpuff-tree.h"
#include "assert.h"
#include "stdint.h"

const size_t BUFFERSIZE = 1024;

struct buflist {
	struct buflist * next;
	size_t size;
	unsigned char buffer[BUFFERSIZE];
}

struct huffpuff_dom {
	uint64_t histogram[256];
	uint64_t uncompressed_size;
	struct buflist * compressed_data;
}

void tree_get_leaves(huffpuff_tree_t * tree, huffpuff_tree_t leaves[]){
	if (!tree)
		return;
	if (tree->type == HUFFPUFF_LEAF){
		if (!leaves[tree->node.symbol])
			leaves[tree->node.symbol] = tree;
	}else{
		tree_get_leaves(tree->node.branch[0], leaves);
		tree_get_leaves(tree->node.branch[1], leaves);
	}
}


int huffpuff_compress(FILE * in, FILE * out){
	
	struct huffpuff_dom dom;
	//unsigned int histogram[256];
	unsigned int c;
	if (!ret)
		return;
	for (c = 0; c < 256; c++){
		dom.histogram[c]=0;
	}

	struct buflist * lhead = NULL;
	struct buflist * lnode = NULL;
	size_t i = 0;
	while (true){
		if (lnode){
			lnode->next = malloc(sizeof(*lhead));
			lnode = lnode->next;
		}
		assert(lnode);
		if (!lhead)
			lhead = lnode;
		lnode->size = fread(lnode->buffer, 1, BUFFERSIZE, in);
		for (i = 0;i < lnode->size;i++ ){
			dom.histogram[lnode->buffer[i]]++;
		}
		if (lnode->size < BUFFERSIZE)
			break;
	}

	assert(lhead);
	
	huffpuff_tree_t * tree = huffpuff_tree_create(histogram);
	huffpuff_tree_t * leaves[256];
	for(c = 0; c< 256; c++)
		leaves[c] = NULL;	

	tree_get_leaves(tree, leaves[0]);
	
	char * codes[256];

	struct huffpuff_compressor compressor;

	for(lnode = lhead; lnode; lnode = lnode->next){
		for (i = 0; i < lnode->size; i++){
			compressor_pump_code(&compressor, code[lnode->buffer[i]] )			
		}
	}
	

}
