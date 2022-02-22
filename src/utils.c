#include <stdio.h>
#include <stdlib.h>
#include "render.h"

void 
clean_exit(const char *error_msg, const char *error_msg_2)
{
	zero_log(error_msg, error_msg_2);
	exit(1);
}
