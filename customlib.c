#include "customlib.h"

double time_execution(fn_ptr function, ...) {
	va_list args;
	va_start(args, function);
	
	clock_t start, end;
	
	/* Store time before function call */
	start = clock();
	function(args);
	
	end = clock();
	va_end(args);
	/* Get the time taken by program to execute in seconds */
	return ((((double)(end - start))/CLOCKS_PER_SEC))*1e6;
}

int read_lines_from_file(const char* filename, char*** sentences, int* num_sentences) {
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("Error: unable to open file %s\n", filename);
		return 1;
	}
	
	// Allocate memory for the sentences array
	*sentences = (char**) malloc(sizeof(char*));
	if (*sentences == NULL) {
		printf("Error: unable to allocate memory for sentences array\n");
		return 1;
	}
	
	// Initialize the number of sentences to 0
	*num_sentences = 0;
	
	// Read sentences from the file and store them in the sentences array
	char sentence[MAX_SENTENCE_LENGTH];
	while (fgets(sentence, MAX_SENTENCE_LENGTH, file) != NULL) {
		// Remove the newline character from the end of the sentence
		int sentence_length = strlen(sentence);
		if (sentence[sentence_length - 1] == '\n') {
			sentence[sentence_length - 1] = '\0';
		}
		
		// Allocate memory for the current sentence
		(*sentences)[*num_sentences] = (char*) malloc((sentence_length + 1) * sizeof(char));
		if ((*sentences)[*num_sentences] == NULL) {
			printf("Error: unable to allocate memory for sentence %d\n", *num_sentences);
			return 1;
		}
		
		// Copy the sentence to the sentences array
		strcpy((*sentences)[*num_sentences], sentence);
		
		// Increase the number of sentences
		(*num_sentences)++;
		
		// Reallocate memory for the sentences array to store one more sentence
		*sentences = (char**) realloc(*sentences, (*num_sentences + 1) * sizeof(char*));
		if (*sentences == NULL) {
			printf("Error: unable to reallocate memory for sentences array\n");
			return 1;
		}
	}
	
	fclose(file);
	return 0;
}

char* print_time()
{
	int size = 0;
	time_t t;
	char *buf;
	
	t=time(NULL); /* get current calendar time */
	
	char *timestr = asctime( localtime(&t) );
	timestr[strlen(timestr) - 1] = 0;  //Getting rid of \n
	
	size = strlen(timestr)+ 1 + 2; //Additional +2 for square braces
	buf = (char*)malloc(size);
	
	memset(buf, 0x0, size);
	snprintf(buf,size,"[%s]", timestr);
		
	return buf;
}

void log_print(char* filename, int line, char* fmt, ...)
{
	va_list         list;
	char            *p, *r;
	int             e;
	float 			f;
	FILE *fp ; // FILE NAME TO HOLD LOGS
	fp = fopen ("log.txt","a+");
	string time = print_time();
	fprintf(fp,"%s ", time);
	fprintf(fp,"[%s][line: %d] ",filename,line);
	va_start( list, fmt );
	
	for ( p = fmt ; *p ; ++p )
	{
		if ( *p != '%' )//If simple string
		{
			fputc( *p,fp );
		}
		else
		{
			switch ( *++p )
			{
				/* string */
				case 's':
				{
					r = va_arg( list, char * );
					
					fprintf(fp,"%s", r);
					continue;
				}
				
				/* string */
				case 'f':
				{
					f = va_arg( list, double );
					
					fprintf(fp,"%f", f);
					continue;
				}
				
				/* integer */
				case 'd':
				{
					e = va_arg( list, int );
					
					fprintf(fp,"%d", e);
					continue;
				}
				
				default:
					fputc( *p, fp );
			}
		}
	}
	va_end( list );
	fputc( '\n', fp );
	fclose(fp);
	free(time);
}

// Returns the length of the string.
// If the string is NULL, returns -1.
// If the string is empty, returns 0.
long unsigned int stringlen(const char* str) {
	if (str == NULL) {
		return -1;
	}
	int len = 0;
	for (const char* p = str; *p; ++p) {
		++len;
	}
	return len;
}
