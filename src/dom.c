#include "huffpuff-dom.h"

int huffpuff_dom_open_from_file(huffpuff_dom_t * dom, FILE * in){
	if (!dom || !in)
		return 0;
	fread(dom->magic, 9, 1, in);
}

int huffpuff_dom_save_to_file(huffpuff_dom_t * dom, FILE * out){
	if (!dom || !out)
		return 0;
	fwrite(dom->magic, sizeof(dom->magic), 1, out);
	
}


