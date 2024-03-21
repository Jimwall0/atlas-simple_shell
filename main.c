#include "main.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
	pid_t pid;
	bool running = 1;

	while (running)
	{
		buffer = malloc(sizeof(char) * size);
		if (buffer == NULL)
			return (ERROR_MALLOC);
		tok = user_input(buffer, size);

		pid = fork();
		if (pid < 0)
			return (EXIT_FAILURE);
		else if (pid == 0)
		{
			if (execve(tok, argv, NULL) == -1)
			{
				free(buffer);
				free(tok);
				exit(EXIT_FAILURE);
			}
			exit(EXIT_SUCCESS);
		}
		else
		{
			wait(NULL);
		}
		if (strcmp(tok, "exit") == 0)
			exit(EXIT_SUCCESS);
		printf("%s\n", tok);
	}
	free(buffer);
	free(tok);
	return (EXIT_SUCCESS);
}