#ifndef ERROR_FUNCTIONS_H
#define ERROR_FUNCTIONS_H

void open_log_file();

void terminate();

void log_error(const char* msg);

void log_war(const char* msg);

void error_die(const char* msg);

void use_die(const char* msg);

#endif
