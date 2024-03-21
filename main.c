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
	struct stat *buff;

	(void)env;
	(void)ac;
	printf("%s\n", PROMPT);
	/* Takes input and turns it into a pointer array*/
	tok = user_input(b, size);
	buff = malloc(sizeof(struct stat));
	if (buff == NULL)
	{
		free(buff);
		free(b);
		exit(EXIT_FAILURE);
	}
	/* Duplicate the process*/
	pid = fork();
	/* Child process*/
	if (pid == 0)
	{
		execve(tok, av, NULL);
	}
	/* This is the main process*/
	wait(NULL);
	free(b);
	free(buff);
	free(tok);
	return (0);
}
