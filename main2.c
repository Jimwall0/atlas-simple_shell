#include "main.h"

int main(int ac, char **av, char **env)
{
	char **cmd_arr = NULL;
	int i = 0;

	(void)ac;
	(void)av;
	(void)env;
	while (1)
	{
		printf("%s", PROMPT);
		cmd_arr = user_input();
		for (i = 0; cmd_arr[i] != NULL; i++)
		{
			printf("%s\n", cmd_arr[i]);
		}
		free2darray(cmd_arr);
		if (strcmp(cmd_arr[0], "exit") == 0)
		{
			free2darray(cmd_arr);
			return (EXIT_SUCCESS);
		}
	}



	free2darray(cmd_arr);
	return(0);
}