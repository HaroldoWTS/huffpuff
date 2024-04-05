#include "huffpuff-tree.h"
#include "stdlib.h"

struct list{
	huffpuff_tree_t * tree;
	struct list * next;
};

typedef struct list list_t;

list_t * list_insert_ordered(list_t * current, huffpuff_tree_t * newt){
	list_t * newl = NULL;
	if (current){
		if (newt->weight < current->tree->weight){
			newl = malloc(sizeof(list_t));
			if (newl){
				newl->tree = newt;
				newl->next = current;
				return newl;
			}else
				return current;
		}else{
			current->next = list_insert_ordered(current->next, newt);
			return current;
		}
	}else{
		newl = malloc(sizeof(list_t));
		if (newl){
			newl->tree = newt;
			newl->next = NULL;
		}
		return newl;
	}
}


list_t * histogram_to_list(huffpuff_histogram_t * h){
	list_t * ret = NULL;
	huffpuff_tree_t * tree = NULL;
	unsigned int it;
	for (it = 0; it < 255; it++){
		if (h->frequency[it] == 0 ){
			continue;
		}
		tree = malloc(sizeof(huffpuff_tree_t));
		if (tree){
			tree->type = HUFFPUFF_LEAF;
			tree->weight = h->frequency[it];
			tree->node.symbol = it;
			ret = list_insert_ordered(ret, tree);	
		}
	}
	return ret;
}

void list_destroy(list_t * l){
	if (l){
		list_t * n = l->next;
		free(l);
		list_destroy(n);
	}
}

huffpuff_tree_t * huffpuff_tree_create(huffpuff_histogram_t * histogram){
	list_t * l = histogram_to_list(histogram);
	list_t * chop = l;
	huffpuff_tree_t * newt = NULL;
	if (l == NULL)
		return NULL;
	while (1){
		if (l->next){
			newt = malloc(sizeof(huffpuff_tree_t));
			if (newt){
				newt->type = HUFFPUFF_BRANCH;
				newt->node.branch[1] = l->tree;
				newt->node.branch[0] = l->next->tree;
				newt->weight = l->tree->weight + l->next->tree->weight;
				l = list_insert_ordered(l->next->next, newt);
			}
		}else{
			newt = l->tree;
		}
	}
	list_destroy(chop);
	return newt;
}

