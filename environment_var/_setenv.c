#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "env-main.h"

/**
 * _setenv - set an environment name and value
 * @name: name of variable
 * @value: value to set
 * @overwrite: ?
 * 
 * Return: 0 for success, -1 for failure
*/

extern char **environ;

int _setenv(const char *name, const char *value, int overwrite)
{
	char *new_var;
	size_t name_len = strlen(name);
	size_t value_len = strlen(value);
	size_t str_len = name_len + value_len + 2;
	char **env;
	
	if (name == NULL || value == NULL || strchr(name, '=') != NULL)
		return (-1);

	new_var = malloc(str_len);
	if (new_var == NULL)
		return (-1);

	strcpy(new_var, name);
	new_var[name_len] = '=';
	strcpy(new_var + name_len + 1, value);

	/* check if variable already exists */
	for (env = environ; *env != NULL; env++)
	{
		if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			if(overwrite)
			{
				*env = new_var;
				return (0);
			}
			else
			{
				free(new_var);
				return (0);
			}
		}
	}
	/* Variable does not exist, add it to environ */
	if (addenv(new_var) == 0)
		return (0);
	else
	{
		free(new_var);
		return(1);
	}
}

/**
 * addenv - adds environ variable if it does not exist
 * @new_var: variable to add
 * 
 * Return: 0 for success, 1 on failure
*/

int addenv(char *new_var)
{
	int env_count, i;

	while(environ[env_count] != NULL)
		env_count++;

	char **new_environ = malloc(sizeof(char *) * (env_count + 2));
	if (new_environ == NULL)
	{
		free(new_var);
		return (-1);
	}

	for(i = 0; i < env_count; i++)
		new_environ[i] = environ[i];

	new_environ[i] = new_var;
	new_environ[i + 1] = NULL;

	free(environ);
	environ = new_environ;

	return (0);
}
