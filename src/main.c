#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "render.h"
#include "networking.h"

#define MAX_LINE_LENGTH 64

const char *usage = "./zerobuster <host> <word_list>\n";

int
main(int argc, char **argv) 
{
	char *word_list;
	char *host;

	
	/* Get arguments */
	if (3 == argc) {
		host = argv[1];
		word_list = argv[2];
	} else {
		printf("%s", usage);
		return 1;
	}

	/* Open wordlist */
	long  response_code;
	char line[MAX_LINE_LENGTH];
	FILE *fp = fopen(word_list, "r");

	if (NULL == fp) {
		fprintf(stderr, "Error opening file %s\n", word_list);
		exit(1);
	}

	/* Iterate through wordlist and send requests */
	while(fgets(line, sizeof(line), fp)) {
		char *url = create_url(host, line);
		response_code = send_request(url);
		print_response(response_code, url);
		free(url);
	}

	fclose(fp);
	return 0;
	
}
