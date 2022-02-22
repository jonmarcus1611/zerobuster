#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "render.h"
#include "networking.h"

#define WORD_LIST "word_list.txt"
#define MAX_LINE_LENGTH 64


int
main(int argc, char **argv) 
{
	char line[MAX_LINE_LENGTH];
	FILE *fp = fopen(WORD_LIST, "r");
	if (!fp) clean_exit("Unable to open wordlist!\n");

	while(fgets(line, sizeof(line), fp)) {
		printf("%s", line);
	}


	fclose(fp);
	return 0;
	
}
