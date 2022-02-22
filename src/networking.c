#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>


void *
send_request(const char *url)
{
	CURL *curl;
	FILE *fp;

	curl = curl_easy_init();
	fp = fopen("/dev/null", "w");

	if (curl) {
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}


	return NULL;
}
