#include "main.h"
/**
 * main - our big function to begin the code
 * @ac: number of arguements
 * @av: pointer to inputs
 * @env: file and pathways
 * Return: returns 0 on success
*/
int main(int ac, char **av, char **env)
{
	char *b = NULL, *tok;
	size_t size = BUFF_SIZE;
	pid_t pid;

	(void)ac;
	(void)env;
	while ()
	{
		printf("%s\n", PROMPT);
		/* Takes input and turns it into a pointer array*/
		tok = user_input(b, size);
		/* Duplicate the process*/
		pid = fork();
		/* Child process*/
		if (pid == 0)
		{
			if (execve(tok, av, NULL) == -1)
				exit(EXIT_FAILURE);
			exit(EXIT_SUCCESS);
		}
		/* This is the main process*/
		wait(NULL);
		free(b);
		free(tok);
	}
	return (0);
}
