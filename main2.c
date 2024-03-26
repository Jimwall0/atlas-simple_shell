#include "main.h"

int main(int ac, char **av, char **env)
{
	size_t size = BUFF_SIZE;
	char **cmd_arr = NULL;
	int i = 0;

	(void)ac;
	(void)av;
	(void)env;
	while (1)
	{
		printf("%s", PROMPT);
		cmd_arr = user_input(size);
		printf("%s\n", cmd_arr[0]);
		for (i = 0; cmd_arr[i] != NULL; i++)
		{
			printf("%s\n", cmd_arr[i]);
		}
	}



	free2darray(cmd_arr);
	return(0);
}