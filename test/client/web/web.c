#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <cerver/utils/log.h>

#include "curl.h"

#define ADDRESS_SIZE			128

static const char *address = { "127.0.0.1:8080" };

static size_t web_request_all_data_handler (
	void *contents, size_t size, size_t nmemb, void *storage
) {

	(void) strncpy ((char *) storage, (char *) contents, size * nmemb);

	return size * nmemb;

}

static unsigned int web_request_all_actual (
	CURL *curl
) {

	unsigned int errors = 0;

	char data_buffer[4096] = { 0 };
	char actual_address[ADDRESS_SIZE] = { 0 };

	// GET /
	errors |= curl_simple_handle_data (
		curl, address,
		web_request_all_data_handler, data_buffer
	);

	// GET /test
	(void) snprintf (actual_address, ADDRESS_SIZE, "%s/test", address);
	errors |= curl_simple_handle_data (
		curl, actual_address,
		web_request_all_data_handler, data_buffer
	);

	// GET /text
	(void) snprintf (actual_address, ADDRESS_SIZE, "%s/text", address);
	errors |= curl_simple_handle_data (
		curl, actual_address,
		web_request_all_data_handler, data_buffer
	);

	// GET /json
	(void) snprintf (actual_address, ADDRESS_SIZE, "%s/json", address);
	errors |= curl_simple_handle_data (
		curl, actual_address,
		web_request_all_data_handler, data_buffer
	);

	// GET /hola
	(void) snprintf (actual_address, ADDRESS_SIZE, "%s/hola", address);
	errors |= curl_simple_handle_data (
		curl, actual_address,
		web_request_all_data_handler, data_buffer
	);

	// GET /adios
	(void) snprintf (actual_address, ADDRESS_SIZE, "%s/adios", address);
	errors |= curl_simple_handle_data (
		curl, actual_address,
		web_request_all_data_handler, data_buffer
	);

	// GET /key
	(void) snprintf (actual_address, ADDRESS_SIZE, "%s/key", address);
	errors |= curl_simple_handle_data (
		curl, actual_address,
		web_request_all_data_handler, data_buffer
	);

	// GET /custom
	// (void) snprintf (actual_address, ADDRESS_SIZE, "%s/custom", address);
	// errors |= curl_simple_handle_data (
	// 	curl, actual_address,
	// 	web_request_all_data_handler, data_buffer
	// );

	// GET /reference
	// (void) snprintf (actual_address, ADDRESS_SIZE, "%s/reference", address);
	// errors |= curl_simple_handle_data (
	// 	curl, actual_address,
	// 	web_request_all_data_handler, data_buffer
	// );

	return errors;

}

// perform requests to every route
static unsigned int web_request_all (void) {

	unsigned int retval = 1;

	CURL *curl = curl_easy_init ();
	if (curl) {
		if (!web_request_all_actual (curl)) {
			cerver_log_line_break ();
			cerver_log_line_break ();

			cerver_log_success (
				"web_request_all () - All requests succeeded!"
			);

			cerver_log_line_break ();
			cerver_log_line_break ();

			retval = 0;
		}
	}

	curl_easy_cleanup (curl);

	return retval;

}

int main (int argc, char **argv) {

	int code = 0;

	cerver_log_init ();

	code = (int) web_request_all ();

	cerver_log_end ();

	return code;

}