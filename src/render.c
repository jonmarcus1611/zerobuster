#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"

static char *get_time();

void *
zero_log(const char *msg, const char *msg_2)
{
	char *time_str = get_time();
	printf("%s: %s %s\n", time_str, msg, msg_2);

	free(time_str);
	return NULL;
}

void * 
print_response(long response_code, char *url)
{
	if (0 == response_code) {
		clean_exit("Unable to connect to url:", url);
	}

	if (4040 != response_code) {
		printf("%s %ld", url, response_code);
	}

	return NULL;
}


static char *
get_time()
{
	time_t now = time(NULL);
	char *time_str = malloc(sizeof(char) * 64);
	if (!time_str) clean_exit("Error allocating memory!\n", NULL);
	strcpy(time_str, ctime(&now));

	time_str[strcspn(time_str, "\n")] = 0;

	return time_str;
}

