#include "main.h"
/**
 * user_input - grabs the input of the user and
 * turns it into an array of tokens
 * Return: array on success, 1 on failure, and NULL for nothing
*/
char **user_input()
{
	char *tok, *buff = NULL;
	char **new_arr = NULL;
	int i;
	size_t size = BUFF_SIZE;

	new_arr = malloc(sizeof(char *) * 50); /*alloc for new_arr*/
	buff = malloc(sizeof(char) * size); /*alloc for buffer*/
	if (new_arr == NULL || buff == NULL) /*check both*/
	{
		free(new_arr);
		exit(ERROR_MALLOC);
	}
	if (getline(&buff, &size, stdin) < 0) /*get user input*/
	{
		free(new_arr);
		free(buff);
		exit(ERROR_MALLOC);
	}
	/*copy tokens*/
	tok = strtok(buff, WHITESPACE);
	new_arr[0] = strdup(tok);
	for (i = 1; tok != NULL; i++)
	{
		tok = strtok(NULL, WHITESPACE);
		if (tok != NULL)
		{
			new_arr[i] = strdup(tok);
			if (new_arr[0] == NULL || new_arr[i] == NULL)
			{
				free2darray(new_arr);
				free(buff);
				exit(ERROR_MALLOC);
			}
		}
		else
			new_arr[i] = NULL;
	}
	free(buff);
	free(tok);
	return (new_arr);
}
/*
 * need to reallocate mem
 * The way I had been doing was broken
 * This currently works
*/
