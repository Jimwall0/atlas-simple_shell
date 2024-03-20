#include "main.h"
/**
 * user_input - grabs the input of the user and
 * turns it into a token
 * @b: string
 * @size: amount of bytes used
 * Return: token
*/
char *user_input(char *b, size_t size)
{
	b = malloc(sizeof(char) * size);
	if (b == NULL)
	{
		free(b);
		exit(EXIT_FAILURE);
	}
	getline(&b, &size, stdin);
	return (strtok(b, " \n"));
}
