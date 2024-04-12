#include "huffpuff.h"
#include "string.h"

int main(int argc, char *argv[]){
	if (argc > 1 ){
		if (strcmp(argv[1],"-x") == 0){
			return huffpuff_decompress(stdin, stdout);
		}else{
			fprintf(stderr, "Argumento inválido: %s \n", argv[1]);
			return 1;
		}
	}else{
		return huffpuff_compress(stdin, stdout);
	}
}
