#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

#include "error_functions.h"

FILE* log_file = NULL;

void open_log_file(){
	if(log_file == NULL){
		log_file = fopen("client.log.out", "w");
	
		fprintf(log_file, "-----THIS IS A SIMPLE LOG FILE-----\n");
	}
}

void terminate(){
	exit(EXIT_FAILURE);
}

void log_error(const char* msg){
	open_log_file();

	time_t now_timestamp = time(NULL);
	struct tm* now_time = localtime(&now_timestamp);

	fprintf(log_file, "[ERROR][%d / %d / %d][%d : %d : %d] : %s : %s\n", now_time->tm_mon, now_time->tm_mday, now_time->tm_year + 1990, 
			now_time->tm_hour, now_time->tm_min, now_time->tm_sec,
			strerror(errno), msg);
}

void error_die(const char* msg){
	log_error(msg);
	perror(msg);
	terminate();
}

void use_die(const char* msg){
	log_error(msg);
	fprintf(stderr, "%s\n", msg);
	terminate();
}
