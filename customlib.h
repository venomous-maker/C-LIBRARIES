#ifndef CUSTOMSTDLIB_H
	#define CUSTOMSTDLIB_H
		#ifndef CUSTOMSTDLIB_H_IMPORTS
		#include <stdio.h>
		#include <sys/types.h>
		#include <unistd.h>
		#include <stdlib.h>
		#include <sys/wait.h>
		#include <wait.h>
		#include <string.h>
		#include <sys/stat.h>
		#include <sys/shm.h>
		#include <sys/ipc.h>
		#include <stdio.h>
		#include <stdarg.h>
		#include <time.h>
		#include "converters.h"
	#endif
	// GET TIME
	char* print_time();
	void log_print(char* filename, int line, char *fmt,...);
	#ifndef LOGFILE
		#define LOG_PRINT(...) log_print(__FILE__, __LINE__, __VA_ARGS__ )
	#endif
	// Returns the length of the string.
	// If the string is NULL, returns -1.
	// If the string is empty, returns 0.
#ifndef strlen
	long unsigned int stringlen(const char* str);
#endif
	#ifndef MAX_SENTENCE_LENGTH
		#define MAX_SENTENCE_LENGTH 256
	#endif
// 	const char* filename: The name of the file to read sentences from
// 	char*** sentences: A pointer to an array of strings (char**) that will be used to store the sentences read from the file
// 	int* num_sentences: A pointer to an integer that will be used to store the number of sentences read from the file
	int read_lines_from_file(const char* filename, char*** sentences, int* num_sentences);
	typedef void (*fn_ptr)();
	double time_execution(fn_ptr function, ...);
#endif
