#include <stdio.h>
#include <stdlib.h>
#include "render.h"


void *
safe_malloc(size_t num_bytes)
{
	void *buffer = malloc(num_bytes);
	if (NULL == buffer) {
		fprintf(stderr, "Unable to allocate memory for malloc!\n");
		exit(1);
	}	
	return buffer;
}
