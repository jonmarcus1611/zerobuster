#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>


void *
send_request(const char *url)
{
	CURL *curl;
	curl = curl_easy_init();

	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}


	return NULL;
}
