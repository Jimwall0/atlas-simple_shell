#include "main.h"

int free2darray(char **array)
{
	int i;
	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
	}
	free(array);
	return(0);
}