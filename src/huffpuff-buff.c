#include "huffpuff-buff.h"

typedef struct {
	struct buflist * next;
	size_t size;
	unsigned char buffer[BUFFERSIZE];
} buflist;

typedef struct {
	buflist * head;
	buflist * bufcursor;
	size_t cursor;
} bolacha; 

static ssize_t reader (void *cookie, char *buffer, size_t size){

}

static ssize_t writer (void *cookie, const char *buffer, size_t size){

}

static int seeker (void *cookie, off64_t *position, int whence){

}


int cleaner (void *cookie){

}

FILE * huffpuff_buffer_open(){
	cookie_io_functions_t c;
	bolacha b;
	c.read = &reader;
	c.write = &writer;
	c.seek = &seeker;
	c.close = &cleaner;
	b.head = b.bufcursor = NULL;
	b.cursor = 0;

	return fopencookie(&b, "rw", c);
}


