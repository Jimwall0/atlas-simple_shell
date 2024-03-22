#include <stdio.h>
#include <unistd.h>
#include "env-main.h"

/**
 * main - prints env var
 * 
*/

int main(int ac, char **av, char **env)
{
	char *value, *name;

	name = "PATH";

	value = _getenv(name);
	printf("%s = %s\n", name, value);
	return (1);
}