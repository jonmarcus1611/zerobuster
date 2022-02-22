#include <stdio.h>
#include <stdlib.h>
#include "render.h"

void 
clean_exit(const char *error_msg)
{
	zero_log(error_msg);
	exit(1);
}
