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
		/* Unable to connect to server. Add error handling later */
	}

	if (404 != response_code) {
		printf("%-77s %ld\n", url, response_code);
	}

	return NULL;
}


static char *
get_time()
{
	time_t now = time(NULL);
	char *time_str = safe_malloc(sizeof(char) * 64);
	strcpy(time_str, ctime(&now));

	time_str[strcspn(time_str, "\n")] = 0;

	return time_str;
}

