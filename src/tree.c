#include "huffpuff-tree.h"
#include "stdlib.h"
#include "stdio.h"

huffpuff_tree_t * list_insert_ordered(huffpuff_tree_t * current, huffpuff_tree_t * newt){
	if (!current || newt->weight < current->weight){
		newt->next = current;
		return newt;
	}else{
		current->next = list_insert_ordered(current->next, newt);
		return current;
	}
	
}

//converts a histogram into a ordered linked list of tree nodes
huffpuff_tree_t * histogram_to_list(unsigned int h []){
	huffpuff_tree_t * ret = NULL;
	huffpuff_tree_t * tree = NULL;
	unsigned int it;
	for (it = 0; it < 255; it++){
		if (h[it] == 0 ){
			continue;
		}
		tree = malloc(sizeof(huffpuff_tree_t));
		if (tree){
			tree->type = HUFFPUFF_LEAF;
			tree->weight = h[it];
			tree->node.symbol = it;
			tree->next = NULL;
			ret = list_insert_ordered(ret, tree);	
		}
	}
	return ret;
}


huffpuff_tree_t * huffpuff_tree_create(usigned int histogram []){
	huffpuff_tree_t * l = histogram_to_list(histogram);
	huffpuff_tree_t * newt = NULL;
	if (l == NULL)
		return NULL;
	while (1){
		if (l->next){
			newt = malloc(sizeof(huffpuff_tree_t));
			if (newt){
				newt->type = HUFFPUFF_BRANCH;
				l->parent = l->next->parent = newt;
				newt->node.branch[0] = l;
				newt->node.branch[1] = l->next;
				newt->weight = l->weight + l->next->weight;
				newt->next =  NULL;
				l = l->next->next;
				newt->node.branch[0]->next = NULL;
				newt->node.branch[1]->next = NULL;

				l = list_insert_ordered(l, newt);
			}else{
				fprintf(stderr, "Sem memória!");
				exit(1);
			}
		}else{
			return l;
		}
	}
}

void huffpuff_tree_print(huffpuff_tree_t * tree){
	
}

void huffpuff_tree_destroy(huffpuff_tree_t * tree){
	if (tree)
		if (tree->type == HUFFPUFF_BRANCH){
			huffpuff_tree_destroy(tree->node.branch[0]);
			tree->node.branch[0] = NULL;
			huffpuff_tree_destroy(tree->node.branch[1]);
			tree->node.branch[1] = NULL;
		}
	free(tree);
}

