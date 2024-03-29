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
	path_t *cmd_list = NULL;
	int check = 1;
	pid_t pid;

	(void)ac;
	(void)av;
	pathlist(&cmd_list); /*get list of PATH*/
	while (check)
	{
		printf("%s ", PROMPT);
		cmd_arr = user_input();
		cmd_arr[0] = pathfinder(cmd_list, cmd_arr[0]);
		if (!isatty(STDIN_FILENO))
			check = 0;
		if (cmd_arr[0] == NULL)/*for cmd not found*/
		{
			free2darray(cmd_arr);
			continue;
		}
		else if (strcmp(cmd_arr[0], "exit") == 0)/*exit*/
		{
			free2darray(cmd_arr);
			freelist(&cmd_list);
			return (EXIT_SUCCESS);
		}
		pid = fork();/*fork for child proccess*/
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
	return (EXIT_SUCCESS);
}
