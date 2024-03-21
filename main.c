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
	char *buffer = NULL, *tok;
	size_t size = BUFF_SIZE;
	pid_t pid;
	bool running = 1;

	while (running)
	{
		tok = user_input(buffer, size);
		if (strcmp(tok, "exit") == 0) /*exit command for loop*/
		{
			free(buffer);
			free(tok);
			exit(EXIT_SUCCESS);
		}
		pid = fork();
		if (pid < 0) 
			return (EXIT_FAILURE);
		else if (pid == 0) /*child*/
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
			wait(NULL); /*parent wait*/
		free(buffer);
		free(tok);
	}
	free(buffer);
	free(tok);
	return (EXIT_SUCCESS);
}