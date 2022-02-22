#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"

static char *get_time();

void *
zero_log(const char *msg)
{
	char *time_str = get_time();
	printf("%s: %s", time_str, msg);

	free(time_str);
	return NULL;
}


static char *
get_time()
{
	time_t now = time(NULL);
	char *time_str = malloc(sizeof(char) * 64);
	if (!time_str) clean_exit("Error allocating memory!\n");
	strcpy(time_str, ctime(&now));

	time_str[strcspn(time_str, "\n")] = 0;

	return time_str;
}





