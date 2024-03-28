#ifndef MAIN_H
#define MAIN_H
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define ERROR_MALLOC 77
#define EXIT_F_STAT 23
#define EXIT_F_ACCESS 24
#define PROMPT "How can I help?"
#define WHITESPACE " \n\t\r"
#define PATH_DELIM ":"
#define BUFF_SIZE 1024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

int main(int ac, char **av, char **env);
int _strcmp(char *string1, char *string2);
char **user_input();
int free2darray(char **array);

#endif
