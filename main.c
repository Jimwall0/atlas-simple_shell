#include "main.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/**
 * main - entry point for simple shell
 * @argc: number of inputs
 * @argv: array of inputs
 * @envp: environment variables
 *
 * Return: status
 */

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
	char *buffer = NULL, *tok = NULL;
	size_t size = BUFF_SIZE;

	buffer = malloc(sizeof(char) * size);
	if (buffer == NULL)
		return (ERROR_MALLOC);
	tok = user_input(buffer, size);
	printf("%s\n", tok);
	free(buffer);
	return (EXIT_SUCCESS);
}