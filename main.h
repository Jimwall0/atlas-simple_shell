#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdlib.h>

/* MACROS */

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define ERROR_MALLOC 77
#define EXIT_F_STAT 23
#define EXIT_F_ACCESS 24

#define PROMPT "How can I help? $ "

#define WHITESPACE " \n\t\r"
#define PATH_DELIM ":"

#define BUFF_SIZE 1024

/* prototypes */

char *user_input(char *b, size_t size);

#endif