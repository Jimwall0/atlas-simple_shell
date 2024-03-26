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

	(void)env;
	(void)ac;
	while (1)
	{
		printf("%s\n", PROMPT);
		/* Stores the users string input into a pointer*/
		tok = user_input(b, size);
		/* forks the process for execution*/
		if (strcmp(tok, "exit") == 0)
		{
			free(b);
			free(tok);
			exit(EXIT_SUCCESS);
		}
		pid = fork();
		/* Child*/
		if (pid == 0)
		{
			if (execve(tok, av, NULL) < 0)
			{
				free(b);
				free(tok);
				exit(EXIT_FAILURE);
			}
			free(b);
			free(tok);
			exit(EXIT_SUCCESS);
		}
		/* Parent proccess*/
		wait(NULL);
		free(b);
		free(tok);
	}
	return (0);
}
