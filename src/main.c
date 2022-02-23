#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "render.h"
#include "networking.h"

#define WORD_LIST "word_list.txt"
#define MAX_LINE_LENGTH 64
#define HOST "http://localhost:31337"

int
main(int argc, char **argv) 
{
	/* Open wordlist */
	long  response_code;
	char line[MAX_LINE_LENGTH];
	FILE *fp = fopen(WORD_LIST, "r");

	if (NULL == fp) {
		fprintf(stderr, "Error opening file %s\n", WORD_LIST);
		exit(1);
	}

	/* Iterate through wordlist and send requests */
	while(fgets(line, sizeof(line), fp)) {
		char *url = create_url(HOST, line);
		response_code = send_request(url);
		if (NULL != response_code)
			print_response(response_code, url);
		free(url);
	}

	fclose(fp);
	return 0;
	
}
