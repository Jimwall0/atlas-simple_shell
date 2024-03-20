#ifndef MAIN_H
#define MAIN_H
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define ERROR_MALLOC 77
#define EXIT_F_STAT 23
#define EXIT_F_ACCESS 24
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void);
int _strcmp(char *string1, char *string2);

#endif
