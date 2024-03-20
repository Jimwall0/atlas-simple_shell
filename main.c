#include "main.h"
/**
 * main - our big function to begin the code
 * Return - returns 0 on success
*/
int main(void)
{
	char *b, *tok;
	size_t size = 32;

	b = malloc(sizeof(char) * size);
	if (b == NULL)
	{
		return (-1);
	}
	/* Grabs the users input and stores it along with a \n */
	getline(&b, &size, stdin);
	/* Should break up the the string and remove the \n*/
	tok = strtok(b, " ");
	while (tok != NULL)
	{
		printf("%s\n", tok);
		tok = strtok(NULL, " \n");
	}
	free(b);
	return (0);
}
