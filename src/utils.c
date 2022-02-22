#include <stdio.h>
#include <stdlib.h>

void 
clean_exit(const char *error_msg)
{
	zero_log(error_msg);
	exit(1);
}
