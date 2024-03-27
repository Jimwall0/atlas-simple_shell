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
	char **cmd_arr = NULL;
	int check = 0;
	pid_t pid;

	(void)ac;
	(void)av;
	(void)env;
	if (isatty(STDIN_FILENO))
	{
		while (check == 0)
		{
			printf("%s ", PROMPT);
			cmd_arr = user_input();
			if (strcmp(cmd_arr[0], "exit") == 0)
			{
				check++;
				free2darray(cmd_arr);
				return (EXIT_SUCCESS);
			}
			pid = fork();
			if (pid == 0)
			{
				while (cmd_arr)
				{
					if (execve(cmd_arr[0], cmd_arr, env) != 0)
					{
						free2darray(cmd_arr);
						exit(EXIT_FAILURE);
					}
				}
				exit(EXIT_SUCCESS);
			}
			wait(NULL);
			free2darray(cmd_arr);
		}
	}
	else
	{
		cmd_arr = user_input();
		pid = fork();
		if (pid == 0)
		{
			if (execve(cmd_arr[0], cmd_arr, env) != 0)
			{
				free2darray(cmd_arr);
				exit(EXIT_FAILURE);
			}
		}
		wait(NULL);
	}
	free2darray(cmd_arr);
	return (0);
}
