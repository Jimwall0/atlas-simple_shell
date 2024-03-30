#include "main.h"

/**
 * free2darray - frees a 2d array
 * @array: array to be freed
 *
 * Return: 0 on success
*/

int free2darray(char **array)
{
	int i;

	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
	}
	free(array);
	return (0);
}
