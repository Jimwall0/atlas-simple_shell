#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "env-main.h"

/**
 * _getenv - gets an environment variable
 * @name: name of variable to find
 * 
 * Return: name=value
*/

extern char **environ;

char *_getenv(const char *name)
{
	char *env_var, *env_name, *env_val;
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		env_var = environ[i];
		env_name = strtok(env_var, "=");
		env_val = strtok(NULL, "=");
		if (strcmp(env_name, name) == 0)
			return(strdup(env_val));
	}
	return (NULL);
}

/* When used please free strdup */