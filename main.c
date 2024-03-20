#include "main.h"
/**
 * main - our big function to begin the code
 * Return - returns 0 on success
*/
int main(void)
{
	char *b;
	size_t size = 32;

	b = malloc(sizeof(char) * size);
	if (b == NULL)
	{
		return (-1);
	}
	/* Grabs the users input and stores it along with a \n */
	getline(&b, &size, stdin);
	/* Should break up the the string */
	printf("Did you just say: %s\n", b);
	free(b);
	return (0);
}
