#include "main.h"
/**
 * user_input - grabs the input of the user and
 * turns it into an array of tokens
 * @b: string
 * @size: amount of bytes used
 * Return: array on success, 1 on failure, and NULL for nothing
*/
char **user_input(size_t size)
{
	char *tok, *buff = NULL;
	char **new_arr = NULL;
	int i;

	new_arr = malloc(sizeof(char *) * 100);
	if (new_arr == NULL)
		exit (EXIT_FAILURE);

	buff = malloc(sizeof(char) * size);
	if (buff == NULL)
	{
		free(new_arr);
		exit(EXIT_FAILURE);
	}
	/*get user input*/
	if(getline(&buff, &size, stdin) < 0)
	{
		free(new_arr);
		free(buff);
		exit (EXIT_FAILURE);
	}
	/*copy tokens*/
	tok = strtok(buff, WHITESPACE);
	new_arr[0] = strdup(tok);
	for(i = 1; tok != NULL; i++)
	{
		tok = strtok(NULL, WHITESPACE);
		if (tok != NULL)
			new_arr[i] = strdup(tok);
		else
			new_arr[i] = NULL;
	}
	/*asign to appropriate sized 2d array*/
	cmd_arr = malloc(sizeof(char *) * i);
	if (cmd_arr == NULL)
		{
			free(buff);
			free2darray(new_arr);
			exit (EXIT_FAILURE);
		}

	cmd_arr = new_arr;
	free2darray(new_arr);
	free(buff);

	return (cmd_arr);
}