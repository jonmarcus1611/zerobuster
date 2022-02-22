#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "utils.h"


long
send_request(const char *url)
{
	/* Send the web request and pipe the output to /dev/null */
	CURL *curl;
	FILE *fp;

	curl = curl_easy_init();
	fp = fopen("/dev/null", "w");
	long response_code;

	if (curl) {
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		curl_easy_setopt(curl, CURLOPT_URL, url);
		if (curl_easy_perform(curl) == CURLE_OK) {
			curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, 
				response_code);

		} 
		curl_easy_cleanup(curl);
	}

	return response_code;
}

char * 
create_url(char *host, char *path)
{
	/* Allocate 2 extra bytes for back slash and null byte */
	/* Url encoding can take a maximum of 8 bytes per unescaped character */
	char *url = malloc(strlen(host) + (strlen(path) * 8) + 2);
	if (!url) clean_exit("Error allocating memory!\n", NULL);

	/* Remove bad characters such as spaces and newlines */
	path[strcspn(path, "\n")] = 0;
	path[strcspn(path, "\x0a")] = 0;
	path[strcspn(path, "\x20")] = 0;

	/* Create and encode url */
	strcpy(url, host);
	strcat(url, "/");
	strcat(url, curl_escape(path, 0));

	return url;
}


