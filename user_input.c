#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * user_input - takes the input of the user and turns it into a token
 * @b: buffer location for mem
 * @size: size of memory
 * 
 * Return: strtok value, or EXIT_FAILURE
*/

char *user_input(char *b, size_t size)
{
	b = malloc(sizeof(char) * size);
	if (b == NULL)
		exit (ERROR_MALLOC);
	
	printf("%s", PROMPT);
	getline(&b, &size, stdin);
	return (strtok(b, WHITESPACE));
}