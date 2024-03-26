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
	int check = 0;
	pid_t pid;

	(void)ac;
	(void)av;
	(void)env;
	if (isatty(STDIN_FILENO))
	{
		while (check == 0)
		{
			printf("%s\n", PROMPT);
			getline(&b, &size, stdin);
			tok = strtok(b, " \n");
			pid = fork();
			if (pid == 0)
			{
				while (tok)
				{
					if (execve(tok, av, env) != 0)
					{
						free(b);
						exit(EXIT_FAILURE);
					}
					tok = strtok(NULL, " \n");
				}
				exit(EXIT_SUCCESS);
			}
			wait(NULL);
			if (_strcmp(b, "exit\n") == 0)
			{
				check++;
				free(b);
			}
		}
	}
	else
	{
		getline(&b, &size, stdin);
		tok = strtok(b, " \n");
		pid = fork();
		if (pid == 0)
		{
			if (execve(tok, av, env) != 0)
			{
				exit(EXIT_FAILURE);
			}
			tok = strtok(NULL, " \n");
		}
		wait(NULL);
		free(b);
	}
	return (0);
}
